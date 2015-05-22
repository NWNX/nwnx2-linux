#ifndef _CEXODEBUGINTERNAL_H_
#define _CEXODEBUGINTERNAL_H_
#include "nwndef.h"
#include "CExoString.h"

class CExoDebugInternal
{
public:
    int Assert(int, char *, char const *);
    void CloseLogFiles();
    int CreateDirectory(CExoString);
    int FlushErrorFile();
    void FlushLogFile();
    void GetCurrentTimestamp(CExoString &);
    void OpenLogFiles(CExoString, int);
    int Warning(int, char *, char const *);
    int WriteToErrorFile(CExoString const &);
    void WriteToLogFile(CExoString const &);
    ~CExoDebugInternal();
    CExoDebugInternal();

};
#endif
