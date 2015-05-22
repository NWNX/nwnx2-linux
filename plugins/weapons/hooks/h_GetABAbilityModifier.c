
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

volatile uintptr_t Hook_ABAM_Return;
volatile CNWSCreatureStats *Hook_ABAM_Attacker;
volatile CNWSCreature *Hook_ABAM_Target;
volatile CNWSItem *Hook_ABAM_Weapon;
volatile int Hook_ABAM_Ranged;


__attribute__((noinline))
int Hook_GetAttackBonusAdjustment(CNWSCreatureStats *attacker, CNWSCreature *target, CNWSItem *weapon, int ranged)
{
    int baseitem, dexmod, ab_abil = 0, ab_feats = 0;

    if (attacker == NULL)
        return 0;

    dexmod   = CNWSCreatureStats__GetDEXMod(attacker, 0);
    baseitem = (weapon == NULL ? BASE_ITEM_GLOVES : weapon->it_baseitem);

    /* get the base ability modifier, also checking for Weapon Finesse */
    if (ranged)
        ab_abil = dexmod;
    else if (dexmod > attacker->cs_str_mod && CNWSCreatureStats__GetWeaponFinesse(attacker, weapon))
        ab_abil = dexmod;
    else
        ab_abil = attacker->cs_str_mod;

    /* check for ability modifier alteration feats (e.g. Zen Archery) */
    if (attacker->cs_str_mod > ab_abil                          &&
            Table_WeaponAbility[baseitem][ABILITY_STRENGTH] > 0     &&
            CNWSCreatureStats__HasFeat(attacker, Table_WeaponAbility[baseitem][ABILITY_STRENGTH]))
        ab_abil = attacker->cs_str_mod;

    if (dexmod > ab_abil                                        &&
            Table_WeaponAbility[baseitem][ABILITY_DEXTERITY] > 0    &&
            CNWSCreatureStats__HasFeat(attacker, Table_WeaponAbility[baseitem][ABILITY_DEXTERITY]))
        ab_abil = dexmod;

    if (attacker->cs_con_mod > ab_abil                          &&
            Table_WeaponAbility[baseitem][ABILITY_CONSTITUTION] > 0 &&
            CNWSCreatureStats__HasFeat(attacker, Table_WeaponAbility[baseitem][ABILITY_CONSTITUTION]))
        ab_abil = attacker->cs_con_mod;

    if (attacker->cs_int_mod > ab_abil                          &&
            Table_WeaponAbility[baseitem][ABILITY_INTELLIGENCE] > 0 &&
            CNWSCreatureStats__HasFeat(attacker, Table_WeaponAbility[baseitem][ABILITY_INTELLIGENCE]))
        ab_abil = attacker->cs_int_mod;

    if (attacker->cs_wis_mod > ab_abil                          &&
            Table_WeaponAbility[baseitem][ABILITY_WISDOM] > 0       &&
            CNWSCreatureStats__HasFeat(attacker, Table_WeaponAbility[baseitem][ABILITY_WISDOM]))
        ab_abil = attacker->cs_wis_mod;

    if (attacker->cs_cha_mod > ab_abil                          &&
            Table_WeaponAbility[baseitem][ABILITY_CHARISMA] > 0     &&
            CNWSCreatureStats__HasFeat(attacker, Table_WeaponAbility[baseitem][ABILITY_CHARISMA]))
        ab_abil = attacker->cs_cha_mod;

    if (Table_WeaponGreaterFocus[baseitem] > 0 &&
            CNWSCreatureStats__HasFeat(attacker, Table_WeaponGreaterFocus[baseitem]))
        ab_feats += Table_WeaponOptions[NWNX_WEAPONS_OPT_GRTFOCUS_AB_BONUS];

    if (Table_WeaponLegendaryFocus[baseitem] > 0 &&
            CNWSCreatureStats__HasFeat(attacker, Table_WeaponLegendaryFocus[baseitem])) {

        ab_feats += Table_WeaponOptions[NWNX_WEAPONS_OPT_LEGFOCUS_AB_BONUS];

        if (CNWSCreatureStats__HasFeat(attacker, FEAT_EPIC_PROWESS))
            ab_feats += Table_WeaponOptions[NWNX_WEAPONS_OPT_LEGFOCUS_AB_EPBONUS];
    }

    if (Table_WeaponParagonFocus[baseitem] > 0 &&
            CNWSCreatureStats__HasFeat(attacker, Table_WeaponParagonFocus[baseitem])) {

        ab_feats += Table_WeaponOptions[NWNX_WEAPONS_OPT_PARFOCUS_AB_BONUS];

        if (CNWSCreatureStats__HasFeat(attacker, FEAT_EPIC_PROWESS))
            ab_feats += Table_WeaponOptions[NWNX_WEAPONS_OPT_PARFOCUS_AB_EPBONUS];
    }

    /* apply local adjustments (if any) */
    return Local_GetAttackBonusAdjustment(attacker, target, weapon, ranged, ab_abil, ab_feats);
}


void Hook_GetABAbilityModifier(void)
{
    asm("leave");

    /* copy attacker, target, weapon, and ranged flag out */
    asm("pushl 0x8(%ebp)");
    asm("popl Hook_ABAM_Attacker");

    asm("pushl 0xc(%ebp)");
    asm("popl Hook_ABAM_Target");

    asm("pushl 0xfffffa38(%ebp)");
    asm("popl Hook_ABAM_Weapon");

    asm("pushl 0xfffffa3c(%ebp)");
    asm("popl Hook_ABAM_Ranged");

    Hook_GetAttackBonusAdjustment(
        (CNWSCreatureStats *)Hook_ABAM_Attacker,
        (CNWSCreature *)Hook_ABAM_Target,
        (CNWSItem *)Hook_ABAM_Weapon,
        Hook_ABAM_Ranged);

    /* the result of Hook_GetAttackBonusAdjustment() is in %eax */
    asm("mov %eax, %edi");

    asm("pushl Hook_ABAM_Return");
    asm("ret");
}


/* vim: set sw=4: */
