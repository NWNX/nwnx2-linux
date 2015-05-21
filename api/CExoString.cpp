#include "CExoString.h"

float CExoString::AsFLOAT() const
{
    asm("leave");
    asm("mov $0x082cb150, %eax");
    asm("jmp *%eax");
}

int CExoString::AsINT() const
{
    asm("leave");
    asm("mov $0x082cb12c, %eax");
    asm("jmp *%eax");
}

CExoString CExoString::AsTAG() const
{
    asm("leave");
    asm("mov $0x082cbe58, %eax");
    asm("jmp *%eax");
}

char * CExoString::CStr() const
{
    asm("leave");
    asm("mov $0x082cc550, %eax");
    asm("jmp *%eax");
}

int CExoString::CompareNoCase(CExoString const &) const
{
    asm("leave");
    asm("mov $0x082cbb84, %eax");
    asm("jmp *%eax");
}

int CExoString::ComparePrefixNoCase(CExoString const &, int) const
{
    asm("leave");
    asm("mov $0x082cc6bc, %eax");
    asm("jmp *%eax");
}

int CExoString::FindNot(char, int) const
{
    asm("leave");
    asm("mov $0x082cc5f0, %eax");
    asm("jmp *%eax");
}

int CExoString::Find(CExoString const &, int) const
{
    asm("leave");
    asm("mov $0x082cb17c, %eax");
    asm("jmp *%eax");
}

int CExoString::Find(char, int) const
{
    asm("leave");
    asm("mov $0x082cc564, %eax");
    asm("jmp *%eax");
}

int CExoString::GetLength() const
{
    asm("leave");
    asm("mov $0x082cc678, %eax");
    asm("jmp *%eax");
}

void CExoString::Insert(CExoString const &, int)
{
    asm("leave");
    asm("mov $0x082cb330, %eax");
    asm("jmp *%eax");
}

int CExoString::IsEmpty() const
{
    asm("leave");
    asm("mov $0x082cc6a0, %eax");
    asm("jmp *%eax");
}

CExoString CExoString::Left(int) const
{
    asm("leave");
    asm("mov $0x082cb3e4, %eax");
    asm("jmp *%eax");
}

CExoString CExoString::LowerCase() const
{
    asm("leave");
    asm("mov $0x082cb548, %eax");
    asm("jmp *%eax");
}

CExoString CExoString::Right(int) const
{
    asm("leave");
    asm("mov $0x082cb6e0, %eax");
    asm("jmp *%eax");
}

int CExoString::StripNonAlphaNumeric(int, int, int)
{
    asm("leave");
    asm("mov $0x082cbcfc, %eax");
    asm("jmp *%eax");
}

CExoString CExoString::SubString(int, int) const
{
    asm("leave");
    asm("mov $0x082cb85c, %eax");
    asm("jmp *%eax");
}

CExoString CExoString::UpperCase() const
{
    asm("leave");
    asm("mov $0x082cb9ec, %eax");
    asm("jmp *%eax");
}

CExoString & CExoString::operator=(char const *)
{
    asm("leave");
    asm("mov $0x082cae0c, %eax");
    asm("jmp *%eax");
}

CExoString & CExoString::operator=(CExoString const &)
{
    asm("leave");
    asm("mov $0x082cad34, %eax");
    asm("jmp *%eax");
}

int CExoString::operator==(char const *) const
{
    asm("leave");
    asm("mov $0x082cc1dc, %eax");
    asm("jmp *%eax");
}

int CExoString::operator==(CExoString const &) const
{
    asm("leave");
    asm("mov $0x082cc180, %eax");
    asm("jmp *%eax");
}

int CExoString::operator>=(char const *) const
{
    asm("leave");
    asm("mov $0x082cc4d0, %eax");
    asm("jmp *%eax");
}

int CExoString::operator>=(CExoString const &) const
{
    asm("leave");
    asm("mov $0x082cc480, %eax");
    asm("jmp *%eax");
}

int CExoString::operator>(char const *) const
{
    asm("leave");
    asm("mov $0x082cc394, %eax");
    asm("jmp *%eax");
}

int CExoString::operator>(CExoString const &) const
{
    asm("leave");
    asm("mov $0x082cc34c, %eax");
    asm("jmp *%eax");
}

int CExoString::operator<=(char const *) const
{
    asm("leave");
    asm("mov $0x082cc430, %eax");
    asm("jmp *%eax");
}

int CExoString::operator<=(CExoString const &) const
{
    asm("leave");
    asm("mov $0x082cc3d8, %eax");
    asm("jmp *%eax");
}

int CExoString::operator<(char const *) const
{
    asm("leave");
    asm("mov $0x082cc30c, %eax");
    asm("jmp *%eax");
}

int CExoString::operator<(CExoString const &) const
{
    asm("leave");
    asm("mov $0x082cc2cc, %eax");
    asm("jmp *%eax");
}

int CExoString::operator!=(char const *) const
{
    asm("leave");
    asm("mov $0x082cc280, %eax");
    asm("jmp *%eax");
}

int CExoString::operator!=(CExoString const &) const
{
    asm("leave");
    asm("mov $0x082cc230, %eax");
    asm("jmp *%eax");
}

CExoString CExoString::operator+(CExoString const &) const
{
    asm("leave");
    asm("mov $0x082caec0, %eax");
    asm("jmp *%eax");
}

char CExoString::operator[](int) const
{
    asm("leave");
    asm("mov $0x082cc51c, %eax");
    asm("jmp *%eax");
}

