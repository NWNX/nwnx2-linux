#include "CExoResourceImageFile.h"

void CExoResourceImageFile::AddAsyncRefCount()
{
    asm("leave");
    asm("mov $0x082c5028, %eax");
    asm("jmp *%eax");
}

void CExoResourceImageFile::AddRefCount()
{
    asm("leave");
    asm("mov $0x082c4df4, %eax");
    asm("jmp *%eax");
}

int CExoResourceImageFile::CloseAsyncFile()
{
    asm("leave");
    asm("mov $0x082c5030, %eax");
    asm("jmp *%eax");
}

int CExoResourceImageFile::CloseFile()
{
    asm("leave");
    asm("mov $0x082c4e24, %eax");
    asm("jmp *%eax");
}

void CExoResourceImageFile::DeleteAsyncRefCount()
{
    asm("leave");
    asm("mov $0x082c503c, %eax");
    asm("jmp *%eax");
}

void CExoResourceImageFile::DeleteRefCount()
{
    asm("leave");
    asm("mov $0x082c4e6c, %eax");
    asm("jmp *%eax");
}

int CExoResourceImageFile::GetHeader()
{
    asm("leave");
    asm("mov $0x082c4f18, %eax");
    asm("jmp *%eax");
}

int CExoResourceImageFile::GetKeyListEntry(unsigned long)
{
    asm("leave");
    asm("mov $0x082c4eac, %eax");
    asm("jmp *%eax");
}

int CExoResourceImageFile::GetKeyList()
{
    asm("leave");
    asm("mov $0x082c4e8c, %eax");
    asm("jmp *%eax");
}

EncapsulatedResListEntry_st * CExoResourceImageFile::GetResourceListEntry(unsigned long)
{
    asm("leave");
    asm("mov $0x082c4ee8, %eax");
    asm("jmp *%eax");
}

unsigned long CExoResourceImageFile::GetResourceSize(unsigned long)
{
    asm("leave");
    asm("mov $0x082c4f24, %eax");
    asm("jmp *%eax");
}

void * CExoResourceImageFile::GetResource(unsigned long)
{
    asm("leave");
    asm("mov $0x082c4f40, %eax");
    asm("jmp *%eax");
}

int CExoResourceImageFile::Initialize()
{
    asm("leave");
    asm("mov $0x082c4f5c, %eax");
    asm("jmp *%eax");
}

int CExoResourceImageFile::LoadHeader(unsigned char)
{
    asm("leave");
    asm("mov $0x082c5050, %eax");
    asm("jmp *%eax");
}

int CExoResourceImageFile::OpenAsyncFile()
{
    asm("leave");
    asm("mov $0x082c5044, %eax");
    asm("jmp *%eax");
}

int CExoResourceImageFile::OpenFile()
{
    asm("leave");
    asm("mov $0x082c4f94, %eax");
    asm("jmp *%eax");
}

int CExoResourceImageFile::OpenFile(unsigned char *)
{
    asm("leave");
    asm("mov $0x082c3f9c, %eax");
    asm("jmp *%eax");
}

void CExoResourceImageFile::ReadResourceAsync(unsigned long, void *, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x082c5004, %eax");
    asm("jmp *%eax");
}

unsigned long CExoResourceImageFile::ReadResource(unsigned long, void *, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x082c4fac, %eax");
    asm("jmp *%eax");
}

int CExoResourceImageFile::UnloadHeader()
{
    asm("leave");
    asm("mov $0x082c4e60, %eax");
    asm("jmp *%eax");
}

