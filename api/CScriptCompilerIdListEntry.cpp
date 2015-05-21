#include "CScriptCompilerIdListEntry.h"

int CScriptCompilerIdListEntry::ExpandParameterSpace()
{
    asm("leave");
    asm("mov $0x08242a38, %eax");
    asm("jmp *%eax");
}

