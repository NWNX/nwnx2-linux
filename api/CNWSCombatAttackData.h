#ifndef _CNWSCOMBATATTACKDATA_H_
#define _CNWSCOMBATATTACKDATA_H_
#include "nwndef.h"
#include "CExoString.h"
#include "CExoArrayList.h"
#include "nwnstructs.h"

class CNWSCombatAttackData
{
public:
    void AddDamage(unsigned short, int);
    void ClearAttackData();
    void Copy(CNWSCombatAttackData *, int);
    int GetDamage(unsigned short);
    int GetTotalDamage(int);
    int LoadData(CResGFF *, CResStruct *);
    int SaveData(CResGFF *, CResStruct *);
    void SetBaseDamage(int);
    int SetDamage(unsigned short, int);
    ~CNWSCombatAttackData();
    CNWSCombatAttackData();

    /* 0x0/0 */ unsigned short AttackGroup;
    /* 0x2/2 */ unsigned short AnimationLength;
    /* 0x4/4 */ unsigned long ReactObject;
    /* 0x8/8 */ unsigned short ReaxnDelay;
    /* 0xA/10 */ unsigned short ReaxnAnimation;
    /* 0xC/12 */ unsigned short ReaxnAnimLength;
    /* 0xE/14 */ char ToHitRoll;
    /* 0xF/15 */ char ThreatRoll;
    /* 0x10/16 */ char ToHitMod;
    /* 0x14/20 */ char rsvd1[3];
    /* 0x14/20 */ char MissedBy;
    /* 0x16/22 */ char rsvd2;
    /* 0x16/22 */ unsigned short Damage[13];
    /* 0x30/48 */ char Weapon;
    /* 0x31/49 */ char AttackMode;
    /* 0x32/50 */ char Concealment;
    /* 0x34/52 */ char rsvd4;
    /* 0x34/52 */ unsigned long RangedAttack;
    /* 0x38/56 */ unsigned long SneakAttack;
    /* 0x3C/60 */ unsigned long m_bDeathAttack;
    /* 0x40/64 */ unsigned long KillingBlow;
    /* 0x44/68 */ unsigned long CoupDeGrace;
    /* 0x48/72 */ unsigned long CriticalThreat;
    /* 0x4C/76 */ unsigned long AttackDeflected;
    /* 0x50/80 */ char AttackResult;
    /* 0x52/82 */ char rsvd5;
    /* 0x52/82 */ unsigned short AttackType;
    /* 0x54/84 */ unsigned short AttackID;
    /* 0x58/88 */ char rsvd6[2];
    /* 0x58/88 */ Vector RangedTargetLocation;
    /* 0x64/100 */ unsigned long AmmoItem;
    /* 0x68/104 */ CExoString AttackDebugText;
    /* 0x70/112 */ CExoString DamageDebugText;
    /* (mtype:CExoArrayList<unsigned long>) */
    /* 0x78/120 */ CExoArrayList<unsigned long> m_alstOnHitGameEffects;
    /* (mtype:CExoArrayList<CNWSSpellScriptData *>) */
    /* 0x84/132 */ CExoArrayList<CNWSSpellScriptData *> m_alstOnHitSpellScripts;
    /* (mtype:CExoArrayList<CNWSSpellScriptData *>) */
    /* 0x90/144 */ CExoArrayList<CNWSSpellScriptData *> m_alstOnHitEnemySpellScripts;
    /* 0x9C/156 */ CExoArrayList<CNWCCMessageData*> m_alstPendingFeedback;
};

static_assert_size(CNWSCombatAttackData, 0xa8);

#endif
