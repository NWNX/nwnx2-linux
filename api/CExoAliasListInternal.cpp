#include "CExoAliasListInternal.h"

void CExoAliasListInternal::Add(CExoString, CExoString)
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

void CExoAliasListInternal::Delete(CExoString)
{
    asm("leave");
    asm("mov $0x082d00f0, %eax");
    asm("jmp *%eax");
}

CExoString const & CExoAliasListInternal::GetAliasPath(CExoString const &, int) const
{
    asm("leave");
    asm("mov $0x082d07f0, %eax");
    asm("jmp *%eax");
}

CExoString CExoAliasListInternal::ResolveFileName(CExoString const &, unsigned short) const
{
    asm("leave");
    asm("mov $0x082d0260, %eax");
    asm("jmp *%eax");
}

