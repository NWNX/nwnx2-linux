#include "../core.h"

#include "NWNXApi.h"
#include "NWNXBase.h"

#include <map>
#include <string>

static HANDLE hConsoleInput;

static void (*ProcessKeyboardInput)();
static void ProcessKeyboardInput_Hook()
{
    CExoCriticalSection *mtx = (CExoCriticalSection*) 0x083CF428;
    const char *g_szCommand = (const char*) 0x083CF440;
    bool *g_ProcessCommand = (bool*) 0x0832F204;

    bool parent_was_called = false;
    bool call_parent = true;

    mtx->EnterCriticalSection();

    char *g_szCommand_dup = strdup(g_szCommand);

    if (*g_ProcessCommand) {
        const char *command = strtok(g_szCommand_dup, " ");
        const char *rest = strtok(NULL, "");

        // help and status is a bit of a special case: We need to call the
        // parent handler FIRST (to print the builtin stuff), then our own.
        // For all other cases, we want to check our own first and only then
        // call parent (so they can be stopped)
        if (!strcmp("help", command) || !strcmp("status", command)) {
            mtx->LeaveCriticalSection();
            ProcessKeyboardInput();
            parent_was_called = true;
            mtx->EnterCriticalSection();
        }

        CoreConsoleInputEvent ev = { command, rest ? rest : "", true };
        NotifyEventHooksNotAbortable(hConsoleInput, (uintptr_t) &ev);
        call_parent = ev.pass;

        if (!call_parent)
            *g_ProcessCommand = 0;
    }

    free(g_szCommand_dup);

    mtx->LeaveCriticalSection();

    if (!parent_was_called && call_parent)
        ProcessKeyboardInput();
}

void Core_Console_Init()
{
    hConsoleInput = CreateHookableEvent(EVENT_CORE_CONSOLE_INPUT);

    NX_HOOK(ProcessKeyboardInput, 0x0804D328,
            ProcessKeyboardInput_Hook, 5);
}
