#ifndef _CGAMEEFFECT_H_
#define _CGAMEEFFECT_H_
#include "nwndef.h"
#include "CExoString.h"

class CGameEffect
{
public:
    void CopyEffect(CGameEffect *, int);
    void GetExpiryTime(unsigned long *, unsigned long *);
    float GetFloat(int);
    int GetInteger(int);
    unsigned long GetObjectID(int);
    int GetScriptEffectType();
    CExoString GetString(int);
    void LoadGameEffect(CResGFF *, CResStruct *);
    void SaveGameEffect(CResGFF *, CResStruct *);
    void SetCreator(unsigned long);
    void SetExpiryTime(unsigned long, unsigned long);
    void SetFloat(int, float);
    void SetInteger(int, int);
    void SetLinked(CGameEffect *, CGameEffect *);
    void SetNumIntegersInitializeToNegativeOne(int);
    void SetNumIntegers(int);
    void SetObjectID(int, unsigned long);
    void SetString(int, CExoString);
    void UpdateLinked();
    ~CGameEffect();
    CGameEffect(CGameEffect *, int);
    CGameEffect(int);
    int operator=(CGameEffect const &);
    int operator==(CGameEffect const &) const;
    int operator!=(CGameEffect const &) const;

    /* 0x0/0 */ unsigned long long Id;
    /* 0x8/8 */ unsigned short Type;
    /* 0xA/10 */ unsigned short SubType;
    /* 0xC/12 */ float Duration;
    /* 0x10/16 */ unsigned long ExpireDay;
    /* 0x14/20 */ unsigned long ExpireTime;
    /* 0x18/24 */ unsigned long CreatorId;
    /* 0x1C/28 */ unsigned long SpellId;
    /* 0x20/32 */ unsigned long IsExposed;
    /* 0x24/36 */ unsigned long IsIconShown;
    /* 0x28/40 */ unsigned long CasterLevel;
    /* 0x2C/44 */ CGameEffect * LinkLeft;
    /* 0x30/48 */ CGameEffect * LinkRight;
    /* 0x34/52 */ unsigned long NumIntegers;
    /* 0x38/56 */ long * IntList;
    /* 0x3C/60 */ float FloatList[4];
    /* 0x4C/76 */ CExoString StringList[6];
    /* 0x7C/124 */ unsigned long ObjectList[4];
    /* 0x8C/140 */ unsigned long SkipOnLoad;
};
#endif
