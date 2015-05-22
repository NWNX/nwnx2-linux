#include "MS_RSAVLong_value.h"

void MS_RSAVLong_value::add(MS_RSAVLong_value &)
{
    asm("leave");
    asm("mov $0x0829b7a8, %eax");
    asm("jmp *%eax");
}

unsigned int MS_RSAVLong_value::bits() const
{
    asm("leave");
    asm("mov $0x0829d358, %eax");
    asm("jmp *%eax");
}

int MS_RSAVLong_value::cf(MS_RSAVLong_value &) const
{
    asm("leave");
    asm("mov $0x0829b714, %eax");
    asm("jmp *%eax");
}

void MS_RSAVLong_value::copy(MS_RSAVLong_value &)
{
    asm("leave");
    asm("mov $0x0829d564, %eax");
    asm("jmp *%eax");
}

void MS_RSAVLong_value::divide(MS_RSAVLong_value &, MS_RSAVLong_value &, MS_RSAVLong_value &)
{
    asm("leave");
    asm("mov $0x0829b914, %eax");
    asm("jmp *%eax");
}

void MS_RSAVLong_value::init(unsigned int)
{
    asm("leave");
    asm("mov $0x0829d540, %eax");
    asm("jmp *%eax");
}

int MS_RSAVLong_value::is_zero() const
{
    asm("leave");
    asm("mov $0x0829d310, %eax");
    asm("jmp *%eax");
}

void MS_RSAVLong_value::mul(MS_RSAVLong_value &, MS_RSAVLong_value &)
{
    asm("leave");
    asm("mov $0x0829b874, %eax");
    asm("jmp *%eax");
}

void MS_RSAVLong_value::shl()
{
    asm("leave");
    asm("mov $0x0829d3a4, %eax");
    asm("jmp *%eax");
}

void MS_RSAVLong_value::shr()
{
    asm("leave");
    asm("mov $0x0829d3f0, %eax");
    asm("jmp *%eax");
}

void MS_RSAVLong_value::shr(unsigned int)
{
    asm("leave");
    asm("mov $0x0829d440, %eax");
    asm("jmp *%eax");
}

void MS_RSAVLong_value::subtract(MS_RSAVLong_value &)
{
    asm("leave");
    asm("mov $0x0829d4d0, %eax");
    asm("jmp *%eax");
}

int MS_RSAVLong_value::test(unsigned int) const
{
    asm("leave");
    asm("mov $0x0829d324, %eax");
    asm("jmp *%eax");
}

