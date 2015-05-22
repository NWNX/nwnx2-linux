#include "CVirtualMachineDebuggerInstance.h"

int CVirtualMachineDebuggerInstance::DebuggerDisplayCurrentLocation(int, int)
{
    asm("leave");
    asm("mov $0x08269a88, %eax");
    asm("jmp *%eax");
}

int CVirtualMachineDebuggerInstance::DebuggerMainLoop()
{
    asm("leave");
    asm("mov $0x0826a07c, %eax");
    asm("jmp *%eax");
}

int CVirtualMachineDebuggerInstance::DebuggerSingleStep(int)
{
    asm("leave");
    asm("mov $0x08265540, %eax");
    asm("jmp *%eax");
}

int CVirtualMachineDebuggerInstance::FindEmptyWatchViewEntry()
{
    asm("leave");
    asm("mov $0x08268178, %eax");
    asm("jmp *%eax");
}

int CVirtualMachineDebuggerInstance::FindWatchViewEntry(CExoString *, CExoString *, int)
{
    asm("leave");
    asm("mov $0x0826a4f0, %eax");
    asm("jmp *%eax");
}

CExoString CVirtualMachineDebuggerInstance::GenerateCallStackParameterView(int, CExoString *, CExoString *)
{
    asm("leave");
    asm("mov $0x08267914, %eax");
    asm("jmp *%eax");
}

CExoString CVirtualMachineDebuggerInstance::GenerateCallStackView(int, int, int)
{
    asm("leave");
    asm("mov $0x08267a30, %eax");
    asm("jmp *%eax");
}

int CVirtualMachineDebuggerInstance::GenerateDebugVariableLocationForParameter(int, int)
{
    asm("leave");
    asm("mov $0x0826a490, %eax");
    asm("jmp *%eax");
}

int CVirtualMachineDebuggerInstance::GenerateFunctionIDFromInstructionPointer(int)
{
    asm("leave");
    asm("mov $0x0826a2f8, %eax");
    asm("jmp *%eax");
}

int CVirtualMachineDebuggerInstance::GenerateLineNumberFromInstructionPointer(int, int)
{
    asm("leave");
    asm("mov $0x0826a338, %eax");
    asm("jmp *%eax");
}

int CVirtualMachineDebuggerInstance::GenerateStackSizeAtInstructionPointer(int, int)
{
    asm("leave");
    asm("mov $0x08267760, %eax");
    asm("jmp *%eax");
}

CExoString CVirtualMachineDebuggerInstance::GenerateTypeName(CExoString *)
{
    asm("leave");
    asm("mov $0x08267488, %eax");
    asm("jmp *%eax");
}

int CVirtualMachineDebuggerInstance::GenerateTypeSize(CExoString *)
{
    asm("leave");
    asm("mov $0x082673c8, %eax");
    asm("jmp *%eax");
}

CExoString CVirtualMachineDebuggerInstance::GenerateTypeValueFromStackLocation(int, CExoString *)
{
    asm("leave");
    asm("mov $0x082675f0, %eax");
    asm("jmp *%eax");
}

int CVirtualMachineDebuggerInstance::GetNextDebugVariable(int, int, int)
{
    asm("leave");
    asm("mov $0x0826a3f4, %eax");
    asm("jmp *%eax");
}

int CVirtualMachineDebuggerInstance::LoadDebugInfoLine(unsigned char *, unsigned long, unsigned long, unsigned long *)
{
    asm("leave");
    asm("mov $0x0826a2b4, %eax");
    asm("jmp *%eax");
}

int CVirtualMachineDebuggerInstance::LoadDebugInfo(CVirtualMachineDebugLoader *)
{
    asm("leave");
    asm("mov $0x082659d4, %eax");
    asm("jmp *%eax");
}

char * CVirtualMachineDebuggerInstance::LoadScriptLine(unsigned char *, unsigned long, unsigned long, unsigned long *, int)
{
    asm("leave");
    asm("mov $0x0826a254, %eax");
    asm("jmp *%eax");
}

int CVirtualMachineDebuggerInstance::ParseAndExecuteMessage(int *)
{
    asm("leave");
    asm("mov $0x08265684, %eax");
    asm("jmp *%eax");
}

int CVirtualMachineDebuggerInstance::ReadIntegerFromInput(int *, int *)
{
    asm("leave");
    asm("mov $0x0826a158, %eax");
    asm("jmp *%eax");
}

int CVirtualMachineDebuggerInstance::ReadStringFromInput(int *, CExoString *)
{
    asm("leave");
    asm("mov $0x082655cc, %eax");
    asm("jmp *%eax");
}

void CVirtualMachineDebuggerInstance::SendCallStackWindowUpdateCommands()
{
    asm("leave");
    asm("mov $0x08267ee8, %eax");
    asm("jmp *%eax");
}

void CVirtualMachineDebuggerInstance::SendCodeWindowUpdateCommands(CExoString, int)
{
    asm("leave");
    asm("mov $0x08267084, %eax");
    asm("jmp *%eax");
}

void CVirtualMachineDebuggerInstance::SendLabelsAndKeywords()
{
    asm("leave");
    asm("mov $0x08269cf8, %eax");
    asm("jmp *%eax");
}

void CVirtualMachineDebuggerInstance::SendWatchWindowEntry(CExoString *, CExoString *, CExoString *, CExoString *, int)
{
    asm("leave");
    asm("mov $0x08268804, %eax");
    asm("jmp *%eax");
}

void CVirtualMachineDebuggerInstance::SendWatchWindowUpdateCommands(int)
{
    asm("leave");
    asm("mov $0x08269238, %eax");
    asm("jmp *%eax");
}

void CVirtualMachineDebuggerInstance::ShutDownDebugger()
{
    asm("leave");
    asm("mov $0x0826a100, %eax");
    asm("jmp *%eax");
}

int CVirtualMachineDebuggerInstance::SpawnDebugger()
{
    asm("leave");
    asm("mov $0x08265364, %eax");
    asm("jmp *%eax");
}

void CVirtualMachineDebuggerInstance::ToggleWatchWindowExpansion(CExoString)
{
    asm("leave");
    asm("mov $0x0826a1b0, %eax");
    asm("jmp *%eax");
}

