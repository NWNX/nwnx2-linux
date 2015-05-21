
/***************************************************************************
    NWNXFuncs.cpp - Implementation of the CNWNXFuncs class.
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

#include "NWNXFuncs.h"

static int GetPlayerPort(void *pNetLayer, uint32_t nPlayerID)
{
    int i;
    uint32_t nNum;
    void *pClientStruct, *pNetLayerInternal, *pExoNet, *pExoNetInternal;

    pNetLayerInternal = *(void **)pNetLayer;
    pExoNet = *(void **)((char*)pNetLayerInternal + 0x4);
    if (!pExoNet) return -1;
    pExoNetInternal = *(void **)pExoNet;
    if (!pExoNetInternal) return -2;

    /* Yes, this is ugly. But I don't want to describe 4 or 5 nested structures. :) */
    for (i = 0; i < 0x60; i++) {
        pClientStruct = (void *)((char *)pNetLayerInternal + 0xC + i * 0x91C);

        if (*(uint32_t *)((char*)pClientStruct + 0x8) == 1) {
            if (*(uint32_t *)((char*)pClientStruct + 0xC) == nPlayerID) {
                nNum = *(uint32_t *)((char*)pClientStruct + 0x14);
                uint8_t *pFlagList = *(uint8_t **)((char*)pExoNetInternal + 0x34);
                if (!pFlagList || !pFlagList[nNum]) return -3;

                char* pNetInfoBase = *(char**)((char*)pExoNetInternal + 0x3c);
                struct sockaddr_in *pIP = (struct sockaddr_in *)(pNetInfoBase + nNum * 16);
                if (!pIP) return -4;

                return pIP->sin_port;
            }
        }
    }
    return -5;
}

void Func_GetPCPort(CGameObject *ob, char *value)
{
    CNWSPlayer *pl;
    CNWSCreature *cre;

    if (ob == NULL || (cre = ob->vtable->AsNWSCreature(ob)) == NULL || !cre->cre_is_pc) {
        snprintf(value, strlen(value), "0");
        return;
    }

    pl = CServerExoApp__GetClientObjectByObjectId((*NWN_AppManager)->app_server, ob->id);
    if (pl == NULL) {
        snprintf(value, strlen(value), "0");
        return;
    }

    int port = GetPlayerPort((*NWN_AppManager)->app_server->srv_internal->srv_network, pl->pl_id);
    snprintf(value, strlen(value), "%d",
             port);

    /* TODO: describe all nested structures */
}


/* vim: set sw=4: */
