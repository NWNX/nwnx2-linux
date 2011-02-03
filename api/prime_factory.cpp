#include "prime_factory.h"

int prime_factory::find_prime(MS_RSAVLong const &, MS_RSAVLong const &)
{
	asm("leave");
	asm("mov $0x08299578, %eax");
	asm("jmp %eax");
}

