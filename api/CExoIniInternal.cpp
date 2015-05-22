#include "CExoIniInternal.h"

int CExoIniInternal::ReadIniEntry(CExoString &, CExoString const &, CExoString const &, CExoString const &)
{
    asm("leave");
    asm("mov $0x082d0b74, %eax");
    asm("jmp *%eax");
}

int CExoIniInternal::WriteIniEntry(CExoString const &, CExoString const &, CExoString const &, CExoString const &)
{
    asm("leave");
    asm("mov $0x082d0be4, %eax");
    asm("jmp *%eax");
}

