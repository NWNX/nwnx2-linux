/***************************************************************************
    NWNX FOR LINUX Vaultster plugin Class interface
    Copyright (C) 2009 John Klar (plasmajohn at avlis dot org)

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; version 2 of the License.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 ***************************************************************************/

#ifndef NWNXVaultster_h_
#define NWNXVaultster_h_

#include <cstdlib>
#include <iostream>
#include <map>
#include <string>

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>

#include "NWNXBase.h"
#include "client.h"
#include "NWNXLib.h"

using namespace::std;
using namespace boost::asio;

class CNWNXVaultster : public CNWNXBase
{
public:
    CNWNXVaultster();
    ~CNWNXVaultster();

    bool OnCreate(gline *nwnxConfig, const char *LogDir = NULL);
    char *OnRequest(char* gameObject, char* Request, char* Parameters);
    // bool OnRelease();

protected:
    bool Configure();

private:
    string key_, pass_, path_;
    int numclients_;
    int lastclient_;
    request *clients_;
};

#endif
