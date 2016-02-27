#ifndef _CNWSPLAYER_H_
#define _CNWSPLAYER_H_
#include "nwndef.h"
#include "CNWSClient.h"
#include "CExoString.h"
#include "CResRef.h"
#include "CExoLinkedList.h"
#include "CLastUpdateObject.h"

class CNWSPlayer : public CNWSClient
{
public:
    int AddArea(unsigned long);
    void AddDMAbilities(CNWSCreature *);
    void AllocateAreas(int);
    CNWSPlayer * AsNWSPlayer();
    int BackupServerCharacter(CExoString const &);
    void CleanMyTURDs();
    int ClearPlayerLastUpdateObject();
    void ClearPlayerOnDestroyGame();
    CNWSPlayerLastUpdateObject * CreateNewPlayerLastUpdateObject();
    void DropTURD();
    void EatTURD(CNWSPlayerTURD *);
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
    CNWSObject * GetGameObject();
    int GetIFOCharacterIndex();
    int GetInventoryGUIInfo();
    int GetIsAllowedToSave();
    int GetIsPrimaryPlayer();
    int GetJournalQuestInfo();
    int GetLastObjectControlled();
    CLastUpdateObject * GetLastUpdateObject(unsigned long);
    int GetLastUpdatedTime();
    int GetLoginState();
    int GetModuleInfoSucceeded();
    int GetOtherInventoryGUIInfo();
    int GetPCObject();
    int GetPlayModuleListingCharacters();
    int GetPlayerLastUpdateObject();
    int GetPlayerListIndex();
    CExoString GetPlayerName();
    int GetStoreGUIInfo();
    int HasExpansionPack(unsigned char, int);
    CNWSCreature * LoadCharacterFromIFO(unsigned long, int, int, int, int);
    unsigned long LoadCreatureData(CResRef, CNWSCreature *);
    unsigned long LoadDMCharacter();
    unsigned long LoadLocalCharacter();
    unsigned long LoadServerCharacter(CResRef, int);
    void LoadTURDInfoFromIFO(unsigned long);
    int PackCreatureIntoMessage();
    int PermittedToDisplayCharacterSheet(unsigned long);
    void RestoreCameraSettings();
    int SaveServerCharacter(int);
    int SetAlwaysRun(int);
    void SetAreaTransitionBMP(int, CExoString);
    int SetCharacterType(unsigned char);
    int SetCommunityNameAuthorized(int);
    int SetCutsceneState(int);
    void SetFileName(CResRef);
    int SetFloatyEffects(int);
    int SetFromSaveGame(int);
    int SetFromTURD(int);
    void SetGameObject(CNWSObject *);
    int SetIFOCharacterIndex(unsigned long);
    int SetIsPrimaryPlayer(int);
    int SetLastObjectControlled(unsigned long);
    int SetLastUpdatedTime(unsigned long long);
    int SetLoginState(unsigned char);
    int SetModuleInfoSucceeded(int);
    int SetPCObject(unsigned long);
    int SetPlayModuleListingCharacters(int);
    int SetPlayerListIndex(unsigned long);
    void StoreCameraSettings();
    void StripAllInvalidItemPropertiesInInventory(CNWSCreature *);
    void StripAllInvalidItemPropertiesOnItem(CNWSItem *);
    int ValidateCharacter_SetNormalBonusFlags(unsigned short, int &, int &, unsigned char);
    unsigned long ValidateCharacter(int *);
    ~CNWSPlayer();
    CNWSPlayer(unsigned long);

    /* (ptr_to:CExoLinkedList<CLastUpdateObject>) */
    /* 0xC/12 */ CExoLinkedList<CLastUpdateObject> *m_pActiveObjectsLastUpdate;
    /* (ptr_to:CExoLinkedList<CLastUpdatePartyObject>) */
    /* 0x10/16 */ unsigned long m_pActivePartyObjectsLastUpdate;
    /* 0x14/20 */ unsigned long AreaTransitionLoadScreenId;
    /* 0x18/24 */ unsigned long AreaTransitionBMP;
    /* 0x1C/28 */ unsigned long field_1C;
    /* 0x20/32 */ unsigned long FloatyEffects;
    /* 0x24/36 */ unsigned long AreaListSize;
    /* 0x28/40 */ unsigned long *AreaList;
    /* 0x2C/44 */ unsigned long LoginState;
    /* 0x30/48 */ unsigned long m_oidNWSObject;
    /* 0x34/52 */ double m_nLastUpdatedTime;
    /* 0x3C/60 */ unsigned long m_oidLastObjectControlled;
    /* 0x40/64 */ unsigned long m_oidPCObject;
    /* 0x44/68 */ unsigned long m_bIsPrimaryPlayer;
    /* 0x48/72 */ unsigned long FromSaveGame;
    /* 0x4C/76 */ unsigned long FromTURD;
    /* 0x50/80 */ unsigned long PlayerListIndex;
    /* 0x54/84 */ unsigned long PlayModuleListingCharacters;
    /* 0x58/88 */ unsigned long JournalQuestInfo;
    /* 0x5C/92 */ unsigned long StoreGUIInfo;
    /* 0x60/96 */ CNWSPlayerCharSheetGUI *PlayerCharSheetGUI;
    /* 0x64/100 */ CNWSPlayerInventoryGUI *m_pInventoryGUI;
    /* 0x68/104 */ CNWSPlayerInventoryGUI *m_pOtherInventoryGUI;
    /* 0x6C/108 */ unsigned long PlayerLastUpdateObject;
    /* 0x70/112 */ unsigned long AlwaysRun;
    /* 0x74/116 */ unsigned char CharacterType;
    /* 0x75/117 */ CResRef       BicFile;
    /* 0x88/136 */ unsigned long CommunityNameAuthorized;
    /* 0x8C/140 */ unsigned long ModuleInfoSucceeded;
    /* 0x90/144 */ unsigned long field_90;
    /* 0x94/148 */ unsigned long CutsceneState;
};

static_assert_size(CNWSPlayer, 0x98);

#endif
