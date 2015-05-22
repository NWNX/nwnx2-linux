/***************************************************************************
    NWN Resource Manager  - Hook DemandRes function in the server
    Copyright (C) 2005 Ingmar Stieger (papillon@nwnx.org)
    copyright (c) 2006 dumbo (dumbo@nm.ru) & virusman (virusman@virusman.ru)

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
#ifndef PAGESIZE
#define PAGESIZE 4096
#endif

#include "HookDemandRes.h"
#include "NWNXResMan.h"
#include "NwnDefines.h"

unsigned char d_jmp_code[] = "\x68\x60\x70\x80\x90"       /* push dword 0x90807060 */
                             "\xc3\x90\x90\x90\x90";//x00 /* ret , nop , nop       */

unsigned char d_ret_code_res[0x20];
unsigned char d_ret_code_dem[0x20];
unsigned char d_ret_code_exi[0x20];

//-----------------------

extern CNWNXResMan resman;

NwnResType lastResType;
char lastResRef[17];

int (*CExoResMan__FreeChunk_int)(CExoResMan *pResMan) = (int(*)(CExoResMan *)) 0x082AFC7C;
char *(*DemandRes_orig)(CExoResMan * pthis, CResStruct* cRes);
int (*RetrieveResEntry_orig)(CExoResMan * pthis, char* resRef, NwnResType resType, void ** v1, void** v2);
int (*CExoResMan__Exists_orig)(CExoResMan *pthis, char* resRef, unsigned short resType, int *tableType);


int CExoResMan__FreeChunk(CExoResMan *pResMan)
{
    return CExoResMan__FreeChunk_int(pResMan);
}

int RetrieveResEntry(CExoResMan * pthis, char* resRef, NwnResType resType, void ** v1, void** v2)
{
    lastResType = resType;
    memcpy(lastResRef, resRef, 16);
    lastResRef[16] = 0x0;
    return RetrieveResEntry_orig(pthis, resRef, resType, v1, v2);
}

char *lastRet = 0;

char* DemandRes(CExoResMan * pthis, CResStruct* cRes)
{
    lastRet = resman.DemandRes(pthis, cRes, lastResRef, lastResType);
    if (lastRet)
        return lastRet;
    else
        return DemandRes_orig(pthis, cRes);
    /*
      resman.Log(0, "cRes(pClass=%08lX, pResData=%08lX, pResName=%08lX), lastResRef=%s, lastResType=%d, ret=%d\n",
        cRes->pClass, cRes->pResData, cRes->pResName, lastResRef, lastResType, lastRet );
    */
}

int CExoResMan__Exists(CExoResMan *pthis, char* resRef, unsigned short resType, int *tableType)
{
    if (resman.ResourceExists(resRef, (NwnResType) resType))
        return 1;
    else
        return CExoResMan__Exists_orig(pthis, resRef, resType, tableType);
}

// 55 89 e5 57 56 53 83 ec 18 8b 75 08 83 c6 1c
unsigned long FindHookRetrieveResEntry()
{
    unsigned long start_addr = 0x08048000, end_addr = 0x08300000;
    char *ptr = (char *) start_addr;

    while (ptr < (char *) end_addr) {
        if ((ptr[0] == (char) 0x55) &&
                (ptr[1] == (char) 0x89) &&
                (ptr[2] == (char) 0xE5) &&
                (ptr[3] == (char) 0x57) &&
                (ptr[4] == (char) 0x56) &&
                (ptr[5] == (char) 0x53) &&
                (ptr[6] == (char) 0x83) &&
                (ptr[7] == (char) 0xEC) &&
                (ptr[8] == (char) 0x18) &&
                (ptr[9] == (char) 0x8B) &&
                (ptr[10] == (char) 0x75) &&
                (ptr[11] == (char) 0x08) &&
                (ptr[12] == (char) 0x83) &&
                (ptr[13] == (char) 0xC6) &&
                (ptr[14] == (char) 0x1C)
           )
            return (unsigned long) ptr;
        else
            ptr++;
    }
    return 0;
}

// 55 89 e5 57 56 53 83 ec 1c 8b 75 0c 85 f6 8b 7d 08 0f
unsigned long FindHookDemandRes()
{
    unsigned long start_addr = 0x08048000, end_addr = 0x08300000;
    char *ptr = (char *) start_addr;

    while (ptr < (char *) end_addr) {
        if ((ptr[0] == (char) 0x55) &&
                (ptr[1] == (char) 0x89) &&
                (ptr[2] == (char) 0xE5) &&
                (ptr[3] == (char) 0x57) &&
                (ptr[4] == (char) 0x56) &&
                (ptr[5] == (char) 0x53) &&
                (ptr[6] == (char) 0x83) &&
                (ptr[7] == (char) 0xEC) &&
                (ptr[8] == (char) 0x1C) &&
                (ptr[9] == (char) 0x8B) &&
                (ptr[10] == (char) 0x75) &&
                (ptr[11] == (char) 0x0C) &&
                (ptr[12] == (char) 0x85) &&
                (ptr[13] == (char) 0xF6) &&
                (ptr[14] == (char) 0x8B) &&
                (ptr[15] == (char) 0x7D) &&
                (ptr[16] == (char) 0x08) &&
                (ptr[17] == (char) 0x0F)
           )
            return (unsigned long) ptr;
        else
            ptr++;
    }
    return 0;
}

//
void d_enable_write(unsigned long location)
{
    char *page;
    page = (char *) location;
    page = (char *)(((int) page + PAGESIZE - 1) & ~(PAGESIZE - 1));
    page -= PAGESIZE;

    if (mprotect(page, PAGESIZE, PROT_WRITE | PROT_READ | PROT_EXEC))
        perror("mprotect");
}

void d_redirect(long from, long to, unsigned char* rbuf, long len = 0)
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

int HookFunctions()
{
    unsigned long old_RetrieveResEntry = FindHookRetrieveResEntry();
    if (old_RetrieveResEntry) {
        resman.Log(0, "o RetrieveResEntry hooked at %x.\n", old_RetrieveResEntry);
        d_redirect(old_RetrieveResEntry, (unsigned long)RetrieveResEntry, d_ret_code_res, 12);
        *(unsigned long*)&RetrieveResEntry_orig = (unsigned long)&d_ret_code_res;
    } else {
        resman.Log(0, "! RetrieveResEntry locate failed.\n");
        return 0;
    }

    unsigned long old_DemandRes = FindHookDemandRes();
    if (old_DemandRes) {
        resman.Log(0, "o DemandRes hooked at %x.\n", old_DemandRes);
        d_redirect(old_DemandRes, (unsigned long)DemandRes, d_ret_code_dem, 12);
        *(unsigned long*)&DemandRes_orig = (unsigned long)&d_ret_code_dem;
    } else {
        resman.Log(0, "! DemandRes locate failed.\n");
        return 0;
    }

    unsigned long old_Exists = 0x082B393C;
    if (old_Exists) {
        resman.Log(0, "o CExoResMan::Exists hooked at %x.\n", old_Exists);
        d_redirect(old_Exists, (unsigned long)CExoResMan__Exists, d_ret_code_exi, 11);
        *(unsigned long*)&CExoResMan__Exists_orig = (unsigned long)&d_ret_code_exi;
    } else {
        resman.Log(0, "! CExoResMan::Exists locate failed.\n");
        return 0;
    }


    lastResRef[0] = 0x0;
    return 1;
}
