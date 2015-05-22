#include "CNWSPlayerStoreGUI.h"

void CNWSPlayerStoreGUI::CloseStore(CNWSPlayer *, int)
{
    asm("leave");
    asm("mov $0x08052f60, %eax");
    asm("jmp *%eax");
}

void CNWSPlayerStoreGUI::OpenStore(CNWSPlayer *, unsigned long, char, char)
{
    asm("leave");
    asm("mov $0x08052de4, %eax");
    asm("jmp *%eax");
}

