/***************************************************************************
    NWNXFunction.h - Interface for the CNWNXFunction class.
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

#ifndef NWNXFunction_h_
#define NWNXFunction_h_

#include "NWNXBase.h"
#include "typedefs.h"
#include "NWNStructures.h"
#include "C2DA.h"
#include "CNWSScriptVarTable.h"
#include "CExoLocString.h"

class CNWNXFunction : public CNWNXBase
{
public:
    CNWNXFunction();
    virtual ~CNWNXFunction();

    bool OnCreate(gline *nwnxConfig, const char *LogDir = NULL);
    char* OnRequest(char* gameObject, char* Request, char* Parameters);
    unsigned long OnRequestObject(char *gameObject, char* Request);
    bool bHooked;

    //bool OnRelease ();

protected:
    void SetGoldPieceValue(char* value);
    void SetTag(char* value);
    void SetArmorAC(char* value);
    void GetArmorAC(char* value);
    void SetRacialType(char* value);
    void GetDescriptionLength(char* value);
    char *GetDescription(char* value);
    void SetDescription(char* value);
    void GetConversation(char *value);
    void GetUndroppable(char* value);
    void SetUndroppable(char* value);
    void GetItemWeight(char *value);
    void SetItemWeight(char *value);
    void GetEventHandler(char* value);
    void SetEventHandler(char* value);
    void GetFactionID(char* value);
    void SetFactionID(char* value);
    char *GetGroundHeight(char *value);
    void GetIsWalkableHL(char *value);
    void ChangeBackgroundMusicForPlayer(char *value);
    void Set2DAString(char* value);
    void SetMovementRate(char* value);
    void ActUseItem(char* value);
    void GetPCPort(char* value);
    void BootPC(char* value);
    void ActJumpToLimbo(char* value);
    char *GetFirstLocalVariable(char* value);
    char *GetNextLocalVariable(char* value);
    void GetItemCount_Ext(char* value);
    void GetItemByPosition_SetPos(char* value);
    void SetELC(char* value);
    void SetILR(char* value);
    void IntToObject(char* value);
    void DebugMe(char* value);
    void ObjDump(char* value);

    //unsigned long GetObjectByID();
    unsigned long GetFirstArea();
    unsigned long GetNextArea();
    unsigned long GetItemByPosition_Ext();
    unsigned long IntToObject_ret();

private:
    char* pGameObject;
    dword nCurrentAreaNum;
    dword nTotalAreaCount;
    int nCurrentVarNum;
    dword nItemPosition;
    dword nTempObjectID;
};

#endif
