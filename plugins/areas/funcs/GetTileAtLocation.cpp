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
#include "../area_info.h"
#include "../tile_info.h"

#ifdef __cplusplus
extern "C" {
#endif

int NWNXGetTileAtLocation(void *pModule, char *locstring)
{
	unsigned int i, ntiles, id;
	unsigned long row, col;
	float x, y;
	dword area_id;
	area_info_s *ap;
	tile_info_s *tp;

	if (sscanf(locstring, "%lx,%f,%f", &area_id, &x, &y) != 3 || area_id <= 0 || area_id == OBJECT_INVALID) {
		areas.Log(1, "NWNXGetTileAtLocation: invalid location string '%s'\n", locstring);
		return -1;
	}

	ap = (struct area_info *)g_pAppManager->ServerExoApp->GetAreaByGameObjectID(area_id);
	ntiles = ap->width * ap->height;
	col = x / 10;
	row = y / 10;
	areas.Log(2, "fetching tile id for area %s (%d tiles) at (%d, %d)\n", ap->resref, ntiles, col, row);

	for (i = 0, tp = ap->Tiles; i < ntiles && (tp->col != col || tp->row != row); i++, tp++)
		;

	if (i < ntiles) {
		id = tp->Tile_ID;
		areas.Log(3, "found tile TILE%d in tile %d at (%d, %d)\n", id, i, tp->col, tp->row);//debug
	} else {
		id = -1;
		areas.Log(1, "no tile found for area %s at vector (%f, %f).\n", ap->resref, x, y);//debug
	}

    return id;
}

#ifdef __cplusplus
}
#endif

/* vim: set ts=4 sw=4: */
