#include "CNWSSoundObject.h"

void CNWSSoundObject::AIUpdate()
{
    asm("leave");
    asm("mov $0x081e9994, %eax");
    asm("jmp *%eax");
}

void CNWSSoundObject::AddToArea(CNWSArea *, int)
{
    asm("leave");
    asm("mov $0x081e99a4, %eax");
    asm("jmp *%eax");
}

CNWSSoundObject * CNWSSoundObject::AsNWSSoundObject()
{
    asm("leave");
    asm("mov $0x081e9b28, %eax");
    asm("jmp *%eax");
}

void CNWSSoundObject::ChangePosition(Vector)
{
    asm("leave");
    asm("mov $0x081e97b4, %eax");
    asm("jmp *%eax");
}

void CNWSSoundObject::ChangeVolume(int)
{
    asm("leave");
    asm("mov $0x081e96bc, %eax");
    asm("jmp *%eax");
}

void CNWSSoundObject::EventHandler(unsigned long, unsigned long, void *, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x081e999c, %eax");
    asm("jmp *%eax");
}

int CNWSSoundObject::GetContinuous()
{
    asm("leave");
    asm("mov $0x081e9d68, %eax");
    asm("jmp *%eax");
}

int CNWSSoundObject::GetHours()
{
    asm("leave");
    asm("mov $0x081e9d08, %eax");
    asm("jmp *%eax");
}

int CNWSSoundObject::GetIntervalVariance()
{
    asm("leave");
    asm("mov $0x081e9d38, %eax");
    asm("jmp *%eax");
}

int CNWSSoundObject::GetInterval()
{
    asm("leave");
    asm("mov $0x081e9d28, %eax");
    asm("jmp *%eax");
}

int CNWSSoundObject::GetIsActive()
{
    asm("leave");
    asm("mov $0x081e9c98, %eax");
    asm("jmp *%eax");
}

int CNWSSoundObject::GetLooping()
{
    asm("leave");
    asm("mov $0x081e9cb8, %eax");
    asm("jmp *%eax");
}

int CNWSSoundObject::GetMaxDistance()
{
    asm("leave");
    asm("mov $0x081e9d58, %eax");
    asm("jmp *%eax");
}

int CNWSSoundObject::GetMinDistance()
{
    asm("leave");
    asm("mov $0x081e9d48, %eax");
    asm("jmp *%eax");
}

int CNWSSoundObject::GetPeopleInSoundRange()
{
    asm("leave");
    asm("mov $0x081e9a54, %eax");
    asm("jmp *%eax");
}

int CNWSSoundObject::GetPitchVariation()
{
    asm("leave");
    asm("mov $0x081e9cf8, %eax");
    asm("jmp *%eax");
}

int CNWSSoundObject::GetPositional()
{
    asm("leave");
    asm("mov $0x081e9ca8, %eax");
    asm("jmp *%eax");
}

int CNWSSoundObject::GetPriority()
{
    asm("leave");
    asm("mov $0x081e9d18, %eax");
    asm("jmp *%eax");
}

int CNWSSoundObject::GetRandomPosition()
{
    asm("leave");
    asm("mov $0x081e9db0, %eax");
    asm("jmp *%eax");
}

int CNWSSoundObject::GetRandomXRange()
{
    asm("leave");
    asm("mov $0x081e9dc0, %eax");
    asm("jmp *%eax");
}

int CNWSSoundObject::GetRandomYRange()
{
    asm("leave");
    asm("mov $0x081e9dd0, %eax");
    asm("jmp *%eax");
}

int CNWSSoundObject::GetRandom()
{
    asm("leave");
    asm("mov $0x081e9d78, %eax");
    asm("jmp *%eax");
}

int CNWSSoundObject::GetSoundList()
{
    asm("leave");
    asm("mov $0x081e9d88, %eax");
    asm("jmp *%eax");
}

int CNWSSoundObject::GetTimeofDay()
{
    asm("leave");
    asm("mov $0x081e9ce8, %eax");
    asm("jmp *%eax");
}

int CNWSSoundObject::GetVolumeVariation()
{
    asm("leave");
    asm("mov $0x081e9cd8, %eax");
    asm("jmp *%eax");
}

int CNWSSoundObject::GetVolume()
{
    asm("leave");
    asm("mov $0x081e9cc8, %eax");
    asm("jmp *%eax");
}

int CNWSSoundObject::Load(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x081e8a0c, %eax");
    asm("jmp *%eax");
}

void CNWSSoundObject::PackIntoMessage(CNWSMessage *)
{
    asm("leave");
    asm("mov $0x081e929c, %eax");
    asm("jmp *%eax");
}

void CNWSSoundObject::Play()
{
    asm("leave");
    asm("mov $0x081e9524, %eax");
    asm("jmp *%eax");
}

int CNWSSoundObject::RemoveFromArea()
{
    asm("leave");
    asm("mov $0x081e9a10, %eax");
    asm("jmp *%eax");
}

void CNWSSoundObject::Save(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x081e8fd4, %eax");
    asm("jmp *%eax");
}

int CNWSSoundObject::SetContinuous(int)
{
    asm("leave");
    asm("mov $0x081e9c34, %eax");
    asm("jmp *%eax");
}

int CNWSSoundObject::SetHours(unsigned long)
{
    asm("leave");
    asm("mov $0x081e9bbc, %eax");
    asm("jmp *%eax");
}

int CNWSSoundObject::SetIntervalVariance(unsigned long)
{
    asm("leave");
    asm("mov $0x081e9bf8, %eax");
    asm("jmp *%eax");
}

int CNWSSoundObject::SetInterval(unsigned long)
{
    asm("leave");
    asm("mov $0x081e9be4, %eax");
    asm("jmp *%eax");
}

int CNWSSoundObject::SetIsActive(int)
{
    asm("leave");
    asm("mov $0x081e9b30, %eax");
    asm("jmp *%eax");
}

int CNWSSoundObject::SetLooping(int)
{
    asm("leave");
    asm("mov $0x081e9b58, %eax");
    asm("jmp *%eax");
}

int CNWSSoundObject::SetMaxDistance(float)
{
    asm("leave");
    asm("mov $0x081e9c20, %eax");
    asm("jmp *%eax");
}

int CNWSSoundObject::SetMinDistance(float)
{
    asm("leave");
    asm("mov $0x081e9c0c, %eax");
    asm("jmp *%eax");
}

int CNWSSoundObject::SetPitchVariation(float)
{
    asm("leave");
    asm("mov $0x081e9ba8, %eax");
    asm("jmp *%eax");
}

int CNWSSoundObject::SetPositional(int)
{
    asm("leave");
    asm("mov $0x081e9b44, %eax");
    asm("jmp *%eax");
}

int CNWSSoundObject::SetPriority(unsigned char)
{
    asm("leave");
    asm("mov $0x081e9bd0, %eax");
    asm("jmp *%eax");
}

int CNWSSoundObject::SetRandomPosition(int)
{
    asm("leave");
    asm("mov $0x081e9c5c, %eax");
    asm("jmp *%eax");
}

int CNWSSoundObject::SetRandomXRange(float)
{
    asm("leave");
    asm("mov $0x081e9c70, %eax");
    asm("jmp *%eax");
}

int CNWSSoundObject::SetRandomYRange(float)
{
    asm("leave");
    asm("mov $0x081e9c84, %eax");
    asm("jmp *%eax");
}

int CNWSSoundObject::SetRandom(int)
{
    asm("leave");
    asm("mov $0x081e9c48, %eax");
    asm("jmp *%eax");
}

int CNWSSoundObject::SetTimeofDay(CNWSSoundObjectTimeOfDay)
{
    asm("leave");
    asm("mov $0x081e9b94, %eax");
    asm("jmp *%eax");
}

int CNWSSoundObject::SetVolumeVariation(int)
{
    asm("leave");
    asm("mov $0x081e9b80, %eax");
    asm("jmp *%eax");
}

int CNWSSoundObject::SetVolume(int)
{
    asm("leave");
    asm("mov $0x081e9b6c, %eax");
    asm("jmp *%eax");
}

void CNWSSoundObject::Stop()
{
    asm("leave");
    asm("mov $0x081e95f0, %eax");
    asm("jmp *%eax");
}

