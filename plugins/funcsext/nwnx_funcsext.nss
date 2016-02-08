/****************************************************************************

    nwnx_funcsext - extended functions for nwnx

    NB - experimental

/****************************************************************************/

//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//                                 CONSTANTS                                //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

//
// constants for SetScript()
//
const int
    CREATURE_SCRIPT_HEARTBEAT       = 0,
    CREATURE_SCRIPT_PERCEPTION      = 1,
    CREATURE_SCRIPT_SPELLCAST_AT    = 2,
    CREATURE_SCRIPT_ATTACKED        = 3,
    CREATURE_SCRIPT_DAMAGED         = 4,
    CREATURE_SCRIPT_DISTURBED       = 5,
    CREATURE_SCRIPT_COMBAT_ROUND    = 6,
    CREATURE_SCRIPT_CONVERSATION    = 7,
    CREATURE_SCRIPT_SPAWN           = 8,
    CREATURE_SCRIPT_RESTED          = 9,
    CREATURE_SCRIPT_DEATH           = 10,
    CREATURE_SCRIPT_USER_DEFINED    = 11,
    CREATURE_SCRIPT_BLOCKED         = 12,

    PLACEABLE_SCRIPT_CLOSE          = 0,
    PLACEABLE_SCRIPT_DAMAGE         = 1,
    PLACEABLE_SCRIPT_DEATH          = 2,
    PLACEABLE_SCRIPT_HEARTBEAT      = 4,
    PLACEABLE_SCRIPT_DISTURBED      = 5,
    PLACEABLE_SCRIPT_LOCK           = 6,
    PLACEABLE_SCRIPT_ATTACKED       = 7,
    PLACEABLE_SCRIPT_OPEN           = 8,
    PLACEABLE_SCRIPT_SPELLCAST_AT   = 9,
    PLACEABLE_SCRIPT_UNLOCK         = 11,
    PLACEABLE_SCRIPT_USED           = 12,
    PLACEABLE_SCRIPT_USER_DEFINED   = 13,
    PLACEABLE_SCRIPT_CLICK          = 15,

    MODULE_SCRIPT_HEARTBEAT         = 0,
    MODULE_SCRIPT_USER_DEFINED      = 1,
    MODULE_SCRIPT_LOAD              = 2,
    MODULE_SCRIPT_CLIENT_ENTER      = 4,
    MODULE_SCRIPT_CLIENT_LEAVE      = 5,
    MODULE_SCRIPT_ACTIVATE_ITEM     = 6,
    MODULE_SCRIPT_ACQURATE_ITEM     = 7,
    MODULE_SCRIPT_UNACQURATE_ITEM   = 8,
    MODULE_SCRIPT_PLAYER_DEATH      = 9,
    MODULE_SCRIPT_PLAYER_DYING      = 10,
    MODULE_SCRIPT_PLAYER_RESPAWN    = 11,
    MODULE_SCRIPT_PLAYER_REST       = 12,
    MODULE_SCRIPT_PLAYER_LEVELUP    = 13,
    MODULE_SCRIPT_CURSCENE_ABORT    = 14,
    MODULE_SCRIPT_EQUIP_ITEM        = 15,
    MODULE_SCRIPT_UNEQUIP_ITEM      = 16,
    MODULE_SCRIPT_PLAYER_CHAT       = 17,

    AREA_SCRIPT_HEARTBEAT           = 0,
    AREA_SCRIPT_USER_DEFINED        = 1,
    AREA_SCRIPT_ENTER               = 2,
    AREA_SCRIPT_EXIT                = 3,

    DOOR_SCRIPT_OPEN                = 0,
    DOOR_SCRIPT_CLOSE               = 1,
    DOOR_SCRIPT_DAMAGED             = 2,
    DOOR_SCRIPT_DEATH               = 3,
    DOOR_SCRIPT_HEARTBEAT           = 5,
    DOOR_SCRIPT_LOCKED              = 6,
    DOOR_SCRIPT_ATTACKED            = 7,
    DOOR_SCRIPT_SPELCAST_AT         = 8,
    DOOR_SCRIPT_UNLOCKED            = 10,
    DOOR_SCRIPT_USER_DEFINED        = 11,
    DOOR_SCRIPT_TRANSITION_CLICK    = 12,
    DOOR_SCRIPT_FAIL_TO_OPEN        = 14,

    STORE_SCIRPT_OPEN               = 0,
    STORE_SCRIPT_CLOSE              = 1,

    TRIGGER_SCRIPT_HEARTBEAT        = 0,
    TRIGGER_SCRIPT_ENTER            = 1,
    TRIGGER_SCRIPT_EXIT             = 2,
    TRIGGER_SCRIPT_USER_DEFINED     = 3,
    TRIGGER_SCRIPT_TRANSITION_CLICK = 6,

    ENCOUNTER_SCRIPT_ENTER          = 0,
    ENCOUNTER_SCRIPT_EXIT           = 1,
    ENCOUNTER_SCRIPT_HEARTBEAT      = 2,
    ENCOUNTER_SCRIPT_EXHAUSTED      = 3,
    ENCOUNTER_SCRIPT_USER_DEFINED   = 4;

const int
    AREA_TRANSITION_LINK_NONE       = 0,
    AREA_TRANSITION_LINK_DOOR       = 1,
    AREA_TRANSITION_LINK_WAYPOINT   = 2;

const int
    SURFACE_MATERIAL_DIRT           = 1,
    SURFACE_MATERIAL_OBSCURING      = 2,
    SURFACE_MATERIAL_GRASS          = 3,
    SURFACE_MATERIAL_STONE          = 4,
    SURFACE_MATERIAL_WOOD           = 5,
    SURFACE_MATERIAL_WATER          = 6,
    SURFACE_MATERIAL_NOWALK         = 7,
    SURFACE_MATERIAL_TRANSPARENT    = 8,
    SURFACE_MATERIAL_CARPET         = 9,
    SURFACE_MATERIAL_METAL          = 10,
    SURFACE_MATERIAL_PUDDLES        = 11,
    SURFACE_MATERIAL_SWAMP          = 12,
    SURFACE_MATERIAL_MUD            = 13,
    SURFACE_MATERIAL_LEAVES         = 14,
    SURFACE_MATERIAL_LAVA           = 15,
    SURFACE_MATERIAL_BOTTOMLESSPIT  = 16,
    SURFACE_MATERIAL_DEEPWATER      = 17,
    SURFACE_MATERIAL_DOOR           = 18,
    SURFACE_MATERIAL_SNOW           = 19,
    SURFACE_MATERIAL_SAND           = 20,
    SURFACE_MATERIAL_BAREBONES      = 21,
    SURFACE_MATERIAL_STONEBRIDGE    = 22,
    SURFACE_MATERIAL_TRIGGER        = 30;

//
// constants for GetAnimation()
// these are the values actually returned by nwnx for the given animations

const int NWNX_ANIMATION_LOOPING_PAUSE2                   = 52;
const int NWNX_ANIMATION_LOOPING_LISTEN                   = 30;
const int NWNX_ANIMATION_LOOPING_MEDITATE                 = 32;
const int NWNX_ANIMATION_LOOPING_WORSHIP                  = 33;
const int NWNX_ANIMATION_LOOPING_LOOK_FAR                 = 48;
const int NWNX_ANIMATION_LOOPING_SIT_CHAIR                = 36;
const int NWNX_ANIMATION_LOOPING_SIT_CROSS                = 47;
const int NWNX_ANIMATION_LOOPING_TALK_NORMAL              = 38;
const int NWNX_ANIMATION_LOOPING_TALK_PLEADING            = 39;
const int NWNX_ANIMATION_LOOPING_TALK_FORCEFUL            = 40;
const int NWNX_ANIMATION_LOOPING_TALK_LAUGHING            = 41;
const int NWNX_ANIMATION_LOOPING_GET_LOW                  = 59;
const int NWNX_ANIMATION_LOOPING_GET_MID                  = 60;
const int NWNX_ANIMATION_LOOPING_PAUSE_TIRED              = 57;
const int NWNX_ANIMATION_LOOPING_PAUSE_DRUNK              = 58;
const int NWNX_ANIMATION_LOOPING_DEAD_FRONT               = 6;
const int NWNX_ANIMATION_LOOPING_DEAD_BACK                = 8;
const int NWNX_ANIMATION_LOOPING_CONJURE1                 = 15;
const int NWNX_ANIMATION_LOOPING_CONJURE2                 = 16;
const int NWNX_ANIMATION_LOOPING_SPASM                    = 93;
const int NWNX_ANIMATION_LOOPING_CUSTOM1                  = 97;
const int NWNX_ANIMATION_LOOPING_CUSTOM2                  = 98;
const int NWNX_ANIMATION_LOOPING_CUSTOM3                  = 101;
const int NWNX_ANIMATION_LOOPING_CUSTOM4                  = 102;
const int NWNX_ANIMATION_LOOPING_CUSTOM5                  = 103;
const int NWNX_ANIMATION_LOOPING_CUSTOM6                  = 104;
const int NWNX_ANIMATION_LOOPING_CUSTOM7                  = 105;
const int NWNX_ANIMATION_LOOPING_CUSTOM8                  = 106;
const int NWNX_ANIMATION_LOOPING_CUSTOM9                  = 107;
const int NWNX_ANIMATION_LOOPING_CUSTOM10                 = 108;
const int NWNX_ANIMATION_LOOPING_CUSTOM11                 = 109;
const int NWNX_ANIMATION_LOOPING_CUSTOM12                 = 110;
const int NWNX_ANIMATION_LOOPING_CUSTOM13                 = 111;
const int NWNX_ANIMATION_LOOPING_CUSTOM14                 = 112;
const int NWNX_ANIMATION_LOOPING_CUSTOM15                 = 113;
const int NWNX_ANIMATION_LOOPING_CUSTOM16                 = 114;
const int NWNX_ANIMATION_LOOPING_CUSTOM17                 = 115;
const int NWNX_ANIMATION_LOOPING_CUSTOM18                 = 116;
const int NWNX_ANIMATION_LOOPING_CUSTOM19                 = 117;
const int NWNX_ANIMATION_LOOPING_CUSTOM20                 = 118;
const int NWNX_ANIMATION_MOUNT1                           = 119;
const int NWNX_ANIMATION_DISMOUNT1                        = 120;


//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//                                PROTOTYPES                                //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

// Sets target's event handler script
//   object oTarget - the object whose event will be handled.
//   int nScript - the event to handle. see the NWNX_SCRIPT_* constants.
//   string sScript - name of script to call.
void SetScript(object oTarget, int nScript, string sScript="");

// Gets target's event handler script as set by SetScript()
string GetScript(object oTarget, int nScript);

// Create a square-shaped 'pseudo-transition' centred at the provided location
//   location lLocation - where to place the transition
//   int nLinkType - type of transition - AREA_TRANSITION_LINK_DOOR,
//     AREA_TRANSITION_LINK_WAYPOINT or AREA_TRANSITION_LINK_NONE (default)
//   string sTargetTag - tag of the object the transition should point to
//     sTargTag is required if nLinkType <> AREA_TRANSITION_LINK_NONE
//   float fSize - the radius of the transition. must be at least 1.0
//   string sTag - the tag of the newly-created transition
//   CAVEAT - the transition created by this function is not a standard transition
//            and will always return OBJECT_INVALID for GetTransitionTarget() !
object CreateAreaTransitionAtLocation(location lLocation, int nLinkType=AREA_TRANSITION_LINK_NONE, string sTargetTag="", float fSize=1.0f,  string sTag="");

// Create a square-shaped trigger centred at the provided location
//   location lLocation - where to place the transition
//   float fSize - the width of the trigger
//   string sTag - the newly-created trigger's tag
object CreateGenericTriggerAtLocation(location lLocation, float fSize=2.0f, string sTag="");

// Get surface material type from location
// returns - integer value corresponding to one of the SURFACE_MATERIAL_* constants
int GetSurface(location lLocation);

// Get the animation currently active on oTarget. see the ANIMATION_* constants.
int GetAnimation(object oTarget);

// Display timing bar for creature and run sScript after delay
void StartTimingBar(object oCreature, int nSeconds, string sScript);

// Hide timing bar and run sScript if specified
void StopTimingBar(object oCreature, string sScript="");

// Remove gold from creature without feedback message
// Return: -1 on success, 0 on failure
int RemoveGold(object oCreature, int nGold);

// Remove item from creature inventory without feedback message
// Function will fail if oItem has no possessor
// Return: -1 on success, 0 on failure
int RemoveItem(object oItem);

// Apply nVFX at vPosition for oPC
void AreaVisualEffectForPC(object oPC, int nVFX, vector vPosition);

// Change possession of oPC to oCreature
void PossessCreature(object oPC, object oCreature);

// unpossess creature formerly possessed with PossessCreature()
void UnPossessCreature(object oPC, object oCreature);

// return a boolean int indicating whether or not oCreature is flat-footed
int GetFlatFooted(object oCreature);


//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//                              IMPLEMENTATION                              //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

void SetScript(object oTarget, int nScript, string sScript="") {
    SetLocalString(oTarget, "NWNX!FUNCSEXT!SETSCRIPT", IntToString(nScript)+":"+sScript+"          ");
    DeleteLocalString(oTarget, "NWNX!FUNCSEXT!SETSCRIPT");
}

string GetScript(object oTarget, int nScript) {
    SetLocalString(oTarget, "NWNX!FUNCSEXT!GETSCRIPT", IntToString(nScript)+"                ");
    string sRet = GetLocalString(oTarget, "NWNX!FUNCSEXT!GETSCRIPT");
    DeleteLocalString(oTarget, "NWNX!FUNCSEXT!GETSCRIPT");
    return sRet;
}

object CreateGenericTriggerAtLocation(location lLocation, float fSize=2.0f, string sTag="") {
    object oTrigger = CreateTrapAtLocation(1, lLocation, fSize, sTag);
    if(GetIsObjectValid(oTrigger)) {
        SetLocalString(oTrigger, "NWNX!FUNCSEXT!SETISGENERICTRIGGER", "          ");
        DeleteLocalString(oTrigger, "NWNX!FUNCSEXT!SETISGENERICTRIGGER");
    }
    return oTrigger;
}

object CreateGenericTriggerOnLocation(location lLocation, float fSize=2.0f, string sTag="") {
    return CreateGenericTriggerAtLocation(lLocation, fSize, sTag);
}

object CreateAreaTransitionAtLocation(location lLocation, int nLinkType=AREA_TRANSITION_LINK_NONE, string sTargetTag="", float fSize=2.0f,  string sTag="") {
    object oTarget;

    // first make sure the target exists and is of the correct type
    if (nLinkType != AREA_TRANSITION_LINK_NONE) {
        oTarget = GetObjectByTag(sTargetTag);
        if (oTarget == OBJECT_INVALID)
            return OBJECT_INVALID;
        if (nLinkType == AREA_TRANSITION_LINK_DOOR && GetObjectType(oTarget) != OBJECT_TYPE_DOOR)
            return OBJECT_INVALID;
        if (nLinkType == AREA_TRANSITION_LINK_WAYPOINT && GetObjectType(oTarget) != OBJECT_TYPE_WAYPOINT)
            return OBJECT_INVALID;
    }

    // create the trigger
    object oTrigger = CreateTrapAtLocation(1, lLocation, fSize, sTag);
    if (GetIsObjectValid(oTrigger)) {
        SetLocalString(oTrigger, "NWNX!FUNCSEXT!SETISAREATRANSITION", "          ");
        DeleteLocalString(oTrigger, "NWNX!FUNCSEXT!SETISAREATRANSITION");
        if (nLinkType != AREA_TRANSITION_LINK_NONE) {
            SetLocalObject(oTrigger, "FUNCSEXT_TRANSITION_TARGET", oTarget);
            SetScript(oTrigger, TRIGGER_SCRIPT_TRANSITION_CLICK, "funcsext_trgclk");
        }
    }
    return oTrigger;
}

object CreateAreaTransitionOnLocation(location lLocation, int nLinkType=AREA_TRANSITION_LINK_NONE, string sTargetTag="", float fSize=2.0f,  string sTag="") {
    return CreateAreaTransitionAtLocation(lLocation, nLinkType, sTargetTag, fSize, sTag);
}

int GetSurface(location lLocation) {
    object oArea = GetAreaFromLocation(lLocation);
    vector vPos = GetPositionFromLocation(lLocation);

    SetLocalString(oArea, "NWNX!FUNCSEXT!GETSURFACE", FloatToString(vPos.x)+"¬"+FloatToString(vPos.y)+"¬"+FloatToString(vPos.z));
    string sRet = GetLocalString(oArea, "NWNX!FUNCSEXT!GETSURFACE");
    DeleteLocalString(oArea, "NWNX!FUNCSEXT!GETSURFACE");
    return StringToInt(sRet);
}

int GetAnimation(object oTarget) {
    SetLocalString(oTarget, "NWNX!FUNCSEXT!GETANIMATION", "                ");
    string sRet = GetLocalString(oTarget, "NWNX!FUNCSEXT!GETANIMATION");
    DeleteLocalString(oTarget, "NWNX!FUNCSEXT!GETANIMATION");

    // map nwnx-returned animations to std nwn animations
    switch(StringToInt(sRet)) {
      case NWNX_ANIMATION_LOOPING_PAUSE2:              return ANIMATION_LOOPING_PAUSE2;
      case NWNX_ANIMATION_LOOPING_LISTEN:              return ANIMATION_LOOPING_LISTEN;
      case NWNX_ANIMATION_LOOPING_MEDITATE:            return ANIMATION_LOOPING_MEDITATE;
      case NWNX_ANIMATION_LOOPING_WORSHIP:             return ANIMATION_LOOPING_WORSHIP;
      case NWNX_ANIMATION_LOOPING_LOOK_FAR:            return ANIMATION_LOOPING_LOOK_FAR;
      case NWNX_ANIMATION_LOOPING_SIT_CHAIR:           return ANIMATION_LOOPING_SIT_CHAIR;
      case NWNX_ANIMATION_LOOPING_SIT_CROSS:           return ANIMATION_LOOPING_SIT_CROSS;
      case NWNX_ANIMATION_LOOPING_TALK_NORMAL:         return ANIMATION_LOOPING_TALK_NORMAL;
      case NWNX_ANIMATION_LOOPING_TALK_PLEADING:       return ANIMATION_LOOPING_TALK_PLEADING;
      case NWNX_ANIMATION_LOOPING_TALK_FORCEFUL:       return ANIMATION_LOOPING_TALK_FORCEFUL;
      case NWNX_ANIMATION_LOOPING_TALK_LAUGHING:       return ANIMATION_LOOPING_TALK_LAUGHING;
      case NWNX_ANIMATION_LOOPING_GET_LOW:             return ANIMATION_LOOPING_GET_LOW;
      case NWNX_ANIMATION_LOOPING_GET_MID:             return ANIMATION_LOOPING_GET_MID;
      case NWNX_ANIMATION_LOOPING_PAUSE_TIRED:         return ANIMATION_LOOPING_PAUSE_TIRED;
      case NWNX_ANIMATION_LOOPING_PAUSE_DRUNK:         return ANIMATION_LOOPING_PAUSE_DRUNK;
      case NWNX_ANIMATION_LOOPING_DEAD_FRONT:          return ANIMATION_LOOPING_DEAD_FRONT;
      case NWNX_ANIMATION_LOOPING_DEAD_BACK:           return ANIMATION_LOOPING_DEAD_BACK;
      case NWNX_ANIMATION_LOOPING_CONJURE1:            return ANIMATION_LOOPING_CONJURE1;
      case NWNX_ANIMATION_LOOPING_CONJURE2:            return ANIMATION_LOOPING_CONJURE2;
      case NWNX_ANIMATION_LOOPING_SPASM:               return ANIMATION_LOOPING_SPASM;
      case NWNX_ANIMATION_LOOPING_CUSTOM1:             return ANIMATION_LOOPING_CUSTOM1;
      case NWNX_ANIMATION_LOOPING_CUSTOM2:             return ANIMATION_LOOPING_CUSTOM2;
      case NWNX_ANIMATION_LOOPING_CUSTOM3:             return ANIMATION_LOOPING_CUSTOM3;
      case NWNX_ANIMATION_LOOPING_CUSTOM4:             return ANIMATION_LOOPING_CUSTOM4;
      case NWNX_ANIMATION_LOOPING_CUSTOM5:             return ANIMATION_LOOPING_CUSTOM5;
      case NWNX_ANIMATION_LOOPING_CUSTOM6:             return ANIMATION_LOOPING_CUSTOM6;
      case NWNX_ANIMATION_LOOPING_CUSTOM7:             return ANIMATION_LOOPING_CUSTOM7;
      case NWNX_ANIMATION_LOOPING_CUSTOM8:             return ANIMATION_LOOPING_CUSTOM8;
      case NWNX_ANIMATION_LOOPING_CUSTOM9:             return ANIMATION_LOOPING_CUSTOM9;
      case NWNX_ANIMATION_LOOPING_CUSTOM10:            return ANIMATION_LOOPING_CUSTOM10;
      case NWNX_ANIMATION_LOOPING_CUSTOM11:            return ANIMATION_LOOPING_CUSTOM11;
      case NWNX_ANIMATION_LOOPING_CUSTOM12:            return ANIMATION_LOOPING_CUSTOM12;
      case NWNX_ANIMATION_LOOPING_CUSTOM13:            return ANIMATION_LOOPING_CUSTOM13;
      case NWNX_ANIMATION_LOOPING_CUSTOM14:            return ANIMATION_LOOPING_CUSTOM14;
      case NWNX_ANIMATION_LOOPING_CUSTOM15:            return ANIMATION_LOOPING_CUSTOM15;
      case NWNX_ANIMATION_LOOPING_CUSTOM16:            return ANIMATION_LOOPING_CUSTOM16;
      case NWNX_ANIMATION_LOOPING_CUSTOM17:            return ANIMATION_LOOPING_CUSTOM17;
      case NWNX_ANIMATION_LOOPING_CUSTOM18:            return ANIMATION_LOOPING_CUSTOM18;
      case NWNX_ANIMATION_LOOPING_CUSTOM19:            return ANIMATION_LOOPING_CUSTOM19;
      case NWNX_ANIMATION_LOOPING_CUSTOM20:            return ANIMATION_LOOPING_CUSTOM20;
      case NWNX_ANIMATION_MOUNT1:                      return ANIMATION_MOUNT1;
      case NWNX_ANIMATION_DISMOUNT1:                   return ANIMATION_DISMOUNT1;
    }

    return 0;
}

void StartTimingBar(object oCreature, int nSeconds, string sScript) {
    SetLocalString(oCreature, "NWNX!FUNCSEXT!STARTTIMINGBAR", IntToString(nSeconds*1000)+"    ");
    DeleteLocalString(oCreature, "NWNX!FUNCSEXT!STARTTIMINGBAR");
    DelayCommand(IntToFloat(nSeconds), StopTimingBar(oCreature, sScript));
}

void StopTimingBar(object oCreature, string sScript="") {
    SetLocalString(oCreature, "NWNX!FUNCSEXT!STOPTIMINGBAR", "    ");
    DeleteLocalString(oCreature, "NWNX!FUNCSEXT!STOPTIMINGBAR");
    if(sScript != "") {
        ExecuteScript(sScript, oCreature);
    }
}

int RemoveGold(object oCreature, int nGold) {
    SetLocalString(oCreature, "NWNX!FUNCSEXT!REMOVEGOLD", IntToString(nGold));
    int nRet = StringToInt(GetLocalString(oCreature, "NWNX!FUNCSEXT!REMOVEGOLD"));
    DeleteLocalString(oCreature, "NWNX!FUNCSEXT!REMOVEGOLD");
    return nRet;
}

int RemoveItem(object oItem) {
    object oPossessor = GetItemPossessor(oItem);
    if(!GetIsObjectValid(oPossessor)) return 0;

    SetLocalString(oPossessor, "NWNX!FUNCSEXT!REMOVEITEM", ObjectToString(oItem));
    int nRet = StringToInt(GetLocalString(oPossessor, "NWNX!FUNCSEXT!REMOVEITEM"));
    DeleteLocalString(oPossessor, "NWNX!FUNCSEXT!REMOVEITEM");
    return nRet;
}

void AreaVisualEffectForPC(object oPC, int nVFX, vector vPosition) {
    SetLocalString(oPC, "NWNX!FUNCSEXT!AREAVFX4PC", ObjectToString(oPC)+"¬"+IntToString(nVFX)+"¬"+FloatToString(vPosition.x)+"¬"+FloatToString(vPosition.y)+"¬"+FloatToString(vPosition.z));
    DeleteLocalString(oPC, "NWNX!FUNCSEXT!AREAVFX4PC");
}

void PossessCreature(object oPC, object oCreature) {
    SetLocalString(oPC, "NWNX!FUNCSEXT!POSSESS", ObjectToString(oCreature));
    DeleteLocalString(oPC, "NWNX!FUNCSEXT!POSSESS");
}

void UnPossessCreature(object oPC, object oCreature) {
    SetLocalString(oPC, "NWNX!FUNCSEXT!UNPOSSESS", "            ");
    DeleteLocalString(oPC, "NWNX!FUNCSEXT!UNPOSSESS");
}

int GetFlatFooted(object oCreature) {
    SetLocalString(oCreature, "NWNX!FUNCSEXT!GETFLATFOOTED", "                ");
    string sRet = GetLocalString(oCreature, "NWNX!FUNCSEXT!GETFLATFOOTED");
    DeleteLocalString(oCreature, "NWNX!FUNCSEXT!GETFLATFOOTED");
    return StringToInt(sRet);
}
