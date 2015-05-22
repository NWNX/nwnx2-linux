/***************************************************************************
    Functions plugin for NWNX - hooks interface
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

#ifndef FunctionHooks_h_
#define FunctionHooks_h_

#include "typedefs.h"
#include "C2DA.h"
#include "CNWSScriptVarTable.h"
#include "CItemRepository.h"

CServerExoApp *GetServerExoApp();
long GetOIDByObj(void *pObject);
int GetFaction(long ObjID, int *buf);
void SetFaction(long ObjID, int nFaction);
void *GetAreaByID(dword nAreaID);
float GetZCoordinate(void *pArea, float X, float Y, float Z);
int GetIsWalkable(void *pArea, float X, float Y, float Z);
void *GetModule();
void *GetPlayer(dword ObjID);
void *GetAreaAmbientSound(void *pArea);
dword GetObjectAreaID(void *pObject);
void SetCreatureMovementRate(void *pCreature, dword nMovementRateType);
C2DA *Get2DARes(char *s2DA);
void ActionUseItem(void *pCreature, dword oItem, dword oTarget, float X, float Y, float Z, dword nPropertyNum = 0);
dword GetPlayerPort(dword nPlayerID);
void DisconnectPlayer(dword nObjectID, dword nStringRef);
int JumpToLimbo(dword nObjectID);
CNWSScriptVar *GetLocalVarByPosition(void *pObject, int nNum);
dword GetItemCount(void *pObject);
dword GetItemByPosition(void *pObject, dword nPos);
void CNWSObject_SetTag(CNWSObject *oObject, CExoString *sNewTag);


CExoString *NewCExoString(char *str);
int FindFunctions();
void InitConstants();

#endif
