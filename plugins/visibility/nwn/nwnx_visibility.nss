const int VISIBILITY_TYPE_DEFAULT = 0;
const int VISIBILITY_TYPE_VISIBLE = 1;
const int VISIBILITY_TYPE_INVISIBLE = 2;

void SetVisibilityOverride(object oObject, int nVisibilityType)
{
    SetLocalString(oObject, "NWNX!VISIBILITY!SET_VISIBILITY_OVERRIDE", IntToString(nVisibilityType));
}

void SetVisibility(object oObject1, object oObject2, int nVisibility)
{
    SetLocalString(oObject1, "NWNX!VISIBILITY!SET_VISIBILITY", ObjectToString(oObject2)+"¬"+IntToString(nVisibility));
}
