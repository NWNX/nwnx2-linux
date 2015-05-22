#include "CNWVirtualMachineCommands.h"

void * CNWVirtualMachineCommands::CopyGameDefinedStructure(int, void *)
{
    asm("leave");
    asm("mov $0x081fb82c, %eax");
    asm("jmp *%eax");
}

void * CNWVirtualMachineCommands::CreateGameDefinedStructure(int)
{
    asm("leave");
    asm("mov $0x081fbc2c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::DebugGUIGetMessageFrom(char **, int *)
{
    asm("leave");
    asm("mov $0x08231c8c, %eax");
    asm("jmp *%eax");
}

void CNWVirtualMachineCommands::DebugGUISendMessageTo(char *, int)
{
    asm("leave");
    asm("mov $0x08231c5c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::DebugGUIStart()
{
    asm("leave");
    asm("mov $0x081fd150, %eax");
    asm("jmp *%eax");
}

void CNWVirtualMachineCommands::DebugGUIStop()
{
    asm("leave");
    asm("mov $0x08231c2c, %eax");
    asm("jmp *%eax");
}

void CNWVirtualMachineCommands::DebugGUIUpdate()
{
    asm("leave");
    asm("mov $0x08231cec, %eax");
    asm("jmp *%eax");
}

void CNWVirtualMachineCommands::DestroyGameDefinedStructure(int, void *)
{
    asm("leave");
    asm("mov $0x08231b28, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandActionCounterSpell(int, int)
{
    asm("leave");
    asm("mov $0x08235484, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandActionDoCommand(int, int)
{
    asm("leave");
    asm("mov $0x082331e8, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandActionEquipMostDamagingMelee(int, int)
{
    asm("leave");
    asm("mov $0x08233e0c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandActionEquipMostDamagingRanged(int, int)
{
    asm("leave");
    asm("mov $0x08233e98, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandActionEquipMostEffectiveArmor(int, int)
{
    asm("leave");
    asm("mov $0x08233f7c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandActionExamine(int, int)
{
    asm("leave");
    asm("mov $0x08235fd4, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandActionExchangeItem(int, int)
{
    asm("leave");
    asm("mov $0x082113b8, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandActionFollowObject(int, int)
{
    asm("leave");
    asm("mov $0x0820ab20, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandActionInteractObject(int, int)
{
    asm("leave");
    asm("mov $0x08233690, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandActionJumpToObject(int, int)
{
    asm("leave");
    asm("mov $0x081ff804, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandActionJumpToPoint(int, int)
{
    asm("leave");
    asm("mov $0x081ff91c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandActionLockActions(int, int)
{
    asm("leave");
    asm("mov $0x082346d4, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandActionMoveAwayFromLocation(int, int)
{
    asm("leave");
    asm("mov $0x08215bfc, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandActionPauseConversation(int, int)
{
    asm("leave");
    asm("mov $0x08232c00, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandActionRandomWalk(int, int)
{
    asm("leave");
    asm("mov $0x081fe9b4, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandActionRest(int, int)
{
    asm("leave");
    asm("mov $0x08233f08, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandActionResumeConversation(int, int)
{
    asm("leave");
    asm("mov $0x08232c90, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandActionSit(int, int)
{
    asm("leave");
    asm("mov $0x08234eec, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandActionStartConversation(int, int)
{
    asm("leave");
    asm("mov $0x0820d030, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandActionUseFeat(int, int)
{
    asm("leave");
    asm("mov $0x08212b6c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandActionUseSkill(int, int)
{
    asm("leave");
    asm("mov $0x08212c4c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandActionUseTalent(int, int)
{
    asm("leave");
    asm("mov $0x08213738, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandActivatePortal(int, int)
{
    asm("leave");
    asm("mov $0x08219f08, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandAddItemProperty(int, int)
{
    asm("leave");
    asm("mov $0x08226fc4, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandAddJournalQuestEntry(int, int)
{
    asm("leave");
    asm("mov $0x082164b0, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandAddToParty(int, int)
{
    asm("leave");
    asm("mov $0x0821f21c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandAdjustAlignment(int, int)
{
    asm("leave");
    asm("mov $0x08211d3c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandAdjustReputation(int, int)
{
    asm("leave");
    asm("mov $0x0820d628, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandAmbientSound(int, int)
{
    asm("leave");
    asm("mov $0x082193a0, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandApplyEffectAtPoint(int, int)
{
    asm("leave");
    asm("mov $0x0820da10, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandApplyEffectOnObject(int, int)
{
    asm("leave");
    asm("mov $0x0820db94, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandAssignCommand(int, int)
{
    asm("leave");
    asm("mov $0x081fdc8c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandAssociateAccess(int, int)
{
    asm("leave");
    asm("mov $0x08216330, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandAttack(int, int)
{
    asm("leave");
    asm("mov $0x082321e8, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandBeginConversation(int, int)
{
    asm("leave");
    asm("mov $0x08210150, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandBlackScreen(int, int)
{
    asm("leave");
    asm("mov $0x08235a9c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandBootPC(int, int)
{
    asm("leave");
    asm("mov $0x08235404, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandCastSpell(int, int)
{
    asm("leave");
    asm("mov $0x081fed80, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandChangeFaction(int, int)
{
    asm("leave");
    asm("mov $0x0820b704, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandClearAllActions(int, int)
{
    asm("leave");
    asm("mov $0x081fdf94, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandCloseDoor(int, int)
{
    asm("leave");
    asm("mov $0x08203304, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandCopyItemAndModify(int, int)
{
    asm("leave");
    asm("mov $0x0821ffe8, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandCopyItem(int, int)
{
    asm("leave");
    asm("mov $0x0821fcb0, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandCopyObject(int, int)
{
    asm("leave");
    asm("mov $0x08229e4c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandCreateItemOnObject(int, int)
{
    asm("leave");
    asm("mov $0x082007e4, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandCreateObject(int, int)
{
    asm("leave");
    asm("mov $0x0820e908, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandCreateTrapAtLocation(int, int)
{
    asm("leave");
    asm("mov $0x0822e05c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandCreateTrapOnObject(int, int)
{
    asm("leave");
    asm("mov $0x0822eaa0, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandDayNightCycle(int, int)
{
    asm("leave");
    asm("mov $0x0822b548, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandDecrementFeatUses(int, int)
{
    asm("leave");
    asm("mov $0x0821f584, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandDecrementSpellUses(int, int)
{
    asm("leave");
    asm("mov $0x0821f650, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandDelayCommand(int, int)
{
    asm("leave");
    asm("mov $0x081fdd44, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandDeleteCampaignVariable(int, int)
{
    asm("leave");
    asm("mov $0x08224dc4, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandDeleteVar(int, int)
{
    asm("leave");
    asm("mov $0x082115c4, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandDestroyCampaignDatabase(int, int)
{
    asm("leave");
    asm("mov $0x08222b94, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandDestroyObject(int, int)
{
    asm("leave");
    asm("mov $0x0820e84c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandDistanceConversions(int, int)
{
    asm("leave");
    asm("mov $0x08232e98, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandDoDoorAction(int, int)
{
    asm("leave");
    asm("mov $0x082146b0, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandDoSinglePlayerAutoSave(int, int)
{
    asm("leave");
    asm("mov $0x0821cd90, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandDoTouchAttack(int, int)
{
    asm("leave");
    asm("mov $0x08209e94, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandDoWhirlwindAttack(int, int)
{
    asm("leave");
    asm("mov $0x08229460, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEffectACDecrease(int, int)
{
    asm("leave");
    asm("mov $0x08207548, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEffectACIncrease(int, int)
{
    asm("leave");
    asm("mov $0x082073b8, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEffectAbilityDecrease(int, int)
{
    asm("leave");
    asm("mov $0x0820579c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEffectAbilityIncrease(int, int)
{
    asm("leave");
    asm("mov $0x08205654, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEffectAppear(int, int)
{
    asm("leave");
    asm("mov $0x0821b304, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEffectAreaEffect(int, int)
{
    asm("leave");
    asm("mov $0x0820b27c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEffectAttackDecrease(int, int)
{
    asm("leave");
    asm("mov $0x08207c34, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEffectAttackIncrease(int, int)
{
    asm("leave");
    asm("mov $0x08207adc, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEffectBeam(int, int)
{
    asm("leave");
    asm("mov $0x0820d2a4, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEffectBlindness(int, int)
{
    asm("leave");
    asm("mov $0x0821b038, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEffectComplex(int, int)
{
    asm("leave");
    asm("mov $0x082092fc, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEffectConcealment(int, int)
{
    asm("leave");
    asm("mov $0x0821abac, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEffectCutsceneGhost(int, int)
{
    asm("leave");
    asm("mov $0x08236598, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEffectDamageDecrease(int, int)
{
    asm("leave");
    asm("mov $0x082080a0, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEffectDamageImmunityDecrease(int, int)
{
    asm("leave");
    asm("mov $0x082124d8, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEffectDamageImmunityIncrease(int, int)
{
    asm("leave");
    asm("mov $0x082123a8, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEffectDamageIncrease(int, int)
{
    asm("leave");
    asm("mov $0x08207f18, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEffectDamageReduction(int, int)
{
    asm("leave");
    asm("mov $0x08207d8c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEffectDamageResistance(int, int)
{
    asm("leave");
    asm("mov $0x0820717c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEffectDamageShield(int, int)
{
    asm("leave");
    asm("mov $0x0821b86c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEffectDamage(int, int)
{
    asm("leave");
    asm("mov $0x08205458, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEffectDarkness(int, int)
{
    asm("leave");
    asm("mov $0x0821ad04, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEffectDisappearAppear(int, int)
{
    asm("leave");
    asm("mov $0x0821b0e8, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEffectDisappear(int, int)
{
    asm("leave");
    asm("mov $0x0821b22c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEffectDisease(int, int)
{
    asm("leave");
    asm("mov $0x08210078, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEffectEthereal(int, int)
{
    asm("leave");
    asm("mov $0x08229d6c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEffectHeal(int, int)
{
    asm("leave");
    asm("mov $0x08205318, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEffectHitPointChangeWhenDying(int, int)
{
    asm("leave");
    asm("mov $0x08218534, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEffectImmunity(int, int)
{
    asm("leave");
    asm("mov $0x08211ef4, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEffectInvisibility(int, int)
{
    asm("leave");
    asm("mov $0x0821a584, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEffectLinkEffects(int, int)
{
    asm("leave");
    asm("mov $0x0821148c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEffectMissChance(int, int)
{
    asm("leave");
    asm("mov $0x0821ae4c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEffectModifyAttacks(int, int)
{
    asm("leave");
    asm("mov $0x0821b3dc, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEffectMovementSpeedDecrease(int, int)
{
    asm("leave");
    asm("mov $0x0820a94c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEffectMovementSpeedIncrease(int, int)
{
    asm("leave");
    asm("mov $0x0820a830, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEffectNegativeLevel(int, int)
{
    asm("leave");
    asm("mov $0x0821b734, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEffectPetrify(int, int)
{
    asm("leave");
    asm("mov $0x0821fbcc, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEffectPoison(int, int)
{
    asm("leave");
    asm("mov $0x0820ffa0, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEffectResurrection(int, int)
{
    asm("leave");
    asm("mov $0x082058e4, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEffectSanctuary(int, int)
{
    asm("leave");
    asm("mov $0x0821a440, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEffectSavingThrowDecrease(int, int)
{
    asm("leave");
    asm("mov $0x08207958, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEffectSavingThrowIncrease(int, int)
{
    asm("leave");
    asm("mov $0x082077d4, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEffectSeeInvisible(int, int)
{
    asm("leave");
    asm("mov $0x0821af94, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEffectSkillDecrease(int, int)
{
    asm("leave");
    asm("mov $0x082161bc, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEffectSkillIncrease(int, int)
{
    asm("leave");
    asm("mov $0x08216048, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEffectSpellFailure(int, int)
{
    asm("leave");
    asm("mov $0x08228b10, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEffectSpellImmunity(int, int)
{
    asm("leave");
    asm("mov $0x0821b4cc, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEffectSpellLevelAbsorption(int, int)
{
    asm("leave");
    asm("mov $0x0821b5cc, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEffectSpellResistanceDecrease(int, int)
{
    asm("leave");
    asm("mov $0x0820d7d8, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEffectSpellResistanceIncrease(int, int)
{
    asm("leave");
    asm("mov $0x0820d700, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEffectSummonCreature(int, int)
{
    asm("leave");
    asm("mov $0x082059bc, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEffectSwarm(int, int)
{
    asm("leave");
    asm("mov $0x0821c878, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEffectTemporaryHP(int, int)
{
    asm("leave");
    asm("mov $0x082139e0, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEffectTrueSeeing(int, int)
{
    asm("leave");
    asm("mov $0x0821ada8, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEffectTurnResistance(int, int)
{
    asm("leave");
    asm("mov $0x0821e8e4, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEffectUltravision(int, int)
{
    asm("leave");
    asm("mov $0x0821ce58, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEffectVisualEffect(int, int)
{
    asm("leave");
    asm("mov $0x0820bd38, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEndGame(int, int)
{
    asm("leave");
    asm("mov $0x08234da8, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEquipItem(int, int)
{
    asm("leave");
    asm("mov $0x082010a8, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEventActivateItem(int, int)
{
    asm("leave");
    asm("mov $0x0821907c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEventConversation(int, int)
{
    asm("leave");
    asm("mov $0x08233264, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEventSpellCastAt(int, int)
{
    asm("leave");
    asm("mov $0x0820f85c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandEventUserDefined(int, int)
{
    asm("leave");
    asm("mov $0x082099ec, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandExecuteScript(int, int)
{
    asm("leave");
    asm("mov $0x081fde94, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandExploreAreaForPlayer(int, int)
{
    asm("leave");
    asm("mov $0x08218e40, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandExportAllCharacters(int, int)
{
    asm("leave");
    asm("mov $0x082351d8, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandExportSingleCharacter(int, int)
{
    asm("leave");
    asm("mov $0x082351f4, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandFindSubString(int, int)
{
    asm("leave");
    asm("mov $0x08204eb8, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandFloatToInt(int, int)
{
    asm("leave");
    asm("mov $0x08232f7c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandFloatToString(int, int)
{
    asm("leave");
    asm("mov $0x0820a368, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandFloatingText(int, int)
{
    asm("leave");
    asm("mov $0x0821d6ac, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandForceRest(int, int)
{
    asm("leave");
    asm("mov $0x0822bdac, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGet2DAString(int, int)
{
    asm("leave");
    asm("mov $0x08229a7c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetAC(int, int)
{
    asm("leave");
    asm("mov $0x082076d8, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetAILevel(int, int)
{
    asm("leave");
    asm("mov $0x08235dd4, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetAOEObjectCreator(int, int)
{
    asm("leave");
    asm("mov $0x08211794, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetAbilityModifier(int, int)
{
    asm("leave");
    asm("mov $0x082142f0, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetAbilityScore(int, int)
{
    asm("leave");
    asm("mov $0x08211844, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetActionMode(int, int)
{
    asm("leave");
    asm("mov $0x081fe228, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetAge(int, int)
{
    asm("leave");
    asm("mov $0x0823486c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetAlignment(int, int)
{
    asm("leave");
    asm("mov $0x08208228, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetAnimalCompanionCreatureType(int, int)
{
    asm("leave");
    asm("mov $0x082349d8, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetAnimalCompanionName(int, int)
{
    asm("leave");
    asm("mov $0x0821c59c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetAppearanceType(int, int)
{
    asm("leave");
    asm("mov $0x0821f4ac, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetArcaneSpellFailure(int, int)
{
    asm("leave");
    asm("mov $0x0822b3f0, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetAreaSize(int, int)
{
    asm("leave");
    asm("mov $0x0822f948, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetArea(int, int)
{
    asm("leave");
    asm("mov $0x081fffb4, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetAssociateType(int, int)
{
    asm("leave");
    asm("mov $0x082363c0, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetAssociate(int, int)
{
    asm("leave");
    asm("mov $0x08215f58, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetAttackTarget(int, int)
{
    asm("leave");
    asm("mov $0x08233400, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetAttemptedAttackTarget(int, int)
{
    asm("leave");
    asm("mov $0x08233b64, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetAttemptedSpellTarget(int, int)
{
    asm("leave");
    asm("mov $0x08233bbc, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetBaseAttackBonus(int, int)
{
    asm("leave");
    asm("mov $0x08235b00, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetBaseItemType(int, int)
{
    asm("leave");
    asm("mov $0x08233d98, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetBattleTrack(int, int)
{
    asm("leave");
    asm("mov $0x082354dc, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetBlockingDoor(int, int)
{
    asm("leave");
    asm("mov $0x08233858, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetCalendarDay(int, int)
{
    asm("leave");
    asm("mov $0x08231e24, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetCalendarMonth(int, int)
{
    asm("leave");
    asm("mov $0x08231dc4, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetCalendarYear(int, int)
{
    asm("leave");
    asm("mov $0x08231d64, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetCampaignFloat(int, int)
{
    asm("leave");
    asm("mov $0x08222c80, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetCampaignInt(int, int)
{
    asm("leave");
    asm("mov $0x082232ac, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetCampaignLocation(int, int)
{
    asm("leave");
    asm("mov $0x08223f50, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetCampaignString(int, int)
{
    asm("leave");
    asm("mov $0x082246b8, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetCampaignVector(int, int)
{
    asm("leave");
    asm("mov $0x082238cc, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetCasterLevel(int, int)
{
    asm("leave");
    asm("mov $0x08205c40, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetChallengeRating(int, int)
{
    asm("leave");
    asm("mov $0x082347f0, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetClassInformation(int, int)
{
    asm("leave");
    asm("mov $0x08215080, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetColor(int, int)
{
    asm("leave");
    asm("mov $0x08231634, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetCommandable(int, int)
{
    asm("leave");
    asm("mov $0x08232978, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetCreatureBodyPart(int, int)
{
    asm("leave");
    asm("mov $0x0822cb90, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetCreatureHasTalent(int, int)
{
    asm("leave");
    asm("mov $0x0821349c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetCreatureSize(int, int)
{
    asm("leave");
    asm("mov $0x08234660, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetCreatureTailType(int, int)
{
    asm("leave");
    asm("mov $0x0822cf84, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetCreatureTalent(int, int)
{
    asm("leave");
    asm("mov $0x0821355c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetCreatureWingType(int, int)
{
    asm("leave");
    asm("mov $0x0822c96c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetCurrentAction(int, int)
{
    asm("leave");
    asm("mov $0x0821d320, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetCutsceneCameraMoveRate(int, int)
{
    asm("leave");
    asm("mov $0x082360dc, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetCutsceneMode(int, int)
{
    asm("leave");
    asm("mov $0x08228e3c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetDamageDealtByType(int, int)
{
    asm("leave");
    asm("mov $0x08215220, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetDayTrack(int, int)
{
    asm("leave");
    asm("mov $0x08235278, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetDeity(int, int)
{
    asm("leave");
    asm("mov $0x0821bc24, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetDescription(int, int)
{
    asm("leave");
    asm("mov $0x082302dc, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetDialogSoundLength(int, int)
{
    asm("leave");
    asm("mov $0x08228ee8, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetDistanceBetweenLocations(int, int)
{
    asm("leave");
    asm("mov $0x08212f94, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetDistanceBetween(int, int)
{
    asm("leave");
    asm("mov $0x0820a580, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetDistanceToObject(int, int)
{
    asm("leave");
    asm("mov $0x082030a0, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetDroppableFlag(int, int)
{
    asm("leave");
    asm("mov $0x08235590, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetEffectCreator(int, int)
{
    asm("leave");
    asm("mov $0x08232694, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetEffectDurationType(int, int)
{
    asm("leave");
    asm("mov $0x0823253c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetEffectSpellId(int, int)
{
    asm("leave");
    asm("mov $0x082332dc, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetEffectSubType(int, int)
{
    asm("leave");
    asm("mov $0x082325b0, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetEffectType(int, int)
{
    asm("leave");
    asm("mov $0x08232624, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetEffect(int, int)
{
    asm("leave");
    asm("mov $0x08205e54, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetEmotions(int, int)
{
    asm("leave");
    asm("mov $0x0820e1a4, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetEncounterData(int, int)
{
    asm("leave");
    asm("mov $0x0821260c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetEnteringObject(int, int)
{
    asm("leave");
    asm("mov $0x08200100, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetFacing(int, int)
{
    asm("leave");
    asm("mov $0x0820056c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetFactionAverageGoodEvilAlignment(int, int)
{
    asm("leave");
    asm("mov $0x0820c38c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetFactionAverageLawChaosAlignment(int, int)
{
    asm("leave");
    asm("mov $0x0820c440, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetFactionAverageLevel(int, int)
{
    asm("leave");
    asm("mov $0x0820c4f4, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetFactionAverageReputation(int, int)
{
    asm("leave");
    asm("mov $0x0820c2bc, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetFactionAverageXP(int, int)
{
    asm("leave");
    asm("mov $0x0820c5a8, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetFactionBestAC(int, int)
{
    asm("leave");
    asm("mov $0x0820c7f4, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetFactionEqual(int, int)
{
    asm("leave");
    asm("mov $0x0820b654, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetFactionGold(int, int)
{
    asm("leave");
    asm("mov $0x0820c208, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetFactionLeader(int, int)
{
    asm("leave");
    asm("mov $0x08235368, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetFactionLeastDamagedMember(int, int)
{
    asm("leave");
    asm("mov $0x0820c124, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetFactionMember(int, int)
{
    asm("leave");
    asm("mov $0x082182cc, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetFactionMostDamagedMember(int, int)
{
    asm("leave");
    asm("mov $0x0820c040, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetFactionMostFrequentClass(int, int)
{
    asm("leave");
    asm("mov $0x0820c65c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetFactionNthNearestMember(int, int)
{
    asm("leave");
    asm("mov $0x08232bf8, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetFactionStrongestMember(int, int)
{
    asm("leave");
    asm("mov $0x0820bf5c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetFactionWeakestMember(int, int)
{
    asm("leave");
    asm("mov $0x0820be78, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetFactionWorstAC(int, int)
{
    asm("leave");
    asm("mov $0x0820c710, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetFamiliarCreatureType(int, int)
{
    asm("leave");
    asm("mov $0x0823495c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetFamiliarName(int, int)
{
    asm("leave");
    asm("mov $0x0821c44c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetFogAmount(int, int)
{
    asm("leave");
    asm("mov $0x0822c600, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetFogColor(int, int)
{
    asm("leave");
    asm("mov $0x0822c308, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetFootstepType(int, int)
{
    asm("leave");
    asm("mov $0x0822c750, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetFortitudeSavingThrow(int, int)
{
    asm("leave");
    asm("mov $0x0821c14c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetGameDifficulty(int, int)
{
    asm("leave");
    asm("mov $0x08234e64, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetGoingToBeAttackedBy(int, int)
{
    asm("leave");
    asm("mov $0x08234fb8, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetGoldPieceValue(int, int)
{
    asm("leave");
    asm("mov $0x08233348, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetGold(int, int)
{
    asm("leave");
    asm("mov $0x08218f18, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetHardness(int, int)
{
    asm("leave");
    asm("mov $0x0822d1a8, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetHasFeatEffect(int, int)
{
    asm("leave");
    asm("mov $0x0821e74c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetHasFeat(int, int)
{
    asm("leave");
    asm("mov $0x08212874, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetHasInventory(int, int)
{
    asm("leave");
    asm("mov $0x0821f130, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetHasSkill(int, int)
{
    asm("leave");
    asm("mov $0x08212984, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetHasSpellEffect(int, int)
{
    asm("leave");
    asm("mov $0x082133dc, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetHasSpell(int, int)
{
    asm("leave");
    asm("mov $0x08217e70, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetHenchman(int, int)
{
    asm("leave");
    asm("mov $0x08215688, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetHitDice(int, int)
{
    asm("leave");
    asm("mov $0x0820aa68, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetHitpoints(int, int)
{
    asm("leave");
    asm("mov $0x08203b60, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetIdentified(int, int)
{
    asm("leave");
    asm("mov $0x08233704, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetImmortal(int, int)
{
    asm("leave");
    asm("mov $0x08235d64, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetInPersistentObject(int, int)
{
    asm("leave");
    asm("mov $0x08210850, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetInfiniteFlag(int, int)
{
    asm("leave");
    asm("mov $0x082369b0, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetInventoryDisturbItem(int, int)
{
    asm("leave");
    asm("mov $0x082339e8, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetInventoryDisturbType(int, int)
{
    asm("leave");
    asm("mov $0x08233964, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetIsAreaAboveGround(int, int)
{
    asm("leave");
    asm("mov $0x08234c6c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetIsAreaInterior(int, int)
{
    asm("leave");
    asm("mov $0x08235ebc, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetIsAreaNatural(int, int)
{
    asm("leave");
    asm("mov $0x08234bec, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetIsCreatureDisarmable(int, int)
{
    asm("leave");
    asm("mov $0x0822bcf8, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetIsDMPossessed(int, int)
{
    asm("leave");
    asm("mov $0x08232e10, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetIsDawn(int, int)
{
    asm("leave");
    asm("mov $0x08234060, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetIsDay(int, int)
{
    asm("leave");
    asm("mov $0x08233fb0, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetIsDoorActionPossible(int, int)
{
    asm("leave");
    asm("mov $0x082143ec, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetIsDusk(int, int)
{
    asm("leave");
    asm("mov $0x082340b8, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetIsEncounterCreature(int, int)
{
    asm("leave");
    asm("mov $0x08234110, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetIsImmune(int, int)
{
    asm("leave");
    asm("mov $0x08211ff4, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetIsInCombat(int, int)
{
    asm("leave");
    asm("mov $0x082334ec, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetIsInTrigger(int, int)
{
    asm("leave");
    asm("mov $0x0822bc58, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetIsNight(int, int)
{
    asm("leave");
    asm("mov $0x08234008, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetIsOpen(int, int)
{
    asm("leave");
    asm("mov $0x08219708, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetIsPossessedFamiliar(int, int)
{
    asm("leave");
    asm("mov $0x08235e40, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetIsRacialTypePlayable(int, int)
{
    asm("leave");
    asm("mov $0x082138dc, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetIsReactionType(int, int)
{
    asm("leave");
    asm("mov $0x08219de8, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetIsResting(int, int)
{
    asm("leave");
    asm("mov $0x08234a54, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetIsSkillSuccessful(int, int)
{
    asm("leave");
    asm("mov $0x082286d4, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetIsTalentValid(int, int)
{
    asm("leave");
    asm("mov $0x08233af4, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetIsTrapped(int, int)
{
    asm("leave");
    asm("mov $0x0821e80c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetIsWeaponEffective(int, int)
{
    asm("leave");
    asm("mov $0x08234330, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetItemACValue(int, int)
{
    asm("leave");
    asm("mov $0x08218d94, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetItemAppearance(int, int)
{
    asm("leave");
    asm("mov $0x0822098c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetItemCharges(int, int)
{
    asm("leave");
    asm("mov $0x0823582c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetItemCursedFlag(int, int)
{
    asm("leave");
    asm("mov $0x082361f0, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetItemHasItemProperty(int, int)
{
    asm("leave");
    asm("mov $0x08218ca4, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetItemInInventory(int, int)
{
    asm("leave");
    asm("mov $0x082149b4, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetItemInSlot(int, int)
{
    asm("leave");
    asm("mov $0x0820a698, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetItemPossessedBy(int, int)
{
    asm("leave");
    asm("mov $0x08200cc8, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetItemPossessor(int, int)
{
    asm("leave");
    asm("mov $0x082006cc, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetItemPropertyDurationType(int, int)
{
    asm("leave");
    asm("mov $0x082359a8, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetItemPropertyInfo(int, int)
{
    asm("leave");
    asm("mov $0x082275dc, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetItemPropertyType(int, int)
{
    asm("leave");
    asm("mov $0x0823591c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetItemProperty(int, int)
{
    asm("leave");
    asm("mov $0x08227378, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetItemStackSize(int, int)
{
    asm("leave");
    asm("mov $0x082357b8, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetJournalQuestExperience(int, int)
{
    asm("leave");
    asm("mov $0x08217b94, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetKeyRequiredFeedbackMessage(int, int)
{
    asm("leave");
    asm("mov $0x0822f4cc, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetLastAssociateCommand(int, int)
{
    asm("leave");
    asm("mov $0x0823355c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetLastAttackMode(int, int)
{
    asm("leave");
    asm("mov $0x08213c84, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetLastAttackType(int, int)
{
    asm("leave");
    asm("mov $0x08213b0c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetLastAttacker(int, int)
{
    asm("leave");
    asm("mov $0x08232144, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetLastClosedBy(int, int)
{
    asm("leave");
    asm("mov $0x0821edcc, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetLastDamager(int, int)
{
    asm("leave");
    asm("mov $0x082338b0, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetLastDisarmed(int, int)
{
    asm("leave");
    asm("mov $0x082153a4, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetLastDisturbed(int, int)
{
    asm("leave");
    asm("mov $0x08215474, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetLastEquipped(int, int)
{
    asm("leave");
    asm("mov $0x08235f3c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetLastHostileActor(int, int)
{
    asm("leave");
    asm("mov $0x0821e9e0, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetLastKiller(int, int)
{
    asm("leave");
    asm("mov $0x082343cc, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetLastLocked(int, int)
{
    asm("leave");
    asm("mov $0x08215520, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetLastOpenedBy(int, int)
{
    asm("leave");
    asm("mov $0x08214224, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetLastPCRested(int, int)
{
    asm("leave");
    asm("mov $0x08234ad0, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetLastPerceived(int, int)
{
    asm("leave");
    asm("mov $0x0823315c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetLastPerception(int, int)
{
    asm("leave");
    asm("mov $0x0821055c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetLastRestEventType(int, int)
{
    asm("leave");
    asm("mov $0x08234b24, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetLastSpeaker(int, int)
{
    asm("leave");
    asm("mov $0x082330cc, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetLastSpellCastClass(int, int)
{
    asm("leave");
    asm("mov $0x0822b8e4, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetLastTrapDetected(int, int)
{
    asm("leave");
    asm("mov $0x0823477c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetLastUnlocked(int, int)
{
    asm("leave");
    asm("mov $0x082155d4, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetLastUsedBy(int, int)
{
    asm("leave");
    asm("mov $0x0821415c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetLastWeaponUsed(int, int)
{
    asm("leave");
    asm("mov $0x0823361c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetLeavingObject(int, int)
{
    asm("leave");
    asm("mov $0x08200230, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetLocation(int, int)
{
    asm("leave");
    asm("mov $0x08200420, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetLockInfo(int, int)
{
    asm("leave");
    asm("mov $0x0821e488, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetLocked(int, int)
{
    asm("leave");
    asm("mov $0x08214080, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetLootable(int, int)
{
    asm("leave");
    asm("mov $0x08236068, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetMaster(int, int)
{
    asm("leave");
    asm("mov $0x08233474, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetMatchedString(int, int)
{
    asm("leave");
    asm("mov $0x0820bbac, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetMatchedStringsCount(int, int)
{
    asm("leave");
    asm("mov $0x08232b18, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetMatchedStringsNum(int, int)
{
    asm("leave");
    asm("mov $0x08232b88, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetMaxHenchmen(int, int)
{
    asm("leave");
    asm("mov $0x0823636c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetMetaMagicFeat(int, int)
{
    asm("leave");
    asm("mov $0x0823277c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetModeState(int, int)
{
    asm("leave");
    asm("mov $0x0821f3f8, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetModuleItemStuff(int, int)
{
    asm("leave");
    asm("mov $0x082127a0, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetModuleName(int, int)
{
    asm("leave");
    asm("mov $0x0821eca4, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetModule(int, int)
{
    asm("leave");
    asm("mov $0x08232fe4, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetMovementRate(int, int)
{
    asm("leave");
    asm("mov $0x082348e4, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetName(int, int)
{
    asm("leave");
    asm("mov $0x08206620, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetNearestObject(int, int)
{
    asm("leave");
    asm("mov $0x082012f0, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetNearestTrap(int, int)
{
    asm("leave");
    asm("mov $0x0821b9b8, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetNightTrack(int, int)
{
    asm("leave");
    asm("mov $0x082352f0, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetNumStackedItems(int, int)
{
    asm("leave");
    asm("mov $0x08234568, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetObjectByTag(int, int)
{
    asm("leave");
    asm("mov $0x0820cba4, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetObjectInArea(int, int)
{
    asm("leave");
    asm("mov $0x0820631c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetObjectInShape(int, int)
{
    asm("leave");
    asm("mov $0x08208338, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetObjectType(int, int)
{
    asm("leave");
    asm("mov $0x08206dc0, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetObjectValid(int, int)
{
    asm("leave");
    asm("mov $0x08232298, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetObjectVisibility(int, int)
{
    asm("leave");
    asm("mov $0x08210734, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetPCChatMessage(int, int)
{
    asm("leave");
    asm("mov $0x082312f4, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetPCChatSpeaker(int, int)
{
    asm("leave");
    asm("mov $0x08236bf8, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetPCChatVolume(int, int)
{
    asm("leave");
    asm("mov $0x082313fc, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetPCIPAddress(int, int)
{
    asm("leave");
    asm("mov $0x08217660, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetPCLevellingUp(int, int)
{
    asm("leave");
    asm("mov $0x08235030, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetPCPlayerName(int, int)
{
    asm("leave");
    asm("mov $0x082177dc, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetPCPublicCDKey(int, int)
{
    asm("leave");
    asm("mov $0x08217268, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetPCSpeaker(int, int)
{
    asm("leave");
    asm("mov $0x0820e320, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetPC(int, int)
{
    asm("leave");
    asm("mov $0x0823516c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetPhenoType(int, int)
{
    asm("leave");
    asm("mov $0x0823673c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetPickpocketableFlag(int, int)
{
    asm("leave");
    asm("mov $0x082367c4, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetPlaceableIllumination(int, int)
{
    asm("leave");
    asm("mov $0x082350f0, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetPlotFlag(int, int)
{
    asm("leave");
    asm("mov $0x082344c8, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetPortraitId(int, int)
{
    asm("leave");
    asm("mov $0x08236ac0, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetPortraitResRef(int, int)
{
    asm("leave");
    asm("mov $0x0822ff30, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetPosition(int, int)
{
    asm("leave");
    asm("mov $0x08200348, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetRacialType(int, int)
{
    asm("leave");
    asm("mov $0x08206eb0, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetReflexAdjustedDamage(int, int)
{
    asm("leave");
    asm("mov $0x08213070, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetReflexSavingThrow(int, int)
{
    asm("leave");
    asm("mov $0x0821c34c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetReputation(int, int)
{
    asm("leave");
    asm("mov $0x0820d564, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetResRef(int, int)
{
    asm("leave");
    asm("mov $0x0821fa18, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetSittingCreature(int, int)
{
    asm("leave");
    asm("mov $0x08234f44, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetSkillRank(int, int)
{
    asm("leave");
    asm("mov $0x08212a5c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetSkyBox(int, int)
{
    asm("leave");
    asm("mov $0x0822c1f8, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetSpellCast(int, int)
{
    asm("leave");
    asm("mov $0x0820f960, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetSpellCasterItem(int, int)
{
    asm("leave");
    asm("mov $0x0823444c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetSpellId(int, int)
{
    asm("leave");
    asm("mov $0x0823303c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetSpellResistance(int, int)
{
    asm("leave");
    asm("mov $0x08236440, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetSpellSaveDC(int, int)
{
    asm("leave");
    asm("mov $0x082070ac, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetSpellTargetLoc(int, int)
{
    asm("leave");
    asm("mov $0x0820dd68, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetSpellTargetObject(int, int)
{
    asm("leave");
    asm("mov $0x0823230c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetStartingPackage(int, int)
{
    asm("leave");
    asm("mov $0x0823662c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetStat(int, int)
{
    asm("leave");
    asm("mov $0x08233a70, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetStolenFlag(int, int)
{
    asm("leave");
    asm("mov $0x082356b0, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetStrByStrRef(int, int)
{
    asm("leave");
    asm("mov $0x0820e3e0, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetStrRefSoundDuration(int, int)
{
    asm("leave");
    asm("mov $0x08219cb0, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetStringLeft(int, int)
{
    asm("leave");
    asm("mov $0x082048a0, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetStringLength(int, int)
{
    asm("leave");
    asm("mov $0x082323b8, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetStringLowerCase(int, int)
{
    asm("leave");
    asm("mov $0x08204530, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetStringRight(int, int)
{
    asm("leave");
    asm("mov $0x082046bc, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetStringUpperCase(int, int)
{
    asm("leave");
    asm("mov $0x082043a4, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetSubRace(int, int)
{
    asm("leave");
    asm("mov $0x0821beb8, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetSubString(int, int)
{
    asm("leave");
    asm("mov $0x08204c80, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetTag(int, int)
{
    asm("leave");
    asm("mov $0x0820ac58, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetTileLightColor(int, int)
{
    asm("leave");
    asm("mov $0x0821d0fc, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetTimeHour(int, int)
{
    asm("leave");
    asm("mov $0x08231e84, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetTimeMillisecond(int, int)
{
    asm("leave");
    asm("mov $0x08231fa4, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetTimeMinute(int, int)
{
    asm("leave");
    asm("mov $0x08231ee4, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetTimeSecond(int, int)
{
    asm("leave");
    asm("mov $0x08231f44, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetTotalDamageDealt(int, int)
{
    asm("leave");
    asm("mov $0x082152f0, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetTrapInfo(int, int)
{
    asm("leave");
    asm("mov $0x0821d984, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetTurnResistanceHD(int, int)
{
    asm("leave");
    asm("mov $0x082345dc, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetUseableFlag(int, int)
{
    asm("leave");
    asm("mov $0x08235618, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetUserDefinedEventNumber(int, int)
{
    asm("leave");
    asm("mov $0x0820fafc, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetVar(int, int)
{
    asm("leave");
    asm("mov $0x08203c90, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetWaypointByTag(int, int)
{
    asm("leave");
    asm("mov $0x0820c8d8, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetWaypointByTrigger(int, int)
{
    asm("leave");
    asm("mov $0x0820c9f0, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetWeaponRanged(int, int)
{
    asm("leave");
    asm("mov $0x0821cd00, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetWeather(int, int)
{
    asm("leave");
    asm("mov $0x08234b74, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetWeight(int, int)
{
    asm("leave");
    asm("mov $0x082293b8, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetWillSavingThrow(int, int)
{
    asm("leave");
    asm("mov $0x0821c24c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetXPScale(int, int)
{
    asm("leave");
    asm("mov $0x082368dc, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGetXP(int, int)
{
    asm("leave");
    asm("mov $0x08218c04, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGiveGoldToCreature(int, int)
{
    asm("leave");
    asm("mov $0x08218a20, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandGiveXPToCreature(int, int)
{
    asm("leave");
    asm("mov $0x08218abc, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandIncrementRemainingFeatUses(int, int)
{
    asm("leave");
    asm("mov $0x0822b220, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandInsertString(int, int)
{
    asm("leave");
    asm("mov $0x08204a84, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandIntToFloat(int, int)
{
    asm("leave");
    asm("mov $0x08232f28, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandIntToHexString(int, int)
{
    asm("leave");
    asm("mov $0x08233cac, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandIntToString(int, int)
{
    asm("leave");
    asm("mov $0x082061fc, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandIsAIState(int, int)
{
    asm("leave");
    asm("mov $0x08209c48, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandIsDM(int, int)
{
    asm("leave");
    asm("mov $0x08232d88, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandIsEffectValid(int, int)
{
    asm("leave");
    asm("mov $0x0823249c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandIsInConversation(int, int)
{
    asm("leave");
    asm("mov $0x08219bd8, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandIsItemPropertyValid(int, int)
{
    asm("leave");
    asm("mov $0x082358a0, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandIsListening(int, int)
{
    asm("leave");
    asm("mov $0x08232a10, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandIsPC(int, int)
{
    asm("leave");
    asm("mov $0x08232d20, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandItemActivated(int, int)
{
    asm("leave");
    asm("mov $0x082194f0, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandItemPropertyEffect(int, int)
{
    asm("leave");
    asm("mov $0x082276bc, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandLevelUpHenchman(int, int)
{
    asm("leave");
    asm("mov $0x08229260, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandLineOfSight(int, int)
{
    asm("leave");
    asm("mov $0x0822b5ec, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandLocationAccess(int, int)
{
    asm("leave");
    asm("mov $0x0820df1c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandLocation(int, int)
{
    asm("leave");
    asm("mov $0x0820d8b0, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandLockCamera(int, int)
{
    asm("leave");
    asm("mov $0x0822f834, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandMath(int, int)
{
    asm("leave");
    asm("mov $0x082050c8, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandModuleAccess(int, int)
{
    asm("leave");
    asm("mov $0x08212db8, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandMoveAwayFromObject(int, int)
{
    asm("leave");
    asm("mov $0x081ffe10, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandMoveToObject(int, int)
{
    asm("leave");
    asm("mov $0x081ffb78, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandMoveToPoint(int, int)
{
    asm("leave");
    asm("mov $0x081feacc, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandMusicBackground(int, int)
{
    asm("leave");
    asm("mov $0x082191d4, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandMusicBattle(int, int)
{
    asm("leave");
    asm("mov $0x082192c8, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandObjectToString(int, int)
{
    asm("leave");
    asm("mov $0x08211c2c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandOpenDoor(int, int)
{
    asm("leave");
    asm("mov $0x08203244, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandOpenInventory(int, int)
{
    asm("leave");
    asm("mov $0x082290f8, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandOpenStore(int, int)
{
    asm("leave");
    asm("mov $0x082181a8, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandPersonalReputationAccess(int, int)
{
    asm("leave");
    asm("mov $0x08218898, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandPickUpItem(int, int)
{
    asm("leave");
    asm("mov $0x08232004, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandPlayAnimation(int, int)
{
    asm("leave");
    asm("mov $0x082027d8, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandPlaySoundByStrRef(int, int)
{
    asm("leave");
    asm("mov $0x082036a0, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandPlaySound(int, int)
{
    asm("leave");
    asm("mov $0x08203544, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandPopUpGUIPanel(int, int)
{
    asm("leave");
    asm("mov $0x08218634, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandPrintFloat(int, int)
{
    asm("leave");
    asm("mov $0x081fd844, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandPrintInteger(int, int)
{
    asm("leave");
    asm("mov $0x081fda18, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandPrintLogEntry(int, int)
{
    asm("leave");
    asm("mov $0x0821eb68, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandPrintObject(int, int)
{
    asm("leave");
    asm("mov $0x081fdad4, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandPrintString(int, int)
{
    asm("leave");
    asm("mov $0x081fd6dc, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandPrintVector(int, int)
{
    asm("leave");
    asm("mov $0x081fdb90, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandPutDownItem(int, int)
{
    asm("leave");
    asm("mov $0x08232090, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandRandomName(int, int)
{
    asm("leave");
    asm("mov $0x0820fbf0, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandRandom(int, int)
{
    asm("leave");
    asm("mov $0x08231cf4, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandRecomputeStaticLighting(int, int)
{
    asm("leave");
    asm("mov $0x08234ea4, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandRemoveEffect(int, int)
{
    asm("leave");
    asm("mov $0x0820608c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandRemoveFromParty(int, int)
{
    asm("leave");
    asm("mov $0x0821f348, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandRemoveItemProperty(int, int)
{
    asm("leave");
    asm("mov $0x082271e0, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandRemoveJournalQuestEntry(int, int)
{
    asm("leave");
    asm("mov $0x08216c88, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandResistSpell(int, int)
{
    asm("leave");
    asm("mov $0x0820ae3c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandRestoreBaseAttackBonus(int, int)
{
    asm("leave");
    asm("mov $0x08236548, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandRestoreCameraFacing(int, int)
{
    asm("leave");
    asm("mov $0x08235c6c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandRetrieveCampaignObject(int, int)
{
    asm("leave");
    asm("mov $0x08225dc8, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandRollDice(int, int)
{
    asm("leave");
    asm("mov $0x08206ce0, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSavingThrow(int, int)
{
    asm("leave");
    asm("mov $0x08206f58, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSendMessageToAllDMs(int, int)
{
    asm("leave");
    asm("mov $0x0821f01c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSendMessageToPCByStrRef(int, int)
{
    asm("leave");
    asm("mov $0x0822b088, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSendMessageToPC(int, int)
{
    asm("leave");
    asm("mov $0x0821ee98, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetAILevel(int, int)
{
    asm("leave");
    asm("mov $0x0822ae54, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetActionMode(int, int)
{
    asm("leave");
    asm("mov $0x081fe174, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetAreaTransitionBMP(int, int)
{
    asm("leave");
    asm("mov $0x0820cd98, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetAssociateListenPatterns(int, int)
{
    asm("leave");
    asm("mov $0x082335cc, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetBaseAttackBonus(int, int)
{
    asm("leave");
    asm("mov $0x082364c0, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetCalendar(int, int)
{
    asm("leave");
    asm("mov $0x081fe668, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetCameraHeight(int, int)
{
    asm("leave");
    asm("mov $0x082366ac, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetCameraLocation(int, int)
{
    asm("leave");
    asm("mov $0x082033a8, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetCameraMode(int, int)
{
    asm("leave");
    asm("mov $0x0821c6ec, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetCampaignFloat(int, int)
{
    asm("leave");
    asm("mov $0x08220b48, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetCampaignInt(int, int)
{
    asm("leave");
    asm("mov $0x0822116c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetCampaignLocation(int, int)
{
    asm("leave");
    asm("mov $0x08221dcc, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetCampaignString(int, int)
{
    asm("leave");
    asm("mov $0x082224cc, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetCampaignVector(int, int)
{
    asm("leave");
    asm("mov $0x08221790, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetColor(int, int)
{
    asm("leave");
    asm("mov $0x082317a8, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetCommandable(int, int)
{
    asm("leave");
    asm("mov $0x0820a798, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetCreatureAppearanceType(int, int)
{
    asm("leave");
    asm("mov $0x0822bafc, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetCreatureBodyPart(int, int)
{
    asm("leave");
    asm("mov $0x0822cd54, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetCreatureTailType(int, int)
{
    asm("leave");
    asm("mov $0x0822d014, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetCreatureWingType(int, int)
{
    asm("leave");
    asm("mov $0x0822c9fc, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetCustomToken(int, int)
{
    asm("leave");
    asm("mov $0x0820ceac, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetCutsceneCameraMoveRate(int, int)
{
    asm("leave");
    asm("mov $0x08236154, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetCutsceneMode(int, int)
{
    asm("leave");
    asm("mov $0x08228c14, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetDeity(int, int)
{
    asm("leave");
    asm("mov $0x0821bd74, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetDescription(int, int)
{
    asm("leave");
    asm("mov $0x08230dec, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetDislike(int, int)
{
    asm("leave");
    asm("mov $0x08217a68, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetDroppableFlag(int, int)
{
    asm("leave");
    asm("mov $0x08235cec, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetEncounterData(int, int)
{
    asm("leave");
    asm("mov $0x082126d0, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetFacing(int, int)
{
    asm("leave");
    asm("mov $0x081fe2e8, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetFade(int, int)
{
    asm("leave");
    asm("mov $0x08229018, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetFogAmount(int, int)
{
    asm("leave");
    asm("mov $0x0822c480, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetFogColor(int, int)
{
    asm("leave");
    asm("mov $0x0822c070, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetFootstepType(int, int)
{
    asm("leave");
    asm("mov $0x0822c860, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetHardness(int, int)
{
    asm("leave");
    asm("mov $0x0822d270, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetIdentified(int, int)
{
    asm("leave");
    asm("mov $0x08233778, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetImmortal(int, int)
{
    asm("leave");
    asm("mov $0x08235b84, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetInfiniteFlag(int, int)
{
    asm("leave");
    asm("mov $0x08236a38, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetIsDestroyable(int, int)
{
    asm("leave");
    asm("mov $0x08213da8, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetItemCharges(int, int)
{
    asm("leave");
    asm("mov $0x08226ef8, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetItemCursedFlag(int, int)
{
    asm("leave");
    asm("mov $0x08236278, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetItemStackSize(int, int)
{
    asm("leave");
    asm("mov $0x08226da0, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetKeyRequiredFeedbackMessage(int, int)
{
    asm("leave");
    asm("mov $0x0822f680, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetLike(int, int)
{
    asm("leave");
    asm("mov $0x0821793c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetListenString(int, int)
{
    asm("leave");
    asm("mov $0x0820b88c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetListening(int, int)
{
    asm("leave");
    asm("mov $0x08232a9c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetLockInfo(int, int)
{
    asm("leave");
    asm("mov $0x0822d5c4, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetLocked(int, int)
{
    asm("leave");
    asm("mov $0x08213f24, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetLootable(int, int)
{
    asm("leave");
    asm("mov $0x0822b494, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetMapPinEnabled(int, int)
{
    asm("leave");
    asm("mov $0x0821841c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetMaxHenchmen(int, int)
{
    asm("leave");
    asm("mov $0x082362f0, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetName(int, int)
{
    asm("leave");
    asm("mov $0x0822fa8c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetPCChatMessage(int, int)
{
    asm("leave");
    asm("mov $0x08231490, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetPCChatVolume(int, int)
{
    asm("leave");
    asm("mov $0x08231564, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetPanelButtonFlash(int, int)
{
    asm("leave");
    asm("mov $0x0821d444, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetPhenoType(int, int)
{
    asm("leave");
    asm("mov $0x0822bfc8, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetPickpocketableFlag(int, int)
{
    asm("leave");
    asm("mov $0x08236864, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetPlaceableIllumination(int, int)
{
    asm("leave");
    asm("mov $0x08235084, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetPlotFlag(int, int)
{
    asm("leave");
    asm("mov $0x08219b0c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetPortraitId(int, int)
{
    asm("leave");
    asm("mov $0x08236b64, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetPortraitResRef(int, int)
{
    asm("leave");
    asm("mov $0x08230074, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetSavingThrow(int, int)
{
    asm("leave");
    asm("mov $0x0822f2ec, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetSkyBox(int, int)
{
    asm("leave");
    asm("mov $0x0822be94, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetStolenFlag(int, int)
{
    asm("leave");
    asm("mov $0x08235738, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetSubRace(int, int)
{
    asm("leave");
    asm("mov $0x0821c008, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetSubType(int, int)
{
    asm("leave");
    asm("mov $0x082072ec, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetTileLightColor(int, int)
{
    asm("leave");
    asm("mov $0x0821cefc, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetTime(int, int)
{
    asm("leave");
    asm("mov $0x081fe864, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetTrapInfo(int, int)
{
    asm("leave");
    asm("mov $0x0822d994, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetUseableFlag(int, int)
{
    asm("leave");
    asm("mov $0x082301cc, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetVar(int, int)
{
    asm("leave");
    asm("mov $0x08203ff0, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetWeather(int, int)
{
    asm("leave");
    asm("mov $0x0821c778, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetXPScale(int, int)
{
    asm("leave");
    asm("mov $0x08236938, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSetXP(int, int)
{
    asm("leave");
    asm("mov $0x08218b60, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSignalEvent(int, int)
{
    asm("leave");
    asm("mov $0x08209a90, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSoundObjectPlay(int, int)
{
    asm("leave");
    asm("mov $0x08234190, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSoundObjectSetPosition(int, int)
{
    asm("leave");
    asm("mov $0x0823429c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSoundObjectSetVolume(int, int)
{
    asm("leave");
    asm("mov $0x08234230, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSoundObjectStop(int, int)
{
    asm("leave");
    asm("mov $0x082341e0, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSpawnScriptDebugger(int, int)
{
    asm("leave");
    asm("mov $0x08235554, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSpeakOneLinerConversation(int, int)
{
    asm("leave");
    asm("mov $0x0820267c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSpeakStrRef(int, int)
{
    asm("leave");
    asm("mov $0x0820e584, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSpeakString(int, int)
{
    asm("leave");
    asm("mov $0x08202404, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandStandardFactionReputationAccess(int, int)
{
    asm("leave");
    asm("mov $0x0821d4e4, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandStartNewModule(int, int)
{
    asm("leave");
    asm("mov $0x08234cec, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandStopFade(int, int)
{
    asm("leave");
    asm("mov $0x08235a38, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandStoreCameraFacing(int, int)
{
    asm("leave");
    asm("mov $0x08235bec, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandStoreCampaignObject(int, int)
{
    asm("leave");
    asm("mov $0x08225328, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandStoreGet(int, int)
{
    asm("leave");
    asm("mov $0x0822b990, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandStoreSet(int, int)
{
    asm("leave");
    asm("mov $0x0822ba44, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandStringConversions(int, int)
{
    asm("leave");
    asm("mov $0x0820e054, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSummonAssociate(int, int)
{
    asm("leave");
    asm("mov $0x082337e4, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandSurrenderToEnemies(int, int)
{
    asm("leave");
    asm("mov $0x0821a690, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandTakeGoldFromCreature(int, int)
{
    asm("leave");
    asm("mov $0x082197e4, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandTalentAccess(int, int)
{
    asm("leave");
    asm("mov $0x08233c14, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandTalent(int, int)
{
    asm("leave");
    asm("mov $0x08213308, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandTestString(int, int)
{
    asm("leave");
    asm("mov $0x0820b9bc, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandTimeConversions(int, int)
{
    asm("leave");
    asm("mov $0x08232804, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandUnequipItem(int, int)
{
    asm("leave");
    asm("mov $0x08201248, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandUnpossessFamiliar(int, int)
{
    asm("leave");
    asm("mov $0x0822afe4, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandVectorConversions(int, int)
{
    asm("leave");
    asm("mov $0x08209d2c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandVectorMagnitude(int, int)
{
    asm("leave");
    asm("mov $0x0823270c, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandVectorNormalize(int, int)
{
    asm("leave");
    asm("mov $0x08209b74, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandVector(int, int)
{
    asm("leave");
    asm("mov $0x082328d0, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandVersusEffect(int, int)
{
    asm("leave");
    asm("mov $0x08215740, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandVoiceChat(int, int)
{
    asm("leave");
    asm("mov $0x08218fdc, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommandWait(int, int)
{
    asm("leave");
    asm("mov $0x0820ccb4, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::ExecuteCommand(int, int)
{
    asm("leave");
    asm("mov $0x08231a34, %eax");
    asm("jmp *%eax");
}

CExoString CNWVirtualMachineCommands::GetDebuggerLabelName(int)
{
    asm("leave");
    asm("mov $0x081fbd80, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::GetEngineStructureWatchView(int, void *, int *, CExoString **, CExoString **)
{
    asm("leave");
    asm("mov $0x081fbed0, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::GetEqualGameDefinedStructure(int, void *, void *)
{
    asm("leave");
    asm("mov $0x081fbb7c, %eax");
    asm("jmp *%eax");
}

CExoString CNWVirtualMachineCommands::GetGameDefinedStructureName(int)
{
    asm("leave");
    asm("mov $0x08231bb4, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::GetObjectWatchView(unsigned long, int *, CExoString **, CExoString **)
{
    asm("leave");
    asm("mov $0x081fc5a0, %eax");
    asm("jmp *%eax");
}

C2DA * CNWVirtualMachineCommands::GetTableFromArmorPart(int)
{
    asm("leave");
    asm("mov $0x0822b2d0, %eax");
    asm("jmp *%eax");
}

void CNWVirtualMachineCommands::InitializeCommands()
{
    asm("leave");
    asm("mov $0x081f5cc4, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::LoadGameDefinedStructure(int, void **, CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x081fb9ac, %eax");
    asm("jmp *%eax");
}

void CNWVirtualMachineCommands::ReportError(CExoString &, int)
{
    asm("leave");
    asm("mov $0x081fb68c, %eax");
    asm("jmp *%eax");
}

void CNWVirtualMachineCommands::RunScriptCallback(CExoString &)
{
    asm("leave");
    asm("mov $0x081fb558, %eax");
    asm("jmp *%eax");
}

int CNWVirtualMachineCommands::SaveGameDefinedStructure(int, void *, CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x08231a90, %eax");
    asm("jmp *%eax");
}

