#ifndef _CNWSFACTION_H_
#define _CNWSFACTION_H_
#include "nwndef.h"
#include "CExoString.h"

class CNWSFaction
{
public:
    void AddMember(unsigned long, int);
    int AttemptJoin(unsigned long);
    int AttemptRemove(unsigned long, unsigned long);
    void ChangeMemberId(unsigned long, unsigned long);
    void ClearAllReputationsTowards(unsigned long);
    int GetAverageGoodEvilAlignment();
    int GetAverageLawChaosAlignment();
    int GetAverageLevel();
    int GetAverageReputation(unsigned long);
    int GetAverageXP();
    unsigned long GetBestAC(unsigned long, int);
    int GetCreatureInParty(unsigned long);
    int GetFactionManager();
    unsigned long GetFactionMember(int, int);
    int GetGold();
    int GetIsInvited(unsigned long);
    unsigned long GetLeader();
    unsigned long GetLeastDamagedMember(unsigned long, int);
    int GetMemberList(unsigned long **);
    unsigned long GetMostDamagedMember(unsigned long, int);
    int GetMostFrequentClass();
    int GetSingletonParty();
    unsigned long GetStrongestMember(unsigned long, int);
    unsigned long GetWeakestMember(unsigned long, int);
    unsigned long GetWorstAC(unsigned long, int);
    int Initialise();
    int InviteMember(unsigned long, unsigned long);
    void RemoveMember(unsigned long);
    void SendChatMessage(unsigned long, CExoString);
    void SendFactionUpdateAdd(unsigned long);
    int SendFactionUpdateList();
    int SendFactionUpdateRemove(unsigned long);
    int TransferLeadership(unsigned long, unsigned long);
    ~CNWSFaction();
    CNWSFaction();
    CNWSFaction(unsigned long);

    /* 0x0/0 */ unsigned long field_0;
    /* 0x4/4 */ unsigned long field_4;
    /* 0x8/8 */ unsigned long field_8;
    /* 0xC/12 */ unsigned long field_C;
    /* 0x10/16 */ unsigned long m_nFactionParentID;
    /* 0x14/20 */ unsigned long field_14;
    /* 0x18/24 */ CExoString m_sName;
    /* 0x20/32 */ unsigned long m_nFactionGlobal;
};
#endif
