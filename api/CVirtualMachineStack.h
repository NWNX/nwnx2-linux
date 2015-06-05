#ifndef _CVIRTUALMACHINESTACK_H_
#define _CVIRTUALMACHINESTACK_H_
#include "nwndef.h"

class CVirtualMachineStack
{
public:
    void AddToTopOfStack(int);
    void AssignLocationToLocation(int, int);
    void ClearStack();
    void CopyFromStack(CVirtualMachineStack *, int, int);
    int GetBasePointer();
    int GetStackPointer();
    int InitializeStack();
    int LoadStack(CResGFF *, CResStruct *);
    int ModifyIntegerAtLocation(int, int);
    int SaveStack(CResGFF *, CResStruct *);
    int SetBasePointer(int);
    void SetStackPointer(int);
    ~CVirtualMachineStack();
    CVirtualMachineStack();

    /* 0x0/0 */ unsigned long StackPointer;
    /* 0x4/4 */ unsigned long BasePointer;
    /* 0x8/8 */ unsigned long AllocatedSize;
    /* 0xC/12 */ char *VarTypes;
    /* 0x10/16 */ void *Values;
    /* 0x14/20 */ CVirtualMachine *pVM;
    /* 0x18/24 */ unsigned long CurrentInstruction;
};
#endif
