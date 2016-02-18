#ifndef _CNWSPLAYERTURD_H_
#define _CNWSPLAYERTURD_H_
#include "nwndef.h"
#include "CExoArrayList.h"
#include "CExoString.h"
#include "CNWSObject.h"

class CNWSPlayerTURD : CNWSObject
{
public:
    void AIUpdate();
    void AddToArea(CNWSArea *, int);
    CNWSPlayerTURD * AsNWSPlayerTURD();
    int ClearAutomapData();
    int CopyAutomapData(int, CExoArrayList<unsigned long> *, unsigned char **);
    void CopyEffectList(CExoArrayList<CGameEffect *> *);
    void EventHandler(unsigned long, unsigned long, void *, unsigned long, unsigned long);
    int GetAutoMapAreasList();
    int GetAutoMapTileData();
    int GetCalendarDay();
    int GetCalendarTimeOfDay();
    CExoString GetCommunityName();
    CExoLocString & GetFirstName();
    CExoLocString & GetLastName();
    int GetNumAutoMapAreas();
    int GetPersonalReputation();
    int GetPlayerID();
    int GetReputation();
    void LoadAutoMapData(CResGFF *, CResStruct *);
    int LoadTURD(CResGFF *, CResStruct *);
    void RemoveFromArea();
    int SaveAutoMapData(CResGFF *, CResStruct *);
    void SaveTURD(CResGFF *, CResStruct *);
    int SetCalendarDay(unsigned long);
    int SetCalendarTimeOfDay(unsigned long);
    int SetCommunityName(CExoString const &);
    int SetFirstName(CExoLocString const &);
    int SetLastName(CExoLocString const &);
    void SetPersonalReputation(CExoArrayList<CNWSPersonalReputation> *);
    int SetPlayerID(unsigned long);
    void SetReputation(CExoArrayList<int> *);
    ~CNWSPlayerTURD();
    CNWSPlayerTURD(unsigned long);

    /* 0x1C4/452 */ CExoString CommntyName;
    /* 0x1CC/460 */ CExoString FirstName;
    /* 0x1D4/468 */ CExoString LastName;
    /* 0x1DC/476 */ unsigned long PlayerID;
    /* 0x1E0/480 */ unsigned long CalendarDay;
    /* 0x1E4/484 */ unsigned long TimeOfDay;
    /* (ptr_to:CExoArrayList<int>) */
    /* 0x1E8/488 */ CExoArrayList<int> *ReputationList;
    /* (ptr_to:CExoArrayList<CNWSPersonalReputation>) */
    /* 0x1EC/492 */ CExoArrayList<CNWSPersonalReputation> *PersonalRep;
    // Nearly the same as CNWSCreature.AutoMap*
    /* 0x1F0/496 */ unsigned long AutoMapNumAreas;
    /* 0x1F4/500 */ unsigned long *AutoMapAreaIdList;
    /* 0x1F8/504 */ char **AutoMapData;
};
#endif
