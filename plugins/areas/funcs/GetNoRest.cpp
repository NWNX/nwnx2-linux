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

int NWNXGetNoRest(void *pModule, dword areaId)
{
	if (areaId <= 0 || areaId == OBJECT_INVALID) {
		areas.Log(1, "Invalid area ID passed to NWNXGetNoRest\n");//debug
		return -1;
	}
	area_info_s *ap = (area_info_s *)g_pAppManager->ServerExoApp->GetAreaByGameObjectID(areaId);
	return ap->no_rest;
}

/* vim: set ts=4 sw=4: */
