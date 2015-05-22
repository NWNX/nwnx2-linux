#include "CServerExoAppInternal.h"

void CServerExoAppInternal::AddCDKeyToBannedList(CExoString)
{
    asm("leave");
    asm("mov $0x080b0eb4, %eax");
    asm("jmp *%eax");
}

void CServerExoAppInternal::AddCharListRequest(unsigned long)
{
    asm("leave");
    asm("mov $0x080b0c80, %eax");
    asm("jmp *%eax");
}

void CServerExoAppInternal::AddIPToBannedList(CExoString)
{
    asm("leave");
    asm("mov $0x080b0dc4, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::AddPendingAuthorization(unsigned long)
{
    asm("leave");
    asm("mov $0x080b07fc, %eax");
    asm("jmp *%eax");
}

void CServerExoAppInternal::AddPlayerNameToBannedList(CExoString)
{
    asm("leave");
    asm("mov $0x080b0e3c, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::AddSubNetProfileRecvSize(unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x080b131c, %eax");
    asm("jmp *%eax");
}

void CServerExoAppInternal::AddSubNetProfileSendSize(unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x080b12a4, %eax");
    asm("jmp *%eax");
}

void CServerExoAppInternal::AddSubNetProfile(unsigned long, CExoString, CExoString)
{
    asm("leave");
    asm("mov $0x080af7ac, %eax");
    asm("jmp *%eax");
}

void CServerExoAppInternal::AddToExclusionList(unsigned long, unsigned char)
{
    asm("leave");
    asm("mov $0x080adf8c, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::AdmitNetworkAddress(unsigned long, CExoString)
{
    asm("leave");
    asm("mov $0x080afcd0, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::AdmitPlayerName(CExoString)
{
    asm("leave");
    asm("mov $0x080afd00, %eax");
    asm("jmp *%eax");
}

void CServerExoAppInternal::CheckMasterServerTranslation()
{
    asm("leave");
    asm("mov $0x080ae270, %eax");
    asm("jmp *%eax");
}

void CServerExoAppInternal::ConnectionLibMainLoop()
{
    asm("leave");
    asm("mov $0x080ab720, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::ContinueMessageProcessing()
{
    asm("leave");
    asm("mov $0x080b02e4, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::CopyModuleToCurrentGame(CExoString &, CExoString &, unsigned short)
{
    asm("leave");
    asm("mov $0x0809e430, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::CreateServerVaultLostAndFound()
{
    asm("leave");
    asm("mov $0x080b1214, %eax");
    asm("jmp *%eax");
}

void CServerExoAppInternal::DealWithLoadGameError(unsigned long)
{
    asm("leave");
    asm("mov $0x080a10f4, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::EndGame(CExoString const &)
{
    asm("leave");
    asm("mov $0x08099a90, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::ExportAllPlayers()
{
    asm("leave");
    asm("mov $0x080afeb0, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::ExportPlayer(CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x080aff10, %eax");
    asm("jmp *%eax");
}

CExoLinkedList<unsigned long> * CServerExoAppInternal::GetActiveExclusionList()
{
    asm("leave");
    asm("mov $0x080ae088, %eax");
    asm("jmp *%eax");
}

unsigned char CServerExoAppInternal::GetActivePauseState()
{
    asm("leave");
    asm("mov $0x080b0a38, %eax");
    asm("jmp *%eax");
}

CWorldTimer * CServerExoAppInternal::GetActiveTimer(unsigned long)
{
    asm("leave");
    asm("mov $0x080ada7c, %eax");
    asm("jmp *%eax");
}

CNWSArea * CServerExoAppInternal::GetAreaByGameObjectID(unsigned long)
{
    asm("leave");
    asm("mov $0x080b0484, %eax");
    asm("jmp *%eax");
}

CNWSAreaOfEffectObject * CServerExoAppInternal::GetAreaOfEffectByGameObjectID(unsigned long)
{
    asm("leave");
    asm("mov $0x080b05d4, %eax");
    asm("jmp *%eax");
}

CExoString CServerExoAppInternal::GetBannedListString()
{
    asm("leave");
    asm("mov $0x080ad4b0, %eax");
    asm("jmp *%eax");
}

CNWSPlayer * CServerExoAppInternal::GetClientObjectByObjectId(unsigned long)
{
    asm("leave");
    asm("mov $0x080afd30, %eax");
    asm("jmp *%eax");
}

CNWSClient * CServerExoAppInternal::GetClientObjectByPlayerId(unsigned long, unsigned char)
{
    asm("leave");
    asm("mov $0x08098e94, %eax");
    asm("jmp *%eax");
}

CNWSCreature * CServerExoAppInternal::GetCreatureByGameObjectID(unsigned long)
{
    asm("leave");
    asm("mov $0x080b03dc, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::GetDifficultyOption(int)
{
    asm("leave");
    asm("mov $0x080b0c58, %eax");
    asm("jmp *%eax");
}

CNWSDoor * CServerExoAppInternal::GetDoorByGameObjectID(unsigned long)
{
    asm("leave");
    asm("mov $0x080b0580, %eax");
    asm("jmp *%eax");
}

CNWSEncounter * CServerExoAppInternal::GetEncounterByGameObjectID(unsigned long)
{
    asm("leave");
    asm("mov $0x080b067c, %eax");
    asm("jmp *%eax");
}

void CServerExoAppInternal::GetExtendedServerInfo(CExtendedServerInfo *)
{
    asm("leave");
    asm("mov $0x080a0318, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::GetFactionOfObject(unsigned long, int *)
{
    asm("leave");
    asm("mov $0x080ac4d4, %eax");
    asm("jmp *%eax");
}

unsigned long CServerExoAppInternal::GetFirstPCObject()
{
    asm("leave");
    asm("mov $0x080b1100, %eax");
    asm("jmp *%eax");
}

CGameObject * CServerExoAppInternal::GetGameObject(unsigned long)
{
    asm("leave");
    asm("mov $0x080b02fc, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::GetIsCDKeyOnBannedList(CExoString)
{
    asm("leave");
    asm("mov $0x080aef04, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::GetIsIPOnBannedList(CExoString)
{
    asm("leave");
    asm("mov $0x080ae8dc, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::GetIsPlayerNameOnBannedList(CExoString)
{
    asm("leave");
    asm("mov $0x080aec10, %eax");
    asm("jmp *%eax");
}

CNWSItem * CServerExoAppInternal::GetItemByGameObjectID(unsigned long)
{
    asm("leave");
    asm("mov $0x080b0388, %eax");
    asm("jmp *%eax");
}

CNWSModule * CServerExoAppInternal::GetModuleByGameObjectID(unsigned long)
{
    asm("leave");
    asm("mov $0x080b0430, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::GetModuleExists(CExoString const &)
{
    asm("leave");
    asm("mov $0x0809fd64, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::GetModuleLanguage()
{
    asm("leave");
    asm("mov $0x080b0790, %eax");
    asm("jmp *%eax");
}

CExoString CServerExoAppInternal::GetModuleName()
{
    asm("leave");
    asm("mov $0x08098f58, %eax");
    asm("jmp *%eax");
}

CNWSModule * CServerExoAppInternal::GetModule()
{
    asm("leave");
    asm("mov $0x080afdc8, %eax");
    asm("jmp *%eax");
}

unsigned long CServerExoAppInternal::GetNextPCObject()
{
    asm("leave");
    asm("mov $0x080b117c, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::GetPauseState(unsigned char)
{
    asm("leave");
    asm("mov $0x080b0958, %eax");
    asm("jmp *%eax");
}

CNWSPlaceable * CServerExoAppInternal::GetPlaceableByGameObjectID(unsigned long)
{
    asm("leave");
    asm("mov $0x080b052c, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::GetPlayerAddressData(unsigned long, unsigned long *, unsigned char **, unsigned char **, unsigned long *)
{
    asm("leave");
    asm("mov $0x080b0000, %eax");
    asm("jmp *%eax");
}

unsigned long CServerExoAppInternal::GetPlayerIDByGameObjectID(unsigned long)
{
    asm("leave");
    asm("mov $0x080b0bb0, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::GetPlayerLanguage(unsigned long)
{
    asm("leave");
    asm("mov $0x080b0724, %eax");
    asm("jmp *%eax");
}

CExoString CServerExoAppInternal::GetPlayerListString()
{
    asm("leave");
    asm("mov $0x080ac5e8, %eax");
    asm("jmp *%eax");
}

CExoString CServerExoAppInternal::GetPortalListString()
{
    asm("leave");
    asm("mov $0x080b08a8, %eax");
    asm("jmp *%eax");
}

void CServerExoAppInternal::GetServerInfoFromIniFile()
{
    asm("leave");
    asm("mov $0x080a5570, %eax");
    asm("jmp *%eax");
}

CNWSSoundObject * CServerExoAppInternal::GetSoundObjectByGameObjectID(unsigned long)
{
    asm("leave");
    asm("mov $0x080b06d0, %eax");
    asm("jmp *%eax");
}

CNWSStore * CServerExoAppInternal::GetStoreByGameObjectID(unsigned long)
{
    asm("leave");
    asm("mov $0x080b0334, %eax");
    asm("jmp *%eax");
}

CNWSTrigger * CServerExoAppInternal::GetTriggerByGameObjectID(unsigned long)
{
    asm("leave");
    asm("mov $0x080b04d8, %eax");
    asm("jmp *%eax");
}

CNWSWaypoint * CServerExoAppInternal::GetWaypointByGameObjectID(unsigned long)
{
    asm("leave");
    asm("mov $0x080b0628, %eax");
    asm("jmp *%eax");
}

void CServerExoAppInternal::HandleGameSpyToServerMessage(int, void *, int)
{
    asm("leave");
    asm("mov $0x080ab024, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::HandleMessage(unsigned long, unsigned char *, unsigned long, int)
{
    asm("leave");
    asm("mov $0x0809df80, %eax");
    asm("jmp *%eax");
}

void CServerExoAppInternal::InitializeNetLayer()
{
    asm("leave");
    asm("mov $0x080a5238, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::Initialize()
{
    asm("leave");
    asm("mov $0x080affc8, %eax");
    asm("jmp *%eax");
}

void CServerExoAppInternal::InitiateModuleForPlayer(void *)
{
    asm("leave");
    asm("mov $0x080a1284, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::IsOnActiveExclusionList(unsigned long)
{
    asm("leave");
    asm("mov $0x080b0b44, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::IsOnExclusionList(unsigned long)
{
    asm("leave");
    asm("mov $0x080ade9c, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::LoadCharacterFinish(CNWSPlayer *, int, int)
{
    asm("leave");
    asm("mov $0x0809da64, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::LoadCharacterStart(unsigned char, CNWSPlayer *, CResRef, void *, unsigned long)
{
    asm("leave");
    asm("mov $0x0809cbd4, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::LoadGame(unsigned long, CExoString &, CExoString &, CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x08099760, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::LoadModule(CExoString, int, CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x0809e4e8, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::LoadPrimaryPlayer(CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x080afe64, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::MainLoop()
{
    asm("leave");
    asm("mov $0x080a0474, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::MarkUpdateClientsForObject(unsigned long)
{
    asm("leave");
    asm("mov $0x080b0104, %eax");
    asm("jmp *%eax");
}

void CServerExoAppInternal::MovePlayerToArea(void *)
{
    asm("leave");
    asm("mov $0x080a1b08, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::OnCDChange()
{
    asm("leave");
    asm("mov $0x080b0024, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::OnExit()
{
    asm("leave");
    asm("mov $0x080b002c, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::OnGainFocus()
{
    asm("leave");
    asm("mov $0x080b0034, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::OnLostFocus()
{
    asm("leave");
    asm("mov $0x080b003c, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::OnVideoChange()
{
    asm("leave");
    asm("mov $0x080b0044, %eax");
    asm("jmp *%eax");
}

void CServerExoAppInternal::PlayerListChange(unsigned long, int, int)
{
    asm("leave");
    asm("mov $0x080a1d18, %eax");
    asm("jmp *%eax");
}

void CServerExoAppInternal::PushMessageOverWall(unsigned char *, unsigned long)
{
    asm("leave");
    asm("mov $0x080b11e4, %eax");
    asm("jmp *%eax");
}

void CServerExoAppInternal::ReadBannedLists()
{
    asm("leave");
    asm("mov $0x080a9910, %eax");
    asm("jmp *%eax");
}

void CServerExoAppInternal::RemoveCDKeyFromBannedList(CExoString)
{
    asm("leave");
    asm("mov $0x080b1064, %eax");
    asm("jmp *%eax");
}

void CServerExoAppInternal::RemoveFromExclusionList(unsigned long, unsigned char)
{
    asm("leave");
    asm("mov $0x080b0a5c, %eax");
    asm("jmp *%eax");
}

void CServerExoAppInternal::RemoveIPFromBannedList(CExoString)
{
    asm("leave");
    asm("mov $0x080b0f2c, %eax");
    asm("jmp *%eax");
}

void CServerExoAppInternal::RemovePCFromWorld(CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x080a4c94, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::RemovePendingAuthorization(unsigned long)
{
    asm("leave");
    asm("mov $0x080b0854, %eax");
    asm("jmp *%eax");
}

void CServerExoAppInternal::RemovePlayerNameFromBannedList(CExoString)
{
    asm("leave");
    asm("mov $0x080b0fc8, %eax");
    asm("jmp *%eax");
}

void CServerExoAppInternal::RemoveSubNetProfile(unsigned long)
{
    asm("leave");
    asm("mov $0x080af90c, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::ReprocessExclusionListActions(unsigned char)
{
    asm("leave");
    asm("mov $0x080b0970, %eax");
    asm("jmp *%eax");
}

unsigned long CServerExoAppInternal::ResolvePlayerByFirstName(CExoString const &)
{
    asm("leave");
    asm("mov $0x080ae0d4, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::RestartNetLayer()
{
    asm("leave");
    asm("mov $0x080b00f8, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::RunModule()
{
    asm("leave");
    asm("mov $0x080a28a4, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::SaveGame(unsigned long, CExoString &, CExoString &, CNWSPlayer *, int, CExoString &)
{
    asm("leave");
    asm("mov $0x0809902c, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::SendCharacterQuery(CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x080aff6c, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::SendEnteringStartNewModuleMessage()
{
    asm("leave");
    asm("mov $0x080afe0c, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::SendExitingStartNewModuleMessage(int)
{
    asm("leave");
    asm("mov $0x080afe34, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::SendHeartbeatToMasterServer()
{
    asm("leave");
    asm("mov $0x080ae4e4, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::SendStartStallEvent(unsigned long)
{
    asm("leave");
    asm("mov $0x080affd4, %eax");
    asm("jmp *%eax");
}

void CServerExoAppInternal::SetEstimatedSaveSize(CExoString const &, unsigned short)
{
    asm("leave");
    asm("mov $0x080a01a8, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::SetGameSpyReporting(int)
{
    asm("leave");
    asm("mov $0x080b0798, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::SetNetworkAddressBan(unsigned long, CExoString, int)
{
    asm("leave");
    asm("mov $0x080b004c, %eax");
    asm("jmp *%eax");
}

void CServerExoAppInternal::SetPauseState(unsigned char, int)
{
    asm("leave");
    asm("mov $0x080adb18, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::ShutdownNetLayer()
{
    asm("leave");
    asm("mov $0x080b00c0, %eax");
    asm("jmp *%eax");
}

void CServerExoAppInternal::ShutdownServerProfiles()
{
    asm("leave");
    asm("mov $0x080afb1c, %eax");
    asm("jmp *%eax");
}

void CServerExoAppInternal::Shutdown(int, int)
{
    asm("leave");
    asm("mov $0x080a4fd0, %eax");
    asm("jmp *%eax");
}

void CServerExoAppInternal::StallEventSaveGame()
{
    asm("leave");
    asm("mov $0x080a0e64, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::StartNewModule(CExoString &)
{
    asm("leave");
    asm("mov $0x08099b68, %eax");
    asm("jmp *%eax");
}

void CServerExoAppInternal::StartServices()
{
    asm("leave");
    asm("mov $0x080a2af8, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::StartShutdownTimer(unsigned long long, unsigned long long)
{
    asm("leave");
    asm("mov $0x080b0c98, %eax");
    asm("jmp *%eax");
}

void CServerExoAppInternal::StopServices()
{
    asm("leave");
    asm("mov $0x080a4524, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::StorePlayerCharacters()
{
    asm("leave");
    asm("mov $0x0809a8b4, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::StripColorTokens(CExoString &)
{
    asm("leave");
    asm("mov $0x080af440, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::Test_Unit_Script_Compile()
{
    asm("leave");
    asm("mov $0x080af110, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::Test_Unit_Script_Run()
{
    asm("leave");
    asm("mov $0x080af2f0, %eax");
    asm("jmp *%eax");
}

void CServerExoAppInternal::TogglePauseState(unsigned char)
{
    asm("leave");
    asm("mov $0x080b0924, %eax");
    asm("jmp *%eax");
}

void CServerExoAppInternal::Uninitialize()
{
    asm("leave");
    asm("mov $0x080b0298, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::UnloadModule()
{
    asm("leave");
    asm("mov $0x0809e070, %eax");
    asm("jmp *%eax");
}

void CServerExoAppInternal::UnlockBiowareModule(CNWSModule *)
{
    asm("leave");
    asm("mov $0x08099c24, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::UpdateAutoSaveTimer()
{
    asm("leave");
    asm("mov $0x080af018, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::UpdateClientGameObjectsForPlayer(CNWSPlayer *, int, unsigned long long)
{
    asm("leave");
    asm("mov $0x080a4a70, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::UpdateClientGameObjects(int)
{
    asm("leave");
    asm("mov $0x080b021c, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::UpdateClientsForObject(unsigned long)
{
    asm("leave");
    asm("mov $0x080b0198, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::UpdateLogHeartbeatTimer(unsigned long long)
{
    asm("leave");
    asm("mov $0x080b0cc8, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::UpdateShutdownTimer(unsigned long long)
{
    asm("leave");
    asm("mov $0x080ae6f0, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::UpdateWindowTitle()
{
    asm("leave");
    asm("mov $0x080b00b8, %eax");
    asm("jmp *%eax");
}

unsigned long CServerExoAppInternal::ValidateCreateServerCharacter(CNWSPlayer *, void *, unsigned long)
{
    asm("leave");
    asm("mov $0x0809ae78, %eax");
    asm("jmp *%eax");
}

int CServerExoAppInternal::ValidatePlayerLogin(void *)
{
    asm("leave");
    asm("mov $0x080b02a0, %eax");
    asm("jmp *%eax");
}

void CServerExoAppInternal::VomitServerOptionsToLog()
{
    asm("leave");
    asm("mov $0x080aa870, %eax");
    asm("jmp *%eax");
}

void CServerExoAppInternal::WriteServerInfoToIniFile()
{
    asm("leave");
    asm("mov $0x080a9e14, %eax");
    asm("jmp *%eax");
}

