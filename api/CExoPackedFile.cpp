#include "CExoPackedFile.h"

int CExoPackedFile::GetAsyncFile()
{
	asm("leave");
	asm("mov $0x082c46cc, %eax");
	asm("jmp *%eax");
}

int CExoPackedFile::GetFile()
{
	asm("leave");
	asm("mov $0x082c46c0, %eax");
	asm("jmp *%eax");
}

