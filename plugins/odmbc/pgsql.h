/***************************************************************************
    CPgSQL.h: interface for the CPgSQL class.
    copyright (c) 2008 virusman (virusman@virusman.ru)

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

#if !defined _PGSQL_H_
#define _PGSQL_H_

#include "db.h"

#include <libpq-fe.h>

class CPgSQL : public CDB
{
public:
    CPgSQL();
    ~CPgSQL();

    BOOL Connect();
    BOOL Connect(const char *server, const char *user, const char *pass, const char *db);
    void Disconnect();

    BOOL Execute(const uchar* query);
    char * Fetch(char * buffer, unsigned int buffersize);
    BOOL WriteScorcoData(char* SQL, BYTE* pData, int Length);
    BYTE * ReadScorcoData(const char * SQL, const char * param, BOOL * pSqlError, int * size);

    const char* GetErrorMessage();

private:
    PGconn *pgsql;
    PGresult *result;
    unsigned long NumCol;
    int CurRow;

    unsigned long version;
};

#endif
