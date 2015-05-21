#include "CVirtualMachineDebugLoader.h"

int CVirtualMachineDebugLoader::DemandDebugInfo(CExoString *)
{
    asm("leave");
    asm("mov $0x08264b08, %eax");
    asm("jmp *%eax");
}

int CVirtualMachineDebugLoader::GetDataPtr()
{
    asm("leave");
    asm("mov $0x08269fe4, %eax");
    asm("jmp *%eax");
}

int CVirtualMachineDebugLoader::GetSize()
{
    asm("leave");
    asm("mov $0x0826a004, %eax");
    asm("jmp *%eax");
}

int CVirtualMachineDebugLoader::ReleaseDebugInfo()
{
    asm("leave");
    asm("mov $0x0826a024, %eax");
    asm("jmp *%eax");
}

