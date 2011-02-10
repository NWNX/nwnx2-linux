#include "CNWSDungeonMaster.h"

int CNWSDungeonMaster::AsNWSDungeonMaster()
{
	asm("leave");
	asm("mov $0x08166394, %eax");
	asm("jmp *%eax");
}

int CNWSDungeonMaster::PossessCreature(unsigned long, unsigned char)
{
	asm("leave");
	asm("mov $0x08165d24, %eax");
	asm("jmp *%eax");
}

