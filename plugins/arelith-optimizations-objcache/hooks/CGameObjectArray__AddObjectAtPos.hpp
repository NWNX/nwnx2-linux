#ifndef NWNX_ARELITH_STEALTH_CGGAMEOBJECTARRAY__ADDOBJECTATPOS_HPP_
#define NWNX_ARELITH_STEALTH_CGGAMEOBJECTARRAY__ADDOBJECTATPOS_HPP_

#include "FunctionHook.hpp"
#include <memory>

class CGameObjectArray;
class CGameObject;

namespace Hooks
{
    namespace CGameObjectArray__AddObjectAtPos
    {
        extern std::unique_ptr<FunctionHook<uint32_t>> g_hookPtr;

        void Hook();
        void Unhook();
    }

    uint32_t CGameObjectArray__AddObjectAtPos__Hook(::CGameObjectArray* thisPtr, uint32_t a1, CGameObject* object);
}

#endif // NWNX_ARELITH_STEALTH_CGGAMEOBJECTARRAY__ADDOBJECTATPOS_HPP_