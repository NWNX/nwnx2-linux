#include "bad_alloc.h"

int bad_alloc::what() const
{
	asm("leave");
	asm("mov $0x0830e7a0, %eax");
	asm("jmp %eax");
}

