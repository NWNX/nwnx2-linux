#include "flex_unit.h"

int flex_unit::clear()
{
	asm("leave");
	asm("mov $0x0829d164, %eax");
	asm("jmp %eax");
}

int flex_unit::fast_mul(flex_unit &, flex_unit &, unsigned int)
{
	asm("leave");
	asm("mov $0x0829b4e8, %eax");
	asm("jmp %eax");
}

int flex_unit::get(unsigned int) const
{
	asm("leave");
	asm("mov $0x0829d148, %eax");
	asm("jmp %eax");
}

int flex_unit::reserve(unsigned int)
{
	asm("leave");
	asm("mov $0x0829d1e0, %eax");
	asm("jmp %eax");
}

int flex_unit::set(unsigned int, unsigned int)
{
	asm("leave");
	asm("mov $0x0829b400, %eax");
	asm("jmp %eax");
}

int flex_unit::shiftLeft32()
{
	asm("leave");
	asm("mov $0x0829d240, %eax");
	asm("jmp %eax");
}

int flex_unit::shiftRight32()
{
	asm("leave");
	asm("mov $0x0829d2bc, %eax");
	asm("jmp %eax");
}

