#include "CGameObjectArray__AddInternalObject.hpp"
#include "CGameObjectArray.hpp"
#include "Functions.hpp"
#include "NWNXApi.h"

using namespace Hooks;
using namespace Hooks::CGameObjectArray;
using namespace Hooks::CGameObjectArray__AddInternalObject;

std::unique_ptr<FunctionHook<uint32_t>> Hooks::CGameObjectArray__AddInternalObject::g_hookPtr;

void Hooks::CGameObjectArray__AddInternalObject::Hook()
{
    g_hookPtr = std::make_unique<FunctionHook<uint32_t>>(
        "CGameObjectArray::AddInternalObject",
        reinterpret_cast<void*>(Functions::CGameObjectArray__AddInternalObject),
        reinterpret_cast<void*>(&CGameObjectArray__AddInternalObject__Hook));
}

void Hooks::CGameObjectArray__AddInternalObject::Unhook()
{
    g_hookPtr.reset();
}

uint32_t Hooks::CGameObjectArray__AddInternalObject__Hook(::CGameObjectArray* thisPtr, uint32_t* objId, CGameObject* object, int32_t a3)
{
    const uint32_t ret = g_hookPtr->callOriginal(thisPtr, objId, object, a3);
    CGameObjectArray::g_objectMap.Set(*objId, object);
    return ret;
}