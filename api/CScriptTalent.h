#ifndef _CSCRIPTTALENT_H_
#define _CSCRIPTTALENT_H_
#include "nwndef.h"

class CScriptTalent
{
public:
    void CopyScriptTalent(CScriptTalent *);
    int Equals(CScriptTalent *);
    int LoadTalent(CResGFF *, CResStruct *);
    int SaveTalent(CResGFF *, CResStruct *);
    ~CScriptTalent();
    CScriptTalent();

};
#endif
