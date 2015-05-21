#include "CNetworkProfiler.h"

void CNetworkProfiler::AddMessageToFrameProfile(unsigned char, unsigned long)
{
    asm("leave");
    asm("mov $0x082c6c3c, %eax");
    asm("jmp *%eax");
}

void CNetworkProfiler::AddMessageToProfile(unsigned char, unsigned char, unsigned char, unsigned long)
{
    asm("leave");
    asm("mov $0x082c6a54, %eax");
    asm("jmp *%eax");
}

int CNetworkProfiler::GetFrameLastTime()
{
    asm("leave");
    asm("mov $0x082c7210, %eax");
    asm("jmp *%eax");
}

int CNetworkProfiler::GetFrameStartTime()
{
    asm("leave");
    asm("mov $0x082c71c8, %eax");
    asm("jmp *%eax");
}

int CNetworkProfiler::GetLastTime()
{
    asm("leave");
    asm("mov $0x082c71ec, %eax");
    asm("jmp *%eax");
}

int CNetworkProfiler::GetStartTime()
{
    asm("leave");
    asm("mov $0x082c71a4, %eax");
    asm("jmp *%eax");
}

void CNetworkProfiler::OutputReport()
{
    asm("leave");
    asm("mov $0x082c6748, %eax");
    asm("jmp *%eax");
}

int CNetworkProfiler::SetOutputFilename(char *)
{
    asm("leave");
    asm("mov $0x082c715c, %eax");
    asm("jmp *%eax");
}

int CNetworkProfiler::SetState(int)
{
    asm("leave");
    asm("mov $0x082c6538, %eax");
    asm("jmp *%eax");
}

