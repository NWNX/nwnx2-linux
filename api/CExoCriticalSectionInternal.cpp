#include "CExoCriticalSectionInternal.h"

int CExoCriticalSectionInternal::EnterCriticalSection()
{
	asm("leave");
	asm("mov $0x082ceca4, %eax");
	asm("jmp *%eax");
}

int CExoCriticalSectionInternal::LeaveCriticalSection()
{
	asm("leave");
	asm("mov $0x082cecb8, %eax");
	asm("jmp *%eax");
}

