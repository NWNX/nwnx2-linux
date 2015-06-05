#ifndef _CSERVERAIMASTER_H_
#define _CSERVERAIMASTER_H_
#include "nwndef.h"
#include "CServerAIList.h"
#include "CExoLinkedList.h"
#include "CServerAIEventNode.h"
#include "CExoString.h"

class CServerAIMaster
{
public:
    int AddEventAbsoluteTimeViaTail(unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, void *);
    int AddEventAbsoluteTime(unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, void *);
    int AddEventDeltaTime(unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, void *);
    int AddObject(CNWSObject *, int);
    void AdjustTargetAndWitnessReputations(unsigned long, unsigned long, int);
    void ClearEventQueue();
    void DeleteEventData(unsigned long, void *);
    int EventPending(unsigned long, unsigned long);
    int GetPendingEvent(unsigned long *, unsigned long *, unsigned long *, unsigned long *, unsigned long *, void **);
    int LoadEventQueue(CResGFF *, CResStruct *);
    void LoadReputationAdjustments();
    int OnEffectApplied(CNWSObject *, CGameEffect *, int);
    int OnEffectRemoved(CNWSObject *, CGameEffect *);
    int OnItemPropertyApplied(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long, int);
    int OnItemPropertyRemoved(CNWSItem *, CNWItemProperty *, CNWSCreature *, unsigned long);
    int RemoveObject(CNWSObject *);
    int SaveEventQueue(CResGFF *, CResStruct *);
    int SetAILevel(CNWSObject *, int);
    void SetExoAppInternal(CServerExoAppInternal *);
    void UpdateState();
    ~CServerAIMaster();
    CServerAIMaster();

    /* 0x0/0 */ CServerExoAppInternal *m_pExoAppInternal;
    /* 0x4/4 */ CServerAIList m_aGameAIList[5];
    /* (mtype:CExoLinkedList<CServerAIEventNode>) */
    /* 0x54/84 */ CExoLinkedList<CServerAIEventNode> m_lEventQueue;
    /* 0x58/88 */ unsigned long m_pGameEffectApplierRemover;
    /* 0x5C/92 */ unsigned long m_pItemPropertyApplierRemover;
    /* 0x60/96 */ CExoString m_sScriptsRun;
    /* 0x68/104 */ unsigned long field_68;
    /* 0x6C/108 */ unsigned long field_6C;
    /* 0x70/112 */ unsigned long field_70;
    /* 0x74/116 */ unsigned long field_74;
    /* 0x78/120 */ unsigned long field_78;
    /* 0x7C/124 */ unsigned long field_7C;
    /* 0x80/128 */ unsigned long m_pAttackRepAdj;
    /* 0x84/132 */ unsigned long m_pTheftRepAdj;
    /* 0x88/136 */ unsigned long m_pKillRepAdj;
    /* 0x8C/140 */ unsigned long m_pHelpRepAdj;
};
#endif
