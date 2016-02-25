#include "../core.h"
#include "../core/ipc/ipc.h"
#include "NWNXApi.h"

#include <cstring>

static CoreRunScript* hRunScript = nullptr;
static CoreRunScriptAfter* hRunScriptAfter = nullptr;
static CoreRunScriptSituation* hRunScriptSituation = nullptr;
static CoreRunScriptSituationAfter* hRunScriptSituationAfter = nullptr;

static int (*CVirtualMachine__RunScript)(CVirtualMachine *cVM, CExoString *s,
        nwobjid objectId, int recursionLevel);
static void (*CVirtualMachine__RunScriptSituation)(CVirtualMachine *vm,
        CVirtualMachineScript *script, uint32_t obj, int a);

static int Hook_RunScript(
    CVirtualMachine *cVM, CExoString *s, nwobjid objectId, int validObject)
{
    if (s == NULL || s->IsEmpty())
        return 0;

    bool suppress = false;
    int returnValue = -1;
    hRunScript->emit(s->Text, objectId, validObject, suppress, returnValue);

    if (!suppress)
        returnValue = CVirtualMachine__RunScript(g_pVirtualMachine, s,
                                                 objectId, validObject);

    hRunScriptAfter->emit(s->Text, objectId, validObject, suppress, returnValue);

    if (!suppress)
        return returnValue;

    int result = 0;
    if (returnValue != -1) {
        g_pVirtualMachine->field_0 = 3;
        g_pVirtualMachine->m_pReturnValue = returnValue;
        result = 1;
    }

    return result;
}

static void Hook_RunScriptSituation(
    CVirtualMachine *vm, CVirtualMachineScript *script, uint32_t obj, int a)
{
    if (!script || !script->Name.Text) { return; }
    bool suppress = false;
    hRunScriptSituation->emit(script->Name.Text, script->StackSize, obj, suppress);

    // Best be safe and not pass on anything that's fake to nwserver.
    const char *s = script->Name.Text;
    bool invalid_script = strspn(s, "abcdefghijklmnopqrstuvwxyz0123456789_") != strlen(s);
    if (suppress || invalid_script) {
        delete script;
    } else {
        CVirtualMachine__RunScriptSituation(vm, script, obj, a);
        hRunScriptSituationAfter->emit(script->Name.Text, script->StackSize, obj, suppress);
    }
}

static void HookFunctions()
{
    nx_log(NX_LOG_INFO, 0, "core: Hooking CVirtualMachine__RunScriptSituation.");
    NX_HOOK(CVirtualMachine__RunScriptSituation, 0x08262534, Hook_RunScriptSituation, 5);

    nx_log(NX_LOG_INFO, 0, "core: Hooking CVirtualMachine__RunScript.");
    NX_HOOK(CVirtualMachine__RunScript, 0x08261f94, Hook_RunScript, 5);
}

void Core_RunScript_Init()
{
    hRunScript = SignalRegister(CoreRunScript, false, HookFunctions);
    hRunScriptAfter = SignalRegister(CoreRunScriptAfter, false);
    hRunScriptSituation = SignalRegister(CoreRunScriptSituation, false);
    hRunScriptSituationAfter = SignalRegister(CoreRunScriptSituationAfter, false);
}
