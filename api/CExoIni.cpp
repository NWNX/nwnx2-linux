#include "CExoIni.h"

int CExoIni::ReadIniEntry(CExoString &, CExoString const &, CExoString const &, CExoString const &)
{
    asm("leave");
    asm("mov $0x082c987c, %eax");
    asm("jmp *%eax");
}

int CExoIni::WriteIniEntry(CExoString const &, CExoString const &, CExoString const &, CExoString const &)
{
    asm("leave");
    asm("mov $0x082c9894, %eax");
    asm("jmp *%eax");
}

