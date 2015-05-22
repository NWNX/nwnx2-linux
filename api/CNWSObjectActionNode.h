#ifndef _CNWSOBJECTACTIONNODE_H_
#define _CNWSOBJECTACTIONNODE_H_
#include "nwndef.h"

class CNWSObjectActionNode
{
public:
    ~CNWSObjectActionNode();
    CNWSObjectActionNode();

    /* 0x0/0 */ unsigned long m_nActionId;
    /* 0x4/4 */ unsigned long m_nParamType[12];
    /* 0x34/52 */ void *m_pParameter[12];
    /* 0x64/100 */ unsigned short m_nGroupActionId;
    /* 0x66/102 */ unsigned short m_nParameters;
    /* 0x68/104 */ unsigned long field_68;
};
#endif
