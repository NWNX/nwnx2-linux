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
	int GenerateCallStackParameterView(int, CExoString *, CExoString *);
	int GenerateCallStackView(int, int, int);
	int GenerateDebugVariableLocationForParameter(int, int);
	int GenerateFunctionIDFromInstructionPointer(int);
	int GenerateLineNumberFromInstructionPointer(int, int);
	int GenerateStackSizeAtInstructionPointer(int, int);
	int GenerateTypeName(CExoString *);
	int GenerateTypeSize(CExoString *);
	int GenerateTypeValueFromStackLocation(int, CExoString *);
	int GetNextDebugVariable(int, int, int);
	int LoadDebugInfoLine(unsigned char *, unsigned long, unsigned long, unsigned long *);
	int LoadDebugInfo(CVirtualMachineDebugLoader *);
	int LoadScriptLine(unsigned char *, unsigned long, unsigned long, unsigned long *, int);
	int ParseAndExecuteMessage(int *);
	int ReadIntegerFromInput(int *, int *);
	int ReadStringFromInput(int *, CExoString *);
	int SendCallStackWindowUpdateCommands();
	int SendCodeWindowUpdateCommands(CExoString, int);
	int SendLabelsAndKeywords();
	int SendWatchWindowEntry(CExoString *, CExoString *, CExoString *, CExoString *, int);
	int SendWatchWindowUpdateCommands(int);
	int ShutDownDebugger();
	int SpawnDebugger();
	int ToggleWatchWindowExpansion(CExoString);
	~CVirtualMachineDebuggerInstance();
	CVirtualMachineDebuggerInstance();

};
#endif
