#ifndef _CEXODEBUG_H_
#define _CEXODEBUG_H_
#include "nwndef.h"
#include "CExoString.h"

class CExoDebug
{
public:
	int Assert(int, char *, char const *);
	int CloseLogFiles();
	int FlushErrorFile();
	int FlushLogFile();
	int GetCurrentAllocatedMemory();
	int GetCurrentMemoryAllocations();
	int GetCurrentTimestamp(CExoString &);
	int GetMaxAllocatedMemory();
	int GetTotalMemoryAllocations();
	int OpenLogFiles(CExoString, int);
	int SetRotateLogFile(int);
	int Warning(int, char *, char const *);
	int WriteToErrorFile(CExoString const &);
	int WriteToLogFile(CExoString const &);
	~CExoDebug();
	CExoDebug();

};
#endif
