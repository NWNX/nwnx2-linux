#include "CResTGA.h"

int CResTGA::CopyTGAData(unsigned char *)
{
    asm("leave");
    asm("mov $0x082bcea4, %eax");
    asm("jmp *%eax");
}

int CResTGA::GetTGAAttrib(unsigned long *, unsigned long *, unsigned char *)
{
    asm("leave");
    asm("mov $0x082bced4, %eax");
    asm("jmp *%eax");
}

int CResTGA::GetTGAColorMapPtr()
{
    asm("leave");
    asm("mov $0x082bcf0c, %eax");
    asm("jmp *%eax");
}

int CResTGA::GetTGADataPtr()
{
    asm("leave");
    asm("mov $0x082bcf18, %eax");
    asm("jmp *%eax");
}

int CResTGA::GetTGAHeaderPtr()
{
    asm("leave");
    asm("mov $0x082bcf24, %eax");
    asm("jmp *%eax");
}

int CResTGA::GetTGASize()
{
    asm("leave");
    asm("mov $0x082bcf30, %eax");
    asm("jmp *%eax");
}

int CResTGA::IsColorMapped()
{
    asm("leave");
    asm("mov $0x082bcf3c, %eax");
    asm("jmp *%eax");
}

int CResTGA::IsCompressed()
{
    asm("leave");
    asm("mov $0x082bcf48, %eax");
    asm("jmp *%eax");
}

int CResTGA::IsLoaded()
{
    asm("leave");
    asm("mov $0x082bcf54, %eax");
    asm("jmp *%eax");
}

int CResTGA::OnResourceFreed()
{
    asm("leave");
    asm("mov $0x082bcf60, %eax");
    asm("jmp *%eax");
}

int CResTGA::OnResourceServiced()
{
    asm("leave");
    asm("mov $0x082bc778, %eax");
    asm("jmp *%eax");
}

int CResTGA::ReadColorMappedRLETGA()
{
    asm("leave");
    asm("mov $0x082bcb74, %eax");
    asm("jmp *%eax");
}

int CResTGA::ReadUnmappedRLETGA()
{
    asm("leave");
    asm("mov $0x082bcc28, %eax");
    asm("jmp *%eax");
}

int CResTGA::Write(CExoString &)
{
    asm("leave");
    asm("mov $0x082bc9bc, %eax");
    asm("jmp *%eax");
}

