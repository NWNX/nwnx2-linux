#include "CMemRecord.h"

int CMemRecord::Clear()
{
    asm("leave");
    asm("mov $0x082ae60c, %eax");
    asm("jmp *%eax");
}

