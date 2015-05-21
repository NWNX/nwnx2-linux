#include "Plane.h"

int Plane::Transform(Vector const &, Quaternion const &)
{
    asm("leave");
    asm("mov $0x0826c164, %eax");
    asm("jmp *%eax");
}

