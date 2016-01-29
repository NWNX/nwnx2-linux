#ifndef NWNX_ARELITH_STEALTH_CGGAMEOBJECTARRAY__DELETE__0_HPP_
#define NWNX_ARELITH_STEALTH_CGGAMEOBJECTARRAY__DELETE__0_HPP_

#include "FunctionHook.hpp"
#include <memory>

class CGameObjectArray;

namespace Hooks
{
    namespace CGameObjectArray__Delete__0
    {
        extern std::unique_ptr<FunctionHook<uint32_t>> g_hookPtr;

        void Hook();
        void Unhook();
    }

    uint32_t CGameObjectArray__Delete__0__Hook(::CGameObjectArray* thisPtr, uint32_t objId);
}

#endif // NWNX_ARELITH_STEALTH_CGGAMEOBJECTARRAY__DELETE__0_HPP_