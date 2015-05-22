#include "CNWSForcedAction.h"

int CNWSForcedAction::LoadForcedAction(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x0818473c, %eax");
    asm("jmp *%eax");
}

int CNWSForcedAction::SaveForcedAction(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x081846a4, %eax");
    asm("jmp *%eax");
}

