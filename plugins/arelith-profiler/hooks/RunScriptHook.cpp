#include "AllHooks.hpp"

const unsigned long RunScriptHook::RUN_SCRIPT_ADDR = 0x08261F94;
const unsigned int RunScriptHook::SCRIPT_TIMING_CACHE_SIZE = 12800;
const unsigned int RunScriptHook::SCRIPT_NAME_CACHE_SIZE = SCRIPT_TIMING_CACHE_SIZE * (MAX_NAME_LENGTH + 1);
const unsigned int RunScriptHook::MAX_NAME_LENGTH = 16;
const unsigned int RunScriptHook::MAX_DEPTH = 16;

RunScriptHook* RunScriptHook::m_instance;
ProfilingHandler* RunScriptHook::m_parent;
ScriptTimingStruct* RunScriptHook::m_scriptTimingCache;
char* RunScriptHook::m_scriptNameCache;
unsigned int RunScriptHook::m_scriptNameIndex;
unsigned int RunScriptHook::m_scriptTimingIndex; 
unsigned int RunScriptHook::m_depth;
unsigned long long RunScriptHook::m_debt[MAX_DEPTH];
unsigned int RunScriptHook::m_debtDepth;

RunScriptHook::RunScriptHook(ProfilingHandler* parent)
    : ProfilingHookBase(parent, "RunScript",
                        reinterpret_cast<void*>(RUN_SCRIPT_ADDR),
                        reinterpret_cast<void*>(runScriptHookFunc))
{
    if (m_instance != nullptr)
    {
        abort();
    }

    m_instance = this;
    m_parent = parent;
    m_scriptTimingIndex = 0;  
    m_scriptNameIndex = 0;
    m_depth = 0;
    m_debtDepth = 0;
}

RunScriptHook::~RunScriptHook()
{
    delete[] m_scriptNameCache;
    delete[] m_scriptTimingCache;
}

RunScriptHook* RunScriptHook::instance()
{
    return m_instance;
}

#pragma GCC push_options
#pragma GCC optimize ("O0")

int RunScriptHook::runScriptHookFunc(void* virtualMachine, char** scriptName, unsigned long int objId, int args)
{
    // Just pass control off.
    if (*scriptName == nullptr)
    {
        return reinterpret_cast<ProfilingHookBase<int>*>(m_instance)->callOriginal(virtualMachine, scriptName, objId, args);
    }

    #ifndef RELEASE
    const auto callStart = rdtscp();
    #endif

    const auto funcStart = rdtscp();
    ++m_depth;
    int ret = reinterpret_cast<ProfilingHookBase<int>*>(m_instance)->callOriginal(virtualMachine, scriptName, objId, args);
    --m_depth;
    const auto funcEnd = rdtscp();
    const auto absFuncTime = funcEnd - funcStart;
    auto funcTime = absFuncTime;

    // If we're moving up depth levels, reset the existing debt for that level.
    for (unsigned int i = m_depth; i > m_debtDepth; --i)
    {
        m_debt[i] = 0;
    }

    // If the debt recorded is for the previous depth, subtract it from our execution time.
    if (m_debtDepth == m_depth + 1)
    {
        // This should never be false unless there's a bug causing inaccurate debt recording.
        // However, in the interests of not corrupting data, it's best to add a check here.
        // Performance hit will be minimal with the branch predication hint.
        if (__builtin_expect(funcTime >= m_debt[m_debtDepth], true))
        {
            funcTime -= m_debt[m_debtDepth];
        }
        else
        {
            m_parent->log(0, "RunScript: Gathered data may be inaccurate for script '%s'. "
                             "(funcTime=%llu, absFuncTime=%llu, m_depth=%u, m_debtDepth=%u, m_debt[m_deptDepth]=%llu.\n",
                             *scriptName, funcTime, absFuncTime, m_depth, m_debtDepth, m_debt[m_debtDepth]);
            funcTime = absFuncTime;
        }
    }

    // In either case, add the absolute execution time as debt for this level.
    m_debtDepth = m_depth;

    // No need to track debt for scripts that have 0 depth.
    if (m_debtDepth != 0)
    {
        m_debt[m_debtDepth] += absFuncTime;
    }

    if (__builtin_expect(m_scriptNameCache == nullptr, false))
    {
        m_scriptNameCache = new char[SCRIPT_NAME_CACHE_SIZE];
        m_parent->log(0, "Allocated '%u' bytes for the Script Name Cache at '0x%x'.\n", SCRIPT_NAME_CACHE_SIZE, m_scriptNameCache);
    }

    if (__builtin_expect(m_scriptTimingCache == nullptr, false))
    {
        m_scriptTimingCache = new ScriptTimingStruct[SCRIPT_TIMING_CACHE_SIZE];
        m_parent->log(0, "Allocated '%u' bytes for the Script Timing Cache at '0x%x'.\n", SCRIPT_TIMING_CACHE_SIZE, m_scriptTimingCache);
    }

    const int len = strlen(*scriptName) + 1;
    memcpy(m_scriptNameCache + m_scriptNameIndex, *scriptName, len);
    m_scriptTimingCache[m_scriptTimingIndex].scriptName = m_scriptNameCache + m_scriptNameIndex;
    m_scriptTimingCache[m_scriptTimingIndex].executionTime = funcTime;
    m_scriptNameIndex += len;
    ++m_scriptTimingIndex;
 
    // These two will always be false unless something goes wrong, but they're here to protect against Bad Things (tm).
    if (__builtin_expect(m_scriptNameIndex >= SCRIPT_NAME_CACHE_SIZE || m_scriptTimingIndex >= SCRIPT_TIMING_CACHE_SIZE, false))
    {
        m_parent->log(1, "The RunScript cache overflowed. This should not happen! Stored data will be unreliable for this snapshot. "
                         "(m_scriptNameIndex=%u, SCRIPT_NAME_CACHE_SIZE=%u, m_scriptTimingIndex=%u, SCRIPT_TIMING_CACHE_SIZE=%u)\n", 
                         m_scriptNameIndex, SCRIPT_NAME_CACHE_SIZE, m_scriptTimingIndex, SCRIPT_TIMING_CACHE_SIZE);
        flushCaches();
    }

    #ifndef RELEASE
    const auto callEnd = rdtscp();
    const auto callOverhead = (callEnd - callStart) - absFuncTime;

    m_parent->log(3, "RunScript: %s, 0x%x, %i (Time=%llu, AbsoluteTime=%llu, Overhead=%llu, Cache Index=%u, Elem Index=%u, Depth=%u)\n", 
                      *scriptName, objId, args, funcTime, absFuncTime, callOverhead, m_scriptNameIndex, m_scriptTimingIndex, m_depth);
    #endif

    return ret;
}

#pragma GCC pop_options

void RunScriptHook::flushCaches()
{
    m_scriptNameIndex = 0;
    m_scriptTimingIndex = 0;
}

ScriptTimingStruct* RunScriptHook::dataPtr()
{
    return m_scriptTimingCache;
}

unsigned int RunScriptHook::dataSize()
{
    return m_scriptTimingIndex;
}