#include "CNWSMessage.h"

void CNWSMessage::AddActiveItemPropertiesToMessage(CNWSItem *, CNWSCreature *)
{
    asm("leave");
    asm("mov $0x08061f24, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::AddAreaOfEffectObjectToMessage(CNWSAreaOfEffectObject *)
{
    asm("leave");
    asm("mov $0x0807efe0, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::AddDoorAppearanceToMessage(CNWSDoor *)
{
    asm("leave");
    asm("mov $0x0807efa0, %eax");
    asm("jmp *%eax");
}

void CNWSMessage::AddItemAppearanceToMessage(CNWSItem *)
{
    asm("leave");
    asm("mov $0x080621b8, %eax");
    asm("jmp *%eax");
}

void CNWSMessage::AddPlaceableAppearanceToMessage(CNWSPlaceable *)
{
    asm("leave");
    asm("mov $0x08061dc8, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::AddTriggerGeometryToMessage(CNWSTrigger *)
{
    asm("leave");
    asm("mov $0x08080508, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::AssignCreatureLists(CExoArrayList<unsigned long> *, CExoArrayList<unsigned long> *)
{
    asm("leave");
    asm("mov $0x0807f078, %eax");
    asm("jmp *%eax");
}

void CNWSMessage::AssignVisualEffectLists(CExoArrayList<CLoopingVisualEffect *> *, CExoArrayList<CLoopingVisualEffect *> *)
{
    asm("leave");
    asm("mov $0x080625cc, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::CompareCreatureLists(CExoArrayList<unsigned long> *, CExoArrayList<unsigned long> *)
{
    asm("leave");
    asm("mov $0x0807f020, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::CompareVisualEffectLists(CExoArrayList<CLoopingVisualEffect *> *, CExoArrayList<CLoopingVisualEffect *> *)
{
    asm("leave");
    asm("mov $0x080626ac, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSMessage::ComputeAppearanceUpdateRequired(CNWSObject *, CLastUpdateObject *)
{
    asm("leave");
    asm("mov $0x08062330, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::ComputeGameObjectUpdateForCategory(unsigned long, unsigned long, CNWSPlayer *, CNWSObject *, CGameObjectArray *, CNWSPlayerLUOSortedObjectList *, int)
{
    asm("leave");
    asm("mov $0x0806b1e8, %eax");
    asm("jmp *%eax");
}

void CNWSMessage::ComputeGameObjectUpdateForObject(CNWSPlayer *, CNWSObject *, CGameObjectArray *, unsigned long)
{
    asm("leave");
    asm("mov $0x0808028c, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::ComputeGameObjectUpdateForYourselfToo(CNWSPlayer *, CNWSObject *, CGameObjectArray *, unsigned long)
{
    asm("leave");
    asm("mov $0x08080230, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::ComputeGameObjectUpdateForYourself(CNWSPlayer *, CNWSObject *, CGameObjectArray *, unsigned long)
{
    asm("leave");
    asm("mov $0x0808027c, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::ComputeInventoryUpdateRequired(CNWSPlayer *, unsigned long, CNWSPlayerInventoryGUI *)
{
    asm("leave");
    asm("mov $0x080624a8, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::ComputeLastUpdate_ActionQueue(CNWSCreature *, CNWSPlayerLastUpdateObject *)
{
    asm("leave");
    asm("mov $0x08064a08, %eax");
    asm("jmp *%eax");
}

unsigned short CNWSMessage::ComputeLastUpdate_AssociateState(CNWSCreature *)
{
    asm("leave");
    asm("mov $0x08064d8c, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::ComputeLastUpdate_AutoMap(CNWSCreature *, CNWSPlayerLastUpdateObject *)
{
    asm("leave");
    asm("mov $0x08064ab0, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::ComputeLastUpdate_CompareSpellLikeAbility(CNWSCreature *, CNWSPlayerLastUpdateObject *)
{
    asm("leave");
    asm("mov $0x08064420, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::ComputeLastUpdate_GuiEffectIcons(CNWSCreature *, CExoArrayList<CEffectIconObject *> *, int)
{
    asm("leave");
    asm("mov $0x080827b0, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::ComputeLastUpdate_GuiFeats(CNWSCreature *, CNWSPlayerLastUpdateObject *)
{
    asm("leave");
    asm("mov $0x08063e60, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::ComputeLastUpdate_GuiKnownSpellUses(CNWSCreature *, CNWSPlayerLastUpdateObject *)
{
    asm("leave");
    asm("mov $0x080646b8, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::ComputeLastUpdate_GuiKnownSpells(CNWSCreature *, CNWSPlayerLastUpdateObject *)
{
    asm("leave");
    asm("mov $0x0806400c, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::ComputeLastUpdate_GuiMemorizedSpells(CNWSCreature *, CNWSPlayerLastUpdateObject *)
{
    asm("leave");
    asm("mov $0x080641ac, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::ComputeLastUpdate_GuiNumberMemorizedSpells(CNWSCreature *, CNWSPlayerLastUpdateObject *)
{
    asm("leave");
    asm("mov $0x08064bac, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::ComputeLastUpdate_GuiSkills(CNWSCreature *)
{
    asm("leave");
    asm("mov $0x0807f0bc, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSMessage::ComputeLastUpdate_PlayerState(CNWSCreature *)
{
    asm("leave");
    asm("mov $0x08064c84, %eax");
    asm("jmp *%eax");
}

void CNWSMessage::ComputeLastUpdate_StoreUpdateSpellLikeAbility(CNWSCreature *, CNWSPlayerLastUpdateObject *)
{
    asm("leave");
    asm("mov $0x080645f0, %eax");
    asm("jmp *%eax");
}

void CNWSMessage::ComputeLastUpdate_WriteSpellLikeAbility(CNWSCreature *, CNWSPlayerLastUpdateObject *)
{
    asm("leave");
    asm("mov $0x080644bc, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSMessage::ComputeNumAutoMapUpdatesRequired(CNWSCreature *, CNWSPlayerLastUpdateObject *, unsigned long *)
{
    asm("leave");
    asm("mov $0x08064830, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::ComputeQuickbarItemUseCountUpdateRequired(CNWSObject *, CLastUpdateObject *)
{
    asm("leave");
    asm("mov $0x0807e6b0, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::ComputeRepositoryUpdateRequired(CNWSPlayer *, CExoLinkedListNode *, CExoLinkedListNode *)
{
    asm("leave");
    asm("mov $0x0807f014, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSMessage::ComputeUpdateRequired(CNWSPlayer *, CNWSObject *, CLastUpdateObject *, int)
{
    asm("leave");
    asm("mov $0x080629d0, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::ComputeVisibilityLists(CNWSCreature *, CNWSPlayerLastUpdateObject *)
{
    asm("leave");
    asm("mov $0x080627dc, %eax");
    asm("jmp *%eax");
}

CLastUpdateObject * CNWSMessage::CreateNewLastUpdateObject(CNWSPlayer *, CNWSObject *, unsigned long *, unsigned long *)
{
    asm("leave");
    asm("mov $0x0806bcd8, %eax");
    asm("jmp *%eax");
}

void CNWSMessage::DeleteLastUpdateObjectsForObject(CNWSPlayer *, unsigned long)
{
    asm("leave");
    asm("mov $0x0806cea8, %eax");
    asm("jmp *%eax");
}

void CNWSMessage::DeleteLastUpdateObjectsInOtherAreas(CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x0806cc64, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::GetLocStringServer(unsigned long, CExoLocString, CExoLocString, CExoString &, float &, unsigned char)
{
    asm("leave");
    asm("mov $0x08052860, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::HandlePlayerToServerAreaMessage(CNWSPlayer *, unsigned char)
{
    asm("leave");
    asm("mov $0x08197630, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::HandlePlayerToServerBarter_AcceptTrade(CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x0819a9ac, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::HandlePlayerToServerBarter_AddItem(CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x0819a6bc, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::HandlePlayerToServerBarter_CloseBarter(CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x0819a5dc, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::HandlePlayerToServerBarter_LockList(CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x0819a920, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::HandlePlayerToServerBarter_MoveItem(CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x0819a850, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::HandlePlayerToServerBarter_RemoveItem(CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x0819a780, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::HandlePlayerToServerBarter_StartBarter(CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x0819bc10, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::HandlePlayerToServerBarter_Window(CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x0819aa38, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::HandlePlayerToServerBarter(CNWSPlayer *, unsigned char)
{
    asm("leave");
    asm("mov $0x0819a558, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::HandlePlayerToServerCharListMessage(CNWSPlayer *, unsigned char)
{
    asm("leave");
    asm("mov $0x08196cdc, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::HandlePlayerToServerCharacterDownload(CNWSPlayer *, unsigned char)
{
    asm("leave");
    asm("mov $0x0819bc94, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::HandlePlayerToServerCharacterSheetMessage(CNWSPlayer *, unsigned char)
{
    asm("leave");
    asm("mov $0x0818f7b0, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::HandlePlayerToServerChatMessage(CNWSPlayer *, unsigned char)
{
    asm("leave");
    asm("mov $0x081848c8, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::HandlePlayerToServerCheatMessage(CNWSPlayer *, unsigned char)
{
    asm("leave");
    asm("mov $0x08184eac, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::HandlePlayerToServerCutscene(CNWSPlayer *, unsigned char)
{
    asm("leave");
    asm("mov $0x0819b64c, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::HandlePlayerToServerDialogMessage(CNWSPlayer *, unsigned char)
{
    asm("leave");
    asm("mov $0x08188208, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::HandlePlayerToServerDungeonMasterMessage(CNWSPlayer *, unsigned char, int)
{
    asm("leave");
    asm("mov $0x081882e4, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::HandlePlayerToServerGameObjectUpdate(CNWSPlayer *, unsigned char)
{
    asm("leave");
    asm("mov $0x0818e910, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::HandlePlayerToServerGoldMessage(CNWSPlayer *, unsigned char)
{
    asm("leave");
    asm("mov $0x08190c14, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::HandlePlayerToServerGroupInputMessage(CNWSPlayer *, unsigned char)
{
    asm("leave");
    asm("mov $0x081934e8, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::HandlePlayerToServerGroupInputWalkToWaypoint(CNWSPlayer *, CNWSCreature *, unsigned long, float, float, float, unsigned char, int, int, unsigned long)
{
    asm("leave");
    asm("mov $0x081901f8, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::HandlePlayerToServerGuiContainerMessage(CNWSPlayer *, unsigned char)
{
    asm("leave");
    asm("mov $0x0818f66c, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::HandlePlayerToServerGuiInventoryMessage(CNWSPlayer *, unsigned char)
{
    asm("leave");
    asm("mov $0x0818f524, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::HandlePlayerToServerGuiQuickbar_SetButton(CNWSPlayer *, unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x08198f1c, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::HandlePlayerToServerGuiQuickbar(CNWSPlayer *, unsigned char)
{
    asm("leave");
    asm("mov $0x0819bb58, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::HandlePlayerToServerInputAbortDriveControl(CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x0818f9ec, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::HandlePlayerToServerInputCancelGuiTimingEvent(CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x0819bab8, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::HandlePlayerToServerInputDriveControl(CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x0818f8c0, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::HandlePlayerToServerInputMessage(CNWSPlayer *, unsigned char)
{
    asm("leave");
    asm("mov $0x08190d9c, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::HandlePlayerToServerInputWalkToWaypoint(CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x0818fa78, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::HandlePlayerToServerInventoryMessage(CNWSPlayer *, unsigned char)
{
    asm("leave");
    asm("mov $0x081952d8, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::HandlePlayerToServerJournalMessage(CNWSPlayer *, unsigned char)
{
    asm("leave");
    asm("mov $0x08198bb8, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::HandlePlayerToServerLevelUpMessage(CNWSPlayer *, unsigned char)
{
    asm("leave");
    asm("mov $0x08198654, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::HandlePlayerToServerLoginMessage(CNWSPlayer *, unsigned char)
{
    asm("leave");
    asm("mov $0x08195f98, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::HandlePlayerToServerMapPinChangePin(CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x0819a0e8, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::HandlePlayerToServerMapPinDestroyMapPin(CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x08199e8c, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::HandlePlayerToServerMapPinMessage(CNWSPlayer *, unsigned char)
{
    asm("leave");
    asm("mov $0x0819bbb8, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::HandlePlayerToServerMapPinSetMapPinAt(CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x0819995c, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::HandlePlayerToServerMessage(unsigned long, unsigned char *, unsigned long)
{
    asm("leave");
    asm("mov $0x08196544, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::HandlePlayerToServerModuleMessage(CNWSPlayer *, unsigned char)
{
    asm("leave");
    asm("mov $0x08196e28, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::HandlePlayerToServerPVPListOperations(CNWSPlayer *, unsigned char)
{
    asm("leave");
    asm("mov $0x0819ab58, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::HandlePlayerToServerParty(CNWSPlayer *, unsigned char)
{
    asm("leave");
    asm("mov $0x08197774, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::HandlePlayerToServerPlayModuleCharacterList_Start(CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x0819b568, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::HandlePlayerToServerPlayModuleCharacterList_Stop(CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x0819bd64, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::HandlePlayerToServerPlayModuleCharacterList(CNWSPlayer *, unsigned char)
{
    asm("leave");
    asm("mov $0x0819bcfc, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::HandlePlayerToServerPlayerDeath(CNWSPlayer *, unsigned char)
{
    asm("leave");
    asm("mov $0x0819aab8, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::HandlePlayerToServerPlayerList(CNWSPlayer *, unsigned char)
{
    asm("leave");
    asm("mov $0x0819b71c, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::HandlePlayerToServerPortal(CNWSPlayer *, unsigned char)
{
    asm("leave");
    asm("mov $0x0819b384, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::HandlePlayerToServerQuickChatMessage(CNWSPlayer *, unsigned char)
{
    asm("leave");
    asm("mov $0x08184804, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::HandlePlayerToServerServerChatMessage(CNWSPlayer *, unsigned char)
{
    asm("leave");
    asm("mov $0x0819bb04, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::HandlePlayerToServerServerStatusMessage(CNWSPlayer *, unsigned char)
{
    asm("leave");
    asm("mov $0x0819bb10, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::HandlePlayerToServerShutDownServer(CNWSPlayer *, unsigned char)
{
    asm("leave");
    asm("mov $0x0819b41c, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::HandlePlayerToServerStoreMessage(CNWSPlayer *, unsigned char)
{
    asm("leave");
    asm("mov $0x08190794, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::HandleServerAdminToServerMessage(unsigned long, unsigned char *, unsigned long)
{
    asm("leave");
    asm("mov $0x0819be40, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::HasValidString(CExoLocString &, unsigned char)
{
    asm("leave");
    asm("mov $0x0807d924, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::ParseGetBool(unsigned char *, unsigned long, int &)
{
    asm("leave");
    asm("mov $0x0819e81c, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::ParseGetString(unsigned char *, unsigned long, CExoString &, unsigned long)
{
    asm("leave");
    asm("mov $0x0819e864, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::ParseToken(char const *, unsigned char **, unsigned long &, int)
{
    asm("leave");
    asm("mov $0x0819e8f0, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSMessage::ReadOBJECTIDServer()
{
    asm("leave");
    asm("mov $0x08052d84, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSMessage::SelectCategoryForGameObject(CGameObject *, CNWSObject *)
{
    asm("leave");
    asm("mov $0x0806b0fc, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendPlayerToServerGuiInventory_Status(CNWSPlayer *, int, unsigned long)
{
    asm("leave");
    asm("mov $0x0808175c, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerPlayerItemUpdate_DestroyItem(CNWSPlayer *, unsigned long)
{
    asm("leave");
    asm("mov $0x080819e0, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToAllPlayersCreatureUpdate_StripEquippedItems(unsigned long, int, int)
{
    asm("leave");
    asm("mov $0x0807bc4c, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerAIActionPlaySound(unsigned long, unsigned long, CExoString)
{
    asm("leave");
    asm("mov $0x0807fae0, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerActivatePortal(unsigned long, CExoString, CExoString, CExoString, int)
{
    asm("leave");
    asm("mov $0x0807daa8, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerAmbientBattleMusicChange(unsigned long, int)
{
    asm("leave");
    asm("mov $0x08082604, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerAmbientBattleMusicPlay(unsigned long, int)
{
    asm("leave");
    asm("mov $0x080825a4, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerAmbientMusicChangeTrack(unsigned long, int, int)
{
    asm("leave");
    asm("mov $0x08082530, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerAmbientMusicPlay(unsigned long, int)
{
    asm("leave");
    asm("mov $0x0808246c, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerAmbientMusicSetDelay(unsigned long, int)
{
    asm("leave");
    asm("mov $0x080824cc, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerAmbientSoundLoopChange(unsigned long, int, int)
{
    asm("leave");
    asm("mov $0x080826c8, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerAmbientSoundLoopPlay(unsigned long, int)
{
    asm("leave");
    asm("mov $0x08082668, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerAmbientSoundVolumeChange(unsigned long, int, int)
{
    asm("leave");
    asm("mov $0x0808273c, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerArea_ChangeDayNight(CNWSPlayer *, int, float)
{
    asm("leave");
    asm("mov $0x0807f87c, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerArea_ClientArea(CNWSPlayer *, CNWSArea *, float, float, float, Vector const &, int)
{
    asm("leave");
    asm("mov $0x0806504c, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerArea_RecomputeStaticLighting(unsigned long)
{
    asm("leave");
    asm("mov $0x0806562c, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerArea_VisualEffect(CNWSPlayer *, unsigned short, Vector)
{
    asm("leave");
    asm("mov $0x08065590, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerArea_Weather(CNWSPlayer *, unsigned char, int)
{
    asm("leave");
    asm("mov $0x0807f804, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerBarterAcceptTrade(unsigned long, unsigned long, int, int)
{
    asm("leave");
    asm("mov $0x08082344, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerBarterCloseBarter(unsigned long, unsigned long, int)
{
    asm("leave");
    asm("mov $0x08082218, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerBarterLockList(unsigned long, unsigned long, int, int)
{
    asm("leave");
    asm("mov $0x080822b0, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerBarterReject(unsigned long, unsigned char, unsigned char, unsigned long)
{
    asm("leave");
    asm("mov $0x080823d8, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerBarterStartBarter(unsigned long, unsigned long, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x08082184, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerCCMessage(unsigned long, unsigned char, CNWCCMessageData *, CNWSCombatAttackData *)
{
    asm("leave");
    asm("mov $0x08078ab8, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerCamera_ChangeLocation(CNWSPlayer *, int, float, float, float, int)
{
    asm("leave");
    asm("mov $0x08064e14, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerCamera_LockDistance(CNWSPlayer *, int)
{
    asm("leave");
    asm("mov $0x0807f29c, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerCamera_LockPitch(CNWSPlayer *, int)
{
    asm("leave");
    asm("mov $0x0807f238, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerCamera_LockYaw(CNWSPlayer *, int)
{
    asm("leave");
    asm("mov $0x0807f300, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerCamera_Restore(CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x0807f1b0, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerCamera_SetHeight(CNWSPlayer *, float)
{
    asm("leave");
    asm("mov $0x0807f1d0, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerCamera_SetMode(CNWSPlayer *, unsigned char)
{
    asm("leave");
    asm("mov $0x0807f124, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerCamera_Store(CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x0807f190, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerCharList(CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x08065ad4, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerCharacterDownloadFail(CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x0807dd48, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerCharacterDownloadReply(CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x0807dc84, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerChatMessage(unsigned char, unsigned long, CExoString, unsigned long, CExoString const &)
{
    asm("leave");
    asm("mov $0x0806839c, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerChatMultiLangMessage(unsigned char, unsigned long, CExoLocString, unsigned long, unsigned char, unsigned long *, unsigned long, int, CResRef const &, int, unsigned long)
{
    asm("leave");
    asm("mov $0x08067e6c, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerChatMultiLang_Helper(unsigned long, unsigned char, unsigned long, CExoLocString, unsigned long, unsigned char, int, CResRef const &, int, unsigned long)
{
    asm("leave");
    asm("mov $0x0807f984, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerChatStrRefMessage(unsigned char, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x08068150, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerChatStrRefStatusMessage(unsigned char, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x0819be0c, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerChat_DM_Silent_Shout(unsigned long, unsigned long, CExoString)
{
    asm("leave");
    asm("mov $0x08069dd8, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerChat_DM_Talk(unsigned long, unsigned long, CExoString)
{
    asm("leave");
    asm("mov $0x08069248, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerChat_DM_Whisper(unsigned long, unsigned long, CExoString)
{
    asm("leave");
    asm("mov $0x0806a03c, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerChat_Party(unsigned long, unsigned long, CExoString)
{
    asm("leave");
    asm("mov $0x08068fe4, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerChat_ServerTell(unsigned long, CExoString)
{
    asm("leave");
    asm("mov $0x0807ff68, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerChat_Shout(unsigned long, unsigned long, CExoString)
{
    asm("leave");
    asm("mov $0x08069710, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerChat_Silent_Shout(unsigned long, unsigned long, CExoString)
{
    asm("leave");
    asm("mov $0x08069a74, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerChat_StrRef(unsigned long, unsigned long, unsigned char, unsigned long)
{
    asm("leave");
    asm("mov $0x0807fd94, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerChat_Talk(unsigned long, unsigned long, CExoString)
{
    asm("leave");
    asm("mov $0x0807fe10, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerChat_Tell(unsigned long, unsigned long, CExoString)
{
    asm("leave");
    asm("mov $0x080694ac, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerChat_Whisper(unsigned long, unsigned long, CExoString)
{
    asm("leave");
    asm("mov $0x0808003c, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerCheatDebugMode(int)
{
    asm("leave");
    asm("mov $0x0807b0d4, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerCheatNasty(unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x08081394, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerCheatPonyRide(unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x080813f4, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerCheatRainOfCows(unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x08081460, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerCloseStoreInventory(CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x0808067c, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerCombatRoundStarted(CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x08081540, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerCutscene_BlackScreen(CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x08081954, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerCutscene_FadeFromBlack(CNWSPlayer *, float)
{
    asm("leave");
    asm("mov $0x080818c4, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerCutscene_FadeToBlack(CNWSPlayer *, float)
{
    asm("leave");
    asm("mov $0x08081854, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerCutscene_HideGui(CNWSPlayer *, int)
{
    asm("leave");
    asm("mov $0x08081974, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerCutscene_Status(CNWSPlayer *, int, int)
{
    asm("leave");
    asm("mov $0x080817d4, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerCutscene_StopFade(CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x08081934, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerDebugInfo_Area(CNWSPlayer *, unsigned long)
{
    asm("leave");
    asm("mov $0x0807d634, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerDebugInfo_Creature(CNWSPlayer *, unsigned long)
{
    asm("leave");
    asm("mov $0x0807cd98, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerDebugInfo_Door(CNWSPlayer *, unsigned long)
{
    asm("leave");
    asm("mov $0x0807d42c, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerDebugInfo_Item(CNWSPlayer *, unsigned long)
{
    asm("leave");
    asm("mov $0x0807d0d0, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerDebugInfo_Placeable(CNWSPlayer *, unsigned long)
{
    asm("leave");
    asm("mov $0x0807d264, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerDebugInfo_Trigger(CNWSPlayer *, unsigned long)
{
    asm("leave");
    asm("mov $0x0807d1b0, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerDestroyDeathGUI(unsigned long)
{
    asm("leave");
    asm("mov $0x080829fc, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerDialogClose(unsigned long)
{
    asm("leave");
    asm("mov $0x08080a24, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerDialogEntry(unsigned long, unsigned long, unsigned long, CExoLocString, unsigned long, unsigned char)
{
    asm("leave");
    asm("mov $0x0808070c, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerDialogReplies(unsigned long, CExoLocString *, unsigned long *, unsigned long, unsigned long, unsigned long, unsigned char, int, unsigned long, int)
{
    asm("leave");
    asm("mov $0x080807fc, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerDialogReplyChosen(unsigned long, unsigned long, unsigned long, CExoLocString, unsigned long, unsigned char, int)
{
    asm("leave");
    asm("mov $0x08080918, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerDungeonMasterAreaList(CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x08075960, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerDungeonMasterAreaList(unsigned long)
{
    asm("leave");
    asm("mov $0x08075a18, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerDungeonMasterCreatorLists(CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x0807678c, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerDungeonMasterObjectList(CNWSPlayer *, unsigned long, int)
{
    asm("leave");
    asm("mov $0x080761d0, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerDungeonMasterSearchByIdResult(CNWSPlayer *, unsigned long, int, unsigned long)
{
    asm("leave");
    asm("mov $0x08080a44, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerDungeonMasterSearchByTagResult(CNWSPlayer *, CExoString const &, int, unsigned long)
{
    asm("leave");
    asm("mov $0x08075b2c, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerDungeonMasterUpdatePartyList(CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x08080ac8, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerDungeonMasterUpdatePartyList(unsigned long)
{
    asm("leave");
    asm("mov $0x08080b04, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerDungeonMastersDifficultyChange(int)
{
    asm("leave");
    asm("mov $0x08076e34, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerExamineGui_CreatureData(CNWSPlayer *, unsigned long)
{
    asm("leave");
    asm("mov $0x08073958, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerExamineGui_DoorData(CNWSPlayer *, unsigned long)
{
    asm("leave");
    asm("mov $0x08074c50, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerExamineGui_ItemData(CNWSPlayer *, unsigned long)
{
    asm("leave");
    asm("mov $0x08073f9c, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerExamineGui_PlaceableData(CNWSPlayer *, unsigned long)
{
    asm("leave");
    asm("mov $0x08074668, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerExamineGui_TrapData(CNWSPlayer *, unsigned long, CNWSCreature *, int)
{
    asm("leave");
    asm("mov $0x080747d0, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerGUICharacterSheet_NotPermitted(unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x08082b14, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerGameObjUpdateFloatyText(CNWSPlayer *, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x080814cc, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerGameObjUpdateVisEffect(CNWSPlayer *, unsigned short, unsigned long, unsigned long, unsigned char, unsigned char, Vector, float)
{
    asm("leave");
    asm("mov $0x0807b1ac, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerGameObjUpdate_ObjControl(unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x0808069c, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerGameObjUpdate(CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x08080358, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerGameObjUpdate(CNWSPlayer *, unsigned long)
{
    asm("leave");
    asm("mov $0x0806b768, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerGuiContainerObject_Status(CNWSPlayer *, unsigned long, int)
{
    asm("leave");
    asm("mov $0x080816e4, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerGuiQuickbar_SetButton(CNWSPlayer *, unsigned char, int)
{
    asm("leave");
    asm("mov $0x0807c794, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerGuiTimingEvent(CNWSPlayer *, int, unsigned char, unsigned long)
{
    asm("leave");
    asm("mov $0x08082a20, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerInventory_ConfirmDrop(unsigned long, unsigned long, int)
{
    asm("leave");
    asm("mov $0x08080de8, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerInventory_DropCancel(unsigned long, unsigned long, int)
{
    asm("leave");
    asm("mov $0x08080b94, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerInventory_Drop(unsigned long, unsigned long, int)
{
    asm("leave");
    asm("mov $0x08080b24, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerInventory_EquipCancel(unsigned long, unsigned long, unsigned long, int)
{
    asm("leave");
    asm("mov $0x08080c84, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerInventory_Equip(unsigned long, unsigned long, unsigned long, int)
{
    asm("leave");
    asm("mov $0x08080c04, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerInventory_LearnScroll(unsigned long, unsigned long, unsigned char)
{
    asm("leave");
    asm("mov $0x080828a4, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerInventory_PickupCancel(unsigned long, unsigned long, int)
{
    asm("leave");
    asm("mov $0x08080f38, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerInventory_Pickup(unsigned long, unsigned long, int)
{
    asm("leave");
    asm("mov $0x08080ec8, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerInventory_RepositoryMoveCancel(unsigned long, unsigned long, int)
{
    asm("leave");
    asm("mov $0x08080d78, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerInventory_RepositoryMove(unsigned long, unsigned long, int)
{
    asm("leave");
    asm("mov $0x08080d08, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerInventory_SelectPage(unsigned long, unsigned char)
{
    asm("leave");
    asm("mov $0x08080ec0, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerInventory_SelectPanel(unsigned long, unsigned char)
{
    asm("leave");
    asm("mov $0x08080e58, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerInventory_UnequipCancel(unsigned long, unsigned long, int)
{
    asm("leave");
    asm("mov $0x08081018, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerInventory_Unequip(unsigned long, unsigned long, int)
{
    asm("leave");
    asm("mov $0x08080fa8, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerJournalAddQuest(CNWSPlayer *, CExoString, int, unsigned long, unsigned short, int, unsigned long, unsigned long, CExoLocString, CExoLocString)
{
    asm("leave");
    asm("mov $0x0807bd28, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerJournalAddWorldStrref(CNWSPlayer *, unsigned long, unsigned long, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x08081bfc, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerJournalAddWorld(CNWSPlayer *, int, CExoString, CExoString, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x0807bf24, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerJournalDeleteWorldAll(CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x08081d78, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerJournalDeleteWorldStrref(CNWSPlayer *, unsigned long)
{
    asm("leave");
    asm("mov $0x08081d08, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerJournalDeleteWorld(CNWSPlayer *, int)
{
    asm("leave");
    asm("mov $0x08081c98, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerJournalFullUpdateNotNeeded(CNWSPlayer *, int)
{
    asm("leave");
    asm("mov $0x08081de0, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerJournalFullUpdate(CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x0807c09c, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerJournalRemoveQuest(CNWSPlayer *, CExoString)
{
    asm("leave");
    asm("mov $0x08081a44, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerJournalSetQuestPicture(CNWSPlayer *, CExoString, int)
{
    asm("leave");
    asm("mov $0x08081b18, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerJournalUpdated(CNWSPlayer *, int, int, CExoLocString)
{
    asm("leave");
    asm("mov $0x08081e74, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerLevelUp_Begin(unsigned long, CNWSCreature *)
{
    asm("leave");
    asm("mov $0x0807c59c, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerLevelUp_Confirmation(unsigned long, int)
{
    asm("leave");
    asm("mov $0x08081f54, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerLoadBar_EndStallEvent(unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x0807f5f0, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerLoadBar_StartStallEvent(unsigned long)
{
    asm("leave");
    asm("mov $0x0807f510, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerLoadBar_UpdateStallEvent(unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x0807f578, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerLogin_CharacterQuery(CNWSPlayer *, unsigned char &, int *, unsigned char *, unsigned long &)
{
    asm("leave");
    asm("mov $0x0807f364, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerLogin_Confirm(unsigned long)
{
    asm("leave");
    asm("mov $0x08081088, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerLogin_Fail(unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x080810c8, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerLogin_GetWaypoint(unsigned long)
{
    asm("leave");
    asm("mov $0x080810a8, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerLogin_NeedCharacter(unsigned long)
{
    asm("leave");
    asm("mov $0x0807f414, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerMapPinAdded(CNWSPlayer *, Vector, CExoString, unsigned long)
{
    asm("leave");
    asm("mov $0x0807cc80, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerMapPinCreated(CNWSPlayer *, unsigned long, Vector, CExoLocString, int)
{
    asm("leave");
    asm("mov $0x0808207c, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerMapPinEnabled(CNWSPlayer *, unsigned long, int)
{
    asm("leave");
    asm("mov $0x0808200c, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerMessage(unsigned long, unsigned char, unsigned char, unsigned char *, unsigned long)
{
    asm("leave");
    asm("mov $0x08076f10, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerModuleUpdate_Time(CNWSPlayer *, unsigned char, unsigned long, unsigned long, unsigned long, unsigned long, unsigned char, unsigned long)
{
    asm("leave");
    asm("mov $0x0807c690, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerModule_DumpPlayer(CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x0807f7e4, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerModule_EndGame(unsigned long, CExoString const &)
{
    asm("leave");
    asm("mov $0x0807f4a0, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerModule_EndStartNewModule(int)
{
    asm("leave");
    asm("mov $0x0807f780, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerModule_ExportReply(CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x0807f668, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerModule_Info(unsigned long)
{
    asm("leave");
    asm("mov $0x08077004, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerModule_Loading(CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x0807f6c0, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerModule_SaveGameStatus(unsigned char)
{
    asm("leave");
    asm("mov $0x0807f434, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerModule_SetPauseState(unsigned char, int)
{
    asm("leave");
    asm("mov $0x08064ee8, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerModule_StartStartNewModule()
{
    asm("leave");
    asm("mov $0x0807f75c, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerOpenStoreInventory(CNWSPlayer *, unsigned long, unsigned char)
{
    asm("leave");
    asm("mov $0x080708b4, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerPVP_Attitude_Change(unsigned long, unsigned long, int)
{
    asm("leave");
    asm("mov $0x0807dea4, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerPartyBar_PanelButtonFlash(unsigned long, unsigned char, int)
{
    asm("leave");
    asm("mov $0x08082914, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerParty_Invite(unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x0808112c, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerParty_List(unsigned long, int, unsigned long *, unsigned char, unsigned long)
{
    asm("leave");
    asm("mov $0x08081138, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerParty_TransferObjectControl(unsigned long, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x080811f4, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerPlaceableUpdate_Useable(CNWSPlaceable *)
{
    asm("leave");
    asm("mov $0x0807ee10, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerPlayModuleCharacterListResponse(unsigned long, unsigned long, int)
{
    asm("leave");
    asm("mov $0x0807e44c, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerPlayerList_Add(unsigned long, CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x080770a8, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerPlayerList_All(CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x080774e4, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerPlayerList_Delete(unsigned long, CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x08081268, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerPlayerList_ReauthorizeCDKey(unsigned long, CExoString const &, CExoString const &)
{
    asm("leave");
    asm("mov $0x080812ec, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerPolymorph(CNWSPlayer *, unsigned long, int, int)
{
    asm("leave");
    asm("mov $0x08082b78, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerPopUpGUIPanel(unsigned long, int, int, int, int, CExoString)
{
    asm("leave");
    asm("mov $0x0807d6d0, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerQuickChatMessage(unsigned long, unsigned short)
{
    asm("leave");
    asm("mov $0x08068dec, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerQuickChat(unsigned long, unsigned long, unsigned short)
{
    asm("leave");
    asm("mov $0x0807fef0, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerSafeProjectile(CNWSPlayer *, unsigned long, unsigned long, Vector, Vector, unsigned long, unsigned char, unsigned long, unsigned char, unsigned char, unsigned char)
{
    asm("leave");
    asm("mov $0x0807073c, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerSaveLoad_Status(CNWSPlayer *, unsigned char, unsigned long)
{
    asm("leave");
    asm("mov $0x0807f6e0, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerServerStatus_Status(unsigned long)
{
    asm("leave");
    asm("mov $0x08077a98, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerSetCustomTokenList(unsigned long)
{
    asm("leave");
    asm("mov $0x08067d60, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerSetCustomToken(unsigned long, int, CExoString const &)
{
    asm("leave");
    asm("mov $0x0807f8f4, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerShutDownServer(unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x08082990, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerSoundObject_ChangePosition(CNWSPlayer *, unsigned long, Vector)
{
    asm("leave");
    asm("mov $0x0807fcfc, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerSoundObject_ChangeVolume(CNWSPlayer *, unsigned long, int)
{
    asm("leave");
    asm("mov $0x0807fc88, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerSoundObject_Play(CNWSPlayer *, unsigned long)
{
    asm("leave");
    asm("mov $0x0807fbc0, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerSoundObject_Stop(CNWSPlayer *, unsigned long)
{
    asm("leave");
    asm("mov $0x0807fc24, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerStoreConfirmTransaction(CNWSPlayer *, int, unsigned long, int)
{
    asm("leave");
    asm("mov $0x08081f98, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerStringMessage(unsigned long, unsigned char, CExoString)
{
    asm("leave");
    asm("mov $0x080805a0, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerUpdateActiveItemPropertiesUses(CNWSPlayer *, unsigned long, unsigned char, unsigned char, unsigned char *)
{
    asm("leave");
    asm("mov $0x080815a0, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerUpdateActiveItemProperties(CNWSPlayer *, CNWSItem *)
{
    asm("leave");
    asm("mov $0x0807b5c8, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerUpdateBlackoutEffect(CNWSPlayer *, int)
{
    asm("leave");
    asm("mov $0x08082ab0, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerUpdateCharResponse(CNWSPlayer *, unsigned char, CResRef)
{
    asm("leave");
    asm("mov $0x08066c40, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerUpdateFogAmount(unsigned char, unsigned char, unsigned long)
{
    asm("leave");
    asm("mov $0x0807bafc, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerUpdateFogColor(unsigned long, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x0807b9bc, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerUpdateItemName(CNWSPlayer *, CNWSItem *)
{
    asm("leave");
    asm("mov $0x0807b704, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerUpdateSkyBox(int, unsigned long)
{
    asm("leave");
    asm("mov $0x0807b890, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerVoiceChat_Play(CNWSPlayer *, unsigned long, unsigned char)
{
    asm("leave");
    asm("mov $0x08081664, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerWhirlwindAttackDamage(CNWSPlayer *, CNWSCreature *)
{
    asm("leave");
    asm("mov $0x0807ecc0, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToPlayerWhirlwindAttack(CNWSPlayer *, CNWSCreature *)
{
    asm("leave");
    asm("mov $0x0807eb68, %eax");
    asm("jmp *%eax");
}

void CNWSMessage::SendServerToServerAdminBannedList(unsigned long)
{
    asm("leave");
    asm("mov $0x081e6030, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::SendServerToServerAdminMessage(unsigned long, CExoString)
{
    asm("leave");
    asm("mov $0x081e4bf4, %eax");
    asm("jmp *%eax");
}

void CNWSMessage::SendServerToServerAdminModuleList(unsigned long)
{
    asm("leave");
    asm("mov $0x081e4cf0, %eax");
    asm("jmp *%eax");
}

void CNWSMessage::SendServerToServerAdminPlayerList(unsigned long)
{
    asm("leave");
    asm("mov $0x081e5f38, %eax");
    asm("jmp *%eax");
}

void CNWSMessage::SendServerToServerAdminPortalList(unsigned long)
{
    asm("leave");
    asm("mov $0x081e6128, %eax");
    asm("jmp *%eax");
}

void CNWSMessage::SendServerToServerAdminSaveGameList(unsigned long)
{
    asm("leave");
    asm("mov $0x081e567c, %eax");
    asm("jmp *%eax");
}

void CNWSMessage::SendServerToServerAdminSaveStatus(unsigned long, unsigned char)
{
    asm("leave");
    asm("mov $0x081e8604, %eax");
    asm("jmp *%eax");
}

void CNWSMessage::SendServerToServerAdminServerSettings(unsigned long)
{
    asm("leave");
    asm("mov $0x081e6220, %eax");
    asm("jmp *%eax");
}

void CNWSMessage::SendServerToServerAdminServerStatus(unsigned long)
{
    asm("leave");
    asm("mov $0x081e5d50, %eax");
    asm("jmp *%eax");
}

CNWSPlayerLUOSortedObjectList * CNWSMessage::SortObjectsForGameObjectUpdate(CNWSPlayer *, CNWSObject *, CGameObjectArray *, int *)
{
    asm("leave");
    asm("mov $0x0806b3a4, %eax");
    asm("jmp *%eax");
}

void CNWSMessage::StoreValuesInLastPlayerUpdateObject(CNWSPlayer *, CNWSPlayerLastUpdateObject *, CLastUpdateObject *, unsigned short)
{
    asm("leave");
    asm("mov $0x0806fbec, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::StoreValuesInLastUpdateObject(CNWSPlayer *, CLastUpdateObject *, CNWSObject *, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x08080400, %eax");
    asm("jmp *%eax");
}

void CNWSMessage::StoreValuesInLastUpdatePartyObject(CNWSCreature *, CLastUpdatePartyObject *, CNWSCreature *, unsigned long)
{
    asm("leave");
    asm("mov $0x080714d8, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::TestObjectUpdateDifferences(CNWSPlayer *, CNWSObject *, CLastUpdateObject **, unsigned long *, unsigned long *)
{
    asm("leave");
    asm("mov $0x08080444, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::TestObjectVisible(CNWSObject *, CNWSObject *)
{
    asm("leave");
    asm("mov $0x0806c6e8, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::TestPartyObjectUpdateDifferences(CNWSPlayer *, CNWSCreature *, CLastUpdatePartyObject **, unsigned long *)
{
    asm("leave");
    asm("mov $0x08070ed4, %eax");
    asm("jmp *%eax");
}

void CNWSMessage::TestPlayerUpdateDifferences(CNWSPlayer *, CNWSPlayerLastUpdateObject *, CLastUpdateObject *, unsigned short &)
{
    asm("leave");
    asm("mov $0x0806d744, %eax");
    asm("jmp *%eax");
}

void CNWSMessage::UpdateLastUpdateActionQueue(CNWSCreature *, CNWSPlayerLastUpdateObject *)
{
    asm("leave");
    asm("mov $0x0806497c, %eax");
    asm("jmp *%eax");
}

void CNWSMessage::UpdateLastUpdateAutoMap(CNWSCreature *, CNWSPlayerLastUpdateObject *)
{
    asm("leave");
    asm("mov $0x08064784, %eax");
    asm("jmp *%eax");
}

void CNWSMessage::UpdateLastUpdateInventory(CNWSPlayer *, unsigned long, CNWSPlayerInventoryGUI *)
{
    asm("leave");
    asm("mov $0x08077cb4, %eax");
    asm("jmp *%eax");
}

void CNWSMessage::UpdateLastUpdateObjectAppearance(CNWSObject *, CLastUpdateObject *, unsigned long)
{
    asm("leave");
    asm("mov $0x08078968, %eax");
    asm("jmp *%eax");
}

void CNWSMessage::UpdateLastUpdateObject(CNWSPlayer *, CNWSObject *, CLastUpdateObject *, unsigned long)
{
    asm("leave");
    asm("mov $0x08077dbc, %eax");
    asm("jmp *%eax");
}

void CNWSMessage::UpdateLastUpdateVisibilityList(CNWSCreature *, CNWSPlayerLastUpdateObject *)
{
    asm("leave");
    asm("mov $0x080628ec, %eax");
    asm("jmp *%eax");
}

void CNWSMessage::UpdateLastUpdate_GuiEffectIcons(CNWSCreature *, CExoArrayList<CEffectIconObject *> *, int)
{
    asm("leave");
    asm("mov $0x0807dfa8, %eax");
    asm("jmp *%eax");
}

void CNWSMessage::WriteCExoLocStringServer(CExoLocString &, unsigned char)
{
    asm("leave");
    asm("mov $0x08052480, %eax");
    asm("jmp *%eax");
}

void CNWSMessage::WriteGameObjUpdate_CharacterSheet(CNWSPlayer *, unsigned long)
{
    asm("leave");
    asm("mov $0x08074db8, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::WriteGameObjUpdate_DungeonMasterAIState(CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x08071898, %eax");
    asm("jmp *%eax");
}

void CNWSMessage::WriteGameObjUpdate_MajorGUIPanels_HenchmanInventoryData(CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x0806d618, %eax");
    asm("jmp *%eax");
}

void CNWSMessage::WriteGameObjUpdate_MajorGUIPanels_Inventory(CNWSPlayer *, CNWSPlayerInventoryGUI *)
{
    asm("leave");
    asm("mov $0x0806d174, %eax");
    asm("jmp *%eax");
}

void CNWSMessage::WriteGameObjUpdate_MajorGUIPanels(CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x0806d040, %eax");
    asm("jmp *%eax");
}

void CNWSMessage::WriteGameObjUpdate_MinorGUIPanels(CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x0806d468, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::WriteGameObjUpdate_PartyAIState(CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x08071704, %eax");
    asm("jmp *%eax");
}

void CNWSMessage::WriteGameObjUpdate_PlayerUpdate(CNWSPlayer *, CNWSPlayerLastUpdateObject *, CLastUpdateObject *, unsigned short)
{
    asm("leave");
    asm("mov $0x0806db28, %eax");
    asm("jmp *%eax");
}

void CNWSMessage::WriteGameObjUpdate_UpdateAppearance(CNWSObject *, CLastUpdateObject *, unsigned long)
{
    asm("leave");
    asm("mov $0x0806a2a0, %eax");
    asm("jmp *%eax");
}

void CNWSMessage::WriteGameObjUpdate_UpdateObject(CNWSPlayer *, CNWSObject *, CLastUpdateObject *, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x08071a24, %eax");
    asm("jmp *%eax");
}

void CNWSMessage::WriteGameObjUpdate_UpdateQuickbarItemUseCount(CNWSObject *, CLastUpdateObject *)
{
    asm("leave");
    asm("mov $0x0807e82c, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::WriteGameObjUpdate_WorkRemaining(CNWSObject *, CNWSArea *, int, int)
{
    asm("leave");
    asm("mov $0x08080374, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::WriteGameObjUpdate_WriteInventorySlotAdd(CNWSCreature *, CNWSItem *, unsigned long)
{
    asm("leave");
    asm("mov $0x0808011c, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::WriteGameObjUpdate_WriteInventorySlotDelete(CNWSCreature *, unsigned long)
{
    asm("leave");
    asm("mov $0x0808017c, %eax");
    asm("jmp *%eax");
}

int CNWSMessage::WriteGameObjUpdate_WriteInventorySlotUpdate(unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x080801bc, %eax");
    asm("jmp *%eax");
}

void CNWSMessage::WriteGuiEffectIconsUpdate(CNWSCreature *, CExoArrayList<CEffectIconObject *> *, int)
{
    asm("leave");
    asm("mov $0x0807e188, %eax");
    asm("jmp *%eax");
}

void CNWSMessage::WriteOBJECTIDServer(unsigned long)
{
    asm("leave");
    asm("mov $0x08052434, %eax");
    asm("jmp *%eax");
}

void CNWSMessage::WriteRepositoryUpdate(CNWSPlayer *, CNWSObject *, CItemRepository *, CNWSPlayerLUOInventory *, unsigned char, char, unsigned char)
{
    asm("leave");
    asm("mov $0x08070240, %eax");
    asm("jmp *%eax");
}

void CNWSMessage::WriteStoreInventoryUpdate(CNWSPlayer *, CNWSStore *)
{
    asm("leave");
    asm("mov $0x08070a90, %eax");
    asm("jmp *%eax");
}

