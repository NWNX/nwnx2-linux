#include "CResNSS.h"

unsigned char * CResNSS::GetNSSDataPtr()
{
    asm("leave");
    asm("mov $0x0826a97c, %eax");
    asm("jmp *%eax");
}

unsigned long CResNSS::GetNSSSize()
{
    asm("leave");
    asm("mov $0x0826a988, %eax");
    asm("jmp *%eax");
}

int CResNSS::IsLoaded()
{
    asm("leave");
    asm("mov $0x0826a994, %eax");
    asm("jmp *%eax");
}

int CResNSS::OnResourceFreed()
{
    asm("leave");
    asm("mov $0x0826a9a0, %eax");
    asm("jmp *%eax");
}

int CResNSS::OnResourceServiced()
{
    asm("leave");
    asm("mov $0x0826a9c4, %eax");
    asm("jmp *%eax");
}

