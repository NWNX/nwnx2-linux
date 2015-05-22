#include "CExoKeyTable.h"

int CExoKeyTable::AddDirectoryContents(int)
{
    asm("leave");
    asm("mov $0x082bfb1c, %eax");
    asm("jmp *%eax");
}

int CExoKeyTable::AddEncapsulatedContents(int)
{
    asm("leave");
    asm("mov $0x082bfd04, %eax");
    asm("jmp *%eax");
}

int CExoKeyTable::AddKeyTableContents(int)
{
    asm("leave");
    asm("mov $0x082c0d5c, %eax");
    asm("jmp *%eax");
}

CKeyTableEntry * CExoKeyTable::AddKey(CResRef const &, unsigned short, unsigned long, int)
{
    asm("leave");
    asm("mov $0x082c0aac, %eax");
    asm("jmp *%eax");
}

int CExoKeyTable::AddResourceImageContents(int, unsigned char *)
{
    asm("leave");
    asm("mov $0x082c084c, %eax");
    asm("jmp *%eax");
}

int CExoKeyTable::AllocateTable(unsigned long, int)
{
    asm("leave");
    asm("mov $0x082c2038, %eax");
    asm("jmp *%eax");
}

int CExoKeyTable::BuildNewTable(unsigned long, CExoString const &, unsigned long, int, unsigned char *)
{
    asm("leave");
    asm("mov $0x082c42f8, %eax");
    asm("jmp *%eax");
}

int CExoKeyTable::DeleteTableList(CExoLinkedList<CKeyTableInfo> *)
{
    asm("leave");
    asm("mov $0x082c4400, %eax");
    asm("jmp *%eax");
}

void CExoKeyTable::DestroyTable()
{
    asm("leave");
    asm("mov $0x082c21dc, %eax");
    asm("jmp *%eax");
}

int CExoKeyTable::FindKey(CRes *)
{
    asm("leave");
    asm("mov $0x082c4484, %eax");
    asm("jmp *%eax");
}

CKeyTableEntry * CExoKeyTable::FindKey(CResRef const &, unsigned short)
{
    asm("leave");
    asm("mov $0x082c23f4, %eax");
    asm("jmp *%eax");
}

int CExoKeyTable::GetEntryCount(int)
{
    asm("leave");
    asm("mov $0x082c4288, %eax");
    asm("jmp *%eax");
}

CExoStringList * CExoKeyTable::GetKeysOfType(unsigned short)
{
    asm("leave");
    asm("mov $0x082c2500, %eax");
    asm("jmp *%eax");
}

int CExoKeyTable::GetResID(CResRef const &, unsigned short)
{
    asm("leave");
    asm("mov $0x082c44dc, %eax");
    asm("jmp *%eax");
}

int CExoKeyTable::GetRes(CResRef const &, unsigned short)
{
    asm("leave");
    asm("mov $0x082c44b4, %eax");
    asm("jmp *%eax");
}

int CExoKeyTable::GetTableEntry(unsigned long, CResRef &, unsigned short &)
{
    asm("leave");
    asm("mov $0x082c4508, %eax");
    asm("jmp *%eax");
}

int CExoKeyTable::GetTableIndex(unsigned long &, CResRef const &, unsigned short)
{
    asm("leave");
    asm("mov $0x082c455c, %eax");
    asm("jmp *%eax");
}

int CExoKeyTable::Hash(CResRef const &, unsigned short)
{
    asm("leave");
    asm("mov $0x082c45cc, %eax");
    asm("jmp *%eax");
}

int CExoKeyTable::LocateBifFile(CExoString const &)
{
    asm("leave");
    asm("mov $0x082c20fc, %eax");
    asm("jmp *%eax");
}

void CExoKeyTable::RebuildTable(unsigned char *)
{
    asm("leave");
    asm("mov $0x082c2640, %eax");
    asm("jmp *%eax");
}

