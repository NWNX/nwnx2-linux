#ifndef _CEXOINIINTERNAL_H_
#define _CEXOINIINTERNAL_H_
#include "nwndef.h"

class CExoIniInternal
{
public:
    int ReadIniEntry(CExoString &, CExoString const &, CExoString const &, CExoString const &);
    int WriteIniEntry(CExoString const &, CExoString const &, CExoString const &, CExoString const &);
    ~CExoIniInternal();
    CExoIniInternal();

};
#endif
