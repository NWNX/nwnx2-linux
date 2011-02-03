#ifndef _CEXOALIASLIST_H_
#define _CEXOALIASLIST_H_
#include "nwndef.h"
#include "CExoString.h"

class CExoAliasList
{
public:
	int Add(CExoString, CExoString);
	int Clear();
	int Delete(CExoString);
	int GetAliasPath(CExoString const &, int) const;
	int ResolveFileName(CExoString const &, unsigned short) const;
	~CExoAliasList();
	CExoAliasList();

};
#endif
