#ifndef NWNX_ARELITH_STEALTH_CGGAMEOBJECTARRAY__GETGAMEOBJECT_HPP_
#define NWNX_ARELITH_STEALTH_CGGAMEOBJECTARRAY__GETGAMEOBJECT_HPP_

#include "FunctionHook.hpp"
#include <memory>

class CGameObjectArray;
class CGameObject;

namespace Hooks
{
    namespace CGameObjectArray__GetGameObject
    {
        extern std::unique_ptr<FunctionHook<uint32_t>> g_hookPtr;

        void Hook();
        void Unhook();
    }

    uint32_t CGameObjectArray__GetGameObject__Hook(::CGameObjectArray* thisPtr, int32_t objId, CGameObject** object);
}

#endif // NWNX_ARELITH_STEALTH_CGGAMEOBJECTARRAY__GETGAMEOBJECT_HPP_