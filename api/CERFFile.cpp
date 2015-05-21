#include "CERFFile.h"

int CERFFile::AddResource(char *, unsigned short, CRes *)
{
    asm("leave");
    asm("mov $0x082b65f4, %eax");
    asm("jmp *%eax");
}

int CERFFile::AddResource(CExoString &)
{
    asm("leave");
    asm("mov $0x082b7b74, %eax");
    asm("jmp *%eax");
}

int CERFFile::AddString(CERFString *)
{
    asm("leave");
    asm("mov $0x082b6844, %eax");
    asm("jmp *%eax");
}

int CERFFile::Create(CExoString &)
{
    asm("leave");
    asm("mov $0x082b7b8c, %eax");
    asm("jmp *%eax");
}

int CERFFile::Finish()
{
    asm("leave");
    asm("mov $0x082b7cac, %eax");
    asm("jmp *%eax");
}

int CERFFile::ReadModuleDescription(CExoString const &, unsigned short, unsigned long *, CExoString *)
{
    asm("leave");
    asm("mov $0x082b7280, %eax");
    asm("jmp *%eax");
}

int CERFFile::Read()
{
    asm("leave");
    asm("mov $0x082b7b84, %eax");
    asm("jmp *%eax");
}

int CERFFile::RecalculateOffsets()
{
    asm("leave");
    asm("mov $0x082b71d8, %eax");
    asm("jmp *%eax");
}

int CERFFile::RemoveResource(CERFRes *)
{
    asm("leave");
    asm("mov $0x082b7b7c, %eax");
    asm("jmp *%eax");
}

int CERFFile::RemoveResource(CExoString &, unsigned short)
{
    asm("leave");
    asm("mov $0x082b6704, %eax");
    asm("jmp *%eax");
}

int CERFFile::Reset()
{
    asm("leave");
    asm("mov $0x082b652c, %eax");
    asm("jmp *%eax");
}

int CERFFile::SetNumEntries(unsigned long)
{
    asm("leave");
    asm("mov $0x082b6a54, %eax");
    asm("jmp *%eax");
}

void CERFFile::SetVersion(char *)
{
    asm("leave");
    asm("mov $0x082b7b5c, %eax");
    asm("jmp *%eax");
}

int CERFFile::WriteHeader()
{
    asm("leave");
    asm("mov $0x082b7c44, %eax");
    asm("jmp *%eax");
}

int CERFFile::WriteResource(char *, unsigned short, CRes *, int)
{
    asm("leave");
    asm("mov $0x082b6bf8, %eax");
    asm("jmp *%eax");
}

int CERFFile::WriteStringTable()
{
    asm("leave");
    asm("mov $0x082b68fc, %eax");
    asm("jmp *%eax");
}

int CERFFile::Write(CExoString &)
{
    asm("leave");
    asm("mov $0x082b6ee8, %eax");
    asm("jmp *%eax");
}

