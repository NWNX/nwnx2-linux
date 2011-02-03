#include "CNWSPlayerCharSheetGUI.h"

int CNWSPlayerCharSheetGUI::ComputeCharacterSheetUpdateRequired(CNWSPlayer *)
{
	asm("leave");
	asm("mov $0x08053054, %eax");
	asm("jmp %eax");
}

int CNWSPlayerCharSheetGUI::SetCreatureDisplayed(unsigned long)
{
	asm("leave");
	asm("mov $0x0805e4f8, %eax");
	asm("jmp %eax");
}

