#include "CLastUpdateObject.h"

void CLastUpdateObject::InitializeQuickbar()
{
    asm("leave");
    asm("mov $0x081e42a0, %eax");
    asm("jmp *%eax");
}

