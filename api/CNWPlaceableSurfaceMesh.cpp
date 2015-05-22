#include "CNWPlaceableSurfaceMesh.h"

int CNWPlaceableSurfaceMesh::LoadWalkMeshString(unsigned char **, unsigned long *, unsigned char *, unsigned long)
{
    asm("leave");
    asm("mov $0x08239e3c, %eax");
    asm("jmp *%eax");
}

int CNWPlaceableSurfaceMesh::LoadWalkMesh(CResRef)
{
    asm("leave");
    asm("mov $0x08239044, %eax");
    asm("jmp *%eax");
}

