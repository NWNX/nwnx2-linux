/***************************************************************************
    Functions plugin for NWNX  - hooks implementation
    (c) 2005 virusman (virusman@virusman.ru)

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

#include <sys/types.h>
#include <sys/mman.h>
#include <dlfcn.h>
#include <stdarg.h>

#include <limits.h>		/* for PAGESIZE */
#ifndef PAGESIZE
#define PAGESIZE 4096
#endif

#include "FunctionHooks.h"
#include "NWNXFunction.h"
#include "AssemblyHelper.cpp"

extern CNWNXFunction functions;
AssemblyHelper asmhelp;

//Functions:
//Return value: 0 upon success, 1 upon failure
int (*pGetObjByOID)(void *pObjectClass, dword ObjID, void **buf);
void *(*pRetObjByOID)(void *pServerExo, long ObjID);
void *(*pGetPlayer)(void *pServerExo4, dword ObjID);
//Return value: 1 upon success, 0 upon failure
int (*pGetFaction)(void *pServerExo, long ObjID, int *buf);
void *(*pGetFactionEntry)(void *pFactionClass, int nFaction);
void (*pChangeFaction)(void *pFactionEntry, int ObjID, int unk);
void *(*pGetObjectFactionEntry)(void *pObject);
long(*pGetFactionLeader)(void *pFactionEntry);
void *(*pGetAreaByID)(void *pServerExo, dword nAreaID);
float(*pGetZCoordinate)(void *pArea, float X, float Y, float Z);
int (*pGetIsWalkable)(void *pArea, float X, float Y, float Z, void *pSomePositionStruct);
void *(*pGetModule)(void *pServerExo4);
void (*pChangeBackgroundMusicForPlayer)(void *pServerMessage, dword nClientID, dword nDayNight, dword nTrackID);
void (*pSetMovementRate)(void *pCreatureInfoStruct, dword nMovementRateType);
void (*pActionUseItem)(void *pCreature, dword nItemObjID, dword nPropertyNum, dword arg_C, dword nTargetObjID, float X, float Y, float Z, dword nAreaID);
void (*pDisconnectPlayer)(void *pClientList, dword nPlayerID, dword nStringRef, dword arg_C);
void (*pRemoveObjectFromLocation)(void *pObject, dword arg_4);
void (*pAddObjectToLimboList)(void *pModule, dword nObjID);
void (*pSetTag)(void *pObject, CExoString *sNewTag);

//Constants:

void *pServer = 0;
void *pServerExo = 0;
void *pServerExo4 = 0;
void *pObjectClass = 0;
void *pFactionClass = 0;
void *pClientClass = 0;
void *pRules = 0;
void *p2das = 0;
//dword pScriptThis = 0;
//dword oPC = 0;

unsigned char d_jmp_code[] = "\x68\x60\x70\x80\x90"       /* push dword 0x90807060 */
                             "\xc3\x90\x90\x90\x90";//x00 /* ret , nop , nop       */

unsigned char d_ret_code[0x20];

unsigned long lastRet;


CExoString *NewCExoString(char *str)
{
    CExoString *ret = (CExoString *) malloc(sizeof(CExoString));
    ret->Text = strdup(str);
    ret->Length = strlen(str) + 1;
    return ret;
}

CServerExoApp *GetServerExoApp()
{
    if (!functions.bHooked) return NULL;
    if (!pServer) InitConstants();
    return (CServerExoApp *) pServerExo;
}

void *GetObjectByID(dword ObjID)
{
    if (!functions.bHooked) return NULL;
    if (!pServer) InitConstants();
    void *pObject;
    pGetObjByOID(pObjectClass, ObjID, &pObject);
    return pObject;
}

long GetOIDByObj(void *pObject)
{
    return *((dword*)pObject + 0x4);
}

void *GetPlayer(dword ObjID)
{
    if (!functions.bHooked) return NULL;
    if (!pServer) InitConstants();
    return pGetPlayer(pServerExo4, ObjID);
}

int GetFaction(long ObjID, int *buf)
{
    if (!functions.bHooked) return -1;
    if (!pServer) InitConstants();
    return pGetFaction(*((void **)pServerExo + 1), ObjID, buf);
}

void SetFaction(long ObjID, int nFaction)
{
    if (!functions.bHooked) return;
    if (!pServer) InitConstants();
    void *pFactionEntry = pGetFactionEntry(pFactionClass, nFaction);
    pChangeFaction(pFactionEntry, ObjID, 0);
}

void *GetAreaByID(dword nAreaID)
{
    if (!functions.bHooked) return NULL;
    if (!pServer) InitConstants();
    return pGetAreaByID(*((void **)pServerExo + 1), nAreaID);
}

float GetZCoordinate(void *pArea, float X, float Y, float Z)
{
    return pGetZCoordinate(pArea, X, Y, Z);
}

int GetIsWalkable(void *pArea, float X, float Y, float Z)
{
    void *pSomePositionStruct = *(void **)((char*)pArea + 0x198);
    if (!pSomePositionStruct) {
        functions.Log(0, "Null. :(");
    }
    return pGetIsWalkable(pArea, X, Y, Z, pSomePositionStruct);
}

void *GetModule()
{
    if (!functions.bHooked) return NULL;
    if (!pServer) InitConstants();
    void *pModule = pGetModule(pServerExo4);
    return pModule;
}

void *GetAreaAmbientSound(void *pArea)
{
    return *(void **)((char*)pArea + 0x1E8);
}

dword GetObjectAreaID(void *pObject)
{
    return *(dword *)((char*)pObject + 0x78);
}

C2DA *Get2DARes(char *s2DA)
{
    if (!p2das) InitConstants();
    //if(strncmp(s2DA, "polymorph", 9) == 0)
    //{
    //	return *(C2DA **)((char*)p2das+0x234);
    //}
    //else return NULL;
    char *ptr = (char*)p2das + 0x8;
    int f_ext = 0;
    int buf = *ptr;
    while (!f_ext) {
        if (*ptr != buf && *ptr != buf + 1 && *ptr != 0 && *ptr % 4 == 0) {
            f_ext = 1;
        }
        buf = *ptr;
        if (!f_ext) ptr++;
        if (ptr - (char *)p2das > 0x500) { ptr = 0; f_ext = 1; }
    }
    functions.Log(3, "Found start of 2das: %08lX\n", ptr);

    C2DA **ptr2 = (C2DA **) ptr;
    C2DA *p2DA = NULL;
    f_ext = 0;
    while (!f_ext) {
        if (*ptr2) {
            p2DA = *ptr2;
            if (strncmp(p2DA->Name, s2DA, 16) == 0)
                f_ext = 1;
        }
        if (*(int *)ptr != 0 && *(int *)ptr < 0x80000) { ptr2 = 0; f_ext = 1; }
        if (!f_ext) ptr2++;
        if ((char *)ptr - (char*)p2das > 0x500) { ptr2 = 0; f_ext = 1; }
    }
    functions.Log(3, "Offset: %08lX\n", (char *)ptr2 - (char *)p2das);
    return p2DA;
}

void SetCreatureMovementRate(void *pCreature, dword nMovementRateType)
{
    if (!functions.bHooked) return;

    void *pCreatureInfoStruct = *(void**)((char*)pCreature + 0xC68);
    if (!pCreatureInfoStruct) return;
    pSetMovementRate(pCreatureInfoStruct, nMovementRateType);
}

void ActionUseItem(void *pCreature, dword oItem, dword oTarget, float X, float Y, float Z, dword nPropertyNum)
{
    if (!functions.bHooked) return;
    if (oItem == OBJECT_INVALID) return;
    if (!pCreature) return;
    dword nAreaID = GetObjectAreaID(pCreature);
    if (!nAreaID || nAreaID == OBJECT_INVALID) return;
    pActionUseItem(pCreature, oItem, nPropertyNum, 0, oTarget, X, Y, Z, nAreaID);
}

dword GetPlayerPort(dword nObjectID)
{
    //Yes, this is ugly. But I don't want to describe 4 or 5 nested structures. :)
    if (!functions.bHooked) return 0;
    if (!pClientClass) InitConstants();
    void *pPlayer = GetPlayer(nObjectID);
    if (!pPlayer) return 0;
    dword nPlayerID = *(dword *)pPlayer;
    void *pSomeStruct = *(void **)pClientClass;
    void *pClientStruct;
    dword nNum;
    if (!pSomeStruct) return 0;

    functions.Log(2, "GetPlayerPort: objectid=%x player=%p playerid=%x clientclass=%p somestruct=%p\n",
                  nObjectID, pPlayer, nPlayerID, pClientClass, pSomeStruct);

    for (int i = 0; i < 0x60; i++) {
        pClientStruct = (void *)((char *)pSomeStruct + 0xC + i * 0x91C);

        functions.Log(3, "- %02x clientstruct=%p +0x8=%x +0xC=%x\n", i, pClientStruct,
                      *(dword *)((char*)pClientStruct + 0x8), *(dword *)((char*)pClientStruct + 0xC));

        if (*(dword *)((char*)pClientStruct + 0x8) == 1) {
            if (*(dword *)((char*)pClientStruct + 0xC) == nPlayerID) {
                nNum = *(dword *)((char*)pClientStruct + 0x14);
                pSomeStruct = *(void **)((char*)pSomeStruct + 0x4);
                if (!pSomeStruct) return 0;
                pSomeStruct = *(void **)pSomeStruct;
                if (!pSomeStruct) return 0;

                byte *pFlagList = *(byte **)((char*)pSomeStruct + 0x34);
                if (!pFlagList || !pFlagList[nNum]) return 0;
                AddressStruct *pIP = *(AddressStruct **)((char*)pSomeStruct + 0x3C);
                if (!pIP) return 0;
                dword nPort = pIP[nNum].port;
                return nPort;
            }
        }
    }
    return 0;
}

void DisconnectPlayer(dword nObjectID, dword nStringRef)
{
    if (!functions.bHooked) return;
    if (!pClientClass) InitConstants();
    void *pPlayer = GetPlayer(nObjectID);
    if (!pPlayer) return;
    dword nPlayerID = *(dword *)pPlayer;
    pDisconnectPlayer(pClientClass, nPlayerID, nStringRef, 1);
}

int JumpToLimbo(dword nObjectID)
{
    void *pCreature = GetObjectByID(nObjectID);
    if (!pCreature) return 0;
    dword nCreatureType = *(dword *)((char*)pCreature + 0xB3C);
    void *pCreatureInfoStruct = *(void **)((char*)pCreature + 0xC68);
    if (!pCreatureInfoStruct) return 0;
    dword nIsPC = *(dword *)((char*)pCreatureInfoStruct + 0x6C);
    dword nIsDM = *(dword *)((char*)pCreatureInfoStruct + 0x70);
    if (nCreatureType == 7 || nCreatureType == 8 || nCreatureType == 3 ||
            nIsPC || nIsDM)
        return 0;

    pRemoveObjectFromLocation(pCreature, 0);
    void *pModule = GetModule();
    if (!pModule) return 0;
    pAddObjectToLimboList(pModule, nObjectID);
    return 1;
}

CNWSScriptVar *GetLocalVarByPosition(void *pObject, int nNum)
{
    if (!pObject) return NULL;
    char nObjectType = *((char*)pObject + 0x8);
    CNWSScriptVarTable *pVarList = NULL;
    if (nObjectType == 4)
        pVarList = (CNWSScriptVarTable *)((char*)pObject + 0x114);
    else if (nObjectType == 3)
        pVarList = (CNWSScriptVarTable *)((char*)pObject + 0x8C);
    else
        pVarList = (CNWSScriptVarTable *)((char*)pObject + 0xDC);
    return pVarList->GetVarByPosition(nNum);
}

dword GetItemCount(void *pObject)
{
    if (!pObject) return 0;
    char nObjectType = *((char*)pObject + 0x8);
    CItemRepository *pItemRepository = NULL;
    if (nObjectType == 5) //Creature
        pItemRepository = (CItemRepository *) * (dword *)((char*)pObject + 0xB74);
    else
        return 0;
    return pItemRepository->GetItemCount();
}

dword GetItemByPosition(void *pObject, dword nPos)
{
    if (!pObject) return OBJECT_INVALID;
    char nObjectType = *((char*)pObject + 0x8);
    CItemRepository *pItemRepository = NULL;
    if (nObjectType == 5) //Creature
        pItemRepository = (CItemRepository *) * (dword *)((char*)pObject + 0xB74);
    else
        return OBJECT_INVALID;
    return pItemRepository->GetItemByPosition(nPos);
}

void CNWSObject_SetTag(CNWSObject *oObject, CExoString *sNewTag)
{
    pSetTag(oObject, sNewTag);
}

int FindFunctions()
{
    //Version check
    /*char *build;
    *(dword*)&build = 0x08308EE3;
    functions.Log(2, "Version: ");
    functions.Log(2, "%s\n", build);
    if(strncmp(build, "8093", 4)!=0) return false;
    functions.Log(2, "Checked\n");*/

    //Functions
    //*(dword*)&pGetObjByOID =				0x080B8EDC;
    //*(dword*)&pRetObjByOID =				0x080B0378;
    //*(dword*)&pGetFaction =				0x080B0AF0;
    //*(dword*)&pGetFactionEntry =			0x080B85B0;
    //*(dword*)&pChangeFaction =			0x081D3794;
    //*(dword*)&pGetObjectFactionEntry =	0x081109B0;
    //*(dword*)&pGetFactionLeader =			0x081D49A8;
    //*(dword*)&pGetZCoordinate =			0x080D40D0;
    //*(dword*)&pGetAreaByID =				0x080B03A8;  //0x080AEA1C
    //*(dword*)&pGetIsWalkable =			0x080D427C;
    *(dword*)&pGetObjByOID = asmhelp.FindFunctionBySignature("55 89 E5 8B 45 0C 56 53 89 C2 89 C3 C1 E8 1F 0F B7 C0 C1 E0 0C");
    functions.Log(2, "GetObjByOID: %08lX\n", pGetObjByOID);
    *(dword*)&pGetPlayer = asmhelp.FindFunctionBySignature("55 89 E5 57 56 53 83 EC 0C 8B ** 0C 81 FF 00 00 00 7F");
    functions.Log(2, "GetPlayer: %08lX\n", pGetPlayer);
    *(dword*)&pGetFaction =	asmhelp.FindFunctionBySignature("55 89 E5 56 53 ** ** ** 8D 45 F4 50 8B 55 0C");
    functions.Log(2, "GetFaction: %08lX\n", pGetFaction);
    *(dword*)&pGetFactionEntry = asmhelp.FindFunctionBySignature("55 89 E5 ** ** ** 8B 55 0C 85 D2 8B 4D 08 78");
    functions.Log(2, "GetFactionEntry: %08lX\n", pGetFactionEntry);
    *(dword*)&pChangeFaction = asmhelp.FindFunctionBySignature("55 89 E5 57 56 53 ** ** ** A1 ** ** ** ** 8B 40 04 FF 75 0C 50 89 45 F0");
    functions.Log(2, "ChangeFaction: %08lX\n", pChangeFaction);
    *(dword*)&pGetObjectFactionEntry = asmhelp.FindFunctionBySignature("55 89 E5 ** ** ** A1 ** ** ** ** 8B 40 04 8B 55 08 8B 48 04 8B 82 64 0C 00 00 FF B0 88 00 00 00");
    if (!pGetObjectFactionEntry)
        *(dword*)&pGetObjectFactionEntry = asmhelp.FindFunctionBySignature("55 89 E5 ** ** ** A1 ** ** ** ** 8B 40 04 8B 55 08 8B 48 04 8B 82 68 0C 00 00 FF B0 90 00 00 00");
    functions.Log(2, "GetObjectFactionEntry: %08lX\n", pGetObjectFactionEntry);
    *(dword*)&pGetFactionLeader = asmhelp.FindFunctionBySignature("55 89 E5 57 56 53 ** ** ** A1 ** ** ** ** C7 45 F0 00 00 00 7F 8B 40 04 89 45 EC FF 75 08");
    functions.Log(2, "GetFactionLeader: %08lX\n", pGetFactionLeader);
    *(dword*)&pGetZCoordinate = asmhelp.FindFunctionBySignature("55 89 E5 57 56 53 ** ** ** 31 D2 8B 3D ** ** ** ** BB FF FF FF FF 39 FA 89 DE 7D");
    functions.Log(2, "GetZCoordinate: %08lX\n", pGetZCoordinate);
    *(dword*)&pGetAreaByID = asmhelp.FindFunctionBySignature("55 89 E5 8D 45 FC ** ** ** 50 8B 55 0C 52 8B 4D 08 FF B1 80 00 01 00 C7 45 FC 00 00 00 00 +41 FF 50 30");
    functions.Log(2, "GetAreaByID: %08lX\n", pGetAreaByID);
    *(dword*)&pGetIsWalkable = asmhelp.FindFunctionBySignature("55 89 E5 57 56 53 81 EC ** ** ** ** 8B 55 18 D9 42 04 D9 45 0C 8B 45 08");
    functions.Log(2, "GetIsWalkable: %08lX\n", pGetIsWalkable);
    *(dword*)&pGetModule = asmhelp.FindFunctionBySignature("55 89 E5 8D 45 FC 83 EC 0C 8B 55 08 50 FF B2 84 00 01 00 FF B2 80 00 01 00 C7 45 FC 00 00 00 00 E8");
    functions.Log(2, "GetModule: %08lX\n", pGetModule);
    *(dword*)&pSetMovementRate = asmhelp.FindFunctionBySignature("55 89 E5 57 56 53 81 EC ** ** ** ** A1 +19 83 FA 07");
    functions.Log(2, "SetMovementRate: %08lX\n", pSetMovementRate);
    *(dword*)&pActionUseItem = asmhelp.FindFunctionBySignature("55 89 E5 57 56 53 81 EC ** 00 00 00 8A 45 10 8A 55 14 88 45 ** 88 55 **");
    if (!pActionUseItem)
        *(dword*)&pActionUseItem = asmhelp.FindFunctionBySignature("55 89 E5 57 56 53 83 EC 64 8A 45 10 8A 4D 14 88 45 A7 88 4D A6 FF 75 0C C7 45 A0 00 00 00 00");
    functions.Log(2, "ActionUseItem: %08lX\n", pActionUseItem);
    *(dword*)&pDisconnectPlayer = asmhelp.FindFunctionBySignature("55 89 E5 83 EC 14 FF 75 14 6A 01 FF 75 10 FF 75 0C 8B 45 08 FF 30 E8");
    functions.Log(2, "DisconnectPlayer: %08lX\n", pDisconnectPlayer);
    *(dword*)&pRemoveObjectFromLocation = asmhelp.FindFunctionBySignature("55 89 E5 57 56 53 83 EC ** FF 75 08 E8 ** ** ** ** 83 C4 10 85 C0 74 1A");
    functions.Log(2, "RemoveObjectFromLocation: %08lX\n", pRemoveObjectFromLocation);
    *(dword*)&pAddObjectToLimboList = asmhelp.FindFunctionBySignature("55 89 E5 57 56 53 83 EC ** 8B 75 08 8D 86 10 02 00 00 31 DB 89 45 F0 3B 9E 14 02 00 00");
    if (!pAddObjectToLimboList)
        *(dword*)&pAddObjectToLimboList = asmhelp.FindFunctionBySignature("55 89 E5 57 56 53 83 EC 0C 8B 75 08 8D 86 18 02 00 00 31 DB 89 45 F0 3B 9E 1C 02 00 00");
    functions.Log(2, "AddObjectToLimboList: %08lX\n", pAddObjectToLimboList);
    *(dword*)&pSetTag = 0x081D5EE8;
    functions.Log(2, "SetTag: %08lX\n", pSetTag);


    if (!(pGetFaction && pGetFactionEntry && pChangeFaction && pGetObjectFactionEntry &&
            pGetFactionLeader && pGetZCoordinate && pGetAreaByID && pGetIsWalkable && pGetModule &&
            pGetPlayer && pSetMovementRate && pActionUseItem && pDisconnectPlayer &&
            pRemoveObjectFromLocation && pAddObjectToLimboList)) {
        functions.Log(2, "Some of the functions could not be found\n");
        return false;
    }
    functions.Log(2, "All functions set\n");
    return true;
}

void InitConstants()
{
    //Constants
    dword *ppServer = *(dword**)((char *)pGetObjectFactionEntry + 0x7);
    //functions.Log(2, "ppServer=%08lX", ppServer);
    //*(dword*)&ppServer = 0x083281D4;
    *(dword*)&pServer = *ppServer;  //CAppManager
    *(dword*)&pRules = *(ppServer + 2);
    *(dword*)&p2das = *(dword*)((char*)pRules + 0xF0);
    *(dword*)&pServerExo = *(dword*)((char*)pServer + 0x4); //CServerExoApp
    *(dword*)&pServerExo4 = *(dword*)((char*)pServerExo + 0x4); //CServerExoAppInternal


    //Да, я знаю, я извращенец!
    *(dword*)&pObjectClass = *(dword*)(*(dword*)((char*)pServerExo + 0x4) + 0x10080);
    *(dword*)&pFactionClass = *(dword*)(*(dword*)((char*)pServerExo + 0x4) + 0x10074);
    *(dword*)&pClientClass = *(dword*)(*(dword*)((char*)pServerExo + 0x4) + 0x10060);

}

