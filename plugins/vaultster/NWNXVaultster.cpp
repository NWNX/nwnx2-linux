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

#include "NWNXVaultster.h"
#include "constants.h"

CNWNXVaultster::CNWNXVaultster(void)
{
    confKey = (char*) "VAULTSTER";
}

CNWNXVaultster::~CNWNXVaultster(void)
{
}

bool
CNWNXVaultster::OnCreate(gline *nwnxConfig, const char *LogDir)
{
    if (LogDir == NULL) {
        cout << "NWNXVaultster: LogDir is not set" << endl;
        return false;
    }

    char log[128];
    sprintf(log, "%s/nwnx_vaultster.txt", LogDir);

    // call the base class function
    if (!CNWNXBase::OnCreate(nwnxConfig, log))
        return false;

    Log(0, "NWNX2 Vaultster Rewrite for Linux.\n");
    Log(0, "Copyright 2009 John Klar (plasmajohn at avlis dot org)\n\n");

    // spelunk nwnx2.ini for a common info
    if (!Configure())
        return false;

    return true;
}

char *
CNWNXVaultster::OnRequest(char* gameObject, char* Request, char* Parameters)
{
    int slot;

    if (strcasecmp(Request, "GETEXPORTPENDING") == 0) {
        sprintf(Parameters, "%d", (*NWN_AppManager)->app_server->srv_internal->srv_pc_export_pending);
        return NULL;
    } else if (strcasecmp(Request, "STATUS") == 0) {
        slot = atoi(Parameters);
        int status = clients_[slot].status;
        Log(0, "o Status for %s, %s = %d\n",
            clients_[slot].playerid.c_str(),
            clients_[slot].charname.c_str(),
            status);
        if (status == STATUS_ERROR || status == STATUS_OK)
            clients_[slot].status = STATUS_READY;
        sprintf(Parameters, "%d", status);
    } else if (strcasecmp(Request, "SEND") == 0) {
        // find an open slot
        time_t now = time(NULL);
        int i;
        for (i = 0; i < numclients_; i++) {
            slot = (lastclient_ + i) % numclients_;
            if (clients_[slot].status == STATUS_READY)
                break;
            /*
            else
            // is it stale? (older than 10 minutes)
            if(clients[slot].status != STATUS_BUSY &&
            	clients[slot].s_time < now-600) {
            	break;
            }
            */
        }

        if (i == numclients_) {
            Log(0, "o All clients busy.\n");
            sprintf(Parameters, "-2");
            return NULL;
        }

        request *req = &clients_[slot];
        req->status = STATUS_BUSY;

        int len, pidx = 1;
        char* param[4];
        char *p = strdup(Parameters);
        len = strlen(p);

        Log(0, "Params: %s\n", Parameters);

        // parse server, port, playerid, charname
        // parse server, playerid, charname, port

        param[0] = p;
        for (i = 0; i < len; i++) {
            if (p[i] == '|') {
                p[i] = 0;
                param[pidx] = &p[i + 1];
                ++pidx;
            }
        }

        len = strlen(param[2]);
        for (i = 0; i < len; i++)
            param[2][i] = tolower(param[2][i]);

        req->playerid = param[1];
        req->charname = param[2];

        req->c = new client(req->ios,
                            req->playerid,
                            req->charname,
                            param[0],
                            param[3],
                            key_,
                            pass_,
                            path_,
                            debuglevel,
                            this,
                            req);

        if (! req->c->prepfile()) {
            sprintf(Parameters, "-3");
            return NULL;
        } else {
            sprintf(Parameters, "%d", slot);
        }

        req->c->start();

        if (req->t != NULL)
            delete req->t;

        req->ios.reset();

        req->t = new boost::thread(boost::bind(&boost::asio::io_service::run, &req->ios));

        free(p);

        lastclient_ = (slot + 1) % numclients_;
    } else {
        Log(0, "o Invalid command.\n");
    }
    return NULL;
}

bool
CNWNXVaultster::Configure()
{

    if (!nwnxConfig->exists(confKey)) {
        Log(0, "[%s] section of nwnx2.ini is missing\n", confKey);
        return false;
    }

    key_ =	(*nwnxConfig)[confKey]["Key"];
    pass_ =	(*nwnxConfig)[confKey]["Password"];
    path_ =	(*nwnxConfig)[confKey]["Path"];

    lastclient_ = 0;
    numclients_ = atoi(((*nwnxConfig)[confKey]["MaxClients"]).c_str());
    clients_ = new request[numclients_];

    for (int i = 0; i < numclients_; i++) {
        clients_[i].status = STATUS_READY;
        clients_[i].t = NULL;
    }

    return true;
}

