
/***************************************************************************
    NWNXDefenses.h - Interface for the CNWNXDefenses class.
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

#ifndef NWNX_DEFENSES_H
#define NWNX_DEFENSES_H


#include "NWNXLib.h"

#define NWNX_DEFENSES_BASE_ITEM_TABLE_SIZE              512
#define NWNX_DEFENSES_OPTIONS_TABLE_SIZE                 64

#define NWNX_DEFENSES_OPT_PALADIN_SAVES_MIN_ALIGN_GE      0 
#define NWNX_DEFENSES_OPT_PALADIN_SAVES_MIN_ALIGN_LC      1 
#define NWNX_DEFENSES_OPT_BLACKGUARD_SAVES_MAX_ALIGN_GE   2 
#define NWNX_DEFENSES_OPT_BLACKGUARD_SAVES_MAX_ALIGN_LC   3 
#define NWNX_DEFENSES_OPT_DEATHATT_IGNORE_CRIT_IMM        4
#define NWNX_DEFENSES_OPT_SNEAKATT_IGNORE_CRIT_IMM        5

#define AC_STRENGTH_BONUS                               -15
#define AC_DEXTERITY_BONUS                              -14
#define AC_CONSTITUTION_BONUS                           -13
#define AC_INTELLIGENCE_BONUS                           -12
#define AC_CHARISMA_BONUS                               -11
#define AC_EQUIP_BONUS                                  -10
#define AC_SKILL_BONUS                                   -9
#define AC_CLASS_BONUS                                   -8
#define AC_FEAT_BONUS                                    -7
#define AC_WISDOM_BONUS                                  -6
#define AC_OTHER_BONUS                                   -5
#define AC_TOUCH_BASE                                    -4
#define AC_SHIELD_BASE                                   -3
#define AC_ARMOUR_BASE                                   -2
#define AC_NATURAL_BASE                                  -1

#ifdef NWNX_DEFENSES_HG
#define DAMAGE_TYPE_LAST                                 23
#else
#define DAMAGE_TYPE_LAST                                 12
#endif


#ifdef __cplusplus
extern "C" {
#endif

void Func_GetACByType                        (CGameObject *ob, char *value);
void Func_GetACVersus                        (CGameObject *ob, char *value);
void Func_GetAllSpellImmunities              (CGameObject *ob, char *value);
void Func_GetDefenseOption                   (CGameObject *ob, char *value);
void Func_GetEffectDamageReduction           (CGameObject *ob, char *value);
void Func_GetEffectDamageResistance          (CGameObject *ob, char *value);
void Func_GetHasSpellImmunity                (CGameObject *ob, char *value);
void Func_GetTrueDamageImmunity              (CGameObject *ob, char *value);
void Func_SetDefenseOption                   (CGameObject *ob, char *value);

nwn_objid_t Func_IntToObject (CGameObject *ob);

void Hook_AddDamageImmunity (CNWSCreature *cre, int damtype, int percent);
void Hook_CheckConcealment (void);
void Hook_CombatHitDamage (void);
void Hook_GetFortitudeSavingThrow (void);
void Hook_GetReflexSavingThrow (void);
void Hook_GetWillSavingThrow (void);
void Hook_PickPocketDC (void);
void Hook_SetDamageImmunity (CNWSCreature *cre, int damtype, int percent);

int Hook_GetACClassAdjustment (CNWSCreatureStats *stats, int touch);
int Hook_GetACFeatAdjustment (CNWSCreatureStats *stats, int touch);
int Hook_GetACNaturalBase (CNWSCreatureStats *stats, int touch);
int Hook_GetACWisAdjustment (CNWSCreatureStats *stats, int touch);
int Hook_GetHasSlipperyMind (CNWSCreatureStats *stats, uint32_t savedata);
int Hook_GetIsDeathAttackImmune (CNWSCreatureStats *target, uint8_t immtype, CNWSCreature *attacker);
int Hook_GetIsSneakAttackImmune (CNWSCreatureStats *target, uint8_t immtype, CNWSCreature *attacker);
int Hook_GetTumbleACBonus (CNWSCreatureStats *stats);

int8_t Hook_GetDamageImmunity (CNWSCreature *cre, int damtypeindex);

void Local_AdjustCombatHitDamage(CNWSCreature *target, int16_t *damages, int crit);
int Local_GetACChaAdjustment (CNWSCreatureStats *stats, int touch, int adj);
int Local_GetACClassAdjustment (CNWSCreatureStats *stats, int touch, int adj);
int Local_GetACConAdjustment (CNWSCreatureStats *stats, int touch, int adj);
int Local_GetACDexAdjustment (CNWSCreatureStats *stats, int touch, int adj);
int Local_GetACEquipAdjustment (CNWSCreatureStats *stats, int touch, int adj);
int Local_GetACFeatAdjustment (CNWSCreatureStats *stats, int touch, int adj);
int Local_GetACIntAdjustment (CNWSCreatureStats *stats, int touch, int adj);
int Local_GetACSkillAdjustment (CNWSCreatureStats *stats, int touch, int adj);
int Local_GetACStrAdjustment (CNWSCreatureStats *stats, int touch, int adj);
int Local_GetACTumbleAdjustment (CNWSCreatureStats *stats, int adj);
int Local_GetACTouchBase (CNWSCreatureStats *stats);
int Local_GetACWisAdjustment (CNWSCreatureStats *stats, int touch, int adj);
int Local_GetConcealmentCheckResult (CNWSCreature *attacker, CNWSCreature *target, int concealment, int misschance);
int Local_GetDamageImmunity (CNWSCreature *cre, int damtypeindex, int imm);
int Local_GetHasSlipperyMind (CNWSCreatureStats *stats, uint32_t savedata);
int Local_GetIsDeathAttackImmune (CNWSCreatureStats *target, uint8_t immtype, CNWSCreature *attacker);
int Local_GetIsSneakAttackImmune (CNWSCreatureStats *target, uint8_t immtype, CNWSCreature *attacker);
int Local_GetPickPocketDCAdjustment (CNWSCreature *thief, CNWSCreature *victim);


extern uint16_t Table_DefenseOptions[NWNX_DEFENSES_OPTIONS_TABLE_SIZE];

#ifdef __cplusplus
}

#include "NWNXBase.h"

class CNWNXDefenses:public CNWNXBase {
  public:
    CNWNXDefenses ();
    virtual ~ CNWNXDefenses ();

    bool OnCreate (gline *nwnxConfig, const char *LogDir = NULL);
    char *OnRequest (char *gameObject, char *Request, char *Parameters);
    unsigned long OnRequestObject (char *gameObject, char *Request);

    // bool OnRelease  ();
};
#endif

#endif /* NWNX_DEFENSES_H */

/* vim: set sw=4: */
