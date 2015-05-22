#include "CExoTimers.h"

unsigned __int64 CExoTimers::GetHighResolutionTimer()
{
    asm("leave");
    asm("mov $0x082cc7a8, %eax");
    asm("jmp *%eax");
}

unsigned long CExoTimers::GetLowResolutionTimer()
{
    asm("leave");
    asm("mov $0x082cc794, %eax");
    asm("jmp *%eax");
}

