/***************************************************************************
    Serverlist plugin for NWNX  - hooks implementation
    (c) 2007 virusman

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

#include <stdint.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <dlfcn.h>
#include <stdarg.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <netdb.h>

#include <limits.h>		/* for PAGESIZE */
#ifndef PAGESIZE
#define PAGESIZE 4096
#endif

#include "ServerlistHooks.h"
#include "NWNXServerlist.h"

extern CNWNXServerlist plugin;

void (*CExoNetInternal__SendMessage_Return)();

unsigned long GetTickCount()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int sendto_hook(int sockfd, const void *buf, size_t len, int flags,
                struct sockaddr_in *dest_addr, socklen_t addrlen)
{
    static sockaddr_in sin = {0};

    plugin.Log(0, "* sendtoMstHook: call to %s, %d\n", inet_ntoa(dest_addr->sin_addr), ntohs(dest_addr->sin_port));

    if (dest_addr->sin_port != htons(MASTER_SERVER_PORT))
        return sendto(sockfd, buf, len, flags, (const struct sockaddr *) dest_addr, addrlen);

    static unsigned long LastMstResolveTick = 0;

    //
    // If it has been 30 minute since the last time the Mst hostname was
    // resolved, or this is the first send, resolve it now.
    //

    if ((LastMstResolveTick == 0) ||
            (GetTickCount() - LastMstResolveTick) >= 1800000) {
        hostent *he = gethostbyname(MASTER_SERVER_HOSTNAME);

        if (he == NULL) {
            plugin.Log(0, "* sendtoMstHook: Failed to resolve %s\n", MASTER_SERVER_HOSTNAME);
        } else {
            memcpy(&sin, dest_addr, addrlen);
            LastMstResolveTick = GetTickCount();
            sin.sin_addr.s_addr = *(unsigned long *)he->h_addr;

            plugin.Log(0, "* sendtoMstHook: Master server hostname resolved.\n");
        }
    }

    //
    // Send a copy of the message to the emulation master server, then pass it
    // on to the BioWare master server.
    //

    sendto(sockfd, buf, len, flags, (const struct sockaddr *) &sin, addrlen);

    return sendto(sockfd, buf, len, flags, (const struct sockaddr *) dest_addr, addrlen);

}

int HookFunctions()
{
    unsigned char *sendto_call = (unsigned char *) 0x082C791B;
    nx_hook_enable_write(sendto_call, 5);
    *(uint32_t *)(sendto_call + 1) = (uint32_t)sendto_hook - (uint32_t)(sendto_call + 5);
    return 1;
}
