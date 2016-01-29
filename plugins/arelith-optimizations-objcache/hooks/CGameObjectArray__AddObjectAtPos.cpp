#include "CGameObjectArray__AddObjectAtPos.hpp"
#include "CGameObjectArray.hpp"
#include "Functions.hpp"
#include "NWNXApi.h"

#include <cmath>

using namespace Hooks;
using namespace Hooks::CGameObjectArray;
using namespace Hooks::CGameObjectArray__AddObjectAtPos;

std::unique_ptr<FunctionHook<uint32_t>> Hooks::CGameObjectArray__AddObjectAtPos::g_hookPtr;

void Hooks::CGameObjectArray__AddObjectAtPos::Hook()
{
    g_hookPtr = std::make_unique<FunctionHook<uint32_t>>(
        "CGameObjectArray::AddObjectAtPos",
        reinterpret_cast<void*>(Functions::CGameObjectArray__AddObjectAtPos),
        reinterpret_cast<void*>(&CGameObjectArray__AddObjectAtPos__Hook));
}

void Hooks::CGameObjectArray__AddObjectAtPos::Unhook()
{
    g_hookPtr.reset();
}

uint32_t Hooks::CGameObjectArray__AddObjectAtPos__Hook(::CGameObjectArray* thisPtr, uint32_t a1, CGameObject* object)
{
    const uint32_t ret = g_hookPtr->callOriginal(thisPtr, a1, object);
    CGameObjectArray::g_objectMap.Set(object->ObjectID, object);
    return ret;
}