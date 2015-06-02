/***************************************************************************
    ODBC plugin for NWNX - Implementation of the CNWNXODBC class.
    copyright (c) 2006-2008 dumbo (dumbo@nm.ru) & virusman (virusman@virusman.ru)

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

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <pthread.h>
#include <stddef.h>

#include "NWNXodbc.h"
#include "HookSCORCO.h"

extern PLUGINLINK *pluginLink;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNWNXODBC::CNWNXODBC()
{
    confKey = "ODBC2";

    request_counter = 0;
    sqlerror_counter = 0;
    scorcoSQL = 0;
    db = 0;
    dbType = dbNONE;
    hookScorco = true;
    bReconnectOnError = false;
    memset(&p, 0, sizeof(PARAMETERS));
}
//============================================================================================================================

CNWNXODBC::~CNWNXODBC()
{
    OnRelease();
}

//============================================================================================================================

bool CNWNXODBC::OnCreate(gline *config, const char* LogDir)
{
    char log[128];

    // call the base class function
    sprintf(log, "%s/nwnx_odbc.txt", LogDir);
    if (!CNWNXBase::OnCreate(config, log))
        return false;

    // write copy information to the log file
    Log(0, "NWNX2 ODBC2 version 1.0.1 for Linux.\n");
    Log(0, "(c) 2005-2006 dumbo (dumbo@nm.ru)\n");
    Log(0, "(c) 2006-2010 virusman (virusman@virusman.ru)\n");
#ifdef SQLITE_SUPPORT
    Log(0, "SQLite engine is supported\n");
#endif
#ifdef PGSQL_SUPPORT
    Log(0, "PostgreSQL engine is supported\n");
#endif
#ifdef MYSQL_SUPPORT
    Log(0, "MySQL engine is supported\n");
#endif

    if (!LoadConfiguration())
        return false;

    if (!pluginLink) {
        Log(0, "Plugin link not accessible\n");
    } else {
        Log(0, "Plugin link: %08lX\n", pluginLink);
        Log(0, "Plugin link: %08lX\n", pluginLink);
        hSCOEvent = CreateHookableEvent(EVENT_ODBC_SCO);
        hRCOEvent = CreateHookableEvent(EVENT_ODBC_RCO);
    }

    if (hookScorco) {
        scorcoSQL = (char*) malloc(MAXSQL);
        int ret = HookFunctions();
        if (!ret) return ret;
    }

    return Connect();
}

//============================================================================================================================

BOOL CNWNXODBC::Connect()
{
    BOOL connected;
// CODBC* odbc;
#ifdef MYSQL_SUPPORT
    CMySQL* mysql;
#endif
#ifdef SQLITE_SUPPORT
    CSQLite* sqlite;
#endif
#ifdef PGSQL_SUPPORT
    CPgSQL* pgsql;
#endif



    // create a database instance
    switch (dbType) {
#ifdef MYSQL_SUPPORT
        case dbMYSQL:
            mysql = new CMySQL();
            if (strcmp(p.server, "localhost") == 0) {
                if (p.socket)
                    Log(2, "o Connecting to localhost, socket=%s\n", p.socket);
                else
                    Log(2, "o Connecting to localhost, default socket\n");
            } else if (p.server) {
                if (p.port)
                    Log(2, "o Connecting to %s, port=%d\n", p.server, p.port);
                else
                    Log(2, "o Connecting to %s, default port\n", p.server);
            }
            connected = mysql->Connect(p.server, p.user, p.pass, p.db, p.port, p.socket, p.charset);
            db = mysql;
            break;
#endif
#ifdef SQLITE_SUPPORT
        case dbSQLITE:
            sqlite = new CSQLite();
            connected = sqlite->Connect(p.db);
            db = sqlite;
            break;
#endif
#ifdef PGSQL_SUPPORT
        case dbPGSQL:
            pgsql = new CPgSQL();
            connected = pgsql->Connect(p.server, p.user, p.pass, p.db);
            db = pgsql;
            break;
#endif
        case dbNONE:
            // Do not connect, no database has been compiled in.
            Log(0, "o Not connecting, no valid datasource has been selected.\n");
            connected = false;
            return true;
    }

    // try to connect to the database
    if (!connected) {
        Log(0, "! Error while connecting to database: %s\n", db->GetErrorMessage());
        return false;
    }

    // we successfully connected
    Log(0, "o Connect successful.\n");
    return true;
}

//============================================================================================================================
BOOL CNWNXODBC::Reconnect()
{
#ifdef MYSQL_SUPPORT
    int error_code = reinterpret_cast<CMySQL*>(db)->GetErrorCode();
    if (bReconnectOnError &&
            dbType == dbMYSQL &&
            (error_code == CR_SERVER_GONE_ERROR ||
             error_code == CR_CONNECTION_ERROR ||
             error_code == CR_CONN_HOST_ERROR)
       ) {
        if (db)
            db->Disconnect();

        Log(1, "o Trying to reconnect...\n");


        if (Connect()) {
            Log(1, "o Reconnect successful\n");
            //if(output != NULL)
            //	snprintf(output, strlen(output), "%d", 1);
            return true;
        }

        Log(1, "! Reconnect failed!\n");
        //if(output != NULL)
        //	snprintf(output, strlen(output), "%d", 0);
    }
#endif
    return false;
}

//============================================================================================================================
char* CNWNXODBC::OnRequest(char* gameObject, char* Request, char* Parameters)
{
    if (strncmp(Request, "EXEC", 4) == 0)
        Execute(Parameters);
    else if (strncmp(Request, "FETCH", 5) == 0)
        return Fetch(Parameters, strlen(Parameters));
    else if (strncmp(Request, "SETSCORCOSQL", 12) == 0)
        SetScorcoSQL(Parameters);
    else if (strncmp(Request, "STOREOBJECT", 11) == 0) {
        int nSize = 0;
        char *pData = SaveObject(strtol(Parameters, NULL, 16), nSize);
        WriteSCO("NWNX", "-", "-", 0, (unsigned char *)pData, nSize);
    } else if (strncmp(Request, "RETRIEVEOBJECT", 14) == 0) {
        dword AreaID;
        float x, y, z, fFacing;
        if (sscanf(Parameters, "%lx¬%f¬%f¬%f¬%f", &AreaID, &x, &y, &z, &fFacing) < 5) {
            Log(1, "o sscanf error\n");
            return NULL;
        }
        Location lLoc;
        lLoc.AreaID = AreaID;
        lLoc.vect.X = x;
        lLoc.vect.Y = y;
        lLoc.vect.Z = z;
        lLoc.Facing = fFacing;
        int nSize = 0;
        unsigned char *pData = ReadSCO("NWNX", "-", "-", &nSize, &nSize);
        if (pData && nSize)
            lastObjectID = LoadObject((const char *)pData, nSize, lLoc);
        else
            lastObjectID = 0x7F000000;
    }

    return NULL;
}

//============================================================================================================================
unsigned long CNWNXODBC::OnRequestObject(char *gameObject, char *Request)
{
    if (strncmp(Request, "RETRIEVEOBJECT", 14) == 0) {
        return lastObjectID;
    } else {
        return 0x7F000000;
    }
}

//============================================================================================================================
void CNWNXODBC::Execute(char *request)
{
    if (!db) {
        Log(1, "! Error: Tried to execute SQL statement, but no support compiled in.\n");
        request[0] = '0';
        request[1] = 0;
        return;
    }
    Log(2, "o Got request: %s\n", request);
    request_counter++;

    if (!request || request[0] == 0) {
        Log(1, "! SQL Error: empty query\n");
        return;
    }


    bool bSuccess = false;

    // try to execute the SQL query
    if (db->Execute((const uchar*)request))
        bSuccess = true;
    else {
        Log(1, "! SQL Error: %s\n", db->GetErrorMessage());

        if (
            Reconnect() &&
            db->Execute((const uchar*)request)
        )
            bSuccess = true;
    }

    request[0] = bSuccess ? '1' : '0';
    request[1] = 0;
}

//============================================================================================================================
char * CNWNXODBC::Fetch(char * buffer, unsigned int buffersize)
{
    if (!db) {
        Log(1, "! Error: Tried to execute SQL statement, but no support compiled in.\n");
        buffer[0] = 0x0;
        return NULL;
    }

    // Clear the SPACER buffer.
    buffer[0] = '\0';

    // Fetch a row from the database.
    char * result = db->Fetch(buffer, buffersize);

    // Print a row content to a log file.
    if (result)
        Log(2, "o Sent result: %s\n", result);
    else
        Log(2, "o No result\n");

    return result;
}

//============================================================================================================================
void CNWNXODBC::SetScorcoSQL(char *request)
{
    if (!db) {
        Log(1, "! Error: Tried to execute SQL-based SCO/RCO, but no support compiled in.\n");
        return;
    }

    memcpy(scorcoSQL, request, strlen(request) + 1);
    Log(2, "o Got request (scorco): %s\n", scorcoSQL);
}

//============================================================================================================================
bool CNWNXODBC::OnRelease()
{
    Log(0, "o Shutdown.\n");

    if (db) db->Disconnect();

    if (scorcoSQL)
        free(scorcoSQL);

    // release the server
    if (p.server)
        free(p.server);

    // release memory
    if (dbType == dbMYSQL || dbType == dbPGSQL) {
        free(p.user);
        free(p.pass);
        free(p.db);
    }
    return true;
}

//============================================================================================================================
int CNWNXODBC::WriteSCO(const char * database, const char * key, char * player, int flags, unsigned char * pData, int size)
{
    Log(3, "o SCO: db='%s', key='%s', player='%s', flags=%08lX, pData=%08lX, size=%08lX\n", database, key, player, flags, pData, size);

    if (strcmp(key, "-") == 0) {

        if (!db) {
            Log(1, "! Error: Tried to execute SQL-based SCO/RCO, but no support compiled in.\n");
            return 0;
        }

        if (size > 0) {
            //Log ("o Writing scorco data.\n");
            if (!db->WriteScorcoData(scorcoSQL, pData, size)) {
                Log(1, "! SQL Error: %s\n", db->GetErrorMessage());
                if (
                    Reconnect() &&
                    db->WriteScorcoData(scorcoSQL, pData, size)
                )
                    return 1;
            }
        }
    } else {
        ODBCSCORCOEvent scoInfo = {
            database,
            key,
            player,
            pData,
            size
        };
        NotifyEventHooks(hSCOEvent, (uintptr_t) &scoInfo);

        return 1;
    }
    return 0;
}


//============================================================================================================================
unsigned char * CNWNXODBC::ReadSCO(const char * database, const char * key, char * player, int * arg4, int * size)
{
    *arg4 = 0x4f;

    Log(3, "o RCO(0): db='%s', key='%s', player='%s', arg4=%08lX, size=%08lX\n", database, key, player, arg4, size);

    if (strcmp(key, "-") == 0) {
        if (!db) {
            Log(1, "! Error: Tried to execute SQL-based SCO/RCO, but no support compiled in.\n");
            return NULL;
        }

        BYTE* pData;
        BOOL sqlError;

        //Log ("o Reading scorco data.\n");
        pData = db->ReadScorcoData(scorcoSQL, key, &sqlError, size);

        Log(3, "o RCO(1): db='%s', key='%s', player='%s', arg4=%08lX, size=%08lX\n", database, key, player, *arg4, *size);
        Log(3, "o RCO(2): err=%lX, pData=%08lX, pData='%s'\n", sqlError, pData, pData);

        if (!sqlError && pData)
            return pData;
        else {
            if (sqlError) {
                Log(1, "! SQL Error: %s\n", db->GetErrorMessage());
                if (Reconnect()) {
                    pData = db->ReadScorcoData(scorcoSQL, key, &sqlError, size);
                    if (!sqlError && pData)
                        return pData;
                }
            }
        }
        return NULL;
    } else {
        ODBCSCORCOEvent rcoInfo = {
            database,
            key,
            player,
            NULL,
            0
        };
        NotifyEventHooks(hRCOEvent, (uintptr_t) &rcoInfo);

        if (rcoInfo.pData && rcoInfo.size) {
            *size = rcoInfo.size;
            Log(3, "o RCO(n1): db='%s', key='%s', player='%s', arg4=%08lX, size=%08lX\n", database, key, player, *arg4, *size);
            Log(3, "o RCO(n2): pData=%08lX, size=%08lX, pData='%s'\n", rcoInfo.pData, rcoInfo.size, rcoInfo.pData);
            return rcoInfo.pData;
        }
        return NULL;
    }
}

//============================================================================================================================
bool CNWNXODBC::LoadConfiguration()
{
    char buffer[256];

    if (!nwnxConfig->exists(confKey)) {
        Log(0, "o Critical Error: Section [%s] not found in nwnx2.ini\n", confKey);
        return false;
    }

    // see what mode should be used
    strcpy(buffer, (char*)((*nwnxConfig)[confKey]["source"].c_str()));
    dbType = dbNONE;

#ifdef MYSQL_SUPPORT
    if (strcasecmp(buffer, "MYSQL") == 0) {
        // load in the settings for a direct mysql connection
        p.server    = strdup((char*)((*nwnxConfig)[confKey]["server"].c_str()));
        p.user      = strdup((char*)((*nwnxConfig)[confKey]["user"].c_str()));
        p.pass      = strdup((char*)((*nwnxConfig)[confKey]["pass"].c_str()));
        if (!*p.pass)
            p.pass      = strdup((char*)((*nwnxConfig)[confKey]["pwd"].c_str()));
        p.db        = strdup((char*)((*nwnxConfig)[confKey]["db"].c_str()));
        p.port      = atoi((char*)((*nwnxConfig)[confKey]["port"].c_str()));
        p.socket    = strdup((char*)((*nwnxConfig)[confKey]["socket"].c_str()));
        if (p.socket && !*p.socket)
            p.socket = NULL;		//use default socket if it's not specified in the config
        p.charset   = strdup((char*)((*nwnxConfig)[confKey]["charset"].c_str()));
        dbType = dbMYSQL;
    }
#endif
    /*
      else if (strcasecmp (buffer, "ODBC") == 0) {
    		p.server = strdup((char*)((*nwnxConfig)[confKey]["dsn"].c_str()));
    		dbType = dbODBC;
    	}*/
#ifdef SQLITE_SUPPORT
    if (strcasecmp(buffer, "SQLITE") == 0) {
        // load in the settings for the internal database
        p.db = strdup((char*)((*nwnxConfig)[confKey]["file"].c_str()));
        dbType = dbSQLITE;
    }
#endif
#ifdef PGSQL_SUPPORT
    if (strcasecmp(buffer, "PGSQL") == 0) {
        // load in the settings for a direct pgsql connection
        p.server	  = strdup((char*)((*nwnxConfig)[confKey]["server"].c_str()));
        p.user	  = strdup((char*)((*nwnxConfig)[confKey]["user"].c_str()));
        p.pass	  = strdup((char*)((*nwnxConfig)[confKey]["pass"].c_str()));
        if (!*p.pass)
            p.pass	  = strdup((char*)((*nwnxConfig)[confKey]["pwd"].c_str()));
        p.db		  = strdup((char*)((*nwnxConfig)[confKey]["db"].c_str()));
        dbType = dbPGSQL;
    }
#endif
    if (dbType == dbNONE) {
        p.db = NULL;
        Log(0, "o Warning: Datasource must be one of:\n");
#ifdef SQLITE_SUPPORT
        Log(0, "oo SQLITE\n");
#endif
#ifdef PGSQL_SUPPORT
        Log(0, "oo PGSQL\n");
#endif
#ifdef MYSQL_SUPPORT
        Log(0, "oo MYSQL\n");
#endif
        Log(0, "o Only providing SCO/RCO hooks to other plugins.\n");
    }

    // check if scorco should be hooked
    strcpy(buffer, (char*)((*nwnxConfig)[confKey]["hookscorco"].c_str()));
    if (strcasecmp(buffer, "false") == 0)
        hookScorco = false;

    //check reconnect flag
    strcpy(buffer, (char*)((*nwnxConfig)[confKey]["reconnectonerror"].c_str()));
    if (strcasecmp(buffer, "true") == 0)
        bReconnectOnError = true;


    return true;
}

//============================================================================================================================
