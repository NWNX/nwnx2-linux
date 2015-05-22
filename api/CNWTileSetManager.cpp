#include "CNWTileSetManager.h"

void CNWTileSetManager::ClearTilePathNodes()
{
    asm("leave");
    asm("mov $0x08086cbc, %eax");
    asm("jmp *%eax");
}

int CNWTileSetManager::ComputePathNodeInformation(unsigned char, int, int &, int &, float **, float **, int **)
{
    asm("leave");
    asm("mov $0x08086d70, %eax");
    asm("jmp *%eax");
}

int CNWTileSetManager::ComputePathNodeRotation(int, float *, float *)
{
    asm("leave");
    asm("mov $0x08088ac0, %eax");
    asm("jmp *%eax");
}

CNWTilePathNode * CNWTileSetManager::GetTilePathNode(unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x08088a44, %eax");
    asm("jmp *%eax");
}

int CNWTileSetManager::InitializeTilePathNodes()
{
    asm("leave");
    asm("mov $0x08088a10, %eax");
    asm("jmp *%eax");
}

CNWTileSet * CNWTileSetManager::RegisterTileSet(CResRef)
{
    asm("leave");
    asm("mov $0x08086ba4, %eax");
    asm("jmp *%eax");
}

void CNWTileSetManager::UnregisterTileSet(CNWTileSet *)
{
    asm("leave");
    asm("mov $0x080889a8, %eax");
    asm("jmp *%eax");
}

