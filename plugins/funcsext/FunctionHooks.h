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

#ifndef FunctionHooks_h_
#define FunctionHooks_h_

#include "typedefs.h"

void SetScriptName_Creature(CNWSCreature *pCreature, int nScript, CExoString *sScript);
CExoString *GetScriptName_Creature(CNWSCreature *pCreature, int nScript);

void SetScriptName_Placeable(CNWSPlaceable *pPlaceable, int nScript, CExoString *sScript);
CExoString *GetScriptName_Placeable(CNWSPlaceable *pPlaceable, int nScript);

void SetScriptName_Module(CNWSModule *pModule, int nScript, CExoString *sScript);
CExoString *GetScriptName_Module(CNWSModule *pModule, int nScript);

void SetScriptName_Area(CNWSArea *pArea, int nScript, CExoString *sScript);
CExoString *GetScriptName_Area(CNWSArea *pArea, int nScript);

void SetScriptName_Door(CNWSDoor *pDoor, int nScript, CExoString *sScript);
CExoString *GetScriptName_Door(CNWSDoor *pDoor, int nScript);

void SetScriptName_Store(CNWSStore *pStore, int nScript, CExoString *sScript);
CExoString *GetScriptName_Store(CNWSStore *pStore, int nScript);

void SetScriptName_Trigger(CNWSTrigger *pTrigger, int nScript, CExoString *sScript);
CExoString *GetScriptName_Trigger(CNWSTrigger *pTrigger, int nScript);

void SetScriptName_Encounter(CNWSEncounter *pEncounter, int nScript, CExoString *sScript);
CExoString *GetScriptName_Encounter(CNWSEncounter *pEncounter, int nScript);


void SetIsGenericTrigger(CNWSTrigger *pTrigger);
void SetIsAreaTransition(CNWSTrigger *pTrigger);

int GetSurfaceMaterial(CNWSArea *pArea, Vector vec);

void SetOpenState(CNWSDoor *pDoor, byte state);

int GetAnimation(CNWSObject *pObject);

void StartGuiTimingBar(CNWSCreature *pCreature, dword time);
void StopGuiTimingBar(CNWSCreature *pCreature);

void PossessCreature(CNWSCreature *pCreature, dword pToPossess);
void UnpossessCreature(CNWSCreature *pCreature);

void RemoveGold(CNWSCreature *pCreature, int gold);
void RemoveItem(CNWSCreature *pCreature, CNWSItem *pItem);

CNWSMessage *GetNWSMessage();

void SendServerToPlayerArea_VisualEffect(CNWSMessage *pMessage, CNWSPlayer *pPlayer, word vfx, Vector vec);

void ClearScripts(CNWSCreature *pCreature, int flag);
void ResetClearedScripts(CNWSCreature *pCreature, int flag);

int SetNumberMemorizedSpellSlots(CNWSCreatureStats *pCreature, byte, byte, byte);

float GetMovementRateFactor(CNWSCreature *pCreature);

int GetFlatFooted(CNWSCreature *pCreature);

CExoString *NewCExoString(char *str);
int FindFunctions();

#endif
