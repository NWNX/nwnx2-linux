#include "CExoTimersInternal.h"

unsigned __int64 CExoTimersInternal::GetHighResolutionTimer()
{
    asm("leave");
    asm("mov $0x082d1d50, %eax");
    asm("jmp *%eax");
}

unsigned long CExoTimersInternal::GetLowResolutionTimer()
{
    asm("leave");
    asm("mov $0x082d1d44, %eax");
    asm("jmp *%eax");
}

