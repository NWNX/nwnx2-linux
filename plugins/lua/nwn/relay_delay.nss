#include "nwnx_lua"

void main() {
    string sCmd = GetLocalString(OBJECT_SELF,"relay_cmd");
    DelayCommand(GetLocalFloat(OBJECT_SELF,"relay_delay"), LuaRunToken(sCmd));
}