#ifndef _CNWSCLIENT_H_
#define _CNWSCLIENT_H_
#include "nwndef.h"

class CNWSClient
{
public:
    CNWSDungeonMaster * AsNWSDungeonMaster();
    CNWSPlayer * AsNWSPlayer();
    int GetLanguage();
    unsigned long GetPlayerId();
    int SetLanguage(int);
    ~CNWSClient();
    CNWSClient(unsigned long);

    /* 0x0/0 */ unsigned long m_nPlayerID;
    /* 0x4/4 */ unsigned long m_nLanguage;
    /* 0x8/8 */ CNWSClient_vtbl *vptr;
};

static_assert_size(CNWSClient, 0xC);

#endif
