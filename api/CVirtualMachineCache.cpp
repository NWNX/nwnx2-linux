#include "CVirtualMachineCache.h"

void CVirtualMachineCache::ClearAllFiles()
{
    asm("leave");
    asm("mov $0x08264114, %eax");
    asm("jmp *%eax");
}

void CVirtualMachineCache::PrecacheFile(CExoString const &)
{
    asm("leave");
    asm("mov $0x0825f0b4, %eax");
    asm("jmp *%eax");
}

