#ifndef _CNWSFACTION_H_
#define _CNWSFACTION_H_
#include "nwndef.h"
#include "CExoString.h"

class CNWSFaction
{
public:
	int AddMember(unsigned long, int);
	int AttemptJoin(unsigned long);
	int AttemptRemove(unsigned long, unsigned long);
	int ChangeMemberId(unsigned long, unsigned long);
	int ClearAllReputationsTowards(unsigned long);
	int GetAverageGoodEvilAlignment();
	int GetAverageLawChaosAlignment();
	int GetAverageLevel();
	int GetAverageReputation(unsigned long);
	int GetAverageXP();
	int GetBestAC(unsigned long, int);
	int GetCreatureInParty(unsigned long);
	int GetFactionManager();
	int GetFactionMember(int, int);
	int GetGold();
	int GetIsInvited(unsigned long);
	int GetLeader();
	int GetLeastDamagedMember(unsigned long, int);
	int GetMemberList(unsigned long **);
	int GetMostDamagedMember(unsigned long, int);
	int GetMostFrequentClass();
	int GetSingletonParty();
	int GetStrongestMember(unsigned long, int);
	int GetWeakestMember(unsigned long, int);
	int GetWorstAC(unsigned long, int);
	int Initialise();
	int InviteMember(unsigned long, unsigned long);
	int RemoveMember(unsigned long);
	int SendChatMessage(unsigned long, CExoString);
	int SendFactionUpdateAdd(unsigned long);
	int SendFactionUpdateList();
	int SendFactionUpdateRemove(unsigned long);
	int TransferLeadership(unsigned long, unsigned long);
	~CNWSFaction();
	CNWSFaction();
	CNWSFaction(unsigned long);

};
#endif
