#ifndef NWNX_COREEVENTS_H
#define NWNX_COREEVENTS_H

#include "NWNXBase.h"

class CNWNXCoreEvents: public CNWNXBase
{
public:
	CNWNXCoreEvents();
	virtual ~ CNWNXCoreEvents();

	bool OnCreate(gline *nwnxConfig, const char *LogDir = NULL);
	char *OnRequest(char *gameObject, char *Request, char *Parameters);

private:

};

#endif /* NWNX_COREEVENTS_H */

/* vim: set sw=4: */
