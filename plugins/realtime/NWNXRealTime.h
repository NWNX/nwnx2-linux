#pragma once

#include "NWNXBase.h"

#pragma warning(disable:4786)
#include "wx/datetime.h"
#include "wx/string.h"
#include "wx/tokenzr.h"

class NWNXRealTime : public NWNXBase  
{
public:
	NWNXRealTime();
	virtual ~NWNXRealTime();
	char* OnRequest(char *gameObject, char* Request, char* Parameters);
	bool OnCreate(const char* LogDir);
	bool OnRelease();
	void WriteLogHeader();

private:
	wxDateTime loadtime;
};