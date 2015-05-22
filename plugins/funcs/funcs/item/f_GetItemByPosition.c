
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


static int Item_Position = -1;


void Func_GetItemByPositionRequest(CGameObject *ob, char *value)
{
    Item_Position = atoi(value);
}


nwn_objid_t Func_GetItemByPosition(CGameObject *ob)
{
    int i;
    CNWSCreature *cre;
    CExoLinkedListNode *node;

    if (ob == NULL                                    ||
            (cre = ob->vtable->AsNWSCreature(ob)) == NULL ||
            cre->cre_inventory == NULL                    ||
            Item_Position < 0                             ||
            Item_Position >= cre->cre_inventory->ir_list.header->len) {

        return OBJECT_INVALID;
    }

    node = cre->cre_inventory->ir_list.header->first;
    for (i = 0; i < Item_Position && node != NULL; i++)
        node = node->next;

    if (node == NULL || node->data == NULL)
        return OBJECT_INVALID;

    return *(nwn_objid_t *)(node->data);
}


/* vim: set sw=4: */
