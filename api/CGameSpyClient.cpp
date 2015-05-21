#include "CGameSpyClient.h"

int CGameSpyClient::ChatNameMangle(CExoString &)
{
    asm("leave");
    asm("mov $0x082740f0, %eax");
    asm("jmp *%eax");
}

int CGameSpyClient::ConnectCallback(void *, PEERBool, void *)
{
    asm("leave");
    asm("mov $0x0827456c, %eax");
    asm("jmp *%eax");
}

int CGameSpyClient::DisconnectedCallback(void *, char const *, void *)
{
    asm("leave");
    asm("mov $0x08274600, %eax");
    asm("jmp *%eax");
}

int CGameSpyClient::EnumPlayersCallback(void *, PEERBool, RoomType, int, char const *, int, void *)
{
    asm("leave");
    asm("mov $0x082747c4, %eax");
    asm("jmp *%eax");
}

int CGameSpyClient::JoinGroupRoomCallback(void *, PEERBool, PEERJoinResult, RoomType, void *)
{
    asm("leave");
    asm("mov $0x0827367c, %eax");
    asm("jmp *%eax");
}

int CGameSpyClient::JoinGroupRoom(int)
{
    asm("leave");
    asm("mov $0x082746f8, %eax");
    asm("jmp *%eax");
}

int CGameSpyClient::ListGroupRoomsCallback(void *, PEERBool, int, _SBServer *, char const *, int, int, int, int, void *)
{
    asm("leave");
    asm("mov $0x0827461c, %eax");
    asm("jmp *%eax");
}

int CGameSpyClient::ListingGamesCallback(void *, PEERBool, char const *, _SBServer *, PEERBool, int, int, void *)
{
    asm("leave");
    asm("mov $0x082737b0, %eax");
    asm("jmp *%eax");
}

int CGameSpyClient::NickErrorCallback(void *, int, char const *, void *)
{
    asm("leave");
    asm("mov $0x08273418, %eax");
    asm("jmp *%eax");
}

int CGameSpyClient::PlayerChangedNickCallback(void *, RoomType, char const *, char const *, void *)
{
    asm("leave");
    asm("mov $0x0827499c, %eax");
    asm("jmp *%eax");
}

int CGameSpyClient::PlayerJoinedCallback(void *, RoomType, char const *, void *)
{
    asm("leave");
    asm("mov $0x08274874, %eax");
    asm("jmp *%eax");
}

int CGameSpyClient::PlayerLeftCallback(void *, RoomType, char const *, char const *, void *)
{
    asm("leave");
    asm("mov $0x08274908, %eax");
    asm("jmp *%eax");
}

int CGameSpyClient::PlayerMessageCallback(void *, char const *, char const *, MessageType, void *)
{
    asm("leave");
    asm("mov $0x08274ac4, %eax");
    asm("jmp *%eax");
}

int CGameSpyClient::RoomMessageCallback(void *, RoomType, char const *, char const *, MessageType, void *)
{
    asm("leave");
    asm("mov $0x08274a30, %eax");
    asm("jmp *%eax");
}

int CGameSpyClient::SendMessageToNick(char const *, char const *)
{
    asm("leave");
    asm("mov $0x08274b90, %eax");
    asm("jmp *%eax");
}

int CGameSpyClient::SendMessageToRoom(char const *)
{
    asm("leave");
    asm("mov $0x08274b74, %eax");
    asm("jmp *%eax");
}

int CGameSpyClient::SetGameBuildFilter(CExoString const &)
{
    asm("leave");
    asm("mov $0x08274c44, %eax");
    asm("jmp *%eax");
}

int CGameSpyClient::SetGameFilters()
{
    asm("leave");
    asm("mov $0x08274bb0, %eax");
    asm("jmp *%eax");
}

int CGameSpyClient::Update()
{
    asm("leave");
    asm("mov $0x08274558, %eax");
    asm("jmp *%eax");
}

