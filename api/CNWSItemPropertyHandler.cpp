#include "CNWSItemPropertyHandler.h"

int CNWSItemPropertyHandler::ApplyACBonus(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int)
{
    asm("leave");
    asm("mov $0x081aafec, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::ApplyAbilityBonus(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int)
{
    asm("leave");
    asm("mov $0x081aac94, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::ApplyArcaneSpellFailure(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int)
{
    asm("leave");
    asm("mov $0x081aff88, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::ApplyAttackBonus(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int)
{
    asm("leave");
    asm("mov $0x081a9e54, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::ApplyAttackPenalty(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int)
{
    asm("leave");
    asm("mov $0x081aa5c8, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::ApplyBonusFeat(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int)
{
    asm("leave");
    asm("mov $0x081acc68, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::ApplyBonusSpellOfLevel(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int)
{
    asm("leave");
    asm("mov $0x081b09ec, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::ApplyChangedSavingThrowVsX(CNWSItem *, int, CNWItemProperty *, CNWSCreature *, int)
{
    asm("leave");
    asm("mov $0x081abbbc, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::ApplyChangedSavingThrow(CNWSItem *, int, CNWItemProperty *, CNWSCreature *, int)
{
    asm("leave");
    asm("mov $0x081abab4, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::ApplyDamageBonus(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int)
{
    asm("leave");
    asm("mov $0x081a9704, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::ApplyDamageImmunity(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int)
{
    asm("leave");
    asm("mov $0x081ace90, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::ApplyDamagePenalty(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int)
{
    asm("leave");
    asm("mov $0x081ad1fc, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::ApplyDamageReduction(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int)
{
    asm("leave");
    asm("mov $0x081ad6a8, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::ApplyDamageResistance(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int)
{
    asm("leave");
    asm("mov $0x081ad900, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::ApplyDamageVulnerability(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int)
{
    asm("leave");
    asm("mov $0x081adb90, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::ApplyDarkVision(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int)
{
    asm("leave");
    asm("mov $0x081b032c, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::ApplyDecreaseAC(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int)
{
    asm("leave");
    asm("mov $0x081ae178, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::ApplyDecreaseAbility(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int)
{
    asm("leave");
    asm("mov $0x081ade1c, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::ApplyDecreaseSkill(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int)
{
    asm("leave");
    asm("mov $0x081ae41c, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::ApplyEnhancementBonus(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int)
{
    asm("leave");
    asm("mov $0x081a8064, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::ApplyEnhancementPenalty(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int)
{
    asm("leave");
    asm("mov $0x081a8f40, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::ApplyFreeAction(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int)
{
    asm("leave");
    asm("mov $0x081ac82c, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::ApplyHaste(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int)
{
    asm("leave");
    asm("mov $0x081b0a7c, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::ApplyHolyAvenger(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int)
{
    asm("leave");
    asm("mov $0x081ae74c, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::ApplyImmunity(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int)
{
    asm("leave");
    asm("mov $0x081af434, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::ApplyImprovedEvasion(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int)
{
    asm("leave");
    asm("mov $0x081b07c4, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::ApplyImprovedSavingThrowVsX(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int)
{
    asm("leave");
    asm("mov $0x081b044c, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::ApplyImprovedSavingThrow(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int)
{
    asm("leave");
    asm("mov $0x081b04ec, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::ApplyImprovedSpellResistance(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int)
{
    asm("leave");
    asm("mov $0x081ab60c, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::ApplyLight(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int)
{
    asm("leave");
    asm("mov $0x081aaa24, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::ApplyReducedSavingThrowVsX(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int)
{
    asm("leave");
    asm("mov $0x081b062c, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::ApplyReducedSavingThrow(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int)
{
    asm("leave");
    asm("mov $0x081b058c, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::ApplyRegeneration(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int)
{
    asm("leave");
    asm("mov $0x081afed0, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::ApplySkillBonus(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int)
{
    asm("leave");
    asm("mov $0x081af94c, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::ApplySpecialWalk(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int)
{
    asm("leave");
    asm("mov $0x081ac5e4, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::ApplySpellImmunityLevel(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int)
{
    asm("leave");
    asm("mov $0x081afd2c, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::ApplySpellImmunitySchool(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int)
{
    asm("leave");
    asm("mov $0x081afaf0, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::ApplySpellImmunitySpecific(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int)
{
    asm("leave");
    asm("mov $0x081af72c, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::ApplyTrueSeeing(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int)
{
    asm("leave");
    asm("mov $0x081b06cc, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::ApplyTurnResistance(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int)
{
    asm("leave");
    asm("mov $0x081b08e0, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::ApplyUnlimitedAmmo(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int)
{
    asm("leave");
    asm("mov $0x081ac058, %eax");
    asm("jmp *%eax");
}

void CNWSItemPropertyHandler::InitializeItemProperties()
{
    asm("leave");
    asm("mov $0x081a757c, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::OnItemPropertyApplied(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int)
{
    asm("leave");
    asm("mov $0x081b0250, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::OnItemPropertyRemoved(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long)
{
    asm("leave");
    asm("mov $0x081b02bc, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::RemoveACBonus(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long)
{
    asm("leave");
    asm("mov $0x081ab2e8, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::RemoveAbilityBonus(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long)
{
    asm("leave");
    asm("mov $0x081aae08, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::RemoveArcaneSpellFailure(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long)
{
    asm("leave");
    asm("mov $0x081b0094, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::RemoveAttackBonus(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long)
{
    asm("leave");
    asm("mov $0x081aa1e4, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::RemoveAttackPenalty(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long)
{
    asm("leave");
    asm("mov $0x081aa7fc, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::RemoveBonusFeat(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long)
{
    asm("leave");
    asm("mov $0x081acd80, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::RemoveBonusSpellOfLevel(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long)
{
    asm("leave");
    asm("mov $0x081acb94, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::RemoveChangedSavingThrowVsX(int, CNWSItem *, CNWItemProperty *, CNWSCreature *)
{
    asm("leave");
    asm("mov $0x081abe64, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::RemoveChangedSavingThrow(int, CNWSItem *, CNWItemProperty *, CNWSCreature *)
{
    asm("leave");
    asm("mov $0x081abd48, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::RemoveDamageBonus(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long)
{
    asm("leave");
    asm("mov $0x081a9a70, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::RemoveDamageImmunity(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long)
{
    asm("leave");
    asm("mov $0x081ad038, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::RemoveDamagePenalty(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long)
{
    asm("leave");
    asm("mov $0x081ad45c, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::RemoveDamageReduction(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long)
{
    asm("leave");
    asm("mov $0x081ad7c0, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::RemoveDamageResistance(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long)
{
    asm("leave");
    asm("mov $0x081ada28, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::RemoveDamageVulnerability(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long)
{
    asm("leave");
    asm("mov $0x081adcc4, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::RemoveDarkVision(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long)
{
    asm("leave");
    asm("mov $0x081b03c0, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::RemoveDecreaseAC(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long)
{
    asm("leave");
    asm("mov $0x081ae2c0, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::RemoveDecreaseAbility(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long)
{
    asm("leave");
    asm("mov $0x081adf94, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::RemoveDecreaseSkill(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long)
{
    asm("leave");
    asm("mov $0x081ae554, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::RemoveEnhancementBonus(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long)
{
    asm("leave");
    asm("mov $0x081a8818, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::RemoveEnhancementPenalty(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long)
{
    asm("leave");
    asm("mov $0x081a9344, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::RemoveFreeAction(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long)
{
    asm("leave");
    asm("mov $0x081aca7c, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::RemoveHaste(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long)
{
    asm("leave");
    asm("mov $0x081ae6b0, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::RemoveHolyAvenger(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long)
{
    asm("leave");
    asm("mov $0x081af1a4, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::RemoveImmunity(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long)
{
    asm("leave");
    asm("mov $0x081af620, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::RemoveImprovedEvasion(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long)
{
    asm("leave");
    asm("mov $0x081b0854, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::RemoveImprovedSavingThrowVsX(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long)
{
    asm("leave");
    asm("mov $0x081ab834, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::RemoveImprovedSavingThrow(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long)
{
    asm("leave");
    asm("mov $0x081ab8d4, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::RemoveImprovedSpellResistance(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long)
{
    asm("leave");
    asm("mov $0x081ab714, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::RemoveLight(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long)
{
    asm("leave");
    asm("mov $0x081aab60, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::RemoveReducedSavingThrowVsX(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long)
{
    asm("leave");
    asm("mov $0x081aba14, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::RemoveReducedSavingThrow(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long)
{
    asm("leave");
    asm("mov $0x081ab974, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::RemoveRegeneration(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long)
{
    asm("leave");
    asm("mov $0x081b0b00, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::RemoveSkillBonus(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long)
{
    asm("leave");
    asm("mov $0x081afa18, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::RemoveSpecialWalk(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long)
{
    asm("leave");
    asm("mov $0x081ac714, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::RemoveSpellImmunityLevel(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long)
{
    asm("leave");
    asm("mov $0x081afe00, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::RemoveSpellImmunitySchool(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long)
{
    asm("leave");
    asm("mov $0x081afc0c, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::RemoveSpellImmunitySpecific(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long)
{
    asm("leave");
    asm("mov $0x081af844, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::RemoveTrueSeeing(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long)
{
    asm("leave");
    asm("mov $0x081b074c, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::RemoveTurnResistance(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long)
{
    asm("leave");
    asm("mov $0x081b0974, %eax");
    asm("jmp *%eax");
}

int CNWSItemPropertyHandler::RemoveUnlimitedAmmo(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long)
{
    asm("leave");
    asm("mov $0x081ac534, %eax");
    asm("jmp *%eax");
}

