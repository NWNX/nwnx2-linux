
/***************************************************************************
    ExaltReplace.c - Implementation of NWN combat replacement functions
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


volatile uintptr_t Hook_DR_Return;

volatile int *Hook_DR_DamResist;
volatile int Hook_DR_DamAmount;
volatile int Hook_DR_DamType;
volatile int Hook_DR_Filter;
volatile CNWSCreature *Hook_DR_Attacker;
volatile CNWSCreature *Hook_DR_Target;


__attribute__((noinline))
int Hook_AdjustDamageResistance(int filter, CNWSCreature *attacker, CNWSCreature *target, int damtype, int damamount, int *damres)
{
#ifdef NWNX_DEFENSES_HG
    if (target != NULL && target->obj.obj_type == OBJECT_TYPE_CREATURE) {
        int i, adj = 0;
        const CGameEffect *eff;

        for (i = 0; i < target->obj.obj_effects_len; i++) {
            if ((eff = target->obj.obj_effects[i]) == NULL)
                continue;

            if (eff->eff_type == EFFECT_TRUETYPE_SPELL_IMMUNITY) {
                if (eff->eff_integers[0] == 765) {
                    if (eff->eff_integers[1] & damtype)
                        adj -= eff->eff_integers[2];
                } else if (eff->eff_integers[0] == 766) {
                    if (eff->eff_integers[1] & damtype)
                        adj += eff->eff_integers[2];
                }
            }
        }

        if (adj != 0) {
            if (adj < 0) {
                if (-adj >= *damres)
                    *damres  = 1;
                else
                    *damres += adj;
            } else if (*damres < damamount) {
                *damres += adj;
                if (*damres > damamount)
                    *damres = damamount - 1;
            }
        }
    }
#endif


    if (filter)
        return 1;

#ifdef NWNX_DEFENSES_HG
#define NWNX_EXALT_GET_FILTER(P)        (P & 0xFF)
#define EXALT_FILTER_IMMUNITY           0x01

    if (attacker != NULL                               &&
            attacker->obj.obj_type == OBJECT_TYPE_CREATURE &&
            attacker->cre_is_pc                            &&
            (attacker->cre_bodybag_id & 0x80000000)        &&
            (NWNX_EXALT_GET_FILTER(attacker->cre_bodybag_id) & EXALT_FILTER_IMMUNITY))
        return 0;

    if (target != NULL                               &&
            target->obj.obj_type == OBJECT_TYPE_CREATURE &&
            target->cre_is_pc                            &&
            (target->cre_bodybag_id & 0x80000000)        &&
            (NWNX_EXALT_GET_FILTER(target->cre_bodybag_id) & EXALT_FILTER_IMMUNITY))
        return 0;
#endif

    return 1;
}

void Hook_DamageResistanceMessage(void)
{
    asm("leave");

    /* read the attacker, target, and normal filter */
    asm("movl 0x18(%ebp), %eax");
    asm("movl %eax, Hook_DR_Filter");

    asm("movl 0xc(%ebp), %eax");
    asm("movl %eax, Hook_DR_Attacker");

    asm("movl 0x8(%ebp), %eax");
    asm("movl %eax, Hook_DR_Target");

    asm("movl 0x14(%ebp), %eax");
    asm("movl %eax, Hook_DR_DamType");

    asm("movl 0x10(%ebp), %eax");
    asm("movl %eax, Hook_DR_DamAmount");

    asm("lea 0xffffffb8(%ebp), %eax");
    asm("movl %eax, Hook_DR_DamResist");

    Hook_DR_Filter = Hook_AdjustDamageResistance(
                         (int)Hook_DR_Filter,
                         (CNWSCreature *)Hook_DR_Attacker,
                         (CNWSCreature *)Hook_DR_Target,
                         (int)Hook_DR_DamType,
                         (int)Hook_DR_DamAmount,
                         (int *)Hook_DR_DamResist);

    /* the result of Hook_AdjustDamageResistance is in %eax */
    asm("test %eax, %eax");

    /* return to the normal message processing */
    asm("push Hook_DR_Return");
    asm("ret");
}


/* vim: set sw=4: */
