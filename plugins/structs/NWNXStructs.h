
/***************************************************************************
    NWNXStructs.h - Interface for the CNWNXStructs class.
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

#ifndef NWNX_STRUCTS_H
#define NWNX_STRUCTS_H


#include "NWNXLib.h"


#ifdef __cplusplus
extern "C" {
#endif
void Func_GetCasterLevel(CGameObject *ob, char *value);
void Func_GetCreatorRequest(CGameObject *ob, char *value);
void Func_GetDuration(CGameObject *ob, char *value);
void Func_GetDurationRemaining(CGameObject *ob, char *value);
void Func_GetHasEffect(CGameObject *ob, char *value);
void Func_GetInteger(CGameObject *ob, char *value);
void Func_GetNumIntegers(CGameObject *ob, char *value);
void Func_GetSpellId(CGameObject *ob, char *value);
void Func_GetTrueType(CGameObject *ob, char *value);
void Func_SetCreator(CGameObject *ob, char *value);
void Func_SetInteger(CGameObject *ob, char *value);
void Func_SetSpellId(CGameObject *ob, char *value);
void Func_SetTrueType(CGameObject *ob, char *value);

nwn_objid_t Func_GetCreator(CGameObject *ob);

void Hook_PushStruct(void);

#ifdef __cplusplus
}

#include "NWNXBase.h"

class CNWNXStructs: public CNWNXBase
{
public:
    CNWNXStructs();
    virtual ~ CNWNXStructs();

    bool OnCreate(gline *nwnxConfig, const char *LogDir = NULL);
    char *OnRequest(char *gameObject, char *Request, char *Parameters);
    unsigned long OnRequestObject(char *gameObject, char *Request);

    // bool OnRelease  ();
};
#endif

#endif /* NWNX_STRUCTS_H */

/* vim: set sw=4: */
