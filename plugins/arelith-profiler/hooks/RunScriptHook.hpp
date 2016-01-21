#ifndef NWNX_RUN_SCRIPT_HOOK_HPP_
#define NWNX_RUN_SCRIPT_HOOK_HPP_

#include "ProfilingHookBase.hpp"

struct ScriptTimingStruct
{
    char* scriptName;
    unsigned long long executionTime;
};

class RunScriptHook final : public ProfilingHookBase<int>
{
public:
    RunScriptHook(ProfilingHandler* parent);
    virtual ~RunScriptHook();

    static int runScriptHookFunc(void* virtualMachine, char** scriptName, unsigned long int objId, int args);
    static RunScriptHook* instance();
    static void flushCaches();
    static ScriptTimingStruct* dataPtr();
    static unsigned int dataSize();

private:
    static const unsigned long RUN_SCRIPT_ADDR;
    static const unsigned int SCRIPT_TIMING_CACHE_SIZE;
    static const unsigned int SCRIPT_NAME_CACHE_SIZE;
    static const unsigned int MAX_NAME_LENGTH;
    static const unsigned int MAX_DEPTH;

    static RunScriptHook* m_instance;
    static ProfilingHandler* m_parent;
    static ScriptTimingStruct* m_scriptTimingCache;
    static char* m_scriptNameCache;
    static unsigned int m_scriptNameIndex;
    static unsigned int m_scriptTimingIndex;
    static unsigned int m_depth;
    static unsigned long long m_debt[];
    static unsigned int m_debtDepth;
};

#endif // NWNX_RUN_SCRIPT_HOOK_HPP_