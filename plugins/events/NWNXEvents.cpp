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

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNWNXEvents::CNWNXEvents()
{
	confKey = "EVENTS";
	strcpy(eventScript,"vir_events");
}

CNWNXEvents::~CNWNXEvents()
{
}

bool CNWNXEvents::OnCreate (gline *config, const char* LogDir)
{
	char log[128];
	bool validate = true, startServer = true;

	// call the base class function
	sprintf (log, "%s/nwnx_events.txt", LogDir);
	if (!CNWNXBase::OnCreate(config,log))
		return false;

	// write copy information to the log file
	Log (0, "NWNX Events version 1.3.0 for Linux.\n");
	Log (0, "(c) 2006-2008 by virusman (virusman@virusman.ru)\n");

	if(nwnxConfig->exists(confKey)) {
		strncpy(eventScript, (*nwnxConfig)[confKey]["event_script"].c_str(), 16);
		eventScript[16] = 0;
	}

	return(HookFunctions());
}

char* CNWNXEvents::OnRequest (char* gameObject, char* Request, char* Parameters)
{
	Log(2,"Request: \"%s\"\n",Request);
	Log(2,"Params:  \"%s\"\n",Parameters);
	this->pGameObject = gameObject;
	this->nGameObjectID = *(dword *)(gameObject+0x4);

	//TODO: make this accessible only from conditional scripts
	if (ConditionalScriptRunning)
	{
		if (strncmp(Request, "GET_NODE_ID", 11) == 0)
		{
			if (strlen(Parameters) > 2)
				sprintf(Parameters, "%d", nCurrentNodeID);
			return NULL;
		}
		else if (strncmp(Request, "GET_ABSOLUTE_NODE_ID", 20) == 0)
		{
			if (strlen(Parameters) > 2)
				sprintf(Parameters, "%d", nCurrentAbsoluteNodeID);
			return NULL;
		}
		else if (strncmp(Request, "GET_NODE_TYPE", 13) == 0)
		{
			if (strlen(Parameters) > 1)
				sprintf(Parameters, "%d", nNodeType);
			return NULL;
		}
		else if (strncmp(Request, "GET_NODE_TEXT", 13) == 0)
		{
			if(!pConversation) return NULL;
			int nLocaleID = atoi(Parameters);
			const char *pText = NULL;

			if(nNodeType == StartingNode || nNodeType == EntryNode)
			{
				CDialogEntry *pEntry = &pConversation->EntryList[nCurrentAbsoluteNodeID];
				CExoLocString *pNodeText = &pEntry->Text;
				pText = pNodeText->GetStringText(nLocaleID);
			}
			else if(nNodeType == ReplyNode)
			{
				CDialogReply *pReply = &pConversation->ReplyList[nCurrentAbsoluteNodeID];
				CExoLocString *pNodeText = &pReply->Text;
				pText = pNodeText->GetStringText(nLocaleID);
			} 
			else return NULL;

			if(!pText) return NULL;
			int len = strlen(pText);
			char *pNewText = (char *) malloc(len+1);
			strncpy(pNewText, pText, len);
			pNewText[len]=0;
			return pNewText;

			return NULL;
		}
		else if (strncmp(Request, "SET_NODE_TEXT", 13) == 0)
		{
			if(!pConversation) return NULL;
			int nLocaleID;
			int nParamLen = strlen(Parameters);
			//char *sNewText = (char *) malloc(nParamLen);
			char *nLastDelimiter = strrchr(Parameters, '¬');
			if (!nLastDelimiter || (nLastDelimiter-Parameters)<0)
			{
				Log(0, "o nLastDelimiter error\n");
				//free(sNewText);
				return NULL;
			}
			int nTextLen = nParamLen-(nLastDelimiter-Parameters)+1;
			char *sNewText = (char *) malloc(nTextLen);
			if(sscanf(Parameters, "%d¬", &nLocaleID)<1) 
			{
				Log(0, "o sscanf error\n");
				free(sNewText);
				return NULL;
			}
			strncpy(sNewText, nLastDelimiter+1, nTextLen-1);

			CExoLocStringElement *pLangEntry=NULL;

			if(nNodeType == StartingNode || nNodeType == EntryNode)
			{
				CDialogEntry *pEntry = &pConversation->EntryList[nCurrentAbsoluteNodeID];
				CExoLocString *pNodeText = &pEntry->Text;
				pLangEntry = pNodeText->GetLangEntry(nLocaleID);

			}
			else if(nNodeType == ReplyNode)
			{
				CDialogReply *pReply = &pConversation->ReplyList[nCurrentAbsoluteNodeID];
				CExoLocString *pNodeText = &pReply->Text;
				pLangEntry = pNodeText->GetLangEntry(nLocaleID);
			}

			if(!pLangEntry){ free(sNewText); return NULL; } //do nothing if there is no text
			if(pLangEntry->Text.Text)
			{
				free(pLangEntry->Text.Text);
				pLangEntry->Text.Text = sNewText;
				pLangEntry->Text.Length = strlen(sNewText)+1;
			}
			return NULL;
		}
	}

	if (ActionScriptRunning)
	{
		if (strncmp(Request, "GET_SELECTED_NODE_ID", 20) == 0)
		{
			if (strlen(Parameters) > 1)
				sprintf(Parameters, "%d", nSelectedNodeID);
			return NULL;
		}
		else if (strncmp(Request, "GET_SELECTED_ABSOLUTE_NODE_ID", 29) == 0)
		{
			if (strlen(Parameters) > 1)
				sprintf(Parameters, "%d", nSelectedAbsoluteNodeID);
			return NULL;
		}
		else if (strncmp(Request, "GET_SELECTED_NODE_TEXT", 22) == 0)
		{
			if(!pConversation) return NULL;
			int nLocaleID = atoi(Parameters);
			CDialogReply *pReply = &pConversation->ReplyList[nSelectedAbsoluteNodeID];
			CExoLocString *pNodeText = &pReply->Text;
			const char *pText = pNodeText->GetStringText(nLocaleID);
			if(!pText) return NULL;
			int len = strlen(pText);
			char *pNewText = (char *) malloc(len+1);
			strncpy(pNewText, pText, len);
			pNewText[len]=0;
			return pNewText;
		}
	}


	if (!scriptRun) return NULL; //The following functions are accessible only from event script
	if ((strncmp(Request, "GET_EVENT_ID", 12) && strncmp(Request, "GETEVENTID", 10)) == 0)
	{
		if (strlen(Parameters) > 1)
			sprintf(Parameters, "%d", nEventID);
		return NULL;
	}
	if (strncmp(Request, "GET_EVENT_SUBID", 15) == 0)
	{
		if (strlen(Parameters) > 1)
			sprintf(Parameters, "%d", nEventSubID);
		return NULL;
	}
	else if (strncmp(Request, "GET_EVENT_POSITION", 18) == 0)
	{
		if (strlen(Parameters) > 24)
			snprintf(Parameters, strlen(Parameters), "%f¬%f¬%f", vPosition.x, vPosition.y, vPosition.z);
	}
	else if (strncmp(Request, "BYPASS", 6) == 0)
	{
		bBypass = atoi(Parameters);
	}
	return NULL;
}

unsigned long CNWNXEvents::OnRequestObject (char *gameObject, char* Request)
{
	Log(2,"ObjRequest: \"%s\"\n",Request);
	this->pGameObject = gameObject;
	this->nGameObjectID = *(dword *)(gameObject+0x4);
	if (!scriptRun) return OBJECT_INVALID; //The following functions are accessible only from event script
	if (strncmp(Request, "TARGET", 6) == 0)
	{
		return oTarget;
	}
	else if (strncmp(Request, "ITEM", 4) == 0)
	{
		return oItem;
	}
	return OBJECT_INVALID;
}

bool CNWNXEvents::OnRelease ()
{
	Log (0, "o Shutdown.\n");
}

int CNWNXEvents::FireEvent(const int pObj, int nEvID)
{
	bBypass = 0;
	nEventID = nEvID;
	Log(3, "o EVENTS: Fired event %d (%08lX). Calling '%s'\n", nEventID, pObj, eventScript);
	RunScript(eventScript, pObj);
	//deinitialize
	oTarget = OBJECT_INVALID;
	nEventID = 0;
        nEventSubID = 0;
	return bBypass;
}
