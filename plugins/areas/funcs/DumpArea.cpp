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
	tile_info_s *tilep;
	unsigned int i;

	areas.Log(0, "    resref: %s\n", ap->resref);
	areas.Log(0, "    tileset: %s\n", ap->tileset);
	areas.Log(0, "    environment id: %d\n", ap->lighting);
	areas.Log(0, "    horizontal tiles: %d\n", ap->width);
	areas.Log(0, "    vertical tiles: %d\n", ap->height);
	areas.Log(0, "    spot mod: %d\n", ap->mod_spot);
	areas.Log(0, "    listen mod: %d\n", ap->mod_listen);
	areas.Log(0, "    no-rest: %d\n", ap->no_rest);
	areas.Log(0, "dumping %d bytes from %p...\n", sizeof(area_info_s), ap);

	// for some strange, bizarre, and wholly inexplicable reason,
	// the nwnx logger's output buffer is limited to 2k.
	// output the dump line by line. *sigh*
	char *dump = hexdump((void *)ap, sizeof(CNWSArea));
	char *tok = strtok(dump, "\n");
	while (tok) {
		areas.Log(0, "%s\n", tok);
		tok = strtok(NULL, "\n");
	}
	for (i = 0, tilep = ap->Tiles; i < ap->width * ap->height; i++, tilep++) {
		areas.Log(0, "dump_area: TILE %d ----------------\n", i);
		areas.Log(0, "    Tile_ID: %d\n", tilep->Tile_ID);
		areas.Log(0, "    Position (row, col): (%d, %d)\n", tilep->row, tilep->col);
		areas.Log(0, "    Location key (x, y): (0x%x, 0x%x)\n", tilep->x, tilep->y);
		areas.Log(0, "    Orientation: %d\n", tilep->Tile_Orientation);
		areas.Log(0, "    Height: %d\n", tilep->Tile_Height);
		areas.Log(0, "    MainLight1: %d\n", tilep->Tile_MainLight1);
		areas.Log(0, "    MainLight2: %d\n", tilep->Tile_MainLight2);
		areas.Log(0, "    SrcLight1: %d\n", (tilep->Tile_SrcLight1 + 1) % 256);
		areas.Log(0, "    SrcLight2: %d\n", (tilep->Tile_SrcLight2 + 1) % 256);
		areas.Log(0, "    AnimLoop1: %d\n", tilep->Tile_AnimLoop1);
		areas.Log(0, "    AnimLoop2: %d\n", tilep->Tile_AnimLoop2);
		areas.Log(0, "    AnimLoop3: %d\n", tilep->Tile_AnimLoop3);
		areas.Log(0, "dumping %d bytes from %p...\n", sizeof(tile_info_s), tilep);
		dump = hexdump(tilep, sizeof(tile_info_s));
		areas.Log(0, "%s\n", dump);
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
