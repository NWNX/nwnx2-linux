#include "CRes2DA.h"

unsigned char * CRes2DA::Get2DADataPtr()
{
    asm("leave");
    asm("mov $0x082c5338, %eax");
    asm("jmp *%eax");
}

int CRes2DA::Get2DAHeaderPtr()
{
    asm("leave");
    asm("mov $0x082c532c, %eax");
    asm("jmp *%eax");
}

unsigned long CRes2DA::Get2DASize()
{
    asm("leave");
    asm("mov $0x082c5344, %eax");
    asm("jmp *%eax");
}

int CRes2DA::IsLoaded()
{
    asm("leave");
    asm("mov $0x082c5350, %eax");
    asm("jmp *%eax");
}

int CRes2DA::OnResourceFreed()
{
    asm("leave");
    asm("mov $0x082c535c, %eax");
    asm("jmp *%eax");
}

int CRes2DA::OnResourceServiced()
{
    asm("leave");
    asm("mov $0x082c5388, %eax");
    asm("jmp *%eax");
}

