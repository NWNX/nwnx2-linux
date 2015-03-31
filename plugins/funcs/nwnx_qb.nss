#include "aps_include"
#include "nwnx_funcs"
#include "x0_i0_stringlib"

// Set this to false if you don't use InnoDB or MySQL
const int InnoDB = TRUE;

// This should return your player's identification number however you have it set
int GetPlayerID(object oPC)
{
    return 1;
}

// Not sure if this is portable to other dbs, might need to use GetMax if not using MySQL
// Technically this should exist in your aps_include or other db specific lib to your site
int GetLastInsertId()
{
    int iId = 0;
    string sSQL="SELECT LAST_INSERT_ID()";
    SQLExecDirect(sSQL);
    if(SQLFetch())
        iId = StringToInt(SQLGetData(1));
    return iId;
}

string GetHenchmanCommandName(int iType)
{
    switch (iType)
    {
        case 0: return "Attack Nearest";
        case 4: return "Heal Me";
        case 9: return "Guard Me";
        case 10: return "Stand Ground";
        case 22: return "Follow";
    }
    return "Unknown";
}

string GetModeName(int iMode)
{
    switch (iMode)
    {
        case ACTION_MODE_DETECT: return "Detect";
        case ACTION_MODE_STEALTH: return "Stealth";
        case ACTION_MODE_PARRY: return "Parry";
        case ACTION_MODE_POWER_ATTACK: return "Power Attack";
        case ACTION_MODE_IMPROVED_POWER_ATTACK: return "Improved Power Attack";
        case ACTION_MODE_COUNTERSPELL: return "Counterspell";
        case ACTION_MODE_FLURRY_OF_BLOWS: return "Flurry of Blows";
        case ACTION_MODE_RAPID_SHOT: return "Rapid Shot";
        case ACTION_MODE_EXPERTISE: return "Expertise";
        case ACTION_MODE_IMPROVED_EXPERTISE: return "Improved Expertise";
        case ACTION_MODE_DEFENSIVE_CAST: return "Defensive Casting";
        case ACTION_MODE_DIRTY_FIGHTING: return "Dirty Fighting";
    }
    return "Unknown";
}

string GetMetaMagicName(int iMeta)
{
    switch (iMeta)
    {
        case METAMAGIC_EMPOWER: return "Empowered";
        case METAMAGIC_EXTEND: return "Extended";
        case METAMAGIC_MAXIMIZE: return "Maximized";
        case METAMAGIC_QUICKEN: return "Quickened";
        case METAMAGIC_SILENT: return "Silent";
        case METAMAGIC_STILL: return "Stilled";
    }
    return "";
}

string GetQuickBarType (int iType) 
{ 
    switch (iType) 
    {
        case QUICKBAR_TYPE_INVALID: return "Empty";
        case QUICKBAR_TYPE_ITEM: return "Item";
        case QUICKBAR_TYPE_SPELL: return "Spell";
        case QUICKBAR_TYPE_SKILL: return "Skill";
        case QUICKBAR_TYPE_FEAT: return "Feat";
        case QUICKBAR_TYPE_TALKTO: return "Talk To";
        case QUICKBAR_TYPE_ATTACK: return "Attack";
        case QUICKBAR_TYPE_EMOTE: return "Emote";
        case QUICKBAR_TYPE_MODE: return "Mode";
        case QUICKBAR_TYPE_MACRO: return "Custom Macro";
        case QUICKBAR_TYPE_POSSESS: return "Possess";
        case QUICKBAR_TYPE_SUMMON: return "Summon Familiar";
        case QUICKBAR_TYPE_EXAMINE: return "Examine";
        case QUICKBAR_TYPE_BARTER: return "Barter";
        case QUICKBAR_TYPE_HENCH: return "Henchman";
    }
    return ""; 
} 

// Returns a human readable name for the slots since they are numbered 0-35 (i.e. Ctrl-F4)
string GetSlotString(int iSlot)
{
    string sRow = "";
    int iRowFKey;
    if (iSlot > 11 && iSlot < 24)
    {
        iRowFKey = iSlot-11;
        sRow = "Shift-";
    }
    else if(iSlot > 23)
    {
        iRowFKey = iSlot-23;
        sRow = "Ctrl-";
    }
    else
        iRowFKey = iSlot+1;
    return sRow+"F"+IntToString(iRowFKey);
}

int CheckForExistingQuickBar(string sPCID, string sEncName)
{
    string sSQL = "SELECT id FROM player_qb WHERE player_id = "+sPCID+" AND name = '"+sEncName+"'";
    SQLExecDirect(sSQL);
    if (SQLFetch() == SQL_SUCCESS)
        return 1;
    return 0;
}

void WarnNoQuickBar(object oPC, string sName)
{
    SendMessageToPC(oPC, "You have no saved quickbars named "+sName+".");
}

void WarnNoName(object oPC, string sCommand)
{
    SendMessageToPC(oPC, "You must specify the name for the quickbar you wish to "+sCommand+".");
}

void ListQuickBars(object oPC)
{
    string sPCID = IntToString(GetPlayerID(oPC));
    string sSQL = "SELECT name FROM player_qb WHERE player_id = "+sPCID;
    SQLExecDirect(sSQL);
    int iFound = 0;
    string sName = "default";
    while (SQLFetch() == SQL_SUCCESS)
    {
        if (!iFound)
        {
            SendMessageToPC(oPC, "Listed below are your current known quickbars:");
            iFound = 1;
        }
        sName = SQLGetData(1);
        SendMessageToPC(oPC, "* "+sName);
    }
    if (iFound)
    {
        SendMessageToPC(oPC, "For a detailed list of what is in each slot, use the describe command.");
    }
    else
        SendMessageToPC(oPC, "You have no quickbars saved.");
}
my
void SaveQuickBar(object oPC, string sName, int iSilent = 0)
{
    if (sName == "")
    {
        WarnNoName(oPC, "save");
        return;
    } 

    if (GetStringLength(sName) > 16)
    {
        SendMessageToPC(oPC, "Quickbar names can not be longer than 16 characters.");
        return;
    }

    int iStart = 0;
    int iEnd = 35;
    int i = iStart;
    string sPCID = IntToString(GetPlayerID(oPC));
    string sEncName = SQLEncodeSpecialChars(sName);
    if (CheckForExistingQuickBar(sPCID, sEncName))
    {
        SendMessageToPC(oPC, "You have already saved a quickbar named "+sName+". If you wish to overwrite it, use "+
        "the replace command.");
        return;
    }
    string sSQL = "INSERT INTO player_qb VALUES (NULL,"+sPCID+",'"+sEncName+"')";
    SQLExecDirect(sSQL);
    string sQBID = IntToString(GetLastInsertId());
    sSQL = "INSERT INTO player_qb_slots "+
    "(qb_id, slot, slot_type, special_id, meta, class, label, command, item_one, item_two) VALUES ";
    while (i <= iEnd)
    {
        string sBar = GetRawQuickBarSlot(oPC, i);
        int iTokens = GetNumberTokens(sBar, "|");
        if (iTokens != 4)
        {
            SendMessageToPC(oPC, "Unable to save slot "+GetSlotString(i)+", invalid pipe character detected.");
            i++;
            continue;
        }
        int iType = StringToInt(GetTokenByPosition(sBar,"|",0));
        switch (iType)
        {
            case 18:
            {
                string sLabel = SQLEncodeSpecialChars(GetTokenByPosition(sBar,"|",1));
                string sCommand = SQLEncodeSpecialChars(GetTokenByPosition(sBar,"|",2));
                sSQL += "("+sQBID+","+IntToString(i)+","+IntToString(iType)+",NULL,NULL,NULL,'"+sLabel+"','"+
                sCommand+"',NULL, NULL),";
                break;
            }
            case 1:
            {
                string sObjID1 = GetTokenByPosition(sBar,"|",1);
                int iObjSpellID = StringToInt(GetTokenByPosition(sBar,"|",3));
                object oEquip1 = StringToObject(sObjID1);
                string sQBEquip1 = GetLocalString(oEquip1,"qb_equip");
                string sQBEquipDB1;
                int iEquipMax = GetPersistentInt(oPC,"qb_equip_max");
                if ((sQBEquip1 == "") || (GetTokenByPosition(sQBEquip1,"-",0) != sPCID))
                {
                    sQBEquip1 = sPCID+"-"+IntToString(iEquipMax);
                    sQBEquipDB1 = IntToString(iEquipMax);
                    SetLocalString(oEquip1, "qb_equip",sQBEquip1);
                    iEquipMax++;
                }
                else
                    sQBEquipDB1 = GetTokenByPosition(sQBEquip1,"-",1);
                string sObjID2 = GetTokenByPosition(sBar,"|",2);
                object oEquip2 = OBJECT_INVALID;
                if (sObjID2 != "0" && sObjID2 != "7f000000")
                {
                    oEquip2 = StringToObject(sObjID2);
                    string sQBEquip2 = GetLocalString(oEquip2,"qb_equip");
                    string sQBEquipDB2;
                    if ((sQBEquip2 == "") || (GetTokenByPosition(sQBEquip2,"-",0) != sPCID))
                    {
                        sQBEquip2 = sPCID+"-"+IntToString(iEquipMax);
                        sQBEquipDB2 = IntToString(iEquipMax);
                        SetLocalString(oEquip2, "qb_equip",sQBEquip2);
                        iEquipMax++;
                    }
                    else
                        sQBEquipDB2 = GetTokenByPosition(sQBEquip2,"-",1);
                    sSQL += "("+sQBID+","+IntToString(i)+","+IntToString(iType)+",16711935,NULL,NULL,NULL,NULL,"+
                    sQBEquipDB1+","+sQBEquipDB2+"),";
                }
                else
                {
                    sSQL += "("+sQBID+","+IntToString(i)+","+IntToString(iType)+","+IntToString(iObjSpellID)+
                    ",NULL,NULL,NULL,NULL,"+sQBEquipDB1+",NULL),";
                }
                SetPersistentInt(oPC,"qb_equip_max",iEquipMax);
                break;
            }
            case 11: case 12: case 13: case 14: case 15: case 16: case 17: {
                string sLabel = SQLEncodeSpecialChars(GetTokenByPosition(sBar,"|",1));
                string sResRef = SQLEncodeSpecialChars(GetTokenByPosition(sBar,"|",2));
                sSQL += "("+sQBID+","+IntToString(i)+","+IntToString(iType)+",NULL,NULL,NULL,'"+sLabel+"','"+
                sResRef+"',NULL, NULL),";
                break;
            }
            default:
            {
                string sClass = GetTokenByPosition(sBar,"|",1);
                string sID = GetTokenByPosition(sBar,"|",2);
                string sMeta = GetTokenByPosition(sBar,"|",3);
                sSQL += "("+sQBID+","+IntToString(i)+","+IntToString(iType)+","+sID+","+sMeta+","+sClass+
                ",NULL,NULL,NULL,NULL),";
            }
        }
        i++;
    }
    // Chop off the last comma
    sSQL = GetSubString(sSQL,0,GetStringLength(sSQL)-1);
    SQLExecDirect(sSQL);
    if (!iSilent)
        SendMessageToPC(oPC, "Quickbar named "+sName+" saved.");
}

void RestoreQuickBar(object oPC, string sName)
{
    if (sName == "")
    {
        WarnNoName(oPC, "restore");
        return;
    }
    string sPCID = IntToString(GetPlayerID(oPC));
    string sEncName = SQLEncodeSpecialChars(sName);
    if (!CheckForExistingQuickBar(sPCID, sEncName))
    {
        WarnNoQuickBar(oPC, sName);
        return;
    }
    string sSQL = "SELECT player_qb_slots.* FROM player_qb, player_qb_slots "+
    "WHERE player_qb.id = player_qb_slots.qb_id AND player_id = "+sPCID+" AND name = '"+sEncName+"'";
    SQLExecDirect(sSQL);
    while (SQLFetch() == SQL_SUCCESS)
    {
        string sSlot = SQLGetData(2);
        int iSlot = StringToInt(sSlot);
        int iType = StringToInt(SQLGetData(3));
        string sSpellID = SQLGetData(4);
        // Items
        if (iType == 1)
        {
            int iItemOne = StringToInt(SQLGetData(9));
            int iItemTwo = StringToInt(SQLGetData(10));
            object oItemFoundOne = OBJECT_INVALID;
            object oItemFoundTwo = OBJECT_INVALID;
            object oItem = GetFirstItemInInventory(oPC);
            while (oItem != OBJECT_INVALID)
            {
                if (GetLocalString(oItem,"qb_equip") == sPCID+"-"+IntToString(iItemOne))
                    oItemFoundOne = oItem;
                if ((iItemTwo != 0) && (GetLocalString(oItem,"qb_equip") == sPCID+"-"+IntToString(iItemTwo)))
                    oItemFoundTwo = oItem;
                if ((oItemFoundOne == OBJECT_INVALID) || ((iItemTwo != 0) && (oItemFoundTwo == OBJECT_INVALID)))
                    oItem = GetNextItemInInventory(oPC);
                else
                    oItem = OBJECT_INVALID;
            }
            int nSlot;
            if (oItemFoundOne == OBJECT_INVALID)
            {
                for (nSlot=0; nSlot<NUM_INVENTORY_SLOTS; nSlot++)
                {
                    oItem=GetItemInSlot(nSlot, oPC);
                    if (GetLocalString(oItem,"qb_equip") == sPCID+"-"+IntToString(iItemOne))
                        oItemFoundOne = oItem;
                }
            }
            if ((iItemTwo != 0) && (oItemFoundTwo == OBJECT_INVALID))
            {
                for (nSlot=0; nSlot<NUM_INVENTORY_SLOTS; nSlot++)
                {
                    oItem=GetItemInSlot(nSlot, oPC);
                    if (GetLocalString(oItem,"qb_equip") == sPCID+"-"+IntToString(iItemTwo))
                        oItemFoundTwo = oItem;
                }
            }
            string sItemOne = ObjectToString(oItemFoundOne);
            string sItemTwo = ObjectToString(oItemFoundTwo);
            if ((oItemFoundOne == OBJECT_INVALID) || ((iItemTwo != 0) && (oItemFoundTwo == OBJECT_INVALID)))
                SendMessageToPC(oPC,"Could not restore slot "+GetSlotString(iSlot)+". Item(s) no longer found.");
            SetRawQuickBarSlot(oPC,sSlot+"¬1¬"+sItemOne+"¬"+sSpellID+"¬"+sItemTwo+"¬ ¬ ");
        }
        else if ((iType >= 11) && (iType <= 18))
        {
            string sLabel = SQLGetData(7);
            string sCommand = SQLGetData(8);
            SetRawQuickBarSlot(oPC,sSlot+"¬"+IntToString(iType)+"¬0¬0¬0¬"+sCommand+"¬"+sLabel);
        }
        else
        {
            string sMeta = SQLGetData(5);
            string sClass = SQLGetData(6);
            SetRawQuickBarSlot(oPC,sSlot+"¬"+IntToString(iType)+"¬"+sClass+"¬"+sSpellID+"¬"+sMeta+"¬ ¬ ");
        }
    }
    SendMessageToPC(oPC, "You restore your "+sName+" quickbar.");
}

void DeleteQuickBar(object oPC, string sName, int iSilent = 0)
{
    if (sName == "")
    {
        WarnNoName(oPC, "delete");
        return;
    }
    string sPCID = IntToString(GetPlayerID(oPC));
    string sEncName = SQLEncodeSpecialChars(sName);
    int iQBID = CheckForExistingQuickBar(sPCID, sName);
    if (iQBID)
    {
        string sSQL;
        if (!InnoDB)
        {
            sSQL = "DELETE FROM player_qb_slots WHERE qb_id = "+IntToString(iQBID);
            SQLExecDirect(sSQL);
        }
        sSQL = "DELETE FROM player_qb WHERE id = "+IntToString(iQBID);
        SQLExecDirect(sSQL);
        if (!iSilent)
            SendMessageToPC(oPC, "You delete your "+sName+" quickbar.");
    }
    else
    {
        WarnNoQuickBar(oPC, sName);
        return;
    }
}

void DescribeQuickBar(object oPC, string sName)
{
    if (sName == "")
    {
        WarnNoName(oPC, "describe");
        return;
    }
    string sPCID = IntToString(GetPlayerID(oPC));
    string sEncName = SQLEncodeSpecialChars(sName);
    if (!CheckForExistingQuickBar(sPCID, sEncName))
    {
        WarnNoQuickBar(oPC, sName);
        return;
    }
    string sSQL = "SELECT * FROM player_qb_slots, player_qb "+
    "WHERE player_qb.id = player_qb_slots.qb_id "+
    "AND player_id = "+sPCID+" AND name = '"+sEncName+"' ORDER BY slot";
    SQLExecDirect(sSQL);
    int iFirst = 0;
    int iLastLevel = -1;
    string sDescription;
    while (SQLFetch() == SQL_SUCCESS)
    {
        int iSlot = StringToInt(SQLGetData(2));
        int iType = StringToInt(SQLGetData(3));
        int iSpecialID = StringToInt(SQLGetData(4));
        sDescription += GetSlotString(iSlot)+": "+GetQuickBarType(iType)+" ";
        switch(iType)
        {
            case QUICKBAR_TYPE_ITEM:
            {
                string sQBItem1 = SQLGetData(9);
                object oItem = GetFirstItemInInventory(oPC);
                object oItemFoundOne;
                while (oItem != OBJECT_INVALID)
                {
                    if (GetLocalString(oItem,"qb_equip") == sPCID+"-"+sQBItem1)
                        oItemFoundOne = oItem;
                    oItem = GetNextItemInInventory(oPC);
                } 
                if (oItem == OBJECT_INVALID)
                {
                    int nSlot = 0;
                    for (nSlot=0; nSlot<NUM_INVENTORY_SLOTS; nSlot++)
                    {
                        oItem=GetItemInSlot(nSlot, oPC);
                        if (GetLocalString(oItem,"qb_equip") == sPCID+"-"+sQBItem1)
                            oItemFoundOne = oItem;
                    }
                }
                string sQBItem2 = SQLGetData(10);
                if (sQBItem2 == "")
                {
                    int iPropertyID = iSpecialID-16711680;
                    if (iPropertyID != 255)
                    {
                        int i = 0;
                        itemproperty iploop = GetFirstItemProperty(oItemFoundOne);
                        string sIPName;
                        while (GetIsItemPropertyValid(iploop))
                        {
                            if (i == iPropertyID)
                            {
                                int iIPType = GetItemPropertyType(iploop);
                                sIPName = " "+GetStringByStrRef(StringToInt(Get2DAString("itempropdef", "Name", iIPType)))+ " ";
                                string sSub2DA = Get2DAString("itempropdef", "SubTypeResRef", iIPType);
                                int iSubType = GetItemPropertySubType(iploop);
                                sIPName += GetStringByStrRef(StringToInt(Get2DAString(sSub2DA, "Name", iSubType)));
                                break;
                            }
                            i++;
                            iploop=GetNextItemProperty(oItemFoundOne);
                        }
                        sDescription += GetName(oItemFoundOne)+sIPName;
                    }
                    else
                    {
                        sDescription += GetName(oItemFoundOne);
                    }
                }
                else
                {
                    oItem = GetFirstItemInInventory(oPC);
                    object oItemFoundTwo;
                    while (oItem != OBJECT_INVALID)
                    {
                        if (GetLocalString(oItem,"qb_equip") == sPCID+"-"+sQBItem2)
                            oItemFoundTwo = oItem;
                        oItem = GetNextItemInInventory(oPC);
                    }
                    if (oItem == OBJECT_INVALID)
                    {
                        int nSlot = 0;
                        for (nSlot=0; nSlot<NUM_INVENTORY_SLOTS; nSlot++)
                        {
                            oItem=GetItemInSlot(nSlot, oPC);
                            if (GetLocalString(oItem,"qb_equip") == sPCID+"-"+sQBItem2)
                                oItemFoundTwo = oItem;
                        }
                    }
                    sDescription += GetName(oItemFoundOne)+" / "+GetName(oItemFoundTwo);
                }
                break;
            }
            case QUICKBAR_TYPE_SPELL:
            {
                string sSpellName = GetStringByStrRef(StringToInt(Get2DAString("spells", "Name", iSpecialID)));
                int iMeta = StringToInt(SQLGetData(5));
                if (iMeta > 0)
                {
                    string sMeta = GetMetaMagicName(iMeta);
                    sDescription += sMeta+" "+sSpellName;
                }
                else
                    sDescription += sSpellName;
                break;
            }
            case QUICKBAR_TYPE_SKILL:
            {
                string sSkillName = GetStringByStrRef(StringToInt(Get2DAString("skills", "Name", iSpecialID)));
                sDescription += sSkillName;
                break;
            }
            case QUICKBAR_TYPE_FEAT:
            {
                string sFeatName = GetStringByStrRef(StringToInt(Get2DAString("feat", "FEAT", iSpecialID)));
                if (sFeatName == "Bad Strref")
                {
                    if (iSpecialID == -35061755)
                        sFeatName = "Called Shot: Arm";
                    else if (iSpecialID == -35127291)
                        sFeatName = "Called Shot: Leg";
                    else
                        sFeatName = "Unknown";
                }
                sDescription += sFeatName;
                break;
            }
            case QUICKBAR_TYPE_MODE:
            {
                string sModeName = GetModeName(iSpecialID);
                sDescription += sModeName;
                break;
            }
            case QUICKBAR_TYPE_MACRO:
            {
                string sLabel = SQLGetData(7);
                string sCommand = SQLGetData(8);
                sDescription += sLabel+" "+sCommand;
                break;
            }
            case QUICKBAR_TYPE_HENCH:
            {
                string sCommandName = GetHenchmanCommandName(iSpecialID);
                sDescription += sCommandName;
                break;
            }
            default:
            {
                sDescription += "";
                break;
            }
        }
        sDescription += "\n";
    }
    SendMessageToPC(oPC, sDescription);
}

void ReplaceQuickBar(object oPC, string sName)
{
    if (sName == "")
    {
        WarnNoName(oPC, "replace");
        return;
    }
    string sEncName = SQLEncodeSpecialChars(sName);
    string sPCID = IntToString(GetPlayerID(oPC));

    if (!CheckForExistingQuickBar(sPCID, sEncName))
    {
        WarnNoQuickBar(oPC, sName);
        return;
    }
    DeleteQuickBar(oPC, sName, 1);
    SaveQuickBar(oPC, sName, 1);
    SendMessageToPC(oPC, "You replace your "+sName+" quickbar.");
}

void main()
{
    object oPC = OBJECT_SELF;
    object oMaster = GetMaster(oPC);
    if (oMaster != OBJECT_INVALID)
        SendMessageToPC(oPC, "You can not work with quickbars while possessing.");
    
    string sSubject = GetLocalString(oPC, "last_qb_command");
    
    string sCommand = sSubject;
    string sArg;
    int iSpace = FindSubString(sSubject, " ");
    if(iSpace >= 0)
    {
        sCommand = GetStringLeft(sSubject, iSpace);
        sArg = GetStringRight(sSubject, GetStringLength(sSubject)-iSpace-1);
    }
    else
    {
        sCommand = sSubject;
        sArg = "";
    }
    
    if (GetStringUpperCase(sCommand) == "LIST")
        ListQuickBars(oPC);
    else if (GetStringUpperCase(sCommand) == "SAVE")
        SaveQuickBar(oPC, sArg);
    else if (GetStringUpperCase(sCommand) == "DELETE")
        DeleteQuickBar(oPC, sArg);
    else if (GetStringUpperCase(sCommand) == "DESCRIBE")
        DescribeQuickBar(oPC, sArg);
    else if (GetStringUpperCase(sCommand) == "RESTORE")
        RestoreQuickBar(oPC, sArg);
    else if (GetStringUpperCase(sCommand) == "REPLACE")
        ReplaceQuickBar(oPC, sArg);
    else
    {
        string sDescription = "";
        if (sCommand != "" && GetStringUpperCase(sCommand) != "HELP")
            sDescription = "'"+sCommand+"' is not a valid quickbar command. ";
        sDescription += "Available quickbar commands are:\n";
        sDescription += "save\nrestore\ndelete\nlist\ndescribe\nreplace";
        SendMessageToPC(oPC, sDescription);
    }
}