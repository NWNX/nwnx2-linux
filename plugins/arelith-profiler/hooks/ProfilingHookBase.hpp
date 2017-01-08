#ifndef PROFILING_HOOK_BASE_HPP_
#define PROFILING_HOOK_BASE_HPP_

#include "FunctionHook.hpp"
#include "ProfilingHandler.hpp"
#include <string>

template <typename ret = void>
class ProfilingHookBase : public FunctionHook<ret>
{
public:
    virtual ~ProfilingHookBase();
    ProfilingHookBase(ProfilingHandler* parent, std::string name, void* originalFunction,
        void* newFunction, const unsigned int length = 0);

private:
    ProfilingHandler* m_parent;
};

template <typename ret>
ProfilingHookBase<ret>::~ProfilingHookBase()
{
    m_parent->log(0, "Detour at '0x%x' for '%s' has been restored.\n",
       this->m_info.originalAddr, this->m_info.hookName.c_str());
}

template <typename ret>
ProfilingHookBase<ret>::ProfilingHookBase(ProfilingHandler* parent, std::string name, void* originalFunction, 
    void* newFunction, const unsigned int length)
    : FunctionHook<ret>(name, originalFunction, newFunction, length), m_parent(parent)
{
    m_parent->log(0, "Memory address '0x%x' (length '%i') detoured to '0x%x' for '%s'.\n",
        this->m_info.originalAddr, this->m_length, this->m_info.newAddr, name.c_str());

    m_parent->log(4, "Cached function (0x%x):", this->m_oldFunction);

    for (unsigned int i = 0; i < this->m_length + FunctionHookBase::RET_SIZE; ++i)
    {
        m_parent->log(4, " %x", *(this->m_oldFunction + i));
    }

    m_parent->log(4, "\n");
    m_parent->log(4, "Detoured function (0x%x):", this->m_info.originalAddr);

    for (unsigned int i = 0; i < this->m_length; ++i)
    {
        m_parent->log(4, " %x", *(reinterpret_cast<unsigned char*>(this->m_info.originalAddr) + i));
    }

    m_parent->log(4, "\n");
}

#endif // PROFILING_HOOK_BASE_HPP_