#include "CNWTileData.h"

int CNWTileData::AddPropertyMethodString(unsigned long, CExoString)
{
    asm("leave");
    asm("mov $0x081f5750, %eax");
    asm("jmp *%eax");
}

int CNWTileData::GetCornerType(unsigned char)
{
    asm("leave");
    asm("mov $0x081f59d8, %eax");
    asm("jmp *%eax");
}

int CNWTileData::GetEdgeType(unsigned char)
{
    asm("leave");
    asm("mov $0x081f5b00, %eax");
    asm("jmp *%eax");
}

int CNWTileData::GetMapIcon()
{
    asm("leave");
    asm("mov $0x081f5b88, %eax");
    asm("jmp *%eax");
}

int CNWTileData::GetModelResRef()
{
    asm("leave");
    asm("mov $0x081f5998, %eax");
    asm("jmp *%eax");
}

int CNWTileData::GetNumDoors()
{
    asm("leave");
    asm("mov $0x081f5c00, %eax");
    asm("jmp *%eax");
}

int CNWTileData::GetPropertyMethodStringList(unsigned long)
{
    asm("leave");
    asm("mov $0x081f597c, %eax");
    asm("jmp *%eax");
}

CNWTileSurfaceMesh * CNWTileData::GetSurfaceMesh()
{
    asm("leave");
    asm("mov $0x081f5bf4, %eax");
    asm("jmp *%eax");
}

void CNWTileData::SetCornerType(unsigned char, CExoString, int)
{
    asm("leave");
    asm("mov $0x081f5844, %eax");
    asm("jmp *%eax");
}

void CNWTileData::SetEdgeType(unsigned char, CExoString)
{
    asm("leave");
    asm("mov $0x081f5a60, %eax");
    asm("jmp *%eax");
}

void CNWTileData::SetMapIcon(CResRef)
{
    asm("leave");
    asm("mov $0x081f5ba8, %eax");
    asm("jmp *%eax");
}

void CNWTileData::SetModelResRef(CResRef)
{
    asm("leave");
    asm("mov $0x081f59b8, %eax");
    asm("jmp *%eax");
}

int CNWTileData::SetNumDoors(unsigned char)
{
    asm("leave");
    asm("mov $0x081f5c0c, %eax");
    asm("jmp *%eax");
}

