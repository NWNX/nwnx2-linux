#ifndef _CNWSPLAYER_H_
#define _CNWSPLAYER_H_
#include "nwndef.h"
#include "CResRef.h"
#include "CExoString.h"
#include "CNWSClient.h"

class CNWSPlayer
{
public:
	int AddArea(unsigned long);
	int AddDMAbilities(CNWSCreature *);
	int AllocateAreas(int);
	int AsNWSPlayer();
	int BackupServerCharacter(CExoString const &);
	int CleanMyTURDs();
	int ClearPlayerLastUpdateObject();
	int ClearPlayerOnDestroyGame();
	int CreateNewPlayerLastUpdateObject();
	int DropTURD();
	int EatTURD(CNWSPlayerTURD *);
	int GetAlwaysRun();
	int GetAreaNum() const;
	int GetAreaTransitionBMP();
	int GetAreaTransitionName();
	int GetArea(int) const;
	int GetCharSheetGUIInfo();
	int GetCharacterInfoFromIFO(unsigned char &, int *, unsigned char *, unsigned long &);
	int GetCharacterType();
	int GetCommunityNameAuthorized();
	int GetContainerGUIInfo();
	int GetCutsceneState();
	int GetFileName();
	int GetFloatyEffects();
	int GetFromSaveGame();
	int GetFromTURD();
	int GetGameObject();
	int GetIFOCharacterIndex();
	int GetInventoryGUIInfo();
	int GetIsAllowedToSave();
	int GetIsPrimaryPlayer();
	int GetJournalQuestInfo();
	int GetLastObjectControlled();
	int GetLastUpdateObject(unsigned long);
	int GetLastUpdatedTime();
	int GetLoginState();
	int GetModuleInfoSucceeded();
	int GetOtherInventoryGUIInfo();
	int GetPCObject();
	int GetPlayModuleListingCharacters();
	int GetPlayerLastUpdateObject();
	int GetPlayerListIndex();
	int GetPlayerName();
	int GetStoreGUIInfo();
	int HasExpansionPack(unsigned char, int);
	int LoadCharacterFromIFO(unsigned long, int, int, int, int);
	int LoadCreatureData(CResRef, CNWSCreature *);
	int LoadDMCharacter();
	int LoadLocalCharacter();
	int LoadServerCharacter(CResRef, int);
	int LoadTURDInfoFromIFO(unsigned long);
	int PackCreatureIntoMessage();
	int PermittedToDisplayCharacterSheet(unsigned long);
	int RestoreCameraSettings();
	int SaveServerCharacter(int);
	int SetAlwaysRun(int);
	int SetAreaTransitionBMP(int, CExoString);
	int SetCharacterType(unsigned char);
	int SetCommunityNameAuthorized(int);
	int SetCutsceneState(int);
	int SetFileName(CResRef);
	int SetFloatyEffects(int);
	int SetFromSaveGame(int);
	int SetFromTURD(int);
	int SetGameObject(CNWSObject *);
	int SetIFOCharacterIndex(unsigned long);
	int SetIsPrimaryPlayer(int);
	int SetLastObjectControlled(unsigned long);
	int SetLastUpdatedTime(unsigned long long);
	int SetLoginState(unsigned char);
	int SetModuleInfoSucceeded(int);
	int SetPCObject(unsigned long);
	int SetPlayModuleListingCharacters(int);
	int SetPlayerListIndex(unsigned long);
	int StoreCameraSettings();
	int StripAllInvalidItemPropertiesInInventory(CNWSCreature *);
	int StripAllInvalidItemPropertiesOnItem(CNWSItem *);
	int ValidateCharacter_SetNormalBonusFlags(unsigned short, int &, int &, unsigned char);
	int ValidateCharacter(int *);
	~CNWSPlayer();
	CNWSPlayer(unsigned long);

	/* 0x0/0 */ CNWSClient Client;
	/* 0x94/148 */ char rsvd1[44];
	/* 0x94/148 */ unsigned long field_94;
};
#endif
