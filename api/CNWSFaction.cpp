#include "CNWSFaction.h"

void CNWSFaction::AddMember(unsigned long, int)
{
    asm("leave");
    asm("mov $0x081d6990, %eax");
    asm("jmp *%eax");
}

int CNWSFaction::AttemptJoin(unsigned long)
{
    asm("leave");
    asm("mov $0x081d7d74, %eax");
    asm("jmp *%eax");
}

int CNWSFaction::AttemptRemove(unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x081d7da4, %eax");
    asm("jmp *%eax");
}

void CNWSFaction::ChangeMemberId(unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x081d7e48, %eax");
    asm("jmp *%eax");
}

void CNWSFaction::ClearAllReputationsTowards(unsigned long)
{
    asm("leave");
    asm("mov $0x081d84b0, %eax");
    asm("jmp *%eax");
}

int CNWSFaction::GetAverageGoodEvilAlignment()
{
    asm("leave");
    asm("mov $0x081d750c, %eax");
    asm("jmp *%eax");
}

int CNWSFaction::GetAverageLawChaosAlignment()
{
    asm("leave");
    asm("mov $0x081d75f4, %eax");
    asm("jmp *%eax");
}

int CNWSFaction::GetAverageLevel()
{
    asm("leave");
    asm("mov $0x081d8190, %eax");
    asm("jmp *%eax");
}

int CNWSFaction::GetAverageReputation(unsigned long)
{
    asm("leave");
    asm("mov $0x081d80fc, %eax");
    asm("jmp *%eax");
}

int CNWSFaction::GetAverageXP()
{
    asm("leave");
    asm("mov $0x081d820c, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSFaction::GetBestAC(unsigned long, int)
{
    asm("leave");
    asm("mov $0x081d79f4, %eax");
    asm("jmp *%eax");
}

int CNWSFaction::GetCreatureInParty(unsigned long)
{
    asm("leave");
    asm("mov $0x081d8278, %eax");
    asm("jmp *%eax");
}

int CNWSFaction::GetFactionManager()
{
    asm("leave");
    asm("mov $0x081d8424, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSFaction::GetFactionMember(int, int)
{
    asm("leave");
    asm("mov $0x081d83a0, %eax");
    asm("jmp *%eax");
}

int CNWSFaction::GetGold()
{
    asm("leave");
    asm("mov $0x081d80b8, %eax");
    asm("jmp *%eax");
}

int CNWSFaction::GetIsInvited(unsigned long)
{
    asm("leave");
    asm("mov $0x081d7e04, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSFaction::GetLeader()
{
    asm("leave");
    asm("mov $0x081d7ba4, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSFaction::GetLeastDamagedMember(unsigned long, int)
{
    asm("leave");
    asm("mov $0x081d7340, %eax");
    asm("jmp *%eax");
}

int CNWSFaction::GetMemberList(unsigned long **)
{
    asm("leave");
    asm("mov $0x081d7df0, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSFaction::GetMostDamagedMember(unsigned long, int)
{
    asm("leave");
    asm("mov $0x081d7168, %eax");
    asm("jmp *%eax");
}

int CNWSFaction::GetMostFrequentClass()
{
    asm("leave");
    asm("mov $0x081d76dc, %eax");
    asm("jmp *%eax");
}

int CNWSFaction::GetSingletonParty()
{
    asm("leave");
    asm("mov $0x081d82a8, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSFaction::GetStrongestMember(unsigned long, int)
{
    asm("leave");
    asm("mov $0x081d6fb8, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSFaction::GetWeakestMember(unsigned long, int)
{
    asm("leave");
    asm("mov $0x081d6e08, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSFaction::GetWorstAC(unsigned long, int)
{
    asm("leave");
    asm("mov $0x081d7844, %eax");
    asm("jmp *%eax");
}

int CNWSFaction::Initialise()
{
    asm("leave");
    asm("mov $0x081d8444, %eax");
    asm("jmp *%eax");
}

int CNWSFaction::InviteMember(unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x081d6b44, %eax");
    asm("jmp *%eax");
}

void CNWSFaction::RemoveMember(unsigned long)
{
    asm("leave");
    asm("mov $0x081d6bc8, %eax");
    asm("jmp *%eax");
}

void CNWSFaction::SendChatMessage(unsigned long, CExoString)
{
    asm("leave");
    asm("mov $0x081d7e90, %eax");
    asm("jmp *%eax");
}

void CNWSFaction::SendFactionUpdateAdd(unsigned long)
{
    asm("leave");
    asm("mov $0x081d7fcc, %eax");
    asm("jmp *%eax");
}

int CNWSFaction::SendFactionUpdateList()
{
    asm("leave");
    asm("mov $0x081d7f50, %eax");
    asm("jmp *%eax");
}

int CNWSFaction::SendFactionUpdateRemove(unsigned long)
{
    asm("leave");
    asm("mov $0x081d8048, %eax");
    asm("jmp *%eax");
}

int CNWSFaction::TransferLeadership(unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x081d8344, %eax");
    asm("jmp *%eax");
}

