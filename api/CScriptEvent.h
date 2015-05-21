#ifndef _CSCRIPTEVENT_H_
#define _CSCRIPTEVENT_H_
#include "nwndef.h"
#include "CExoString.h"

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

};
#endif
