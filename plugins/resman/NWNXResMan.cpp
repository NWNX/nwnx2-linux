/***************************************************************************
    NWNXResMan.cpp - Implementation of the CNWNXResMan class.
    Copyright (C) 2005 Ingmar Stieger (papillon@nwnx.org)
    copyright (c) 2006 dumbo (dumbo@nm.ru) & virusman (virusman@virusman.ru)
    
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

#include "NWNXResMan.h"
#include "NwnDefines.h"
#include "HookDemandRes.h"
#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNWNXResMan::CNWNXResMan()
{
    confKey = "RESOURCEMANAGER";
    bufferSize = 0;
	disableHook= 0;
}

CNWNXResMan::~CNWNXResMan()
{
}

bool CNWNXResMan::OnCreate (gline *config, const char *LogDir) 
{
    // call the base class function
    char log[MAXPATH];

    sprintf(log, "%s/nwnx_resman.txt", LogDir);
    if (!CNWNXBase::OnCreate(config, log))
        return false;

    LoadConfiguration();
    WriteLogHeader();
    HookFunctions();

    hDemandRes = CreateHookableEvent("NWNX/ResMan/DemandResource");

    return true;
}

char* CNWNXResMan::OnRequest (char* gameObject, char* Request, char* Parameters)
{
    return NULL;
}

bool CNWNXResMan::OnRelease ()
{
    Log(0, "o Shutdown.\n");
}

char* CNWNXResMan::DemandRes(CExoResMan *pResMan, CResStruct *cRes, char *resRef, NwnResType resType)
{
    unsigned long size;
	bool overwriteRes = 0;

    if (!resRef || *resRef == '*' || strcmp(resRef, "default") == 0)
        return NULL;
    if (cRes == NULL) {
        Log(5, "o Request for internal resource = %s (type %X)\n", resRef, resType);

        // nothing for us to do
        return NULL;
    }

    char resrefWithExt[20];
    snprintf(resrefWithExt, 20, "%s.%s", resRef, NwnGetResTypeExtension(resType));

    ResManDemandResStruct demandResInfo = {
        resrefWithExt, NULL, NULL
    };
    int notifyRet = NotifyEventHooks(hDemandRes, (WPARAM)&demandResInfo, 0);
    if (notifyRet && demandResInfo.pData == NULL)
        return NULL;

	if(!cRes->pResName) {
		Log(1, "o ResID = %x\n", cRes->ID);
	}

	if (demandResInfo.pData && demandResInfo.size) {
		printf("Got data from Hook, returning (size = %d): %s\n", demandResInfo.size, demandResInfo.pData);
		pScriptBuffer = (char*) demandResInfo.pData;
		size = demandResInfo.size;

	} else {
		// try to load external resource
		char resPath[MAXPATH + 16];

		snprintf(resPath, sizeof(resPath), "%s/%s/%s.%s",
		m_sourcePath, NwnGetResTypeExtension(resType), resRef, NwnGetResTypeExtension(resType));

		struct stat stFileInfo;
		CResFileInfo pFileInfo;
		if(stat(resPath, &stFileInfo) == 0){  //exists
			//Log(4, "Searching for changes in resource\n");
			if(resFiles.count(resPath)){
				//Log(4, "Found entry\n");
				pFileInfo = resFiles[resPath];
				if(pFileInfo.size == stFileInfo.st_size && pFileInfo.mtime == stFileInfo.st_mtime){
					//Log(4, "The file has not been changed\n");
				}
				else {
					Log(4, "The file has been changed\n");
					pFileInfo.size = stFileInfo.st_size;
					pFileInfo.mtime = stFileInfo.st_mtime;
					resFiles[resPath] = pFileInfo;
					overwriteRes = 1;
				}
			}
			else {
				strncpy(pFileInfo.ResName, resRef, 16);
				pFileInfo.resType = resType;
				pFileInfo.size = stFileInfo.st_size;
				pFileInfo.mtime = stFileInfo.st_mtime;
				resFiles[resPath] = pFileInfo;
				overwriteRes = 1;
			}
		}
		else{
			Log(3, "o Skip - File not found: %s\n", resPath);
			return NULL;
		}

		if(!cRes->pResData)
			overwriteRes = 1;
		
		if(!overwriteRes){
			Log(4, "Skipping...\n");
			return NULL;
		}

		size = LoadResource(resPath);
		if (size == 0)
			return NULL;
	}

    int namelen = strlen(resRef) + 1;
    saveName = new char[namelen];

	Log(4, "Original Structure:\n");
	DumpResStruct(cRes);
	Log(4, "Free memory: %d\n", pResMan->FreeMemory);
	if(pResMan->FreeMemory < size){ //not enough memory
		Log(4, "Freeing some memory\n");
		while ( 1 )
		{
		  if (size <= pResMan->FreeMemory)
			break;
		  if (!CExoResMan__FreeChunk(pResMan))
			break;
		}
	}
	if(pResMan->FreeMemory < 0)
		pResMan->FreeMemory = 0;

    strcpy(saveName, resRef);

	if(cRes->pResData)
	{
		free(cRes->pResData);
		pResMan->FreeMemory += cRes->resSize;
		cRes->pResData = pScriptBuffer;
		cRes->resSize = size;
	}
	else
	{
		// resource loaded		
		// set resStruct

	    cRes->pResData = pScriptBuffer;
	    cRes->pResName = saveName;
	    cRes->resSize = size;
	    cRes->Demands = 1;
	    //cRes->unk4 = 4;
	    cRes->unk4 = 0x4;
	    cRes->loaded = 2;
		if(!cRes->ID || cRes->ID == 0xFFFFFFFF)  //resource is not indexed
		{
	    	cRes->ID = 0;
		}
	}
	pResMan->FreeMemory -= size;

    // Call server function which sets various data pointers
    if (cRes->pClass)
    {
        char *pFunc = cRes->pClass;

		if(resType == NwnResType_NCS){
			CResNCS *pNCS = (CResNCS*) cRes;
			pNCS->m_bLoaded = 0;
		}

        pFunc = (char *)(*(int *)(pFunc + 0x18));  // CRes* :: OnResourceServiced
        int (*pServFunc) (CResStruct * cRes) =
            (int (*)(CResStruct * cRes))pFunc;
		Log(4, "Calling CRes*::OnResourceServiced: %08lx\n", pServFunc);
        int nRet = pServFunc(cRes);
		Log(4, "Return value: %d\n", nRet);
    }
	Log(4, "Resulting Structure:\n");
	DumpResStruct(cRes);

    return cRes->pResData;
}

void CNWNXResMan::DumpResStruct(CResStruct *cRes)
{
	Log(4, "- m_nDemands = %d\n", cRes->Demands);
	Log(4, "- m_nRequests = %d\n", cRes->Requests);
	Log(4, "- m_nID = %08lX\n", cRes->ID);
	Log(4, "- m_pResource = %08lx\n", cRes->pResData);
	Log(4, "- m_nSize = %d\n", cRes->resSize);
	Log(4, "- m_sName = %s\n", cRes->pResName);
	Log(4, "- flags = %x\n", cRes->unk4);
	Log(4, "- m_status = %d\n", cRes->loaded);
	Log(4, "- m_pKeyEntry = %08lx\n", cRes->pListElement);
}

unsigned long CNWNXResMan::LoadResource(char *resPath)
{
    FILE *pTemp = fopen(resPath, "rb");

    if (pTemp == NULL)
    {
        Log(3, "o Skip - File not found: %s\n", resPath);
        return 0;
    }
    fseek(pTemp, 0, SEEK_END);
    unsigned long size = ftell(pTemp);

    Log(1, "o Loading external resource %s (%ld bytes)\n", resPath, size);

    pScriptBuffer = new char[size];

    fseek(pTemp, 0, SEEK_SET);
    fread(pScriptBuffer, 1, size, pTemp);
    fclose(pTemp);
    return size;
}

int CNWNXResMan::ResourceExists(char *resRef, NwnResType resType)
{
    // try to load external resource
    char resPath[MAXPATH + 16];

    snprintf(resPath, sizeof(resPath), "%s/%s/%s.%s",
        m_sourcePath, NwnGetResTypeExtension(resType), resRef, NwnGetResTypeExtension(resType));

	struct stat stFileInfo;
	CResFileInfo pFileInfo;
	if(stat(resPath, &stFileInfo) == 0){  //exists
		return 1;
	}
	else{
		return 0;
	}
}

void CNWNXResMan::LoadConfiguration ()
{
    if (nwnxConfig->exists(confKey)) {
        strncpy(m_sourcePath, (*nwnxConfig)[confKey]["SourcePath"].c_str(), MAXPATH);
    }
/*    if (nwnxConfig->exists(confKey, "disablehook") && 
		toupper((*nwnxConfig)[confKey]["disablehook"].c_str()[0])=='Y') {
		    disableHook = 1;
        )
    }*/

}

void CNWNXResMan::WriteLogHeader()
{
    // write copy information to the log file
    Log(0, "NWNX Resource Manager 1.0.1 for Linux.\n");
    Log(0, "(c) 2005 by Ingmar Stieger (papillon@nwnx.org)\n");
    Log(0, "(c) 2006 by dumbo (dumbo@nm.ru)\n");
    Log(0, "(c) 2006-2010 by virusman (virusman@virusman.ru)\n");
    Log(0, "* Resource source path is: %s\n", m_sourcePath);
}
