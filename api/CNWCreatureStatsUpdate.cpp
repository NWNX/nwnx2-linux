#include "CNWCreatureStatsUpdate.h"

void CNWCreatureStatsUpdate::ClearEffectIcons()
{
    asm("leave");
    asm("mov $0x08094764, %eax");
    asm("jmp *%eax");
}

void CNWCreatureStatsUpdate::SetCombatInformation(CCombatInformation *)
{
    asm("leave");
    asm("mov $0x080947c8, %eax");
    asm("jmp *%eax");
}

