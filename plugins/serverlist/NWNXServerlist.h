
/***************************************************************************
    NWNXServerlist.h - Interface for the CNWNXServerlist class.
    Copyright (C) 2013 virusman

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

#ifndef NWNXSERVERLIST_h_
#define NWNXSERVERLIST_h_

#define MASTER_SERVER_HOSTNAME "nwn1.mst.valhallalegends.com"
#define MASTER_SERVER_PORT     5121

#include "NWNXBase.h"

class CNWNXServerlist: public CNWNXBase
{
public:
    CNWNXServerlist();
    virtual ~ CNWNXServerlist();

    bool OnCreate(gline * nwnxConfig, const char *LogDir = NULL);
    char *OnRequest(char *gameObject, char *Request, char *Parameters);

    // bool OnRelease ();

protected:

private:
};

#endif
