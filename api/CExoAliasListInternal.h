#ifndef _CEXOALIASLISTINTERNAL_H_
#define _CEXOALIASLISTINTERNAL_H_
#include "nwndef.h"
#include "CExoString.h"

class CExoAliasListInternal
{
public:
    void Add(CExoString, CExoString);
    int Clear();
    void Delete(CExoString);
    CExoString const & GetAliasPath(CExoString const &, int) const;
    CExoString ResolveFileName(CExoString const &, unsigned short) const;
    ~CExoAliasListInternal();
    CExoAliasListInternal();

};
#endif
