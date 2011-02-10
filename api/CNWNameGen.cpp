#include "CNWNameGen.h"

int CNWNameGen::GetRandomName()
{
	asm("leave");
	asm("mov $0x08270380, %eax");
	asm("jmp *%eax");
}

int CNWNameGen::GetRandomName(unsigned short, unsigned char)
{
	asm("leave");
	asm("mov $0x08270b0c, %eax");
	asm("jmp *%eax");
}

int CNWNameGen::LoadNameTable(CExoString)
{
	asm("leave");
	asm("mov $0x08271030, %eax");
	asm("jmp *%eax");
}

int CNWNameGen::UnloadNameTable()
{
	asm("leave");
	asm("mov $0x082710d4, %eax");
	asm("jmp *%eax");
}

