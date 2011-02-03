#ifndef _CERFSTRING_H_
#define _CERFSTRING_H_
#include "nwndef.h"

class CERFString
{
public:
	int GetText();
	int Read();
	int Reset();
	int SetText(CExoString &);
	int Write(CExoFile &);
	~CERFString();
	CERFString();

};
#endif
