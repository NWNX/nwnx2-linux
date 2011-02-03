#ifndef _CEXOFILEINTERNAL_H_
#define _CEXOFILEINTERNAL_H_
#include "nwndef.h"

class CExoFileInternal
{
public:
	int GetOffset();
	int GetSize();
	int ReadAsyncBytesRead();
	int ReadAsyncComplete();
	int ReadAsync(void *, unsigned long, unsigned long);
	int Read(CExoString *, unsigned long);
	int Write(char const *);
	~CExoFileInternal();
	CExoFileInternal(CExoString const &, unsigned short, CExoString const &);

};
#endif
