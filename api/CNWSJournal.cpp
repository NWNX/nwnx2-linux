#include "CNWSJournal.h"

int CNWSJournal::Destroy(CExoString)
{
	asm("leave");
	asm("mov $0x081b22f4, %eax");
	asm("jmp %eax");
}

int CNWSJournal::SetDate(CExoString, unsigned long, int)
{
	asm("leave");
	asm("mov $0x081b1ab8, %eax");
	asm("jmp %eax");
}

int CNWSJournal::SetPicture(CExoString, int, int)
{
	asm("leave");
	asm("mov $0x081b22c8, %eax");
	asm("jmp %eax");
}

int CNWSJournal::SetState(CExoString, unsigned long, int)
{
	asm("leave");
	asm("mov $0x081b0c54, %eax");
	asm("jmp %eax");
}

int CNWSJournal::SetTime(CExoString, unsigned long, int)
{
	asm("leave");
	asm("mov $0x081b1ec0, %eax");
	asm("jmp %eax");
}

