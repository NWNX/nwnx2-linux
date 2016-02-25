#include "../core.h"
#include "../core/ipc/ipc.h"
#include "NWNXApi.h"

static CoreCNWSObjectCreated* hObjectCreated = nullptr;
static CoreCNWSObjectDestroyed* hObjectDestroyed = nullptr;

static int (*CNWSObject__ctor)(
	CNWSObject *obj,
	char objectType,
	nwobjid objectId,
	int a4, int a5);
static void (*CNWSObject__dtor)(CNWSObject *obj, char a2);

static int CNWSObject__ctor_Hook(
	CNWSObject *obj,
	char objectType,
	nwobjid objectId,
	int a4, int a5)
{
	int ret = CNWSObject__ctor(obj, objectType, objectId, a4, a5);

    hObjectCreated->emit(obj, objectId);

    return ret;
}

static void CNWSObject__dtor_Hook(CNWSObject *obj, char a2)
{
    hObjectDestroyed->emit(obj);

	CNWSObject__dtor(obj, a2);
}

static void HookObjectCreated()
{
	nx_log(NX_LOG_INFO, 0, "core: Hooking CNWSObject__ctor.");
	NX_HOOK(CNWSObject__ctor, 0x081C88F0, CNWSObject__ctor_Hook, 5);
}

static void HookObjectDestroyed()
{
	nx_log(NX_LOG_INFO, 0, "core: Hooking CNWSObject__dtor.");
	NX_HOOK(CNWSObject__dtor, 0x081C8E94, CNWSObject__dtor_Hook, 5);
}

void Core_Object_Init()
{
	hObjectCreated = SignalRegister(CoreCNWSObjectCreated, false, HookObjectCreated);
	hObjectDestroyed = SignalRegister(CoreCNWSObjectDestroyed, false, HookObjectDestroyed);
}
