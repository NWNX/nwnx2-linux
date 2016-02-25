#include "../core.h"
#include "../core/ipc/ipc.h"
#include "NWNXApi.h"

static CoreMainloopBefore* hMainLoopInnerBefore = nullptr;
static CoreMainloopAfter* hMainLoopInnerAfter = nullptr;

static int (*CServerExoApp__MainLoopInner)(void *pServer);

void ThreadUtil_Mainloop_After();

static int Hook_MainLoopInner(void *pServer)
{
    hMainLoopInnerBefore->emit();

    int ret = CServerExoApp__MainLoopInner(pServer);

    ThreadUtil_Mainloop_After();

    hMainLoopInnerAfter->emit();

    return ret;
}

static bool hooked = false;

static void HookFunctions()
{
    if (hooked)
        return;

    nx_log(NX_LOG_INFO, 0, "core: Hooking CServerExoApp__MainLoopInner.");
    NX_HOOK(CServerExoApp__MainLoopInner, 0x080B2050, Hook_MainLoopInner, 9);

    hooked = true;
}

void Core_Mainloop_Init()
{
    hMainLoopInnerBefore = SignalRegister(CoreMainloopBefore, false);
    hMainLoopInnerAfter = SignalRegister(CoreMainloopAfter, false);

    /* Always hook this due to ThreadUtils needing it. */
    HookFunctions();
}
