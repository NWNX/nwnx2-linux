#include "CNWSInventory.h"

int CNWSInventory::GetArraySlotFromSlotFlag(unsigned long)
{
    asm("leave");
    asm("mov $0x0819e998, %eax");
    asm("jmp *%eax");
}

int CNWSInventory::GetItemInInventory(CNWSItem *)
{
    asm("leave");
    asm("mov $0x0819ec40, %eax");
    asm("jmp *%eax");
}

CNWSItem * CNWSInventory::GetItemInSlot(unsigned long)
{
    asm("leave");
    asm("mov $0x0819ec9c, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSInventory::GetSlotFromItem(CNWSItem *)
{
    asm("leave");
    asm("mov $0x0819ec6c, %eax");
    asm("jmp *%eax");
}

void CNWSInventory::PutItemInSlot(unsigned long, CNWSItem *)
{
    asm("leave");
    asm("mov $0x0819ed18, %eax");
    asm("jmp *%eax");
}

int CNWSInventory::RemoveItem(CNWSItem *)
{
    asm("leave");
    asm("mov $0x0819ecdc, %eax");
    asm("jmp *%eax");
}

