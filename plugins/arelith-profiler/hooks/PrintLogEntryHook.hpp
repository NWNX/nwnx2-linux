#ifndef NWNX_PRINT_LOG_ENTRY_HOOK_HPP_
#define NWNX_PRINT_LOG_ENTRY_HOOK_HPP_

#include "ProfilingHookBase.hpp"

class PrintLogEntryHook final : public ProfilingHookBase<int>
{
public:
    PrintLogEntryHook(ProfilingHandler* parent);
    virtual ~PrintLogEntryHook();

    static int printLogEntryHookFunc(void* virtualMachine, int arg1, int arg2);
    static PrintLogEntryHook* instance();
    static unsigned long long getCyclesAndReset();

private:
    static const unsigned long PRINT_LOG_ENTRY_ADDR;

    static PrintLogEntryHook* m_instance;
    static ProfilingHandler* m_parent;
    static unsigned long long m_executionCycles;
};

#endif // NWNX_PRINT_LOG_ENTRY_HOOK_HPP_