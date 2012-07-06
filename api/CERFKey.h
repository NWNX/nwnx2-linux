#ifndef _CERFKEY_H_
#define _CERFKEY_H_
#include "nwndef.h"
#include "CExoString.h"
#include "CExoFile.h"

class CERFKey
{
public:
	int Read();
	int Reset();
	int SetName(CExoString &);
	int Write(CExoFile &);
	~CERFKey();
	CERFKey();

};
#endif
