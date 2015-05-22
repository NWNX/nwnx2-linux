#include "CNWSpell.h"

int CNWSpell::GetSpellHasSomaticComponent()
{
    asm("leave");
    asm("mov $0x081db788, %eax");
    asm("jmp *%eax");
}

int CNWSpell::GetSpellHasVerbalComponent()
{
    asm("leave");
    asm("mov $0x081db70c, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSpell::GetSpellLevel(unsigned char)
{
    asm("leave");
    asm("mov $0x081d8920, %eax");
    asm("jmp *%eax");
}

int CNWSpell::GetSpellNameText()
{
    asm("leave");
    asm("mov $0x081d897c, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSpell::GetSubRadialSpell(unsigned char)
{
    asm("leave");
    asm("mov $0x081db804, %eax");
    asm("jmp *%eax");
}

int CNWSpell::SetSubRadialSpellCount(unsigned char)
{
    asm("leave");
    asm("mov $0x081db850, %eax");
    asm("jmp *%eax");
}

int CNWSpell::SetSubRadialSpell(unsigned char, unsigned long)
{
    asm("leave");
    asm("mov $0x081db82c, %eax");
    asm("jmp *%eax");
}

