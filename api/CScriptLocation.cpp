#include "CScriptLocation.h"

void CScriptLocation::CopyScriptLocation(CScriptLocation *)
{
    asm("leave");
    asm("mov $0x081d4394, %eax");
    asm("jmp *%eax");
}

int CScriptLocation::LoadLocation(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x081c86f8, %eax");
    asm("jmp *%eax");
}

int CScriptLocation::SaveLocation(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x081d43c8, %eax");
    asm("jmp *%eax");
}

