#include "CResGFFFieldIDHash.h"

int CResGFFFieldIDHash::Hash(char const *, unsigned long)
{
	asm("leave");
	asm("mov $0x082c5270, %eax");
	asm("jmp *%eax");
}

int CResGFFFieldIDHash::Initialize()
{
	asm("leave");
	asm("mov $0x082c5234, %eax");
	asm("jmp *%eax");
}

