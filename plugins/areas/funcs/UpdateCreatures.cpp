#include "../NWNXAreas.h"

void UpdateCreatures()
{
    auto module = g_pAppManager->ServerExoApp->GetModule();
    auto playerList = g_pAppManager->ServerExoApp->GetPlayerList();
    auto& areaIdList = module->AreaIdList;

    for (auto elem = (CExoLinkedListNode*) playerList->GetHeadPos();
            elem != nullptr;
            elem = elem->Next) {

        auto client = ((CNWSClient*) elem->Data);
        auto player = client->vptr->AsNWSPlayer(client);

        auto creature = g_pAppManager->ServerExoApp->
                        GetCreatureByGameObjectID(player->m_oidPCObject);

        // Players in the character selection screen don't have a creature associated.
        if (!creature)
            continue;

        // Creatures with no automaptiledata yet must not be touched.
        // Not sure when this would happen, but better safe than sorry.
        if (!creature->AutoMapTileData)
            continue;

        // We just rebuild the creature mapdata lists from scratch, because that's
        // much easier to understand and less prone to errors.

        char** newMapData = (char**) calloc(areaIdList.Length, 4);

        for (size_t areaIdx = 0; areaIdx < areaIdList.Length; areaIdx++) {
            unsigned long areaId = areaIdList[areaIdx];

            int idx = creature->AutoMapAreaIdList.IndexOf(areaId);
            if (idx != -1) {
                // we have a existing value. Let's grab that.
                newMapData[areaIdx] = creature->AutoMapTileData[idx];
                creature->AutoMapTileData[idx] = nullptr;
            } else {
                newMapData[areaIdx] = new char[0x80];
            }
        }

        // Swapsies.

        for (size_t i = 0; i < creature->AutoMapNumAreas; i++)
            if (creature->AutoMapTileData[i] != nullptr)
                free(creature->AutoMapTileData[i]);

        creature->AutoMapAreaIdList.SetSize(0);
        for (size_t areaIdx = 0; areaIdx < areaIdList.Length; areaIdx++)
            creature->AutoMapAreaIdList.Add(areaIdList[areaIdx]);

        free(creature->AutoMapTileData);

        creature->AutoMapNumAreas = areaIdList.Length;
        creature->AutoMapTileData = newMapData;
    }
}
