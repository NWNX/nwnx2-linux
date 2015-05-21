#include "CNWSTile.h"

int CNWSTile::AddDoor(unsigned long)
{
    asm("leave");
    asm("mov $0x081ee0d4, %eax");
    asm("jmp *%eax");
}

void CNWSTile::AddTrigger(unsigned long)
{
    asm("leave");
    asm("mov $0x081ed9cc, %eax");
    asm("jmp *%eax");
}

int CNWSTile::ClearLineOfSight(int, Vector, Vector, Vector *)
{
    asm("leave");
    asm("mov $0x081ed0bc, %eax");
    asm("jmp *%eax");
}

int CNWSTile::ClippedLineSegmentWalkable(float, float, float, float, float *, float *, float *, float *, float *, float *)
{
    asm("leave");
    asm("mov $0x081eda58, %eax");
    asm("jmp *%eax");
}

int CNWSTile::ComputeClippedLineSegment(Vector, Vector, Vector *, Vector *)
{
    asm("leave");
    asm("mov $0x081ed254, %eax");
    asm("jmp *%eax");
}

float CNWSTile::ComputeHeight(Vector)
{
    asm("leave");
    asm("mov $0x081edb30, %eax");
    asm("jmp *%eax");
}

int CNWSTile::FindClosestRegion(float, float)
{
    asm("leave");
    asm("mov $0x081edbbc, %eax");
    asm("jmp *%eax");
}

int CNWSTile::GetDoorsList()
{
    asm("leave");
    asm("mov $0x081ee104, %eax");
    asm("jmp *%eax");
}

int CNWSTile::GetExitNumber(float, float)
{
    asm("leave");
    asm("mov $0x081edc70, %eax");
    asm("jmp *%eax");
}

int CNWSTile::GetExit(int, float *, float *, int *)
{
    asm("leave");
    asm("mov $0x081edc14, %eax");
    asm("jmp *%eax");
}

int CNWSTile::GetFlaggedAsProblem()
{
    asm("leave");
    asm("mov $0x081ee158, %eax");
    asm("jmp *%eax");
}

int CNWSTile::GetHasPlaceableWithWalkMesh()
{
    asm("leave");
    asm("mov $0x081ee174, %eax");
    asm("jmp *%eax");
}

int CNWSTile::GetMainLightColorChange()
{
    asm("leave");
    asm("mov $0x081ee110, %eax");
    asm("jmp *%eax");
}

int CNWSTile::GetNumTriggers()
{
    asm("leave");
    asm("mov $0x081ee0c8, %eax");
    asm("jmp *%eax");
}

int CNWSTile::GetRegionCoords(int, float *, float *)
{
    asm("leave");
    asm("mov $0x081edcc0, %eax");
    asm("jmp *%eax");
}

int CNWSTile::GetRegionEntrance(float, float)
{
    asm("leave");
    asm("mov $0x081edd1c, %eax");
    asm("jmp *%eax");
}

int CNWSTile::GetSourceLightColorChange()
{
    asm("leave");
    asm("mov $0x081ee12c, %eax");
    asm("jmp *%eax");
}

int CNWSTile::GetSurfaceMaterial(Vector)
{
    asm("leave");
    asm("mov $0x081ede94, %eax");
    asm("jmp *%eax");
}

CNWTileData * CNWSTile::GetTileData()
{
    asm("leave");
    asm("mov $0x081edd70, %eax");
    asm("jmp *%eax");
}

int CNWSTile::GetTotalExits()
{
    asm("leave");
    asm("mov $0x081edd7c, %eax");
    asm("jmp *%eax");
}

int CNWSTile::GetTriggerData()
{
    asm("leave");
    asm("mov $0x081ee0bc, %eax");
    asm("jmp *%eax");
}

int CNWSTile::GetWalkMesh()
{
    asm("leave");
    asm("mov $0x081ede6c, %eax");
    asm("jmp *%eax");
}

int CNWSTile::InTrigger(Vector, CExoArrayList<unsigned long> *)
{
    asm("leave");
    asm("mov $0x081edda0, %eax");
    asm("jmp *%eax");
}

int CNWSTile::IntersectLineSegments(float, float, float, float, float, float, float, float, float *, float *)
{
    asm("leave");
    asm("mov $0x081ed4bc, %eax");
    asm("jmp *%eax");
}

int CNWSTile::LoadWalkMesh()
{
    asm("leave");
    asm("mov $0x081ede54, %eax");
    asm("jmp *%eax");
}

int CNWSTile::NoNonWalkPolysOnTile(float, float, float, float, float, float, float)
{
    asm("leave");
    asm("mov $0x081edf08, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSTile::PlotIntraTilePath(CNWArea *, CPathfindInformation *, float, float, float, float, unsigned long)
{
    asm("leave");
    asm("mov $0x081ed634, %eax");
    asm("jmp *%eax");
}

int CNWSTile::RemoveDoor(unsigned long)
{
    asm("leave");
    asm("mov $0x081ee0ec, %eax");
    asm("jmp *%eax");
}

int CNWSTile::SetFlaggedAsProblem()
{
    asm("leave");
    asm("mov $0x081ee148, %eax");
    asm("jmp *%eax");
}

int CNWSTile::SetHasPlaceableWithWalkMesh()
{
    asm("leave");
    asm("mov $0x081ee164, %eax");
    asm("jmp *%eax");
}

int CNWSTile::SetMainLightColorChange(int)
{
    asm("leave");
    asm("mov $0x081ee11c, %eax");
    asm("jmp *%eax");
}

void CNWSTile::SetMainLightColor(unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x081ee000, %eax");
    asm("jmp *%eax");
}

int CNWSTile::SetSourceLightColorChange(int)
{
    asm("leave");
    asm("mov $0x081ee138, %eax");
    asm("jmp *%eax");
}

void CNWSTile::SetSourceLightColor(unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x081ee02c, %eax");
    asm("jmp *%eax");
}

void CNWSTile::SetTileData(CNWTileData *)
{
    asm("leave");
    asm("mov $0x081edff0, %eax");
    asm("jmp *%eax");
}

