
/***************************************************************************
    NWNXSpells.h - Interface for the CNWNXSpells class.
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

#ifndef NWNX_SPELLS_H
#define NWNX_SPELLS_H

#include "NWNXLib.h"


#define NWNX_SPELLS_CLASS_TABLE_SIZE                    256
#define NWNX_SPELLS_SPELL_TABLE_SIZE                   4096
#define NWNX_SPELLS_OPTIONS_TABLE_SIZE                   64


#ifdef __cplusplus
extern "C" {
#endif

void Func_GetSpellOption(CGameObject *ob, char *value);
void Func_SetSpellOption(CGameObject *ob, char *value);

nwn_objid_t Func_IntToObject(CGameObject *ob);

void Hook_ComputeSpellRange(void);
void Hook_GetCasterClassAbility1(void);
void Hook_GetIsMemorizationCasterClass1(void);
void Hook_GetIsMemorizationCasterClass2(void);
void Hook_GetIsMemorizationCasterClass3(void);
void Hook_GetIsMemorizationCasterClass4(void);
void Hook_GetIsUnlimitedBookCasterClass1(void);
void Hook_GetSpellLevel(void);
void Hook_SpellSlotLoop1(void);
void Hook_SpellSlotLoop2(void);
void Hook_SpellSlotLoop3(void);

int Hook_GetSpellMinAbilityMet(CNWSCreatureStats *stats, int clpos, int level);

int Local_GetIsArcaneCasterClass(int cl);
int Local_GetIsMemorizationCasterClass(int cl);
int Local_GetIsSpontaneousCasterClass(int cl);
int Local_GetIsUnlimitedBookCasterClass(int cl);


extern int8_t Table_SpellAbilities[NWNX_SPELLS_CLASS_TABLE_SIZE];
extern uint16_t Table_SpellOptions[NWNX_SPELLS_OPTIONS_TABLE_SIZE];

#ifdef __cplusplus
}

#include "NWNXBase.h"

class CNWNXSpells: public CNWNXBase
{
public:
    CNWNXSpells();
    virtual ~ CNWNXSpells();

    bool OnCreate(gline *nwnxConfig, const char *LogDir = NULL);
    char *OnRequest(char *gameObject, char *Request, char *Parameters);
    unsigned long OnRequestObject(char *gameObject, char *Request);

    // bool OnRelease  ();
};
#endif

#endif /* NWNX_SPELLS_H */

/* vim: set sw=4: */
