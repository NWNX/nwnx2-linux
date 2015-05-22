#include "CExoCriticalSection.h"

void CExoCriticalSection::EnterCriticalSection()
{
    asm("leave");
    asm("mov $0x082c8f38, %eax");
    asm("jmp *%eax");
}

void CExoCriticalSection::LeaveCriticalSection()
{
    asm("leave");
    asm("mov $0x082c8f4c, %eax");
    asm("jmp *%eax");
}

