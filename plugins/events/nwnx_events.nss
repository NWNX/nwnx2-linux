const int EVENT_TYPE_SAVE_CHAR         = 1;
const int EVENT_TYPE_PICKPOCKET        = 2;
const int EVENT_TYPE_ATTACK            = 3;
const int EVENT_TYPE_USE_ITEM          = 4;
const int EVENT_TYPE_QUICKCHAT         = 5;
const int EVENT_TYPE_EXAMINE           = 6;
const int EVENT_TYPE_USE_SKILL         = 7;
const int EVENT_TYPE_USE_FEAT          = 8;
const int EVENT_TYPE_CAST_SPELL        = 9;
const int EVENT_TYPE_TOGGLE_MODE       = 10;
const int EVENT_TYPE_TOGGLE_PAUSE      = 11;
const int EVENT_TYPE_POSSESS_FAMILIAR  = 12;

const int NODE_TYPE_STARTING_NODE      = 0;
const int NODE_TYPE_ENTRY_NODE         = 1;
const int NODE_TYPE_REPLY_NODE         = 2;

const int LANGUAGE_ENGLISH             = 0;
const int LANGUAGE_FRENCH              = 1;
const int LANGUAGE_GERMAN              = 2;
const int LANGUAGE_ITALIAN             = 3;
const int LANGUAGE_SPANISH             = 4;
const int LANGUAGE_POLISH              = 5;
const int LANGUAGE_KOREAN              = 128;
const int LANGUAGE_CHINESE_TRADITIONAL = 129;
const int LANGUAGE_CHINESE_SIMPLIFIED  = 130;
const int LANGUAGE_JAPANESE            = 131;

int GetEventType();
int GetEventSubType();
object GetEventTarget();
object GetEventItem();
vector GetEventPosition();
void BypassEvent();

int GetCurrentNodeType();
int GetCurrentNodeID();
int GetCurrentAbsoluteNodeID();
string GetCurrentNodeText(int nLangID = LANGUAGE_ENGLISH, int nGender = GENDER_MALE);
void SetCurrentNodeText(string sText, int nLangID = LANGUAGE_ENGLISH, int nGender = GENDER_MALE);
int GetSelectedNodeID();
int GetSelectedAbsoluteNodeID();
string GetSelectedNodeText(int nLangID = LANGUAGE_ENGLISH, int nGender = GENDER_MALE);

int GetEventType()
{
    SetLocalString(GetModule(), "NWNX!EVENTS!GET_EVENT_ID", "          ");
    return StringToInt(GetLocalString(GetModule(), "NWNX!EVENTS!GET_EVENT_ID"));
}

int GetEventSubType()
{
    SetLocalString(GetModule(), "NWNX!EVENTS!GET_EVENT_SUBID", "          ");
    return StringToInt(GetLocalString(GetModule(), "NWNX!EVENTS!GET_EVENT_SUBID"));
}

object GetEventTarget()
{
    return GetLocalObject(GetModule(), "NWNX!EVENTS!TARGET");
}

object GetEventItem()
{
    return GetLocalObject(GetModule(), "NWNX!EVENTS!ITEM");
}

vector GetEventPosition()
{
    SetLocalString(GetModule(), "NWNX!EVENTS!GET_EVENT_POSITION", "                                              ");
    string sVector = GetLocalString(GetModule(), "NWNX!EVENTS!GET_EVENT_POSITION");
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
    if(nPos == -1)
    {
        z = StringToFloat(sVector);
    }
    else return Vector();
    return Vector(x, y, z);
}

void BypassEvent()
{
    SetLocalString(GetModule(), "NWNX!EVENTS!BYPASS", "1");
}

int GetCurrentNodeType()
{
    SetLocalString(GetModule(), "NWNX!EVENTS!GET_NODE_TYPE", "      ");
    return StringToInt(GetLocalString(GetModule(), "NWNX!EVENTS!GET_NODE_TYPE"));
}

int GetCurrentNodeID()
{
    SetLocalString(GetModule(), "NWNX!EVENTS!GET_NODE_ID", "      ");
    return StringToInt(GetLocalString(GetModule(), "NWNX!EVENTS!GET_NODE_ID"));
}

int GetCurrentAbsoluteNodeID()
{
    SetLocalString(GetModule(), "NWNX!EVENTS!GET_ABSOLUTE_NODE_ID", "      ");
    return StringToInt(GetLocalString(GetModule(), "NWNX!EVENTS!GET_ABSOLUTE_NODE_ID"));
}

int GetSelectedNodeID()
{
    SetLocalString(GetModule(), "NWNX!EVENTS!GET_SELECTED_NODE_ID", "      ");
    return StringToInt(GetLocalString(GetModule(), "NWNX!EVENTS!GET_SELECTED_NODE_ID"));
}

int GetSelectedAbsoluteNodeID()
{
    SetLocalString(GetModule(), "NWNX!EVENTS!GET_SELECTED_ABSOLUTE_NODE_ID", "      ");
    return StringToInt(GetLocalString(GetModule(), "NWNX!EVENTS!GET_SELECTED_ABSOLUTE_NODE_ID"));
}

string GetSelectedNodeText(int nLangID, int nGender)
{
    if (nGender != GENDER_FEMALE) nGender = GENDER_MALE;
    SetLocalString(GetModule(), "NWNX!EVENTS!GET_SELECTED_NODE_TEXT", IntToString(nLangID*2 + nGender));
    return GetLocalString(GetModule(), "NWNX!EVENTS!GET_SELECTED_NODE_TEXT");
}

string GetCurrentNodeText(int nLangID, int nGender)
{
    if (nGender != GENDER_FEMALE) nGender = GENDER_MALE;
    SetLocalString(GetModule(), "NWNX!EVENTS!GET_NODE_TEXT", IntToString(nLangID*2 + nGender));
    return GetLocalString(GetModule(), "NWNX!EVENTS!GET_NODE_TEXT");
}

void SetCurrentNodeText(string sText, int nLangID, int nGender)
{
    if (nGender != GENDER_FEMALE) nGender = GENDER_MALE;
    SetLocalString(GetModule(), "NWNX!EVENTS!SET_NODE_TEXT", IntToString(nLangID*2 + nGender)+"¬"+sText);
}
