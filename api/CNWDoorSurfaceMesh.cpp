#include "CNWDoorSurfaceMesh.h"

int CNWDoorSurfaceMesh::GetMeshBoundingBox(Vector, Vector, Vector &, Vector &)
{
    asm("leave");
    asm("mov $0x08238854, %eax");
    asm("jmp *%eax");
}

int CNWDoorSurfaceMesh::GetOpenLocation(unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x08238cc8, %eax");
    asm("jmp *%eax");
}

int CNWDoorSurfaceMesh::IntersectLineSegments(Vector, Vector, Vector, Vector, Vector *)
{
    asm("leave");
    asm("mov $0x08238390, %eax");
    asm("jmp *%eax");
}

int CNWDoorSurfaceMesh::LoadWalkMeshString(unsigned char **, unsigned long *, unsigned char *, unsigned long)
{
    asm("leave");
    asm("mov $0x08238acc, %eax");
    asm("jmp *%eax");
}

int CNWDoorSurfaceMesh::LoadWalkMesh(CResRef)
{
    asm("leave");
    asm("mov $0x0823701c, %eax");
    asm("jmp *%eax");
}

int CNWDoorSurfaceMesh::NoNonWalkPolysOnSurfaceMesh(int, float, float, float, float, float, float, float)
{
    asm("leave");
    asm("mov $0x08237aa4, %eax");
    asm("jmp *%eax");
}

