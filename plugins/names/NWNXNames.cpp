/***************************************************************************
    NWNX Names - Implementation of the CNWNXNames class.
    (c) 2006 virusman (virusman@virusman.ru)

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

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <pthread.h>
#include <stddef.h>

#include "NWNXNames.h"
#include "CCustomNames.h"
#include "HookFunc.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNWNXNames::CNWNXNames()
{
    confKey = "NAMES";
    strcpy(eventScript, "vir_names");
    logDebug = 0;
}

CNWNXNames::~CNWNXNames()
{
}

bool CNWNXNames::OnCreate(gline *config, const char* LogDir)
{
    char log[128];
    bool validate = true, startServer = true;

    // call the base class function
    sprintf(log, "%s/nwnx_names.txt", LogDir);
    if (!CNWNXBase::OnCreate(config, log))
        return false;

    // write copy information to the log file
    Log(0, "NWNX Names version 1.0.3 for Linux.\n");
    Log(0, "(c) 2006-2010 by virusman (virusman@virusman.ru)\n");

    if (nwnxConfig->exists(confKey)) {
        strncpy(eventScript, (*nwnxConfig)[confKey]["event_script"].c_str(), 16);
        eventScript[16] = 0;

        int log_dbg = atoi((*nwnxConfig)[confKey]["log_debug"].c_str());
        if (log_dbg) logDebug = log_dbg;
    }
    if (!this->Names.data) {
        Log(0, "Unable to construct names array\n");
        return 0;
    }
    //Names.InsertPlayer(0x7FFFFFFF, 0);
    //int nPlyID = Names.FindPlayerID(0x7FFFFFFF);
    //Log(0, "PlyID=%n", nPlyID);
    //char plog[128];
    //sprintf (plog, "%s/nwnx_names_plog.txt", LogDir);
    //PacketData = fopen(plog, "w");

    return (HookFunctions());
}

void CNWNXNames::InitPlayerList(char *value)
{
    Log(2, "Player %08lX entered the game.\n", this->nGameObjectID);
    dword oPlayer = nGameObjectID;
    int nUnkStyle = atoi(value);
    if (nUnkStyle < 0 || nUnkStyle > 2) nUnkStyle = 1;
    if (Names.FindPlayerID(oPlayer) == -1) {
        Names.InsertPlayer(oPlayer, nUnkStyle, 1);
    }
}

void CNWNXNames::EnableDisableNames(char *value)
{
    CPlayerNames *pPlayerEntry = Names.FindPlayerEntry(nGameObjectID);
    if (!pPlayerEntry) return;
    pPlayerEntry->bEnabled = (bool) atoi(value);
}

char *CNWNXNames::GetDynamicName(char *value)
{
    dword oPlayer = nGameObjectID;
    dword oObject = strtol(value, NULL, 16);
    char *sName;
    CPlayerNames *pPlayerEntry = Names.FindPlayerEntry(oPlayer);
    if (pPlayerEntry) {
        sName = Names.FindCustomName(oPlayer, oObject);
        if (sName) {
            char *sNameRet = new char[strlen(sName) + 1];
            strncpy(sNameRet, sName, strlen(sName));
            sNameRet[strlen(sName)] = 0;
            return sNameRet;
        }
    }
    value[0] = 0;
    return NULL;
}

void CNWNXNames::SetDynamicName(char *value)
{
    dword oPlayer, oObject;
    oPlayer = nGameObjectID;
    int nParamLen = strlen(value);
    char *nLastDelimiter = strrchr(value, '¬');
    if (!nLastDelimiter || (nLastDelimiter - value) < 0) {
        Log(3, "o nLastDelimiter error\n");
        return;
    }
    char *sName = new char[nParamLen - (nLastDelimiter - value) + 1];
    if (sscanf(value, "%lx¬%s", &oObject, sName) < 2) {
        Log(3, "o sscanf error\n");
        return;
    }
    strcpy(sName, nLastDelimiter + 1);
    if (!oPlayer || !oObject) {
        Log(3, "o invalid object\n");
        return;
    }
    Names.InsertCustomName(oPlayer, oObject, sName);
    SendNewName(oPlayer, oObject);
}

void CNWNXNames::UpdateDynamicName(char *value)
{
    dword oPlayer = nGameObjectID;
    dword oObject = strtol(value, NULL, 16);
    SendNewName(oPlayer, oObject);
}

void CNWNXNames::UpdatePlayerList(char *value)
{
    dword oPlayer = nGameObjectID;
    SendPlayerList(oPlayer);
}

void CNWNXNames::DeleteDynamicName(char *value)
{
    dword oPlayer = nGameObjectID;
    dword oObject = strtol(value, NULL, 16);
    CPlayerNames *pPlayerEntry = Names.FindPlayerEntry(oPlayer);
    if (pPlayerEntry) {
        pPlayerEntry->DeleteByObjectID(oObject);
    }
}

void CNWNXNames::ClearPlayerList(char *value)
{
    Log(2, "Player %08lX is exiting.\n", this->nGameObjectID);
    dword oPlayer = nGameObjectID;
    Names.DeletePlayer(oPlayer);
}

char* CNWNXNames::OnRequest(char* gameObject, char* Request, char* Parameters)
{
    Log(2, "Request: \"%s\"\n", Request);
    Log(2, "Params:  \"%s\"\n", Parameters);
    this->pGameObject = gameObject;
    this->nGameObjectID = *(dword *)(gameObject + 0x4);
    if (strncmp(Request, "INITPLAYERNAMELIST", 18) == 0) {
        InitPlayerList(Parameters);
        return NULL;
    } else if (strncmp(Request, "GETDYNAMICNAME", 14) == 0) {
        return GetDynamicName(Parameters);
    } else if (strncmp(Request, "SETDYNAMICNAME", 14) == 0) {
        SetDynamicName(Parameters);
        return NULL;
    } else if (strncmp(Request, "UPDATEDYNAMICNAME", 17) == 0) {
        UpdateDynamicName(Parameters);
        return NULL;
    } else if (strncmp(Request, "UPDATEPLAYERLIST", 16) == 0) {
        UpdatePlayerList(Parameters);
        return NULL;
    } else if (strncmp(Request, "DELETEDYNAMICNAME", 17) == 0) {
        DeleteDynamicName(Parameters);
        return NULL;
    } else if (strncmp(Request, "CLEARPLAYERNAMELIST", 19) == 0) {
        ClearPlayerList(Parameters);
        return NULL;
    } else if (strncmp(Request, "SETNAMESENABLED", 15) == 0) {
        EnableDisableNames(Parameters);
        return NULL;
    }
    return NULL;
}

bool CNWNXNames::OnRelease()
{
    Log(0, "o Shutdown.\n");
    fclose(PacketData);
    return true;
}
