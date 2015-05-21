#ifndef _CGAMESPYCLIENT_H_
#define _CGAMESPYCLIENT_H_
#include "nwndef.h"
#include "nwnstructs.h"

class CGameSpyClient
{
public:
    int ChatNameMangle(CExoString &);
    int ConnectCallback(void *, PEERBool, void *);
    int DisconnectedCallback(void *, char const *, void *);
    int EnumPlayersCallback(void *, PEERBool, RoomType, int, char const *, int, void *);
    int JoinGroupRoomCallback(void *, PEERBool, PEERJoinResult, RoomType, void *);
    int JoinGroupRoom(int);
    int ListGroupRoomsCallback(void *, PEERBool, int, _SBServer *, char const *, int, int, int, int, void *);
    int ListingGamesCallback(void *, PEERBool, char const *, _SBServer *, PEERBool, int, int, void *);
    int NickErrorCallback(void *, int, char const *, void *);
    int PlayerChangedNickCallback(void *, RoomType, char const *, char const *, void *);
    int PlayerJoinedCallback(void *, RoomType, char const *, void *);
    int PlayerLeftCallback(void *, RoomType, char const *, char const *, void *);
    int PlayerMessageCallback(void *, char const *, char const *, MessageType, void *);
    int RoomMessageCallback(void *, RoomType, char const *, char const *, MessageType, void *);
    int SendMessageToNick(char const *, char const *);
    int SendMessageToRoom(char const *);
    int SetGameBuildFilter(CExoString const &);
    int SetGameFilters();
    int Update();
    ~CGameSpyClient();
    CGameSpyClient(CConnectionLib *, int &, CExoString const &);

};
#endif
