#include "CNWSCreatureStats_ClassInfo.h"

int CNWSCreatureStats_ClassInfo::AddKnownSpell(unsigned char, unsigned long)
{
    asm("leave");
    asm("mov $0x08163738, %eax");
    asm("jmp *%eax");
}

void CNWSCreatureStats_ClassInfo::ClearMemorizedKnownSpells(unsigned long)
{
    asm("leave");
    asm("mov $0x0813f528, %eax");
    asm("jmp *%eax");
}

void CNWSCreatureStats_ClassInfo::ClearMemorizedSpellSlot(unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x0813f4b4, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats_ClassInfo::ConfirmDomainSpell(unsigned char, unsigned long)
{
    asm("leave");
    asm("mov $0x0813fb10, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats_ClassInfo::DecrementSpellsPerDayLeft(unsigned char)
{
    asm("leave");
    asm("mov $0x08163ae4, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats_ClassInfo::GetIsDomainSpell(unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x0816382c, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreatureStats_ClassInfo::GetKnownSpell(unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x08163790, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats_ClassInfo::GetMaxSpellsPerDayLeft(unsigned char)
{
    asm("leave");
    asm("mov $0x08163aa8, %eax");
    asm("jmp *%eax");
}

CNWSStats_Spell * CNWSCreatureStats_ClassInfo::GetMemorizedSpellInSlotDetails(unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x08163884, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSCreatureStats_ClassInfo::GetMemorizedSpellInSlotMetaType(unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x08163a14, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats_ClassInfo::GetMemorizedSpellInSlotReady(unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x081638d8, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreatureStats_ClassInfo::GetMemorizedSpellInSlot(unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x081637d0, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSCreatureStats_ClassInfo::GetMemorizedSpellReadyCount(unsigned long, unsigned char *, unsigned char *, unsigned char)
{
    asm("leave");
    asm("mov $0x0813f738, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats_ClassInfo::GetMemorizedSpellReadyCount(unsigned long, unsigned char)
{
    asm("leave");
    asm("mov $0x0816399c, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats_ClassInfo::GetNumberBonusSpells(unsigned char)
{
    asm("leave");
    asm("mov $0x08163b94, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats_ClassInfo::GetNumberKnownSpells(unsigned char)
{
    asm("leave");
    asm("mov $0x08163b5c, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSCreatureStats_ClassInfo::GetNumberMemorizedSpellSlots(unsigned char)
{
    asm("leave");
    asm("mov $0x08163b74, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats_ClassInfo::GetSpellsPerDayLeft(unsigned char)
{
    asm("leave");
    asm("mov $0x08163a6c, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats_ClassInfo::IncrementSpellsPerDayLeft(unsigned char)
{
    asm("leave");
    asm("mov $0x08163b00, %eax");
    asm("jmp *%eax");
}

void CNWSCreatureStats_ClassInfo::RemoveKnownSpell(unsigned char, unsigned long)
{
    asm("leave");
    asm("mov $0x08163764, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats_ClassInfo::ResetSpellsPerDayLeft(unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x08163b1c, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats_ClassInfo::SetMaxSpellsPerDayLeft(unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x08163ac8, %eax");
    asm("jmp *%eax");
}

void CNWSCreatureStats_ClassInfo::SetMemorizedSpellInSlotReady(unsigned char, unsigned char, int)
{
    asm("leave");
    asm("mov $0x08163930, %eax");
    asm("jmp *%eax");
}

void CNWSCreatureStats_ClassInfo::SetMemorizedSpellSlot(unsigned char, unsigned char, unsigned long, int, unsigned char)
{
    asm("leave");
    asm("mov $0x0813f3d4, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats_ClassInfo::SetNumberBonusSpells(unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x08163bb4, %eax");
    asm("jmp *%eax");
}

void CNWSCreatureStats_ClassInfo::SetNumberMemorizedSpellSlots(unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x0813f688, %eax");
    asm("jmp *%eax");
}

int CNWSCreatureStats_ClassInfo::SetSpellsPerDayLeft(unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x08163a8c, %eax");
    asm("jmp *%eax");
}

