
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
#include <string.h>
#include <stdio.h>
#include "NWNXFuncs.h"


void Func_SetQuickBarSlot (CGameObject *ob, char *value) {
    int slot, qb_type, qb_class, qb_id, qb_meta, qb_objid1, qb_objid2;
    CNWSCreature *cre;
    int iLenValue = strlen(value);
    char *tok = value;
    char *params[7];
    char valuestr[iLenValue];
    
    if (ob == NULL                                    ||
        (cre = ob->vtable->AsNWSCreature(ob)) == NULL ||
        !cre->cre_is_pc                               ||
        cre->cre_quickbar == NULL) 
    {
        snprintf(value, iLenValue, "-1");
    }
    /* walk through other tokens */
    int i = 0;
    while ((tok = strtok(tok, "¬")) != NULL)
    {
        params[i] = tok;
        tok = NULL;
        i++;
    }
    if (i != 7)
    {
        snprintf(value, iLenValue, "-1");
        return;
    }
    int pos = 0;
    int n = 5;
    int k;
    for (k=0; k < n; k++) {
        pos += sprintf(&valuestr[pos], "%s ", params[k]);
    }
    int valuelen = strlen(valuestr);
    valuestr[valuelen - 1] = 0;
    
    // Special case for items
    if (strcmp(params[1],"1") == 0)
    {        
        if (sscanf(valuestr, "%d %d %x %d %x", &slot, &qb_type, &qb_objid1, &qb_id, &qb_objid2) != 5)
        {
            snprintf(value, iLenValue, "-1");
            return;
        }
    } 
    else 
    {
        if (sscanf(valuestr, "%d %d %d %d %d", &slot, &qb_type, &qb_class, &qb_id, &qb_meta) != 5)
        {
            snprintf(value, iLenValue, "-1");
            return;
        }
    }
    
    CNWSQuickbarButton *button = &cre->cre_quickbar[slot];
    
    //if quickslot contains strings, free their memory first
    switch (button->qb_type) {
        case 18: {
            free(button->qb_label.text); button->qb_label.text = NULL;
            button->qb_label.len = 0;
            free(button->qb_command.text); button->qb_command.text = NULL;
            button->qb_command.len = 0;
        } break;
        case 11: case 12: case 13: case 14: case 15: case 16: case 17: {
            free(button->qb_label2.text); button->qb_label2.text = NULL;
            button->qb_label2.len = 0;
        } break;
    }
    
    button->qb_objid1 = 0x7F000000;
    button->qb_objid2 = 0x7F000000;
    button->qb_class = 0;
    button->qb_id = 0;
    button->qb_metamagic = 0;

    // put the new data in
    switch (qb_type) {
        case 1: {
            button->qb_type      = qb_type;
            button->qb_id        = qb_id;
            button->qb_objid1    = qb_objid1;
            button->qb_objid2    = qb_objid2;
        } break;
            
        case 18: {
            if (strlen(params[5]) > 0 && strlen(params[6]) > 0) {
                button->qb_label.len = strlen(params[6])+1;
                button->qb_label.text = (char*)malloc(button->qb_label.len);
                sprintf(button->qb_label.text, "%s", params[6]);
                
                button->qb_command.len = strlen(params[5])+1;
                button->qb_command.text = (char*)malloc(button->qb_command.len);
                sprintf(button->qb_command.text, "%s", params[5]);
            }
            else {
                qb_type = 0;
                qb_class = 0;
                qb_id = 0;
                qb_meta = 0;
            }
        } break;
        case 11: case 12: case 13: case 14: case 15: case 16: case 17: {
            if (strlen(params[5]) > 0 && strlen(params[6]) > 0) {
                button->qb_label2.len = strlen(params[6])+1;
                button->qb_label2.text = (char*)malloc(button->qb_label2.len);
                sprintf(button->qb_label2.text, "%s", params[6]);
                
                sprintf(button->qb_resref, "%s", params[5]);
            }
            else {
                qb_type = 0;
                qb_class = 0;
                qb_id = 0;
                qb_meta = 0;
            }
        } break;
    }
    
    if (qb_type != 1) 
    {
        button->qb_type      = qb_type;
        button->qb_class     = qb_class;
        button->qb_id        = qb_id;
        button->qb_metamagic = qb_meta;
    }

    nwn_UpdateQuickBar(cre);
}


/* vim: set sw=4: */
