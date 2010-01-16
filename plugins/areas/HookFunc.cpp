/***************************************************************************
    Events plugin for NWNX  - hooks implementation
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

#include <sys/types.h>
#include <sys/mman.h>
#include <dlfcn.h>
#include <stdarg.h>

#include <limits.h>		/* for PAGESIZE */
#ifndef PAGESIZE
#define PAGESIZE 4096
#endif

#include "HookFunc.h"
#include "CGameObjectArray.h"
#include "NWNStructures.h"
#include "NWNXAreas.h"
#include "AssemblyHelper.cpp"

extern CNWNXAreas areas;
AssemblyHelper asmhelp;


void (*CNWSArea__CNWSArea)(void *pArea, CResRef res, int a3, dword ObjID);
void (*CNWSArea__LoadArea)(void *pArea, int flag);
void (*CExoArrayList__Add)(void *pArray, dword nObjID);
void (*CExoArrayList__Remove)(void *pArray, dword nObjID);
void (*CNWSArea__Destructor)(void *pArea, int flag);
void *(*GetAreaByGameObjectID)(void *pServerExoAppInternal, dword nObjID);
CGameObjectArray *(*CServerExoApp__GetObjectArray)(void *pServerExo);
void (*CExoArrayList_unsigned_long___Add)(CExoArrayList *pArray, unsigned long nElement);
void (*CExoArrayList_unsigned_long___Remove)(CExoArrayList *pArray, unsigned long nElement);
int (*CExoArrayList_unsigned_long___IndexOf)(CExoArrayList *pArray, unsigned long nElement);
CExoLinkedList *(*pGetPlayerList)(void *pServerExo);
void *(*pGetServerMessage)(void *pServerExo);
void (*SendServerToPlayerDungeonMasterAreaList)(void *pMessage, void *pPlayer);


dword ppServThis = 0;
dword pServThis = 0; //g_pAppManager
dword pScriptThis = 0;
dword pServInternal = 0;

CResRef *CResRef____as(CResRef *res, char *str)
{
	memset(res->ResRef, 0, 0x10);
	strncpy(res->ResRef, str, 0x10);
	return res;
}

void AddAreaToCreatures(CNWSModule *pModule, dword nAreaID)
{
	if(!pServThis) InitConstants();
	CGameObjectArray *pGameObjArray = CServerExoApp__GetObjectArray((void *)pServThis);
	
	areas.Log(3, "Area count: %d\n", pModule->Areas.Count);
	if(!pGameObjArray) return;
	for(int i=0; i<=0xFFF; i++)
	{
		CGameObjectArrayElement **pObjects = pGameObjArray->Objects;
		CGameObjectArrayElement *pElement = pObjects[i];
		if(!pElement) continue;
		CNWSCreature *pObject = (CNWSCreature *) pElement->Object;
		if(!pObject) continue;
		if(pObject->Object.ObjectType == 5)
		{
			if(pObject->AreaMiniMaps)
			{
				areas.Log(3, "Adding minimap to creature '%x'\n", pObject->Object.ObjectID);
				pObject->AreaMiniMaps = (void **) realloc(pObject->AreaMiniMaps, pModule->Areas.Count * 4);
				void *pMinimap = new char[0x80];
				memset(pMinimap, 0, 0x80);
				pObject->AreaMiniMaps[pModule->Areas.Count - 1] = pMinimap;
				CExoArrayList_unsigned_long___Add(&pObject->AreaList, nAreaID);
				pObject->AreaCount++;
				areas.Log(3, "Object area count: %d\n", pObject->AreaCount);
			}
		}
	}
}

void RemoveAreaForCreatures(CNWSModule *pModule, dword nAreaID)
{
	if(!pServThis) InitConstants();
	CGameObjectArray *pGameObjArray = CServerExoApp__GetObjectArray((void *)pServThis);
	
	areas.Log(3, "Area count: %d\n", pModule->Areas.Count);
	if(!pGameObjArray) return;
	for(int i=0; i<=0xFFF; i++)
	{
		CGameObjectArrayElement **pObjects = pGameObjArray->Objects;
		CGameObjectArrayElement *pElement = pObjects[i];
		if(!pElement) continue;
		CNWSCreature *pObject = (CNWSCreature *) pElement->Object;
		if(!pObject) continue;
		if(pObject->Object.ObjectType == 5)
		{
			if(pObject->AreaMiniMaps)
			{
				areas.Log(3, "Removing minimaps for creature '%x'\n", pObject->Object.ObjectID);
				//TODO: cleanup minimap data
				/*int nIndex = CExoArrayList_unsigned_long___IndexOf(&pObject->AreaList, nAreaID);
				if(nIndex!=-1)
				{
					free(pObject->AreaMiniMaps[nIndex]);
				}*/
				pObject->AreaMiniMaps = (void **) realloc(pObject->AreaMiniMaps, pModule->Areas.Count * 4);
				CExoArrayList_unsigned_long___Remove(&pObject->AreaList, nAreaID);
				pObject->AreaCount--;
				areas.Log(3, "Object area count: %d\n", pObject->AreaCount);
			}
		}
	}
}

void UpdateAreasForDMs()
{
	if(!pServThis) InitConstants();
	void *pMessage = pGetServerMessage((void *)pServThis);
	CExoLinkedList *pPlayerList = pGetPlayerList((void *)pServThis);
	CExoLinkedListElement *pElement = pPlayerList->GetHeadPos();
	while(pElement)
	{
		void *pPlayer = pPlayerList->GetAtPos(pElement);
		if(pPlayer) SendServerToPlayerDungeonMasterAreaList(pMessage, pPlayer);
		pElement = pPlayerList->GetNext(pElement);
	}
}

void NWNXCreateArea(void *pModule, char *sResRef)
{
	CResRef res;
	CResRef____as(&res, sResRef);
	void *pArea = malloc(0x210);
	areas.Log(0, "Creating area '%s'\n", sResRef);
	CNWSArea__CNWSArea(pArea, res, 0, OBJECT_INVALID);
	areas.Log(0, "Loading area '%s'\n", sResRef);
	CNWSArea__LoadArea(pArea, 0);
	dword nAreaID = *((dword *)pArea+0x32);
	areas.Log(0, "AreaID=%08lX\n", nAreaID);
	void *pArray = ((dword *)pModule+0x7);
	CExoArrayList__Add(pArray, nAreaID);
	areas.nLastAreaID = nAreaID;
	AddAreaToCreatures((CNWSModule *)pModule, nAreaID);
	UpdateAreasForDMs();
}

void NWNXDestroyArea(void *pModule, dword nAreaID)
{
	if(!nAreaID || nAreaID == OBJECT_INVALID)
		return;
	if(!pServInternal)
		InitConstants();
	areas.Log(2, "Unregistering area %08lX\n", nAreaID);
	void *pArray = ((dword *)pModule+0x7);
	CExoArrayList__Remove(pArray, nAreaID);
	areas.Log(0, "Destroying area %08lX\n", nAreaID);
	CNWSArea *pArea = (CNWSArea *) GetAreaByGameObjectID((void *)pServInternal, nAreaID);
	if(pArea->NumPlayers > 0)
	{
		areas.Log(1, "NumPlayers > 0, aborting\n");
		return;
	}
	CNWSArea__Destructor(pArea, 3);
	RemoveAreaForCreatures((CNWSModule *)pModule, nAreaID);
	UpdateAreasForDMs();
}

void NWNXSetAreaName(CNWSArea *pArea, char *sNewName)
{
	areas.Log(3, "SetAreaName: %x, '%s'\n", pArea->GameObject.ObjectID, sNewName);
	CExoLocString *lsName = (CExoLocString *)&pArea->Name;
	if(!lsName) return;
	char *newstr = new char[strlen(sNewName)+1];
	strncpy(newstr, sNewName, strlen(sNewName));
	lsName->AddString(0, newstr);
	UpdateAreasForDMs();
}

int HookFunctions()
{
	ppServThis = 0x0832F1F4;
	pScriptThis = pServThis - 8;

	*(dword*)&CNWSArea__CNWSArea = 0x080CBD30;
	*(dword*)&CNWSArea__LoadArea = 0x080CDFDC;
	*(dword*)&CExoArrayList__Add = 0x0805EEE0;
	*(dword*)&CNWSArea__Destructor = 0x080CC244;
	*(dword*)&GetAreaByGameObjectID = 0x080B0484;
	*(dword*)&CExoArrayList__Remove = 0x0805EE88;
	*(dword*)&CServerExoApp__GetObjectArray = 0x080B1D84;
	*(dword*)&CExoArrayList_unsigned_long___Add = 0x0805EEE0;
	*(dword*)&CExoArrayList_unsigned_long___Remove = 0x0805EE88;
	*(dword*)&CExoArrayList_unsigned_long___IndexOf = 0x080986C4;

	*(dword*)&pGetPlayerList = 0x080B1F2C;  //CServerExoApp::GetPlayerList(void)
	*(dword*)&pGetServerMessage = 0x080B1F54;  //CServerExoApp::GetNWSMessage(void)
	*(dword*)&SendServerToPlayerDungeonMasterAreaList = 0x08075960;  //CNWSMessage::SendServerToPlayerDungeonMasterAreaList(CNWSPlayer *)

    areas.Log(0, "pServThis = %08lX\n", pServThis);

	return (ppServThis && pScriptThis);
}

void InitConstants()
{
	pServThis = *((*(dword**)ppServThis) + 1);
	pServInternal = *((dword*)pServThis + 1);
}

