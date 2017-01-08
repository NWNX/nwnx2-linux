#include "AllHooks.hpp"

const unsigned long IntraTileDFSHook::INTRA_TILE_DFS_ADDR = 0x0808DCFC;
const unsigned int IntraTileDFSHook::AREA_TIMING_CACHE_SIZE = 12800;
const unsigned int IntraTileDFSHook::AREA_NAME_CACHE_SIZE = AREA_TIMING_CACHE_SIZE * (MAX_NAME_LENGTH + 1);
const unsigned int IntraTileDFSHook::MAX_NAME_LENGTH = 16;

IntraTileDFSHook* IntraTileDFSHook::m_instance;
ProfilingHandler* IntraTileDFSHook::m_parent;
AreaTimingStruct* IntraTileDFSHook::m_areaTimingCache;
char* IntraTileDFSHook::m_areaNameCache;
unsigned int IntraTileDFSHook::m_areaNameIndex;
unsigned int IntraTileDFSHook::m_areaTimingIndex;
unsigned int IntraTileDFSHook::m_depth;

IntraTileDFSHook::IntraTileDFSHook(ProfilingHandler* parent)
    : ProfilingHookBase(parent, "IntraTileDFS",
                        reinterpret_cast<void*>(INTRA_TILE_DFS_ADDR),
                        reinterpret_cast<void*>(intraTileDFSHookFunc))
{
    if (m_instance != nullptr)
    {
        abort();
    }

    m_instance = this;
    m_parent = parent;
    m_areaTimingIndex = 0;  
    m_areaNameIndex = 0;
}

IntraTileDFSHook::~IntraTileDFSHook()
{
    delete[] m_areaNameCache;
    delete[] m_areaTimingCache;
}

IntraTileDFSHook* IntraTileDFSHook::instance()
{
    return m_instance;
}

#pragma GCC push_options
#pragma GCC optimize ("O0")

int IntraTileDFSHook::intraTileDFSHookFunc(void* mesh, void* tile, void* area, void* pathFindInfo, 
                                           int unused1, float unused2, int unused3, float unused4,
                                           float unused5, float unused6, float unused7, float unused8, int unused9)
{
    // We should just skip in this case. Unlike RunScript, call count is unimportant.
    // Only execution time matters. The best way to capture that is to track the first
    // call, and disregard deeper calls.
    if (m_depth != 0)
    {
        #ifndef RELEASE
        m_parent->log(3, "IntraTileDFS: Depth > 0, skipping.\n");
        #endif
        
        return reinterpret_cast<ProfilingHookBase<int>*>(m_instance)->callOriginal(mesh, tile, area, pathFindInfo, 
                                                                                   unused1, unused2, unused3, unused4, 
                                                                                   unused5, unused6, unused7, unused8, 
                                                                                   unused9);
    }

    #ifndef RELEASE
    const auto callStart = rdtscp();
    #endif

    const auto funcStart = rdtscp();
    ++m_depth;
    int ret = reinterpret_cast<ProfilingHookBase<int>*>(m_instance)->callOriginal(mesh, tile, area, pathFindInfo, 
                                                                                  unused1, unused2, unused3, unused4, 
                                                                                  unused5, unused6, unused7, unused8, 
                                                                                  unused9);
    --m_depth;
    const auto funcEnd = rdtscp();
    const auto funcTime = funcEnd - funcStart;

    // The offset to the area tag is CNWArea+0xB0.
    const char* areaTagPtr = reinterpret_cast<char*>(area) + 0xB0;

    if (__builtin_expect(m_areaNameCache == nullptr, false))
    {
        m_areaNameCache = new char[AREA_NAME_CACHE_SIZE];
        m_parent->log(0, "Allocated '%u' bytes for the Area Name Cache at '0x%x'.\n", AREA_NAME_CACHE_SIZE, m_areaNameCache);
    }

    if (__builtin_expect(m_areaTimingCache == nullptr, false))
    {
        m_areaTimingCache = new AreaTimingStruct[AREA_TIMING_CACHE_SIZE];
        m_parent->log(0, "Allocated '%u' bytes for the Area Timing Cache at '0x%x'.\n", AREA_TIMING_CACHE_SIZE, m_areaTimingCache);
    }

    auto len = strlen(areaTagPtr);

    // The ResRef can be up to MAX_NAME_LENGTH in size.
    if (len >= MAX_NAME_LENGTH)
    {
        len = MAX_NAME_LENGTH;
    }

    memcpy(m_areaNameCache + m_areaNameIndex, areaTagPtr, len);
    // Force the null terminator to be added to the buffer.
    m_areaNameCache[m_areaNameIndex + len] = '\0';
    m_areaTimingCache[m_areaTimingIndex].areaName = m_areaNameCache + m_areaNameIndex;
    m_areaTimingCache[m_areaTimingIndex].executionTime = funcTime;
    m_areaNameIndex += len + 1;
    ++m_areaTimingIndex;
 
    // These two will always be false unless something goes wrong, but they're here to protect against Bad Things (tm).
    if (__builtin_expect(m_areaNameIndex >= AREA_NAME_CACHE_SIZE || m_areaTimingIndex >= AREA_TIMING_CACHE_SIZE, false))
    {
        m_parent->log(1, "The IntraTileDFS cache overflowed. This should not happen! Stored data will be unreliable for this snapshot. "
                         "(m_areaNameIndex=%u, AREA_NAME_CACHE_SIZE=%u, m_areaTimingIndex=%u, AREA_TIMING_CACHE_SIZE=%u)\n", 
                         m_areaNameIndex, AREA_NAME_CACHE_SIZE, m_areaTimingIndex, AREA_TIMING_CACHE_SIZE);
        flushCaches();
    }

    #ifndef RELEASE
    const auto callEnd = rdtscp();
    const auto callOverhead = (callEnd - callStart) - funcTime;
    m_parent->log(3, "IntraTileDFS: %s (Time=%llu, Overhead=%llu, Cache Index=%u, Elem Index=%u)\n", 
        areaTagPtr, funcTime, callOverhead, m_areaNameIndex, m_areaTimingIndex);
    #endif

    return ret;
}

#pragma GCC pop_options

void IntraTileDFSHook::flushCaches()
{
    m_areaNameIndex = 0;
    m_areaTimingIndex = 0;
}

AreaTimingStruct* IntraTileDFSHook::dataPtr()
{
    return m_areaTimingCache;
}

unsigned int IntraTileDFSHook::dataSize()
{
    return m_areaTimingIndex;
}