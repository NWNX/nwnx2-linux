#include "CResDWK.h"

unsigned char * CResDWK::GetDWKDataPtr()
{
    asm("leave");
    asm("mov $0x08240504, %eax");
    asm("jmp *%eax");
}

unsigned long CResDWK::GetDWKSize()
{
    asm("leave");
    asm("mov $0x08240510, %eax");
    asm("jmp *%eax");
}

int CResDWK::IsLoaded()
{
    asm("leave");
    asm("mov $0x0824051c, %eax");
    asm("jmp *%eax");
}

int CResDWK::OnResourceFreed()
{
    asm("leave");
    asm("mov $0x08240528, %eax");
    asm("jmp *%eax");
}

int CResDWK::OnResourceServiced()
{
    asm("leave");
    asm("mov $0x0824054c, %eax");
    asm("jmp *%eax");
}

