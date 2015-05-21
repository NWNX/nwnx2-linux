#include "CNWTileSurfaceMeshHashTableEntry.h"

int CNWTileSurfaceMeshHashTableEntry::Fetch(int)
{
    asm("leave");
    asm("mov $0x0809349c, %eax");
    asm("jmp *%eax");
}

int CNWTileSurfaceMeshHashTableEntry::Store(int, float)
{
    asm("leave");
    asm("mov $0x080934c0, %eax");
    asm("jmp *%eax");
}

