#include "../NWNXAreas.h"

CNWSArea* LoadArea(const std::string& resref)
{
    CResRef res(resref.c_str());

    auto area = new CNWSArea(res, 0, OBJECT_INVALID);

    if (!area->LoadArea(0)) {
        areas.Log(0, "Failed to load area resref='%s'\n", resref.c_str());
        area->CNWArea::vptr->Destructor(area, 3);
        return nullptr;
    }

    areas.Log(1, "Loaded area: resref='%s', tag='%s'\n",
              resref.c_str(), area->Tag.CStr());

    g_pAppManager->ServerExoApp->GetModule()->
    AreaIdList.Add(area->ObjectID);

    // Add the newly created area to existing player TURDs.
    {
        auto& turdList = g_pAppManager->ServerExoApp->GetModule()->TURDList;
        for (auto elem = (CExoLinkedListNode*) turdList.GetHeadPos();
                elem != nullptr;
                elem = elem->Next) {

            auto turd = (CNWSPlayerTURD*) turdList.GetAtPos(elem);

            turd->AutoMapData = (char**) realloc(turd->AutoMapData,
                                                 (turd->AutoMapNumAreas + 1) * 4);
            assert(turd->AutoMapData); // OOM?

            turd->AutoMapAreaIdList = (unsigned long*) realloc(turd->AutoMapAreaIdList,
                                      (turd->AutoMapNumAreas + 1) * 4);
            assert(turd->AutoMapAreaIdList); // OOM?

            turd->AutoMapData[turd->AutoMapNumAreas] = new char[0x80];
            turd->AutoMapAreaIdList[turd->AutoMapNumAreas] = area->ObjectID;
            turd->AutoMapNumAreas++;
            areas.Log(1, "Expanded automap data for TURD of '%s' to include %x\n",
                      turd->CommntyName.Text, area->ObjectID);
        }
    }

    UpdateCreatures();
    UpdateDMs();

    return area;
}