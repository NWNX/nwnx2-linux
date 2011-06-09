void NWNXExtend_ScriptResult(int nResult=1);

void NWNXExtend_ScriptResult(int nResult=1) {
    SetLocalInt(GetModule(), "NWNX!EXTEND!RESULT", IntToString(nResult));
    DeleteLocalInt(GetModule(), "NWNX!EXTEND!RESULT");
}