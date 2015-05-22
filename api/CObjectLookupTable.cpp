#include "CObjectLookupTable.h"

int CObjectLookupTable::AddID(unsigned long)
{
    asm("leave");
    asm("mov $0x08094a48, %eax");
    asm("jmp *%eax");
}

int CObjectLookupTable::GetIDFromIndex(unsigned long)
{
    asm("leave");
    asm("mov $0x08094aac, %eax");
    asm("jmp *%eax");
}

int CObjectLookupTable::GetIndexFromID(unsigned long)
{
    asm("leave");
    asm("mov $0x08094abc, %eax");
    asm("jmp *%eax");
}

int CObjectLookupTable::GetUpdate(void *, unsigned long *)
{
    asm("leave");
    asm("mov $0x08094b9c, %eax");
    asm("jmp *%eax");
}

int CObjectLookupTable::Touch(unsigned long)
{
    asm("leave");
    asm("mov $0x08094af8, %eax");
    asm("jmp *%eax");
}

int CObjectLookupTable::Update(void *, unsigned long)
{
    asm("leave");
    asm("mov $0x08094c1c, %eax");
    asm("jmp *%eax");
}

