#include "nwnx_names"
#include "aps_include"
#include "ax_lib_misc_h"

void LoadNamesForPC(object oPC)
{
    InitPlayerNameList(oPC, 1);
    SetNamesEnabled(oPC);

    int nPCID = GetPCId(oPC);
    SQLExec("SELECT pc2, name FROM ax_dynamic_names WHERE pc1="+IntToString(nPCID));
    while(SQLFetch())
    {
        int nPC2ID = StringToInt(SQLGet(1));
        string sName = SQLGet(2);
        object oTmp = GetFirstPC();
        while(GetIsObjectValid(oTmp))
        {
            if(GetPCId(oTmp) == nPC2ID)
                SetDynamicName(oPC, oTmp, sName);
            oTmp = GetNextPC();
        }
    }
    SQLExec("SELECT pc1, name FROM ax_dynamic_names WHERE pc2="+IntToString(nPCID));
    while(SQLFetch())
    {
        int nPC2ID = StringToInt(SQLGet(1));
        string sName = SQLGet(2);
        object oTmp = GetFirstPC();
        while(GetIsObjectValid(oTmp))
        {
            if(GetPCId(oTmp) == nPC2ID)
                SetDynamicName(oTmp, oPC, sName);
            oTmp = GetNextPC();
        }
    }
    object oTmp = GetFirstPC();
    while(GetIsObjectValid(oTmp))
    {
        if(GetIsDM(oTmp))
            DelayCommand(2.0, UpdatePlayerList(oTmp));
        oTmp = GetNextPC();
    }
}

void SetDynamicNameDB(object oPC, object oObject, string sName)
{
    SetDynamicName(oPC, oObject, sName);
    int nPC1ID = GetPCId(oPC);
    int nPC2ID = GetPCId(oObject);
    if(nPC1ID && nPC2ID)
    {
        SQLExec("INSERT INTO ax_dynamic_names (pc1, pc2, name)"+
                "VALUES("+IntToString(nPC1ID)+","+IntToString(nPC2ID)+",'"+SQLEncode(sName)+"') "+
                "ON DUPLICATE KEY UPDATE name='"+SQLEncode(sName)+"'");
    }
}