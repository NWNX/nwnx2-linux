#ifndef _CTLKTABLE_H_
#define _CTLKTABLE_H_
#include "nwndef.h"
#include "CExoString.h"

class CTlkTable
{
public:
    void ClearCustomTokens();
    void CloseFileAlternate();
    int CloseFile(CTlkFile **);
    static int ExoIsDBCSLeadByte(unsigned char);
    int FetchInternal(unsigned long, STR_RES &, int);
    unsigned long GetLanguageVersion();
    CExoString GetSimpleString(unsigned long);
    void GetTokenValue(CTlkTableToken const &, CExoString &);
    int OpenFileAlternate(CExoString const &);
    int OpenFile(CExoString);
    int OpenFile(CExoString const &, CTlkFile **);
    void ParseStr(CExoString &);
    int RemapFontName(char *);
    void SetCustomToken(int, CExoString const &);
    int SetUseLargeDialogFont(int);
    ~CTlkTable();
    CTlkTable();

};
#endif
