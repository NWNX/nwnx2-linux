
/***************************************************************************
    NWNXTweaks.h - Interface for the CNWNXTweaks class.
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

#ifndef NWNX_TWEAKS_H
#define NWNX_TWEAKS_H

#include "NWNXLib.h"


#define NWNX_TWEAKS_OPTIONS_TABLE_SIZE                   64


#ifdef __cplusplus
extern "C" {
#endif

void Func_GetTweakOption(CGameObject *ob, char *value);
void Func_SetTweakOption(CGameObject *ob, char *value);

nwn_objid_t Func_IntToObject(CGameObject *ob);

void Hook_FixSendFeedbackMessage(void);

extern uint16_t Table_TweakOptions[NWNX_TWEAKS_OPTIONS_TABLE_SIZE];

#ifdef __cplusplus
}

#include "NWNXBase.h"

class CNWNXTweaks: public CNWNXBase
{
public:
    CNWNXTweaks();
    virtual ~ CNWNXTweaks();

    bool OnCreate(gline *nwnxConfig, const char *LogDir = NULL);
    char *OnRequest(char *gameObject, char *Request, char *Parameters);
    unsigned long OnRequestObject(char *gameObject, char *Request);

    // bool OnRelease  ();
};
#endif

#endif /* NWNX_TWEAKS_H */

/* vim: set sw=4: */
