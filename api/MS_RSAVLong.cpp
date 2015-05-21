#include "MS_RSAVLong.h"

MS_RSAVLong & MS_RSAVLong::operator-=(MS_RSAVLong const &)
{
    asm("leave");
    asm("mov $0x0829bf4c, %eax");
    asm("jmp *%eax");
}

MS_RSAVLong & MS_RSAVLong::operator+=(MS_RSAVLong const &)
{
    asm("leave");
    asm("mov $0x0829be24, %eax");
    asm("jmp *%eax");
}

MS_RSAVLong & MS_RSAVLong::operator=(MS_RSAVLong const &)
{
    asm("leave");
    asm("mov $0x0829bd38, %eax");
    asm("jmp *%eax");
}

int MS_RSAVLong::cf(MS_RSAVLong const &) const
{
    asm("leave");
    asm("mov $0x0829d5d4, %eax");
    asm("jmp *%eax");
}

void MS_RSAVLong::docopy()
{
    asm("leave");
    asm("mov $0x0829bc64, %eax");
    asm("jmp *%eax");
}

int MS_RSAVLong::is_negative() const
{
    asm("leave");
    asm("mov $0x0829d7d8, %eax");
    asm("jmp *%eax");
}

int MS_RSAVLong::is_zero() const
{
    asm("leave");
    asm("mov $0x0829d7c4, %eax");
    asm("jmp *%eax");
}

void MS_RSAVLong::shiftLeft32()
{
    asm("leave");
    asm("mov $0x0829d7e4, %eax");
    asm("jmp *%eax");
}

void MS_RSAVLong::shiftRight32()
{
    asm("leave");
    asm("mov $0x0829d860, %eax");
    asm("jmp *%eax");
}

