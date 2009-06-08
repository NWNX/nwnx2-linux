// Name     : NWNX functions
// Purpose  : Various new functions for objects
// Author   : Ingmar Stieger (Papillon)
// Author   : virusman
// Modified : June 04, 2008

// This file is licensed under the terms of the
// GNU GENERAL PUBLIC LICENSE (GPL) Version 2

#include "nwnx_functions_h"

/************************************/
/* Function prototypes              */
/************************************/

// Get the AC of armor oObject
int GetArmorAC(object oObject);

// Set the AC of armor oObject
void SetArmorAC(object oObject, int iAC);

// Set the gold piece value of oObject
void SetGoldPieceValue(object oObject, int iValue);

// Set tag of oObject to sValue
void SetTag(object oObject, string sValue);

// Set the racial type of oObject
// - nRacialType: RACIAL_TYPE_*
void SetRacialType(object oObject, int nRacialType);

// Get the length of oObject's description
// Works with items, placeables, doors and creatures
int GetDescriptionLength(object oObject);

// Get description of oObject
// Works with items, placeables, doors and creatures
string NWNX_GetDescription(object oObject);

// Set description of oObject
// Works with items, placeables, doors and creatures
void NWNX_SetDescription(object oObject, string sNewDescription);

// Get NPC's conversation resource name
string GetConversation(object oObject);

// Returns TRUE if the item is undroppable
int GetUndroppableFlag(object oItem);

// Set the Droppable flag on an item
// - oItem: the item to change
// - bUndroppable: TRUE or FALSE, whether the item is undroppable
void SetUndroppableFlag(object oItem, int bUndroppable);

// Get the weight of an item in tenths of pounds
int GetItemWeight(object oObject);

// Set item weight
// - oObject: the item to change
// - nWeight: new weight in tenths of pounds
// NOTE: Weight is recalculated from baseitems.2da on every player login
void SetItemWeight(object oObject, int nWeight);

// Get event handler for a creature
// - oObject: the target creature
// - nEventId: CREATURE_EVENT_* (see nwnx_functions_h)
string GetEventHandler(object oObject, int nEventId);

// Set event handler for a creature
// - oObject: the target creature
// - nEventId: CREATURE_EVENT_* (see nwnx_functions_h)
// - sScript: script file name
void SetEventHandler(object oObject, int nEventId, string sScript);

// Get Faction ID of an object
int GetFactionID(object oObject);

// Set Faction ID of an object
void SetFactionID(object oObject, int nFaction);

// Returns ground height of the location
float GetGroundHeight(location lLocation);

// Returns TRUE if the position is walkable
int GetIsWalkable(location lLocation);

object GetFirstArea();
object GetNextArea();

// This function doesn't write to a file!!
// It changes a value in memory, so Get2DAString will return old value
void Set2DAString(string s2DA, string sColumn, int nRow, string sValue);

// Set oCreature's movement rate
// - nMovementRate: MOVEMENT_RATE_*
//   (see creaturespeed.2da)
void SetMovementRate(object oCreature, int nMovementRate = MOVEMENT_RATE_DEFAULT);

// Use item on object
void ActionUseItemOnObject(object oItem, object oTarget, int nPropertyNum = 0);

// Use item at location
void ActionUseItemAtLocation(object oItem, location lLocation, int nPropertyNum = 0);

// Get the IP port from which oPlayer has connected.
int GetPCPort(object oPlayer);

// Disconnect oPC from the server with custom message
void BootPCWithMessage(object oPC, int nStrRef);

// Jump to Limbo.
// Object can be returned from Limbo with JumpToLocation/JumpToObject
int JumpToLimbo(object oObject);

// Returns TRUE of svVariable is a valid scriptvar structure
int GetIsVariableValid(struct scriptvar svVariable);

// Get first local variable on oObject
struct scriptvar GetFirstLocalVariable(object oObject);

// Get next local variable on oObject
struct scriptvar GetNextLocalVariable(object oObject);

// Get total count of items possessed by oTarget
int GetItemCount(object oTarget);

// Get item from oTarget's inventory at position nPosition
object GetItemByPosition(object oTarget, int nPosition);

// Convert nObjectID to an object reference
object IntToObject(int nObjectID);

// Change 'Enforce Legal Characters' server setting
void SetELC(int bELC);

// Change 'Item Level Restrictions' server setting
void SetILR(int bILR);

// Restart the server
// Works only with NWNX Reset Plugin installed
void RestartServer();

// For development purposes
void DebugMe(object oObject);

// Dump oObject
// Developers use only
void ObjectDump(object oObject);


/************************************/
/* Implementation                   */
/************************************/

int GetArmorAC(object oObject)
{
    string sAC;
    SetLocalString(oObject, "NWNX!FUNCTIONS!GETARMORAC", "      ");
    sAC = GetLocalString(oObject, "NWNX!FUNCTIONS!GETARMORAC");
    DeleteLocalString(oObject, "NWNX!FUNCTIONS!GETARMORAC");
    return StringToInt(sAC);
}

void SetArmorAC(object oObject, int iAC)
{
    SetLocalString(oObject, "NWNX!FUNCTIONS!SETARMORAC", IntToString(iAC));
    DeleteLocalString(oObject, "NWNX!FUNCTIONS!SETARMORAC");
}

void SetGoldPieceValue(object oObject, int iValue)
{
    SetLocalString(oObject, "NWNX!FUNCTIONS!SETGOLDPIECEVALUE", IntToString(iValue));
    DeleteLocalString(oObject, "NWNX!FUNCTIONS!SETGOLDPIECEVALUE");
}

void SetTag(object oObject, string sValue)
{
    SetLocalString(oObject, "NWNX!FUNCTIONS!SETTAG", sValue);
    DeleteLocalString(oObject, "NWNX!FUNCTIONS!SETTAG");
}

void SetRacialType(object oObject, int nRacialType)
{
    SetLocalString(oObject, "NWNX!FUNCTIONS!SETRACIALTYPE", IntToString(nRacialType));
    DeleteLocalString(oObject, "NWNX!FUNCTIONS!SETRACIALTYPE");
}

int GetDescriptionLength(object oObject)
{
    int nDescLength;
    SetLocalString(oObject, "NWNX!FUNCTIONS!GETDESCRIPTIONLENGTH", "          ");
    nDescLength = StringToInt(GetLocalString(oObject, "NWNX!FUNCTIONS!GETDESCRIPTIONLENGTH"));
    DeleteLocalString(oObject, "NWNX!FUNCTIONS!GETDESCRIPTIONLENGTH");
    return nDescLength;
}

string NWNX_GetDescription(object oObject)
{
    string sDesc;
    SetLocalString(oObject, "NWNX!FUNCTIONS!GETDESCRIPTION", "                                                                                                                                                                                                                                                            ");
    sDesc = GetLocalString(oObject, "NWNX!FUNCTIONS!GETDESCRIPTION");
    DeleteLocalString(oObject, "NWNX!FUNCTIONS!GETDESCRIPTION");
    return sDesc;
}

void NWNX_SetDescription(object oObject, string sNewDescription)
{
    SetLocalString(oObject, "NWNX!FUNCTIONS!SETDESCRIPTION", sNewDescription);
    DeleteLocalString(oObject, "NWNX!FUNCTIONS!SETDESCRIPTION");
}

string GetConversation(object oObject)
{
    string sConv;
    SetLocalString(oObject, "NWNX!FUNCTIONS!GETCONVERSATION", "                 ");
    sConv = GetLocalString(oObject, "NWNX!FUNCTIONS!GETCONVERSATION");
    DeleteLocalString(oObject, "NWNX!FUNCTIONS!GETCONVERSATION");
    return sConv;
}

int GetUndroppableFlag(object oItem)
{
    string sUndroppable;
    SetLocalString(oItem, "NWNX!FUNCTIONS!GETUNDROPPABLE", "      ");
    sUndroppable = GetLocalString(oItem, "NWNX!FUNCTIONS!GETUNDROPPABLE");
    DeleteLocalString(oItem, "NWNX!FUNCTIONS!GETUNDROPPABLE");
    return StringToInt(sUndroppable);
}

void SetUndroppableFlag(object oItem, int bUndroppable)
{
    SetLocalString(oItem, "NWNX!FUNCTIONS!SETUNDROPPABLE", IntToString(bUndroppable));
    DeleteLocalString(oItem, "NWNX!FUNCTIONS!SETUNDROPPABLE");
}

int GetItemWeight(object oObject)
{
    string sWeight;
    SetLocalString(oObject, "NWNX!FUNCTIONS!GETITEMWEIGHT", "      ");
    sWeight = GetLocalString(oObject, "NWNX!FUNCTIONS!GETITEMWEIGHT");
    DeleteLocalString(oObject, "NWNX!FUNCTIONS!GETITEMWEIGHT");
    return StringToInt(sWeight);
}

void SetItemWeight(object oObject, int nWeight)
{
    SetLocalString(oObject, "NWNX!FUNCTIONS!SETITEMWEIGHT", IntToString(nWeight));
    DeleteLocalString(oObject, "NWNX!FUNCTIONS!SETITEMWEIGHT");
}

string GetEventHandler(object oObject, int nEventId)
{
    string sDesc;
    SetLocalString(oObject, "NWNX!FUNCTIONS!GETEVENTHANDLER", IntToString(nEventId)+"                                                                                                                                                                                                                                                            ");
    sDesc = GetLocalString(oObject, "NWNX!FUNCTIONS!GETEVENTHANDLER");
    DeleteLocalString(oObject, "NWNX!FUNCTIONS!GETEVENTHANDLER");
    return sDesc;
}

void SetEventHandler(object oObject, int nEventId, string sScript)
{
    SetLocalString(oObject, "NWNX!FUNCTIONS!SETEVENTHANDLER", IntToString(nEventId)+":"+sScript);
    DeleteLocalString(oObject, "NWNX!FUNCTIONS!SETEVENTHANDLER");
}

int GetFactionID(object oObject)
{
    int nFaction;
    SetLocalString(oObject, "NWNX!FUNCTIONS!GETFACTION", "        ");
    nFaction = StringToInt(GetLocalString(oObject, "NWNX!FUNCTIONS!GETFACTION"));
    DeleteLocalString(oObject, "NWNX!FUNCTIONS!GETFACTION");
    return nFaction;
}

void SetFactionID(object oObject, int nFaction)
{
    SetLocalString(oObject, "NWNX!FUNCTIONS!SETFACTION", IntToString(nFaction));
    DeleteLocalString(oObject, "NWNX!FUNCTIONS!SETFACTION");
}

float GetGroundHeight(location lLocation)
{
    vector vLocation = GetPositionFromLocation(lLocation);
    SetLocalString(GetModule(), "NWNX!FUNCTIONS!GETGROUNDHEIGHT", ObjectToString(GetAreaFromLocation(lLocation))+"¬"+FloatToString(vLocation.x)+"¬"+FloatToString(vLocation.y)+"¬"+FloatToString(vLocation.z));
    return StringToFloat(GetLocalString(GetModule(), "NWNX!FUNCTIONS!GETGROUNDHEIGHT"));
}

int GetIsWalkable(location lLocation)
{
    vector vLocation = GetPositionFromLocation(lLocation);
    SetLocalString(GetModule(), "NWNX!FUNCTIONS!GETISWALKABLE", ObjectToString(GetAreaFromLocation(lLocation))+"¬"+FloatToString(vLocation.x)+"¬"+FloatToString(vLocation.y)+"¬"+FloatToString(vLocation.z));
    return StringToInt(GetLocalString(GetModule(), "NWNX!FUNCTIONS!GETISWALKABLE"));
}

object GetFirstArea()
{
    return GetLocalObject(GetModule(), "NWNX!FUNCTIONS!GET_FIRST_AREA");
}

object GetNextArea()
{
    return GetLocalObject(GetModule(), "NWNX!FUNCTIONS!GET_NEXT_AREA");
}

void Set2DAString(string s2DA, string sColumn, int nRow, string sValue)
{
    SetLocalString(GetModule(), "NWNX!FUNCTIONS!SET2DASTRING", GetStringLowerCase(s2DA)+"¬"+GetStringLowerCase(sColumn)+"¬"+IntToString(nRow)+"¬"+sValue);
}

void SetMovementRate(object oCreature, int nMovementRate)
{
    SetLocalString(oCreature, "NWNX!FUNCTIONS!SET_MOVEMENT_RATE", IntToString(nMovementRate));
    DeleteLocalString(oCreature, "NWNX!FUNCTIONS!SET_MOVEMENT_RATE");
}

void ActionUseItemOnObject(object oItem, object oTarget, int nPropertyNum)
{
    SetLocalString(OBJECT_SELF, "NWNX!FUNCTIONS!ACTION_USE_ITEM", ObjectToString(oItem)+"¬"+ObjectToString(oTarget)+"¬0.0¬0.0¬0.0¬"+IntToString(nPropertyNum));
    DeleteLocalString(OBJECT_SELF, "NWNX!FUNCTIONS!ACTION_USE_ITEM");
}

void ActionUseItemAtLocation(object oItem, location lLocation, int nPropertyNum)
{
    vector vPos = GetPositionFromLocation(lLocation);
    SetLocalString(OBJECT_SELF, "NWNX!FUNCTIONS!ACTION_USE_ITEM", ObjectToString(oItem)+"¬7F000000¬"+FloatToString(vPos.x)+"¬"+FloatToString(vPos.y)+"¬"+FloatToString(vPos.z)+"¬"+IntToString(nPropertyNum));
    DeleteLocalString(OBJECT_SELF, "NWNX!FUNCTIONS!ACTION_USE_ITEM");
}

int GetPCPort(object oPlayer)
{
    SetLocalString(oPlayer, "NWNX!FUNCTIONS!GET_PC_PORT", "              ");
    int nPort = StringToInt(GetLocalString(oPlayer, "NWNX!FUNCTIONS!GET_PC_PORT"));
    DeleteLocalString(oPlayer, "NWNX!FUNCTIONS!GET_PC_PORT");
    return nPort;
}

void BootPCWithMessage(object oPC, int nStrRef)
{
    SetLocalString(oPC, "NWNX!FUNCTIONS!BOOT_PC", IntToString(nStrRef));
}

int JumpToLimbo(object oObject)
{
    SetLocalString(oObject, "NWNX!FUNCTIONS!JUMP_TO_LIMBO", "         ");
    int nResult = StringToInt(GetLocalString(oObject, "NWNX!FUNCTIONS!JUMP_TO_LIMBO"));
    DeleteLocalString(oObject, "NWNX!FUNCTIONS!JUMP_TO_LIMBO");
    return nResult;
}

int GetIsVariableValid(struct scriptvar svVariable)
{
    if(svVariable.Name == "" || svVariable.Type<1 || svVariable.Type>5) return FALSE;
    return TRUE;
}

struct scriptvar GetFirstLocalVariable(object oObject)
{
    struct scriptvar svVariable;
    SetLocalString(oObject, "NWNX!FUNCTIONS!GET_FIRST_LOCALVAR", "                                                            ");
    string sResult = GetLocalString(oObject, "NWNX!FUNCTIONS!GET_FIRST_LOCALVAR");
    DeleteLocalString(oObject, "NWNX!FUNCTIONS!GET_FIRST_LOCALVAR");
    if(sResult == "") return svVariable;
    int nNameDelimiter = FindSubString(sResult, "¬");
    svVariable.Name = GetStringLeft(sResult, nNameDelimiter);
    sResult = GetStringRight(sResult, GetStringLength(sResult)-nNameDelimiter-1);
    int nTypeDelimiter = FindSubString(sResult, "¬");
    svVariable.Type = StringToInt(GetStringLeft(sResult, nTypeDelimiter));
    svVariable.Value = GetStringRight(sResult, GetStringLength(sResult)-nTypeDelimiter-1);
    return svVariable;
}

struct scriptvar GetNextLocalVariable(object oObject)
{
    struct scriptvar svVariable;
    SetLocalString(oObject, "NWNX!FUNCTIONS!GET_NEXT_LOCALVAR", "                                                            ");
    string sResult = GetLocalString(oObject, "NWNX!FUNCTIONS!GET_NEXT_LOCALVAR");
    DeleteLocalString(oObject, "NWNX!FUNCTIONS!GET_NEXT_LOCALVAR");
    if(sResult == "") return svVariable;
    int nNameDelimiter = FindSubString(sResult, "¬");
    svVariable.Name = GetStringLeft(sResult, nNameDelimiter);
    sResult = GetStringRight(sResult, GetStringLength(sResult)-nNameDelimiter-1);
    int nTypeDelimiter = FindSubString(sResult, "¬");
    svVariable.Type = StringToInt(GetStringLeft(sResult, nTypeDelimiter));
    svVariable.Value = GetStringRight(sResult, GetStringLength(sResult)-nTypeDelimiter-1);
    return svVariable;
}

int GetItemCount(object oTarget)
{
    SetLocalString(oTarget, "NWNX!FUNCTIONS!GET_ITEM_COUNT", "              ");
    int nCount = StringToInt(GetLocalString(oTarget, "NWNX!FUNCTIONS!GET_ITEM_COUNT"));
    DeleteLocalString(oTarget, "NWNX!FUNCTIONS!GET_ITEM_COUNT");
    return nCount;
}

object GetItemByPosition(object oTarget, int nPosition)
{
    SetLocalString(oTarget, "NWNX!FUNCTIONS!GET_ITEM_BY_POSITION", IntToString(nPosition));
    DeleteLocalString(oTarget, "NWNX!FUNCTIONS!GET_ITEM_BY_POSITION");
    return GetLocalObject(oTarget, "NWNX!FUNCTIONS!GET_ITEM_BY_POSITION");
}

object IntToObject(int nObjectID)
{
    SetLocalString(GetModule(), "NWNX!FUNCTIONS!INT_TO_OBJECT", IntToString(nObjectID));
    DeleteLocalString(GetModule(), "NWNX!FUNCTIONS!INT_TO_OBJECT");
    return GetLocalObject(GetModule(), "NWNX!FUNCTIONS!INT_TO_OBJECT");
}

void SetELC(int bELC)
{
    SetLocalString(GetModule(), "NWNX!FUNCTIONS!SET_ELC", IntToString(bELC==1));
    DeleteLocalString(GetModule(), "NWNX!FUNCTIONS!SET_ELC");
}

void SetILR(int bILR)
{
    SetLocalString(GetModule(), "NWNX!FUNCTIONS!SET_ILR", IntToString(bILR==1));
    DeleteLocalString(GetModule(), "NWNX!FUNCTIONS!SET_ILR");
}

void DebugMe(object oObject)
{
    SetLocalString(oObject, "NWNX!FUNCTIONS!DEBUGME", "      ");
    DeleteLocalString(oObject, "NWNX!FUNCTIONS!DEBUGME");
}

void ObjectDump(object oObject)
{
    SetLocalString(oObject, "NWNX!FUNCTIONS!OBJDUMP", "      ");
    DeleteLocalString(oObject, "NWNX!FUNCTIONS!OBJDUMP");
}

void RestartServer()
{
    SetLocalString(GetModule(), "NWNX!RESETPLUGIN!SHUTDOWN", "1");
}
