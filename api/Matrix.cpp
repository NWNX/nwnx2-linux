#include "Matrix.h"

int Matrix::getquaternion() const
{
    asm("leave");
    asm("mov $0x0826bed0, %eax");
    asm("jmp *%eax");
}

