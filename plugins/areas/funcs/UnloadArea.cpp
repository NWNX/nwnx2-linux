#include "../NWNXAreas.h"

bool UnloadArea(nwobjid areaId)
{
    CNWSArea* area = g_pAppManager->ServerExoApp->
                     GetAreaByGameObjectID(areaId);

    if (area == nullptr)
        return false;

    areas.Log(1, "Unloading area: oid=%x, tag='%s'\n", areaId, area->Tag.CStr());

    if (area->GetNumPlayersInArea()) {
        areas.Log(0, "Cannot unload area oid=%x, tag='%s', players in area\n",
                  areaId, area->Tag.CStr());
        return false;
    }

    g_pAppManager->ServerExoApp->GetModule()->
    AreaIdList.Remove(area->ObjectID);

    auto& turdList = g_pAppManager->ServerExoApp->GetModule()->TURDList;

    while (area->ObjectList.Length > 0) {
        auto id = area->ObjectList[0];
        area->ObjectList.Remove(id);

        auto go = g_pAppManager->ServerExoApp->GetGameObject(id);

        // TURDs are added to areas directly as objects, to determine where
        // the player needs to respawn. We have the choice of rebasing the TURD
        // onto another area, or just removing it completely.
        // We'll add a config option to rebase TURDs onto static areas later; for
        // now, we'll just delete them (and lose all the reputation data they hold).
        if (const auto turd = go->vptr->AsNWSPlayerTURD(go)) {
            areas.Log(1, "TURD for '%s' in area, removing from module\n",
                      turd->CommntyName.CStr());

            for (auto elem = (CExoLinkedListNode*) turdList.GetHeadPos();
                    elem != nullptr;
                    elem = elem->Next) {

                if (elem->Data == turd) {
                    turdList.Remove(elem);
                    break;
                }
            }
        }

        go->vptr->Destructor(go, 3);

        assert(nullptr == g_pAppManager->ServerExoApp->GetGameObject(id));
    }

    area->CNWArea::vptr->Destructor(area, 3);

    UpdateCreatures();
    UpdateDMs();

    areas.Log(1, "Unloaded area %x\n", areaId);

    return true;
}