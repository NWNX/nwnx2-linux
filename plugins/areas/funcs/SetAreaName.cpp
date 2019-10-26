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

void NWNXSetAreaName(CNWSArea *pArea, char *sNewName)
{
	areas.Log(0, "*** SetAreaName is non-functional ***\n");

/* broken since nwnx_areas rewrite

	areas.Log(3, "SetAreaName: %x, '%s'\n", pArea->GameObject.ObjectID, sNewName);

	lsName->AddString(0, (CExoString *)0, newstr);
	CExoLocString *lsName = (CExoLocString *)&pArea->Name;
	if (!lsName)
		return;
	int len = strlen(sNewName);
	char *newstr = new char[len + 1];
	strncpy(newstr, sNewName, len);
	newstr[len] = 0;

    UpdateCreatures();
    UpdateDMs();
*/
}

/* vim: set ts=4 sw=4: */
