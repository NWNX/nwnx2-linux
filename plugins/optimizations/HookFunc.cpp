/***************************************************************************
    Experimental plugin for NWNX  - hooks implementation
    (c) 2009 virusman (virusman@virusman.ru)

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
#include <stdint.h>
#include <unistd.h>
#include <chrono>

#include <limits.h>		/* for PAGESIZE */
#ifndef PAGESIZE
#define PAGESIZE 4096
#endif

#include "HookFunc.h"
#include "NWNXOptimizations.h"

extern CNWNXOptimizations plugin;

unsigned char d_jmp_code[] = "\x68\x60\x70\x80\x90"       /* push dword 0x90807060 */
                             "\xc3\x90\x90\x90\x90";//x00 /* ret , nop , nop       */

unsigned char d_ret_code_hrtimer[0x20];
unsigned char d_ret_code_loop[0x20];
unsigned char d_ret_code_scallback[0x20];

dword nESP;
int64_t nCachedTime = 0;

int64_t (*CExoTimers__GetHighResolutionTimer)(void *pTimer);
int (*CServerExoApp__MainLoop)(void *pServer);
void (*CNWVirtualMachineCommands__RunScriptCallback)(void *pCommands, void *sScriptName);

int64_t CExoTimers__GetHighResolutionTimer_hook(void *pTimer)
{
    asm("push %ebx");
    asm("movl 0x4(%ebp), %ebx");
    asm("movl  %ebx, nESP");
    asm("pop %ebx");

    if (nESP > 0x08095D60 && nESP < 0x080962A4 && nCachedTime) {
        return nCachedTime;
    } else {
        nCachedTime = CExoTimers__GetHighResolutionTimer(pTimer);
        return nCachedTime;
    }
}

namespace
{
    std::chrono::time_point<std::chrono::high_resolution_clock> beforeTime;
    unsigned int desiredTickRate;
}

int eventMainLoopBefore(uintptr_t p)
{
    beforeTime = std::chrono::high_resolution_clock::now();
    return 0;
}

int eventMainLoopAfter(uintptr_t p)
{
    const auto afterTime = std::chrono::high_resolution_clock::now();
    const auto totalTime = std::chrono::duration_cast<std::chrono::microseconds>(afterTime - beforeTime).count();
    const int timeToSleep = static_cast<int>((1000.0f / static_cast<float>(desiredTickRate)) * 1000.0f) - totalTime;

    if (timeToSleep > 0)
    {
        usleep(timeToSleep);
    }

    return 0;
}

void CNWVirtualMachineCommands__RunScriptCallback_hook(void *pCommands, void *sScriptName)
{
    //This function is useless: do nothing
    return;
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
    HookEvent(EVENT_CORE_PLUGINSLOADED, [](uintptr_t) -> int
    {
        HookEvent(EVENT_CORE_MAINLOOP_BEFORE, eventMainLoopBefore);
        HookEvent(EVENT_CORE_MAINLOOP_AFTER, eventMainLoopAfter);
        return 0;
    });

    // No-op the delay code.
    constexpr static uintptr_t address = 0x0804BBEE;
    constexpr static size_t length = 16;
    d_enable_write(address);
    memset(reinterpret_cast<void*>(address), 0x90, length);

    *(dword*)&CExoTimers__GetHighResolutionTimer = 0x082CC7A8;
    d_redirect((unsigned long)CExoTimers__GetHighResolutionTimer, (unsigned long)CExoTimers__GetHighResolutionTimer_hook, d_ret_code_hrtimer, 9);
    *(dword*)&CExoTimers__GetHighResolutionTimer = (dword)&d_ret_code_hrtimer;

    *(dword*)&CNWVirtualMachineCommands__RunScriptCallback = 0x081FB558;
    d_redirect((unsigned long)CNWVirtualMachineCommands__RunScriptCallback, (unsigned long)CNWVirtualMachineCommands__RunScriptCallback_hook, d_ret_code_scallback, 9);
    *(dword*)&CNWVirtualMachineCommands__RunScriptCallback = (dword)&d_ret_code_scallback;

    return 1;
}

void SetTargetTickRate(const unsigned int rate)
{
    desiredTickRate = rate;
}