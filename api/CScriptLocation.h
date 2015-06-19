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

    /* 0x0/0 */ float X;
    /* 0x4/4 */ float Y;
    /* 0x8/8 */ float Z;
    /* 0xC/12 */ float OrientationX;
    /* 0x10/16 */ float OrientationY;
    /* 0x14/20 */ float OrientationZ;
    /* 0x18/24 */ unsigned long AreaID;
};
#endif
