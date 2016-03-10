# RealTime

Port of the Windows NWNX2 RealTime plugin, times are in the servers local timezone unless specified.

Here's a little fresh retro... A RealTime plugin for NWNX2.

Rather the getting the server time via Database calls (SQL) here's a plugin that goes via the POSIX time APIs.

Here's what's available

string GetServerLoadTime() -> yyyy-mm-dd hh:mm:ss (when Plugin loads)
string GetServerDate() -> yyyy-mm-dd
string GetServerTime() -> hh:mm:ss
string GetServerDateTime() -> yyyy-mm-dd hh:mm:ss
string GetServerDayName(int iFullname = TRUE) eg Monday or Mon
string GetServerMonthName(int iFullname = TRUE) eg January or Jan
int GetServerYear()
int GetServerMonth()
int GetServerDay()
int GetServerHour()
int GetServerMinute()
int GetServerSecond()
int GetServerUpDays()
int GetServerUpHours()
int GetServerUpMinutes()
int GetServerUpSeconds()
string GetServerUptime() -> hh:mm:ss 

See the included ```nwnx_realtime.nss``` for usage examples.

Any usage or library errors are printed to the plugin log at ```logs.0/nwnx_realtime.txt```.

Added by special request for a PW that uses the RealTime plugin:

int GetServerTicks() number of seconds since January 1st 2000 (UTC)
