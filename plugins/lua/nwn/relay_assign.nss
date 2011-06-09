#include "nwnx_lua"

void main() {
    string sCmd = GetLocalString(OBJECT_SELF,"relay_cmd");
    AssignCommand(OBJECT_SELF,LuaRunToken(sCmd));
}