#include "CNWItem.h"

int CNWItem::GetBaseItemID()
{
    asm("leave");
    asm("mov $0x080c1b1c, %eax");
    asm("jmp *%eax");
}

int CNWItem::GetLayeredTextureColor(unsigned char)
{
    asm("leave");
    asm("mov $0x080c1b28, %eax");
    asm("jmp *%eax");
}

int CNWItem::SetBaseItemID(unsigned long)
{
    asm("leave");
    asm("mov $0x080c1b44, %eax");
    asm("jmp *%eax");
}

int CNWItem::SetLayeredTextureColor(unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x080c1b54, %eax");
    asm("jmp *%eax");
}

