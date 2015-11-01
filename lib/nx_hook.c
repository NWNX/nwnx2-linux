/*
 *  NWNeXalt - Empty File
 *  (c) 2007 Doug Swarin (zac@intertex.net)
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *  $Id$
 *  $HeadURL$
 *
 */

#include "NWNXLib.h"

#ifndef PAGE_SIZE
#define PAGE_SIZE 4096
#endif


#define NX_HOOK_TRAMPOLINE_OFFSET       32

static const unsigned char *nx_hook_jump_code =
    (unsigned char *)"\xe9\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90";


static int nx_hook_protect(uint32_t addr, size_t len, int prot)
{
    addr -= (addr % PAGE_SIZE) + PAGE_SIZE;
    len   = (len - (len % PAGE_SIZE)) + (PAGE_SIZE * 2);

    return mprotect((void *)addr, len, prot);
}

int nx_hook_enable_exec(const void *addr, size_t len)
{
    return nx_hook_protect((uint32_t)addr, len, PROT_READ | PROT_EXEC);
}

int nx_hook_enable_write(const void *addr, size_t len)
{
    return nx_hook_protect((uint32_t)addr, len, PROT_READ | PROT_WRITE);
}

void *nx_hook_function(void *addr, void *func, size_t len, uint32_t flags)
{
    unsigned char *trampoline = NULL;

    if (len < 5 || nx_hook_enable_write(addr, len) < 0)
        return (void *) - 1;

    if (flags & NX_HOOK_DIRECT) {
        if (flags & NX_HOOK_RETCODE) {
            /* create a trampoline to hold the displaced code */
            trampoline = mmap(NULL, PAGE_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

            /* copy the displaced code to the trampoline */
            memcpy(trampoline, addr, len);

            /* append a jump to after the end of the displaced code to the trampoline */
            trampoline[len] = 0xE9;  /* JMP */

            *((uint32_t *)(trampoline + len + 1)) = (uint32_t)(addr + len) -
                                                    (uint32_t)(trampoline + len + 5);
        }

        /* create a direct jump to the target code */
        memcpy(addr, nx_hook_jump_code, len);
        *((uint32_t *)(addr + 1)) = (uint32_t)func - (uint32_t)(addr + 5);
    } else {
        /* create a trampoline containing the displaced code */
        trampoline = mmap(NULL, PAGE_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

        /* copy the displaced code to the trampoline */
        memcpy(trampoline + NX_HOOK_TRAMPOLINE_OFFSET, addr, len);

        /* replace the displaced code with a jump to the trampoline */
        memcpy(addr, nx_hook_jump_code, len);

        *((uint32_t *)(addr + 1)) = (uint32_t)(trampoline +
                                               NX_HOOK_TRAMPOLINE_OFFSET) -
                                    (uint32_t)(addr + 5);

        /* append a jump to the hook code to the end of the displaced code in
         * the trampoline */
        trampoline[len + NX_HOOK_TRAMPOLINE_OFFSET] = 0xE9;  /* JMP */

        *((uint32_t *)(trampoline + len + NX_HOOK_TRAMPOLINE_OFFSET + 1)) =
            (uint32_t)func - (uint32_t)(trampoline + len +
                                        NX_HOOK_TRAMPOLINE_OFFSET + 5);
    }

    /* make the trampoline executable */
    if (trampoline != NULL && mprotect(trampoline, PAGE_SIZE, PROT_READ | PROT_EXEC) < 0)
        return (void *) - 1;

    return trampoline;
}

void nx_hook_function_call(void *addr, void *func)
{
    nx_hook_enable_write((void*) addr, 5);
    *(uint32_t *)(addr + 1) = func - (addr + 5);
}

/* vim: set sw=4: */
