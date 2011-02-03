#ifndef _CVIRTUALMACHINESTACK_H_
#define _CVIRTUALMACHINESTACK_H_
#include "nwndef.h"

class CVirtualMachineStack
{
public:
	int AddToTopOfStack(int);
	int AssignLocationToLocation(int, int);
	int ClearStack();
	int CopyFromStack(CVirtualMachineStack *, int, int);
	int GetBasePointer();
	int GetStackPointer();
	int InitializeStack();
	int LoadStack(CResGFF *, CResStruct *);
	int ModifyIntegerAtLocation(int, int);
	int SaveStack(CResGFF *, CResStruct *);
	int SetBasePointer(int);
	int SetStackPointer(int);
	~CVirtualMachineStack();
	CVirtualMachineStack();

	/* 0x0/0 */ unsigned long StackPointer;
	/* 0x4/4 */ unsigned long field_4;
	/* 0x8/8 */ unsigned long AllocatedSize;
	/* 0xC/12 */ void *VarTypes;
	/* 0x10/16 */ void *Values;
	/* 0x14/20 */ unsigned long field_14;
	/* 0x18/24 */ unsigned long CurrentInstruction;
};
#endif
