/*
 *  NWNeXalt - Empty File
 *  (c) 2007 Doug Swarin (zac@intertex.net)
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *  $Id$
 *  $HeadURL$
 *
 */

#include "NWNXLib.h"

CGameObject *nwn_GetObjectByID(nwn_objid_t oid)
{
    CGameObject *ob = NULL;

    CGameObjectArray__GetGameObject((*NWN_AppManager)->app_server->srv_internal->srv_objects, oid, &ob);
    return ob;
}


CGameObject *nwn_GetObjectByStringID(const char *oid)
{
    return nwn_GetObjectByID(strtoul(oid, NULL, 16));
}


CNWSPlayer *nwn_GetPlayerByID(nwn_objid_t oid)
{
    return CServerExoApp__GetClientObjectByObjectId((*NWN_AppManager)->app_server, oid);
}


bool nwn_GetKnowsFeat(const CNWSCreatureStats *stats, int feat)
{
    return CExoArrayList_uint16_contains(&(stats->cs_feats), feat);
}


int nwn_GetKnowsSkill(const CNWSCreatureStats *stats, int skill)
{
    if (skill >= 0 && skill <= SKILL_LAST)
        skill = stats->cs_skills[skill];

    return 0;
}


int nwn_GetLevelByClass(const CNWSCreatureStats *stats, int cl)
{
    int i;

    for (i = 0; i < stats->cs_classes_len; i++) {
        if (stats->cs_classes[i].cl_class == cl)
            return stats->cs_classes[i].cl_level;
    }

    return 0;
}


CNWLevelStats *nwn_GetLevelStats(const CNWSCreatureStats *stats, int level)
{
    if (level < 1 || level > stats->cs_levelstat.len)
        return NULL;

    return stats->cs_levelstat.data[level - 1];
}


int64_t nwn_GetWorldTime(uint32_t *time_2880s, uint32_t *time_msec)
{
    int64_t ret;
    uint32_t a, b;

    if (time_2880s == NULL)
        time_2880s = &a;
    if (time_msec == NULL)
        time_msec = &b;

    CWorldTimer__GetWorldTime((*NWN_AppManager)->app_server->srv_internal->srv_time_world, time_2880s, time_msec);

    ret = *time_2880s;

    return ((ret * 2880000LL) + *time_msec);
}


void nwn_UpdateQuickBar(CNWSCreature *cre)
{
    CNWSPlayer *pl;

    if ((pl = nwn_GetPlayerByID(cre->obj.obj_id)) == NULL)
        return;

    CNWSMessage__SendServerToPlayerGuiQuickbar_SetButton(
        (*NWN_AppManager)->app_server->srv_internal->srv_client_messages, pl, 0, 1);
}


void nwn_ExecuteScript(const char *scr, nwn_objid_t oid)
{
    CExoString run;

    run.text = (char *)scr;
    run.len  = strlen(scr);

    CVirtualMachine__RunScript(*NWN_VirtualMachine, &run, oid, 1);
}


/* vim: set sw=4: */
