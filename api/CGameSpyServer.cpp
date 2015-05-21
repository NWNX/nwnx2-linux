#include "CGameSpyServer.h"

int CGameSpyServer::AddErrorCallback(qr2_error_t, char *, void *)
{
    asm("leave");
    asm("mov $0x082744a4, %eax");
    asm("jmp *%eax");
}

int CGameSpyServer::CountCallback(qr2_key_type, void *)
{
    asm("leave");
    asm("mov $0x0827449c, %eax");
    asm("jmp *%eax");
}

int CGameSpyServer::HandleGameSpyMessage(unsigned long, unsigned char *, unsigned long)
{
    asm("leave");
    asm("mov $0x08272fbc, %eax");
    asm("jmp *%eax");
}

int CGameSpyServer::KeyListCallback(qr2_key_type, qr2_keybuffer_s *, void *)
{
    asm("leave");
    asm("mov $0x08272e80, %eax");
    asm("jmp *%eax");
}

void CGameSpyServer::PlayerTeamKeyCallback(int, int, qr2_buffer_s *, void *)
{
    asm("leave");
    asm("mov $0x0827447c, %eax");
    asm("jmp *%eax");
}

void CGameSpyServer::RegisterAllKeys()
{
    asm("leave");
    asm("mov $0x08274374, %eax");
    asm("jmp *%eax");
}

void CGameSpyServer::ServerKeyCallback(int, qr2_buffer_s *, void *)
{
    asm("leave");
    asm("mov $0x08274460, %eax");
    asm("jmp *%eax");
}

void CGameSpyServer::Update()
{
    asm("leave");
    asm("mov $0x082744e8, %eax");
    asm("jmp *%eax");
}

