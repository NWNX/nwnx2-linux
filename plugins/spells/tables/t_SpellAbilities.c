
/***************************************************************************
    CombatTables.h - NWN Combat Tables
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

int8_t Table_SpellAbilities[NWNX_SPELLS_CLASS_TABLE_SIZE] = {
    [CLASS_TYPE_BARD]                   = ABILITY_CHARISMA + 1,
    [CLASS_TYPE_CLERIC]                 = ABILITY_WISDOM + 1,
    [CLASS_TYPE_DRUID]                  = ABILITY_WISDOM + 1,
    [CLASS_TYPE_PALADIN]                = ABILITY_WISDOM + 1,
    [CLASS_TYPE_RANGER]                 = ABILITY_WISDOM + 1,
    [CLASS_TYPE_SORCERER]               = ABILITY_CHARISMA + 1,
    [CLASS_TYPE_WIZARD]                 = ABILITY_INTELLIGENCE + 1,

    [CLASS_TYPE_ABERRATION]             = -1,
    [CLASS_TYPE_ANIMAL]                 = -1,
    [CLASS_TYPE_BEAST]                  = -1,
    [CLASS_TYPE_COMMONER]               = -1,
    [CLASS_TYPE_CONSTRUCT]              = -1,
    [CLASS_TYPE_DRAGON]                 = -1,
    [CLASS_TYPE_ELEMENTAL]              = -1,
    [CLASS_TYPE_FEY]                    = -1,
    [CLASS_TYPE_GIANT]                  = -1,
    [CLASS_TYPE_HUMANOID]               = -1,
    [CLASS_TYPE_MAGICAL_BEAST]          = -1,
    [CLASS_TYPE_MONSTROUS]              = -1,
    [CLASS_TYPE_OOZE]                   = -1,
    [CLASS_TYPE_OUTSIDER]               = -1,
    [CLASS_TYPE_SHAPECHANGER]           = -1,
    [CLASS_TYPE_UNDEAD]                 = -1,
    [CLASS_TYPE_VERMIN]                 = -1,

#ifdef NWNX_SPELLS_HG
    [CLASS_TYPE_ASSASSIN]               = ABILITY_INTELLIGENCE + 1,
    [CLASS_TYPE_BLACKGUARD]             = ABILITY_WISDOM + 1,
#endif
};

/* vim: set sw=4: */
