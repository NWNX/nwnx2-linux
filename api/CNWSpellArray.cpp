#include "CNWSpellArray.h"

CNWSpell * CNWSpellArray::GetSpell(int) const
{
    asm("leave");
    asm("mov $0x081db8c4, %eax");
    asm("jmp *%eax");
}

void CNWSpellArray::Load()
{
    asm("leave");
    asm("mov $0x081d8af0, %eax");
    asm("jmp *%eax");
}

int CNWSpellArray::operator[](int) const
{
    asm("leave");
    asm("mov $0x081daf38, %eax");
    asm("jmp *%eax");
}

