#include "CExoLocStringInternal.h"

int CExoLocStringInternal::AddString(int, CExoString)
{
    asm("leave");
    asm("mov $0x082d0c34, %eax");
    asm("jmp *%eax");
}

int CExoLocStringInternal::Assign(CExoLocStringInternal *)
{
    asm("leave");
    asm("mov $0x082d0d70, %eax");
    asm("jmp *%eax");
}

void CExoLocStringInternal::ClearLocString()
{
    asm("leave");
    asm("mov $0x082d0ff4, %eax");
    asm("jmp *%eax");
}

int CExoLocStringInternal::Compare(CExoLocString &)
{
    asm("leave");
    asm("mov $0x082d0e20, %eax");
    asm("jmp *%eax");
}

unsigned long CExoLocStringInternal::GetStringCount()
{
    asm("leave");
    asm("mov $0x082d1130, %eax");
    asm("jmp *%eax");
}

int CExoLocStringInternal::GetStringLength(unsigned long)
{
    asm("leave");
    asm("mov $0x082d113c, %eax");
    asm("jmp *%eax");
}

int CExoLocStringInternal::GetString(unsigned long, int *, CExoString *)
{
    asm("leave");
    asm("mov $0x082d104c, %eax");
    asm("jmp *%eax");
}

int CExoLocStringInternal::GetString(int, CExoString *)
{
    asm("leave");
    asm("mov $0x082d10cc, %eax");
    asm("jmp *%eax");
}

int CExoLocStringInternal::RemoveString(int)
{
    asm("leave");
    asm("mov $0x082d11ac, %eax");
    asm("jmp *%eax");
}

