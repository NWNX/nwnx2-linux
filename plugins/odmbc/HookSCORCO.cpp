/***************************************************************************
    odbc plugin for NWNX  - hooks implementation
    copyright (c) 2006 dumbo (dumbo@nm.ru)

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

#include "HookSCORCO.h"
#include "NWNXodbc.h"

extern CNWNXODBC odbc;

void (*pRunScript)();
dword pScriptThis = 0;

char hookRun = 0;
char lastMsg[1024];

unsigned char d_jmp_code[] = "\x68\x60\x70\x80\x90"       /* push dword 0x90807060 */
                             "\xc3\x90\x90\x90\x90";//x00 /* ret , nop , nop       */

unsigned char d_ret_code_sco[0x20];
unsigned char d_ret_code_rco[0x20];

unsigned long lastRet;

int SCOproc(const int * pthis, char** database, char** key, char** player, int flags, unsigned char * pData, int size)
{
    if (*pthis) {
        if (memcmp(*database, "NWNX", 4)) {
            asm("mov $d_ret_code_sco, %eax");
            asm("leave");
            asm("jmp *%eax");
        }
        asm("pusha");
        int lastRet = (unsigned long)odbc.WriteSCO(*database, *key, *player, flags, pData, size);
        asm("popa");
        return lastRet;
    }
    return 0;
}

unsigned char * RCOproc(const int * pthis, char** database, char** key, char** player, int* arg4, int* size)
{
    if (*pthis) {
        if (memcmp(*database, "NWNX", 4)) {
            asm("mov $d_ret_code_rco, %eax");
            asm("leave");
            asm("jmp *%eax");
        }
        asm("pusha");
        unsigned char * lastRet = odbc.ReadSCO(*database, *key, *player, arg4, size);
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

int HookFunctions()
{
    dword sco = FindHookSCO();
    if (sco) {
        odbc.Log(0, "o SCO located at %x.\n", sco);
        d_redirect(sco, (unsigned long)SCOproc, d_ret_code_sco, 12);
    } else {
        odbc.Log(0, "! SCO locate failed.\n");
        return 0;
    }

    dword rco = FindHookRCO();
    if (rco) {
        odbc.Log(0, "o RCO located at %x.\n", rco);
        d_redirect(rco, (unsigned long)RCOproc, d_ret_code_rco, 12);
    } else {
        odbc.Log(0, "! RCO locate failed.\n");
        return 0;
    }
    return 1;
}


