#include "CWorldTimer.h"

unsigned long CWorldTimer::AddWorldTimes(unsigned long, unsigned long, unsigned long, unsigned long, unsigned long *, unsigned long *)
{
    asm("leave");
    asm("mov $0x08241804, %eax");
    asm("jmp *%eax");
}

void CWorldTimer::AdvanceToTime(int, int, int, int)
{
    asm("leave");
    asm("mov $0x08240ce0, %eax");
    asm("jmp *%eax");
}

int CWorldTimer::CompareWorldTimes(unsigned long, unsigned long, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x082418ac, %eax");
    asm("jmp *%eax");
}

void CWorldTimer::ConvertFromCalendarDay(unsigned long, unsigned long *, unsigned long *, unsigned long *)
{
    asm("leave");
    asm("mov $0x08241388, %eax");
    asm("jmp *%eax");
}

void CWorldTimer::ConvertFromTimeOfDay(unsigned long, unsigned long *, unsigned long *, unsigned long *, unsigned long *)
{
    asm("leave");
    asm("mov $0x082413f8, %eax");
    asm("jmp *%eax");
}

unsigned long CWorldTimer::ConvertToCalendarDay(unsigned long, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x082412a0, %eax");
    asm("jmp *%eax");
}

int CWorldTimer::ConvertToTimeOfDay(unsigned long, unsigned long, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x082412f4, %eax");
    asm("jmp *%eax");
}

unsigned long CWorldTimer::GetCalendarDayFromSeconds(float)
{
    asm("leave");
    asm("mov $0x08241a8c, %eax");
    asm("jmp *%eax");
}

unsigned __int64 CWorldTimer::GetSnapshotTimeDifference()
{
    asm("leave");
    asm("mov $0x08241284, %eax");
    asm("jmp *%eax");
}

unsigned __int64 CWorldTimer::GetSnapshotTime()
{
    asm("leave");
    asm("mov $0x08241274, %eax");
    asm("jmp *%eax");
}

int CWorldTimer::GetTimeDifferenceFromWorldTime(unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x08241650, %eax");
    asm("jmp *%eax");
}

unsigned long CWorldTimer::GetTimeOfDayFromSeconds(float)
{
    asm("leave");
    asm("mov $0x08241af0, %eax");
    asm("jmp *%eax");
}

int CWorldTimer::GetWorldTimeCalendarDayString()
{
    asm("leave");
    asm("mov $0x08240938, %eax");
    asm("jmp *%eax");
}

int CWorldTimer::GetWorldTimeCalendarDay()
{
    asm("leave");
    asm("mov $0x0824084c, %eax");
    asm("jmp *%eax");
}

unsigned long CWorldTimer::GetWorldTimeDay()
{
    asm("leave");
    asm("mov $0x0824196c, %eax");
    asm("jmp *%eax");
}

unsigned long CWorldTimer::GetWorldTimeHour()
{
    asm("leave");
    asm("mov $0x08241994, %eax");
    asm("jmp *%eax");
}

unsigned long CWorldTimer::GetWorldTimeMillisecond()
{
    asm("leave");
    asm("mov $0x08241a3c, %eax");
    asm("jmp *%eax");
}

unsigned long CWorldTimer::GetWorldTimeMinute()
{
    asm("leave");
    asm("mov $0x082419cc, %eax");
    asm("jmp *%eax");
}

unsigned long CWorldTimer::GetWorldTimeMonth()
{
    asm("leave");
    asm("mov $0x08241934, %eax");
    asm("jmp *%eax");
}

unsigned long CWorldTimer::GetWorldTimeSecond()
{
    asm("leave");
    asm("mov $0x08241a08, %eax");
    asm("jmp *%eax");
}

int CWorldTimer::GetWorldTimeTimeOfDayString()
{
    asm("leave");
    asm("mov $0x08240afc, %eax");
    asm("jmp *%eax");
}

int CWorldTimer::GetWorldTimeTimeOfDay()
{
    asm("leave");
    asm("mov $0x08240a10, %eax");
    asm("jmp *%eax");
}

unsigned long CWorldTimer::GetWorldTimeYear()
{
    asm("leave");
    asm("mov $0x082418f8, %eax");
    asm("jmp *%eax");
}

void CWorldTimer::GetWorldTime(unsigned long *, unsigned long *)
{
    asm("leave");
    asm("mov $0x082416a4, %eax");
    asm("jmp *%eax");
}

void CWorldTimer::PauseWorldTimer()
{
    asm("leave");
    asm("mov $0x082406dc, %eax");
    asm("jmp *%eax");
}

void CWorldTimer::ResetTimer(CWorldTimer *)
{
    asm("leave");
    asm("mov $0x082417a0, %eax");
    asm("jmp *%eax");
}

int CWorldTimer::SetFixedSnapshotRate(int, int)
{
    asm("leave");
    asm("mov $0x08241a5c, %eax");
    asm("jmp *%eax");
}

void CWorldTimer::SetMinutesPerHour(unsigned char)
{
    asm("leave");
    asm("mov $0x082411dc, %eax");
    asm("jmp *%eax");
}

void CWorldTimer::SetSnapshotTime()
{
    asm("leave");
    asm("mov $0x0824121c, %eax");
    asm("jmp *%eax");
}

void CWorldTimer::SetWorldTime(unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, int)
{
    asm("leave");
    asm("mov $0x08241478, %eax");
    asm("jmp *%eax");
}

void CWorldTimer::SetWorldTime(unsigned long, unsigned long, int)
{
    asm("leave");
    asm("mov $0x08241590, %eax");
    asm("jmp *%eax");
}

unsigned long CWorldTimer::SubtractWorldTimes(unsigned long, unsigned long, unsigned long, unsigned long, unsigned long *, unsigned long *)
{
    asm("leave");
    asm("mov $0x08241850, %eax");
    asm("jmp *%eax");
}

int CWorldTimer::TranslateWorldTimeToString(unsigned long, unsigned long, CExoString &, CExoString &)
{
    asm("leave");
    asm("mov $0x08240bcc, %eax");
    asm("jmp *%eax");
}

void CWorldTimer::UnpauseWorldTimer()
{
    asm("leave");
    asm("mov $0x082407bc, %eax");
    asm("jmp *%eax");
}

