
/***************************************************************************
    Replace.c - Implementation of NWN combat replacement functions
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

#include "NWNXSpells.h"


volatile uintptr_t Hook_SPR_Return;

static volatile float Hook_SPR_Value;

static volatile CNWSCreature *Hook_SPR_Caster;
static volatile CExoString *Hook_SPR_Range;
static volatile nwn_objid_t Hook_SPR_Target;


__attribute__((noinline))
static float Hook_GetSpellRange (CNWSCreature *caster, CExoString *range, nwn_objid_t target_id) {
    float ret;
    CGameObject *ob;
    CNWSCreature *target;

    if (range == NULL || range->text == NULL)
        return 0.0;

    switch (*(range->text)) {
        case 'T': ret = 2.25; break;
        case 'S': ret = 8.00; break;
        case 'M': ret = 20.0; break;
        case 'L': ret = 40.0; break;
        default:  ret = 0.0; break;
    }

    /* increase spell range when someone is hit by Targeting Ray */
    if (target_id != OBJECT_INVALID                      &&
        (ob = nwn_GetObjectByID(target_id)) != NULL      &&
        (target = ob->vtable->AsNWSCreature(ob)) != NULL &&
        target->cre_stats != NULL) {

#if 0
        if (ret >= 5.0 && 
            CNWSCreatureStats__HasFeat(target->cre_stats, HGFEAT_Z_TARGETING_RAY))
            ret *= 1.5;
#endif
    }

    return ret;
}


void Hook_ComputeSpellRange (void) {
    asm("leave");

    /* extract the caster, range descriptor, and target */
    asm("mov 0x8(%ebp), %eax");
    asm("mov %eax, Hook_SPR_Caster");
    asm("mov %ebx, Hook_SPR_Range");
    asm("mov 0x10(%ebp), %eax");
    asm("mov %eax, Hook_SPR_Target");

    Hook_SPR_Value = Hook_GetSpellRange(
        (CNWSCreature *)Hook_SPR_Caster,
        (CExoString *)Hook_SPR_Range,
        (nwn_objid_t)Hook_SPR_Target);

    /* the result of Hook_GetSpellRange() is in Hook_SPR_Value */
    asm("flds Hook_SPR_Value");

    asm("push Hook_SPR_Return");
    asm("ret");
}


/* vim: set sw=4: */
