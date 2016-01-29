#ifndef NWNX_ARELITH_STICKYCOMBATMODES_CNWSCREATURE__SETCOMBATMODE_HPP_
#define NWNX_ARELITH_STICKYCOMBATMODES_CNWSCREATURE__SETCOMBATMODE_HPP_

#include "FunctionHook.hpp"
#include <memory>

class CNWSCreature;

namespace Hooks
{
    namespace CNWSCreature__SetCombatMode
    {
        extern std::unique_ptr<FunctionHook<void>> g_hookPtr;

        void Hook();
        void Unhook();
    }

    void CNWSCreature__SetCombatMode__Hook(CNWSCreature* thisPtr, const uint8_t mode, const int32_t a2);
}

#endif // NWNX_ARELITH_STICKYCOMBATMODES_CNWSCREATURE__SETCOMBATMODE_HPP_