
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
CNWNXResMan::CNWNXResMan() {
    confKey = "RESOURCEMANAGER";
    bufferSize = 0;
}

CNWNXResMan::~CNWNXResMan() {
}

bool CNWNXResMan::OnCreate(gline * config, const char *LogDir) {

    // call the base class function
    char log[MAXPATH];

    sprintf(log, "%s/nwnx_resman.txt", LogDir);
    if (!CNWNXBase::OnCreate(config, log))
        return false;
    LoadConfiguration();
    WriteLogHeader();
    HookFunctions();
    return true;
}

char *CNWNXResMan::OnRequest(char *gameObject, char *Request, char *Parameters) {
    return NULL;
}

bool CNWNXResMan::OnRelease() {
    Log(0, "o Shutdown.\n");
}

char *CNWNXResMan::DemandRes(CResStruct * cRes, char *resRef, NwnResType resType) {
    unsigned long size;

    if (!resRef || *resRef == '*' || strcmp(resRef, "default") == 0)
        return NULL;
    if (cRes == NULL || cRes->pResName != NULL) {
        Log(5, "o Request for internal resource = %s (type %X)\n", resRef, resType);

        // nothing for us to do
        return NULL;
    }

    // try to load external resource
    char resPath[MAXPATH + 16];

    snprintf(resPath, sizeof(resPath), "%s/%s/%s.%s",
        m_sourcePath, NwnGetResTypeExtension(resType), resRef, NwnGetResTypeExtension(resType));

    size = LoadResource(resPath);
    if (size == 0)
        return NULL;
    int namelen = strlen(resRef) + 1;
    saveName = new char[namelen];

    strcpy(saveName, resRef);

    // resource loaded      
    // set resStruct
    cRes->pResData = pScriptBuffer;
    cRes->pResName = saveName;
    cRes->resSize = size;
    cRes->unk2 = 1;
    cRes->unk4 = 4;
    cRes->loaded = 1;
    cRes->loaded2 = 1;
    cRes->resSize2 = size;
    cRes->pResData2 = pScriptBuffer;
    cRes->id1 = 0;
    cRes->id2 = 0;
    cRes->id3 = 0;
    cRes->id4 = 0;

    // Call server function which sets various data pointers
    if (cRes->pClass) {
        char *pFunc = cRes->pClass;

        pFunc = (char *)(*(int *)(pFunc + 0x18));
        void (*pServFunc) (CResStruct * cRes) =
            (void (*)(CResStruct * cRes))pFunc;
        pServFunc(cRes);
    }
    return cRes->pResData;
}

unsigned long CNWNXResMan::LoadResource(char *resPath) {
    FILE *pTemp = fopen(resPath, "rb");

    if (pTemp == NULL) {
        Log(1, "o Skip - File not found: %s\n", resPath);
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

void CNWNXResMan::LoadConfiguration() {
    if (nwnxConfig->exists(confKey)) {
        strncpy(m_sourcePath, (*nwnxConfig)[confKey]["SourcePath"].c_str(), MAXPATH);
    }
}

void CNWNXResMan::WriteLogHeader() {
    // write copy information to the log file
    Log(0, "NWNX Resource Manager V.0.0.2.1 for Linux.\n");
    Log(0, "(c) 2005 by Ingmar Stieger (papillon@nwnx.org)\n");
    Log(0, "(c) 2006 by dumbo (dumbo@nm.ru) & virusman (virusman@virusman.ru)\n");
    Log(0, "* Resource source path is: %s\n", m_sourcePath);
}
