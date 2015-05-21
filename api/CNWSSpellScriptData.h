#ifndef _CNWSSPELLSCRIPTDATA_H_
#define _CNWSSPELLSCRIPTDATA_H_
#include "nwndef.h"
#include "Vector.h"
#include "CExoString.h"

class CNWSSpellScriptData
{
public:
    int LoadData(CResGFF *, CResStruct *);
    int SaveData(CResGFF *, CResStruct *);

    /* 0x0/0 */ unsigned long m_nSpellId;
    /* 0x4/4 */ unsigned short m_nFeatId;
    /* 0x8/8 */ char rsvd1[2];
    /* 0x8/8 */ unsigned long m_oidCaster;
    /* 0xC/12 */ unsigned long m_oidTarget;
    /* 0x10/16 */ unsigned long m_oidItem;
    /* 0x14/20 */ Vector m_vTargetPosition;
    /* 0x20/32 */ CExoString m_sScript;
    /* 0x28/40 */ unsigned long m_oidArea;
    /* 0x2C/44 */ unsigned long m_nItemCastLevel;
};
#endif
