#include "CNWClass.h"

unsigned char CNWClass::GetAttackBonus(unsigned char)
{
    asm("leave");
    asm("mov $0x080bf260, %eax");
    asm("jmp *%eax");
}

unsigned char CNWClass::GetBonusFeats(unsigned char)
{
    asm("leave");
    asm("mov $0x080bf280, %eax");
    asm("jmp *%eax");
}

int CNWClass::GetClassFeat(unsigned short)
{
    asm("leave");
    asm("mov $0x080bf4b0, %eax");
    asm("jmp *%eax");
}

int CNWClass::GetDescriptionText()
{
    asm("leave");
    asm("mov $0x080bee98, %eax");
    asm("jmp *%eax");
}

unsigned char CNWClass::GetFortSaveBonus(unsigned char)
{
    asm("leave");
    asm("mov $0x080bf2a4, %eax");
    asm("jmp *%eax");
}

int CNWClass::GetIsAlignmentAllowed(unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x080bf164, %eax");
    asm("jmp *%eax");
}

int CNWClass::GetLevelFeatGranted(unsigned short)
{
    asm("leave");
    asm("mov $0x080bf4d4, %eax");
    asm("jmp *%eax");
}

int CNWClass::GetLevelGranted(unsigned short)
{
    asm("leave");
    asm("mov $0x080bf640, %eax");
    asm("jmp *%eax");
}

int CNWClass::GetNameLowerText()
{
    asm("leave");
    asm("mov $0x080beffc, %eax");
    asm("jmp *%eax");
}

int CNWClass::GetNamePluralText()
{
    asm("leave");
    asm("mov $0x080bf0b0, %eax");
    asm("jmp *%eax");
}

int CNWClass::GetNameText()
{
    asm("leave");
    asm("mov $0x080bef4c, %eax");
    asm("jmp *%eax");
}

unsigned char CNWClass::GetRefSaveBonus(unsigned char)
{
    asm("leave");
    asm("mov $0x080bf2c4, %eax");
    asm("jmp *%eax");
}

unsigned char CNWClass::GetSpellGain(unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x080bf30c, %eax");
    asm("jmp *%eax");
}

unsigned char CNWClass::GetSpellsKnownPerLevel(unsigned char, unsigned char, unsigned char, unsigned short, unsigned char)
{
    asm("leave");
    asm("mov $0x080bf344, %eax");
    asm("jmp *%eax");
}

unsigned char CNWClass::GetWillSaveBonus(unsigned char)
{
    asm("leave");
    asm("mov $0x080bf2e8, %eax");
    asm("jmp *%eax");
}

int CNWClass::IsBonusFeat(unsigned short)
{
    asm("leave");
    asm("mov $0x080bf524, %eax");
    asm("jmp *%eax");
}

int CNWClass::IsFeatUseable(unsigned short)
{
    asm("leave");
    asm("mov $0x080bf688, %eax");
    asm("jmp *%eax");
}

int CNWClass::IsGrantedFeat(unsigned short, unsigned char &)
{
    asm("leave");
    asm("mov $0x080bf5e0, %eax");
    asm("jmp *%eax");
}

int CNWClass::IsNormalFeat(unsigned short)
{
    asm("leave");
    asm("mov $0x080bf570, %eax");
    asm("jmp *%eax");
}

int CNWClass::IsSkillClassSkill(unsigned short)
{
    asm("leave");
    asm("mov $0x080bf3e4, %eax");
    asm("jmp *%eax");
}

int CNWClass::IsSkillUseable(unsigned short)
{
    asm("leave");
    asm("mov $0x080bf440, %eax");
    asm("jmp *%eax");
}

void CNWClass::LoadAttackBonusTable(CExoString)
{
    asm("leave");
    asm("mov $0x080bd504, %eax");
    asm("jmp *%eax");
}

void CNWClass::LoadBonusFeatsTable(CExoString)
{
    asm("leave");
    asm("mov $0x080be4c0, %eax");
    asm("jmp *%eax");
}

void CNWClass::LoadFeatsTable(CExoString, CNWRules *)
{
    asm("leave");
    asm("mov $0x080bd7ec, %eax");
    asm("jmp *%eax");
}

void CNWClass::LoadSavingThrowTable(CExoString)
{
    asm("leave");
    asm("mov $0x080bddec, %eax");
    asm("jmp *%eax");
}

void CNWClass::LoadSkillsTable(CExoString)
{
    asm("leave");
    asm("mov $0x080be158, %eax");
    asm("jmp *%eax");
}

void CNWClass::LoadSpellGainTable(CExoString)
{
    asm("leave");
    asm("mov $0x080be73c, %eax");
    asm("jmp *%eax");
}

void CNWClass::LoadSpellKnownTable(CExoString)
{
    asm("leave");
    asm("mov $0x080beb1c, %eax");
    asm("jmp *%eax");
}

