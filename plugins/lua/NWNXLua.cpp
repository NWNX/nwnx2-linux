/***************************************************************************
    NWNXLua.cpp - Implementation of the CNWNXLua class.
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

#include <string.h>
#include <string>
#include <stdlib.h>
#include <sys/stat.h>
#include <signal.h>

#include "NWNXLua.h"
#include "FunctionHooks.h"
#include "lua_int.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNWNXLua::CNWNXLua()
{
    confKey = strdup("LUA");
    bHooked = 1;
}

CNWNXLua::~CNWNXLua()
{
    OnRelease();
}

bool CNWNXLua::OnCreate(gline *config, const char *LogDir)
{
    char log[128];
    struct stat statbuf;
    int i = 0;
    sprintf(log, "%s/nwnx_lua.txt", LogDir);

    // call the base class function
    if (!CNWNXBase::OnCreate(config, log))
        return false;

    Log(0, "NWNX Lua V.1.0.0\n");
    Log(0, "(c) by pardik, 2010\n");
    LuaInstance = lua_open();
    luaL_openlibs(LuaInstance);
    LuaInt_DefineConstants(LuaInstance);
    LUA_InitNWScript(LuaInstance);
    luaL_dostring(LuaInstance, "print(\"NWNX Lua Initialized\")\n");

    char *preload = (char*)((*nwnxConfig)[confKey]["preload"].c_str());
    event_method = (char*)((*nwnxConfig)[confKey]["eventListener"].c_str());
    token_method = (char*)((*nwnxConfig)[confKey]["tokenListener"].c_str());
    sco_method = (char*)((*nwnxConfig)[confKey]["sco"].c_str());
    rco_method = (char*)((*nwnxConfig)[confKey]["rco"].c_str());

    if (strlen(preload) > 0) {
        int nError;
        Log(0, "Preloading: %s\n", preload);
        nError = luaL_dofile(LuaInstance, preload);
        if (nError) {
            char *fLastError = (char *)lua_tostring(LuaInstance, -1);
            Log(0, "Error %d while evaluating a Lua expression: %s\n", nError, fLastError);
            lua_pop(LuaInstance, 1);
            return false;
        }
    }

    if (strlen(event_method) > 0) {
        Log(0, "Event Listener: %s\n", event_method);
    }
    if (strlen(token_method) > 0) {
        Log(0, "Token Listener: %s\n", token_method);
    }
    if (strlen(sco_method) > 0) {
        Log(0, "SCO Listener: %s\n", sco_method);
    }
    if (strlen(rco_method) > 0) {
        Log(0, "RCO Listener: %s\n", rco_method);
    }

    if (HookFunctions()) {
        bHooked = 1;
        Log(0, "* Module loaded successfully.\n");
    } else {
        bHooked = 0;
        Log(0, "* Module loaded successfully.\n");
        Log(0, "* Signature recognition failed. Some functions will be disabled.\n");
        //return false;
    }
    return true;
}

void CNWNXLua::Event(char *value)
{
    //Changed to call directly event listener
    if (event_method == NULL) return;
    const char* event = strtok(value, ":");
    const char* oid  = strtok(NULL, ":");

    lua_getglobal(LuaInstance, event_method);  /* function to be called */
    lua_pushstring(LuaInstance, event);   /* push 1st argument */
    lua_pushinteger(LuaInstance, strtol(oid, NULL, 16)); /* push 2nd argument */

    if (lua_pcall(LuaInstance, 2, 0, 0) != 0)
        Log(0, "error running event %s on Object 0x%x : %s\n", event, oid, lua_tostring(LuaInstance, -1));
    lua_pop(LuaInstance, lua_gettop(LuaInstance));
}

void CNWNXLua::Token(char *value)
{
    //Changed to call directly token listener
    if (token_method == NULL) return;
    lua_getglobal(LuaInstance, token_method);  /* function to be called */
    lua_pushstring(LuaInstance, (const char*)value);   /* push 1st argument */
    if (lua_pcall(LuaInstance, 1, 0, 0) != 0)
        Log(0, "error running token %s : %s\n", value, lua_tostring(LuaInstance, -1));
    lua_pop(LuaInstance, lua_gettop(LuaInstance));
}

char *CNWNXLua::Eval(char *value)
{
    //Evaluate Lua expression (protected)
    try {
        int nError;
        char *buf = NULL;
        size_t lLen = 0;

        nError = luaL_dostring(LuaInstance, value);
        if (nError) {
            char *fLastError = (char *)lua_tolstring(LuaInstance, -1, &lLen);
            Log(0, "Error %d while evaluating a Lua expression: %s\n", nError, fLastError);
            buf = (char *)malloc(lLen + 1);
            strcpy(buf, fLastError);
            lua_pop(LuaInstance, lua_gettop(LuaInstance));
            return buf;
        }
        int nNum = lua_gettop(LuaInstance);
        if (nNum) {
            char *sReturn = (char *)lua_tolstring(LuaInstance, -1, &lLen);
            if (lLen > 0) {
                buf = (char *)malloc(lLen + 1);
                strcpy(buf, sReturn);
                Log(3, "Return %s from evaluating a Lua expression\n", buf);
            }
            lua_pop(LuaInstance, nNum);
        }
        return buf;
    } catch (...) {
        Log(0, "Caught a C++ exception while evaluating a Lua expression: %s\n", value);
        return NULL;
    }
}

char* CNWNXLua::OnRequest(char *gameObject, char* Request, char* Parameters)
{
    Log(2, "(S) Request: \"%s\"\n", Request);
    Log(3, "(S) Params:  \"%s\"\n", Parameters);
    // set OBJECT_SELF
    lua_setIntConst(LuaInstance, "OBJECT_SELF", GetObjectSelf());

    if (strncmp(Request, "TOKEN", 5) == 0) {
        Token(Parameters);
        return NULL;
    }

    if (strncmp(Request, "EVENT", 5) == 0) {
        Event(Parameters);
        return NULL;
    } else if (strncmp(Request, "EVAL", 4) == 0) {
        return Eval(Parameters);
    }
    return NULL;
}
bool CNWNXLua::OnRelease()
{
    int nKBytes = lua_gc(LuaInstance, LUA_GCCOUNT, 0);
    Log(0, "o Shutdown.. Memory: %d Kb\n", nKBytes);
    return true;
}

int CNWNXLua::WriteSCO(char* database, char* key, char* player, int flags, unsigned char * pData, int size)
{
    Log(3, "o SCO: db='%s', key='%s', player='%s', flags=%08lX, pData=%08lX, size=%d\n", database, key, player, flags, pData, size);
    if (sco_method == NULL) return 0;
    if (player == NULL) player = (char *)"-";
    lua_getglobal(LuaInstance, sco_method);  /* function to be called */
    lua_pushstring(LuaInstance, key);
    lua_pushstring(LuaInstance, player);
    lua_pushlstring(LuaInstance, (const char*)pData, (size_t)size);
    if (lua_pcall(LuaInstance, 3, 0, 0) != 0) //SCO
        Log(0, "error running sco function %s : %s", sco_method, lua_tostring(LuaInstance, -1));
    return 1;
}

unsigned char* CNWNXLua::ReadSCO(char* database, char* key, char* player, int* arg4, int* size)
{
    *arg4 = 0x4f;
    Log(3, "o RCO(0): db='%s', key='%s', player='%s', arg4=%08lX, size=%d\n", database, key, player, arg4, *size);
    if (rco_method == NULL) return NULL;
    if (player == NULL) player = (char *)"-";
    lua_getglobal(LuaInstance, rco_method);  /* function to be called */
    lua_pushstring(LuaInstance, key);
    lua_pushstring(LuaInstance, player);
    if (lua_pcall(LuaInstance, 2, 1, 0) != 0) { //RCO
        Log(0, "error running rco function %s : %s", rco_method, lua_tostring(LuaInstance, -1));
        return NULL;
    }
    char *pData = (char *)lua_tolstring(LuaInstance, -1, (size_t *)size);
    char* buf = NULL;
    if (*size) {
        Log(5, "o RCO(0): Retrieved Object size=%d\n", database, key, player, arg4, *size);
        buf = new char[*size];
        memcpy(buf, pData, (size_t)*size);
    }
    lua_pop(LuaInstance, 1);
    return (unsigned char*)buf;
}

/*
unsigned long CNWNXLua::OnRequestObject (char *gameObject, char* Request)
{
	return OBJECT_INVALID;
}
*/
