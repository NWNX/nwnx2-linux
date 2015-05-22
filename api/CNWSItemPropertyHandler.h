#ifndef _CNWSITEMPROPERTYHANDLER_H_
#define _CNWSITEMPROPERTYHANDLER_H_
#include "nwndef.h"

class CNWSItemPropertyHandler
{
public:
    int ApplyACBonus(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int);
    int ApplyAbilityBonus(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int);
    int ApplyArcaneSpellFailure(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int);
    int ApplyAttackBonus(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int);
    int ApplyAttackPenalty(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int);
    int ApplyBonusFeat(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int);
    int ApplyBonusSpellOfLevel(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int);
    int ApplyChangedSavingThrowVsX(CNWSItem *, int, CNWItemProperty *, CNWSCreature *, int);
    int ApplyChangedSavingThrow(CNWSItem *, int, CNWItemProperty *, CNWSCreature *, int);
    int ApplyDamageBonus(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int);
    int ApplyDamageImmunity(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int);
    int ApplyDamagePenalty(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int);
    int ApplyDamageReduction(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int);
    int ApplyDamageResistance(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int);
    int ApplyDamageVulnerability(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int);
    int ApplyDarkVision(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int);
    int ApplyDecreaseAC(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int);
    int ApplyDecreaseAbility(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int);
    int ApplyDecreaseSkill(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int);
    int ApplyEnhancementBonus(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int);
    int ApplyEnhancementPenalty(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int);
    int ApplyFreeAction(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int);
    int ApplyHaste(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int);
    int ApplyHolyAvenger(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int);
    int ApplyImmunity(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int);
    int ApplyImprovedEvasion(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int);
    int ApplyImprovedSavingThrowVsX(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int);
    int ApplyImprovedSavingThrow(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int);
    int ApplyImprovedSpellResistance(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int);
    int ApplyLight(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int);
    int ApplyReducedSavingThrowVsX(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int);
    int ApplyReducedSavingThrow(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int);
    int ApplyRegeneration(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int);
    int ApplySkillBonus(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int);
    int ApplySpecialWalk(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int);
    int ApplySpellImmunityLevel(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int);
    int ApplySpellImmunitySchool(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int);
    int ApplySpellImmunitySpecific(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int);
    int ApplyTrueSeeing(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int);
    int ApplyTurnResistance(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int);
    int ApplyUnlimitedAmmo(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int);
    void InitializeItemProperties();
    int OnItemPropertyApplied(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int);
    int OnItemPropertyRemoved(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long);
    int RemoveACBonus(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long);
    int RemoveAbilityBonus(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long);
    int RemoveArcaneSpellFailure(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long);
    int RemoveAttackBonus(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long);
    int RemoveAttackPenalty(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long);
    int RemoveBonusFeat(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long);
    int RemoveBonusSpellOfLevel(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long);
    int RemoveChangedSavingThrowVsX(int, CNWSItem *, CNWItemProperty *, CNWSCreature *);
    int RemoveChangedSavingThrow(int, CNWSItem *, CNWItemProperty *, CNWSCreature *);
    int RemoveDamageBonus(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long);
    int RemoveDamageImmunity(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long);
    int RemoveDamagePenalty(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long);
    int RemoveDamageReduction(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long);
    int RemoveDamageResistance(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long);
    int RemoveDamageVulnerability(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long);
    int RemoveDarkVision(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long);
    int RemoveDecreaseAC(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long);
    int RemoveDecreaseAbility(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long);
    int RemoveDecreaseSkill(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long);
    int RemoveEnhancementBonus(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long);
    int RemoveEnhancementPenalty(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long);
    int RemoveFreeAction(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long);
    int RemoveHaste(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long);
    int RemoveHolyAvenger(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long);
    int RemoveImmunity(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long);
    int RemoveImprovedEvasion(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long);
    int RemoveImprovedSavingThrowVsX(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long);
    int RemoveImprovedSavingThrow(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long);
    int RemoveImprovedSpellResistance(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long);
    int RemoveLight(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long);
    int RemoveReducedSavingThrowVsX(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long);
    int RemoveReducedSavingThrow(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long);
    int RemoveRegeneration(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long);
    int RemoveSkillBonus(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long);
    int RemoveSpecialWalk(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long);
    int RemoveSpellImmunityLevel(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long);
    int RemoveSpellImmunitySchool(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long);
    int RemoveSpellImmunitySpecific(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long);
    int RemoveTrueSeeing(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long);
    int RemoveTurnResistance(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long);
    int RemoveUnlimitedAmmo(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long);
    ~CNWSItemPropertyHandler();

};
#endif
