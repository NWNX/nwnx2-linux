// NWNX Areas
// Area instancing plugin
// (c) by virusman, 2006-2010

// Create new area from ResRef
object LoadArea(string sResRef);
// Create new area from ResRef
object CreateArea(string sResRef);
// Destroy area
void DestroyArea(object oArea);
// Set name for oArea
void SetAreaName(object oArea, string sName);

const string DYN_AREA_POINTERS = "dyn_ptrs";

object LoadArea(string sResRef)
{
    SetLocalString(GetModule(), "NWNX!AREAS!CREATE_AREA", sResRef);
    object area = GetLocalObject(GetModule(), "NWNX!AREAS!GET_LAST_AREA_ID");
    
    if ( area != OBJECT_INVALID ) {
        object mod = GetModule();
        string pointers = GetLocalString(mod, DYN_AREA_POINTERS);
        string ptr = ObjectToString(area);
        int len;
        for ( len = GetStringLength(ptr); len < 8; len++ )
        {
            ptr = "0" + ptr;
        }
        SetLocalString(mod, DYN_AREA_POINTERS, pointers + ptr);
    }
    
    return area;
}

object CreateArea(string sResRef)
{
    return LoadArea(sResRef);
}

void DestroyArea(object oArea)
{
    SetLocalString(GetModule(), "NWNX!AREAS!DESTROY_AREA", ObjectToString(oArea));
    // TODO: Remove area pointer from pointer string ... 
}

void SetAreaName(object oArea, string sName)
{
    SetLocalString(oArea, "NWNX!AREAS!SET_AREA_NAME", sName);
}

// Call whenever someone joins the module.
// This might sound expensive, but it will only reallocate memory if someone doesn't yet have all the dynamic areas.
void CatchupAreas()
{
    SetLocalString(GetModule(), "NWNX!AREAS!CATCHUP_AREAS", GetLocalString(GetModule(), DYN_AREA_POINTERS));
}
