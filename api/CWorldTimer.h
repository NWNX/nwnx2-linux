#ifndef _CWORLDTIMER_H_
#define _CWORLDTIMER_H_
#include "nwndef.h"

class CWorldTimer
{
public:
	int AddWorldTimes(unsigned long, unsigned long, unsigned long, unsigned long, unsigned long *, unsigned long *);
	int AdvanceToTime(int, int, int, int);
	int CompareWorldTimes(unsigned long, unsigned long, unsigned long, unsigned long);
	int ConvertFromCalendarDay(unsigned long, unsigned long *, unsigned long *, unsigned long *);
	int ConvertFromTimeOfDay(unsigned long, unsigned long *, unsigned long *, unsigned long *, unsigned long *);
	int ConvertToCalendarDay(unsigned long, unsigned long, unsigned long);
	int ConvertToTimeOfDay(unsigned long, unsigned long, unsigned long, unsigned long);
	int GetCalendarDayFromSeconds(float);
	int GetSnapshotTimeDifference();
	int GetSnapshotTime();
	int GetTimeDifferenceFromWorldTime(unsigned long, unsigned long);
	int GetTimeOfDayFromSeconds(float);
	int GetWorldTimeCalendarDayString();
	int GetWorldTimeCalendarDay();
	int GetWorldTimeDay();
	int GetWorldTimeHour();
	int GetWorldTimeMillisecond();
	int GetWorldTimeMinute();
	int GetWorldTimeMonth();
	int GetWorldTimeSecond();
	int GetWorldTimeTimeOfDayString();
	int GetWorldTimeTimeOfDay();
	int GetWorldTimeYear();
	int GetWorldTime(unsigned long *, unsigned long *);
	int PauseWorldTimer();
	int ResetTimer(CWorldTimer *);
	int SetFixedSnapshotRate(int, int);
	int SetMinutesPerHour(unsigned char);
	int SetSnapshotTime();
	int SetWorldTime(unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, int);
	int SetWorldTime(unsigned long, unsigned long, int);
	int SubtractWorldTimes(unsigned long, unsigned long, unsigned long, unsigned long, unsigned long *, unsigned long *);
	int TranslateWorldTimeToString(unsigned long, unsigned long, CExoString &, CExoString &);
	int UnpauseWorldTimer();
	~CWorldTimer();
	CWorldTimer();

};
#endif
