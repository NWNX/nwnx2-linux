#include "CNWMessage.h"

void CNWMessage::ClearReadMessage()
{
    asm("leave");
    asm("mov $0x080c33a8, %eax");
    asm("jmp *%eax");
}

void CNWMessage::CreateWriteMessage(unsigned long, unsigned long, int)
{
    asm("leave");
    asm("mov $0x080c3aec, %eax");
    asm("jmp *%eax");
}

void CNWMessage::ExtendWriteBuffer(unsigned long)
{
    asm("leave");
    asm("mov $0x080c3b50, %eax");
    asm("jmp *%eax");
}

void CNWMessage::ExtendWriteFragmentsBuffer(unsigned long)
{
    asm("leave");
    asm("mov $0x080c3ba0, %eax");
    asm("jmp *%eax");
}

int CNWMessage::GetObjectLookupTable()
{
    asm("leave");
    asm("mov $0x080c4344, %eax");
    asm("jmp *%eax");
}

int CNWMessage::GetWriteMessage(unsigned char **, unsigned long *)
{
    asm("leave");
    asm("mov $0x080c2e54, %eax");
    asm("jmp *%eax");
}

int CNWMessage::MessageMoreDataToRead()
{
    asm("leave");
    asm("mov $0x080c3abc, %eax");
    asm("jmp *%eax");
}

int CNWMessage::MessageReadOverflow(int)
{
    asm("leave");
    asm("mov $0x080c3a64, %eax");
    asm("jmp *%eax");
}

int CNWMessage::MessageReadUnderflow(int)
{
    asm("leave");
    asm("mov $0x080c3a8c, %eax");
    asm("jmp *%eax");
}

unsigned long CNWMessage::PeekAtWriteMessageSize()
{
    asm("leave");
    asm("mov $0x080c42d8, %eax");
    asm("jmp *%eax");
}

int CNWMessage::ReadBOOL()
{
    asm("leave");
    asm("mov $0x080c3570, %eax");
    asm("jmp *%eax");
}

unsigned char CNWMessage::ReadBYTE(int)
{
    asm("leave");
    asm("mov $0x080c3588, %eax");
    asm("jmp *%eax");
}

int CNWMessage::ReadBit(unsigned char)
{
    asm("leave");
    asm("mov $0x080c33c4, %eax");
    asm("jmp *%eax");
}

__int64 CNWMessage::ReadBits(int)
{
    asm("leave");
    asm("mov $0x080c33f0, %eax");
    asm("jmp *%eax");
}

CExoString CNWMessage::ReadCExoString(int)
{
    asm("leave");
    asm("mov $0x080c2954, %eax");
    asm("jmp *%eax");
}

char CNWMessage::ReadCHAR(int)
{
    asm("leave");
    asm("mov $0x080c35d4, %eax");
    asm("jmp *%eax");
}

CResRef CNWMessage::ReadCResRef(int)
{
    asm("leave");
    asm("mov $0x080c39d4, %eax");
    asm("jmp *%eax");
}

int CNWMessage::ReadDOUBLE(double, double, int)
{
    asm("leave");
    asm("mov $0x080c395c, %eax");
    asm("jmp *%eax");
}

int CNWMessage::ReadDOUBLE(double, int)
{
    asm("leave");
    asm("mov $0x080c38ec, %eax");
    asm("jmp *%eax");
}

int CNWMessage::ReadDWORD64(int)
{
    asm("leave");
    asm("mov $0x080c376c, %eax");
    asm("jmp *%eax");
}

unsigned long CNWMessage::ReadDWORD(int)
{
    asm("leave");
    asm("mov $0x080c36cc, %eax");
    asm("jmp *%eax");
}

int CNWMessage::ReadFLOAT(float, float, int)
{
    asm("leave");
    asm("mov $0x080c3874, %eax");
    asm("jmp *%eax");
}

float CNWMessage::ReadFLOAT(float, int)
{
    asm("leave");
    asm("mov $0x080c37fc, %eax");
    asm("jmp *%eax");
}

int CNWMessage::ReadINT64(int)
{
    asm("leave");
    asm("mov $0x080c37b4, %eax");
    asm("jmp *%eax");
}

int CNWMessage::ReadINT(int)
{
    asm("leave");
    asm("mov $0x080c3710, %eax");
    asm("jmp *%eax");
}

int CNWMessage::ReadSHORT(int)
{
    asm("leave");
    asm("mov $0x080c3670, %eax");
    asm("jmp *%eax");
}

int CNWMessage::ReadSigned(int)
{
    asm("leave");
    asm("mov $0x080c2888, %eax");
    asm("jmp *%eax");
}

unsigned __int64 CNWMessage::ReadUnsigned(int)
{
    asm("leave");
    asm("mov $0x080c2640, %eax");
    asm("jmp *%eax");
}

void * CNWMessage::ReadVOIDPtr(int)
{
    asm("leave");
    asm("mov $0x080c3a40, %eax");
    asm("jmp *%eax");
}

unsigned short CNWMessage::ReadWORD(int)
{
    asm("leave");
    asm("mov $0x080c362c, %eax");
    asm("jmp *%eax");
}

void CNWMessage::SetReadMessage(unsigned char *, unsigned long, unsigned long, int)
{
    asm("leave");
    asm("mov $0x080c3328, %eax");
    asm("jmp *%eax");
}

void CNWMessage::WriteBOOL(int)
{
    asm("leave");
    asm("mov $0x080c3c08, %eax");
    asm("jmp *%eax");
}

void CNWMessage::WriteBYTE(unsigned char, int)
{
    asm("leave");
    asm("mov $0x080c3c24, %eax");
    asm("jmp *%eax");
}

void CNWMessage::WriteBit(unsigned char)
{
    asm("leave");
    asm("mov $0x080c3484, %eax");
    asm("jmp *%eax");
}

int CNWMessage::WriteBits(unsigned long long, int)
{
    asm("leave");
    asm("mov $0x080c34d0, %eax");
    asm("jmp *%eax");
}

void CNWMessage::WriteCExoString(CExoString, int)
{
    asm("leave");
    asm("mov $0x080c2d04, %eax");
    asm("jmp *%eax");
}

void CNWMessage::WriteCHAR(char, int)
{
    asm("leave");
    asm("mov $0x080c3cb4, %eax");
    asm("jmp *%eax");
}

void CNWMessage::WriteCResRef(CResRef, int)
{
    asm("leave");
    asm("mov $0x080c2c74, %eax");
    asm("jmp *%eax");
}

int CNWMessage::WriteDOUBLE(double, double, double, int)
{
    asm("leave");
    asm("mov $0x080c2b48, %eax");
    asm("jmp *%eax");
}

int CNWMessage::WriteDOUBLE(double, double, int)
{
    asm("leave");
    asm("mov $0x080c4188, %eax");
    asm("jmp *%eax");
}

int CNWMessage::WriteDWORD64(unsigned long long, int)
{
    asm("leave");
    asm("mov $0x080c3f90, %eax");
    asm("jmp *%eax");
}

void CNWMessage::WriteDWORD(unsigned long, int)
{
    asm("leave");
    asm("mov $0x080c3e74, %eax");
    asm("jmp *%eax");
}

void CNWMessage::WriteFLOAT(float, float, float, int)
{
    asm("leave");
    asm("mov $0x080c2a44, %eax");
    asm("jmp *%eax");
}

void CNWMessage::WriteFLOAT(float, float, int)
{
    asm("leave");
    asm("mov $0x080c40c8, %eax");
    asm("jmp *%eax");
}

int CNWMessage::WriteINT64(long long, int)
{
    asm("leave");
    asm("mov $0x080c402c, %eax");
    asm("jmp *%eax");
}

void CNWMessage::WriteINT(int, int)
{
    asm("leave");
    asm("mov $0x080c3f00, %eax");
    asm("jmp *%eax");
}

void CNWMessage::WriteSHORT(short, int)
{
    asm("leave");
    asm("mov $0x080c3ddc, %eax");
    asm("jmp *%eax");
}

int CNWMessage::WriteSigned(long long, int)
{
    asm("leave");
    asm("mov $0x080c24f0, %eax");
    asm("jmp *%eax");
}

int CNWMessage::WriteUnsigned(unsigned long long, int)
{
    asm("leave");
    asm("mov $0x080c231c, %eax");
    asm("jmp *%eax");
}

void CNWMessage::WriteVOIDPtr(void *, int)
{
    asm("leave");
    asm("mov $0x080c4258, %eax");
    asm("jmp *%eax");
}

void CNWMessage::WriteWORD(unsigned short, int)
{
    asm("leave");
    asm("mov $0x080c3d44, %eax");
    asm("jmp *%eax");
}

