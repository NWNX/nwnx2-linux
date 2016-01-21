#ifndef NWNX_PROFILING_HANDLER_HPP_
#define NWNX_PROFILING_HANDLER_HPP_

#include "NWNXArelithProfiler.hpp"
#include <unordered_map>
#include <memory>
#include <mutex>

class MySQLHandler; struct SnapshotDataStruct;
class RunScriptHook; class MainLoopHook; 
class PrintLogEntryHook; class IntraTileDFSHook;
struct ScriptPerfInfoStruct; struct PathingPerfInfoStruct;

class ProfilingHandler final
{
public:
    ProfilingHandler(NWNXArelithProfiler* parent);
    ~ProfilingHandler();

    void storeData(const SnapshotDataStruct* snapshotData, 
                   const std::unordered_map<std::string, ScriptPerfInfoStruct>* scriptData,
                   const std::unordered_map<std::string, PathingPerfInfoStruct>* pathingData) const;

    template<typename ... params>
    void log(const int severity, const std::string& message, const params ... args) const;

private:
    NWNXArelithProfiler* m_parent;
    std::unique_ptr<MainLoopHook> m_mainLoopHook;
    std::unique_ptr<RunScriptHook> m_runScriptHook;
    std::unique_ptr<PrintLogEntryHook> m_printLogEntryHook;
    std::unique_ptr<IntraTileDFSHook> m_intraTileDFSHook;
    std::unique_ptr<MySQLHandler> m_mySqlHandler;
    mutable std::mutex m_logMutex;
};

template<typename ... params>
void ProfilingHandler::log(const int severity, const std::string& message, const params ... args) const
{
    m_logMutex.lock();
    m_parent->Log(severity, message.c_str(), args ...);
    m_logMutex.unlock();
}

// Returns the current cycle count.
inline unsigned long long rdtscp() __attribute__((always_inline));
inline unsigned long long rdtsc() __attribute__((always_inline));
inline unsigned long long serialisedRdtsc() __attribute__((always_inline));

inline unsigned long long rdtscp()
{
    unsigned long long ret;
    __asm__ __volatile__ ("rdtscp" : "=A"(ret));
    return ret;
}

inline unsigned long long rdtsc()
{
    unsigned long long ret;
    __asm__ __volatile__ ("rdtsc" : "=A"(ret));
    return ret;
}

// As per the Intel optimization manual.
// CPUID takes too long for real time work.
// Better to use the high resolution clock.
inline unsigned long long serialisedRdtsc()
{
    register unsigned cyclesHigh, cyclesLow;               
    __asm__ __volatile__ ("cpuid\n"                           
        "rdtsc\n"                           
        "mov %%edx, %0\n"                   
        "mov %%eax, %1\n"                  
        : "=r" (cyclesHigh), "=r" (cyclesLow)    
        :
        : "%eax", "%ebx", "%ecx", "%edx");                     
    return ((unsigned long long) cyclesHigh << 32) | cyclesLow;  
}

#endif // NWNX_PROFILING_HANDLER_HPP_