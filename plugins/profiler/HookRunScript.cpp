/***************************************************************************
    NWN Extender - Hook run script function in the server
    Copyright (C) 2003 Ingmar Stieger (Papillon)
    email: papillon@blackdagger.com
	Linux port - (c) virusman (virusman@virusman.ru)

	With performance optimization ideas from FastFrench.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 ***************************************************************************/

#include <sys/types.h>
#include <sys/mman.h>
#include <dlfcn.h>

#include <limits.h>		/* for PAGESIZE */
#include <ctime>

#define DATEBUFFERLENGTH 256
#ifndef PAGESIZE
#define PAGESIZE 4096
#endif

#include "HookRunScript.h"
#include "hash.h"
#include "NWNXProfiler.h"

#define MAX_CALLDEPTH 128

extern CNWNXProfiler profiler;

DWORD old_RunScript;
DWORD old_CrossAreaPathFind;
DWORD old_PathFind;

unsigned char d_jmp_code[] = "\x68\x60\x70\x80\x90"       /* push dword 0x90807060 */
                             "\xc3\x90\x90\x90\x90";//x00 /* ret , nop , nop       */

unsigned char d_ret_code_runscript[0x20];
unsigned char d_ret_code_crossarea[0x20];
unsigned char d_ret_code_pathfind[0x20];

unsigned long lastRet;

void (*RunScriptNextHook)();
void (*CrossAreaNextHook)();
int (*PathfindNextHook)(const char * pthis, const char * NWTile, const char * NWArea, const char * PathFindInfo, int depth, float a2, int a3, float a4, float a5, float a6, float a7, float a8, int a9);

hash_table scriptHash;

int iColumn;
volatile int iCallDepth;
unsigned long ulScriptCounter;
unsigned long ulTotalRuntime;
unsigned long ulTotalLast;
bool emptyScript;
bool isScriptpart;
char scriptName[MAX_CALLDEPTH][17];
//LARGE_INTEGER liFrequency;
struct timeval tvLast[MAX_CALLDEPTH];
struct timeval tvLastStatistic;
char *ScriptName;
unsigned int pCaller;

struct sScriptData {
    unsigned long ulCalls;
    DWORD dwElapsedTime;
    char updated;
};

void myRunScript(char *str);
void myRunScriptPart(char *str);
void StopTimer();

void printer(char *string, void *data)
{
    sScriptData* scriptData = (sScriptData*)data;

    int iLen = strlen(string);
    unsigned long ulMsec = scriptData->dwElapsedTime / 1000;
    profiler.Log(1, "%s", string);
    if (iLen > 7 && iLen < 16)
        profiler.Log(1, "\t");
    else if (iLen < 8)
        profiler.Log(1, "\t\t");

    if (scriptData->updated)
        profiler.Log(1, "%10lu msec %6lu calls *| ", ulMsec, scriptData->ulCalls);
    else
        profiler.Log(1, "%10lu msec %6lu calls  | ", ulMsec, scriptData->ulCalls);
    if (iColumn == 1) {
        iColumn = 0;
        profiler.Log(1, "\n");
    } else
        iColumn++;

    ulTotalRuntime += ulMsec;
    scriptData->updated = FALSE;
}

void FlushStatistics(DWORD dwStatisticMsec)
{
    /*if (ftell(profiler.m_fFile) > profiler.m_maxLogSizeKB)
    {
    	fclose(profiler.m_fFile);
    	profiler.m_fFile = fopen (profiler.m_LogFile, "w+");
    	profiler.WriteLogHeader();
    	profiler.Log(1, "* Logfile hit maximum size limit, starting again.\n");
    }*/

    // Get current time
    time_t now;
    char strDate[DATEBUFFERLENGTH];
    time(&now);
    strftime(strDate, DATEBUFFERLENGTH, "%c", localtime(&now));

    profiler.Log(1, "\nCurrent statistics\n");
    profiler.Log(1, "-----------------------------------------------------------------------------------------------\n");
    enumerate(&scriptHash, printer);
    if (iColumn != 0) {
        profiler.Log(1, "\n");
        iColumn = 0;
    }
    profiler.Log(1, "-----------------------------------------------------------------------------------------------\n");
    profiler.Log(1, "Elapsed time                : %lu msec\n", dwStatisticMsec);
    profiler.Log(1, "Runtime delta               : %lu msec\n", ulTotalRuntime - ulTotalLast);
    profiler.Log(1, "Total cumulative runtime    : %lu msec\n", ulTotalRuntime);
    profiler.Log(1, "Total number of scriptcalls : %lu\n", ulScriptCounter);
    profiler.Log(1, "Current date is             : %s\n\n", strDate);
    ulTotalLast = ulTotalRuntime;
    ulTotalRuntime = 0;
    //fflush(profiler.m_fFile);
}

void StopTimer()
{
    if (emptyScript)
        return;

    sScriptData* scriptData;
    DWORD dwPerfElapsed;
    DWORD dwStatisticMsec;

    struct timeval tvCurrent;
    gettimeofday(&tvCurrent, NULL);
    dwPerfElapsed = (DWORD)(((tvCurrent.tv_usec + tvCurrent.tv_sec * 1000000) - (tvLast[iCallDepth].tv_usec + tvLast[iCallDepth].tv_sec * 1000000)) / 1);

    //profiler.Log(1, "(stop %s, %d microsec)\n", scriptName[iCallDepth], dwPerfElapsed);

    scriptData = (sScriptData*)lookup(scriptName[iCallDepth], &scriptHash);
    if (!scriptData) {
        scriptData = new sScriptData;
        scriptData->dwElapsedTime = dwPerfElapsed;
        scriptData->ulCalls = 1;
        scriptData->updated = TRUE;
    } else {
        scriptData->dwElapsedTime += dwPerfElapsed;
        if (profiler.log_scriptparts || !isScriptpart)scriptData->ulCalls++;
        scriptData->updated = TRUE;
    }
    insert(scriptName[iCallDepth], (void*)scriptData, &scriptHash);
    isScriptpart = false;


    dwStatisticMsec = (DWORD)(((tvCurrent.tv_usec + tvCurrent.tv_sec * 1000000) - (tvLastStatistic.tv_usec + tvLastStatistic.tv_sec * 1000000)) / 1000);
    if (dwStatisticMsec > 10000) {
        gettimeofday(&tvLastStatistic, NULL);
        FlushStatistics(dwStatisticMsec);
    }

    if (iCallDepth > -1)
        iCallDepth--;
}

void myRunScript(char *str)
{
    if (str != NULL) {
        if (iCallDepth < MAX_CALLDEPTH - 1)
            iCallDepth++;
        else
            profiler.Log(1, "Maximum call depth reached!\n");

        emptyScript = false;
        isScriptpart = false;
        strncpy(scriptName[iCallDepth], str, 16);
        scriptName[iCallDepth][16] = 0x0;
        ulScriptCounter++;

        if (profiler.m_LogLevel == profiler.logCallstack) {
            profiler.Log(1, "%s (calldepth %d) - caller %08lX\n", str, iCallDepth, pCaller);
            //fflush(profiler.m_fFile);
        }
        gettimeofday(&tvLast[iCallDepth], NULL);
    } else
        emptyScript = true;
}

void myRunScriptPart(char *str)
{
    if (str != NULL) {
        if (iCallDepth < MAX_CALLDEPTH - 1)
            iCallDepth++;
        else
            profiler.Log(1, "Maximum call depth reached!\n");

        emptyScript = false;
        isScriptpart = true;
        if (profiler.log_scriptparts == 1) {
            scriptName[iCallDepth][0] = '>';
            scriptName[iCallDepth][1] = 0x0;
            strncat(scriptName[iCallDepth], str, 15);
            scriptName[iCallDepth][16] = 0x0;
        } else {
            strncpy(scriptName[iCallDepth], str, 16);
            scriptName[iCallDepth][16] = 0x0;
        }
        ulScriptCounter++;

        if (profiler.m_LogLevel == profiler.logCallstack) {
            profiler.Log(1, "%s (calldepth %d, scriptpart) - caller %08lX\n", str, iCallDepth, pCaller);
            //fflush(profiler.m_fFile);
        }
        gettimeofday(&tvLast[iCallDepth], NULL);
    } else
        emptyScript = true;
}

void RunScriptHookProc()
{
    //It would be simplier to do it in C++...

    asm("pusha");
    //asm ("mov (%esp), %eax");
    //asm ("mov myFunc, %esp");
    asm("mov 0x3C(%ebp), %ecx");
    asm("mov (%ecx), %eax");
    asm("movl %%eax, %0" : "=r"(ScriptName));
    asm("test %eax, %eax");
    asm("je scriptpart");

    asm("cmpb $0, %ds:(%eax)");
    asm("je invalidscript");

    asm("push %eax");
    //asm ("call *myRunScript");
    asm("call *%0" : : "a"(myRunScript));
    asm("add $4, %esp");
    asm("jmp original");

    asm("scriptpart:");
    asm("mov 0x4(%ebp), %eax");
    asm("mov %eax, pCaller");
    asm("add $0x18, %ecx");
    asm("mov (%ecx), %eax");
    asm("test %eax, %eax");
    asm("je invalidscript");
    asm("push %eax");
    //asm ("call *myRunScriptPart");
    asm("call *%0" : : "a"(myRunScriptPart));
    asm("add $4, %esp");

    asm("original:");
    asm("popa");
    asm("mov (%ebp), %eax");
    asm("mov 0x4(%eax), %eax");
    asm("mov %eax, pCaller");
    asm("mov 0xC(%ebp), %eax");
    asm("push %eax");
    asm("mov 0x8(%ebp), %eax");
    asm("push %eax");
    asm("mov $d_ret_code_runscript, %eax");
    asm("call *%eax");

    asm("push %eax");
    asm("push %ecx");
    asm("push %edx");
    //asm ("push $0");
    //asm ("call StopTimer");
    asm("call *%0" : : "a"(StopTimer));
    asm("jmp cleanup");

    asm("invalidscript:");
    asm("popa");
    asm("mov 0xC(%ebp), %eax");
    asm("push %eax");
    asm("mov 0x8(%ebp), %eax");
    asm("push %eax");
    asm("mov $d_ret_code_runscript, %eax");
    asm("call *%eax");

    asm("push %eax");
    asm("push %ecx");
    asm("push %edx");
    //asm ("push $0");

    asm("cleanup:");
    asm("pop %edx");
    asm("pop %ecx");
    asm("pop %eax");
    asm("add $0x8, %esp");
    asm("pop %ebp");

    asm("ret");
}

void MyCrossArea(char *gameObject)
{
    char* tag = (char*)(*(int*)(gameObject + 0x18));
    //profiler.Log(1, "MyCrossArea: %s\n", tag);

    if (tag != NULL) {
        if (iCallDepth < MAX_CALLDEPTH - 1)
            iCallDepth++;
        else
            profiler.Log(1, "Maximum call depth reached!\n");

        emptyScript = false;
        scriptName[iCallDepth][0] = '@';
        scriptName[iCallDepth][1] = 0x0;
        strncat(scriptName[iCallDepth], tag, 15);
        scriptName[iCallDepth][16] = 0x0;
        ulScriptCounter++;

        if (profiler.m_LogLevel == profiler.logCallstack) {
            profiler.Log(1, "%s (calldepth %d, pathfinding)\n", tag, iCallDepth);
            //fflush(profiler.m_fFile);
        }
        gettimeofday(&tvLast[iCallDepth], NULL);
        //QueryPerformanceCounter(&liLast[iCallDepth]);
    } else
        emptyScript = true;
}


void CrossAreaHookProc(const char *pThis, int depth, int a2, void *pPathfindInformation)
{
    /*
    int depth,int,CPathfindInformation *
    __asm {

    	push ecx	  // save register contents
    	push edx
    	push ebx
    	push esi
    	push edi
    	push ebp	  // prolog 1
        mov ebp, esp  // prolog 2

    	mov eax, dword ptr ss:[esp+0x1c] // recursion depth
    	cmp al, 0
    	jne skip

    	mov eax, dword ptr ss:[esp+0x5c] // param 1
    	push eax
    	call MyCrossArea
    	add esp, 0x4

    	pop ebp		// restore register contents
    	pop edi
    	pop esi
    	pop ebx
    	pop edx
    	pop ecx

    	mov eax, dword ptr ss:[esp+0xc] // arg 3
    	push eax
    	mov eax, dword ptr ss:[esp+0xc] // arg 2
    	push eax
    	mov eax, dword ptr ss:[esp+0xc] // arg 1
    	push eax

    	call CrossAreaNextHook // call original function

    	// save return value
    	push eax
    	push 0

    	call StopTimer
    	jmp cleanup

    skip:
    	pop ebp		// restore register contents
    	pop edi
    	pop esi
    	pop ebx
    	pop edx
    	pop ecx

    	mov eax, dword ptr ss:[esp+0xc] // arg 3
    	push eax
    	mov eax, dword ptr ss:[esp+0xc] // arg 2
    	push eax
    	mov eax, dword ptr ss:[esp+0xc] // arg 1
    	push eax

    	call CrossAreaNextHook // call original function

    	// save return value
    	push eax
    	push 0

    cleanup:
    	// cleanup stack
    	add esp, 0x8
    	pop eax
    	add esp, 0xc
    	push eax

    	// put return value of StartConditional() script in EAX
    	sub esp, 0x10
    	pop eax
    	add esp, 0xc

        retn

    }*/
}

void MyPathfind(const char *gameArea)
{
    char* tag = (char*) gameArea + 0xb4;
    //profiler.Log(1, "MyPathfind: %s\n", tag);

    if (tag != NULL) {
        if (iCallDepth < MAX_CALLDEPTH - 1)
            iCallDepth++;
        else
            profiler.Log(1, "Maximum call depth reached!\n");

        emptyScript = false;
        scriptName[iCallDepth][0] = '$';
        scriptName[iCallDepth][1] = 0x0;
        strncat(scriptName[iCallDepth], tag, 15);
        scriptName[iCallDepth][16] = 0x0;
        ulScriptCounter++;

        if (profiler.m_LogLevel == profiler.logCallstack) {
            profiler.Log(1, "%s (calldepth %d, pathfinding)\n", tag, iCallDepth);
            //fflush(profiler.m_fFile);
        }
        gettimeofday(&tvLast[iCallDepth], NULL);
    } else
        emptyScript = true;

}


int PathfindHookProc(const char * pthis, const char * NWTile, const char * NWArea, const char * PathFindInfo, int depth, float a2, int a3, float a4, float a5, float a6, float a7, float a8, int a9)
{
    int retval;
    if (depth == 0) {
        MyPathfind(NWArea);
        retval = PathfindNextHook(pthis, NWTile, NWArea, PathFindInfo, depth, a2, a3, a4, a5, a6, a7, a8, a9);
        StopTimer();
        return retval;
    } else {
        return PathfindNextHook(pthis, NWTile, NWArea, PathFindInfo, depth, a2, a3, a4, a5, a6, a7, a8, a9);
    }

//CNWTileSurfaceMesh::IntraTileDFS(CNWTile *,CNWArea *,CPathfindInformation *,int,float,int,float,float,float,float,float,int)
    //PathfindOrig(pthis, NWTile, NWArea, PathFindInfo, a1, a2, a3, a4, a5, a6, a7, a8, a9);
    /*
    __asm {

    	push ecx	  // save register contents
    	push edx
    	push ebx
    	push esi
    	push edi
    	push ebp	  // prolog 1
        mov ebp, esp  // prolog 2

    	mov eax, dword ptr ss:[esp+0x28] // recursion depth
    	cmp al, 0
    	jne skip

    	mov eax, dword ptr ss:[esp+0x20] // param 1
    	push eax
    	call MyPathfind
    	add esp, 0x4

    	pop ebp		// restore register contents
    	pop edi
    	pop esi
    	pop ebx
    	pop edx
    	pop ecx

    	mov eax, dword ptr ss:[esp+0x30] // arg 12
    	push eax
    	mov eax, dword ptr ss:[esp+0x30] // arg 11
    	push eax
    	mov eax, dword ptr ss:[esp+0x30] // arg 10
    	push eax
    	mov eax, dword ptr ss:[esp+0x30] // arg 9
    	push eax
    	mov eax, dword ptr ss:[esp+0x30] // arg 8
    	push eax
    	mov eax, dword ptr ss:[esp+0x30] // arg 7
    	push eax
    	mov eax, dword ptr ss:[esp+0x30] // arg 6
    	push eax
    	mov eax, dword ptr ss:[esp+0x30] // arg 5
    	push eax
    	mov eax, dword ptr ss:[esp+0x30] // arg 4
    	push eax
    	mov eax, dword ptr ss:[esp+0x30] // arg 3
    	push eax
    	mov eax, dword ptr ss:[esp+0x30] // arg 2
    	push eax
    	mov eax, dword ptr ss:[esp+0x30] // arg 1
    	push eax

    	call PathfindNextHook // call original function

    	// save return value
    	push eax
    	push 0

    	call StopTimer
    	jmp cleanup

    skip:
    	pop ebp		// restore register contents
    	pop edi
    	pop esi
    	pop ebx
    	pop edx
    	pop ecx

    	mov eax, dword ptr ss:[esp+0x30] // arg 12
    	push eax
    	mov eax, dword ptr ss:[esp+0x30] // arg 11
    	push eax
    	mov eax, dword ptr ss:[esp+0x30] // arg 10
    	push eax
    	mov eax, dword ptr ss:[esp+0x30] // arg 9
    	push eax
    	mov eax, dword ptr ss:[esp+0x30] // arg 8
    	push eax
    	mov eax, dword ptr ss:[esp+0x30] // arg 7
    	push eax
    	mov eax, dword ptr ss:[esp+0x30] // arg 6
    	push eax
    	mov eax, dword ptr ss:[esp+0x30] // arg 5
    	push eax
    	mov eax, dword ptr ss:[esp+0x30] // arg 4
    	push eax
    	mov eax, dword ptr ss:[esp+0x30] // arg 3
    	push eax
    	mov eax, dword ptr ss:[esp+0x30] // arg 2
    	push eax
    	mov eax, dword ptr ss:[esp+0x30] // arg 1
    	push eax

    	call PathfindNextHook // call original function

    	// save return value
    	push eax
    	push 0

    cleanup:
    	// cleanup stack
    	add esp, 0x8
    	pop eax
    	add esp, 0x30 // number of parameters * 4
    	push eax

    	// put return value of StartConditional() script in EAX
    	sub esp, 0x34 // number of parameters * 4 + 4
    	pop eax
    	add esp, 0x30 // number of parameters * 4

        retn
    }*/
}


DWORD FindHookRunScript()
{
    unsigned long start_addr = 0x08048000, end_addr = 0x08300000;
    char *ptr = (char *) start_addr;

    while (ptr < (char *) end_addr) {
        if ((ptr[0] == (char) 0x55) &&
                (ptr[1] == (char) 0x89) &&
                (ptr[2] == (char) 0xE5) &&
                (ptr[3] == (char) 0x57) &&
                (ptr[4] == (char) 0x56) &&

                (ptr[9] == (char) 0x8B) &&
                (ptr[0xA] == (char) 0x7D) &&
                (ptr[0xB] == (char) 0x08) &&
                (ptr[0xC] == (char) 0x8D) &&
                (ptr[0xD] == (char) 0x87) &&
                (ptr[0xE] == (char) 0x70) &&
                (ptr[0xF] == (char) 0x01) &&
                (ptr[0x10] == (char) 0x00) &&
                (ptr[0x11] == (char) 0x00)
           )

            return (DWORD) ptr;
        else
            ptr++;

    }
    return 0;
}

DWORD FindHookCrossAreaPathFind()
{
    /*
    CNWSModule::InterAreaDFS(int depth,int,CPathfindInformation *)
    */

    unsigned long start_addr = 0x08048000, end_addr = 0x08300000;
    char *ptr = (char *) start_addr;

    while (ptr < (char *) end_addr) {
        if ((ptr[0] == (char) 0x55) &&
                (ptr[1] == (char) 0x89) &&
                (ptr[2] == (char) 0xE5) &&
                (ptr[3] == (char) 0x57) &&
                (ptr[4] == (char) 0x56) &&

                (ptr[9] == (char) 0x8B) &&
                (ptr[0xA] == (char) 0x55) &&
                (ptr[0xB] == (char) 0x14) &&
                (ptr[0xC] == (char) 0x8B) &&
                (ptr[0xD] == (char) 0x82) &&
                (ptr[0xE] == (char) 0x9C) &&
                (ptr[0xF] == (char) 0x00) &&
                (ptr[0x10] == (char) 0x00) &&
                (ptr[0x11] == (char) 0x00)
           )

            return (DWORD) ptr;
        else
            ptr++;

    }
    return 0;
}

DWORD FindHookPathFind()
{
    /*
    CNWTileSurfaceMesh::IntraTileDFS(CNWTile *,CNWArea *,CPathfindInformation *,int,float,int,float,float,float,float,float,int)
    */

    unsigned long start_addr = 0x08048000, end_addr = 0x08300000;
    char *ptr = (char *) start_addr;

    while (ptr < (char *) end_addr) {
        if ((ptr[0] == (char) 0x55) &&
                (ptr[1] == (char) 0x89) &&
                (ptr[2] == (char) 0xE5) &&
                (ptr[3] == (char) 0x57) &&
                (ptr[4] == (char) 0x56) &&
                (ptr[5] == (char) 0x53) &&

                (ptr[9] == (char) 0x8B) &&
                (ptr[0xA] == (char) 0x7D) &&
                (ptr[0xB] == (char) 0x08) &&
                (ptr[0xC] == (char) 0x8B) &&
                (ptr[0xD] == (char) 0x77) &&
                (ptr[0xE] == (char) 0x68) &&
                (ptr[0xF] == (char) 0x85)
           )

            return (DWORD) ptr;
        else
            ptr++;

    }
    return 0;
}

void Release()
{
    struct timeval tvCurrent;
    gettimeofday(&tvCurrent, NULL);
    DWORD dwStatisticMsec = 0;
    //DWORD dwStatisticMsec = (DWORD) (((liCurrent.QuadPart - liLastStatistic.QuadPart) * 1000) / liFrequency.QuadPart);
    FlushStatistics(dwStatisticMsec);
}

void
d_enable_write(unsigned long location)
{
    char *page;
    page = (char *) location;
    page = (char *)(((int) page + PAGESIZE - 1) & ~(PAGESIZE - 1));
    page -= PAGESIZE;

    if (mprotect(page, PAGESIZE, PROT_WRITE | PROT_READ | PROT_EXEC))
        perror("mprotect");
}

int intlen = -1;

void
d_redirect(long from, long to, unsigned char* rbuf, long len = 0)
{
    // enable write to code pages
    d_enable_write(from);
    // copy orig code stub to our "ret_code"
    len = len ? len : sizeof(d_jmp_code) - 1; // - trailing 0x00
    memcpy((void *) rbuf, (const void *) from, len);
    // make ret code
    *(long *)(d_jmp_code + 1) = from + len;
    memcpy((char *) rbuf + len, (const void *) d_jmp_code, 6);
    // make hook code
    *(long *)(d_jmp_code + 1) = to;
    memcpy((void *) from, (const void *) d_jmp_code, 6);
}

void HookRunScript()
{
    old_RunScript = FindHookRunScript();
    old_CrossAreaPathFind = FindHookCrossAreaPathFind();
    old_PathFind = FindHookPathFind();

    if (old_RunScript)
        d_redirect(old_RunScript, (unsigned long)RunScriptHookProc, d_ret_code_runscript, 12);
    //HookCode((PVOID) old_RunScript, RunScriptHookProc, (PVOID*) &RunScriptNextHook);

    /*if (old_CrossAreaPathFind)
    	d_redirect (old_CrossAreaPathFind, (unsigned long)CrossAreaHookProc, d_ret_code_crossarea, 12);
    	//success_crossarea = HookCode((PVOID) old_CrossAreaPathFind, CrossAreaHookProc, (PVOID*) &CrossAreaNextHook);*/

    if (old_PathFind)
        d_redirect(old_PathFind, (unsigned long)PathfindHookProc, d_ret_code_pathfind, 12);
    *(DWORD*)&PathfindNextHook = (DWORD) &d_ret_code_pathfind;
    //success_pathfind = HookCode((PVOID) old_PathFind, PathfindHookProc, (PVOID*) &PathfindNextHook);

    // Performance analysis variables
    iColumn = 0;
    ulTotalRuntime = 0;
    ulTotalLast = 0;
    ulScriptCounter = 0;
    iCallDepth = -1;
    construct_table(&scriptHash, 2048);
    gettimeofday(&tvLastStatistic, NULL);

    // Log file
    profiler.WriteLogHeader();

    if (old_RunScript)
        profiler.Log(1, "* RunScript hooked (symbol: >).\n");
    else
        profiler.Log(1, "* Could not find RunScript function or hook failed: %x\n", old_RunScript);

    if (old_CrossAreaPathFind)
        profiler.Log(1, "* Cross area pathfinding hooked (symbol: @)\n");
    else
        profiler.Log(1, "* Could not find Cross area pathfinding function or hook failed: %x\n", old_CrossAreaPathFind);

    if (old_PathFind)
        profiler.Log(1, "* Tile pathfinding hooked (symbol: $)\n");
    else
        profiler.Log(1, "* Could not find pathfinding function or hook failed: %x\n", old_PathFind);
    //fflush(profiler.m_fFile);

    return;
}


