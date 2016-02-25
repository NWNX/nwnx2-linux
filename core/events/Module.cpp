#include "../core.h"
#include "../core/ipc/ipc.h"
#include "NWNXApi.h"

static CoreModuleLoading* hModuleLoading = nullptr;
static CoreModuleLoaded* hModuleLoaded = nullptr;

/* Mid-function hook to load a new module. */
static int CServerExoApp__LoadModule(
    CServerExoApp *s,
    CExoString mod,
    int a3,
    CNWSPlayer *p
)
{
    hModuleLoading->emit(mod.CStr());
    return s->LoadModule(mod, a3, p);
}

/* Obscure mid-function hook that is triggered on successful module load.
 * Unlikely to conflict with other plugins. */
static short CServerExoApp__GetServerMode(CServerExoApp *s)
{
    short ret = s->GetServerMode();

    if (ret)
        hModuleLoaded->emit();

    return ret;
}

void Core_Module_Init()
{
    hModuleLoading = SignalRegister(CoreModuleLoading, false);
    hModuleLoaded = SignalRegister(CoreModuleLoaded, false);

    NX_HOOK_CALL(0x0804e712, CServerExoApp__LoadModule);
    NX_HOOK_CALL(0x0804e77a, CServerExoApp__GetServerMode);
}
