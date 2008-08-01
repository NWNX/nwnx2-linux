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

#ifndef __DATA_H__
#define __DATA_H__
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* Type of DB Error */
#define ERR_NOTCONNECTED 10
#define ERR_NOTQUERY 20
#define ERR_OK 30
/* Type of debug */
#define DBG_NO 0
#define DBG_YES 1

typedef struct ConnParam
{
    char *user;
    char *pass;
    char *server;
    char *db;
}

ConnParam;

class Data
{
  public:
    Data ();			// Constructor
    virtual bool SqlConn (ConnParam * p = NULL) = 0;	// Allocate env, stat, and conn
    virtual unsigned int SqlExec (unsigned char *cmdstr, char *buffer, unsigned int buffersize) = 0;	// Execute SQL statement
    virtual void SqlDisconn () = 0;	// Free pointers to env, stat, conn, and disconnect
    virtual unsigned int SqlFetch (char *buffer, unsigned int buffersize) = 0;	// Fetch One single row in table
    virtual bool ProcessRequest (char *request, unsigned int responseSize) = 0;	//Initializze the db request
    char *ErrorMsg ();		// Return pointer to error message
    bool IsValidSQLStatement (unsigned char *);	//Validate the SQL code
    bool ErrorState ();		// Return TRUE if error occured
 	short getDbState();		// Return the state of DB
    short getDebug();		// Return the level of debug
    void setDebug(short dbg, FILE *fp); // Set the level of debug and output
  protected:
    bool error; // There is error
    char *errorString; // Error message
    short connValid; // For check the status of DB
    short debugLevel; // Level of debugging
    FILE *stream; // stream used for debug

	ConnParam connParams;

	void SetConnParams(ConnParam *p);
    virtual void SqlExec (char *buffer, unsigned int buffersize) = 0;	// Called by ProcessRequest
};

#endif
