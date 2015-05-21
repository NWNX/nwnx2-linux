
/***************************************************************************
    NWNXSystem.h - Interface for the CNWNXSystem class.
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

#ifndef NWNX_SYSTEM_H
#define NWNX_SYSTEM_H


#include "NWNXLib.h"


#ifdef __cplusplus
extern "C" {
#endif
void Func_DirList(CGameObject *ob, char *value);
void Func_FileCopy(CGameObject *ob, char *value);
void Func_FileDelete(CGameObject *ob, char *value);
void Func_FileLink(CGameObject *ob, char *value);
void Func_FileReadAll(CGameObject *ob, char *value);
void Func_FileRename(CGameObject *ob, char *value);
void Func_FileSymlink(CGameObject *ob, char *value);
void Func_GetProcessCPUUsage(CGameObject *ob, char *value);
void Func_GetProcessMemoryUsage(CGameObject *ob, char *value);
void Func_GetSystemTime(CGameObject *ob, char *value);
void Func_GetTMILimit(CGameObject *ob, char *value);
void Func_SetTMILimit(CGameObject *ob, char *value);
void Func_ShutdownServer(CGameObject *ob, char *value);
void Func_TrueRandom(CGameObject *ob, char *value);

nwn_objid_t Func_IntToObject(CGameObject *ob);

#ifdef __cplusplus
}

#include "NWNXBase.h"

class CNWNXSystem: public CNWNXBase
{
public:
    CNWNXSystem();
    virtual ~ CNWNXSystem();

    bool OnCreate(gline *nwnxConfig, const char *LogDir = NULL);
    char *OnRequest(char *gameObject, char *Request, char *Parameters);
    unsigned long OnRequestObject(char *gameObject, char *Request);

    // bool OnRelease  ();
};
#endif

#endif /* NWNX_SYSTEM_H */

/* vim: set sw=4: */
