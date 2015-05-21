#include "CLoopingVisualEffect.h"

int CLoopingVisualEffect::GetIsBeam()
{
    asm("leave");
    asm("mov $0x081c8800, %eax");
    asm("jmp *%eax");
}

