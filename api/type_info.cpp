#include "type_info.h"

int type_info::operator==(type_info const &) const
{
	asm("leave");
	asm("mov $0x0830bac0, %eax");
	asm("jmp %eax");
}

int type_info::operator!=(type_info const &) const
{
	asm("leave");
	asm("mov $0x0830c6a0, %eax");
	asm("jmp %eax");
}

int type_info::before(type_info const &) const
{
	asm("leave");
	asm("mov $0x0830d634, %eax");
	asm("jmp %eax");
}

int type_info::name() const
{
	asm("leave");
	asm("mov $0x0830c690, %eax");
	asm("jmp %eax");
}

