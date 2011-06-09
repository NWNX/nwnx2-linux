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

//#include <assert.h>
#include "sqlite.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

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

BOOL CSQLite::Connect(char *db)
{
	int rc;
	rc = sqlite3_open(db, &sdb);
	if (rc)
	{
	    sprintf(lastError, "Can't open database: %s", sqlite3_errmsg(sdb));
	    sqlite3_close(sdb);
		return false;
	}

	// begin implicit transaction
	rc = sqlite3_prepare(sdb, "BEGIN", -1, &pStmt, NULL);
	if (rc != SQLITE_OK)
		strcpy(lastError, sqlite3_errmsg(sdb));
	else
	{
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
	else
	{
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
	if (rc != SQLITE_OK)
	{
		strcpy(lastError, sqlite3_errmsg(sdb));
		finalizeStatement();
		return false;
	}
	// execute step
	rc = sqlite3_step(pStmt);
	switch(rc)
	{
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

uint CSQLite::Fetch(char* buffer, uint size)
{
	int rc;
	unsigned int total, len, i, maxCol, totalbytes;
	const char* pCol;

	if (firstFetch)
	{
		firstFetch = false;
		rc = SQLITE_ROW;
	}
	else
	{
		// execute step
		rc = sqlite3_step(pStmt);
		if (rc == SQLITE_ERROR)
		{
			strcpy(lastError, sqlite3_errmsg(sdb));
			finalizeStatement();
			return (uint)-1;
		}
	}
	if (rc == SQLITE_ROW)
	{
		totalbytes = 0;
		maxCol = sqlite3_column_count(pStmt);
		for (i = 0; i < maxCol; i++)
		{
			pCol = (const char*) sqlite3_column_text(pStmt, i);
			if (pCol)
			{
				len = strlen(pCol);
				total = totalbytes + len;
				if ((total < size) && (len > 0))
				{
					memcpy (&buffer[totalbytes], pCol, len);
					totalbytes = total;					
				}
			}
			if ((i < maxCol - 1) && (totalbytes + 1 < size))
			{
				buffer[totalbytes] = '¬'; // ascii 170
				totalbytes++;
			}
		}

		buffer[totalbytes] = 0;
		return totalbytes;
	}
	else 
	{
		finalizeStatement();
	}

	return 0;
}

BOOL CSQLite::WriteScorcoData(char* SQL, BYTE* pData, int Length)
{
	int rc;
	char* pSQL = (char*) malloc(strlen(SQL)+1);
	sprintf(pSQL, SQL, "?");

	finalizeStatement();
	rc = sqlite3_prepare(sdb, pSQL, -1, &pStmt, NULL);
	free(pSQL);

	if (rc != SQLITE_OK)
	{
		strcpy(lastError, sqlite3_errmsg(sdb));
		finalizeStatement();
		return false;
	}

	rc = sqlite3_bind_blob(pStmt, 1, (const void*) pData, Length, SQLITE_STATIC);
	rc = sqlite3_step(pStmt);   
	finalizeStatement();

	if (rc != SQLITE_DONE)
	{
		strcpy(lastError, sqlite3_errmsg(sdb));
		return false;
	}

	return true;
}

BYTE* CSQLite::ReadScorcoData(char* SQL, char *param, BOOL* pSqlError, int *size)
{
	int rc;
	const void* pBlob;

	if (strcmp(param, "FETCHMODE") != 0)
	{	
		finalizeStatement();
		rc = sqlite3_prepare(sdb, SQL, -1, &pStmt, NULL);
		if (rc != SQLITE_OK)
		{
			strcpy(lastError, sqlite3_errmsg(sdb));
			finalizeStatement();
			*pSqlError = true;
			return NULL;
		}
	}

	// execute step
	rc = sqlite3_step(pStmt);
	if (rc == SQLITE_ERROR)
	{
		strcpy(lastError, sqlite3_errmsg(sdb));
		*pSqlError = true;
		finalizeStatement();
		return NULL;
	}

	*pSqlError = false;
	if (rc == SQLITE_ROW)
	{
		*size = sqlite3_column_bytes(pStmt, 0);
		if (*size > MAXRESULT)
		{
			sprintf(lastError, "Critical error - object too large (>%ld bytes).\n", MAXRESULT);
			*pSqlError = true;
			return NULL;
		}
		pBlob = sqlite3_column_blob(pStmt, 0);
		memcpy(pReturn, pBlob, *size);
		return pReturn;	
	}
	else if (rc == SQLITE_DONE)
	{
		finalizeStatement();
	}
	return NULL;
}

void CSQLite::finalizeStatement()
{
	if (pStmt)
	{
		sqlite3_finalize(pStmt);
		pStmt = NULL;
	}
}

const char* CSQLite::GetErrorMessage()
{
	// return the error message
	return lastError;
}
