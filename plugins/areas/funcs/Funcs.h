// Loads an area, returns nullptr on failure.
CNWSArea* LoadArea(const std::string& resref);

// Unloads an area by oid. False on failure.
bool UnloadArea(nwobjid areaId);

// Update all player minimap lists. Used internally.
void UpdateCreatures();

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