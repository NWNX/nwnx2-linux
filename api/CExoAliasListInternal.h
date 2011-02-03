#ifndef _CEXOALIASLISTINTERNAL_H_
#define _CEXOALIASLISTINTERNAL_H_
#include "nwndef.h"
#include "CExoString.h"

class CExoAliasListInternal
{
public:
	int Add(CExoString, CExoString);
	int Clear();
	int Delete(CExoString);
	int GetAliasPath(CExoString const &, int) const;
	int ResolveFileName(CExoString const &, unsigned short) const;
	~CExoAliasListInternal();
	CExoAliasListInternal();

};
#endif
