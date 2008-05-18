//::///////////////////////////////////////////////
//:: dmb_chat
//:: FileName
//:: Copyright (c) 2005 dumbo (dumbo@nm.ru)
//:: Copyright (c) 2006-2007 virusman (virusman@virusman.ru)
//:://////////////////////////////////////////////
/*
  include file with initialization and some helpers
*/
//:://////////////////////////////////////////////
//:: Created By: dumbo
//:: Created On: 2005-09-08
//:: Modified By: virusman
//:: Modified On: 2007-02-15
//:://////////////////////////////////////////////

string dmb_LIST_ITEM_NAME = "dmbPC_";
string dmb_PC_ID_NAME = "dmbID";

const int CHAT_CHANNEL_TALK        = 1;
const int CHAT_CHANNEL_SHOUT       = 2;
const int CHAT_CHANNEL_WHISPER     = 3;
const int CHAT_CHANNEL_PRIVATE     = 4;
const int CHAT_CHANNEL_SERVER_MSG  = 5;
const int CHAT_CHANNEL_PARTY       = 6;

//Send chat message
//nChannel - CHAT_CHANNEL_*
void dmb_SendMessage(object oSender, int nChannel, string sMessage, object oRecipient=OBJECT_INVALID);

void dmb_ChatInit()
{
    int i;
    object oMod = GetModule();
    // memory for chat text
    string sMemory;
    for (i = 0; i < 8; i++) // reserve 8*128 bytes
        sMemory += "................................................................................................................................";
    SetLocalString(oMod, "NWNX!INIT", "1");
    SetLocalString(oMod, "NWNX!CHAT!SPACER", sMemory);
}

string dmb_GetStringFrom(string s, int from = 1)
{
    return GetStringRight(s, GetStringLength(s) - from);
}

string dmb_GetSpacer()
{
    return GetLocalString(GetModule(), "NWNX!CHAT!SPACER");
}

void dmb_PCin(object oPC)
{
  if (!GetIsObjectValid(oPC)) return;
  object oMod = GetModule();
  SetLocalString(oPC, "NWNX!CHAT!GETID", ObjectToString(oPC)+"        ");
  string sID = GetLocalString(oPC, "NWNX!CHAT!GETID");
  int nID = StringToInt(sID);
  if (nID != -1)
  {
    SetLocalObject(oMod, dmb_LIST_ITEM_NAME + sID, oPC);
    SetLocalInt(oPC, dmb_PC_ID_NAME, nID);
  }
  DeleteLocalString(oPC, "NWNX!CHAT!GETID");
}

int dmb_GetClientID(object oPC)
{
    if (!GetIsObjectValid(oPC)) return -1;
    if (!GetIsPC(oPC)&&!GetIsPossessedFamiliar(oPC)&&!GetIsDM(oPC)&&!GetIsDMPossessed(oPC)) return -1;
    SetLocalString(oPC, "NWNX!CHAT!GETID", ObjectToString(oPC)+"        ");
    string sID = GetLocalString(oPC, "NWNX!CHAT!GETID");
    int nID = StringToInt(sID);
    return nID;
}

int dmb_SendMessage(object oSender, int nChannel, string sMessage, object oRecipient=OBJECT_INVALID)
{
    if (!GetIsObjectValid(oSender)) return;
    if (FindSubString(sMessage, "¬")!=-1) return;
    if (nChannel == CHAT_CHANNEL_PRIVATE && !GetIsObjectValid(oRecipient)) return;
    SetLocalString(oSender, "NWNX!CHAT!SPEAK", ObjectToString(oSender)+"¬"+ObjectToString(oRecipient)+"¬"+IntToString(nChannel)+"¬"+sMessage);
	if(GetLocalString(oSender, "NWNX!CHAT!SPEAK")=="1") return TRUE;
	else return FALSE;
}

void dmb_PCout(object oPC)
{
  if (!GetIsObjectValid(oPC)) return;
  int nID = GetLocalInt(oPC, dmb_PC_ID_NAME);
  DeleteLocalInt(oPC, dmb_PC_ID_NAME);
  DeleteLocalObject(GetModule(), dmb_LIST_ITEM_NAME + IntToString(nID));
}

object dmb_getPC(int nID)
{
  return GetLocalObject(GetModule(), dmb_LIST_ITEM_NAME + IntToString(nID));
}
