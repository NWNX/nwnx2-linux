#ifndef NWNX_ARELITH_STEALTH_CGGAMEOBJECTARRAY_HPP_
#define NWNX_ARELITH_STEALTH_CGGAMEOBJECTARRAY_HPP_

#include <algorithm>
#include <array>
#include <vector>

class CGameObject;

namespace Hooks
{
    namespace CGameObjectArray
    {
        // We use this 'cause unordered_map be slow as heck for us, yo.
        class GhettoHashmap
        {
        public:
            GhettoHashmap();
            CGameObject* Find(const uint32_t id);
            void Set(const uint32_t id, CGameObject* obj);
            void Remove(const uint32_t id);

        private:
            struct CacheData
            {
                uint32_t m_objId;
                CGameObject* m_obj;
            };

            static constexpr size_t BUCKET_SIZE = 256000;
            std::array<std::vector<CacheData>, BUCKET_SIZE> m_map;
        };

        extern GhettoHashmap g_objectMap;

        void Hook();
        void Unhook();
    }
}

#endif // NWNX_ARELITH_STEALTH_CGGAMEOBJECTARRAY_HPP_