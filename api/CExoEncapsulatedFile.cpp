#include "CExoEncapsulatedFile.h"

void CExoEncapsulatedFile::AddAsyncRefCount()
{
    asm("leave");
    asm("mov $0x082c4ac0, %eax");
    asm("jmp *%eax");
}

void CExoEncapsulatedFile::AddRefCount()
{
    asm("leave");
    asm("mov $0x082c4a90, %eax");
    asm("jmp *%eax");
}

int CExoEncapsulatedFile::CloseAsyncFile()
{
    asm("leave");
    asm("mov $0x082c4b30, %eax");
    asm("jmp *%eax");
}

int CExoEncapsulatedFile::CloseFile()
{
    asm("leave");
    asm("mov $0x082c4af0, %eax");
    asm("jmp *%eax");
}

void CExoEncapsulatedFile::DeleteAsyncRefCount()
{
    asm("leave");
    asm("mov $0x082c4c04, %eax");
    asm("jmp *%eax");
}

void CExoEncapsulatedFile::DeleteRefCount()
{
    asm("leave");
    asm("mov $0x082c4bd4, %eax");
    asm("jmp *%eax");
}

int CExoEncapsulatedFile::GetDescription()
{
    asm("leave");
    asm("mov $0x082c5124, %eax");
    asm("jmp *%eax");
}

unsigned long CExoEncapsulatedFile::GetResourceSize(unsigned long)
{
    asm("leave");
    asm("mov $0x082c4c34, %eax");
    asm("jmp *%eax");
}

int CExoEncapsulatedFile::Initialize()
{
    asm("leave");
    asm("mov $0x082c4c4c, %eax");
    asm("jmp *%eax");
}

int CExoEncapsulatedFile::LoadHeader(unsigned char)
{
    asm("leave");
    asm("mov $0x082c3688, %eax");
    asm("jmp *%eax");
}

int CExoEncapsulatedFile::OpenAsyncFile()
{
    asm("leave");
    asm("mov $0x082c334c, %eax");
    asm("jmp *%eax");
}

int CExoEncapsulatedFile::OpenFile()
{
    asm("leave");
    asm("mov $0x082c3010, %eax");
    asm("jmp *%eax");
}

int CExoEncapsulatedFile::OpenFile(unsigned char *)
{
    asm("leave");
    asm("mov $0x082c4ca4, %eax");
    asm("jmp *%eax");
}

void CExoEncapsulatedFile::ReadResourceAsync(unsigned long, void *, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x082c4d3c, %eax");
    asm("jmp *%eax");
}

unsigned long CExoEncapsulatedFile::ReadResource(unsigned long, void *, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x082c4cbc, %eax");
    asm("jmp *%eax");
}

int CExoEncapsulatedFile::UnloadHeader()
{
    asm("leave");
    asm("mov $0x082c4b70, %eax");
    asm("jmp *%eax");
}

