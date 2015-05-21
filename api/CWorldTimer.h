#ifndef _CWORLDTIMER_H_
#define _CWORLDTIMER_H_
#include "nwndef.h"

class CWorldTimer
{
public:
    unsigned long AddWorldTimes(unsigned long, unsigned long, unsigned long, unsigned long, unsigned long *, unsigned long *);
    void AdvanceToTime(int, int, int, int);
    int CompareWorldTimes(unsigned long, unsigned long, unsigned long, unsigned long);
    void ConvertFromCalendarDay(unsigned long, unsigned long *, unsigned long *, unsigned long *);
    void ConvertFromTimeOfDay(unsigned long, unsigned long *, unsigned long *, unsigned long *, unsigned long *);
    unsigned long ConvertToCalendarDay(unsigned long, unsigned long, unsigned long);
    int ConvertToTimeOfDay(unsigned long, unsigned long, unsigned long, unsigned long);
    unsigned long GetCalendarDayFromSeconds(float);
    unsigned __int64 GetSnapshotTimeDifference();
    unsigned __int64 GetSnapshotTime();
    int GetTimeDifferenceFromWorldTime(unsigned long, unsigned long);
    unsigned long GetTimeOfDayFromSeconds(float);
    int GetWorldTimeCalendarDayString();
    int GetWorldTimeCalendarDay();
    unsigned long GetWorldTimeDay();
    unsigned long GetWorldTimeHour();
    unsigned long GetWorldTimeMillisecond();
    unsigned long GetWorldTimeMinute();
    unsigned long GetWorldTimeMonth();
    unsigned long GetWorldTimeSecond();
    int GetWorldTimeTimeOfDayString();
    int GetWorldTimeTimeOfDay();
    unsigned long GetWorldTimeYear();
    void GetWorldTime(unsigned long *, unsigned long *);
    void PauseWorldTimer();
    void ResetTimer(CWorldTimer *);
    int SetFixedSnapshotRate(int, int);
    void SetMinutesPerHour(unsigned char);
    void SetSnapshotTime();
    void SetWorldTime(unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, int);
    void SetWorldTime(unsigned long, unsigned long, int);
    unsigned long SubtractWorldTimes(unsigned long, unsigned long, unsigned long, unsigned long, unsigned long *, unsigned long *);
    int TranslateWorldTimeToString(unsigned long, unsigned long, CExoString &, CExoString &);
    void UnpauseWorldTimer();
    ~CWorldTimer();
    CWorldTimer();

};
#endif
