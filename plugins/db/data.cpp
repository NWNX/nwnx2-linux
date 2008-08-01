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

#include "data.h"

Data::Data ()
{
    error = false;
	debugLevel=DBG_NO;
	stream=stderr;

	connParams.user = NULL;
	connParams.pass = NULL;
	connParams.server = NULL;
	connParams.db = NULL;
}

void
Data::SetConnParams(ConnParam *p) {

	if(p!=NULL) {
		if(connParams.user!=NULL) free(connParams.user);
		connParams.user   = (p->user!=NULL)?strdup(p->user):NULL;

		if(connParams.pass!=NULL) free(connParams.pass);
		connParams.pass   = (p->pass!=NULL)?strdup(p->pass):NULL;

		if(connParams.server!=NULL) free(connParams.server);
		connParams.server = (p->server!=NULL)?strdup(p->server):NULL;

		if(connParams.db!=NULL) free(connParams.db);
		connParams.db     = (p->db!=NULL)?strdup(p->db):NULL;
	}
}

char *
Data::ErrorMsg ()
{
    if (error == true)
		return errorString;
    else
		return (char *) "";
}

bool Data::ErrorState ()
{
    return error;
}

short Data::getDbState ()
{
	return connValid;
}

short Data::getDebug()
{
	return debugLevel;
}

void Data::setDebug(short dbg, FILE *fp)
{
	debugLevel=dbg;
	stream=fp;
}

bool Data::IsValidSQLStatement (unsigned char *statement)
{
    if (strncasecmp ((const char *) statement, "SELECT", 6) == 0)
	return true;
    if (strncasecmp ((const char *) statement, "INSERT", 6) == 0)
	return true;
    if (strncasecmp ((const char *) statement, "UPDATE", 6) == 0)
	return true;
    if (strncasecmp ((const char *) statement, "DELETE", 6) == 0)
	return true;
    if (strncasecmp ((const char *) statement, "KILL", 4) == 0)
	return true;
    if (strncasecmp ((const char *) statement, "RESET", 5) == 0)
	return true;
    if (strncasecmp ((const char *) statement, "CREATE", 6) == 0)
	return true;
    if (strncasecmp ((const char *) statement, "RENAME", 6) == 0)
	return true;
    if (strncasecmp ((const char *) statement, "TRUNCATE", 8) == 0)
	return true;
    if (strncasecmp ((const char *) statement, "REPLACE", 7) == 0)
	return true;
    if (strncasecmp ((const char *) statement, "LOAD", 4) == 0)
	return true;
    if (strncasecmp ((const char *) statement, "BEGIN", 5) == 0)
	return true;
    if (strncasecmp ((const char *) statement, "COMMIT", 6) == 0)
	return true;
    if (strncasecmp ((const char *) statement, "ROLLBACK", 8) == 0)
	return true;
    if (strncasecmp ((const char *) statement, "LOCK", 4) == 0)
	return true;
    if (strncasecmp ((const char *) statement, "UNLOCK", 6) == 0)
	return true;
    if (strncasecmp ((const char *) statement, "SHOW", 4) == 0)
	return true;
    if (strncasecmp ((const char *) statement, "ANALYZE", 7) == 0)
	return true;
    if (strncasecmp ((const char *) statement, "ALTER", 5) == 0)
	return true;
    if (strncasecmp ((const char *) statement, "GRANT", 5) == 0)
	return true;
    if (strncasecmp ((const char *) statement, "DROP", 4) == 0)
	return true;
    if (strncasecmp ((const char *) statement, "USE", 3) == 0)
	return true;
    if (strncasecmp ((const char *) statement, "SET", 3) == 0)
	return true;

    return false;

}
