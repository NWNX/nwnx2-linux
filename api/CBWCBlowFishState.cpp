#include "CBWCBlowFishState.h"

int CBWCBlowFishState::GetChain()
{
    asm("leave");
    asm("mov $0x0830836c, %eax");
    asm("jmp *%eax");
}

int CBWCBlowFishState::ResetChain()
{
    asm("leave");
    asm("mov $0x08308354, %eax");
    asm("jmp *%eax");
}

int CBWCBlowFishState::SetChain(CBWCBlowFishBlock)
{
    asm("leave");
    asm("mov $0x0830831c, %eax");
    asm("jmp *%eax");
}

