#include "CItemRepository.h"

int CItemRepository::AddItem(CNWSItem **, unsigned char, unsigned char, int, int)
{
    asm("leave");
    asm("mov $0x081a32d0, %eax");
    asm("jmp *%eax");
}

int CItemRepository::AddPanel()
{
    asm("leave");
    asm("mov $0x081a6b48, %eax");
    asm("jmp *%eax");
}

int CItemRepository::CalculateContentsWeight()
{
    asm("leave");
    asm("mov $0x081a4a54, %eax");
    asm("jmp *%eax");
}

unsigned char CItemRepository::CalculatePage(unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x081a6a38, %eax");
    asm("jmp *%eax");
}

int CItemRepository::CheckFit(CNWSItem *, unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x081a3bb4, %eax");
    asm("jmp *%eax");
}

int CItemRepository::CheckItemOverlaps(CNWSItem *, CNWSItem *, unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x081a3dd8, %eax");
    asm("jmp *%eax");
}

unsigned long CItemRepository::FindItemWithBaseItemId(unsigned long, int)
{
    asm("leave");
    asm("mov $0x081a3ee4, %eax");
    asm("jmp *%eax");
}

unsigned long CItemRepository::FindItemWithTag(CExoString *)
{
    asm("leave");
    asm("mov $0x081a3f9c, %eax");
    asm("jmp *%eax");
}

int CItemRepository::FindPosition(CNWSItem *, unsigned char &, unsigned char &, int)
{
    asm("leave");
    asm("mov $0x081a4114, %eax");
    asm("jmp *%eax");
}

int CItemRepository::GetItemInRepository(CNWSItem *, int)
{
    asm("leave");
    asm("mov $0x081a4744, %eax");
    asm("jmp *%eax");
}

unsigned long CItemRepository::GetItemInRepository(unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x081a6ab8, %eax");
    asm("jmp *%eax");
}

unsigned long CItemRepository::ItemListGetItemObjectID(CExoLinkedListNode *)
{
    asm("leave");
    asm("mov $0x081a6a90, %eax");
    asm("jmp *%eax");
}

CNWSItem * CItemRepository::ItemListGetItem(CExoLinkedListNode *)
{
    asm("leave");
    asm("mov $0x081a6a58, %eax");
    asm("jmp *%eax");
}

int CItemRepository::MoveItem(CNWSItem *, unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x081a497c, %eax");
    asm("jmp *%eax");
}

int CItemRepository::RemoveItem(CNWSItem *)
{
    asm("leave");
    asm("mov $0x081a4844, %eax");
    asm("jmp *%eax");
}

