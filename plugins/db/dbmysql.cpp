/***************************************************************************
    NWNX FOR LINUX DB CLASSES 
    Original idea by: Ingmar Stieger (Papillon) papillon@blackdagger.com
    Copyright (C) 2003 Mirko Bernardoni (Firedeath)
    email: firedeath@ghostnight.net

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
#include "dbmysql.h"

DbMySql::DbMySql (ConnParam *p)
{
    error = false;
	connValid = ERR_NOTCONNECTED;	
	debugLevel=DBG_NO;
	stream=stderr;
        result=NULL;
	SetConnParams(p);
}

DbMySql::~DbMySql ()
{
    mysql_close (&mysql);
}

bool DbMySql::SqlConn (ConnParam * p)
{
    error = false;
	connValid = ERR_NOTCONNECTED;	

	SetConnParams(p);

	if( connParams.user==NULL && 
		connParams.pass==NULL &&
		connParams.server==NULL &&
		connParams.db==NULL)
	{
		error = true;
		errorString = "No credentials supplied";
		fprintf(stream,"o ERROR: %s\n", errorString);
		return false;
	}

    if (mysql_init (&mysql) == NULL)
    {
		error = true;
		errorString = "Unable to connect to Mysql";
		fprintf(stream,"o ERROR: %s\n", errorString);
		return false;
    }				/* if */

    if ((mysql_real_connect(&mysql, 
							connParams.server, 
							connParams.user, 
							connParams.pass, 
							connParams.db, 
							0, NULL, 0)) == NULL)
    {
		error = true;
		errorString = (char *)mysql_error (&mysql);
		mysql_close (&mysql);
		fprintf(stream,"o ERROR: %s\n", errorString);
		return false;
    }				/* if */
	connValid = ERR_NOTQUERY;	
    return true;
}

void
DbMySql::SqlDisconn ()
{
    error = false;
	connValid = ERR_NOTCONNECTED;
    mysql_close (&mysql);
}

unsigned int
DbMySql::SqlExec (unsigned char *cmdstr, char *buffer,
		  unsigned int buffersize)
{
    unsigned int totalbytes = 0;
    unsigned long NumCol, i, total, byte;
    unsigned long *lengths;
    MYSQL_ROW row;
    
	if(connValid == ERR_NOTCONNECTED)
	{
		errorString = "DB not connected";
		fprintf(stream,"o ERROR: %s\n", errorString);
		error = true;
		return 0;
	} /* if */

	// make sure it's up.  If not attempt a reconnect
	if( mysql_ping(&mysql)!=0 ) 
	{
		errorString = "DB went away";
		fprintf(stream,"o ERROR: %s\n", errorString);
		error = true;
		// connValid == ERR_NOTCONNECTED;
		return 0;
	}

	if(debugLevel==DBG_YES)
		fprintf(stream,"o Got request: %s\n", cmdstr);
	error = false;
    buffer[0] = '\0';		// same as strcpy but more efficently
	connValid = ERR_NOTQUERY;
    if (mysql_query (&mysql, (const char *) cmdstr) != 0)
    {
		error = true;
		errorString = (char *)mysql_error (&mysql);
		fprintf(stream,"o ERROR: [1] %s\n", errorString);
		if (strlen (errorString) < buffersize)
		    strcpy (buffer, errorString);
		else
		    strncpy (buffer, errorString, buffersize);
		return 0;
    }				/* if */

    result = mysql_store_result (&mysql);

    if (result)			// there are rows
		// retrieve rows, then call mysql_free_result(result)
		NumCol = mysql_num_fields (result);
    else			// mysql_store_result() returned nothing; should it have?
    {
		if (mysql_field_count (&mysql) == 0)
		{
		    // query does not return data
	    	// (it was not a SELECT)
			if(debugLevel==DBG_YES)
				fprintf(stream, "o Empty set\n");
		    return 0;
		}			/* if */
		else			// mysql_store_result() should have returned data
		{
	    	error = true;
		    errorString = (char *)mysql_error (&mysql);
		    if (strlen (errorString) < buffersize)
				strcpy (buffer, errorString);
		    else
				strncpy (buffer, errorString, buffersize);
			fprintf(stream,"o ERROR: [2] %s\n", errorString);
	    	return 0;
		}			/* else */
    }				/* else */

    while ((row = mysql_fetch_row (result)))
    {
		lengths = mysql_fetch_lengths (result);
		for (i = 0; i < NumCol; i++)
		{
	    	//performace issue
		    byte = lengths[i];
		    total = byte + totalbytes;
	    	if ((byte > 0) && (total <= buffersize))	//if there is data and there is memory for data    
	    	{
				strcat (buffer, row[i]);
				totalbytes = total;
		    }			/* if */

		    if ((i != NumCol) && (totalbytes + 1 <= buffersize))	// last column
	    	{
			totalbytes++;
			strcat (buffer, "¬");	// ascii 170
	    	}			/* if */
		}			/* for */

    }				/* while */
	if(debugLevel==DBG_YES)
		fprintf(stream, "o Sent response (%d bytes): %s\n", totalbytes, buffer);
	
    buffer[totalbytes] = '\0';	//remove the last ¬
    if (totalbytes > 0)
		totalbytes--;

    return (unsigned int) totalbytes;
}

unsigned int
DbMySql::SqlFetch (char *buffer, unsigned int buffersize)
{
    unsigned int totalbytes = 0;
    unsigned long *lengths;
    unsigned long i, total, byte;
    MYSQL_ROW row;
	
	// MUST be set before any errors are returned
	// APS depends on a zero length buffer to indicate an error
    buffer[0] = '\0';

	if(connValid != ERR_OK) {
		errorString = "Connection not valid";
		// fprintf(stream,"o ERROR: %s\n", errorString);
		error = true;
	}

	if(error || connValid != ERR_OK) {
		return 0;
	} /* if */

	// walk through the resultset
    row = mysql_fetch_row (result);
    if (row)
    {
		lengths = mysql_fetch_lengths (result);
		// add each column to buffer
		for (i = 0; i < NumCol; i++)
		{
		    //performace issue
		    byte = lengths[i];
		    total = byte + totalbytes;
		    if ((byte > 0) && (total <= buffersize))	//if there is data and there is memory for data    
		    {
				strcat (buffer, row[i]);
				totalbytes = total;
	    	}			/* if */

		    if ((i != NumCol - 1) && (totalbytes + 1 <= buffersize))	// last column
		    {
				totalbytes++;
				strcat (buffer, "¬");	// ascii 170
	    	}			/* if */
		}			/* for */
    }				/* if */
	if(debugLevel==DBG_YES)
		{
		if(totalbytes>0)
			fprintf(stream, "o Sent response (%d bytes): %s\n", totalbytes, buffer);
		else
			fprintf(stream, "o Empty set\n");
		}/* if */
    error = false;
    return (unsigned int) totalbytes;
}

void
DbMySql::SqlExec (char *buffer, unsigned int buffersize)
{
	if(connValid == ERR_NOTCONNECTED)
	{
		errorString = "DB not connected";
		fprintf(stream,"o ERROR: %s\n", errorString);
		error = true;
		return ;
	} /* if */

	// make sure it's up.  If not attempt a reconnect
	if( mysql_ping(&mysql)!=0 ) 
	{
		errorString = "DB went away";
		fprintf(stream,"o ERROR: %s\n", errorString);
		error = true;
		// connValid == ERR_NOTCONNECTED;
		return;
	}

	connValid= ERR_NOTQUERY;
    if (mysql_real_query (&mysql, (const char *) buffer, strlen(buffer)) != 0)
    {
		error = true;
		// connValid = false;
		errorString = (char *)mysql_error (&mysql);
		fprintf(stream,"o ERROR: [3] %s\n", errorString);
		if (strlen (errorString) < buffersize)
		    strcpy (buffer, errorString);
		else
	    	strncpy (buffer, errorString, buffersize);
		return;
    }				/* if */

    result = mysql_store_result (&mysql);

    if (!result)		// mysql_store_result() returned nothing; should it have?
    {
		if (mysql_field_count (&mysql) == 0)
		{
		    // query does not return data
		    // (it was not a SELECT)
			if(debugLevel==DBG_YES)
				fprintf(stream, "o Empty set\n");
		    return;
		}			/* if */
		else			// mysql_store_result() should have returned data
		{
		    error = true;
	    	errorString = (char *)mysql_error (&mysql);
			fprintf(stream,"o ERROR: [4] %s\n", errorString);
		    if (strlen (errorString) < buffersize)
				strcpy (buffer, errorString);
		    else
				strncpy (buffer, errorString, buffersize);
		    return;
		}			/* else */
    }				/* if */

    NumCol = mysql_num_fields (result);

    error = false;
	connValid = ERR_OK;
    buffer[0] = '\0';
}

bool DbMySql::ProcessRequest (char *request, unsigned int responseSize)
{
	// if not connected try to reconnect
	if(connValid == ERR_NOTCONNECTED && !SqlConn()) {
		// SqlConn() will set the errorString for us
		return false;
	}

	// free the last results set
	if( result != NULL ) {
		mysql_free_result(result);
		result = NULL;
	}

    if(debugLevel==DBG_YES)
        fprintf(stream,"o Got request: %s\n", request);
    SqlExec (request, responseSize - 1);
	// if(error) printf("Error: %s\n", errorString);
    return !error;
}

