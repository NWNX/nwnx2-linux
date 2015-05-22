#include "CNWSCreatureStats.h"

void CNWSCreatureStats::AddExperience(unsigned long)
{
    asm("leave");
    asm("mov $0x08152478, %eax");
    asm("jmp *%eax");
}

void CNWSCreatureStats::AddFeat(unsigned short)
{
    asm("leave");
    asm("mov $0x08153b14, %eax");
    asm("jmp *%eax");
}

void CNWSCreatureStats::AddKnownSpell(unsigned char, unsigned long)
{
    asm("leave");
    asm("mov $0x08155118, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::AddSpellLikeAbilityToList(unsigned long, int, unsigned char)
{
    asm("leave");
    asm("mov $0x08165078, %eax");
    asm("jmp *%eax");
}

void CNWSCreatureStats::AdjustAlignment(unsigned char, short, unsigned long)
{
    asm("leave");
    asm("mov $0x081497d0, %eax");
    asm("jmp *%eax");
}

void CNWSCreatureStats::AdjustSpellUsesPerDay()
{
    asm("leave");
    asm("mov $0x08160088, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::AutoMemorizeSpells(int)
{
    asm("leave");
    asm("mov $0x0815c614, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::CalcLevelUpNumberFeats(unsigned char, unsigned char, unsigned char &, unsigned char &)
{
    asm("leave");
    asm("mov $0x08160e60, %eax");
    asm("jmp *%eax");
}

char CNWSCreatureStats::CalcStatModifier(unsigned char)
{
    asm("leave");
    asm("mov $0x08164554, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::CanChooseFeat(unsigned short, unsigned char, unsigned char, CExoArrayList<unsigned short> *)
{
    asm("leave");
    asm("mov $0x0815bc80, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::CanLevelUp()
{
    asm("leave");
    asm("mov $0x08158354, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::CheckSpellSuitability(int, CNWSpell *, int, int, int, int, int, int, unsigned char &, int)
{
    asm("leave");
    asm("mov $0x0815e04c, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::ClearFeats()
{
    asm("leave");
    asm("mov $0x08164648, %eax");
    asm("jmp *%eax");
}

void CNWSCreatureStats::ClearMemorizedSpellSlot(unsigned char, unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x081648d0, %eax");
    asm("jmp *%eax");
}

void CNWSCreatureStats::ComputeFeatBonuses(CExoArrayList<unsigned short> *, int, int)
{
    asm("leave");
    asm("mov $0x08162c14, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSCreatureStats::ComputeNumberKnownSpellsLeft(unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x0815e24c, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::ConfirmDomainSpell(unsigned char, unsigned char, unsigned long)
{
    asm("leave");
    asm("mov $0x08164800, %eax");
    asm("jmp *%eax");
}

void CNWSCreatureStats::DecrementFeatRemainingUses(unsigned short)
{
    asm("leave");
    asm("mov $0x081646ec, %eax");
    asm("jmp *%eax");
}

void CNWSCreatureStats::DecrementSpellsPerDayLeft(unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x08164d04, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::FeatAcquired(unsigned short, CExoArrayList<unsigned short> *, int)
{
    asm("leave");
    asm("mov $0x08164ed4, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::FeatRequirementsMetAfterLevelUp(unsigned short, CNWLevelStats *, unsigned char)
{
    asm("leave");
    asm("mov $0x08161160, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::FeatRequirementsMet(unsigned short, CExoArrayList<unsigned short> *)
{
    asm("leave");
    asm("mov $0x0815bf44, %eax");
    asm("jmp *%eax");
}

char CNWSCreatureStats::GetACNaturalBase(int)
{
    asm("leave");
    asm("mov $0x0815e684, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::GetAlignmentString()
{
    asm("leave");
    asm("mov $0x08151dfc, %eax");
    asm("jmp *%eax");
}

short CNWSCreatureStats::GetArmorClassVersus(CNWSCreature *, int)
{
    asm("leave");
    asm("mov $0x0814088c, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::GetAttackModifierVersus(CNWSCreature *)
{
    asm("leave");
    asm("mov $0x081445b4, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSCreatureStats::GetAttacksPerRound()
{
    asm("leave");
    asm("mov $0x08163d18, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::GetBaseAttackBonus(int)
{
    asm("leave");
    asm("mov $0x08142054, %eax");
    asm("jmp *%eax");
}

char CNWSCreatureStats::GetBaseFortSavingThrow()
{
    asm("leave");
    asm("mov $0x081529f0, %eax");
    asm("jmp *%eax");
}

char CNWSCreatureStats::GetBaseReflexSavingThrow()
{
    asm("leave");
    asm("mov $0x08152cc0, %eax");
    asm("jmp *%eax");
}

char CNWSCreatureStats::GetBaseWillSavingThrow()
{
    asm("leave");
    asm("mov $0x08152b4c, %eax");
    asm("jmp *%eax");
}

unsigned short CNWSCreatureStats::GetBonusFeat(unsigned short)
{
    asm("leave");
    asm("mov $0x08165550, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSCreatureStats::GetCHAStat()
{
    asm("leave");
    asm("mov $0x081641ac, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSCreatureStats::GetCONStat()
{
    asm("leave");
    asm("mov $0x08164020, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::GetCanUseRelatedCategory(int, int)
{
    asm("leave");
    asm("mov $0x08165580, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::GetCanUseSkillAfterLevelUp(unsigned short, CNWLevelStats *)
{
    asm("leave");
    asm("mov $0x08161918, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::GetCanUseSkill(unsigned char)
{
    asm("leave");
    asm("mov $0x08152e1c, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::GetCasterLevel(unsigned char)
{
    asm("leave");
    asm("mov $0x0815fe20, %eax");
    asm("jmp *%eax");
}

CNWSCreatureStats_ClassInfo * CNWSCreatureStats::GetClassInfo(unsigned char)
{
    asm("leave");
    asm("mov $0x08163dd0, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSCreatureStats::GetClassLevel(unsigned char, int)
{
    asm("leave");
    asm("mov $0x08163e50, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSCreatureStats::GetClassNegativeLevels(unsigned char)
{
    asm("leave");
    asm("mov $0x08163e9c, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::GetClassString(unsigned char)
{
    asm("leave");
    asm("mov $0x081643fc, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSCreatureStats::GetClass(unsigned char)
{
    asm("leave");
    asm("mov $0x08163da4, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSCreatureStats::GetCreatureDamageDice(unsigned char)
{
    asm("leave");
    asm("mov $0x0814425c, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSCreatureStats::GetCreatureDamageDie(unsigned char)
{
    asm("leave");
    asm("mov $0x08144368, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::GetCreatureHasTalent(int, int, unsigned char)
{
    asm("leave");
    asm("mov $0x08155888, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::GetCreatureTalentRandomFeat(int, int, int &, int &, unsigned char &)
{
    asm("leave");
    asm("mov $0x0815f9e8, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::GetCreatureTalentRandomKnownSpell(int, int, int &, int &, unsigned char &, int)
{
    asm("leave");
    asm("mov $0x08160220, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::GetCreatureTalentRandomMemorisedSpell(int, int, int &, int &, unsigned char &, int, unsigned char &)
{
    asm("leave");
    asm("mov $0x08160764, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::GetCreatureTalentRandomSkill(int, int, int &, int &, unsigned char &)
{
    asm("leave");
    asm("mov $0x0815fb84, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::GetCreatureTalentRandomSpellFromItem(int, int, int &, int &, unsigned char &, unsigned long &, int &)
{
    asm("leave");
    asm("mov $0x0815f13c, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::GetCreatureTalentRandomSpellLikeAbility(int, int, int &, int &, unsigned char &, unsigned char &)
{
    asm("leave");
    asm("mov $0x0815ee34, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::GetCreatureTalentRandomSpell(int, int, int &, int &, unsigned char &, unsigned char &)
{
    asm("leave");
    asm("mov $0x08165404, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::GetCreatureTalentRandom(int, int, int &, int &, unsigned char &, unsigned long &, int &, unsigned char &, unsigned char &)
{
    asm("leave");
    asm("mov $0x08155b18, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::GetCriticalHitMultiplier(int)
{
    asm("leave");
    asm("mov $0x0814c4a0, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::GetCriticalHitRoll(int)
{
    asm("leave");
    asm("mov $0x0814c31c, %eax");
    asm("jmp *%eax");
}

char CNWSCreatureStats::GetDEXMod(int)
{
    asm("leave");
    asm("mov $0x08151868, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSCreatureStats::GetDEXStat()
{
    asm("leave");
    asm("mov $0x081517b8, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::GetDamageBonus(CNWSCreature *, int)
{
    asm("leave");
    asm("mov $0x081476f0, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::GetDamageRoll(CNWSObject *, int, int, int, int, int)
{
    asm("leave");
    asm("mov $0x0814a8f0, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSCreatureStats::GetDomain1(unsigned char)
{
    asm("leave");
    asm("mov $0x08164e60, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSCreatureStats::GetDomain2(unsigned char)
{
    asm("leave");
    asm("mov $0x08164eac, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::GetEffectImmunity(unsigned char, CNWSCreature *)
{
    asm("leave");
    asm("mov $0x0815ff10, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSCreatureStats::GetEffectiveCRForPotentialLevel()
{
    asm("leave");
    asm("mov $0x0815284c, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::GetEpicWeaponDevastatingCritical(CNWSItem *)
{
    asm("leave");
    asm("mov $0x08156ccc, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::GetEpicWeaponFocus(CNWSItem *)
{
    asm("leave");
    asm("mov $0x08155ff0, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::GetEpicWeaponOverwhelmingCritical(CNWSItem *)
{
    asm("leave");
    asm("mov $0x08156a18, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::GetEpicWeaponSpecialization(CNWSItem *)
{
    asm("leave");
    asm("mov $0x08156550, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreatureStats::GetExpNeededForLevelUp()
{
    asm("leave");
    asm("mov $0x08152718, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::GetFavoredEnemyBonus(CNWSCreature *)
{
    asm("leave");
    asm("mov $0x0815e9e0, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSCreatureStats::GetFeatRemainingUses(unsigned short)
{
    asm("leave");
    asm("mov $0x08153e00, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSCreatureStats::GetFeatSourceClass(unsigned short)
{
    asm("leave");
    asm("mov $0x081623f4, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSCreatureStats::GetFeatTotalUses(unsigned short)
{
    asm("leave");
    asm("mov $0x0815479c, %eax");
    asm("jmp *%eax");
}

unsigned short CNWSCreatureStats::GetFeat(unsigned short)
{
    asm("leave");
    asm("mov $0x08165520, %eax");
    asm("jmp *%eax");
}

char CNWSCreatureStats::GetFortSavingThrow(int)
{
    asm("leave");
    asm("mov $0x08164f40, %eax");
    asm("jmp *%eax");
}

CExoString CNWSCreatureStats::GetFullName()
{
    asm("leave");
    asm("mov $0x08163c20, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::GetHasLostClassAbilities(unsigned char)
{
    asm("leave");
    asm("mov $0x08163ef8, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::GetHasSilencedSpell(unsigned long)
{
    asm("leave");
    asm("mov $0x08155520, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::GetHasStilledSpell(unsigned long)
{
    asm("leave");
    asm("mov $0x081556d8, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreatureStats::GetHighestLevelKnown()
{
    asm("leave");
    asm("mov $0x08164bcc, %eax");
    asm("jmp *%eax");
}

unsigned short CNWSCreatureStats::GetHighestLevelOfFeat(unsigned short)
{
    asm("leave");
    asm("mov $0x0816562c, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSCreatureStats::GetHitDie(unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x081578d8, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSCreatureStats::GetINTStat()
{
    asm("leave");
    asm("mov $0x081640a4, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::GetIsClassAvailable(unsigned char)
{
    asm("leave");
    asm("mov $0x08158534, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSCreatureStats::GetIsClass(unsigned char)
{
    asm("leave");
    asm("mov $0x08163dfc, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::GetIsDomainSpell(unsigned char, unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x08164848, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::GetIsEpitomeOfAlignment()
{
    asm("leave");
    asm("mov $0x0814954c, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::GetIsInKnownSpellList(unsigned char, unsigned long)
{
    asm("leave");
    asm("mov $0x0815df28, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::GetIsInSpellLikeAbilityList(unsigned long)
{
    asm("leave");
    asm("mov $0x081651ec, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::GetIsWeaponOfChoice(unsigned long)
{
    asm("leave");
    asm("mov $0x08160f50, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreatureStats::GetKnownSpell(unsigned char, unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x0816491c, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::GetLargePortrait()
{
    asm("leave");
    asm("mov $0x081642bc, %eax");
    asm("jmp *%eax");
}

CNWLevelStats * CNWSCreatureStats::GetLevelStats(unsigned char)
{
    asm("leave");
    asm("mov $0x08163ec8, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSCreatureStats::GetLevel(int)
{
    asm("leave");
    asm("mov $0x08163cc8, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::GetMeetsPrestigeClassRequirements(CNWClass *)
{
    asm("leave");
    asm("mov $0x08158748, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::GetMeleeAttackBonus(int, int, int)
{
    asm("leave");
    asm("mov $0x08143068, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::GetMeleeDamageBonus(int, unsigned char)
{
    asm("leave");
    asm("mov $0x08143524, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSCreatureStats::GetMemorizedSpellInSlotMetaType(unsigned char, unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x08164b00, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSCreatureStats::GetMemorizedSpellInSlotReady(unsigned char, unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x08164a08, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreatureStats::GetMemorizedSpellInSlot(unsigned char, unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x08164984, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSCreatureStats::GetMemorizedSpellReadyCount(unsigned char, unsigned long, unsigned char *, unsigned char *)
{
    asm("leave");
    asm("mov $0x08165360, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSCreatureStats::GetMemorizedSpellReadyCount(unsigned char, unsigned long, unsigned char)
{
    asm("leave");
    asm("mov $0x081653b0, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::GetMemorizedSpellReadyCount(unsigned long)
{
    asm("leave");
    asm("mov $0x0815e5ac, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::GetNumLevelsOfClass(unsigned char)
{
    asm("leave");
    asm("mov $0x08165750, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::GetNumLevelsOfClass(unsigned char, int)
{
    asm("leave");
    asm("mov $0x081634e0, %eax");
    asm("jmp *%eax");
}

unsigned short CNWSCreatureStats::GetNumberKnownSpells(unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x08164b8c, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSCreatureStats::GetNumberMemorizedSpellSlots(unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x08164c34, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSCreatureStats::GetPotentialLevel()
{
    asm("leave");
    asm("mov $0x08152794, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSCreatureStats::GetPrimaryMod(unsigned char)
{
    asm("leave");
    asm("mov $0x0815d778, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::GetRaceString()
{
    asm("leave");
    asm("mov $0x08164348, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::GetRangedAttackBonus(int, int)
{
    asm("leave");
    asm("mov $0x0814374c, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::GetRangedDamageBonus()
{
    asm("leave");
    asm("mov $0x08143b5c, %eax");
    asm("jmp *%eax");
}

char CNWSCreatureStats::GetReflexSavingThrow(int)
{
    asm("leave");
    asm("mov $0x0815db54, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSCreatureStats::GetSTRStat()
{
    asm("leave");
    asm("mov $0x08163f9c, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSCreatureStats::GetSchool(unsigned char)
{
    asm("leave");
    asm("mov $0x08164e14, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSCreatureStats::GetSimpleAlignmentGoodEvil()
{
    asm("leave");
    asm("mov $0x08163f74, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSCreatureStats::GetSimpleAlignmentLawChaos()
{
    asm("leave");
    asm("mov $0x08163f4c, %eax");
    asm("jmp *%eax");
}

char CNWSCreatureStats::GetSkillRank(unsigned char, CNWSObject *, int)
{
    asm("leave");
    asm("mov $0x08152f5c, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::GetSmallPortrait()
{
    asm("leave");
    asm("mov $0x08164230, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSCreatureStats::GetSpellFailure(unsigned char)
{
    asm("leave");
    asm("mov $0x0816569c, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSCreatureStats::GetSpellGainWithBonusAfterLevelUp(unsigned char, unsigned char, CNWLevelStats *, unsigned char, int)
{
    asm("leave");
    asm("mov $0x08161ab4, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSCreatureStats::GetSpellGainWithBonus(unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x08140520, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSCreatureStats::GetSpellLikeAbilityCasterLevel(unsigned long)
{
    asm("leave");
    asm("mov $0x081655c8, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::GetSpellMinAbilityMet(unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x08157210, %eax");
    asm("jmp *%eax");
}

char CNWSCreatureStats::GetSpellResistance()
{
    asm("leave");
    asm("mov $0x0815e3b0, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSCreatureStats::GetSpellUsesLeft(unsigned long, unsigned char, unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x08156f80, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSCreatureStats::GetSpellsOfLevelReady(unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x081624bc, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSCreatureStats::GetSpellsPerDayLeft(unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x08164cc4, %eax");
    asm("jmp *%eax");
}

void CNWSCreatureStats::GetStatBonusesFromFeats(CExoArrayList<unsigned short> *, int *, unsigned char)
{
    asm("leave");
    asm("mov $0x0816260c, %eax");
    asm("jmp *%eax");
}

float CNWSCreatureStats::GetStatById(int)
{
    asm("leave");
    asm("mov $0x0815dc00, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::GetTag()
{
    asm("leave");
    asm("mov $0x0816457c, %eax");
    asm("jmp *%eax");
}

char CNWSCreatureStats::GetTotalACSkillMod()
{
    asm("leave");
    asm("mov $0x081656d8, %eax");
    asm("jmp *%eax");
}

char CNWSCreatureStats::GetTotalCHABonus()
{
    asm("leave");
    asm("mov $0x08165334, %eax");
    asm("jmp *%eax");
}

char CNWSCreatureStats::GetTotalCONBonus()
{
    asm("leave");
    asm("mov $0x081652b0, %eax");
    asm("jmp *%eax");
}

char CNWSCreatureStats::GetTotalDEXBonus()
{
    asm("leave");
    asm("mov $0x08165284, %eax");
    asm("jmp *%eax");
}

char CNWSCreatureStats::GetTotalINTBonus()
{
    asm("leave");
    asm("mov $0x081652dc, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::GetTotalNegativeLevels()
{
    asm("leave");
    asm("mov $0x0816571c, %eax");
    asm("jmp *%eax");
}

char CNWSCreatureStats::GetTotalSTRBonus()
{
    asm("leave");
    asm("mov $0x08165258, %eax");
    asm("jmp *%eax");
}

char CNWSCreatureStats::GetTotalWISBonus()
{
    asm("leave");
    asm("mov $0x08165308, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSCreatureStats::GetUnarmedDamageDice()
{
    asm("leave");
    asm("mov $0x08143f88, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSCreatureStats::GetUnarmedDamageDie()
{
    asm("leave");
    asm("mov $0x0814408c, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::GetUnarmedDamageRoll(CNWSObject *)
{
    asm("leave");
    asm("mov $0x08144474, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::GetUseMonkAttackTables(int)
{
    asm("leave");
    asm("mov $0x08143f00, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSCreatureStats::GetWISStat()
{
    asm("leave");
    asm("mov $0x08164128, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::GetWeaponFinesse(CNWSItem *)
{
    asm("leave");
    asm("mov $0x08155cf4, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::GetWeaponFocus(CNWSItem *)
{
    asm("leave");
    asm("mov $0x08155dec, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::GetWeaponImprovedCritical(CNWSItem *)
{
    asm("leave");
    asm("mov $0x08156804, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::GetWeaponSpecialization(CNWSItem *)
{
    asm("leave");
    asm("mov $0x081562a4, %eax");
    asm("jmp *%eax");
}

char CNWSCreatureStats::GetWillSavingThrow(int)
{
    asm("leave");
    asm("mov $0x08164fdc, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::HasFeat(unsigned short)
{
    asm("leave");
    asm("mov $0x08153bc4, %eax");
    asm("jmp *%eax");
}

void CNWSCreatureStats::IncrementFeatRemainingUses(unsigned short)
{
    asm("leave");
    asm("mov $0x08164734, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::IncrementSpellsPerDayLeft(unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x08164d3c, %eax");
    asm("jmp *%eax");
}

void CNWSCreatureStats::LevelDown(CNWLevelStats *)
{
    asm("leave");
    asm("mov $0x08159870, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::LevelUpAutomatic(unsigned char, int, unsigned char)
{
    asm("leave");
    asm("mov $0x0815a0c4, %eax");
    asm("jmp *%eax");
}

void CNWSCreatureStats::LevelUp(CNWLevelStats *, unsigned char, unsigned char, unsigned char, int)
{
    asm("leave");
    asm("mov $0x081590f0, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::ModifyAlignment(short, short)
{
    asm("leave");
    asm("mov $0x081495f0, %eax");
    asm("jmp *%eax");
}

void CNWSCreatureStats::ReadSpellsFromGff(CResGFF *, CResStruct *, int)
{
    asm("leave");
    asm("mov $0x0814f8dc, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreatureStats::ReadStatsFromGff(CResGFF *, CResStruct *, CNWSCreatureAppearanceInfo *, int, int, int)
{
    asm("leave");
    asm("mov $0x0814c578, %eax");
    asm("jmp *%eax");
}

void CNWSCreatureStats::ReadySpellLevel(unsigned char)
{
    asm("leave");
    asm("mov $0x08157398, %eax");
    asm("jmp *%eax");
}

void CNWSCreatureStats::RemoveFeat(unsigned short)
{
    asm("leave");
    asm("mov $0x08164788, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::RemoveKnownSpell(unsigned char, unsigned long)
{
    asm("leave");
    asm("mov $0x08155250, %eax");
    asm("jmp *%eax");
}

void CNWSCreatureStats::ResetFeatRemainingUses()
{
    asm("leave");
    asm("mov $0x081646ac, %eax");
    asm("jmp *%eax");
}

void CNWSCreatureStats::ResetSpellLikeAbilities()
{
    asm("leave");
    asm("mov $0x081651a8, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::ResetSpellsPerDayLeft(unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x08164d74, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::ResolveSpecialAttackAttackBonus(CNWSCreature *)
{
    asm("leave");
    asm("mov $0x08148f20, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::ResolveSpecialAttackDamageBonus(CNWSCreature *)
{
    asm("leave");
    asm("mov $0x08149140, %eax");
    asm("jmp *%eax");
}

void CNWSCreatureStats::SaveClassInfo(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x08150964, %eax");
    asm("jmp *%eax");
}

void CNWSCreatureStats::SaveStats(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x0814fc8c, %eax");
    asm("jmp *%eax");
}

void CNWSCreatureStats::SetArcaneSpellFailure(char)
{
    asm("leave");
    asm("mov $0x081654cc, %eax");
    asm("jmp *%eax");
}

void CNWSCreatureStats::SetCHABase(unsigned char)
{
    asm("leave");
    asm("mov $0x08151c64, %eax");
    asm("jmp *%eax");
}

void CNWSCreatureStats::SetCONBase(unsigned char, int)
{
    asm("leave");
    asm("mov $0x081519f0, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::SetClassLevel(unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x081644dc, %eax");
    asm("jmp *%eax");
}

void CNWSCreatureStats::SetClassNegativeLevels(unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x08164518, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::SetClass(unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x081644a0, %eax");
    asm("jmp *%eax");
}

void CNWSCreatureStats::SetDEXBase(unsigned char)
{
    asm("leave");
    asm("mov $0x0816446c, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::SetDomain1(unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x08164e3c, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::SetDomain2(unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x08164e88, %eax");
    asm("jmp *%eax");
}

void CNWSCreatureStats::SetExperience(unsigned long, int)
{
    asm("leave");
    asm("mov $0x08152084, %eax");
    asm("jmp *%eax");
}

void CNWSCreatureStats::SetFeatRemainingUses(unsigned short, unsigned char)
{
    asm("leave");
    asm("mov $0x08153d14, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::SetHasLostClassAbilities(unsigned char, int)
{
    asm("leave");
    asm("mov $0x08163f24, %eax");
    asm("jmp *%eax");
}

void CNWSCreatureStats::SetINTBase(unsigned char)
{
    asm("leave");
    asm("mov $0x08151afc, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::SetMemorizedSpellInSlotReady(unsigned char, unsigned char, unsigned char, int)
{
    asm("leave");
    asm("mov $0x08164a8c, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::SetMemorizedSpellSlot(unsigned char, unsigned char, unsigned long, unsigned char, unsigned char, int)
{
    asm("leave");
    asm("mov $0x081552f4, %eax");
    asm("jmp *%eax");
}

void CNWSCreatureStats::SetMovementRate(int)
{
    asm("leave");
    asm("mov $0x0815d81c, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::SetNormalBonusFlags(unsigned short, int &, int &)
{
    asm("leave");
    asm("mov $0x0815c534, %eax");
    asm("jmp *%eax");
}

void CNWSCreatureStats::SetNumberBonusSpells(unsigned char, unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x0815fd64, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::SetNumberMemorizedSpellSlots(unsigned char, unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x08164c78, %eax");
    asm("jmp *%eax");
}

void CNWSCreatureStats::SetSTRBase(unsigned char)
{
    asm("leave");
    asm("mov $0x0815193c, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::SetSchool(unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x08164ddc, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::SetSkillRank(unsigned char, char)
{
    asm("leave");
    asm("mov $0x08164620, %eax");
    asm("jmp *%eax");
}

void CNWSCreatureStats::SetSpellFailure(unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x081656bc, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::SetSpellLikeAbilityReady(unsigned long, int, unsigned char)
{
    asm("leave");
    asm("mov $0x081650c8, %eax");
    asm("jmp *%eax");
}

void CNWSCreatureStats::SetSpellResistancePenalty(char)
{
    asm("leave");
    asm("mov $0x08165504, %eax");
    asm("jmp *%eax");
}

void CNWSCreatureStats::SetSpellResistance(char)
{
    asm("leave");
    asm("mov $0x081654e8, %eax");
    asm("jmp *%eax");
}

void CNWSCreatureStats::SetStatById(int, float)
{
    asm("leave");
    asm("mov $0x0815dcd4, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::SetTag(CExoString const &)
{
    asm("leave");
    asm("mov $0x0816458c, %eax");
    asm("jmp *%eax");
}

void CNWSCreatureStats::SetWISBase(unsigned char)
{
    asm("leave");
    asm("mov $0x08151bb0, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::UnReadySpell(unsigned long, unsigned char, unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x08157510, %eax");
    asm("jmp *%eax");
}

void CNWSCreatureStats::UpdateCombatInformation()
{
    asm("leave");
    asm("mov $0x08142134, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats::UpdateLastStatsObject(unsigned long long, CNWCreatureStatsUpdate *)
{
    asm("leave");
    asm("mov $0x0814a47c, %eax");
    asm("jmp *%eax");
}

void CNWSCreatureStats::UpdateNumberMemorizedSpellSlots()
{
    asm("leave");
    asm("mov $0x08151d18, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreatureStats::ValidateLevelUp(CNWLevelStats *, unsigned char, unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x081579cc, %eax");
    asm("jmp *%eax");
}

