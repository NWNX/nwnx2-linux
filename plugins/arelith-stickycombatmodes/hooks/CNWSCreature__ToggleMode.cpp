#include "CNWSCreature__ToggleMode.hpp"
#include "Functions.hpp"
#include "NWNXApi.h"

using namespace Hooks;
using namespace Hooks::CNWSCreature__ToggleMode;

std::unordered_map<CNWSCreature*, uint32_t> Hooks::CNWSCreature__ToggleMode::g_stickyMap;
std::unique_ptr<FunctionHook<int32_t>> Hooks::CNWSCreature__ToggleMode::g_hookPtr;

void Hooks::CNWSCreature__ToggleMode::Hook()
{
    g_hookPtr = std::make_unique<FunctionHook<int32_t>>(
        "CNWSCreature::ToggleMode",
        reinterpret_cast<void*>(Functions::CNWSCreature__ToggleMode),
        reinterpret_cast<void*>(&CNWSCreature__ToggleMode__Hook),
        10);
}

void Hooks::CNWSCreature__ToggleMode::Unhook()
{
    g_hookPtr.reset();
}

void Hooks::CNWSCreature__ToggleMode__Hook(CNWSCreature* thisPtr, const uint8_t mode)
{
    if (thisPtr->IsPC)
    {
        if (mode > 1)
        {
            if (g_stickyMap.find(thisPtr) != g_stickyMap.end())
            {
                uint8_t actualMode = thisPtr->GetCombatMode();
                actualMode = actualMode > 0 ? actualMode + 1 : 0; // Make sure to account for the different mode enumerations.
                g_stickyMap[thisPtr] = actualMode == mode ? 0 : mode; // Only toggle off the flag if we're actually in the mode we think we're in.
            }
            else
            {
                g_stickyMap[thisPtr] = mode;
            }
        }
    }

    g_hookPtr->callOriginal(thisPtr, mode);
}