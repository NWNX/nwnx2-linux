#include "CExoFileThread.h"

int CExoFileThread::AsyncRead()
{
    asm("leave");
    asm("mov $0x082d05e4, %eax");
    asm("jmp *%eax");
}

int CExoFileThread::Read(void *, unsigned long, unsigned long, _IO_FILE *)
{
    asm("leave");
    asm("mov $0x082d0654, %eax");
    asm("jmp *%eax");
}

