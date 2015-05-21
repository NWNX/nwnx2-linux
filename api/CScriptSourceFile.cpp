#include "CScriptSourceFile.h"

int CScriptSourceFile::LoadScript(CExoString const &, char **, unsigned long *)
{
    asm("leave");
    asm("mov $0x08247b44, %eax");
    asm("jmp *%eax");
}

void CScriptSourceFile::UnloadScript()
{
    asm("leave");
    asm("mov $0x08247bac, %eax");
    asm("jmp *%eax");
}

