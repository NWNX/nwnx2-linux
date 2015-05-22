#include "CExtendedServerInfo.h"

int CExtendedServerInfo::operator=(CNetLayerSessionInfo &)
{
    asm("leave");
    asm("mov $0x0829f8b0, %eax");
    asm("jmp *%eax");
}

