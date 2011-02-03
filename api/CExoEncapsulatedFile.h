#ifndef _CEXOENCAPSULATEDFILE_H_
#define _CEXOENCAPSULATEDFILE_H_
#include "nwndef.h"

class CExoEncapsulatedFile
{
public:
	int AddAsyncRefCount();
	int AddRefCount();
	int CloseAsyncFile();
	int CloseFile();
	int DeleteAsyncRefCount();
	int DeleteRefCount();
	int GetDescription();
	int GetResourceSize(unsigned long);
	int Initialize();
	int LoadHeader(unsigned char);
	int OpenAsyncFile();
	int OpenFile();
	int OpenFile(unsigned char *);
	int ReadResourceAsync(unsigned long, void *, unsigned long, unsigned long);
	int ReadResource(unsigned long, void *, unsigned long, unsigned long);
	int UnloadHeader();
	~CExoEncapsulatedFile();
	CExoEncapsulatedFile();

};
#endif
