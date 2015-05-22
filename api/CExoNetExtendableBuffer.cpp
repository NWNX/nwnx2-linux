#include "CExoNetExtendableBuffer.h"

unsigned long CExoNetExtendableBuffer::ChangeFrameReference(unsigned short, int, int)
{
    asm("leave");
    asm("mov $0x082c57c4, %eax");
    asm("jmp *%eax");
}

int CExoNetExtendableBuffer::GetCurrentUsage(unsigned long *, unsigned long *)
{
    asm("leave");
    asm("mov $0x082c5d78, %eax");
    asm("jmp *%eax");
}

unsigned short CExoNetExtendableBuffer::GetFirstUsedFrame(int)
{
    asm("leave");
    asm("mov $0x082c5bac, %eax");
    asm("jmp *%eax");
}

int CExoNetExtendableBuffer::GetFrameConnectionId(unsigned short, int)
{
    asm("leave");
    asm("mov $0x082c5cf8, %eax");
    asm("jmp *%eax");
}

int CExoNetExtendableBuffer::GetFrameData(unsigned short, unsigned char **, unsigned long *, unsigned long *, unsigned short *, int)
{
    asm("leave");
    asm("mov $0x082c56a8, %eax");
    asm("jmp *%eax");
}

unsigned char * CExoNetExtendableBuffer::GetFramePointer(unsigned short, int)
{
    asm("leave");
    asm("mov $0x082c5c00, %eax");
    asm("jmp *%eax");
}

int CExoNetExtendableBuffer::GetFrameSize(unsigned short, int)
{
    asm("leave");
    asm("mov $0x082c5c7c, %eax");
    asm("jmp *%eax");
}

int CExoNetExtendableBuffer::GetMaximumUsage(unsigned long *, unsigned long *)
{
    asm("leave");
    asm("mov $0x082c5d94, %eax");
    asm("jmp *%eax");
}

unsigned short CExoNetExtendableBuffer::GetUnusedFrame(int)
{
    asm("leave");
    asm("mov $0x082c54e8, %eax");
    asm("jmp *%eax");
}

int CExoNetExtendableBuffer::LockExtBufferInstance()
{
    asm("leave");
    asm("mov $0x082c5ad8, %eax");
    asm("jmp *%eax");
}

int CExoNetExtendableBuffer::SetFrameData(unsigned short, unsigned char *, unsigned long, unsigned long, unsigned long, int)
{
    asm("leave");
    asm("mov $0x082c5b18, %eax");
    asm("jmp *%eax");
}

int CExoNetExtendableBuffer::UnlockExtBufferInstance()
{
    asm("leave");
    asm("mov $0x082c5af8, %eax");
    asm("jmp *%eax");
}

