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


BOOL CPgSQL::Connect ()
{
	// try to establish a default connection
	return Connect ("localhost", "nwn", "nwnpwd", "nwn");
}


BOOL CPgSQL::Connect (const char *server, const char *user, const char *pass, const char *db)
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
	sprintf(connstring, HOST"%s "PORT"%hu "DB"%s "USR"%s "PW"%s", server, PORT_NUM, db, user, pass);

	// Connect attempt
	pgsql = PQconnectdb(connstring);
	if (PQstatus(pgsql) != CONNECTION_OK)
	{
		free(connstring);
		return false;
	}

	free(connstring);

	return true;
}

void CPgSQL::Disconnect ()
{
	// close the connection
	PQfinish(pgsql);
}

BOOL CPgSQL::Execute (const uchar* query)
{
	if (PQstatus(pgsql) != CONNECTION_OK)
		return false;

	// release a previous result set
	if (result != NULL) {
		PQclear (result);
		result = NULL;
	}

	// execute the query
	result = PQexec (pgsql, (const char *) query);
	if (result == NULL || PQresultStatus(result) == PGRES_FATAL_ERROR)
	{
		return false;
	}

	// successfull retreived the results from the SELECT
	NumCol = PQnfields (result);
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
	for (unsigned int i = 0; i < NumCol; ++i)
	{
		// We will need one more character per a column to act as a column separator and a NULL terminating character.
		row_length += PQgetlength(result, CurRow, i) + 1;
	}
	if (row_length == 0)
		return NULL;

	// If the row length exceeds size of the SPACER buffer, allocate a new one.
	// The SPACER will be deleted automatically in nwnx2lib.cpp.
	char * result = row_length <= buffersize ? buffer : (char *)malloc(row_length);

	for (unsigned int i = 0, pos = 0; i < NumCol; ++i)
	{
		int length = PQgetlength(this->result, CurRow, i);
		strncpy(&result[pos], PQgetvalue(this->result, CurRow, i), length);
		pos += length;
		result[pos++] = '¬';
	}
	result[row_length-1] = '\0';

	CurRow++;

	return result;
}

BOOL CPgSQL::WriteScorcoData(char* SQL, BYTE* pData, int Length)
{
	int res;
	PGresult *sco_result;
	unsigned int len;
	char* Data = NULL;
	unsigned char *Data2 = NULL;
	char* pSQL = NULL;

	//len = mysql_real_escape_string (&mysql, Data + 1, (const char*)pData, Length);
	Data2 = PQescapeByteaConn(pgsql, pData, Length, &len);

	Data = new char[len + 4];
	pSQL = new char[MAXSQL + len + 3];

	memcpy(Data + 2, Data2, len);
	Data[0] = 'E';
	Data[1] = Data[len+1] = 39; //'
	Data[len + 2] = 0x0;
	sprintf(pSQL, SQL, Data);

	sco_result = PQexec (pgsql, pSQL);

	if (sco_result == NULL || PQresultStatus(sco_result) == PGRES_FATAL_ERROR)
		res = 1;
	else
		res = 0;

	PQclear (sco_result);

	delete[] pSQL;
	delete[] Data;
	PQfreemem(Data2);

	if (res == 0)
		return true;
	else
		return false;
}

BYTE * CPgSQL::ReadScorcoData(const char * SQL, const char * param, BOOL * pSqlError, int * size)
{
	PGresult *rcoresult;
	if (strcmp(param, "FETCHMODE") != 0)
	{
		rcoresult = PQexec (pgsql, SQL);
		if (rcoresult == NULL || PQresultStatus(rcoresult) == PGRES_FATAL_ERROR)
		{
			PQclear (rcoresult);
			*pSqlError = true;
			return NULL;
		}
	}
	else rcoresult=result;

	*pSqlError = false;

	if(PQntuples(rcoresult) > 0)
	{
		unsigned char *buf = PQunescapeBytea((unsigned char *) PQgetvalue(rcoresult, 0, 0), (size_t *) size);
		if(!buf) return NULL;

		PQclear (rcoresult);
		return (BYTE *)buf;
	}
	else
	{
		PQclear (rcoresult);
		return NULL;
	}
	return NULL;
}

const char* CPgSQL::GetErrorMessage ()
{
	// return the error message
	return PQerrorMessage(pgsql);
}
