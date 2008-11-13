object LoadArea(string sResRef)
{
    SetLocalString(GetModule(), "NWNX!AREAS!CREATE_AREA", sResRef);
    return GetLocalObject(GetModule(), "NWNX!AREAS!GET_LAST_AREA_ID");
}

void DestroyArea(object oArea)
{
    SetLocalString(GetModule(), "NWNX!AREAS!DESTROY_AREA", ObjectToString(oArea));
}