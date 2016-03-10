#include "stdafx.h"
#include "NWNXBase.h"
#include <stdarg.h>
#include <typeinfo.h>

NWNXBase::NWNXBase()
{
	m_fFile = NULL;
	m_maxLogSizeKB = 1024 * 1024;
}

NWNXBase::~NWNXBase()
{
	// The OnRelease function is always called before
	// an instance is deleted
	OnRelease ();
}

bool NWNXBase::OnCreate(const char* LogFile)
{
	// try to open the log file
	m_LogFile = strdup(LogFile);
	m_fFile = fopen (LogFile, "w");
	return (m_fFile != NULL);
}

bool NWNXBase::OnRelease()
{
	// close the log file
	int ret;
	if (m_fFile)
		ret = fclose (m_fFile);
	return (ret == 0);
}

void NWNXBase::Log(const char *pcMsg, ...)
{
	va_list argList;
	char *pos;

	if (m_fFile)
	{  
		if (ftell(m_fFile) > m_maxLogSizeKB)
		{	
			fclose(m_fFile);
			m_fFile = fopen (m_LogFile, "w");
			WriteLogHeader();
			fprintf(m_fFile, "o Logfile hit maximum size limit, starting again.\n");
		}

		// build up the string
		va_start(argList, pcMsg);
		vsprintf(acBuffer, pcMsg, argList);
		va_end(argList);

		// replace any percent signs
		pos = strchr(acBuffer, '%');
		while (pos)
		{
			*pos = '~';
			pos = strchr(acBuffer, '%');
		}

		// log string in file
		fprintf (m_fFile, acBuffer);
		fflush (m_fFile);
	}
}

void NWNXBase::WriteLogHeader()
{
	fprintf(m_fFile, "NWNX base plugin\n");
}