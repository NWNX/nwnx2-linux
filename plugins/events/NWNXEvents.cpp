/***************************************************************************
    NWNX Events - Implementation of the CNWNXEvents class.
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

#include "NWNXEvents.h"
#include "HookFunc.h"
#include "pluginlink.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNWNXEvents::CNWNXEvents()
{
    int i;

    for (i = 0; i < NUM_EVENT_TYPES; i++)
        eventScripts[i] = strdup("vir_events");

    confKey = "EVENTS";
}

CNWNXEvents::~CNWNXEvents()
{
}

bool CNWNXEvents::OnCreate(gline *config, const char* LogDir)
{
    char log[128];
    bool enableUnsafe = false;

    // call the base class function
    sprintf(log, "%s/nwnx_events.txt", LogDir);
    if (!CNWNXBase::OnCreate(config, log))
        return false;

    // write copy information to the log file
    Log(0, "NWNX Events version 1.3.3 for Linux.\n");
    Log(0, "(c) 2006-2011 by virusman (virusman@virusman.ru)\n");

    if (nwnxConfig->exists(confKey)) {
        int i;

        for (i = 0; i < NUM_EVENT_TYPES; i++) {
            if (strlen((*nwnxConfig)[confKey]["event_script"].c_str())) {
                eventScripts[i]     = strdup((*nwnxConfig)[confKey]["event_script"].c_str());
                eventScripts[i][16] = 0;
            }
        }
        if (atoi((*nwnxConfig)[confKey]["enable_unsafe_events"].c_str()))
            enableUnsafe = true;
    }

    hEvent = CreateHookableEvent(NWNX_EVENTS_EVENT);
    return (HookFunctions(enableUnsafe));
}

char* CNWNXEvents::OnRequest(char* gameObject, char* Request, char* Parameters)
{
    Log(2, "Request: \"%s\"\n", Request);
    Log(2, "Params:  \"%s\"\n", Parameters);
    this->pGameObject = gameObject;
    this->nGameObjectID = *(dword *)(gameObject + 0x4);

    if (strncmp(Request, "GET_SCRIPT_RETURN_VALUE", 23) == 0) {
        if (strlen(Parameters) > 2)
            sprintf(Parameters, "%d", GetRunScriptReturnValue());
        return NULL;
    }
    //TODO: make this accessible only from conditional scripts
    if (ConditionalScriptRunning) {
        if (strncmp(Request, "GET_NODE_ID", 11) == 0) {
            if (strlen(Parameters) > 2)
                sprintf(Parameters, "%d", nCurrentNodeID);
            return NULL;
        } else if (strncmp(Request, "GET_ABSOLUTE_NODE_ID", 20) == 0) {
            if (strlen(Parameters) > 2)
                sprintf(Parameters, "%d", nCurrentAbsoluteNodeID);
            return NULL;
        } else if (strncmp(Request, "GET_NODE_TYPE", 13) == 0) {
            if (strlen(Parameters) > 1)
                sprintf(Parameters, "%d", nNodeType);
            return NULL;
        } else if (strncmp(Request, "GET_NODE_TEXT", 13) == 0) {
            if (!pConversation) return NULL;
            int nLocaleID = atoi(Parameters);
            CExoString str;

            if (nNodeType == StartingNode || nNodeType == EntryNode) {
                CDialogEntry *pEntry = &pConversation->EntryList[nCurrentAbsoluteNodeID];
                CExoLocString *pNodeText = &pEntry->Text;
                pNodeText->GetStringInternal(nLocaleID, &str);
            } else if (nNodeType == ReplyNode) {
                CDialogReply *pReply = &pConversation->ReplyList[nCurrentAbsoluteNodeID];
                CExoLocString *pNodeText = &pReply->Text;
                pNodeText->GetStringInternal(nLocaleID, &str);
            } else return NULL;

            if (!str.Text) return NULL;
            int len = strlen(str.Text);
            char *pNewText = (char *) malloc(len + 1);
            strncpy(pNewText, str.Text, len);
            pNewText[len] = 0;
            return pNewText;

            return NULL;
        } else if (strncmp(Request, "SET_NODE_TEXT", 13) == 0) {
            if (!pConversation) return NULL;
            int nLocaleID;
            int nParamLen = strlen(Parameters);
            //char *sNewText = (char *) malloc(nParamLen);
            char *nLastDelimiter = strrchr(Parameters, '\xAC');
            if (!nLastDelimiter || (nLastDelimiter - Parameters) < 0) {
                Log(0, "o nLastDelimiter error\n");
                //free(sNewText);
                return NULL;
            }
            int nTextLen = nParamLen - (nLastDelimiter - Parameters) + 1;
            CExoString newText;
            newText.Text = (char *) malloc(nTextLen);
            if (sscanf(Parameters, "%d\xAC", &nLocaleID) < 1) {
                Log(0, "o sscanf error\n");
                return NULL;
            }
            strncpy(newText.Text, nLastDelimiter + 1, nTextLen - 1);

            if (nNodeType == StartingNode || nNodeType == EntryNode) {
                CDialogEntry *pEntry = &pConversation->EntryList[nCurrentAbsoluteNodeID];
                pEntry->Text.AddString(nLocaleID, newText, 0);

            } else if (nNodeType == ReplyNode) {
                CDialogReply *pReply = &pConversation->ReplyList[nCurrentAbsoluteNodeID];
                pReply->Text.AddString(nLocaleID, newText, 0);
            }
        }
    }

    if (ActionScriptRunning) {
        if (strncmp(Request, "GET_SELECTED_NODE_ID", 20) == 0) {
            if (strlen(Parameters) > 1)
                sprintf(Parameters, "%d", nSelectedNodeID);
            return NULL;
        } else if (strncmp(Request, "GET_SELECTED_ABSOLUTE_NODE_ID", 29) == 0) {
            if (strlen(Parameters) > 1)
                sprintf(Parameters, "%d", nSelectedAbsoluteNodeID);
            return NULL;
        } else if (strncmp(Request, "GET_SELECTED_NODE_TEXT", 22) == 0) {
            if (!pConversation) return NULL;
            int nLocaleID = atoi(Parameters);
            CDialogReply *pReply = &pConversation->ReplyList[nSelectedAbsoluteNodeID];
            CExoString str;
            pReply->Text.GetStringInternal(nLocaleID, &str);
            if (!str.Text) return NULL;
            int len = strlen(str.Text);
            char *pNewText = (char *) malloc(len + 1);
            strncpy(pNewText, str.Text, len);
            pNewText[len] = 0;
            return pNewText;
        }
    }


    if (!scriptRun) {
        if (strncmp(Request, "SET_EVENT_HANDLER_", 18) == 0) {
            int nHandler = atoi(Request + 18);

            if (nHandler < 0 || nHandler >= NUM_EVENT_TYPES) {
                *Parameters = 0;
            } else if (nHandler == EVENT_TYPE_ALL) {
                int i;

                for (i = 0; i < NUM_EVENT_TYPES; i++) {
                    if (eventScripts[i] != NULL)
                        free(eventScripts[i]);

                    if (strlen(Parameters) > 1 && strlen(Parameters) <= 16)
                        eventScripts[i] = strdup(Parameters);
                    else
                        eventScripts[i] = NULL;
                }
            } else {
                if (eventScripts[nHandler] != NULL) {
                    free(eventScripts[nHandler]);
                    eventScripts[nHandler] = NULL;
                }

                if (strlen(Parameters) > 1 && strlen(Parameters) <= 16)
                    eventScripts[nHandler] = strdup(Parameters);
                else
                    *Parameters = 0;
            }
        }

        return NULL;
    }

    //The following functions are accessible only from event script
    if ((strncmp(Request, "GET_EVENT_ID", 12) && strncmp(Request, "GETEVENTID", 10)) == 0) {
        if (strlen(Parameters) > 1)
            sprintf(Parameters, "%d", nEventID);
        return NULL;
    }
    if (strncmp(Request, "GET_EVENT_SUBID", 15) == 0) {
        if (strlen(Parameters) > 1)
            sprintf(Parameters, "%d", nEventSubID);
        return NULL;
    } else if (strncmp(Request, "GET_EVENT_POSITION", 18) == 0) {
        if (strlen(Parameters) > 24)
            snprintf(Parameters, strlen(Parameters), "%f\xAC%f\xAC%f", vPosition.X, vPosition.Y, vPosition.Z);
    } else if (strncmp(Request, "BYPASS", 6) == 0) {
        bBypass = atoi(Parameters);
    } else if (strncmp(Request, "RETURN", 6) == 0) {
        nReturnValue = atoi(Parameters);
    }
    return NULL;
}

unsigned long CNWNXEvents::OnRequestObject(char *gameObject, char* Request)
{
    Log(2, "ObjRequest: \"%s\"\n", Request);
    this->pGameObject = gameObject;
    this->nGameObjectID = *(dword *)(gameObject + 0x4);
    if (!scriptRun) return OBJECT_INVALID; //The following functions are accessible only from event script
    if (strncmp(Request, "TARGET", 6) == 0) {
        return oTarget;
    } else if (strncmp(Request, "ITEM", 4) == 0) {
        return oItem;
    }
    return OBJECT_INVALID;
}

bool CNWNXEvents::OnRelease()
{
    Log(0, "o Shutdown.\n");
    return true;
}

int CNWNXEvents::FireEvent(const int pObj, int nEvID)
{
    bBypass = 0;
    nEventID = nEvID;

    if (nEventID < 0 || nEventID >= NUM_EVENT_TYPES || eventScripts[nEventID] == NULL)
        return 0;

    EventsEvent event;
    event.object = pObj;
    event.type = nEventID;
    event.subtype = nEventSubID;
    event.target = oTarget;
    event.bypass = false;
    event.item = oItem;
    event.result = 0;
    event.position.x = vPosition.X;
    event.position.y = vPosition.Y;
    event.position.z = vPosition.Z;

    scriptRun = 1;
    if (!NotifyEventHooks(hEvent, (uintptr_t)&event)) {
        Log(3, "o EVENTS: Fired event %d (%08lX). Calling '%s'\n", nEventID, pObj, eventScripts[nEventID]);
        CExoString script_name(eventScripts[nEventID]);
        g_pVirtualMachine->RunScript(&script_name, pObj, 1);
    } else {
        Log(3, "o EVENTS: Fired event %d (%08lX). Event hook took over.\n", nEventID, pObj);
        nReturnValue = event.result;
        bBypass = event.bypass;
    }
    scriptRun = 0;
    //deinitialize
    oTarget = OBJECT_INVALID;
    nEventID = 0;
    nEventSubID = 0;
    return bBypass;
}
