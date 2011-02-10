#include "CExoTimersInternal.h"

int CExoTimersInternal::GetHighResolutionTimer()
{
	asm("leave");
	asm("mov $0x082d1d50, %eax");
	asm("jmp *%eax");
}

int CExoTimersInternal::GetLowResolutionTimer()
{
	asm("leave");
	asm("mov $0x082d1d44, %eax");
	asm("jmp *%eax");
}

