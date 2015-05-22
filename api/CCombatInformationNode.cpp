#include "CCombatInformationNode.h"

int CCombatInformationNode::operator=(CCombatInformationNode const &)
{
    asm("leave");
    asm("mov $0x080cb5c8, %eax");
    asm("jmp *%eax");
}

int CCombatInformationNode::operator==(CCombatInformationNode &)
{
    asm("leave");
    asm("mov $0x080cb540, %eax");
    asm("jmp *%eax");
}

int CCombatInformationNode::operator!=(CCombatInformationNode &)
{
    asm("leave");
    asm("mov $0x080cb584, %eax");
    asm("jmp *%eax");
}

