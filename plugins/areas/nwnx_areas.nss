// NWNX Areas
// Area instancing and data manipulation plugin
// (c) by virusman, 2006-2010
// additions (c) 2018 by niv, xorbaxian

// Create new area from ResRef
object CreateArea(string sResRef);

// Destroy area oArea
void DestroyArea(object oArea);

// Create new area from ResRef. Same as CreateArea
// this function is DEPRECATED, included only for backward compatibility
object LoadArea(string sResRef);

// given a valid area oArea, dump the structure's contents to the server log.
// this should be used for debugging only.
void DumpArea(object oArea);

// Set name for oArea
void SetAreaName(object oArea, string sName);

// given a valid area oArea, return the name of the tileset the area was built with
string GetAreaTileset(object oArea);

// given a valid area oArea, return how many tiles across it is (i.e., East-West)
// returns 0 on error
int GetAreaWidth(object oArea);

// given a valid area oArea, return how many tiles it is long (i.e., North-South)
// returns 0 on error
int GetAreaHeight(object oArea);

// given a valid area oArea, return the id that determines its lighting effects,
//   as given in environment.2da
// returns -1 on error
int GetAreaLighting(object oArea);

// given a valid area oArea, return TRUE if the area has the 'no rest' flag
//   set, otherwise return FALSE
// returns FALSE on error
int GetNoRest(object oArea);

// given a valid area oArea, return the area's global listen skill modifier
// returns 0 on error
int GetAreaListenMod(object oArea);

// given a valid area oArea, return the area's global spot skill modifier
// returns 0 on error
int GetAreaSpotMod(object oArea);

// given a valid area oArea and an integer argument 'mod' from -127 to 127,
// set the area's global listen skill modifier to the provided argument
void SetAreaListenMod(object oArea, int mod);

// given a valid area oArea and an integer argument 'mod' from -127 to 127,
// set the area's global listen skill modifier to the provided argument
void SetAreaSpotMod(object oArea, int mod);


object CreateArea(string sResRef)
{
    object oM = GetModule();
    SetLocalString(oM, "NWNX!AREAS!CREATE_AREA", sResRef);
    return GetLocalObject(oM, "NWNX!AREAS!GET_LAST_AREA_ID");
}

void DestroyArea(object oArea)
{
    object oM = GetModule();
    SetLocalString(oM, "NWNX!AREAS!DESTROY_AREA", ObjectToString(oArea));
}

object LoadArea(string sResRef)
{
    return CreateArea(sResRef);
}

void DumpArea(object oArea)
{
    object oM = GetModule();
    SetLocalString(oM, "NWNX!AREAS!DUMP_AREA", ObjectToString(oArea));
}

string GetAreaTileset(object oArea)
{
	string padding = "                ";	// assure we have space for return value
    object oM = GetModule();
    SetLocalString(oM, "NWNX!AREAS!GET_AREA_TILESET", padding + ObjectToString(oArea));
    return GetLocalString(oM, "NWNX!AREAS!GET_AREA_TILESET");
}

int GetAreaHeight(object oArea)
{
	string padding = "                ";	// assure we have space for return value
    object oM = GetModule();
    SetLocalString(oM, "NWNX!AREAS!GET_AREA_HEIGHT", padding + ObjectToString(oArea));
    return StringToInt(GetLocalString(oM, "NWNX!AREAS!GET_AREA_HEIGHT"));
}

int GetAreaWidth(object oArea)
{
	string padding = "                ";	// assure we have space for return value
    object oM = GetModule();
    SetLocalString(oM, "NWNX!AREAS!GET_AREA_WIDTH", padding + ObjectToString(oArea));
    return StringToInt(GetLocalString(oM, "NWNX!AREAS!GET_AREA_WIDTH"));
}

int GetNoRest(object oArea)
{
	string padding = "                ";	// assure we have space for return value
    object oM = GetModule();
    SetLocalString(oM, "NWNX!AREAS!GET_AREA_NO_REST", padding + ObjectToString(oArea));
    return StringToInt(GetLocalString(oM, "NWNX!AREAS!GET_AREA_NO_REST"));
}

int GetAreaLighting(object oArea)
{
	string padding = "                ";	// assure we have space for return value
    object oM = GetModule();
    SetLocalString(oM, "NWNX!AREAS!GET_AREA_LIGHTING", padding + ObjectToString(oArea));
    return StringToInt(GetLocalString(oM, "NWNX!AREAS!GET_AREA_LIGHTING"));
}

int GetAreaListenMod(object oArea)
{
	string padding = "                ";	// assure we have space for return value
    object oM = GetModule();
    SetLocalString(oM, "NWNX!AREAS!GET_AREA_LISTEN_MOD", padding + ObjectToString(oArea));
    return StringToInt(GetLocalString(oM, "NWNX!AREAS!GET_AREA_LISTEN_MOD"));
}

int GetAreaSpotMod(object oArea)
{
	string padding = "                ";	// assure we have space for return value
    object oM = GetModule();
    SetLocalString(oM, "NWNX!AREAS!GET_AREA_SPOT_MOD", padding + ObjectToString(oArea));
    return StringToInt(GetLocalString(oM, "NWNX!AREAS!GET_AREA_SPOT_MOD"));
}

void SetAreaListenMod(object oArea, int mod)
{
    SetLocalString(oArea, "NWNX!AREAS!SET_AREA_LISTEN_MOD", IntToString(mod));
}

void SetAreaSpotMod(object oArea, int mod)
{
    SetLocalString(oArea, "NWNX!AREAS!SET_AREA_SPOT_MOD", IntToString(mod));
}

void SetAreaName(object oArea, string sName)
{
    SetLocalString(oArea, "NWNX!AREAS!SET_AREA_NAME", sName);
}
