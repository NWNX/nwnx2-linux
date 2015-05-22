#include "CNWBaseItem.h"

CResRef CNWBaseItem::GetIconResRef(unsigned char, short, char)
{
    asm("leave");
    asm("mov $0x080c1814, %eax");
    asm("jmp *%eax");
}

CResRef CNWBaseItem::GetModelResRef(unsigned char, short, char)
{
    asm("leave");
    asm("mov $0x080c1954, %eax");
    asm("jmp *%eax");
}

int CNWBaseItem::GetNameText()
{
    asm("leave");
    asm("mov $0x080bfb34, %eax");
    asm("jmp *%eax");
}

unsigned short CNWBaseItem::GetRequiredFeat(unsigned char)
{
    asm("leave");
    asm("mov $0x080c192c, %eax");
    asm("jmp *%eax");
}

int CNWBaseItem::SetRequiredFeatCount(unsigned char)
{
    asm("leave");
    asm("mov $0x080c18a8, %eax");
    asm("jmp *%eax");
}

int CNWBaseItem::SetRequiredFeat(unsigned char, unsigned short)
{
    asm("leave");
    asm("mov $0x080c1904, %eax");
    asm("jmp *%eax");
}

