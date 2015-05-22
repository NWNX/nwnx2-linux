
/***************************************************************************
    ExaltReplace.c - Implementation of NWN combat replacement functions
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

volatile CNWSCreatureStats *Hook_GetCriticalRange_Attacker;
volatile CNWSItem *Hook_GetCriticalRange_Weapon;


__attribute__((noinline))
static int Hook_GetCriticalRangeAdjustment(CNWSCreatureStats *attacker, CNWSItem *weapon)
{
    int feat, bonus = 0, ki = CNWSCreatureStats__HasFeat(attacker, FEAT_KI_CRITICAL);

    if (Table_WeaponOptions[NWNX_WEAPONS_OPT_POWCRIT_RANGE_BONUS] &&
            (!ki || Table_WeaponOptions[NWNX_WEAPONS_OPT_POWCRIT_RANGE_STACK])) {

        if (weapon == NULL)
            feat = Table_WeaponPowerCritical[BASE_ITEM_GLOVES];
        else if (weapon->it_baseitem < NWNX_WEAPONS_BASE_ITEM_TABLE_SIZE)
            feat = Table_WeaponPowerCritical[weapon->it_baseitem];
        else
            feat = 0;

        if (feat > 0 && CNWSCreatureStats__HasFeat(attacker, feat))
            bonus += Table_WeaponOptions[NWNX_WEAPONS_OPT_POWCRIT_RANGE_BONUS];
    }

    if (Table_WeaponOptions[NWNX_WEAPONS_OPT_SUPCRIT_RANGE_BONUS] &&
            (!ki || Table_WeaponOptions[NWNX_WEAPONS_OPT_SUPCRIT_RANGE_STACK])) {

        if (weapon == NULL)
            feat = Table_WeaponSuperiorCritical[BASE_ITEM_GLOVES];
        else if (weapon->it_baseitem < NWNX_WEAPONS_BASE_ITEM_TABLE_SIZE)
            feat = Table_WeaponSuperiorCritical[weapon->it_baseitem];
        else
            feat = 0;

        if (feat > 0 && CNWSCreatureStats__HasFeat(attacker, feat))
            bonus += Table_WeaponOptions[NWNX_WEAPONS_OPT_SUPCRIT_RANGE_BONUS];
    }

    if (Table_WeaponOptions[NWNX_WEAPONS_OPT_OVERCRIT_RANGE_BONUS] &&
            (!ki || Table_WeaponOptions[NWNX_WEAPONS_OPT_OVERCRIT_RANGE_STACK])) {

        if (weapon == NULL)
            feat = Table_WeaponOverwhelmingCritical[BASE_ITEM_GLOVES];
        else if (weapon->it_baseitem < NWNX_WEAPONS_BASE_ITEM_TABLE_SIZE)
            feat = Table_WeaponOverwhelmingCritical[weapon->it_baseitem];
        else
            feat = 0;

        if (feat > 0 && CNWSCreatureStats__HasFeat(attacker, feat))
            bonus += Table_WeaponOptions[NWNX_WEAPONS_OPT_OVERCRIT_RANGE_BONUS];
    }

    if (Table_WeaponOptions[NWNX_WEAPONS_OPT_DEVCRIT_RANGE_BONUS] &&
            (!ki || Table_WeaponOptions[NWNX_WEAPONS_OPT_DEVCRIT_RANGE_STACK])) {

        if (weapon == NULL)
            feat = Table_WeaponDevastatingCritical[BASE_ITEM_GLOVES];
        else if (weapon->it_baseitem < NWNX_WEAPONS_BASE_ITEM_TABLE_SIZE)
            feat = Table_WeaponDevastatingCritical[weapon->it_baseitem];
        else
            feat = 0;

        if (feat > 0 && CNWSCreatureStats__HasFeat(attacker, feat))
            bonus += Table_WeaponOptions[NWNX_WEAPONS_OPT_DEVCRIT_RANGE_BONUS];
    }

    return Local_GetCriticalRangeAdjustment(attacker, weapon, bonus);
}


void Hook_GetCriticalRange(void)
{
    asm("leave");

    asm("pushl 0x8(%ebp)");
    asm("popl Hook_GetCriticalRange_Attacker");

    asm("movl %ebx, Hook_GetCriticalRange_Weapon");

    Hook_GetCriticalRangeAdjustment(
        (CNWSCreatureStats *)Hook_GetCriticalRange_Attacker,
        (CNWSItem *)Hook_GetCriticalRange_Weapon);

    /* the result of Hook_GetCriticalRangeAdjustment() is in %eax */
    asm("addl %eax, %edi");

    /* duplicate the work originally done */
    asm("mov %edi, %ecx");
    asm("lea 0xfffffff4(%ebp), %esp");
    asm("movzbl %cl, %edx");
    asm("mov %esi, %ecx");
    asm("movzbl %cl, %eax");
    asm("pop %ebx");
    asm("add %eax, %edx");
    asm("pop %esi");
    asm("mov $0x15, %eax");
    asm("sub %edx, %eax");
    asm("pop %edi");
    asm("pop %ebp");
    asm("ret");
}


/* vim: set sw=4: */
