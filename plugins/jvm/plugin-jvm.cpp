#include "NWNXJVM.h"

CNWNXJVM jvm;
PLUGINLINK *pluginLink = 0;

PLUGININFO pluginInfo = {
    sizeof(PLUGININFO),
    "NWNXJVM",
    PLUGIN_MAKE_VERSION(0, 0, 0, 1),
    "",
    "niv",
    "n@e-ix.net",
    "MIT",
    "",
    0		//not transient
};

extern "C" PLUGININFO* GetPluginInfo(DWORD nwnxVersion)
{
    return &pluginInfo;
}

extern "C" int InitPlugin(PLUGINLINK *link)
{
    pluginLink = link;
    return 0;
}

extern "C"
CNWNXBase* GetClassObject()
{
    return &jvm;
}
