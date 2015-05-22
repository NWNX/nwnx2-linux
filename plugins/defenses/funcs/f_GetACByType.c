
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


void Func_GetACByType(CGameObject *ob, char *value)
{
    int ac = 0;
    const CNWSCreature *cre;

    if (ob == NULL || (cre = ob->vtable->AsNWSCreature(ob)) == NULL || cre->cre_stats == NULL) {
        snprintf(value, strlen(value), "0");
        return;
    }

    switch (atoi(value)) {
        case AC_ARMOUR_ENCHANTMENT_BONUS:
            ac = (cre->cre_stats->cs_ac_armour_bonus - cre->cre_stats->cs_ac_armour_penalty);
            break;

        case AC_SHIELD_ENCHANTMENT_BONUS:
            ac = (cre->cre_stats->cs_ac_shield_bonus - cre->cre_stats->cs_ac_shield_penalty);
            break;

        case AC_DODGE_BONUS:
            ac = (cre->cre_stats->cs_ac_dodge_bonus - cre->cre_stats->cs_ac_dodge_penalty);
            break;

        case AC_NATURAL_BONUS:
            ac = (cre->cre_stats->cs_ac_natural_bonus - cre->cre_stats->cs_ac_natural_penalty);
            break;

        case AC_DEFLECTION_BONUS:
            ac = (cre->cre_stats->cs_ac_deflection_bonus - cre->cre_stats->cs_ac_deflection_penalty);
            break;

        case AC_NATURAL_BASE:        ac = cre->cre_stats->cs_ac_natural_base;                     break;
        case AC_ARMOUR_BASE:         ac = cre->cre_stats->cs_ac_armour_base;                      break;
        case AC_SHIELD_BASE:         ac = cre->cre_stats->cs_ac_shield_base;                      break;
        case AC_TOUCH_BASE:          ac = Local_GetACTouchBase(cre->cre_stats);                   break;
        case AC_OTHER_BONUS:         ac = CNWSCreatureStats__GetACNaturalBase(cre->cre_stats, 0); break;
        case AC_CLASS_BONUS:         ac = Hook_GetACClassAdjustment(cre->cre_stats, 0);           break;
        case AC_FEAT_BONUS:          ac = Hook_GetACFeatAdjustment(cre->cre_stats, 0);            break;
        case AC_SKILL_BONUS:         ac = Local_GetACSkillAdjustment(cre->cre_stats, 0, 0);       break;
        case AC_EQUIP_BONUS:         ac = Local_GetACEquipAdjustment(cre->cre_stats, 0, 0);       break;
        case AC_STRENGTH_BONUS:      ac = Local_GetACStrAdjustment(cre->cre_stats, 0, 0);         break;
        case AC_DEXTERITY_BONUS:     ac = Local_GetACDexAdjustment(cre->cre_stats, 0, 0);         break;
        case AC_CONSTITUTION_BONUS:  ac = Local_GetACConAdjustment(cre->cre_stats, 0, 0);         break;
        case AC_INTELLIGENCE_BONUS:  ac = Local_GetACIntAdjustment(cre->cre_stats, 0, 0);         break;
        case AC_WISDOM_BONUS:        ac = Hook_GetACWisAdjustment(cre->cre_stats, 0);             break;
        case AC_CHARISMA_BONUS:      ac = Local_GetACChaAdjustment(cre->cre_stats, 0, 0);         break;
    }

    snprintf(value, strlen(value), "%d", ac);
}


/* vim: set sw=4: */
