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

#ifndef _NX_HOOK_H_
#define _NX_HOOK_H_

#define NX_HOOK_DIRECT          (1 <<  0)
#define NX_HOOK_RETCODE         (1 <<  1)

#ifdef __cplusplus
extern "C" {
#endif

int nx_hook_enable_exec(const void *addr, size_t len);
int nx_hook_enable_write(const void *addr, size_t len);

void *nx_hook_function(void *addr, void *func, size_t len, uint32_t flags);
void nx_hook_function_call(void *addr, void *func);

void nwn_hook_init(void);

#ifdef __cplusplus
}
#endif

/**
 * Macro: NX_HOOK
 *
 * Helper macro to that wraps nx_hook_function in order to remove user specified casting.
 *
 * Parameters:
 *     orig  - Function pointer for the trampoline.
 *     addr  - Address of the function to hook.
 *     hook  - Hook function.
 *     bytes - Number of bytes to copy into the trampoline.
 */
#define NX_HOOK(orig, addr, hook, bytes) \
    *(void**)&orig = nx_hook_function((void*)addr, (void*)hook, bytes, NX_HOOK_DIRECT | NX_HOOK_RETCODE)

/**
 * Macro: NX_HOOK_CALL
 *
 * Helper macro to hook mid-function calls without having to apply user casts.
 */
#define NX_HOOK_CALL(addr,hook) \
    nx_hook_function_call((void*) addr, (void*) hook)

#endif /* _NX_HOOK_H_ */

/* vim: set sw=4: */
