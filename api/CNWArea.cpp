#include "CNWArea.h"

int CNWArea::AddStaticBoundingBox(unsigned long, Vector const &, Vector const &)
{
    asm("leave");
    asm("mov $0x080bcb98, %eax");
    asm("jmp *%eax");
}

int CNWArea::AddStaticObject(unsigned long, Vector const &, Vector const &, int, Vector *, int, int *)
{
    asm("leave");
    asm("mov $0x080bb5d4, %eax");
    asm("jmp *%eax");
}

int CNWArea::GetFlags()
{
    asm("leave");
    asm("mov $0x080bd088, %eax");
    asm("jmp *%eax");
}

int CNWArea::GetFogClipDistance()
{
    asm("leave");
    asm("mov $0x080bd0dc, %eax");
    asm("jmp *%eax");
}

int CNWArea::GetFog(int *, Vector *)
{
    asm("leave");
    asm("mov $0x080bcf20, %eax");
    asm("jmp *%eax");
}

int CNWArea::GetHeight()
{
    asm("leave");
    asm("mov $0x080bd0a0, %eax");
    asm("jmp *%eax");
}

int CNWArea::GetIsIDInExcludeList(unsigned long, CExoArrayList<CGameObject *> *)
{
    asm("leave");
    asm("mov $0x080bd0b4, %eax");
    asm("jmp *%eax");
}

int CNWArea::GetIsNight()
{
    asm("leave");
    asm("mov $0x080bcf44, %eax");
    asm("jmp *%eax");
}

int CNWArea::GetMoonFogAmount()
{
    asm("leave");
    asm("mov $0x080bd16c, %eax");
    asm("jmp *%eax");
}

int CNWArea::GetMoonFogColor()
{
    asm("leave");
    asm("mov $0x080bd154, %eax");
    asm("jmp *%eax");
}

int CNWArea::GetNoRestingAllowed()
{
    asm("leave");
    asm("mov $0x080bd0bc, %eax");
    asm("jmp *%eax");
}

int CNWArea::GetShadowOpacity()
{
    asm("leave");
    asm("mov $0x080bd0cc, %eax");
    asm("jmp *%eax");
}

int CNWArea::GetSkyBox()
{
    asm("leave");
    asm("mov $0x080bd110, %eax");
    asm("jmp *%eax");
}

int CNWArea::GetSunFogAmount()
{
    asm("leave");
    asm("mov $0x080bd188, %eax");
    asm("jmp *%eax");
}

int CNWArea::GetSunFogColor()
{
    asm("leave");
    asm("mov $0x080bd160, %eax");
    asm("jmp *%eax");
}

int CNWArea::GetUseDayNightCycle()
{
    asm("leave");
    asm("mov $0x080bd0ec, %eax");
    asm("jmp *%eax");
}

int CNWArea::GetWidth()
{
    asm("leave");
    asm("mov $0x080bd094, %eax");
    asm("jmp *%eax");
}

void CNWArea::GrowStaticObjectArray()
{
    asm("leave");
    asm("mov $0x080bb768, %eax");
    asm("jmp *%eax");
}

void CNWArea::GrowStaticObjectTriangles(int)
{
    asm("leave");
    asm("mov $0x080bcde0, %eax");
    asm("jmp *%eax");
}

void CNWArea::GrowStaticObjectVertices(int)
{
    asm("leave");
    asm("mov $0x080bb8ac, %eax");
    asm("jmp *%eax");
}

int CNWArea::HandleTransparentDoors(float, float, float, float, float, float, float, unsigned long, unsigned long &, int, CExoArrayList<CGameObject *> *, int)
{
    asm("leave");
    asm("mov $0x080bd0ac, %eax");
    asm("jmp *%eax");
}

void CNWArea::InitializeStaticObjects()
{
    asm("leave");
    asm("mov $0x080bce68, %eax");
    asm("jmp *%eax");
}

int CNWArea::IntersectLineSegments(float, float, float, float, float, float, float, float, float *, float *)
{
    asm("leave");
    asm("mov $0x080bb970, %eax");
    asm("jmp *%eax");
}

int CNWArea::NoCreaturesOnLine(float, float, float, float, CPathfindInformation *)
{
    asm("leave");
    asm("mov $0x080bd07c, %eax");
    asm("jmp *%eax");
}

int CNWArea::NoNonWalkPolysDetailed(float, float, float, float, float, float, float, unsigned long, unsigned long &, int, CExoArrayList<CGameObject *> *, int)
{
    asm("leave");
    asm("mov $0x080bbe60, %eax");
    asm("jmp *%eax");
}

int CNWArea::NoNonWalkPolysInDoors(float, float, float, float, float, float, float, unsigned long, unsigned long &, int, CExoArrayList<CGameObject *> *, int)
{
    asm("leave");
    asm("mov $0x080bc6a8, %eax");
    asm("jmp *%eax");
}

int CNWArea::NoNonWalkPolys(float, float, float, float, float, float, float, unsigned long)
{
    asm("leave");
    asm("mov $0x080bcee8, %eax");
    asm("jmp *%eax");
}

int CNWArea::RemoveStaticBoundingBox(unsigned long)
{
    asm("leave");
    asm("mov $0x080bcfac, %eax");
    asm("jmp *%eax");
}

void CNWArea::RemoveStaticObject(int)
{
    asm("leave");
    asm("mov $0x080bca58, %eax");
    asm("jmp *%eax");
}

void CNWArea::ReplaceStaticObject(int, unsigned long, Vector const &, Vector const &, int, Vector *, int, int *)
{
    asm("leave");
    asm("mov $0x080bcce0, %eax");
    asm("jmp *%eax");
}

int CNWArea::SetFog(int, Vector)
{
    asm("leave");
    asm("mov $0x080bcf54, %eax");
    asm("jmp *%eax");
}

int CNWArea::SetIsNight(int)
{
    asm("leave");
    asm("mov $0x080bcf7c, %eax");
    asm("jmp *%eax");
}

int CNWArea::SetMoonFogAmount(unsigned char)
{
    asm("leave");
    asm("mov $0x080bd178, %eax");
    asm("jmp *%eax");
}

int CNWArea::SetMoonFogColor(unsigned long)
{
    asm("leave");
    asm("mov $0x080bd134, %eax");
    asm("jmp *%eax");
}

int CNWArea::SetSkyBox(unsigned char)
{
    asm("leave");
    asm("mov $0x080bd120, %eax");
    asm("jmp *%eax");
}

int CNWArea::SetSunFogAmount(unsigned char)
{
    asm("leave");
    asm("mov $0x080bd198, %eax");
    asm("jmp *%eax");
}

int CNWArea::SetSunFogColor(unsigned long)
{
    asm("leave");
    asm("mov $0x080bd144, %eax");
    asm("jmp *%eax");
}

int CNWArea::SetUseDayNightCycle(int)
{
    asm("leave");
    asm("mov $0x080bd0fc, %eax");
    asm("jmp *%eax");
}

int CNWArea::SetWind(unsigned char)
{
    asm("leave");
    asm("mov $0x080bcf94, %eax");
    asm("jmp *%eax");
}

