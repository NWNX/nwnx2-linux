#include "CServerAIList.h"

int CServerAIList::AddObject(unsigned long)
{
    asm("leave");
    asm("mov $0x08097fd4, %eax");
    asm("jmp *%eax");
}

int CServerAIList::GetNextObject()
{
    asm("leave");
    asm("mov $0x08098038, %eax");
    asm("jmp *%eax");
}

int CServerAIList::RemoveObject(unsigned long)
{
    asm("leave");
    asm("mov $0x08097ff0, %eax");
    asm("jmp *%eax");
}

