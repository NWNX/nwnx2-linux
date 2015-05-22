#ifndef _CEXONETINTERNAL_H_
#define _CEXONETINTERNAL_H_
#include "nwndef.h"
#include "CExoString.h"

class CExoNetInternal
{
public:
    unsigned long AddressTranslationAvailable();
    void ClearNetworkAddressProtect();
    void ClearUnusedNetworkAddresses(unsigned long);
    int CloseTCPConnection(int);
    int CompareToLocalAddress(unsigned long, unsigned char *, unsigned char *);
    void EndAddressTranslation();
    int EndIncomingMessageProcessing();
    int EnumerateLocalAddresses(unsigned long);
    void ExoWarningOnError();
    int FetchIncomingMessage(unsigned long *, unsigned char **, unsigned long *);
    void GetAddressTranslation(unsigned char *);
    int GetLocalAdapterString(unsigned long, unsigned long);
    int GetNetworkAddressData(unsigned long, unsigned long *, unsigned char **, unsigned char **, unsigned long *);
    CExoString GetNetworkAddressString(unsigned long);
    int GetNumberLocalAdapters(unsigned long);
    int GetProtocolInitialized(unsigned long);
    unsigned long GetProtocolReceivePort(unsigned long);
    int GetProtocolSendPort(unsigned long);
    unsigned long GetSendUDPSocket();
    int GetTCPMessage(int *, char **, int *);
    int InitializeProtocol(unsigned long, unsigned long, unsigned long, unsigned long);
    int MessageArrived(unsigned long, unsigned long, unsigned long, int);
    int OpenTCPConnection(int, CExoString, int);
    int RemoveIncomingMessage();
    int SendMessage(unsigned long, unsigned char *, unsigned long, unsigned long, unsigned long);
    int SendTCPMessage(int, char *, int);
    int SetConnectionIdTimer(unsigned long);
    void SetMasterServerInternetAddress(unsigned char const *, unsigned long);
    unsigned long SetNetworkAddressData(unsigned long, unsigned char *, unsigned char *, unsigned long);
    int SetNetworkAddressProtect(unsigned long, int);
    int ShutDownProtocol(unsigned long);
    void StartAddressTranslation(CExoString, unsigned long);
    int StartIncomingMessageProcessing();
    void StoreMessage(unsigned char *, unsigned long, unsigned long);
    int TranslateAddressFromString(char *, unsigned long *, unsigned char *, unsigned char *, unsigned long *);
    int WinSockInitialize();
    ~CExoNetInternal();
    CExoNetInternal();

};
#endif
