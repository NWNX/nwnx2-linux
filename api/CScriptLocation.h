#ifndef _CSCRIPTLOCATION_H_
#define _CSCRIPTLOCATION_H_
#include "nwndef.h"

class CScriptLocation
{
public:
    void CopyScriptLocation(CScriptLocation *);
    int LoadLocation(CResGFF *, CResStruct *);
    int SaveLocation(CResGFF *, CResStruct *);
    ~CScriptLocation();
    CScriptLocation();

    /* 0x0/0 */ unsigned long X;
    /* 0x4/4 */ unsigned long Y;
    /* 0x8/8 */ unsigned long Z;
    /* 0xC/12 */ unsigned long OrientationX;
    /* 0x10/16 */ unsigned long OrientationY;
    /* 0x14/20 */ unsigned long OrientationZ;
    /* 0x18/24 */ unsigned long AreaID;
};
#endif
