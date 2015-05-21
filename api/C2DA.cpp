#include "C2DA.h"

int C2DA::GetCExoStringEntry(CExoString const &, CExoString const &, CExoString *)
{
    asm("leave");
    asm("mov $0x082bd000, %eax");
    asm("jmp *%eax");
}

int C2DA::GetCExoStringEntry(CExoString const &, int, CExoString *)
{
    asm("leave");
    asm("mov $0x082bee60, %eax");
    asm("jmp *%eax");
}

int C2DA::GetCExoStringEntry(int, CExoString const &, CExoString *)
{
    asm("leave");
    asm("mov $0x082bd0d4, %eax");
    asm("jmp *%eax");
}

int C2DA::GetCExoStringEntry(int, int, CExoString *)
{
    asm("leave");
    asm("mov $0x082bedbc, %eax");
    asm("jmp *%eax");
}

int C2DA::GetColumnIndex(CExoString const &)
{
    asm("leave");
    asm("mov $0x082bed74, %eax");
    asm("jmp *%eax");
}

int C2DA::GetFLOATEntry(CExoString const &, CExoString const &, float *)
{
    asm("leave");
    asm("mov $0x082bf038, %eax");
    asm("jmp *%eax");
}

int C2DA::GetFLOATEntry(CExoString const &, int, float *)
{
    asm("leave");
    asm("mov $0x082bf1c0, %eax");
    asm("jmp *%eax");
}

int C2DA::GetFLOATEntry(int, CExoString const &, float *)
{
    asm("leave");
    asm("mov $0x082bf100, %eax");
    asm("jmp *%eax");
}

int C2DA::GetFLOATEntry(int, int, float *)
{
    asm("leave");
    asm("mov $0x082befa4, %eax");
    asm("jmp *%eax");
}

int C2DA::GetINTEntry(CExoString const &, CExoString const &, int *)
{
    asm("leave");
    asm("mov $0x082bd8a8, %eax");
    asm("jmp *%eax");
}

int C2DA::GetINTEntry(CExoString const &, int, int *)
{
    asm("leave");
    asm("mov $0x082bdb58, %eax");
    asm("jmp *%eax");
}

int C2DA::GetINTEntry(int, CExoString const &, int *)
{
    asm("leave");
    asm("mov $0x082bda04, %eax");
    asm("jmp *%eax");
}

int C2DA::GetINTEntry(int, int, int *)
{
    asm("leave");
    asm("mov $0x082bd77c, %eax");
    asm("jmp *%eax");
}

int C2DA::GetNextLineLength(char *, unsigned long)
{
    asm("leave");
    asm("mov $0x082bf580, %eax");
    asm("jmp *%eax");
}

int C2DA::GetNextToken(char **, unsigned long *, char *, unsigned long *)
{
    asm("leave");
    asm("mov $0x082be0c0, %eax");
    asm("jmp *%eax");
}

int C2DA::GetNumColumns()
{
    asm("leave");
    asm("mov $0x082bf6d0, %eax");
    asm("jmp *%eax");
}

int C2DA::GetNumRows()
{
    asm("leave");
    asm("mov $0x082bf6dc, %eax");
    asm("jmp *%eax");
}

int C2DA::GetRowIndex(CExoString const &)
{
    asm("leave");
    asm("mov $0x082bf5a8, %eax");
    asm("jmp *%eax");
}

int C2DA::Load2DArray()
{
    asm("leave");
    asm("mov $0x082be1a8, %eax");
    asm("jmp *%eax");
}

int C2DA::SetBlankEntry(CExoString, CExoString)
{
    asm("leave");
    asm("mov $0x082bdebc, %eax");
    asm("jmp *%eax");
}

int C2DA::SetBlankEntry(CExoString, int)
{
    asm("leave");
    asm("mov $0x082bf4d4, %eax");
    asm("jmp *%eax");
}

int C2DA::SetBlankEntry(int, CExoString)
{
    asm("leave");
    asm("mov $0x082bdfec, %eax");
    asm("jmp *%eax");
}

int C2DA::SetBlankEntry(int, int)
{
    asm("leave");
    asm("mov $0x082bf488, %eax");
    asm("jmp *%eax");
}

int C2DA::SetCExoStringEntry(CExoString, CExoString, CExoString)
{
    asm("leave");
    asm("mov $0x082bd1a0, %eax");
    asm("jmp *%eax");
}

int C2DA::SetCExoStringEntry(CExoString, int, CExoString)
{
    asm("leave");
    asm("mov $0x082bd448, %eax");
    asm("jmp *%eax");
}

int C2DA::SetCExoStringEntry(int, CExoString, CExoString)
{
    asm("leave");
    asm("mov $0x082bd320, %eax");
    asm("jmp *%eax");
}

int C2DA::SetCExoStringEntry(int, int, CExoString)
{
    asm("leave");
    asm("mov $0x082bef04, %eax");
    asm("jmp *%eax");
}

int C2DA::SetFLOATEntry(CExoString, CExoString, float)
{
    asm("leave");
    asm("mov $0x082bd544, %eax");
    asm("jmp *%eax");
}

int C2DA::SetFLOATEntry(CExoString, int, float)
{
    asm("leave");
    asm("mov $0x082bf28c, %eax");
    asm("jmp *%eax");
}

int C2DA::SetFLOATEntry(int, CExoString, float)
{
    asm("leave");
    asm("mov $0x082bd68c, %eax");
    asm("jmp *%eax");
}

int C2DA::SetFLOATEntry(int, int, float)
{
    asm("leave");
    asm("mov $0x082bf224, %eax");
    asm("jmp *%eax");
}

int C2DA::SetINTEntry(CExoString, CExoString, int)
{
    asm("leave");
    asm("mov $0x082bdc8c, %eax");
    asm("jmp *%eax");
}

int C2DA::SetINTEntry(CExoString, int, int)
{
    asm("leave");
    asm("mov $0x082bf3c0, %eax");
    asm("jmp *%eax");
}

int C2DA::SetINTEntry(int, CExoString, int)
{
    asm("leave");
    asm("mov $0x082bddd0, %eax");
    asm("jmp *%eax");
}

int C2DA::SetINTEntry(int, int, int)
{
    asm("leave");
    asm("mov $0x082bf35c, %eax");
    asm("jmp *%eax");
}

int C2DA::SkipNewLines(char **, unsigned long *)
{
    asm("leave");
    asm("mov $0x082bf5f0, %eax");
    asm("jmp *%eax");
}

void C2DA::Unload2DArray()
{
    asm("leave");
    asm("mov $0x082bea88, %eax");
    asm("jmp *%eax");
}

