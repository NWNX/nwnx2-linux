#include "CResNCS.h"

int CResNCS::GetNCSDataPtr()
{
	asm("leave");
	asm("mov $0x0826a73c, %eax");
	asm("jmp %eax");
}

int CResNCS::GetNCSSize()
{
	asm("leave");
	asm("mov $0x0826a748, %eax");
	asm("jmp %eax");
}

int CResNCS::IsLoaded()
{
	asm("leave");
	asm("mov $0x0826a754, %eax");
	asm("jmp %eax");
}

int CResNCS::OnResourceFreed()
{
	asm("leave");
	asm("mov $0x0826a760, %eax");
	asm("jmp %eax");
}

int CResNCS::OnResourceServiced()
{
	asm("leave");
	asm("mov $0x0826a784, %eax");
	asm("jmp %eax");
}

