#include "../core.h"

#include "NWNXApi.h"

static HANDLE hObjectCreated;
static HANDLE hObjectDestroyed;

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

	ObjectCreatedEvent p = {
		obj,
		objectId
	};

	NotifyEventHooksNotAbortable(hObjectCreated, (uintptr_t) &p);

	return ret;
}

static void CNWSObject__dtor_Hook(CNWSObject *obj, char a2)
{
	ObjectDestroyedEvent p = {
		obj
	};

	NotifyEventHooksNotAbortable(hObjectDestroyed, (uintptr_t) &p);

	CNWSObject__dtor(obj, a2);
}

static int HookObjectCreated(uintptr_t p)
{
	nx_log(NX_LOG_INFO, 0, "core: Hooking CNWSObject__ctor.");
	NX_HOOK(CNWSObject__ctor, 0x081C88F0, CNWSObject__ctor_Hook, 5);

	return true;
}

static int HookObjectDestroyed(uintptr_t p)
{
	nx_log(NX_LOG_INFO, 0, "core: Hooking CNWSObject__dtor.");
	NX_HOOK(CNWSObject__dtor, 0x081C8E94, CNWSObject__dtor_Hook, 5);

	return true;
}

void Core_Object_Init()
{
	hObjectCreated = CreateHookableEvent(EVENT_CORE_OBJECT_CREATED);
	hObjectDestroyed = CreateHookableEvent(EVENT_CORE_OBJECT_DESTROYED);

	if (hObjectCreated)
		SetHookInitializer(hObjectCreated, HookObjectCreated);

	if (hObjectDestroyed)
		SetHookInitializer(hObjectDestroyed, HookObjectDestroyed);
}
