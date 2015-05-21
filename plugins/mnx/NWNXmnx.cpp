/***************************************************************************
    NWNX FOR LINUX Minimal Network eXtender plugin Class
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

/* modified */
/* fpont 12/99 */
/* pont.net    */
/* udpClient.c */
#include "NWNXmnx.h"

CNWNXmnx::CNWNXmnx()
{
    confKey = "MNX";
}

CNWNXmnx::~CNWNXmnx()
{
}

bool CNWNXmnx::ClientClose(const char *cname)
{
    connectdict::iterator i;
    if ((i = Connections.find(cname)) == Connections.end()) {
        Log(0, "[%s] has not been registerred.\n", cname);
        return false;
    }

    if ((*i).second.sd != -1)
        close((*i).second.sd);
    Connections.erase(i);
    return true;
}

bool CNWNXmnx::ClientInit(const char *cname, const char *dest)
{
    int rc, len;;
    struct sockaddr_in cliAddr;
    struct hostent *h;
    const char *pStr;
    char hostname[128];
    short port;
    connection conn;

    if (Connections.find(cname) != Connections.end()) {
        Log(0, "[%s] has already been registerred.\n", cname);
        return false;
    }

    if (dest == NULL || dest[0] == '\0' || (pStr = strchr(dest, ':')) == NULL) {
        Log(1, "[%s] Received: \"%s\"\n", cname, dest);
        Log(0, "USAGE: name=NWNX!MNX!OPEN!<CONNNAME> value=hostname:port\n");
        return false;
    }

    len = pStr - dest;
    strncpy(hostname, dest, len);
    hostname[len] = 0;

    ++pStr;
    port = atoi(pStr);

    conn.sd = -1;

    /* get server IP address (no check if input is IP address or DNS name */
    h = gethostbyname(hostname);
    if (h == NULL) {
        Log(0, "[%s] unknown host '%s'\n", cname, hostname);
        return false;
    }

    Log(1, "[%s] sending data to '%s' (IP : %s) \n", cname, h->h_name,
        inet_ntoa(*(struct in_addr *)h->h_addr_list[0]));

    conn.srvAddr.sin_family = h->h_addrtype;
    memcpy((char *) &conn.srvAddr.sin_addr.s_addr,
           h->h_addr_list[0], h->h_length);
    conn.srvAddr.sin_port = htons(port);

    /* socket creation */
    conn.sd = socket(AF_INET, SOCK_DGRAM, 0);
    if (conn.sd < 0) {
        conn.sd = -1;
        Log(0, "[%s] cannot open socket \n", cname);
        return false;
    }

    /* bind any port */
    cliAddr.sin_family = AF_INET;
    cliAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    cliAddr.sin_port = htons(0);

    rc = bind(conn.sd, (struct sockaddr *) &cliAddr, sizeof(cliAddr));
    if (rc < 0) {
        Log(0, "[%s] cannot bind port\n", cname);
        close(conn.sd);
        return false;
    }

    Connections[cname] = conn;

    return true;
}

bool CNWNXmnx::OnCreate(gline *config, const char *LogDir)
{
    char log[128];
    sprintf(log, "%s/nwnx_mnx.txt", LogDir);

    // call the base class function
    if (!CNWNXBase::OnCreate(config, log))
        return false;

    // spelunk nwnx2.ini for a connection section
    if (!Configure())
        return false;

    return true;
}

char *CNWNXmnx::OnRequest(char *gameObject, char *Request, char* Parameters)
{
    int len;
    char cmd[32], cname[32], *bang, *bang2;

    Log(2, "Request: %s\n", Request);
    Log(3, "Params : %s\n", Parameters);

    if ((bang = strchr(Request, '!')) == NULL) {
        sprintf(mnx_buf, "no command found.");
        ParamLog(0, mnx_buf, Parameters);
        return NULL;
    }
    len = bang - Request;
    strncpy(cmd, Request, len);
    cmd[len] = 0;

    ++bang;

    if ((bang2 = strchr(bang, '!')) != NULL) {
        len = bang2 - bang;
        strncpy(cname, bang, len);
        cname[len] = 0;
        ++bang2;
    } else {
        len = strlen(bang);
        strcpy(cname, bang);
    }

    if (len == 0) {
        sprintf(mnx_buf, "no connection name found");
        ParamLog(0, mnx_buf, Parameters);
        return NULL;
    }

    if (strcmp("OPEN", cmd) == 0) {
        ClientInit(cname, Parameters);
    } else if (strcmp("CLOSE", cmd) == 0) {
        ClientClose(cname);
    } else if (strcmp("SEND", cmd) == 0) {
        SendMsg(cname, bang2, Parameters);
    } else {
        sprintf(mnx_buf, "[%s] bad command", cmd);
        ParamLog(0, mnx_buf, Parameters);
    }

    return NULL;
}

bool CNWNXmnx::SendMsg(const char *cname, const char *Request, char *Parameters)
{

    int rc, len;
    socklen_t fromlen;
    struct timeval tv;
    fd_set fds;
    connection *conn;

    connectdict::iterator i;
    if ((i = Connections.find(cname)) == Connections.end()) {
        sprintf(mnx_buf, "[%s] has not been registerred.", cname);
        ParamLog(0, mnx_buf, Parameters);
        return false;
    }

    conn = &(*i).second;

    if (conn->sd == -1) {
        sprintf(mnx_buf, "[%s] *** no backend ***", cname);
        ParamLog(0, mnx_buf, Parameters);
        return true;
    }

    if (Request == NULL || Request[0] == 0)
        strcpy(mnx_buf, Parameters);
    else
        sprintf(mnx_buf, "%s!%s", Request, Parameters);

    /* send query */
    rc = sendto(conn->sd, mnx_buf, strlen(mnx_buf) + 1, 0,
                (struct sockaddr *) &conn->srvAddr,
                sizeof(conn->srvAddr));

    if (rc < 0) {
        sprintf(mnx_buf, "[%s] *** backend send errored [%d]:%s ***",
                cname, errno, strerror(errno));
        ParamLog(0, mnx_buf, Parameters);
        // close(conn->sd);
        // conn->sd = -1;
        return true;
    }

    /* 250ms */
    tv.tv_sec = 1;
    tv.tv_usec = 0;

    /* */
    FD_ZERO(&fds);
    FD_SET(conn->sd, &fds);

    if (select(conn->sd + 1, &fds, NULL, NULL, &tv) != 0) {

        memset(mnx_buf, 0, 2048);

        /* get response */
        rc = recvfrom(conn->sd, mnx_buf, 1024, 0, NULL,
                      &fromlen);

        len = strlen(Parameters);
        strncpy(Parameters, mnx_buf, len);

        if (rc < 0) {
            sprintf(mnx_buf, "[%s] *** backend recv errored [%d]:%s ***",
                    cname, errno, strerror(errno));
            ParamLog(0, mnx_buf, Parameters);
            // close(conn->sd);
            // conn->sd = -1;
            return true;
        }
        // printf("msg: %s\n",Parameters);

    } else {
        sprintf(mnx_buf, "[%s] *** backend timed-out ***", cname);
        Log(0, mnx_buf, Parameters);
        // close(conn->sd);
        // conn->sd = -1;
    }

    return true;
}

bool CNWNXmnx::Configure()
{
    char *srvcname;
    char *hostport;

    if (nwnxConfig->exists(confKey)) {
        srvcname = (char*)((*nwnxConfig)[confKey]["service"].c_str());
        hostport = (char*)((*nwnxConfig)[confKey]["hostname"].c_str());

        // this shouldn't cause a fatal error, so
        // we don't care about the return code
        ClientInit(srvcname, hostport);
    }

    return true;
}
