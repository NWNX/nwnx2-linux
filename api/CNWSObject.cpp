#include "CNWSObject.h"

unsigned long CNWSObject::AIActionCloseDoor(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x081c4a58, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSObject::AIActionDialogObject(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x081c3204, %eax");
    asm("jmp *%eax");
}

int CNWSObject::AIActionDoCommand(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x081c8448, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSObject::AIActionGiveItem(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x081c43b8, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSObject::AIActionLockObject(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x081c6398, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSObject::AIActionOpenDoor(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x081c4d6c, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSObject::AIActionPauseDialog(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x081c3a7c, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSObject::AIActionPlayAnimation(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x081c4014, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSObject::AIActionPlaySound(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x081c3e18, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSObject::AIActionResumeDialog(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x081c3b88, %eax");
    asm("jmp *%eax");
}

int CNWSObject::AIActionSetCommandable(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x081c8568, %eax");
    asm("jmp *%eax");
}

int CNWSObject::AIActionSpeakStrRef(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x081c83c8, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSObject::AIActionSpeak(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x081c3ce8, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSObject::AIActionTakeItem(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x081c48b4, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSObject::AIActionUnlockObject(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x081c53d0, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSObject::AIActionUseObject(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x081c7274, %eax");
    asm("jmp *%eax");
}

int CNWSObject::AIActionWait(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x081c84a4, %eax");
    asm("jmp *%eax");
}

void CNWSObject::AddActionAfterFront(unsigned long, unsigned short, unsigned long, void *, unsigned long, void *, unsigned long, void *, unsigned long, void *, unsigned long, void *, unsigned long, void *, unsigned long, void *, unsigned long, void *, unsigned long, void *, unsigned long, void *, unsigned long, void *, unsigned long, void *)
{
    asm("leave");
    asm("mov $0x081cadb0, %eax");
    asm("jmp *%eax");
}

void CNWSObject::AddActionNodeParameter(CNWSObjectActionNode *, unsigned long, unsigned long, void *)
{
    asm("leave");
    asm("mov $0x081d49e0, %eax");
    asm("jmp *%eax");
}

void CNWSObject::AddActionToFront(unsigned long, unsigned short, unsigned long, void *, unsigned long, void *, unsigned long, void *, unsigned long, void *, unsigned long, void *, unsigned long, void *, unsigned long, void *, unsigned long, void *, unsigned long, void *, unsigned long, void *, unsigned long, void *, unsigned long, void *)
{
    asm("leave");
    asm("mov $0x081ca5c0, %eax");
    asm("jmp *%eax");
}

void CNWSObject::AddAction(unsigned long, unsigned short, unsigned long, void *, unsigned long, void *, unsigned long, void *, unsigned long, void *, unsigned long, void *, unsigned long, void *, unsigned long, void *, unsigned long, void *, unsigned long, void *, unsigned long, void *, unsigned long, void *, unsigned long, void *)
{
    asm("leave");
    asm("mov $0x081c9384, %eax");
    asm("jmp *%eax");
}

int CNWSObject::AddCloseDoorAction(unsigned long, int)
{
    asm("leave");
    asm("mov $0x081d5590, %eax");
    asm("jmp *%eax");
}

int CNWSObject::AddDoCommandAction(void *)
{
    asm("leave");
    asm("mov $0x081c861c, %eax");
    asm("jmp *%eax");
}

int CNWSObject::AddEffectTarget(unsigned long)
{
    asm("leave");
    asm("mov $0x081d5b6c, %eax");
    asm("jmp *%eax");
}

int CNWSObject::AddGiveItemActions(unsigned long, unsigned long, int)
{
    asm("leave");
    asm("mov $0x081c7bd8, %eax");
    asm("jmp *%eax");
}

int CNWSObject::AddLockObjectAction(unsigned long)
{
    asm("leave");
    asm("mov $0x081d565c, %eax");
    asm("jmp *%eax");
}

void CNWSObject::AddLoopingVisualEffect(unsigned short, unsigned long, unsigned char)
{
    asm("leave");
    asm("mov $0x081d4e98, %eax");
    asm("jmp *%eax");
}

void CNWSObject::AddMatchedExpressionString(CExoString const &)
{
    asm("leave");
    asm("mov $0x081d5254, %eax");
    asm("jmp *%eax");
}

int CNWSObject::AddOpenDoorAction(unsigned long, int)
{
    asm("leave");
    asm("mov $0x081d552c, %eax");
    asm("jmp *%eax");
}

int CNWSObject::AddTakeItemActions(unsigned long, unsigned long, int)
{
    asm("leave");
    asm("mov $0x081c7c94, %eax");
    asm("jmp *%eax");
}

int CNWSObject::AddUnlockObjectAction(unsigned long, unsigned long, int)
{
    asm("leave");
    asm("mov $0x081d55f4, %eax");
    asm("jmp *%eax");
}

int CNWSObject::AddUseObjectAction(unsigned long)
{
    asm("leave");
    asm("mov $0x081c85b0, %eax");
    asm("jmp *%eax");
}

int CNWSObject::AnimationStationary(unsigned short)
{
    asm("leave");
    asm("mov $0x081d4ca8, %eax");
    asm("jmp *%eax");
}

void CNWSObject::ApplyEffect(CGameEffect *, int, int)
{
    asm("leave");
    asm("mov $0x081ce7d8, %eax");
    asm("jmp *%eax");
}

CNWSObject * CNWSObject::AsNWSObject()
{
    asm("leave");
    asm("mov $0x081d5838, %eax");
    asm("jmp *%eax");
}

void CNWSObject::BroadcastCounterSpellData(CNWSpell *, CNWCCMessageData *)
{
    asm("leave");
    asm("mov $0x081d1cd4, %eax");
    asm("jmp *%eax");
}

void CNWSObject::BroadcastDialog(CExoString, float)
{
    asm("leave");
    asm("mov $0x081d1604, %eax");
    asm("jmp *%eax");
}

void CNWSObject::BroadcastFloatyDataSTRREF(unsigned long)
{
    asm("leave");
    asm("mov $0x081d5340, %eax");
    asm("jmp *%eax");
}

void CNWSObject::BroadcastFloatyData(CNWCCMessageData *)
{
    asm("leave");
    asm("mov $0x081d5338, %eax");
    asm("jmp *%eax");
}

void CNWSObject::BroadcastSafeProjectile(unsigned long, unsigned long, Vector, Vector, unsigned long, unsigned char, unsigned long, unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x081d2390, %eax");
    asm("jmp *%eax");
}

void CNWSObject::BroadcastSpellData(CNWSpell *, CNWCCMessageData *)
{
    asm("leave");
    asm("mov $0x081d1fec, %eax");
    asm("jmp *%eax");
}

void CNWSObject::CalculateLastSpellProjectileTime(unsigned char)
{
    asm("leave");
    asm("mov $0x081d2cec, %eax");
    asm("jmp *%eax");
}

Vector CNWSObject::CalculateSpellRangedMissTarget(unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x081d2f9c, %eax");
    asm("jmp *%eax");
}

int CNWSObject::ClearAction(CNWSObjectActionNode *, int)
{
    asm("leave");
    asm("mov $0x081d585c, %eax");
    asm("jmp *%eax");
}

void CNWSObject::ClearAllActions()
{
    asm("leave");
    asm("mov $0x081cb77c, %eax");
    asm("jmp *%eax");
}

void CNWSObject::ClearAllPartyInvalidActions()
{
    asm("leave");
    asm("mov $0x081cb908, %eax");
    asm("jmp *%eax");
}

void CNWSObject::ClearMatchedExpressionStrings()
{
    asm("leave");
    asm("mov $0x081d52b0, %eax");
    asm("jmp *%eax");
}

void CNWSObject::ClearSpellEffectsOnOthers()
{
    asm("leave");
    asm("mov $0x081cff48, %eax");
    asm("jmp *%eax");
}

void CNWSObject::CopyScriptVars(CNWSScriptVarTable *)
{
    asm("leave");
    asm("mov $0x081c9638, %eax");
    asm("jmp *%eax");
}

void CNWSObject::DeleteCurrentAIAction()
{
    asm("leave");
    asm("mov $0x081cb678, %eax");
    asm("jmp *%eax");
}

int CNWSObject::DoDamageImmunity(CNWSCreature *, int, unsigned short, int, int)
{
    asm("leave");
    asm("mov $0x081cdc4c, %eax");
    asm("jmp *%eax");
}

int CNWSObject::DoDamageReduction(CNWSCreature *, int, unsigned char, int, int)
{
    asm("leave");
    asm("mov $0x081cbd74, %eax");
    asm("jmp *%eax");
}

int CNWSObject::DoDamageResistance(CNWSCreature *, int, unsigned short, int, int, int)
{
    asm("leave");
    asm("mov $0x081cc7bc, %eax");
    asm("jmp *%eax");
}

void CNWSObject::DoDamage(int)
{
    asm("leave");
    asm("mov $0x081d4d20, %eax");
    asm("jmp *%eax");
}

int CNWSObject::DoSpellImmunity(CNWSObject *)
{
    asm("leave");
    asm("mov $0x081ce490, %eax");
    asm("jmp *%eax");
}

int CNWSObject::DoSpellLevelAbsorption(CNWSObject *)
{
    asm("leave");
    asm("mov $0x081cdfbc, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetAILevel()
{
    asm("leave");
    asm("mov $0x081d5868, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetAILock()
{
    asm("leave");
    asm("mov $0x081d5874, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetAIPosList()
{
    asm("leave");
    asm("mov $0x081d5880, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSObject::GetAIStateReaction(unsigned long)
{
    asm("leave");
    asm("mov $0x081c8154, %eax");
    asm("jmp *%eax");
}

unsigned short CNWSObject::GetAQActionIDByID(unsigned short, int)
{
    asm("leave");
    asm("mov $0x081c2d50, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetAcceptableAction(unsigned long)
{
    asm("leave");
    asm("mov $0x081c83a8, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetActionByGroupId(unsigned short, CNWSObjectActionNode **)
{
    asm("leave");
    asm("mov $0x081d4770, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetAnimationSpeed()
{
    asm("leave");
    asm("mov $0x081d589c, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetAnimation()
{
    asm("leave");
    asm("mov $0x081d588c, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetAppliedEffects()
{
    asm("leave");
    asm("mov $0x081d5b04, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetApplyingPostProcessEffects()
{
    asm("leave");
    asm("mov $0x081d62e4, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetAreaId()
{
    asm("leave");
    asm("mov $0x081d60b0, %eax");
    asm("jmp *%eax");
}

CNWSArea * CNWSObject::GetArea()
{
    asm("leave");
    asm("mov $0x081d5028, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetBaseHitPoints()
{
    asm("leave");
    asm("mov $0x081d5a88, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetConversationPlayHello()
{
    asm("leave");
    asm("mov $0x081d5ccc, %eax");
    asm("jmp *%eax");
}

short CNWSObject::GetCurrentHitPoints(int)
{
    asm("leave");
    asm("mov $0x081d4cf8, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetCustomScriptEventId()
{
    asm("leave");
    asm("mov $0x081d5fb0, %eax");
    asm("jmp *%eax");
}

char CNWSObject::GetDamageImmunityByFlags(unsigned short)
{
    asm("leave");
    asm("mov $0x081cdea4, %eax");
    asm("jmp *%eax");
}

char CNWSObject::GetDamageImmunity(unsigned char)
{
    asm("leave");
    asm("mov $0x081d4d50, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSObject::GetDamageLevel()
{
    asm("leave");
    asm("mov $0x081ce6c8, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetDead()
{
    asm("leave");
    asm("mov $0x081d1c10, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetDialogInterruptable()
{
    asm("leave");
    asm("mov $0x081d5a40, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetDialogOwner()
{
    asm("leave");
    asm("mov $0x081d59e4, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetDialogPrivate()
{
    asm("leave");
    asm("mov $0x081d5980, %eax");
    asm("jmp *%eax");
}

CResRef CNWSObject::GetDialogResref()
{
    asm("leave");
    asm("mov $0x081d5a1c, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetDialogValid()
{
    asm("leave");
    asm("mov $0x081d596c, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetEffectArrayIndex()
{
    asm("leave");
    asm("mov $0x081d62c0, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSObject::GetEffectSpellId()
{
    asm("leave");
    asm("mov $0x081d5bbc, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetEffectTargets()
{
    asm("leave");
    asm("mov $0x081d5b5c, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetExecutingAIAction()
{
    asm("leave");
    asm("mov $0x081d5ad0, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetExpressionStrings()
{
    asm("leave");
    asm("mov $0x081d5ed8, %eax");
    asm("jmp *%eax");
}

CExoLocString & CNWSObject::GetFirstName()
{
    asm("leave");
    asm("mov $0x081d5a4c, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSObject::GetGender()
{
    asm("leave");
    asm("mov $0x081d509c, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetHasFeatEffectApplied(unsigned short)
{
    asm("leave");
    asm("mov $0x081d56c0, %eax");
    asm("jmp *%eax");
}

unsigned short CNWSObject::GetIDByAQActionID(unsigned short)
{
    asm("leave");
    asm("mov $0x081c305c, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetInventoryDisturbItem()
{
    asm("leave");
    asm("mov $0x081d5e38, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetInventoryDisturbType()
{
    asm("leave");
    asm("mov $0x081d5e14, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetIsDestroyable()
{
    asm("leave");
    asm("mov $0x081d5ff8, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetIsPCDying()
{
    asm("leave");
    asm("mov $0x081d5498, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetIsRaiseable()
{
    asm("leave");
    asm("mov $0x081d601c, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetKiller()
{
    asm("leave");
    asm("mov $0x081d5d04, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetLastAttackMode()
{
    asm("leave");
    asm("mov $0x081d5da8, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetLastAttackType()
{
    asm("leave");
    asm("mov $0x081d5d84, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetLastAttacker()
{
    asm("leave");
    asm("mov $0x081d5d14, %eax");
    asm("jmp *%eax");
}

CExoString CNWSObject::GetLastConversationResref()
{
    asm("leave");
    asm("mov $0x081d5c28, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetLastDamageAmountByFlags(int)
{
    asm("leave");
    asm("mov $0x081d4ddc, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetLastDamager()
{
    asm("leave");
    asm("mov $0x081d5d4c, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetLastDisturbed()
{
    asm("leave");
    asm("mov $0x081d5df0, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetLastGroupID()
{
    asm("leave");
    asm("mov $0x081d5850, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetLastHostileActor()
{
    asm("leave");
    asm("mov $0x081d5d74, %eax");
    asm("jmp *%eax");
}

CExoLocString & CNWSObject::GetLastName()
{
    asm("leave");
    asm("mov $0x081d5a58, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetLastSpeaker()
{
    asm("leave");
    asm("mov $0x081d5c04, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetLastSpellCastAtMeCaster()
{
    asm("leave");
    asm("mov $0x081d6160, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetLastSpellCastAtMeHarmful()
{
    asm("leave");
    asm("mov $0x081d6180, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetLastSpellCastAtMe()
{
    asm("leave");
    asm("mov $0x081d6170, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetLastSpellCastDomainLevel()
{
    asm("leave");
    asm("mov $0x081d60ec, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetLastSpellCastFeat()
{
    asm("leave");
    asm("mov $0x081d6190, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetLastSpellCastMetaType()
{
    asm("leave");
    asm("mov $0x081d6150, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetLastSpellCastMulticlass()
{
    asm("leave");
    asm("mov $0x081d60cc, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetLastSpellCastSpontaneous()
{
    asm("leave");
    asm("mov $0x081d6140, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetLastSpellCast()
{
    asm("leave");
    asm("mov $0x081d6130, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetLastSpellId()
{
    asm("leave");
    asm("mov $0x081d60dc, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetLastSpellLocationTarget()
{
    asm("leave");
    asm("mov $0x081d610c, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetLastSpellObjectTarget()
{
    asm("leave");
    asm("mov $0x081d60fc, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetLastWeaponAttackedWith()
{
    asm("leave");
    asm("mov $0x081d5dcc, %eax");
    asm("jmp *%eax");
}

CNWSExpression * CNWSObject::GetListenExpressionObj(int)
{
    asm("leave");
    asm("mov $0x081d51fc, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetListenExpressions()
{
    asm("leave");
    asm("mov $0x081d5ec8, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSObject::GetLockOrientationToObject()
{
    asm("leave");
    asm("mov $0x081d5fdc, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetLoopingVisualEffects()
{
    asm("leave");
    asm("mov $0x081d5bd0, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetMatchedPos()
{
    asm("leave");
    asm("mov $0x081d5ea4, %eax");
    asm("jmp *%eax");
}

short CNWSObject::GetMaxHitPoints(int)
{
    asm("leave");
    asm("mov $0x081d5a64, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetMaximumDamageResistanceVsDamageFlag(unsigned short, int *)
{
    asm("leave");
    asm("mov $0x081cdb30, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSObject::GetNearestObjectByName(CExoString const &, float)
{
    asm("leave");
    asm("mov $0x081d103c, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetNewGroupID()
{
    asm("leave");
    asm("mov $0x081d49bc, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetNodeById(unsigned short, unsigned short)
{
    asm("leave");
    asm("mov $0x081d48a8, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetNumActionGroups()
{
    asm("leave");
    asm("mov $0x081d492c, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetObjectToDialog()
{
    asm("leave");
    asm("mov $0x081d59b8, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetOpenDoorAnimationPlayed()
{
    asm("leave");
    asm("mov $0x081d62b0, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetOrientation()
{
    asm("leave");
    asm("mov $0x081d58ac, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetPendingEffectRemoval()
{
    asm("leave");
    asm("mov $0x081d5b28, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetPlotObject()
{
    asm("leave");
    asm("mov $0x081d5e5c, %eax");
    asm("jmp *%eax");
}

unsigned short CNWSObject::GetPortraitId()
{
    asm("leave");
    asm("mov $0x081d60a4, %eax");
    asm("jmp *%eax");
}

CResRef CNWSObject::GetPortrait()
{
    asm("leave");
    asm("mov $0x081d6064, %eax");
    asm("jmp *%eax");
}

CExoLinkedListNode * CNWSObject::GetPositionByGroupIndex(int)
{
    asm("leave");
    asm("mov $0x081d481c, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetPosition()
{
    asm("leave");
    asm("mov $0x081d58d0, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetPrivateConversation()
{
    asm("leave");
    asm("mov $0x081d5ca8, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetQueuedActionsList()
{
    asm("leave");
    asm("mov $0x081d5840, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetReputation(unsigned long, int &, int)
{
    asm("leave");
    asm("mov $0x081c7e5c, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetSavingThrowSpellId()
{
    asm("leave");
    asm("mov $0x081d5b38, %eax");
    asm("jmp *%eax");
}

CScriptLocation CNWSObject::GetScriptLocation()
{
    asm("leave");
    asm("mov $0x081d1b90, %eax");
    asm("jmp *%eax");
}

CNWSScriptVarTable * CNWSObject::GetScriptVarTable()
{
    asm("leave");
    asm("mov $0x081d5af4, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetSelectableWhenDead()
{
    asm("leave");
    asm("mov $0x081d6040, %eax");
    asm("jmp *%eax");
}

CExoString * CNWSObject::GetTag()
{
    asm("leave");
    asm("mov $0x081d5f80, %eax");
    asm("jmp *%eax");
}

CExoString * CNWSObject::GetTemplate()
{
    asm("leave");
    asm("mov $0x081d5f8c, %eax");
    asm("jmp *%eax");
}

int CNWSObject::GetTemporaryHitPoints()
{
    asm("leave");
    asm("mov $0x081d5aac, %eax");
    asm("jmp *%eax");
}

int CNWSObject::HasSpellEffectApplied(unsigned long)
{
    asm("leave");
    asm("mov $0x081d53dc, %eax");
    asm("jmp *%eax");
}

int CNWSObject::IsAbleToModifyActionQueue()
{
    asm("leave");
    asm("mov $0x081d5bf4, %eax");
    asm("jmp *%eax");
}

int CNWSObject::IsDialogDelay()
{
    asm("leave");
    asm("mov $0x081d50a8, %eax");
    asm("jmp *%eax");
}

int CNWSObject::IsDialogPaused()
{
    asm("leave");
    asm("mov $0x081d59f0, %eax");
    asm("jmp *%eax");
}

int CNWSObject::IsListening()
{
    asm("leave");
    asm("mov $0x081d5e94, %eax");
    asm("jmp *%eax");
}

int CNWSObject::IsPCInDialog()
{
    asm("leave");
    asm("mov $0x081d5998, %eax");
    asm("jmp *%eax");
}

void CNWSObject::LoadActionQueue(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x081c98bc, %eax");
    asm("jmp *%eax");
}

void CNWSObject::LoadEffectList(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x081ca0a0, %eax");
    asm("jmp *%eax");
}

void CNWSObject::LoadListenData(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x081ca264, %eax");
    asm("jmp *%eax");
}

void CNWSObject::LoadObjectState(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x081d4b40, %eax");
    asm("jmp *%eax");
}

void CNWSObject::LoadVarTable(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x081d4bc0, %eax");
    asm("jmp *%eax");
}

void CNWSObject::PlaySoundSet(CNWSPlayer *, unsigned char)
{
    asm("leave");
    asm("mov $0x081d1384, %eax");
    asm("jmp *%eax");
}

void CNWSObject::RemoveEffectByCreator(unsigned long)
{
    asm("leave");
    asm("mov $0x081d4f44, %eax");
    asm("jmp *%eax");
}

int CNWSObject::RemoveEffectById(unsigned long long)
{
    asm("leave");
    asm("mov $0x081ceea0, %eax");
    asm("jmp *%eax");
}

int CNWSObject::RemoveEffectBySpellId(unsigned long)
{
    asm("leave");
    asm("mov $0x081d5434, %eax");
    asm("jmp *%eax");
}

void CNWSObject::RemoveEffectTarget(unsigned long)
{
    asm("leave");
    asm("mov $0x081cfe84, %eax");
    asm("jmp *%eax");
}

void CNWSObject::RemoveEffect(CGameEffect *)
{
    asm("leave");
    asm("mov $0x081cedb8, %eax");
    asm("jmp *%eax");
}

void CNWSObject::RemoveGroup(unsigned short)
{
    asm("leave");
    asm("mov $0x081c91ec, %eax");
    asm("jmp *%eax");
}

void CNWSObject::RemoveLoopingVisualEffect(unsigned short)
{
    asm("leave");
    asm("mov $0x081d4ee0, %eax");
    asm("jmp *%eax");
}

int CNWSObject::RemoveObjectFromDialog(unsigned long)
{
    asm("leave");
    asm("mov $0x081d0f8c, %eax");
    asm("jmp *%eax");
}

void CNWSObject::RemoveSomeEffectsOfDurationType(unsigned short)
{
    asm("leave");
    asm("mov $0x081d4fb0, %eax");
    asm("jmp *%eax");
}

int CNWSObject::ReplyDialog(unsigned long, unsigned long, int, unsigned long)
{
    asm("leave");
    asm("mov $0x081d5104, %eax");
    asm("jmp *%eax");
}

void CNWSObject::ReportOverflow(int, int, int, int)
{
    asm("leave");
    asm("mov $0x081d3ea4, %eax");
    asm("jmp *%eax");
}

int CNWSObject::RunActions(unsigned long, unsigned long, unsigned long long)
{
    asm("leave");
    asm("mov $0x081c213c, %eax");
    asm("jmp *%eax");
}

int CNWSObject::RunDialogOneLiner(CExoString const &, unsigned long)
{
    asm("leave");
    asm("mov $0x081d05cc, %eax");
    asm("jmp *%eax");
}

void CNWSObject::SaveActionQueue(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x081c9e44, %eax");
    asm("jmp *%eax");
}

void CNWSObject::SaveEffectList(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x081ca198, %eax");
    asm("jmp *%eax");
}

void CNWSObject::SaveListenData(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x081d4bf0, %eax");
    asm("jmp *%eax");
}

void CNWSObject::SaveObjectState(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x081d4b80, %eax");
    asm("jmp *%eax");
}

void CNWSObject::SaveVarTable(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x081d4bd8, %eax");
    asm("jmp *%eax");
}

int CNWSObject::SendDialogEntry(unsigned long, int)
{
    asm("leave");
    asm("mov $0x081d0a4c, %eax");
    asm("jmp *%eax");
}

int CNWSObject::SendDialogReplies()
{
    asm("leave");
    asm("mov $0x081d0b4c, %eax");
    asm("jmp *%eax");
}

int CNWSObject::SetAILevel(int)
{
    asm("leave");
    asm("mov $0x081d58f0, %eax");
    asm("jmp *%eax");
}

int CNWSObject::SetAILock(int)
{
    asm("leave");
    asm("mov $0x081d5900, %eax");
    asm("jmp *%eax");
}

int CNWSObject::SetAIPosList(CExoLinkedListNode *)
{
    asm("leave");
    asm("mov $0x081d5910, %eax");
    asm("jmp *%eax");
}

int CNWSObject::SetAbleToModifyActionQueue(int)
{
    asm("leave");
    asm("mov $0x081d5be0, %eax");
    asm("jmp *%eax");
}

int CNWSObject::SetAnimationSpeed(float)
{
    asm("leave");
    asm("mov $0x081d5920, %eax");
    asm("jmp *%eax");
}

void CNWSObject::SetAnimation(int)
{
    asm("leave");
    asm("mov $0x081d4ce4, %eax");
    asm("jmp *%eax");
}

int CNWSObject::SetApplyingPostProcessEffects(int)
{
    asm("leave");
    asm("mov $0x081d62f4, %eax");
    asm("jmp *%eax");
}

int CNWSObject::SetAreaId(unsigned long)
{
    asm("leave");
    asm("mov $0x081d60bc, %eax");
    asm("jmp *%eax");
}

void CNWSObject::SetArea(CNWSArea *)
{
    asm("leave");
    asm("mov $0x081d5078, %eax");
    asm("jmp *%eax");
}

int CNWSObject::SetBaseHitPoints(int)
{
    asm("leave");
    asm("mov $0x081d5a98, %eax");
    asm("jmp *%eax");
}

int CNWSObject::SetConversationPlayHello(int)
{
    asm("leave");
    asm("mov $0x081d5cdc, %eax");
    asm("jmp *%eax");
}

int CNWSObject::SetCurrentActionTarget(unsigned long)
{
    asm("leave");
    asm("mov $0x081d5fe8, %eax");
    asm("jmp *%eax");
}

int CNWSObject::SetCurrentHitPoints(int)
{
    asm("leave");
    asm("mov $0x081d5a74, %eax");
    asm("jmp *%eax");
}

int CNWSObject::SetCustomScriptEventId(int)
{
    asm("leave");
    asm("mov $0x081d5fc0, %eax");
    asm("jmp *%eax");
}

void CNWSObject::SetDamageImmunity(unsigned short, int)
{
    asm("leave");
    asm("mov $0x081d4d84, %eax");
    asm("jmp *%eax");
}

int CNWSObject::SetDialogAnimation(int)
{
    asm("leave");
    asm("mov $0x081d5a0c, %eax");
    asm("jmp *%eax");
}

void CNWSObject::SetDialogDelay(float)
{
    asm("leave");
    asm("mov $0x081d0104, %eax");
    asm("jmp *%eax");
}

void CNWSObject::SetDialogOwner(unsigned long)
{
    asm("leave");
    asm("mov $0x081d51ac, %eax");
    asm("jmp *%eax");
}

int CNWSObject::SetDialogPaused(int)
{
    asm("leave");
    asm("mov $0x081d59fc, %eax");
    asm("jmp *%eax");
}

int CNWSObject::SetEffectArrayIndex(unsigned short)
{
    asm("leave");
    asm("mov $0x081d62d0, %eax");
    asm("jmp *%eax");
}

void CNWSObject::SetEffectSpellId(unsigned long)
{
    asm("leave");
    asm("mov $0x081d5bc8, %eax");
    asm("jmp *%eax");
}

int CNWSObject::SetExecutingAIAction(CNWSObjectActionNode *)
{
    asm("leave");
    asm("mov $0x081d5ae0, %eax");
    asm("jmp *%eax");
}

void CNWSObject::SetGroupInterruptable(unsigned short, int)
{
    asm("leave");
    asm("mov $0x081d4aa4, %eax");
    asm("jmp *%eax");
}

int CNWSObject::SetInventoryDisturbItem(unsigned long)
{
    asm("leave");
    asm("mov $0x081d5e48, %eax");
    asm("jmp *%eax");
}

int CNWSObject::SetInventoryDisturbType(int)
{
    asm("leave");
    asm("mov $0x081d5e24, %eax");
    asm("jmp *%eax");
}

int CNWSObject::SetIsDestroyable(int)
{
    asm("leave");
    asm("mov $0x081d6008, %eax");
    asm("jmp *%eax");
}

int CNWSObject::SetIsRaiseable(int)
{
    asm("leave");
    asm("mov $0x081d602c, %eax");
    asm("jmp *%eax");
}

int CNWSObject::SetKiller(unsigned long)
{
    asm("leave");
    asm("mov $0x081d5cf0, %eax");
    asm("jmp *%eax");
}

int CNWSObject::SetLastAnimationTimes(unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x081d5934, %eax");
    asm("jmp *%eax");
}

int CNWSObject::SetLastAttackMode(unsigned char)
{
    asm("leave");
    asm("mov $0x081d5db8, %eax");
    asm("jmp *%eax");
}

int CNWSObject::SetLastAttackType(unsigned short)
{
    asm("leave");
    asm("mov $0x081d5d94, %eax");
    asm("jmp *%eax");
}

int CNWSObject::SetLastAttacker(unsigned long)
{
    asm("leave");
    asm("mov $0x081d5d24, %eax");
    asm("jmp *%eax");
}

void CNWSObject::SetLastConversationResref(CExoString)
{
    asm("leave");
    asm("mov $0x081d5c50, %eax");
    asm("jmp *%eax");
}

int CNWSObject::SetLastDamageAmount(int, int)
{
    asm("leave");
    asm("mov $0x081d5d5c, %eax");
    asm("jmp *%eax");
}

int CNWSObject::SetLastDamager(unsigned long)
{
    asm("leave");
    asm("mov $0x081d5d38, %eax");
    asm("jmp *%eax");
}

int CNWSObject::SetLastDisturbed(unsigned long)
{
    asm("leave");
    asm("mov $0x081d5e00, %eax");
    asm("jmp *%eax");
}

int CNWSObject::SetLastGroupID(unsigned short)
{
    asm("leave");
    asm("mov $0x081d6308, %eax");
    asm("jmp *%eax");
}

void CNWSObject::SetLastHostileActor(unsigned long, int)
{
    asm("leave");
    asm("mov $0x081d40a0, %eax");
    asm("jmp *%eax");
}

int CNWSObject::SetLastSpeaker(unsigned long)
{
    asm("leave");
    asm("mov $0x081d5c14, %eax");
    asm("jmp *%eax");
}

int CNWSObject::SetLastSpellCastAtMeCaster(unsigned long)
{
    asm("leave");
    asm("mov $0x081d624c, %eax");
    asm("jmp *%eax");
}

int CNWSObject::SetLastSpellCastAtMeHarmful(int)
{
    asm("leave");
    asm("mov $0x081d6274, %eax");
    asm("jmp *%eax");
}

int CNWSObject::SetLastSpellCastAtMe(unsigned long)
{
    asm("leave");
    asm("mov $0x081d6260, %eax");
    asm("jmp *%eax");
}

int CNWSObject::SetLastSpellCastDomainLevel(unsigned char)
{
    asm("leave");
    asm("mov $0x081d61c8, %eax");
    asm("jmp *%eax");
}

int CNWSObject::SetLastSpellCastFeat(unsigned short)
{
    asm("leave");
    asm("mov $0x081d6288, %eax");
    asm("jmp *%eax");
}

int CNWSObject::SetLastSpellCastMetaType(unsigned char)
{
    asm("leave");
    asm("mov $0x081d6238, %eax");
    asm("jmp *%eax");
}

int CNWSObject::SetLastSpellCastMulticlass(unsigned char)
{
    asm("leave");
    asm("mov $0x081d61a0, %eax");
    asm("jmp *%eax");
}

int CNWSObject::SetLastSpellCastSpontaneous(int)
{
    asm("leave");
    asm("mov $0x081d6224, %eax");
    asm("jmp *%eax");
}

int CNWSObject::SetLastSpellCast(int)
{
    asm("leave");
    asm("mov $0x081d6210, %eax");
    asm("jmp *%eax");
}

int CNWSObject::SetLastSpellId(unsigned long)
{
    asm("leave");
    asm("mov $0x081d61b4, %eax");
    asm("jmp *%eax");
}

int CNWSObject::SetLastSpellLocationTarget(Vector)
{
    asm("leave");
    asm("mov $0x081d61f0, %eax");
    asm("jmp *%eax");
}

int CNWSObject::SetLastSpellObjectTarget(unsigned long)
{
    asm("leave");
    asm("mov $0x081d61dc, %eax");
    asm("jmp *%eax");
}

int CNWSObject::SetLastWeaponAttackedWith(unsigned long)
{
    asm("leave");
    asm("mov $0x081d5ddc, %eax");
    asm("jmp *%eax");
}

int CNWSObject::SetListenExpression(CExoString, int)
{
    asm("leave");
    asm("mov $0x081d1438, %eax");
    asm("jmp *%eax");
}

int CNWSObject::SetListening(int)
{
    asm("leave");
    asm("mov $0x081d5e80, %eax");
    asm("jmp *%eax");
}

void CNWSObject::SetLockOrientationToObject(unsigned long)
{
    asm("leave");
    asm("mov $0x081d5fd4, %eax");
    asm("jmp *%eax");
}

int CNWSObject::SetMatchedPos(int)
{
    asm("leave");
    asm("mov $0x081d5eb4, %eax");
    asm("jmp *%eax");
}

int CNWSObject::SetOpenDoorAnimationPlayed(int)
{
    asm("leave");
    asm("mov $0x081d629c, %eax");
    asm("jmp *%eax");
}

void CNWSObject::SetOrientation(Vector)
{
    asm("leave");
    asm("mov $0x081d4e10, %eax");
    asm("jmp *%eax");
}

int CNWSObject::SetPendingEffectRemoval(int)
{
    asm("leave");
    asm("mov $0x081d5b14, %eax");
    asm("jmp *%eax");
}

int CNWSObject::SetPlotObject(int)
{
    asm("leave");
    asm("mov $0x081d5e6c, %eax");
    asm("jmp *%eax");
}

void CNWSObject::SetPortraitId(unsigned short)
{
    asm("leave");
    asm("mov $0x081ca41c, %eax");
    asm("jmp *%eax");
}

void CNWSObject::SetPortrait(CResRef)
{
    asm("leave");
    asm("mov $0x081d6084, %eax");
    asm("jmp *%eax");
}

void CNWSObject::SetPosition(Vector, int)
{
    asm("leave");
    asm("mov $0x081d4e30, %eax");
    asm("jmp *%eax");
}

int CNWSObject::SetPrivateConversation(int)
{
    asm("leave");
    asm("mov $0x081d5cb8, %eax");
    asm("jmp *%eax");
}

int CNWSObject::SetSavingThrowSpellId(unsigned long)
{
    asm("leave");
    asm("mov $0x081d5b48, %eax");
    asm("jmp *%eax");
}

int CNWSObject::SetSelectableWhenDead(int)
{
    asm("leave");
    asm("mov $0x081d6050, %eax");
    asm("jmp *%eax");
}

int CNWSObject::SetStartActionTimer(unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x081d5950, %eax");
    asm("jmp *%eax");
}

void CNWSObject::SetTag(CExoString)
{
    asm("leave");
    asm("mov $0x081d5ee8, %eax");
    asm("jmp *%eax");
}

int CNWSObject::SetTemplate(CExoString const &)
{
    asm("leave");
    asm("mov $0x081d5f98, %eax");
    asm("jmp *%eax");
}

int CNWSObject::SetTemporaryHitPoints(int)
{
    asm("leave");
    asm("mov $0x081d5abc, %eax");
    asm("jmp *%eax");
}

void CNWSObject::SpawnBodyBag()
{
    asm("leave");
    asm("mov $0x081d3aa8, %eax");
    asm("jmp *%eax");
}

void CNWSObject::SpellCastAndImpact(unsigned long, Vector, unsigned long, unsigned char, unsigned long, int, int, unsigned char, int)
{
    asm("leave");
    asm("mov $0x081d261c, %eax");
    asm("jmp *%eax");
}

int CNWSObject::StartDialog(unsigned long, CExoString const &, int, int)
{
    asm("leave");
    asm("mov $0x081d0198, %eax");
    asm("jmp *%eax");
}

int CNWSObject::StopDialog()
{
    asm("leave");
    asm("mov $0x081d0e8c, %eax");
    asm("jmp *%eax");
}

int CNWSObject::TerminateAISliceAfterAction(unsigned long)
{
    asm("leave");
    asm("mov $0x081c8380, %eax");
    asm("jmp *%eax");
}

int CNWSObject::TestActionList()
{
    asm("leave");
    asm("mov $0x081d4afc, %eax");
    asm("jmp *%eax");
}

int CNWSObject::TestListenExpression(CExoString)
{
    asm("leave");
    asm("mov $0x081d1540, %eax");
    asm("jmp *%eax");
}

void CNWSObject::UpdateAttributesOnEffect(CGameEffect *, int)
{
    asm("leave");
    asm("mov $0x081d6320, %eax");
    asm("jmp *%eax");
}

int CNWSObject::UpdateDialog()
{
    asm("leave");
    asm("mov $0x081d0c38, %eax");
    asm("jmp *%eax");
}

void CNWSObject::UpdateEffectList(unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x081cf014, %eax");
    asm("jmp *%eax");
}

void CNWSObject::UpdateEffectPtrs()
{
    asm("leave");
    asm("mov $0x081d6318, %eax");
    asm("jmp *%eax");
}

