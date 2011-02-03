#ifndef _CNETLAYER_H_
#define _CNETLAYER_H_
#include "nwndef.h"
#include "CExoString.h"
#include "CNetLayerInternal.h"

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
	int GetExpansionPackReqd();
	int GetGameMasterPassword();
	int GetGameMasterPermision() const;
	int GetIPBySessionId(unsigned long, CExoString *);
	int GetInternetAddressTranslationStatus(unsigned char *);
	int GetLocalAdapterString(unsigned long, unsigned long);
	int GetLocalPrivileges(unsigned long);
	int GetMessageFromStandardConnection(int *, char **, int *);
	int GetNumberLocalAdapters(unsigned long);
	int GetPasswordRequired();
	int GetPlayerAddressData(unsigned long, unsigned long *, unsigned char **, unsigned char **, unsigned long *);
	int GetPlayerAddress(unsigned long);
	int GetPlayerInfo(unsigned long);
	int GetPlayerPassword();
	int GetPortBySessionId(unsigned long);
	int GetSendUDPSocket();
	int GetServerAdminPassword();
	int GetServerConnected();
	int GetServerNetworkAddress();
	int GetSessionInfoChanged(unsigned long);
	int GetSessionInfo(unsigned long);
	int GetSessionMaxPlayers();
	int GetSessionName();
	int GetUDPRecievePort();
	int Initialize(CBaseExoApp *);
	int IsConnectedToLocalhost();
	int MessageArrived(unsigned long, unsigned long, unsigned long, int);
	int OpenStandardConnection(int, CExoString, int);
	int PlayerIdToConnectionId(unsigned long, unsigned long *);
	int ProcessReceivedFrames(int);
	int RequestExtendedServerInfo(unsigned long, int, int);
	int RequestServerDetails(unsigned long);
	int SendMessageToAddress(unsigned long, unsigned char *, unsigned long);
	int SendMessageToPlayer(unsigned long, unsigned char *, unsigned long, unsigned long);
	int SendMessageToStandardConnection(int, char *, int);
	int SetConnectionsDisallowed(int);
	int SetConnectionsMustBeValidated(int);
	int SetDisconnectStrref(unsigned long);
	int SetExpansionPackReqd(unsigned short);
	int SetGameMasterPassword(CExoString);
	int SetMasterServerInternetAddress(unsigned char const *, unsigned long);
	int SetMstServerPassword(CExoString);
	int SetPlayerPassword(CExoString);
	int SetServerAdminPassword(CExoString);
	int SetServerLanguage(int);
	int SetSessionInfoChanged(unsigned long, int);
	int SetSessionMaxPlayers(unsigned long);
	int SetSessionName(CExoString);
	int SetUpPlayBackConnection();
	int ShutDownClientInterfaceWithReason(unsigned long);
	int ShutDown();
	int StartConnectToSession(unsigned long, CExoString const &, int, int, CExoString const &, unsigned long, unsigned long, CExoString const &);
	int StartEnumerateSessions(unsigned long, int, unsigned char *, unsigned short, int, unsigned short, CExoString *, unsigned short, CExoString *, unsigned short, CExoString *);
	int StartInternetAddressTranslation(CExoString, unsigned long, unsigned long);
	int StartPing(unsigned long);
	int StartProtocol(unsigned long, unsigned long, unsigned long, unsigned long);
	int StartServerMode(CExoString, unsigned long);
	int StoreMessage(unsigned char *, unsigned long);
	int TranslateAddressFromString(char *, unsigned long *, unsigned char *, unsigned char *, unsigned long *);
	int UpdateStatusLoop(unsigned long);
	~CNetLayer();
	CNetLayer();

	/* 0x0/0 */ CNetLayerInternal *Internal;
};
#endif
