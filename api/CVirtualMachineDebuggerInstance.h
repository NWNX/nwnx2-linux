#ifndef _CVIRTUALMACHINEDEBUGGERINSTANCE_H_
#define _CVIRTUALMACHINEDEBUGGERINSTANCE_H_
#include "nwndef.h"
#include "CExoString.h"

class CVirtualMachineDebuggerInstance
{
public:
    int DebuggerDisplayCurrentLocation(int, int);
    int DebuggerMainLoop();
    int DebuggerSingleStep(int);
    int FindEmptyWatchViewEntry();
    int FindWatchViewEntry(CExoString *, CExoString *, int);
    CExoString GenerateCallStackParameterView(int, CExoString *, CExoString *);
    CExoString GenerateCallStackView(int, int, int);
    int GenerateDebugVariableLocationForParameter(int, int);
    int GenerateFunctionIDFromInstructionPointer(int);
    int GenerateLineNumberFromInstructionPointer(int, int);
    int GenerateStackSizeAtInstructionPointer(int, int);
    CExoString GenerateTypeName(CExoString *);
    int GenerateTypeSize(CExoString *);
    CExoString GenerateTypeValueFromStackLocation(int, CExoString *);
    int GetNextDebugVariable(int, int, int);
    int LoadDebugInfoLine(unsigned char *, unsigned long, unsigned long, unsigned long *);
    int LoadDebugInfo(CVirtualMachineDebugLoader *);
    char * LoadScriptLine(unsigned char *, unsigned long, unsigned long, unsigned long *, int);
    int ParseAndExecuteMessage(int *);
    int ReadIntegerFromInput(int *, int *);
    int ReadStringFromInput(int *, CExoString *);
    void SendCallStackWindowUpdateCommands();
    void SendCodeWindowUpdateCommands(CExoString, int);
    void SendLabelsAndKeywords();
    void SendWatchWindowEntry(CExoString *, CExoString *, CExoString *, CExoString *, int);
    void SendWatchWindowUpdateCommands(int);
    void ShutDownDebugger();
    int SpawnDebugger();
    void ToggleWatchWindowExpansion(CExoString);
    ~CVirtualMachineDebuggerInstance();
    CVirtualMachineDebuggerInstance();

};
#endif
