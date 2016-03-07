#ifndef _NWNSTRUCTS_H_
#define _NWNSTRUCTS_H_
#include "nwndef.h"
#include "CGameObject.h"
#include "CExoArrayList.h"
#include "CExoString.h"
#include "CResRef.h"
#include "CExoLocString.h"
#include "nwnstructs.h"
#include "CGameEffect.h"
#include "Vector.h"
struct CServerExoAppConfig {
    /* 0x0/0 */ unsigned long field_0;
    /* 0x4/4 */ unsigned long field_4;
    /* 0x8/8 */ unsigned long field_8;
    /* 0xC/12 */ unsigned long field_C;
    /* 0x10/16 */ unsigned long field_10;
    /* 0x14/20 */ unsigned long field_14;
    /* 0x18/24 */ unsigned long field_18;
    /* 0x1C/28 */ unsigned long field_1C;
    /* 0x20/32 */ unsigned long field_20;
    /* 0x24/36 */ unsigned long field_24;
    /* 0x28/40 */ unsigned long field_28;
    /* 0x2C/44 */ unsigned long field_2C;
    /* 0x30/48 */ unsigned long field_30;
    /* 0x34/52 */ unsigned long field_34;
    /* 0x38/56 */ unsigned long field_38;
    /* 0x3C/60 */ unsigned long field_3C;
    /* 0x40/64 */ unsigned long field_40;
    /* 0x44/68 */ unsigned long field_44;
    /* 0x48/72 */ unsigned long field_48;
    /* 0x4C/76 */ unsigned long field_4C;
    /* 0x50/80 */ unsigned long field_50;
    /* 0x54/84 */ unsigned long field_54;
    /* 0x58/88 */ unsigned long field_58;
    /* 0x5C/92 */ unsigned long field_5C;
    /* 0x60/96 */ unsigned long field_60;
    /* 0x64/100 */ unsigned long field_64;
    /* 0x68/104 */ unsigned long field_68;
    /* 0x6C/108 */ unsigned long field_6C;
    /* 0x70/112 */ unsigned long field_70;
    /* 0x74/116 */ unsigned long field_74;
    /* 0x78/120 */ unsigned long field_78;
    /* 0x7C/124 */ unsigned long field_7C;
    /* 0x80/128 */ unsigned long field_80;
    /* 0x84/132 */ unsigned long field_84;
    /* 0x88/136 */ unsigned long field_88;
    /* 0x8C/140 */ unsigned long field_8C;
    /* 0x90/144 */ unsigned long field_90;
    /* 0x94/148 */ unsigned long field_94;
    /* 0x98/152 */ unsigned long field_98;
    /* 0x9C/156 */ unsigned long field_9C;
    /* 0xA0/160 */ unsigned long field_A0;
    /* 0xA4/164 */ unsigned long field_A4;
    /* 0xA8/168 */ unsigned long field_A8;
    /* 0xAC/172 */ unsigned long field_AC;
    /* 0xB0/176 */ unsigned long field_B0;
    /* 0xB4/180 */ unsigned long field_B4;
    /* 0xB8/184 */ unsigned long AllowLocalChars;
    /* 0xBC/188 */ unsigned long field_BC;
    /* 0xC0/192 */ unsigned long field_C0;
    /* 0xC4/196 */ unsigned long field_C4;
    /* 0xC8/200 */ unsigned long field_C8;
    /* 0xCC/204 */ unsigned long field_CC;
    /* 0xD0/208 */ unsigned long field_D0;
    /* 0xD4/212 */ unsigned long field_D4;
    /* 0xD8/216 */ unsigned long field_D8;
    /* 0xDC/220 */ unsigned long field_DC;
    /* 0xE0/224 */ unsigned long field_E0;
    /* 0xE4/228 */ unsigned long field_E4;
    /* 0xE8/232 */ unsigned long PauseAndPlay;
    /* 0xEC/236 */ unsigned long OneParty;
    /* 0xF0/240 */ unsigned long EnforceLegalCharacters;
    /* 0xF4/244 */ unsigned long ItemLevelRestrictions;
    /* 0xF8/248 */ unsigned long CDBannedBehavior;
    /* 0xFC/252 */ unsigned long DisallowShouting;
    /* 0x100/256 */ unsigned long ShowDMJoinedMessage;
    /* 0x104/260 */ unsigned long BackupSavedChars;
    /* 0x108/264 */ unsigned long AutoFail1;
    /* 0x10C/268 */ unsigned long ValidateSpells;
    /* 0x110/272 */ unsigned long ExamineEffects;
    /* 0x114/276 */ unsigned long ExamineCR;
    /* 0x118/280 */ unsigned long MaxHP;
    /* 0x11C/284 */ unsigned long RestoreSpellUses;
    /* 0x120/288 */ unsigned long ResetEncounterSpawns;
    /* 0x124/292 */ unsigned long HideHPGained;
    /* 0x128/296 */ unsigned long field_128;
    /* 0x12C/300 */ unsigned long field_12C;
    /* 0x130/304 */ unsigned long field_130;
    /* 0x134/308 */ unsigned long field_134;
    /* 0x138/312 */ unsigned long field_138;
    /* 0x13C/316 */ unsigned long field_13C;
    /* 0x140/320 */ unsigned long field_140;
    /* 0x144/324 */ unsigned long field_144;
    /* 0x148/328 */ unsigned long field_148;
    /* 0x14C/332 */ unsigned long VaultCharsOnly;
    /* 0x150/336 */ unsigned long SaveCharsInSaveGame;
    /* 0x154/340 */ unsigned long SuppressBaseServervault;
    /* 0x158/344 */ unsigned long GameRegion;
    /* 0x15C/348 */ unsigned long field_15C;
    /* 0x160/352 */ unsigned long field_160;
    /* 0x164/356 */ unsigned long field_164;
};

struct CNWSCreatureAppearanceInfo {
    /* 0x0/0 */ unsigned long LeftHandObjId;
    /* 0x4/4 */ unsigned long RightHandObjId;
    /* 0x8/8 */ unsigned char RightHandVfx;
    /* 0x9/9 */ unsigned char LeftHandVfx;
    /* 0xA/10 */ unsigned short field_A;
    /* 0xC/12 */ unsigned long ChestObjId;
    /* 0x10/16 */ unsigned long HeadObjId;
    /* 0x14/20 */ unsigned short Appearance;
    /* 0x16/22 */ unsigned short field_16;
    /* 0x18/24 */ char field_18;
    /* 0x19/25 */ char field_19;
    /* 0x1A/26 */ char field_1A;
    /* 0x1B/27 */ char field_1B;
    /* 0x1C/28 */ char field_1C;
    /* 0x1D/29 */ char field_1D;
    /* 0x1E/30 */ char field_1E;
    /* 0x1F/31 */ char field_1F;
    /* 0x20/32 */ unsigned long field_20;
    /* 0x24/36 */ unsigned long field_24;
    /* 0x28/40 */ unsigned long field_28;
    /* 0x2C/44 */ char field_2C;
    /* 0x2D/45 */ char field_2D;
    /* 0x2E/46 */ char field_2E;
    /* 0x2F/47 */ char field_2F;
    /* 0x30/48 */ unsigned long field_30;
    /* 0x34/52 */ unsigned long field_34;
    /* 0x38/56 */ unsigned long field_38;
    /* 0x3C/60 */ unsigned long field_3C;
};
struct CResStruct {
    /* 0x0/0 */ unsigned long m_nStructIndex;
};
struct CNWSActionNode {
    /* 0x0/0 */ unsigned long ActionType;
    /* 0x4/4 */ unsigned long ParamTypes[12];
    /* 0x34/52 */ unsigned long ParamValues[12];
    /* 0x64/100 */ unsigned short field_64;
    /* 0x66/102 */ unsigned short field_66;
    /* 0x68/104 */ unsigned long field_68;
};
struct CExoLinkedListNode {
    /* 0x0/0 */ CExoLinkedListNode *Previous;
    /* 0x4/4 */ CExoLinkedListNode *Next;
    /* 0x8/8 */ void *Data;
};
struct ExoLocString_st {
    /* 0x0/0 */ unsigned long LocaleID;
    /* 0x4/4 */ void *String;
};
struct CGameObjectArrayElement {
    /* 0x0/0 */ unsigned long OID;
    /* 0x4/4 */ unsigned long GameObject;
    /* 0x8/8 */ CGameObjectArrayElement *pNextElement;
};
struct CVirtualMachineCommand {
    /* 0x0/0 */ unsigned short offset;
    /* 0x2/2 */ unsigned short flag;
    /* 0x4/4 */ void *Command;
};
struct CNWSVector {
    /* 0x0/0 */ float X;
    /* 0x4/4 */ float Y;
    /* 0x8/8 */ float Z;
};
struct CActionParam {
    /* 0x0/0 */ unsigned long m_nParamType;
    /* 0x4/4 */ unsigned long m_pParamValue;
};
struct CNWModule {
    /* 0x0/0 */ unsigned long field_0;
    /* 0x4/4 */ unsigned long field_4;
    /* 0x18/24 */ char rsvd1[16];
    /* 0x18/24 */ unsigned long Methods;
    /* 0x1C/28 */ CGameObject GameObject;
    /* 0x2C/44 */ unsigned long ModuleExpansionList;
    /* 0x30/48 */ unsigned long field_30;
    /* 0x34/52 */ unsigned long AreasResrefList;
    /* (mtype:CExoArrayList<unsigned long>) */
    /* 0x38/56 */ CExoArrayList<unsigned long> Areas;
    /* 0x44/68 */ unsigned long field_44;
    /* 0x68/104 */ char rsvd2[32];
    /* 0x68/104 */ unsigned long field_68;
    /* 0xB8/184 */ char rsvd3[76];
    /* 0xB8/184 */ CExoString field_B8;
    /* 0xF0/240 */ char rsvd4[48];
    /* 0xF0/240 */ CExoString field_F0;
    /* 0xF8/248 */ CExoString field_F8;
    /* 0x100/256 */ CExoString OnPlayerDeath;
    /* 0x108/264 */ CExoString OnPlayerDying;
    /* 0x110/272 */ CExoString field_110;
    /* 0x148/328 */ char rsvd5[48];
    /* 0x148/328 */ unsigned long Time1;
    /* 0x14C/332 */ unsigned long Time2;
    /* 0x1E8/488 */ char rsvd6[152];
    /* 0x1E8/488 */ unsigned long field_1E8;
    /* 0x1EC/492 */ unsigned long field_1EC;
    /* 0x1F0/496 */ unsigned long field_1F0;
    /* 0x1F4/500 */ unsigned long field_1F4;
    /* 0x1F8/504 */ unsigned long field_1F8;
    /* 0x1FC/508 */ unsigned long field_1FC;
    /* 0x200/512 */ unsigned long field_200;
};
struct CAppManager_ModuleInfo {
    /* 0x0/0 */ unsigned long field_0;
    /* 0x4/4 */ unsigned long field_4;
    /* 0x8/8 */ unsigned long LoadedAreas;
    /* 0xC/12 */ unsigned long TotalAreas;
    /* 0x10/16 */ unsigned long field_10;
    /* 0x14/20 */ unsigned long field_14;
    /* 0x18/24 */ CExoString ModuleName;
    /* 0x20/32 */ CExoString ModulePath;
    /* 0x28/40 */ CExoString CurrentGame;
    /* 0x30/48 */ unsigned long field_30;
    /* 0x34/52 */ unsigned long field_34;
    /* 0x38/56 */ unsigned long field_38;
};
struct CVirtualMachineScript {
    /* 0x0/0 */ CVirtualMachineStack *Stack;
    /* 0x4/4 */ unsigned long StackSize;
    /* 0x8/8 */ unsigned long InstructionPtr;
    /* 0xC/12 */ unsigned long SecondaryPtr;
    /* 0x10/16 */ void *Code;
    /* 0x14/20 */ unsigned long CodeSize;
    /* 0x18/24 */ CExoString Name;
    /* 0x20/32 */ unsigned long field_20;
};
template<typename RES> struct CResHelper {
    /* 0x0/0 */ unsigned long m_bAutoRequest;
    /* 0x4/4 */ RES *m_pRes;
    /* 0x8/8 */ CResRef m_cResRef;
    /* 0x18/24 */ unsigned long res_vptr;
};
struct CKeyTableEntry {
    /* 0x0/0 */ CResRef m_cResRef;
    /* 0x10/16 */ CRes *m_pRes;
    /* 0x14/20 */ unsigned long m_nID;
    /* 0x18/24 */ unsigned short m_nRefCount;
    /* 0x1A/26 */ unsigned short m_nType;
};
struct CDialogEntry {
    /* 0x0/0 */ unsigned long Speaker;
    /* 0x4/4 */ unsigned long SpeakerLen;
    /* 0x8/8 */ unsigned long Animation;
    /* 0xC/12 */ unsigned long AnimLoop;
    /* 0x10/16 */ CExoLocString Text;
    /* 0x18/24 */ CDialogEntryReply *RepliesList;
    /* 0x1C/28 */ unsigned long RepliesNum;
    /* 0x20/32 */ CResRef Script;
    /* 0x30/48 */ unsigned long Delay;
    /* 0x34/52 */ CResRef Sound;
    /* 0x44/68 */ unsigned long Quest;
    /* 0x48/72 */ unsigned long QuestLen;
    /* 0x4C/76 */ unsigned long QuestEntry;
};
struct CDialogReply {
    /* 0x0/0 */ unsigned long Animation;
    /* 0x4/4 */ unsigned long AnimLoop;
    /* 0x8/8 */ CExoLocString Text;
    /* 0x10/16 */ CDialogReplyEntry *EntriesList;
    /* 0x14/20 */ unsigned long EntriesNum;
    /* 0x18/24 */ CResRef Script;
    /* 0x28/40 */ unsigned long Delay;
    /* 0x2C/44 */ CResRef Sound;
    /* 0x3C/60 */ unsigned long Quest;
    /* 0x40/64 */ unsigned long QuestLen;
    /* 0x44/68 */ unsigned long QuestEntry;
};
struct CDialogEntryReply {
    /* 0x0/0 */ CResRef ConditionalScript;
    /* 0x10/16 */ unsigned long Index;
    /* 0x14/20 */ unsigned long DisplayInactive;
};
struct CDialogReplyEntry {
    /* 0x0/0 */ CResRef ConditionalScript;
    /* 0x10/16 */ unsigned long Index;
};
struct CActionParams {
    /* 0x0/0 */ CActionParam Params[12];
};
struct CNWSScriptVar {
    /* 0x0/0 */ CExoString m_sName;
    /* 0x8/8 */ unsigned long m_nType;
    /* 0xC/12 */  union {
        nwobjid Object;
        int Int;
        float Float;
        CExoString *String;
        CScriptLocation *Location;
    } m_pValue;
};
struct CNWItemProperty {
    unsigned short Type;
    unsigned short Subtype;
    unsigned char  CostTable;
    unsigned char  field_5;
    unsigned short CostValue;
    unsigned char  Param1;
    unsigned char  Param1Value;
    unsigned char  ChanceAppear;
    unsigned char  field_B;
    unsigned char  Useable;
    unsigned char  field_D;
    unsigned char  field_E;
    unsigned char  field_F;
    unsigned char  UsesPerDay;
    unsigned char  DurationType;

};
struct CNWSQuickbarButton {
};
struct CNWVisibilityNode {
};
struct CEncounterListEntry {
};
struct CNWSSoundObjectTimeOfDay {
};
struct CNWSAreaGridSuccessors {
};
struct CNWSPlayerLUOSortedObjectList {
};
struct CLastUpdatePartyObject {
};
struct CLinuxFileKey {
};
struct CNWSPlayerLUOInventoryItem {
};
struct CKeyTableInfo {
};
struct CNWSDialogPlayer {
};
struct CLinuxFileSection {
};
struct NWAreaExpansion_st {
};
struct NWModuleCutScene_st {
};
struct NWPlayerListItem_st {
};
struct NWModuleExpansion_st {
};
struct EncapsulatedResListEntry_st {
};
struct SCodeBaseData {
};
struct SRecord {
};
struct CResGFFField {
};
struct CResList {
};
struct CResGFFStruct {
};
struct CBaseExoApp {
};
struct CScriptParseTreeNode {
};
struct NWPlayerCharacterList_st {
};
struct CNWSTagNode {
    char Tag[64];
    unsigned long unknown;
    nwobjid ObjectID;
};
static_assert_size(CNWSTagNode, 0x48);
struct CNWSPVPEntry {
    nwobjid Object;
    unsigned long field_0004;
    int LikeStatus;
};
struct SJournalEntry {
};
struct SGameSpyRoomEntry {
};
struct CWorldJournalEntry {
};
struct CNWSInvitationDetails {
};
struct CNWSPersonalReputation {
};
struct CNetLayerPlayerCDKeyInfo {
};
struct CNWSPlayerJournalQuestUpdates {
};
struct NWPlayerCharacterListClass_st {
};
struct CFileInfo {
};
struct CScriptLog {
};
struct CSpell_Add {
};
struct SMstKeyEntry {
};
struct CSpell_Delete {
};
struct SMstNameEntry {
};
struct SMstBuddyEntry {
};
struct SSubNetProfile {
};
struct SMstDigiDistInfo {
};
struct CEffectIconObject {
};
struct CFeatUseListEntry {
};
struct CNWCAreaOfEffectObject {
};
struct CNWCArea {
};
struct CNWCCreature {
};
struct CNWCDoor {
};
struct CNWCItem {
};
struct CNWCModule {
};
struct CNWCObject {
};
struct CNWCPlaceable {
};
struct CNWCProjectile {
};
struct CNWCSoundObject {
};
struct CNWCStore {
};
struct CNWCTrigger {
};
struct PEERBool {
};
struct RoomType {
};
struct PEERJoinResult {
};
struct MessageType {
};
struct STR_RES {
    CExoString Text;
    CResRef SoundResRef;
    float SoundLength;
};
struct CTlkTableToken {
};
struct CNWTilePathNode {
};
struct CVirtualMachineDebuggingContext {
};
struct Quaternion {
};
struct CSpawnPoint {
    Vector Position;
    float Orientation;
};
struct CNWClass_FeatTableEntry {
    unsigned short FeatIndex;
    unsigned char GrantedOnLevel;
    unsigned char List;
    unsigned long Category;
    unsigned long MaxCR;
    unsigned long OnMenu;
};
struct CNWClass_SkillTableEntry {
    unsigned long SkillIndex;
    unsigned long ClassSkill;
};
#endif
