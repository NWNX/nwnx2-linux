#include "CERFRes.h"

int CERFRes::Read()
{
    asm("leave");
    asm("mov $0x082b7eac, %eax");
    asm("jmp *%eax");
}

int CERFRes::Reset()
{
    asm("leave");
    asm("mov $0x082b7e70, %eax");
    asm("jmp *%eax");
}

int CERFRes::Write(CExoFile &, unsigned long)
{
    asm("leave");
    asm("mov $0x082b7eb4, %eax");
    asm("jmp *%eax");
}

