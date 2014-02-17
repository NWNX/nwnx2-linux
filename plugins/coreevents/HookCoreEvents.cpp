#include "HookCoreEvents.h"
#include "NWNXCoreEvents.h"
#include "../../api/all.h"
#include "../../include/nx_hook.h"

HANDLE hMainLoopInner;
HANDLE hRunScript;

int (*CServerExoApp__MainLoopInner)(void *pServer);
int (*CVirtualMachine__RunScript)(CVirtualMachine *cVM, CExoString *s, dword objectId,
								  int recursionLevel);

int Hook_MainLoopInner(void *pServer)
{
	int ret = CServerExoApp__MainLoopInner(pServer);

	NotifyEventHooks(hMainLoopInner, 0, 0);

	return ret;
}

int Hook_RunScript(CVirtualMachine *cVM, CExoString *s, dword objectId, int recursionLevel)
{
	if (s == NULL || s->IsEmpty())
		return 0;

	CoreEventRunScriptStruct info = {
		s->Text, objectId, recursionLevel, false
	};

	NotifyEventHooks(hRunScript, (WPARAM)&info, 0);

	if (!info.suppress)
		return CVirtualMachine__RunScript(g_pVirtualMachine, s, objectId, recursionLevel);

	/* Always clear the stack, just in case. This is what RunScript() does as well. */
	g_pVirtualMachine->Stack.ClearStack();

	return 1;
}

int HookFunctions()
{
	*(void **)&CServerExoApp__MainLoopInner = nx_hook_function((void *)0x080B2050,
			(void *)Hook_MainLoopInner, 9, NX_HOOK_DIRECT | NX_HOOK_RETCODE);

	*(void **)&CVirtualMachine__RunScript = nx_hook_function((void *)0x08261f94,
			(void *)Hook_RunScript, 5, NX_HOOK_DIRECT | NX_HOOK_RETCODE);

	hMainLoopInner = CreateHookableEvent("NWServer/MainLoop");
	hRunScript = CreateHookableEvent("NWServer/RunScript");

	return true;
}
