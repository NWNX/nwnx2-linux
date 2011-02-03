#include "CExoTimers.h"

int CExoTimers::GetHighResolutionTimer()
{
	asm("leave");
	asm("mov $0x082cc7a8, %eax");
	asm("jmp %eax");
}

int CExoTimers::GetLowResolutionTimer()
{
	asm("leave");
	asm("mov $0x082cc794, %eax");
	asm("jmp %eax");
}

