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
    ENCOUNTER_SCRIPT_USER_DEFINED   = 4,


    AREA_TRANSITION_LINK_NONE       = 0,
    AREA_TRANSITION_LINK_DOOR       = 1,
    AREA_TRANSITION_LINK_WAYPOINT   = 2,

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

// Sets target's event handler script
void SetScript(object oTarget, int nScript, string sScript="");

// Gets target's event handler script
string GetScript(object oTarget, int nScript);

// Creates area transition
object CreateAreaTransitionOnLocation(location lLocation, int nLinkType=AREA_TRANSITION_LINK_NONE, string sTargetTag="", float fSize=2.0f,  string sTag="");

// Get surface material type from location
int GetSurface(location lLocation);

// Get current animation of oTarget
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

void UnPossessCreature(object oPC, object oCreature);

// Get is oCreature flat-footed
int GetFlatFooted(object oCreature);

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

object CreateGenericTriggerOnLocation(location lLocation, float fSize=2.0f,  string sTag="") {
    object oTrigger = CreateTrapAtLocation(1, lLocation, fSize, sTag);
    if(GetIsObjectValid(oTrigger)) {
        SetLocalString(oTrigger, "NWNX!FUNCSEXT!SETISGENERICTRIGGER", "          ");
        DeleteLocalString(oTrigger, "NWNX!FUNCSEXT!SETISGENERICTRIGGER");
    }
    return oTrigger;
}

object CreateAreaTransitionOnLocation(location lLocation, int nLinkType=AREA_TRANSITION_LINK_NONE, string sTargetTag="", float fSize=2.0f,  string sTag="") {
    object oTrigger = CreateTrapAtLocation(1, lLocation, fSize, sTag);
    if(GetIsObjectValid(oTrigger)) {
        SetLocalString(oTrigger, "NWNX!FUNCSEXT!SETISAREATRANSITION", "          ");
        DeleteLocalString(oTrigger, "NWNX!FUNCSEXT!SETISAREATRANSITION");
        if(nLinkType != AREA_TRANSITION_LINK_NONE) {
            object oTarget;
            if(nLinkType == AREA_TRANSITION_LINK_DOOR) {
                int nNth;
                for(nNth=0;nNth<25;++nNth) {
                    object oTmp = GetObjectByTag(sTargetTag, nNth);
                    if(GetObjectType(oTmp) == OBJECT_TYPE_DOOR) {
                        oTarget = oTmp;
                        break;
                    }
                }
            } else
            if(nLinkType == AREA_TRANSITION_LINK_WAYPOINT) {
                oTarget = GetWaypointByTag("sTargetTag");
            }
            if(GetIsObjectValid(oTarget)) {
                SetLocalObject(oTrigger, "FUNCSEXT_TRANSITION_TARGET", oTarget);
            }
            SetScript(oTrigger, TRIGGER_SCRIPT_TRANSITION_CLICK, "funcsext_trgclk");
        }
    }
    return oTrigger;
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
    return StringToInt(sRet);
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
