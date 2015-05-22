#include "CNWSPlayer.h"

int CNWSPlayer::AddArea(unsigned long)
{
    asm("leave");
    asm("mov $0x0805e944, %eax");
    asm("jmp *%eax");
}

void CNWSPlayer::AddDMAbilities(CNWSCreature *)
{
    asm("leave");
    asm("mov $0x08055758, %eax");
    asm("jmp *%eax");
}

void CNWSPlayer::AllocateAreas(int)
{
    asm("leave");
    asm("mov $0x0805e8f0, %eax");
    asm("jmp *%eax");
}

CNWSPlayer * CNWSPlayer::AsNWSPlayer()
{
    asm("leave");
    asm("mov $0x0805eba4, %eax");
    asm("jmp *%eax");
}

int CNWSPlayer::BackupServerCharacter(CExoString const &)
{
    asm("leave");
    asm("mov $0x08057ef0, %eax");
    asm("jmp *%eax");
}

void CNWSPlayer::CleanMyTURDs()
{
    asm("leave");
    asm("mov $0x0805e6c4, %eax");
    asm("jmp *%eax");
}

int CNWSPlayer::ClearPlayerLastUpdateObject()
{
    asm("leave");
    asm("mov $0x0805ea54, %eax");
    asm("jmp *%eax");
}

void CNWSPlayer::ClearPlayerOnDestroyGame()
{
    asm("leave");
    asm("mov $0x08053e48, %eax");
    asm("jmp *%eax");
}

CNWSPlayerLastUpdateObject * CNWSPlayer::CreateNewPlayerLastUpdateObject()
{
    asm("leave");
    asm("mov $0x0805e9dc, %eax");
    asm("jmp *%eax");
}

void CNWSPlayer::DropTURD()
{
    asm("leave");
    asm("mov $0x08054150, %eax");
    asm("jmp *%eax");
}

void CNWSPlayer::EatTURD(CNWSPlayerTURD *)
{
    asm("leave");
    asm("mov $0x08054468, %eax");
    asm("jmp *%eax");
}

int CNWSPlayer::GetAlwaysRun()
{
    asm("leave");
    asm("mov $0x0805ed4c, %eax");
    asm("jmp *%eax");
}

int CNWSPlayer::GetAreaNum() const
{
    asm("leave");
    asm("mov $0x0805ed10, %eax");
    asm("jmp *%eax");
}

int CNWSPlayer::GetAreaTransitionBMP()
{
    asm("leave");
    asm("mov $0x0805ecc4, %eax");
    asm("jmp *%eax");
}

int CNWSPlayer::GetAreaTransitionName()
{
    asm("leave");
    asm("mov $0x0805ecd0, %eax");
    asm("jmp *%eax");
}

int CNWSPlayer::GetArea(int) const
{
    asm("leave");
    asm("mov $0x0805ed1c, %eax");
    asm("jmp *%eax");
}

int CNWSPlayer::GetCharSheetGUIInfo()
{
    asm("leave");
    asm("mov $0x0805ec90, %eax");
    asm("jmp *%eax");
}

int CNWSPlayer::GetCharacterInfoFromIFO(unsigned char &, int *, unsigned char *, unsigned long &)
{
    asm("leave");
    asm("mov $0x08055380, %eax");
    asm("jmp *%eax");
}

int CNWSPlayer::GetCharacterType()
{
    asm("leave");
    asm("mov $0x0805ed68, %eax");
    asm("jmp *%eax");
}

int CNWSPlayer::GetCommunityNameAuthorized()
{
    asm("leave");
    asm("mov $0x0805edc8, %eax");
    asm("jmp *%eax");
}

int CNWSPlayer::GetContainerGUIInfo()
{
    asm("leave");
    asm("mov $0x0805ecb4, %eax");
    asm("jmp *%eax");
}

int CNWSPlayer::GetCutsceneState()
{
    asm("leave");
    asm("mov $0x0805ee78, %eax");
    asm("jmp *%eax");
}

int CNWSPlayer::GetFileName()
{
    asm("leave");
    asm("mov $0x0805ed94, %eax");
    asm("jmp *%eax");
}

int CNWSPlayer::GetFloatyEffects()
{
    asm("leave");
    asm("mov $0x0805ecf4, %eax");
    asm("jmp *%eax");
}

int CNWSPlayer::GetFromSaveGame()
{
    asm("leave");
    asm("mov $0x0805ec24, %eax");
    asm("jmp *%eax");
}

int CNWSPlayer::GetFromTURD()
{
    asm("leave");
    asm("mov $0x0805ec5c, %eax");
    asm("jmp *%eax");
}

CNWSObject * CNWSPlayer::GetGameObject()
{
    asm("leave");
    asm("mov $0x0805e8b8, %eax");
    asm("jmp *%eax");
}

int CNWSPlayer::GetIFOCharacterIndex()
{
    asm("leave");
    asm("mov $0x0805edd8, %eax");
    asm("jmp *%eax");
}

int CNWSPlayer::GetInventoryGUIInfo()
{
    asm("leave");
    asm("mov $0x0805ec9c, %eax");
    asm("jmp *%eax");
}

int CNWSPlayer::GetIsAllowedToSave()
{
    asm("leave");
    asm("mov $0x0805e768, %eax");
    asm("jmp *%eax");
}

int CNWSPlayer::GetIsPrimaryPlayer()
{
    asm("leave");
    asm("mov $0x0805ec08, %eax");
    asm("jmp *%eax");
}

int CNWSPlayer::GetJournalQuestInfo()
{
    asm("leave");
    asm("mov $0x0805ec78, %eax");
    asm("jmp *%eax");
}

int CNWSPlayer::GetLastObjectControlled()
{
    asm("leave");
    asm("mov $0x0805ebc8, %eax");
    asm("jmp *%eax");
}

CLastUpdateObject * CNWSPlayer::GetLastUpdateObject(unsigned long)
{
    asm("leave");
    asm("mov $0x0805e710, %eax");
    asm("jmp *%eax");
}

int CNWSPlayer::GetLastUpdatedTime()
{
    asm("leave");
    asm("mov $0x0805ebe4, %eax");
    asm("jmp *%eax");
}

int CNWSPlayer::GetLoginState()
{
    asm("leave");
    asm("mov $0x0805ebac, %eax");
    asm("jmp *%eax");
}

int CNWSPlayer::GetModuleInfoSucceeded()
{
    asm("leave");
    asm("mov $0x0805ee10, %eax");
    asm("jmp *%eax");
}

int CNWSPlayer::GetOtherInventoryGUIInfo()
{
    asm("leave");
    asm("mov $0x0805eca8, %eax");
    asm("jmp *%eax");
}

int CNWSPlayer::GetPCObject()
{
    asm("leave");
    asm("mov $0x0805ee30, %eax");
    asm("jmp *%eax");
}

int CNWSPlayer::GetPlayModuleListingCharacters()
{
    asm("leave");
    asm("mov $0x0805ee58, %eax");
    asm("jmp *%eax");
}

int CNWSPlayer::GetPlayerLastUpdateObject()
{
    asm("leave");
    asm("mov $0x0805ee3c, %eax");
    asm("jmp *%eax");
}

int CNWSPlayer::GetPlayerListIndex()
{
    asm("leave");
    asm("mov $0x0805ec40, %eax");
    asm("jmp *%eax");
}

CExoString CNWSPlayer::GetPlayerName()
{
    asm("leave");
    asm("mov $0x0805e980, %eax");
    asm("jmp *%eax");
}

int CNWSPlayer::GetStoreGUIInfo()
{
    asm("leave");
    asm("mov $0x0805ec84, %eax");
    asm("jmp *%eax");
}

int CNWSPlayer::HasExpansionPack(unsigned char, int)
{
    asm("leave");
    asm("mov $0x0805ea80, %eax");
    asm("jmp *%eax");
}

CNWSCreature * CNWSPlayer::LoadCharacterFromIFO(unsigned long, int, int, int, int)
{
    asm("leave");
    asm("mov $0x0805489c, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSPlayer::LoadCreatureData(CResRef, CNWSCreature *)
{
    asm("leave");
    asm("mov $0x08055fec, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSPlayer::LoadDMCharacter()
{
    asm("leave");
    asm("mov $0x08055514, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSPlayer::LoadLocalCharacter()
{
    asm("leave");
    asm("mov $0x080547e0, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSPlayer::LoadServerCharacter(CResRef, int)
{
    asm("leave");
    asm("mov $0x080555f4, %eax");
    asm("jmp *%eax");
}

void CNWSPlayer::LoadTURDInfoFromIFO(unsigned long)
{
    asm("leave");
    asm("mov $0x0805507c, %eax");
    asm("jmp *%eax");
}

int CNWSPlayer::PackCreatureIntoMessage()
{
    asm("leave");
    asm("mov $0x0805d910, %eax");
    asm("jmp *%eax");
}

int CNWSPlayer::PermittedToDisplayCharacterSheet(unsigned long)
{
    asm("leave");
    asm("mov $0x0805e1f4, %eax");
    asm("jmp *%eax");
}

void CNWSPlayer::RestoreCameraSettings()
{
    asm("leave");
    asm("mov $0x0805eb14, %eax");
    asm("jmp *%eax");
}

int CNWSPlayer::SaveServerCharacter(int)
{
    asm("leave");
    asm("mov $0x080569d4, %eax");
    asm("jmp *%eax");
}

int CNWSPlayer::SetAlwaysRun(int)
{
    asm("leave");
    asm("mov $0x0805ed3c, %eax");
    asm("jmp *%eax");
}

void CNWSPlayer::SetAreaTransitionBMP(int, CExoString)
{
    asm("leave");
    asm("mov $0x0805e794, %eax");
    asm("jmp *%eax");
}

int CNWSPlayer::SetCharacterType(unsigned char)
{
    asm("leave");
    asm("mov $0x0805ed58, %eax");
    asm("jmp *%eax");
}

int CNWSPlayer::SetCommunityNameAuthorized(int)
{
    asm("leave");
    asm("mov $0x0805edb4, %eax");
    asm("jmp *%eax");
}

int CNWSPlayer::SetCutsceneState(int)
{
    asm("leave");
    asm("mov $0x0805ee64, %eax");
    asm("jmp *%eax");
}

void CNWSPlayer::SetFileName(CResRef)
{
    asm("leave");
    asm("mov $0x0805ed74, %eax");
    asm("jmp *%eax");
}

int CNWSPlayer::SetFloatyEffects(int)
{
    asm("leave");
    asm("mov $0x0805ed00, %eax");
    asm("jmp *%eax");
}

int CNWSPlayer::SetFromSaveGame(int)
{
    asm("leave");
    asm("mov $0x0805ec30, %eax");
    asm("jmp *%eax");
}

int CNWSPlayer::SetFromTURD(int)
{
    asm("leave");
    asm("mov $0x0805ec68, %eax");
    asm("jmp *%eax");
}

void CNWSPlayer::SetGameObject(CNWSObject *)
{
    asm("leave");
    asm("mov $0x0805df90, %eax");
    asm("jmp *%eax");
}

int CNWSPlayer::SetIFOCharacterIndex(unsigned long)
{
    asm("leave");
    asm("mov $0x0805ede8, %eax");
    asm("jmp *%eax");
}

int CNWSPlayer::SetIsPrimaryPlayer(int)
{
    asm("leave");
    asm("mov $0x0805ec14, %eax");
    asm("jmp *%eax");
}

int CNWSPlayer::SetLastObjectControlled(unsigned long)
{
    asm("leave");
    asm("mov $0x0805ebd4, %eax");
    asm("jmp *%eax");
}

int CNWSPlayer::SetLastUpdatedTime(unsigned long long)
{
    asm("leave");
    asm("mov $0x0805ebf4, %eax");
    asm("jmp *%eax");
}

int CNWSPlayer::SetLoginState(unsigned char)
{
    asm("leave");
    asm("mov $0x0805ebb8, %eax");
    asm("jmp *%eax");
}

int CNWSPlayer::SetModuleInfoSucceeded(int)
{
    asm("leave");
    asm("mov $0x0805edfc, %eax");
    asm("jmp *%eax");
}

int CNWSPlayer::SetPCObject(unsigned long)
{
    asm("leave");
    asm("mov $0x0805ee20, %eax");
    asm("jmp *%eax");
}

int CNWSPlayer::SetPlayModuleListingCharacters(int)
{
    asm("leave");
    asm("mov $0x0805ee48, %eax");
    asm("jmp *%eax");
}

int CNWSPlayer::SetPlayerListIndex(unsigned long)
{
    asm("leave");
    asm("mov $0x0805ec4c, %eax");
    asm("jmp *%eax");
}

void CNWSPlayer::StoreCameraSettings()
{
    asm("leave");
    asm("mov $0x0805eae8, %eax");
    asm("jmp *%eax");
}

void CNWSPlayer::StripAllInvalidItemPropertiesInInventory(CNWSCreature *)
{
    asm("leave");
    asm("mov $0x0805e278, %eax");
    asm("jmp *%eax");
}

void CNWSPlayer::StripAllInvalidItemPropertiesOnItem(CNWSItem *)
{
    asm("leave");
    asm("mov $0x0805e338, %eax");
    asm("jmp *%eax");
}

int CNWSPlayer::ValidateCharacter_SetNormalBonusFlags(unsigned short, int &, int &, unsigned char)
{
    asm("leave");
    asm("mov $0x0805e800, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSPlayer::ValidateCharacter(int *)
{
    asm("leave");
    asm("mov $0x080580bc, %eax");
    asm("jmp *%eax");
}

