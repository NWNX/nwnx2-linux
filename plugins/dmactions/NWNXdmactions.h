/***************************************************************************
    NWNXkz.h - Interface for the CNWNXkz class.

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

#ifndef NWNXkz_h_
#define NWNXkz_h_

#include "NWNXBase.h"
#include "NWNXLib.h"
#include "typedefs.h"

#define DM_ACTION_ALL                    0
#define DM_ACTION_MESSAGE_TYPE           1
#define DM_ACTION_GIVE_XP                2
#define DM_ACTION_GIVE_LEVEL             3
#define DM_ACTION_GIVE_GOLD              4
#define DM_ACTION_CREATE_ITEM_ON_OBJECT  5
#define DM_ACTION_CREATE_ITEM_ON_AREA    6
#define DM_ACTION_HEAL_CREATURE          7
#define DM_ACTION_REST_CREATURE          8
#define DM_ACTION_RUNSCRIPT              9
#define DM_ACTION_CREATE_PLACEABLE       10
#define DM_ACTION_SPAWN_CREATURE         11
#define DM_ACTION_TOGGLE_INVULNERABILITY 12
#define DM_ACTION_TOGGLE_IMMORTALITY     13
#define NUM_ACTIONS                      14

class CNWNXdmactions : public CNWNXBase
{
public:
    CNWNXdmactions();
    virtual ~CNWNXdmactions();

    bool OnCreate(gline *nwnxConfig, const char *LogDir = NULL);
    char* OnRequest(char* gameObject, char* Request, char* Parameters);
    unsigned long OnRequestObject(char *gameObject, char* Request);

    char *ActionsScripts[NUM_ACTIONS];

    int FireAction(nwn_objid_t pDM, int nAction);

    bool InScript;
    int bPrevent;

    int nActionID;
    dword oTarget1;
    dword oTarget2;
    int nParam1;
    int nParam2;
    Vector vPos;
    char sParam1[32];

    uint nCount;
    uint nCurrent;
    //bool OnRelease ();


//protected:

private:
    char* pGameObject;
};

extern void nwn_ExecuteScript(const char *scr, nwn_objid_t oid);

#endif
