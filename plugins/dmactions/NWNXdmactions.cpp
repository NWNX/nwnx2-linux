/***************************************************************************
    NWNXdmactions.cpp - Implementation of the CNWNXdmactions class.

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

#include "NWNXdmactions.h"
#include "FunctionHooks.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNWNXdmactions::CNWNXdmactions()
{
    for (int i = 0; i < NUM_ACTIONS; i++)
        ActionsScripts[i] = strdup("dmaction");

    confKey = strdup("DMACTIONS");
}

CNWNXdmactions::~CNWNXdmactions()
{
}

bool CNWNXdmactions::OnCreate(gline *config, const char *LogDir)
{
    char log[128];
    sprintf(log, "%s/nwnx_dmactions.txt", LogDir);

    // call the base class function
    if (!CNWNXBase::OnCreate(config, log))
        return false;
    Log(0, "NWNX DM Actions v0.2.6, 2010\n");

    if (!FindFunctions()) {
        Log(0, "* Failed to hook functions.\n");
        return false;
    }

    return true;
}

char* CNWNXdmactions::OnRequest(char *gameObject, char* Request, char* Parameters)
{
    this->pGameObject = gameObject + 4;

    Log(2, "(S) Request: \"%s\"\n", Request);
    Log(3, "(S) Params:  \"%s\"\n", Parameters);

    bool bMatch = 0;

    if (this->InScript) {
        if (strncmp(Request, "GETACTIONID", 11) == 0) {
            snprintf(Parameters, strlen(Parameters), "%d", this->nActionID);
        } else if (strncmp(Request, "GETPARAM_1", 10) == 0) {
            snprintf(Parameters, strlen(Parameters), "%d", this->nParam1);
        } else if (strncmp(Request, "GETPARAM_2", 10) == 0) {
            snprintf(Parameters, strlen(Parameters), "%d", this->nParam2);
        } else if (strncmp(Request, "GETSTRPARAM1", 12) == 0) {
            snprintf(Parameters, strlen(Parameters), "%s", this->sParam1);
        } else if (strncmp(Request, "GETPOS", 6) == 0) {
            snprintf(Parameters, strlen(Parameters), "%f¬%f¬%f", this->vPos.x, this->vPos.y, this->vPos.z);
        } else if (strncmp(Request, "GETTARGETSCOUNT", 15) == 0) {
            snprintf(Parameters, strlen(Parameters), "%d", this->nCount);
        } else if (strncmp(Request, "GETTARGETSCURRENT", 17) == 0) {
            snprintf(Parameters, strlen(Parameters), "%d", this->nCurrent);
        } else if (strncmp(Request, "PREVENT", 6) == 0) {
            this->bPrevent = 1;
        }
        bMatch = 1;
    }
    if (!bMatch) {
        if (strncmp(Request, "SET_ACTION_SCRIPT", 17) == 0) {
            char *scriptname = (char *)malloc(strlen(Parameters));
            int action_id;
            if (sscanf(Parameters, "%i:%s", &action_id, scriptname) == 2 && strspn(scriptname, "abcdefghijklmnopqrstuvwxyz0123456789_") == strlen(scriptname)) {
                if (action_id >= 0 && action_id < NUM_ACTIONS) {
                    if (action_id == DM_ACTION_ALL) {
                        for (int i = 0; i < NUM_ACTIONS; i++) {
                            if (ActionsScripts[i] != NULL) {
                                free(ActionsScripts[i]);
                            }
                            if (strlen(scriptname) >= 1 && strlen(scriptname) <= 16) {
                                ActionsScripts[i] = strdup(scriptname);
                            } else {
                                ActionsScripts[i] = NULL;
                            }
                        }
                    } else {
                        if (ActionsScripts[action_id] != NULL) {
                            free(ActionsScripts[action_id]);
                            ActionsScripts[action_id] = NULL;
                        }
                        if (strlen(scriptname) >= 1 && strlen(scriptname) <= 16) {
                            ActionsScripts[action_id] = strdup(scriptname);
                        }
                    }
                }
            }
        }
    }

    return NULL;
}

unsigned long CNWNXdmactions::OnRequestObject(char *gameObject, char* Request)
{
    this->pGameObject = gameObject + 4;
    Log(2, "(O) Request: \"%s\"\n", Request);

    if (InScript) {
        if (strncmp(Request, "TARGET_1", 8) == 0) {
            return this->oTarget1;
        } else if (strncmp(Request, "TARGET_2", 8) == 0) {
            return this->oTarget2;
        }
    }
    return OBJECT_INVALID;
}

int CNWNXdmactions::FireAction(nwn_objid_t pDM, int nAction)
{
    this->bPrevent = 0;
    this->nActionID = nAction;

    if (nAction < 0 || nAction >= NUM_ACTIONS || ActionsScripts[nAction] == NULL) {
        return 0;
    }
    Log(3, "o Fired action %d (%08lX). Calling '%s'\n", nAction, pDM, ActionsScripts[nAction]);
    this->InScript = 1;
    nwn_ExecuteScript(ActionsScripts[nAction], pDM);
    this->InScript = 0;


    this->nActionID = 0;
    this->oTarget1 = OBJECT_INVALID;
    this->oTarget2 = OBJECT_INVALID;
    this->nParam1 = 0;
    this->nParam2 = 0;
    this->sParam1[0] = 0;
    this->nCount = 0;
    this->nCurrent = 0;

    return this->bPrevent;
}
