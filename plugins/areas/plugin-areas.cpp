#include "NWNXAreas.h"

CNWNXAreas areas;
PLUGINLINK* pluginLink = 0;

PLUGININFO pluginInfo = {
    sizeof(PLUGININFO),
    "NWNXAreas",
    PLUGIN_MAKE_VERSION(0, 0, 0, 1),
    "",
    "",
    "",
    "",
    "",
    0
};

extern "C"
CNWNXBase* GetClassObject()
{
    return &areas;
}

extern "C"
PLUGININFO* GetPluginInfo(DWORD nwnxVersion)
{
    return &pluginInfo;
}

extern "C"
int InitPlugin(PLUGINLINK* link)
{
    pluginLink = link;
    return 0;
}
