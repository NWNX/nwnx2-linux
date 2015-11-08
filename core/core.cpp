#include "core.h"

PLUGINLINK *pluginLink;

void Core_Console_Init();
void Core_Console_Builtins_Init();
void Core_Mainloop_Init();
void Core_Module_Init();
void Core_RunScript_Init();
void Core_Object_Init();

void Core_Init(PLUGINLINK *link)
{
    pluginLink = link;

    Core_Console_Init();
    Core_Console_Builtins_Init();
    Core_Mainloop_Init();
    Core_Module_Init();
    Core_RunScript_Init();
    Core_Object_Init();
}
