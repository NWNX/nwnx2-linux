#include "CERFKey.h"

int CERFKey::Read()
{
    asm("leave");
    asm("mov $0x082b7dc4, %eax");
    asm("jmp *%eax");
}

int CERFKey::Reset()
{
    asm("leave");
    asm("mov $0x082b7d58, %eax");
    asm("jmp *%eax");
}

int CERFKey::SetName(CExoString &)
{
    asm("leave");
    asm("mov $0x082b7d80, %eax");
    asm("jmp *%eax");
}

int CERFKey::Write(CExoFile &)
{
    asm("leave");
    asm("mov $0x082b7dcc, %eax");
    asm("jmp *%eax");
}

