#include "CExoFileInternal.h"

unsigned long CExoFileInternal::GetOffset()
{
    asm("leave");
    asm("mov $0x082d096c, %eax");
    asm("jmp *%eax");
}

int CExoFileInternal::GetSize()
{
    asm("leave");
    asm("mov $0x082d0988, %eax");
    asm("jmp *%eax");
}

int CExoFileInternal::ReadAsyncBytesRead()
{
    asm("leave");
    asm("mov $0x082d0adc, %eax");
    asm("jmp *%eax");
}

int CExoFileInternal::ReadAsyncComplete()
{
    asm("leave");
    asm("mov $0x082d0ad0, %eax");
    asm("jmp *%eax");
}

void CExoFileInternal::ReadAsync(void *, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x082d0a54, %eax");
    asm("jmp *%eax");
}

unsigned long CExoFileInternal::Read(CExoString *, unsigned long)
{
    asm("leave");
    asm("mov $0x082d09f0, %eax");
    asm("jmp *%eax");
}

int CExoFileInternal::Write(char const *)
{
    asm("leave");
    asm("mov $0x082d0ae8, %eax");
    asm("jmp *%eax");
}

