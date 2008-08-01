
/***************************************************************************
    Structs plugin for NWNX  - hooks implementation
    Copyright (C) 2007 Doug Swarin (zac@intertex.net)

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

#include <stdio.h>
#include <string.h>

#include <sys/types.h>
#include <sys/mman.h>

#include <dlfcn.h>

#include <limits.h>             /* for PAGESIZE */
#ifndef PAGESIZE
#define PAGESIZE 4096
#endif

#include "HookFunc.h"
#include "NWNXStruct.h"

#define MAX_EFFECTS	8

unsigned long orig_Struct, jump_Struct, last_Struct;

unsigned char restore_Struct[9];
unsigned char replace_Struct[10] = "\x68\x90\x90\x90\x90\xc3\x90\x90\x90";

void StructHookProc() {
    asm("leave");

    /* duplicate the work originally done */
    asm("mov 0x10(%esi), %eax");
    asm("mov 0xc(%ebp), %edi");
    asm("mov 0x8(%edx), %ecx");

    /* push the struct address onto the stack and pop it into
     * our cached last struct variable */
    asm("pushl (%eax,%edi,4)");
    asm("popl last_Struct");

#if 0
    asm("pusha");

    memmove(&(last_Structs[1]), &(last_Structs[0]),
        sizeof(unsigned long) * (MAX_EFFECTS - 1));
    last_Structs[0] = last_Struct;

    asm("popa");
#endif

    asm("push jump_Struct");
    asm("ret");
}

/* 8B 46 10 8B 7D 0C 8B 4A  08 FF 34 B8 0F BE 04 1F */
unsigned long FindStructHook() {
    unsigned long start_addr = 0x08048000, end_addr = 0x08300000;

    char *ptr = (char *)start_addr;

    while (ptr < (char *)end_addr) {
        if (ptr[0x0] == (char)0x8b &&
            ptr[0x1] == (char)0x46 &&
            ptr[0x2] == (char)0x10 &&
            ptr[0x3] == (char)0x8b &&
            ptr[0x4] == (char)0x7d &&
            ptr[0x5] == (char)0x0c &&
            ptr[0x6] == (char)0x8b &&
            ptr[0x7] == (char)0x4a &&
            ptr[0x8] == (char)0x08 &&
            ptr[0x9] == (char)0xff &&
            ptr[0xa] == (char)0x34 &&
            ptr[0xb] == (char)0xb8 &&
            ptr[0xc] == (char)0x0f &&
            ptr[0xd] == (char)0xbe &&
            ptr[0xe] == (char)0x04 &&
            ptr[0xf] == (char)0x1f)
            return (unsigned long)ptr;
        else
            ptr++;
    }

    return 0;
}

void ActivateStructFunctionHook() {
    memcpy((char *)orig_Struct, replace_Struct, sizeof(restore_Struct));
}

void DeactivateStructFunctionHook() {
    memcpy((char *)orig_Struct, restore_Struct, sizeof(restore_Struct));
}

unsigned long GetLastStruct(int idx) {
    if (idx < 0 || idx >= MAX_EFFECTS)
        return 0;

#if 0
    return last_Structs[idx];
#else
    return last_Struct;
#endif
}

static void enable_write(unsigned long location) {
    char *page;

    page = (char *)location;
    page = (char *)(((int)page + PAGESIZE - 1) & ~(PAGESIZE - 1));
    page -= PAGESIZE;

    if (mprotect(page, PAGESIZE, PROT_WRITE | PROT_READ | PROT_EXEC))
        perror("mprotect");
}

unsigned long FindStructFunctionHook() {
    orig_Struct = FindStructHook();

    if (sizeof(int) != 4 || !orig_Struct)
        return 0;

    enable_write(orig_Struct);

    memcpy(restore_Struct, (const void *)orig_Struct, sizeof(restore_Struct));

    jump_Struct = orig_Struct + sizeof(restore_Struct);

    *(unsigned long *)(replace_Struct + 1) = (unsigned long)StructHookProc;

    return orig_Struct;
}
