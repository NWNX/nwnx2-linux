/***************************************************************************
    Lua plugin for NWNX  - hooks implementation
    (c) 2008 virusman (virusman@virusman.ru)
    modified - 2010 pardik (d.paroli@tiscali.it)

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
#include <stdarg.h>
#include <time.h>

#include <limits.h>		/* for PAGESIZE */
#ifndef PAGESIZE
#define PAGESIZE 4096
#endif

#include "FunctionHooks.h"
#include "NWNXLua.h"
#include "AssemblyHelper.cpp"

extern CNWNXLua lua;
AssemblyHelper asmhelp;

unsigned char d_jmp_code[] = "\x68\x60\x70\x80\x90"       /* push dword 0x90807060 */
                             "\xc3\x90\x90\x90\x90";//x00 /* ret , nop , nop       */

unsigned char d_ret_code_sm[0x20];
unsigned char d_ret_code_sdm[0x20];
unsigned char d_ret_code_sco[0x20];
unsigned char d_ret_code_rco[0x20];

unsigned long lastRet;
bool bReturn = 0;

dword **g_pVirtualMachine;


////////////////////////////////////////////////////////////////////
// FUNCTIONS
////////////////////////////////////////////////////////////////////

int (*CNWVirtualMachineCommands_ExecuteCommand)(void *pCommands, dword nCommandID, int arg_8);
int (*CVirtualMachine_StackPopInteger)(void *pVM, int *buf);
int (*CVirtualMachine_StackPopFloat)(void *pVM, float *buf);
int (*CVirtualMachine_StackPopString)(void *pVM, CExoString *buf);
int (*CVirtualMachine_StackPopVector)(void *pVM, Vector *buf);
int (*CVirtualMachine_StackPopObject)(void *pVM, dword *buf);
int (*CVirtualMachine_StackPopEngineStructure)(void *pVM, dword nStructType, void **buf);

int (*CVirtualMachine_StackPushInteger)(void *pVM, int value);
int (*CVirtualMachine_StackPushFloat)(void *pVM, float value);
int (*CVirtualMachine_StackPushString)(void *pVM, CExoString *value);
int (*CVirtualMachine_StackPushVector)(void *pVM, Vector value);
int (*CVirtualMachine_StackPushObject)(void *pVM, dword value);
int (*CVirtualMachine_StackPushEngineStructure)(void *pVM, dword nStructType, void *value);

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
d_redirect(long from, long to, unsigned char *d_ret_code, long len = 0)
{
    // enable write to code pages
    d_enable_write(from);
    // copy orig code stub to our "ret_code"
    len = len ? len : sizeof(d_jmp_code) - 1; // - trailing 0x00
    intlen = len;
    memcpy((void *) d_ret_code, (const void *) from, len);
    // make ret code
    *(long *)(d_jmp_code + 1) = from + len;
    memcpy((char *) d_ret_code + len, (const void *) d_jmp_code, 6);
    // make hook code
    *(long *)(d_jmp_code + 1) = to;
    memcpy((void *) from, (const void *) d_jmp_code, 6);
}

int StackPopInteger(int *buf)
{
    return CVirtualMachine_StackPopInteger(*g_pVirtualMachine, buf);
}

int StackPopFloat(float *buf)
{
    return CVirtualMachine_StackPopFloat(*g_pVirtualMachine, buf);
}

int StackPopString(char **buf)
{
    CExoString *str = (CExoString *) malloc(sizeof(CExoString));
    str->Text = NULL;
    str->Length = 0;
    int retval = CVirtualMachine_StackPopString(*g_pVirtualMachine, str);
    if (!str->Text)
        *buf = (char *)"";//aggiunto cast by Daniele Paroli
    else
        *buf = str->Text;
    free(str);
    return retval;
}

int StackPopVector(Vector *buf)
{
    return CVirtualMachine_StackPopVector(*g_pVirtualMachine, buf);
}

int StackPopObject(dword *buf)
{
    return CVirtualMachine_StackPopObject(*g_pVirtualMachine, buf);
}

int StackPopEngineStructure(dword nStructType, void **buf)
{
    return CVirtualMachine_StackPopEngineStructure(*g_pVirtualMachine, nStructType, buf);
}

int StackPushInteger(int value)
{
    return CVirtualMachine_StackPushInteger(*g_pVirtualMachine, value);
}

int StackPushFloat(float value)
{
    return CVirtualMachine_StackPushFloat(*g_pVirtualMachine, value);
}

int StackPushString(char *value)
{
    return CVirtualMachine_StackPushString(*g_pVirtualMachine, (CExoString *) &value);
}

int StackPushVector(Vector value)
{
    return CVirtualMachine_StackPushVector(*g_pVirtualMachine, value);
}

int StackPushObject(dword value)
{
    return CVirtualMachine_StackPushObject(*g_pVirtualMachine, value);
}

int StackPushEngineStructure(dword nStructType, void *value)
{
    return CVirtualMachine_StackPushEngineStructure(*g_pVirtualMachine, nStructType, value);
}

dword GetObjectSelf()
{
    CVirtualMachine *pVM = (CVirtualMachine *) *g_pVirtualMachine;
    return pVM->ObjectID[pVM->RecursionLevel];
}

void *GetCommandsPtr()
{
    return *(void **)(*(dword *)(g_pVirtualMachine) + 0x398);
}

void VM_ExecuteCommand(dword nCommandID, int nArgsCount)
{
    CNWVirtualMachineCommands_ExecuteCommand(GetCommandsPtr(), nCommandID, nArgsCount);
}

void debug_function_addr(dword func, const char *name)
{
    lua.Log(2, "%s: %x\n", name, func);
}

int SCOproc(const int * pthis, char** database, char** key, char** player, int flags, unsigned char * pData, int size)
{
    if (*pthis) {
        if (memcmp(*database, "LUA", 3)) {
            asm("mov $d_ret_code_sco, %eax");
            asm("leave");
            asm("jmp *%eax");
        }
        asm("pusha");
        int lastRet = (unsigned long)lua.WriteSCO(*database, *key, *player, flags, pData, size);
        asm("popa");
        return lastRet;
    }
    return 0;
}

unsigned char * RCOproc(const int * pthis, char** database, char** key, char** player, int* arg4, int* size)
{
    if (*pthis) {
        if (memcmp(*database, "LUA", 3)) {
            asm("mov $d_ret_code_rco, %eax");
            asm("leave");
            asm("jmp *%eax");
        }
        asm("pusha");
        unsigned char * lastRet = lua.ReadSCO(*database, *key, *player, arg4, size);
        asm("popa");
        return lastRet;
    }
    return 0;
}

// finds the address of the SCO function
unsigned long
FindHookSCO(unsigned long sa = 0)
{
    unsigned long start_addr = 0x08048000, end_addr = 0x08300000;
    char *ptr = (char *) start_addr;
    if (sa) ptr = (char *)sa;

    while (ptr < (char *) end_addr) {
        if ((ptr[0] == (char) 0x55) &&
                (ptr[1] == (char) 0x89) &&
                (ptr[2] == (char) 0xe5) &&
                (ptr[3] == (char) 0x57) &&
                (ptr[4] == (char) 0x56) &&
                (ptr[5] == (char) 0x53) &&
                (ptr[0x18] == (char) 0x8b) &&
                (ptr[0x19] == (char) 0x1b) &&
                (ptr[0x1a] == (char) 0x85) &&
                (ptr[0x1b] == (char) 0xdb) &&
                (ptr[0x1c] == (char) 0x8a) &&
                (ptr[0x1d] == (char) 0x4d)
           )
            return (unsigned long) ptr;
        else
            ptr++;
    }
    return 0;
}

// finds the address of the RCO function
unsigned long
FindHookRCO(unsigned long sa = 0)
{
    unsigned long start_addr = 0x08048000, end_addr = 0x08300000;
    char *ptr = (char *) start_addr;
    if (sa) ptr = (char *)sa;

    while (ptr < (char *) end_addr) {
        if ((ptr[0] == (char) 0x55) &&
                (ptr[1] == (char) 0x89) &&
                (ptr[2] == (char) 0xe5) &&
                (ptr[3] == (char) 0x57) &&
                (ptr[4] == (char) 0x56) &&
                (ptr[5] == (char) 0x53) &&
                (ptr[0x09] == (char) 0x8b) &&
                (ptr[0x0a] == (char) 0x45) &&
                (ptr[0x0b] == (char) 0x08) &&
                (ptr[0x0c] == (char) 0x8b) &&
                (ptr[0x0d] == (char) 0x00) &&
                (ptr[0x0e] == (char) 0x85) &&
                (ptr[0x0f] == (char) 0xc0)
           )
            return (unsigned long) ptr;
        else
            ptr++;
    }
    return 0;
}

int HookFunctions()
{
    /*dword CExoNetInternal_StoreMessage =
    if(CExoNetInternal_StoreMessage) d_redirect (CExoNetInternal_StoreMessage, (unsigned long)StoreMessage, d_ret_code_sm, 9);*/

    *(dword*)&CNWVirtualMachineCommands_ExecuteCommand = asmhelp.FindFunctionBySignature("55 89 E5 8B 4D 0C 56 81 F9 ** ** 00 00 53 8B 75 08 7F 3D 8B 56 0C"); //0x082319C0

    *(dword*)&CVirtualMachine_StackPopInteger = asmhelp.FindFunctionBySignature("55 89 E5 57 56 53 83 EC 0C 8B 4D 08 8D 81 70 01 00 00 89 45 F0 8B B9 70 01 00 00 85 FF 7E 0D 4F"); //0x08262988
    *(dword*)&CVirtualMachine_StackPopFloat  = asmhelp.FindFunctionBySignature("55 89 E5 57 56 53 83 EC 0C 8B 4D 08 8D 81 70 01 00 00 89 45 F0 8B 99 70 01 00 00 85 DB 89 5D EC 7E 0D 4B 8B B9 7C 01 00 00 80 3C 3B 04"); //0x08262A64
    *(dword*)&CVirtualMachine_StackPopString = asmhelp.FindFunctionBySignature("55 89 E5 57 56 53 83 EC 0C 8B 5D 08 8D 83 70 01 00 00 89 45 F0 8B BB 70 01 00 00 85 FF 7E 0D 4F"); //0x08262BA4
    *(dword*)&CVirtualMachine_StackPopVector = asmhelp.FindFunctionBySignature("55 89 E5 57 56 53 83 EC 14 8D 5D F0 53 8B 75 08 56 8B 7D 0C E8 ** ** ** ** 89 C2 83 C4 10 83 FA"); //0x08264354
    *(dword*)&CVirtualMachine_StackPopObject = asmhelp.FindFunctionBySignature("55 89 E5 57 56 53 83 EC 0C 8B 4D 08 8D 81 70 01 00 00 89 45 F0 8B 99 70 01 00 00 85 DB 89 5D EC 7E 0D 4B 8B B9 7C 01 00 00 80 3C 3B 06"); //0x08262D88
    *(dword*)&CVirtualMachine_StackPopEngineStructure = asmhelp.FindFunctionBySignature("55 89 E5 57 56 53 83 EC 0C 8B 5D 08 8D 83 70 01 00 00 89 45 F0 8B BB 70 01 00 00 85 FF 8B 4D 0C"); //0x08262C88

    *(dword*)&CVirtualMachine_StackPushInteger = asmhelp.FindFunctionBySignature("55 89 E5 56 53 83 EC 08 8B 5D 08 8D 83 70 01 00 00 6A 03 8B 75 0C 50 E8"); //0x082642D8
    *(dword*)&CVirtualMachine_StackPushFloat = asmhelp.FindFunctionBySignature("55 89 E5 56 53 83 EC 08 8B 5D 08 8B 75 0C 8D 83 70 01 00 00 6A 04 50 E8"); //0x08264314
    *(dword*)&CVirtualMachine_StackPushString = asmhelp.FindFunctionBySignature("55 89 E5 57 56 53 83 EC 18 8B 7D 08 8B 5D 0C 6A 08 +24 59 5B 8D 87 70 01 00 00 6A 05 50 E8"); //0x082643BC
    *(dword*)&CVirtualMachine_StackPushVector = asmhelp.FindFunctionBySignature("55 89 E5 57 56 53 83 EC 14 8B 5D 08 8D B3 70 01 00 00 6A 04 8B 7D 0C 56 E8 ** ** ** ** 58 5A 8B 8B 70 01 00 00"); //0x08262B24
    *(dword*)&CVirtualMachine_StackPushObject = asmhelp.FindFunctionBySignature("55 89 E5 56 53 83 EC 08 8B 5D 08 8D 83 70 01 00 00 6A 06 8B 75 0C 50 E8"); //0x082644A0
    *(dword*)&CVirtualMachine_StackPushEngineStructure = asmhelp.FindFunctionBySignature("55 89 E5 57 56 53 83 EC 0C 8B 75 08 8B 86 98 03 00 00 85 C0 8B 7D 0C 75 07 31 C0 EB 40"); //0x08264438

    InitConstants();

    debug_function_addr((dword)CNWVirtualMachineCommands_ExecuteCommand, "CNWVirtualMachineCommands_ExecuteCommand");
    debug_function_addr((dword)CVirtualMachine_StackPopInteger, "CVirtualMachine_StackPopInteger");
    debug_function_addr((dword)CVirtualMachine_StackPopFloat, "CVirtualMachine_StackPopFloat");
    debug_function_addr((dword)CVirtualMachine_StackPopString, "CVirtualMachine_StackPopString");
    debug_function_addr((dword)CVirtualMachine_StackPopVector, "CVirtualMachine_StackPopVector");
    debug_function_addr((dword)CVirtualMachine_StackPopObject, "CVirtualMachine_StackPopObject");
    debug_function_addr((dword)CVirtualMachine_StackPopEngineStructure, "CVirtualMachine_StackPopEngineStructure");
    debug_function_addr((dword)CVirtualMachine_StackPushInteger, "CVirtualMachine_StackPushInteger");
    debug_function_addr((dword)CVirtualMachine_StackPushFloat, "CVirtualMachine_StackPushFloat");
    debug_function_addr((dword)CVirtualMachine_StackPushString, "CVirtualMachine_StackPushString");
    debug_function_addr((dword)CVirtualMachine_StackPushVector, "CVirtualMachine_StackPushVector");
    debug_function_addr((dword)CVirtualMachine_StackPushObject, "CVirtualMachine_StackPushObject");
    debug_function_addr((dword)CVirtualMachine_StackPushEngineStructure, "CVirtualMachine_StackPushEngineStructure");

    dword sco = FindHookSCO();
    if (sco) {
        lua.Log(0, "o SCO located at %x.\n", sco);
        d_redirect(sco, (unsigned long)SCOproc, d_ret_code_sco, 12);
    } else {
        lua.Log(0, "! SCO locate failed.\n");
        return 0;
    }

    dword rco = FindHookRCO();
    if (rco) {
        lua.Log(0, "o RCO located at %x.\n", rco);
        d_redirect(rco, (unsigned long)RCOproc, d_ret_code_rco, 12);
    } else {
        lua.Log(0, "! RCO locate failed.\n");
        return 0;
    }
    lua.Log(2, "All functions set\n");
    return true;
}

void InitConstants()
{
    *(dword*)&g_pVirtualMachine = 0x0832F1EC;
}

