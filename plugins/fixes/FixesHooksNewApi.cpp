#include "FixesHooksNewApi.h"
#include "NWNXApi.h"
#include "NWNXFixes.h"

extern CNWNXFixes fixes;

int Hook_CNWSMessage__SendServerToPlayerPlayModuleCharacterListResponse(CNWSMessage* oMessageManager, int nPlayerId, int nObjectId, int bSendInfo)
{
    if (fixes.bHideCharList) //Global GTFO
        bSendInfo = 0;

    oMessageManager->CreateWriteMessage(4, nPlayerId, 1);

    CNWSCreature* oCreature = (CNWSCreature*)(g_pAppManager->ServerExoApp->GetCreatureByGameObjectID(nObjectId));
    if (oCreature == NULL || oCreature->ObjectType != 5)
        bSendInfo = 0;
    else if (fixes.bHideDMs) {
        int nAssociateType = oCreature->GetAssociateType();
        //hide if
        //-- possessed
        //-- possessed full powers
        //-- DM
        if (nAssociateType == 7 || nAssociateType == 8 || (oCreature->CreatureStats != NULL && oCreature->CreatureStats->IsDM))
            bSendInfo = 0;
    }

    oMessageManager->WriteBOOL(bSendInfo);
    oMessageManager->WriteDWORD(nObjectId, 32);

    if (bSendInfo) {
        unsigned char nGender = oCreature->GetGender();
        CExoLocString* sFirstName = new CExoLocString((const CExoLocString&)(oCreature->GetFirstName()));
        CExoLocString* sLastName = new CExoLocString((const CExoLocString&)(oCreature->GetLastName()));
        oMessageManager->WriteCExoLocStringServer(*sFirstName, nGender);
        oMessageManager->WriteCExoLocStringServer(*sLastName, nGender);
        delete sFirstName;
        delete sLastName;

        //92 is "po_hu_f_99_"
        //129 is "po_hu_m_99_"
        unsigned short nPortraitId = fixes.bHidePortraits ? (nGender == 1 ? 92 : 129)/*(const unsigned short)0xFFFF*/ : (unsigned short)(oCreature->GetPortraitId());

        oMessageManager->WriteWORD(nPortraitId, 16);
        if (nPortraitId == 0xFFFE || nPortraitId == 0xFFFF) {
            //CResRef sResRef = fixes.HidePortraits ? (CResRef)/*(nGender == 1 ? "po_hu_f_99_" : */"po_hu_m_99_"/*)*/ : oCreature->GetPortrait();
            oMessageManager->WriteCResRef(oCreature->GetPortrait()/*sResRef*/, 16);
        }

        CNWSCreatureStats* oStats = oCreature->CreatureStats;
        int nClassCount = fixes.bHideClasses || oStats == NULL ? (const unsigned char)0 : *(unsigned char*)((int)oStats + 0xA1);
        oMessageManager->WriteBYTE(nClassCount, 8);

        int i;
        for (i = 0; i < nClassCount; i++) {
            oMessageManager->WriteBYTE(oStats->GetClass(i), 8);
            oMessageManager->WriteBYTE(oStats->GetClassLevel(i, false), 8);
        }

    }

    unsigned char* sMessage;
    unsigned long nLength;
    if (!oMessageManager->GetWriteMessage(&sMessage, &nLength))
        return 0;

    return oMessageManager->SendServerToPlayerMessage(nPlayerId, 49, 3, sMessage, nLength);
}

void HookFunctions_NewApi()
{
    nx_hook_function((void*)0x0807E44C, (void*)Hook_CNWSMessage__SendServerToPlayerPlayModuleCharacterListResponse, 5, NX_HOOK_DIRECT);
    fixes.Log(2, "CNWSMessage__SendServerToPlayerPlayModuleCharacterListResponse: %08lX\n", 0x0807E44C);
}
