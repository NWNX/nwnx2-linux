#include "typedefs.h"
#include "NWNStructures.h"

#ifndef CVirtualMachine_h_
#define CVirtualMachine_h_

/*
00000000 CVirtualMachineScript struc ; (sizeof=0x24)
00000000 Stack dd ?                              ; offset
00000004 StackSize dd ?
00000008 InstructionPtr dd ?
0000000C SecondaryPtr dd ?
00000010 Code dd ?                               ; offset
00000014 CodeSize dd ?
00000018 Name CExoString ?
00000020 field_20 dd ?
00000024 CVirtualMachineScript ends
*/

typedef struct {
    dword Stack;
    dword StackSize;
    dword InstructionPtr;
    dword SecondaryPtr;
    dword Code;
    dword CodeSize;
    CExoString Name;
    dword field_20;
} CVirtualMachineScript;

/*
00000000 CVirtualMachineStack struc ; (sizeof=0x1C)
00000000 StackPointer dd ?
00000004 field_4 dd ?
00000008 AllocatedSize dd ?
0000000C VarTypes dd ?                           ; offset
00000010 Values dd ?                             ; offset
00000014 field_14 dd ?
00000018 CurrentInstruction dd ?
0000001C CVirtualMachineStack ends
*/

typedef struct {
    dword  StackPointer;
    dword  field_4;
    dword  AllocatedSize;
    byte  *VarTypes;
    dword *Values;
    dword  field_14;
    dword  CurrentInstruction;
} CVirtualMachineStack;

/*
00000000 CVirtualMachine struc ; (sizeof=0x3E8)
00000000 field_0 dd ?
00000004 field_4 dd ?
00000008 field_8 dd ?
0000000C RecursionLevel dd ?
00000010 Scripts CVirtualMachineScript 8 dup(?)
00000130 LevelActive dd 8 dup(?)
00000150 ObjectID dd 8 dup(?)
00000170 Stack CVirtualMachineStack ?
0000018C field_18C dd 8 dup(?)
000001AC field_1AC dd 123 dup(?)
00000398 Commands dd ?                           ; offset
0000039C field_39C dd ?
000003A0 field_3A0 dd ?
000003A4 ResHelper CResHelper ?
000003C0 VirtualMachineFileList dd ?
000003C4 field_3C4 dd ?
000003C8 ScriptLog dd ?
000003CC field_3CC dd ?
000003D0 field_3D0 dd ?
000003D4 EnableLogging dd ?
000003D8 EnableProfiling dd ?
000003DC field_3DC dd ?
000003E0 field_3E0 dd ?
000003E4 field_174 dd ?
000003E8 CVirtualMachine ends
*/

typedef struct {
    dword field_0;
    dword field_4;
    dword field_8;
    dword RecursionLevel;
    CVirtualMachineScript Scripts[8];
    dword LevelActive[8];
    dword ObjectID[8];
    CVirtualMachineStack Stack;
    dword field_18C[8];
    dword field_1AC[123];
    void *Commands;
} CVirtualMachine;

#endif

