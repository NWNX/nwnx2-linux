#include "CNWFeat.h"

int CNWFeat::GetDescriptionText()
{
    asm("leave");
    asm("mov $0x08238ec4, %eax");
    asm("jmp *%eax");
}

CExoString CNWFeat::GetNameText()
{
    asm("leave");
    asm("mov $0x08238f78, %eax");
    asm("jmp *%eax");
}

