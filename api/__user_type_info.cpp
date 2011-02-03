#include "__user_type_info.h"

int __user_type_info::do_find_public_subobj(int, type_info const &, void *, void *) const
{
	asm("leave");
	asm("mov $0x0830bdf0, %eax");
	asm("jmp %eax");
}

int __user_type_info::dyncast(int, type_info const &, void *, type_info const &, void *) const
{
	asm("leave");
	asm("mov $0x0830bc50, %eax");
	asm("jmp %eax");
}

int __user_type_info::find_public_subobj(int, type_info const &, void *, void *) const
{
	asm("leave");
	asm("mov $0x0830c9a0, %eax");
	asm("jmp %eax");
}

int __user_type_info::upcast(type_info const &, void *, void **) const
{
	asm("leave");
	asm("mov $0x0830bbf0, %eax");
	asm("jmp %eax");
}

