#include "CExoNetFrameBuffer.h"

unsigned long CExoNetFrameBuffer::ChangeRefCount(unsigned char, int)
{
    asm("leave");
    asm("mov $0x082c5ea8, %eax");
    asm("jmp *%eax");
}

int CExoNetFrameBuffer::GetFrameConnectionId(unsigned char)
{
    asm("leave");
    asm("mov $0x082c5f60, %eax");
    asm("jmp *%eax");
}

int CExoNetFrameBuffer::GetFrameData(unsigned char, unsigned char **, unsigned long *, unsigned long *, unsigned char *)
{
    asm("leave");
    asm("mov $0x082c5fa4, %eax");
    asm("jmp *%eax");
}

int CExoNetFrameBuffer::GetFramePointer(unsigned char)
{
    asm("leave");
    asm("mov $0x082c5f80, %eax");
    asm("jmp *%eax");
}

int CExoNetFrameBuffer::GetFrameSize(unsigned char)
{
    asm("leave");
    asm("mov $0x082c5f40, %eax");
    asm("jmp *%eax");
}

int CExoNetFrameBuffer::GetRefCount(unsigned char)
{
    asm("leave");
    asm("mov $0x082c5e88, %eax");
    asm("jmp *%eax");
}

int CExoNetFrameBuffer::GetUnusedFrame()
{
    asm("leave");
    asm("mov $0x082c5e4c, %eax");
    asm("jmp *%eax");
}

int CExoNetFrameBuffer::GetUsedFrame()
{
    asm("leave");
    asm("mov $0x082c5e5c, %eax");
    asm("jmp *%eax");
}

int CExoNetFrameBuffer::SetFrameData(unsigned char, unsigned char *, unsigned long, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x082c602c, %eax");
    asm("jmp *%eax");
}

