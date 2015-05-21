#include "CExoAliasList.h"

void CExoAliasList::Add(CExoString, CExoString)
{
    asm("leave");
    asm("mov $0x082c9364, %eax");
    asm("jmp *%eax");
}

int CExoAliasList::Clear()
{
    asm("leave");
    asm("mov $0x082c940c, %eax");
    asm("jmp *%eax");
}

void CExoAliasList::Delete(CExoString)
{
    asm("leave");
    asm("mov $0x082c9420, %eax");
    asm("jmp *%eax");
}

CExoString const & CExoAliasList::GetAliasPath(CExoString const &, int) const
{
    asm("leave");
    asm("mov $0x082c9484, %eax");
    asm("jmp *%eax");
}

CExoString CExoAliasList::ResolveFileName(CExoString const &, unsigned short) const
{
    asm("leave");
    asm("mov $0x082c9498, %eax");
    asm("jmp *%eax");
}

