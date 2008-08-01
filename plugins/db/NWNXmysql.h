#ifndef NWNXmysql_h_
#define NWNXmysql_h_

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h> /* memset() */
#include <sys/time.h> /* select() */ 
#include <errno.h>
#include <signal.h>

#include "data.h"
#include "dbmysql.h"

#include "NWNXBase.h"

class CNWNXmysql : public CNWNXBase
{
public:
	CNWNXmysql();
	~CNWNXmysql();

	bool OnCreate(gline *nwnxConfig, const char *LogDir=NULL);
	char *OnRequest(char* gameObject, char* Request, char* Parameters);
	bool OnRelease();

protected:
	bool ClientClose(const char *conn);
	bool ClientInit(const char *conn,const char *dest);

private:
	Data *db;
	// dbdict Connections;
	char mysql_buf[2048];
};

#endif
