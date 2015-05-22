/***************************************************************************
    CMySQL.cpp: implementation of the CMySQL class.
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

#include "mysql.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

CMySQL::CMySQL() : CDB()
{
    result = NULL;
}

CMySQL::~CMySQL()
{
}


BOOL CMySQL::Connect()
{
    // try to establish a default connection
    return Connect("localhost", "nwn", "nwnpwd", "nwn", 0, NULL, NULL);
}


BOOL CMySQL::Connect(const char *server, const char *user, const char *pass, const char *db, unsigned int port, const char *unix_socket, const char *charset)
{
    // initialize the mysql structure
    if (mysql_init(&mysql) == NULL) {
        return false;
    }
    // try to connect to the mysql server
    connection = mysql_real_connect(&mysql, server, user, pass, db, port, unix_socket, 0);
    if (connection == NULL) {
        mysql_close(&mysql);
        return false;
    }
    version = mysql_get_server_version(&mysql);
    if (charset) SetCharacterSet(charset);

    return true;
}

void CMySQL::Disconnect()
{
    // close the connection
    mysql_close(&mysql);
}

BOOL CMySQL::SetCharacterSet(const char *charset)
{
    return (mysql_set_character_set(&mysql, charset) == 0);
}

BOOL CMySQL::Execute(const uchar* query)
{
    if (connection == NULL)
        return false;

    // release a previous result set
    if (result != NULL) {
        mysql_free_result(result);
        result = NULL;
    }

    // execute the query
    if (mysql_query(connection, (const char *) query) != 0) {
        return false;
    }

    // store the resultset in local memory
    result = mysql_store_result(&mysql);
    if (result == NULL) {
        if (mysql_field_count(&mysql) != 0) {
            return false;
        }
    } else {
        // successfull retreived the results from the SELECT
        NumCol = mysql_num_fields(result);
    }
    return true;
}

char * CMySQL::Fetch(char * buffer, unsigned int buffersize)
{
    // Attempt to fetch a row and column lengths.
    MYSQL_ROW row;
    unsigned long * column_lengths;
    if (!connection || !result || !(row = mysql_fetch_row(result)) || !(column_lengths = mysql_fetch_lengths(result)))
        return NULL;

    // Calculate length of the row.
    unsigned long row_length = 0;
    for (unsigned int i = 0; i < NumCol; ++i) {
        // We will need one more character per a column to act as a column separator and a NULL terminating character.
        row_length += column_lengths[i] + 1;
    }
    if (row_length == 0)
        return NULL;

    // If the row length exceeds size of the SPACER buffer, allocate a new one.
    // The SPACER will be deleted automatically in nwnx2lib.cpp.
    char * result = row_length <= buffersize ? buffer : (char *)malloc(row_length);

    // Copy content of the columns to the buffer.
    for (unsigned int i = 0, pos = 0; i < NumCol; ++i) {
        strncpy(&result[pos], row[i], column_lengths[i]);
        pos += column_lengths[i];
        result[pos++] = '¬';
    }
    result[row_length - 1] = '\0';

    return result;
}

BOOL CMySQL::WriteScorcoData(char* SQL, BYTE* pData, int Length)
{
    int res;
    unsigned long len;
    char* Data = new char[Length * 2 + 1 + 2];
    char* pSQL = new char[MAXSQL + Length * 2 + 1];

    len = mysql_real_escape_string(&mysql, Data + 1, (const char*)pData, Length);
    Data[0] = Data[len + 1] = 39; //'
    Data[len + 2] = 0x0;
    sprintf(pSQL, SQL, Data);

    MYSQL_RES *result = mysql_store_result(&mysql);
    res = mysql_query(&mysql, (const char *) pSQL);

    mysql_free_result(result);
    delete[] pSQL;
    delete[] Data;

    if (res == 0)
        return true;
    else
        return false;
}

BYTE * CMySQL::ReadScorcoData(const char * SQL, const char * param, BOOL * pSqlError, int * size)
{
    MYSQL_RES *rcoresult;
    if (strcmp(param, "FETCHMODE") != 0) {
        if (mysql_query(&mysql, (const char *) SQL) != 0) {
            *pSqlError = true;
            return NULL;
        }

        /*if (result)
        {
        mysql_free_result(result);
        result = NULL;
        }*/
        rcoresult = mysql_store_result(&mysql);
        if (!rcoresult) {
            *pSqlError = true;
            return NULL;
        }
    } else rcoresult = result;

    MYSQL_ROW row;
    *pSqlError = false;
    row = mysql_fetch_row(rcoresult);
    if (row) {
        unsigned long* length = mysql_fetch_lengths(rcoresult);
        // allocate buf for result!
        char* buf = new char[*length];
        if (!buf) return NULL;

        memcpy(buf, row[0], length[0]);
        *size = length[0];
        mysql_free_result(rcoresult);
        return (BYTE*)buf;
    } else {
        mysql_free_result(rcoresult);
        return NULL;
    }
}

const char* CMySQL::GetErrorMessage()
{
    // return the error message
    return mysql_error(&mysql);
}

unsigned int CMySQL::GetErrorCode()
{
    // return the error code
    return mysql_errno(&mysql);
}
