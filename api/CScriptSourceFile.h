#ifndef _CSCRIPTSOURCEFILE_H_
#define _CSCRIPTSOURCEFILE_H_
#include "nwndef.h"

class CScriptSourceFile
{
public:
    int LoadScript(CExoString const &, char **, unsigned long *);
    void UnloadScript();
    ~CScriptSourceFile();
    CScriptSourceFile();

};
#endif
