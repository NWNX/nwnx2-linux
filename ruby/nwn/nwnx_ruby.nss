string NWNXRuby_Eval(string sCode);

string NWNXRuby_Eval(string sCode)
{
    SetLocalString(GetModule(), "NWNX!RUBY!EVAL", sCode);
    return GetLocalString(GetModule(), "NWNX!RUBY!EVAL");
}
