#include "CServerExoApp.h"

void CServerExoApp::AddCDKeyToBannedList(CExoString)
{
    asm("leave");
    asm("mov $0x080b27b8, %eax");
    asm("jmp *%eax");
}

void CServerExoApp::AddCharListRequest(unsigned long)
{
    asm("leave");
    asm("mov $0x080b26b0, %eax");
    asm("jmp *%eax");
}

void CServerExoApp::AddIPToBannedList(CExoString)
{
    asm("leave");
    asm("mov $0x080b26f0, %eax");
    asm("jmp *%eax");
}

void CServerExoApp::AddPlayerNameToBannedList(CExoString)
{
    asm("leave");
    asm("mov $0x080b2754, %eax");
    asm("jmp *%eax");
}

void CServerExoApp::AddSubNetProfileSendSize(unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x080b2b24, %eax");
    asm("jmp *%eax");
}

void CServerExoApp::AddToExclusionList(unsigned long, unsigned char)
{
    asm("leave");
    asm("mov $0x080b25e0, %eax");
    asm("jmp *%eax");
}

int CServerExoApp::AdmitNetworkAddress(unsigned long, CExoString)
{
    asm("leave");
    asm("mov $0x080b2068, %eax");
    asm("jmp *%eax");
}

int CServerExoApp::AdmitPlayerName(CExoString)
{
    asm("leave");
    asm("mov $0x080b2148, %eax");
    asm("jmp *%eax");
}

int CServerExoApp::ContinueMessageProcessing()
{
    asm("leave");
    asm("mov $0x080b21e4, %eax");
    asm("jmp *%eax");
}

int CServerExoApp::ExportAllPlayers()
{
    asm("leave");
    asm("mov $0x080b1c74, %eax");
    asm("jmp *%eax");
}

void CServerExoApp::GSClientAddServer(void *, char *, char *, int, int, int, int, char *, int, int, char *, int, int, int, char *, char *, int, int, int, int, int, bool)
{
    asm("leave");
    asm("mov $0x080b2c48, %eax");
    asm("jmp *%eax");
}

void CServerExoApp::GSClientChatMessage(int, CExoString, CExoString)
{
    asm("leave");
    asm("mov $0x080b2be4, %eax");
    asm("jmp *%eax");
}

void CServerExoApp::GSClientClearServers()
{
    asm("leave");
    asm("mov $0x080b2c60, %eax");
    asm("jmp *%eax");
}

void CServerExoApp::GSClientGroupRoomAdded(int, unsigned long)
{
    asm("leave");
    asm("mov $0x080b2bdc, %eax");
    asm("jmp *%eax");
}

void CServerExoApp::GSClientRemoveServer(void *)
{
    asm("leave");
    asm("mov $0x080b2c50, %eax");
    asm("jmp *%eax");
}

void CServerExoApp::GSClientUpdateConnectionPhase(unsigned char, CExoString const &)
{
    asm("leave");
    asm("mov $0x080b2c68, %eax");
    asm("jmp *%eax");
}

void CServerExoApp::GSClientUpdateServer(void *, char *, char *, int, int, int, int, char *, int, int, char *, int, int, int, char *, char *, int, int, int, int, int, bool)
{
    asm("leave");
    asm("mov $0x080b2c58, %eax");
    asm("jmp *%eax");
}

CExoLinkedList<unsigned long> * CServerExoApp::GetActiveExclusionList()
{
    asm("leave");
    asm("mov $0x080b2618, %eax");
    asm("jmp *%eax");
}

unsigned char CServerExoApp::GetActivePauseState()
{
    asm("leave");
    asm("mov $0x080b25a8, %eax");
    asm("jmp *%eax");
}

CWorldTimer * CServerExoApp::GetActiveTimer(unsigned long)
{
    asm("leave");
    asm("mov $0x080b1fa4, %eax");
    asm("jmp *%eax");
}

unsigned long CServerExoApp::GetApplicationId()
{
    asm("leave");
    asm("mov $0x080b26c8, %eax");
    asm("jmp *%eax");
}

CNWSArea * CServerExoApp::GetAreaByGameObjectID(unsigned long)
{
    asm("leave");
    asm("mov $0x080b1e10, %eax");
    asm("jmp *%eax");
}

CNWSAreaOfEffectObject * CServerExoApp::GetAreaOfEffectByGameObjectID(unsigned long)
{
    asm("leave");
    asm("mov $0x080b1e70, %eax");
    asm("jmp *%eax");
}

int CServerExoApp::GetAutoSavePending()
{
    asm("leave");
    asm("mov $0x080b1cf0, %eax");
    asm("jmp *%eax");
}

CExoString CServerExoApp::GetBannedListString()
{
    asm("leave");
    asm("mov $0x080b22f0, %eax");
    asm("jmp *%eax");
}

int CServerExoApp::GetCDKeys(CExoArrayList<CExoString> **)
{
    asm("leave");
    asm("mov $0x080b2c78, %eax");
    asm("jmp *%eax");
}

CNWSPlayer * CServerExoApp::GetClientObjectByObjectId(unsigned long)
{
    asm("leave");
    asm("mov $0x080b24b8, %eax");
    asm("jmp *%eax");
}

CNWSClient * CServerExoApp::GetClientObjectByPlayerId(unsigned long, unsigned char)
{
    asm("leave");
    asm("mov $0x080b24d0, %eax");
    asm("jmp *%eax");
}

CCodeBase * CServerExoApp::GetCodeBase()
{
    asm("leave");
    asm("mov $0x080b2424, %eax");
    asm("jmp *%eax");
}

CConnectionLib * CServerExoApp::GetConnectionLib()
{
    asm("leave");
    asm("mov $0x080b2410, %eax");
    asm("jmp *%eax");
}

CNWSCreature * CServerExoApp::GetCreatureByGameObjectID(unsigned long)
{
    asm("leave");
    asm("mov $0x080b1de0, %eax");
    asm("jmp *%eax");
}

int CServerExoApp::GetCreatureDeathLogging()
{
    asm("leave");
    asm("mov $0x080b2b3c, %eax");
    asm("jmp *%eax");
}

int CServerExoApp::GetDebugMode()
{
    asm("leave");
    asm("mov $0x080b200c, %eax");
    asm("jmp *%eax");
}

int CServerExoApp::GetDifficultyOption(int)
{
    asm("leave");
    asm("mov $0x080b2698, %eax");
    asm("jmp *%eax");
}

CNWSDoor * CServerExoApp::GetDoorByGameObjectID(unsigned long)
{
    asm("leave");
    asm("mov $0x080b1e58, %eax");
    asm("jmp *%eax");
}

CNWSEncounter * CServerExoApp::GetEncounterByGameObjectID(unsigned long)
{
    asm("leave");
    asm("mov $0x080b1ea0, %eax");
    asm("jmp *%eax");
}

int CServerExoApp::GetExoAppInternal()
{
    asm("leave");
    asm("mov $0x080b2bb4, %eax");
    asm("jmp *%eax");
}

int CServerExoApp::GetExportCharacterPending()
{
    asm("leave");
    asm("mov $0x080b1c24, %eax");
    asm("jmp *%eax");
}

int CServerExoApp::GetExportPlayersCharacter()
{
    asm("leave");
    asm("mov $0x080b1c60, %eax");
    asm("jmp *%eax");
}

CExtendedServerInfo * CServerExoApp::GetExtendedServerInfo()
{
    asm("leave");
    asm("mov $0x080b2bc8, %eax");
    asm("jmp *%eax");
}

void CServerExoApp::GetExtendedServerInfo(CExtendedServerInfo *)
{
    asm("leave");
    asm("mov $0x080b1ac4, %eax");
    asm("jmp *%eax");
}

float CServerExoApp::GetFPS()
{
    asm("leave");
    asm("mov $0x080b2bd0, %eax");
    asm("jmp *%eax");
}

int CServerExoApp::GetFactionOfObject(unsigned long, int *)
{
    asm("leave");
    asm("mov $0x080b2558, %eax");
    asm("jmp *%eax");
}

unsigned long CServerExoApp::GetFirstPCObject()
{
    asm("leave");
    asm("mov $0x080b2a8c, %eax");
    asm("jmp *%eax");
}

CGameObject * CServerExoApp::GetGameObject(unsigned long)
{
    asm("leave");
    asm("mov $0x080b1d98, %eax");
    asm("jmp *%eax");
}

int CServerExoApp::GetGameSpyEnabled()
{
    asm("leave");
    asm("mov $0x080b2af8, %eax");
    asm("jmp *%eax");
}

int CServerExoApp::GetImportingChar()
{
    asm("leave");
    asm("mov $0x080b1cb4, %eax");
    asm("jmp *%eax");
}

int CServerExoApp::GetIsCDKeyOnBannedList(CExoString)
{
    asm("leave");
    asm("mov $0x080b2a20, %eax");
    asm("jmp *%eax");
}

int CServerExoApp::GetIsControlledByPlayer(unsigned long)
{
    asm("leave");
    asm("mov $0x080b2534, %eax");
    asm("jmp *%eax");
}

int CServerExoApp::GetIsIPOnBannedList(CExoString)
{
    asm("leave");
    asm("mov $0x080b2948, %eax");
    asm("jmp *%eax");
}

int CServerExoApp::GetIsMultiPlayer()
{
    asm("leave");
    asm("mov $0x080b2ad4, %eax");
    asm("jmp *%eax");
}

int CServerExoApp::GetIsPlayerNameOnBannedList(CExoString)
{
    asm("leave");
    asm("mov $0x080b29b4, %eax");
    asm("jmp *%eax");
}

CNWSItem * CServerExoApp::GetItemByGameObjectID(unsigned long)
{
    asm("leave");
    asm("mov $0x080b1dc8, %eax");
    asm("jmp *%eax");
}

int CServerExoApp::GetLoadingModule()
{
    asm("leave");
    asm("mov $0x080b1c8c, %eax");
    asm("jmp *%eax");
}

CNWSModule * CServerExoApp::GetModuleByGameObjectID(unsigned long)
{
    asm("leave");
    asm("mov $0x080b1df8, %eax");
    asm("jmp *%eax");
}

CExoLocString CServerExoApp::GetModuleDescription()
{
    asm("leave");
    asm("mov $0x080b18f4, %eax");
    asm("jmp *%eax");
}

int CServerExoApp::GetModuleLanguage()
{
    asm("leave");
    asm("mov $0x080b1f00, %eax");
    asm("jmp *%eax");
}

CExoString CServerExoApp::GetModuleName()
{
    asm("leave");
    asm("mov $0x080b1af4, %eax");
    asm("jmp *%eax");
}

CNWSModule * CServerExoApp::GetModule()
{
    asm("leave");
    asm("mov $0x080b1adc, %eax");
    asm("jmp *%eax");
}

int CServerExoApp::GetMoveToModulePending()
{
    asm("leave");
    asm("mov $0x080b1b94, %eax");
    asm("jmp *%eax");
}

int CServerExoApp::GetMoveToModuleString()
{
    asm("leave");
    asm("mov $0x080b1bc8, %eax");
    asm("jmp *%eax");
}

int CServerExoApp::GetMultiplayerEnabled()
{
    asm("leave");
    asm("mov $0x080b2660, %eax");
    asm("jmp *%eax");
}

CNWSMessage * CServerExoApp::GetNWSMessage()
{
    asm("leave");
    asm("mov $0x080b1f54, %eax");
    asm("jmp *%eax");
}

CNetLayer * CServerExoApp::GetNetLayer()
{
    asm("leave");
    asm("mov $0x080b1f40, %eax");
    asm("jmp *%eax");
}

unsigned long CServerExoApp::GetNextPCObject()
{
    asm("leave");
    asm("mov $0x080b2aa4, %eax");
    asm("jmp *%eax");
}

CGameObjectArray * CServerExoApp::GetObjectArray()
{
    asm("leave");
    asm("mov $0x080b1d84, %eax");
    asm("jmp *%eax");
}

int CServerExoApp::GetPauseState(unsigned char)
{
    asm("leave");
    asm("mov $0x080b258c, %eax");
    asm("jmp *%eax");
}

CWorldTimer * CServerExoApp::GetPauseTimer()
{
    asm("leave");
    asm("mov $0x080b1fe4, %eax");
    asm("jmp *%eax");
}

CNWPlaceMeshManager * CServerExoApp::GetPlaceMeshManager()
{
    asm("leave");
    asm("mov $0x080b1f90, %eax");
    asm("jmp *%eax");
}

CNWSPlaceable * CServerExoApp::GetPlaceableByGameObjectID(unsigned long)
{
    asm("leave");
    asm("mov $0x080b1e40, %eax");
    asm("jmp *%eax");
}

int CServerExoApp::GetPlayerAddressData(unsigned long, unsigned long *, unsigned char **, unsigned char **, unsigned long *)
{
    asm("leave");
    asm("mov $0x080b2438, %eax");
    asm("jmp *%eax");
}

unsigned long CServerExoApp::GetPlayerIDByGameObjectID(unsigned long)
{
    asm("leave");
    asm("mov $0x080b1ed0, %eax");
    asm("jmp *%eax");
}

int CServerExoApp::GetPlayerLanguage(unsigned long)
{
    asm("leave");
    asm("mov $0x080b1ee8, %eax");
    asm("jmp *%eax");
}

CExoString CServerExoApp::GetPlayerListString()
{
    asm("leave");
    asm("mov $0x080b22cc, %eax");
    asm("jmp *%eax");
}

CExoLinkedList<CNWSClient> * CServerExoApp::GetPlayerList()
{
    asm("leave");
    asm("mov $0x080b1f2c, %eax");
    asm("jmp *%eax");
}

CExoString CServerExoApp::GetPortalListString()
{
    asm("leave");
    asm("mov $0x080b2314, %eax");
    asm("jmp *%eax");
}

int CServerExoApp::GetReloadModuleWhenEmpty()
{
    asm("leave");
    asm("mov $0x080b2684, %eax");
    asm("jmp *%eax");
}

CServerAIMaster * CServerExoApp::GetServerAIMaster()
{
    asm("leave");
    asm("mov $0x080b1f18, %eax");
    asm("jmp *%eax");
}

CServerInfo * CServerExoApp::GetServerInfo()
{
    asm("leave");
    asm("mov $0x080b1ab0, %eax");
    asm("jmp *%eax");
}

short CServerExoApp::GetServerMode()
{
    asm("leave");
    asm("mov $0x080b1f7c, %eax");
    asm("jmp *%eax");
}

CNWSSoundObject * CServerExoApp::GetSoundObjectByGameObjectID(unsigned long)
{
    asm("leave");
    asm("mov $0x080b1eb8, %eax");
    asm("jmp *%eax");
}

CNWSStore * CServerExoApp::GetStoreByGameObjectID(unsigned long)
{
    asm("leave");
    asm("mov $0x080b1db0, %eax");
    asm("jmp *%eax");
}

void * CServerExoApp::GetSysAdminList()
{
    asm("leave");
    asm("mov $0x080b1f68, %eax");
    asm("jmp *%eax");
}

CWorldTimer * CServerExoApp::GetTimestopTimer()
{
    asm("leave");
    asm("mov $0x080b1fd0, %eax");
    asm("jmp *%eax");
}

CNWSTrigger * CServerExoApp::GetTriggerByGameObjectID(unsigned long)
{
    asm("leave");
    asm("mov $0x080b1e28, %eax");
    asm("jmp *%eax");
}

CNWSWaypoint * CServerExoApp::GetWaypointByGameObjectID(unsigned long)
{
    asm("leave");
    asm("mov $0x080b1e88, %eax");
    asm("jmp *%eax");
}

CWorldTimer * CServerExoApp::GetWorldTimer()
{
    asm("leave");
    asm("mov $0x080b1fbc, %eax");
    asm("jmp *%eax");
}

void CServerExoApp::HandleGameSpyToServerMessage(int, void *, int)
{
    asm("leave");
    asm("mov $0x080b23f8, %eax");
    asm("jmp *%eax");
}

int CServerExoApp::HandleMessage(unsigned long, unsigned char *, unsigned long, int)
{
    asm("leave");
    asm("mov $0x080b2020, %eax");
    asm("jmp *%eax");
}

int CServerExoApp::Initialize()
{
    asm("leave");
    asm("mov $0x080b2038, %eax");
    asm("jmp *%eax");
}

void CServerExoApp::InitiateModuleForPlayer(void *)
{
    asm("leave");
    asm("mov $0x080b2504, %eax");
    asm("jmp *%eax");
}

int CServerExoApp::IsOnActiveExclusionList(unsigned long)
{
    asm("leave");
    asm("mov $0x080b2630, %eax");
    asm("jmp *%eax");
}

int CServerExoApp::IsOnExclusionList(unsigned long)
{
    asm("leave");
    asm("mov $0x080b26d8, %eax");
    asm("jmp *%eax");
}

int CServerExoApp::LoadCharacterFinish(CNWSPlayer *, int, int)
{
    asm("leave");
    asm("mov $0x080b1d54, %eax");
    asm("jmp *%eax");
}

int CServerExoApp::LoadCharacterStart(unsigned char, CNWSPlayer *, CResRef, void *, unsigned long)
{
    asm("leave");
    asm("mov $0x080b1d04, %eax");
    asm("jmp *%eax");
}

int CServerExoApp::LoadGame(unsigned long, CExoString &, CExoString &, CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x080b1b50, %eax");
    asm("jmp *%eax");
}

int CServerExoApp::LoadModule(CExoString, int, CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x080b2244, %eax");
    asm("jmp *%eax");
}

int CServerExoApp::LoadPrimaryPlayer(CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x080b1d6c, %eax");
    asm("jmp *%eax");
}

int CServerExoApp::MainLoop()
{
    asm("leave");
    asm("mov $0x080b2050, %eax");
    asm("jmp *%eax");
}

void CServerExoApp::MovePlayerToArea(void *)
{
    asm("leave");
    asm("mov $0x080b251c, %eax");
    asm("jmp *%eax");
}

int CServerExoApp::OnCDChange()
{
    asm("leave");
    asm("mov $0x080b2338, %eax");
    asm("jmp *%eax");
}

int CServerExoApp::OnExit()
{
    asm("leave");
    asm("mov $0x080b2350, %eax");
    asm("jmp *%eax");
}

int CServerExoApp::OnGainFocus()
{
    asm("leave");
    asm("mov $0x080b2368, %eax");
    asm("jmp *%eax");
}

int CServerExoApp::OnLostFocus()
{
    asm("leave");
    asm("mov $0x080b2380, %eax");
    asm("jmp *%eax");
}

int CServerExoApp::OnVideoChange()
{
    asm("leave");
    asm("mov $0x080b2398, %eax");
    asm("jmp *%eax");
}

void CServerExoApp::PlayerListChange(unsigned long, int, int)
{
    asm("leave");
    asm("mov $0x080b21b4, %eax");
    asm("jmp *%eax");
}

void CServerExoApp::PushMessageOverWall(unsigned char *, unsigned long)
{
    asm("leave");
    asm("mov $0x080b2abc, %eax");
    asm("jmp *%eax");
}

void CServerExoApp::RemoveCDKeyFromBannedList(CExoString)
{
    asm("leave");
    asm("mov $0x080b28e4, %eax");
    asm("jmp *%eax");
}

void CServerExoApp::RemoveFromExclusionList(unsigned long, unsigned char)
{
    asm("leave");
    asm("mov $0x080b25fc, %eax");
    asm("jmp *%eax");
}

void CServerExoApp::RemoveIPFromBannedList(CExoString)
{
    asm("leave");
    asm("mov $0x080b281c, %eax");
    asm("jmp *%eax");
}

int CServerExoApp::RemovePCFromWorld(CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x080b21fc, %eax");
    asm("jmp *%eax");
}

void CServerExoApp::RemovePlayerNameFromBannedList(CExoString)
{
    asm("leave");
    asm("mov $0x080b2880, %eax");
    asm("jmp *%eax");
}

unsigned long CServerExoApp::ResolvePlayerByFirstName(CExoString const &)
{
    asm("leave");
    asm("mov $0x080b2648, %eax");
    asm("jmp *%eax");
}

int CServerExoApp::RestartNetLayer()
{
    asm("leave");
    asm("mov $0x080b2488, %eax");
    asm("jmp *%eax");
}

int CServerExoApp::RunModule()
{
    asm("leave");
    asm("mov $0x080b22b4, %eax");
    asm("jmp *%eax");
}

int CServerExoApp::SaveGame(unsigned long, CExoString &, CExoString &, CNWSPlayer *, int, CExoString &)
{
    asm("leave");
    asm("mov $0x080b1b18, %eax");
    asm("jmp *%eax");
}

int CServerExoApp::SendCharacterQuery(CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x080b1b38, %eax");
    asm("jmp *%eax");
}

void CServerExoApp::SetApplicationIdsMatch(int)
{
    asm("leave");
    asm("mov $0x080b2c70, %eax");
    asm("jmp *%eax");
}

void CServerExoApp::SetAutoSavePending(int)
{
    asm("leave");
    asm("mov $0x080b1cdc, %eax");
    asm("jmp *%eax");
}

void CServerExoApp::SetDebugMode(int)
{
    asm("leave");
    asm("mov $0x080b1ff8, %eax");
    asm("jmp *%eax");
}

void CServerExoApp::SetEndGamePending(int)
{
    asm("leave");
    asm("mov $0x080b1bf0, %eax");
    asm("jmp *%eax");
}

void CServerExoApp::SetEndGameString(CExoString &)
{
    asm("leave");
    asm("mov $0x080b1c04, %eax");
    asm("jmp *%eax");
}

void CServerExoApp::SetExportCharacterPending(int)
{
    asm("leave");
    asm("mov $0x080b1c38, %eax");
    asm("jmp *%eax");
}

void CServerExoApp::SetExportPlayersCharacter(unsigned long)
{
    asm("leave");
    asm("mov $0x080b1c4c, %eax");
    asm("jmp *%eax");
}

int CServerExoApp::SetForceUpdate()
{
    asm("leave");
    asm("mov $0x080b23e0, %eax");
    asm("jmp *%eax");
}

void CServerExoApp::SetGameSpyEnabled(int)
{
    asm("leave");
    asm("mov $0x080b2ae4, %eax");
    asm("jmp *%eax");
}

int CServerExoApp::SetGameSpyReporting(int)
{
    asm("leave");
    asm("mov $0x080b23b0, %eax");
    asm("jmp *%eax");
}

void CServerExoApp::SetImportingChar(int)
{
    asm("leave");
    asm("mov $0x080b1cc8, %eax");
    asm("jmp *%eax");
}

void CServerExoApp::SetLoadingModule(int)
{
    asm("leave");
    asm("mov $0x080b1ca0, %eax");
    asm("jmp *%eax");
}

void CServerExoApp::SetMoveToModulePending(int)
{
    asm("leave");
    asm("mov $0x080b1b80, %eax");
    asm("jmp *%eax");
}

void CServerExoApp::SetMoveToModuleString(CExoString &)
{
    asm("leave");
    asm("mov $0x080b1ba8, %eax");
    asm("jmp *%eax");
}

int CServerExoApp::SetNetworkAddressBan(unsigned long, CExoString, int)
{
    asm("leave");
    asm("mov $0x080b20d8, %eax");
    asm("jmp *%eax");
}

void CServerExoApp::SetPauseState(unsigned char, int)
{
    asm("leave");
    asm("mov $0x080b25c0, %eax");
    asm("jmp *%eax");
}

void CServerExoApp::SetReloadModuleWhenEmpty(int)
{
    asm("leave");
    asm("mov $0x080b2670, %eax");
    asm("jmp *%eax");
}

void CServerExoApp::SetWeGotDisconnected()
{
    asm("leave");
    asm("mov $0x080b2c80, %eax");
    asm("jmp *%eax");
}

void CServerExoApp::ShutDownToMainMenu()
{
    asm("leave");
    asm("mov $0x080b2bc0, %eax");
    asm("jmp *%eax");
}

int CServerExoApp::ShutdownNetLayer()
{
    asm("leave");
    asm("mov $0x080b2470, %eax");
    asm("jmp *%eax");
}

void CServerExoApp::Shutdown(int, int)
{
    asm("leave");
    asm("mov $0x080b2214, %eax");
    asm("jmp *%eax");
}

int CServerExoApp::StartNewModule(CExoString &)
{
    asm("leave");
    asm("mov $0x080b1b68, %eax");
    asm("jmp *%eax");
}

void CServerExoApp::StartServices()
{
    asm("leave");
    asm("mov $0x080b2458, %eax");
    asm("jmp *%eax");
}

void CServerExoApp::StopServices()
{
    asm("leave");
    asm("mov $0x080b24a0, %eax");
    asm("jmp *%eax");
}

int CServerExoApp::StripColorTokens(CExoString &)
{
    asm("leave");
    asm("mov $0x080b2b0c, %eax");
    asm("jmp *%eax");
}

void CServerExoApp::TogglePauseState(unsigned char)
{
    asm("leave");
    asm("mov $0x080b2570, %eax");
    asm("jmp *%eax");
}

void CServerExoApp::Uninitialize()
{
    asm("leave");
    asm("mov $0x080b23c8, %eax");
    asm("jmp *%eax");
}

int CServerExoApp::UnloadModule()
{
    asm("leave");
    asm("mov $0x080b222c, %eax");
    asm("jmp *%eax");
}

int CServerExoApp::ValidatePlayerLogin(void *)
{
    asm("leave");
    asm("mov $0x080b24ec, %eax");
    asm("jmp *%eax");
}

void CServerExoApp::VomitServerOptionsToLog()
{
    asm("leave");
    asm("mov $0x080b21cc, %eax");
    asm("jmp *%eax");
}

