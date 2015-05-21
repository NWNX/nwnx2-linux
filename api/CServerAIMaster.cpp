#include "CServerAIMaster.h"

int CServerAIMaster::AddEventAbsoluteTimeViaTail(unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, void *)
{
    asm("leave");
    asm("mov $0x0809820c, %eax");
    asm("jmp *%eax");
}

int CServerAIMaster::AddEventAbsoluteTime(unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, void *)
{
    asm("leave");
    asm("mov $0x0809813c, %eax");
    asm("jmp *%eax");
}

int CServerAIMaster::AddEventDeltaTime(unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, void *)
{
    asm("leave");
    asm("mov $0x08096388, %eax");
    asm("jmp *%eax");
}

int CServerAIMaster::AddObject(CNWSObject *, int)
{
    asm("leave");
    asm("mov $0x080980e0, %eax");
    asm("jmp *%eax");
}

void CServerAIMaster::AdjustTargetAndWitnessReputations(unsigned long, unsigned long, int)
{
    asm("leave");
    asm("mov $0x08096480, %eax");
    asm("jmp *%eax");
}

void CServerAIMaster::ClearEventQueue()
{
    asm("leave");
    asm("mov $0x080980a4, %eax");
    asm("jmp *%eax");
}

void CServerAIMaster::DeleteEventData(unsigned long, void *)
{
    asm("leave");
    asm("mov $0x080976c0, %eax");
    asm("jmp *%eax");
}

int CServerAIMaster::EventPending(unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x080982dc, %eax");
    asm("jmp *%eax");
}

int CServerAIMaster::GetPendingEvent(unsigned long *, unsigned long *, unsigned long *, unsigned long *, unsigned long *, void **)
{
    asm("leave");
    asm("mov $0x08098334, %eax");
    asm("jmp *%eax");
}

int CServerAIMaster::LoadEventQueue(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x0809844c, %eax");
    asm("jmp *%eax");
}

void CServerAIMaster::LoadReputationAdjustments()
{
    asm("leave");
    asm("mov $0x08096de0, %eax");
    asm("jmp *%eax");
}

int CServerAIMaster::OnEffectApplied(CNWSObject *, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x080984e4, %eax");
    asm("jmp *%eax");
}

int CServerAIMaster::OnEffectRemoved(CNWSObject *, CGameEffect *)
{
    asm("leave");
    asm("mov $0x08098508, %eax");
    asm("jmp *%eax");
}

int CServerAIMaster::OnItemPropertyApplied(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int)
{
    asm("leave");
    asm("mov $0x08098528, %eax");
    asm("jmp *%eax");
}

int CServerAIMaster::OnItemPropertyRemoved(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long)
{
    asm("leave");
    asm("mov $0x08098550, %eax");
    asm("jmp *%eax");
}

int CServerAIMaster::RemoveObject(CNWSObject *)
{
    asm("leave");
    asm("mov $0x080962a8, %eax");
    asm("jmp *%eax");
}

int CServerAIMaster::SaveEventQueue(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x080983a8, %eax");
    asm("jmp *%eax");
}

int CServerAIMaster::SetAILevel(CNWSObject *, int)
{
    asm("leave");
    asm("mov $0x08096318, %eax");
    asm("jmp *%eax");
}

void CServerAIMaster::SetExoAppInternal(CServerExoAppInternal *)
{
    asm("leave");
    asm("mov $0x08098094, %eax");
    asm("jmp *%eax");
}

void CServerAIMaster::UpdateState()
{
    asm("leave");
    asm("mov $0x08095d60, %eax");
    asm("jmp *%eax");
}

