#ifndef _CEXOINI_H_
#define _CEXOINI_H_
#include "nwndef.h"

class CExoIni
{
public:
    int ReadIniEntry(CExoString &, CExoString const &, CExoString const &, CExoString const &);
    int WriteIniEntry(CExoString const &, CExoString const &, CExoString const &, CExoString const &);
    ~CExoIni();
    CExoIni();

};
#endif
