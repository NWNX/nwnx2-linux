#ifndef _CNWSJOURNAL_H_
#define _CNWSJOURNAL_H_
#include "nwndef.h"
#include "CExoString.h"

class CNWSJournal
{
public:
    void Destroy(CExoString);
    void SetDate(CExoString, unsigned long, int);
    void SetPicture(CExoString, int, int);
    void SetState(CExoString, unsigned long, int);
    void SetTime(CExoString, unsigned long, int);
    ~CNWSJournal();
    CNWSJournal();

};
#endif
