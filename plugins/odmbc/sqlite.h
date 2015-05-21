/***************************************************************************
    sqlite.h: interface for the CSQLITE class.
    Copyright (C) 2005 Ingmar Stieger (papillon@blackdagger.com)
    Copyright (C) 2007 virusman (virusman@virusman.ru)

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

#if !defined _SQLITE_H_
#define _SQLITE_H_

#include <vector>
#include <string>
#include "db.h"
#include <sqlite3.h>

class CSQLite : public CDB
{
public:
    static const int lastErrorSize = 512;
    CSQLite();
    ~CSQLite();

    BOOL Connect();
    BOOL Connect(const char * db);
    void Disconnect();

    BOOL Execute(const uchar* query);
    char * Fetch(char * buffer, unsigned int buffersize);
    BOOL WriteScorcoData(char* SQL, BYTE* pData, int Length);
    BYTE * ReadScorcoData(const char * SQL, const char * param, BOOL * pSqlError, int * size);

    const char* GetErrorMessage();
    char lastError[lastErrorSize];

private:
    sqlite3 *sdb;
    sqlite3_stmt* pStmt;
    bool firstFetch;
    void finalizeStatement();
};

#endif
