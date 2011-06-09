//wrap_mod_onload
#include "nwnx_lua"

void main()
{
     SetLocalString(OBJECT_SELF, "NWNX!INIT", "1");
     GetLocalObject(OBJECT_SELF, "NWNX!INIT");
     ExecuteScript("x2_mod_def_load",OBJECT_SELF);

     LuaRunEvent("mod_load", OBJECT_SELF);
}