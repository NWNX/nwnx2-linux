// Gets the current call stack, with the running script first, separated by :
// Example: currentScript:caller2:caller1
string GetRunningScriptCallStack();

// Gets the running scripts name.
string GetRunningScriptName();

string GetRunningScriptCallStack()
{
    SetLocalString(GetModule(), "NWNX!PROFILER!STACK", "1");
    return GetLocalString(GetModule(), "NWNX!PROFILER!STACK");
}

string GetRunningScriptName()
{
    SetLocalString(GetModule(), "NWNX!PROFILER!CURRENTSCRIPT", "1");
    return GetLocalString(GetModule(), "NWNX!PROFILER!CURRENTSCRIPT");
}
