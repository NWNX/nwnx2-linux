#include "CNWLevelStats.h"

void CNWLevelStats::AddFeat(unsigned short)
{
    asm("leave");
    asm("mov $0x080bfa84, %eax");
    asm("jmp *%eax");
}

int CNWLevelStats::ClearFeats()
{
    asm("leave");
    asm("mov $0x080bfa14, %eax");
    asm("jmp *%eax");
}

char CNWLevelStats::GetSkillRankChange(unsigned short)
{
    asm("leave");
    asm("mov $0x080bfa30, %eax");
    asm("jmp *%eax");
}

void CNWLevelStats::SetSkillRankChange(unsigned short, char)
{
    asm("leave");
    asm("mov $0x080bfa5c, %eax");
    asm("jmp *%eax");
}

