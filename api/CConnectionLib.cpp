#include "CConnectionLib.h"

int CConnectionLib::AddServer(void *, char *, char *, int, int, int, int, char *, int, int, char *, int, int, int, char *, char *, int, int, int, int, int, bool)
{
    asm("leave");
    asm("mov $0x08272a98, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::ChatNameMangle(CExoString &)
{
    asm("leave");
    asm("mov $0x08272d34, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::ClearServers()
{
    asm("leave");
    asm("mov $0x08272b74, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::ClientConnectToGameSpy(CExoString const &)
{
    asm("leave");
    asm("mov $0x08271ef8, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::ErrorClientShuttingDown(unsigned char)
{
    asm("leave");
    asm("mov $0x08272924, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::GSClientGetBuildFilter()
{
    asm("leave");
    asm("mov $0x08272a50, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::GSClientGetGroupRoomNumber()
{
    asm("leave");
    asm("mov $0x08272a10, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::GSClientGroupRoomAdded(int, unsigned long)
{
    asm("leave");
    asm("mov $0x08272948, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::GSClientJoinGroupRoom(int)
{
    asm("leave");
    asm("mov $0x082729f0, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::GSClientMessage(int, CExoString const &, CExoString const &)
{
    asm("leave");
    asm("mov $0x082729ac, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::GSClientRoomPlayerChange(int, CExoString const &, CExoString const &)
{
    asm("leave");
    asm("mov $0x08272968, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::GSClientSetBuildFilter(CExoString const &)
{
    asm("leave");
    asm("mov $0x08272a2c, %eax");
    asm("jmp *%eax");
}

CExoString CConnectionLib::GenerateCommunityNameResponse(CExoString const &, CExoString const &)
{
    asm("leave");
    asm("mov $0x082726c0, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::GenerateResponse(CExoString const &, CExoString const &, CExoString &, CExoString &)
{
    asm("leave");
    asm("mov $0x082721a0, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::GetAvailabilityStatus()
{
    asm("leave");
    asm("mov $0x0827282c, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::GetAvailability()
{
    asm("leave");
    asm("mov $0x0827283c, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::GetClientConnectionPhase()
{
    asm("leave");
    asm("mov $0x08272918, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::GetClientError()
{
    asm("leave");
    asm("mov $0x0827293c, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::GetCommunityNameStatus(CExoString const &, unsigned char **)
{
    asm("leave");
    asm("mov $0x082726ac, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::GetDigiDistModuleCipher(CExoString &, int)
{
    asm("leave");
    asm("mov $0x08272860, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::GetGSClientGameRegion()
{
    asm("leave");
    asm("mov $0x08272a80, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::GetGameFilters(CExoString *)
{
    asm("leave");
    asm("mov $0x08272ccc, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::GetGameTypeFromGroupId(int)
{
    asm("leave");
    asm("mov $0x08272c54, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::GetGroupIdFromGameType(int)
{
    asm("leave");
    asm("mov $0x08272c9c, %eax");
    asm("jmp *%eax");
}

CExoString CConnectionLib::GetKeyAuthDemand(CExoString &)
{
    asm("leave");
    asm("mov $0x08272634, %eax");
    asm("jmp *%eax");
}

CExoString CConnectionLib::GetKeyCollision()
{
    asm("leave");
    asm("mov $0x08272658, %eax");
    asm("jmp *%eax");
}

unsigned long CConnectionLib::GetKeyRejectionReason(unsigned short)
{
    asm("leave");
    asm("mov $0x08272690, %eax");
    asm("jmp *%eax");
}

unsigned short CConnectionLib::GetKeyStatus(CExoString const &, unsigned short &)
{
    asm("leave");
    asm("mov $0x0827267c, %eax");
    asm("jmp *%eax");
}

CExoString CConnectionLib::GetMasterServerInternetName()
{
    asm("leave");
    asm("mov $0x08272208, %eax");
    asm("jmp *%eax");
}

unsigned long CConnectionLib::GetMasterServerPort()
{
    asm("leave");
    asm("mov $0x0827222c, %eax");
    asm("jmp *%eax");
}

unsigned short CConnectionLib::GetMasterServerStatus()
{
    asm("leave");
    asm("mov $0x08272778, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::GetMessageOfTheDay()
{
    asm("leave");
    asm("mov $0x082726e8, %eax");
    asm("jmp *%eax");
}

unsigned long CConnectionLib::GetMessagesIn()
{
    asm("leave");
    asm("mov $0x08272610, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::GetNetConnectionUp()
{
    asm("leave");
    asm("mov $0x08272044, %eax");
    asm("jmp *%eax");
}

CNetLayer * CConnectionLib::GetNetLayer()
{
    asm("leave");
    asm("mov $0x08272524, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::GetNextBuddyEntry()
{
    asm("leave");
    asm("mov $0x08272818, %eax");
    asm("jmp *%eax");
}

CExoString CConnectionLib::GetPublicPartFromCDKey(CExoString const &)
{
    asm("leave");
    asm("mov $0x082721c8, %eax");
    asm("jmp *%eax");
}

unsigned long CConnectionLib::GetStrrefFromGameType(int)
{
    asm("leave");
    asm("mov $0x08272c24, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::GetStrrefFromGroupId(int)
{
    asm("leave");
    asm("mov $0x08272bd4, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::GetVersionNumber()
{
    asm("leave");
    asm("mov $0x0827253c, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::GetVersion()
{
    asm("leave");
    asm("mov $0x08272788, %eax");
    asm("jmp *%eax");
}

void CConnectionLib::HandleGameSpyToServerMessage(int, void *, int)
{
    asm("leave");
    asm("mov $0x08272154, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::HandleMasterServerToGameMessage(unsigned char *, unsigned long)
{
    asm("leave");
    asm("mov $0x082725f0, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::HandleServerGameSpyMessage(unsigned long, unsigned char *, unsigned long)
{
    asm("leave");
    asm("mov $0x08272130, %eax");
    asm("jmp *%eax");
}

void CConnectionLib::InitializeGameSpyRooms()
{
    asm("leave");
    asm("mov $0x08271e04, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::NewClientChallenge(unsigned long)
{
    asm("leave");
    asm("mov $0x0827218c, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::RemoveServer(void *)
{
    asm("leave");
    asm("mov $0x08272af8, %eax");
    asm("jmp *%eax");
}

void CConnectionLib::ResetMessagesInFlag(unsigned long)
{
    asm("leave");
    asm("mov $0x08272620, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::SendAddBuddyRequest(CExoString const &, CExoString const &)
{
    asm("leave");
    asm("mov $0x0827247c, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::SendClientToMasterCreateAccountPartOne(CExoString const &)
{
    asm("leave");
    asm("mov $0x082723dc, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::SendClientToMasterCreateAccountPartTwo(CExoString const &, CExoString const &, CExoString const &, unsigned char *, CExoString const &)
{
    asm("leave");
    asm("mov $0x082723fc, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::SendClientToMasterMOTDRequest(unsigned short)
{
    asm("leave");
    asm("mov $0x0827242c, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::SendClientToMasterVersionRequest(unsigned short)
{
    asm("leave");
    asm("mov $0x08272454, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::SendDigiDistAuthRequest(CExoArrayList<CExoString> *, CExoString const &)
{
    asm("leave");
    asm("mov $0x0827284c, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::SendGameToMasterAuthorizationRequest(void *, int)
{
    asm("leave");
    asm("mov $0x08272260, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::SendGameToMasterAuthorizationRequest(unsigned long, int)
{
    asm("leave");
    asm("mov $0x08272240, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::SendGameToMasterCommunityNameAuth(CExoString const &, CExoString const &, CExoString const &, unsigned short, unsigned char)
{
    asm("leave");
    asm("mov $0x08272398, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::SendGameToMasterDisconnect(void *, int)
{
    asm("leave");
    asm("mov $0x082722c0, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::SendGameToMasterDisconnect(unsigned long)
{
    asm("leave");
    asm("mov $0x082722a0, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::SendGameToMasterHeartbeat(void *, int)
{
    asm("leave");
    asm("mov $0x08272280, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::SendGameToMasterModule(unsigned char, CExoString const &)
{
    asm("leave");
    asm("mov $0x08272370, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::SendGameToMasterShutDown()
{
    asm("leave");
    asm("mov $0x08272350, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::SendGameToMasterStartup(unsigned char, unsigned long, int, unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x08272300, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::SendGameToMasterStatusRequest()
{
    asm("leave");
    asm("mov $0x082722e0, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::SendGetAvailabilityRequest(CExoString const &)
{
    asm("leave");
    asm("mov $0x08272504, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::SendGetBuddyListRequest(CExoString const &)
{
    asm("leave");
    asm("mov $0x082724bc, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::SendMessageToNick(char const *, char const *)
{
    asm("leave");
    asm("mov $0x08272bb0, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::SendMessageToRoom(char const *)
{
    asm("leave");
    asm("mov $0x08272b8c, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::SendRemoveBuddyRequest(CExoString const &, CExoString const &)
{
    asm("leave");
    asm("mov $0x0827249c, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::SendSetAvailabilityRequest(CExoString const &, unsigned short)
{
    asm("leave");
    asm("mov $0x082724dc, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::ServerConnectToGameSpy(unsigned int)
{
    asm("leave");
    asm("mov $0x08272050, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::SetGSClientGameRegion(int)
{
    asm("leave");
    asm("mov $0x08272a68, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::SetGameFilters(unsigned long, CExoString *)
{
    asm("leave");
    asm("mov $0x08272cf4, %eax");
    asm("jmp *%eax");
}

void CConnectionLib::SetLanguage(int)
{
    asm("leave");
    asm("mov $0x08272010, %eax");
    asm("jmp *%eax");
}

void CConnectionLib::SetNetConnectionUp(int)
{
    asm("leave");
    asm("mov $0x08272034, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::ShutDownClientGameSpyConnection()
{
    asm("leave");
    asm("mov $0x08272874, %eax");
    asm("jmp *%eax");
}

void CConnectionLib::ShutDownServerGameSpyConnection()
{
    asm("leave");
    asm("mov $0x082720e4, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::StartMstHeartbeatTimer(unsigned long long)
{
    asm("leave");
    asm("mov $0x08272560, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::StartSystemUpdateTimer(unsigned long long)
{
    asm("leave");
    asm("mov $0x08272588, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::StartTimeOutTimer(unsigned long long)
{
    asm("leave");
    asm("mov $0x082725b0, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::TimeOutTimerRunning()
{
    asm("leave");
    asm("mov $0x082725d8, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::UpdateConnectionPhase(unsigned char, CExoString const &)
{
    asm("leave");
    asm("mov $0x082728e8, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::UpdateGameSpyClient()
{
    asm("leave");
    asm("mov $0x082728a0, %eax");
    asm("jmp *%eax");
}

void CConnectionLib::UpdateGameSpyServer()
{
    asm("leave");
    asm("mov $0x08272110, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::UpdateMstHeartbeatTimer(unsigned long long)
{
    asm("leave");
    asm("mov $0x08272574, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::UpdateServer(void *, char *, char *, int, int, int, int, char *, int, int, char *, int, int, int, char *, char *, int, int, int, int, int, bool)
{
    asm("leave");
    asm("mov $0x08272b14, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::UpdateSystemUpdateTimer(unsigned long long)
{
    asm("leave");
    asm("mov $0x0827259c, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::UpdateTimeOutTimer(unsigned long long)
{
    asm("leave");
    asm("mov $0x082725c4, %eax");
    asm("jmp *%eax");
}

int CConnectionLib::ValidateCdKey(char *)
{
    asm("leave");
    asm("mov $0x08272178, %eax");
    asm("jmp *%eax");
}

