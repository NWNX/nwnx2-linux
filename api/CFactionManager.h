#ifndef _CFACTIONMANAGER_H_
#define _CFACTIONMANAGER_H_
#include "nwndef.h"
#include "CExoArrayList.h"

class CFactionManager
{
public:
    void CreateDefaultFactions();
    void DeleteFaction(int);
    CExoArrayList<int> * GetDefaultPCReputation();
    int GetFactionIdByName(CExoString const &);
    CNWSFaction * GetFaction(int);
    int GetIsNPCFaction(int);
    int GetNPCFactionReputation(int, int);
    int LoadFactions(CResGFF *, CResList *);
    int LoadReputations(CResGFF *, CResList *);
    int SaveFactions(CResGFF *, CResList *);
    int SaveReputations(CResGFF *, CResList *);
    void SetNPCFactionReputation(int, int, int);
    ~CFactionManager();
    CFactionManager();

    /* 0x0/0 */ CNWSFaction *m_pDefender;
    /* 0x4/4 */ CNWSFaction *m_pCommoner;
    /* 0x8/8 */ CNWSFaction *m_pMerchant;
    /* 0xC/12 */ CNWSFaction *m_pHostile;
    /* 0x10/16 */ unsigned long field_10;
    /* 0x14/20 */ unsigned long m_nFactionCount;
    /* (ptr_to:CExoArrayList<int>) */
    /* 0x18/24 */ CExoArrayList<int> *m_aReputation;
    /* (ptr_to:CExoArrayList<CNWSFaction *>) */
    /* 0x1C/28 */ CExoArrayList<CNWSFaction *> *m_pFactionsArray;
};
#endif
