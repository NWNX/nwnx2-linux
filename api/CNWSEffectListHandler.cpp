#include "CNWSEffectListHandler.h"

void CNWSEffectListHandler::InitializeEffects()
{
    asm("leave");
    asm("mov $0x0816b304, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyACDecrease(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x08170500, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyACIncrease(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x08170034, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyAbilityDecrease(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x0816f4d8, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyAbilityIncrease(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x0816f3a4, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyAppear(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x0817d5f8, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyArcaneSpellFailure(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x08172948, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyAreaOfEffect(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x08174f78, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyAttackDecrease(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x08170a48, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyAttackIncrease(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x08170978, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyBeam(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x08175334, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyBlindnessInactive(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x0817d3ec, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyBlindness(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x0817acdc, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyBonusFeat(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x0817d81c, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyBonusSpellOfLevel(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x0817d534, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyConcealment(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x0817b110, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyCurse(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x08177dc4, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyCutsceneGhost(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x0817dab8, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyCutsceneImmobile(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x0817db40, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyDamageDecrease(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x08170c18, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyDamageImmunityDecrease(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x0817153c, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyDamageImmunityIncrease(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x081712a8, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyDamageIncrease(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x08170b5c, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyDamageReduction(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x0816c6bc, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyDamageResistance(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x0816c750, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyDamageShield(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x0817d780, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyDamage(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x0816c7e4, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyDarkness(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x0817b1d4, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyDeaf(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x081724e0, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyDeath(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x0816e054, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyDefensiveStance(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x0817c920, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyDisappearAppear(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x0817b4a0, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyDisappear(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x0817d548, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyDisarm(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x08172004, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyDisease(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x08176548, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyDispelAllMagic(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x081786a8, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyDispelBestMagic(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x08178a44, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyEffectIcon(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x081798e0, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyEffectImmunity(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x08178470, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyEnemyAttackBonus(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x08172788, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyEntangled(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x0817181c, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyHasteInternal(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x08177038, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyHasteOrSlow(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x08176a78, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyHeal(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x0816dc58, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyHitPointChangeWhenDying(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x08179294, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyInvisibility(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x08177498, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyItemProperty(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x0817c088, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyKnockdown(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x08171b58, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyLight(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x0817d17c, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyLimitMovementSpeed(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x08178f4c, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyLink(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x0817d0cc, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyMissChance(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x0817d45c, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyModifyNumAttacks(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x0817d22c, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyMovementSpeedDecrease(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x08174868, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyMovementSpeedIncrease(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x08174644, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyNegativeLevel(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x0817b954, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyPetrify(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x0817bfc0, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyPoison(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x081759d8, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyPolymorph(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x08179c5c, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyRacialType(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x0817a23c, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyRegenerate(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x08175918, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyResurrection(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x0816f244, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplySanctuary(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x081776f4, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplySavingThrowDecrease(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x0816ff24, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplySavingThrowIncrease(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x0816fe08, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplySeeInvisible(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x0817a3d8, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplySetAIState(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x0817cfb4, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplySetStateInternal(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x08173a2c, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplySetState(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x08172b88, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplySilence(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x0817825c, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplySkillDecrease(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x08179190, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplySkillIncrease(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x081790d8, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplySlowInternal(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x081771c4, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplySpecialWalkAnimation(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x0817d350, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplySpellFailure(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x0817c808, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplySpellImmunity(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x0817d668, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplySpellLevelAbsorption(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x0817b8a8, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplySpellResistanceDecrease(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x081756a4, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplySpellResistanceIncrease(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x08175420, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyStore(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x0817dc14, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplySummonCreature(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x0816f7f8, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplySwarm(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x0817d994, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyTaunt(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x08178d84, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyTemporaryHitpoints(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x08170d08, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyTimestop(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x0817a0f4, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyTrueSeeing(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x0817a8f4, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyTurnResistance(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x0817d4c8, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyUltraVision(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x0817a520, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyVampiricRegeneration(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x0817bef0, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyVision(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x08177be0, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyVisualEffect(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x08174aac, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnApplyWounding(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x0817d910, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnEffectApplied(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x0817cc30, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnEffectRemoved(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x0817cc9c, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveACDecrease(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x08170738, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveACIncrease(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x081702c4, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveAbilityDecrease(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x0817cd50, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveAbilityIncrease(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x0817cd04, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveArcaneSpellFailure(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x08172a68, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveAreaOfEffect(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x0817d034, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveAttackDecrease(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x0817ce80, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveAttackIncrease(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x0817ce44, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveBeam(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x0817d0c0, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveBlindness(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x0817b034, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveBonusFeat(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x0817d898, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveBonusSpellOfLevel(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x0817d53c, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveConcealment(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x0817d4bc, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveCurse(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x0817d2a8, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveCutsceneGhost(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x0817db04, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveDamageDecrease(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x0817cef8, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveDamageImmunityDecrease(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x08171734, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveDamageImmunityIncrease(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x08171454, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveDamageIncrease(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x0817cebc, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveDamageShield(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x0817d810, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveDarkness(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x0817b3e0, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveDisappearAppear(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x0817b630, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveDisarm(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x0817cfa8, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveEffectIcon(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x08179a68, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveEffectImmunity(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x0817d2f0, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveEnemyAttackBonus(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x08172878, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveEntangled(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x0817cf34, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveHasteInternal(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x0817d12c, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveHasteOrSlow(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x08176dd0, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveHitPointChangeWhenDying(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x081793b8, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveInvisibility(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x081775c4, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveItemProperty(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x0817c3f4, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveKnockdown(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x08171f6c, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveLight(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x0817d214, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveLimitMovementSpeed(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x08179020, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveMissChance(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x0817d4b0, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveModifyNumAttacks(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x08177d00, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveMovementSpeedDecrease(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x081749a0, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveMovementSpeedIncrease(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x0817475c, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveNegativeLevel(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x0817d704, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemovePetrify(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x0817da28, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemovePolymorph(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x08179e90, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveRacialType(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x0817d3e0, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveSanctuary(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x08177928, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveSavingThrowDecrease(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x0817ce08, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveSavingThrowIncrease(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x0817cdcc, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveSeeInvisible(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x0817a46c, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveSetAIState(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x08172420, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveSetStateInternal(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x081744b8, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveSetState(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x08173830, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveSilence(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x0817d2b4, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveSkillDecrease(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x0817d344, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveSkillIncrease(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x0817d338, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveSlowInternal(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x0817d154, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveSpecialWalkAnimation(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x0817983c, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveSpellFailure(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x0817da34, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveSpellImmunity(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x0817d6f8, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveSpellLevelAbsorption(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x0817d65c, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveSpellResistanceDecrease(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x081757f8, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveSpellResistanceIncrease(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x08175558, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveSummonCreature(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x0817cd8c, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveSwarm(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x0817d9e8, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveTaunt(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x0817d2fc, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveTemporaryHitpoints(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x08170e00, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveTimestop(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x0817d3a4, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveTrueSeeing(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x0817aa80, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveTurnResistance(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x0817d528, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveUltraVision(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x0817a698, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveVision(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x0817d220, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveVisualEffect(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x0817d004, %eax");
    asm("jmp *%eax");
}

int CNWSEffectListHandler::OnRemoveWounding(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x0817d988, %eax");
    asm("jmp *%eax");
}

void CNWSEffectListHandler::SendFloatyEffect(unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x0816c4d8, %eax");
    asm("jmp *%eax");
}

