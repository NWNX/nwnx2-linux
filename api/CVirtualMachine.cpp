#include "CVirtualMachine.h"

void CVirtualMachine::Debugger(int *)
{
    asm("leave");
    asm("mov $0x08263d98, %eax");
    asm("jmp *%eax");
}

void CVirtualMachine::DeleteScriptSituation(void *)
{
    asm("leave");
    asm("mov $0x08264550, %eax");
    asm("jmp *%eax");
}

int CVirtualMachine::DeleteScript(CVirtualMachineScript *)
{
    asm("leave");
    asm("mov $0x082641ec, %eax");
    asm("jmp *%eax");
}

int CVirtualMachine::ExecuteCode(int *, char *, int, CVirtualMachineDebuggingContext *)
{
    asm("leave");
    asm("mov $0x0825fd0c, %eax");
    asm("jmp *%eax");
}

int CVirtualMachine::GetRunScriptReturnValue(int *, void **)
{
    asm("leave");
    asm("mov $0x08264324, %eax");
    asm("jmp *%eax");
}

int CVirtualMachine::GetScriptLog(CExoString const &)
{
    asm("leave");
    asm("mov $0x082642c4, %eax");
    asm("jmp *%eax");
}

int CVirtualMachine::InitializeScript(CVirtualMachineScript *, char *, int)
{
    asm("leave");
    asm("mov $0x08264194, %eax");
    asm("jmp *%eax");
}

int CVirtualMachine::LoadScriptSituation_Internal(CVirtualMachineScript **, CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x08263244, %eax");
    asm("jmp *%eax");
}

int CVirtualMachine::PopInstructionPtr(int *)
{
    asm("leave");
    asm("mov $0x08264258, %eax");
    asm("jmp *%eax");
}

int CVirtualMachine::PushInstructionPtr(int)
{
    asm("leave");
    asm("mov $0x08264294, %eax");
    asm("jmp *%eax");
}

int CVirtualMachine::ReadScriptFile(CExoString *)
{
    asm("leave");
    asm("mov $0x08261c2c, %eax");
    asm("jmp *%eax");
}

int CVirtualMachine::RunScriptFile(int)
{
    asm("leave");
    asm("mov $0x0826276c, %eax");
    asm("jmp *%eax");
}

int CVirtualMachine::RunScriptSituation(void *, unsigned long, int)
{
    asm("leave");
    asm("mov $0x08262534, %eax");
    asm("jmp *%eax");
}

int CVirtualMachine::RunScript(CExoString *, unsigned long, int)
{
    asm("leave");
    asm("mov $0x08261f94, %eax");
    asm("jmp *%eax");
}

int CVirtualMachine::SaveScriptSituation_Internal(CVirtualMachineScript *, CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x0826306c, %eax");
    asm("jmp *%eax");
}

void CVirtualMachine::SetCommandImplementer(CVirtualMachineCmdImplementer *)
{
    asm("leave");
    asm("mov $0x082645cc, %eax");
    asm("jmp *%eax");
}

void CVirtualMachine::SetDebugGUIFlag(int)
{
    asm("leave");
    asm("mov $0x082645b8, %eax");
    asm("jmp *%eax");
}

int CVirtualMachine::SetUpScriptSituation(CVirtualMachineScript *)
{
    asm("leave");
    asm("mov $0x08262920, %eax");
    asm("jmp *%eax");
}

int CVirtualMachine::StackPopCommand_Internal(CVirtualMachineScript **)
{
    asm("leave");
    asm("mov $0x08262ebc, %eax");
    asm("jmp *%eax");
}

int CVirtualMachine::StackPopEngineStructure(int, void **)
{
    asm("leave");
    asm("mov $0x08262cfc, %eax");
    asm("jmp *%eax");
}

int CVirtualMachine::StackPopFloat(float *)
{
    asm("leave");
    asm("mov $0x08262ad8, %eax");
    asm("jmp *%eax");
}

int CVirtualMachine::StackPopInteger(int *)
{
    asm("leave");
    asm("mov $0x082629fc, %eax");
    asm("jmp *%eax");
}

int CVirtualMachine::StackPopObject(unsigned long *)
{
    asm("leave");
    asm("mov $0x08262dfc, %eax");
    asm("jmp *%eax");
}

int CVirtualMachine::StackPopString(CExoString *)
{
    asm("leave");
    asm("mov $0x08262c18, %eax");
    asm("jmp *%eax");
}

int CVirtualMachine::StackPopVector(Vector *)
{
    asm("leave");
    asm("mov $0x082643c8, %eax");
    asm("jmp *%eax");
}

int CVirtualMachine::StackPushEngineStructure(int, void *)
{
    asm("leave");
    asm("mov $0x082644ac, %eax");
    asm("jmp *%eax");
}

int CVirtualMachine::StackPushFloat(float)
{
    asm("leave");
    asm("mov $0x08264388, %eax");
    asm("jmp *%eax");
}

int CVirtualMachine::StackPushInteger(int)
{
    asm("leave");
    asm("mov $0x0826434c, %eax");
    asm("jmp *%eax");
}

int CVirtualMachine::StackPushObject(unsigned long)
{
    asm("leave");
    asm("mov $0x08264514, %eax");
    asm("jmp *%eax");
}

int CVirtualMachine::StackPushString(CExoString const &)
{
    asm("leave");
    asm("mov $0x08264430, %eax");
    asm("jmp *%eax");
}

int CVirtualMachine::StackPushVector(Vector)
{
    asm("leave");
    asm("mov $0x08262b98, %eax");
    asm("jmp *%eax");
}

int CVirtualMachine::Test_RunAllScriptsInDirectory(CExoString &)
{
    asm("leave");
    asm("mov $0x082634c4, %eax");
    asm("jmp *%eax");
}

