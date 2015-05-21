#include "CScriptTalent.h"

void CScriptTalent::CopyScriptTalent(CScriptTalent *)
{
    asm("leave");
    asm("mov $0x081d44a8, %eax");
    asm("jmp *%eax");
}

int CScriptTalent::Equals(CScriptTalent *)
{
    asm("leave");
    asm("mov $0x081d4644, %eax");
    asm("jmp *%eax");
}

int CScriptTalent::LoadTalent(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x081d457c, %eax");
    asm("jmp *%eax");
}

int CScriptTalent::SaveTalent(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x081d44e0, %eax");
    asm("jmp *%eax");
}

