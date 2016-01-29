#include "FunctionHook.hpp"

#ifdef _WIN32
    #include "windows.h"
#else
    #include "sys/mman.h"
    #include <cstring>
#endif

FunctionHookBase::FunctionHookBase(const std::string& hookName, void* originalFunction,
                                   void* newFunction, const unsigned int length)
    : m_oldFunction{}, m_length(length)
{
    if (m_length < RET_SIZE)
    {
        m_length = RET_SIZE;
    }

    m_info.hookName = hookName;
    m_info.originalAddr = reinterpret_cast<unsigned long>(originalFunction);
    m_info.newAddr = reinterpret_cast<unsigned long>(newFunction);

    copyOriginal();
    hook();
}

FunctionHookBase::~FunctionHookBase()
{
    restore();
}

const void* FunctionHookBase::oldFunction() const
{
    return reinterpret_cast<const void*>(m_oldFunction);
}

const FunctionHookBase::FunctionHookInfo* FunctionHookBase::hookInfo() const
{
    return &m_info;
}

void FunctionHookBase::hook() const
{
    setPageFlags(m_info.originalAddr, MemProtectionFlags::READ_WRITE_EXECUTE);
    hookFast(); 
    setPageFlags(m_info.originalAddr, MemProtectionFlags::READ_EXECUTE);
}

void FunctionHookBase::hookFast() const
{
    constexpr unsigned char tempPushRet[] =
    {
        0x68, // PUSH
        0x90, 0x90, 0x90, 0x90, // NOOP x4 (will hold address)
        0xC3 // RET
    };

    // Write our hook.
    memcpy(reinterpret_cast<void*>(m_info.originalAddr), tempPushRet, RET_SIZE);
    memcpy(reinterpret_cast<void*>(m_info.originalAddr + 1), &m_info.newAddr, 4);
}

void FunctionHookBase::setPageFlags(const unsigned long address, const MemProtectionFlags flags) const
{
#ifdef _WIN32
    DWORD platformFlags = 0x0;

    if (flags == MemProtectionFlags::READ_EXECUTE)
    {
        platformFlags = PAGE_EXECUTE_READ;
    }
    else if (flags == MemProtectionFlags::READ_WRITE_EXECUTE)
    {
        platformFlags = PAGE_EXECUTE_READWRITE;
    }

    DWORD oldProtect;
    VirtualProtect(reinterpret_cast<void*>(address), MAX_RET_SIZE, platformFlags, &oldProtect);
#else
    const int PAGE_SIZE = 4096;

    // Align the address to a page boundary.
    const char* const originalAddress = reinterpret_cast<char*>(address);
    char* page = reinterpret_cast<char*>(address);
    page = reinterpret_cast<char*>((reinterpret_cast<int>(page) + PAGE_SIZE - 1) & ~(PAGE_SIZE - 1));
    page -= PAGE_SIZE;

    int platformFlags = 0x0;

    if (flags == MemProtectionFlags::READ_EXECUTE)
    {
        platformFlags = PROT_READ | PROT_EXEC;
    }
    else if (flags == MemProtectionFlags::READ_WRITE_EXECUTE)
    {
        platformFlags = PROT_WRITE | PROT_READ | PROT_EXEC;
    }

    mprotect(page, (originalAddress - page) + MAX_RET_SIZE, platformFlags);
#endif
}

void FunctionHookBase::restore() const
{
    setPageFlags(m_info.originalAddr, MemProtectionFlags::READ_WRITE_EXECUTE);
    restoreFast();
    setPageFlags(m_info.originalAddr, MemProtectionFlags::READ_EXECUTE);
}

void FunctionHookBase::restoreFast() const
{
    // Copy the original function back to where it was.
    memcpy(reinterpret_cast<void*>(m_info.originalAddr), m_oldFunction, RET_SIZE);
}

void FunctionHookBase::copyOriginal()
{
    const unsigned int lengthToCopy = m_length > MAX_RET_SIZE ? MAX_RET_SIZE : m_length;
    memcpy(m_oldFunction, reinterpret_cast<void*>(m_info.originalAddr), lengthToCopy);

    constexpr unsigned char tempPushRet[] =
    {
        0x68, // PUSH
        0x90, 0x90, 0x90, 0x90, // NOOP x4 (will hold address)
        0xC3 // RET
    };

    memcpy(m_oldFunction + lengthToCopy, tempPushRet, RET_SIZE);
    const unsigned int modifiedAddr = m_info.originalAddr + lengthToCopy;
    memcpy(m_oldFunction + lengthToCopy + 1, &modifiedAddr, 4);

    // We'll set the old function to executable. Were we not the ones doing the hacking,
    // this might be considered a security risk.
    setPageFlags(reinterpret_cast<unsigned long>(m_oldFunction), MemProtectionFlags::READ_WRITE_EXECUTE);
}