#include "CExoRand.h"

int CExoRand::GetString(unsigned short)
{
	asm("leave");
	asm("mov $0x082ca278, %eax");
	asm("jmp %eax");
}

int CExoRand::Rand()
{
	asm("leave");
	asm("mov $0x082ca264, %eax");
	asm("jmp %eax");
}

int CExoRand::SignalEvent()
{
	asm("leave");
	asm("mov $0x082ca2a0, %eax");
	asm("jmp %eax");
}

int CExoRand::SignalEvent(unsigned long)
{
	asm("leave");
	asm("mov $0x082ca2b4, %eax");
	asm("jmp %eax");
}

