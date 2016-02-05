#ifndef _CNWAREA_H_
#define _CNWAREA_H_
#include "nwndef.h"
#include "CExoArrayList.h"
#include "Vector.h"

class CNWArea
{
public:
    int AddStaticBoundingBox(unsigned long, Vector const &, Vector const &);
    int AddStaticObject(unsigned long, Vector const &, Vector const &, int, Vector *, int, int *);
    int GetFlags();
    int GetFogClipDistance();
    int GetFog(int *, Vector *);
    int GetHeight();
    int GetIsIDInExcludeList(unsigned long, CExoArrayList<CGameObject *> *);
    int GetIsNight();
    int GetMoonFogAmount();
    int GetMoonFogColor();
    int GetNoRestingAllowed();
    int GetShadowOpacity();
    int GetSkyBox();
    int GetSunFogAmount();
    int GetSunFogColor();
    int GetUseDayNightCycle();
    int GetWidth();
    void GrowStaticObjectArray();
    void GrowStaticObjectTriangles(int);
    void GrowStaticObjectVertices(int);
    int HandleTransparentDoors(float, float, float, float, float, float, float, unsigned long, unsigned long &, int, CExoArrayList<CGameObject *> *, int);
    void InitializeStaticObjects();
    int IntersectLineSegments(float, float, float, float, float, float, float, float, float *, float *);
    int NoCreaturesOnLine(float, float, float, float, CPathfindInformation *);
    int NoNonWalkPolysDetailed(float, float, float, float, float, float, float, unsigned long, unsigned long &, int, CExoArrayList<CGameObject *> *, int);
    int NoNonWalkPolysInDoors(float, float, float, float, float, float, float, unsigned long, unsigned long &, int, CExoArrayList<CGameObject *> *, int);
    int NoNonWalkPolys(float, float, float, float, float, float, float, unsigned long);
    int RemoveStaticBoundingBox(unsigned long);
    void RemoveStaticObject(int);
    void ReplaceStaticObject(int, unsigned long, Vector const &, Vector const &, int, Vector *, int, int *);
    int SetFog(int, Vector);
    int SetIsNight(int);
    int SetMoonFogAmount(unsigned char);
    int SetMoonFogColor(unsigned long);
    int SetSkyBox(unsigned char);
    int SetSunFogAmount(unsigned char);
    int SetSunFogColor(unsigned long);
    int SetUseDayNightCycle(int);
    int SetWind(unsigned char);

protected:
    ~CNWArea();
    CNWArea();

public:
    /* 0x0/0 */ unsigned long Flags;
    /* 0x4/4 */ unsigned long Width;
    /* 0x8/8 */ unsigned long Height;
    /* 0xC/12 */ unsigned long field_C;
    /* 0x10/16 */ unsigned long field_10;
    /* 0x14/20 */ unsigned long field_14;
    /* 0x18/24 */ unsigned long field_18;
    /* 0x1C/28 */ unsigned long field_1C;
    /* 0x20/32 */ unsigned long field_20;
    /* 0x24/36 */ unsigned long field_24;
    /* 0x28/40 */ unsigned long field_28;
    /* 0x2C/44 */ unsigned long field_2C;
    /* 0x30/48 */ unsigned long field_30;
    /* 0x34/52 */ unsigned long field_34;
    /* 0x38/56 */ unsigned long field_38;
    /* 0x3C/60 */ unsigned long field_3C;
    /* 0x40/64 */ unsigned long field_40;
    /* 0x44/68 */ unsigned long field_44;
    /* 0x48/72 */ unsigned long field_48;
    /* 0x4C/76 */ unsigned long field_4C;
    /* 0x50/80 */ unsigned long field_50;
    /* 0x54/84 */ unsigned long field_54;
    /* 0x58/88 */ unsigned long field_58;
    /* 0x5C/92 */ unsigned long field_5C;
    /* 0x60/96 */ unsigned long MoonAmbientColor;
    /* 0x64/100 */ unsigned long MoonDiffuseColor;
    /* 0x68/104 */ unsigned long MoonFogColor;
    /* 0x6C/108 */ unsigned long MoonFogAmount;
    /* 0x70/112 */ unsigned long MoonShadows;
    /* 0x74/116 */ unsigned long SunAmbientColor;
    /* 0x78/120 */ unsigned long SunDiffuseColor;
    /* 0x7C/124 */ unsigned long SunFogColor;
    /* 0x80/128 */ unsigned long SunFogAmount;
    /* 0x84/132 */ unsigned long SunShadows;
    /* 0x88/136 */ unsigned long DayNightCycle;
    /* 0x8C/140 */ unsigned long IsNight;
    /* 0x90/144 */ unsigned char SkyBox;
    /* 0x91/145 */ unsigned char field_91;
    /* 0x92/146 */ unsigned char field_92;
    /* 0x93/147 */ unsigned char field_93;
    /* 0x94/148 */ unsigned char Wind;
    /* 0x98/152 */ unsigned long NoRest;
    /* 0x9C/156 */ unsigned long ShadowOpacity;
    /* 0xA0/160 */ float FogClipDistance;
    /* 0xA4/164 */ CNWArea_vtbl *vptr;
};
#endif
