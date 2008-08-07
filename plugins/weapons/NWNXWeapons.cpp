
/***************************************************************************
    NWNXWeapons.cpp - Implementation of the CNWNXWeapons class.
    Copyright (C) 2007 Doug Swarin (zac@intertex.net)

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

#include "NWNXWeapons.h"
#include "WeaponsStrCmds.h"
#include "WeaponsObjCmds.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNWNXWeapons::CNWNXWeapons() {
    confKey = "FUNCS";
}


CNWNXWeapons::~CNWNXWeapons() {
}


char *CNWNXWeapons::OnRequest (char *gameObject, char *Request, char *Parameters) {
    const struct WeaponsStrCommand_s *cmd;

    Log(1, "StrReq: \"%s\"\nParams: \"%s\"\n", Request, Parameters);

    if ((cmd = WeaponsStrCommandLookup(Request, strlen(Request))) != NULL)
        cmd->func((CGameObject *)gameObject, Parameters);
    else
        Log(0, "Unrecognized string request: \"%s\" \"%s\"\n", Request, Parameters);

    Log(1, "Return: \"%s\"\n", Parameters);

    return NULL;
}


unsigned long CNWNXWeapons::OnRequestObject (char *gameObject, char *Request) {
    unsigned long ret = OBJECT_INVALID;
    const struct WeaponsObjCommand_s *cmd;

    Log(1, "ObjReq: \"%s\"\n", Request);

    if ((cmd = WeaponsObjCommandLookup(Request, strlen(Request))) != NULL)
        ret = cmd->func((CGameObject *)gameObject);
    else
        Log(0, "Unrecognized object request: \"%s\"\n", Request);

    Log(1, "Return: %08X\n", ret);

    return ret;
}


bool CNWNXWeapons::OnCreate (gline *config, const char *LogDir) {
    char log[128];

    sprintf(log, "%s/nwnx_weapons.txt", LogDir);

    // call the base class function
    if (!CNWNXBase::OnCreate(config, log))
        return false;

    /* replace weapon focus feats */
    nx_hook_function((void *)CNWSCreatureStats__GetWeaponFocus,
        (void *)Hook_GetWeaponFocus, 5, NX_HOOK_DIRECT);
    nx_hook_function((void *)CNWSCreatureStats__GetEpicWeaponFocus,
        (void *)Hook_GetEpicWeaponFocus, 5, NX_HOOK_DIRECT);

    /* replace weapon specialization feats */
    nx_hook_function((void *)CNWSCreatureStats__GetWeaponSpecialization,
        (void *)Hook_GetWeaponSpecialization, 5, NX_HOOK_DIRECT);
    nx_hook_function((void *)CNWSCreatureStats__GetEpicWeaponSpecialization,
        (void *)Hook_GetEpicWeaponSpecialization, 5, NX_HOOK_DIRECT);

    /* replace critical hit feats */
    nx_hook_function((void *)CNWSCreatureStats__GetWeaponImprovedCritical,
        (void *)Hook_GetWeaponImprovedCritical, 5, NX_HOOK_DIRECT);
    nx_hook_function((void *)CNWSCreatureStats__GetEpicWeaponOverwhelmingCritical,
        (void *)Hook_GetEpicWeaponOverwhelmingCritical, 5, NX_HOOK_DIRECT);
    nx_hook_function((void *)CNWSCreatureStats__GetEpicWeaponDevastatingCritical,
        (void *)Hook_GetEpicWeaponDevastatingCritical, 5, NX_HOOK_DIRECT);

    /* replace Weapon of Choice feats */
    nx_hook_function((void *)CNWSCreatureStats__GetIsWeaponOfChoice,
        (void *)Hook_GetIsWeaponOfChoice, 5, NX_HOOK_DIRECT);

    /* replace weapon finesse and monk weapon checks */
    nx_hook_function((void *)CNWSCreatureStats__GetWeaponFinesse,
        (void *)Hook_GetWeaponFinesse, 5, NX_HOOK_DIRECT);
    nx_hook_function((void *)CNWSCreatureStats__GetUseMonkAttackTables,
        (void *)Hook_GetUseMonkAttackTables, 5, NX_HOOK_DIRECT);

    return true;
}

/* vim: set sw=4: */
