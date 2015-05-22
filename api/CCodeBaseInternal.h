#ifndef _CCODEBASEINTERNAL_H_
#define _CCODEBASEINTERNAL_H_
#include "nwndef.h"

class CCodeBaseInternal
{
public:
    int AddBinaryData(CExoString &, CExoString &, CExoString &, char, void *, int);
    int AddFloat(CExoString &, CExoString &, CExoString &, float);
    int AddInt(CExoString &, CExoString &, CExoString &, int);
    int AddLocation(CExoString &, CExoString &, CExoString &, CScriptLocation const &);
    int AddString(CExoString &, CExoString &, CExoString &, CExoString &);
    int AddVarEnd(SCodeBaseData *, int);
    int AddVarStart(SCodeBaseData *, CExoString &, CExoString &, int &);
    int AddVector(CExoString &, CExoString &, CExoString &, Vector const &);
    void CloseAllFiles();
    void CloseFile(int);
    int DeleteVar(CExoString &, CExoString &, CExoString &);
    void DestroyDatabase(CExoString &);
    void * GetBinaryData(CExoString &, CExoString &, CExoString &, char &, int &);
    SCodeBaseData * GetFile(CExoString &, int);
    float GetFloat(CExoString &, CExoString &, CExoString &);
    int GetInt(CExoString &, CExoString &, CExoString &);
    CScriptLocation * GetLocation(CExoString &, CExoString &, CExoString &);
    CExoString * GetString(CExoString &, CExoString &, CExoString &);
    SRecord * GetVar(SCodeBaseData *, CExoString &, CExoString &);
    Vector * GetVector(CExoString &, CExoString &, CExoString &);
    int OpenFile(CExoString &, int);
    ~CCodeBaseInternal();
    CCodeBaseInternal();

};
#endif
