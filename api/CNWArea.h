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
    ~CNWArea();
    CNWArea();

};
#endif
