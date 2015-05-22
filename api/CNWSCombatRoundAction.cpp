#include "CNWSCombatRoundAction.h"

int CNWSCombatRoundAction::LoadData(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x080e00a8, %eax");
    asm("jmp *%eax");
}

int CNWSCombatRoundAction::SaveData(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x080e4ac8, %eax");
    asm("jmp *%eax");
}

