/***************************************************************************
    CPgSQL.cpp: implementation of the CPgSQL class.
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

#include "pgsql.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define HOST	"host="
#define PORT	"port="
#define DB	"dbname="
#define USR	"user="
#define PW	"password="
#define PORT_NUM	5432


CPgSQL::CPgSQL() : CDB()
{
    result = NULL;
}

CPgSQL::~CPgSQL()
{
}


BOOL CPgSQL::Connect()
{
    // try to establish a default connection
    return Connect("localhost", "nwn", "nwnpwd", "nwn");
}


BOOL CPgSQL::Connect(const char *server, const char *user, const char *pass, const char *db)
{
    char *connstring = (char *)malloc(strlen(HOST)
                                      + strlen(PORT)
                                      + strlen(DB)
                                      + strlen(USR)
                                      + strlen(PW)
                                      + 20
                                      + strlen(server)
                                      + strlen(db)
                                      + strlen(user)
                                      + strlen(pass));
    // Build the connection string
    sprintf(connstring, HOST "%s " PORT "%hu " DB "%s " USR "%s " PW "%s", server, PORT_NUM, db, user, pass);

    // Connect attempt
    pgsql = PQconnectdb(connstring);
    if (PQstatus(pgsql) != CONNECTION_OK) {
        free(connstring);
        return false;
    }

    free(connstring);

    return true;
}

void CPgSQL::Disconnect()
{
    // close the connection
    PQfinish(pgsql);
}

BOOL CPgSQL::Execute(const uchar* query)
{
    if (PQstatus(pgsql) != CONNECTION_OK)
        return false;

    // release a previous result set
    if (result != NULL) {
        PQclear(result);
        result = NULL;
    }

    // execute the query
    result = PQexec(pgsql, (const char *) query);
    if (result == NULL || PQresultStatus(result) == PGRES_FATAL_ERROR) {
        return false;
    }

    // successfull retreived the results from the SELECT
    NumCol = PQnfields(result);
    // Set the CurCol cursor to 0
    CurRow = 0;
    return true;
}

char * CPgSQL::Fetch(char * buffer, unsigned int buffersize)
{

    if (PQstatus(pgsql) != CONNECTION_OK || PQresultStatus(result) != PGRES_TUPLES_OK || PQntuples(result) <= CurRow)
        return NULL;

    // Calculate length of the row.
    unsigned long row_length = 0;
    for (unsigned int i = 0; i < NumCol; ++i) {
        // We will need one more character per a column to act as a column separator and a NULL terminating character.
        row_length += PQgetlength(result, CurRow, i) + 1;
    }
    if (row_length == 0)
        return NULL;

    // If the row length exceeds size of the SPACER buffer, allocate a new one.
    // The SPACER will be deleted automatically in nwnx2lib.cpp.
    char * result = row_length <= buffersize ? buffer : (char *)malloc(row_length);

    for (unsigned int i = 0, pos = 0; i < NumCol; ++i) {
        int length = PQgetlength(this->result, CurRow, i);
        strncpy(&result[pos], PQgetvalue(this->result, CurRow, i), length);
        pos += length;
        result[pos++] = '¬';
    }
    result[row_length - 1] = '\0';

    CurRow++;

    return result;
}

BOOL CPgSQL::WriteScorcoData(char* SQL, BYTE* pData, int Length)
{
    BOOL bWriteSuccess = true;

    unsigned int escaped_data_len = 0;
    char* escaped_data = (char*)PQescapeByteaConn(pgsql, pData, Length, &escaped_data_len);

    unsigned int full_query_len = (strlen(SQL) - 2) + (escaped_data_len + 4);
    char* full_query = new char[full_query_len];

    // Build the full query string. The SQL query must have a %s token to locate the
    // substituted escaped data. This loops through the original SQL writing it to the
    // full query string until the %s is hit, then inserts the escaped data surrounded
    // by the proper escape syntax, then returns to write the remaining SQL.
    char* fs_ptr = SQL;
    char* fd_ptr = escaped_data;
    char* tq_ptr = full_query;
    bool tok_hit = false;
    while (fs_ptr[0] != '\x00') {
        if (!tok_hit && (fs_ptr[0] == '%') && (fs_ptr[1] == 's')) {
            tok_hit = true;
            fs_ptr += 2;
            *tq_ptr++ = 'E'; *tq_ptr++ = '\''; *tq_ptr++ = '\\';
            while (fd_ptr[0] != '\x00') *tq_ptr++ = *fd_ptr++;
            *tq_ptr++ = '\'';
        } else {
            *tq_ptr++ = *fs_ptr++;
        }
    }
    *tq_ptr = '\x00';
    if (!tok_hit) bWriteSuccess = false;

    PGresult* sco_result = PQexec(pgsql, full_query);
    if (PQresultStatus(sco_result) != PGRES_COMMAND_OK) bWriteSuccess = false;

    PQfreemem(escaped_data);
    delete[] full_query;
    PQclear(sco_result);

    return bWriteSuccess;
}

BYTE * CPgSQL::ReadScorcoData(const char * SQL, const char * param, BOOL * pSqlError, int * size)
{
    *pSqlError = false;
    *size = 0;

    PGresult* rco_result = NULL;
    if (strcmp(param, "FETCHMODE") != 0) {
        // In normal mode (NOT in FETCHMODE), run the SQL query for a new result set
        rco_result = PQexec(pgsql, SQL);
    } else {
        // In FETCHMODE, use the result set from previous call to EXEC of a SQL query.
        rco_result = result;
    }
    if (PQresultStatus(rco_result) != PGRES_TUPLES_OK) {
        PQclear(rco_result);
        *pSqlError = true;
        return NULL;
    }
    if (PQntuples(rco_result) > 0) {
        // At lest one row left in the result set, assume it's the first field from the query,
        // unescape it (since PostgreSQL is being queried in text mode), and return it in a
        // heap allocated block of memory for the NWN VM to deallocate.
        unsigned int one_field_len = PQgetlength(rco_result, 0, 0);
        unsigned char* one_field = (unsigned char*)PQgetvalue(rco_result, 0, 0); // static do not deallocate !
        unsigned int unesc_field_len = 0;
        unsigned char *unesc_field = PQunescapeBytea(one_field, &unesc_field_len);
        if (unesc_field == NULL) {
            *pSqlError = true;
            return NULL;
        }
        PQclear(rco_result);
        *size = unesc_field_len;
        return unesc_field;
    } else {
        PQclear(rco_result);
        return NULL;
    }

    return NULL;
}

const char* CPgSQL::GetErrorMessage()
{
    // return the error message
    return PQerrorMessage(pgsql);
}
