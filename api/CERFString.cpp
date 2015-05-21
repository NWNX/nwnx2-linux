#include "CERFString.h"

CExoString CERFString::GetText()
{
    asm("leave");
    asm("mov $0x082b7fa8, %eax");
    asm("jmp *%eax");
}

int CERFString::Read()
{
    asm("leave");
    asm("mov $0x082b8038, %eax");
    asm("jmp *%eax");
}

int CERFString::Reset()
{
    asm("leave");
    asm("mov $0x082b7f6c, %eax");
    asm("jmp *%eax");
}

void CERFString::SetText(CExoString &)
{
    asm("leave");
    asm("mov $0x082b7fd0, %eax");
    asm("jmp *%eax");
}

int CERFString::Write(CExoFile &)
{
    asm("leave");
    asm("mov $0x082b8040, %eax");
    asm("jmp *%eax");
}

