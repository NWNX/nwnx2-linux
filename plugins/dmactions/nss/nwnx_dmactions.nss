const int
    DM_ACTION_MESSAGE_TYPE           =  1,
    DM_ACTION_GIVE_XP                =  2,
    DM_ACTION_GIVE_LEVEL             =  3,
    DM_ACTION_GIVE_GOLD              =  4,
    DM_ACTION_CREATE_ITEM_ON_OBJECT  =  5,
    DM_ACTION_CREATE_ITEM_ON_AREA    =  6,
    DM_ACTION_HEAL_CREATURE          =  7,
    DM_ACTION_REST_CREATURE          =  8,
    DM_ACTION_RUNSCRIPT              =  9,
    DM_ACTION_CREATE_PLACEABLE       = 10,
    DM_ACTION_SPAWN_CREATURE         = 11,
    DM_ACTION_TOGGLE_INVULNERABILITY = 12,
    DM_ACTION_TOGGLE_IMMORTALITY     = 13;

// Set script name called on specified action
void SetDMActionScript(int nAction, string sScript);

// Get ID of DM Action
int nGetDMActionID();

// Get int param of DM Action
int nGetDMAction_Param(int bSecond=FALSE);

// Get string param of DM Action
string sGetDMAction_Param();

// Get target object of DM Action
object oGetDMAction_Target(int bSecond=FALSE);

// Get target position of DM Action
vector vGetDMAction_Position();

// Get total targets number in multiselection
int nGetDMAction_TargetsCount();

// Get current target number in multiselection.
int nGetDMAction_TargetsCurrent();

void SetDMActionScript(int nAction, string sScript) {
    SetLocalString(OBJECT_SELF, "NWNX!DMACTIONS!SET_ACTION_SCRIPT", IntToString(nAction)+":"+sScript);
    DeleteLocalString(OBJECT_SELF, "NWNX!DMACTIONS!SET_ACTION_SCRIPT");
}

int nGetDMActionID() {
    SetLocalString(OBJECT_SELF, "NWNX!DMACTIONS!GETACTIONID", "                ");
    string sAction = GetLocalString(OBJECT_SELF, "NWNX!DMACTIONS!GETACTIONID");
    DeleteLocalString(OBJECT_SELF, "NWNX!DMACTIONS!GETACTIONID");
    return StringToInt(sAction);
}

void PreventDMAction() {
    SetLocalString(OBJECT_SELF, "NWNX!DMACTIONS!PREVENT", "1");
    DeleteLocalString(OBJECT_SELF, "NWNX!DMACTIONS!PREVENT");
}

int nGetDMAction_Param(int bSecond=FALSE) {
    string sNth = bSecond?"2":"1";
    SetLocalString(OBJECT_SELF, "NWNX!DMACTIONS!GETPARAM_"+sNth, "                ");
    string sVal = GetLocalString(OBJECT_SELF, "NWNX!DMACTIONS!GETPARAM_"+sNth);
    DeleteLocalString(OBJECT_SELF, "NWNX!DMACTIONS!GETPARAM_"+sNth);
    return StringToInt(sVal);
}

string sGetDMAction_Param() {
    SetLocalString(OBJECT_SELF, "NWNX!DMACTIONS!GETSTRPARAM1", "                                ");
    string sVal = GetLocalString(OBJECT_SELF, "NWNX!DMACTIONS!GETSTRPARAM1");
    DeleteLocalString(OBJECT_SELF, "NWNX!DMACTIONS!GETSTRPARAM1");
    return sVal;
}

object oGetDMAction_Target(int bSecond=FALSE) {
    string sNth = bSecond?"2":"1";
    return GetLocalObject(OBJECT_SELF, "NWNX!DMACTIONS!TARGET_"+sNth);
}

vector vGetDMAction_Position() {
    SetLocalString(OBJECT_SELF, "NWNX!DMACTIONS!GETPOS", "                                              ");
    string sVector = GetLocalString(OBJECT_SELF, "NWNX!DMACTIONS!GETPOS");
    DeleteLocalString(OBJECT_SELF, "NWNX!DMACTIONS!GETPOS");
    float x, y, z;

    //Get X
    int nPos = FindSubString(sVector, "¬");
    if(nPos == -1) return Vector();
    x = StringToFloat(GetStringLeft(sVector, nPos));
    sVector = GetStringRight(sVector, GetStringLength(sVector) - nPos - 1);

    //Get Y
    nPos = FindSubString(sVector, "¬");
    if(nPos == -1) return Vector();
    y = StringToFloat(GetStringLeft(sVector, nPos));
    sVector = GetStringRight(sVector, GetStringLength(sVector) - nPos - 1);

    //Get Z
    nPos = FindSubString(sVector, "¬");
    if(nPos == -1) {
        z = StringToFloat(sVector);
    } else return Vector();

    return Vector(x, y, z);
}

int nGetDMAction_TargetsCount() {
    SetLocalString(OBJECT_SELF, "NWNX!DMACTIONS!GETTARGETSCOUNT", "                ");
    string sVal = GetLocalString(OBJECT_SELF, "NWNX!DMACTIONS!GETTARGETSCOUNT");
    DeleteLocalString(OBJECT_SELF, "NWNX!DMACTIONS!GETTARGETSCOUNT");
    return StringToInt(sVal);
}

int nGetDMAction_TargetsCurrent() {
    SetLocalString(OBJECT_SELF, "NWNX!DMACTIONS!GETTARGETSCURRENT", "                ");
    string sVal = GetLocalString(OBJECT_SELF, "NWNX!DMACTIONS!GETTARGETSCURRENT");
    DeleteLocalString(OBJECT_SELF, "NWNX!DMACTIONS!GETTARGETSCURRENT");
    return StringToInt(sVal);
}
