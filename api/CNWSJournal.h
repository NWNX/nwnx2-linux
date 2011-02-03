#ifndef _CNWSJOURNAL_H_
#define _CNWSJOURNAL_H_
#include "nwndef.h"
#include "CExoString.h"

class CNWSJournal
{
public:
	int Destroy(CExoString);
	int SetDate(CExoString, unsigned long, int);
	int SetPicture(CExoString, int, int);
	int SetState(CExoString, unsigned long, int);
	int SetTime(CExoString, unsigned long, int);
	~CNWSJournal();
	CNWSJournal();

};
#endif
