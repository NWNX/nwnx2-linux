#include "../core.h"

#include "NWNXApi.h"

static HANDLE hModuleLoading, hModuleLoaded;

/* Mid-function hook to load a new module. */
static int CServerExoApp__LoadModule(
    CServerExoApp *s,
    CExoString mod,
    int a3,
    CNWSPlayer *p
)
{
    CoreModuleLoadingEvent e = {
        mod.CStr()
    };

    NotifyEventHooksNotAbortable(hModuleLoading, (uintptr_t) &e);

    return s->LoadModule(mod, a3, p);
}

/* Obscure mid-function hook that is triggered on successful module load.
 * Unlikely to conflict with other plugins. */
static short CServerExoApp__GetServerMode(CServerExoApp *s)
{
    short ret = s->GetServerMode();

    if (ret)
        NotifyEventHooksNotAbortable(hModuleLoaded, 0);

    return ret;
}

void Core_Module_Init()
{
    hModuleLoading = CreateHookableEvent(EVENT_CORE_MODULE_LOADING);
    hModuleLoaded = CreateHookableEvent(EVENT_CORE_MODULE_LOADED);

    NX_HOOK_CALL(0x0804e712, CServerExoApp__LoadModule);
    NX_HOOK_CALL(0x0804e77a, CServerExoApp__GetServerMode);
}
