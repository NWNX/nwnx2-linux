#include "CExoFile.h"

int CExoFile::Eof()
{
    asm("leave");
    asm("mov $0x082c9558, %eax");
    asm("jmp *%eax");
}

int CExoFile::FileOpened()
{
    asm("leave");
    asm("mov $0x082c957c, %eax");
    asm("jmp *%eax");
}

int CExoFile::Flush()
{
    asm("leave");
    asm("mov $0x082c9590, %eax");
    asm("jmp *%eax");
}

unsigned long CExoFile::GetOffset()
{
    asm("leave");
    asm("mov $0x082c95bc, %eax");
    asm("jmp *%eax");
}

int CExoFile::GetSize()
{
    asm("leave");
    asm("mov $0x082c95d0, %eax");
    asm("jmp *%eax");
}

int CExoFile::ReadAsyncBytesRead()
{
    asm("leave");
    asm("mov $0x082c9654, %eax");
    asm("jmp *%eax");
}

int CExoFile::ReadAsyncComplete()
{
    asm("leave");
    asm("mov $0x082c9640, %eax");
    asm("jmp *%eax");
}

void CExoFile::ReadAsync(void *, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x082c9628, %eax");
    asm("jmp *%eax");
}

int CExoFile::ReadStringLineFromBuffer(unsigned char **, unsigned long *, unsigned char *, unsigned long)
{
    asm("leave");
    asm("mov $0x082c9780, %eax");
    asm("jmp *%eax");
}

unsigned long CExoFile::Read(void *, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x082c95e4, %eax");
    asm("jmp *%eax");
}

unsigned long CExoFile::Read(CExoString &, unsigned long)
{
    asm("leave");
    asm("mov $0x082c9614, %eax");
    asm("jmp *%eax");
}

int CExoFile::SeekBeginning()
{
    asm("leave");
    asm("mov $0x082c9720, %eax");
    asm("jmp *%eax");
}

int CExoFile::SeekEnd()
{
    asm("leave");
    asm("mov $0x082c9750, %eax");
    asm("jmp *%eax");
}

int CExoFile::Seek(int, int)
{
    asm("leave");
    asm("mov $0x082c96ec, %eax");
    asm("jmp *%eax");
}

int CExoFile::Write(char const *)
{
    asm("leave");
    asm("mov $0x082c9698, %eax");
    asm("jmp *%eax");
}

unsigned long CExoFile::Write(void const *, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x082c9668, %eax");
    asm("jmp *%eax");
}

unsigned long CExoFile::Write(CExoString const &)
{
    asm("leave");
    asm("mov $0x082c96ac, %eax");
    asm("jmp *%eax");
}

