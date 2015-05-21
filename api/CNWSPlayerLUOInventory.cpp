#include "CNWSPlayerLUOInventory.h"

void CNWSPlayerLUOInventory::ClearBarter()
{
    asm("leave");
    asm("mov $0x081e3e90, %eax");
    asm("jmp *%eax");
}

void CNWSPlayerLUOInventory::ClearContainer()
{
    asm("leave");
    asm("mov $0x081e3e00, %eax");
    asm("jmp *%eax");
}

void CNWSPlayerLUOInventory::ClearRepository()
{
    asm("leave");
    asm("mov $0x081e3dc4, %eax");
    asm("jmp *%eax");
}

void CNWSPlayerLUOInventory::ClearSlots()
{
    asm("leave");
    asm("mov $0x081e3ecc, %eax");
    asm("jmp *%eax");
}

void CNWSPlayerLUOInventory::ClearStore()
{
    asm("leave");
    asm("mov $0x081e3e44, %eax");
    asm("jmp *%eax");
}

void CNWSPlayerLUOInventory::ItemListAddHead(unsigned long, unsigned char, unsigned char, unsigned char, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x081e41cc, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSPlayerLUOInventory::ItemListGetItemObjectID(CExoLinkedListNode *, unsigned char)
{
    asm("leave");
    asm("mov $0x081e3ef8, %eax");
    asm("jmp *%eax");
}

CNWSItem * CNWSPlayerLUOInventory::ItemListGetItem(CExoLinkedListNode *, unsigned char)
{
    asm("leave");
    asm("mov $0x081e2ad4, %eax");
    asm("jmp *%eax");
}

int CNWSPlayerLUOInventory::ItemListGetNext(CExoLinkedListNode *&, unsigned char)
{
    asm("leave");
    asm("mov $0x081e408c, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSPlayerLUOInventory::ItemListGetNumber(unsigned char)
{
    asm("leave");
    asm("mov $0x081e416c, %eax");
    asm("jmp *%eax");
}

int CNWSPlayerLUOInventory::ItemListGetPrev(CExoLinkedListNode *&, unsigned char)
{
    asm("leave");
    asm("mov $0x081e40fc, %eax");
    asm("jmp *%eax");
}

CNWSPlayerLUOInventoryItem * CNWSPlayerLUOInventory::ItemListGetUpdateItem(CExoLinkedListNode *, unsigned char)
{
    asm("leave");
    asm("mov $0x081e3f6c, %eax");
    asm("jmp *%eax");
}

void CNWSPlayerLUOInventory::ItemListRemove(CExoLinkedListNode *, unsigned char)
{
    asm("leave");
    asm("mov $0x081e2b7c, %eax");
    asm("jmp *%eax");
}

int CNWSPlayerLUOInventory::ItemListSetEnd(CExoLinkedListNode *&, unsigned char)
{
    asm("leave");
    asm("mov $0x081e4030, %eax");
    asm("jmp *%eax");
}

int CNWSPlayerLUOInventory::ItemListSetStart(CExoLinkedListNode *&, unsigned char)
{
    asm("leave");
    asm("mov $0x081e3fd4, %eax");
    asm("jmp *%eax");
}

