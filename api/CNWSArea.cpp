#include "CNWSArea.h"

int CNWSArea::AIUpdate()
{
    asm("leave");
    asm("mov $0x080cc3e0, %eax");
    asm("jmp *%eax");
}

int CNWSArea::AddObjectToArea(unsigned long, int)
{
    asm("leave");
    asm("mov $0x080cd6e4, %eax");
    asm("jmp *%eax");
}

int CNWSArea::AddSubArea(CGameObject *)
{
    asm("leave");
    asm("mov $0x080d57f8, %eax");
    asm("jmp *%eax");
}

void CNWSArea::ApplyEffect(CGameEffect *, Vector, Vector)
{
    asm("leave");
    asm("mov $0x080d3af0, %eax");
    asm("jmp *%eax");
}

CNWSArea * CNWSArea::AsNWSArea()
{
    asm("leave");
    asm("mov $0x080d55bc, %eax");
    asm("jmp *%eax");
}

void CNWSArea::BudgeCreatures(Vector const &, Vector const &, Vector const &, unsigned long, int)
{
    asm("leave");
    asm("mov $0x080d4468, %eax");
    asm("jmp *%eax");
}

int CNWSArea::ClearLineOfSight(Vector, Vector, Vector *, unsigned long *, unsigned long, unsigned long, int)
{
    asm("leave");
    asm("mov $0x080d31f0, %eax");
    asm("jmp *%eax");
}

Vector CNWSArea::ComputeAwayVector(Vector, Vector, float, CPathfindInformation *)
{
    asm("leave");
    asm("mov $0x080d5e48, %eax");
    asm("jmp *%eax");
}

int CNWSArea::ComputeBestCorner(float, float, float, float, float, float, float, float, float *, float *, float *, float *)
{
    asm("leave");
    asm("mov $0x080d63b8, %eax");
    asm("jmp *%eax");
}

float CNWSArea::ComputeHeight(Vector)
{
    asm("leave");
    asm("mov $0x080d65fc, %eax");
    asm("jmp *%eax");
}

int CNWSArea::ComputeNonVisibleLocation(Vector, CPathfindInformation *, int, Vector *, float)
{
    asm("leave");
    asm("mov $0x080d7658, %eax");
    asm("jmp *%eax");
}

int CNWSArea::ComputePathDistance(int, float *)
{
    asm("leave");
    asm("mov $0x080de8b0, %eax");
    asm("jmp *%eax");
}

int CNWSArea::ComputeSafeLocationInDirection(Vector, Vector, float, CPathfindInformation *, int, Vector *)
{
    asm("leave");
    asm("mov $0x080d6c08, %eax");
    asm("jmp *%eax");
}

int CNWSArea::ComputeSafeLocation(Vector, float, CPathfindInformation *, int, Vector *)
{
    asm("leave");
    asm("mov $0x080d70d4, %eax");
    asm("jmp *%eax");
}

int CNWSArea::CountAreaTransitionTriggers(unsigned long *, int, unsigned long *)
{
    asm("leave");
    asm("mov $0x080d7de8, %eax");
    asm("jmp *%eax");
}

int CNWSArea::CountVisibleToPlayers(Vector, int)
{
    asm("leave");
    asm("mov $0x080d7c28, %eax");
    asm("jmp *%eax");
}

void CNWSArea::DecreaseAILevelPriority()
{
    asm("leave");
    asm("mov $0x080cdf18, %eax");
    asm("jmp *%eax");
}

void CNWSArea::DecrementPlayersInArea()
{
    asm("leave");
    asm("mov $0x080d48cc, %eax");
    asm("jmp *%eax");
}

int CNWSArea::EvaluateOverlappingTargets(CPathfindInformation *, Vector, unsigned long, float, float, float, int, int, unsigned long *)
{
    asm("leave");
    asm("mov $0x080da5c8, %eax");
    asm("jmp *%eax");
}

void CNWSArea::EventHandler(unsigned long, unsigned long, void *, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x080cc5f0, %eax");
    asm("jmp *%eax");
}

int CNWSArea::ExploreArea(CNWSCreature *, int, int, int)
{
    asm("leave");
    asm("mov $0x080d9268, %eax");
    asm("jmp *%eax");
}

int CNWSArea::GenerateInterTilePath(int *, int, int, int)
{
    asm("leave");
    asm("mov $0x080d9438, %eax");
    asm("jmp *%eax");
}

int CNWSArea::GetAmbientSound()
{
    asm("leave");
    asm("mov $0x080d597c, %eax");
    asm("jmp *%eax");
}

int CNWSArea::GetAreaListenCheckModifier()
{
    asm("leave");
    asm("mov $0x080d58f4, %eax");
    asm("jmp *%eax");
}

int CNWSArea::GetAreaName()
{
    asm("leave");
    asm("mov $0x080d595c, %eax");
    asm("jmp *%eax");
}

int CNWSArea::GetAreaSpotCheckModifier()
{
    asm("leave");
    asm("mov $0x080d58e4, %eax");
    asm("jmp *%eax");
}

int CNWSArea::GetCurrentWeather()
{
    asm("leave");
    asm("mov $0x080d59e8, %eax");
    asm("jmp *%eax");
}

int CNWSArea::GetCustomScriptEventId()
{
    asm("leave");
    asm("mov $0x080d5904, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSArea::GetDoorCrossed(Vector, Vector)
{
    asm("leave");
    asm("mov $0x080d412c, %eax");
    asm("jmp *%eax");
}

int CNWSArea::GetFirstObjectInArea(unsigned long &)
{
    asm("leave");
    asm("mov $0x080d4814, %eax");
    asm("jmp *%eax");
}

int CNWSArea::GetFirstObjectIndiceByX(int *, float)
{
    asm("leave");
    asm("mov $0x080cd5f4, %eax");
    asm("jmp *%eax");
}

int CNWSArea::GetGameObjectsArray()
{
    asm("leave");
    asm("mov $0x080d57b4, %eax");
    asm("jmp *%eax");
}

int CNWSArea::GetInterAreaDFSVisited()
{
    asm("leave");
    asm("mov $0x080d5938, %eax");
    asm("jmp *%eax");
}

int CNWSArea::GetIsIDInExcludeList(unsigned long, CExoArrayList<CGameObject *> *)
{
    asm("leave");
    asm("mov $0x080d51e8, %eax");
    asm("jmp *%eax");
}

int CNWSArea::GetLastEntered()
{
    asm("leave");
    asm("mov $0x080d5780, %eax");
    asm("jmp *%eax");
}

int CNWSArea::GetLastLeft()
{
    asm("leave");
    asm("mov $0x080d5790, %eax");
    asm("jmp *%eax");
}

unsigned short CNWSArea::GetLoadScreenID()
{
    asm("leave");
    asm("mov $0x080d5a1c, %eax");
    asm("jmp *%eax");
}

int CNWSArea::GetMapSize()
{
    asm("leave");
    asm("mov $0x080d59b4, %eax");
    asm("jmp *%eax");
}

int CNWSArea::GetNextObjectInArea(unsigned long &)
{
    asm("leave");
    asm("mov $0x080d4858, %eax");
    asm("jmp *%eax");
}

int CNWSArea::GetNumPlayersInArea()
{
    asm("leave");
    asm("mov $0x080d596c, %eax");
    asm("jmp *%eax");
}

int CNWSArea::GetObjectByNameIndex()
{
    asm("leave");
    asm("mov $0x080d58c4, %eax");
    asm("jmp *%eax");
}

int CNWSArea::GetObjectsArrayPosition()
{
    asm("leave");
    asm("mov $0x080d57c4, %eax");
    asm("jmp *%eax");
}

int CNWSArea::GetOverrideWeather()
{
    asm("leave");
    asm("mov $0x080d59d8, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSArea::GetPVPSetting()
{
    asm("leave");
    asm("mov $0x080d5234, %eax");
    asm("jmp *%eax");
}

int CNWSArea::GetScriptName(int)
{
    asm("leave");
    asm("mov $0x080d55cc, %eax");
    asm("jmp *%eax");
}

CNWSScriptVarTable *  CNWSArea::GetScriptVarTable()
{
    asm("leave");
    asm("mov $0x080d57e8, %eax");
    asm("jmp *%eax");
}

int CNWSArea::GetSoundPathInformation()
{
    asm("leave");
    asm("mov $0x080d58d4, %eax");
    asm("jmp *%eax");
}

int CNWSArea::GetSurfaceMaterial(Vector)
{
    asm("leave");
    asm("mov $0x080d528c, %eax");
    asm("jmp *%eax");
}

CExoString CNWSArea::GetTag()
{
    asm("leave");
    asm("mov $0x080d5744, %eax");
    asm("jmp *%eax");
}

int CNWSArea::GetTileSetResRef()
{
    asm("leave");
    asm("mov $0x080d59f8, %eax");
    asm("jmp *%eax");
}

CNWSTile * CNWSArea::GetTile(Vector)
{
    asm("leave");
    asm("mov $0x080cdcc8, %eax");
    asm("jmp *%eax");
}

int CNWSArea::GetTile(int, int)
{
    asm("leave");
    asm("mov $0x080d5650, %eax");
    asm("jmp *%eax");
}

int CNWSArea::GetTrapList()
{
    asm("leave");
    asm("mov $0x080d5928, %eax");
    asm("jmp *%eax");
}

int CNWSArea::GoalMoveDenied(int, int, int)
{
    asm("leave");
    asm("mov $0x080d9590, %eax");
    asm("jmp *%eax");
}

int CNWSArea::GridDFSGenerateSuccessors(int, int, int, int, int, CNWSAreaGridSuccessors **)
{
    asm("leave");
    asm("mov $0x080ddbcc, %eax");
    asm("jmp *%eax");
}

int CNWSArea::GridDFSTransTableGet(int, int, int *, int *)
{
    asm("leave");
    asm("mov $0x080dea24, %eax");
    asm("jmp *%eax");
}

int CNWSArea::GridDFSTransTableHash(int, int)
{
    asm("leave");
    asm("mov $0x080de9f0, %eax");
    asm("jmp *%eax");
}

int CNWSArea::GridDFSTransTableInitialize()
{
    asm("leave");
    asm("mov $0x080de984, %eax");
    asm("jmp *%eax");
}

void CNWSArea::GridDFSTransTablePut(int, int, int, int)
{
    asm("leave");
    asm("mov $0x080deabc, %eax");
    asm("jmp *%eax");
}

int CNWSArea::GridDFSearch(int, int, int, int, int, int)
{
    asm("leave");
    asm("mov $0x080dd9a0, %eax");
    asm("jmp *%eax");
}

int CNWSArea::HandleTransparentDoors(float, float, float, float, float, float, float, unsigned long, unsigned long &, int, CExoArrayList<CGameObject *> *, int)
{
    asm("leave");
    asm("mov $0x080d308c, %eax");
    asm("jmp *%eax");
}

int CNWSArea::InSubAreas(Vector, CExoArrayList<unsigned long> *)
{
    asm("leave");
    asm("mov $0x080da3f4, %eax");
    asm("jmp *%eax");
}

void CNWSArea::IncreaseAILevelPriority()
{
    asm("leave");
    asm("mov $0x080cdda8, %eax");
    asm("jmp *%eax");
}

void CNWSArea::IncrementPlayersInArea()
{
    asm("leave");
    asm("mov $0x080d489c, %eax");
    asm("jmp *%eax");
}

void CNWSArea::InterTileDFSExploreArea(unsigned char *, int, int, int, float, float)
{
    asm("leave");
    asm("mov $0x080d7fa4, %eax");
    asm("jmp *%eax");
}

int CNWSArea::InterTileDFSGenerateSuccessors(int, int, int, int)
{
    asm("leave");
    asm("mov $0x080d9820, %eax");
    asm("jmp *%eax");
}

int CNWSArea::InterTileDFSSoundPath(unsigned char *, int, int, int, int)
{
    asm("leave");
    asm("mov $0x080d882c, %eax");
    asm("jmp *%eax");
}

int CNWSArea::InterTileDFS(int, int, int, int, int)
{
    asm("leave");
    asm("mov $0x080d96b0, %eax");
    asm("jmp *%eax");
}

int CNWSArea::IntersectingLineSegment(Vector, Vector, CExoArrayList<unsigned long> *)
{
    asm("leave");
    asm("mov $0x080da1f8, %eax");
    asm("jmp *%eax");
}

int CNWSArea::LoadAreaEffects(CResGFF *, CResStruct *, int)
{
    asm("leave");
    asm("mov $0x080d0b24, %eax");
    asm("jmp *%eax");
}

int CNWSArea::LoadAreaHeader(CResStruct *)
{
    asm("leave");
    asm("mov $0x080ce0d8, %eax");
    asm("jmp *%eax");
}

int CNWSArea::LoadArea(int)
{
    asm("leave");
    asm("mov $0x080cdfdc, %eax");
    asm("jmp *%eax");
}

int CNWSArea::LoadCreatures(CResGFF *, CResStruct *, int)
{
    asm("leave");
    asm("mov $0x080cf3f0, %eax");
    asm("jmp *%eax");
}

int CNWSArea::LoadDoors(CResGFF *, CResStruct *, int)
{
    asm("leave");
    asm("mov $0x080cf99c, %eax");
    asm("jmp *%eax");
}

int CNWSArea::LoadEncounters(CResGFF *, CResStruct *, int)
{
    asm("leave");
    asm("mov $0x080cffa4, %eax");
    asm("jmp *%eax");
}

int CNWSArea::LoadGIT(int)
{
    asm("leave");
    asm("mov $0x080cf218, %eax");
    asm("jmp *%eax");
}

int CNWSArea::LoadItems(CResGFF *, CResStruct *, int)
{
    asm("leave");
    asm("mov $0x080cf758, %eax");
    asm("jmp *%eax");
}

int CNWSArea::LoadPlaceables(CResGFF *, CResStruct *, int)
{
    asm("leave");
    asm("mov $0x080d041c, %eax");
    asm("jmp *%eax");
}

int CNWSArea::LoadPlayers(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x080d48f4, %eax");
    asm("jmp *%eax");
}

int CNWSArea::LoadProperties(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x080d4900, %eax");
    asm("jmp *%eax");
}

int CNWSArea::LoadSounds(CResGFF *, CResStruct *, int)
{
    asm("leave");
    asm("mov $0x080d02ec, %eax");
    asm("jmp *%eax");
}

int CNWSArea::LoadStores(CResGFF *, CResStruct *, int)
{
    asm("leave");
    asm("mov $0x080d0880, %eax");
    asm("jmp *%eax");
}

int CNWSArea::LoadTileSetInfo(CResStruct *)
{
    asm("leave");
    asm("mov $0x080cec24, %eax");
    asm("jmp *%eax");
}

int CNWSArea::LoadTriggers(CResGFF *, CResStruct *, int)
{
    asm("leave");
    asm("mov $0x080cfde0, %eax");
    asm("jmp *%eax");
}

int CNWSArea::LoadWaypoints(CResGFF *, CResStruct *, int)
{
    asm("leave");
    asm("mov $0x080d0144, %eax");
    asm("jmp *%eax");
}

CNWSArea * CNWSArea::NWAreaAsNWSArea()
{
    asm("leave");
    asm("mov $0x080d55c4, %eax");
    asm("jmp *%eax");
}

int CNWSArea::NoCreaturesOnLine(float, float, float, float, CPathfindInformation *, int, int, unsigned long *, int)
{
    asm("leave");
    asm("mov $0x080da71c, %eax");
    asm("jmp *%eax");
}

int CNWSArea::NoNoneWalkPolysInStaticObject(unsigned long, float, float, float, float, float, float, float, unsigned long, int)
{
    asm("leave");
    asm("mov $0x080deb48, %eax");
    asm("jmp *%eax");
}

int CNWSArea::PackAreaIntoMessage(int, int, int, CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x080d0e00, %eax");
    asm("jmp *%eax");
}

void CNWSArea::PlayVisualEffect(unsigned short, Vector)
{
    asm("leave");
    asm("mov $0x080d2e54, %eax");
    asm("jmp *%eax");
}

int CNWSArea::PlotGridPath(CPathfindInformation *, unsigned long long)
{
    asm("leave");
    asm("mov $0x080dcbb4, %eax");
    asm("jmp *%eax");
}

int CNWSArea::PlotPath(CPathfindInformation *, unsigned long long)
{
    asm("leave");
    asm("mov $0x080daef8, %eax");
    asm("jmp *%eax");
}

int CNWSArea::PlotSoundPath(CPathfindInformation *)
{
    asm("leave");
    asm("mov $0x080de750, %eax");
    asm("jmp *%eax");
}

int CNWSArea::PositionWalkable(Vector)
{
    asm("leave");
    asm("mov $0x080d4024, %eax");
    asm("jmp *%eax");
}

int CNWSArea::RemoveInterTileExit(int, int, int, int)
{
    asm("leave");
    asm("mov $0x080dbaa0, %eax");
    asm("jmp *%eax");
}

int CNWSArea::RemoveObjectFromArea(unsigned long)
{
    asm("leave");
    asm("mov $0x080cdb74, %eax");
    asm("jmp *%eax");
}

int CNWSArea::RemoveSubArea(CGameObject *)
{
    asm("leave");
    asm("mov $0x080d5848, %eax");
    asm("jmp *%eax");
}

void CNWSArea::SaveAreaEffects(CResGFF *, CResStruct *, CExoArrayList<unsigned long> &)
{
    asm("leave");
    asm("mov $0x080d507c, %eax");
    asm("jmp *%eax");
}

int CNWSArea::SaveArea(CERFFile *, CExoString &)
{
    asm("leave");
    asm("mov $0x080d49fc, %eax");
    asm("jmp *%eax");
}

void CNWSArea::SaveCreatures(CResGFF *, CResStruct *, CExoArrayList<unsigned long> &)
{
    asm("leave");
    asm("mov $0x080d2ae4, %eax");
    asm("jmp *%eax");
}

void CNWSArea::SaveDoors(CResGFF *, CResStruct *, CExoArrayList<unsigned long> &)
{
    asm("leave");
    asm("mov $0x080d4ae8, %eax");
    asm("jmp *%eax");
}

void CNWSArea::SaveEncounters(CResGFF *, CResStruct *, CExoArrayList<unsigned long> &)
{
    asm("leave");
    asm("mov $0x080d4c80, %eax");
    asm("jmp *%eax");
}

void CNWSArea::SaveGIT(CERFFile *, CExoString &, CExoArrayList<unsigned long> &)
{
    asm("leave");
    asm("mov $0x080d2238, %eax");
    asm("jmp *%eax");
}

void CNWSArea::SaveItems(CResGFF *, CResStruct *, CExoArrayList<unsigned long> &)
{
    asm("leave");
    asm("mov $0x080d4a04, %eax");
    asm("jmp *%eax");
}

void CNWSArea::SavePlaceables(CResGFF *, CResStruct *, CExoArrayList<unsigned long> &)
{
    asm("leave");
    asm("mov $0x080d4ee4, %eax");
    asm("jmp *%eax");
}

int CNWSArea::SaveProperties(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x080d5148, %eax");
    asm("jmp *%eax");
}

void CNWSArea::SaveSounds(CResGFF *, CResStruct *, CExoArrayList<unsigned long> &)
{
    asm("leave");
    asm("mov $0x080d4e18, %eax");
    asm("jmp *%eax");
}

void CNWSArea::SaveStores(CResGFF *, CResStruct *, CExoArrayList<unsigned long> &)
{
    asm("leave");
    asm("mov $0x080d4fb0, %eax");
    asm("jmp *%eax");
}

void CNWSArea::SaveTriggers(CResGFF *, CResStruct *, CExoArrayList<unsigned long> &)
{
    asm("leave");
    asm("mov $0x080d4bb4, %eax");
    asm("jmp *%eax");
}

void CNWSArea::SaveWaypoints(CResGFF *, CResStruct *, CExoArrayList<unsigned long> &)
{
    asm("leave");
    asm("mov $0x080d4d4c, %eax");
    asm("jmp *%eax");
}

void CNWSArea::SetCurrentWeather(unsigned char, int)
{
    asm("leave");
    asm("mov $0x080d42e4, %eax");
    asm("jmp *%eax");
}

int CNWSArea::SetCustomScriptEventId(int)
{
    asm("leave");
    asm("mov $0x080d5914, %eax");
    asm("jmp *%eax");
}

int CNWSArea::SetInterAreaDFSVisited(int)
{
    asm("leave");
    asm("mov $0x080d5948, %eax");
    asm("jmp *%eax");
}

int CNWSArea::SetLastEntered(unsigned long)
{
    asm("leave");
    asm("mov $0x080d576c, %eax");
    asm("jmp *%eax");
}

int CNWSArea::SetLastLeft(unsigned long)
{
    asm("leave");
    asm("mov $0x080d57a0, %eax");
    asm("jmp *%eax");
}

int CNWSArea::SetMapSize(unsigned char)
{
    asm("leave");
    asm("mov $0x080d59a0, %eax");
    asm("jmp *%eax");
}

int CNWSArea::SetObjectByNameIndex(int)
{
    asm("leave");
    asm("mov $0x080d58b0, %eax");
    asm("jmp *%eax");
}

int CNWSArea::SetObjectsArrayPosition(int)
{
    asm("leave");
    asm("mov $0x080d57d4, %eax");
    asm("jmp *%eax");
}

int CNWSArea::SetOverrideWeather(unsigned char)
{
    asm("leave");
    asm("mov $0x080d59c4, %eax");
    asm("jmp *%eax");
}

int CNWSArea::SetPVPSetting(unsigned char)
{
    asm("leave");
    asm("mov $0x080d598c, %eax");
    asm("jmp *%eax");
}

void CNWSArea::SetScriptName(int, CExoString)
{
    asm("leave");
    asm("mov $0x080d55e8, %eax");
    asm("jmp *%eax");
}

int CNWSArea::SetSearchInfo(CPathfindInformation *)
{
    asm("leave");
    asm("mov $0x080d5694, %eax");
    asm("jmp *%eax");
}

int CNWSArea::SetTag(CExoString)
{
    asm("leave");
    asm("mov $0x080d56a8, %eax");
    asm("jmp *%eax");
}

int CNWSArea::SmoothCornerOptimize(int, float *, int *, float **)
{
    asm("leave");
    asm("mov $0x080dbbb4, %eax");
    asm("jmp *%eax");
}

int CNWSArea::SmoothPointsOnPath()
{
    asm("leave");
    asm("mov $0x080dbeb4, %eax");
    asm("jmp *%eax");
}

int CNWSArea::SmoothSelectNodes(int, float *, int *, float **, int, int)
{
    asm("leave");
    asm("mov $0x080dbfc0, %eax");
    asm("jmp *%eax");
}

int CNWSArea::SmoothSelection(int, float *, int *, float **)
{
    asm("leave");
    asm("mov $0x080de8f8, %eax");
    asm("jmp *%eax");
}

int CNWSArea::TestDirectLine(float, float, float, float, float, float, int)
{
    asm("leave");
    asm("mov $0x080dc354, %eax");
    asm("jmp *%eax");
}

int CNWSArea::TestLineWalkable(float, float, float, float, float)
{
    asm("leave");
    asm("mov $0x080dc890, %eax");
    asm("jmp *%eax");
}

int CNWSArea::TestSafeLocationPoint(Vector, CPathfindInformation *)
{
    asm("leave");
    asm("mov $0x080d67a8, %eax");
    asm("jmp *%eax");
}

void CNWSArea::UnloadArea()
{
    asm("leave");
    asm("mov $0x080d2c48, %eax");
    asm("jmp *%eax");
}

void CNWSArea::UpdatePlayerAutomaps()
{
    asm("leave");
    asm("mov $0x080d9378, %eax");
    asm("jmp *%eax");
}

int CNWSArea::UpdatePositionInObjectsArray(CGameObject *)
{
    asm("leave");
    asm("mov $0x080cd898, %eax");
    asm("jmp *%eax");
}

