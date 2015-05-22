#include "CNWSAmbientSound.h"

int CNWSAmbientSound::GetPlayersInArea(CExoArrayList<unsigned long> *)
{
    asm("leave");
    asm("mov $0x0823a884, %eax");
    asm("jmp *%eax");
}

int CNWSAmbientSound::Load(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x0823a970, %eax");
    asm("jmp *%eax");
}

void CNWSAmbientSound::PackIntoMessage(CNWSMessage *)
{
    asm("leave");
    asm("mov $0x0823abac, %eax");
    asm("jmp *%eax");
}

void CNWSAmbientSound::PlayAmbientSound(int)
{
    asm("leave");
    asm("mov $0x0823a530, %eax");
    asm("jmp *%eax");
}

void CNWSAmbientSound::PlayBattleMusic(int)
{
    asm("leave");
    asm("mov $0x0823a3e8, %eax");
    asm("jmp *%eax");
}

void CNWSAmbientSound::PlayMusic(int)
{
    asm("leave");
    asm("mov $0x0823a160, %eax");
    asm("jmp *%eax");
}

void CNWSAmbientSound::Save(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x0823ab08, %eax");
    asm("jmp *%eax");
}

void CNWSAmbientSound::SetAmbientDayTrack(int)
{
    asm("leave");
    asm("mov $0x0823a5cc, %eax");
    asm("jmp *%eax");
}

void CNWSAmbientSound::SetAmbientDayVolume(int)
{
    asm("leave");
    asm("mov $0x0823a71c, %eax");
    asm("jmp *%eax");
}

void CNWSAmbientSound::SetAmbientNightTrack(int)
{
    asm("leave");
    asm("mov $0x0823a674, %eax");
    asm("jmp *%eax");
}

void CNWSAmbientSound::SetAmbientNightVolume(int)
{
    asm("leave");
    asm("mov $0x0823a7d0, %eax");
    asm("jmp *%eax");
}

void CNWSAmbientSound::SetBattleMusicTrack(int)
{
    asm("leave");
    asm("mov $0x0823a48c, %eax");
    asm("jmp *%eax");
}

void CNWSAmbientSound::SetMusicDayTrack(int)
{
    asm("leave");
    asm("mov $0x0823a2a0, %eax");
    asm("jmp *%eax");
}

void CNWSAmbientSound::SetMusicDelay(int)
{
    asm("leave");
    asm("mov $0x0823a1fc, %eax");
    asm("jmp *%eax");
}

void CNWSAmbientSound::SetMusicNightTrack(int)
{
    asm("leave");
    asm("mov $0x0823a340, %eax");
    asm("jmp *%eax");
}

