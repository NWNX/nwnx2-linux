#include "CNWRules.h"

int CNWRules::CompareFeatName(void const *, void const *)
{
    asm("leave");
    asm("mov $0x080c85ec, %eax");
    asm("jmp *%eax");
}

CTwoDimArrays * CNWRules::Get2DArrays()
{
    asm("leave");
    asm("mov $0x080cbba8, %eax");
    asm("jmp *%eax");
}

int CNWRules::GetBaseItem(unsigned long)
{
    asm("leave");
    asm("mov $0x080cba5c, %eax");
    asm("jmp *%eax");
}

unsigned char CNWRules::GetClassExpansionLevel(unsigned char)
{
    asm("leave");
    asm("mov $0x080cb9a8, %eax");
    asm("jmp *%eax");
}

int CNWRules::GetClass(unsigned char)
{
    asm("leave");
    asm("mov $0x080cbac8, %eax");
    asm("jmp *%eax");
}

int CNWRules::GetDamageIndexFromFlags(unsigned long)
{
    asm("leave");
    asm("mov $0x080cb894, %eax");
    asm("jmp *%eax");
}

int CNWRules::GetDifficultyOption(int, int)
{
    asm("leave");
    asm("mov $0x080cb780, %eax");
    asm("jmp *%eax");
}

CNWDomain * CNWRules::GetDomain(unsigned short)
{
    asm("leave");
    asm("mov $0x080cb750, %eax");
    asm("jmp *%eax");
}

int CNWRules::GetExperienceLevel(unsigned char)
{
    asm("leave");
    asm("mov $0x080cba74, %eax");
    asm("jmp *%eax");
}

unsigned char CNWRules::GetFamiliarExpansionLevel(unsigned char, int)
{
    asm("leave");
    asm("mov $0x080cb9d8, %eax");
    asm("jmp *%eax");
}

unsigned char CNWRules::GetFeatExpansionLevel(unsigned short)
{
    asm("leave");
    asm("mov $0x080cb8b4, %eax");
    asm("jmp *%eax");
}

CNWFeat * CNWRules::GetFeat(unsigned short)
{
    asm("leave");
    asm("mov $0x080cb718, %eax");
    asm("jmp *%eax");
}

int CNWRules::GetIsClassValid(unsigned char)
{
    asm("leave");
    asm("mov $0x080cbab0, %eax");
    asm("jmp *%eax");
}

int CNWRules::GetMasterFeatDescriptionText(char)
{
    asm("leave");
    asm("mov $0x080c8518, %eax");
    asm("jmp *%eax");
}

int CNWRules::GetMasterFeatIcon(char)
{
    asm("leave");
    asm("mov $0x080cb62c, %eax");
    asm("jmp *%eax");
}

CExoString CNWRules::GetMasterFeatNameText(char)
{
    asm("leave");
    asm("mov $0x080c8444, %eax");
    asm("jmp *%eax");
}

unsigned char CNWRules::GetMetaMagicLevelCost(unsigned char)
{
    asm("leave");
    asm("mov $0x080cb6f0, %eax");
    asm("jmp *%eax");
}

int CNWRules::GetNumClasses()
{
    asm("leave");
    asm("mov $0x080cbae8, %eax");
    asm("jmp *%eax");
}

int CNWRules::GetNumDomains()
{
    asm("leave");
    asm("mov $0x080cbb50, %eax");
    asm("jmp *%eax");
}

int CNWRules::GetNumFeats()
{
    asm("leave");
    asm("mov $0x080cbb78, %eax");
    asm("jmp *%eax");
}

int CNWRules::GetNumRaces()
{
    asm("leave");
    asm("mov $0x080cbb14, %eax");
    asm("jmp *%eax");
}

int CNWRules::GetNumSkills()
{
    asm("leave");
    asm("mov $0x080cbb40, %eax");
    asm("jmp *%eax");
}

int CNWRules::GetNumSortedFeats()
{
    asm("leave");
    asm("mov $0x080cbb88, %eax");
    asm("jmp *%eax");
}

int CNWRules::GetNumSpells()
{
    asm("leave");
    asm("mov $0x080cbaa0, %eax");
    asm("jmp *%eax");
}

int CNWRules::GetRace(unsigned short)
{
    asm("leave");
    asm("mov $0x080cbaf8, %eax");
    asm("jmp *%eax");
}

unsigned char CNWRules::GetSkillExpansionLevel(unsigned short)
{
    asm("leave");
    asm("mov $0x080cb91c, %eax");
    asm("jmp *%eax");
}

int CNWRules::GetSkill(unsigned short)
{
    asm("leave");
    asm("mov $0x080cbb24, %eax");
    asm("jmp *%eax");
}

int CNWRules::GetSortedFeatID(unsigned short)
{
    asm("leave");
    asm("mov $0x080cbb60, %eax");
    asm("jmp *%eax");
}

unsigned char CNWRules::GetSpellExpansionLevel(unsigned long)
{
    asm("leave");
    asm("mov $0x080cb944, %eax");
    asm("jmp *%eax");
}

int CNWRules::GetSpellRange(int)
{
    asm("leave");
    asm("mov $0x080cbb98, %eax");
    asm("jmp *%eax");
}

int CNWRules::GetSpell(unsigned long)
{
    asm("leave");
    asm("mov $0x080cba88, %eax");
    asm("jmp *%eax");
}

int CNWRules::GetWeightedDamageAmount(int, int, int, int, int)
{
    asm("leave");
    asm("mov $0x080cb7a4, %eax");
    asm("jmp *%eax");
}

int CNWRules::IsArcaneClass(unsigned char)
{
    asm("leave");
    asm("mov $0x080cba08, %eax");
    asm("jmp *%eax");
}

int CNWRules::IsFeatUseable(unsigned char, unsigned short)
{
    asm("leave");
    asm("mov $0x080cb600, %eax");
    asm("jmp *%eax");
}

void CNWRules::LoadClassInfo()
{
    asm("leave");
    asm("mov $0x080c8918, %eax");
    asm("jmp *%eax");
}

void CNWRules::LoadDifficultyInfo()
{
    asm("leave");
    asm("mov $0x080cb440, %eax");
    asm("jmp *%eax");
}

void CNWRules::LoadDomainInfo()
{
    asm("leave");
    asm("mov $0x080caef0, %eax");
    asm("jmp *%eax");
}

void CNWRules::LoadFeatInfo()
{
    asm("leave");
    asm("mov $0x080c6dd8, %eax");
    asm("jmp *%eax");
}

void CNWRules::LoadRaceInfo()
{
    asm("leave");
    asm("mov $0x080c9d58, %eax");
    asm("jmp *%eax");
}

void CNWRules::LoadSkillInfo()
{
    asm("leave");
    asm("mov $0x080ca75c, %eax");
    asm("jmp *%eax");
}

void CNWRules::ReloadAll()
{
    asm("leave");
    asm("mov $0x080c6aa0, %eax");
    asm("jmp *%eax");
}

unsigned short CNWRules::RollDice(unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x080cb6b0, %eax");
    asm("jmp *%eax");
}

int CNWRules::SortFeats()
{
    asm("leave");
    asm("mov $0x080cb688, %eax");
    asm("jmp *%eax");
}

void CNWRules::UnloadAll()
{
    asm("leave");
    asm("mov $0x080c680c, %eax");
    asm("jmp *%eax");
}

