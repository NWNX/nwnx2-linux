#include "CGameObjectArray__GetGameObject.hpp"
#include "CGameObjectArray.hpp"
#include "Functions.hpp"
#include "NWNXApi.h"

using namespace Hooks;
using namespace Hooks::CGameObjectArray__GetGameObject;

std::unique_ptr<FunctionHook<uint32_t>> Hooks::CGameObjectArray__GetGameObject::g_hookPtr;

void Hooks::CGameObjectArray__GetGameObject::Hook()
{
    g_hookPtr = std::make_unique<FunctionHook<uint32_t>>(
        "CGameObjectArray::GetGameObject",
        reinterpret_cast<void*>(Functions::CGameObjectArray__GetGameObject),
        reinterpret_cast<void*>(&CGameObjectArray__GetGameObject__Hook));
}

void Hooks::CGameObjectArray__GetGameObject::Unhook()
{
    g_hookPtr.reset();
}

uint32_t Hooks::CGameObjectArray__GetGameObject__Hook(::CGameObjectArray* thisPtr, int32_t objId, CGameObject** object)
{
    auto found = CGameObjectArray::g_objectMap.Find(objId);
    *object = found;
    return !found; // 0 on success, 1 on failure
}