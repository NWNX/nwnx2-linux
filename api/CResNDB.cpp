#include "CResNDB.h"

unsigned char * CResNDB::GetNDBDataPtr()
{
    asm("leave");
    asm("mov $0x0826a85c, %eax");
    asm("jmp *%eax");
}

unsigned long CResNDB::GetNDBSize()
{
    asm("leave");
    asm("mov $0x0826a868, %eax");
    asm("jmp *%eax");
}

int CResNDB::IsLoaded()
{
    asm("leave");
    asm("mov $0x0826a874, %eax");
    asm("jmp *%eax");
}

int CResNDB::OnResourceFreed()
{
    asm("leave");
    asm("mov $0x0826a880, %eax");
    asm("jmp *%eax");
}

int CResNDB::OnResourceServiced()
{
    asm("leave");
    asm("mov $0x0826a8a4, %eax");
    asm("jmp *%eax");
}

