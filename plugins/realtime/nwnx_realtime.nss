// Name     : NWNX RealTime include
// Purpose  : Various functions for accessing the RealTime plugin
// Authors  : Rob Lobbe(Gryphyn)
// Modified : 16 Nov 2007

const string rtBuffer = "                         ";	//25
const string rtPlugin = "NWNX!REALTIME!";

string GetRealTime(string sOption = "DATETIME")
{
    object oModule = GetModule();
    string rtOption = rtPlugin + sOption;
    SetLocalString(oModule, rtOption, rtBuffer);
    return GetLocalString(oModule, rtOption);
}

string GetServerDate()
{
    return GetRealTime("DATE");
}

string GetServerTime()
{
    return GetRealTime("TIME");
}

string GetServerDateTime()
{
    return GetRealTime("DATETIME");
}

string GetServerLoadTime()
{
    return GetRealTime("LOADTIME");
}

string GetServerUptime()
{
    return GetRealTime("UPTIME");
}

string GetServerDayName(int iFull = TRUE)
{
    return iFull ? GetRealTime("DAYFULL") : GetRealTime("DAYSHORT");
}

string GetServerMonthName(int iFull = TRUE)
{
    return iFull ? GetRealTime("MONTHFULL") : GetRealTime("MONTHSHORT");
}

int GetServerYear()
{
    return StringToInt(GetRealTime("YEAR"));
}

int GetServerMonth()
{
    return StringToInt(GetRealTime("MONTH"));
}

int GetServerDay()
{
    return StringToInt(GetRealTime("DAY"));
}

int GetServerHour()
{
    return StringToInt(GetRealTime("HOUR"));
}

int GetServerMinute()
{
    return StringToInt(GetRealTime("MINUTE"));
}

int GetServerSecond()
{
    return StringToInt(GetRealTime("SECOND"));
}

int GetServerMilliSecond()
{
    return StringToInt(GetRealTime("MILLISECOND"));
}

int GetServerUpDays()
{
    return StringToInt(GetRealTime("UPDAYS"));
}

int GetServerUpHours()
{
    return StringToInt(GetRealTime("UPHOURS"));
}

int GetServerUpMinutes()
{
    return StringToInt(GetRealTime("UPMINUTES"));
}

int GetServerUpSeconds()
{
    return StringToInt(GetRealTime("UPSECONDS"));
}

int GetServerUpMilliseconds()
{
    return StringToInt(GetRealTime("UPMILLISECONDS"));
}

int GetServerTicks() number of seconds since January 1st 2000
{
    return StringToInt(GetRealTime("TICKS"));
}
