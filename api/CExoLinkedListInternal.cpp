#include "CExoLinkedListInternal.h"

int CExoLinkedListInternal::AddAfter(void *, CExoLinkedListNode *)
{
	asm("leave");
	asm("mov $0x082c99a0, %eax");
	asm("jmp %eax");
}

int CExoLinkedListInternal::AddBefore(void *, CExoLinkedListNode *)
{
	asm("leave");
	asm("mov $0x082c9a30, %eax");
	asm("jmp %eax");
}

int CExoLinkedListInternal::AddHead(void *)
{
	asm("leave");
	asm("mov $0x082c98f8, %eax");
	asm("jmp %eax");
}

int CExoLinkedListInternal::AddTail(void *)
{
	asm("leave");
	asm("mov $0x082c994c, %eax");
	asm("jmp %eax");
}

int CExoLinkedListInternal::GetAtPos(CExoLinkedListNode *)
{
	asm("leave");
	asm("mov $0x082c9ab4, %eax");
	asm("jmp %eax");
}

int CExoLinkedListInternal::GetNext(CExoLinkedListNode *&)
{
	asm("leave");
	asm("mov $0x082c9aec, %eax");
	asm("jmp %eax");
}

int CExoLinkedListInternal::GetPrev(CExoLinkedListNode *&)
{
	asm("leave");
	asm("mov $0x082c9b3c, %eax");
	asm("jmp %eax");
}

int CExoLinkedListInternal::RemoveHead()
{
	asm("leave");
	asm("mov $0x082c9bfc, %eax");
	asm("jmp %eax");
}

int CExoLinkedListInternal::RemoveTail()
{
	asm("leave");
	asm("mov $0x082c9c68, %eax");
	asm("jmp %eax");
}

int CExoLinkedListInternal::Remove(CExoLinkedListNode *)
{
	asm("leave");
	asm("mov $0x082c9b88, %eax");
	asm("jmp %eax");
}

