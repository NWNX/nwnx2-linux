#include "CExoStringList.h"

void CExoStringList::AddSorted(CExoString *)
{
    asm("leave");
    asm("mov $0x082ca2c8, %eax");
    asm("jmp *%eax");
}

void CExoStringList::Add(CExoString *)
{
    asm("leave");
    asm("mov $0x082ca5d4, %eax");
    asm("jmp *%eax");
}

int CExoStringList::Clear()
{
    asm("leave");
    asm("mov $0x082cac4c, %eax");
    asm("jmp *%eax");
}

int CExoStringList::Delete(CExoString *)
{
    asm("leave");
    asm("mov $0x082ca714, %eax");
    asm("jmp *%eax");
}

int CExoStringList::GetCount()
{
    asm("leave");
    asm("mov $0x082cac98, %eax");
    asm("jmp *%eax");
}

int CExoStringList::GetDuplicate()
{
    asm("leave");
    asm("mov $0x082caca4, %eax");
    asm("jmp *%eax");
}

int CExoStringList::GetSize()
{
    asm("leave");
    asm("mov $0x082cacb0, %eax");
    asm("jmp *%eax");
}

int CExoStringList::GetSorted()
{
    asm("leave");
    asm("mov $0x082cacbc, %eax");
    asm("jmp *%eax");
}

CExoString * CExoStringList::GetString(int)
{
    asm("leave");
    asm("mov $0x082cacc8, %eax");
    asm("jmp *%eax");
}

int CExoStringList::Insert(CExoString *, int)
{
    asm("leave");
    asm("mov $0x082ca7f0, %eax");
    asm("jmp *%eax");
}

void CExoStringList::Introduce(CExoString *, int)
{
    asm("leave");
    asm("mov $0x082caad0, %eax");
    asm("jmp *%eax");
}

int CExoStringList::Merge(CExoStringList *, int, int)
{
    asm("leave");
    asm("mov $0x082ca8a0, %eax");
    asm("jmp *%eax");
}

int CExoStringList::Remove(int)
{
    asm("leave");
    asm("mov $0x082cacd8, %eax");
    asm("jmp *%eax");
}

int CExoStringList::operator=(CExoStringList &)
{
    asm("leave");
    asm("mov $0x082ca9e4, %eax");
    asm("jmp *%eax");
}

int CExoStringList::operator[](int)
{
    asm("leave");
    asm("mov $0x082cad24, %eax");
    asm("jmp *%eax");
}

