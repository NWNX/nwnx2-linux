#ifndef _CNETLAYER_H_
#define _CNETLAYER_H_
#include "nwndef.h"
#include "CExoString.h"

class CNetLayer
{
public:
    int CleanUpEnumerateSpecific();
    int ClearSessionInfoChanged(unsigned long);
    int CloseStandardConnection(int);
    int DisconnectFromSession();
    int DisconnectPlayer(unsigned long, unsigned long, int);
    int DropConnectionToServer();
    int EndConnectToSession();
    int EndEnumerateSessions();
    int EndInternetAddressTranslation();
    int EndPing(unsigned long);
    int EndProtocol(unsigned long);
    int EndServerMode();
    int EnumerateSessionsList(unsigned char);
    int GetAnySessionsEnumerated();
    int GetAnyWindowBehind();
    int GetClientConnected();
    int GetConnectionError();
    int GetConnectionsMustBeValidated();
    int GetDisconnectStrref();
    int GetExoApp();
    int GetExoNet();
    unsigned short GetExpansionPackReqd();
    CExoString GetGameMasterPassword();
    int GetGameMasterPermision() const;
    int GetIPBySessionId(unsigned long, CExoString *);
    unsigned long GetInternetAddressTranslationStatus(unsigned char *);
    int GetLocalAdapterString(unsigned long, unsigned long);
    int GetLocalPrivileges(unsigned long);
    int GetMessageFromStandardConnection(int *, char **, int *);
    int GetNumberLocalAdapters(unsigned long);
    int GetPasswordRequired();
    int GetPlayerAddressData(unsigned long, unsigned long *, unsigned char **, unsigned char **, unsigned long *);
    CExoString GetPlayerAddress(unsigned long);
    CNetLayerPlayerInfo * GetPlayerInfo(unsigned long);
    CExoString GetPlayerPassword();
    int GetPortBySessionId(unsigned long);
    unsigned long GetSendUDPSocket();
    CExoString GetServerAdminPassword();
    int GetServerConnected();
    int GetServerNetworkAddress();
    int GetSessionInfoChanged(unsigned long);
    int GetSessionInfo(unsigned long);
    unsigned long GetSessionMaxPlayers();
    CExoString GetSessionName();
    unsigned long GetUDPRecievePort();
    int Initialize(CBaseExoApp *);
    int IsConnectedToLocalhost();
    int MessageArrived(unsigned long, unsigned long, unsigned long, int);
    int OpenStandardConnection(int, CExoString, int);
    int PlayerIdToConnectionId(unsigned long, unsigned long *);
    void ProcessReceivedFrames(int);
    int RequestExtendedServerInfo(unsigned long, int, int);
    int RequestServerDetails(unsigned long);
    int SendMessageToAddress(unsigned long, unsigned char *, unsigned long);
    int SendMessageToPlayer(unsigned long, unsigned char *, unsigned long, unsigned long);
    int SendMessageToStandardConnection(int, char *, int);
    void SetConnectionsDisallowed(int);
    void SetConnectionsMustBeValidated(int);
    int SetDisconnectStrref(unsigned long);
    void SetExpansionPackReqd(unsigned short);
    int SetGameMasterPassword(CExoString);
    void SetMasterServerInternetAddress(unsigned char const *, unsigned long);
    int SetMstServerPassword(CExoString);
    int SetPlayerPassword(CExoString);
    int SetServerAdminPassword(CExoString);
    void SetServerLanguage(int);
    int SetSessionInfoChanged(unsigned long, int);
    void SetSessionMaxPlayers(unsigned long);
    void SetSessionName(CExoString);
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
    int TranslateAddressFromString(char *, unsigned long *, unsigned char *, unsigned char *, unsigned long *);
    int UpdateStatusLoop(unsigned long);
    ~CNetLayer();
    CNetLayer();

    /* 0x0/0 */ CNetLayerInternal *Internal;
};
#endif
