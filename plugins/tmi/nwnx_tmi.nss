// Returns the TMI limit.
// nwserver default is 131071
int GetTMILimit();

// Sets the TMI limit to the given value.
// Min is 16k, max is about 8M.
void SetTMILimit(int nLimit);


int GetTMILimit () {
    SetLocalString(GetModule(), "NWNX!TMI!GETLIMIT", "          ");
    return StringToInt(GetLocalString(GetModule(), "NWNX!TMI!GETLIMIT"));
}

void SetTMILimit (int nLimit) {
    SetLocalString(GetModule(), "NWNX!TMI!SETLIMIT", IntToString(nLimit));
}
