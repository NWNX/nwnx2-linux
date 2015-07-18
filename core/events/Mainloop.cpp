#include "../core.h"

#include "NWNXApi.h"

static HANDLE hMainLoopInnerBefore, hMainLoopInnerAfter;

static int (*CServerExoApp__MainLoopInner)(void *pServer);

void ThreadUtil_Mainloop_After();

static int Hook_MainLoopInner(void *pServer)
{
    NotifyEventHooksNotAbortable(hMainLoopInnerBefore, 0);

    int ret = CServerExoApp__MainLoopInner(pServer);

    ThreadUtil_Mainloop_After();

    NotifyEventHooksNotAbortable(hMainLoopInnerAfter, 0);

    return ret;
}

static bool hooked = false;

static int HookFunctions(uintptr_t p)
{
    if (hooked)
        return true;

    nx_log(NX_LOG_INFO, 0, "core: Hooking CServerExoApp__MainLoopInner.");
    NX_HOOK(CServerExoApp__MainLoopInner, 0x080B2050, Hook_MainLoopInner, 9);

    hooked = true;

    return true;
}

void Core_Mainloop_Init()
{
    hMainLoopInnerBefore = CreateHookableEvent(EVENT_CORE_MAINLOOP_BEFORE);
    hMainLoopInnerAfter = CreateHookableEvent(EVENT_CORE_MAINLOOP_AFTER);

    /* Always hook this due to ThreadUtils needing it. */
    HookFunctions(0);
}
