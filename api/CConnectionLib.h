#ifndef _CCONNECTIONLIB_H_
#define _CCONNECTIONLIB_H_
#include "nwndef.h"
#include "CExoString.h"
#include "CExoArrayList.h"

class CConnectionLib
{
public:
    int AddServer(void *, char *, char *, int, int, int, int, char *, int, int, char *, int, int, int, char *, char *, int, int, int, int, int, bool);
    int ChatNameMangle(CExoString &);
    int ClearServers();
    int ClientConnectToGameSpy(CExoString const &);
    int ErrorClientShuttingDown(unsigned char);
    int GSClientGetBuildFilter();
    int GSClientGetGroupRoomNumber();
    int GSClientGroupRoomAdded(int, unsigned long);
    int GSClientJoinGroupRoom(int);
    int GSClientMessage(int, CExoString const &, CExoString const &);
    int GSClientRoomPlayerChange(int, CExoString const &, CExoString const &);
    int GSClientSetBuildFilter(CExoString const &);
    CExoString GenerateCommunityNameResponse(CExoString const &, CExoString const &);
    int GenerateResponse(CExoString const &, CExoString const &, CExoString &, CExoString &);
    int GetAvailabilityStatus();
    int GetAvailability();
    int GetClientConnectionPhase();
    int GetClientError();
    int GetCommunityNameStatus(CExoString const &, unsigned char **);
    int GetDigiDistModuleCipher(CExoString &, int);
    int GetGSClientGameRegion();
    int GetGameFilters(CExoString *);
    int GetGameTypeFromGroupId(int);
    int GetGroupIdFromGameType(int);
    CExoString GetKeyAuthDemand(CExoString &);
    CExoString GetKeyCollision();
    unsigned long GetKeyRejectionReason(unsigned short);
    unsigned short GetKeyStatus(CExoString const &, unsigned short &);
    CExoString GetMasterServerInternetName();
    unsigned long GetMasterServerPort();
    unsigned short GetMasterServerStatus();
    int GetMessageOfTheDay();
    unsigned long GetMessagesIn();
    int GetNetConnectionUp();
    CNetLayer * GetNetLayer();
    int GetNextBuddyEntry();
    CExoString GetPublicPartFromCDKey(CExoString const &);
    unsigned long GetStrrefFromGameType(int);
    int GetStrrefFromGroupId(int);
    int GetVersionNumber();
    int GetVersion();
    void HandleGameSpyToServerMessage(int, void *, int);
    int HandleMasterServerToGameMessage(unsigned char *, unsigned long);
    int HandleServerGameSpyMessage(unsigned long, unsigned char *, unsigned long);
    void InitializeGameSpyRooms();
    int NewClientChallenge(unsigned long);
    int RemoveServer(void *);
    void ResetMessagesInFlag(unsigned long);
    int SendAddBuddyRequest(CExoString const &, CExoString const &);
    int SendClientToMasterCreateAccountPartOne(CExoString const &);
    int SendClientToMasterCreateAccountPartTwo(CExoString const &, CExoString const &, CExoString const &, unsigned char *, CExoString const &);
    int SendClientToMasterMOTDRequest(unsigned short);
    int SendClientToMasterVersionRequest(unsigned short);
    int SendDigiDistAuthRequest(CExoArrayList<CExoString> *, CExoString const &);
    int SendGameToMasterAuthorizationRequest(void *, int);
    int SendGameToMasterAuthorizationRequest(unsigned long, int);
    int SendGameToMasterCommunityNameAuth(CExoString const &, CExoString const &, CExoString const &, unsigned short, unsigned char);
    int SendGameToMasterDisconnect(void *, int);
    int SendGameToMasterDisconnect(unsigned long);
    int SendGameToMasterHeartbeat(void *, int);
    int SendGameToMasterModule(unsigned char, CExoString const &);
    int SendGameToMasterShutDown();
    int SendGameToMasterStartup(unsigned char, unsigned long, int, unsigned char, unsigned char);
    int SendGameToMasterStatusRequest();
    int SendGetAvailabilityRequest(CExoString const &);
    int SendGetBuddyListRequest(CExoString const &);
    int SendMessageToNick(char const *, char const *);
    int SendMessageToRoom(char const *);
    int SendRemoveBuddyRequest(CExoString const &, CExoString const &);
    int SendSetAvailabilityRequest(CExoString const &, unsigned short);
    int ServerConnectToGameSpy(unsigned int);
    int SetGSClientGameRegion(int);
    int SetGameFilters(unsigned long, CExoString *);
    void SetLanguage(int);
    void SetNetConnectionUp(int);
    int ShutDownClientGameSpyConnection();
    void ShutDownServerGameSpyConnection();
    int StartMstHeartbeatTimer(unsigned long long);
    int StartSystemUpdateTimer(unsigned long long);
    int StartTimeOutTimer(unsigned long long);
    int TimeOutTimerRunning();
    int UpdateConnectionPhase(unsigned char, CExoString const &);
    int UpdateGameSpyClient();
    void UpdateGameSpyServer();
    int UpdateMstHeartbeatTimer(unsigned long long);
    int UpdateServer(void *, char *, char *, int, int, int, int, char *, int, int, char *, int, int, int, char *, char *, int, int, int, int, int, bool);
    int UpdateSystemUpdateTimer(unsigned long long);
    int UpdateTimeOutTimer(unsigned long long);
    int ValidateCdKey(char *);
    ~CConnectionLib();
    CConnectionLib(CBaseExoApp *);

    /* 0x0/0 */ unsigned long field_0;
};
#endif
