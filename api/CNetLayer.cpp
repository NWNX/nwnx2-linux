#include "CNetLayer.h"

int CNetLayer::CleanUpEnumerateSpecific()
{
    asm("leave");
    asm("mov $0x082ad3e0, %eax");
    asm("jmp *%eax");
}

int CNetLayer::ClearSessionInfoChanged(unsigned long)
{
    asm("leave");
    asm("mov $0x082ad5e0, %eax");
    asm("jmp *%eax");
}

int CNetLayer::CloseStandardConnection(int)
{
    asm("leave");
    asm("mov $0x082adb5c, %eax");
    asm("jmp *%eax");
}

int CNetLayer::DisconnectFromSession()
{
    asm("leave");
    asm("mov $0x082ad43c, %eax");
    asm("jmp *%eax");
}

int CNetLayer::DisconnectPlayer(unsigned long, unsigned long, int)
{
    asm("leave");
    asm("mov $0x082ad478, %eax");
    asm("jmp *%eax");
}

int CNetLayer::DropConnectionToServer()
{
    asm("leave");
    asm("mov $0x082ad450, %eax");
    asm("jmp *%eax");
}

int CNetLayer::EndConnectToSession()
{
    asm("leave");
    asm("mov $0x082ad414, %eax");
    asm("jmp *%eax");
}

int CNetLayer::EndEnumerateSessions()
{
    asm("leave");
    asm("mov $0x082ad3cc, %eax");
    asm("jmp *%eax");
}

int CNetLayer::EndInternetAddressTranslation()
{
    asm("leave");
    asm("mov $0x082ad774, %eax");
    asm("jmp *%eax");
}

int CNetLayer::EndPing(unsigned long)
{
    asm("leave");
    asm("mov $0x082ad538, %eax");
    asm("jmp *%eax");
}

int CNetLayer::EndProtocol(unsigned long)
{
    asm("leave");
    asm("mov $0x082ad130, %eax");
    asm("jmp *%eax");
}

int CNetLayer::EndServerMode()
{
    asm("leave");
    asm("mov $0x082ad37c, %eax");
    asm("jmp *%eax");
}

int CNetLayer::EnumerateSessionsList(unsigned char)
{
    asm("leave");
    asm("mov $0x082ad7dc, %eax");
    asm("jmp *%eax");
}

int CNetLayer::GetAnySessionsEnumerated()
{
    asm("leave");
    asm("mov $0x082ad7f8, %eax");
    asm("jmp *%eax");
}

int CNetLayer::GetAnyWindowBehind()
{
    asm("leave");
    asm("mov $0x082ada64, %eax");
    asm("jmp *%eax");
}

int CNetLayer::GetClientConnected()
{
    asm("leave");
    asm("mov $0x082ad79c, %eax");
    asm("jmp *%eax");
}

int CNetLayer::GetConnectionError()
{
    asm("leave");
    asm("mov $0x082ad428, %eax");
    asm("jmp *%eax");
}

int CNetLayer::GetConnectionsMustBeValidated()
{
    asm("leave");
    asm("mov $0x082adbac, %eax");
    asm("jmp *%eax");
}

int CNetLayer::GetDisconnectStrref()
{
    asm("leave");
    asm("mov $0x082ad498, %eax");
    asm("jmp *%eax");
}

int CNetLayer::GetExoApp()
{
    asm("leave");
    asm("mov $0x082ad094, %eax");
    asm("jmp *%eax");
}

int CNetLayer::GetExoNet()
{
    asm("leave");
    asm("mov $0x082ad8b4, %eax");
    asm("jmp *%eax");
}

unsigned short CNetLayer::GetExpansionPackReqd()
{
    asm("leave");
    asm("mov $0x082ada2c, %eax");
    asm("jmp *%eax");
}

CExoString CNetLayer::GetGameMasterPassword()
{
    asm("leave");
    asm("mov $0x082ad264, %eax");
    asm("jmp *%eax");
}

int CNetLayer::GetGameMasterPermision() const
{
    asm("leave");
    asm("mov $0x082ad87c, %eax");
    asm("jmp *%eax");
}

int CNetLayer::GetIPBySessionId(unsigned long, CExoString *)
{
    asm("leave");
    asm("mov $0x082adb78, %eax");
    asm("jmp *%eax");
}

unsigned long CNetLayer::GetInternetAddressTranslationStatus(unsigned char *)
{
    asm("leave");
    asm("mov $0x082ad760, %eax");
    asm("jmp *%eax");
}

int CNetLayer::GetLocalAdapterString(unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x082ad4d0, %eax");
    asm("jmp *%eax");
}

int CNetLayer::GetLocalPrivileges(unsigned long)
{
    asm("leave");
    asm("mov $0x082ad820, %eax");
    asm("jmp *%eax");
}

int CNetLayer::GetMessageFromStandardConnection(int *, char **, int *)
{
    asm("leave");
    asm("mov $0x082adb14, %eax");
    asm("jmp *%eax");
}

int CNetLayer::GetNumberLocalAdapters(unsigned long)
{
    asm("leave");
    asm("mov $0x082ad4bc, %eax");
    asm("jmp *%eax");
}

int CNetLayer::GetPasswordRequired()
{
    asm("leave");
    asm("mov $0x082ad1c4, %eax");
    asm("jmp *%eax");
}

int CNetLayer::GetPlayerAddressData(unsigned long, unsigned long *, unsigned char **, unsigned char **, unsigned long *)
{
    asm("leave");
    asm("mov $0x082ad54c, %eax");
    asm("jmp *%eax");
}

CExoString CNetLayer::GetPlayerAddress(unsigned long)
{
    asm("leave");
    asm("mov $0x082ad858, %eax");
    asm("jmp *%eax");
}

CNetLayerPlayerInfo * CNetLayer::GetPlayerInfo(unsigned long)
{
    asm("leave");
    asm("mov $0x082ad834, %eax");
    asm("jmp *%eax");
}

CExoString CNetLayer::GetPlayerPassword()
{
    asm("leave");
    asm("mov $0x082ad1d8, %eax");
    asm("jmp *%eax");
}

int CNetLayer::GetPortBySessionId(unsigned long)
{
    asm("leave");
    asm("mov $0x082ad6b8, %eax");
    asm("jmp *%eax");
}

unsigned long CNetLayer::GetSendUDPSocket()
{
    asm("leave");
    asm("mov $0x082ad92c, %eax");
    asm("jmp *%eax");
}

CExoString CNetLayer::GetServerAdminPassword()
{
    asm("leave");
    asm("mov $0x082ad2f0, %eax");
    asm("jmp *%eax");
}

int CNetLayer::GetServerConnected()
{
    asm("leave");
    asm("mov $0x082ad7c8, %eax");
    asm("jmp *%eax");
}

int CNetLayer::GetServerNetworkAddress()
{
    asm("leave");
    asm("mov $0x082ad8cc, %eax");
    asm("jmp *%eax");
}

int CNetLayer::GetSessionInfoChanged(unsigned long)
{
    asm("leave");
    asm("mov $0x082ad5c8, %eax");
    asm("jmp *%eax");
}

int CNetLayer::GetSessionInfo(unsigned long)
{
    asm("leave");
    asm("mov $0x082ad6cc, %eax");
    asm("jmp *%eax");
}

unsigned long CNetLayer::GetSessionMaxPlayers()
{
    asm("leave");
    asm("mov $0x082ad5f4, %eax");
    asm("jmp *%eax");
}

CExoString CNetLayer::GetSessionName()
{
    asm("leave");
    asm("mov $0x082ad61c, %eax");
    asm("jmp *%eax");
}

unsigned long CNetLayer::GetUDPRecievePort()
{
    asm("leave");
    asm("mov $0x082ad6a4, %eax");
    asm("jmp *%eax");
}

int CNetLayer::Initialize(CBaseExoApp *)
{
    asm("leave");
    asm("mov $0x082ad080, %eax");
    asm("jmp *%eax");
}

int CNetLayer::IsConnectedToLocalhost()
{
    asm("leave");
    asm("mov $0x082ad464, %eax");
    asm("jmp *%eax");
}

int CNetLayer::MessageArrived(unsigned long, unsigned long, unsigned long, int)
{
    asm("leave");
    asm("mov $0x082ad0d0, %eax");
    asm("jmp *%eax");
}

int CNetLayer::OpenStandardConnection(int, CExoString, int)
{
    asm("leave");
    asm("mov $0x082ada7c, %eax");
    asm("jmp *%eax");
}

int CNetLayer::PlayerIdToConnectionId(unsigned long, unsigned long *)
{
    asm("leave");
    asm("mov $0x082ada48, %eax");
    asm("jmp *%eax");
}

void CNetLayer::ProcessReceivedFrames(int)
{
    asm("leave");
    asm("mov $0x082ad0a8, %eax");
    asm("jmp *%eax");
}

int CNetLayer::RequestExtendedServerInfo(unsigned long, int, int)
{
    asm("leave");
    asm("mov $0x082ad4f8, %eax");
    asm("jmp *%eax");
}

int CNetLayer::RequestServerDetails(unsigned long)
{
    asm("leave");
    asm("mov $0x082ad510, %eax");
    asm("jmp *%eax");
}

int CNetLayer::SendMessageToAddress(unsigned long, unsigned char *, unsigned long)
{
    asm("leave");
    asm("mov $0x082ad100, %eax");
    asm("jmp *%eax");
}

int CNetLayer::SendMessageToPlayer(unsigned long, unsigned char *, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x082ad0e8, %eax");
    asm("jmp *%eax");
}

int CNetLayer::SendMessageToStandardConnection(int, char *, int)
{
    asm("leave");
    asm("mov $0x082adb38, %eax");
    asm("jmp *%eax");
}

void CNetLayer::SetConnectionsDisallowed(int)
{
    asm("leave");
    asm("mov $0x082adb94, %eax");
    asm("jmp *%eax");
}

void CNetLayer::SetConnectionsMustBeValidated(int)
{
    asm("leave");
    asm("mov $0x082adbc4, %eax");
    asm("jmp *%eax");
}

int CNetLayer::SetDisconnectStrref(unsigned long)
{
    asm("leave");
    asm("mov $0x082ad4a8, %eax");
    asm("jmp *%eax");
}

void CNetLayer::SetExpansionPackReqd(unsigned short)
{
    asm("leave");
    asm("mov $0x082ada14, %eax");
    asm("jmp *%eax");
}

int CNetLayer::SetGameMasterPassword(CExoString)
{
    asm("leave");
    asm("mov $0x082ad288, %eax");
    asm("jmp *%eax");
}

void CNetLayer::SetMasterServerInternetAddress(unsigned char const *, unsigned long)
{
    asm("leave");
    asm("mov $0x082ad908, %eax");
    asm("jmp *%eax");
}

int CNetLayer::SetMstServerPassword(CExoString)
{
    asm("leave");
    asm("mov $0x082ad970, %eax");
    asm("jmp *%eax");
}

int CNetLayer::SetPlayerPassword(CExoString)
{
    asm("leave");
    asm("mov $0x082ad1fc, %eax");
    asm("jmp *%eax");
}

int CNetLayer::SetServerAdminPassword(CExoString)
{
    asm("leave");
    asm("mov $0x082ad314, %eax");
    asm("jmp *%eax");
}

void CNetLayer::SetServerLanguage(int)
{
    asm("leave");
    asm("mov $0x082ad144, %eax");
    asm("jmp *%eax");
}

int CNetLayer::SetSessionInfoChanged(unsigned long, int)
{
    asm("leave");
    asm("mov $0x082ad580, %eax");
    asm("jmp *%eax");
}

void CNetLayer::SetSessionMaxPlayers(unsigned long)
{
    asm("leave");
    asm("mov $0x082ad608, %eax");
    asm("jmp *%eax");
}

void CNetLayer::SetSessionName(CExoString)
{
    asm("leave");
    asm("mov $0x082ad640, %eax");
    asm("jmp *%eax");
}

int CNetLayer::SetUpPlayBackConnection()
{
    asm("leave");
    asm("mov $0x082ad6e0, %eax");
    asm("jmp *%eax");
}

int CNetLayer::ShutDownClientInterfaceWithReason(unsigned long)
{
    asm("leave");
    asm("mov $0x082ad94c, %eax");
    asm("jmp *%eax");
}

int CNetLayer::ShutDown()
{
    asm("leave");
    asm("mov $0x082ad0bc, %eax");
    asm("jmp *%eax");
}

int CNetLayer::StartConnectToSession(unsigned long, CExoString const &, int, int, CExoString const &, unsigned long, unsigned long, CExoString const &)
{
    asm("leave");
    asm("mov $0x082ad3f4, %eax");
    asm("jmp *%eax");
}

int CNetLayer::StartEnumerateSessions(unsigned long, int, unsigned char *, unsigned short, int, unsigned short, CExoString *, unsigned short, CExoString *, unsigned short, CExoString *)
{
    asm("leave");
    asm("mov $0x082ad390, %eax");
    asm("jmp *%eax");
}

int CNetLayer::StartInternetAddressTranslation(CExoString, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x082ad6f4, %eax");
    asm("jmp *%eax");
}

int CNetLayer::StartPing(unsigned long)
{
    asm("leave");
    asm("mov $0x082ad524, %eax");
    asm("jmp *%eax");
}

int CNetLayer::StartProtocol(unsigned long, unsigned long, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x082ad118, %eax");
    asm("jmp *%eax");
}

int CNetLayer::StartServerMode(CExoString, unsigned long)
{
    asm("leave");
    asm("mov $0x082ad158, %eax");
    asm("jmp *%eax");
}

void CNetLayer::StoreMessage(unsigned char *, unsigned long)
{
    asm("leave");
    asm("mov $0x082ad56c, %eax");
    asm("jmp *%eax");
}

int CNetLayer::TranslateAddressFromString(char *, unsigned long *, unsigned char *, unsigned char *, unsigned long *)
{
    asm("leave");
    asm("mov $0x082ad894, %eax");
    asm("jmp *%eax");
}

int CNetLayer::UpdateStatusLoop(unsigned long)
{
    asm("leave");
    asm("mov $0x082ad788, %eax");
    asm("jmp *%eax");
}

