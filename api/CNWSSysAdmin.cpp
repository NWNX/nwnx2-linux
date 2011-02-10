#include "CNWSSysAdmin.h"

int CNWSSysAdmin::AsNWSSysAdmin()
{
	asm("leave");
	asm("mov $0x081ed0b4, %eax");
	asm("jmp *%eax");
}

