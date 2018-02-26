/***************************************************************************
    Funcs.h -
    advance declarations and definitions for use in functions of nwnx_areas

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

typedef unsigned long dword;

#ifdef __cplusplus
extern "C" {
#endif

// Loads an area, returns nullptr on failure.
CNWSArea* LoadArea(const std::string& resref);

// Unloads an area by oid. False on failure.
bool UnloadArea(nwobjid areaId);

// Update all player minimap lists. Used internally.
void UpdateCreatures();

// global function / alt entry point, if actual area is available
void dump_area(CNWSArea *ap);

void NWNXDumpArea(void *pModule, dword nAreaID);

int NWNXGetAreaHeight(void *pModule, dword nAreaID);

int NWNXGetAreaWidth(void *pModule, dword nAreaID);

int NWNXGetAreaLighting(void *pModule, dword nAreaID);

int NWNXGetAreaListen(void *pModule, dword nAreaID);

int NWNXGetAreaLoadscreen(void *pModule, dword nAreaID);

int NWNXGetAreaPVP(void *pModule, dword nAreaID);

int NWNXGetAreaSpot(void *pModule, dword nAreaID);

int NWNXGetNoRest(void *pModule, dword nAreaID);

char* NWNXGetAreaTileset(void *pModule, dword nAreaID);

int NWNXGetTileAtLocation(void *pModule, char *locstring);

void NWNXSetAreaName(CNWSArea *pArea, char *sNewName);

void NWNXSetAreaListen(CNWSArea *pArea, char *val);

void NWNXSetAreaSpot(CNWSArea *pArea, char *val);


// Re-send area lists to all DMs. Used internally.
inline void UpdateDMs()
{
    auto playerList = g_pAppManager->ServerExoApp->GetPlayerList();

    for (auto elem = (CExoLinkedListNode*) playerList->GetHeadPos();
            elem != nullptr;
            elem = elem->Next) {

        const auto cli = ((CNWSClient*) playerList->GetAtPos(elem));

        if (const auto pl = cli->vptr->AsNWSDungeonMaster(cli)) {
            g_pAppManager->ServerExoApp->GetNWSMessage()->
            SendServerToPlayerDungeonMasterAreaList(pl->m_nPlayerID);
        }

    }
}

#ifdef __cplusplus
}
#endif
