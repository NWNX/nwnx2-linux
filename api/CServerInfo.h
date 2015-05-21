#ifndef _CSERVERINFO_H_
#define _CSERVERINFO_H_
#include "nwndef.h"
#include "CExoString.h"

class CServerInfo
{
public:
    int FindOptionIndex(CExoString, CExoString);
    void SetDifficultyLevel(int, int);
    CServerInfo();

};
#endif
