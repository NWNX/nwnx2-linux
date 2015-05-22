
/***************************************************************************
    NWNXWeapons.h - Interface for the CNWNXWeapons class.
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

#ifndef NWNX_WEAPONS_H
#define NWNX_WEAPONS_H


#include "NWNXLib.h"

#define NWNX_WEAPONS_BASE_ITEM_TABLE_SIZE               512
#define NWNX_WEAPONS_OPTIONS_TABLE_SIZE                  64

#define NWNX_WEAPONS_OPT_DEVCRIT_DISABLE_ALL              0
#define NWNX_WEAPONS_OPT_DEVCRIT_DISABLE_PC               1
#define NWNX_WEAPONS_OPT_DEVCRIT_CONF_BONUS               2
#define NWNX_WEAPONS_OPT_DEVCRIT_MULT_BONUS               3
#define NWNX_WEAPONS_OPT_DEVCRIT_MULT_STACK               4
#define NWNX_WEAPONS_OPT_DEVCRIT_RANGE_BONUS              5
#define NWNX_WEAPONS_OPT_DEVCRIT_RANGE_STACK              6
#define NWNX_WEAPONS_OPT_OVERCRIT_CONF_BONUS              7
#define NWNX_WEAPONS_OPT_OVERCRIT_MULT_BONUS              8
#define NWNX_WEAPONS_OPT_OVERCRIT_MULT_STACK              9
#define NWNX_WEAPONS_OPT_OVERCRIT_RANGE_BONUS            10
#define NWNX_WEAPONS_OPT_OVERCRIT_RANGE_STACK            11
#define NWNX_WEAPONS_OPT_POWCRIT_CONF_BONUS              12
#define NWNX_WEAPONS_OPT_POWCRIT_MULT_BONUS              13
#define NWNX_WEAPONS_OPT_POWCRIT_MULT_STACK              14
#define NWNX_WEAPONS_OPT_POWCRIT_RANGE_BONUS             15
#define NWNX_WEAPONS_OPT_POWCRIT_RANGE_STACK             16
#define NWNX_WEAPONS_OPT_SUPCRIT_CONF_BONUS              17
#define NWNX_WEAPONS_OPT_SUPCRIT_MULT_BONUS              18
#define NWNX_WEAPONS_OPT_SUPCRIT_MULT_STACK              19
#define NWNX_WEAPONS_OPT_SUPCRIT_RANGE_BONUS             20
#define NWNX_WEAPONS_OPT_SUPCRIT_RANGE_STACK             21
#define NWNX_WEAPONS_OPT_GRTFOCUS_AB_BONUS               22
#define NWNX_WEAPONS_OPT_LEGFOCUS_AB_BONUS               23
#define NWNX_WEAPONS_OPT_LEGFOCUS_AB_EPBONUS             24
#define NWNX_WEAPONS_OPT_PARFOCUS_AB_BONUS               25
#define NWNX_WEAPONS_OPT_PARFOCUS_AB_EPBONUS             26
#define NWNX_WEAPONS_OPT_GRTSPEC_DAM_BONUS               27
#define NWNX_WEAPONS_OPT_LEGSPEC_DAM_BONUS               28
#define NWNX_WEAPONS_OPT_PARSPEC_DAM_BONUS               29

#ifdef __cplusplus
extern "C" {
#endif

bool GetIsUnarmedWeapon(CNWSItem *weapon);
bool GetIsWeaponLight(CNWSCreatureStats *info, CNWSItem *weapon, bool finesse);

void Func_GetWeaponOption(CGameObject *ob, char *value);
void Func_SetWeaponOption(CGameObject *ob, char *value);

void Func_GetAttackBonusAdjustment(CGameObject *ob, char *value);

void Func_GetWeaponAbilityFeat(CGameObject *ob, char *value);
void Func_GetWeaponDevastatingCriticalFeat(CGameObject *ob, char *value);
void Func_GetWeaponEpicFocusFeat(CGameObject *ob, char *value);
void Func_GetWeaponEpicSpecializationFeat(CGameObject *ob, char *value);
void Func_GetWeaponFinesseSize(CGameObject *ob, char *value);
void Func_GetWeaponFocusFeat(CGameObject *ob, char *value);
void Func_GetWeaponGreaterFocusFeat(CGameObject *ob, char *value);
void Func_GetWeaponGreaterSpecializationFeat(CGameObject *ob, char *value);
void Func_GetWeaponImprovedCriticalFeat(CGameObject *ob, char *value);
void Func_GetWeaponIsMonkWeapon(CGameObject *ob, char *value);
void Func_GetWeaponLegendaryFocusFeat(CGameObject *ob, char *value);
void Func_GetWeaponLegendarySpecializationFeat(CGameObject *ob, char *value);
void Func_GetWeaponOfChoiceFeat(CGameObject *ob, char *value);
void Func_GetWeaponOverwhelmingCriticalFeat(CGameObject *ob, char *value);
void Func_GetWeaponParagonFocusFeat(CGameObject *ob, char *value);
void Func_GetWeaponParagonSpecializationFeat(CGameObject *ob, char *value);
void Func_GetWeaponPowerCriticalFeat(CGameObject *ob, char *value);
void Func_GetWeaponSpecializationFeat(CGameObject *ob, char *value);
void Func_GetWeaponSuperiorCriticalFeat(CGameObject *ob, char *value);

void Func_SetWeaponAbilityFeat(CGameObject *ob, char *value);
void Func_SetWeaponDevastatingCriticalFeat(CGameObject *ob, char *value);
void Func_SetWeaponEpicFocusFeat(CGameObject *ob, char *value);
void Func_SetWeaponEpicSpecializationFeat(CGameObject *ob, char *value);
void Func_SetWeaponFinesseSize(CGameObject *ob, char *value);
void Func_SetWeaponFocusFeat(CGameObject *ob, char *value);
void Func_SetWeaponGreaterFocusFeat(CGameObject *ob, char *value);
void Func_SetWeaponGreaterSpecializationFeat(CGameObject *ob, char *value);
void Func_SetWeaponImprovedCriticalFeat(CGameObject *ob, char *value);
void Func_SetWeaponIsMonkWeapon(CGameObject *ob, char *value);
void Func_SetWeaponLegendaryFocusFeat(CGameObject *ob, char *value);
void Func_SetWeaponLegendarySpecializationFeat(CGameObject *ob, char *value);
void Func_SetWeaponOfChoiceFeat(CGameObject *ob, char *value);
void Func_SetWeaponOverwhelmingCriticalFeat(CGameObject *ob, char *value);
void Func_SetWeaponParagonFocusFeat(CGameObject *ob, char *value);
void Func_SetWeaponParagonSpecializationFeat(CGameObject *ob, char *value);
void Func_SetWeaponPowerCriticalFeat(CGameObject *ob, char *value);
void Func_SetWeaponSpecializationFeat(CGameObject *ob, char *value);
void Func_SetWeaponSuperiorCriticalFeat(CGameObject *ob, char *value);

nwn_objid_t Func_IntToObject(CGameObject *ob);

void Hook_GetABAbilityModifier(void);
void Hook_GetCriticalConfirmationRoll(void);
void Hook_GetCriticalMultiplier(void);
void Hook_GetCriticalRange(void);
void Hook_GetMonsterDamageHandler(void);
void Hook_OffhandCritMult1(void);
void Hook_OffhandCritMult2(void);
void Hook_OffhandCritMult3(void);
void Hook_OffhandCritMult4(void);

int Hook_GetAttackBonusAdjustment(CNWSCreatureStats *attacker, CNWSCreature *target, CNWSItem *weapon, int ranged);
int Hook_GetDamageBonusAdjustment(CNWSCreatureStats *info, CNWSItem *weapon);
int Hook_GetEpicWeaponDevastatingCritical(CNWSCreatureStats *info, CNWSItem *weapon);
int Hook_GetEpicWeaponFocus(CNWSCreatureStats *info, CNWSItem *weapon);
int Hook_GetEpicWeaponOverwhelmingCritical(CNWSCreatureStats *info, CNWSItem *weapon);
int Hook_GetEpicWeaponSpecialization(CNWSCreatureStats *info, CNWSItem *weapon);
int Hook_GetIsWeaponOfChoice(CNWSCreatureStats *info, int baseitem);
int Hook_GetUseMonkAttackTables(CNWSCreatureStats *info, int unarmedonly);
int Hook_GetWeaponFinesse(CNWSCreatureStats *info, CNWSItem *weapon);
int Hook_GetWeaponFocus(CNWSCreatureStats *info, CNWSItem *weapon);
int Hook_GetWeaponImprovedCritical(CNWSCreatureStats *info, CNWSItem *weapon);
int Hook_GetWeaponSpecialization(CNWSCreatureStats *info, CNWSItem *weapon);


int Local_GetAttackBonusAdjustment(CNWSCreatureStats *attacker, CNWSCreature *target, CNWSItem *weapon,
                                   int ranged, int ab_abil, int ab_feats);
int Local_GetCriticalConfirmationAdjustment(CNWSCreature *attacker, CNWSCreature *target, CNWSItem *weapon, int roll, int bonus);
int Local_GetCriticalMultiplierAdjustment(CNWSCreatureStats *attacker, CNWSItem *weapon, int adj);
int Local_GetCriticalRangeAdjustment(CNWSCreatureStats *attacker, CNWSItem *weapon, int adj);
int Local_GetDamageBonusAdjustment(CNWSCreatureStats *attacker, CNWSItem *weapon, int adj);


extern uint16_t Table_WeaponOptions[NWNX_WEAPONS_OPTIONS_TABLE_SIZE];

extern uint16_t Table_WeaponAbility[NWNX_WEAPONS_BASE_ITEM_TABLE_SIZE][6];
extern uint16_t Table_WeaponDevastatingCritical[NWNX_WEAPONS_BASE_ITEM_TABLE_SIZE];
extern uint16_t Table_WeaponEpicFocus[NWNX_WEAPONS_BASE_ITEM_TABLE_SIZE];
extern uint16_t Table_WeaponEpicSpecialization[NWNX_WEAPONS_BASE_ITEM_TABLE_SIZE];
extern uint16_t Table_WeaponFinesseSize[NWNX_WEAPONS_BASE_ITEM_TABLE_SIZE];
extern uint16_t Table_WeaponFocus[NWNX_WEAPONS_BASE_ITEM_TABLE_SIZE];
extern uint16_t Table_WeaponGreaterFocus[NWNX_WEAPONS_BASE_ITEM_TABLE_SIZE];
extern uint16_t Table_WeaponGreaterSpecialization[NWNX_WEAPONS_BASE_ITEM_TABLE_SIZE];
extern uint16_t Table_WeaponImprovedCritical[NWNX_WEAPONS_BASE_ITEM_TABLE_SIZE];
extern uint16_t Table_WeaponIteration[NWNX_WEAPONS_BASE_ITEM_TABLE_SIZE];
extern uint16_t Table_WeaponLegendaryFocus[NWNX_WEAPONS_BASE_ITEM_TABLE_SIZE];
extern uint16_t Table_WeaponLegendarySpecialization[NWNX_WEAPONS_BASE_ITEM_TABLE_SIZE];
extern uint16_t Table_WeaponMonk[NWNX_WEAPONS_BASE_ITEM_TABLE_SIZE];
extern uint16_t Table_WeaponOfChoice[NWNX_WEAPONS_BASE_ITEM_TABLE_SIZE];
extern uint16_t Table_WeaponOverwhelmingCritical[NWNX_WEAPONS_BASE_ITEM_TABLE_SIZE];
extern uint16_t Table_WeaponParagonFocus[NWNX_WEAPONS_BASE_ITEM_TABLE_SIZE];
extern uint16_t Table_WeaponParagonSpecialization[NWNX_WEAPONS_BASE_ITEM_TABLE_SIZE];
extern uint16_t Table_WeaponPowerCritical[NWNX_WEAPONS_BASE_ITEM_TABLE_SIZE];
extern uint16_t Table_WeaponSpecialization[NWNX_WEAPONS_BASE_ITEM_TABLE_SIZE];
extern uint16_t Table_WeaponSuperiorCritical[NWNX_WEAPONS_BASE_ITEM_TABLE_SIZE];

#ifdef __cplusplus
}

#include "NWNXBase.h"

class CNWNXWeapons: public CNWNXBase
{
public:
    CNWNXWeapons();
    virtual ~ CNWNXWeapons();

    bool OnCreate(gline *nwnxConfig, const char *LogDir = NULL);
    char *OnRequest(char *gameObject, char *Request, char *Parameters);
    unsigned long OnRequestObject(char *gameObject, char *Request);

    // bool OnRelease  ();
};
#endif

#endif /* NWNX_WEAPONS_H */

/* vim: set sw=4: */
