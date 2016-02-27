#pragma once

template <typename G>
struct Base_vtbl {
    unsigned long           field_0;
    void                    (*Constructor)(G*);
    void                    (*Destructor)(G*, char);
};

template <typename G>
struct CGameObject_vtbl : public Base_vtbl<G> {
    void                    (*SetId)(G*);
    void                    (*ResetUpdateTimes)(G*);
    CNWCObject*             (*AsNWCObject)(G*);
    CNWSObject*             (*AsNWSObject)(G*);
    CNWCDoor*               (*AsNWCDoor)(G*);
    CNWSDoor*               (*AsNWSDoor)(G*);
    CNWCModule*             (*AsNWCModule)(G*);
    CNWSModule*             (*AsNWSModule)(G*);
    CNWCArea*               (*AsNWCArea)(G*);
    CNWSArea*               (*AsNWSArea)(G*);
    CNWCCreature*           (*AsNWCCreature)(G*);
    CNWSCreature*           (*AsNWSCreature)(G*);
    CNWCItem*               (*AsNWCItem)(G*);
    CNWSItem*               (*AsNWSItem)(G*);
    CNWCTrigger*            (*AsNWCTrigger)(G*);
    CNWSTrigger*            (*AsNWSTrigger)(G*);
    CNWCProjectile*         (*AsNWCProjectile)(G*);
    CNWSPlayerTURD*         (*AsNWSPlayerTURD)(G*);
    CNWSPlaceable*          (*AsNWSPlaceable)(G*);
    CNWCPlaceable*          (*AsNWCPlaceable)(G*);
    CNWSAreaOfEffectObject* (*AsNWSAreaOfEffectObject)(G*);
    CNWCAreaOfEffectObject* (*AsNWCAreaOfEffectObject)(G*);
    CNWSWaypoint*           (*AsNWSWaypoint)(G*);
    CNWSEncounter*          (*AsNWSEncounter)(G*);
    CNWCStore*              (*AsNWCStore)(G*);
    CNWSStore*              (*AsNWSStore)(G*);
    CNWSSoundObject*        (*AsNWSSoundObject)(G*);
    CNWCSoundObject*        (*AsNWCSoundObject)(G*);
};

template<typename G>
struct CNWSObject_vtbl : public CGameObject_vtbl<G> {
    void                    (*AIUpdate)(G*);
    void                    (*ClearAction)(G*, CNWSObjectActionNode*, int);
    void                    (*EventHandler)(G*, unsigned long, unsigned long, void*, unsigned long, unsigned long);
    void                    (*SetAnimation)(G*, int);
    CResRef                 (*GetDialogResref)(G*);
    int                     (*GetDialogInterruptable)(G*);
    char                    (*GetGender)(G*);
    CExoLocString*          (*GetFirstName)(G*);
    CExoLocString*          (*GetLastName)(G*);
    int                     (*GetMaxHitPoints)(G*, int);
    int                     (*GetCurrentHitPoints)(G*, int);
    int                     (*DoDamage)(G*, int);
    int                     (*DoDamageReduction)(G*, CNWSCreature*, int, unsigned char, int, int);
    unsigned int            (*DoDamageResistance)(G*, CNWSCreature*, int, unsigned short, int, int, int);
    unsigned int            (*GetMaximumDamageResistanceVsDamageFlag)(G*, unsigned short, int*);
    void                    (*DoDamageImmunity)(G*, CNWSCreature*, int, unsigned short, int, int);
    void                    (*GetDamageImmunity)(G*, unsigned char);
    void                    (*GetDamageImmunityByFlags)(G*, unsigned short);
    unsigned long           (*GetEffectSpellId)(G*);
    void                    (*SetEffectSpellId)(G*, unsigned long);
    void                    (*SetLockOrientationToObject)(G*, unsigned long);
    unsigned long           (*GetLockOrientationToObject)(G*);
    CResRef                 (*GetPortrait)(G*);
    void                    (*SetPortrait)(G*, CResRef);
    unsigned short          (*GetPortraitId)(G*);
    void                    (*SetPortraitId)(G*, unsigned short);
    void                    (*BroadcastFloatyData)(G*, CNWCCMessageData*);
    void                    (*BroadcastFloatyDataSTRREF)(G*, unsigned long);
    void                    (*UpdateEffectPtrs)(G*);
    void                    (*UpdateAttributesOnEffect)(G*, CGameEffect*, int);
};

struct CNWArea_vtbl : public Base_vtbl<CNWArea> {
    int                     (*NoCreaturesOnLine)(CNWArea*);
    int                     (*HandleTransparentDoors)(CNWArea*);
    int                     (*GetIsIDInExcludeList)(CNWArea*);
    void                    (*pure__virtual);
    void                    (*SetFog)(CNWArea*, int, Vector);
    void                    (*SetIsNight)(CNWArea*, int);
    void                    (*SetWind)(CNWArea*, unsigned char);
    CNWSArea*               (*AsNWSArea)(CNWArea*);
};

struct CNWSArea_vtbl : public CNWArea_vtbl {
    // These appear to be always 0x0.
    unsigned long           field_24;
    unsigned long           field_28;
};

struct CNWSClient_vtbl : public Base_vtbl<CNWSClient> {
    CNWSDungeonMaster*      (*AsNWSDungeonMaster)(CNWSClient*);
    CNWSPlayer*             (*AsNWSPlayer)(CNWSClient*);
};

struct CRes_vtbl : public Base_vtbl<CRes> {
    int                     (*GetFixedResourceSize)(CRes*);
    int                     (*GetFixedResourceDataOffset)(CRes*);
    void                    (*OnResourceFreed)(CRes*);
    void                    (*OnResourceServiced)(CRes*);
};

// Below this line: TODO. :)

struct CServerExoApp_vtbl {
    unsigned long           field_0;
    void                    (*Constructor)(CServerExoApp*);
    void                    *AdmitNetworkAddress;
    unsigned long           AdmitPlayerName;
    unsigned long           SetNetworkAddressBan;
    unsigned long           PlayerListChange;
    unsigned long           HandleMessage;
    unsigned long           GetFPS;
    unsigned long           ContinueMessageProcessing;
    unsigned long           GetNetLayer;
    unsigned long           ShutDownToMainMenu;
    void                    *GetMultiplayerEnabled;
    unsigned long           GetExtendedServerInfo;
    unsigned long           HandleGameSpyToServerMessage;
    unsigned long           GetConnectionLib;
    unsigned long           GSClientGroupRoomAdded;
    unsigned long           GSClientChatMessage;
    unsigned long           GSClientAddServer;
    unsigned long           GSClientRemoveServer;
    unsigned long           GSClientUpdateServer;
    unsigned long           GSClientClearServers;
    unsigned long           GSClientUpdateConnectionPhase;
    unsigned long           GetServerInfo;
    unsigned long           GetExtendedServerInfo_;
    unsigned long           GetModuleDescription;
    void                    *GetApplicationId;
    unsigned long           SetApplicationIdsMatch;
    void                    *GetIsIPOnBannedList;
    void                    *GetIsPlayerNameOnBannedList;
    void                    *GetIsCDKeyOnBannedList;
    unsigned long           PushMessageOverWall;
    void                    *GetIsMultiPlayer;
    unsigned long           GetCDKeys;
    unsigned long           SetWeGotDisconnected;
};

struct CNWVirtualMachineCommands_vtbl : public Base_vtbl<CNWVirtualMachineCommands> {
    unsigned long           InitializeCommands;
    unsigned long           ExecuteCommand;
    void                    *RunScriptCallback;
    unsigned long           ReportError;
    unsigned long           CreateGameDefinedStructure;
    unsigned long           DestroyGameDefinedStructure;
    unsigned long           GetEqualGameDefinedStructure;
    void                    *CopyGameDefinedStructure;
    void                    *SaveGameDefinedStructure;
    unsigned long           LoadGameDefinedStructure;
    unsigned long           GetGameDefinedStructureName;
    unsigned long           GetDebuggerLabelName;
    unsigned long           GetEngineStructureWatchView;
    unsigned long           GetObjectWatchView;
    unsigned long           DebugGUIStart;
    unsigned long           DebugGUIStop;
    unsigned long           DebugGUISendMessageTo;
    unsigned long           DebugGUIGetMessageFrom;
    unsigned long           DebugGUIUpdate;
};

struct CExoPackedFile_vtbl : public Base_vtbl<CExoPackedFile> {
    void                    *AddRefCount;
    void                    *AddAsyncRefCount;
    unsigned long           CloseFile;
    unsigned long           CloseAsyncFile;
    void                    *DeleteRefCount;
    void                    *DeleteAsyncRefCount;
    unsigned long           GetFile;
    void                    *GetAsyncFile;
    void                    *GetResourceSize;
    unsigned long           Initialize;
    unsigned long           OpenFile;
    unsigned long           OpenFile2;
    unsigned long           OpenAsyncFile;
    void                    *ReadResource;
    void                    *ReadResourceAsync;
    unsigned long           LoadHeader;
    unsigned long           UnloadHeader;
    unsigned long           GetResource;
};
