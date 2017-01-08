#include "PrintLogEntryHook.hpp"

const unsigned long PrintLogEntryHook::PRINT_LOG_ENTRY_ADDR = 0x0821EB68;

PrintLogEntryHook* PrintLogEntryHook::m_instance;
ProfilingHandler* PrintLogEntryHook::m_parent;
unsigned long long PrintLogEntryHook::m_executionCycles;

PrintLogEntryHook::PrintLogEntryHook(ProfilingHandler* parent)
    : ProfilingHookBase(parent, "PrintLogEntry",
                        reinterpret_cast<void*>(PRINT_LOG_ENTRY_ADDR),
                        reinterpret_cast<void*>(printLogEntryHookFunc), 8)
{
    if (m_instance != nullptr)
    {
        abort();
    }
    
    m_instance = this;
    m_parent = parent;
    m_executionCycles = 0;
}

PrintLogEntryHook::~PrintLogEntryHook()
{
}

PrintLogEntryHook* PrintLogEntryHook::instance()
{
    return m_instance;
}

#pragma GCC push_options
#pragma GCC optimize ("O0")

int PrintLogEntryHook::printLogEntryHookFunc(void* virtualMachine, int arg1, int arg2)
{
    #ifndef RELEASE
    const auto callStart = rdtscp();
    #endif

    const auto funcStart = rdtscp();
    int ret = reinterpret_cast<ProfilingHookBase<int>*>(m_instance)->callOriginal(virtualMachine, arg1, arg2);
    const auto funcEnd = rdtscp();
    const auto funcTime = funcEnd - funcStart;

    m_executionCycles += funcTime;

    #ifndef RELEASE
    const auto callEnd = rdtscp();
    const auto callOverhead = (callEnd - callStart) - funcTime;
    m_parent->log(3, "PrintLogEntry: %i, %i (Time=%llu, Overhead=%llu)\n", arg1, arg2, funcTime, callOverhead);
    #endif

    return ret;
}

#pragma GCC pop_options

unsigned long long PrintLogEntryHook::getCyclesAndReset()
{
    unsigned long long int tempCycles = m_executionCycles;
    m_executionCycles = 0;
    return tempCycles;
}