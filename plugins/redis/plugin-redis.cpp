#include "NWNXRedis.h"

CNWNXRedis Redis;

PLUGINLINK *pluginLink = 0;

PLUGININFO pluginInfo={
	sizeof(PLUGININFO),
	"NWNXREDIS",
	PLUGIN_MAKE_VERSION(0,0,0,1),
	"",
	"niv",
	"n@e-ix.net",
	"MIT licence",
	"",
	0		//not transient
};


extern "C" PLUGININFO* GetPluginInfo(DWORD nwnxVersion) {
	return &pluginInfo;
}

extern "C" int InitPlugin(PLUGINLINK *link) {
	pluginLink=link;
	return 0;
}

extern "C" CNWNXBase *GetClassObject() {
    return &Redis;
}
