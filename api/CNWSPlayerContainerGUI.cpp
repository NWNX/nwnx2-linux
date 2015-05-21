#include "CNWSPlayerContainerGUI.h"

void CNWSPlayerContainerGUI::SetNextPage(CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x0805385c, %eax");
    asm("jmp *%eax");
}

void CNWSPlayerContainerGUI::SetOpen(CNWSPlayer *, unsigned long, int)
{
    asm("leave");
    asm("mov $0x08053928, %eax");
    asm("jmp *%eax");
}

void CNWSPlayerContainerGUI::SetPreviousPage(CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x080538c8, %eax");
    asm("jmp *%eax");
}

