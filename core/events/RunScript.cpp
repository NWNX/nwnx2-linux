#include "../core.h"

#include "NWNXApi.h"

#include <cstring>

static HANDLE hRunScript, hRunScriptAfter;
static HANDLE hRunScriptSituation, hRunScriptSituationAfter;

static int (*CVirtualMachine__RunScript)(CVirtualMachine *cVM, CExoString *s,
        nwobjid objectId, int recursionLevel);
static void (*CVirtualMachine__RunScriptSituation)(CVirtualMachine *vm,
        CVirtualMachineScript *script, uint32_t obj, int a);

static int Hook_RunScript(
    CVirtualMachine *cVM, CExoString *s, nwobjid objectId, int validObject)
{
    if (s == NULL || s->IsEmpty())
        return 0;

    CoreRunScriptEvent info = {
        s->Text, objectId, validObject, false, -1
    };

    NotifyEventHooksNotAbortable(hRunScript, (uintptr_t)&info);

    if (!info.suppress)
        info.returnValue = CVirtualMachine__RunScript(
                               g_pVirtualMachine, s,
                               objectId, validObject);

    NotifyEventHooksNotAbortable(hRunScriptAfter, (uintptr_t)&info);

    if (!info.suppress)
        return info.returnValue;

    int result = 0;
    if (info.returnValue != -1) {
        g_pVirtualMachine->field_0 = 3;
        g_pVirtualMachine->m_pReturnValue = info.returnValue;
        result = 1;
    }

    return result;
}

static void Hook_RunScriptSituation(
    CVirtualMachine *vm, CVirtualMachineScript *script, uint32_t obj, int a)
{
    if (!script || !script->Name.Text) { return; }
    CoreRunScriptSituationEvent info = {
        script->Name.Text, // Plugin specific marker, for determing if it should run the script situation.
        script->StackSize, // Plugin specific integer token for determining which script situation to run.
        obj,
        false,
    };

    NotifyEventHooksNotAbortable(hRunScriptSituation, (uintptr_t)&info);

    // Best be safe and not pass on anything that's fake to nwserver.
    const char *s = script->Name.Text;
    bool invalid_script = strspn(s, "abcdefghijklmnopqrstuvwxyz0123456789_") != strlen(s);
    if (info.suppress || invalid_script) {
        delete script;
    } else {
        CVirtualMachine__RunScriptSituation(vm, script, obj, a);

        NotifyEventHooksNotAbortable(hRunScriptSituationAfter, (uintptr_t)&info);
    }
}

static int HookFunctions(uintptr_t unused)
{
    nx_log(NX_LOG_INFO, 0, "core: Hooking CVirtualMachine__RunScriptSituation.");
    NX_HOOK(CVirtualMachine__RunScriptSituation, 0x08262534, Hook_RunScriptSituation, 5);

    nx_log(NX_LOG_INFO, 0, "core: Hooking CVirtualMachine__RunScript.");
    NX_HOOK(CVirtualMachine__RunScript, 0x08261f94, Hook_RunScript, 5);

    return true;
}

void Core_RunScript_Init()
{

    hRunScript = CreateHookableEvent(EVENT_CORE_RUNSCRIPT);
    hRunScriptAfter = CreateHookableEvent(EVENT_CORE_RUNSCRIPT_AFTER);
    hRunScriptSituation = CreateHookableEvent(EVENT_CORE_RUNSCRIPT_SITUATION);
    hRunScriptSituationAfter = CreateHookableEvent(EVENT_CORE_RUNSCRIPT_SITUATION_AFTER);

    if (hRunScript && hRunScriptAfter &&
            hRunScriptSituation && hRunScriptSituationAfter)
        SetHookInitializer(hRunScript, HookFunctions);
}
