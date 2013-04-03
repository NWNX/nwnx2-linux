/* interface functions for nwnx_system plugin */

struct CPUUsage {
    float user, sys;
};


/* Get a listing of the files in sDir, separated by "\n". */
string DirList (string sDir);

/* Get the entire contents of the file sFile. */
string FileReadAll (string sFile);

/* Copy the file sFrom to sTo. Returns >0 on success. */
int FileCopy (string sFrom, string sTo);

/* Delete the file sFile. Returns >0 on success. */
int FileDelete (string sFile);

/* Link the file sFrom to sTo. Returns >0 on success. */
int FileLink (string sFrom, string sTo);

/* Rename the file sFrom to sTo. Returns >0 on success. */
int FileRename (string sFrom, string sTo);

/* Symlink the file sFrom to sTo. Returns >0 on success. */
int FileSymlink (string sFrom, string sTo);

/* Get the CPU usage values for the current process. */
struct CPUUsage GetProcessCPUUsage ();

/* Get an estimate of memory used by the current process in bytes. */
int GetProcessMemoryUsage ();

/* Get the current system time in seconds since the epoch. */
int GetSystemTime ();

/* Get the current process TMI limit. The nwserver default is 131071. */
int GetTMILimit ();

/* Set the current process TMI limit, with a minimum of 16k and a maximum of 8M. */
void SetTMILimit (int nLimit);

/* Shut down the current process. If nForce is specified, the process will be
 * force-killed in that number of seconds, in case it hangs during shutdown. */
void ShutdownServer (int nForce=0);

/* Returns random integer between 0 and nMax-1 directly from /dev/urandom
Returns -1 on error
It is strongly recommended not to use this function with large (>>1000)
arguments. Int this case quality isn't guaranteed.
I hope it will be better than bugged default NWN randomizer /Ilerien/
*/
int TrueRandom(int nMax);


string DirList (string sDir) {
    object oMod = GetModule();
    string sSpacer = GetLocalString(oMod, "NWNX!ODBC!SPACER");

    sDir += "\n" + sSpacer + sSpacer + sSpacer + sSpacer;

    SetLocalString(oMod, "NWNX!SYSTEM!DIRLIST", sDir);
    sDir = GetLocalString(oMod, "NWNX!SYSTEM!DIRLIST");
    DeleteLocalString(oMod, "NWNX!SYSTEM!DIRLIST");

    return sDir;
}
 
string FileReadAll (string sFile) {
    object oMod = GetModule();
    string sSpacer = GetLocalString(oMod, "NWNX!ODBC!SPACER");

    sFile += "\n" + sSpacer + sSpacer + sSpacer + sSpacer;

    SetLocalString(oMod, "NWNX!SYSTEM!FILEREADALL", sFile);
    sFile = GetLocalString(oMod, "NWNX!SYSTEM!FILEREADALL");
    DeleteLocalString(oMod, "NWNX!SYSTEM!FILEREADALL");

    return sFile;
}

int FileCopy (string sFrom, string sTo) {
    SetLocalString(GetModule(), "NWNX!SYSTEM!FILECOPY", sFrom + "\n" + sTo);
    return StringToInt(GetLocalString(GetModule(), "NWNX!SYSTEM!FILECOPY"));
}

int FileLink (string sFrom, string sTo) {
    SetLocalString(GetModule(), "NWNX!SYSTEM!FILELINK", sFrom + "\n" + sTo);
    return StringToInt(GetLocalString(GetModule(), "NWNX!SYSTEM!FILELINK"));
}

int FileDelete (string sFile) {
    SetLocalString(GetModule(), "NWNX!SYSTEM!FILEDELETE", sFile);
    return StringToInt(GetLocalString(GetModule(), "NWNX!SYSTEM!FILEDELETE"));
}

int FileRename (string sFrom, string sTo) {
    SetLocalString(GetModule(), "NWNX!SYSTEM!FILERENAME", sFrom + "\n" + sTo);
    return StringToInt(GetLocalString(GetModule(), "NWNX!SYSTEM!FILERENAME"));
}

int FileSymlink (string sFrom, string sTo) {
    SetLocalString(GetModule(), "NWNX!SYSTEM!FILESYMLINK", sFrom + "\n" + sTo);
    return StringToInt(GetLocalString(GetModule(), "NWNX!SYSTEM!FILESYMLINK"));
}


struct CPUUsage GetProcessCPUUsage () {
    struct CPUUsage ret;
    
    SetLocalString(GetModule(), "NWNX!SYSTEM!GETPROCESSCPUUSAGE", "                                ");
    string sUsage = GetLocalString(GetModule(), "NWNX!SYSTEM!GETPROCESSCPUUSAGE");

    ret.user = StringToFloat(sUsage);
    ret.sys  = StringToFloat(GetSubString(sUsage, FindSubString(sUsage, " ") + 1, 100));

    return ret;
}

int GetProcessMemoryUsage () {
    SetLocalString(GetModule(), "NWNX!SYSTEM!GETPROCESSMEMORYUSAGE", "            ");
    return StringToInt(GetLocalString(GetModule(), "NWNX!SYSTEM!GETPROCESSMEMORYUSAGE"));
}


int GetSystemTime () {
    SetLocalString(GetModule(), "NWNX!SYSTEM!GETSYSTEMTIME", "            ");
    return StringToInt(GetLocalString(GetModule(), "NWNX!SYSTEM!GETSYSTEMTIME"));
}


int GetTMILimit () {
    SetLocalString(GetModule(), "NWNX!SYSTEM!GETTMILIMIT", "          ");
    return StringToInt(GetLocalString(GetModule(), "NWNX!SYSTEM!GETTMILIMIT"));
}

void SetTMILimit (int nLimit) {
    SetLocalString(GetModule(), "NWNX!SYSTEM!SETTMILIMIT", IntToString(nLimit));
}


void ShutdownServer (int nForce) {
    SetLocalString(GetModule(), "NWNX!SYSTEM!SHUTDOWNSERVER", IntToString(nForce));
}

int TrueRandom(int nMax)
{
    SetLocalString(GetModule(), "NWNX!SYSTEM!TRUERANDOM", IntToString(nMax) + "          ");
    return StringToInt(GetLocalString(GetModule(), "NWNX!SYSTEM!TRUERANDOM"));
}
