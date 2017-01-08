#ifndef NWNX_INTRA_TILE_DFS_HOOK_HPP_
#define NWNX_INTRA_TILE_DFS_HOOK_HPP_

#include "ProfilingHookBase.hpp"

struct AreaTimingStruct
{
    char* areaName;
    unsigned long long executionTime;
};

class IntraTileDFSHook final : public ProfilingHookBase<int>
{
public:
    IntraTileDFSHook(ProfilingHandler* parent);
    virtual ~IntraTileDFSHook();

    static int intraTileDFSHookFunc(void* mesh, void* tile, void* area, void* pathFindInfo, 
                                    int unused1, float unused2, int unused3, float unused4,
                                    float unused5, float unused6, float unused7, float unused8, int unused9);
    static IntraTileDFSHook* instance();
    static void flushCaches();
    static AreaTimingStruct* dataPtr();
    static unsigned int dataSize();

private:
    static const unsigned long INTRA_TILE_DFS_ADDR;
    static const unsigned int AREA_TIMING_CACHE_SIZE;
    static const unsigned int AREA_NAME_CACHE_SIZE;
    static const unsigned int MAX_NAME_LENGTH;

    static IntraTileDFSHook* m_instance;
    static ProfilingHandler* m_parent;
    static AreaTimingStruct* m_areaTimingCache;
    static char* m_areaNameCache;
    static unsigned int m_areaNameIndex;
    static unsigned int m_areaTimingIndex;
    static unsigned int m_depth;
};

#endif // NWNX_INTRA_TILE_DFS_HOOK_HPP_