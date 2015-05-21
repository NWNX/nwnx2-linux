#include "CNWSkill.h"

int CNWSkill::GetDescriptionText()
{
    asm("leave");
    asm("mov $0x081b2bf0, %eax");
    asm("jmp *%eax");
}

int CNWSkill::GetNameText()
{
    asm("leave");
    asm("mov $0x081b2ca4, %eax");
    asm("jmp *%eax");
}

