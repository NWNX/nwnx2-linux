#include "CNWTileSet.h"

int CNWTileSet::GetCornerType(int, unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x08089ef0, %eax");
    asm("jmp *%eax");
}

int CNWTileSet::GetEdgeType(int, unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x08089f3c, %eax");
    asm("jmp *%eax");
}

int CNWTileSet::GetEnvMapResRef()
{
    asm("leave");
    asm("mov $0x08089f88, %eax");
    asm("jmp *%eax");
}

int CNWTileSet::GetGrassAmbientColor()
{
    asm("leave");
    asm("mov $0x0808a220, %eax");
    asm("jmp *%eax");
}

int CNWTileSet::GetGrassDensity()
{
    asm("leave");
    asm("mov $0x0808a208, %eax");
    asm("jmp *%eax");
}

int CNWTileSet::GetGrassDiffuseColor()
{
    asm("leave");
    asm("mov $0x0808a240, %eax");
    asm("jmp *%eax");
}

int CNWTileSet::GetGrassHeight()
{
    asm("leave");
    asm("mov $0x0808a214, %eax");
    asm("jmp *%eax");
}

int CNWTileSet::GetGrassTexture()
{
    asm("leave");
    asm("mov $0x0808a260, %eax");
    asm("jmp *%eax");
}

int CNWTileSet::GetHasGrass()
{
    asm("leave");
    asm("mov $0x0808a1fc, %eax");
    asm("jmp *%eax");
}

float CNWTileSet::GetHeightTransition()
{
    asm("leave");
    asm("mov $0x08089fa8, %eax");
    asm("jmp *%eax");
}

CNWTileData * CNWTileSet::GetTileData(int)
{
    asm("leave");
    asm("mov $0x08088cf8, %eax");
    asm("jmp *%eax");
}

int CNWTileSet::GetTileSetName()
{
    asm("leave");
    asm("mov $0x0808a1dc, %eax");
    asm("jmp *%eax");
}

int CNWTileSet::LoadTileSet()
{
    asm("leave");
    asm("mov $0x08088dd8, %eax");
    asm("jmp *%eax");
}

int CNWTileSet::ParseLine(char *)
{
    asm("leave");
    asm("mov $0x0808990c, %eax");
    asm("jmp *%eax");
}

int CNWTileSet::SetTileValue(char *, char *)
{
    asm("leave");
    asm("mov $0x08089ab0, %eax");
    asm("jmp *%eax");
}

int CNWTileSet::UnloadTileSet()
{
    asm("leave");
    asm("mov $0x08089fb4, %eax");
    asm("jmp *%eax");
}

