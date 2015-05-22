#include "CGameObjectArray.h"

int CGameObjectArray::AddCharacterObjectAtPos(unsigned long, CGameObject *)
{
    asm("leave");
    asm("mov $0x080bae78, %eax");
    asm("jmp *%eax");
}

int CGameObjectArray::AddExternalObject(unsigned long &, CGameObject *, int)
{
    asm("leave");
    asm("mov $0x080baf5c, %eax");
    asm("jmp *%eax");
}

unsigned char CGameObjectArray::AddInternalObject(unsigned long &, CGameObject *, int)
{
    asm("leave");
    asm("mov $0x080bb04c, %eax");
    asm("jmp *%eax");
}

unsigned char CGameObjectArray::AddObjectAtPos(unsigned long, CGameObject *)
{
    asm("leave");
    asm("mov $0x080bad30, %eax");
    asm("jmp *%eax");
}

int CGameObjectArray::Clean(unsigned short)
{
    asm("leave");
    asm("mov $0x080bb2c4, %eax");
    asm("jmp *%eax");
}

unsigned char CGameObjectArray::Delete(unsigned long)
{
    asm("leave");
    asm("mov $0x080bb200, %eax");
    asm("jmp *%eax");
}

int CGameObjectArray::Delete(unsigned long, CGameObject **)
{
    asm("leave");
    asm("mov $0x080bb21c, %eax");
    asm("jmp *%eax");
}

int CGameObjectArray::GetGameObject(unsigned long, CGameObject **)
{
    asm("leave");
    asm("mov $0x080bb2cc, %eax");
    asm("jmp *%eax");
}

