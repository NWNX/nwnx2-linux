
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

static volatile CNWSCreatureStats *Hook_Save_Creature;
static volatile int8_t Hook_Save_Value;


__attribute__((noinline))
static int8_t Hook_GetSavingThrowAdjustment(CNWSCreatureStats *stats, int save, int8_t current)
{
    int value = current;
    int16_t *table = NULL;

    if (stats == NULL)
        return value;

    if (stats->cs_cha_mod > 0) {
        if (Table_DefenseOptions[NWNX_DEFENSES_OPT_PALADIN_SAVES_MIN_ALIGN_GE] > 0 &&
                stats->cs_al_goodevil < Table_DefenseOptions[NWNX_DEFENSES_OPT_PALADIN_SAVES_MIN_ALIGN_GE]) {

            if (CNWSCreatureStats__HasFeat(stats, FEAT_DIVINE_GRACE))
                value -= stats->cs_cha_mod;

        } else if (Table_DefenseOptions[NWNX_DEFENSES_OPT_PALADIN_SAVES_MIN_ALIGN_LC] > 0 &&
                   stats->cs_al_lawchaos < Table_DefenseOptions[NWNX_DEFENSES_OPT_PALADIN_SAVES_MIN_ALIGN_LC]) {

            if (CNWSCreatureStats__HasFeat(stats, FEAT_DIVINE_GRACE))
                value -= stats->cs_cha_mod;
        }

        if (Table_DefenseOptions[NWNX_DEFENSES_OPT_BLACKGUARD_SAVES_MAX_ALIGN_GE] > 0 &&
                stats->cs_al_goodevil > Table_DefenseOptions[NWNX_DEFENSES_OPT_BLACKGUARD_SAVES_MAX_ALIGN_GE]) {

            if (CNWSCreatureStats__HasFeat(stats, FEAT_PRESTIGE_DARK_BLESSING))
                value -= stats->cs_cha_mod;

        } else if (Table_DefenseOptions[NWNX_DEFENSES_OPT_BLACKGUARD_SAVES_MAX_ALIGN_LC] > 0 &&
                   stats->cs_al_lawchaos > Table_DefenseOptions[NWNX_DEFENSES_OPT_BLACKGUARD_SAVES_MAX_ALIGN_LC]) {

            if (CNWSCreatureStats__HasFeat(stats, FEAT_PRESTIGE_DARK_BLESSING))
                value -= stats->cs_cha_mod;
        }
    }

    switch (save) {
        case SAVING_THROW_FORT:   table = Table_DefenseSaveFort;   break;
        case SAVING_THROW_REFLEX: table = Table_DefenseSaveReflex; break;
        case SAVING_THROW_WILL:   table = Table_DefenseSaveWill;   break;
    }

    if (table != NULL) {
        int i;

        for (i = 0; i < NWNX_DEFENSES_SAVEFEATS_TABLE_SIZE * 2; i += 2) {
            if (table[i] != 0 && CNWSCreatureStats__HasFeat(stats, table[i]))
                value += table[i + 1];
        }
    }

    if (value < -100)
        value = -100;
    else if (value > 100)
        value = 100;

    return value;
}


void Hook_GetFortitudeSavingThrow(void)
{
    asm("leave");

    /* duplicate the work originally done */
    asm("addl %edi, %eax");
    asm("addl %esi, %eax");

    asm("movl %ebx, Hook_Save_Creature");
    asm("movb %al, Hook_Save_Value");

    Hook_GetSavingThrowAdjustment(
        (CNWSCreatureStats *)Hook_Save_Creature,
        SAVING_THROW_FORT, Hook_Save_Value);

    /* the result of Hook_GetSavingThrowAdjustment() is in %eax */

    asm("lea 0xfffffff4(%ebp), %esp");
    asm("pop %ebx");
    asm("pop %esi");
    asm("pop %edi");
    asm("pop %ebp");
    asm("ret");
}

void Hook_GetReflexSavingThrow(void)
{
    asm("leave");

    /* duplicate the work originally done */
    asm("addl %edi, %eax");

    asm("movl %esi, Hook_Save_Creature");
    asm("movl %eax, Hook_Save_Value");

    Hook_GetSavingThrowAdjustment(
        (CNWSCreatureStats *)Hook_Save_Creature,
        SAVING_THROW_REFLEX, Hook_Save_Value);

    /* the result of Hook_GetSavingThrowAdjustment() is in %eax */

    asm("lea 0xfffffff4(%ebp), %esp");
    asm("pop %ebx");
    asm("pop %esi");
    asm("pop %edi");
    asm("pop %ebp");
    asm("ret");
}

void Hook_GetWillSavingThrow(void)
{
    asm("leave");

    /* duplicate the work originally done */
    asm("addl %edi, %eax");
    asm("addl %esi, %eax");

    asm("movl %ebx, Hook_Save_Creature");
    asm("movl %eax, Hook_Save_Value");

    Hook_GetSavingThrowAdjustment(
        (CNWSCreatureStats *)Hook_Save_Creature,
        SAVING_THROW_WILL, Hook_Save_Value);

    /* the result of Hook_GetSavingThrowAdjustment() is in %eax */

    asm("lea 0xfffffff4(%ebp), %esp");
    asm("pop %ebx");
    asm("pop %esi");
    asm("pop %edi");
    asm("pop %ebp");
    asm("ret");
}


/* vim: set sw=4: */
