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
    Log(2, "Request: %s(%s)\n", Request, Parameters);

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
    } else if (strncmp(Request, "DUMP_AREA", 9) == 0) {
        NWNXDumpArea(gameObject, strtol(Parameters, (char **)NULL, 16));
    } else if (strncmp(Request, "GET_AREA_TILESET", 16) == 0) {
        strncpy(Parameters, NWNXGetAreaTileset(gameObject, strtol(Parameters, (char **)NULL, 16)), strlen(Parameters));
    } else if (strncmp(Request, "GET_AREA_NO_REST", 16) == 0) {
        snprintf(Parameters, strlen(Parameters), "%d", NWNXGetNoRest(gameObject, strtol(Parameters, (char **)NULL, 16)));
    } else if (strncmp(Request, "GET_AREA_HEIGHT", 15) == 0) {
        snprintf(Parameters, strlen(Parameters), "%d", NWNXGetAreaHeight(gameObject, strtol(Parameters, (char **)NULL, 16)));
    } else if (strncmp(Request, "GET_AREA_WIDTH", 14) == 0) {
        snprintf(Parameters, strlen(Parameters), "%d", NWNXGetAreaWidth(gameObject, strtol(Parameters, (char **)NULL, 16)));
    } else if (strncmp(Request, "GET_AREA_LIGHTING", 17) == 0) {
        snprintf(Parameters, strlen(Parameters), "%d", NWNXGetAreaLighting(gameObject, strtol(Parameters, (char **)NULL, 16)));
    } else if (strncmp(Request, "GET_AREA_LISTEN_MOD", 19) == 0) {
        snprintf(Parameters, strlen(Parameters), "%d", NWNXGetAreaListen(gameObject, strtol(Parameters, (char **)NULL, 16)));
    } else if (strncmp(Request, "GET_AREA_SPOT_MOD", 17) == 0) {
        snprintf(Parameters, strlen(Parameters), "%d", NWNXGetAreaSpot(gameObject, strtol(Parameters, (char **)NULL, 16)));
    } else if (strncmp(Request, "SET_AREA_LISTEN_MOD", 19) == 0) {
        NWNXSetAreaListen((CNWSArea *)(gameObject - 0xC4), Parameters);
    } else if (strncmp(Request, "SET_AREA_SPOT_MOD", 17) == 0) {
        NWNXSetAreaSpot((CNWSArea *)(gameObject - 0xC4), Parameters);
    } else if (strncmp(Request, "SET_AREA_NAME", 13) == 0) {
        NWNXSetAreaName((CNWSArea *)(gameObject - 0xC4), Parameters);
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
