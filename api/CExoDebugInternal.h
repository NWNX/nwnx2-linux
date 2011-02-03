#ifndef _CEXODEBUGINTERNAL_H_
#define _CEXODEBUGINTERNAL_H_
#include "nwndef.h"
#include "CExoString.h"

class CExoDebugInternal
{
public:
	int Assert(int, char *, char const *);
	int CloseLogFiles();
	int CreateDirectory(CExoString);
	int FlushErrorFile();
	int FlushLogFile();
	int GetCurrentTimestamp(CExoString &);
	int OpenLogFiles(CExoString, int);
	int Warning(int, char *, char const *);
	int WriteToErrorFile(CExoString const &);
	int WriteToLogFile(CExoString const &);
	~CExoDebugInternal();
	CExoDebugInternal();

};
#endif
