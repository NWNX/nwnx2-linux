#include "CNetLayerPlayerInfo.h"

int CNetLayerPlayerInfo::AddCDKey(CExoString const &, CExoString const &)
{
    asm("leave");
    asm("mov $0x0829fb8c, %eax");
    asm("jmp *%eax");
}

int CNetLayerPlayerInfo::AllKeysAuthed(unsigned long &)
{
    asm("leave");
    asm("mov $0x082ab744, %eax");
    asm("jmp *%eax");
}

void CNetLayerPlayerInfo::Initialize()
{
    asm("leave");
    asm("mov $0x082ab5b0, %eax");
    asm("jmp *%eax");
}

void CNetLayerPlayerInfo::SetCDKey(int, CExoString const &, CExoString const &)
{
    asm("leave");
    asm("mov $0x082ab7ac, %eax");
    asm("jmp *%eax");
}

int CNetLayerPlayerInfo::StartMstTimer(unsigned long long)
{
    asm("leave");
    asm("mov $0x082ab684, %eax");
    asm("jmp *%eax");
}

int CNetLayerPlayerInfo::UpdateMstTimer(unsigned long long)
{
    asm("leave");
    asm("mov $0x082ab6a8, %eax");
    asm("jmp *%eax");
}

