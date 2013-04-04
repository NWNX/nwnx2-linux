string LIST_ITEM_NAME = "PC_";
string PC_ID_NAME = "OID";

const int CHAT_CHANNEL_TALK        = 1;
const int CHAT_CHANNEL_SHOUT       = 2;
const int CHAT_CHANNEL_WHISPER     = 3;
const int CHAT_CHANNEL_PRIVATE     = 4;
const int CHAT_CHANNEL_SERVER_MSG  = 5;
const int CHAT_CHANNEL_PARTY       = 6;

struct chat_message
{
    int    Mode;
    object Recipient;
    string Text;
};

//Send chat message
//nChannel - CHAT_CHANNEL_*
int NWNXChat_SendMessage(object oSender, int nChannel, string sMessage, object oRecipient=OBJECT_INVALID);


string GetStringFrom(string s, int from = 1)
{
    return GetStringRight(s, GetStringLength(s) - from);
}

void NWNXChat_Init()
{
    int i;
    object oMod = GetModule();
    // memory for chat text
    string sMemory;
    for (i = 0; i < 8; i++) // reserve 8*128 bytes
        sMemory += "................................................................................................................................";
    SetLocalString(oMod, "NWNX!CHAT!SPACER", sMemory);
}

string NWNXChat_GetSpacer()
{
    return GetLocalString(GetModule(), "NWNX!CHAT!SPACER");
}

void NWNXChat_PCEnter(object oPC)
{
  if (!GetIsObjectValid(oPC)) return;
  object oMod = GetModule();
  SetLocalString(oPC, "NWNX!CHAT!GETID", ObjectToString(oPC)+"        ");
  string sID = GetLocalString(oPC, "NWNX!CHAT!GETID");
  int nID = StringToInt(sID);
  if (nID != -1)
  {
    SetLocalObject(oMod, LIST_ITEM_NAME + sID, oPC);
    SetLocalInt(oPC, PC_ID_NAME, nID);
  }
  DeleteLocalString(oPC, "NWNX!CHAT!GETID");
}

void NWNXChat_PCExit(object oPC)
{
  if (!GetIsObjectValid(oPC)) return;
  int nID = GetLocalInt(oPC, PC_ID_NAME);
  DeleteLocalInt(oPC, PC_ID_NAME);
  DeleteLocalObject(GetModule(), LIST_ITEM_NAME + IntToString(nID));
}

object NWNXChat_GetPCByPlayerID(int nID)
{
  return GetLocalObject(GetModule(), LIST_ITEM_NAME + IntToString(nID));
}


string NWNXChat_GetMessageText()
{
    SetLocalString(GetModule(), "NWNX!CHAT!TEXT", NWNXChat_GetSpacer());
    return GetLocalString(GetModule(), "NWNX!CHAT!TEXT");
}

struct chat_message NWNXChat_GetMessage()
{
    struct chat_message cmMessage;
    string sText = NWNXChat_GetMessageText();

    int nMode = StringToInt(GetStringLeft(sText,2));
    int nTo = StringToInt(GetSubString(sText,2,10));
    sText = GetStringFrom(sText, 12);
    cmMessage.Mode = nMode;
    cmMessage.Recipient = NWNXChat_GetPCByPlayerID(nTo);
    cmMessage.Text = sText;
    return cmMessage;
}

void NWNXChat_Log(string sLogMessage)
{
    SetLocalString(GetModule(), "NWNX!CHAT!LOG", sLogMessage);
}

void NWNXChat_SuppressMessage()
{
    SetLocalString(GetModule(), "NWNX!CHAT!SUPRESS", "1");
    DeleteLocalString(GetModule(), "NWNX!CHAT!SUPRESS");
}
int NWNXChat_SendMessage(object oSender, int nChannel, string sMessage, object oRecipient=OBJECT_INVALID)
{
    if (!GetIsObjectValid(oSender)) return FALSE;
    if (FindSubString(sMessage, "¬")!=-1) return FALSE;
    if (nChannel == CHAT_CHANNEL_PRIVATE && !GetIsObjectValid(oRecipient)) return FALSE;
    SetLocalString(oSender, "NWNX!CHAT!SPEAK", ObjectToString(oSender)+"¬"+ObjectToString(oRecipient)+"¬"+IntToString(nChannel)+"¬"+sMessage);
    if(GetLocalString(oSender, "NWNX!CHAT!SPEAK")=="1") return TRUE;
    else return FALSE;
}

void NWNXChat_SendMessageVoid(object oSender, int nChannel, string sMessage, object oRecipient=OBJECT_INVALID)
{
    NWNXChat_SendMessage(oSender, nChannel, sMessage, oRecipient);
}

int NWNXChat_GetCCMessageType()
{
    SetLocalString(GetModule(), "NWNX!CHAT!TYPE", "  ");
    return StringToInt(GetLocalString(GetModule(), "NWNX!CHAT!TYPE"));
}

int NWNXChat_GetCCMessagSubtype()
{
    SetLocalString(GetModule(), "NWNX!CHAT!SUBTYPE", "  ");
    return StringToInt(GetLocalString(GetModule(), "NWNX!CHAT!SUBTYPE"));
}