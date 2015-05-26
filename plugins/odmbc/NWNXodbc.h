/***************************************************************************
    ODBC plugin for NWNX - interface for the CNWNXChat class.
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

#ifndef _NWNX_odbc_H_
#define _NWNX_odbc_H_

#include "NWNXBase.h"

#include "pluginlink.h"


#include "db.h"
#ifdef MYSQL_SUPPORT
#include "mysql.h"
#endif
#ifdef SQLITE_SUPPORT
#include "sqlite.h"
#endif
#ifdef PGSQL_SUPPORT
#include "pgsql.h"
#endif
#include "HookSCORCO.h"
#include "ObjectStorage.h"

class CNWNXODBC : public CNWNXBase
{

public:
    CNWNXODBC();
    ~CNWNXODBC();
    bool OnCreate(gline *config, const char* LogDir);
    char* OnRequest(char* gameObject, char* Request, char* Parameters);
    unsigned long OnRequestObject(char *gameObject, char *Request);
    bool OnRelease();

    int WriteSCO(const char * database, const char * key, char * player, int flags, unsigned char * pData, int size);
    unsigned char * ReadSCO(const char * database, const char * key, char * player, int * arg4, int * size);

protected:
    BOOL Connect();
    BOOL Reconnect();
    void Execute(char* request);
    char * Fetch(char * buffer, unsigned int buffersize);
    void SetScorcoSQL(char *request);
    bool LoadConfiguration();

private:
    CDB* db;
    enum EDBType {dbNONE, dbODBC, dbMYSQL, dbSQLITE, dbPGSQL};
    int dbType;

    struct PARAMETERS {
        char *server;
        char *user;
        char *pass;
        char *db;
        unsigned int port;
        char *socket;
        char *charset;
    } p;

    unsigned int request_counter;
    unsigned int sqlerror_counter;

    bool hookScorco;
    bool bReconnectOnError;
    char* scorcoSQL;
    unsigned long lastObjectID;

    HANDLE hSCOEvent;
    HANDLE hRCOEvent;

    enum ELogLevel {logNothing, logErrors, logAll};
};

#endif
