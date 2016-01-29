#ifndef NWNX_ARELITH_STICKYCOMBATMODES_CNWSCREATURE__TOGGLEMODE_HPP_
#define NWNX_ARELITH_STICKYCOMBATMODES_CNWSCREATURE__TOGGLEMODE_HPP_

#include "FunctionHook.hpp"
#include <memory>
#include <unordered_map>

class CNWSCreature;

namespace Hooks
{
    namespace CNWSCreature__ToggleMode
    {
        extern std::unordered_map<CNWSCreature*, uint32_t> g_stickyMap;
        extern std::unique_ptr<FunctionHook<int32_t>> g_hookPtr;

        void Hook();
        void Unhook();
    }

    void CNWSCreature__ToggleMode__Hook(CNWSCreature* thisPtr, const uint8_t mode);
}

#endif // NWNX_ARELITH_STICKYCOMBATMODES_CNWSCREATURE__TOGGLEMODE_HPP_