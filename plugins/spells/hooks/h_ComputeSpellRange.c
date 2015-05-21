
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
static float Hook_GetSpellRange(CNWSCreature *caster, CExoString *range, nwn_objid_t target_id)
{
    float ret;
    bool no_bonus = false;
#ifdef NWNX_SPELLS_HG
    CGameObject *ob;
    CNWSCreature *target;
#endif // (NWNX_SPELLS_HG)

    if (range == NULL || range->text == NULL)
        return 0.0;

    switch (*(range->text)) {
        case 'T': ret =  2.25; break;
        case 's': no_bonus = true;
        case 'S': ret =  8.00; break;
        case 'm': no_bonus = true;
        case 'M': ret = 20.00; break;
        case 'L': ret = 40.00; break;
        case 'P': ret =  0.00; break;

#ifdef NWNX_SPELLS_HG
        case 'a':
        case 'c':
        case 'd':
        case 'e':
        case 'i':
        case 'n':
        case 't':
        case 'v':
        case 'p': {
            u_int16_t feats[3] = { 0, 0, 0 };

            switch (*(range->text)) {
                case 'a':
                    feats[0] = FEAT_SPELL_FOCUS_ABJURATION;
                    feats[1] = FEAT_GREATER_SPELL_FOCUS_ABJURATION;
                    feats[2] = FEAT_EPIC_SPELL_FOCUS_ABJURATION;
                    break;

                case 'c':
                    feats[0] = FEAT_SPELL_FOCUS_CONJURATION;
                    feats[1] = FEAT_GREATER_SPELL_FOCUS_CONJURATION;
                    feats[2] = FEAT_EPIC_SPELL_FOCUS_CONJURATION;
                    break;

                case 'd':
                    feats[0] = FEAT_SPELL_FOCUS_DIVINATION;
                    feats[1] = FEAT_GREATER_SPELL_FOCUS_DIVINATION;
                    feats[2] = FEAT_EPIC_SPELL_FOCUS_DIVINATION;
                    break;

                case 'e':
                    feats[0] = FEAT_SPELL_FOCUS_ENCHANTMENT;
                    feats[1] = FEAT_GREATER_SPELL_FOCUS_ENCHANTMENT;
                    feats[2] = FEAT_EPIC_SPELL_FOCUS_ENCHANTMENT;
                    break;

                case 'i':
                    feats[0] = FEAT_SPELL_FOCUS_ILLUSION;
                    feats[1] = FEAT_GREATER_SPELL_FOCUS_ILLUSION;
                    feats[2] = FEAT_EPIC_SPELL_FOCUS_ILLUSION;
                    break;

                case 'n':
                    feats[0] = FEAT_SPELL_FOCUS_NECROMANCY;
                    feats[1] = FEAT_GREATER_SPELL_FOCUS_NECROMANCY;
                    feats[2] = FEAT_EPIC_SPELL_FOCUS_NECROMANCY;
                    break;

                case 't':
                    feats[0] = FEAT_SPELL_FOCUS_TRANSMUTATION;
                    feats[1] = FEAT_GREATER_SPELL_FOCUS_TRANSMUTATION;
                    feats[2] = FEAT_EPIC_SPELL_FOCUS_TRANSMUTATION;
                    break;

                case 'v':
                    feats[0] = FEAT_SPELL_FOCUS_EVOCATION;
                    feats[1] = FEAT_GREATER_SPELL_FOCUS_EVOCATION;
                    feats[2] = FEAT_EPIC_SPELL_FOCUS_EVOCATION;
                    break;

                case 'p':
                    feats[0] = FEAT_SPELL_PENETRATION;
                    feats[1] = FEAT_GREATER_SPELL_PENETRATION;
                    feats[2] = FEAT_EPIC_SPELL_PENETRATION;
                    break;

                default: return 0.0;
            }

            if (caster != NULL                               &&
                    caster->obj.obj_type == OBJECT_TYPE_CREATURE &&
                    caster->cre_stats != NULL) {

                if (CNWSCreatureStats__HasFeat(caster->cre_stats, feats[2]))
                    ret = 40.0;
                else if (CNWSCreatureStats__HasFeat(caster->cre_stats, feats[1]))
                    ret = 20.0;
                else if (CNWSCreatureStats__HasFeat(caster->cre_stats, feats[0]))
                    ret = 8.0;
                else
                    ret = 2.25;
            } else
                ret = 2.25;

        }
        break;
#endif

        default:  ret = 0.0; break;
    }

    /* TODO: check if spell is being cast from an item */

#ifdef NWNX_SPELLS_HG
    if (!no_bonus) {
        /* increase spell range with Extraordinary Spell Reach feat */
        if (caster != NULL                               &&
                caster->obj.obj_type == OBJECT_TYPE_CREATURE &&
                caster->cre_is_pc                            &&
                caster->cre_stats != NULL                    &&
                CNWSCreatureStats__HasFeat(caster->cre_stats, 2426)) {  /* HGFEAT_EXTRAORDINARY_SPELL_REACH */

            if (ret >= 5.0 && ret <= 30.0)
                ret *= 1.25;
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
    }
#endif

    return ret;
}


void Hook_ComputeSpellRange(void)
{
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
