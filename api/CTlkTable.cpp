#include "CTlkTable.h"

void CTlkTable::ClearCustomTokens()
{
    asm("leave");
    asm("mov $0x082b636c, %eax");
    asm("jmp *%eax");
}

void CTlkTable::CloseFileAlternate()
{
    asm("leave");
    asm("mov $0x082b62e4, %eax");
    asm("jmp *%eax");
}

int CTlkTable::CloseFile(CTlkFile **)
{
    asm("leave");
    asm("mov $0x082b6284, %eax");
    asm("jmp *%eax");
}

int CTlkTable::ExoIsDBCSLeadByte(unsigned char)
{
    asm("leave");
    asm("mov $0x082b6348, %eax");
    asm("jmp *%eax");
}

int CTlkTable::FetchInternal(unsigned long, STR_RES &, int)
{
    asm("leave");
    asm("mov $0x082b4404, %eax");
    asm("jmp *%eax");
}

unsigned long CTlkTable::GetLanguageVersion()
{
    asm("leave");
    asm("mov $0x082b63c8, %eax");
    asm("jmp *%eax");
}

CExoString CTlkTable::GetSimpleString(unsigned long)
{
    asm("leave");
    asm("mov $0x082b4af8, %eax");
    asm("jmp *%eax");
}

void CTlkTable::GetTokenValue(CTlkTableToken const &, CExoString &)
{
    asm("leave");
    asm("mov $0x082b6474, %eax");
    asm("jmp *%eax");
}

int CTlkTable::OpenFileAlternate(CExoString const &)
{
    asm("leave");
    asm("mov $0x082b6350, %eax");
    asm("jmp *%eax");
}

int CTlkTable::OpenFile(CExoString)
{
    asm("leave");
    asm("mov $0x082b4ba0, %eax");
    asm("jmp *%eax");
}

int CTlkTable::OpenFile(CExoString const &, CTlkFile **)
{
    asm("leave");
    asm("mov $0x082b553c, %eax");
    asm("jmp *%eax");
}

void CTlkTable::ParseStr(CExoString &)
{
    asm("leave");
    asm("mov $0x082b5b24, %eax");
    asm("jmp *%eax");
}

int CTlkTable::RemapFontName(char *)
{
    asm("leave");
    asm("mov $0x082b432c, %eax");
    asm("jmp *%eax");
}

void CTlkTable::SetCustomToken(int, CExoString const &)
{
    asm("leave");
    asm("mov $0x082b58d4, %eax");
    asm("jmp *%eax");
}

int CTlkTable::SetUseLargeDialogFont(int)
{
    asm("leave");
    asm("mov $0x082b63ec, %eax");
    asm("jmp *%eax");
}

