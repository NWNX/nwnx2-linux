#ifndef _CNETWORKPROFILER_H_
#define _CNETWORKPROFILER_H_
#include "nwndef.h"

class CNetworkProfiler
{
public:
	int AddMessageToFrameProfile(unsigned char, unsigned long);
	int AddMessageToProfile(unsigned char, unsigned char, unsigned char, unsigned long);
	int GetFrameLastTime();
	int GetFrameStartTime();
	int GetLastTime();
	int GetStartTime();
	int OutputReport();
	int SetOutputFilename(char *);
	int SetState(int);
	~CNetworkProfiler();
	CNetworkProfiler();

};
#endif
