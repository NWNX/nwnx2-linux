#pragma once

#include <stdio.h>

class NWNXBase  
{
public:
	NWNXBase();
	virtual ~NWNXBase();
	virtual bool OnCreate (const char* LogFile = NULL);
	virtual char* OnRequest (char *gameObject, char* Request, char* Parameters) = 0;
	virtual bool OnRelease ();
	void Log (const char* Msg, ...);
	void WriteLogHeader();

	FILE* m_fFile;
	char* m_LogFile;
	long m_maxLogSizeKB;

protected:
	char acBuffer[65535];

};

