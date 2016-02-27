#ifndef _CNWSSCRIPTVARTABLE_H_
#define _CNWSSCRIPTVARTABLE_H_
#include "nwndef.h"
#include "CScriptLocation.h"
#include "CExoString.h"

class CNWSScriptVarTable
{
public:
    int DeleteIndex(CExoString &, unsigned long);
    void DestroyFloat(CExoString &);
    void DestroyInt(CExoString &);
    void DestroyLocation(CExoString &);
    void DestroyObject(CExoString &);
    void DestroyString(CExoString &);
    float GetFloat(CExoString &);
    int GetInt(CExoString &);
    CScriptLocation GetLocation(CExoString &);
    unsigned long GetObject(CExoString &);
    CExoString GetString(CExoString &);
    void LoadVarTable(CResGFF *, CResStruct *);
    CNWSScriptVar * MatchIndex(CExoString &, unsigned long, int);
    void SaveVarTable(CResGFF *, CResStruct *);
    void SetFloat(CExoString &, float);
    void SetInt(CExoString &, int, int);
    void SetLocation(CExoString &, CScriptLocation);
    void SetObject(CExoString &, unsigned long);
    void SetString(CExoString &, CExoString &);
    ~CNWSScriptVarTable();

    CNWSScriptVar *First;
    uint32_t Len;

};
#endif
