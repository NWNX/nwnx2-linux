string LuaEval(string sCode)
{
    SetLocalString(GetModule(), "NWNX!LUA!EVAL", sCode);
    return GetLocalString(GetModule(), "NWNX!LUA!EVAL");
}
void LuaEvalVoid(string sCode)
{
    SetLocalString(GetModule(), "NWNX!LUA!EVAL", sCode);
}
void LuaRunEvent(string sEvent, object oSelf=OBJECT_SELF)
{
    SetLocalString(GetModule(), "NWNX!LUA!EVENT", sEvent+":0x"+ObjectToString(oSelf));
}
void LuaRunToken(string sToken)
{
    SetLocalString(GetModule(), "NWNX!LUA!TOKEN", sToken);
}