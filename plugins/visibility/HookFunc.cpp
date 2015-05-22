/***************************************************************************
    Visibility plugin for NWNX  - hooks implementation
    (c) 2007-2010 virusman (virusman@virusman.ru)

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

#include <limits.h>		/* for PAGESIZE */
#ifndef PAGESIZE
#define PAGESIZE 4096
#endif

#include "HookFunc.h"
#include "NWNXVisibility.h"

extern CNWNXVisibility visibility;

int (*CNWSMessage__TestObjectVisible_orig)(void *pMessage, CNWSObject *pObject1, CNWSObject *pObject2);

unsigned char d_jmp_code[] = "\x68\x60\x70\x80\x90"       /* push dword 0x90807060 */
                             "\xc3\x90\x90\x90\x90";//x00 /* ret , nop , nop       */
unsigned char d_ret_code_tov[0x20];


int CNWSMessage__TestObjectVisible(void *pMessage, CNWSObject *pObject1, CNWSObject *pObject2)
{
    dword oObject1 = pObject1->ObjectID;
    dword oObject2 = pObject2->ObjectID;
    int nResult = 0;
    if (!visibility.TestVisibility(oObject1, oObject2, nResult)) {
        nResult = CNWSMessage__TestObjectVisible_orig(pMessage, pObject1, pObject2);
    }
    visibility.Log(3, "Visibility check: %x - %x: %d\n", pObject1->ObjectID, pObject2->ObjectID, nResult);
    return nResult;
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

int HookFunctions()
{
    dword org_TestObjectVisible = 0x0806C6E8;
    d_redirect(org_TestObjectVisible, (unsigned long)CNWSMessage__TestObjectVisible, d_ret_code_tov, 12);
    *(unsigned long*)&CNWSMessage__TestObjectVisible_orig = (unsigned long)&d_ret_code_tov;

    return 1;
}


