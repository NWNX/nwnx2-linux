#ifndef _CMSTNETLAYER_H_
#define _CMSTNETLAYER_H_
#include "nwndef.h"
#include "CExoArrayList.h"

class CMstNetLayer
{
public:
	int GenerateCommunityNameResponse(CExoString const &, CExoString const &);
	int GetCommunityNameStatus(CExoString const &, unsigned char **);
	int GetDigiDistInfo(CExoString &);
	int GetDigiDistModuleCipher(CExoString &, int);
	int GetKeyAuthDemand(CExoString &);
	int GetKeyCollision();
	int GetKeyRejectionReason(unsigned short);
	int GetKeyStatus(CExoString const &, unsigned short &);
	int GetMasterServerInternetName();
	int GetMasterServerPort();
	int GetNextBuddyEntry();
	int HandleAddBuddyResponse(unsigned char *, unsigned long);
	int HandleAuthorizationResponse(unsigned char *, unsigned long);
	int HandleCommunityNameAuthResponse(unsigned char *, unsigned long);
	int HandleCreateAccountPartOne(unsigned char *, unsigned long);
	int HandleCreateAccountPartTwo(unsigned char *, unsigned long);
	int HandleDemandAuthorization(unsigned char *, unsigned long);
	int HandleDemandHeartbeat(unsigned char *, unsigned long);
	int HandleDigiDistAuthResponse(unsigned char *, unsigned long);
	int HandleGetAvailabilityResponse(unsigned char *, unsigned long);
	int HandleGetBuddyListResponse(unsigned char *, unsigned long);
	int HandleMOTDResponse(unsigned char *, unsigned long);
	int HandleMasterServerToGameMessage(unsigned char *, unsigned long);
	int HandleNotifyCollision(unsigned char *, unsigned long);
	int HandleRemoveBuddyResponse(unsigned char *, unsigned long);
	int HandleSetAvailabilityResponse(unsigned char *, unsigned long);
	int HandleStatusResponse(unsigned char *, unsigned long);
	int HandleVersionResponse(unsigned char *, unsigned long);
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
	int SetLanguage(int);
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
