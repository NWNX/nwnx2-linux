#ifndef _CEXOBASEINTERNAL_H_
#define _CEXOBASEINTERNAL_H_
#include "nwndef.h"
#include "CExoString.h"
#include "CExoArrayList.h"

class CExoBaseInternal
{
public:
    void AddAlias(CExoString, CExoString, CExoString);
    int CheckForCD(unsigned long);
    void CreateResourceExtensionTable();
    int GetAugmentedDirectoryList(CExoArrayList<CFileInfo> *, CExoString, unsigned short, int);
    int GetDirectoryList(CExoArrayList<CExoString> *, CExoString, unsigned short, int, int);
    unsigned short GetResTypeFromExtension(CExoString const &);
    CExoString const & GetResourceExtension(unsigned short);
    void LoadAliases(CExoString);
    int ShutDown();
    int SpawnExternalApplication(CExoString const &, CExoString const &, int);
    ~CExoBaseInternal();
    CExoBaseInternal();

};
#endif
