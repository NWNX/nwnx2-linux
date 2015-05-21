#include "CTlkFile.h"

int CTlkFile::ReadHeader()
{
    asm("leave");
    asm("mov $0x082b61f8, %eax");
    asm("jmp *%eax");
}

