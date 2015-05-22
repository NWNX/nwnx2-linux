#include "CResPWK.h"

unsigned char * CResPWK::GetPWKDataPtr()
{
    asm("leave");
    asm("mov $0x0824062c, %eax");
    asm("jmp *%eax");
}

unsigned long CResPWK::GetPWKSize()
{
    asm("leave");
    asm("mov $0x08240638, %eax");
    asm("jmp *%eax");
}

int CResPWK::IsLoaded()
{
    asm("leave");
    asm("mov $0x08240644, %eax");
    asm("jmp *%eax");
}

int CResPWK::OnResourceFreed()
{
    asm("leave");
    asm("mov $0x08240650, %eax");
    asm("jmp *%eax");
}

int CResPWK::OnResourceServiced()
{
    asm("leave");
    asm("mov $0x08240674, %eax");
    asm("jmp *%eax");
}

