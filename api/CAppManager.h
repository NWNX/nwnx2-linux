#ifndef _CAPPMANAGER_H_
#define _CAPPMANAGER_H_
#include "nwndef.h"

class CAppManager
{
public:
    void CreateServer();
    void DestroyScriptDebuggerPopup();
    void DestroyServer();
    void DisplayScriptDebuggerPopup();
    void DoSaveGameScreenShot(CExoString &);
    int GetDungeonMasterEXERunning();
    CObjectTableManager * GetObjectTableManager(unsigned long);
    unsigned char GetProgressFromCodeword(CExoString &);
    unsigned char ReadProgressFromINI(unsigned char);
    int SetDungeonMasterEXERunning(int);
    int ShowServerMem();
    int SpawnExternalScriptDebugger();
    ~CAppManager();
    CAppManager();

    /* 0x0/0 */ unsigned long field_0;
    /* 0x4/4 */ CServerExoApp *ServerExoApp;
    /* 0x8/8 */ unsigned long field_8;
    /* 0xC/12 */ unsigned long field_C;
    /* 0x10/16 */ unsigned long field_10;
    /* 0x14/20 */ CAppManager_ModuleInfo *some_struct;
    /* 0x18/24 */ unsigned long field_18;
    /* 0x1C/28 */ unsigned long field_1C;
    /* 0x20/32 */ unsigned long MultiplayerEnabled;
    /* 0x24/36 */ unsigned long field_24;
    /* 0x28/40 */ unsigned long field_28;
    /* 0x2C/44 */ unsigned long field_2C;
    /* 0x30/48 */ unsigned long field_30;
    /* 0x34/52 */ unsigned long field_34;
    /* 0x38/56 */ unsigned long field_38;
};
#endif
