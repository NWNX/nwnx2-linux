#ifndef _CEXOALIASLIST_H_
#define _CEXOALIASLIST_H_
#include "nwndef.h"
#include "CExoString.h"

class CExoAliasList
{
public:
    void Add(CExoString, CExoString);
    int Clear();
    void Delete(CExoString);
    CExoString const & GetAliasPath(CExoString const &, int) const;
    CExoString ResolveFileName(CExoString const &, unsigned short) const;
    ~CExoAliasList();
    CExoAliasList();

};
#endif
