/***************************************************************************
    NWNXFuncsExt.cpp - Implementation of the CNWNXFuncsExt class.

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

#include "NWNXFuncsExt.h"
#include "FunctionHooks.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNWNXFuncsExt::CNWNXFuncsExt()
{
    confKey = strdup("FUNCSEXT");
}

CNWNXFuncsExt::~CNWNXFuncsExt()
{
}

void CNWNXFuncsExt::SetScript(CGameObject *ob, char* value)
{
    if (ob == NULL) {
        snprintf(value, strlen(value), "-");
        return;
    }
    char *scriptname = (char *)malloc(strlen(value));
    int event_id;
    if (sscanf(value, "%i:%s", &event_id, scriptname) < 2 || strspn(scriptname, "abcdefghijklmnopqrstuvwxyz0123456789_") != strlen(scriptname)) {
        snprintf(value, strlen(value), "-");
        return;
    }

    CExoString *sNewScript = NewCExoString(scriptname);
    if (ob->type == 5 && !(event_id < 0 || event_id > 12)) {
        SetScriptName_Creature(ob->vtable->AsNWSCreature(ob), event_id, sNewScript);
    } else if (ob->type == 9 && !(event_id < 0 || event_id > 15 || event_id == 3 || event_id == 10 || event_id == 14)) {
        SetScriptName_Placeable(ob->vtable->AsNWSPlaceable(ob), event_id, sNewScript);
    } else if (ob->type == 3 && !(event_id < 0 || event_id > 17 || event_id == 3)) {
        SetScriptName_Module(ob->vtable->AsNWSModule(ob), event_id, sNewScript);
    } else if (ob->type == 4 && !(event_id < 0 || event_id > 3)) {
        SetScriptName_Area(ob->vtable->AsNWSArea(ob), event_id, sNewScript);
    } else if (ob->type == 10 && !(event_id < 0 || event_id > 14 || event_id == 4 || event_id == 9 || event_id == 13)) {
        SetScriptName_Door(ob->vtable->AsNWSDoor(ob), event_id, sNewScript);
    } else if (ob->type == 14 && !(event_id < 0 || event_id > 1)) {
        SetScriptName_Store(ob->vtable->AsNWSStore(ob), event_id, sNewScript);
    } else if (ob->type == 7 && !(event_id < 0 || event_id > 6 || event_id == 4 || event_id == 5)) {
        SetScriptName_Trigger(ob->vtable->AsNWSTrigger(ob), event_id, sNewScript);
    } else if (ob->type == 13 && !(event_id < 0 || event_id > 4)) {
        SetScriptName_Encounter(ob->vtable->AsNWSEncounter(ob), event_id, sNewScript);
    } else {
        snprintf(value, strlen(value), "1");
        return;
    }
    value[0] = 0;
}

void CNWNXFuncsExt::GetScript(CGameObject *ob, char* value)
{
    if (ob == NULL) {
        snprintf(value, strlen(value), "-");
        return;
    }
    int event_id = atoi(value);
    int length = strlen(value);

    CExoString *sScript;
    //printf("ObjectType: %d\n", ob->type);
    if (ob->type == 5 && !(event_id < 0 || event_id > 12)) {
        sScript = GetScriptName_Creature(ob->vtable->AsNWSCreature(ob), event_id);
    } else if (ob->type == 9 && !(event_id < 0 || event_id > 15 || event_id == 3 || event_id == 10 || event_id == 14)) {
        sScript = GetScriptName_Placeable(ob->vtable->AsNWSPlaceable(ob), event_id);
    } else if (ob->type == 3 && !(event_id < 0 || event_id > 17 || event_id == 3)) {
        sScript = GetScriptName_Module(ob->vtable->AsNWSModule(ob), event_id);
    } else if (ob->type == 4 && !(event_id < 0 || event_id > 3)) {
        sScript = GetScriptName_Area(ob->vtable->AsNWSArea(ob), event_id);
    } else if (ob->type == 10 && !(event_id < 0 || event_id > 14 || event_id == 4 || event_id == 9 || event_id == 13)) {
        sScript = GetScriptName_Door(ob->vtable->AsNWSDoor(ob), event_id);
    } else if (ob->type == 14 && !(event_id < 0 || event_id > 1)) {
        sScript = GetScriptName_Store(ob->vtable->AsNWSStore(ob), event_id);
    } else if (ob->type == 7 && !(event_id < 0 || event_id > 6 || event_id == 4 || event_id == 5)) {
        sScript = GetScriptName_Trigger(ob->vtable->AsNWSTrigger(ob), event_id);
    } else if (ob->type == 13 && !(event_id < 0 || event_id > 4)) {
        sScript = GetScriptName_Encounter(ob->vtable->AsNWSEncounter(ob), event_id);
    }

    if (sScript->text == NULL) {
        snprintf(value, strlen(value), "-");
        return;
    }

    char *script = sScript->text;
    int iScriptLen = strlen(script);

    if (iScriptLen < length) {
        strncpy(value, script, iScriptLen);
        *(value + iScriptLen) = 0x0;
    } else {
        strncpy(value, script, length);
        *(value + length) = 0x0;
    }
}

void CNWNXFuncsExt::Set_IsGenericTrigger(CGameObject *ob, char* value)
{
    if (ob == NULL) {
        snprintf(value, strlen(value), "0");
        return;
    }
    if (ob->type != 7) {
        snprintf(value, strlen(value), "0");
        return;
    }

    SetIsGenericTrigger(ob->vtable->AsNWSTrigger(ob));
    value[0] = 0;
}

void CNWNXFuncsExt::Set_IsAreaTransition(CGameObject *ob, char* value)
{
    if (ob == NULL) {
        snprintf(value, strlen(value), "0");
        return;
    }
    if (ob->type != 7) {
        snprintf(value, strlen(value), "0");
        return;
    }

    SetIsAreaTransition(ob->vtable->AsNWSTrigger(ob));
    value[0] = 0;
}

void CNWNXFuncsExt::Get_SurfaceMaterial(CGameObject *ob, char* value)
{
    if (ob == NULL) {
        snprintf(value, strlen(value), "-1");
        return;
    }
    if (ob->type != 4) {
        snprintf(value, strlen(value), "-1");
        return;
    }

    CNWSArea *pArea;
    Vector vec;

    if ((pArea = ob->vtable->AsNWSArea(ob)) == NULL || sscanf(value, "%f¬%f¬%f", &(vec.x), &(vec.y), &(vec.z)) != 3) {
        snprintf(value, strlen(value), "-1");
        return;
    }

    snprintf(value, strlen(value), "%d", GetSurfaceMaterial(pArea, vec));
}

void CNWNXFuncsExt::Get_Animation(CGameObject *ob, char* value)
{
    CNWSObject *pObject;

    if (ob == NULL || (pObject = ob->vtable->AsNWSObject(ob)) == NULL) {
        snprintf(value, strlen(value), "-1");
        return;
    }

    sprintf(value, "%d", GetAnimation(pObject));
}

void CNWNXFuncsExt::Start_GuiTimingBar(CGameObject *ob, char* value)
{
    CNWSCreature *pCreature;
    dword time;

    if (ob == NULL || (pCreature = ob->vtable->AsNWSCreature(ob)) == NULL || (time = atoi(value)) <= 0) {
        snprintf(value, strlen(value), "0");
        return;
    }
    StartGuiTimingBar(pCreature, time);
    snprintf(value, strlen(value), "1");
}

void CNWNXFuncsExt::Stop_GuiTimingBar(CGameObject *ob, char* value)
{
    CNWSCreature *pCreature;

    if (ob == NULL || (pCreature = ob->vtable->AsNWSCreature(ob)) == NULL) {
        snprintf(value, strlen(value), "0");
        return;
    }
    StopGuiTimingBar(pCreature);
    snprintf(value, strlen(value), "1");
}

void CNWNXFuncsExt::Possess_Creature(CGameObject *ob, char* value)
{
    CNWSCreature *pCreature;

    if (ob == NULL || (pCreature = ob->vtable->AsNWSCreature(ob)) == NULL) {
        snprintf(value, strlen(value), "-1");
        return;
    }

    PossessCreature(pCreature, strtol(value, NULL, 16));
}

void CNWNXFuncsExt::Unpossess_Creature(CGameObject *ob, char* value)
{
    CNWSCreature *pCreature;

    if (ob == NULL || (pCreature = ob->vtable->AsNWSCreature(ob)) == NULL) {
        snprintf(value, strlen(value), "-1");
        return;
    }

    UnpossessCreature(pCreature);
}

void CNWNXFuncsExt::Remove_Gold(CGameObject *ob, char* value)
{
    CNWSCreature *pCreature;
    int gold;

    if (ob == NULL || (pCreature = ob->vtable->AsNWSCreature(ob)) == NULL || (gold = atoi(value)) < 1) {
        snprintf(value, strlen(value), "0");
        return;
    }
    RemoveGold(pCreature, gold);
    snprintf(value, strlen(value), "-1");
}

void CNWNXFuncsExt::Remove_Item(CGameObject *ob, char* value)
{
    CNWSCreature *pCreature;
    CNWSItem *pItem;
    nwn_objid_t obj;

    if (ob == NULL || (pCreature = ob->vtable->AsNWSCreature(ob)) == NULL || sscanf(value, "%x", &(obj)) != 1) {
        snprintf(value, strlen(value), "0");
        return;
    }

    CGameObject *oItem = nwn_GetObjectByID(obj);
    if (oItem == NULL || (pItem = oItem->vtable->AsNWSItem(oItem)) == NULL) {
        snprintf(value, strlen(value), "0");
        return;
    }
    RemoveItem(pCreature, pItem);
}

void CNWNXFuncsExt::ApplyArea_VFX(CGameObject *ob, char* value)
{
    CNWSPlayer *pPlayer;
    int vfx;
    Vector vec;
    nwn_objid_t target;

    if (sscanf(value, "%x¬%d¬%f¬%f¬%f", &(target), &(vfx), &(vec.x), &(vec.y), &(vec.z)) != 5 || (pPlayer = nwn_GetPlayerByID(target)) == NULL) {
        snprintf(value, strlen(value), "0");
        return;
    }

    CNWSMessage *pMessage = GetNWSMessage();
    if (pMessage != NULL) {
        SendServerToPlayerArea_VisualEffect(pMessage, pPlayer, (word)vfx, vec);
    }

    snprintf(value, strlen(value), "1");
}

void CNWNXFuncsExt::Get_FlatFooted(CGameObject *ob, char* value)
{
    CNWSCreature *pCreature;

    if (ob == NULL || (pCreature = ob->vtable->AsNWSCreature(ob)) == NULL) {
        snprintf(value, strlen(value), "-1");
        return;
    }

    snprintf(value, strlen(value), "%d", GetFlatFooted(pCreature));
}

bool CNWNXFuncsExt::OnCreate(gline *config, const char *LogDir)
{
    char log[128];
    sprintf(log, "%s/nwnx_fnext.txt", LogDir);

    // call the base class function
    if (!CNWNXBase::OnCreate(config, log))
        return false;
    Log(0, "NWNX Funcs Ext V.0.2.6.TESTING by pZv!, 2009\n");
    Log(0, "Based on NWNX Functions V.1.9.1 (c) by virusman, 2006-2009\n");
    Log(0, "visit http://www.nwnx.org\n\n");
    Log(0, "* Module loaded successfully.\n");

    FindFunctions();

    return true;
}

char* CNWNXFuncsExt::OnRequest(char *gameObject, char* Request, char* Parameters)
{
    this->pGameObject = gameObject + 4;

    Log(2, "(S) Request: \"%s\"\n", Request);
    Log(3, "(S) Params:  \"%s\"\n", Parameters);

    if (strncmp(Request, "SETSCRIPT", 9) == 0) {
        SetScript((CGameObject *)gameObject, Parameters);
        return NULL;
    } else if (strncmp(Request, "GETSCRIPT", 9) == 0) {
        GetScript((CGameObject *)gameObject, Parameters);
        return NULL;
    } else if (strncmp(Request, "SETISGENERICTRIGGER", 19) == 0) {
        Set_IsGenericTrigger((CGameObject *)gameObject, Parameters);
        return NULL;
    } else if (strncmp(Request, "SETISAREATRANSITION", 19) == 0) {
        Set_IsAreaTransition((CGameObject *)gameObject, Parameters);
        return NULL;
    } else if (strncmp(Request, "GETSURFACE", 10) == 0) {
        Get_SurfaceMaterial((CGameObject *)gameObject, Parameters);
        return NULL;
    } else if (strncmp(Request, "GETANIMATION", 12) == 0) {
        Get_Animation((CGameObject *)gameObject, Parameters);
        return NULL;
    } else if (strncmp(Request, "PRINT", 5) == 0) {
        printf("%s\n", Parameters);
        return NULL;
    } else if (strncmp(Request, "STARTTIMINGBAR", 14) == 0) {
        Start_GuiTimingBar((CGameObject *)gameObject, Parameters);
        return NULL;
    } else if (strncmp(Request, "STOPTIMINGBAR", 13) == 0) {
        Stop_GuiTimingBar((CGameObject *)gameObject, Parameters);
        return NULL;
    } else if (strncmp(Request, "POSSESS", 7) == 0) {
        Possess_Creature((CGameObject *)gameObject, Parameters);
        return NULL;
    } else if (strncmp(Request, "UNPOSSESS", 9) == 0) {
        Unpossess_Creature((CGameObject *)gameObject, Parameters);
        return NULL;
    } else if (strncmp(Request, "REMOVEGOLD", 10) == 0) {
        Remove_Gold((CGameObject *)gameObject, Parameters);
        return NULL;
    } else if (strncmp(Request, "REMOVEITEM", 10) == 0) {
        Remove_Item((CGameObject *)gameObject, Parameters);
        return NULL;
    } else if (strncmp(Request, "AREAVFX4PC", 10) == 0) {
        ApplyArea_VFX((CGameObject *)gameObject, Parameters);
        return NULL;
    } else if (strncmp(Request, "GETFLATFOOTED", 13) == 0) {
        Get_FlatFooted((CGameObject *)gameObject, Parameters);
        return NULL;
    }

    return NULL;
}

unsigned long CNWNXFuncsExt::OnRequestObject(char *gameObject, char* Request)
{
    this->pGameObject = gameObject + 4;

    Log(2, "(O) Request: \"%s\"\n", Request);

    return OBJECT_INVALID;
}

