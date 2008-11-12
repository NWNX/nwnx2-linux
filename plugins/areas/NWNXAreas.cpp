/***************************************************************************
    NWNX Areas - Implementation of the CNWNXAreas class.
    (c) 2006-2008 virusman (virusman@virusman.ru)

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
#include <unistd.h>

#include "NWNXAreas.h"
#include "HookFunc.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNWNXAreas::CNWNXAreas()
{
	confKey = "AREAS";
}

CNWNXAreas::~CNWNXAreas()
{
}

bool CNWNXAreas::OnCreate (gline *config, const char* LogDir)
{
	char log[128];
	bool validate = true, startServer = true;

	// call the base class function
	sprintf (log, "%s/nwnx_areas.txt", LogDir);
	if (!CNWNXBase::OnCreate(config,log))
		return false;

	// write copy information to the log file
	Log (0, "NWNX Areas version 0.2.1 for Linux.\n");
	Log (0, "(c) 2006-2008 by virusman (virusman@virusman.ru)\n");

	/*if(nwnxConfig->exists(confKey)) {
		strncpy(eventScript, (*nwnxConfig)[confKey]["event_script"].c_str(), 16);
		eventScript[16] = 0;

		int log_dbg = atoi((*nwnxConfig)[confKey]["log_debug"].c_str());
		if (log_dbg) logDebug = log_dbg;
	}*/
	//sleep(2);
	

	return(HookFunctions());
}

void CNWNXAreas::CreateArea(char *value)
{
	/*
	//void *pAreaList = malloc(0x10);
	void *pModule = RetObjByOID(0);
	//void *pAreaList = *((void **)pModule+6);
	void **pAreaList = (void **)pModule+6;
	CreateAreaListItem(pAreaList, value);
	void **pAreaListItem = **(void ****)pAreaList;
	*(pAreaListItem+1) = pAreaListItem;
	//int nAreaNum = CExoLinkedListInternal__GetSize(*pAreaList);
	int nAreaNum = *((int *)pAreaList+2);
	LoadAreaNum((void **)pModule-7, nAreaNum);
	*((int *)pAreaList+2) = nAreaNum+1;
	*(pAreaListItem+1) = NULL;
	CExoLinkedListInternal__RemoveHead(*pAreaList);
	*/
}

char* CNWNXAreas::OnRequest (char* gameObject, char* Request, char* Parameters)
{
	this->pGameObject = gameObject;
	this->nGameObjectID = *(dword *)(gameObject+0x4);
	if (strncmp(Request, "CREATE_AREA", 9) == 0) 	
	{
		NWNXCreateArea(gameObject, Parameters);
		return NULL;
	}
	return NULL;
}

unsigned long CNWNXAreas::OnRequestObject (char *gameObject, char* Request)
{
	if (strncmp(Request, "GET_LAST_AREA_ID", 16) == 0) 	
	{
		return nLastAreaID;
	}
}


bool CNWNXAreas::OnRelease ()
{
	Log (0, "o Shutdown.\n");
}
