#include "CNWSCombatRound.h"

int CNWSCombatRound::AddAction(CNWSCombatRoundAction *)
{
    asm("leave");
    asm("mov $0x080e50dc, %eax");
    asm("jmp *%eax");
}

void CNWSCombatRound::AddAttackOfOpportunity(unsigned long)
{
    asm("leave");
    asm("mov $0x080e31e0, %eax");
    asm("jmp *%eax");
}

void CNWSCombatRound::AddCircleKickAttack(unsigned long)
{
    asm("leave");
    asm("mov $0x080e2f94, %eax");
    asm("jmp *%eax");
}

void CNWSCombatRound::AddCleaveAttack(unsigned long, int)
{
    asm("leave");
    asm("mov $0x080e2e4c, %eax");
    asm("jmp *%eax");
}

void CNWSCombatRound::AddCombatStepAction(unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x080e3688, %eax");
    asm("jmp *%eax");
}

void CNWSCombatRound::AddEquipAction(unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x080e332c, %eax");
    asm("jmp *%eax");
}

void CNWSCombatRound::AddParryAttack(unsigned long)
{
    asm("leave");
    asm("mov $0x080e2be4, %eax");
    asm("jmp *%eax");
}

void CNWSCombatRound::AddParryIndex()
{
    asm("leave");
    asm("mov $0x080e2d40, %eax");
    asm("jmp *%eax");
}

void CNWSCombatRound::AddReaction(int, int)
{
    asm("leave");
    asm("mov $0x080e29bc, %eax");
    asm("jmp *%eax");
}

void CNWSCombatRound::AddSpecialAttack(unsigned short)
{
    asm("leave");
    asm("mov $0x080e2494, %eax");
    asm("jmp *%eax");
}

void CNWSCombatRound::AddSpellAction()
{
    asm("leave");
    asm("mov $0x080e2ad8, %eax");
    asm("jmp *%eax");
}

void CNWSCombatRound::AddUnequipAction(unsigned long, unsigned long, unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x080e350c, %eax");
    asm("jmp *%eax");
}

void CNWSCombatRound::AddWhirlwindAttack(unsigned long, int)
{
    asm("leave");
    asm("mov $0x080e30d0, %eax");
    asm("jmp *%eax");
}

int CNWSCombatRound::CalculateOffHandAttacks()
{
    asm("leave");
    asm("mov $0x080e1d50, %eax");
    asm("jmp *%eax");
}

int CNWSCombatRound::CheckActionLengthAtTime(unsigned long, int, int)
{
    asm("leave");
    asm("mov $0x080e4f04, %eax");
    asm("jmp *%eax");
}

int CNWSCombatRound::CheckActionLength(unsigned long, int)
{
    asm("leave");
    asm("mov $0x080e1c7c, %eax");
    asm("jmp *%eax");
}

void CNWSCombatRound::ClearAllAttacks()
{
    asm("leave");
    asm("mov $0x080e5260, %eax");
    asm("jmp *%eax");
}

void CNWSCombatRound::ClearAllSpecialAttacks()
{
    asm("leave");
    asm("mov $0x080e5388, %eax");
    asm("jmp *%eax");
}

void CNWSCombatRound::DecrementPauseTimer(int)
{
    asm("leave");
    asm("mov $0x080e4dd8, %eax");
    asm("jmp *%eax");
}

void CNWSCombatRound::DecrementRoundLength(int, int)
{
    asm("leave");
    asm("mov $0x080e1ac4, %eax");
    asm("jmp *%eax");
}

void CNWSCombatRound::EndCombatRound()
{
    asm("leave");
    asm("mov $0x080e1908, %eax");
    asm("jmp *%eax");
}

int CNWSCombatRound::GetActionPending()
{
    asm("leave");
    asm("mov $0x080e4f6c, %eax");
    asm("jmp *%eax");
}

CNWSCombatRoundAction * CNWSCombatRound::GetAction()
{
    asm("leave");
    asm("mov $0x080e50a0, %eax");
    asm("jmp *%eax");
}

int CNWSCombatRound::GetAttackActionPending()
{
    asm("leave");
    asm("mov $0x080e4fbc, %eax");
    asm("jmp *%eax");
}

CNWSCombatAttackData * CNWSCombatRound::GetAttack(int)
{
    asm("leave");
    asm("mov $0x080e522c, %eax");
    asm("jmp *%eax");
}

int CNWSCombatRound::GetCombatStepRequired(unsigned long)
{
    asm("leave");
    asm("mov $0x080e3be4, %eax");
    asm("jmp *%eax");
}

CNWSItem * CNWSCombatRound::GetCurrentAttackWeapon(int)
{
    asm("leave");
    asm("mov $0x080e3778, %eax");
    asm("jmp *%eax");
}

int CNWSCombatRound::GetExtraAttack()
{
    asm("leave");
    asm("mov $0x080e51f4, %eax");
    asm("jmp *%eax");
}

unsigned short CNWSCombatRound::GetNewAttackID()
{
    asm("leave");
    asm("mov $0x080e535c, %eax");
    asm("jmp *%eax");
}

int CNWSCombatRound::GetNumSpecialAttacks()
{
    asm("leave");
    asm("mov $0x080e52dc, %eax");
    asm("jmp *%eax");
}

int CNWSCombatRound::GetOffHandAttack()
{
    asm("leave");
    asm("mov $0x080e51bc, %eax");
    asm("jmp *%eax");
}

unsigned short CNWSCombatRound::GetSpecialAttackID(int)
{
    asm("leave");
    asm("mov $0x080e2808, %eax");
    asm("jmp *%eax");
}

unsigned short CNWSCombatRound::GetSpecialAttack(int)
{
    asm("leave");
    asm("mov $0x080e2760, %eax");
    asm("jmp *%eax");
}

int CNWSCombatRound::GetSpellActionPending()
{
    asm("leave");
    asm("mov $0x080e5010, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSCombatRound::GetTotalAttacks()
{
    asm("leave");
    asm("mov $0x080e5534, %eax");
    asm("jmp *%eax");
}

int CNWSCombatRound::GetWeaponAttackType()
{
    asm("leave");
    asm("mov $0x080e38dc, %eax");
    asm("jmp *%eax");
}

int CNWSCombatRound::HasCreatureWeapons()
{
    asm("leave");
    asm("mov $0x080e3b30, %eax");
    asm("jmp *%eax");
}

void CNWSCombatRound::IncrementTimer(int)
{
    asm("leave");
    asm("mov $0x080e4d7c, %eax");
    asm("jmp *%eax");
}

void CNWSCombatRound::InitializeAttackActions(unsigned long)
{
    asm("leave");
    asm("mov $0x080e1e88, %eax");
    asm("jmp *%eax");
}

int CNWSCombatRound::InitializeCombatModes()
{
    asm("leave");
    asm("mov $0x080e52a0, %eax");
    asm("jmp *%eax");
}

void CNWSCombatRound::InitializeNumberOfAttacks()
{
    asm("leave");
    asm("mov $0x080e2260, %eax");
    asm("jmp *%eax");
}

int CNWSCombatRound::InsertSpecialAttack(unsigned short, int)
{
    asm("leave");
    asm("mov $0x080e2900, %eax");
    asm("jmp *%eax");
}

int CNWSCombatRound::LoadCombatRound(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x080e4340, %eax");
    asm("jmp *%eax");
}

void CNWSCombatRound::RecomputeRound()
{
    asm("leave");
    asm("mov $0x080e1390, %eax");
    asm("jmp *%eax");
}

void CNWSCombatRound::RemoveAllActions()
{
    asm("leave");
    asm("mov $0x080e516c, %eax");
    asm("jmp *%eax");
}

void CNWSCombatRound::RemoveSpecialAttack(int)
{
    asm("leave");
    asm("mov $0x080e25b8, %eax");
    asm("jmp *%eax");
}

void CNWSCombatRound::RemoveSpellAction()
{
    asm("leave");
    asm("mov $0x080e541c, %eax");
    asm("jmp *%eax");
}

int CNWSCombatRound::SaveCombatRound(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x080e3d68, %eax");
    asm("jmp *%eax");
}

void CNWSCombatRound::SetCurrentAttack(unsigned char)
{
    asm("leave");
    asm("mov $0x080e524c, %eax");
    asm("jmp *%eax");
}

void CNWSCombatRound::SetDeflectArrow(int)
{
    asm("leave");
    asm("mov $0x080e5560, %eax");
    asm("jmp *%eax");
}

void CNWSCombatRound::SetPauseTimer(int, int)
{
    asm("leave");
    asm("mov $0x080e4e78, %eax");
    asm("jmp *%eax");
}

void CNWSCombatRound::SetRoundPaused(int, unsigned long)
{
    asm("leave");
    asm("mov $0x080e4df8, %eax");
    asm("jmp *%eax");
}

int CNWSCombatRound::SignalCombatRoundStarted()
{
    asm("leave");
    asm("mov $0x080e4d30, %eax");
    asm("jmp *%eax");
}

void CNWSCombatRound::StartCombatRoundCast(unsigned long)
{
    asm("leave");
    asm("mov $0x080e180c, %eax");
    asm("jmp *%eax");
}

void CNWSCombatRound::StartCombatRound(unsigned long)
{
    asm("leave");
    asm("mov $0x080e11e8, %eax");
    asm("jmp *%eax");
}

void CNWSCombatRound::UpdateAttackTargetForAllActions(unsigned long)
{
    asm("leave");
    asm("mov $0x080e54c0, %eax");
    asm("jmp *%eax");
}

