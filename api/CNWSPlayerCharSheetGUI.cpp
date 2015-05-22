#include "CNWSPlayerCharSheetGUI.h"

unsigned long CNWSPlayerCharSheetGUI::ComputeCharacterSheetUpdateRequired(CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x08053054, %eax");
    asm("jmp *%eax");
}

void CNWSPlayerCharSheetGUI::SetCreatureDisplayed(unsigned long)
{
    asm("leave");
    asm("mov $0x0805e4f8, %eax");
    asm("jmp *%eax");
}

