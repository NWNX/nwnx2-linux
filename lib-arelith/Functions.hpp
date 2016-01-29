#ifndef NWNX_UNIFIED__FUNCTIONS_HPP
#define NWNX_UNIFIED__FUNCTIONS_HPP

#include <functional>

namespace Functions {

// public C2DA::C2DACResRef, int
extern void * const C2DA__C2DACtor__0;
// public C2DA::C2DAvoid
extern void * const C2DA__C2DACtor__1;
// public C2DA::~C2DAvoid
extern void * const C2DA__C2DADtor;
// public int C2DA::GetCExoStringEntryconst CExoString&, const CExoString&, CExoString*
extern void * const C2DA__GetCExoStringEntry__0;
// public int C2DA::GetCExoStringEntryint, const CExoString&, CExoString*
extern void * const C2DA__GetCExoStringEntry__1;
// public int C2DA::GetCExoStringEntryint, int, CExoString*
extern void * const C2DA__GetCExoStringEntry__2;
// public int C2DA::GetCExoStringEntryconst CExoString&, int, CExoString*
extern void * const C2DA__GetCExoStringEntry__3;
// public int C2DA::GetColumnIndexconst CExoString&
extern void * const C2DA__GetColumnIndex;
// public int C2DA::GetFLOATEntryint, int, float*
extern void * const C2DA__GetFLOATEntry__0;
// public int C2DA::GetFLOATEntryconst CExoString&, const CExoString&, float*
extern void * const C2DA__GetFLOATEntry__1;
// public int C2DA::GetFLOATEntryint, const CExoString&, float*
extern void * const C2DA__GetFLOATEntry__2;
// public int C2DA::GetFLOATEntryconst CExoString&, int, float*
extern void * const C2DA__GetFLOATEntry__3;
// public int C2DA::GetINTEntryint, const CExoString&, int*
extern void * const C2DA__GetINTEntry__0;
// public int C2DA::GetINTEntryconst CExoString&, int, int*
extern void * const C2DA__GetINTEntry__1;
// public int C2DA::GetINTEntryint, int, int*
extern void * const C2DA__GetINTEntry__2;
// public int C2DA::GetINTEntryconst CExoString&, const CExoString&, int*
extern void * const C2DA__GetINTEntry__3;
// void C2DA::GetNextLineLengthchar*, unsigned long int
extern void * const C2DA__GetNextLineLength;
// protected int C2DA::GetNextTokenchar**, unsigned long int*, char*, unsigned long int*
extern void * const C2DA__GetNextToken;
// void C2DA::GetNumColumnsvoid
extern void * const C2DA__GetNumColumns;
// void C2DA::GetNumRowsvoid
extern void * const C2DA__GetNumRows;
// void C2DA::GetRowIndexconst CExoString&
extern void * const C2DA__GetRowIndex;
// public int C2DA::Load2DArrayvoid
extern void * const C2DA__Load2DArray;
// void C2DA::SetBlankEntryCExoString, CExoString
extern void * const C2DA__SetBlankEntry__0;
// void C2DA::SetBlankEntryint, CExoString
extern void * const C2DA__SetBlankEntry__1;
// void C2DA::SetBlankEntryint, int
extern void * const C2DA__SetBlankEntry__2;
// void C2DA::SetBlankEntryCExoString, int
extern void * const C2DA__SetBlankEntry__3;
// void C2DA::SetCExoStringEntryCExoString, CExoString, CExoString
extern void * const C2DA__SetCExoStringEntry__0;
// void C2DA::SetCExoStringEntryint, CExoString, CExoString
extern void * const C2DA__SetCExoStringEntry__1;
// void C2DA::SetCExoStringEntryCExoString, int, CExoString
extern void * const C2DA__SetCExoStringEntry__2;
// void C2DA::SetCExoStringEntryint, int, CExoString
extern void * const C2DA__SetCExoStringEntry__3;
// void C2DA::SetFLOATEntryCExoString, CExoString, float
extern void * const C2DA__SetFLOATEntry__0;
// void C2DA::SetFLOATEntryint, CExoString, float
extern void * const C2DA__SetFLOATEntry__1;
// void C2DA::SetFLOATEntryint, int, float
extern void * const C2DA__SetFLOATEntry__2;
// void C2DA::SetFLOATEntryCExoString, int, float
extern void * const C2DA__SetFLOATEntry__3;
// void C2DA::SetINTEntryCExoString, CExoString, int
extern void * const C2DA__SetINTEntry__0;
// void C2DA::SetINTEntryint, CExoString, int
extern void * const C2DA__SetINTEntry__1;
// void C2DA::SetINTEntryint, int, int
extern void * const C2DA__SetINTEntry__2;
// void C2DA::SetINTEntryCExoString, int, int
extern void * const C2DA__SetINTEntry__3;
// protected int C2DA::SkipNewLineschar**, unsigned long int*
extern void * const C2DA__SkipNewLines;
// public void C2DA::Unload2DArrayvoid
extern void * const C2DA__Unload2DArray;

// public CAppManager::CAppManagervoid
extern void * const CAppManager__CAppManagerCtor;
// public CAppManager::~CAppManagervoid
extern void * const CAppManager__CAppManagerDtor;
// public void CAppManager::CreateServervoid
extern void * const CAppManager__CreateServer;
// public void CAppManager::DestroyScriptDebuggerPopupvoid
extern void * const CAppManager__DestroyScriptDebuggerPopup;
// public void CAppManager::DestroyServervoid
extern void * const CAppManager__DestroyServer;
// public void CAppManager::DisplayScriptDebuggerPopupvoid
extern void * const CAppManager__DisplayScriptDebuggerPopup;
// public void CAppManager::DoSaveGameScreenShotCExoString&
extern void * const CAppManager__DoSaveGameScreenShot;
// public int CAppManager::GetDungeonMasterEXERunningvoid
extern void * const CAppManager__GetDungeonMasterEXERunning;
// public CObjectTableManager* CAppManager::GetObjectTableManagerunsigned long int
extern void * const CAppManager__GetObjectTableManager;
// public unsigned char CAppManager::GetProgressFromCodewordCExoString&
extern void * const CAppManager__GetProgressFromCodeword;
// public unsigned char CAppManager::ReadProgressFromINIunsigned char
extern void * const CAppManager__ReadProgressFromINI;
// void CAppManager::SetDungeonMasterEXERunningint
extern void * const CAppManager__SetDungeonMasterEXERunning;
// void CAppManager::ShowServerMemvoid
extern void * const CAppManager__ShowServerMem;
// public int CAppManager::SpawnExternalScriptDebuggervoid
extern void * const CAppManager__SpawnExternalScriptDebugger;

// public CBWCBlowFish::CBWCBlowFishvoid
extern void * const CBWCBlowFish__CBWCBlowFishCtor__0;
// public CBWCBlowFish::CBWCBlowFishconst CBWCBlowFish&
extern void * const CBWCBlowFish__CBWCBlowFishCtor__1;
// public CBWCBlowFish::~CBWCBlowFishvoid
extern void * const CBWCBlowFish__CBWCBlowFishDtor;
// private void CBWCBlowFish::BlockToBytesconst CBWCBlowFishBlock&, unsigned char*
extern void * const CBWCBlowFish__BlockToBytes;
// private void CBWCBlowFish::BytesToBlockconst unsigned char*, CBWCBlowFishBlock&
extern void * const CBWCBlowFish__BytesToBlock;
// public int CBWCBlowFish::Decryptunsigned char*, unsigned long int, unsigned char*, unsigned long int&, unsigned char&
extern void * const CBWCBlowFish__Decrypt__0;
// public int CBWCBlowFish::Decryptunsigned char*, unsigned long int, unsigned long int&, unsigned char&
extern void * const CBWCBlowFish__Decrypt__1;
// private void CBWCBlowFish::DecryptBlockCBWCBlowFishBlock&
extern void * const CBWCBlowFish__DecryptBlock;
// public int CBWCBlowFish::Encryptunsigned char*, unsigned long int, unsigned char*, unsigned long int&, unsigned char&
extern void * const CBWCBlowFish__Encrypt__0;
// public int CBWCBlowFish::Encryptunsigned char*, unsigned long int, unsigned long int&, unsigned char&
extern void * const CBWCBlowFish__Encrypt__1;
// private void CBWCBlowFish::EncryptBlockCBWCBlowFishBlock&
extern void * const CBWCBlowFish__EncryptBlock;
// private unsigned long int CBWCBlowFish::Funsigned long int
extern void * const CBWCBlowFish__F;
// public int CBWCBlowFish::GetDecryptedSizeunsigned long int, unsigned long int&
extern void * const CBWCBlowFish__GetDecryptedSize;
// public int CBWCBlowFish::GetEncryptedSizeunsigned long int, unsigned long int&
extern void * const CBWCBlowFish__GetEncryptedSize;
// private unsigned char CBWCBlowFish::GetLowOrderByteunsigned long int
extern void * const CBWCBlowFish__GetLowOrderByte;
// public int CBWCBlowFish::GetStatevoid*
extern void * const CBWCBlowFish__GetState;
// public int CBWCBlowFish::GetStateSizeunsigned long int&
extern void * const CBWCBlowFish__GetStateSize;
// void CBWCBlowFish::ResetChainvoid
extern void * const CBWCBlowFish__ResetChain;
// public int CBWCBlowFish::ResetKeyvoid
extern void * const CBWCBlowFish__ResetKey;
// public int CBWCBlowFish::SetKeyunsigned char*, unsigned long int, unsigned char&
extern void * const CBWCBlowFish__SetKey;
// public int CBWCBlowFish::SetStatevoid*, unsigned long int
extern void * const CBWCBlowFish__SetState;

// public CBWCBlowFishBlock::CBWCBlowFishBlockunsigned long int, unsigned long int
extern void * const CBWCBlowFishBlock__CBWCBlowFishBlockCtor__0;
// public CBWCBlowFishBlock::CBWCBlowFishBlockconst CBWCBlowFishBlock&
extern void * const CBWCBlowFishBlock__CBWCBlowFishBlockCtor__1;
// public CBWCBlowFishBlock::~CBWCBlowFishBlockvoid
extern void * const CBWCBlowFishBlock__CBWCBlowFishBlockDtor;
// void CBWCBlowFishBlock::__aerCBWCBlowFishBlock&
extern void * const CBWCBlowFishBlock____aer;

// public CBWCBlowFishState::CBWCBlowFishStateconst CBWCBlowFishState&
extern void * const CBWCBlowFishState__CBWCBlowFishStateCtor__0;
// public CBWCBlowFishState::CBWCBlowFishStateCBWCBlowFishBlock
extern void * const CBWCBlowFishState__CBWCBlowFishStateCtor__1;
// public CBWCBlowFishState::~CBWCBlowFishStatevoid
extern void * const CBWCBlowFishState__CBWCBlowFishStateDtor;
// void CBWCBlowFishState::GetChainvoid
extern void * const CBWCBlowFishState__GetChain;
// void CBWCBlowFishState::ResetChainvoid
extern void * const CBWCBlowFishState__ResetChain;
// void CBWCBlowFishState::SetChainCBWCBlowFishBlock
extern void * const CBWCBlowFishState__SetChain;

// public CBWCMD5::CBWCMD5void
extern void * const CBWCMD5__CBWCMD5Ctor;
// public CBWCMD5::~CBWCMD5void
extern void * const CBWCMD5__CBWCMD5Dtor;
// public int CBWCMD5::Decryptunsigned char*, unsigned long int, unsigned char*, unsigned long int&, unsigned char&
extern void * const CBWCMD5__Decrypt__0;
// public int CBWCMD5::Decryptunsigned char*, unsigned long int, unsigned long int&, unsigned char&
extern void * const CBWCMD5__Decrypt__1;
// public int CBWCMD5::Encryptunsigned char*, unsigned long int, unsigned char*, unsigned long int&, unsigned char&
extern void * const CBWCMD5__Encrypt__0;
// public int CBWCMD5::Encryptunsigned char*, unsigned long int, unsigned long int&, unsigned char&
extern void * const CBWCMD5__Encrypt__1;
// private void CBWCMD5::EncryptBlockconst unsigned long int*
extern void * const CBWCMD5__EncryptBlock;
// private void CBWCMD5::EncryptFinalBlockconst unsigned long int*, unsigned long int
extern void * const CBWCMD5__EncryptFinalBlock;
// private unsigned long int CBWCMD5::Funsigned long int, unsigned long int, unsigned long int
extern void * const CBWCMD5__F;
// private unsigned long int CBWCMD5::Gunsigned long int, unsigned long int, unsigned long int
extern void * const CBWCMD5__G;
// public int CBWCMD5::GetDecryptedSizeunsigned long int, unsigned long int&
extern void * const CBWCMD5__GetDecryptedSize;
// public int CBWCMD5::GetEncryptedSizeunsigned long int, unsigned long int&
extern void * const CBWCMD5__GetEncryptedSize;
// public int CBWCMD5::GetStatevoid*
extern void * const CBWCMD5__GetState;
// public int CBWCMD5::GetStateSizeunsigned long int&
extern void * const CBWCMD5__GetStateSize;
// private unsigned long int CBWCMD5::Hunsigned long int, unsigned long int, unsigned long int
extern void * const CBWCMD5__H;
// private unsigned long int CBWCMD5::Iunsigned long int, unsigned long int, unsigned long int
extern void * const CBWCMD5__I;
// public void CBWCMD5::Resetvoid
extern void * const CBWCMD5__Reset;
// public int CBWCMD5::SetKeyunsigned char*, unsigned long int, unsigned char&
extern void * const CBWCMD5__SetKey;
// public int CBWCMD5::SetStatevoid*, unsigned long int
extern void * const CBWCMD5__SetState;

// public CCodeBase::CCodeBasevoid
extern void * const CCodeBase__CCodeBaseCtor;
// public CCodeBase::~CCodeBasevoid
extern void * const CCodeBase__CCodeBaseDtor;
// public int CCodeBase::AddBinaryDataCExoString&, CExoString&, CExoString&, char, void*, int
extern void * const CCodeBase__AddBinaryData;
// public int CCodeBase::AddFloatCExoString&, CExoString&, CExoString&, float
extern void * const CCodeBase__AddFloat;
// public int CCodeBase::AddIntCExoString&, CExoString&, CExoString&, int
extern void * const CCodeBase__AddInt;
// public int CCodeBase::AddLocationCExoString&, CExoString&, CExoString&, const CScriptLocation&
extern void * const CCodeBase__AddLocation;
// public int CCodeBase::AddStringCExoString&, CExoString&, CExoString&, CExoString&
extern void * const CCodeBase__AddString;
// public int CCodeBase::AddVectorCExoString&, CExoString&, CExoString&, const Vector&
extern void * const CCodeBase__AddVector;
// void CCodeBase::CloseAllFilesvoid
extern void * const CCodeBase__CloseAllFiles;
// public int CCodeBase::DeleteVarCExoString&, CExoString&, CExoString&
extern void * const CCodeBase__DeleteVar;
// public void CCodeBase::DestroyDatabaseCExoString&
extern void * const CCodeBase__DestroyDatabase;
// public void* CCodeBase::GetBinaryDataCExoString&, CExoString&, CExoString&, char&, int&
extern void * const CCodeBase__GetBinaryData;
// public float CCodeBase::GetFloatCExoString&, CExoString&, CExoString&
extern void * const CCodeBase__GetFloat;
// public int CCodeBase::GetIntCExoString&, CExoString&, CExoString&
extern void * const CCodeBase__GetInt;
// public CScriptLocation* CCodeBase::GetLocationCExoString&, CExoString&, CExoString&
extern void * const CCodeBase__GetLocation;
// public CExoString* CCodeBase::GetStringCExoString&, CExoString&, CExoString&
extern void * const CCodeBase__GetString;
// public Vector* CCodeBase::GetVectorCExoString&, CExoString&, CExoString&
extern void * const CCodeBase__GetVector;

// public CCodeBaseInternal::CCodeBaseInternalvoid
extern void * const CCodeBaseInternal__CCodeBaseInternalCtor;
// public CCodeBaseInternal::~CCodeBaseInternalvoid
extern void * const CCodeBaseInternal__CCodeBaseInternalDtor;
// public int CCodeBaseInternal::AddBinaryDataCExoString&, CExoString&, CExoString&, char, void*, int
extern void * const CCodeBaseInternal__AddBinaryData;
// public int CCodeBaseInternal::AddFloatCExoString&, CExoString&, CExoString&, float
extern void * const CCodeBaseInternal__AddFloat;
// public int CCodeBaseInternal::AddIntCExoString&, CExoString&, CExoString&, int
extern void * const CCodeBaseInternal__AddInt;
// public int CCodeBaseInternal::AddLocationCExoString&, CExoString&, CExoString&, const CScriptLocation&
extern void * const CCodeBaseInternal__AddLocation;
// public int CCodeBaseInternal::AddStringCExoString&, CExoString&, CExoString&, CExoString&
extern void * const CCodeBaseInternal__AddString;
// protected int CCodeBaseInternal::AddVarEndSCodeBaseData*, int
extern void * const CCodeBaseInternal__AddVarEnd;
// protected int CCodeBaseInternal::AddVarStartSCodeBaseData*, CExoString&, CExoString&, int&
extern void * const CCodeBaseInternal__AddVarStart;
// public int CCodeBaseInternal::AddVectorCExoString&, CExoString&, CExoString&, const Vector&
extern void * const CCodeBaseInternal__AddVector;
// public void CCodeBaseInternal::CloseAllFilesvoid
extern void * const CCodeBaseInternal__CloseAllFiles;
// protected void CCodeBaseInternal::CloseFileint
extern void * const CCodeBaseInternal__CloseFile;
// public int CCodeBaseInternal::DeleteVarCExoString&, CExoString&, CExoString&
extern void * const CCodeBaseInternal__DeleteVar;
// public void CCodeBaseInternal::DestroyDatabaseCExoString&
extern void * const CCodeBaseInternal__DestroyDatabase;
// public void* CCodeBaseInternal::GetBinaryDataCExoString&, CExoString&, CExoString&, char&, int&
extern void * const CCodeBaseInternal__GetBinaryData;
// protected SCodeBaseData* CCodeBaseInternal::GetFileCExoString&, int
extern void * const CCodeBaseInternal__GetFile;
// public float CCodeBaseInternal::GetFloatCExoString&, CExoString&, CExoString&
extern void * const CCodeBaseInternal__GetFloat;
// public int CCodeBaseInternal::GetIntCExoString&, CExoString&, CExoString&
extern void * const CCodeBaseInternal__GetInt;
// public CScriptLocation* CCodeBaseInternal::GetLocationCExoString&, CExoString&, CExoString&
extern void * const CCodeBaseInternal__GetLocation;
// public CExoString* CCodeBaseInternal::GetStringCExoString&, CExoString&, CExoString&
extern void * const CCodeBaseInternal__GetString;
// void CCodeBaseInternal::GetVarSCodeBaseData*, CExoString&, CExoString&
extern void * const CCodeBaseInternal__GetVar;
// public Vector* CCodeBaseInternal::GetVectorCExoString&, CExoString&, CExoString&
extern void * const CCodeBaseInternal__GetVector;
// protected int CCodeBaseInternal::OpenFileCExoString&, int
extern void * const CCodeBaseInternal__OpenFile;

// public CCombatInformation::CCombatInformationvoid
extern void * const CCombatInformation__CCombatInformationCtor;
// public CCombatInformation::~CCombatInformationvoid
extern void * const CCombatInformation__CCombatInformationDtor;
// void CCombatInformation::__asCCombatInformation&
extern void * const CCombatInformation____as;
// void CCombatInformation::__eqCCombatInformation&
extern void * const CCombatInformation____eq;
// void CCombatInformation::__neCCombatInformation&
extern void * const CCombatInformation____ne;
// public int CCombatInformation::LoadDataCResGFF*, CResStruct*
extern void * const CCombatInformation__LoadData;
// public int CCombatInformation::SaveDataCResGFF*, CResStruct*
extern void * const CCombatInformation__SaveData;

// public CCombatInformationNode::CCombatInformationNodevoid
extern void * const CCombatInformationNode__CCombatInformationNodeCtor;
// void CCombatInformationNode::__asconst CCombatInformationNode&
extern void * const CCombatInformationNode____as;
// void CCombatInformationNode::__eqCCombatInformationNode&
extern void * const CCombatInformationNode____eq;
// void CCombatInformationNode::__neCCombatInformationNode&
extern void * const CCombatInformationNode____ne;

// public CConnectionLib::CConnectionLibCBaseExoApp*
extern void * const CConnectionLib__CConnectionLibCtor;
// public CConnectionLib::~CConnectionLibvoid
extern void * const CConnectionLib__CConnectionLibDtor;
// void CConnectionLib::AddServervoid*, char*, char*, int, int, int, int, char*, int, int, char*, int, int, int, char*, char*, int, int, int, int, int, bool
extern void * const CConnectionLib__AddServer;
// void CConnectionLib::ChatNameMangleCExoString&
extern void * const CConnectionLib__ChatNameMangle;
// void CConnectionLib::ClearServersvoid
extern void * const CConnectionLib__ClearServers;
// void CConnectionLib::ClientConnectToGameSpyconst CExoString&
extern void * const CConnectionLib__ClientConnectToGameSpy;
// void CConnectionLib::ErrorClientShuttingDownunsigned char
extern void * const CConnectionLib__ErrorClientShuttingDown;
// public CExoString CConnectionLib::GenerateCommunityNameResponseconst CExoString&, const CExoString&
extern void * const CConnectionLib__GenerateCommunityNameResponse;
// void CConnectionLib::GenerateResponseconst CExoString&, const CExoString&, CExoString&, CExoString&
extern void * const CConnectionLib__GenerateResponse;
// void CConnectionLib::GetAvailabilityvoid
extern void * const CConnectionLib__GetAvailability;
// void CConnectionLib::GetAvailabilityStatusvoid
extern void * const CConnectionLib__GetAvailabilityStatus;
// void CConnectionLib::GetClientConnectionPhasevoid
extern void * const CConnectionLib__GetClientConnectionPhase;
// void CConnectionLib::GetClientErrorvoid
extern void * const CConnectionLib__GetClientError;
// public unsigned short int CConnectionLib::GetCommunityNameStatusconst CExoString&, unsigned char**
extern void * const CConnectionLib__GetCommunityNameStatus;
// void CConnectionLib::GetDigiDistModuleCipherCExoString&, int
extern void * const CConnectionLib__GetDigiDistModuleCipher;
// void CConnectionLib::GetGameFiltersCExoString*
extern void * const CConnectionLib__GetGameFilters;
// void CConnectionLib::GetGameTypeFromGroupIdint
extern void * const CConnectionLib__GetGameTypeFromGroupId;
// public int CConnectionLib::GetGroupIdFromGameTypeint
extern void * const CConnectionLib__GetGroupIdFromGameType;
// void CConnectionLib::GetGSClientGameRegionvoid
extern void * const CConnectionLib__GetGSClientGameRegion;
// public CExoString CConnectionLib::GetKeyAuthDemandCExoString&
extern void * const CConnectionLib__GetKeyAuthDemand;
// public CExoString CConnectionLib::GetKeyCollisionvoid
extern void * const CConnectionLib__GetKeyCollision;
// public unsigned long int CConnectionLib::GetKeyRejectionReasonunsigned short int
extern void * const CConnectionLib__GetKeyRejectionReason;
// public unsigned short int CConnectionLib::GetKeyStatusconst CExoString&, unsigned short int&
extern void * const CConnectionLib__GetKeyStatus;
// public CExoString CConnectionLib::GetMasterServerInternetNamevoid
extern void * const CConnectionLib__GetMasterServerInternetName;
// public unsigned long int CConnectionLib::GetMasterServerPortvoid
extern void * const CConnectionLib__GetMasterServerPort;
// public unsigned short int CConnectionLib::GetMasterServerStatusvoid
extern void * const CConnectionLib__GetMasterServerStatus;
// void CConnectionLib::GetMessageOfTheDayvoid
extern void * const CConnectionLib__GetMessageOfTheDay;
// public unsigned long int CConnectionLib::GetMessagesInvoid
extern void * const CConnectionLib__GetMessagesIn;
// public int CConnectionLib::GetNetConnectionUpvoid
extern void * const CConnectionLib__GetNetConnectionUp;
// public CNetLayer* CConnectionLib::GetNetLayervoid
extern void * const CConnectionLib__GetNetLayer;
// void CConnectionLib::GetNextBuddyEntryvoid
extern void * const CConnectionLib__GetNextBuddyEntry;
// public CExoString CConnectionLib::GetPublicPartFromCDKeyconst CExoString&
extern void * const CConnectionLib__GetPublicPartFromCDKey;
// public unsigned long int CConnectionLib::GetStrrefFromGameTypeint
extern void * const CConnectionLib__GetStrrefFromGameType;
// void CConnectionLib::GetStrrefFromGroupIdint
extern void * const CConnectionLib__GetStrrefFromGroupId;
// void CConnectionLib::GetVersionvoid
extern void * const CConnectionLib__GetVersion;
// void CConnectionLib::GetVersionNumbervoid
extern void * const CConnectionLib__GetVersionNumber;
// void CConnectionLib::GSClientGetBuildFiltervoid
extern void * const CConnectionLib__GSClientGetBuildFilter;
// void CConnectionLib::GSClientGetGroupRoomNumbervoid
extern void * const CConnectionLib__GSClientGetGroupRoomNumber;
// void CConnectionLib::GSClientGroupRoomAddedint, unsigned long int
extern void * const CConnectionLib__GSClientGroupRoomAdded;
// void CConnectionLib::GSClientJoinGroupRoomint
extern void * const CConnectionLib__GSClientJoinGroupRoom;
// void CConnectionLib::GSClientMessageint, const CExoString&, const CExoString&
extern void * const CConnectionLib__GSClientMessage;
// void CConnectionLib::GSClientRoomPlayerChangeint, const CExoString&, const CExoString&
extern void * const CConnectionLib__GSClientRoomPlayerChange;
// void CConnectionLib::GSClientSetBuildFilterconst CExoString&
extern void * const CConnectionLib__GSClientSetBuildFilter;
// public void CConnectionLib::HandleGameSpyToServerMessageint, void*, int
extern void * const CConnectionLib__HandleGameSpyToServerMessage;
// public int CConnectionLib::HandleMasterServerToGameMessageunsigned char*, unsigned long int
extern void * const CConnectionLib__HandleMasterServerToGameMessage;
// public int CConnectionLib::HandleServerGameSpyMessageunsigned long int, unsigned char*, unsigned long int
extern void * const CConnectionLib__HandleServerGameSpyMessage;
// public void CConnectionLib::InitializeGameSpyRoomsvoid
extern void * const CConnectionLib__InitializeGameSpyRooms;
// void CConnectionLib::NewClientChallengeunsigned long int
extern void * const CConnectionLib__NewClientChallenge;
// void CConnectionLib::RemoveServervoid*
extern void * const CConnectionLib__RemoveServer;
// public void CConnectionLib::ResetMessagesInFlagunsigned long int
extern void * const CConnectionLib__ResetMessagesInFlag;
// void CConnectionLib::SendAddBuddyRequestconst CExoString&, const CExoString&
extern void * const CConnectionLib__SendAddBuddyRequest;
// void CConnectionLib::SendClientToMasterCreateAccountPartOneconst CExoString&
extern void * const CConnectionLib__SendClientToMasterCreateAccountPartOne;
// void CConnectionLib::SendClientToMasterCreateAccountPartTwoconst CExoString&, const CExoString&, const CExoString&, unsigned char*, const CExoString&
extern void * const CConnectionLib__SendClientToMasterCreateAccountPartTwo;
// void CConnectionLib::SendClientToMasterMOTDRequestunsigned short int
extern void * const CConnectionLib__SendClientToMasterMOTDRequest;
// void CConnectionLib::SendClientToMasterVersionRequestunsigned short int
extern void * const CConnectionLib__SendClientToMasterVersionRequest;
// void CConnectionLib::SendDigiDistAuthRequestCExoArrayListTemplatedCExoString*, const CExoString&
extern void * const CConnectionLib__SendDigiDistAuthRequest;
// public int CConnectionLib::SendGameToMasterAuthorizationRequestunsigned long int, int
extern void * const CConnectionLib__SendGameToMasterAuthorizationRequest__0;
// public int CConnectionLib::SendGameToMasterAuthorizationRequestvoid*, int
extern void * const CConnectionLib__SendGameToMasterAuthorizationRequest__1;
// public int CConnectionLib::SendGameToMasterCommunityNameAuthconst CExoString&, const CExoString&, const CExoString&, unsigned short int, unsigned char
extern void * const CConnectionLib__SendGameToMasterCommunityNameAuth;
// public int CConnectionLib::SendGameToMasterDisconnectvoid*, int
extern void * const CConnectionLib__SendGameToMasterDisconnect__0;
// public int CConnectionLib::SendGameToMasterDisconnectunsigned long int
extern void * const CConnectionLib__SendGameToMasterDisconnect__1;
// public int CConnectionLib::SendGameToMasterHeartbeatvoid*, int
extern void * const CConnectionLib__SendGameToMasterHeartbeat;
// public int CConnectionLib::SendGameToMasterModuleunsigned char, const CExoString&
extern void * const CConnectionLib__SendGameToMasterModule;
// public int CConnectionLib::SendGameToMasterShutDownvoid
extern void * const CConnectionLib__SendGameToMasterShutDown;
// public int CConnectionLib::SendGameToMasterStartupunsigned char, unsigned long int, int, unsigned char, unsigned char
extern void * const CConnectionLib__SendGameToMasterStartup;
// public int CConnectionLib::SendGameToMasterStatusRequestvoid
extern void * const CConnectionLib__SendGameToMasterStatusRequest;
// void CConnectionLib::SendGetAvailabilityRequestconst CExoString&
extern void * const CConnectionLib__SendGetAvailabilityRequest;
// void CConnectionLib::SendGetBuddyListRequestconst CExoString&
extern void * const CConnectionLib__SendGetBuddyListRequest;
// void CConnectionLib::SendMessageToNickconst char*, const char*
extern void * const CConnectionLib__SendMessageToNick;
// void CConnectionLib::SendMessageToRoomconst char*
extern void * const CConnectionLib__SendMessageToRoom;
// void CConnectionLib::SendRemoveBuddyRequestconst CExoString&, const CExoString&
extern void * const CConnectionLib__SendRemoveBuddyRequest;
// void CConnectionLib::SendSetAvailabilityRequestconst CExoString&, unsigned short int
extern void * const CConnectionLib__SendSetAvailabilityRequest;
// public int CConnectionLib::ServerConnectToGameSpyunsigned int
extern void * const CConnectionLib__ServerConnectToGameSpy;
// void CConnectionLib::SetGameFiltersunsigned long int, CExoString*
extern void * const CConnectionLib__SetGameFilters;
// void CConnectionLib::SetGSClientGameRegionint
extern void * const CConnectionLib__SetGSClientGameRegion;
// public void CConnectionLib::SetLanguageint
extern void * const CConnectionLib__SetLanguage;
// public void CConnectionLib::SetNetConnectionUpint
extern void * const CConnectionLib__SetNetConnectionUp;
// void CConnectionLib::ShutDownClientGameSpyConnectionvoid
extern void * const CConnectionLib__ShutDownClientGameSpyConnection;
// public void CConnectionLib::ShutDownServerGameSpyConnectionvoid
extern void * const CConnectionLib__ShutDownServerGameSpyConnection;
// public void CConnectionLib::StartMstHeartbeatTimerunsigned long long int
extern void * const CConnectionLib__StartMstHeartbeatTimer;
// public void CConnectionLib::StartSystemUpdateTimerunsigned long long int
extern void * const CConnectionLib__StartSystemUpdateTimer;
// public void CConnectionLib::StartTimeOutTimerunsigned long long int
extern void * const CConnectionLib__StartTimeOutTimer;
// public int CConnectionLib::TimeOutTimerRunningvoid
extern void * const CConnectionLib__TimeOutTimerRunning;
// void CConnectionLib::UpdateConnectionPhaseunsigned char, const CExoString&
extern void * const CConnectionLib__UpdateConnectionPhase;
// void CConnectionLib::UpdateGameSpyClientvoid
extern void * const CConnectionLib__UpdateGameSpyClient;
// public void CConnectionLib::UpdateGameSpyServervoid
extern void * const CConnectionLib__UpdateGameSpyServer;
// public int CConnectionLib::UpdateMstHeartbeatTimerunsigned long long int
extern void * const CConnectionLib__UpdateMstHeartbeatTimer;
// void CConnectionLib::UpdateServervoid*, char*, char*, int, int, int, int, char*, int, int, char*, int, int, int, char*, char*, int, int, int, int, int, bool
extern void * const CConnectionLib__UpdateServer;
// public int CConnectionLib::UpdateSystemUpdateTimerunsigned long long int
extern void * const CConnectionLib__UpdateSystemUpdateTimer;
// public int CConnectionLib::UpdateTimeOutTimerunsigned long long int
extern void * const CConnectionLib__UpdateTimeOutTimer;
// void CConnectionLib::ValidateCdKeychar*
extern void * const CConnectionLib__ValidateCdKey;

// void CDUtil::CalculateCRCchar*, int, char*, int, char*, int
extern void * const CDUtil__CalculateCRC;
// void CDUtil::CreateChallengeStringunsigned long int
extern void * const CDUtil__CreateChallengeString;
// void CDUtil::DecodeBasechar*, int
extern void * const CDUtil__DecodeBase;
// void CDUtil::EncodeBaseunsigned long long int, char*, int
extern void * const CDUtil__EncodeBase;
// void CDUtil::GenerateResponseconst CExoString&, const CExoString&, CExoString&, CExoString&
extern void * const CDUtil__GenerateResponse;
// void CDUtil::Initializevoid
extern void * const CDUtil__Initialize;
// void CDUtil::InitializeBaseConvertvoid
extern void * const CDUtil__InitializeBaseConvert;
// void CDUtil::InitializeCrcvoid
extern void * const CDUtil__InitializeCrc;
// void CDUtil::ScrambleKeychar*, const char*, const char*, const char*, int
extern void * const CDUtil__ScrambleKey;
// void CDUtil::UnScrambleKeyconst char*, char*, char*, char*
extern void * const CDUtil__UnScrambleKey;
// void CDUtil::ValidateKeychar*
extern void * const CDUtil__ValidateKey;

// public CERFFile::CERFFilevoid
extern void * const CERFFile__CERFFileCtor;
// public CERFFile::~CERFFilevoid
extern void * const CERFFile__CERFFileDtor;
// void CERFFile::AddResourcechar*, unsigned short int, CRes*
extern void * const CERFFile__AddResource__0;
// void CERFFile::AddResourceCExoString&
extern void * const CERFFile__AddResource__1;
// public int CERFFile::AddStringCERFString*
extern void * const CERFFile__AddString;
// public int CERFFile::CreateCExoString&
extern void * const CERFFile__Create;
// public int CERFFile::Finishvoid
extern void * const CERFFile__Finish;
// void CERFFile::Readvoid
extern void * const CERFFile__Read;
// void CERFFile::ReadModuleDescriptionconst CExoString&, unsigned short int, unsigned long int*, CExoString*
extern void * const CERFFile__ReadModuleDescription;
// void CERFFile::RecalculateOffsetsvoid
extern void * const CERFFile__RecalculateOffsets;
// void CERFFile::RemoveResourceCExoString&, unsigned short int
extern void * const CERFFile__RemoveResource__0;
// void CERFFile::RemoveResourceCERFRes*
extern void * const CERFFile__RemoveResource__1;
// public int CERFFile::Resetvoid
extern void * const CERFFile__Reset;
// public int CERFFile::SetNumEntriesunsigned long int
extern void * const CERFFile__SetNumEntries;
// public void CERFFile::SetVersionchar*
extern void * const CERFFile__SetVersion;
// void CERFFile::WriteCExoString&
extern void * const CERFFile__Write;
// public int CERFFile::WriteHeadervoid
extern void * const CERFFile__WriteHeader;
// public int CERFFile::WriteResourcechar*, unsigned short int, CRes*, int
extern void * const CERFFile__WriteResource;
// public int CERFFile::WriteStringTablevoid
extern void * const CERFFile__WriteStringTable;

// CERFKey::CERFKeyvoid
extern void * const CERFKey__CERFKeyCtor;
// public CERFKey::~CERFKeyvoid
extern void * const CERFKey__CERFKeyDtor;
// void CERFKey::Readvoid
extern void * const CERFKey__Read;
// void CERFKey::Resetvoid
extern void * const CERFKey__Reset;
// void CERFKey::SetNameCExoString&
extern void * const CERFKey__SetName;
// void CERFKey::WriteCExoFile&
extern void * const CERFKey__Write;

// CERFRes::CERFResvoid
extern void * const CERFRes__CERFResCtor;
// public CERFRes::~CERFResvoid
extern void * const CERFRes__CERFResDtor;
// void CERFRes::Readvoid
extern void * const CERFRes__Read;
// void CERFRes::Resetvoid
extern void * const CERFRes__Reset;
// void CERFRes::WriteCExoFile&, unsigned long int
extern void * const CERFRes__Write;

// public CERFString::CERFStringvoid
extern void * const CERFString__CERFStringCtor;
// public CERFString::~CERFStringvoid
extern void * const CERFString__CERFStringDtor;
// public CExoString CERFString::GetTextvoid
extern void * const CERFString__GetText;
// void CERFString::Readvoid
extern void * const CERFString__Read;
// void CERFString::Resetvoid
extern void * const CERFString__Reset;
// public void CERFString::SetTextCExoString&
extern void * const CERFString__SetText;
// void CERFString::WriteCExoFile&
extern void * const CERFString__Write;

// public CExoAliasList::CExoAliasListvoid
extern void * const CExoAliasList__CExoAliasListCtor;
// public CExoAliasList::~CExoAliasListvoid
extern void * const CExoAliasList__CExoAliasListDtor;
// public void CExoAliasList::AddCExoString, CExoString
extern void * const CExoAliasList__Add;
// void CExoAliasList::Clearvoid
extern void * const CExoAliasList__Clear;
// public void CExoAliasList::DeleteCExoString
extern void * const CExoAliasList__Delete;
// public const CExoString& CExoAliasList::GetAliasPathconst CExoString&, int const
extern void * const CExoAliasList__GetAliasPath;
// public CExoString CExoAliasList::ResolveFileNameconst CExoString&, unsigned short int const
extern void * const CExoAliasList__ResolveFileName;

// public CExoAliasListInternal::CExoAliasListInternalvoid
extern void * const CExoAliasListInternal__CExoAliasListInternalCtor;
// public CExoAliasListInternal::~CExoAliasListInternalvoid
extern void * const CExoAliasListInternal__CExoAliasListInternalDtor;
// public void CExoAliasListInternal::AddCExoString, CExoString
extern void * const CExoAliasListInternal__Add;
// void CExoAliasListInternal::Clearvoid
extern void * const CExoAliasListInternal__Clear;
// public void CExoAliasListInternal::DeleteCExoString
extern void * const CExoAliasListInternal__Delete;
// public const CExoString& CExoAliasListInternal::GetAliasPathconst CExoString&, int const
extern void * const CExoAliasListInternal__GetAliasPath;
// public CExoString CExoAliasListInternal::ResolveFileNameconst CExoString&, unsigned short int const
extern void * const CExoAliasListInternal__ResolveFileName;

// CExoArrayListTemplatedCCombatInformationNodePtr::CExoArrayListTemplatedCCombatInformationNodePtrvoid
extern void * const CExoArrayListTemplatedCCombatInformationNodePtr__CExoArrayListTemplatedCCombatInformationNodePtrCtor__0;
// CExoArrayListTemplatedCCombatInformationNodePtr::CExoArrayListTemplatedCCombatInformationNodePtrint
extern void * const CExoArrayListTemplatedCCombatInformationNodePtr__CExoArrayListTemplatedCCombatInformationNodePtrCtor__1;
// void CExoArrayListTemplatedCCombatInformationNodePtr::__vcint
extern void * const CExoArrayListTemplatedCCombatInformationNodePtr____vc;
// public void CExoArrayListTemplatedCCombatInformationNodePtr::AddCCombatInformationNode*
extern void * const CExoArrayListTemplatedCCombatInformationNodePtr__Add;
// public void CExoArrayListTemplatedCCombatInformationNodePtr::Allocateint
extern void * const CExoArrayListTemplatedCCombatInformationNodePtr__Allocate;
// void CExoArrayListTemplatedCCombatInformationNodePtr::DelIndexint
extern void * const CExoArrayListTemplatedCCombatInformationNodePtr__DelIndex;
// void CExoArrayListTemplatedCCombatInformationNodePtr::SetSizeint
extern void * const CExoArrayListTemplatedCCombatInformationNodePtr__SetSize;

// CExoArrayListTemplatedCEffectIconObjectPtr::CExoArrayListTemplatedCEffectIconObjectPtrvoid
extern void * const CExoArrayListTemplatedCEffectIconObjectPtr__CExoArrayListTemplatedCEffectIconObjectPtrCtor__0;
// CExoArrayListTemplatedCEffectIconObjectPtr::CExoArrayListTemplatedCEffectIconObjectPtrint
extern void * const CExoArrayListTemplatedCEffectIconObjectPtr__CExoArrayListTemplatedCEffectIconObjectPtrCtor__1;
// void CExoArrayListTemplatedCEffectIconObjectPtr::__vcint
extern void * const CExoArrayListTemplatedCEffectIconObjectPtr____vc;
// void CExoArrayListTemplatedCEffectIconObjectPtr::AddCEffectIconObject*
extern void * const CExoArrayListTemplatedCEffectIconObjectPtr__Add;
// void CExoArrayListTemplatedCEffectIconObjectPtr::Allocateint
extern void * const CExoArrayListTemplatedCEffectIconObjectPtr__Allocate;
// void CExoArrayListTemplatedCEffectIconObjectPtr::DelIndexint
extern void * const CExoArrayListTemplatedCEffectIconObjectPtr__DelIndex;
// public void CExoArrayListTemplatedCEffectIconObjectPtr::SetSizeint
extern void * const CExoArrayListTemplatedCEffectIconObjectPtr__SetSize;

// CExoArrayListTemplatedCExoString::CExoArrayListTemplatedCExoStringvoid
extern void * const CExoArrayListTemplatedCExoString__CExoArrayListTemplatedCExoStringCtor__0;
// CExoArrayListTemplatedCExoString::CExoArrayListTemplatedCExoStringint
extern void * const CExoArrayListTemplatedCExoString__CExoArrayListTemplatedCExoStringCtor__1;
// void CExoArrayListTemplatedCExoString::__vcint
extern void * const CExoArrayListTemplatedCExoString____vc__0;
// void CExoArrayListTemplatedCExoString::__vcint const
extern void * const CExoArrayListTemplatedCExoString____vc__1;
// public void CExoArrayListTemplatedCExoString::AddCExoString
extern void * const CExoArrayListTemplatedCExoString__Add;
// public int CExoArrayListTemplatedCExoString::AddUniqueCExoString
extern void * const CExoArrayListTemplatedCExoString__AddUnique;
// public void CExoArrayListTemplatedCExoString::Allocateint
extern void * const CExoArrayListTemplatedCExoString__Allocate;
// public int CExoArrayListTemplatedCExoString::ContainsCExoString
extern void * const CExoArrayListTemplatedCExoString__Contains;
// void CExoArrayListTemplatedCExoString::DelIndexint
extern void * const CExoArrayListTemplatedCExoString__DelIndex;
// public void CExoArrayListTemplatedCExoString::InsertCExoString, int
extern void * const CExoArrayListTemplatedCExoString__Insert;
// public void CExoArrayListTemplatedCExoString::RemoveCExoString
extern void * const CExoArrayListTemplatedCExoString__Remove;
// void CExoArrayListTemplatedCExoString::SetSizeint
extern void * const CExoArrayListTemplatedCExoString__SetSize;

// CExoArrayListTemplatedCExoStringPtr::CExoArrayListTemplatedCExoStringPtrvoid
extern void * const CExoArrayListTemplatedCExoStringPtr__CExoArrayListTemplatedCExoStringPtrCtor__0;
// CExoArrayListTemplatedCExoStringPtr::CExoArrayListTemplatedCExoStringPtrint
extern void * const CExoArrayListTemplatedCExoStringPtr__CExoArrayListTemplatedCExoStringPtrCtor__1;
// CExoArrayListTemplatedCExoStringPtr::CExoArrayListTemplatedCExoStringPtrconst CExoArrayListTemplatedCExoStringPtr&
extern void * const CExoArrayListTemplatedCExoStringPtr__CExoArrayListTemplatedCExoStringPtrCtor__2;
// void CExoArrayListTemplatedCExoStringPtr::__vcint
extern void * const CExoArrayListTemplatedCExoStringPtr____vc__0;
// void CExoArrayListTemplatedCExoStringPtr::__vcint const
extern void * const CExoArrayListTemplatedCExoStringPtr____vc__1;
// void CExoArrayListTemplatedCExoStringPtr::AddCExoString*
extern void * const CExoArrayListTemplatedCExoStringPtr__Add;
// public void CExoArrayListTemplatedCExoStringPtr::Allocateint
extern void * const CExoArrayListTemplatedCExoStringPtr__Allocate;
// public void CExoArrayListTemplatedCExoStringPtr::SetSizeint
extern void * const CExoArrayListTemplatedCExoStringPtr__SetSize;

// CExoArrayListTemplatedCFeatUseListEntryPtr::CExoArrayListTemplatedCFeatUseListEntryPtrvoid
extern void * const CExoArrayListTemplatedCFeatUseListEntryPtr__CExoArrayListTemplatedCFeatUseListEntryPtrCtor__0;
// CExoArrayListTemplatedCFeatUseListEntryPtr::CExoArrayListTemplatedCFeatUseListEntryPtrint
extern void * const CExoArrayListTemplatedCFeatUseListEntryPtr__CExoArrayListTemplatedCFeatUseListEntryPtrCtor__1;
// void CExoArrayListTemplatedCFeatUseListEntryPtr::__vcint
extern void * const CExoArrayListTemplatedCFeatUseListEntryPtr____vc;
// void CExoArrayListTemplatedCFeatUseListEntryPtr::AddCFeatUseListEntry*
extern void * const CExoArrayListTemplatedCFeatUseListEntryPtr__Add;
// public void CExoArrayListTemplatedCFeatUseListEntryPtr::Allocateint
extern void * const CExoArrayListTemplatedCFeatUseListEntryPtr__Allocate;
// public void CExoArrayListTemplatedCFeatUseListEntryPtr::DelIndexint
extern void * const CExoArrayListTemplatedCFeatUseListEntryPtr__DelIndex;

// CExoArrayListTemplatedCFileInfo::CExoArrayListTemplatedCFileInfovoid
extern void * const CExoArrayListTemplatedCFileInfo__CExoArrayListTemplatedCFileInfoCtor__0;
// CExoArrayListTemplatedCFileInfo::CExoArrayListTemplatedCFileInfoint
extern void * const CExoArrayListTemplatedCFileInfo__CExoArrayListTemplatedCFileInfoCtor__1;
// void CExoArrayListTemplatedCFileInfo::__vcint
extern void * const CExoArrayListTemplatedCFileInfo____vc;
// public void CExoArrayListTemplatedCFileInfo::AddCFileInfo
extern void * const CExoArrayListTemplatedCFileInfo__Add;
// void CExoArrayListTemplatedCFileInfo::Allocateint
extern void * const CExoArrayListTemplatedCFileInfo__Allocate;
// public void CExoArrayListTemplatedCFileInfo::InsertCFileInfo, int
extern void * const CExoArrayListTemplatedCFileInfo__Insert;

// CExoArrayListTemplatedCGameEffectPtr::CExoArrayListTemplatedCGameEffectPtrvoid
extern void * const CExoArrayListTemplatedCGameEffectPtr__CExoArrayListTemplatedCGameEffectPtrCtor__0;
// CExoArrayListTemplatedCGameEffectPtr::CExoArrayListTemplatedCGameEffectPtrint
extern void * const CExoArrayListTemplatedCGameEffectPtr__CExoArrayListTemplatedCGameEffectPtrCtor__1;
// CExoArrayListTemplatedCGameEffectPtr::CExoArrayListTemplatedCGameEffectPtrconst CExoArrayListTemplatedCGameEffectPtr&
extern void * const CExoArrayListTemplatedCGameEffectPtr__CExoArrayListTemplatedCGameEffectPtrCtor__2;
// void CExoArrayListTemplatedCGameEffectPtr::__asconst CExoArrayListTemplatedCGameEffectPtr&
extern void * const CExoArrayListTemplatedCGameEffectPtr____as;
// void CExoArrayListTemplatedCGameEffectPtr::__vcint
extern void * const CExoArrayListTemplatedCGameEffectPtr____vc__0;
// void CExoArrayListTemplatedCGameEffectPtr::__vcint const
extern void * const CExoArrayListTemplatedCGameEffectPtr____vc__1;
// public void CExoArrayListTemplatedCGameEffectPtr::AddCGameEffect*
extern void * const CExoArrayListTemplatedCGameEffectPtr__Add;
// public void CExoArrayListTemplatedCGameEffectPtr::Allocateint
extern void * const CExoArrayListTemplatedCGameEffectPtr__Allocate;
// void CExoArrayListTemplatedCGameEffectPtr::DelIndexint
extern void * const CExoArrayListTemplatedCGameEffectPtr__DelIndex;
// void CExoArrayListTemplatedCGameEffectPtr::IndexOfCGameEffect*
extern void * const CExoArrayListTemplatedCGameEffectPtr__IndexOf;
// void CExoArrayListTemplatedCGameEffectPtr::InsertCGameEffect*, int
extern void * const CExoArrayListTemplatedCGameEffectPtr__Insert;
// void CExoArrayListTemplatedCGameEffectPtr::SetSizeint
extern void * const CExoArrayListTemplatedCGameEffectPtr__SetSize;

// CExoArrayListTemplatedCGameObjectPtr::CExoArrayListTemplatedCGameObjectPtrvoid
extern void * const CExoArrayListTemplatedCGameObjectPtr__CExoArrayListTemplatedCGameObjectPtrCtor__0;
// CExoArrayListTemplatedCGameObjectPtr::CExoArrayListTemplatedCGameObjectPtrint
extern void * const CExoArrayListTemplatedCGameObjectPtr__CExoArrayListTemplatedCGameObjectPtrCtor__1;
// void CExoArrayListTemplatedCGameObjectPtr::__vcint
extern void * const CExoArrayListTemplatedCGameObjectPtr____vc;
// void CExoArrayListTemplatedCGameObjectPtr::AddCGameObject*
extern void * const CExoArrayListTemplatedCGameObjectPtr__Add;
// public void CExoArrayListTemplatedCGameObjectPtr::Allocateint
extern void * const CExoArrayListTemplatedCGameObjectPtr__Allocate;

// CExoArrayListTemplatedchar::CExoArrayListTemplatedcharvoid
extern void * const CExoArrayListTemplatedchar__CExoArrayListTemplatedcharCtor__0;
// CExoArrayListTemplatedchar::CExoArrayListTemplatedcharint
extern void * const CExoArrayListTemplatedchar__CExoArrayListTemplatedcharCtor__1;
// void CExoArrayListTemplatedchar::__vcint
extern void * const CExoArrayListTemplatedchar____vc;
// void CExoArrayListTemplatedchar::Addchar
extern void * const CExoArrayListTemplatedchar__Add;
// public void CExoArrayListTemplatedchar::Allocateint
extern void * const CExoArrayListTemplatedchar__Allocate;

// CExoArrayListTemplatedCLoopingVisualEffectPtr::CExoArrayListTemplatedCLoopingVisualEffectPtrvoid
extern void * const CExoArrayListTemplatedCLoopingVisualEffectPtr__CExoArrayListTemplatedCLoopingVisualEffectPtrCtor__0;
// CExoArrayListTemplatedCLoopingVisualEffectPtr::CExoArrayListTemplatedCLoopingVisualEffectPtrint
extern void * const CExoArrayListTemplatedCLoopingVisualEffectPtr__CExoArrayListTemplatedCLoopingVisualEffectPtrCtor__1;
// void CExoArrayListTemplatedCLoopingVisualEffectPtr::__vcint
extern void * const CExoArrayListTemplatedCLoopingVisualEffectPtr____vc;
// void CExoArrayListTemplatedCLoopingVisualEffectPtr::AddCLoopingVisualEffect*
extern void * const CExoArrayListTemplatedCLoopingVisualEffectPtr__Add;
// void CExoArrayListTemplatedCLoopingVisualEffectPtr::AddUniqueCLoopingVisualEffect*
extern void * const CExoArrayListTemplatedCLoopingVisualEffectPtr__AddUnique;
// void CExoArrayListTemplatedCLoopingVisualEffectPtr::Allocateint
extern void * const CExoArrayListTemplatedCLoopingVisualEffectPtr__Allocate;
// void CExoArrayListTemplatedCLoopingVisualEffectPtr::ContainsCLoopingVisualEffect*
extern void * const CExoArrayListTemplatedCLoopingVisualEffectPtr__Contains;
// void CExoArrayListTemplatedCLoopingVisualEffectPtr::DelIndexint
extern void * const CExoArrayListTemplatedCLoopingVisualEffectPtr__DelIndex;
// void CExoArrayListTemplatedCLoopingVisualEffectPtr::SetSizeint
extern void * const CExoArrayListTemplatedCLoopingVisualEffectPtr__SetSize;

// CExoArrayListTemplatedCNetLayerPlayerCDKeyInfo::CExoArrayListTemplatedCNetLayerPlayerCDKeyInfovoid
extern void * const CExoArrayListTemplatedCNetLayerPlayerCDKeyInfo__CExoArrayListTemplatedCNetLayerPlayerCDKeyInfoCtor__0;
// CExoArrayListTemplatedCNetLayerPlayerCDKeyInfo::CExoArrayListTemplatedCNetLayerPlayerCDKeyInfoint
extern void * const CExoArrayListTemplatedCNetLayerPlayerCDKeyInfo__CExoArrayListTemplatedCNetLayerPlayerCDKeyInfoCtor__1;
// void CExoArrayListTemplatedCNetLayerPlayerCDKeyInfo::__vcint
extern void * const CExoArrayListTemplatedCNetLayerPlayerCDKeyInfo____vc;
// public void CExoArrayListTemplatedCNetLayerPlayerCDKeyInfo::AddCNetLayerPlayerCDKeyInfo
extern void * const CExoArrayListTemplatedCNetLayerPlayerCDKeyInfo__Add;
// void CExoArrayListTemplatedCNetLayerPlayerCDKeyInfo::Allocateint
extern void * const CExoArrayListTemplatedCNetLayerPlayerCDKeyInfo__Allocate;
// void CExoArrayListTemplatedCNetLayerPlayerCDKeyInfo::SetSizeint
extern void * const CExoArrayListTemplatedCNetLayerPlayerCDKeyInfo__SetSize;

// CExoArrayListTemplatedCNWCCMessageDataPtr::CExoArrayListTemplatedCNWCCMessageDataPtrvoid
extern void * const CExoArrayListTemplatedCNWCCMessageDataPtr__CExoArrayListTemplatedCNWCCMessageDataPtrCtor__0;
// CExoArrayListTemplatedCNWCCMessageDataPtr::CExoArrayListTemplatedCNWCCMessageDataPtrint
extern void * const CExoArrayListTemplatedCNWCCMessageDataPtr__CExoArrayListTemplatedCNWCCMessageDataPtrCtor__1;
// void CExoArrayListTemplatedCNWCCMessageDataPtr::__vcint
extern void * const CExoArrayListTemplatedCNWCCMessageDataPtr____vc;
// void CExoArrayListTemplatedCNWCCMessageDataPtr::AddCNWCCMessageData*
extern void * const CExoArrayListTemplatedCNWCCMessageDataPtr__Add;
// public void CExoArrayListTemplatedCNWCCMessageDataPtr::Allocateint
extern void * const CExoArrayListTemplatedCNWCCMessageDataPtr__Allocate;

// CExoArrayListTemplatedCNWItemProperty::CExoArrayListTemplatedCNWItemPropertyvoid
extern void * const CExoArrayListTemplatedCNWItemProperty__CExoArrayListTemplatedCNWItemPropertyCtor__0;
// CExoArrayListTemplatedCNWItemProperty::CExoArrayListTemplatedCNWItemPropertyint
extern void * const CExoArrayListTemplatedCNWItemProperty__CExoArrayListTemplatedCNWItemPropertyCtor__1;
// void CExoArrayListTemplatedCNWItemProperty::__asconst CExoArrayListTemplatedCNWItemProperty&
extern void * const CExoArrayListTemplatedCNWItemProperty____as;
// void CExoArrayListTemplatedCNWItemProperty::__vcint
extern void * const CExoArrayListTemplatedCNWItemProperty____vc__0;
// void CExoArrayListTemplatedCNWItemProperty::__vcint const
extern void * const CExoArrayListTemplatedCNWItemProperty____vc__1;
// void CExoArrayListTemplatedCNWItemProperty::AddCNWItemProperty
extern void * const CExoArrayListTemplatedCNWItemProperty__Add;
// public void CExoArrayListTemplatedCNWItemProperty::Allocateint
extern void * const CExoArrayListTemplatedCNWItemProperty__Allocate;
// void CExoArrayListTemplatedCNWItemProperty::DelIndexint
extern void * const CExoArrayListTemplatedCNWItemProperty__DelIndex;
// void CExoArrayListTemplatedCNWItemProperty::SetSizeint
extern void * const CExoArrayListTemplatedCNWItemProperty__SetSize;

// CExoArrayListTemplatedCNWLevelStatsPtr::CExoArrayListTemplatedCNWLevelStatsPtrvoid
extern void * const CExoArrayListTemplatedCNWLevelStatsPtr__CExoArrayListTemplatedCNWLevelStatsPtrCtor__0;
// CExoArrayListTemplatedCNWLevelStatsPtr::CExoArrayListTemplatedCNWLevelStatsPtrint
extern void * const CExoArrayListTemplatedCNWLevelStatsPtr__CExoArrayListTemplatedCNWLevelStatsPtrCtor__1;
// void CExoArrayListTemplatedCNWLevelStatsPtr::__vcint
extern void * const CExoArrayListTemplatedCNWLevelStatsPtr____vc;
// void CExoArrayListTemplatedCNWLevelStatsPtr::AddCNWLevelStats*
extern void * const CExoArrayListTemplatedCNWLevelStatsPtr__Add;
// public void CExoArrayListTemplatedCNWLevelStatsPtr::Allocateint
extern void * const CExoArrayListTemplatedCNWLevelStatsPtr__Allocate;
// public void CExoArrayListTemplatedCNWLevelStatsPtr::DelIndexint
extern void * const CExoArrayListTemplatedCNWLevelStatsPtr__DelIndex;
// void CExoArrayListTemplatedCNWLevelStatsPtr::RemoveCNWLevelStats*
extern void * const CExoArrayListTemplatedCNWLevelStatsPtr__Remove;

// CExoArrayListTemplatedCNWSExpressionListPtr::CExoArrayListTemplatedCNWSExpressionListPtrvoid
extern void * const CExoArrayListTemplatedCNWSExpressionListPtr__CExoArrayListTemplatedCNWSExpressionListPtrCtor__0;
// CExoArrayListTemplatedCNWSExpressionListPtr::CExoArrayListTemplatedCNWSExpressionListPtrint
extern void * const CExoArrayListTemplatedCNWSExpressionListPtr__CExoArrayListTemplatedCNWSExpressionListPtrCtor__1;
// void CExoArrayListTemplatedCNWSExpressionListPtr::__vcint
extern void * const CExoArrayListTemplatedCNWSExpressionListPtr____vc;
// void CExoArrayListTemplatedCNWSExpressionListPtr::AddCNWSExpressionList*
extern void * const CExoArrayListTemplatedCNWSExpressionListPtr__Add;
// public void CExoArrayListTemplatedCNWSExpressionListPtr::Allocateint
extern void * const CExoArrayListTemplatedCNWSExpressionListPtr__Allocate;
// void CExoArrayListTemplatedCNWSExpressionListPtr::DelIndexint
extern void * const CExoArrayListTemplatedCNWSExpressionListPtr__DelIndex;

// CExoArrayListTemplatedCNWSExpressionNodePtr::CExoArrayListTemplatedCNWSExpressionNodePtrvoid
extern void * const CExoArrayListTemplatedCNWSExpressionNodePtr__CExoArrayListTemplatedCNWSExpressionNodePtrCtor__0;
// CExoArrayListTemplatedCNWSExpressionNodePtr::CExoArrayListTemplatedCNWSExpressionNodePtrint
extern void * const CExoArrayListTemplatedCNWSExpressionNodePtr__CExoArrayListTemplatedCNWSExpressionNodePtrCtor__1;
// void CExoArrayListTemplatedCNWSExpressionNodePtr::__vcint
extern void * const CExoArrayListTemplatedCNWSExpressionNodePtr____vc;
// void CExoArrayListTemplatedCNWSExpressionNodePtr::AddCNWSExpressionNode*
extern void * const CExoArrayListTemplatedCNWSExpressionNodePtr__Add;
// public void CExoArrayListTemplatedCNWSExpressionNodePtr::Allocateint
extern void * const CExoArrayListTemplatedCNWSExpressionNodePtr__Allocate;
// void CExoArrayListTemplatedCNWSExpressionNodePtr::DelIndexint
extern void * const CExoArrayListTemplatedCNWSExpressionNodePtr__DelIndex;

// CExoArrayListTemplatedCNWSExpressionPtr::CExoArrayListTemplatedCNWSExpressionPtrvoid
extern void * const CExoArrayListTemplatedCNWSExpressionPtr__CExoArrayListTemplatedCNWSExpressionPtrCtor__0;
// CExoArrayListTemplatedCNWSExpressionPtr::CExoArrayListTemplatedCNWSExpressionPtrint
extern void * const CExoArrayListTemplatedCNWSExpressionPtr__CExoArrayListTemplatedCNWSExpressionPtrCtor__1;
// void CExoArrayListTemplatedCNWSExpressionPtr::__vcint
extern void * const CExoArrayListTemplatedCNWSExpressionPtr____vc;
// void CExoArrayListTemplatedCNWSExpressionPtr::AddCNWSExpression*
extern void * const CExoArrayListTemplatedCNWSExpressionPtr__Add;
// void CExoArrayListTemplatedCNWSExpressionPtr::Allocateint
extern void * const CExoArrayListTemplatedCNWSExpressionPtr__Allocate;

// CExoArrayListTemplatedCNWSFactionPtr::CExoArrayListTemplatedCNWSFactionPtrvoid
extern void * const CExoArrayListTemplatedCNWSFactionPtr__CExoArrayListTemplatedCNWSFactionPtrCtor__0;
// CExoArrayListTemplatedCNWSFactionPtr::CExoArrayListTemplatedCNWSFactionPtrint
extern void * const CExoArrayListTemplatedCNWSFactionPtr__CExoArrayListTemplatedCNWSFactionPtrCtor__1;
// void CExoArrayListTemplatedCNWSFactionPtr::__vcint
extern void * const CExoArrayListTemplatedCNWSFactionPtr____vc;
// void CExoArrayListTemplatedCNWSFactionPtr::AddCNWSFaction*
extern void * const CExoArrayListTemplatedCNWSFactionPtr__Add;
// public void CExoArrayListTemplatedCNWSFactionPtr::Allocateint
extern void * const CExoArrayListTemplatedCNWSFactionPtr__Allocate;

// CExoArrayListTemplatedCNWSInvitationDetails::CExoArrayListTemplatedCNWSInvitationDetailsint
extern void * const CExoArrayListTemplatedCNWSInvitationDetails__CExoArrayListTemplatedCNWSInvitationDetailsCtor;
// void CExoArrayListTemplatedCNWSInvitationDetails::__vcint
extern void * const CExoArrayListTemplatedCNWSInvitationDetails____vc;
// void CExoArrayListTemplatedCNWSInvitationDetails::AddCNWSInvitationDetails
extern void * const CExoArrayListTemplatedCNWSInvitationDetails__Add;
// void CExoArrayListTemplatedCNWSInvitationDetails::Allocateint
extern void * const CExoArrayListTemplatedCNWSInvitationDetails__Allocate;
// void CExoArrayListTemplatedCNWSInvitationDetails::DelIndexint
extern void * const CExoArrayListTemplatedCNWSInvitationDetails__DelIndex;

// CExoArrayListTemplatedCNWSItemPtr::CExoArrayListTemplatedCNWSItemPtrvoid
extern void * const CExoArrayListTemplatedCNWSItemPtr__CExoArrayListTemplatedCNWSItemPtrCtor__0;
// CExoArrayListTemplatedCNWSItemPtr::CExoArrayListTemplatedCNWSItemPtrint
extern void * const CExoArrayListTemplatedCNWSItemPtr__CExoArrayListTemplatedCNWSItemPtrCtor__1;
// void CExoArrayListTemplatedCNWSItemPtr::__vcint
extern void * const CExoArrayListTemplatedCNWSItemPtr____vc;
// void CExoArrayListTemplatedCNWSItemPtr::AddCNWSItem*
extern void * const CExoArrayListTemplatedCNWSItemPtr__Add;
// public void CExoArrayListTemplatedCNWSItemPtr::Allocateint
extern void * const CExoArrayListTemplatedCNWSItemPtr__Allocate;
// void CExoArrayListTemplatedCNWSItemPtr::InsertCNWSItem*, int
extern void * const CExoArrayListTemplatedCNWSItemPtr__Insert;

// CExoArrayListTemplatedCNWSPersonalReputation::CExoArrayListTemplatedCNWSPersonalReputationvoid
extern void * const CExoArrayListTemplatedCNWSPersonalReputation__CExoArrayListTemplatedCNWSPersonalReputationCtor__0;
// CExoArrayListTemplatedCNWSPersonalReputation::CExoArrayListTemplatedCNWSPersonalReputationint
extern void * const CExoArrayListTemplatedCNWSPersonalReputation__CExoArrayListTemplatedCNWSPersonalReputationCtor__1;
// void CExoArrayListTemplatedCNWSPersonalReputation::__vcint
extern void * const CExoArrayListTemplatedCNWSPersonalReputation____vc;
// void CExoArrayListTemplatedCNWSPersonalReputation::AddCNWSPersonalReputation
extern void * const CExoArrayListTemplatedCNWSPersonalReputation__Add;
// public void CExoArrayListTemplatedCNWSPersonalReputation::Allocateint
extern void * const CExoArrayListTemplatedCNWSPersonalReputation__Allocate;
// void CExoArrayListTemplatedCNWSPersonalReputation::DelIndexint
extern void * const CExoArrayListTemplatedCNWSPersonalReputation__DelIndex;

// CExoArrayListTemplatedCNWSPlayerJournalQuestUpdates::CExoArrayListTemplatedCNWSPlayerJournalQuestUpdatesvoid
extern void * const CExoArrayListTemplatedCNWSPlayerJournalQuestUpdates__CExoArrayListTemplatedCNWSPlayerJournalQuestUpdatesCtor__0;
// CExoArrayListTemplatedCNWSPlayerJournalQuestUpdates::CExoArrayListTemplatedCNWSPlayerJournalQuestUpdatesint
extern void * const CExoArrayListTemplatedCNWSPlayerJournalQuestUpdates__CExoArrayListTemplatedCNWSPlayerJournalQuestUpdatesCtor__1;
// void CExoArrayListTemplatedCNWSPlayerJournalQuestUpdates::__vcint
extern void * const CExoArrayListTemplatedCNWSPlayerJournalQuestUpdates____vc;
// public void CExoArrayListTemplatedCNWSPlayerJournalQuestUpdates::AddCNWSPlayerJournalQuestUpdates
extern void * const CExoArrayListTemplatedCNWSPlayerJournalQuestUpdates__Add;
// void CExoArrayListTemplatedCNWSPlayerJournalQuestUpdates::Allocateint
extern void * const CExoArrayListTemplatedCNWSPlayerJournalQuestUpdates__Allocate;
// void CExoArrayListTemplatedCNWSPlayerJournalQuestUpdates::SetSizeint
extern void * const CExoArrayListTemplatedCNWSPlayerJournalQuestUpdates__SetSize;

// CExoArrayListTemplatedCNWSPVPEntry::CExoArrayListTemplatedCNWSPVPEntryvoid
extern void * const CExoArrayListTemplatedCNWSPVPEntry__CExoArrayListTemplatedCNWSPVPEntryCtor__0;
// CExoArrayListTemplatedCNWSPVPEntry::CExoArrayListTemplatedCNWSPVPEntryint
extern void * const CExoArrayListTemplatedCNWSPVPEntry__CExoArrayListTemplatedCNWSPVPEntryCtor__1;
// void CExoArrayListTemplatedCNWSPVPEntry::__vcint
extern void * const CExoArrayListTemplatedCNWSPVPEntry____vc;
// void CExoArrayListTemplatedCNWSPVPEntry::AddCNWSPVPEntry
extern void * const CExoArrayListTemplatedCNWSPVPEntry__Add;
// void CExoArrayListTemplatedCNWSPVPEntry::Allocateint
extern void * const CExoArrayListTemplatedCNWSPVPEntry__Allocate;
// void CExoArrayListTemplatedCNWSPVPEntry::DelIndexint
extern void * const CExoArrayListTemplatedCNWSPVPEntry__DelIndex;

// CExoArrayListTemplatedCNWSScriptVar::CExoArrayListTemplatedCNWSScriptVarvoid
extern void * const CExoArrayListTemplatedCNWSScriptVar__CExoArrayListTemplatedCNWSScriptVarCtor__0;
// CExoArrayListTemplatedCNWSScriptVar::CExoArrayListTemplatedCNWSScriptVarint
extern void * const CExoArrayListTemplatedCNWSScriptVar__CExoArrayListTemplatedCNWSScriptVarCtor__1;
// void CExoArrayListTemplatedCNWSScriptVar::__vcint
extern void * const CExoArrayListTemplatedCNWSScriptVar____vc;
// public void CExoArrayListTemplatedCNWSScriptVar::AddCNWSScriptVar
extern void * const CExoArrayListTemplatedCNWSScriptVar__Add;
// void CExoArrayListTemplatedCNWSScriptVar::Allocateint
extern void * const CExoArrayListTemplatedCNWSScriptVar__Allocate;
// void CExoArrayListTemplatedCNWSScriptVar::DelIndexint
extern void * const CExoArrayListTemplatedCNWSScriptVar__DelIndex;

// CExoArrayListTemplatedCNWSSpellScriptDataPtr::CExoArrayListTemplatedCNWSSpellScriptDataPtrvoid
extern void * const CExoArrayListTemplatedCNWSSpellScriptDataPtr__CExoArrayListTemplatedCNWSSpellScriptDataPtrCtor__0;
// CExoArrayListTemplatedCNWSSpellScriptDataPtr::CExoArrayListTemplatedCNWSSpellScriptDataPtrint
extern void * const CExoArrayListTemplatedCNWSSpellScriptDataPtr__CExoArrayListTemplatedCNWSSpellScriptDataPtrCtor__1;
// void CExoArrayListTemplatedCNWSSpellScriptDataPtr::__vcint
extern void * const CExoArrayListTemplatedCNWSSpellScriptDataPtr____vc;
// void CExoArrayListTemplatedCNWSSpellScriptDataPtr::AddCNWSSpellScriptData*
extern void * const CExoArrayListTemplatedCNWSSpellScriptDataPtr__Add;
// void CExoArrayListTemplatedCNWSSpellScriptDataPtr::Allocateint
extern void * const CExoArrayListTemplatedCNWSSpellScriptDataPtr__Allocate;

// CExoArrayListTemplatedCNWSStats_SpellLikeAbility::CExoArrayListTemplatedCNWSStats_SpellLikeAbilityvoid
extern void * const CExoArrayListTemplatedCNWSStats_SpellLikeAbility__CExoArrayListTemplatedCNWSStats_SpellLikeAbilityCtor__0;
// CExoArrayListTemplatedCNWSStats_SpellLikeAbility::CExoArrayListTemplatedCNWSStats_SpellLikeAbilityint
extern void * const CExoArrayListTemplatedCNWSStats_SpellLikeAbility__CExoArrayListTemplatedCNWSStats_SpellLikeAbilityCtor__1;
// void CExoArrayListTemplatedCNWSStats_SpellLikeAbility::__vcint
extern void * const CExoArrayListTemplatedCNWSStats_SpellLikeAbility____vc;
// void CExoArrayListTemplatedCNWSStats_SpellLikeAbility::AddCNWSStats_SpellLikeAbility
extern void * const CExoArrayListTemplatedCNWSStats_SpellLikeAbility__Add;
// void CExoArrayListTemplatedCNWSStats_SpellLikeAbility::Allocateint
extern void * const CExoArrayListTemplatedCNWSStats_SpellLikeAbility__Allocate;
// void CExoArrayListTemplatedCNWSStats_SpellLikeAbility::SetSizeint
extern void * const CExoArrayListTemplatedCNWSStats_SpellLikeAbility__SetSize;

// CExoArrayListTemplatedCNWSStats_SpellPtr::CExoArrayListTemplatedCNWSStats_SpellPtrvoid
extern void * const CExoArrayListTemplatedCNWSStats_SpellPtr__CExoArrayListTemplatedCNWSStats_SpellPtrCtor__0;
// CExoArrayListTemplatedCNWSStats_SpellPtr::CExoArrayListTemplatedCNWSStats_SpellPtrint
extern void * const CExoArrayListTemplatedCNWSStats_SpellPtr__CExoArrayListTemplatedCNWSStats_SpellPtrCtor__1;
// void CExoArrayListTemplatedCNWSStats_SpellPtr::__vcint
extern void * const CExoArrayListTemplatedCNWSStats_SpellPtr____vc;
// void CExoArrayListTemplatedCNWSStats_SpellPtr::AddCNWSStats_Spell*
extern void * const CExoArrayListTemplatedCNWSStats_SpellPtr__Add;
// void CExoArrayListTemplatedCNWSStats_SpellPtr::Allocateint
extern void * const CExoArrayListTemplatedCNWSStats_SpellPtr__Allocate;
// void CExoArrayListTemplatedCNWSStats_SpellPtr::DelIndexint
extern void * const CExoArrayListTemplatedCNWSStats_SpellPtr__DelIndex;

// CExoArrayListTemplatedCNWSTagNode::CExoArrayListTemplatedCNWSTagNodevoid
extern void * const CExoArrayListTemplatedCNWSTagNode__CExoArrayListTemplatedCNWSTagNodeCtor__0;
// CExoArrayListTemplatedCNWSTagNode::CExoArrayListTemplatedCNWSTagNodeint
extern void * const CExoArrayListTemplatedCNWSTagNode__CExoArrayListTemplatedCNWSTagNodeCtor__1;
// void CExoArrayListTemplatedCNWSTagNode::__vcint
extern void * const CExoArrayListTemplatedCNWSTagNode____vc;
// void CExoArrayListTemplatedCNWSTagNode::AddCNWSTagNode
extern void * const CExoArrayListTemplatedCNWSTagNode__Add;
// void CExoArrayListTemplatedCNWSTagNode::Allocateint
extern void * const CExoArrayListTemplatedCNWSTagNode__Allocate;
// void CExoArrayListTemplatedCNWSTagNode::DelIndexint
extern void * const CExoArrayListTemplatedCNWSTagNode__DelIndex;
// void CExoArrayListTemplatedCNWSTagNode::InsertCNWSTagNode, int
extern void * const CExoArrayListTemplatedCNWSTagNode__Insert;

// CExoArrayListTemplatedCNWTileSurfaceMeshAABBNodePtr::CExoArrayListTemplatedCNWTileSurfaceMeshAABBNodePtrvoid
extern void * const CExoArrayListTemplatedCNWTileSurfaceMeshAABBNodePtr__CExoArrayListTemplatedCNWTileSurfaceMeshAABBNodePtrCtor__0;
// CExoArrayListTemplatedCNWTileSurfaceMeshAABBNodePtr::CExoArrayListTemplatedCNWTileSurfaceMeshAABBNodePtrint
extern void * const CExoArrayListTemplatedCNWTileSurfaceMeshAABBNodePtr__CExoArrayListTemplatedCNWTileSurfaceMeshAABBNodePtrCtor__1;
// void CExoArrayListTemplatedCNWTileSurfaceMeshAABBNodePtr::AddCNWTileSurfaceMeshAABBNode*
extern void * const CExoArrayListTemplatedCNWTileSurfaceMeshAABBNodePtr__Add;
// void CExoArrayListTemplatedCNWTileSurfaceMeshAABBNodePtr::Allocateint
extern void * const CExoArrayListTemplatedCNWTileSurfaceMeshAABBNodePtr__Allocate;
// void CExoArrayListTemplatedCNWTileSurfaceMeshAABBNodePtr::DelIndexint
extern void * const CExoArrayListTemplatedCNWTileSurfaceMeshAABBNodePtr__DelIndex;

// CExoArrayListTemplatedCNWVisibilityNodePtr::CExoArrayListTemplatedCNWVisibilityNodePtrvoid
extern void * const CExoArrayListTemplatedCNWVisibilityNodePtr__CExoArrayListTemplatedCNWVisibilityNodePtrCtor__0;
// CExoArrayListTemplatedCNWVisibilityNodePtr::CExoArrayListTemplatedCNWVisibilityNodePtrint
extern void * const CExoArrayListTemplatedCNWVisibilityNodePtr__CExoArrayListTemplatedCNWVisibilityNodePtrCtor__1;
// void CExoArrayListTemplatedCNWVisibilityNodePtr::__vcint
extern void * const CExoArrayListTemplatedCNWVisibilityNodePtr____vc;
// void CExoArrayListTemplatedCNWVisibilityNodePtr::AddCNWVisibilityNode*
extern void * const CExoArrayListTemplatedCNWVisibilityNodePtr__Add;
// void CExoArrayListTemplatedCNWVisibilityNodePtr::Allocateint
extern void * const CExoArrayListTemplatedCNWVisibilityNodePtr__Allocate;
// public void CExoArrayListTemplatedCNWVisibilityNodePtr::DelIndexint
extern void * const CExoArrayListTemplatedCNWVisibilityNodePtr__DelIndex;

// CExoArrayListTemplatedCResRef::CExoArrayListTemplatedCResRefvoid
extern void * const CExoArrayListTemplatedCResRef__CExoArrayListTemplatedCResRefCtor__0;
// CExoArrayListTemplatedCResRef::CExoArrayListTemplatedCResRefint
extern void * const CExoArrayListTemplatedCResRef__CExoArrayListTemplatedCResRefCtor__1;
// CExoArrayListTemplatedCResRef::CExoArrayListTemplatedCResRefconst CExoArrayListTemplatedCResRef&
extern void * const CExoArrayListTemplatedCResRef__CExoArrayListTemplatedCResRefCtor__2;
// void CExoArrayListTemplatedCResRef::__vcint
extern void * const CExoArrayListTemplatedCResRef____vc__0;
// void CExoArrayListTemplatedCResRef::__vcint const
extern void * const CExoArrayListTemplatedCResRef____vc__1;
// void CExoArrayListTemplatedCResRef::AddCResRef
extern void * const CExoArrayListTemplatedCResRef__Add;
// void CExoArrayListTemplatedCResRef::Allocateint
extern void * const CExoArrayListTemplatedCResRef__Allocate;
// void CExoArrayListTemplatedCResRef::ContainsCResRef
extern void * const CExoArrayListTemplatedCResRef__Contains;

// CExoArrayListTemplatedCScriptLogPtr::CExoArrayListTemplatedCScriptLogPtrvoid
extern void * const CExoArrayListTemplatedCScriptLogPtr__CExoArrayListTemplatedCScriptLogPtrCtor__0;
// CExoArrayListTemplatedCScriptLogPtr::CExoArrayListTemplatedCScriptLogPtrint
extern void * const CExoArrayListTemplatedCScriptLogPtr__CExoArrayListTemplatedCScriptLogPtrCtor__1;
// void CExoArrayListTemplatedCScriptLogPtr::__vcint
extern void * const CExoArrayListTemplatedCScriptLogPtr____vc;
// void CExoArrayListTemplatedCScriptLogPtr::AddCScriptLog*
extern void * const CExoArrayListTemplatedCScriptLogPtr__Add;
// void CExoArrayListTemplatedCScriptLogPtr::Allocateint
extern void * const CExoArrayListTemplatedCScriptLogPtr__Allocate;
// void CExoArrayListTemplatedCScriptLogPtr::SetSizeint
extern void * const CExoArrayListTemplatedCScriptLogPtr__SetSize;

// CExoArrayListTemplatedCSpell_AddPtr::CExoArrayListTemplatedCSpell_AddPtrvoid
extern void * const CExoArrayListTemplatedCSpell_AddPtr__CExoArrayListTemplatedCSpell_AddPtrCtor__0;
// CExoArrayListTemplatedCSpell_AddPtr::CExoArrayListTemplatedCSpell_AddPtrint
extern void * const CExoArrayListTemplatedCSpell_AddPtr__CExoArrayListTemplatedCSpell_AddPtrCtor__1;
// void CExoArrayListTemplatedCSpell_AddPtr::__vcint
extern void * const CExoArrayListTemplatedCSpell_AddPtr____vc;
// void CExoArrayListTemplatedCSpell_AddPtr::AddCSpell_Add*
extern void * const CExoArrayListTemplatedCSpell_AddPtr__Add;
// void CExoArrayListTemplatedCSpell_AddPtr::Allocateint
extern void * const CExoArrayListTemplatedCSpell_AddPtr__Allocate;
// void CExoArrayListTemplatedCSpell_AddPtr::DelIndexint
extern void * const CExoArrayListTemplatedCSpell_AddPtr__DelIndex;

// CExoArrayListTemplatedCSpell_DeletePtr::CExoArrayListTemplatedCSpell_DeletePtrvoid
extern void * const CExoArrayListTemplatedCSpell_DeletePtr__CExoArrayListTemplatedCSpell_DeletePtrCtor__0;
// CExoArrayListTemplatedCSpell_DeletePtr::CExoArrayListTemplatedCSpell_DeletePtrint
extern void * const CExoArrayListTemplatedCSpell_DeletePtr__CExoArrayListTemplatedCSpell_DeletePtrCtor__1;
// void CExoArrayListTemplatedCSpell_DeletePtr::__vcint
extern void * const CExoArrayListTemplatedCSpell_DeletePtr____vc;
// void CExoArrayListTemplatedCSpell_DeletePtr::AddCSpell_Delete*
extern void * const CExoArrayListTemplatedCSpell_DeletePtr__Add;
// void CExoArrayListTemplatedCSpell_DeletePtr::Allocateint
extern void * const CExoArrayListTemplatedCSpell_DeletePtr__Allocate;
// void CExoArrayListTemplatedCSpell_DeletePtr::DelIndexint
extern void * const CExoArrayListTemplatedCSpell_DeletePtr__DelIndex;

// CExoArrayListTemplatedCStoreCustomerPtr::CExoArrayListTemplatedCStoreCustomerPtrvoid
extern void * const CExoArrayListTemplatedCStoreCustomerPtr__CExoArrayListTemplatedCStoreCustomerPtrCtor__0;
// CExoArrayListTemplatedCStoreCustomerPtr::CExoArrayListTemplatedCStoreCustomerPtrint
extern void * const CExoArrayListTemplatedCStoreCustomerPtr__CExoArrayListTemplatedCStoreCustomerPtrCtor__1;
// void CExoArrayListTemplatedCStoreCustomerPtr::__vcint
extern void * const CExoArrayListTemplatedCStoreCustomerPtr____vc;
// void CExoArrayListTemplatedCStoreCustomerPtr::AddCStoreCustomer*
extern void * const CExoArrayListTemplatedCStoreCustomerPtr__Add;
// void CExoArrayListTemplatedCStoreCustomerPtr::Allocateint
extern void * const CExoArrayListTemplatedCStoreCustomerPtr__Allocate;
// void CExoArrayListTemplatedCStoreCustomerPtr::DelIndexint
extern void * const CExoArrayListTemplatedCStoreCustomerPtr__DelIndex;

// CExoArrayListTemplatedCVirtualMachineFilePtr::CExoArrayListTemplatedCVirtualMachineFilePtrvoid
extern void * const CExoArrayListTemplatedCVirtualMachineFilePtr__CExoArrayListTemplatedCVirtualMachineFilePtrCtor__0;
// CExoArrayListTemplatedCVirtualMachineFilePtr::CExoArrayListTemplatedCVirtualMachineFilePtrint
extern void * const CExoArrayListTemplatedCVirtualMachineFilePtr__CExoArrayListTemplatedCVirtualMachineFilePtrCtor__1;
// void CExoArrayListTemplatedCVirtualMachineFilePtr::__vcint
extern void * const CExoArrayListTemplatedCVirtualMachineFilePtr____vc;
// void CExoArrayListTemplatedCVirtualMachineFilePtr::AddCVirtualMachineFile*
extern void * const CExoArrayListTemplatedCVirtualMachineFilePtr__Add;
// void CExoArrayListTemplatedCVirtualMachineFilePtr::Allocateint
extern void * const CExoArrayListTemplatedCVirtualMachineFilePtr__Allocate;
// void CExoArrayListTemplatedCVirtualMachineFilePtr::DelIndexint
extern void * const CExoArrayListTemplatedCVirtualMachineFilePtr__DelIndex;

// CExoArrayListTemplatedCWorldJournalEntry::CExoArrayListTemplatedCWorldJournalEntryvoid
extern void * const CExoArrayListTemplatedCWorldJournalEntry__CExoArrayListTemplatedCWorldJournalEntryCtor__0;
// CExoArrayListTemplatedCWorldJournalEntry::CExoArrayListTemplatedCWorldJournalEntryint
extern void * const CExoArrayListTemplatedCWorldJournalEntry__CExoArrayListTemplatedCWorldJournalEntryCtor__1;
// void CExoArrayListTemplatedCWorldJournalEntry::__vcint
extern void * const CExoArrayListTemplatedCWorldJournalEntry____vc;
// public void CExoArrayListTemplatedCWorldJournalEntry::AddCWorldJournalEntry
extern void * const CExoArrayListTemplatedCWorldJournalEntry__Add;
// void CExoArrayListTemplatedCWorldJournalEntry::Allocateint
extern void * const CExoArrayListTemplatedCWorldJournalEntry__Allocate;
// void CExoArrayListTemplatedCWorldJournalEntry::DelIndexint
extern void * const CExoArrayListTemplatedCWorldJournalEntry__DelIndex;
// void CExoArrayListTemplatedCWorldJournalEntry::SetSizeint
extern void * const CExoArrayListTemplatedCWorldJournalEntry__SetSize;

// CExoArrayListTemplatedfloat::CExoArrayListTemplatedfloatvoid
extern void * const CExoArrayListTemplatedfloat__CExoArrayListTemplatedfloatCtor__0;
// CExoArrayListTemplatedfloat::CExoArrayListTemplatedfloatint
extern void * const CExoArrayListTemplatedfloat__CExoArrayListTemplatedfloatCtor__1;
// void CExoArrayListTemplatedfloat::__vcint
extern void * const CExoArrayListTemplatedfloat____vc;
// public void CExoArrayListTemplatedfloat::Addfloat
extern void * const CExoArrayListTemplatedfloat__Add;
// public void CExoArrayListTemplatedfloat::Allocateint
extern void * const CExoArrayListTemplatedfloat__Allocate;
// void CExoArrayListTemplatedfloat::Insertfloat, int
extern void * const CExoArrayListTemplatedfloat__Insert;
// void CExoArrayListTemplatedfloat::SetSizeint
extern void * const CExoArrayListTemplatedfloat__SetSize;

// public CExoArrayListTemplatedint::CExoArrayListTemplatedintvoid
extern void * const CExoArrayListTemplatedint__CExoArrayListTemplatedintCtor__0;
// public CExoArrayListTemplatedint::CExoArrayListTemplatedintint
extern void * const CExoArrayListTemplatedint__CExoArrayListTemplatedintCtor__1;
// void CExoArrayListTemplatedint::__vcint
extern void * const CExoArrayListTemplatedint____vc;
// public void CExoArrayListTemplatedint::Addint
extern void * const CExoArrayListTemplatedint__Add;
// public void CExoArrayListTemplatedint::Allocateint
extern void * const CExoArrayListTemplatedint__Allocate;
// void CExoArrayListTemplatedint::Containsint
extern void * const CExoArrayListTemplatedint__Contains;
// void CExoArrayListTemplatedint::IndexOfint
extern void * const CExoArrayListTemplatedint__IndexOf;
// void CExoArrayListTemplatedint::Packvoid
extern void * const CExoArrayListTemplatedint__Pack;
// public void CExoArrayListTemplatedint::SetSizeint
extern void * const CExoArrayListTemplatedint__SetSize;

// CExoArrayListTemplatedNWPlayerCharacterList_stPtr::CExoArrayListTemplatedNWPlayerCharacterList_stPtrvoid
extern void * const CExoArrayListTemplatedNWPlayerCharacterList_stPtr__CExoArrayListTemplatedNWPlayerCharacterList_stPtrCtor__0;
// CExoArrayListTemplatedNWPlayerCharacterList_stPtr::CExoArrayListTemplatedNWPlayerCharacterList_stPtrint
extern void * const CExoArrayListTemplatedNWPlayerCharacterList_stPtr__CExoArrayListTemplatedNWPlayerCharacterList_stPtrCtor__1;
// void CExoArrayListTemplatedNWPlayerCharacterList_stPtr::__vcint
extern void * const CExoArrayListTemplatedNWPlayerCharacterList_stPtr____vc;
// public void CExoArrayListTemplatedNWPlayerCharacterList_stPtr::AddNWPlayerCharacterList_st*
extern void * const CExoArrayListTemplatedNWPlayerCharacterList_stPtr__Add;
// void CExoArrayListTemplatedNWPlayerCharacterList_stPtr::AddUniqueNWPlayerCharacterList_st*
extern void * const CExoArrayListTemplatedNWPlayerCharacterList_stPtr__AddUnique;
// void CExoArrayListTemplatedNWPlayerCharacterList_stPtr::Allocateint
extern void * const CExoArrayListTemplatedNWPlayerCharacterList_stPtr__Allocate;
// void CExoArrayListTemplatedNWPlayerCharacterList_stPtr::ContainsNWPlayerCharacterList_st*
extern void * const CExoArrayListTemplatedNWPlayerCharacterList_stPtr__Contains;
// void CExoArrayListTemplatedNWPlayerCharacterList_stPtr::DerefContainsNWPlayerCharacterList_st*
extern void * const CExoArrayListTemplatedNWPlayerCharacterList_stPtr__DerefContains;

// CExoArrayListTemplatedNWPlayerCharacterListClass_st::CExoArrayListTemplatedNWPlayerCharacterListClass_stvoid
extern void * const CExoArrayListTemplatedNWPlayerCharacterListClass_st__CExoArrayListTemplatedNWPlayerCharacterListClass_stCtor__0;
// CExoArrayListTemplatedNWPlayerCharacterListClass_st::CExoArrayListTemplatedNWPlayerCharacterListClass_stint
extern void * const CExoArrayListTemplatedNWPlayerCharacterListClass_st__CExoArrayListTemplatedNWPlayerCharacterListClass_stCtor__1;
// void CExoArrayListTemplatedNWPlayerCharacterListClass_st::__vcint
extern void * const CExoArrayListTemplatedNWPlayerCharacterListClass_st____vc;
// void CExoArrayListTemplatedNWPlayerCharacterListClass_st::AddNWPlayerCharacterListClass_st
extern void * const CExoArrayListTemplatedNWPlayerCharacterListClass_st__Add;
// public void CExoArrayListTemplatedNWPlayerCharacterListClass_st::Allocateint
extern void * const CExoArrayListTemplatedNWPlayerCharacterListClass_st__Allocate;

// CExoArrayListTemplatedSCodeBaseDataPtr::CExoArrayListTemplatedSCodeBaseDataPtrvoid
extern void * const CExoArrayListTemplatedSCodeBaseDataPtr__CExoArrayListTemplatedSCodeBaseDataPtrCtor__0;
// CExoArrayListTemplatedSCodeBaseDataPtr::CExoArrayListTemplatedSCodeBaseDataPtrint
extern void * const CExoArrayListTemplatedSCodeBaseDataPtr__CExoArrayListTemplatedSCodeBaseDataPtrCtor__1;
// void CExoArrayListTemplatedSCodeBaseDataPtr::__vcint
extern void * const CExoArrayListTemplatedSCodeBaseDataPtr____vc;
// void CExoArrayListTemplatedSCodeBaseDataPtr::AddSCodeBaseData*
extern void * const CExoArrayListTemplatedSCodeBaseDataPtr__Add;
// void CExoArrayListTemplatedSCodeBaseDataPtr::Allocateint
extern void * const CExoArrayListTemplatedSCodeBaseDataPtr__Allocate;
// void CExoArrayListTemplatedSCodeBaseDataPtr::DelIndexint
extern void * const CExoArrayListTemplatedSCodeBaseDataPtr__DelIndex;

// CExoArrayListTemplatedSGameSpyRoomEntry::CExoArrayListTemplatedSGameSpyRoomEntryvoid
extern void * const CExoArrayListTemplatedSGameSpyRoomEntry__CExoArrayListTemplatedSGameSpyRoomEntryCtor__0;
// CExoArrayListTemplatedSGameSpyRoomEntry::CExoArrayListTemplatedSGameSpyRoomEntryint
extern void * const CExoArrayListTemplatedSGameSpyRoomEntry__CExoArrayListTemplatedSGameSpyRoomEntryCtor__1;
// void CExoArrayListTemplatedSGameSpyRoomEntry::__vcint
extern void * const CExoArrayListTemplatedSGameSpyRoomEntry____vc;
// void CExoArrayListTemplatedSGameSpyRoomEntry::AddSGameSpyRoomEntry
extern void * const CExoArrayListTemplatedSGameSpyRoomEntry__Add;
// void CExoArrayListTemplatedSGameSpyRoomEntry::Allocateint
extern void * const CExoArrayListTemplatedSGameSpyRoomEntry__Allocate;

// CExoArrayListTemplatedSMstBuddyEntryPtr::CExoArrayListTemplatedSMstBuddyEntryPtrvoid
extern void * const CExoArrayListTemplatedSMstBuddyEntryPtr__CExoArrayListTemplatedSMstBuddyEntryPtrCtor__0;
// CExoArrayListTemplatedSMstBuddyEntryPtr::CExoArrayListTemplatedSMstBuddyEntryPtrint
extern void * const CExoArrayListTemplatedSMstBuddyEntryPtr__CExoArrayListTemplatedSMstBuddyEntryPtrCtor__1;
// void CExoArrayListTemplatedSMstBuddyEntryPtr::__vcint
extern void * const CExoArrayListTemplatedSMstBuddyEntryPtr____vc;
// void CExoArrayListTemplatedSMstBuddyEntryPtr::AddSMstBuddyEntry*
extern void * const CExoArrayListTemplatedSMstBuddyEntryPtr__Add;
// void CExoArrayListTemplatedSMstBuddyEntryPtr::Allocateint
extern void * const CExoArrayListTemplatedSMstBuddyEntryPtr__Allocate;
// void CExoArrayListTemplatedSMstBuddyEntryPtr::DelIndexint
extern void * const CExoArrayListTemplatedSMstBuddyEntryPtr__DelIndex;

// CExoArrayListTemplatedSMstDigiDistInfoPtr::CExoArrayListTemplatedSMstDigiDistInfoPtrvoid
extern void * const CExoArrayListTemplatedSMstDigiDistInfoPtr__CExoArrayListTemplatedSMstDigiDistInfoPtrCtor__0;
// CExoArrayListTemplatedSMstDigiDistInfoPtr::CExoArrayListTemplatedSMstDigiDistInfoPtrint
extern void * const CExoArrayListTemplatedSMstDigiDistInfoPtr__CExoArrayListTemplatedSMstDigiDistInfoPtrCtor__1;
// void CExoArrayListTemplatedSMstDigiDistInfoPtr::__vcint
extern void * const CExoArrayListTemplatedSMstDigiDistInfoPtr____vc;
// void CExoArrayListTemplatedSMstDigiDistInfoPtr::AddSMstDigiDistInfo*
extern void * const CExoArrayListTemplatedSMstDigiDistInfoPtr__Add;
// void CExoArrayListTemplatedSMstDigiDistInfoPtr::Allocateint
extern void * const CExoArrayListTemplatedSMstDigiDistInfoPtr__Allocate;
// void CExoArrayListTemplatedSMstDigiDistInfoPtr::DelIndexint
extern void * const CExoArrayListTemplatedSMstDigiDistInfoPtr__DelIndex;
// void CExoArrayListTemplatedSMstDigiDistInfoPtr::RemoveSMstDigiDistInfo*
extern void * const CExoArrayListTemplatedSMstDigiDistInfoPtr__Remove;

// CExoArrayListTemplatedunsignedchar::CExoArrayListTemplatedunsignedcharvoid
extern void * const CExoArrayListTemplatedunsignedchar__CExoArrayListTemplatedunsignedcharCtor__0;
// CExoArrayListTemplatedunsignedchar::CExoArrayListTemplatedunsignedcharint
extern void * const CExoArrayListTemplatedunsignedchar__CExoArrayListTemplatedunsignedcharCtor__1;
// void CExoArrayListTemplatedunsignedchar::__vcint
extern void * const CExoArrayListTemplatedunsignedchar____vc;
// void CExoArrayListTemplatedunsignedchar::Addunsigned char
extern void * const CExoArrayListTemplatedunsignedchar__Add;
// public void CExoArrayListTemplatedunsignedchar::Allocateint
extern void * const CExoArrayListTemplatedunsignedchar__Allocate;
// void CExoArrayListTemplatedunsignedchar::DelIndexint
extern void * const CExoArrayListTemplatedunsignedchar__DelIndex;
// void CExoArrayListTemplatedunsignedchar::SetSizeint
extern void * const CExoArrayListTemplatedunsignedchar__SetSize;

// CExoArrayListTemplatedunsignedlong::CExoArrayListTemplatedunsignedlongvoid
extern void * const CExoArrayListTemplatedunsignedlong__CExoArrayListTemplatedunsignedlongCtor__0;
// CExoArrayListTemplatedunsignedlong::CExoArrayListTemplatedunsignedlongint
extern void * const CExoArrayListTemplatedunsignedlong__CExoArrayListTemplatedunsignedlongCtor__1;
// CExoArrayListTemplatedunsignedlong::CExoArrayListTemplatedunsignedlongconst CExoArrayListTemplatedunsignedlong&
extern void * const CExoArrayListTemplatedunsignedlong__CExoArrayListTemplatedunsignedlongCtor__2;
// void CExoArrayListTemplatedunsignedlong::__asconst CExoArrayListTemplatedunsignedlong&
extern void * const CExoArrayListTemplatedunsignedlong____as;
// void CExoArrayListTemplatedunsignedlong::__vcint
extern void * const CExoArrayListTemplatedunsignedlong____vc__0;
// void CExoArrayListTemplatedunsignedlong::__vcint const
extern void * const CExoArrayListTemplatedunsignedlong____vc__1;
// public void CExoArrayListTemplatedunsignedlong::Addunsigned long int
extern void * const CExoArrayListTemplatedunsignedlong__Add;
// void CExoArrayListTemplatedunsignedlong::AddUniqueunsigned long int
extern void * const CExoArrayListTemplatedunsignedlong__AddUnique;
// public void CExoArrayListTemplatedunsignedlong::Allocateint
extern void * const CExoArrayListTemplatedunsignedlong__Allocate;
// public int CExoArrayListTemplatedunsignedlong::Containsunsigned long int
extern void * const CExoArrayListTemplatedunsignedlong__Contains;
// public void CExoArrayListTemplatedunsignedlong::DelIndexint
extern void * const CExoArrayListTemplatedunsignedlong__DelIndex;
// public int CExoArrayListTemplatedunsignedlong::IndexOfunsigned long int
extern void * const CExoArrayListTemplatedunsignedlong__IndexOf;
// void CExoArrayListTemplatedunsignedlong::Insertunsigned long int, int
extern void * const CExoArrayListTemplatedunsignedlong__Insert;
// public void CExoArrayListTemplatedunsignedlong::Removeunsigned long int
extern void * const CExoArrayListTemplatedunsignedlong__Remove;
// public void CExoArrayListTemplatedunsignedlong::SetSizeint
extern void * const CExoArrayListTemplatedunsignedlong__SetSize;

// CExoArrayListTemplatedunsignedlonglong::CExoArrayListTemplatedunsignedlonglongvoid
extern void * const CExoArrayListTemplatedunsignedlonglong__CExoArrayListTemplatedunsignedlonglongCtor__0;
// CExoArrayListTemplatedunsignedlonglong::CExoArrayListTemplatedunsignedlonglongint
extern void * const CExoArrayListTemplatedunsignedlonglong__CExoArrayListTemplatedunsignedlonglongCtor__1;
// void CExoArrayListTemplatedunsignedlonglong::__vcint
extern void * const CExoArrayListTemplatedunsignedlonglong____vc;
// void CExoArrayListTemplatedunsignedlonglong::Addunsigned long long int
extern void * const CExoArrayListTemplatedunsignedlonglong__Add;
// void CExoArrayListTemplatedunsignedlonglong::AddUniqueunsigned long long int
extern void * const CExoArrayListTemplatedunsignedlonglong__AddUnique;
// void CExoArrayListTemplatedunsignedlonglong::Allocateint
extern void * const CExoArrayListTemplatedunsignedlonglong__Allocate;
// void CExoArrayListTemplatedunsignedlonglong::Containsunsigned long long int
extern void * const CExoArrayListTemplatedunsignedlonglong__Contains;

// CExoArrayListTemplatedunsignedshort::CExoArrayListTemplatedunsignedshortvoid
extern void * const CExoArrayListTemplatedunsignedshort__CExoArrayListTemplatedunsignedshortCtor__0;
// CExoArrayListTemplatedunsignedshort::CExoArrayListTemplatedunsignedshortint
extern void * const CExoArrayListTemplatedunsignedshort__CExoArrayListTemplatedunsignedshortCtor__1;
// void CExoArrayListTemplatedunsignedshort::__vcint
extern void * const CExoArrayListTemplatedunsignedshort____vc;
// public void CExoArrayListTemplatedunsignedshort::Addunsigned short int
extern void * const CExoArrayListTemplatedunsignedshort__Add;
// void CExoArrayListTemplatedunsignedshort::AddUniqueunsigned short int
extern void * const CExoArrayListTemplatedunsignedshort__AddUnique;
// public void CExoArrayListTemplatedunsignedshort::Allocateint
extern void * const CExoArrayListTemplatedunsignedshort__Allocate;
// public int CExoArrayListTemplatedunsignedshort::Containsunsigned short int
extern void * const CExoArrayListTemplatedunsignedshort__Contains;
// void CExoArrayListTemplatedunsignedshort::DelIndexint
extern void * const CExoArrayListTemplatedunsignedshort__DelIndex;
// void CExoArrayListTemplatedunsignedshort::Insertunsigned short int, int
extern void * const CExoArrayListTemplatedunsignedshort__Insert;
// public void CExoArrayListTemplatedunsignedshort::Removeunsigned short int
extern void * const CExoArrayListTemplatedunsignedshort__Remove;
// public void CExoArrayListTemplatedunsignedshort::SetSizeint
extern void * const CExoArrayListTemplatedunsignedshort__SetSize;

// public CExoBase::CExoBasevoid
extern void * const CExoBase__CExoBaseCtor;
// public CExoBase::~CExoBasevoid
extern void * const CExoBase__CExoBaseDtor;
// void CExoBase::CheckForCDunsigned long int
extern void * const CExoBase__CheckForCD;
// public int CExoBase::GetAugmentedDirectoryListCExoArrayListTemplatedCFileInfo*, CExoString, unsigned short int, int
extern void * const CExoBase__GetAugmentedDirectoryList;
// public int CExoBase::GetDirectoryListCExoArrayListTemplatedCExoString*, CExoString, unsigned short int, int, int
extern void * const CExoBase__GetDirectoryList;
// public const CExoString& CExoBase::GetResourceExtensionunsigned short int
extern void * const CExoBase__GetResourceExtension;
// public unsigned short int CExoBase::GetResTypeFromExtensionconst CExoString&
extern void * const CExoBase__GetResTypeFromExtension;
// public void CExoBase::LoadAliasesCExoString
extern void * const CExoBase__LoadAliases;
// void CExoBase::ShutDownvoid
extern void * const CExoBase__ShutDown;
// void CExoBase::SpawnExternalApplicationconst CExoString&, const CExoString&, int
extern void * const CExoBase__SpawnExternalApplication;

// public CExoBaseInternal::CExoBaseInternalvoid
extern void * const CExoBaseInternal__CExoBaseInternalCtor;
// public CExoBaseInternal::~CExoBaseInternalvoid
extern void * const CExoBaseInternal__CExoBaseInternalDtor;
// public void CExoBaseInternal::AddAliasCExoString, CExoString, CExoString
extern void * const CExoBaseInternal__AddAlias;
// void CExoBaseInternal::CheckForCDunsigned long int
extern void * const CExoBaseInternal__CheckForCD;
// public void CExoBaseInternal::CreateResourceExtensionTablevoid
extern void * const CExoBaseInternal__CreateResourceExtensionTable;
// public int CExoBaseInternal::GetAugmentedDirectoryListCExoArrayListTemplatedCFileInfo*, CExoString, unsigned short int, int
extern void * const CExoBaseInternal__GetAugmentedDirectoryList;
// public int CExoBaseInternal::GetDirectoryListCExoArrayListTemplatedCExoString*, CExoString, unsigned short int, int, int
extern void * const CExoBaseInternal__GetDirectoryList;
// public const CExoString& CExoBaseInternal::GetResourceExtensionunsigned short int
extern void * const CExoBaseInternal__GetResourceExtension;
// public unsigned short int CExoBaseInternal::GetResTypeFromExtensionconst CExoString&
extern void * const CExoBaseInternal__GetResTypeFromExtension;
// public void CExoBaseInternal::LoadAliasesCExoString
extern void * const CExoBaseInternal__LoadAliases;
// void CExoBaseInternal::ShutDownvoid
extern void * const CExoBaseInternal__ShutDown;
// void CExoBaseInternal::SpawnExternalApplicationconst CExoString&, const CExoString&, int
extern void * const CExoBaseInternal__SpawnExternalApplication;

// public CExoCriticalSection::CExoCriticalSectionvoid
extern void * const CExoCriticalSection__CExoCriticalSectionCtor;
// public CExoCriticalSection::~CExoCriticalSectionvoid
extern void * const CExoCriticalSection__CExoCriticalSectionDtor;
// public void CExoCriticalSection::EnterCriticalSectionvoid
extern void * const CExoCriticalSection__EnterCriticalSection;
// public void CExoCriticalSection::LeaveCriticalSectionvoid
extern void * const CExoCriticalSection__LeaveCriticalSection;

// public CExoCriticalSectionInternal::CExoCriticalSectionInternalvoid
extern void * const CExoCriticalSectionInternal__CExoCriticalSectionInternalCtor;
// public CExoCriticalSectionInternal::~CExoCriticalSectionInternalvoid
extern void * const CExoCriticalSectionInternal__CExoCriticalSectionInternalDtor;
// public void CExoCriticalSectionInternal::EnterCriticalSectionvoid
extern void * const CExoCriticalSectionInternal__EnterCriticalSection;
// public void CExoCriticalSectionInternal::LeaveCriticalSectionvoid
extern void * const CExoCriticalSectionInternal__LeaveCriticalSection;

// public CExoDebug::CExoDebugvoid
extern void * const CExoDebug__CExoDebugCtor;
// public CExoDebug::~CExoDebugvoid
extern void * const CExoDebug__CExoDebugDtor;
// void CExoDebug::Assertint, char*, const char*
extern void * const CExoDebug__Assert;
// void CExoDebug::CloseLogFilesvoid
extern void * const CExoDebug__CloseLogFiles;
// public void CExoDebug::FlushErrorFilevoid
extern void * const CExoDebug__FlushErrorFile;
// public void CExoDebug::FlushLogFilevoid
extern void * const CExoDebug__FlushLogFile;
// void CExoDebug::GetCurrentAllocatedMemoryvoid
extern void * const CExoDebug__GetCurrentAllocatedMemory;
// void CExoDebug::GetCurrentMemoryAllocationsvoid
extern void * const CExoDebug__GetCurrentMemoryAllocations;
// public void CExoDebug::GetCurrentTimestampCExoString&
extern void * const CExoDebug__GetCurrentTimestamp;
// void CExoDebug::GetMaxAllocatedMemoryvoid
extern void * const CExoDebug__GetMaxAllocatedMemory;
// void CExoDebug::GetTotalMemoryAllocationsvoid
extern void * const CExoDebug__GetTotalMemoryAllocations;
// public void CExoDebug::NoLog...
extern void * const CExoDebug__NoLog;
// public void CExoDebug::OpenLogFilesCExoString, int
extern void * const CExoDebug__OpenLogFiles;
// public void CExoDebug::SetRotateLogFileint
extern void * const CExoDebug__SetRotateLogFile;
// public void CExoDebug::Warningint, char*, const char*
extern void * const CExoDebug__Warning;
// public void CExoDebug::WriteToErrorFileconst CExoString&
extern void * const CExoDebug__WriteToErrorFile;
// public void CExoDebug::WriteToLogFileconst CExoString&
extern void * const CExoDebug__WriteToLogFile;

// public CExoDebugInternal::CExoDebugInternalvoid
extern void * const CExoDebugInternal__CExoDebugInternalCtor;
// public CExoDebugInternal::~CExoDebugInternalvoid
extern void * const CExoDebugInternal__CExoDebugInternalDtor;
// void CExoDebugInternal::Assertint, char*, const char*
extern void * const CExoDebugInternal__Assert;
// public void CExoDebugInternal::CloseLogFilesvoid
extern void * const CExoDebugInternal__CloseLogFiles;
// void CExoDebugInternal::CreateDirectoryCExoString
extern void * const CExoDebugInternal__CreateDirectory;
// void CExoDebugInternal::FlushErrorFilevoid
extern void * const CExoDebugInternal__FlushErrorFile;
// public void CExoDebugInternal::FlushLogFilevoid
extern void * const CExoDebugInternal__FlushLogFile;
// public void CExoDebugInternal::GetCurrentTimestampCExoString&
extern void * const CExoDebugInternal__GetCurrentTimestamp;
// public void CExoDebugInternal::OpenLogFilesCExoString, int
extern void * const CExoDebugInternal__OpenLogFiles;
// void CExoDebugInternal::Warningint, char*, const char*
extern void * const CExoDebugInternal__Warning;
// void CExoDebugInternal::WriteToErrorFileconst CExoString&
extern void * const CExoDebugInternal__WriteToErrorFile;
// public void CExoDebugInternal::WriteToLogFileconst CExoString&
extern void * const CExoDebugInternal__WriteToLogFile;

// CExoEncapsulatedFile::CExoEncapsulatedFilevoid
extern void * const CExoEncapsulatedFile__CExoEncapsulatedFileCtor;
// public CExoEncapsulatedFile::~CExoEncapsulatedFilevoid
extern void * const CExoEncapsulatedFile__CExoEncapsulatedFileDtor;
// public void CExoEncapsulatedFile::AddAsyncRefCountvoid
extern void * const CExoEncapsulatedFile__AddAsyncRefCount;
// public void CExoEncapsulatedFile::AddRefCountvoid
extern void * const CExoEncapsulatedFile__AddRefCount;
// public int CExoEncapsulatedFile::CloseAsyncFilevoid
extern void * const CExoEncapsulatedFile__CloseAsyncFile;
// public int CExoEncapsulatedFile::CloseFilevoid
extern void * const CExoEncapsulatedFile__CloseFile;
// public void CExoEncapsulatedFile::DeleteAsyncRefCountvoid
extern void * const CExoEncapsulatedFile__DeleteAsyncRefCount;
// public void CExoEncapsulatedFile::DeleteRefCountvoid
extern void * const CExoEncapsulatedFile__DeleteRefCount;
// void CExoEncapsulatedFile::GetDescriptionvoid
extern void * const CExoEncapsulatedFile__GetDescription;
// public unsigned long int CExoEncapsulatedFile::GetResourceSizeunsigned long int
extern void * const CExoEncapsulatedFile__GetResourceSize;
// public int CExoEncapsulatedFile::Initializevoid
extern void * const CExoEncapsulatedFile__Initialize;
// public int CExoEncapsulatedFile::LoadHeaderunsigned char
extern void * const CExoEncapsulatedFile__LoadHeader;
// public int CExoEncapsulatedFile::OpenAsyncFilevoid
extern void * const CExoEncapsulatedFile__OpenAsyncFile;
// public int CExoEncapsulatedFile::OpenFilevoid
extern void * const CExoEncapsulatedFile__OpenFile__0;
// public int CExoEncapsulatedFile::OpenFileunsigned char*
extern void * const CExoEncapsulatedFile__OpenFile__1;
// public unsigned long int CExoEncapsulatedFile::ReadResourceunsigned long int, void*, unsigned long int, unsigned long int
extern void * const CExoEncapsulatedFile__ReadResource;
// public void CExoEncapsulatedFile::ReadResourceAsyncunsigned long int, void*, unsigned long int, unsigned long int
extern void * const CExoEncapsulatedFile__ReadResourceAsync;
// public int CExoEncapsulatedFile::UnloadHeadervoid
extern void * const CExoEncapsulatedFile__UnloadHeader;

// public CExoString CExoEncrypt::EncryptStringconst CExoString&
extern void * const CExoEncrypt__EncryptString;
// public CExoString CExoEncrypt::GenerateChallengeunsigned short int
extern void * const CExoEncrypt__GenerateChallenge;

// public CExoFile::CExoFileconst CExoString&, unsigned short int, const CExoString&
extern void * const CExoFile__CExoFileCtor;
// public CExoFile::~CExoFilevoid
extern void * const CExoFile__CExoFileDtor;
// void CExoFile::Eofvoid
extern void * const CExoFile__Eof;
// public int CExoFile::FileOpenedvoid
extern void * const CExoFile__FileOpened;
// public int CExoFile::Flushvoid
extern void * const CExoFile__Flush;
// public unsigned long int CExoFile::GetOffsetvoid
extern void * const CExoFile__GetOffset;
// public int CExoFile::GetSizevoid
extern void * const CExoFile__GetSize;
// public unsigned long int CExoFile::Readvoid*, unsigned long int, unsigned long int
extern void * const CExoFile__Read__0;
// public unsigned long int CExoFile::ReadCExoString&, unsigned long int
extern void * const CExoFile__Read__1;
// public void CExoFile::ReadAsyncvoid*, unsigned long int, unsigned long int
extern void * const CExoFile__ReadAsync;
// void CExoFile::ReadAsyncBytesReadvoid
extern void * const CExoFile__ReadAsyncBytesRead;
// public int CExoFile::ReadAsyncCompletevoid
extern void * const CExoFile__ReadAsyncComplete;
// void CExoFile::ReadStringLineFromBufferunsigned char**, unsigned long int*, unsigned char*, unsigned long int
extern void * const CExoFile__ReadStringLineFromBuffer;
// public int CExoFile::Seekint, int
extern void * const CExoFile__Seek;
// public int CExoFile::SeekBeginningvoid
extern void * const CExoFile__SeekBeginning;
// public int CExoFile::SeekEndvoid
extern void * const CExoFile__SeekEnd;
// public unsigned long int CExoFile::Writeconst void*, unsigned long int, unsigned long int
extern void * const CExoFile__Write__0;
// public unsigned long int CExoFile::Writeconst char*
extern void * const CExoFile__Write__1;
// public unsigned long int CExoFile::Writeconst CExoString&
extern void * const CExoFile__Write__2;

// public CExoFileInternal::CExoFileInternalconst CExoString&, unsigned short int, const CExoString&
extern void * const CExoFileInternal__CExoFileInternalCtor;
// public CExoFileInternal::~CExoFileInternalvoid
extern void * const CExoFileInternal__CExoFileInternalDtor;
// public unsigned long int CExoFileInternal::GetOffsetvoid
extern void * const CExoFileInternal__GetOffset;
// public int CExoFileInternal::GetSizevoid
extern void * const CExoFileInternal__GetSize;
// public unsigned long int CExoFileInternal::ReadCExoString*, unsigned long int
extern void * const CExoFileInternal__Read;
// public void CExoFileInternal::ReadAsyncvoid*, unsigned long int, unsigned long int
extern void * const CExoFileInternal__ReadAsync;
// void CExoFileInternal::ReadAsyncBytesReadvoid
extern void * const CExoFileInternal__ReadAsyncBytesRead;
// public int CExoFileInternal::ReadAsyncCompletevoid
extern void * const CExoFileInternal__ReadAsyncComplete;
// void CExoFileInternal::Writeconst char*
extern void * const CExoFileInternal__Write;

// public CExoFileThread::CExoFileThreadvoid
extern void * const CExoFileThread__CExoFileThreadCtor;
// void CExoFileThread::AsyncReadvoid
extern void * const CExoFileThread__AsyncRead;
// void CExoFileThread::Readvoid*, unsigned long int, unsigned long int, _IO_FILE*
extern void * const CExoFileThread__Read;

// public CExoIni::CExoInivoid
extern void * const CExoIni__CExoIniCtor;
// public CExoIni::~CExoInivoid
extern void * const CExoIni__CExoIniDtor;
// public int CExoIni::ReadIniEntryCExoString&, const CExoString&, const CExoString&, const CExoString&
extern void * const CExoIni__ReadIniEntry;
// public int CExoIni::WriteIniEntryconst CExoString&, const CExoString&, const CExoString&, const CExoString&
extern void * const CExoIni__WriteIniEntry;

// public CExoIniInternal::CExoIniInternalvoid
extern void * const CExoIniInternal__CExoIniInternalCtor;
// public CExoIniInternal::~CExoIniInternalvoid
extern void * const CExoIniInternal__CExoIniInternalDtor;
// public int CExoIniInternal::ReadIniEntryCExoString&, const CExoString&, const CExoString&, const CExoString&
extern void * const CExoIniInternal__ReadIniEntry;
// public int CExoIniInternal::WriteIniEntryconst CExoString&, const CExoString&, const CExoString&, const CExoString&
extern void * const CExoIniInternal__WriteIniEntry;

// public CExoKeyTable::CExoKeyTablevoid
extern void * const CExoKeyTable__CExoKeyTableCtor;
// public CExoKeyTable::~CExoKeyTablevoid
extern void * const CExoKeyTable__CExoKeyTableDtor;
// public int CExoKeyTable::AddDirectoryContentsint
extern void * const CExoKeyTable__AddDirectoryContents;
// public int CExoKeyTable::AddEncapsulatedContentsint
extern void * const CExoKeyTable__AddEncapsulatedContents;
// public CKeyTableEntry* CExoKeyTable::AddKeyconst CResRef&, unsigned short int, unsigned long int, int
extern void * const CExoKeyTable__AddKey;
// public int CExoKeyTable::AddKeyTableContentsint
extern void * const CExoKeyTable__AddKeyTableContents;
// public int CExoKeyTable::AddResourceImageContentsint, unsigned char*
extern void * const CExoKeyTable__AddResourceImageContents;
// void CExoKeyTable::AllocateTableunsigned long int, int
extern void * const CExoKeyTable__AllocateTable;
// public int CExoKeyTable::BuildNewTableunsigned long int, const CExoString&, unsigned long int, int, unsigned char*
extern void * const CExoKeyTable__BuildNewTable;
// void CExoKeyTable::DeleteTableListCExoLinkedListTemplatedCKeyTableInfo*
extern void * const CExoKeyTable__DeleteTableList;
// public void CExoKeyTable::DestroyTablevoid
extern void * const CExoKeyTable__DestroyTable;
// public CKeyTableEntry* CExoKeyTable::FindKeyconst CResRef&, unsigned short int
extern void * const CExoKeyTable__FindKey__0;
// public CKeyTableEntry* CExoKeyTable::FindKeyCRes*
extern void * const CExoKeyTable__FindKey__1;
// public int CExoKeyTable::GetEntryCountint
extern void * const CExoKeyTable__GetEntryCount;
// public CExoStringList* CExoKeyTable::GetKeysOfTypeunsigned short int
extern void * const CExoKeyTable__GetKeysOfType;
// void CExoKeyTable::GetResconst CResRef&, unsigned short int
extern void * const CExoKeyTable__GetRes;
// void CExoKeyTable::GetResIDconst CResRef&, unsigned short int
extern void * const CExoKeyTable__GetResID;
// void CExoKeyTable::GetTableEntryunsigned long int, CResRef&, unsigned short int&
extern void * const CExoKeyTable__GetTableEntry;
// void CExoKeyTable::GetTableIndexunsigned long int&, const CResRef&, unsigned short int
extern void * const CExoKeyTable__GetTableIndex;
// void CExoKeyTable::Hashconst CResRef&, unsigned short int
extern void * const CExoKeyTable__Hash;
// public int CExoKeyTable::LocateBifFileconst CExoString&
extern void * const CExoKeyTable__LocateBifFile;
// public void CExoKeyTable::RebuildTableunsigned char*
extern void * const CExoKeyTable__RebuildTable;

// public CExoLinkedListInternal::~CExoLinkedListInternalvoid
extern void * const CExoLinkedListInternal__CExoLinkedListInternalDtor;
// public CExoLinkedListNode* CExoLinkedListInternal::AddAftervoid*, CExoLinkedListNode*
extern void * const CExoLinkedListInternal__AddAfter;
// public CExoLinkedListNode* CExoLinkedListInternal::AddBeforevoid*, CExoLinkedListNode*
extern void * const CExoLinkedListInternal__AddBefore;
// public CExoLinkedListNode* CExoLinkedListInternal::AddHeadvoid*
extern void * const CExoLinkedListInternal__AddHead;
// public CExoLinkedListNode* CExoLinkedListInternal::AddTailvoid*
extern void * const CExoLinkedListInternal__AddTail;
// public void* CExoLinkedListInternal::GetAtPosCExoLinkedListNode*
extern void * const CExoLinkedListInternal__GetAtPos;
// public void* CExoLinkedListInternal::GetNextCExoLinkedListNode*
extern void * const CExoLinkedListInternal__GetNext;
// public void* CExoLinkedListInternal::GetPrevCExoLinkedListNode*
extern void * const CExoLinkedListInternal__GetPrev;
// public void* CExoLinkedListInternal::RemoveCExoLinkedListNode*
extern void * const CExoLinkedListInternal__Remove;
// public void* CExoLinkedListInternal::RemoveHeadvoid
extern void * const CExoLinkedListInternal__RemoveHead;
// public void* CExoLinkedListInternal::RemoveTailvoid
extern void * const CExoLinkedListInternal__RemoveTail;

// CExoLinkedListTemplatedC2DA::CExoLinkedListTemplatedC2DAvoid
extern void * const CExoLinkedListTemplatedC2DA__CExoLinkedListTemplatedC2DACtor;
// void CExoLinkedListTemplatedC2DA::AddHeadC2DA*
extern void * const CExoLinkedListTemplatedC2DA__AddHead;
// void CExoLinkedListTemplatedC2DA::Countvoid
extern void * const CExoLinkedListTemplatedC2DA__Count;
// void CExoLinkedListTemplatedC2DA::GetAtPosCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedC2DA__GetAtPos;
// void CExoLinkedListTemplatedC2DA::GetHeadPosvoid
extern void * const CExoLinkedListTemplatedC2DA__GetHeadPos;
// void CExoLinkedListTemplatedC2DA::GetNextCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedC2DA__GetNext;
// void CExoLinkedListTemplatedC2DA::IsEmptyvoid
extern void * const CExoLinkedListTemplatedC2DA__IsEmpty;
// void CExoLinkedListTemplatedC2DA::RemoveCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedC2DA__Remove;
// void CExoLinkedListTemplatedC2DA::RemoveHeadvoid
extern void * const CExoLinkedListTemplatedC2DA__RemoveHead;
// void CExoLinkedListTemplatedC2DA::RemoveTailvoid
extern void * const CExoLinkedListTemplatedC2DA__RemoveTail;

// CExoLinkedListTemplatedCERFKey::CExoLinkedListTemplatedCERFKeyvoid
extern void * const CExoLinkedListTemplatedCERFKey__CExoLinkedListTemplatedCERFKeyCtor__0;
// CExoLinkedListTemplatedCERFKey::CExoLinkedListTemplatedCERFKeyvoid
extern void * const CExoLinkedListTemplatedCERFKey__CExoLinkedListTemplatedCERFKeyCtor__1;
// void CExoLinkedListTemplatedCERFKey::AddTailCERFKey*
extern void * const CExoLinkedListTemplatedCERFKey__AddTail;
// void CExoLinkedListTemplatedCERFKey::Countvoid
extern void * const CExoLinkedListTemplatedCERFKey__Count;
// void CExoLinkedListTemplatedCERFKey::GetAtPosCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCERFKey__GetAtPos;
// void CExoLinkedListTemplatedCERFKey::GetHeadPosvoid
extern void * const CExoLinkedListTemplatedCERFKey__GetHeadPos;
// void CExoLinkedListTemplatedCERFKey::GetNextCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCERFKey__GetNext;
// void CExoLinkedListTemplatedCERFKey::IsEmptyvoid
extern void * const CExoLinkedListTemplatedCERFKey__IsEmpty;
// void CExoLinkedListTemplatedCERFKey::RemoveCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCERFKey__Remove;
// void CExoLinkedListTemplatedCERFKey::RemoveHeadvoid
extern void * const CExoLinkedListTemplatedCERFKey__RemoveHead;

// CExoLinkedListTemplatedCERFRes::CExoLinkedListTemplatedCERFResvoid
extern void * const CExoLinkedListTemplatedCERFRes__CExoLinkedListTemplatedCERFResCtor__0;
// CExoLinkedListTemplatedCERFRes::CExoLinkedListTemplatedCERFResvoid
extern void * const CExoLinkedListTemplatedCERFRes__CExoLinkedListTemplatedCERFResCtor__1;
// void CExoLinkedListTemplatedCERFRes::AddTailCERFRes*
extern void * const CExoLinkedListTemplatedCERFRes__AddTail;
// void CExoLinkedListTemplatedCERFRes::Countvoid
extern void * const CExoLinkedListTemplatedCERFRes__Count;
// void CExoLinkedListTemplatedCERFRes::GetAtPosCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCERFRes__GetAtPos;
// void CExoLinkedListTemplatedCERFRes::GetHeadPosvoid
extern void * const CExoLinkedListTemplatedCERFRes__GetHeadPos;
// void CExoLinkedListTemplatedCERFRes::GetNextCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCERFRes__GetNext;
// void CExoLinkedListTemplatedCERFRes::IsEmptyvoid
extern void * const CExoLinkedListTemplatedCERFRes__IsEmpty;
// void CExoLinkedListTemplatedCERFRes::RemoveCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCERFRes__Remove;
// void CExoLinkedListTemplatedCERFRes::RemoveHeadvoid
extern void * const CExoLinkedListTemplatedCERFRes__RemoveHead;

// CExoLinkedListTemplatedCERFString::CExoLinkedListTemplatedCERFStringvoid
extern void * const CExoLinkedListTemplatedCERFString__CExoLinkedListTemplatedCERFStringCtor__0;
// CExoLinkedListTemplatedCERFString::CExoLinkedListTemplatedCERFStringvoid
extern void * const CExoLinkedListTemplatedCERFString__CExoLinkedListTemplatedCERFStringCtor__1;
// void CExoLinkedListTemplatedCERFString::AddTailCERFString*
extern void * const CExoLinkedListTemplatedCERFString__AddTail;
// void CExoLinkedListTemplatedCERFString::Countvoid
extern void * const CExoLinkedListTemplatedCERFString__Count;
// void CExoLinkedListTemplatedCERFString::GetAtPosCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCERFString__GetAtPos;
// void CExoLinkedListTemplatedCERFString::GetHeadPosvoid
extern void * const CExoLinkedListTemplatedCERFString__GetHeadPos;
// void CExoLinkedListTemplatedCERFString::GetNextCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCERFString__GetNext;
// void CExoLinkedListTemplatedCERFString::IsEmptyvoid
extern void * const CExoLinkedListTemplatedCERFString__IsEmpty;
// void CExoLinkedListTemplatedCERFString::RemoveHeadvoid
extern void * const CExoLinkedListTemplatedCERFString__RemoveHead;

// CExoLinkedListTemplatedCExoKeyTable::CExoLinkedListTemplatedCExoKeyTablevoid
extern void * const CExoLinkedListTemplatedCExoKeyTable__CExoLinkedListTemplatedCExoKeyTableCtor__0;
// CExoLinkedListTemplatedCExoKeyTable::CExoLinkedListTemplatedCExoKeyTablevoid
extern void * const CExoLinkedListTemplatedCExoKeyTable__CExoLinkedListTemplatedCExoKeyTableCtor__1;
// void CExoLinkedListTemplatedCExoKeyTable::AddHeadCExoKeyTable*
extern void * const CExoLinkedListTemplatedCExoKeyTable__AddHead;
// void CExoLinkedListTemplatedCExoKeyTable::GetAtPosCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCExoKeyTable__GetAtPos;
// void CExoLinkedListTemplatedCExoKeyTable::GetHeadPosvoid
extern void * const CExoLinkedListTemplatedCExoKeyTable__GetHeadPos;
// void CExoLinkedListTemplatedCExoKeyTable::GetNextCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCExoKeyTable__GetNext;
// void CExoLinkedListTemplatedCExoKeyTable::GetPrevCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCExoKeyTable__GetPrev;
// void CExoLinkedListTemplatedCExoKeyTable::GetTailPosvoid
extern void * const CExoLinkedListTemplatedCExoKeyTable__GetTailPos;
// void CExoLinkedListTemplatedCExoKeyTable::RemoveCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCExoKeyTable__Remove;

// public CExoLinkedListTemplatedCExoString::CExoLinkedListTemplatedCExoStringvoid
extern void * const CExoLinkedListTemplatedCExoString__CExoLinkedListTemplatedCExoStringCtor__0;
// public CExoLinkedListTemplatedCExoString::CExoLinkedListTemplatedCExoStringvoid
extern void * const CExoLinkedListTemplatedCExoString__CExoLinkedListTemplatedCExoStringCtor__1;
// void CExoLinkedListTemplatedCExoString::AddTailCExoString*
extern void * const CExoLinkedListTemplatedCExoString__AddTail;
// void CExoLinkedListTemplatedCExoString::GetAtPosCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCExoString__GetAtPos;
// void CExoLinkedListTemplatedCExoString::GetHeadPosvoid
extern void * const CExoLinkedListTemplatedCExoString__GetHeadPos;
// void CExoLinkedListTemplatedCExoString::GetNextCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCExoString__GetNext;
// void CExoLinkedListTemplatedCExoString::IsEmptyvoid
extern void * const CExoLinkedListTemplatedCExoString__IsEmpty;
// void CExoLinkedListTemplatedCExoString::RemoveCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCExoString__Remove;
// void CExoLinkedListTemplatedCExoString::RemoveHeadvoid
extern void * const CExoLinkedListTemplatedCExoString__RemoveHead;

// CExoLinkedListTemplatedCKeyTableInfo::CExoLinkedListTemplatedCKeyTableInfovoid
extern void * const CExoLinkedListTemplatedCKeyTableInfo__CExoLinkedListTemplatedCKeyTableInfoCtor__0;
// CExoLinkedListTemplatedCKeyTableInfo::CExoLinkedListTemplatedCKeyTableInfovoid
extern void * const CExoLinkedListTemplatedCKeyTableInfo__CExoLinkedListTemplatedCKeyTableInfoCtor__1;
// void CExoLinkedListTemplatedCKeyTableInfo::AddTailCKeyTableInfo*
extern void * const CExoLinkedListTemplatedCKeyTableInfo__AddTail;
// void CExoLinkedListTemplatedCKeyTableInfo::GetAtPosCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCKeyTableInfo__GetAtPos;
// void CExoLinkedListTemplatedCKeyTableInfo::GetHeadPosvoid
extern void * const CExoLinkedListTemplatedCKeyTableInfo__GetHeadPos;
// void CExoLinkedListTemplatedCKeyTableInfo::RemoveHeadvoid
extern void * const CExoLinkedListTemplatedCKeyTableInfo__RemoveHead;

// CExoLinkedListTemplatedCLastUpdateObject::CExoLinkedListTemplatedCLastUpdateObjectvoid
extern void * const CExoLinkedListTemplatedCLastUpdateObject__CExoLinkedListTemplatedCLastUpdateObjectCtor__0;
// CExoLinkedListTemplatedCLastUpdateObject::CExoLinkedListTemplatedCLastUpdateObjectvoid
extern void * const CExoLinkedListTemplatedCLastUpdateObject__CExoLinkedListTemplatedCLastUpdateObjectCtor__1;
// void CExoLinkedListTemplatedCLastUpdateObject::AddHeadCLastUpdateObject*
extern void * const CExoLinkedListTemplatedCLastUpdateObject__AddHead;
// void CExoLinkedListTemplatedCLastUpdateObject::GetAtPosCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCLastUpdateObject__GetAtPos;
// void CExoLinkedListTemplatedCLastUpdateObject::GetHeadPosvoid
extern void * const CExoLinkedListTemplatedCLastUpdateObject__GetHeadPos;
// void CExoLinkedListTemplatedCLastUpdateObject::GetNextCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCLastUpdateObject__GetNext;
// void CExoLinkedListTemplatedCLastUpdateObject::IsEmptyvoid
extern void * const CExoLinkedListTemplatedCLastUpdateObject__IsEmpty;
// void CExoLinkedListTemplatedCLastUpdateObject::RemoveCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCLastUpdateObject__Remove;
// void CExoLinkedListTemplatedCLastUpdateObject::RemoveHeadvoid
extern void * const CExoLinkedListTemplatedCLastUpdateObject__RemoveHead;

// CExoLinkedListTemplatedCLastUpdatePartyObject::CExoLinkedListTemplatedCLastUpdatePartyObjectvoid
extern void * const CExoLinkedListTemplatedCLastUpdatePartyObject__CExoLinkedListTemplatedCLastUpdatePartyObjectCtor__0;
// CExoLinkedListTemplatedCLastUpdatePartyObject::CExoLinkedListTemplatedCLastUpdatePartyObjectvoid
extern void * const CExoLinkedListTemplatedCLastUpdatePartyObject__CExoLinkedListTemplatedCLastUpdatePartyObjectCtor__1;
// void CExoLinkedListTemplatedCLastUpdatePartyObject::AddHeadCLastUpdatePartyObject*
extern void * const CExoLinkedListTemplatedCLastUpdatePartyObject__AddHead;
// void CExoLinkedListTemplatedCLastUpdatePartyObject::GetAtPosCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCLastUpdatePartyObject__GetAtPos;
// void CExoLinkedListTemplatedCLastUpdatePartyObject::GetHeadPosvoid
extern void * const CExoLinkedListTemplatedCLastUpdatePartyObject__GetHeadPos;
// void CExoLinkedListTemplatedCLastUpdatePartyObject::GetNextCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCLastUpdatePartyObject__GetNext;
// void CExoLinkedListTemplatedCLastUpdatePartyObject::RemoveCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCLastUpdatePartyObject__Remove;

// CExoLinkedListTemplatedCLinuxFileKey::CExoLinkedListTemplatedCLinuxFileKeyvoid
extern void * const CExoLinkedListTemplatedCLinuxFileKey__CExoLinkedListTemplatedCLinuxFileKeyCtor__0;
// CExoLinkedListTemplatedCLinuxFileKey::CExoLinkedListTemplatedCLinuxFileKeyvoid
extern void * const CExoLinkedListTemplatedCLinuxFileKey__CExoLinkedListTemplatedCLinuxFileKeyCtor__1;
// void CExoLinkedListTemplatedCLinuxFileKey::AddHeadCLinuxFileKey*
extern void * const CExoLinkedListTemplatedCLinuxFileKey__AddHead;
// void CExoLinkedListTemplatedCLinuxFileKey::AddTailCLinuxFileKey*
extern void * const CExoLinkedListTemplatedCLinuxFileKey__AddTail;
// void CExoLinkedListTemplatedCLinuxFileKey::GetHeadvoid
extern void * const CExoLinkedListTemplatedCLinuxFileKey__GetHead;
// void CExoLinkedListTemplatedCLinuxFileKey::GetHeadPosvoid
extern void * const CExoLinkedListTemplatedCLinuxFileKey__GetHeadPos;
// void CExoLinkedListTemplatedCLinuxFileKey::GetNextCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCLinuxFileKey__GetNext;
// void CExoLinkedListTemplatedCLinuxFileKey::IsEmptyvoid
extern void * const CExoLinkedListTemplatedCLinuxFileKey__IsEmpty;
// void CExoLinkedListTemplatedCLinuxFileKey::RemoveCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCLinuxFileKey__Remove;
// void CExoLinkedListTemplatedCLinuxFileKey::RemoveHeadvoid
extern void * const CExoLinkedListTemplatedCLinuxFileKey__RemoveHead;

// CExoLinkedListTemplatedCLinuxFileSection::CExoLinkedListTemplatedCLinuxFileSectionvoid
extern void * const CExoLinkedListTemplatedCLinuxFileSection__CExoLinkedListTemplatedCLinuxFileSectionCtor__0;
// CExoLinkedListTemplatedCLinuxFileSection::CExoLinkedListTemplatedCLinuxFileSectionvoid
extern void * const CExoLinkedListTemplatedCLinuxFileSection__CExoLinkedListTemplatedCLinuxFileSectionCtor__1;
// void CExoLinkedListTemplatedCLinuxFileSection::AddTailCLinuxFileSection*
extern void * const CExoLinkedListTemplatedCLinuxFileSection__AddTail;
// void CExoLinkedListTemplatedCLinuxFileSection::GetHeadvoid
extern void * const CExoLinkedListTemplatedCLinuxFileSection__GetHead;
// void CExoLinkedListTemplatedCLinuxFileSection::GetHeadPosvoid
extern void * const CExoLinkedListTemplatedCLinuxFileSection__GetHeadPos;
// void CExoLinkedListTemplatedCLinuxFileSection::GetNextCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCLinuxFileSection__GetNext;
// void CExoLinkedListTemplatedCLinuxFileSection::IsEmptyvoid
extern void * const CExoLinkedListTemplatedCLinuxFileSection__IsEmpty;
// void CExoLinkedListTemplatedCLinuxFileSection::RemoveCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCLinuxFileSection__Remove;
// void CExoLinkedListTemplatedCLinuxFileSection::RemoveHeadvoid
extern void * const CExoLinkedListTemplatedCLinuxFileSection__RemoveHead;

// CExoLinkedListTemplatedCNWSClient::CExoLinkedListTemplatedCNWSClientvoid
extern void * const CExoLinkedListTemplatedCNWSClient__CExoLinkedListTemplatedCNWSClientCtor__0;
// CExoLinkedListTemplatedCNWSClient::CExoLinkedListTemplatedCNWSClientvoid
extern void * const CExoLinkedListTemplatedCNWSClient__CExoLinkedListTemplatedCNWSClientCtor__1;
// void CExoLinkedListTemplatedCNWSClient::AddHeadCNWSClient*
extern void * const CExoLinkedListTemplatedCNWSClient__AddHead;
// void CExoLinkedListTemplatedCNWSClient::Countvoid
extern void * const CExoLinkedListTemplatedCNWSClient__Count;
// void CExoLinkedListTemplatedCNWSClient::GetAtPosCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCNWSClient__GetAtPos;
// void CExoLinkedListTemplatedCNWSClient::GetHeadvoid
extern void * const CExoLinkedListTemplatedCNWSClient__GetHead;
// void CExoLinkedListTemplatedCNWSClient::GetHeadPosvoid
extern void * const CExoLinkedListTemplatedCNWSClient__GetHeadPos;
// void CExoLinkedListTemplatedCNWSClient::GetNextCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCNWSClient__GetNext;
// void CExoLinkedListTemplatedCNWSClient::IsEmptyvoid
extern void * const CExoLinkedListTemplatedCNWSClient__IsEmpty;
// void CExoLinkedListTemplatedCNWSClient::RemoveCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCNWSClient__Remove;
// void CExoLinkedListTemplatedCNWSClient::RemoveHeadvoid
extern void * const CExoLinkedListTemplatedCNWSClient__RemoveHead;

// CExoLinkedListTemplatedCNWSCombatRoundAction::CExoLinkedListTemplatedCNWSCombatRoundActionvoid
extern void * const CExoLinkedListTemplatedCNWSCombatRoundAction__CExoLinkedListTemplatedCNWSCombatRoundActionCtor__0;
// CExoLinkedListTemplatedCNWSCombatRoundAction::CExoLinkedListTemplatedCNWSCombatRoundActionvoid
extern void * const CExoLinkedListTemplatedCNWSCombatRoundAction__CExoLinkedListTemplatedCNWSCombatRoundActionCtor__1;
// void CExoLinkedListTemplatedCNWSCombatRoundAction::AddBeforeCNWSCombatRoundAction*, CExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCNWSCombatRoundAction__AddBefore;
// void CExoLinkedListTemplatedCNWSCombatRoundAction::AddTailCNWSCombatRoundAction*
extern void * const CExoLinkedListTemplatedCNWSCombatRoundAction__AddTail;
// void CExoLinkedListTemplatedCNWSCombatRoundAction::GetAtPosCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCNWSCombatRoundAction__GetAtPos;
// void CExoLinkedListTemplatedCNWSCombatRoundAction::GetHeadvoid
extern void * const CExoLinkedListTemplatedCNWSCombatRoundAction__GetHead;
// void CExoLinkedListTemplatedCNWSCombatRoundAction::GetHeadPosvoid
extern void * const CExoLinkedListTemplatedCNWSCombatRoundAction__GetHeadPos;
// void CExoLinkedListTemplatedCNWSCombatRoundAction::GetNextCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCNWSCombatRoundAction__GetNext;
// void CExoLinkedListTemplatedCNWSCombatRoundAction::GetPrevCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCNWSCombatRoundAction__GetPrev;
// void CExoLinkedListTemplatedCNWSCombatRoundAction::GetTailPosvoid
extern void * const CExoLinkedListTemplatedCNWSCombatRoundAction__GetTailPos;
// void CExoLinkedListTemplatedCNWSCombatRoundAction::IsEmptyvoid
extern void * const CExoLinkedListTemplatedCNWSCombatRoundAction__IsEmpty;
// void CExoLinkedListTemplatedCNWSCombatRoundAction::RemoveCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCNWSCombatRoundAction__Remove;
// void CExoLinkedListTemplatedCNWSCombatRoundAction::RemoveHeadvoid
extern void * const CExoLinkedListTemplatedCNWSCombatRoundAction__RemoveHead;

// CExoLinkedListTemplatedCNWSDialogPlayer::CExoLinkedListTemplatedCNWSDialogPlayervoid
extern void * const CExoLinkedListTemplatedCNWSDialogPlayer__CExoLinkedListTemplatedCNWSDialogPlayerCtor__0;
// CExoLinkedListTemplatedCNWSDialogPlayer::CExoLinkedListTemplatedCNWSDialogPlayervoid
extern void * const CExoLinkedListTemplatedCNWSDialogPlayer__CExoLinkedListTemplatedCNWSDialogPlayerCtor__1;
// void CExoLinkedListTemplatedCNWSDialogPlayer::AddTailCNWSDialogPlayer*
extern void * const CExoLinkedListTemplatedCNWSDialogPlayer__AddTail;
// public unsigned long int CExoLinkedListTemplatedCNWSDialogPlayer::Countvoid
extern void * const CExoLinkedListTemplatedCNWSDialogPlayer__Count;
// void CExoLinkedListTemplatedCNWSDialogPlayer::GetHeadvoid
extern void * const CExoLinkedListTemplatedCNWSDialogPlayer__GetHead;
// void CExoLinkedListTemplatedCNWSDialogPlayer::GetHeadPosvoid
extern void * const CExoLinkedListTemplatedCNWSDialogPlayer__GetHeadPos;
// void CExoLinkedListTemplatedCNWSDialogPlayer::GetNextCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCNWSDialogPlayer__GetNext;
// void CExoLinkedListTemplatedCNWSDialogPlayer::IsEmptyvoid
extern void * const CExoLinkedListTemplatedCNWSDialogPlayer__IsEmpty;
// void CExoLinkedListTemplatedCNWSDialogPlayer::RemoveCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCNWSDialogPlayer__Remove;
// void CExoLinkedListTemplatedCNWSDialogPlayer::RemoveHeadvoid
extern void * const CExoLinkedListTemplatedCNWSDialogPlayer__RemoveHead;

// CExoLinkedListTemplatedCNWSObjectActionNode::CExoLinkedListTemplatedCNWSObjectActionNodevoid
extern void * const CExoLinkedListTemplatedCNWSObjectActionNode__CExoLinkedListTemplatedCNWSObjectActionNodeCtor__0;
// CExoLinkedListTemplatedCNWSObjectActionNode::CExoLinkedListTemplatedCNWSObjectActionNodevoid
extern void * const CExoLinkedListTemplatedCNWSObjectActionNode__CExoLinkedListTemplatedCNWSObjectActionNodeCtor__1;
// void CExoLinkedListTemplatedCNWSObjectActionNode::AddBeforeCNWSObjectActionNode*, CExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCNWSObjectActionNode__AddBefore;
// void CExoLinkedListTemplatedCNWSObjectActionNode::AddHeadCNWSObjectActionNode*
extern void * const CExoLinkedListTemplatedCNWSObjectActionNode__AddHead;
// void CExoLinkedListTemplatedCNWSObjectActionNode::AddTailCNWSObjectActionNode*
extern void * const CExoLinkedListTemplatedCNWSObjectActionNode__AddTail;
// void CExoLinkedListTemplatedCNWSObjectActionNode::Countvoid
extern void * const CExoLinkedListTemplatedCNWSObjectActionNode__Count;
// void CExoLinkedListTemplatedCNWSObjectActionNode::GetAtPosCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCNWSObjectActionNode__GetAtPos;
// void CExoLinkedListTemplatedCNWSObjectActionNode::GetHeadvoid
extern void * const CExoLinkedListTemplatedCNWSObjectActionNode__GetHead;
// void CExoLinkedListTemplatedCNWSObjectActionNode::GetHeadPosvoid
extern void * const CExoLinkedListTemplatedCNWSObjectActionNode__GetHeadPos;
// void CExoLinkedListTemplatedCNWSObjectActionNode::GetNextCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCNWSObjectActionNode__GetNext;
// void CExoLinkedListTemplatedCNWSObjectActionNode::IsEmptyvoid
extern void * const CExoLinkedListTemplatedCNWSObjectActionNode__IsEmpty;
// void CExoLinkedListTemplatedCNWSObjectActionNode::RemoveCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCNWSObjectActionNode__Remove;
// void CExoLinkedListTemplatedCNWSObjectActionNode::RemoveHeadvoid
extern void * const CExoLinkedListTemplatedCNWSObjectActionNode__RemoveHead;

// void CExoLinkedListTemplatedCNWSPlayer::GetAtPosCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCNWSPlayer__GetAtPos;
// void CExoLinkedListTemplatedCNWSPlayer::GetHeadPosvoid
extern void * const CExoLinkedListTemplatedCNWSPlayer__GetHeadPos;
// void CExoLinkedListTemplatedCNWSPlayer::GetNextCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCNWSPlayer__GetNext;

// CExoLinkedListTemplatedCNWSPlayerLUOInventoryItem::CExoLinkedListTemplatedCNWSPlayerLUOInventoryItemvoid
extern void * const CExoLinkedListTemplatedCNWSPlayerLUOInventoryItem__CExoLinkedListTemplatedCNWSPlayerLUOInventoryItemCtor__0;
// CExoLinkedListTemplatedCNWSPlayerLUOInventoryItem::CExoLinkedListTemplatedCNWSPlayerLUOInventoryItemvoid
extern void * const CExoLinkedListTemplatedCNWSPlayerLUOInventoryItem__CExoLinkedListTemplatedCNWSPlayerLUOInventoryItemCtor__1;
// void CExoLinkedListTemplatedCNWSPlayerLUOInventoryItem::AddHeadCNWSPlayerLUOInventoryItem*
extern void * const CExoLinkedListTemplatedCNWSPlayerLUOInventoryItem__AddHead;
// void CExoLinkedListTemplatedCNWSPlayerLUOInventoryItem::Countvoid
extern void * const CExoLinkedListTemplatedCNWSPlayerLUOInventoryItem__Count;
// void CExoLinkedListTemplatedCNWSPlayerLUOInventoryItem::GetAtPosCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCNWSPlayerLUOInventoryItem__GetAtPos;
// void CExoLinkedListTemplatedCNWSPlayerLUOInventoryItem::GetHeadPosvoid
extern void * const CExoLinkedListTemplatedCNWSPlayerLUOInventoryItem__GetHeadPos;
// void CExoLinkedListTemplatedCNWSPlayerLUOInventoryItem::GetNextCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCNWSPlayerLUOInventoryItem__GetNext;
// void CExoLinkedListTemplatedCNWSPlayerLUOInventoryItem::GetPrevCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCNWSPlayerLUOInventoryItem__GetPrev;
// void CExoLinkedListTemplatedCNWSPlayerLUOInventoryItem::GetTailPosvoid
extern void * const CExoLinkedListTemplatedCNWSPlayerLUOInventoryItem__GetTailPos;
// void CExoLinkedListTemplatedCNWSPlayerLUOInventoryItem::IsEmptyvoid
extern void * const CExoLinkedListTemplatedCNWSPlayerLUOInventoryItem__IsEmpty;
// void CExoLinkedListTemplatedCNWSPlayerLUOInventoryItem::RemoveCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCNWSPlayerLUOInventoryItem__Remove;
// void CExoLinkedListTemplatedCNWSPlayerLUOInventoryItem::RemoveHeadvoid
extern void * const CExoLinkedListTemplatedCNWSPlayerLUOInventoryItem__RemoveHead;

// void CExoLinkedListTemplatedCNWSPlayerPtr::GetAtPosCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCNWSPlayerPtr__GetAtPos;
// void CExoLinkedListTemplatedCNWSPlayerPtr::GetHeadPosvoid
extern void * const CExoLinkedListTemplatedCNWSPlayerPtr__GetHeadPos;
// void CExoLinkedListTemplatedCNWSPlayerPtr::GetNextCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCNWSPlayerPtr__GetNext;

// CExoLinkedListTemplatedCNWSPlayerTURD::CExoLinkedListTemplatedCNWSPlayerTURDvoid
extern void * const CExoLinkedListTemplatedCNWSPlayerTURD__CExoLinkedListTemplatedCNWSPlayerTURDCtor__0;
// CExoLinkedListTemplatedCNWSPlayerTURD::CExoLinkedListTemplatedCNWSPlayerTURDvoid
extern void * const CExoLinkedListTemplatedCNWSPlayerTURD__CExoLinkedListTemplatedCNWSPlayerTURDCtor__1;
// void CExoLinkedListTemplatedCNWSPlayerTURD::AddHeadCNWSPlayerTURD*
extern void * const CExoLinkedListTemplatedCNWSPlayerTURD__AddHead;
// void CExoLinkedListTemplatedCNWSPlayerTURD::GetAtPosCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCNWSPlayerTURD__GetAtPos;
// void CExoLinkedListTemplatedCNWSPlayerTURD::GetHeadPosvoid
extern void * const CExoLinkedListTemplatedCNWSPlayerTURD__GetHeadPos;
// void CExoLinkedListTemplatedCNWSPlayerTURD::GetNextCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCNWSPlayerTURD__GetNext;
// void CExoLinkedListTemplatedCNWSPlayerTURD::RemoveCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCNWSPlayerTURD__Remove;

// CExoLinkedListTemplatedCRes::CExoLinkedListTemplatedCResvoid
extern void * const CExoLinkedListTemplatedCRes__CExoLinkedListTemplatedCResCtor__0;
// CExoLinkedListTemplatedCRes::CExoLinkedListTemplatedCResvoid
extern void * const CExoLinkedListTemplatedCRes__CExoLinkedListTemplatedCResCtor__1;
// void CExoLinkedListTemplatedCRes::AddHeadCRes*
extern void * const CExoLinkedListTemplatedCRes__AddHead;
// void CExoLinkedListTemplatedCRes::AddTailCRes*
extern void * const CExoLinkedListTemplatedCRes__AddTail;
// void CExoLinkedListTemplatedCRes::GetAtPosCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCRes__GetAtPos;
// void CExoLinkedListTemplatedCRes::GetHeadvoid
extern void * const CExoLinkedListTemplatedCRes__GetHead;
// void CExoLinkedListTemplatedCRes::GetHeadPosvoid
extern void * const CExoLinkedListTemplatedCRes__GetHeadPos;
// void CExoLinkedListTemplatedCRes::GetNextCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCRes__GetNext;
// void CExoLinkedListTemplatedCRes::IsEmptyvoid
extern void * const CExoLinkedListTemplatedCRes__IsEmpty;
// void CExoLinkedListTemplatedCRes::RemoveCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCRes__Remove;
// void CExoLinkedListTemplatedCRes::RemoveHeadvoid
extern void * const CExoLinkedListTemplatedCRes__RemoveHead;

// CExoLinkedListTemplatedCResRef::CExoLinkedListTemplatedCResRefvoid
extern void * const CExoLinkedListTemplatedCResRef__CExoLinkedListTemplatedCResRefCtor__0;
// CExoLinkedListTemplatedCResRef::CExoLinkedListTemplatedCResRefvoid
extern void * const CExoLinkedListTemplatedCResRef__CExoLinkedListTemplatedCResRefCtor__1;
// void CExoLinkedListTemplatedCResRef::AddTailCResRef*
extern void * const CExoLinkedListTemplatedCResRef__AddTail;
// void CExoLinkedListTemplatedCResRef::GetHeadvoid
extern void * const CExoLinkedListTemplatedCResRef__GetHead;
// void CExoLinkedListTemplatedCResRef::GetHeadPosvoid
extern void * const CExoLinkedListTemplatedCResRef__GetHeadPos;
// void CExoLinkedListTemplatedCResRef::GetNextCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCResRef__GetNext;
// void CExoLinkedListTemplatedCResRef::IsEmptyvoid
extern void * const CExoLinkedListTemplatedCResRef__IsEmpty;
// void CExoLinkedListTemplatedCResRef::RemoveHeadvoid
extern void * const CExoLinkedListTemplatedCResRef__RemoveHead;

// CExoLinkedListTemplatedCServerAIEventNode::CExoLinkedListTemplatedCServerAIEventNodevoid
extern void * const CExoLinkedListTemplatedCServerAIEventNode__CExoLinkedListTemplatedCServerAIEventNodeCtor__0;
// CExoLinkedListTemplatedCServerAIEventNode::CExoLinkedListTemplatedCServerAIEventNodevoid
extern void * const CExoLinkedListTemplatedCServerAIEventNode__CExoLinkedListTemplatedCServerAIEventNodeCtor__1;
// void CExoLinkedListTemplatedCServerAIEventNode::AddAfterCServerAIEventNode*, CExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCServerAIEventNode__AddAfter;
// void CExoLinkedListTemplatedCServerAIEventNode::AddBeforeCServerAIEventNode*, CExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCServerAIEventNode__AddBefore;
// void CExoLinkedListTemplatedCServerAIEventNode::AddHeadCServerAIEventNode*
extern void * const CExoLinkedListTemplatedCServerAIEventNode__AddHead;
// void CExoLinkedListTemplatedCServerAIEventNode::AddTailCServerAIEventNode*
extern void * const CExoLinkedListTemplatedCServerAIEventNode__AddTail;
// void CExoLinkedListTemplatedCServerAIEventNode::Countvoid
extern void * const CExoLinkedListTemplatedCServerAIEventNode__Count;
// void CExoLinkedListTemplatedCServerAIEventNode::GetAtPosCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCServerAIEventNode__GetAtPos;
// void CExoLinkedListTemplatedCServerAIEventNode::GetHeadvoid
extern void * const CExoLinkedListTemplatedCServerAIEventNode__GetHead;
// void CExoLinkedListTemplatedCServerAIEventNode::GetHeadPosvoid
extern void * const CExoLinkedListTemplatedCServerAIEventNode__GetHeadPos;
// void CExoLinkedListTemplatedCServerAIEventNode::GetNextCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCServerAIEventNode__GetNext;
// void CExoLinkedListTemplatedCServerAIEventNode::GetPrevCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedCServerAIEventNode__GetPrev;
// void CExoLinkedListTemplatedCServerAIEventNode::GetTailPosvoid
extern void * const CExoLinkedListTemplatedCServerAIEventNode__GetTailPos;
// void CExoLinkedListTemplatedCServerAIEventNode::IsEmptyvoid
extern void * const CExoLinkedListTemplatedCServerAIEventNode__IsEmpty;
// void CExoLinkedListTemplatedCServerAIEventNode::RemoveHeadvoid
extern void * const CExoLinkedListTemplatedCServerAIEventNode__RemoveHead;

// CExoLinkedListTemplatedExoLocString_st::CExoLinkedListTemplatedExoLocString_stvoid
extern void * const CExoLinkedListTemplatedExoLocString_st__CExoLinkedListTemplatedExoLocString_stCtor__0;
// CExoLinkedListTemplatedExoLocString_st::CExoLinkedListTemplatedExoLocString_stvoid
extern void * const CExoLinkedListTemplatedExoLocString_st__CExoLinkedListTemplatedExoLocString_stCtor__1;
// void CExoLinkedListTemplatedExoLocString_st::AddTailExoLocString_st*
extern void * const CExoLinkedListTemplatedExoLocString_st__AddTail;
// void CExoLinkedListTemplatedExoLocString_st::GetHeadvoid
extern void * const CExoLinkedListTemplatedExoLocString_st__GetHead;
// void CExoLinkedListTemplatedExoLocString_st::GetHeadPosvoid
extern void * const CExoLinkedListTemplatedExoLocString_st__GetHeadPos;
// void CExoLinkedListTemplatedExoLocString_st::GetNextCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedExoLocString_st__GetNext;
// void CExoLinkedListTemplatedExoLocString_st::IsEmptyvoid
extern void * const CExoLinkedListTemplatedExoLocString_st__IsEmpty;
// void CExoLinkedListTemplatedExoLocString_st::RemoveCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedExoLocString_st__Remove;
// void CExoLinkedListTemplatedExoLocString_st::RemoveHeadvoid
extern void * const CExoLinkedListTemplatedExoLocString_st__RemoveHead;

// CExoLinkedListTemplatedNWAreaExpansion_st::CExoLinkedListTemplatedNWAreaExpansion_stvoid
extern void * const CExoLinkedListTemplatedNWAreaExpansion_st__CExoLinkedListTemplatedNWAreaExpansion_stCtor__0;
// CExoLinkedListTemplatedNWAreaExpansion_st::CExoLinkedListTemplatedNWAreaExpansion_stvoid
extern void * const CExoLinkedListTemplatedNWAreaExpansion_st__CExoLinkedListTemplatedNWAreaExpansion_stCtor__1;
// void CExoLinkedListTemplatedNWAreaExpansion_st::AddTailNWAreaExpansion_st*
extern void * const CExoLinkedListTemplatedNWAreaExpansion_st__AddTail;
// void CExoLinkedListTemplatedNWAreaExpansion_st::IsEmptyvoid
extern void * const CExoLinkedListTemplatedNWAreaExpansion_st__IsEmpty;
// void CExoLinkedListTemplatedNWAreaExpansion_st::RemoveHeadvoid
extern void * const CExoLinkedListTemplatedNWAreaExpansion_st__RemoveHead;

// CExoLinkedListTemplatedNWModuleCutScene_st::CExoLinkedListTemplatedNWModuleCutScene_stvoid
extern void * const CExoLinkedListTemplatedNWModuleCutScene_st__CExoLinkedListTemplatedNWModuleCutScene_stCtor__0;
// CExoLinkedListTemplatedNWModuleCutScene_st::CExoLinkedListTemplatedNWModuleCutScene_stvoid
extern void * const CExoLinkedListTemplatedNWModuleCutScene_st__CExoLinkedListTemplatedNWModuleCutScene_stCtor__1;
// void CExoLinkedListTemplatedNWModuleCutScene_st::AddTailNWModuleCutScene_st*
extern void * const CExoLinkedListTemplatedNWModuleCutScene_st__AddTail;
// void CExoLinkedListTemplatedNWModuleCutScene_st::GetAtPosCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedNWModuleCutScene_st__GetAtPos;
// void CExoLinkedListTemplatedNWModuleCutScene_st::GetHeadPosvoid
extern void * const CExoLinkedListTemplatedNWModuleCutScene_st__GetHeadPos;
// void CExoLinkedListTemplatedNWModuleCutScene_st::GetNextCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedNWModuleCutScene_st__GetNext;
// void CExoLinkedListTemplatedNWModuleCutScene_st::IsEmptyvoid
extern void * const CExoLinkedListTemplatedNWModuleCutScene_st__IsEmpty;
// void CExoLinkedListTemplatedNWModuleCutScene_st::RemoveHeadvoid
extern void * const CExoLinkedListTemplatedNWModuleCutScene_st__RemoveHead;

// CExoLinkedListTemplatedNWModuleExpansion_st::CExoLinkedListTemplatedNWModuleExpansion_stvoid
extern void * const CExoLinkedListTemplatedNWModuleExpansion_st__CExoLinkedListTemplatedNWModuleExpansion_stCtor__0;
// CExoLinkedListTemplatedNWModuleExpansion_st::CExoLinkedListTemplatedNWModuleExpansion_stvoid
extern void * const CExoLinkedListTemplatedNWModuleExpansion_st__CExoLinkedListTemplatedNWModuleExpansion_stCtor__1;
// void CExoLinkedListTemplatedNWModuleExpansion_st::AddTailNWModuleExpansion_st*
extern void * const CExoLinkedListTemplatedNWModuleExpansion_st__AddTail;
// void CExoLinkedListTemplatedNWModuleExpansion_st::GetAtPosCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedNWModuleExpansion_st__GetAtPos;
// void CExoLinkedListTemplatedNWModuleExpansion_st::GetHeadPosvoid
extern void * const CExoLinkedListTemplatedNWModuleExpansion_st__GetHeadPos;
// void CExoLinkedListTemplatedNWModuleExpansion_st::GetNextCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedNWModuleExpansion_st__GetNext;
// void CExoLinkedListTemplatedNWModuleExpansion_st::IsEmptyvoid
extern void * const CExoLinkedListTemplatedNWModuleExpansion_st__IsEmpty;
// void CExoLinkedListTemplatedNWModuleExpansion_st::RemoveHeadvoid
extern void * const CExoLinkedListTemplatedNWModuleExpansion_st__RemoveHead;

// CExoLinkedListTemplatedNWPlayerListItem_st::CExoLinkedListTemplatedNWPlayerListItem_stvoid
extern void * const CExoLinkedListTemplatedNWPlayerListItem_st__CExoLinkedListTemplatedNWPlayerListItem_stCtor__0;
// CExoLinkedListTemplatedNWPlayerListItem_st::CExoLinkedListTemplatedNWPlayerListItem_stvoid
extern void * const CExoLinkedListTemplatedNWPlayerListItem_st__CExoLinkedListTemplatedNWPlayerListItem_stCtor__1;
// void CExoLinkedListTemplatedNWPlayerListItem_st::AddTailNWPlayerListItem_st*
extern void * const CExoLinkedListTemplatedNWPlayerListItem_st__AddTail;
// void CExoLinkedListTemplatedNWPlayerListItem_st::Countvoid
extern void * const CExoLinkedListTemplatedNWPlayerListItem_st__Count;
// void CExoLinkedListTemplatedNWPlayerListItem_st::GetAtPosCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedNWPlayerListItem_st__GetAtPos;
// void CExoLinkedListTemplatedNWPlayerListItem_st::GetHeadPosvoid
extern void * const CExoLinkedListTemplatedNWPlayerListItem_st__GetHeadPos;
// void CExoLinkedListTemplatedNWPlayerListItem_st::GetNextCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedNWPlayerListItem_st__GetNext;
// void CExoLinkedListTemplatedNWPlayerListItem_st::IsEmptyvoid
extern void * const CExoLinkedListTemplatedNWPlayerListItem_st__IsEmpty;
// void CExoLinkedListTemplatedNWPlayerListItem_st::RemoveHeadvoid
extern void * const CExoLinkedListTemplatedNWPlayerListItem_st__RemoveHead;

// CExoLinkedListTemplatedunsignedlong::CExoLinkedListTemplatedunsignedlongvoid
extern void * const CExoLinkedListTemplatedunsignedlong__CExoLinkedListTemplatedunsignedlongCtor__0;
// CExoLinkedListTemplatedunsignedlong::CExoLinkedListTemplatedunsignedlongvoid
extern void * const CExoLinkedListTemplatedunsignedlong__CExoLinkedListTemplatedunsignedlongCtor__1;
// void CExoLinkedListTemplatedunsignedlong::AddHeadunsigned long int*
extern void * const CExoLinkedListTemplatedunsignedlong__AddHead;
// void CExoLinkedListTemplatedunsignedlong::AddTailunsigned long int*
extern void * const CExoLinkedListTemplatedunsignedlong__AddTail;
// void CExoLinkedListTemplatedunsignedlong::Countvoid
extern void * const CExoLinkedListTemplatedunsignedlong__Count;
// void CExoLinkedListTemplatedunsignedlong::GetAtPosCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedunsignedlong__GetAtPos;
// void CExoLinkedListTemplatedunsignedlong::GetHeadPosvoid
extern void * const CExoLinkedListTemplatedunsignedlong__GetHeadPos;
// void CExoLinkedListTemplatedunsignedlong::GetNextCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedunsignedlong__GetNext;
// void CExoLinkedListTemplatedunsignedlong::GetPrevCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedunsignedlong__GetPrev;
// void CExoLinkedListTemplatedunsignedlong::GetTailPosvoid
extern void * const CExoLinkedListTemplatedunsignedlong__GetTailPos;
// void CExoLinkedListTemplatedunsignedlong::IsEmptyvoid
extern void * const CExoLinkedListTemplatedunsignedlong__IsEmpty;
// void CExoLinkedListTemplatedunsignedlong::RemoveCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedunsignedlong__Remove;
// void CExoLinkedListTemplatedunsignedlong::RemoveHeadvoid
extern void * const CExoLinkedListTemplatedunsignedlong__RemoveHead;

// CExoLinkedListTemplatedunsignedshort::CExoLinkedListTemplatedunsignedshortvoid
extern void * const CExoLinkedListTemplatedunsignedshort__CExoLinkedListTemplatedunsignedshortCtor__0;
// CExoLinkedListTemplatedunsignedshort::CExoLinkedListTemplatedunsignedshortvoid
extern void * const CExoLinkedListTemplatedunsignedshort__CExoLinkedListTemplatedunsignedshortCtor__1;
// void CExoLinkedListTemplatedunsignedshort::AddTailunsigned short int*
extern void * const CExoLinkedListTemplatedunsignedshort__AddTail;
// void CExoLinkedListTemplatedunsignedshort::GetHeadvoid
extern void * const CExoLinkedListTemplatedunsignedshort__GetHead;
// void CExoLinkedListTemplatedunsignedshort::GetHeadPosvoid
extern void * const CExoLinkedListTemplatedunsignedshort__GetHeadPos;
// void CExoLinkedListTemplatedunsignedshort::GetNextCExoLinkedListNode*
extern void * const CExoLinkedListTemplatedunsignedshort__GetNext;
// void CExoLinkedListTemplatedunsignedshort::IsEmptyvoid
extern void * const CExoLinkedListTemplatedunsignedshort__IsEmpty;
// void CExoLinkedListTemplatedunsignedshort::RemoveHeadvoid
extern void * const CExoLinkedListTemplatedunsignedshort__RemoveHead;

// public CExoLocString::CExoLocStringvoid
extern void * const CExoLocString__CExoLocStringCtor__0;
// public CExoLocString::CExoLocStringconst CExoLocString&
extern void * const CExoLocString__CExoLocStringCtor__1;
// public CExoLocString::~CExoLocStringvoid
extern void * const CExoLocString__CExoLocStringDtor;
// void CExoLocString::__asconst CExoLocString&
extern void * const CExoLocString____as;
// void CExoLocString::__eqCExoLocString&
extern void * const CExoLocString____eq;
// void CExoLocString::__neCExoLocString&
extern void * const CExoLocString____ne;
// public int CExoLocString::AddStringint, CExoString, unsigned char
extern void * const CExoLocString__AddString;
// public void CExoLocString::ClearLocStringvoid
extern void * const CExoLocString__ClearLocString;
// public int CExoLocString::GetStringint, CExoString*, unsigned char, bool
extern void * const CExoLocString__GetString__0;
// public int CExoLocString::GetStringunsigned long int, int*, CExoString*, unsigned char*
extern void * const CExoLocString__GetString__1;
// public unsigned long int CExoLocString::GetStringCountvoid
extern void * const CExoLocString__GetStringCount;
// void CExoLocString::GetStringInternalint, CExoString*
extern void * const CExoLocString__GetStringInternal;
// public int CExoLocString::GetStringLengthunsigned long int
extern void * const CExoLocString__GetStringLength;
// public int CExoLocString::GetStringLocint, CExoString*, unsigned char
extern void * const CExoLocString__GetStringLoc;
// void CExoLocString::RemoveStringint
extern void * const CExoLocString__RemoveString__0;
// void CExoLocString::RemoveStringint, unsigned char
extern void * const CExoLocString__RemoveString__1;

// public CExoLocStringInternal::CExoLocStringInternalvoid
extern void * const CExoLocStringInternal__CExoLocStringInternalCtor;
// public CExoLocStringInternal::~CExoLocStringInternalvoid
extern void * const CExoLocStringInternal__CExoLocStringInternalDtor;
// public int CExoLocStringInternal::AddStringint, CExoString
extern void * const CExoLocStringInternal__AddString;
// public int CExoLocStringInternal::AssignCExoLocStringInternal*
extern void * const CExoLocStringInternal__Assign;
// public void CExoLocStringInternal::ClearLocStringvoid
extern void * const CExoLocStringInternal__ClearLocString;
// public int CExoLocStringInternal::CompareCExoLocString&
extern void * const CExoLocStringInternal__Compare;
// public int CExoLocStringInternal::GetStringunsigned long int, int*, CExoString*
extern void * const CExoLocStringInternal__GetString__0;
// public int CExoLocStringInternal::GetStringint, CExoString*
extern void * const CExoLocStringInternal__GetString__1;
// public unsigned long int CExoLocStringInternal::GetStringCountvoid
extern void * const CExoLocStringInternal__GetStringCount;
// public int CExoLocStringInternal::GetStringLengthunsigned long int
extern void * const CExoLocStringInternal__GetStringLength;
// void CExoLocStringInternal::RemoveStringint
extern void * const CExoLocStringInternal__RemoveString;

// void CExoMemman::AddFreeRecordunsigned long int
extern void * const CExoMemman__AddFreeRecord;
// void CExoMemman::Allocunsigned long int, int
extern void * const CExoMemman__Alloc;
// void CExoMemman::CheckHeapsvoid
extern void * const CExoMemman__CheckHeaps;
// public void CExoMemman::Clearvoid
extern void * const CExoMemman__Clear;
// void CExoMemman::Destroyvoid
extern void * const CExoMemman__Destroy;
// void CExoMemman::DoHeapWalkvoid
extern void * const CExoMemman__DoHeapWalk;
// void CExoMemman::FillRecordPtrArrayvoid
extern void * const CExoMemman__FillRecordPtrArray;
// void CExoMemman::FinalReportvoid
extern void * const CExoMemman__FinalReport;
// void CExoMemman::Freevoid*
extern void * const CExoMemman__Free;
// void CExoMemman::GetFreeRecordvoid
extern void * const CExoMemman__GetFreeRecord;
// void CExoMemman::GetHeapsvoid
extern void * const CExoMemman__GetHeaps;
// public void CExoMemman::OutputTypeTrackingReportvoid
extern void * const CExoMemman__OutputTypeTrackingReport;
// void CExoMemman::PopTypeunsigned long int
extern void * const CExoMemman__PopType;
// void CExoMemman::PushTypeunsigned long int
extern void * const CExoMemman__PushType;
// void CExoMemman::ReportEntryCMemRecord&
extern void * const CExoMemman__ReportEntry;
// void CExoMemman::ReportRemovalCMemRecord&, int
extern void * const CExoMemman__ReportRemoval;
// void CExoMemman::SnapShotReportPrintvoid
extern void * const CExoMemman__SnapShotReportPrint;
// void CExoMemman::SnapShotReportWithSortvoid
extern void * const CExoMemman__SnapShotReportWithSort;
// void CExoMemman::StartReportvoid
extern void * const CExoMemman__StartReport;

// public CExoNet::CExoNetvoid
extern void * const CExoNet__CExoNetCtor;
// public CExoNet::~CExoNetvoid
extern void * const CExoNet__CExoNetDtor;
// public unsigned long int CExoNet::AddressTranslationAvailablevoid
extern void * const CExoNet__AddressTranslationAvailable;
// public void CExoNet::ClearNetworkAddressProtectvoid
extern void * const CExoNet__ClearNetworkAddressProtect;
// public int CExoNet::ClearUnusedNetworkAddressesunsigned long int
extern void * const CExoNet__ClearUnusedNetworkAddresses;
// public int CExoNet::CloseTCPConnectionint
extern void * const CExoNet__CloseTCPConnection;
// public int CExoNet::CompareToLocalAddressunsigned long int, unsigned char*, unsigned char*
extern void * const CExoNet__CompareToLocalAddress;
// public int CExoNet::CompareToSpecificInternetAddressunsigned char*
extern void * const CExoNet__CompareToSpecificInternetAddress;
// public void CExoNet::EndAddressTranslationvoid
extern void * const CExoNet__EndAddressTranslation;
// public int CExoNet::EndIncomingMessageProcessingvoid
extern void * const CExoNet__EndIncomingMessageProcessing;
// public int CExoNet::FetchIncomingMessageunsigned long int*, unsigned char**, unsigned long int*
extern void * const CExoNet__FetchIncomingMessage;
// public void CExoNet::GetAddressTranslationunsigned char*
extern void * const CExoNet__GetAddressTranslation;
// void CExoNet::GetLocalAdapterStringunsigned long int, unsigned long int
extern void * const CExoNet__GetLocalAdapterString;
// public int CExoNet::GetNetworkAddressDataunsigned long int, unsigned long int*, unsigned char**, unsigned char**, unsigned long int*
extern void * const CExoNet__GetNetworkAddressData;
// public CExoString CExoNet::GetNetworkAddressStringunsigned long int
extern void * const CExoNet__GetNetworkAddressString;
// void CExoNet::GetNumberLocalAdaptersunsigned long int
extern void * const CExoNet__GetNumberLocalAdapters;
// public int CExoNet::GetProtocolInitializedunsigned long int
extern void * const CExoNet__GetProtocolInitialized;
// public unsigned long int CExoNet::GetProtocolReceivePortunsigned long int
extern void * const CExoNet__GetProtocolReceivePort;
// void CExoNet::GetProtocolSendPortunsigned long int
extern void * const CExoNet__GetProtocolSendPort;
// public unsigned long int CExoNet::GetSendUDPSocketvoid
extern void * const CExoNet__GetSendUDPSocket;
// public void CExoNet::GetSpecificInternetAddressunsigned char*, unsigned short int*
extern void * const CExoNet__GetSpecificInternetAddress;
// public int CExoNet::GetTCPMessageint*, char**, int*
extern void * const CExoNet__GetTCPMessage;
// public int CExoNet::InitializeProtocolunsigned long int, unsigned long int, unsigned long int, unsigned long int
extern void * const CExoNet__InitializeProtocol;
// public int CExoNet::MessageArrivedunsigned long int, unsigned long int, unsigned long int, int
extern void * const CExoNet__MessageArrived;
// public int CExoNet::OpenTCPConnectionint, CExoString, int
extern void * const CExoNet__OpenTCPConnection;
// public int CExoNet::RemoveIncomingMessagevoid
extern void * const CExoNet__RemoveIncomingMessage;
// public int CExoNet::SendDirectMessageunsigned long int, unsigned char*, unsigned long int, unsigned long int, unsigned long int
extern void * const CExoNet__SendDirectMessage;
// public int CExoNet::SendTCPMessageint, char*, int
extern void * const CExoNet__SendTCPMessage;
// public void CExoNet::SetMasterServerInternetAddressconst unsigned char*, unsigned long int
extern void * const CExoNet__SetMasterServerInternetAddress;
// public unsigned long int CExoNet::SetNetworkAddressDataunsigned long int, unsigned char*, unsigned char*, unsigned long int
extern void * const CExoNet__SetNetworkAddressData;
// public int CExoNet::SetNetworkAddressProtectunsigned long int, int
extern void * const CExoNet__SetNetworkAddressProtect;
// void CExoNet::SetSpecificInternetAddressunsigned char*, unsigned short int
extern void * const CExoNet__SetSpecificInternetAddress;
// public int CExoNet::ShutDownProtocolunsigned long int
extern void * const CExoNet__ShutDownProtocol;
// public void CExoNet::StartAddressTranslationCExoString, unsigned long int
extern void * const CExoNet__StartAddressTranslation;
// public int CExoNet::StartIncomingMessageProcessingvoid
extern void * const CExoNet__StartIncomingMessageProcessing;
// public void CExoNet::StoreMessageunsigned char*, unsigned long int, unsigned long int
extern void * const CExoNet__StoreMessage;
// public int CExoNet::TranslateAddressFromStringchar*, unsigned long int*, unsigned char*, unsigned char*, unsigned long int*
extern void * const CExoNet__TranslateAddressFromString;

// public CExoNetExtendableBuffer::CExoNetExtendableBuffervoid
extern void * const CExoNetExtendableBuffer__CExoNetExtendableBufferCtor;
// public CExoNetExtendableBuffer::~CExoNetExtendableBuffervoid
extern void * const CExoNetExtendableBuffer__CExoNetExtendableBufferDtor;
// public unsigned long int CExoNetExtendableBuffer::ChangeFrameReferenceunsigned short int, int, int
extern void * const CExoNetExtendableBuffer__ChangeFrameReference;
// void CExoNetExtendableBuffer::GetCurrentUsageunsigned long int*, unsigned long int*
extern void * const CExoNetExtendableBuffer__GetCurrentUsage;
// public unsigned short int CExoNetExtendableBuffer::GetFirstUsedFrameint
extern void * const CExoNetExtendableBuffer__GetFirstUsedFrame;
// void CExoNetExtendableBuffer::GetFrameConnectionIdunsigned short int, int
extern void * const CExoNetExtendableBuffer__GetFrameConnectionId;
// public int CExoNetExtendableBuffer::GetFrameDataunsigned short int, unsigned char**, unsigned long int*, unsigned long int*, unsigned short int*, int
extern void * const CExoNetExtendableBuffer__GetFrameData;
// public unsigned char* CExoNetExtendableBuffer::GetFramePointerunsigned short int, int
extern void * const CExoNetExtendableBuffer__GetFramePointer;
// void CExoNetExtendableBuffer::GetFrameSizeunsigned short int, int
extern void * const CExoNetExtendableBuffer__GetFrameSize;
// void CExoNetExtendableBuffer::GetMaximumUsageunsigned long int*, unsigned long int*
extern void * const CExoNetExtendableBuffer__GetMaximumUsage;
// public unsigned short int CExoNetExtendableBuffer::GetUnusedFrameint
extern void * const CExoNetExtendableBuffer__GetUnusedFrame;
// public int CExoNetExtendableBuffer::LockExtBufferInstancevoid
extern void * const CExoNetExtendableBuffer__LockExtBufferInstance;
// public int CExoNetExtendableBuffer::SetFrameDataunsigned short int, unsigned char*, unsigned long int, unsigned long int, unsigned long int, int
extern void * const CExoNetExtendableBuffer__SetFrameData;
// public int CExoNetExtendableBuffer::UnlockExtBufferInstancevoid
extern void * const CExoNetExtendableBuffer__UnlockExtBufferInstance;

// CExoNetFrameBuffer::CExoNetFrameBuffervoid
extern void * const CExoNetFrameBuffer__CExoNetFrameBufferCtor;
// CExoNetFrameBuffer::~CExoNetFrameBuffervoid
extern void * const CExoNetFrameBuffer__CExoNetFrameBufferDtor;
// public unsigned long int CExoNetFrameBuffer::ChangeRefCountunsigned char, int
extern void * const CExoNetFrameBuffer__ChangeRefCount;
// void CExoNetFrameBuffer::GetFrameConnectionIdunsigned char
extern void * const CExoNetFrameBuffer__GetFrameConnectionId;
// void CExoNetFrameBuffer::GetFrameDataunsigned char, unsigned char**, unsigned long int*, unsigned long int*, unsigned char*
extern void * const CExoNetFrameBuffer__GetFrameData;
// void CExoNetFrameBuffer::GetFramePointerunsigned char
extern void * const CExoNetFrameBuffer__GetFramePointer;
// void CExoNetFrameBuffer::GetFrameSizeunsigned char
extern void * const CExoNetFrameBuffer__GetFrameSize;
// void CExoNetFrameBuffer::GetRefCountunsigned char
extern void * const CExoNetFrameBuffer__GetRefCount;
// void CExoNetFrameBuffer::GetUnusedFramevoid
extern void * const CExoNetFrameBuffer__GetUnusedFrame;
// void CExoNetFrameBuffer::GetUsedFramevoid
extern void * const CExoNetFrameBuffer__GetUsedFrame;
// void CExoNetFrameBuffer::SetFrameDataunsigned char, unsigned char*, unsigned long int, unsigned long int, unsigned long int
extern void * const CExoNetFrameBuffer__SetFrameData;

// public CExoNetInternal::CExoNetInternalvoid
extern void * const CExoNetInternal__CExoNetInternalCtor;
// public CExoNetInternal::~CExoNetInternalvoid
extern void * const CExoNetInternal__CExoNetInternalDtor;
// public unsigned long int CExoNetInternal::AddressTranslationAvailablevoid
extern void * const CExoNetInternal__AddressTranslationAvailable;
// public void CExoNetInternal::ClearNetworkAddressProtectvoid
extern void * const CExoNetInternal__ClearNetworkAddressProtect;
// public void CExoNetInternal::ClearUnusedNetworkAddressesunsigned long int
extern void * const CExoNetInternal__ClearUnusedNetworkAddresses;
// public int CExoNetInternal::CloseTCPConnectionint
extern void * const CExoNetInternal__CloseTCPConnection;
// public int CExoNetInternal::CompareToLocalAddressunsigned long int, unsigned char*, unsigned char*
extern void * const CExoNetInternal__CompareToLocalAddress;
// public void CExoNetInternal::EndAddressTranslationvoid
extern void * const CExoNetInternal__EndAddressTranslation;
// public int CExoNetInternal::EndIncomingMessageProcessingvoid
extern void * const CExoNetInternal__EndIncomingMessageProcessing;
// public int CExoNetInternal::EnumerateLocalAddressesunsigned long int
extern void * const CExoNetInternal__EnumerateLocalAddresses;
// private void CExoNetInternal::ExoWarningOnErrorvoid
extern void * const CExoNetInternal__ExoWarningOnError;
// public int CExoNetInternal::FetchIncomingMessageunsigned long int*, unsigned char**, unsigned long int*
extern void * const CExoNetInternal__FetchIncomingMessage;
// public void CExoNetInternal::GetAddressTranslationunsigned char*
extern void * const CExoNetInternal__GetAddressTranslation;
// void CExoNetInternal::GetLocalAdapterStringunsigned long int, unsigned long int
extern void * const CExoNetInternal__GetLocalAdapterString;
// public int CExoNetInternal::GetNetworkAddressDataunsigned long int, unsigned long int*, unsigned char**, unsigned char**, unsigned long int*
extern void * const CExoNetInternal__GetNetworkAddressData;
// public CExoString CExoNetInternal::GetNetworkAddressStringunsigned long int
extern void * const CExoNetInternal__GetNetworkAddressString;
// void CExoNetInternal::GetNumberLocalAdaptersunsigned long int
extern void * const CExoNetInternal__GetNumberLocalAdapters;
// public int CExoNetInternal::GetProtocolInitializedunsigned long int
extern void * const CExoNetInternal__GetProtocolInitialized;
// public unsigned long int CExoNetInternal::GetProtocolReceivePortunsigned long int
extern void * const CExoNetInternal__GetProtocolReceivePort;
// void CExoNetInternal::GetProtocolSendPortunsigned long int
extern void * const CExoNetInternal__GetProtocolSendPort;
// public unsigned long int CExoNetInternal::GetSendUDPSocketvoid
extern void * const CExoNetInternal__GetSendUDPSocket;
// public int CExoNetInternal::GetTCPMessageint*, char**, int*
extern void * const CExoNetInternal__GetTCPMessage;
// public int CExoNetInternal::InitializeProtocolunsigned long int, unsigned long int, unsigned long int, unsigned long int
extern void * const CExoNetInternal__InitializeProtocol;
// public int CExoNetInternal::MessageArrivedunsigned long int, unsigned long int, unsigned long int, int
extern void * const CExoNetInternal__MessageArrived;
// public int CExoNetInternal::OpenTCPConnectionint, CExoString, int
extern void * const CExoNetInternal__OpenTCPConnection;
// public int CExoNetInternal::RemoveIncomingMessagevoid
extern void * const CExoNetInternal__RemoveIncomingMessage;
// void CExoNetInternal::SendMessageunsigned long int, unsigned char*, unsigned long int, unsigned long int, unsigned long int
extern void * const CExoNetInternal__SendMessage;
// public int CExoNetInternal::SendTCPMessageint, char*, int
extern void * const CExoNetInternal__SendTCPMessage;
// void CExoNetInternal::SetConnectionIdTimerunsigned long int
extern void * const CExoNetInternal__SetConnectionIdTimer;
// public void CExoNetInternal::SetMasterServerInternetAddressconst unsigned char*, unsigned long int
extern void * const CExoNetInternal__SetMasterServerInternetAddress;
// public unsigned long int CExoNetInternal::SetNetworkAddressDataunsigned long int, unsigned char*, unsigned char*, unsigned long int
extern void * const CExoNetInternal__SetNetworkAddressData;
// public int CExoNetInternal::SetNetworkAddressProtectunsigned long int, int
extern void * const CExoNetInternal__SetNetworkAddressProtect;
// public int CExoNetInternal::ShutDownProtocolunsigned long int
extern void * const CExoNetInternal__ShutDownProtocol;
// public void CExoNetInternal::StartAddressTranslationCExoString, unsigned long int
extern void * const CExoNetInternal__StartAddressTranslation;
// public int CExoNetInternal::StartIncomingMessageProcessingvoid
extern void * const CExoNetInternal__StartIncomingMessageProcessing;
// public void CExoNetInternal::StoreMessageunsigned char*, unsigned long int, unsigned long int
extern void * const CExoNetInternal__StoreMessage;
// public int CExoNetInternal::TranslateAddressFromStringchar*, unsigned long int*, unsigned char*, unsigned char*, unsigned long int*
extern void * const CExoNetInternal__TranslateAddressFromString;
// void CExoNetInternal::WinSockInitializevoid
extern void * const CExoNetInternal__WinSockInitialize;

// CExoPackedFile::CExoPackedFilevoid
extern void * const CExoPackedFile__CExoPackedFileCtor;
// public CExoPackedFile::~CExoPackedFilevoid
extern void * const CExoPackedFile__CExoPackedFileDtor;
// public CExoFile* CExoPackedFile::GetAsyncFilevoid
extern void * const CExoPackedFile__GetAsyncFile;
// public CExoFile* CExoPackedFile::GetFilevoid
extern void * const CExoPackedFile__GetFile;

// public CExoRand::CExoRandvoid
extern void * const CExoRand__CExoRandCtor;
// public CExoRand::~CExoRandvoid
extern void * const CExoRand__CExoRandDtor;
// public CExoString CExoRand::GetStringunsigned short int
extern void * const CExoRand__GetString;
// public unsigned long int CExoRand::Randvoid
extern void * const CExoRand__Rand;
// public void CExoRand::SignalEventvoid
extern void * const CExoRand__SignalEvent__0;
// public void CExoRand::SignalEventunsigned long int
extern void * const CExoRand__SignalEvent__1;

// public CExoRandInternal::CExoRandInternalvoid
extern void * const CExoRandInternal__CExoRandInternalCtor;
// public CExoRandInternal::~CExoRandInternalvoid
extern void * const CExoRandInternal__CExoRandInternalDtor;
// void CExoRandInternal::Addunsigned char*, int
extern void * const CExoRandInternal__Add;
// void CExoRandInternal::GenSeedvoid
extern void * const CExoRandInternal__GenSeed;
// public CExoString CExoRandInternal::GetStringunsigned short int
extern void * const CExoRandInternal__GetString;
// public unsigned long int CExoRandInternal::Randvoid
extern void * const CExoRandInternal__Rand;
// private void CExoRandInternal::ReSeedunsigned long int, unsigned long int, unsigned long int, unsigned long int
extern void * const CExoRandInternal__ReSeed;
// public void CExoRandInternal::SignalEventvoid
extern void * const CExoRandInternal__SignalEvent__0;
// public void CExoRandInternal::SignalEventunsigned long int
extern void * const CExoRandInternal__SignalEvent__1;

// CExoResFile::CExoResFilevoid
extern void * const CExoResFile__CExoResFileCtor;
// public CExoResFile::~CExoResFilevoid
extern void * const CExoResFile__CExoResFileDtor;
// public void CExoResFile::AddAsyncRefCountvoid
extern void * const CExoResFile__AddAsyncRefCount;
// public void CExoResFile::AddRefCountvoid
extern void * const CExoResFile__AddRefCount;
// public int CExoResFile::CloseAsyncFilevoid
extern void * const CExoResFile__CloseAsyncFile;
// public int CExoResFile::CloseFilevoid
extern void * const CExoResFile__CloseFile;
// public void CExoResFile::DeleteAsyncRefCountvoid
extern void * const CExoResFile__DeleteAsyncRefCount;
// public void CExoResFile::DeleteRefCountvoid
extern void * const CExoResFile__DeleteRefCount;
// public unsigned long int CExoResFile::GetResourceSizeunsigned long int
extern void * const CExoResFile__GetResourceSize;
// public int CExoResFile::Initializevoid
extern void * const CExoResFile__Initialize;
// public int CExoResFile::LoadHeaderunsigned char
extern void * const CExoResFile__LoadHeader;
// public int CExoResFile::OpenAsyncFilevoid
extern void * const CExoResFile__OpenAsyncFile;
// public int CExoResFile::OpenFilevoid
extern void * const CExoResFile__OpenFile__0;
// public int CExoResFile::OpenFileunsigned char*
extern void * const CExoResFile__OpenFile__1;
// public unsigned long int CExoResFile::ReadResourceunsigned long int, void*, unsigned long int, unsigned long int
extern void * const CExoResFile__ReadResource;
// public void CExoResFile::ReadResourceAsyncunsigned long int, void*, unsigned long int, unsigned long int
extern void * const CExoResFile__ReadResourceAsync;
// public int CExoResFile::UnloadHeadervoid
extern void * const CExoResFile__UnloadHeader;

// public CExoResMan::CExoResManvoid
extern void * const CExoResMan__CExoResManCtor;
// public CExoResMan::~CExoResManvoid
extern void * const CExoResMan__CExoResManDtor;
// public int CExoResMan::AddEncapsulatedResourceFileconst CExoString&
extern void * const CExoResMan__AddEncapsulatedResourceFile;
// public int CExoResMan::AddFixedKeyTableFileconst CExoString&
extern void * const CExoResMan__AddFixedKeyTableFile;
// private int CExoResMan::AddKeyTableconst CExoString&, unsigned long int, unsigned char*
extern void * const CExoResMan__AddKeyTable;
// public int CExoResMan::AddResourceDirectoryconst CExoString&
extern void * const CExoResMan__AddResourceDirectory;
// public int CExoResMan::AddResourceImageFileconst CExoString&, unsigned char*
extern void * const CExoResMan__AddResourceImageFile;
// public int CExoResMan::CancelRequestCRes*
extern void * const CExoResMan__CancelRequest;
// public int CExoResMan::CleanDirectoryCExoString, int, int
extern void * const CExoResMan__CleanDirectory;
// void CExoResMan::CreateDirectoryCExoString
extern void * const CExoResMan__CreateDirectory;
// public void* CExoResMan::DemandCRes*
extern void * const CExoResMan__Demand;
// void CExoResMan::DumpCRes*, int
extern void * const CExoResMan__Dump;
// void CExoResMan::DumpAllvoid
extern void * const CExoResMan__DumpAll;
// public int CExoResMan::Existsconst CResRef&, unsigned short int, unsigned long int*
extern void * const CExoResMan__Exists;
// private int CExoResMan::FreeCRes*
extern void * const CExoResMan__Free;
// private int CExoResMan::FreeChunkvoid
extern void * const CExoResMan__FreeChunk;
// void CExoResMan::FreeResourceDataCRes*
extern void * const CExoResMan__FreeResourceData;
// void CExoResMan::GetEncapsulatedFileDescriptionconst CExoString&
extern void * const CExoResMan__GetEncapsulatedFileDescription;
// public int CExoResMan::GetFreeDiskSpaceconst CExoString&, unsigned long long int*
extern void * const CExoResMan__GetFreeDiskSpace;
// public int CExoResMan::GetIsStaticTypeunsigned short int
extern void * const CExoResMan__GetIsStaticType;
// public int CExoResMan::GetKeyEntryconst CResRef&, unsigned short int, CExoKeyTable**, CKeyTableEntry**
extern void * const CExoResMan__GetKeyEntry;
// void CExoResMan::GetNewResRefconst CResRef&, unsigned short int, CResRef&
extern void * const CExoResMan__GetNewResRef;
// void CExoResMan::GetResIDconst CResRef&, unsigned short int
extern void * const CExoResMan__GetResID;
// public CRes* CExoResMan::GetResObjectconst CResRef&, unsigned short int
extern void * const CExoResMan__GetResObject;
// public CExoStringList* CExoResMan::GetResOfTypeunsigned short int, int
extern void * const CExoResMan__GetResOfType__0;
// public CExoStringList* CExoResMan::GetResOfTypeunsigned short int, CRes*
extern void * const CExoResMan__GetResOfType__1;
// public void CExoResMan::GetResRefFromFileCResRef&, const CExoString&
extern void * const CExoResMan__GetResRefFromFile;
// public unsigned short int CExoResMan::GetResTypeFromFileconst CExoString&
extern void * const CExoResMan__GetResTypeFromFile;
// private CExoKeyTable* CExoResMan::GetTableCRes*
extern void * const CExoResMan__GetTable;
// public int CExoResMan::GetTableCountCRes*, int
extern void * const CExoResMan__GetTableCount;
// void CExoResMan::GetTotalPhysicalMemoryvoid
extern void * const CExoResMan__GetTotalPhysicalMemory;
// private int CExoResMan::MallocCRes*
extern void * const CExoResMan__Malloc;
// public int CExoResMan::NukeDirectoryCExoString, int, int
extern void * const CExoResMan__NukeDirectory;
// void CExoResMan::ReadRawCRes*, int, char*
extern void * const CExoResMan__ReadRaw;
// public int CExoResMan::ReleaseCRes*
extern void * const CExoResMan__Release;
// public int CExoResMan::ReleaseResObjectCRes*
extern void * const CExoResMan__ReleaseResObject;
// public int CExoResMan::RemoveEncapsulatedResourceFileconst CExoString&
extern void * const CExoResMan__RemoveEncapsulatedResourceFile;
// public int CExoResMan::RemoveFileconst CExoString&, unsigned short int
extern void * const CExoResMan__RemoveFile;
// public int CExoResMan::RemoveFixedKeyTableFileconst CExoString&
extern void * const CExoResMan__RemoveFixedKeyTableFile;
// void CExoResMan::RemoveFromToBeFreedListCRes*
extern void * const CExoResMan__RemoveFromToBeFreedList;
// private int CExoResMan::RemoveKeyTableconst CExoString&, unsigned long int
extern void * const CExoResMan__RemoveKeyTable;
// public int CExoResMan::RemoveResourceDirectoryconst CExoString&
extern void * const CExoResMan__RemoveResourceDirectory;
// public int CExoResMan::RemoveResourceImageFileconst CExoString&
extern void * const CExoResMan__RemoveResourceImageFile;
// void CExoResMan::RequestCRes*
extern void * const CExoResMan__Request;
// void CExoResMan::ResumeServicingvoid
extern void * const CExoResMan__ResumeServicing;
// public int CExoResMan::ServiceCurrentAsyncResvoid
extern void * const CExoResMan__ServiceCurrentAsyncRes;
// private int CExoResMan::ServiceFromDirectoryCRes*, int
extern void * const CExoResMan__ServiceFromDirectory;
// void CExoResMan::ServiceFromDirectoryRawCRes*, int, char*
extern void * const CExoResMan__ServiceFromDirectoryRaw;
// private int CExoResMan::ServiceFromEncapsulatedCRes*, int
extern void * const CExoResMan__ServiceFromEncapsulated;
// void CExoResMan::ServiceFromEncapsulatedRawCRes*, int, char*
extern void * const CExoResMan__ServiceFromEncapsulatedRaw;
// private int CExoResMan::ServiceFromImageCRes*, int
extern void * const CExoResMan__ServiceFromImage;
// void CExoResMan::ServiceFromImageRawCRes*, int, char*
extern void * const CExoResMan__ServiceFromImageRaw;
// private int CExoResMan::ServiceFromResFileCRes*, int
extern void * const CExoResMan__ServiceFromResFile;
// void CExoResMan::ServiceFromResFileRawCRes*, int, char*
extern void * const CExoResMan__ServiceFromResFileRaw;
// public void CExoResMan::SetResObjectconst CResRef&, unsigned short int, CRes*
extern void * const CExoResMan__SetResObject;
// public int CExoResMan::SetTotalResourceMemoryint
extern void * const CExoResMan__SetTotalResourceMemory;
// void CExoResMan::SuspendServicingvoid
extern void * const CExoResMan__SuspendServicing;
// void CExoResMan::Updateunsigned long int
extern void * const CExoResMan__Update;
// void CExoResMan::UpdateEncapsulatedResourceFileconst CExoString&
extern void * const CExoResMan__UpdateEncapsulatedResourceFile;
// void CExoResMan::UpdateFixedKeyTableFileconst CExoString&
extern void * const CExoResMan__UpdateFixedKeyTableFile;
// private int CExoResMan::UpdateKeyTableconst CExoString&, unsigned long int
extern void * const CExoResMan__UpdateKeyTable;
// public int CExoResMan::UpdateResourceDirectoryconst CExoString&
extern void * const CExoResMan__UpdateResourceDirectory;
// private int CExoResMan::WipeDirectoryCExoString, int, int, int, int
extern void * const CExoResMan__WipeDirectory;

// CExoResourceImageFile::CExoResourceImageFilevoid
extern void * const CExoResourceImageFile__CExoResourceImageFileCtor;
// public CExoResourceImageFile::~CExoResourceImageFilevoid
extern void * const CExoResourceImageFile__CExoResourceImageFileDtor;
// public void CExoResourceImageFile::AddAsyncRefCountvoid
extern void * const CExoResourceImageFile__AddAsyncRefCount;
// public void CExoResourceImageFile::AddRefCountvoid
extern void * const CExoResourceImageFile__AddRefCount;
// public int CExoResourceImageFile::CloseAsyncFilevoid
extern void * const CExoResourceImageFile__CloseAsyncFile;
// public int CExoResourceImageFile::CloseFilevoid
extern void * const CExoResourceImageFile__CloseFile;
// public void CExoResourceImageFile::DeleteAsyncRefCountvoid
extern void * const CExoResourceImageFile__DeleteAsyncRefCount;
// public void CExoResourceImageFile::DeleteRefCountvoid
extern void * const CExoResourceImageFile__DeleteRefCount;
// void CExoResourceImageFile::GetHeadervoid
extern void * const CExoResourceImageFile__GetHeader;
// void CExoResourceImageFile::GetKeyListvoid
extern void * const CExoResourceImageFile__GetKeyList;
// void CExoResourceImageFile::GetKeyListEntryunsigned long int
extern void * const CExoResourceImageFile__GetKeyListEntry;
// public void* CExoResourceImageFile::GetResourceunsigned long int
extern void * const CExoResourceImageFile__GetResource;
// public EncapsulatedResListEntry_st* CExoResourceImageFile::GetResourceListEntryunsigned long int
extern void * const CExoResourceImageFile__GetResourceListEntry;
// public unsigned long int CExoResourceImageFile::GetResourceSizeunsigned long int
extern void * const CExoResourceImageFile__GetResourceSize;
// public int CExoResourceImageFile::Initializevoid
extern void * const CExoResourceImageFile__Initialize;
// public int CExoResourceImageFile::LoadHeaderunsigned char
extern void * const CExoResourceImageFile__LoadHeader;
// public int CExoResourceImageFile::OpenAsyncFilevoid
extern void * const CExoResourceImageFile__OpenAsyncFile;
// public int CExoResourceImageFile::OpenFileunsigned char*
extern void * const CExoResourceImageFile__OpenFile__0;
// public int CExoResourceImageFile::OpenFilevoid
extern void * const CExoResourceImageFile__OpenFile__1;
// public unsigned long int CExoResourceImageFile::ReadResourceunsigned long int, void*, unsigned long int, unsigned long int
extern void * const CExoResourceImageFile__ReadResource;
// public void CExoResourceImageFile::ReadResourceAsyncunsigned long int, void*, unsigned long int, unsigned long int
extern void * const CExoResourceImageFile__ReadResourceAsync;
// public int CExoResourceImageFile::UnloadHeadervoid
extern void * const CExoResourceImageFile__UnloadHeader;

// public CExoString::CExoStringvoid
extern void * const CExoString__CExoStringCtor__0;
// public CExoString::CExoStringconst char*
extern void * const CExoString__CExoStringCtor__1;
// public CExoString::CExoStringconst CExoString&
extern void * const CExoString__CExoStringCtor__2;
// public CExoString::CExoStringconst char*, int
extern void * const CExoString__CExoStringCtor__3;
// public CExoString::CExoStringint
extern void * const CExoString__CExoStringCtor__4;
// public CExoString::~CExoStringvoid
extern void * const CExoString__CExoStringDtor;
// void CExoString::__asconst CExoString&
extern void * const CExoString____as__0;
// void CExoString::__asconst char*
extern void * const CExoString____as__1;
// void CExoString::__eqconst CExoString& const
extern void * const CExoString____eq__0;
// void CExoString::__eqconst char* const
extern void * const CExoString____eq__1;
// void CExoString::__geconst CExoString& const
extern void * const CExoString____ge__0;
// void CExoString::__geconst char* const
extern void * const CExoString____ge__1;
// void CExoString::__gtconst CExoString& const
extern void * const CExoString____gt__0;
// void CExoString::__gtconst char* const
extern void * const CExoString____gt__1;
// void CExoString::__leconst CExoString& const
extern void * const CExoString____le__0;
// void CExoString::__leconst char* const
extern void * const CExoString____le__1;
// void CExoString::__ltconst CExoString& const
extern void * const CExoString____lt__0;
// void CExoString::__ltconst char* const
extern void * const CExoString____lt__1;
// void CExoString::__neconst CExoString& const
extern void * const CExoString____ne__0;
// void CExoString::__neconst char* const
extern void * const CExoString____ne__1;
// void CExoString::__plconst CExoString& const
extern void * const CExoString____pl;
// void CExoString::__vcint const
extern void * const CExoString____vc;
// public float CExoString::AsFLOATvoid const
extern void * const CExoString__AsFLOAT;
// public int CExoString::AsINTvoid const
extern void * const CExoString__AsINT;
// public CExoString CExoString::AsTAGvoid const
extern void * const CExoString__AsTAG;
// public int CExoString::CompareNoCaseconst CExoString& const
extern void * const CExoString__CompareNoCase;
// public int CExoString::ComparePrefixNoCaseconst CExoString&, int const
extern void * const CExoString__ComparePrefixNoCase;
// public char* CExoString::CStrvoid const
extern void * const CExoString__CStr;
// public int CExoString::Findchar, int const
extern void * const CExoString__Find__0;
// public int CExoString::Findconst CExoString&, int const
extern void * const CExoString__Find__1;
// void CExoString::FindNotchar, int const
extern void * const CExoString__FindNot;
// public void CExoString::Formatchar*, ...
extern void * const CExoString__Format;
// public int CExoString::GetLengthvoid const
extern void * const CExoString__GetLength;
// public void CExoString::Insertconst CExoString&, int
extern void * const CExoString__Insert;
// public int CExoString::IsEmptyvoid const
extern void * const CExoString__IsEmpty;
// public CExoString CExoString::Leftint const
extern void * const CExoString__Left;
// public CExoString CExoString::LowerCasevoid const
extern void * const CExoString__LowerCase;
// public CExoString CExoString::Rightint const
extern void * const CExoString__Right;
// public int CExoString::StripNonAlphaNumericint, int, int
extern void * const CExoString__StripNonAlphaNumeric;
// public CExoString CExoString::SubStringint, int const
extern void * const CExoString__SubString;
// public CExoString CExoString::UpperCasevoid const
extern void * const CExoString__UpperCase;

// public CExoStringList::CExoStringListvoid
extern void * const CExoStringList__CExoStringListCtor__0;
// public CExoStringList::CExoStringListint, int, int
extern void * const CExoStringList__CExoStringListCtor__1;
// public CExoStringList::CExoStringListCExoStringList*
extern void * const CExoStringList__CExoStringListCtor__2;
// public CExoStringList::~CExoStringListvoid
extern void * const CExoStringList__CExoStringListDtor;
// void CExoStringList::__asCExoStringList&
extern void * const CExoStringList____as;
// void CExoStringList::__vcint
extern void * const CExoStringList____vc;
// public void CExoStringList::AddCExoString*
extern void * const CExoStringList__Add;
// private void CExoStringList::AddSortedCExoString*
extern void * const CExoStringList__AddSorted;
// void CExoStringList::Clearvoid
extern void * const CExoStringList__Clear;
// void CExoStringList::DeleteCExoString*
extern void * const CExoStringList__Delete;
// public int CExoStringList::GetCountvoid
extern void * const CExoStringList__GetCount;
// void CExoStringList::GetDuplicatevoid
extern void * const CExoStringList__GetDuplicate;
// void CExoStringList::GetSizevoid
extern void * const CExoStringList__GetSize;
// void CExoStringList::GetSortedvoid
extern void * const CExoStringList__GetSorted;
// public CExoString* CExoStringList::GetStringint
extern void * const CExoStringList__GetString;
// void CExoStringList::InsertCExoString*, int
extern void * const CExoStringList__Insert;
// private void CExoStringList::IntroduceCExoString*, int
extern void * const CExoStringList__Introduce;
// void CExoStringList::MergeCExoStringList*, int, int
extern void * const CExoStringList__Merge;
// void CExoStringList::Removeint
extern void * const CExoStringList__Remove;

// public CExoTimers::CExoTimersvoid
extern void * const CExoTimers__CExoTimersCtor;
// public CExoTimers::~CExoTimersvoid
extern void * const CExoTimers__CExoTimersDtor;
// public unsigned__int64 CExoTimers::GetHighResolutionTimervoid
extern void * const CExoTimers__GetHighResolutionTimer;
// public unsigned long int CExoTimers::GetLowResolutionTimervoid
extern void * const CExoTimers__GetLowResolutionTimer;

// public CExoTimersInternal::CExoTimersInternalvoid
extern void * const CExoTimersInternal__CExoTimersInternalCtor;
// public CExoTimersInternal::~CExoTimersInternalvoid
extern void * const CExoTimersInternal__CExoTimersInternalDtor;
// public unsigned__int64 CExoTimersInternal::GetHighResolutionTimervoid
extern void * const CExoTimersInternal__GetHighResolutionTimer;
// public unsigned long int CExoTimersInternal::GetLowResolutionTimervoid
extern void * const CExoTimersInternal__GetLowResolutionTimer;

// void CExtendedServerInfo::__asCNetLayerSessionInfo&
extern void * const CExtendedServerInfo____as;

// public CFactionManager::CFactionManagervoid
extern void * const CFactionManager__CFactionManagerCtor;
// public CFactionManager::~CFactionManagervoid
extern void * const CFactionManager__CFactionManagerDtor;
// public void CFactionManager::CreateDefaultFactionsvoid
extern void * const CFactionManager__CreateDefaultFactions;
// public void CFactionManager::DeleteFactionint
extern void * const CFactionManager__DeleteFaction;
// public CExoArrayListTemplatedint* CFactionManager::GetDefaultPCReputationvoid
extern void * const CFactionManager__GetDefaultPCReputation;
// public CNWSFaction* CFactionManager::GetFactionint
extern void * const CFactionManager__GetFaction;
// public int CFactionManager::GetFactionIdByNameconst CExoString&
extern void * const CFactionManager__GetFactionIdByName;
// public int CFactionManager::GetIsNPCFactionint
extern void * const CFactionManager__GetIsNPCFaction;
// public int CFactionManager::GetNPCFactionReputationint, int
extern void * const CFactionManager__GetNPCFactionReputation;
// public int CFactionManager::LoadFactionsCResGFF*, CResList*
extern void * const CFactionManager__LoadFactions;
// public int CFactionManager::LoadReputationsCResGFF*, CResList*
extern void * const CFactionManager__LoadReputations;
// public int CFactionManager::SaveFactionsCResGFF*, CResList*
extern void * const CFactionManager__SaveFactions;
// public int CFactionManager::SaveReputationsCResGFF*, CResList*
extern void * const CFactionManager__SaveReputations;
// public void CFactionManager::SetNPCFactionReputationint, int, int
extern void * const CFactionManager__SetNPCFactionReputation;

// public CGameEffect::CGameEffectint
extern void * const CGameEffect__CGameEffectCtor__0;
// public CGameEffect::CGameEffectCGameEffect*, int
extern void * const CGameEffect__CGameEffectCtor__1;
// public CGameEffect::~CGameEffectvoid
extern void * const CGameEffect__CGameEffectDtor;
// void CGameEffect::__asconst CGameEffect&
extern void * const CGameEffect____as;
// void CGameEffect::__eqconst CGameEffect& const
extern void * const CGameEffect____eq;
// void CGameEffect::__neconst CGameEffect& const
extern void * const CGameEffect____ne;
// public void CGameEffect::CopyEffectCGameEffect*, int
extern void * const CGameEffect__CopyEffect;
// public void CGameEffect::GetExpiryTimeunsigned long int*, unsigned long int*
extern void * const CGameEffect__GetExpiryTime;
// public float CGameEffect::GetFloatint
extern void * const CGameEffect__GetFloat;
// public int CGameEffect::GetIntegerint
extern void * const CGameEffect__GetInteger;
// public unsigned long int CGameEffect::GetObjectIDint
extern void * const CGameEffect__GetObjectID;
// public int CGameEffect::GetScriptEffectTypevoid
extern void * const CGameEffect__GetScriptEffectType;
// public CExoString CGameEffect::GetStringint
extern void * const CGameEffect__GetString;
// public void CGameEffect::LoadGameEffectCResGFF*, CResStruct*
extern void * const CGameEffect__LoadGameEffect;
// public void CGameEffect::SaveGameEffectCResGFF*, CResStruct*
extern void * const CGameEffect__SaveGameEffect;
// public void CGameEffect::SetCreatorunsigned long int
extern void * const CGameEffect__SetCreator;
// public void CGameEffect::SetExpiryTimeunsigned long int, unsigned long int
extern void * const CGameEffect__SetExpiryTime;
// public void CGameEffect::SetFloatint, float
extern void * const CGameEffect__SetFloat;
// public void CGameEffect::SetIntegerint, int
extern void * const CGameEffect__SetInteger;
// public void CGameEffect::SetLinkedCGameEffect*, CGameEffect*
extern void * const CGameEffect__SetLinked;
// public void CGameEffect::SetNumIntegersint
extern void * const CGameEffect__SetNumIntegers;
// public void CGameEffect::SetNumIntegersInitializeToNegativeOneint
extern void * const CGameEffect__SetNumIntegersInitializeToNegativeOne;
// public void CGameEffect::SetObjectIDint, unsigned long int
extern void * const CGameEffect__SetObjectID;
// public void CGameEffect::SetStringint, CExoString
extern void * const CGameEffect__SetString;
// public void CGameEffect::UpdateLinkedvoid
extern void * const CGameEffect__UpdateLinked;

// public CGameEffectApplierRemover::~CGameEffectApplierRemovervoid
extern void * const CGameEffectApplierRemover__CGameEffectApplierRemoverDtor;

// public CGameObject::CGameObjectunsigned char, unsigned long int
extern void * const CGameObject__CGameObjectCtor;
// public CGameObject::~CGameObjectvoid
extern void * const CGameObject__CGameObjectDtor;
// public CNWCArea* CGameObject::AsNWCAreavoid
extern void * const CGameObject__AsNWCArea;
// public CNWCAreaOfEffectObject* CGameObject::AsNWCAreaOfEffectObjectvoid
extern void * const CGameObject__AsNWCAreaOfEffectObject;
// public CNWCCreature* CGameObject::AsNWCCreaturevoid
extern void * const CGameObject__AsNWCCreature;
// public CNWCDoor* CGameObject::AsNWCDoorvoid
extern void * const CGameObject__AsNWCDoor;
// public CNWCItem* CGameObject::AsNWCItemvoid
extern void * const CGameObject__AsNWCItem;
// public CNWCModule* CGameObject::AsNWCModulevoid
extern void * const CGameObject__AsNWCModule;
// public CNWCObject* CGameObject::AsNWCObjectvoid
extern void * const CGameObject__AsNWCObject;
// public CNWCPlaceable* CGameObject::AsNWCPlaceablevoid
extern void * const CGameObject__AsNWCPlaceable;
// public CNWCProjectile* CGameObject::AsNWCProjectilevoid
extern void * const CGameObject__AsNWCProjectile;
// public CNWCSoundObject* CGameObject::AsNWCSoundObjectvoid
extern void * const CGameObject__AsNWCSoundObject;
// public CNWCStore* CGameObject::AsNWCStorevoid
extern void * const CGameObject__AsNWCStore;
// public CNWCTrigger* CGameObject::AsNWCTriggervoid
extern void * const CGameObject__AsNWCTrigger;
// public CNWSArea* CGameObject::AsNWSAreavoid
extern void * const CGameObject__AsNWSArea;
// public CNWSAreaOfEffectObject* CGameObject::AsNWSAreaOfEffectObjectvoid
extern void * const CGameObject__AsNWSAreaOfEffectObject;
// public CNWSCreature* CGameObject::AsNWSCreaturevoid
extern void * const CGameObject__AsNWSCreature;
// public CNWSDoor* CGameObject::AsNWSDoorvoid
extern void * const CGameObject__AsNWSDoor;
// public CNWSEncounter* CGameObject::AsNWSEncountervoid
extern void * const CGameObject__AsNWSEncounter;
// public CNWSItem* CGameObject::AsNWSItemvoid
extern void * const CGameObject__AsNWSItem;
// public CNWSModule* CGameObject::AsNWSModulevoid
extern void * const CGameObject__AsNWSModule;
// public CNWSObject* CGameObject::AsNWSObjectvoid
extern void * const CGameObject__AsNWSObject;
// public CNWSPlaceable* CGameObject::AsNWSPlaceablevoid
extern void * const CGameObject__AsNWSPlaceable;
// public CNWSPlayerTURD* CGameObject::AsNWSPlayerTURDvoid
extern void * const CGameObject__AsNWSPlayerTURD;
// public CNWSSoundObject* CGameObject::AsNWSSoundObjectvoid
extern void * const CGameObject__AsNWSSoundObject;
// public CNWSStore* CGameObject::AsNWSStorevoid
extern void * const CGameObject__AsNWSStore;
// public CNWSTrigger* CGameObject::AsNWSTriggervoid
extern void * const CGameObject__AsNWSTrigger;
// public CNWSWaypoint* CGameObject::AsNWSWaypointvoid
extern void * const CGameObject__AsNWSWaypoint;
// public void CGameObject::ResetUpdateTimesunsigned long int, unsigned long int
extern void * const CGameObject__ResetUpdateTimes;
// public void CGameObject::SetIdunsigned long int
extern void * const CGameObject__SetId;

// public CGameObjectArray::CGameObjectArrayint
extern void * const CGameObjectArray__CGameObjectArrayCtor;
// public CGameObjectArray::~CGameObjectArrayvoid
extern void * const CGameObjectArray__CGameObjectArrayDtor;
// void CGameObjectArray::AddCharacterObjectAtPosunsigned long int, CGameObject*
extern void * const CGameObjectArray__AddCharacterObjectAtPos;
// void CGameObjectArray::AddExternalObjectunsigned long int&, CGameObject*, int
extern void * const CGameObjectArray__AddExternalObject;
// public unsigned char CGameObjectArray::AddInternalObjectunsigned long int&, CGameObject*, int
extern void * const CGameObjectArray__AddInternalObject;
// public unsigned char CGameObjectArray::AddObjectAtPosunsigned long int, CGameObject*
extern void * const CGameObjectArray__AddObjectAtPos;
// void CGameObjectArray::Cleanunsigned short int
extern void * const CGameObjectArray__Clean;
// public unsigned char CGameObjectArray::Deleteunsigned long int
extern void * const CGameObjectArray__Delete__0;
// public unsigned char CGameObjectArray::Deleteunsigned long int, CGameObject**
extern void * const CGameObjectArray__Delete__1;
// public unsigned char CGameObjectArray::GetGameObjectunsigned long int, CGameObject**
extern void * const CGameObjectArray__GetGameObject;

// CGameSpyClient::CGameSpyClientCConnectionLib*, int&, const CExoString&
extern void * const CGameSpyClient__CGameSpyClientCtor;
// CGameSpyClient::~CGameSpyClientvoid
extern void * const CGameSpyClient__CGameSpyClientDtor;
// void CGameSpyClient::ChatNameMangleCExoString&
extern void * const CGameSpyClient__ChatNameMangle;
// void CGameSpyClient::ConnectCallbackvoid*, PEERBool, void*
extern void * const CGameSpyClient__ConnectCallback;
// void CGameSpyClient::DisconnectedCallbackvoid*, const char*, void*
extern void * const CGameSpyClient__DisconnectedCallback;
// void CGameSpyClient::EnumPlayersCallbackvoid*, PEERBool, RoomType, int, const char*, int, void*
extern void * const CGameSpyClient__EnumPlayersCallback;
// void CGameSpyClient::JoinGroupRoomint
extern void * const CGameSpyClient__JoinGroupRoom;
// void CGameSpyClient::JoinGroupRoomCallbackvoid*, PEERBool, PEERJoinResult, RoomType, void*
extern void * const CGameSpyClient__JoinGroupRoomCallback;
// void CGameSpyClient::ListGroupRoomsCallbackvoid*, PEERBool, int, _SBServer*, const char*, int, int, int, int, void*
extern void * const CGameSpyClient__ListGroupRoomsCallback;
// void CGameSpyClient::ListingGamesCallbackvoid*, PEERBool, const char*, _SBServer*, PEERBool, int, int, void*
extern void * const CGameSpyClient__ListingGamesCallback;
// void CGameSpyClient::NickErrorCallbackvoid*, int, const char*, void*
extern void * const CGameSpyClient__NickErrorCallback;
// void CGameSpyClient::PlayerChangedNickCallbackvoid*, RoomType, const char*, const char*, void*
extern void * const CGameSpyClient__PlayerChangedNickCallback;
// void CGameSpyClient::PlayerJoinedCallbackvoid*, RoomType, const char*, void*
extern void * const CGameSpyClient__PlayerJoinedCallback;
// void CGameSpyClient::PlayerLeftCallbackvoid*, RoomType, const char*, const char*, void*
extern void * const CGameSpyClient__PlayerLeftCallback;
// void CGameSpyClient::PlayerMessageCallbackvoid*, const char*, const char*, MessageType, void*
extern void * const CGameSpyClient__PlayerMessageCallback;
// void CGameSpyClient::RoomMessageCallbackvoid*, RoomType, const char*, const char*, MessageType, void*
extern void * const CGameSpyClient__RoomMessageCallback;
// void CGameSpyClient::SendMessageToNickconst char*, const char*
extern void * const CGameSpyClient__SendMessageToNick;
// void CGameSpyClient::SendMessageToRoomconst char*
extern void * const CGameSpyClient__SendMessageToRoom;
// void CGameSpyClient::SetGameBuildFilterconst CExoString&
extern void * const CGameSpyClient__SetGameBuildFilter;
// void CGameSpyClient::SetGameFiltersvoid
extern void * const CGameSpyClient__SetGameFilters;
// void CGameSpyClient::Updatevoid
extern void * const CGameSpyClient__Update;

// public CGameSpyServer::CGameSpyServerint, CConnectionLib*, int&
extern void * const CGameSpyServer__CGameSpyServerCtor;
// public CGameSpyServer::~CGameSpyServervoid
extern void * const CGameSpyServer__CGameSpyServerDtor;
// public void CGameSpyServer::AddErrorCallbackqr2_error_t, char*, void*
extern void * const CGameSpyServer__AddErrorCallback;
// public int CGameSpyServer::CountCallbackqr2_key_type, void*
extern void * const CGameSpyServer__CountCallback;
// public int CGameSpyServer::HandleGameSpyMessageunsigned long int, unsigned char*, unsigned long int
extern void * const CGameSpyServer__HandleGameSpyMessage;
// public void CGameSpyServer::KeyListCallbackqr2_key_type, qr2_keybuffer_s*, void*
extern void * const CGameSpyServer__KeyListCallback;
// public void CGameSpyServer::PlayerTeamKeyCallbackint, int, qr2_buffer_s*, void*
extern void * const CGameSpyServer__PlayerTeamKeyCallback;
// public void CGameSpyServer::RegisterAllKeysvoid
extern void * const CGameSpyServer__RegisterAllKeys;
// public void CGameSpyServer::ServerKeyCallbackint, qr2_buffer_s*, void*
extern void * const CGameSpyServer__ServerKeyCallback;
// public void CGameSpyServer::Updatevoid
extern void * const CGameSpyServer__Update;

// public CItemPropertyApplierRemover::~CItemPropertyApplierRemovervoid
extern void * const CItemPropertyApplierRemover__CItemPropertyApplierRemoverDtor;

// public CItemRepository::CItemRepositoryunsigned long int, unsigned char, unsigned char, unsigned long int, int
extern void * const CItemRepository__CItemRepositoryCtor;
// public CItemRepository::~CItemRepositoryvoid
extern void * const CItemRepository__CItemRepositoryDtor;
// public int CItemRepository::AddItemCNWSItem**, unsigned char, unsigned char, int, int
extern void * const CItemRepository__AddItem;
// void CItemRepository::AddPanelvoid
extern void * const CItemRepository__AddPanel;
// public int CItemRepository::CalculateContentsWeightvoid
extern void * const CItemRepository__CalculateContentsWeight;
// public unsigned char CItemRepository::CalculatePageunsigned char, unsigned char
extern void * const CItemRepository__CalculatePage;
// public int CItemRepository::CheckFitCNWSItem*, unsigned char, unsigned char
extern void * const CItemRepository__CheckFit;
// public int CItemRepository::CheckItemOverlapsCNWSItem*, CNWSItem*, unsigned char, unsigned char
extern void * const CItemRepository__CheckItemOverlaps;
// public unsigned long int CItemRepository::FindItemWithBaseItemIdunsigned long int, int
extern void * const CItemRepository__FindItemWithBaseItemId;
// public unsigned long int CItemRepository::FindItemWithTagCExoString*
extern void * const CItemRepository__FindItemWithTag;
// public int CItemRepository::FindPositionCNWSItem*, unsigned char&, unsigned char&, int
extern void * const CItemRepository__FindPosition;
// public int CItemRepository::GetItemInRepositoryCNWSItem*, int
extern void * const CItemRepository__GetItemInRepository__0;
// public int CItemRepository::GetItemInRepositoryunsigned char, unsigned char
extern void * const CItemRepository__GetItemInRepository__1;
// public CNWSItem* CItemRepository::ItemListGetItemCExoLinkedListNode*
extern void * const CItemRepository__ItemListGetItem;
// public unsigned long int CItemRepository::ItemListGetItemObjectIDCExoLinkedListNode*
extern void * const CItemRepository__ItemListGetItemObjectID;
// public int CItemRepository::MoveItemCNWSItem*, unsigned char, unsigned char
extern void * const CItemRepository__MoveItem;
// public int CItemRepository::RemoveItemCNWSItem*
extern void * const CItemRepository__RemoveItem;

// public CLastUpdateObject::CLastUpdateObjectvoid
extern void * const CLastUpdateObject__CLastUpdateObjectCtor;
// public CLastUpdateObject::~CLastUpdateObjectvoid
extern void * const CLastUpdateObject__CLastUpdateObjectDtor;
// public void CLastUpdateObject::InitializeQuickbarvoid
extern void * const CLastUpdateObject__InitializeQuickbar;

// public int CLoopingVisualEffect::GetIsBeamvoid
extern void * const CLoopingVisualEffect__GetIsBeam;

// void CMemRecord::Clearvoid
extern void * const CMemRecord__Clear;

// public CMstNetLayer::CMstNetLayerCConnectionLib*
extern void * const CMstNetLayer__CMstNetLayerCtor;
// public CMstNetLayer::~CMstNetLayervoid
extern void * const CMstNetLayer__CMstNetLayerDtor;
// public CExoString CMstNetLayer::GenerateCommunityNameResponseconst CExoString&, const CExoString&
extern void * const CMstNetLayer__GenerateCommunityNameResponse;
// public unsigned short int CMstNetLayer::GetCommunityNameStatusconst CExoString&, unsigned char**
extern void * const CMstNetLayer__GetCommunityNameStatus;
// private SMstDigiDistInfo* CMstNetLayer::GetDigiDistInfoCExoString&
extern void * const CMstNetLayer__GetDigiDistInfo;
// void CMstNetLayer::GetDigiDistModuleCipherCExoString&, int
extern void * const CMstNetLayer__GetDigiDistModuleCipher;
// public CExoString CMstNetLayer::GetKeyAuthDemandCExoString&
extern void * const CMstNetLayer__GetKeyAuthDemand;
// public CExoString CMstNetLayer::GetKeyCollisionvoid
extern void * const CMstNetLayer__GetKeyCollision;
// public unsigned long int CMstNetLayer::GetKeyRejectionReasonunsigned short int
extern void * const CMstNetLayer__GetKeyRejectionReason;
// public unsigned short int CMstNetLayer::GetKeyStatusconst CExoString&, unsigned short int&
extern void * const CMstNetLayer__GetKeyStatus;
// public CExoString CMstNetLayer::GetMasterServerInternetNamevoid
extern void * const CMstNetLayer__GetMasterServerInternetName;
// public unsigned long int CMstNetLayer::GetMasterServerPortvoid
extern void * const CMstNetLayer__GetMasterServerPort;
// void CMstNetLayer::GetNextBuddyEntryvoid
extern void * const CMstNetLayer__GetNextBuddyEntry;
// public void CMstNetLayer::HandleAddBuddyResponseunsigned char*, unsigned long int
extern void * const CMstNetLayer__HandleAddBuddyResponse;
// public void CMstNetLayer::HandleAuthorizationResponseunsigned char*, unsigned long int
extern void * const CMstNetLayer__HandleAuthorizationResponse;
// public void CMstNetLayer::HandleCommunityNameAuthResponseunsigned char*, unsigned long int
extern void * const CMstNetLayer__HandleCommunityNameAuthResponse;
// public void CMstNetLayer::HandleCreateAccountPartOneunsigned char*, unsigned long int
extern void * const CMstNetLayer__HandleCreateAccountPartOne;
// public void CMstNetLayer::HandleCreateAccountPartTwounsigned char*, unsigned long int
extern void * const CMstNetLayer__HandleCreateAccountPartTwo;
// public void CMstNetLayer::HandleDemandAuthorizationunsigned char*, unsigned long int
extern void * const CMstNetLayer__HandleDemandAuthorization;
// public void CMstNetLayer::HandleDemandHeartbeatunsigned char*, unsigned long int
extern void * const CMstNetLayer__HandleDemandHeartbeat;
// public void CMstNetLayer::HandleDigiDistAuthResponseunsigned char*, unsigned long int
extern void * const CMstNetLayer__HandleDigiDistAuthResponse;
// public void CMstNetLayer::HandleGetAvailabilityResponseunsigned char*, unsigned long int
extern void * const CMstNetLayer__HandleGetAvailabilityResponse;
// public void CMstNetLayer::HandleGetBuddyListResponseunsigned char*, unsigned long int
extern void * const CMstNetLayer__HandleGetBuddyListResponse;
// public int CMstNetLayer::HandleMasterServerToGameMessageunsigned char*, unsigned long int
extern void * const CMstNetLayer__HandleMasterServerToGameMessage;
// public void CMstNetLayer::HandleMOTDResponseunsigned char*, unsigned long int
extern void * const CMstNetLayer__HandleMOTDResponse;
// public void CMstNetLayer::HandleNotifyCollisionunsigned char*, unsigned long int
extern void * const CMstNetLayer__HandleNotifyCollision;
// public void CMstNetLayer::HandleRemoveBuddyResponseunsigned char*, unsigned long int
extern void * const CMstNetLayer__HandleRemoveBuddyResponse;
// public void CMstNetLayer::HandleSetAvailabilityResponseunsigned char*, unsigned long int
extern void * const CMstNetLayer__HandleSetAvailabilityResponse;
// public void CMstNetLayer::HandleStatusResponseunsigned char*, unsigned long int
extern void * const CMstNetLayer__HandleStatusResponse;
// public void CMstNetLayer::HandleVersionResponseunsigned char*, unsigned long int
extern void * const CMstNetLayer__HandleVersionResponse;
// void CMstNetLayer::SendAddBuddyRequestconst CExoString&, const CExoString&
extern void * const CMstNetLayer__SendAddBuddyRequest;
// void CMstNetLayer::SendClientToMasterCreateAccountPartOneconst CExoString&
extern void * const CMstNetLayer__SendClientToMasterCreateAccountPartOne;
// void CMstNetLayer::SendClientToMasterCreateAccountPartTwoconst CExoString&, const CExoString&, const CExoString&, unsigned char*, const CExoString&
extern void * const CMstNetLayer__SendClientToMasterCreateAccountPartTwo;
// void CMstNetLayer::SendClientToMasterMOTDRequestunsigned short int
extern void * const CMstNetLayer__SendClientToMasterMOTDRequest;
// void CMstNetLayer::SendClientToMasterVersionRequestunsigned short int
extern void * const CMstNetLayer__SendClientToMasterVersionRequest;
// void CMstNetLayer::SendDigiDistAuthRequestCExoArrayListTemplatedCExoString*, const CExoString&
extern void * const CMstNetLayer__SendDigiDistAuthRequest;
// public int CMstNetLayer::SendGameToMasterAuthorizationRequestunsigned long int, int
extern void * const CMstNetLayer__SendGameToMasterAuthorizationRequest__0;
// public int CMstNetLayer::SendGameToMasterAuthorizationRequestvoid*, int
extern void * const CMstNetLayer__SendGameToMasterAuthorizationRequest__1;
// public int CMstNetLayer::SendGameToMasterCommunityNameAuthconst CExoString&, const CExoString&, const CExoString&, unsigned short int, unsigned char
extern void * const CMstNetLayer__SendGameToMasterCommunityNameAuth;
// public int CMstNetLayer::SendGameToMasterDisconnectunsigned long int
extern void * const CMstNetLayer__SendGameToMasterDisconnect__0;
// public int CMstNetLayer::SendGameToMasterDisconnectvoid*, int
extern void * const CMstNetLayer__SendGameToMasterDisconnect__1;
// public int CMstNetLayer::SendGameToMasterHeartbeatvoid*, int
extern void * const CMstNetLayer__SendGameToMasterHeartbeat;
// public int CMstNetLayer::SendGameToMasterModuleunsigned char, const CExoString&
extern void * const CMstNetLayer__SendGameToMasterModule;
// public int CMstNetLayer::SendGameToMasterShutDownvoid
extern void * const CMstNetLayer__SendGameToMasterShutDown;
// public int CMstNetLayer::SendGameToMasterStartupunsigned char, unsigned long int, int, unsigned char, unsigned char
extern void * const CMstNetLayer__SendGameToMasterStartup;
// public int CMstNetLayer::SendGameToMasterStatusRequestvoid
extern void * const CMstNetLayer__SendGameToMasterStatusRequest;
// void CMstNetLayer::SendGetAvailabilityRequestconst CExoString&
extern void * const CMstNetLayer__SendGetAvailabilityRequest;
// void CMstNetLayer::SendGetBuddyListRequestconst CExoString&
extern void * const CMstNetLayer__SendGetBuddyListRequest;
// void CMstNetLayer::SendRemoveBuddyRequestconst CExoString&, const CExoString&
extern void * const CMstNetLayer__SendRemoveBuddyRequest;
// void CMstNetLayer::SendSetAvailabilityRequestconst CExoString&, unsigned short int
extern void * const CMstNetLayer__SendSetAvailabilityRequest;
// public void CMstNetLayer::SetLanguageint
extern void * const CMstNetLayer__SetLanguage;
// public void CMstNetLayer::StartHeartbeatTimerunsigned long long int
extern void * const CMstNetLayer__StartHeartbeatTimer;
// public void CMstNetLayer::StartSystemUpdateTimerunsigned long long int
extern void * const CMstNetLayer__StartSystemUpdateTimer;
// public void CMstNetLayer::StartTimeOutTimerunsigned long long int
extern void * const CMstNetLayer__StartTimeOutTimer;
// public int CMstNetLayer::UpdateHeartbeatTimerunsigned long long int
extern void * const CMstNetLayer__UpdateHeartbeatTimer;
// public int CMstNetLayer::UpdateSystemUpdateTimerunsigned long long int
extern void * const CMstNetLayer__UpdateSystemUpdateTimer;
// public int CMstNetLayer::UpdateTimeOutTimerunsigned long long int
extern void * const CMstNetLayer__UpdateTimeOutTimer;

// public CNetLayer::CNetLayervoid
extern void * const CNetLayer__CNetLayerCtor;
// public CNetLayer::~CNetLayervoid
extern void * const CNetLayer__CNetLayerDtor;
// void CNetLayer::CleanUpEnumerateSpecificvoid
extern void * const CNetLayer__CleanUpEnumerateSpecific;
// void CNetLayer::ClearSessionInfoChangedunsigned long int
extern void * const CNetLayer__ClearSessionInfoChanged;
// public int CNetLayer::CloseStandardConnectionint
extern void * const CNetLayer__CloseStandardConnection;
// void CNetLayer::DisconnectFromSessionvoid
extern void * const CNetLayer__DisconnectFromSession;
// public int CNetLayer::DisconnectPlayerunsigned long int, unsigned long int, int
extern void * const CNetLayer__DisconnectPlayer;
// void CNetLayer::DropConnectionToServervoid
extern void * const CNetLayer__DropConnectionToServer;
// void CNetLayer::EndConnectToSessionvoid
extern void * const CNetLayer__EndConnectToSession;
// void CNetLayer::EndEnumerateSessionsvoid
extern void * const CNetLayer__EndEnumerateSessions;
// public int CNetLayer::EndInternetAddressTranslationvoid
extern void * const CNetLayer__EndInternetAddressTranslation;
// void CNetLayer::EndPingunsigned long int
extern void * const CNetLayer__EndPing;
// public int CNetLayer::EndProtocolunsigned long int
extern void * const CNetLayer__EndProtocol;
// public int CNetLayer::EndServerModevoid
extern void * const CNetLayer__EndServerMode;
// void CNetLayer::EnumerateSessionsListunsigned char
extern void * const CNetLayer__EnumerateSessionsList;
// void CNetLayer::GetAnySessionsEnumeratedvoid
extern void * const CNetLayer__GetAnySessionsEnumerated;
// public int CNetLayer::GetAnyWindowBehindvoid
extern void * const CNetLayer__GetAnyWindowBehind;
// void CNetLayer::GetClientConnectedvoid
extern void * const CNetLayer__GetClientConnected;
// void CNetLayer::GetConnectionErrorvoid
extern void * const CNetLayer__GetConnectionError;
// public int CNetLayer::GetConnectionsMustBeValidatedvoid
extern void * const CNetLayer__GetConnectionsMustBeValidated;
// void CNetLayer::GetDisconnectStrrefvoid
extern void * const CNetLayer__GetDisconnectStrref;
// void CNetLayer::GetExoAppvoid
extern void * const CNetLayer__GetExoApp;
// void CNetLayer::GetExoNetvoid
extern void * const CNetLayer__GetExoNet;
// public unsigned short int CNetLayer::GetExpansionPackReqdvoid
extern void * const CNetLayer__GetExpansionPackReqd;
// public CExoString CNetLayer::GetGameMasterPasswordvoid
extern void * const CNetLayer__GetGameMasterPassword;
// void CNetLayer::GetGameMasterPermisionvoid const
extern void * const CNetLayer__GetGameMasterPermision;
// public unsigned long int CNetLayer::GetInternetAddressTranslationStatusunsigned char*
extern void * const CNetLayer__GetInternetAddressTranslationStatus;
// void CNetLayer::GetIPBySessionIdunsigned long int, CExoString*
extern void * const CNetLayer__GetIPBySessionId;
// void CNetLayer::GetLocalAdapterStringunsigned long int, unsigned long int
extern void * const CNetLayer__GetLocalAdapterString;
// void CNetLayer::GetLocalPrivilegesunsigned long int
extern void * const CNetLayer__GetLocalPrivileges;
// public int CNetLayer::GetMessageFromStandardConnectionint*, char**, int*
extern void * const CNetLayer__GetMessageFromStandardConnection;
// void CNetLayer::GetNumberLocalAdaptersunsigned long int
extern void * const CNetLayer__GetNumberLocalAdapters;
// public int CNetLayer::GetPasswordRequiredvoid
extern void * const CNetLayer__GetPasswordRequired;
// public CExoString CNetLayer::GetPlayerAddressunsigned long int
extern void * const CNetLayer__GetPlayerAddress;
// public int CNetLayer::GetPlayerAddressDataunsigned long int, unsigned long int*, unsigned char**, unsigned char**, unsigned long int*
extern void * const CNetLayer__GetPlayerAddressData;
// public CNetLayerPlayerInfo* CNetLayer::GetPlayerInfounsigned long int
extern void * const CNetLayer__GetPlayerInfo;
// public CExoString CNetLayer::GetPlayerPasswordvoid
extern void * const CNetLayer__GetPlayerPassword;
// void CNetLayer::GetPortBySessionIdunsigned long int
extern void * const CNetLayer__GetPortBySessionId;
// public unsigned long int CNetLayer::GetSendUDPSocketvoid
extern void * const CNetLayer__GetSendUDPSocket;
// public CExoString CNetLayer::GetServerAdminPasswordvoid
extern void * const CNetLayer__GetServerAdminPassword;
// void CNetLayer::GetServerConnectedvoid
extern void * const CNetLayer__GetServerConnected;
// void CNetLayer::GetServerNetworkAddressvoid
extern void * const CNetLayer__GetServerNetworkAddress;
// void CNetLayer::GetSessionInfounsigned long int
extern void * const CNetLayer__GetSessionInfo;
// void CNetLayer::GetSessionInfoChangedunsigned long int
extern void * const CNetLayer__GetSessionInfoChanged;
// public unsigned long int CNetLayer::GetSessionMaxPlayersvoid
extern void * const CNetLayer__GetSessionMaxPlayers;
// public CExoString CNetLayer::GetSessionNamevoid
extern void * const CNetLayer__GetSessionName;
// public unsigned long int CNetLayer::GetUDPRecievePortvoid
extern void * const CNetLayer__GetUDPRecievePort;
// public int CNetLayer::InitializeCBaseExoApp*
extern void * const CNetLayer__Initialize;
// void CNetLayer::IsConnectedToLocalhostvoid
extern void * const CNetLayer__IsConnectedToLocalhost;
// public int CNetLayer::MessageArrivedunsigned long int, unsigned long int, unsigned long int, int
extern void * const CNetLayer__MessageArrived;
// public int CNetLayer::OpenStandardConnectionint, CExoString, int
extern void * const CNetLayer__OpenStandardConnection;
// public int CNetLayer::PlayerIdToConnectionIdunsigned long int, unsigned long int*
extern void * const CNetLayer__PlayerIdToConnectionId;
// public void CNetLayer::ProcessReceivedFramesint
extern void * const CNetLayer__ProcessReceivedFrames;
// void CNetLayer::RequestExtendedServerInfounsigned long int, int, int
extern void * const CNetLayer__RequestExtendedServerInfo;
// void CNetLayer::RequestServerDetailsunsigned long int
extern void * const CNetLayer__RequestServerDetails;
// public int CNetLayer::SendMessageToAddressunsigned long int, unsigned char*, unsigned long int
extern void * const CNetLayer__SendMessageToAddress;
// public int CNetLayer::SendMessageToPlayerunsigned long int, unsigned char*, unsigned long int, unsigned long int
extern void * const CNetLayer__SendMessageToPlayer;
// public int CNetLayer::SendMessageToStandardConnectionint, char*, int
extern void * const CNetLayer__SendMessageToStandardConnection;
// public void CNetLayer::SetConnectionsDisallowedint
extern void * const CNetLayer__SetConnectionsDisallowed;
// public void CNetLayer::SetConnectionsMustBeValidatedint
extern void * const CNetLayer__SetConnectionsMustBeValidated;
// void CNetLayer::SetDisconnectStrrefunsigned long int
extern void * const CNetLayer__SetDisconnectStrref;
// public void CNetLayer::SetExpansionPackReqdunsigned short int
extern void * const CNetLayer__SetExpansionPackReqd;
// public int CNetLayer::SetGameMasterPasswordCExoString
extern void * const CNetLayer__SetGameMasterPassword;
// public void CNetLayer::SetMasterServerInternetAddressconst unsigned char*, unsigned long int
extern void * const CNetLayer__SetMasterServerInternetAddress;
// void CNetLayer::SetMstServerPasswordCExoString
extern void * const CNetLayer__SetMstServerPassword;
// public int CNetLayer::SetPlayerPasswordCExoString
extern void * const CNetLayer__SetPlayerPassword;
// public int CNetLayer::SetServerAdminPasswordCExoString
extern void * const CNetLayer__SetServerAdminPassword;
// public void CNetLayer::SetServerLanguageint
extern void * const CNetLayer__SetServerLanguage;
// void CNetLayer::SetSessionInfoChangedunsigned long int, int
extern void * const CNetLayer__SetSessionInfoChanged;
// public void CNetLayer::SetSessionMaxPlayersunsigned long int
extern void * const CNetLayer__SetSessionMaxPlayers;
// public void CNetLayer::SetSessionNameCExoString
extern void * const CNetLayer__SetSessionName;
// void CNetLayer::SetUpPlayBackConnectionvoid
extern void * const CNetLayer__SetUpPlayBackConnection;
// public int CNetLayer::ShutDownvoid
extern void * const CNetLayer__ShutDown;
// void CNetLayer::ShutDownClientInterfaceWithReasonunsigned long int
extern void * const CNetLayer__ShutDownClientInterfaceWithReason;
// void CNetLayer::StartConnectToSessionunsigned long int, const CExoString&, int, int, const CExoString&, unsigned long int, unsigned long int, const CExoString&
extern void * const CNetLayer__StartConnectToSession;
// void CNetLayer::StartEnumerateSessionsunsigned long int, int, unsigned char*, unsigned short int, int, unsigned short int, CExoString*, unsigned short int, CExoString*, unsigned short int, CExoString*
extern void * const CNetLayer__StartEnumerateSessions;
// public int CNetLayer::StartInternetAddressTranslationCExoString, unsigned long int, unsigned long int
extern void * const CNetLayer__StartInternetAddressTranslation;
// void CNetLayer::StartPingunsigned long int
extern void * const CNetLayer__StartPing;
// public int CNetLayer::StartProtocolunsigned long int, unsigned long int, unsigned long int, unsigned long int
extern void * const CNetLayer__StartProtocol;
// public int CNetLayer::StartServerModeCExoString, unsigned long int
extern void * const CNetLayer__StartServerMode;
// public void CNetLayer::StoreMessageunsigned char*, unsigned long int
extern void * const CNetLayer__StoreMessage;
// public int CNetLayer::TranslateAddressFromStringchar*, unsigned long int*, unsigned char*, unsigned char*, unsigned long int*
extern void * const CNetLayer__TranslateAddressFromString;
// public int CNetLayer::UpdateStatusLoopunsigned long int
extern void * const CNetLayer__UpdateStatusLoop;

// public CNetLayerInternal::CNetLayerInternalvoid
extern void * const CNetLayerInternal__CNetLayerInternalCtor;
// public CNetLayerInternal::~CNetLayerInternalvoid
extern void * const CNetLayerInternal__CNetLayerInternalDtor;
// void CNetLayerInternal::BroadcastMessageToAddressunsigned long int, unsigned long int, unsigned char*, unsigned long int
extern void * const CNetLayerInternal__BroadcastMessageToAddress;
// protected void CNetLayerInternal::CheckMasterServerTimeoutsvoid
extern void * const CNetLayerInternal__CheckMasterServerTimeouts;
// void CNetLayerInternal::CleanUpEnumerateSpecificvoid
extern void * const CNetLayerInternal__CleanUpEnumerateSpecific;
// void CNetLayerInternal::ClearSessionInfoChangedunsigned long int
extern void * const CNetLayerInternal__ClearSessionInfoChanged;
// public int CNetLayerInternal::CloseStandardConnectionint
extern void * const CNetLayerInternal__CloseStandardConnection;
// void CNetLayerInternal::ConnectionIdToSlidingWindowunsigned long int, unsigned long int*
extern void * const CNetLayerInternal__ConnectionIdToSlidingWindow;
// void CNetLayerInternal::ConnectToSessionLoopvoid
extern void * const CNetLayerInternal__ConnectToSessionLoop;
// void CNetLayerInternal::CRCBlockunsigned char*, unsigned long int
extern void * const CNetLayerInternal__CRCBlock;
// void CNetLayerInternal::CRCBuildTablevoid
extern void * const CNetLayerInternal__CRCBuildTable;
// void CNetLayerInternal::CRCEncodeFrameunsigned char*, unsigned long int
extern void * const CNetLayerInternal__CRCEncodeFrame;
// void CNetLayerInternal::CRCVerifyFrameunsigned char*, unsigned long int
extern void * const CNetLayerInternal__CRCVerifyFrame;
// void CNetLayerInternal::DisconnectFromSessionvoid
extern void * const CNetLayerInternal__DisconnectFromSession;
// public int CNetLayerInternal::DisconnectPlayerunsigned long int, unsigned long int, int, int
extern void * const CNetLayerInternal__DisconnectPlayer;
// void CNetLayerInternal::DropConnectionToServervoid
extern void * const CNetLayerInternal__DropConnectionToServer;
// void CNetLayerInternal::EndConnectToSessionvoid
extern void * const CNetLayerInternal__EndConnectToSession;
// void CNetLayerInternal::EndEnumerateSessionsvoid
extern void * const CNetLayerInternal__EndEnumerateSessions;
// public int CNetLayerInternal::EndInternetAddressTranslationvoid
extern void * const CNetLayerInternal__EndInternetAddressTranslation;
// public int CNetLayerInternal::EndPingunsigned long int
extern void * const CNetLayerInternal__EndPing;
// public int CNetLayerInternal::EndProtocolunsigned long int
extern void * const CNetLayerInternal__EndProtocol;
// public int CNetLayerInternal::EndServerModevoid
extern void * const CNetLayerInternal__EndServerMode;
// public int CNetLayerInternal::EnumerateSessionsListunsigned char
extern void * const CNetLayerInternal__EnumerateSessionsList;
// public int CNetLayerInternal::EnumerateSessionsLoopvoid
extern void * const CNetLayerInternal__EnumerateSessionsLoop;
// public int CNetLayerInternal::FindPlayerNameCExoString, unsigned long int
extern void * const CNetLayerInternal__FindPlayerName;
// void CNetLayerInternal::GetConnectionErrorvoid
extern void * const CNetLayerInternal__GetConnectionError;
// void CNetLayerInternal::GetExoAppvoid
extern void * const CNetLayerInternal__GetExoApp;
// public CExoString CNetLayerInternal::GetGameMasterPasswordvoid
extern void * const CNetLayerInternal__GetGameMasterPassword;
// public unsigned long int CNetLayerInternal::GetInternetAddressTranslationStatusunsigned char*
extern void * const CNetLayerInternal__GetInternetAddressTranslationStatus;
// void CNetLayerInternal::GetIPBySessionIdunsigned long int, CExoString*
extern void * const CNetLayerInternal__GetIPBySessionId;
// void CNetLayerInternal::GetLocalAdapterStringunsigned long int, unsigned long int
extern void * const CNetLayerInternal__GetLocalAdapterString;
// void CNetLayerInternal::GetLocalPrivilegesunsigned long int
extern void * const CNetLayerInternal__GetLocalPrivileges;
// public int CNetLayerInternal::GetMessageFromStandardConnectionint*, char**, int*
extern void * const CNetLayerInternal__GetMessageFromStandardConnection;
// void CNetLayerInternal::GetNumberLocalAdaptersunsigned long int
extern void * const CNetLayerInternal__GetNumberLocalAdapters;
// public int CNetLayerInternal::GetPasswordRequiredvoid
extern void * const CNetLayerInternal__GetPasswordRequired;
// public CExoString CNetLayerInternal::GetPlayerAddressunsigned long int
extern void * const CNetLayerInternal__GetPlayerAddress;
// public int CNetLayerInternal::GetPlayerAddressDataunsigned long int, unsigned long int*, unsigned char**, unsigned char**, unsigned long int*
extern void * const CNetLayerInternal__GetPlayerAddressData;
// public CExoString CNetLayerInternal::GetPlayerPasswordvoid
extern void * const CNetLayerInternal__GetPlayerPassword;
// void CNetLayerInternal::GetPortBySessionIdunsigned long int
extern void * const CNetLayerInternal__GetPortBySessionId;
// public unsigned long int CNetLayerInternal::GetSendUDPSocketvoid
extern void * const CNetLayerInternal__GetSendUDPSocket;
// public CExoString CNetLayerInternal::GetServerAdminPasswordvoid
extern void * const CNetLayerInternal__GetServerAdminPassword;
// void CNetLayerInternal::GetServerConnectedvoid
extern void * const CNetLayerInternal__GetServerConnected;
// void CNetLayerInternal::GetServerNetworkAddressvoid
extern void * const CNetLayerInternal__GetServerNetworkAddress;
// void CNetLayerInternal::GetServerPlayerCountvoid
extern void * const CNetLayerInternal__GetServerPlayerCount;
// void CNetLayerInternal::GetSessionInfounsigned long int
extern void * const CNetLayerInternal__GetSessionInfo;
// public unsigned long int CNetLayerInternal::GetSessionMaxPlayersvoid
extern void * const CNetLayerInternal__GetSessionMaxPlayers;
// public CExoString CNetLayerInternal::GetSessionNamevoid
extern void * const CNetLayerInternal__GetSessionName;
// public unsigned long int CNetLayerInternal::GetUDPRecievePortvoid
extern void * const CNetLayerInternal__GetUDPRecievePort;
// void CNetLayerInternal::GetWindowSendIdByReceiveIdunsigned long int, unsigned long int*
extern void * const CNetLayerInternal__GetWindowSendIdByReceiveId;
// public int CNetLayerInternal::HandleBNCRMessageunsigned long int, unsigned char*, unsigned long int
extern void * const CNetLayerInternal__HandleBNCRMessage;
// public int CNetLayerInternal::HandleBNCSMessageunsigned long int, unsigned char*, unsigned long int
extern void * const CNetLayerInternal__HandleBNCSMessage;
// void CNetLayerInternal::HandleBNDMMessageunsigned long int, unsigned char*, unsigned long int
extern void * const CNetLayerInternal__HandleBNDMMessage;
// void CNetLayerInternal::HandleBNDPMessageunsigned long int, unsigned char*, unsigned long int
extern void * const CNetLayerInternal__HandleBNDPMessage;
// public int CNetLayerInternal::HandleBNDRMessageunsigned long int, unsigned char*, unsigned long int
extern void * const CNetLayerInternal__HandleBNDRMessage;
// public int CNetLayerInternal::HandleBNDSMessageunsigned long int, unsigned char*, unsigned long int
extern void * const CNetLayerInternal__HandleBNDSMessage;
// public int CNetLayerInternal::HandleBNERMessageunsigned long int, unsigned char*, unsigned long int
extern void * const CNetLayerInternal__HandleBNERMessage;
// public int CNetLayerInternal::HandleBNESMessageunsigned long int, unsigned char*, unsigned long int
extern void * const CNetLayerInternal__HandleBNESMessage;
// public int CNetLayerInternal::HandleBNLMMessageunsigned long int, unsigned char*, unsigned long int
extern void * const CNetLayerInternal__HandleBNLMMessage;
// public int CNetLayerInternal::HandleBNLRMessageunsigned long int, unsigned char*, unsigned long int
extern void * const CNetLayerInternal__HandleBNLRMessage;
// public int CNetLayerInternal::HandleBNVRMessageunsigned long int, unsigned char*, unsigned long int
extern void * const CNetLayerInternal__HandleBNVRMessage;
// public int CNetLayerInternal::HandleBNVSMessageunsigned long int, unsigned char*, unsigned long int
extern void * const CNetLayerInternal__HandleBNVSMessage;
// public int CNetLayerInternal::HandleBNXIMessageunsigned long int, unsigned char*, unsigned long int
extern void * const CNetLayerInternal__HandleBNXIMessage;
// public int CNetLayerInternal::HandleBNXRMessageunsigned long int, unsigned char*, unsigned long int
extern void * const CNetLayerInternal__HandleBNXRMessage;
// public int CNetLayerInternal::InitializeCBaseExoApp*
extern void * const CNetLayerInternal__Initialize;
// public int CNetLayerInternal::IsConnectedToLocalhostvoid
extern void * const CNetLayerInternal__IsConnectedToLocalhost;
// public int CNetLayerInternal::IsPlayerIpSameAsConnectionunsigned long int, unsigned long int
extern void * const CNetLayerInternal__IsPlayerIpSameAsConnection;
// public int CNetLayerInternal::MessageArrivedunsigned long int, unsigned long int, unsigned long int, int
extern void * const CNetLayerInternal__MessageArrived;
// public int CNetLayerInternal::NonWindowMessagesunsigned long int, unsigned char*, unsigned long int
extern void * const CNetLayerInternal__NonWindowMessages;
// public int CNetLayerInternal::OpenStandardConnectionint, CExoString, int
extern void * const CNetLayerInternal__OpenStandardConnection;
// public int CNetLayerInternal::PacketizeSendMessageToPlayerunsigned long int, unsigned char*, unsigned long int, unsigned long int
extern void * const CNetLayerInternal__PacketizeSendMessageToPlayer;
// public int CNetLayerInternal::PacketizeSmallMessageToPlayerunsigned long int, unsigned char*, unsigned long int, unsigned long int
extern void * const CNetLayerInternal__PacketizeSmallMessageToPlayer;
// public int CNetLayerInternal::PlacePacketInSendQueuesunsigned long int, int, unsigned char*, unsigned long int, int
extern void * const CNetLayerInternal__PlacePacketInSendQueues;
// public int CNetLayerInternal::PlayerIdToConnectionIdunsigned long int, unsigned long int*
extern void * const CNetLayerInternal__PlayerIdToConnectionId;
// void CNetLayerInternal::PlayerIdToSlidingWindowunsigned long int, unsigned long int*
extern void * const CNetLayerInternal__PlayerIdToSlidingWindow;
// public void CNetLayerInternal::ProcessReceivedFramesint
extern void * const CNetLayerInternal__ProcessReceivedFrames;
// public int CNetLayerInternal::PurgeConnectionsvoid
extern void * const CNetLayerInternal__PurgeConnections;
// public int CNetLayerInternal::RequestExtendedServerInfounsigned long int, int, int
extern void * const CNetLayerInternal__RequestExtendedServerInfo;
// public int CNetLayerInternal::SendBNCRMessageunsigned long int, unsigned char, unsigned long int
extern void * const CNetLayerInternal__SendBNCRMessage;
// void CNetLayerInternal::SendBNCSMessageunsigned long int, unsigned char, int, int, const CExoString&, const CExoString&, unsigned long int&
extern void * const CNetLayerInternal__SendBNCSMessage;
// void CNetLayerInternal::SendBNDMMessagevoid
extern void * const CNetLayerInternal__SendBNDMMessage;
// public void CNetLayerInternal::SendBNDPMessageunsigned long int, unsigned long int
extern void * const CNetLayerInternal__SendBNDPMessage;
// void CNetLayerInternal::SendBNDSMessageunsigned long int
extern void * const CNetLayerInternal__SendBNDSMessage;
// public int CNetLayerInternal::SendBNLMMessageunsigned long int, unsigned long int
extern void * const CNetLayerInternal__SendBNLMMessage;
// public int CNetLayerInternal::SendBNVRMessageunsigned long int, unsigned char
extern void * const CNetLayerInternal__SendBNVRMessage;
// public int CNetLayerInternal::SendBNVSMessageconst CExoArrayListTemplatedCExoString*, const CExoString&, const CExoString&
extern void * const CNetLayerInternal__SendBNVSMessage;
// void CNetLayerInternal::SendDirectMessageunsigned long int, unsigned char*, unsigned long int, unsigned long int, unsigned long int
extern void * const CNetLayerInternal__SendDirectMessage;
// public int CNetLayerInternal::SendMessageToAddressunsigned long int, unsigned char*, unsigned long int
extern void * const CNetLayerInternal__SendMessageToAddress;
// public int CNetLayerInternal::SendMessageToPlayerunsigned long int, unsigned char*, unsigned long int, unsigned long int
extern void * const CNetLayerInternal__SendMessageToPlayer;
// public int CNetLayerInternal::SendMessageToStandardConnectionint, char*, int
extern void * const CNetLayerInternal__SendMessageToStandardConnection;
// public int CNetLayerInternal::SetGameMasterPasswordCExoString
extern void * const CNetLayerInternal__SetGameMasterPassword;
// public void CNetLayerInternal::SetMasterServerInternetAddressconst unsigned char*, unsigned long int
extern void * const CNetLayerInternal__SetMasterServerInternetAddress;
// void CNetLayerInternal::SetNetworkAddressDataunsigned long int, unsigned char*, unsigned char*, unsigned long int
extern void * const CNetLayerInternal__SetNetworkAddressData;
// public void CNetLayerInternal::SetPlayerConnectedunsigned long int
extern void * const CNetLayerInternal__SetPlayerConnected;
// public int CNetLayerInternal::SetPlayerPasswordCExoString
extern void * const CNetLayerInternal__SetPlayerPassword;
// public int CNetLayerInternal::SetServerAdminPasswordCExoString
extern void * const CNetLayerInternal__SetServerAdminPassword;
// public void CNetLayerInternal::SetServerLanguageint
extern void * const CNetLayerInternal__SetServerLanguage;
// public void CNetLayerInternal::SetSessionMaxPlayersunsigned long int
extern void * const CNetLayerInternal__SetSessionMaxPlayers;
// public void CNetLayerInternal::SetSessionNameCExoString
extern void * const CNetLayerInternal__SetSessionName;
// public int CNetLayerInternal::SetSlidingWindowunsigned long int, unsigned long int, unsigned long int*
extern void * const CNetLayerInternal__SetSlidingWindow;
// void CNetLayerInternal::SetUpPlayBackConnectionvoid
extern void * const CNetLayerInternal__SetUpPlayBackConnection;
// public int CNetLayerInternal::ShutDownvoid
extern void * const CNetLayerInternal__ShutDown;
// void CNetLayerInternal::ShutDownClientInterfaceWithReasonunsigned long int
extern void * const CNetLayerInternal__ShutDownClientInterfaceWithReason;
// void CNetLayerInternal::StartConnectToSessionunsigned long int, const CExoString&, int, int, const CExoString&, unsigned long int, unsigned long int, const CExoString&
extern void * const CNetLayerInternal__StartConnectToSession;
// void CNetLayerInternal::StartEnumerateSessionsunsigned long int, int, unsigned char*, unsigned short int, int, unsigned short int, CExoString*, unsigned short int, CExoString*, unsigned short int, CExoString*
extern void * const CNetLayerInternal__StartEnumerateSessions;
// public int CNetLayerInternal::StartInternetAddressTranslationCExoString, unsigned long int, unsigned long int
extern void * const CNetLayerInternal__StartInternetAddressTranslation;
// public int CNetLayerInternal::StartPingunsigned long int
extern void * const CNetLayerInternal__StartPing;
// public int CNetLayerInternal::StartProtocolunsigned long int, unsigned long int, unsigned long int, unsigned long int
extern void * const CNetLayerInternal__StartProtocol;
// public int CNetLayerInternal::StartServerModeCExoString, unsigned long int
extern void * const CNetLayerInternal__StartServerMode;
// public void CNetLayerInternal::StoreMessageunsigned char*, unsigned long int
extern void * const CNetLayerInternal__StoreMessage;
// public int CNetLayerInternal::UncompressMessageunsigned long int, unsigned char*, unsigned long int
extern void * const CNetLayerInternal__UncompressMessage;
// public int CNetLayerInternal::UpdateStatusLoopunsigned long int
extern void * const CNetLayerInternal__UpdateStatusLoop;
// public int CNetLayerInternal::ValidatePlayerAgainstLastSuccessfulLoginCExoString, CExoString
extern void * const CNetLayerInternal__ValidatePlayerAgainstLastSuccessfulLogin;

// public CNetLayerPlayerInfo::CNetLayerPlayerInfovoid
extern void * const CNetLayerPlayerInfo__CNetLayerPlayerInfoCtor;
// void CNetLayerPlayerInfo::AddCDKeyconst CExoString&, const CExoString&
extern void * const CNetLayerPlayerInfo__AddCDKey;
// public int CNetLayerPlayerInfo::AllKeysAuthedunsigned long int&
extern void * const CNetLayerPlayerInfo__AllKeysAuthed;
// public void CNetLayerPlayerInfo::Initializevoid
extern void * const CNetLayerPlayerInfo__Initialize;
// public void CNetLayerPlayerInfo::SetCDKeyint, const CExoString&, const CExoString&
extern void * const CNetLayerPlayerInfo__SetCDKey;
// void CNetLayerPlayerInfo::StartMstTimerunsigned long long int
extern void * const CNetLayerPlayerInfo__StartMstTimer;
// void CNetLayerPlayerInfo::UpdateMstTimerunsigned long long int
extern void * const CNetLayerPlayerInfo__UpdateMstTimer;

// CNetLayerSessionInfo::CNetLayerSessionInfovoid
extern void * const CNetLayerSessionInfo__CNetLayerSessionInfoCtor;
// public CNetLayerSessionInfo::~CNetLayerSessionInfovoid
extern void * const CNetLayerSessionInfo__CNetLayerSessionInfoDtor;

// public CNetLayerWindow::CNetLayerWindowvoid
extern void * const CNetLayerWindow__CNetLayerWindowCtor;
// public CNetLayerWindow::~CNetLayerWindowvoid
extern void * const CNetLayerWindow__CNetLayerWindowDtor;
// void CNetLayerWindow::AddToHighOutgoingQueueunsigned short int
extern void * const CNetLayerWindow__AddToHighOutgoingQueue;
// void CNetLayerWindow::AddToLowOutgoingQueueunsigned short int
extern void * const CNetLayerWindow__AddToLowOutgoingQueue;
// public void CNetLayerWindow::CutOutgoingBufferSizevoid
extern void * const CNetLayerWindow__CutOutgoingBufferSize;
// void CNetLayerWindow::DoubleOutgoingBufferSizevoid
extern void * const CNetLayerWindow__DoubleOutgoingBufferSize;
// void CNetLayerWindow::FauxNaglevoid
extern void * const CNetLayerWindow__FauxNagle;
// void CNetLayerWindow::FrameNumberBetweenunsigned long int, unsigned long int, unsigned long int
extern void * const CNetLayerWindow__FrameNumberBetween;
// public int CNetLayerWindow::FrameReceiveunsigned char*, unsigned long int
extern void * const CNetLayerWindow__FrameReceive;
// public void CNetLayerWindow::FrameSendunsigned char, unsigned short int, unsigned short int
extern void * const CNetLayerWindow__FrameSend;
// public int CNetLayerWindow::FrameTimeoutunsigned long int
extern void * const CNetLayerWindow__FrameTimeout;
// public void CNetLayerWindow::InitializeCNetLayerInternal*
extern void * const CNetLayerWindow__Initialize;
// public void CNetLayerWindow::InitializeCompressionBuffersvoid
extern void * const CNetLayerWindow__InitializeCompressionBuffers;
// public void CNetLayerWindow::LoadWindowWithFramesvoid
extern void * const CNetLayerWindow__LoadWindowWithFrames;
// void CNetLayerWindow::PlaceFrameInOutgoingBuffersunsigned short int
extern void * const CNetLayerWindow__PlaceFrameInOutgoingBuffers;
// void CNetLayerWindow::SetAckTimervoid
extern void * const CNetLayerWindow__SetAckTimer;
// void CNetLayerWindow::SetFauxNagleTimervoid
extern void * const CNetLayerWindow__SetFauxNagleTimer;
// void CNetLayerWindow::SetInFrameTimervoid
extern void * const CNetLayerWindow__SetInFrameTimer;
// void CNetLayerWindow::SetOutFrameTimerunsigned long int
extern void * const CNetLayerWindow__SetOutFrameTimer;
// public void CNetLayerWindow::ShutDownvoid
extern void * const CNetLayerWindow__ShutDown;
// void CNetLayerWindow::TestAckTimerunsigned long int
extern void * const CNetLayerWindow__TestAckTimer;
// void CNetLayerWindow::TestFauxNagleTimerunsigned long int
extern void * const CNetLayerWindow__TestFauxNagleTimer;
// void CNetLayerWindow::TestInFrameTimerunsigned long int
extern void * const CNetLayerWindow__TestInFrameTimer;
// void CNetLayerWindow::TestOutFrameTimerunsigned long int, unsigned long int
extern void * const CNetLayerWindow__TestOutFrameTimer;
// public int CNetLayerWindow::UnpacketizeFullMessagesint
extern void * const CNetLayerWindow__UnpacketizeFullMessages;

// public CNetworkProfiler::CNetworkProfilervoid
extern void * const CNetworkProfiler__CNetworkProfilerCtor;
// CNetworkProfiler::~CNetworkProfilervoid
extern void * const CNetworkProfiler__CNetworkProfilerDtor;
// public void CNetworkProfiler::AddMessageToFrameProfileunsigned char, unsigned long int
extern void * const CNetworkProfiler__AddMessageToFrameProfile;
// public void CNetworkProfiler::AddMessageToProfileunsigned char, unsigned char, unsigned char, unsigned long int
extern void * const CNetworkProfiler__AddMessageToProfile;
// void CNetworkProfiler::GetFrameLastTimevoid
extern void * const CNetworkProfiler__GetFrameLastTime;
// void CNetworkProfiler::GetFrameStartTimevoid
extern void * const CNetworkProfiler__GetFrameStartTime;
// void CNetworkProfiler::GetLastTimevoid
extern void * const CNetworkProfiler__GetLastTime;
// void CNetworkProfiler::GetStartTimevoid
extern void * const CNetworkProfiler__GetStartTime;
// public void CNetworkProfiler::OutputReportvoid
extern void * const CNetworkProfiler__OutputReport;
// void CNetworkProfiler::SetOutputFilenamechar*
extern void * const CNetworkProfiler__SetOutputFilename;
// public int CNetworkProfiler::SetStateint
extern void * const CNetworkProfiler__SetState;

// public CNWArea::CNWAreavoid
extern void * const CNWArea__CNWAreaCtor;
// public CNWArea::~CNWAreavoid
extern void * const CNWArea__CNWAreaDtor;
// public int CNWArea::AddStaticBoundingBoxunsigned long int, const Vector&, const Vector&
extern void * const CNWArea__AddStaticBoundingBox;
// public int CNWArea::AddStaticObjectunsigned long int, const Vector&, const Vector&, int, Vector*, int, int*
extern void * const CNWArea__AddStaticObject;
// void CNWArea::GetFlagsvoid
extern void * const CNWArea__GetFlags;
// void CNWArea::GetFogint*, Vector*
extern void * const CNWArea__GetFog;
// void CNWArea::GetFogClipDistancevoid
extern void * const CNWArea__GetFogClipDistance;
// void CNWArea::GetHeightvoid
extern void * const CNWArea__GetHeight;
// public int CNWArea::GetIsIDInExcludeListunsigned long int, CExoArrayListTemplatedCGameObjectPtr*
extern void * const CNWArea__GetIsIDInExcludeList;
// void CNWArea::GetIsNightvoid
extern void * const CNWArea__GetIsNight;
// void CNWArea::GetMoonFogAmountvoid
extern void * const CNWArea__GetMoonFogAmount;
// void CNWArea::GetMoonFogColorvoid
extern void * const CNWArea__GetMoonFogColor;
// void CNWArea::GetNoRestingAllowedvoid
extern void * const CNWArea__GetNoRestingAllowed;
// void CNWArea::GetShadowOpacityvoid
extern void * const CNWArea__GetShadowOpacity;
// void CNWArea::GetSkyBoxvoid
extern void * const CNWArea__GetSkyBox;
// void CNWArea::GetSunFogAmountvoid
extern void * const CNWArea__GetSunFogAmount;
// void CNWArea::GetSunFogColorvoid
extern void * const CNWArea__GetSunFogColor;
// void CNWArea::GetUseDayNightCyclevoid
extern void * const CNWArea__GetUseDayNightCycle;
// void CNWArea::GetWidthvoid
extern void * const CNWArea__GetWidth;
// public void CNWArea::GrowStaticObjectArrayvoid
extern void * const CNWArea__GrowStaticObjectArray;
// public void CNWArea::GrowStaticObjectTrianglesint
extern void * const CNWArea__GrowStaticObjectTriangles;
// public void CNWArea::GrowStaticObjectVerticesint
extern void * const CNWArea__GrowStaticObjectVertices;
// public int CNWArea::HandleTransparentDoorsfloat, float, float, float, float, float, float, unsigned long int, unsigned long int&, int, CExoArrayListTemplatedCGameObjectPtr*, int
extern void * const CNWArea__HandleTransparentDoors;
// public void CNWArea::InitializeStaticObjectsvoid
extern void * const CNWArea__InitializeStaticObjects;
// public int CNWArea::IntersectLineSegmentsfloat, float, float, float, float, float, float, float, float*, float*
extern void * const CNWArea__IntersectLineSegments;
// public int CNWArea::NoCreaturesOnLinefloat, float, float, float, CPathfindInformation*
extern void * const CNWArea__NoCreaturesOnLine;
// public int CNWArea::NoNonWalkPolysfloat, float, float, float, float, float, float, unsigned long int
extern void * const CNWArea__NoNonWalkPolys;
// public int CNWArea::NoNonWalkPolysDetailedfloat, float, float, float, float, float, float, unsigned long int, unsigned long int&, int, CExoArrayListTemplatedCGameObjectPtr*, int
extern void * const CNWArea__NoNonWalkPolysDetailed;
// public int CNWArea::NoNonWalkPolysInDoorsfloat, float, float, float, float, float, float, unsigned long int, unsigned long int&, int, CExoArrayListTemplatedCGameObjectPtr*, int
extern void * const CNWArea__NoNonWalkPolysInDoors;
// public int CNWArea::RemoveStaticBoundingBoxunsigned long int
extern void * const CNWArea__RemoveStaticBoundingBox;
// public void CNWArea::RemoveStaticObjectint
extern void * const CNWArea__RemoveStaticObject;
// public void CNWArea::ReplaceStaticObjectint, unsigned long int, const Vector&, const Vector&, int, Vector*, int, int*
extern void * const CNWArea__ReplaceStaticObject;
// public int CNWArea::SetFogint, Vector
extern void * const CNWArea__SetFog;
// public int CNWArea::SetIsNightint
extern void * const CNWArea__SetIsNight;
// void CNWArea::SetMoonFogAmountunsigned char
extern void * const CNWArea__SetMoonFogAmount;
// void CNWArea::SetMoonFogColorunsigned long int
extern void * const CNWArea__SetMoonFogColor;
// void CNWArea::SetSkyBoxunsigned char
extern void * const CNWArea__SetSkyBox;
// void CNWArea::SetSunFogAmountunsigned char
extern void * const CNWArea__SetSunFogAmount;
// void CNWArea::SetSunFogColorunsigned long int
extern void * const CNWArea__SetSunFogColor;
// void CNWArea::SetUseDayNightCycleint
extern void * const CNWArea__SetUseDayNightCycle;
// public int CNWArea::SetWindunsigned char
extern void * const CNWArea__SetWind;

// public CNWBaseItem::CNWBaseItemvoid
extern void * const CNWBaseItem__CNWBaseItemCtor;
// public CNWBaseItem::~CNWBaseItemvoid
extern void * const CNWBaseItem__CNWBaseItemDtor;
// public CResRef CNWBaseItem::GetIconResRefunsigned char, short int, char
extern void * const CNWBaseItem__GetIconResRef;
// public CResRef CNWBaseItem::GetModelResRefunsigned char, short int, char
extern void * const CNWBaseItem__GetModelResRef;
// void CNWBaseItem::GetNameTextvoid
extern void * const CNWBaseItem__GetNameText;
// public unsigned short int CNWBaseItem::GetRequiredFeatunsigned char
extern void * const CNWBaseItem__GetRequiredFeat;
// void CNWBaseItem::SetRequiredFeatunsigned char, unsigned short int
extern void * const CNWBaseItem__SetRequiredFeat;
// void CNWBaseItem::SetRequiredFeatCountunsigned char
extern void * const CNWBaseItem__SetRequiredFeatCount;

// public CNWBaseItemArray::CNWBaseItemArrayvoid
extern void * const CNWBaseItemArray__CNWBaseItemArrayCtor;
// public CNWBaseItemArray::~CNWBaseItemArrayvoid
extern void * const CNWBaseItemArray__CNWBaseItemArrayDtor;
// public CNWBaseItem* CNWBaseItemArray::GetBaseItemint const
extern void * const CNWBaseItemArray__GetBaseItem;
// public void CNWBaseItemArray::Loadvoid
extern void * const CNWBaseItemArray__Load;

// public CNWCCMessageData::CNWCCMessageDatavoid
extern void * const CNWCCMessageData__CNWCCMessageDataCtor;
// public CNWCCMessageData::~CNWCCMessageDatavoid
extern void * const CNWCCMessageData__CNWCCMessageDataDtor;
// void CNWCCMessageData::ClearDatavoid
extern void * const CNWCCMessageData__ClearData;
// public void CNWCCMessageData::CopyToCNWCCMessageData*
extern void * const CNWCCMessageData__CopyTo;
// void CNWCCMessageData::GetFloatint
extern void * const CNWCCMessageData__GetFloat;
// public int CNWCCMessageData::GetIntegerint
extern void * const CNWCCMessageData__GetInteger;
// public unsigned long int CNWCCMessageData::GetObjectIDint
extern void * const CNWCCMessageData__GetObjectID;
// public CExoString CNWCCMessageData::GetStringint
extern void * const CNWCCMessageData__GetString;
// public int CNWCCMessageData::LoadDataCResGFF*, CResStruct*
extern void * const CNWCCMessageData__LoadData;
// public int CNWCCMessageData::SaveDataCResGFF*, CResStruct*
extern void * const CNWCCMessageData__SaveData;
// void CNWCCMessageData::SetFloatint, float
extern void * const CNWCCMessageData__SetFloat;
// public void CNWCCMessageData::SetIntegerint, int
extern void * const CNWCCMessageData__SetInteger;
// public void CNWCCMessageData::SetObjectIDint, unsigned long int
extern void * const CNWCCMessageData__SetObjectID;
// public void CNWCCMessageData::SetStringint, CExoString
extern void * const CNWCCMessageData__SetString;

// public CNWClass::CNWClassvoid
extern void * const CNWClass__CNWClassCtor;
// public CNWClass::~CNWClassvoid
extern void * const CNWClass__CNWClassDtor;
// public unsigned char CNWClass::GetAttackBonusunsigned char
extern void * const CNWClass__GetAttackBonus;
// public unsigned char CNWClass::GetBonusFeatsunsigned char
extern void * const CNWClass__GetBonusFeats;
// void CNWClass::GetClassFeatunsigned short int
extern void * const CNWClass__GetClassFeat;
// void CNWClass::GetDescriptionTextvoid
extern void * const CNWClass__GetDescriptionText;
// public unsigned char CNWClass::GetFortSaveBonusunsigned char
extern void * const CNWClass__GetFortSaveBonus;
// public int CNWClass::GetIsAlignmentAllowedunsigned char, unsigned char
extern void * const CNWClass__GetIsAlignmentAllowed;
// void CNWClass::GetLevelFeatGrantedunsigned short int
extern void * const CNWClass__GetLevelFeatGranted;
// void CNWClass::GetLevelGrantedunsigned short int
extern void * const CNWClass__GetLevelGranted;
// void CNWClass::GetNameLowerTextvoid
extern void * const CNWClass__GetNameLowerText;
// void CNWClass::GetNamePluralTextvoid
extern void * const CNWClass__GetNamePluralText;
// void CNWClass::GetNameTextvoid
extern void * const CNWClass__GetNameText;
// public unsigned char CNWClass::GetRefSaveBonusunsigned char
extern void * const CNWClass__GetRefSaveBonus;
// public unsigned char CNWClass::GetSpellGainunsigned char, unsigned char
extern void * const CNWClass__GetSpellGain;
// public unsigned char CNWClass::GetSpellsKnownPerLevelunsigned char, unsigned char, unsigned char, unsigned short int, unsigned char
extern void * const CNWClass__GetSpellsKnownPerLevel;
// public unsigned char CNWClass::GetWillSaveBonusunsigned char
extern void * const CNWClass__GetWillSaveBonus;
// public int CNWClass::IsBonusFeatunsigned short int
extern void * const CNWClass__IsBonusFeat;
// void CNWClass::IsFeatUseableunsigned short int
extern void * const CNWClass__IsFeatUseable;
// public int CNWClass::IsGrantedFeatunsigned short int, unsigned char&
extern void * const CNWClass__IsGrantedFeat;
// public int CNWClass::IsNormalFeatunsigned short int
extern void * const CNWClass__IsNormalFeat;
// public int CNWClass::IsSkillClassSkillunsigned short int
extern void * const CNWClass__IsSkillClassSkill;
// public int CNWClass::IsSkillUseableunsigned short int
extern void * const CNWClass__IsSkillUseable;
// public void CNWClass::LoadAttackBonusTableCExoString
extern void * const CNWClass__LoadAttackBonusTable;
// public void CNWClass::LoadBonusFeatsTableCExoString
extern void * const CNWClass__LoadBonusFeatsTable;
// public void CNWClass::LoadFeatsTableCExoString, CNWRules*
extern void * const CNWClass__LoadFeatsTable;
// public void CNWClass::LoadSavingThrowTableCExoString
extern void * const CNWClass__LoadSavingThrowTable;
// public void CNWClass::LoadSkillsTableCExoString
extern void * const CNWClass__LoadSkillsTable;
// public void CNWClass::LoadSpellGainTableCExoString
extern void * const CNWClass__LoadSpellGainTable;
// public void CNWClass::LoadSpellKnownTableCExoString
extern void * const CNWClass__LoadSpellKnownTable;

// public CNWCreatureStatsUpdate::CNWCreatureStatsUpdatevoid
extern void * const CNWCreatureStatsUpdate__CNWCreatureStatsUpdateCtor;
// public CNWCreatureStatsUpdate::~CNWCreatureStatsUpdatevoid
extern void * const CNWCreatureStatsUpdate__CNWCreatureStatsUpdateDtor;
// public void CNWCreatureStatsUpdate::ClearEffectIconsvoid
extern void * const CNWCreatureStatsUpdate__ClearEffectIcons;
// public void CNWCreatureStatsUpdate::SetCombatInformationCCombatInformation*
extern void * const CNWCreatureStatsUpdate__SetCombatInformation;

// public CNWDomain::CNWDomainvoid
extern void * const CNWDomain__CNWDomainCtor;
// public CNWDomain::~CNWDomainvoid
extern void * const CNWDomain__CNWDomainDtor;
// void CNWDomain::GetDescriptionTextvoid
extern void * const CNWDomain__GetDescriptionText;
// void CNWDomain::GetNameTextvoid
extern void * const CNWDomain__GetNameText;

// public CNWDoorSurfaceMesh::CNWDoorSurfaceMeshvoid
extern void * const CNWDoorSurfaceMesh__CNWDoorSurfaceMeshCtor;
// public CNWDoorSurfaceMesh::~CNWDoorSurfaceMeshvoid
extern void * const CNWDoorSurfaceMesh__CNWDoorSurfaceMeshDtor;
// public int CNWDoorSurfaceMesh::GetMeshBoundingBoxVector, Vector, Vector&, Vector&
extern void * const CNWDoorSurfaceMesh__GetMeshBoundingBox;
// void CNWDoorSurfaceMesh::GetOpenLocationunsigned char, unsigned char
extern void * const CNWDoorSurfaceMesh__GetOpenLocation;
// public int CNWDoorSurfaceMesh::IntersectLineSegmentsVector, Vector, Vector, Vector, Vector*
extern void * const CNWDoorSurfaceMesh__IntersectLineSegments;
// public int CNWDoorSurfaceMesh::LoadWalkMeshCResRef
extern void * const CNWDoorSurfaceMesh__LoadWalkMesh;
// void CNWDoorSurfaceMesh::LoadWalkMeshStringunsigned char**, unsigned long int*, unsigned char*, unsigned long int
extern void * const CNWDoorSurfaceMesh__LoadWalkMeshString;
// public int CNWDoorSurfaceMesh::NoNonWalkPolysOnSurfaceMeshint, float, float, float, float, float, float, float
extern void * const CNWDoorSurfaceMesh__NoNonWalkPolysOnSurfaceMesh;

// public CNWFeat::CNWFeatvoid
extern void * const CNWFeat__CNWFeatCtor;
// public CNWFeat::~CNWFeatvoid
extern void * const CNWFeat__CNWFeatDtor;
// void CNWFeat::GetDescriptionTextvoid
extern void * const CNWFeat__GetDescriptionText;
// public CExoString CNWFeat::GetNameTextvoid
extern void * const CNWFeat__GetNameText;

// public CNWItem::CNWItemvoid
extern void * const CNWItem__CNWItemCtor;
// public CNWItem::~CNWItemvoid
extern void * const CNWItem__CNWItemDtor;
// void CNWItem::GetBaseItemIDvoid
extern void * const CNWItem__GetBaseItemID;
// void CNWItem::GetLayeredTextureColorunsigned char
extern void * const CNWItem__GetLayeredTextureColor;
// void CNWItem::SetBaseItemIDunsigned long int
extern void * const CNWItem__SetBaseItemID;
// void CNWItem::SetLayeredTextureColorunsigned char, unsigned char
extern void * const CNWItem__SetLayeredTextureColor;

// public CNWLevelStats::CNWLevelStatsvoid
extern void * const CNWLevelStats__CNWLevelStatsCtor;
// public CNWLevelStats::~CNWLevelStatsvoid
extern void * const CNWLevelStats__CNWLevelStatsDtor;
// public void CNWLevelStats::AddFeatunsigned short int
extern void * const CNWLevelStats__AddFeat;
// void CNWLevelStats::ClearFeatsvoid
extern void * const CNWLevelStats__ClearFeats;
// public char CNWLevelStats::GetSkillRankChangeunsigned short int
extern void * const CNWLevelStats__GetSkillRankChange;
// public void CNWLevelStats::SetSkillRankChangeunsigned short int, char
extern void * const CNWLevelStats__SetSkillRankChange;

// public CNWMessage::CNWMessagevoid
extern void * const CNWMessage__CNWMessageCtor;
// public CNWMessage::~CNWMessagevoid
extern void * const CNWMessage__CNWMessageDtor;
// public void CNWMessage::ClearReadMessagevoid
extern void * const CNWMessage__ClearReadMessage;
// public void CNWMessage::CreateWriteMessageunsigned long int, unsigned long int, int
extern void * const CNWMessage__CreateWriteMessage;
// protected void CNWMessage::ExtendWriteBufferunsigned long int
extern void * const CNWMessage__ExtendWriteBuffer;
// protected void CNWMessage::ExtendWriteFragmentsBufferunsigned long int
extern void * const CNWMessage__ExtendWriteFragmentsBuffer;
// void CNWMessage::GetObjectLookupTablevoid
extern void * const CNWMessage__GetObjectLookupTable;
// public int CNWMessage::GetWriteMessageunsigned char**, unsigned long int*
extern void * const CNWMessage__GetWriteMessage;
// void CNWMessage::MessageMoreDataToReadvoid
extern void * const CNWMessage__MessageMoreDataToRead;
// public int CNWMessage::MessageReadOverflowint
extern void * const CNWMessage__MessageReadOverflow;
// public int CNWMessage::MessageReadUnderflowint
extern void * const CNWMessage__MessageReadUnderflow;
// public unsigned long int CNWMessage::PeekAtWriteMessageSizevoid
extern void * const CNWMessage__PeekAtWriteMessageSize;
// void CNWMessage::ReadBitunsigned char
extern void * const CNWMessage__ReadBit;
// protected __int64 CNWMessage::ReadBitsint
extern void * const CNWMessage__ReadBits;
// public int CNWMessage::ReadBOOLvoid
extern void * const CNWMessage__ReadBOOL;
// public unsigned char CNWMessage::ReadBYTEint
extern void * const CNWMessage__ReadBYTE;
// public CExoString CNWMessage::ReadCExoStringint
extern void * const CNWMessage__ReadCExoString;
// public char CNWMessage::ReadCHARint
extern void * const CNWMessage__ReadCHAR;
// public CResRef CNWMessage::ReadCResRefint
extern void * const CNWMessage__ReadCResRef;
// void CNWMessage::ReadDOUBLEdouble, int
extern void * const CNWMessage__ReadDOUBLE__0;
// void CNWMessage::ReadDOUBLEdouble, double, int
extern void * const CNWMessage__ReadDOUBLE__1;
// public unsigned long int CNWMessage::ReadDWORDint
extern void * const CNWMessage__ReadDWORD;
// void CNWMessage::ReadDWORD64int
extern void * const CNWMessage__ReadDWORD64;
// public float CNWMessage::ReadFLOATfloat, int
extern void * const CNWMessage__ReadFLOAT__0;
// public float CNWMessage::ReadFLOATfloat, float, int
extern void * const CNWMessage__ReadFLOAT__1;
// public int CNWMessage::ReadINTint
extern void * const CNWMessage__ReadINT;
// void CNWMessage::ReadINT64int
extern void * const CNWMessage__ReadINT64;
// void CNWMessage::ReadSHORTint
extern void * const CNWMessage__ReadSHORT;
// void CNWMessage::ReadSignedint
extern void * const CNWMessage__ReadSigned;
// protected unsigned__int64 CNWMessage::ReadUnsignedint
extern void * const CNWMessage__ReadUnsigned;
// public void* CNWMessage::ReadVOIDPtrint
extern void * const CNWMessage__ReadVOIDPtr;
// public unsigned short int CNWMessage::ReadWORDint
extern void * const CNWMessage__ReadWORD;
// public void CNWMessage::SetReadMessageunsigned char*, unsigned long int, unsigned long int, int
extern void * const CNWMessage__SetReadMessage;
// protected void CNWMessage::WriteBitunsigned char
extern void * const CNWMessage__WriteBit;
// protected void CNWMessage::WriteBitsunsigned long long int, int
extern void * const CNWMessage__WriteBits;
// public void CNWMessage::WriteBOOLint
extern void * const CNWMessage__WriteBOOL;
// public void CNWMessage::WriteBYTEunsigned char, int
extern void * const CNWMessage__WriteBYTE;
// public void CNWMessage::WriteCExoStringCExoString, int
extern void * const CNWMessage__WriteCExoString;
// public void CNWMessage::WriteCHARchar, int
extern void * const CNWMessage__WriteCHAR;
// public void CNWMessage::WriteCResRefCResRef, int
extern void * const CNWMessage__WriteCResRef;
// void CNWMessage::WriteDOUBLEdouble, double, double, int
extern void * const CNWMessage__WriteDOUBLE__0;
// void CNWMessage::WriteDOUBLEdouble, double, int
extern void * const CNWMessage__WriteDOUBLE__1;
// public void CNWMessage::WriteDWORDunsigned long int, int
extern void * const CNWMessage__WriteDWORD;
// void CNWMessage::WriteDWORD64unsigned long long int, int
extern void * const CNWMessage__WriteDWORD64;
// public void CNWMessage::WriteFLOATfloat, float, float, int
extern void * const CNWMessage__WriteFLOAT__0;
// public void CNWMessage::WriteFLOATfloat, float, int
extern void * const CNWMessage__WriteFLOAT__1;
// public void CNWMessage::WriteINTint, int
extern void * const CNWMessage__WriteINT;
// void CNWMessage::WriteINT64long long, int
extern void * const CNWMessage__WriteINT64;
// public void CNWMessage::WriteSHORTshort int, int
extern void * const CNWMessage__WriteSHORT;
// void CNWMessage::WriteSignedlong long, int
extern void * const CNWMessage__WriteSigned;
// protected void CNWMessage::WriteUnsignedunsigned long long int, int
extern void * const CNWMessage__WriteUnsigned;
// public void CNWMessage::WriteVOIDPtrvoid*, int
extern void * const CNWMessage__WriteVOIDPtr;
// public void CNWMessage::WriteWORDunsigned short int, int
extern void * const CNWMessage__WriteWORD;

// public CNWNameGen::CNWNameGenvoid
extern void * const CNWNameGen__CNWNameGenCtor;
// public CNWNameGen::~CNWNameGenvoid
extern void * const CNWNameGen__CNWNameGenDtor;
// public CExoString CNWNameGen::GetRandomNamevoid
extern void * const CNWNameGen__GetRandomName__0;
// public CExoString CNWNameGen::GetRandomNameunsigned short int, unsigned char
extern void * const CNWNameGen__GetRandomName__1;
// public int CNWNameGen::LoadNameTableCExoString
extern void * const CNWNameGen__LoadNameTable;
// public void CNWNameGen::UnloadNameTablevoid
extern void * const CNWNameGen__UnloadNameTable;

// public CNWPlaceableSurfaceMesh::CNWPlaceableSurfaceMeshvoid
extern void * const CNWPlaceableSurfaceMesh__CNWPlaceableSurfaceMeshCtor;
// public CNWPlaceableSurfaceMesh::~CNWPlaceableSurfaceMeshvoid
extern void * const CNWPlaceableSurfaceMesh__CNWPlaceableSurfaceMeshDtor;
// public int CNWPlaceableSurfaceMesh::LoadWalkMeshCResRef
extern void * const CNWPlaceableSurfaceMesh__LoadWalkMesh;
// void CNWPlaceableSurfaceMesh::LoadWalkMeshStringunsigned char**, unsigned long int*, unsigned char*, unsigned long int
extern void * const CNWPlaceableSurfaceMesh__LoadWalkMeshString;

// public CNWPlaceMeshManager::CNWPlaceMeshManagervoid
extern void * const CNWPlaceMeshManager__CNWPlaceMeshManagerCtor;
// public CNWPlaceMeshManager::~CNWPlaceMeshManagervoid
extern void * const CNWPlaceMeshManager__CNWPlaceMeshManagerDtor;
// public void CNWPlaceMeshManager::ClearWalkMeshesvoid
extern void * const CNWPlaceMeshManager__ClearWalkMeshes;
// public CNWPlaceableSurfaceMesh* CNWPlaceMeshManager::GetWalkMeshint
extern void * const CNWPlaceMeshManager__GetWalkMesh;
// void CNWPlaceMeshManager::InitializeWalkMeshesint
extern void * const CNWPlaceMeshManager__InitializeWalkMeshes;

// public CNWRace::CNWRacevoid
extern void * const CNWRace__CNWRaceCtor;
// public CNWRace::~CNWRacevoid
extern void * const CNWRace__CNWRaceDtor;
// void CNWRace::GetConverNameLowerTextvoid
extern void * const CNWRace__GetConverNameLowerText;
// void CNWRace::GetConverNameTextvoid
extern void * const CNWRace__GetConverNameText;
// void CNWRace::GetDefaultBiographyTextvoid
extern void * const CNWRace__GetDefaultBiographyText;
// void CNWRace::GetDescriptionTextvoid
extern void * const CNWRace__GetDescriptionText;
// void CNWRace::GetNamePluralTextvoid
extern void * const CNWRace__GetNamePluralText;
// void CNWRace::GetNameTextvoid
extern void * const CNWRace__GetNameText;
// public int CNWRace::IsFirstLevelGrantedFeatunsigned short int
extern void * const CNWRace__IsFirstLevelGrantedFeat;
// public void CNWRace::LoadFeatsTableCExoString
extern void * const CNWRace__LoadFeatsTable;

// public CNWRules::CNWRulesvoid
extern void * const CNWRules__CNWRulesCtor;
// public CNWRules::~CNWRulesvoid
extern void * const CNWRules__CNWRulesDtor;
// protected int CNWRules::CompareFeatNameconst void*, const void*
extern void * const CNWRules__CompareFeatName;
// public CTwoDimArrays* CNWRules::Get2DArraysvoid
extern void * const CNWRules__Get2DArrays;
// void CNWRules::GetBaseItemunsigned long int
extern void * const CNWRules__GetBaseItem;
// void CNWRules::GetClassunsigned char
extern void * const CNWRules__GetClass;
// public unsigned char CNWRules::GetClassExpansionLevelunsigned char
extern void * const CNWRules__GetClassExpansionLevel;
// public int CNWRules::GetDamageIndexFromFlagsunsigned long int
extern void * const CNWRules__GetDamageIndexFromFlags;
// public int CNWRules::GetDifficultyOptionint, int
extern void * const CNWRules__GetDifficultyOption;
// public CNWDomain* CNWRules::GetDomainunsigned short int
extern void * const CNWRules__GetDomain;
// void CNWRules::GetExperienceLevelunsigned char
extern void * const CNWRules__GetExperienceLevel;
// public unsigned char CNWRules::GetFamiliarExpansionLevelunsigned char, int
extern void * const CNWRules__GetFamiliarExpansionLevel;
// public CNWFeat* CNWRules::GetFeatunsigned short int
extern void * const CNWRules__GetFeat;
// public unsigned char CNWRules::GetFeatExpansionLevelunsigned short int
extern void * const CNWRules__GetFeatExpansionLevel;
// void CNWRules::GetIsClassValidunsigned char
extern void * const CNWRules__GetIsClassValid;
// void CNWRules::GetMasterFeatDescriptionTextchar
extern void * const CNWRules__GetMasterFeatDescriptionText;
// void CNWRules::GetMasterFeatIconchar
extern void * const CNWRules__GetMasterFeatIcon;
// public CExoString CNWRules::GetMasterFeatNameTextchar
extern void * const CNWRules__GetMasterFeatNameText;
// public unsigned char CNWRules::GetMetaMagicLevelCostunsigned char
extern void * const CNWRules__GetMetaMagicLevelCost;
// void CNWRules::GetNumClassesvoid
extern void * const CNWRules__GetNumClasses;
// void CNWRules::GetNumDomainsvoid
extern void * const CNWRules__GetNumDomains;
// void CNWRules::GetNumFeatsvoid
extern void * const CNWRules__GetNumFeats;
// void CNWRules::GetNumRacesvoid
extern void * const CNWRules__GetNumRaces;
// void CNWRules::GetNumSkillsvoid
extern void * const CNWRules__GetNumSkills;
// void CNWRules::GetNumSortedFeatsvoid
extern void * const CNWRules__GetNumSortedFeats;
// void CNWRules::GetNumSpellsvoid
extern void * const CNWRules__GetNumSpells;
// void CNWRules::GetRaceunsigned short int
extern void * const CNWRules__GetRace;
// void CNWRules::GetSkillunsigned short int
extern void * const CNWRules__GetSkill;
// public unsigned char CNWRules::GetSkillExpansionLevelunsigned short int
extern void * const CNWRules__GetSkillExpansionLevel;
// void CNWRules::GetSortedFeatIDunsigned short int
extern void * const CNWRules__GetSortedFeatID;
// void CNWRules::GetSpellunsigned long int
extern void * const CNWRules__GetSpell;
// public unsigned char CNWRules::GetSpellExpansionLevelunsigned long int
extern void * const CNWRules__GetSpellExpansionLevel;
// void CNWRules::GetSpellRangeint
extern void * const CNWRules__GetSpellRange;
// public int CNWRules::GetWeightedDamageAmountint, int, int, int, int
extern void * const CNWRules__GetWeightedDamageAmount;
// public int CNWRules::IsArcaneClassunsigned char
extern void * const CNWRules__IsArcaneClass;
// void CNWRules::IsFeatUseableunsigned char, unsigned short int
extern void * const CNWRules__IsFeatUseable;
// protected void CNWRules::LoadClassInfovoid
extern void * const CNWRules__LoadClassInfo;
// protected void CNWRules::LoadDifficultyInfovoid
extern void * const CNWRules__LoadDifficultyInfo;
// protected void CNWRules::LoadDomainInfovoid
extern void * const CNWRules__LoadDomainInfo;
// protected void CNWRules::LoadFeatInfovoid
extern void * const CNWRules__LoadFeatInfo;
// protected void CNWRules::LoadRaceInfovoid
extern void * const CNWRules__LoadRaceInfo;
// protected void CNWRules::LoadSkillInfovoid
extern void * const CNWRules__LoadSkillInfo;
// public void CNWRules::ReloadAllvoid
extern void * const CNWRules__ReloadAll;
// public unsigned short int CNWRules::RollDiceunsigned char, unsigned char
extern void * const CNWRules__RollDice;
// void CNWRules::SortFeatsvoid
extern void * const CNWRules__SortFeats;
// public void CNWRules::UnloadAllvoid
extern void * const CNWRules__UnloadAll;

// public CNWSAmbientSound::CNWSAmbientSoundunsigned long int
extern void * const CNWSAmbientSound__CNWSAmbientSoundCtor;
// CNWSAmbientSound::~CNWSAmbientSoundvoid
extern void * const CNWSAmbientSound__CNWSAmbientSoundDtor;
// private int CNWSAmbientSound::GetPlayersInAreaCExoArrayListTemplatedunsignedlong*
extern void * const CNWSAmbientSound__GetPlayersInArea;
// public int CNWSAmbientSound::LoadCResGFF*, CResStruct*
extern void * const CNWSAmbientSound__Load;
// public void CNWSAmbientSound::PackIntoMessageCNWSMessage*
extern void * const CNWSAmbientSound__PackIntoMessage;
// public void CNWSAmbientSound::PlayAmbientSoundint
extern void * const CNWSAmbientSound__PlayAmbientSound;
// public void CNWSAmbientSound::PlayBattleMusicint
extern void * const CNWSAmbientSound__PlayBattleMusic;
// public void CNWSAmbientSound::PlayMusicint
extern void * const CNWSAmbientSound__PlayMusic;
// public void CNWSAmbientSound::SaveCResGFF*, CResStruct*
extern void * const CNWSAmbientSound__Save;
// public void CNWSAmbientSound::SetAmbientDayTrackint
extern void * const CNWSAmbientSound__SetAmbientDayTrack;
// public void CNWSAmbientSound::SetAmbientDayVolumeint
extern void * const CNWSAmbientSound__SetAmbientDayVolume;
// public void CNWSAmbientSound::SetAmbientNightTrackint
extern void * const CNWSAmbientSound__SetAmbientNightTrack;
// public void CNWSAmbientSound::SetAmbientNightVolumeint
extern void * const CNWSAmbientSound__SetAmbientNightVolume;
// public void CNWSAmbientSound::SetBattleMusicTrackint
extern void * const CNWSAmbientSound__SetBattleMusicTrack;
// public void CNWSAmbientSound::SetMusicDayTrackint
extern void * const CNWSAmbientSound__SetMusicDayTrack;
// public void CNWSAmbientSound::SetMusicDelayint
extern void * const CNWSAmbientSound__SetMusicDelay;
// public void CNWSAmbientSound::SetMusicNightTrackint
extern void * const CNWSAmbientSound__SetMusicNightTrack;

// public CNWSArea::CNWSAreaCResRef, int, unsigned long int
extern void * const CNWSArea__CNWSAreaCtor;
// public CNWSArea::~CNWSAreavoid
extern void * const CNWSArea__CNWSAreaDtor;
// public int CNWSArea::AddObjectToAreaunsigned long int, int
extern void * const CNWSArea__AddObjectToArea;
// void CNWSArea::AddSubAreaCGameObject*
extern void * const CNWSArea__AddSubArea;
// public int CNWSArea::AIUpdatevoid
extern void * const CNWSArea__AIUpdate;
// public void CNWSArea::ApplyEffectCGameEffect*, Vector, Vector
extern void * const CNWSArea__ApplyEffect;
// public CNWSArea* CNWSArea::AsNWSAreavoid
extern void * const CNWSArea__AsNWSArea;
// public void CNWSArea::BudgeCreaturesconst Vector&, const Vector&, const Vector&, unsigned long int, int
extern void * const CNWSArea__BudgeCreatures;
// public int CNWSArea::ClearLineOfSightVector, Vector, Vector*, unsigned long int*, unsigned long int, unsigned long int, int
extern void * const CNWSArea__ClearLineOfSight;
// public Vector CNWSArea::ComputeAwayVectorVector, Vector, float, CPathfindInformation*
extern void * const CNWSArea__ComputeAwayVector;
// public int CNWSArea::ComputeBestCornerfloat, float, float, float, float, float, float, float, float*, float*, float*, float*
extern void * const CNWSArea__ComputeBestCorner;
// public float CNWSArea::ComputeHeightVector
extern void * const CNWSArea__ComputeHeight;
// public int CNWSArea::ComputeNonVisibleLocationVector, CPathfindInformation*, int, Vector*, float
extern void * const CNWSArea__ComputeNonVisibleLocation;
// void CNWSArea::ComputePathDistanceint, float*
extern void * const CNWSArea__ComputePathDistance;
// public int CNWSArea::ComputeSafeLocationVector, float, CPathfindInformation*, int, Vector*
extern void * const CNWSArea__ComputeSafeLocation;
// public int CNWSArea::ComputeSafeLocationInDirectionVector, Vector, float, CPathfindInformation*, int, Vector*
extern void * const CNWSArea__ComputeSafeLocationInDirection;
// public int CNWSArea::CountAreaTransitionTriggersunsigned long int*, int, unsigned long int*
extern void * const CNWSArea__CountAreaTransitionTriggers;
// public int CNWSArea::CountVisibleToPlayersVector, int
extern void * const CNWSArea__CountVisibleToPlayers;
// protected void CNWSArea::DecreaseAILevelPriorityvoid
extern void * const CNWSArea__DecreaseAILevelPriority;
// public void CNWSArea::DecrementPlayersInAreavoid
extern void * const CNWSArea__DecrementPlayersInArea;
// public int CNWSArea::EvaluateOverlappingTargetsCPathfindInformation*, Vector, unsigned long int, float, float, float, int, int, unsigned long int*
extern void * const CNWSArea__EvaluateOverlappingTargets;
// public void CNWSArea::EventHandlerunsigned long int, unsigned long int, void*, unsigned long int, unsigned long int
extern void * const CNWSArea__EventHandler;
// public int CNWSArea::ExploreAreaCNWSCreature*, int, int, int
extern void * const CNWSArea__ExploreArea;
// public int CNWSArea::GenerateInterTilePathint*, int, int, int
extern void * const CNWSArea__GenerateInterTilePath;
// void CNWSArea::GetAmbientSoundvoid
extern void * const CNWSArea__GetAmbientSound;
// void CNWSArea::GetAreaListenCheckModifiervoid
extern void * const CNWSArea__GetAreaListenCheckModifier;
// void CNWSArea::GetAreaNamevoid
extern void * const CNWSArea__GetAreaName;
// void CNWSArea::GetAreaSpotCheckModifiervoid
extern void * const CNWSArea__GetAreaSpotCheckModifier;
// void CNWSArea::GetCurrentWeathervoid
extern void * const CNWSArea__GetCurrentWeather;
// void CNWSArea::GetCustomScriptEventIdvoid
extern void * const CNWSArea__GetCustomScriptEventId;
// public unsigned long int CNWSArea::GetDoorCrossedVector, Vector
extern void * const CNWSArea__GetDoorCrossed;
// public int CNWSArea::GetFirstObjectInAreaunsigned long int&
extern void * const CNWSArea__GetFirstObjectInArea;
// public int CNWSArea::GetFirstObjectIndiceByXint*, float
extern void * const CNWSArea__GetFirstObjectIndiceByX;
// void CNWSArea::GetGameObjectsArrayvoid
extern void * const CNWSArea__GetGameObjectsArray;
// void CNWSArea::GetInterAreaDFSVisitedvoid
extern void * const CNWSArea__GetInterAreaDFSVisited;
// public int CNWSArea::GetIsIDInExcludeListunsigned long int, CExoArrayListTemplatedCGameObjectPtr*
extern void * const CNWSArea__GetIsIDInExcludeList;
// void CNWSArea::GetLastEnteredvoid
extern void * const CNWSArea__GetLastEntered;
// void CNWSArea::GetLastLeftvoid
extern void * const CNWSArea__GetLastLeft;
// public unsigned short int CNWSArea::GetLoadScreenIDvoid
extern void * const CNWSArea__GetLoadScreenID;
// void CNWSArea::GetMapSizevoid
extern void * const CNWSArea__GetMapSize;
// public int CNWSArea::GetNextObjectInAreaunsigned long int&
extern void * const CNWSArea__GetNextObjectInArea;
// void CNWSArea::GetNumPlayersInAreavoid
extern void * const CNWSArea__GetNumPlayersInArea;
// void CNWSArea::GetObjectByNameIndexvoid
extern void * const CNWSArea__GetObjectByNameIndex;
// void CNWSArea::GetObjectsArrayPositionvoid
extern void * const CNWSArea__GetObjectsArrayPosition;
// void CNWSArea::GetOverrideWeathervoid
extern void * const CNWSArea__GetOverrideWeather;
// public unsigned char CNWSArea::GetPVPSettingvoid
extern void * const CNWSArea__GetPVPSetting;
// void CNWSArea::GetScriptNameint
extern void * const CNWSArea__GetScriptName;
// void CNWSArea::GetScriptVarTablevoid
extern void * const CNWSArea__GetScriptVarTable;
// void CNWSArea::GetSoundPathInformationvoid
extern void * const CNWSArea__GetSoundPathInformation;
// void CNWSArea::GetSurfaceMaterialVector
extern void * const CNWSArea__GetSurfaceMaterial;
// public CExoString CNWSArea::GetTagvoid
extern void * const CNWSArea__GetTag;
// public CNWSTile* CNWSArea::GetTileVector
extern void * const CNWSArea__GetTile__0;
// public CNWSTile* CNWSArea::GetTileint, int
extern void * const CNWSArea__GetTile__1;
// void CNWSArea::GetTileSetResRefvoid
extern void * const CNWSArea__GetTileSetResRef;
// void CNWSArea::GetTrapListvoid
extern void * const CNWSArea__GetTrapList;
// public int CNWSArea::GoalMoveDeniedint, int, int
extern void * const CNWSArea__GoalMoveDenied;
// public int CNWSArea::GridDFSearchint, int, int, int, int, int
extern void * const CNWSArea__GridDFSearch;
// public int CNWSArea::GridDFSGenerateSuccessorsint, int, int, int, int, CNWSAreaGridSuccessors**
extern void * const CNWSArea__GridDFSGenerateSuccessors;
// public int CNWSArea::GridDFSTransTableGetint, int, int*, int*
extern void * const CNWSArea__GridDFSTransTableGet;
// void CNWSArea::GridDFSTransTableHashint, int
extern void * const CNWSArea__GridDFSTransTableHash;
// void CNWSArea::GridDFSTransTableInitializevoid
extern void * const CNWSArea__GridDFSTransTableInitialize;
// public void CNWSArea::GridDFSTransTablePutint, int, int, int
extern void * const CNWSArea__GridDFSTransTablePut;
// public int CNWSArea::HandleTransparentDoorsfloat, float, float, float, float, float, float, unsigned long int, unsigned long int&, int, CExoArrayListTemplatedCGameObjectPtr*, int
extern void * const CNWSArea__HandleTransparentDoors;
// protected void CNWSArea::IncreaseAILevelPriorityvoid
extern void * const CNWSArea__IncreaseAILevelPriority;
// public void CNWSArea::IncrementPlayersInAreavoid
extern void * const CNWSArea__IncrementPlayersInArea;
// public int CNWSArea::InSubAreasVector, CExoArrayListTemplatedunsignedlong*
extern void * const CNWSArea__InSubAreas;
// public int CNWSArea::IntersectingLineSegmentVector, Vector, CExoArrayListTemplatedunsignedlong*
extern void * const CNWSArea__IntersectingLineSegment;
// public int CNWSArea::InterTileDFSint, int, int, int, int
extern void * const CNWSArea__InterTileDFS;
// public void CNWSArea::InterTileDFSExploreAreaunsigned char*, int, int, int, float, float
extern void * const CNWSArea__InterTileDFSExploreArea;
// public int CNWSArea::InterTileDFSGenerateSuccessorsint, int, int, int
extern void * const CNWSArea__InterTileDFSGenerateSuccessors;
// public int CNWSArea::InterTileDFSSoundPathunsigned char*, int, int, int, int
extern void * const CNWSArea__InterTileDFSSoundPath;
// public int CNWSArea::LoadAreaint
extern void * const CNWSArea__LoadArea;
// protected int CNWSArea::LoadAreaEffectsCResGFF*, CResStruct*, int
extern void * const CNWSArea__LoadAreaEffects;
// protected int CNWSArea::LoadAreaHeaderCResStruct*
extern void * const CNWSArea__LoadAreaHeader;
// protected int CNWSArea::LoadCreaturesCResGFF*, CResStruct*, int
extern void * const CNWSArea__LoadCreatures;
// protected int CNWSArea::LoadDoorsCResGFF*, CResStruct*, int
extern void * const CNWSArea__LoadDoors;
// protected int CNWSArea::LoadEncountersCResGFF*, CResStruct*, int
extern void * const CNWSArea__LoadEncounters;
// protected int CNWSArea::LoadGITint
extern void * const CNWSArea__LoadGIT;
// protected int CNWSArea::LoadItemsCResGFF*, CResStruct*, int
extern void * const CNWSArea__LoadItems;
// protected int CNWSArea::LoadPlaceablesCResGFF*, CResStruct*, int
extern void * const CNWSArea__LoadPlaceables;
// void CNWSArea::LoadPlayersCResGFF*, CResStruct*
extern void * const CNWSArea__LoadPlayers;
// protected int CNWSArea::LoadPropertiesCResGFF*, CResStruct*
extern void * const CNWSArea__LoadProperties;
// protected int CNWSArea::LoadSoundsCResGFF*, CResStruct*, int
extern void * const CNWSArea__LoadSounds;
// protected int CNWSArea::LoadStoresCResGFF*, CResStruct*, int
extern void * const CNWSArea__LoadStores;
// protected int CNWSArea::LoadTileSetInfoCResStruct*
extern void * const CNWSArea__LoadTileSetInfo;
// protected int CNWSArea::LoadTriggersCResGFF*, CResStruct*, int
extern void * const CNWSArea__LoadTriggers;
// protected int CNWSArea::LoadWaypointsCResGFF*, CResStruct*, int
extern void * const CNWSArea__LoadWaypoints;
// public int CNWSArea::NoCreaturesOnLinefloat, float, float, float, CPathfindInformation*, int, int, unsigned long int*, int
extern void * const CNWSArea__NoCreaturesOnLine;
// public int CNWSArea::NoNoneWalkPolysInStaticObjectunsigned long int, float, float, float, float, float, float, float, unsigned long int, int
extern void * const CNWSArea__NoNoneWalkPolysInStaticObject;
// public CNWSArea* CNWSArea::NWAreaAsNWSAreavoid
extern void * const CNWSArea__NWAreaAsNWSArea;
// public int CNWSArea::PackAreaIntoMessageint, int, int, CNWSPlayer*
extern void * const CNWSArea__PackAreaIntoMessage;
// public void CNWSArea::PlayVisualEffectunsigned short int, Vector
extern void * const CNWSArea__PlayVisualEffect;
// public unsigned long int CNWSArea::PlotGridPathCPathfindInformation*, unsigned long long int
extern void * const CNWSArea__PlotGridPath;
// public unsigned long int CNWSArea::PlotPathCPathfindInformation*, unsigned long long int
extern void * const CNWSArea__PlotPath;
// public int CNWSArea::PlotSoundPathCPathfindInformation*
extern void * const CNWSArea__PlotSoundPath;
// public int CNWSArea::PositionWalkableVector
extern void * const CNWSArea__PositionWalkable;
// public int CNWSArea::RemoveInterTileExitint, int, int, int
extern void * const CNWSArea__RemoveInterTileExit;
// public int CNWSArea::RemoveObjectFromAreaunsigned long int
extern void * const CNWSArea__RemoveObjectFromArea;
// void CNWSArea::RemoveSubAreaCGameObject*
extern void * const CNWSArea__RemoveSubArea;
// void CNWSArea::SaveAreaCERFFile*, CExoString&
extern void * const CNWSArea__SaveArea;
// protected void CNWSArea::SaveAreaEffectsCResGFF*, CResStruct*, CExoArrayListTemplatedunsignedlong&
extern void * const CNWSArea__SaveAreaEffects;
// protected void CNWSArea::SaveCreaturesCResGFF*, CResStruct*, CExoArrayListTemplatedunsignedlong&
extern void * const CNWSArea__SaveCreatures;
// protected void CNWSArea::SaveDoorsCResGFF*, CResStruct*, CExoArrayListTemplatedunsignedlong&
extern void * const CNWSArea__SaveDoors;
// protected void CNWSArea::SaveEncountersCResGFF*, CResStruct*, CExoArrayListTemplatedunsignedlong&
extern void * const CNWSArea__SaveEncounters;
// public void CNWSArea::SaveGITCERFFile*, CExoString&, CExoArrayListTemplatedunsignedlong&
extern void * const CNWSArea__SaveGIT;
// protected void CNWSArea::SaveItemsCResGFF*, CResStruct*, CExoArrayListTemplatedunsignedlong&
extern void * const CNWSArea__SaveItems;
// protected void CNWSArea::SavePlaceablesCResGFF*, CResStruct*, CExoArrayListTemplatedunsignedlong&
extern void * const CNWSArea__SavePlaceables;
// void CNWSArea::SavePropertiesCResGFF*, CResStruct*
extern void * const CNWSArea__SaveProperties;
// protected void CNWSArea::SaveSoundsCResGFF*, CResStruct*, CExoArrayListTemplatedunsignedlong&
extern void * const CNWSArea__SaveSounds;
// protected void CNWSArea::SaveStoresCResGFF*, CResStruct*, CExoArrayListTemplatedunsignedlong&
extern void * const CNWSArea__SaveStores;
// protected void CNWSArea::SaveTriggersCResGFF*, CResStruct*, CExoArrayListTemplatedunsignedlong&
extern void * const CNWSArea__SaveTriggers;
// protected void CNWSArea::SaveWaypointsCResGFF*, CResStruct*, CExoArrayListTemplatedunsignedlong&
extern void * const CNWSArea__SaveWaypoints;
// public void CNWSArea::SetCurrentWeatherunsigned char, int
extern void * const CNWSArea__SetCurrentWeather;
// void CNWSArea::SetCustomScriptEventIdint
extern void * const CNWSArea__SetCustomScriptEventId;
// void CNWSArea::SetInterAreaDFSVisitedint
extern void * const CNWSArea__SetInterAreaDFSVisited;
// void CNWSArea::SetLastEnteredunsigned long int
extern void * const CNWSArea__SetLastEntered;
// void CNWSArea::SetLastLeftunsigned long int
extern void * const CNWSArea__SetLastLeft;
// void CNWSArea::SetMapSizeunsigned char
extern void * const CNWSArea__SetMapSize;
// void CNWSArea::SetObjectByNameIndexint
extern void * const CNWSArea__SetObjectByNameIndex;
// void CNWSArea::SetObjectsArrayPositionint
extern void * const CNWSArea__SetObjectsArrayPosition;
// void CNWSArea::SetOverrideWeatherunsigned char
extern void * const CNWSArea__SetOverrideWeather;
// void CNWSArea::SetPVPSettingunsigned char
extern void * const CNWSArea__SetPVPSetting;
// public void CNWSArea::SetScriptNameint, CExoString
extern void * const CNWSArea__SetScriptName;
// void CNWSArea::SetSearchInfoCPathfindInformation*
extern void * const CNWSArea__SetSearchInfo;
// void CNWSArea::SetTagCExoString
extern void * const CNWSArea__SetTag;
// public void CNWSArea::SmoothCornerOptimizeint, float*, int*, float**
extern void * const CNWSArea__SmoothCornerOptimize;
// public int CNWSArea::SmoothPointsOnPathvoid
extern void * const CNWSArea__SmoothPointsOnPath;
// void CNWSArea::SmoothSelectionint, float*, int*, float**
extern void * const CNWSArea__SmoothSelection;
// public void CNWSArea::SmoothSelectNodesint, float*, int*, float**, int, int
extern void * const CNWSArea__SmoothSelectNodes;
// public int CNWSArea::TestDirectLinefloat, float, float, float, float, float, int
extern void * const CNWSArea__TestDirectLine;
// public int CNWSArea::TestLineWalkablefloat, float, float, float, float
extern void * const CNWSArea__TestLineWalkable;
// public int CNWSArea::TestSafeLocationPointVector, CPathfindInformation*
extern void * const CNWSArea__TestSafeLocationPoint;
// public void CNWSArea::UnloadAreavoid
extern void * const CNWSArea__UnloadArea;
// public void CNWSArea::UpdatePlayerAutomapsvoid
extern void * const CNWSArea__UpdatePlayerAutomaps;
// public int CNWSArea::UpdatePositionInObjectsArrayCGameObject*
extern void * const CNWSArea__UpdatePositionInObjectsArray;

// public CNWSAreaOfEffectObject::CNWSAreaOfEffectObjectunsigned long int
extern void * const CNWSAreaOfEffectObject__CNWSAreaOfEffectObjectCtor;
// public CNWSAreaOfEffectObject::~CNWSAreaOfEffectObjectvoid
extern void * const CNWSAreaOfEffectObject__CNWSAreaOfEffectObjectDtor;
// public void CNWSAreaOfEffectObject::AddToAreaCNWSArea*, float, float, float, int
extern void * const CNWSAreaOfEffectObject__AddToArea;
// public void CNWSAreaOfEffectObject::AIUpdatevoid
extern void * const CNWSAreaOfEffectObject__AIUpdate;
// public CNWSAreaOfEffectObject* CNWSAreaOfEffectObject::AsNWSAreaOfEffectObjectvoid
extern void * const CNWSAreaOfEffectObject__AsNWSAreaOfEffectObject;
// public void CNWSAreaOfEffectObject::EventHandlerunsigned long int, unsigned long int, void*, unsigned long int, unsigned long int
extern void * const CNWSAreaOfEffectObject__EventHandler;
// void CNWSAreaOfEffectObject::GetAreaEffectIdvoid
extern void * const CNWSAreaOfEffectObject__GetAreaEffectId;
// void CNWSAreaOfEffectObject::GetCreatorvoid
extern void * const CNWSAreaOfEffectObject__GetCreator;
// public unsigned long int CNWSAreaOfEffectObject::GetEffectSpellIdvoid
extern void * const CNWSAreaOfEffectObject__GetEffectSpellId;
// void CNWSAreaOfEffectObject::GetLastEnteredvoid
extern void * const CNWSAreaOfEffectObject__GetLastEntered;
// void CNWSAreaOfEffectObject::GetLastLeftvoid
extern void * const CNWSAreaOfEffectObject__GetLastLeft;
// void CNWSAreaOfEffectObject::GetObjectArrayIndexvoid
extern void * const CNWSAreaOfEffectObject__GetObjectArrayIndex;
// public Vector CNWSAreaOfEffectObject::GetPositionvoid
extern void * const CNWSAreaOfEffectObject__GetPosition;
// void CNWSAreaOfEffectObject::GetRadiusvoid
extern void * const CNWSAreaOfEffectObject__GetRadius;
// void CNWSAreaOfEffectObject::GetScriptNameint
extern void * const CNWSAreaOfEffectObject__GetScriptName;
// void CNWSAreaOfEffectObject::GetShapevoid
extern void * const CNWSAreaOfEffectObject__GetShape;
// void CNWSAreaOfEffectObject::GetSpellLevelvoid
extern void * const CNWSAreaOfEffectObject__GetSpellLevel;
// void CNWSAreaOfEffectObject::GetSpellSaveDCvoid
extern void * const CNWSAreaOfEffectObject__GetSpellSaveDC;
// void CNWSAreaOfEffectObject::GetTargetObjIDvoid
extern void * const CNWSAreaOfEffectObject__GetTargetObjID;
// public int CNWSAreaOfEffectObject::InAreaOfEffectVector
extern void * const CNWSAreaOfEffectObject__InAreaOfEffect;
// public void CNWSAreaOfEffectObject::JumpToPointCNWSArea*, const Vector&
extern void * const CNWSAreaOfEffectObject__JumpToPoint;
// public int CNWSAreaOfEffectObject::LineSegmentIntersectAreaOfEffectVector, Vector
extern void * const CNWSAreaOfEffectObject__LineSegmentIntersectAreaOfEffect;
// public void CNWSAreaOfEffectObject::LoadAreaEffectint
extern void * const CNWSAreaOfEffectObject__LoadAreaEffect;
// public int CNWSAreaOfEffectObject::LoadEffectCResGFF*, CResStruct*
extern void * const CNWSAreaOfEffectObject__LoadEffect;
// public void CNWSAreaOfEffectObject::RemoveFromAreavoid
extern void * const CNWSAreaOfEffectObject__RemoveFromArea;
// protected void CNWSAreaOfEffectObject::RemoveFromSubAreasint
extern void * const CNWSAreaOfEffectObject__RemoveFromSubAreas;
// public int CNWSAreaOfEffectObject::SaveEffectCResGFF*, CResStruct*
extern void * const CNWSAreaOfEffectObject__SaveEffect;
// public void CNWSAreaOfEffectObject::SetCreatorunsigned long int
extern void * const CNWSAreaOfEffectObject__SetCreator;
// public void CNWSAreaOfEffectObject::SetDurationunsigned char, float
extern void * const CNWSAreaOfEffectObject__SetDuration;
// public void CNWSAreaOfEffectObject::SetEffectSpellIdunsigned long int
extern void * const CNWSAreaOfEffectObject__SetEffectSpellId;
// void CNWSAreaOfEffectObject::SetLastEnteredunsigned long int
extern void * const CNWSAreaOfEffectObject__SetLastEntered;
// void CNWSAreaOfEffectObject::SetLastLeftunsigned long int
extern void * const CNWSAreaOfEffectObject__SetLastLeft;
// void CNWSAreaOfEffectObject::SetObjectArrayIndexunsigned short int
extern void * const CNWSAreaOfEffectObject__SetObjectArrayIndex;
// public void CNWSAreaOfEffectObject::SetScriptNameint, CExoString
extern void * const CNWSAreaOfEffectObject__SetScriptName;
// void CNWSAreaOfEffectObject::SetShapeunsigned char, float, float
extern void * const CNWSAreaOfEffectObject__SetShape;
// public void CNWSAreaOfEffectObject::SetTargetObjIDunsigned long int
extern void * const CNWSAreaOfEffectObject__SetTargetObjID;
// protected void CNWSAreaOfEffectObject::UpdateSubAreasVector*
extern void * const CNWSAreaOfEffectObject__UpdateSubAreas;

// public CNWSBarter::CNWSBarterCNWSCreature*
extern void * const CNWSBarter__CNWSBarterCtor;
// public CNWSBarter::~CNWSBartervoid
extern void * const CNWSBarter__CNWSBarterDtor;
// public int CNWSBarter::AddItemunsigned long int, unsigned char&, unsigned char&
extern void * const CNWSBarter__AddItem;
// public void CNWSBarter::CleanUpvoid
extern void * const CNWSBarter__CleanUp;
// public unsigned char CNWSBarter::GetStatevoid
extern void * const CNWSBarter__GetState;
// public int CNWSBarter::MoveItemunsigned long int, unsigned char&, unsigned char&
extern void * const CNWSBarter__MoveItem;
// public int CNWSBarter::PullItemOutunsigned long int
extern void * const CNWSBarter__PullItemOut;
// public int CNWSBarter::RemoveItemunsigned long int, unsigned char&, unsigned char&
extern void * const CNWSBarter__RemoveItem;
// public void CNWSBarter::Resetunsigned long int, int
extern void * const CNWSBarter__Reset;
// public int CNWSBarter::SetListAcceptedint
extern void * const CNWSBarter__SetListAccepted;
// public int CNWSBarter::SetListLockedint
extern void * const CNWSBarter__SetListLocked;

// public CNWSClient::CNWSClientunsigned long int
extern void * const CNWSClient__CNWSClientCtor;
// public CNWSClient::~CNWSClientvoid
extern void * const CNWSClient__CNWSClientDtor;
// public CNWSDungeonMaster* CNWSClient::AsNWSDungeonMastervoid
extern void * const CNWSClient__AsNWSDungeonMaster;
// public CNWSPlayer* CNWSClient::AsNWSPlayervoid
extern void * const CNWSClient__AsNWSPlayer;
// void CNWSClient::GetLanguagevoid
extern void * const CNWSClient__GetLanguage;
// public unsigned long int CNWSClient::GetPlayerIdvoid
extern void * const CNWSClient__GetPlayerId;
// void CNWSClient::SetLanguageint
extern void * const CNWSClient__SetLanguage;

// public CNWSCombatAttackData::CNWSCombatAttackDatavoid
extern void * const CNWSCombatAttackData__CNWSCombatAttackDataCtor;
// public CNWSCombatAttackData::~CNWSCombatAttackDatavoid
extern void * const CNWSCombatAttackData__CNWSCombatAttackDataDtor;
// public void CNWSCombatAttackData::AddDamageunsigned short int, int
extern void * const CNWSCombatAttackData__AddDamage;
// public void CNWSCombatAttackData::ClearAttackDatavoid
extern void * const CNWSCombatAttackData__ClearAttackData;
// public void CNWSCombatAttackData::CopyCNWSCombatAttackData*, int
extern void * const CNWSCombatAttackData__Copy;
// public int CNWSCombatAttackData::GetDamageunsigned short int
extern void * const CNWSCombatAttackData__GetDamage;
// public int CNWSCombatAttackData::GetTotalDamageint
extern void * const CNWSCombatAttackData__GetTotalDamage;
// public int CNWSCombatAttackData::LoadDataCResGFF*, CResStruct*
extern void * const CNWSCombatAttackData__LoadData;
// public int CNWSCombatAttackData::SaveDataCResGFF*, CResStruct*
extern void * const CNWSCombatAttackData__SaveData;
// public void CNWSCombatAttackData::SetBaseDamageint
extern void * const CNWSCombatAttackData__SetBaseDamage;
// void CNWSCombatAttackData::SetDamageunsigned short int, int
extern void * const CNWSCombatAttackData__SetDamage;

// public CNWSCombatRound::CNWSCombatRoundCNWSCreature*
extern void * const CNWSCombatRound__CNWSCombatRoundCtor;
// public CNWSCombatRound::~CNWSCombatRoundvoid
extern void * const CNWSCombatRound__CNWSCombatRoundDtor;
// void CNWSCombatRound::AddActionCNWSCombatRoundAction*
extern void * const CNWSCombatRound__AddAction;
// public void CNWSCombatRound::AddAttackOfOpportunityunsigned long int
extern void * const CNWSCombatRound__AddAttackOfOpportunity;
// public void CNWSCombatRound::AddCircleKickAttackunsigned long int
extern void * const CNWSCombatRound__AddCircleKickAttack;
// public void CNWSCombatRound::AddCleaveAttackunsigned long int, int
extern void * const CNWSCombatRound__AddCleaveAttack;
// public void CNWSCombatRound::AddCombatStepActionunsigned long int, unsigned long int
extern void * const CNWSCombatRound__AddCombatStepAction;
// public void CNWSCombatRound::AddEquipActionunsigned long int, unsigned long int
extern void * const CNWSCombatRound__AddEquipAction;
// public void CNWSCombatRound::AddParryAttackunsigned long int
extern void * const CNWSCombatRound__AddParryAttack;
// public void CNWSCombatRound::AddParryIndexvoid
extern void * const CNWSCombatRound__AddParryIndex;
// public void CNWSCombatRound::AddReactionint, int
extern void * const CNWSCombatRound__AddReaction;
// public void CNWSCombatRound::AddSpecialAttackunsigned short int
extern void * const CNWSCombatRound__AddSpecialAttack;
// public void CNWSCombatRound::AddSpellActionvoid
extern void * const CNWSCombatRound__AddSpellAction;
// public void CNWSCombatRound::AddUnequipActionunsigned long int, unsigned long int, unsigned char, unsigned char
extern void * const CNWSCombatRound__AddUnequipAction;
// public void CNWSCombatRound::AddWhirlwindAttackunsigned long int, int
extern void * const CNWSCombatRound__AddWhirlwindAttack;
// public int CNWSCombatRound::CalculateOffHandAttacksvoid
extern void * const CNWSCombatRound__CalculateOffHandAttacks;
// public int CNWSCombatRound::CheckActionLengthunsigned long int, int
extern void * const CNWSCombatRound__CheckActionLength;
// public int CNWSCombatRound::CheckActionLengthAtTimeunsigned long int, int, int
extern void * const CNWSCombatRound__CheckActionLengthAtTime;
// public void CNWSCombatRound::ClearAllAttacksvoid
extern void * const CNWSCombatRound__ClearAllAttacks;
// public void CNWSCombatRound::ClearAllSpecialAttacksvoid
extern void * const CNWSCombatRound__ClearAllSpecialAttacks;
// public void CNWSCombatRound::DecrementPauseTimerint
extern void * const CNWSCombatRound__DecrementPauseTimer;
// public void CNWSCombatRound::DecrementRoundLengthint, int
extern void * const CNWSCombatRound__DecrementRoundLength;
// public void CNWSCombatRound::EndCombatRoundvoid
extern void * const CNWSCombatRound__EndCombatRound;
// public CNWSCombatRoundAction* CNWSCombatRound::GetActionvoid
extern void * const CNWSCombatRound__GetAction;
// public int CNWSCombatRound::GetActionPendingvoid
extern void * const CNWSCombatRound__GetActionPending;
// public CNWSCombatAttackData* CNWSCombatRound::GetAttackint
extern void * const CNWSCombatRound__GetAttack;
// void CNWSCombatRound::GetAttackActionPendingvoid
extern void * const CNWSCombatRound__GetAttackActionPending;
// public int CNWSCombatRound::GetCombatStepRequiredunsigned long int
extern void * const CNWSCombatRound__GetCombatStepRequired;
// public CNWSItem* CNWSCombatRound::GetCurrentAttackWeaponint
extern void * const CNWSCombatRound__GetCurrentAttackWeapon;
// void CNWSCombatRound::GetExtraAttackvoid
extern void * const CNWSCombatRound__GetExtraAttack;
// public unsigned short int CNWSCombatRound::GetNewAttackIDvoid
extern void * const CNWSCombatRound__GetNewAttackID;
// public int CNWSCombatRound::GetNumSpecialAttacksvoid
extern void * const CNWSCombatRound__GetNumSpecialAttacks;
// public int CNWSCombatRound::GetOffHandAttackvoid
extern void * const CNWSCombatRound__GetOffHandAttack;
// public unsigned short int CNWSCombatRound::GetSpecialAttackint
extern void * const CNWSCombatRound__GetSpecialAttack;
// public unsigned short int CNWSCombatRound::GetSpecialAttackIDint
extern void * const CNWSCombatRound__GetSpecialAttackID;
// public int CNWSCombatRound::GetSpellActionPendingvoid
extern void * const CNWSCombatRound__GetSpellActionPending;
// public unsigned char CNWSCombatRound::GetTotalAttacksvoid
extern void * const CNWSCombatRound__GetTotalAttacks;
// public int CNWSCombatRound::GetWeaponAttackTypevoid
extern void * const CNWSCombatRound__GetWeaponAttackType;
// void CNWSCombatRound::HasCreatureWeaponsvoid
extern void * const CNWSCombatRound__HasCreatureWeapons;
// public void CNWSCombatRound::IncrementTimerint
extern void * const CNWSCombatRound__IncrementTimer;
// public void CNWSCombatRound::InitializeAttackActionsunsigned long int
extern void * const CNWSCombatRound__InitializeAttackActions;
// void CNWSCombatRound::InitializeCombatModesvoid
extern void * const CNWSCombatRound__InitializeCombatModes;
// public void CNWSCombatRound::InitializeNumberOfAttacksvoid
extern void * const CNWSCombatRound__InitializeNumberOfAttacks;
// void CNWSCombatRound::InsertSpecialAttackunsigned short int, int
extern void * const CNWSCombatRound__InsertSpecialAttack;
// public int CNWSCombatRound::LoadCombatRoundCResGFF*, CResStruct*
extern void * const CNWSCombatRound__LoadCombatRound;
// public void CNWSCombatRound::RecomputeRoundvoid
extern void * const CNWSCombatRound__RecomputeRound;
// public void CNWSCombatRound::RemoveAllActionsvoid
extern void * const CNWSCombatRound__RemoveAllActions;
// public void CNWSCombatRound::RemoveSpecialAttackint
extern void * const CNWSCombatRound__RemoveSpecialAttack;
// public void CNWSCombatRound::RemoveSpellActionvoid
extern void * const CNWSCombatRound__RemoveSpellAction;
// public int CNWSCombatRound::SaveCombatRoundCResGFF*, CResStruct*
extern void * const CNWSCombatRound__SaveCombatRound;
// public void CNWSCombatRound::SetCurrentAttackunsigned char
extern void * const CNWSCombatRound__SetCurrentAttack;
// public void CNWSCombatRound::SetDeflectArrowint
extern void * const CNWSCombatRound__SetDeflectArrow;
// public void CNWSCombatRound::SetPauseTimerint, int
extern void * const CNWSCombatRound__SetPauseTimer;
// public void CNWSCombatRound::SetRoundPausedint, unsigned long int
extern void * const CNWSCombatRound__SetRoundPaused;
// void CNWSCombatRound::SignalCombatRoundStartedvoid
extern void * const CNWSCombatRound__SignalCombatRoundStarted;
// public void CNWSCombatRound::StartCombatRoundunsigned long int
extern void * const CNWSCombatRound__StartCombatRound;
// public void CNWSCombatRound::StartCombatRoundCastunsigned long int
extern void * const CNWSCombatRound__StartCombatRoundCast;
// public void CNWSCombatRound::UpdateAttackTargetForAllActionsunsigned long int
extern void * const CNWSCombatRound__UpdateAttackTargetForAllActions;

// CNWSCombatRoundAction::CNWSCombatRoundActionvoid
extern void * const CNWSCombatRoundAction__CNWSCombatRoundActionCtor;
// public CNWSCombatRoundAction::~CNWSCombatRoundActionvoid
extern void * const CNWSCombatRoundAction__CNWSCombatRoundActionDtor;
// public int CNWSCombatRoundAction::LoadDataCResGFF*, CResStruct*
extern void * const CNWSCombatRoundAction__LoadData;
// public int CNWSCombatRoundAction::SaveDataCResGFF*, CResStruct*
extern void * const CNWSCombatRoundAction__SaveData;

// public CNWSCreature::CNWSCreatureunsigned long int, int, int
extern void * const CNWSCreature__CNWSCreatureCtor;
// public CNWSCreature::~CNWSCreaturevoid
extern void * const CNWSCreature__CNWSCreatureDtor;
// public int CNWSCreature::AcquireItemCNWSItem**, unsigned long int, unsigned long int, unsigned char, unsigned char, int, int
extern void * const CNWSCreature__AcquireItem;
// public void CNWSCreature::ActionManagerunsigned long int
extern void * const CNWSCreature__ActionManager;
// public void CNWSCreature::ActivityManagerunsigned long int
extern void * const CNWSCreature__ActivityManager;
// public int CNWSCreature::AddAnimalEmpathyActionunsigned long int
extern void * const CNWSCreature__AddAnimalEmpathyAction;
// public int CNWSCreature::AddAppearActionsint
extern void * const CNWSCreature__AddAppearActions;
// void CNWSCreature::AddAreaOfEffectunsigned long int
extern void * const CNWSCreature__AddAreaOfEffect;
// public void CNWSCreature::AddAssociateunsigned long int, unsigned short int
extern void * const CNWSCreature__AddAssociate;
// public int CNWSCreature::AddAttackActionsunsigned long int, int, int, int
extern void * const CNWSCreature__AddAttackActions;
// public int CNWSCreature::AddCastSpellActionsunsigned long int, int, int, int, int, Vector, unsigned long int, int, int, int, unsigned char, int, int, int, unsigned char
extern void * const CNWSCreature__AddCastSpellActions;
// public int CNWSCreature::AddCounterSpellActionsunsigned long int
extern void * const CNWSCreature__AddCounterSpellActions;
// public int CNWSCreature::AddDisappearActionsint, int
extern void * const CNWSCreature__AddDisappearActions;
// public int CNWSCreature::AddDriveActionunsigned short int, const Vector&, int, int, int, int
extern void * const CNWSCreature__AddDriveAction;
// public int CNWSCreature::AddDropItemActionsunsigned long int, Vector, int
extern void * const CNWSCreature__AddDropItemActions;
// public int CNWSCreature::AddEquipItemActionsCNWSItem*, unsigned long int, int, int, unsigned long int
extern void * const CNWSCreature__AddEquipItemActions;
// public void CNWSCreature::AddGoldint, int
extern void * const CNWSCreature__AddGold;
// public int CNWSCreature::AddHealActionsunsigned long int, unsigned long int, int
extern void * const CNWSCreature__AddHealActions;
// public int CNWSCreature::AddItemCastSpellActionsunsigned long int, int, int, Vector, unsigned long int, int
extern void * const CNWSCreature__AddItemCastSpellActions;
// public int CNWSCreature::AddMoveToPointActionunsigned short int, Vector, unsigned long int, unsigned long int, int, float, float, int, int, int, int, int, int
extern void * const CNWSCreature__AddMoveToPointAction;
// public int CNWSCreature::AddMoveToPointActionToFrontunsigned short int, Vector, unsigned long int, unsigned long int, int, float, float, int, int, int, int, int, int
extern void * const CNWSCreature__AddMoveToPointActionToFront;
// public int CNWSCreature::AddPathfindingWaitActionToFrontunsigned short int
extern void * const CNWSCreature__AddPathfindingWaitActionToFront;
// public int CNWSCreature::AddPickPocketActionsunsigned long int
extern void * const CNWSCreature__AddPickPocketActions;
// public int CNWSCreature::AddPickUpItemActionsunsigned long int, unsigned long int, unsigned char, unsigned char
extern void * const CNWSCreature__AddPickUpItemActions;
// public int CNWSCreature::AddRepositoryMoveActionsCNWSItem*, unsigned long int, unsigned char, unsigned char
extern void * const CNWSCreature__AddRepositoryMoveActions;
// public int CNWSCreature::AddSitActionsunsigned long int
extern void * const CNWSCreature__AddSitActions;
// public int CNWSCreature::AddTauntActionsunsigned long int
extern void * const CNWSCreature__AddTauntActions;
// public void CNWSCreature::AddToAreaCNWSArea*, float, float, float, int
extern void * const CNWSCreature__AddToArea;
// protected void CNWSCreature::AddToAssociateListunsigned long int
extern void * const CNWSCreature__AddToAssociateList;
// public void CNWSCreature::AddToInvitationsIgnoredunsigned long int
extern void * const CNWSCreature__AddToInvitationsIgnored;
// public void CNWSCreature::AddToInvitationsOfferedunsigned long int
extern void * const CNWSCreature__AddToInvitationsOffered;
// public void CNWSCreature::AddToPersonalReputationListunsigned long int, int, int, float
extern void * const CNWSCreature__AddToPersonalReputationList;
// public void CNWSCreature::AddToPVPListunsigned long int
extern void * const CNWSCreature__AddToPVPList;
// public void CNWSCreature::AddToVisibleListunsigned long int, int, int, unsigned char, int
extern void * const CNWSCreature__AddToVisibleList;
// public int CNWSCreature::AddTrapActionsunsigned long int, unsigned char, unsigned long int, Vector, unsigned long int
extern void * const CNWSCreature__AddTrapActions;
// public int CNWSCreature::AddUnequipActionsCNWSItem*, unsigned long int, unsigned char, unsigned char, int, int, unsigned long int
extern void * const CNWSCreature__AddUnequipActions;
// public int CNWSCreature::AddUseTalentAtLocationActionsint, int, Vector, unsigned char, unsigned long int, int, unsigned char, unsigned char
extern void * const CNWSCreature__AddUseTalentAtLocationActions;
// public int CNWSCreature::AddUseTalentOnObjectActionsint, int, unsigned long int, unsigned char, unsigned long int, int, unsigned char, unsigned char
extern void * const CNWSCreature__AddUseTalentOnObjectActions;
// public void CNWSCreature::AdjustReputationint, int
extern void * const CNWSCreature__AdjustReputation;
// public unsigned long int CNWSCreature::AIActionAnimalEmpathyCNWSObjectActionNode*
extern void * const CNWSCreature__AIActionAnimalEmpathy;
// public unsigned long int CNWSCreature::AIActionAppearCNWSObjectActionNode*
extern void * const CNWSCreature__AIActionAppear;
// public unsigned long int CNWSCreature::AIActionAreaWaitCNWSObjectActionNode*
extern void * const CNWSCreature__AIActionAreaWait;
// public unsigned long int CNWSCreature::AIActionAttackObjectCNWSObjectActionNode*
extern void * const CNWSCreature__AIActionAttackObject;
// public unsigned long int CNWSCreature::AIActionBarterCNWSObjectActionNode*
extern void * const CNWSCreature__AIActionBarter;
// public unsigned long int CNWSCreature::AIActionCastSpellCNWSObjectActionNode*
extern void * const CNWSCreature__AIActionCastSpell;
// public unsigned long int CNWSCreature::AIActionChangeFacingObjectCNWSObjectActionNode*
extern void * const CNWSCreature__AIActionChangeFacingObject;
// public unsigned long int CNWSCreature::AIActionChangeFacingPointCNWSObjectActionNode*
extern void * const CNWSCreature__AIActionChangeFacingPoint;
// public unsigned long int CNWSCreature::AIActionCheckForceFollowObjectCNWSObjectActionNode*
extern void * const CNWSCreature__AIActionCheckForceFollowObject;
// public unsigned long int CNWSCreature::AIActionCheckInterAreaPathfindingCNWSObjectActionNode*
extern void * const CNWSCreature__AIActionCheckInterAreaPathfinding;
// public unsigned long int CNWSCreature::AIActionCheckMoveAwayFromLocationCNWSObjectActionNode*
extern void * const CNWSCreature__AIActionCheckMoveAwayFromLocation;
// public unsigned long int CNWSCreature::AIActionCheckMoveAwayFromObjectCNWSObjectActionNode*
extern void * const CNWSCreature__AIActionCheckMoveAwayFromObject;
// public unsigned long int CNWSCreature::AIActionCheckMoveToObjectCNWSObjectActionNode*
extern void * const CNWSCreature__AIActionCheckMoveToObject;
// public unsigned long int CNWSCreature::AIActionCheckMoveToObjectRadiusCNWSObjectActionNode*
extern void * const CNWSCreature__AIActionCheckMoveToObjectRadius;
// public unsigned long int CNWSCreature::AIActionCheckMoveToPointCNWSObjectActionNode*
extern void * const CNWSCreature__AIActionCheckMoveToPoint;
// public unsigned long int CNWSCreature::AIActionCheckMoveToPointRadiusCNWSObjectActionNode*
extern void * const CNWSCreature__AIActionCheckMoveToPointRadius;
// public unsigned long int CNWSCreature::AIActionCounterSpellCNWSObjectActionNode*
extern void * const CNWSCreature__AIActionCounterSpell;
// public unsigned long int CNWSCreature::AIActionDisappearCNWSObjectActionNode*
extern void * const CNWSCreature__AIActionDisappear;
// public unsigned long int CNWSCreature::AIActionDisarmTrapCNWSObjectActionNode*
extern void * const CNWSCreature__AIActionDisarmTrap;
// public unsigned long int CNWSCreature::AIActionDriveCNWSObjectActionNode*
extern void * const CNWSCreature__AIActionDrive;
// public unsigned long int CNWSCreature::AIActionDropItemCNWSObjectActionNode*
extern void * const CNWSCreature__AIActionDropItem;
// public unsigned long int CNWSCreature::AIActionEncounterCreatureDestroySelfvoid
extern void * const CNWSCreature__AIActionEncounterCreatureDestroySelf;
// public unsigned long int CNWSCreature::AIActionEquipItemCNWSObjectActionNode*
extern void * const CNWSCreature__AIActionEquipItem;
// public unsigned long int CNWSCreature::AIActionExamineCNWSObjectActionNode*
extern void * const CNWSCreature__AIActionExamine;
// public unsigned long int CNWSCreature::AIActionExamineTrapCNWSObjectActionNode*
extern void * const CNWSCreature__AIActionExamineTrap;
// public unsigned long int CNWSCreature::AIActionFlagTrapCNWSObjectActionNode*
extern void * const CNWSCreature__AIActionFlagTrap;
// public unsigned long int CNWSCreature::AIActionForceFollowObjectCNWSObjectActionNode*
extern void * const CNWSCreature__AIActionForceFollowObject;
// public unsigned long int CNWSCreature::AIActionHealCNWSObjectActionNode*
extern void * const CNWSCreature__AIActionHeal;
// public unsigned long int CNWSCreature::AIActionItemCastSpellCNWSObjectActionNode*
extern void * const CNWSCreature__AIActionItemCastSpell;
// public unsigned long int CNWSCreature::AIActionJumpToObjectCNWSObjectActionNode*
extern void * const CNWSCreature__AIActionJumpToObject;
// public unsigned long int CNWSCreature::AIActionJumpToPointCNWSObjectActionNode*
extern void * const CNWSCreature__AIActionJumpToPoint;
// public unsigned long int CNWSCreature::AIActionMoveToPointCNWSObjectActionNode*
extern void * const CNWSCreature__AIActionMoveToPoint;
// public unsigned long int CNWSCreature::AIActionOrientCameraCNWSObjectActionNode*
extern void * const CNWSCreature__AIActionOrientCamera;
// public unsigned long int CNWSCreature::AIActionPickPocketCNWSObjectActionNode*
extern void * const CNWSCreature__AIActionPickPocket;
// public unsigned long int CNWSCreature::AIActionPickUpItemCNWSObjectActionNode*
extern void * const CNWSCreature__AIActionPickUpItem;
// public unsigned long int CNWSCreature::AIActionRandomWalkCNWSObjectActionNode*
extern void * const CNWSCreature__AIActionRandomWalk;
// public unsigned long int CNWSCreature::AIActionRecoverTrapCNWSObjectActionNode*
extern void * const CNWSCreature__AIActionRecoverTrap;
// public unsigned long int CNWSCreature::AIActionRepositoryMoveCNWSObjectActionNode*
extern void * const CNWSCreature__AIActionRepositoryMove;
// public unsigned long int CNWSCreature::AIActionRestCNWSObjectActionNode*
extern void * const CNWSCreature__AIActionRest;
// public unsigned long int CNWSCreature::AIActionSetTrapCNWSObjectActionNode*
extern void * const CNWSCreature__AIActionSetTrap;
// public unsigned long int CNWSCreature::AIActionSitCNWSObjectActionNode*
extern void * const CNWSCreature__AIActionSit;
// public unsigned long int CNWSCreature::AIActionTauntCNWSObjectActionNode*
extern void * const CNWSCreature__AIActionTaunt;
// public unsigned long int CNWSCreature::AIActionUnequipItemCNWSObjectActionNode*
extern void * const CNWSCreature__AIActionUnequipItem;
// public unsigned long int CNWSCreature::AIActionWaitForEndOfRoundCNWSObjectActionNode*
extern void * const CNWSCreature__AIActionWaitForEndOfRound;
// public void CNWSCreature::AIUpdatevoid
extern void * const CNWSCreature__AIUpdate;
// public void CNWSCreature::ApplyDeathExperiencevoid
extern void * const CNWSCreature__ApplyDeathExperience;
// public int CNWSCreature::ApplyDiseasePayloadCGameEffect*, unsigned long int, unsigned long int
extern void * const CNWSCreature__ApplyDiseasePayload;
// protected void CNWSCreature::ApplyOnHitAbilityDamageCNWSObject*, CNWItemProperty*
extern void * const CNWSCreature__ApplyOnHitAbilityDamage;
// protected void CNWSCreature::ApplyOnHitBlindnessCNWSObject*, int
extern void * const CNWSCreature__ApplyOnHitBlindness;
// protected void CNWSCreature::ApplyOnHitCastSpellCNWSObject*, CNWItemProperty*, CNWSItem*
extern void * const CNWSCreature__ApplyOnHitCastSpell;
// protected void CNWSCreature::ApplyOnHitConfusionCNWSObject*, int
extern void * const CNWSCreature__ApplyOnHitConfusion;
// protected void CNWSCreature::ApplyOnHitDazeCNWSObject*, int
extern void * const CNWSCreature__ApplyOnHitDaze;
// protected void CNWSCreature::ApplyOnHitDeafnessCNWSObject*, int
extern void * const CNWSCreature__ApplyOnHitDeafness;
// protected void CNWSCreature::ApplyOnHitDeathAttackCNWSObject*, int
extern void * const CNWSCreature__ApplyOnHitDeathAttack;
// protected void CNWSCreature::ApplyOnHitDiseaseCNWSObject*, CNWItemProperty*
extern void * const CNWSCreature__ApplyOnHitDisease;
// protected void CNWSCreature::ApplyOnHitDispelMagicCNWSObject*, unsigned long int
extern void * const CNWSCreature__ApplyOnHitDispelMagic__0;
// protected void CNWSCreature::ApplyOnHitDispelMagicCNWSObject*, CNWItemProperty*
extern void * const CNWSCreature__ApplyOnHitDispelMagic__1;
// void CNWSCreature::ApplyOnHitDominateCNWSObject*, int
extern void * const CNWSCreature__ApplyOnHitDominate;
// protected void CNWSCreature::ApplyOnHitDoomCNWSObject*, int
extern void * const CNWSCreature__ApplyOnHitDoom;
// protected void CNWSCreature::ApplyOnHitFearCNWSObject*, int
extern void * const CNWSCreature__ApplyOnHitFear;
// protected void CNWSCreature::ApplyOnHitGreaterDispelCNWSObject*, unsigned long int
extern void * const CNWSCreature__ApplyOnHitGreaterDispel;
// protected void CNWSCreature::ApplyOnHitHoldCNWSObject*, int
extern void * const CNWSCreature__ApplyOnHitHold;
// protected void CNWSCreature::ApplyOnHitKnockCNWSObject*, unsigned long int
extern void * const CNWSCreature__ApplyOnHitKnock;
// protected void CNWSCreature::ApplyOnHitLesserDispelCNWSObject*, unsigned long int
extern void * const CNWSCreature__ApplyOnHitLesserDispel;
// protected void CNWSCreature::ApplyOnHitLevelDrainCNWSObject*, CNWItemProperty*
extern void * const CNWSCreature__ApplyOnHitLevelDrain;
// protected void CNWSCreature::ApplyOnHitMordysDisjunctionCNWSObject*, unsigned long int
extern void * const CNWSCreature__ApplyOnHitMordysDisjunction;
// protected void CNWSCreature::ApplyOnHitPoisonCNWSObject*, CNWItemProperty*
extern void * const CNWSCreature__ApplyOnHitPoison;
// protected void CNWSCreature::ApplyOnHitSilenceCNWSObject*, int
extern void * const CNWSCreature__ApplyOnHitSilence;
// protected void CNWSCreature::ApplyOnHitSlayAlignmentCNWSObject*, CNWItemProperty*
extern void * const CNWSCreature__ApplyOnHitSlayAlignment;
// protected void CNWSCreature::ApplyOnHitSlayAlignmentGroupCNWSObject*, CNWItemProperty*
extern void * const CNWSCreature__ApplyOnHitSlayAlignmentGroup;
// protected void CNWSCreature::ApplyOnHitSlayRacialGroupCNWSObject*, CNWItemProperty*
extern void * const CNWSCreature__ApplyOnHitSlayRacialGroup;
// protected void CNWSCreature::ApplyOnHitSleepCNWSObject*, int
extern void * const CNWSCreature__ApplyOnHitSleep;
// protected void CNWSCreature::ApplyOnHitSlowCNWSObject*, int
extern void * const CNWSCreature__ApplyOnHitSlow;
// protected void CNWSCreature::ApplyOnHitStunCNWSObject*, int
extern void * const CNWSCreature__ApplyOnHitStun;
// protected void CNWSCreature::ApplyOnHitVampiricRegenerationCNWSObject*, CNWItemProperty*
extern void * const CNWSCreature__ApplyOnHitVampiricRegeneration;
// protected void CNWSCreature::ApplyOnHitVorpalCNWSObject*, CNWItemProperty*
extern void * const CNWSCreature__ApplyOnHitVorpal;
// protected void CNWSCreature::ApplyOnHitWoundingCNWSObject*, CNWItemProperty*
extern void * const CNWSCreature__ApplyOnHitWounding;
// public int CNWSCreature::ApplyPoisonPayloadCGameEffect*, unsigned long int, unsigned long int
extern void * const CNWSCreature__ApplyPoisonPayload;
// public int CNWSCreature::ApplyWoundingCGameEffect*
extern void * const CNWSCreature__ApplyWounding;
// public CNWSCreature* CNWSCreature::AsNWSCreaturevoid
extern void * const CNWSCreature__AsNWSCreature;
// public void CNWSCreature::AutoCloseGUIPanelsint
extern void * const CNWSCreature__AutoCloseGUIPanels;
// public void CNWSCreature::BringAssociatesToNewFactionint
extern void * const CNWSCreature__BringAssociatesToNewFaction;
// void CNWSCreature::BroadcastAssociateCommandint
extern void * const CNWSCreature__BroadcastAssociateCommand;
// public void CNWSCreature::BroadcastAttackDataToPartyCNWCCMessageData*, CNWSCombatAttackData*, CNWSCreature*
extern void * const CNWSCreature__BroadcastAttackDataToParty;
// public void CNWSCreature::BroadcastAttackOfOpportunityunsigned long int, int
extern void * const CNWSCreature__BroadcastAttackOfOpportunity;
// public void CNWSCreature::BroadcastBattleCryvoid
extern void * const CNWSCreature__BroadcastBattleCry;
// public void CNWSCreature::BroadcastCombatStateToPartyvoid
extern void * const CNWSCreature__BroadcastCombatStateToParty;
// public void CNWSCreature::BroadcastDamageDataToPartyCNWCCMessageData*, CNWSCreature*
extern void * const CNWSCreature__BroadcastDamageDataToParty;
// public void CNWSCreature::BroadcastDeathDataToPartyCNWCCMessageData*, CNWSCreature*
extern void * const CNWSCreature__BroadcastDeathDataToParty;
// public void CNWSCreature::BroadcastFloatyDataCNWCCMessageData*
extern void * const CNWSCreature__BroadcastFloatyData;
// public void CNWSCreature::BroadcastSavingThrowDataCNWCCMessageData*
extern void * const CNWSCreature__BroadcastSavingThrowData;
// public void CNWSCreature::BroadcastSkillDataCNWCCMessageData*
extern void * const CNWSCreature__BroadcastSkillData;
// public void CNWSCreature::BroadcastSpellCastunsigned long int, unsigned char, unsigned short int
extern void * const CNWSCreature__BroadcastSpellCast;
// public void CNWSCreature::BroadcastVoiceChatunsigned char
extern void * const CNWSCreature__BroadcastVoiceChat;
// public void CNWSCreature::BroadcastWhirlwindAttackint
extern void * const CNWSCreature__BroadcastWhirlwindAttack;
// protected int CNWSCreature::BumpFriendsCNWSCreature*, const Vector&, const Vector&
extern void * const CNWSCreature__BumpFriends;
// public unsigned char CNWSCreature::CalculateDamagePowerCNWSObject*, int
extern void * const CNWSCreature__CalculateDamagePower;
// public float CNWSCreature::CalculateDeathExperienceint, int
extern void * const CNWSCreature__CalculateDeathExperience;
// protected int CNWSCreature::CalculateMaxElementalDamageCNWSObject*, int
extern void * const CNWSCreature__CalculateMaxElementalDamage;
// public int CNWSCreature::CalculatePersonalReputationAdjustmentunsigned long int
extern void * const CNWSCreature__CalculatePersonalReputationAdjustment;
// void CNWSCreature::CalculateProjectileTimeToTargetVector, int
extern void * const CNWSCreature__CalculateProjectileTimeToTarget;
// public int CNWSCreature::CalculateSpellSaveDCint
extern void * const CNWSCreature__CalculateSpellSaveDC;
// public int CNWSCreature::CancelActionunsigned short int, unsigned short int
extern void * const CNWSCreature__CancelAction;
// public void CNWSCreature::CancelGoldTransferunsigned long int
extern void * const CNWSCreature__CancelGoldTransfer;
// public void CNWSCreature::CancelRestunsigned short int
extern void * const CNWSCreature__CancelRest;
// public unsigned char CNWSCreature::CanEquipItemCNWSItem*, unsigned long int*, int, int, int, CNWSPlayer*
extern void * const CNWSCreature__CanEquipItem;
// protected unsigned char CNWSCreature::CanEquipMiscellaneousCNWSItem*, unsigned long int*, int, int
extern void * const CNWSCreature__CanEquipMiscellaneous;
// protected unsigned char CNWSCreature::CanEquipShieldCNWSItem*, int, int
extern void * const CNWSCreature__CanEquipShield;
// protected unsigned char CNWSCreature::CanEquipWeaponCNWSItem*, unsigned long int*, int, int, CNWSPlayer*
extern void * const CNWSCreature__CanEquipWeapon;
// public unsigned char CNWSCreature::CanUnEquipWeaponCNWSItem*
extern void * const CNWSCreature__CanUnEquipWeapon;
// public int CNWSCreature::CanUseItemCNWSItem*, int
extern void * const CNWSCreature__CanUseItem;
// public void CNWSCreature::CheckInventoryForPlotItemsvoid
extern void * const CNWSCreature__CheckInventoryForPlotItems;
// protected int CNWSCreature::CheckItemAlignmentRestrictionsCNWSItem*
extern void * const CNWSCreature__CheckItemAlignmentRestrictions;
// protected int CNWSCreature::CheckItemClassRestrictionsCNWSItem*
extern void * const CNWSCreature__CheckItemClassRestrictions;
// protected int CNWSCreature::CheckItemRaceRestrictionsCNWSItem*
extern void * const CNWSCreature__CheckItemRaceRestrictions;
// protected void CNWSCreature::CheckMasterIsValidunsigned long int, unsigned long int
extern void * const CNWSCreature__CheckMasterIsValid;
// protected int CNWSCreature::CheckProficienciesCNWSItem*, unsigned long int
extern void * const CNWSCreature__CheckProficiencies;
// protected int CNWSCreature::CheckUseMagicDeviceSkillCNWSItem*, int
extern void * const CNWSCreature__CheckUseMagicDeviceSkill;
// void CNWSCreature::CheckVisibleListunsigned long int
extern void * const CNWSCreature__CheckVisibleList;
// public void CNWSCreature::CleanInvitationListsint
extern void * const CNWSCreature__CleanInvitationLists;
// public void CNWSCreature::CleanOutPersonalReputationListvoid
extern void * const CNWSCreature__CleanOutPersonalReputationList;
// protected int CNWSCreature::ClearActionCNWSObjectActionNode*, int
extern void * const CNWSCreature__ClearAction;
// public void CNWSCreature::ClearActivitiesint
extern void * const CNWSCreature__ClearActivities;
// void CNWSCreature::ClearAutoMapDatavoid
extern void * const CNWSCreature__ClearAutoMapData;
// public void CNWSCreature::ClearHostileActionsVersusCNWSCreature*
extern void * const CNWSCreature__ClearHostileActionsVersus;
// public void CNWSCreature::ClearPersonalReputationunsigned long int
extern void * const CNWSCreature__ClearPersonalReputation;
// public void CNWSCreature::ClearVisibleListvoid
extern void * const CNWSCreature__ClearVisibleList;
// public void CNWSCreature::ComputeAIStatevoid
extern void * const CNWSCreature__ComputeAIState;
// protected void CNWSCreature::ComputeAIStateOnActionint, unsigned long int
extern void * const CNWSCreature__ComputeAIStateOnAction;
// public void CNWSCreature::ComputeArmourClassCNWSItem*, int, int
extern void * const CNWSCreature__ComputeArmourClass;
// public void CNWSCreature::ComputeModifiedMovementRatevoid
extern void * const CNWSCreature__ComputeModifiedMovementRate;
// public float CNWSCreature::ComputeSpellRangeCExoString, unsigned long int
extern void * const CNWSCreature__ComputeSpellRange;
// void CNWSCreature::ComputeTotalEquippedWeightvoid
extern void * const CNWSCreature__ComputeTotalEquippedWeight;
// protected float CNWSCreature::ComputeTotalWalkDistancevoid
extern void * const CNWSCreature__ComputeTotalWalkDistance;
// public int CNWSCreature::ComputeTotalWeightCarriedvoid
extern void * const CNWSCreature__ComputeTotalWeightCarried;
// public void CNWSCreature::ConvertModeToggleQuickButtonCNWSQuickbarButton*
extern void * const CNWSCreature__ConvertModeToggleQuickButton;
// public void CNWSCreature::CopyQuickButtonsFromDMCNWSPlayer*
extern void * const CNWSCreature__CopyQuickButtonsFromDM;
// public void CNWSCreature::CreateDefaultQuickButtonsvoid
extern void * const CNWSCreature__CreateDefaultQuickButtons;
// public void CNWSCreature::CreateDefaultQuickButtons_AddFeatunsigned char&, unsigned short int, int
extern void * const CNWSCreature__CreateDefaultQuickButtons_AddFeat;
// void CNWSCreature::CreateDefaultQuickButtons_CheckItemCNWSItem*, unsigned long int&, unsigned long int&, unsigned long int&, unsigned long int&
extern void * const CNWSCreature__CreateDefaultQuickButtons_CheckItem;
// void CNWSCreature::CreateDefaultQuickButtonsDMvoid
extern void * const CNWSCreature__CreateDefaultQuickButtonsDM;
// public void CNWSCreature::CutWaypointPathvoid
extern void * const CNWSCreature__CutWaypointPath;
// public int CNWSCreature::DecrementSpellReadyCountunsigned long int, unsigned char, unsigned char, unsigned char, unsigned char
extern void * const CNWSCreature__DecrementSpellReadyCount;
// public float CNWSCreature::DesiredAttackRangeunsigned long int, int
extern void * const CNWSCreature__DesiredAttackRange;
// public void CNWSCreature::DestroyEquippedItemsvoid
extern void * const CNWSCreature__DestroyEquippedItems;
// public void CNWSCreature::DisplayFloatyDataToSelfunsigned long int
extern void * const CNWSCreature__DisplayFloatyDataToSelf;
// public void CNWSCreature::DMClearScriptsint
extern void * const CNWSCreature__DMClearScripts;
// public void CNWSCreature::DMResetClearedScriptsint
extern void * const CNWSCreature__DMResetClearedScripts;
// public void CNWSCreature::DoCombatStepunsigned char, int, unsigned long int
extern void * const CNWSCreature__DoCombatStep;
// public void CNWSCreature::DoDamageint
extern void * const CNWSCreature__DoDamage;
// protected int CNWSCreature::DoListenDetectionCNWSCreature*, int
extern void * const CNWSCreature__DoListenDetection;
// public void CNWSCreature::DoPerceptionUpdateOnCreatureCNWSCreature*, int
extern void * const CNWSCreature__DoPerceptionUpdateOnCreature;
// protected int CNWSCreature::DoSpotDetectionCNWSCreature*, int
extern void * const CNWSCreature__DoSpotDetection;
// protected int CNWSCreature::DoStealthDetectionCNWSCreature*, int, int*, int*, int
extern void * const CNWSCreature__DoStealthDetection;
// public unsigned long int CNWSCreature::DriveUpdateLocationint
extern void * const CNWSCreature__DriveUpdateLocation;
// public void CNWSCreature::DumpToLogvoid
extern void * const CNWSCreature__DumpToLog;
// public int CNWSCreature::EquipItemunsigned long int, CNWSItem*, int, int
extern void * const CNWSCreature__EquipItem;
// public int CNWSCreature::EquipMostDamagingAmmunitionunsigned long int, CNWSItem*
extern void * const CNWSCreature__EquipMostDamagingAmmunition;
// public int CNWSCreature::EquipMostDamagingMeleeWeaponunsigned long int, int, int
extern void * const CNWSCreature__EquipMostDamagingMeleeWeapon;
// public int CNWSCreature::EquipMostDamagingRangedWeaponunsigned long int
extern void * const CNWSCreature__EquipMostDamagingRangedWeapon;
// public int CNWSCreature::EquipMostEffectiveArmorvoid
extern void * const CNWSCreature__EquipMostEffectiveArmor;
// public int CNWSCreature::EvaluateLockCNWSObject*, int
extern void * const CNWSCreature__EvaluateLock;
// public void CNWSCreature::EventHandlerunsigned long int, unsigned long int, void*, unsigned long int, unsigned long int
extern void * const CNWSCreature__EventHandler;
// public void CNWSCreature::ExternalResolveAttackunsigned long int, int
extern void * const CNWSCreature__ExternalResolveAttack;
// public void CNWSCreature::FailedOpenInformAssociatesvoid
extern void * const CNWSCreature__FailedOpenInformAssociates;
// public int CNWSCreature::ForceMoveToPointCNWSForcedAction*
extern void * const CNWSCreature__ForceMoveToPoint;
// void CNWSCreature::GetActionQueueListvoid
extern void * const CNWSCreature__GetActionQueueList;
// public int CNWSCreature::GetActivityint
extern void * const CNWSCreature__GetActivity;
// void CNWSCreature::GetActivityLockedunsigned long int
extern void * const CNWSCreature__GetActivityLocked;
// void CNWSCreature::GetAIStatevoid
extern void * const CNWSCreature__GetAIState;
// void CNWSCreature::GetAIStateActeevoid
extern void * const CNWSCreature__GetAIStateActee;
// void CNWSCreature::GetAIStateActionvoid
extern void * const CNWSCreature__GetAIStateAction;
// void CNWSCreature::GetAIStateActivitiesvoid
extern void * const CNWSCreature__GetAIStateActivities;
// void CNWSCreature::GetAlreadyRemovedFromEncountervoid
extern void * const CNWSCreature__GetAlreadyRemovedFromEncounter;
// void CNWSCreature::GetAmbientAnimationStatevoid
extern void * const CNWSCreature__GetAmbientAnimationState;
// protected int CNWSCreature::GetAmmunitionAvailableint
extern void * const CNWSCreature__GetAmmunitionAvailable;
// void CNWSCreature::GetAnimalCompanionCreatureTypevoid
extern void * const CNWSCreature__GetAnimalCompanionCreatureType;
// void CNWSCreature::GetAnimalCompanionIdvoid
extern void * const CNWSCreature__GetAnimalCompanionId;
// public CExoString CNWSCreature::GetAnimalCompanionNamevoid
extern void * const CNWSCreature__GetAnimalCompanionName;
// void CNWSCreature::GetAppearancevoid
extern void * const CNWSCreature__GetAppearance;
// void CNWSCreature::GetAreaOfEffectObjectsvoid
extern void * const CNWSCreature__GetAreaOfEffectObjects;
// public short int CNWSCreature::GetArmorClassvoid
extern void * const CNWSCreature__GetArmorClass;
// public unsigned long int CNWSCreature::GetAssociateIdunsigned short int, int
extern void * const CNWSCreature__GetAssociateId;
// void CNWSCreature::GetAssociateListvoid
extern void * const CNWSCreature__GetAssociateList;
// void CNWSCreature::GetAssociateTypevoid
extern void * const CNWSCreature__GetAssociateType;
// public int CNWSCreature::GetAttackResultHitCNWSCombatAttackData*
extern void * const CNWSCreature__GetAttackResultHit;
// void CNWSCreature::GetAttackTargetvoid
extern void * const CNWSCreature__GetAttackTarget;
// void CNWSCreature::GetAttemptedAttackTargetvoid
extern void * const CNWSCreature__GetAttemptedAttackTarget;
// void CNWSCreature::GetAttemptedSpellTargetvoid
extern void * const CNWSCreature__GetAttemptedSpellTarget;
// void CNWSCreature::GetAutoMapAreaListvoid
extern void * const CNWSCreature__GetAutoMapAreaList;
// void CNWSCreature::GetAutoMapTileDatavoid
extern void * const CNWSCreature__GetAutoMapTileData;
// public CNWSBarter* CNWSCreature::GetBarterInfoint
extern void * const CNWSCreature__GetBarterInfo;
// public int CNWSCreature::GetBlindvoid
extern void * const CNWSCreature__GetBlind;
// void CNWSCreature::GetBlindsightDistancevoid
extern void * const CNWSCreature__GetBlindsightDistance;
// void CNWSCreature::GetBodyBagvoid
extern void * const CNWSCreature__GetBodyBag;
// public unsigned short int CNWSCreature::GetBodyBagAppearancevoid
extern void * const CNWSCreature__GetBodyBagAppearance;
// void CNWSCreature::GetBodyBagIdvoid
extern void * const CNWSCreature__GetBodyBagId;
// void CNWSCreature::GetBroadcastedAOOTovoid
extern void * const CNWSCreature__GetBroadcastedAOOTo;
// void CNWSCreature::GetCalculateNPCWeightvoid
extern void * const CNWSCreature__GetCalculateNPCWeight;
// protected int CNWSCreature::GetCanSlayAlignmentCNWSObject*, CNWItemProperty*
extern void * const CNWSCreature__GetCanSlayAlignment;
// void CNWSCreature::GetCombatModevoid
extern void * const CNWSCreature__GetCombatMode;
// void CNWSCreature::GetCombatRoundvoid
extern void * const CNWSCreature__GetCombatRound;
// void CNWSCreature::GetCombatStatevoid
extern void * const CNWSCreature__GetCombatState;
// void CNWSCreature::GetCombatStateTimervoid
extern void * const CNWSCreature__GetCombatStateTimer;
// void CNWSCreature::GetCounterSpellTargetvoid
extern void * const CNWSCreature__GetCounterSpellTarget;
// public int CNWSCreature::GetCreatureReputationunsigned long int, int, int
extern void * const CNWSCreature__GetCreatureReputation;
// void CNWSCreature::GetCreatureSizevoid
extern void * const CNWSCreature__GetCreatureSize;
// void CNWSCreature::GetCreatureStatevoid
extern void * const CNWSCreature__GetCreatureState;
// void CNWSCreature::GetCurrentItemContainervoid
extern void * const CNWSCreature__GetCurrentItemContainer;
// void CNWSCreature::GetCutsceneCameraModevoid
extern void * const CNWSCreature__GetCutsceneCameraMode;
// void CNWSCreature::GetCutsceneCameraMovementRateFactorvoid
extern void * const CNWSCreature__GetCutsceneCameraMovementRateFactor;
// void CNWSCreature::GetCutsceneGhostvoid
extern void * const CNWSCreature__GetCutsceneGhost;
// public unsigned short int CNWSCreature::GetDamageFlagsvoid
extern void * const CNWSCreature__GetDamageFlags;
// void CNWSCreature::GetDecayTimevoid
extern void * const CNWSCreature__GetDecayTime;
// void CNWSCreature::GetDefensiveCastingModevoid
extern void * const CNWSCreature__GetDefensiveCastingMode;
// void CNWSCreature::GetDesiredAreaIdvoid
extern void * const CNWSCreature__GetDesiredAreaId;
// void CNWSCreature::GetDesiredAreaLocationvoid
extern void * const CNWSCreature__GetDesiredAreaLocation;
// void CNWSCreature::GetDesiredAreaUpdateCompletevoid
extern void * const CNWSCreature__GetDesiredAreaUpdateComplete;
// void CNWSCreature::GetDesiredCombatModevoid
extern void * const CNWSCreature__GetDesiredCombatMode;
// public unsigned char CNWSCreature::GetDetectModevoid
extern void * const CNWSCreature__GetDetectMode;
// public int CNWSCreature::GetDialogInterruptablevoid
extern void * const CNWSCreature__GetDialogInterruptable;
// public CResRef CNWSCreature::GetDialogResrefvoid
extern void * const CNWSCreature__GetDialogResref;
// void CNWSCreature::GetDisarmablevoid
extern void * const CNWSCreature__GetDisarmable;
// public CExoString CNWSCreature::GetDisplayNamevoid
extern void * const CNWSCreature__GetDisplayName;
// void CNWSCreature::GetDMCharactervoid
extern void * const CNWSCreature__GetDMCharacter;
// public unsigned long int CNWSCreature::GetDominatedCreatureIdvoid
extern void * const CNWSCreature__GetDominatedCreatureId;
// void CNWSCreature::GetDriveModevoid
extern void * const CNWSCreature__GetDriveMode;
// void CNWSCreature::GetDriveModeMoveFactorvoid
extern void * const CNWSCreature__GetDriveModeMoveFactor;
// void CNWSCreature::GetDropItemAnimationPlayedvoid
extern void * const CNWSCreature__GetDropItemAnimationPlayed;
// void CNWSCreature::GetEffectIconsvoid
extern void * const CNWSCreature__GetEffectIcons;
// public unsigned long int CNWSCreature::GetEffectSpellIdvoid
extern void * const CNWSCreature__GetEffectSpellId;
// void CNWSCreature::GetEncounterIdvoid
extern void * const CNWSCreature__GetEncounterId;
// void CNWSCreature::GetEncumbranceStatevoid
extern void * const CNWSCreature__GetEncumbranceState;
// void CNWSCreature::GetEquipArrayIndexvoid
extern void * const CNWSCreature__GetEquipArrayIndex;
// void CNWSCreature::GetEquippedWeightvoid
extern void * const CNWSCreature__GetEquippedWeight;
// void CNWSCreature::GetExternalCombatModeEnabledvoid
extern void * const CNWSCreature__GetExternalCombatModeEnabled;
// void CNWSCreature::GetFacingAndAnimationDonevoid
extern void * const CNWSCreature__GetFacingAndAnimationDone;
// public CNWSFaction* CNWSCreature::GetFactionvoid
extern void * const CNWSCreature__GetFaction;
// void CNWSCreature::GetFactionIdvoid
extern void * const CNWSCreature__GetFactionId;
// void CNWSCreature::GetFamiliarCreatureTypevoid
extern void * const CNWSCreature__GetFamiliarCreatureType;
// void CNWSCreature::GetFamiliarIdvoid
extern void * const CNWSCreature__GetFamiliarId;
// public CExoString CNWSCreature::GetFamiliarNamevoid
extern void * const CNWSCreature__GetFamiliarName;
// public CExoArrayListTemplatedCGameEffectPtr CNWSCreature::GetFilteredEffectListunsigned char
extern void * const CNWSCreature__GetFilteredEffectList;
// public CExoLocString& CNWSCreature::GetFirstNamevoid
extern void * const CNWSCreature__GetFirstName;
// public int CNWSCreature::GetFlankedCNWSCreature*
extern void * const CNWSCreature__GetFlanked;
// public int CNWSCreature::GetFlatFootedvoid
extern void * const CNWSCreature__GetFlatFooted;
// void CNWSCreature::GetFootstepTypevoid
extern void * const CNWSCreature__GetFootstepType;
// void CNWSCreature::GetForcedWalkvoid
extern void * const CNWSCreature__GetForcedWalk;
// void CNWSCreature::GetFreeWillvoid
extern void * const CNWSCreature__GetFreeWill;
// public unsigned char CNWSCreature::GetGendervoid
extern void * const CNWSCreature__GetGender;
// void CNWSCreature::GetGoingToBeAttackedByvoid
extern void * const CNWSCreature__GetGoingToBeAttackedBy;
// void CNWSCreature::GetGoldvoid
extern void * const CNWSCreature__GetGold;
// void CNWSCreature::GetHasArmsvoid
extern void * const CNWSCreature__GetHasArms;
// void CNWSCreature::GetHasInvisbilityEffectAppliedvoid
extern void * const CNWSCreature__GetHasInvisbilityEffectApplied;
// void CNWSCreature::GetHasLegsvoid
extern void * const CNWSCreature__GetHasLegs;
// void CNWSCreature::GetHastedvoid
extern void * const CNWSCreature__GetHasted;
// void CNWSCreature::GetHealAnimationPlayedvoid
extern void * const CNWSCreature__GetHealAnimationPlayed;
// void CNWSCreature::GetHenchmanIdint
extern void * const CNWSCreature__GetHenchmanId;
// void CNWSCreature::GetHenchmanIndexunsigned long int
extern void * const CNWSCreature__GetHenchmanIndex;
// void CNWSCreature::GetInitiativeExpiredvoid
extern void * const CNWSCreature__GetInitiativeExpired;
// void CNWSCreature::GetInitiativeRollvoid
extern void * const CNWSCreature__GetInitiativeRoll;
// void CNWSCreature::GetInSubAreasArrayvoid
extern void * const CNWSCreature__GetInSubAreasArray;
// void CNWSCreature::GetInTransitvoid
extern void * const CNWSCreature__GetInTransit;
// void CNWSCreature::GetInventoryvoid
extern void * const CNWSCreature__GetInventory;
// public int CNWSCreature::GetInvisibleCNWSObject*, int
extern void * const CNWSCreature__GetInvisible;
// void CNWSCreature::GetInvitedToPartyvoid
extern void * const CNWSCreature__GetInvitedToParty;
// void CNWSCreature::GetInvitedToPartyByvoid
extern void * const CNWSCreature__GetInvitedToPartyBy;
// public int CNWSCreature::GetIsAbleToPossessFamiliarvoid
extern void * const CNWSCreature__GetIsAbleToPossessFamiliar;
// public int CNWSCreature::GetIsCreatureBumpableCNWSCreature*
extern void * const CNWSCreature__GetIsCreatureBumpable;
// void CNWSCreature::GetIsDiseasedvoid
extern void * const CNWSCreature__GetIsDiseased;
// void CNWSCreature::GetIsExcitedvoid
extern void * const CNWSCreature__GetIsExcited;
// void CNWSCreature::GetIsImmortalvoid
extern void * const CNWSCreature__GetIsImmortal;
// public int CNWSCreature::GetIsInInvitationsIgnoredunsigned long int
extern void * const CNWSCreature__GetIsInInvitationsIgnored;
// public int CNWSCreature::GetIsInInvitationsOfferedunsigned long int
extern void * const CNWSCreature__GetIsInInvitationsOffered;
// void CNWSCreature::GetIsInMeleevoid
extern void * const CNWSCreature__GetIsInMelee;
// public int CNWSCreature::GetIsInUseRangeunsigned long int, float, int
extern void * const CNWSCreature__GetIsInUseRange;
// void CNWSCreature::GetIsPoisonedvoid
extern void * const CNWSCreature__GetIsPoisoned;
// void CNWSCreature::GetIsPolymorphedvoid
extern void * const CNWSCreature__GetIsPolymorphed;
// void CNWSCreature::GetIsPolymorphingvoid
extern void * const CNWSCreature__GetIsPolymorphing;
// void CNWSCreature::GetIsPolymorphLockedvoid
extern void * const CNWSCreature__GetIsPolymorphLocked;
// public int CNWSCreature::GetIsPossessedFamiliarvoid
extern void * const CNWSCreature__GetIsPossessedFamiliar;
// public int CNWSCreature::GetIsWeaponEffectiveunsigned long int, int
extern void * const CNWSCreature__GetIsWeaponEffective;
// void CNWSCreature::GetItemCastSpellBroadcastAOOvoid
extern void * const CNWSCreature__GetItemCastSpellBroadcastAOO;
// void CNWSCreature::GetItemContainerArrayIndexvoid
extern void * const CNWSCreature__GetItemContainerArrayIndex;
// public unsigned long int CNWSCreature::GetItemCountint
extern void * const CNWSCreature__GetItemCount;
// void CNWSCreature::GetItemRepositoryvoid
extern void * const CNWSCreature__GetItemRepository;
// public CNWSJournal* CNWSCreature::GetJournalvoid
extern void * const CNWSCreature__GetJournal;
// void CNWSCreature::GetJumpedRecentlyvoid
extern void * const CNWSCreature__GetJumpedRecently;
// void CNWSCreature::GetLastAmmunitionWarningvoid
extern void * const CNWSCreature__GetLastAmmunitionWarning;
// void CNWSCreature::GetLastAssociateCommandvoid
extern void * const CNWSCreature__GetLastAssociateCommand;
// void CNWSCreature::GetLastBlockingDoorvoid
extern void * const CNWSCreature__GetLastBlockingDoor;
// void CNWSCreature::GetLastCounterDomainLevelvoid
extern void * const CNWSCreature__GetLastCounterDomainLevel;
// void CNWSCreature::GetLastCounterMetaTypevoid
extern void * const CNWSCreature__GetLastCounterMetaType;
// void CNWSCreature::GetLastCounterSpellClassvoid
extern void * const CNWSCreature__GetLastCounterSpellClass;
// void CNWSCreature::GetLastCounterSpellIDvoid
extern void * const CNWSCreature__GetLastCounterSpellID;
// void CNWSCreature::GetLastHideRollvoid
extern void * const CNWSCreature__GetLastHideRoll;
// void CNWSCreature::GetLastItemCastSpellvoid
extern void * const CNWSCreature__GetLastItemCastSpell;
// void CNWSCreature::GetLastItemCastSpellLevelvoid
extern void * const CNWSCreature__GetLastItemCastSpellLevel;
// void CNWSCreature::GetLastListenRollvoid
extern void * const CNWSCreature__GetLastListenRoll;
// void CNWSCreature::GetLastMoveSilentlyRollvoid
extern void * const CNWSCreature__GetLastMoveSilentlyRoll;
// public CExoLocString& CNWSCreature::GetLastNamevoid
extern void * const CNWSCreature__GetLastName;
// void CNWSCreature::GetLastPerceivedvoid
extern void * const CNWSCreature__GetLastPerceived;
// void CNWSCreature::GetLastPerceptionHeardvoid
extern void * const CNWSCreature__GetLastPerceptionHeard;
// void CNWSCreature::GetLastPerceptionInaudiblevoid
extern void * const CNWSCreature__GetLastPerceptionInaudible;
// void CNWSCreature::GetLastPerceptionSeenvoid
extern void * const CNWSCreature__GetLastPerceptionSeen;
// void CNWSCreature::GetLastPerceptionVanishedvoid
extern void * const CNWSCreature__GetLastPerceptionVanished;
// void CNWSCreature::GetLastPickupFailedvoid
extern void * const CNWSCreature__GetLastPickupFailed;
// void CNWSCreature::GetLastSpellCastItemvoid
extern void * const CNWSCreature__GetLastSpellCastItem;
// void CNWSCreature::GetLastSpellProjectileTimevoid
extern void * const CNWSCreature__GetLastSpellProjectileTime;
// void CNWSCreature::GetLastSpellUnReadiedvoid
extern void * const CNWSCreature__GetLastSpellUnReadied;
// void CNWSCreature::GetLastSpotRollvoid
extern void * const CNWSCreature__GetLastSpotRoll;
// void CNWSCreature::GetLastTrapDetectedvoid
extern void * const CNWSCreature__GetLastTrapDetected;
// public float CNWSCreature::GetListenCheckDistancevoid
extern void * const CNWSCreature__GetListenCheckDistance;
// void CNWSCreature::GetLockAnimationPlayedvoid
extern void * const CNWSCreature__GetLockAnimationPlayed;
// public unsigned long int CNWSCreature::GetLockOrientationToObjectvoid
extern void * const CNWSCreature__GetLockOrientationToObject;
// void CNWSCreature::GetLootablevoid
extern void * const CNWSCreature__GetLootable;
// void CNWSCreature::GetMagicalArrowsEquippedvoid
extern void * const CNWSCreature__GetMagicalArrowsEquipped;
// void CNWSCreature::GetMagicalBoltsEquippedvoid
extern void * const CNWSCreature__GetMagicalBoltsEquipped;
// void CNWSCreature::GetMagicalBulletsEquippedvoid
extern void * const CNWSCreature__GetMagicalBulletsEquipped;
// void CNWSCreature::GetMasterIdvoid
extern void * const CNWSCreature__GetMasterId;
// public short int CNWSCreature::GetMaxHitPointsint
extern void * const CNWSCreature__GetMaxHitPoints;
// public int CNWSCreature::GetModeunsigned char
extern void * const CNWSCreature__GetMode;
// public CExoString CNWSCreature::GetModelTypevoid
extern void * const CNWSCreature__GetModelType;
// public float CNWSCreature::GetMovementRateFactorvoid
extern void * const CNWSCreature__GetMovementRateFactor;
// public unsigned long int CNWSCreature::GetNearestEnemyfloat, unsigned long int, int, int
extern void * const CNWSCreature__GetNearestEnemy;
// void CNWSCreature::GetNonPolymorphCONBasevoid
extern void * const CNWSCreature__GetNonPolymorphCONBase;
// void CNWSCreature::GetNonPolymorphDEXBasevoid
extern void * const CNWSCreature__GetNonPolymorphDEXBase;
// void CNWSCreature::GetNonPolymorphSTRBasevoid
extern void * const CNWSCreature__GetNonPolymorphSTRBase;
// void CNWSCreature::GetNoPermDeathvoid
extern void * const CNWSCreature__GetNoPermDeath;
// void CNWSCreature::GetNumAreasvoid
extern void * const CNWSCreature__GetNumAreas;
// void CNWSCreature::GetNumAssociatesOfTypeunsigned short int
extern void * const CNWSCreature__GetNumAssociatesOfType;
// void CNWSCreature::GetNumCharSheetViewersvoid
extern void * const CNWSCreature__GetNumCharSheetViewers;
// public int CNWSCreature::GetNumCounterSpellingCreaturesunsigned long int
extern void * const CNWSCreature__GetNumCounterSpellingCreatures;
// public int CNWSCreature::GetNumInvitedvoid
extern void * const CNWSCreature__GetNumInvited;
// void CNWSCreature::GetOnCreationScriptExecutedvoid
extern void * const CNWSCreature__GetOnCreationScriptExecuted;
// void CNWSCreature::GetOriginalFactionIdvoid
extern void * const CNWSCreature__GetOriginalFactionId;
// void CNWSCreature::GetPassiveAttackBehaviourvoid
extern void * const CNWSCreature__GetPassiveAttackBehaviour;
// void CNWSCreature::GetPathfindInformationvoid
extern void * const CNWSCreature__GetPathfindInformation;
// void CNWSCreature::GetPendingRealizationvoid
extern void * const CNWSCreature__GetPendingRealization;
// void CNWSCreature::GetPersonalReputationListvoid
extern void * const CNWSCreature__GetPersonalReputationList;
// void CNWSCreature::GetPickUpItemAnimationPlayedvoid
extern void * const CNWSCreature__GetPickUpItemAnimationPlayed;
// void CNWSCreature::GetPlayerCharactervoid
extern void * const CNWSCreature__GetPlayerCharacter;
// void CNWSCreature::GetPolymorphSpellId1void
extern void * const CNWSCreature__GetPolymorphSpellId1;
// void CNWSCreature::GetPolymorphSpellId2void
extern void * const CNWSCreature__GetPolymorphSpellId2;
// void CNWSCreature::GetPolymorphSpellId3void
extern void * const CNWSCreature__GetPolymorphSpellId3;
// void CNWSCreature::GetPonyRidevoid
extern void * const CNWSCreature__GetPonyRide;
// public CResRef CNWSCreature::GetPortraitvoid
extern void * const CNWSCreature__GetPortrait;
// void CNWSCreature::GetPreDominationFactionIdvoid
extern void * const CNWSCreature__GetPreDominationFactionId;
// void CNWSCreature::GetPreferredAttackDistancevoid
extern void * const CNWSCreature__GetPreferredAttackDistance;
// void CNWSCreature::GetPrePolymorphCONvoid
extern void * const CNWSCreature__GetPrePolymorphCON;
// void CNWSCreature::GetPrePolymorphDEXvoid
extern void * const CNWSCreature__GetPrePolymorphDEX;
// void CNWSCreature::GetPrePolymorphSTRvoid
extern void * const CNWSCreature__GetPrePolymorphSTR;
// void CNWSCreature::GetPVPListvoid
extern void * const CNWSCreature__GetPVPList;
// public int CNWSCreature::GetPVPPlayerLikesMeunsigned long int
extern void * const CNWSCreature__GetPVPPlayerLikesMe;
// void CNWSCreature::GetPVPReputationunsigned long int
extern void * const CNWSCreature__GetPVPReputation;
// public CNWSQuickbarButton* CNWSCreature::GetQuickbarButtonunsigned char
extern void * const CNWSCreature__GetQuickbarButton;
// void CNWSCreature::GetQuickbarInitializedvoid
extern void * const CNWSCreature__GetQuickbarInitialized;
// public int CNWSCreature::GetRangeWeaponEquippedvoid
extern void * const CNWSCreature__GetRangeWeaponEquipped;
// public int CNWSCreature::GetRelativeWeaponSizeCNWSItem*
extern void * const CNWSCreature__GetRelativeWeaponSize;
// void CNWSCreature::GetRepositoryArrayIndexvoid
extern void * const CNWSCreature__GetRepositoryArrayIndex;
// void CNWSCreature::GetReputationListvoid
extern void * const CNWSCreature__GetReputationList;
// public float CNWSCreature::GetRunRatevoid
extern void * const CNWSCreature__GetRunRate;
// void CNWSCreature::GetScriptNameint
extern void * const CNWSCreature__GetScriptName;
// void CNWSCreature::GetSilentvoid
extern void * const CNWSCreature__GetSilent;
// void CNWSCreature::GetSittingObjectvoid
extern void * const CNWSCreature__GetSittingObject;
// void CNWSCreature::GetSlowedvoid
extern void * const CNWSCreature__GetSlowed;
// void CNWSCreature::GetSoundSetvoid
extern void * const CNWSCreature__GetSoundSet;
// void CNWSCreature::GetSpellIdentifiedListvoid
extern void * const CNWSCreature__GetSpellIdentifiedList;
// public int CNWSCreature::GetSpellOrHealActionQueuedvoid
extern void * const CNWSCreature__GetSpellOrHealActionQueued;
// void CNWSCreature::GetSpellTargetvoid
extern void * const CNWSCreature__GetSpellTarget;
// public float CNWSCreature::GetSpotCheckDistancevoid
extern void * const CNWSCreature__GetSpotCheckDistance;
// public int CNWSCreature::GetStandardFactionReputationint
extern void * const CNWSCreature__GetStandardFactionReputation;
// public CNWSCreatureStats* CNWSCreature::GetStatsvoid
extern void * const CNWSCreature__GetStats;
// void CNWSCreature::GetStealAnimationPlayedvoid
extern void * const CNWSCreature__GetStealAnimationPlayed;
// void CNWSCreature::GetStealAttemptDetectedvoid
extern void * const CNWSCreature__GetStealAttemptDetected;
// void CNWSCreature::GetStealthModevoid
extern void * const CNWSCreature__GetStealthMode;
// void CNWSCreature::GetSummonedAnimalCompanionvoid
extern void * const CNWSCreature__GetSummonedAnimalCompanion;
// void CNWSCreature::GetSummonedCreatureIdvoid
extern void * const CNWSCreature__GetSummonedCreatureId;
// void CNWSCreature::GetSummonedFamiliarvoid
extern void * const CNWSCreature__GetSummonedFamiliar;
// void CNWSCreature::GetTauntvoid
extern void * const CNWSCreature__GetTaunt;
// void CNWSCreature::GetTauntAnimationPlayedvoid
extern void * const CNWSCreature__GetTauntAnimationPlayed;
// public int CNWSCreature::GetTileExploredunsigned long int, int, int
extern void * const CNWSCreature__GetTileExplored;
// public int CNWSCreature::GetTotalEffectBonusunsigned char, CNWSObject*, int, int, unsigned char, unsigned char, unsigned char, unsigned char, int
extern void * const CNWSCreature__GetTotalEffectBonus;
// void CNWSCreature::GetTotalWeightCarriedvoid
extern void * const CNWSCreature__GetTotalWeightCarried;
// void CNWSCreature::GetTrapAnimationPlayedvoid
extern void * const CNWSCreature__GetTrapAnimationPlayed;
// public int CNWSCreature::GetTurnResistanceHDvoid
extern void * const CNWSCreature__GetTurnResistanceHD;
// public int CNWSCreature::GetUnarmedvoid
extern void * const CNWSCreature__GetUnarmed;
// void CNWSCreature::GetUnlockAnimationPlayedvoid
extern void * const CNWSCreature__GetUnlockAnimationPlayed;
// void CNWSCreature::GetUpdateCombatInformationvoid
extern void * const CNWSCreature__GetUpdateCombatInformation;
// void CNWSCreature::GetUpdateDisplayNamevoid
extern void * const CNWSCreature__GetUpdateDisplayName;
// public int CNWSCreature::GetUseMonkAbilitiesvoid
extern void * const CNWSCreature__GetUseMonkAbilities;
// public int CNWSCreature::GetUseRangeunsigned long int, Vector&, float&
extern void * const CNWSCreature__GetUseRange;
// void CNWSCreature::GetVisibilityListvoid
extern void * const CNWSCreature__GetVisibilityList;
// public CNWVisibilityNode* CNWSCreature::GetVisibleListElementunsigned long int
extern void * const CNWSCreature__GetVisibleListElement;
// void CNWSCreature::GetVisionTypevoid
extern void * const CNWSCreature__GetVisionType;
// void CNWSCreature::GetWalkAnimationvoid
extern void * const CNWSCreature__GetWalkAnimation;
// public float CNWSCreature::GetWalkRatevoid
extern void * const CNWSCreature__GetWalkRate;
// public int CNWSCreature::GetWeaponPowerCNWSObject*, int
extern void * const CNWSCreature__GetWeaponPower;
// void CNWSCreature::GetWeaponScalevoid
extern void * const CNWSCreature__GetWeaponScale;
// public int CNWSCreature::HandleSubAreaStateChangesCExoArrayListTemplatedunsignedlong*, CExoArrayListTemplatedunsignedlong*, int
extern void * const CNWSCreature__HandleSubAreaStateChanges;
// protected void CNWSCreature::InitialisePVPListvoid
extern void * const CNWSCreature__InitialisePVPList;
// public void CNWSCreature::InitializeQuickbarvoid
extern void * const CNWSCreature__InitializeQuickbar;
// void CNWSCreature::IsAIStateunsigned short int
extern void * const CNWSCreature__IsAIState;
// void CNWSCreature::IsHelplessvoid
extern void * const CNWSCreature__IsHelpless;
// public int CNWSCreature::LearnScrollunsigned long int
extern void * const CNWSCreature__LearnScroll;
// public void CNWSCreature::LoadAssociateListCResGFF*, CResStruct*
extern void * const CNWSCreature__LoadAssociateList;
// public void CNWSCreature::LoadAutoMapDataCResGFF*, CResStruct*
extern void * const CNWSCreature__LoadAutoMapData;
// public int CNWSCreature::LoadCreatureCResGFF*, CResStruct*, int, int, int, int
extern void * const CNWSCreature__LoadCreature;
// public int CNWSCreature::LoadFromTemplateCResRef, CExoString*
extern void * const CNWSCreature__LoadFromTemplate;
// public void CNWSCreature::LoadPersonalReputationListCResGFF*, CResStruct*
extern void * const CNWSCreature__LoadPersonalReputationList;
// public int CNWSCreature::LoadPolymorphDataCResGFF*, CResStruct*, int
extern void * const CNWSCreature__LoadPolymorphData;
// public void CNWSCreature::LoadQuickBarHackCExoString
extern void * const CNWSCreature__LoadQuickBarHack;
// public void CNWSCreature::LoadQuickButtonsCResGFF*, CResStruct*
extern void * const CNWSCreature__LoadQuickButtons;
// public float CNWSCreature::MaxAttackRangeunsigned long int, int, int
extern void * const CNWSCreature__MaxAttackRange;
// public void CNWSCreature::MergeItemCNWSItem*, CNWSItem*
extern void * const CNWSCreature__MergeItem;
// public void CNWSCreature::NotifyAssociateActionToggleint
extern void * const CNWSCreature__NotifyAssociateActionToggle;
// public void CNWSCreature::PacifyCreaturevoid
extern void * const CNWSCreature__PacifyCreature__0;
// public void CNWSCreature::PacifyCreatureunsigned long int
extern void * const CNWSCreature__PacifyCreature__1;
// public void CNWSCreature::PayToIdentifyItemunsigned long int, unsigned long int
extern void * const CNWSCreature__PayToIdentifyItem;
// public int CNWSCreature::Polymorphint, CGameEffect*, int
extern void * const CNWSCreature__Polymorph;
// public void CNWSCreature::PossessCreatureunsigned long int
extern void * const CNWSCreature__PossessCreature;
// public void CNWSCreature::PossessCreatureDMunsigned long int, unsigned char
extern void * const CNWSCreature__PossessCreatureDM;
// public void CNWSCreature::PossessFamiliarvoid
extern void * const CNWSCreature__PossessFamiliar;
// public void CNWSCreature::PostProcessvoid
extern void * const CNWSCreature__PostProcess;
// public void CNWSCreature::ProcessMasterDeathForAssociatesvoid
extern void * const CNWSCreature__ProcessMasterDeathForAssociates;
// public void CNWSCreature::ProcessPendingCombatActionsvoid
extern void * const CNWSCreature__ProcessPendingCombatActions;
// public void CNWSCreature::QuickbarButton_RemoveItemunsigned long int
extern void * const CNWSCreature__QuickbarButton_RemoveItem;
// public void CNWSCreature::QuickbarButton_RemoveSpellunsigned long int
extern void * const CNWSCreature__QuickbarButton_RemoveSpell;
// public void CNWSCreature::ReadItemsFromGffCResGFF*, CResStruct*, int, int
extern void * const CNWSCreature__ReadItemsFromGff;
// public void CNWSCreature::ReadScriptsFromGffCResGFF*, CResStruct*
extern void * const CNWSCreature__ReadScriptsFromGff;
// public void CNWSCreature::RealizeAssociateListvoid
extern void * const CNWSCreature__RealizeAssociateList;
// public void CNWSCreature::ReceiveAssociateCommandint
extern void * const CNWSCreature__ReceiveAssociateCommand;
// public void CNWSCreature::RecomputeAmbientAnimationStatevoid
extern void * const CNWSCreature__RecomputeAmbientAnimationState;
// public void CNWSCreature::RelayQuickChatCommandToAssociatesunsigned short int
extern void * const CNWSCreature__RelayQuickChatCommandToAssociates;
// public void CNWSCreature::RemoveAllAssociatesvoid
extern void * const CNWSCreature__RemoveAllAssociates;
// void CNWSCreature::RemoveAreaOfEffectunsigned long int
extern void * const CNWSCreature__RemoveAreaOfEffect;
// public void CNWSCreature::RemoveAssociateunsigned long int
extern void * const CNWSCreature__RemoveAssociate;
// public void CNWSCreature::RemoveBadEffectsvoid
extern void * const CNWSCreature__RemoveBadEffects;
// public int CNWSCreature::RemoveCharmEffectsByFactionIDint, int
extern void * const CNWSCreature__RemoveCharmEffectsByFactionID;
// void CNWSCreature::RemoveCharmEffectsByOBJECTIDunsigned long int, int
extern void * const CNWSCreature__RemoveCharmEffectsByOBJECTID;
// public void CNWSCreature::RemoveCombatInvisibilityEffectsvoid
extern void * const CNWSCreature__RemoveCombatInvisibilityEffects;
// public void CNWSCreature::RemoveDominationvoid
extern void * const CNWSCreature__RemoveDomination;
// void CNWSCreature::RemoveDominationEffectvoid
extern void * const CNWSCreature__RemoveDominationEffect;
// public void CNWSCreature::RemoveFromAreaint
extern void * const CNWSCreature__RemoveFromArea;
// void CNWSCreature::RemoveFromAssociateListunsigned long int
extern void * const CNWSCreature__RemoveFromAssociateList;
// void CNWSCreature::RemoveFromInvitationsOfferedunsigned long int
extern void * const CNWSCreature__RemoveFromInvitationsOffered;
// public void CNWSCreature::RemoveFromPVPListunsigned long int
extern void * const CNWSCreature__RemoveFromPVPList;
// public void CNWSCreature::RemoveFromVisibleListunsigned long int
extern void * const CNWSCreature__RemoveFromVisibleList;
// public void CNWSCreature::RemoveGoldint, int
extern void * const CNWSCreature__RemoveGold;
// public int CNWSCreature::RemoveItemCNWSItem*, int, int, int, int
extern void * const CNWSCreature__RemoveItem;
// public int CNWSCreature::RemoveItemFromRepositoryCNWSItem*, int
extern void * const CNWSCreature__RemoveItemFromRepository;
// public void CNWSCreature::RemoveSleepEffectsvoid
extern void * const CNWSCreature__RemoveSleepEffects;
// public void CNWSCreature::RemoveSpellActionFromRoundvoid
extern void * const CNWSCreature__RemoveSpellActionFromRound;
// public void CNWSCreature::RemoveWoundingEffectsvoid
extern void * const CNWSCreature__RemoveWoundingEffects;
// public int CNWSCreature::ReplyToInvitationint, unsigned long int
extern void * const CNWSCreature__ReplyToInvitation;
// protected void CNWSCreature::ReprocessAssociateListvoid
extern void * const CNWSCreature__ReprocessAssociateList;
// public int CNWSCreature::RequestBuyunsigned long int, unsigned long int, unsigned long int
extern void * const CNWSCreature__RequestBuy;
// public int CNWSCreature::RequestSellunsigned long int, unsigned long int
extern void * const CNWSCreature__RequestSell;
// public void CNWSCreature::ResetItemPossessorvoid
extern void * const CNWSCreature__ResetItemPossessor;
// public void CNWSCreature::ResetPCDominatedScriptsvoid
extern void * const CNWSCreature__ResetPCDominatedScripts;
// public void CNWSCreature::ResetUpdateTimesunsigned long int, unsigned long int
extern void * const CNWSCreature__ResetUpdateTimes;
// protected void CNWSCreature::ResolveAmmunitionunsigned long int
extern void * const CNWSCreature__ResolveAmmunition;
// protected void CNWSCreature::ResolveAttackunsigned long int, int, int
extern void * const CNWSCreature__ResolveAttack;
// protected void CNWSCreature::ResolveAttackRollCNWSObject*
extern void * const CNWSCreature__ResolveAttackRoll;
// protected void CNWSCreature::ResolveCachedSpecialAttacksvoid
extern void * const CNWSCreature__ResolveCachedSpecialAttacks;
// protected void CNWSCreature::ResolveDamageCNWSObject*
extern void * const CNWSCreature__ResolveDamage;
// public void CNWSCreature::ResolveDamageShieldsCNWSCreature*
extern void * const CNWSCreature__ResolveDamageShields;
// protected void CNWSCreature::ResolveDeathAttackCNWSCreature*
extern void * const CNWSCreature__ResolveDeathAttack;
// public int CNWSCreature::ResolveDefensiveEffectsCNWSObject*, int
extern void * const CNWSCreature__ResolveDefensiveEffects;
// void CNWSCreature::ResolveElementalDamageCNWSObject*
extern void * const CNWSCreature__ResolveElementalDamage;
// public void CNWSCreature::ResolveInitiativevoid
extern void * const CNWSCreature__ResolveInitiative;
// protected void CNWSCreature::ResolveItemCastSpellCNWSObject*
extern void * const CNWSCreature__ResolveItemCastSpell;
// protected void CNWSCreature::ResolveMeleeAnimationsint, int, CNWSObject*, int
extern void * const CNWSCreature__ResolveMeleeAnimations;
// protected void CNWSCreature::ResolveMeleeAttackCNWSObject*, int, int
extern void * const CNWSCreature__ResolveMeleeAttack;
// protected void CNWSCreature::ResolveMeleeSpecialAttackint, int, CNWSObject*, int
extern void * const CNWSCreature__ResolveMeleeSpecialAttack;
// protected void CNWSCreature::ResolveOnHitEffectCNWSObject*, int, int
extern void * const CNWSCreature__ResolveOnHitEffect;
// protected void CNWSCreature::ResolveOnHitVisualsCNWSObject*
extern void * const CNWSCreature__ResolveOnHitVisuals;
// protected void CNWSCreature::ResolvePostMeleeDamageCNWSObject*
extern void * const CNWSCreature__ResolvePostMeleeDamage;
// protected void CNWSCreature::ResolvePostRangedDamageCNWSObject*
extern void * const CNWSCreature__ResolvePostRangedDamage;
// protected void CNWSCreature::ResolveRangedAnimationsCNWSObject*, int
extern void * const CNWSCreature__ResolveRangedAnimations;
// protected void CNWSCreature::ResolveRangedAttackCNWSObject*, int, int
extern void * const CNWSCreature__ResolveRangedAttack;
// protected void CNWSCreature::ResolveRangedMissCNWSObject*
extern void * const CNWSCreature__ResolveRangedMiss;
// protected void CNWSCreature::ResolveRangedSpecialAttackCNWSObject*, int
extern void * const CNWSCreature__ResolveRangedSpecialAttack;
// protected void CNWSCreature::ResolveSafeProjectileunsigned long int, int
extern void * const CNWSCreature__ResolveSafeProjectile;
// protected void CNWSCreature::ResolveSituationalModifiersCNWSObject*
extern void * const CNWSCreature__ResolveSituationalModifiers;
// protected void CNWSCreature::ResolveSneakAttackCNWSCreature*
extern void * const CNWSCreature__ResolveSneakAttack;
// public void CNWSCreature::Restint, int
extern void * const CNWSCreature__Rest;
// public void CNWSCreature::RestoreCutsceneVarsvoid
extern void * const CNWSCreature__RestoreCutsceneVars;
// public void CNWSCreature::RestoreItemPropertiesvoid
extern void * const CNWSCreature__RestoreItemProperties;
// protected void CNWSCreature::RestoreItemPropertiesInRepositoryCItemRepository*
extern void * const CNWSCreature__RestoreItemPropertiesInRepository;
// public int CNWSCreature::RunEquipunsigned long int, unsigned long int, unsigned long int
extern void * const CNWSCreature__RunEquip;
// public int CNWSCreature::RunUnequipunsigned long int, unsigned long int, unsigned char, unsigned char, int, unsigned long int
extern void * const CNWSCreature__RunUnequip;
// public void CNWSCreature::SaveAssociateListCResGFF*, CResStruct*
extern void * const CNWSCreature__SaveAssociateList;
// public void CNWSCreature::SaveAutoMapDataCResGFF*, CResStruct*
extern void * const CNWSCreature__SaveAutoMapData;
// public int CNWSCreature::SaveCreatureCResGFF*, CResStruct*, int, int, int
extern void * const CNWSCreature__SaveCreature;
// public void CNWSCreature::SavePersonalReputationListCResGFF*, CResStruct*
extern void * const CNWSCreature__SavePersonalReputationList;
// public void CNWSCreature::SaveQuickBarHackCExoString
extern void * const CNWSCreature__SaveQuickBarHack;
// protected void CNWSCreature::SaveQuickButtonsCResGFF*, CResStruct*
extern void * const CNWSCreature__SaveQuickButtons;
// public unsigned char CNWSCreature::SavingThrowRollunsigned char, unsigned short int, unsigned char, unsigned long int, int, unsigned short int, int
extern void * const CNWSCreature__SavingThrowRoll;
// public void CNWSCreature::SawTrapInformAssociatesunsigned long int
extern void * const CNWSCreature__SawTrapInformAssociates;
// public void CNWSCreature::SendFeedbackMessageunsigned short int, CNWCCMessageData*, CNWSPlayer*
extern void * const CNWSCreature__SendFeedbackMessage;
// public void CNWSCreature::SendFeedbackStringCExoString, CNWSPlayer*
extern void * const CNWSCreature__SendFeedbackString;
// public void CNWSCreature::SetActivityint, int
extern void * const CNWSCreature__SetActivity;
// void CNWSCreature::SetActivityLockedunsigned long int, int
extern void * const CNWSCreature__SetActivityLocked;
// void CNWSCreature::SetAIStateunsigned short int
extern void * const CNWSCreature__SetAIState;
// void CNWSCreature::SetAIStateFlagunsigned short int, int
extern void * const CNWSCreature__SetAIStateFlag;
// void CNWSCreature::SetAlivevoid
extern void * const CNWSCreature__SetAlive;
// public void CNWSCreature::SetAllTilesExploredunsigned long int, int
extern void * const CNWSCreature__SetAllTilesExplored;
// void CNWSCreature::SetAlreadyRemovedFromEncounterint
extern void * const CNWSCreature__SetAlreadyRemovedFromEncounter;
// void CNWSCreature::SetAmbientAnimationStateunsigned char
extern void * const CNWSCreature__SetAmbientAnimationState;
// void CNWSCreature::SetAnimalCompanionCreatureTypeint
extern void * const CNWSCreature__SetAnimalCompanionCreatureType;
// public void CNWSCreature::SetAnimalCompanionNameCExoString
extern void * const CNWSCreature__SetAnimalCompanionName;
// public void CNWSCreature::SetAnimationint
extern void * const CNWSCreature__SetAnimation;
// public void CNWSCreature::SetAssociateListenPatternsvoid
extern void * const CNWSCreature__SetAssociateListenPatterns;
// protected void CNWSCreature::SetAssociatesToForgetAggressionunsigned long int
extern void * const CNWSCreature__SetAssociatesToForgetAggression;
// public void CNWSCreature::SetAssociateTypeunsigned short int
extern void * const CNWSCreature__SetAssociateType;
// void CNWSCreature::SetAttackTargetunsigned long int
extern void * const CNWSCreature__SetAttackTarget;
// void CNWSCreature::SetAttemptedAttackTargetunsigned long int
extern void * const CNWSCreature__SetAttemptedAttackTarget;
// void CNWSCreature::SetAttemptedSpellTargetunsigned long int
extern void * const CNWSCreature__SetAttemptedSpellTarget;
// public void CNWSCreature::SetAutoMapDataint, unsigned long int*, unsigned char**
extern void * const CNWSCreature__SetAutoMapData;
// void CNWSCreature::SetBlindsightDistancefloat
extern void * const CNWSCreature__SetBlindsightDistance;
// void CNWSCreature::SetBodyBagunsigned char
extern void * const CNWSCreature__SetBodyBag;
// void CNWSCreature::SetBodyBagIdunsigned long int
extern void * const CNWSCreature__SetBodyBagId;
// void CNWSCreature::SetBroadcastedAOOToint
extern void * const CNWSCreature__SetBroadcastedAOOTo;
// void CNWSCreature::SetCalculateNPCWeightint
extern void * const CNWSCreature__SetCalculateNPCWeight;
// public void CNWSCreature::SetCombatModeunsigned char, int
extern void * const CNWSCreature__SetCombatMode;
// public void CNWSCreature::SetCombatStateint
extern void * const CNWSCreature__SetCombatState;
// void CNWSCreature::SetCounterSpellTargetunsigned long int
extern void * const CNWSCreature__SetCounterSpellTarget;
// void CNWSCreature::SetCreatureSizeint
extern void * const CNWSCreature__SetCreatureSize;
// void CNWSCreature::SetCreatureStateunsigned char
extern void * const CNWSCreature__SetCreatureState;
// void CNWSCreature::SetCurrentItemContainerunsigned long int
extern void * const CNWSCreature__SetCurrentItemContainer;
// void CNWSCreature::SetCutsceneCameraModeint
extern void * const CNWSCreature__SetCutsceneCameraMode;
// void CNWSCreature::SetCutsceneCameraMovementRateFactorfloat
extern void * const CNWSCreature__SetCutsceneCameraMovementRateFactor;
// void CNWSCreature::SetCutsceneGhostint
extern void * const CNWSCreature__SetCutsceneGhost;
// void CNWSCreature::SetDeadvoid
extern void * const CNWSCreature__SetDead;
// void CNWSCreature::SetDecayTimeunsigned long int
extern void * const CNWSCreature__SetDecayTime;
// public void CNWSCreature::SetDefensiveCastingModeunsigned char
extern void * const CNWSCreature__SetDefensiveCastingMode;
// void CNWSCreature::SetDesiredAreaIdunsigned long int
extern void * const CNWSCreature__SetDesiredAreaId;
// void CNWSCreature::SetDesiredAreaLocationVector
extern void * const CNWSCreature__SetDesiredAreaLocation;
// void CNWSCreature::SetDesiredAreaUpdateCompleteint
extern void * const CNWSCreature__SetDesiredAreaUpdateComplete;
// void CNWSCreature::SetDesiredCombatModeunsigned char
extern void * const CNWSCreature__SetDesiredCombatMode;
// public void CNWSCreature::SetDetectModeunsigned char
extern void * const CNWSCreature__SetDetectMode;
// void CNWSCreature::SetDisarmableint
extern void * const CNWSCreature__SetDisarmable;
// public void CNWSCreature::SetDisplayNameCExoString
extern void * const CNWSCreature__SetDisplayName;
// void CNWSCreature::SetDMCharacterint
extern void * const CNWSCreature__SetDMCharacter;
// void CNWSCreature::SetDriveModeint
extern void * const CNWSCreature__SetDriveMode;
// void CNWSCreature::SetDriveModeMoveFactorfloat
extern void * const CNWSCreature__SetDriveModeMoveFactor;
// void CNWSCreature::SetDropItemAnimationPlayedint
extern void * const CNWSCreature__SetDropItemAnimationPlayed;
// public void CNWSCreature::SetEffectSpellIdunsigned long int
extern void * const CNWSCreature__SetEffectSpellId;
// void CNWSCreature::SetEncounterIdunsigned long int
extern void * const CNWSCreature__SetEncounterId;
// void CNWSCreature::SetEncumbranceStateint
extern void * const CNWSCreature__SetEncumbranceState;
// void CNWSCreature::SetEquipArrayIndexunsigned short int
extern void * const CNWSCreature__SetEquipArrayIndex;
// void CNWSCreature::SetEquippedWeightint
extern void * const CNWSCreature__SetEquippedWeight;
// public void CNWSCreature::SetExcitedStateunsigned char
extern void * const CNWSCreature__SetExcitedState;
// void CNWSCreature::SetExternalCombatModeEnabledint
extern void * const CNWSCreature__SetExternalCombatModeEnabled;
// void CNWSCreature::SetFacingAndAnimationDoneint
extern void * const CNWSCreature__SetFacingAndAnimationDone;
// void CNWSCreature::SetFactionIdint
extern void * const CNWSCreature__SetFactionId;
// void CNWSCreature::SetFamiliarCreatureTypeint
extern void * const CNWSCreature__SetFamiliarCreatureType;
// public void CNWSCreature::SetFamiliarNameCExoString
extern void * const CNWSCreature__SetFamiliarName;
// void CNWSCreature::SetFootstepTypeint
extern void * const CNWSCreature__SetFootstepType;
// void CNWSCreature::SetForcedWalkint
extern void * const CNWSCreature__SetForcedWalk;
// void CNWSCreature::SetGoingToBeAttackedByunsigned long int
extern void * const CNWSCreature__SetGoingToBeAttackedBy;
// public void CNWSCreature::SetGoldint
extern void * const CNWSCreature__SetGold;
// void CNWSCreature::SetHasArmsint
extern void * const CNWSCreature__SetHasArms;
// void CNWSCreature::SetHasLegsint
extern void * const CNWSCreature__SetHasLegs;
// void CNWSCreature::SetHastedint
extern void * const CNWSCreature__SetHasted;
// void CNWSCreature::SetHealAnimationPlayedint
extern void * const CNWSCreature__SetHealAnimationPlayed;
// public void CNWSCreature::SetIdunsigned long int
extern void * const CNWSCreature__SetId;
// void CNWSCreature::SetInitiativeExpiredint
extern void * const CNWSCreature__SetInitiativeExpired;
// void CNWSCreature::SetInitiativeRollunsigned char
extern void * const CNWSCreature__SetInitiativeRoll;
// public void CNWSCreature::SetInTransitint
extern void * const CNWSCreature__SetInTransit;
// public void CNWSCreature::SetInvitedToPartyint
extern void * const CNWSCreature__SetInvitedToParty;
// void CNWSCreature::SetInvitedToPartyByunsigned long int
extern void * const CNWSCreature__SetInvitedToPartyBy;
// void CNWSCreature::SetIsDiseasedint
extern void * const CNWSCreature__SetIsDiseased;
// void CNWSCreature::SetIsImmortalint
extern void * const CNWSCreature__SetIsImmortal;
// void CNWSCreature::SetIsPoisonedint
extern void * const CNWSCreature__SetIsPoisoned;
// void CNWSCreature::SetIsPolymorphedint
extern void * const CNWSCreature__SetIsPolymorphed;
// void CNWSCreature::SetItemCastSpellBroadcastAOOint
extern void * const CNWSCreature__SetItemCastSpellBroadcastAOO;
// void CNWSCreature::SetItemContainerArrayIndexunsigned short int
extern void * const CNWSCreature__SetItemContainerArrayIndex;
// void CNWSCreature::SetJumpedRecentlyint
extern void * const CNWSCreature__SetJumpedRecently;
// void CNWSCreature::SetLastAmmunitionWarningint
extern void * const CNWSCreature__SetLastAmmunitionWarning;
// void CNWSCreature::SetLastAssociateCommandint
extern void * const CNWSCreature__SetLastAssociateCommand;
// void CNWSCreature::SetLastBlockingDoorunsigned long int
extern void * const CNWSCreature__SetLastBlockingDoor;
// void CNWSCreature::SetLastCounterDomainLevelunsigned char
extern void * const CNWSCreature__SetLastCounterDomainLevel;
// void CNWSCreature::SetLastCounterMetaTypeunsigned char
extern void * const CNWSCreature__SetLastCounterMetaType;
// void CNWSCreature::SetLastCounterSpellClassunsigned char
extern void * const CNWSCreature__SetLastCounterSpellClass;
// void CNWSCreature::SetLastCounterSpellIDint
extern void * const CNWSCreature__SetLastCounterSpellID;
// void CNWSCreature::SetLastHearbeatTimeunsigned long int, unsigned long int
extern void * const CNWSCreature__SetLastHearbeatTime;
// void CNWSCreature::SetLastHideRollunsigned char
extern void * const CNWSCreature__SetLastHideRoll;
// void CNWSCreature::SetLastItemCastSpellint
extern void * const CNWSCreature__SetLastItemCastSpell;
// void CNWSCreature::SetLastItemCastSpellLevelint
extern void * const CNWSCreature__SetLastItemCastSpellLevel;
// void CNWSCreature::SetLastListenRollunsigned char
extern void * const CNWSCreature__SetLastListenRoll;
// void CNWSCreature::SetLastMoveSilentlyRollunsigned char
extern void * const CNWSCreature__SetLastMoveSilentlyRoll;
// void CNWSCreature::SetLastPerceivedunsigned long int
extern void * const CNWSCreature__SetLastPerceived;
// void CNWSCreature::SetLastPerceptionHeardint
extern void * const CNWSCreature__SetLastPerceptionHeard;
// void CNWSCreature::SetLastPerceptionInaudibleint
extern void * const CNWSCreature__SetLastPerceptionInaudible;
// void CNWSCreature::SetLastPerceptionSeenint
extern void * const CNWSCreature__SetLastPerceptionSeen;
// void CNWSCreature::SetLastPerceptionVanishedint
extern void * const CNWSCreature__SetLastPerceptionVanished;
// void CNWSCreature::SetLastPickupFailedint
extern void * const CNWSCreature__SetLastPickupFailed;
// void CNWSCreature::SetLastSpellCastItemunsigned long int
extern void * const CNWSCreature__SetLastSpellCastItem;
// void CNWSCreature::SetLastSpellUnReadiedint
extern void * const CNWSCreature__SetLastSpellUnReadied;
// void CNWSCreature::SetLastSpotRollunsigned char
extern void * const CNWSCreature__SetLastSpotRoll;
// void CNWSCreature::SetLastTrapDetectedunsigned long int
extern void * const CNWSCreature__SetLastTrapDetected;
// void CNWSCreature::SetListenCheckDistancefloat
extern void * const CNWSCreature__SetListenCheckDistance;
// void CNWSCreature::SetLockAnimationPlayedint
extern void * const CNWSCreature__SetLockAnimationPlayed;
// public void CNWSCreature::SetLockOrientationToObjectunsigned long int
extern void * const CNWSCreature__SetLockOrientationToObject;
// void CNWSCreature::SetLootableint
extern void * const CNWSCreature__SetLootable;
// void CNWSCreature::SetMagicalArrowsEquippedint
extern void * const CNWSCreature__SetMagicalArrowsEquipped;
// void CNWSCreature::SetMagicalBoltsEquippedint
extern void * const CNWSCreature__SetMagicalBoltsEquipped;
// void CNWSCreature::SetMagicalBulletsEquippedint
extern void * const CNWSCreature__SetMagicalBulletsEquipped;
// void CNWSCreature::SetMasterIdunsigned long int
extern void * const CNWSCreature__SetMasterId;
// void CNWSCreature::SetMaxListenCheckDistancefloat
extern void * const CNWSCreature__SetMaxListenCheckDistance;
// void CNWSCreature::SetMaxSpotCheckDistancefloat
extern void * const CNWSCreature__SetMaxSpotCheckDistance;
// public void CNWSCreature::SetModeunsigned char, int
extern void * const CNWSCreature__SetMode;
// public void CNWSCreature::SetModelTypeCExoString
extern void * const CNWSCreature__SetModelType;
// public void CNWSCreature::SetMovementRateFactorfloat
extern void * const CNWSCreature__SetMovementRateFactor;
// void CNWSCreature::SetNoPermDeathint
extern void * const CNWSCreature__SetNoPermDeath;
// void CNWSCreature::SetNumAreasint
extern void * const CNWSCreature__SetNumAreas;
// void CNWSCreature::SetNumCharSheetViewersint
extern void * const CNWSCreature__SetNumCharSheetViewers;
// void CNWSCreature::SetOnCreationScriptExecutedint
extern void * const CNWSCreature__SetOnCreationScriptExecuted;
// void CNWSCreature::SetOriginalFactionIdint
extern void * const CNWSCreature__SetOriginalFactionId;
// void CNWSCreature::SetPassiveAttackBehaviourint
extern void * const CNWSCreature__SetPassiveAttackBehaviour;
// public void CNWSCreature::SetPCDominatedScriptsvoid
extern void * const CNWSCreature__SetPCDominatedScripts;
// void CNWSCreature::SetPendingRealizationint
extern void * const CNWSCreature__SetPendingRealization;
// void CNWSCreature::SetPersonalReputationCExoArrayListTemplatedCNWSPersonalReputation*
extern void * const CNWSCreature__SetPersonalReputation;
// void CNWSCreature::SetPickUpItemAnimationPlayedint
extern void * const CNWSCreature__SetPickUpItemAnimationPlayed;
// void CNWSCreature::SetPlayerCharacterint
extern void * const CNWSCreature__SetPlayerCharacter;
// void CNWSCreature::SetPolymorphLockedint
extern void * const CNWSCreature__SetPolymorphLocked;
// void CNWSCreature::SetPonyRideint
extern void * const CNWSCreature__SetPonyRide;
// public void CNWSCreature::SetPortraitCResRef
extern void * const CNWSCreature__SetPortrait;
// public void CNWSCreature::SetPortraitIdunsigned short int
extern void * const CNWSCreature__SetPortraitId;
// void CNWSCreature::SetPreDominationFactionIdint
extern void * const CNWSCreature__SetPreDominationFactionId;
// void CNWSCreature::SetPreferredAttackDistancefloat
extern void * const CNWSCreature__SetPreferredAttackDistance;
// void CNWSCreature::SetPrePolymorphCONint
extern void * const CNWSCreature__SetPrePolymorphCON;
// void CNWSCreature::SetPrePolymorphDEXint
extern void * const CNWSCreature__SetPrePolymorphDEX;
// void CNWSCreature::SetPrePolymorphSTRint
extern void * const CNWSCreature__SetPrePolymorphSTR;
// public void CNWSCreature::SetPVPPlayerLikesMeunsigned long int, int, int
extern void * const CNWSCreature__SetPVPPlayerLikesMe;
// public void CNWSCreature::SetQuickbarButton_AssociateCommandunsigned char, int, unsigned short int, unsigned long int
extern void * const CNWSCreature__SetQuickbarButton_AssociateCommand;
// public void CNWSCreature::SetQuickbarButton_CommandLineunsigned char, const CExoString&, const CExoString&
extern void * const CNWSCreature__SetQuickbarButton_CommandLine;
// public void CNWSCreature::SetQuickbarButton_DM_General_ResRefParamunsigned char, unsigned char, const CResRef&
extern void * const CNWSCreature__SetQuickbarButton_DM_General_ResRefParam;
// public void CNWSCreature::SetQuickbarButton_DungeonMaster_CreateCreatureunsigned char, const CResRef&, const CExoString&
extern void * const CNWSCreature__SetQuickbarButton_DungeonMaster_CreateCreature;
// public void CNWSCreature::SetQuickbarButton_DungeonMaster_CreateEncounterunsigned char, const CResRef&, const CExoString&
extern void * const CNWSCreature__SetQuickbarButton_DungeonMaster_CreateEncounter;
// public void CNWSCreature::SetQuickbarButton_DungeonMaster_CreateItemunsigned char, const CResRef&, const CExoString&
extern void * const CNWSCreature__SetQuickbarButton_DungeonMaster_CreateItem;
// public void CNWSCreature::SetQuickbarButton_DungeonMaster_CreatePlaceableunsigned char, const CResRef&, const CExoString&
extern void * const CNWSCreature__SetQuickbarButton_DungeonMaster_CreatePlaceable;
// public void CNWSCreature::SetQuickbarButton_DungeonMaster_CreatePortalunsigned char, const CResRef&, const CExoString&
extern void * const CNWSCreature__SetQuickbarButton_DungeonMaster_CreatePortal;
// public void CNWSCreature::SetQuickbarButton_DungeonMaster_CreateTriggerunsigned char, const CResRef&, const CExoString&
extern void * const CNWSCreature__SetQuickbarButton_DungeonMaster_CreateTrigger;
// public void CNWSCreature::SetQuickbarButton_DungeonMaster_CreateWaypointunsigned char, const CResRef&, const CExoString&
extern void * const CNWSCreature__SetQuickbarButton_DungeonMaster_CreateWaypoint;
// public void CNWSCreature::SetQuickbarButton_GeneralINTParamunsigned char, unsigned char, int
extern void * const CNWSCreature__SetQuickbarButton_GeneralINTParam;
// public void CNWSCreature::SetQuickbarButton_GeneralNoParamunsigned char, unsigned char
extern void * const CNWSCreature__SetQuickbarButton_GeneralNoParam;
// public void CNWSCreature::SetQuickbarButton_Itemunsigned char, unsigned long int, int, unsigned long int
extern void * const CNWSCreature__SetQuickbarButton_Item;
// public void CNWSCreature::SetQuickbarButton_Spellunsigned char, unsigned char, unsigned long int, unsigned char, unsigned char
extern void * const CNWSCreature__SetQuickbarButton_Spell;
// public void CNWSCreature::SetQuickbarButton_SpellLikeAbilityunsigned char, unsigned long int, unsigned char
extern void * const CNWSCreature__SetQuickbarButton_SpellLikeAbility;
// void CNWSCreature::SetRepositoryArrayIndexunsigned short int
extern void * const CNWSCreature__SetRepositoryArrayIndex;
// void CNWSCreature::SetReputationCExoArrayListTemplatedint*
extern void * const CNWSCreature__SetReputation;
// public void CNWSCreature::SetScriptNameint, CExoString
extern void * const CNWSCreature__SetScriptName;
// void CNWSCreature::SetSilentint
extern void * const CNWSCreature__SetSilent;
// void CNWSCreature::SetSittingObjectunsigned long int
extern void * const CNWSCreature__SetSittingObject;
// void CNWSCreature::SetSlowedint
extern void * const CNWSCreature__SetSlowed;
// void CNWSCreature::SetSoundSetunsigned short int
extern void * const CNWSCreature__SetSoundSet;
// void CNWSCreature::SetSpellTargetunsigned long int
extern void * const CNWSCreature__SetSpellTarget;
// void CNWSCreature::SetSpotCheckDistancefloat
extern void * const CNWSCreature__SetSpotCheckDistance;
// public void CNWSCreature::SetStandardFactionReputationint, int
extern void * const CNWSCreature__SetStandardFactionReputation;
// void CNWSCreature::SetStealAnimationPlayedint
extern void * const CNWSCreature__SetStealAnimationPlayed;
// void CNWSCreature::SetStealAttemptDetectedint
extern void * const CNWSCreature__SetStealAttemptDetected;
// public void CNWSCreature::SetStealthModeunsigned char
extern void * const CNWSCreature__SetStealthMode;
// void CNWSCreature::SetSummonedAnimalCompanionint
extern void * const CNWSCreature__SetSummonedAnimalCompanion;
// void CNWSCreature::SetSummonedFamiliarint
extern void * const CNWSCreature__SetSummonedFamiliar;
// void CNWSCreature::SetTauntint
extern void * const CNWSCreature__SetTaunt;
// void CNWSCreature::SetTauntAnimationPlayedint
extern void * const CNWSCreature__SetTauntAnimationPlayed;
// public void CNWSCreature::SetTileExploredunsigned long int, int, int
extern void * const CNWSCreature__SetTileExplored;
// void CNWSCreature::SetTrapAnimationPlayedint
extern void * const CNWSCreature__SetTrapAnimationPlayed;
// void CNWSCreature::SetUnlockAnimationPlayedint
extern void * const CNWSCreature__SetUnlockAnimationPlayed;
// void CNWSCreature::SetUpdateCombatInformationint
extern void * const CNWSCreature__SetUpdateCombatInformation;
// void CNWSCreature::SetUpdateDisplayNameint
extern void * const CNWSCreature__SetUpdateDisplayName;
// void CNWSCreature::SetVisionTypeunsigned char
extern void * const CNWSCreature__SetVisionType;
// void CNWSCreature::SetWalkAnimationunsigned char
extern void * const CNWSCreature__SetWalkAnimation;
// void CNWSCreature::SetWeaponScalefloat
extern void * const CNWSCreature__SetWeaponScale;
// protected void CNWSCreature::SignalMeleeDamageCNWSObject*, int
extern void * const CNWSCreature__SignalMeleeDamage;
// protected void CNWSCreature::SignalRangedDamageCNWSObject*, int
extern void * const CNWSCreature__SignalRangedDamage;
// public void CNWSCreature::SpawnInHeartbeatPerceptionint
extern void * const CNWSCreature__SpawnInHeartbeatPerception;
// public void CNWSCreature::SplitItemCNWSItem*, int
extern void * const CNWSCreature__SplitItem;
// public int CNWSCreature::StartBarterunsigned long int, unsigned long int, int
extern void * const CNWSCreature__StartBarter;
// public void CNWSCreature::StartGuiTimingBarunsigned long int, unsigned char
extern void * const CNWSCreature__StartGuiTimingBar;
// public void CNWSCreature::StopGuiTimingBarvoid
extern void * const CNWSCreature__StopGuiTimingBar;
// public void CNWSCreature::StoreCutsceneVarsvoid
extern void * const CNWSCreature__StoreCutsceneVars;
// public void CNWSCreature::SummonAnimalCompanionvoid
extern void * const CNWSCreature__SummonAnimalCompanion;
// protected void CNWSCreature::SummonAssociateCResRef, CExoString, unsigned short int
extern void * const CNWSCreature__SummonAssociate;
// public void CNWSCreature::SummonFamiliarvoid
extern void * const CNWSCreature__SummonFamiliar;
// void CNWSCreature::TerminateClientSidePathint
extern void * const CNWSCreature__TerminateClientSidePath;
// void CNWSCreature::TestAIStateAsModeint
extern void * const CNWSCreature__TestAIStateAsMode;
// public int CNWSCreature::ToggleModeunsigned char
extern void * const CNWSCreature__ToggleMode;
// public int CNWSCreature::TransferGoldunsigned long int, Vector, unsigned long int, int, unsigned char, unsigned char
extern void * const CNWSCreature__TransferGold;
// public int CNWSCreature::TranslateAddressunsigned long int, int, int, int*, int*
extern void * const CNWSCreature__TranslateAddress;
// public int CNWSCreature::UnequipItemCNWSItem*, int
extern void * const CNWSCreature__UnequipItem;
// public int CNWSCreature::UnPolymorphCGameEffect*
extern void * const CNWSCreature__UnPolymorph;
// public void CNWSCreature::UnpossessCreaturevoid
extern void * const CNWSCreature__UnpossessCreature;
// public void CNWSCreature::UnpossessCreatureDMvoid
extern void * const CNWSCreature__UnpossessCreatureDM;
// public void CNWSCreature::UnpossessFamiliarvoid
extern void * const CNWSCreature__UnpossessFamiliar;
// public void CNWSCreature::UnsummonMyselfvoid
extern void * const CNWSCreature__UnsummonMyself;
// public void CNWSCreature::UpdateActionQueuevoid
extern void * const CNWSCreature__UpdateActionQueue;
// public void CNWSCreature::UpdateAppearanceDependantInfovoid
extern void * const CNWSCreature__UpdateAppearanceDependantInfo;
// public void CNWSCreature::UpdateAppearanceForEquippedItemsvoid
extern void * const CNWSCreature__UpdateAppearanceForEquippedItems;
// protected void CNWSCreature::UpdateAttributesOnEffectCGameEffect*, int
extern void * const CNWSCreature__UpdateAttributesOnEffect;
// public void CNWSCreature::UpdateAutoMapunsigned long int
extern void * const CNWSCreature__UpdateAutoMap;
// protected void CNWSCreature::UpdateCombatRoundTimervoid
extern void * const CNWSCreature__UpdateCombatRoundTimer;
// protected void CNWSCreature::UpdateEffectPtrsvoid
extern void * const CNWSCreature__UpdateEffectPtrs;
// public void CNWSCreature::UpdateEncumbranceStateint
extern void * const CNWSCreature__UpdateEncumbranceState;
// void CNWSCreature::UpdateExcitedStateTimervoid
extern void * const CNWSCreature__UpdateExcitedStateTimer;
// public void CNWSCreature::UpdatePersonalSpacevoid
extern void * const CNWSCreature__UpdatePersonalSpace;
// public int CNWSCreature::UpdateSpecialAttacksvoid
extern void * const CNWSCreature__UpdateSpecialAttacks;
// public int CNWSCreature::UpdateSubareasOnJumpPositionVector, unsigned long int
extern void * const CNWSCreature__UpdateSubareasOnJumpPosition;
// public int CNWSCreature::UpdateSubareasOnMoveToVector, Vector, int, CExoArrayListTemplatedunsignedlong*, int
extern void * const CNWSCreature__UpdateSubareasOnMoveTo;
// protected void CNWSCreature::UpdateTrapCheckvoid
extern void * const CNWSCreature__UpdateTrapCheck;
// void CNWSCreature::UpdateTrapCheckDMvoid
extern void * const CNWSCreature__UpdateTrapCheckDM;
// public void CNWSCreature::UpdateVisibleListvoid
extern void * const CNWSCreature__UpdateVisibleList;
// public int CNWSCreature::UseFeatunsigned short int, unsigned short int, unsigned long int, unsigned long int, Vector*
extern void * const CNWSCreature__UseFeat;
// public int CNWSCreature::UseItemunsigned long int, unsigned char, unsigned char, unsigned long int, Vector, unsigned long int
extern void * const CNWSCreature__UseItem;
// public int CNWSCreature::UseLoreOnItemunsigned long int
extern void * const CNWSCreature__UseLoreOnItem;
// public int CNWSCreature::UseSkillunsigned char, unsigned char, unsigned long int, Vector, unsigned long int, unsigned long int, int
extern void * const CNWSCreature__UseSkill;
// public void CNWSCreature::ValidateCounterSpellDataunsigned long int, unsigned char, unsigned char
extern void * const CNWSCreature__ValidateCounterSpellData;
// protected unsigned long int CNWSCreature::WalkUpdateLocationvoid
extern void * const CNWSCreature__WalkUpdateLocation;
// protected int CNWSCreature::WalkUpdateLocationDistancefloat, Vector*, Vector*, CExoArrayListTemplatedunsignedlong*
extern void * const CNWSCreature__WalkUpdateLocationDistance;
// protected int CNWSCreature::WalkUpdateLocationTestDistanceVector, Vector
extern void * const CNWSCreature__WalkUpdateLocationTestDistance;

// public CNWSCreatureStats::CNWSCreatureStatsCNWSCreature*
extern void * const CNWSCreatureStats__CNWSCreatureStatsCtor;
// public CNWSCreatureStats::~CNWSCreatureStatsvoid
extern void * const CNWSCreatureStats__CNWSCreatureStatsDtor;
// public void CNWSCreatureStats::AddExperienceunsigned long int
extern void * const CNWSCreatureStats__AddExperience;
// public void CNWSCreatureStats::AddFeatunsigned short int
extern void * const CNWSCreatureStats__AddFeat;
// public void CNWSCreatureStats::AddKnownSpellunsigned char, unsigned long int
extern void * const CNWSCreatureStats__AddKnownSpell;
// void CNWSCreatureStats::AddSpellLikeAbilityToListunsigned long int, int, unsigned char
extern void * const CNWSCreatureStats__AddSpellLikeAbilityToList;
// public void CNWSCreatureStats::AdjustAlignmentunsigned char, short int, unsigned long int
extern void * const CNWSCreatureStats__AdjustAlignment;
// public void CNWSCreatureStats::AdjustSpellUsesPerDayvoid
extern void * const CNWSCreatureStats__AdjustSpellUsesPerDay;
// public int CNWSCreatureStats::AutoMemorizeSpellsint
extern void * const CNWSCreatureStats__AutoMemorizeSpells;
// void CNWSCreatureStats::CalcLevelUpNumberFeatsunsigned char, unsigned char, unsigned char&, unsigned char&
extern void * const CNWSCreatureStats__CalcLevelUpNumberFeats;
// public char CNWSCreatureStats::CalcStatModifierunsigned char
extern void * const CNWSCreatureStats__CalcStatModifier;
// public int CNWSCreatureStats::CanChooseFeatunsigned short int, unsigned char, unsigned char, CExoArrayListTemplatedunsignedshort*
extern void * const CNWSCreatureStats__CanChooseFeat;
// public int CNWSCreatureStats::CanLevelUpvoid
extern void * const CNWSCreatureStats__CanLevelUp;
// private int CNWSCreatureStats::CheckSpellSuitabilityint, CNWSpell*, int, int, int, int, int, int, unsigned char&, int
extern void * const CNWSCreatureStats__CheckSpellSuitability;
// void CNWSCreatureStats::ClearFeatsvoid
extern void * const CNWSCreatureStats__ClearFeats;
// public void CNWSCreatureStats::ClearMemorizedSpellSlotunsigned char, unsigned char, unsigned char
extern void * const CNWSCreatureStats__ClearMemorizedSpellSlot;
// public void CNWSCreatureStats::ComputeFeatBonusesCExoArrayListTemplatedunsignedshort*, int, int
extern void * const CNWSCreatureStats__ComputeFeatBonuses;
// public unsigned char CNWSCreatureStats::ComputeNumberKnownSpellsLeftunsigned char, unsigned char
extern void * const CNWSCreatureStats__ComputeNumberKnownSpellsLeft;
// void CNWSCreatureStats::ConfirmDomainSpellunsigned char, unsigned char, unsigned long int
extern void * const CNWSCreatureStats__ConfirmDomainSpell;
// public void CNWSCreatureStats::DecrementFeatRemainingUsesunsigned short int
extern void * const CNWSCreatureStats__DecrementFeatRemainingUses;
// public void CNWSCreatureStats::DecrementSpellsPerDayLeftunsigned char, unsigned char
extern void * const CNWSCreatureStats__DecrementSpellsPerDayLeft;
// void CNWSCreatureStats::FeatAcquiredunsigned short int, CExoArrayListTemplatedunsignedshort*, int
extern void * const CNWSCreatureStats__FeatAcquired;
// public int CNWSCreatureStats::FeatRequirementsMetunsigned short int, CExoArrayListTemplatedunsignedshort*
extern void * const CNWSCreatureStats__FeatRequirementsMet;
// public int CNWSCreatureStats::FeatRequirementsMetAfterLevelUpunsigned short int, CNWLevelStats*, unsigned char
extern void * const CNWSCreatureStats__FeatRequirementsMetAfterLevelUp;
// public char CNWSCreatureStats::GetACNaturalBaseint
extern void * const CNWSCreatureStats__GetACNaturalBase;
// void CNWSCreatureStats::GetAlignmentStringvoid
extern void * const CNWSCreatureStats__GetAlignmentString;
// public short int CNWSCreatureStats::GetArmorClassVersusCNWSCreature*, int
extern void * const CNWSCreatureStats__GetArmorClassVersus;
// public int CNWSCreatureStats::GetAttackModifierVersusCNWSCreature*
extern void * const CNWSCreatureStats__GetAttackModifierVersus;
// public unsigned char CNWSCreatureStats::GetAttacksPerRoundvoid
extern void * const CNWSCreatureStats__GetAttacksPerRound;
// public int CNWSCreatureStats::GetBaseAttackBonusint
extern void * const CNWSCreatureStats__GetBaseAttackBonus;
// public char CNWSCreatureStats::GetBaseFortSavingThrowvoid
extern void * const CNWSCreatureStats__GetBaseFortSavingThrow;
// public char CNWSCreatureStats::GetBaseReflexSavingThrowvoid
extern void * const CNWSCreatureStats__GetBaseReflexSavingThrow;
// public char CNWSCreatureStats::GetBaseWillSavingThrowvoid
extern void * const CNWSCreatureStats__GetBaseWillSavingThrow;
// public unsigned short int CNWSCreatureStats::GetBonusFeatunsigned short int
extern void * const CNWSCreatureStats__GetBonusFeat;
// void CNWSCreatureStats::GetCanUseRelatedCategoryint, int
extern void * const CNWSCreatureStats__GetCanUseRelatedCategory;
// public int CNWSCreatureStats::GetCanUseSkillunsigned char
extern void * const CNWSCreatureStats__GetCanUseSkill;
// public int CNWSCreatureStats::GetCanUseSkillAfterLevelUpunsigned short int, CNWLevelStats*
extern void * const CNWSCreatureStats__GetCanUseSkillAfterLevelUp;
// void CNWSCreatureStats::GetCasterLevelunsigned char
extern void * const CNWSCreatureStats__GetCasterLevel;
// public unsigned char CNWSCreatureStats::GetCHAStatvoid
extern void * const CNWSCreatureStats__GetCHAStat;
// public unsigned char CNWSCreatureStats::GetClassunsigned char
extern void * const CNWSCreatureStats__GetClass;
// public CNWSCreatureStats_ClassInfo* CNWSCreatureStats::GetClassInfounsigned char
extern void * const CNWSCreatureStats__GetClassInfo;
// public unsigned char CNWSCreatureStats::GetClassLevelunsigned char, int
extern void * const CNWSCreatureStats__GetClassLevel;
// public unsigned char CNWSCreatureStats::GetClassNegativeLevelsunsigned char
extern void * const CNWSCreatureStats__GetClassNegativeLevels;
// void CNWSCreatureStats::GetClassStringunsigned char
extern void * const CNWSCreatureStats__GetClassString;
// public unsigned char CNWSCreatureStats::GetCONStatvoid
extern void * const CNWSCreatureStats__GetCONStat;
// public unsigned char CNWSCreatureStats::GetCreatureDamageDiceunsigned char
extern void * const CNWSCreatureStats__GetCreatureDamageDice;
// public unsigned char CNWSCreatureStats::GetCreatureDamageDieunsigned char
extern void * const CNWSCreatureStats__GetCreatureDamageDie;
// public int CNWSCreatureStats::GetCreatureHasTalentint, int, unsigned char
extern void * const CNWSCreatureStats__GetCreatureHasTalent;
// public int CNWSCreatureStats::GetCreatureTalentRandomint, int, int&, int&, unsigned char&, unsigned long int&, int&, unsigned char&, unsigned char&
extern void * const CNWSCreatureStats__GetCreatureTalentRandom;
// public int CNWSCreatureStats::GetCreatureTalentRandomFeatint, int, int&, int&, unsigned char&
extern void * const CNWSCreatureStats__GetCreatureTalentRandomFeat;
// public int CNWSCreatureStats::GetCreatureTalentRandomKnownSpellint, int, int&, int&, unsigned char&, int
extern void * const CNWSCreatureStats__GetCreatureTalentRandomKnownSpell;
// public int CNWSCreatureStats::GetCreatureTalentRandomMemorisedSpellint, int, int&, int&, unsigned char&, int, unsigned char&
extern void * const CNWSCreatureStats__GetCreatureTalentRandomMemorisedSpell;
// public int CNWSCreatureStats::GetCreatureTalentRandomSkillint, int, int&, int&, unsigned char&
extern void * const CNWSCreatureStats__GetCreatureTalentRandomSkill;
// public int CNWSCreatureStats::GetCreatureTalentRandomSpellint, int, int&, int&, unsigned char&, unsigned char&
extern void * const CNWSCreatureStats__GetCreatureTalentRandomSpell;
// public int CNWSCreatureStats::GetCreatureTalentRandomSpellFromItemint, int, int&, int&, unsigned char&, unsigned long int&, int&
extern void * const CNWSCreatureStats__GetCreatureTalentRandomSpellFromItem;
// public int CNWSCreatureStats::GetCreatureTalentRandomSpellLikeAbilityint, int, int&, int&, unsigned char&, unsigned char&
extern void * const CNWSCreatureStats__GetCreatureTalentRandomSpellLikeAbility;
// public int CNWSCreatureStats::GetCriticalHitMultiplierint
extern void * const CNWSCreatureStats__GetCriticalHitMultiplier;
// public int CNWSCreatureStats::GetCriticalHitRollint
extern void * const CNWSCreatureStats__GetCriticalHitRoll;
// public int CNWSCreatureStats::GetDamageBonusCNWSCreature*, int
extern void * const CNWSCreatureStats__GetDamageBonus;
// public int CNWSCreatureStats::GetDamageRollCNWSObject*, int, int, int, int, int
extern void * const CNWSCreatureStats__GetDamageRoll;
// public char CNWSCreatureStats::GetDEXModint
extern void * const CNWSCreatureStats__GetDEXMod;
// public unsigned char CNWSCreatureStats::GetDEXStatvoid
extern void * const CNWSCreatureStats__GetDEXStat;
// public unsigned char CNWSCreatureStats::GetDomain1unsigned char
extern void * const CNWSCreatureStats__GetDomain1;
// public unsigned char CNWSCreatureStats::GetDomain2unsigned char
extern void * const CNWSCreatureStats__GetDomain2;
// public int CNWSCreatureStats::GetEffectImmunityunsigned char, CNWSCreature*
extern void * const CNWSCreatureStats__GetEffectImmunity;
// public unsigned char CNWSCreatureStats::GetEffectiveCRForPotentialLevelvoid
extern void * const CNWSCreatureStats__GetEffectiveCRForPotentialLevel;
// public int CNWSCreatureStats::GetEpicWeaponDevastatingCriticalCNWSItem*
extern void * const CNWSCreatureStats__GetEpicWeaponDevastatingCritical;
// public int CNWSCreatureStats::GetEpicWeaponFocusCNWSItem*
extern void * const CNWSCreatureStats__GetEpicWeaponFocus;
// public int CNWSCreatureStats::GetEpicWeaponOverwhelmingCriticalCNWSItem*
extern void * const CNWSCreatureStats__GetEpicWeaponOverwhelmingCritical;
// public int CNWSCreatureStats::GetEpicWeaponSpecializationCNWSItem*
extern void * const CNWSCreatureStats__GetEpicWeaponSpecialization;
// public unsigned long int CNWSCreatureStats::GetExpNeededForLevelUpvoid
extern void * const CNWSCreatureStats__GetExpNeededForLevelUp;
// public int CNWSCreatureStats::GetFavoredEnemyBonusCNWSCreature*
extern void * const CNWSCreatureStats__GetFavoredEnemyBonus;
// public unsigned short int CNWSCreatureStats::GetFeatunsigned short int
extern void * const CNWSCreatureStats__GetFeat;
// public unsigned char CNWSCreatureStats::GetFeatRemainingUsesunsigned short int
extern void * const CNWSCreatureStats__GetFeatRemainingUses;
// public unsigned char CNWSCreatureStats::GetFeatSourceClassunsigned short int
extern void * const CNWSCreatureStats__GetFeatSourceClass;
// public unsigned char CNWSCreatureStats::GetFeatTotalUsesunsigned short int
extern void * const CNWSCreatureStats__GetFeatTotalUses;
// public char CNWSCreatureStats::GetFortSavingThrowint
extern void * const CNWSCreatureStats__GetFortSavingThrow;
// public CExoString CNWSCreatureStats::GetFullNamevoid
extern void * const CNWSCreatureStats__GetFullName;
// void CNWSCreatureStats::GetHasLostClassAbilitiesunsigned char
extern void * const CNWSCreatureStats__GetHasLostClassAbilities;
// public int CNWSCreatureStats::GetHasSilencedSpellunsigned long int
extern void * const CNWSCreatureStats__GetHasSilencedSpell;
// public int CNWSCreatureStats::GetHasStilledSpellunsigned long int
extern void * const CNWSCreatureStats__GetHasStilledSpell;
// public unsigned long int CNWSCreatureStats::GetHighestLevelKnownvoid
extern void * const CNWSCreatureStats__GetHighestLevelKnown;
// public unsigned short int CNWSCreatureStats::GetHighestLevelOfFeatunsigned short int
extern void * const CNWSCreatureStats__GetHighestLevelOfFeat;
// public unsigned char CNWSCreatureStats::GetHitDieunsigned char, unsigned char
extern void * const CNWSCreatureStats__GetHitDie;
// public unsigned char CNWSCreatureStats::GetINTStatvoid
extern void * const CNWSCreatureStats__GetINTStat;
// public unsigned char CNWSCreatureStats::GetIsClassunsigned char
extern void * const CNWSCreatureStats__GetIsClass;
// public int CNWSCreatureStats::GetIsClassAvailableunsigned char
extern void * const CNWSCreatureStats__GetIsClassAvailable;
// public int CNWSCreatureStats::GetIsDomainSpellunsigned char, unsigned char, unsigned char
extern void * const CNWSCreatureStats__GetIsDomainSpell;
// public int CNWSCreatureStats::GetIsEpitomeOfAlignmentvoid
extern void * const CNWSCreatureStats__GetIsEpitomeOfAlignment;
// void CNWSCreatureStats::GetIsInKnownSpellListunsigned char, unsigned long int
extern void * const CNWSCreatureStats__GetIsInKnownSpellList;
// public int CNWSCreatureStats::GetIsInSpellLikeAbilityListunsigned long int
extern void * const CNWSCreatureStats__GetIsInSpellLikeAbilityList;
// public int CNWSCreatureStats::GetIsWeaponOfChoiceunsigned long int
extern void * const CNWSCreatureStats__GetIsWeaponOfChoice;
// public unsigned long int CNWSCreatureStats::GetKnownSpellunsigned char, unsigned char, unsigned char
extern void * const CNWSCreatureStats__GetKnownSpell;
// void CNWSCreatureStats::GetLargePortraitvoid
extern void * const CNWSCreatureStats__GetLargePortrait;
// public unsigned char CNWSCreatureStats::GetLevelint
extern void * const CNWSCreatureStats__GetLevel;
// public CNWLevelStats* CNWSCreatureStats::GetLevelStatsunsigned char
extern void * const CNWSCreatureStats__GetLevelStats;
// public int CNWSCreatureStats::GetMeetsPrestigeClassRequirementsCNWClass*
extern void * const CNWSCreatureStats__GetMeetsPrestigeClassRequirements;
// public int CNWSCreatureStats::GetMeleeAttackBonusint, int, int
extern void * const CNWSCreatureStats__GetMeleeAttackBonus;
// public int CNWSCreatureStats::GetMeleeDamageBonusint, unsigned char
extern void * const CNWSCreatureStats__GetMeleeDamageBonus;
// public unsigned long int CNWSCreatureStats::GetMemorizedSpellInSlotunsigned char, unsigned char, unsigned char
extern void * const CNWSCreatureStats__GetMemorizedSpellInSlot;
// public unsigned char CNWSCreatureStats::GetMemorizedSpellInSlotMetaTypeunsigned char, unsigned char, unsigned char
extern void * const CNWSCreatureStats__GetMemorizedSpellInSlotMetaType;
// public unsigned char CNWSCreatureStats::GetMemorizedSpellInSlotReadyunsigned char, unsigned char, unsigned char
extern void * const CNWSCreatureStats__GetMemorizedSpellInSlotReady;
// public unsigned char CNWSCreatureStats::GetMemorizedSpellReadyCountunsigned long int
extern void * const CNWSCreatureStats__GetMemorizedSpellReadyCount__0;
// public unsigned char CNWSCreatureStats::GetMemorizedSpellReadyCountunsigned char, unsigned long int, unsigned char*, unsigned char*
extern void * const CNWSCreatureStats__GetMemorizedSpellReadyCount__1;
// public unsigned char CNWSCreatureStats::GetMemorizedSpellReadyCountunsigned char, unsigned long int, unsigned char
extern void * const CNWSCreatureStats__GetMemorizedSpellReadyCount__2;
// public unsigned short int CNWSCreatureStats::GetNumberKnownSpellsunsigned char, unsigned char
extern void * const CNWSCreatureStats__GetNumberKnownSpells;
// public unsigned char CNWSCreatureStats::GetNumberMemorizedSpellSlotsunsigned char, unsigned char
extern void * const CNWSCreatureStats__GetNumberMemorizedSpellSlots;
// public int CNWSCreatureStats::GetNumLevelsOfClassunsigned char, int
extern void * const CNWSCreatureStats__GetNumLevelsOfClass__0;
// public int CNWSCreatureStats::GetNumLevelsOfClassunsigned char
extern void * const CNWSCreatureStats__GetNumLevelsOfClass__1;
// public unsigned char CNWSCreatureStats::GetPotentialLevelvoid
extern void * const CNWSCreatureStats__GetPotentialLevel;
// public unsigned char CNWSCreatureStats::GetPrimaryModunsigned char
extern void * const CNWSCreatureStats__GetPrimaryMod;
// void CNWSCreatureStats::GetRaceStringvoid
extern void * const CNWSCreatureStats__GetRaceString;
// public int CNWSCreatureStats::GetRangedAttackBonusint, int
extern void * const CNWSCreatureStats__GetRangedAttackBonus;
// public int CNWSCreatureStats::GetRangedDamageBonusvoid
extern void * const CNWSCreatureStats__GetRangedDamageBonus;
// public char CNWSCreatureStats::GetReflexSavingThrowint
extern void * const CNWSCreatureStats__GetReflexSavingThrow;
// public unsigned char CNWSCreatureStats::GetSchoolunsigned char
extern void * const CNWSCreatureStats__GetSchool;
// public unsigned char CNWSCreatureStats::GetSimpleAlignmentGoodEvilvoid
extern void * const CNWSCreatureStats__GetSimpleAlignmentGoodEvil;
// public unsigned char CNWSCreatureStats::GetSimpleAlignmentLawChaosvoid
extern void * const CNWSCreatureStats__GetSimpleAlignmentLawChaos;
// public char CNWSCreatureStats::GetSkillRankunsigned char, CNWSObject*, int
extern void * const CNWSCreatureStats__GetSkillRank;
// void CNWSCreatureStats::GetSmallPortraitvoid
extern void * const CNWSCreatureStats__GetSmallPortrait;
// public unsigned char CNWSCreatureStats::GetSpellFailureunsigned char
extern void * const CNWSCreatureStats__GetSpellFailure;
// public unsigned char CNWSCreatureStats::GetSpellGainWithBonusunsigned char, unsigned char
extern void * const CNWSCreatureStats__GetSpellGainWithBonus;
// public unsigned char CNWSCreatureStats::GetSpellGainWithBonusAfterLevelUpunsigned char, unsigned char, CNWLevelStats*, unsigned char, int
extern void * const CNWSCreatureStats__GetSpellGainWithBonusAfterLevelUp;
// public unsigned char CNWSCreatureStats::GetSpellLikeAbilityCasterLevelunsigned long int
extern void * const CNWSCreatureStats__GetSpellLikeAbilityCasterLevel;
// public int CNWSCreatureStats::GetSpellMinAbilityMetunsigned char, unsigned char
extern void * const CNWSCreatureStats__GetSpellMinAbilityMet;
// public char CNWSCreatureStats::GetSpellResistancevoid
extern void * const CNWSCreatureStats__GetSpellResistance;
// public unsigned char CNWSCreatureStats::GetSpellsOfLevelReadyunsigned char, unsigned char
extern void * const CNWSCreatureStats__GetSpellsOfLevelReady;
// public unsigned char CNWSCreatureStats::GetSpellsPerDayLeftunsigned char, unsigned char
extern void * const CNWSCreatureStats__GetSpellsPerDayLeft;
// public unsigned char CNWSCreatureStats::GetSpellUsesLeftunsigned long int, unsigned char, unsigned char, unsigned char
extern void * const CNWSCreatureStats__GetSpellUsesLeft;
// public void CNWSCreatureStats::GetStatBonusesFromFeatsCExoArrayListTemplatedunsignedshort*, int*, unsigned char
extern void * const CNWSCreatureStats__GetStatBonusesFromFeats;
// public float CNWSCreatureStats::GetStatByIdint
extern void * const CNWSCreatureStats__GetStatById;
// public unsigned char CNWSCreatureStats::GetSTRStatvoid
extern void * const CNWSCreatureStats__GetSTRStat;
// void CNWSCreatureStats::GetTagvoid
extern void * const CNWSCreatureStats__GetTag;
// public char CNWSCreatureStats::GetTotalACSkillModvoid
extern void * const CNWSCreatureStats__GetTotalACSkillMod;
// public char CNWSCreatureStats::GetTotalCHABonusvoid
extern void * const CNWSCreatureStats__GetTotalCHABonus;
// public char CNWSCreatureStats::GetTotalCONBonusvoid
extern void * const CNWSCreatureStats__GetTotalCONBonus;
// public char CNWSCreatureStats::GetTotalDEXBonusvoid
extern void * const CNWSCreatureStats__GetTotalDEXBonus;
// public char CNWSCreatureStats::GetTotalINTBonusvoid
extern void * const CNWSCreatureStats__GetTotalINTBonus;
// void CNWSCreatureStats::GetTotalNegativeLevelsvoid
extern void * const CNWSCreatureStats__GetTotalNegativeLevels;
// public char CNWSCreatureStats::GetTotalSTRBonusvoid
extern void * const CNWSCreatureStats__GetTotalSTRBonus;
// public char CNWSCreatureStats::GetTotalWISBonusvoid
extern void * const CNWSCreatureStats__GetTotalWISBonus;
// public unsigned char CNWSCreatureStats::GetUnarmedDamageDicevoid
extern void * const CNWSCreatureStats__GetUnarmedDamageDice;
// public unsigned char CNWSCreatureStats::GetUnarmedDamageDievoid
extern void * const CNWSCreatureStats__GetUnarmedDamageDie;
// public int CNWSCreatureStats::GetUnarmedDamageRollCNWSObject*
extern void * const CNWSCreatureStats__GetUnarmedDamageRoll;
// public int CNWSCreatureStats::GetUseMonkAttackTablesint
extern void * const CNWSCreatureStats__GetUseMonkAttackTables;
// public int CNWSCreatureStats::GetWeaponFinesseCNWSItem*
extern void * const CNWSCreatureStats__GetWeaponFinesse;
// public int CNWSCreatureStats::GetWeaponFocusCNWSItem*
extern void * const CNWSCreatureStats__GetWeaponFocus;
// public int CNWSCreatureStats::GetWeaponImprovedCriticalCNWSItem*
extern void * const CNWSCreatureStats__GetWeaponImprovedCritical;
// public int CNWSCreatureStats::GetWeaponSpecializationCNWSItem*
extern void * const CNWSCreatureStats__GetWeaponSpecialization;
// public char CNWSCreatureStats::GetWillSavingThrowint
extern void * const CNWSCreatureStats__GetWillSavingThrow;
// public unsigned char CNWSCreatureStats::GetWISStatvoid
extern void * const CNWSCreatureStats__GetWISStat;
// public int CNWSCreatureStats::HasFeatunsigned short int
extern void * const CNWSCreatureStats__HasFeat;
// public void CNWSCreatureStats::IncrementFeatRemainingUsesunsigned short int
extern void * const CNWSCreatureStats__IncrementFeatRemainingUses;
// void CNWSCreatureStats::IncrementSpellsPerDayLeftunsigned char, unsigned char
extern void * const CNWSCreatureStats__IncrementSpellsPerDayLeft;
// public void CNWSCreatureStats::LevelDownCNWLevelStats*
extern void * const CNWSCreatureStats__LevelDown;
// public void CNWSCreatureStats::LevelUpCNWLevelStats*, unsigned char, unsigned char, unsigned char, int
extern void * const CNWSCreatureStats__LevelUp;
// public int CNWSCreatureStats::LevelUpAutomaticunsigned char, int, unsigned char
extern void * const CNWSCreatureStats__LevelUpAutomatic;
// public int CNWSCreatureStats::ModifyAlignmentshort int, short int
extern void * const CNWSCreatureStats__ModifyAlignment;
// public void CNWSCreatureStats::ReadSpellsFromGffCResGFF*, CResStruct*, int
extern void * const CNWSCreatureStats__ReadSpellsFromGff;
// public unsigned long int CNWSCreatureStats::ReadStatsFromGffCResGFF*, CResStruct*, CNWSCreatureAppearanceInfo*, int, int, int
extern void * const CNWSCreatureStats__ReadStatsFromGff;
// public void CNWSCreatureStats::ReadySpellLevelunsigned char
extern void * const CNWSCreatureStats__ReadySpellLevel;
// public void CNWSCreatureStats::RemoveFeatunsigned short int
extern void * const CNWSCreatureStats__RemoveFeat;
// void CNWSCreatureStats::RemoveKnownSpellunsigned char, unsigned long int
extern void * const CNWSCreatureStats__RemoveKnownSpell;
// public void CNWSCreatureStats::ResetFeatRemainingUsesvoid
extern void * const CNWSCreatureStats__ResetFeatRemainingUses;
// public void CNWSCreatureStats::ResetSpellLikeAbilitiesvoid
extern void * const CNWSCreatureStats__ResetSpellLikeAbilities;
// void CNWSCreatureStats::ResetSpellsPerDayLeftunsigned char, unsigned char
extern void * const CNWSCreatureStats__ResetSpellsPerDayLeft;
// public int CNWSCreatureStats::ResolveSpecialAttackAttackBonusCNWSCreature*
extern void * const CNWSCreatureStats__ResolveSpecialAttackAttackBonus;
// public int CNWSCreatureStats::ResolveSpecialAttackDamageBonusCNWSCreature*
extern void * const CNWSCreatureStats__ResolveSpecialAttackDamageBonus;
// public void CNWSCreatureStats::SaveClassInfoCResGFF*, CResStruct*
extern void * const CNWSCreatureStats__SaveClassInfo;
// public void CNWSCreatureStats::SaveStatsCResGFF*, CResStruct*
extern void * const CNWSCreatureStats__SaveStats;
// public void CNWSCreatureStats::SetArcaneSpellFailurechar
extern void * const CNWSCreatureStats__SetArcaneSpellFailure;
// public void CNWSCreatureStats::SetCHABaseunsigned char
extern void * const CNWSCreatureStats__SetCHABase;
// void CNWSCreatureStats::SetClassunsigned char, unsigned char
extern void * const CNWSCreatureStats__SetClass;
// void CNWSCreatureStats::SetClassLevelunsigned char, unsigned char
extern void * const CNWSCreatureStats__SetClassLevel;
// public void CNWSCreatureStats::SetClassNegativeLevelsunsigned char, unsigned char
extern void * const CNWSCreatureStats__SetClassNegativeLevels;
// public void CNWSCreatureStats::SetCONBaseunsigned char, int
extern void * const CNWSCreatureStats__SetCONBase;
// public void CNWSCreatureStats::SetDEXBaseunsigned char
extern void * const CNWSCreatureStats__SetDEXBase;
// void CNWSCreatureStats::SetDomain1unsigned char, unsigned char
extern void * const CNWSCreatureStats__SetDomain1;
// void CNWSCreatureStats::SetDomain2unsigned char, unsigned char
extern void * const CNWSCreatureStats__SetDomain2;
// public void CNWSCreatureStats::SetExperienceunsigned long int, int
extern void * const CNWSCreatureStats__SetExperience;
// public void CNWSCreatureStats::SetFeatRemainingUsesunsigned short int, unsigned char
extern void * const CNWSCreatureStats__SetFeatRemainingUses;
// void CNWSCreatureStats::SetHasLostClassAbilitiesunsigned char, int
extern void * const CNWSCreatureStats__SetHasLostClassAbilities;
// public void CNWSCreatureStats::SetINTBaseunsigned char
extern void * const CNWSCreatureStats__SetINTBase;
// void CNWSCreatureStats::SetMemorizedSpellInSlotReadyunsigned char, unsigned char, unsigned char, int
extern void * const CNWSCreatureStats__SetMemorizedSpellInSlotReady;
// public int CNWSCreatureStats::SetMemorizedSpellSlotunsigned char, unsigned char, unsigned long int, unsigned char, unsigned char, int
extern void * const CNWSCreatureStats__SetMemorizedSpellSlot;
// public void CNWSCreatureStats::SetMovementRateint
extern void * const CNWSCreatureStats__SetMovementRate;
// void CNWSCreatureStats::SetNormalBonusFlagsunsigned short int, int&, int&
extern void * const CNWSCreatureStats__SetNormalBonusFlags;
// public void CNWSCreatureStats::SetNumberBonusSpellsunsigned char, unsigned char, unsigned char
extern void * const CNWSCreatureStats__SetNumberBonusSpells;
// void CNWSCreatureStats::SetNumberMemorizedSpellSlotsunsigned char, unsigned char, unsigned char
extern void * const CNWSCreatureStats__SetNumberMemorizedSpellSlots;
// void CNWSCreatureStats::SetSchoolunsigned char, unsigned char
extern void * const CNWSCreatureStats__SetSchool;
// void CNWSCreatureStats::SetSkillRankunsigned char, char
extern void * const CNWSCreatureStats__SetSkillRank;
// public void CNWSCreatureStats::SetSpellFailureunsigned char, unsigned char
extern void * const CNWSCreatureStats__SetSpellFailure;
// public int CNWSCreatureStats::SetSpellLikeAbilityReadyunsigned long int, int, unsigned char
extern void * const CNWSCreatureStats__SetSpellLikeAbilityReady;
// public void CNWSCreatureStats::SetSpellResistancechar
extern void * const CNWSCreatureStats__SetSpellResistance;
// public void CNWSCreatureStats::SetSpellResistancePenaltychar
extern void * const CNWSCreatureStats__SetSpellResistancePenalty;
// public void CNWSCreatureStats::SetStatByIdint, float
extern void * const CNWSCreatureStats__SetStatById;
// public void CNWSCreatureStats::SetSTRBaseunsigned char
extern void * const CNWSCreatureStats__SetSTRBase;
// void CNWSCreatureStats::SetTagconst CExoString&
extern void * const CNWSCreatureStats__SetTag;
// public void CNWSCreatureStats::SetWISBaseunsigned char
extern void * const CNWSCreatureStats__SetWISBase;
// public int CNWSCreatureStats::UnReadySpellunsigned long int, unsigned char, unsigned char, unsigned char
extern void * const CNWSCreatureStats__UnReadySpell;
// public void CNWSCreatureStats::UpdateCombatInformationvoid
extern void * const CNWSCreatureStats__UpdateCombatInformation;
// public void CNWSCreatureStats::UpdateLastStatsObjectunsigned long long int, CNWCreatureStatsUpdate*
extern void * const CNWSCreatureStats__UpdateLastStatsObject;
// public void CNWSCreatureStats::UpdateNumberMemorizedSpellSlotsvoid
extern void * const CNWSCreatureStats__UpdateNumberMemorizedSpellSlots;
// public unsigned long int CNWSCreatureStats::ValidateLevelUpCNWLevelStats*, unsigned char, unsigned char, unsigned char
extern void * const CNWSCreatureStats__ValidateLevelUp;

// public CNWSCreatureStats_ClassInfo::CNWSCreatureStats_ClassInfovoid
extern void * const CNWSCreatureStats_ClassInfo__CNWSCreatureStats_ClassInfoCtor;
// public CNWSCreatureStats_ClassInfo::~CNWSCreatureStats_ClassInfovoid
extern void * const CNWSCreatureStats_ClassInfo__CNWSCreatureStats_ClassInfoDtor;
// void CNWSCreatureStats_ClassInfo::AddKnownSpellunsigned char, unsigned long int
extern void * const CNWSCreatureStats_ClassInfo__AddKnownSpell;
// public void CNWSCreatureStats_ClassInfo::ClearMemorizedKnownSpellsunsigned long int
extern void * const CNWSCreatureStats_ClassInfo__ClearMemorizedKnownSpells;
// public void CNWSCreatureStats_ClassInfo::ClearMemorizedSpellSlotunsigned char, unsigned char
extern void * const CNWSCreatureStats_ClassInfo__ClearMemorizedSpellSlot;
// public int CNWSCreatureStats_ClassInfo::ConfirmDomainSpellunsigned char, unsigned long int
extern void * const CNWSCreatureStats_ClassInfo__ConfirmDomainSpell;
// void CNWSCreatureStats_ClassInfo::DecrementSpellsPerDayLeftunsigned char
extern void * const CNWSCreatureStats_ClassInfo__DecrementSpellsPerDayLeft;
// public int CNWSCreatureStats_ClassInfo::GetIsDomainSpellunsigned char, unsigned char
extern void * const CNWSCreatureStats_ClassInfo__GetIsDomainSpell;
// public unsigned long int CNWSCreatureStats_ClassInfo::GetKnownSpellunsigned char, unsigned char
extern void * const CNWSCreatureStats_ClassInfo__GetKnownSpell;
// void CNWSCreatureStats_ClassInfo::GetMaxSpellsPerDayLeftunsigned char
extern void * const CNWSCreatureStats_ClassInfo__GetMaxSpellsPerDayLeft;
// public unsigned long int CNWSCreatureStats_ClassInfo::GetMemorizedSpellInSlotunsigned char, unsigned char
extern void * const CNWSCreatureStats_ClassInfo__GetMemorizedSpellInSlot;
// public CNWSStats_Spell* CNWSCreatureStats_ClassInfo::GetMemorizedSpellInSlotDetailsunsigned char, unsigned char
extern void * const CNWSCreatureStats_ClassInfo__GetMemorizedSpellInSlotDetails;
// public unsigned char CNWSCreatureStats_ClassInfo::GetMemorizedSpellInSlotMetaTypeunsigned char, unsigned char
extern void * const CNWSCreatureStats_ClassInfo__GetMemorizedSpellInSlotMetaType;
// public int CNWSCreatureStats_ClassInfo::GetMemorizedSpellInSlotReadyunsigned char, unsigned char
extern void * const CNWSCreatureStats_ClassInfo__GetMemorizedSpellInSlotReady;
// public unsigned char CNWSCreatureStats_ClassInfo::GetMemorizedSpellReadyCountunsigned long int, unsigned char*, unsigned char*, unsigned char
extern void * const CNWSCreatureStats_ClassInfo__GetMemorizedSpellReadyCount__0;
// public unsigned char CNWSCreatureStats_ClassInfo::GetMemorizedSpellReadyCountunsigned long int, unsigned char
extern void * const CNWSCreatureStats_ClassInfo__GetMemorizedSpellReadyCount__1;
// void CNWSCreatureStats_ClassInfo::GetNumberBonusSpellsunsigned char
extern void * const CNWSCreatureStats_ClassInfo__GetNumberBonusSpells;
// void CNWSCreatureStats_ClassInfo::GetNumberKnownSpellsunsigned char
extern void * const CNWSCreatureStats_ClassInfo__GetNumberKnownSpells;
// public unsigned char CNWSCreatureStats_ClassInfo::GetNumberMemorizedSpellSlotsunsigned char
extern void * const CNWSCreatureStats_ClassInfo__GetNumberMemorizedSpellSlots;
// void CNWSCreatureStats_ClassInfo::GetSpellsPerDayLeftunsigned char
extern void * const CNWSCreatureStats_ClassInfo__GetSpellsPerDayLeft;
// void CNWSCreatureStats_ClassInfo::IncrementSpellsPerDayLeftunsigned char
extern void * const CNWSCreatureStats_ClassInfo__IncrementSpellsPerDayLeft;
// public void CNWSCreatureStats_ClassInfo::RemoveKnownSpellunsigned char, unsigned long int
extern void * const CNWSCreatureStats_ClassInfo__RemoveKnownSpell;
// void CNWSCreatureStats_ClassInfo::ResetSpellsPerDayLeftunsigned char, unsigned char
extern void * const CNWSCreatureStats_ClassInfo__ResetSpellsPerDayLeft;
// void CNWSCreatureStats_ClassInfo::SetMaxSpellsPerDayLeftunsigned char, unsigned char
extern void * const CNWSCreatureStats_ClassInfo__SetMaxSpellsPerDayLeft;
// public void CNWSCreatureStats_ClassInfo::SetMemorizedSpellInSlotReadyunsigned char, unsigned char, int
extern void * const CNWSCreatureStats_ClassInfo__SetMemorizedSpellInSlotReady;
// public void CNWSCreatureStats_ClassInfo::SetMemorizedSpellSlotunsigned char, unsigned char, unsigned long int, int, unsigned char
extern void * const CNWSCreatureStats_ClassInfo__SetMemorizedSpellSlot;
// void CNWSCreatureStats_ClassInfo::SetNumberBonusSpellsunsigned char, unsigned char
extern void * const CNWSCreatureStats_ClassInfo__SetNumberBonusSpells;
// public void CNWSCreatureStats_ClassInfo::SetNumberMemorizedSpellSlotsunsigned char, unsigned char
extern void * const CNWSCreatureStats_ClassInfo__SetNumberMemorizedSpellSlots;
// void CNWSCreatureStats_ClassInfo::SetSpellsPerDayLeftunsigned char, unsigned char
extern void * const CNWSCreatureStats_ClassInfo__SetSpellsPerDayLeft;

// public CNWSDialog::CNWSDialogvoid
extern void * const CNWSDialog__CNWSDialogCtor;
// public CNWSDialog::~CNWSDialogvoid
extern void * const CNWSDialog__CNWSDialogDtor;
// public void CNWSDialog::AddJournalEntryconst CExoString&, unsigned long int, unsigned long int
extern void * const CNWSDialog__AddJournalEntry;
// public int CNWSDialog::CheckScriptCNWSObject*, const CResRef&
extern void * const CNWSDialog__CheckScript;
// public void CNWSDialog::Cleanupvoid
extern void * const CNWSDialog__Cleanup;
// void CNWSDialog::ClearDialogOwnerInObjectunsigned long int
extern void * const CNWSDialog__ClearDialogOwnerInObject;
// public CNWSObject* CNWSDialog::GetSpeakerCNWSObject*, const CExoString&
extern void * const CNWSDialog__GetSpeaker;
// public unsigned long int CNWSDialog::GetStartEntryCNWSObject*
extern void * const CNWSDialog__GetStartEntry;
// public int CNWSDialog::GetStartEntryOneLinerCNWSObject*, CExoLocString&, CResRef&, CResRef&
extern void * const CNWSDialog__GetStartEntryOneLiner;
// public int CNWSDialog::HandleReplyunsigned long int, CNWSObject*, unsigned long int, int, unsigned long int
extern void * const CNWSDialog__HandleReply;
// public int CNWSDialog::IsPlayerInDialogunsigned long int
extern void * const CNWSDialog__IsPlayerInDialog;
// public int CNWSDialog::LoadDialogCResGFF*, int
extern void * const CNWSDialog__LoadDialog;
// public int CNWSDialog::RemovePlayerunsigned long int
extern void * const CNWSDialog__RemovePlayer;
// public void CNWSDialog::RunScriptCNWSObject*, const CResRef&
extern void * const CNWSDialog__RunScript;
// public int CNWSDialog::SendDialogEntryCNWSObject*, unsigned long int, unsigned long int, int
extern void * const CNWSDialog__SendDialogEntry;
// public int CNWSDialog::SendDialogRepliesCNWSObject*, unsigned long int
extern void * const CNWSDialog__SendDialogReplies;
// public float CNWSDialog::SetDialogDelayCNWSObject*, CExoLocString, unsigned long int, int
extern void * const CNWSDialog__SetDialogDelay;

// public CNWSDoor::CNWSDoorunsigned long int
extern void * const CNWSDoor__CNWSDoorCtor;
// public CNWSDoor::~CNWSDoorvoid
extern void * const CNWSDoor__CNWSDoorDtor;
// public void CNWSDoor::AddToAreaCNWSArea*, float, float, float, int
extern void * const CNWSDoor__AddToArea;
// public void CNWSDoor::AIUpdatevoid
extern void * const CNWSDoor__AIUpdate;
// public CNWSDoor* CNWSDoor::AsNWSDoorvoid
extern void * const CNWSDoor__AsNWSDoor;
// public void CNWSDoor::DoDamageint
extern void * const CNWSDoor__DoDamage;
// public void CNWSDoor::EventHandlerunsigned long int, unsigned long int, void*, unsigned long int, unsigned long int
extern void * const CNWSDoor__EventHandler;
// public Vector CNWSDoor::GetActionPointint, unsigned char
extern void * const CNWSDoor__GetActionPoint;
// void CNWSDoor::GetActivevoid
extern void * const CNWSDoor__GetActive;
// void CNWSDoor::GetAppearanceTypevoid
extern void * const CNWSDoor__GetAppearanceType;
// void CNWSDoor::GetAutoRemoveKeyvoid
extern void * const CNWSDoor__GetAutoRemoveKey;
// void CNWSDoor::GetBaseTypevoid
extern void * const CNWSDoor__GetBaseType;
// void CNWSDoor::GetBearingvoid
extern void * const CNWSDoor__GetBearing;
// void CNWSDoor::GetCreatureListvoid
extern void * const CNWSDoor__GetCreatureList;
// public CExoLocString& CNWSDoor::GetDescriptionvoid
extern void * const CNWSDoor__GetDescription;
// public CExoString CNWSDoor::GetDescriptionOverridevoid
extern void * const CNWSDoor__GetDescriptionOverride;
// void CNWSDoor::GetDetectablevoid
extern void * const CNWSDoor__GetDetectable;
// void CNWSDoor::GetDetectDCvoid
extern void * const CNWSDoor__GetDetectDC;
// public CResRef CNWSDoor::GetDialogResrefvoid
extern void * const CNWSDoor__GetDialogResref;
// void CNWSDoor::GetDisarmablevoid
extern void * const CNWSDoor__GetDisarmable;
// void CNWSDoor::GetDisarmDCvoid
extern void * const CNWSDoor__GetDisarmDC;
// public CExoString CNWSDoor::GetDisplayNamevoid
extern void * const CNWSDoor__GetDisplayName;
// void CNWSDoor::GetFactionIdvoid
extern void * const CNWSDoor__GetFactionId;
// public CExoLocString& CNWSDoor::GetFirstNamevoid
extern void * const CNWSDoor__GetFirstName;
// void CNWSDoor::GetFlaggedvoid
extern void * const CNWSDoor__GetFlagged;
// void CNWSDoor::GetFortitudeSavevoid
extern void * const CNWSDoor__GetFortitudeSave;
// void CNWSDoor::GetGenericTypevoid
extern void * const CNWSDoor__GetGenericType;
// void CNWSDoor::GetHardnessvoid
extern void * const CNWSDoor__GetHardness;
// public int CNWSDoor::GetIsLinkedvoid
extern void * const CNWSDoor__GetIsLinked;
// public CExoString* CNWSDoor::GetKeyNamevoid
extern void * const CNWSDoor__GetKeyName;
// void CNWSDoor::GetKeyRequiredvoid
extern void * const CNWSDoor__GetKeyRequired;
// public CExoString CNWSDoor::GetKeyRequiredFeedbackMessagevoid
extern void * const CNWSDoor__GetKeyRequiredFeedbackMessage;
// void CNWSDoor::GetLastClosedvoid
extern void * const CNWSDoor__GetLastClosed;
// void CNWSDoor::GetLastDisarmedvoid
extern void * const CNWSDoor__GetLastDisarmed;
// void CNWSDoor::GetLastLockedvoid
extern void * const CNWSDoor__GetLastLocked;
// void CNWSDoor::GetLastOpenedvoid
extern void * const CNWSDoor__GetLastOpened;
// void CNWSDoor::GetLastTriggeredvoid
extern void * const CNWSDoor__GetLastTriggered;
// void CNWSDoor::GetLastUnlockedvoid
extern void * const CNWSDoor__GetLastUnlocked;
// public CNWSObject* CNWSDoor::GetLinkedObjectvoid
extern void * const CNWSDoor__GetLinkedObject;
// public CExoString CNWSDoor::GetLinkedToTagvoid
extern void * const CNWSDoor__GetLinkedToTag;
// public unsigned short int CNWSDoor::GetLoadScreenIDvoid
extern void * const CNWSDoor__GetLoadScreenID;
// void CNWSDoor::GetLockablevoid
extern void * const CNWSDoor__GetLockable;
// void CNWSDoor::GetLockDCvoid
extern void * const CNWSDoor__GetLockDC;
// void CNWSDoor::GetLockedvoid
extern void * const CNWSDoor__GetLocked;
// public Vector CNWSDoor::GetNearestActionPointconst Vector&, int
extern void * const CNWSDoor__GetNearestActionPoint;
// void CNWSDoor::GetOneShotvoid
extern void * const CNWSDoor__GetOneShot;
// void CNWSDoor::GetOpenLockDCvoid
extern void * const CNWSDoor__GetOpenLockDC;
// public unsigned char CNWSDoor::GetOpenStatevoid
extern void * const CNWSDoor__GetOpenState;
// void CNWSDoor::GetRecoverablevoid
extern void * const CNWSDoor__GetRecoverable;
// void CNWSDoor::GetReflexSavevoid
extern void * const CNWSDoor__GetReflexSave;
// void CNWSDoor::GetScriptNameint
extern void * const CNWSDoor__GetScriptName;
// void CNWSDoor::GetSecretDoorDCvoid
extern void * const CNWSDoor__GetSecretDoorDC;
// void CNWSDoor::GetTrapCreatorvoid
extern void * const CNWSDoor__GetTrapCreator;
// void CNWSDoor::GetTrapFactionIdvoid
extern void * const CNWSDoor__GetTrapFactionId;
// void CNWSDoor::GetTrappedvoid
extern void * const CNWSDoor__GetTrapped;
// void CNWSDoor::GetUpdateDisplayNamevoid
extern void * const CNWSDoor__GetUpdateDisplayName;
// void CNWSDoor::GetVisibleModelvoid
extern void * const CNWSDoor__GetVisibleModel;
// void CNWSDoor::GetWillSavevoid
extern void * const CNWSDoor__GetWillSave;
// public int CNWSDoor::LoadDoorCResGFF*, CResStruct*
extern void * const CNWSDoor__LoadDoor;
// public int CNWSDoor::NoNonWalkPolysInDoorfloat, float, float, float, float, float, float
extern void * const CNWSDoor__NoNonWalkPolysInDoor;
// public void CNWSDoor::PostProcessvoid
extern void * const CNWSDoor__PostProcess;
// public void CNWSDoor::RemoveFromAreavoid
extern void * const CNWSDoor__RemoveFromArea;
// public int CNWSDoor::SaveDoorCResGFF*, CResStruct*
extern void * const CNWSDoor__SaveDoor;
// void CNWSDoor::SetActiveint
extern void * const CNWSDoor__SetActive;
// void CNWSDoor::SetAppearanceTypeunsigned long int
extern void * const CNWSDoor__SetAppearanceType;
// void CNWSDoor::SetAutoRemoveKeyint
extern void * const CNWSDoor__SetAutoRemoveKey;
// void CNWSDoor::SetBaseTypeunsigned char
extern void * const CNWSDoor__SetBaseType;
// void CNWSDoor::SetBearingfloat
extern void * const CNWSDoor__SetBearing;
// public void CNWSDoor::SetDescriptionCExoLocString
extern void * const CNWSDoor__SetDescription;
// public void CNWSDoor::SetDescriptionOverrideCExoString
extern void * const CNWSDoor__SetDescriptionOverride;
// void CNWSDoor::SetDetectableint
extern void * const CNWSDoor__SetDetectable;
// void CNWSDoor::SetDetectDCunsigned char
extern void * const CNWSDoor__SetDetectDC;
// void CNWSDoor::SetDialogResrefCResRef
extern void * const CNWSDoor__SetDialogResref;
// void CNWSDoor::SetDisarmableint
extern void * const CNWSDoor__SetDisarmable;
// void CNWSDoor::SetDisarmDCunsigned char
extern void * const CNWSDoor__SetDisarmDC;
// public void CNWSDoor::SetDisplayNameCExoString
extern void * const CNWSDoor__SetDisplayName;
// void CNWSDoor::SetFactionIdint
extern void * const CNWSDoor__SetFactionId;
// public void CNWSDoor::SetFirstNameCExoLocString
extern void * const CNWSDoor__SetFirstName;
// void CNWSDoor::SetFlaggedunsigned char
extern void * const CNWSDoor__SetFlagged;
// void CNWSDoor::SetFortitudeSaveunsigned char
extern void * const CNWSDoor__SetFortitudeSave;
// void CNWSDoor::SetGenericTypeunsigned long int
extern void * const CNWSDoor__SetGenericType;
// void CNWSDoor::SetHardnessunsigned char
extern void * const CNWSDoor__SetHardness;
// void CNWSDoor::SetKeyNameconst CExoString&
extern void * const CNWSDoor__SetKeyName;
// void CNWSDoor::SetKeyRequiredint
extern void * const CNWSDoor__SetKeyRequired;
// public void CNWSDoor::SetKeyRequiredFeedbackMessageCExoString
extern void * const CNWSDoor__SetKeyRequiredFeedbackMessage;
// void CNWSDoor::SetLastClosedunsigned long int
extern void * const CNWSDoor__SetLastClosed;
// void CNWSDoor::SetLastDisarmedunsigned long int
extern void * const CNWSDoor__SetLastDisarmed;
// void CNWSDoor::SetLastLockedunsigned long int
extern void * const CNWSDoor__SetLastLocked;
// void CNWSDoor::SetLastOpenedunsigned long int
extern void * const CNWSDoor__SetLastOpened;
// void CNWSDoor::SetLastTriggeredunsigned long int
extern void * const CNWSDoor__SetLastTriggered;
// void CNWSDoor::SetLastUnlockedunsigned long int
extern void * const CNWSDoor__SetLastUnlocked;
// void CNWSDoor::SetLinkedFlagsunsigned char
extern void * const CNWSDoor__SetLinkedFlags;
// public void CNWSDoor::SetLinkedToTagCExoString
extern void * const CNWSDoor__SetLinkedToTag;
// void CNWSDoor::SetLockableint
extern void * const CNWSDoor__SetLockable;
// void CNWSDoor::SetLockDCunsigned char
extern void * const CNWSDoor__SetLockDC;
// void CNWSDoor::SetLockedint
extern void * const CNWSDoor__SetLocked;
// void CNWSDoor::SetOneShotint
extern void * const CNWSDoor__SetOneShot;
// void CNWSDoor::SetOpenLockDCunsigned char
extern void * const CNWSDoor__SetOpenLockDC;
// public void CNWSDoor::SetOpenStateunsigned char
extern void * const CNWSDoor__SetOpenState;
// void CNWSDoor::SetRecoverableint
extern void * const CNWSDoor__SetRecoverable;
// void CNWSDoor::SetReflexSaveunsigned char
extern void * const CNWSDoor__SetReflexSave;
// public void CNWSDoor::SetScriptNameint, CExoString
extern void * const CNWSDoor__SetScriptName;
// void CNWSDoor::SetSecretDoorDCunsigned char
extern void * const CNWSDoor__SetSecretDoorDC;
// void CNWSDoor::SetTrapCreatorunsigned long int
extern void * const CNWSDoor__SetTrapCreator;
// void CNWSDoor::SetTrapFactionIdint
extern void * const CNWSDoor__SetTrapFactionId;
// void CNWSDoor::SetTrappedint
extern void * const CNWSDoor__SetTrapped;
// void CNWSDoor::SetUpdateDisplayNameint
extern void * const CNWSDoor__SetUpdateDisplayName;
// void CNWSDoor::SetVisibleModelint
extern void * const CNWSDoor__SetVisibleModel;
// void CNWSDoor::SetWillSaveunsigned char
extern void * const CNWSDoor__SetWillSave;

// public CNWSDungeonMaster::CNWSDungeonMasterunsigned long int
extern void * const CNWSDungeonMaster__CNWSDungeonMasterCtor;
// public CNWSDungeonMaster::~CNWSDungeonMastervoid
extern void * const CNWSDungeonMaster__CNWSDungeonMasterDtor;
// public CNWSDungeonMaster* CNWSDungeonMaster::AsNWSDungeonMastervoid
extern void * const CNWSDungeonMaster__AsNWSDungeonMaster;
// public void CNWSDungeonMaster::PossessCreatureunsigned long int, unsigned char
extern void * const CNWSDungeonMaster__PossessCreature;

// public CNWSEffectListHandler::~CNWSEffectListHandlervoid
extern void * const CNWSEffectListHandler__CNWSEffectListHandlerDtor;
// public void CNWSEffectListHandler::InitializeEffectsvoid
extern void * const CNWSEffectListHandler__InitializeEffects;
// public int CNWSEffectListHandler::OnApplyAbilityDecreaseCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyAbilityDecrease;
// public int CNWSEffectListHandler::OnApplyAbilityIncreaseCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyAbilityIncrease;
// public int CNWSEffectListHandler::OnApplyACDecreaseCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyACDecrease;
// public int CNWSEffectListHandler::OnApplyACIncreaseCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyACIncrease;
// public int CNWSEffectListHandler::OnApplyAppearCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyAppear;
// public int CNWSEffectListHandler::OnApplyArcaneSpellFailureCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyArcaneSpellFailure;
// public int CNWSEffectListHandler::OnApplyAreaOfEffectCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyAreaOfEffect;
// public int CNWSEffectListHandler::OnApplyAttackDecreaseCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyAttackDecrease;
// public int CNWSEffectListHandler::OnApplyAttackIncreaseCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyAttackIncrease;
// public int CNWSEffectListHandler::OnApplyBeamCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyBeam;
// public int CNWSEffectListHandler::OnApplyBlindnessCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyBlindness;
// public int CNWSEffectListHandler::OnApplyBlindnessInactiveCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyBlindnessInactive;
// public int CNWSEffectListHandler::OnApplyBonusFeatCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyBonusFeat;
// public int CNWSEffectListHandler::OnApplyBonusSpellOfLevelCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyBonusSpellOfLevel;
// public int CNWSEffectListHandler::OnApplyConcealmentCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyConcealment;
// public int CNWSEffectListHandler::OnApplyCurseCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyCurse;
// public int CNWSEffectListHandler::OnApplyCutsceneGhostCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyCutsceneGhost;
// public int CNWSEffectListHandler::OnApplyCutsceneImmobileCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyCutsceneImmobile;
// public int CNWSEffectListHandler::OnApplyDamageCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyDamage;
// public int CNWSEffectListHandler::OnApplyDamageDecreaseCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyDamageDecrease;
// public int CNWSEffectListHandler::OnApplyDamageImmunityDecreaseCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyDamageImmunityDecrease;
// public int CNWSEffectListHandler::OnApplyDamageImmunityIncreaseCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyDamageImmunityIncrease;
// public int CNWSEffectListHandler::OnApplyDamageIncreaseCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyDamageIncrease;
// public int CNWSEffectListHandler::OnApplyDamageReductionCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyDamageReduction;
// public int CNWSEffectListHandler::OnApplyDamageResistanceCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyDamageResistance;
// public int CNWSEffectListHandler::OnApplyDamageShieldCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyDamageShield;
// public int CNWSEffectListHandler::OnApplyDarknessCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyDarkness;
// public int CNWSEffectListHandler::OnApplyDeafCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyDeaf;
// public int CNWSEffectListHandler::OnApplyDeathCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyDeath;
// public int CNWSEffectListHandler::OnApplyDefensiveStanceCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyDefensiveStance;
// public int CNWSEffectListHandler::OnApplyDisappearCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyDisappear;
// public int CNWSEffectListHandler::OnApplyDisappearAppearCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyDisappearAppear;
// public int CNWSEffectListHandler::OnApplyDisarmCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyDisarm;
// public int CNWSEffectListHandler::OnApplyDiseaseCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyDisease;
// public int CNWSEffectListHandler::OnApplyDispelAllMagicCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyDispelAllMagic;
// public int CNWSEffectListHandler::OnApplyDispelBestMagicCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyDispelBestMagic;
// public int CNWSEffectListHandler::OnApplyEffectIconCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyEffectIcon;
// public int CNWSEffectListHandler::OnApplyEffectImmunityCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyEffectImmunity;
// public int CNWSEffectListHandler::OnApplyEnemyAttackBonusCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyEnemyAttackBonus;
// public int CNWSEffectListHandler::OnApplyEntangledCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyEntangled;
// public int CNWSEffectListHandler::OnApplyHasteInternalCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyHasteInternal;
// public int CNWSEffectListHandler::OnApplyHasteOrSlowCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyHasteOrSlow;
// public int CNWSEffectListHandler::OnApplyHealCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyHeal;
// public int CNWSEffectListHandler::OnApplyHitPointChangeWhenDyingCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyHitPointChangeWhenDying;
// public int CNWSEffectListHandler::OnApplyInvisibilityCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyInvisibility;
// public int CNWSEffectListHandler::OnApplyItemPropertyCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyItemProperty;
// public int CNWSEffectListHandler::OnApplyKnockdownCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyKnockdown;
// public int CNWSEffectListHandler::OnApplyLightCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyLight;
// public int CNWSEffectListHandler::OnApplyLimitMovementSpeedCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyLimitMovementSpeed;
// public int CNWSEffectListHandler::OnApplyLinkCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyLink;
// public int CNWSEffectListHandler::OnApplyMissChanceCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyMissChance;
// public int CNWSEffectListHandler::OnApplyModifyNumAttacksCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyModifyNumAttacks;
// public int CNWSEffectListHandler::OnApplyMovementSpeedDecreaseCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyMovementSpeedDecrease;
// public int CNWSEffectListHandler::OnApplyMovementSpeedIncreaseCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyMovementSpeedIncrease;
// public int CNWSEffectListHandler::OnApplyNegativeLevelCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyNegativeLevel;
// public int CNWSEffectListHandler::OnApplyPetrifyCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyPetrify;
// public int CNWSEffectListHandler::OnApplyPoisonCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyPoison;
// public int CNWSEffectListHandler::OnApplyPolymorphCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyPolymorph;
// public int CNWSEffectListHandler::OnApplyRacialTypeCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyRacialType;
// public int CNWSEffectListHandler::OnApplyRegenerateCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyRegenerate;
// public int CNWSEffectListHandler::OnApplyResurrectionCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyResurrection;
// public int CNWSEffectListHandler::OnApplySanctuaryCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplySanctuary;
// public int CNWSEffectListHandler::OnApplySavingThrowDecreaseCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplySavingThrowDecrease;
// public int CNWSEffectListHandler::OnApplySavingThrowIncreaseCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplySavingThrowIncrease;
// public int CNWSEffectListHandler::OnApplySeeInvisibleCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplySeeInvisible;
// public int CNWSEffectListHandler::OnApplySetAIStateCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplySetAIState;
// public int CNWSEffectListHandler::OnApplySetStateCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplySetState;
// public int CNWSEffectListHandler::OnApplySetStateInternalCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplySetStateInternal;
// public int CNWSEffectListHandler::OnApplySilenceCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplySilence;
// public int CNWSEffectListHandler::OnApplySkillDecreaseCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplySkillDecrease;
// public int CNWSEffectListHandler::OnApplySkillIncreaseCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplySkillIncrease;
// public int CNWSEffectListHandler::OnApplySlowInternalCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplySlowInternal;
// public int CNWSEffectListHandler::OnApplySpecialWalkAnimationCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplySpecialWalkAnimation;
// public int CNWSEffectListHandler::OnApplySpellFailureCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplySpellFailure;
// public int CNWSEffectListHandler::OnApplySpellImmunityCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplySpellImmunity;
// public int CNWSEffectListHandler::OnApplySpellLevelAbsorptionCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplySpellLevelAbsorption;
// public int CNWSEffectListHandler::OnApplySpellResistanceDecreaseCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplySpellResistanceDecrease;
// public int CNWSEffectListHandler::OnApplySpellResistanceIncreaseCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplySpellResistanceIncrease;
// void CNWSEffectListHandler::OnApplyStoreCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnApplyStore;
// public int CNWSEffectListHandler::OnApplySummonCreatureCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplySummonCreature;
// public int CNWSEffectListHandler::OnApplySwarmCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplySwarm;
// public int CNWSEffectListHandler::OnApplyTauntCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyTaunt;
// public int CNWSEffectListHandler::OnApplyTemporaryHitpointsCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyTemporaryHitpoints;
// public int CNWSEffectListHandler::OnApplyTimestopCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyTimestop;
// public int CNWSEffectListHandler::OnApplyTrueSeeingCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyTrueSeeing;
// public int CNWSEffectListHandler::OnApplyTurnResistanceCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyTurnResistance;
// public int CNWSEffectListHandler::OnApplyUltraVisionCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyUltraVision;
// public int CNWSEffectListHandler::OnApplyVampiricRegenerationCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyVampiricRegeneration;
// public int CNWSEffectListHandler::OnApplyVisionCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyVision;
// public int CNWSEffectListHandler::OnApplyVisualEffectCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyVisualEffect;
// public int CNWSEffectListHandler::OnApplyWoundingCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnApplyWounding;
// public int CNWSEffectListHandler::OnEffectAppliedCNWSObject*, CGameEffect*, int
extern void * const CNWSEffectListHandler__OnEffectApplied;
// public int CNWSEffectListHandler::OnEffectRemovedCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnEffectRemoved;
// public int CNWSEffectListHandler::OnRemoveAbilityDecreaseCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveAbilityDecrease;
// public int CNWSEffectListHandler::OnRemoveAbilityIncreaseCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveAbilityIncrease;
// public int CNWSEffectListHandler::OnRemoveACDecreaseCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveACDecrease;
// public int CNWSEffectListHandler::OnRemoveACIncreaseCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveACIncrease;
// public int CNWSEffectListHandler::OnRemoveArcaneSpellFailureCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveArcaneSpellFailure;
// public int CNWSEffectListHandler::OnRemoveAreaOfEffectCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveAreaOfEffect;
// public int CNWSEffectListHandler::OnRemoveAttackDecreaseCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveAttackDecrease;
// public int CNWSEffectListHandler::OnRemoveAttackIncreaseCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveAttackIncrease;
// public int CNWSEffectListHandler::OnRemoveBeamCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveBeam;
// public int CNWSEffectListHandler::OnRemoveBlindnessCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveBlindness;
// public int CNWSEffectListHandler::OnRemoveBonusFeatCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveBonusFeat;
// public int CNWSEffectListHandler::OnRemoveBonusSpellOfLevelCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveBonusSpellOfLevel;
// public int CNWSEffectListHandler::OnRemoveConcealmentCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveConcealment;
// public int CNWSEffectListHandler::OnRemoveCurseCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveCurse;
// public int CNWSEffectListHandler::OnRemoveCutsceneGhostCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveCutsceneGhost;
// public int CNWSEffectListHandler::OnRemoveDamageDecreaseCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveDamageDecrease;
// public int CNWSEffectListHandler::OnRemoveDamageImmunityDecreaseCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveDamageImmunityDecrease;
// public int CNWSEffectListHandler::OnRemoveDamageImmunityIncreaseCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveDamageImmunityIncrease;
// public int CNWSEffectListHandler::OnRemoveDamageIncreaseCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveDamageIncrease;
// public int CNWSEffectListHandler::OnRemoveDamageShieldCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveDamageShield;
// public int CNWSEffectListHandler::OnRemoveDarknessCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveDarkness;
// public int CNWSEffectListHandler::OnRemoveDisappearAppearCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveDisappearAppear;
// public int CNWSEffectListHandler::OnRemoveDisarmCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveDisarm;
// public int CNWSEffectListHandler::OnRemoveEffectIconCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveEffectIcon;
// public int CNWSEffectListHandler::OnRemoveEffectImmunityCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveEffectImmunity;
// public int CNWSEffectListHandler::OnRemoveEnemyAttackBonusCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveEnemyAttackBonus;
// public int CNWSEffectListHandler::OnRemoveEntangledCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveEntangled;
// public int CNWSEffectListHandler::OnRemoveHasteInternalCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveHasteInternal;
// public int CNWSEffectListHandler::OnRemoveHasteOrSlowCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveHasteOrSlow;
// public int CNWSEffectListHandler::OnRemoveHitPointChangeWhenDyingCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveHitPointChangeWhenDying;
// public int CNWSEffectListHandler::OnRemoveInvisibilityCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveInvisibility;
// public int CNWSEffectListHandler::OnRemoveItemPropertyCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveItemProperty;
// public int CNWSEffectListHandler::OnRemoveKnockdownCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveKnockdown;
// public int CNWSEffectListHandler::OnRemoveLightCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveLight;
// public int CNWSEffectListHandler::OnRemoveLimitMovementSpeedCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveLimitMovementSpeed;
// public int CNWSEffectListHandler::OnRemoveMissChanceCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveMissChance;
// public int CNWSEffectListHandler::OnRemoveModifyNumAttacksCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveModifyNumAttacks;
// public int CNWSEffectListHandler::OnRemoveMovementSpeedDecreaseCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveMovementSpeedDecrease;
// public int CNWSEffectListHandler::OnRemoveMovementSpeedIncreaseCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveMovementSpeedIncrease;
// public int CNWSEffectListHandler::OnRemoveNegativeLevelCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveNegativeLevel;
// public int CNWSEffectListHandler::OnRemovePetrifyCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemovePetrify;
// public int CNWSEffectListHandler::OnRemovePolymorphCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemovePolymorph;
// public int CNWSEffectListHandler::OnRemoveRacialTypeCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveRacialType;
// public int CNWSEffectListHandler::OnRemoveSanctuaryCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveSanctuary;
// public int CNWSEffectListHandler::OnRemoveSavingThrowDecreaseCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveSavingThrowDecrease;
// public int CNWSEffectListHandler::OnRemoveSavingThrowIncreaseCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveSavingThrowIncrease;
// public int CNWSEffectListHandler::OnRemoveSeeInvisibleCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveSeeInvisible;
// public int CNWSEffectListHandler::OnRemoveSetAIStateCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveSetAIState;
// public int CNWSEffectListHandler::OnRemoveSetStateCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveSetState;
// public int CNWSEffectListHandler::OnRemoveSetStateInternalCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveSetStateInternal;
// public int CNWSEffectListHandler::OnRemoveSilenceCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveSilence;
// public int CNWSEffectListHandler::OnRemoveSkillDecreaseCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveSkillDecrease;
// public int CNWSEffectListHandler::OnRemoveSkillIncreaseCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveSkillIncrease;
// public int CNWSEffectListHandler::OnRemoveSlowInternalCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveSlowInternal;
// public int CNWSEffectListHandler::OnRemoveSpecialWalkAnimationCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveSpecialWalkAnimation;
// public int CNWSEffectListHandler::OnRemoveSpellFailureCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveSpellFailure;
// public int CNWSEffectListHandler::OnRemoveSpellImmunityCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveSpellImmunity;
// public int CNWSEffectListHandler::OnRemoveSpellLevelAbsorptionCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveSpellLevelAbsorption;
// public int CNWSEffectListHandler::OnRemoveSpellResistanceDecreaseCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveSpellResistanceDecrease;
// public int CNWSEffectListHandler::OnRemoveSpellResistanceIncreaseCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveSpellResistanceIncrease;
// public int CNWSEffectListHandler::OnRemoveSummonCreatureCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveSummonCreature;
// public int CNWSEffectListHandler::OnRemoveSwarmCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveSwarm;
// public int CNWSEffectListHandler::OnRemoveTauntCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveTaunt;
// public int CNWSEffectListHandler::OnRemoveTemporaryHitpointsCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveTemporaryHitpoints;
// public int CNWSEffectListHandler::OnRemoveTimestopCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveTimestop;
// public int CNWSEffectListHandler::OnRemoveTrueSeeingCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveTrueSeeing;
// public int CNWSEffectListHandler::OnRemoveTurnResistanceCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveTurnResistance;
// public int CNWSEffectListHandler::OnRemoveUltraVisionCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveUltraVision;
// public int CNWSEffectListHandler::OnRemoveVisionCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveVision;
// public int CNWSEffectListHandler::OnRemoveVisualEffectCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveVisualEffect;
// public int CNWSEffectListHandler::OnRemoveWoundingCNWSObject*, CGameEffect*
extern void * const CNWSEffectListHandler__OnRemoveWounding;
// public void CNWSEffectListHandler::SendFloatyEffectunsigned long int, unsigned long int
extern void * const CNWSEffectListHandler__SendFloatyEffect;

// public CNWSEncounter::CNWSEncounterunsigned long int
extern void * const CNWSEncounter__CNWSEncounterCtor;
// public CNWSEncounter::~CNWSEncountervoid
extern void * const CNWSEncounter__CNWSEncounterDtor;
// protected void CNWSEncounter::AddCreaturesToSpawnListCEncounterListEntry*, int&, int, CEncounterListEntry
extern void * const CNWSEncounter__AddCreaturesToSpawnList;
// protected void CNWSEncounter::AddToActivateAreaListunsigned long int
extern void * const CNWSEncounter__AddToActivateAreaList;
// public void CNWSEncounter::AddToAreaCNWSArea*, float, float, float, int
extern void * const CNWSEncounter__AddToArea;
// public void CNWSEncounter::AIUpdatevoid
extern void * const CNWSEncounter__AIUpdate;
// public CNWSEncounter* CNWSEncounter::AsNWSEncountervoid
extern void * const CNWSEncounter__AsNWSEncounter;
// protected float CNWSEncounter::CalculatePointsFromCRfloat
extern void * const CNWSEncounter__CalculatePointsFromCR;
// protected void CNWSEncounter::CalculateSpawnPoolfloat
extern void * const CNWSEncounter__CalculateSpawnPool;
// public void CNWSEncounter::EventHandlerunsigned long int, unsigned long int, void*, unsigned long int, unsigned long int
extern void * const CNWSEncounter__EventHandler;
// void CNWSEncounter::GetActivateObjectArrayIndexvoid
extern void * const CNWSEncounter__GetActivateObjectArrayIndex;
// void CNWSEncounter::GetActivevoid
extern void * const CNWSEncounter__GetActive;
// void CNWSEncounter::GetCustomScriptEventIdvoid
extern void * const CNWSEncounter__GetCustomScriptEventId;
// void CNWSEncounter::GetDifficultyvoid
extern void * const CNWSEncounter__GetDifficulty;
// void CNWSEncounter::GetDifficultyIndexvoid
extern void * const CNWSEncounter__GetDifficultyIndex;
// void CNWSEncounter::GetEncounterCanResetvoid
extern void * const CNWSEncounter__GetEncounterCanReset;
// void CNWSEncounter::GetEncounterExhaustedvoid
extern void * const CNWSEncounter__GetEncounterExhausted;
// void CNWSEncounter::GetEncounterStartedvoid
extern void * const CNWSEncounter__GetEncounterStarted;
// void CNWSEncounter::GetFactionIdvoid
extern void * const CNWSEncounter__GetFactionId;
// public CExoLocString& CNWSEncounter::GetFirstNamevoid
extern void * const CNWSEncounter__GetFirstName;
// public int CNWSEncounter::GetInActivateAreaVector
extern void * const CNWSEncounter__GetInActivateArea;
// void CNWSEncounter::GetInActivateAreaListunsigned long int
extern void * const CNWSEncounter__GetInActivateAreaList;
// void CNWSEncounter::GetLastEnteredvoid
extern void * const CNWSEncounter__GetLastEntered;
// void CNWSEncounter::GetLastLeftvoid
extern void * const CNWSEncounter__GetLastLeft;
// void CNWSEncounter::GetMaxActivateXvoid
extern void * const CNWSEncounter__GetMaxActivateX;
// void CNWSEncounter::GetMaxActivateYvoid
extern void * const CNWSEncounter__GetMaxActivateY;
// void CNWSEncounter::GetMinActivateXvoid
extern void * const CNWSEncounter__GetMinActivateX;
// void CNWSEncounter::GetMinActivateYvoid
extern void * const CNWSEncounter__GetMinActivateY;
// void CNWSEncounter::GetNewEntryvoid
extern void * const CNWSEncounter__GetNewEntry;
// void CNWSEncounter::GetPlayerTriggeredOnlyvoid
extern void * const CNWSEncounter__GetPlayerTriggeredOnly;
// void CNWSEncounter::GetPositionvoid
extern void * const CNWSEncounter__GetPosition;
// void CNWSEncounter::GetRespawnsCurrentvoid
extern void * const CNWSEncounter__GetRespawnsCurrent;
// void CNWSEncounter::GetRespawnsMaxvoid
extern void * const CNWSEncounter__GetRespawnsMax;
// void CNWSEncounter::GetScriptNameint
extern void * const CNWSEncounter__GetScriptName;
// void CNWSEncounter::GetSpawnModevoid
extern void * const CNWSEncounter__GetSpawnMode;
// public int CNWSEncounter::LineSegmentIntersectActivateAreaVector, Vector
extern void * const CNWSEncounter__LineSegmentIntersectActivateArea;
// public int CNWSEncounter::LoadEncounterCResGFF*, CResStruct*
extern void * const CNWSEncounter__LoadEncounter;
// void CNWSEncounter::LoadFractionalCRDatavoid
extern void * const CNWSEncounter__LoadFractionalCRData;
// public void CNWSEncounter::LoadFromTemplateCResRef, int, Vector*
extern void * const CNWSEncounter__LoadFromTemplate;
// protected void CNWSEncounter::MakeSpawnListCEncounterListEntry*, int&
extern void * const CNWSEncounter__MakeSpawnList;
// protected void CNWSEncounter::PadOutCreatureCountCEncounterListEntry*, int&
extern void * const CNWSEncounter__PadOutCreatureCount;
// public int CNWSEncounter::ReadEncounterFromGffCResGFF*, CResStruct*, int, Vector*
extern void * const CNWSEncounter__ReadEncounterFromGff;
// public void CNWSEncounter::ReadEncounterScriptsFromGffCResGFF*, CResStruct*
extern void * const CNWSEncounter__ReadEncounterScriptsFromGff;
// void CNWSEncounter::RemoveFromActivateAreaListunsigned long int
extern void * const CNWSEncounter__RemoveFromActivateAreaList;
// public void CNWSEncounter::RemoveFromActiveCreatureCountfloat, int
extern void * const CNWSEncounter__RemoveFromActiveCreatureCount;
// public void CNWSEncounter::RemoveFromAreavoid
extern void * const CNWSEncounter__RemoveFromArea;
// public int CNWSEncounter::SaveEncounterCResGFF*, CResStruct*
extern void * const CNWSEncounter__SaveEncounter;
// void CNWSEncounter::SetActivateObjectArrayIndexunsigned short int
extern void * const CNWSEncounter__SetActivateObjectArrayIndex;
// public void CNWSEncounter::SetActiveint
extern void * const CNWSEncounter__SetActive;
// void CNWSEncounter::SetCustomScriptEventIdint
extern void * const CNWSEncounter__SetCustomScriptEventId;
// public void CNWSEncounter::SetDifficultyint
extern void * const CNWSEncounter__SetDifficulty;
// void CNWSEncounter::SetEncounterCanResetint
extern void * const CNWSEncounter__SetEncounterCanReset;
// void CNWSEncounter::SetEncounterExhaustedint
extern void * const CNWSEncounter__SetEncounterExhausted;
// void CNWSEncounter::SetEncounterStartedint
extern void * const CNWSEncounter__SetEncounterStarted;
// void CNWSEncounter::SetLastEnteredunsigned long int
extern void * const CNWSEncounter__SetLastEntered;
// void CNWSEncounter::SetLastLeftunsigned long int
extern void * const CNWSEncounter__SetLastLeft;
// void CNWSEncounter::SetNewEntryint
extern void * const CNWSEncounter__SetNewEntry;
// void CNWSEncounter::SetPlayerTriggeredOnlyint
extern void * const CNWSEncounter__SetPlayerTriggeredOnly;
// void CNWSEncounter::SetRespawnsCurrentint
extern void * const CNWSEncounter__SetRespawnsCurrent;
// void CNWSEncounter::SetRespawnsMaxint
extern void * const CNWSEncounter__SetRespawnsMax;
// protected void CNWSEncounter::SetScriptNameint, CExoString
extern void * const CNWSEncounter__SetScriptName;
// void CNWSEncounter::SetSpawnModeint
extern void * const CNWSEncounter__SetSpawnMode;
// protected void CNWSEncounter::SpawnEncounterCreaturesvoid
extern void * const CNWSEncounter__SpawnEncounterCreatures;
// public void CNWSEncounter::SpawnIfAppropriateunsigned long int, float
extern void * const CNWSEncounter__SpawnIfAppropriate;
// protected void CNWSEncounter::TallyEnemyRadiusPointsvoid
extern void * const CNWSEncounter__TallyEnemyRadiusPoints;
// protected void CNWSEncounter::UpdateActivateAreaListunsigned long int
extern void * const CNWSEncounter__UpdateActivateAreaList;

// public CNWSExpression::CNWSExpressionvoid
extern void * const CNWSExpression__CNWSExpressionCtor;
// public CNWSExpression::~CNWSExpressionvoid
extern void * const CNWSExpression__CNWSExpressionDtor;
// private void CNWSExpression::ClearAlternateCNWSExpressionNode*
extern void * const CNWSExpression__ClearAlternate;
// void CNWSExpression::ClearGraphvoid
extern void * const CNWSExpression__ClearGraph;
// private CNWSExpressionNode* CNWSExpression::NewNodeint
extern void * const CNWSExpression__NewNode;
// public int CNWSExpression::ParseStringCExoString
extern void * const CNWSExpression__ParseString;
// public int CNWSExpression::TestStringconst CExoString&, int
extern void * const CNWSExpression__TestString;

// CNWSExpressionList::CNWSExpressionListvoid
extern void * const CNWSExpressionList__CNWSExpressionListCtor;
// CNWSExpressionList::~CNWSExpressionListvoid
extern void * const CNWSExpressionList__CNWSExpressionListDtor;
// public void CNWSExpressionList::AddNodeCNWSExpressionNode*
extern void * const CNWSExpressionList__AddNode;
// void CNWSExpressionList::AddNodeToHeadCNWSExpressionNode*
extern void * const CNWSExpressionList__AddNodeToHead;
// private void CNWSExpressionList::DeleteAlternateCNWSExpressionNode*
extern void * const CNWSExpressionList__DeleteAlternate;
// void CNWSExpressionList::DeleteListvoid
extern void * const CNWSExpressionList__DeleteList;

// public CNWSExpressionNode::CNWSExpressionNodevoid
extern void * const CNWSExpressionNode__CNWSExpressionNodeCtor;
// public CNWSExpressionNode::~CNWSExpressionNodevoid
extern void * const CNWSExpressionNode__CNWSExpressionNodeDtor;

// public CNWSFaction::CNWSFactionunsigned long int
extern void * const CNWSFaction__CNWSFactionCtor__0;
// public CNWSFaction::CNWSFactionvoid
extern void * const CNWSFaction__CNWSFactionCtor__1;
// public CNWSFaction::~CNWSFactionvoid
extern void * const CNWSFaction__CNWSFactionDtor;
// public void CNWSFaction::AddMemberunsigned long int, int
extern void * const CNWSFaction__AddMember;
// void CNWSFaction::AttemptJoinunsigned long int
extern void * const CNWSFaction__AttemptJoin;
// public int CNWSFaction::AttemptRemoveunsigned long int, unsigned long int
extern void * const CNWSFaction__AttemptRemove;
// public void CNWSFaction::ChangeMemberIdunsigned long int, unsigned long int
extern void * const CNWSFaction__ChangeMemberId;
// public void CNWSFaction::ClearAllReputationsTowardsunsigned long int
extern void * const CNWSFaction__ClearAllReputationsTowards;
// public int CNWSFaction::GetAverageGoodEvilAlignmentvoid
extern void * const CNWSFaction__GetAverageGoodEvilAlignment;
// public int CNWSFaction::GetAverageLawChaosAlignmentvoid
extern void * const CNWSFaction__GetAverageLawChaosAlignment;
// public int CNWSFaction::GetAverageLevelvoid
extern void * const CNWSFaction__GetAverageLevel;
// public int CNWSFaction::GetAverageReputationunsigned long int
extern void * const CNWSFaction__GetAverageReputation;
// public int CNWSFaction::GetAverageXPvoid
extern void * const CNWSFaction__GetAverageXP;
// public unsigned long int CNWSFaction::GetBestACunsigned long int, int
extern void * const CNWSFaction__GetBestAC;
// public int CNWSFaction::GetCreatureInPartyunsigned long int
extern void * const CNWSFaction__GetCreatureInParty;
// void CNWSFaction::GetFactionManagervoid
extern void * const CNWSFaction__GetFactionManager;
// public unsigned long int CNWSFaction::GetFactionMemberint, int
extern void * const CNWSFaction__GetFactionMember;
// public int CNWSFaction::GetGoldvoid
extern void * const CNWSFaction__GetGold;
// void CNWSFaction::GetIsInvitedunsigned long int
extern void * const CNWSFaction__GetIsInvited;
// public unsigned long int CNWSFaction::GetLeadervoid
extern void * const CNWSFaction__GetLeader;
// public unsigned long int CNWSFaction::GetLeastDamagedMemberunsigned long int, int
extern void * const CNWSFaction__GetLeastDamagedMember;
// public unsigned long int CNWSFaction::GetMemberListunsigned long int**
extern void * const CNWSFaction__GetMemberList;
// public unsigned long int CNWSFaction::GetMostDamagedMemberunsigned long int, int
extern void * const CNWSFaction__GetMostDamagedMember;
// public int CNWSFaction::GetMostFrequentClassvoid
extern void * const CNWSFaction__GetMostFrequentClass;
// public int CNWSFaction::GetSingletonPartyvoid
extern void * const CNWSFaction__GetSingletonParty;
// public unsigned long int CNWSFaction::GetStrongestMemberunsigned long int, int
extern void * const CNWSFaction__GetStrongestMember;
// public unsigned long int CNWSFaction::GetWeakestMemberunsigned long int, int
extern void * const CNWSFaction__GetWeakestMember;
// public unsigned long int CNWSFaction::GetWorstACunsigned long int, int
extern void * const CNWSFaction__GetWorstAC;
// void CNWSFaction::Initialisevoid
extern void * const CNWSFaction__Initialise;
// public int CNWSFaction::InviteMemberunsigned long int, unsigned long int
extern void * const CNWSFaction__InviteMember;
// public void CNWSFaction::RemoveMemberunsigned long int
extern void * const CNWSFaction__RemoveMember;
// public void CNWSFaction::SendChatMessageunsigned long int, CExoString
extern void * const CNWSFaction__SendChatMessage;
// public void CNWSFaction::SendFactionUpdateAddunsigned long int
extern void * const CNWSFaction__SendFactionUpdateAdd;
// void CNWSFaction::SendFactionUpdateListvoid
extern void * const CNWSFaction__SendFactionUpdateList;
// void CNWSFaction::SendFactionUpdateRemoveunsigned long int
extern void * const CNWSFaction__SendFactionUpdateRemove;
// public int CNWSFaction::TransferLeadershipunsigned long int, unsigned long int
extern void * const CNWSFaction__TransferLeadership;

// public CNWSForcedAction::CNWSForcedActionvoid
extern void * const CNWSForcedAction__CNWSForcedActionCtor;
// public CNWSForcedAction::~CNWSForcedActionvoid
extern void * const CNWSForcedAction__CNWSForcedActionDtor;
// public int CNWSForcedAction::LoadForcedActionCResGFF*, CResStruct*
extern void * const CNWSForcedAction__LoadForcedAction;
// public int CNWSForcedAction::SaveForcedActionCResGFF*, CResStruct*
extern void * const CNWSForcedAction__SaveForcedAction;

// public CNWSInventory::CNWSInventoryvoid
extern void * const CNWSInventory__CNWSInventoryCtor;
// CNWSInventory::~CNWSInventoryvoid
extern void * const CNWSInventory__CNWSInventoryDtor;
// void CNWSInventory::GetArraySlotFromSlotFlagunsigned long int
extern void * const CNWSInventory__GetArraySlotFromSlotFlag;
// public int CNWSInventory::GetItemInInventoryCNWSItem*
extern void * const CNWSInventory__GetItemInInventory;
// public CNWSItem* CNWSInventory::GetItemInSlotunsigned long int
extern void * const CNWSInventory__GetItemInSlot;
// public unsigned long int CNWSInventory::GetSlotFromItemCNWSItem*
extern void * const CNWSInventory__GetSlotFromItem;
// public void CNWSInventory::PutItemInSlotunsigned long int, CNWSItem*
extern void * const CNWSInventory__PutItemInSlot;
// public int CNWSInventory::RemoveItemCNWSItem*
extern void * const CNWSInventory__RemoveItem;

// public CNWSItem::CNWSItemunsigned long int
extern void * const CNWSItem__CNWSItemCtor;
// public CNWSItem::~CNWSItemvoid
extern void * const CNWSItem__CNWSItemDtor;
// public int CNWSItem::AcquireItemCNWSItem**, unsigned long int, unsigned char, unsigned char, int
extern void * const CNWSItem__AcquireItem;
// public int CNWSItem::ActivePropertyunsigned short int
extern void * const CNWSItem__ActiveProperty;
// public void CNWSItem::AddActivePropertyCNWItemProperty
extern void * const CNWSItem__AddActiveProperty;
// public void CNWSItem::AddPassivePropertyCNWItemProperty
extern void * const CNWSItem__AddPassiveProperty;
// public void CNWSItem::AddToAreaCNWSArea*, float, float, float, int
extern void * const CNWSItem__AddToArea;
// public void CNWSItem::AIUpdatevoid
extern void * const CNWSItem__AIUpdate;
// public void CNWSItem::ApplyItemPropertiesCNWSCreature*, unsigned long int, int
extern void * const CNWSItem__ApplyItemProperties;
// public CNWSItem* CNWSItem::AsNWSItemvoid
extern void * const CNWSItem__AsNWSItem;
// protected void CNWSItem::CalculateBaseCostsvoid
extern void * const CNWSItem__CalculateBaseCosts;
// protected float CNWSItem::CalculatePassiveCostCNWItemProperty*
extern void * const CNWSItem__CalculatePassiveCost;
// public void CNWSItem::CloseInventoryunsigned long int, int
extern void * const CNWSItem__CloseInventory;
// public void CNWSItem::CloseItemForAllPlayersvoid
extern void * const CNWSItem__CloseItemForAllPlayers;
// public int CNWSItem::CompareItemCNWSItem*
extern void * const CNWSItem__CompareItem;
// public int CNWSItem::ComputeArmorClassvoid
extern void * const CNWSItem__ComputeArmorClass;
// public void CNWSItem::ComputeWeightvoid
extern void * const CNWSItem__ComputeWeight;
// public int CNWSItem::CopyItemCNWSItem*, int
extern void * const CNWSItem__CopyItem;
// public void CNWSItem::EventHandlerunsigned long int, unsigned long int, void*, unsigned long int, unsigned long int
extern void * const CNWSItem__EventHandler;
// void CNWSItem::GetActivePropertiesListvoid
extern void * const CNWSItem__GetActivePropertiesList;
// public CNWItemProperty* CNWSItem::GetActivePropertyint
extern void * const CNWSItem__GetActiveProperty;
// void CNWSItem::GetArmorModelPartunsigned char
extern void * const CNWSItem__GetArmorModelPart;
// void CNWSItem::GetArmorValuevoid
extern void * const CNWSItem__GetArmorValue;
// public unsigned long int CNWSItem::GetCostint, int, int, int
extern void * const CNWSItem__GetCost;
// public unsigned short int CNWSItem::GetDamageFlagsvoid
extern void * const CNWSItem__GetDamageFlags;
// public CExoLocString CNWSItem::GetDescriptionint
extern void * const CNWSItem__GetDescription;
// public CExoString CNWSItem::GetDescriptionOverrideint
extern void * const CNWSItem__GetDescriptionOverride;
// public CExoString CNWSItem::GetDisplayNamevoid
extern void * const CNWSItem__GetDisplayName;
// public CExoLocString& CNWSItem::GetFirstNamevoid
extern void * const CNWSItem__GetFirstName;
// void CNWSItem::GetIdentifiedvoid
extern void * const CNWSItem__GetIdentified;
// void CNWSItem::GetInfinitevoid
extern void * const CNWSItem__GetInfinite;
// void CNWSItem::GetIsCursedvoid
extern void * const CNWSItem__GetIsCursed;
// void CNWSItem::GetIsDroppablevoid
extern void * const CNWSItem__GetIsDroppable;
// void CNWSItem::GetIsPickPocketablevoid
extern void * const CNWSItem__GetIsPickPocketable;
// void CNWSItem::GetLastUsedActivePropertiesvoid
extern void * const CNWSItem__GetLastUsedActiveProperties;
// void CNWSItem::GetLastUsedActivePropertyUsesLeftunsigned char
extern void * const CNWSItem__GetLastUsedActivePropertyUsesLeft;
// public unsigned char CNWSItem::GetMinEquipLevelvoid
extern void * const CNWSItem__GetMinEquipLevel;
// void CNWSItem::GetModelPartunsigned char
extern void * const CNWSItem__GetModelPart;
// public CExoLocString CNWSItem::GetNamevoid
extern void * const CNWSItem__GetName;
// void CNWSItem::GetNumActivePropertiesvoid
extern void * const CNWSItem__GetNumActiveProperties;
// void CNWSItem::GetNumChargesvoid
extern void * const CNWSItem__GetNumCharges;
// void CNWSItem::GetNumPassivePropertiesvoid
extern void * const CNWSItem__GetNumPassiveProperties;
// void CNWSItem::GetPassivePropertiesListvoid
extern void * const CNWSItem__GetPassivePropertiesList;
// public CNWItemProperty* CNWSItem::GetPassivePropertyint
extern void * const CNWSItem__GetPassiveProperty;
// void CNWSItem::GetPossessorvoid
extern void * const CNWSItem__GetPossessor;
// public int CNWSItem::GetPropertyByTypeCNWItemProperty**, unsigned short int, unsigned short int
extern void * const CNWSItem__GetPropertyByType;
// public int CNWSItem::GetPropertyByTypeExistsunsigned short int, unsigned short int
extern void * const CNWSItem__GetPropertyByTypeExists;
// void CNWSItem::GetRepositoryArrayIndexvoid
extern void * const CNWSItem__GetRepositoryArrayIndex;
// void CNWSItem::GetRepositoryPositionunsigned char&, unsigned char&
extern void * const CNWSItem__GetRepositoryPosition;
// void CNWSItem::GetRepositoryPtrvoid
extern void * const CNWSItem__GetRepositoryPtr;
// void CNWSItem::GetStackSizevoid
extern void * const CNWSItem__GetStackSize;
// void CNWSItem::GetStolenvoid
extern void * const CNWSItem__GetStolen;
// void CNWSItem::GetUnalteredArmorModelPartunsigned char
extern void * const CNWSItem__GetUnalteredArmorModelPart;
// void CNWSItem::GetUpdateDisplayNamevoid
extern void * const CNWSItem__GetUpdateDisplayName;
// public unsigned short int CNWSItem::GetUsedActivePropertyUsesLeftunsigned char
extern void * const CNWSItem__GetUsedActivePropertyUsesLeft;
// void CNWSItem::GetVisualEffectvoid
extern void * const CNWSItem__GetVisualEffect;
// public int CNWSItem::GetWeightvoid
extern void * const CNWSItem__GetWeight;
// void CNWSItem::InitRepositoryunsigned long int
extern void * const CNWSItem__InitRepository;
// public int CNWSItem::LoadDataFromGffCResGFF*, CResStruct*, int
extern void * const CNWSItem__LoadDataFromGff;
// public int CNWSItem::LoadFromTemplateCResRef, CExoString*
extern void * const CNWSItem__LoadFromTemplate;
// public int CNWSItem::LoadItemCResGFF*, CResStruct*, int
extern void * const CNWSItem__LoadItem;
// public int CNWSItem::MergeItemCNWSItem*
extern void * const CNWSItem__MergeItem;
// public void CNWSItem::OpenInventoryunsigned long int
extern void * const CNWSItem__OpenInventory;
// public void CNWSItem::ReadContainerItemsFromGffCResGFF*, CResStruct*
extern void * const CNWSItem__ReadContainerItemsFromGff;
// public int CNWSItem::RemoveActivePropertyint
extern void * const CNWSItem__RemoveActiveProperty;
// public void CNWSItem::RemoveFromAreavoid
extern void * const CNWSItem__RemoveFromArea;
// public void CNWSItem::RemoveItemPropertiesCNWSCreature*, unsigned long int
extern void * const CNWSItem__RemoveItemProperties;
// public int CNWSItem::RemovePassivePropertyint
extern void * const CNWSItem__RemovePassiveProperty;
// public void CNWSItem::RestoreUsedActivePropertiesint
extern void * const CNWSItem__RestoreUsedActiveProperties;
// public void CNWSItem::RestoreUsedActivePropertyCNWItemProperty*, int
extern void * const CNWSItem__RestoreUsedActiveProperty;
// void CNWSItem::SaveContainerItemsCResGFF*, CResStruct*
extern void * const CNWSItem__SaveContainerItems;
// public int CNWSItem::SaveItemCResGFF*, CResStruct*, int
extern void * const CNWSItem__SaveItem;
// public int CNWSItem::SaveItemPropertiesCResGFF*, CResStruct*
extern void * const CNWSItem__SaveItemProperties;
// void CNWSItem::SetArmorModelPartunsigned char, unsigned char
extern void * const CNWSItem__SetArmorModelPart;
// void CNWSItem::SetArmorValueint
extern void * const CNWSItem__SetArmorValue;
// void CNWSItem::SetBarterOwnerunsigned long int
extern void * const CNWSItem__SetBarterOwner;
// public void CNWSItem::SetDisplayNameCExoString
extern void * const CNWSItem__SetDisplayName;
// void CNWSItem::SetFirstNameunsigned long int
extern void * const CNWSItem__SetFirstName;
// public void CNWSItem::SetIdentifiedint
extern void * const CNWSItem__SetIdentified;
// public void CNWSItem::SetIdentifiedDescriptionCExoLocString
extern void * const CNWSItem__SetIdentifiedDescription;
// public void CNWSItem::SetIdentifiedDescriptionOverrideCExoString
extern void * const CNWSItem__SetIdentifiedDescriptionOverride;
// void CNWSItem::SetInfiniteint
extern void * const CNWSItem__SetInfinite;
// void CNWSItem::SetIsCursedint
extern void * const CNWSItem__SetIsCursed;
// void CNWSItem::SetIsDroppableint
extern void * const CNWSItem__SetIsDroppable;
// void CNWSItem::SetIsPickPocketableint
extern void * const CNWSItem__SetIsPickPocketable;
// void CNWSItem::SetModelPartunsigned char, unsigned char
extern void * const CNWSItem__SetModelPart;
// public void CNWSItem::SetNameCExoLocString
extern void * const CNWSItem__SetName;
// void CNWSItem::SetNumChargesint
extern void * const CNWSItem__SetNumCharges;
// public void CNWSItem::SetPossessorunsigned long int, int, int, int
extern void * const CNWSItem__SetPossessor;
// void CNWSItem::SetRecalculateCostFlagint
extern void * const CNWSItem__SetRecalculateCostFlag;
// void CNWSItem::SetRepositoryArrayIndexunsigned short int
extern void * const CNWSItem__SetRepositoryArrayIndex;
// void CNWSItem::SetRepositoryPositionunsigned char, unsigned char
extern void * const CNWSItem__SetRepositoryPosition;
// void CNWSItem::SetStackSizeint
extern void * const CNWSItem__SetStackSize;
// void CNWSItem::SetStolenint
extern void * const CNWSItem__SetStolen;
// void CNWSItem::SetUnalteredArmorModelPartunsigned char, unsigned char
extern void * const CNWSItem__SetUnalteredArmorModelPart;
// public void CNWSItem::SetUnidentifiedDescriptionCExoLocString
extern void * const CNWSItem__SetUnidentifiedDescription;
// public void CNWSItem::SetUnidentifiedDescriptionOverrideCExoString
extern void * const CNWSItem__SetUnidentifiedDescriptionOverride;
// void CNWSItem::SetUpdateDisplayNameint
extern void * const CNWSItem__SetUpdateDisplayName;
// void CNWSItem::SetWeightint
extern void * const CNWSItem__SetWeight;
// public CNWSItem* CNWSItem::SplitItemint
extern void * const CNWSItem__SplitItem;
// public void CNWSItem::UpdateUsedActivePropertiesint
extern void * const CNWSItem__UpdateUsedActiveProperties;
// public void CNWSItem::UpdateVisualEffectvoid
extern void * const CNWSItem__UpdateVisualEffect;

// public CNWSItemPropertyHandler::~CNWSItemPropertyHandlervoid
extern void * const CNWSItemPropertyHandler__CNWSItemPropertyHandlerDtor;
// public int CNWSItemPropertyHandler::ApplyAbilityBonusCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int, int
extern void * const CNWSItemPropertyHandler__ApplyAbilityBonus;
// public int CNWSItemPropertyHandler::ApplyACBonusCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int, int
extern void * const CNWSItemPropertyHandler__ApplyACBonus;
// public int CNWSItemPropertyHandler::ApplyArcaneSpellFailureCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int, int
extern void * const CNWSItemPropertyHandler__ApplyArcaneSpellFailure;
// public int CNWSItemPropertyHandler::ApplyAttackBonusCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int, int
extern void * const CNWSItemPropertyHandler__ApplyAttackBonus;
// public int CNWSItemPropertyHandler::ApplyAttackPenaltyCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int, int
extern void * const CNWSItemPropertyHandler__ApplyAttackPenalty;
// public int CNWSItemPropertyHandler::ApplyBonusFeatCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int, int
extern void * const CNWSItemPropertyHandler__ApplyBonusFeat;
// public int CNWSItemPropertyHandler::ApplyBonusSpellOfLevelCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int, int
extern void * const CNWSItemPropertyHandler__ApplyBonusSpellOfLevel;
// public int CNWSItemPropertyHandler::ApplyChangedSavingThrowCNWSItem*, int, CNWItemProperty*, CNWSCreature*, int
extern void * const CNWSItemPropertyHandler__ApplyChangedSavingThrow;
// public int CNWSItemPropertyHandler::ApplyChangedSavingThrowVsXCNWSItem*, int, CNWItemProperty*, CNWSCreature*, int
extern void * const CNWSItemPropertyHandler__ApplyChangedSavingThrowVsX;
// public int CNWSItemPropertyHandler::ApplyDamageBonusCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int, int
extern void * const CNWSItemPropertyHandler__ApplyDamageBonus;
// public int CNWSItemPropertyHandler::ApplyDamageImmunityCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int, int
extern void * const CNWSItemPropertyHandler__ApplyDamageImmunity;
// public int CNWSItemPropertyHandler::ApplyDamagePenaltyCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int, int
extern void * const CNWSItemPropertyHandler__ApplyDamagePenalty;
// public int CNWSItemPropertyHandler::ApplyDamageReductionCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int, int
extern void * const CNWSItemPropertyHandler__ApplyDamageReduction;
// public int CNWSItemPropertyHandler::ApplyDamageResistanceCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int, int
extern void * const CNWSItemPropertyHandler__ApplyDamageResistance;
// public int CNWSItemPropertyHandler::ApplyDamageVulnerabilityCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int, int
extern void * const CNWSItemPropertyHandler__ApplyDamageVulnerability;
// public int CNWSItemPropertyHandler::ApplyDarkVisionCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int, int
extern void * const CNWSItemPropertyHandler__ApplyDarkVision;
// public int CNWSItemPropertyHandler::ApplyDecreaseAbilityCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int, int
extern void * const CNWSItemPropertyHandler__ApplyDecreaseAbility;
// public int CNWSItemPropertyHandler::ApplyDecreaseACCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int, int
extern void * const CNWSItemPropertyHandler__ApplyDecreaseAC;
// public int CNWSItemPropertyHandler::ApplyDecreaseSkillCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int, int
extern void * const CNWSItemPropertyHandler__ApplyDecreaseSkill;
// public int CNWSItemPropertyHandler::ApplyEnhancementBonusCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int, int
extern void * const CNWSItemPropertyHandler__ApplyEnhancementBonus;
// public int CNWSItemPropertyHandler::ApplyEnhancementPenaltyCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int, int
extern void * const CNWSItemPropertyHandler__ApplyEnhancementPenalty;
// public int CNWSItemPropertyHandler::ApplyFreeActionCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int, int
extern void * const CNWSItemPropertyHandler__ApplyFreeAction;
// public int CNWSItemPropertyHandler::ApplyHasteCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int, int
extern void * const CNWSItemPropertyHandler__ApplyHaste;
// public int CNWSItemPropertyHandler::ApplyHolyAvengerCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int, int
extern void * const CNWSItemPropertyHandler__ApplyHolyAvenger;
// public int CNWSItemPropertyHandler::ApplyImmunityCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int, int
extern void * const CNWSItemPropertyHandler__ApplyImmunity;
// public int CNWSItemPropertyHandler::ApplyImprovedEvasionCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int, int
extern void * const CNWSItemPropertyHandler__ApplyImprovedEvasion;
// public int CNWSItemPropertyHandler::ApplyImprovedSavingThrowCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int, int
extern void * const CNWSItemPropertyHandler__ApplyImprovedSavingThrow;
// public int CNWSItemPropertyHandler::ApplyImprovedSavingThrowVsXCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int, int
extern void * const CNWSItemPropertyHandler__ApplyImprovedSavingThrowVsX;
// public int CNWSItemPropertyHandler::ApplyImprovedSpellResistanceCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int, int
extern void * const CNWSItemPropertyHandler__ApplyImprovedSpellResistance;
// public int CNWSItemPropertyHandler::ApplyLightCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int, int
extern void * const CNWSItemPropertyHandler__ApplyLight;
// public int CNWSItemPropertyHandler::ApplyReducedSavingThrowCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int, int
extern void * const CNWSItemPropertyHandler__ApplyReducedSavingThrow;
// public int CNWSItemPropertyHandler::ApplyReducedSavingThrowVsXCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int, int
extern void * const CNWSItemPropertyHandler__ApplyReducedSavingThrowVsX;
// public int CNWSItemPropertyHandler::ApplyRegenerationCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int, int
extern void * const CNWSItemPropertyHandler__ApplyRegeneration;
// public int CNWSItemPropertyHandler::ApplySkillBonusCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int, int
extern void * const CNWSItemPropertyHandler__ApplySkillBonus;
// public int CNWSItemPropertyHandler::ApplySpecialWalkCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int, int
extern void * const CNWSItemPropertyHandler__ApplySpecialWalk;
// public int CNWSItemPropertyHandler::ApplySpellImmunityLevelCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int, int
extern void * const CNWSItemPropertyHandler__ApplySpellImmunityLevel;
// public int CNWSItemPropertyHandler::ApplySpellImmunitySchoolCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int, int
extern void * const CNWSItemPropertyHandler__ApplySpellImmunitySchool;
// public int CNWSItemPropertyHandler::ApplySpellImmunitySpecificCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int, int
extern void * const CNWSItemPropertyHandler__ApplySpellImmunitySpecific;
// public int CNWSItemPropertyHandler::ApplyTrueSeeingCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int, int
extern void * const CNWSItemPropertyHandler__ApplyTrueSeeing;
// public int CNWSItemPropertyHandler::ApplyTurnResistanceCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int, int
extern void * const CNWSItemPropertyHandler__ApplyTurnResistance;
// public int CNWSItemPropertyHandler::ApplyUnlimitedAmmoCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int, int
extern void * const CNWSItemPropertyHandler__ApplyUnlimitedAmmo;
// public void CNWSItemPropertyHandler::InitializeItemPropertiesvoid
extern void * const CNWSItemPropertyHandler__InitializeItemProperties;
// public int CNWSItemPropertyHandler::OnItemPropertyAppliedCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int, int
extern void * const CNWSItemPropertyHandler__OnItemPropertyApplied;
// public int CNWSItemPropertyHandler::OnItemPropertyRemovedCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int
extern void * const CNWSItemPropertyHandler__OnItemPropertyRemoved;
// public int CNWSItemPropertyHandler::RemoveAbilityBonusCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int
extern void * const CNWSItemPropertyHandler__RemoveAbilityBonus;
// public int CNWSItemPropertyHandler::RemoveACBonusCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int
extern void * const CNWSItemPropertyHandler__RemoveACBonus;
// public int CNWSItemPropertyHandler::RemoveArcaneSpellFailureCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int
extern void * const CNWSItemPropertyHandler__RemoveArcaneSpellFailure;
// public int CNWSItemPropertyHandler::RemoveAttackBonusCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int
extern void * const CNWSItemPropertyHandler__RemoveAttackBonus;
// public int CNWSItemPropertyHandler::RemoveAttackPenaltyCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int
extern void * const CNWSItemPropertyHandler__RemoveAttackPenalty;
// public int CNWSItemPropertyHandler::RemoveBonusFeatCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int
extern void * const CNWSItemPropertyHandler__RemoveBonusFeat;
// public int CNWSItemPropertyHandler::RemoveBonusSpellOfLevelCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int
extern void * const CNWSItemPropertyHandler__RemoveBonusSpellOfLevel;
// public int CNWSItemPropertyHandler::RemoveChangedSavingThrowint, CNWSItem*, CNWItemProperty*, CNWSCreature*
extern void * const CNWSItemPropertyHandler__RemoveChangedSavingThrow;
// public int CNWSItemPropertyHandler::RemoveChangedSavingThrowVsXint, CNWSItem*, CNWItemProperty*, CNWSCreature*
extern void * const CNWSItemPropertyHandler__RemoveChangedSavingThrowVsX;
// public int CNWSItemPropertyHandler::RemoveDamageBonusCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int
extern void * const CNWSItemPropertyHandler__RemoveDamageBonus;
// public int CNWSItemPropertyHandler::RemoveDamageImmunityCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int
extern void * const CNWSItemPropertyHandler__RemoveDamageImmunity;
// public int CNWSItemPropertyHandler::RemoveDamagePenaltyCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int
extern void * const CNWSItemPropertyHandler__RemoveDamagePenalty;
// public int CNWSItemPropertyHandler::RemoveDamageReductionCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int
extern void * const CNWSItemPropertyHandler__RemoveDamageReduction;
// public int CNWSItemPropertyHandler::RemoveDamageResistanceCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int
extern void * const CNWSItemPropertyHandler__RemoveDamageResistance;
// public int CNWSItemPropertyHandler::RemoveDamageVulnerabilityCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int
extern void * const CNWSItemPropertyHandler__RemoveDamageVulnerability;
// public int CNWSItemPropertyHandler::RemoveDarkVisionCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int
extern void * const CNWSItemPropertyHandler__RemoveDarkVision;
// public int CNWSItemPropertyHandler::RemoveDecreaseAbilityCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int
extern void * const CNWSItemPropertyHandler__RemoveDecreaseAbility;
// public int CNWSItemPropertyHandler::RemoveDecreaseACCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int
extern void * const CNWSItemPropertyHandler__RemoveDecreaseAC;
// public int CNWSItemPropertyHandler::RemoveDecreaseSkillCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int
extern void * const CNWSItemPropertyHandler__RemoveDecreaseSkill;
// public int CNWSItemPropertyHandler::RemoveEnhancementBonusCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int
extern void * const CNWSItemPropertyHandler__RemoveEnhancementBonus;
// public int CNWSItemPropertyHandler::RemoveEnhancementPenaltyCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int
extern void * const CNWSItemPropertyHandler__RemoveEnhancementPenalty;
// public int CNWSItemPropertyHandler::RemoveFreeActionCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int
extern void * const CNWSItemPropertyHandler__RemoveFreeAction;
// public int CNWSItemPropertyHandler::RemoveHasteCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int
extern void * const CNWSItemPropertyHandler__RemoveHaste;
// public int CNWSItemPropertyHandler::RemoveHolyAvengerCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int
extern void * const CNWSItemPropertyHandler__RemoveHolyAvenger;
// public int CNWSItemPropertyHandler::RemoveImmunityCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int
extern void * const CNWSItemPropertyHandler__RemoveImmunity;
// public int CNWSItemPropertyHandler::RemoveImprovedEvasionCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int
extern void * const CNWSItemPropertyHandler__RemoveImprovedEvasion;
// public int CNWSItemPropertyHandler::RemoveImprovedSavingThrowCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int
extern void * const CNWSItemPropertyHandler__RemoveImprovedSavingThrow;
// public int CNWSItemPropertyHandler::RemoveImprovedSavingThrowVsXCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int
extern void * const CNWSItemPropertyHandler__RemoveImprovedSavingThrowVsX;
// public int CNWSItemPropertyHandler::RemoveImprovedSpellResistanceCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int
extern void * const CNWSItemPropertyHandler__RemoveImprovedSpellResistance;
// public int CNWSItemPropertyHandler::RemoveLightCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int
extern void * const CNWSItemPropertyHandler__RemoveLight;
// public int CNWSItemPropertyHandler::RemoveReducedSavingThrowCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int
extern void * const CNWSItemPropertyHandler__RemoveReducedSavingThrow;
// public int CNWSItemPropertyHandler::RemoveReducedSavingThrowVsXCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int
extern void * const CNWSItemPropertyHandler__RemoveReducedSavingThrowVsX;
// public int CNWSItemPropertyHandler::RemoveRegenerationCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int
extern void * const CNWSItemPropertyHandler__RemoveRegeneration;
// public int CNWSItemPropertyHandler::RemoveSkillBonusCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int
extern void * const CNWSItemPropertyHandler__RemoveSkillBonus;
// public int CNWSItemPropertyHandler::RemoveSpecialWalkCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int
extern void * const CNWSItemPropertyHandler__RemoveSpecialWalk;
// public int CNWSItemPropertyHandler::RemoveSpellImmunityLevelCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int
extern void * const CNWSItemPropertyHandler__RemoveSpellImmunityLevel;
// public int CNWSItemPropertyHandler::RemoveSpellImmunitySchoolCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int
extern void * const CNWSItemPropertyHandler__RemoveSpellImmunitySchool;
// public int CNWSItemPropertyHandler::RemoveSpellImmunitySpecificCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int
extern void * const CNWSItemPropertyHandler__RemoveSpellImmunitySpecific;
// public int CNWSItemPropertyHandler::RemoveTrueSeeingCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int
extern void * const CNWSItemPropertyHandler__RemoveTrueSeeing;
// public int CNWSItemPropertyHandler::RemoveTurnResistanceCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int
extern void * const CNWSItemPropertyHandler__RemoveTurnResistance;
// public int CNWSItemPropertyHandler::RemoveUnlimitedAmmoCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int
extern void * const CNWSItemPropertyHandler__RemoveUnlimitedAmmo;

// public CNWSJournal::CNWSJournalvoid
extern void * const CNWSJournal__CNWSJournalCtor;
// public CNWSJournal::~CNWSJournalvoid
extern void * const CNWSJournal__CNWSJournalDtor;
// public void CNWSJournal::DestroyCExoString
extern void * const CNWSJournal__Destroy;
// public void CNWSJournal::SetDateCExoString, unsigned long int, int
extern void * const CNWSJournal__SetDate;
// public void CNWSJournal::SetPictureCExoString, int, int
extern void * const CNWSJournal__SetPicture;
// public void CNWSJournal::SetStateCExoString, unsigned long int, int
extern void * const CNWSJournal__SetState;
// public void CNWSJournal::SetTimeCExoString, unsigned long int, int
extern void * const CNWSJournal__SetTime;

// public CNWSkill::CNWSkillvoid
extern void * const CNWSkill__CNWSkillCtor;
// public CNWSkill::~CNWSkillvoid
extern void * const CNWSkill__CNWSkillDtor;
// void CNWSkill::GetDescriptionTextvoid
extern void * const CNWSkill__GetDescriptionText;
// void CNWSkill::GetNameTextvoid
extern void * const CNWSkill__GetNameText;

// public CNWSMessage::CNWSMessagevoid
extern void * const CNWSMessage__CNWSMessageCtor;
// public CNWSMessage::~CNWSMessagevoid
extern void * const CNWSMessage__CNWSMessageDtor;
// protected void CNWSMessage::AddActiveItemPropertiesToMessageCNWSItem*, CNWSCreature*
extern void * const CNWSMessage__AddActiveItemPropertiesToMessage;
// void CNWSMessage::AddAreaOfEffectObjectToMessageCNWSAreaOfEffectObject*
extern void * const CNWSMessage__AddAreaOfEffectObjectToMessage;
// void CNWSMessage::AddDoorAppearanceToMessageCNWSDoor*
extern void * const CNWSMessage__AddDoorAppearanceToMessage;
// protected void CNWSMessage::AddItemAppearanceToMessageCNWSItem*
extern void * const CNWSMessage__AddItemAppearanceToMessage;
// protected void CNWSMessage::AddPlaceableAppearanceToMessageCNWSPlaceable*
extern void * const CNWSMessage__AddPlaceableAppearanceToMessage;
// void CNWSMessage::AddTriggerGeometryToMessageCNWSTrigger*
extern void * const CNWSMessage__AddTriggerGeometryToMessage;
// void CNWSMessage::AssignCreatureListsCExoArrayListTemplatedunsignedlong*, CExoArrayListTemplatedunsignedlong*
extern void * const CNWSMessage__AssignCreatureLists;
// protected void CNWSMessage::AssignVisualEffectListsCExoArrayListTemplatedCLoopingVisualEffectPtr*, CExoArrayListTemplatedCLoopingVisualEffectPtr*
extern void * const CNWSMessage__AssignVisualEffectLists;
// void CNWSMessage::CompareCreatureListsCExoArrayListTemplatedunsignedlong*, CExoArrayListTemplatedunsignedlong*
extern void * const CNWSMessage__CompareCreatureLists;
// protected int CNWSMessage::CompareVisualEffectListsCExoArrayListTemplatedCLoopingVisualEffectPtr*, CExoArrayListTemplatedCLoopingVisualEffectPtr*
extern void * const CNWSMessage__CompareVisualEffectLists;
// protected unsigned long int CNWSMessage::ComputeAppearanceUpdateRequiredCNWSObject*, CLastUpdateObject*
extern void * const CNWSMessage__ComputeAppearanceUpdateRequired;
// public int CNWSMessage::ComputeGameObjectUpdateForCategoryunsigned long int, unsigned long int, CNWSPlayer*, CNWSObject*, CGameObjectArray*, CNWSPlayerLUOSortedObjectList*, int
extern void * const CNWSMessage__ComputeGameObjectUpdateForCategory;
// public void CNWSMessage::ComputeGameObjectUpdateForObjectCNWSPlayer*, CNWSObject*, CGameObjectArray*, unsigned long int
extern void * const CNWSMessage__ComputeGameObjectUpdateForObject;
// void CNWSMessage::ComputeGameObjectUpdateForYourselfCNWSPlayer*, CNWSObject*, CGameObjectArray*, unsigned long int
extern void * const CNWSMessage__ComputeGameObjectUpdateForYourself;
// void CNWSMessage::ComputeGameObjectUpdateForYourselfTooCNWSPlayer*, CNWSObject*, CGameObjectArray*, unsigned long int
extern void * const CNWSMessage__ComputeGameObjectUpdateForYourselfToo;
// protected int CNWSMessage::ComputeInventoryUpdateRequiredCNWSPlayer*, unsigned long int, CNWSPlayerInventoryGUI*
extern void * const CNWSMessage__ComputeInventoryUpdateRequired;
// protected int CNWSMessage::ComputeLastUpdate_ActionQueueCNWSCreature*, CNWSPlayerLastUpdateObject*
extern void * const CNWSMessage__ComputeLastUpdate_ActionQueue;
// protected unsigned short int CNWSMessage::ComputeLastUpdate_AssociateStateCNWSCreature*
extern void * const CNWSMessage__ComputeLastUpdate_AssociateState;
// protected int CNWSMessage::ComputeLastUpdate_AutoMapCNWSCreature*, CNWSPlayerLastUpdateObject*
extern void * const CNWSMessage__ComputeLastUpdate_AutoMap;
// protected int CNWSMessage::ComputeLastUpdate_CompareSpellLikeAbilityCNWSCreature*, CNWSPlayerLastUpdateObject*
extern void * const CNWSMessage__ComputeLastUpdate_CompareSpellLikeAbility;
// public int CNWSMessage::ComputeLastUpdate_GuiEffectIconsCNWSCreature*, CExoArrayListTemplatedCEffectIconObjectPtr*, int
extern void * const CNWSMessage__ComputeLastUpdate_GuiEffectIcons;
// protected int CNWSMessage::ComputeLastUpdate_GuiFeatsCNWSCreature*, CNWSPlayerLastUpdateObject*
extern void * const CNWSMessage__ComputeLastUpdate_GuiFeats;
// protected int CNWSMessage::ComputeLastUpdate_GuiKnownSpellsCNWSCreature*, CNWSPlayerLastUpdateObject*
extern void * const CNWSMessage__ComputeLastUpdate_GuiKnownSpells;
// protected int CNWSMessage::ComputeLastUpdate_GuiKnownSpellUsesCNWSCreature*, CNWSPlayerLastUpdateObject*
extern void * const CNWSMessage__ComputeLastUpdate_GuiKnownSpellUses;
// protected int CNWSMessage::ComputeLastUpdate_GuiMemorizedSpellsCNWSCreature*, CNWSPlayerLastUpdateObject*
extern void * const CNWSMessage__ComputeLastUpdate_GuiMemorizedSpells;
// protected int CNWSMessage::ComputeLastUpdate_GuiNumberMemorizedSpellsCNWSCreature*, CNWSPlayerLastUpdateObject*
extern void * const CNWSMessage__ComputeLastUpdate_GuiNumberMemorizedSpells;
// void CNWSMessage::ComputeLastUpdate_GuiSkillsCNWSCreature*
extern void * const CNWSMessage__ComputeLastUpdate_GuiSkills;
// protected unsigned long int CNWSMessage::ComputeLastUpdate_PlayerStateCNWSCreature*
extern void * const CNWSMessage__ComputeLastUpdate_PlayerState;
// protected void CNWSMessage::ComputeLastUpdate_StoreUpdateSpellLikeAbilityCNWSCreature*, CNWSPlayerLastUpdateObject*
extern void * const CNWSMessage__ComputeLastUpdate_StoreUpdateSpellLikeAbility;
// protected void CNWSMessage::ComputeLastUpdate_WriteSpellLikeAbilityCNWSCreature*, CNWSPlayerLastUpdateObject*
extern void * const CNWSMessage__ComputeLastUpdate_WriteSpellLikeAbility;
// protected unsigned long int CNWSMessage::ComputeNumAutoMapUpdatesRequiredCNWSCreature*, CNWSPlayerLastUpdateObject*, unsigned long int*
extern void * const CNWSMessage__ComputeNumAutoMapUpdatesRequired;
// protected int CNWSMessage::ComputeQuickbarItemUseCountUpdateRequiredCNWSObject*, CLastUpdateObject*
extern void * const CNWSMessage__ComputeQuickbarItemUseCountUpdateRequired;
// void CNWSMessage::ComputeRepositoryUpdateRequiredCNWSPlayer*, CExoLinkedListNode*, CExoLinkedListNode*
extern void * const CNWSMessage__ComputeRepositoryUpdateRequired;
// protected unsigned long int CNWSMessage::ComputeUpdateRequiredCNWSPlayer*, CNWSObject*, CLastUpdateObject*, int
extern void * const CNWSMessage__ComputeUpdateRequired;
// protected int CNWSMessage::ComputeVisibilityListsCNWSCreature*, CNWSPlayerLastUpdateObject*
extern void * const CNWSMessage__ComputeVisibilityLists;
// public CLastUpdateObject* CNWSMessage::CreateNewLastUpdateObjectCNWSPlayer*, CNWSObject*, unsigned long int*, unsigned long int*
extern void * const CNWSMessage__CreateNewLastUpdateObject;
// public void CNWSMessage::DeleteLastUpdateObjectsForObjectCNWSPlayer*, unsigned long int
extern void * const CNWSMessage__DeleteLastUpdateObjectsForObject;
// public void CNWSMessage::DeleteLastUpdateObjectsInOtherAreasCNWSPlayer*
extern void * const CNWSMessage__DeleteLastUpdateObjectsInOtherAreas;
// public int CNWSMessage::GetLocStringServerunsigned long int, CExoLocString, CExoLocString, CExoString&, float&, unsigned char
extern void * const CNWSMessage__GetLocStringServer;
// public int CNWSMessage::HandlePlayerToServerAreaMessageCNWSPlayer*, unsigned char
extern void * const CNWSMessage__HandlePlayerToServerAreaMessage;
// void CNWSMessage::HandlePlayerToServerBarterCNWSPlayer*, unsigned char
extern void * const CNWSMessage__HandlePlayerToServerBarter;
// void CNWSMessage::HandlePlayerToServerBarter_AcceptTradeCNWSPlayer*
extern void * const CNWSMessage__HandlePlayerToServerBarter_AcceptTrade;
// public int CNWSMessage::HandlePlayerToServerBarter_AddItemCNWSPlayer*
extern void * const CNWSMessage__HandlePlayerToServerBarter_AddItem;
// public int CNWSMessage::HandlePlayerToServerBarter_CloseBarterCNWSPlayer*
extern void * const CNWSMessage__HandlePlayerToServerBarter_CloseBarter;
// void CNWSMessage::HandlePlayerToServerBarter_LockListCNWSPlayer*
extern void * const CNWSMessage__HandlePlayerToServerBarter_LockList;
// public int CNWSMessage::HandlePlayerToServerBarter_MoveItemCNWSPlayer*
extern void * const CNWSMessage__HandlePlayerToServerBarter_MoveItem;
// public int CNWSMessage::HandlePlayerToServerBarter_RemoveItemCNWSPlayer*
extern void * const CNWSMessage__HandlePlayerToServerBarter_RemoveItem;
// void CNWSMessage::HandlePlayerToServerBarter_StartBarterCNWSPlayer*
extern void * const CNWSMessage__HandlePlayerToServerBarter_StartBarter;
// void CNWSMessage::HandlePlayerToServerBarter_WindowCNWSPlayer*
extern void * const CNWSMessage__HandlePlayerToServerBarter_Window;
// void CNWSMessage::HandlePlayerToServerCharacterDownloadCNWSPlayer*, unsigned char
extern void * const CNWSMessage__HandlePlayerToServerCharacterDownload;
// public int CNWSMessage::HandlePlayerToServerCharacterSheetMessageCNWSPlayer*, unsigned char
extern void * const CNWSMessage__HandlePlayerToServerCharacterSheetMessage;
// public int CNWSMessage::HandlePlayerToServerCharListMessageCNWSPlayer*, unsigned char
extern void * const CNWSMessage__HandlePlayerToServerCharListMessage;
// public int CNWSMessage::HandlePlayerToServerChatMessageCNWSPlayer*, unsigned char
extern void * const CNWSMessage__HandlePlayerToServerChatMessage;
// public int CNWSMessage::HandlePlayerToServerCheatMessageCNWSPlayer*, unsigned char
extern void * const CNWSMessage__HandlePlayerToServerCheatMessage;
// public int CNWSMessage::HandlePlayerToServerCutsceneCNWSPlayer*, unsigned char
extern void * const CNWSMessage__HandlePlayerToServerCutscene;
// public int CNWSMessage::HandlePlayerToServerDialogMessageCNWSPlayer*, unsigned char
extern void * const CNWSMessage__HandlePlayerToServerDialogMessage;
// public int CNWSMessage::HandlePlayerToServerDungeonMasterMessageCNWSPlayer*, unsigned char, int
extern void * const CNWSMessage__HandlePlayerToServerDungeonMasterMessage;
// public int CNWSMessage::HandlePlayerToServerGameObjectUpdateCNWSPlayer*, unsigned char
extern void * const CNWSMessage__HandlePlayerToServerGameObjectUpdate;
// public int CNWSMessage::HandlePlayerToServerGoldMessageCNWSPlayer*, unsigned char
extern void * const CNWSMessage__HandlePlayerToServerGoldMessage;
// public int CNWSMessage::HandlePlayerToServerGroupInputMessageCNWSPlayer*, unsigned char
extern void * const CNWSMessage__HandlePlayerToServerGroupInputMessage;
// public int CNWSMessage::HandlePlayerToServerGroupInputWalkToWaypointCNWSPlayer*, CNWSCreature*, unsigned long int, float, float, float, unsigned char, int, int, unsigned long int
extern void * const CNWSMessage__HandlePlayerToServerGroupInputWalkToWaypoint;
// public int CNWSMessage::HandlePlayerToServerGuiContainerMessageCNWSPlayer*, unsigned char
extern void * const CNWSMessage__HandlePlayerToServerGuiContainerMessage;
// public int CNWSMessage::HandlePlayerToServerGuiInventoryMessageCNWSPlayer*, unsigned char
extern void * const CNWSMessage__HandlePlayerToServerGuiInventoryMessage;
// void CNWSMessage::HandlePlayerToServerGuiQuickbarCNWSPlayer*, unsigned char
extern void * const CNWSMessage__HandlePlayerToServerGuiQuickbar;
// public int CNWSMessage::HandlePlayerToServerGuiQuickbar_SetButtonCNWSPlayer*, unsigned char, unsigned char
extern void * const CNWSMessage__HandlePlayerToServerGuiQuickbar_SetButton;
// public int CNWSMessage::HandlePlayerToServerInputAbortDriveControlCNWSPlayer*
extern void * const CNWSMessage__HandlePlayerToServerInputAbortDriveControl;
// void CNWSMessage::HandlePlayerToServerInputCancelGuiTimingEventCNWSPlayer*
extern void * const CNWSMessage__HandlePlayerToServerInputCancelGuiTimingEvent;
// public int CNWSMessage::HandlePlayerToServerInputDriveControlCNWSPlayer*
extern void * const CNWSMessage__HandlePlayerToServerInputDriveControl;
// public int CNWSMessage::HandlePlayerToServerInputMessageCNWSPlayer*, unsigned char
extern void * const CNWSMessage__HandlePlayerToServerInputMessage;
// public int CNWSMessage::HandlePlayerToServerInputWalkToWaypointCNWSPlayer*
extern void * const CNWSMessage__HandlePlayerToServerInputWalkToWaypoint;
// public int CNWSMessage::HandlePlayerToServerInventoryMessageCNWSPlayer*, unsigned char
extern void * const CNWSMessage__HandlePlayerToServerInventoryMessage;
// public int CNWSMessage::HandlePlayerToServerJournalMessageCNWSPlayer*, unsigned char
extern void * const CNWSMessage__HandlePlayerToServerJournalMessage;
// public int CNWSMessage::HandlePlayerToServerLevelUpMessageCNWSPlayer*, unsigned char
extern void * const CNWSMessage__HandlePlayerToServerLevelUpMessage;
// public int CNWSMessage::HandlePlayerToServerLoginMessageCNWSPlayer*, unsigned char
extern void * const CNWSMessage__HandlePlayerToServerLoginMessage;
// public int CNWSMessage::HandlePlayerToServerMapPinChangePinCNWSPlayer*
extern void * const CNWSMessage__HandlePlayerToServerMapPinChangePin;
// public int CNWSMessage::HandlePlayerToServerMapPinDestroyMapPinCNWSPlayer*
extern void * const CNWSMessage__HandlePlayerToServerMapPinDestroyMapPin;
// void CNWSMessage::HandlePlayerToServerMapPinMessageCNWSPlayer*, unsigned char
extern void * const CNWSMessage__HandlePlayerToServerMapPinMessage;
// public int CNWSMessage::HandlePlayerToServerMapPinSetMapPinAtCNWSPlayer*
extern void * const CNWSMessage__HandlePlayerToServerMapPinSetMapPinAt;
// public int CNWSMessage::HandlePlayerToServerMessageunsigned long int, unsigned char*, unsigned long int
extern void * const CNWSMessage__HandlePlayerToServerMessage;
// public int CNWSMessage::HandlePlayerToServerModuleMessageCNWSPlayer*, unsigned char
extern void * const CNWSMessage__HandlePlayerToServerModuleMessage;
// public int CNWSMessage::HandlePlayerToServerPartyCNWSPlayer*, unsigned char
extern void * const CNWSMessage__HandlePlayerToServerParty;
// void CNWSMessage::HandlePlayerToServerPlayerDeathCNWSPlayer*, unsigned char
extern void * const CNWSMessage__HandlePlayerToServerPlayerDeath;
// public int CNWSMessage::HandlePlayerToServerPlayerListCNWSPlayer*, unsigned char
extern void * const CNWSMessage__HandlePlayerToServerPlayerList;
// void CNWSMessage::HandlePlayerToServerPlayModuleCharacterListCNWSPlayer*, unsigned char
extern void * const CNWSMessage__HandlePlayerToServerPlayModuleCharacterList;
// public int CNWSMessage::HandlePlayerToServerPlayModuleCharacterList_StartCNWSPlayer*
extern void * const CNWSMessage__HandlePlayerToServerPlayModuleCharacterList_Start;
// void CNWSMessage::HandlePlayerToServerPlayModuleCharacterList_StopCNWSPlayer*
extern void * const CNWSMessage__HandlePlayerToServerPlayModuleCharacterList_Stop;
// public int CNWSMessage::HandlePlayerToServerPortalCNWSPlayer*, unsigned char
extern void * const CNWSMessage__HandlePlayerToServerPortal;
// public int CNWSMessage::HandlePlayerToServerPVPListOperationsCNWSPlayer*, unsigned char
extern void * const CNWSMessage__HandlePlayerToServerPVPListOperations;
// public int CNWSMessage::HandlePlayerToServerQuickChatMessageCNWSPlayer*, unsigned char
extern void * const CNWSMessage__HandlePlayerToServerQuickChatMessage;
// void CNWSMessage::HandlePlayerToServerServerChatMessageCNWSPlayer*, unsigned char
extern void * const CNWSMessage__HandlePlayerToServerServerChatMessage;
// void CNWSMessage::HandlePlayerToServerServerStatusMessageCNWSPlayer*, unsigned char
extern void * const CNWSMessage__HandlePlayerToServerServerStatusMessage;
// public int CNWSMessage::HandlePlayerToServerShutDownServerCNWSPlayer*, unsigned char
extern void * const CNWSMessage__HandlePlayerToServerShutDownServer;
// public int CNWSMessage::HandlePlayerToServerStoreMessageCNWSPlayer*, unsigned char
extern void * const CNWSMessage__HandlePlayerToServerStoreMessage;
// public int CNWSMessage::HandleServerAdminToServerMessageunsigned long int, unsigned char*, unsigned long int
extern void * const CNWSMessage__HandleServerAdminToServerMessage;
// protected int CNWSMessage::HasValidStringCExoLocString&, unsigned char
extern void * const CNWSMessage__HasValidString;
// void CNWSMessage::ParseGetBoolunsigned char*, unsigned long int, int&
extern void * const CNWSMessage__ParseGetBool;
// void CNWSMessage::ParseGetStringunsigned char*, unsigned long int, CExoString&, unsigned long int
extern void * const CNWSMessage__ParseGetString;
// void CNWSMessage::ParseTokenconst char*, unsigned char**, unsigned long int&, int
extern void * const CNWSMessage__ParseToken;
// public unsigned long int CNWSMessage::ReadOBJECTIDServervoid
extern void * const CNWSMessage__ReadOBJECTIDServer;
// public unsigned long int CNWSMessage::SelectCategoryForGameObjectCGameObject*, CNWSObject*
extern void * const CNWSMessage__SelectCategoryForGameObject;
// public int CNWSMessage::SendPlayerToServerGuiInventory_StatusCNWSPlayer*, int, unsigned long int
extern void * const CNWSMessage__SendPlayerToServerGuiInventory_Status;
// public int CNWSMessage::SendServerPlayerItemUpdate_DestroyItemCNWSPlayer*, unsigned long int
extern void * const CNWSMessage__SendServerPlayerItemUpdate_DestroyItem;
// public int CNWSMessage::SendServerToAllPlayersCreatureUpdate_StripEquippedItemsunsigned long int, int, int
extern void * const CNWSMessage__SendServerToAllPlayersCreatureUpdate_StripEquippedItems;
// public int CNWSMessage::SendServerToPlayerActivatePortalunsigned long int, CExoString, CExoString, CExoString, int
extern void * const CNWSMessage__SendServerToPlayerActivatePortal;
// public int CNWSMessage::SendServerToPlayerAIActionPlaySoundunsigned long int, unsigned long int, CExoString
extern void * const CNWSMessage__SendServerToPlayerAIActionPlaySound;
// public int CNWSMessage::SendServerToPlayerAmbientBattleMusicChangeunsigned long int, int
extern void * const CNWSMessage__SendServerToPlayerAmbientBattleMusicChange;
// public int CNWSMessage::SendServerToPlayerAmbientBattleMusicPlayunsigned long int, int
extern void * const CNWSMessage__SendServerToPlayerAmbientBattleMusicPlay;
// public int CNWSMessage::SendServerToPlayerAmbientMusicChangeTrackunsigned long int, int, int
extern void * const CNWSMessage__SendServerToPlayerAmbientMusicChangeTrack;
// public int CNWSMessage::SendServerToPlayerAmbientMusicPlayunsigned long int, int
extern void * const CNWSMessage__SendServerToPlayerAmbientMusicPlay;
// public int CNWSMessage::SendServerToPlayerAmbientMusicSetDelayunsigned long int, int
extern void * const CNWSMessage__SendServerToPlayerAmbientMusicSetDelay;
// public int CNWSMessage::SendServerToPlayerAmbientSoundLoopChangeunsigned long int, int, int
extern void * const CNWSMessage__SendServerToPlayerAmbientSoundLoopChange;
// public int CNWSMessage::SendServerToPlayerAmbientSoundLoopPlayunsigned long int, int
extern void * const CNWSMessage__SendServerToPlayerAmbientSoundLoopPlay;
// public int CNWSMessage::SendServerToPlayerAmbientSoundVolumeChangeunsigned long int, int, int
extern void * const CNWSMessage__SendServerToPlayerAmbientSoundVolumeChange;
// public int CNWSMessage::SendServerToPlayerArea_ChangeDayNightCNWSPlayer*, int, float
extern void * const CNWSMessage__SendServerToPlayerArea_ChangeDayNight;
// public int CNWSMessage::SendServerToPlayerArea_ClientAreaCNWSPlayer*, CNWSArea*, float, float, float, const Vector&, int
extern void * const CNWSMessage__SendServerToPlayerArea_ClientArea;
// public int CNWSMessage::SendServerToPlayerArea_RecomputeStaticLightingunsigned long int
extern void * const CNWSMessage__SendServerToPlayerArea_RecomputeStaticLighting;
// public int CNWSMessage::SendServerToPlayerArea_VisualEffectCNWSPlayer*, unsigned short int, Vector
extern void * const CNWSMessage__SendServerToPlayerArea_VisualEffect;
// public int CNWSMessage::SendServerToPlayerArea_WeatherCNWSPlayer*, unsigned char, int
extern void * const CNWSMessage__SendServerToPlayerArea_Weather;
// public int CNWSMessage::SendServerToPlayerBarterAcceptTradeunsigned long int, unsigned long int, int, int
extern void * const CNWSMessage__SendServerToPlayerBarterAcceptTrade;
// public int CNWSMessage::SendServerToPlayerBarterCloseBarterunsigned long int, unsigned long int, int
extern void * const CNWSMessage__SendServerToPlayerBarterCloseBarter;
// public int CNWSMessage::SendServerToPlayerBarterLockListunsigned long int, unsigned long int, int, int
extern void * const CNWSMessage__SendServerToPlayerBarterLockList;
// public int CNWSMessage::SendServerToPlayerBarterRejectunsigned long int, unsigned char, unsigned char, unsigned long int
extern void * const CNWSMessage__SendServerToPlayerBarterReject;
// public int CNWSMessage::SendServerToPlayerBarterStartBarterunsigned long int, unsigned long int, unsigned long int, unsigned long int
extern void * const CNWSMessage__SendServerToPlayerBarterStartBarter;
// public int CNWSMessage::SendServerToPlayerCamera_ChangeLocationCNWSPlayer*, int, float, float, float, int
extern void * const CNWSMessage__SendServerToPlayerCamera_ChangeLocation;
// public int CNWSMessage::SendServerToPlayerCamera_LockDistanceCNWSPlayer*, int
extern void * const CNWSMessage__SendServerToPlayerCamera_LockDistance;
// public int CNWSMessage::SendServerToPlayerCamera_LockPitchCNWSPlayer*, int
extern void * const CNWSMessage__SendServerToPlayerCamera_LockPitch;
// public int CNWSMessage::SendServerToPlayerCamera_LockYawCNWSPlayer*, int
extern void * const CNWSMessage__SendServerToPlayerCamera_LockYaw;
// public int CNWSMessage::SendServerToPlayerCamera_RestoreCNWSPlayer*
extern void * const CNWSMessage__SendServerToPlayerCamera_Restore;
// public int CNWSMessage::SendServerToPlayerCamera_SetHeightCNWSPlayer*, float
extern void * const CNWSMessage__SendServerToPlayerCamera_SetHeight;
// public int CNWSMessage::SendServerToPlayerCamera_SetModeCNWSPlayer*, unsigned char
extern void * const CNWSMessage__SendServerToPlayerCamera_SetMode;
// public int CNWSMessage::SendServerToPlayerCamera_StoreCNWSPlayer*
extern void * const CNWSMessage__SendServerToPlayerCamera_Store;
// public int CNWSMessage::SendServerToPlayerCCMessageunsigned long int, unsigned char, CNWCCMessageData*, CNWSCombatAttackData*
extern void * const CNWSMessage__SendServerToPlayerCCMessage;
// public int CNWSMessage::SendServerToPlayerCharacterDownloadFailCNWSPlayer*
extern void * const CNWSMessage__SendServerToPlayerCharacterDownloadFail;
// public int CNWSMessage::SendServerToPlayerCharacterDownloadReplyCNWSPlayer*
extern void * const CNWSMessage__SendServerToPlayerCharacterDownloadReply;
// public int CNWSMessage::SendServerToPlayerCharListCNWSPlayer*
extern void * const CNWSMessage__SendServerToPlayerCharList;
// protected int CNWSMessage::SendServerToPlayerChat_DM_Silent_Shoutunsigned long int, unsigned long int, CExoString
extern void * const CNWSMessage__SendServerToPlayerChat_DM_Silent_Shout;
// protected int CNWSMessage::SendServerToPlayerChat_DM_Talkunsigned long int, unsigned long int, CExoString
extern void * const CNWSMessage__SendServerToPlayerChat_DM_Talk;
// protected int CNWSMessage::SendServerToPlayerChat_DM_Whisperunsigned long int, unsigned long int, CExoString
extern void * const CNWSMessage__SendServerToPlayerChat_DM_Whisper;
// public int CNWSMessage::SendServerToPlayerChat_Partyunsigned long int, unsigned long int, CExoString
extern void * const CNWSMessage__SendServerToPlayerChat_Party;
// protected int CNWSMessage::SendServerToPlayerChat_ServerTellunsigned long int, CExoString
extern void * const CNWSMessage__SendServerToPlayerChat_ServerTell;
// protected int CNWSMessage::SendServerToPlayerChat_Shoutunsigned long int, unsigned long int, CExoString
extern void * const CNWSMessage__SendServerToPlayerChat_Shout;
// protected int CNWSMessage::SendServerToPlayerChat_Silent_Shoutunsigned long int, unsigned long int, CExoString
extern void * const CNWSMessage__SendServerToPlayerChat_Silent_Shout;
// protected int CNWSMessage::SendServerToPlayerChat_StrRefunsigned long int, unsigned long int, unsigned char, unsigned long int
extern void * const CNWSMessage__SendServerToPlayerChat_StrRef;
// protected int CNWSMessage::SendServerToPlayerChat_Talkunsigned long int, unsigned long int, CExoString
extern void * const CNWSMessage__SendServerToPlayerChat_Talk;
// protected int CNWSMessage::SendServerToPlayerChat_Tellunsigned long int, unsigned long int, CExoString
extern void * const CNWSMessage__SendServerToPlayerChat_Tell;
// protected int CNWSMessage::SendServerToPlayerChat_Whisperunsigned long int, unsigned long int, CExoString
extern void * const CNWSMessage__SendServerToPlayerChat_Whisper;
// public int CNWSMessage::SendServerToPlayerChatMessageunsigned char, unsigned long int, CExoString, unsigned long int, const CExoString&
extern void * const CNWSMessage__SendServerToPlayerChatMessage;
// public int CNWSMessage::SendServerToPlayerChatMultiLang_Helperunsigned long int, unsigned char, unsigned long int, CExoLocString, unsigned long int, unsigned char, int, const CResRef&, int, unsigned long int
extern void * const CNWSMessage__SendServerToPlayerChatMultiLang_Helper;
// public int CNWSMessage::SendServerToPlayerChatMultiLangMessageunsigned char, unsigned long int, CExoLocString, unsigned long int, unsigned char, unsigned long int*, unsigned long int, int, const CResRef&, int, unsigned long int
extern void * const CNWSMessage__SendServerToPlayerChatMultiLangMessage;
// public int CNWSMessage::SendServerToPlayerChatStrRefMessageunsigned char, unsigned long int, unsigned long int
extern void * const CNWSMessage__SendServerToPlayerChatStrRefMessage;
// void CNWSMessage::SendServerToPlayerChatStrRefStatusMessageunsigned char, unsigned long int, unsigned long int
extern void * const CNWSMessage__SendServerToPlayerChatStrRefStatusMessage;
// public int CNWSMessage::SendServerToPlayerCheatDebugModeint
extern void * const CNWSMessage__SendServerToPlayerCheatDebugMode;
// public int CNWSMessage::SendServerToPlayerCheatNastyunsigned long int, unsigned long int
extern void * const CNWSMessage__SendServerToPlayerCheatNasty;
// public int CNWSMessage::SendServerToPlayerCheatPonyRideunsigned long int, unsigned long int
extern void * const CNWSMessage__SendServerToPlayerCheatPonyRide;
// void CNWSMessage::SendServerToPlayerCheatRainOfCowsunsigned long int, unsigned long int
extern void * const CNWSMessage__SendServerToPlayerCheatRainOfCows;
// public int CNWSMessage::SendServerToPlayerCloseStoreInventoryCNWSPlayer*
extern void * const CNWSMessage__SendServerToPlayerCloseStoreInventory;
// void CNWSMessage::SendServerToPlayerCombatRoundStartedCNWSPlayer*
extern void * const CNWSMessage__SendServerToPlayerCombatRoundStarted;
// public int CNWSMessage::SendServerToPlayerCutscene_BlackScreenCNWSPlayer*
extern void * const CNWSMessage__SendServerToPlayerCutscene_BlackScreen;
// public int CNWSMessage::SendServerToPlayerCutscene_FadeFromBlackCNWSPlayer*, float
extern void * const CNWSMessage__SendServerToPlayerCutscene_FadeFromBlack;
// public int CNWSMessage::SendServerToPlayerCutscene_FadeToBlackCNWSPlayer*, float
extern void * const CNWSMessage__SendServerToPlayerCutscene_FadeToBlack;
// void CNWSMessage::SendServerToPlayerCutscene_HideGuiCNWSPlayer*, int
extern void * const CNWSMessage__SendServerToPlayerCutscene_HideGui;
// public int CNWSMessage::SendServerToPlayerCutscene_StatusCNWSPlayer*, int, int
extern void * const CNWSMessage__SendServerToPlayerCutscene_Status;
// public int CNWSMessage::SendServerToPlayerCutscene_StopFadeCNWSPlayer*
extern void * const CNWSMessage__SendServerToPlayerCutscene_StopFade;
// public int CNWSMessage::SendServerToPlayerDebugInfo_AreaCNWSPlayer*, unsigned long int
extern void * const CNWSMessage__SendServerToPlayerDebugInfo_Area;
// public int CNWSMessage::SendServerToPlayerDebugInfo_CreatureCNWSPlayer*, unsigned long int
extern void * const CNWSMessage__SendServerToPlayerDebugInfo_Creature;
// public int CNWSMessage::SendServerToPlayerDebugInfo_DoorCNWSPlayer*, unsigned long int
extern void * const CNWSMessage__SendServerToPlayerDebugInfo_Door;
// public int CNWSMessage::SendServerToPlayerDebugInfo_ItemCNWSPlayer*, unsigned long int
extern void * const CNWSMessage__SendServerToPlayerDebugInfo_Item;
// public int CNWSMessage::SendServerToPlayerDebugInfo_PlaceableCNWSPlayer*, unsigned long int
extern void * const CNWSMessage__SendServerToPlayerDebugInfo_Placeable;
// public int CNWSMessage::SendServerToPlayerDebugInfo_TriggerCNWSPlayer*, unsigned long int
extern void * const CNWSMessage__SendServerToPlayerDebugInfo_Trigger;
// public int CNWSMessage::SendServerToPlayerDestroyDeathGUIunsigned long int
extern void * const CNWSMessage__SendServerToPlayerDestroyDeathGUI;
// public int CNWSMessage::SendServerToPlayerDialogCloseunsigned long int
extern void * const CNWSMessage__SendServerToPlayerDialogClose;
// public int CNWSMessage::SendServerToPlayerDialogEntryunsigned long int, unsigned long int, unsigned long int, CExoLocString, unsigned long int, unsigned char
extern void * const CNWSMessage__SendServerToPlayerDialogEntry;
// public int CNWSMessage::SendServerToPlayerDialogRepliesunsigned long int, CExoLocString*, unsigned long int*, unsigned long int, unsigned long int, unsigned long int, unsigned char, int, unsigned long int, int
extern void * const CNWSMessage__SendServerToPlayerDialogReplies;
// public int CNWSMessage::SendServerToPlayerDialogReplyChosenunsigned long int, unsigned long int, unsigned long int, CExoLocString, unsigned long int, unsigned char, int
extern void * const CNWSMessage__SendServerToPlayerDialogReplyChosen;
// public int CNWSMessage::SendServerToPlayerDungeonMasterAreaListCNWSPlayer*
extern void * const CNWSMessage__SendServerToPlayerDungeonMasterAreaList__0;
// public int CNWSMessage::SendServerToPlayerDungeonMasterAreaListunsigned long int
extern void * const CNWSMessage__SendServerToPlayerDungeonMasterAreaList__1;
// public int CNWSMessage::SendServerToPlayerDungeonMasterCreatorListsCNWSPlayer*
extern void * const CNWSMessage__SendServerToPlayerDungeonMasterCreatorLists;
// public int CNWSMessage::SendServerToPlayerDungeonMasterObjectListCNWSPlayer*, unsigned long int, int
extern void * const CNWSMessage__SendServerToPlayerDungeonMasterObjectList;
// public int CNWSMessage::SendServerToPlayerDungeonMastersDifficultyChangeint
extern void * const CNWSMessage__SendServerToPlayerDungeonMastersDifficultyChange;
// public int CNWSMessage::SendServerToPlayerDungeonMasterSearchByIdResultCNWSPlayer*, unsigned long int, int, unsigned long int
extern void * const CNWSMessage__SendServerToPlayerDungeonMasterSearchByIdResult;
// public int CNWSMessage::SendServerToPlayerDungeonMasterSearchByTagResultCNWSPlayer*, const CExoString&, int, unsigned long int
extern void * const CNWSMessage__SendServerToPlayerDungeonMasterSearchByTagResult;
// public int CNWSMessage::SendServerToPlayerDungeonMasterUpdatePartyListCNWSPlayer*
extern void * const CNWSMessage__SendServerToPlayerDungeonMasterUpdatePartyList__0;
// public int CNWSMessage::SendServerToPlayerDungeonMasterUpdatePartyListunsigned long int
extern void * const CNWSMessage__SendServerToPlayerDungeonMasterUpdatePartyList__1;
// public int CNWSMessage::SendServerToPlayerExamineGui_CreatureDataCNWSPlayer*, unsigned long int
extern void * const CNWSMessage__SendServerToPlayerExamineGui_CreatureData;
// public int CNWSMessage::SendServerToPlayerExamineGui_DoorDataCNWSPlayer*, unsigned long int
extern void * const CNWSMessage__SendServerToPlayerExamineGui_DoorData;
// public int CNWSMessage::SendServerToPlayerExamineGui_ItemDataCNWSPlayer*, unsigned long int
extern void * const CNWSMessage__SendServerToPlayerExamineGui_ItemData;
// public int CNWSMessage::SendServerToPlayerExamineGui_PlaceableDataCNWSPlayer*, unsigned long int
extern void * const CNWSMessage__SendServerToPlayerExamineGui_PlaceableData;
// public int CNWSMessage::SendServerToPlayerExamineGui_TrapDataCNWSPlayer*, unsigned long int, CNWSCreature*, int
extern void * const CNWSMessage__SendServerToPlayerExamineGui_TrapData;
// public int CNWSMessage::SendServerToPlayerGameObjUpdateCNWSPlayer*, unsigned long int
extern void * const CNWSMessage__SendServerToPlayerGameObjUpdate__0;
// public int CNWSMessage::SendServerToPlayerGameObjUpdateCNWSPlayer*
extern void * const CNWSMessage__SendServerToPlayerGameObjUpdate__1;
// public int CNWSMessage::SendServerToPlayerGameObjUpdate_ObjControlunsigned long int, unsigned long int
extern void * const CNWSMessage__SendServerToPlayerGameObjUpdate_ObjControl;
// public int CNWSMessage::SendServerToPlayerGameObjUpdateFloatyTextCNWSPlayer*, unsigned long int, unsigned long int
extern void * const CNWSMessage__SendServerToPlayerGameObjUpdateFloatyText;
// public int CNWSMessage::SendServerToPlayerGameObjUpdateVisEffectCNWSPlayer*, unsigned short int, unsigned long int, unsigned long int, unsigned char, unsigned char, Vector, float
extern void * const CNWSMessage__SendServerToPlayerGameObjUpdateVisEffect;
// public int CNWSMessage::SendServerToPlayerGUICharacterSheet_NotPermittedunsigned long int, unsigned long int
extern void * const CNWSMessage__SendServerToPlayerGUICharacterSheet_NotPermitted;
// public int CNWSMessage::SendServerToPlayerGuiContainerObject_StatusCNWSPlayer*, unsigned long int, int
extern void * const CNWSMessage__SendServerToPlayerGuiContainerObject_Status;
// public int CNWSMessage::SendServerToPlayerGuiQuickbar_SetButtonCNWSPlayer*, unsigned char, int
extern void * const CNWSMessage__SendServerToPlayerGuiQuickbar_SetButton;
// public int CNWSMessage::SendServerToPlayerGuiTimingEventCNWSPlayer*, int, unsigned char, unsigned long int
extern void * const CNWSMessage__SendServerToPlayerGuiTimingEvent;
// public int CNWSMessage::SendServerToPlayerInventory_ConfirmDropunsigned long int, unsigned long int, int
extern void * const CNWSMessage__SendServerToPlayerInventory_ConfirmDrop;
// public int CNWSMessage::SendServerToPlayerInventory_Dropunsigned long int, unsigned long int, int
extern void * const CNWSMessage__SendServerToPlayerInventory_Drop;
// public int CNWSMessage::SendServerToPlayerInventory_DropCancelunsigned long int, unsigned long int, int
extern void * const CNWSMessage__SendServerToPlayerInventory_DropCancel;
// public int CNWSMessage::SendServerToPlayerInventory_Equipunsigned long int, unsigned long int, unsigned long int, int
extern void * const CNWSMessage__SendServerToPlayerInventory_Equip;
// public int CNWSMessage::SendServerToPlayerInventory_EquipCancelunsigned long int, unsigned long int, unsigned long int, int
extern void * const CNWSMessage__SendServerToPlayerInventory_EquipCancel;
// protected int CNWSMessage::SendServerToPlayerInventory_LearnScrollunsigned long int, unsigned long int, unsigned char
extern void * const CNWSMessage__SendServerToPlayerInventory_LearnScroll;
// public int CNWSMessage::SendServerToPlayerInventory_Pickupunsigned long int, unsigned long int, int
extern void * const CNWSMessage__SendServerToPlayerInventory_Pickup;
// public int CNWSMessage::SendServerToPlayerInventory_PickupCancelunsigned long int, unsigned long int, int
extern void * const CNWSMessage__SendServerToPlayerInventory_PickupCancel;
// public int CNWSMessage::SendServerToPlayerInventory_RepositoryMoveunsigned long int, unsigned long int, int
extern void * const CNWSMessage__SendServerToPlayerInventory_RepositoryMove;
// public int CNWSMessage::SendServerToPlayerInventory_RepositoryMoveCancelunsigned long int, unsigned long int, int
extern void * const CNWSMessage__SendServerToPlayerInventory_RepositoryMoveCancel;
// void CNWSMessage::SendServerToPlayerInventory_SelectPageunsigned long int, unsigned char
extern void * const CNWSMessage__SendServerToPlayerInventory_SelectPage;
// public int CNWSMessage::SendServerToPlayerInventory_SelectPanelunsigned long int, unsigned char
extern void * const CNWSMessage__SendServerToPlayerInventory_SelectPanel;
// public int CNWSMessage::SendServerToPlayerInventory_Unequipunsigned long int, unsigned long int, int
extern void * const CNWSMessage__SendServerToPlayerInventory_Unequip;
// public int CNWSMessage::SendServerToPlayerInventory_UnequipCancelunsigned long int, unsigned long int, int
extern void * const CNWSMessage__SendServerToPlayerInventory_UnequipCancel;
// public int CNWSMessage::SendServerToPlayerJournalAddQuestCNWSPlayer*, CExoString, int, unsigned long int, unsigned short int, int, unsigned long int, unsigned long int, CExoLocString, CExoLocString
extern void * const CNWSMessage__SendServerToPlayerJournalAddQuest;
// public int CNWSMessage::SendServerToPlayerJournalAddWorldCNWSPlayer*, int, CExoString, CExoString, unsigned long int, unsigned long int
extern void * const CNWSMessage__SendServerToPlayerJournalAddWorld;
// void CNWSMessage::SendServerToPlayerJournalAddWorldStrrefCNWSPlayer*, unsigned long int, unsigned long int, unsigned long int, unsigned long int
extern void * const CNWSMessage__SendServerToPlayerJournalAddWorldStrref;
// public int CNWSMessage::SendServerToPlayerJournalDeleteWorldCNWSPlayer*, int
extern void * const CNWSMessage__SendServerToPlayerJournalDeleteWorld;
// void CNWSMessage::SendServerToPlayerJournalDeleteWorldAllCNWSPlayer*
extern void * const CNWSMessage__SendServerToPlayerJournalDeleteWorldAll;
// public int CNWSMessage::SendServerToPlayerJournalDeleteWorldStrrefCNWSPlayer*, unsigned long int
extern void * const CNWSMessage__SendServerToPlayerJournalDeleteWorldStrref;
// public int CNWSMessage::SendServerToPlayerJournalFullUpdateCNWSPlayer*
extern void * const CNWSMessage__SendServerToPlayerJournalFullUpdate;
// void CNWSMessage::SendServerToPlayerJournalFullUpdateNotNeededCNWSPlayer*, int
extern void * const CNWSMessage__SendServerToPlayerJournalFullUpdateNotNeeded;
// public int CNWSMessage::SendServerToPlayerJournalRemoveQuestCNWSPlayer*, CExoString
extern void * const CNWSMessage__SendServerToPlayerJournalRemoveQuest;
// void CNWSMessage::SendServerToPlayerJournalSetQuestPictureCNWSPlayer*, CExoString, int
extern void * const CNWSMessage__SendServerToPlayerJournalSetQuestPicture;
// public int CNWSMessage::SendServerToPlayerJournalUpdatedCNWSPlayer*, int, int, CExoLocString
extern void * const CNWSMessage__SendServerToPlayerJournalUpdated;
// public int CNWSMessage::SendServerToPlayerLevelUp_Beginunsigned long int, CNWSCreature*
extern void * const CNWSMessage__SendServerToPlayerLevelUp_Begin;
// public int CNWSMessage::SendServerToPlayerLevelUp_Confirmationunsigned long int, int
extern void * const CNWSMessage__SendServerToPlayerLevelUp_Confirmation;
// public int CNWSMessage::SendServerToPlayerLoadBar_EndStallEventunsigned long int, unsigned long int
extern void * const CNWSMessage__SendServerToPlayerLoadBar_EndStallEvent;
// public int CNWSMessage::SendServerToPlayerLoadBar_StartStallEventunsigned long int
extern void * const CNWSMessage__SendServerToPlayerLoadBar_StartStallEvent;
// public int CNWSMessage::SendServerToPlayerLoadBar_UpdateStallEventunsigned long int, unsigned long int
extern void * const CNWSMessage__SendServerToPlayerLoadBar_UpdateStallEvent;
// public int CNWSMessage::SendServerToPlayerLogin_CharacterQueryCNWSPlayer*, unsigned char&, int*, unsigned char*, unsigned long int&
extern void * const CNWSMessage__SendServerToPlayerLogin_CharacterQuery;
// public int CNWSMessage::SendServerToPlayerLogin_Confirmunsigned long int
extern void * const CNWSMessage__SendServerToPlayerLogin_Confirm;
// public int CNWSMessage::SendServerToPlayerLogin_Failunsigned long int, unsigned long int
extern void * const CNWSMessage__SendServerToPlayerLogin_Fail;
// public int CNWSMessage::SendServerToPlayerLogin_GetWaypointunsigned long int
extern void * const CNWSMessage__SendServerToPlayerLogin_GetWaypoint;
// public int CNWSMessage::SendServerToPlayerLogin_NeedCharacterunsigned long int
extern void * const CNWSMessage__SendServerToPlayerLogin_NeedCharacter;
// public int CNWSMessage::SendServerToPlayerMapPinAddedCNWSPlayer*, Vector, CExoString, unsigned long int
extern void * const CNWSMessage__SendServerToPlayerMapPinAdded;
// public int CNWSMessage::SendServerToPlayerMapPinCreatedCNWSPlayer*, unsigned long int, Vector, CExoLocString, int
extern void * const CNWSMessage__SendServerToPlayerMapPinCreated;
// public int CNWSMessage::SendServerToPlayerMapPinEnabledCNWSPlayer*, unsigned long int, int
extern void * const CNWSMessage__SendServerToPlayerMapPinEnabled;
// protected int CNWSMessage::SendServerToPlayerMessageunsigned long int, unsigned char, unsigned char, unsigned char*, unsigned long int
extern void * const CNWSMessage__SendServerToPlayerMessage;
// public int CNWSMessage::SendServerToPlayerModule_DumpPlayerCNWSPlayer*
extern void * const CNWSMessage__SendServerToPlayerModule_DumpPlayer;
// public int CNWSMessage::SendServerToPlayerModule_EndGameunsigned long int, const CExoString&
extern void * const CNWSMessage__SendServerToPlayerModule_EndGame;
// public int CNWSMessage::SendServerToPlayerModule_EndStartNewModuleint
extern void * const CNWSMessage__SendServerToPlayerModule_EndStartNewModule;
// public int CNWSMessage::SendServerToPlayerModule_ExportReplyCNWSPlayer*
extern void * const CNWSMessage__SendServerToPlayerModule_ExportReply;
// public int CNWSMessage::SendServerToPlayerModule_Infounsigned long int
extern void * const CNWSMessage__SendServerToPlayerModule_Info;
// public int CNWSMessage::SendServerToPlayerModule_LoadingCNWSPlayer*
extern void * const CNWSMessage__SendServerToPlayerModule_Loading;
// public int CNWSMessage::SendServerToPlayerModule_SaveGameStatusunsigned char
extern void * const CNWSMessage__SendServerToPlayerModule_SaveGameStatus;
// public int CNWSMessage::SendServerToPlayerModule_SetPauseStateunsigned char, int
extern void * const CNWSMessage__SendServerToPlayerModule_SetPauseState;
// public int CNWSMessage::SendServerToPlayerModule_StartStartNewModulevoid
extern void * const CNWSMessage__SendServerToPlayerModule_StartStartNewModule;
// public int CNWSMessage::SendServerToPlayerModuleUpdate_TimeCNWSPlayer*, unsigned char, unsigned long int, unsigned long int, unsigned long int, unsigned long int, unsigned char, unsigned long int
extern void * const CNWSMessage__SendServerToPlayerModuleUpdate_Time;
// public int CNWSMessage::SendServerToPlayerOpenStoreInventoryCNWSPlayer*, unsigned long int, unsigned char
extern void * const CNWSMessage__SendServerToPlayerOpenStoreInventory;
// void CNWSMessage::SendServerToPlayerParty_Inviteunsigned long int, unsigned long int
extern void * const CNWSMessage__SendServerToPlayerParty_Invite;
// public int CNWSMessage::SendServerToPlayerParty_Listunsigned long int, int, unsigned long int*, unsigned char, unsigned long int
extern void * const CNWSMessage__SendServerToPlayerParty_List;
// public int CNWSMessage::SendServerToPlayerParty_TransferObjectControlunsigned long int, unsigned long int, unsigned long int
extern void * const CNWSMessage__SendServerToPlayerParty_TransferObjectControl;
// public int CNWSMessage::SendServerToPlayerPartyBar_PanelButtonFlashunsigned long int, unsigned char, int
extern void * const CNWSMessage__SendServerToPlayerPartyBar_PanelButtonFlash;
// public int CNWSMessage::SendServerToPlayerPlaceableUpdate_UseableCNWSPlaceable*
extern void * const CNWSMessage__SendServerToPlayerPlaceableUpdate_Useable;
// public int CNWSMessage::SendServerToPlayerPlayerList_Addunsigned long int, CNWSPlayer*
extern void * const CNWSMessage__SendServerToPlayerPlayerList_Add;
// public int CNWSMessage::SendServerToPlayerPlayerList_AllCNWSPlayer*
extern void * const CNWSMessage__SendServerToPlayerPlayerList_All;
// public int CNWSMessage::SendServerToPlayerPlayerList_Deleteunsigned long int, CNWSPlayer*
extern void * const CNWSMessage__SendServerToPlayerPlayerList_Delete;
// public int CNWSMessage::SendServerToPlayerPlayerList_ReauthorizeCDKeyunsigned long int, const CExoString&, const CExoString&
extern void * const CNWSMessage__SendServerToPlayerPlayerList_ReauthorizeCDKey;
// public int CNWSMessage::SendServerToPlayerPlayModuleCharacterListResponseunsigned long int, unsigned long int, int
extern void * const CNWSMessage__SendServerToPlayerPlayModuleCharacterListResponse;
// public int CNWSMessage::SendServerToPlayerPolymorphCNWSPlayer*, unsigned long int, int, int
extern void * const CNWSMessage__SendServerToPlayerPolymorph;
// public int CNWSMessage::SendServerToPlayerPopUpGUIPanelunsigned long int, int, int, int, int, CExoString
extern void * const CNWSMessage__SendServerToPlayerPopUpGUIPanel;
// public int CNWSMessage::SendServerToPlayerPVP_Attitude_Changeunsigned long int, unsigned long int, int
extern void * const CNWSMessage__SendServerToPlayerPVP_Attitude_Change;
// void CNWSMessage::SendServerToPlayerQuickChatunsigned long int, unsigned long int, unsigned short int
extern void * const CNWSMessage__SendServerToPlayerQuickChat;
// public int CNWSMessage::SendServerToPlayerQuickChatMessageunsigned long int, unsigned short int
extern void * const CNWSMessage__SendServerToPlayerQuickChatMessage;
// public int CNWSMessage::SendServerToPlayerSafeProjectileCNWSPlayer*, unsigned long int, unsigned long int, Vector, Vector, unsigned long int, unsigned char, unsigned long int, unsigned char, unsigned char, unsigned char
extern void * const CNWSMessage__SendServerToPlayerSafeProjectile;
// public int CNWSMessage::SendServerToPlayerSaveLoad_StatusCNWSPlayer*, unsigned char, unsigned long int
extern void * const CNWSMessage__SendServerToPlayerSaveLoad_Status;
// public int CNWSMessage::SendServerToPlayerServerStatus_Statusunsigned long int
extern void * const CNWSMessage__SendServerToPlayerServerStatus_Status;
// public int CNWSMessage::SendServerToPlayerSetCustomTokenunsigned long int, int, const CExoString&
extern void * const CNWSMessage__SendServerToPlayerSetCustomToken;
// public int CNWSMessage::SendServerToPlayerSetCustomTokenListunsigned long int
extern void * const CNWSMessage__SendServerToPlayerSetCustomTokenList;
// public int CNWSMessage::SendServerToPlayerShutDownServerunsigned long int, unsigned long int
extern void * const CNWSMessage__SendServerToPlayerShutDownServer;
// public int CNWSMessage::SendServerToPlayerSoundObject_ChangePositionCNWSPlayer*, unsigned long int, Vector
extern void * const CNWSMessage__SendServerToPlayerSoundObject_ChangePosition;
// public int CNWSMessage::SendServerToPlayerSoundObject_ChangeVolumeCNWSPlayer*, unsigned long int, int
extern void * const CNWSMessage__SendServerToPlayerSoundObject_ChangeVolume;
// public int CNWSMessage::SendServerToPlayerSoundObject_PlayCNWSPlayer*, unsigned long int
extern void * const CNWSMessage__SendServerToPlayerSoundObject_Play;
// public int CNWSMessage::SendServerToPlayerSoundObject_StopCNWSPlayer*, unsigned long int
extern void * const CNWSMessage__SendServerToPlayerSoundObject_Stop;
// public int CNWSMessage::SendServerToPlayerStoreConfirmTransactionCNWSPlayer*, int, unsigned long int, int
extern void * const CNWSMessage__SendServerToPlayerStoreConfirmTransaction;
// public int CNWSMessage::SendServerToPlayerStringMessageunsigned long int, unsigned char, CExoString
extern void * const CNWSMessage__SendServerToPlayerStringMessage;
// public int CNWSMessage::SendServerToPlayerUpdateActiveItemPropertiesCNWSPlayer*, CNWSItem*
extern void * const CNWSMessage__SendServerToPlayerUpdateActiveItemProperties;
// public int CNWSMessage::SendServerToPlayerUpdateActiveItemPropertiesUsesCNWSPlayer*, unsigned long int, unsigned char, unsigned char, unsigned char*
extern void * const CNWSMessage__SendServerToPlayerUpdateActiveItemPropertiesUses;
// public int CNWSMessage::SendServerToPlayerUpdateBlackoutEffectCNWSPlayer*, int
extern void * const CNWSMessage__SendServerToPlayerUpdateBlackoutEffect;
// public int CNWSMessage::SendServerToPlayerUpdateCharResponseCNWSPlayer*, unsigned char, CResRef
extern void * const CNWSMessage__SendServerToPlayerUpdateCharResponse;
// public int CNWSMessage::SendServerToPlayerUpdateFogAmountunsigned char, unsigned char, unsigned long int
extern void * const CNWSMessage__SendServerToPlayerUpdateFogAmount;
// public int CNWSMessage::SendServerToPlayerUpdateFogColorunsigned long int, unsigned long int, unsigned long int
extern void * const CNWSMessage__SendServerToPlayerUpdateFogColor;
// public int CNWSMessage::SendServerToPlayerUpdateItemNameCNWSPlayer*, CNWSItem*
extern void * const CNWSMessage__SendServerToPlayerUpdateItemName;
// public int CNWSMessage::SendServerToPlayerUpdateSkyBoxint, unsigned long int
extern void * const CNWSMessage__SendServerToPlayerUpdateSkyBox;
// public int CNWSMessage::SendServerToPlayerVoiceChat_PlayCNWSPlayer*, unsigned long int, unsigned char
extern void * const CNWSMessage__SendServerToPlayerVoiceChat_Play;
// public int CNWSMessage::SendServerToPlayerWhirlwindAttackCNWSPlayer*, CNWSCreature*
extern void * const CNWSMessage__SendServerToPlayerWhirlwindAttack;
// public int CNWSMessage::SendServerToPlayerWhirlwindAttackDamageCNWSPlayer*, CNWSCreature*
extern void * const CNWSMessage__SendServerToPlayerWhirlwindAttackDamage;
// public void CNWSMessage::SendServerToServerAdminBannedListunsigned long int
extern void * const CNWSMessage__SendServerToServerAdminBannedList;
// public int CNWSMessage::SendServerToServerAdminMessageunsigned long int, CExoString
extern void * const CNWSMessage__SendServerToServerAdminMessage;
// public void CNWSMessage::SendServerToServerAdminModuleListunsigned long int
extern void * const CNWSMessage__SendServerToServerAdminModuleList;
// public void CNWSMessage::SendServerToServerAdminPlayerListunsigned long int
extern void * const CNWSMessage__SendServerToServerAdminPlayerList;
// public void CNWSMessage::SendServerToServerAdminPortalListunsigned long int
extern void * const CNWSMessage__SendServerToServerAdminPortalList;
// public void CNWSMessage::SendServerToServerAdminSaveGameListunsigned long int
extern void * const CNWSMessage__SendServerToServerAdminSaveGameList;
// public void CNWSMessage::SendServerToServerAdminSaveStatusunsigned long int, unsigned char
extern void * const CNWSMessage__SendServerToServerAdminSaveStatus;
// public void CNWSMessage::SendServerToServerAdminServerSettingsunsigned long int
extern void * const CNWSMessage__SendServerToServerAdminServerSettings;
// public void CNWSMessage::SendServerToServerAdminServerStatusunsigned long int
extern void * const CNWSMessage__SendServerToServerAdminServerStatus;
// public CNWSPlayerLUOSortedObjectList* CNWSMessage::SortObjectsForGameObjectUpdateCNWSPlayer*, CNWSObject*, CGameObjectArray*, int*
extern void * const CNWSMessage__SortObjectsForGameObjectUpdate;
// public void CNWSMessage::StoreValuesInLastPlayerUpdateObjectCNWSPlayer*, CNWSPlayerLastUpdateObject*, CLastUpdateObject*, unsigned short int
extern void * const CNWSMessage__StoreValuesInLastPlayerUpdateObject;
// void CNWSMessage::StoreValuesInLastUpdateObjectCNWSPlayer*, CLastUpdateObject*, CNWSObject*, unsigned long int, unsigned long int
extern void * const CNWSMessage__StoreValuesInLastUpdateObject;
// public void CNWSMessage::StoreValuesInLastUpdatePartyObjectCNWSCreature*, CLastUpdatePartyObject*, CNWSCreature*, unsigned long int
extern void * const CNWSMessage__StoreValuesInLastUpdatePartyObject;
// public void CNWSMessage::TestObjectUpdateDifferencesCNWSPlayer*, CNWSObject*, CLastUpdateObject**, unsigned long int*, unsigned long int*
extern void * const CNWSMessage__TestObjectUpdateDifferences;
// public int CNWSMessage::TestObjectVisibleCNWSObject*, CNWSObject*
extern void * const CNWSMessage__TestObjectVisible;
// public void CNWSMessage::TestPartyObjectUpdateDifferencesCNWSPlayer*, CNWSCreature*, CLastUpdatePartyObject**, unsigned long int*
extern void * const CNWSMessage__TestPartyObjectUpdateDifferences;
// public void CNWSMessage::TestPlayerUpdateDifferencesCNWSPlayer*, CNWSPlayerLastUpdateObject*, CLastUpdateObject*, unsigned short int&
extern void * const CNWSMessage__TestPlayerUpdateDifferences;
// public void CNWSMessage::UpdateLastUpdate_GuiEffectIconsCNWSCreature*, CExoArrayListTemplatedCEffectIconObjectPtr*, int
extern void * const CNWSMessage__UpdateLastUpdate_GuiEffectIcons;
// protected void CNWSMessage::UpdateLastUpdateActionQueueCNWSCreature*, CNWSPlayerLastUpdateObject*
extern void * const CNWSMessage__UpdateLastUpdateActionQueue;
// protected void CNWSMessage::UpdateLastUpdateAutoMapCNWSCreature*, CNWSPlayerLastUpdateObject*
extern void * const CNWSMessage__UpdateLastUpdateAutoMap;
// protected void CNWSMessage::UpdateLastUpdateInventoryCNWSPlayer*, unsigned long int, CNWSPlayerInventoryGUI*
extern void * const CNWSMessage__UpdateLastUpdateInventory;
// protected void CNWSMessage::UpdateLastUpdateObjectCNWSPlayer*, CNWSObject*, CLastUpdateObject*, unsigned long int
extern void * const CNWSMessage__UpdateLastUpdateObject;
// protected void CNWSMessage::UpdateLastUpdateObjectAppearanceCNWSObject*, CLastUpdateObject*, unsigned long int
extern void * const CNWSMessage__UpdateLastUpdateObjectAppearance;
// protected void CNWSMessage::UpdateLastUpdateVisibilityListCNWSCreature*, CNWSPlayerLastUpdateObject*
extern void * const CNWSMessage__UpdateLastUpdateVisibilityList;
// public void CNWSMessage::WriteCExoLocStringServerCExoLocString&, unsigned char
extern void * const CNWSMessage__WriteCExoLocStringServer;
// public void CNWSMessage::WriteGameObjUpdate_CharacterSheetCNWSPlayer*, unsigned long int
extern void * const CNWSMessage__WriteGameObjUpdate_CharacterSheet;
// public int CNWSMessage::WriteGameObjUpdate_DungeonMasterAIStateCNWSPlayer*
extern void * const CNWSMessage__WriteGameObjUpdate_DungeonMasterAIState;
// public void CNWSMessage::WriteGameObjUpdate_MajorGUIPanelsCNWSPlayer*
extern void * const CNWSMessage__WriteGameObjUpdate_MajorGUIPanels;
// public void CNWSMessage::WriteGameObjUpdate_MajorGUIPanels_HenchmanInventoryDataCNWSPlayer*
extern void * const CNWSMessage__WriteGameObjUpdate_MajorGUIPanels_HenchmanInventoryData;
// public void CNWSMessage::WriteGameObjUpdate_MajorGUIPanels_InventoryCNWSPlayer*, CNWSPlayerInventoryGUI*
extern void * const CNWSMessage__WriteGameObjUpdate_MajorGUIPanels_Inventory;
// public void CNWSMessage::WriteGameObjUpdate_MinorGUIPanelsCNWSPlayer*
extern void * const CNWSMessage__WriteGameObjUpdate_MinorGUIPanels;
// public int CNWSMessage::WriteGameObjUpdate_PartyAIStateCNWSPlayer*
extern void * const CNWSMessage__WriteGameObjUpdate_PartyAIState;
// public void CNWSMessage::WriteGameObjUpdate_PlayerUpdateCNWSPlayer*, CNWSPlayerLastUpdateObject*, CLastUpdateObject*, unsigned short int
extern void * const CNWSMessage__WriteGameObjUpdate_PlayerUpdate;
// protected void CNWSMessage::WriteGameObjUpdate_UpdateAppearanceCNWSObject*, CLastUpdateObject*, unsigned long int
extern void * const CNWSMessage__WriteGameObjUpdate_UpdateAppearance;
// public void CNWSMessage::WriteGameObjUpdate_UpdateObjectCNWSPlayer*, CNWSObject*, CLastUpdateObject*, unsigned long int, unsigned long int
extern void * const CNWSMessage__WriteGameObjUpdate_UpdateObject;
// protected void CNWSMessage::WriteGameObjUpdate_UpdateQuickbarItemUseCountCNWSObject*, CLastUpdateObject*
extern void * const CNWSMessage__WriteGameObjUpdate_UpdateQuickbarItemUseCount;
// void CNWSMessage::WriteGameObjUpdate_WorkRemainingCNWSObject*, CNWSArea*, int, int
extern void * const CNWSMessage__WriteGameObjUpdate_WorkRemaining;
// void CNWSMessage::WriteGameObjUpdate_WriteInventorySlotAddCNWSCreature*, CNWSItem*, unsigned long int
extern void * const CNWSMessage__WriteGameObjUpdate_WriteInventorySlotAdd;
// void CNWSMessage::WriteGameObjUpdate_WriteInventorySlotDeleteCNWSCreature*, unsigned long int
extern void * const CNWSMessage__WriteGameObjUpdate_WriteInventorySlotDelete;
// void CNWSMessage::WriteGameObjUpdate_WriteInventorySlotUpdateunsigned long int, unsigned long int
extern void * const CNWSMessage__WriteGameObjUpdate_WriteInventorySlotUpdate;
// public void CNWSMessage::WriteGuiEffectIconsUpdateCNWSCreature*, CExoArrayListTemplatedCEffectIconObjectPtr*, int
extern void * const CNWSMessage__WriteGuiEffectIconsUpdate;
// public void CNWSMessage::WriteOBJECTIDServerunsigned long int
extern void * const CNWSMessage__WriteOBJECTIDServer;
// protected void CNWSMessage::WriteRepositoryUpdateCNWSPlayer*, CNWSObject*, CItemRepository*, CNWSPlayerLUOInventory*, unsigned char, char, unsigned char
extern void * const CNWSMessage__WriteRepositoryUpdate;
// protected void CNWSMessage::WriteStoreInventoryUpdateCNWSPlayer*, CNWSStore*
extern void * const CNWSMessage__WriteStoreInventoryUpdate;

// public CNWSModule::CNWSModuleCExoString, int, int
extern void * const CNWSModule__CNWSModuleCtor;
// public CNWSModule::~CNWSModulevoid
extern void * const CNWSModule__CNWSModuleDtor;
// public void CNWSModule::AddObjectToLimbounsigned long int
extern void * const CNWSModule__AddObjectToLimbo;
// public int CNWSModule::AddObjectToLookupTableCExoString, unsigned long int
extern void * const CNWSModule__AddObjectToLookupTable;
// public void CNWSModule::AddToTURDListCNWSPlayerTURD*
extern void * const CNWSModule__AddToTURDList;
// void CNWSModule::AddTURDsToWorldvoid
extern void * const CNWSModule__AddTURDsToWorld;
// public void CNWSModule::AddWorldJournalEntryint, CExoString, CExoString, unsigned long int, unsigned long int
extern void * const CNWSModule__AddWorldJournalEntry;
// void CNWSModule::AddWorldJournalEntryStrrefunsigned long int, unsigned long int, unsigned long int, unsigned long int
extern void * const CNWSModule__AddWorldJournalEntryStrref;
// public int CNWSModule::AIUpdatevoid
extern void * const CNWSModule__AIUpdate;
// public CNWSModule* CNWSModule::AsNWSModulevoid
extern void * const CNWSModule__AsNWSModule;
// public void CNWSModule::CleanUpLimboListvoid
extern void * const CNWSModule__CleanUpLimboList;
// void CNWSModule::ClearAreaVisitedFlagsvoid
extern void * const CNWSModule__ClearAreaVisitedFlags;
// public int CNWSModule::ComputeInterAreaPathCPathfindInformation*
extern void * const CNWSModule__ComputeInterAreaPath;
// void CNWSModule::DeleteWorldJournalAllEntriesvoid
extern void * const CNWSModule__DeleteWorldJournalAllEntries;
// public void CNWSModule::DeleteWorldJournalEntryint
extern void * const CNWSModule__DeleteWorldJournalEntry;
// public void CNWSModule::DeleteWorldJournalEntryStrrefunsigned long int
extern void * const CNWSModule__DeleteWorldJournalEntryStrref;
// public void CNWSModule::DoUpdatevoid
extern void * const CNWSModule__DoUpdate;
// public void CNWSModule::EventHandlerunsigned long int, unsigned long int, void*, unsigned long int, unsigned long int
extern void * const CNWSModule__EventHandler;
// public unsigned long int CNWSModule::FindObjectByTagOrdinalconst CExoString&, unsigned long int
extern void * const CNWSModule__FindObjectByTagOrdinal;
// public unsigned long int CNWSModule::FindObjectByTagTypeOrdinalconst CExoString&, int, unsigned long int
extern void * const CNWSModule__FindObjectByTagTypeOrdinal;
// void CNWSModule::FindTagPositionInTablechar*
extern void * const CNWSModule__FindTagPositionInTable;
// void CNWSModule::GenerateInterAreaDFSSuccessorsint, CPathfindInformation*, unsigned long int**
extern void * const CNWSModule__GenerateInterAreaDFSSuccessors;
// public CNWSArea* CNWSModule::GetAreaCResRef
extern void * const CNWSModule__GetArea__0;
// public CNWSArea* CNWSModule::GetAreaunsigned long int
extern void * const CNWSModule__GetArea__1;
// void CNWSModule::GetAreaByNameCExoString&
extern void * const CNWSModule__GetAreaByName;
// public CNWSArea* CNWSModule::GetAreaByTagCExoString&
extern void * const CNWSModule__GetAreaByTag;
// void CNWSModule::GetAreaListvoid
extern void * const CNWSModule__GetAreaList;
// void CNWSModule::GetCustomScriptEventIdvoid
extern void * const CNWSModule__GetCustomScriptEventId;
// void CNWSModule::GetDawnHourvoid
extern void * const CNWSModule__GetDawnHour;
// void CNWSModule::GetDuskHourvoid
extern void * const CNWSModule__GetDuskHour;
// void CNWSModule::GetEnableScriptDebuggervoid
extern void * const CNWSModule__GetEnableScriptDebugger;
// private unsigned char* CNWSModule::GetFullCipherCExoString
extern void * const CNWSModule__GetFullCipher;
// void CNWSModule::GetInvisibleCreaturesListvoid
extern void * const CNWSModule__GetInvisibleCreaturesList;
// void CNWSModule::GetIsDigitalDistributionDemovoid
extern void * const CNWSModule__GetIsDigitalDistributionDemo;
// void CNWSModule::GetIsNWMFilevoid
extern void * const CNWSModule__GetIsNWMFile;
// void CNWSModule::GetIsSaveGamevoid
extern void * const CNWSModule__GetIsSaveGame;
// void CNWSModule::GetLastEntervoid
extern void * const CNWSModule__GetLastEnter;
// void CNWSModule::GetLastExitvoid
extern void * const CNWSModule__GetLastExit;
// void CNWSModule::GetLastItemAcquiredvoid
extern void * const CNWSModule__GetLastItemAcquired;
// void CNWSModule::GetLastItemAcquiredByvoid
extern void * const CNWSModule__GetLastItemAcquiredBy;
// void CNWSModule::GetLastItemAcquiredFromvoid
extern void * const CNWSModule__GetLastItemAcquiredFrom;
// void CNWSModule::GetLastItemAcquiredStackSizevoid
extern void * const CNWSModule__GetLastItemAcquiredStackSize;
// void CNWSModule::GetLastItemActivatedvoid
extern void * const CNWSModule__GetLastItemActivated;
// void CNWSModule::GetLastItemActivatedAreavoid
extern void * const CNWSModule__GetLastItemActivatedArea;
// void CNWSModule::GetLastItemActivatedPositionvoid
extern void * const CNWSModule__GetLastItemActivatedPosition;
// void CNWSModule::GetLastItemActivatedTargetvoid
extern void * const CNWSModule__GetLastItemActivatedTarget;
// void CNWSModule::GetLastItemActivatorvoid
extern void * const CNWSModule__GetLastItemActivator;
// void CNWSModule::GetLastItemLoservoid
extern void * const CNWSModule__GetLastItemLoser;
// void CNWSModule::GetLastItemLostvoid
extern void * const CNWSModule__GetLastItemLost;
// void CNWSModule::GetLastItemLostStackSizevoid
extern void * const CNWSModule__GetLastItemLostStackSize;
// void CNWSModule::GetLastPCCancelCutscenevoid
extern void * const CNWSModule__GetLastPCCancelCutscene;
// void CNWSModule::GetLastPCLevellingUpvoid
extern void * const CNWSModule__GetLastPCLevellingUp;
// public CExoString CNWSModule::GetLastPlayerChatMessagevoid
extern void * const CNWSModule__GetLastPlayerChatMessage;
// void CNWSModule::GetLastPlayerChatMessageTypevoid
extern void * const CNWSModule__GetLastPlayerChatMessageType;
// void CNWSModule::GetLastPlayerChatObjectvoid
extern void * const CNWSModule__GetLastPlayerChatObject;
// void CNWSModule::GetLastPlayerDiedvoid
extern void * const CNWSModule__GetLastPlayerDied;
// void CNWSModule::GetLastPlayerDyingvoid
extern void * const CNWSModule__GetLastPlayerDying;
// void CNWSModule::GetLastRespawnButtonPresservoid
extern void * const CNWSModule__GetLastRespawnButtonPresser;
// void CNWSModule::GetLastRestedvoid
extern void * const CNWSModule__GetLastRested;
// void CNWSModule::GetLastRestEventTypevoid
extern void * const CNWSModule__GetLastRestEventType;
// void CNWSModule::GetLimboArrayvoid
extern void * const CNWSModule__GetLimboArray;
// void CNWSModule::GetMaxHenchmenvoid
extern void * const CNWSModule__GetMaxHenchmen;
// void CNWSModule::GetMinutesPerHourvoid
extern void * const CNWSModule__GetMinutesPerHour;
// public CExoLocString CNWSModule::GetModuleDescriptionvoid
extern void * const CNWSModule__GetModuleDescription;
// void CNWSModule::GetModuleEntryInfovoid
extern void * const CNWSModule__GetModuleEntryInfo;
// public CExoLocString CNWSModule::GetModuleNamevoid
extern void * const CNWSModule__GetModuleName;
// public CExoString CNWSModule::GetNWMResNamevoid
extern void * const CNWSModule__GetNWMResName;
// void CNWSModule::GetPCItemLastEquippedvoid
extern void * const CNWSModule__GetPCItemLastEquipped;
// void CNWSModule::GetPCItemLastEquippedByvoid
extern void * const CNWSModule__GetPCItemLastEquippedBy;
// void CNWSModule::GetPCItemLastUnequippedvoid
extern void * const CNWSModule__GetPCItemLastUnequipped;
// void CNWSModule::GetPCItemLastUnequippedByvoid
extern void * const CNWSModule__GetPCItemLastUnequippedBy;
// public unsigned long int CNWSModule::GetPlayerIndexInPlayerListCNWSPlayer*
extern void * const CNWSModule__GetPlayerIndexInPlayerList;
// void CNWSModule::GetPlayerPathfindRulevoid
extern void * const CNWSModule__GetPlayerPathfindRule;
// public CNWSPlayerTURD* CNWSModule::GetPlayerTURDFromListCNWSPlayer*
extern void * const CNWSModule__GetPlayerTURDFromList;
// public unsigned long int CNWSModule::GetPrimaryPlayerIndexvoid
extern void * const CNWSModule__GetPrimaryPlayerIndex;
// void CNWSModule::GetScriptNameint
extern void * const CNWSModule__GetScriptName;
// void CNWSModule::GetScriptVarTablevoid
extern void * const CNWSModule__GetScriptVarTable;
// void CNWSModule::GetStartMovievoid
extern void * const CNWSModule__GetStartMovie;
// public CExoString CNWSModule::GetTagvoid
extern void * const CNWSModule__GetTag;
// public void CNWSModule::GetTimeunsigned long int*, unsigned long int*, unsigned long int*, unsigned long int*, unsigned char*, unsigned long int*
extern void * const CNWSModule__GetTime;
// void CNWSModule::GetTimeOfDayStatevoid
extern void * const CNWSModule__GetTimeOfDayState;
// public unsigned long int CNWSModule::GetWaypointconst CExoString&
extern void * const CNWSModule__GetWaypoint;
// public unsigned long int CNWSModule::GetWorldJournalIndexUniquevoid
extern void * const CNWSModule__GetWorldJournalIndexUnique;
// void CNWSModule::GetXPScalevoid
extern void * const CNWSModule__GetXPScale;
// public int CNWSModule::InterAreaDFSint, int, CPathfindInformation*
extern void * const CNWSModule__InterAreaDFS;
// public int CNWSModule::IsObjectInLimbounsigned long int
extern void * const CNWSModule__IsObjectInLimbo;
// public unsigned char CNWSModule::IsOfficialCampaignvoid
extern void * const CNWSModule__IsOfficialCampaign;
// private int CNWSModule::LoadLimboCreaturesCResGFF*, CResStruct*, int
extern void * const CNWSModule__LoadLimboCreatures;
// public unsigned long int CNWSModule::LoadModuleFinishvoid
extern void * const CNWSModule__LoadModuleFinish;
// public unsigned long int CNWSModule::LoadModuleInProgressint, int
extern void * const CNWSModule__LoadModuleInProgress;
// public unsigned long int CNWSModule::LoadModuleStartCExoString, int
extern void * const CNWSModule__LoadModuleStart;
// public void CNWSModule::LoadTURDListCResGFF*, CResStruct*
extern void * const CNWSModule__LoadTURDList;
// public void CNWSModule::PackModuleIntoMessageunsigned long int
extern void * const CNWSModule__PackModuleIntoMessage;
// public void CNWSModule::PackPlayerCharacterListIntoMessageCNWSPlayer*, CExoArrayListTemplatedNWPlayerCharacterList_stPtr&
extern void * const CNWSModule__PackPlayerCharacterListIntoMessage;
// public unsigned long int CNWSModule::PlotInterAreaPathCPathfindInformation*, unsigned long int
extern void * const CNWSModule__PlotInterAreaPath;
// public unsigned long int CNWSModule::PlotPathCPathfindInformation*, unsigned long int
extern void * const CNWSModule__PlotPath;
// public unsigned long int CNWSModule::PlotPathInAreaCPathfindInformation*, unsigned long int
extern void * const CNWSModule__PlotPathInArea;
// private void CNWSModule::PostProcessvoid
extern void * const CNWSModule__PostProcess;
// public void CNWSModule::RemoveFromTURDListCNWSPlayer*
extern void * const CNWSModule__RemoveFromTURDList;
// public void CNWSModule::RemoveObjectFromLimbounsigned long int
extern void * const CNWSModule__RemoveObjectFromLimbo;
// public int CNWSModule::RemoveObjectFromLookupTableCExoString, unsigned long int
extern void * const CNWSModule__RemoveObjectFromLookupTable;
// private void CNWSModule::SaveLimboCreaturesCResGFF*, CResStruct*
extern void * const CNWSModule__SaveLimboCreatures;
// private int CNWSModule::SaveModuleFACCERFFile*
extern void * const CNWSModule__SaveModuleFAC;
// public int CNWSModule::SaveModuleFinishCExoString&, CExoString&
extern void * const CNWSModule__SaveModuleFinish;
// private int CNWSModule::SaveModuleIFOFinishCResGFF*, CResStruct*, CERFFile*, CExoString&, CExoArrayListTemplatedunsignedlong&
extern void * const CNWSModule__SaveModuleIFOFinish;
// private int CNWSModule::SaveModuleIFOStartCResGFF*, CResStruct*
extern void * const CNWSModule__SaveModuleIFOStart;
// public int CNWSModule::SaveModuleInProgressvoid
extern void * const CNWSModule__SaveModuleInProgress;
// public void CNWSModule::SaveModuleStartCExoString&, CExoString&
extern void * const CNWSModule__SaveModuleStart;
// private int CNWSModule::SavePlayersCResGFF*, CResStruct*, CExoString&, CExoArrayListTemplatedunsignedlong&
extern void * const CNWSModule__SavePlayers;
// private int CNWSModule::SaveStaticCERFFile*, CExoString, unsigned short int, int
extern void * const CNWSModule__SaveStatic;
// void CNWSModule::SaveTURDListCResGFF*, CResStruct*
extern void * const CNWSModule__SaveTURDList;
// void CNWSModule::SetCustomScriptEventIdint
extern void * const CNWSModule__SetCustomScriptEventId;
// void CNWSModule::SetEnableScriptDebuggerunsigned char
extern void * const CNWSModule__SetEnableScriptDebugger;
// public void CNWSModule::SetIntraAreaGoalCPathfindInformation*
extern void * const CNWSModule__SetIntraAreaGoal;
// void CNWSModule::SetIsNWMFileint
extern void * const CNWSModule__SetIsNWMFile;
// void CNWSModule::SetIsSaveGameint
extern void * const CNWSModule__SetIsSaveGame;
// void CNWSModule::SetLastEnterunsigned long int
extern void * const CNWSModule__SetLastEnter;
// void CNWSModule::SetLastExitunsigned long int
extern void * const CNWSModule__SetLastExit;
// void CNWSModule::SetLastItemAcquiredunsigned long int
extern void * const CNWSModule__SetLastItemAcquired;
// void CNWSModule::SetLastItemAcquiredByunsigned long int
extern void * const CNWSModule__SetLastItemAcquiredBy;
// void CNWSModule::SetLastItemAcquiredFromunsigned long int
extern void * const CNWSModule__SetLastItemAcquiredFrom;
// void CNWSModule::SetLastItemAcquiredStackSizeint
extern void * const CNWSModule__SetLastItemAcquiredStackSize;
// void CNWSModule::SetLastItemActivatedunsigned long int
extern void * const CNWSModule__SetLastItemActivated;
// void CNWSModule::SetLastItemActivatedAreaunsigned long int
extern void * const CNWSModule__SetLastItemActivatedArea;
// void CNWSModule::SetLastItemActivatedPositionconst Vector&
extern void * const CNWSModule__SetLastItemActivatedPosition;
// void CNWSModule::SetLastItemActivatedTargetunsigned long int
extern void * const CNWSModule__SetLastItemActivatedTarget;
// void CNWSModule::SetLastItemActivatorunsigned long int
extern void * const CNWSModule__SetLastItemActivator;
// void CNWSModule::SetLastItemLoserunsigned long int
extern void * const CNWSModule__SetLastItemLoser;
// void CNWSModule::SetLastItemLostunsigned long int
extern void * const CNWSModule__SetLastItemLost;
// void CNWSModule::SetLastItemLostStackSizeint
extern void * const CNWSModule__SetLastItemLostStackSize;
// void CNWSModule::SetLastPCCancelCutsceneunsigned long int
extern void * const CNWSModule__SetLastPCCancelCutscene;
// void CNWSModule::SetLastPCLevellingUpunsigned long int
extern void * const CNWSModule__SetLastPCLevellingUp;
// void CNWSModule::SetLastPlayerChatMessageconst CExoString&
extern void * const CNWSModule__SetLastPlayerChatMessage;
// void CNWSModule::SetLastPlayerChatMessageTypeunsigned char
extern void * const CNWSModule__SetLastPlayerChatMessageType;
// void CNWSModule::SetLastPlayerChatObjectunsigned long int
extern void * const CNWSModule__SetLastPlayerChatObject;
// void CNWSModule::SetLastPlayerDiedunsigned long int
extern void * const CNWSModule__SetLastPlayerDied;
// void CNWSModule::SetLastPlayerDyingunsigned long int
extern void * const CNWSModule__SetLastPlayerDying;
// void CNWSModule::SetLastRespawnButtonPresserunsigned long int
extern void * const CNWSModule__SetLastRespawnButtonPresser;
// void CNWSModule::SetLastRestedunsigned long int
extern void * const CNWSModule__SetLastRested;
// void CNWSModule::SetLastRestEventTypeunsigned char
extern void * const CNWSModule__SetLastRestEventType;
// void CNWSModule::SetMaxHenchmenint
extern void * const CNWSModule__SetMaxHenchmen;
// void CNWSModule::SetNWMResNameCExoString&
extern void * const CNWSModule__SetNWMResName;
// void CNWSModule::SetPCItemLastEquippedunsigned long int
extern void * const CNWSModule__SetPCItemLastEquipped;
// void CNWSModule::SetPCItemLastEquippedByunsigned long int
extern void * const CNWSModule__SetPCItemLastEquippedBy;
// void CNWSModule::SetPCItemLastUnequippedunsigned long int
extern void * const CNWSModule__SetPCItemLastUnequipped;
// void CNWSModule::SetPCItemLastUnequippedByunsigned long int
extern void * const CNWSModule__SetPCItemLastUnequippedBy;
// void CNWSModule::SetPlayerPathfindRuleunsigned char
extern void * const CNWSModule__SetPlayerPathfindRule;
// public void CNWSModule::SetScriptNameint, CExoString
extern void * const CNWSModule__SetScriptName;
// void CNWSModule::SetXPScaleunsigned char
extern void * const CNWSModule__SetXPScale;
// private void CNWSModule::TimeStopSanityCheckvoid
extern void * const CNWSModule__TimeStopSanityCheck;
// void CNWSModule::UnloadModulevoid
extern void * const CNWSModule__UnloadModule;
// public void CNWSModule::UpdateTimeunsigned long int, unsigned long int, unsigned long int
extern void * const CNWSModule__UpdateTime;

// public CNWSObject::CNWSObjectunsigned char, unsigned long int, int, int
extern void * const CNWSObject__CNWSObjectCtor;
// public CNWSObject::~CNWSObjectvoid
extern void * const CNWSObject__CNWSObjectDtor;
// public void CNWSObject::AddActionunsigned long int, unsigned short int, unsigned long int, void*, unsigned long int, void*, unsigned long int, void*, unsigned long int, void*, unsigned long int, void*, unsigned long int, void*, unsigned long int, void*, unsigned long int, void*, unsigned long int, void*, unsigned long int, void*, unsigned long int, void*, unsigned long int, void*
extern void * const CNWSObject__AddAction;
// public void CNWSObject::AddActionAfterFrontunsigned long int, unsigned short int, unsigned long int, void*, unsigned long int, void*, unsigned long int, void*, unsigned long int, void*, unsigned long int, void*, unsigned long int, void*, unsigned long int, void*, unsigned long int, void*, unsigned long int, void*, unsigned long int, void*, unsigned long int, void*, unsigned long int, void*
extern void * const CNWSObject__AddActionAfterFront;
// protected void CNWSObject::AddActionNodeParameterCNWSObjectActionNode*, unsigned long int, unsigned long int, void*
extern void * const CNWSObject__AddActionNodeParameter;
// public void CNWSObject::AddActionToFrontunsigned long int, unsigned short int, unsigned long int, void*, unsigned long int, void*, unsigned long int, void*, unsigned long int, void*, unsigned long int, void*, unsigned long int, void*, unsigned long int, void*, unsigned long int, void*, unsigned long int, void*, unsigned long int, void*, unsigned long int, void*, unsigned long int, void*
extern void * const CNWSObject__AddActionToFront;
// public int CNWSObject::AddCloseDoorActionunsigned long int, int
extern void * const CNWSObject__AddCloseDoorAction;
// public int CNWSObject::AddDoCommandActionvoid*
extern void * const CNWSObject__AddDoCommandAction;
// void CNWSObject::AddEffectTargetunsigned long int
extern void * const CNWSObject__AddEffectTarget;
// public int CNWSObject::AddGiveItemActionsunsigned long int, unsigned long int, int
extern void * const CNWSObject__AddGiveItemActions;
// public int CNWSObject::AddLockObjectActionunsigned long int
extern void * const CNWSObject__AddLockObjectAction;
// public void CNWSObject::AddLoopingVisualEffectunsigned short int, unsigned long int, unsigned char
extern void * const CNWSObject__AddLoopingVisualEffect;
// public void CNWSObject::AddMatchedExpressionStringconst CExoString&
extern void * const CNWSObject__AddMatchedExpressionString;
// public int CNWSObject::AddOpenDoorActionunsigned long int, int
extern void * const CNWSObject__AddOpenDoorAction;
// public int CNWSObject::AddTakeItemActionsunsigned long int, unsigned long int, int
extern void * const CNWSObject__AddTakeItemActions;
// public int CNWSObject::AddUnlockObjectActionunsigned long int, unsigned long int, int
extern void * const CNWSObject__AddUnlockObjectAction;
// public int CNWSObject::AddUseObjectActionunsigned long int
extern void * const CNWSObject__AddUseObjectAction;
// protected unsigned long int CNWSObject::AIActionCloseDoorCNWSObjectActionNode*
extern void * const CNWSObject__AIActionCloseDoor;
// protected unsigned long int CNWSObject::AIActionDialogObjectCNWSObjectActionNode*
extern void * const CNWSObject__AIActionDialogObject;
// void CNWSObject::AIActionDoCommandCNWSObjectActionNode*
extern void * const CNWSObject__AIActionDoCommand;
// protected unsigned long int CNWSObject::AIActionGiveItemCNWSObjectActionNode*
extern void * const CNWSObject__AIActionGiveItem;
// protected unsigned long int CNWSObject::AIActionLockObjectCNWSObjectActionNode*
extern void * const CNWSObject__AIActionLockObject;
// protected unsigned long int CNWSObject::AIActionOpenDoorCNWSObjectActionNode*
extern void * const CNWSObject__AIActionOpenDoor;
// protected unsigned long int CNWSObject::AIActionPauseDialogCNWSObjectActionNode*
extern void * const CNWSObject__AIActionPauseDialog;
// protected unsigned long int CNWSObject::AIActionPlayAnimationCNWSObjectActionNode*
extern void * const CNWSObject__AIActionPlayAnimation;
// protected unsigned long int CNWSObject::AIActionPlaySoundCNWSObjectActionNode*
extern void * const CNWSObject__AIActionPlaySound;
// protected unsigned long int CNWSObject::AIActionResumeDialogCNWSObjectActionNode*
extern void * const CNWSObject__AIActionResumeDialog;
// void CNWSObject::AIActionSetCommandableCNWSObjectActionNode*
extern void * const CNWSObject__AIActionSetCommandable;
// protected unsigned long int CNWSObject::AIActionSpeakCNWSObjectActionNode*
extern void * const CNWSObject__AIActionSpeak;
// void CNWSObject::AIActionSpeakStrRefCNWSObjectActionNode*
extern void * const CNWSObject__AIActionSpeakStrRef;
// protected unsigned long int CNWSObject::AIActionTakeItemCNWSObjectActionNode*
extern void * const CNWSObject__AIActionTakeItem;
// protected unsigned long int CNWSObject::AIActionUnlockObjectCNWSObjectActionNode*
extern void * const CNWSObject__AIActionUnlockObject;
// protected unsigned long int CNWSObject::AIActionUseObjectCNWSObjectActionNode*
extern void * const CNWSObject__AIActionUseObject;
// void CNWSObject::AIActionWaitCNWSObjectActionNode*
extern void * const CNWSObject__AIActionWait;
// public int CNWSObject::AnimationStationaryunsigned short int
extern void * const CNWSObject__AnimationStationary;
// public void CNWSObject::ApplyEffectCGameEffect*, int, int
extern void * const CNWSObject__ApplyEffect;
// public CNWSObject* CNWSObject::AsNWSObjectvoid
extern void * const CNWSObject__AsNWSObject;
// public void CNWSObject::BroadcastCounterSpellDataCNWSpell*, CNWCCMessageData*
extern void * const CNWSObject__BroadcastCounterSpellData;
// public void CNWSObject::BroadcastDialogCExoString, float
extern void * const CNWSObject__BroadcastDialog;
// public void CNWSObject::BroadcastFloatyDataCNWCCMessageData*
extern void * const CNWSObject__BroadcastFloatyData;
// public void CNWSObject::BroadcastFloatyDataSTRREFunsigned long int
extern void * const CNWSObject__BroadcastFloatyDataSTRREF;
// public void CNWSObject::BroadcastSafeProjectileunsigned long int, unsigned long int, Vector, Vector, unsigned long int, unsigned char, unsigned long int, unsigned char, unsigned char
extern void * const CNWSObject__BroadcastSafeProjectile;
// public void CNWSObject::BroadcastSpellDataCNWSpell*, CNWCCMessageData*
extern void * const CNWSObject__BroadcastSpellData;
// public void CNWSObject::CalculateLastSpellProjectileTimeunsigned char
extern void * const CNWSObject__CalculateLastSpellProjectileTime;
// public Vector CNWSObject::CalculateSpellRangedMissTargetunsigned long int, unsigned long int
extern void * const CNWSObject__CalculateSpellRangedMissTarget;
// public int CNWSObject::ClearActionCNWSObjectActionNode*, int
extern void * const CNWSObject__ClearAction;
// public void CNWSObject::ClearAllActionsvoid
extern void * const CNWSObject__ClearAllActions;
// public void CNWSObject::ClearAllPartyInvalidActionsvoid
extern void * const CNWSObject__ClearAllPartyInvalidActions;
// public void CNWSObject::ClearMatchedExpressionStringsvoid
extern void * const CNWSObject__ClearMatchedExpressionStrings;
// public void CNWSObject::ClearSpellEffectsOnOthersvoid
extern void * const CNWSObject__ClearSpellEffectsOnOthers;
// public void CNWSObject::CopyScriptVarsCNWSScriptVarTable*
extern void * const CNWSObject__CopyScriptVars;
// public void CNWSObject::DeleteCurrentAIActionvoid
extern void * const CNWSObject__DeleteCurrentAIAction;
// public void CNWSObject::DoDamageint
extern void * const CNWSObject__DoDamage;
// public int CNWSObject::DoDamageImmunityCNWSCreature*, int, unsigned short int, int, int
extern void * const CNWSObject__DoDamageImmunity;
// public int CNWSObject::DoDamageReductionCNWSCreature*, int, unsigned char, int, int
extern void * const CNWSObject__DoDamageReduction;
// public int CNWSObject::DoDamageResistanceCNWSCreature*, int, unsigned short int, int, int, int
extern void * const CNWSObject__DoDamageResistance;
// public int CNWSObject::DoSpellImmunityCNWSObject*
extern void * const CNWSObject__DoSpellImmunity;
// public int CNWSObject::DoSpellLevelAbsorptionCNWSObject*
extern void * const CNWSObject__DoSpellLevelAbsorption;
// public int CNWSObject::GetAcceptableActionunsigned long int
extern void * const CNWSObject__GetAcceptableAction;
// public unsigned short int CNWSObject::GetActionByGroupIdunsigned short int, CNWSObjectActionNode**
extern void * const CNWSObject__GetActionByGroupId;
// void CNWSObject::GetAILevelvoid
extern void * const CNWSObject__GetAILevel;
// void CNWSObject::GetAILockvoid
extern void * const CNWSObject__GetAILock;
// void CNWSObject::GetAIPosListvoid
extern void * const CNWSObject__GetAIPosList;
// public unsigned char CNWSObject::GetAIStateReactionunsigned long int
extern void * const CNWSObject__GetAIStateReaction;
// void CNWSObject::GetAnimationvoid
extern void * const CNWSObject__GetAnimation;
// void CNWSObject::GetAnimationSpeedvoid
extern void * const CNWSObject__GetAnimationSpeed;
// void CNWSObject::GetAppliedEffectsvoid
extern void * const CNWSObject__GetAppliedEffects;
// void CNWSObject::GetApplyingPostProcessEffectsvoid
extern void * const CNWSObject__GetApplyingPostProcessEffects;
// public unsigned short int CNWSObject::GetAQActionIDByIDunsigned short int, int
extern void * const CNWSObject__GetAQActionIDByID;
// public CNWSArea* CNWSObject::GetAreavoid
extern void * const CNWSObject__GetArea;
// void CNWSObject::GetAreaIdvoid
extern void * const CNWSObject__GetAreaId;
// void CNWSObject::GetBaseHitPointsvoid
extern void * const CNWSObject__GetBaseHitPoints;
// void CNWSObject::GetConversationPlayHellovoid
extern void * const CNWSObject__GetConversationPlayHello;
// public short int CNWSObject::GetCurrentHitPointsint
extern void * const CNWSObject__GetCurrentHitPoints;
// void CNWSObject::GetCustomScriptEventIdvoid
extern void * const CNWSObject__GetCustomScriptEventId;
// public char CNWSObject::GetDamageImmunityunsigned char
extern void * const CNWSObject__GetDamageImmunity;
// public char CNWSObject::GetDamageImmunityByFlagsunsigned short int
extern void * const CNWSObject__GetDamageImmunityByFlags;
// public unsigned char CNWSObject::GetDamageLevelvoid
extern void * const CNWSObject__GetDamageLevel;
// public int CNWSObject::GetDeadvoid
extern void * const CNWSObject__GetDead;
// public int CNWSObject::GetDialogInterruptablevoid
extern void * const CNWSObject__GetDialogInterruptable;
// void CNWSObject::GetDialogOwnervoid
extern void * const CNWSObject__GetDialogOwner;
// void CNWSObject::GetDialogPrivatevoid
extern void * const CNWSObject__GetDialogPrivate;
// public CResRef CNWSObject::GetDialogResrefvoid
extern void * const CNWSObject__GetDialogResref;
// void CNWSObject::GetDialogValidvoid
extern void * const CNWSObject__GetDialogValid;
// void CNWSObject::GetEffectArrayIndexvoid
extern void * const CNWSObject__GetEffectArrayIndex;
// public unsigned long int CNWSObject::GetEffectSpellIdvoid
extern void * const CNWSObject__GetEffectSpellId;
// void CNWSObject::GetEffectTargetsvoid
extern void * const CNWSObject__GetEffectTargets;
// void CNWSObject::GetExecutingAIActionvoid
extern void * const CNWSObject__GetExecutingAIAction;
// void CNWSObject::GetExpressionStringsvoid
extern void * const CNWSObject__GetExpressionStrings;
// public CExoLocString& CNWSObject::GetFirstNamevoid
extern void * const CNWSObject__GetFirstName;
// public unsigned char CNWSObject::GetGendervoid
extern void * const CNWSObject__GetGender;
// public int CNWSObject::GetHasFeatEffectAppliedunsigned short int
extern void * const CNWSObject__GetHasFeatEffectApplied;
// public unsigned short int CNWSObject::GetIDByAQActionIDunsigned short int
extern void * const CNWSObject__GetIDByAQActionID;
// void CNWSObject::GetInventoryDisturbItemvoid
extern void * const CNWSObject__GetInventoryDisturbItem;
// void CNWSObject::GetInventoryDisturbTypevoid
extern void * const CNWSObject__GetInventoryDisturbType;
// void CNWSObject::GetIsDestroyablevoid
extern void * const CNWSObject__GetIsDestroyable;
// public int CNWSObject::GetIsPCDyingvoid
extern void * const CNWSObject__GetIsPCDying;
// void CNWSObject::GetIsRaiseablevoid
extern void * const CNWSObject__GetIsRaiseable;
// void CNWSObject::GetKillervoid
extern void * const CNWSObject__GetKiller;
// void CNWSObject::GetLastAttackervoid
extern void * const CNWSObject__GetLastAttacker;
// void CNWSObject::GetLastAttackModevoid
extern void * const CNWSObject__GetLastAttackMode;
// void CNWSObject::GetLastAttackTypevoid
extern void * const CNWSObject__GetLastAttackType;
// public CExoString CNWSObject::GetLastConversationResrefvoid
extern void * const CNWSObject__GetLastConversationResref;
// public int CNWSObject::GetLastDamageAmountByFlagsint
extern void * const CNWSObject__GetLastDamageAmountByFlags;
// void CNWSObject::GetLastDamagervoid
extern void * const CNWSObject__GetLastDamager;
// void CNWSObject::GetLastDisturbedvoid
extern void * const CNWSObject__GetLastDisturbed;
// void CNWSObject::GetLastGroupIDvoid
extern void * const CNWSObject__GetLastGroupID;
// void CNWSObject::GetLastHostileActorvoid
extern void * const CNWSObject__GetLastHostileActor;
// public CExoLocString& CNWSObject::GetLastNamevoid
extern void * const CNWSObject__GetLastName;
// void CNWSObject::GetLastSpeakervoid
extern void * const CNWSObject__GetLastSpeaker;
// void CNWSObject::GetLastSpellCastvoid
extern void * const CNWSObject__GetLastSpellCast;
// void CNWSObject::GetLastSpellCastAtMevoid
extern void * const CNWSObject__GetLastSpellCastAtMe;
// void CNWSObject::GetLastSpellCastAtMeCastervoid
extern void * const CNWSObject__GetLastSpellCastAtMeCaster;
// void CNWSObject::GetLastSpellCastAtMeHarmfulvoid
extern void * const CNWSObject__GetLastSpellCastAtMeHarmful;
// void CNWSObject::GetLastSpellCastDomainLevelvoid
extern void * const CNWSObject__GetLastSpellCastDomainLevel;
// void CNWSObject::GetLastSpellCastFeatvoid
extern void * const CNWSObject__GetLastSpellCastFeat;
// void CNWSObject::GetLastSpellCastMetaTypevoid
extern void * const CNWSObject__GetLastSpellCastMetaType;
// void CNWSObject::GetLastSpellCastMulticlassvoid
extern void * const CNWSObject__GetLastSpellCastMulticlass;
// void CNWSObject::GetLastSpellCastSpontaneousvoid
extern void * const CNWSObject__GetLastSpellCastSpontaneous;
// void CNWSObject::GetLastSpellIdvoid
extern void * const CNWSObject__GetLastSpellId;
// void CNWSObject::GetLastSpellLocationTargetvoid
extern void * const CNWSObject__GetLastSpellLocationTarget;
// void CNWSObject::GetLastSpellObjectTargetvoid
extern void * const CNWSObject__GetLastSpellObjectTarget;
// void CNWSObject::GetLastWeaponAttackedWithvoid
extern void * const CNWSObject__GetLastWeaponAttackedWith;
// public CNWSExpression* CNWSObject::GetListenExpressionObjint
extern void * const CNWSObject__GetListenExpressionObj;
// void CNWSObject::GetListenExpressionsvoid
extern void * const CNWSObject__GetListenExpressions;
// public unsigned long int CNWSObject::GetLockOrientationToObjectvoid
extern void * const CNWSObject__GetLockOrientationToObject;
// void CNWSObject::GetLoopingVisualEffectsvoid
extern void * const CNWSObject__GetLoopingVisualEffects;
// void CNWSObject::GetMatchedPosvoid
extern void * const CNWSObject__GetMatchedPos;
// public short int CNWSObject::GetMaxHitPointsint
extern void * const CNWSObject__GetMaxHitPoints;
// public int CNWSObject::GetMaximumDamageResistanceVsDamageFlagunsigned short int, int*
extern void * const CNWSObject__GetMaximumDamageResistanceVsDamageFlag;
// public unsigned long int CNWSObject::GetNearestObjectByNameconst CExoString&, float
extern void * const CNWSObject__GetNearestObjectByName;
// void CNWSObject::GetNewGroupIDvoid
extern void * const CNWSObject__GetNewGroupID;
// void CNWSObject::GetNodeByIdunsigned short int, unsigned short int
extern void * const CNWSObject__GetNodeById;
// public int CNWSObject::GetNumActionGroupsvoid
extern void * const CNWSObject__GetNumActionGroups;
// void CNWSObject::GetObjectToDialogvoid
extern void * const CNWSObject__GetObjectToDialog;
// void CNWSObject::GetOpenDoorAnimationPlayedvoid
extern void * const CNWSObject__GetOpenDoorAnimationPlayed;
// void CNWSObject::GetOrientationvoid
extern void * const CNWSObject__GetOrientation;
// void CNWSObject::GetPendingEffectRemovalvoid
extern void * const CNWSObject__GetPendingEffectRemoval;
// void CNWSObject::GetPlotObjectvoid
extern void * const CNWSObject__GetPlotObject;
// public CResRef CNWSObject::GetPortraitvoid
extern void * const CNWSObject__GetPortrait;
// public unsigned short int CNWSObject::GetPortraitIdvoid
extern void * const CNWSObject__GetPortraitId;
// void CNWSObject::GetPositionvoid
extern void * const CNWSObject__GetPosition;
// public CExoLinkedListNode* CNWSObject::GetPositionByGroupIndexint
extern void * const CNWSObject__GetPositionByGroupIndex;
// void CNWSObject::GetPrivateConversationvoid
extern void * const CNWSObject__GetPrivateConversation;
// void CNWSObject::GetQueuedActionsListvoid
extern void * const CNWSObject__GetQueuedActionsList;
// public int CNWSObject::GetReputationunsigned long int, int&, int
extern void * const CNWSObject__GetReputation;
// void CNWSObject::GetSavingThrowSpellIdvoid
extern void * const CNWSObject__GetSavingThrowSpellId;
// public CScriptLocation CNWSObject::GetScriptLocationvoid
extern void * const CNWSObject__GetScriptLocation;
// void CNWSObject::GetScriptVarTablevoid
extern void * const CNWSObject__GetScriptVarTable;
// void CNWSObject::GetSelectableWhenDeadvoid
extern void * const CNWSObject__GetSelectableWhenDead;
// public CExoString* CNWSObject::GetTagvoid
extern void * const CNWSObject__GetTag;
// public CExoString* CNWSObject::GetTemplatevoid
extern void * const CNWSObject__GetTemplate;
// void CNWSObject::GetTemporaryHitPointsvoid
extern void * const CNWSObject__GetTemporaryHitPoints;
// public int CNWSObject::HasSpellEffectAppliedunsigned long int
extern void * const CNWSObject__HasSpellEffectApplied;
// void CNWSObject::IsAbleToModifyActionQueuevoid
extern void * const CNWSObject__IsAbleToModifyActionQueue;
// void CNWSObject::IsDialogDelayvoid
extern void * const CNWSObject__IsDialogDelay;
// void CNWSObject::IsDialogPausedvoid
extern void * const CNWSObject__IsDialogPaused;
// void CNWSObject::IsListeningvoid
extern void * const CNWSObject__IsListening;
// void CNWSObject::IsPCInDialogvoid
extern void * const CNWSObject__IsPCInDialog;
// protected void CNWSObject::LoadActionQueueCResGFF*, CResStruct*
extern void * const CNWSObject__LoadActionQueue;
// protected void CNWSObject::LoadEffectListCResGFF*, CResStruct*
extern void * const CNWSObject__LoadEffectList;
// protected void CNWSObject::LoadListenDataCResGFF*, CResStruct*
extern void * const CNWSObject__LoadListenData;
// public void CNWSObject::LoadObjectStateCResGFF*, CResStruct*
extern void * const CNWSObject__LoadObjectState;
// protected void CNWSObject::LoadVarTableCResGFF*, CResStruct*
extern void * const CNWSObject__LoadVarTable;
// public void CNWSObject::PlaySoundSetCNWSPlayer*, unsigned char
extern void * const CNWSObject__PlaySoundSet;
// public void CNWSObject::RemoveEffectCGameEffect*
extern void * const CNWSObject__RemoveEffect;
// public void CNWSObject::RemoveEffectByCreatorunsigned long int
extern void * const CNWSObject__RemoveEffectByCreator;
// public int CNWSObject::RemoveEffectByIdunsigned long long int
extern void * const CNWSObject__RemoveEffectById;
// void CNWSObject::RemoveEffectBySpellIdunsigned long int
extern void * const CNWSObject__RemoveEffectBySpellId;
// public void CNWSObject::RemoveEffectTargetunsigned long int
extern void * const CNWSObject__RemoveEffectTarget;
// public void CNWSObject::RemoveGroupunsigned short int
extern void * const CNWSObject__RemoveGroup;
// public void CNWSObject::RemoveLoopingVisualEffectunsigned short int
extern void * const CNWSObject__RemoveLoopingVisualEffect;
// void CNWSObject::RemoveObjectFromDialogunsigned long int
extern void * const CNWSObject__RemoveObjectFromDialog;
// public void CNWSObject::RemoveSomeEffectsOfDurationTypeunsigned short int
extern void * const CNWSObject__RemoveSomeEffectsOfDurationType;
// public int CNWSObject::ReplyDialogunsigned long int, unsigned long int, int, unsigned long int
extern void * const CNWSObject__ReplyDialog;
// public void CNWSObject::ReportOverflowint, int, int, int
extern void * const CNWSObject__ReportOverflow;
// protected void CNWSObject::RunActionsunsigned long int, unsigned long int, unsigned long long int
extern void * const CNWSObject__RunActions;
// public int CNWSObject::RunDialogOneLinerconst CExoString&, unsigned long int
extern void * const CNWSObject__RunDialogOneLiner;
// protected void CNWSObject::SaveActionQueueCResGFF*, CResStruct*
extern void * const CNWSObject__SaveActionQueue;
// protected void CNWSObject::SaveEffectListCResGFF*, CResStruct*
extern void * const CNWSObject__SaveEffectList;
// protected void CNWSObject::SaveListenDataCResGFF*, CResStruct*
extern void * const CNWSObject__SaveListenData;
// public void CNWSObject::SaveObjectStateCResGFF*, CResStruct*
extern void * const CNWSObject__SaveObjectState;
// protected void CNWSObject::SaveVarTableCResGFF*, CResStruct*
extern void * const CNWSObject__SaveVarTable;
// public int CNWSObject::SendDialogEntryunsigned long int, int
extern void * const CNWSObject__SendDialogEntry;
// public int CNWSObject::SendDialogRepliesvoid
extern void * const CNWSObject__SendDialogReplies;
// void CNWSObject::SetAbleToModifyActionQueueint
extern void * const CNWSObject__SetAbleToModifyActionQueue;
// void CNWSObject::SetAILevelint
extern void * const CNWSObject__SetAILevel;
// void CNWSObject::SetAILockint
extern void * const CNWSObject__SetAILock;
// void CNWSObject::SetAIPosListCExoLinkedListNode*
extern void * const CNWSObject__SetAIPosList;
// public void CNWSObject::SetAnimationint
extern void * const CNWSObject__SetAnimation;
// void CNWSObject::SetAnimationSpeedfloat
extern void * const CNWSObject__SetAnimationSpeed;
// void CNWSObject::SetApplyingPostProcessEffectsint
extern void * const CNWSObject__SetApplyingPostProcessEffects;
// public void CNWSObject::SetAreaCNWSArea*
extern void * const CNWSObject__SetArea;
// void CNWSObject::SetAreaIdunsigned long int
extern void * const CNWSObject__SetAreaId;
// void CNWSObject::SetBaseHitPointsint
extern void * const CNWSObject__SetBaseHitPoints;
// void CNWSObject::SetConversationPlayHelloint
extern void * const CNWSObject__SetConversationPlayHello;
// void CNWSObject::SetCurrentActionTargetunsigned long int
extern void * const CNWSObject__SetCurrentActionTarget;
// void CNWSObject::SetCurrentHitPointsint
extern void * const CNWSObject__SetCurrentHitPoints;
// void CNWSObject::SetCustomScriptEventIdint
extern void * const CNWSObject__SetCustomScriptEventId;
// public void CNWSObject::SetDamageImmunityunsigned short int, int
extern void * const CNWSObject__SetDamageImmunity;
// void CNWSObject::SetDialogAnimationint
extern void * const CNWSObject__SetDialogAnimation;
// public void CNWSObject::SetDialogDelayfloat
extern void * const CNWSObject__SetDialogDelay;
// public void CNWSObject::SetDialogOwnerunsigned long int
extern void * const CNWSObject__SetDialogOwner;
// void CNWSObject::SetDialogPausedint
extern void * const CNWSObject__SetDialogPaused;
// void CNWSObject::SetEffectArrayIndexunsigned short int
extern void * const CNWSObject__SetEffectArrayIndex;
// public void CNWSObject::SetEffectSpellIdunsigned long int
extern void * const CNWSObject__SetEffectSpellId;
// void CNWSObject::SetExecutingAIActionCNWSObjectActionNode*
extern void * const CNWSObject__SetExecutingAIAction;
// public void CNWSObject::SetGroupInterruptableunsigned short int, int
extern void * const CNWSObject__SetGroupInterruptable;
// void CNWSObject::SetInventoryDisturbItemunsigned long int
extern void * const CNWSObject__SetInventoryDisturbItem;
// void CNWSObject::SetInventoryDisturbTypeint
extern void * const CNWSObject__SetInventoryDisturbType;
// void CNWSObject::SetIsDestroyableint
extern void * const CNWSObject__SetIsDestroyable;
// void CNWSObject::SetIsRaiseableint
extern void * const CNWSObject__SetIsRaiseable;
// void CNWSObject::SetKillerunsigned long int
extern void * const CNWSObject__SetKiller;
// void CNWSObject::SetLastAnimationTimesunsigned long int, unsigned long int
extern void * const CNWSObject__SetLastAnimationTimes;
// void CNWSObject::SetLastAttackerunsigned long int
extern void * const CNWSObject__SetLastAttacker;
// void CNWSObject::SetLastAttackModeunsigned char
extern void * const CNWSObject__SetLastAttackMode;
// void CNWSObject::SetLastAttackTypeunsigned short int
extern void * const CNWSObject__SetLastAttackType;
// public void CNWSObject::SetLastConversationResrefCExoString
extern void * const CNWSObject__SetLastConversationResref;
// void CNWSObject::SetLastDamageAmountint, int
extern void * const CNWSObject__SetLastDamageAmount;
// void CNWSObject::SetLastDamagerunsigned long int
extern void * const CNWSObject__SetLastDamager;
// void CNWSObject::SetLastDisturbedunsigned long int
extern void * const CNWSObject__SetLastDisturbed;
// void CNWSObject::SetLastGroupIDunsigned short int
extern void * const CNWSObject__SetLastGroupID;
// public void CNWSObject::SetLastHostileActorunsigned long int, int
extern void * const CNWSObject__SetLastHostileActor;
// void CNWSObject::SetLastSpeakerunsigned long int
extern void * const CNWSObject__SetLastSpeaker;
// void CNWSObject::SetLastSpellCastint
extern void * const CNWSObject__SetLastSpellCast;
// void CNWSObject::SetLastSpellCastAtMeunsigned long int
extern void * const CNWSObject__SetLastSpellCastAtMe;
// void CNWSObject::SetLastSpellCastAtMeCasterunsigned long int
extern void * const CNWSObject__SetLastSpellCastAtMeCaster;
// void CNWSObject::SetLastSpellCastAtMeHarmfulint
extern void * const CNWSObject__SetLastSpellCastAtMeHarmful;
// void CNWSObject::SetLastSpellCastDomainLevelunsigned char
extern void * const CNWSObject__SetLastSpellCastDomainLevel;
// void CNWSObject::SetLastSpellCastFeatunsigned short int
extern void * const CNWSObject__SetLastSpellCastFeat;
// void CNWSObject::SetLastSpellCastMetaTypeunsigned char
extern void * const CNWSObject__SetLastSpellCastMetaType;
// void CNWSObject::SetLastSpellCastMulticlassunsigned char
extern void * const CNWSObject__SetLastSpellCastMulticlass;
// void CNWSObject::SetLastSpellCastSpontaneousint
extern void * const CNWSObject__SetLastSpellCastSpontaneous;
// void CNWSObject::SetLastSpellIdunsigned long int
extern void * const CNWSObject__SetLastSpellId;
// void CNWSObject::SetLastSpellLocationTargetVector
extern void * const CNWSObject__SetLastSpellLocationTarget;
// void CNWSObject::SetLastSpellObjectTargetunsigned long int
extern void * const CNWSObject__SetLastSpellObjectTarget;
// void CNWSObject::SetLastWeaponAttackedWithunsigned long int
extern void * const CNWSObject__SetLastWeaponAttackedWith;
// public int CNWSObject::SetListenExpressionCExoString, int
extern void * const CNWSObject__SetListenExpression;
// void CNWSObject::SetListeningint
extern void * const CNWSObject__SetListening;
// public void CNWSObject::SetLockOrientationToObjectunsigned long int
extern void * const CNWSObject__SetLockOrientationToObject;
// void CNWSObject::SetMatchedPosint
extern void * const CNWSObject__SetMatchedPos;
// void CNWSObject::SetOpenDoorAnimationPlayedint
extern void * const CNWSObject__SetOpenDoorAnimationPlayed;
// public void CNWSObject::SetOrientationVector
extern void * const CNWSObject__SetOrientation;
// void CNWSObject::SetPendingEffectRemovalint
extern void * const CNWSObject__SetPendingEffectRemoval;
// void CNWSObject::SetPlotObjectint
extern void * const CNWSObject__SetPlotObject;
// public void CNWSObject::SetPortraitCResRef
extern void * const CNWSObject__SetPortrait;
// public void CNWSObject::SetPortraitIdunsigned short int
extern void * const CNWSObject__SetPortraitId;
// public void CNWSObject::SetPositionVector, int
extern void * const CNWSObject__SetPosition;
// void CNWSObject::SetPrivateConversationint
extern void * const CNWSObject__SetPrivateConversation;
// void CNWSObject::SetSavingThrowSpellIdunsigned long int
extern void * const CNWSObject__SetSavingThrowSpellId;
// void CNWSObject::SetSelectableWhenDeadint
extern void * const CNWSObject__SetSelectableWhenDead;
// void CNWSObject::SetStartActionTimerunsigned long int, unsigned long int
extern void * const CNWSObject__SetStartActionTimer;
// public void CNWSObject::SetTagCExoString
extern void * const CNWSObject__SetTag;
// void CNWSObject::SetTemplateconst CExoString&
extern void * const CNWSObject__SetTemplate;
// void CNWSObject::SetTemporaryHitPointsint
extern void * const CNWSObject__SetTemporaryHitPoints;
// public void CNWSObject::SpawnBodyBagvoid
extern void * const CNWSObject__SpawnBodyBag;
// public void CNWSObject::SpellCastAndImpactunsigned long int, Vector, unsigned long int, unsigned char, unsigned long int, int, int, unsigned char, int
extern void * const CNWSObject__SpellCastAndImpact;
// public int CNWSObject::StartDialogunsigned long int, const CExoString&, int, int
extern void * const CNWSObject__StartDialog;
// public int CNWSObject::StopDialogvoid
extern void * const CNWSObject__StopDialog;
// void CNWSObject::TerminateAISliceAfterActionunsigned long int
extern void * const CNWSObject__TerminateAISliceAfterAction;
// void CNWSObject::TestActionListvoid
extern void * const CNWSObject__TestActionList;
// public int CNWSObject::TestListenExpressionCExoString
extern void * const CNWSObject__TestListenExpression;
// protected void CNWSObject::UpdateAttributesOnEffectCGameEffect*, int
extern void * const CNWSObject__UpdateAttributesOnEffect;
// public int CNWSObject::UpdateDialogvoid
extern void * const CNWSObject__UpdateDialog;
// public void CNWSObject::UpdateEffectListunsigned long int, unsigned long int
extern void * const CNWSObject__UpdateEffectList;
// protected void CNWSObject::UpdateEffectPtrsvoid
extern void * const CNWSObject__UpdateEffectPtrs;

// public CNWSObjectActionNode::CNWSObjectActionNodevoid
extern void * const CNWSObjectActionNode__CNWSObjectActionNodeCtor;
// public CNWSObjectActionNode::~CNWSObjectActionNodevoid
extern void * const CNWSObjectActionNode__CNWSObjectActionNodeDtor;

// public CNWSpell::CNWSpellvoid
extern void * const CNWSpell__CNWSpellCtor;
// public CNWSpell::~CNWSpellvoid
extern void * const CNWSpell__CNWSpellDtor;
// public int CNWSpell::GetSpellHasSomaticComponentvoid
extern void * const CNWSpell__GetSpellHasSomaticComponent;
// public int CNWSpell::GetSpellHasVerbalComponentvoid
extern void * const CNWSpell__GetSpellHasVerbalComponent;
// public unsigned char CNWSpell::GetSpellLevelunsigned char
extern void * const CNWSpell__GetSpellLevel;
// void CNWSpell::GetSpellNameTextvoid
extern void * const CNWSpell__GetSpellNameText;
// public unsigned long int CNWSpell::GetSubRadialSpellunsigned char
extern void * const CNWSpell__GetSubRadialSpell;
// void CNWSpell::SetSubRadialSpellunsigned char, unsigned long int
extern void * const CNWSpell__SetSubRadialSpell;
// void CNWSpell::SetSubRadialSpellCountunsigned char
extern void * const CNWSpell__SetSubRadialSpellCount;

// public CNWSpellArray::CNWSpellArrayvoid
extern void * const CNWSpellArray__CNWSpellArrayCtor;
// public CNWSpellArray::~CNWSpellArrayvoid
extern void * const CNWSpellArray__CNWSpellArrayDtor;
// void CNWSpellArray::__vcint const
extern void * const CNWSpellArray____vc;
// public CNWSpell* CNWSpellArray::GetSpellint const
extern void * const CNWSpellArray__GetSpell;
// public void CNWSpellArray::Loadvoid
extern void * const CNWSpellArray__Load;

// public CNWSPlaceable::CNWSPlaceableunsigned long int
extern void * const CNWSPlaceable__CNWSPlaceableCtor;
// public CNWSPlaceable::~CNWSPlaceablevoid
extern void * const CNWSPlaceable__CNWSPlaceableDtor;
// public int CNWSPlaceable::AcquireItemCNWSItem**, unsigned long int, unsigned char, unsigned char, int
extern void * const CNWSPlaceable__AcquireItem;
// public unsigned long int CNWSPlaceable::AcquireItemsFromObjectunsigned long int, int
extern void * const CNWSPlaceable__AcquireItemsFromObject;
// public int CNWSPlaceable::AddCastSpellActionsunsigned long int, int, Vector, unsigned long int, int, unsigned char
extern void * const CNWSPlaceable__AddCastSpellActions;
// public void CNWSPlaceable::AddToAreaCNWSArea*, float, float, float, int
extern void * const CNWSPlaceable__AddToArea;
// public unsigned long int CNWSPlaceable::AIActionCastSpellCNWSObjectActionNode*
extern void * const CNWSPlaceable__AIActionCastSpell;
// public void CNWSPlaceable::AIUpdatevoid
extern void * const CNWSPlaceable__AIUpdate;
// public CNWSPlaceable* CNWSPlaceable::AsNWSPlaceablevoid
extern void * const CNWSPlaceable__AsNWSPlaceable;
// protected void CNWSPlaceable::CalculateActionPointsvoid
extern void * const CNWSPlaceable__CalculateActionPoints;
// public void CNWSPlaceable::CloseInventoryunsigned long int, int
extern void * const CNWSPlaceable__CloseInventory;
// public void CNWSPlaceable::ClosePlaceableForAllPlayersvoid
extern void * const CNWSPlaceable__ClosePlaceableForAllPlayers;
// public void CNWSPlaceable::DoDamageint
extern void * const CNWSPlaceable__DoDamage;
// void CNWSPlaceable::DropItemsIntoAreavoid
extern void * const CNWSPlaceable__DropItemsIntoArea;
// public void CNWSPlaceable::EventHandlerunsigned long int, unsigned long int, void*, unsigned long int, unsigned long int
extern void * const CNWSPlaceable__EventHandler;
// void CNWSPlaceable::GetActivevoid
extern void * const CNWSPlaceable__GetActive;
// void CNWSPlaceable::GetAppearancevoid
extern void * const CNWSPlaceable__GetAppearance;
// void CNWSPlaceable::GetAutoRemoveKeyvoid
extern void * const CNWSPlaceable__GetAutoRemoveKey;
// void CNWSPlaceable::GetBaseTypevoid
extern void * const CNWSPlaceable__GetBaseType;
// void CNWSPlaceable::GetBearingvoid
extern void * const CNWSPlaceable__GetBearing;
// void CNWSPlaceable::GetBodyBagvoid
extern void * const CNWSPlaceable__GetBodyBag;
// public unsigned short int CNWSPlaceable::GetBodyBagAppearancevoid
extern void * const CNWSPlaceable__GetBodyBagAppearance;
// void CNWSPlaceable::GetCloseLockDCvoid
extern void * const CNWSPlaceable__GetCloseLockDC;
// void CNWSPlaceable::GetCreatureListvoid
extern void * const CNWSPlaceable__GetCreatureList;
// void CNWSPlaceable::GetCurrentItemContainervoid
extern void * const CNWSPlaceable__GetCurrentItemContainer;
// public CExoLocString& CNWSPlaceable::GetDescriptionvoid
extern void * const CNWSPlaceable__GetDescription;
// public CExoString CNWSPlaceable::GetDescriptionOverridevoid
extern void * const CNWSPlaceable__GetDescriptionOverride;
// void CNWSPlaceable::GetDetectablevoid
extern void * const CNWSPlaceable__GetDetectable;
// void CNWSPlaceable::GetDetectDCvoid
extern void * const CNWSPlaceable__GetDetectDC;
// public CResRef CNWSPlaceable::GetDialogResrefvoid
extern void * const CNWSPlaceable__GetDialogResref;
// void CNWSPlaceable::GetDieWhenEmptyvoid
extern void * const CNWSPlaceable__GetDieWhenEmpty;
// void CNWSPlaceable::GetDisarmablevoid
extern void * const CNWSPlaceable__GetDisarmable;
// void CNWSPlaceable::GetDisarmDCvoid
extern void * const CNWSPlaceable__GetDisarmDC;
// public CExoString CNWSPlaceable::GetDisplayNamevoid
extern void * const CNWSPlaceable__GetDisplayName;
// public unsigned long int CNWSPlaceable::GetEffectSpellIdvoid
extern void * const CNWSPlaceable__GetEffectSpellId;
// void CNWSPlaceable::GetFactionIdvoid
extern void * const CNWSPlaceable__GetFactionId;
// public CExoLocString& CNWSPlaceable::GetFirstNamevoid
extern void * const CNWSPlaceable__GetFirstName;
// void CNWSPlaceable::GetFlaggedvoid
extern void * const CNWSPlaceable__GetFlagged;
// void CNWSPlaceable::GetFortSavevoid
extern void * const CNWSPlaceable__GetFortSave;
// void CNWSPlaceable::GetHardnessvoid
extern void * const CNWSPlaceable__GetHardness;
// void CNWSPlaceable::GetHasInventoryvoid
extern void * const CNWSPlaceable__GetHasInventory;
// void CNWSPlaceable::GetIsBodyBagvoid
extern void * const CNWSPlaceable__GetIsBodyBag;
// void CNWSPlaceable::GetIsGroundPilevoid
extern void * const CNWSPlaceable__GetIsGroundPile;
// void CNWSPlaceable::GetItemContainerArrayIndexvoid
extern void * const CNWSPlaceable__GetItemContainerArrayIndex;
// public unsigned long int CNWSPlaceable::GetItemCountint
extern void * const CNWSPlaceable__GetItemCount;
// void CNWSPlaceable::GetItemRepositoryvoid
extern void * const CNWSPlaceable__GetItemRepository;
// void CNWSPlaceable::GetKeyNamevoid
extern void * const CNWSPlaceable__GetKeyName;
// void CNWSPlaceable::GetKeyRequiredvoid
extern void * const CNWSPlaceable__GetKeyRequired;
// public CExoString CNWSPlaceable::GetKeyRequiredFeedbackMessagevoid
extern void * const CNWSPlaceable__GetKeyRequiredFeedbackMessage;
// void CNWSPlaceable::GetLastClosedvoid
extern void * const CNWSPlaceable__GetLastClosed;
// void CNWSPlaceable::GetLastDefaultClickedByvoid
extern void * const CNWSPlaceable__GetLastDefaultClickedBy;
// void CNWSPlaceable::GetLastDisarmedvoid
extern void * const CNWSPlaceable__GetLastDisarmed;
// void CNWSPlaceable::GetLastLockedvoid
extern void * const CNWSPlaceable__GetLastLocked;
// void CNWSPlaceable::GetLastOpenedvoid
extern void * const CNWSPlaceable__GetLastOpened;
// void CNWSPlaceable::GetLastTriggeredvoid
extern void * const CNWSPlaceable__GetLastTriggered;
// void CNWSPlaceable::GetLastUnlockedvoid
extern void * const CNWSPlaceable__GetLastUnlocked;
// void CNWSPlaceable::GetLastUservoid
extern void * const CNWSPlaceable__GetLastUser;
// public int CNWSPlaceable::GetLightIsOnvoid
extern void * const CNWSPlaceable__GetLightIsOn;
// void CNWSPlaceable::GetLightStateChangevoid
extern void * const CNWSPlaceable__GetLightStateChange;
// void CNWSPlaceable::GetLockablevoid
extern void * const CNWSPlaceable__GetLockable;
// void CNWSPlaceable::GetLockedvoid
extern void * const CNWSPlaceable__GetLocked;
// void CNWSPlaceable::GetLootableCreatureIdvoid
extern void * const CNWSPlaceable__GetLootableCreatureId;
// public Vector CNWSPlaceable::GetNearestActionPointconst Vector&
extern void * const CNWSPlaceable__GetNearestActionPoint;
// void CNWSPlaceable::GetNeverMakeIntoStaticObjectvoid
extern void * const CNWSPlaceable__GetNeverMakeIntoStaticObject;
// void CNWSPlaceable::GetOneShotvoid
extern void * const CNWSPlaceable__GetOneShot;
// void CNWSPlaceable::GetOpenLockDCvoid
extern void * const CNWSPlaceable__GetOpenLockDC;
// void CNWSPlaceable::GetPickablevoid
extern void * const CNWSPlaceable__GetPickable;
// public CExoString CNWSPlaceable::GetPortalInfovoid
extern void * const CNWSPlaceable__GetPortalInfo;
// void CNWSPlaceable::GetRecoverablevoid
extern void * const CNWSPlaceable__GetRecoverable;
// void CNWSPlaceable::GetReflexSavevoid
extern void * const CNWSPlaceable__GetReflexSave;
// void CNWSPlaceable::GetRepositoryArrayIndexvoid
extern void * const CNWSPlaceable__GetRepositoryArrayIndex;
// void CNWSPlaceable::GetScriptNameint
extern void * const CNWSPlaceable__GetScriptName;
// void CNWSPlaceable::GetSittingCreaturevoid
extern void * const CNWSPlaceable__GetSittingCreature;
// void CNWSPlaceable::GetStaticObjectvoid
extern void * const CNWSPlaceable__GetStaticObject;
// void CNWSPlaceable::GetTemplateResRefvoid
extern void * const CNWSPlaceable__GetTemplateResRef;
// void CNWSPlaceable::GetTrapCreatorvoid
extern void * const CNWSPlaceable__GetTrapCreator;
// void CNWSPlaceable::GetTrapFactionvoid
extern void * const CNWSPlaceable__GetTrapFaction;
// void CNWSPlaceable::GetTrappedvoid
extern void * const CNWSPlaceable__GetTrapped;
// void CNWSPlaceable::GetTypevoid
extern void * const CNWSPlaceable__GetType;
// void CNWSPlaceable::GetUpdateDisplayNamevoid
extern void * const CNWSPlaceable__GetUpdateDisplayName;
// void CNWSPlaceable::GetUseablevoid
extern void * const CNWSPlaceable__GetUseable;
// void CNWSPlaceable::GetWillSavevoid
extern void * const CNWSPlaceable__GetWillSave;
// public int CNWSPlaceable::LoadBodyBagunsigned short int
extern void * const CNWSPlaceable__LoadBodyBag;
// public int CNWSPlaceable::LoadFromTemplateCResRef, CExoString*
extern void * const CNWSPlaceable__LoadFromTemplate;
// public int CNWSPlaceable::LoadPlaceableCResGFF*, CResStruct*, CExoString*
extern void * const CNWSPlaceable__LoadPlaceable;
// public void CNWSPlaceable::OpenInventoryunsigned long int
extern void * const CNWSPlaceable__OpenInventory;
// public void CNWSPlaceable::PostProcessvoid
extern void * const CNWSPlaceable__PostProcess;
// public void CNWSPlaceable::RemoveFromAreavoid
extern void * const CNWSPlaceable__RemoveFromArea;
// public int CNWSPlaceable::RemoveItemCNWSItem*, int
extern void * const CNWSPlaceable__RemoveItem;
// public int CNWSPlaceable::SavePlaceableCResGFF*, CResStruct*
extern void * const CNWSPlaceable__SavePlaceable;
// void CNWSPlaceable::SetActiveint
extern void * const CNWSPlaceable__SetActive;
// void CNWSPlaceable::SetAppearanceunsigned short int
extern void * const CNWSPlaceable__SetAppearance;
// void CNWSPlaceable::SetAutoRemoveKeyint
extern void * const CNWSPlaceable__SetAutoRemoveKey;
// void CNWSPlaceable::SetBaseTypeunsigned char
extern void * const CNWSPlaceable__SetBaseType;
// void CNWSPlaceable::SetBearingfloat
extern void * const CNWSPlaceable__SetBearing;
// void CNWSPlaceable::SetBodyBagunsigned char
extern void * const CNWSPlaceable__SetBodyBag;
// void CNWSPlaceable::SetCloseLockDCunsigned char
extern void * const CNWSPlaceable__SetCloseLockDC;
// void CNWSPlaceable::SetCurrentItemContainerunsigned long int
extern void * const CNWSPlaceable__SetCurrentItemContainer;
// public void CNWSPlaceable::SetDescriptionCExoLocString
extern void * const CNWSPlaceable__SetDescription;
// public void CNWSPlaceable::SetDescriptionOverrideCExoString
extern void * const CNWSPlaceable__SetDescriptionOverride;
// void CNWSPlaceable::SetDetectableint
extern void * const CNWSPlaceable__SetDetectable;
// void CNWSPlaceable::SetDetectDCunsigned char
extern void * const CNWSPlaceable__SetDetectDC;
// public void CNWSPlaceable::SetDialogResrefCResRef
extern void * const CNWSPlaceable__SetDialogResref;
// void CNWSPlaceable::SetDieWhenEmptyint
extern void * const CNWSPlaceable__SetDieWhenEmpty;
// void CNWSPlaceable::SetDisarmableint
extern void * const CNWSPlaceable__SetDisarmable;
// void CNWSPlaceable::SetDisarmDCunsigned char
extern void * const CNWSPlaceable__SetDisarmDC;
// public void CNWSPlaceable::SetDisplayNameCExoString
extern void * const CNWSPlaceable__SetDisplayName;
// public void CNWSPlaceable::SetEffectSpellIdunsigned long int
extern void * const CNWSPlaceable__SetEffectSpellId;
// void CNWSPlaceable::SetFactionIdint
extern void * const CNWSPlaceable__SetFactionId;
// public void CNWSPlaceable::SetFirstNameCExoLocString
extern void * const CNWSPlaceable__SetFirstName;
// void CNWSPlaceable::SetFlaggedunsigned char
extern void * const CNWSPlaceable__SetFlagged;
// void CNWSPlaceable::SetFortSaveunsigned char
extern void * const CNWSPlaceable__SetFortSave;
// void CNWSPlaceable::SetHardnessunsigned char
extern void * const CNWSPlaceable__SetHardness;
// void CNWSPlaceable::SetHasInventoryint
extern void * const CNWSPlaceable__SetHasInventory;
// void CNWSPlaceable::SetIsBodyBagint
extern void * const CNWSPlaceable__SetIsBodyBag;
// void CNWSPlaceable::SetIsGroundPileint
extern void * const CNWSPlaceable__SetIsGroundPile;
// void CNWSPlaceable::SetItemContainerArrayIndexunsigned short int
extern void * const CNWSPlaceable__SetItemContainerArrayIndex;
// void CNWSPlaceable::SetKeyNameconst CExoString&
extern void * const CNWSPlaceable__SetKeyName;
// void CNWSPlaceable::SetKeyRequiredint
extern void * const CNWSPlaceable__SetKeyRequired;
// public void CNWSPlaceable::SetKeyRequiredFeedbackMessageCExoString
extern void * const CNWSPlaceable__SetKeyRequiredFeedbackMessage;
// void CNWSPlaceable::SetLastClosedunsigned long int
extern void * const CNWSPlaceable__SetLastClosed;
// void CNWSPlaceable::SetLastDefaultClickedByunsigned long int
extern void * const CNWSPlaceable__SetLastDefaultClickedBy;
// void CNWSPlaceable::SetLastDisarmedunsigned long int
extern void * const CNWSPlaceable__SetLastDisarmed;
// void CNWSPlaceable::SetLastLockedunsigned long int
extern void * const CNWSPlaceable__SetLastLocked;
// void CNWSPlaceable::SetLastOpenedunsigned long int
extern void * const CNWSPlaceable__SetLastOpened;
// void CNWSPlaceable::SetLastTriggeredunsigned long int
extern void * const CNWSPlaceable__SetLastTriggered;
// void CNWSPlaceable::SetLastUnlockedunsigned long int
extern void * const CNWSPlaceable__SetLastUnlocked;
// void CNWSPlaceable::SetLastUserunsigned long int
extern void * const CNWSPlaceable__SetLastUser;
// public void CNWSPlaceable::SetLightIsOnint
extern void * const CNWSPlaceable__SetLightIsOn;
// void CNWSPlaceable::SetLightStateChangeint
extern void * const CNWSPlaceable__SetLightStateChange;
// void CNWSPlaceable::SetLockableint
extern void * const CNWSPlaceable__SetLockable;
// void CNWSPlaceable::SetLockedint
extern void * const CNWSPlaceable__SetLocked;
// void CNWSPlaceable::SetLootableCreatureIdunsigned long int
extern void * const CNWSPlaceable__SetLootableCreatureId;
// void CNWSPlaceable::SetNeverMakeIntoStaticObjectint
extern void * const CNWSPlaceable__SetNeverMakeIntoStaticObject;
// void CNWSPlaceable::SetOneShotint
extern void * const CNWSPlaceable__SetOneShot;
// void CNWSPlaceable::SetOpenLockDCunsigned char
extern void * const CNWSPlaceable__SetOpenLockDC;
// public void CNWSPlaceable::SetOrientationVector
extern void * const CNWSPlaceable__SetOrientation;
// void CNWSPlaceable::SetPickableint
extern void * const CNWSPlaceable__SetPickable;
// public void CNWSPlaceable::SetPortalInfoCExoString
extern void * const CNWSPlaceable__SetPortalInfo;
// void CNWSPlaceable::SetRecoverableint
extern void * const CNWSPlaceable__SetRecoverable;
// void CNWSPlaceable::SetReflexSaveunsigned char
extern void * const CNWSPlaceable__SetReflexSave;
// void CNWSPlaceable::SetRepositoryArrayIndexunsigned short int
extern void * const CNWSPlaceable__SetRepositoryArrayIndex;
// public void CNWSPlaceable::SetScriptNameint, CExoString
extern void * const CNWSPlaceable__SetScriptName;
// void CNWSPlaceable::SetSittingCreatureunsigned long int
extern void * const CNWSPlaceable__SetSittingCreature;
// void CNWSPlaceable::SetStaticObjectint
extern void * const CNWSPlaceable__SetStaticObject;
// public void CNWSPlaceable::SetTemplateResRefCResRef
extern void * const CNWSPlaceable__SetTemplateResRef;
// void CNWSPlaceable::SetTrapCreatorunsigned long int
extern void * const CNWSPlaceable__SetTrapCreator;
// void CNWSPlaceable::SetTrapFactionint
extern void * const CNWSPlaceable__SetTrapFaction;
// void CNWSPlaceable::SetTrappedint
extern void * const CNWSPlaceable__SetTrapped;
// void CNWSPlaceable::SetTypeunsigned char
extern void * const CNWSPlaceable__SetType;
// void CNWSPlaceable::SetUpdateDisplayNameint
extern void * const CNWSPlaceable__SetUpdateDisplayName;
// void CNWSPlaceable::SetUseableint
extern void * const CNWSPlaceable__SetUseable;
// void CNWSPlaceable::SetWillSaveunsigned char
extern void * const CNWSPlaceable__SetWillSave;

// public CNWSPlayer::CNWSPlayerunsigned long int
extern void * const CNWSPlayer__CNWSPlayerCtor;
// public CNWSPlayer::~CNWSPlayervoid
extern void * const CNWSPlayer__CNWSPlayerDtor;
// public int CNWSPlayer::AddAreaunsigned long int
extern void * const CNWSPlayer__AddArea;
// public void CNWSPlayer::AddDMAbilitiesCNWSCreature*
extern void * const CNWSPlayer__AddDMAbilities;
// public void CNWSPlayer::AllocateAreasint
extern void * const CNWSPlayer__AllocateAreas;
// public CNWSPlayer* CNWSPlayer::AsNWSPlayervoid
extern void * const CNWSPlayer__AsNWSPlayer;
// public int CNWSPlayer::BackupServerCharacterconst CExoString&
extern void * const CNWSPlayer__BackupServerCharacter;
// public void CNWSPlayer::CleanMyTURDsvoid
extern void * const CNWSPlayer__CleanMyTURDs;
// void CNWSPlayer::ClearPlayerLastUpdateObjectvoid
extern void * const CNWSPlayer__ClearPlayerLastUpdateObject;
// public void CNWSPlayer::ClearPlayerOnDestroyGamevoid
extern void * const CNWSPlayer__ClearPlayerOnDestroyGame;
// public CNWSPlayerLastUpdateObject* CNWSPlayer::CreateNewPlayerLastUpdateObjectvoid
extern void * const CNWSPlayer__CreateNewPlayerLastUpdateObject;
// public void CNWSPlayer::DropTURDvoid
extern void * const CNWSPlayer__DropTURD;
// public void CNWSPlayer::EatTURDCNWSPlayerTURD*
extern void * const CNWSPlayer__EatTURD;
// void CNWSPlayer::GetAlwaysRunvoid
extern void * const CNWSPlayer__GetAlwaysRun;
// void CNWSPlayer::GetAreaint const
extern void * const CNWSPlayer__GetArea;
// void CNWSPlayer::GetAreaNumvoid const
extern void * const CNWSPlayer__GetAreaNum;
// void CNWSPlayer::GetAreaTransitionBMPvoid
extern void * const CNWSPlayer__GetAreaTransitionBMP;
// void CNWSPlayer::GetAreaTransitionNamevoid
extern void * const CNWSPlayer__GetAreaTransitionName;
// public int CNWSPlayer::GetCharacterInfoFromIFOunsigned char&, int*, unsigned char*, unsigned long int&
extern void * const CNWSPlayer__GetCharacterInfoFromIFO;
// void CNWSPlayer::GetCharacterTypevoid
extern void * const CNWSPlayer__GetCharacterType;
// void CNWSPlayer::GetCharSheetGUIInfovoid
extern void * const CNWSPlayer__GetCharSheetGUIInfo;
// void CNWSPlayer::GetCommunityNameAuthorizedvoid
extern void * const CNWSPlayer__GetCommunityNameAuthorized;
// void CNWSPlayer::GetContainerGUIInfovoid
extern void * const CNWSPlayer__GetContainerGUIInfo;
// void CNWSPlayer::GetCutsceneStatevoid
extern void * const CNWSPlayer__GetCutsceneState;
// void CNWSPlayer::GetFileNamevoid
extern void * const CNWSPlayer__GetFileName;
// void CNWSPlayer::GetFloatyEffectsvoid
extern void * const CNWSPlayer__GetFloatyEffects;
// void CNWSPlayer::GetFromSaveGamevoid
extern void * const CNWSPlayer__GetFromSaveGame;
// void CNWSPlayer::GetFromTURDvoid
extern void * const CNWSPlayer__GetFromTURD;
// public CNWSObject* CNWSPlayer::GetGameObjectvoid
extern void * const CNWSPlayer__GetGameObject;
// void CNWSPlayer::GetIFOCharacterIndexvoid
extern void * const CNWSPlayer__GetIFOCharacterIndex;
// void CNWSPlayer::GetInventoryGUIInfovoid
extern void * const CNWSPlayer__GetInventoryGUIInfo;
// public int CNWSPlayer::GetIsAllowedToSavevoid
extern void * const CNWSPlayer__GetIsAllowedToSave;
// void CNWSPlayer::GetIsPrimaryPlayervoid
extern void * const CNWSPlayer__GetIsPrimaryPlayer;
// void CNWSPlayer::GetJournalQuestInfovoid
extern void * const CNWSPlayer__GetJournalQuestInfo;
// void CNWSPlayer::GetLastObjectControlledvoid
extern void * const CNWSPlayer__GetLastObjectControlled;
// void CNWSPlayer::GetLastUpdatedTimevoid
extern void * const CNWSPlayer__GetLastUpdatedTime;
// public CLastUpdateObject* CNWSPlayer::GetLastUpdateObjectunsigned long int
extern void * const CNWSPlayer__GetLastUpdateObject;
// void CNWSPlayer::GetLoginStatevoid
extern void * const CNWSPlayer__GetLoginState;
// void CNWSPlayer::GetModuleInfoSucceededvoid
extern void * const CNWSPlayer__GetModuleInfoSucceeded;
// void CNWSPlayer::GetOtherInventoryGUIInfovoid
extern void * const CNWSPlayer__GetOtherInventoryGUIInfo;
// void CNWSPlayer::GetPCObjectvoid
extern void * const CNWSPlayer__GetPCObject;
// void CNWSPlayer::GetPlayerLastUpdateObjectvoid
extern void * const CNWSPlayer__GetPlayerLastUpdateObject;
// void CNWSPlayer::GetPlayerListIndexvoid
extern void * const CNWSPlayer__GetPlayerListIndex;
// public CExoString CNWSPlayer::GetPlayerNamevoid
extern void * const CNWSPlayer__GetPlayerName;
// void CNWSPlayer::GetPlayModuleListingCharactersvoid
extern void * const CNWSPlayer__GetPlayModuleListingCharacters;
// void CNWSPlayer::GetStoreGUIInfovoid
extern void * const CNWSPlayer__GetStoreGUIInfo;
// public int CNWSPlayer::HasExpansionPackunsigned char, int
extern void * const CNWSPlayer__HasExpansionPack;
// public CNWSCreature* CNWSPlayer::LoadCharacterFromIFOunsigned long int, int, int, int, int
extern void * const CNWSPlayer__LoadCharacterFromIFO;
// public unsigned long int CNWSPlayer::LoadCreatureDataCResRef, CNWSCreature*
extern void * const CNWSPlayer__LoadCreatureData;
// public unsigned long int CNWSPlayer::LoadDMCharactervoid
extern void * const CNWSPlayer__LoadDMCharacter;
// public unsigned long int CNWSPlayer::LoadLocalCharactervoid
extern void * const CNWSPlayer__LoadLocalCharacter;
// public unsigned long int CNWSPlayer::LoadServerCharacterCResRef, int
extern void * const CNWSPlayer__LoadServerCharacter;
// public void CNWSPlayer::LoadTURDInfoFromIFOunsigned long int
extern void * const CNWSPlayer__LoadTURDInfoFromIFO;
// public int CNWSPlayer::PackCreatureIntoMessagevoid
extern void * const CNWSPlayer__PackCreatureIntoMessage;
// public int CNWSPlayer::PermittedToDisplayCharacterSheetunsigned long int
extern void * const CNWSPlayer__PermittedToDisplayCharacterSheet;
// public void CNWSPlayer::RestoreCameraSettingsvoid
extern void * const CNWSPlayer__RestoreCameraSettings;
// public int CNWSPlayer::SaveServerCharacterint
extern void * const CNWSPlayer__SaveServerCharacter;
// void CNWSPlayer::SetAlwaysRunint
extern void * const CNWSPlayer__SetAlwaysRun;
// public void CNWSPlayer::SetAreaTransitionBMPint, CExoString
extern void * const CNWSPlayer__SetAreaTransitionBMP;
// void CNWSPlayer::SetCharacterTypeunsigned char
extern void * const CNWSPlayer__SetCharacterType;
// void CNWSPlayer::SetCommunityNameAuthorizedint
extern void * const CNWSPlayer__SetCommunityNameAuthorized;
// void CNWSPlayer::SetCutsceneStateint
extern void * const CNWSPlayer__SetCutsceneState;
// public void CNWSPlayer::SetFileNameCResRef
extern void * const CNWSPlayer__SetFileName;
// void CNWSPlayer::SetFloatyEffectsint
extern void * const CNWSPlayer__SetFloatyEffects;
// void CNWSPlayer::SetFromSaveGameint
extern void * const CNWSPlayer__SetFromSaveGame;
// void CNWSPlayer::SetFromTURDint
extern void * const CNWSPlayer__SetFromTURD;
// public void CNWSPlayer::SetGameObjectCNWSObject*
extern void * const CNWSPlayer__SetGameObject;
// void CNWSPlayer::SetIFOCharacterIndexunsigned long int
extern void * const CNWSPlayer__SetIFOCharacterIndex;
// void CNWSPlayer::SetIsPrimaryPlayerint
extern void * const CNWSPlayer__SetIsPrimaryPlayer;
// void CNWSPlayer::SetLastObjectControlledunsigned long int
extern void * const CNWSPlayer__SetLastObjectControlled;
// void CNWSPlayer::SetLastUpdatedTimeunsigned long long int
extern void * const CNWSPlayer__SetLastUpdatedTime;
// void CNWSPlayer::SetLoginStateunsigned char
extern void * const CNWSPlayer__SetLoginState;
// void CNWSPlayer::SetModuleInfoSucceededint
extern void * const CNWSPlayer__SetModuleInfoSucceeded;
// void CNWSPlayer::SetPCObjectunsigned long int
extern void * const CNWSPlayer__SetPCObject;
// void CNWSPlayer::SetPlayerListIndexunsigned long int
extern void * const CNWSPlayer__SetPlayerListIndex;
// void CNWSPlayer::SetPlayModuleListingCharactersint
extern void * const CNWSPlayer__SetPlayModuleListingCharacters;
// public void CNWSPlayer::StoreCameraSettingsvoid
extern void * const CNWSPlayer__StoreCameraSettings;
// public void CNWSPlayer::StripAllInvalidItemPropertiesInInventoryCNWSCreature*
extern void * const CNWSPlayer__StripAllInvalidItemPropertiesInInventory;
// public void CNWSPlayer::StripAllInvalidItemPropertiesOnItemCNWSItem*
extern void * const CNWSPlayer__StripAllInvalidItemPropertiesOnItem;
// public unsigned long int CNWSPlayer::ValidateCharacterint*
extern void * const CNWSPlayer__ValidateCharacter;
// void CNWSPlayer::ValidateCharacter_SetNormalBonusFlagsunsigned short int, int&, int&, unsigned char
extern void * const CNWSPlayer__ValidateCharacter_SetNormalBonusFlags;

// public unsigned long int CNWSPlayerCharSheetGUI::ComputeCharacterSheetUpdateRequiredCNWSPlayer*
extern void * const CNWSPlayerCharSheetGUI__ComputeCharacterSheetUpdateRequired;
// public void CNWSPlayerCharSheetGUI::SetCreatureDisplayedunsigned long int
extern void * const CNWSPlayerCharSheetGUI__SetCreatureDisplayed;

// CNWSPlayerContainerGUI::CNWSPlayerContainerGUIvoid
extern void * const CNWSPlayerContainerGUI__CNWSPlayerContainerGUICtor;
// public void CNWSPlayerContainerGUI::SetNextPageCNWSPlayer*
extern void * const CNWSPlayerContainerGUI__SetNextPage;
// public void CNWSPlayerContainerGUI::SetOpenCNWSPlayer*, unsigned long int, int
extern void * const CNWSPlayerContainerGUI__SetOpen;
// public void CNWSPlayerContainerGUI::SetPreviousPageCNWSPlayer*
extern void * const CNWSPlayerContainerGUI__SetPreviousPage;

// public CNWSPlayerInventoryGUI::CNWSPlayerInventoryGUIvoid
extern void * const CNWSPlayerInventoryGUI__CNWSPlayerInventoryGUICtor;
// public CNWSPlayerInventoryGUI::~CNWSPlayerInventoryGUIvoid
extern void * const CNWSPlayerInventoryGUI__CNWSPlayerInventoryGUIDtor;
// public void CNWSPlayerInventoryGUI::SetOpenint
extern void * const CNWSPlayerInventoryGUI__SetOpen;
// public void CNWSPlayerInventoryGUI::SetOwnerunsigned long int
extern void * const CNWSPlayerInventoryGUI__SetOwner;
// public void CNWSPlayerInventoryGUI::SetPanelCNWSPlayer*, unsigned char
extern void * const CNWSPlayerInventoryGUI__SetPanel;

// public CNWSPlayerLastUpdateObject::CNWSPlayerLastUpdateObjectvoid
extern void * const CNWSPlayerLastUpdateObject__CNWSPlayerLastUpdateObjectCtor;
// public CNWSPlayerLastUpdateObject::~CNWSPlayerLastUpdateObjectvoid
extern void * const CNWSPlayerLastUpdateObject__CNWSPlayerLastUpdateObjectDtor;
// public void CNWSPlayerLastUpdateObject::AddKnownSpellunsigned char, unsigned char, unsigned long int
extern void * const CNWSPlayerLastUpdateObject__AddKnownSpell;
// public void CNWSPlayerLastUpdateObject::ClearActionQueuevoid
extern void * const CNWSPlayerLastUpdateObject__ClearActionQueue;
// public void CNWSPlayerLastUpdateObject::ClearAutoMapDatavoid
extern void * const CNWSPlayerLastUpdateObject__ClearAutoMapData;
// void CNWSPlayerLastUpdateObject::ClearEffectIconsvoid
extern void * const CNWSPlayerLastUpdateObject__ClearEffectIcons;
// public void CNWSPlayerLastUpdateObject::ClearKnownSpellsvoid
extern void * const CNWSPlayerLastUpdateObject__ClearKnownSpells;
// public void CNWSPlayerLastUpdateObject::ClearKnownSpellUsesLeftvoid
extern void * const CNWSPlayerLastUpdateObject__ClearKnownSpellUsesLeft;
// public void CNWSPlayerLastUpdateObject::ClearMemorizedSpellsvoid
extern void * const CNWSPlayerLastUpdateObject__ClearMemorizedSpells;
// public void CNWSPlayerLastUpdateObject::ClearSpellAddDeleteListsvoid
extern void * const CNWSPlayerLastUpdateObject__ClearSpellAddDeleteLists;
// public void CNWSPlayerLastUpdateObject::ClearVisibilityListvoid
extern void * const CNWSPlayerLastUpdateObject__ClearVisibilityList;
// public int CNWSPlayerLastUpdateObject::GetIsDomainSpellunsigned char, unsigned char, unsigned char
extern void * const CNWSPlayerLastUpdateObject__GetIsDomainSpell;
// public unsigned long int CNWSPlayerLastUpdateObject::GetKnownSpellunsigned char, unsigned char, unsigned char
extern void * const CNWSPlayerLastUpdateObject__GetKnownSpell;
// public unsigned char CNWSPlayerLastUpdateObject::GetKnownSpellUsesLeftunsigned char, unsigned char
extern void * const CNWSPlayerLastUpdateObject__GetKnownSpellUsesLeft;
// public unsigned long int CNWSPlayerLastUpdateObject::GetMemorizedSpellunsigned char, unsigned char, unsigned char
extern void * const CNWSPlayerLastUpdateObject__GetMemorizedSpell;
// public unsigned char CNWSPlayerLastUpdateObject::GetMemorizedSpellMetaTypeunsigned char, unsigned char, unsigned char
extern void * const CNWSPlayerLastUpdateObject__GetMemorizedSpellMetaType;
// public int CNWSPlayerLastUpdateObject::GetMemorizedSpellReadiedunsigned char, unsigned char, unsigned char
extern void * const CNWSPlayerLastUpdateObject__GetMemorizedSpellReadied;
// public int CNWSPlayerLastUpdateObject::InitializeAutoMapDatavoid
extern void * const CNWSPlayerLastUpdateObject__InitializeAutoMapData;
// public void CNWSPlayerLastUpdateObject::ResetAutoMapDataunsigned long int
extern void * const CNWSPlayerLastUpdateObject__ResetAutoMapData;
// public void CNWSPlayerLastUpdateObject::SetKnownSpellUsesLeftunsigned char, unsigned char, unsigned char
extern void * const CNWSPlayerLastUpdateObject__SetKnownSpellUsesLeft;
// public void CNWSPlayerLastUpdateObject::SetMemorizedSpellReadiedunsigned char, unsigned char, unsigned char, int
extern void * const CNWSPlayerLastUpdateObject__SetMemorizedSpellReadied;
// public void CNWSPlayerLastUpdateObject::SetMemorizedSpellSlotunsigned char, unsigned char, unsigned char, unsigned long int, int, unsigned char
extern void * const CNWSPlayerLastUpdateObject__SetMemorizedSpellSlot;
// public void CNWSPlayerLastUpdateObject::SetNumberMemorizedSpellSlotsunsigned char, unsigned char, unsigned char
extern void * const CNWSPlayerLastUpdateObject__SetNumberMemorizedSpellSlots;

// public CNWSPlayerLUOInventory::CNWSPlayerLUOInventoryvoid
extern void * const CNWSPlayerLUOInventory__CNWSPlayerLUOInventoryCtor;
// public CNWSPlayerLUOInventory::~CNWSPlayerLUOInventoryvoid
extern void * const CNWSPlayerLUOInventory__CNWSPlayerLUOInventoryDtor;
// public void CNWSPlayerLUOInventory::ClearBartervoid
extern void * const CNWSPlayerLUOInventory__ClearBarter;
// public void CNWSPlayerLUOInventory::ClearContainervoid
extern void * const CNWSPlayerLUOInventory__ClearContainer;
// public void CNWSPlayerLUOInventory::ClearRepositoryvoid
extern void * const CNWSPlayerLUOInventory__ClearRepository;
// public void CNWSPlayerLUOInventory::ClearSlotsvoid
extern void * const CNWSPlayerLUOInventory__ClearSlots;
// public void CNWSPlayerLUOInventory::ClearStorevoid
extern void * const CNWSPlayerLUOInventory__ClearStore;
// public void CNWSPlayerLUOInventory::ItemListAddHeadunsigned long int, unsigned char, unsigned char, unsigned char, unsigned long int, unsigned long int
extern void * const CNWSPlayerLUOInventory__ItemListAddHead;
// public CNWSItem* CNWSPlayerLUOInventory::ItemListGetItemCExoLinkedListNode*, unsigned char
extern void * const CNWSPlayerLUOInventory__ItemListGetItem;
// public unsigned long int CNWSPlayerLUOInventory::ItemListGetItemObjectIDCExoLinkedListNode*, unsigned char
extern void * const CNWSPlayerLUOInventory__ItemListGetItemObjectID;
// void CNWSPlayerLUOInventory::ItemListGetNextCExoLinkedListNode*, unsigned char
extern void * const CNWSPlayerLUOInventory__ItemListGetNext;
// public unsigned long int CNWSPlayerLUOInventory::ItemListGetNumberunsigned char
extern void * const CNWSPlayerLUOInventory__ItemListGetNumber;
// public void CNWSPlayerLUOInventory::ItemListGetPrevCExoLinkedListNode*, unsigned char
extern void * const CNWSPlayerLUOInventory__ItemListGetPrev;
// public CNWSPlayerLUOInventoryItem* CNWSPlayerLUOInventory::ItemListGetUpdateItemCExoLinkedListNode*, unsigned char
extern void * const CNWSPlayerLUOInventory__ItemListGetUpdateItem;
// public void CNWSPlayerLUOInventory::ItemListRemoveCExoLinkedListNode*, unsigned char
extern void * const CNWSPlayerLUOInventory__ItemListRemove;
// public void CNWSPlayerLUOInventory::ItemListSetEndCExoLinkedListNode*, unsigned char
extern void * const CNWSPlayerLUOInventory__ItemListSetEnd;
// void CNWSPlayerLUOInventory::ItemListSetStartCExoLinkedListNode*, unsigned char
extern void * const CNWSPlayerLUOInventory__ItemListSetStart;

// CNWSPlayerStoreGUI::CNWSPlayerStoreGUIvoid
extern void * const CNWSPlayerStoreGUI__CNWSPlayerStoreGUICtor;
// public void CNWSPlayerStoreGUI::CloseStoreCNWSPlayer*, int
extern void * const CNWSPlayerStoreGUI__CloseStore;
// public void CNWSPlayerStoreGUI::OpenStoreCNWSPlayer*, unsigned long int, char, char
extern void * const CNWSPlayerStoreGUI__OpenStore;

// public CNWSPlayerTURD::CNWSPlayerTURDunsigned long int
extern void * const CNWSPlayerTURD__CNWSPlayerTURDCtor;
// public CNWSPlayerTURD::~CNWSPlayerTURDvoid
extern void * const CNWSPlayerTURD__CNWSPlayerTURDDtor;
// public void CNWSPlayerTURD::AddToAreaCNWSArea*, int
extern void * const CNWSPlayerTURD__AddToArea;
// public void CNWSPlayerTURD::AIUpdatevoid
extern void * const CNWSPlayerTURD__AIUpdate;
// public CNWSPlayerTURD* CNWSPlayerTURD::AsNWSPlayerTURDvoid
extern void * const CNWSPlayerTURD__AsNWSPlayerTURD;
// void CNWSPlayerTURD::ClearAutomapDatavoid
extern void * const CNWSPlayerTURD__ClearAutomapData;
// public void CNWSPlayerTURD::CopyAutomapDataint, CExoArrayListTemplatedunsignedlong*, unsigned char**
extern void * const CNWSPlayerTURD__CopyAutomapData;
// public void CNWSPlayerTURD::CopyEffectListCExoArrayListTemplatedCGameEffectPtr*
extern void * const CNWSPlayerTURD__CopyEffectList;
// public void CNWSPlayerTURD::EventHandlerunsigned long int, unsigned long int, void*, unsigned long int, unsigned long int
extern void * const CNWSPlayerTURD__EventHandler;
// void CNWSPlayerTURD::GetAutoMapAreasListvoid
extern void * const CNWSPlayerTURD__GetAutoMapAreasList;
// void CNWSPlayerTURD::GetAutoMapTileDatavoid
extern void * const CNWSPlayerTURD__GetAutoMapTileData;
// void CNWSPlayerTURD::GetCalendarDayvoid
extern void * const CNWSPlayerTURD__GetCalendarDay;
// void CNWSPlayerTURD::GetCalendarTimeOfDayvoid
extern void * const CNWSPlayerTURD__GetCalendarTimeOfDay;
// public CExoString CNWSPlayerTURD::GetCommunityNamevoid
extern void * const CNWSPlayerTURD__GetCommunityName;
// public CExoLocString& CNWSPlayerTURD::GetFirstNamevoid
extern void * const CNWSPlayerTURD__GetFirstName;
// public CExoLocString& CNWSPlayerTURD::GetLastNamevoid
extern void * const CNWSPlayerTURD__GetLastName;
// void CNWSPlayerTURD::GetNumAutoMapAreasvoid
extern void * const CNWSPlayerTURD__GetNumAutoMapAreas;
// void CNWSPlayerTURD::GetPersonalReputationvoid
extern void * const CNWSPlayerTURD__GetPersonalReputation;
// void CNWSPlayerTURD::GetPlayerIDvoid
extern void * const CNWSPlayerTURD__GetPlayerID;
// void CNWSPlayerTURD::GetReputationvoid
extern void * const CNWSPlayerTURD__GetReputation;
// private void CNWSPlayerTURD::LoadAutoMapDataCResGFF*, CResStruct*
extern void * const CNWSPlayerTURD__LoadAutoMapData;
// public int CNWSPlayerTURD::LoadTURDCResGFF*, CResStruct*
extern void * const CNWSPlayerTURD__LoadTURD;
// public void CNWSPlayerTURD::RemoveFromAreavoid
extern void * const CNWSPlayerTURD__RemoveFromArea;
// void CNWSPlayerTURD::SaveAutoMapDataCResGFF*, CResStruct*
extern void * const CNWSPlayerTURD__SaveAutoMapData;
// public void CNWSPlayerTURD::SaveTURDCResGFF*, CResStruct*
extern void * const CNWSPlayerTURD__SaveTURD;
// void CNWSPlayerTURD::SetCalendarDayunsigned long int
extern void * const CNWSPlayerTURD__SetCalendarDay;
// void CNWSPlayerTURD::SetCalendarTimeOfDayunsigned long int
extern void * const CNWSPlayerTURD__SetCalendarTimeOfDay;
// void CNWSPlayerTURD::SetCommunityNameconst CExoString&
extern void * const CNWSPlayerTURD__SetCommunityName;
// void CNWSPlayerTURD::SetFirstNameconst CExoLocString&
extern void * const CNWSPlayerTURD__SetFirstName;
// void CNWSPlayerTURD::SetLastNameconst CExoLocString&
extern void * const CNWSPlayerTURD__SetLastName;
// public void CNWSPlayerTURD::SetPersonalReputationCExoArrayListTemplatedCNWSPersonalReputation*
extern void * const CNWSPlayerTURD__SetPersonalReputation;
// void CNWSPlayerTURD::SetPlayerIDunsigned long int
extern void * const CNWSPlayerTURD__SetPlayerID;
// public void CNWSPlayerTURD::SetReputationCExoArrayListTemplatedint*
extern void * const CNWSPlayerTURD__SetReputation;

// public CNWSRules::CNWSRulesvoid
extern void * const CNWSRules__CNWSRulesCtor;
// public CNWSRules::~CNWSRulesvoid
extern void * const CNWSRules__CNWSRulesDtor;

// public CNWSScriptVarTable::~CNWSScriptVarTablevoid
extern void * const CNWSScriptVarTable__CNWSScriptVarTableDtor;
// void CNWSScriptVarTable::DeleteIndexCExoString&, unsigned long int
extern void * const CNWSScriptVarTable__DeleteIndex;
// public void CNWSScriptVarTable::DestroyFloatCExoString&
extern void * const CNWSScriptVarTable__DestroyFloat;
// public void CNWSScriptVarTable::DestroyIntCExoString&
extern void * const CNWSScriptVarTable__DestroyInt;
// public void CNWSScriptVarTable::DestroyLocationCExoString&
extern void * const CNWSScriptVarTable__DestroyLocation;
// public void CNWSScriptVarTable::DestroyObjectCExoString&
extern void * const CNWSScriptVarTable__DestroyObject;
// public void CNWSScriptVarTable::DestroyStringCExoString&
extern void * const CNWSScriptVarTable__DestroyString;
// public float CNWSScriptVarTable::GetFloatCExoString&
extern void * const CNWSScriptVarTable__GetFloat;
// public int CNWSScriptVarTable::GetIntCExoString&
extern void * const CNWSScriptVarTable__GetInt;
// public CScriptLocation CNWSScriptVarTable::GetLocationCExoString&
extern void * const CNWSScriptVarTable__GetLocation;
// public unsigned long int CNWSScriptVarTable::GetObjectCExoString&
extern void * const CNWSScriptVarTable__GetObject;
// public CExoString CNWSScriptVarTable::GetStringCExoString&
extern void * const CNWSScriptVarTable__GetString;
// public void CNWSScriptVarTable::LoadVarTableCResGFF*, CResStruct*
extern void * const CNWSScriptVarTable__LoadVarTable;
// private CNWSScriptVar* CNWSScriptVarTable::MatchIndexCExoString&, unsigned long int, int
extern void * const CNWSScriptVarTable__MatchIndex;
// public void CNWSScriptVarTable::SaveVarTableCResGFF*, CResStruct*
extern void * const CNWSScriptVarTable__SaveVarTable;
// public void CNWSScriptVarTable::SetFloatCExoString&, float
extern void * const CNWSScriptVarTable__SetFloat;
// public void CNWSScriptVarTable::SetIntCExoString&, int, int
extern void * const CNWSScriptVarTable__SetInt;
// public void CNWSScriptVarTable::SetLocationCExoString&, CScriptLocation
extern void * const CNWSScriptVarTable__SetLocation;
// public void CNWSScriptVarTable::SetObjectCExoString&, unsigned long int
extern void * const CNWSScriptVarTable__SetObject;
// public void CNWSScriptVarTable::SetStringCExoString&, CExoString&
extern void * const CNWSScriptVarTable__SetString;

// public CNWSSoundObject::CNWSSoundObjectunsigned long int
extern void * const CNWSSoundObject__CNWSSoundObjectCtor;
// public CNWSSoundObject::~CNWSSoundObjectvoid
extern void * const CNWSSoundObject__CNWSSoundObjectDtor;
// public void CNWSSoundObject::AddToAreaCNWSArea*, int
extern void * const CNWSSoundObject__AddToArea;
// public void CNWSSoundObject::AIUpdatevoid
extern void * const CNWSSoundObject__AIUpdate;
// public CNWSSoundObject* CNWSSoundObject::AsNWSSoundObjectvoid
extern void * const CNWSSoundObject__AsNWSSoundObject;
// public void CNWSSoundObject::ChangePositionVector
extern void * const CNWSSoundObject__ChangePosition;
// public void CNWSSoundObject::ChangeVolumeint
extern void * const CNWSSoundObject__ChangeVolume;
// public void CNWSSoundObject::EventHandlerunsigned long int, unsigned long int, void*, unsigned long int, unsigned long int
extern void * const CNWSSoundObject__EventHandler;
// void CNWSSoundObject::GetContinuousvoid
extern void * const CNWSSoundObject__GetContinuous;
// void CNWSSoundObject::GetHoursvoid
extern void * const CNWSSoundObject__GetHours;
// void CNWSSoundObject::GetIntervalvoid
extern void * const CNWSSoundObject__GetInterval;
// void CNWSSoundObject::GetIntervalVariancevoid
extern void * const CNWSSoundObject__GetIntervalVariance;
// void CNWSSoundObject::GetIsActivevoid
extern void * const CNWSSoundObject__GetIsActive;
// void CNWSSoundObject::GetLoopingvoid
extern void * const CNWSSoundObject__GetLooping;
// void CNWSSoundObject::GetMaxDistancevoid
extern void * const CNWSSoundObject__GetMaxDistance;
// void CNWSSoundObject::GetMinDistancevoid
extern void * const CNWSSoundObject__GetMinDistance;
// void CNWSSoundObject::GetPeopleInSoundRangevoid
extern void * const CNWSSoundObject__GetPeopleInSoundRange;
// void CNWSSoundObject::GetPitchVariationvoid
extern void * const CNWSSoundObject__GetPitchVariation;
// void CNWSSoundObject::GetPositionalvoid
extern void * const CNWSSoundObject__GetPositional;
// void CNWSSoundObject::GetPriorityvoid
extern void * const CNWSSoundObject__GetPriority;
// void CNWSSoundObject::GetRandomvoid
extern void * const CNWSSoundObject__GetRandom;
// void CNWSSoundObject::GetRandomPositionvoid
extern void * const CNWSSoundObject__GetRandomPosition;
// void CNWSSoundObject::GetRandomXRangevoid
extern void * const CNWSSoundObject__GetRandomXRange;
// void CNWSSoundObject::GetRandomYRangevoid
extern void * const CNWSSoundObject__GetRandomYRange;
// void CNWSSoundObject::GetSoundListvoid
extern void * const CNWSSoundObject__GetSoundList;
// void CNWSSoundObject::GetTimeofDayvoid
extern void * const CNWSSoundObject__GetTimeofDay;
// void CNWSSoundObject::GetVolumevoid
extern void * const CNWSSoundObject__GetVolume;
// void CNWSSoundObject::GetVolumeVariationvoid
extern void * const CNWSSoundObject__GetVolumeVariation;
// public int CNWSSoundObject::LoadCResGFF*, CResStruct*
extern void * const CNWSSoundObject__Load;
// public void CNWSSoundObject::PackIntoMessageCNWSMessage*
extern void * const CNWSSoundObject__PackIntoMessage;
// public void CNWSSoundObject::Playvoid
extern void * const CNWSSoundObject__Play;
// void CNWSSoundObject::RemoveFromAreavoid
extern void * const CNWSSoundObject__RemoveFromArea;
// public void CNWSSoundObject::SaveCResGFF*, CResStruct*
extern void * const CNWSSoundObject__Save;
// void CNWSSoundObject::SetContinuousint
extern void * const CNWSSoundObject__SetContinuous;
// void CNWSSoundObject::SetHoursunsigned long int
extern void * const CNWSSoundObject__SetHours;
// void CNWSSoundObject::SetIntervalunsigned long int
extern void * const CNWSSoundObject__SetInterval;
// void CNWSSoundObject::SetIntervalVarianceunsigned long int
extern void * const CNWSSoundObject__SetIntervalVariance;
// void CNWSSoundObject::SetIsActiveint
extern void * const CNWSSoundObject__SetIsActive;
// void CNWSSoundObject::SetLoopingint
extern void * const CNWSSoundObject__SetLooping;
// void CNWSSoundObject::SetMaxDistancefloat
extern void * const CNWSSoundObject__SetMaxDistance;
// void CNWSSoundObject::SetMinDistancefloat
extern void * const CNWSSoundObject__SetMinDistance;
// void CNWSSoundObject::SetPitchVariationfloat
extern void * const CNWSSoundObject__SetPitchVariation;
// void CNWSSoundObject::SetPositionalint
extern void * const CNWSSoundObject__SetPositional;
// void CNWSSoundObject::SetPriorityunsigned char
extern void * const CNWSSoundObject__SetPriority;
// void CNWSSoundObject::SetRandomint
extern void * const CNWSSoundObject__SetRandom;
// void CNWSSoundObject::SetRandomPositionint
extern void * const CNWSSoundObject__SetRandomPosition;
// void CNWSSoundObject::SetRandomXRangefloat
extern void * const CNWSSoundObject__SetRandomXRange;
// void CNWSSoundObject::SetRandomYRangefloat
extern void * const CNWSSoundObject__SetRandomYRange;
// void CNWSSoundObject::SetTimeofDayCNWSSoundObjectTimeOfDay
extern void * const CNWSSoundObject__SetTimeofDay;
// void CNWSSoundObject::SetVolumeint
extern void * const CNWSSoundObject__SetVolume;
// void CNWSSoundObject::SetVolumeVariationint
extern void * const CNWSSoundObject__SetVolumeVariation;
// public void CNWSSoundObject::Stopvoid
extern void * const CNWSSoundObject__Stop;

// public int CNWSSpellScriptData::LoadDataCResGFF*, CResStruct*
extern void * const CNWSSpellScriptData__LoadData;
// public int CNWSSpellScriptData::SaveDataCResGFF*, CResStruct*
extern void * const CNWSSpellScriptData__SaveData;

// public CNWSStats_Spell::CNWSStats_Spellvoid
extern void * const CNWSStats_Spell__CNWSStats_SpellCtor;

// public CNWSStats_SpellLikeAbility::CNWSStats_SpellLikeAbilityvoid
extern void * const CNWSStats_SpellLikeAbility__CNWSStats_SpellLikeAbilityCtor;

// public CNWSStore::CNWSStoreunsigned long int
extern void * const CNWSStore__CNWSStoreCtor;
// public CNWSStore::~CNWSStorevoid
extern void * const CNWSStore__CNWSStoreDtor;
// public int CNWSStore::AcquireItemCNWSItem*, int, unsigned char, unsigned char
extern void * const CNWSStore__AcquireItem;
// public void CNWSStore::AddCustomerCNWSPlayer*, char, char
extern void * const CNWSStore__AddCustomer;
// void CNWSStore::AddGoldint
extern void * const CNWSStore__AddGold;
// protected int CNWSStore::AddItemToInventoryCNWSItem**, unsigned char, unsigned char, unsigned char
extern void * const CNWSStore__AddItemToInventory;
// public void CNWSStore::AddToAreaCNWSArea*, float, float, float, int
extern void * const CNWSStore__AddToArea;
// public void CNWSStore::AIUpdatevoid
extern void * const CNWSStore__AIUpdate;
// public CNWSStore* CNWSStore::AsNWSStorevoid
extern void * const CNWSStore__AsNWSStore;
// public int CNWSStore::CalculateItemBuyPriceCNWSItem*, unsigned long int
extern void * const CNWSStore__CalculateItemBuyPrice;
// public int CNWSStore::CalculateItemSellPriceCNWSItem*, unsigned long int
extern void * const CNWSStore__CalculateItemSellPrice;
// public void CNWSStore::EventHandlerunsigned long int, unsigned long int, void*, unsigned long int, unsigned long int
extern void * const CNWSStore__EventHandler;
// void CNWSStore::GetAppropriateListIdunsigned long int
extern void * const CNWSStore__GetAppropriateListId;
// void CNWSStore::GetBlackMarketvoid
extern void * const CNWSStore__GetBlackMarket;
// void CNWSStore::GetBlackMarketMarkDownvoid
extern void * const CNWSStore__GetBlackMarketMarkDown;
// void CNWSStore::GetCustomerunsigned long int
extern void * const CNWSStore__GetCustomer;
// public unsigned char CNWSStore::GetCustomerBuyRateunsigned long int, int
extern void * const CNWSStore__GetCustomerBuyRate;
// public short int CNWSStore::GetCustomerSellRateunsigned long int
extern void * const CNWSStore__GetCustomerSellRate;
// void CNWSStore::GetGoldvoid
extern void * const CNWSStore__GetGold;
// void CNWSStore::GetIdentifyCostvoid
extern void * const CNWSStore__GetIdentifyCost;
// public int CNWSStore::GetIsRestrictedBuyItemint
extern void * const CNWSStore__GetIsRestrictedBuyItem;
// public int CNWSStore::GetItemInInventoryunsigned long int
extern void * const CNWSStore__GetItemInInventory__0;
// public int CNWSStore::GetItemInInventoryCExoString*
extern void * const CNWSStore__GetItemInInventory__1;
// void CNWSStore::GetLastClosedvoid
extern void * const CNWSStore__GetLastClosed;
// void CNWSStore::GetLastOpenedvoid
extern void * const CNWSStore__GetLastOpened;
// void CNWSStore::GetMarkDownvoid
extern void * const CNWSStore__GetMarkDown;
// void CNWSStore::GetMarkUpvoid
extern void * const CNWSStore__GetMarkUp;
// void CNWSStore::GetMaxBuyPricevoid
extern void * const CNWSStore__GetMaxBuyPrice;
// public CExoLocString CNWSStore::GetNamevoid
extern void * const CNWSStore__GetName;
// void CNWSStore::GetRepositoryunsigned char
extern void * const CNWSStore__GetRepository;
// void CNWSStore::GetRepositoryArrayIndexvoid
extern void * const CNWSStore__GetRepositoryArrayIndex;
// void CNWSStore::GetRepositoryListNumbervoid
extern void * const CNWSStore__GetRepositoryListNumber;
// void CNWSStore::GetScriptNameint
extern void * const CNWSStore__GetScriptName;
// void CNWSStore::GetWillNotBuyItemint
extern void * const CNWSStore__GetWillNotBuyItem;
// void CNWSStore::GetWillNotBuyListSizevoid
extern void * const CNWSStore__GetWillNotBuyListSize;
// void CNWSStore::GetWillOnlyBuyItemint
extern void * const CNWSStore__GetWillOnlyBuyItem;
// void CNWSStore::GetWillOnlyBuyListSizevoid
extern void * const CNWSStore__GetWillOnlyBuyListSize;
// public int CNWSStore::LoadFromTemplateCResRef, CExoString*
extern void * const CNWSStore__LoadFromTemplate;
// public int CNWSStore::LoadStoreCResGFF*, CResStruct*, CExoString*
extern void * const CNWSStore__LoadStore;
// public void CNWSStore::RemoveCustomerCNWSPlayer*
extern void * const CNWSStore__RemoveCustomer;
// void CNWSStore::RemoveFromAreavoid
extern void * const CNWSStore__RemoveFromArea;
// void CNWSStore::RemoveGoldint
extern void * const CNWSStore__RemoveGold;
// public void CNWSStore::RemoveItemCNWSItem*
extern void * const CNWSStore__RemoveItem;
// protected int CNWSStore::RemoveItemFromInventoryCNWSItem*, unsigned char
extern void * const CNWSStore__RemoveItemFromInventory;
// public int CNWSStore::SaveStoreCResGFF*, CResStruct*
extern void * const CNWSStore__SaveStore;
// public int CNWSStore::SellItemCNWSItem*, CNWSCreature*, unsigned char, unsigned char
extern void * const CNWSStore__SellItem;
// void CNWSStore::SetBlackMarketint
extern void * const CNWSStore__SetBlackMarket;
// void CNWSStore::SetBlackMarketMarkDownint
extern void * const CNWSStore__SetBlackMarketMarkDown;
// void CNWSStore::SetGoldint
extern void * const CNWSStore__SetGold;
// void CNWSStore::SetIdentifyCostint
extern void * const CNWSStore__SetIdentifyCost;
// void CNWSStore::SetLastClosedunsigned long int
extern void * const CNWSStore__SetLastClosed;
// void CNWSStore::SetLastOpenedunsigned long int
extern void * const CNWSStore__SetLastOpened;
// void CNWSStore::SetMarkDownint
extern void * const CNWSStore__SetMarkDown;
// void CNWSStore::SetMarkUpint
extern void * const CNWSStore__SetMarkUp;
// void CNWSStore::SetMaxBuyPriceint
extern void * const CNWSStore__SetMaxBuyPrice;
// public void CNWSStore::SetNameCExoLocString
extern void * const CNWSStore__SetName;
// void CNWSStore::SetRepositoryArrayIndexunsigned short int
extern void * const CNWSStore__SetRepositoryArrayIndex;
// void CNWSStore::SetRepositoryListNumberunsigned char
extern void * const CNWSStore__SetRepositoryListNumber;
// public void CNWSStore::SetScriptNameint, CExoString
extern void * const CNWSStore__SetScriptName;

// public CNWSSysAdmin::CNWSSysAdminunsigned long int
extern void * const CNWSSysAdmin__CNWSSysAdminCtor;
// public CNWSSysAdmin::~CNWSSysAdminvoid
extern void * const CNWSSysAdmin__CNWSSysAdminDtor;
// public CNWSSysAdmin* CNWSSysAdmin::AsNWSSysAdminvoid
extern void * const CNWSSysAdmin__AsNWSSysAdmin;

// public CNWSTile::CNWSTilevoid
extern void * const CNWSTile__CNWSTileCtor;
// public CNWSTile::~CNWSTilevoid
extern void * const CNWSTile__CNWSTileDtor;
// void CNWSTile::AddDoorunsigned long int
extern void * const CNWSTile__AddDoor;
// public void CNWSTile::AddTriggerunsigned long int
extern void * const CNWSTile__AddTrigger;
// public int CNWSTile::ClearLineOfSightint, Vector, Vector, Vector*
extern void * const CNWSTile__ClearLineOfSight;
// public int CNWSTile::ClippedLineSegmentWalkablefloat, float, float, float, float*, float*, float*, float*, float*, float*
extern void * const CNWSTile__ClippedLineSegmentWalkable;
// public int CNWSTile::ComputeClippedLineSegmentVector, Vector, Vector*, Vector*
extern void * const CNWSTile__ComputeClippedLineSegment;
// public float CNWSTile::ComputeHeightVector
extern void * const CNWSTile__ComputeHeight;
// public int CNWSTile::FindClosestRegionfloat, float
extern void * const CNWSTile__FindClosestRegion;
// void CNWSTile::GetDoorsListvoid
extern void * const CNWSTile__GetDoorsList;
// public int CNWSTile::GetExitint, float*, float*, int*
extern void * const CNWSTile__GetExit;
// public int CNWSTile::GetExitNumberfloat, float
extern void * const CNWSTile__GetExitNumber;
// void CNWSTile::GetFlaggedAsProblemvoid
extern void * const CNWSTile__GetFlaggedAsProblem;
// void CNWSTile::GetHasPlaceableWithWalkMeshvoid
extern void * const CNWSTile__GetHasPlaceableWithWalkMesh;
// void CNWSTile::GetMainLightColorChangevoid
extern void * const CNWSTile__GetMainLightColorChange;
// void CNWSTile::GetNumTriggersvoid
extern void * const CNWSTile__GetNumTriggers;
// public int CNWSTile::GetRegionCoordsint, float*, float*
extern void * const CNWSTile__GetRegionCoords;
// public int CNWSTile::GetRegionEntrancefloat, float
extern void * const CNWSTile__GetRegionEntrance;
// void CNWSTile::GetSourceLightColorChangevoid
extern void * const CNWSTile__GetSourceLightColorChange;
// public int CNWSTile::GetSurfaceMaterialVector
extern void * const CNWSTile__GetSurfaceMaterial;
// public CNWTileData* CNWSTile::GetTileDatavoid
extern void * const CNWSTile__GetTileData;
// public int CNWSTile::GetTotalExitsvoid
extern void * const CNWSTile__GetTotalExits;
// void CNWSTile::GetTriggerDatavoid
extern void * const CNWSTile__GetTriggerData;
// void CNWSTile::GetWalkMeshvoid
extern void * const CNWSTile__GetWalkMesh;
// void CNWSTile::IntersectLineSegmentsfloat, float, float, float, float, float, float, float, float*, float*
extern void * const CNWSTile__IntersectLineSegments;
// void CNWSTile::InTriggerVector, CExoArrayListTemplatedunsignedlong*
extern void * const CNWSTile__InTrigger;
// void CNWSTile::LoadWalkMeshvoid
extern void * const CNWSTile__LoadWalkMesh;
// public int CNWSTile::NoNonWalkPolysOnTilefloat, float, float, float, float, float, float
extern void * const CNWSTile__NoNonWalkPolysOnTile;
// public unsigned long int CNWSTile::PlotIntraTilePathCNWArea*, CPathfindInformation*, float, float, float, float, unsigned long int
extern void * const CNWSTile__PlotIntraTilePath;
// void CNWSTile::RemoveDoorunsigned long int
extern void * const CNWSTile__RemoveDoor;
// void CNWSTile::SetFlaggedAsProblemvoid
extern void * const CNWSTile__SetFlaggedAsProblem;
// void CNWSTile::SetHasPlaceableWithWalkMeshvoid
extern void * const CNWSTile__SetHasPlaceableWithWalkMesh;
// public void CNWSTile::SetMainLightColorunsigned char, unsigned char
extern void * const CNWSTile__SetMainLightColor;
// void CNWSTile::SetMainLightColorChangeint
extern void * const CNWSTile__SetMainLightColorChange;
// public void CNWSTile::SetSourceLightColorunsigned char, unsigned char
extern void * const CNWSTile__SetSourceLightColor;
// void CNWSTile::SetSourceLightColorChangeint
extern void * const CNWSTile__SetSourceLightColorChange;
// public void CNWSTile::SetTileDataCNWTileData*
extern void * const CNWSTile__SetTileData;

// public CNWSTrigger::CNWSTriggerunsigned long int
extern void * const CNWSTrigger__CNWSTriggerCtor;
// public CNWSTrigger::~CNWSTriggervoid
extern void * const CNWSTrigger__CNWSTriggerDtor;
// public void CNWSTrigger::AddToAreaCNWSArea*, float, float, float, int
extern void * const CNWSTrigger__AddToArea;
// public void CNWSTrigger::AIUpdatevoid
extern void * const CNWSTrigger__AIUpdate;
// public CNWSTrigger* CNWSTrigger::AsNWSTriggervoid
extern void * const CNWSTrigger__AsNWSTrigger;
// public int CNWSTrigger::CalculateNearestPointVector, Vector*
extern void * const CNWSTrigger__CalculateNearestPoint;
// public void CNWSTrigger::ComputeBoundingBoxfloat*, float*, float*, float*
extern void * const CNWSTrigger__ComputeBoundingBox;
// public void CNWSTrigger::CreateNewGeometryfloat, Vector, CNWSArea*
extern void * const CNWSTrigger__CreateNewGeometry__0;
// public void CNWSTrigger::CreateNewGeometryfloat, CScriptLocation*, CNWSArea*
extern void * const CNWSTrigger__CreateNewGeometry__1;
// public void CNWSTrigger::EventHandlerunsigned long int, unsigned long int, void*, unsigned long int, unsigned long int
extern void * const CNWSTrigger__EventHandler;
// void CNWSTrigger::GetActivevoid
extern void * const CNWSTrigger__GetActive;
// void CNWSTrigger::GetAutoRemoveKeyvoid
extern void * const CNWSTrigger__GetAutoRemoveKey;
// void CNWSTrigger::GetBaseTypevoid
extern void * const CNWSTrigger__GetBaseType;
// public int CNWSTrigger::GetCanFireTrapOnObjectunsigned long int, int
extern void * const CNWSTrigger__GetCanFireTrapOnObject;
// public int CNWSTrigger::GetClosestPointWithinTriggerVector, Vector*
extern void * const CNWSTrigger__GetClosestPointWithinTrigger;
// void CNWSTrigger::GetCreatorvoid
extern void * const CNWSTrigger__GetCreator;
// void CNWSTrigger::GetCreatureListvoid
extern void * const CNWSTrigger__GetCreatureList;
// void CNWSTrigger::GetCursorvoid
extern void * const CNWSTrigger__GetCursor;
// void CNWSTrigger::GetCustomScriptEventIdvoid
extern void * const CNWSTrigger__GetCustomScriptEventId;
// public CExoString CNWSTrigger::GetDescriptionOverridevoid
extern void * const CNWSTrigger__GetDescriptionOverride;
// void CNWSTrigger::GetDetectablevoid
extern void * const CNWSTrigger__GetDetectable;
// void CNWSTrigger::GetDetectDCvoid
extern void * const CNWSTrigger__GetDetectDC;
// void CNWSTrigger::GetDisarmablevoid
extern void * const CNWSTrigger__GetDisarmable;
// void CNWSTrigger::GetDisarmDCvoid
extern void * const CNWSTrigger__GetDisarmDC;
// public Vector CNWSTrigger::GetFacingPositionvoid
extern void * const CNWSTrigger__GetFacingPosition;
// void CNWSTrigger::GetFactionIdvoid
extern void * const CNWSTrigger__GetFactionId;
// public CExoLocString& CNWSTrigger::GetFirstNamevoid
extern void * const CNWSTrigger__GetFirstName;
// void CNWSTrigger::GetFlaggedvoid
extern void * const CNWSTrigger__GetFlagged;
// void CNWSTrigger::GetIsAreaTransitionvoid
extern void * const CNWSTrigger__GetIsAreaTransition;
// void CNWSTrigger::GetIsTrapvoid
extern void * const CNWSTrigger__GetIsTrap;
// void CNWSTrigger::GetKeyNamevoid
extern void * const CNWSTrigger__GetKeyName;
// void CNWSTrigger::GetLastDisarmedvoid
extern void * const CNWSTrigger__GetLastDisarmed;
// void CNWSTrigger::GetLastEnteredvoid
extern void * const CNWSTrigger__GetLastEntered;
// void CNWSTrigger::GetLastLeftvoid
extern void * const CNWSTrigger__GetLastLeft;
// void CNWSTrigger::GetLinkedFlagsvoid
extern void * const CNWSTrigger__GetLinkedFlags;
// public CExoString CNWSTrigger::GetLinkedTovoid
extern void * const CNWSTrigger__GetLinkedTo;
// public unsigned short int CNWSTrigger::GetLoadScreenIDvoid
extern void * const CNWSTrigger__GetLoadScreenID;
// void CNWSTrigger::GetNumVerticesvoid
extern void * const CNWSTrigger__GetNumVertices;
// void CNWSTrigger::GetObjectArrayIndexvoid
extern void * const CNWSTrigger__GetObjectArrayIndex;
// void CNWSTrigger::GetOneShotvoid
extern void * const CNWSTrigger__GetOneShot;
// void CNWSTrigger::GetRecoverablevoid
extern void * const CNWSTrigger__GetRecoverable;
// public CExoString* CNWSTrigger::GetScriptNameint
extern void * const CNWSTrigger__GetScriptName;
// public unsigned long int CNWSTrigger::GetTargetAreavoid
extern void * const CNWSTrigger__GetTargetArea;
// void CNWSTrigger::GetTriggerHeightvoid
extern void * const CNWSTrigger__GetTriggerHeight;
// void CNWSTrigger::GetVerticesvoid
extern void * const CNWSTrigger__GetVertices;
// public int CNWSTrigger::InTriggerVector
extern void * const CNWSTrigger__InTrigger;
// public int CNWSTrigger::LineSegmentIntersectTriggerVector, Vector
extern void * const CNWSTrigger__LineSegmentIntersectTrigger;
// public int CNWSTrigger::LoadFromTemplateCResRef
extern void * const CNWSTrigger__LoadFromTemplate;
// public int CNWSTrigger::LoadTriggerCResGFF*, CResStruct*
extern void * const CNWSTrigger__LoadTrigger;
// public void CNWSTrigger::OnEnterTrapint
extern void * const CNWSTrigger__OnEnterTrap;
// public void CNWSTrigger::RemoveFromAreavoid
extern void * const CNWSTrigger__RemoveFromArea;
// public int CNWSTrigger::SaveTriggerCResGFF*, CResStruct*
extern void * const CNWSTrigger__SaveTrigger;
// void CNWSTrigger::SetActiveint
extern void * const CNWSTrigger__SetActive;
// void CNWSTrigger::SetAutoRemoveKeyint
extern void * const CNWSTrigger__SetAutoRemoveKey;
// void CNWSTrigger::SetBaseTypeunsigned char
extern void * const CNWSTrigger__SetBaseType;
// void CNWSTrigger::SetCreatorunsigned long int
extern void * const CNWSTrigger__SetCreator;
// void CNWSTrigger::SetCursorunsigned char
extern void * const CNWSTrigger__SetCursor;
// void CNWSTrigger::SetCustomScriptEventIdint
extern void * const CNWSTrigger__SetCustomScriptEventId;
// public void CNWSTrigger::SetDescriptionOverrideCExoString
extern void * const CNWSTrigger__SetDescriptionOverride;
// void CNWSTrigger::SetDetectableint
extern void * const CNWSTrigger__SetDetectable;
// void CNWSTrigger::SetDetectDCint
extern void * const CNWSTrigger__SetDetectDC;
// void CNWSTrigger::SetDisarmableint
extern void * const CNWSTrigger__SetDisarmable;
// void CNWSTrigger::SetDisarmDCint
extern void * const CNWSTrigger__SetDisarmDC;
// void CNWSTrigger::SetFactionIdint
extern void * const CNWSTrigger__SetFactionId;
// void CNWSTrigger::SetFirstNameunsigned long int
extern void * const CNWSTrigger__SetFirstName;
// void CNWSTrigger::SetFlaggedint
extern void * const CNWSTrigger__SetFlagged;
// void CNWSTrigger::SetIsAreaTransitionint
extern void * const CNWSTrigger__SetIsAreaTransition;
// void CNWSTrigger::SetIsTrapint
extern void * const CNWSTrigger__SetIsTrap;
// void CNWSTrigger::SetKeyNameconst CExoString&
extern void * const CNWSTrigger__SetKeyName;
// void CNWSTrigger::SetLastDisarmedunsigned long int
extern void * const CNWSTrigger__SetLastDisarmed;
// void CNWSTrigger::SetLastEnteredunsigned long int
extern void * const CNWSTrigger__SetLastEntered;
// void CNWSTrigger::SetLastLeftunsigned long int
extern void * const CNWSTrigger__SetLastLeft;
// void CNWSTrigger::SetLinkedFlagsunsigned char
extern void * const CNWSTrigger__SetLinkedFlags;
// void CNWSTrigger::SetLinkedToCExoString
extern void * const CNWSTrigger__SetLinkedTo;
// void CNWSTrigger::SetObjectArrayIndexunsigned short int
extern void * const CNWSTrigger__SetObjectArrayIndex;
// void CNWSTrigger::SetOneShotunsigned char
extern void * const CNWSTrigger__SetOneShot;
// void CNWSTrigger::SetRecoverableint
extern void * const CNWSTrigger__SetRecoverable;
// public void CNWSTrigger::SetScriptNameint, CExoString
extern void * const CNWSTrigger__SetScriptName;
// void CNWSTrigger::SetTriggerHeightfloat
extern void * const CNWSTrigger__SetTriggerHeight;

// public CNWSWaypoint::CNWSWaypointunsigned long int
extern void * const CNWSWaypoint__CNWSWaypointCtor;
// public CNWSWaypoint::~CNWSWaypointvoid
extern void * const CNWSWaypoint__CNWSWaypointDtor;
// public void CNWSWaypoint::AddToAreaCNWSArea*, float, float, float, int
extern void * const CNWSWaypoint__AddToArea;
// public void CNWSWaypoint::AIUpdatevoid
extern void * const CNWSWaypoint__AIUpdate;
// public CNWSWaypoint* CNWSWaypoint::AsNWSWaypointvoid
extern void * const CNWSWaypoint__AsNWSWaypoint;
// public void CNWSWaypoint::EventHandlerunsigned long int, unsigned long int, void*, unsigned long int, unsigned long int
extern void * const CNWSWaypoint__EventHandler;
// public CExoLocString& CNWSWaypoint::GetFirstNamevoid
extern void * const CNWSWaypoint__GetFirstName;
// void CNWSWaypoint::GetIsMapNotevoid
extern void * const CNWSWaypoint__GetIsMapNote;
// void CNWSWaypoint::GetMapNoteEnabledvoid
extern void * const CNWSWaypoint__GetMapNoteEnabled;
// public CExoLocString& CNWSWaypoint::GetMapNoteStringvoid
extern void * const CNWSWaypoint__GetMapNoteString;
// public int CNWSWaypoint::LoadFromTemplateCResRef, CExoString*
extern void * const CNWSWaypoint__LoadFromTemplate;
// public int CNWSWaypoint::LoadWaypointCResGFF*, CResStruct*, CExoString*
extern void * const CNWSWaypoint__LoadWaypoint;
// void CNWSWaypoint::RemoveFromAreavoid
extern void * const CNWSWaypoint__RemoveFromArea;
// public int CNWSWaypoint::SaveWaypointCResGFF*, CResStruct*
extern void * const CNWSWaypoint__SaveWaypoint;
// void CNWSWaypoint::SetIsMapNoteint
extern void * const CNWSWaypoint__SetIsMapNote;
// void CNWSWaypoint::SetMapNoteEnabledint
extern void * const CNWSWaypoint__SetMapNoteEnabled;
// void CNWSWaypoint::SetMapNoteStringCExoLocString
extern void * const CNWSWaypoint__SetMapNoteString;

// public CNWTile::CNWTilevoid
extern void * const CNWTile__CNWTileCtor;
// public CNWTile::~CNWTilevoid
extern void * const CNWTile__CNWTileDtor;
// public void CNWTile::GetAnimLoopunsigned char*, unsigned char*, unsigned char*
extern void * const CNWTile__GetAnimLoop;
// void CNWTile::GetHeightvoid
extern void * const CNWTile__GetHeight;
// void CNWTile::GetIDvoid
extern void * const CNWTile__GetID;
// public void CNWTile::GetLocationint*, int*
extern void * const CNWTile__GetLocation;
// public void CNWTile::GetMainLightColorunsigned char*, unsigned char*
extern void * const CNWTile__GetMainLightColor;
// void CNWTile::GetModelPositionvoid
extern void * const CNWTile__GetModelPosition;
// void CNWTile::GetOrientationvoid
extern void * const CNWTile__GetOrientation;
// void CNWTile::GetReplaceTexturevoid
extern void * const CNWTile__GetReplaceTexture;
// public void CNWTile::GetSourceLightColorunsigned char*, unsigned char*
extern void * const CNWTile__GetSourceLightColor;
// public void CNWTile::RotateCanonicalToRealfloat, float, float*, float*
extern void * const CNWTile__RotateCanonicalToReal;
// public void CNWTile::RotateCanonicalToRealTilefloat, float, float*, float*
extern void * const CNWTile__RotateCanonicalToRealTile;
// public void CNWTile::RotateRealToCanonicalfloat, float, float*, float*
extern void * const CNWTile__RotateRealToCanonical;
// public void CNWTile::RotateRealToCanonicalTilefloat, float, float*, float*
extern void * const CNWTile__RotateRealToCanonicalTile;
// public void CNWTile::SetAnimLoopunsigned char, unsigned char, unsigned char
extern void * const CNWTile__SetAnimLoop;
// public void CNWTile::SetIDint
extern void * const CNWTile__SetID;
// public void CNWTile::SetMainLightColorunsigned char, unsigned char
extern void * const CNWTile__SetMainLightColor;
// public void CNWTile::SetOrientationint
extern void * const CNWTile__SetOrientation;
// public void CNWTile::SetPositionint, int, int, float
extern void * const CNWTile__SetPosition;
// public void CNWTile::SetReplaceTextureunsigned char
extern void * const CNWTile__SetReplaceTexture;
// public void CNWTile::SetSourceLightColorunsigned char, unsigned char
extern void * const CNWTile__SetSourceLightColor;

// public CNWTileData::CNWTileDatavoid
extern void * const CNWTileData__CNWTileDataCtor;
// public CNWTileData::~CNWTileDatavoid
extern void * const CNWTileData__CNWTileDataDtor;
// void CNWTileData::AddPropertyMethodStringunsigned long int, CExoString
extern void * const CNWTileData__AddPropertyMethodString;
// void CNWTileData::GetCornerTypeunsigned char
extern void * const CNWTileData__GetCornerType;
// void CNWTileData::GetEdgeTypeunsigned char
extern void * const CNWTileData__GetEdgeType;
// void CNWTileData::GetMapIconvoid
extern void * const CNWTileData__GetMapIcon;
// void CNWTileData::GetModelResRefvoid
extern void * const CNWTileData__GetModelResRef;
// void CNWTileData::GetNumDoorsvoid
extern void * const CNWTileData__GetNumDoors;
// void CNWTileData::GetPropertyMethodStringListunsigned long int
extern void * const CNWTileData__GetPropertyMethodStringList;
// public CNWTileSurfaceMesh* CNWTileData::GetSurfaceMeshvoid
extern void * const CNWTileData__GetSurfaceMesh;
// public void CNWTileData::SetCornerTypeunsigned char, CExoString, int
extern void * const CNWTileData__SetCornerType;
// public void CNWTileData::SetEdgeTypeunsigned char, CExoString
extern void * const CNWTileData__SetEdgeType;
// public void CNWTileData::SetMapIconCResRef
extern void * const CNWTileData__SetMapIcon;
// public void CNWTileData::SetModelResRefCResRef
extern void * const CNWTileData__SetModelResRef;
// void CNWTileData::SetNumDoorsunsigned char
extern void * const CNWTileData__SetNumDoors;

// public CNWTileSet::CNWTileSetCResRef, int
extern void * const CNWTileSet__CNWTileSetCtor;
// public CNWTileSet::~CNWTileSetvoid
extern void * const CNWTileSet__CNWTileSetDtor;
// void CNWTileSet::GetCornerTypeint, unsigned char, unsigned char
extern void * const CNWTileSet__GetCornerType;
// void CNWTileSet::GetEdgeTypeint, unsigned char, unsigned char
extern void * const CNWTileSet__GetEdgeType;
// void CNWTileSet::GetEnvMapResRefvoid
extern void * const CNWTileSet__GetEnvMapResRef;
// void CNWTileSet::GetGrassAmbientColorvoid
extern void * const CNWTileSet__GetGrassAmbientColor;
// void CNWTileSet::GetGrassDensityvoid
extern void * const CNWTileSet__GetGrassDensity;
// void CNWTileSet::GetGrassDiffuseColorvoid
extern void * const CNWTileSet__GetGrassDiffuseColor;
// void CNWTileSet::GetGrassHeightvoid
extern void * const CNWTileSet__GetGrassHeight;
// void CNWTileSet::GetGrassTexturevoid
extern void * const CNWTileSet__GetGrassTexture;
// void CNWTileSet::GetHasGrassvoid
extern void * const CNWTileSet__GetHasGrass;
// public float CNWTileSet::GetHeightTransitionvoid
extern void * const CNWTileSet__GetHeightTransition;
// public CNWTileData* CNWTileSet::GetTileDataint
extern void * const CNWTileSet__GetTileData;
// void CNWTileSet::GetTileSetNamevoid
extern void * const CNWTileSet__GetTileSetName;
// public int CNWTileSet::LoadTileSetvoid
extern void * const CNWTileSet__LoadTileSet;
// void CNWTileSet::ParseLinechar*
extern void * const CNWTileSet__ParseLine;
// void CNWTileSet::SetTileValuechar*, char*
extern void * const CNWTileSet__SetTileValue;
// void CNWTileSet::UnloadTileSetvoid
extern void * const CNWTileSet__UnloadTileSet;

// public CNWTileSetManager::CNWTileSetManagervoid
extern void * const CNWTileSetManager__CNWTileSetManagerCtor;
// public CNWTileSetManager::~CNWTileSetManagervoid
extern void * const CNWTileSetManager__CNWTileSetManagerDtor;
// public void CNWTileSetManager::ClearTilePathNodesvoid
extern void * const CNWTileSetManager__ClearTilePathNodes;
// public void CNWTileSetManager::ComputePathNodeInformationunsigned char, int, int&, int&, float**, float**, int**
extern void * const CNWTileSetManager__ComputePathNodeInformation;
// void CNWTileSetManager::ComputePathNodeRotationint, float*, float*
extern void * const CNWTileSetManager__ComputePathNodeRotation;
// public CNWTilePathNode* CNWTileSetManager::GetTilePathNodeunsigned char, unsigned char
extern void * const CNWTileSetManager__GetTilePathNode;
// void CNWTileSetManager::InitializeTilePathNodesvoid
extern void * const CNWTileSetManager__InitializeTilePathNodes;
// public CNWTileSet* CNWTileSetManager::RegisterTileSetCResRef
extern void * const CNWTileSetManager__RegisterTileSet;
// public void CNWTileSetManager::UnregisterTileSetCNWTileSet*
extern void * const CNWTileSetManager__UnregisterTileSet;

// public CNWTileSurfaceMesh::CNWTileSurfaceMeshvoid
extern void * const CNWTileSurfaceMesh__CNWTileSurfaceMeshCtor;
// public CNWTileSurfaceMesh::~CNWTileSurfaceMeshvoid
extern void * const CNWTileSurfaceMesh__CNWTileSurfaceMeshDtor;
// public int CNWTileSurfaceMesh::CheckAABBNodeint, CNWTileSurfaceMeshAABBNode*, const Vector&, Vector&
extern void * const CNWTileSurfaceMesh__CheckAABBNode;
// void CNWTileSurfaceMesh::CheckAABBNodeOneWayint, CNWTileSurfaceMeshAABBNode*, const Vector&, Vector&
extern void * const CNWTileSurfaceMesh__CheckAABBNodeOneWay;
// public int CNWTileSurfaceMesh::ClearLineOfSightint, Vector, Vector, Vector*
extern void * const CNWTileSurfaceMesh__ClearLineOfSight;
// void CNWTileSurfaceMesh::ClearLineOfSightOneWayint, Vector, Vector, Vector*
extern void * const CNWTileSurfaceMesh__ClearLineOfSightOneWay;
// public void CNWTileSurfaceMesh::ClearSubdivisionvoid
extern void * const CNWTileSurfaceMesh__ClearSubdivision;
// public int CNWTileSurfaceMesh::ClippedLineSegmentWalkableCNWTile*, float, float, float, float, float*, float*, float*, float*, float*, float*
extern void * const CNWTileSurfaceMesh__ClippedLineSegmentWalkable;
// public int CNWTileSurfaceMesh::ComputeClippedLineSegmentCNWTile*, float, float, float, float, float*, float*, float*, float*
extern void * const CNWTileSurfaceMesh__ComputeClippedLineSegment;
// public float CNWTileSurfaceMesh::ComputeHeightVector
extern void * const CNWTileSurfaceMesh__ComputeHeight;
// public void CNWTileSurfaceMesh::ComputePathNodesvoid
extern void * const CNWTileSurfaceMesh__ComputePathNodes;
// public void CNWTileSurfaceMesh::ComputeTriangleAdjacencyvoid
extern void * const CNWTileSurfaceMesh__ComputeTriangleAdjacency;
// protected unsigned char CNWTileSurfaceMesh::ConvertToTileOrientationint
extern void * const CNWTileSurfaceMesh__ConvertToTileOrientation;
// void CNWTileSurfaceMesh::EstimateDistanceToTargetfloat, float
extern void * const CNWTileSurfaceMesh__EstimateDistanceToTarget;
// public int CNWTileSurfaceMesh::FindClosestRegionCNWTile*, float, float, unsigned char, int
extern void * const CNWTileSurfaceMesh__FindClosestRegion;
// public int CNWTileSurfaceMesh::FindRegionViaTriangleint, int, int*, int*
extern void * const CNWTileSurfaceMesh__FindRegionViaTriangle;
// public int CNWTileSurfaceMesh::FindTriangleint, int, float, float, int
extern void * const CNWTileSurfaceMesh__FindTriangle;
// public int CNWTileSurfaceMesh::GenerateBestIntraTileExitCNWTile*, CNWArea*, CPathfindInformation*, float, float
extern void * const CNWTileSurfaceMesh__GenerateBestIntraTileExit;
// void CNWTileSurfaceMesh::GetDoorVisNodevoid
extern void * const CNWTileSurfaceMesh__GetDoorVisNode;
// void CNWTileSurfaceMesh::GetDoorVisNodeOrientationvoid
extern void * const CNWTileSurfaceMesh__GetDoorVisNodeOrientation;
// public int CNWTileSurfaceMesh::GetExitint, float*, float*, int*
extern void * const CNWTileSurfaceMesh__GetExit;
// public int CNWTileSurfaceMesh::GetExitNumberfloat, float
extern void * const CNWTileSurfaceMesh__GetExitNumber;
// public int* CNWTileSurfaceMesh::GetLOSMaterialsvoid
extern void * const CNWTileSurfaceMesh__GetLOSMaterials;
// void CNWTileSurfaceMesh::GetNumTrianglesvoid
extern void * const CNWTileSurfaceMesh__GetNumTriangles;
// public unsigned char CNWTileSurfaceMesh::GetPathNodevoid
extern void * const CNWTileSurfaceMesh__GetPathNode;
// public int CNWTileSurfaceMesh::GetPathNodeOrientationvoid
extern void * const CNWTileSurfaceMesh__GetPathNodeOrientation;
// public int CNWTileSurfaceMesh::GetRegionCoordsint, float*, float*, unsigned char, int
extern void * const CNWTileSurfaceMesh__GetRegionCoords;
// public int CNWTileSurfaceMesh::GetRegionEntrancefloat, float, unsigned char, int
extern void * const CNWTileSurfaceMesh__GetRegionEntrance;
// public int CNWTileSurfaceMesh::GetSurfaceMaterialVector
extern void * const CNWTileSurfaceMesh__GetSurfaceMaterial;
// void CNWTileSurfaceMesh::GetTopLevelVertexGeometryint, float*, float*, float*
extern void * const CNWTileSurfaceMesh__GetTopLevelVertexGeometry;
// public int CNWTileSurfaceMesh::GetTotalExitsvoid
extern void * const CNWTileSurfaceMesh__GetTotalExits;
// public void CNWTileSurfaceMesh::GetTriangleAdjacencyint, int, int*, int*, int*
extern void * const CNWTileSurfaceMesh__GetTriangleAdjacency;
// public void CNWTileSurfaceMesh::GetTriangleCentroidint, float*, float*, float*
extern void * const CNWTileSurfaceMesh__GetTriangleCentroid;
// public void CNWTileSurfaceMesh::GetTriangleVerticesint, int, int*, int*, int*
extern void * const CNWTileSurfaceMesh__GetTriangleVertices;
// void CNWTileSurfaceMesh::GetVertexGeometryint, float*, float*, float*
extern void * const CNWTileSurfaceMesh__GetVertexGeometry__0;
// void CNWTileSurfaceMesh::GetVertexGeometryint, Vector*
extern void * const CNWTileSurfaceMesh__GetVertexGeometry__1;
// void CNWTileSurfaceMesh::GetVisibilityNodevoid
extern void * const CNWTileSurfaceMesh__GetVisibilityNode;
// void CNWTileSurfaceMesh::GetVisibilityNodeOrientationvoid
extern void * const CNWTileSurfaceMesh__GetVisibilityNodeOrientation;
// void CNWTileSurfaceMesh::GetWalkMeshvoid
extern void * const CNWTileSurfaceMesh__GetWalkMesh;
// void CNWTileSurfaceMesh::GetWalkTileHashTablevoid
extern void * const CNWTileSurfaceMesh__GetWalkTileHashTable;
// public int CNWTileSurfaceMesh::IntersectLineSegmentsVector, Vector, Vector, Vector, Vector*
extern void * const CNWTileSurfaceMesh__IntersectLineSegments;
// public int CNWTileSurfaceMesh::IntraTileDFSCNWTile*, CNWArea*, CPathfindInformation*, int, float, int, float, float, float, float, float, int
extern void * const CNWTileSurfaceMesh__IntraTileDFS;
// public int CNWTileSurfaceMesh::IntraTileDFSGenerateSuccessorsint, CNWTile*, CNWArea*, float, float, int, CPathfindInformation*, CPathfindInfoIntraTileSuccessors**
extern void * const CNWTileSurfaceMesh__IntraTileDFSGenerateSuccessors;
// public void CNWTileSurfaceMesh::LoadDefaultWalkMeshvoid
extern void * const CNWTileSurfaceMesh__LoadDefaultWalkMesh;
// public int CNWTileSurfaceMesh::LoadWalkMeshvoid
extern void * const CNWTileSurfaceMesh__LoadWalkMesh;
// void CNWTileSurfaceMesh::LoadWalkMeshStringunsigned char**, unsigned long int*, unsigned char*, unsigned long int
extern void * const CNWTileSurfaceMesh__LoadWalkMeshString;
// public int CNWTileSurfaceMesh::NoNonWalkPolysOnTilefloat, float, float, float, float, float, float
extern void * const CNWTileSurfaceMesh__NoNonWalkPolysOnTile;
// public unsigned long int CNWTileSurfaceMesh::PlotIntraTilePathCNWTile*, CNWArea*, CPathfindInformation*, float, float, float, float, unsigned long int, int
extern void * const CNWTileSurfaceMesh__PlotIntraTilePath;
// public int CNWTileSurfaceMesh::PolyHitconst Vector*, int, const Vector&, const Vector&, const Vector&, float, Vector*
extern void * const CNWTileSurfaceMesh__PolyHit;
// void CNWTileSurfaceMesh::PrintAABBTreeToPrintLogCNWTileSurfaceMeshAABBNode*, int
extern void * const CNWTileSurfaceMesh__PrintAABBTreeToPrintLog;
// public void CNWTileSurfaceMesh::RunSubdivisionint*, int, float*, int, int*, int*, int, float*, int, int*
extern void * const CNWTileSurfaceMesh__RunSubdivision;
// void CNWTileSurfaceMesh::SetDoorVisNodeunsigned char
extern void * const CNWTileSurfaceMesh__SetDoorVisNode;
// void CNWTileSurfaceMesh::SetDoorVisNodeOrientationint
extern void * const CNWTileSurfaceMesh__SetDoorVisNodeOrientation;
// public void CNWTileSurfaceMesh::SetPathNodeunsigned char
extern void * const CNWTileSurfaceMesh__SetPathNode;
// void CNWTileSurfaceMesh::SetPathNodeOrientationint
extern void * const CNWTileSurfaceMesh__SetPathNodeOrientation;
// void CNWTileSurfaceMesh::SetVisibilityNodeunsigned char
extern void * const CNWTileSurfaceMesh__SetVisibilityNode;
// void CNWTileSurfaceMesh::SetVisibilityNodeOrientationint
extern void * const CNWTileSurfaceMesh__SetVisibilityNodeOrientation;
// public void CNWTileSurfaceMesh::SetWalkMeshCResRef
extern void * const CNWTileSurfaceMesh__SetWalkMesh;
// void CNWTileSurfaceMesh::SetWalkTileHashTableCNWTileSurfaceMeshHashTableEntry*
extern void * const CNWTileSurfaceMesh__SetWalkTileHashTable;
// public void CNWTileSurfaceMesh::Subdividevoid
extern void * const CNWTileSurfaceMesh__Subdivide;
// public int CNWTileSurfaceMesh::TestLineForWalkableOnAreafloat, float, float, float, float, float, CPathfindInformation*, CNWTile*, CNWArea*
extern void * const CNWTileSurfaceMesh__TestLineForWalkableOnArea;
// public int CNWTileSurfaceMesh::TestLineForWalkableOnTilefloat, float, float, float, float*, float*, CPathfindInformation*, CNWTile*, int
extern void * const CNWTileSurfaceMesh__TestLineForWalkableOnTile;

// CNWTileSurfaceMeshAABBNode::~CNWTileSurfaceMeshAABBNodevoid
extern void * const CNWTileSurfaceMeshAABBNode__CNWTileSurfaceMeshAABBNodeDtor;

// CNWTileSurfaceMeshHashTableEntry::CNWTileSurfaceMeshHashTableEntryvoid
extern void * const CNWTileSurfaceMeshHashTableEntry__CNWTileSurfaceMeshHashTableEntryCtor;
// void CNWTileSurfaceMeshHashTableEntry::Fetchint
extern void * const CNWTileSurfaceMeshHashTableEntry__Fetch;
// void CNWTileSurfaceMeshHashTableEntry::Storeint, float
extern void * const CNWTileSurfaceMeshHashTableEntry__Store;

// public CNWVirtualMachineCommands::~CNWVirtualMachineCommandsvoid
extern void * const CNWVirtualMachineCommands__CNWVirtualMachineCommandsDtor;
// public void* CNWVirtualMachineCommands::CopyGameDefinedStructureint, void*
extern void * const CNWVirtualMachineCommands__CopyGameDefinedStructure;
// public void* CNWVirtualMachineCommands::CreateGameDefinedStructureint
extern void * const CNWVirtualMachineCommands__CreateGameDefinedStructure;
// public int CNWVirtualMachineCommands::DebugGUIGetMessageFromchar**, int*
extern void * const CNWVirtualMachineCommands__DebugGUIGetMessageFrom;
// public void CNWVirtualMachineCommands::DebugGUISendMessageTochar*, int
extern void * const CNWVirtualMachineCommands__DebugGUISendMessageTo;
// public int CNWVirtualMachineCommands::DebugGUIStartvoid
extern void * const CNWVirtualMachineCommands__DebugGUIStart;
// public void CNWVirtualMachineCommands::DebugGUIStopvoid
extern void * const CNWVirtualMachineCommands__DebugGUIStop;
// public void CNWVirtualMachineCommands::DebugGUIUpdatevoid
extern void * const CNWVirtualMachineCommands__DebugGUIUpdate;
// public void CNWVirtualMachineCommands::DestroyGameDefinedStructureint, void*
extern void * const CNWVirtualMachineCommands__DestroyGameDefinedStructure;
// public int CNWVirtualMachineCommands::ExecuteCommandint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommand;
// public int CNWVirtualMachineCommands::ExecuteCommandActionCounterSpellint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandActionCounterSpell;
// public int CNWVirtualMachineCommands::ExecuteCommandActionDoCommandint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandActionDoCommand;
// public int CNWVirtualMachineCommands::ExecuteCommandActionEquipMostDamagingMeleeint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandActionEquipMostDamagingMelee;
// public int CNWVirtualMachineCommands::ExecuteCommandActionEquipMostDamagingRangedint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandActionEquipMostDamagingRanged;
// public int CNWVirtualMachineCommands::ExecuteCommandActionEquipMostEffectiveArmorint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandActionEquipMostEffectiveArmor;
// public int CNWVirtualMachineCommands::ExecuteCommandActionExamineint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandActionExamine;
// public int CNWVirtualMachineCommands::ExecuteCommandActionExchangeItemint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandActionExchangeItem;
// public int CNWVirtualMachineCommands::ExecuteCommandActionFollowObjectint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandActionFollowObject;
// public int CNWVirtualMachineCommands::ExecuteCommandActionInteractObjectint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandActionInteractObject;
// public int CNWVirtualMachineCommands::ExecuteCommandActionJumpToObjectint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandActionJumpToObject;
// public int CNWVirtualMachineCommands::ExecuteCommandActionJumpToPointint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandActionJumpToPoint;
// public int CNWVirtualMachineCommands::ExecuteCommandActionLockActionsint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandActionLockActions;
// public int CNWVirtualMachineCommands::ExecuteCommandActionMoveAwayFromLocationint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandActionMoveAwayFromLocation;
// public int CNWVirtualMachineCommands::ExecuteCommandActionPauseConversationint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandActionPauseConversation;
// public int CNWVirtualMachineCommands::ExecuteCommandActionRandomWalkint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandActionRandomWalk;
// public int CNWVirtualMachineCommands::ExecuteCommandActionRestint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandActionRest;
// public int CNWVirtualMachineCommands::ExecuteCommandActionResumeConversationint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandActionResumeConversation;
// public int CNWVirtualMachineCommands::ExecuteCommandActionSitint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandActionSit;
// public int CNWVirtualMachineCommands::ExecuteCommandActionStartConversationint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandActionStartConversation;
// public int CNWVirtualMachineCommands::ExecuteCommandActionUseFeatint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandActionUseFeat;
// public int CNWVirtualMachineCommands::ExecuteCommandActionUseSkillint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandActionUseSkill;
// public int CNWVirtualMachineCommands::ExecuteCommandActionUseTalentint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandActionUseTalent;
// public int CNWVirtualMachineCommands::ExecuteCommandActivatePortalint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandActivatePortal;
// public int CNWVirtualMachineCommands::ExecuteCommandAddItemPropertyint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandAddItemProperty;
// public int CNWVirtualMachineCommands::ExecuteCommandAddJournalQuestEntryint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandAddJournalQuestEntry;
// public int CNWVirtualMachineCommands::ExecuteCommandAddToPartyint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandAddToParty;
// public int CNWVirtualMachineCommands::ExecuteCommandAdjustAlignmentint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandAdjustAlignment;
// public int CNWVirtualMachineCommands::ExecuteCommandAdjustReputationint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandAdjustReputation;
// public int CNWVirtualMachineCommands::ExecuteCommandAmbientSoundint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandAmbientSound;
// public int CNWVirtualMachineCommands::ExecuteCommandApplyEffectAtPointint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandApplyEffectAtPoint;
// public int CNWVirtualMachineCommands::ExecuteCommandApplyEffectOnObjectint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandApplyEffectOnObject;
// public int CNWVirtualMachineCommands::ExecuteCommandAssignCommandint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandAssignCommand;
// public int CNWVirtualMachineCommands::ExecuteCommandAssociateAccessint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandAssociateAccess;
// public int CNWVirtualMachineCommands::ExecuteCommandAttackint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandAttack;
// public int CNWVirtualMachineCommands::ExecuteCommandBeginConversationint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandBeginConversation;
// public int CNWVirtualMachineCommands::ExecuteCommandBlackScreenint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandBlackScreen;
// public int CNWVirtualMachineCommands::ExecuteCommandBootPCint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandBootPC;
// public int CNWVirtualMachineCommands::ExecuteCommandCastSpellint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandCastSpell;
// public int CNWVirtualMachineCommands::ExecuteCommandChangeFactionint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandChangeFaction;
// public int CNWVirtualMachineCommands::ExecuteCommandClearAllActionsint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandClearAllActions;
// public int CNWVirtualMachineCommands::ExecuteCommandCloseDoorint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandCloseDoor;
// public int CNWVirtualMachineCommands::ExecuteCommandCopyItemint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandCopyItem;
// public int CNWVirtualMachineCommands::ExecuteCommandCopyItemAndModifyint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandCopyItemAndModify;
// public int CNWVirtualMachineCommands::ExecuteCommandCopyObjectint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandCopyObject;
// public int CNWVirtualMachineCommands::ExecuteCommandCreateItemOnObjectint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandCreateItemOnObject;
// public int CNWVirtualMachineCommands::ExecuteCommandCreateObjectint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandCreateObject;
// public int CNWVirtualMachineCommands::ExecuteCommandCreateTrapAtLocationint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandCreateTrapAtLocation;
// public int CNWVirtualMachineCommands::ExecuteCommandCreateTrapOnObjectint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandCreateTrapOnObject;
// public int CNWVirtualMachineCommands::ExecuteCommandDayNightCycleint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandDayNightCycle;
// public int CNWVirtualMachineCommands::ExecuteCommandDecrementFeatUsesint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandDecrementFeatUses;
// public int CNWVirtualMachineCommands::ExecuteCommandDecrementSpellUsesint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandDecrementSpellUses;
// public int CNWVirtualMachineCommands::ExecuteCommandDelayCommandint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandDelayCommand;
// public int CNWVirtualMachineCommands::ExecuteCommandDeleteCampaignVariableint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandDeleteCampaignVariable;
// public int CNWVirtualMachineCommands::ExecuteCommandDeleteVarint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandDeleteVar;
// public int CNWVirtualMachineCommands::ExecuteCommandDestroyCampaignDatabaseint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandDestroyCampaignDatabase;
// public int CNWVirtualMachineCommands::ExecuteCommandDestroyObjectint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandDestroyObject;
// public int CNWVirtualMachineCommands::ExecuteCommandDistanceConversionsint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandDistanceConversions;
// public int CNWVirtualMachineCommands::ExecuteCommandDoDoorActionint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandDoDoorAction;
// public int CNWVirtualMachineCommands::ExecuteCommandDoSinglePlayerAutoSaveint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandDoSinglePlayerAutoSave;
// public int CNWVirtualMachineCommands::ExecuteCommandDoTouchAttackint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandDoTouchAttack;
// public int CNWVirtualMachineCommands::ExecuteCommandDoWhirlwindAttackint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandDoWhirlwindAttack;
// public int CNWVirtualMachineCommands::ExecuteCommandEffectAbilityDecreaseint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEffectAbilityDecrease;
// public int CNWVirtualMachineCommands::ExecuteCommandEffectAbilityIncreaseint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEffectAbilityIncrease;
// public int CNWVirtualMachineCommands::ExecuteCommandEffectACDecreaseint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEffectACDecrease;
// public int CNWVirtualMachineCommands::ExecuteCommandEffectACIncreaseint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEffectACIncrease;
// public int CNWVirtualMachineCommands::ExecuteCommandEffectAppearint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEffectAppear;
// public int CNWVirtualMachineCommands::ExecuteCommandEffectAreaEffectint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEffectAreaEffect;
// public int CNWVirtualMachineCommands::ExecuteCommandEffectAttackDecreaseint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEffectAttackDecrease;
// public int CNWVirtualMachineCommands::ExecuteCommandEffectAttackIncreaseint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEffectAttackIncrease;
// public int CNWVirtualMachineCommands::ExecuteCommandEffectBeamint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEffectBeam;
// public int CNWVirtualMachineCommands::ExecuteCommandEffectBlindnessint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEffectBlindness;
// public int CNWVirtualMachineCommands::ExecuteCommandEffectComplexint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEffectComplex;
// public int CNWVirtualMachineCommands::ExecuteCommandEffectConcealmentint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEffectConcealment;
// public int CNWVirtualMachineCommands::ExecuteCommandEffectCutsceneGhostint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEffectCutsceneGhost;
// public int CNWVirtualMachineCommands::ExecuteCommandEffectDamageint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEffectDamage;
// public int CNWVirtualMachineCommands::ExecuteCommandEffectDamageDecreaseint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEffectDamageDecrease;
// public int CNWVirtualMachineCommands::ExecuteCommandEffectDamageImmunityDecreaseint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEffectDamageImmunityDecrease;
// public int CNWVirtualMachineCommands::ExecuteCommandEffectDamageImmunityIncreaseint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEffectDamageImmunityIncrease;
// public int CNWVirtualMachineCommands::ExecuteCommandEffectDamageIncreaseint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEffectDamageIncrease;
// public int CNWVirtualMachineCommands::ExecuteCommandEffectDamageReductionint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEffectDamageReduction;
// public int CNWVirtualMachineCommands::ExecuteCommandEffectDamageResistanceint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEffectDamageResistance;
// public int CNWVirtualMachineCommands::ExecuteCommandEffectDamageShieldint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEffectDamageShield;
// public int CNWVirtualMachineCommands::ExecuteCommandEffectDarknessint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEffectDarkness;
// public int CNWVirtualMachineCommands::ExecuteCommandEffectDisappearint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEffectDisappear;
// public int CNWVirtualMachineCommands::ExecuteCommandEffectDisappearAppearint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEffectDisappearAppear;
// public int CNWVirtualMachineCommands::ExecuteCommandEffectDiseaseint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEffectDisease;
// public int CNWVirtualMachineCommands::ExecuteCommandEffectEtherealint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEffectEthereal;
// public int CNWVirtualMachineCommands::ExecuteCommandEffectHealint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEffectHeal;
// public int CNWVirtualMachineCommands::ExecuteCommandEffectHitPointChangeWhenDyingint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEffectHitPointChangeWhenDying;
// public int CNWVirtualMachineCommands::ExecuteCommandEffectImmunityint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEffectImmunity;
// public int CNWVirtualMachineCommands::ExecuteCommandEffectInvisibilityint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEffectInvisibility;
// public int CNWVirtualMachineCommands::ExecuteCommandEffectLinkEffectsint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEffectLinkEffects;
// public int CNWVirtualMachineCommands::ExecuteCommandEffectMissChanceint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEffectMissChance;
// public int CNWVirtualMachineCommands::ExecuteCommandEffectModifyAttacksint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEffectModifyAttacks;
// public int CNWVirtualMachineCommands::ExecuteCommandEffectMovementSpeedDecreaseint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEffectMovementSpeedDecrease;
// public int CNWVirtualMachineCommands::ExecuteCommandEffectMovementSpeedIncreaseint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEffectMovementSpeedIncrease;
// public int CNWVirtualMachineCommands::ExecuteCommandEffectNegativeLevelint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEffectNegativeLevel;
// public int CNWVirtualMachineCommands::ExecuteCommandEffectPetrifyint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEffectPetrify;
// public int CNWVirtualMachineCommands::ExecuteCommandEffectPoisonint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEffectPoison;
// public int CNWVirtualMachineCommands::ExecuteCommandEffectResurrectionint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEffectResurrection;
// public int CNWVirtualMachineCommands::ExecuteCommandEffectSanctuaryint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEffectSanctuary;
// public int CNWVirtualMachineCommands::ExecuteCommandEffectSavingThrowDecreaseint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEffectSavingThrowDecrease;
// public int CNWVirtualMachineCommands::ExecuteCommandEffectSavingThrowIncreaseint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEffectSavingThrowIncrease;
// public int CNWVirtualMachineCommands::ExecuteCommandEffectSeeInvisibleint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEffectSeeInvisible;
// public int CNWVirtualMachineCommands::ExecuteCommandEffectSkillDecreaseint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEffectSkillDecrease;
// public int CNWVirtualMachineCommands::ExecuteCommandEffectSkillIncreaseint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEffectSkillIncrease;
// public int CNWVirtualMachineCommands::ExecuteCommandEffectSpellFailureint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEffectSpellFailure;
// public int CNWVirtualMachineCommands::ExecuteCommandEffectSpellImmunityint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEffectSpellImmunity;
// public int CNWVirtualMachineCommands::ExecuteCommandEffectSpellLevelAbsorptionint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEffectSpellLevelAbsorption;
// public int CNWVirtualMachineCommands::ExecuteCommandEffectSpellResistanceDecreaseint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEffectSpellResistanceDecrease;
// public int CNWVirtualMachineCommands::ExecuteCommandEffectSpellResistanceIncreaseint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEffectSpellResistanceIncrease;
// public int CNWVirtualMachineCommands::ExecuteCommandEffectSummonCreatureint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEffectSummonCreature;
// public int CNWVirtualMachineCommands::ExecuteCommandEffectSwarmint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEffectSwarm;
// public int CNWVirtualMachineCommands::ExecuteCommandEffectTemporaryHPint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEffectTemporaryHP;
// public int CNWVirtualMachineCommands::ExecuteCommandEffectTrueSeeingint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEffectTrueSeeing;
// public int CNWVirtualMachineCommands::ExecuteCommandEffectTurnResistanceint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEffectTurnResistance;
// public int CNWVirtualMachineCommands::ExecuteCommandEffectUltravisionint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEffectUltravision;
// public int CNWVirtualMachineCommands::ExecuteCommandEffectVisualEffectint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEffectVisualEffect;
// public int CNWVirtualMachineCommands::ExecuteCommandEndGameint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEndGame;
// public int CNWVirtualMachineCommands::ExecuteCommandEquipItemint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEquipItem;
// public int CNWVirtualMachineCommands::ExecuteCommandEventActivateItemint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEventActivateItem;
// public int CNWVirtualMachineCommands::ExecuteCommandEventConversationint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEventConversation;
// public int CNWVirtualMachineCommands::ExecuteCommandEventSpellCastAtint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEventSpellCastAt;
// public int CNWVirtualMachineCommands::ExecuteCommandEventUserDefinedint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandEventUserDefined;
// public int CNWVirtualMachineCommands::ExecuteCommandExecuteScriptint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandExecuteScript;
// public int CNWVirtualMachineCommands::ExecuteCommandExploreAreaForPlayerint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandExploreAreaForPlayer;
// public int CNWVirtualMachineCommands::ExecuteCommandExportAllCharactersint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandExportAllCharacters;
// public int CNWVirtualMachineCommands::ExecuteCommandExportSingleCharacterint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandExportSingleCharacter;
// public int CNWVirtualMachineCommands::ExecuteCommandFindSubStringint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandFindSubString;
// public int CNWVirtualMachineCommands::ExecuteCommandFloatingTextint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandFloatingText;
// public int CNWVirtualMachineCommands::ExecuteCommandFloatToIntint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandFloatToInt;
// public int CNWVirtualMachineCommands::ExecuteCommandFloatToStringint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandFloatToString;
// public int CNWVirtualMachineCommands::ExecuteCommandForceRestint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandForceRest;
// public int CNWVirtualMachineCommands::ExecuteCommandGet2DAStringint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGet2DAString;
// public int CNWVirtualMachineCommands::ExecuteCommandGetAbilityModifierint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetAbilityModifier;
// public int CNWVirtualMachineCommands::ExecuteCommandGetAbilityScoreint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetAbilityScore;
// public int CNWVirtualMachineCommands::ExecuteCommandGetACint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetAC;
// public int CNWVirtualMachineCommands::ExecuteCommandGetActionModeint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetActionMode;
// public int CNWVirtualMachineCommands::ExecuteCommandGetAgeint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetAge;
// public int CNWVirtualMachineCommands::ExecuteCommandGetAILevelint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetAILevel;
// public int CNWVirtualMachineCommands::ExecuteCommandGetAlignmentint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetAlignment;
// public int CNWVirtualMachineCommands::ExecuteCommandGetAnimalCompanionCreatureTypeint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetAnimalCompanionCreatureType;
// public int CNWVirtualMachineCommands::ExecuteCommandGetAnimalCompanionNameint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetAnimalCompanionName;
// public int CNWVirtualMachineCommands::ExecuteCommandGetAOEObjectCreatorint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetAOEObjectCreator;
// public int CNWVirtualMachineCommands::ExecuteCommandGetAppearanceTypeint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetAppearanceType;
// public int CNWVirtualMachineCommands::ExecuteCommandGetArcaneSpellFailureint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetArcaneSpellFailure;
// public int CNWVirtualMachineCommands::ExecuteCommandGetAreaint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetArea;
// public int CNWVirtualMachineCommands::ExecuteCommandGetAreaSizeint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetAreaSize;
// public int CNWVirtualMachineCommands::ExecuteCommandGetAssociateint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetAssociate;
// public int CNWVirtualMachineCommands::ExecuteCommandGetAssociateTypeint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetAssociateType;
// public int CNWVirtualMachineCommands::ExecuteCommandGetAttackTargetint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetAttackTarget;
// public int CNWVirtualMachineCommands::ExecuteCommandGetAttemptedAttackTargetint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetAttemptedAttackTarget;
// public int CNWVirtualMachineCommands::ExecuteCommandGetAttemptedSpellTargetint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetAttemptedSpellTarget;
// public int CNWVirtualMachineCommands::ExecuteCommandGetBaseAttackBonusint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetBaseAttackBonus;
// public int CNWVirtualMachineCommands::ExecuteCommandGetBaseItemTypeint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetBaseItemType;
// public int CNWVirtualMachineCommands::ExecuteCommandGetBattleTrackint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetBattleTrack;
// public int CNWVirtualMachineCommands::ExecuteCommandGetBlockingDoorint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetBlockingDoor;
// public int CNWVirtualMachineCommands::ExecuteCommandGetCalendarDayint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetCalendarDay;
// public int CNWVirtualMachineCommands::ExecuteCommandGetCalendarMonthint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetCalendarMonth;
// public int CNWVirtualMachineCommands::ExecuteCommandGetCalendarYearint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetCalendarYear;
// public int CNWVirtualMachineCommands::ExecuteCommandGetCampaignFloatint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetCampaignFloat;
// public int CNWVirtualMachineCommands::ExecuteCommandGetCampaignIntint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetCampaignInt;
// public int CNWVirtualMachineCommands::ExecuteCommandGetCampaignLocationint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetCampaignLocation;
// public int CNWVirtualMachineCommands::ExecuteCommandGetCampaignStringint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetCampaignString;
// public int CNWVirtualMachineCommands::ExecuteCommandGetCampaignVectorint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetCampaignVector;
// public int CNWVirtualMachineCommands::ExecuteCommandGetCasterLevelint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetCasterLevel;
// public int CNWVirtualMachineCommands::ExecuteCommandGetChallengeRatingint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetChallengeRating;
// public int CNWVirtualMachineCommands::ExecuteCommandGetClassInformationint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetClassInformation;
// public int CNWVirtualMachineCommands::ExecuteCommandGetColorint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetColor;
// public int CNWVirtualMachineCommands::ExecuteCommandGetCommandableint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetCommandable;
// public int CNWVirtualMachineCommands::ExecuteCommandGetCreatureBodyPartint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetCreatureBodyPart;
// public int CNWVirtualMachineCommands::ExecuteCommandGetCreatureHasTalentint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetCreatureHasTalent;
// public int CNWVirtualMachineCommands::ExecuteCommandGetCreatureSizeint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetCreatureSize;
// public int CNWVirtualMachineCommands::ExecuteCommandGetCreatureTailTypeint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetCreatureTailType;
// public int CNWVirtualMachineCommands::ExecuteCommandGetCreatureTalentint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetCreatureTalent;
// public int CNWVirtualMachineCommands::ExecuteCommandGetCreatureWingTypeint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetCreatureWingType;
// public int CNWVirtualMachineCommands::ExecuteCommandGetCurrentActionint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetCurrentAction;
// public int CNWVirtualMachineCommands::ExecuteCommandGetCutsceneCameraMoveRateint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetCutsceneCameraMoveRate;
// public int CNWVirtualMachineCommands::ExecuteCommandGetCutsceneModeint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetCutsceneMode;
// public int CNWVirtualMachineCommands::ExecuteCommandGetDamageDealtByTypeint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetDamageDealtByType;
// public int CNWVirtualMachineCommands::ExecuteCommandGetDayTrackint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetDayTrack;
// public int CNWVirtualMachineCommands::ExecuteCommandGetDeityint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetDeity;
// public int CNWVirtualMachineCommands::ExecuteCommandGetDescriptionint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetDescription;
// public int CNWVirtualMachineCommands::ExecuteCommandGetDialogSoundLengthint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetDialogSoundLength;
// public int CNWVirtualMachineCommands::ExecuteCommandGetDistanceBetweenint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetDistanceBetween;
// public int CNWVirtualMachineCommands::ExecuteCommandGetDistanceBetweenLocationsint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetDistanceBetweenLocations;
// public int CNWVirtualMachineCommands::ExecuteCommandGetDistanceToObjectint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetDistanceToObject;
// public int CNWVirtualMachineCommands::ExecuteCommandGetDroppableFlagint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetDroppableFlag;
// public int CNWVirtualMachineCommands::ExecuteCommandGetEffectint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetEffect;
// public int CNWVirtualMachineCommands::ExecuteCommandGetEffectCreatorint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetEffectCreator;
// public int CNWVirtualMachineCommands::ExecuteCommandGetEffectDurationTypeint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetEffectDurationType;
// public int CNWVirtualMachineCommands::ExecuteCommandGetEffectSpellIdint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetEffectSpellId;
// public int CNWVirtualMachineCommands::ExecuteCommandGetEffectSubTypeint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetEffectSubType;
// public int CNWVirtualMachineCommands::ExecuteCommandGetEffectTypeint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetEffectType;
// public int CNWVirtualMachineCommands::ExecuteCommandGetEmotionsint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetEmotions;
// public int CNWVirtualMachineCommands::ExecuteCommandGetEncounterDataint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetEncounterData;
// public int CNWVirtualMachineCommands::ExecuteCommandGetEnteringObjectint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetEnteringObject;
// public int CNWVirtualMachineCommands::ExecuteCommandGetFacingint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetFacing;
// public int CNWVirtualMachineCommands::ExecuteCommandGetFactionAverageGoodEvilAlignmentint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetFactionAverageGoodEvilAlignment;
// public int CNWVirtualMachineCommands::ExecuteCommandGetFactionAverageLawChaosAlignmentint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetFactionAverageLawChaosAlignment;
// public int CNWVirtualMachineCommands::ExecuteCommandGetFactionAverageLevelint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetFactionAverageLevel;
// public int CNWVirtualMachineCommands::ExecuteCommandGetFactionAverageReputationint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetFactionAverageReputation;
// public int CNWVirtualMachineCommands::ExecuteCommandGetFactionAverageXPint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetFactionAverageXP;
// public int CNWVirtualMachineCommands::ExecuteCommandGetFactionBestACint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetFactionBestAC;
// public int CNWVirtualMachineCommands::ExecuteCommandGetFactionEqualint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetFactionEqual;
// public int CNWVirtualMachineCommands::ExecuteCommandGetFactionGoldint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetFactionGold;
// public int CNWVirtualMachineCommands::ExecuteCommandGetFactionLeaderint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetFactionLeader;
// public int CNWVirtualMachineCommands::ExecuteCommandGetFactionLeastDamagedMemberint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetFactionLeastDamagedMember;
// public int CNWVirtualMachineCommands::ExecuteCommandGetFactionMemberint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetFactionMember;
// public int CNWVirtualMachineCommands::ExecuteCommandGetFactionMostDamagedMemberint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetFactionMostDamagedMember;
// public int CNWVirtualMachineCommands::ExecuteCommandGetFactionMostFrequentClassint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetFactionMostFrequentClass;
// void CNWVirtualMachineCommands::ExecuteCommandGetFactionNthNearestMemberint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetFactionNthNearestMember;
// public int CNWVirtualMachineCommands::ExecuteCommandGetFactionStrongestMemberint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetFactionStrongestMember;
// public int CNWVirtualMachineCommands::ExecuteCommandGetFactionWeakestMemberint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetFactionWeakestMember;
// public int CNWVirtualMachineCommands::ExecuteCommandGetFactionWorstACint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetFactionWorstAC;
// public int CNWVirtualMachineCommands::ExecuteCommandGetFamiliarCreatureTypeint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetFamiliarCreatureType;
// public int CNWVirtualMachineCommands::ExecuteCommandGetFamiliarNameint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetFamiliarName;
// public int CNWVirtualMachineCommands::ExecuteCommandGetFogAmountint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetFogAmount;
// public int CNWVirtualMachineCommands::ExecuteCommandGetFogColorint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetFogColor;
// public int CNWVirtualMachineCommands::ExecuteCommandGetFootstepTypeint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetFootstepType;
// public int CNWVirtualMachineCommands::ExecuteCommandGetFortitudeSavingThrowint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetFortitudeSavingThrow;
// public int CNWVirtualMachineCommands::ExecuteCommandGetGameDifficultyint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetGameDifficulty;
// public int CNWVirtualMachineCommands::ExecuteCommandGetGoingToBeAttackedByint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetGoingToBeAttackedBy;
// public int CNWVirtualMachineCommands::ExecuteCommandGetGoldint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetGold;
// public int CNWVirtualMachineCommands::ExecuteCommandGetGoldPieceValueint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetGoldPieceValue;
// public int CNWVirtualMachineCommands::ExecuteCommandGetHardnessint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetHardness;
// public int CNWVirtualMachineCommands::ExecuteCommandGetHasFeatint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetHasFeat;
// public int CNWVirtualMachineCommands::ExecuteCommandGetHasFeatEffectint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetHasFeatEffect;
// public int CNWVirtualMachineCommands::ExecuteCommandGetHasInventoryint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetHasInventory;
// public int CNWVirtualMachineCommands::ExecuteCommandGetHasSkillint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetHasSkill;
// public int CNWVirtualMachineCommands::ExecuteCommandGetHasSpellint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetHasSpell;
// public int CNWVirtualMachineCommands::ExecuteCommandGetHasSpellEffectint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetHasSpellEffect;
// public int CNWVirtualMachineCommands::ExecuteCommandGetHenchmanint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetHenchman;
// public int CNWVirtualMachineCommands::ExecuteCommandGetHitDiceint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetHitDice;
// public int CNWVirtualMachineCommands::ExecuteCommandGetHitpointsint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetHitpoints;
// public int CNWVirtualMachineCommands::ExecuteCommandGetIdentifiedint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetIdentified;
// public int CNWVirtualMachineCommands::ExecuteCommandGetImmortalint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetImmortal;
// public int CNWVirtualMachineCommands::ExecuteCommandGetInfiniteFlagint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetInfiniteFlag;
// public int CNWVirtualMachineCommands::ExecuteCommandGetInPersistentObjectint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetInPersistentObject;
// public int CNWVirtualMachineCommands::ExecuteCommandGetInventoryDisturbItemint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetInventoryDisturbItem;
// public int CNWVirtualMachineCommands::ExecuteCommandGetInventoryDisturbTypeint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetInventoryDisturbType;
// public int CNWVirtualMachineCommands::ExecuteCommandGetIsAreaAboveGroundint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetIsAreaAboveGround;
// public int CNWVirtualMachineCommands::ExecuteCommandGetIsAreaInteriorint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetIsAreaInterior;
// public int CNWVirtualMachineCommands::ExecuteCommandGetIsAreaNaturalint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetIsAreaNatural;
// public int CNWVirtualMachineCommands::ExecuteCommandGetIsCreatureDisarmableint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetIsCreatureDisarmable;
// public int CNWVirtualMachineCommands::ExecuteCommandGetIsDawnint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetIsDawn;
// public int CNWVirtualMachineCommands::ExecuteCommandGetIsDayint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetIsDay;
// public int CNWVirtualMachineCommands::ExecuteCommandGetIsDMPossessedint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetIsDMPossessed;
// public int CNWVirtualMachineCommands::ExecuteCommandGetIsDoorActionPossibleint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetIsDoorActionPossible;
// public int CNWVirtualMachineCommands::ExecuteCommandGetIsDuskint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetIsDusk;
// public int CNWVirtualMachineCommands::ExecuteCommandGetIsEncounterCreatureint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetIsEncounterCreature;
// public int CNWVirtualMachineCommands::ExecuteCommandGetIsImmuneint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetIsImmune;
// public int CNWVirtualMachineCommands::ExecuteCommandGetIsInCombatint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetIsInCombat;
// public int CNWVirtualMachineCommands::ExecuteCommandGetIsInTriggerint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetIsInTrigger;
// public int CNWVirtualMachineCommands::ExecuteCommandGetIsNightint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetIsNight;
// public int CNWVirtualMachineCommands::ExecuteCommandGetIsOpenint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetIsOpen;
// public int CNWVirtualMachineCommands::ExecuteCommandGetIsPossessedFamiliarint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetIsPossessedFamiliar;
// public int CNWVirtualMachineCommands::ExecuteCommandGetIsRacialTypePlayableint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetIsRacialTypePlayable;
// public int CNWVirtualMachineCommands::ExecuteCommandGetIsReactionTypeint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetIsReactionType;
// public int CNWVirtualMachineCommands::ExecuteCommandGetIsRestingint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetIsResting;
// public int CNWVirtualMachineCommands::ExecuteCommandGetIsSkillSuccessfulint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetIsSkillSuccessful;
// public int CNWVirtualMachineCommands::ExecuteCommandGetIsTalentValidint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetIsTalentValid;
// public int CNWVirtualMachineCommands::ExecuteCommandGetIsTrappedint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetIsTrapped;
// public int CNWVirtualMachineCommands::ExecuteCommandGetIsWeaponEffectiveint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetIsWeaponEffective;
// public int CNWVirtualMachineCommands::ExecuteCommandGetItemACValueint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetItemACValue;
// public int CNWVirtualMachineCommands::ExecuteCommandGetItemAppearanceint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetItemAppearance;
// public int CNWVirtualMachineCommands::ExecuteCommandGetItemChargesint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetItemCharges;
// public int CNWVirtualMachineCommands::ExecuteCommandGetItemCursedFlagint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetItemCursedFlag;
// public int CNWVirtualMachineCommands::ExecuteCommandGetItemHasItemPropertyint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetItemHasItemProperty;
// public int CNWVirtualMachineCommands::ExecuteCommandGetItemInInventoryint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetItemInInventory;
// public int CNWVirtualMachineCommands::ExecuteCommandGetItemInSlotint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetItemInSlot;
// public int CNWVirtualMachineCommands::ExecuteCommandGetItemPossessedByint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetItemPossessedBy;
// public int CNWVirtualMachineCommands::ExecuteCommandGetItemPossessorint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetItemPossessor;
// public int CNWVirtualMachineCommands::ExecuteCommandGetItemPropertyint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetItemProperty;
// public int CNWVirtualMachineCommands::ExecuteCommandGetItemPropertyDurationTypeint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetItemPropertyDurationType;
// public int CNWVirtualMachineCommands::ExecuteCommandGetItemPropertyInfoint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetItemPropertyInfo;
// public int CNWVirtualMachineCommands::ExecuteCommandGetItemPropertyTypeint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetItemPropertyType;
// public int CNWVirtualMachineCommands::ExecuteCommandGetItemStackSizeint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetItemStackSize;
// public int CNWVirtualMachineCommands::ExecuteCommandGetJournalQuestExperienceint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetJournalQuestExperience;
// public int CNWVirtualMachineCommands::ExecuteCommandGetKeyRequiredFeedbackMessageint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetKeyRequiredFeedbackMessage;
// public int CNWVirtualMachineCommands::ExecuteCommandGetLastAssociateCommandint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetLastAssociateCommand;
// public int CNWVirtualMachineCommands::ExecuteCommandGetLastAttackerint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetLastAttacker;
// public int CNWVirtualMachineCommands::ExecuteCommandGetLastAttackModeint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetLastAttackMode;
// public int CNWVirtualMachineCommands::ExecuteCommandGetLastAttackTypeint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetLastAttackType;
// public int CNWVirtualMachineCommands::ExecuteCommandGetLastClosedByint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetLastClosedBy;
// public int CNWVirtualMachineCommands::ExecuteCommandGetLastDamagerint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetLastDamager;
// public int CNWVirtualMachineCommands::ExecuteCommandGetLastDisarmedint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetLastDisarmed;
// public int CNWVirtualMachineCommands::ExecuteCommandGetLastDisturbedint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetLastDisturbed;
// public int CNWVirtualMachineCommands::ExecuteCommandGetLastEquippedint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetLastEquipped;
// public int CNWVirtualMachineCommands::ExecuteCommandGetLastHostileActorint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetLastHostileActor;
// public int CNWVirtualMachineCommands::ExecuteCommandGetLastKillerint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetLastKiller;
// public int CNWVirtualMachineCommands::ExecuteCommandGetLastLockedint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetLastLocked;
// public int CNWVirtualMachineCommands::ExecuteCommandGetLastOpenedByint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetLastOpenedBy;
// public int CNWVirtualMachineCommands::ExecuteCommandGetLastPCRestedint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetLastPCRested;
// public int CNWVirtualMachineCommands::ExecuteCommandGetLastPerceivedint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetLastPerceived;
// public int CNWVirtualMachineCommands::ExecuteCommandGetLastPerceptionint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetLastPerception;
// public int CNWVirtualMachineCommands::ExecuteCommandGetLastRestEventTypeint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetLastRestEventType;
// public int CNWVirtualMachineCommands::ExecuteCommandGetLastSpeakerint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetLastSpeaker;
// public int CNWVirtualMachineCommands::ExecuteCommandGetLastSpellCastClassint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetLastSpellCastClass;
// public int CNWVirtualMachineCommands::ExecuteCommandGetLastTrapDetectedint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetLastTrapDetected;
// public int CNWVirtualMachineCommands::ExecuteCommandGetLastUnlockedint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetLastUnlocked;
// public int CNWVirtualMachineCommands::ExecuteCommandGetLastUsedByint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetLastUsedBy;
// public int CNWVirtualMachineCommands::ExecuteCommandGetLastWeaponUsedint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetLastWeaponUsed;
// public int CNWVirtualMachineCommands::ExecuteCommandGetLeavingObjectint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetLeavingObject;
// public int CNWVirtualMachineCommands::ExecuteCommandGetLocationint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetLocation;
// public int CNWVirtualMachineCommands::ExecuteCommandGetLockedint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetLocked;
// public int CNWVirtualMachineCommands::ExecuteCommandGetLockInfoint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetLockInfo;
// public int CNWVirtualMachineCommands::ExecuteCommandGetLootableint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetLootable;
// public int CNWVirtualMachineCommands::ExecuteCommandGetMasterint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetMaster;
// public int CNWVirtualMachineCommands::ExecuteCommandGetMatchedStringint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetMatchedString;
// public int CNWVirtualMachineCommands::ExecuteCommandGetMatchedStringsCountint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetMatchedStringsCount;
// public int CNWVirtualMachineCommands::ExecuteCommandGetMatchedStringsNumint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetMatchedStringsNum;
// public int CNWVirtualMachineCommands::ExecuteCommandGetMaxHenchmenint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetMaxHenchmen;
// public int CNWVirtualMachineCommands::ExecuteCommandGetMetaMagicFeatint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetMetaMagicFeat;
// public int CNWVirtualMachineCommands::ExecuteCommandGetModeStateint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetModeState;
// public int CNWVirtualMachineCommands::ExecuteCommandGetModuleint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetModule;
// public int CNWVirtualMachineCommands::ExecuteCommandGetModuleItemStuffint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetModuleItemStuff;
// public int CNWVirtualMachineCommands::ExecuteCommandGetModuleNameint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetModuleName;
// public int CNWVirtualMachineCommands::ExecuteCommandGetMovementRateint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetMovementRate;
// public int CNWVirtualMachineCommands::ExecuteCommandGetNameint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetName;
// public int CNWVirtualMachineCommands::ExecuteCommandGetNearestObjectint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetNearestObject;
// public int CNWVirtualMachineCommands::ExecuteCommandGetNearestTrapint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetNearestTrap;
// public int CNWVirtualMachineCommands::ExecuteCommandGetNightTrackint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetNightTrack;
// public int CNWVirtualMachineCommands::ExecuteCommandGetNumStackedItemsint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetNumStackedItems;
// public int CNWVirtualMachineCommands::ExecuteCommandGetObjectByTagint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetObjectByTag;
// public int CNWVirtualMachineCommands::ExecuteCommandGetObjectInAreaint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetObjectInArea;
// public int CNWVirtualMachineCommands::ExecuteCommandGetObjectInShapeint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetObjectInShape;
// public int CNWVirtualMachineCommands::ExecuteCommandGetObjectTypeint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetObjectType;
// public int CNWVirtualMachineCommands::ExecuteCommandGetObjectValidint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetObjectValid;
// public int CNWVirtualMachineCommands::ExecuteCommandGetObjectVisibilityint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetObjectVisibility;
// public int CNWVirtualMachineCommands::ExecuteCommandGetPCint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetPC;
// public int CNWVirtualMachineCommands::ExecuteCommandGetPCChatMessageint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetPCChatMessage;
// public int CNWVirtualMachineCommands::ExecuteCommandGetPCChatSpeakerint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetPCChatSpeaker;
// public int CNWVirtualMachineCommands::ExecuteCommandGetPCChatVolumeint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetPCChatVolume;
// public int CNWVirtualMachineCommands::ExecuteCommandGetPCIPAddressint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetPCIPAddress;
// public int CNWVirtualMachineCommands::ExecuteCommandGetPCLevellingUpint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetPCLevellingUp;
// public int CNWVirtualMachineCommands::ExecuteCommandGetPCPlayerNameint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetPCPlayerName;
// public int CNWVirtualMachineCommands::ExecuteCommandGetPCPublicCDKeyint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetPCPublicCDKey;
// public int CNWVirtualMachineCommands::ExecuteCommandGetPCSpeakerint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetPCSpeaker;
// public int CNWVirtualMachineCommands::ExecuteCommandGetPhenoTypeint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetPhenoType;
// public int CNWVirtualMachineCommands::ExecuteCommandGetPickpocketableFlagint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetPickpocketableFlag;
// public int CNWVirtualMachineCommands::ExecuteCommandGetPlaceableIlluminationint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetPlaceableIllumination;
// public int CNWVirtualMachineCommands::ExecuteCommandGetPlotFlagint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetPlotFlag;
// public int CNWVirtualMachineCommands::ExecuteCommandGetPortraitIdint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetPortraitId;
// public int CNWVirtualMachineCommands::ExecuteCommandGetPortraitResRefint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetPortraitResRef;
// public int CNWVirtualMachineCommands::ExecuteCommandGetPositionint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetPosition;
// public int CNWVirtualMachineCommands::ExecuteCommandGetRacialTypeint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetRacialType;
// public int CNWVirtualMachineCommands::ExecuteCommandGetReflexAdjustedDamageint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetReflexAdjustedDamage;
// public int CNWVirtualMachineCommands::ExecuteCommandGetReflexSavingThrowint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetReflexSavingThrow;
// public int CNWVirtualMachineCommands::ExecuteCommandGetReputationint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetReputation;
// public int CNWVirtualMachineCommands::ExecuteCommandGetResRefint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetResRef;
// public int CNWVirtualMachineCommands::ExecuteCommandGetSittingCreatureint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetSittingCreature;
// public int CNWVirtualMachineCommands::ExecuteCommandGetSkillRankint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetSkillRank;
// public int CNWVirtualMachineCommands::ExecuteCommandGetSkyBoxint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetSkyBox;
// public int CNWVirtualMachineCommands::ExecuteCommandGetSpellCastint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetSpellCast;
// public int CNWVirtualMachineCommands::ExecuteCommandGetSpellCasterItemint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetSpellCasterItem;
// public int CNWVirtualMachineCommands::ExecuteCommandGetSpellIdint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetSpellId;
// public int CNWVirtualMachineCommands::ExecuteCommandGetSpellResistanceint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetSpellResistance;
// public int CNWVirtualMachineCommands::ExecuteCommandGetSpellSaveDCint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetSpellSaveDC;
// public int CNWVirtualMachineCommands::ExecuteCommandGetSpellTargetLocint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetSpellTargetLoc;
// public int CNWVirtualMachineCommands::ExecuteCommandGetSpellTargetObjectint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetSpellTargetObject;
// public int CNWVirtualMachineCommands::ExecuteCommandGetStartingPackageint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetStartingPackage;
// public int CNWVirtualMachineCommands::ExecuteCommandGetStatint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetStat;
// public int CNWVirtualMachineCommands::ExecuteCommandGetStolenFlagint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetStolenFlag;
// public int CNWVirtualMachineCommands::ExecuteCommandGetStrByStrRefint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetStrByStrRef;
// public int CNWVirtualMachineCommands::ExecuteCommandGetStringLeftint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetStringLeft;
// public int CNWVirtualMachineCommands::ExecuteCommandGetStringLengthint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetStringLength;
// public int CNWVirtualMachineCommands::ExecuteCommandGetStringLowerCaseint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetStringLowerCase;
// public int CNWVirtualMachineCommands::ExecuteCommandGetStringRightint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetStringRight;
// public int CNWVirtualMachineCommands::ExecuteCommandGetStringUpperCaseint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetStringUpperCase;
// public int CNWVirtualMachineCommands::ExecuteCommandGetStrRefSoundDurationint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetStrRefSoundDuration;
// public int CNWVirtualMachineCommands::ExecuteCommandGetSubRaceint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetSubRace;
// public int CNWVirtualMachineCommands::ExecuteCommandGetSubStringint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetSubString;
// public int CNWVirtualMachineCommands::ExecuteCommandGetTagint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetTag;
// public int CNWVirtualMachineCommands::ExecuteCommandGetTileLightColorint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetTileLightColor;
// public int CNWVirtualMachineCommands::ExecuteCommandGetTimeHourint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetTimeHour;
// public int CNWVirtualMachineCommands::ExecuteCommandGetTimeMillisecondint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetTimeMillisecond;
// public int CNWVirtualMachineCommands::ExecuteCommandGetTimeMinuteint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetTimeMinute;
// public int CNWVirtualMachineCommands::ExecuteCommandGetTimeSecondint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetTimeSecond;
// public int CNWVirtualMachineCommands::ExecuteCommandGetTotalDamageDealtint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetTotalDamageDealt;
// public int CNWVirtualMachineCommands::ExecuteCommandGetTrapInfoint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetTrapInfo;
// public int CNWVirtualMachineCommands::ExecuteCommandGetTurnResistanceHDint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetTurnResistanceHD;
// public int CNWVirtualMachineCommands::ExecuteCommandGetUseableFlagint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetUseableFlag;
// public int CNWVirtualMachineCommands::ExecuteCommandGetUserDefinedEventNumberint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetUserDefinedEventNumber;
// public int CNWVirtualMachineCommands::ExecuteCommandGetVarint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetVar;
// public int CNWVirtualMachineCommands::ExecuteCommandGetWaypointByTagint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetWaypointByTag;
// public int CNWVirtualMachineCommands::ExecuteCommandGetWaypointByTriggerint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetWaypointByTrigger;
// public int CNWVirtualMachineCommands::ExecuteCommandGetWeaponRangedint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetWeaponRanged;
// public int CNWVirtualMachineCommands::ExecuteCommandGetWeatherint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetWeather;
// public int CNWVirtualMachineCommands::ExecuteCommandGetWeightint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetWeight;
// public int CNWVirtualMachineCommands::ExecuteCommandGetWillSavingThrowint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetWillSavingThrow;
// public int CNWVirtualMachineCommands::ExecuteCommandGetXPint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetXP;
// public int CNWVirtualMachineCommands::ExecuteCommandGetXPScaleint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGetXPScale;
// public int CNWVirtualMachineCommands::ExecuteCommandGiveGoldToCreatureint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGiveGoldToCreature;
// public int CNWVirtualMachineCommands::ExecuteCommandGiveXPToCreatureint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandGiveXPToCreature;
// public int CNWVirtualMachineCommands::ExecuteCommandIncrementRemainingFeatUsesint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandIncrementRemainingFeatUses;
// public int CNWVirtualMachineCommands::ExecuteCommandInsertStringint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandInsertString;
// public int CNWVirtualMachineCommands::ExecuteCommandIntToFloatint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandIntToFloat;
// public int CNWVirtualMachineCommands::ExecuteCommandIntToHexStringint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandIntToHexString;
// public int CNWVirtualMachineCommands::ExecuteCommandIntToStringint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandIntToString;
// public int CNWVirtualMachineCommands::ExecuteCommandIsAIStateint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandIsAIState;
// public int CNWVirtualMachineCommands::ExecuteCommandIsDMint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandIsDM;
// public int CNWVirtualMachineCommands::ExecuteCommandIsEffectValidint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandIsEffectValid;
// public int CNWVirtualMachineCommands::ExecuteCommandIsInConversationint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandIsInConversation;
// public int CNWVirtualMachineCommands::ExecuteCommandIsItemPropertyValidint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandIsItemPropertyValid;
// public int CNWVirtualMachineCommands::ExecuteCommandIsListeningint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandIsListening;
// public int CNWVirtualMachineCommands::ExecuteCommandIsPCint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandIsPC;
// public int CNWVirtualMachineCommands::ExecuteCommandItemActivatedint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandItemActivated;
// public int CNWVirtualMachineCommands::ExecuteCommandItemPropertyEffectint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandItemPropertyEffect;
// public int CNWVirtualMachineCommands::ExecuteCommandLevelUpHenchmanint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandLevelUpHenchman;
// public int CNWVirtualMachineCommands::ExecuteCommandLineOfSightint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandLineOfSight;
// public int CNWVirtualMachineCommands::ExecuteCommandLocationint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandLocation;
// public int CNWVirtualMachineCommands::ExecuteCommandLocationAccessint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandLocationAccess;
// public int CNWVirtualMachineCommands::ExecuteCommandLockCameraint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandLockCamera;
// public int CNWVirtualMachineCommands::ExecuteCommandMathint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandMath;
// public int CNWVirtualMachineCommands::ExecuteCommandModuleAccessint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandModuleAccess;
// public int CNWVirtualMachineCommands::ExecuteCommandMoveAwayFromObjectint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandMoveAwayFromObject;
// public int CNWVirtualMachineCommands::ExecuteCommandMoveToObjectint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandMoveToObject;
// public int CNWVirtualMachineCommands::ExecuteCommandMoveToPointint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandMoveToPoint;
// public int CNWVirtualMachineCommands::ExecuteCommandMusicBackgroundint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandMusicBackground;
// public int CNWVirtualMachineCommands::ExecuteCommandMusicBattleint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandMusicBattle;
// public int CNWVirtualMachineCommands::ExecuteCommandObjectToStringint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandObjectToString;
// public int CNWVirtualMachineCommands::ExecuteCommandOpenDoorint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandOpenDoor;
// public int CNWVirtualMachineCommands::ExecuteCommandOpenInventoryint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandOpenInventory;
// public int CNWVirtualMachineCommands::ExecuteCommandOpenStoreint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandOpenStore;
// public int CNWVirtualMachineCommands::ExecuteCommandPersonalReputationAccessint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandPersonalReputationAccess;
// public int CNWVirtualMachineCommands::ExecuteCommandPickUpItemint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandPickUpItem;
// public int CNWVirtualMachineCommands::ExecuteCommandPlayAnimationint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandPlayAnimation;
// public int CNWVirtualMachineCommands::ExecuteCommandPlaySoundint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandPlaySound;
// public int CNWVirtualMachineCommands::ExecuteCommandPlaySoundByStrRefint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandPlaySoundByStrRef;
// public int CNWVirtualMachineCommands::ExecuteCommandPopUpGUIPanelint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandPopUpGUIPanel;
// public int CNWVirtualMachineCommands::ExecuteCommandPrintFloatint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandPrintFloat;
// public int CNWVirtualMachineCommands::ExecuteCommandPrintIntegerint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandPrintInteger;
// public int CNWVirtualMachineCommands::ExecuteCommandPrintLogEntryint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandPrintLogEntry;
// public int CNWVirtualMachineCommands::ExecuteCommandPrintObjectint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandPrintObject;
// public int CNWVirtualMachineCommands::ExecuteCommandPrintStringint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandPrintString;
// public int CNWVirtualMachineCommands::ExecuteCommandPrintVectorint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandPrintVector;
// public int CNWVirtualMachineCommands::ExecuteCommandPutDownItemint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandPutDownItem;
// public int CNWVirtualMachineCommands::ExecuteCommandRandomint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandRandom;
// public int CNWVirtualMachineCommands::ExecuteCommandRandomNameint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandRandomName;
// public int CNWVirtualMachineCommands::ExecuteCommandRecomputeStaticLightingint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandRecomputeStaticLighting;
// public int CNWVirtualMachineCommands::ExecuteCommandRemoveEffectint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandRemoveEffect;
// public int CNWVirtualMachineCommands::ExecuteCommandRemoveFromPartyint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandRemoveFromParty;
// public int CNWVirtualMachineCommands::ExecuteCommandRemoveItemPropertyint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandRemoveItemProperty;
// public int CNWVirtualMachineCommands::ExecuteCommandRemoveJournalQuestEntryint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandRemoveJournalQuestEntry;
// public int CNWVirtualMachineCommands::ExecuteCommandResistSpellint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandResistSpell;
// public int CNWVirtualMachineCommands::ExecuteCommandRestoreBaseAttackBonusint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandRestoreBaseAttackBonus;
// public int CNWVirtualMachineCommands::ExecuteCommandRestoreCameraFacingint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandRestoreCameraFacing;
// public int CNWVirtualMachineCommands::ExecuteCommandRetrieveCampaignObjectint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandRetrieveCampaignObject;
// public int CNWVirtualMachineCommands::ExecuteCommandRollDiceint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandRollDice;
// public int CNWVirtualMachineCommands::ExecuteCommandSavingThrowint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSavingThrow;
// public int CNWVirtualMachineCommands::ExecuteCommandSendMessageToAllDMsint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSendMessageToAllDMs;
// public int CNWVirtualMachineCommands::ExecuteCommandSendMessageToPCint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSendMessageToPC;
// public int CNWVirtualMachineCommands::ExecuteCommandSendMessageToPCByStrRefint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSendMessageToPCByStrRef;
// public int CNWVirtualMachineCommands::ExecuteCommandSetActionModeint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetActionMode;
// public int CNWVirtualMachineCommands::ExecuteCommandSetAILevelint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetAILevel;
// public int CNWVirtualMachineCommands::ExecuteCommandSetAreaTransitionBMPint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetAreaTransitionBMP;
// public int CNWVirtualMachineCommands::ExecuteCommandSetAssociateListenPatternsint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetAssociateListenPatterns;
// public int CNWVirtualMachineCommands::ExecuteCommandSetBaseAttackBonusint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetBaseAttackBonus;
// public int CNWVirtualMachineCommands::ExecuteCommandSetCalendarint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetCalendar;
// public int CNWVirtualMachineCommands::ExecuteCommandSetCameraHeightint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetCameraHeight;
// public int CNWVirtualMachineCommands::ExecuteCommandSetCameraLocationint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetCameraLocation;
// public int CNWVirtualMachineCommands::ExecuteCommandSetCameraModeint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetCameraMode;
// public int CNWVirtualMachineCommands::ExecuteCommandSetCampaignFloatint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetCampaignFloat;
// public int CNWVirtualMachineCommands::ExecuteCommandSetCampaignIntint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetCampaignInt;
// public int CNWVirtualMachineCommands::ExecuteCommandSetCampaignLocationint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetCampaignLocation;
// public int CNWVirtualMachineCommands::ExecuteCommandSetCampaignStringint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetCampaignString;
// public int CNWVirtualMachineCommands::ExecuteCommandSetCampaignVectorint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetCampaignVector;
// public int CNWVirtualMachineCommands::ExecuteCommandSetColorint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetColor;
// public int CNWVirtualMachineCommands::ExecuteCommandSetCommandableint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetCommandable;
// public int CNWVirtualMachineCommands::ExecuteCommandSetCreatureAppearanceTypeint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetCreatureAppearanceType;
// public int CNWVirtualMachineCommands::ExecuteCommandSetCreatureBodyPartint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetCreatureBodyPart;
// public int CNWVirtualMachineCommands::ExecuteCommandSetCreatureTailTypeint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetCreatureTailType;
// public int CNWVirtualMachineCommands::ExecuteCommandSetCreatureWingTypeint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetCreatureWingType;
// public int CNWVirtualMachineCommands::ExecuteCommandSetCustomTokenint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetCustomToken;
// public int CNWVirtualMachineCommands::ExecuteCommandSetCutsceneCameraMoveRateint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetCutsceneCameraMoveRate;
// public int CNWVirtualMachineCommands::ExecuteCommandSetCutsceneModeint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetCutsceneMode;
// public int CNWVirtualMachineCommands::ExecuteCommandSetDeityint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetDeity;
// public int CNWVirtualMachineCommands::ExecuteCommandSetDescriptionint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetDescription;
// public int CNWVirtualMachineCommands::ExecuteCommandSetDislikeint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetDislike;
// public int CNWVirtualMachineCommands::ExecuteCommandSetDroppableFlagint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetDroppableFlag;
// public int CNWVirtualMachineCommands::ExecuteCommandSetEncounterDataint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetEncounterData;
// public int CNWVirtualMachineCommands::ExecuteCommandSetFacingint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetFacing;
// public int CNWVirtualMachineCommands::ExecuteCommandSetFadeint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetFade;
// public int CNWVirtualMachineCommands::ExecuteCommandSetFogAmountint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetFogAmount;
// public int CNWVirtualMachineCommands::ExecuteCommandSetFogColorint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetFogColor;
// public int CNWVirtualMachineCommands::ExecuteCommandSetFootstepTypeint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetFootstepType;
// public int CNWVirtualMachineCommands::ExecuteCommandSetHardnessint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetHardness;
// public int CNWVirtualMachineCommands::ExecuteCommandSetIdentifiedint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetIdentified;
// public int CNWVirtualMachineCommands::ExecuteCommandSetImmortalint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetImmortal;
// public int CNWVirtualMachineCommands::ExecuteCommandSetInfiniteFlagint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetInfiniteFlag;
// public int CNWVirtualMachineCommands::ExecuteCommandSetIsDestroyableint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetIsDestroyable;
// public int CNWVirtualMachineCommands::ExecuteCommandSetItemChargesint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetItemCharges;
// public int CNWVirtualMachineCommands::ExecuteCommandSetItemCursedFlagint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetItemCursedFlag;
// public int CNWVirtualMachineCommands::ExecuteCommandSetItemStackSizeint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetItemStackSize;
// public int CNWVirtualMachineCommands::ExecuteCommandSetKeyRequiredFeedbackMessageint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetKeyRequiredFeedbackMessage;
// public int CNWVirtualMachineCommands::ExecuteCommandSetLikeint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetLike;
// public int CNWVirtualMachineCommands::ExecuteCommandSetListeningint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetListening;
// public int CNWVirtualMachineCommands::ExecuteCommandSetListenStringint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetListenString;
// public int CNWVirtualMachineCommands::ExecuteCommandSetLockedint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetLocked;
// public int CNWVirtualMachineCommands::ExecuteCommandSetLockInfoint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetLockInfo;
// public int CNWVirtualMachineCommands::ExecuteCommandSetLootableint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetLootable;
// public int CNWVirtualMachineCommands::ExecuteCommandSetMapPinEnabledint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetMapPinEnabled;
// public int CNWVirtualMachineCommands::ExecuteCommandSetMaxHenchmenint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetMaxHenchmen;
// public int CNWVirtualMachineCommands::ExecuteCommandSetNameint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetName;
// public int CNWVirtualMachineCommands::ExecuteCommandSetPanelButtonFlashint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetPanelButtonFlash;
// public int CNWVirtualMachineCommands::ExecuteCommandSetPCChatMessageint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetPCChatMessage;
// public int CNWVirtualMachineCommands::ExecuteCommandSetPCChatVolumeint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetPCChatVolume;
// public int CNWVirtualMachineCommands::ExecuteCommandSetPhenoTypeint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetPhenoType;
// public int CNWVirtualMachineCommands::ExecuteCommandSetPickpocketableFlagint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetPickpocketableFlag;
// public int CNWVirtualMachineCommands::ExecuteCommandSetPlaceableIlluminationint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetPlaceableIllumination;
// public int CNWVirtualMachineCommands::ExecuteCommandSetPlotFlagint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetPlotFlag;
// public int CNWVirtualMachineCommands::ExecuteCommandSetPortraitIdint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetPortraitId;
// public int CNWVirtualMachineCommands::ExecuteCommandSetPortraitResRefint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetPortraitResRef;
// public int CNWVirtualMachineCommands::ExecuteCommandSetSavingThrowint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetSavingThrow;
// public int CNWVirtualMachineCommands::ExecuteCommandSetSkyBoxint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetSkyBox;
// public int CNWVirtualMachineCommands::ExecuteCommandSetStolenFlagint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetStolenFlag;
// public int CNWVirtualMachineCommands::ExecuteCommandSetSubRaceint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetSubRace;
// public int CNWVirtualMachineCommands::ExecuteCommandSetSubTypeint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetSubType;
// public int CNWVirtualMachineCommands::ExecuteCommandSetTileLightColorint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetTileLightColor;
// public int CNWVirtualMachineCommands::ExecuteCommandSetTimeint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetTime;
// public int CNWVirtualMachineCommands::ExecuteCommandSetTrapInfoint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetTrapInfo;
// public int CNWVirtualMachineCommands::ExecuteCommandSetUseableFlagint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetUseableFlag;
// public int CNWVirtualMachineCommands::ExecuteCommandSetVarint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetVar;
// public int CNWVirtualMachineCommands::ExecuteCommandSetWeatherint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetWeather;
// public int CNWVirtualMachineCommands::ExecuteCommandSetXPint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetXP;
// public int CNWVirtualMachineCommands::ExecuteCommandSetXPScaleint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSetXPScale;
// public int CNWVirtualMachineCommands::ExecuteCommandSignalEventint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSignalEvent;
// public int CNWVirtualMachineCommands::ExecuteCommandSoundObjectPlayint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSoundObjectPlay;
// public int CNWVirtualMachineCommands::ExecuteCommandSoundObjectSetPositionint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSoundObjectSetPosition;
// public int CNWVirtualMachineCommands::ExecuteCommandSoundObjectSetVolumeint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSoundObjectSetVolume;
// public int CNWVirtualMachineCommands::ExecuteCommandSoundObjectStopint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSoundObjectStop;
// public int CNWVirtualMachineCommands::ExecuteCommandSpawnScriptDebuggerint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSpawnScriptDebugger;
// public int CNWVirtualMachineCommands::ExecuteCommandSpeakOneLinerConversationint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSpeakOneLinerConversation;
// public int CNWVirtualMachineCommands::ExecuteCommandSpeakStringint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSpeakString;
// public int CNWVirtualMachineCommands::ExecuteCommandSpeakStrRefint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSpeakStrRef;
// public int CNWVirtualMachineCommands::ExecuteCommandStandardFactionReputationAccessint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandStandardFactionReputationAccess;
// public int CNWVirtualMachineCommands::ExecuteCommandStartNewModuleint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandStartNewModule;
// public int CNWVirtualMachineCommands::ExecuteCommandStopFadeint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandStopFade;
// public int CNWVirtualMachineCommands::ExecuteCommandStoreCameraFacingint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandStoreCameraFacing;
// public int CNWVirtualMachineCommands::ExecuteCommandStoreCampaignObjectint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandStoreCampaignObject;
// public int CNWVirtualMachineCommands::ExecuteCommandStoreGetint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandStoreGet;
// public int CNWVirtualMachineCommands::ExecuteCommandStoreSetint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandStoreSet;
// public int CNWVirtualMachineCommands::ExecuteCommandStringConversionsint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandStringConversions;
// public int CNWVirtualMachineCommands::ExecuteCommandSummonAssociateint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSummonAssociate;
// public int CNWVirtualMachineCommands::ExecuteCommandSurrenderToEnemiesint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandSurrenderToEnemies;
// public int CNWVirtualMachineCommands::ExecuteCommandTakeGoldFromCreatureint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandTakeGoldFromCreature;
// public int CNWVirtualMachineCommands::ExecuteCommandTalentint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandTalent;
// public int CNWVirtualMachineCommands::ExecuteCommandTalentAccessint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandTalentAccess;
// public int CNWVirtualMachineCommands::ExecuteCommandTestStringint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandTestString;
// public int CNWVirtualMachineCommands::ExecuteCommandTimeConversionsint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandTimeConversions;
// public int CNWVirtualMachineCommands::ExecuteCommandUnequipItemint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandUnequipItem;
// public int CNWVirtualMachineCommands::ExecuteCommandUnpossessFamiliarint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandUnpossessFamiliar;
// public int CNWVirtualMachineCommands::ExecuteCommandVectorint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandVector;
// public int CNWVirtualMachineCommands::ExecuteCommandVectorConversionsint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandVectorConversions;
// public int CNWVirtualMachineCommands::ExecuteCommandVectorMagnitudeint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandVectorMagnitude;
// public int CNWVirtualMachineCommands::ExecuteCommandVectorNormalizeint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandVectorNormalize;
// public int CNWVirtualMachineCommands::ExecuteCommandVersusEffectint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandVersusEffect;
// public int CNWVirtualMachineCommands::ExecuteCommandVoiceChatint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandVoiceChat;
// public int CNWVirtualMachineCommands::ExecuteCommandWaitint, int
extern void * const CNWVirtualMachineCommands__ExecuteCommandWait;
// public CExoString CNWVirtualMachineCommands::GetDebuggerLabelNameint
extern void * const CNWVirtualMachineCommands__GetDebuggerLabelName;
// public void CNWVirtualMachineCommands::GetEngineStructureWatchViewint, void*, int*, CExoString**, CExoString**
extern void * const CNWVirtualMachineCommands__GetEngineStructureWatchView;
// public int CNWVirtualMachineCommands::GetEqualGameDefinedStructureint, void*, void*
extern void * const CNWVirtualMachineCommands__GetEqualGameDefinedStructure;
// public CExoString CNWVirtualMachineCommands::GetGameDefinedStructureNameint
extern void * const CNWVirtualMachineCommands__GetGameDefinedStructureName;
// public void CNWVirtualMachineCommands::GetObjectWatchViewunsigned long int, int*, CExoString**, CExoString**
extern void * const CNWVirtualMachineCommands__GetObjectWatchView;
// public C2DA* CNWVirtualMachineCommands::GetTableFromArmorPartint
extern void * const CNWVirtualMachineCommands__GetTableFromArmorPart;
// public void CNWVirtualMachineCommands::InitializeCommandsvoid
extern void * const CNWVirtualMachineCommands__InitializeCommands;
// public int CNWVirtualMachineCommands::LoadGameDefinedStructureint, void**, CResGFF*, CResStruct*
extern void * const CNWVirtualMachineCommands__LoadGameDefinedStructure;
// public void CNWVirtualMachineCommands::ReportErrorCExoString&, int
extern void * const CNWVirtualMachineCommands__ReportError;
// public void CNWVirtualMachineCommands::RunScriptCallbackCExoString&
extern void * const CNWVirtualMachineCommands__RunScriptCallback;
// public int CNWVirtualMachineCommands::SaveGameDefinedStructureint, void*, CResGFF*, CResStruct*
extern void * const CNWVirtualMachineCommands__SaveGameDefinedStructure;

// CObjectLookupTable::CObjectLookupTablevoid
extern void * const CObjectLookupTable__CObjectLookupTableCtor;
// CObjectLookupTable::~CObjectLookupTablevoid
extern void * const CObjectLookupTable__CObjectLookupTableDtor;
// void CObjectLookupTable::AddIDunsigned long int
extern void * const CObjectLookupTable__AddID;
// void CObjectLookupTable::GetIDFromIndexunsigned long int
extern void * const CObjectLookupTable__GetIDFromIndex;
// void CObjectLookupTable::GetIndexFromIDunsigned long int
extern void * const CObjectLookupTable__GetIndexFromID;
// void CObjectLookupTable::GetUpdatevoid*, unsigned long int*
extern void * const CObjectLookupTable__GetUpdate;
// void CObjectLookupTable::Touchunsigned long int
extern void * const CObjectLookupTable__Touch;
// void CObjectLookupTable::Updatevoid*, unsigned long int
extern void * const CObjectLookupTable__Update;

// public CObjectTableManager::CObjectTableManagervoid
extern void * const CObjectTableManager__CObjectTableManagerCtor;
// public CObjectTableManager::~CObjectTableManagervoid
extern void * const CObjectTableManager__CObjectTableManagerDtor;
// void CObjectTableManager::AddIDunsigned long int, unsigned long int*, unsigned long int
extern void * const CObjectTableManager__AddID;
// public void CObjectTableManager::ClearAllvoid
extern void * const CObjectTableManager__ClearAll;
// void CObjectTableManager::CreateNewPlayerunsigned long int
extern void * const CObjectTableManager__CreateNewPlayer;
// void CObjectTableManager::GetIDFromIndexunsigned long int, unsigned long int
extern void * const CObjectTableManager__GetIDFromIndex;
// void CObjectTableManager::GetIndexFromIDunsigned long int, unsigned long int
extern void * const CObjectTableManager__GetIndexFromID;
// public int CObjectTableManager::RemovePlayerunsigned long int
extern void * const CObjectTableManager__RemovePlayer;
// void CObjectTableManager::Touchunsigned long int, unsigned long int
extern void * const CObjectTableManager__Touch;

// public CPathfindInfoIntraTileSuccessors::CPathfindInfoIntraTileSuccessorsvoid
extern void * const CPathfindInfoIntraTileSuccessors__CPathfindInfoIntraTileSuccessorsCtor;

// public CPathfindInformation::CPathfindInformationvoid
extern void * const CPathfindInformation__CPathfindInformationCtor;
// public CPathfindInformation::~CPathfindInformationvoid
extern void * const CPathfindInformation__CPathfindInformationDtor;
// protected void CPathfindInformation::ComputeStepTolerancevoid
extern void * const CPathfindInformation__ComputeStepTolerance;
// public void CPathfindInformation::CreateFirstTileFValueAlternativesint
extern void * const CPathfindInformation__CreateFirstTileFValueAlternatives;
// public void CPathfindInformation::DeleteFirstTileFValueAlternativesvoid
extern void * const CPathfindInformation__DeleteFirstTileFValueAlternatives;
// public void CPathfindInformation::FlipStartEndPointsvoid
extern void * const CPathfindInformation__FlipStartEndPoints;
// public void CPathfindInformation::FlipTempEndPointsvoid
extern void * const CPathfindInformation__FlipTempEndPoints;
// public void CPathfindInformation::GetFirstTileFValueAlternativesint, int*, int*, CPathfindInfoIntraTileSuccessors**
extern void * const CPathfindInformation__GetFirstTileFValueAlternatives;
// public void CPathfindInformation::Initializevoid
extern void * const CPathfindInformation__Initialize;
// public void CPathfindInformation::ResetAtEndOfPathvoid
extern void * const CPathfindInformation__ResetAtEndOfPath;
// public void CPathfindInformation::ResetGridSearchDatavoid
extern void * const CPathfindInformation__ResetGridSearchData;
// public void CPathfindInformation::ResetInterAreaPathSearchDatavoid
extern void * const CPathfindInformation__ResetInterAreaPathSearchData;
// public void CPathfindInformation::ResetInterAreaSearchDatavoid
extern void * const CPathfindInformation__ResetInterAreaSearchData;
// public void CPathfindInformation::ResetInterTileSearchDatavoid
extern void * const CPathfindInformation__ResetInterTileSearchData;
// void CPathfindInformation::ResetIntraTileSearchDatavoid
extern void * const CPathfindInformation__ResetIntraTileSearchData;
// public void CPathfindInformation::ResetWayPointDatavoid
extern void * const CPathfindInformation__ResetWayPointData;
// public void CPathfindInformation::SetFirstTileFValueAlternativesint, int, int, CPathfindInfoIntraTileSuccessors*
extern void * const CPathfindInformation__SetFirstTileFValueAlternatives;
// public void CPathfindInformation::Shutdownvoid
extern void * const CPathfindInformation__Shutdown;

// public CRes::CResvoid
extern void * const CRes__CResCtor__0;
// public CRes::CResunsigned long int
extern void * const CRes__CResCtor__1;
// public CRes::~CResvoid
extern void * const CRes__CResDtor;
// public int CRes::CancelRequestvoid
extern void * const CRes__CancelRequest;
// public void* CRes::Demandvoid
extern void * const CRes__Demand;
// public void CRes::Dumpint
extern void * const CRes__Dump;
// public void* CRes::GetDatavoid
extern void * const CRes__GetData;
// void CRes::GetDemandsvoid
extern void * const CRes__GetDemands;
// public int CRes::GetFixedResourceDataOffsetvoid
extern void * const CRes__GetFixedResourceDataOffset;
// public int CRes::GetFixedResourceSizevoid
extern void * const CRes__GetFixedResourceSize;
// void CRes::GetIDvoid
extern void * const CRes__GetID;
// void CRes::GetRequestsvoid
extern void * const CRes__GetRequests;
// public int CRes::GetSizevoid
extern void * const CRes__GetSize;
// public int CRes::OnResourceFreedvoid
extern void * const CRes__OnResourceFreed;
// public int CRes::OnResourceServicedvoid
extern void * const CRes__OnResourceServiced;
// void CRes::ReadRawint, char*
extern void * const CRes__ReadRaw;
// public int CRes::Releasevoid
extern void * const CRes__Release;
// public int CRes::Requestvoid
extern void * const CRes__Request;
// void CRes::SetIDunsigned long int
extern void * const CRes__SetID;
// void CRes::SetPosCExoLinkedListNode*
extern void * const CRes__SetPos;

// public CRes2DA::CRes2DAvoid
extern void * const CRes2DA__CRes2DACtor;
// public CRes2DA::~CRes2DAvoid
extern void * const CRes2DA__CRes2DADtor;
// public unsigned char* CRes2DA::Get2DADataPtrvoid
extern void * const CRes2DA__Get2DADataPtr;
// void CRes2DA::Get2DAHeaderPtrvoid
extern void * const CRes2DA__Get2DAHeaderPtr;
// public unsigned long int CRes2DA::Get2DASizevoid
extern void * const CRes2DA__Get2DASize;
// void CRes2DA::IsLoadedvoid
extern void * const CRes2DA__IsLoaded;
// public int CRes2DA::OnResourceFreedvoid
extern void * const CRes2DA__OnResourceFreed;
// public int CRes2DA::OnResourceServicedvoid
extern void * const CRes2DA__OnResourceServiced;

// public CResARE::~CResAREvoid
extern void * const CResARE__CResAREDtor;

// public CResDWK::CResDWKvoid
extern void * const CResDWK__CResDWKCtor;
// public CResDWK::~CResDWKvoid
extern void * const CResDWK__CResDWKDtor;
// public unsigned char* CResDWK::GetDWKDataPtrvoid
extern void * const CResDWK__GetDWKDataPtr;
// public unsigned long int CResDWK::GetDWKSizevoid
extern void * const CResDWK__GetDWKSize;
// void CResDWK::IsLoadedvoid
extern void * const CResDWK__IsLoaded;
// public int CResDWK::OnResourceFreedvoid
extern void * const CResDWK__OnResourceFreed;
// public int CResDWK::OnResourceServicedvoid
extern void * const CResDWK__OnResourceServiced;

// public CResGFF::CResGFFunsigned short int, char*, const CResRef&
extern void * const CResGFF__CResGFFCtor__0;
// public CResGFF::CResGFFvoid
extern void * const CResGFF__CResGFFCtor__1;
// public CResGFF::~CResGFFvoid
extern void * const CResGFF__CResGFFDtor;
// protected unsigned char* CResGFF::AddDataFieldunsigned long int, unsigned long int, unsigned long int
extern void * const CResGFF__AddDataField;
// protected unsigned char* CResGFF::AddDataLayoutFieldunsigned long int, unsigned long int, unsigned long int
extern void * const CResGFF__AddDataLayoutField;
// protected unsigned char* CResGFF::AddDataLayoutListunsigned long int, unsigned long int, unsigned long int
extern void * const CResGFF__AddDataLayoutList;
// protected CResGFFField* CResGFF::AddFieldCResStruct*, char*, unsigned long int
extern void * const CResGFF__AddField;
// protected unsigned long int CResGFF::AddLabelchar*
extern void * const CResGFF__AddLabel;
// public int CResGFF::AddListCResList*, CResStruct*, char*
extern void * const CResGFF__AddList;
// public int CResGFF::AddListElementCResStruct*, CResList*, unsigned long int
extern void * const CResGFF__AddListElement;
// protected unsigned long int CResGFF::AddStructunsigned long int
extern void * const CResGFF__AddStruct;
// public int CResGFF::AddStructToStructCResStruct*, CResStruct*, char*, unsigned long int
extern void * const CResGFF__AddStructToStruct;
// public int CResGFF::CreateGFFFileCResStruct*, const CExoString&, const CExoString&
extern void * const CResGFF__CreateGFFFile;
// void CResGFF::GetDataFieldCResGFFField*, unsigned long int&
extern void * const CResGFF__GetDataField;
// void CResGFF::GetDataFieldNumvoid
extern void * const CResGFF__GetDataFieldNum;
// public int CResGFF::GetDataFromPointervoid*, int
extern void * const CResGFF__GetDataFromPointer;
// void CResGFF::GetDataLayoutFieldCResGFFField*, unsigned long int&
extern void * const CResGFF__GetDataLayoutField;
// void CResGFF::GetDataLayoutFieldNumvoid
extern void * const CResGFF__GetDataLayoutFieldNum;
// void CResGFF::GetDataLayoutListCResGFFField*, unsigned long int&
extern void * const CResGFF__GetDataLayoutList;
// void CResGFF::GetDataLayoutListNumvoid
extern void * const CResGFF__GetDataLayoutListNum;
// public unsigned long int CResGFF::GetElementTypeCResStruct*
extern void * const CResGFF__GetElementType;
// protected CResGFFField* CResGFF::GetFieldCResStruct*, unsigned long int
extern void * const CResGFF__GetField__0;
// protected CResGFFField* CResGFF::GetFieldCResGFFStruct*, unsigned long int
extern void * const CResGFF__GetField__1;
// protected unsigned long int CResGFF::GetFieldByLabelCResStruct*, char*
extern void * const CResGFF__GetFieldByLabel;
// public unsigned long int CResGFF::GetFieldCountCResGFFStruct*
extern void * const CResGFF__GetFieldCount__0;
// public unsigned long int CResGFF::GetFieldCountCResStruct*
extern void * const CResGFF__GetFieldCount__1;
// void CResGFF::GetFieldLabelCResStruct*, unsigned long int
extern void * const CResGFF__GetFieldLabel;
// void CResGFF::GetFieldNumvoid
extern void * const CResGFF__GetFieldNum;
// void CResGFF::GetFieldSizeCResStruct*, char*, unsigned long int
extern void * const CResGFF__GetFieldSize;
// void CResGFF::GetFieldStringIDCResStruct*, unsigned long int
extern void * const CResGFF__GetFieldStringID;
// void CResGFF::GetFieldTypeCResStruct*, char*, unsigned long int
extern void * const CResGFF__GetFieldType;
// void CResGFF::GetFileDatachar*
extern void * const CResGFF__GetFileData;
// public void CResGFF::GetGFFFileInfoCExoString*, CExoString*
extern void * const CResGFF__GetGFFFileInfo;
// void CResGFF::GetLabelCResStruct*, unsigned long int
extern void * const CResGFF__GetLabel;
// void CResGFF::GetLabelNumvoid
extern void * const CResGFF__GetLabelNum;
// public int CResGFF::GetListCResList*, CResStruct*, char*
extern void * const CResGFF__GetList;
// public unsigned long int CResGFF::GetListCountCResList*
extern void * const CResGFF__GetListCount;
// public int CResGFF::GetListElementCResStruct*, CResList*, unsigned long int
extern void * const CResGFF__GetListElement;
// void CResGFF::GetStructCResStruct*
extern void * const CResGFF__GetStruct;
// public int CResGFF::GetStructFromStructCResStruct*, CResStruct*, char*
extern void * const CResGFF__GetStructFromStruct;
// void CResGFF::GetStructNumvoid
extern void * const CResGFF__GetStructNum;
// public int CResGFF::GetTopLevelStructCResStruct*
extern void * const CResGFF__GetTopLevelStruct;
// public unsigned long int CResGFF::GetTotalSizevoid
extern void * const CResGFF__GetTotalSize;
// void CResGFF::GetWastedFieldSpacevoid
extern void * const CResGFF__GetWastedFieldSpace;
// void CResGFF::GetWastedListSpacevoid
extern void * const CResGFF__GetWastedListSpace;
// protected void CResGFF::InitializeForWritingvoid
extern void * const CResGFF__InitializeForWriting;
// void CResGFF::IsDataInPlaceunsigned long int
extern void * const CResGFF__IsDataInPlace;
// void CResGFF::IsLoadedvoid
extern void * const CResGFF__IsLoaded;
// public int CResGFF::OnResourceFreedvoid
extern void * const CResGFF__OnResourceFreed;
// public int CResGFF::OnResourceServicedvoid
extern void * const CResGFF__OnResourceServiced;
// public void CResGFF::Packunsigned char, unsigned long int
extern void * const CResGFF__Pack;
// public unsigned char CResGFF::ReadFieldBYTECResStruct*, char*, int&, unsigned char
extern void * const CResGFF__ReadFieldBYTE;
// public CExoLocString CResGFF::ReadFieldCExoLocStringCResStruct*, char*, int&, const CExoLocString&
extern void * const CResGFF__ReadFieldCExoLocString;
// public CExoString CResGFF::ReadFieldCExoStringCResStruct*, char*, int&, const CExoString&
extern void * const CResGFF__ReadFieldCExoString;
// public char CResGFF::ReadFieldCHARCResStruct*, char*, int&, char
extern void * const CResGFF__ReadFieldCHAR;
// public CResRef CResGFF::ReadFieldCResRefCResStruct*, char*, int&, const CResRef&
extern void * const CResGFF__ReadFieldCResRef;
// void CResGFF::ReadFieldDOUBLECResStruct*, char*, int&, double
extern void * const CResGFF__ReadFieldDOUBLE;
// public unsigned long int CResGFF::ReadFieldDWORDCResStruct*, char*, int&, unsigned long int
extern void * const CResGFF__ReadFieldDWORD;
// public unsigned__int64 CResGFF::ReadFieldDWORD64CResStruct*, char*, int&, unsigned long long int
extern void * const CResGFF__ReadFieldDWORD64;
// public float CResGFF::ReadFieldFLOATCResStruct*, char*, int&, float
extern void * const CResGFF__ReadFieldFLOAT;
// public int CResGFF::ReadFieldINTCResStruct*, char*, int&, int
extern void * const CResGFF__ReadFieldINT;
// void CResGFF::ReadFieldINT64CResStruct*, char*, int&, long long
extern void * const CResGFF__ReadFieldINT64;
// public short int CResGFF::ReadFieldSHORTCResStruct*, char*, int&, short int
extern void * const CResGFF__ReadFieldSHORT;
// public void* CResGFF::ReadFieldVOIDCResStruct*, void*, unsigned long int, char*, int&, void*
extern void * const CResGFF__ReadFieldVOID;
// public unsigned short int CResGFF::ReadFieldWORDCResStruct*, char*, int&, unsigned short int
extern void * const CResGFF__ReadFieldWORD;
// protected void CResGFF::ReleaseResourcevoid
extern void * const CResGFF__ReleaseResource;
// void CResGFF::SetFileTypechar*
extern void * const CResGFF__SetFileType;
// void CResGFF::SetReplaceExistingFieldsint
extern void * const CResGFF__SetReplaceExistingFields;
// public int CResGFF::WriteFieldBYTECResStruct*, unsigned char, char*
extern void * const CResGFF__WriteFieldBYTE;
// public int CResGFF::WriteFieldCExoLocStringCResStruct*, CExoLocString, char*
extern void * const CResGFF__WriteFieldCExoLocString;
// public int CResGFF::WriteFieldCExoStringCResStruct*, const CExoString&, char*
extern void * const CResGFF__WriteFieldCExoString;
// public int CResGFF::WriteFieldCHARCResStruct*, char, char*
extern void * const CResGFF__WriteFieldCHAR;
// public int CResGFF::WriteFieldCResRefCResStruct*, const CResRef&, char*
extern void * const CResGFF__WriteFieldCResRef;
// void CResGFF::WriteFieldDOUBLECResStruct*, double, char*
extern void * const CResGFF__WriteFieldDOUBLE;
// public int CResGFF::WriteFieldDWORDCResStruct*, unsigned long int, char*
extern void * const CResGFF__WriteFieldDWORD;
// public int CResGFF::WriteFieldDWORD64CResStruct*, unsigned long long int, char*
extern void * const CResGFF__WriteFieldDWORD64;
// public int CResGFF::WriteFieldFLOATCResStruct*, float, char*
extern void * const CResGFF__WriteFieldFLOAT;
// public int CResGFF::WriteFieldINTCResStruct*, int, char*
extern void * const CResGFF__WriteFieldINT;
// void CResGFF::WriteFieldINT64CResStruct*, long long, char*
extern void * const CResGFF__WriteFieldINT64;
// public int CResGFF::WriteFieldSHORTCResStruct*, short int, char*
extern void * const CResGFF__WriteFieldSHORT;
// public int CResGFF::WriteFieldVOIDCResStruct*, const void*, unsigned long int, char*
extern void * const CResGFF__WriteFieldVOID;
// public int CResGFF::WriteFieldWORDCResStruct*, unsigned short int, char*
extern void * const CResGFF__WriteFieldWORD;
// public int CResGFF::WriteGFFDataCExoFile&, unsigned long int&
extern void * const CResGFF__WriteGFFData;
// public int CResGFF::WriteGFFFilechar*
extern void * const CResGFF__WriteGFFFile__0;
// public int CResGFF::WriteGFFFileconst CExoString&, unsigned short int
extern void * const CResGFF__WriteGFFFile__1;
// public int CResGFF::WriteGFFToPointervoid**, int&
extern void * const CResGFF__WriteGFFToPointer;

// public unsigned long int CResGFFFieldIDHash::Hashconst char*, unsigned long int
extern void * const CResGFFFieldIDHash__Hash;
// public void CResGFFFieldIDHash::Initializevoid
extern void * const CResGFFFieldIDHash__Initialize;

// public CResIFO::~CResIFOvoid
extern void * const CResIFO__CResIFODtor;

// public CResLTR::CResLTRvoid
extern void * const CResLTR__CResLTRCtor;
// public CResLTR::~CResLTRvoid
extern void * const CResLTR__CResLTRDtor;
// void CResLTR::GetEndDoubleLetterProbvoid
extern void * const CResLTR__GetEndDoubleLetterProb;
// void CResLTR::GetEndSingleLetterProbvoid
extern void * const CResLTR__GetEndSingleLetterProb;
// void CResLTR::GetEndTripleLetterProbvoid
extern void * const CResLTR__GetEndTripleLetterProb;
// void CResLTR::GetLTRHeaderPtrvoid
extern void * const CResLTR__GetLTRHeaderPtr;
// void CResLTR::GetMiddleDoubleLetterProbvoid
extern void * const CResLTR__GetMiddleDoubleLetterProb;
// void CResLTR::GetMiddleSingleLetterProbvoid
extern void * const CResLTR__GetMiddleSingleLetterProb;
// void CResLTR::GetMiddleTripleLetterProbvoid
extern void * const CResLTR__GetMiddleTripleLetterProb;
// void CResLTR::GetStartDoubleLetterProbvoid
extern void * const CResLTR__GetStartDoubleLetterProb;
// void CResLTR::GetStartSingleLetterProbvoid
extern void * const CResLTR__GetStartSingleLetterProb;
// void CResLTR::GetStartTripleLetterProbvoid
extern void * const CResLTR__GetStartTripleLetterProb;
// public int CResLTR::OnResourceFreedvoid
extern void * const CResLTR__OnResourceFreed;
// public int CResLTR::OnResourceServicedvoid
extern void * const CResLTR__OnResourceServiced;

// public CResNCS::CResNCSvoid
extern void * const CResNCS__CResNCSCtor;
// public CResNCS::~CResNCSvoid
extern void * const CResNCS__CResNCSDtor;
// public unsigned char* CResNCS::GetNCSDataPtrvoid
extern void * const CResNCS__GetNCSDataPtr;
// public unsigned long int CResNCS::GetNCSSizevoid
extern void * const CResNCS__GetNCSSize;
// void CResNCS::IsLoadedvoid
extern void * const CResNCS__IsLoaded;
// public int CResNCS::OnResourceFreedvoid
extern void * const CResNCS__OnResourceFreed;
// public int CResNCS::OnResourceServicedvoid
extern void * const CResNCS__OnResourceServiced;

// public CResNDB::CResNDBvoid
extern void * const CResNDB__CResNDBCtor;
// public CResNDB::~CResNDBvoid
extern void * const CResNDB__CResNDBDtor;
// public unsigned char* CResNDB::GetNDBDataPtrvoid
extern void * const CResNDB__GetNDBDataPtr;
// public unsigned long int CResNDB::GetNDBSizevoid
extern void * const CResNDB__GetNDBSize;
// void CResNDB::IsLoadedvoid
extern void * const CResNDB__IsLoaded;
// public int CResNDB::OnResourceFreedvoid
extern void * const CResNDB__OnResourceFreed;
// public int CResNDB::OnResourceServicedvoid
extern void * const CResNDB__OnResourceServiced;

// public CResNSS::CResNSSvoid
extern void * const CResNSS__CResNSSCtor;
// public CResNSS::~CResNSSvoid
extern void * const CResNSS__CResNSSDtor;
// public unsigned char* CResNSS::GetNSSDataPtrvoid
extern void * const CResNSS__GetNSSDataPtr;
// public unsigned long int CResNSS::GetNSSSizevoid
extern void * const CResNSS__GetNSSSize;
// void CResNSS::IsLoadedvoid
extern void * const CResNSS__IsLoaded;
// public int CResNSS::OnResourceFreedvoid
extern void * const CResNSS__OnResourceFreed;
// public int CResNSS::OnResourceServicedvoid
extern void * const CResNSS__OnResourceServiced;

// public CResPWK::CResPWKvoid
extern void * const CResPWK__CResPWKCtor;
// public CResPWK::~CResPWKvoid
extern void * const CResPWK__CResPWKDtor;
// public unsigned char* CResPWK::GetPWKDataPtrvoid
extern void * const CResPWK__GetPWKDataPtr;
// public unsigned long int CResPWK::GetPWKSizevoid
extern void * const CResPWK__GetPWKSize;
// void CResPWK::IsLoadedvoid
extern void * const CResPWK__IsLoaded;
// public int CResPWK::OnResourceFreedvoid
extern void * const CResPWK__OnResourceFreed;
// public int CResPWK::OnResourceServicedvoid
extern void * const CResPWK__OnResourceServiced;

// public CResRef::CResRefvoid
extern void * const CResRef__CResRefCtor__0;
// public CResRef::CResRefconst CExoString&
extern void * const CResRef__CResRefCtor__1;
// public CResRef::CResRefchar*
extern void * const CResRef__CResRefCtor__2;
// public CResRef::CResRefunsigned char*
extern void * const CResRef__CResRefCtor__3;
// public CResRef::CResRefunsigned char*, unsigned char
extern void * const CResRef__CResRefCtor__4;
// void CResRef::__aplconst CExoString&
extern void * const CResRef____apl;
// void CResRef::__asconst CExoString&
extern void * const CResRef____as__0;
// void CResRef::__asconst CResRef&
extern void * const CResRef____as__1;
// void CResRef::__asunsigned char*
extern void * const CResRef____as__2;
// void CResRef::__aschar*
extern void * const CResRef____as__3;
// void CResRef::__eqchar* const
extern void * const CResRef____eq__0;
// void CResRef::__eqconst CResRef& const
extern void * const CResRef____eq__1;
// void CResRef::__eqconst CExoString& const
extern void * const CResRef____eq__2;
// void CResRef::__nechar* const
extern void * const CResRef____ne__0;
// void CResRef::__neconst CResRef& const
extern void * const CResRef____ne__1;
// void CResRef::__neconst CExoString& const
extern void * const CResRef____ne__2;
// void CResRef::__ntvoid
extern void * const CResRef____nt;
// public void CResRef::CopyToStringCExoString& const
extern void * const CResRef__CopyToString__0;
// public void CResRef::CopyToStringchar* const
extern void * const CResRef__CopyToString__1;
// public unsigned char CResRef::GetLengthvoid const
extern void * const CResRef__GetLength;
// public char* CResRef::GetResRefvoid const
extern void * const CResRef__GetResRef__0;
// public char* CResRef::GetResRefunsigned char* const
extern void * const CResRef__GetResRef__1;
// public char* CResRef::GetResRefStrvoid const
extern void * const CResRef__GetResRefStr;
// void CResRef::IsValidvoid const
extern void * const CResRef__IsValid;

// public CResSET::CResSETvoid
extern void * const CResSET__CResSETCtor;
// public CResSET::~CResSETvoid
extern void * const CResSET__CResSETDtor;
// void CResSET::CopySETDataunsigned char*
extern void * const CResSET__CopySETData;
// public int CResSET::CreateSectionTablevoid
extern void * const CResSET__CreateSectionTable;
// void CResSET::GetNextLineunsigned long int, unsigned long int*
extern void * const CResSET__GetNextLine;
// public void CResSET::GetSectionEntryValuechar*, char*, char*
extern void * const CResSET__GetSectionEntryValue;
// void CResSET::GetSETDataPtrvoid
extern void * const CResSET__GetSETDataPtr;
// void CResSET::GetSETSizevoid
extern void * const CResSET__GetSETSize;
// void CResSET::IsLoadedvoid
extern void * const CResSET__IsLoaded;
// public int CResSET::OnResourceFreedvoid
extern void * const CResSET__OnResourceFreed;
// public int CResSET::OnResourceServicedvoid
extern void * const CResSET__OnResourceServiced;
// void CResSET::SkipWhiteSpacechar*
extern void * const CResSET__SkipWhiteSpace;

// public CResTGA::CResTGAvoid
extern void * const CResTGA__CResTGACtor;
// public CResTGA::~CResTGAvoid
extern void * const CResTGA__CResTGADtor;
// void CResTGA::CopyTGADataunsigned char*
extern void * const CResTGA__CopyTGAData;
// void CResTGA::GetTGAAttribunsigned long int*, unsigned long int*, unsigned char*
extern void * const CResTGA__GetTGAAttrib;
// void CResTGA::GetTGAColorMapPtrvoid
extern void * const CResTGA__GetTGAColorMapPtr;
// void CResTGA::GetTGADataPtrvoid
extern void * const CResTGA__GetTGADataPtr;
// void CResTGA::GetTGAHeaderPtrvoid
extern void * const CResTGA__GetTGAHeaderPtr;
// void CResTGA::GetTGASizevoid
extern void * const CResTGA__GetTGASize;
// void CResTGA::IsColorMappedvoid
extern void * const CResTGA__IsColorMapped;
// void CResTGA::IsCompressedvoid
extern void * const CResTGA__IsCompressed;
// void CResTGA::IsLoadedvoid
extern void * const CResTGA__IsLoaded;
// public int CResTGA::OnResourceFreedvoid
extern void * const CResTGA__OnResourceFreed;
// public int CResTGA::OnResourceServicedvoid
extern void * const CResTGA__OnResourceServiced;
// private int CResTGA::ReadColorMappedRLETGAvoid
extern void * const CResTGA__ReadColorMappedRLETGA;
// private int CResTGA::ReadUnmappedRLETGAvoid
extern void * const CResTGA__ReadUnmappedRLETGA;
// public int CResTGA::WriteCExoString&
extern void * const CResTGA__Write;

// public CResWOK::CResWOKvoid
extern void * const CResWOK__CResWOKCtor;
// public CResWOK::~CResWOKvoid
extern void * const CResWOK__CResWOKDtor;
// public unsigned char* CResWOK::GetWOKDataPtrvoid
extern void * const CResWOK__GetWOKDataPtr;
// public unsigned long int CResWOK::GetWOKSizevoid
extern void * const CResWOK__GetWOKSize;
// void CResWOK::IsLoadedvoid
extern void * const CResWOK__IsLoaded;
// public int CResWOK::OnResourceFreedvoid
extern void * const CResWOK__OnResourceFreed;
// public int CResWOK::OnResourceServicedvoid
extern void * const CResWOK__OnResourceServiced;

// CScriptCompiler::CScriptCompilervoid
extern void * const CScriptCompiler__CScriptCompilerCtor;
// CScriptCompiler::~CScriptCompilervoid
extern void * const CScriptCompiler__CScriptCompilerDtor;
// void CScriptCompiler::AddStructureToStackconst CExoString&, int
extern void * const CScriptCompiler__AddStructureToStack;
// void CScriptCompiler::AddSymbolToLabelListint, int, int, int
extern void * const CScriptCompiler__AddSymbolToLabelList;
// void CScriptCompiler::AddSymbolToQueryListint, int, int, int
extern void * const CScriptCompiler__AddSymbolToQueryList;
// void CScriptCompiler::AddToGlobalVariableListCScriptParseTreeNode*
extern void * const CScriptCompiler__AddToGlobalVariableList;
// void CScriptCompiler::AddToSymbolTableVarStackint, int, int
extern void * const CScriptCompiler__AddToSymbolTableVarStack;
// void CScriptCompiler::AddUserDefinedIdentifierCScriptParseTreeNode*, int
extern void * const CScriptCompiler__AddUserDefinedIdentifier;
// void CScriptCompiler::AddVariableToStackint, CExoString*, int
extern void * const CScriptCompiler__AddVariableToStack;
// void CScriptCompiler::CheckForBadLValueCScriptParseTreeNode*
extern void * const CScriptCompiler__CheckForBadLValue;
// void CScriptCompiler::CleanUpAfterCompileint, CScriptParseTreeNode*
extern void * const CScriptCompiler__CleanUpAfterCompile;
// void CScriptCompiler::CleanUpAfterCompilesvoid
extern void * const CScriptCompiler__CleanUpAfterCompiles;
// void CScriptCompiler::CleanUpDuringCompileint
extern void * const CScriptCompiler__CleanUpDuringCompile;
// void CScriptCompiler::ClearAllSymbolListsvoid
extern void * const CScriptCompiler__ClearAllSymbolLists;
// void CScriptCompiler::ClearCompiledScriptCodevoid
extern void * const CScriptCompiler__ClearCompiledScriptCode;
// void CScriptCompiler::ClearSwitchLabelListvoid
extern void * const CScriptCompiler__ClearSwitchLabelList;
// void CScriptCompiler::ClearUserDefinedIdentifiersvoid
extern void * const CScriptCompiler__ClearUserDefinedIdentifiers;
// void CScriptCompiler::CompileFileconst CExoString&
extern void * const CScriptCompiler__CompileFile;
// void CScriptCompiler::CompileScriptChunkconst CExoString&
extern void * const CScriptCompiler__CompileScriptChunk;
// void CScriptCompiler::CompileScriptConditionalconst CExoString&
extern void * const CScriptCompiler__CompileScriptConditional;
// void CScriptCompiler::CreateScriptParseTreeNodeint, CScriptParseTreeNode*, CScriptParseTreeNode*
extern void * const CScriptCompiler__CreateScriptParseTreeNode;
// void CScriptCompiler::DeleteCompileStackvoid
extern void * const CScriptCompiler__DeleteCompileStack;
// void CScriptCompiler::DeleteParseTreeint, CScriptParseTreeNode*
extern void * const CScriptCompiler__DeleteParseTree;
// void CScriptCompiler::DeleteScriptParseTreeNodeCScriptParseTreeNode*
extern void * const CScriptCompiler__DeleteScriptParseTreeNode;
// void CScriptCompiler::DetermineLocationOfCodevoid
extern void * const CScriptCompiler__DetermineLocationOfCode;
// void CScriptCompiler::DuplicateScriptParseTreeCScriptParseTreeNode*
extern void * const CScriptCompiler__DuplicateScriptParseTree;
// void CScriptCompiler::EndLineNumberAtBinaryInstructionint, int, int
extern void * const CScriptCompiler__EndLineNumberAtBinaryInstruction;
// void CScriptCompiler::FinalizeFinalCodevoid
extern void * const CScriptCompiler__FinalizeFinalCode;
// void CScriptCompiler::FoundReturnStatementOnAllBranchesCScriptParseTreeNode*
extern void * const CScriptCompiler__FoundReturnStatementOnAllBranches;
// void CScriptCompiler::GenerateCodeForSwitchLabelsCScriptParseTreeNode*
extern void * const CScriptCompiler__GenerateCodeForSwitchLabels;
// void CScriptCompiler::GenerateDebuggerTypeAbbreviationint, CExoString
extern void * const CScriptCompiler__GenerateDebuggerTypeAbbreviation;
// void CScriptCompiler::GenerateFinalCodeFromParseTreeCExoString
extern void * const CScriptCompiler__GenerateFinalCodeFromParseTree;
// void CScriptCompiler::GenerateIdentifierListvoid
extern void * const CScriptCompiler__GenerateIdentifierList;
// void CScriptCompiler::GenerateIdentifiersFromConstantVariablesCScriptParseTreeNode*
extern void * const CScriptCompiler__GenerateIdentifiersFromConstantVariables;
// void CScriptCompiler::GenerateParseTreevoid
extern void * const CScriptCompiler__GenerateParseTree;
// void CScriptCompiler::GetCompiledScriptCodechar**, int*
extern void * const CScriptCompiler__GetCompiledScriptCode;
// void CScriptCompiler::GetFunctionNameFromSymbolSubTypesint, int
extern void * const CScriptCompiler__GetFunctionNameFromSymbolSubTypes;
// void CScriptCompiler::GetHashEntryByNameconst char*
extern void * const CScriptCompiler__GetHashEntryByName;
// void CScriptCompiler::GetIdentifierByNameconst CExoString&
extern void * const CScriptCompiler__GetIdentifierByName;
// void CScriptCompiler::GetNewScriptParseTreeNodevoid
extern void * const CScriptCompiler__GetNewScriptParseTreeNode;
// void CScriptCompiler::GetStructureFieldconst CExoString&, const CExoString&
extern void * const CScriptCompiler__GetStructureField;
// void CScriptCompiler::GetStructureSizeconst CExoString&
extern void * const CScriptCompiler__GetStructureSize;
// void CScriptCompiler::HandleIdentifierTokenvoid
extern void * const CScriptCompiler__HandleIdentifierToken;
// void CScriptCompiler::HandleTokenvoid
extern void * const CScriptCompiler__HandleToken;
// void CScriptCompiler::HashManagerAddunsigned long int, unsigned long int
extern void * const CScriptCompiler__HashManagerAdd;
// void CScriptCompiler::HashManagerDeleteunsigned long int, unsigned long int
extern void * const CScriptCompiler__HashManagerDelete;
// void CScriptCompiler::HashStringconst char*
extern void * const CScriptCompiler__HashString__0;
// void CScriptCompiler::HashStringconst CExoString&
extern void * const CScriptCompiler__HashString__1;
// void CScriptCompiler::Initializevoid
extern void * const CScriptCompiler__Initialize;
// void CScriptCompiler::InitializeFinalCodevoid
extern void * const CScriptCompiler__InitializeFinalCode;
// void CScriptCompiler::InitializeIncludeFileint
extern void * const CScriptCompiler__InitializeIncludeFile;
// void CScriptCompiler::InitializePreDefinedStructuresvoid
extern void * const CScriptCompiler__InitializePreDefinedStructures;
// void CScriptCompiler::InitializeSwitchLabelListvoid
extern void * const CScriptCompiler__InitializeSwitchLabelList;
// void CScriptCompiler::InsertGlobalVariablesInParseTreeCScriptParseTreeNode*
extern void * const CScriptCompiler__InsertGlobalVariablesInParseTree;
// void CScriptCompiler::InstallLoadervoid
extern void * const CScriptCompiler__InstallLoader;
// void CScriptCompiler::InVisitGenerateCodeCScriptParseTreeNode*
extern void * const CScriptCompiler__InVisitGenerateCode;
// void CScriptCompiler::ModifySRStackReturnTreeCScriptParseTreeNode*
extern void * const CScriptCompiler__ModifySRStackReturnTree;
// void CScriptCompiler::OutputErrorint, CExoString*, int, const CExoString&
extern void * const CScriptCompiler__OutputError;
// void CScriptCompiler::OutputIdentifierErrorconst CExoString&, int, int
extern void * const CScriptCompiler__OutputIdentifierError;
// void CScriptCompiler::OutputWalkTreeErrorint, CScriptParseTreeNode*
extern void * const CScriptCompiler__OutputWalkTreeError;
// void CScriptCompiler::ParseCharacterAlphabetint
extern void * const CScriptCompiler__ParseCharacterAlphabet;
// void CScriptCompiler::ParseCharacterAmpersandint
extern void * const CScriptCompiler__ParseCharacterAmpersand;
// void CScriptCompiler::ParseCharacterAsteriskint
extern void * const CScriptCompiler__ParseCharacterAsterisk;
// void CScriptCompiler::ParseCharacterCaratint
extern void * const CScriptCompiler__ParseCharacterCarat;
// void CScriptCompiler::ParseCharacterColonvoid
extern void * const CScriptCompiler__ParseCharacterColon;
// void CScriptCompiler::ParseCharacterCommavoid
extern void * const CScriptCompiler__ParseCharacterComma;
// void CScriptCompiler::ParseCharacterEllipsisvoid
extern void * const CScriptCompiler__ParseCharacterEllipsis;
// void CScriptCompiler::ParseCharacterEqualSignint
extern void * const CScriptCompiler__ParseCharacterEqualSign;
// void CScriptCompiler::ParseCharacterExclamationPointint
extern void * const CScriptCompiler__ParseCharacterExclamationPoint;
// void CScriptCompiler::ParseCharacterHyphenint
extern void * const CScriptCompiler__ParseCharacterHyphen;
// void CScriptCompiler::ParseCharacterLeftAngleint
extern void * const CScriptCompiler__ParseCharacterLeftAngle;
// void CScriptCompiler::ParseCharacterLeftBracevoid
extern void * const CScriptCompiler__ParseCharacterLeftBrace;
// void CScriptCompiler::ParseCharacterLeftBracketvoid
extern void * const CScriptCompiler__ParseCharacterLeftBracket;
// void CScriptCompiler::ParseCharacterLeftSquareBracketvoid
extern void * const CScriptCompiler__ParseCharacterLeftSquareBracket;
// void CScriptCompiler::ParseCharacterNumericint
extern void * const CScriptCompiler__ParseCharacterNumeric;
// void CScriptCompiler::ParseCharacterPercentSignint
extern void * const CScriptCompiler__ParseCharacterPercentSign;
// void CScriptCompiler::ParseCharacterPeriodvoid
extern void * const CScriptCompiler__ParseCharacterPeriod;
// void CScriptCompiler::ParseCharacterPlusSignint
extern void * const CScriptCompiler__ParseCharacterPlusSign;
// void CScriptCompiler::ParseCharacterQuestionMarkvoid
extern void * const CScriptCompiler__ParseCharacterQuestionMark;
// void CScriptCompiler::ParseCharacterQuotationMarkvoid
extern void * const CScriptCompiler__ParseCharacterQuotationMark;
// void CScriptCompiler::ParseCharacterRightAngleint
extern void * const CScriptCompiler__ParseCharacterRightAngle;
// void CScriptCompiler::ParseCharacterRightBracevoid
extern void * const CScriptCompiler__ParseCharacterRightBrace;
// void CScriptCompiler::ParseCharacterRightBracketvoid
extern void * const CScriptCompiler__ParseCharacterRightBracket;
// void CScriptCompiler::ParseCharacterRightSquareBracketvoid
extern void * const CScriptCompiler__ParseCharacterRightSquareBracket;
// void CScriptCompiler::ParseCharacterSemicolonvoid
extern void * const CScriptCompiler__ParseCharacterSemicolon;
// void CScriptCompiler::ParseCharacterSlashint
extern void * const CScriptCompiler__ParseCharacterSlash;
// void CScriptCompiler::ParseCharacterTildevoid
extern void * const CScriptCompiler__ParseCharacterTilde;
// void CScriptCompiler::ParseCharacterVerticalBarint
extern void * const CScriptCompiler__ParseCharacterVerticalBar;
// void CScriptCompiler::ParseCommentedOutCharacterint
extern void * const CScriptCompiler__ParseCommentedOutCharacter;
// void CScriptCompiler::ParseFloatFromTokenStringvoid
extern void * const CScriptCompiler__ParseFloatFromTokenString;
// void CScriptCompiler::ParseIdentifierFilevoid
extern void * const CScriptCompiler__ParseIdentifierFile;
// void CScriptCompiler::ParseNextCharacterint, int
extern void * const CScriptCompiler__ParseNextCharacter;
// void CScriptCompiler::ParseSourcechar*, int
extern void * const CScriptCompiler__ParseSource;
// void CScriptCompiler::ParseStringCharacterint, int
extern void * const CScriptCompiler__ParseStringCharacter;
// void CScriptCompiler::PopSRStackint*, int*, int*, CScriptParseTreeNode**, CScriptParseTreeNode**
extern void * const CScriptCompiler__PopSRStack;
// void CScriptCompiler::PostVisitGenerateCodeCScriptParseTreeNode*
extern void * const CScriptCompiler__PostVisitGenerateCode;
// void CScriptCompiler::PreVisitGenerateCodeCScriptParseTreeNode*
extern void * const CScriptCompiler__PreVisitGenerateCode;
// void CScriptCompiler::PrintBinaryAddressvoid
extern void * const CScriptCompiler__PrintBinaryAddress;
// void CScriptCompiler::PrintParseIdentifierFileErrorint
extern void * const CScriptCompiler__PrintParseIdentifierFileError;
// void CScriptCompiler::PrintParseSourceErrorint
extern void * const CScriptCompiler__PrintParseSourceError;
// void CScriptCompiler::PushSRStackint, int, int, CScriptParseTreeNode*
extern void * const CScriptCompiler__PushSRStack;
// void CScriptCompiler::RemoveFromSymbolTableVarStackint, int, int
extern void * const CScriptCompiler__RemoveFromSymbolTableVarStack;
// void CScriptCompiler::ResolveDebuggingInformationvoid
extern void * const CScriptCompiler__ResolveDebuggingInformation;
// void CScriptCompiler::ResolveDebuggingInformationForIdentifierint
extern void * const CScriptCompiler__ResolveDebuggingInformationForIdentifier;
// void CScriptCompiler::ResolveLabelsvoid
extern void * const CScriptCompiler__ResolveLabels;
// void CScriptCompiler::SetAutomaticCleanUpAfterCompilesint
extern void * const CScriptCompiler__SetAutomaticCleanUpAfterCompiles;
// void CScriptCompiler::SetCompileConditionalFileint
extern void * const CScriptCompiler__SetCompileConditionalFile;
// void CScriptCompiler::SetCompileConditionalOrMainint
extern void * const CScriptCompiler__SetCompileConditionalOrMain;
// void CScriptCompiler::SetCompileDebugLevelint
extern void * const CScriptCompiler__SetCompileDebugLevel;
// void CScriptCompiler::SetCompileSymbolicOutputint
extern void * const CScriptCompiler__SetCompileSymbolicOutput;
// void CScriptCompiler::SetGenerateDebuggerOutputint
extern void * const CScriptCompiler__SetGenerateDebuggerOutput;
// void CScriptCompiler::SetIdentifierSpecificationconst CExoString&
extern void * const CScriptCompiler__SetIdentifierSpecification;
// void CScriptCompiler::SetOptimizeBinaryCodeLengthint
extern void * const CScriptCompiler__SetOptimizeBinaryCodeLength;
// void CScriptCompiler::SetOutputAliasconst CExoString&
extern void * const CScriptCompiler__SetOutputAlias;
// void CScriptCompiler::ShutDownvoid
extern void * const CScriptCompiler__ShutDown;
// void CScriptCompiler::ShutdownIncludeFileint
extern void * const CScriptCompiler__ShutdownIncludeFile;
// void CScriptCompiler::StartLineNumberAtBinaryInstructionint, int, int
extern void * const CScriptCompiler__StartLineNumberAtBinaryInstruction;
// void CScriptCompiler::Test_CompareDirectoryContentsCExoString&, CExoString&
extern void * const CScriptCompiler__Test_CompareDirectoryContents;
// void CScriptCompiler::Test_CompareFileInclusionCExoString&, CExoString&, CExoStringList*, unsigned short int
extern void * const CScriptCompiler__Test_CompareFileInclusion;
// void CScriptCompiler::Test_CompileAllScriptsInDirectoryCExoString&, CExoString&, CExoString&
extern void * const CScriptCompiler__Test_CompileAllScriptsInDirectory;
// void CScriptCompiler::TestIdentifierTokenvoid
extern void * const CScriptCompiler__TestIdentifierToken;
// void CScriptCompiler::TokenInitializevoid
extern void * const CScriptCompiler__TokenInitialize;
// void CScriptCompiler::TraverseTreeForSwitchLabelsCScriptParseTreeNode*
extern void * const CScriptCompiler__TraverseTreeForSwitchLabels;
// void CScriptCompiler::ValidateLocationOfIdentifierconst CExoString&
extern void * const CScriptCompiler__ValidateLocationOfIdentifier;
// void CScriptCompiler::WalkParseTreeCScriptParseTreeNode*
extern void * const CScriptCompiler__WalkParseTree;
// void CScriptCompiler::WriteDebuggerOutputToFileCExoString
extern void * const CScriptCompiler__WriteDebuggerOutputToFile;
// void CScriptCompiler::WriteFinalCodeToFileconst CExoString&
extern void * const CScriptCompiler__WriteFinalCodeToFile;
// void CScriptCompiler::WriteResolvedOutputvoid
extern void * const CScriptCompiler__WriteResolvedOutput;

// CScriptCompilerIdListEntry::CScriptCompilerIdListEntryvoid
extern void * const CScriptCompilerIdListEntry__CScriptCompilerIdListEntryCtor;
// CScriptCompilerIdListEntry::~CScriptCompilerIdListEntryvoid
extern void * const CScriptCompilerIdListEntry__CScriptCompilerIdListEntryDtor;
// void CScriptCompilerIdListEntry::ExpandParameterSpacevoid
extern void * const CScriptCompilerIdListEntry__ExpandParameterSpace;

// public CScriptEvent::CScriptEventvoid
extern void * const CScriptEvent__CScriptEventCtor;
// public CScriptEvent::~CScriptEventvoid
extern void * const CScriptEvent__CScriptEventDtor;
// void CScriptEvent::__eqconst CScriptEvent& const
extern void * const CScriptEvent____eq;
// void CScriptEvent::__neconst CScriptEvent& const
extern void * const CScriptEvent____ne;
// public void CScriptEvent::CopyScriptEventCScriptEvent*
extern void * const CScriptEvent__CopyScriptEvent;
// public float CScriptEvent::GetFloatint
extern void * const CScriptEvent__GetFloat;
// public int CScriptEvent::GetIntegerint
extern void * const CScriptEvent__GetInteger;
// public unsigned long int CScriptEvent::GetObjectIDint
extern void * const CScriptEvent__GetObjectID;
// public CExoString CScriptEvent::GetStringint
extern void * const CScriptEvent__GetString;
// public int CScriptEvent::LoadEventCResGFF*, CResStruct*
extern void * const CScriptEvent__LoadEvent;
// public int CScriptEvent::SaveEventCResGFF*, CResStruct*
extern void * const CScriptEvent__SaveEvent;
// public void CScriptEvent::SetFloatint, float
extern void * const CScriptEvent__SetFloat;
// public void CScriptEvent::SetIntegerint, int
extern void * const CScriptEvent__SetInteger;
// public void CScriptEvent::SetObjectIDint, unsigned long int
extern void * const CScriptEvent__SetObjectID;
// public void CScriptEvent::SetStringint, CExoString
extern void * const CScriptEvent__SetString;

// public CScriptLocation::CScriptLocationvoid
extern void * const CScriptLocation__CScriptLocationCtor;
// public CScriptLocation::~CScriptLocationvoid
extern void * const CScriptLocation__CScriptLocationDtor;
// public void CScriptLocation::CopyScriptLocationCScriptLocation*
extern void * const CScriptLocation__CopyScriptLocation;
// public int CScriptLocation::LoadLocationCResGFF*, CResStruct*
extern void * const CScriptLocation__LoadLocation;
// public int CScriptLocation::SaveLocationCResGFF*, CResStruct*
extern void * const CScriptLocation__SaveLocation;

// public CScriptSourceFile::CScriptSourceFilevoid
extern void * const CScriptSourceFile__CScriptSourceFileCtor;
// public CScriptSourceFile::~CScriptSourceFilevoid
extern void * const CScriptSourceFile__CScriptSourceFileDtor;
// public int CScriptSourceFile::LoadScriptconst CExoString&, char**, unsigned long int*
extern void * const CScriptSourceFile__LoadScript;
// public void CScriptSourceFile::UnloadScriptvoid
extern void * const CScriptSourceFile__UnloadScript;

// public CScriptTalent::CScriptTalentvoid
extern void * const CScriptTalent__CScriptTalentCtor;
// public CScriptTalent::~CScriptTalentvoid
extern void * const CScriptTalent__CScriptTalentDtor;
// public void CScriptTalent::CopyScriptTalentCScriptTalent*
extern void * const CScriptTalent__CopyScriptTalent;
// public int CScriptTalent::EqualsCScriptTalent*
extern void * const CScriptTalent__Equals;
// public int CScriptTalent::LoadTalentCResGFF*, CResStruct*
extern void * const CScriptTalent__LoadTalent;
// public int CScriptTalent::SaveTalentCResGFF*, CResStruct*
extern void * const CScriptTalent__SaveTalent;

// void CServerAIBodyBagInfo::LoadBodyBagCResGFF*, CResStruct*
extern void * const CServerAIBodyBagInfo__LoadBodyBag;
// void CServerAIBodyBagInfo::SaveBodyBagCResGFF*, CResStruct*
extern void * const CServerAIBodyBagInfo__SaveBodyBag;

// public int CServerAIEventNode::LoadNodeCResGFF*, CResStruct*
extern void * const CServerAIEventNode__LoadNode;
// public int CServerAIEventNode::SaveNodeCResGFF*, CResStruct*
extern void * const CServerAIEventNode__SaveNode;

// public CServerAIList::CServerAIListvoid
extern void * const CServerAIList__CServerAIListCtor;
// public CServerAIList::~CServerAIListvoid
extern void * const CServerAIList__CServerAIListDtor;
// void CServerAIList::AddObjectunsigned long int
extern void * const CServerAIList__AddObject;
// void CServerAIList::GetNextObjectvoid
extern void * const CServerAIList__GetNextObject;
// void CServerAIList::RemoveObjectunsigned long int
extern void * const CServerAIList__RemoveObject;

// public CServerAIMaster::CServerAIMastervoid
extern void * const CServerAIMaster__CServerAIMasterCtor;
// public CServerAIMaster::~CServerAIMastervoid
extern void * const CServerAIMaster__CServerAIMasterDtor;
// public int CServerAIMaster::AddEventAbsoluteTimeunsigned long int, unsigned long int, unsigned long int, unsigned long int, unsigned long int, void*
extern void * const CServerAIMaster__AddEventAbsoluteTime;
// public int CServerAIMaster::AddEventAbsoluteTimeViaTailunsigned long int, unsigned long int, unsigned long int, unsigned long int, unsigned long int, void*
extern void * const CServerAIMaster__AddEventAbsoluteTimeViaTail;
// public int CServerAIMaster::AddEventDeltaTimeunsigned long int, unsigned long int, unsigned long int, unsigned long int, unsigned long int, void*
extern void * const CServerAIMaster__AddEventDeltaTime;
// public int CServerAIMaster::AddObjectCNWSObject*, int
extern void * const CServerAIMaster__AddObject;
// public void CServerAIMaster::AdjustTargetAndWitnessReputationsunsigned long int, unsigned long int, int
extern void * const CServerAIMaster__AdjustTargetAndWitnessReputations;
// public void CServerAIMaster::ClearEventQueuevoid
extern void * const CServerAIMaster__ClearEventQueue;
// protected void CServerAIMaster::DeleteEventDataunsigned long int, void*
extern void * const CServerAIMaster__DeleteEventData;
// void CServerAIMaster::EventPendingunsigned long int, unsigned long int
extern void * const CServerAIMaster__EventPending;
// void CServerAIMaster::GetPendingEventunsigned long int*, unsigned long int*, unsigned long int*, unsigned long int*, unsigned long int*, void**
extern void * const CServerAIMaster__GetPendingEvent;
// public int CServerAIMaster::LoadEventQueueCResGFF*, CResStruct*
extern void * const CServerAIMaster__LoadEventQueue;
// public void CServerAIMaster::LoadReputationAdjustmentsvoid
extern void * const CServerAIMaster__LoadReputationAdjustments;
// public int CServerAIMaster::OnEffectAppliedCNWSObject*, CGameEffect*, int
extern void * const CServerAIMaster__OnEffectApplied;
// public int CServerAIMaster::OnEffectRemovedCNWSObject*, CGameEffect*
extern void * const CServerAIMaster__OnEffectRemoved;
// public int CServerAIMaster::OnItemPropertyAppliedCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int, int
extern void * const CServerAIMaster__OnItemPropertyApplied;
// public int CServerAIMaster::OnItemPropertyRemovedCNWSItem*, CNWItemProperty*, CNWSCreature*, unsigned long int
extern void * const CServerAIMaster__OnItemPropertyRemoved;
// public int CServerAIMaster::RemoveObjectCNWSObject*
extern void * const CServerAIMaster__RemoveObject;
// public int CServerAIMaster::SaveEventQueueCResGFF*, CResStruct*
extern void * const CServerAIMaster__SaveEventQueue;
// public int CServerAIMaster::SetAILevelCNWSObject*, int
extern void * const CServerAIMaster__SetAILevel;
// public void CServerAIMaster::SetExoAppInternalCServerExoAppInternal*
extern void * const CServerAIMaster__SetExoAppInternal;
// public void CServerAIMaster::UpdateStatevoid
extern void * const CServerAIMaster__UpdateState;

// public CServerExoApp::CServerExoAppvoid
extern void * const CServerExoApp__CServerExoAppCtor;
// public CServerExoApp::~CServerExoAppvoid
extern void * const CServerExoApp__CServerExoAppDtor;
// public void CServerExoApp::AddCDKeyToBannedListCExoString
extern void * const CServerExoApp__AddCDKeyToBannedList;
// public void CServerExoApp::AddCharListRequestunsigned long int
extern void * const CServerExoApp__AddCharListRequest;
// public void CServerExoApp::AddIPToBannedListCExoString
extern void * const CServerExoApp__AddIPToBannedList;
// public void CServerExoApp::AddPlayerNameToBannedListCExoString
extern void * const CServerExoApp__AddPlayerNameToBannedList;
// public void CServerExoApp::AddSubNetProfileSendSizeunsigned long int, unsigned long int
extern void * const CServerExoApp__AddSubNetProfileSendSize;
// public void CServerExoApp::AddToExclusionListunsigned long int, unsigned char
extern void * const CServerExoApp__AddToExclusionList;
// public int CServerExoApp::AdmitNetworkAddressunsigned long int, CExoString
extern void * const CServerExoApp__AdmitNetworkAddress;
// public int CServerExoApp::AdmitPlayerNameCExoString
extern void * const CServerExoApp__AdmitPlayerName;
// public int CServerExoApp::ContinueMessageProcessingvoid
extern void * const CServerExoApp__ContinueMessageProcessing;
// void CServerExoApp::ExportAllPlayersvoid
extern void * const CServerExoApp__ExportAllPlayers;
// public CExoLinkedListTemplatedunsignedlong* CServerExoApp::GetActiveExclusionListvoid
extern void * const CServerExoApp__GetActiveExclusionList;
// public unsigned char CServerExoApp::GetActivePauseStatevoid
extern void * const CServerExoApp__GetActivePauseState;
// public CWorldTimer* CServerExoApp::GetActiveTimerunsigned long int
extern void * const CServerExoApp__GetActiveTimer;
// public unsigned long int CServerExoApp::GetApplicationIdvoid
extern void * const CServerExoApp__GetApplicationId;
// public CNWSArea* CServerExoApp::GetAreaByGameObjectIDunsigned long int
extern void * const CServerExoApp__GetAreaByGameObjectID;
// public CNWSAreaOfEffectObject* CServerExoApp::GetAreaOfEffectByGameObjectIDunsigned long int
extern void * const CServerExoApp__GetAreaOfEffectByGameObjectID;
// void CServerExoApp::GetAutoSavePendingvoid
extern void * const CServerExoApp__GetAutoSavePending;
// public CExoString CServerExoApp::GetBannedListStringvoid
extern void * const CServerExoApp__GetBannedListString;
// public int CServerExoApp::GetCDKeysCExoArrayListTemplatedCExoString**
extern void * const CServerExoApp__GetCDKeys;
// public CNWSPlayer* CServerExoApp::GetClientObjectByObjectIdunsigned long int
extern void * const CServerExoApp__GetClientObjectByObjectId;
// public CNWSClient* CServerExoApp::GetClientObjectByPlayerIdunsigned long int, unsigned char
extern void * const CServerExoApp__GetClientObjectByPlayerId;
// public CCodeBase* CServerExoApp::GetCodeBasevoid
extern void * const CServerExoApp__GetCodeBase;
// public CConnectionLib* CServerExoApp::GetConnectionLibvoid
extern void * const CServerExoApp__GetConnectionLib;
// public CNWSCreature* CServerExoApp::GetCreatureByGameObjectIDunsigned long int
extern void * const CServerExoApp__GetCreatureByGameObjectID;
// public int CServerExoApp::GetCreatureDeathLoggingvoid
extern void * const CServerExoApp__GetCreatureDeathLogging;
// public int CServerExoApp::GetDebugModevoid
extern void * const CServerExoApp__GetDebugMode;
// public int CServerExoApp::GetDifficultyOptionint
extern void * const CServerExoApp__GetDifficultyOption;
// public CNWSDoor* CServerExoApp::GetDoorByGameObjectIDunsigned long int
extern void * const CServerExoApp__GetDoorByGameObjectID;
// public CNWSEncounter* CServerExoApp::GetEncounterByGameObjectIDunsigned long int
extern void * const CServerExoApp__GetEncounterByGameObjectID;
// void CServerExoApp::GetExoAppInternalvoid
extern void * const CServerExoApp__GetExoAppInternal;
// public int CServerExoApp::GetExportCharacterPendingvoid
extern void * const CServerExoApp__GetExportCharacterPending;
// void CServerExoApp::GetExportPlayersCharactervoid
extern void * const CServerExoApp__GetExportPlayersCharacter;
// public void CServerExoApp::GetExtendedServerInfoCExtendedServerInfo*
extern void * const CServerExoApp__GetExtendedServerInfo__0;
// public void CServerExoApp::GetExtendedServerInfovoid
extern void * const CServerExoApp__GetExtendedServerInfo__1;
// public int CServerExoApp::GetFactionOfObjectunsigned long int, int*
extern void * const CServerExoApp__GetFactionOfObject;
// public unsigned long int CServerExoApp::GetFirstPCObjectvoid
extern void * const CServerExoApp__GetFirstPCObject;
// public float CServerExoApp::GetFPSvoid
extern void * const CServerExoApp__GetFPS;
// public CGameObject* CServerExoApp::GetGameObjectunsigned long int
extern void * const CServerExoApp__GetGameObject;
// public int CServerExoApp::GetGameSpyEnabledvoid
extern void * const CServerExoApp__GetGameSpyEnabled;
// void CServerExoApp::GetImportingCharvoid
extern void * const CServerExoApp__GetImportingChar;
// public int CServerExoApp::GetIsCDKeyOnBannedListCExoString
extern void * const CServerExoApp__GetIsCDKeyOnBannedList;
// public int CServerExoApp::GetIsControlledByPlayerunsigned long int
extern void * const CServerExoApp__GetIsControlledByPlayer;
// public int CServerExoApp::GetIsIPOnBannedListCExoString
extern void * const CServerExoApp__GetIsIPOnBannedList;
// public int CServerExoApp::GetIsMultiPlayervoid
extern void * const CServerExoApp__GetIsMultiPlayer;
// public int CServerExoApp::GetIsPlayerNameOnBannedListCExoString
extern void * const CServerExoApp__GetIsPlayerNameOnBannedList;
// public CNWSItem* CServerExoApp::GetItemByGameObjectIDunsigned long int
extern void * const CServerExoApp__GetItemByGameObjectID;
// public int CServerExoApp::GetLoadingModulevoid
extern void * const CServerExoApp__GetLoadingModule;
// public void* CServerExoApp::GetModulevoid
extern void * const CServerExoApp__GetModule;
// public CNWSModule* CServerExoApp::GetModuleByGameObjectIDunsigned long int
extern void * const CServerExoApp__GetModuleByGameObjectID;
// public CExoLocString CServerExoApp::GetModuleDescriptionvoid
extern void * const CServerExoApp__GetModuleDescription;
// public int CServerExoApp::GetModuleLanguagevoid
extern void * const CServerExoApp__GetModuleLanguage;
// public CExoString CServerExoApp::GetModuleNamevoid
extern void * const CServerExoApp__GetModuleName;
// void CServerExoApp::GetMoveToModulePendingvoid
extern void * const CServerExoApp__GetMoveToModulePending;
// void CServerExoApp::GetMoveToModuleStringvoid
extern void * const CServerExoApp__GetMoveToModuleString;
// public int CServerExoApp::GetMultiplayerEnabledvoid
extern void * const CServerExoApp__GetMultiplayerEnabled;
// public CNetLayer* CServerExoApp::GetNetLayervoid
extern void * const CServerExoApp__GetNetLayer;
// public unsigned long int CServerExoApp::GetNextPCObjectvoid
extern void * const CServerExoApp__GetNextPCObject;
// public void* CServerExoApp::GetNWSMessagevoid
extern void * const CServerExoApp__GetNWSMessage;
// public CGameObjectArray* CServerExoApp::GetObjectArrayvoid
extern void * const CServerExoApp__GetObjectArray;
// public int CServerExoApp::GetPauseStateunsigned char
extern void * const CServerExoApp__GetPauseState;
// public CWorldTimer* CServerExoApp::GetPauseTimervoid
extern void * const CServerExoApp__GetPauseTimer;
// public CNWSPlaceable* CServerExoApp::GetPlaceableByGameObjectIDunsigned long int
extern void * const CServerExoApp__GetPlaceableByGameObjectID;
// public CNWPlaceMeshManager* CServerExoApp::GetPlaceMeshManagervoid
extern void * const CServerExoApp__GetPlaceMeshManager;
// void CServerExoApp::GetPlayerAddressDataunsigned long int, unsigned long int*, unsigned char**, unsigned char**, unsigned long int*
extern void * const CServerExoApp__GetPlayerAddressData;
// public unsigned long int CServerExoApp::GetPlayerIDByGameObjectIDunsigned long int
extern void * const CServerExoApp__GetPlayerIDByGameObjectID;
// public int CServerExoApp::GetPlayerLanguageunsigned long int
extern void * const CServerExoApp__GetPlayerLanguage;
// public void* CServerExoApp::GetPlayerListvoid
extern void * const CServerExoApp__GetPlayerList;
// public CExoString CServerExoApp::GetPlayerListStringvoid
extern void * const CServerExoApp__GetPlayerListString;
// public CExoString CServerExoApp::GetPortalListStringvoid
extern void * const CServerExoApp__GetPortalListString;
// public int CServerExoApp::GetReloadModuleWhenEmptyvoid
extern void * const CServerExoApp__GetReloadModuleWhenEmpty;
// public void* CServerExoApp::GetServerAIMastervoid
extern void * const CServerExoApp__GetServerAIMaster;
// public CServerInfo* CServerExoApp::GetServerInfovoid
extern void * const CServerExoApp__GetServerInfo;
// public short int CServerExoApp::GetServerModevoid
extern void * const CServerExoApp__GetServerMode;
// public CNWSSoundObject* CServerExoApp::GetSoundObjectByGameObjectIDunsigned long int
extern void * const CServerExoApp__GetSoundObjectByGameObjectID;
// public CNWSStore* CServerExoApp::GetStoreByGameObjectIDunsigned long int
extern void * const CServerExoApp__GetStoreByGameObjectID;
// public void* CServerExoApp::GetSysAdminListvoid
extern void * const CServerExoApp__GetSysAdminList;
// public CWorldTimer* CServerExoApp::GetTimestopTimervoid
extern void * const CServerExoApp__GetTimestopTimer;
// public CNWSTrigger* CServerExoApp::GetTriggerByGameObjectIDunsigned long int
extern void * const CServerExoApp__GetTriggerByGameObjectID;
// public CNWSWaypoint* CServerExoApp::GetWaypointByGameObjectIDunsigned long int
extern void * const CServerExoApp__GetWaypointByGameObjectID;
// public CWorldTimer* CServerExoApp::GetWorldTimervoid
extern void * const CServerExoApp__GetWorldTimer;
// public void CServerExoApp::GSClientAddServervoid*, char*, char*, int, int, int, int, char*, int, int, char*, int, int, int, char*, char*, int, int, int, int, int, bool
extern void * const CServerExoApp__GSClientAddServer;
// public void CServerExoApp::GSClientChatMessageint, CExoString, CExoString
extern void * const CServerExoApp__GSClientChatMessage;
// public void CServerExoApp::GSClientClearServersvoid
extern void * const CServerExoApp__GSClientClearServers;
// public void CServerExoApp::GSClientGroupRoomAddedint, unsigned long int
extern void * const CServerExoApp__GSClientGroupRoomAdded;
// public void CServerExoApp::GSClientRemoveServervoid*
extern void * const CServerExoApp__GSClientRemoveServer;
// public void CServerExoApp::GSClientUpdateConnectionPhaseunsigned char, const CExoString&
extern void * const CServerExoApp__GSClientUpdateConnectionPhase;
// public void CServerExoApp::GSClientUpdateServervoid*, char*, char*, int, int, int, int, char*, int, int, char*, int, int, int, char*, char*, int, int, int, int, int, bool
extern void * const CServerExoApp__GSClientUpdateServer;
// public void CServerExoApp::HandleGameSpyToServerMessageint, void*, int
extern void * const CServerExoApp__HandleGameSpyToServerMessage;
// public int CServerExoApp::HandleMessageunsigned long int, unsigned char*, unsigned long int, int
extern void * const CServerExoApp__HandleMessage;
// public int CServerExoApp::Initializevoid
extern void * const CServerExoApp__Initialize;
// public void CServerExoApp::InitiateModuleForPlayervoid*
extern void * const CServerExoApp__InitiateModuleForPlayer;
// void CServerExoApp::IsOnActiveExclusionListunsigned long int
extern void * const CServerExoApp__IsOnActiveExclusionList;
// public int CServerExoApp::IsOnExclusionListunsigned long int
extern void * const CServerExoApp__IsOnExclusionList;
// public int CServerExoApp::LoadCharacterFinishCNWSPlayer*, int, int
extern void * const CServerExoApp__LoadCharacterFinish;
// public int CServerExoApp::LoadCharacterStartunsigned char, CNWSPlayer*, CResRef, void*, unsigned long int
extern void * const CServerExoApp__LoadCharacterStart;
// public int CServerExoApp::LoadGameunsigned long int, CExoString&, CExoString&, CNWSPlayer*
extern void * const CServerExoApp__LoadGame;
// public int CServerExoApp::LoadModuleCExoString, int, CNWSPlayer*
extern void * const CServerExoApp__LoadModule;
// void CServerExoApp::LoadPrimaryPlayerCNWSPlayer*
extern void * const CServerExoApp__LoadPrimaryPlayer;
// public int CServerExoApp::MainLoopvoid
extern void * const CServerExoApp__MainLoop;
// public void CServerExoApp::MovePlayerToAreavoid*
extern void * const CServerExoApp__MovePlayerToArea;
// void CServerExoApp::OnCDChangevoid
extern void * const CServerExoApp__OnCDChange;
// void CServerExoApp::OnExitvoid
extern void * const CServerExoApp__OnExit;
// void CServerExoApp::OnGainFocusvoid
extern void * const CServerExoApp__OnGainFocus;
// void CServerExoApp::OnLostFocusvoid
extern void * const CServerExoApp__OnLostFocus;
// void CServerExoApp::OnVideoChangevoid
extern void * const CServerExoApp__OnVideoChange;
// public void CServerExoApp::PlayerListChangeunsigned long int, int, int
extern void * const CServerExoApp__PlayerListChange;
// public void CServerExoApp::PushMessageOverWallunsigned char*, unsigned long int
extern void * const CServerExoApp__PushMessageOverWall;
// public void CServerExoApp::RemoveCDKeyFromBannedListCExoString
extern void * const CServerExoApp__RemoveCDKeyFromBannedList;
// public void CServerExoApp::RemoveFromExclusionListunsigned long int, unsigned char
extern void * const CServerExoApp__RemoveFromExclusionList;
// public void CServerExoApp::RemoveIPFromBannedListCExoString
extern void * const CServerExoApp__RemoveIPFromBannedList;
// void CServerExoApp::RemovePCFromWorldCNWSPlayer*
extern void * const CServerExoApp__RemovePCFromWorld;
// public void CServerExoApp::RemovePlayerNameFromBannedListCExoString
extern void * const CServerExoApp__RemovePlayerNameFromBannedList;
// public unsigned long int CServerExoApp::ResolvePlayerByFirstNameconst CExoString&
extern void * const CServerExoApp__ResolvePlayerByFirstName;
// void CServerExoApp::RestartNetLayervoid
extern void * const CServerExoApp__RestartNetLayer;
// public int CServerExoApp::RunModulevoid
extern void * const CServerExoApp__RunModule;
// public int CServerExoApp::SaveGameunsigned long int, CExoString&, CExoString&, CNWSPlayer*, int, CExoString&
extern void * const CServerExoApp__SaveGame;
// void CServerExoApp::SendCharacterQueryCNWSPlayer*
extern void * const CServerExoApp__SendCharacterQuery;
// public void CServerExoApp::SetApplicationIdsMatchint
extern void * const CServerExoApp__SetApplicationIdsMatch;
// public void CServerExoApp::SetAutoSavePendingint
extern void * const CServerExoApp__SetAutoSavePending;
// public void CServerExoApp::SetDebugModeint
extern void * const CServerExoApp__SetDebugMode;
// public void CServerExoApp::SetEndGamePendingint
extern void * const CServerExoApp__SetEndGamePending;
// public void CServerExoApp::SetEndGameStringCExoString&
extern void * const CServerExoApp__SetEndGameString;
// public void CServerExoApp::SetExportCharacterPendingint
extern void * const CServerExoApp__SetExportCharacterPending;
// public void CServerExoApp::SetExportPlayersCharacterunsigned long int
extern void * const CServerExoApp__SetExportPlayersCharacter;
// void CServerExoApp::SetForceUpdatevoid
extern void * const CServerExoApp__SetForceUpdate;
// public void CServerExoApp::SetGameSpyEnabledint
extern void * const CServerExoApp__SetGameSpyEnabled;
// void CServerExoApp::SetGameSpyReportingint
extern void * const CServerExoApp__SetGameSpyReporting;
// public void CServerExoApp::SetImportingCharint
extern void * const CServerExoApp__SetImportingChar;
// public void CServerExoApp::SetLoadingModuleint
extern void * const CServerExoApp__SetLoadingModule;
// public void CServerExoApp::SetMoveToModulePendingint
extern void * const CServerExoApp__SetMoveToModulePending;
// public void CServerExoApp::SetMoveToModuleStringCExoString&
extern void * const CServerExoApp__SetMoveToModuleString;
// public int CServerExoApp::SetNetworkAddressBanunsigned long int, CExoString, int
extern void * const CServerExoApp__SetNetworkAddressBan;
// public void CServerExoApp::SetPauseStateunsigned char, int
extern void * const CServerExoApp__SetPauseState;
// public void CServerExoApp::SetReloadModuleWhenEmptyint
extern void * const CServerExoApp__SetReloadModuleWhenEmpty;
// public void CServerExoApp::SetWeGotDisconnectedvoid
extern void * const CServerExoApp__SetWeGotDisconnected;
// public void CServerExoApp::Shutdownint, int
extern void * const CServerExoApp__Shutdown;
// void CServerExoApp::ShutdownNetLayervoid
extern void * const CServerExoApp__ShutdownNetLayer;
// public void CServerExoApp::ShutDownToMainMenuvoid
extern void * const CServerExoApp__ShutDownToMainMenu;
// public int CServerExoApp::StartNewModuleCExoString&
extern void * const CServerExoApp__StartNewModule;
// public void CServerExoApp::StartServicesvoid
extern void * const CServerExoApp__StartServices;
// public void CServerExoApp::StopServicesvoid
extern void * const CServerExoApp__StopServices;
// public int CServerExoApp::StripColorTokensCExoString&
extern void * const CServerExoApp__StripColorTokens;
// public void CServerExoApp::TogglePauseStateunsigned char
extern void * const CServerExoApp__TogglePauseState;
// public void CServerExoApp::Uninitializevoid
extern void * const CServerExoApp__Uninitialize;
// void CServerExoApp::UnloadModulevoid
extern void * const CServerExoApp__UnloadModule;
// void CServerExoApp::ValidatePlayerLoginvoid*
extern void * const CServerExoApp__ValidatePlayerLogin;
// public void CServerExoApp::VomitServerOptionsToLogvoid
extern void * const CServerExoApp__VomitServerOptionsToLog;

// public CServerExoAppInternal::CServerExoAppInternalvoid
extern void * const CServerExoAppInternal__CServerExoAppInternalCtor;
// public CServerExoAppInternal::~CServerExoAppInternalvoid
extern void * const CServerExoAppInternal__CServerExoAppInternalDtor;
// public void CServerExoAppInternal::AddCDKeyToBannedListCExoString
extern void * const CServerExoAppInternal__AddCDKeyToBannedList;
// public void CServerExoAppInternal::AddCharListRequestunsigned long int
extern void * const CServerExoAppInternal__AddCharListRequest;
// public void CServerExoAppInternal::AddIPToBannedListCExoString
extern void * const CServerExoAppInternal__AddIPToBannedList;
// void CServerExoAppInternal::AddPendingAuthorizationunsigned long int
extern void * const CServerExoAppInternal__AddPendingAuthorization;
// public void CServerExoAppInternal::AddPlayerNameToBannedListCExoString
extern void * const CServerExoAppInternal__AddPlayerNameToBannedList;
// protected void CServerExoAppInternal::AddSubNetProfileunsigned long int, CExoString, CExoString
extern void * const CServerExoAppInternal__AddSubNetProfile;
// void CServerExoAppInternal::AddSubNetProfileRecvSizeunsigned long int, unsigned long int
extern void * const CServerExoAppInternal__AddSubNetProfileRecvSize;
// public void CServerExoAppInternal::AddSubNetProfileSendSizeunsigned long int, unsigned long int
extern void * const CServerExoAppInternal__AddSubNetProfileSendSize;
// public void CServerExoAppInternal::AddToExclusionListunsigned long int, unsigned char
extern void * const CServerExoAppInternal__AddToExclusionList;
// public int CServerExoAppInternal::AdmitNetworkAddressunsigned long int, CExoString
extern void * const CServerExoAppInternal__AdmitNetworkAddress;
// public int CServerExoAppInternal::AdmitPlayerNameCExoString
extern void * const CServerExoAppInternal__AdmitPlayerName;
// protected void CServerExoAppInternal::CheckMasterServerTranslationvoid
extern void * const CServerExoAppInternal__CheckMasterServerTranslation;
// protected void CServerExoAppInternal::ConnectionLibMainLoopvoid
extern void * const CServerExoAppInternal__ConnectionLibMainLoop;
// public int CServerExoAppInternal::ContinueMessageProcessingvoid
extern void * const CServerExoAppInternal__ContinueMessageProcessing;
// void CServerExoAppInternal::CopyModuleToCurrentGameCExoString&, CExoString&, unsigned short int
extern void * const CServerExoAppInternal__CopyModuleToCurrentGame;
// public int CServerExoAppInternal::CreateServerVaultLostAndFoundvoid
extern void * const CServerExoAppInternal__CreateServerVaultLostAndFound;
// public void CServerExoAppInternal::DealWithLoadGameErrorunsigned long int
extern void * const CServerExoAppInternal__DealWithLoadGameError;
// void CServerExoAppInternal::EndGameconst CExoString&
extern void * const CServerExoAppInternal__EndGame;
// void CServerExoAppInternal::ExportAllPlayersvoid
extern void * const CServerExoAppInternal__ExportAllPlayers;
// public int CServerExoAppInternal::ExportPlayerCNWSPlayer*
extern void * const CServerExoAppInternal__ExportPlayer;
// public CExoLinkedListTemplatedunsignedlong* CServerExoAppInternal::GetActiveExclusionListvoid
extern void * const CServerExoAppInternal__GetActiveExclusionList;
// public unsigned char CServerExoAppInternal::GetActivePauseStatevoid
extern void * const CServerExoAppInternal__GetActivePauseState;
// public CWorldTimer* CServerExoAppInternal::GetActiveTimerunsigned long int
extern void * const CServerExoAppInternal__GetActiveTimer;
// public CNWSArea* CServerExoAppInternal::GetAreaByGameObjectIDunsigned long int
extern void * const CServerExoAppInternal__GetAreaByGameObjectID;
// public CNWSAreaOfEffectObject* CServerExoAppInternal::GetAreaOfEffectByGameObjectIDunsigned long int
extern void * const CServerExoAppInternal__GetAreaOfEffectByGameObjectID;
// public CExoString CServerExoAppInternal::GetBannedListStringvoid
extern void * const CServerExoAppInternal__GetBannedListString;
// public CNWSPlayer* CServerExoAppInternal::GetClientObjectByObjectIdunsigned long int
extern void * const CServerExoAppInternal__GetClientObjectByObjectId;
// public CNWSClient* CServerExoAppInternal::GetClientObjectByPlayerIdunsigned long int, unsigned char
extern void * const CServerExoAppInternal__GetClientObjectByPlayerId;
// public CNWSCreature* CServerExoAppInternal::GetCreatureByGameObjectIDunsigned long int
extern void * const CServerExoAppInternal__GetCreatureByGameObjectID;
// public int CServerExoAppInternal::GetDifficultyOptionint
extern void * const CServerExoAppInternal__GetDifficultyOption;
// public CNWSDoor* CServerExoAppInternal::GetDoorByGameObjectIDunsigned long int
extern void * const CServerExoAppInternal__GetDoorByGameObjectID;
// public CNWSEncounter* CServerExoAppInternal::GetEncounterByGameObjectIDunsigned long int
extern void * const CServerExoAppInternal__GetEncounterByGameObjectID;
// public void CServerExoAppInternal::GetExtendedServerInfoCExtendedServerInfo*
extern void * const CServerExoAppInternal__GetExtendedServerInfo;
// public int CServerExoAppInternal::GetFactionOfObjectunsigned long int, int*
extern void * const CServerExoAppInternal__GetFactionOfObject;
// public unsigned long int CServerExoAppInternal::GetFirstPCObjectvoid
extern void * const CServerExoAppInternal__GetFirstPCObject;
// public CGameObject* CServerExoAppInternal::GetGameObjectunsigned long int
extern void * const CServerExoAppInternal__GetGameObject;
// public int CServerExoAppInternal::GetIsCDKeyOnBannedListCExoString
extern void * const CServerExoAppInternal__GetIsCDKeyOnBannedList;
// public int CServerExoAppInternal::GetIsIPOnBannedListCExoString
extern void * const CServerExoAppInternal__GetIsIPOnBannedList;
// public int CServerExoAppInternal::GetIsPlayerNameOnBannedListCExoString
extern void * const CServerExoAppInternal__GetIsPlayerNameOnBannedList;
// public CNWSItem* CServerExoAppInternal::GetItemByGameObjectIDunsigned long int
extern void * const CServerExoAppInternal__GetItemByGameObjectID;
// public CNWSModule* CServerExoAppInternal::GetModulevoid
extern void * const CServerExoAppInternal__GetModule;
// public CNWSModule* CServerExoAppInternal::GetModuleByGameObjectIDunsigned long int
extern void * const CServerExoAppInternal__GetModuleByGameObjectID;
// public int CServerExoAppInternal::GetModuleExistsconst CExoString&
extern void * const CServerExoAppInternal__GetModuleExists;
// public int CServerExoAppInternal::GetModuleLanguagevoid
extern void * const CServerExoAppInternal__GetModuleLanguage;
// public CExoString CServerExoAppInternal::GetModuleNamevoid
extern void * const CServerExoAppInternal__GetModuleName;
// public unsigned long int CServerExoAppInternal::GetNextPCObjectvoid
extern void * const CServerExoAppInternal__GetNextPCObject;
// public int CServerExoAppInternal::GetPauseStateunsigned char
extern void * const CServerExoAppInternal__GetPauseState;
// public CNWSPlaceable* CServerExoAppInternal::GetPlaceableByGameObjectIDunsigned long int
extern void * const CServerExoAppInternal__GetPlaceableByGameObjectID;
// void CServerExoAppInternal::GetPlayerAddressDataunsigned long int, unsigned long int*, unsigned char**, unsigned char**, unsigned long int*
extern void * const CServerExoAppInternal__GetPlayerAddressData;
// public unsigned long int CServerExoAppInternal::GetPlayerIDByGameObjectIDunsigned long int
extern void * const CServerExoAppInternal__GetPlayerIDByGameObjectID;
// public int CServerExoAppInternal::GetPlayerLanguageunsigned long int
extern void * const CServerExoAppInternal__GetPlayerLanguage;
// public CExoString CServerExoAppInternal::GetPlayerListStringvoid
extern void * const CServerExoAppInternal__GetPlayerListString;
// public CExoString CServerExoAppInternal::GetPortalListStringvoid
extern void * const CServerExoAppInternal__GetPortalListString;
// protected void CServerExoAppInternal::GetServerInfoFromIniFilevoid
extern void * const CServerExoAppInternal__GetServerInfoFromIniFile;
// public CNWSSoundObject* CServerExoAppInternal::GetSoundObjectByGameObjectIDunsigned long int
extern void * const CServerExoAppInternal__GetSoundObjectByGameObjectID;
// public CNWSStore* CServerExoAppInternal::GetStoreByGameObjectIDunsigned long int
extern void * const CServerExoAppInternal__GetStoreByGameObjectID;
// public CNWSTrigger* CServerExoAppInternal::GetTriggerByGameObjectIDunsigned long int
extern void * const CServerExoAppInternal__GetTriggerByGameObjectID;
// public CNWSWaypoint* CServerExoAppInternal::GetWaypointByGameObjectIDunsigned long int
extern void * const CServerExoAppInternal__GetWaypointByGameObjectID;
// public void CServerExoAppInternal::HandleGameSpyToServerMessageint, void*, int
extern void * const CServerExoAppInternal__HandleGameSpyToServerMessage;
// public int CServerExoAppInternal::HandleMessageunsigned long int, unsigned char*, unsigned long int, int
extern void * const CServerExoAppInternal__HandleMessage;
// public int CServerExoAppInternal::Initializevoid
extern void * const CServerExoAppInternal__Initialize;
// protected void CServerExoAppInternal::InitializeNetLayervoid
extern void * const CServerExoAppInternal__InitializeNetLayer;
// public void CServerExoAppInternal::InitiateModuleForPlayervoid*
extern void * const CServerExoAppInternal__InitiateModuleForPlayer;
// void CServerExoAppInternal::IsOnActiveExclusionListunsigned long int
extern void * const CServerExoAppInternal__IsOnActiveExclusionList;
// public int CServerExoAppInternal::IsOnExclusionListunsigned long int
extern void * const CServerExoAppInternal__IsOnExclusionList;
// public int CServerExoAppInternal::LoadCharacterFinishCNWSPlayer*, int, int
extern void * const CServerExoAppInternal__LoadCharacterFinish;
// public int CServerExoAppInternal::LoadCharacterStartunsigned char, CNWSPlayer*, CResRef, void*, unsigned long int
extern void * const CServerExoAppInternal__LoadCharacterStart;
// public int CServerExoAppInternal::LoadGameunsigned long int, CExoString&, CExoString&, CNWSPlayer*
extern void * const CServerExoAppInternal__LoadGame;
// public int CServerExoAppInternal::LoadModuleCExoString, int, CNWSPlayer*
extern void * const CServerExoAppInternal__LoadModule;
// void CServerExoAppInternal::LoadPrimaryPlayerCNWSPlayer*
extern void * const CServerExoAppInternal__LoadPrimaryPlayer;
// public int CServerExoAppInternal::MainLoopvoid
extern void * const CServerExoAppInternal__MainLoop;
// void CServerExoAppInternal::MarkUpdateClientsForObjectunsigned long int
extern void * const CServerExoAppInternal__MarkUpdateClientsForObject;
// public void CServerExoAppInternal::MovePlayerToAreavoid*
extern void * const CServerExoAppInternal__MovePlayerToArea;
// void CServerExoAppInternal::OnCDChangevoid
extern void * const CServerExoAppInternal__OnCDChange;
// void CServerExoAppInternal::OnExitvoid
extern void * const CServerExoAppInternal__OnExit;
// void CServerExoAppInternal::OnGainFocusvoid
extern void * const CServerExoAppInternal__OnGainFocus;
// void CServerExoAppInternal::OnLostFocusvoid
extern void * const CServerExoAppInternal__OnLostFocus;
// void CServerExoAppInternal::OnVideoChangevoid
extern void * const CServerExoAppInternal__OnVideoChange;
// public void CServerExoAppInternal::PlayerListChangeunsigned long int, int, int
extern void * const CServerExoAppInternal__PlayerListChange;
// public void CServerExoAppInternal::PushMessageOverWallunsigned char*, unsigned long int
extern void * const CServerExoAppInternal__PushMessageOverWall;
// protected void CServerExoAppInternal::ReadBannedListsvoid
extern void * const CServerExoAppInternal__ReadBannedLists;
// public void CServerExoAppInternal::RemoveCDKeyFromBannedListCExoString
extern void * const CServerExoAppInternal__RemoveCDKeyFromBannedList;
// public void CServerExoAppInternal::RemoveFromExclusionListunsigned long int, unsigned char
extern void * const CServerExoAppInternal__RemoveFromExclusionList;
// public void CServerExoAppInternal::RemoveIPFromBannedListCExoString
extern void * const CServerExoAppInternal__RemoveIPFromBannedList;
// public void CServerExoAppInternal::RemovePCFromWorldCNWSPlayer*
extern void * const CServerExoAppInternal__RemovePCFromWorld;
// void CServerExoAppInternal::RemovePendingAuthorizationunsigned long int
extern void * const CServerExoAppInternal__RemovePendingAuthorization;
// public void CServerExoAppInternal::RemovePlayerNameFromBannedListCExoString
extern void * const CServerExoAppInternal__RemovePlayerNameFromBannedList;
// protected void CServerExoAppInternal::RemoveSubNetProfileunsigned long int
extern void * const CServerExoAppInternal__RemoveSubNetProfile;
// void CServerExoAppInternal::ReprocessExclusionListActionsunsigned char
extern void * const CServerExoAppInternal__ReprocessExclusionListActions;
// public unsigned long int CServerExoAppInternal::ResolvePlayerByFirstNameconst CExoString&
extern void * const CServerExoAppInternal__ResolvePlayerByFirstName;
// void CServerExoAppInternal::RestartNetLayervoid
extern void * const CServerExoAppInternal__RestartNetLayer;
// public int CServerExoAppInternal::RunModulevoid
extern void * const CServerExoAppInternal__RunModule;
// public int CServerExoAppInternal::SaveGameunsigned long int, CExoString&, CExoString&, CNWSPlayer*, int, CExoString&
extern void * const CServerExoAppInternal__SaveGame;
// void CServerExoAppInternal::SendCharacterQueryCNWSPlayer*
extern void * const CServerExoAppInternal__SendCharacterQuery;
// void CServerExoAppInternal::SendEnteringStartNewModuleMessagevoid
extern void * const CServerExoAppInternal__SendEnteringStartNewModuleMessage;
// void CServerExoAppInternal::SendExitingStartNewModuleMessageint
extern void * const CServerExoAppInternal__SendExitingStartNewModuleMessage;
// public int CServerExoAppInternal::SendHeartbeatToMasterServervoid
extern void * const CServerExoAppInternal__SendHeartbeatToMasterServer;
// void CServerExoAppInternal::SendStartStallEventunsigned long int
extern void * const CServerExoAppInternal__SendStartStallEvent;
// public void CServerExoAppInternal::SetEstimatedSaveSizeconst CExoString&, unsigned short int
extern void * const CServerExoAppInternal__SetEstimatedSaveSize;
// void CServerExoAppInternal::SetGameSpyReportingint
extern void * const CServerExoAppInternal__SetGameSpyReporting;
// public int CServerExoAppInternal::SetNetworkAddressBanunsigned long int, CExoString, int
extern void * const CServerExoAppInternal__SetNetworkAddressBan;
// public void CServerExoAppInternal::SetPauseStateunsigned char, int
extern void * const CServerExoAppInternal__SetPauseState;
// public void CServerExoAppInternal::Shutdownint, int
extern void * const CServerExoAppInternal__Shutdown;
// void CServerExoAppInternal::ShutdownNetLayervoid
extern void * const CServerExoAppInternal__ShutdownNetLayer;
// protected void CServerExoAppInternal::ShutdownServerProfilesvoid
extern void * const CServerExoAppInternal__ShutdownServerProfiles;
// public void CServerExoAppInternal::StallEventSaveGamevoid
extern void * const CServerExoAppInternal__StallEventSaveGame;
// public int CServerExoAppInternal::StartNewModuleCExoString&
extern void * const CServerExoAppInternal__StartNewModule;
// public void CServerExoAppInternal::StartServicesvoid
extern void * const CServerExoAppInternal__StartServices;
// void CServerExoAppInternal::StartShutdownTimerunsigned long long int, unsigned long long int
extern void * const CServerExoAppInternal__StartShutdownTimer;
// public void CServerExoAppInternal::StopServicesvoid
extern void * const CServerExoAppInternal__StopServices;
// protected int CServerExoAppInternal::StorePlayerCharactersvoid
extern void * const CServerExoAppInternal__StorePlayerCharacters;
// public int CServerExoAppInternal::StripColorTokensCExoString&
extern void * const CServerExoAppInternal__StripColorTokens;
// void CServerExoAppInternal::Test_Unit_Script_Compilevoid
extern void * const CServerExoAppInternal__Test_Unit_Script_Compile;
// void CServerExoAppInternal::Test_Unit_Script_Runvoid
extern void * const CServerExoAppInternal__Test_Unit_Script_Run;
// public void CServerExoAppInternal::TogglePauseStateunsigned char
extern void * const CServerExoAppInternal__TogglePauseState;
// public void CServerExoAppInternal::Uninitializevoid
extern void * const CServerExoAppInternal__Uninitialize;
// public int CServerExoAppInternal::UnloadModulevoid
extern void * const CServerExoAppInternal__UnloadModule;
// public void CServerExoAppInternal::UnlockBiowareModuleCNWSModule*
extern void * const CServerExoAppInternal__UnlockBiowareModule;
// void CServerExoAppInternal::UpdateAutoSaveTimervoid
extern void * const CServerExoAppInternal__UpdateAutoSaveTimer;
// void CServerExoAppInternal::UpdateClientGameObjectsint
extern void * const CServerExoAppInternal__UpdateClientGameObjects;
// public void CServerExoAppInternal::UpdateClientGameObjectsForPlayerCNWSPlayer*, int, unsigned long long int
extern void * const CServerExoAppInternal__UpdateClientGameObjectsForPlayer;
// void CServerExoAppInternal::UpdateClientsForObjectunsigned long int
extern void * const CServerExoAppInternal__UpdateClientsForObject;
// void CServerExoAppInternal::UpdateLogHeartbeatTimerunsigned long long int
extern void * const CServerExoAppInternal__UpdateLogHeartbeatTimer;
// protected int CServerExoAppInternal::UpdateShutdownTimerunsigned long long int
extern void * const CServerExoAppInternal__UpdateShutdownTimer;
// void CServerExoAppInternal::UpdateWindowTitlevoid
extern void * const CServerExoAppInternal__UpdateWindowTitle;
// public unsigned long int CServerExoAppInternal::ValidateCreateServerCharacterCNWSPlayer*, void*, unsigned long int
extern void * const CServerExoAppInternal__ValidateCreateServerCharacter;
// void CServerExoAppInternal::ValidatePlayerLoginvoid*
extern void * const CServerExoAppInternal__ValidatePlayerLogin;
// public void CServerExoAppInternal::VomitServerOptionsToLogvoid
extern void * const CServerExoAppInternal__VomitServerOptionsToLog;
// protected void CServerExoAppInternal::WriteServerInfoToIniFilevoid
extern void * const CServerExoAppInternal__WriteServerInfoToIniFile;

// public CServerInfo::CServerInfovoid
extern void * const CServerInfo__CServerInfoCtor;
// public int CServerInfo::FindOptionIndexCExoString, CExoString
extern void * const CServerInfo__FindOptionIndex;
// public void CServerInfo::SetDifficultyLevelint, int
extern void * const CServerInfo__SetDifficultyLevel;

// CStoreCustomer::CStoreCustomervoid
extern void * const CStoreCustomer__CStoreCustomerCtor;

// public CTlkFile::CTlkFileCExoString
extern void * const CTlkFile__CTlkFileCtor;
// void CTlkFile::ReadHeadervoid
extern void * const CTlkFile__ReadHeader;

// public CTlkTable::CTlkTablevoid
extern void * const CTlkTable__CTlkTableCtor;
// public CTlkTable::~CTlkTablevoid
extern void * const CTlkTable__CTlkTableDtor;
// public void CTlkTable::ClearCustomTokensvoid
extern void * const CTlkTable__ClearCustomTokens;
// void CTlkTable::CloseFileCTlkFile**
extern void * const CTlkTable__CloseFile;
// public void CTlkTable::CloseFileAlternatevoid
extern void * const CTlkTable__CloseFileAlternate;
// public int CTlkTable::ExoIsDBCSLeadByteunsigned char
extern void * const CTlkTable__ExoIsDBCSLeadByte;
// protected int CTlkTable::FetchInternalunsigned long int, STR_RES&, int
extern void * const CTlkTable__FetchInternal;
// public unsigned long int CTlkTable::GetLanguageVersionvoid
extern void * const CTlkTable__GetLanguageVersion;
// public CExoString CTlkTable::GetSimpleStringunsigned long int
extern void * const CTlkTable__GetSimpleString;
// protected void CTlkTable::GetTokenValueconst CTlkTableToken&, CExoString&
extern void * const CTlkTable__GetTokenValue;
// public int CTlkTable::OpenFileCExoString
extern void * const CTlkTable__OpenFile__0;
// public int CTlkTable::OpenFileconst CExoString&, CTlkFile**
extern void * const CTlkTable__OpenFile__1;
// public int CTlkTable::OpenFileAlternateconst CExoString&
extern void * const CTlkTable__OpenFileAlternate;
// public void CTlkTable::ParseStrCExoString&
extern void * const CTlkTable__ParseStr;
// void CTlkTable::RemapFontNamechar*
extern void * const CTlkTable__RemapFontName;
// public void CTlkTable::SetCustomTokenint, const CExoString&
extern void * const CTlkTable__SetCustomToken;
// void CTlkTable::SetUseLargeDialogFontint
extern void * const CTlkTable__SetUseLargeDialogFont;

// public CTwoDimArrays::CTwoDimArraysvoid
extern void * const CTwoDimArrays__CTwoDimArraysCtor;
// public CTwoDimArrays::~CTwoDimArraysvoid
extern void * const CTwoDimArrays__CTwoDimArraysDtor;
// public void CTwoDimArrays::ClearCached2DAsvoid
extern void * const CTwoDimArrays__ClearCached2DAs;
// public C2DA* CTwoDimArrays::GetCached2DACExoString, int
extern void * const CTwoDimArrays__GetCached2DA;
// public unsigned char CTwoDimArrays::GetEpicAttackBonusunsigned char
extern void * const CTwoDimArrays__GetEpicAttackBonus;
// public unsigned char CTwoDimArrays::GetEpicFortSaveBonusunsigned char
extern void * const CTwoDimArrays__GetEpicFortSaveBonus;
// public unsigned char CTwoDimArrays::GetEpicRefSaveBonusunsigned char
extern void * const CTwoDimArrays__GetEpicRefSaveBonus;
// public unsigned char CTwoDimArrays::GetEpicWillSaveBonusunsigned char
extern void * const CTwoDimArrays__GetEpicWillSaveBonus;
// public C2DA* CTwoDimArrays::GetIPRPCostTableunsigned char
extern void * const CTwoDimArrays__GetIPRPCostTable;
// public int CTwoDimArrays::Load2DArraysvoid
extern void * const CTwoDimArrays__Load2DArrays;
// private int CTwoDimArrays::LoadEpicAttacksvoid
extern void * const CTwoDimArrays__LoadEpicAttacks;
// private int CTwoDimArrays::LoadEpicSavesvoid
extern void * const CTwoDimArrays__LoadEpicSaves;
// private int CTwoDimArrays::LoadIPRPCostTablesvoid
extern void * const CTwoDimArrays__LoadIPRPCostTables;
// public int CTwoDimArrays::UnLoad2DArraysvoid
extern void * const CTwoDimArrays__UnLoad2DArrays;
// void CTwoDimArrays::UnLoadIPRPCostTablesvoid
extern void * const CTwoDimArrays__UnLoadIPRPCostTables;
// void CTwoDimArrays::Update2DACacheCExoLinkedListTemplatedC2DA*, int, C2DA*
extern void * const CTwoDimArrays__Update2DACache;

// public CVirtualMachine::CVirtualMachinevoid
extern void * const CVirtualMachine__CVirtualMachineCtor;
// public CVirtualMachine::~CVirtualMachinevoid
extern void * const CVirtualMachine__CVirtualMachineDtor;
// private void CVirtualMachine::Debuggerint*
extern void * const CVirtualMachine__Debugger;
// void CVirtualMachine::DeleteScriptCVirtualMachineScript*
extern void * const CVirtualMachine__DeleteScript;
// public void CVirtualMachine::DeleteScriptSituationvoid*
extern void * const CVirtualMachine__DeleteScriptSituation;
// public int CVirtualMachine::ExecuteCodeint*, char*, int, CVirtualMachineDebuggingContext*
extern void * const CVirtualMachine__ExecuteCode;
// public int CVirtualMachine::GetRunScriptReturnValueint*, void**
extern void * const CVirtualMachine__GetRunScriptReturnValue;
// void CVirtualMachine::GetScriptLogconst CExoString&
extern void * const CVirtualMachine__GetScriptLog;
// void CVirtualMachine::InitializeScriptCVirtualMachineScript*, char*, int
extern void * const CVirtualMachine__InitializeScript;
// private int CVirtualMachine::LoadScriptSituation_InternalCVirtualMachineScript**, CResGFF*, CResStruct*
extern void * const CVirtualMachine__LoadScriptSituation_Internal;
// void CVirtualMachine::PopInstructionPtrint*
extern void * const CVirtualMachine__PopInstructionPtr;
// void CVirtualMachine::PushInstructionPtrint
extern void * const CVirtualMachine__PushInstructionPtr;
// private int CVirtualMachine::ReadScriptFileCExoString*
extern void * const CVirtualMachine__ReadScriptFile;
// public int CVirtualMachine::RunScriptCExoString*, unsigned long int, int
extern void * const CVirtualMachine__RunScript;
// private int CVirtualMachine::RunScriptFileint
extern void * const CVirtualMachine__RunScriptFile;
// public int CVirtualMachine::RunScriptSituationvoid*, unsigned long int, int
extern void * const CVirtualMachine__RunScriptSituation;
// private int CVirtualMachine::SaveScriptSituation_InternalCVirtualMachineScript*, CResGFF*, CResStruct*
extern void * const CVirtualMachine__SaveScriptSituation_Internal;
// public void CVirtualMachine::SetCommandImplementerCVirtualMachineCmdImplementer*
extern void * const CVirtualMachine__SetCommandImplementer;
// public void CVirtualMachine::SetDebugGUIFlagint
extern void * const CVirtualMachine__SetDebugGUIFlag;
// private int CVirtualMachine::SetUpScriptSituationCVirtualMachineScript*
extern void * const CVirtualMachine__SetUpScriptSituation;
// private int CVirtualMachine::StackPopCommand_InternalCVirtualMachineScript**
extern void * const CVirtualMachine__StackPopCommand_Internal;
// public int CVirtualMachine::StackPopEngineStructureint, void**
extern void * const CVirtualMachine__StackPopEngineStructure;
// public int CVirtualMachine::StackPopFloatfloat*
extern void * const CVirtualMachine__StackPopFloat;
// public int CVirtualMachine::StackPopIntegerint*
extern void * const CVirtualMachine__StackPopInteger;
// public int CVirtualMachine::StackPopObjectunsigned long int*
extern void * const CVirtualMachine__StackPopObject;
// public int CVirtualMachine::StackPopStringCExoString*
extern void * const CVirtualMachine__StackPopString;
// public int CVirtualMachine::StackPopVectorVector*
extern void * const CVirtualMachine__StackPopVector;
// public int CVirtualMachine::StackPushEngineStructureint, void*
extern void * const CVirtualMachine__StackPushEngineStructure;
// public int CVirtualMachine::StackPushFloatfloat
extern void * const CVirtualMachine__StackPushFloat;
// public int CVirtualMachine::StackPushIntegerint
extern void * const CVirtualMachine__StackPushInteger;
// public int CVirtualMachine::StackPushObjectunsigned long int
extern void * const CVirtualMachine__StackPushObject;
// public int CVirtualMachine::StackPushStringconst CExoString&
extern void * const CVirtualMachine__StackPushString;
// public int CVirtualMachine::StackPushVectorVector
extern void * const CVirtualMachine__StackPushVector;
// void CVirtualMachine::Test_RunAllScriptsInDirectoryCExoString&
extern void * const CVirtualMachine__Test_RunAllScriptsInDirectory;

// CVirtualMachineCache::~CVirtualMachineCachevoid
extern void * const CVirtualMachineCache__CVirtualMachineCacheDtor;
// public void CVirtualMachineCache::ClearAllFilesvoid
extern void * const CVirtualMachineCache__ClearAllFiles;
// public void CVirtualMachineCache::PrecacheFileconst CExoString&
extern void * const CVirtualMachineCache__PrecacheFile;

// public CVirtualMachineCmdImplementer::~CVirtualMachineCmdImplementervoid
extern void * const CVirtualMachineCmdImplementer__CVirtualMachineCmdImplementerDtor;

// public CVirtualMachineDebuggerInstance::CVirtualMachineDebuggerInstancevoid
extern void * const CVirtualMachineDebuggerInstance__CVirtualMachineDebuggerInstanceCtor;
// public CVirtualMachineDebuggerInstance::~CVirtualMachineDebuggerInstancevoid
extern void * const CVirtualMachineDebuggerInstance__CVirtualMachineDebuggerInstanceDtor;
// private int CVirtualMachineDebuggerInstance::DebuggerDisplayCurrentLocationint, int
extern void * const CVirtualMachineDebuggerInstance__DebuggerDisplayCurrentLocation;
// public int CVirtualMachineDebuggerInstance::DebuggerMainLoopvoid
extern void * const CVirtualMachineDebuggerInstance__DebuggerMainLoop;
// private int CVirtualMachineDebuggerInstance::DebuggerSingleStepint
extern void * const CVirtualMachineDebuggerInstance__DebuggerSingleStep;
// private int CVirtualMachineDebuggerInstance::FindEmptyWatchViewEntryvoid
extern void * const CVirtualMachineDebuggerInstance__FindEmptyWatchViewEntry;
// void CVirtualMachineDebuggerInstance::FindWatchViewEntryCExoString*, CExoString*, int
extern void * const CVirtualMachineDebuggerInstance__FindWatchViewEntry;
// private CExoString CVirtualMachineDebuggerInstance::GenerateCallStackParameterViewint, CExoString*, CExoString*
extern void * const CVirtualMachineDebuggerInstance__GenerateCallStackParameterView;
// private CExoString CVirtualMachineDebuggerInstance::GenerateCallStackViewint, int, int
extern void * const CVirtualMachineDebuggerInstance__GenerateCallStackView;
// void CVirtualMachineDebuggerInstance::GenerateDebugVariableLocationForParameterint, int
extern void * const CVirtualMachineDebuggerInstance__GenerateDebugVariableLocationForParameter;
// void CVirtualMachineDebuggerInstance::GenerateFunctionIDFromInstructionPointerint
extern void * const CVirtualMachineDebuggerInstance__GenerateFunctionIDFromInstructionPointer;
// public int CVirtualMachineDebuggerInstance::GenerateLineNumberFromInstructionPointerint, int
extern void * const CVirtualMachineDebuggerInstance__GenerateLineNumberFromInstructionPointer;
// private int CVirtualMachineDebuggerInstance::GenerateStackSizeAtInstructionPointerint, int
extern void * const CVirtualMachineDebuggerInstance__GenerateStackSizeAtInstructionPointer;
// private CExoString CVirtualMachineDebuggerInstance::GenerateTypeNameCExoString*
extern void * const CVirtualMachineDebuggerInstance__GenerateTypeName;
// private int CVirtualMachineDebuggerInstance::GenerateTypeSizeCExoString*
extern void * const CVirtualMachineDebuggerInstance__GenerateTypeSize;
// private CExoString CVirtualMachineDebuggerInstance::GenerateTypeValueFromStackLocationint, CExoString*
extern void * const CVirtualMachineDebuggerInstance__GenerateTypeValueFromStackLocation;
// private int CVirtualMachineDebuggerInstance::GetNextDebugVariableint, int, int
extern void * const CVirtualMachineDebuggerInstance__GetNextDebugVariable;
// private int CVirtualMachineDebuggerInstance::LoadDebugInfoCVirtualMachineDebugLoader*
extern void * const CVirtualMachineDebuggerInstance__LoadDebugInfo;
// void CVirtualMachineDebuggerInstance::LoadDebugInfoLineunsigned char*, unsigned long int, unsigned long int, unsigned long int*
extern void * const CVirtualMachineDebuggerInstance__LoadDebugInfoLine;
// private char* CVirtualMachineDebuggerInstance::LoadScriptLineunsigned char*, unsigned long int, unsigned long int, unsigned long int*, int
extern void * const CVirtualMachineDebuggerInstance__LoadScriptLine;
// private int CVirtualMachineDebuggerInstance::ParseAndExecuteMessageint*
extern void * const CVirtualMachineDebuggerInstance__ParseAndExecuteMessage;
// void CVirtualMachineDebuggerInstance::ReadIntegerFromInputint*, int*
extern void * const CVirtualMachineDebuggerInstance__ReadIntegerFromInput;
// private int CVirtualMachineDebuggerInstance::ReadStringFromInputint*, CExoString*
extern void * const CVirtualMachineDebuggerInstance__ReadStringFromInput;
// private void CVirtualMachineDebuggerInstance::SendCallStackWindowUpdateCommandsvoid
extern void * const CVirtualMachineDebuggerInstance__SendCallStackWindowUpdateCommands;
// private void CVirtualMachineDebuggerInstance::SendCodeWindowUpdateCommandsCExoString, int
extern void * const CVirtualMachineDebuggerInstance__SendCodeWindowUpdateCommands;
// private void CVirtualMachineDebuggerInstance::SendLabelsAndKeywordsvoid
extern void * const CVirtualMachineDebuggerInstance__SendLabelsAndKeywords;
// private void CVirtualMachineDebuggerInstance::SendWatchWindowEntryCExoString*, CExoString*, CExoString*, CExoString*, int
extern void * const CVirtualMachineDebuggerInstance__SendWatchWindowEntry;
// private void CVirtualMachineDebuggerInstance::SendWatchWindowUpdateCommandsint
extern void * const CVirtualMachineDebuggerInstance__SendWatchWindowUpdateCommands;
// public void CVirtualMachineDebuggerInstance::ShutDownDebuggervoid
extern void * const CVirtualMachineDebuggerInstance__ShutDownDebugger;
// public int CVirtualMachineDebuggerInstance::SpawnDebuggervoid
extern void * const CVirtualMachineDebuggerInstance__SpawnDebugger;
// private void CVirtualMachineDebuggerInstance::ToggleWatchWindowExpansionCExoString
extern void * const CVirtualMachineDebuggerInstance__ToggleWatchWindowExpansion;

// public CVirtualMachineDebugLoader::~CVirtualMachineDebugLoadervoid
extern void * const CVirtualMachineDebugLoader__CVirtualMachineDebugLoaderDtor;
// public int CVirtualMachineDebugLoader::DemandDebugInfoCExoString*
extern void * const CVirtualMachineDebugLoader__DemandDebugInfo;
// void CVirtualMachineDebugLoader::GetDataPtrvoid
extern void * const CVirtualMachineDebugLoader__GetDataPtr;
// void CVirtualMachineDebugLoader::GetSizevoid
extern void * const CVirtualMachineDebugLoader__GetSize;
// void CVirtualMachineDebugLoader::ReleaseDebugInfovoid
extern void * const CVirtualMachineDebugLoader__ReleaseDebugInfo;

// CVirtualMachineFile::CVirtualMachineFilevoid
extern void * const CVirtualMachineFile__CVirtualMachineFileCtor;
// public CVirtualMachineFile::~CVirtualMachineFilevoid
extern void * const CVirtualMachineFile__CVirtualMachineFileDtor;
// void CVirtualMachineFile::GetDatachar**, unsigned long int&
extern void * const CVirtualMachineFile__GetData;
// void CVirtualMachineFile::LoadFileconst CExoString&
extern void * const CVirtualMachineFile__LoadFile;
// void CVirtualMachineFile::UnloadFilevoid
extern void * const CVirtualMachineFile__UnloadFile;

// CVirtualMachineStack::CVirtualMachineStackvoid
extern void * const CVirtualMachineStack__CVirtualMachineStackCtor;
// public CVirtualMachineStack::~CVirtualMachineStackvoid
extern void * const CVirtualMachineStack__CVirtualMachineStackDtor;
// public void CVirtualMachineStack::AddToTopOfStackint
extern void * const CVirtualMachineStack__AddToTopOfStack;
// public void CVirtualMachineStack::AssignLocationToLocationint, int
extern void * const CVirtualMachineStack__AssignLocationToLocation;
// public void CVirtualMachineStack::ClearStackvoid
extern void * const CVirtualMachineStack__ClearStack;
// public void CVirtualMachineStack::CopyFromStackCVirtualMachineStack*, int, int
extern void * const CVirtualMachineStack__CopyFromStack;
// void CVirtualMachineStack::GetBasePointervoid
extern void * const CVirtualMachineStack__GetBasePointer;
// void CVirtualMachineStack::GetStackPointervoid
extern void * const CVirtualMachineStack__GetStackPointer;
// void CVirtualMachineStack::InitializeStackvoid
extern void * const CVirtualMachineStack__InitializeStack;
// public int CVirtualMachineStack::LoadStackCResGFF*, CResStruct*
extern void * const CVirtualMachineStack__LoadStack;
// void CVirtualMachineStack::ModifyIntegerAtLocationint, int
extern void * const CVirtualMachineStack__ModifyIntegerAtLocation;
// public int CVirtualMachineStack::SaveStackCResGFF*, CResStruct*
extern void * const CVirtualMachineStack__SaveStack;
// void CVirtualMachineStack::SetBasePointerint
extern void * const CVirtualMachineStack__SetBasePointer;
// public void CVirtualMachineStack::SetStackPointerint
extern void * const CVirtualMachineStack__SetStackPointer;

// public CWorldTimer::CWorldTimervoid
extern void * const CWorldTimer__CWorldTimerCtor;
// public CWorldTimer::~CWorldTimervoid
extern void * const CWorldTimer__CWorldTimerDtor;
// public unsigned long int CWorldTimer::AddWorldTimesunsigned long int, unsigned long int, unsigned long int, unsigned long int, unsigned long int*, unsigned long int*
extern void * const CWorldTimer__AddWorldTimes;
// public void CWorldTimer::AdvanceToTimeint, int, int, int
extern void * const CWorldTimer__AdvanceToTime;
// public int CWorldTimer::CompareWorldTimesunsigned long int, unsigned long int, unsigned long int, unsigned long int
extern void * const CWorldTimer__CompareWorldTimes;
// public void CWorldTimer::ConvertFromCalendarDayunsigned long int, unsigned long int*, unsigned long int*, unsigned long int*
extern void * const CWorldTimer__ConvertFromCalendarDay;
// public void CWorldTimer::ConvertFromTimeOfDayunsigned long int, unsigned long int*, unsigned long int*, unsigned long int*, unsigned long int*
extern void * const CWorldTimer__ConvertFromTimeOfDay;
// public unsigned long int CWorldTimer::ConvertToCalendarDayunsigned long int, unsigned long int, unsigned long int
extern void * const CWorldTimer__ConvertToCalendarDay;
// void CWorldTimer::ConvertToTimeOfDayunsigned long int, unsigned long int, unsigned long int, unsigned long int
extern void * const CWorldTimer__ConvertToTimeOfDay;
// public unsigned long int CWorldTimer::GetCalendarDayFromSecondsfloat
extern void * const CWorldTimer__GetCalendarDayFromSeconds;
// public unsigned__int64 CWorldTimer::GetSnapshotTimevoid
extern void * const CWorldTimer__GetSnapshotTime;
// public unsigned__int64 CWorldTimer::GetSnapshotTimeDifferencevoid
extern void * const CWorldTimer__GetSnapshotTimeDifference;
// void CWorldTimer::GetTimeDifferenceFromWorldTimeunsigned long int, unsigned long int
extern void * const CWorldTimer__GetTimeDifferenceFromWorldTime;
// public unsigned long int CWorldTimer::GetTimeOfDayFromSecondsfloat
extern void * const CWorldTimer__GetTimeOfDayFromSeconds;
// public void CWorldTimer::GetWorldTimeunsigned long int*, unsigned long int*
extern void * const CWorldTimer__GetWorldTime;
// void CWorldTimer::GetWorldTimeCalendarDayvoid
extern void * const CWorldTimer__GetWorldTimeCalendarDay;
// void CWorldTimer::GetWorldTimeCalendarDayStringvoid
extern void * const CWorldTimer__GetWorldTimeCalendarDayString;
// public unsigned long int CWorldTimer::GetWorldTimeDayvoid
extern void * const CWorldTimer__GetWorldTimeDay;
// public unsigned long int CWorldTimer::GetWorldTimeHourvoid
extern void * const CWorldTimer__GetWorldTimeHour;
// public unsigned long int CWorldTimer::GetWorldTimeMillisecondvoid
extern void * const CWorldTimer__GetWorldTimeMillisecond;
// public unsigned long int CWorldTimer::GetWorldTimeMinutevoid
extern void * const CWorldTimer__GetWorldTimeMinute;
// public unsigned long int CWorldTimer::GetWorldTimeMonthvoid
extern void * const CWorldTimer__GetWorldTimeMonth;
// public unsigned long int CWorldTimer::GetWorldTimeSecondvoid
extern void * const CWorldTimer__GetWorldTimeSecond;
// void CWorldTimer::GetWorldTimeTimeOfDayvoid
extern void * const CWorldTimer__GetWorldTimeTimeOfDay;
// void CWorldTimer::GetWorldTimeTimeOfDayStringvoid
extern void * const CWorldTimer__GetWorldTimeTimeOfDayString;
// public unsigned long int CWorldTimer::GetWorldTimeYearvoid
extern void * const CWorldTimer__GetWorldTimeYear;
// public void CWorldTimer::PauseWorldTimervoid
extern void * const CWorldTimer__PauseWorldTimer;
// public void CWorldTimer::ResetTimerCWorldTimer*
extern void * const CWorldTimer__ResetTimer;
// void CWorldTimer::SetFixedSnapshotRateint, int
extern void * const CWorldTimer__SetFixedSnapshotRate;
// public void CWorldTimer::SetMinutesPerHourunsigned char
extern void * const CWorldTimer__SetMinutesPerHour;
// public void CWorldTimer::SetSnapshotTimevoid
extern void * const CWorldTimer__SetSnapshotTime;
// public void CWorldTimer::SetWorldTimeunsigned long int, unsigned long int, unsigned long int, unsigned long int, unsigned long int, unsigned long int, unsigned long int, int
extern void * const CWorldTimer__SetWorldTime__0;
// public void CWorldTimer::SetWorldTimeunsigned long int, unsigned long int, int
extern void * const CWorldTimer__SetWorldTime__1;
// public unsigned long int CWorldTimer::SubtractWorldTimesunsigned long int, unsigned long int, unsigned long int, unsigned long int, unsigned long int*, unsigned long int*
extern void * const CWorldTimer__SubtractWorldTimes;
// void CWorldTimer::TranslateWorldTimeToStringunsigned long int, unsigned long int, CExoString&, CExoString&
extern void * const CWorldTimer__TranslateWorldTimeToString;
// public void CWorldTimer::UnpauseWorldTimervoid
extern void * const CWorldTimer__UnpauseWorldTimer;

// void FreeStanding::AdminClientInfoCExoString
extern void * const FreeStanding__AdminClientInfo;
// void FreeStanding::AdminClientListvoid
extern void * const FreeStanding__AdminClientList;
// void FreeStanding::AdminKickCExoString
extern void * const FreeStanding__AdminKick;
// void FreeStanding::AdminLoadGameint
extern void * const FreeStanding__AdminLoadGame;
// void FreeStanding::AdminLoadModulechar*
extern void * const FreeStanding__AdminLoadModule;
// int FreeStanding::AdminSaveGameint, CExoString, int
extern void * const FreeStanding__AdminSaveGame;
// void FreeStanding::AdminSayCExoString
extern void * const FreeStanding__AdminSay;
// void FreeStanding::AdminSetPortunsigned long int
extern void * const FreeStanding__AdminSetPort;
// void FreeStanding::AdminStatusvoid
extern void * const FreeStanding__AdminStatus;
// void FreeStanding::ExoFreevoid*
extern void * const FreeStanding__ExoFree;
// void* FreeStanding::ExoMallocunsigned int
extern void * const FreeStanding__ExoMalloc;

// void Matrix::getquaternionvoid const
extern void * const Matrix__getquaternion;

// void Plane::Transformconst Vector&, const Quaternion&
extern void * const Plane__Transform;

// void Quaternion::__amlfloat
extern void * const Quaternion____aml;

// void Vector::__advfloat
extern void * const Vector____adv;
// void Vector::__amiconst Vector&
extern void * const Vector____ami;
// void Vector::__amlfloat
extern void * const Vector____aml;
// void Vector::__aplconst Vector&
extern void * const Vector____apl;
// public void Vector::Normalizevoid
extern void * const Vector__Normalize;

}

#endif // NWNX_UNIFIED__FUNCTIONS_HPP