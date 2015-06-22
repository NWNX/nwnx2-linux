#include "CNWSModule.h"

int CNWSModule::AIUpdate()
{
    asm("leave");
    asm("mov $0x081b3dec, %eax");
    asm("jmp *%eax");
}

void CNWSModule::AddObjectToLimbo(unsigned long)
{
    asm("leave");
    asm("mov $0x081c09f8, %eax");
    asm("jmp *%eax");
}

int CNWSModule::AddObjectToLookupTable(CExoString, unsigned long)
{
    asm("leave");
    asm("mov $0x081bead4, %eax");
    asm("jmp *%eax");
}

int CNWSModule::AddTURDsToWorld()
{
    asm("leave");
    asm("mov $0x081b8bc0, %eax");
    asm("jmp *%eax");
}

void CNWSModule::AddToTURDList(CNWSPlayerTURD *)
{
    asm("leave");
    asm("mov $0x081bf7f8, %eax");
    asm("jmp *%eax");
}

int CNWSModule::AddWorldJournalEntryStrref(unsigned long, unsigned long, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x081bf3b8, %eax");
    asm("jmp *%eax");
}

void CNWSModule::AddWorldJournalEntry(int, CExoString, CExoString, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x081bf134, %eax");
    asm("jmp *%eax");
}

CNWSModule * CNWSModule::AsNWSModule()
{
    asm("leave");
    asm("mov $0x081c103c, %eax");
    asm("jmp *%eax");
}

void CNWSModule::CleanUpLimboList()
{
    asm("leave");
    asm("mov $0x081c0aec, %eax");
    asm("jmp *%eax");
}

int CNWSModule::ClearAreaVisitedFlags()
{
    asm("leave");
    asm("mov $0x081c0780, %eax");
    asm("jmp *%eax");
}

int CNWSModule::ComputeInterAreaPath(CPathfindInformation *)
{
    asm("leave");
    asm("mov $0x081b3d34, %eax");
    asm("jmp *%eax");
}

int CNWSModule::DeleteWorldJournalAllEntries()
{
    asm("leave");
    asm("mov $0x081bf748, %eax");
    asm("jmp *%eax");
}

void CNWSModule::DeleteWorldJournalEntryStrref(unsigned long)
{
    asm("leave");
    asm("mov $0x081bf658, %eax");
    asm("jmp *%eax");
}

void CNWSModule::DeleteWorldJournalEntry(int)
{
    asm("leave");
    asm("mov $0x081bf568, %eax");
    asm("jmp *%eax");
}

void CNWSModule::DoUpdate()
{
    asm("leave");
    asm("mov $0x081c05fc, %eax");
    asm("jmp *%eax");
}

void CNWSModule::EventHandler(unsigned long, unsigned long, void *, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x081b3f0c, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSModule::FindObjectByTagOrdinal(CExoString const &, unsigned long)
{
    asm("leave");
    asm("mov $0x081bee08, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSModule::FindObjectByTagTypeOrdinal(CExoString const &, int, unsigned long)
{
    asm("leave");
    asm("mov $0x081bef74, %eax");
    asm("jmp *%eax");
}

int CNWSModule::FindTagPositionInTable(char *)
{
    asm("leave");
    asm("mov $0x081c08d0, %eax");
    asm("jmp *%eax");
}

int CNWSModule::GenerateInterAreaDFSSuccessors(int, CPathfindInformation *, unsigned long **)
{
    asm("leave");
    asm("mov $0x081b43cc, %eax");
    asm("jmp *%eax");
}

int CNWSModule::GetAreaByName(CExoString &)
{
    asm("leave");
    asm("mov $0x081b4458, %eax");
    asm("jmp *%eax");
}

CNWSArea * CNWSModule::GetAreaByTag(CExoString &)
{
    asm("leave");
    asm("mov $0x081b45e8, %eax");
    asm("jmp *%eax");
}

int CNWSModule::GetAreaList()
{
    asm("leave");
    asm("mov $0x081c1044, %eax");
    asm("jmp *%eax");
}

CNWSArea * CNWSModule::GetArea(CResRef)
{
    asm("leave");
    asm("mov $0x081c0690, %eax");
    asm("jmp *%eax");
}

CNWSArea * CNWSModule::GetArea(unsigned long)
{
    asm("leave");
    asm("mov $0x081c0728, %eax");
    asm("jmp *%eax");
}

int CNWSModule::GetCustomScriptEventId()
{
    asm("leave");
    asm("mov $0x081c10f0, %eax");
    asm("jmp *%eax");
}

int CNWSModule::GetDawnHour()
{
    asm("leave");
    asm("mov $0x081c154c, %eax");
    asm("jmp *%eax");
}

int CNWSModule::GetDuskHour()
{
    asm("leave");
    asm("mov $0x081c155c, %eax");
    asm("jmp *%eax");
}

int CNWSModule::GetEnableScriptDebugger()
{
    asm("leave");
    asm("mov $0x081c16cc, %eax");
    asm("jmp *%eax");
}

unsigned char * CNWSModule::GetFullCipher(CExoString)
{
    asm("leave");
    asm("mov $0x081bffd8, %eax");
    asm("jmp *%eax");
}

int CNWSModule::GetInvisibleCreaturesList()
{
    asm("leave");
    asm("mov $0x081c157c, %eax");
    asm("jmp *%eax");
}

int CNWSModule::GetIsDigitalDistributionDemo()
{
    asm("leave");
    asm("mov $0x081c15d8, %eax");
    asm("jmp *%eax");
}

int CNWSModule::GetIsNWMFile()
{
    asm("leave");
    asm("mov $0x081c15b4, %eax");
    asm("jmp *%eax");
}

int CNWSModule::GetIsSaveGame()
{
    asm("leave");
    asm("mov $0x081c14c8, %eax");
    asm("jmp *%eax");
}

int CNWSModule::GetLastEnter()
{
    asm("leave");
    asm("mov $0x081c1114, %eax");
    asm("jmp *%eax");
}

int CNWSModule::GetLastExit()
{
    asm("leave");
    asm("mov $0x081c1138, %eax");
    asm("jmp *%eax");
}

int CNWSModule::GetLastItemAcquiredBy()
{
    asm("leave");
    asm("mov $0x081c11a4, %eax");
    asm("jmp *%eax");
}

int CNWSModule::GetLastItemAcquiredFrom()
{
    asm("leave");
    asm("mov $0x081c1180, %eax");
    asm("jmp *%eax");
}

int CNWSModule::GetLastItemAcquiredStackSize()
{
    asm("leave");
    asm("mov $0x081c11c8, %eax");
    asm("jmp *%eax");
}

int CNWSModule::GetLastItemAcquired()
{
    asm("leave");
    asm("mov $0x081c115c, %eax");
    asm("jmp *%eax");
}

int CNWSModule::GetLastItemActivatedArea()
{
    asm("leave");
    asm("mov $0x081c144c, %eax");
    asm("jmp *%eax");
}

int CNWSModule::GetLastItemActivatedPosition()
{
    asm("leave");
    asm("mov $0x081c1408, %eax");
    asm("jmp *%eax");
}

int CNWSModule::GetLastItemActivatedTarget()
{
    asm("leave");
    asm("mov $0x081c13e4, %eax");
    asm("jmp *%eax");
}

int CNWSModule::GetLastItemActivated()
{
    asm("leave");
    asm("mov $0x081c139c, %eax");
    asm("jmp *%eax");
}

int CNWSModule::GetLastItemActivator()
{
    asm("leave");
    asm("mov $0x081c13c0, %eax");
    asm("jmp *%eax");
}

int CNWSModule::GetLastItemLoser()
{
    asm("leave");
    asm("mov $0x081c1354, %eax");
    asm("jmp *%eax");
}

int CNWSModule::GetLastItemLostStackSize()
{
    asm("leave");
    asm("mov $0x081c1378, %eax");
    asm("jmp *%eax");
}

int CNWSModule::GetLastItemLost()
{
    asm("leave");
    asm("mov $0x081c1330, %eax");
    asm("jmp *%eax");
}

int CNWSModule::GetLastPCCancelCutscene()
{
    asm("leave");
    asm("mov $0x081c1494, %eax");
    asm("jmp *%eax");
}

int CNWSModule::GetLastPCLevellingUp()
{
    asm("leave");
    asm("mov $0x081c1470, %eax");
    asm("jmp *%eax");
}

int CNWSModule::GetLastPlayerChatMessageType()
{
    asm("leave");
    asm("mov $0x081c1764, %eax");
    asm("jmp *%eax");
}

CExoString CNWSModule::GetLastPlayerChatMessage()
{
    asm("leave");
    asm("mov $0x081c173c, %eax");
    asm("jmp *%eax");
}

int CNWSModule::GetLastPlayerChatObject()
{
    asm("leave");
    asm("mov $0x081c172c, %eax");
    asm("jmp *%eax");
}

int CNWSModule::GetLastPlayerDied()
{
    asm("leave");
    asm("mov $0x081c127c, %eax");
    asm("jmp *%eax");
}

int CNWSModule::GetLastPlayerDying()
{
    asm("leave");
    asm("mov $0x081c12a0, %eax");
    asm("jmp *%eax");
}

int CNWSModule::GetLastRespawnButtonPresser()
{
    asm("leave");
    asm("mov $0x081c12c4, %eax");
    asm("jmp *%eax");
}

int CNWSModule::GetLastRestEventType()
{
    asm("leave");
    asm("mov $0x081c130c, %eax");
    asm("jmp *%eax");
}

int CNWSModule::GetLastRested()
{
    asm("leave");
    asm("mov $0x081c12e8, %eax");
    asm("jmp *%eax");
}

int CNWSModule::GetLimboArray()
{
    asm("leave");
    asm("mov $0x081c156c, %eax");
    asm("jmp *%eax");
}

int CNWSModule::GetMaxHenchmen()
{
    asm("leave");
    asm("mov $0x081c14ec, %eax");
    asm("jmp *%eax");
}

int CNWSModule::GetMinutesPerHour()
{
    asm("leave");
    asm("mov $0x081c16dc, %eax");
    asm("jmp *%eax");
}

CExoLocString CNWSModule::GetModuleDescription()
{
    asm("leave");
    asm("mov $0x081c1670, %eax");
    asm("jmp *%eax");
}

int CNWSModule::GetModuleEntryInfo()
{
    asm("leave");
    asm("mov $0x081c10d4, %eax");
    asm("jmp *%eax");
}

CExoLocString CNWSModule::GetModuleName()
{
    asm("leave");
    asm("mov $0x081c1624, %eax");
    asm("jmp *%eax");
}

CExoString CNWSModule::GetNWMResName()
{
    asm("leave");
    asm("mov $0x081c15fc, %eax");
    asm("jmp *%eax");
}

int CNWSModule::GetPCItemLastEquippedBy()
{
    asm("leave");
    asm("mov $0x081c1210, %eax");
    asm("jmp *%eax");
}

int CNWSModule::GetPCItemLastEquipped()
{
    asm("leave");
    asm("mov $0x081c11ec, %eax");
    asm("jmp *%eax");
}

int CNWSModule::GetPCItemLastUnequippedBy()
{
    asm("leave");
    asm("mov $0x081c1258, %eax");
    asm("jmp *%eax");
}

int CNWSModule::GetPCItemLastUnequipped()
{
    asm("leave");
    asm("mov $0x081c1234, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSModule::GetPlayerIndexInPlayerList(CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x081be568, %eax");
    asm("jmp *%eax");
}

int CNWSModule::GetPlayerPathfindRule()
{
    asm("leave");
    asm("mov $0x081c16a8, %eax");
    asm("jmp *%eax");
}

CNWSPlayerTURD * CNWSModule::GetPlayerTURDFromList(CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x081bb068, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSModule::GetPrimaryPlayerIndex()
{
    asm("leave");
    asm("mov $0x081c0864, %eax");
    asm("jmp *%eax");
}

int CNWSModule::GetScriptName(int)
{
    asm("leave");
    asm("mov $0x081c1050, %eax");
    asm("jmp *%eax");
}

CNWSScriptVarTable *  CNWSModule::GetScriptVarTable()
{
    asm("leave");
    asm("mov $0x081c10e0, %eax");
    asm("jmp *%eax");
}

int CNWSModule::GetStartMovie()
{
    asm("leave");
    asm("mov $0x081c164c, %eax");
    asm("jmp *%eax");
}

CExoString CNWSModule::GetTag()
{
    asm("leave");
    asm("mov $0x081c158c, %eax");
    asm("jmp *%eax");
}

int CNWSModule::GetTimeOfDayState()
{
    asm("leave");
    asm("mov $0x081c14b8, %eax");
    asm("jmp *%eax");
}

void CNWSModule::GetTime(unsigned long *, unsigned long *, unsigned long *, unsigned long *, unsigned char *, unsigned long *)
{
    asm("leave");
    asm("mov $0x081c09a8, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSModule::GetWaypoint(CExoString const &)
{
    asm("leave");
    asm("mov $0x081c0670, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSModule::GetWorldJournalIndexUnique()
{
    asm("leave");
    asm("mov $0x081c0944, %eax");
    asm("jmp *%eax");
}

int CNWSModule::GetXPScale()
{
    asm("leave");
    asm("mov $0x081c1528, %eax");
    asm("jmp *%eax");
}

int CNWSModule::InterAreaDFS(int, int, CPathfindInformation *)
{
    asm("leave");
    asm("mov $0x081b4810, %eax");
    asm("jmp *%eax");
}

int CNWSModule::IsObjectInLimbo(unsigned long)
{
    asm("leave");
    asm("mov $0x081c0aa4, %eax");
    asm("jmp *%eax");
}

unsigned char CNWSModule::IsOfficialCampaign()
{
    asm("leave");
    asm("mov $0x081bfda8, %eax");
    asm("jmp *%eax");
}

int CNWSModule::LoadLimboCreatures(CResGFF *, CResStruct *, int)
{
    asm("leave");
    asm("mov $0x081be2d8, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSModule::LoadModuleFinish()
{
    asm("leave");
    asm("mov $0x081b87b8, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSModule::LoadModuleInProgress(int, int)
{
    asm("leave");
    asm("mov $0x081b8584, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSModule::LoadModuleStart(CExoString, int)
{
    asm("leave");
    asm("mov $0x081b4a4c, %eax");
    asm("jmp *%eax");
}

void CNWSModule::LoadTURDList(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x081baf90, %eax");
    asm("jmp *%eax");
}

void CNWSModule::PackModuleIntoMessage(unsigned long)
{
    asm("leave");
    asm("mov $0x081b8c84, %eax");
    asm("jmp *%eax");
}

void CNWSModule::PackPlayerCharacterListIntoMessage(CNWSPlayer *, CExoArrayList<NWPlayerCharacterList_st *> &)
{
    asm("leave");
    asm("mov $0x081be6b8, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSModule::PlotInterAreaPath(CPathfindInformation *, unsigned long)
{
    asm("leave");
    asm("mov $0x081b8fb4, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSModule::PlotPathInArea(CPathfindInformation *, unsigned long)
{
    asm("leave");
    asm("mov $0x081b91f0, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSModule::PlotPath(CPathfindInformation *, unsigned long)
{
    asm("leave");
    asm("mov $0x081b9124, %eax");
    asm("jmp *%eax");
}

void CNWSModule::PostProcess()
{
    asm("leave");
    asm("mov $0x081b89f8, %eax");
    asm("jmp *%eax");
}

void CNWSModule::RemoveFromTURDList(CNWSPlayer *)
{
    asm("leave");
    asm("mov $0x081bf97c, %eax");
    asm("jmp *%eax");
}

void CNWSModule::RemoveObjectFromLimbo(unsigned long)
{
    asm("leave");
    asm("mov $0x081c0a58, %eax");
    asm("jmp *%eax");
}

int CNWSModule::RemoveObjectFromLookupTable(CExoString, unsigned long)
{
    asm("leave");
    asm("mov $0x081bec28, %eax");
    asm("jmp *%eax");
}

void CNWSModule::SaveLimboCreatures(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x081be1d0, %eax");
    asm("jmp *%eax");
}

int CNWSModule::SaveModuleFAC(CERFFile *)
{
    asm("leave");
    asm("mov $0x081bb37c, %eax");
    asm("jmp *%eax");
}

int CNWSModule::SaveModuleFinish(CExoString &, CExoString &)
{
    asm("leave");
    asm("mov $0x081ba01c, %eax");
    asm("jmp *%eax");
}

int CNWSModule::SaveModuleIFOFinish(CResGFF *, CResStruct *, CERFFile *, CExoString &, CExoArrayList<unsigned long> &)
{
    asm("leave");
    asm("mov $0x081bb1c4, %eax");
    asm("jmp *%eax");
}

int CNWSModule::SaveModuleIFOStart(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x081ba420, %eax");
    asm("jmp *%eax");
}

int CNWSModule::SaveModuleInProgress()
{
    asm("leave");
    asm("mov $0x081bb7a8, %eax");
    asm("jmp *%eax");
}

void CNWSModule::SaveModuleStart(CExoString &, CExoString &)
{
    asm("leave");
    asm("mov $0x081b9c90, %eax");
    asm("jmp *%eax");
}

int CNWSModule::SavePlayers(CResGFF *, CResStruct *, CExoString &, CExoArrayList<unsigned long> &)
{
    asm("leave");
    asm("mov $0x081bba0c, %eax");
    asm("jmp *%eax");
}

int CNWSModule::SaveStatic(CERFFile *, CExoString, unsigned short, int)
{
    asm("leave");
    asm("mov $0x081bdf5c, %eax");
    asm("jmp *%eax");
}

int CNWSModule::SaveTURDList(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x081c07d4, %eax");
    asm("jmp *%eax");
}

int CNWSModule::SetCustomScriptEventId(int)
{
    asm("leave");
    asm("mov $0x081c1100, %eax");
    asm("jmp *%eax");
}

int CNWSModule::SetEnableScriptDebugger(unsigned char)
{
    asm("leave");
    asm("mov $0x081c16b8, %eax");
    asm("jmp *%eax");
}

void CNWSModule::SetIntraAreaGoal(CPathfindInformation *)
{
    asm("leave");
    asm("mov $0x081be92c, %eax");
    asm("jmp *%eax");
}

int CNWSModule::SetIsNWMFile(int)
{
    asm("leave");
    asm("mov $0x081c15c4, %eax");
    asm("jmp *%eax");
}

int CNWSModule::SetIsSaveGame(int)
{
    asm("leave");
    asm("mov $0x081c14d8, %eax");
    asm("jmp *%eax");
}

int CNWSModule::SetLastEnter(unsigned long)
{
    asm("leave");
    asm("mov $0x081c1124, %eax");
    asm("jmp *%eax");
}

int CNWSModule::SetLastExit(unsigned long)
{
    asm("leave");
    asm("mov $0x081c1148, %eax");
    asm("jmp *%eax");
}

int CNWSModule::SetLastItemAcquiredBy(unsigned long)
{
    asm("leave");
    asm("mov $0x081c11b4, %eax");
    asm("jmp *%eax");
}

int CNWSModule::SetLastItemAcquiredFrom(unsigned long)
{
    asm("leave");
    asm("mov $0x081c1190, %eax");
    asm("jmp *%eax");
}

int CNWSModule::SetLastItemAcquiredStackSize(int)
{
    asm("leave");
    asm("mov $0x081c11d8, %eax");
    asm("jmp *%eax");
}

int CNWSModule::SetLastItemAcquired(unsigned long)
{
    asm("leave");
    asm("mov $0x081c116c, %eax");
    asm("jmp *%eax");
}

int CNWSModule::SetLastItemActivatedArea(unsigned long)
{
    asm("leave");
    asm("mov $0x081c145c, %eax");
    asm("jmp *%eax");
}

int CNWSModule::SetLastItemActivatedPosition(Vector const &)
{
    asm("leave");
    asm("mov $0x081c142c, %eax");
    asm("jmp *%eax");
}

int CNWSModule::SetLastItemActivatedTarget(unsigned long)
{
    asm("leave");
    asm("mov $0x081c13f4, %eax");
    asm("jmp *%eax");
}

int CNWSModule::SetLastItemActivated(unsigned long)
{
    asm("leave");
    asm("mov $0x081c13ac, %eax");
    asm("jmp *%eax");
}

int CNWSModule::SetLastItemActivator(unsigned long)
{
    asm("leave");
    asm("mov $0x081c13d0, %eax");
    asm("jmp *%eax");
}

int CNWSModule::SetLastItemLoser(unsigned long)
{
    asm("leave");
    asm("mov $0x081c1364, %eax");
    asm("jmp *%eax");
}

int CNWSModule::SetLastItemLostStackSize(int)
{
    asm("leave");
    asm("mov $0x081c1388, %eax");
    asm("jmp *%eax");
}

int CNWSModule::SetLastItemLost(unsigned long)
{
    asm("leave");
    asm("mov $0x081c1340, %eax");
    asm("jmp *%eax");
}

int CNWSModule::SetLastPCCancelCutscene(unsigned long)
{
    asm("leave");
    asm("mov $0x081c14a4, %eax");
    asm("jmp *%eax");
}

int CNWSModule::SetLastPCLevellingUp(unsigned long)
{
    asm("leave");
    asm("mov $0x081c1480, %eax");
    asm("jmp *%eax");
}

int CNWSModule::SetLastPlayerChatMessageType(unsigned char)
{
    asm("leave");
    asm("mov $0x081c1718, %eax");
    asm("jmp *%eax");
}

int CNWSModule::SetLastPlayerChatMessage(CExoString const &)
{
    asm("leave");
    asm("mov $0x081c1700, %eax");
    asm("jmp *%eax");
}

int CNWSModule::SetLastPlayerChatObject(unsigned long)
{
    asm("leave");
    asm("mov $0x081c16ec, %eax");
    asm("jmp *%eax");
}

int CNWSModule::SetLastPlayerDied(unsigned long)
{
    asm("leave");
    asm("mov $0x081c128c, %eax");
    asm("jmp *%eax");
}

int CNWSModule::SetLastPlayerDying(unsigned long)
{
    asm("leave");
    asm("mov $0x081c12b0, %eax");
    asm("jmp *%eax");
}

int CNWSModule::SetLastRespawnButtonPresser(unsigned long)
{
    asm("leave");
    asm("mov $0x081c12d4, %eax");
    asm("jmp *%eax");
}

int CNWSModule::SetLastRestEventType(unsigned char)
{
    asm("leave");
    asm("mov $0x081c131c, %eax");
    asm("jmp *%eax");
}

int CNWSModule::SetLastRested(unsigned long)
{
    asm("leave");
    asm("mov $0x081c12f8, %eax");
    asm("jmp *%eax");
}

int CNWSModule::SetMaxHenchmen(int)
{
    asm("leave");
    asm("mov $0x081c14fc, %eax");
    asm("jmp *%eax");
}

int CNWSModule::SetNWMResName(CExoString &)
{
    asm("leave");
    asm("mov $0x081c15e4, %eax");
    asm("jmp *%eax");
}

int CNWSModule::SetPCItemLastEquippedBy(unsigned long)
{
    asm("leave");
    asm("mov $0x081c1220, %eax");
    asm("jmp *%eax");
}

int CNWSModule::SetPCItemLastEquipped(unsigned long)
{
    asm("leave");
    asm("mov $0x081c11fc, %eax");
    asm("jmp *%eax");
}

int CNWSModule::SetPCItemLastUnequippedBy(unsigned long)
{
    asm("leave");
    asm("mov $0x081c1268, %eax");
    asm("jmp *%eax");
}

int CNWSModule::SetPCItemLastUnequipped(unsigned long)
{
    asm("leave");
    asm("mov $0x081c1244, %eax");
    asm("jmp *%eax");
}

int CNWSModule::SetPlayerPathfindRule(unsigned char)
{
    asm("leave");
    asm("mov $0x081c1694, %eax");
    asm("jmp *%eax");
}

void CNWSModule::SetScriptName(int, CExoString)
{
    asm("leave");
    asm("mov $0x081c106c, %eax");
    asm("jmp *%eax");
}

int CNWSModule::SetXPScale(unsigned char)
{
    asm("leave");
    asm("mov $0x081c1538, %eax");
    asm("jmp *%eax");
}

void CNWSModule::TimeStopSanityCheck()
{
    asm("leave");
    asm("mov $0x081bfcdc, %eax");
    asm("jmp *%eax");
}

int CNWSModule::UnloadModule()
{
    asm("leave");
    asm("mov $0x081c08c8, %eax");
    asm("jmp *%eax");
}

void CNWSModule::UpdateTime(unsigned long, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x081bfaf8, %eax");
    asm("jmp *%eax");
}

