#ifndef _CSERVERAIEVENTNODE_H_
#define _CSERVERAIEVENTNODE_H_
#include "nwndef.h"

class CServerAIEventNode
{
public:
    int LoadNode(CResGFF *, CResStruct *);
    int SaveNode(CResGFF *, CResStruct *);

    /* 0x0/0 */ unsigned long m_nCalendarDay;
    /* 0x4/4 */ unsigned long m_nTimeOfDay;
    /* 0x8/8 */ unsigned long m_nCallerObjectId;
    /* 0xC/12 */ unsigned long m_nObjectId;
    /* 0x10/16 */ unsigned long m_nEventId;
    /* 0x14/20 */ void *m_pEventData;
};
#endif
