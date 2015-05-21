/***************************************************************************
    Funcs Ext plugin for NWNX

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

#include "NWNXFuncsExt.h"
#include "FunctionHooks.h"

extern CNWNXFuncsExt funcsext;

void *pServerExo = 0;

//Functions:
//Return value: 0 upon success, 1 upon failure

//Return value: 1 upon success, 0 upon failure

void (*pSetScriptName_Creature)(CNWSCreature *pCreature, int nScript, CExoString *sScript);
CExoString *(*pGetScriptName_Creature)(CNWSCreature *pCreature, int nScript);

void (*pSetScriptName_Placeable)(CNWSPlaceable *pPlaceable, int nScript, CExoString *sScript);
CExoString *(*pGetScriptName_Placeable)(CNWSPlaceable *pPlaceable, int nScript);

void (*pSetScriptName_Module)(CNWSModule *pModule, int nScript, CExoString *sScript);
CExoString *(*pGetScriptName_Module)(void *pModule, int nScript);

void (*pSetScriptName_Area)(CNWSArea *pArea, int nScript, CExoString *sScript);
CExoString *(*pGetScriptName_Area)(CNWSArea *pArea, int nScript);

void (*pSetScriptName_Door)(CNWSDoor *pDoor, int nScript, CExoString *sScript);
CExoString *(*pGetScriptName_Door)(CNWSDoor *pDoor, int nScript);

void (*pSetScriptName_Store)(CNWSStore *pStore, int nScript, CExoString *sScript);
CExoString *(*pGetScriptName_Store)(CNWSStore *pStore, int nScript);

void (*pSetScriptName_Trigger)(CNWSTrigger *pTrigger, int nScript, CExoString *sScript);
CExoString *(*pGetScriptName_Trigger)(CNWSTrigger *pTrigger, int nScript);

void (*pSetScriptName_Encounter)(CNWSEncounter *pEncounter, int nScript, CExoString *sScript);
CExoString *(*pGetScriptName_Encounter)(CNWSEncounter *pEncounter, int nScript);

void (*pSetScriptName_AoE)(CNWSAreaOfEffectObject *pAoE, int nScript, CExoString *sScript);
CExoString *(*pGetScriptName_AoE)(CNWSAreaOfEffectObject *pAoE, int nScript);

//Constants:


CExoString *NewCExoString(char *str)
{
    CExoString *ret = (CExoString *) malloc(sizeof(CExoString));
    ret->text = strdup(str);
    ret->len = strlen(str) + 1;
    return ret;
}

void SetScriptName_Creature(CNWSCreature *pCreature, int nScript, CExoString *sScript)
{
    pSetScriptName_Creature(pCreature, nScript, sScript);
}

CExoString *GetScriptName_Creature(CNWSCreature *pCreature, int nScript)
{
    return pGetScriptName_Creature(pCreature, nScript);
}

void SetScriptName_Placeable(CNWSPlaceable *pPlaceable, int nScript, CExoString *sScript)
{
    pSetScriptName_Placeable(pPlaceable, nScript, sScript);
}

CExoString *GetScriptName_Placeable(CNWSPlaceable *pPlaceable, int nScript)
{
    return pGetScriptName_Placeable(pPlaceable, nScript);
}

void SetScriptName_Module(CNWSModule *pModule, int nScript, CExoString *sScript)
{
    pSetScriptName_Module(pModule, nScript, sScript);
}

CExoString *GetScriptName_Module(CNWSModule *pModule, int nScript)
{
    return pGetScriptName_Module(pModule, nScript);
}

void SetScriptName_Area(CNWSArea *pArea, int nScript, CExoString *sScript)
{
    pSetScriptName_Area(pArea, nScript, sScript);
}

CExoString *GetScriptName_Area(CNWSArea *pArea, int nScript)
{
    return pGetScriptName_Area(pArea, nScript);
}

void SetScriptName_Door(CNWSDoor *pDoor, int nScript, CExoString *sScript)
{
    pSetScriptName_Door(pDoor, nScript, sScript);
}

CExoString *GetScriptName_Door(CNWSDoor *pDoor, int nScript)
{
    return pGetScriptName_Door(pDoor, nScript);
}

void SetScriptName_Store(CNWSStore *pStore, int nScript, CExoString *sScript)
{
    pSetScriptName_Store(pStore, nScript, sScript);
}

CExoString *GetScriptName_Store(CNWSStore *pStore, int nScript)
{
    return pGetScriptName_Store(pStore, nScript);
}

void SetScriptName_Trigger(CNWSTrigger *pTrigger, int nScript, CExoString *sScript)
{
    pSetScriptName_Trigger(pTrigger, nScript, sScript);
}

CExoString *GetScriptName_Trigger(CNWSTrigger *pTrigger, int nScript)
{
    return pGetScriptName_Trigger(pTrigger, nScript);
}

void SetScriptName_Encounter(CNWSEncounter *pEncounter, int nScript, CExoString *sScript)
{
    pSetScriptName_Encounter(pEncounter, nScript, sScript);
}

CExoString *GetScriptName_Encounter(CNWSEncounter *pEncounter, int nScript)
{
    return pGetScriptName_Encounter(pEncounter, nScript);
}


void (*pSetIsTrap)(CNWSTrigger *pTrigger, int flag);
void (*pSetIsAreaTransition)(CNWSTrigger *pTrigger, int flag);

void SetIsGenericTrigger(CNWSTrigger *pTrigger)
{
    pSetIsTrap(pTrigger, 0);
    pSetIsAreaTransition(pTrigger, 0);
}

void SetIsAreaTransition(CNWSTrigger *pTrigger)
{
    pSetIsTrap(pTrigger, 0);
    pSetIsAreaTransition(pTrigger, 1);
}

int (*pGetSurfaceMaterial)(CNWSArea *, Vector);

int GetSurfaceMaterial(CNWSArea *pArea, Vector vec)
{
    return pGetSurfaceMaterial(pArea, vec);
}

void (*pSetOpenState)(CNWSDoor *, byte);
void SetOpenState(CNWSDoor *pDoor, byte state)
{
    pSetOpenState(pDoor, state);
}

int (*pGetAnimation)(CNWSObject *);

int GetAnimation(CNWSObject *pObject)
{
    return pGetAnimation(pObject);
}


void (*pSetIsMapNote)(CNWSWaypoint *, int);
int (*pGetIsMapNote)(CNWSWaypoint *);
void (*pSetMapNoteString)(CNWSWaypoint *, CExoLocString *);
CExoLocString *(*pGetMapNoteString)(CNWSWaypoint *);

void (*pStartGuiTimingBar)(CNWSCreature *, dword, byte);
void (*pStopGuiTimingBar)(CNWSCreature *);

void StartGuiTimingBar(CNWSCreature *pCreature, dword time)
{
    pStartGuiTimingBar(pCreature, time, 10);
}

void StopGuiTimingBar(CNWSCreature *pCreature)
{
    pStopGuiTimingBar(pCreature);
}

void (*pPossessCreature)(CNWSCreature *, dword);
void (*pUnpossessCreature)(CNWSCreature *);

void PossessCreature(CNWSCreature *pCreature, dword pToPossess)
{
    pPossessCreature(pCreature, pToPossess);
}

void UnpossessCreature(CNWSCreature *pCreature)
{
    pUnpossessCreature(pCreature);
}

void (*pRemoveGold)(CNWSCreature *, int, int);
void (*pRemoveItem)(CNWSCreature *, CNWSItem *, int, int, int, int);

void RemoveGold(CNWSCreature *pCreature, int gold)
{
    pRemoveGold(pCreature, gold, 0);
}

void RemoveItem(CNWSCreature *pCreature, CNWSItem *pItem)
{
    pRemoveItem(pCreature, pItem, 0, 1, 0, 0);
}

CNWSMessage *(*pGetNWSMessage)(CServerExoApp *);

CNWSMessage *GetNWSMessage()
{
    CServerExoApp *pServerExo = (*NWN_AppManager)->app_server;
    if (pServerExo == NULL)
        return NULL;
    return pGetNWSMessage(pServerExo);
}

void (*pSendServerToPlayerArea_VisualEffect)(CNWSMessage *, CNWSPlayer *, word, Vector);

void SendServerToPlayerArea_VisualEffect(CNWSMessage *pMessage, CNWSPlayer *pPlayer, word vfx, Vector vec)
{
    pSendServerToPlayerArea_VisualEffect(pMessage, pPlayer, vfx, vec);
}

void (*pClearScripts)(CNWSCreature *, int);
void (*pResetClearedScripts)(CNWSCreature *, int);

void ClearScripts(CNWSCreature *pCreature, int flag)
{

}

void ResetClearedScripts(CNWSCreature *pCreature, int flag)
{

}

float(*pGetMovementRateFactor)(CNWSCreature *);

float GetMovementRateFactor(CNWSCreature *pCreature)
{
    return pGetMovementRateFactor(pCreature);
}

int (*pGetFlatFooted)(CNWSCreature *);

int GetFlatFooted(CNWSCreature *pCreature)
{
    return pGetFlatFooted(pCreature);
}


int FindFunctions()
{
    *(dword*)&pSetScriptName_Creature = 0x0813d720;
    funcsext.Log(2, "SetScriptName_Creature: %08lX\n", pSetScriptName_Creature);
    *(dword*)&pGetScriptName_Creature = 0x0813d704;
    funcsext.Log(2, "GetScriptName_Creature: %08lX\n", pGetScriptName_Creature);

    *(dword*)&pSetScriptName_Placeable = 0x081e23e4;
    funcsext.Log(2, "SetScriptName_Placeable: %08lX\n", pSetScriptName_Placeable);
    *(dword*)&pGetScriptName_Placeable = 0x081e23c8;
    funcsext.Log(2, "GetScriptName_Placeable: %08lX\n", pGetScriptName_Placeable);

    *(dword*)&pSetScriptName_Module = 0x081c106c;
    funcsext.Log(2, "SetScriptName_Module: %08lX\n", pSetScriptName_Module);
    *(dword*)&pGetScriptName_Module = 0x081c1050;
    funcsext.Log(2, "GetScriptName_Module: %08lX\n", pGetScriptName_Module);

    *(dword*)&pSetScriptName_Area = 0x080d55e8;
    funcsext.Log(2, "SetScriptName_Area: %08lX\n", pSetScriptName_Area);
    *(dword*)&pGetScriptName_Area = 0x080d55cc;
    funcsext.Log(2, "GetScriptName_Area: %08lX\n", pGetScriptName_Area);

    *(dword*)&pSetScriptName_Door = 0x0816af58;
    funcsext.Log(2, "SetScriptName_Door: %08lX\n", pSetScriptName_Door);
    *(dword*)&pGetScriptName_Door = 0x0816afb8;
    funcsext.Log(2, "GetScriptName_Door: %08lX\n", pGetScriptName_Door);

    *(dword*)&pSetScriptName_Store = 0x0808614c;
    funcsext.Log(2, "SetScriptName_Store: %08lX\n", pSetScriptName_Store);
    *(dword*)&pGetScriptName_Store = 0x080861b4;
    funcsext.Log(2, "GetScriptName_Store: %08lX\n", pGetScriptName_Store);

    *(dword*)&pSetScriptName_Trigger = 0x081f2df4;
    funcsext.Log(2, "SetScriptName_Trigger: %08lX\n", pSetScriptName_Trigger);
    *(dword*)&pGetScriptName_Trigger = 0x081f2cdc;
    funcsext.Log(2, "GetScriptName_Trigger: %08lX\n", pGetScriptName_Trigger);

    *(dword*)&pSetScriptName_Encounter = 0x081845e4;
    funcsext.Log(2, "SetScriptName_Encounter: %08lX\n", pSetScriptName_Encounter);
    *(dword*)&pGetScriptName_Encounter = 0x081845c8;
    funcsext.Log(2, "GetScriptName_Encounter: %08lX\n", pGetScriptName_Encounter);


    *(dword*)&pSetIsTrap = 0x081f3078;
    *(dword*)&pSetIsAreaTransition = 0x081f2e5c;

    *(dword*)&pGetSurfaceMaterial = 0x080d528c;

    *(dword*)&pSetOpenState = 0x0816a5b8;

    *(dword*)&pGetAnimation = 0x081d588c; // CNWSObject

    *(dword*)&pSetIsMapNote = 0x081f5224; //NWNSWaypoint, int
    *(dword*)&pGetIsMapNote = 0x081f5238; //NWNSWaypoint
    *(dword*)&pSetMapNoteString = 0x081f526c; //NWNSWaypoint, ExoLocString
    *(dword*)&pGetMapNoteString = 0x081f526c; //NWNSWaypoint, ExoLocString

    *(dword*)&pStartGuiTimingBar = 0x0813d1a0; // CNWSCreature, unsigned long, unsigned char
    *(dword*)&pStopGuiTimingBar = 0x0813d224; // void

    *(dword*)&pPossessCreature = 0x0810e658; // CNWSCreature, unsigned long
    *(dword*)&pUnpossessCreature = 0x0810e83c; // CNWSCreature

    *(dword*)&pRemoveGold = 0x081318a0; // CNWSCreature, int, int
    *(dword*)&pRemoveItem = 0x081000e8; // CNWSCreature, CNWSItem, int, int, int, int

    *(dword*)&pGetNWSMessage = 0x080b1f54;
    *(dword*)&pSendServerToPlayerArea_VisualEffect = 0x08065590;

    *(dword*)&pClearScripts = 0x0810e920;
    *(dword*)&pResetClearedScripts = 0x0810f198;

    *(dword*)&pGetMovementRateFactor = 0x08123FD8;

    *(dword*)&pGetFlatFooted = 0x080f1830;

    funcsext.Log(2, "All functions set\n");
    return true;
}
