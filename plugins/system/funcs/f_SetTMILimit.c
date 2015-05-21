
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

#include "NWNXSystem.h"

extern unsigned char *Ref_TMILimit;


void Func_SetTMILimit(CGameObject *ob, char *value)
{
    int lim = atoi(value);

    if (lim < 16383)
        lim = 16383;
    else if (lim > 8388607)
        lim = 8388607;

    *(Ref_TMILimit + 15) = (lim >> 16) & 0xFF;
    *(Ref_TMILimit + 14) = (lim >> 8) & 0xFF;
    *(Ref_TMILimit + 13) = lim & 0xFF;
}


/* vim: set sw=4: */
