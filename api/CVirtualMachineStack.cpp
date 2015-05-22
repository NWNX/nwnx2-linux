#include "CVirtualMachineStack.h"

void CVirtualMachineStack::AddToTopOfStack(int)
{
    asm("leave");
    asm("mov $0x0825e5c4, %eax");
    asm("jmp *%eax");
}

void CVirtualMachineStack::AssignLocationToLocation(int, int)
{
    asm("leave");
    asm("mov $0x0825e738, %eax");
    asm("jmp *%eax");
}

void CVirtualMachineStack::ClearStack()
{
    asm("leave");
    asm("mov $0x0825efd0, %eax");
    asm("jmp *%eax");
}

void CVirtualMachineStack::CopyFromStack(CVirtualMachineStack *, int, int)
{
    asm("leave");
    asm("mov $0x0825e89c, %eax");
    asm("jmp *%eax");
}

int CVirtualMachineStack::GetBasePointer()
{
    asm("leave");
    asm("mov $0x08263ec4, %eax");
    asm("jmp *%eax");
}

int CVirtualMachineStack::GetStackPointer()
{
    asm("leave");
    asm("mov $0x08263ee0, %eax");
    asm("jmp *%eax");
}

int CVirtualMachineStack::InitializeStack()
{
    asm("leave");
    asm("mov $0x08263e90, %eax");
    asm("jmp *%eax");
}

int CVirtualMachineStack::LoadStack(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x0825ed18, %eax");
    asm("jmp *%eax");
}

int CVirtualMachineStack::ModifyIntegerAtLocation(int, int)
{
    asm("leave");
    asm("mov $0x08263e9c, %eax");
    asm("jmp *%eax");
}

int CVirtualMachineStack::SaveStack(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x0825eb80, %eax");
    asm("jmp *%eax");
}

int CVirtualMachineStack::SetBasePointer(int)
{
    asm("leave");
    asm("mov $0x08263ed0, %eax");
    asm("jmp *%eax");
}

void CVirtualMachineStack::SetStackPointer(int)
{
    asm("leave");
    asm("mov $0x08263eec, %eax");
    asm("jmp *%eax");
}

