#include "CServerInfo.h"

int CServerInfo::FindOptionIndex(CExoString, CExoString)
{
    asm("leave");
    asm("mov $0x080b3aa4, %eax");
    asm("jmp *%eax");
}

void CServerInfo::SetDifficultyLevel(int, int)
{
    asm("leave");
    asm("mov $0x080b3bc4, %eax");
    asm("jmp *%eax");
}

