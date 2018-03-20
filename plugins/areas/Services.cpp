#include "NWNXAreas.h"

void RegisterServices()
{
    CreateServiceFunction(SERVICE_AREAS_LOAD_AREA, [](uintptr_t p) -> int {
        AreasLoadAreaService* e = (AreasLoadAreaService*) p;

        CNWSArea* a = LoadArea(e->resref);
        e->areaId = a != nullptr ? a->ObjectID : OBJECT_INVALID;

        return 1;
    });

    CreateServiceFunction(SERVICE_AREAS_DESTROY_AREA, [](uintptr_t p) -> int {
        AreasDestroyAreaService* e = (AreasDestroyAreaService*) p;

        e->success = UnloadArea(e->areaId);

        return 1;
    });
}
