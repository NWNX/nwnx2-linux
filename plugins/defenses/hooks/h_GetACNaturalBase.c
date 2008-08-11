
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


int ExaltReplace_GetOtherACBonus (CNWSCreatureStats *stats, int touch) {
    int i, bonus = 0;

    if (stats == NULL)
        return 0;

    bonus = ExaltReplace_GetWisdomACBonus(stats);


    /* cap shield AC for large/tower shields */
    if (stats->cs_ac_shield_base > 1 && stats->cs_ac_armour_base < 6) {
        int dex = CNWSCreatureStats__GetDEXMod(stats, 1);

        if (stats->cs_ac_shield_base == 3) {
            if (dex > (11 - stats->cs_ac_armour_base))
                bonus -= dex - (11 - stats->cs_ac_armour_base);
        } else if (stats->cs_ac_shield_base == 2) {
            if (dex > (18 - stats->cs_ac_armour_base))
                bonus -= dex - (18 - stats->cs_ac_armour_base);
        }
    }


    if (touch) {
        if (stats->cs_age & 0x80000000)
            bonus += NWNX_EXALT_GET_TOUCHAC(stats->cs_age);

        return bonus;
    }


    /* Insurmountable Protection feats */
    for (i = 3105; i <= 3109; i++) {
        if (CNWSCreatureStats__HasFeat(stats, i))
            bonus += 2;
    }


    bonus += CNWSCreatureStats__GetSkillRank(stats, SKILL_CRAFT_ARMOR, NULL, 0) / 40;

    if (CNWSCreatureStats__HasFeat(stats, FEAT_EPIC_ARMOR_SKIN))
        bonus += 2;

    if (CNWSCreatureStats__HasFeat(stats, FEAT_DRAGON_ARMOR))
        bonus += nwn_GetLevelByClass(stats, CLASS_TYPE_DRAGONDISCIPLE) / 3;

    if (CNWSCreatureStats__HasFeat(stats, FEAT_BONE_SKIN_2)) {
        int pm = nwn_GetLevelByClass(stats, CLASS_TYPE_PALEMASTER) / 4;

        bonus += 2;

        if (stats->cs_str >= 25 || stats->cs_dex >= 25)
            bonus += pm;
        else
            bonus += pm * 2;
    }


    return (bonus + stats->cs_ac_natural_base);
}


int ExaltReplace_GetWisdomACBonus (CNWSCreatureStats *stats) {
    int ranger, bonus = 0;

    if (CNWSCreatureStats__HasFeat(stats, FEAT_MONK_AC_BONUS)) {
        if (stats->cs_ac_armour_base == 0 && stats->cs_ac_shield_base == 0) {
            int monk = nwn_GetLevelByClass(stats, CLASS_TYPE_MONK);

            bonus += (stats->cs_wis_mod > 0 ? stats->cs_wis_mod : 0) + (monk / 5);

        } else if (nwn_GetLevelByClass(stats, CLASS_TYPE_DRUID) > 30 &&
                   stats->cs_ac_armour_base <= 3                     &&
                   stats->cs_ac_shield_base <= 2) {

            if (stats->cs_wis_mod > 3)
                bonus += (stats->cs_wis_mod * 2) / 3;
        }
    } else if (stats->cs_ac_armour_base >= 1 &&
               stats->cs_ac_armour_base <= 3 &&
               stats->cs_ac_shield_base == 0 &&
               (ranger = nwn_GetLevelByClass(stats, CLASS_TYPE_RANGER)) > 1) {

        if (stats->cs_original != NULL && stats->cs_original->cre_equipment != NULL) {
            CNWSItem *weapon = CNWSInventory__GetItemInSlot(stats->cs_original->cre_equipment,
                EQUIPMENT_SLOT_RIGHTHAND);

            switch (weapon != NULL ? weapon->it_baseitem : -1) {
                case BASE_ITEM_DIREMACE:
                case BASE_ITEM_DOUBLEAXE:
                case BASE_ITEM_DWARVENWARAXE:
                case BASE_ITEM_GREATAXE:
                case BASE_ITEM_GREATSWORD:
                case BASE_ITEM_HALBERD:
                case BASE_ITEM_HEAVYFLAIL:
                case BASE_ITEM_KAMA:
                case BASE_ITEM_QUARTERSTAFF:
                case BASE_ITEM_SCYTHE:
                case BASE_ITEM_TWOBLADEDSWORD:

                case BASE_ITEM_CEP_DOUBLEPICK:
                case BASE_ITEM_CEP_DOUBLESCIMITAR:
                case BASE_ITEM_CEP_FALCHION:
                case BASE_ITEM_CEP_GOAD:
                case BASE_ITEM_CEP_HEAVYPICK:
                case BASE_ITEM_CEP_MAUL:
                case BASE_ITEM_CEP_MERCURIALGREATSWORD:
                case BASE_ITEM_CEP_MERCURIALLONGSWORD:
                case BASE_ITEM_CEP_NUNCHAKU:
                    ranger = 0;
                    break;

                default: break;
            }
        }

        if (stats->cs_wis_mod <= 20) {
            int wisac = stats->cs_wis_mod * 2, limit = ranger / 2;

            if (wisac > limit)
                bonus += limit;
            else if (wisac > 0)
                bonus += wisac;
        } else if (ranger > 20)
            bonus += (stats->cs_wis_mod > ranger ? ranger : stats->cs_wis_mod);

    } else if (nwn_GetLevelByClass(stats, CLASS_TYPE_SHIFTER) > 20 &&
               stats->cs_ac_armour_base == 0                       &&
               stats->cs_ac_shield_base == 0) {

        if (stats->cs_wis_mod > 3)
            bonus += stats->cs_wis_mod - 3;
    }

    return bonus;
}


/* vim: set sw=4: */
