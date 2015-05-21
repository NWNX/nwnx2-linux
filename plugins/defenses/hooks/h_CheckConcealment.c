
/***************************************************************************
    NWNXFuncs.cpp - Implementation of the CNWNXFuncs class.
    Copyright (C) 2007 Doug Swarin (zac@intertex.net)

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 ***************************************************************************/

#include "NWNXDefenses.h"

volatile uintptr_t Hook_CCONC_ReturnHit;
volatile uintptr_t Hook_CCONC_ReturnMiss;
static volatile CNWSCreature *Hook_CCONC_Attacker;
static volatile CNWSCreature *Hook_CCONC_Target;
static volatile int Hook_CCONC_Concealment;
static volatile int Hook_CCONC_MissChance;


__attribute__((noinline))
static int Hook_GetConcealmentCheckResult(CNWSCreature *attacker, CNWSCreature *target, int concealment, int misschance)
{
    int ret;

    if ((ret = Local_GetConcealmentCheckResult(attacker, target, concealment, misschance)) >= 0)
        return ret;

    if (misschance > 0) {
        if (random() % 100 < misschance) {
            if (attacker != NULL                               &&
                    attacker->obj.obj_type == OBJECT_TYPE_CREATURE &&
                    attacker->cre_stats != NULL                    &&
                    CNWSCreatureStats__HasFeat(attacker->cre_stats, FEAT_BLIND_FIGHT)) {

                if (random() % 100 < misschance)
                    return misschance;
            } else
                return misschance;
        }
    }

    if (concealment > 0) {
        if (random() % 100 < concealment) {
            if (attacker != NULL                               &&
                    attacker->obj.obj_type == OBJECT_TYPE_CREATURE &&
                    attacker->cre_stats != NULL                    &&
                    CNWSCreatureStats__HasFeat(attacker->cre_stats, FEAT_BLIND_FIGHT)) {

                if (random() % 100 < concealment)
                    return concealment;
            } else
                return concealment;
        }
    }

    return 0;
}


void Hook_CheckConcealment(void)
{
    asm("leave");

    /* copy attacker, concealment, and miss chance out */
    asm("pushl 0x8(%ebp)");
    asm("popl Hook_CCONC_Attacker");

    asm("pushl 0xffffffac(%ebp)");
    asm("popl Hook_CCONC_Target");

    asm("pushl 0xffffffbc(%ebp)");
    asm("popl Hook_CCONC_Concealment");

    asm("pushl 0xffffffc0(%ebp)");
    asm("popl Hook_CCONC_MissChance");

    Hook_CCONC_Concealment = Hook_GetConcealmentCheckResult(
                                 (CNWSCreature *)Hook_CCONC_Attacker,
                                 (CNWSCreature *)Hook_CCONC_Target,
                                 Hook_CCONC_Concealment, Hook_CCONC_MissChance);

    if (Hook_CCONC_Concealment) {
        asm("pushl Hook_CCONC_Concealment");
        asm("popl 0xffffffbc(%ebp)");

        asm("pushl Hook_CCONC_ReturnMiss");
    } else
        asm("pushl Hook_CCONC_ReturnHit");

    asm("ret");
}


/* vim: set sw=4: */
