/***************************************************************************
    Areas plugin for NWNX
    (c) 2010 virusman (virusman@virusman.ru)
    modifications 2018 by niv, xorbaxian

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

#include "../NWNXAreas.h"
#include "hexdump.h"

void dump_area(struct area_info *ap)
{
	areas.Log(0, "dump_area: area width=%d, area height=%d, no-rest = %d\n", ap->width, ap->height, ap->no_rest);
	areas.Log(0, "dump_area: resref = %s, tileset = %s, spot = %d, listen = %d, lighting = %d\n",
		ap->resref, ap->tileset, ap->mod_spot, ap->mod_listen, ap->lighting);
	areas.Log(0, "dump_area: dumping %d bytes from %p...\n", sizeof(CNWSArea), ap);

	// for some strange, bizarre, and wholly inexplicable reason,
	// the nwnx logger's output buffer is limited to 2k.
	// output the dump line by line. *sigh*
	char *dump = hexdump((void *)ap, sizeof(CNWSArea));
	char *tok = strtok(dump, "\n");
	while (tok) {
		areas.Log(0, "%s\n", tok);
		tok = strtok(NULL, "\n");
	}
	areas.Log(0, "dump_area: DUMP ENDS ----------------\n");
}

void NWNXDumpArea(void *pModule, dword areaId)
{
	if (areaId <= 0 || areaId == OBJECT_INVALID) {
		areas.Log(1, "Invalid area ID passed to NWNXDumpArea\n");//debug
		return;
	}
	areas.Log(0, "Dumping area %08lX\n", areaId);
	dump_area((struct area_info *)g_pAppManager->ServerExoApp->GetAreaByGameObjectID(areaId));
}

/* vim: set ts=4 sw=4: */
