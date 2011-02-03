#ifndef _CEXONETINTERNAL_H_
#define _CEXONETINTERNAL_H_
#include "nwndef.h"
#include "CExoString.h"

class CExoNetInternal
{
public:
	int AddressTranslationAvailable();
	int ClearNetworkAddressProtect();
	int ClearUnusedNetworkAddresses(unsigned long);
	int CloseTCPConnection(int);
	int CompareToLocalAddress(unsigned long, unsigned char *, unsigned char *);
	int EndAddressTranslation();
	int EndIncomingMessageProcessing();
	int EnumerateLocalAddresses(unsigned long);
	int ExoWarningOnError();
	int FetchIncomingMessage(unsigned long *, unsigned char **, unsigned long *);
	int GetAddressTranslation(unsigned char *);
	int GetLocalAdapterString(unsigned long, unsigned long);
	int GetNetworkAddressData(unsigned long, unsigned long *, unsigned char **, unsigned char **, unsigned long *);
	int GetNetworkAddressString(unsigned long);
	int GetNumberLocalAdapters(unsigned long);
	int GetProtocolInitialized(unsigned long);
	int GetProtocolReceivePort(unsigned long);
	int GetProtocolSendPort(unsigned long);
	int GetSendUDPSocket();
	int GetTCPMessage(int *, char **, int *);
	int InitializeProtocol(unsigned long, unsigned long, unsigned long, unsigned long);
	int MessageArrived(unsigned long, unsigned long, unsigned long, int);
	int OpenTCPConnection(int, CExoString, int);
	int RemoveIncomingMessage();
	int SendMessage(unsigned long, unsigned char *, unsigned long, unsigned long, unsigned long);
	int SendTCPMessage(int, char *, int);
	int SetConnectionIdTimer(unsigned long);
	int SetMasterServerInternetAddress(unsigned char const *, unsigned long);
	int SetNetworkAddressData(unsigned long, unsigned char *, unsigned char *, unsigned long);
	int SetNetworkAddressProtect(unsigned long, int);
	int ShutDownProtocol(unsigned long);
	int StartAddressTranslation(CExoString, unsigned long);
	int StartIncomingMessageProcessing();
	int StoreMessage(unsigned char *, unsigned long, unsigned long);
	int TranslateAddressFromString(char *, unsigned long *, unsigned char *, unsigned char *, unsigned long *);
	int WinSockInitialize();
	~CExoNetInternal();
	CExoNetInternal();

};
#endif
