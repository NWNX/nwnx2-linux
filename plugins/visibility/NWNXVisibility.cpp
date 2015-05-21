/***************************************************************************
    NWNX Visibility - Implementation of the CNWNXVisibility class.
    (c) 2007-2010 virusman (virusman@virusman.ru)

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

#include "NWNXVisibility.h"
#include "HookFunc.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNWNXVisibility::CNWNXVisibility()
{
    confKey = "VISIBILITY";
}

CNWNXVisibility::~CNWNXVisibility()
{
}

bool CNWNXVisibility::OnCreate(gline *config, const char* LogDir)
{
    char log[128];
    bool validate = true, startServer = true;

    // call the base class function
    sprintf(log, "%s/nwnx_visibility.txt", LogDir);
    if (!CNWNXBase::OnCreate(config, log))
        return false;

    // write copy information to the log file
    Log(0, "NWNX Visibility version 1.0 for Linux.\n");
    Log(0, "(c) 2007-2010 by virusman (virusman@virusman.ru)\n");

    return (HookFunctions());
}

//Returns 1 if override is active
//nResult contains the return value: 1 if visible, 0 if no
int CNWNXVisibility::TestVisibility(dword oObject1, dword oObject2, int &nResult)
{
    if (objects.find(oObject1) != objects.end()) {
        Log(2, "Found object entry!");
        if (objects[oObject1].vismap.find(oObject2) != objects[oObject1].vismap.end()) {
            Log(2, "Found object-object entry!");
            nResult = objects[oObject1].vismap[oObject2];
            return 1;
        } else {
            switch (objects[oObject1].eOverrideType) {
                case AlwaysVisible:
                    nResult = 1;
                    return 1;
                    break;

                case AlwaysInvisible:
                    nResult = 0;
                    return 1;
                    break;

                case Default:
                default:
                    return 0;
            }
        }
    }
    return 0;
}

void CNWNXVisibility::SetVisibilityOverride(dword oObject1, OverrideType eOverrideType)
{
    objects[oObject1];
    objects[oObject1].eOverrideType = eOverrideType;
}

void CNWNXVisibility::SetVisibility(dword oObject1, dword oObject2, unsigned int nValue)
{
    if (objects.find(oObject1) == objects.end()) {
        objects[oObject1];
        objects[oObject1].eOverrideType = Default;
    }
    objects[oObject1].vismap[oObject2] = nValue;
}

char* CNWNXVisibility::OnRequest(char* gameObject, char* Request, char* Parameters)
{
    Log(2, "Request: \"%s\"\n", Request);
    Log(2, "Params:  \"%s\"\n", Parameters);
    this->pGameObject = gameObject;
    this->nGameObjectID = *(dword *)(gameObject + 0x4);
    if (strncmp(Request, "SET_VISIBILITY_OVERRIDE", 23) == 0) {
        SetVisibilityOverride(nGameObjectID, (OverrideType) atoi(Parameters));
        return NULL;
    } else if (strncmp(Request, "SET_VISIBILITY", 14) == 0) {
        dword oObject2;
        int nValue;
        if (sscanf(Parameters, "%lx¬%d", &oObject2, &nValue) < 2) {
            Log(0, "o sscanf error\n");
            return NULL;
        }
        SetVisibility(nGameObjectID, oObject2, nValue);
        return NULL;
    }

    return NULL;
}

bool CNWNXVisibility::OnRelease()
{
    Log(0, "o Shutdown.\n");
    return true;
}
