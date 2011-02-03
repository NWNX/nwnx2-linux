#ifndef _CEXOBASEINTERNAL_H_
#define _CEXOBASEINTERNAL_H_
#include "nwndef.h"
#include "CExoString.h"
#include "CExoArrayList.h"

class CExoBaseInternal
{
public:
	int AddAlias(CExoString, CExoString, CExoString);
	int CheckForCD(unsigned long);
	int CreateResourceExtensionTable();
	int GetAugmentedDirectoryList(CExoArrayList<CFileInfo> *, CExoString, unsigned short, int);
	int GetDirectoryList(CExoArrayList<CExoString> *, CExoString, unsigned short, int, int);
	int GetResTypeFromExtension(CExoString const &);
	int GetResourceExtension(unsigned short);
	int LoadAliases(CExoString);
	int ShutDown();
	int SpawnExternalApplication(CExoString const &, CExoString const &, int);
	~CExoBaseInternal();
	CExoBaseInternal();

};
#endif
