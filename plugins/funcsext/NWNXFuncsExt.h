/***************************************************************************
    NWNXFuncsExt.h - Interface for the CNWNXFuncsExt class.

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

#ifndef NWNXFuncsExt_h_
#define NWNXFuncsExt_h_

#include "NWNXBase.h"
#include "NWNXLib.h"
#include "typedefs.h"

class CNWNXFuncsExt : public CNWNXBase
{
public:
    CNWNXFuncsExt();
    virtual ~CNWNXFuncsExt();

    bool OnCreate(gline *nwnxConfig, const char *LogDir = NULL);
    char* OnRequest(char* gameObject, char* Request, char* Parameters);
    unsigned long OnRequestObject(char *gameObject, char* Request);
    bool bHooked;

    //bool OnRelease ();

protected:
    void SetScript(CGameObject *ob, char* value);
    void GetScript(CGameObject *ob, char* value);
    void Set_IsGenericTrigger(CGameObject *ob, char* value);
    void Set_IsAreaTransition(CGameObject *ob, char* value);
    void Get_SurfaceMaterial(CGameObject *ob, char* value);
    void Get_Animation(CGameObject *ob, char* value);
    void Start_GuiTimingBar(CGameObject *ob, char* value);
    void Stop_GuiTimingBar(CGameObject *ob, char* value);
    void Possess_Creature(CGameObject *ob, char* value);
    void Unpossess_Creature(CGameObject *ob, char* value);
    void Remove_Gold(CGameObject *ob, char* value);
    void Remove_Item(CGameObject *ob, char* value);
    void ApplyArea_VFX(CGameObject *ob, char* value);
    void Get_FlatFooted(CGameObject *ob, char* value);


private:
    char* pGameObject;
};

#endif
