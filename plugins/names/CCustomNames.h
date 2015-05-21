#if !defined(CCustomNames_h_)
#define CCustomNames_h_

#include "typedefs.h"

#define ALLOC_SIZE 10

struct NameEntry {
    dword TargetObjID;
    char *sCustomName;
};

class CPlayerNames
{
public:

    dword PlayerObjID;
    struct NameEntry *data;
    int size;
    int capacity;
    int UnknownStyle;
    int bEnabled;

    CPlayerNames();
    ~CPlayerNames();

    void Construct();

    void InsertCustomName(dword ObjID, char *CustomName);
    void DeleteByObjectID(dword ObjID);
    NameEntry *FindEntryByObjectID(dword ObjID);
    int FindNumByObjectID(dword ObjID);
    void AllocNewMemory();
};

class CCustomNames
{
public:

    CPlayerNames *data;
    int size;
    int capacity;

    CCustomNames();
    ~CCustomNames();

    CPlayerNames *InsertPlayer(dword ObjID, int nStyle, bool bEnabled);
    void DeletePlayer(dword ObjID);
    CPlayerNames *FindPlayerEntry(dword ObjID);
    int FindPlayerID(dword ObjID);
    void AllocNewMemory();
    void InsertCustomName(dword ObjID1, dword ObjID2, char *CustomName);
    char *FindCustomName(dword ObjID1, dword ObjID2);
};


#endif
