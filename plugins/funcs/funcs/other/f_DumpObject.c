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
#include "hexdump.h"


void Func_DumpObject(CGameObject *ob, char *value)
{
    char buf[HDBUFSIZE], *p;
    int osize = HDBUFSIZE;	// object size. dump this much (round to line len)

	strcpy(buf, "DUMP: ");
	p = buf + 6;
	switch(ob->type) {
	  case OBJECT_TYPE_AREA:
		// global CNWSArea struct doesn't have tag or resref, as nwnx_areas does
		osize = sizeof(CNWSArea);
		sprintf(p, "DUMP: AREA (object type %d): %p, %d bytes",
			ob->type, ob, osize);
		break;
	  case OBJECT_TYPE_CREATURE:
		osize = sizeof(CNWSCreature);
		sprintf(p, "DUMP: CREATURE (object type %d): tag: %s  resref: %s  id: %u (%#x)  stats: %p - %p, %d bytes",
			ob->type, ob->tag, ob->resref, ob->id, ob->id, ((CNWSCreature *)ob)->cre_stats, ob, osize);
		break;
	  case OBJECT_TYPE_ITEM:
		osize = sizeof(CNWSItem);
		sprintf(p, "DUMP: ITEM (object type %d): tag: %s  resref: %s  id: %u (%#x) - %p, %d bytes",
			ob->type, ob->tag, ob->resref, ob->id, ob->id, ob, osize);
		break;
	  case OBJECT_TYPE_MODULE:
		osize = sizeof(CNWSModule);
		sprintf(p, "DUMP: MODULE (object type %d): tag: %s  resref: %s  id: %u (%#x) - %p, %d bytes",
			ob->type, ob->tag, ob->resref, ob->id, ob->id, ob, osize);
		break;
	  case OBJECT_TYPE_PLACEABLE:
		osize = sizeof(CNWSPlaceable);
		sprintf(p, "DUMP: PLACEABLE (object type %d): tag: %s  resref: %s  id: %u (%#x) - %p, %d bytes",
			ob->type, ob->tag, ob->resref, ob->id, ob->id, ob, osize);
		break;
	  case OBJECT_TYPE_WAYPOINT:
		osize = sizeof(CNWSWaypoint);
		sprintf(p, "DUMP: WAYPOINT (object type %d): tag: %s  resref: %s  id: %u (%#x) - %p, %d bytes",
			ob->type, ob->tag, ob->resref, ob->id, ob->id, ob, osize);
		break;
	  default:
		sprintf(p, "unknown object (type %d)  tag: %s  resref: %s  id: %u (%#x) - %p, %d bytes",
			ob->type, ob->tag, ob->resref, ob->id, ob->id, ob, osize);
	}

	nx_log(NX_LOG_DEBUG, 0, buf);
	nx_log(NX_LOG_DEBUG, 0, "\n%s", hexdump((void *)ob, osize));
	nx_log(NX_LOG_DEBUG, 0, "DUMP ENDS ----------------\n");
}
