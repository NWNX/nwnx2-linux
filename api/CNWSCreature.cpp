#include "CNWSCreature.h"

unsigned long CNWSCreature::AIActionAnimalEmpathy(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x08108afc, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreature::AIActionAppear(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x0810a23c, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreature::AIActionAreaWait(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x08112f04, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreature::AIActionAttackObject(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x080e5928, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreature::AIActionBarter(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x080f93d8, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreature::AIActionCastSpell(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x080faba8, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreature::AIActionChangeFacingObject(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x080fd69c, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreature::AIActionChangeFacingPoint(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x080fd83c, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreature::AIActionCheckForceFollowObject(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x08112fd4, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreature::AIActionCheckInterAreaPathfinding(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x080fdeac, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreature::AIActionCheckMoveAwayFromLocation(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x080fdc8c, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreature::AIActionCheckMoveAwayFromObject(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x080fd924, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreature::AIActionCheckMoveToObjectRadius(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x080fe368, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreature::AIActionCheckMoveToObject(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x080fe128, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreature::AIActionCheckMoveToPointRadius(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x080feac0, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreature::AIActionCheckMoveToPoint(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x080fe884, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreature::AIActionCounterSpell(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x0810c250, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreature::AIActionDisappear(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x0810a318, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreature::AIActionDisarmTrap(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x080f7070, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreature::AIActionDrive(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x081052c0, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreature::AIActionDropItem(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x0810735c, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreature::AIActionEncounterCreatureDestroySelf()
{
    asm("leave");
    asm("mov $0x080fecb4, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreature::AIActionEquipItem(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x081001b8, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreature::AIActionExamineTrap(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x080f7b78, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreature::AIActionExamine(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x080f9648, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreature::AIActionFlagTrap(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x080f5d3c, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreature::AIActionForceFollowObject(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x081069c8, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreature::AIActionHeal(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x0810b3f8, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreature::AIActionItemCastSpell(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x080f9c88, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreature::AIActionJumpToObject(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x0810031c, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreature::AIActionJumpToPoint(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x08100ba4, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreature::AIActionMoveToPoint(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x08101e4c, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreature::AIActionOrientCamera(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x0811309c, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreature::AIActionPickPocket(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x0810a3f4, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreature::AIActionPickUpItem(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x08106bb0, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreature::AIActionRandomWalk(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x08101a10, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreature::AIActionRecoverTrap(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x080f63a8, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreature::AIActionRepositoryMove(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x08101194, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreature::AIActionRest(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x08109114, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreature::AIActionSetTrap(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x080f8174, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreature::AIActionSit(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x0810bddc, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreature::AIActionTaunt(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x08109bec, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreature::AIActionUnequipItem(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x08107fb4, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreature::AIActionWaitForEndOfRound(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x08113118, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::AIUpdate()
{
    asm("leave");
    asm("mov $0x08119108, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::AcquireItem(CNWSItem **, unsigned long, unsigned long, unsigned char, unsigned char, int, int)
{
    asm("leave");
    asm("mov $0x080ffe20, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ActionManager(unsigned long)
{
    asm("leave");
    asm("mov $0x0813bb24, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ActivityManager(unsigned long)
{
    asm("leave");
    asm("mov $0x0813bba0, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::AddAnimalEmpathyAction(unsigned long)
{
    asm("leave");
    asm("mov $0x0812ca18, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::AddAppearActions(int)
{
    asm("leave");
    asm("mov $0x0813c6a4, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::AddAreaOfEffect(unsigned long)
{
    asm("leave");
    asm("mov $0x0813de74, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::AddAssociate(unsigned long, unsigned short)
{
    asm("leave");
    asm("mov $0x0810c620, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::AddAttackActions(unsigned long, int, int, int)
{
    asm("leave");
    asm("mov $0x081188d4, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::AddCastSpellActions(unsigned long, int, int, int, int, Vector, unsigned long, int, int, int, unsigned char, int, int, int, unsigned char)
{
    asm("leave");
    asm("mov $0x0811610c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::AddCounterSpellActions(unsigned long)
{
    asm("leave");
    asm("mov $0x0812cbf4, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::AddDisappearActions(int, int)
{
    asm("leave");
    asm("mov $0x0812cdcc, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::AddDriveAction(unsigned short, Vector const &, int, int, int, int)
{
    asm("leave");
    asm("mov $0x0813bcf4, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::AddDropItemActions(unsigned long, Vector, int)
{
    asm("leave");
    asm("mov $0x081183ec, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::AddEquipItemActions(CNWSItem *, unsigned long, int, int, unsigned long)
{
    asm("leave");
    asm("mov $0x08116cec, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::AddGold(int, int)
{
    asm("leave");
    asm("mov $0x081317a0, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::AddHealActions(unsigned long, unsigned long, int)
{
    asm("leave");
    asm("mov $0x0811850c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::AddItemCastSpellActions(unsigned long, int, int, Vector, unsigned long, int)
{
    asm("leave");
    asm("mov $0x081159bc, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::AddMoveToPointActionToFront(unsigned short, Vector, unsigned long, unsigned long, int, float, float, int, int, int, int, int, int)
{
    asm("leave");
    asm("mov $0x0813bc08, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::AddMoveToPointAction(unsigned short, Vector, unsigned long, unsigned long, int, float, float, int, int, int, int, int, int)
{
    asm("leave");
    asm("mov $0x0813be0c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::AddPathfindingWaitActionToFront(unsigned short)
{
    asm("leave");
    asm("mov $0x0813bd88, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::AddPickPocketActions(unsigned long)
{
    asm("leave");
    asm("mov $0x08118224, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::AddPickUpItemActions(unsigned long, unsigned long, unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x08118320, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::AddRepositoryMoveActions(CNWSItem *, unsigned long, unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x0813bef8, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::AddSitActions(unsigned long)
{
    asm("leave");
    asm("mov $0x081185c8, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::AddTauntActions(unsigned long)
{
    asm("leave");
    asm("mov $0x0812cb08, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::AddToArea(CNWSArea *, float, float, float, int)
{
    asm("leave");
    asm("mov $0x08118d20, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::AddToAssociateList(unsigned long)
{
    asm("leave");
    asm("mov $0x08113254, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::AddToInvitationsIgnored(unsigned long)
{
    asm("leave");
    asm("mov $0x081136bc, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::AddToInvitationsOffered(unsigned long)
{
    asm("leave");
    asm("mov $0x081135ac, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::AddToPVPList(unsigned long)
{
    asm("leave");
    asm("mov $0x0811387c, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::AddToPersonalReputationList(unsigned long, int, int, float)
{
    asm("leave");
    asm("mov $0x0810897c, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::AddToVisibleList(unsigned long, int, int, unsigned char, int)
{
    asm("leave");
    asm("mov $0x08108824, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::AddTrapActions(unsigned long, unsigned char, unsigned long, Vector, unsigned long)
{
    asm("leave");
    asm("mov $0x081186c8, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::AddUnequipActions(CNWSItem *, unsigned long, unsigned char, unsigned char, int, int, unsigned long)
{
    asm("leave");
    asm("mov $0x081178e4, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::AddUseTalentAtLocationActions(int, int, Vector, unsigned char, unsigned long, int, unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x0812d0e8, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::AddUseTalentOnObjectActions(int, int, unsigned long, unsigned char, unsigned long, int, unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x0812ce9c, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::AdjustReputation(int, int)
{
    asm("leave");
    asm("mov $0x081083a4, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ApplyDeathExperience()
{
    asm("leave");
    asm("mov $0x0812385c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::ApplyDiseasePayload(CGameEffect *, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x08138790, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ApplyOnHitAbilityDamage(CNWSObject *, CNWItemProperty *)
{
    asm("leave");
    asm("mov $0x080f4c4c, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ApplyOnHitBlindness(CNWSObject *, int)
{
    asm("leave");
    asm("mov $0x080f19d4, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ApplyOnHitCastSpell(CNWSObject *, CNWItemProperty *, CNWSItem *)
{
    asm("leave");
    asm("mov $0x080eccf8, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ApplyOnHitConfusion(CNWSObject *, int)
{
    asm("leave");
    asm("mov $0x080f1c60, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ApplyOnHitDaze(CNWSObject *, int)
{
    asm("leave");
    asm("mov $0x080f1f58, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ApplyOnHitDeafness(CNWSObject *, int)
{
    asm("leave");
    asm("mov $0x080f2250, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ApplyOnHitDeathAttack(CNWSObject *, int)
{
    asm("leave");
    asm("mov $0x080f34d8, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ApplyOnHitDisease(CNWSObject *, CNWItemProperty *)
{
    asm("leave");
    asm("mov $0x080f4e88, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ApplyOnHitDispelMagic(CNWSObject *, CNWItemProperty *)
{
    asm("leave");
    asm("mov $0x080f4dc4, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ApplyOnHitDispelMagic(CNWSObject *, unsigned long)
{
    asm("leave");
    asm("mov $0x080f447c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::ApplyOnHitDominate(CNWSObject *, int)
{
    asm("leave");
    asm("mov $0x080f24d0, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ApplyOnHitDoom(CNWSObject *, int)
{
    asm("leave");
    asm("mov $0x080f27c8, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ApplyOnHitFear(CNWSObject *, int)
{
    asm("leave");
    asm("mov $0x080f2df0, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ApplyOnHitGreaterDispel(CNWSObject *, unsigned long)
{
    asm("leave");
    asm("mov $0x080f45f8, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ApplyOnHitHold(CNWSObject *, int)
{
    asm("leave");
    asm("mov $0x080f30d8, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ApplyOnHitKnock(CNWSObject *, unsigned long)
{
    asm("leave");
    asm("mov $0x080f4774, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ApplyOnHitLesserDispel(CNWSObject *, unsigned long)
{
    asm("leave");
    asm("mov $0x080f4954, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ApplyOnHitLevelDrain(CNWSObject *, CNWItemProperty *)
{
    asm("leave");
    asm("mov $0x080f4f48, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ApplyOnHitMordysDisjunction(CNWSObject *, unsigned long)
{
    asm("leave");
    asm("mov $0x080f4ad0, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ApplyOnHitPoison(CNWSObject *, CNWItemProperty *)
{
    asm("leave");
    asm("mov $0x080f50d0, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ApplyOnHitSilence(CNWSObject *, int)
{
    asm("leave");
    asm("mov $0x080f38e4, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ApplyOnHitSlayAlignmentGroup(CNWSObject *, CNWItemProperty *)
{
    asm("leave");
    asm("mov $0x080f54a0, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ApplyOnHitSlayAlignment(CNWSObject *, CNWItemProperty *)
{
    asm("leave");
    asm("mov $0x080f525c, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ApplyOnHitSlayRacialGroup(CNWSObject *, CNWItemProperty *)
{
    asm("leave");
    asm("mov $0x080f564c, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ApplyOnHitSleep(CNWSObject *, int)
{
    asm("leave");
    asm("mov $0x080f3b64, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ApplyOnHitSlow(CNWSObject *, int)
{
    asm("leave");
    asm("mov $0x080f3f04, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ApplyOnHitStun(CNWSObject *, int)
{
    asm("leave");
    asm("mov $0x080f4184, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ApplyOnHitVampiricRegeneration(CNWSObject *, CNWItemProperty *)
{
    asm("leave");
    asm("mov $0x080f5988, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ApplyOnHitVorpal(CNWSObject *, CNWItemProperty *)
{
    asm("leave");
    asm("mov $0x080f58c8, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ApplyOnHitWounding(CNWSObject *, CNWItemProperty *)
{
    asm("leave");
    asm("mov $0x080f57dc, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::ApplyPoisonPayload(CGameEffect *, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x08138f3c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::ApplyWounding(CGameEffect *)
{
    asm("leave");
    asm("mov $0x0813b6b4, %eax");
    asm("jmp *%eax");
}

CNWSCreature * CNWSCreature::AsNWSCreature()
{
    asm("leave");
    asm("mov $0x0813d6ac, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::AutoCloseGUIPanels(int)
{
    asm("leave");
    asm("mov $0x08135404, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::BringAssociatesToNewFaction(int)
{
    asm("leave");
    asm("mov $0x08113778, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::BroadcastAssociateCommand(int)
{
    asm("leave");
    asm("mov $0x0813c59c, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::BroadcastAttackDataToParty(CNWCCMessageData *, CNWSCombatAttackData *, CNWSCreature *)
{
    asm("leave");
    asm("mov $0x08126b58, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::BroadcastAttackOfOpportunity(unsigned long, int)
{
    asm("leave");
    asm("mov $0x08128ea8, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::BroadcastBattleCry()
{
    asm("leave");
    asm("mov $0x08128864, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::BroadcastCombatStateToParty()
{
    asm("leave");
    asm("mov $0x08128d34, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::BroadcastDamageDataToParty(CNWCCMessageData *, CNWSCreature *)
{
    asm("leave");
    asm("mov $0x08126dd4, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::BroadcastDeathDataToParty(CNWCCMessageData *, CNWSCreature *)
{
    asm("leave");
    asm("mov $0x08127014, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::BroadcastFloatyData(CNWCCMessageData *)
{
    asm("leave");
    asm("mov $0x081272dc, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::BroadcastSavingThrowData(CNWCCMessageData *)
{
    asm("leave");
    asm("mov $0x08127584, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::BroadcastSkillData(CNWCCMessageData *)
{
    asm("leave");
    asm("mov $0x0812742c, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::BroadcastSpellCast(unsigned long, unsigned char, unsigned short)
{
    asm("leave");
    asm("mov $0x08127cec, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::BroadcastVoiceChat(unsigned char)
{
    asm("leave");
    asm("mov $0x081289cc, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::BroadcastWhirlwindAttack(int)
{
    asm("leave");
    asm("mov $0x0813b55c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::BumpFriends(CNWSCreature *, Vector const &, Vector const &)
{
    asm("leave");
    asm("mov $0x0813836c, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSCreature::CalculateDamagePower(CNWSObject *, int)
{
    asm("leave");
    asm("mov $0x0812eb24, %eax");
    asm("jmp *%eax");
}

float CNWSCreature::CalculateDeathExperience(int, int)
{
    asm("leave");
    asm("mov $0x08123e0c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::CalculateMaxElementalDamage(CNWSObject *, int)
{
    asm("leave");
    asm("mov $0x080f5b14, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::CalculatePersonalReputationAdjustment(unsigned long)
{
    asm("leave");
    asm("mov $0x081121ec, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::CalculateProjectileTimeToTarget(Vector, int)
{
    asm("leave");
    asm("mov $0x080f5b98, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::CalculateSpellSaveDC(int)
{
    asm("leave");
    asm("mov $0x0813adc8, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSCreature::CanEquipItem(CNWSItem *, unsigned long *, int, int, int, CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x080ff978, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSCreature::CanEquipMiscellaneous(CNWSItem *, unsigned long *, int, int)
{
    asm("leave");
    asm("mov $0x080ff8c0, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSCreature::CanEquipShield(CNWSItem *, int, int)
{
    asm("leave");
    asm("mov $0x080ff798, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSCreature::CanEquipWeapon(CNWSItem *, unsigned long *, int, int, CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x080fed6c, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSCreature::CanUnEquipWeapon(CNWSItem *)
{
    asm("leave");
    asm("mov $0x08107e78, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::CanUseItem(CNWSItem *, int)
{
    asm("leave");
    asm("mov $0x08110df8, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::CancelAction(unsigned short, unsigned short)
{
    asm("leave");
    asm("mov $0x08124fb4, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::CancelGoldTransfer(unsigned long)
{
    asm("leave");
    asm("mov $0x0813c7d8, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::CancelRest(unsigned short)
{
    asm("leave");
    asm("mov $0x0812d888, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::CheckInventoryForPlotItems()
{
    asm("leave");
    asm("mov $0x081399c4, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::CheckItemAlignmentRestrictions(CNWSItem *)
{
    asm("leave");
    asm("mov $0x08111374, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::CheckItemClassRestrictions(CNWSItem *)
{
    asm("leave");
    asm("mov $0x08111294, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::CheckItemRaceRestrictions(CNWSItem *)
{
    asm("leave");
    asm("mov $0x08111678, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::CheckMasterIsValid(unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x08130120, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::CheckProficiencies(CNWSItem *, unsigned long)
{
    asm("leave");
    asm("mov $0x080ffcd4, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::CheckUseMagicDeviceSkill(CNWSItem *, int)
{
    asm("leave");
    asm("mov $0x0811172c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::CheckVisibleList(unsigned long)
{
    asm("leave");
    asm("mov $0x081131a8, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::CleanInvitationLists(int)
{
    asm("leave");
    asm("mov $0x08111c24, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::CleanOutPersonalReputationList()
{
    asm("leave");
    asm("mov $0x08112ab8, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::ClearAction(CNWSObjectActionNode *, int)
{
    asm("leave");
    asm("mov $0x0811bbb0, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ClearActivities(int)
{
    asm("leave");
    asm("mov $0x08115528, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::ClearAutoMapData()
{
    asm("leave");
    asm("mov $0x0813d2d8, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ClearHostileActionsVersus(CNWSCreature *)
{
    asm("leave");
    asm("mov $0x08137f50, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ClearPersonalReputation(unsigned long)
{
    asm("leave");
    asm("mov $0x08108a6c, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ClearVisibleList()
{
    asm("leave");
    asm("mov $0x081088a0, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ComputeAIStateOnAction(int, unsigned long)
{
    asm("leave");
    asm("mov $0x0811d974, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ComputeAIState()
{
    asm("leave");
    asm("mov $0x0813c184, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ComputeArmourClass(CNWSItem *, int, int)
{
    asm("leave");
    asm("mov $0x081298b0, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ComputeModifiedMovementRate()
{
    asm("leave");
    asm("mov $0x081391ac, %eax");
    asm("jmp *%eax");
}

float CNWSCreature::ComputeSpellRange(CExoString, unsigned long)
{
    asm("leave");
    asm("mov $0x08115864, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::ComputeTotalEquippedWeight()
{
    asm("leave");
    asm("mov $0x0813c054, %eax");
    asm("jmp *%eax");
}

float CNWSCreature::ComputeTotalWalkDistance()
{
    asm("leave");
    asm("mov $0x08103f60, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::ComputeTotalWeightCarried()
{
    asm("leave");
    asm("mov $0x0813c030, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ConvertModeToggleQuickButton(CNWSQuickbarButton *)
{
    asm("leave");
    asm("mov $0x0813c2dc, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::CopyQuickButtonsFromDM(CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x08123698, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::CreateDefaultQuickButtonsDM()
{
    asm("leave");
    asm("mov $0x0813c3f8, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::CreateDefaultQuickButtons_AddFeat(unsigned char &, unsigned short, int)
{
    asm("leave");
    asm("mov $0x08122f80, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::CreateDefaultQuickButtons_CheckItem(CNWSItem *, unsigned long &, unsigned long &, unsigned long &, unsigned long &)
{
    asm("leave");
    asm("mov $0x0813c388, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::CreateDefaultQuickButtons()
{
    asm("leave");
    asm("mov $0x08122494, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::CutWaypointPath()
{
    asm("leave");
    asm("mov $0x0813cf74, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::DMClearScripts(int)
{
    asm("leave");
    asm("mov $0x0810e920, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::DMResetClearedScripts(int)
{
    asm("leave");
    asm("mov $0x0810f198, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::DecrementSpellReadyCount(unsigned long, unsigned char, unsigned char, unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x0813ce5c, %eax");
    asm("jmp *%eax");
}

float CNWSCreature::DesiredAttackRange(unsigned long, int)
{
    asm("leave");
    asm("mov $0x0811d858, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::DestroyEquippedItems()
{
    asm("leave");
    asm("mov $0x0813bfcc, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::DisplayFloatyDataToSelf(unsigned long)
{
    asm("leave");
    asm("mov $0x0813a60c, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::DoCombatStep(unsigned char, int, unsigned long)
{
    asm("leave");
    asm("mov $0x080f0008, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::DoDamage(int)
{
    asm("leave");
    asm("mov $0x0812e998, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::DoListenDetection(CNWSCreature *, int)
{
    asm("leave");
    asm("mov $0x08125ddc, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::DoPerceptionUpdateOnCreature(CNWSCreature *, int)
{
    asm("leave");
    asm("mov $0x08125164, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::DoSpotDetection(CNWSCreature *, int)
{
    asm("leave");
    asm("mov $0x081265c4, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::DoStealthDetection(CNWSCreature *, int, int *, int *, int)
{
    asm("leave");
    asm("mov $0x08125bfc, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreature::DriveUpdateLocation(int)
{
    asm("leave");
    asm("mov $0x08106580, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::DumpToLog()
{
    asm("leave");
    asm("mov $0x0813a6f0, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::EquipItem(unsigned long, CNWSItem *, int, int)
{
    asm("leave");
    asm("mov $0x0811b64c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::EquipMostDamagingAmmunition(unsigned long, CNWSItem *)
{
    asm("leave");
    asm("mov $0x08130e14, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::EquipMostDamagingMeleeWeapon(unsigned long, int, int)
{
    asm("leave");
    asm("mov $0x08130418, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::EquipMostDamagingRangedWeapon(unsigned long)
{
    asm("leave");
    asm("mov $0x08130a1c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::EquipMostEffectiveArmor()
{
    asm("leave");
    asm("mov $0x081312dc, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::EvaluateLock(CNWSObject *, int)
{
    asm("leave");
    asm("mov $0x0811af4c, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::EventHandler(unsigned long, unsigned long, void *, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x0811c160, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ExternalResolveAttack(unsigned long, int)
{
    asm("leave");
    asm("mov $0x080f5c50, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::FailedOpenInformAssociates()
{
    asm("leave");
    asm("mov $0x08113820, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::ForceMoveToPoint(CNWSForcedAction *)
{
    asm("leave");
    asm("mov $0x081314c8, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetAIStateActee()
{
    asm("leave");
    asm("mov $0x0813d8b4, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetAIStateAction()
{
    asm("leave");
    asm("mov $0x0813d894, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetAIStateActivities()
{
    asm("leave");
    asm("mov $0x0813d8a4, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetAIState()
{
    asm("leave");
    asm("mov $0x0813d884, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetActionQueueList()
{
    asm("leave");
    asm("mov $0x0813eb34, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetActivityLocked(unsigned long)
{
    asm("leave");
    asm("mov $0x0813e994, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetActivity(int)
{
    asm("leave");
    asm("mov $0x0813bbf0, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetAlreadyRemovedFromEncounter()
{
    asm("leave");
    asm("mov $0x0813ec7c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetAmbientAnimationState()
{
    asm("leave");
    asm("mov $0x0813e34c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetAmmunitionAvailable(int)
{
    asm("leave");
    asm("mov $0x080e78a4, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetAnimalCompanionCreatureType()
{
    asm("leave");
    asm("mov $0x0813e4ec, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetAnimalCompanionId()
{
    asm("leave");
    asm("mov $0x0813e500, %eax");
    asm("jmp *%eax");
}

CExoString CNWSCreature::GetAnimalCompanionName()
{
    asm("leave");
    asm("mov $0x0813e4c0, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetAppearance()
{
    asm("leave");
    asm("mov $0x0813d6b4, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetAreaOfEffectObjects()
{
    asm("leave");
    asm("mov $0x0813df28, %eax");
    asm("jmp *%eax");
}

short CNWSCreature::GetArmorClass()
{
    asm("leave");
    asm("mov $0x0812e19c, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreature::GetAssociateId(unsigned short, int)
{
    asm("leave");
    asm("mov $0x0810f9b4, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetAssociateList()
{
    asm("leave");
    asm("mov $0x0813e3b8, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetAssociateType()
{
    asm("leave");
    asm("mov $0x0813e3a8, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetAttackResultHit(CNWSCombatAttackData *)
{
    asm("leave");
    asm("mov $0x080f5c24, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetAttackTarget()
{
    asm("leave");
    asm("mov $0x0813e9f0, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetAttemptedAttackTarget()
{
    asm("leave");
    asm("mov $0x0813ea14, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetAttemptedSpellTarget()
{
    asm("leave");
    asm("mov $0x0813ea38, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetAutoMapAreaList()
{
    asm("leave");
    asm("mov $0x0813ebe4, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetAutoMapTileData()
{
    asm("leave");
    asm("mov $0x0813ebd4, %eax");
    asm("jmp *%eax");
}

CNWSBarter * CNWSCreature::GetBarterInfo(int)
{
    asm("leave");
    asm("mov $0x0813c8fc, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetBlind()
{
    asm("leave");
    asm("mov $0x0813d060, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetBlindsightDistance()
{
    asm("leave");
    asm("mov $0x0813ecf0, %eax");
    asm("jmp *%eax");
}

unsigned short CNWSCreature::GetBodyBagAppearance()
{
    asm("leave");
    asm("mov $0x08139850, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetBodyBagId()
{
    asm("leave");
    asm("mov $0x0813eaec, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetBodyBag()
{
    asm("leave");
    asm("mov $0x0813efd4, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetBroadcastedAOOTo()
{
    asm("leave");
    asm("mov $0x0813e220, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetCalculateNPCWeight()
{
    asm("leave");
    asm("mov $0x0813ed48, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetCanSlayAlignment(CNWSObject *, CNWItemProperty *)
{
    asm("leave");
    asm("mov $0x080f53e0, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSCreature::GetCombatMode()
{
    asm("leave");
    asm("mov $0x0813da9c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetCombatRound()
{
    asm("leave");
    asm("mov $0x0813d6c4, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetCombatStateTimer()
{
    asm("leave");
    asm("mov $0x0813e210, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetCombatState()
{
    asm("leave");
    asm("mov $0x0813e200, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetCounterSpellTarget()
{
    asm("leave");
    asm("mov $0x0813e328, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetCreatureReputation(unsigned long, int, int)
{
    asm("leave");
    asm("mov $0x0810811c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetCreatureSize()
{
    asm("leave");
    asm("mov $0x0813db2c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetCreatureState()
{
    asm("leave");
    asm("mov $0x0813d8e8, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetCurrentItemContainer()
{
    asm("leave");
    asm("mov $0x0813dc90, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetCutsceneCameraMode()
{
    asm("leave");
    asm("mov $0x0813e01c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetCutsceneCameraMovementRateFactor()
{
    asm("leave");
    asm("mov $0x0813e064, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetCutsceneGhost()
{
    asm("leave");
    asm("mov $0x0813e040, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetDMCharacter()
{
    asm("leave");
    asm("mov $0x0813ec40, %eax");
    asm("jmp *%eax");
}

unsigned short CNWSCreature::GetDamageFlags()
{
    asm("leave");
    asm("mov $0x0813c760, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetDecayTime()
{
    asm("leave");
    asm("mov $0x0813eac8, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetDefensiveCastingMode()
{
    asm("leave");
    asm("mov $0x0813da8c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetDesiredAreaId()
{
    asm("leave");
    asm("mov $0x0813df48, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetDesiredAreaLocation()
{
    asm("leave");
    asm("mov $0x0813df6c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetDesiredAreaUpdateComplete()
{
    asm("leave");
    asm("mov $0x0813dfb0, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetDesiredCombatMode()
{
    asm("leave");
    asm("mov $0x0813daac, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSCreature::GetDetectMode()
{
    asm("leave");
    asm("mov $0x0813c850, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetDialogInterruptable()
{
    asm("leave");
    asm("mov $0x0813dcfc, %eax");
    asm("jmp *%eax");
}

CResRef CNWSCreature::GetDialogResref()
{
    asm("leave");
    asm("mov $0x0813dcb4, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetDisarmable()
{
    asm("leave");
    asm("mov $0x0813da10, %eax");
    asm("jmp *%eax");
}

CExoString CNWSCreature::GetDisplayName()
{
    asm("leave");
    asm("mov $0x0813dd7c, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreature::GetDominatedCreatureId()
{
    asm("leave");
    asm("mov $0x0811353c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetDriveModeMoveFactor()
{
    asm("leave");
    asm("mov $0x0813da00, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetDriveMode()
{
    asm("leave");
    asm("mov $0x0813e194, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetDropItemAnimationPlayed()
{
    asm("leave");
    asm("mov $0x0813d654, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetEffectIcons()
{
    asm("leave");
    asm("mov $0x0813dff8, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreature::GetEffectSpellId()
{
    asm("leave");
    asm("mov $0x0813e808, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetEncounterId()
{
    asm("leave");
    asm("mov $0x0813e79c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetEncumbranceState()
{
    asm("leave");
    asm("mov $0x0813e7c0, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetEquipArrayIndex()
{
    asm("leave");
    asm("mov $0x0813dc24, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetEquippedWeight()
{
    asm("leave");
    asm("mov $0x0813ed14, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetExternalCombatModeEnabled()
{
    asm("leave");
    asm("mov $0x0813f01c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetFacingAndAnimationDone()
{
    asm("leave");
    asm("mov $0x0813f00c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetFactionId()
{
    asm("leave");
    asm("mov $0x0813e668, %eax");
    asm("jmp *%eax");
}

CNWSFaction * CNWSCreature::GetFaction()
{
    asm("leave");
    asm("mov $0x08113178, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetFamiliarCreatureType()
{
    asm("leave");
    asm("mov $0x0813e624, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetFamiliarId()
{
    asm("leave");
    asm("mov $0x0813e638, %eax");
    asm("jmp *%eax");
}

CExoString CNWSCreature::GetFamiliarName()
{
    asm("leave");
    asm("mov $0x0813e5f8, %eax");
    asm("jmp *%eax");
}

CExoArrayList<CGameEffect *> CNWSCreature::GetFilteredEffectList(unsigned char)
{
    asm("leave");
    asm("mov $0x08131d1c, %eax");
    asm("jmp *%eax");
}

CExoLocString & CNWSCreature::GetFirstName()
{
    asm("leave");
    asm("mov $0x0813dd3c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetFlanked(CNWSCreature *)
{
    asm("leave");
    asm("mov $0x080f1928, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetFlatFooted()
{
    asm("leave");
    asm("mov $0x080f1830, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetFootstepType()
{
    asm("leave");
    asm("mov $0x0813ef84, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetForcedWalk()
{
    asm("leave");
    asm("mov $0x0813e184, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetFreeWill()
{
    asm("leave");
    asm("mov $0x0813e0e0, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSCreature::GetGender()
{
    asm("leave");
    asm("mov $0x0813dd18, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetGoingToBeAttackedBy()
{
    asm("leave");
    asm("mov $0x0813ea80, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetGold()
{
    asm("leave");
    asm("mov $0x0813ec18, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetHasArms()
{
    asm("leave");
    asm("mov $0x0813dae4, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetHasInvisbilityEffectApplied()
{
    asm("leave");
    asm("mov $0x0813ba18, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetHasLegs()
{
    asm("leave");
    asm("mov $0x0813db08, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetHasted()
{
    asm("leave");
    asm("mov $0x0813e0ac, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetHealAnimationPlayed()
{
    asm("leave");
    asm("mov $0x0813d5c4, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetHenchmanId(int)
{
    asm("leave");
    asm("mov $0x0813e3c8, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetHenchmanIndex(unsigned long)
{
    asm("leave");
    asm("mov $0x0813d3b0, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetInSubAreasArray()
{
    asm("leave");
    asm("mov $0x0813df38, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetInTransit()
{
    asm("leave");
    asm("mov $0x0813ed7c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetInitiativeExpired()
{
    asm("leave");
    asm("mov $0x0813e1dc, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetInitiativeRoll()
{
    asm("leave");
    asm("mov $0x0813e1b8, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetInventory()
{
    asm("leave");
    asm("mov $0x0813d6d4, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetInvisible(CNWSObject *, int)
{
    asm("leave");
    asm("mov $0x08136f94, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetInvitedToPartyBy()
{
    asm("leave");
    asm("mov $0x0813e104, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetInvitedToParty()
{
    asm("leave");
    asm("mov $0x0813e0f4, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetIsAbleToPossessFamiliar()
{
    asm("leave");
    asm("mov $0x0813c7b4, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetIsCreatureBumpable(CNWSCreature *)
{
    asm("leave");
    asm("mov $0x0813811c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetIsDiseased()
{
    asm("leave");
    asm("mov $0x0813d930, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetIsExcited()
{
    asm("leave");
    asm("mov $0x0813e9d8, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetIsImmortal()
{
    asm("leave");
    asm("mov $0x0813ef18, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetIsInInvitationsIgnored(unsigned long)
{
    asm("leave");
    asm("mov $0x08111b3c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetIsInInvitationsOffered(unsigned long)
{
    asm("leave");
    asm("mov $0x08111a54, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetIsInMelee()
{
    asm("leave");
    asm("mov $0x080f5b58, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetIsInUseRange(unsigned long, float, int)
{
    asm("leave");
    asm("mov $0x08137730, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetIsPoisoned()
{
    asm("leave");
    asm("mov $0x0813d90c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetIsPolymorphLocked()
{
    asm("leave");
    asm("mov $0x0813eef4, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetIsPolymorphed()
{
    asm("leave");
    asm("mov $0x0813eda0, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetIsPolymorphing()
{
    asm("leave");
    asm("mov $0x0813eed0, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetIsPossessedFamiliar()
{
    asm("leave");
    asm("mov $0x08113574, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetIsWeaponEffective(unsigned long, int)
{
    asm("leave");
    asm("mov $0x081311b0, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetItemCastSpellBroadcastAOO()
{
    asm("leave");
    asm("mov $0x0813d818, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetItemContainerArrayIndex()
{
    asm("leave");
    asm("mov $0x0813dc6c, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreature::GetItemCount(int)
{
    asm("leave");
    asm("mov $0x0812e0bc, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetItemRepository()
{
    asm("leave");
    asm("mov $0x0813d6e4, %eax");
    asm("jmp *%eax");
}

CNWSJournal * CNWSCreature::GetJournal()
{
    asm("leave");
    asm("mov $0x0813c89c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetJumpedRecently()
{
    asm("leave");
    asm("mov $0x0813de2c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetLastAmmunitionWarning()
{
    asm("leave");
    asm("mov $0x0813d850, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetLastAssociateCommand()
{
    asm("leave");
    asm("mov $0x0813e398, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetLastBlockingDoor()
{
    asm("leave");
    asm("mov $0x0813eb10, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetLastCounterDomainLevel()
{
    asm("leave");
    asm("mov $0x0813e2c0, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetLastCounterMetaType()
{
    asm("leave");
    asm("mov $0x0813e29c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetLastCounterSpellClass()
{
    asm("leave");
    asm("mov $0x0813e278, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetLastCounterSpellID()
{
    asm("leave");
    asm("mov $0x0813e254, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetLastHideRoll()
{
    asm("leave");
    asm("mov $0x0813e93c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetLastItemCastSpellLevel()
{
    asm("leave");
    asm("mov $0x0813d7d0, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetLastItemCastSpell()
{
    asm("leave");
    asm("mov $0x0813d7ac, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetLastListenRoll()
{
    asm("leave");
    asm("mov $0x0813e918, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetLastMoveSilentlyRoll()
{
    asm("leave");
    asm("mov $0x0813e960, %eax");
    asm("jmp *%eax");
}

CExoLocString & CNWSCreature::GetLastName()
{
    asm("leave");
    asm("mov $0x0813dd5c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetLastPerceived()
{
    asm("leave");
    asm("mov $0x0813e82c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetLastPerceptionHeard()
{
    asm("leave");
    asm("mov $0x0813e850, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetLastPerceptionInaudible()
{
    asm("leave");
    asm("mov $0x0813e898, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetLastPerceptionSeen()
{
    asm("leave");
    asm("mov $0x0813e874, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetLastPerceptionVanished()
{
    asm("leave");
    asm("mov $0x0813e8bc, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetLastPickupFailed()
{
    asm("leave");
    asm("mov $0x0813e7d0, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetLastSpellCastItem()
{
    asm("leave");
    asm("mov $0x0813d808, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetLastSpellProjectileTime()
{
    asm("leave");
    asm("mov $0x0813dc14, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetLastSpellUnReadied()
{
    asm("leave");
    asm("mov $0x0813d788, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetLastSpotRoll()
{
    asm("leave");
    asm("mov $0x0813e8f4, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetLastTrapDetected()
{
    asm("leave");
    asm("mov $0x0813d860, %eax");
    asm("jmp *%eax");
}

float CNWSCreature::GetListenCheckDistance()
{
    asm("leave");
    asm("mov $0x0813d180, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetLockAnimationPlayed()
{
    asm("leave");
    asm("mov $0x0813d630, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreature::GetLockOrientationToObject()
{
    asm("leave");
    asm("mov $0x0813dc04, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetLootable()
{
    asm("leave");
    asm("mov $0x0813eaa4, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetMagicalArrowsEquipped()
{
    asm("leave");
    asm("mov $0x0813d510, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetMagicalBoltsEquipped()
{
    asm("leave");
    asm("mov $0x0813d534, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetMagicalBulletsEquipped()
{
    asm("leave");
    asm("mov $0x0813d558, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetMasterId()
{
    asm("leave");
    asm("mov $0x0813e388, %eax");
    asm("jmp *%eax");
}

short CNWSCreature::GetMaxHitPoints(int)
{
    asm("leave");
    asm("mov $0x0812e25c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetMode(unsigned char)
{
    asm("leave");
    asm("mov $0x0812c078, %eax");
    asm("jmp *%eax");
}

CExoString CNWSCreature::GetModelType()
{
    asm("leave");
    asm("mov $0x0813db94, %eax");
    asm("jmp *%eax");
}

float CNWSCreature::GetMovementRateFactor()
{
    asm("leave");
    asm("mov $0x08123fd8, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreature::GetNearestEnemy(float, unsigned long, int, int)
{
    asm("leave");
    asm("mov $0x0812c188, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetNoPermDeath()
{
    asm("leave");
    asm("mov $0x0813ef3c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetNonPolymorphCONBase()
{
    asm("leave");
    asm("mov $0x0813ee78, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetNonPolymorphDEXBase()
{
    asm("leave");
    asm("mov $0x0813eea4, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetNonPolymorphSTRBase()
{
    asm("leave");
    asm("mov $0x0813ee4c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetNumAreas()
{
    asm("leave");
    asm("mov $0x0813ec08, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetNumAssociatesOfType(unsigned short)
{
    asm("leave");
    asm("mov $0x08113460, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetNumCharSheetViewers()
{
    asm("leave");
    asm("mov $0x0813da6c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetNumCounterSpellingCreatures(unsigned long)
{
    asm("leave");
    asm("mov $0x081276c4, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetNumInvited()
{
    asm("leave");
    asm("mov $0x08113804, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetOnCreationScriptExecuted()
{
    asm("leave");
    asm("mov $0x0813de50, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetOriginalFactionId()
{
    asm("leave");
    asm("mov $0x0813e67c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetPVPList()
{
    asm("leave");
    asm("mov $0x0813ed6c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetPVPPlayerLikesMe(unsigned long)
{
    asm("leave");
    asm("mov $0x081138cc, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetPVPReputation(unsigned long)
{
    asm("leave");
    asm("mov $0x081123f4, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetPassiveAttackBehaviour()
{
    asm("leave");
    asm("mov $0x0813e970, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetPathfindInformation()
{
    asm("leave");
    asm("mov $0x0813d6f4, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetPendingRealization()
{
    asm("leave");
    asm("mov $0x0813efa8, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetPersonalReputationList()
{
    asm("leave");
    asm("mov $0x0813e6b4, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetPickUpItemAnimationPlayed()
{
    asm("leave");
    asm("mov $0x0813d678, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetPlayerCharacter()
{
    asm("leave");
    asm("mov $0x0813e2d0, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetPolymorphSpellId1()
{
    asm("leave");
    asm("mov $0x0813edb0, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetPolymorphSpellId2()
{
    asm("leave");
    asm("mov $0x0813edc0, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetPolymorphSpellId3()
{
    asm("leave");
    asm("mov $0x0813edd0, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetPonyRide()
{
    asm("leave");
    asm("mov $0x0813d8c4, %eax");
    asm("jmp *%eax");
}

CResRef CNWSCreature::GetPortrait()
{
    asm("leave");
    asm("mov $0x0813eb44, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetPreDominationFactionId()
{
    asm("leave");
    asm("mov $0x0813e690, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetPrePolymorphCON()
{
    asm("leave");
    asm("mov $0x0813ee2c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetPrePolymorphDEX()
{
    asm("leave");
    asm("mov $0x0813ee3c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetPrePolymorphSTR()
{
    asm("leave");
    asm("mov $0x0813ee1c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetPreferredAttackDistance()
{
    asm("leave");
    asm("mov $0x0813dbf4, %eax");
    asm("jmp *%eax");
}

CNWSQuickbarButton * CNWSCreature::GetQuickbarButton(unsigned char)
{
    asm("leave");
    asm("mov $0x0813d370, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetQuickbarInitialized()
{
    asm("leave");
    asm("mov $0x0813ec28, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetRangeWeaponEquipped()
{
    asm("leave");
    asm("mov $0x0813c0a8, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetRelativeWeaponSize(CNWSItem *)
{
    asm("leave");
    asm("mov $0x0813c71c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetRepositoryArrayIndex()
{
    asm("leave");
    asm("mov $0x0813dc48, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetReputationList()
{
    asm("leave");
    asm("mov $0x0813e6a4, %eax");
    asm("jmp *%eax");
}

float CNWSCreature::GetRunRate()
{
    asm("leave");
    asm("mov $0x0813c484, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetScriptName(int)
{
    asm("leave");
    asm("mov $0x0813d704, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetSilent()
{
    asm("leave");
    asm("mov $0x0813e088, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetSittingObject()
{
    asm("leave");
    asm("mov $0x0813d4ec, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetSlowed()
{
    asm("leave");
    asm("mov $0x0813e0d0, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetSoundSet()
{
    asm("leave");
    asm("mov $0x0813ef60, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetSpellIdentifiedList()
{
    asm("leave");
    asm("mov $0x0813e230, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetSpellOrHealActionQueued()
{
    asm("leave");
    asm("mov $0x0813b980, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetSpellTarget()
{
    asm("leave");
    asm("mov $0x0813ea5c, %eax");
    asm("jmp *%eax");
}

float CNWSCreature::GetSpotCheckDistance()
{
    asm("leave");
    asm("mov $0x0813d160, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetStandardFactionReputation(int)
{
    asm("leave");
    asm("mov $0x081127d8, %eax");
    asm("jmp *%eax");
}

CNWSCreatureStats * CNWSCreature::GetStats()
{
    asm("leave");
    asm("mov $0x0813d4c8, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetStealAnimationPlayed()
{
    asm("leave");
    asm("mov $0x0813d57c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetStealAttemptDetected()
{
    asm("leave");
    asm("mov $0x0813d5a0, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetStealthMode()
{
    asm("leave");
    asm("mov $0x0813da7c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetSummonedAnimalCompanion()
{
    asm("leave");
    asm("mov $0x0813e4b0, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetSummonedCreatureId()
{
    asm("leave");
    asm("mov $0x0813e650, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetSummonedFamiliar()
{
    asm("leave");
    asm("mov $0x0813e5e8, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetTauntAnimationPlayed()
{
    asm("leave");
    asm("mov $0x0813d69c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetTaunt()
{
    asm("leave");
    asm("mov $0x0813e13c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetTileExplored(unsigned long, int, int)
{
    asm("leave");
    asm("mov $0x08124f04, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetTotalEffectBonus(unsigned char, CNWSObject *, int, int, unsigned char, unsigned char, unsigned char, unsigned char, int)
{
    asm("leave");
    asm("mov $0x08132298, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetTotalWeightCarried()
{
    asm("leave");
    asm("mov $0x0813ed38, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetTrapAnimationPlayed()
{
    asm("leave");
    asm("mov $0x0813d5e8, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetTurnResistanceHD()
{
    asm("leave");
    asm("mov $0x08138074, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetUnarmed()
{
    asm("leave");
    asm("mov $0x0813c0f0, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetUnlockAnimationPlayed()
{
    asm("leave");
    asm("mov $0x0813d60c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetUpdateCombatInformation()
{
    asm("leave");
    asm("mov $0x0813da48, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetUpdateDisplayName()
{
    asm("leave");
    asm("mov $0x0813de08, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetUseMonkAbilities()
{
    asm("leave");
    asm("mov $0x081241f8, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetUseRange(unsigned long, Vector &, float &)
{
    asm("leave");
    asm("mov $0x0813799c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetVisibilityList()
{
    asm("leave");
    asm("mov $0x0813e78c, %eax");
    asm("jmp *%eax");
}

CNWVisibilityNode * CNWSCreature::GetVisibleListElement(unsigned long)
{
    asm("leave");
    asm("mov $0x081131fc, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetVisionType()
{
    asm("leave");
    asm("mov $0x0813dfe8, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetWalkAnimation()
{
    asm("leave");
    asm("mov $0x0813e14c, %eax");
    asm("jmp *%eax");
}

float CNWSCreature::GetWalkRate()
{
    asm("leave");
    asm("mov $0x0813c458, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetWeaponPower(CNWSObject *, int)
{
    asm("leave");
    asm("mov $0x08131a10, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::GetWeaponScale()
{
    asm("leave");
    asm("mov $0x0813dbd0, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::HandleSubAreaStateChanges(CExoArrayList<unsigned long> *, CExoArrayList<unsigned long> *, int)
{
    asm("leave");
    asm("mov $0x08103970, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::InitialisePVPList()
{
    asm("leave");
    asm("mov $0x08112694, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::InitializeQuickbar()
{
    asm("leave");
    asm("mov $0x0813b2d8, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::IsAIState(unsigned short)
{
    asm("leave");
    asm("mov $0x0813d954, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::IsHelpless()
{
    asm("leave");
    asm("mov $0x0813d9ac, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::LearnScroll(unsigned long)
{
    asm("leave");
    asm("mov $0x0813a974, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::LoadAssociateList(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x0811fc20, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::LoadAutoMapData(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x08121630, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::LoadCreature(CResGFF *, CResStruct *, int, int, int, int)
{
    asm("leave");
    asm("mov $0x08120218, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::LoadFromTemplate(CResRef, CExoString *)
{
    asm("leave");
    asm("mov $0x0811e46c, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::LoadPersonalReputationList(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x0811f7bc, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::LoadPolymorphData(CResGFF *, CResStruct *, int)
{
    asm("leave");
    asm("mov $0x08120688, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::LoadQuickBarHack(CExoString)
{
    asm("leave");
    asm("mov $0x081394f4, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::LoadQuickButtons(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x08121788, %eax");
    asm("jmp *%eax");
}

float CNWSCreature::MaxAttackRange(unsigned long, int, int)
{
    asm("leave");
    asm("mov $0x0813c114, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::MergeItem(CNWSItem *, CNWSItem *)
{
    asm("leave");
    asm("mov $0x0811a014, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::NotifyAssociateActionToggle(int)
{
    asm("leave");
    asm("mov $0x0813b454, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::PacifyCreature()
{
    asm("leave");
    asm("mov $0x08137ca8, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::PacifyCreature(unsigned long)
{
    asm("leave");
    asm("mov $0x08137dc4, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::PayToIdentifyItem(unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x08131984, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::Polymorph(int, CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x081356a0, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::PossessCreatureDM(unsigned long, unsigned char)
{
    asm("leave");
    asm("mov $0x081133b0, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::PossessCreature(unsigned long)
{
    asm("leave");
    asm("mov $0x0810e658, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::PossessFamiliar()
{
    asm("leave");
    asm("mov $0x0810de48, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::PostProcess()
{
    asm("leave");
    asm("mov $0x0812430c, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ProcessMasterDeathForAssociates()
{
    asm("leave");
    asm("mov $0x08110ae8, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ProcessPendingCombatActions()
{
    asm("leave");
    asm("mov $0x0813a4c0, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::QuickbarButton_RemoveItem(unsigned long)
{
    asm("leave");
    asm("mov $0x0813029c, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::QuickbarButton_RemoveSpell(unsigned long)
{
    asm("leave");
    asm("mov $0x0813034c, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ReadItemsFromGff(CResGFF *, CResStruct *, int, int)
{
    asm("leave");
    asm("mov $0x0811eee0, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ReadScriptsFromGff(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x0811e768, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::RealizeAssociateList()
{
    asm("leave");
    asm("mov $0x0811ffd4, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ReceiveAssociateCommand(int)
{
    asm("leave");
    asm("mov $0x0810cdc0, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::RecomputeAmbientAnimationState()
{
    asm("leave");
    asm("mov $0x08128ca0, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::RelayQuickChatCommandToAssociates(unsigned short)
{
    asm("leave");
    asm("mov $0x08113308, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::RemoveAllAssociates()
{
    asm("leave");
    asm("mov $0x08112a28, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::RemoveAreaOfEffect(unsigned long)
{
    asm("leave");
    asm("mov $0x0813dec0, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::RemoveAssociate(unsigned long)
{
    asm("leave");
    asm("mov $0x0810c8f4, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::RemoveBadEffects()
{
    asm("leave");
    asm("mov $0x0812dfb8, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::RemoveCharmEffectsByFactionID(int, int)
{
    asm("leave");
    asm("mov $0x0812dc88, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::RemoveCharmEffectsByOBJECTID(unsigned long, int)
{
    asm("leave");
    asm("mov $0x0812da14, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::RemoveCombatInvisibilityEffects()
{
    asm("leave");
    asm("mov $0x081374d0, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::RemoveDominationEffect()
{
    asm("leave");
    asm("mov $0x08110a40, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::RemoveDomination()
{
    asm("leave");
    asm("mov $0x081134cc, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::RemoveFromArea(int)
{
    asm("leave");
    asm("mov $0x0811b87c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::RemoveFromAssociateList(unsigned long)
{
    asm("leave");
    asm("mov $0x081132c4, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::RemoveFromInvitationsOffered(unsigned long)
{
    asm("leave");
    asm("mov $0x08113668, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::RemoveFromPVPList(unsigned long)
{
    asm("leave");
    asm("mov $0x08113924, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::RemoveFromVisibleList(unsigned long)
{
    asm("leave");
    asm("mov $0x0810890c, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::RemoveGold(int, int)
{
    asm("leave");
    asm("mov $0x081318a0, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::RemoveItemFromRepository(CNWSItem *, int)
{
    asm("leave");
    asm("mov $0x0813b22c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::RemoveItem(CNWSItem *, int, int, int, int)
{
    asm("leave");
    asm("mov $0x081000e8, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::RemoveSleepEffects()
{
    asm("leave");
    asm("mov $0x0812de6c, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::RemoveSpellActionFromRound()
{
    asm("leave");
    asm("mov $0x0813a424, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::RemoveWoundingEffects()
{
    asm("leave");
    asm("mov $0x0812e04c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::ReplyToInvitation(int, unsigned long)
{
    asm("leave");
    asm("mov $0x08111930, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ReprocessAssociateList()
{
    asm("leave");
    asm("mov $0x0810c55c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::RequestBuy(unsigned long, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x0812f0f4, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::RequestSell(unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x0812f1e4, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ResetItemPossessor()
{
    asm("leave");
    asm("mov $0x081111d8, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ResetPCDominatedScripts()
{
    asm("leave");
    asm("mov $0x08110268, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ResetUpdateTimes(unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x0813bf90, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ResolveAmmunition(unsigned long)
{
    asm("leave");
    asm("mov $0x080e7754, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ResolveAttackRoll(CNWSObject *)
{
    asm("leave");
    asm("mov $0x080eb190, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ResolveAttack(unsigned long, int, int)
{
    asm("leave");
    asm("mov $0x080e6c44, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ResolveCachedSpecialAttacks()
{
    asm("leave");
    asm("mov $0x080ec390, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ResolveDamageShields(CNWSCreature *)
{
    asm("leave");
    asm("mov $0x080efcac, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ResolveDamage(CNWSObject *)
{
    asm("leave");
    asm("mov $0x080ec5b4, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ResolveDeathAttack(CNWSCreature *)
{
    asm("leave");
    asm("mov $0x080ebdfc, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::ResolveDefensiveEffects(CNWSObject *, int)
{
    asm("leave");
    asm("mov $0x080edc58, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::ResolveElementalDamage(CNWSObject *)
{
    asm("leave");
    asm("mov $0x080f5ad4, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ResolveInitiative()
{
    asm("leave");
    asm("mov $0x08128b18, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ResolveItemCastSpell(CNWSObject *)
{
    asm("leave");
    asm("mov $0x080ecb18, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ResolveMeleeAnimations(int, int, CNWSObject *, int)
{
    asm("leave");
    asm("mov $0x080eaa18, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ResolveMeleeAttack(CNWSObject *, int, int)
{
    asm("leave");
    asm("mov $0x080e9930, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ResolveMeleeSpecialAttack(int, int, CNWSObject *, int)
{
    asm("leave");
    asm("mov $0x080e9a98, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ResolveOnHitEffect(CNWSObject *, int, int)
{
    asm("leave");
    asm("mov $0x080ee6c0, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ResolveOnHitVisuals(CNWSObject *)
{
    asm("leave");
    asm("mov $0x080ee4d4, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ResolvePostMeleeDamage(CNWSObject *)
{
    asm("leave");
    asm("mov $0x080ecf80, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ResolvePostRangedDamage(CNWSObject *)
{
    asm("leave");
    asm("mov $0x080ed7e4, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ResolveRangedAnimations(CNWSObject *, int)
{
    asm("leave");
    asm("mov $0x080e7fe8, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ResolveRangedAttack(CNWSObject *, int, int)
{
    asm("leave");
    asm("mov $0x080e6fe4, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ResolveRangedMiss(CNWSObject *)
{
    asm("leave");
    asm("mov $0x080e8530, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ResolveRangedSpecialAttack(CNWSObject *, int)
{
    asm("leave");
    asm("mov $0x080e71d4, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ResolveSafeProjectile(unsigned long, int)
{
    asm("leave");
    asm("mov $0x080e7630, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ResolveSituationalModifiers(CNWSObject *)
{
    asm("leave");
    asm("mov $0x080ec480, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ResolveSneakAttack(CNWSCreature *)
{
    asm("leave");
    asm("mov $0x080eb720, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::Rest(int, int)
{
    asm("leave");
    asm("mov $0x0812d45c, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::RestoreCutsceneVars()
{
    asm("leave");
    asm("mov $0x0813d444, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::RestoreItemPropertiesInRepository(CItemRepository *)
{
    asm("leave");
    asm("mov $0x0812bc00, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::RestoreItemProperties()
{
    asm("leave");
    asm("mov $0x0813c600, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::RunEquip(unsigned long, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x08116f20, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::RunUnequip(unsigned long, unsigned long, unsigned char, unsigned char, int, unsigned long)
{
    asm("leave");
    asm("mov $0x08117b54, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SaveAssociateList(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x0811faa0, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SaveAutoMapData(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x0813c224, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SaveCreature(CResGFF *, CResStruct *, int, int, int)
{
    asm("leave");
    asm("mov $0x081209fc, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SavePersonalReputationList(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x0811f558, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SaveQuickBarHack(CExoString)
{
    asm("leave");
    asm("mov $0x0813960c, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SaveQuickButtons(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x081230f4, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSCreature::SavingThrowRoll(unsigned char, unsigned short, unsigned char, unsigned long, int, unsigned short, int)
{
    asm("leave");
    asm("mov $0x080f0a90, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SawTrapInformAssociates(unsigned long)
{
    asm("leave");
    asm("mov $0x081124a0, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SendFeedbackMessage(unsigned short, CNWCCMessageData *, CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x0813533c, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SendFeedbackString(CExoString, CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x0813cecc, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetAIStateFlag(unsigned short, int)
{
    asm("leave");
    asm("mov $0x0813d970, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetAIState(unsigned short)
{
    asm("leave");
    asm("mov $0x0813d998, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetActivityLocked(unsigned long, int)
{
    asm("leave");
    asm("mov $0x0813e9b0, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SetActivity(int, int)
{
    asm("leave");
    asm("mov $0x081152e8, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetAlive()
{
    asm("leave");
    asm("mov $0x0813d9dc, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SetAllTilesExplored(unsigned long, int)
{
    asm("leave");
    asm("mov $0x08124d7c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetAlreadyRemovedFromEncounter(int)
{
    asm("leave");
    asm("mov $0x0813ec8c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetAmbientAnimationState(unsigned char)
{
    asm("leave");
    asm("mov $0x0813e338, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetAnimalCompanionCreatureType(int)
{
    asm("leave");
    asm("mov $0x0813e498, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SetAnimalCompanionName(CExoString)
{
    asm("leave");
    asm("mov $0x0813e3f4, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SetAnimation(int)
{
    asm("leave");
    asm("mov $0x0811b544, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SetAssociateListenPatterns()
{
    asm("leave");
    asm("mov $0x0810cb90, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SetAssociateType(unsigned short)
{
    asm("leave");
    asm("mov $0x0813d388, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SetAssociatesToForgetAggression(unsigned long)
{
    asm("leave");
    asm("mov $0x08112c00, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetAttackTarget(unsigned long)
{
    asm("leave");
    asm("mov $0x0813ea00, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetAttemptedAttackTarget(unsigned long)
{
    asm("leave");
    asm("mov $0x0813ea24, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetAttemptedSpellTarget(unsigned long)
{
    asm("leave");
    asm("mov $0x0813ea48, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetAutoMapData(int, unsigned long *, unsigned char **)
{
    asm("leave");
    asm("mov $0x0813a86c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetBlindsightDistance(float)
{
    asm("leave");
    asm("mov $0x0813ed00, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetBodyBagId(unsigned long)
{
    asm("leave");
    asm("mov $0x0813eafc, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetBodyBag(unsigned char)
{
    asm("leave");
    asm("mov $0x0813efe4, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetBroadcastedAOOTo(int)
{
    asm("leave");
    asm("mov $0x0813c504, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetCalculateNPCWeight(int)
{
    asm("leave");
    asm("mov $0x0813ed58, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SetCombatMode(unsigned char, int)
{
    asm("leave");
    asm("mov $0x080f982c, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SetCombatState(int)
{
    asm("leave");
    asm("mov $0x0813c524, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetCounterSpellTarget(unsigned long)
{
    asm("leave");
    asm("mov $0x0813e314, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetCreatureSize(int)
{
    asm("leave");
    asm("mov $0x0813db18, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetCreatureState(unsigned char)
{
    asm("leave");
    asm("mov $0x0813d8f8, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetCurrentItemContainer(unsigned long)
{
    asm("leave");
    asm("mov $0x0813dca0, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetCutsceneCameraMode(int)
{
    asm("leave");
    asm("mov $0x0813e008, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetCutsceneCameraMovementRateFactor(float)
{
    asm("leave");
    asm("mov $0x0813e050, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetCutsceneGhost(int)
{
    asm("leave");
    asm("mov $0x0813e02c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetDMCharacter(int)
{
    asm("leave");
    asm("mov $0x0813ec64, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetDead()
{
    asm("leave");
    asm("mov $0x0813d9c8, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetDecayTime(unsigned long)
{
    asm("leave");
    asm("mov $0x0813ead8, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SetDefensiveCastingMode(unsigned char)
{
    asm("leave");
    asm("mov $0x08112eb0, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetDesiredAreaId(unsigned long)
{
    asm("leave");
    asm("mov $0x0813df58, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetDesiredAreaLocation(Vector)
{
    asm("leave");
    asm("mov $0x0813df90, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetDesiredAreaUpdateComplete(int)
{
    asm("leave");
    asm("mov $0x0813dfc0, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetDesiredCombatMode(unsigned char)
{
    asm("leave");
    asm("mov $0x0813dabc, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SetDetectMode(unsigned char)
{
    asm("leave");
    asm("mov $0x08112e84, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetDisarmable(int)
{
    asm("leave");
    asm("mov $0x0813da20, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SetDisplayName(CExoString)
{
    asm("leave");
    asm("mov $0x0813dda4, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetDriveModeMoveFactor(float)
{
    asm("leave");
    asm("mov $0x0813d9ec, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetDriveMode(int)
{
    asm("leave");
    asm("mov $0x0813e1a4, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetDropItemAnimationPlayed(int)
{
    asm("leave");
    asm("mov $0x0813d640, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SetEffectSpellId(unsigned long)
{
    asm("leave");
    asm("mov $0x0813e818, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetEncounterId(unsigned long)
{
    asm("leave");
    asm("mov $0x0813e7ac, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetEncumbranceState(int)
{
    asm("leave");
    asm("mov $0x0813e7e0, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetEquipArrayIndex(unsigned short)
{
    asm("leave");
    asm("mov $0x0813dc34, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetEquippedWeight(int)
{
    asm("leave");
    asm("mov $0x0813ed24, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SetExcitedState(unsigned char)
{
    asm("leave");
    asm("mov $0x0812d29c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetExternalCombatModeEnabled(int)
{
    asm("leave");
    asm("mov $0x0813f02c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetFacingAndAnimationDone(int)
{
    asm("leave");
    asm("mov $0x0813eff8, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetFactionId(int)
{
    asm("leave");
    asm("mov $0x0813e6c4, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetFamiliarCreatureType(int)
{
    asm("leave");
    asm("mov $0x0813e5d0, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SetFamiliarName(CExoString)
{
    asm("leave");
    asm("mov $0x0813e52c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetFootstepType(int)
{
    asm("leave");
    asm("mov $0x0813ef70, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetForcedWalk(int)
{
    asm("leave");
    asm("mov $0x0813e170, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetGoingToBeAttackedBy(unsigned long)
{
    asm("leave");
    asm("mov $0x0813ea90, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SetGold(int)
{
    asm("leave");
    asm("mov $0x0813ce38, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetHasArms(int)
{
    asm("leave");
    asm("mov $0x0813dad0, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetHasLegs(int)
{
    asm("leave");
    asm("mov $0x0813daf4, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetHasted(int)
{
    asm("leave");
    asm("mov $0x0813e098, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetHealAnimationPlayed(int)
{
    asm("leave");
    asm("mov $0x0813d5b0, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SetId(unsigned long)
{
    asm("leave");
    asm("mov $0x0813bae8, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SetInTransit(int)
{
    asm("leave");
    asm("mov $0x0813d024, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetInitiativeExpired(int)
{
    asm("leave");
    asm("mov $0x0813e1ec, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetInitiativeRoll(unsigned char)
{
    asm("leave");
    asm("mov $0x0813e1c8, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetInvitedToPartyBy(unsigned long)
{
    asm("leave");
    asm("mov $0x0813e114, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SetInvitedToParty(int)
{
    asm("leave");
    asm("mov $0x0813d298, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetIsDiseased(int)
{
    asm("leave");
    asm("mov $0x0813d940, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetIsImmortal(int)
{
    asm("leave");
    asm("mov $0x0813ef04, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetIsPoisoned(int)
{
    asm("leave");
    asm("mov $0x0813d91c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetIsPolymorphed(int)
{
    asm("leave");
    asm("mov $0x0813ed8c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetItemCastSpellBroadcastAOO(int)
{
    asm("leave");
    asm("mov $0x0813d828, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetItemContainerArrayIndex(unsigned short)
{
    asm("leave");
    asm("mov $0x0813dc7c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetJumpedRecently(int)
{
    asm("leave");
    asm("mov $0x0813de3c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetLastAmmunitionWarning(int)
{
    asm("leave");
    asm("mov $0x0813d83c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetLastAssociateCommand(int)
{
    asm("leave");
    asm("mov $0x0813e374, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetLastBlockingDoor(unsigned long)
{
    asm("leave");
    asm("mov $0x0813eb20, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetLastCounterDomainLevel(unsigned char)
{
    asm("leave");
    asm("mov $0x0813e2ac, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetLastCounterMetaType(unsigned char)
{
    asm("leave");
    asm("mov $0x0813e288, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetLastCounterSpellClass(unsigned char)
{
    asm("leave");
    asm("mov $0x0813e264, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetLastCounterSpellID(int)
{
    asm("leave");
    asm("mov $0x0813e240, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetLastHearbeatTime(unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x0813efb8, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetLastHideRoll(unsigned char)
{
    asm("leave");
    asm("mov $0x0813e928, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetLastItemCastSpellLevel(int)
{
    asm("leave");
    asm("mov $0x0813d7e0, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetLastItemCastSpell(int)
{
    asm("leave");
    asm("mov $0x0813d7bc, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetLastListenRoll(unsigned char)
{
    asm("leave");
    asm("mov $0x0813e904, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetLastMoveSilentlyRoll(unsigned char)
{
    asm("leave");
    asm("mov $0x0813e94c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetLastPerceived(unsigned long)
{
    asm("leave");
    asm("mov $0x0813e83c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetLastPerceptionHeard(int)
{
    asm("leave");
    asm("mov $0x0813e860, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetLastPerceptionInaudible(int)
{
    asm("leave");
    asm("mov $0x0813e8a8, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetLastPerceptionSeen(int)
{
    asm("leave");
    asm("mov $0x0813e884, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetLastPerceptionVanished(int)
{
    asm("leave");
    asm("mov $0x0813e8cc, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetLastPickupFailed(int)
{
    asm("leave");
    asm("mov $0x0813e7f4, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetLastSpellCastItem(unsigned long)
{
    asm("leave");
    asm("mov $0x0813d7f4, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetLastSpellUnReadied(int)
{
    asm("leave");
    asm("mov $0x0813d798, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetLastSpotRoll(unsigned char)
{
    asm("leave");
    asm("mov $0x0813e8e0, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetLastTrapDetected(unsigned long)
{
    asm("leave");
    asm("mov $0x0813d870, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetListenCheckDistance(float)
{
    asm("leave");
    asm("mov $0x0813ecb4, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetLockAnimationPlayed(int)
{
    asm("leave");
    asm("mov $0x0813d61c, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SetLockOrientationToObject(unsigned long)
{
    asm("leave");
    asm("mov $0x0812c8bc, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetLootable(int)
{
    asm("leave");
    asm("mov $0x0813eab4, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetMagicalArrowsEquipped(int)
{
    asm("leave");
    asm("mov $0x0813d4fc, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetMagicalBoltsEquipped(int)
{
    asm("leave");
    asm("mov $0x0813d520, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetMagicalBulletsEquipped(int)
{
    asm("leave");
    asm("mov $0x0813d544, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetMasterId(unsigned long)
{
    asm("leave");
    asm("mov $0x0813e35c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetMaxListenCheckDistance(float)
{
    asm("leave");
    asm("mov $0x0813ecdc, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetMaxSpotCheckDistance(float)
{
    asm("leave");
    asm("mov $0x0813ecc8, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SetMode(unsigned char, int)
{
    asm("leave");
    asm("mov $0x0813c66c, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SetModelType(CExoString)
{
    asm("leave");
    asm("mov $0x0813db3c, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SetMovementRateFactor(float)
{
    asm("leave");
    asm("mov $0x08124130, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetNoPermDeath(int)
{
    asm("leave");
    asm("mov $0x0813ef28, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetNumAreas(int)
{
    asm("leave");
    asm("mov $0x0813ebf4, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetNumCharSheetViewers(int)
{
    asm("leave");
    asm("mov $0x0813da58, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetOnCreationScriptExecuted(int)
{
    asm("leave");
    asm("mov $0x0813de60, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetOriginalFactionId(int)
{
    asm("leave");
    asm("mov $0x0813e6dc, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SetPCDominatedScripts()
{
    asm("leave");
    asm("mov $0x0810fa40, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SetPVPPlayerLikesMe(unsigned long, int, int)
{
    asm("leave");
    asm("mov $0x081125b4, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetPassiveAttackBehaviour(int)
{
    asm("leave");
    asm("mov $0x0813e980, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetPendingRealization(int)
{
    asm("leave");
    asm("mov $0x0813ef94, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetPersonalReputation(CExoArrayList<CNWSPersonalReputation> *)
{
    asm("leave");
    asm("mov $0x0813e74c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetPickUpItemAnimationPlayed(int)
{
    asm("leave");
    asm("mov $0x0813d664, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetPlayerCharacter(int)
{
    asm("leave");
    asm("mov $0x0813e300, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetPolymorphLocked(int)
{
    asm("leave");
    asm("mov $0x0813eee0, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetPonyRide(int)
{
    asm("leave");
    asm("mov $0x0813d8d4, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SetPortraitId(unsigned short)
{
    asm("leave");
    asm("mov $0x0812e7f4, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SetPortrait(CResRef)
{
    asm("leave");
    asm("mov $0x0813eb90, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetPreDominationFactionId(int)
{
    asm("leave");
    asm("mov $0x0813e6f4, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetPrePolymorphCON(int)
{
    asm("leave");
    asm("mov $0x0813edf4, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetPrePolymorphDEX(int)
{
    asm("leave");
    asm("mov $0x0813ee08, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetPrePolymorphSTR(int)
{
    asm("leave");
    asm("mov $0x0813ede0, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetPreferredAttackDistance(float)
{
    asm("leave");
    asm("mov $0x0813dbe0, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SetQuickbarButton_AssociateCommand(unsigned char, int, unsigned short, unsigned long)
{
    asm("leave");
    asm("mov $0x0813ca38, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SetQuickbarButton_CommandLine(unsigned char, CExoString const &, CExoString const &)
{
    asm("leave");
    asm("mov $0x0813cd20, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SetQuickbarButton_DM_General_ResRefParam(unsigned char, unsigned char, CResRef const &)
{
    asm("leave");
    asm("mov $0x0813cd8c, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SetQuickbarButton_DungeonMaster_CreateCreature(unsigned char, CResRef const &, CExoString const &)
{
    asm("leave");
    asm("mov $0x0813ca80, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SetQuickbarButton_DungeonMaster_CreateEncounter(unsigned char, CResRef const &, CExoString const &)
{
    asm("leave");
    asm("mov $0x0813cb40, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SetQuickbarButton_DungeonMaster_CreateItem(unsigned char, CResRef const &, CExoString const &)
{
    asm("leave");
    asm("mov $0x0813cae0, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SetQuickbarButton_DungeonMaster_CreatePlaceable(unsigned char, CResRef const &, CExoString const &)
{
    asm("leave");
    asm("mov $0x0813ccc0, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SetQuickbarButton_DungeonMaster_CreatePortal(unsigned char, CResRef const &, CExoString const &)
{
    asm("leave");
    asm("mov $0x0813cc60, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SetQuickbarButton_DungeonMaster_CreateTrigger(unsigned char, CResRef const &, CExoString const &)
{
    asm("leave");
    asm("mov $0x0813cc00, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SetQuickbarButton_DungeonMaster_CreateWaypoint(unsigned char, CResRef const &, CExoString const &)
{
    asm("leave");
    asm("mov $0x0813cba0, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SetQuickbarButton_GeneralINTParam(unsigned char, unsigned char, int)
{
    asm("leave");
    asm("mov $0x0813ce00, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SetQuickbarButton_GeneralNoParam(unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x0813cdd4, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SetQuickbarButton_Item(unsigned char, unsigned long, int, unsigned long)
{
    asm("leave");
    asm("mov $0x0813c960, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SetQuickbarButton_SpellLikeAbility(unsigned char, unsigned long, unsigned char)
{
    asm("leave");
    asm("mov $0x0813c9fc, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SetQuickbarButton_Spell(unsigned char, unsigned char, unsigned long, unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x0813c9a0, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetRepositoryArrayIndex(unsigned short)
{
    asm("leave");
    asm("mov $0x0813dc58, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetReputation(CExoArrayList<int> *)
{
    asm("leave");
    asm("mov $0x0813e70c, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SetScriptName(int, CExoString)
{
    asm("leave");
    asm("mov $0x0813d720, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetSilent(int)
{
    asm("leave");
    asm("mov $0x0813e074, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetSittingObject(unsigned long)
{
    asm("leave");
    asm("mov $0x0813d4d8, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetSlowed(int)
{
    asm("leave");
    asm("mov $0x0813e0bc, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetSoundSet(unsigned short)
{
    asm("leave");
    asm("mov $0x0813ef4c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetSpellTarget(unsigned long)
{
    asm("leave");
    asm("mov $0x0813ea6c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetSpotCheckDistance(float)
{
    asm("leave");
    asm("mov $0x0813eca0, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SetStandardFactionReputation(int, int)
{
    asm("leave");
    asm("mov $0x08112938, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetStealAnimationPlayed(int)
{
    asm("leave");
    asm("mov $0x0813d568, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetStealAttemptDetected(int)
{
    asm("leave");
    asm("mov $0x0813d58c, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SetStealthMode(unsigned char)
{
    asm("leave");
    asm("mov $0x080f975c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetSummonedAnimalCompanion(int)
{
    asm("leave");
    asm("mov $0x0813e3e0, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetSummonedFamiliar(int)
{
    asm("leave");
    asm("mov $0x0813e518, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetTauntAnimationPlayed(int)
{
    asm("leave");
    asm("mov $0x0813d688, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetTaunt(int)
{
    asm("leave");
    asm("mov $0x0813e128, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SetTileExplored(unsigned long, int, int)
{
    asm("leave");
    asm("mov $0x08124e4c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetTrapAnimationPlayed(int)
{
    asm("leave");
    asm("mov $0x0813d5d4, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetUnlockAnimationPlayed(int)
{
    asm("leave");
    asm("mov $0x0813d5f8, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetUpdateCombatInformation(int)
{
    asm("leave");
    asm("mov $0x0813da34, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetUpdateDisplayName(int)
{
    asm("leave");
    asm("mov $0x0813de18, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetVisionType(unsigned char)
{
    asm("leave");
    asm("mov $0x0813dfd4, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetWalkAnimation(unsigned char)
{
    asm("leave");
    asm("mov $0x0813e15c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::SetWeaponScale(float)
{
    asm("leave");
    asm("mov $0x0813dbbc, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SignalMeleeDamage(CNWSObject *, int)
{
    asm("leave");
    asm("mov $0x080eacac, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SignalRangedDamage(CNWSObject *, int)
{
    asm("leave");
    asm("mov $0x080e94dc, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SpawnInHeartbeatPerception(int)
{
    asm("leave");
    asm("mov $0x0811972c, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SplitItem(CNWSItem *, int)
{
    asm("leave");
    asm("mov $0x0811a1d0, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::StartBarter(unsigned long, unsigned long, int)
{
    asm("leave");
    asm("mov $0x0812fc6c, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::StartGuiTimingBar(unsigned long, unsigned char)
{
    asm("leave");
    asm("mov $0x0813d1a0, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::StopGuiTimingBar()
{
    asm("leave");
    asm("mov $0x0813d224, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::StoreCutsceneVars()
{
    asm("leave");
    asm("mov $0x0813d424, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SummonAnimalCompanion()
{
    asm("leave");
    asm("mov $0x0810d1c0, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SummonAssociate(CResRef, CExoString, unsigned short)
{
    asm("leave");
    asm("mov $0x0810da28, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::SummonFamiliar()
{
    asm("leave");
    asm("mov $0x0810d628, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::TerminateClientSidePath(int)
{
    asm("leave");
    asm("mov $0x08112f5c, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::TestAIStateAsMode(int)
{
    asm("leave");
    asm("mov $0x0813c214, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::ToggleMode(unsigned char)
{
    asm("leave");
    asm("mov $0x0812bcb4, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::TransferGold(unsigned long, Vector, unsigned long, int, unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x0812f3e8, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::TranslateAddress(unsigned long, int, int, int *, int *)
{
    asm("leave");
    asm("mov $0x0813c4b0, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::UnPolymorph(CGameEffect *)
{
    asm("leave");
    asm("mov $0x081369f8, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::UnequipItem(CNWSItem *, int)
{
    asm("leave");
    asm("mov $0x0811b7b0, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::UnpossessCreatureDM()
{
    asm("leave");
    asm("mov $0x08113420, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::UnpossessCreature()
{
    asm("leave");
    asm("mov $0x0810e83c, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::UnpossessFamiliar()
{
    asm("leave");
    asm("mov $0x0810e174, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::UnsummonMyself()
{
    asm("leave");
    asm("mov $0x0810cf84, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::UpdateActionQueue()
{
    asm("leave");
    asm("mov $0x08139ca4, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::UpdateAppearanceDependantInfo()
{
    asm("leave");
    asm("mov $0x0812f900, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::UpdateAppearanceForEquippedItems()
{
    asm("leave");
    asm("mov $0x0812efa0, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::UpdateAttributesOnEffect(CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x0811e0a8, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::UpdateAutoMap(unsigned long)
{
    asm("leave");
    asm("mov $0x08119e24, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::UpdateCombatRoundTimer()
{
    asm("leave");
    asm("mov $0x0811d740, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::UpdateEffectPtrs()
{
    asm("leave");
    asm("mov $0x0811dd04, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::UpdateEncumbranceState(int)
{
    asm("leave");
    asm("mov $0x08111e94, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::UpdateExcitedStateTimer()
{
    asm("leave");
    asm("mov $0x0812d3c8, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::UpdatePersonalSpace()
{
    asm("leave");
    asm("mov $0x0812f6b4, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::UpdateSpecialAttacks()
{
    asm("leave");
    asm("mov $0x0813a374, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::UpdateSubareasOnJumpPosition(Vector, unsigned long)
{
    asm("leave");
    asm("mov $0x081037cc, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::UpdateSubareasOnMoveTo(Vector, Vector, int, CExoArrayList<unsigned long> *, int)
{
    asm("leave");
    asm("mov $0x081035e0, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::UpdateTrapCheckDM()
{
    asm("leave");
    asm("mov $0x0813bfc4, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::UpdateTrapCheck()
{
    asm("leave");
    asm("mov $0x0811a2f4, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::UpdateVisibleList()
{
    asm("leave");
    asm("mov $0x08108500, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::UseFeat(unsigned short, unsigned short, unsigned long, unsigned long, Vector *)
{
    asm("leave");
    asm("mov $0x0812a004, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::UseItem(unsigned long, unsigned char, unsigned char, unsigned long, Vector, unsigned long)
{
    asm("leave");
    asm("mov $0x0812b958, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::UseLoreOnItem(unsigned long)
{
    asm("leave");
    asm("mov $0x08131680, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::UseSkill(unsigned char, unsigned char, unsigned long, Vector, unsigned long, unsigned long, int)
{
    asm("leave");
    asm("mov $0x0812b1d8, %eax");
    asm("jmp *%eax");
}

void CNWSCreature::ValidateCounterSpellData(unsigned long, unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x08127c08, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::WalkUpdateLocationDistance(float, Vector *, Vector *, CExoArrayList<unsigned long> *)
{
    asm("leave");
    asm("mov $0x081048a0, %eax");
    asm("jmp *%eax");
}

int CNWSCreature::WalkUpdateLocationTestDistance(Vector, Vector)
{
    asm("leave");
    asm("mov $0x08105040, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSCreature::WalkUpdateLocation()
{
    asm("leave");
    asm("mov $0x08104174, %eax");
    asm("jmp *%eax");
}

