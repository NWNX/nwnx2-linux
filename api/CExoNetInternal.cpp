#include "CExoNetInternal.h"

unsigned long CExoNetInternal::AddressTranslationAvailable()
{
    asm("leave");
    asm("mov $0x082c88cc, %eax");
    asm("jmp *%eax");
}

void CExoNetInternal::ClearNetworkAddressProtect()
{
    asm("leave");
    asm("mov $0x082c8774, %eax");
    asm("jmp *%eax");
}

void CExoNetInternal::ClearUnusedNetworkAddresses(unsigned long)
{
    asm("leave");
    asm("mov $0x082c87ec, %eax");
    asm("jmp *%eax");
}

int CExoNetInternal::CloseTCPConnection(int)
{
    asm("leave");
    asm("mov $0x082c8a50, %eax");
    asm("jmp *%eax");
}

int CExoNetInternal::CompareToLocalAddress(unsigned long, unsigned char *, unsigned char *)
{
    asm("leave");
    asm("mov $0x082c8598, %eax");
    asm("jmp *%eax");
}

void CExoNetInternal::EndAddressTranslation()
{
    asm("leave");
    asm("mov $0x082c8974, %eax");
    asm("jmp *%eax");
}

int CExoNetInternal::EndIncomingMessageProcessing()
{
    asm("leave");
    asm("mov $0x082c83c0, %eax");
    asm("jmp *%eax");
}

int CExoNetInternal::EnumerateLocalAddresses(unsigned long)
{
    asm("leave");
    asm("mov $0x082c7c64, %eax");
    asm("jmp *%eax");
}

void CExoNetInternal::ExoWarningOnError()
{
    asm("leave");
    asm("mov $0x082c89f4, %eax");
    asm("jmp *%eax");
}

int CExoNetInternal::FetchIncomingMessage(unsigned long *, unsigned char **, unsigned long *)
{
    asm("leave");
    asm("mov $0x082c831c, %eax");
    asm("jmp *%eax");
}

void CExoNetInternal::GetAddressTranslation(unsigned char *)
{
    asm("leave");
    asm("mov $0x082c8928, %eax");
    asm("jmp *%eax");
}

int CExoNetInternal::GetLocalAdapterString(unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x082c8658, %eax");
    asm("jmp *%eax");
}

int CExoNetInternal::GetNetworkAddressData(unsigned long, unsigned long *, unsigned char **, unsigned char **, unsigned long *)
{
    asm("leave");
    asm("mov $0x082c853c, %eax");
    asm("jmp *%eax");
}

CExoString CExoNetInternal::GetNetworkAddressString(unsigned long)
{
    asm("leave");
    asm("mov $0x082c8400, %eax");
    asm("jmp *%eax");
}

int CExoNetInternal::GetNumberLocalAdapters(unsigned long)
{
    asm("leave");
    asm("mov $0x082c861c, %eax");
    asm("jmp *%eax");
}

int CExoNetInternal::GetProtocolInitialized(unsigned long)
{
    asm("leave");
    asm("mov $0x082c814c, %eax");
    asm("jmp *%eax");
}

unsigned long CExoNetInternal::GetProtocolReceivePort(unsigned long)
{
    asm("leave");
    asm("mov $0x082c8170, %eax");
    asm("jmp *%eax");
}

int CExoNetInternal::GetProtocolSendPort(unsigned long)
{
    asm("leave");
    asm("mov $0x082c8194, %eax");
    asm("jmp *%eax");
}

unsigned long CExoNetInternal::GetSendUDPSocket()
{
    asm("leave");
    asm("mov $0x082c89e8, %eax");
    asm("jmp *%eax");
}

int CExoNetInternal::GetTCPMessage(int *, char **, int *)
{
    asm("leave");
    asm("mov $0x082c8078, %eax");
    asm("jmp *%eax");
}

int CExoNetInternal::InitializeProtocol(unsigned long, unsigned long, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x082c755c, %eax");
    asm("jmp *%eax");
}

int CExoNetInternal::MessageArrived(unsigned long, unsigned long, unsigned long, int)
{
    asm("leave");
    asm("mov $0x082c7734, %eax");
    asm("jmp *%eax");
}

int CExoNetInternal::OpenTCPConnection(int, CExoString, int)
{
    asm("leave");
    asm("mov $0x082c7edc, %eax");
    asm("jmp *%eax");
}

int CExoNetInternal::RemoveIncomingMessage()
{
    asm("leave");
    asm("mov $0x082c8374, %eax");
    asm("jmp *%eax");
}

int CExoNetInternal::SendMessage(unsigned long, unsigned char *, unsigned long, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x082c789c, %eax");
    asm("jmp *%eax");
}

int CExoNetInternal::SendTCPMessage(int, char *, int)
{
    asm("leave");
    asm("mov $0x082c89fc, %eax");
    asm("jmp *%eax");
}

int CExoNetInternal::SetConnectionIdTimer(unsigned long)
{
    asm("leave");
    asm("mov $0x082c872c, %eax");
    asm("jmp *%eax");
}

void CExoNetInternal::SetMasterServerInternetAddress(unsigned char const *, unsigned long)
{
    asm("leave");
    asm("mov $0x082c89bc, %eax");
    asm("jmp *%eax");
}

unsigned long CExoNetInternal::SetNetworkAddressData(unsigned long, unsigned char *, unsigned char *, unsigned long)
{
    asm("leave");
    asm("mov $0x082c79a4, %eax");
    asm("jmp *%eax");
}

int CExoNetInternal::SetNetworkAddressProtect(unsigned long, int)
{
    asm("leave");
    asm("mov $0x082c8798, %eax");
    asm("jmp *%eax");
}

int CExoNetInternal::ShutDownProtocol(unsigned long)
{
    asm("leave");
    asm("mov $0x082c81b8, %eax");
    asm("jmp *%eax");
}

void CExoNetInternal::StartAddressTranslation(CExoString, unsigned long)
{
    asm("leave");
    asm("mov $0x082c7cfc, %eax");
    asm("jmp *%eax");
}

int CExoNetInternal::StartIncomingMessageProcessing()
{
    asm("leave");
    asm("mov $0x082c82cc, %eax");
    asm("jmp *%eax");
}

void CExoNetInternal::StoreMessage(unsigned char *, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x082c823c, %eax");
    asm("jmp *%eax");
}

int CExoNetInternal::TranslateAddressFromString(char *, unsigned long *, unsigned char *, unsigned char *, unsigned long *)
{
    asm("leave");
    asm("mov $0x082c84bc, %eax");
    asm("jmp *%eax");
}

int CExoNetInternal::WinSockInitialize()
{
    asm("leave");
    asm("mov $0x082c822c, %eax");
    asm("jmp *%eax");
}

