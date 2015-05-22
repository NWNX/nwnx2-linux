/***************************************************************************
    sqlite.cpp: implementation of for CSQLITE class.
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

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "sqlite.h"

CSQLite::CSQLite() : CDB()
{
    pStmt = NULL;
    firstFetch = false;
}

CSQLite::~CSQLite()
{
}

BOOL CSQLite::Connect()
{
    return Connect("sqlite.db");
}

BOOL CSQLite::Connect(const char * db)
{
    int rc;
    rc = sqlite3_open(db, &sdb);
    if (rc) {
        sprintf(lastError, "Can't open database: %s", sqlite3_errmsg(sdb));
        sqlite3_close(sdb);
        return false;
    }

    // begin implicit transaction
    rc = sqlite3_prepare(sdb, "BEGIN", -1, &pStmt, NULL);
    if (rc != SQLITE_OK)
        strcpy(lastError, sqlite3_errmsg(sdb));
    else {
        rc = sqlite3_step(pStmt);
        if (rc != SQLITE_DONE)
            strcpy(lastError, sqlite3_errmsg(sdb));
        finalizeStatement();
    }

    return true;
}

void CSQLite::Disconnect()
{
    int rc;

    // end implicit transaction
    finalizeStatement();
    rc = sqlite3_prepare(sdb, "COMMIT", -1, &pStmt, NULL);
    if (rc != SQLITE_OK)
        strcpy(lastError, sqlite3_errmsg(sdb));
    else {
        rc = sqlite3_step(pStmt);
        if (rc != SQLITE_DONE)
            strcpy(lastError, sqlite3_errmsg(sdb));
    }
    finalizeStatement();
    sqlite3_close(sdb);
}

BOOL CSQLite::Execute(const uchar* query)
{
    int rc;

    // prepare query
    finalizeStatement();
    rc = sqlite3_prepare(sdb, (const char*) query, -1, &pStmt, NULL);
    if (rc != SQLITE_OK) {
        strcpy(lastError, sqlite3_errmsg(sdb));
        finalizeStatement();
        return false;
    }
    // execute step
    rc = sqlite3_step(pStmt);
    switch (rc) {
        case SQLITE_DONE:
            finalizeStatement();
            break;
        case SQLITE_ROW:
            firstFetch = true;
            break;
        case SQLITE_ERROR:
            strcpy(lastError, sqlite3_errmsg(sdb));
            finalizeStatement();
            return false;
            break;
    }

    return true;
}

char * CSQLite::Fetch(char * buffer, unsigned int buffersize)
{
    // Move a database cursor to the next (requested) row.
    int rc;
    if (firstFetch) {
        firstFetch = false;
        rc = SQLITE_ROW;
    } else
        rc = sqlite3_step(pStmt);

    switch (rc) {
        case SQLITE_BUSY:
            strncpy(lastError, "CSQLite::Fetch: The database file is locked!", lastErrorSize);
            finalizeStatement();
            return NULL;

        case SQLITE_ERROR:
            strncpy(lastError, sqlite3_errmsg(sdb), lastErrorSize);
            finalizeStatement();
            return NULL;

        case SQLITE_MISUSE:
            strncpy(lastError, "CSQLite::Fetch: Library used incorrectly.", lastErrorSize);
            finalizeStatement();
            return NULL;

        case SQLITE_ROW:
            break;

        default:
            finalizeStatement();
            return NULL;
    };

    // Calculate length of the row.
    int NumCol = sqlite3_column_count(pStmt);
    unsigned long row_length = 0;
    for (int i = 0; i < NumCol; ++i) {
        const char * column = (const char *)sqlite3_column_text(pStmt, i);
        if (column) {
            // We will need one more character per a column to act as a column separator and a NULL terminating
            // character.
            row_length += strlen(column) + 1;
        }
    }
    if (row_length == 0)
        return NULL;

    // If the row length exceeds size of the SPACER buffer, allocate a new one.
    // The SPACER will be deleted automatically in nwnx2lib.cpp.
    char * result = row_length <= buffersize ? buffer : (char *)malloc(row_length);

    // Copy content of the columns to the buffer.
    for (int i = 0, pos = 0; i < NumCol; ++i) {
        const char * column = (const char *)sqlite3_column_text(pStmt, i);
        if (column) {
            int length = strlen(column);
            strncpy(&result[pos], column, length);
            pos += length;
            result[pos++] = '¬';
        }
    }
    result[row_length - 1] = '\0';

    return result;
}

BOOL CSQLite::WriteScorcoData(char* SQL, BYTE* pData, int Length)
{
    int rc;
    char* pSQL = (char*) malloc(strlen(SQL) + 1);
    sprintf(pSQL, SQL, "?");

    finalizeStatement();
    rc = sqlite3_prepare(sdb, pSQL, -1, &pStmt, NULL);
    free(pSQL);

    if (rc != SQLITE_OK) {
        strcpy(lastError, sqlite3_errmsg(sdb));
        finalizeStatement();
        return false;
    }

    rc = sqlite3_bind_blob(pStmt, 1, (const void*) pData, Length, SQLITE_STATIC);
    rc = sqlite3_step(pStmt);
    finalizeStatement();

    if (rc != SQLITE_DONE) {
        strcpy(lastError, sqlite3_errmsg(sdb));
        return false;
    }

    return true;
}

BYTE * CSQLite::ReadScorcoData(const char * SQL, const char * param, BOOL * pSqlError, int * size)
{
    int rc;
    const void* pBlob;

    if (strcmp(param, "FETCHMODE") != 0) {
        finalizeStatement();
        rc = sqlite3_prepare(sdb, SQL, -1, &pStmt, NULL);
        if (rc != SQLITE_OK) {
            strcpy(lastError, sqlite3_errmsg(sdb));
            finalizeStatement();
            *pSqlError = true;
            return NULL;
        }
    }

    // execute step
    rc = sqlite3_step(pStmt);
    if (rc == SQLITE_ERROR) {
        strcpy(lastError, sqlite3_errmsg(sdb));
        *pSqlError = true;
        finalizeStatement();
        return NULL;
    }

    *pSqlError = false;
    if (rc == SQLITE_ROW) {
        unsigned long length = sqlite3_column_bytes(pStmt, 0);
        *size = length;
        if (length == 0) return NULL;
        char* buf = new char[length];
        if (buf == NULL) return NULL;
        pBlob = sqlite3_column_blob(pStmt, 0);
        if (pBlob == NULL) { delete [] buf; return NULL; }
        memcpy(buf, pBlob, length);
        return (BYTE*)buf; // NWN VM will delete this block of memory
    } else if (rc == SQLITE_DONE) {
        finalizeStatement();
    }
    return NULL;
}

void CSQLite::finalizeStatement()
{
    if (pStmt) {
        sqlite3_finalize(pStmt);
        pStmt = NULL;
    }
}

const char* CSQLite::GetErrorMessage()
{
    // return the error message
    return lastError;
}
