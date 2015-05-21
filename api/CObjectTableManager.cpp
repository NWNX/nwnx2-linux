#include "CObjectTableManager.h"

int CObjectTableManager::AddID(unsigned long, unsigned long *, unsigned long)
{
    asm("leave");
    asm("mov $0x08094d80, %eax");
    asm("jmp *%eax");
}

void CObjectTableManager::ClearAll()
{
    asm("leave");
    asm("mov $0x08094d18, %eax");
    asm("jmp *%eax");
}

int CObjectTableManager::CreateNewPlayer(unsigned long)
{
    asm("leave");
    asm("mov $0x0809484c, %eax");
    asm("jmp *%eax");
}

int CObjectTableManager::GetIDFromIndex(unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x08094e28, %eax");
    asm("jmp *%eax");
}

int CObjectTableManager::GetIndexFromID(unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x08094e6c, %eax");
    asm("jmp *%eax");
}

int CObjectTableManager::RemovePlayer(unsigned long)
{
    asm("leave");
    asm("mov $0x08094cb8, %eax");
    asm("jmp *%eax");
}

int CObjectTableManager::Touch(unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x0809490c, %eax");
    asm("jmp *%eax");
}

