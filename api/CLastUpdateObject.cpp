#include "CLastUpdateObject.h"

int CLastUpdateObject::InitializeQuickbar()
{
	asm("leave");
	asm("mov $0x081e42a0, %eax");
	asm("jmp *%eax");
}

