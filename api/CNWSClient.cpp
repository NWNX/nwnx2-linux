#include "CNWSClient.h"

CNWSDungeonMaster * CNWSClient::AsNWSDungeonMaster()
{
    asm("leave");
    asm("mov $0x080e0098, %eax");
    asm("jmp *%eax");
}

CNWSPlayer * CNWSClient::AsNWSPlayer()
{
    asm("leave");
    asm("mov $0x080e00a0, %eax");
    asm("jmp *%eax");
}

int CNWSClient::GetLanguage()
{
    asm("leave");
    asm("mov $0x080e008c, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSClient::GetPlayerId()
{
    asm("leave");
    asm("mov $0x080e0070, %eax");
    asm("jmp *%eax");
}

int CNWSClient::SetLanguage(int)
{
    asm("leave");
    asm("mov $0x080e007c, %eax");
    asm("jmp *%eax");
}

