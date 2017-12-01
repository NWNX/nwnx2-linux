// Create new area from ResRef.
// Will return OBJECT_INVALID on failure.
object CreateArea(string sResRef);

// Destroy area. Will return FALSE on failure.
int DestroyArea(object oArea);

object CreateArea(string sResRef)
{
    SetLocalString(GetModule(), "NWNX!AREAS!CREATE_AREA", sResRef);
    return GetLocalObject(GetModule(), "NWNX!AREAS!GET_LAST_AREA_ID");
}

void DestroyArea(object oArea)
{
    SetLocalString(GetModule(), "NWNX!AREAS!DESTROY_AREA", ObjectToString(oArea));
    return StringToInt(GetLocalString(GetModule(), "NWNX!AREAS!DESTROY_AREA"));
}
