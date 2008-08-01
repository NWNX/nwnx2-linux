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


static int nx_hook_protect (uint32_t addr, size_t len, int prot) {
    addr -= (addr % PAGE_SIZE) + PAGE_SIZE;
    len   = (len - (len % PAGE_SIZE)) + (PAGE_SIZE * 2);

    return mprotect((void *)addr, len, prot);
}

int nx_hook_enable_exec (const void *addr, size_t len) {
    return nx_hook_protect((uint32_t)addr, len, PROT_READ|PROT_EXEC);
}

int nx_hook_enable_write (const void *addr, size_t len) {
    return nx_hook_protect((uint32_t)addr, len, PROT_READ|PROT_WRITE);
}

void *nx_hook_function (void *addr, void *func, size_t len, uint32_t flags) {
    unsigned char *trampoline = NULL;

    if (nx_hook_enable_write(addr, len) < 0)
        return (void *)-1;

    if (flags & NX_HOOK_DIRECT) {
        memcpy(addr, nx_hook_jump_code, len);
        *((uint32_t *)(addr + 1)) = (uint32_t)func - (uint32_t)(addr + 5);
    } else {
        trampoline = nx_safe_calloc(1, PAGE_SIZE);

        memcpy(trampoline + NX_HOOK_TRAMPOLINE_OFFSET, addr, len);
        memcpy(addr, nx_hook_jump_code, len);

        *((uint32_t *)(addr + 1)) = (uint32_t)(trampoline +
            NX_HOOK_TRAMPOLINE_OFFSET) - (uint32_t)(addr + 5);

        trampoline[len + NX_HOOK_TRAMPOLINE_OFFSET] = 0xE9;  /* JMP */

        *((uint32_t *)(trampoline + len + NX_HOOK_TRAMPOLINE_OFFSET + 1)) =
            (uint32_t)func - (uint32_t)(trampoline + len +
                                          NX_HOOK_TRAMPOLINE_OFFSET + 5);

        if (nx_hook_enable_exec(trampoline, PAGE_SIZE) < 0)
            return (void *)-1;
    }

    return trampoline;
}

/* vim: set sw=4: */
