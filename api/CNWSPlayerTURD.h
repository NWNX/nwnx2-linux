#ifndef _CNWSPLAYERTURD_H_
#define _CNWSPLAYERTURD_H_
#include "nwndef.h"
#include "CExoArrayList.h"
#include "CNWSObject.h"
#include "CExoString.h"

class CNWSPlayerTURD
{
public:
	int AIUpdate();
	int AddToArea(CNWSArea *, int);
	int AsNWSPlayerTURD();
	int ClearAutomapData();
	int CopyAutomapData(int, CExoArrayList<unsigned long> *, unsigned char **);
	int CopyEffectList(CExoArrayList<CGameEffect *> *);
	int EventHandler(unsigned long, unsigned long, void *, unsigned long, unsigned long);
	int GetAutoMapAreasList();
	int GetAutoMapTileData();
	int GetCalendarDay();
	int GetCalendarTimeOfDay();
	int GetCommunityName();
	int GetFirstName();
	int GetLastName();
	int GetNumAutoMapAreas();
	int GetPersonalReputation();
	int GetPlayerID();
	int GetReputation();
	int LoadAutoMapData(CResGFF *, CResStruct *);
	int LoadTURD(CResGFF *, CResStruct *);
	int RemoveFromArea();
	int SaveAutoMapData(CResGFF *, CResStruct *);
	int SaveTURD(CResGFF *, CResStruct *);
	int SetCalendarDay(unsigned long);
	int SetCalendarTimeOfDay(unsigned long);
	int SetCommunityName(CExoString const &);
	int SetFirstName(CExoLocString const &);
	int SetLastName(CExoLocString const &);
	int SetPersonalReputation(CExoArrayList<CNWSPersonalReputation> *);
	int SetPlayerID(unsigned long);
	int SetReputation(CExoArrayList<int> *);
	~CNWSPlayerTURD();
	CNWSPlayerTURD(unsigned long);

	/* 0x0/0 */ CNWSObject Object;
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
	/* 0x1F0/496 */ unsigned long MapNumAreas;
	/* 0x1F4/500 */ char **MapAreasData;
	/* 0x1F8/504 */ char **MapData;
};
#endif
