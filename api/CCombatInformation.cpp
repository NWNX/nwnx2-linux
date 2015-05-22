#include "CCombatInformation.h"

int CCombatInformation::LoadData(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x080c55c4, %eax");
    asm("jmp *%eax");
}

int CCombatInformation::SaveData(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x080c50b0, %eax");
    asm("jmp *%eax");
}

CCombatInformation & CCombatInformation::operator=(CCombatInformation &)
{
    asm("leave");
    asm("mov $0x080c5fa4, %eax");
    asm("jmp *%eax");
}

int CCombatInformation::operator==(CCombatInformation &)
{
    asm("leave");
    asm("mov $0x080c5cf0, %eax");
    asm("jmp *%eax");
}

int CCombatInformation::operator!=(CCombatInformation &)
{
    asm("leave");
    asm("mov $0x080c5e10, %eax");
    asm("jmp *%eax");
}

