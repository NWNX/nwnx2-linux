#include "CExoResFile.h"

void CExoResFile::AddAsyncRefCount()
{
    asm("leave");
    asm("mov $0x082c4754, %eax");
    asm("jmp *%eax");
}

void CExoResFile::AddRefCount()
{
    asm("leave");
    asm("mov $0x082c4724, %eax");
    asm("jmp *%eax");
}

int CExoResFile::CloseAsyncFile()
{
    asm("leave");
    asm("mov $0x082c47c4, %eax");
    asm("jmp *%eax");
}

int CExoResFile::CloseFile()
{
    asm("leave");
    asm("mov $0x082c4784, %eax");
    asm("jmp *%eax");
}

void CExoResFile::DeleteAsyncRefCount()
{
    asm("leave");
    asm("mov $0x082c4888, %eax");
    asm("jmp *%eax");
}

void CExoResFile::DeleteRefCount()
{
    asm("leave");
    asm("mov $0x082c4858, %eax");
    asm("jmp *%eax");
}

unsigned long CExoResFile::GetResourceSize(unsigned long)
{
    asm("leave");
    asm("mov $0x082c48b8, %eax");
    asm("jmp *%eax");
}

int CExoResFile::Initialize()
{
    asm("leave");
    asm("mov $0x082c48d4, %eax");
    asm("jmp *%eax");
}

int CExoResFile::LoadHeader(unsigned char)
{
    asm("leave");
    asm("mov $0x082c2d84, %eax");
    asm("jmp *%eax");
}

int CExoResFile::OpenAsyncFile()
{
    asm("leave");
    asm("mov $0x082c2c80, %eax");
    asm("jmp *%eax");
}

int CExoResFile::OpenFile()
{
    asm("leave");
    asm("mov $0x082c2b7c, %eax");
    asm("jmp *%eax");
}

int CExoResFile::OpenFile(unsigned char *)
{
    asm("leave");
    asm("mov $0x082c4928, %eax");
    asm("jmp *%eax");
}

void CExoResFile::ReadResourceAsync(unsigned long, void *, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x082c49c4, %eax");
    asm("jmp *%eax");
}

unsigned long CExoResFile::ReadResource(unsigned long, void *, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x082c4940, %eax");
    asm("jmp *%eax");
}

int CExoResFile::UnloadHeader()
{
    asm("leave");
    asm("mov $0x082c4804, %eax");
    asm("jmp *%eax");
}

