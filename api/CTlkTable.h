#ifndef _CTLKTABLE_H_
#define _CTLKTABLE_H_
#include "nwndef.h"
#include "CExoString.h"

class CTlkTable
{
public:
	int ClearCustomTokens();
	int CloseFileAlternate();
	int CloseFile(CTlkFile **);
	int ExoIsDBCSLeadByte(unsigned char);
	int FetchInternal(unsigned long, STR_RES &, int);
	int GetLanguageVersion();
	int GetSimpleString(unsigned long);
	int GetTokenValue(CTlkTableToken const &, CExoString &);
	int OpenFileAlternate(CExoString const &);
	int OpenFile(CExoString);
	int OpenFile(CExoString const &, CTlkFile **);
	int ParseStr(CExoString &);
	int RemapFontName(char *);
	int SetCustomToken(int, CExoString const &);
	int SetUseLargeDialogFont(int);
	~CTlkTable();
	CTlkTable();

};
#endif
