#include "CNWPlaceMeshManager.h"

void CNWPlaceMeshManager::ClearWalkMeshes()
{
    asm("leave");
    asm("mov $0x080c460c, %eax");
    asm("jmp *%eax");
}

CNWPlaceableSurfaceMesh * CNWPlaceMeshManager::GetWalkMesh(int)
{
    asm("leave");
    asm("mov $0x080c434c, %eax");
    asm("jmp *%eax");
}

int CNWPlaceMeshManager::InitializeWalkMeshes(int)
{
    asm("leave");
    asm("mov $0x080c45bc, %eax");
    asm("jmp *%eax");
}

