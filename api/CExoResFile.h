#ifndef _CEXORESFILE_H_
#define _CEXORESFILE_H_
#include "nwndef.h"

class CExoResFile
{
public:
	int AddAsyncRefCount();
	int AddRefCount();
	int CloseAsyncFile();
	int CloseFile();
	int DeleteAsyncRefCount();
	int DeleteRefCount();
	int GetResourceSize(unsigned long);
	int Initialize();
	int LoadHeader(unsigned char);
	int OpenAsyncFile();
	int OpenFile();
	int OpenFile(unsigned char *);
	int ReadResourceAsync(unsigned long, void *, unsigned long, unsigned long);
	int ReadResource(unsigned long, void *, unsigned long, unsigned long);
	int UnloadHeader();
	~CExoResFile();
	CExoResFile();

};
#endif
