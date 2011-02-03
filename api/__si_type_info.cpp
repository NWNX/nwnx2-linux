#include "__si_type_info.h"

int __si_type_info::do_find_public_subobj(int, type_info const &, void *, void *) const
{
	asm("leave");
	asm("mov $0x0830bf50, %eax");
	asm("jmp %eax");
}

