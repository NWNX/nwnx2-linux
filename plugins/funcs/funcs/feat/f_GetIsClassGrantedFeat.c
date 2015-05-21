
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


void Func_GetIsClassGrantedFeat(CGameObject *ob, char *value)
{
    uint8_t level = 0;
    int ret, idx, feat;

    if (sscanf(value, "%d %d", &idx, &feat) != 2 || idx < 0 || idx >= (*NWN_Rules)->ru_classes_len) {
        snprintf(value, strlen(value), "0");
        return;
    }

    ret = CNWClass__IsGrantedFeat(&((*NWN_Rules)->ru_classes[idx]), feat, &level);

    if (ret)
        snprintf(value, strlen(value), "%d", level);
    else
        snprintf(value, strlen(value), "%d", 0);
}


/* vim: set sw=4: */
