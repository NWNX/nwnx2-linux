#ifndef _CEXODEBUG_H_
#define _CEXODEBUG_H_
#include "nwndef.h"
#include "CExoString.h"

class CExoDebug
{
public:
    int Assert(int, char *, char const *);
    int CloseLogFiles();
    void FlushErrorFile();
    void FlushLogFile();
    int GetCurrentAllocatedMemory();
    int GetCurrentMemoryAllocations();
    void GetCurrentTimestamp(CExoString &);
    int GetMaxAllocatedMemory();
    int GetTotalMemoryAllocations();
    void OpenLogFiles(CExoString, int);
    void SetRotateLogFile(int);
    void Warning(int, char *, char const *);
    void WriteToErrorFile(CExoString const &);
    void WriteToLogFile(CExoString const &);
    ~CExoDebug();
    CExoDebug();

};
#endif
