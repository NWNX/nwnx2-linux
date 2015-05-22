
/***************************************************************************
    CMySQL.h: interface for the CMySQL class.
    Copyright (C) 2004 Jeroen Broekhuizen (nwnx@jengine.nl)
    copyright (c) 2006 dumbo (dumbo@nm.ru) & virusman (virusman@virusman.ru)

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

#if !defined _MYSQL_H_
#define _MYSQL_H_

#include "db.h"

#include <mysql/mysql.h>
#include <mysql/errmsg.h>

class CMySQL : public CDB
{
public:
    CMySQL();
    ~CMySQL();

    BOOL Connect();
    BOOL Connect(const char *server, const char *user, const char *pass, const char *db, unsigned int port, const char *unix_socket, const char *charset);
    void Disconnect();

    BOOL Execute(const uchar* query);
    char * Fetch(char * buffer, unsigned int buffersize);
    BOOL WriteScorcoData(char* SQL, BYTE* pData, int Length);
    BYTE * ReadScorcoData(const char * SQL, const char * param, BOOL * pSqlError, int * size);
    BOOL SetCharacterSet(const char *charset);

    const char* GetErrorMessage();

    unsigned int GetErrorCode();

private:
    MYSQL mysql;
    MYSQL* connection;
    MYSQL_RES *result;
    ulong NumCol;
    unsigned long version;
};

#endif
