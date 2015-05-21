#ifndef _CSERVERAILIST_H_
#define _CSERVERAILIST_H_
#include "nwndef.h"
#include "CExoArrayList.h"

class CServerAIList
{
public:
    int AddObject(unsigned long);
    int GetNextObject();
    int RemoveObject(unsigned long);
    ~CServerAIList();
    CServerAIList();

    /* (mtype:CExoArrayList<unsigned long>) */
    /* 0x0/0 */ CExoArrayList<unsigned long> m_aoGameObjects;
    /* 0xC/12 */ unsigned long m_nPosition;
};
#endif
