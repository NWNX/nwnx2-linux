#include "CNWSCreature__SetCombatMode.hpp"
#include "CNWSCreature__ToggleMode.hpp"
#include "Functions.hpp"
#include "NWNXApi.h"

using namespace Hooks;
using namespace Hooks::CNWSCreature__SetCombatMode;

std::unique_ptr<FunctionHook<void>> Hooks::CNWSCreature__SetCombatMode::g_hookPtr;

bool ShouldSkip(CNWSCreature* creature, const uint8_t requestedMode);
bool GetWeaponRanged(CNWSItem* item);
uint32_t GetBaseItemType(CNWSItem* item);

void Hooks::CNWSCreature__SetCombatMode::Hook()
{
    g_hookPtr = std::make_unique<FunctionHook<void>>(
        "CNWSCreature::SetCombatMode",
        reinterpret_cast<void*>(Functions::CNWSCreature__SetCombatMode),
        reinterpret_cast<void*>(&CNWSCreature__SetCombatMode__Hook));
}

void Hooks::CNWSCreature__SetCombatMode::Unhook()
{
    g_hookPtr.reset();
}

void Hooks::CNWSCreature__SetCombatMode__Hook(CNWSCreature* thisPtr, const uint8_t mode, const int32_t a2)
{
    if (thisPtr->IsPC)
    {
        // Modify the mode to align with ToggleMode's modes.
        // 0 = CLEAR_MODE. 1 = Unused. 2+ = Normal modes.
        const uint8_t modifiedMode = mode > 0 ? mode + 1 : mode;

        if (ShouldSkip(thisPtr, modifiedMode))
        {
            return;
        }
    }

    g_hookPtr->callOriginal(thisPtr, mode, a2);
}

bool ShouldSkip(CNWSCreature* creature, const uint8_t requestedMode)
{
    static constexpr uint8_t CLEAR_MODE                        = 0;
    static constexpr uint8_t ACTION_MODE_PARRY                 = 2;
    static constexpr uint8_t ACTION_MODE_POWER_ATTACK          = 3;
    static constexpr uint8_t ACTION_MODE_IMPROVED_POWER_ATTACK = 4;
    static constexpr uint8_t ACTION_MODE_COUNTERSPELL          = 5;
    static constexpr uint8_t ACTION_MODE_FLURRY_OF_BLOWS       = 6;
    static constexpr uint8_t ACTION_MODE_RAPID_SHOT            = 7;
    static constexpr uint8_t ACTION_MODE_EXPERTISE             = 8;
    static constexpr uint8_t ACTION_MODE_IMPROVED_EXPERTISE    = 9;
    static constexpr uint8_t ACTION_MODE_DEFENSIVE_CAST        = 10;
    static constexpr uint8_t ACTION_MODE_DIRTY_FIGHTING        = 11;

    auto& stickyMap = CNWSCreature__ToggleMode::g_stickyMap;

    switch (stickyMap[creature])
    {
        // PARRY, COUNTERSPELL, DETECT, STEALTH, or NONE
        case CLEAR_MODE:
        case ACTION_MODE_PARRY:
        case ACTION_MODE_COUNTERSPELL:
        default:

            // No need to enforce sticky for these. Just leave.
            return false;
            break;

        // Unarmed or melee only.
        case ACTION_MODE_POWER_ATTACK:

            if (requestedMode == 0)
            {
                if (GetWeaponRanged(creature->Inventory->GetItemInSlot(EQUIPMENT_SLOT_RIGHTHAND)))
                {
                    stickyMap[creature] = 0;
                    return false;
                }
                else
                {
                    return true;
                }
            }

            break;

        // Unarmed or melee only.
        case ACTION_MODE_IMPROVED_POWER_ATTACK:

            if (requestedMode == 0)
            {
                if (GetWeaponRanged(creature->Inventory->GetItemInSlot(EQUIPMENT_SLOT_RIGHTHAND)))
                {
                    stickyMap[creature] = 0;
                    return false;
                }
                else
                {
                    return true;
                }
            }

            break;

        // Unarmed or kamas only.
        case ACTION_MODE_FLURRY_OF_BLOWS:

            if (requestedMode == 0)
            {
                CNWSItem* leftHandItem = creature->Inventory->GetItemInSlot(EQUIPMENT_SLOT_LEFTHAND);
                CNWSItem* rightHandItem  = creature->Inventory->GetItemInSlot(EQUIPMENT_SLOT_RIGHTHAND);

                const uint32_t leftHandBaseItemType = GetBaseItemType(leftHandItem);
                const uint32_t rightHandBaseItemType = GetBaseItemType(rightHandItem);

                const bool leftHandUnsafe = leftHandBaseItemType != BASE_ITEM_INVALID && leftHandBaseItemType != BASE_ITEM_KAMA;
                const bool rightHandUnsafe = rightHandBaseItemType != BASE_ITEM_INVALID && rightHandBaseItemType != BASE_ITEM_KAMA;

                if (leftHandUnsafe || rightHandUnsafe)
                {
                    stickyMap[creature] = 0;
                    return false;
                }
                else
                {
                    return true;
                }
            }

            break;

        // Ranged only, excluding crossbows.
        case ACTION_MODE_RAPID_SHOT:

            if (requestedMode == 0)
            {
                CNWSItem* rightHandItem = creature->Inventory->GetItemInSlot(EQUIPMENT_SLOT_RIGHTHAND);
                const uint32_t rightHandBaseItemType = GetBaseItemType(rightHandItem);

                if (!GetWeaponRanged(rightHandItem) ||
                    rightHandBaseItemType == BASE_ITEM_LIGHTCROSSBOW ||
                    rightHandBaseItemType == BASE_ITEM_HEAVYCROSSBOW)
                {
                    stickyMap[creature] = 0;
                    return false;
                }
                else
                {
                    return true;
                }
            }

            break;

        // Unarmed or melee only.
        case ACTION_MODE_EXPERTISE:

            if (requestedMode == 0)
            {
                if (GetWeaponRanged(creature->Inventory->GetItemInSlot(EQUIPMENT_SLOT_RIGHTHAND)))
                {
                    stickyMap[creature] = 0;
                    return false;
                }
                else
                {
                    return true;
                }
            }

            break;

        // Unarmed or melee only.
        case ACTION_MODE_IMPROVED_EXPERTISE:

            if (requestedMode == 0)
            {
                if (GetWeaponRanged(creature->Inventory->GetItemInSlot(EQUIPMENT_SLOT_RIGHTHAND)))
                {
                    stickyMap[creature] = 0;
                    return false;
                }
                else
                {
                    return true;
                }
            }

            break;

        // Nothing special here. Defensive casting can be activated with all weapon styles.
        case ACTION_MODE_DEFENSIVE_CAST:

            if (requestedMode == 0)
            {
                return true;
            }

            break;

        // Unarmed or melee only.
        case ACTION_MODE_DIRTY_FIGHTING:

            if (requestedMode == 0)
            {
                if (GetWeaponRanged(creature->Inventory->GetItemInSlot(EQUIPMENT_SLOT_RIGHTHAND)))
                {
                    stickyMap[creature] = 0;
                    return false;
                }
                else
                {
                    return true;
                }
            }

            break;
    }

    return false;
}

bool GetWeaponRanged(CNWSItem* item)
{
    if (item == nullptr)
    {
        return false;
    }

    const uint32_t itemType = GetBaseItemType(item);
    return itemType == BASE_ITEM_LONGBOW ||
           itemType == BASE_ITEM_SHORTBOW ||
           itemType == BASE_ITEM_HEAVYCROSSBOW ||
           itemType == BASE_ITEM_LIGHTCROSSBOW ||
           itemType == BASE_ITEM_SLING ||
           itemType == BASE_ITEM_DART ||
           itemType == BASE_ITEM_SHURIKEN ||
           itemType == BASE_ITEM_THROWINGAXE;
}

uint32_t GetBaseItemType(CNWSItem* item)
{
    return item == nullptr ? BASE_ITEM_INVALID : item->BaseItem;
}