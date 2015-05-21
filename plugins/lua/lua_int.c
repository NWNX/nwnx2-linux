/***************************************************************************
    lua_int.c - Lua interface to nwscript VM.
    (c) 2010 pardik (d.paroli@tiscali.it)

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 ***************************************************************************/

#include <stdlib.h>
#include "FunctionHooks.h"
#include "NWNStructures.h"
#include "nwscript.h"
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

static int luaL_checkboolean(lua_State *L, int narg)
{
    int d = lua_toboolean(L, narg);
    if (d == 0 && !lua_isboolean(L, narg))  /* avoid extra test when d is not 0 */
        luaL_typerror(L, narg, lua_typename(L, LUA_TBOOLEAN));
    return d;
}

static int luaL_optboolean(lua_State *L, int narg, int def)
{
    return luaL_opt(L, luaL_checkboolean, narg, def);
}

static void *luaL_checklightnwndata(lua_State *L, int index, const char *tname)
{
    void *pt;
    pt = lua_touserdata(L, index);
    if (pt == NULL) luaL_typerror(L, index, tname);
    return pt;
}

// Start NWN Functions
static int NWScript_Random(lua_State *L)
{
    int nMaxInteger = luaL_checkint(L, 1);

    StackPushInteger(nMaxInteger);
    VM_ExecuteCommand(0, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_PrintString(lua_State *L)
{
    char *sString = (char *)luaL_checkstring(L, 1);

    StackPushString(sString);
    VM_ExecuteCommand(1, 1);
    return 0;
}

static int NWScript_PrintFloat(lua_State *L)
{
    double fFloat = luaL_checknumber(L, 1);
    int nWidth = luaL_optint(L, 2, 18);
    int nDecimals = luaL_optint(L, 3, 9);

    StackPushInteger(nDecimals);
    StackPushInteger(nWidth);
    StackPushFloat(fFloat);
    VM_ExecuteCommand(2, 3);
    return 0;
}

static int NWScript_FloatToString(lua_State *L)
{
    double fFloat = luaL_checknumber(L, 1);
    int nWidth = luaL_optint(L, 2, 18);
    int nDecimals = luaL_optint(L, 3, 9);

    StackPushInteger(nDecimals);
    StackPushInteger(nWidth);
    StackPushFloat(fFloat);
    VM_ExecuteCommand(3, 3);
    char *sRetVal;
    StackPopString(&sRetVal);
    lua_pushstring(L, sRetVal);
    return 1;
}

static int NWScript_PrintInteger(lua_State *L)
{
    int nInteger = luaL_checkint(L, 1);

    StackPushInteger(nInteger);
    VM_ExecuteCommand(4, 1);
    return 0;
}

static int NWScript_PrintObject(lua_State *L)
{
    dword oObject = luaL_checkint(L, 1);

    StackPushObject(oObject);
    VM_ExecuteCommand(5, 1);
    return 0;
}
/*
static int NWScript_AssignCommand(VALUE oActionSubject, VALUE aActionToAssign)
{
	//ERROR: Undefined variable type: action
	StackPushObject(oActionSubject));
	VM_ExecuteCommand(6, 2);
	return 0;
}

static int NWScript_DelayCommand(VALUE fSeconds, VALUE aActionToDelay)
{
	//ERROR: Undefined variable type: action
	StackPushFloat(luaL_checkint(L, 2));
	VM_ExecuteCommand(7, 2);
	return 0;
}
*/
static int NWScript_ExecuteScript(lua_State *L)
{
    char *sScript = (char *)luaL_checkstring(L, 1);
    dword oTarget = luaL_checkint(L, 2);

    StackPushObject(oTarget);
    StackPushString(sScript);
    VM_ExecuteCommand(8, 2);
    return 0;
}

static int NWScript_ClearAllActions(lua_State *L)
{
    int nClearCombatState = luaL_optboolean(L, 1, FALSE);

    StackPushInteger(nClearCombatState);
    VM_ExecuteCommand(9, 1);
    return 0;
}

static int NWScript_SetFacing(lua_State *L)
{
    double fDirection = luaL_checknumber(L, 1);

    StackPushFloat(fDirection);
    VM_ExecuteCommand(10, 1);
    return 0;
}

static int NWScript_SetCalendar(lua_State *L)
{
    int nYear = luaL_checkint(L, 1);
    int nMonth = luaL_checkint(L, 2);
    int nDay = luaL_checkint(L, 3);

    StackPushInteger(nDay);
    StackPushInteger(nMonth);
    StackPushInteger(nYear);
    VM_ExecuteCommand(11, 3);
    return 0;
}

static int NWScript_SetTime(lua_State *L)
{
    int nHour = luaL_checkint(L, 1);
    int nMinute = luaL_checkint(L, 2);
    int nSecond = luaL_checkint(L, 3);
    int nMillisecond = luaL_checkint(L, 4);

    StackPushInteger(nMillisecond);
    StackPushInteger(nSecond);
    StackPushInteger(nMinute);
    StackPushInteger(nHour);
    VM_ExecuteCommand(12, 4);
    return 0;
}

static int NWScript_GetCalendarYear(lua_State *L)
{
    VM_ExecuteCommand(13, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetCalendarMonth(lua_State *L)
{
    VM_ExecuteCommand(14, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetCalendarDay(lua_State *L)
{
    VM_ExecuteCommand(15, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetTimeHour(lua_State *L)
{
    VM_ExecuteCommand(16, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetTimeMinute(lua_State *L)
{
    VM_ExecuteCommand(17, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetTimeSecond(lua_State *L)
{
    VM_ExecuteCommand(18, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetTimeMillisecond(lua_State *L)
{
    VM_ExecuteCommand(19, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_ActionRandomWalk(lua_State *L)
{
    VM_ExecuteCommand(20, 0);
    return 1;
}

static int NWScript_ActionMoveToLocation(lua_State *L)
{
    void *lDestination = luaL_checklightnwndata(L, 1, LOCATION);
    int bRun = luaL_optboolean(L, 2, FALSE);

    StackPushInteger(bRun);
    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lDestination);
    VM_ExecuteCommand(21, 2);
    return 0;
}

static int NWScript_ActionMoveToObject(lua_State *L)
{
    dword oMoveTo = luaL_checkint(L, 1);
    int bRun = luaL_optboolean(L, 2, FALSE);
    double fRange = luaL_optnumber(L, 3, 1.0);

    StackPushFloat(fRange);
    StackPushInteger(bRun);
    StackPushObject(oMoveTo);
    VM_ExecuteCommand(22, 3);
    return 0;
}

static int NWScript_ActionMoveAwayFromObject(lua_State *L)
{
    dword oFleeFrom = luaL_checkint(L, 1);
    int bRun = luaL_optboolean(L, 2, FALSE);
    double fMoveAwayRange = luaL_optnumber(L, 3, 40.0);

    StackPushFloat(fMoveAwayRange);
    StackPushInteger(bRun);
    StackPushObject(oFleeFrom);
    VM_ExecuteCommand(23, 3);
    return 0;
}

static int NWScript_GetArea(lua_State *L)
{
    dword oTarget = luaL_checkint(L, 1);

    StackPushObject(oTarget);
    VM_ExecuteCommand(24, 1);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetEnteringObject(lua_State *L)
{
    VM_ExecuteCommand(25, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetExitingObject(lua_State *L)
{
    VM_ExecuteCommand(26, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetPosition(lua_State *L)
{
    dword oTarget = luaL_checkint(L, 1);

    StackPushObject(oTarget);
    VM_ExecuteCommand(27, 1);
    Vector *vRetVal = (Vector *)lua_newuserdata(L, sizeof(Vector));
    StackPopVector(vRetVal);
    luaL_getmetatable(L, VECTOR);
    lua_setmetatable(L, -2);
    return 1;
}

static int NWScript_GetFacing(lua_State *L)
{
    dword oTarget = luaL_checkint(L, 1);

    StackPushObject(oTarget);
    VM_ExecuteCommand(28, 1);
    float fRetVal;
    StackPopFloat(&fRetVal);
    lua_pushnumber(L, fRetVal);
    return 1;
}

static int NWScript_GetItemPossessor(lua_State *L)
{
    dword oItem = luaL_checkint(L, 1);

    StackPushObject(oItem);
    VM_ExecuteCommand(29, 1);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetItemPossessedBy(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);
    char *sItemTag = (char *)luaL_checkstring(L, 2);

    StackPushString(sItemTag);
    StackPushObject(oCreature);
    VM_ExecuteCommand(30, 2);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_CreateItemOnObject(lua_State *L)
{
    char *sItemTemplate = (char *)luaL_checkstring(L, 1);
    dword oTarget = luaL_optint(L, 2, OBJECT_SELF);
    int nStackSize = luaL_optint(L, 3, 1);
    char *sNewTag = (char *)luaL_optstring(L,  4, "");

    StackPushString(sNewTag);
    StackPushInteger(nStackSize);
    StackPushObject(oTarget);
    StackPushString(sItemTemplate);
    VM_ExecuteCommand(31, 4);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_ActionEquipItem(lua_State *L)
{
    dword oItem = luaL_checkint(L, 1);
    int nInventorySlot = luaL_checkint(L, 2);

    StackPushInteger(nInventorySlot);
    StackPushObject(oItem);
    VM_ExecuteCommand(32, 2);
    return 0;
}

static int NWScript_ActionUnequipItem(lua_State *L)
{
    dword oItem = luaL_checkint(L, 1);

    StackPushObject(oItem);
    VM_ExecuteCommand(33, 1);
    return 0;
}

static int NWScript_ActionPickUpItem(lua_State *L)
{
    dword oItem = luaL_checkint(L, 1);

    StackPushObject(oItem);
    VM_ExecuteCommand(34, 1);
    return 0;
}

static int NWScript_ActionPutDownItem(lua_State *L)
{
    dword oItem = luaL_checkint(L, 1);

    StackPushObject(oItem);
    VM_ExecuteCommand(35, 1);
    return 0;
}

static int NWScript_GetLastAttacker(lua_State *L)
{
    dword oAttackee = luaL_optint(L, 1, OBJECT_SELF);

    StackPushObject(oAttackee);
    VM_ExecuteCommand(36, 1);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_ActionAttack(lua_State *L)
{
    dword oAttackee = luaL_checkint(L, 1);
    int bPassive = luaL_optboolean(L, 2, FALSE);

    StackPushInteger(bPassive);
    StackPushObject(oAttackee);
    VM_ExecuteCommand(37, 2);
    return 0;
}

static int NWScript_GetNearestCreature(lua_State *L)
{
    int nFirstCriteriaType = luaL_checkint(L, 1);
    int nFirstCriteriaValue = luaL_checkint(L, 2);
    dword oTarget = luaL_optint(L, 3, OBJECT_SELF);
    int nNth = luaL_optint(L, 4, 1);
    int nSecondCriteriaType = luaL_optint(L, 5, -1);
    int nSecondCriteriaValue = luaL_optint(L, 6, -1);
    int nThirdCriteriaType = luaL_optint(L, 7, -1);
    int nThirdCriteriaValue = luaL_optint(L, 8, -1);

    StackPushInteger(nThirdCriteriaValue);
    StackPushInteger(nThirdCriteriaType);
    StackPushInteger(nSecondCriteriaValue);
    StackPushInteger(nSecondCriteriaType);
    StackPushInteger(nNth);
    StackPushObject(oTarget);
    StackPushInteger(nFirstCriteriaValue);
    StackPushInteger(nFirstCriteriaType);
    VM_ExecuteCommand(38, 8);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_ActionSpeakString(lua_State *L)
{
    char *sStringToSpeak = (char *)luaL_checkstring(L, 1);
    int nTalkVolume = luaL_optint(L, 2, TALKVOLUME_TALK);

    StackPushInteger(nTalkVolume);
    StackPushString(sStringToSpeak);
    VM_ExecuteCommand(39, 2);
    return 0;
}

static int NWScript_ActionPlayAnimation(lua_State *L)
{
    int nAnimation = luaL_checkint(L, 1);
    double fSpeed = luaL_optnumber(L, 2, 1.0);
    double fDurationSeconds = luaL_optnumber(L, 3, 1.0);

    StackPushFloat(fDurationSeconds);
    StackPushFloat(fSpeed);
    StackPushInteger(nAnimation);
    VM_ExecuteCommand(40, 3);
    return 0;
}

static int NWScript_GetDistanceToObject(lua_State *L)
{
    dword oObject = luaL_checkint(L, 1);

    StackPushObject(oObject);
    VM_ExecuteCommand(41, 1);
    float fRetVal;
    StackPopFloat(&fRetVal);
    lua_pushnumber(L, fRetVal);
    return 1;
}

static int NWScript_GetIsObjectValid(lua_State *L)
{
    dword oObject = luaL_checkint(L, 1);

    StackPushObject(oObject);
    VM_ExecuteCommand(42, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_ActionOpenDoor(lua_State *L)
{
    dword oDoor = luaL_checkint(L, 1);

    StackPushObject(oDoor);
    VM_ExecuteCommand(43, 1);
    return 0;
}

static int NWScript_ActionCloseDoor(lua_State *L)
{
    dword oDoor = luaL_checkint(L, 1);

    StackPushObject(oDoor);
    VM_ExecuteCommand(44, 1);
    return 0;
}

static int NWScript_SetCameraFacing(lua_State *L)
{
    double fDirection = luaL_checknumber(L, 1);
    double fDistance  = luaL_optnumber(L, 2, -1.0);
    double fPitch  = luaL_optnumber(L, 3, -1.0);
    int nTransitionType = luaL_optint(L, 4, CAMERA_TRANSITION_TYPE_SNAP);

    StackPushInteger(nTransitionType);
    StackPushFloat(fPitch);
    StackPushFloat(fDistance);
    StackPushFloat(fDirection);
    VM_ExecuteCommand(45, 4);
    return 0;
}

static int NWScript_PlaySound(lua_State *L)
{
    char *sSoundName = (char *)luaL_checkstring(L, 1);

    StackPushString(sSoundName);
    VM_ExecuteCommand(46, 1);
    return 0;
}

static int NWScript_GetSpellTargetObject(lua_State *L)
{
    VM_ExecuteCommand(47, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_ActionCastSpellAtObject(lua_State *L)
{
    int nSpell = luaL_checkint(L, 1);
    dword oTarget = luaL_checkint(L, 2);
    int nMetaMagic = luaL_optint(L, 3, METAMAGIC_ANY);
    int bCheat = luaL_optboolean(L, 4, FALSE);
    int nDomainLevel = luaL_optint(L, 5, 0);
    int nProjectilePathType = luaL_optint(L, 6, PROJECTILE_PATH_TYPE_DEFAULT);
    int bInstantSpell = luaL_optboolean(L, 7, FALSE);

    StackPushInteger(bInstantSpell);
    StackPushInteger(nProjectilePathType);
    StackPushInteger(nDomainLevel);
    StackPushInteger(bCheat);
    StackPushInteger(nMetaMagic);
    StackPushObject(oTarget);
    StackPushInteger(nSpell);
    VM_ExecuteCommand(48, 7);
    return 0;
}

static int NWScript_GetCurrentHitPoints(lua_State *L)
{
    dword oObject = luaL_optint(L, 1, OBJECT_SELF);

    StackPushObject(oObject);
    VM_ExecuteCommand(49, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetMaxHitPoints(lua_State *L)
{
    dword oObject = luaL_optint(L, 1, OBJECT_SELF);

    StackPushObject(oObject);
    VM_ExecuteCommand(50, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetLocalInt(lua_State *L)
{
    dword oObject = luaL_checkint(L, 1);
    char *sVarName = (char *)luaL_checkstring(L, 2);

    StackPushString(sVarName);
    StackPushObject(oObject);
    VM_ExecuteCommand(51, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetLocalFloat(lua_State *L)
{
    dword oObject = luaL_checkint(L, 1);
    char *sVarName = (char *)luaL_checkstring(L, 2);

    StackPushString(sVarName);
    StackPushObject(oObject);
    VM_ExecuteCommand(52, 2);
    float fRetVal;
    StackPopFloat(&fRetVal);
    lua_pushnumber(L, fRetVal);
    return 1;
}

static int NWScript_GetLocalString(lua_State *L)
{
    dword oObject = luaL_checkint(L, 1);
    char *sVarName = (char *)luaL_checkstring(L, 2);

    StackPushString(sVarName);
    StackPushObject(oObject);
    VM_ExecuteCommand(53, 2);
    char *sRetVal;
    StackPopString(&sRetVal);
    lua_pushstring(L, sRetVal);
    return 1;
}

static int NWScript_GetLocalObject(lua_State *L)
{
    dword oObject = luaL_checkint(L, 1);
    char *sVarName = (char *)luaL_checkstring(L, 2);

    StackPushString(sVarName);
    StackPushObject(oObject);
    VM_ExecuteCommand(54, 2);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_SetLocalInt(lua_State *L)
{
    dword oObject = luaL_checkint(L, 1);
    char *sVarName = (char *)luaL_checkstring(L, 2);
    int nValue = luaL_checkint(L, 3);

    StackPushInteger(nValue);
    StackPushString(sVarName);
    StackPushObject(oObject);
    VM_ExecuteCommand(55, 3);
    return 0;
}

static int NWScript_SetLocalFloat(lua_State *L)
{
    dword oObject = luaL_checkint(L, 1);
    char *sVarName = (char *)luaL_checkstring(L, 2);
    double fValue = luaL_checknumber(L, 3);

    StackPushFloat(fValue);
    StackPushString(sVarName);
    StackPushObject(oObject);
    VM_ExecuteCommand(56, 3);
    return 0;
}

static int NWScript_SetLocalString(lua_State *L)
{
    dword oObject = luaL_checkint(L, 1);
    char *sVarName = (char *)luaL_checkstring(L, 2);
    char *sValue = (char *)luaL_checkstring(L, 3);

    StackPushString(sValue);
    StackPushString(sVarName);
    StackPushObject(oObject);
    VM_ExecuteCommand(57, 3);
    return 0;
}

static int NWScript_SetLocalObject(lua_State *L)
{
    dword oObject = luaL_checkint(L, 1);
    char *sVarName = (char *)luaL_checkstring(L, 2);
    dword oValue = luaL_checkint(L, 3);

    StackPushObject(oValue);
    StackPushString(sVarName);
    StackPushObject(oObject);
    VM_ExecuteCommand(58, 3);
    return 0;
}

static int NWScript_GetStringLength(lua_State *L)
{
    char *sString = (char *)luaL_checkstring(L, 1);

    StackPushString(sString);
    VM_ExecuteCommand(59, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetStringUpperCase(lua_State *L)
{
    char *sString = (char *)luaL_checkstring(L, 1);

    StackPushString(sString);
    VM_ExecuteCommand(60, 1);
    char *sRetVal;
    StackPopString(&sRetVal);
    lua_pushstring(L, sRetVal);
    return 1;
}

static int NWScript_GetStringLowerCase(lua_State *L)
{
    char *sString = (char *)luaL_checkstring(L, 1);

    StackPushString(sString);
    VM_ExecuteCommand(61, 1);
    char *sRetVal;
    StackPopString(&sRetVal);
    lua_pushstring(L, sRetVal);
    return 1;
}

static int NWScript_GetStringRight(lua_State *L)
{
    char *sString = (char *)luaL_checkstring(L, 1);
    int nCount = luaL_checkint(L, 2);

    StackPushInteger(nCount);
    StackPushString(sString);
    VM_ExecuteCommand(62, 2);
    char *sRetVal;
    StackPopString(&sRetVal);
    lua_pushstring(L, sRetVal);
    return 1;
}

static int NWScript_GetStringLeft(lua_State *L)
{
    char *sString = (char *)luaL_checkstring(L, 1);
    int nCount = luaL_checkint(L, 2);

    StackPushInteger(nCount);
    StackPushString(sString);
    VM_ExecuteCommand(63, 2);
    char *sRetVal;
    StackPopString(&sRetVal);
    lua_pushstring(L, sRetVal);
    return 1;
}

static int NWScript_InsertString(lua_State *L)
{
    char *sDestination = (char *)luaL_checkstring(L, 1);
    char *sString = (char *)luaL_checkstring(L, 2);
    int nPosition = luaL_checkint(L, 3);

    StackPushInteger(nPosition);
    StackPushString(sString);
    StackPushString(sDestination);
    VM_ExecuteCommand(64, 3);
    char *sRetVal;
    StackPopString(&sRetVal);
    lua_pushstring(L, sRetVal);
    return 1;
}

static int NWScript_GetSubString(lua_State *L)
{
    char *sString = (char *)luaL_checkstring(L, 1);
    int nStart = luaL_checkint(L, 2);
    int nCount = luaL_checkint(L, 3);

    StackPushInteger(nCount);
    StackPushInteger(nStart);
    StackPushString(sString);
    VM_ExecuteCommand(65, 3);
    char *sRetVal;
    StackPopString(&sRetVal);
    lua_pushstring(L, sRetVal);
    return 1;
}

static int NWScript_FindSubString(lua_State *L)
{
    char *sString = (char *)luaL_checkstring(L, 1);
    char *sSubString = (char *)luaL_checkstring(L, 2);
    int nStart = luaL_optint(L, 3, 0);

    StackPushInteger(nStart);
    StackPushString(sSubString);
    StackPushString(sString);
    VM_ExecuteCommand(66, 3);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_fabs(lua_State *L)
{
    double fValue = luaL_checknumber(L, 1);

    StackPushFloat(fValue);
    VM_ExecuteCommand(67, 1);
    float fRetVal;
    StackPopFloat(&fRetVal);
    lua_pushnumber(L, fRetVal);
    return 1;
}

static int NWScript_cos(lua_State *L)
{
    double fValue = luaL_checknumber(L, 1);

    StackPushFloat(fValue);
    VM_ExecuteCommand(68, 1);
    float fRetVal;
    StackPopFloat(&fRetVal);
    lua_pushnumber(L, fRetVal);
    return 1;
}

static int NWScript_sin(lua_State *L)
{
    double fValue = luaL_checknumber(L, 1);

    StackPushFloat(fValue);
    VM_ExecuteCommand(69, 1);
    float fRetVal;
    StackPopFloat(&fRetVal);
    lua_pushnumber(L, fRetVal);
    return 1;
}

static int NWScript_tan(lua_State *L)
{
    double fValue = luaL_checknumber(L, 1);

    StackPushFloat(fValue);
    VM_ExecuteCommand(70, 1);
    float fRetVal;
    StackPopFloat(&fRetVal);
    lua_pushnumber(L, fRetVal);
    return 1;
}

static int NWScript_acos(lua_State *L)
{
    double fValue = luaL_checknumber(L, 1);

    StackPushFloat(fValue);
    VM_ExecuteCommand(71, 1);
    float fRetVal;
    StackPopFloat(&fRetVal);
    lua_pushnumber(L, fRetVal);
    return 1;
}

static int NWScript_asin(lua_State *L)
{
    double fValue = luaL_checknumber(L, 1);

    StackPushFloat(fValue);
    VM_ExecuteCommand(72, 1);
    float fRetVal;
    StackPopFloat(&fRetVal);
    lua_pushnumber(L, fRetVal);
    return 1;
}

static int NWScript_atan(lua_State *L)
{
    double fValue = luaL_checknumber(L, 1);

    StackPushFloat(fValue);
    VM_ExecuteCommand(73, 1);
    float fRetVal;
    StackPopFloat(&fRetVal);
    lua_pushnumber(L, fRetVal);
    return 1;
}

static int NWScript_log(lua_State *L)
{
    double fValue = luaL_checknumber(L, 1);

    StackPushFloat(fValue);
    VM_ExecuteCommand(74, 1);
    float fRetVal;
    StackPopFloat(&fRetVal);
    lua_pushnumber(L, fRetVal);
    return 1;
}

static int NWScript_pow(lua_State *L)
{
    double fValue = luaL_checknumber(L, 1);
    double fExponent = luaL_checknumber(L, 2);

    StackPushFloat(fExponent);
    StackPushFloat(fValue);
    VM_ExecuteCommand(75, 2);
    float fRetVal;
    StackPopFloat(&fRetVal);
    lua_pushnumber(L, fRetVal);
    return 1;
}

static int NWScript_sqrt(lua_State *L)
{
    double fValue = luaL_checknumber(L, 1);

    StackPushFloat(fValue);
    VM_ExecuteCommand(76, 1);
    float fRetVal;
    StackPopFloat(&fRetVal);
    lua_pushnumber(L, fRetVal);
    return 1;
}

static int NWScript_abs(lua_State *L)
{
    int nValue = luaL_checkint(L, 1);

    StackPushInteger(nValue);
    VM_ExecuteCommand(77, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_EffectHeal(lua_State *L)
{
    int nDamageToHeal = luaL_checkint(L, 1);

    StackPushInteger(nDamageToHeal);
    VM_ExecuteCommand(78, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_EffectDamage(lua_State *L)
{
    int nDamageAmount = luaL_checkint(L, 1);
    int nDamageType = luaL_optint(L, 2, DAMAGE_TYPE_MAGICAL);
    int nDamagePower = luaL_optint(L, 3, DAMAGE_POWER_NORMAL);

    StackPushInteger(nDamagePower);
    StackPushInteger(nDamageType);
    StackPushInteger(nDamageAmount);
    VM_ExecuteCommand(79, 3);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_EffectAbilityIncrease(lua_State *L)
{
    int nAbilityToIncrease = luaL_checkint(L, 1);
    int nModifyBy = luaL_checkint(L, 2);

    StackPushInteger(nModifyBy);
    StackPushInteger(nAbilityToIncrease);
    VM_ExecuteCommand(80, 2);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_EffectDamageResistance(lua_State *L)
{
    int nDamageType = luaL_checkint(L, 1);
    int nAmount = luaL_checkint(L, 2);
    int nLimit = luaL_optint(L, 3, 0);

    StackPushInteger(nLimit);
    StackPushInteger(nAmount);
    StackPushInteger(nDamageType);
    VM_ExecuteCommand(81, 3);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_EffectResurrection(lua_State *L)
{
    VM_ExecuteCommand(82, 0);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_EffectSummonCreature(lua_State *L)
{
    char *sCreatureResref = (char *)luaL_checkstring(L, 1);
    int nVisualEffectId = luaL_optint(L, 2, VFX_NONE);
    double fDelaySeconds = luaL_optnumber(L, 3, 0.0);
    int nUseAppearAnimation = luaL_optboolean(L, 4, FALSE);

    StackPushInteger(nUseAppearAnimation);
    StackPushFloat(fDelaySeconds);
    StackPushInteger(nVisualEffectId);
    StackPushString(sCreatureResref);
    VM_ExecuteCommand(83, 4);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_GetCasterLevel(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);

    StackPushObject(oCreature);
    VM_ExecuteCommand(84, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetFirstEffect(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);

    StackPushObject(oCreature);
    VM_ExecuteCommand(85, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_GetNextEffect(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);

    StackPushObject(oCreature);
    VM_ExecuteCommand(86, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_RemoveEffect(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);
    void *eEffect = luaL_checklightnwndata(L, 2, EFFECT);

    StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eEffect);
    StackPushObject(oCreature);
    VM_ExecuteCommand(87, 2);
    return 0;
}

static int NWScript_GetIsEffectValid(lua_State *L)
{
    void *eEffect = luaL_checklightnwndata(L, 1, EFFECT);

    StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eEffect);
    VM_ExecuteCommand(88, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_GetEffectDurationType(lua_State *L)
{
    void *eEffect = luaL_checklightnwndata(L, 1, EFFECT);

    StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eEffect);
    VM_ExecuteCommand(89, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetEffectSubType(lua_State *L)
{
    void *eEffect = luaL_checklightnwndata(L, 1, EFFECT);

    StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eEffect);
    VM_ExecuteCommand(90, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetEffectCreator(lua_State *L)
{
    void *eEffect = luaL_checklightnwndata(L, 1, EFFECT);

    StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eEffect);
    VM_ExecuteCommand(91, 1);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_IntToString(lua_State *L)
{
    int nInteger = luaL_checkint(L, 1);

    StackPushInteger(nInteger);
    VM_ExecuteCommand(92, 1);
    char *sRetVal;
    StackPopString(&sRetVal);
    lua_pushstring(L, sRetVal);
    return 1;
}

static int NWScript_GetFirstObjectInArea(lua_State *L)
{
    dword oArea = luaL_optint(L, 1, OBJECT_INVALID);

    StackPushObject(oArea);
    VM_ExecuteCommand(93, 1);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetNextObjectInArea(lua_State *L)
{
    dword oArea = luaL_optint(L, 1, OBJECT_INVALID);

    StackPushObject(oArea);
    VM_ExecuteCommand(94, 1);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_d2(lua_State *L)
{
    int nNumDice = luaL_optint(L, 1, 1);

    StackPushInteger(nNumDice);
    VM_ExecuteCommand(95, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_d3(lua_State *L)
{
    int nNumDice = luaL_optint(L, 1, 1);

    StackPushInteger(nNumDice);
    VM_ExecuteCommand(96, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_d4(lua_State *L)
{
    int nNumDice = luaL_optint(L, 1, 1);

    StackPushInteger(nNumDice);
    VM_ExecuteCommand(97, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_d6(lua_State *L)
{
    int nNumDice = luaL_optint(L, 1, 1);

    StackPushInteger(nNumDice);
    VM_ExecuteCommand(98, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_d8(lua_State *L)
{
    int nNumDice = luaL_optint(L, 1, 1);

    StackPushInteger(nNumDice);
    VM_ExecuteCommand(99, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_d10(lua_State *L)
{
    int nNumDice = luaL_optint(L, 1, 1);

    StackPushInteger(nNumDice);
    VM_ExecuteCommand(100, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_d12(lua_State *L)
{
    int nNumDice = luaL_optint(L, 1, 1);

    StackPushInteger(nNumDice);
    VM_ExecuteCommand(101, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_d20(lua_State *L)
{
    int nNumDice = luaL_optint(L, 1, 1);

    StackPushInteger(nNumDice);
    VM_ExecuteCommand(102, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_d100(lua_State *L)
{
    int nNumDice = luaL_optint(L, 1, 1);

    StackPushInteger(nNumDice);
    VM_ExecuteCommand(103, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_VectorMagnitude(lua_State *L)
{
    Vector *vVector = (Vector *)luaL_checkudata(L, 1, VECTOR);

    StackPushVector(*vVector);
    VM_ExecuteCommand(104, 1);
    float fRetVal;
    StackPopFloat(&fRetVal);
    lua_pushnumber(L, fRetVal);
    return 1;
}

static int NWScript_GetMetaMagicFeat(lua_State *L)
{
    VM_ExecuteCommand(105, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetObjectType(lua_State *L)
{
    dword oTarget = luaL_checkint(L, 1);

    StackPushObject(oTarget);
    VM_ExecuteCommand(106, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetRacialType(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);

    StackPushObject(oCreature);
    VM_ExecuteCommand(107, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_FortitudeSave(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);
    int nDC = luaL_checkint(L, 2);
    int nSaveType = luaL_optint(L, 3, SAVING_THROW_TYPE_NONE);
    dword oSaveVersus = luaL_optint(L, 4, OBJECT_SELF);

    StackPushObject(oSaveVersus);
    StackPushInteger(nSaveType);
    StackPushInteger(nDC);
    StackPushObject(oCreature);
    VM_ExecuteCommand(108, 4);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_ReflexSave(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);
    int nDC = luaL_checkint(L, 2);
    int nSaveType = luaL_optint(L, 3, SAVING_THROW_TYPE_NONE);
    dword oSaveVersus = luaL_optint(L, 4, OBJECT_SELF);

    StackPushObject(oSaveVersus);
    StackPushInteger(nSaveType);
    StackPushInteger(nDC);
    StackPushObject(oCreature);
    VM_ExecuteCommand(109, 4);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_WillSave(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);
    int nDC = luaL_checkint(L, 2);
    int nSaveType = luaL_optint(L, 3, SAVING_THROW_TYPE_NONE);
    dword oSaveVersus = luaL_optint(L, 4, OBJECT_SELF);

    StackPushObject(oSaveVersus);
    StackPushInteger(nSaveType);
    StackPushInteger(nDC);
    StackPushObject(oCreature);
    VM_ExecuteCommand(110, 4);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetSpellSaveDC(lua_State *L)
{
    VM_ExecuteCommand(111, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_MagicalEffect(lua_State *L)
{
    void *eEffect = luaL_checklightnwndata(L, 1, EFFECT);

    StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eEffect);
    VM_ExecuteCommand(112, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_SupernaturalEffect(lua_State *L)
{
    void *eEffect = luaL_checklightnwndata(L, 1, EFFECT);

    StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eEffect);
    VM_ExecuteCommand(113, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ExtraordinaryEffect(lua_State *L)
{
    void *eEffect = luaL_checklightnwndata(L, 1, EFFECT);

    StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eEffect);
    VM_ExecuteCommand(114, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_EffectACIncrease(lua_State *L)
{
    int nValue = luaL_checkint(L, 1);
    int nModifyType = luaL_optint(L, 2, AC_DODGE_BONUS);
    int nDamageType = luaL_optint(L, 3, AC_VS_DAMAGE_TYPE_ALL);

    StackPushInteger(nDamageType);
    StackPushInteger(nModifyType);
    StackPushInteger(nValue);
    VM_ExecuteCommand(115, 3);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_GetAC(lua_State *L)
{
    dword oObject = luaL_checkint(L, 1);
    int nForFutureUse = luaL_optint(L, 2, 0);

    StackPushInteger(nForFutureUse);
    StackPushObject(oObject);
    VM_ExecuteCommand(116, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_EffectSavingThrowIncrease(lua_State *L)
{
    int nSave = luaL_checkint(L, 1);
    int nValue = luaL_checkint(L, 2);
    int nSaveType = luaL_optint(L, 3, SAVING_THROW_TYPE_ALL);

    StackPushInteger(nSaveType);
    StackPushInteger(nValue);
    StackPushInteger(nSave);
    VM_ExecuteCommand(117, 3);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_EffectAttackIncrease(lua_State *L)
{
    int nBonus = luaL_checkint(L, 1);
    int nModifierType = luaL_optint(L, 2, ATTACK_BONUS_MISC);

    StackPushInteger(nModifierType);
    StackPushInteger(nBonus);
    VM_ExecuteCommand(118, 2);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_EffectDamageReduction(lua_State *L)
{
    int nAmount = luaL_checkint(L, 1);
    int nDamagePower = luaL_checkint(L, 2);
    int nLimit = luaL_optint(L, 3, 0);

    StackPushInteger(nLimit);
    StackPushInteger(nDamagePower);
    StackPushInteger(nAmount);
    VM_ExecuteCommand(119, 3);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_EffectDamageIncrease(lua_State *L)
{
    int nBonus = luaL_checkint(L, 1);
    int nDamageType = luaL_optint(L, 2, DAMAGE_TYPE_MAGICAL);

    StackPushInteger(nDamageType);
    StackPushInteger(nBonus);
    VM_ExecuteCommand(120, 2);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_RoundsToSeconds(lua_State *L)
{
    int nRounds = luaL_checkint(L, 1);

    StackPushInteger(nRounds);
    VM_ExecuteCommand(121, 1);
    float fRetVal;
    StackPopFloat(&fRetVal);
    lua_pushnumber(L, fRetVal);
    return 1;
}

static int NWScript_HoursToSeconds(lua_State *L)
{
    int nHours = luaL_checkint(L, 1);

    StackPushInteger(nHours);
    VM_ExecuteCommand(122, 1);
    float fRetVal;
    StackPopFloat(&fRetVal);
    lua_pushnumber(L, fRetVal);
    return 1;
}

static int NWScript_TurnsToSeconds(lua_State *L)
{
    int nTurns = luaL_checkint(L, 1);

    StackPushInteger(nTurns);
    VM_ExecuteCommand(123, 1);
    float fRetVal;
    StackPopFloat(&fRetVal);
    lua_pushnumber(L, fRetVal);
    return 1;
}

static int NWScript_GetLawChaosValue(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);

    StackPushObject(oCreature);
    VM_ExecuteCommand(124, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetGoodEvilValue(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);

    StackPushObject(oCreature);
    VM_ExecuteCommand(125, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetAlignmentLawChaos(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);

    StackPushObject(oCreature);
    VM_ExecuteCommand(126, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetAlignmentGoodEvil(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);

    StackPushObject(oCreature);
    VM_ExecuteCommand(127, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_EffectEntangle(lua_State *L)
{
    VM_ExecuteCommand(130, 0);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_SignalEvent(lua_State *L)
{
    dword oObject = luaL_checkint(L, 1);
    void *eEvent = luaL_checklightnwndata(L, 2, EVENT);
    StackPushEngineStructure(ENGINE_STRUCTURE_EVENT, eEvent);
    StackPushObject(oObject);
    VM_ExecuteCommand(131, 2);
    return 0;
}

static int NWScript_EventUserDefined(lua_State *L)
{
    int nUserDefinedEventNumber = luaL_checkint(L, 1);
    StackPushInteger(nUserDefinedEventNumber);
    VM_ExecuteCommand(132, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EVENT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_EffectDeath(lua_State *L)
{
    int nSpectacularDeath = luaL_optboolean(L, 1, FALSE);
    int nDisplayFeedback = luaL_optboolean(L, 2, TRUE);

    StackPushInteger(nDisplayFeedback);
    StackPushInteger(nSpectacularDeath);
    VM_ExecuteCommand(133, 2);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_EffectKnockdown(lua_State *L)
{
    VM_ExecuteCommand(134, 0);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ActionGiveItem(lua_State *L)
{
    dword oItem = luaL_checkint(L, 1);
    dword oGiveTo = luaL_checkint(L, 2);

    StackPushObject(oGiveTo);
    StackPushObject(oItem);
    VM_ExecuteCommand(135, 2);
    return 0;
}

static int NWScript_ActionTakeItem(lua_State *L)
{
    dword oItem = luaL_checkint(L, 1);
    dword oTakeFrom = luaL_checkint(L, 2);

    StackPushObject(oTakeFrom);
    StackPushObject(oItem);
    VM_ExecuteCommand(136, 2);
    return 0;
}

static int NWScript_VectorNormalize(lua_State *L)
{
    Vector *vVector = (Vector *)luaL_checkudata(L, 1, VECTOR);

    StackPushVector(*vVector);
    VM_ExecuteCommand(137, 1);
    Vector *vRetVal = (Vector *)lua_newuserdata(L, sizeof(Vector));
    StackPopVector(vRetVal);
    luaL_getmetatable(L, VECTOR);
    lua_setmetatable(L, -2);
    return 1;
}

static int NWScript_EffectCurse(lua_State *L)
{
    int nStrMod = luaL_optint(L, 1, 1);
    int nDexMod = luaL_optint(L, 2, 1);
    int nConMod = luaL_optint(L, 3, 1);
    int nIntMod = luaL_optint(L, 4, 1);
    int nWisMod = luaL_optint(L, 5, 1);
    int nChaMod = luaL_optint(L, 6, 1);

    StackPushInteger(nChaMod);
    StackPushInteger(nWisMod);
    StackPushInteger(nIntMod);
    StackPushInteger(nConMod);
    StackPushInteger(nDexMod);
    StackPushInteger(nStrMod);
    VM_ExecuteCommand(138, 6);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_GetAbilityScore(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);
    int nAbilityType = luaL_checkint(L, 2);
    int nBaseAbilityScore = luaL_optboolean(L, 3, FALSE);

    StackPushInteger(nBaseAbilityScore);
    StackPushInteger(nAbilityType);
    StackPushObject(oCreature);
    VM_ExecuteCommand(139, 3);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetIsDead(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);

    StackPushObject(oCreature);
    VM_ExecuteCommand(140, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_PrintVector(lua_State *L)
{
    Vector *vVector = (Vector *)luaL_checkudata(L, 1, VECTOR);
    int bPrepend = luaL_checkboolean(L, 2);

    StackPushInteger(bPrepend);
    StackPushVector(*vVector);
    VM_ExecuteCommand(141, 2);
    return 0;
}

static int NWScript_Vector(lua_State *L)
{
    double x = luaL_optnumber(L, 1, 0.0);
    double y = luaL_optnumber(L, 2, 0.0);
    double z = luaL_optnumber(L, 3, 0.0);

    StackPushFloat(z);
    StackPushFloat(y);
    StackPushFloat(x);
    VM_ExecuteCommand(142, 3);
    Vector *vRetVal = (Vector *)lua_newuserdata(L, sizeof(Vector));
    StackPopVector(vRetVal);
    luaL_getmetatable(L, VECTOR);
    lua_setmetatable(L, -2);
    return 1;
}

static int NWScript_SetFacingPoint(lua_State *L)
{
    Vector *vTarget = (Vector *)luaL_checkudata(L, 1, VECTOR);

    StackPushVector(*vTarget);
    VM_ExecuteCommand(143, 1);
    return 0;
}

static int NWScript_AngleToVector(lua_State *L)
{
    double fAngle = luaL_checknumber(L, 1);

    StackPushFloat(fAngle);
    VM_ExecuteCommand(144, 1);
    Vector *vRetVal = (Vector *)lua_newuserdata(L, sizeof(Vector));
    StackPopVector(vRetVal);
    luaL_getmetatable(L, VECTOR);
    lua_setmetatable(L, -2);
    return 1;
}

static int NWScript_VectorToAngle(lua_State *L)
{
    Vector *vVector = (Vector *)luaL_checkudata(L, 1, VECTOR);

    StackPushVector(*vVector);
    VM_ExecuteCommand(145, 1);
    float fRetVal;
    StackPopFloat(&fRetVal);
    lua_pushnumber(L, fRetVal);
    return 1;
}

static int NWScript_TouchAttackMelee(lua_State *L)
{
    dword oTarget = luaL_checkint(L, 1);
    int bDisplayFeedback = luaL_optboolean(L, 2, TRUE);

    StackPushInteger(bDisplayFeedback);
    StackPushObject(oTarget);
    VM_ExecuteCommand(146, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_TouchAttackRanged(lua_State *L)
{
    dword oTarget = luaL_checkint(L, 1);
    int bDisplayFeedback = luaL_optboolean(L, 2, TRUE);

    StackPushInteger(bDisplayFeedback);
    StackPushObject(oTarget);
    VM_ExecuteCommand(147, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_EffectParalyze(lua_State *L)
{
    VM_ExecuteCommand(148, 0);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_EffectSpellImmunity(lua_State *L)
{
    int nImmunityToSpell = luaL_optint(L, 1, SPELL_ALL_SPELLS);

    StackPushInteger(nImmunityToSpell);
    VM_ExecuteCommand(149, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_EffectDeaf(lua_State *L)
{
    VM_ExecuteCommand(150, 0);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_GetDistanceBetween(lua_State *L)
{
    dword oObjectA = luaL_checkint(L, 1);
    dword oObjectB = luaL_checkint(L, 2);

    StackPushObject(oObjectB);
    StackPushObject(oObjectA);
    VM_ExecuteCommand(151, 2);
    float fRetVal;
    StackPopFloat(&fRetVal);
    lua_pushnumber(L, fRetVal);
    return 1;
}

static int NWScript_SetLocalLocation(lua_State *L)
{
    dword oObject = luaL_checkint(L, 1);
    char *sVarName = (char *)luaL_checkstring(L, 2);
    void *lValue = luaL_checklightnwndata(L, 3, LOCATION);

    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lValue);
    StackPushString(sVarName);
    StackPushObject(oObject);
    VM_ExecuteCommand(152, 3);
    return 0;
}

static int NWScript_GetLocalLocation(lua_State *L)
{
    dword oObject = luaL_checkint(L, 1);
    char *sVarName = (char *)luaL_checkstring(L, 2);

    StackPushString(sVarName);
    StackPushObject(oObject);
    VM_ExecuteCommand(153, 2);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_LOCATION, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_EffectSleep(lua_State *L)
{
    VM_ExecuteCommand(154, 0);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_GetItemInSlot(lua_State *L)
{
    int nInventorySlot = luaL_checkint(L, 1);
    dword oCreature = luaL_optint(L, 2, OBJECT_SELF);

    StackPushObject(oCreature);
    StackPushInteger(nInventorySlot);
    VM_ExecuteCommand(155, 2);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_EffectCharmed(lua_State *L)
{
    VM_ExecuteCommand(156, 0);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_EffectConfused(lua_State *L)
{
    VM_ExecuteCommand(157, 0);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_EffectFrightened(lua_State *L)
{
    VM_ExecuteCommand(158, 0);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_EffectDominated(lua_State *L)
{
    VM_ExecuteCommand(159, 0);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_EffectDazed(lua_State *L)
{
    VM_ExecuteCommand(160, 0);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_EffectStunned(lua_State *L)
{
    VM_ExecuteCommand(161, 0);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_SetCommandable(lua_State *L)
{
    int bCommandable = luaL_checkboolean(L, 1);
    dword oTarget = luaL_optint(L, 2, OBJECT_SELF);

    StackPushObject(oTarget);
    StackPushInteger(bCommandable);
    VM_ExecuteCommand(162, 2);
    return 0;
}

static int NWScript_GetCommandable(lua_State *L)
{
    dword oTarget = luaL_optint(L, 1, OBJECT_SELF);

    StackPushObject(oTarget);
    VM_ExecuteCommand(163, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_EffectRegenerate(lua_State *L)
{
    int nAmount = luaL_checkint(L, 1);
    double fIntervalSeconds = luaL_checknumber(L, 2);

    StackPushFloat(fIntervalSeconds);
    StackPushInteger(nAmount);
    VM_ExecuteCommand(164, 2);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_EffectMovementSpeedIncrease(lua_State *L)
{
    int nPercentChange = luaL_checkint(L, 1);

    StackPushInteger(nPercentChange);
    VM_ExecuteCommand(165, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_GetHitDice(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);

    StackPushObject(oCreature);
    VM_ExecuteCommand(166, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_ActionForceFollowObject(lua_State *L)
{
    dword oFollow = luaL_checkint(L, 1);
    double fFollowDistance = luaL_optnumber(L, 2, 0.0);

    StackPushFloat(fFollowDistance);
    StackPushObject(oFollow);
    VM_ExecuteCommand(167, 2);
    return 0;
}

static int NWScript_GetTag(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);

    StackPushObject(oCreature);
    VM_ExecuteCommand(168, 1);
    char *sRetVal;
    StackPopString(&sRetVal);
    lua_pushstring(L, sRetVal);
    return 1;
}

static int NWScript_ResistSpell(lua_State *L)
{
    dword oCaster = luaL_checkint(L, 1);
    dword oTarget = luaL_checkint(L, 2);

    StackPushObject(oTarget);
    StackPushObject(oCaster);
    VM_ExecuteCommand(169, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetEffectType(lua_State *L)
{
    void *eEffect = luaL_checklightnwndata(L, 1, EFFECT);

    StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eEffect);
    VM_ExecuteCommand(170, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_EffectAreaOfEffect(lua_State *L)
{
    int nAreaEffectId = luaL_checkint(L, 1);
    char *sOnEnterScript = (char *)luaL_optstring(L,  2, "");
    char *sHeartbeatScript = (char *)luaL_optstring(L,  3, "");
    char *sOnExitScript = (char *)luaL_optstring(L,  4, "");

    StackPushString(sOnExitScript);
    StackPushString(sHeartbeatScript);
    StackPushString(sOnEnterScript);
    StackPushInteger(nAreaEffectId);
    VM_ExecuteCommand(171, 4);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_GetFactionEqual(lua_State *L)
{
    dword oFirstObject = luaL_checkint(L, 1);
    dword oSecondObject = luaL_optint(L, 2, OBJECT_SELF);

    StackPushObject(oSecondObject);
    StackPushObject(oFirstObject);
    VM_ExecuteCommand(172, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_ChangeFaction(lua_State *L)
{
    dword oObjectToChangeFaction = luaL_checkint(L, 1);
    dword oMemberOfFactionToJoin = luaL_checkint(L, 2);

    StackPushObject(oMemberOfFactionToJoin);
    StackPushObject(oObjectToChangeFaction);
    VM_ExecuteCommand(173, 2);
    return 0;
}

static int NWScript_GetIsListening(lua_State *L)
{
    dword oObject = luaL_checkint(L, 1);

    StackPushObject(oObject);
    VM_ExecuteCommand(174, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_SetListening(lua_State *L)
{
    dword oObject = luaL_checkint(L, 1);
    int  bValue = luaL_checkboolean(L, 2);

    StackPushInteger(bValue);
    StackPushObject(oObject);
    VM_ExecuteCommand(175, 2);
    return 0;
}

static int NWScript_SetListenPattern(lua_State *L)
{
    dword oObject = luaL_checkboolean(L, 1);
    char *sPattern = (char *)luaL_checkstring(L, 2);
    int nNumber = luaL_optint(L, 3, 0);

    StackPushInteger(nNumber);
    StackPushString(sPattern);
    StackPushObject(oObject);
    VM_ExecuteCommand(176, 3);
    return 0;
}

static int NWScript_TestStringAgainstPattern(lua_State *L)
{
    char *sPattern = (char *)luaL_checkstring(L, 1);
    char *sStringToTest = (char *)luaL_checkstring(L, 2);

    StackPushString(sStringToTest);
    StackPushString(sPattern);
    VM_ExecuteCommand(177, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_GetMatchedSubstring(lua_State *L)
{
    int nString = luaL_checkint(L, 1);

    StackPushInteger(nString);
    VM_ExecuteCommand(178, 1);
    char *sRetVal;
    StackPopString(&sRetVal);
    lua_pushstring(L, sRetVal);
    return 1;
}

static int NWScript_GetMatchedSubstringsCount(lua_State *L)
{
    VM_ExecuteCommand(179, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_EffectVisualEffect(lua_State *L)
{
    int nVisualEffectId = luaL_checkint(L, 1);
    int nMissEffect = luaL_optboolean(L, 2, FALSE);

    StackPushInteger(nMissEffect);
    StackPushInteger(nVisualEffectId);
    VM_ExecuteCommand(180, 2);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_GetFactionWeakestMember(lua_State *L)
{
    dword oFactionMember = luaL_optint(L, 1, OBJECT_SELF);
    int bMustBeVisible = luaL_optboolean(L, 2, TRUE);

    StackPushInteger(bMustBeVisible);
    StackPushObject(oFactionMember);
    VM_ExecuteCommand(181, 2);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetFactionStrongestMember(lua_State *L)
{
    dword oFactionMember = luaL_optint(L, 1, OBJECT_SELF);
    int bMustBeVisible = luaL_optboolean(L, 2, TRUE);

    StackPushInteger(bMustBeVisible);
    StackPushObject(oFactionMember);
    VM_ExecuteCommand(182, 2);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetFactionMostDamagedMember(lua_State *L)
{
    dword oFactionMember = luaL_optint(L, 1, OBJECT_SELF);
    int bMustBeVisible = luaL_optboolean(L, 2, TRUE);

    StackPushInteger(bMustBeVisible);
    StackPushObject(oFactionMember);
    VM_ExecuteCommand(183, 2);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetFactionLeastDamagedMember(lua_State *L)
{
    dword oFactionMember = luaL_optint(L, 1, OBJECT_SELF);
    int bMustBeVisible = luaL_optboolean(L, 2, TRUE);

    StackPushInteger(bMustBeVisible);
    StackPushObject(oFactionMember);
    VM_ExecuteCommand(184, 2);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetFactionGold(lua_State *L)
{
    dword oFactionMember = luaL_checkint(L, 1);

    StackPushObject(oFactionMember);
    VM_ExecuteCommand(185, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetFactionAverageReputation(lua_State *L)
{
    dword oSourceFactionMember = luaL_checkint(L, 1);
    dword oTarget = luaL_checkint(L, 2);

    StackPushObject(oTarget);
    StackPushObject(oSourceFactionMember);
    VM_ExecuteCommand(186, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetFactionAverageGoodEvilAlignment(lua_State *L)
{
    dword oFactionMember = luaL_checkint(L, 1);

    StackPushObject(oFactionMember);
    VM_ExecuteCommand(187, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetFactionAverageLawChaosAlignment(lua_State *L)
{
    dword oFactionMember = luaL_checkint(L, 1);

    StackPushObject(oFactionMember);
    VM_ExecuteCommand(188, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetFactionAverageLevel(lua_State *L)
{
    dword oFactionMember = luaL_checkint(L, 1);

    StackPushObject(oFactionMember);
    VM_ExecuteCommand(189, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetFactionAverageXP(lua_State *L)
{
    dword oFactionMember = luaL_checkint(L, 1);

    StackPushObject(oFactionMember);
    VM_ExecuteCommand(190, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetFactionMostFrequentClass(lua_State *L)
{
    dword oFactionMember = luaL_checkint(L, 1);

    StackPushObject(oFactionMember);
    VM_ExecuteCommand(191, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetFactionWorstAC(lua_State *L)
{
    dword oFactionMember = luaL_optint(L, 1, OBJECT_SELF);
    int bMustBeVisible = luaL_optboolean(L, 2, TRUE);

    StackPushInteger(bMustBeVisible);
    StackPushObject(oFactionMember);
    VM_ExecuteCommand(192, 2);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetFactionBestAC(lua_State *L)
{
    dword oFactionMember = luaL_optint(L, 1, OBJECT_SELF);
    int bMustBeVisible = luaL_optboolean(L, 2, TRUE);

    StackPushInteger(bMustBeVisible);
    StackPushObject(oFactionMember);
    VM_ExecuteCommand(193, 2);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_ActionSit(lua_State *L)
{
    dword oChair = luaL_checkint(L, 1);

    StackPushObject(oChair);
    VM_ExecuteCommand(194, 1);
    return 0;
}

static int NWScript_GetListenPatternNumber(lua_State *L)
{
    VM_ExecuteCommand(195, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_ActionJumpToObject(lua_State *L)
{
    dword oToJumpTo = luaL_checkint(L, 1);
    int bWalkStraightLineToPoint = luaL_optboolean(L, 2, TRUE);

    StackPushInteger(bWalkStraightLineToPoint);
    StackPushObject(oToJumpTo);
    VM_ExecuteCommand(196, 2);
    return 0;
}

static int NWScript_GetWaypointByTag(lua_State *L)
{
    char *sWaypointTag = (char *)luaL_checkstring(L, 1);

    StackPushString(sWaypointTag);
    VM_ExecuteCommand(197, 1);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetTransitionTarget(lua_State *L)
{
    dword oTransition = luaL_checkint(L, 1);

    StackPushObject(oTransition);
    VM_ExecuteCommand(198, 1);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_EffectLinkEffects(lua_State *L)
{
    void *eChildEffect = luaL_checklightnwndata(L, 1, EFFECT);
    void *eParentEffect = luaL_checklightnwndata(L, 2, EFFECT);

    StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eParentEffect);
    StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eChildEffect);
    VM_ExecuteCommand(199, 2);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_GetObjectByTag(lua_State *L)
{
    char *sTag = (char *)luaL_checkstring(L, 1);
    int nNth = luaL_optint(L, 2, 0);

    StackPushInteger(nNth);
    StackPushString(sTag);
    VM_ExecuteCommand(200, 2);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_AdjustAlignment(lua_State *L)
{
    dword oSubject = luaL_checkint(L, 1);
    int nAlignment = luaL_checkint(L, 2);
    int nShift = luaL_checkint(L, 3);
    int bAllPartyMembers = luaL_optboolean(L, 4, TRUE);

    StackPushInteger(bAllPartyMembers);
    StackPushInteger(nShift);
    StackPushInteger(nAlignment);
    StackPushObject(oSubject);
    VM_ExecuteCommand(201, 4);
    return 0;
}

static int NWScript_ActionWait(lua_State *L)
{
    double fSeconds = luaL_checknumber(L, 1);

    StackPushFloat(fSeconds);
    VM_ExecuteCommand(202, 1);
    return 0;
}

static int NWScript_SetAreaTransitionBMP(lua_State *L)
{
    int nPredefinedAreaTransition = luaL_checkint(L, 1);
    char *sCustomAreaTransitionBMP = (char *)luaL_optstring(L, 2, "");

    StackPushString(sCustomAreaTransitionBMP);
    StackPushInteger(nPredefinedAreaTransition);
    VM_ExecuteCommand(203, 2);
    return 0;
}

static int NWScript_ActionStartConversation(lua_State *L)
{
    dword oObjectToConverseWith = luaL_checkint(L, 1);
    char *sDialogResRef = (char *)luaL_optstring(L, 2, "");
    int bPrivateConversation = luaL_optboolean(L, 3, FALSE);
    int bPlayHello = luaL_optboolean(L, 4, TRUE);

    StackPushInteger(bPlayHello);
    StackPushInteger(bPrivateConversation);
    StackPushString(sDialogResRef);
    StackPushObject(oObjectToConverseWith);
    VM_ExecuteCommand(204, 4);
    return 0;
}

static int NWScript_ActionPauseConversation(lua_State *L)
{
    VM_ExecuteCommand(205, 0);
    return 0;
}

static int NWScript_ActionResumeConversation(lua_State *L)
{
    VM_ExecuteCommand(206, 0);
    return 0;
}

static int NWScript_EffectBeam(lua_State *L)
{
    int nBeamVisualEffect = luaL_checkint(L, 1);
    dword oEffector = luaL_checkint(L, 2);
    int nBodyPart = luaL_checkint(L, 3);
    int bMissEffect = luaL_optboolean(L, 4, FALSE);

    StackPushInteger(bMissEffect);
    StackPushInteger(nBodyPart);
    StackPushObject(oEffector);
    StackPushInteger(nBeamVisualEffect);
    VM_ExecuteCommand(207, 4);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_GetReputation(lua_State *L)
{
    dword oSource = luaL_checkint(L, 1);
    dword oTarget = luaL_checkint(L, 2);

    StackPushObject(oTarget);
    StackPushObject(oSource);
    VM_ExecuteCommand(208, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_AdjustReputation(lua_State *L)
{
    dword oTarget = luaL_checkint(L, 1);
    dword oSourceFactionMember = luaL_checkint(L, 2);
    int nAdjustment = luaL_checkint(L, 3);

    StackPushInteger(nAdjustment);
    StackPushObject(oSourceFactionMember);
    StackPushObject(oTarget);
    VM_ExecuteCommand(209, 3);
    return 0;
}

static int NWScript_GetSittingCreature(lua_State *L)
{
    dword oChair = luaL_checkint(L, 1);

    StackPushObject(oChair);
    VM_ExecuteCommand(210, 1);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetGoingToBeAttackedBy(lua_State *L)
{
    dword oTarget = luaL_checkint(L, 1);

    StackPushObject(oTarget);
    VM_ExecuteCommand(211, 1);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_EffectSpellResistanceIncrease(lua_State *L)
{
    int nValue = luaL_checkint(L, 1);

    StackPushInteger(nValue);
    VM_ExecuteCommand(212, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_GetLocation(lua_State *L)
{
    dword oObject = luaL_checkint(L, 1);

    StackPushObject(oObject);
    VM_ExecuteCommand(213, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_LOCATION, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ActionJumpToLocation(lua_State *L)
{
    void *lLocation = luaL_checklightnwndata(L, 1, LOCATION);

    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lLocation);
    VM_ExecuteCommand(214, 1);
    return 0;
}

static int NWScript_Location(lua_State *L)
{
    dword oArea = luaL_checkint(L, 1);
    Vector *vPosition = (Vector *)luaL_checkudata(L, 2, VECTOR);
    double fOrientation = luaL_checknumber(L, 3);

    StackPushFloat(fOrientation);
    StackPushVector(*vPosition);
    StackPushObject(oArea);
    VM_ExecuteCommand(215, 3);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_LOCATION, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ApplyEffectAtLocation(lua_State *L)
{
    int nDurationType = luaL_checkint(L, 1);
    void *eEffect = luaL_checklightnwndata(L, 2, EFFECT);
    void *lLocation = luaL_checklightnwndata(L, 3, LOCATION);
    double fDuration = luaL_optnumber(L, 4, 0.0);

    StackPushFloat(fDuration);
    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lLocation);
    StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eEffect);
    StackPushInteger(nDurationType);
    VM_ExecuteCommand(216, 4);
    return 0;
}

static int NWScript_GetIsPC(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);

    StackPushObject(oCreature);
    VM_ExecuteCommand(217, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_FeetToMeters(lua_State *L)
{
    double fFeet = luaL_checknumber(L, 1);

    StackPushFloat(fFeet);
    VM_ExecuteCommand(218, 1);
    float fRetVal;
    StackPopFloat(&fRetVal);
    lua_pushnumber(L, fRetVal);
    return 1;
}

static int NWScript_YardsToMeters(lua_State *L)
{
    double fYards = luaL_checknumber(L, 1);

    StackPushFloat(fYards);
    VM_ExecuteCommand(219, 1);
    float fRetVal;
    StackPopFloat(&fRetVal);
    lua_pushnumber(L, fRetVal);
    return 1;
}

static int NWScript_ApplyEffectToObject(lua_State *L)
{
    int nDurationType = luaL_checkint(L, 1);
    void *eEffect = luaL_checklightnwndata(L, 2, EFFECT);
    dword oTarget = luaL_checkint(L, 3);
    double fDuration = luaL_optnumber(L, 4, 0.0);

    StackPushFloat(fDuration);
    StackPushObject(oTarget);
    StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eEffect);
    StackPushInteger(nDurationType);
    VM_ExecuteCommand(220, 4);
    return 0;
}

static int NWScript_SpeakString(lua_State *L)
{
    char *sStringToSpeak = (char *)luaL_checkstring(L, 1);
    int nTalkVolume = luaL_optint(L, 2, TALKVOLUME_TALK);

    StackPushInteger(nTalkVolume);
    StackPushString(sStringToSpeak);
    VM_ExecuteCommand(221, 2);
    return 0;
}

static int NWScript_GetSpellTargetLocation(lua_State *L)
{
    VM_ExecuteCommand(222, 0);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_LOCATION, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_GetPositionFromLocation(lua_State *L)
{
    void *lLocation = luaL_checklightnwndata(L, 1, LOCATION);

    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lLocation);
    VM_ExecuteCommand(223, 1);
    Vector *vRetVal = (Vector *)lua_newuserdata(L, sizeof(Vector));
    luaL_getmetatable(L, VECTOR);
    lua_setmetatable(L, -2);
    return 1;
}

static int NWScript_GetAreaFromLocation(lua_State *L)
{
    void *lLocation = luaL_checklightnwndata(L, 1, LOCATION);

    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lLocation);
    VM_ExecuteCommand(224, 1);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetFacingFromLocation(lua_State *L)
{
    void *lLocation = luaL_checklightnwndata(L, 1, LOCATION);

    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lLocation);
    VM_ExecuteCommand(225, 1);
    float fRetVal;
    StackPopFloat(&fRetVal);
    lua_pushnumber(L, fRetVal);
    return 1;
}

static int NWScript_GetNearestCreatureToLocation(lua_State *L)
{
    int nFirstCriteriaType = luaL_checkint(L, 1);
    int nFirstCriteriaValue = luaL_checkint(L, 2);
    void *lLocation = luaL_checklightnwndata(L, 3, LOCATION);
    int nNth = luaL_optint(L, 4, 1);
    int nSecondCriteriaType = luaL_optint(L, 5, -1);
    int nSecondCriteriaValue = luaL_optint(L, 6, -1);
    int nThirdCriteriaType = luaL_optint(L, 7, -1);
    int nThirdCriteriaValue = luaL_optint(L, 8, -1);

    StackPushInteger(nThirdCriteriaValue);
    StackPushInteger(nThirdCriteriaType);
    StackPushInteger(nSecondCriteriaValue);
    StackPushInteger(nSecondCriteriaType);
    StackPushInteger(nNth);
    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lLocation);
    StackPushInteger(nFirstCriteriaValue);
    StackPushInteger(nFirstCriteriaType);
    VM_ExecuteCommand(226, 8);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetNearestObject(lua_State *L)
{
    int nObjectType = luaL_optint(L, 1, OBJECT_TYPE_ALL);
    dword oTarget = luaL_optint(L, 2, OBJECT_SELF);
    int nNth = luaL_optint(L, 3, 1);

    StackPushInteger(nNth);
    StackPushObject(oTarget);
    StackPushInteger(nObjectType);
    VM_ExecuteCommand(227, 3);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetNearestObjectToLocation(lua_State *L)
{
    int nObjectType = luaL_checkint(L, 1);
    void *lLocation = luaL_checklightnwndata(L, 2, LOCATION);
    int nNth = luaL_optint(L, 3, 1);

    StackPushInteger(nNth);
    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lLocation);
    StackPushInteger(nObjectType);
    VM_ExecuteCommand(228, 3);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetNearestObjectByTag(lua_State *L)
{
    char *sTag = (char *)luaL_checkstring(L, 1);
    dword oTarget = luaL_optint(L, 2, OBJECT_SELF);
    int nNth = luaL_optint(L, 3, 1);

    StackPushInteger(nNth);
    StackPushObject(oTarget);
    StackPushString(sTag);
    VM_ExecuteCommand(229, 3);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_IntToFloat(lua_State *L)
{
    int nInteger = luaL_checkint(L, 1);

    StackPushInteger(nInteger);
    VM_ExecuteCommand(230, 1);
    float fRetVal;
    StackPopFloat(&fRetVal);
    lua_pushnumber(L, fRetVal);
    return 1;
}

static int NWScript_FloatToInt(lua_State *L)
{
    double fFloat = luaL_checknumber(L, 1);

    StackPushFloat(fFloat);
    VM_ExecuteCommand(231, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_StringToInt(lua_State *L)
{
    char *sNumber = (char *)luaL_checkstring(L, 1);

    StackPushString(sNumber);
    VM_ExecuteCommand(232, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_StringToFloat(lua_State *L)
{
    char *sNumber = (char *)luaL_checkstring(L, 1);

    StackPushString(sNumber);
    VM_ExecuteCommand(233, 1);
    float fRetVal;
    StackPopFloat(&fRetVal);
    lua_pushnumber(L, fRetVal);
    return 1;
}

static int NWScript_ActionCastSpellAtLocation(lua_State *L)
{
    int nSpell = luaL_checkint(L, 1);
    void *lTargetLocation = luaL_checklightnwndata(L, 2, LOCATION);
    int nMetaMagic = luaL_optint(L, 3, METAMAGIC_ANY);
    int bCheat = luaL_optboolean(L, 4, FALSE);
    int nProjectilePathType = luaL_optint(L, 5, PROJECTILE_PATH_TYPE_DEFAULT);
    int bInstantSpell = luaL_optboolean(L, 6, FALSE);

    StackPushInteger(bInstantSpell);
    StackPushInteger(nProjectilePathType);
    StackPushInteger(bCheat);
    StackPushInteger(nMetaMagic);
    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lTargetLocation);
    StackPushInteger(nSpell);
    VM_ExecuteCommand(234, 6);
    return 0;
}

static int NWScript_GetIsEnemy(lua_State *L)
{
    dword oTarget = luaL_checkint(L, 1);
    dword oSource = luaL_optint(L, 2, OBJECT_SELF);

    StackPushObject(oSource);
    StackPushObject(oTarget);
    VM_ExecuteCommand(235, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_GetIsFriend(lua_State *L)
{
    dword oTarget = luaL_checkint(L, 1);
    dword oSource = luaL_optint(L, 2, OBJECT_SELF);

    StackPushObject(oSource);
    StackPushObject(oTarget);
    VM_ExecuteCommand(236, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_GetIsNeutral(lua_State *L)
{
    dword oTarget = luaL_checkint(L, 1);
    dword oSource = luaL_optint(L, 2, OBJECT_SELF);

    StackPushObject(oSource);
    StackPushObject(oTarget);
    VM_ExecuteCommand(237, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_GetPCSpeaker(lua_State *L)
{
    VM_ExecuteCommand(238, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetStringByStrRef(lua_State *L)
{
    int nStrRef = luaL_checkint(L, 1);
    int nGender = luaL_optint(L, 2, GENDER_MALE);

    StackPushInteger(nGender);
    StackPushInteger(nStrRef);
    VM_ExecuteCommand(239, 2);
    char *sRetVal;
    StackPopString(&sRetVal);
    lua_pushstring(L, sRetVal);
    return 1;
}

static int NWScript_ActionSpeakStringByStrRef(lua_State *L)
{
    int nStrRef = luaL_checkint(L, 1);
    int nTalkVolume = luaL_optint(L, 2, TALKVOLUME_TALK);

    StackPushInteger(nTalkVolume);
    StackPushInteger(nStrRef);
    VM_ExecuteCommand(240, 2);
    return 0;
}

static int NWScript_DestroyObject(lua_State *L)
{
    dword oDestroy = luaL_checkint(L, 1);
    double fDelay = luaL_optnumber(L, 2, 0.0);

    StackPushFloat(fDelay);
    StackPushObject(oDestroy);
    VM_ExecuteCommand(241, 2);
    return 0;
}

static int NWScript_GetModule(lua_State *L)
{
    VM_ExecuteCommand(242, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_CreateObject(lua_State *L)
{
    int nObjectType = luaL_checkint(L, 1);
    char *sTemplate = (char *)luaL_checkstring(L, 2);
    void *lLocation = luaL_checklightnwndata(L, 3, LOCATION);
    int bUseAppearAnimation = luaL_optboolean(L, 4, FALSE);
    char *sNewTag = (char *)luaL_optstring(L, 5, "");

    StackPushString(sNewTag);
    StackPushInteger(bUseAppearAnimation);
    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lLocation);
    StackPushString(sTemplate);
    StackPushInteger(nObjectType);
    VM_ExecuteCommand(243, 5);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_EventSpellCastAt(lua_State *L)
{
    dword oCaster = luaL_checkint(L, 1);
    int nSpell = luaL_checkint(L, 2);
    int bHarmful = luaL_optboolean(L, 3, TRUE);

    StackPushInteger(bHarmful);
    StackPushInteger(nSpell);
    StackPushObject(oCaster);
    VM_ExecuteCommand(244, 3);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EVENT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_GetLastSpellCaster(lua_State *L)
{
    VM_ExecuteCommand(245, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetLastSpell(lua_State *L)
{
    VM_ExecuteCommand(246, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetUserDefinedEventNumber(lua_State *L)
{
    VM_ExecuteCommand(247, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetSpellId(lua_State *L)
{
    VM_ExecuteCommand(248, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_RandomName(lua_State *L)
{
    int nNameType = luaL_optint(L, 1, NAME_FIRST_GENERIC_MALE);

    StackPushInteger(nNameType);
    VM_ExecuteCommand(249, 1);
    char *sRetVal;
    StackPopString(&sRetVal);
    lua_pushstring(L, sRetVal);
    return 1;
}

static int NWScript_EffectPoison(lua_State *L)
{
    int nPoisonType = luaL_checkint(L, 1);

    StackPushInteger(nPoisonType);
    VM_ExecuteCommand(250, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_EffectDisease(lua_State *L)
{
    int nDiseaseType = luaL_checkint(L, 1);

    StackPushInteger(nDiseaseType);
    VM_ExecuteCommand(251, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_EffectSilence(lua_State *L)
{
    VM_ExecuteCommand(252, 0);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_GetName(lua_State *L)
{
    dword oObject = luaL_checkint(L, 1);
    int bOriginalName = luaL_optboolean(L, 2, FALSE);

    StackPushInteger(bOriginalName);
    StackPushObject(oObject);
    VM_ExecuteCommand(253, 2);
    char *sRetVal;
    StackPopString(&sRetVal);
    lua_pushstring(L, sRetVal);
    return 1;
}

static int NWScript_GetLastSpeaker(lua_State *L)
{
    VM_ExecuteCommand(254, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_BeginConversation(lua_State *L)
{
    char *sResRef = (char *)luaL_optstring(L, 1, "");
    int oObjectToDialog = luaL_optint(L, 2, OBJECT_INVALID);

    StackPushObject(oObjectToDialog);
    StackPushString(sResRef);
    VM_ExecuteCommand(255, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetLastPerceived(lua_State *L)
{
    VM_ExecuteCommand(256, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetLastPerceptionHeard(lua_State *L)
{
    VM_ExecuteCommand(257, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetLastPerceptionInaudible(lua_State *L)
{
    VM_ExecuteCommand(258, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetLastPerceptionSeen(lua_State *L)
{
    VM_ExecuteCommand(259, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetLastClosedBy(lua_State *L)
{
    VM_ExecuteCommand(260, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetLastPerceptionVanished(lua_State *L)
{
    VM_ExecuteCommand(261, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetFirstInPersistentObject(lua_State *L)
{
    dword oPersistentObject = luaL_optint(L, 1, OBJECT_SELF);
    int nResidentObjectType = luaL_optint(L, 2, OBJECT_TYPE_CREATURE);
    int nPersistentZone = luaL_optint(L, 3, PERSISTENT_ZONE_ACTIVE);

    StackPushInteger(nPersistentZone);
    StackPushInteger(nResidentObjectType);
    StackPushObject(oPersistentObject);
    VM_ExecuteCommand(262, 3);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetNextInPersistentObject(lua_State *L)
{
    dword oPersistentObject = luaL_optint(L, 1, OBJECT_SELF);
    int nResidentObjectType = luaL_optint(L, 2, OBJECT_TYPE_CREATURE);
    int nPersistentZone = luaL_optint(L, 3, PERSISTENT_ZONE_ACTIVE);

    StackPushInteger(nPersistentZone);
    StackPushInteger(nResidentObjectType);
    StackPushObject(oPersistentObject);
    VM_ExecuteCommand(263, 3);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetAreaOfEffectCreator(lua_State *L)
{
    dword oAreaOfEffectObject = luaL_optint(L, 1, OBJECT_SELF);

    StackPushObject(oAreaOfEffectObject);
    VM_ExecuteCommand(264, 1);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_DeleteLocalInt(lua_State *L)
{
    dword oObject = luaL_checkint(L, 1);
    char *sVarName = (char *)luaL_checkstring(L, 2);

    StackPushString(sVarName);
    StackPushObject(oObject);
    VM_ExecuteCommand(265, 2);
    return 0;
}

static int NWScript_DeleteLocalFloat(lua_State *L)
{
    dword oObject = luaL_checkint(L, 1);
    char *sVarName = (char *)luaL_checkstring(L, 2);

    StackPushString(sVarName);
    StackPushObject(oObject);
    VM_ExecuteCommand(266, 2);
    return 0;
}

static int NWScript_DeleteLocalString(lua_State *L)
{
    dword oObject = luaL_checkint(L, 1);
    char *sVarName = (char *)luaL_checkstring(L, 2);

    StackPushString(sVarName);
    StackPushObject(oObject);
    VM_ExecuteCommand(267, 2);
    return 0;
}

static int NWScript_DeleteLocalObject(lua_State *L)
{
    dword oObject = luaL_checkint(L, 1);
    char *sVarName = (char *)luaL_checkstring(L, 2);

    StackPushString(sVarName);
    StackPushObject(oObject);
    VM_ExecuteCommand(268, 2);
    return 0;
}

static int NWScript_DeleteLocalLocation(lua_State *L)
{
    dword oObject = luaL_checkint(L, 1);
    char *sVarName = (char *)luaL_checkstring(L, 2);

    StackPushString(sVarName);
    StackPushObject(oObject);
    VM_ExecuteCommand(269, 2);
    return 0;
}

static int NWScript_EffectHaste(lua_State *L)
{
    VM_ExecuteCommand(270, 0);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_EffectSlow(lua_State *L)
{
    VM_ExecuteCommand(271, 0);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ObjectToString(lua_State *L)
{
    dword oObject = luaL_checkint(L, 1);

    StackPushObject(oObject);
    VM_ExecuteCommand(272, 1);
    char *sRetVal;
    StackPopString(&sRetVal);
    lua_pushstring(L, sRetVal);
    return 1;
}

static int NWScript_EffectImmunity(lua_State *L)
{
    int nImmunityType = luaL_checkint(L, 1);

    StackPushInteger(nImmunityType);
    VM_ExecuteCommand(273, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_GetIsImmune(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);
    int nImmunityType = luaL_checkint(L, 2);
    dword oVersus = luaL_optint(L, 3, OBJECT_INVALID);

    StackPushObject(oVersus);
    StackPushInteger(nImmunityType);
    StackPushObject(oCreature);
    VM_ExecuteCommand(274, 3);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_EffectDamageImmunityIncrease(lua_State *L)
{
    int nDamageType = luaL_checkint(L, 1);
    int nPercentImmunity = luaL_checkint(L, 2);

    StackPushInteger(nPercentImmunity);
    StackPushInteger(nDamageType);
    VM_ExecuteCommand(275, 2);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_GetEncounterActive(lua_State *L)
{
    dword oEncounter = luaL_optint(L, 1, OBJECT_SELF);

    StackPushObject(oEncounter);
    VM_ExecuteCommand(276, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_SetEncounterActive(lua_State *L)
{
    int nNewValue = luaL_checkboolean(L, 1);
    dword oEncounter = luaL_optint(L, 2, OBJECT_SELF);

    StackPushObject(oEncounter);
    StackPushInteger(nNewValue);
    VM_ExecuteCommand(277, 2);
    return 0;
}

static int NWScript_GetEncounterSpawnsMax(lua_State *L)
{
    dword oEncounter = luaL_optint(L, 1, OBJECT_SELF);

    StackPushObject(oEncounter);
    VM_ExecuteCommand(278, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_SetEncounterSpawnsMax(lua_State *L)
{
    int nNewValue = luaL_checkint(L, 1);
    dword oEncounter = luaL_optint(L, 2, OBJECT_SELF);

    StackPushObject(oEncounter);
    StackPushInteger(nNewValue);
    VM_ExecuteCommand(279, 2);
    return 0;
}

static int NWScript_GetEncounterSpawnsCurrent(lua_State *L)
{
    dword oEncounter = luaL_optint(L, 1, OBJECT_SELF);

    StackPushObject(oEncounter);
    VM_ExecuteCommand(280, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_SetEncounterSpawnsCurrent(lua_State *L)
{
    int nNewValue = luaL_checkint(L, 1);
    dword oEncounter = luaL_optint(L, 2, OBJECT_SELF);

    StackPushObject(oEncounter);
    StackPushInteger(nNewValue);
    VM_ExecuteCommand(281, 2);
    return 0;
}

static int NWScript_GetModuleItemAcquired(lua_State *L)
{
    VM_ExecuteCommand(282, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetModuleItemAcquiredFrom(lua_State *L)
{
    VM_ExecuteCommand(283, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_SetCustomToken(lua_State *L)
{
    int nCustomTokenNumber = luaL_checkint(L, 1);
    char *sTokenValue = (char *)luaL_checkstring(L, 2);

    StackPushString(sTokenValue);
    StackPushInteger(nCustomTokenNumber);
    VM_ExecuteCommand(284, 2);
    return 0;
}

static int NWScript_GetHasFeat(lua_State *L)
{
    int nFeat = luaL_checkint(L, 1);
    dword oCreature = luaL_optint(L, 2, OBJECT_SELF);

    StackPushObject(oCreature);
    StackPushInteger(nFeat);
    VM_ExecuteCommand(285, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_GetHasSkill(lua_State *L)
{
    int nSkill = luaL_checkint(L, 1);
    dword oCreature = luaL_optint(L, 2, OBJECT_SELF);

    StackPushObject(oCreature);
    StackPushInteger(nSkill);
    VM_ExecuteCommand(286, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_ActionUseFeat(lua_State *L)
{
    int nFeat = luaL_checkint(L, 1);
    dword oTarget = luaL_checkint(L, 2);

    StackPushObject(oTarget);
    StackPushInteger(nFeat);
    VM_ExecuteCommand(287, 2);
    return 0;
}

static int NWScript_ActionUseSkill(lua_State *L)
{
    int nSkill = luaL_checkint(L, 1);
    dword oTarget = luaL_checkint(L, 2);
    int nSubSkill = luaL_optint(L, 3, 0);
    dword oItemUsed = luaL_optint(L, 4, OBJECT_INVALID);

    StackPushObject(oItemUsed);
    StackPushInteger(nSubSkill);
    StackPushObject(oTarget);
    StackPushInteger(nSkill);
    VM_ExecuteCommand(288, 4);
    return 0;
}

static int NWScript_GetObjectSeen(lua_State *L)
{
    dword oTarget = luaL_checkint(L, 1);
    dword oSource = luaL_optint(L, 2, OBJECT_SELF);

    StackPushObject(oSource);
    StackPushObject(oTarget);
    VM_ExecuteCommand(289, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_GetObjectHeard(lua_State *L)
{
    dword oTarget = luaL_checkint(L, 1);
    dword oSource = luaL_optint(L, 2, OBJECT_SELF);

    StackPushObject(oSource);
    StackPushObject(oTarget);
    VM_ExecuteCommand(290, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_GetLastPlayerDied(lua_State *L)
{
    VM_ExecuteCommand(291, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetModuleItemLost(lua_State *L)
{
    VM_ExecuteCommand(292, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetModuleItemLostBy(lua_State *L)
{
    VM_ExecuteCommand(293, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}
/*
static int NWScript_ActionDoCommand(VALUE aActionToDo)
{
	//ERROR: Undefined variable type: action
	VM_ExecuteCommand(294, 1);
	return 0;
}
*/
static int NWScript_EventConversation(lua_State *L)
{
    VM_ExecuteCommand(295, 0);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EVENT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_SetEncounterDifficulty(lua_State *L)
{
    int nEncounterDifficulty = luaL_checkint(L, 1);
    dword oEncounter = luaL_optint(L, 2, OBJECT_SELF);

    StackPushObject(oEncounter);
    StackPushInteger(nEncounterDifficulty);
    VM_ExecuteCommand(296, 2);
    return 0;
}

static int NWScript_GetEncounterDifficulty(lua_State *L)
{
    dword oEncounter = luaL_optint(L, 1, OBJECT_SELF);

    StackPushObject(oEncounter);
    VM_ExecuteCommand(297, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetDistanceBetweenLocations(lua_State *L)
{
    void *lLocationA = luaL_checklightnwndata(L, 1, LOCATION);
    void *lLocationB = luaL_checklightnwndata(L, 2, LOCATION);

    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lLocationB);
    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lLocationA);
    VM_ExecuteCommand(298, 2);
    float fRetVal;
    StackPopFloat(&fRetVal);
    lua_pushnumber(L, fRetVal);
    return 1;
}

static int NWScript_GetReflexAdjustedDamage(lua_State *L)
{
    int nDamage = luaL_checkint(L, 1);
    dword oTarget = luaL_checkint(L, 2);
    int nDC = luaL_checkint(L, 3);
    int nSaveType = luaL_optint(L, 4, SAVING_THROW_TYPE_NONE);
    dword oSaveVersus = luaL_optint(L, 5, OBJECT_SELF);

    StackPushObject(oSaveVersus);
    StackPushInteger(nSaveType);
    StackPushInteger(nDC);
    StackPushObject(oTarget);
    StackPushInteger(nDamage);
    VM_ExecuteCommand(299, 5);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_PlayAnimation(lua_State *L)
{
    int nAnimation = luaL_checkint(L, 1);
    double fSpeed = luaL_optnumber(L, 2, 1.0);
    double fSeconds = luaL_optnumber(L, 3, 0.0);

    StackPushFloat(fSeconds);
    StackPushFloat(fSpeed);
    StackPushInteger(nAnimation);
    VM_ExecuteCommand(300, 3);
    return 0;
}

static int NWScript_TalentSpell(lua_State *L)
{
    int nSpell = luaL_checkint(L, 1);

    StackPushInteger(nSpell);
    VM_ExecuteCommand(301, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_TALENT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_TalentFeat(lua_State *L)
{
    int nFeat = luaL_checkint(L, 1);

    StackPushInteger(nFeat);
    VM_ExecuteCommand(302, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_TALENT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_TalentSkill(lua_State *L)
{
    int nSkill = luaL_checkint(L, 1);

    StackPushInteger(nSkill);
    VM_ExecuteCommand(303, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_TALENT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_GetHasSpellEffect(lua_State *L)
{
    int nSpell = luaL_checkint(L, 1);
    dword oObject = luaL_optint(L, 2, OBJECT_SELF);

    StackPushObject(oObject);
    StackPushInteger(nSpell);
    VM_ExecuteCommand(304, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_GetEffectSpellId(lua_State *L)
{
    void *eSpellEffect = luaL_checklightnwndata(L, 1, EFFECT);

    StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eSpellEffect);
    VM_ExecuteCommand(305, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetCreatureHasTalent(lua_State *L)
{
    void *tTalent = luaL_checklightnwndata(L, 1, TALENT);
    dword oCreature = luaL_optint(L, 2, OBJECT_SELF);

    StackPushObject(oCreature);
    StackPushEngineStructure(ENGINE_STRUCTURE_TALENT, tTalent);
    VM_ExecuteCommand(306, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_GetCreatureTalentRandom(lua_State *L)
{
    int nCategory = luaL_checkint(L, 1);
    dword oCreature = luaL_optint(L, 2, OBJECT_SELF);

    StackPushObject(oCreature);
    StackPushInteger(nCategory);
    VM_ExecuteCommand(307, 2);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_TALENT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_GetCreatureTalentBest(lua_State *L)
{
    int nCategory = luaL_checkint(L, 1);
    int nCRMax = luaL_checkint(L, 2);
    dword oCreature = luaL_optint(L, 2, OBJECT_SELF);

    StackPushObject(oCreature);
    StackPushInteger(nCRMax);
    StackPushInteger(nCategory);
    VM_ExecuteCommand(308, 3);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_TALENT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ActionUseTalentOnObject(lua_State *L)
{
    void *tChosenTalent = luaL_checklightnwndata(L, 1, TALENT);
    dword oTarget = luaL_checkint(L, 2);

    StackPushObject(oTarget);
    StackPushEngineStructure(ENGINE_STRUCTURE_TALENT, tChosenTalent);
    VM_ExecuteCommand(309, 2);
    return 0;
}

static int NWScript_ActionUseTalentAtLocation(lua_State *L)
{
    void *tChosenTalent = luaL_checklightnwndata(L, 1, TALENT);
    void *lTargetLocation = luaL_checklightnwndata(L, 2, LOCATION);

    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lTargetLocation);
    StackPushEngineStructure(ENGINE_STRUCTURE_TALENT, tChosenTalent);
    VM_ExecuteCommand(310, 2);
    return 0;
}

static int NWScript_GetGoldPieceValue(lua_State *L)
{
    dword oItem = luaL_checkint(L, 1);

    StackPushObject(oItem);
    VM_ExecuteCommand(311, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetIsPlayableRacialType(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);

    StackPushObject(oCreature);
    VM_ExecuteCommand(312, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_JumpToLocation(lua_State *L)
{
    void *lDestination = luaL_checklightnwndata(L, 1, LOCATION);

    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lDestination);
    VM_ExecuteCommand(313, 1);
    return 0;
}

static int NWScript_EffectTemporaryHitpoints(lua_State *L)
{
    int nHitPoints = luaL_checkint(L, 1);

    StackPushInteger(nHitPoints);
    VM_ExecuteCommand(314, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_GetSkillRank(lua_State *L)
{
    int nSkill = luaL_checkint(L, 1);
    dword oTarget = luaL_optint(L, 2, OBJECT_SELF);
    int nBaseSkillRank = luaL_optboolean(L, 3, FALSE);

    StackPushInteger(nBaseSkillRank);
    StackPushObject(oTarget);
    StackPushInteger(nSkill);
    VM_ExecuteCommand(315, 3);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetAttackTarget(lua_State *L)
{
    dword oCreature = luaL_optint(L, 1, OBJECT_SELF);

    StackPushObject(oCreature);
    VM_ExecuteCommand(316, 1);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetLastAttackType(lua_State *L)
{
    dword oCreature = luaL_optint(L, 1, OBJECT_SELF);

    StackPushObject(oCreature);
    VM_ExecuteCommand(317, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetLastAttackMode(lua_State *L)
{
    dword oCreature = luaL_optint(L, 1, OBJECT_SELF);

    StackPushObject(oCreature);
    VM_ExecuteCommand(318, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetMaster(lua_State *L)
{
    dword oAssociate = luaL_optint(L, 1, OBJECT_SELF);

    StackPushObject(oAssociate);
    VM_ExecuteCommand(319, 1);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetIsInCombat(lua_State *L)
{
    dword oCreature = luaL_optint(L, 1, OBJECT_SELF);

    StackPushObject(oCreature);
    VM_ExecuteCommand(320, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_GetLastAssociateCommand(lua_State *L)
{
    dword oAssociate = luaL_optint(L, 1, OBJECT_SELF);

    StackPushObject(oAssociate);
    VM_ExecuteCommand(321, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GiveGoldToCreature(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);

    int nGP = luaL_checkint(L, 2);
    StackPushInteger(nGP);
    StackPushObject(oCreature);
    VM_ExecuteCommand(322, 2);
    return 0;
}

static int NWScript_SetIsDestroyable(lua_State *L)
{
    int bDestroyable = luaL_checkboolean(L, 1);
    int bRaiseable = luaL_optboolean(L, 2, TRUE);
    int bSelectableWhenDead = luaL_optboolean(L, 3, FALSE);

    StackPushInteger(bSelectableWhenDead);
    StackPushInteger(bRaiseable);
    StackPushInteger(bDestroyable);
    VM_ExecuteCommand(323, 3);
    return 0;
}

static int NWScript_SetLocked(lua_State *L)
{
    dword oTarget = luaL_checkint(L, 1);
    int bLocked = luaL_checkboolean(L, 2);

    StackPushInteger(bLocked);
    StackPushObject(oTarget);
    VM_ExecuteCommand(324, 2);
    return 0;
}

static int NWScript_GetLocked(lua_State *L)
{
    dword oTarget = luaL_checkint(L, 1);

    StackPushObject(oTarget);
    VM_ExecuteCommand(325, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetClickingObject(lua_State *L)
{
    VM_ExecuteCommand(326, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_SetAssociateListenPatterns(lua_State *L)
{
    dword oTarget = luaL_optint(L, 1, OBJECT_SELF);

    StackPushObject(oTarget);
    VM_ExecuteCommand(327, 1);
    return 0;
}

static int NWScript_GetLastWeaponUsed(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);

    StackPushObject(oCreature);
    VM_ExecuteCommand(328, 1);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_ActionInteractObject(lua_State *L)
{
    dword oPlaceable = luaL_checkint(L, 1);

    StackPushObject(oPlaceable);
    VM_ExecuteCommand(329, 1);
    return 0;
}

static int NWScript_GetLastUsedBy(lua_State *L)
{
    VM_ExecuteCommand(330, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetAbilityModifier(lua_State *L)
{
    int nAbility = luaL_checkint(L, 1);
    dword oCreature = luaL_optint(L, 2, OBJECT_SELF);

    StackPushObject(oCreature);
    StackPushInteger(nAbility);
    VM_ExecuteCommand(331, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetIdentified(lua_State *L)
{
    dword oItem = luaL_checkint(L, 1);

    StackPushObject(oItem);
    VM_ExecuteCommand(332, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_SetIdentified(lua_State *L)
{
    dword oItem = luaL_checkint(L, 1);
    int bIdentified = luaL_checkboolean(L, 2);

    StackPushInteger(bIdentified);
    StackPushObject(oItem);
    VM_ExecuteCommand(333, 2);
    return 0;
}

static int NWScript_SummonAnimalCompanion(lua_State *L)
{
    dword oMaster = luaL_optint(L, 1, OBJECT_SELF);

    StackPushObject(oMaster);
    VM_ExecuteCommand(334, 1);
    return 0;
}

static int NWScript_SummonFamiliar(lua_State *L)
{
    dword oMaster = luaL_optint(L, 1, OBJECT_SELF);

    StackPushObject(oMaster);
    VM_ExecuteCommand(335, 1);
    return 0;
}

static int NWScript_GetBlockingDoor(lua_State *L)
{
    VM_ExecuteCommand(336, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetIsDoorActionPossible(lua_State *L)
{
    dword oTargetDoor = luaL_checkint(L, 1);
    int nDoorAction = luaL_checkint(L, 2);

    StackPushInteger(nDoorAction);
    StackPushObject(oTargetDoor);
    VM_ExecuteCommand(337, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_DoDoorAction(lua_State *L)
{
    dword oTargetDoor = luaL_checkint(L, 1);
    int nDoorAction = luaL_checkint(L, 2);

    StackPushInteger(nDoorAction);
    StackPushObject(oTargetDoor);
    VM_ExecuteCommand(338, 2);
    return 0;
}

static int NWScript_GetFirstItemInInventory(lua_State *L)
{
    dword oTarget = luaL_optint(L, 1, OBJECT_SELF);

    StackPushObject(oTarget);
    VM_ExecuteCommand(339, 1);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetNextItemInInventory(lua_State *L)
{
    dword oTarget = luaL_optint(L, 1, OBJECT_SELF);

    StackPushObject(oTarget);
    VM_ExecuteCommand(340, 1);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetClassByPosition(lua_State *L)
{
    int nClassPosition = luaL_checkint(L, 1);
    dword oCreature = luaL_optint(L, 2, OBJECT_SELF);

    StackPushObject(oCreature);
    StackPushInteger(nClassPosition);
    VM_ExecuteCommand(341, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetLevelByPosition(lua_State *L)
{
    int nClassPosition = luaL_checkint(L, 1);
    dword oCreature = luaL_optint(L, 2, OBJECT_SELF);

    StackPushObject(oCreature);
    StackPushInteger(nClassPosition);
    VM_ExecuteCommand(342, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetLevelByClass(lua_State *L)
{
    int nClassType = luaL_checkint(L, 1);
    dword oCreature = luaL_optint(L, 2, OBJECT_SELF);

    StackPushObject(oCreature);
    StackPushInteger(nClassType);
    VM_ExecuteCommand(343, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetDamageDealtByType(lua_State *L)
{
    int nDamageType = luaL_checkint(L, 1);

    StackPushInteger(nDamageType);
    VM_ExecuteCommand(344, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetTotalDamageDealt(lua_State *L)
{
    VM_ExecuteCommand(345, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetLastDamager(lua_State *L)
{
    dword oObject = luaL_optint(L, 1, OBJECT_SELF);

    StackPushObject(oObject);
    VM_ExecuteCommand(346, 1);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetLastDisarmed(lua_State *L)
{
    VM_ExecuteCommand(347, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetLastDisturbed(lua_State *L)
{
    VM_ExecuteCommand(348, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetLastLocked(lua_State *L)
{
    VM_ExecuteCommand(349, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetLastUnlocked(lua_State *L)
{
    VM_ExecuteCommand(350, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_EffectSkillIncrease(lua_State *L)
{
    int nSkill = luaL_checkint(L, 1);
    int nValue = luaL_checkint(L, 2);

    StackPushInteger(nValue);
    StackPushInteger(nSkill);
    VM_ExecuteCommand(351, 2);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_GetInventoryDisturbType(lua_State *L)
{
    VM_ExecuteCommand(352, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetInventoryDisturbItem(lua_State *L)
{
    VM_ExecuteCommand(353, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetHenchman(lua_State *L)
{
    dword oMaster = luaL_optint(L, 1, OBJECT_SELF);
    int nNth = luaL_optint(L, 2, 1);

    StackPushInteger(nNth);
    StackPushObject(oMaster);
    VM_ExecuteCommand(354, 2);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_VersusAlignmentEffect(lua_State *L)
{
    void *eEffect = luaL_checklightnwndata(L, 1, EFFECT);
    int nLawChaos = luaL_optint(L, 2, ALIGNMENT_ALL);
    int nGoodEvil = luaL_optint(L, 3, ALIGNMENT_ALL);

    StackPushInteger(nGoodEvil);
    StackPushInteger(nLawChaos);
    StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eEffect);
    VM_ExecuteCommand(355, 3);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_VersusRacialTypeEffect(lua_State *L)
{
    void *eEffect = luaL_checklightnwndata(L, 1, EFFECT);
    int nRacialType = luaL_checkint(L, 2);

    StackPushInteger(nRacialType);
    StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eEffect);
    VM_ExecuteCommand(356, 2);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_VersusTrapEffect(lua_State *L)
{
    void *eEffect = luaL_checklightnwndata(L, 1, EFFECT);

    StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eEffect);
    VM_ExecuteCommand(357, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_GetGender(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);

    StackPushObject(oCreature);
    VM_ExecuteCommand(358, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetIsTalentValid(lua_State *L)
{
    void *tTalent = luaL_checklightnwndata(L, 1, TALENT);

    StackPushEngineStructure(ENGINE_STRUCTURE_TALENT, tTalent);
    VM_ExecuteCommand(359, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_ActionMoveAwayFromLocation(lua_State *L)
{
    void *lMoveAwayFrom = luaL_checklightnwndata(L, 1, LOCATION);
    int bRun = luaL_optboolean(L, 2, FALSE);
    double fMoveAwayRange = luaL_optnumber(L, 3, 40.0);

    StackPushFloat(fMoveAwayRange);
    StackPushInteger(bRun);
    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lMoveAwayFrom);
    VM_ExecuteCommand(360, 3);
    return 0;
}

static int NWScript_GetAttemptedAttackTarget(lua_State *L)
{
    VM_ExecuteCommand(361, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetTypeFromTalent(lua_State *L)
{
    void *tTalent = luaL_checklightnwndata(L, 1, TALENT);

    StackPushEngineStructure(ENGINE_STRUCTURE_TALENT, tTalent);
    VM_ExecuteCommand(362, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetIdFromTalent(lua_State *L)
{
    void *tTalent = luaL_checklightnwndata(L, 1, TALENT);

    StackPushEngineStructure(ENGINE_STRUCTURE_TALENT, tTalent);
    VM_ExecuteCommand(363, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetAssociate(lua_State *L)
{
    int nAssociateType = luaL_checkint(L, 1);
    dword oMaster = luaL_optint(L, 2, OBJECT_SELF);
    int nTh = luaL_optint(L, 3, 1);

    StackPushInteger(nTh);
    StackPushObject(oMaster);
    StackPushInteger(nAssociateType);
    VM_ExecuteCommand(364, 3);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_AddHenchman(lua_State *L)
{
    dword oMaster = luaL_checkint(L, 1);
    dword oHenchman = luaL_optint(L, 2, OBJECT_SELF);

    StackPushObject(oHenchman);
    StackPushObject(oMaster);
    VM_ExecuteCommand(365, 2);
    return 0;
}

static int NWScript_RemoveHenchman(lua_State *L)
{
    dword oMaster = luaL_checkint(L, 1);
    dword oHenchman = luaL_optint(L, 2, OBJECT_SELF);

    StackPushObject(oHenchman);
    StackPushObject(oMaster);
    VM_ExecuteCommand(366, 2);
    return 0;
}

static int NWScript_AddJournalQuestEntry(lua_State *L)
{
    char *szPlotID = (char *)luaL_checkstring(L, 1);
    int nState = luaL_checkint(L, 2);
    dword oCreature = luaL_checkint(L, 3);
    int bAllPartyMembers = luaL_optboolean(L, 4, TRUE);
    int bAllPlayers = luaL_optboolean(L, 5, FALSE);
    int bAllowOverrideHigher = luaL_optboolean(L, 6, FALSE);

    StackPushInteger(bAllowOverrideHigher);
    StackPushInteger(bAllPlayers);
    StackPushInteger(bAllPartyMembers);
    StackPushObject(oCreature);
    StackPushInteger(nState);
    StackPushString(szPlotID);
    VM_ExecuteCommand(367, 6);
    return 0;
}

static int NWScript_RemoveJournalQuestEntry(lua_State *L)
{
    char *szPlotID = (char *)luaL_checkstring(L, 1);
    dword oCreature = luaL_checkint(L, 2);
    int bAllPartyMembers = luaL_optboolean(L, 3, TRUE);
    int bAllPlayers = luaL_optboolean(L, 4, FALSE);

    StackPushInteger(bAllPlayers);
    StackPushInteger(bAllPartyMembers);
    StackPushObject(oCreature);
    StackPushString(szPlotID);
    VM_ExecuteCommand(368, 4);
    return 0;
}

static int NWScript_GetPCPublicCDKey(lua_State *L)
{
    dword oPlayer = luaL_checkint(L, 1);
    int nSinglePlayerCDKey = luaL_optboolean(L, 2, FALSE);

    StackPushInteger(nSinglePlayerCDKey);
    StackPushObject(oPlayer);
    VM_ExecuteCommand(369, 2);
    char *sRetVal;
    StackPopString(&sRetVal);
    lua_pushstring(L, sRetVal);
    return 1;
}

static int NWScript_GetPCIPAddress(lua_State *L)
{
    dword oPlayer = luaL_checkint(L, 1);

    StackPushObject(oPlayer);
    VM_ExecuteCommand(370, 1);
    char *sRetVal;
    StackPopString(&sRetVal);
    lua_pushstring(L, sRetVal);
    return 1;
}

static int NWScript_GetPCPlayerName(lua_State *L)
{
    dword oPlayer = luaL_checkint(L, 1);

    StackPushObject(oPlayer);
    VM_ExecuteCommand(371, 1);
    char *sRetVal;
    StackPopString(&sRetVal);
    lua_pushstring(L, sRetVal);
    return 1;
}

static int NWScript_SetPCLike(lua_State *L)
{
    dword oPlayer = luaL_checkint(L, 1);
    dword oTarget = luaL_checkint(L, 2);

    StackPushObject(oTarget);
    StackPushObject(oPlayer);
    VM_ExecuteCommand(372, 2);
    return 0;
}

static int NWScript_SetPCDislike(lua_State *L)
{
    dword oPlayer = luaL_checkint(L, 1);
    dword oTarget = luaL_checkint(L, 2);

    StackPushObject(oTarget);
    StackPushObject(oPlayer);
    VM_ExecuteCommand(373, 2);
    return 0;
}

static int NWScript_SendMessageToPC(lua_State *L)
{
    dword oPlayer = luaL_checkint(L, 1);
    char *sMessage = (char *)luaL_checkstring(L, 2);

    StackPushString(sMessage);
    StackPushObject(oPlayer);
    VM_ExecuteCommand(374, 2);
    return 0;
}

static int NWScript_GetAttemptedSpellTarget(lua_State *L)
{
    VM_ExecuteCommand(375, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetLastOpenedBy(lua_State *L)
{
    VM_ExecuteCommand(376, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetHasSpell(lua_State *L)
{
    int nSpell = luaL_checkint(L, 1);
    dword oCreature = luaL_optint(L, 2, OBJECT_SELF);

    StackPushObject(oCreature);
    StackPushInteger(nSpell);
    VM_ExecuteCommand(377, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_OpenStore(lua_State *L)
{
    dword oStore = luaL_checkint(L, 1);
    dword oPC = luaL_checkint(L, 2);
    int nBonusMarkUp = luaL_optint(L, 3, 0);
    int nBonusMarkDown = luaL_optint(L, 4, 0);

    StackPushInteger(nBonusMarkDown);
    StackPushInteger(nBonusMarkUp);
    StackPushObject(oPC);
    StackPushObject(oStore);
    VM_ExecuteCommand(378, 4);
    return 0;
}

static int NWScript_EffectTurned(lua_State *L)
{
    VM_ExecuteCommand(379, 0);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_GetFirstFactionMember(lua_State *L)
{
    dword oMemberOfFaction = luaL_checkint(L, 1);
    int bPCOnly = luaL_optboolean(L, 2, TRUE);

    StackPushInteger(bPCOnly);
    StackPushObject(oMemberOfFaction);
    VM_ExecuteCommand(380, 2);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetNextFactionMember(lua_State *L)
{
    dword oMemberOfFaction = luaL_checkint(L, 1);
    int bPCOnly = luaL_optboolean(L, 2, TRUE);

    StackPushInteger(bPCOnly);
    StackPushObject(oMemberOfFaction);
    VM_ExecuteCommand(381, 2);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_ActionForceMoveToLocation(lua_State *L)
{
    void *lDestination = luaL_checklightnwndata(L, 1, LOCATION);
    int bRun = luaL_optboolean(L, 2, FALSE);
    double fTimeout = luaL_optnumber(L, 3, 30.0);

    StackPushFloat(fTimeout);
    StackPushInteger(bRun);
    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lDestination);
    VM_ExecuteCommand(382, 3);
    return 0;
}

static int NWScript_ActionForceMoveToObject(lua_State *L)
{
    dword oMoveTo = luaL_checkint(L, 1);
    int bRun = luaL_optboolean(L, 2, FALSE);
    double fRange = luaL_optnumber(L, 3, 1.0);
    double fTimeout = luaL_optnumber(L, 4, 30.0);

    StackPushFloat(fTimeout);
    StackPushFloat(fRange);
    StackPushInteger(bRun);
    StackPushObject(oMoveTo);
    VM_ExecuteCommand(383, 4);
    return 0;
}

static int NWScript_GetJournalQuestExperience(lua_State *L)
{
    char *szPlotID = (char *)luaL_checkstring(L, 1);

    StackPushString(szPlotID);
    VM_ExecuteCommand(384, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_JumpToObject(lua_State *L)
{
    dword oToJumpTo = luaL_checkint(L, 1);
    int nWalkStraightLineToPoint = luaL_optint(L, 2, 1);

    StackPushInteger(nWalkStraightLineToPoint);
    StackPushObject(oToJumpTo);
    VM_ExecuteCommand(385, 2);
    return 0;
}

static int NWScript_SetMapPinEnabled(lua_State *L)
{
    dword oMapPin = luaL_checkint(L, 1);
    int nEnabled = luaL_checkboolean(L, 2);

    StackPushInteger(nEnabled);
    StackPushObject(oMapPin);
    VM_ExecuteCommand(386, 2);
    return 0;
}

static int NWScript_EffectHitPointChangeWhenDying(lua_State *L)
{
    double fHitPointChangePerRound = luaL_checknumber(L, 1);

    StackPushFloat(fHitPointChangePerRound);
    VM_ExecuteCommand(387, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_PopUpGUIPanel(lua_State *L)
{
    dword oPC = luaL_checkint(L, 1);
    int nGUIPanel = luaL_checkint(L, 2);

    StackPushInteger(nGUIPanel);
    StackPushObject(oPC);
    VM_ExecuteCommand(388, 2);
    return 0;
}

static int NWScript_ClearPersonalReputation(lua_State *L)
{
    dword oTarget = luaL_checkint(L, 1);
    dword oSource = luaL_optint(L, 2, OBJECT_SELF);

    StackPushObject(oSource);
    StackPushObject(oTarget);
    VM_ExecuteCommand(389, 2);
    return 0;
}

static int NWScript_SetIsTemporaryFriend(lua_State *L)
{
    dword oTarget = luaL_checkint(L, 1);
    dword oSource = luaL_optint(L, 2, OBJECT_SELF);
    int bDecays = luaL_optboolean(L, 3, FALSE);
    double fDurationInSeconds = luaL_optnumber(L, 4, 180.0);

    StackPushFloat(fDurationInSeconds);
    StackPushInteger(bDecays);
    StackPushObject(oSource);
    StackPushObject(oTarget);
    VM_ExecuteCommand(390, 4);
    return 0;
}

static int NWScript_SetIsTemporaryEnemy(lua_State *L)
{
    dword oTarget = luaL_checkint(L, 1);
    dword oSource = luaL_optint(L, 2, OBJECT_SELF);
    int bDecays = luaL_optboolean(L, 3, FALSE);
    double fDurationInSeconds = luaL_optnumber(L, 4, 180.0);

    StackPushFloat(fDurationInSeconds);
    StackPushInteger(bDecays);
    StackPushObject(oSource);
    StackPushObject(oTarget);
    VM_ExecuteCommand(391, 4);
    return 0;
}

static int NWScript_SetIsTemporaryNeutral(lua_State *L)
{
    dword oTarget = luaL_checkint(L, 1);
    dword oSource = luaL_optint(L, 2, OBJECT_SELF);
    int bDecays = luaL_optboolean(L, 3, FALSE);
    double fDurationInSeconds = luaL_optnumber(L, 4, 180.0);

    StackPushFloat(fDurationInSeconds);
    StackPushInteger(bDecays);
    StackPushObject(oSource);
    StackPushObject(oTarget);
    VM_ExecuteCommand(392, 4);
    return 0;
}

static int NWScript_GiveXPToCreature(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);
    int nXpAmount = luaL_checkint(L, 2);

    StackPushInteger(nXpAmount);
    StackPushObject(oCreature);
    VM_ExecuteCommand(393, 2);
    return 0;
}

static int NWScript_SetXP(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);
    int nXpAmount = luaL_checkint(L, 2);

    StackPushInteger(nXpAmount);
    StackPushObject(oCreature);
    VM_ExecuteCommand(394, 2);
    return 0;
}

static int NWScript_GetXP(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);

    StackPushObject(oCreature);
    VM_ExecuteCommand(395, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_IntToHexString(lua_State *L)
{
    int nInteger = luaL_checkint(L, 1);

    StackPushInteger(nInteger);
    VM_ExecuteCommand(396, 1);
    char *sRetVal;
    StackPopString(&sRetVal);
    lua_pushstring(L, sRetVal);
    return 1;
}

static int NWScript_GetBaseItemType(lua_State *L)
{
    dword oItem = luaL_checkint(L, 1);

    StackPushObject(oItem);
    VM_ExecuteCommand(397, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetItemHasItemProperty(lua_State *L)
{
    dword oItem = luaL_checkint(L, 1);
    int nProperty = luaL_checkint(L, 2);

    StackPushInteger(nProperty);
    StackPushObject(oItem);
    VM_ExecuteCommand(398, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_ActionEquipMostDamagingMelee(lua_State *L)
{
    dword oVersus = luaL_optint(L, 1, OBJECT_INVALID);
    int bOffHand = luaL_optboolean(L, 2, FALSE);

    StackPushInteger(bOffHand);
    StackPushObject(oVersus);
    VM_ExecuteCommand(399, 2);
    return 0;
}

static int NWScript_ActionEquipMostDamagingRanged(lua_State *L)
{
    dword oVersus = luaL_optint(L, 1, OBJECT_INVALID);

    StackPushObject(oVersus);
    VM_ExecuteCommand(400, 1);
    return 0;
}

static int NWScript_GetItemACValue(lua_State *L)
{
    dword oItem = luaL_checkint(L, 1);

    StackPushObject(oItem);
    VM_ExecuteCommand(401, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_ActionRest(lua_State *L)
{
    int bCreatureToEnemyLineOfSightCheck = luaL_optboolean(L, 1, FALSE);

    StackPushInteger(bCreatureToEnemyLineOfSightCheck);
    VM_ExecuteCommand(402, 1);
    return 0;
}

static int NWScript_ExploreAreaForPlayer(lua_State *L)
{
    dword oArea = luaL_checkint(L, 1);
    dword oPlayer = luaL_checkint(L, 2);
    int bExplored = luaL_optboolean(L, 3, TRUE);

    StackPushInteger(bExplored);
    StackPushObject(oPlayer);
    StackPushObject(oArea);
    VM_ExecuteCommand(403, 3);
    return 0;
}

static int NWScript_ActionEquipMostEffectiveArmor(lua_State *L)
{
    VM_ExecuteCommand(404, 0);
    return 0;
}

static int NWScript_GetIsDay(lua_State *L)
{
    VM_ExecuteCommand(405, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_GetIsNight(lua_State *L)
{
    VM_ExecuteCommand(406, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_GetIsDawn(lua_State *L)
{
    VM_ExecuteCommand(407, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_GetIsDusk(lua_State *L)
{
    VM_ExecuteCommand(408, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_GetIsEncounterCreature(lua_State *L)
{
    dword oCreature = luaL_optint(L, 1, OBJECT_SELF);

    StackPushObject(oCreature);
    VM_ExecuteCommand(409, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_GetLastPlayerDying(lua_State *L)
{
    VM_ExecuteCommand(410, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetStartingLocation(lua_State *L)
{
    VM_ExecuteCommand(411, 0);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_LOCATION, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ChangeToStandardFaction(lua_State *L)
{
    dword oCreatureToChange = luaL_checkint(L, 1);
    int nStandardFaction = luaL_checkint(L, 2);

    StackPushInteger(nStandardFaction);
    StackPushObject(oCreatureToChange);
    VM_ExecuteCommand(412, 2);
    return 0;
}

static int NWScript_SoundObjectPlay(lua_State *L)
{
    dword oSound = luaL_checkint(L, 1);

    StackPushObject(oSound);
    VM_ExecuteCommand(413, 1);
    return 0;
}

static int NWScript_SoundObjectStop(lua_State *L)
{
    dword oSound = luaL_checkint(L, 1);

    StackPushObject(oSound);
    VM_ExecuteCommand(414, 1);
    return 0;
}

static int NWScript_SoundObjectSetVolume(lua_State *L)
{
    dword oSound = luaL_checkint(L, 1);
    int nVolume = luaL_checkint(L, 2);

    StackPushInteger(nVolume);
    StackPushObject(oSound);
    VM_ExecuteCommand(415, 2);
    return 0;
}

static int NWScript_SoundObjectSetPosition(lua_State *L)
{
    dword oSound = luaL_checkint(L, 1);
    Vector *vPosition = (Vector *)luaL_checkudata(L, 2, VECTOR);

    StackPushVector(*vPosition);
    StackPushObject(oSound);
    VM_ExecuteCommand(416, 2);
    return 0;
}

static int NWScript_SpeakOneLinerConversation(lua_State *L)
{
    char *sDialogResRef = (char *)luaL_optstring(L, 1, "");
    dword oTokenTarget = luaL_optint(L, 2, OBJECT_TYPE_INVALID);

    StackPushObject(oTokenTarget);
    StackPushString(sDialogResRef);
    VM_ExecuteCommand(417, 2);
    return 0;
}

static int NWScript_GetGold(lua_State *L)
{
    dword oTarget = luaL_optint(L, 1, OBJECT_SELF);

    StackPushObject(oTarget);
    VM_ExecuteCommand(418, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetLastRespawnButtonPresser(lua_State *L)
{
    VM_ExecuteCommand(419, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetIsDM(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);

    StackPushObject(oCreature);
    VM_ExecuteCommand(420, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_PlayVoiceChat(lua_State *L)
{
    int nVoiceChatID = luaL_checkint(L, 1);
    dword oTarget = luaL_optint(L, 2, OBJECT_SELF);

    StackPushObject(oTarget);
    StackPushInteger(nVoiceChatID);
    VM_ExecuteCommand(421, 2);
    return 0;
}

static int NWScript_GetIsWeaponEffective(lua_State *L)
{
    dword oVersus = luaL_optint(L, 1, OBJECT_INVALID);
    int bOffHand = luaL_optboolean(L, 2, FALSE);

    StackPushInteger(bOffHand);
    StackPushObject(oVersus);
    VM_ExecuteCommand(422, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_GetLastSpellHarmful(lua_State *L)
{
    VM_ExecuteCommand(423, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_EventActivateItem(lua_State *L)
{
    dword oItem = luaL_checkint(L, 1);
    void *lTarget = luaL_checklightnwndata(L, 2, LOCATION);
    dword oTarget = luaL_optint(L, 3, OBJECT_INVALID);

    StackPushObject(oTarget);
    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lTarget);
    StackPushObject(oItem);
    VM_ExecuteCommand(424, 3);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EVENT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_MusicBackgroundPlay(lua_State *L)
{
    dword oArea = luaL_checkint(L, 1);

    StackPushObject(oArea);
    VM_ExecuteCommand(425, 1);
    return 0;
}

static int NWScript_MusicBackgroundStop(lua_State *L)
{
    dword oArea = luaL_checkint(L, 1);

    StackPushObject(oArea);
    VM_ExecuteCommand(426, 1);
    return 0;
}

static int NWScript_MusicBackgroundSetDelay(lua_State *L)
{
    dword oArea = luaL_checkint(L, 1);
    int nDelay = luaL_checkint(L, 2);

    StackPushInteger(nDelay);
    StackPushObject(oArea);
    VM_ExecuteCommand(427, 2);
    return 0;
}

static int NWScript_MusicBackgroundChangeDay(lua_State *L)
{
    dword oArea = luaL_checkint(L, 1);
    int nTrack = luaL_checkint(L, 2);

    StackPushInteger(nTrack);
    StackPushObject(oArea);
    VM_ExecuteCommand(428, 2);
    return 0;
}

static int NWScript_MusicBackgroundChangeNight(lua_State *L)
{
    dword oArea = luaL_checkint(L, 1);
    int nTrack = luaL_checkint(L, 2);

    StackPushInteger(nTrack);
    StackPushObject(oArea);
    VM_ExecuteCommand(429, 2);
    return 0;
}

static int NWScript_MusicBattlePlay(lua_State *L)
{
    dword oArea = luaL_checkint(L, 1);

    StackPushObject(oArea);
    VM_ExecuteCommand(430, 1);
    return 0;
}

static int NWScript_MusicBattleStop(lua_State *L)
{
    dword oArea = luaL_checkint(L, 1);

    StackPushObject(oArea);
    VM_ExecuteCommand(431, 1);
    return 0;
}

static int NWScript_MusicBattleChange(lua_State *L)
{
    dword oArea = luaL_checkint(L, 1);
    int nTrack = luaL_checkint(L, 2);

    StackPushInteger(nTrack);
    StackPushObject(oArea);
    VM_ExecuteCommand(432, 2);
    return 0;
}

static int NWScript_AmbientSoundPlay(lua_State *L)
{
    dword oArea = luaL_checkint(L, 1);

    StackPushObject(oArea);
    VM_ExecuteCommand(433, 1);
    return 0;
}

static int NWScript_AmbientSoundStop(lua_State *L)
{
    dword oArea = luaL_checkint(L, 1);

    StackPushObject(oArea);
    VM_ExecuteCommand(434, 1);
    return 0;
}

static int NWScript_AmbientSoundChangeDay(lua_State *L)
{
    dword oArea = luaL_checkint(L, 1);
    int nTrack = luaL_checkint(L, 2);

    StackPushInteger(nTrack);
    StackPushObject(oArea);
    VM_ExecuteCommand(435, 2);
    return 0;
}

static int NWScript_AmbientSoundChangeNight(lua_State *L)
{
    dword oArea = luaL_checkint(L, 1);
    int nTrack = luaL_checkint(L, 2);

    StackPushInteger(nTrack);
    StackPushObject(oArea);
    VM_ExecuteCommand(436, 2);
    return 0;
}

static int NWScript_GetLastKiller(lua_State *L)
{
    VM_ExecuteCommand(437, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetSpellCastItem(lua_State *L)
{
    VM_ExecuteCommand(438, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetItemActivated(lua_State *L)
{
    VM_ExecuteCommand(439, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetItemActivator(lua_State *L)
{
    VM_ExecuteCommand(440, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetItemActivatedTargetLocation(lua_State *L)
{
    VM_ExecuteCommand(441, 0);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_LOCATION, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_GetItemActivatedTarget(lua_State *L)
{
    VM_ExecuteCommand(442, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetIsOpen(lua_State *L)
{
    dword oObject = luaL_checkint(L, 1);

    StackPushObject(oObject);
    VM_ExecuteCommand(443, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_TakeGoldFromCreature(lua_State *L)
{
    int nAmount = luaL_checkint(L, 1);
    dword oCreatureToTakeFrom = luaL_checkint(L, 2);
    int bDestroy = luaL_optboolean(L, 3, FALSE);

    StackPushInteger(bDestroy);
    StackPushObject(oCreatureToTakeFrom);
    StackPushInteger(nAmount);
    VM_ExecuteCommand(444, 3);
    return 0;
}

static int NWScript_IsInConversation(lua_State *L)
{
    dword oObject = luaL_checkint(L, 1);

    StackPushObject(oObject);
    VM_ExecuteCommand(445, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_EffectAbilityDecrease(lua_State *L)
{
    int nAbility = luaL_checkint(L, 1);
    int nModifyBy = luaL_checkint(L, 2);

    StackPushInteger(nModifyBy);
    StackPushInteger(nAbility);
    VM_ExecuteCommand(446, 2);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_EffectAttackDecrease(lua_State *L)
{
    int nPenalty = luaL_checkint(L, 1);
    int nModifierType = luaL_optint(L, 2, ATTACK_BONUS_MISC);

    StackPushInteger(nModifierType);
    StackPushInteger(nPenalty);
    VM_ExecuteCommand(447, 2);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_EffectDamageDecrease(lua_State *L)
{
    int nPenalty = luaL_checkint(L, 1);
    int nDamageType = luaL_optint(L, 2, DAMAGE_TYPE_MAGICAL);

    StackPushInteger(nDamageType);
    StackPushInteger(nPenalty);
    VM_ExecuteCommand(448, 2);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_EffectDamageImmunityDecrease(lua_State *L)
{
    int nDamageType = luaL_checkint(L, 1);
    int nPercentImmunity = luaL_checkint(L, 2);

    StackPushInteger(nPercentImmunity);
    StackPushInteger(nDamageType);
    VM_ExecuteCommand(449, 2);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_EffectACDecrease(lua_State *L)
{
    int nValue = luaL_checkint(L, 1);
    int nModifyType = luaL_optint(L, 2, AC_DODGE_BONUS);
    int nDamageType = luaL_optint(L, 3, AC_VS_DAMAGE_TYPE_ALL);

    StackPushInteger(nDamageType);
    StackPushInteger(nModifyType);
    StackPushInteger(nValue);
    VM_ExecuteCommand(450, 3);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_EffectMovementSpeedDecrease(lua_State *L)
{
    int nPercentChange = luaL_checkint(L, 1);

    StackPushInteger(nPercentChange);
    VM_ExecuteCommand(451, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_EffectSavingThrowDecrease(lua_State *L)
{
    int nSave = luaL_checkint(L, 1);
    int nValue = luaL_checkint(L, 2);
    int nSaveType = luaL_optint(L, 3, SAVING_THROW_TYPE_ALL);

    StackPushInteger(nSaveType);
    StackPushInteger(nValue);
    StackPushInteger(nSave);
    VM_ExecuteCommand(452, 3);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_EffectSkillDecrease(lua_State *L)
{
    int nSkill = luaL_checkint(L, 1);
    int nValue = luaL_checkint(L, 2);

    StackPushInteger(nValue);
    StackPushInteger(nSkill);
    VM_ExecuteCommand(453, 2);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_EffectSpellResistanceDecrease(lua_State *L)
{
    int nValue = luaL_checkint(L, 1);

    StackPushInteger(nValue);
    VM_ExecuteCommand(454, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_GetPlotFlag(lua_State *L)
{
    dword oTarget = luaL_optint(L, 1, OBJECT_SELF);

    StackPushObject(oTarget);
    VM_ExecuteCommand(455, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_SetPlotFlag(lua_State *L)
{
    dword oTarget = luaL_checkint(L, 1);
    int nPlotFlag = luaL_checkboolean(L, 2);

    StackPushInteger(nPlotFlag);
    StackPushObject(oTarget);
    VM_ExecuteCommand(456, 2);
    return 0;
}

static int NWScript_EffectInvisibility(lua_State *L)
{
    int nInvisibilityType = luaL_checkint(L, 1);

    StackPushInteger(nInvisibilityType);
    VM_ExecuteCommand(457, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_EffectConcealment(lua_State *L)
{
    int nPercentage = luaL_checkint(L, 1);
    int nMissType = luaL_optint(L, 2, MISS_CHANCE_TYPE_NORMAL);

    StackPushInteger(nMissType);
    StackPushInteger(nPercentage);
    VM_ExecuteCommand(458, 2);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_EffectDarkness(lua_State *L)
{
    VM_ExecuteCommand(459, 0);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_EffectDispelMagicAll(lua_State *L)
{
    int nCasterLevel = luaL_optint(L, 1, USE_CREATURE_LEVEL);

    StackPushInteger(nCasterLevel);
    VM_ExecuteCommand(460, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_EffectUltravision(lua_State *L)
{
    VM_ExecuteCommand(461, 0);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_EffectNegativeLevel(lua_State *L)
{
    int nNumLevels = luaL_checkint(L, 1);
    int bHPBonus = luaL_optboolean(L, 2, FALSE);

    StackPushInteger(bHPBonus);
    StackPushInteger(nNumLevels);
    VM_ExecuteCommand(462, 2);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_EffectPolymorph(lua_State *L)
{
    int nPolymorphSelection = luaL_checkint(L, 1);
    int nLocked = luaL_optboolean(L, 2, FALSE);

    StackPushInteger(nLocked);
    StackPushInteger(nPolymorphSelection);
    VM_ExecuteCommand(463, 2);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_EffectSanctuary(lua_State *L)
{
    int nDifficultyClass = luaL_checkint(L, 1);

    StackPushInteger(nDifficultyClass);
    VM_ExecuteCommand(464, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_EffectTrueSeeing(lua_State *L)
{
    VM_ExecuteCommand(465, 0);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_EffectSeeInvisible(lua_State *L)
{
    VM_ExecuteCommand(466, 0);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_EffectTimeStop(lua_State *L)
{
    VM_ExecuteCommand(467, 0);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_EffectBlindness(lua_State *L)
{
    VM_ExecuteCommand(468, 0);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_GetIsReactionTypeFriendly(lua_State *L)
{
    dword oTarget = luaL_checkint(L, 1);
    dword oSource = luaL_optint(L, 2, OBJECT_SELF);

    StackPushObject(oSource);
    StackPushObject(oTarget);
    VM_ExecuteCommand(469, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_GetIsReactionTypeNeutral(lua_State *L)
{
    dword oTarget = luaL_checkint(L, 1);
    dword oSource = luaL_optint(L, 2, OBJECT_SELF);

    StackPushObject(oSource);
    StackPushObject(oTarget);
    VM_ExecuteCommand(470, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_GetIsReactionTypeHostile(lua_State *L)
{
    dword oTarget = luaL_checkint(L, 1);
    dword oSource = luaL_optint(L, 2, OBJECT_SELF);

    StackPushObject(oSource);
    StackPushObject(oTarget);
    VM_ExecuteCommand(471, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_EffectSpellLevelAbsorption(lua_State *L)
{
    int nMaxSpellLevelAbsorbed = luaL_checkint(L, 1);
    int nTotalSpellLevelsAbsorbed = luaL_optint(L, 2, 0);
    int nSpellSchool = luaL_optint(L, 3, SPELL_SCHOOL_GENERAL);

    StackPushInteger(nSpellSchool);
    StackPushInteger(nTotalSpellLevelsAbsorbed);
    StackPushInteger(nMaxSpellLevelAbsorbed);
    VM_ExecuteCommand(472, 3);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_EffectDispelMagicBest(lua_State *L)
{
    int nCasterLevel = luaL_optint(L, 1, USE_CREATURE_LEVEL);

    StackPushInteger(nCasterLevel);
    VM_ExecuteCommand(473, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ActivatePortal(lua_State *L)
{
    dword oTarget = luaL_checkint(L, 1);
    char *sIPaddress = (char *)luaL_optstring(L, 2, "");
    char *sPassword = (char *)luaL_optstring(L, 3, "");
    char *sWaypointTag = (char *)luaL_optstring(L, 4, "");
    int bSeemless = luaL_optboolean(L, 5, FALSE);

    StackPushInteger(bSeemless);
    StackPushString(sWaypointTag);
    StackPushString(sPassword);
    StackPushString(sIPaddress);
    StackPushObject(oTarget);
    VM_ExecuteCommand(474, 5);
    return 0;
}

static int NWScript_GetNumStackedItems(lua_State *L)
{
    dword oItem = luaL_checkint(L, 1);

    StackPushObject(oItem);
    VM_ExecuteCommand(475, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_SurrenderToEnemies(lua_State *L)
{
    VM_ExecuteCommand(476, 0);
    return 0;
}

static int NWScript_EffectMissChance(lua_State *L)
{
    int nPercentage = luaL_checkint(L, 1);
    int nMissChanceType = luaL_optint(L, 2, MISS_CHANCE_TYPE_NORMAL);

    StackPushInteger(nMissChanceType);
    StackPushInteger(nPercentage);
    VM_ExecuteCommand(477, 2);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_GetTurnResistanceHD(lua_State *L)
{
    dword oUndead = luaL_optint(L, 1, OBJECT_SELF);

    StackPushObject(oUndead);
    VM_ExecuteCommand(478, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetCreatureSize(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);

    StackPushObject(oCreature);
    VM_ExecuteCommand(479, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_EffectDisappearAppear(lua_State *L)
{
    void *lLocation = luaL_checklightnwndata(L, 1, LOCATION);
    int nAnimation = luaL_optint(L, 2, 1);

    StackPushInteger(nAnimation);
    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lLocation);
    VM_ExecuteCommand(480, 2);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_EffectDisappear(lua_State *L)
{
    int nAnimation = luaL_optint(L, 1, 1);

    StackPushInteger(nAnimation);
    VM_ExecuteCommand(481, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_EffectAppear(lua_State *L)
{
    int nAnimation = luaL_optint(L, 1, 1);

    StackPushInteger(nAnimation);
    VM_ExecuteCommand(482, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ActionUnlockObject(lua_State *L)
{
    dword oTarget = luaL_checkint(L, 1);

    StackPushObject(oTarget);
    VM_ExecuteCommand(483, 1);
    return 0;
}

static int NWScript_ActionLockObject(lua_State *L)
{
    dword oTarget = luaL_checkint(L, 1);

    StackPushObject(oTarget);
    VM_ExecuteCommand(484, 1);
    return 0;
}

static int NWScript_EffectModifyAttacks(lua_State *L)
{
    int nAttacks = luaL_checkint(L, 1);

    StackPushInteger(nAttacks);
    VM_ExecuteCommand(485, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_GetLastTrapDetected(lua_State *L)
{
    dword oTarget = luaL_optint(L, 1, OBJECT_SELF);

    StackPushObject(oTarget);
    VM_ExecuteCommand(486, 1);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_EffectDamageShield(lua_State *L)
{
    int nDamageAmount = luaL_checkint(L, 1);
    int nRandomAmount = luaL_checkint(L, 2);
    int nDamageType = luaL_checkint(L, 3);

    StackPushInteger(nDamageType);
    StackPushInteger(nRandomAmount);
    StackPushInteger(nDamageAmount);
    VM_ExecuteCommand(487, 3);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_GetNearestTrapToObject(lua_State *L)
{
    dword oTarget = luaL_optint(L, 1, OBJECT_SELF);
    int nTrapDetected = luaL_optboolean(L, 2, TRUE);

    StackPushInteger(nTrapDetected);
    StackPushObject(oTarget);
    VM_ExecuteCommand(488, 2);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetDeity(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);

    StackPushObject(oCreature);
    VM_ExecuteCommand(489, 1);
    char *sRetVal;
    StackPopString(&sRetVal);
    lua_pushstring(L, sRetVal);
    return 1;
}

static int NWScript_GetSubRace(lua_State *L)
{
    dword oTarget = luaL_checkint(L, 1);

    StackPushObject(oTarget);
    VM_ExecuteCommand(490, 1);
    char *sRetVal;
    StackPopString(&sRetVal);
    lua_pushstring(L, sRetVal);
    return 1;
}

static int NWScript_GetFortitudeSavingThrow(lua_State *L)
{
    dword oTarget = luaL_checkint(L, 1);

    StackPushObject(oTarget);
    VM_ExecuteCommand(491, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetWillSavingThrow(lua_State *L)
{
    dword oTarget = luaL_checkint(L, 1);

    StackPushObject(oTarget);
    VM_ExecuteCommand(492, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetReflexSavingThrow(lua_State *L)
{
    dword oTarget = luaL_checkint(L, 1);

    StackPushObject(oTarget);
    VM_ExecuteCommand(493, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetChallengeRating(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);

    StackPushObject(oCreature);
    VM_ExecuteCommand(494, 1);
    float fRetVal;
    StackPopFloat(&fRetVal);
    lua_pushnumber(L, fRetVal);
    return 1;
}

static int NWScript_GetAge(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);

    StackPushObject(oCreature);
    VM_ExecuteCommand(495, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetMovementRate(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);

    StackPushObject(oCreature);
    VM_ExecuteCommand(496, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetFamiliarCreatureType(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);

    StackPushObject(oCreature);
    VM_ExecuteCommand(497, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetAnimalCompanionCreatureType(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);

    StackPushObject(oCreature);
    VM_ExecuteCommand(498, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetFamiliarName(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);

    StackPushObject(oCreature);
    VM_ExecuteCommand(499, 1);
    char *sRetVal;
    StackPopString(&sRetVal);
    lua_pushstring(L, sRetVal);
    return 1;
}

static int NWScript_GetAnimalCompanionName(lua_State *L)
{
    dword oTarget = luaL_checkint(L, 1);

    StackPushObject(oTarget);
    VM_ExecuteCommand(500, 1);
    char *sRetVal;
    StackPopString(&sRetVal);
    lua_pushstring(L, sRetVal);
    return 1;
}

static int NWScript_ActionCastFakeSpellAtObject(lua_State *L)
{
    int nSpell = luaL_checkint(L, 1);
    dword oTarget = luaL_checkint(L, 2);
    int nProjectilePathType = luaL_optint(L, 3, PROJECTILE_PATH_TYPE_DEFAULT);

    StackPushInteger(nProjectilePathType);
    StackPushObject(oTarget);
    StackPushInteger(nSpell);
    VM_ExecuteCommand(501, 3);
    return 0;
}

static int NWScript_ActionCastFakeSpellAtLocation(lua_State *L)
{
    int nSpell = luaL_checkint(L, 1);
    void *lTarget = luaL_checklightnwndata(L, 2, LOCATION);
    int nProjectilePathType = luaL_optint(L, 3, PROJECTILE_PATH_TYPE_DEFAULT);

    StackPushInteger(nProjectilePathType);
    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lTarget);
    StackPushInteger(nSpell);
    VM_ExecuteCommand(502, 3);
    return 0;
}

static int NWScript_RemoveSummonedAssociate(lua_State *L)
{
    dword oMaster = luaL_checkint(L, 1);
    dword oAssociate = luaL_optint(L, 2, OBJECT_SELF);

    StackPushObject(oAssociate);
    StackPushObject(oMaster);
    VM_ExecuteCommand(503, 2);
    return 0;
}

static int NWScript_SetCameraMode(lua_State *L)
{
    dword oPlayer = luaL_checkint(L, 1);
    int nCameraMode = luaL_checkint(L, 2);

    StackPushInteger(nCameraMode);
    StackPushObject(oPlayer);
    VM_ExecuteCommand(504, 2);
    return 0;
}

static int NWScript_GetIsResting(lua_State *L)
{
    dword oCreature = luaL_optint(L, 1, OBJECT_SELF);

    StackPushObject(oCreature);
    VM_ExecuteCommand(505, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_GetLastPCRested(lua_State *L)
{
    VM_ExecuteCommand(506, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_SetWeather(lua_State *L)
{
    dword oTarget = luaL_checkint(L, 1);
    int nWeather = luaL_checkint(L, 2);

    StackPushInteger(nWeather);
    StackPushObject(oTarget);
    VM_ExecuteCommand(507, 2);
    return 0;
}

static int NWScript_GetLastRestEventType(lua_State *L)
{
    VM_ExecuteCommand(508, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_StartNewModule(lua_State *L)
{
    char *sModuleName = (char *)luaL_checkstring(L, 1);

    StackPushString(sModuleName);
    VM_ExecuteCommand(509, 1);
    return 0;
}

static int NWScript_EffectSwarm(lua_State *L)
{
    int nLooping = luaL_checkint(L, 1);
    char *sCreatureTemplate1 = (char *)luaL_checkstring(L, 2);
    char *sCreatureTemplate2 = (char *)luaL_optstring(L, 3, "");
    char *sCreatureTemplate3 = (char *)luaL_optstring(L, 4, "");
    char *sCreatureTemplate4 = (char *)luaL_optstring(L, 5, "");

    StackPushString(sCreatureTemplate4);
    StackPushString(sCreatureTemplate3);
    StackPushString(sCreatureTemplate2);
    StackPushString(sCreatureTemplate1);
    StackPushInteger(nLooping);
    VM_ExecuteCommand(510, 5);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_GetWeaponRanged(lua_State *L)
{
    dword oItem = luaL_checkint(L, 1);

    StackPushObject(oItem);
    VM_ExecuteCommand(511, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_DoSinglePlayerAutoSave(lua_State *L)
{
    VM_ExecuteCommand(512, 0);
    return 0;
}

static int NWScript_GetGameDifficulty(lua_State *L)
{
    VM_ExecuteCommand(513, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_SetTileMainLightColor(lua_State *L)
{
    void *lTileLocation = luaL_checklightnwndata(L, 1, LOCATION);
    int nMainLight1Color = luaL_checkint(L, 2);
    int nMainLight2Color = luaL_checkint(L, 3);

    StackPushInteger(nMainLight2Color);
    StackPushInteger(nMainLight1Color);
    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lTileLocation);
    VM_ExecuteCommand(514, 3);
    return 0;
}

static int NWScript_SetTileSourceLightColor(lua_State *L)
{
    void *lTileLocation = luaL_checklightnwndata(L, 1, LOCATION);
    int nSourceLight1Color = luaL_checkint(L, 2);
    int nSourceLight2Color = luaL_checkint(L, 3);

    StackPushInteger(nSourceLight2Color);
    StackPushInteger(nSourceLight1Color);
    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lTileLocation);
    VM_ExecuteCommand(515, 3);
    return 0;
}

static int NWScript_RecomputeStaticLighting(lua_State *L)
{
    dword oArea = luaL_checkint(L, 1);

    StackPushObject(oArea);
    VM_ExecuteCommand(516, 1);
    return 0;
}

static int NWScript_GetTileMainLight1Color(lua_State *L)
{
    void *lTile = luaL_checklightnwndata(L, 1, LOCATION);

    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lTile);
    VM_ExecuteCommand(517, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetTileMainLight2Color(lua_State *L)
{
    void *lTile = luaL_checklightnwndata(L, 1, LOCATION);

    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lTile);
    VM_ExecuteCommand(518, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetTileSourceLight1Color(lua_State *L)
{
    void *lTile = luaL_checklightnwndata(L, 1, LOCATION);

    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lTile);
    VM_ExecuteCommand(519, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetTileSourceLight2Color(lua_State *L)
{
    void *lTile = luaL_checklightnwndata(L, 1, LOCATION);

    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lTile);
    VM_ExecuteCommand(520, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_SetPanelButtonFlash(lua_State *L)
{
    dword oPlayer = luaL_checkint(L, 1);
    int nButton = luaL_checkint(L, 2);
    int nEnableFlash = luaL_checkint(L, 3);

    StackPushInteger(nEnableFlash);
    StackPushInteger(nButton);
    StackPushObject(oPlayer);
    VM_ExecuteCommand(521, 3);
    return 0;
}

static int NWScript_GetCurrentAction(lua_State *L)
{
    dword oObject = luaL_optint(L, 1, OBJECT_SELF);

    StackPushObject(oObject);
    VM_ExecuteCommand(522, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_SetStandardFactionReputation(lua_State *L)
{
    int nStandardFaction = luaL_checkint(L, 1);
    int nNewReputation = luaL_checkint(L, 2);
    dword oCreature = luaL_optint(L, 3, OBJECT_SELF);

    StackPushObject(oCreature);
    StackPushInteger(nNewReputation);
    StackPushInteger(nStandardFaction);
    VM_ExecuteCommand(523, 3);
    return 0;
}

static int NWScript_GetStandardFactionReputation(lua_State *L)
{
    int nStandardFaction = luaL_checkint(L, 1);
    dword oCreature = luaL_optint(L, 2, OBJECT_SELF);

    StackPushObject(oCreature);
    StackPushInteger(nStandardFaction);
    VM_ExecuteCommand(524, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_FloatingTextStrRefOnCreature(lua_State *L)
{
    int nStrRefToDisplay = luaL_checkint(L, 1);
    dword oCreatureToFloatAbove = luaL_checkint(L, 2);
    int bBroadcastToFaction = luaL_optboolean(L, 3, TRUE);

    StackPushInteger(bBroadcastToFaction);
    StackPushObject(oCreatureToFloatAbove);
    StackPushInteger(nStrRefToDisplay);
    VM_ExecuteCommand(525, 3);
    return 0;
}

static int NWScript_FloatingTextStringOnCreature(lua_State *L)
{
    char *sStringToDisplay = (char *)luaL_checkstring(L, 1);
    dword oCreatureToFloatAbove = luaL_checkint(L, 2);
    int bBroadcastToFaction = luaL_optboolean(L, 3, TRUE);

    StackPushInteger(bBroadcastToFaction);
    StackPushObject(oCreatureToFloatAbove);
    StackPushString(sStringToDisplay);
    VM_ExecuteCommand(526, 3);
    return 0;
}

static int NWScript_GetTrapDisarmable(lua_State *L)
{
    dword oTrapObject = luaL_checkint(L, 1);

    StackPushObject(oTrapObject);
    VM_ExecuteCommand(527, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_GetTrapDetectable(lua_State *L)
{
    dword oTrapObject = luaL_checkint(L, 1);

    StackPushObject(oTrapObject);
    VM_ExecuteCommand(528, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_GetTrapDetectedBy(lua_State *L)
{
    dword oTrapObject = luaL_checkint(L, 1);
    dword oCreature = luaL_checkint(L, 2);

    StackPushObject(oCreature);
    StackPushObject(oTrapObject);
    VM_ExecuteCommand(529, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_GetTrapFlagged(lua_State *L)
{
    dword oTrapObject = luaL_checkint(L, 1);

    StackPushObject(oTrapObject);
    VM_ExecuteCommand(530, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_GetTrapBaseType(lua_State *L)
{
    dword oTrapObject = luaL_checkint(L, 1);

    StackPushObject(oTrapObject);
    VM_ExecuteCommand(531, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetTrapOneShot(lua_State *L)
{
    dword oTrapObject = luaL_checkint(L, 1);

    StackPushObject(oTrapObject);
    VM_ExecuteCommand(532, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_GetTrapCreator(lua_State *L)
{
    dword oTrapObject = luaL_checkint(L, 1);

    StackPushObject(oTrapObject);
    VM_ExecuteCommand(533, 1);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetTrapKeyTag(lua_State *L)
{
    dword oTrapObject = luaL_checkint(L, 1);

    StackPushObject(oTrapObject);
    VM_ExecuteCommand(534, 1);
    char *sRetVal;
    StackPopString(&sRetVal);
    lua_pushstring(L, sRetVal);
    return 1;
}

static int NWScript_GetTrapDisarmDC(lua_State *L)
{
    dword oTrapObject = luaL_checkint(L, 1);

    StackPushObject(oTrapObject);
    VM_ExecuteCommand(535, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetTrapDetectDC(lua_State *L)
{
    dword oTrapObject = luaL_checkint(L, 1);

    StackPushObject(oTrapObject);
    VM_ExecuteCommand(536, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetLockKeyRequired(lua_State *L)
{
    dword oObject = luaL_checkint(L, 1);

    StackPushObject(oObject);
    VM_ExecuteCommand(537, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_GetLockKeyTag(lua_State *L)
{
    dword oObject = luaL_checkint(L, 1);

    StackPushObject(oObject);
    VM_ExecuteCommand(538, 1);
    char *sRetVal;
    StackPopString(&sRetVal);
    lua_pushstring(L, sRetVal);
    return 1;
}

static int NWScript_GetLockLockable(lua_State *L)
{
    dword oObject = luaL_checkint(L, 1);

    StackPushObject(oObject);
    VM_ExecuteCommand(539, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_GetLockUnlockDC(lua_State *L)
{
    dword oObject = luaL_checkint(L, 1);

    StackPushObject(oObject);
    VM_ExecuteCommand(540, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetLockLockDC(lua_State *L)
{
    dword oObject = luaL_checkint(L, 1);

    StackPushObject(oObject);
    VM_ExecuteCommand(541, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetPCLevellingUp(lua_State *L)
{
    VM_ExecuteCommand(542, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetHasFeatEffect(lua_State *L)
{
    int nFeat = luaL_checkint(L, 1);
    dword oObject = luaL_optint(L, 2, OBJECT_SELF);

    StackPushObject(oObject);
    StackPushInteger(nFeat);
    VM_ExecuteCommand(543, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_SetPlaceableIllumination(lua_State *L)
{
    dword oPlaceable = luaL_optint(L, 1, OBJECT_SELF);
    int bIlluminate = luaL_optboolean(L, 2, TRUE);

    StackPushInteger(bIlluminate);
    StackPushObject(oPlaceable);
    VM_ExecuteCommand(544, 2);
    return 0;
}

static int NWScript_GetPlaceableIllumination(lua_State *L)
{
    dword oPlaceable = luaL_optint(L, 1, OBJECT_SELF);

    StackPushObject(oPlaceable);
    VM_ExecuteCommand(545, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_GetIsPlaceableObjectActionPossible(lua_State *L)
{
    dword oPlaceable = luaL_checkint(L, 1);
    int nPlaceableAction = luaL_checkint(L, 2);

    StackPushInteger(nPlaceableAction);
    StackPushObject(oPlaceable);
    VM_ExecuteCommand(546, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_DoPlaceableObjectAction(lua_State *L)
{
    dword oPlaceable = luaL_checkint(L, 1);
    int nPlaceableAction = luaL_checkint(L, 2);

    StackPushInteger(nPlaceableAction);
    StackPushObject(oPlaceable);
    VM_ExecuteCommand(547, 2);
    return 0;
}

static int NWScript_GetFirstPC(lua_State *L)
{
    VM_ExecuteCommand(548, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetNextPC(lua_State *L)
{
    VM_ExecuteCommand(549, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_SetTrapDetectedBy(lua_State *L)
{
    dword oTrap = luaL_checkint(L, 1);
    dword oDetector = luaL_checkint(L, 2);
    int bDetected = luaL_optboolean(L, 3, TRUE);

    StackPushInteger(bDetected);
    StackPushObject(oDetector);
    StackPushObject(oTrap);
    VM_ExecuteCommand(550, 3);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetIsTrapped(lua_State *L)
{
    dword oObject = luaL_checkint(L, 1);

    StackPushObject(oObject);
    VM_ExecuteCommand(551, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_EffectTurnResistanceDecrease(lua_State *L)
{
    int nHitDice = luaL_checkint(L, 1);

    StackPushInteger(nHitDice);
    VM_ExecuteCommand(552, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_EffectTurnResistanceIncrease(lua_State *L)
{
    int nHitDice = luaL_checkint(L, 1);

    StackPushInteger(nHitDice);
    VM_ExecuteCommand(553, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_PopUpDeathGUIPanel(lua_State *L)
{
    dword oPC = luaL_checkint(L, 1);
    int bRespawnButtonEnabled = luaL_optboolean(L, 2, TRUE);
    int bWaitForHelpButtonEnabled = luaL_optboolean(L, 3, TRUE);
    int nHelpStringReference = luaL_optint(L, 4, 0);
    char *sHelpString = (char *)luaL_optstring(L, 5, "");

    StackPushString(sHelpString);
    StackPushInteger(nHelpStringReference);
    StackPushInteger(bWaitForHelpButtonEnabled);
    StackPushInteger(bRespawnButtonEnabled);
    StackPushObject(oPC);
    VM_ExecuteCommand(554, 5);
    return 0;
}

static int NWScript_SetTrapDisabled(lua_State *L)
{
    dword oTrap = luaL_checkint(L, 1);

    StackPushObject(oTrap);
    VM_ExecuteCommand(555, 1);
    return 0;
}

static int NWScript_GetLastHostileActor(lua_State *L)
{
    dword oVictim = luaL_optint(L, 1, OBJECT_SELF);

    StackPushObject(oVictim);
    VM_ExecuteCommand(556, 1);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_ExportAllCharacters(lua_State *L)
{
    VM_ExecuteCommand(557, 0);
    return 0;
}

static int NWScript_MusicBackgroundGetDayTrack(lua_State *L)
{
    dword oArea = luaL_checkint(L, 1);

    StackPushObject(oArea);
    VM_ExecuteCommand(558, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_MusicBackgroundGetNightTrack(lua_State *L)
{
    dword oArea = luaL_checkint(L, 1);

    StackPushObject(oArea);
    VM_ExecuteCommand(559, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_WriteTimestampedLogEntry(lua_State *L)
{
    char *sLogEntry = (char *)luaL_checkstring(L, 1);

    StackPushString(sLogEntry);
    VM_ExecuteCommand(560, 1);
    return 0;
}

static int NWScript_GetModuleName(lua_State *L)
{
    VM_ExecuteCommand(561, 0);
    char *sRetVal;
    StackPopString(&sRetVal);
    lua_pushstring(L, sRetVal);
    return 1;
}

static int NWScript_GetFactionLeader(lua_State *L)
{
    dword oMemberOfFaction = luaL_checkint(L, 1);

    StackPushObject(oMemberOfFaction);
    VM_ExecuteCommand(562, 1);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_SendMessageToAllDMs(lua_State *L)
{
    char *szMessage = (char *)luaL_checkstring(L, 1);

    StackPushString(szMessage);
    VM_ExecuteCommand(563, 1);
    return 0;
}

static int NWScript_EndGame(lua_State *L)
{
    char *sEndMovie = (char *)luaL_checkstring(L, 1);

    StackPushString(sEndMovie);
    VM_ExecuteCommand(564, 1);
    return 0;
}

static int NWScript_BootPC(lua_State *L)
{
    dword oPlayer = luaL_checkint(L, 1);

    StackPushObject(oPlayer);
    VM_ExecuteCommand(565, 1);
    return 0;
}

static int NWScript_ActionCounterSpell(lua_State *L)
{
    dword oCounterSpellTarget = luaL_checkint(L, 1);

    StackPushObject(oCounterSpellTarget);
    VM_ExecuteCommand(566, 1);
    return 0;
}

static int NWScript_AmbientSoundSetDayVolume(lua_State *L)
{
    dword oArea = luaL_checkint(L, 1);
    int nVolume = luaL_checkint(L, 2);

    StackPushInteger(nVolume);
    StackPushObject(oArea);
    VM_ExecuteCommand(567, 2);
    return 0;
}

static int NWScript_AmbientSoundSetNightVolume(lua_State *L)
{
    dword oArea = luaL_checkint(L, 1);
    int nVolume = luaL_checkint(L, 2);

    StackPushInteger(nVolume);
    StackPushObject(oArea);
    VM_ExecuteCommand(568, 2);
    return 0;
}

static int NWScript_MusicBackgroundGetBattleTrack(lua_State *L)
{
    dword oArea = luaL_checkint(L, 1);

    StackPushObject(oArea);
    VM_ExecuteCommand(569, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetHasInventory(lua_State *L)
{
    dword oObject = luaL_checkint(L, 1);

    StackPushObject(oObject);
    VM_ExecuteCommand(570, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_GetStrRefSoundDuration(lua_State *L)
{
    int nStrRef = luaL_checkint(L, 1);

    StackPushInteger(nStrRef);
    VM_ExecuteCommand(571, 1);
    float fRetVal;
    StackPopFloat(&fRetVal);
    lua_pushnumber(L, fRetVal);
    return 1;
}

static int NWScript_AddToParty(lua_State *L)
{
    dword oPC = luaL_checkint(L, 1);
    dword oPartyLeader = luaL_checkint(L, 2);

    StackPushObject(oPartyLeader);
    StackPushObject(oPC);
    VM_ExecuteCommand(572, 2);
    return 0;
}

static int NWScript_RemoveFromParty(lua_State *L)
{
    dword oPC = luaL_checkint(L, 1);

    StackPushObject(oPC);
    VM_ExecuteCommand(573, 1);
    return 0;
}

static int NWScript_GetStealthMode(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);

    StackPushObject(oCreature);
    VM_ExecuteCommand(574, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetDetectMode(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);

    StackPushObject(oCreature);
    VM_ExecuteCommand(575, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetDefensiveCastingMode(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);

    StackPushObject(oCreature);
    VM_ExecuteCommand(576, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetAppearanceType(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);

    StackPushObject(oCreature);
    VM_ExecuteCommand(577, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_SpawnScriptDebugger(lua_State *L)
{
    VM_ExecuteCommand(578, 0);
    return 0;
}

static int NWScript_GetModuleItemAcquiredStackSize(lua_State *L)
{
    VM_ExecuteCommand(579, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_DecrementRemainingFeatUses(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);
    int nFeat = luaL_checkint(L, 2);

    StackPushInteger(nFeat);
    StackPushObject(oCreature);
    VM_ExecuteCommand(580, 2);
    return 0;
}

static int NWScript_DecrementRemainingSpellUses(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);
    int nSpell = luaL_checkint(L, 2);

    StackPushInteger(nSpell);
    StackPushObject(oCreature);
    VM_ExecuteCommand(581, 2);
    return 0;
}

static int NWScript_GetResRef(lua_State *L)
{
    dword oObject = luaL_checkint(L, 1);

    StackPushObject(oObject);
    VM_ExecuteCommand(582, 1);
    char *sRetVal;
    StackPopString(&sRetVal);
    lua_pushstring(L, sRetVal);
    return 1;
}

static int NWScript_EffectPetrify(lua_State *L)
{
    VM_ExecuteCommand(583, 0);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_CopyItem(lua_State *L)
{
    dword oItem = luaL_checkint(L, 1);
    dword oTargetInventory = luaL_optint(L, 2, OBJECT_INVALID);
    int bCopyVars = luaL_optboolean(L, 3, FALSE);

    StackPushInteger(bCopyVars);
    StackPushObject(oTargetInventory);
    StackPushObject(oItem);
    VM_ExecuteCommand(584, 3);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_EffectCutsceneParalyze(lua_State *L)
{
    VM_ExecuteCommand(585, 0);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_GetDroppableFlag(lua_State *L)
{
    dword oItem = luaL_checkint(L, 1);

    StackPushObject(oItem);
    VM_ExecuteCommand(586, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_GetUseableFlag(lua_State *L)
{
    dword oObject = luaL_optint(L, 1, OBJECT_SELF);

    StackPushObject(oObject);
    VM_ExecuteCommand(587, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_GetStolenFlag(lua_State *L)
{
    dword oStolen = luaL_checkint(L, 1);

    StackPushObject(oStolen);
    VM_ExecuteCommand(588, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_SetCampaignFloat(lua_State *L)
{
    char *sCampaignName = (char *)luaL_checkstring(L, 1);
    char *sVarName = (char *)luaL_checkstring(L, 2);
    double flFloat = luaL_checknumber(L, 3);
    dword oPlayer = luaL_optint(L, 4, OBJECT_INVALID);

    StackPushObject(oPlayer);
    StackPushFloat(flFloat);
    StackPushString(sVarName);
    StackPushString(sCampaignName);
    VM_ExecuteCommand(589, 4);
    return 0;
}

static int NWScript_SetCampaignInt(lua_State *L)
{
    char *sCampaignName = (char *)luaL_checkstring(L, 1);
    char *sVarName = (char *)luaL_checkstring(L, 2);
    int nInt = luaL_checkint(L, 3);
    dword oPlayer = luaL_optint(L, 4, OBJECT_INVALID);

    StackPushObject(oPlayer);
    StackPushInteger(nInt);
    StackPushString(sVarName);
    StackPushString(sCampaignName);
    VM_ExecuteCommand(590, 4);
    return 0;
}

static int NWScript_SetCampaignVector(lua_State *L)
{
    char *sCampaignName = (char *)luaL_checkstring(L, 1);
    char *sVarName = (char *)luaL_checkstring(L, 2);
    Vector *vVector = (Vector *)luaL_checkudata(L, 3, VECTOR);
    dword oPlayer = luaL_optint(L, 4, OBJECT_INVALID);

    StackPushObject(oPlayer);
    StackPushVector(*vVector);
    StackPushString(sVarName);
    StackPushString(sCampaignName);
    VM_ExecuteCommand(591, 4);
    return 0;
}

static int NWScript_SetCampaignLocation(lua_State *L)
{
    char *sCampaignName = (char *)luaL_checkstring(L, 1);
    char *sVarName = (char *)luaL_checkstring(L, 2);
    void *locLocation = luaL_checklightnwndata(L, 3, LOCATION);
    dword oPlayer = luaL_optint(L, 4, OBJECT_INVALID);

    StackPushObject(oPlayer);
    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, locLocation);
    StackPushString(sVarName);
    StackPushString(sCampaignName);
    VM_ExecuteCommand(592, 4);
    return 0;
}

static int NWScript_SetCampaignString(lua_State *L)
{
    char *sCampaignName = (char *)luaL_checkstring(L, 1);
    char *sVarName = (char *)luaL_checkstring(L, 2);
    char *sString = (char *)luaL_checkstring(L, 3);
    dword oPlayer = luaL_optint(L, 4, OBJECT_INVALID);

    StackPushObject(oPlayer);
    StackPushString(sString);
    StackPushString(sVarName);
    StackPushString(sCampaignName);
    VM_ExecuteCommand(593, 4);
    return 0;
}

static int NWScript_DestroyCampaignDatabase(lua_State *L)
{
    char *sCampaignName = (char *)luaL_checkstring(L, 1);

    StackPushString(sCampaignName);
    VM_ExecuteCommand(594, 1);
    return 0;
}

static int NWScript_GetCampaignFloat(lua_State *L)
{
    char *sCampaignName = (char *)luaL_checkstring(L, 1);
    char *sVarName = (char *)luaL_checkstring(L, 2);
    dword oPlayer = luaL_optint(L, 3, OBJECT_INVALID);

    StackPushObject(oPlayer);
    StackPushString(sVarName);
    StackPushString(sCampaignName);
    VM_ExecuteCommand(595, 3);
    float fRetVal;
    StackPopFloat(&fRetVal);
    lua_pushnumber(L, fRetVal);
    return 1;
}

static int NWScript_GetCampaignInt(lua_State *L)
{
    char *sCampaignName = (char *)luaL_checkstring(L, 1);
    char *sVarName = (char *)luaL_checkstring(L, 2);
    dword oPlayer = luaL_optint(L, 3, OBJECT_INVALID);

    StackPushObject(oPlayer);
    StackPushString(sVarName);
    StackPushString(sCampaignName);
    VM_ExecuteCommand(596, 3);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetCampaignVector(lua_State *L)
{
    char *sCampaignName = (char *)luaL_checkstring(L, 1);
    char *sVarName = (char *)luaL_checkstring(L, 2);
    dword oPlayer = luaL_optint(L, 3, OBJECT_INVALID);

    StackPushObject(oPlayer);
    StackPushString(sVarName);
    StackPushString(sCampaignName);
    VM_ExecuteCommand(597, 3);
    Vector *vRetVal = (Vector *)lua_newuserdata(L, sizeof(Vector));
    StackPopVector(vRetVal);
    luaL_getmetatable(L, VECTOR);
    lua_setmetatable(L, -2);
    return 1;
}

static int NWScript_GetCampaignLocation(lua_State *L)
{
    char *sCampaignName = (char *)luaL_checkstring(L, 1);
    char *sVarName = (char *)luaL_checkstring(L, 2);
    dword oPlayer = luaL_optint(L, 3, OBJECT_INVALID);

    StackPushObject(oPlayer);
    StackPushString(sVarName);
    StackPushString(sCampaignName);
    VM_ExecuteCommand(598, 3);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_LOCATION, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_GetCampaignString(lua_State *L)
{
    char *sCampaignName = (char *)luaL_checkstring(L, 1);
    char *sVarName = (char *)luaL_checkstring(L, 2);
    dword oPlayer = luaL_optint(L, 3, OBJECT_INVALID);

    StackPushObject(oPlayer);
    StackPushString(sVarName);
    StackPushString(sCampaignName);
    VM_ExecuteCommand(599, 3);
    char *sRetVal;
    StackPopString(&sRetVal);
    lua_pushstring(L, sRetVal);
    return 1;
}

static int NWScript_CopyObject(lua_State *L)
{
    dword oSource = luaL_checkint(L, 1);
    void *locLocation = luaL_checklightnwndata(L, 2, LOCATION);
    dword oOwner  = luaL_optint(L, 3, OBJECT_INVALID);
    char *sNewTag  = (char *)luaL_optstring(L, 4, "");

    StackPushString(sNewTag);
    StackPushObject(oOwner);
    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, locLocation);
    StackPushObject(oSource);
    VM_ExecuteCommand(600, 4);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_DeleteCampaignVariable(lua_State *L)
{
    char *sCampaignName = (char *)luaL_checkstring(L, 1);
    char *sVarName = (char *)luaL_checkstring(L, 2);
    dword oPlayer = luaL_optint(L, 3, OBJECT_INVALID);

    StackPushObject(oPlayer);
    StackPushString(sVarName);
    StackPushString(sCampaignName);
    VM_ExecuteCommand(601, 3);
    return 0;
}

static int NWScript_StoreCampaignObject(lua_State *L)
{
    char *sCampaignName = (char *)luaL_checkstring(L, 1);
    char *sVarName = (char *)luaL_checkstring(L, 2);
    dword oObject = luaL_checkint(L, 3);
    dword oPlayer = luaL_optint(L, 4, OBJECT_INVALID);

    StackPushObject(oPlayer);
    StackPushObject(oObject);
    StackPushString(sVarName);
    StackPushString(sCampaignName);
    VM_ExecuteCommand(602, 4);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_RetrieveCampaignObject(lua_State *L)
{
    char *sCampaignName = (char *)luaL_checkstring(L, 1);
    char *sVarName = (char *)luaL_checkstring(L, 2);
    void *locLocation = luaL_checklightnwndata(L, 3, LOCATION);
    dword oOwner  = luaL_optint(L, 4, OBJECT_INVALID);
    dword oPlayer = luaL_optint(L, 5, OBJECT_INVALID);

    StackPushObject(oPlayer);
    StackPushObject(oOwner);
    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, locLocation);
    StackPushString(sVarName);
    StackPushString(sCampaignName);
    VM_ExecuteCommand(603, 5);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_EffectCutsceneDominated(lua_State *L)
{
    VM_ExecuteCommand(604, 0);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_GetItemStackSize(lua_State *L)
{
    dword oItem = luaL_checkint(L, 1);

    StackPushObject(oItem);
    VM_ExecuteCommand(605, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_SetItemStackSize(lua_State *L)
{
    dword oItem = luaL_checkint(L, 1);
    int nSize = luaL_checkint(L, 2);

    StackPushInteger(nSize);
    StackPushObject(oItem);
    VM_ExecuteCommand(606, 2);
    return 0;
}

static int NWScript_GetItemCharges(lua_State *L)
{
    dword oItem = luaL_checkint(L, 1);

    StackPushObject(oItem);
    VM_ExecuteCommand(607, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_SetItemCharges(lua_State *L)
{
    dword oItem = luaL_checkint(L, 1);
    int nCharges = luaL_checkint(L, 2);

    StackPushInteger(nCharges);
    StackPushObject(oItem);
    VM_ExecuteCommand(608, 2);
    return 0;
}

static int NWScript_AddItemProperty(lua_State *L)
{
    int nDurationType = luaL_checkint(L, 1);
    void *ipProperty = luaL_checklightnwndata(L, 2, ITEMPROPERTY);
    dword oItem = luaL_checkint(L, 3);
    double fDuration = luaL_optnumber(L, 4, 0.0);

    StackPushFloat(fDuration);
    StackPushObject(oItem);
    StackPushEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, ipProperty);
    StackPushInteger(nDurationType);
    VM_ExecuteCommand(609, 4);
    return 0;
}

static int NWScript_RemoveItemProperty(lua_State *L)
{
    dword oItem = luaL_checkint(L, 1);
    void *ipProperty = luaL_checklightnwndata(L, 2, ITEMPROPERTY);

    StackPushEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, ipProperty);
    StackPushObject(oItem);
    VM_ExecuteCommand(610, 2);
    return 0;
}

static int NWScript_GetIsItemPropertyValid(lua_State *L)
{
    void *ipProperty = luaL_checklightnwndata(L, 1, ITEMPROPERTY);

    StackPushEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, ipProperty);
    VM_ExecuteCommand(611, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_GetFirstItemProperty(lua_State *L)
{
    dword oItem = luaL_checkint(L, 1);

    StackPushObject(oItem);
    VM_ExecuteCommand(612, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_GetNextItemProperty(lua_State *L)
{
    dword oItem = luaL_checkint(L, 1);

    StackPushObject(oItem);
    VM_ExecuteCommand(613, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_GetItemPropertyType(lua_State *L)
{
    void *ip = luaL_checklightnwndata(L, 1, ITEMPROPERTY);

    StackPushEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, ip);
    VM_ExecuteCommand(614, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetItemPropertyDurationType(lua_State *L)
{
    void *ip = luaL_checklightnwndata(L, 1, ITEMPROPERTY);

    StackPushEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, ip);
    VM_ExecuteCommand(615, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_ItemPropertyAbilityBonus(lua_State *L)
{
    int nAbility = luaL_checkint(L, 1);
    int nBonus = luaL_checkint(L, 2);

    StackPushInteger(nBonus);
    StackPushInteger(nAbility);
    VM_ExecuteCommand(616, 2);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyACBonus(lua_State *L)
{
    int nBonus = luaL_checkint(L, 1);

    StackPushInteger(nBonus);
    VM_ExecuteCommand(617, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyACBonusVsAlign(lua_State *L)
{
    int nAlignGroup = luaL_checkint(L, 1);
    int nACBonus = luaL_checkint(L, 2);

    StackPushInteger(nACBonus);
    StackPushInteger(nAlignGroup);
    VM_ExecuteCommand(618, 2);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyACBonusVsDmgType(lua_State *L)
{
    int nDamageType = luaL_checkint(L, 1);
    int nACBonus = luaL_checkint(L, 2);

    StackPushInteger(nACBonus);
    StackPushInteger(nDamageType);
    VM_ExecuteCommand(619, 2);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyACBonusVsRace(lua_State *L)
{
    int nRace = luaL_checkint(L, 1);
    int nACBonus = luaL_checkint(L, 2);

    StackPushInteger(nACBonus);
    StackPushInteger(nRace);
    VM_ExecuteCommand(620, 2);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyACBonusVsSAlign(lua_State *L)
{
    int nAlign = luaL_checkint(L, 1);
    int nACBonus = luaL_checkint(L, 2);

    StackPushInteger(nACBonus);
    StackPushInteger(nAlign);
    VM_ExecuteCommand(621, 2);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyEnhancementBonus(lua_State *L)
{
    int nEnhancementBonus = luaL_checkint(L, 1);
    StackPushInteger(nEnhancementBonus);

    VM_ExecuteCommand(622, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyEnhancementBonusVsAlign(lua_State *L)
{
    int nAlignGroup = luaL_checkint(L, 1);
    int nBonus = luaL_checkint(L, 2);

    StackPushInteger(nBonus);
    StackPushInteger(nAlignGroup);
    VM_ExecuteCommand(623, 2);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyEnhancementBonusVsRace(lua_State *L)
{
    int nRace = luaL_checkint(L, 1);
    int nBonus = luaL_checkint(L, 2);

    StackPushInteger(nBonus);
    StackPushInteger(nRace);
    VM_ExecuteCommand(624, 2);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyEnhancementBonusVsSAlign(lua_State *L)
{
    int nAlign = luaL_checkint(L, 1);
    int nBonus = luaL_checkint(L, 2);

    StackPushInteger(nBonus);
    StackPushInteger(nAlign);
    VM_ExecuteCommand(625, 2);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyEnhancementPenalty(lua_State *L)
{
    int nPenalty = luaL_checkint(L, 1);

    StackPushInteger(nPenalty);
    VM_ExecuteCommand(626, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyWeightReduction(lua_State *L)
{
    int nReduction = luaL_checkint(L, 1);

    StackPushInteger(nReduction);
    VM_ExecuteCommand(627, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyBonusFeat(lua_State *L)
{
    int nFeat = luaL_checkint(L, 1);

    StackPushInteger(nFeat);
    VM_ExecuteCommand(628, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyBonusLevelSpell(lua_State *L)
{
    int nClass = luaL_checkint(L, 1);
    int nSpellLevel = luaL_checkint(L, 2);

    StackPushInteger(nSpellLevel);
    StackPushInteger(nClass);
    VM_ExecuteCommand(629, 2);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyCastSpell(lua_State *L)
{
    int nSpell = luaL_checkint(L, 1);
    int nNumUses = luaL_checkint(L, 2);

    StackPushInteger(nNumUses);
    StackPushInteger(nSpell);
    VM_ExecuteCommand(630, 2);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyDamageBonus(lua_State *L)
{
    int nDamageType = luaL_checkint(L, 1);
    int nDamage = luaL_checkint(L, 2);

    StackPushInteger(nDamage);
    StackPushInteger(nDamageType);
    VM_ExecuteCommand(631, 2);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyDamageBonusVsAlign(lua_State *L)
{
    int nAlignGroup = luaL_checkint(L, 1);
    int nDamageType = luaL_checkint(L, 2);
    int nDamage = luaL_checkint(L, 3);

    StackPushInteger(nDamage);
    StackPushInteger(nDamageType);
    StackPushInteger(nAlignGroup);
    VM_ExecuteCommand(632, 3);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyDamageBonusVsRace(lua_State *L)
{
    int nRace = luaL_checkint(L, 1);
    int nDamageType = luaL_checkint(L, 2);
    int nDamage = luaL_checkint(L, 3);

    StackPushInteger(nDamage);
    StackPushInteger(nDamageType);
    StackPushInteger(nRace);
    VM_ExecuteCommand(633, 3);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyDamageBonusVsSAlign(lua_State *L)
{
    int nAlign = luaL_checkint(L, 1);
    int nDamageType = luaL_checkint(L, 2);
    int nDamage = luaL_checkint(L, 3);

    StackPushInteger(nDamage);
    StackPushInteger(nDamageType);
    StackPushInteger(nAlign);
    VM_ExecuteCommand(634, 3);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyDamageImmunity(lua_State *L)
{
    int nImmuneBonus = luaL_checkint(L, 1);
    int nDamageType = luaL_checkint(L, 2);

    StackPushInteger(nImmuneBonus);
    StackPushInteger(nDamageType);
    VM_ExecuteCommand(635, 2);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyDamagePenalty(lua_State *L)
{
    int nPenalty = luaL_checkint(L, 1);

    StackPushInteger(nPenalty);
    VM_ExecuteCommand(636, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyDamageReduction(lua_State *L)
{
    int nEnhancement = luaL_checkint(L, 1);
    int nHPSoak = luaL_checkint(L, 2);

    StackPushInteger(nHPSoak);
    StackPushInteger(nEnhancement);
    VM_ExecuteCommand(637, 2);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyDamageResistance(lua_State *L)
{
    int nDamageType = luaL_checkint(L, 1);
    int nHPResist = luaL_checkint(L, 2);

    StackPushInteger(nHPResist);
    StackPushInteger(nDamageType);
    VM_ExecuteCommand(638, 2);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyDamageVulnerability(lua_State *L)
{
    int nDamageType = luaL_checkint(L, 1);
    int nVulnerability = luaL_checkint(L, 2);

    StackPushInteger(nVulnerability);
    StackPushInteger(nDamageType);
    VM_ExecuteCommand(639, 2);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyDarkvision(lua_State *L)
{
    VM_ExecuteCommand(640, 0);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyDecreaseAbility(lua_State *L)
{
    int nAbility = luaL_checkint(L, 1);
    int nModifier = luaL_checkint(L, 2);

    StackPushInteger(nModifier);
    StackPushInteger(nAbility);
    VM_ExecuteCommand(641, 2);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyDecreaseAC(lua_State *L)
{
    int nModifierType = luaL_checkint(L, 1);
    int nPenalty = luaL_checkint(L, 2);

    StackPushInteger(nPenalty);
    StackPushInteger(nModifierType);
    VM_ExecuteCommand(642, 2);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyDecreaseSkill(lua_State *L)
{
    int nSkill = luaL_checkint(L, 1);
    int nPenalty = luaL_checkint(L, 2);

    StackPushInteger(nPenalty);
    StackPushInteger(nSkill);
    VM_ExecuteCommand(643, 2);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyContainerReducedWeight(lua_State *L)
{
    int nContainerType = luaL_checkint(L, 1);

    StackPushInteger(nContainerType);
    VM_ExecuteCommand(644, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyExtraMeleeDamageType(lua_State *L)
{
    int nDamageType = luaL_checkint(L, 1);

    StackPushInteger(nDamageType);
    VM_ExecuteCommand(645, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyExtraRangeDamageType(lua_State *L)
{
    int nDamageType = luaL_checkint(L, 1);

    StackPushInteger(nDamageType);
    VM_ExecuteCommand(646, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyHaste(lua_State *L)
{
    VM_ExecuteCommand(647, 0);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyHolyAvenger(lua_State *L)
{
    VM_ExecuteCommand(648, 0);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyImmunityMisc(lua_State *L)
{
    int nImmunityType = luaL_checkint(L, 1);

    StackPushInteger(nImmunityType);
    VM_ExecuteCommand(649, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyImprovedEvasion(lua_State *L)
{
    VM_ExecuteCommand(650, 0);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyBonusSpellResistance(lua_State *L)
{
    int nBonus = luaL_checkint(L, 1);

    StackPushInteger(nBonus);
    VM_ExecuteCommand(651, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyBonusSavingThrowVsX(lua_State *L)
{
    int nBonusType = luaL_checkint(L, 1);
    int nBonus = luaL_checkint(L, 2);

    StackPushInteger(nBonus);
    StackPushInteger(nBonusType);
    VM_ExecuteCommand(652, 2);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyBonusSavingThrow(lua_State *L)
{
    int nBaseSaveType = luaL_checkint(L, 1);
    int nBonus = luaL_checkint(L, 2);

    StackPushInteger(nBonus);
    StackPushInteger(nBaseSaveType);
    VM_ExecuteCommand(653, 2);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyKeen(lua_State *L)
{
    VM_ExecuteCommand(654, 0);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyLight(lua_State *L)
{
    int nBrightness = luaL_checkint(L, 1);
    int nColor = luaL_checkint(L, 2);

    StackPushInteger(nColor);
    StackPushInteger(nBrightness);
    VM_ExecuteCommand(655, 2);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyMaxRangeStrengthMod(lua_State *L)
{
    int nModifier = luaL_checkint(L, 1);

    StackPushInteger(nModifier);
    VM_ExecuteCommand(656, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyNoDamage(lua_State *L)
{
    VM_ExecuteCommand(657, 0);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyOnHitProps(lua_State *L)
{
    int nProperty = luaL_checkint(L, 1);
    int nSaveDC = luaL_checkint(L, 2);
    int nSpecial = luaL_optint(L, 3, 0);

    StackPushInteger(nSpecial);
    StackPushInteger(nSaveDC);
    StackPushInteger(nProperty);
    VM_ExecuteCommand(658, 3);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyReducedSavingThrowVsX(lua_State *L)
{
    int nBaseSaveType = luaL_checkint(L, 1);
    int nPenalty = luaL_checkint(L, 2);

    StackPushInteger(nPenalty);
    StackPushInteger(nBaseSaveType);
    VM_ExecuteCommand(659, 2);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyReducedSavingThrow(lua_State *L)
{
    int nBonusType = luaL_checkint(L, 1);
    int nPenalty = luaL_checkint(L, 2);

    StackPushInteger(nPenalty);
    StackPushInteger(nBonusType);
    VM_ExecuteCommand(660, 2);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyRegeneration(lua_State *L)
{
    int nRegenAmount = luaL_checkint(L, 1);

    StackPushInteger(nRegenAmount);
    VM_ExecuteCommand(661, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertySkillBonus(lua_State *L)
{
    int nSkill = luaL_checkint(L, 1);
    int nBonus = luaL_checkint(L, 2);

    StackPushInteger(nBonus);
    StackPushInteger(nSkill);
    VM_ExecuteCommand(662, 2);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertySpellImmunitySpecific(lua_State *L)
{
    int nSpell = luaL_checkint(L, 1);

    StackPushInteger(nSpell);
    VM_ExecuteCommand(663, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertySpellImmunitySchool(lua_State *L)
{
    int nSchool = luaL_checkint(L, 1);

    StackPushInteger(nSchool);
    VM_ExecuteCommand(664, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyThievesTools(lua_State *L)
{
    int nModifier = luaL_checkint(L, 1);

    StackPushInteger(nModifier);
    VM_ExecuteCommand(665, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyAttackBonus(lua_State *L)
{
    int nBonus = luaL_checkint(L, 1);

    StackPushInteger(nBonus);
    VM_ExecuteCommand(666, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyAttackBonusVsAlign(lua_State *L)
{
    int nAlignGroup = luaL_checkint(L, 1);
    int nBonus = luaL_checkint(L, 2);

    StackPushInteger(nBonus);
    StackPushInteger(nAlignGroup);
    VM_ExecuteCommand(667, 2);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyAttackBonusVsRace(lua_State *L)
{
    int nRace = luaL_checkint(L, 1);
    int nBonus = luaL_checkint(L, 2);

    StackPushInteger(nBonus);
    StackPushInteger(nRace);
    VM_ExecuteCommand(668, 2);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyAttackBonusVsSAlign(lua_State *L)
{
    int nAlignment = luaL_checkint(L, 1);
    int nBonus = luaL_checkint(L, 2);

    StackPushInteger(nBonus);
    StackPushInteger(nAlignment);
    VM_ExecuteCommand(669, 2);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyAttackPenalty(lua_State *L)
{
    int nPenalty = luaL_checkint(L, 1);

    StackPushInteger(nPenalty);
    VM_ExecuteCommand(670, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyUnlimitedAmmo(lua_State *L)
{
    int nAmmoDamage = luaL_optint(L, 1, IP_CONST_UNLIMITEDAMMO_BASIC);

    StackPushInteger(nAmmoDamage);
    VM_ExecuteCommand(671, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyLimitUseByAlign(lua_State *L)
{
    int nAlignGroup = luaL_checkint(L, 1);

    StackPushInteger(nAlignGroup);
    VM_ExecuteCommand(672, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyLimitUseByClass(lua_State *L)
{
    int nClass = luaL_checkint(L, 1);

    StackPushInteger(nClass);
    VM_ExecuteCommand(673, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyLimitUseByRace(lua_State *L)
{
    int nRace = luaL_checkint(L, 1);

    StackPushInteger(nRace);
    VM_ExecuteCommand(674, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyLimitUseBySAlign(lua_State *L)
{
    int nAlignment = luaL_checkint(L, 1);

    StackPushInteger(nAlignment);
    VM_ExecuteCommand(675, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_BadBadReplaceMeThisDoesNothing(lua_State *L)
{
    VM_ExecuteCommand(676, 0);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyVampiricRegeneration(lua_State *L)
{
    int nRegenAmount = luaL_checkint(L, 1);

    StackPushInteger(nRegenAmount);
    VM_ExecuteCommand(677, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyTrap(lua_State *L)
{
    int nTrapLevel = luaL_checkint(L, 1);
    int nTrapType = luaL_checkint(L, 2);

    StackPushInteger(nTrapType);
    StackPushInteger(nTrapLevel);
    VM_ExecuteCommand(678, 2);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyTrueSeeing(lua_State *L)
{
    VM_ExecuteCommand(679, 0);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyOnMonsterHitProperties(lua_State *L)
{
    int nProperty = luaL_checkint(L, 1);
    int nSpecial = luaL_optint(L, 2, 0);

    StackPushInteger(nSpecial);
    StackPushInteger(nProperty);
    VM_ExecuteCommand(680, 2);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyTurnResistance(lua_State *L)
{
    int nModifier = luaL_checkint(L, 1);

    StackPushInteger(nModifier);
    VM_ExecuteCommand(681, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyMassiveCritical(lua_State *L)
{
    int nDamage = luaL_checkint(L, 1);

    StackPushInteger(nDamage);
    VM_ExecuteCommand(682, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyFreeAction(lua_State *L)
{
    VM_ExecuteCommand(683, 0);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyMonsterDamage(lua_State *L)
{
    int nDamage = luaL_checkint(L, 1);

    StackPushInteger(nDamage);
    VM_ExecuteCommand(684, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyImmunityToSpellLevel(lua_State *L)
{
    int nLevel = luaL_checkint(L, 1);

    StackPushInteger(nLevel);
    VM_ExecuteCommand(685, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertySpecialWalk(lua_State *L)
{
    int nWalkType = luaL_optint(L, 1, 0);

    StackPushInteger(nWalkType);
    VM_ExecuteCommand(686, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyHealersKit(lua_State *L)
{
    int nModifier = luaL_checkint(L, 1);

    StackPushInteger(nModifier);
    VM_ExecuteCommand(687, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyWeightIncrease(lua_State *L)
{
    int nWeight = luaL_checkint(L, 1);

    StackPushInteger(nWeight);
    VM_ExecuteCommand(688, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_GetIsSkillSuccessful(lua_State *L)
{
    dword oTarget = luaL_checkint(L, 1);
    int nSkill = luaL_checkint(L, 2);
    int nDifficulty = luaL_checkint(L, 3);

    StackPushInteger(nDifficulty);
    StackPushInteger(nSkill);
    StackPushObject(oTarget);
    VM_ExecuteCommand(689, 3);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_EffectSpellFailure(lua_State *L)
{
    int nPercent = luaL_optint(L, 1, 100);
    int nSpellSchool = luaL_optint(L, 2, SPELL_SCHOOL_GENERAL);

    StackPushInteger(nSpellSchool);
    StackPushInteger(nPercent);
    VM_ExecuteCommand(690, 2);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_SpeakStringByStrRef(lua_State *L)
{
    int nStrRef = luaL_checkint(L, 1);
    int nTalkVolume = luaL_optint(L, 2, TALKVOLUME_TALK);

    StackPushInteger(nTalkVolume);
    StackPushInteger(nStrRef);
    VM_ExecuteCommand(691, 2);
    return 0;
}

static int NWScript_SetCutsceneMode(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);
    int nInCutscene = luaL_optboolean(L, 2, TRUE);
    int nLeftClickingEnabled = luaL_optboolean(L, 3, FALSE);

    StackPushInteger(nLeftClickingEnabled);
    StackPushInteger(nInCutscene);
    StackPushObject(oCreature);
    VM_ExecuteCommand(692, 3);
    return 0;
}

static int NWScript_GetLastPCToCancelCutscene(lua_State *L)
{
    VM_ExecuteCommand(693, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetDialogSoundLength(lua_State *L)
{
    int nStrRef = luaL_checkint(L, 1);

    StackPushInteger(nStrRef);
    VM_ExecuteCommand(694, 1);
    float fRetVal;
    StackPopFloat(&fRetVal);
    lua_pushnumber(L, fRetVal);
    return 1;
}

static int NWScript_FadeFromBlack(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);
    double fSpeed = luaL_optnumber(L, 2, FADE_SPEED_MEDIUM);

    StackPushFloat(fSpeed);
    StackPushObject(oCreature);
    VM_ExecuteCommand(695, 2);
    return 0;
}

static int NWScript_FadeToBlack(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);
    double fSpeed = luaL_optnumber(L, 2, FADE_SPEED_MEDIUM);

    StackPushFloat(fSpeed);
    StackPushObject(oCreature);
    VM_ExecuteCommand(696, 2);
    return 0;
}

static int NWScript_StopFade(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);

    StackPushObject(oCreature);
    VM_ExecuteCommand(697, 1);
    return 0;
}

static int NWScript_BlackScreen(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);

    StackPushObject(oCreature);
    VM_ExecuteCommand(698, 1);
    return 0;
}

static int NWScript_GetBaseAttackBonus(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);

    StackPushObject(oCreature);
    VM_ExecuteCommand(699, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_SetImmortal(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);
    int bImmortal = luaL_checkboolean(L, 2);

    StackPushInteger(bImmortal);
    StackPushObject(oCreature);
    VM_ExecuteCommand(700, 2);
    return 0;
}

static int NWScript_OpenInventory(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);
    dword oPlayer = luaL_checkint(L, 2);

    StackPushObject(oPlayer);
    StackPushObject(oCreature);
    VM_ExecuteCommand(701, 2);
    return 0;
}

static int NWScript_StoreCameraFacing(lua_State *L)
{
    VM_ExecuteCommand(702, 0);
    return 0;
}

static int NWScript_RestoreCameraFacing(lua_State *L)
{
    VM_ExecuteCommand(703, 0);
    return 0;
}

static int NWScript_LevelUpHenchman(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);
    int nClass  = luaL_optint(L, 2, CLASS_TYPE_INVALID);
    int bReadyAllSpells  = luaL_optboolean(L, 3, FALSE);
    int nPackage  = luaL_optint(L, 4, PACKAGE_INVALID);

    StackPushInteger(nPackage);
    StackPushInteger(bReadyAllSpells);
    StackPushInteger(nClass);
    StackPushObject(oCreature);
    VM_ExecuteCommand(704, 4);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_SetDroppableFlag(lua_State *L)
{
    dword oItem = luaL_checkint(L, 1);
    int bDroppable = luaL_checkboolean(L, 2);

    StackPushInteger(bDroppable);
    StackPushObject(oItem);
    VM_ExecuteCommand(705, 2);
    return 0;
}

static int NWScript_GetWeight(lua_State *L)
{
    dword oTarget = luaL_optint(L, 1, OBJECT_SELF);

    StackPushObject(oTarget);
    VM_ExecuteCommand(706, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetModuleItemAcquiredBy(lua_State *L)
{
    VM_ExecuteCommand(707, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetImmortal(lua_State *L)
{
    dword oTarget = luaL_optint(L, 1, OBJECT_SELF);

    StackPushObject(oTarget);
    VM_ExecuteCommand(708, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_DoWhirlwindAttack(lua_State *L)
{
    int bDisplayFeedback = luaL_optboolean(L, 1, TRUE);
    int bImproved = luaL_optboolean(L, 2, FALSE);

    StackPushInteger(bImproved);
    StackPushInteger(bDisplayFeedback);
    VM_ExecuteCommand(709, 2);
    return 0;
}

static int NWScript_Get2DAString(lua_State *L)
{
    char *s2DA = (char *)luaL_checkstring(L, 1);
    char *sColumn = (char *)luaL_checkstring(L, 2);
    int nRow = luaL_checkint(L, 3);

    StackPushInteger(nRow);
    StackPushString(sColumn);
    StackPushString(s2DA);
    VM_ExecuteCommand(710, 3);
    char *sRetVal;
    StackPopString(&sRetVal);
    lua_pushstring(L, sRetVal);
    return 1;
}

static int NWScript_EffectEthereal(lua_State *L)
{
    VM_ExecuteCommand(711, 0);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_GetAILevel(lua_State *L)
{
    dword oTarget = luaL_optint(L, 1, OBJECT_SELF);

    StackPushObject(oTarget);
    VM_ExecuteCommand(712, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_SetAILevel(lua_State *L)
{
    dword oTarget = luaL_checkint(L, 1);
    int nAILevel = luaL_checkint(L, 2);

    StackPushInteger(nAILevel);
    StackPushObject(oTarget);
    VM_ExecuteCommand(713, 2);
    return 0;
}

static int NWScript_GetIsPossessedFamiliar(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);

    StackPushObject(oCreature);
    VM_ExecuteCommand(714, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_UnpossessFamiliar(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);
    StackPushObject(oCreature);
    VM_ExecuteCommand(715, 1);
    return 0;
}

static int NWScript_GetIsAreaInterior(lua_State *L)
{
    dword oArea  = luaL_optint(L, 1, OBJECT_INVALID);

    StackPushObject(oArea);
    VM_ExecuteCommand(716, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_SendMessageToPCByStrRef(lua_State *L)
{
    dword oPlayer = luaL_checkint(L, 1);
    int nStrRef = luaL_checkint(L, 2);

    StackPushInteger(nStrRef);
    StackPushObject(oPlayer);
    VM_ExecuteCommand(717, 2);
    return 0;
}

static int NWScript_IncrementRemainingFeatUses(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);
    int nFeat = luaL_checkint(L, 2);

    StackPushInteger(nFeat);
    StackPushObject(oCreature);
    VM_ExecuteCommand(718, 2);
    return 0;
}

static int NWScript_ExportSingleCharacter(lua_State *L)
{
    dword oPlayer = luaL_checkint(L, 1);

    StackPushObject(oPlayer);
    VM_ExecuteCommand(719, 1);
    return 0;
}

static int NWScript_PlaySoundByStrRef(lua_State *L)
{
    int nStrRef = luaL_checkint(L, 1);
    int nRunAsAction  = luaL_optboolean(L, 2, TRUE);

    StackPushInteger(nRunAsAction);
    StackPushInteger(nStrRef);
    VM_ExecuteCommand(720, 2);
    return 0;
}

static int NWScript_SetSubRace(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);
    char *sSubRace = (char *)luaL_checkstring(L, 2);

    StackPushString(sSubRace);
    StackPushObject(oCreature);
    VM_ExecuteCommand(721, 2);
    return 0;
}

static int NWScript_SetDeity(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);
    char *sDeity = (char *)luaL_checkstring(L, 2);

    StackPushString(sDeity);
    StackPushObject(oCreature);
    VM_ExecuteCommand(722, 2);
    return 0;
}

static int NWScript_GetIsDMPossessed(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);

    StackPushObject(oCreature);
    VM_ExecuteCommand(723, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_GetWeather(lua_State *L)
{
    dword oArea = luaL_checkint(L, 1);

    StackPushObject(oArea);
    VM_ExecuteCommand(724, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetIsAreaNatural(lua_State *L)
{
    dword oArea = luaL_checkint(L, 1);

    StackPushObject(oArea);
    VM_ExecuteCommand(725, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_GetIsAreaAboveGround(lua_State *L)
{
    dword oArea = luaL_checkint(L, 1);

    StackPushObject(oArea);
    VM_ExecuteCommand(726, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_GetPCItemLastEquipped(lua_State *L)
{
    VM_ExecuteCommand(727, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetPCItemLastEquippedBy(lua_State *L)
{
    VM_ExecuteCommand(728, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetPCItemLastUnequipped(lua_State *L)
{
    VM_ExecuteCommand(729, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetPCItemLastUnequippedBy(lua_State *L)
{
    VM_ExecuteCommand(730, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_CopyItemAndModify(lua_State *L)
{
    dword oItem = luaL_checkint(L, 1);
    int nType = luaL_checkint(L, 2);
    int nIndex = luaL_checkint(L, 3);
    int nNewValue = luaL_checkint(L, 4);
    int bCopyVars = luaL_optboolean(L, 5, FALSE);

    StackPushInteger(bCopyVars);
    StackPushInteger(nNewValue);
    StackPushInteger(nIndex);
    StackPushInteger(nType);
    StackPushObject(oItem);
    VM_ExecuteCommand(731, 5);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetItemAppearance(lua_State *L)
{
    dword oItem = luaL_checkint(L, 1);
    int nType = luaL_checkint(L, 2);
    int nIndex = luaL_checkint(L, 3);

    StackPushInteger(nIndex);
    StackPushInteger(nType);
    StackPushObject(oItem);
    VM_ExecuteCommand(732, 3);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_ItemPropertyOnHitCastSpell(lua_State *L)
{
    int nSpell = luaL_checkint(L, 1);
    int nLevel = luaL_checkint(L, 2);

    StackPushInteger(nLevel);
    StackPushInteger(nSpell);
    VM_ExecuteCommand(733, 2);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_GetItemPropertySubType(lua_State *L)
{
    void *iProperty = luaL_checklightnwndata(L, 1, ITEMPROPERTY);

    StackPushEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, iProperty);
    VM_ExecuteCommand(734, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetActionMode(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);
    int nMode = luaL_checkint(L, 2);

    StackPushInteger(nMode);
    StackPushObject(oCreature);
    VM_ExecuteCommand(735, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_SetActionMode(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);
    int nMode = luaL_checkint(L, 2);
    int nStatus = luaL_checkboolean(L, 3);

    StackPushInteger(nStatus);
    StackPushInteger(nMode);
    StackPushObject(oCreature);
    VM_ExecuteCommand(736, 3);
    return 0;
}

static int NWScript_GetArcaneSpellFailure(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);

    StackPushObject(oCreature);
    VM_ExecuteCommand(737, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_ActionExamine(lua_State *L)
{
    dword oExamine = luaL_checkint(L, 1);

    StackPushObject(oExamine);
    VM_ExecuteCommand(738, 1);
    return 0;
}

static int NWScript_ItemPropertyVisualEffect(lua_State *L)
{
    int nEffect = luaL_checkint(L, 1);

    StackPushInteger(nEffect);
    VM_ExecuteCommand(739, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_SetLootable(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);
    int bLootable = luaL_checkboolean(L, 2);

    StackPushInteger(bLootable);
    StackPushObject(oCreature);
    VM_ExecuteCommand(740, 2);
    return 0;
}

static int NWScript_GetLootable(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);

    StackPushObject(oCreature);
    VM_ExecuteCommand(741, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_GetCutsceneCameraMoveRate(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);

    StackPushObject(oCreature);
    VM_ExecuteCommand(742, 1);
    float fRetVal;
    StackPopFloat(&fRetVal);
    lua_pushnumber(L, fRetVal);
    return 1;
}

static int NWScript_SetCutsceneCameraMoveRate(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);
    double fRate = luaL_checknumber(L, 2);

    StackPushFloat(fRate);
    StackPushObject(oCreature);
    VM_ExecuteCommand(743, 2);
    return 0;
}

static int NWScript_GetItemCursedFlag(lua_State *L)
{
    dword oItem = luaL_checkint(L, 1);

    StackPushObject(oItem);
    VM_ExecuteCommand(744, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}
static int NWScript_SetItemCursedFlag(lua_State *L)
{
    dword oItem = luaL_checkint(L, 1);
    int nCursed = luaL_checkint(L, 2);

    StackPushInteger(nCursed);
    StackPushObject(oItem);
    VM_ExecuteCommand(745, 2);
    return 0;
}

static int NWScript_SetMaxHenchmen(lua_State *L)
{
    int nNumHenchmen = luaL_checkint(L, 1);

    StackPushInteger(nNumHenchmen);
    VM_ExecuteCommand(746, 1);
    return 0;
}

static int NWScript_GetMaxHenchmen(lua_State *L)
{
    VM_ExecuteCommand(747, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetAssociateType(lua_State *L)
{
    dword oAssociate = luaL_checkint(L, 1);

    StackPushObject(oAssociate);
    VM_ExecuteCommand(748, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetSpellResistance(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);

    StackPushObject(oCreature);
    VM_ExecuteCommand(749, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_DayToNight(lua_State *L)
{
    dword oPlayer = luaL_checkint(L, 1);
    double fTransitionTime = luaL_optnumber(L, 2, 0.0);

    StackPushFloat(fTransitionTime);
    StackPushObject(oPlayer);
    VM_ExecuteCommand(750, 2);
    return 0;
}

static int NWScript_NightToDay(lua_State *L)
{
    dword oPlayer = luaL_checkint(L, 1);
    double fTransitionTime = luaL_optnumber(L, 2, 0.0);

    StackPushFloat(fTransitionTime);
    StackPushObject(oPlayer);
    VM_ExecuteCommand(751, 2);
    return 0;
}

static int NWScript_LineOfSightObject(lua_State *L)
{
    dword oSource = luaL_checkint(L, 1);
    dword oTarget = luaL_checkint(L, 2);

    StackPushObject(oTarget);
    StackPushObject(oSource);
    VM_ExecuteCommand(752, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_LineOfSightVector(lua_State *L)
{
    Vector *vSource = (Vector *)luaL_checkudata(L, 1, VECTOR);
    Vector *vTarget = (Vector *)luaL_checkudata(L, 2, VECTOR);

    StackPushVector(*vTarget);
    StackPushVector(*vSource);
    VM_ExecuteCommand(753, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_GetLastSpellCastClass(lua_State *L)
{
    VM_ExecuteCommand(754, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_SetBaseAttackBonus(lua_State *L)
{
    int nBaseAttackBonus = luaL_checkint(L, 1);
    dword oCreature  = luaL_optint(L, 2, OBJECT_SELF);

    StackPushObject(oCreature);
    StackPushInteger(nBaseAttackBonus);
    VM_ExecuteCommand(755, 2);
    return 0;
}

static int NWScript_RestoreBaseAttackBonus(lua_State *L)
{
    dword oCreature = luaL_optint(L, 1, OBJECT_SELF);

    StackPushObject(oCreature);
    VM_ExecuteCommand(756, 1);
    return 0;
}

static int NWScript_EffectCutsceneGhost(lua_State *L)
{
    VM_ExecuteCommand(757, 0);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyArcaneSpellFailure(lua_State *L)
{
    int nModLevel = luaL_checkint(L, 1);

    StackPushInteger(nModLevel);
    VM_ExecuteCommand(758, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_GetStoreGold(lua_State *L)
{
    dword oidStore = luaL_checkint(L, 1);

    StackPushObject(oidStore);
    VM_ExecuteCommand(759, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_SetStoreGold(lua_State *L)
{
    dword oidStore = luaL_checkint(L, 1);
    int nGold = luaL_checkint(L, 2);

    StackPushInteger(nGold);
    StackPushObject(oidStore);
    VM_ExecuteCommand(760, 2);
    return 0;
}

static int NWScript_GetStoreMaxBuyPrice(lua_State *L)
{
    dword oidStore = luaL_checkint(L, 1);

    StackPushObject(oidStore);
    VM_ExecuteCommand(761, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_SetStoreMaxBuyPrice(lua_State *L)
{
    dword oidStore = luaL_checkint(L, 1);
    int nMaxBuy = luaL_checkint(L, 2);

    StackPushInteger(nMaxBuy);
    StackPushObject(oidStore);
    VM_ExecuteCommand(762, 2);
    return 0;
}

static int NWScript_GetStoreIdentifyCost(lua_State *L)
{
    dword oidStore = luaL_checkint(L, 1);

    StackPushObject(oidStore);
    VM_ExecuteCommand(763, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_SetStoreIdentifyCost(lua_State *L)
{
    dword oidStore = luaL_checkint(L, 1);
    int nCost = luaL_checkint(L, 2);

    StackPushInteger(nCost);
    StackPushObject(oidStore);
    VM_ExecuteCommand(764, 2);
    return 0;
}

static int NWScript_SetCreatureAppearanceType(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);
    int nAppearanceType = luaL_checkint(L, 2);

    StackPushInteger(nAppearanceType);
    StackPushObject(oCreature);
    VM_ExecuteCommand(765, 2);
    return 0;
}

static int NWScript_GetCreatureStartingPackage(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);

    StackPushObject(oCreature);
    VM_ExecuteCommand(766, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_EffectCutsceneImmobilize(lua_State *L)
{
    VM_ExecuteCommand(767, 0);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_GetIsInSubArea(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);
    dword oSubArea = luaL_optint(L, 2, OBJECT_SELF);

    StackPushObject(oSubArea);
    StackPushObject(oCreature);
    VM_ExecuteCommand(768, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_GetItemPropertyCostTable(lua_State *L)
{
    void *iProp = luaL_checklightnwndata(L, 1, ITEMPROPERTY);

    StackPushEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, iProp);
    VM_ExecuteCommand(769, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetItemPropertyCostTableValue(lua_State *L)
{
    void *iProp = luaL_checklightnwndata(L, 1, ITEMPROPERTY);

    StackPushEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, iProp);
    VM_ExecuteCommand(770, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetItemPropertyParam1(lua_State *L)
{
    void *iProp = luaL_checklightnwndata(L, 1, ITEMPROPERTY);

    StackPushEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, iProp);
    VM_ExecuteCommand(771, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetItemPropertyParam1Value(lua_State *L)
{
    void *iProp = luaL_checklightnwndata(L, 1, ITEMPROPERTY);

    StackPushEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, iProp);
    VM_ExecuteCommand(772, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetIsCreatureDisarmable(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);

    StackPushObject(oCreature);
    VM_ExecuteCommand(773, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_SetStolenFlag(lua_State *L)
{
    dword oItem = luaL_checkint(L, 1);
    int nStolenFlag = luaL_checkboolean(L, 2);

    StackPushInteger(nStolenFlag);
    StackPushObject(oItem);
    VM_ExecuteCommand(774, 2);
    return 0;
}

static int NWScript_ForceRest(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);

    StackPushObject(oCreature);
    VM_ExecuteCommand(775, 1);
    return 0;
}

static int NWScript_SetCameraHeight(lua_State *L)
{
    dword oPlayer = luaL_checkint(L, 1);
    double fHeight = luaL_optnumber(L, 2, 0.0);

    StackPushFloat(fHeight);
    StackPushObject(oPlayer);
    VM_ExecuteCommand(776, 2);
    return 0;
}

static int NWScript_SetSkyBox(lua_State *L)
{
    int nSkyBox = luaL_checkint(L, 1);
    dword oArea = luaL_optint(L, 2, OBJECT_INVALID);

    StackPushObject(oArea);
    StackPushInteger(nSkyBox);
    VM_ExecuteCommand(777, 2);
    return 0;
}

static int NWScript_GetPhenoType(lua_State *L)
{
    dword oCreature = luaL_checkint(L, 1);

    StackPushObject(oCreature);
    VM_ExecuteCommand(778, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_SetPhenoType(lua_State *L)
{
    int nPhenoType = luaL_checkint(L, 1);
    dword oCreature = luaL_optint(L, 2, OBJECT_SELF);

    StackPushObject(oCreature);
    StackPushInteger(nPhenoType);
    VM_ExecuteCommand(779, 2);
    return 0;
}

static int NWScript_SetFogColor(lua_State *L)
{
    int nFogType = luaL_checkint(L, 1);
    int nFogColor = luaL_checkint(L, 2);
    dword oArea = luaL_optint(L, 3, OBJECT_INVALID);

    StackPushObject(oArea);
    StackPushInteger(nFogColor);
    StackPushInteger(nFogType);
    VM_ExecuteCommand(780, 3);
    return 0;
}

static int NWScript_GetCutsceneMode(lua_State *L)
{
    dword oCreature = luaL_optint(L, 1, OBJECT_SELF);

    StackPushObject(oCreature);
    VM_ExecuteCommand(781, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetSkyBox(lua_State *L)
{
    dword oArea = luaL_optint(L, 1, OBJECT_INVALID);

    StackPushObject(oArea);
    VM_ExecuteCommand(782, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetFogColor(lua_State *L)
{
    int nFogType = luaL_checkint(L, 1);
    dword oArea = luaL_optint(L, 2, OBJECT_INVALID);

    StackPushObject(oArea);
    StackPushInteger(nFogType);
    VM_ExecuteCommand(783, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_SetFogAmount(lua_State *L)
{
    int nFogType = luaL_checkint(L, 1);
    int nFogAmount = luaL_checkint(L, 2);
    dword oArea = luaL_optint(L, 3, OBJECT_INVALID);

    StackPushObject(oArea);
    StackPushInteger(nFogAmount);
    StackPushInteger(nFogType);
    VM_ExecuteCommand(784, 3);
    return 0;
}

static int NWScript_GetFogAmount(lua_State *L)
{
    int nFogType = luaL_checkint(L, 1);
    dword oArea = luaL_optint(L, 2, OBJECT_INVALID);

    StackPushObject(oArea);
    StackPushInteger(nFogType);
    VM_ExecuteCommand(785, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetPickpocketableFlag(lua_State *L)
{
    dword oItem = luaL_checkint(L, 1);

    StackPushObject(oItem);
    VM_ExecuteCommand(786, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_SetPickpocketableFlag(lua_State *L)
{
    dword oItem = luaL_checkint(L, 1);
    int bPickpocketable = luaL_checkboolean(L, 2);

    StackPushInteger(bPickpocketable);
    StackPushObject(oItem);
    VM_ExecuteCommand(787, 2);
    return 0;
}

static int NWScript_GetFootstepType(lua_State *L)
{
    dword oCreature = luaL_optint(L, 1, OBJECT_SELF);

    StackPushObject(oCreature);
    VM_ExecuteCommand(788, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_SetFootstepType(lua_State *L)
{
    int nFootstepType = luaL_checkint(L, 1);
    dword oCreature = luaL_optint(L, 2, OBJECT_SELF);

    StackPushObject(oCreature);
    StackPushInteger(nFootstepType);
    VM_ExecuteCommand(789, 2);
    return 0;
}

static int NWScript_GetCreatureWingType(lua_State *L)
{
    dword oCreature = luaL_optint(L, 1, OBJECT_SELF);

    StackPushObject(oCreature);
    VM_ExecuteCommand(790, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_SetCreatureWingType(lua_State *L)
{
    int nWingType = luaL_checkint(L, 1);
    dword oCreature = luaL_optint(L, 2, OBJECT_SELF);

    StackPushObject(oCreature);
    StackPushInteger(nWingType);
    VM_ExecuteCommand(791, 2);
    return 0;
}

static int NWScript_GetCreatureBodyPart(lua_State *L)
{
    int nPart = luaL_checkint(L, 1);
    dword oCreature = luaL_optint(L, 2, OBJECT_SELF);

    StackPushObject(oCreature);
    StackPushInteger(nPart);
    VM_ExecuteCommand(792, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_SetCreatureBodyPart(lua_State *L)
{
    int nPart = luaL_checkint(L, 1);
    int nModelNumber = luaL_checkint(L, 2);
    dword oCreature = luaL_optint(L, 3, OBJECT_SELF);

    StackPushObject(oCreature);
    StackPushInteger(nModelNumber);
    StackPushInteger(nPart);
    VM_ExecuteCommand(793, 3);
    return 0;
}

static int NWScript_GetCreatureTailType(lua_State *L)
{
    dword oCreature = luaL_optint(L, 1, OBJECT_SELF);

    StackPushObject(oCreature);
    VM_ExecuteCommand(794, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_SetCreatureTailType(lua_State *L)
{
    int nTailType = luaL_checkint(L, 1);
    dword oCreature = luaL_optint(L, 2, OBJECT_SELF);

    StackPushObject(oCreature);
    StackPushInteger(nTailType);
    VM_ExecuteCommand(795, 2);
    return 0;
}

static int NWScript_GetHardness(lua_State *L)
{
    dword oObject = luaL_optint(L, 1, OBJECT_SELF);

    StackPushObject(oObject);
    VM_ExecuteCommand(796, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_SetHardness(lua_State *L)
{
    int nHardness = luaL_checkint(L, 1);
    dword oObject = luaL_optint(L, 2, OBJECT_SELF);

    StackPushObject(oObject);
    StackPushInteger(nHardness);
    VM_ExecuteCommand(797, 2);
    return 0;
}

static int NWScript_SetLockKeyRequired(lua_State *L)
{
    dword oObject = luaL_checkint(L, 1);
    int nKeyRequired = luaL_optboolean(L, 2, TRUE);

    StackPushInteger(nKeyRequired);
    StackPushObject(oObject);
    VM_ExecuteCommand(798, 2);
    return 0;
}

static int NWScript_SetLockKeyTag(lua_State *L)
{
    dword oObject = luaL_checkint(L, 1);
    char *sNewKeyTag = (char *)luaL_checkstring(L, 2);

    StackPushString(sNewKeyTag);
    StackPushObject(oObject);
    VM_ExecuteCommand(799, 2);
    return 0;
}

static int NWScript_SetLockLockable(lua_State *L)
{
    dword oObject = luaL_checkint(L, 1);
    int nLockable = luaL_optboolean(L, 2, TRUE);

    StackPushInteger(nLockable);
    StackPushObject(oObject);
    VM_ExecuteCommand(800, 2);
    return 0;
}

static int NWScript_SetLockUnlockDC(lua_State *L)
{
    dword oObject = luaL_checkint(L, 1);
    int nNewUnlockDC = luaL_checkint(L, 2);

    StackPushInteger(nNewUnlockDC);
    StackPushObject(oObject);
    VM_ExecuteCommand(801, 2);
    return 0;
}

static int NWScript_SetLockLockDC(lua_State *L)
{
    dword oObject = luaL_checkint(L, 1);
    int nNewLockDC = luaL_checkint(L, 2);

    StackPushInteger(nNewLockDC);
    StackPushObject(oObject);
    VM_ExecuteCommand(802, 2);
    return 0;
}

static int NWScript_SetTrapDisarmable(lua_State *L)
{
    dword oTrapObject = luaL_checkint(L, 1);
    int nDisarmable = luaL_optboolean(L, 2, TRUE);

    StackPushInteger(nDisarmable);
    StackPushObject(oTrapObject);
    VM_ExecuteCommand(803, 2);
    return 0;
}

static int NWScript_SetTrapDetectable(lua_State *L)
{
    dword oTrapObject = luaL_checkint(L, 1);
    int nDetectable = luaL_optboolean(L, 2, TRUE);

    StackPushInteger(nDetectable);
    StackPushObject(oTrapObject);
    VM_ExecuteCommand(804, 2);
    return 0;
}

static int NWScript_SetTrapOneShot(lua_State *L)
{
    dword oTrapObject = luaL_checkint(L, 1);
    int nOneShot = luaL_optboolean(L, 2, TRUE);

    StackPushInteger(nOneShot);
    StackPushObject(oTrapObject);
    VM_ExecuteCommand(805, 2);
    return 0;
}

static int NWScript_SetTrapKeyTag(lua_State *L)
{
    dword oTrapObject = luaL_checkint(L, 1);
    char *sKeyTag = (char *)luaL_checkstring(L, 2);

    StackPushString(sKeyTag);
    StackPushObject(oTrapObject);
    VM_ExecuteCommand(806, 2);
    return 0;
}

static int NWScript_SetTrapDisarmDC(lua_State *L)
{
    dword oTrapObject = luaL_checkint(L, 1);
    int nDisarmDC = luaL_checkint(L, 2);

    StackPushInteger(nDisarmDC);
    StackPushObject(oTrapObject);
    VM_ExecuteCommand(807, 2);
    return 0;
}

static int NWScript_SetTrapDetectDC(lua_State *L)
{
    dword oTrapObject = luaL_checkint(L, 1);
    int nDetectDC = luaL_checkint(L, 2);

    StackPushInteger(nDetectDC);
    StackPushObject(oTrapObject);
    VM_ExecuteCommand(808, 2);
    return 0;
}

static int NWScript_CreateTrapAtLocation(lua_State *L)
{
    int nTrapType = luaL_checkint(L, 1);
    void *lLocation = luaL_checklightnwndata(L, 2, LOCATION);
    double fSize = luaL_optnumber(L, 3, 2.0);
    char *sTag = (char *)luaL_optstring(L, 4, "");
    int nFaction = luaL_optint(L, 5, STANDARD_FACTION_HOSTILE);
    char *sOnDisarmScript = (char *)luaL_optstring(L, 6, "");
    char *sOnTrapTriggeredScript = (char *)luaL_optstring(L, 7, "");

    StackPushString(sOnTrapTriggeredScript);
    StackPushString(sOnDisarmScript);
    StackPushInteger(nFaction);
    StackPushString(sTag);
    StackPushFloat(fSize);
    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lLocation);
    StackPushInteger(nTrapType);
    VM_ExecuteCommand(809, 7);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_CreateTrapOnObject(lua_State *L)
{
    int nTrapType = luaL_checkint(L, 1);
    dword oObject = luaL_checkint(L, 2);
    int nFaction = luaL_optint(L, 3, STANDARD_FACTION_HOSTILE);
    char *sOnDisarmScript = (char *)luaL_optstring(L, 4, "");
    char *sOnTrapTriggeredScript = (char *)luaL_optstring(L, 5, "");

    StackPushString(sOnTrapTriggeredScript);
    StackPushString(sOnDisarmScript);
    StackPushInteger(nFaction);
    StackPushObject(oObject);
    StackPushInteger(nTrapType);
    VM_ExecuteCommand(810, 5);
    return 0;
}

static int NWScript_SetWillSavingThrow(lua_State *L)
{
    dword oObject = luaL_checkint(L, 1);
    int nWillSave = luaL_checkint(L, 2);

    StackPushInteger(nWillSave);
    StackPushObject(oObject);
    VM_ExecuteCommand(811, 2);
    return 0;
}

static int NWScript_SetReflexSavingThrow(lua_State *L)
{
    dword oObject = luaL_checkint(L, 1);
    int nReflexSave = luaL_checkint(L, 2);

    StackPushInteger(nReflexSave);
    StackPushObject(oObject);
    VM_ExecuteCommand(812, 2);
    return 0;
}

static int NWScript_SetFortitudeSavingThrow(lua_State *L)
{
    dword oObject = luaL_checkint(L, 1);
    int nFortitudeSave = luaL_checkint(L, 2);

    StackPushInteger(nFortitudeSave);
    StackPushObject(oObject);
    VM_ExecuteCommand(813, 2);
    return 0;
}

static int NWScript_GetTilesetResRef(lua_State *L)
{
    dword oArea = luaL_checkint(L, 1);

    StackPushObject(oArea);
    VM_ExecuteCommand(814, 1);
    char *sRetVal;
    StackPopString(&sRetVal);
    lua_pushstring(L, sRetVal);
    return 1;
}

static int NWScript_GetTrapRecoverable(lua_State *L)
{
    dword oTrapObject = luaL_checkint(L, 1);

    StackPushObject(oTrapObject);
    VM_ExecuteCommand(815, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_SetTrapRecoverable(lua_State *L)
{
    dword oTrapObject = luaL_checkint(L, 1);
    int nRecoverable = luaL_optboolean(L, 2, TRUE);

    StackPushInteger(nRecoverable);
    StackPushObject(oTrapObject);
    VM_ExecuteCommand(816, 2);
    return 0;
}

static int NWScript_GetModuleXPScale(lua_State *L)
{
    VM_ExecuteCommand(817, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_SetModuleXPScale(lua_State *L)
{
    int nXPScale = luaL_checkint(L, 1);

    StackPushInteger(nXPScale);
    VM_ExecuteCommand(818, 1);
    return 0;
}

static int NWScript_GetKeyRequiredFeedback(lua_State *L)
{
    dword oObject = luaL_checkint(L, 1);

    StackPushObject(oObject);
    VM_ExecuteCommand(819, 1);
    char *sRetVal;
    StackPopString(&sRetVal);
    lua_pushstring(L, sRetVal);
    return 1;
}

static int NWScript_SetKeyRequiredFeedback(lua_State *L)
{
    dword oObject = luaL_checkint(L, 1);
    char *sFeedbackMessage = (char *)luaL_checkstring(L, 2);

    StackPushString(sFeedbackMessage);
    StackPushObject(oObject);
    VM_ExecuteCommand(820, 2);
    return 0;
}

static int NWScript_GetTrapActive(lua_State *L)
{
    dword oTrapObject = luaL_checkint(L, 1);

    StackPushObject(oTrapObject);
    VM_ExecuteCommand(821, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_SetTrapActive(lua_State *L)
{
    dword oTrapObject = luaL_checkint(L, 1);
    int nActive = luaL_optboolean(L, 2, TRUE);

    StackPushInteger(nActive);
    StackPushObject(oTrapObject);
    VM_ExecuteCommand(822, 2);
    return 0;
}

static int NWScript_LockCameraPitch(lua_State *L)
{
    dword oPlayer = luaL_checkint(L, 1);
    int bLocked = luaL_optboolean(L, 2, TRUE);

    StackPushInteger(bLocked);
    StackPushObject(oPlayer);
    VM_ExecuteCommand(823, 2);
    return 0;
}

static int NWScript_LockCameraDistance(lua_State *L)
{
    dword oPlayer = luaL_checkint(L, 1);
    int bLocked = luaL_optboolean(L, 2, TRUE);

    StackPushInteger(bLocked);
    StackPushObject(oPlayer);
    VM_ExecuteCommand(824, 2);
    return 0;
}

static int NWScript_LockCameraDirection(lua_State *L)
{
    dword oPlayer = luaL_checkint(L, 1);
    int bLocked = luaL_optboolean(L, 2, TRUE);

    StackPushInteger(bLocked);
    StackPushObject(oPlayer);
    VM_ExecuteCommand(825, 2);
    return 0;
}

static int NWScript_GetPlaceableLastClickedBy(lua_State *L)
{
    VM_ExecuteCommand(826, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetInfiniteFlag(lua_State *L)
{
    dword oItem = luaL_checkint(L, 1);

    StackPushObject(oItem);
    VM_ExecuteCommand(827, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushboolean(L, nRetVal);
    return 1;
}

static int NWScript_SetInfiniteFlag(lua_State *L)
{
    dword oItem = luaL_checkint(L, 1);
    int bInfinite = luaL_optboolean(L, 2, TRUE);

    StackPushInteger(bInfinite);
    StackPushObject(oItem);
    VM_ExecuteCommand(828, 2);
    return 0;
}

static int NWScript_GetAreaSize(lua_State *L)
{
    int nAreaDimension = luaL_checkint(L, 1);
    dword oArea = luaL_optint(L, 2, OBJECT_INVALID);

    StackPushObject(oArea);
    StackPushInteger(nAreaDimension);
    VM_ExecuteCommand(829, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_SetName(lua_State *L)
{
    dword oObject = luaL_checkint(L, 1);
    char *sNewName = (char *)luaL_optstring(L, 2, "");

    StackPushString(sNewName);
    StackPushObject(oObject);
    VM_ExecuteCommand(830, 2);
    return 0;
}

static int NWScript_GetPortraitId(lua_State *L)
{
    dword oTarget = luaL_optint(L, 1, OBJECT_SELF);

    StackPushObject(oTarget);
    VM_ExecuteCommand(831, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_SetPortraitId(lua_State *L)
{
    dword oTarget = luaL_checkint(L, 1);
    int nPortraitId = luaL_checkint(L, 2);

    StackPushInteger(nPortraitId);
    StackPushObject(oTarget);
    VM_ExecuteCommand(832, 2);
    return 0;
}

static int NWScript_GetPortraitResRef(lua_State *L)
{
    dword oTarget = luaL_optint(L, 1, OBJECT_SELF);

    StackPushObject(oTarget);
    VM_ExecuteCommand(833, 1);
    char *sRetVal;
    StackPopString(&sRetVal);
    lua_pushstring(L, sRetVal);
    return 1;
}

static int NWScript_SetPortraitResRef(lua_State *L)
{
    dword oTarget = luaL_checkint(L, 1);
    char *sPortraitResRef = (char *)luaL_checkstring(L, 2);

    StackPushString(sPortraitResRef);
    StackPushObject(oTarget);
    VM_ExecuteCommand(834, 2);
    return 0;
}

static int NWScript_SetUseableFlag(lua_State *L)
{
    dword oPlaceable = luaL_checkint(L, 1);
    int nUseableFlag = luaL_checkboolean(L, 2);

    StackPushInteger(nUseableFlag);
    StackPushObject(oPlaceable);
    VM_ExecuteCommand(835, 2);
    return 0;
}

static int NWScript_GetDescription(lua_State *L)
{
    dword oObject = luaL_checkint(L, 1);
    int bOriginalDescription = luaL_optboolean(L, 2, FALSE);
    int bIdentifiedDescription = luaL_optboolean(L, 3, TRUE);

    StackPushInteger(bIdentifiedDescription);
    StackPushInteger(bOriginalDescription);
    StackPushObject(oObject);
    VM_ExecuteCommand(836, 3);
    char *sRetVal;
    StackPopString(&sRetVal);
    lua_pushstring(L, sRetVal);
    return 1;
}

static int NWScript_SetDescription(lua_State *L)
{
    dword oObject = luaL_checkint(L, 1);
    char *sNewDescription = (char *)luaL_optstring(L, 2, "");
    int bIdentifiedDescription = luaL_optboolean(L, 3, TRUE);

    StackPushInteger(bIdentifiedDescription);
    StackPushString(sNewDescription);
    StackPushObject(oObject);
    VM_ExecuteCommand(837, 3);
    return 0;
}

static int NWScript_GetPCChatSpeaker(lua_State *L)
{
    VM_ExecuteCommand(838, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_GetPCChatMessage(lua_State *L)
{
    VM_ExecuteCommand(839, 0);
    char *sRetVal;
    StackPopString(&sRetVal);
    lua_pushstring(L, sRetVal);
    return 1;
}

static int NWScript_GetPCChatVolume(lua_State *L)
{
    VM_ExecuteCommand(840, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_SetPCChatMessage(lua_State *L)
{
    char *sNewChatMessage = (char *)luaL_optstring(L, 1, "");

    StackPushString(sNewChatMessage);
    VM_ExecuteCommand(841, 1);
    return 0;
}

static int NWScript_SetPCChatVolume(lua_State *L)
{
    int nTalkVolume = luaL_optint(L, 1, TALKVOLUME_TALK);

    StackPushInteger(nTalkVolume);
    VM_ExecuteCommand(842, 1);
    return 0;
}

static int NWScript_GetColor(lua_State *L)
{
    dword oObject = luaL_checkint(L, 1);
    int nColorChannel = luaL_checkint(L, 2);

    StackPushInteger(nColorChannel);
    StackPushObject(oObject);
    VM_ExecuteCommand(843, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    lua_pushinteger(L, nRetVal);
    return 1;
}

static int NWScript_SetColor(lua_State *L)
{
    dword oObject = luaL_checkint(L, 1);
    int nColorChannel = luaL_checkint(L, 2);
    int nColorValue = luaL_checkint(L, 3);

    StackPushInteger(nColorValue);
    StackPushInteger(nColorChannel);
    StackPushObject(oObject);
    VM_ExecuteCommand(844, 3);
    return 0;
}

static int NWScript_ItemPropertyMaterial(lua_State *L)
{
    int nMaterialType = luaL_checkint(L, 1);

    StackPushInteger(nMaterialType);
    VM_ExecuteCommand(845, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyQuality(lua_State *L)
{
    int nQuality = luaL_checkint(L, 1);

    StackPushInteger(nQuality);
    VM_ExecuteCommand(846, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}

static int NWScript_ItemPropertyAdditional(lua_State *L)
{
    int nAdditionalProperty = luaL_checkint(L, 1);

    StackPushInteger(nAdditionalProperty);
    VM_ExecuteCommand(847, 1);
    void *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, &pRetVal);
    lua_pushlightuserdata(L, pRetVal);
    return 1;
}


void LUA_InitNWScript(lua_State *L)
{

    lua_register(L, "Random", NWScript_Random);
    lua_register(L, "PrintString", NWScript_PrintString);
    lua_register(L, "PrintFloat", NWScript_PrintFloat);
    lua_register(L, "FloatToString", NWScript_FloatToString);
    lua_register(L, "PrintInteger", NWScript_PrintInteger);
    lua_register(L, "PrintObject", NWScript_PrintObject);
    //lua_register(L, "AssignCommand", NWScript_AssignCommand);
    //lua_register(L, "DelayCommand", NWScript_DelayCommand);
    lua_register(L, "ExecuteScript", NWScript_ExecuteScript);
    lua_register(L, "ClearAllActions", NWScript_ClearAllActions);
    lua_register(L, "SetFacing", NWScript_SetFacing);
    lua_register(L, "SetCalendar", NWScript_SetCalendar);
    lua_register(L, "SetTime", NWScript_SetTime);
    lua_register(L, "GetCalendarYear", NWScript_GetCalendarYear);
    lua_register(L, "GetCalendarMonth", NWScript_GetCalendarMonth);
    lua_register(L, "GetCalendarDay", NWScript_GetCalendarDay);
    lua_register(L, "GetTimeHour", NWScript_GetTimeHour);
    lua_register(L, "GetTimeMinute", NWScript_GetTimeMinute);
    lua_register(L, "GetTimeSecond", NWScript_GetTimeSecond);
    lua_register(L, "GetTimeMillisecond", NWScript_GetTimeMillisecond);
    lua_register(L, "ActionRandomWalk", NWScript_ActionRandomWalk);
    lua_register(L, "ActionMoveToLocation", NWScript_ActionMoveToLocation);
    lua_register(L, "ActionMoveToObject", NWScript_ActionMoveToObject);
    lua_register(L, "ActionMoveAwayFromObject", NWScript_ActionMoveAwayFromObject);
    lua_register(L, "GetArea", NWScript_GetArea);
    lua_register(L, "GetEnteringObject", NWScript_GetEnteringObject);
    lua_register(L, "GetExitingObject", NWScript_GetExitingObject);
    lua_register(L, "GetPosition", NWScript_GetPosition);
    lua_register(L, "GetFacing", NWScript_GetFacing);
    lua_register(L, "GetItemPossessor", NWScript_GetItemPossessor);
    lua_register(L, "GetItemPossessedBy", NWScript_GetItemPossessedBy);
    lua_register(L, "CreateItemOnObject", NWScript_CreateItemOnObject);
    lua_register(L, "ActionEquipItem", NWScript_ActionEquipItem);
    lua_register(L, "ActionUnequipItem", NWScript_ActionUnequipItem);
    lua_register(L, "ActionPickUpItem", NWScript_ActionPickUpItem);
    lua_register(L, "ActionPutDownItem", NWScript_ActionPutDownItem);
    lua_register(L, "GetLastAttacker", NWScript_GetLastAttacker);
    lua_register(L, "ActionAttack", NWScript_ActionAttack);
    lua_register(L, "GetNearestCreature", NWScript_GetNearestCreature);
    lua_register(L, "ActionSpeakString", NWScript_ActionSpeakString);
    lua_register(L, "ActionPlayAnimation", NWScript_ActionPlayAnimation);
    lua_register(L, "GetDistanceToObject", NWScript_GetDistanceToObject);
    lua_register(L, "GetIsObjectValid", NWScript_GetIsObjectValid);
    lua_register(L, "ActionOpenDoor", NWScript_ActionOpenDoor);
    lua_register(L, "ActionCloseDoor", NWScript_ActionCloseDoor);
    lua_register(L, "SetCameraFacing", NWScript_SetCameraFacing);
    lua_register(L, "PlaySound", NWScript_PlaySound);
    lua_register(L, "GetSpellTargetObject", NWScript_GetSpellTargetObject);
    lua_register(L, "ActionCastSpellAtObject", NWScript_ActionCastSpellAtObject);
    lua_register(L, "GetCurrentHitPoints", NWScript_GetCurrentHitPoints);
    lua_register(L, "GetMaxHitPoints", NWScript_GetMaxHitPoints);
    lua_register(L, "GetLocalInt", NWScript_GetLocalInt);
    lua_register(L, "GetLocalFloat", NWScript_GetLocalFloat);
    lua_register(L, "GetLocalString", NWScript_GetLocalString);
    lua_register(L, "GetLocalObject", NWScript_GetLocalObject);
    lua_register(L, "SetLocalInt", NWScript_SetLocalInt);
    lua_register(L, "SetLocalFloat", NWScript_SetLocalFloat);
    lua_register(L, "SetLocalString", NWScript_SetLocalString);
    lua_register(L, "SetLocalObject", NWScript_SetLocalObject);
    lua_register(L, "GetStringLength", NWScript_GetStringLength);
    lua_register(L, "GetStringUpperCase", NWScript_GetStringUpperCase);
    lua_register(L, "GetStringLowerCase", NWScript_GetStringLowerCase);
    lua_register(L, "GetStringRight", NWScript_GetStringRight);
    lua_register(L, "GetStringLeft", NWScript_GetStringLeft);
    lua_register(L, "InsertString", NWScript_InsertString);
    lua_register(L, "GetSubString", NWScript_GetSubString);
    lua_register(L, "FindSubString", NWScript_FindSubString);
    lua_register(L, "fabs", NWScript_fabs);
    lua_register(L, "cos", NWScript_cos);
    lua_register(L, "sin", NWScript_sin);
    lua_register(L, "tan", NWScript_tan);
    lua_register(L, "acos", NWScript_acos);
    lua_register(L, "asin", NWScript_asin);
    lua_register(L, "atan", NWScript_atan);
    lua_register(L, "log", NWScript_log);
    lua_register(L, "pow", NWScript_pow);
    lua_register(L, "sqrt", NWScript_sqrt);
    lua_register(L, "abs", NWScript_abs);
    lua_register(L, "EffectHeal", NWScript_EffectHeal);
    lua_register(L, "EffectDamage", NWScript_EffectDamage);
    lua_register(L, "EffectAbilityIncrease", NWScript_EffectAbilityIncrease);
    lua_register(L, "EffectDamageResistance", NWScript_EffectDamageResistance);
    lua_register(L, "EffectResurrection", NWScript_EffectResurrection);
    lua_register(L, "EffectSummonCreature", NWScript_EffectSummonCreature);
    lua_register(L, "GetCasterLevel", NWScript_GetCasterLevel);
    lua_register(L, "GetFirstEffect", NWScript_GetFirstEffect);
    lua_register(L, "GetNextEffect", NWScript_GetNextEffect);
    lua_register(L, "RemoveEffect", NWScript_RemoveEffect);
    lua_register(L, "GetIsEffectValid", NWScript_GetIsEffectValid);
    lua_register(L, "GetEffectDurationType", NWScript_GetEffectDurationType);
    lua_register(L, "GetEffectSubType", NWScript_GetEffectSubType);
    lua_register(L, "GetEffectCreator", NWScript_GetEffectCreator);
    lua_register(L, "IntToString", NWScript_IntToString);
    lua_register(L, "GetFirstObjectInArea", NWScript_GetFirstObjectInArea);
    lua_register(L, "GetNextObjectInArea", NWScript_GetNextObjectInArea);
    lua_register(L, "d2", NWScript_d2);
    lua_register(L, "d3", NWScript_d3);
    lua_register(L, "d4", NWScript_d4);
    lua_register(L, "d6", NWScript_d6);
    lua_register(L, "d8", NWScript_d8);
    lua_register(L, "d10", NWScript_d10);
    lua_register(L, "d12", NWScript_d12);
    lua_register(L, "d20", NWScript_d20);
    lua_register(L, "d100", NWScript_d100);
    lua_register(L, "VectorMagnitude", NWScript_VectorMagnitude);
    lua_register(L, "GetMetaMagicFeat", NWScript_GetMetaMagicFeat);
    lua_register(L, "GetObjectType", NWScript_GetObjectType);
    lua_register(L, "GetRacialType", NWScript_GetRacialType);
    lua_register(L, "FortitudeSave", NWScript_FortitudeSave);
    lua_register(L, "ReflexSave", NWScript_ReflexSave);
    lua_register(L, "WillSave", NWScript_WillSave);
    lua_register(L, "GetSpellSaveDC", NWScript_GetSpellSaveDC);
    lua_register(L, "MagicalEffect", NWScript_MagicalEffect);
    lua_register(L, "SupernaturalEffect", NWScript_SupernaturalEffect);
    lua_register(L, "ExtraordinaryEffect", NWScript_ExtraordinaryEffect);
    lua_register(L, "EffectACIncrease", NWScript_EffectACIncrease);
    lua_register(L, "GetAC", NWScript_GetAC);
    lua_register(L, "EffectSavingThrowIncrease", NWScript_EffectSavingThrowIncrease);
    lua_register(L, "EffectAttackIncrease", NWScript_EffectAttackIncrease);
    lua_register(L, "EffectDamageReduction", NWScript_EffectDamageReduction);
    lua_register(L, "EffectDamageIncrease", NWScript_EffectDamageIncrease);
    lua_register(L, "RoundsToSeconds", NWScript_RoundsToSeconds);
    lua_register(L, "HoursToSeconds", NWScript_HoursToSeconds);
    lua_register(L, "TurnsToSeconds", NWScript_TurnsToSeconds);
    lua_register(L, "GetLawChaosValue", NWScript_GetLawChaosValue);
    lua_register(L, "GetGoodEvilValue", NWScript_GetGoodEvilValue);
    lua_register(L, "GetAlignmentLawChaos", NWScript_GetAlignmentLawChaos);
    lua_register(L, "GetAlignmentGoodEvil", NWScript_GetAlignmentGoodEvil);
    lua_register(L, "EffectEntangle", NWScript_EffectEntangle);
    lua_register(L, "SignalEvent", NWScript_SignalEvent);
    lua_register(L, "EventUserDefined", NWScript_EventUserDefined);
    lua_register(L, "EffectDeath", NWScript_EffectDeath);
    lua_register(L, "EffectKnockdown", NWScript_EffectKnockdown);
    lua_register(L, "ActionGiveItem", NWScript_ActionGiveItem);
    lua_register(L, "ActionTakeItem", NWScript_ActionTakeItem);
    lua_register(L, "VectorNormalize", NWScript_VectorNormalize);
    lua_register(L, "EffectCurse", NWScript_EffectCurse);
    lua_register(L, "GetAbilityScore", NWScript_GetAbilityScore);
    lua_register(L, "GetIsDead", NWScript_GetIsDead);
    lua_register(L, "PrintVector", NWScript_PrintVector);
    lua_register(L, "Vector", NWScript_Vector);
    lua_register(L, "SetFacingPoint", NWScript_SetFacingPoint);
    lua_register(L, "AngleToVector", NWScript_AngleToVector);
    lua_register(L, "VectorToAngle", NWScript_VectorToAngle);
    lua_register(L, "TouchAttackMelee", NWScript_TouchAttackMelee);
    lua_register(L, "TouchAttackRanged", NWScript_TouchAttackRanged);
    lua_register(L, "EffectParalyze", NWScript_EffectParalyze);
    lua_register(L, "EffectSpellImmunity", NWScript_EffectSpellImmunity);
    lua_register(L, "EffectDeaf", NWScript_EffectDeaf);
    lua_register(L, "GetDistanceBetween", NWScript_GetDistanceBetween);
    lua_register(L, "SetLocalLocation", NWScript_SetLocalLocation);
    lua_register(L, "GetLocalLocation", NWScript_GetLocalLocation);
    lua_register(L, "EffectSleep", NWScript_EffectSleep);
    lua_register(L, "GetItemInSlot", NWScript_GetItemInSlot);
    lua_register(L, "EffectCharmed", NWScript_EffectCharmed);
    lua_register(L, "EffectConfused", NWScript_EffectConfused);
    lua_register(L, "EffectFrightened", NWScript_EffectFrightened);
    lua_register(L, "EffectDominated", NWScript_EffectDominated);
    lua_register(L, "EffectDazed", NWScript_EffectDazed);
    lua_register(L, "EffectStunned", NWScript_EffectStunned);
    lua_register(L, "SetCommandable", NWScript_SetCommandable);
    lua_register(L, "GetCommandable", NWScript_GetCommandable);
    lua_register(L, "EffectRegenerate", NWScript_EffectRegenerate);
    lua_register(L, "EffectMovementSpeedIncrease", NWScript_EffectMovementSpeedIncrease);
    lua_register(L, "GetHitDice", NWScript_GetHitDice);
    lua_register(L, "ActionForceFollowObject", NWScript_ActionForceFollowObject);
    lua_register(L, "GetTag", NWScript_GetTag);
    lua_register(L, "ResistSpell", NWScript_ResistSpell);
    lua_register(L, "GetEffectType", NWScript_GetEffectType);
    lua_register(L, "EffectAreaOfEffect", NWScript_EffectAreaOfEffect);
    lua_register(L, "GetFactionEqual", NWScript_GetFactionEqual);
    lua_register(L, "ChangeFaction", NWScript_ChangeFaction);
    lua_register(L, "GetIsListening", NWScript_GetIsListening);
    lua_register(L, "SetListening", NWScript_SetListening);
    lua_register(L, "SetListenPattern", NWScript_SetListenPattern);
    lua_register(L, "TestStringAgainstPattern", NWScript_TestStringAgainstPattern);
    lua_register(L, "GetMatchedSubstring", NWScript_GetMatchedSubstring);
    lua_register(L, "GetMatchedSubstringsCount", NWScript_GetMatchedSubstringsCount);
    lua_register(L, "EffectVisualEffect", NWScript_EffectVisualEffect);
    lua_register(L, "GetFactionWeakestMember", NWScript_GetFactionWeakestMember);
    lua_register(L, "GetFactionStrongestMember", NWScript_GetFactionStrongestMember);
    lua_register(L, "GetFactionMostDamagedMember", NWScript_GetFactionMostDamagedMember);
    lua_register(L, "GetFactionLeastDamagedMember", NWScript_GetFactionLeastDamagedMember);
    lua_register(L, "GetFactionGold", NWScript_GetFactionGold);
    lua_register(L, "GetFactionAverageReputation", NWScript_GetFactionAverageReputation);
    lua_register(L, "GetFactionAverageGoodEvilAlignment", NWScript_GetFactionAverageGoodEvilAlignment);
    lua_register(L, "GetFactionAverageLawChaosAlignment", NWScript_GetFactionAverageLawChaosAlignment);
    lua_register(L, "GetFactionAverageLevel", NWScript_GetFactionAverageLevel);
    lua_register(L, "GetFactionAverageXP", NWScript_GetFactionAverageXP);
    lua_register(L, "GetFactionMostFrequentClass", NWScript_GetFactionMostFrequentClass);
    lua_register(L, "GetFactionWorstAC", NWScript_GetFactionWorstAC);
    lua_register(L, "GetFactionBestAC", NWScript_GetFactionBestAC);
    lua_register(L, "ActionSit", NWScript_ActionSit);
    lua_register(L, "GetListenPatternNumber", NWScript_GetListenPatternNumber);
    lua_register(L, "ActionJumpToObject", NWScript_ActionJumpToObject);
    lua_register(L, "GetWaypointByTag", NWScript_GetWaypointByTag);
    lua_register(L, "GetTransitionTarget", NWScript_GetTransitionTarget);
    lua_register(L, "EffectLinkEffects", NWScript_EffectLinkEffects);
    lua_register(L, "GetObjectByTag", NWScript_GetObjectByTag);
    lua_register(L, "AdjustAlignment", NWScript_AdjustAlignment);
    lua_register(L, "ActionWait", NWScript_ActionWait);
    lua_register(L, "SetAreaTransitionBMP", NWScript_SetAreaTransitionBMP);
    lua_register(L, "ActionStartConversation", NWScript_ActionStartConversation);
    lua_register(L, "ActionPauseConversation", NWScript_ActionPauseConversation);
    lua_register(L, "ActionResumeConversation", NWScript_ActionResumeConversation);
    lua_register(L, "EffectBeam", NWScript_EffectBeam);
    lua_register(L, "GetReputation", NWScript_GetReputation);
    lua_register(L, "AdjustReputation", NWScript_AdjustReputation);
    lua_register(L, "GetSittingCreature", NWScript_GetSittingCreature);
    lua_register(L, "GetGoingToBeAttackedBy", NWScript_GetGoingToBeAttackedBy);
    lua_register(L, "EffectSpellResistanceIncrease", NWScript_EffectSpellResistanceIncrease);
    lua_register(L, "GetLocation", NWScript_GetLocation);
    lua_register(L, "ActionJumpToLocation", NWScript_ActionJumpToLocation);
    lua_register(L, "Location", NWScript_Location);
    lua_register(L, "ApplyEffectAtLocation", NWScript_ApplyEffectAtLocation);
    lua_register(L, "GetIsPC", NWScript_GetIsPC);
    lua_register(L, "FeetToMeters", NWScript_FeetToMeters);
    lua_register(L, "YardsToMeters", NWScript_YardsToMeters);
    lua_register(L, "ApplyEffectToObject", NWScript_ApplyEffectToObject);
    lua_register(L, "SpeakString", NWScript_SpeakString);
    lua_register(L, "GetSpellTargetLocation", NWScript_GetSpellTargetLocation);
    lua_register(L, "GetPositionFromLocation", NWScript_GetPositionFromLocation);
    lua_register(L, "GetAreaFromLocation", NWScript_GetAreaFromLocation);
    lua_register(L, "GetFacingFromLocation", NWScript_GetFacingFromLocation);
    lua_register(L, "GetNearestCreatureToLocation", NWScript_GetNearestCreatureToLocation);
    lua_register(L, "GetNearestObject", NWScript_GetNearestObject);
    lua_register(L, "GetNearestObjectToLocation", NWScript_GetNearestObjectToLocation);
    lua_register(L, "GetNearestObjectByTag", NWScript_GetNearestObjectByTag);
    lua_register(L, "IntToFloat", NWScript_IntToFloat);
    lua_register(L, "FloatToInt", NWScript_FloatToInt);
    lua_register(L, "StringToInt", NWScript_StringToInt);
    lua_register(L, "StringToFloat", NWScript_StringToFloat);
    lua_register(L, "ActionCastSpellAtLocation", NWScript_ActionCastSpellAtLocation);
    lua_register(L, "GetIsEnemy", NWScript_GetIsEnemy);
    lua_register(L, "GetIsFriend", NWScript_GetIsFriend);
    lua_register(L, "GetIsNeutral", NWScript_GetIsNeutral);
    lua_register(L, "GetPCSpeaker", NWScript_GetPCSpeaker);
    lua_register(L, "GetStringByStrRef", NWScript_GetStringByStrRef);
    lua_register(L, "ActionSpeakStringByStrRef", NWScript_ActionSpeakStringByStrRef);
    lua_register(L, "DestroyObject", NWScript_DestroyObject);
    lua_register(L, "GetModule", NWScript_GetModule);
    lua_register(L, "CreateObject", NWScript_CreateObject);
    lua_register(L, "EventSpellCastAt", NWScript_EventSpellCastAt);
    lua_register(L, "GetLastSpellCaster", NWScript_GetLastSpellCaster);
    lua_register(L, "GetLastSpell", NWScript_GetLastSpell);
    lua_register(L, "GetUserDefinedEventNumber", NWScript_GetUserDefinedEventNumber);
    lua_register(L, "GetSpellId", NWScript_GetSpellId);
    lua_register(L, "RandomName", NWScript_RandomName);
    lua_register(L, "EffectPoison", NWScript_EffectPoison);
    lua_register(L, "EffectDisease", NWScript_EffectDisease);
    lua_register(L, "EffectSilence", NWScript_EffectSilence);
    lua_register(L, "GetName", NWScript_GetName);
    lua_register(L, "GetLastSpeaker", NWScript_GetLastSpeaker);
    lua_register(L, "BeginConversation", NWScript_BeginConversation);
    lua_register(L, "GetLastPerceived", NWScript_GetLastPerceived);
    lua_register(L, "GetLastPerceptionHeard", NWScript_GetLastPerceptionHeard);
    lua_register(L, "GetLastPerceptionInaudible", NWScript_GetLastPerceptionInaudible);
    lua_register(L, "GetLastPerceptionSeen", NWScript_GetLastPerceptionSeen);
    lua_register(L, "GetLastClosedBy", NWScript_GetLastClosedBy);
    lua_register(L, "GetLastPerceptionVanished", NWScript_GetLastPerceptionVanished);
    lua_register(L, "GetFirstInPersistentObject", NWScript_GetFirstInPersistentObject);
    lua_register(L, "GetNextInPersistentObject", NWScript_GetNextInPersistentObject);
    lua_register(L, "GetAreaOfEffectCreator", NWScript_GetAreaOfEffectCreator);
    lua_register(L, "DeleteLocalInt", NWScript_DeleteLocalInt);
    lua_register(L, "DeleteLocalFloat", NWScript_DeleteLocalFloat);
    lua_register(L, "DeleteLocalString", NWScript_DeleteLocalString);
    lua_register(L, "DeleteLocalObject", NWScript_DeleteLocalObject);
    lua_register(L, "DeleteLocalLocation", NWScript_DeleteLocalLocation);
    lua_register(L, "EffectHaste", NWScript_EffectHaste);
    lua_register(L, "EffectSlow", NWScript_EffectSlow);
    lua_register(L, "ObjectToString", NWScript_ObjectToString);
    lua_register(L, "EffectImmunity", NWScript_EffectImmunity);
    lua_register(L, "GetIsImmune", NWScript_GetIsImmune);
    lua_register(L, "EffectDamageImmunityIncrease", NWScript_EffectDamageImmunityIncrease);
    lua_register(L, "GetEncounterActive", NWScript_GetEncounterActive);
    lua_register(L, "SetEncounterActive", NWScript_SetEncounterActive);
    lua_register(L, "GetEncounterSpawnsMax", NWScript_GetEncounterSpawnsMax);
    lua_register(L, "SetEncounterSpawnsMax", NWScript_SetEncounterSpawnsMax);
    lua_register(L, "GetEncounterSpawnsCurrent", NWScript_GetEncounterSpawnsCurrent);
    lua_register(L, "SetEncounterSpawnsCurrent", NWScript_SetEncounterSpawnsCurrent);
    lua_register(L, "GetModuleItemAcquired", NWScript_GetModuleItemAcquired);
    lua_register(L, "GetModuleItemAcquiredFrom", NWScript_GetModuleItemAcquiredFrom);
    lua_register(L, "SetCustomToken", NWScript_SetCustomToken);
    lua_register(L, "GetHasFeat", NWScript_GetHasFeat);
    lua_register(L, "GetHasSkill", NWScript_GetHasSkill);
    lua_register(L, "ActionUseFeat", NWScript_ActionUseFeat);
    lua_register(L, "ActionUseSkill", NWScript_ActionUseSkill);
    lua_register(L, "GetObjectSeen", NWScript_GetObjectSeen);
    lua_register(L, "GetObjectHeard", NWScript_GetObjectHeard);
    lua_register(L, "GetLastPlayerDied", NWScript_GetLastPlayerDied);
    lua_register(L, "GetModuleItemLost", NWScript_GetModuleItemLost);
    lua_register(L, "GetModuleItemLostBy", NWScript_GetModuleItemLostBy);
    //lua_register(L, "ActionDoCommand", NWScript_ActionDoCommand);
    lua_register(L, "EventConversation", NWScript_EventConversation);
    lua_register(L, "SetEncounterDifficulty", NWScript_SetEncounterDifficulty);
    lua_register(L, "GetEncounterDifficulty", NWScript_GetEncounterDifficulty);
    lua_register(L, "GetDistanceBetweenLocations", NWScript_GetDistanceBetweenLocations);
    lua_register(L, "GetReflexAdjustedDamage", NWScript_GetReflexAdjustedDamage);
    lua_register(L, "PlayAnimation", NWScript_PlayAnimation);
    lua_register(L, "TalentSpell", NWScript_TalentSpell);
    lua_register(L, "TalentFeat", NWScript_TalentFeat);
    lua_register(L, "TalentSkill", NWScript_TalentSkill);
    lua_register(L, "GetHasSpellEffect", NWScript_GetHasSpellEffect);
    lua_register(L, "GetEffectSpellId", NWScript_GetEffectSpellId);
    lua_register(L, "GetCreatureHasTalent", NWScript_GetCreatureHasTalent);
    lua_register(L, "GetCreatureTalentRandom", NWScript_GetCreatureTalentRandom);
    lua_register(L, "GetCreatureTalentBest", NWScript_GetCreatureTalentBest);
    lua_register(L, "ActionUseTalentOnObject", NWScript_ActionUseTalentOnObject);
    lua_register(L, "ActionUseTalentAtLocation", NWScript_ActionUseTalentAtLocation);
    lua_register(L, "GetGoldPieceValue", NWScript_GetGoldPieceValue);
    lua_register(L, "GetIsPlayableRacialType", NWScript_GetIsPlayableRacialType);
    lua_register(L, "JumpToLocation", NWScript_JumpToLocation);
    lua_register(L, "EffectTemporaryHitpoints", NWScript_EffectTemporaryHitpoints);
    lua_register(L, "GetSkillRank", NWScript_GetSkillRank);
    lua_register(L, "GetAttackTarget", NWScript_GetAttackTarget);
    lua_register(L, "GetLastAttackType", NWScript_GetLastAttackType);
    lua_register(L, "GetLastAttackMode", NWScript_GetLastAttackMode);
    lua_register(L, "GetMaster", NWScript_GetMaster);
    lua_register(L, "GetIsInCombat", NWScript_GetIsInCombat);
    lua_register(L, "GetLastAssociateCommand", NWScript_GetLastAssociateCommand);
    lua_register(L, "GiveGoldToCreature", NWScript_GiveGoldToCreature);
    lua_register(L, "SetIsDestroyable", NWScript_SetIsDestroyable);
    lua_register(L, "SetLocked", NWScript_SetLocked);
    lua_register(L, "GetLocked", NWScript_GetLocked);
    lua_register(L, "GetClickingObject", NWScript_GetClickingObject);
    lua_register(L, "SetAssociateListenPatterns", NWScript_SetAssociateListenPatterns);
    lua_register(L, "GetLastWeaponUsed", NWScript_GetLastWeaponUsed);
    lua_register(L, "ActionInteractObject", NWScript_ActionInteractObject);
    lua_register(L, "GetLastUsedBy", NWScript_GetLastUsedBy);
    lua_register(L, "GetAbilityModifier", NWScript_GetAbilityModifier);
    lua_register(L, "GetIdentified", NWScript_GetIdentified);
    lua_register(L, "SetIdentified", NWScript_SetIdentified);
    lua_register(L, "SummonAnimalCompanion", NWScript_SummonAnimalCompanion);
    lua_register(L, "SummonFamiliar", NWScript_SummonFamiliar);
    lua_register(L, "GetBlockingDoor", NWScript_GetBlockingDoor);
    lua_register(L, "GetIsDoorActionPossible", NWScript_GetIsDoorActionPossible);
    lua_register(L, "DoDoorAction", NWScript_DoDoorAction);
    lua_register(L, "GetFirstItemInInventory", NWScript_GetFirstItemInInventory);
    lua_register(L, "GetNextItemInInventory", NWScript_GetNextItemInInventory);
    lua_register(L, "GetClassByPosition", NWScript_GetClassByPosition);
    lua_register(L, "GetLevelByPosition", NWScript_GetLevelByPosition);
    lua_register(L, "GetLevelByClass", NWScript_GetLevelByClass);
    lua_register(L, "GetDamageDealtByType", NWScript_GetDamageDealtByType);
    lua_register(L, "GetTotalDamageDealt", NWScript_GetTotalDamageDealt);
    lua_register(L, "GetLastDamager", NWScript_GetLastDamager);
    lua_register(L, "GetLastDisarmed", NWScript_GetLastDisarmed);
    lua_register(L, "GetLastDisturbed", NWScript_GetLastDisturbed);
    lua_register(L, "GetLastLocked", NWScript_GetLastLocked);
    lua_register(L, "GetLastUnlocked", NWScript_GetLastUnlocked);
    lua_register(L, "EffectSkillIncrease", NWScript_EffectSkillIncrease);
    lua_register(L, "GetInventoryDisturbType", NWScript_GetInventoryDisturbType);
    lua_register(L, "GetInventoryDisturbItem", NWScript_GetInventoryDisturbItem);
    lua_register(L, "GetHenchman", NWScript_GetHenchman);
    lua_register(L, "VersusAlignmentEffect", NWScript_VersusAlignmentEffect);
    lua_register(L, "VersusRacialTypeEffect", NWScript_VersusRacialTypeEffect);
    lua_register(L, "VersusTrapEffect", NWScript_VersusTrapEffect);
    lua_register(L, "GetGender", NWScript_GetGender);
    lua_register(L, "GetIsTalentValid", NWScript_GetIsTalentValid);
    lua_register(L, "ActionMoveAwayFromLocation", NWScript_ActionMoveAwayFromLocation);
    lua_register(L, "GetAttemptedAttackTarget", NWScript_GetAttemptedAttackTarget);
    lua_register(L, "GetTypeFromTalent", NWScript_GetTypeFromTalent);
    lua_register(L, "GetIdFromTalent", NWScript_GetIdFromTalent);
    lua_register(L, "GetAssociate", NWScript_GetAssociate);
    lua_register(L, "AddHenchman", NWScript_AddHenchman);
    lua_register(L, "RemoveHenchman", NWScript_RemoveHenchman);
    lua_register(L, "AddJournalQuestEntry", NWScript_AddJournalQuestEntry);
    lua_register(L, "RemoveJournalQuestEntry", NWScript_RemoveJournalQuestEntry);
    lua_register(L, "GetPCPublicCDKey", NWScript_GetPCPublicCDKey);
    lua_register(L, "GetPCIPAddress", NWScript_GetPCIPAddress);
    lua_register(L, "GetPCPlayerName", NWScript_GetPCPlayerName);
    lua_register(L, "SetPCLike", NWScript_SetPCLike);
    lua_register(L, "SetPCDislike", NWScript_SetPCDislike);
    lua_register(L, "SendMessageToPC", NWScript_SendMessageToPC);
    lua_register(L, "GetAttemptedSpellTarget", NWScript_GetAttemptedSpellTarget);
    lua_register(L, "GetLastOpenedBy", NWScript_GetLastOpenedBy);
    lua_register(L, "GetHasSpell", NWScript_GetHasSpell);
    lua_register(L, "OpenStore", NWScript_OpenStore);
    lua_register(L, "EffectTurned", NWScript_EffectTurned);
    lua_register(L, "GetFirstFactionMember", NWScript_GetFirstFactionMember);
    lua_register(L, "GetNextFactionMember", NWScript_GetNextFactionMember);
    lua_register(L, "ActionForceMoveToLocation", NWScript_ActionForceMoveToLocation);
    lua_register(L, "ActionForceMoveToObject", NWScript_ActionForceMoveToObject);
    lua_register(L, "GetJournalQuestExperience", NWScript_GetJournalQuestExperience);
    lua_register(L, "JumpToObject", NWScript_JumpToObject);
    lua_register(L, "SetMapPinEnabled", NWScript_SetMapPinEnabled);
    lua_register(L, "EffectHitPointChangeWhenDying", NWScript_EffectHitPointChangeWhenDying);
    lua_register(L, "PopUpGUIPanel", NWScript_PopUpGUIPanel);
    lua_register(L, "ClearPersonalReputation", NWScript_ClearPersonalReputation);
    lua_register(L, "SetIsTemporaryFriend", NWScript_SetIsTemporaryFriend);
    lua_register(L, "SetIsTemporaryEnemy", NWScript_SetIsTemporaryEnemy);
    lua_register(L, "SetIsTemporaryNeutral", NWScript_SetIsTemporaryNeutral);
    lua_register(L, "GiveXPToCreature", NWScript_GiveXPToCreature);
    lua_register(L, "SetXP", NWScript_SetXP);
    lua_register(L, "GetXP", NWScript_GetXP);
    lua_register(L, "IntToHexString", NWScript_IntToHexString);
    lua_register(L, "GetBaseItemType", NWScript_GetBaseItemType);
    lua_register(L, "GetItemHasItemProperty", NWScript_GetItemHasItemProperty);
    lua_register(L, "ActionEquipMostDamagingMelee", NWScript_ActionEquipMostDamagingMelee);
    lua_register(L, "ActionEquipMostDamagingRanged", NWScript_ActionEquipMostDamagingRanged);
    lua_register(L, "GetItemACValue", NWScript_GetItemACValue);
    lua_register(L, "ActionRest", NWScript_ActionRest);
    lua_register(L, "ExploreAreaForPlayer", NWScript_ExploreAreaForPlayer);
    lua_register(L, "ActionEquipMostEffectiveArmor", NWScript_ActionEquipMostEffectiveArmor);
    lua_register(L, "GetIsDay", NWScript_GetIsDay);
    lua_register(L, "GetIsNight", NWScript_GetIsNight);
    lua_register(L, "GetIsDawn", NWScript_GetIsDawn);
    lua_register(L, "GetIsDusk", NWScript_GetIsDusk);
    lua_register(L, "GetIsEncounterCreature", NWScript_GetIsEncounterCreature);
    lua_register(L, "GetLastPlayerDying", NWScript_GetLastPlayerDying);
    lua_register(L, "GetStartingLocation", NWScript_GetStartingLocation);
    lua_register(L, "ChangeToStandardFaction", NWScript_ChangeToStandardFaction);
    lua_register(L, "SoundObjectPlay", NWScript_SoundObjectPlay);
    lua_register(L, "SoundObjectStop", NWScript_SoundObjectStop);
    lua_register(L, "SoundObjectSetVolume", NWScript_SoundObjectSetVolume);
    lua_register(L, "SoundObjectSetPosition", NWScript_SoundObjectSetPosition);
    lua_register(L, "SpeakOneLinerConversation", NWScript_SpeakOneLinerConversation);
    lua_register(L, "GetGold", NWScript_GetGold);
    lua_register(L, "GetLastRespawnButtonPresser", NWScript_GetLastRespawnButtonPresser);
    lua_register(L, "GetIsDM", NWScript_GetIsDM);
    lua_register(L, "PlayVoiceChat", NWScript_PlayVoiceChat);
    lua_register(L, "GetIsWeaponEffective", NWScript_GetIsWeaponEffective);
    lua_register(L, "GetLastSpellHarmful", NWScript_GetLastSpellHarmful);
    lua_register(L, "EventActivateItem", NWScript_EventActivateItem);
    lua_register(L, "MusicBackgroundPlay", NWScript_MusicBackgroundPlay);
    lua_register(L, "MusicBackgroundStop", NWScript_MusicBackgroundStop);
    lua_register(L, "MusicBackgroundSetDelay", NWScript_MusicBackgroundSetDelay);
    lua_register(L, "MusicBackgroundChangeDay", NWScript_MusicBackgroundChangeDay);
    lua_register(L, "MusicBackgroundChangeNight", NWScript_MusicBackgroundChangeNight);
    lua_register(L, "MusicBattlePlay", NWScript_MusicBattlePlay);
    lua_register(L, "MusicBattleStop", NWScript_MusicBattleStop);
    lua_register(L, "MusicBattleChange", NWScript_MusicBattleChange);
    lua_register(L, "AmbientSoundPlay", NWScript_AmbientSoundPlay);
    lua_register(L, "AmbientSoundStop", NWScript_AmbientSoundStop);
    lua_register(L, "AmbientSoundChangeDay", NWScript_AmbientSoundChangeDay);
    lua_register(L, "AmbientSoundChangeNight", NWScript_AmbientSoundChangeNight);
    lua_register(L, "GetLastKiller", NWScript_GetLastKiller);
    lua_register(L, "GetSpellCastItem", NWScript_GetSpellCastItem);
    lua_register(L, "GetItemActivated", NWScript_GetItemActivated);
    lua_register(L, "GetItemActivator", NWScript_GetItemActivator);
    lua_register(L, "GetItemActivatedTargetLocation", NWScript_GetItemActivatedTargetLocation);
    lua_register(L, "GetItemActivatedTarget", NWScript_GetItemActivatedTarget);
    lua_register(L, "GetIsOpen", NWScript_GetIsOpen);
    lua_register(L, "TakeGoldFromCreature", NWScript_TakeGoldFromCreature);
    lua_register(L, "IsInConversation", NWScript_IsInConversation);
    lua_register(L, "EffectAbilityDecrease", NWScript_EffectAbilityDecrease);
    lua_register(L, "EffectAttackDecrease", NWScript_EffectAttackDecrease);
    lua_register(L, "EffectDamageDecrease", NWScript_EffectDamageDecrease);
    lua_register(L, "EffectDamageImmunityDecrease", NWScript_EffectDamageImmunityDecrease);
    lua_register(L, "EffectACDecrease", NWScript_EffectACDecrease);
    lua_register(L, "EffectMovementSpeedDecrease", NWScript_EffectMovementSpeedDecrease);
    lua_register(L, "EffectSavingThrowDecrease", NWScript_EffectSavingThrowDecrease);
    lua_register(L, "EffectSkillDecrease", NWScript_EffectSkillDecrease);
    lua_register(L, "EffectSpellResistanceDecrease", NWScript_EffectSpellResistanceDecrease);
    lua_register(L, "GetPlotFlag", NWScript_GetPlotFlag);
    lua_register(L, "SetPlotFlag", NWScript_SetPlotFlag);
    lua_register(L, "EffectInvisibility", NWScript_EffectInvisibility);
    lua_register(L, "EffectConcealment", NWScript_EffectConcealment);
    lua_register(L, "EffectDarkness", NWScript_EffectDarkness);
    lua_register(L, "EffectDispelMagicAll", NWScript_EffectDispelMagicAll);
    lua_register(L, "EffectUltravision", NWScript_EffectUltravision);
    lua_register(L, "EffectNegativeLevel", NWScript_EffectNegativeLevel);
    lua_register(L, "EffectPolymorph", NWScript_EffectPolymorph);
    lua_register(L, "EffectSanctuary", NWScript_EffectSanctuary);
    lua_register(L, "EffectTrueSeeing", NWScript_EffectTrueSeeing);
    lua_register(L, "EffectSeeInvisible", NWScript_EffectSeeInvisible);
    lua_register(L, "EffectTimeStop", NWScript_EffectTimeStop);
    lua_register(L, "EffectBlindness", NWScript_EffectBlindness);
    lua_register(L, "GetIsReactionTypeFriendly", NWScript_GetIsReactionTypeFriendly);
    lua_register(L, "GetIsReactionTypeNeutral", NWScript_GetIsReactionTypeNeutral);
    lua_register(L, "GetIsReactionTypeHostile", NWScript_GetIsReactionTypeHostile);
    lua_register(L, "EffectSpellLevelAbsorption", NWScript_EffectSpellLevelAbsorption);
    lua_register(L, "EffectDispelMagicBest", NWScript_EffectDispelMagicBest);
    lua_register(L, "ActivatePortal", NWScript_ActivatePortal);
    lua_register(L, "GetNumStackedItems", NWScript_GetNumStackedItems);
    lua_register(L, "SurrenderToEnemies", NWScript_SurrenderToEnemies);
    lua_register(L, "EffectMissChance", NWScript_EffectMissChance);
    lua_register(L, "GetTurnResistanceHD", NWScript_GetTurnResistanceHD);
    lua_register(L, "GetCreatureSize", NWScript_GetCreatureSize);
    lua_register(L, "EffectDisappearAppear", NWScript_EffectDisappearAppear);
    lua_register(L, "EffectDisappear", NWScript_EffectDisappear);
    lua_register(L, "EffectAppear", NWScript_EffectAppear);
    lua_register(L, "ActionUnlockObject", NWScript_ActionUnlockObject);
    lua_register(L, "ActionLockObject", NWScript_ActionLockObject);
    lua_register(L, "EffectModifyAttacks", NWScript_EffectModifyAttacks);
    lua_register(L, "GetLastTrapDetected", NWScript_GetLastTrapDetected);
    lua_register(L, "EffectDamageShield", NWScript_EffectDamageShield);
    lua_register(L, "GetNearestTrapToObject", NWScript_GetNearestTrapToObject);
    lua_register(L, "GetDeity", NWScript_GetDeity);
    lua_register(L, "GetSubRace", NWScript_GetSubRace);
    lua_register(L, "GetFortitudeSavingThrow", NWScript_GetFortitudeSavingThrow);
    lua_register(L, "GetWillSavingThrow", NWScript_GetWillSavingThrow);
    lua_register(L, "GetReflexSavingThrow", NWScript_GetReflexSavingThrow);
    lua_register(L, "GetChallengeRating", NWScript_GetChallengeRating);
    lua_register(L, "GetAge", NWScript_GetAge);
    lua_register(L, "GetMovementRate", NWScript_GetMovementRate);
    lua_register(L, "GetFamiliarCreatureType", NWScript_GetFamiliarCreatureType);
    lua_register(L, "GetAnimalCompanionCreatureType", NWScript_GetAnimalCompanionCreatureType);
    lua_register(L, "GetFamiliarName", NWScript_GetFamiliarName);
    lua_register(L, "GetAnimalCompanionName", NWScript_GetAnimalCompanionName);
    lua_register(L, "ActionCastFakeSpellAtObject", NWScript_ActionCastFakeSpellAtObject);
    lua_register(L, "ActionCastFakeSpellAtLocation", NWScript_ActionCastFakeSpellAtLocation);
    lua_register(L, "RemoveSummonedAssociate", NWScript_RemoveSummonedAssociate);
    lua_register(L, "SetCameraMode", NWScript_SetCameraMode);
    lua_register(L, "GetIsResting", NWScript_GetIsResting);
    lua_register(L, "GetLastPCRested", NWScript_GetLastPCRested);
    lua_register(L, "SetWeather", NWScript_SetWeather);
    lua_register(L, "GetLastRestEventType", NWScript_GetLastRestEventType);
    lua_register(L, "StartNewModule", NWScript_StartNewModule);
    lua_register(L, "EffectSwarm", NWScript_EffectSwarm);
    lua_register(L, "GetWeaponRanged", NWScript_GetWeaponRanged);
    lua_register(L, "DoSinglePlayerAutoSave", NWScript_DoSinglePlayerAutoSave);
    lua_register(L, "GetGameDifficulty", NWScript_GetGameDifficulty);
    lua_register(L, "SetTileMainLightColor", NWScript_SetTileMainLightColor);
    lua_register(L, "SetTileSourceLightColor", NWScript_SetTileSourceLightColor);
    lua_register(L, "RecomputeStaticLighting", NWScript_RecomputeStaticLighting);
    lua_register(L, "GetTileMainLight1Color", NWScript_GetTileMainLight1Color);
    lua_register(L, "GetTileMainLight2Color", NWScript_GetTileMainLight2Color);
    lua_register(L, "GetTileSourceLight1Color", NWScript_GetTileSourceLight1Color);
    lua_register(L, "GetTileSourceLight2Color", NWScript_GetTileSourceLight2Color);
    lua_register(L, "SetPanelButtonFlash", NWScript_SetPanelButtonFlash);
    lua_register(L, "GetCurrentAction", NWScript_GetCurrentAction);
    lua_register(L, "SetStandardFactionReputation", NWScript_SetStandardFactionReputation);
    lua_register(L, "GetStandardFactionReputation", NWScript_GetStandardFactionReputation);
    lua_register(L, "FloatingTextStrRefOnCreature", NWScript_FloatingTextStrRefOnCreature);
    lua_register(L, "FloatingTextStringOnCreature", NWScript_FloatingTextStringOnCreature);
    lua_register(L, "GetTrapDisarmable", NWScript_GetTrapDisarmable);
    lua_register(L, "GetTrapDetectable", NWScript_GetTrapDetectable);
    lua_register(L, "GetTrapDetectedBy", NWScript_GetTrapDetectedBy);
    lua_register(L, "GetTrapFlagged", NWScript_GetTrapFlagged);
    lua_register(L, "GetTrapBaseType", NWScript_GetTrapBaseType);
    lua_register(L, "GetTrapOneShot", NWScript_GetTrapOneShot);
    lua_register(L, "GetTrapCreator", NWScript_GetTrapCreator);
    lua_register(L, "GetTrapKeyTag", NWScript_GetTrapKeyTag);
    lua_register(L, "GetTrapDisarmDC", NWScript_GetTrapDisarmDC);
    lua_register(L, "GetTrapDetectDC", NWScript_GetTrapDetectDC);
    lua_register(L, "GetLockKeyRequired", NWScript_GetLockKeyRequired);
    lua_register(L, "GetLockKeyTag", NWScript_GetLockKeyTag);
    lua_register(L, "GetLockLockable", NWScript_GetLockLockable);
    lua_register(L, "GetLockUnlockDC", NWScript_GetLockUnlockDC);
    lua_register(L, "GetLockLockDC", NWScript_GetLockLockDC);
    lua_register(L, "GetPCLevellingUp", NWScript_GetPCLevellingUp);
    lua_register(L, "GetHasFeatEffect", NWScript_GetHasFeatEffect);
    lua_register(L, "SetPlaceableIllumination", NWScript_SetPlaceableIllumination);
    lua_register(L, "GetPlaceableIllumination", NWScript_GetPlaceableIllumination);
    lua_register(L, "GetIsPlaceableObjectActionPossible", NWScript_GetIsPlaceableObjectActionPossible);
    lua_register(L, "DoPlaceableObjectAction", NWScript_DoPlaceableObjectAction);
    lua_register(L, "GetFirstPC", NWScript_GetFirstPC);
    lua_register(L, "GetNextPC", NWScript_GetNextPC);
    lua_register(L, "SetTrapDetectedBy", NWScript_SetTrapDetectedBy);
    lua_register(L, "GetIsTrapped", NWScript_GetIsTrapped);
    lua_register(L, "EffectTurnResistanceDecrease", NWScript_EffectTurnResistanceDecrease);
    lua_register(L, "EffectTurnResistanceIncrease", NWScript_EffectTurnResistanceIncrease);
    lua_register(L, "PopUpDeathGUIPanel", NWScript_PopUpDeathGUIPanel);
    lua_register(L, "SetTrapDisabled", NWScript_SetTrapDisabled);
    lua_register(L, "GetLastHostileActor", NWScript_GetLastHostileActor);
    lua_register(L, "ExportAllCharacters", NWScript_ExportAllCharacters);
    lua_register(L, "MusicBackgroundGetDayTrack", NWScript_MusicBackgroundGetDayTrack);
    lua_register(L, "MusicBackgroundGetNightTrack", NWScript_MusicBackgroundGetNightTrack);
    lua_register(L, "WriteTimestampedLogEntry", NWScript_WriteTimestampedLogEntry);
    lua_register(L, "GetModuleName", NWScript_GetModuleName);
    lua_register(L, "GetFactionLeader", NWScript_GetFactionLeader);
    lua_register(L, "SendMessageToAllDMs", NWScript_SendMessageToAllDMs);
    lua_register(L, "EndGame", NWScript_EndGame);
    lua_register(L, "BootPC", NWScript_BootPC);
    lua_register(L, "ActionCounterSpell", NWScript_ActionCounterSpell);
    lua_register(L, "AmbientSoundSetDayVolume", NWScript_AmbientSoundSetDayVolume);
    lua_register(L, "AmbientSoundSetNightVolume", NWScript_AmbientSoundSetNightVolume);
    lua_register(L, "MusicBackgroundGetBattleTrack", NWScript_MusicBackgroundGetBattleTrack);
    lua_register(L, "GetHasInventory", NWScript_GetHasInventory);
    lua_register(L, "GetStrRefSoundDuration", NWScript_GetStrRefSoundDuration);
    lua_register(L, "AddToParty", NWScript_AddToParty);
    lua_register(L, "RemoveFromParty", NWScript_RemoveFromParty);
    lua_register(L, "GetStealthMode", NWScript_GetStealthMode);
    lua_register(L, "GetDetectMode", NWScript_GetDetectMode);
    lua_register(L, "GetDefensiveCastingMode", NWScript_GetDefensiveCastingMode);
    lua_register(L, "GetAppearanceType", NWScript_GetAppearanceType);
    lua_register(L, "SpawnScriptDebugger", NWScript_SpawnScriptDebugger);
    lua_register(L, "GetModuleItemAcquiredStackSize", NWScript_GetModuleItemAcquiredStackSize);
    lua_register(L, "DecrementRemainingFeatUses", NWScript_DecrementRemainingFeatUses);
    lua_register(L, "DecrementRemainingSpellUses", NWScript_DecrementRemainingSpellUses);
    lua_register(L, "GetResRef", NWScript_GetResRef);
    lua_register(L, "EffectPetrify", NWScript_EffectPetrify);
    lua_register(L, "CopyItem", NWScript_CopyItem);
    lua_register(L, "EffectCutsceneParalyze", NWScript_EffectCutsceneParalyze);
    lua_register(L, "GetDroppableFlag", NWScript_GetDroppableFlag);
    lua_register(L, "GetUseableFlag", NWScript_GetUseableFlag);
    lua_register(L, "GetStolenFlag", NWScript_GetStolenFlag);
    lua_register(L, "SetCampaignFloat", NWScript_SetCampaignFloat);
    lua_register(L, "SetCampaignInt", NWScript_SetCampaignInt);
    lua_register(L, "SetCampaignVector", NWScript_SetCampaignVector);
    lua_register(L, "SetCampaignLocation", NWScript_SetCampaignLocation);
    lua_register(L, "SetCampaignString", NWScript_SetCampaignString);
    lua_register(L, "DestroyCampaignDatabase", NWScript_DestroyCampaignDatabase);
    lua_register(L, "GetCampaignFloat", NWScript_GetCampaignFloat);
    lua_register(L, "GetCampaignInt", NWScript_GetCampaignInt);
    lua_register(L, "GetCampaignVector", NWScript_GetCampaignVector);
    lua_register(L, "GetCampaignLocation", NWScript_GetCampaignLocation);
    lua_register(L, "GetCampaignString", NWScript_GetCampaignString);
    lua_register(L, "CopyObject", NWScript_CopyObject);
    lua_register(L, "DeleteCampaignVariable", NWScript_DeleteCampaignVariable);
    lua_register(L, "StoreCampaignObject", NWScript_StoreCampaignObject);
    lua_register(L, "RetrieveCampaignObject", NWScript_RetrieveCampaignObject);
    lua_register(L, "EffectCutsceneDominated", NWScript_EffectCutsceneDominated);
    lua_register(L, "GetItemStackSize", NWScript_GetItemStackSize);
    lua_register(L, "SetItemStackSize", NWScript_SetItemStackSize);
    lua_register(L, "GetItemCharges", NWScript_GetItemCharges);
    lua_register(L, "SetItemCharges", NWScript_SetItemCharges);
    lua_register(L, "AddItemProperty", NWScript_AddItemProperty);
    lua_register(L, "RemoveItemProperty", NWScript_RemoveItemProperty);
    lua_register(L, "GetIsItemPropertyValid", NWScript_GetIsItemPropertyValid);
    lua_register(L, "GetFirstItemProperty", NWScript_GetFirstItemProperty);
    lua_register(L, "GetNextItemProperty", NWScript_GetNextItemProperty);
    lua_register(L, "GetItemPropertyType", NWScript_GetItemPropertyType);
    lua_register(L, "GetItemPropertyDurationType", NWScript_GetItemPropertyDurationType);
    lua_register(L, "ItemPropertyAbilityBonus", NWScript_ItemPropertyAbilityBonus);
    lua_register(L, "ItemPropertyACBonus", NWScript_ItemPropertyACBonus);
    lua_register(L, "ItemPropertyACBonusVsAlign", NWScript_ItemPropertyACBonusVsAlign);
    lua_register(L, "ItemPropertyACBonusVsDmgType", NWScript_ItemPropertyACBonusVsDmgType);
    lua_register(L, "ItemPropertyACBonusVsRace", NWScript_ItemPropertyACBonusVsRace);
    lua_register(L, "ItemPropertyACBonusVsSAlign", NWScript_ItemPropertyACBonusVsSAlign);
    lua_register(L, "ItemPropertyEnhancementBonus", NWScript_ItemPropertyEnhancementBonus);
    lua_register(L, "ItemPropertyEnhancementBonusVsAlign", NWScript_ItemPropertyEnhancementBonusVsAlign);
    lua_register(L, "ItemPropertyEnhancementBonusVsRace", NWScript_ItemPropertyEnhancementBonusVsRace);
    lua_register(L, "ItemPropertyEnhancementBonusVsSAlign", NWScript_ItemPropertyEnhancementBonusVsSAlign);
    lua_register(L, "ItemPropertyEnhancementPenalty", NWScript_ItemPropertyEnhancementPenalty);
    lua_register(L, "ItemPropertyWeightReduction", NWScript_ItemPropertyWeightReduction);
    lua_register(L, "ItemPropertyBonusFeat", NWScript_ItemPropertyBonusFeat);
    lua_register(L, "ItemPropertyBonusLevelSpell", NWScript_ItemPropertyBonusLevelSpell);
    lua_register(L, "ItemPropertyCastSpell", NWScript_ItemPropertyCastSpell);
    lua_register(L, "ItemPropertyDamageBonus", NWScript_ItemPropertyDamageBonus);
    lua_register(L, "ItemPropertyDamageBonusVsAlign", NWScript_ItemPropertyDamageBonusVsAlign);
    lua_register(L, "ItemPropertyDamageBonusVsRace", NWScript_ItemPropertyDamageBonusVsRace);
    lua_register(L, "ItemPropertyDamageBonusVsSAlign", NWScript_ItemPropertyDamageBonusVsSAlign);
    lua_register(L, "ItemPropertyDamageImmunity", NWScript_ItemPropertyDamageImmunity);
    lua_register(L, "ItemPropertyDamagePenalty", NWScript_ItemPropertyDamagePenalty);
    lua_register(L, "ItemPropertyDamageReduction", NWScript_ItemPropertyDamageReduction);
    lua_register(L, "ItemPropertyDamageResistance", NWScript_ItemPropertyDamageResistance);
    lua_register(L, "ItemPropertyDamageVulnerability", NWScript_ItemPropertyDamageVulnerability);
    lua_register(L, "ItemPropertyDarkvision", NWScript_ItemPropertyDarkvision);
    lua_register(L, "ItemPropertyDecreaseAbility", NWScript_ItemPropertyDecreaseAbility);
    lua_register(L, "ItemPropertyDecreaseAC", NWScript_ItemPropertyDecreaseAC);
    lua_register(L, "ItemPropertyDecreaseSkill", NWScript_ItemPropertyDecreaseSkill);
    lua_register(L, "ItemPropertyContainerReducedWeight", NWScript_ItemPropertyContainerReducedWeight);
    lua_register(L, "ItemPropertyExtraMeleeDamageType", NWScript_ItemPropertyExtraMeleeDamageType);
    lua_register(L, "ItemPropertyExtraRangeDamageType", NWScript_ItemPropertyExtraRangeDamageType);
    lua_register(L, "ItemPropertyHaste", NWScript_ItemPropertyHaste);
    lua_register(L, "ItemPropertyHolyAvenger", NWScript_ItemPropertyHolyAvenger);
    lua_register(L, "ItemPropertyImmunityMisc", NWScript_ItemPropertyImmunityMisc);
    lua_register(L, "ItemPropertyImprovedEvasion", NWScript_ItemPropertyImprovedEvasion);
    lua_register(L, "ItemPropertyBonusSpellResistance", NWScript_ItemPropertyBonusSpellResistance);
    lua_register(L, "ItemPropertyBonusSavingThrowVsX", NWScript_ItemPropertyBonusSavingThrowVsX);
    lua_register(L, "ItemPropertyBonusSavingThrow", NWScript_ItemPropertyBonusSavingThrow);
    lua_register(L, "ItemPropertyKeen", NWScript_ItemPropertyKeen);
    lua_register(L, "ItemPropertyLight", NWScript_ItemPropertyLight);
    lua_register(L, "ItemPropertyMaxRangeStrengthMod", NWScript_ItemPropertyMaxRangeStrengthMod);
    lua_register(L, "ItemPropertyNoDamage", NWScript_ItemPropertyNoDamage);
    lua_register(L, "ItemPropertyOnHitProps", NWScript_ItemPropertyOnHitProps);
    lua_register(L, "ItemPropertyReducedSavingThrowVsX", NWScript_ItemPropertyReducedSavingThrowVsX);
    lua_register(L, "ItemPropertyReducedSavingThrow", NWScript_ItemPropertyReducedSavingThrow);
    lua_register(L, "ItemPropertyRegeneration", NWScript_ItemPropertyRegeneration);
    lua_register(L, "ItemPropertySkillBonus", NWScript_ItemPropertySkillBonus);
    lua_register(L, "ItemPropertySpellImmunitySpecific", NWScript_ItemPropertySpellImmunitySpecific);
    lua_register(L, "ItemPropertySpellImmunitySchool", NWScript_ItemPropertySpellImmunitySchool);
    lua_register(L, "ItemPropertyThievesTools", NWScript_ItemPropertyThievesTools);
    lua_register(L, "ItemPropertyAttackBonus", NWScript_ItemPropertyAttackBonus);
    lua_register(L, "ItemPropertyAttackBonusVsAlign", NWScript_ItemPropertyAttackBonusVsAlign);
    lua_register(L, "ItemPropertyAttackBonusVsRace", NWScript_ItemPropertyAttackBonusVsRace);
    lua_register(L, "ItemPropertyAttackBonusVsSAlign", NWScript_ItemPropertyAttackBonusVsSAlign);
    lua_register(L, "ItemPropertyAttackPenalty", NWScript_ItemPropertyAttackPenalty);
    lua_register(L, "ItemPropertyUnlimitedAmmo", NWScript_ItemPropertyUnlimitedAmmo);
    lua_register(L, "ItemPropertyLimitUseByAlign", NWScript_ItemPropertyLimitUseByAlign);
    lua_register(L, "ItemPropertyLimitUseByClass", NWScript_ItemPropertyLimitUseByClass);
    lua_register(L, "ItemPropertyLimitUseByRace", NWScript_ItemPropertyLimitUseByRace);
    lua_register(L, "ItemPropertyLimitUseBySAlign", NWScript_ItemPropertyLimitUseBySAlign);
    lua_register(L, "BadBadReplaceMeThisDoesNothing", NWScript_BadBadReplaceMeThisDoesNothing);
    lua_register(L, "ItemPropertyVampiricRegeneration", NWScript_ItemPropertyVampiricRegeneration);
    lua_register(L, "ItemPropertyTrap", NWScript_ItemPropertyTrap);
    lua_register(L, "ItemPropertyTrueSeeing", NWScript_ItemPropertyTrueSeeing);
    lua_register(L, "ItemPropertyOnMonsterHitProperties", NWScript_ItemPropertyOnMonsterHitProperties);
    lua_register(L, "ItemPropertyTurnResistance", NWScript_ItemPropertyTurnResistance);
    lua_register(L, "ItemPropertyMassiveCritical", NWScript_ItemPropertyMassiveCritical);
    lua_register(L, "ItemPropertyFreeAction", NWScript_ItemPropertyFreeAction);
    lua_register(L, "ItemPropertyMonsterDamage", NWScript_ItemPropertyMonsterDamage);
    lua_register(L, "ItemPropertyImmunityToSpellLevel", NWScript_ItemPropertyImmunityToSpellLevel);
    lua_register(L, "ItemPropertySpecialWalk", NWScript_ItemPropertySpecialWalk);
    lua_register(L, "ItemPropertyHealersKit", NWScript_ItemPropertyHealersKit);
    lua_register(L, "ItemPropertyWeightIncrease", NWScript_ItemPropertyWeightIncrease);
    lua_register(L, "GetIsSkillSuccessful", NWScript_GetIsSkillSuccessful);
    lua_register(L, "EffectSpellFailure", NWScript_EffectSpellFailure);
    lua_register(L, "SpeakStringByStrRef", NWScript_SpeakStringByStrRef);
    lua_register(L, "SetCutsceneMode", NWScript_SetCutsceneMode);
    lua_register(L, "GetLastPCToCancelCutscene", NWScript_GetLastPCToCancelCutscene);
    lua_register(L, "GetDialogSoundLength", NWScript_GetDialogSoundLength);
    lua_register(L, "FadeFromBlack", NWScript_FadeFromBlack);
    lua_register(L, "FadeToBlack", NWScript_FadeToBlack);
    lua_register(L, "StopFade", NWScript_StopFade);
    lua_register(L, "BlackScreen", NWScript_BlackScreen);
    lua_register(L, "GetBaseAttackBonus", NWScript_GetBaseAttackBonus);
    lua_register(L, "SetImmortal", NWScript_SetImmortal);
    lua_register(L, "OpenInventory", NWScript_OpenInventory);
    lua_register(L, "StoreCameraFacing", NWScript_StoreCameraFacing);
    lua_register(L, "RestoreCameraFacing", NWScript_RestoreCameraFacing);
    lua_register(L, "LevelUpHenchman", NWScript_LevelUpHenchman);
    lua_register(L, "SetDroppableFlag", NWScript_SetDroppableFlag);
    lua_register(L, "GetWeight", NWScript_GetWeight);
    lua_register(L, "GetModuleItemAcquiredBy", NWScript_GetModuleItemAcquiredBy);
    lua_register(L, "GetImmortal", NWScript_GetImmortal);
    lua_register(L, "DoWhirlwindAttack", NWScript_DoWhirlwindAttack);
    lua_register(L, "Get2DAString", NWScript_Get2DAString);
    lua_register(L, "EffectEthereal", NWScript_EffectEthereal);
    lua_register(L, "GetAILevel", NWScript_GetAILevel);
    lua_register(L, "SetAILevel", NWScript_SetAILevel);
    lua_register(L, "GetIsPossessedFamiliar", NWScript_GetIsPossessedFamiliar);
    lua_register(L, "UnpossessFamiliar", NWScript_UnpossessFamiliar);
    lua_register(L, "GetIsAreaInterior", NWScript_GetIsAreaInterior);
    lua_register(L, "SendMessageToPCByStrRef", NWScript_SendMessageToPCByStrRef);
    lua_register(L, "IncrementRemainingFeatUses", NWScript_IncrementRemainingFeatUses);
    lua_register(L, "ExportSingleCharacter", NWScript_ExportSingleCharacter);
    lua_register(L, "PlaySoundByStrRef", NWScript_PlaySoundByStrRef);
    lua_register(L, "SetSubRace", NWScript_SetSubRace);
    lua_register(L, "SetDeity", NWScript_SetDeity);
    lua_register(L, "GetIsDMPossessed", NWScript_GetIsDMPossessed);
    lua_register(L, "GetWeather", NWScript_GetWeather);
    lua_register(L, "GetIsAreaNatural", NWScript_GetIsAreaNatural);
    lua_register(L, "GetIsAreaAboveGround", NWScript_GetIsAreaAboveGround);
    lua_register(L, "GetPCItemLastEquipped", NWScript_GetPCItemLastEquipped);
    lua_register(L, "GetPCItemLastEquippedBy", NWScript_GetPCItemLastEquippedBy);
    lua_register(L, "GetPCItemLastUnequipped", NWScript_GetPCItemLastUnequipped);
    lua_register(L, "GetPCItemLastUnequippedBy", NWScript_GetPCItemLastUnequippedBy);
    lua_register(L, "CopyItemAndModify", NWScript_CopyItemAndModify);
    lua_register(L, "GetItemAppearance", NWScript_GetItemAppearance);
    lua_register(L, "ItemPropertyOnHitCastSpell", NWScript_ItemPropertyOnHitCastSpell);
    lua_register(L, "GetItemPropertySubType", NWScript_GetItemPropertySubType);
    lua_register(L, "GetActionMode", NWScript_GetActionMode);
    lua_register(L, "SetActionMode", NWScript_SetActionMode);
    lua_register(L, "GetArcaneSpellFailure", NWScript_GetArcaneSpellFailure);
    lua_register(L, "ActionExamine", NWScript_ActionExamine);
    lua_register(L, "ItemPropertyVisualEffect", NWScript_ItemPropertyVisualEffect);
    lua_register(L, "SetLootable", NWScript_SetLootable);
    lua_register(L, "GetLootable", NWScript_GetLootable);
    lua_register(L, "GetCutsceneCameraMoveRate", NWScript_GetCutsceneCameraMoveRate);
    lua_register(L, "SetCutsceneCameraMoveRate", NWScript_SetCutsceneCameraMoveRate);
    lua_register(L, "GetItemCursedFlag", NWScript_GetItemCursedFlag);
    lua_register(L, "SetItemCursedFlag", NWScript_SetItemCursedFlag);
    lua_register(L, "SetMaxHenchmen", NWScript_SetMaxHenchmen);
    lua_register(L, "GetMaxHenchmen", NWScript_GetMaxHenchmen);
    lua_register(L, "GetAssociateType", NWScript_GetAssociateType);
    lua_register(L, "GetSpellResistance", NWScript_GetSpellResistance);
    lua_register(L, "DayToNight", NWScript_DayToNight);
    lua_register(L, "NightToDay", NWScript_NightToDay);
    lua_register(L, "LineOfSightObject", NWScript_LineOfSightObject);
    lua_register(L, "LineOfSightVector", NWScript_LineOfSightVector);
    lua_register(L, "GetLastSpellCastClass", NWScript_GetLastSpellCastClass);
    lua_register(L, "SetBaseAttackBonus", NWScript_SetBaseAttackBonus);
    lua_register(L, "RestoreBaseAttackBonus", NWScript_RestoreBaseAttackBonus);
    lua_register(L, "EffectCutsceneGhost", NWScript_EffectCutsceneGhost);
    lua_register(L, "ItemPropertyArcaneSpellFailure", NWScript_ItemPropertyArcaneSpellFailure);
    lua_register(L, "GetStoreGold", NWScript_GetStoreGold);
    lua_register(L, "SetStoreGold", NWScript_SetStoreGold);
    lua_register(L, "GetStoreMaxBuyPrice", NWScript_GetStoreMaxBuyPrice);
    lua_register(L, "SetStoreMaxBuyPrice", NWScript_SetStoreMaxBuyPrice);
    lua_register(L, "GetStoreIdentifyCost", NWScript_GetStoreIdentifyCost);
    lua_register(L, "SetStoreIdentifyCost", NWScript_SetStoreIdentifyCost);
    lua_register(L, "SetCreatureAppearanceType", NWScript_SetCreatureAppearanceType);
    lua_register(L, "GetCreatureStartingPackage", NWScript_GetCreatureStartingPackage);
    lua_register(L, "EffectCutsceneImmobilize", NWScript_EffectCutsceneImmobilize);
    lua_register(L, "GetIsInSubArea", NWScript_GetIsInSubArea);
    lua_register(L, "GetItemPropertyCostTable", NWScript_GetItemPropertyCostTable);
    lua_register(L, "GetItemPropertyCostTableValue", NWScript_GetItemPropertyCostTableValue);
    lua_register(L, "GetItemPropertyParam1", NWScript_GetItemPropertyParam1);
    lua_register(L, "GetItemPropertyParam1Value", NWScript_GetItemPropertyParam1Value);
    lua_register(L, "GetIsCreatureDisarmable", NWScript_GetIsCreatureDisarmable);
    lua_register(L, "SetStolenFlag", NWScript_SetStolenFlag);
    lua_register(L, "ForceRest", NWScript_ForceRest);
    lua_register(L, "SetCameraHeight", NWScript_SetCameraHeight);
    lua_register(L, "SetSkyBox", NWScript_SetSkyBox);
    lua_register(L, "GetPhenoType", NWScript_GetPhenoType);
    lua_register(L, "SetPhenoType", NWScript_SetPhenoType);
    lua_register(L, "SetFogColor", NWScript_SetFogColor);
    lua_register(L, "GetCutsceneMode", NWScript_GetCutsceneMode);
    lua_register(L, "GetSkyBox", NWScript_GetSkyBox);
    lua_register(L, "GetFogColor", NWScript_GetFogColor);
    lua_register(L, "SetFogAmount", NWScript_SetFogAmount);
    lua_register(L, "GetFogAmount", NWScript_GetFogAmount);
    lua_register(L, "GetPickpocketableFlag", NWScript_GetPickpocketableFlag);
    lua_register(L, "SetPickpocketableFlag", NWScript_SetPickpocketableFlag);
    lua_register(L, "GetFootstepType", NWScript_GetFootstepType);
    lua_register(L, "SetFootstepType", NWScript_SetFootstepType);
    lua_register(L, "GetCreatureWingType", NWScript_GetCreatureWingType);
    lua_register(L, "SetCreatureWingType", NWScript_SetCreatureWingType);
    lua_register(L, "GetCreatureBodyPart", NWScript_GetCreatureBodyPart);
    lua_register(L, "SetCreatureBodyPart", NWScript_SetCreatureBodyPart);
    lua_register(L, "GetCreatureTailType", NWScript_GetCreatureTailType);
    lua_register(L, "SetCreatureTailType", NWScript_SetCreatureTailType);
    lua_register(L, "GetHardness", NWScript_GetHardness);
    lua_register(L, "SetHardness", NWScript_SetHardness);
    lua_register(L, "SetLockKeyRequired", NWScript_SetLockKeyRequired);
    lua_register(L, "SetLockKeyTag", NWScript_SetLockKeyTag);
    lua_register(L, "SetLockLockable", NWScript_SetLockLockable);
    lua_register(L, "SetLockUnlockDC", NWScript_SetLockUnlockDC);
    lua_register(L, "SetLockLockDC", NWScript_SetLockLockDC);
    lua_register(L, "SetTrapDisarmable", NWScript_SetTrapDisarmable);
    lua_register(L, "SetTrapDetectable", NWScript_SetTrapDetectable);
    lua_register(L, "SetTrapOneShot", NWScript_SetTrapOneShot);
    lua_register(L, "SetTrapKeyTag", NWScript_SetTrapKeyTag);
    lua_register(L, "SetTrapDisarmDC", NWScript_SetTrapDisarmDC);
    lua_register(L, "SetTrapDetectDC", NWScript_SetTrapDetectDC);
    lua_register(L, "CreateTrapAtLocation", NWScript_CreateTrapAtLocation);
    lua_register(L, "CreateTrapOnObject", NWScript_CreateTrapOnObject);
    lua_register(L, "SetWillSavingThrow", NWScript_SetWillSavingThrow);
    lua_register(L, "SetReflexSavingThrow", NWScript_SetReflexSavingThrow);
    lua_register(L, "SetFortitudeSavingThrow", NWScript_SetFortitudeSavingThrow);
    lua_register(L, "GetTilesetResRef", NWScript_GetTilesetResRef);
    lua_register(L, "GetTrapRecoverable", NWScript_GetTrapRecoverable);
    lua_register(L, "SetTrapRecoverable", NWScript_SetTrapRecoverable);
    lua_register(L, "GetModuleXPScale", NWScript_GetModuleXPScale);
    lua_register(L, "SetModuleXPScale", NWScript_SetModuleXPScale);
    lua_register(L, "GetKeyRequiredFeedback", NWScript_GetKeyRequiredFeedback);
    lua_register(L, "SetKeyRequiredFeedback", NWScript_SetKeyRequiredFeedback);
    lua_register(L, "GetTrapActive", NWScript_GetTrapActive);
    lua_register(L, "SetTrapActive", NWScript_SetTrapActive);
    lua_register(L, "LockCameraPitch", NWScript_LockCameraPitch);
    lua_register(L, "LockCameraDistance", NWScript_LockCameraDistance);
    lua_register(L, "LockCameraDirection", NWScript_LockCameraDirection);
    lua_register(L, "GetPlaceableLastClickedBy", NWScript_GetPlaceableLastClickedBy);
    lua_register(L, "GetInfiniteFlag", NWScript_GetInfiniteFlag);
    lua_register(L, "SetInfiniteFlag", NWScript_SetInfiniteFlag);
    lua_register(L, "GetAreaSize", NWScript_GetAreaSize);
    lua_register(L, "SetName", NWScript_SetName);
    lua_register(L, "GetPortraitId", NWScript_GetPortraitId);
    lua_register(L, "SetPortraitId", NWScript_SetPortraitId);
    lua_register(L, "GetPortraitResRef", NWScript_GetPortraitResRef);
    lua_register(L, "SetPortraitResRef", NWScript_SetPortraitResRef);
    lua_register(L, "SetUseableFlag", NWScript_SetUseableFlag);
    lua_register(L, "GetDescription", NWScript_GetDescription);
    lua_register(L, "SetDescription", NWScript_SetDescription);
    lua_register(L, "GetPCChatSpeaker", NWScript_GetPCChatSpeaker);
    lua_register(L, "GetPCChatMessage", NWScript_GetPCChatMessage);
    lua_register(L, "GetPCChatVolume", NWScript_GetPCChatVolume);
    lua_register(L, "SetPCChatMessage", NWScript_SetPCChatMessage);
    lua_register(L, "SetPCChatVolume", NWScript_SetPCChatVolume);
    lua_register(L, "GetColor", NWScript_GetColor);
    lua_register(L, "SetColor", NWScript_SetColor);
    lua_register(L, "ItemPropertyMaterial", NWScript_ItemPropertyMaterial);
    lua_register(L, "ItemPropertyQuality", NWScript_ItemPropertyQuality);
    lua_register(L, "ItemPropertyAdditional", NWScript_ItemPropertyAdditional);

}
// VECTOR

static int vector_get_x(lua_State *L)
{
    Vector *ptr = (Vector *)luaL_checkudata(L, 1, VECTOR);
    lua_pushnumber(L, ptr->X);
    return 1;
}

static int vector_get_y(lua_State *L)
{
    Vector *ptr = (Vector *)luaL_checkudata(L, 1, VECTOR);
    lua_pushnumber(L, ptr->Y);
    return 1;
}
static int vector_get_z(lua_State *L)
{
    Vector *ptr = (Vector *)luaL_checkudata(L, 1, VECTOR);
    lua_pushnumber(L, ptr->Z);
    return 1;
}

static int vector_to_string(lua_State *L)
{
    Vector *ptr = (Vector *)luaL_checkudata(L, 1, VECTOR);
    lua_pushfstring(L, "vector: %p", ptr);
    return 1;
}
static int vector_equal(lua_State *L)
{
    Vector *ptr = (Vector *)luaL_checkudata(L, 1, VECTOR);
    Vector *ptr2 = (Vector *)luaL_checkudata(L, 2, VECTOR);

    if ((ptr->X == ptr2->X) && (ptr->Y == ptr2->Y) && (ptr->Z == ptr2->Z)) {
        lua_pushboolean(L, 1);
        return 1;
    }
    lua_pushboolean(L, 0);
    return 1;
}

static const struct luaL_reg vectorlib [] = {
    {"new", NWScript_Vector},
    {"x", vector_get_x},
    {"y", vector_get_y},
    {"z", vector_get_z},
    {"magnitude", NWScript_VectorMagnitude},
    {"normalize", NWScript_VectorNormalize},
    {"toangle", NWScript_VectorToAngle},
    {NULL, NULL}
};

static const struct luaL_reg vectorlib_m [] = {
    {"__tostring", vector_to_string},
    {"__eq", vector_equal},
    {NULL, NULL}
};

int luaopen_vector(lua_State *L)
{
    luaL_register(L, VECTOR, vectorlib);  // create methods table,
    //  add it to the globals
    luaL_newmetatable(L, VECTOR);         // create metatable for Foo,
    //  and add it to the Lua registry
    luaL_register(L, NULL, vectorlib_m);   //    fill metatable
    lua_pushliteral(L, "__index");
    lua_pushvalue(L, -3);                 // dup methods table
    lua_rawset(L, -3);                    // metatable.__index = methods
    lua_pushliteral(L, "__metatable");
    lua_pushvalue(L, -3);                 // dup methods table
    lua_rawset(L, -3);                    // hide metatable:
    //metatable.__metatable = methods
    lua_pop(L, 1);                        // drop metatable
    return 1;                             // return methods on the stack
}


// LOCATION

static int location_get_x(lua_State *L)
{
    CScriptLocation *ptr = (CScriptLocation *)luaL_checklightnwndata(L, 1, LOCATION);
    lua_pushnumber(L, ptr->X);
    return 1;
}
static int location_get_y(lua_State *L)
{
    CScriptLocation *ptr = (CScriptLocation *)luaL_checklightnwndata(L, 1, LOCATION);
    lua_pushnumber(L, ptr->Y);
    return 1;
}
static int location_get_z(lua_State *L)
{
    CScriptLocation *ptr = (CScriptLocation *)luaL_checklightnwndata(L, 1, LOCATION);
    lua_pushnumber(L, ptr->Z);
    return 1;
}
static int location_get_area_id(lua_State *L)
{
    CScriptLocation *ptr = (CScriptLocation *)luaL_checklightnwndata(L, 1, LOCATION);
    lua_pushinteger(L, ptr->AreaID);
    return 1;
}
static int location_get_facing(lua_State *L)
{
    CScriptLocation *ptr = (CScriptLocation *)luaL_checklightnwndata(L, 1, LOCATION);
    lua_pushnumber(L, ptr->OrientationX);
    return 1;
}

static const struct luaL_reg locationlib [] = {
    {"x", location_get_x},
    {"y", location_get_y},
    {"z", location_get_z},
    {"area", location_get_area_id},
    {"facing", location_get_facing},
    {NULL, NULL}
};

int luaopen_location(lua_State *L)
{
    luaL_register(L, LOCATION, locationlib);
    return 1;
}

void lua_setIntConst(lua_State *L, const char *name, int nValue)
{
    lua_pushinteger(L, nValue);
    lua_setglobal(L, name);
}

void LuaInt_DefineConstants(lua_State *L)
{
    luaopen_vector(L);
    luaopen_location(L);
    lua_setIntConst(L, "OBJECT_INVALID", OBJECT_INVALID);
    lua_setIntConst(L, "OBJECT_SELF", OBJECT_INVALID);
}

