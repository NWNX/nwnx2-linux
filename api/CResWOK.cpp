#include "CResWOK.h"

unsigned char * CResWOK::GetWOKDataPtr()
{
    asm("leave");
    asm("mov $0x080959ec, %eax");
    asm("jmp *%eax");
}

unsigned long CResWOK::GetWOKSize()
{
    asm("leave");
    asm("mov $0x080959f8, %eax");
    asm("jmp *%eax");
}

int CResWOK::IsLoaded()
{
    asm("leave");
    asm("mov $0x08095a04, %eax");
    asm("jmp *%eax");
}

int CResWOK::OnResourceFreed()
{
    asm("leave");
    asm("mov $0x08095a10, %eax");
    asm("jmp *%eax");
}

int CResWOK::OnResourceServiced()
{
    asm("leave");
    asm("mov $0x08095a34, %eax");
    asm("jmp *%eax");
}

