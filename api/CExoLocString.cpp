#include "CExoLocString.h"

int CExoLocString::AddString(int, CExoString, unsigned char)
{
    asm("leave");
    asm("mov $0x082ca040, %eax");
    asm("jmp *%eax");
}

void CExoLocString::ClearLocString()
{
    asm("leave");
    asm("mov $0x082ca0c0, %eax");
    asm("jmp *%eax");
}

unsigned long CExoLocString::GetStringCount()
{
    asm("leave");
    asm("mov $0x082ca148, %eax");
    asm("jmp *%eax");
}

int CExoLocString::GetStringInternal(int, CExoString *)
{
    asm("leave");
    asm("mov $0x082ca170, %eax");
    asm("jmp *%eax");
}

int CExoLocString::GetStringLength(unsigned long)
{
    asm("leave");
    asm("mov $0x082ca15c, %eax");
    asm("jmp *%eax");
}

int CExoLocString::GetStringLoc(int, CExoString *, unsigned char)
{
    asm("leave");
    asm("mov $0x082ca118, %eax");
    asm("jmp *%eax");
}

int CExoLocString::GetString(unsigned long, int *, CExoString *, unsigned char *)
{
    asm("leave");
    asm("mov $0x082ca0d4, %eax");
    asm("jmp *%eax");
}

int CExoLocString::GetString(int, CExoString *, unsigned char, bool)
{
    asm("leave");
    asm("mov $0x082c9cd0, %eax");
    asm("jmp *%eax");
}

int CExoLocString::RemoveString(int)
{
    asm("leave");
    asm("mov $0x082ca184, %eax");
    asm("jmp *%eax");
}

int CExoLocString::RemoveString(int, unsigned char)
{
    asm("leave");
    asm("mov $0x082ca1b0, %eax");
    asm("jmp *%eax");
}

CExoLocString & CExoLocString::operator=(CExoLocString const &)
{
    asm("leave");
    asm("mov $0x082ca010, %eax");
    asm("jmp *%eax");
}

int CExoLocString::operator==(CExoLocString &)
{
    asm("leave");
    asm("mov $0x082c9f9c, %eax");
    asm("jmp *%eax");
}

int CExoLocString::operator!=(CExoLocString &)
{
    asm("leave");
    asm("mov $0x082c9fd4, %eax");
    asm("jmp *%eax");
}

