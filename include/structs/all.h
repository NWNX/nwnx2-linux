/*
 *  NWNeXalt - Empty File
 *  (c) 2007 Doug Swarin (zac@intertex.net)
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *  $Id$
 *  $HeadURL$
 *
 */

#ifndef _NX_NWN_STRUCT_ALL_
#define _NX_NWN_STRUCT_ALL_

struct C2DA_s;                            typedef struct C2DA_s                            C2DA;
struct CAppManager_s;                     typedef struct CAppManager_s                     CAppManager;
struct CBaseExoApp_s;                     typedef struct CBaseExoApp_s                     CBaseExoApp;
struct CCombatInformation_s;              typedef struct CCombatInformation_s              CCombatInformation;
struct CDialogNode_s;                     typedef struct CDialogNode_s                     CDialogNode;
struct CDialogReply_s;                    typedef struct CDialogReply_s                    CDialogReply;
struct CDialogSpeak_s;                    typedef struct CDialogSpeak_s                    CDialogSpeak;
struct CERFFile_s;                        typedef struct CERFFile_s                        CERFFile;
struct CEncounterListEntry_s;             typedef struct CEncounterListEntry_s             CEncounterListEntry;
struct CEvent_s;                          typedef struct CEvent_s                          CEvent;
struct CExoAliasList_s;                   typedef struct CExoAliasList_s                   CExoAliasList;
struct CExoArrayList_float_s;             typedef struct CExoArrayList_float_s             CExoArrayList_float;
struct CExoArrayList_int32_s;             typedef struct CExoArrayList_int32_s             CExoArrayList_int32;
struct CExoArrayList_int8_s;              typedef struct CExoArrayList_int8_s              CExoArrayList_int8;
struct CExoArrayList_ptr_s;               typedef struct CExoArrayList_ptr_s               CExoArrayList_ptr;
struct CExoArrayList_uint16_s;            typedef struct CExoArrayList_uint16_s            CExoArrayList_uint16;
struct CExoArrayList_uint32_s;            typedef struct CExoArrayList_uint32_s            CExoArrayList_uint32;
struct CExoArrayList_uint64_s;            typedef struct CExoArrayList_uint64_s            CExoArrayList_uint64;
struct CExoArrayList_uint8_s;             typedef struct CExoArrayList_uint8_s             CExoArrayList_uint8;
struct CExoBaseInternal_s;                typedef struct CExoBaseInternal_s                CExoBaseInternal;
struct CExoBase_s;                        typedef struct CExoBase_s                        CExoBase;
struct CExoDebug_s;                       typedef struct CExoDebug_s                       CExoDebug;
struct CExoFile_s;                        typedef struct CExoFile_s                        CExoFile;
struct CExoIni_s;                         typedef struct CExoIni_s                         CExoIni;
struct CExoKeyTable_s;                    typedef struct CExoKeyTable_s                    CExoKeyTable;
struct CExoLinkedListInternal_s;          typedef struct CExoLinkedListInternal_s          CExoLinkedListInternal;
struct CExoLinkedListNode_s;              typedef struct CExoLinkedListNode_s              CExoLinkedListNode;
struct CExoLinkedList_s;                  typedef struct CExoLinkedList_s                  CExoLinkedList;
struct CExoLocStringElement_s;            typedef struct CExoLocStringElement_s            CExoLocStringElement;
struct CExoLocString_s;                   typedef struct CExoLocString_s                   CExoLocString;
struct CExoRand_s;                        typedef struct CExoRand_s                        CExoRand;
struct CExoResMan_s;                      typedef struct CExoResMan_s                      CExoResMan;
struct CExoStringList_s;                  typedef struct CExoStringList_s                  CExoStringList;
struct CExoString_s;                      typedef struct CExoString_s                      CExoString;
struct CExoTimers_s;                      typedef struct CExoTimers_s                      CExoTimers;
struct CExtendedServerInfo_s;             typedef struct CExtendedServerInfo_s             CExtendedServerInfo;
struct CFactionManager_s;                 typedef struct CFactionManager_s                 CFactionManager;
struct CGameEffectListHandler_s;          typedef struct CGameEffectListHandler_s          CGameEffectListHandler;
struct CGameEffect_s;                     typedef struct CGameEffect_s                     CGameEffect;
struct CGameObjectArray_s;                typedef struct CGameObjectArray_s                CGameObjectArray;
struct CGameObject_VTable_s;              typedef struct CGameObject_VTable_s              CGameObject_VTable;
struct CGameObject_s;                     typedef struct CGameObject_s                     CGameObject;
struct CItemRepository_s;                 typedef struct CItemRepository_s                 CItemRepository;
struct CLastUpdateObject_s;               typedef struct CLastUpdateObject_s               CLastUpdateObject;
struct CLastUpdatePartyObject_s;          typedef struct CLastUpdatePartyObject_s          CLastUpdatePartyObject;
struct CNWAmbientSound_s;                 typedef struct CNWAmbientSound_s                 CNWAmbientSound;
struct CNWArea_s;                         typedef struct CNWArea_s                         CNWArea;
struct CNWBaseItemArray_s;                typedef struct CNWBaseItemArray_s                CNWBaseItemArray;
struct CNWBaseItem_s;                     typedef struct CNWBaseItem_s                     CNWBaseItem;
struct CNWCCMessageData_s;                typedef struct CNWCCMessageData_s                CNWCCMessageData;
struct CNWClass_s;                        typedef struct CNWClass_s                        CNWClass;
struct CNWCreatureStatsUpdate_s;          typedef struct CNWCreatureStatsUpdate_s          CNWCreatureStatsUpdate;
struct CNWDomain_s;                       typedef struct CNWDomain_s                       CNWDomain;
struct CNWFeat_s;                         typedef struct CNWFeat_s                         CNWFeat;
struct CNWItemProperty_s;                 typedef struct CNWItemProperty_s                 CNWItemProperty;
struct CNWItem_s;                         typedef struct CNWItem_s                         CNWItem;
struct CNWMessage_s;                      typedef struct CNWMessage_s                      CNWMessage;
struct CNWNameGen_s;                      typedef struct CNWNameGen_s                      CNWNameGen;
struct CNWRace_s;                         typedef struct CNWRace_s                         CNWRace;
struct CNWRules_s;                        typedef struct CNWRules_s                        CNWRules;
struct CNWSActionNode_s;                  typedef struct CNWSActionNode_s                      CNWSActionNode;
struct CNWSAmbientSound_s;                typedef struct CNWSAmbientSound_s                CNWSAmbientSound;
struct CNWSAreaGridSuccessors_s;          typedef struct CNWSAreaGridSuccessors_s          CNWSAreaGridSuccessors;
struct CNWSAreaOfEffectObject_s;          typedef struct CNWSAreaOfEffectObject_s          CNWSAreaOfEffectObject;
struct CNWSArea_s;                        typedef struct CNWSArea_s                        CNWSArea;
struct CNWSBarter_s;                      typedef struct CNWSBarter_s                      CNWSBarter;
struct CNWSClient_s;                      typedef struct CNWSClient_s                      CNWSClient;
struct CNWSCombatAttackData_s;            typedef struct CNWSCombatAttackData_s            CNWSCombatAttackData;
struct CNWSCombatRoundAction_s;           typedef struct CNWSCombatRoundAction_s           CNWSCombatRoundAction;
struct CNWSCombatRound_s;                 typedef struct CNWSCombatRound_s                 CNWSCombatRound;
struct CNWSCreatureAppearanceInfo_s;      typedef struct CNWSCreatureAppearanceInfo_s      CNWSCreatureAppearanceInfo;
struct CNWSCreatureStats_ClassInfo_s;     typedef struct CNWSCreatureStats_ClassInfo_s     CNWSCreatureStats_ClassInfo;
struct CNWSCreatureStats_s;               typedef struct CNWSCreatureStats_s               CNWSCreatureStats;
struct CNWSCreature_s;                    typedef struct CNWSCreature_s                    CNWSCreature;
struct CNWSDialog_s;                      typedef struct CNWSDialog_s                      CNWSDialog;
struct CNWSDoor_s;                        typedef struct CNWSDoor_s                        CNWSDoor;
struct CNWSDungeonMaster_s;               typedef struct CNWSDungeonMaster_s               CNWSDungeonMaster;
struct CNWSEffectListHandler_s;           typedef struct CNWSEffectListHandler_s           CNWSEffectListHandler;
struct CNWSEncounter_s;                   typedef struct CNWSEncounter_s                   CNWSEncounter;
struct CNWSFaction_s;                     typedef struct CNWSFaction_s                     CNWSFaction;
struct CNWSForcedAction_s;                typedef struct CNWSForcedAction_s                CNWSForcedAction;
struct CNWSInventory_s;                   typedef struct CNWSInventory_s                   CNWSInventory;
struct CNWSItemPropertyHandler_s;         typedef struct CNWSItemPropertyHandler_s         CNWSItemPropertyHandler;
struct CNWSItem_s;                        typedef struct CNWSItem_s                        CNWSItem;
struct CNWSJournal_s;                     typedef struct CNWSJournal_s                     CNWSJournal;
struct CNWSMessage_s;                     typedef struct CNWSMessage_s                     CNWSMessage;
struct CNWSModule_s;                      typedef struct CNWSModule_s                      CNWSModule;
struct CNWSObject_s;                      typedef struct CNWSObject_s                      CNWSObject;
struct CNWSPlaceable_s;                   typedef struct CNWSPlaceable_s                   CNWSPlaceable;
struct CNWSPlayerInventoryGUI_s;          typedef struct CNWSPlayerInventoryGUI_s          CNWSPlayerInventoryGUI;
struct CNWSPlayerLUOInventory_s;          typedef struct CNWSPlayerLUOInventory_s          CNWSPlayerLUOInventory;
struct CNWSPlayerLUOSortedObjectList_s;   typedef struct CNWSPlayerLUOSortedObjectList_s   CNWSPlayerLUOSortedObjectList;
struct CNWSPlayerLastUpdateObject_s;      typedef struct CNWSPlayerLastUpdateObject_s      CNWSPlayerLastUpdateObject;
struct CNWSPlayerTURD_s;                  typedef struct CNWSPlayerTURD_s                  CNWSPlayerTURD;
struct CNWSPlayer_s;                      typedef struct CNWSPlayer_s                      CNWSPlayer;
struct CNWSQuickbarButton_s;              typedef struct CNWSQuickbarButton_s              CNWSQuickbarButton;
struct CNWSScriptVarTable_s;              typedef struct CNWSScriptVarTable_s              CNWSScriptVarTable;
struct CNWSSoundObjectTimeOfDay_s;        typedef struct CNWSSoundObjectTimeOfDay_s        CNWSSoundObjectTimeOfDay;
struct CNWSSoundObject_s;                 typedef struct CNWSSoundObject_s                 CNWSSoundObject;
struct CNWSStats_FeatUses_s;              typedef struct CNWSStats_FeatUses_s              CNWSStats_FeatUses;
struct CNWLevelStats_s;                   typedef struct CNWLevelStats_s                   CNWLevelStats;
struct CNWSStats_SpecAbil_s;              typedef struct CNWSStats_SpecAbil_s              CNWSStats_SpecAbil;
struct CNWSStats_Spell_s;                 typedef struct CNWSStats_Spell_s                 CNWSStats_Spell;
struct CNWSStore_s;                       typedef struct CNWSStore_s                       CNWSStore;
struct CNWSTile_s;                        typedef struct CNWSTile_s                        CNWSTile;
struct CNWSTrigger_s;                     typedef struct CNWSTrigger_s                     CNWSTrigger;
struct CNWSWaypoint_s;                    typedef struct CNWSWaypoint_s                    CNWSWaypoint;
struct CNWSkill_s;                        typedef struct CNWSkill_s                        CNWSkill;
struct CNWSpellArray_s;                   typedef struct CNWSpellArray_s                   CNWSpellArray;
struct CNWSpell_s;                        typedef struct CNWSpell_s                        CNWSpell;
struct CNWTileData_s;                     typedef struct CNWTileData_s                     CNWTileData;
struct CNWTileSetManager_s;               typedef struct CNWTileSetManager_s               CNWTileSetManager;
struct CNWVirtualMachineCommands_s;       typedef struct CNWVirtualMachineCommands_s       CNWVirtualMachineCommands;
struct CNWVirtualMachineImplementation_s; typedef struct CNWVirtualMachineImplementation_s CNWVirtualMachineImplementation;
struct CNetLayer_s;                       typedef struct CNetLayer_s                       CNetLayer;
struct CObjectLookupTable_s;              typedef struct CObjectLookupTable_s              CObjectLookupTable;
struct CObjectTableManager_s;             typedef struct CObjectTableManager_s             CObjectTableManager;
struct CPathfindInformation_s;            typedef struct CPathfindInformation_s            CPathfindInformation;
struct CRes2DA_s;                         typedef struct CRes2DA_s                         CRes2DA;
struct CResDWK_s;                         typedef struct CResDWK_s                         CResDWK;
struct CResGFFFieldIDHash_s;              typedef struct CResGFFFieldIDHash_s              CResGFFFieldIDHash;
struct CResGFF_s;                         typedef struct CResGFF_s                         CResGFF;
struct CResLTR_s;                         typedef struct CResLTR_s                         CResLTR;
struct CResList_s;                        typedef struct CResList_s                        CResList;
struct CResNCS_s;                         typedef struct CResNCS_s                         CResNCS;
struct CResNDB_s;                         typedef struct CResNDB_s                         CResNDB;
struct CResNSS_s;                         typedef struct CResNSS_s                         CResNSS;
struct CResPWK_s;                         typedef struct CResPWK_s                         CResPWK;
struct CResRef_s;                         typedef struct CResRef_s                         CResRef;
struct CResSET_s;                         typedef struct CResSET_s                         CResSET;
struct CResStruct_s;                      typedef struct CResStruct_s                      CResStruct;
struct CResTGA_s;                         typedef struct CResTGA_s                         CResTGA;
struct CResWOK_s;                         typedef struct CResWOK_s                         CResWOK;
struct CRes_s;                            typedef struct CRes_s                            CRes;
struct CResource_s;                       typedef struct CResource_s                       CResource;
struct CScriptCompiler_s;                 typedef struct CScriptCompiler_s                 CScriptCompiler;
struct CScriptEvent_s;                    typedef struct CScriptEvent_s                    CScriptEvent;
struct CScriptLocation_s;                 typedef struct CScriptLocation_s                 CScriptLocation;
struct CScriptVariable_s;                 typedef struct CScriptVariable_s                 CScriptVariable;
struct CServerAIMaster_s;                 typedef struct CServerAIMaster_s                 CServerAIMaster;
struct CServerExoAppInternal_s;           typedef struct CServerExoAppInternal_s           CServerExoAppInternal;
struct CServerExoApp_s;                   typedef struct CServerExoApp_s                   CServerExoApp;
struct CTlkFile_s;                        typedef struct CTlkFile_s                        CTlkFile;
struct CTlkTableToken_s;                  typedef struct CTlkTableToken_s                  CTlkTableToken;
struct CTlkTable_s;                       typedef struct CTlkTable_s                       CTlkTable;
struct CTwoDimArrays_s;                   typedef struct CTwoDimArrays_s                   CTwoDimArrays;
struct CVirtualMachine_s;                 typedef struct CVirtualMachine_s                 CVirtualMachine;
struct CVirtualMachineCmdImplementer_s;   typedef struct CVirtualMachineCmdImplementer_s   CVirtualMachineCmdImplementer;
struct CVirtualMachineDebuggingContext_s; typedef struct CVirtualMachineDebuggingContext_s CVirtualMachineDebuggingContext;
struct CVirtualMachineScript_s;           typedef struct CVirtualMachineScript_s           CVirtualMachineScript;
struct CWorldTimer_s;                     typedef struct CWorldTimer_s                     CWorldTimer;
struct Vector_s;                          typedef struct Vector_s                          Vector;


#include "structs/Vector.h"

#include "structs/CExoString.h"
#include "structs/CExoStringList.h"
#include "structs/CExoLocString.h"
#include "structs/CExoLocStringElement.h"

#include "structs/CExoAliasList.h"
#include "structs/CExoArrayList.h"
#include "structs/CExoBase.h"
#include "structs/CExoBaseInternal.h"
#include "structs/CExoDebug.h"
#include "structs/CExoFile.h"
#include "structs/CExoIni.h"
#include "structs/CExoKeyTable.h"
#include "structs/CExoLinkedList.h"
#include "structs/CExoLinkedListHeader.h"
#include "structs/CExoLinkedListNode.h"
#include "structs/CExoRand.h"
#include "structs/CExoResMan.h"
#include "structs/CExoTimers.h"


#include "structs/C2DA.h"
#include "structs/CAppManager.h"
#include "structs/CBaseExoApp.h"
#include "structs/CCombatInformation.h"
#include "structs/CDialogReply.h"
#include "structs/CDialogSpeak.h"
#include "structs/CDialogNode.h"
#include "structs/CERFFile.h"
#include "structs/CEncounterListEntry.h"
#include "structs/CEvent.h"
#include "structs/CExtendedServerInfo.h"
#include "structs/CFactionManager.h"
#include "structs/CGameEffect.h"
#include "structs/CGameEffectListHandler.h"
#include "structs/CGameObject.h"
#include "structs/CGameObjectArray.h"
#include "structs/CGameObject_VTable.h"
#include "structs/CItemRepository.h"
#include "structs/CLastUpdateObject.h"
#include "structs/CLastUpdatePartyObject.h"
#include "structs/CNetLayer.h"

#include "structs/CNWAmbientSound.h"
#include "structs/CNWArea.h"
#include "structs/CNWBaseItem.h"
#include "structs/CNWBaseItemArray.h"
#include "structs/CNWCCMessageData.h"
#include "structs/CNWClass.h"
#include "structs/CNWCreatureStatsUpdate.h"
#include "structs/CNWDomain.h"
#include "structs/CNWFeat.h"
#include "structs/CNWItem.h"
#include "structs/CNWItemProperty.h"
#include "structs/CNWMessage.h"
#include "structs/CNWNameGen.h"
#include "structs/CNWRace.h"
#include "structs/CNWRules.h"
#include "structs/CNWSkill.h"
#include "structs/CNWSpell.h"
#include "structs/CNWSpellArray.h"
#include "structs/CNWTileData.h"
#include "structs/CNWTileSetManager.h"
#include "structs/CNWVirtualMachineCommands.h"
#include "structs/CNWVirtualMachineImplementation.h"

#include "structs/CNWSStats_FeatUses.h"
#include "structs/CNWSStats_Level.h"
#include "structs/CNWSStats_SpecAbil.h"
#include "structs/CNWSStats_Spell.h"
#include "structs/CNWSScriptVarTable.h"

#include "structs/CNWSObject.h"
#include "structs/CNWSAction.h"
#include "structs/CNWSAmbientSound.h"
#include "structs/CNWSArea.h"
#include "structs/CNWSAreaGridSuccessors.h"
#include "structs/CNWSAreaOfEffectObject.h"
#include "structs/CNWSBarter.h"
#include "structs/CNWSClient.h"
#include "structs/CNWSCombatAttackData.h"
#include "structs/CNWSCombatRound.h"
#include "structs/CNWSCombatRoundAction.h"
#include "structs/CNWSCreature.h"
#include "structs/CNWSCreatureAppearanceInfo.h"
#include "structs/CNWSCreatureClass.h"
#include "structs/CNWSCreatureStats.h"
#include "structs/CNWSDialog.h"
#include "structs/CNWSDoor.h"
#include "structs/CNWSDungeonMaster.h"
#include "structs/CNWSEffectListHandler.h"
#include "structs/CNWSEncounter.h"
#include "structs/CNWSFaction.h"
#include "structs/CNWSForcedAction.h"
#include "structs/CNWSInventory.h"
#include "structs/CNWSItem.h"
#include "structs/CNWSItemPropertyHandler.h"
#include "structs/CNWSJournal.h"
#include "structs/CNWSMessage.h"
#include "structs/CNWSModule.h"
#include "structs/CNWSPlaceable.h"
#include "structs/CNWSPlayer.h"
#include "structs/CNWSPlayerInventoryGUI.h"
#include "structs/CNWSPlayerLUOInventory.h"
#include "structs/CNWSPlayerLUOSortedObjectList.h"
#include "structs/CNWSPlayerLastUpdateObject.h"
#include "structs/CNWSPlayerTURD.h"
#include "structs/CNWSQuickbarButton.h"
#include "structs/CNWSSoundObject.h"
#include "structs/CNWSSoundObjectTimeOfDay.h"
#include "structs/CNWSStore.h"
#include "structs/CNWSTile.h"
#include "structs/CNWSTrigger.h"
#include "structs/CNWSWaypoint.h"

#include "structs/CNetLayer.h"
#include "structs/CObjectLookupTable.h"
#include "structs/CObjectTableManager.h"
#include "structs/CPathfindInformation.h"
#include "structs/CRes.h"
#include "structs/CRes2DA.h"
#include "structs/CResDWK.h"
#include "structs/CResGFF.h"
#include "structs/CResGFFFieldIDHash.h"
#include "structs/CResLTR.h"
#include "structs/CResList.h"
#include "structs/CResNCS.h"
#include "structs/CResNDB.h"
#include "structs/CResNSS.h"
#include "structs/CResPWK.h"
#include "structs/CResRef.h"
#include "structs/CResSET.h"
#include "structs/CResStruct.h"
#include "structs/CResTGA.h"
#include "structs/CResWOK.h"
#include "structs/CResource.h"
#include "structs/CScriptCompiler.h"
#include "structs/CScriptEvent.h"
#include "structs/CScriptLocation.h"
#include "structs/CScriptVariable.h"
#include "structs/CServerAIMaster.h"
#include "structs/CServerExoApp.h"
#include "structs/CServerExoAppInternal.h"
#include "structs/CTlkFile.h"
#include "structs/CTlkTable.h"
#include "structs/CTlkTableToken.h"
#include "structs/CTwoDimArrays.h"
#include "structs/CVirtualMachine.h"
#include "structs/CVirtualMachineCmdImplementer.h"
#include "structs/CVirtualMachineDebuggingContext.h"
#include "structs/CVirtualMachineScript.h"
#include "structs/CWorldTimer.h"

#endif /* _NX_NWN_STRUCT_ALL_ */

/* vim: set sw=4: */
