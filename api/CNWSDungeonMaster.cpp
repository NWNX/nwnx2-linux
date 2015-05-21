#include "CNWSDungeonMaster.h"

CNWSDungeonMaster * CNWSDungeonMaster::AsNWSDungeonMaster()
{
    asm("leave");
    asm("mov $0x08166394, %eax");
    asm("jmp *%eax");
}

void CNWSDungeonMaster::PossessCreature(unsigned long, unsigned char)
{
    asm("leave");
    asm("mov $0x08165d24, %eax");
    asm("jmp *%eax");
}

