#ifndef _CNETLAYERINTERNAL_H_
#define _CNETLAYERINTERNAL_H_
#include "nwndef.h"
#include "CExoString.h"
#include "CExoArrayList.h"
#include "CNetLayerWindow.h"
#include "CNetLayerPlayerInfo.h"
#include "CExoLinkedList.h"

class CNetLayerInternal
{
public:
    int BroadcastMessageToAddress(unsigned long, unsigned long, unsigned char *, unsigned long);
    int CRCBlock(unsigned char *, unsigned long);
    int CRCBuildTable();
    int CRCEncodeFrame(unsigned char *, unsigned long);
    int CRCVerifyFrame(unsigned char *, unsigned long);
    void CheckMasterServerTimeouts();
    int CleanUpEnumerateSpecific();
    int ClearSessionInfoChanged(unsigned long);
    int CloseStandardConnection(int);
    int ConnectToSessionLoop();
    int ConnectionIdToSlidingWindow(unsigned long, unsigned long *);
    int DisconnectFromSession();
    int DisconnectPlayer(unsigned long, unsigned long, int, int);
    int DropConnectionToServer();
    int EndConnectToSession();
    int EndEnumerateSessions();
    int EndInternetAddressTranslation();
    int EndPing(unsigned long);
    int EndProtocol(unsigned long);
    int EndServerMode();
    int EnumerateSessionsList(unsigned char);
    int EnumerateSessionsLoop();
    int FindPlayerName(CExoString, unsigned long);
    int GetConnectionError();
    int GetExoApp();
    CExoString GetGameMasterPassword();
    int GetIPBySessionId(unsigned long, CExoString *);
    unsigned long GetInternetAddressTranslationStatus(unsigned char *);
    int GetLocalAdapterString(unsigned long, unsigned long);
    int GetLocalPrivileges(unsigned long);
    int GetMessageFromStandardConnection(int *, char **, int *);
    int GetNumberLocalAdapters(unsigned long);
    int GetPasswordRequired();
    int GetPlayerAddressData(unsigned long, unsigned long *, unsigned char **, unsigned char **, unsigned long *);
    CExoString GetPlayerAddress(unsigned long);
    CExoString GetPlayerPassword();
    int GetPortBySessionId(unsigned long);
    unsigned long GetSendUDPSocket();
    CExoString GetServerAdminPassword();
    int GetServerConnected();
    int GetServerNetworkAddress();
    int GetServerPlayerCount();
    int GetSessionInfo(unsigned long);
    unsigned long GetSessionMaxPlayers();
    CExoString GetSessionName();
    unsigned long GetUDPRecievePort();
    int GetWindowSendIdByReceiveId(unsigned long, unsigned long *);
    int HandleBNCRMessage(unsigned long, unsigned char *, unsigned long);
    int HandleBNCSMessage(unsigned long, unsigned char *, unsigned long);
    int HandleBNDMMessage(unsigned long, unsigned char *, unsigned long);
    int HandleBNDPMessage(unsigned long, unsigned char *, unsigned long);
    int HandleBNDRMessage(unsigned long, unsigned char *, unsigned long);
    int HandleBNDSMessage(unsigned long, unsigned char *, unsigned long);
    int HandleBNERMessage(unsigned long, unsigned char *, unsigned long);
    int HandleBNESMessage(unsigned long, unsigned char *, unsigned long);
    int HandleBNLMMessage(unsigned long, unsigned char *, unsigned long);
    int HandleBNLRMessage(unsigned long, unsigned char *, unsigned long);
    int HandleBNVRMessage(unsigned long, unsigned char *, unsigned long);
    int HandleBNVSMessage(unsigned long, unsigned char *, unsigned long);
    int HandleBNXIMessage(unsigned long, unsigned char *, unsigned long);
    int HandleBNXRMessage(unsigned long, unsigned char *, unsigned long);
    int Initialize(CBaseExoApp *);
    int IsConnectedToLocalhost();
    int IsPlayerIpSameAsConnection(unsigned long, unsigned long);
    int MessageArrived(unsigned long, unsigned long, unsigned long, int);
    int NonWindowMessages(unsigned long, unsigned char *, unsigned long);
    int OpenStandardConnection(int, CExoString, int);
    int PacketizeSendMessageToPlayer(unsigned long, unsigned char *, unsigned long, unsigned long);
    int PacketizeSmallMessageToPlayer(unsigned long, unsigned char *, unsigned long, unsigned long);
    int PlacePacketInSendQueues(unsigned long, int, unsigned char *, unsigned long, int);
    int PlayerIdToConnectionId(unsigned long, unsigned long *);
    int PlayerIdToSlidingWindow(unsigned long, unsigned long *);
    void ProcessReceivedFrames(int);
    int PurgeConnections();
    int RequestExtendedServerInfo(unsigned long, int, int);
    int SendBNCRMessage(unsigned long, unsigned char, unsigned long);
    int SendBNCSMessage(unsigned long, unsigned char, int, int, CExoString const &, CExoString const &, unsigned long &);
    int SendBNDMMessage();
    void SendBNDPMessage(unsigned long, unsigned long);
    int SendBNDSMessage(unsigned long);
    int SendBNLMMessage(unsigned long, unsigned long);
    int SendBNVRMessage(unsigned long, unsigned char);
    int SendBNVSMessage(CExoArrayList<CExoString> const *, CExoString const &, CExoString const &);
    int SendDirectMessage(unsigned long, unsigned char *, unsigned long, unsigned long, unsigned long);
    int SendMessageToAddress(unsigned long, unsigned char *, unsigned long);
    int SendMessageToPlayer(unsigned long, unsigned char *, unsigned long, unsigned long);
    int SendMessageToStandardConnection(int, char *, int);
    int SetGameMasterPassword(CExoString);
    void SetMasterServerInternetAddress(unsigned char const *, unsigned long);
    int SetNetworkAddressData(unsigned long, unsigned char *, unsigned char *, unsigned long);
    void SetPlayerConnected(unsigned long);
    int SetPlayerPassword(CExoString);
    int SetServerAdminPassword(CExoString);
    void SetServerLanguage(int);
    void SetSessionMaxPlayers(unsigned long);
    void SetSessionName(CExoString);
    int SetSlidingWindow(unsigned long, unsigned long, unsigned long *);
    int SetUpPlayBackConnection();
    int ShutDownClientInterfaceWithReason(unsigned long);
    int ShutDown();
    int StartConnectToSession(unsigned long, CExoString const &, int, int, CExoString const &, unsigned long, unsigned long, CExoString const &);
    int StartEnumerateSessions(unsigned long, int, unsigned char *, unsigned short, int, unsigned short, CExoString *, unsigned short, CExoString *, unsigned short, CExoString *);
    int StartInternetAddressTranslation(CExoString, unsigned long, unsigned long);
    int StartPing(unsigned long);
    int StartProtocol(unsigned long, unsigned long, unsigned long, unsigned long);
    int StartServerMode(CExoString, unsigned long);
    void StoreMessage(unsigned char *, unsigned long);
    int UncompressMessage(unsigned long, unsigned char *, unsigned long);
    int UpdateStatusLoop(unsigned long);
    int ValidatePlayerAgainstLastSuccessfulLogin(CExoString, CExoString);
    ~CNetLayerInternal();
    CNetLayerInternal();

    /* 0x0/0 */ CServerExoApp *ServerExoApp;
    /* 0x4/4 */ unsigned long field_4;
    /* 0x8/8 */ unsigned long field_8;
    /* 0xC/12 */ CNetLayerWindow NetWindows[96];
    /* 0x36A8C/223884 */ CNetLayerPlayerInfo PlayerInfos[96];
    /* 0x39790/235408 */ char rsvd1[4];
    /* 0x39790/235408 */ char field_39790[131072];
    /* 0x59790/366480 */ char field_59790[131072];
    /* 0x79790/497552 */ unsigned long CRCTable[256];
    /* 0x79F54/499540 */ char rsvd2[964];
    /* 0x79F54/499540 */ CExoString field_79F54;
    /* 0x79F5C/499548 */ CExoString field_79F5C;
    /* 0x79F64/499556 */ CExoString field_79F64;
    /* 0x79F6C/499564 */ CExoString field_79F6C;
    /* 0x79F74/499572 */ unsigned long MaxPlayers;
    /* 0x79F90/499600 */ char rsvd3[24];
    /* 0x79F90/499600 */ unsigned long field_79F90;
    /* 0x79FA4/499620 */ char rsvd4[16];
    /* 0x79FA4/499620 */ unsigned long field_79FA4;
    /* 0x79FC4/499652 */ char rsvd5[28];
    /* 0x79FC4/499652 */ CExoString field_79FC4;
    /* 0x7A008/499720 */ char rsvd6[60];
    /* (mtype:CExoLinkedList<unsigned long>) */
    /* 0x7A008/499720 */ CExoLinkedList<unsigned long> field_7A008;
    /* 0x7A02C/499756 */ char rsvd7[32];
    /* 0x7A02C/499756 */ CExoString field_7A02C;
    /* 0x7A034/499764 */ unsigned long field_7A034;
    /* 0x7A038/499768 */ unsigned long field_7A038;
    /* 0x7A03C/499772 */ unsigned long field_7A03C;
    /* 0x7A04C/499788 */ char rsvd8[12];
    /* 0x7A04C/499788 */ unsigned long field_7A04C;
};
#endif
