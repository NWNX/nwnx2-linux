#include "monty.h"

int monty::exp(MS_RSAVLong const &, MS_RSAVLong const &)
{
	asm("leave");
	asm("mov $0x0829cd68, %eax");
	asm("jmp %eax");
}

int monty::mul(MS_RSAVLong &, MS_RSAVLong const &)
{
	asm("leave");
	asm("mov $0x0829cc0c, %eax");
	asm("jmp %eax");
}

