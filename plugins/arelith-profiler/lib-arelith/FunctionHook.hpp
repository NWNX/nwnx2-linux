#ifndef NWNX_UNIFIED__FUNCTION_HOOK_HPP
#define NWNX_UNIFIED__FUNCTION_HOOK_HPP

// This stops the provided register from being used in the current compilation unit. 
// This is necessary for hooks to work in high optimization levels (-O2+), otherwise,
// the compiler will, for example, use fcaller-saves and clobber the EBX register, 
// thus causing a seg fault when the caller uses it.
#define NO_CLOBBER(REGISTER) register int __no__clobber__##REGISTER asm (#REGISTER)

#include <string>

class FunctionHookBase
{
public:
    struct FunctionHookInfo
    {
        std::string hookName;
        unsigned long originalAddr;
        unsigned long newAddr;
    };

    FunctionHookBase(const std::string& hookName,
                     void* originalFunction,
                     void* newFunction,
                     const unsigned int length = 0);
    virtual ~FunctionHookBase() = 0;

#ifdef __GNUC__
    void inline jumpOriginalFast() const __attribute__((always_inline))
    {
        __asm__ __volatile__
        (
            "leave;"
            "jmp *%0;"
            : // No outputs
            : "r" (m_oldFunction)
            : // No clobbered registers
        );
    }
#endif

protected:
    const void* oldFunction() const;
    const FunctionHookInfo* hookInfo() const;

    enum class MemProtectionFlags
    {
        READ_EXECUTE,
        READ_WRITE_EXECUTE
    };

    // Array length holding the old function in memory.
    static const unsigned int ARRAY_SIZE = 32;

    // Minimum length to copy over.
    static const unsigned int RET_SIZE = 6;

    // Maximum length to copy over.
    static const unsigned int MAX_RET_SIZE = ARRAY_SIZE - RET_SIZE;

    unsigned char m_oldFunction[ARRAY_SIZE];
    unsigned int m_length;
    FunctionHookInfo m_info;

    void hook() const;
    void hookFast() const;
    void setPageFlags(const unsigned long address, const MemProtectionFlags flags) const;
    void restore() const;
    void restoreFast() const;
    void copyOriginal();
};

template <typename ret = void>
class FunctionHook : public FunctionHookBase
{
public:
    FunctionHook(const std::string& hookName,
                 void* originalFunction,
                 void* newFunction,
                 const unsigned int length = 0);

    virtual ~FunctionHook();

    template<typename ... params>
    ret callOriginal(params ... args);

    template<typename ... params>
    ret callOriginalSafely(params ... args);
};

template <typename ret>
FunctionHook<ret>::FunctionHook(const std::string& hookName,
                                void* originalFunction,
                                void* newFunction,
                                const unsigned int length)
    : FunctionHookBase(hookName, originalFunction, newFunction, length)
{ }

template <typename ret>
FunctionHook<ret>::~FunctionHook()
{ }

template <>
template <typename ... params>
void FunctionHook<void>::callOriginal(params ... args)
{
    void(*funcPtr)(params ...) = reinterpret_cast<void(*)(params ...)>(m_oldFunction);
    funcPtr(args ...);
}

template <>
template <typename ... params>
void FunctionHook<void>::callOriginalSafely(params ... args)
{
    setPageFlags(m_info.originalAddr, MemProtectionFlags::READ_WRITE_EXECUTE);
    restoreFast();
    void(*funcPtr)(params ...) = reinterpret_cast<void(*)(params ...)>(m_info.originalAddr);
    funcPtr(args ...);
    hookFast();
    setPageFlags(m_info.originalAddr, MemProtectionFlags::READ_EXECUTE);
}

template <typename ret>
template <typename ... params>
ret FunctionHook<ret>::callOriginal(params ... args)
{
    ret(*funcPtr)(params ...) = reinterpret_cast<ret(*)(params ...)>(m_oldFunction);
    ret retVal = funcPtr(args ...);
    return retVal;
}

template <typename ret>
template <typename ... params>
ret FunctionHook<ret>::callOriginalSafely(params ... args)
{
    setPageFlags(m_info.originalAddr, MemProtectionFlags::READ_WRITE_EXECUTE);
    restoreFast();
    ret(*funcPtr)(params ...) = reinterpret_cast<ret(*)(params ...)>(m_info.originalAddr);
    ret retVal = funcPtr(args ...);
    hookFast();
    setPageFlags(m_info.originalAddr, MemProtectionFlags::READ_EXECUTE);
    return retVal;
}

#endif // NWNX_UNIFIED__FUNCTION_HOOK_HPP