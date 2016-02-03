#ifndef _CSCRIPTEVENT_H_
#define _CSCRIPTEVENT_H_
#include "nwndef.h"
#include "CExoString.h"
#include "CExoArrayList.h"

class CScriptEvent
{
public:
    void CopyScriptEvent(CScriptEvent *);
    float GetFloat(int);
    int GetInteger(int);
    unsigned long GetObjectID(int);
    CExoString GetString(int);
    int LoadEvent(CResGFF *, CResStruct *);
    int SaveEvent(CResGFF *, CResStruct *);
    void SetFloat(int, float);
    void SetInteger(int, int);
    void SetObjectID(int, unsigned long);
    void SetString(int, CExoString);
    ~CScriptEvent();
    CScriptEvent();
    int operator==(CScriptEvent const &) const;
    int operator!=(CScriptEvent const &) const;

    /* 0x0/0 */ unsigned short Type;
    /* 0x2/2 */ unsigned short field_02;
    /* 0x04/4 */ CExoArrayList<int> Integers;
    /* 0x10/16 */ CExoArrayList<float> Floats;
    /* 0x1C/28 */ CExoArrayList<CExoString> Strings;
    /* 0x28/40 */ CExoArrayList<nwobjid> Objects;
};

static_assert_size(CScriptEvent, 0x34);

#endif
