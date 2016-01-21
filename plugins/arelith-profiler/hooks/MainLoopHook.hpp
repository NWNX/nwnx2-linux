#ifndef NWNX_MAIN_LOOP_HOOK_HPP_
#define NWNX_MAIN_LOOP_HOOK_HPP_

#include "ProfilingHookBase.hpp"
#include <memory>
#include <unordered_map>
#include <thread>

struct ScriptPerfInfoStruct
{
    unsigned long long totalExecutionCycles;
    unsigned int totalCalls;
};

struct PathingPerfInfoStruct
{
    unsigned long long totalExecutionCycles;
};

struct SnapshotDataStruct
{
    unsigned short serverID;
    unsigned int mainLoopTicks;
    unsigned long long mainLoopCycles;
    unsigned long long logCycles;
    unsigned short playerCount;
    unsigned short dmCount;
};

class MainLoopHook final : public ProfilingHookBase<int>
{
public:
    MainLoopHook(ProfilingHandler* parent);
    virtual ~MainLoopHook();

    static MainLoopHook* instance();
    static int mainLoopHookFunc(void* serverExoApp);
    static void sortData();
    static void sortScriptData();
    static void sortPathingData();

private:
    static void pushDataToDb(SnapshotDataStruct snapshot);

    static const unsigned long MAIN_LOOP_ADDR;
    static const long long FLUSH_INTERVAL_IN_MS;

    static MainLoopHook* m_instance;
    static ProfilingHandler* m_parent;
    static std::unordered_map<std::string, ScriptPerfInfoStruct> m_formattedScriptMap;
    static std::unordered_map<std::string, PathingPerfInfoStruct> m_formattedPathingMap;
    static std::chrono::steady_clock::time_point m_lastFlush;
    static std::unique_ptr<std::thread>* m_processingThreadPtr;
    static unsigned int m_mainLoopTicks;
    static unsigned long long m_mainLoopCycles;

    // This can't be static -- we need to guarantee the order of destruction to ensure
    // that we prevent segfaults when shutting down the server.
    std::unique_ptr<std::thread> m_processingThread;
};

#endif // NWNX_MAIN_LOOP_HOOK_HPP_