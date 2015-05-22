#include "Vector.h"

void Vector::Normalize()
{
    asm("leave");
    asm("mov $0x0826b0d0, %eax");
    asm("jmp *%eax");
}

Vector & Vector::operator-=(Vector const &)
{
    asm("leave");
    asm("mov $0x0826fb1c, %eax");
    asm("jmp *%eax");
}

Vector & Vector::operator+=(Vector const &)
{
    asm("leave");
    asm("mov $0x0826faf8, %eax");
    asm("jmp *%eax");
}

