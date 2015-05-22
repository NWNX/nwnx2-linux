#include "CMstNetLayer.h"

CExoString CMstNetLayer::GenerateCommunityNameResponse(CExoString const &, CExoString const &)
{
    asm("leave");
    asm("mov $0x082943d8, %eax");
    asm("jmp *%eax");
}

int CMstNetLayer::GetCommunityNameStatus(CExoString const &, unsigned char **)
{
    asm("leave");
    asm("mov $0x082987fc, %eax");
    asm("jmp *%eax");
}

SMstDigiDistInfo * CMstNetLayer::GetDigiDistInfo(CExoString &)
{
    asm("leave");
    asm("mov $0x082988c8, %eax");
    asm("jmp *%eax");
}

int CMstNetLayer::GetDigiDistModuleCipher(CExoString &, int)
{
    asm("leave");
    asm("mov $0x08297d60, %eax");
    asm("jmp *%eax");
}

CExoString CMstNetLayer::GetKeyAuthDemand(CExoString &)
{
    asm("leave");
    asm("mov $0x08297990, %eax");
    asm("jmp *%eax");
}

CExoString CMstNetLayer::GetKeyCollision()
{
    asm("leave");
    asm("mov $0x08297b0c, %eax");
    asm("jmp *%eax");
}

unsigned long CMstNetLayer::GetKeyRejectionReason(unsigned short)
{
    asm("leave");
    asm("mov $0x082987ac, %eax");
    asm("jmp *%eax");
}

unsigned short CMstNetLayer::GetKeyStatus(CExoString const &, unsigned short &)
{
    asm("leave");
    asm("mov $0x08297c78, %eax");
    asm("jmp *%eax");
}

CExoString CMstNetLayer::GetMasterServerInternetName()
{
    asm("leave");
    asm("mov $0x08297fdc, %eax");
    asm("jmp *%eax");
}

unsigned long CMstNetLayer::GetMasterServerPort()
{
    asm("leave");
    asm("mov $0x08298000, %eax");
    asm("jmp *%eax");
}

int CMstNetLayer::GetNextBuddyEntry()
{
    asm("leave");
    asm("mov $0x0829888c, %eax");
    asm("jmp *%eax");
}

void CMstNetLayer::HandleAddBuddyResponse(unsigned char *, unsigned long)
{
    asm("leave");
    asm("mov $0x08297560, %eax");
    asm("jmp *%eax");
}

void CMstNetLayer::HandleAuthorizationResponse(unsigned char *, unsigned long)
{
    asm("leave");
    asm("mov $0x08296f08, %eax");
    asm("jmp *%eax");
}

void CMstNetLayer::HandleCommunityNameAuthResponse(unsigned char *, unsigned long)
{
    asm("leave");
    asm("mov $0x08297280, %eax");
    asm("jmp *%eax");
}

void CMstNetLayer::HandleCreateAccountPartOne(unsigned char *, unsigned long)
{
    asm("leave");
    asm("mov $0x082973c4, %eax");
    asm("jmp *%eax");
}

void CMstNetLayer::HandleCreateAccountPartTwo(unsigned char *, unsigned long)
{
    asm("leave");
    asm("mov $0x082974a8, %eax");
    asm("jmp *%eax");
}

void CMstNetLayer::HandleDemandAuthorization(unsigned char *, unsigned long)
{
    asm("leave");
    asm("mov $0x0829688c, %eax");
    asm("jmp *%eax");
}

void CMstNetLayer::HandleDemandHeartbeat(unsigned char *, unsigned long)
{
    asm("leave");
    asm("mov $0x08298544, %eax");
    asm("jmp *%eax");
}

void CMstNetLayer::HandleDigiDistAuthResponse(unsigned char *, unsigned long)
{
    asm("leave");
    asm("mov $0x0829789c, %eax");
    asm("jmp *%eax");
}

void CMstNetLayer::HandleGetAvailabilityResponse(unsigned char *, unsigned long)
{
    asm("leave");
    asm("mov $0x08298768, %eax");
    asm("jmp *%eax");
}

void CMstNetLayer::HandleGetBuddyListResponse(unsigned char *, unsigned long)
{
    asm("leave");
    asm("mov $0x08297700, %eax");
    asm("jmp *%eax");
}

void CMstNetLayer::HandleMOTDResponse(unsigned char *, unsigned long)
{
    asm("leave");
    asm("mov $0x0829866c, %eax");
    asm("jmp *%eax");
}

int CMstNetLayer::HandleMasterServerToGameMessage(unsigned char *, unsigned long)
{
    asm("leave");
    asm("mov $0x082965a4, %eax");
    asm("jmp *%eax");
}

void CMstNetLayer::HandleNotifyCollision(unsigned char *, unsigned long)
{
    asm("leave");
    asm("mov $0x08296c40, %eax");
    asm("jmp *%eax");
}

void CMstNetLayer::HandleRemoveBuddyResponse(unsigned char *, unsigned long)
{
    asm("leave");
    asm("mov $0x08297630, %eax");
    asm("jmp *%eax");
}

void CMstNetLayer::HandleSetAvailabilityResponse(unsigned char *, unsigned long)
{
    asm("leave");
    asm("mov $0x0829872c, %eax");
    asm("jmp *%eax");
}

void CMstNetLayer::HandleStatusResponse(unsigned char *, unsigned long)
{
    asm("leave");
    asm("mov $0x082985c8, %eax");
    asm("jmp *%eax");
}

void CMstNetLayer::HandleVersionResponse(unsigned char *, unsigned long)
{
    asm("leave");
    asm("mov $0x082986cc, %eax");
    asm("jmp *%eax");
}

int CMstNetLayer::SendAddBuddyRequest(CExoString const &, CExoString const &)
{
    asm("leave");
    asm("mov $0x08295ab8, %eax");
    asm("jmp *%eax");
}

int CMstNetLayer::SendClientToMasterCreateAccountPartOne(CExoString const &)
{
    asm("leave");
    asm("mov $0x08295414, %eax");
    asm("jmp *%eax");
}

int CMstNetLayer::SendClientToMasterCreateAccountPartTwo(CExoString const &, CExoString const &, CExoString const &, unsigned char *, CExoString const &)
{
    asm("leave");
    asm("mov $0x08295508, %eax");
    asm("jmp *%eax");
}

int CMstNetLayer::SendClientToMasterMOTDRequest(unsigned short)
{
    asm("leave");
    asm("mov $0x08298438, %eax");
    asm("jmp *%eax");
}

int CMstNetLayer::SendClientToMasterVersionRequest(unsigned short)
{
    asm("leave");
    asm("mov $0x082984bc, %eax");
    asm("jmp *%eax");
}

int CMstNetLayer::SendDigiDistAuthRequest(CExoArrayList<CExoString> *, CExoString const &)
{
    asm("leave");
    asm("mov $0x08295f54, %eax");
    asm("jmp *%eax");
}

int CMstNetLayer::SendGameToMasterAuthorizationRequest(void *, int)
{
    asm("leave");
    asm("mov $0x08294e64, %eax");
    asm("jmp *%eax");
}

int CMstNetLayer::SendGameToMasterAuthorizationRequest(unsigned long, int)
{
    asm("leave");
    asm("mov $0x08294530, %eax");
    asm("jmp *%eax");
}

int CMstNetLayer::SendGameToMasterCommunityNameAuth(CExoString const &, CExoString const &, CExoString const &, unsigned short, unsigned char)
{
    asm("leave");
    asm("mov $0x0829521c, %eax");
    asm("jmp *%eax");
}

int CMstNetLayer::SendGameToMasterDisconnect(void *, int)
{
    asm("leave");
    asm("mov $0x0829515c, %eax");
    asm("jmp *%eax");
}

int CMstNetLayer::SendGameToMasterDisconnect(unsigned long)
{
    asm("leave");
    asm("mov $0x08294fd0, %eax");
    asm("jmp *%eax");
}

int CMstNetLayer::SendGameToMasterHeartbeat(void *, int)
{
    asm("leave");
    asm("mov $0x08294f10, %eax");
    asm("jmp *%eax");
}

int CMstNetLayer::SendGameToMasterModule(unsigned char, CExoString const &)
{
    asm("leave");
    asm("mov $0x08298394, %eax");
    asm("jmp *%eax");
}

int CMstNetLayer::SendGameToMasterShutDown()
{
    asm("leave");
    asm("mov $0x08298328, %eax");
    asm("jmp *%eax");
}

int CMstNetLayer::SendGameToMasterStartup(unsigned char, unsigned long, int, unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x082982b0, %eax");
    asm("jmp *%eax");
}

int CMstNetLayer::SendGameToMasterStatusRequest()
{
    asm("leave");
    asm("mov $0x0829824c, %eax");
    asm("jmp *%eax");
}

int CMstNetLayer::SendGetAvailabilityRequest(CExoString const &)
{
    asm("leave");
    asm("mov $0x08295e90, %eax");
    asm("jmp *%eax");
}

int CMstNetLayer::SendGetBuddyListRequest(CExoString const &)
{
    asm("leave");
    asm("mov $0x08295ce8, %eax");
    asm("jmp *%eax");
}

int CMstNetLayer::SendRemoveBuddyRequest(CExoString const &, CExoString const &)
{
    asm("leave");
    asm("mov $0x08295bd0, %eax");
    asm("jmp *%eax");
}

int CMstNetLayer::SendSetAvailabilityRequest(CExoString const &, unsigned short)
{
    asm("leave");
    asm("mov $0x08295dac, %eax");
    asm("jmp *%eax");
}

void CMstNetLayer::SetLanguage(int)
{
    asm("leave");
    asm("mov $0x08294290, %eax");
    asm("jmp *%eax");
}

int CMstNetLayer::StartHeartbeatTimer(unsigned long long)
{
    asm("leave");
    asm("mov $0x0829800c, %eax");
    asm("jmp *%eax");
}

int CMstNetLayer::StartSystemUpdateTimer(unsigned long long)
{
    asm("leave");
    asm("mov $0x082980cc, %eax");
    asm("jmp *%eax");
}

int CMstNetLayer::StartTimeOutTimer(unsigned long long)
{
    asm("leave");
    asm("mov $0x0829818c, %eax");
    asm("jmp *%eax");
}

int CMstNetLayer::UpdateHeartbeatTimer(unsigned long long)
{
    asm("leave");
    asm("mov $0x08298030, %eax");
    asm("jmp *%eax");
}

int CMstNetLayer::UpdateSystemUpdateTimer(unsigned long long)
{
    asm("leave");
    asm("mov $0x082980f0, %eax");
    asm("jmp *%eax");
}

int CMstNetLayer::UpdateTimeOutTimer(unsigned long long)
{
    asm("leave");
    asm("mov $0x082981b0, %eax");
    asm("jmp *%eax");
}

