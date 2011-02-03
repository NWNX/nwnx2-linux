#include "CNWSCombatRound.h"

int CNWSCombatRound::AddAction(CNWSCombatRoundAction *)
{
	asm("leave");
	asm("mov $0x080e50dc, %eax");
	asm("jmp %eax");
}

int CNWSCombatRound::AddAttackOfOpportunity(unsigned long)
{
	asm("leave");
	asm("mov $0x080e31e0, %eax");
	asm("jmp %eax");
}

int CNWSCombatRound::AddCircleKickAttack(unsigned long)
{
	asm("leave");
	asm("mov $0x080e2f94, %eax");
	asm("jmp %eax");
}

int CNWSCombatRound::AddCleaveAttack(unsigned long, int)
{
	asm("leave");
	asm("mov $0x080e2e4c, %eax");
	asm("jmp %eax");
}

int CNWSCombatRound::AddCombatStepAction(unsigned long, unsigned long)
{
	asm("leave");
	asm("mov $0x080e3688, %eax");
	asm("jmp %eax");
}

int CNWSCombatRound::AddEquipAction(unsigned long, unsigned long)
{
	asm("leave");
	asm("mov $0x080e332c, %eax");
	asm("jmp %eax");
}

int CNWSCombatRound::AddParryAttack(unsigned long)
{
	asm("leave");
	asm("mov $0x080e2be4, %eax");
	asm("jmp %eax");
}

int CNWSCombatRound::AddParryIndex()
{
	asm("leave");
	asm("mov $0x080e2d40, %eax");
	asm("jmp %eax");
}

int CNWSCombatRound::AddReaction(int, int)
{
	asm("leave");
	asm("mov $0x080e29bc, %eax");
	asm("jmp %eax");
}

int CNWSCombatRound::AddSpecialAttack(unsigned short)
{
	asm("leave");
	asm("mov $0x080e2494, %eax");
	asm("jmp %eax");
}

int CNWSCombatRound::AddSpellAction()
{
	asm("leave");
	asm("mov $0x080e2ad8, %eax");
	asm("jmp %eax");
}

int CNWSCombatRound::AddUnequipAction(unsigned long, unsigned long, unsigned char, unsigned char)
{
	asm("leave");
	asm("mov $0x080e350c, %eax");
	asm("jmp %eax");
}

int CNWSCombatRound::AddWhirlwindAttack(unsigned long, int)
{
	asm("leave");
	asm("mov $0x080e30d0, %eax");
	asm("jmp %eax");
}

int CNWSCombatRound::CalculateOffHandAttacks()
{
	asm("leave");
	asm("mov $0x080e1d50, %eax");
	asm("jmp %eax");
}

int CNWSCombatRound::CheckActionLengthAtTime(unsigned long, int, int)
{
	asm("leave");
	asm("mov $0x080e4f04, %eax");
	asm("jmp %eax");
}

int CNWSCombatRound::CheckActionLength(unsigned long, int)
{
	asm("leave");
	asm("mov $0x080e1c7c, %eax");
	asm("jmp %eax");
}

int CNWSCombatRound::ClearAllAttacks()
{
	asm("leave");
	asm("mov $0x080e5260, %eax");
	asm("jmp %eax");
}

int CNWSCombatRound::ClearAllSpecialAttacks()
{
	asm("leave");
	asm("mov $0x080e5388, %eax");
	asm("jmp %eax");
}

int CNWSCombatRound::DecrementPauseTimer(int)
{
	asm("leave");
	asm("mov $0x080e4dd8, %eax");
	asm("jmp %eax");
}

int CNWSCombatRound::DecrementRoundLength(int, int)
{
	asm("leave");
	asm("mov $0x080e1ac4, %eax");
	asm("jmp %eax");
}

int CNWSCombatRound::EndCombatRound()
{
	asm("leave");
	asm("mov $0x080e1908, %eax");
	asm("jmp %eax");
}

int CNWSCombatRound::GetActionPending()
{
	asm("leave");
	asm("mov $0x080e4f6c, %eax");
	asm("jmp %eax");
}

int CNWSCombatRound::GetAction()
{
	asm("leave");
	asm("mov $0x080e50a0, %eax");
	asm("jmp %eax");
}

int CNWSCombatRound::GetAttackActionPending()
{
	asm("leave");
	asm("mov $0x080e4fbc, %eax");
	asm("jmp %eax");
}

int CNWSCombatRound::GetAttack(int)
{
	asm("leave");
	asm("mov $0x080e522c, %eax");
	asm("jmp %eax");
}

int CNWSCombatRound::GetCombatStepRequired(unsigned long)
{
	asm("leave");
	asm("mov $0x080e3be4, %eax");
	asm("jmp %eax");
}

int CNWSCombatRound::GetCurrentAttackWeapon(int)
{
	asm("leave");
	asm("mov $0x080e3778, %eax");
	asm("jmp %eax");
}

int CNWSCombatRound::GetExtraAttack()
{
	asm("leave");
	asm("mov $0x080e51f4, %eax");
	asm("jmp %eax");
}

int CNWSCombatRound::GetNewAttackID()
{
	asm("leave");
	asm("mov $0x080e535c, %eax");
	asm("jmp %eax");
}

int CNWSCombatRound::GetNumSpecialAttacks()
{
	asm("leave");
	asm("mov $0x080e52dc, %eax");
	asm("jmp %eax");
}

int CNWSCombatRound::GetOffHandAttack()
{
	asm("leave");
	asm("mov $0x080e51bc, %eax");
	asm("jmp %eax");
}

int CNWSCombatRound::GetSpecialAttackID(int)
{
	asm("leave");
	asm("mov $0x080e2808, %eax");
	asm("jmp %eax");
}

int CNWSCombatRound::GetSpecialAttack(int)
{
	asm("leave");
	asm("mov $0x080e2760, %eax");
	asm("jmp %eax");
}

int CNWSCombatRound::GetSpellActionPending()
{
	asm("leave");
	asm("mov $0x080e5010, %eax");
	asm("jmp %eax");
}

int CNWSCombatRound::GetTotalAttacks()
{
	asm("leave");
	asm("mov $0x080e5534, %eax");
	asm("jmp %eax");
}

int CNWSCombatRound::GetWeaponAttackType()
{
	asm("leave");
	asm("mov $0x080e38dc, %eax");
	asm("jmp %eax");
}

int CNWSCombatRound::HasCreatureWeapons()
{
	asm("leave");
	asm("mov $0x080e3b30, %eax");
	asm("jmp %eax");
}

int CNWSCombatRound::IncrementTimer(int)
{
	asm("leave");
	asm("mov $0x080e4d7c, %eax");
	asm("jmp %eax");
}

int CNWSCombatRound::InitializeAttackActions(unsigned long)
{
	asm("leave");
	asm("mov $0x080e1e88, %eax");
	asm("jmp %eax");
}

int CNWSCombatRound::InitializeCombatModes()
{
	asm("leave");
	asm("mov $0x080e52a0, %eax");
	asm("jmp %eax");
}

int CNWSCombatRound::InitializeNumberOfAttacks()
{
	asm("leave");
	asm("mov $0x080e2260, %eax");
	asm("jmp %eax");
}

int CNWSCombatRound::InsertSpecialAttack(unsigned short, int)
{
	asm("leave");
	asm("mov $0x080e2900, %eax");
	asm("jmp %eax");
}

int CNWSCombatRound::LoadCombatRound(CResGFF *, CResStruct *)
{
	asm("leave");
	asm("mov $0x080e4340, %eax");
	asm("jmp %eax");
}

int CNWSCombatRound::RecomputeRound()
{
	asm("leave");
	asm("mov $0x080e1390, %eax");
	asm("jmp %eax");
}

int CNWSCombatRound::RemoveAllActions()
{
	asm("leave");
	asm("mov $0x080e516c, %eax");
	asm("jmp %eax");
}

int CNWSCombatRound::RemoveSpecialAttack(int)
{
	asm("leave");
	asm("mov $0x080e25b8, %eax");
	asm("jmp %eax");
}

int CNWSCombatRound::RemoveSpellAction()
{
	asm("leave");
	asm("mov $0x080e541c, %eax");
	asm("jmp %eax");
}

int CNWSCombatRound::SaveCombatRound(CResGFF *, CResStruct *)
{
	asm("leave");
	asm("mov $0x080e3d68, %eax");
	asm("jmp %eax");
}

int CNWSCombatRound::SetCurrentAttack(unsigned char)
{
	asm("leave");
	asm("mov $0x080e524c, %eax");
	asm("jmp %eax");
}

int CNWSCombatRound::SetDeflectArrow(int)
{
	asm("leave");
	asm("mov $0x080e5560, %eax");
	asm("jmp %eax");
}

int CNWSCombatRound::SetPauseTimer(int, int)
{
	asm("leave");
	asm("mov $0x080e4e78, %eax");
	asm("jmp %eax");
}

int CNWSCombatRound::SetRoundPaused(int, unsigned long)
{
	asm("leave");
	asm("mov $0x080e4df8, %eax");
	asm("jmp %eax");
}

int CNWSCombatRound::SignalCombatRoundStarted()
{
	asm("leave");
	asm("mov $0x080e4d30, %eax");
	asm("jmp %eax");
}

int CNWSCombatRound::StartCombatRoundCast(unsigned long)
{
	asm("leave");
	asm("mov $0x080e180c, %eax");
	asm("jmp %eax");
}

int CNWSCombatRound::StartCombatRound(unsigned long)
{
	asm("leave");
	asm("mov $0x080e11e8, %eax");
	asm("jmp %eax");
}

int CNWSCombatRound::UpdateAttackTargetForAllActions(unsigned long)
{
	asm("leave");
	asm("mov $0x080e54c0, %eax");
	asm("jmp %eax");
}

