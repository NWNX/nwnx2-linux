#ifndef _CVIRTUALMACHINE_H_
#define _CVIRTUALMACHINE_H_
#include "nwndef.h"
#include "Vector.h"
#include "nwnstructs.h"
#include "CVirtualMachineStack.h"
#include "CVirtualMachineFile.h"

class CVirtualMachine
{
public:
    void Debugger(int *);
    void DeleteScriptSituation(void *);
    int DeleteScript(CVirtualMachineScript *);
    int ExecuteCode(int *, char *, int, CVirtualMachineDebuggingContext *);
    int GetRunScriptReturnValue(int *, void **);
    int GetScriptLog(CExoString const &);
    int InitializeScript(CVirtualMachineScript *, char *, int);
    int LoadScriptSituation_Internal(CVirtualMachineScript **, CResGFF *, CResStruct *);
    int PopInstructionPtr(int *);
    int PushInstructionPtr(int);
    int ReadScriptFile(CExoString *);
    int RunScriptFile(int);
    int RunScriptSituation(void *, unsigned long, int);
    int RunScript(CExoString *, unsigned long, int);
    int SaveScriptSituation_Internal(CVirtualMachineScript *, CResGFF *, CResStruct *);
    void SetCommandImplementer(CVirtualMachineCmdImplementer *);
    void SetDebugGUIFlag(int);
    int SetUpScriptSituation(CVirtualMachineScript *);
    int StackPopCommand_Internal(CVirtualMachineScript **);
    int StackPopEngineStructure(int, void **);
    int StackPopFloat(float *);
    int StackPopInteger(int *);
    int StackPopObject(unsigned long *);
    int StackPopString(CExoString *);
    int StackPopVector(Vector *);
    int StackPushEngineStructure(int, void *);
    int StackPushFloat(float);
    int StackPushInteger(int);
    int StackPushObject(unsigned long);
    int StackPushString(CExoString const &);
    int StackPushVector(Vector);
    int Test_RunAllScriptsInDirectory(CExoString &);
    ~CVirtualMachine();
    CVirtualMachine();

    /* 0x0/0 */ unsigned long field_0;
    /* 0x4/4 */ unsigned long m_pReturnValue;
    /* 0x8/8 */ unsigned long InstructionsExecuted;
    /* 0xC/12 */ unsigned long RecursionLevel;
    /* 0x10/16 */ CVirtualMachineScript m_pVirtualMachineScript[8];
    /* 0x130/304 */ unsigned long m_bValidObjectRunScript[8];
    /* 0x150/336 */ unsigned long ObjectID[8];
    /* 0x170/368 */ CVirtualMachineStack Stack;
    /* 0x18C/396 */ unsigned long m_nInstructPtrLevel;
    /* 0x190/400 */ unsigned long m_pnRunTimeInstructPtr[128];
    /* 0x390/912 */ unsigned long m_nStackSizeToSave;
    /* 0x394/916 */ unsigned long m_nBaseStackSizeToSave;
    /* 0x398/920 */ CNWVirtualMachineCommands *m_pCmdImplementer;
    /* 0x39C/924 */ unsigned long m_bDebugGUIRequired;
    /* 0x3A0/928 */ unsigned long m_bDebuggerSpawned;
    /* 0x3A4/932 */ CVirtualMachineFile m_cVMFile;
    /* 0x3C0/960 */ unsigned long m_pCache;
    /* 0x3C4/964 */ unsigned long field_3C4;
    /* 0x3C8/968 */ unsigned long ScriptLog;
    /* 0x3CC/972 */ unsigned long field_3CC;
    /* 0x3D0/976 */ unsigned long field_3D0;
    /* 0x3D4/980 */ unsigned long EnableLogging;
    /* 0x3D8/984 */ unsigned long EnableProfiling;
    /* 0x3DC/988 */ unsigned long field_3DC;
    /* 0x3E0/992 */ unsigned long field_3E0;
    /* 0x3E4/996 */ unsigned long field_174;
};
#endif
