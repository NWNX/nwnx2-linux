#include "CNWSSpellScriptData.h"

int CNWSSpellScriptData::LoadData(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x0813758c, %eax");
    asm("jmp *%eax");
}

int CNWSSpellScriptData::SaveData(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x0813d098, %eax");
    asm("jmp *%eax");
}

