#include "CExoNet.h"

unsigned long CExoNet::AddressTranslationAvailable()
{
    asm("leave");
    asm("mov $0x082c63ac, %eax");
    asm("jmp *%eax");
}

void CExoNet::ClearNetworkAddressProtect()
{
    asm("leave");
    asm("mov $0x082c62b4, %eax");
    asm("jmp *%eax");
}

int CExoNet::ClearUnusedNetworkAddresses(unsigned long)
{
    asm("leave");
    asm("mov $0x082c6318, %eax");
    asm("jmp *%eax");
}

int CExoNet::CloseTCPConnection(int)
{
    asm("leave");
    asm("mov $0x082c6524, %eax");
    asm("jmp *%eax");
}

int CExoNet::CompareToLocalAddress(unsigned long, unsigned char *, unsigned char *)
{
    asm("leave");
    asm("mov $0x082c629c, %eax");
    asm("jmp *%eax");
}

int CExoNet::CompareToSpecificInternetAddress(unsigned char *)
{
    asm("leave");
    asm("mov $0x082c6434, %eax");
    asm("jmp *%eax");
}

void CExoNet::EndAddressTranslation()
{
    asm("leave");
    asm("mov $0x082c63d4, %eax");
    asm("jmp *%eax");
}

int CExoNet::EndIncomingMessageProcessing()
{
    asm("leave");
    asm("mov $0x082c61e0, %eax");
    asm("jmp *%eax");
}

int CExoNet::FetchIncomingMessage(unsigned long *, unsigned char **, unsigned long *)
{
    asm("leave");
    asm("mov $0x082c61f4, %eax");
    asm("jmp *%eax");
}

void CExoNet::GetAddressTranslation(unsigned char *)
{
    asm("leave");
    asm("mov $0x082c63c0, %eax");
    asm("jmp *%eax");
}

int CExoNet::GetLocalAdapterString(unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x082c62f0, %eax");
    asm("jmp *%eax");
}

int CExoNet::GetNetworkAddressData(unsigned long, unsigned long *, unsigned char **, unsigned char **, unsigned long *)
{
    asm("leave");
    asm("mov $0x082c6264, %eax");
    asm("jmp *%eax");
}

CExoString CExoNet::GetNetworkAddressString(unsigned long)
{
    asm("leave");
    asm("mov $0x082c6220, %eax");
    asm("jmp *%eax");
}

int CExoNet::GetNumberLocalAdapters(unsigned long)
{
    asm("leave");
    asm("mov $0x082c62dc, %eax");
    asm("jmp *%eax");
}

int CExoNet::GetProtocolInitialized(unsigned long)
{
    asm("leave");
    asm("mov $0x082c612c, %eax");
    asm("jmp *%eax");
}

unsigned long CExoNet::GetProtocolReceivePort(unsigned long)
{
    asm("leave");
    asm("mov $0x082c6140, %eax");
    asm("jmp *%eax");
}

int CExoNet::GetProtocolSendPort(unsigned long)
{
    asm("leave");
    asm("mov $0x082c6154, %eax");
    asm("jmp *%eax");
}

unsigned long CExoNet::GetSendUDPSocket()
{
    asm("leave");
    asm("mov $0x082c6474, %eax");
    asm("jmp *%eax");
}

void CExoNet::GetSpecificInternetAddress(unsigned char *, unsigned short *)
{
    asm("leave");
    asm("mov $0x082c640c, %eax");
    asm("jmp *%eax");
}

int CExoNet::GetTCPMessage(int *, char **, int *)
{
    asm("leave");
    asm("mov $0x082c64f4, %eax");
    asm("jmp *%eax");
}

int CExoNet::InitializeProtocol(unsigned long, unsigned long, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x082c6114, %eax");
    asm("jmp *%eax");
}

int CExoNet::MessageArrived(unsigned long, unsigned long, unsigned long, int)
{
    asm("leave");
    asm("mov $0x082c619c, %eax");
    asm("jmp *%eax");
}

int CExoNet::OpenTCPConnection(int, CExoString, int)
{
    asm("leave");
    asm("mov $0x082c6488, %eax");
    asm("jmp *%eax");
}

int CExoNet::RemoveIncomingMessage()
{
    asm("leave");
    asm("mov $0x082c620c, %eax");
    asm("jmp *%eax");
}

int CExoNet::SendDirectMessage(unsigned long, unsigned char *, unsigned long, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x082c617c, %eax");
    asm("jmp *%eax");
}

int CExoNet::SendTCPMessage(int, char *, int)
{
    asm("leave");
    asm("mov $0x082c650c, %eax");
    asm("jmp *%eax");
}

void CExoNet::SetMasterServerInternetAddress(unsigned char const *, unsigned long)
{
    asm("leave");
    asm("mov $0x082c6460, %eax");
    asm("jmp *%eax");
}

unsigned long CExoNet::SetNetworkAddressData(unsigned long, unsigned char *, unsigned char *, unsigned long)
{
    asm("leave");
    asm("mov $0x082c6284, %eax");
    asm("jmp *%eax");
}

int CExoNet::SetNetworkAddressProtect(unsigned long, int)
{
    asm("leave");
    asm("mov $0x082c62c8, %eax");
    asm("jmp *%eax");
}

int CExoNet::SetSpecificInternetAddress(unsigned char *, unsigned short)
{
    asm("leave");
    asm("mov $0x082c63e8, %eax");
    asm("jmp *%eax");
}

int CExoNet::ShutDownProtocol(unsigned long)
{
    asm("leave");
    asm("mov $0x082c6168, %eax");
    asm("jmp *%eax");
}

void CExoNet::StartAddressTranslation(CExoString, unsigned long)
{
    asm("leave");
    asm("mov $0x082c6344, %eax");
    asm("jmp *%eax");
}

int CExoNet::StartIncomingMessageProcessing()
{
    asm("leave");
    asm("mov $0x082c61cc, %eax");
    asm("jmp *%eax");
}

void CExoNet::StoreMessage(unsigned char *, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x082c61b4, %eax");
    asm("jmp *%eax");
}

int CExoNet::TranslateAddressFromString(char *, unsigned long *, unsigned char *, unsigned char *, unsigned long *)
{
    asm("leave");
    asm("mov $0x082c6244, %eax");
    asm("jmp *%eax");
}

