#include "CNetLayerInternal.h"

int CNetLayerInternal::BroadcastMessageToAddress(unsigned long, unsigned long, unsigned char *, unsigned long)
{
    asm("leave");
    asm("mov $0x082ab924, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::CRCBlock(unsigned char *, unsigned long)
{
    asm("leave");
    asm("mov $0x082ac810, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::CRCBuildTable()
{
    asm("leave");
    asm("mov $0x082ac7d0, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::CRCEncodeFrame(unsigned char *, unsigned long)
{
    asm("leave");
    asm("mov $0x082ac848, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::CRCVerifyFrame(unsigned char *, unsigned long)
{
    asm("leave");
    asm("mov $0x082ac8a8, %eax");
    asm("jmp *%eax");
}

void CNetLayerInternal::CheckMasterServerTimeouts()
{
    asm("leave");
    asm("mov $0x082aab20, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::CleanUpEnumerateSpecific()
{
    asm("leave");
    asm("mov $0x082abffc, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::ClearSessionInfoChanged(unsigned long)
{
    asm("leave");
    asm("mov $0x082ac070, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::CloseStandardConnection(int)
{
    asm("leave");
    asm("mov $0x082aca44, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::ConnectToSessionLoop()
{
    asm("leave");
    asm("mov $0x082ac3a0, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::ConnectionIdToSlidingWindow(unsigned long, unsigned long *)
{
    asm("leave");
    asm("mov $0x082ab95c, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::DisconnectFromSession()
{
    asm("leave");
    asm("mov $0x082ac418, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::DisconnectPlayer(unsigned long, unsigned long, int, int)
{
    asm("leave");
    asm("mov $0x082a9f68, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::DropConnectionToServer()
{
    asm("leave");
    asm("mov $0x082ac468, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::EndConnectToSession()
{
    asm("leave");
    asm("mov $0x082ac300, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::EndEnumerateSessions()
{
    asm("leave");
    asm("mov $0x082abf74, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::EndInternetAddressTranslation()
{
    asm("leave");
    asm("mov $0x082ac678, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::EndPing(unsigned long)
{
    asm("leave");
    asm("mov $0x082a968c, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::EndProtocol(unsigned long)
{
    asm("leave");
    asm("mov $0x082abb1c, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::EndServerMode()
{
    asm("leave");
    asm("mov $0x082abf04, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::EnumerateSessionsList(unsigned char)
{
    asm("leave");
    asm("mov $0x082a7780, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::EnumerateSessionsLoop()
{
    asm("leave");
    asm("mov $0x082a75f4, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::FindPlayerName(CExoString, unsigned long)
{
    asm("leave");
    asm("mov $0x082aa80c, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::GetConnectionError()
{
    asm("leave");
    asm("mov $0x082ac360, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::GetExoApp()
{
    asm("leave");
    asm("mov $0x082ab800, %eax");
    asm("jmp *%eax");
}

CExoString CNetLayerInternal::GetGameMasterPassword()
{
    asm("leave");
    asm("mov $0x082abd6c, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::GetIPBySessionId(unsigned long, CExoString *)
{
    asm("leave");
    asm("mov $0x082aca5c, %eax");
    asm("jmp *%eax");
}

unsigned long CNetLayerInternal::GetInternetAddressTranslationStatus(unsigned char *)
{
    asm("leave");
    asm("mov $0x082ac5bc, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::GetLocalAdapterString(unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x082abb60, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::GetLocalPrivileges(unsigned long)
{
    asm("leave");
    asm("mov $0x082abf2c, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::GetMessageFromStandardConnection(int *, char **, int *)
{
    asm("leave");
    asm("mov $0x082aca14, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::GetNumberLocalAdapters(unsigned long)
{
    asm("leave");
    asm("mov $0x082abb48, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::GetPasswordRequired()
{
    asm("leave");
    asm("mov $0x082abc78, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::GetPlayerAddressData(unsigned long, unsigned long *, unsigned char **, unsigned char **, unsigned long *)
{
    asm("leave");
    asm("mov $0x082ac0cc, %eax");
    asm("jmp *%eax");
}

CExoString CNetLayerInternal::GetPlayerAddress(unsigned long)
{
    asm("leave");
    asm("mov $0x082ac4d4, %eax");
    asm("jmp *%eax");
}

CExoString CNetLayerInternal::GetPlayerPassword()
{
    asm("leave");
    asm("mov $0x082abca0, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::GetPortBySessionId(unsigned long)
{
    asm("leave");
    asm("mov $0x082a98e8, %eax");
    asm("jmp *%eax");
}

unsigned long CNetLayerInternal::GetSendUDPSocket()
{
    asm("leave");
    asm("mov $0x082ac798, %eax");
    asm("jmp *%eax");
}

CExoString CNetLayerInternal::GetServerAdminPassword()
{
    asm("leave");
    asm("mov $0x082abe38, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::GetServerConnected()
{
    asm("leave");
    asm("mov $0x082ac6d0, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::GetServerNetworkAddress()
{
    asm("leave");
    asm("mov $0x082aa620, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::GetServerPlayerCount()
{
    asm("leave");
    asm("mov $0x082ac704, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::GetSessionInfo(unsigned long)
{
    asm("leave");
    asm("mov $0x082ac2cc, %eax");
    asm("jmp *%eax");
}

unsigned long CNetLayerInternal::GetSessionMaxPlayers()
{
    asm("leave");
    asm("mov $0x082ac204, %eax");
    asm("jmp *%eax");
}

CExoString CNetLayerInternal::GetSessionName()
{
    asm("leave");
    asm("mov $0x082ac230, %eax");
    asm("jmp *%eax");
}

unsigned long CNetLayerInternal::GetUDPRecievePort()
{
    asm("leave");
    asm("mov $0x082ac2b0, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::GetWindowSendIdByReceiveId(unsigned long, unsigned long *)
{
    asm("leave");
    asm("mov $0x082ac738, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::HandleBNCRMessage(unsigned long, unsigned char *, unsigned long)
{
    asm("leave");
    asm("mov $0x082a36f4, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::HandleBNCSMessage(unsigned long, unsigned char *, unsigned long)
{
    asm("leave");
    asm("mov $0x082a1e38, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::HandleBNDMMessage(unsigned long, unsigned char *, unsigned long)
{
    asm("leave");
    asm("mov $0x082aba30, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::HandleBNDPMessage(unsigned long, unsigned char *, unsigned long)
{
    asm("leave");
    asm("mov $0x082a6fa0, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::HandleBNDRMessage(unsigned long, unsigned char *, unsigned long)
{
    asm("leave");
    asm("mov $0x082a8a70, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::HandleBNDSMessage(unsigned long, unsigned char *, unsigned long)
{
    asm("leave");
    asm("mov $0x082a85b4, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::HandleBNERMessage(unsigned long, unsigned char *, unsigned long)
{
    asm("leave");
    asm("mov $0x082a696c, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::HandleBNESMessage(unsigned long, unsigned char *, unsigned long)
{
    asm("leave");
    asm("mov $0x082a18f4, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::HandleBNLMMessage(unsigned long, unsigned char *, unsigned long)
{
    asm("leave");
    asm("mov $0x082a936c, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::HandleBNLRMessage(unsigned long, unsigned char *, unsigned long)
{
    asm("leave");
    asm("mov $0x082a94c4, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::HandleBNVRMessage(unsigned long, unsigned char *, unsigned long)
{
    asm("leave");
    asm("mov $0x082a67dc, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::HandleBNVSMessage(unsigned long, unsigned char *, unsigned long)
{
    asm("leave");
    asm("mov $0x082a4a54, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::HandleBNXIMessage(unsigned long, unsigned char *, unsigned long)
{
    asm("leave");
    asm("mov $0x082a7b38, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::HandleBNXRMessage(unsigned long, unsigned char *, unsigned long)
{
    asm("leave");
    asm("mov $0x082a7f44, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::Initialize(CBaseExoApp *)
{
    asm("leave");
    asm("mov $0x082a0258, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::IsConnectedToLocalhost()
{
    asm("leave");
    asm("mov $0x082a9c48, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::IsPlayerIpSameAsConnection(unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x082aa920, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::MessageArrived(unsigned long, unsigned long, unsigned long, int)
{
    asm("leave");
    asm("mov $0x082ab8d0, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::NonWindowMessages(unsigned long, unsigned char *, unsigned long)
{
    asm("leave");
    asm("mov $0x082a7098, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::OpenStandardConnection(int, CExoString, int)
{
    asm("leave");
    asm("mov $0x082ac9a4, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::PacketizeSendMessageToPlayer(unsigned long, unsigned char *, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x082a0d94, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::PacketizeSmallMessageToPlayer(unsigned long, unsigned char *, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x082a1338, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::PlacePacketInSendQueues(unsigned long, int, unsigned char *, unsigned long, int)
{
    asm("leave");
    asm("mov $0x082a112c, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::PlayerIdToConnectionId(unsigned long, unsigned long *)
{
    asm("leave");
    asm("mov $0x082ab9e4, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::PlayerIdToSlidingWindow(unsigned long, unsigned long *)
{
    asm("leave");
    asm("mov $0x082ab9a0, %eax");
    asm("jmp *%eax");
}

void CNetLayerInternal::ProcessReceivedFrames(int)
{
    asm("leave");
    asm("mov $0x082a0640, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::PurgeConnections()
{
    asm("leave");
    asm("mov $0x082a1700, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::RequestExtendedServerInfo(unsigned long, int, int)
{
    asm("leave");
    asm("mov $0x082a9020, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::SendBNCRMessage(unsigned long, unsigned char, unsigned long)
{
    asm("leave");
    asm("mov $0x082a3208, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::SendBNCSMessage(unsigned long, unsigned char, int, int, CExoString const &, CExoString const &, unsigned long &)
{
    asm("leave");
    asm("mov $0x082a1bd8, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::SendBNDMMessage()
{
    asm("leave");
    asm("mov $0x082ac540, %eax");
    asm("jmp *%eax");
}

void CNetLayerInternal::SendBNDPMessage(unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x082aa1f4, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::SendBNDSMessage(unsigned long)
{
    asm("leave");
    asm("mov $0x082a981c, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::SendBNLMMessage(unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x082a925c, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::SendBNVRMessage(unsigned long, unsigned char)
{
    asm("leave");
    asm("mov $0x082a673c, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::SendBNVSMessage(CExoArrayList<CExoString> const *, CExoString const &, CExoString const &)
{
    asm("leave");
    asm("mov $0x082a4818, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::SendDirectMessage(unsigned long, unsigned char *, unsigned long, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x082ac924, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::SendMessageToAddress(unsigned long, unsigned char *, unsigned long)
{
    asm("leave");
    asm("mov $0x082ab8f4, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::SendMessageToPlayer(unsigned long, unsigned char *, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x082a0b04, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::SendMessageToStandardConnection(int, char *, int)
{
    asm("leave");
    asm("mov $0x082aca2c, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::SetGameMasterPassword(CExoString)
{
    asm("leave");
    asm("mov $0x082abdac, %eax");
    asm("jmp *%eax");
}

void CNetLayerInternal::SetMasterServerInternetAddress(unsigned char const *, unsigned long)
{
    asm("leave");
    asm("mov $0x082ac780, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::SetNetworkAddressData(unsigned long, unsigned char *, unsigned char *, unsigned long)
{
    asm("leave");
    asm("mov $0x082ac178, %eax");
    asm("jmp *%eax");
}

void CNetLayerInternal::SetPlayerConnected(unsigned long)
{
    asm("leave");
    asm("mov $0x082a9d88, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::SetPlayerPassword(CExoString)
{
    asm("leave");
    asm("mov $0x082abce0, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::SetServerAdminPassword(CExoString)
{
    asm("leave");
    asm("mov $0x082abe78, %eax");
    asm("jmp *%eax");
}

void CNetLayerInternal::SetServerLanguage(int)
{
    asm("leave");
    asm("mov $0x082abb34, %eax");
    asm("jmp *%eax");
}

void CNetLayerInternal::SetSessionMaxPlayers(unsigned long)
{
    asm("leave");
    asm("mov $0x082ac214, %eax");
    asm("jmp *%eax");
}

void CNetLayerInternal::SetSessionName(CExoString)
{
    asm("leave");
    asm("mov $0x082ac258, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::SetSlidingWindow(unsigned long, unsigned long, unsigned long *)
{
    asm("leave");
    asm("mov $0x082a177c, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::SetUpPlayBackConnection()
{
    asm("leave");
    asm("mov $0x082ab80c, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::ShutDownClientInterfaceWithReason(unsigned long)
{
    asm("leave");
    asm("mov $0x082ac7b0, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::ShutDown()
{
    asm("leave");
    asm("mov $0x082ab82c, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::StartConnectToSession(unsigned long, CExoString const &, int, int, CExoString const &, unsigned long, unsigned long, CExoString const &)
{
    asm("leave");
    asm("mov $0x082a99e0, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::StartEnumerateSessions(unsigned long, int, unsigned char *, unsigned short, int, unsigned short, CExoString *, unsigned short, CExoString *, unsigned short, CExoString *)
{
    asm("leave");
    asm("mov $0x082a7314, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::StartInternetAddressTranslation(CExoString, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x082aa27c, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::StartPing(unsigned long)
{
    asm("leave");
    asm("mov $0x082a912c, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::StartProtocol(unsigned long, unsigned long, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x082abaac, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::StartServerMode(CExoString, unsigned long)
{
    asm("leave");
    asm("mov $0x082abb88, %eax");
    asm("jmp *%eax");
}

void CNetLayerInternal::StoreMessage(unsigned char *, unsigned long)
{
    asm("leave");
    asm("mov $0x082ac1e4, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::UncompressMessage(unsigned long, unsigned char *, unsigned long)
{
    asm("leave");
    asm("mov $0x082a0844, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::UpdateStatusLoop(unsigned long)
{
    asm("leave");
    asm("mov $0x082aa398, %eax");
    asm("jmp *%eax");
}

int CNetLayerInternal::ValidatePlayerAgainstLastSuccessfulLogin(CExoString, CExoString)
{
    asm("leave");
    asm("mov $0x082aaf0c, %eax");
    asm("jmp *%eax");
}

