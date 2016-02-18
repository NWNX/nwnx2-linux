#include "NWNXAreas.h"
#include "Services.h"

CNWNXAreas::CNWNXAreas()
{
    confKey = "AREAS";
}

bool CNWNXAreas::OnCreate(gline* config, const char* LogDir)
{
    char log[128];
    sprintf(log, "%s/nwnx_areas.txt", LogDir);
    if (!CNWNXBase::OnCreate(config, log))
        return false;

    RegisterServices();

    return true;
}

namespace
{

nwobjid lastAreaId = OBJECT_INVALID;

};

char* CNWNXAreas::OnRequest(char* gameObject, char* Request, char* Parameters)
{
    Log(2, "Request: %s\n", Request);

    if (strncmp(Request, "CREATE_AREA", 11) == 0) {
        auto area = LoadArea(Parameters);
        if (area != nullptr)
            lastAreaId = area->ObjectID;
        else
            lastAreaId = OBJECT_INVALID;

        return NULL;

    } else if (strncmp(Request, "DESTROY_AREA", 12) == 0) {
        bool ret = UnloadArea(strtol(Parameters, NULL, 16));
        char* sret;
        asprintf(&sret, "%d", ret);
        return sret;
    }

    return NULL;
}

unsigned long CNWNXAreas::OnRequestObject(char* gameObject, char* Request)
{
    if (strncmp(Request, "GET_LAST_AREA_ID", 16) == 0) {
        return lastAreaId;
    }

    return OBJECT_INVALID;
}
