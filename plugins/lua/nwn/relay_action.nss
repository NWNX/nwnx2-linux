#include "nwnx_lua"

void main() {
    string sCmd = GetLocalString(OBJECT_SELF,"relay_cmd");
    ActionDoCommand(LuaRunToken(sCmd));
}