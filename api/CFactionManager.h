#ifndef _CFACTIONMANAGER_H_
#define _CFACTIONMANAGER_H_
#include "nwndef.h"

class CFactionManager
{
public:
	int CreateDefaultFactions();
	int DeleteFaction(int);
	int GetDefaultPCReputation();
	int GetFactionIdByName(CExoString const &);
	int GetFaction(int);
	int GetIsNPCFaction(int);
	int GetNPCFactionReputation(int, int);
	int LoadFactions(CResGFF *, CResList *);
	int LoadReputations(CResGFF *, CResList *);
	int SaveFactions(CResGFF *, CResList *);
	int SaveReputations(CResGFF *, CResList *);
	int SetNPCFactionReputation(int, int, int);
	~CFactionManager();
	CFactionManager();

};
#endif
