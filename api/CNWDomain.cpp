#include "CNWDomain.h"

int CNWDomain::GetDescriptionText()
{
    asm("leave");
    asm("mov $0x08236db8, %eax");
    asm("jmp *%eax");
}

int CNWDomain::GetNameText()
{
    asm("leave");
    asm("mov $0x08236e6c, %eax");
    asm("jmp *%eax");
}

