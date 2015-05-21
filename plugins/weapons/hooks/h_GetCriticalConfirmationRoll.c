
/***************************************************************************
    NWNXFuncs.cpp - Implementation of the CNWNXFuncs class.
    Copyright (C) 2007 Doug Swarin (zac@intertex.net)

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 ***************************************************************************/

#include "NWNXWeapons.h"

volatile uintptr_t Hook_CCR_Return;
volatile CNWSCreature *Hook_CCR_Attacker;
volatile CNWSCreature *Hook_CCR_Target;
volatile int32_t Hook_CCR_Roll;


__attribute__((noinline))
static int Hook_GetCriticalConfirmationAdjustment(CNWSCreature *attacker, CNWSCreature *target, int roll)
{
    int baseitem, bonus = 0;
    CNWSItem *weapon;

    if (attacker == NULL || attacker->cre_stats == NULL)
        return roll;

    weapon   = CNWSCombatRound__GetCurrentAttackWeapon(attacker->cre_combat_round, 0);
    baseitem = (weapon == NULL ? BASE_ITEM_GLOVES : weapon->it_baseitem);

    if (Table_WeaponOptions[NWNX_WEAPONS_OPT_OVERCRIT_CONF_BONUS] > bonus &&
            Table_WeaponOverwhelmingCritical[baseitem] > 0                    &&
            CNWSCreatureStats__HasFeat(attacker->cre_stats, Table_WeaponOverwhelmingCritical[baseitem]))
        bonus = Table_WeaponOptions[NWNX_WEAPONS_OPT_OVERCRIT_CONF_BONUS];

    if (Table_WeaponOptions[NWNX_WEAPONS_OPT_DEVCRIT_CONF_BONUS] > bonus &&
            Table_WeaponDevastatingCritical[baseitem] > 0                    &&
            CNWSCreatureStats__HasFeat(attacker->cre_stats, Table_WeaponDevastatingCritical[baseitem]))
        bonus = Table_WeaponOptions[NWNX_WEAPONS_OPT_DEVCRIT_CONF_BONUS];

    if (Table_WeaponOptions[NWNX_WEAPONS_OPT_POWCRIT_CONF_BONUS] > bonus &&
            Table_WeaponPowerCritical[baseitem] > 0                          &&
            CNWSCreatureStats__HasFeat(attacker->cre_stats, Table_WeaponPowerCritical[baseitem]))
        bonus = Table_WeaponOptions[NWNX_WEAPONS_OPT_POWCRIT_CONF_BONUS];

    if (Table_WeaponOptions[NWNX_WEAPONS_OPT_SUPCRIT_CONF_BONUS] > bonus &&
            Table_WeaponSuperiorCritical[baseitem] > 0                       &&
            CNWSCreatureStats__HasFeat(attacker->cre_stats, Table_WeaponSuperiorCritical[baseitem]))
        bonus = Table_WeaponOptions[NWNX_WEAPONS_OPT_SUPCRIT_CONF_BONUS];

    /* apply local adjustments (if any) */
    return Local_GetCriticalConfirmationAdjustment(attacker, target, weapon, roll, bonus);
}


void Hook_GetCriticalConfirmationRoll(void)
{
    asm("leave");

    /* duplicate the work originally done, copying the roll out */
    asm("movzwl %ax, %eax");
    asm("movl %eax, Hook_CCR_Roll");
    asm("movl $0x1, 0x48(%edi)");

    /* copy attacker, target, weapon, and ranged flag out */
    asm("pushl 0x8(%ebp)");
    asm("popl Hook_CCR_Attacker");

    asm("pushl 0xc(%ebp)");
    asm("popl Hook_CCR_Target");

    Hook_GetCriticalConfirmationAdjustment(
        (CNWSCreature *)Hook_CCR_Attacker,
        (CNWSCreature *)Hook_CCR_Target,
        Hook_CCR_Roll);

    /* the result of Hook_GetCriticalConfirmationAdjustment() is in %eax */

    asm("pushl Hook_CCR_Return");
    asm("ret");
}


/* vim: set sw=4: */
