#ifndef _CEXOFILE_H_
#define _CEXOFILE_H_
#include "nwndef.h"

class CExoFile
{
public:
	int Eof();
	int FileOpened();
	int Flush();
	int GetOffset();
	int GetSize();
	int ReadAsyncBytesRead();
	int ReadAsyncComplete();
	int ReadAsync(void *, unsigned long, unsigned long);
	int ReadStringLineFromBuffer(unsigned char **, unsigned long *, unsigned char *, unsigned long);
	int Read(void *, unsigned long, unsigned long);
	int Read(CExoString &, unsigned long);
	int SeekBeginning();
	int SeekEnd();
	int Seek(int, int);
	int Write(char const *);
	int Write(void const *, unsigned long, unsigned long);
	int Write(CExoString const &);
	~CExoFile();
	CExoFile(CExoString const &, unsigned short, CExoString const &);

};
#endif
