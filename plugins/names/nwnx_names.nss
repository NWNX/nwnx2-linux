//NWNX Names
//Dynamic names plugin
//written by virusman, 2006-2010

// Call this function on ClientEnter event
void InitPlayerNameList(object oObject, int nUnknownStyle = 0);
// Call SetNamesEnabled after initializing the name list to activate the system for the player
// SetNamesEnabled(oPC, 0) can be used to exclude DMs from names replacement
// and always show them the true names
void SetNamesEnabled(object oPlayer, int bEnabled = TRUE);
string GetDynamicName(object oPlayer, object oObject);
void SetDynamicName(object oPlayer, object oObject, string sName);
void DeleteDynamicName(object oPlayer, object oObject);
// Do not use this
void ClearPlayerNameList(object oPlayer);


void InitPlayerNameList(object oObject, int nUnknownStyle = 0)
{
    SetLocalString(oObject, "NWNX!NAMES!INITPLAYERNAMELIST", IntToString(nUnknownStyle));
}

void SetNamesEnabled(object oPlayer, int bEnabled = TRUE)
{
    if(!GetIsPC(oPlayer)) return;
    SetLocalString(oPlayer, "NWNX!NAMES!SETNAMESENABLED", IntToString(bEnabled));
}

string GetDynamicName(object oPlayer, object oObject)
{
    SetLocalString(oPlayer, "NWNX!NAMES!GETDYNAMICNAME", ObjectToString(oObject));
    return GetLocalString(oPlayer, "NWNX!NAMES!GETDYNAMICNAME");
}

void SetDynamicName(object oPlayer, object oObject, string sName)
{
    SetLocalString(oPlayer, "NWNX!NAMES!SETDYNAMICNAME", ObjectToString(oObject)+"¬"+sName);
}

void DeleteDynamicName(object oPlayer, object oObject)
{
    SetLocalString(oPlayer, "NWNX!NAMES!DELETEDYNAMICNAME", ObjectToString(oObject));
}

void ClearPlayerNameList(object oPlayer)
{
    SetLocalString(oPlayer, "NWNX!NAMES!CLEARPLAYERNAMELIST", " ");
}
