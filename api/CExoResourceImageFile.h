#ifndef _CEXORESOURCEIMAGEFILE_H_
#define _CEXORESOURCEIMAGEFILE_H_
#include "nwndef.h"

class CExoResourceImageFile
{
public:
	int AddAsyncRefCount();
	int AddRefCount();
	int CloseAsyncFile();
	int CloseFile();
	int DeleteAsyncRefCount();
	int DeleteRefCount();
	int GetHeader();
	int GetKeyListEntry(unsigned long);
	int GetKeyList();
	int GetResourceListEntry(unsigned long);
	int GetResourceSize(unsigned long);
	int GetResource(unsigned long);
	int Initialize();
	int LoadHeader(unsigned char);
	int OpenAsyncFile();
	int OpenFile();
	int OpenFile(unsigned char *);
	int ReadResourceAsync(unsigned long, void *, unsigned long, unsigned long);
	int ReadResource(unsigned long, void *, unsigned long, unsigned long);
	int UnloadHeader();
	~CExoResourceImageFile();
	CExoResourceImageFile();

};
#endif
