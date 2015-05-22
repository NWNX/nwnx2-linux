#include "CExoRandInternal.h"

int CExoRandInternal::Add(unsigned char *, int)
{
    asm("leave");
    asm("mov $0x082d1c80, %eax");
    asm("jmp *%eax");
}

int CExoRandInternal::GenSeed()
{
    asm("leave");
    asm("mov $0x082d1c58, %eax");
    asm("jmp *%eax");
}

CExoString CExoRandInternal::GetString(unsigned short)
{
    asm("leave");
    asm("mov $0x082d15e0, %eax");
    asm("jmp *%eax");
}

unsigned long CExoRandInternal::Rand()
{
    asm("leave");
    asm("mov $0x082d1b64, %eax");
    asm("jmp *%eax");
}

void CExoRandInternal::ReSeed(unsigned long, unsigned long, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x082d19f0, %eax");
    asm("jmp *%eax");
}

void CExoRandInternal::SignalEvent()
{
    asm("leave");
    asm("mov $0x082d1850, %eax");
    asm("jmp *%eax");
}

int CExoRandInternal::SignalEvent(unsigned long)
{
    asm("leave");
    asm("mov $0x082d1c18, %eax");
    asm("jmp *%eax");
}

