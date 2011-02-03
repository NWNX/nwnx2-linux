#include "CNWCreatureStatsUpdate.h"

int CNWCreatureStatsUpdate::ClearEffectIcons()
{
	asm("leave");
	asm("mov $0x08094764, %eax");
	asm("jmp %eax");
}

int CNWCreatureStatsUpdate::SetCombatInformation(CCombatInformation *)
{
	asm("leave");
	asm("mov $0x080947c8, %eax");
	asm("jmp %eax");
}

