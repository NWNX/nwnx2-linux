/***************************************************************************
    NWNX FOR LINUX DB Plugin Wrapper CLASS
    Copyright (C) 2003 John Klar (paladin at projectplasma dot com)

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

#include "NWNXmysql.h"

CNWNXmysql::CNWNXmysql() {
	confKey = "Database";
}

CNWNXmysql::~CNWNXmysql() {
}

bool CNWNXmysql::ClientClose(const char *cname) {
	db->SqlDisconn();
	return true;
}

bool CNWNXmysql::ClientInit(const char *cname, const char *dest) {
  
	int rc, len;
	ConnParam dbParam;

	if(nwnxConfig->exists(confKey)) {
		dbParam.server = (char*)((*nwnxConfig)[confKey]["server"].c_str());
		dbParam.user   = (char*)((*nwnxConfig)[confKey]["user"].c_str());
		dbParam.pass   = (char*)((*nwnxConfig)[confKey]["pass"].c_str());
		dbParam.db     = (char*)((*nwnxConfig)[confKey]["db"].c_str());

		if((db = new DbMySql(&dbParam))==NULL) {
			Log(0,"[%s] failed to create DbMySql() object.\n",cname);
			return false;
		}

		if(db->SqlConn()==false) {
			Log(0,"[%s] unable to setup connection to database: %s.\n",
				cname, db->ErrorMsg());
			return true;
		}

		if(debuglevel>0) {
			// error log
			db->setDebug(DBG_YES,m_fFile);
		}

		Log(0,"[%s] Database connection up.\n",cname);
	}

	return true;
}

bool CNWNXmysql::OnCreate(gline *config, const char *LogDir)
{
	// call the base class function
	char log[128];
	sprintf (log, "%s/nwnx_odbc.txt", LogDir);

	if(!CNWNXBase::OnCreate(config,log))
		return false;

	if(!ClientInit("CTEST","home"))
		return false;

	return true;
}

char *CNWNXmysql::OnRequest(char *gameObject, char *Request, char *Parameters) {
	int len;
	char cmd[32], cname[32], *pos, *bang, *bang2;

	Log(2,"Request: %s\n",Request);
	Log(3,"Params : %s\n",Parameters);

	if(strncasecmp(Request,"EXEC_AND_FETCH",14)==0) {
		// Store the *total* buffer length just in case
		// ProcessRequest modifies Parameters
		len = strlen(Parameters);

		pos= strchr(Parameters, '¬');	// ascii 170
		if(pos!=NULL) *pos= 0;  // end of query, the rest is return buffer

		// SqlFetch is set up to do error processing
		// so fall thru in either case
		db->ProcessRequest(Parameters,len);
		db->SqlFetch(Parameters,len);
	} else
	if(strncasecmp(Request,"EXEC",4)==0) {
		db->ProcessRequest(Parameters,strlen(Parameters));
	} else
	if(strncasecmp(Request,"FETCH",5)==0) {
		db->SqlFetch(Parameters,strlen(Parameters));
	}

	Log(4,"Results: %s\n",Parameters);

	return NULL;
}

bool CNWNXmysql::OnRelease()
{
	if(!CNWNXBase::OnRelease())
		return false;

	if(!ClientClose("CTEST"))
		return false;

	return true;
}

