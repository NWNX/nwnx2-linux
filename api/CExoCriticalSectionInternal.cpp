#include "CExoCriticalSectionInternal.h"

void CExoCriticalSectionInternal::EnterCriticalSection()
{
    asm("leave");
    asm("mov $0x082ceca4, %eax");
    asm("jmp *%eax");
}

void CExoCriticalSectionInternal::LeaveCriticalSection()
{
    asm("leave");
    asm("mov $0x082cecb8, %eax");
    asm("jmp *%eax");
}

