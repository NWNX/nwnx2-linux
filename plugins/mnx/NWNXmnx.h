/***************************************************************************
    NWNX FOR LINUX Minimal Network eXtender plugin Class interface
    Copyright (C) 2003 John Klar (paladin at projectplasma dot com)

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

#ifndef NWNXmnx_h_
#define NWNXmnx_h_

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h> /* memset() */
#include <sys/time.h> /* select() */
#include <errno.h>
#include <signal.h>

using namespace::std;
#include <iostream>
#include <map>
#include <string>

#include "NWNXBase.h"

struct connection {
    int sd;
    struct sockaddr_in srvAddr;
};

typedef map<string, connection> connectdict;

class CNWNXmnx : public CNWNXBase
{
public:
    CNWNXmnx();
    ~CNWNXmnx();

    bool OnCreate(gline *nwnxConfig, const char *LogDir = NULL);
    char *OnRequest(char* gameObject, char* Request, char* Parameters);
    // bool OnRelease();

protected:
    bool ClientClose(const char *conn);
    bool ClientInit(const char *conn, const char *dest);
    bool SendMsg(const char *conn, const char *Request, char *Parameters);
    bool Configure();

private:

    connectdict Connections;
    char mnx_buf[2048];
};

#endif
