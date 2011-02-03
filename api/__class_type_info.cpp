#include "__class_type_info.h"

int __class_type_info::do_find_public_subobj(int, type_info const &, void *, void *) const
{
	asm("leave");
	asm("mov $0x0830c530, %eax");
	asm("jmp %eax");
}

