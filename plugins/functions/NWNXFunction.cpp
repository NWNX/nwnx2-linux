/***************************************************************************
    NWNXFunction.cpp - Implementation of the CNWNXFunction class.
    Copyright (C) 2003 Ingmar Stieger (Papillon)
    email: papillon@blackdagger.com

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

#include "NWNXFunction.h"
#include "FunctionHooks.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNWNXFunction::CNWNXFunction()
{
    confKey = "FUNCTIONS";
    bHooked = 1;
}

CNWNXFunction::~CNWNXFunction()
{
}

void CNWNXFunction::SetGoldPieceValue(char* value)
{
    if (*(pGameObject + 0x4) == 0x6) { // object type item
        int iGoldValue = atoi(value);
        *(int*)(pGameObject + 0x1F4) = iGoldValue;
    }
}

void CNWNXFunction::SetTag(char* value)
{
    /*
    #ifdef NWNX_FUNCTIONS_SETTAG_REWRITE
        // warning: leaks memory, but allows setting a longer tag than the original, plus
        // there appear to be some cases where rewriting the tag causes corruption
        *(char **)(pGameObject + 0x18) = strdup(value);
    #else
    	// default behavior
        char* tag = (char*)(*(int*)(pGameObject+0x18));

    	int iLength;
    	int iOrgLength = strlen(tag);
    	int iNewLength = strlen(value);

    	if (iOrgLength > iNewLength)
    		iLength = iNewLength;
    	else
    		iLength = iOrgLength;

    	strncpy(tag, value, iLength);

    	*(tag+iLength) = 0x0;
    #endif
    */
    CExoString *sNewTag = NewCExoString(value);
    CNWSObject_SetTag((CNWSObject *)(pGameObject - 4), sNewTag);
}

void CNWNXFunction::SetArmorAC(char* value)
{
    if (*(pGameObject + 0x4) == 0x6) { // object type item
        int iAC = atoi(value);
        *(int*)(pGameObject + 0x1CC) = iAC;
    }
    // 0x1d4: auch armor class ??
}

void CNWNXFunction::GetArmorAC(char* value)
{
    if (*(pGameObject + 0x4) == 0x6) { // object type item
        int iAC = *(int*)(pGameObject + 0x1CC);
        if (strlen(value) > 1)
            sprintf(value, "%d", iAC);
    }
}

void CNWNXFunction::SetRacialType(char* value)
{
    if (*(pGameObject + 0x4) == 0x5) { // object type creature
        int iRace = atoi(value);
        char *nCreatureStruct = *(char **)((char *)pGameObject + 0xC64);
        char *nCreatureRace = nCreatureStruct + 0x3E4;
        *(int*)nCreatureRace = iRace;
    }
}

void CNWNXFunction::GetDescriptionLength(char* value)
{
    int length = strlen(value);
    char* desc;

    //if (*(pGameObject+0x4) != 0x6 && *(pGameObject+0x4) != 0x9) // object type item	or placeable
    //	return;

    if (*(pGameObject + 0x4) == 0x6) desc = (char*)(*(int*)(pGameObject - 0x1C + 0x258)); //object type item
    else if (*(pGameObject + 0x4) == 0x9) desc = (char*)(*(int*)(pGameObject + 0x1D8)); //object type placeable
    else if (*(pGameObject + 0x4) == 0x5) desc = (char*)(*(*(int**)(pGameObject + 0xC64) + 0x16)); //object type creature
    else if (*(pGameObject + 0x4) == 0xA) desc = (char*)(*(int*)(pGameObject + 0x314)); //object type door
    else return;

    if (*(desc + 4) == 0)
        return;
    desc = (char*)(*(int*)(desc));
    desc = (char*)(*(int*)(desc));
    desc = (char*)(*(int*)(desc + 0x8));
    desc = (char*)(*(int*)(desc + 0x4));

    int iDescLength = strlen(desc);
    try {
        if (length >= 6) sprintf(value, "%d", iDescLength);
    } catch (...) {
        Log(0, "Not enough memory in buffer to copy description length.\n");
        return;
    }
}


char *CNWNXFunction::GetDescription(char* value)
{
    int length = strlen(value);
    char* desc;

    //if (*(pGameObject+0x4) != 0x6 && *(pGameObject+0x4) != 0x9) // object type item	or placeable
    //	return;

    if (*(pGameObject + 0x4) == 0x6) desc = (char*)(*(int*)(pGameObject - 0x1C + 0x258)); //object type item
    else if (*(pGameObject + 0x4) == 0x9) desc = (char*)(*(int*)(pGameObject + 0x1D8)); //object type placeable
    else if (*(pGameObject + 0x4) == 0x5) desc = (char*)(*(*(int**)(pGameObject + 0xC64) + 0x16)); //object type creature
    else if (*(pGameObject + 0x4) == 0xA) desc = (char*)(*(int*)(pGameObject + 0x314)); //object type door
    else return NULL;

    if (*(desc + 4) == 0)
        return NULL;
    desc = (char*)(*(int*)(desc));
    desc = (char*)(*(int*)(desc));
    desc = (char*)(*(int*)(desc + 0x8));
    desc = (char*)(*(int*)(desc + 0x4));

    /*int iDescLength = strlen(desc);
    if (iDescLength < length)
    {
    	strncpy(value, desc, iDescLength);
    	*(value+iDescLength) = 0x0;
    }
    else
    {
    	strncpy(value, desc, length);
    	*(value+length) = 0x0;
    }*/

    //Dynamic allocation
    //This requires NWNX Core >=2.7
    char *newDesc = (char *) malloc(strlen(desc) + 1);
    strcpy(newDesc, desc);
    return newDesc;
}

void CNWNXFunction::SetDescription(char* value)
{
    int length = strlen(value);
    CExoLocString* pDesc;

    if (*(pGameObject + 0x4) == 0x6) pDesc = (CExoLocString *)(pGameObject - 0x1C + 0x258); //object type item
    else if (*(pGameObject + 0x4) == 0x9) pDesc = (CExoLocString *)(pGameObject + 0x1D8); //object type placeable
    else if (*(pGameObject + 0x4) == 0x5) pDesc = (CExoLocString *)(*(int*)(pGameObject + 0xC64) + 0x16); //object type creature
    else if (*(pGameObject + 0x4) == 0xA) pDesc = (CExoLocString *)(pGameObject + 0x314); //object type door
    else return;

    char *newstr = new char[length + 1];
    strncpy(newstr, value, length);
    pDesc->AddString(0, newstr);


    /*if (*(desc+4) == 0)
    	return;
    desc = (char*)(*(int*)(desc));
    desc = (char*)(*(int*)(desc));
    desc = (char*)(*(int*)(desc+0x8));
    descp = desc;
    desc = (char*)(*(int*)(desc+0x4));

    int iDescLength = strlen(desc);
    //if (iDescLength < length)
    //{
    	char *newstr = new char[length+1];
    	strncpy(newstr, value, length);
    	*(newstr+length) = 0x0;
    	asm("mov %0, %%eax" : : "b"(descp));
    	asm("mov %0, 0x4(%%eax)" : : "b"(newstr));
    	free(desc);
    //}
    //else
    //{
    	//strncpy(value, desc, length);
    	//*(value+length) = 0x0;
    //}*/
}

void CNWNXFunction::GetConversation(char *value)
{
    if (*(pGameObject + 0x4) == 0x5) { // object type creature
        char* conv;
        conv = (char*)(*(*(int**)(pGameObject + 0x318) + 0x11));
        if (!conv) {
            value[0] = 0;
            return;
        }
        int iConvLength = strlen(conv);
        int length = strlen(value);
        if (iConvLength < length) {
            strncpy(value, conv, iConvLength);
            *(value + iConvLength) = 0x0;
        } else {
            strncpy(value, conv, length);
            *(value + length) = 0x0;
        }
    }
}

void CNWNXFunction::GetUndroppable(char* value)
{
    if (*(pGameObject + 0x4) == 0x6) { // object type item
        int i = *(int*)(pGameObject - 0x14 + 0x280);
        if (strlen(value) > 1)
            sprintf(value, "%d", i);
    }
}

void CNWNXFunction::SetUndroppable(char* value)
{
    if (*(pGameObject + 0x4) == 0x6) { // object type item
        int i = atoi(value);
        *(int*)(pGameObject - 0x14 + 0x280) = i;
    }
}

void CNWNXFunction::GetItemWeight(char *value)
{
    if (*(pGameObject + 0x4) == 0x6) { // object type item
        int i = *(int*)(pGameObject - 0x14 + 0x28C);
        if (strlen(value) > 1)
            sprintf(value, "%d", i);
    }
}

void CNWNXFunction::SetItemWeight(char *value)
{
    if (*(pGameObject + 0x4) == 0x6) { // object type item
        int i = atoi(value);
        *(int*)(pGameObject - 0x14 + 0x28C) = i;
    }
}

void CNWNXFunction::GetEventHandler(char* value)
{
    int event_id = atoi(value);
    if (event_id < 0 || event_id > 12) return;

    int length = strlen(value);
    //char *func;
    if (*(pGameObject + 0x4) != 0x5) // object type creature
        return;

    CNWSCreature *cr = (CNWSCreature *)(pGameObject - 4);
    CExoString *func_0 = &cr->HeartbeatScript;
    char *func = func_0[event_id].Text;

    //func = (char*)(*(int*)(pGameObject+0x1F4+0x8*event_id));
    if (!func) { value[0] = 0; return; }

    int iFuncLength = strlen(func);

    if (iFuncLength < length) {
        strncpy(value, func, iFuncLength);
        *(value + iFuncLength) = 0x0;
    } else {
        strncpy(value, func, length);
        *(value + length) = 0x0;
    }
}

void CNWNXFunction::SetEventHandler(char* value)
{
    char *scriptname = (char *) malloc(strlen(value));
    int event_id;
    sscanf(value, "%i:%s", &event_id, scriptname);

    int length = strlen(scriptname);
    char *func;
    char *p_func;
    int *func_len;

    if (*(pGameObject + 0x4) != 0x5) // object type creature
        return;
    if (event_id < 0 || event_id > 12) return;

    p_func = (char*)(pGameObject + 0x1F4 + 0x8 * event_id);
    func = (char*)(*(int*)(pGameObject + 0x1F4 + 0x8 * event_id));
    func_len = (int*)(pGameObject + 0x1F4 + 0x8 * event_id + 0x4);

    if (!func || func_len == 0) return;

    int iFuncLength = strlen(func);
    //char *newfunc = new char[length+1];
    //strncpy(newfunc, scriptname, length);
    //*(scriptname+length) = 0x0;
    asm("mov %0, %%eax" : : "b"(pGameObject+0x1F4+0x8*event_id));
    asm("mov %0, (%%eax)" : : "b"(scriptname));
    free(func);

    //strncpy(func, scriptname, length);
    //*(func+length) = 0x0;
    *(func_len) = length + 1;
}

void CNWNXFunction::GetFactionID(char* value)
{
    if (!bHooked) return;
    int nFaction;
    GetFaction(*(dword *)pGameObject, &nFaction);
    if (strlen(value) > 2) {
        sprintf(value, "%d", nFaction);
    }
}

void CNWNXFunction::SetFactionID(char* value)
{
    if (!bHooked) return;
    int nFaction = atoi(value);
    if (nFaction > 0) {
        SetFaction(*(dword *)pGameObject, nFaction);
    }
}

char *CNWNXFunction::GetGroundHeight(char* value)
{
    dword AreaID;
    float x, y, z;
    if (sscanf(value, "%x¬%f¬%f¬%f", &AreaID, &x, &y, &z) < 4) {
        Log(0, "o sscanf error\n");
        return NULL;
    }
    void *pArea = GetAreaByID(AreaID);
    if (!pArea) {
        Log(0, "o Could not return area object\n");
        return NULL;
    }
    float XRes = GetZCoordinate(pArea, x, y, z);
    Log(2, "GetGroundHeight(%x=%p,%f,%f,%f) = %f\n", AreaID, pArea, x, y, z, XRes);
    char *sOut = new char[20];
    sprintf(sOut, "%f", XRes);
    return sOut;
}

void CNWNXFunction::GetIsWalkableHL(char* value)
{
    dword AreaID;
    float x, y, z;
    if (sscanf(value, "%x¬%f¬%f¬%f", &AreaID, &x, &y, &z) < 4) {
        Log(0, "o sscanf error\n");
        return;
    }
    void *pArea = GetAreaByID(AreaID);
    if (!pArea) {
        Log(0, "o Could not return area object\n");
        return;
    }
    int res = GetIsWalkable(pArea, x, y, z);
    Log(2, "GetIsWalkable(%f,%f,%f) = %d\n", x, y, z, res);
    if (strlen(value) > 2) {
        sprintf(value, "%d", res);
    }
}

void CNWNXFunction::ChangeBackgroundMusicForPlayer(char* value)
{
    dword AreaID = GetObjectAreaID(pGameObject - 4);
    dword nTrack = atoi(value);
    void *pArea = GetAreaByID(AreaID);
    if (!pArea) {
        Log(0, "o Could not return area object\n");
        return;
    }
    CNWSAmbientSound *pAmbient = *(CNWSAmbientSound**)((char*)pArea + 0x1E8);
    if (!pArea) {
        Log(0, "o Could not return ambient sound object\n");
        return;
    }
}

int ReadNextParam(char **psCurrentPosition, char *sDestination, unsigned int nDefMaxLen)
{
    unsigned int nMaxLen = 0;
    char *sCurrentPosition = *psCurrentPosition;
    if (!sCurrentPosition) return 0;

    char *sDelimiter = strchr(sCurrentPosition, '¬');
    if (!sDelimiter) return 0;

    if (sDelimiter - sCurrentPosition > nDefMaxLen) nMaxLen = nDefMaxLen;
    else nMaxLen = sDelimiter - sCurrentPosition;

    strncpy(sDestination, sCurrentPosition, nMaxLen);
    sDestination[nMaxLen] = 0;

    *psCurrentPosition = sDelimiter + 1;
    return 1;
}

void CNWNXFunction::Set2DAString(char* value)
{
    //Get parameters
    char s2DA[17];
    char sColumn[36];
    char sRow[5];
    int nRow;
    char *nLastDelimiter = strrchr(value, '¬');
    if (!nLastDelimiter || (nLastDelimiter - value) < 0) {
        Log(0, "o nLastDelimiter error\n");
        return;
    }
    /*if(sscanf(value, "%s¬%s¬%d¬", s2DA, sColumn, &nRow)<3)
    {
    	Log(0, "o sscanf error\n");
    	return;
    }*/
    unsigned int nMaxLen = 0;
    char *sCurrentPosition = value;
    if (!ReadNextParam(&sCurrentPosition, s2DA, 16)) {
        Log(0, "o Could not read the parameters list\n");
        return;
    }
    if (!ReadNextParam(&sCurrentPosition, sColumn, 35)) {
        Log(0, "o Could not read the parameters list\n");
        return;
    }
    if (!ReadNextParam(&sCurrentPosition, sRow, 4)) {
        Log(0, "o Could not read the parameters list\n");
        return;
    }
    nRow = atoi(sRow);
    //strcpy(sValue, sCurrentPosition+1);

    int nValueLen = strlen(value) - (nLastDelimiter - value) + 1;
    char *sNewValue = (char *) malloc(nValueLen);
    strncpy(sNewValue, nLastDelimiter + 1, nValueLen - 1);

    //Find the column
    C2DA *p2DA = Get2DARes(s2DA);
    if (!p2DA) {
        Log(0, "o 2DA not found\n");
        free(sNewValue);
        return;
    }
    int nColumnID = p2DA->GetColumnID(sColumn);
    if (nColumnID == -1) {
        Log(0, "o Column not found\n");
        free(sNewValue);
        return;
    }
    int nRowID = p2DA->GetRowID(nRow);
    if (nRowID == -1) {
        Log(0, "o Row not found\n");
        free(sNewValue);
        return;
    }
    CExoString *sFieldValue = &p2DA->Rows[nRowID][nColumnID];
    if (sFieldValue->Text)
        free(sFieldValue->Text);
    sFieldValue->Text = sNewValue;
    sFieldValue->Length = nValueLen;
}

void CNWNXFunction::SetMovementRate(char* value)
{
    if (!bHooked) return;
    if (*(pGameObject + 0x4) == 0x5) { // object type creature
        int nMovementRateType = atoi(value);
        SetCreatureMovementRate(pGameObject - 0x4, nMovementRateType);
    }
}

void CNWNXFunction::ActUseItem(char* value)
{
    dword oItem, oTarget, nPropertyNum;
    float x, y, z;

    if (!bHooked) return;
    if (*(pGameObject + 0x4) == 0x5) { // object type creature
        if (sscanf(value, "%x¬%x¬%f¬%f¬%f¬%d", &oItem, &oTarget, &x, &y, &z, &nPropertyNum) < 6) {
            Log(0, "o sscanf error\n");
            return;
        }
        ActionUseItem(pGameObject - 0x4, oItem, oTarget, x, y, z, nPropertyNum);
    }
}

void CNWNXFunction::GetPCPort(char* value)
{
    dword nPort = GetPlayerPort(*(dword *)pGameObject);
    Log(2, "Player port = %d\n", nPort);
    sprintf(value, "%d", nPort);
}

void CNWNXFunction::BootPC(char* value)
{
    if (!bHooked) return;
    if (*(pGameObject + 0x4) == 0x5) { // object type creature
        DisconnectPlayer(*(dword *)pGameObject, atoi(value));
    }
}

void CNWNXFunction::ActJumpToLimbo(char* value)
{
    if (!bHooked) return;
    if (*(pGameObject + 0x4) == 0x5) { // object type creature
        int nRetVal = JumpToLimbo(*(dword *)pGameObject);
        Log(2, "Jump to limbo: %d\n", nRetVal);
        if (strlen(value) >= 2) sprintf(value, "%d", nRetVal);
    }
}

char *CNWNXFunction::GetFirstLocalVariable(char* value)
{
    nCurrentVarNum = -1;
    return this->GetNextLocalVariable(value);
}

char *CNWNXFunction::GetNextLocalVariable(char* value)
{
    nCurrentVarNum++;
    CNWSScriptVar *pVariable;
    char *sOutput = NULL;
    pVariable = GetLocalVarByPosition(pGameObject - 0x4, nCurrentVarNum);
    if (!pVariable || pVariable->VarType < 1 || pVariable->VarType > 5 || !pVariable->VarName.Text) return NULL;
    //build output
    switch (pVariable->VarType) {
        case VARIABLE_TYPE_INT:
            sOutput = (char *) malloc(strlen(pVariable->VarName.Text) + 14);
            sprintf(sOutput, "%s¬%d¬%d", pVariable->VarName.Text, VARIABLE_TYPE_INT, pVariable->VarValue);
            break;
        case VARIABLE_TYPE_FLOAT:
            sOutput = (char *) malloc(strlen(pVariable->VarName.Text) + 4 + 18);
            sprintf(sOutput, "%s¬%d¬%18.09f", pVariable->VarName.Text, VARIABLE_TYPE_FLOAT, *(float*)&pVariable->VarValue);
            break;
        case VARIABLE_TYPE_STRING:
            if (pVariable->VarValue) {
                sOutput = (char *) malloc(strlen(pVariable->VarName.Text) + strlen(((CExoString *)pVariable->VarValue)->Text)) + 4;
                sprintf(sOutput, "%s¬%d¬%s", pVariable->VarName.Text, VARIABLE_TYPE_STRING, ((CExoString *)pVariable->VarValue)->Text);
            } else {
                sOutput = (char *) malloc(strlen(pVariable->VarName.Text) + 4);
                sprintf(sOutput, "%s¬%d¬", pVariable->VarName.Text, VARIABLE_TYPE_STRING);
            }
            break;
        case VARIABLE_TYPE_OBJECT:
            sOutput = (char *) malloc(strlen(pVariable->VarName.Text) + 14);
            sprintf(sOutput, "%s¬%d¬%d", pVariable->VarName.Text, VARIABLE_TYPE_OBJECT, pVariable->VarValue);
            break;
        case VARIABLE_TYPE_LOCATION:
            sOutput = (char *) malloc(strlen(pVariable->VarName.Text) + 4);
            sprintf(sOutput, "%s¬%d¬", pVariable->VarName.Text, VARIABLE_TYPE_LOCATION);
            break;
    }
    return sOutput;
}

void CNWNXFunction::GetItemCount_Ext(char* value)
{
    dword nCount = GetItemCount(pGameObject - 0x4);
    Log(2, "Item count = %d\n", nCount);
    sprintf(value, "%d", nCount);
}

void CNWNXFunction::GetItemByPosition_SetPos(char* value)
{
    nItemPosition = atoi(value);
}

void CNWNXFunction::IntToObject(char * value)
{
    nTempObjectID = atoi(value);
}

void CNWNXFunction::SetELC(char *value)
{
    CServerExoApp *pServ = GetServerExoApp();
    pServ->Internal->config->EnforceLegalCharacters = (atoi(value) == 1);
}

void CNWNXFunction::SetILR(char *value)
{
    CServerExoApp *pServ = GetServerExoApp();
    pServ->Internal->config->ItemLevelRestrictions = (atoi(value) == 1);
}

void CNWNXFunction::DebugMe(char* value)
{

}

void CNWNXFunction::ObjDump(char *value)
{
    int i, j;
    char buf[2048], chbuf[16], prbuf[32], *p;
    unsigned char *ob = (unsigned char *)pGameObject;

    sprintf(buf, "object: %08p  tag: %s  type: %d", ob,
            *((char **)(ob + 0x18)), ob[4]);
    p = buf + strlen(buf);

    if (ob[4] == 5) {
        sprintf(p, "  creature: %08p", (char *)(ob + 0xC60));
        p = buf + strlen(buf);
    }

    p = stpcpy(p, "\n");

    for (i = 0; i < 16; i++) {
        prbuf[0] = 0;

        for (j = (i * 256); j < ((i + 1) * 256); j++) {
            if (j % 16 == 0) {
                snprintf(chbuf, sizeof(chbuf), "\n0x%04X:  ", j);
                strcat(prbuf, chbuf);
                p = stpcpy(p, prbuf);

                snprintf(prbuf, sizeof(prbuf), "|................|");
            }

            if (j % 8 == 7)
                snprintf(chbuf, sizeof(chbuf), "%02x  ", ob[j]);
            else
                snprintf(chbuf, sizeof(chbuf), "%02x ", ob[j]);

            p = stpcpy(p, chbuf);

            if (ob[j] >= ' ' && ob[j] < 127)
                prbuf[(j % 16) + 1] = ob[j];
        }

        p = stpcpy(p, prbuf);
        p = stpcpy(p, "\n");

        Log(1, "%s", buf);

        p = buf;
    }
}

bool CNWNXFunction::OnCreate(gline *config, const char *LogDir)
{
    char log[128];
    sprintf(log, "%s/nwnx_fn.txt", LogDir);

    // call the base class function
    if (!CNWNXBase::OnCreate(config, log))
        return false;
    Log(0, "NWNX Functions V.1.9.1\n");
    Log(0, "(c) 2004 by the APS/NWNX Linux Conversion Group\n");
    Log(0, "Based on the Win32 version (c) 2003 by Ingmar Stieger (Papillon)\n");
    Log(0, "(c) by virusman, 2006-2009\n");
    Log(0, "visit us at http://www.nwnx.org\n\n");
    if (FindFunctions()) {
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

char* CNWNXFunction::OnRequest(char *gameObject, char* Request, char* Parameters)
{
    this->pGameObject = gameObject + 4;

    Log(2, "(S) Request: \"%s\"\n", Request);
    Log(3, "(S) Params:  \"%s\"\n", Parameters);

    if (strncmp(Request, "SETGOLDPIECEVALUE", 17) == 0) {
        SetGoldPieceValue(Parameters);
        return NULL;
    } else if (strncmp(Request, "SETTAG", 6) == 0) {
        SetTag(Parameters);
        return NULL;
    } else if (strncmp(Request, "SETARMORAC", 10) == 0) {
        SetArmorAC(Parameters);
        return NULL;
    } else if (strncmp(Request, "GETARMORAC", 10) == 0) {
        GetArmorAC(Parameters);
        return NULL;
    } else if (strncmp(Request, "SETRACIALTYPE", 13) == 0) {
        SetRacialType(Parameters);
        return NULL;
    } else if (strncmp(Request, "GETDESCRIPTIONLENGTH", 20) == 0) {
        GetDescriptionLength(Parameters);
        return NULL;
    } else if (strncmp(Request, "GETDESCRIPTION", 14) == 0) {
        return GetDescription(Parameters);
    } else if (strncmp(Request, "SETDESCRIPTION", 14) == 0) {
        SetDescription(Parameters);
        return NULL;
    } else if (strncmp(Request, "GETCONVERSATION", 15) == 0) {
        GetConversation(Parameters);
        return NULL;
    } else if (strncmp(Request, "GETUNDROPPABLE", 14) == 0) {
        GetUndroppable(Parameters);
        return NULL;
    } else if (strncmp(Request, "SETUNDROPPABLE", 14) == 0) {
        SetUndroppable(Parameters);
        return NULL;
    } else if (strncmp(Request, "GETITEMWEIGHT", 13) == 0) {
        GetItemWeight(Parameters);
        return NULL;
    } else if (strncmp(Request, "SETITEMWEIGHT", 13) == 0) {
        SetItemWeight(Parameters);
        return NULL;
    } else if (strncmp(Request, "GETEVENTHANDLER", 14) == 0) {
        GetEventHandler(Parameters);
        return NULL;
    } else if (strncmp(Request, "SETEVENTHANDLER", 14) == 0) {
        SetEventHandler(Parameters);
        return NULL;
    } else if (strncmp(Request, "GETFACTION", 10) == 0) {
        if (bHooked) GetFactionID(Parameters);
        return NULL;
    } else if (strncmp(Request, "SETFACTION", 10) == 0) {
        if (bHooked) SetFactionID(Parameters);
        return NULL;
    } else if (strncmp(Request, "GETGROUNDHEIGHT", 15) == 0) {
        if (bHooked) return GetGroundHeight(Parameters);
    } else if (strncmp(Request, "GETISWALKABLE", 13) == 0) {
        if (bHooked) GetIsWalkableHL(Parameters);
        return NULL;
    } else if (strncmp(Request, "SET2DASTRING", 12) == 0) {
        Set2DAString(Parameters);
        return NULL;
    } else if (strncmp(Request, "SET_MOVEMENT_RATE", 17) == 0) {
        SetMovementRate(Parameters);
        return NULL;
    } else if (strncmp(Request, "ACTION_USE_ITEM", 15) == 0) {
        ActUseItem(Parameters);
        return NULL;
    } else if (strncmp(Request, "GET_PC_PORT", 11) == 0) {
        GetPCPort(Parameters);
        return NULL;
    } else if (strncmp(Request, "BOOT_PC", 7) == 0) {
        BootPC(Parameters);
        return NULL;
    } else if (strncmp(Request, "JUMP_TO_LIMBO", 13) == 0) {
        ActJumpToLimbo(Parameters);
        return NULL;
    } else if (strncmp(Request, "GET_FIRST_LOCALVAR", 18) == 0) {
        return GetFirstLocalVariable(Parameters);
    } else if (strncmp(Request, "GET_NEXT_LOCALVAR", 17) == 0) {
        return GetNextLocalVariable(Parameters);
    } else if (strncmp(Request, "GET_ITEM_COUNT", 14) == 0) {
        GetItemCount_Ext(Parameters);
        return NULL;
    } else if (strncmp(Request, "GET_ITEM_BY_POSITION", 20) == 0) {
        GetItemByPosition_SetPos(Parameters);
        return NULL;
    } else if (strncmp(Request, "INT_TO_OBJECT", 13) == 0) {
        IntToObject(Parameters);
        return NULL;
    } else if (strncmp(Request, "SET_ELC", 7) == 0) {
        SetELC(Parameters);
        return NULL;
    } else if (strncmp(Request, "SET_ILR", 7) == 0) {
        SetILR(Parameters);
        return NULL;
    } else if (strncmp(Request, "DEBUGME", 7) == 0) {
        DebugMe(Parameters);
        return NULL;
    } else if (strncmp(Request, "OBJDUMP", 7) == 0) {
        ObjDump(Parameters);
        return NULL;
    }
    return NULL;
}

/*unsigned long CNWNXFunction::GetObjectByID()
{

}*/

unsigned long CNWNXFunction::GetFirstArea()
{
    void *pModule = GetModule();
    if (!pModule) return OBJECT_INVALID;
    dword *pAreaList = *(dword**)((char*)pModule + 0x38);
    if (!pAreaList) return OBJECT_INVALID;
    dword nAreaNum = *(dword*)((char*)pModule + 0x3C);
    Log(2, "nAreaNum = %d\n", nAreaNum);
    if (nAreaNum < 1) return OBJECT_INVALID;
    nTotalAreaCount = nAreaNum;
    nCurrentAreaNum = 0;
    return pAreaList[nCurrentAreaNum];
}

unsigned long CNWNXFunction::GetNextArea()
{
    nCurrentAreaNum++;
    void *pModule = GetModule();
    if (!pModule) return OBJECT_INVALID;
    dword *pAreaList = *(dword**)((char*)pModule + 0x38);
    if (!pAreaList) return OBJECT_INVALID;
    dword nAreaNum = *(dword*)((char*)pModule + 0x3C);
    if (nAreaNum < 1) return OBJECT_INVALID;
    if (nCurrentAreaNum >= nAreaNum) return OBJECT_INVALID;

    Log(2, "Area[%d/%d] = %d\n", nCurrentAreaNum, nAreaNum, pAreaList[nCurrentAreaNum]);
    return pAreaList[nCurrentAreaNum];
}

unsigned long CNWNXFunction::GetItemByPosition_Ext()
{
    dword nItemID = GetItemByPosition(pGameObject - 0x4, nItemPosition);
    Log(2, "Item = %08lX\n", nItemID);
    return nItemID;
}

unsigned long CNWNXFunction::IntToObject_ret()
{
    return nTempObjectID;
}

unsigned long CNWNXFunction::OnRequestObject(char *gameObject, char* Request)
{
    this->pGameObject = gameObject + 4;

    Log(2, "(O) Request: \"%s\"\n", Request);

    if (strncmp(Request, "GET_FIRST_AREA", 14) == 0)
        return GetFirstArea();
    else if (strncmp(Request, "GET_NEXT_AREA", 13) == 0)
        return GetNextArea();
    else if (strncmp(Request, "GET_ITEM_BY_POSITION", 20) == 0)
        return GetItemByPosition_Ext();
    else if (strncmp(Request, "INT_TO_OBJECT", 13) == 0)
        return IntToObject_ret();


    return OBJECT_INVALID;
}

