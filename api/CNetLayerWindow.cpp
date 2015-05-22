#include "CNetLayerWindow.h"

int CNetLayerWindow::AddToHighOutgoingQueue(unsigned short)
{
    asm("leave");
    asm("mov $0x082ab1b8, %eax");
    asm("jmp *%eax");
}

int CNetLayerWindow::AddToLowOutgoingQueue(unsigned short)
{
    asm("leave");
    asm("mov $0x082ab228, %eax");
    asm("jmp *%eax");
}

void CNetLayerWindow::CutOutgoingBufferSize()
{
    asm("leave");
    asm("mov $0x0829f4cc, %eax");
    asm("jmp *%eax");
}

int CNetLayerWindow::DoubleOutgoingBufferSize()
{
    asm("leave");
    asm("mov $0x082ab594, %eax");
    asm("jmp *%eax");
}

int CNetLayerWindow::FauxNagle()
{
    asm("leave");
    asm("mov $0x0829f068, %eax");
    asm("jmp *%eax");
}

int CNetLayerWindow::FrameNumberBetween(unsigned long, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x082ab308, %eax");
    asm("jmp *%eax");
}

int CNetLayerWindow::FrameReceive(unsigned char *, unsigned long)
{
    asm("leave");
    asm("mov $0x0829ea4c, %eax");
    asm("jmp *%eax");
}

void CNetLayerWindow::FrameSend(unsigned char, unsigned short, unsigned short)
{
    asm("leave");
    asm("mov $0x0829e8bc, %eax");
    asm("jmp *%eax");
}

int CNetLayerWindow::FrameTimeout(unsigned long)
{
    asm("leave");
    asm("mov $0x0829ee40, %eax");
    asm("jmp *%eax");
}

void CNetLayerWindow::InitializeCompressionBuffers()
{
    asm("leave");
    asm("mov $0x0829e6ac, %eax");
    asm("jmp *%eax");
}

void CNetLayerWindow::Initialize(CNetLayerInternal *)
{
    asm("leave");
    asm("mov $0x0829e390, %eax");
    asm("jmp *%eax");
}

void CNetLayerWindow::LoadWindowWithFrames()
{
    asm("leave");
    asm("mov $0x0829e7b0, %eax");
    asm("jmp *%eax");
}

int CNetLayerWindow::PlaceFrameInOutgoingBuffers(unsigned short)
{
    asm("leave");
    asm("mov $0x082ab2b4, %eax");
    asm("jmp *%eax");
}

int CNetLayerWindow::SetAckTimer()
{
    asm("leave");
    asm("mov $0x082ab3d4, %eax");
    asm("jmp *%eax");
}

int CNetLayerWindow::SetFauxNagleTimer()
{
    asm("leave");
    asm("mov $0x082ab430, %eax");
    asm("jmp *%eax");
}

int CNetLayerWindow::SetInFrameTimer()
{
    asm("leave");
    asm("mov $0x082ab338, %eax");
    asm("jmp *%eax");
}

int CNetLayerWindow::SetOutFrameTimer(unsigned long)
{
    asm("leave");
    asm("mov $0x082ab4f4, %eax");
    asm("jmp *%eax");
}

void CNetLayerWindow::ShutDown()
{
    asm("leave");
    asm("mov $0x0829e4cc, %eax");
    asm("jmp *%eax");
}

int CNetLayerWindow::TestAckTimer(unsigned long)
{
    asm("leave");
    asm("mov $0x082ab410, %eax");
    asm("jmp *%eax");
}

int CNetLayerWindow::TestFauxNagleTimer(unsigned long)
{
    asm("leave");
    asm("mov $0x082ab46c, %eax");
    asm("jmp *%eax");
}

int CNetLayerWindow::TestInFrameTimer(unsigned long)
{
    asm("leave");
    asm("mov $0x082ab394, %eax");
    asm("jmp *%eax");
}

int CNetLayerWindow::TestOutFrameTimer(unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x082ab550, %eax");
    asm("jmp *%eax");
}

int CNetLayerWindow::UnpacketizeFullMessages(int)
{
    asm("leave");
    asm("mov $0x0829f0f0, %eax");
    asm("jmp *%eax");
}

