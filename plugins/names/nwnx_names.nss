//NWNX Names
//Dynamic names plugin
//written by virusman, 2006

void InitPlayerNameList(object oObject, int nUnknownStyle = 0);
void SetDynamicName(object oPlayer, object oObject, string sName);
void DeleteDynamicName(object oPlayer, object oObject);
void ClearPlayerNameList(object oPlayer);

void InitPlayerNameList(object oObject, int nUnknownStyle = 0)
{
    SetLocalString(oObject, "NWNX!EVENTS!INITPLAYERNAMELIST", IntToString(nUnknownStyle));
}

void SetDynamicName(object oPlayer, object oObject, string sName)
{
    SetLocalString(oPlayer, "NWNX!EVENTS!SETDYNAMICNAME", ObjectToString(oObject)+"¬"+sName);
}

void DeleteDynamicName(object oPlayer, object oObject)
{
    SetLocalString(oPlayer, "NWNX!EVENTS!DELETEDYNAMICNAME", ObjectToString(oObject));
}

void ClearPlayerNameList(object oPlayer)
{
    SetLocalString(oPlayer, "NWNX!EVENTS!CLEARPLAYERNAMELIST", " ");
}

