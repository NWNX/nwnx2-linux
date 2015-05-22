
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

volatile CNWSCreatureStats *Hook_GetCriticalMultiplier_Attacker;
volatile CNWSItem *Hook_GetCriticalMultiplier_Weapon;


__attribute__((noinline))
static int Hook_GetCriticalMultiplierAdjustment(CNWSCreatureStats *attacker, CNWSItem *weapon)
{
    int feat, bonus = 0, im = CNWSCreatureStats__HasFeat(attacker, FEAT_INCREASE_MULTIPLIER);

    if (Table_WeaponOptions[NWNX_WEAPONS_OPT_POWCRIT_MULT_BONUS] &&
            (!im || Table_WeaponOptions[NWNX_WEAPONS_OPT_POWCRIT_MULT_STACK])) {

        if (weapon == NULL)
            feat = Table_WeaponPowerCritical[BASE_ITEM_GLOVES];
        else if (weapon->it_baseitem < NWNX_WEAPONS_BASE_ITEM_TABLE_SIZE)
            feat = Table_WeaponPowerCritical[weapon->it_baseitem];
        else
            feat = 0;

        if (feat > 0 && CNWSCreatureStats__HasFeat(attacker, feat))
            bonus += Table_WeaponOptions[NWNX_WEAPONS_OPT_POWCRIT_MULT_BONUS];
    }

    if (Table_WeaponOptions[NWNX_WEAPONS_OPT_SUPCRIT_MULT_BONUS] &&
            (!im || Table_WeaponOptions[NWNX_WEAPONS_OPT_SUPCRIT_MULT_STACK])) {

        if (weapon == NULL)
            feat = Table_WeaponSuperiorCritical[BASE_ITEM_GLOVES];
        else if (weapon->it_baseitem < NWNX_WEAPONS_BASE_ITEM_TABLE_SIZE)
            feat = Table_WeaponSuperiorCritical[weapon->it_baseitem];
        else
            feat = 0;

        if (feat > 0 && CNWSCreatureStats__HasFeat(attacker, feat))
            bonus += Table_WeaponOptions[NWNX_WEAPONS_OPT_SUPCRIT_MULT_BONUS];
    }

    if (Table_WeaponOptions[NWNX_WEAPONS_OPT_OVERCRIT_MULT_BONUS] &&
            (!im || Table_WeaponOptions[NWNX_WEAPONS_OPT_OVERCRIT_MULT_STACK])) {

        if (weapon == NULL)
            feat = Table_WeaponOverwhelmingCritical[BASE_ITEM_GLOVES];
        else if (weapon->it_baseitem < NWNX_WEAPONS_BASE_ITEM_TABLE_SIZE)
            feat = Table_WeaponOverwhelmingCritical[weapon->it_baseitem];
        else
            feat = 0;

        if (feat > 0 && CNWSCreatureStats__HasFeat(attacker, feat))
            bonus += Table_WeaponOptions[NWNX_WEAPONS_OPT_OVERCRIT_MULT_BONUS];
    }

    if (Table_WeaponOptions[NWNX_WEAPONS_OPT_DEVCRIT_MULT_BONUS] &&
            (!im || Table_WeaponOptions[NWNX_WEAPONS_OPT_DEVCRIT_MULT_STACK])) {

        if (weapon == NULL)
            feat = Table_WeaponDevastatingCritical[BASE_ITEM_GLOVES];
        else if (weapon->it_baseitem < NWNX_WEAPONS_BASE_ITEM_TABLE_SIZE)
            feat = Table_WeaponDevastatingCritical[weapon->it_baseitem];
        else
            feat = 0;

        if (feat > 0 && CNWSCreatureStats__HasFeat(attacker, feat))
            bonus += Table_WeaponOptions[NWNX_WEAPONS_OPT_DEVCRIT_MULT_BONUS];
    }

    return Local_GetCriticalMultiplierAdjustment(attacker, weapon, bonus);
}


void Hook_GetCriticalMultiplier(void)
{
    asm("leave");

    asm("movl %esi, Hook_GetCriticalMultiplier_Attacker");
    asm("movl %ebx, Hook_GetCriticalMultiplier_Weapon");

    Hook_GetCriticalMultiplierAdjustment(
        (CNWSCreatureStats *)Hook_GetCriticalMultiplier_Attacker,
        (CNWSItem *)Hook_GetCriticalMultiplier_Weapon);

    /* the result of Hook_GetCriticalMultiplierAdjustment() is in %eax */
    asm("addl %eax, %edi");

    /* duplicate the work originally done */
    asm("lea 0xfffffff4(%ebp), %esp");
    asm("pop %ebx");
    asm("pop %esi");
    asm("mov %edi, %eax");
    asm("pop %edi");
    asm("pop %ebp");
    asm("ret");
}


/* vim: set sw=4: */
