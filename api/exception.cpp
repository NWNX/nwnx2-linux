#include "exception.h"

int exception::what() const
{
	asm("leave");
	asm("mov $0x0830d4a0, %eax");
	asm("jmp %eax");
}

