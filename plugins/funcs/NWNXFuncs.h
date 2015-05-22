
/***************************************************************************
    NWNXFuncs.h - Interface for the CNWNXFuncs class.
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

#ifndef NWNX_FUNCS_H
#define NWNX_FUNCS_H


#include "NWNXLib.h"

#ifdef __cplusplus
extern "C" {
#endif

void Func_ActionUseItem(CGameObject *ob, char *value);
void Func_AddKnownFeat(CGameObject *ob, char *value);
void Func_AddKnownFeatAtLevel(CGameObject *ob, char *value);
void Func_AddKnownSpell(CGameObject *ob, char *value);
void Func_AddSpecialAbility(CGameObject *ob, char *value);
void Func_BootPCWithMessage(CGameObject *ob, char *value);
void Func_BroadcastProjectile(CGameObject *ob, char *value);
void Func_DumpObject(CGameObject *ob, char *value);
void Func_GetACNaturalBase(CGameObject *ob, char *value);
void Func_GetAbilityIncreaseByLevel(CGameObject *ob, char *value);
void Func_GetAllMemorizedSpells(CGameObject *ob, char *value);
void Func_GetAllRemainingFeatUses(CGameObject *ob, char *value);
void Func_GetBonusSpellSlots(CGameObject *ob, char *value);
void Func_GetClassByLevel(CGameObject *ob, char *value);
void Func_GetClericDomain(CGameObject *ob, char *value);
void Func_GetConversation(CGameObject *ob, char *value);
void Func_GetCorpseDecayTime(CGameObject *ob, char *value);
void Func_GetCreatureEventHandler(CGameObject *ob, char *value);
void Func_GetCriticalHitMultiplier(CGameObject *ob, char *value);
void Func_GetCriticalHitRange(CGameObject *ob, char *value);
void Func_GetDamageImmunity(CGameObject *ob, char *value);
void Func_GetEffectSkillModifier(CGameObject *ob, char *value);
void Func_GetEntireItemAppearance(CGameObject *ob, char *value);
void Func_GetEventHandler(CGameObject *ob, char *value);
void Func_GetFactionId(CGameObject *ob, char *value);
void Func_GetGroundHeight(CGameObject *ob, char *value);
void Func_GetIsClassBonusFeat(CGameObject *ob, char *value);
void Func_GetIsClassGeneralFeat(CGameObject *ob, char *value);
void Func_GetIsClassGrantedFeat(CGameObject *ob, char *value);
void Func_GetIsClassSkill(CGameObject *ob, char *value);
void Func_GetIsStatic(CGameObject *ob, char *value);
void Func_GetIsWalkable(CGameObject *ob, char *value);
void Func_GetItemByPositionRequest(CGameObject *ob, char *value);
void Func_GetItemCount(CGameObject *ob, char *value);
void Func_GetKnownFeat(CGameObject *ob, char *value);
void Func_GetKnownFeatByLevel(CGameObject *ob, char *value);
void Func_GetKnownSpell(CGameObject *ob, char *value);
void Func_GetKnowsFeat(CGameObject *ob, char *value);
void Func_GetKnowsSpell(CGameObject *ob, char *value);
void Func_GetLocalVariableByPosition(CGameObject *ob, char *value);
void Func_GetLocalVariableCount(CGameObject *ob, char *value);
void Func_GetMaxHitPointsByLevel(CGameObject *ob, char *value);
void Func_GetMaxSpellSlots(CGameObject *ob, char *value);
void Func_GetMeetsFeatRequirements(CGameObject *ob, char *value);
void Func_GetMemorizedSpell(CGameObject *ob, char *value);
void Func_GetPCBodyBag(CGameObject *ob, char *value);
void Func_GetPCFileName(CGameObject *ob, char *value);
void Func_GetPCPort(CGameObject *ob, char *value);
void Func_GetPCSkillPoints(CGameObject *ob, char *value);
void Func_GetPortrait(CGameObject *ob, char *value);
void Func_GetQuickBarSlot(CGameObject *ob, char *value);
void Func_GetRemainingFeatUses(CGameObject *ob, char *value);
void Func_GetRemainingSpellSlots(CGameObject *ob, char *value);
void Func_GetSavingThrowBonus(CGameObject *ob, char *value);
void Func_GetSkillIncreaseByLevel(CGameObject *ob, char *value);
void Func_GetSoundset(CGameObject *ob, char *value);
void Func_GetSpecialAbility(CGameObject *ob, char *value);
void Func_GetTotalFeatUses(CGameObject *ob, char *value);
void Func_GetTotalKnownFeats(CGameObject *ob, char *value);
void Func_GetTotalKnownFeatsByLevel(CGameObject *ob, char *value);
void Func_GetTotalKnownSpells(CGameObject *ob, char *value);
void Func_GetTotalSpecialAbilities(CGameObject *ob, char *value);
void Func_GetWizardSpecialization(CGameObject *ob, char *value);
void Func_IntToObjectRequest(CGameObject *ob, char *value);
void Func_JumpToLimbo(CGameObject *ob, char *value);
void Func_ModifyAbilityScore(CGameObject *ob, char *value);
void Func_ModifyCurrentHitPoints(CGameObject *ob, char *value);
void Func_ModifySkillRank(CGameObject *ob, char *value);
void Func_ModifySkillRankByLevel(CGameObject *ob, char *value);
void Func_RecalculateDexModifier(CGameObject *ob, char *value);
void Func_RemoveKnownFeat(CGameObject *ob, char *value);
void Func_RemoveKnownFeatByLevel(CGameObject *ob, char *value);
void Func_RemoveKnownSpell(CGameObject *ob, char *value);
void Func_RemoveSpecialAbility(CGameObject *ob, char *value);
void Func_ReplaceKnownFeat(CGameObject *ob, char *value);
void Func_ReplaceKnownSpell(CGameObject *ob, char *value);
void Func_RestoreItemAppearance(CGameObject *ob, char *value);
void Func_RestoreReadyFeats(CGameObject *ob, char *value);
void Func_RestoreReadySpells(CGameObject *ob, char *value);
void Func_SetACNaturalBase(CGameObject *ob, char *value);
void Func_SetAbilityScore(CGameObject *ob, char *value);
void Func_SetAlignmentValue(CGameObject *ob, char *value);
void Func_SetBaseItemType(CGameObject *ob, char *value);
void Func_SetClericDomain(CGameObject *ob, char *value);
void Func_SetConversation(CGameObject *ob, char *value);
void Func_SetCorpseDecayTime(CGameObject *ob, char *value);
void Func_SetCreatureEventHandler(CGameObject *ob, char *value);
void Func_SetCreatureSize(CGameObject *ob, char *value);
void Func_SetCurrentHitPoints(CGameObject *ob, char *value);
void Func_SetEventHandler(CGameObject *ob, char *value);
void Func_SetFactionId(CGameObject *ob, char *value);
void Func_SetGender(CGameObject *ob, char *value);
void Func_SetGoldPieceValue(CGameObject *ob, char *value);
void Func_SetIsCreatureDisarmable(CGameObject *ob, char *value);
void Func_SetItemAppearance(CGameObject *ob, char *value);
void Func_SetItemColor(CGameObject *ob, char *value);
void Func_SetItemWeight(CGameObject *ob, char *value);
void Func_SetKnownFeat(CGameObject *ob, char *value);
void Func_SetKnownFeatByLevel(CGameObject *ob, char *value);
void Func_SetKnownSpell(CGameObject *ob, char *value);
void Func_SetLastHostileActor(CGameObject *ob, char *value);
void Func_SetMaxHitPoints(CGameObject *ob, char *value);
void Func_SetMaxHitPointsByLevel(CGameObject *ob, char *value);
void Func_SetMemorizedSpell(CGameObject *ob, char *value);
void Func_SetMovementRate(CGameObject *ob, char *value);
void Func_SetPCBodyBag(CGameObject *ob, char *value);
void Func_SetPCLootable(CGameObject *ob, char *value);
void Func_SetPCSkillPoints(CGameObject *ob, char *value);
void Func_SetPlaceableAppearance(CGameObject *ob, char *value);
void Func_SetPortrait(CGameObject *ob, char *value);
void Func_SetQuickBarSlot(CGameObject *ob, char *value);
void Func_SetRacialType(CGameObject *ob, char *value);
void Func_SetRemainingSpellSlots(CGameObject *ob, char *value);
void Func_SetSavingThrowBonus(CGameObject *ob, char *value);
void Func_SetSkillRank(CGameObject *ob, char *value);
void Func_SetSoundset(CGameObject *ob, char *value);
void Func_SetSpecialAbility(CGameObject *ob, char *value);
void Func_SetTag(CGameObject *ob, char *value);
void Func_SetTrapCreator(CGameObject *ob, char *value);
void Func_SetWizardSpecialization(CGameObject *ob, char *value);
void Func_StringToObjectRequest(CGameObject *ob, char *value);
void Func_USleep(CGameObject *ob, char* value);
void Func_GetTimeOfDay(CGameObject *ob, char* value);

nwn_objid_t Func_GetFirstArea(CGameObject *ob);
nwn_objid_t Func_GetItemByPosition(CGameObject *ob);
nwn_objid_t Func_GetNextArea(CGameObject *ob);
nwn_objid_t Func_IntToObject(CGameObject *ob);

#ifdef __cplusplus
}

#include "NWNXBase.h"

class CNWNXFuncs: public CNWNXBase
{
public:
    CNWNXFuncs();
    virtual ~ CNWNXFuncs();

    bool OnCreate(gline *nwnxConfig, const char *LogDir = NULL);
    char *OnRequest(char *gameObject, char *Request, char *Parameters);
    unsigned long OnRequestObject(char *gameObject, char *Request);

    // bool OnRelease  ();
};
#endif

#endif /* NWNX_FUNCS_H */

/* vim: set sw=4: */
