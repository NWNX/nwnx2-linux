#include "CNWSPlayerInventoryGUI.h"

void CNWSPlayerInventoryGUI::SetOpen(int)
{
    asm("leave");
    asm("mov $0x08053804, %eax");
    asm("jmp *%eax");
}

void CNWSPlayerInventoryGUI::SetOwner(unsigned long)
{
    asm("leave");
    asm("mov $0x0805e5b8, %eax");
    asm("jmp *%eax");
}

void CNWSPlayerInventoryGUI::SetPanel(CNWSPlayer *, unsigned char)
{
    asm("leave");
    asm("mov $0x0805e62c, %eax");
    asm("jmp *%eax");
}

