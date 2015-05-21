#ifndef _CGAMESPYSERVER_H_
#define _CGAMESPYSERVER_H_
#include "nwndef.h"

class CGameSpyServer
{
public:
    int AddErrorCallback(qr2_error_t, char *, void *);
    int CountCallback(qr2_key_type, void *);
    int HandleGameSpyMessage(unsigned long, unsigned char *, unsigned long);
    int KeyListCallback(qr2_key_type, qr2_keybuffer_s *, void *);
    static void PlayerTeamKeyCallback(int, int, qr2_buffer_s *, void *);
    void RegisterAllKeys();
    static void ServerKeyCallback(int, qr2_buffer_s *, void *);
    void Update();
    ~CGameSpyServer();
    CGameSpyServer(int, CConnectionLib *, int &);

};
#endif
