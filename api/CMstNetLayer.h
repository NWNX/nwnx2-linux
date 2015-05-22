#ifndef _CMSTNETLAYER_H_
#define _CMSTNETLAYER_H_
#include "nwndef.h"
#include "CExoString.h"
#include "CExoArrayList.h"

class CMstNetLayer
{
public:
    CExoString GenerateCommunityNameResponse(CExoString const &, CExoString const &);
    int GetCommunityNameStatus(CExoString const &, unsigned char **);
    SMstDigiDistInfo * GetDigiDistInfo(CExoString &);
    int GetDigiDistModuleCipher(CExoString &, int);
    CExoString GetKeyAuthDemand(CExoString &);
    CExoString GetKeyCollision();
    unsigned long GetKeyRejectionReason(unsigned short);
    unsigned short GetKeyStatus(CExoString const &, unsigned short &);
    CExoString GetMasterServerInternetName();
    unsigned long GetMasterServerPort();
    int GetNextBuddyEntry();
    void HandleAddBuddyResponse(unsigned char *, unsigned long);
    void HandleAuthorizationResponse(unsigned char *, unsigned long);
    void HandleCommunityNameAuthResponse(unsigned char *, unsigned long);
    void HandleCreateAccountPartOne(unsigned char *, unsigned long);
    void HandleCreateAccountPartTwo(unsigned char *, unsigned long);
    void HandleDemandAuthorization(unsigned char *, unsigned long);
    void HandleDemandHeartbeat(unsigned char *, unsigned long);
    void HandleDigiDistAuthResponse(unsigned char *, unsigned long);
    void HandleGetAvailabilityResponse(unsigned char *, unsigned long);
    void HandleGetBuddyListResponse(unsigned char *, unsigned long);
    void HandleMOTDResponse(unsigned char *, unsigned long);
    int HandleMasterServerToGameMessage(unsigned char *, unsigned long);
    void HandleNotifyCollision(unsigned char *, unsigned long);
    void HandleRemoveBuddyResponse(unsigned char *, unsigned long);
    void HandleSetAvailabilityResponse(unsigned char *, unsigned long);
    void HandleStatusResponse(unsigned char *, unsigned long);
    void HandleVersionResponse(unsigned char *, unsigned long);
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
    int SendRemoveBuddyRequest(CExoString const &, CExoString const &);
    int SendSetAvailabilityRequest(CExoString const &, unsigned short);
    void SetLanguage(int);
    int StartHeartbeatTimer(unsigned long long);
    int StartSystemUpdateTimer(unsigned long long);
    int StartTimeOutTimer(unsigned long long);
    int UpdateHeartbeatTimer(unsigned long long);
    int UpdateSystemUpdateTimer(unsigned long long);
    int UpdateTimeOutTimer(unsigned long long);
    ~CMstNetLayer();
    CMstNetLayer(CConnectionLib *);

};
#endif
