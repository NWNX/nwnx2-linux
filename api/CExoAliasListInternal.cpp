#include "CExoAliasListInternal.h"

int CExoAliasListInternal::Add(CExoString, CExoString)
{
	asm("leave");
	asm("mov $0x082cfe54, %eax");
	asm("jmp *%eax");
}

int CExoAliasListInternal::Clear()
{
	asm("leave");
	asm("mov $0x082d079c, %eax");
	asm("jmp *%eax");
}

int CExoAliasListInternal::Delete(CExoString)
{
	asm("leave");
	asm("mov $0x082d00f0, %eax");
	asm("jmp *%eax");
}

int CExoAliasListInternal::GetAliasPath(CExoString const &, int) const
{
	asm("leave");
	asm("mov $0x082d07f0, %eax");
	asm("jmp *%eax");
}

int CExoAliasListInternal::ResolveFileName(CExoString const &, unsigned short) const
{
	asm("leave");
	asm("mov $0x082d0260, %eax");
	asm("jmp *%eax");
}

