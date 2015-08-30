#include "core.h"

PLUGINLINK *pluginLink;

void Core_Mainloop_Init();
void Core_RunScript_Init();
void Core_Object_Init();

void Core_Init(PLUGINLINK *link)
{
	pluginLink = link;

	Core_Mainloop_Init();
	Core_RunScript_Init();
	Core_Object_Init();
}
