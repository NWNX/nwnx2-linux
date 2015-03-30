/* interface functions for nwnx_funcs plugin */

/* TODO:
 *
 */

const int CREATURE_EVENT_HEARTBEAT              = 0;
const int CREATURE_EVENT_PERCEPTION             = 1;
const int CREATURE_EVENT_SPELLCAST              = 2;
const int CREATURE_EVENT_ATTACKED               = 3;
const int CREATURE_EVENT_DAMAGED                = 4;
const int CREATURE_EVENT_DISTURBED              = 5;
const int CREATURE_EVENT_ENDCOMBAT              = 6;
const int CREATURE_EVENT_CONVERSATION           = 7;
const int CREATURE_EVENT_SPAWN                  = 8;
const int CREATURE_EVENT_RESTED                 = 9;
const int CREATURE_EVENT_DEATH                  = 10;
const int CREATURE_EVENT_USERDEF                = 11;
const int CREATURE_EVENT_BLOCKED                = 12;

// Supported by SetEventHandler() / GetEventHandler
int CREATURE_SCRIPT_ON_HEARTBEAT              = 0;
int CREATURE_SCRIPT_ON_NOTICE                 = 1;
int CREATURE_SCRIPT_ON_SPELLCASTAT            = 2;
int CREATURE_SCRIPT_ON_MELEE_ATTACKED         = 3;
int CREATURE_SCRIPT_ON_DAMAGED                = 4;
int CREATURE_SCRIPT_ON_DISTURBED              = 5;
int CREATURE_SCRIPT_ON_END_COMBATROUND        = 6;
int CREATURE_SCRIPT_ON_DIALOGUE               = 7;
int CREATURE_SCRIPT_ON_SPAWN_IN               = 8;
int CREATURE_SCRIPT_ON_RESTED                 = 9;
int CREATURE_SCRIPT_ON_DEATH                  = 10;
int CREATURE_SCRIPT_ON_USER_DEFINED_EVENT     = 11;
int CREATURE_SCRIPT_ON_BLOCKED_BY_DOOR        = 12;
// Trigger
int SCRIPT_TRIGGER_ON_HEARTBEAT          = 0;
int SCRIPT_TRIGGER_ON_OBJECT_ENTER       = 1;
int SCRIPT_TRIGGER_ON_OBJECT_EXIT        = 2;
int SCRIPT_TRIGGER_ON_USER_DEFINED_EVENT = 3;
int SCRIPT_TRIGGER_ON_TRAPTRIGGERED      = 4;
int SCRIPT_TRIGGER_ON_DISARMED           = 5;
int SCRIPT_TRIGGER_ON_CLICKED            = 6;
// Area
int SCRIPT_AREA_ON_HEARTBEAT            = 0;
int SCRIPT_AREA_ON_USER_DEFINED_EVENT   = 1;
int SCRIPT_AREA_ON_ENTER                = 2;
int SCRIPT_AREA_ON_EXIT                 = 3;
int SCRIPT_AREA_ON_CLIENT_ENTER	        = 4;
// Door
int SCRIPT_DOOR_ON_OPEN            = 0;
int SCRIPT_DOOR_ON_CLOSE           = 1;
int SCRIPT_DOOR_ON_DAMAGE          = 2;
int SCRIPT_DOOR_ON_DEATH           = 3;
int SCRIPT_DOOR_ON_DISARM          = 4;
int SCRIPT_DOOR_ON_HEARTBEAT       = 5;
int SCRIPT_DOOR_ON_LOCK            = 6;
int SCRIPT_DOOR_ON_MELEE_ATTACKED  = 7;
int SCRIPT_DOOR_ON_SPELLCASTAT     = 8;
int SCRIPT_DOOR_ON_TRAPTRIGGERED   = 9;
int SCRIPT_DOOR_ON_UNLOCK          = 10;
int SCRIPT_DOOR_ON_USERDEFINED     = 11;
int SCRIPT_DOOR_ON_CLICKED         = 12;
int SCRIPT_DOOR_ON_DIALOGUE        = 13;
int SCRIPT_DOOR_ON_FAIL_TO_OPEN    = 14;
// Encounter
int SCRIPT_ENCOUNTER_ON_OBJECT_ENTER        = 0;
int SCRIPT_ENCOUNTER_ON_OBJECT_EXIT         = 1;
int SCRIPT_ENCOUNTER_ON_HEARTBEAT           = 2;
int SCRIPT_ENCOUNTER_ON_ENCOUNTER_EXHAUSTED = 3;
int SCRIPT_ENCOUNTER_ON_USER_DEFINED_EVENT  = 4;
// Module
int SCRIPT_MODULE_ON_HEARTBEAT              = 0;
int SCRIPT_MODULE_ON_USER_DEFINED_EVENT     = 1;
int SCRIPT_MODULE_ON_MODULE_LOAD            = 2;
int SCRIPT_MODULE_ON_MODULE_START           = 3;
int SCRIPT_MODULE_ON_CLIENT_ENTER           = 4;
int SCRIPT_MODULE_ON_CLIENT_EXIT            = 5;
int SCRIPT_MODULE_ON_ACTIVATE_ITEM          = 6;
int SCRIPT_MODULE_ON_ACQUIRE_ITEM           = 7;
int SCRIPT_MODULE_ON_LOSE_ITEM              = 8;
int SCRIPT_MODULE_ON_PLAYER_DEATH           = 9;
int SCRIPT_MODULE_ON_PLAYER_DYING           = 10;
int SCRIPT_MODULE_ON_RESPAWN_BUTTON_PRESSED = 11;
int SCRIPT_MODULE_ON_PLAYER_REST            = 12;
int SCRIPT_MODULE_ON_PLAYER_LEVEL_UP        = 13;
int SCRIPT_MODULE_ON_PLAYER_CANCEL_CUTSCENE = 14;
int SCRIPT_MODULE_ON_EQUIP_ITEM             = 15;
int SCRIPT_MODULE_ON_UNEQUIP_ITEM           = 16;
// Placeable
int SCRIPT_PLACEABLE_ON_CLOSED              = 0;
int SCRIPT_PLACEABLE_ON_DAMAGED             = 1;
int SCRIPT_PLACEABLE_ON_DEATH               = 2;
int SCRIPT_PLACEABLE_ON_DISARM              = 3;
int SCRIPT_PLACEABLE_ON_HEARTBEAT           = 4;
int SCRIPT_PLACEABLE_ON_INVENTORYDISTURBED  = 5;
int SCRIPT_PLACEABLE_ON_LOCK                = 6;
int SCRIPT_PLACEABLE_ON_MELEEATTACKED       = 7;
int SCRIPT_PLACEABLE_ON_OPEN                = 8;
int SCRIPT_PLACEABLE_ON_SPELLCASTAT         = 9;
int SCRIPT_PLACEABLE_ON_TRAPTRIGGERED       = 10;
int SCRIPT_PLACEABLE_ON_UNLOCK              = 11;
int SCRIPT_PLACEABLE_ON_USED                = 12;
int SCRIPT_PLACEABLE_ON_USER_DEFINED_EVENT  = 13;
int SCRIPT_PLACEABLE_ON_DIALOGUE            = 14;
// AOE
int SCRIPT_AOE_ON_HEARTBEAT            = 0;
int SCRIPT_AOE_ON_USER_DEFINED_EVENT   = 1;
int SCRIPT_AOE_ON_OBJECT_ENTER         = 2;
int SCRIPT_AOE_ON_OBJECT_EXIT          = 3;
// Store
int SCRIPT_STORE_ON_OPEN              = 0;
int SCRIPT_STORE_ON_CLOSE             = 1;

const int MOVEMENT_RATE_PC                      = 0;
const int MOVEMENT_RATE_IMMOBILE                = 1;
const int MOVEMENT_RATE_VERY_SLOW               = 2;
const int MOVEMENT_RATE_SLOW                    = 3;
const int MOVEMENT_RATE_NORMAL                  = 4;
const int MOVEMENT_RATE_FAST                    = 5;
const int MOVEMENT_RATE_VERY_FAST               = 6;
const int MOVEMENT_RATE_DEFAULT                 = 7;
const int MOVEMENT_RATE_DM_FAST                 = 8;

const int VARIABLE_TYPE_INT                     = 1;
const int VARIABLE_TYPE_FLOAT                   = 2;
const int VARIABLE_TYPE_STRING                  = 3;
const int VARIABLE_TYPE_OBJECT                  = 4;
const int VARIABLE_TYPE_LOCATION                = 5;

const int QUICKBAR_TYPE_ITEM                    = 1;
const int QUICKBAR_TYPE_SPELL                   = 2;
const int QUICKBAR_TYPE_FEAT                    = 4;


struct MemorizedSpellSlot {
    int id;
    int ready, meta, domain;
};

struct SpecialAbilitySlot {
    int id;
    int ready, level;
};

struct QuickBarSlot {
    int slot;
    int type, class;
    int id, meta;
};

struct LocalVariable {
    int type, pos;
    string name;
    object obj;
};

struct CreatureAbilities {
    int a_str;
    int a_dex;
    int a_con;
    int a_int;
    int a_wis;
    int a_cha;
};

struct CreatureSkills {
    int sk_aniemp;
    int sk_conc;
    int sk_distrap;
    int sk_disc;
    int sk_heal;
    int sk_hide;
    int sk_listen;
    int sk_lore;
    int sk_movesil;
    int sk_openlock;
    int sk_parry;
    int sk_perform;
    int sk_persuade;
    int sk_ppocket;
    int sk_search;
    int sk_settrap;
    int sk_spcraft;
    int sk_spot;
    int sk_taunt;
    int sk_umd;
    int sk_appraise;
    int sk_tumble;
    int sk_ctrap;
    int sk_bluff;
    int sk_intim;
    int sk_carmor;
    int sk_cweapon;
    int sk_ride;
};

struct Timeval {
    int sec;
    int usec;
};

/* Returns TRUE if the target inherently knows a feat (as opposed to
 * by any equipment they may possess) */
int GetKnowsFeat (int nFeatId, object oCreature);

/* returns oCreature's damage immunity against nDamType. */
int GetDamageImmunity (object oCreature, int nDamType);

/* Sets oCreature's ability score nAbility to nValue. */
int SetAbilityScore (object oCreature, int nAbility, int nValue);

/* Sets oCreature's base skill rank for nSkill to nValue. */
int SetSkillRank (object oCreature, int nSkill, int nValue);

/* Modifies oCreature's ability score nAbility by nValue. */
int ModifyAbilityScore (object oCreature, int nAbility, int nValue);

/* Modifies oCreature's base skill rank for nSkill by nValue. */
int ModifySkillRank (object oCreature, int nSkill, int nValue);

/* Modifies oCreature's base skill rank for nSkill at nLevel by nValue. */
int ModifySkillRankByLevel (object oCreature, int nLevel, int nSkill, int nValue);

/* Gets oCreature's natural base AC */
int GetACNaturalBase (object oCreature);

/* Sets oCreature's natural base AC */
int SetACNaturalBase (object oCreature, int nAC);

/* Adds nFeat to oCreature. Does not check if the creature already knows
 * the feat. If the feat has limited uses per day and is added to a PC,
 * the PC must relog for proper use limiting. If nLevel is specified,
 * the feat will also be added to the specified level stat list. */
int AddKnownFeat (object oCreature, int nFeat, int nLevel=-1);

/* Removes nFeat from oCreature if it knows the feat inherently. */
int RemoveKnownFeat (object oCreature, int nFeat);

/* Gets the total number of feats known by oCreature. */
int GetTotalKnownFeats (object oCreature);

/* Gets the feat at nIndex in oCreature's feat list. */
int GetKnownFeat (object oCreature, int nIndex);

/* Sets the feat at nIndex in oCreature's feat list. */
int SetKnownFeat (object oCreature, int nIndex, int nFeat);

/* Gets the total number of feats earned by oCreature at nLevel. */
int GetTotalKnownFeatsByLevel (object oCreature, int nLevel);

/* Gets the feat at nIndex in oCreature's level stat list for feats */
int GetKnownFeatByLevel (object oCreature, int nLevel, int nIndex);

/* Sets the feat at nIndex in oCreature's level stat list for feats. */
int SetKnownFeatByLevel (object oCreature, int nLevel, int nIndex, int nFeat);

/* Get the number of remaining feat uses for nFeat for oCreature. */
int GetRemainingFeatUses (object oCreature, int nFeat);

/* Get the total number of feat uses for nFeat for oCreature. */
int GetTotalFeatUses (object oCreature, int nFeat);

/* Get a string containing all remaining feat uses for oCreature. */
string GetAllRemainingFeatUses (object oCreature);

/* Restore the remaining feat uses for oCreature from the given string. */
int RestoreReadyFeats (object oCreature, string sFeats);

/* Check if oCreature meets the requirements to take nFeat. */
int GetMeetsFeatRequirements (object oCreature, int nFeat);

/* Check if oCreature would be able to take nFeat after taking a level in
 * nClass, raising nAbility by 1 point, and raising the skills given in
 * sk. If no ability is being raised, nAbility should be passed as -1. */
int GetMeetsLevelUpFeatRequirements (object oCreature, int nFeat, int nClass, int nAbility, struct CreatureSkills sk);

/* Check if nFeat is a bonus feat for nClass. */
int GetIsClassBonusFeat (int nClass, int nFeat);

/* Check if nFeat is a general feat for nClass. */
int GetIsClassGeneralFeat (int nClass, int nFeat);

/* Check if nFeat is a granted feat for nClass. If it is, return the class
 * level the feat would be granted on. */
int GetIsClassGrantedFeat (int nClass, int nFeat);

/* Check if nSkill is a class skill for nClass. If the class cannot raise
 * the skill at all (e.g. Perform for non-bards), returns -1. */
int GetIsClassSkill (int nClass, int nSkill);

/* Gets the class taken by oCreature at nLevel. */
int GetClassByLevel (object oCreature, int nLevel);

/* Gets the ability which was increased at nLevel. */
int GetAbilityIncreaseByLevel (object oCreature, int nLevel);

/* Gets the amount nSkill was increased at nLevel. */
int GetSkillIncreaseByLevel (object oCreature, int nLevel, int nSkill);

/* Gets the base saving throw bonus for nSave for nCreature. */
int GetSavingThrowBonus (object oCreature, int nSave);

/* Sets the base saving throw bonus for nSave to nValue for oCreature. */
int SetSavingThrowBonus (object oCreature, int nSave, int nValue);

/* Modifies oCreature's base saving throw bonus for nSave by nValue. */
int ModifySavingThrowBonus (object oCreature, int nSave, int nValue);

/* Gets the maximum hit points for oCreature for nLevel. */
int GetMaxHitPointsByLevel (object oCreature, int nLevel);

/* Sets the maximum hit points for oCreature for nLevel to nValue. */
int SetMaxHitPointsByLevel (object oCreature, int nLevel, int nValue);

/* Sets oCreature's gender using a GENDER_* constant. */
int SetGender (object oCreature, int nGender);

/* Sets oCreature's size using a CREATURE_SIZE_* constant. */
int SetCreatureSize (object oCreature, int nSize);

/* Gets oPC's remaining skill points. */
int GetPCSkillPoints (object oPC);

/* Sets oPC's remaining skill points. */
int SetPCSkillPoints (object oPC, int nSkillPoints);

/* Sets the value of Lootable for a PC in the range 0-127. */
int SetPCLootable (object oPC, int nLootable);

/* Gets the value of BodyBag for a PC. */
int GetPCBodyBag (object oPC);

/* Sets the value of BodyBag for a PC in the range 0-127. */
int SetPCBodyBag (object oPC, int nBodyBag);

/* Set oCreature's raw good/evil alignment value. */
int SetAlignmentGoodEvil (object oCreature, int nValue);

/* Set oCreature's raw law/chaos alignment value. */
int SetAlignmentLawChaos (object oCreature, int nValue);

/* Modify oCreature's current hit points */
int ModifyCurrentHitPoints (object oCreature, int nHP);

/* Set oCreature's current hit points */
int SetCurrentHitPoints (object oCreature, int nHP);

/* Set oCreature's maximum hit points; will not work on PCs. */
int SetMaxHitPoints (object oCreature, int nHP);

/* Check if oCreature knows the specified spell (this will only work for arcane casters) */
int GetKnowsSpell (int nSpellId, object oCreature, int nClass=CLASS_TYPE_INVALID);

/* Get the spell at nIndex in nSpellLevel in oCreature's spellbook from nClass. */
int GetKnownSpell (object oCreature, int nClass, int nSpellLevel, int nIndex);

/* Set the spell at nIndex in nSpellLevel in oCreature's spellbook from nClass. */
int SetKnownSpell (object oCreature, int nClass, int nSpellLevel, int nIndex, int nSpellId);

/* Get the total number of known spells for oCreature's spellbook in nClass at nSpellLevel. */
int GetTotalKnownSpells (object oCreature, int nClass, int nSpellLevel);

/* Add a new spell to oCreature's spellbook for nClass. */
int AddKnownSpell (object oCreature, int nClass, int nSpellLevel, int nSpellId);

/* Remove a spell from oCreature's spellbook for nClass. */
int RemoveKnownSpell (object oCreature, int nClass, int nSpellLevel, int nSpellId);

/* Replace a spell in oCreature's spellbook for nClass. */
int ReplaceKnownSpell (object oCreature, int nClass, int nOldSpell, int nNewSpell);

/* Get information about one of oCreature's memorized spells. */
struct MemorizedSpellSlot GetMemorizedSpell (object oCreature, int nClass, int nLevel, int nIndex);

/* Set information about oCreature's memorized spells. */
int SetMemorizedSpell (object oCreature, int nClass, int nLevel, int nIndex, struct MemorizedSpellSlot mss);

/* Clear one of oCreature's memorized spells. */
int ClearMemorizedSpell (object oCreature, int nClass, int nLevel, int nIndex);

/* Get the maximum number of oCreature's spell slots at nClass and nSpellLevel. */
int GetMaxSpellSlots (object oCreature, int nClass, int nSpellLevel);

/* Get the number of bonus spell slots oCreature has at nClass and nSpellLevel.
 * This value only includes bonus slots from equipment and effects, not from
 * having a high ability score. */
int GetBonusSpellSlots (object oCreature, int nClass, int nSpellLevel);

/* Get the number of remaining spell slots oCreature has at nClass and
 * nSpellLevel (only applies for bards and sorcerers) */
int GetRemainingSpellSlots (object oCreature, int nClass, int nSpellLevel);

/* Set the number of remaining spell slots oCreature has at nClass and
 * nSpellLevel (only applies for bards and sorcerers) */
int SetRemainingSpellSlots (object oCreature, int nClass, int nSpellLevel, int nSlots);

/* Get a string containing all remaining spell uses for oCreature. */
string GetAllMemorizedSpells (object oCreature);

/* Restore the remaining spell uses for oCreature from the given string. */
int RestoreReadySpells (object oCreature, string sSpells);

/* Gets one of oCreature's cleric domains (either 1 or 2). */
int GetClericDomain (object oCreature, int nIndex);

/* Sets one of oCreature's cleric domains. */
int SetClericDomain (object oCreature, int nIndex, int nDomain);

/* Gets whether or not oCreature has a specialist school of wizardry. */
int GetWizardSpecialization (object oCreature);

/* Sets oCreature's wizard specialist school. */
int SetWizardSpecialization (object oCreature, int nSchool);


struct SpecialAbilitySlot GetSpecialAbility (object oCreature, int nIndex);
int SetSpecialAbility (object oCreature, int nIndex, struct SpecialAbilitySlot sas);
int GetTotalSpecialAbilities (object oCreature);
int AddSpecialAbility (object oCreature, struct SpecialAbilitySlot sas);
int RemoveSpecialAbility (object oCreature, int nIndex);


string GetRawQuickBarSlot (object oPC, int nSlot);
void SetRawQuickBarSlot (object oPC, string sSlot);


/* Get the name of the portrait oCreature is using. */
string GetPortrait (object oCreature);

/* Set the portrait oCreature is using. The portrait string must be no more
 * than 15 characters long. */
int SetPortrait (object oCreature, string sPortrait);

/* Get the soundset index for oCreature. */
int GetSoundset (object oCreature);

/* Set the soundset index for oCreature. */
int SetSoundset (object oCreature, int nSoundset);

/* Set the creature who created oTrap to oCreator. */
int SetTrapCreator (object oTrap, object oCreator);

/* Get oCreature's conversation file name. */
string GetConversation (object oCreature);

/* Set oCreature's conversation file name. */
string SetConversation (object oCreature, string sConv);

/* Get if a local variable structure is valid. */
int GetIsVariableValid (struct LocalVariable lv);

/* Get the number of local variables on oObject. */
int GetLocalVariableCount (object oObject);

/* Get the nPos local variable from oObject. */
struct LocalVariable GetLocalVariableByPosition (object oObject, int nPos);

/* Get the first local variable from an object. */
struct LocalVariable GetFirstLocalVariable (object oObject);

/* Get the next local variable from an object. */
struct LocalVariable GetNextLocalVariable (struct LocalVariable lv);

/* Get the first area in the module. */
object GetFirstArea ();

/* Get the next area in the module. */
object GetNextArea ();

/* Set oItem's base item type. */
int SetBaseItemType (object oItem, int nBaseItem);

/* Set oItem's value in gold pieces. Will not persist through zoning or saving. */
int SetGoldPieceValue (object oItem, int nValue);

/* Set oItem's weight. Will not persist through zoning or saving. */
int SetItemWeight (object oItem, int nTenthLbs);

/* Return a string containing the entire appearance for oItem which can later be
 * passed to RestoreItemAppearance(). */
string GetEntireItemAppearance (object oItem);

/* Restore an item's appearance with the value returned by GetEntireItemAppearance(). */
void RestoreItemAppearance (object oItem, string sApp);

/* Directly set an appearance value on an item. This will not be visible to PCs until
 * the item is refreshed for them (e.g. by logging out and back in). */
int SetItemAppearance (object oItem, int nIndex, int nValue);

/* Directly set a color value on an item. This will not be visible to PCs until the
 * item is refreshed for them (e.g. by logging out and back in). */
int SetItemColor (object oItem, int nIndex, int nColor);

int GetIsStatic (object oPlace);

/* Set oPlace's appearance. Will not update for PCs until they re-enter the area. */
int SetPlaceableAppearance (object oPlace, int nApp);

/* Get the ground height from a position or location. */
float GetGroundHeight (object oArea, vector vPos);
float GetGroundHeightFromLocation (location lLoc);

/* Get whether or not a position or location is walkable. */
int GetIsWalkable (object oArea, vector vPos);
int GetIsWalkableLocation (location lLoc);

/* Use the specified item on the specified location. */
void ActionUseItemAtLocation (object oItem, location lTarget, int nProp=0);

/* Use the specified item on the specified object. */
void ActionUseItemOnObject (object oItem, object oTarget, int nProp=0);

/* Get oPC's local connection port. */
int GetPCPort (object oPC);

/* Boot oPC, displaying the specified strref on their computer. */
void BootPCWithMessage (object oPC, int nStrRef);

/* Get oCreature's event handler for nEvent. */
string GetCreatureEventHandler (object oCreature, int nEvent);

/* Set oCreature's event handler for nEvent. */
string SetCreatureEventHandler (object oCreature, int nEvent, string sScript);

/* Get oObject's event handler for nEvent. */
string GetEventHandler (object oObject, int nEvent);

/* Set oObject's event handler for nEvent. */
string SetEventHandler (object oObject, int nEvent, string sScript);

/* Get oObject's faction ID. */
int GetFactionId (object oObject);

/* Set oObject's faction ID. */
int SetFactionId (object oObject, int nFaction);

/* Set oObject's last hostile actor. */
void SetLastHostileActor (object oObject, object oActor);

/* Get the item at nPos in oCreature's inventory. */
object GetItemByPosition (object oCreature, int nPos);

/* Get the total number of items carried by oCreature. */
int GetItemCount (object oCreature);

/* Set oCreature's movement rate. */
int SetMovementRate (object oCreature, int nRate);

/* Set oCreature's racial type. Do not use on PCs. */
int SetRacialType (object oCreature, int nRacialType);

/* Set oObject's tag. */
string SetTag (object oObject, string sTag);

/* Get oPC's bic file name */
string GetPCFileName (object oPC);

/* Jump oCreature to Limbo. */
void JumpToLimbo (object oCreature);

/* Broadcast the projectile for nSpellId going from oSource to oTarget. nDelay
 * is in milliseconds (1000=1s). If nSpellId is -1, the projectile for
 * oSource's weapon (e.g. an arrow if oSource is wielding a bow) will be
 * displayed.
 *
 * This will display cones for cone spells as well, though they will always
 * be forward-facing from oSource. */
int BroadcastProjectileToObject (object oSource, object oTarget, int nSpellId, int nDelay=-1);

/* As for BroadcastProjectileToObject(), but to a target location. */
int BroadcastProjectileToLocation (object oSource, location lTarget, int nSpellId, int nDelay=-1);

//Sets disarm flag on oCreature
//Returns:
//  1 on success
//  0 on failure
//Note: standard function GetIsCreatureDisarmable() also takes into account weapon in creature's right hand besides disarm flag itself
int SetIsCreatureDisarmable(object oCreature, int bDisarmable);

/* Convert an object ID to an object. */
object IntToObject (int nObjectId);
object StringToObject (string sObjectId);

/* Dump oObject to the NWNX log. */
void DumpObject (object oObject);

/* Sleep for the given number of microseconds. This will block the whole nwserver process. */
void USleep (int usec);

/* Returns the current system time.
 * Returns .sec = 0 and .usec = 0 on failure. */
struct Timeval GetTimeOfDay();

//Sets oCreature's corpse decay time in milliseconds
//Returns:
//  1 on success
//  0 on failure
int SetCorpseDecayTime(object oCreature, int nTime);

//Returns:
//  oCreature's corpse decay time in milliseconds on success
//  0 on failure
int GetCorpseDecayTime(object oCreature);


int NWNXFuncsZero (object oObject, string sFunc) {
    SetLocalString(oObject, sFunc, "          ");
    return StringToInt(GetLocalString(oObject, sFunc));
}

int NWNXFuncsOne (object oObject, string sFunc, int nVal1) {
    SetLocalString(oObject, sFunc, IntToString(nVal1) + "          ");
    return StringToInt(GetLocalString(oObject, sFunc));
}

int NWNXFuncsTwo (object oObject, string sFunc, int nVal1, int nVal2) {
    SetLocalString(oObject, sFunc, IntToString(nVal1) + " " + IntToString(nVal2) + "          ");
    return StringToInt(GetLocalString(oObject, sFunc));
}

int NWNXFuncsThree (object oObject, string sFunc, int nVal1, int nVal2, int nVal3) {
    SetLocalString(oObject, sFunc, IntToString(nVal1) + " " + IntToString(nVal2) +
      " " + IntToString(nVal3) + "          ");
    return StringToInt(GetLocalString(oObject, sFunc));
}


void USleep (int usec) {
    NWNXFuncsOne(GetModule(), "NWNX!FUNCS!USLEEP", usec);
}

struct Timeval GetTimeOfDay() {
    struct Timeval ret;
    string sFunc = "NWNX!FUNCS!GETTIMEOFDAY";
    SetLocalString(GetModule(),
        sFunc, "                                         ");
    string time = GetLocalString(GetModule(), sFunc);
    int idx = FindSubString(time, ".");
    if (-1 != idx) {
        ret.sec = StringToInt(GetSubString(time, 0, idx));
        ret.usec = StringToInt(GetSubString(time, idx + 1, 32));
    }
    return ret;
}

int SetAbilityScore (object oCreature, int nAbility, int nValue) {
    return NWNXFuncsTwo(oCreature, "NWNX!FUNCS!SETABILITYSCORE", nAbility, nValue);
}

int ModifyAbilityScore (object oCreature, int nAbility, int nValue) {
    return NWNXFuncsTwo(oCreature, "NWNX!FUNCS!MODIFYABILITYSCORE", nAbility, nValue);
}


int SetSkillRank (object oCreature, int nSkill, int nValue) {
    return NWNXFuncsTwo(oCreature, "NWNX!FUNCS!SETSKILLRANK", nSkill, nValue);
}

int ModifySkillRank (object oCreature, int nSkill, int nValue) {
    return NWNXFuncsTwo(oCreature, "NWNX!FUNCS!MODIFYSKILLRANK", nSkill, nValue);
}

int ModifySkillRankByLevel (object oCreature, int nLevel, int nSkill, int nValue) {
    return NWNXFuncsThree(oCreature, "NWNX!FUNCS!MODIFYSKILLRANKBYLEVEL", nLevel, nSkill, nValue);
}


int GetACNaturalBase (object oCreature) {
    return NWNXFuncsZero(oCreature, "NWNX!FUNCS!GETACNATURALBASE");
}

int SetACNaturalBase (object oCreature, int nAC) {
    return NWNXFuncsOne(oCreature, "NWNX!FUNCS!SETACNATURALBASE", nAC);
}


int GetKnowsFeat (int nFeatId, object oCreature) {
    return NWNXFuncsOne(oCreature, "NWNX!FUNCS!GETKNOWSFEAT", nFeatId);
}

int AddKnownFeat (object oCreature, int nFeat, int nLevel=-1) {
    if (nLevel == 0)
        nLevel = GetHitDice(oCreature);

    if (nLevel > 0)
        return NWNXFuncsTwo(oCreature, "NWNX!FUNCS!ADDKNOWNFEATATLEVEL", nLevel, nFeat);

    return NWNXFuncsOne(oCreature, "NWNX!FUNCS!ADDKNOWNFEAT", nFeat);
}

int RemoveKnownFeat (object oCreature, int nFeat) {
    return NWNXFuncsOne(oCreature, "NWNX!FUNCS!REMOVEKNOWNFEAT", nFeat);
}


int GetTotalKnownFeats (object oCreature) {
    return NWNXFuncsZero(oCreature, "NWNX!FUNCS!GETTOTALKNOWNFEATS");
}

int GetKnownFeat (object oCreature, int nIndex) {
    return NWNXFuncsOne(oCreature, "NWNX!FUNCS!GETKNOWNFEAT", nIndex);
}

int SetKnownFeat (object oCreature, int nIndex, int nFeat) {
    return NWNXFuncsTwo(oCreature, "NWNX!FUNCS!SETKNOWNFEAT", nIndex, nFeat);
}


int GetTotalKnownFeatsByLevel (object oCreature, int nLevel) {
    return NWNXFuncsOne(oCreature, "NWNX!FUNCS!GETTOTALKNOWNFEATSBYLEVEL", nLevel);
}

int GetKnownFeatByLevel (object oCreature, int nLevel, int nIndex) {
    return NWNXFuncsTwo(oCreature, "NWNX!FUNCS!GETKNOWNFEATBYLEVEL", nLevel, nIndex);
}

int SetKnownFeatByLevel (object oCreature, int nLevel, int nIndex, int nFeat) {
    return NWNXFuncsThree(oCreature, "NWNX!FUNCS!SETKNOWNFEATBYLEVEL", nLevel, nIndex, nFeat);
}


int GetRemainingFeatUses (object oCreature, int nFeat) {
    return NWNXFuncsOne(oCreature, "NWNX!FUNCS!GETREMAININGFEATUSES", nFeat);
}

int GetTotalFeatUses (object oCreature, int nFeat) {
    return NWNXFuncsOne(oCreature, "NWNX!FUNCS!GETTOTALFEATUSES", nFeat);
}


string GetAllRemainingFeatUses (object oCreature) {
    string sFeats = GetLocalString(GetModule(), "NWNX!ODBC!SPACER");

    SetLocalString(oCreature, "NWNX!FUNCS!GETALLREMAININGFEATUSES", sFeats + sFeats + sFeats + sFeats);
    sFeats = GetLocalString(oCreature, "NWNX!FUNCS!GETALLREMAININGFEATUSES");
    DeleteLocalString(oCreature, "NWNX!FUNCS!GETALLREMAININGFEATUSES");

    return sFeats;
}

int RestoreReadyFeats (object oCreature, string sFeats) {
    SetLocalString(oCreature, "NWNX!FUNCS!RESTOREREADYFEATS", sFeats + " ");
    return StringToInt(GetLocalString(oCreature, "NWNX!FUNCS!RESTOREREADYFEATS"));
}


int GetMeetsFeatRequirements (object oCreature, int nFeat) {
    return NWNXFuncsOne(oCreature, "NWNX!FUNCS!GETMEETSFEATREQUIREMENTS", nFeat);
}

int GetMeetsLevelUpFeatRequirements (object oCreature, int nFeat, int nClass, int nAbility, struct CreatureSkills sk) {
    SetLocalString(oCreature, "NWNX!FUNCS!GETMEETSFEATREQUIREMENTS", ">" + 
        IntToString(nFeat)          + " " +
        IntToString(nClass)         + " " +
        IntToString(nAbility)       + " ¬" +
        IntToString(sk.sk_aniemp)   + "¬" +
        IntToString(sk.sk_conc)     + "¬" +
        IntToString(sk.sk_distrap)  + "¬" +
        IntToString(sk.sk_disc)     + "¬" +
        IntToString(sk.sk_heal)     + "¬" +
        IntToString(sk.sk_hide)     + "¬" +
        IntToString(sk.sk_listen)   + "¬" +
        IntToString(sk.sk_lore)     + "¬" +
        IntToString(sk.sk_movesil)  + "¬" +
        IntToString(sk.sk_openlock) + "¬" +
        IntToString(sk.sk_parry)    + "¬" +
        IntToString(sk.sk_perform)  + "¬" +
        IntToString(sk.sk_persuade) + "¬" +
        IntToString(sk.sk_ppocket)  + "¬" +
        IntToString(sk.sk_search)   + "¬" +
        IntToString(sk.sk_settrap)  + "¬" +
        IntToString(sk.sk_spcraft)  + "¬" +
        IntToString(sk.sk_spot)     + "¬" +
        IntToString(sk.sk_taunt)    + "¬" +
        IntToString(sk.sk_umd)      + "¬" +
        IntToString(sk.sk_appraise) + "¬" +
        IntToString(sk.sk_tumble)   + "¬" +
        IntToString(sk.sk_ctrap)    + "¬" +
        IntToString(sk.sk_bluff)    + "¬" +
        IntToString(sk.sk_intim)    + "¬" +
        IntToString(sk.sk_carmor)   + "¬" +
        IntToString(sk.sk_cweapon)  + "¬" +
        IntToString(sk.sk_ride));
    return StringToInt(GetLocalString(oCreature, "NWNX!FUNCS!GETMEETSFEATREQUIREMENTS"));
}


int GetIsClassBonusFeat (int nClass, int nFeat) {
    return NWNXFuncsTwo(GetModule(), "NWNX!FUNCS!GETISCLASSBONUSFEAT", nClass, nFeat);
}

int GetIsClassGeneralFeat (int nClass, int nFeat) {
    return NWNXFuncsTwo(GetModule(), "NWNX!FUNCS!GETISCLASSGENERALFEAT", nClass, nFeat);
}

int GetIsClassGrantedFeat (int nClass, int nFeat) {
    return NWNXFuncsTwo(GetModule(), "NWNX!FUNCS!GETISCLASSGRANTEDFEAT", nClass, nFeat);
}

int GetIsClassSkill (int nClass, int nSkill) {
    return NWNXFuncsTwo(GetModule(), "NWNX!FUNCS!GETISCLASSSKILL", nClass, nSkill);
}


int GetClassByLevel (object oCreature, int nLevel) {
    return NWNXFuncsOne(oCreature, "NWNX!FUNCS!GETCLASSBYLEVEL", nLevel);
}

int GetAbilityIncreaseByLevel (object oCreature, int nLevel) {
    return NWNXFuncsOne(oCreature, "NWNX!FUNCS!GETABILITYINCREASEBYLEVEL", nLevel);
}

int GetSkillIncreaseByLevel (object oCreature, int nLevel, int nSkill) {
    return NWNXFuncsTwo(oCreature, "NWNX!FUNCS!GETSKILLINCREASEBYLEVEL", nLevel, nSkill);
}


int GetSavingThrowBonus (object oCreature, int nSave) {
    return NWNXFuncsOne(oCreature, "NWNX!FUNCS!GETSAVINGTHROWBONUS", nSave);
}

int SetSavingThrowBonus (object oCreature, int nSave, int nValue) {
    return NWNXFuncsTwo(oCreature, "NWNX!FUNCS!SETSAVINGTHROWBONUS", nSave, nValue);
}

int ModifySavingThrowBonus (object oCreature, int nSave, int nValue) {
    if (nSave < 1 || nSave > 3)
        return -1;

    int nBonus = GetSavingThrowBonus(oCreature, nSave) + nValue;

    if (nBonus < 0)
        nBonus = 0;
    else if (nBonus > 127)
        nBonus = 127;

    return SetSavingThrowBonus(oCreature, nSave, nBonus);
}


int GetMaxHitPointsByLevel (object oCreature, int nLevel) {
    return NWNXFuncsOne(oCreature, "NWNX!FUNCS!GETMAXHITPOINTSBYLEVEL", nLevel);
}

int SetMaxHitPointsByLevel (object oCreature, int nLevel, int nValue) {
    return NWNXFuncsTwo(oCreature, "NWNX!FUNCS!SETMAXHITPOINTSBYLEVEL", nLevel, nValue);
}


int SetGender (object oCreature, int nSize) {
    return NWNXFuncsOne(oCreature, "NWNX!FUNCS!SETGENDER", nSize);
}

int SetCreatureSize (object oCreature, int nSize) {
    return NWNXFuncsOne(oCreature, "NWNX!FUNCS!SETCREATURESIZE", nSize);
}


int GetCriticalHitMultiplier (object oCreature, int bOffhand) {
    return NWNXFuncsOne(oCreature, "NWNX!FUNCS!GETCRITICALHITMULTIPLIER", bOffhand);
}

int GetCriticalHitRange (object oCreature, int bOffhand) {
    return NWNXFuncsOne(oCreature, "NWNX!FUNCS!GETCRITICALHITRANGE", bOffhand);
}


int GetPCSkillPoints (object oPC) {
    return NWNXFuncsZero(oPC, "NWNX!FUNCS!GETPCSKILLPOINTS");
}

int SetPCSkillPoints (object oPC, int nSkillPoints) {
    return NWNXFuncsOne(oPC, "NWNX!FUNCS!SETPCSKILLPOINTS", nSkillPoints);
}


int SetPCLootable (object oPC, int nLootable) {
    return NWNXFuncsOne(oPC, "NWNX!FUNCS!SETPCLOOTABLE", nLootable);
}


int GetPCBodyBag (object oPC) {
    return NWNXFuncsZero(oPC, "NWNX!FUNCS!GETPCBODYBAG");
}

int SetPCBodyBag (object oPC, int nBodyBag) {
    return NWNXFuncsOne(oPC, "NWNX!FUNCS!SETPCBODYBAG", nBodyBag);
}


int GetDamageImmunity (object oCreature, int nDamType) {
    return NWNXFuncsOne(oCreature, "NWNX!FUNCS!GETDAMAGEIMMUNITY", nDamType);
}


int SetAlignmentGoodEvil (object oCreature, int nValue) {
    return NWNXFuncsTwo(oCreature, "NWNX!FUNCS!SETALIGNMENTVALUE", 0, nValue);
}

int SetAlignmentLawChaos (object oCreature, int nValue) {
    return NWNXFuncsTwo(oCreature, "NWNX!FUNCS!SETALIGNMENTVALUE", 1, nValue);
}


int ModifyCurrentHitPoints (object oCreature, int nHP) {
    return NWNXFuncsOne(oCreature, "NWNX!FUNCS!MODIFYCURRENTHITPOINTS", nHP);
}

int SetCurrentHitPoints (object oCreature, int nHP) {
    return NWNXFuncsOne(oCreature, "NWNX!FUNCS!SETCURRENTHITPOINTS", nHP);
}

int SetMaxHitPoints (object oCreature, int nHP) {
    return NWNXFuncsOne(oCreature, "NWNX!FUNCS!SETMAXHITPOINTS", nHP);
}


int RecalculateDexModifier (object oCreature) {
    return NWNXFuncsZero(oCreature, "NWNX!FUNCS!RECALCULATEDEXMODIFIER");
}


int GetKnowsSpell (int nSpellId, object oCreature, int nClass=CLASS_TYPE_INVALID) {
    return NWNXFuncsTwo(oCreature, "NWNX!FUNCS!GETKNOWSSPELL", nClass, nSpellId);
}

int GetKnownSpell (object oCreature, int nClass, int nSpellLevel, int nIndex) {
    return NWNXFuncsThree(oCreature, "NWNX!FUNCS!GETKNOWNSPELL", nClass, nSpellLevel, nIndex);
}

int SetKnownSpell (object oCreature, int nClass, int nSpellLevel, int nIndex, int nSpellId) {
    SetLocalString(oCreature, "NWNX!FUNCS!SETKNOWNSPELL",
        IntToString(nClass) + " " + IntToString(nSpellLevel) + " " +
        IntToString(nIndex) + " " + IntToString(nSpellId) + "          ");
    return StringToInt(GetLocalString(oCreature, "NWNX!FUNCS!SETKNOWNSPELL"));
}

int GetTotalKnownSpells (object oCreature, int nClass, int nSpellLevel) {
    return NWNXFuncsTwo(oCreature, "NWNX!FUNCS!GETTOTALKNOWNSPELLS", nClass, nSpellLevel);
}

int AddKnownSpell (object oCreature, int nClass, int nSpellLevel, int nSpellId) {
    return NWNXFuncsThree(oCreature, "NWNX!FUNCS!ADDKNOWNSPELL", nClass, nSpellLevel, nSpellId);
}

int RemoveKnownSpell (object oCreature, int nClass, int nSpellLevel, int nSpellId) {
    return NWNXFuncsThree(oCreature, "NWNX!FUNCS!REMOVEKNOWNSPELL", nClass, nSpellLevel, nSpellId);
}

int ReplaceKnownSpell (object oCreature, int nClass, int nOldSpell, int nNewSpell) {
    return NWNXFuncsThree(oCreature, "NWNX!FUNCS!REPLACEKNOWNSPELL", nClass, nOldSpell, nNewSpell);
}


struct MemorizedSpellSlot GetMemorizedSpell (object oCreature, int nClass, int nLevel, int nIndex) {
    SetLocalString(oCreature, "NWNX!FUNCS!GETMEMORIZEDSPELL",
        IntToString(nClass) + " " + IntToString(nLevel) + " " + IntToString(nIndex) + "          ");

    int nSpell = StringToInt(GetLocalString(oCreature, "NWNX!FUNCS!GETMEMORIZEDSPELL"));

    struct MemorizedSpellSlot mss;

    if (nSpell >= 0) {
        mss.id    = nSpell & 0xFFFF;
        mss.meta  = (nSpell >> 16) & 0x7F;
        mss.ready = (nSpell >> 24) & 1;
    } else
        mss.id = -1;

    return mss;
}

int SetMemorizedSpell (object oCreature, int nClass, int nLevel, int nIndex, struct MemorizedSpellSlot mss) {
    int nFlags = (mss.ready != 0) | ((mss.domain != 0) << 1);
    SetLocalString(oCreature, "NWNX!FUNCS!SETMEMORIZEDSPELL",
        IntToString(nClass) + " " + IntToString(nLevel) + " " + IntToString(nIndex) + " " +
        IntToString(mss.id) + " " + IntToString(mss.meta & 0x7F) + " " + IntToString(nFlags) + "          ");
    return StringToInt(GetLocalString(oCreature, "NWNX!FUNCS!GETMEMORIZEDSPELL"));
}

int ClearMemorizedSpell (object oCreature, int nClass, int nLevel, int nIndex) {
    struct MemorizedSpellSlot mss;

    mss.id = -1;
    return SetMemorizedSpell(oCreature, nClass, nLevel, nIndex, mss);
}


int GetMaxSpellSlots (object oCreature, int nClass, int nSpellLevel) {
    return NWNXFuncsTwo(oCreature, "NWNX!FUNCS!GETMAXSPELLSLOTS", nClass, nSpellLevel);
}

int GetBonusSpellSlots (object oCreature, int nClass, int nSpellLevel) {
    return NWNXFuncsTwo(oCreature, "NWNX!FUNCS!GETBONUSSPELLSLOTS", nClass, nSpellLevel);
}

int GetRemainingSpellSlots (object oCreature, int nClass, int nSpellLevel) {
    return NWNXFuncsTwo(oCreature, "NWNX!FUNCS!GETREMAININGSPELLSLOTS", nClass, nSpellLevel);
}

int SetRemainingSpellSlots (object oCreature, int nClass, int nSpellLevel, int nSlots) {
    return NWNXFuncsThree(oCreature, "NWNX!FUNCS!SETREMAININGSPELLSLOTS", nClass, nSpellLevel, nSlots);
}


string GetAllMemorizedSpells (object oCreature) {
    string sSpells = GetLocalString(GetModule(), "NWNX!ODBC!SPACER");

    SetLocalString(oCreature, "NWNX!FUNCS!GETALLMEMORIZEDSPELLS", sSpells + sSpells + sSpells + sSpells);
    sSpells = GetLocalString(oCreature, "NWNX!FUNCS!GETALLMEMORIZEDSPELLS");
    DeleteLocalString(oCreature, "NWNX!FUNCS!GETALLMEMORIZEDSPELLS");

    return sSpells;
}

int RestoreReadySpells (object oCreature, string sSpells) {
    SetLocalString(oCreature, "NWNX!FUNCS!RESTOREREADYSPELLS", sSpells + " ");
    return StringToInt(GetLocalString(oCreature, "NWNX!FUNCS!RESTOREREADYSPELLS"));
}


int GetClericDomain (object oCreature, int nIndex) {
    return NWNXFuncsOne(oCreature, "NWNX!FUNCS!GETCLERICDOMAIN", nIndex);
}

int SetClericDomain (object oCreature, int nIndex, int nDomain) {
    return NWNXFuncsTwo(oCreature, "NWNX!FUNCS!SETCLERICDOMAIN", nIndex, nDomain);
}

int GetWizardSpecialization (object oCreature) {
    return NWNXFuncsZero(oCreature, "NWNX!FUNCS!GETWIZARDSPECIALIZATION");
}

int SetWizardSpecialization (object oCreature, int nSchool) {
    return NWNXFuncsOne(oCreature, "NWNX!FUNCS!SETWIZARDSPECIALIZATION", nSchool);
}


struct SpecialAbilitySlot GetSpecialAbility (object oCreature, int nIndex) {
    SetLocalString(oCreature, "NWNX!FUNCS!GETSPECIALABILITY",
        IntToString(nIndex) + "          ");

    int nSpec = StringToInt(GetLocalString(oCreature, "NWNX!FUNCS!GETSPECIALABILITY"));

    struct SpecialAbilitySlot sas;

    if (nSpec >= 0) {
        sas.id    = nSpec & 0xFFFF;
        sas.level = (nSpec >> 16) & 0x7F;
        sas.ready = (nSpec >> 24) & 1;
    } else
        sas.id = -1;

    return sas;
}

int SetSpecialAbility (object oCreature, int nIndex, struct SpecialAbilitySlot sas) {
    SetLocalString(oCreature, "NWNX!FUNCS!SETSPECIALABILITY",
        IntToString(nIndex) + " " + IntToString(sas.id) + " " +
        IntToString(sas.level & 0x7F) + " " + IntToString(sas.ready != 0) + "          ");
    return StringToInt(GetLocalString(oCreature, "NWNX!FUNCS!SETSPECIALABILITY"));
}

int GetTotalSpecialAbilities (object oCreature) {
    return NWNXFuncsZero(oCreature, "NWNX!FUNCS!GETTOTALSPECIALABILITIES");
}

int AddSpecialAbility (object oCreature, struct SpecialAbilitySlot sas) {
    SetLocalString(oCreature, "NWNX!FUNCS!ADDSPECIALABILITY",
        IntToString(sas.id) + " " + IntToString(sas.level & 0x7F) + " " + IntToString(sas.ready != 0) + "          ");
    return StringToInt(GetLocalString(oCreature, "NWNX!FUNCS!ADDSPECIALABILITY"));
}

int RemoveSpecialAbility (object oCreature, int nIndex) {
    return NWNXFuncsOne(oCreature, "NWNX!FUNCS!REMOVESPECIALABILITY", nIndex);
}


string GetRawQuickBarSlot (object oPC, int nSlot) {
    SetLocalString(oPC, "NWNX!FUNCS!GETQUICKBARSLOT",
        IntToString(nSlot) + "                                                                                                                                ");
    return GetLocalString(oPC, "NWNX!FUNCS!GETQUICKBARSLOT");
}

void SetRawQuickBarSlot (object oPC, string sSlot) {
    SetLocalString(oPC, "NWNX!FUNCS!SETQUICKBARSLOT", sSlot);
}


string GetPortrait (object oCreature) {
    SetLocalString(oCreature, "NWNX!FUNCS!GETPORTRAIT", "                    ");
    return GetLocalString(oCreature, "NWNX!FUNCS!GETPORTRAIT");
}

int SetPortrait (object oCreature, string sPortrait) {
    SetLocalString(oCreature, "NWNX!FUNCS!SETPORTRAIT", sPortrait);
    return StringToInt(GetLocalString(oCreature, "NWNX!FUNCS!SETPORTRAIT"));
}


int GetSoundset (object oCreature) {
    return NWNXFuncsZero(oCreature, "NWNX!FUNCS!GETSOUNDSET");
}

int SetSoundset (object oCreature, int nSoundset) {
    return NWNXFuncsOne(oCreature, "NWNX!FUNCS!SETSOUNDSET", nSoundset);
}


int SetTrapCreator (object oTrap, object oCreator) {
    SetLocalString(oTrap, "NWNX!FUNCS!SETTRAPCREATOR", ObjectToString(oCreator));
    return StringToInt(GetLocalString(oTrap, "NWNX!FUNCS!SETTRAPCREATOR"));
}


string GetConversation (object oCreature) {
    SetLocalString(oCreature, "NWNX!FUNCS!GETCONVERSATION", "                ");
    return GetLocalString(oCreature, "NWNX!FUNCS!GETCONVERSATION");
}

string SetConversation (object oCreature, string sConv) {
    SetLocalString(oCreature, "NWNX!FUNCS!SETCONVERSATION", sConv);
    return GetLocalString(oCreature, "NWNX!FUNCS!SETCONVERSATION");
}


int GetIsVariableValid (struct LocalVariable lv) {
    return (lv.type >= 1 && lv.type <= 5);
}

int GetLocalVariableCount (object oObject) {
    DeleteLocalString(oObject, "NWNX!FUNCS!GETLOCALVARIABLECOUNT");
    DeleteLocalString(oObject, "NWNX!FUNCS!GETLOCALVARIABLEBYPOSITION");

    int nVariables = NWNXFuncsZero(oObject, "NWNX!FUNCS!GETLOCALVARIABLECOUNT");
    DeleteLocalString(oObject, "NWNX!FUNCS!GETLOCALVARIABLECOUNT");

    return nVariables;
}


struct LocalVariable GetLocalVariableByPosition (object oObject, int nPos) {
    struct LocalVariable lv;

    DeleteLocalString(oObject, "NWNX!FUNCS!GETLOCALVARIABLEBYPOSITION");
    SetLocalString(oObject, "NWNX!FUNCS!GETLOCALVARIABLEBYPOSITION", 
        IntToString(nPos) + "                                                                                                                                ");

    lv.name = GetLocalString(oObject, "NWNX!FUNCS!GETLOCALVARIABLEBYPOSITION");
    DeleteLocalString(oObject, "NWNX!FUNCS!GETLOCALVARIABLEBYPOSITION");

    lv.type = StringToInt(lv.name);
    lv.name = GetSubString(lv.name, 2, 1000);
    lv.pos  = nPos;
    lv.obj  = oObject;

    return lv;
}

struct LocalVariable GetFirstLocalVariable (object oObject) {
    return GetLocalVariableByPosition(oObject, 0);
}

struct LocalVariable GetNextLocalVariable (struct LocalVariable lv) {
    return GetLocalVariableByPosition(lv.obj, lv.pos + 1);
}

string DumpLocalVariables (object oObject) {
    int i, nVariables = GetLocalVariableCount(oObject);
    object oVar;
    vector vPos;
    location lLoc;
    string sDump = "";
    struct LocalVariable lv;

    for (i = 0; i < nVariables; i++) {
        lv = GetLocalVariableByPosition(oObject, i);

        switch (lv.type) {
            case VARIABLE_TYPE_INT:
                sDump += lv.name + " (int): " + IntToString(GetLocalInt(oObject, lv.name)) + "\n";
                break;

            case VARIABLE_TYPE_FLOAT:
                sDump += lv.name + " (float): " + FloatToString(GetLocalFloat(oObject, lv.name), 1, 2) + "\n";
                break;

            case VARIABLE_TYPE_STRING:
                sDump += lv.name + " (string): '" + GetLocalString(oObject, lv.name) + "'\n";
                break;

            case VARIABLE_TYPE_OBJECT:
                oVar = GetLocalObject(oObject, lv.name);
                if (GetIsPC(oVar))
                    sDump += lv.name + " (object): " + GetName(oVar) + " (player: " +
                             GetPCPlayerName(oVar) + ") [" + ObjectToString(oVar) + "]\n";
                else
                    sDump += lv.name + " (object): " + GetName(oVar) + " (tag: " + GetTag(oVar) +
                             " resref: " + GetResRef(oVar) + ") [" + ObjectToString(oVar) + "]\n";
                break;

            case VARIABLE_TYPE_LOCATION:
                lLoc = GetLocalLocation(oObject, lv.name);
                oVar = GetAreaFromLocation(lLoc);
                vPos = GetPositionFromLocation(lLoc);
                sDump += lv.name + " (location): " + GetName(oVar) + " (" + GetResRef(oVar) + ") [" +
                         FloatToString(vPos.x, 1, 2) + ", " + FloatToString(vPos.y, 1, 2) + ", " +
                         FloatToString(vPos.z, 1, 2) + " | " +
                         FloatToString(GetFacingFromLocation(lLoc), 1, 2) + "]\n";
                break;

            default:
                sDump += lv.name + " (UNKNOWN)\n";
                break;
        }
    }

    return sDump;
}


object GetFirstArea () {
    return GetLocalObject(GetModule(), "NWNX!FUNCS!GETFIRSTAREA");
}

object GetNextArea () {
    return GetLocalObject(GetModule(), "NWNX!FUNCS!GETNEXTAREA");
}

int SetBaseItemType (object oItem, int nBaseItem)
{
    SetLocalString(oItem, "NWNX!FUNCS!SETBASEITEMTYPE", IntToString(nBaseItem));
    return StringToInt(GetLocalString(oItem, "NWNX!FUNCS!SETBASEITEMTYPE"));
}


int SetGoldPieceValue (object oItem, int nValue) {
    return NWNXFuncsOne(oItem, "NWNX!FUNCS!SETGOLDPIECEVALUE", nValue);
}

int SetItemWeight (object oItem, int nTenthLbs) {
    return NWNXFuncsOne(oItem, "NWNX!FUNCS!SETITEMWEIGHT", nTenthLbs);
}


string GetEntireItemAppearance (object oItem) {
    SetLocalString(oItem, "NWNX!FUNCS!GETENTIREITEMAPPEARANCE", "                                                            ");
    string sApp = GetLocalString(oItem, "NWNX!FUNCS!GETENTIREITEMAPPEARANCE");
    DeleteLocalString(oItem, "NWNX!FUNCS!GETENTIREITEMAPPEARANCE");

    return sApp;
}

void RestoreItemAppearance (object oItem, string sApp) {
    SetLocalString(oItem, "NWNX!FUNCS!RESTOREITEMAPPEARANCE", sApp);
    DeleteLocalString(oItem, "NWNX!FUNCS!RESTOREITEMAPPEARANCE");
}

int SetItemAppearance (object oItem, int nIndex, int nValue) {
    int nRet = NWNXFuncsTwo(oItem, "NWNX!FUNCS!SETITEMAPPEARANCE", nIndex, nValue);
    DeleteLocalString(oItem, "NWNX!FUNCS!SETITEMAPPEARANCE");
    return nRet;
}

int SetItemColor (object oItem, int nIndex, int nColor) {
    int nRet = NWNXFuncsTwo(oItem, "NWNX!FUNCS!SETITEMCOLOR", nIndex, nColor);
    DeleteLocalString(oItem, "NWNX!FUNCS!SETITEMCOLOR");
    return nRet;
}

int GetIsStatic (object oPlace) {
    int nRet = NWNXFuncsZero(oPlace, "NWNX!FUNCS!GETISSTATIC");
    DeleteLocalString(oPlace, "NWNX!FUNCS!GETISSTATIC");
    return nRet;
}

int SetPlaceableAppearance (object oPlace, int nApp) {
    int nRet = NWNXFuncsOne(oPlace, "NWNX!FUNCS!SETPLACEABLEAPPEARANCE", nApp);
    DeleteLocalString(oPlace, "NWNX!FUNCS!SETPLACEABLEAPPEARANCE");
    return nRet;
}


float GetGroundHeight (object oArea, vector vPos) {
    SetLocalString(oArea, "NWNX!FUNCS!GETGROUNDHEIGHT",
        FloatToString(vPos.x) + "¬" + FloatToString(vPos.y) + "¬" +
        FloatToString(vPos.z) + "                    ");
    return StringToFloat(GetLocalString(oArea, "NWNX!FUNCS!GETGROUNDHEIGHT"));
}

float GetGroundHeightFromLocation (location lLoc) {
    return GetGroundHeight(GetAreaFromLocation(lLoc), GetPositionFromLocation(lLoc));
}

int GetIsWalkable (object oArea, vector vPos) {
    SetLocalString(oArea, "NWNX!FUNCS!GETISWALKABLE",
        FloatToString(vPos.x) + "¬" + FloatToString(vPos.y) + "¬" +
        FloatToString(vPos.z) + "                    ");
    return StringToInt(GetLocalString(oArea, "NWNX!FUNCS!GETISWALKABLE"));
}

int GetIsWalkableLocation (location lLoc) {
    return GetIsWalkable(GetAreaFromLocation(lLoc), GetPositionFromLocation(lLoc));
}


void ActionUseItem (object oItem, object oTarget, location lTarget, int nProp) {
    object oArea = GetAreaFromLocation(lTarget);
    vector vVec = GetPositionFromLocation(lTarget);

    if (!GetIsObjectValid(oArea))
        return;

    SetLocalString(OBJECT_SELF, "NWNX!FUNCS!ACTIONUSEITEM",
        ObjectToString(oItem) + "¬" + ObjectToString(oTarget) + "¬" +
        ObjectToString(oArea) + "¬" + FloatToString(vVec.x)   + "¬" +
        FloatToString(vVec.y) + "¬" + FloatToString(vVec.z)   + "¬" +
        IntToString(nProp));
}

void ActionUseItemAtLocation (object oItem, location lTarget, int nProp=0) {
    ActionUseItem(oItem, OBJECT_INVALID, lTarget, nProp);
}

void ActionUseItemOnObject (object oItem, object oTarget, int nProp=0) {
    ActionUseItem(oItem, OBJECT_INVALID, GetLocation(oTarget), nProp);
}


int GetPCPort (object oPC) {
    if (!GetIsPC(oPC) || GetIsDMPossessed(oPC))
        return 0;
    return NWNXFuncsZero(oPC, "NWNX!FUNCS!GETPCPORT");
}

void BootPCWithMessage (object oPC, int nStrRef) {
    SetLocalString(oPC, "NWNX!FUNCS!BOOTPCWITHMESSAGE", IntToString(nStrRef));
}


string GetCreatureEventHandler (object oCreature, int nEvent) {
    SetLocalString(oCreature, "NWNX!FUNCS!GETCREATUREEVENTHANDLER", IntToString(nEvent) + "                ");
    return GetLocalString(oCreature, "NWNX!FUNCS!GETCREATUREEVENTHANDLER");
}

string SetCreatureEventHandler (object oCreature, int nEvent, string sScript) {
    SetLocalString(oCreature, "NWNX!FUNCS!SETCREATUREEVENTHANDLER", IntToString(nEvent) + " " + sScript);
    return GetLocalString(oCreature, "NWNX!FUNCS!SETCREATUREEVENTHANDLER");
}

string GetEventHandler (object oObject, int nEvent) {
    SetLocalString(oObject, "NWNX!FUNCS!GETEVENTHANDLER", IntToString(nEvent) + "                ");
    return GetLocalString(oObject, "NWNX!FUNCS!GETEVENTHANDLER");
}

string SetEventHandler (object oObject, int nEvent, string sScript) {
    SetLocalString(oObject, "NWNX!FUNCS!SETEVENTHANDLER", IntToString(nEvent) + " " + sScript);
    return GetLocalString(oObject, "NWNX!FUNCS!SETEVENTHANDLER");
}

int GetFactionId (object oObject) {
    return NWNXFuncsZero(oObject, "NWNX!FUNCS!GETFACTIONID");
}

int SetFactionId (object oObject, int nFaction) {
    return NWNXFuncsOne(oObject, "NWNX!FUNCS!SETFACTIONID", nFaction);
}

void SetLastHostileActor (object oObject, object oActor) {
    SetLocalString(oObject, "NWNX!FUNCS!SETLASTHOSTILEACTOR", ObjectToString(oActor));
}


object GetItemByPosition (object oCreature, int nPos) {
    SetLocalString(oCreature, "NWNX!FUNCS!GETITEMBYPOSITIONREQUEST", IntToString(nPos));
    return GetLocalObject(oCreature, "NWNX!FUNCS!GETITEMBYPOSITION");
}

int GetItemCount (object oCreature) {
    return NWNXFuncsZero(oCreature, "NWNX!FUNCS!GETITEMCOUNT");
}


int SetMovementRate (object oCreature, int nRate) {
    if (GetIsDM(oCreature))
        nRate = MOVEMENT_RATE_DM_FAST;
    return NWNXFuncsOne(oCreature, "NWNX!FUNCS!SETMOVEMENTRATE", nRate);
}


int SetRacialType (object oCreature, int nRacialType) {
    return NWNXFuncsOne(oCreature, "NWNX!FUNCS!SETRACIALTYPE", nRacialType);
}


string SetTag (object oObject, string sTag) {
    SetLocalString(oObject, "NWNX!FUNCS!SETTAG", sTag);
    return GetLocalString(oObject, "NWNX!FUNCS!SETTAG");
}


string GetPCFileName (object oPC) {
    if (!GetIsPC(oPC))
        return "";

    SetLocalString(oPC, "NWNX!FUNCS!GETPCFILENAME", "                    ");
    return GetLocalString(oPC, "NWNX!FUNCS!GETPCFILENAME");
}


void JumpToLimbo (object oCreature) {
    SetLocalString(oCreature, "NWNX!FUNCS!JUMPTOLIMBO", "          ");
}


int BroadcastProjectileToObject (object oSource, object oTarget, int nSpellId, int nDelay=-1) {
    if (!GetIsObjectValid(oTarget))
        return 0;

    location lTarget = GetLocation(oTarget);
    vector vTarget   = GetPositionFromLocation(lTarget);

    if (nDelay < 0) {
        float fDelay = GetDistanceBetween(oSource, oTarget) / 20;
        nDelay = FloatToInt(fDelay * 1000);
    }

    SetLocalString(oSource, "NWNX!FUNCS!BROADCASTPROJECTILE",
        ObjectToString(oTarget)        + " " +
        FloatToString(vTarget.x, 1, 4) + " " +
        FloatToString(vTarget.y, 1, 4) + " " +
        FloatToString(vTarget.z, 1, 4) + " " +
        IntToString(nSpellId) + " " + IntToString(nDelay));
    return StringToInt(GetLocalString(oSource, "NWNX!FUNCS!BROADCASTPROJECTILE"));
}

int BroadcastProjectileToLocation (object oSource, location lTarget, int nSpellId, int nDelay=-1) {
    vector vTarget = GetPositionFromLocation(lTarget);

    if (nDelay < 0) {
        float fDelay = GetDistanceBetweenLocations(GetLocation(oSource), lTarget) / 20;
        nDelay = FloatToInt(fDelay * 1000);
    }

    SetLocalString(oSource, "NWNX!FUNCS!BROADCASTPROJECTILE", "0 " +
        FloatToString(vTarget.x, 1, 4) + " " +
        FloatToString(vTarget.y, 1, 4) + " " +
        FloatToString(vTarget.z, 1, 4) + " " +
        IntToString(nSpellId) + " " + IntToString(nDelay));
    return StringToInt(GetLocalString(oSource, "NWNX!FUNCS!BROADCASTPROJECTILE"));
}


int SetIsCreatureDisarmable(object oCreature, int bDisarmable)
{
    int nRet = NWNXFuncsOne(oCreature, "NWNX!FUNCS!SETISCREATUREDISARMABLE", bDisarmable != FALSE);
    DeleteLocalString(oCreature, "NWNX!FUNCS!SETISCREATUREDISARMABLE");
    return nRet;	
}

int SetCorpseDecayTime(object oCreature, int nTime)
{
    int nRet = NWNXFuncsOne(oCreature, "NWNX!FUNCS!SETCORPSEDECAYTIME", nTime);
    DeleteLocalString(oCreature, "NWNX!FUNCS!SETCORPSEDECAYTIME");
    return nRet;
}

int GetCorpseDecayTime(object oCreature)
{
    int nRet = NWNXFuncsZero(oCreature, "NWNX!FUNCS!GETCORPSEDECAYTIME");
    DeleteLocalString(oCreature, "NWNX!FUNCS!GETCORPSEDECAYTIME");
    return nRet;	
}

object IntToObject (int nObjectId) {
    SetLocalString(GetModule(), "NWNX!FUNCS!INTTOOBJECTREQUEST", IntToString(nObjectId));
    return GetLocalObject(GetModule(), "NWNX!FUNCS!INTTOOBJECT");
}

object StringToObject (string sObjectId) {
    SetLocalString(GetModule(), "NWNX!FUNCS!STRINGTOOBJECTREQUEST", sObjectId);
    return GetLocalObject(GetModule(), "NWNX!FUNCS!INTTOOBJECT");
}


void DumpObject (object oObject) {
    SetLocalString(oObject, "NWNX!FUNCS!DUMPOBJECT", "          ");
}
