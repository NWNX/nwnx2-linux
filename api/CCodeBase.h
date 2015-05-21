#ifndef _CCODEBASE_H_
#define _CCODEBASE_H_
#include "nwndef.h"

class CCodeBase
{
public:
    int AddBinaryData(CExoString &, CExoString &, CExoString &, char, void *, int);
    int AddFloat(CExoString &, CExoString &, CExoString &, float);
    int AddInt(CExoString &, CExoString &, CExoString &, int);
    int AddLocation(CExoString &, CExoString &, CExoString &, CScriptLocation const &);
    int AddString(CExoString &, CExoString &, CExoString &, CExoString &);
    int AddVector(CExoString &, CExoString &, CExoString &, Vector const &);
    int CloseAllFiles();
    int DeleteVar(CExoString &, CExoString &, CExoString &);
    void DestroyDatabase(CExoString &);
    void * GetBinaryData(CExoString &, CExoString &, CExoString &, char &, int &);
    float GetFloat(CExoString &, CExoString &, CExoString &);
    int GetInt(CExoString &, CExoString &, CExoString &);
    CScriptLocation * GetLocation(CExoString &, CExoString &, CExoString &);
    CExoString * GetString(CExoString &, CExoString &, CExoString &);
    Vector * GetVector(CExoString &, CExoString &, CExoString &);
    ~CCodeBase();
    CCodeBase();

};
#endif
