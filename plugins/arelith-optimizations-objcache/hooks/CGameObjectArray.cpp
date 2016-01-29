#include "CGameObjectArray.hpp"

#include "hooks/CGameObjectArray__AddInternalObject.hpp"
#include "hooks/CGameObjectArray__AddObjectAtPos.hpp"
#include "hooks/CGameObjectArray__Delete__0.hpp"
#include "hooks/CGameObjectArray__Delete__1.hpp"
#include "hooks/CGameObjectArray__GetGameObject.hpp"

Hooks::CGameObjectArray::GhettoHashmap Hooks::CGameObjectArray::g_objectMap;

Hooks::CGameObjectArray::GhettoHashmap::GhettoHashmap()
{
    for (size_t i = 0; i < BUCKET_SIZE; ++i)
    {
        m_map[i].reserve(10); // Surely we won't have more than ten collisions. Probably. PLEASE.
    }
}

CGameObject* Hooks::CGameObjectArray::GhettoHashmap::Find(const uint32_t id)
{
    for (auto& elem : m_map[id % BUCKET_SIZE])
    {
        if (elem.m_objId == id)
        {
            return elem.m_obj;
        }
    }

    return nullptr;
}

void Hooks::CGameObjectArray::GhettoHashmap::Set(const uint32_t id, CGameObject* obj)
{
    auto& bucket = m_map[id % BUCKET_SIZE];

    for (auto& elem : bucket)
    {
        if (elem.m_objId == id)
        {
            elem.m_obj = obj;
            return;
        }
    }

    bucket.push_back({id, obj});
}

void Hooks::CGameObjectArray::GhettoHashmap::Remove(const uint32_t id)
{
    auto& bucket = m_map[id % BUCKET_SIZE];
    auto elem = std::find_if(bucket.begin(), bucket.end(), [id](auto& elem) -> bool { return elem.m_objId == id; });

    if (elem != bucket.end())
    {
        bucket.erase(elem);
    }
}

void Hooks::CGameObjectArray::Hook()
{
    Hooks::CGameObjectArray__AddInternalObject::Hook();
    Hooks::CGameObjectArray__AddObjectAtPos::Hook();
    Hooks::CGameObjectArray__Delete__0::Hook();
    Hooks::CGameObjectArray__Delete__1::Hook();
    Hooks::CGameObjectArray__GetGameObject::Hook();
}

void Hooks::CGameObjectArray::Unhook()
{
    Hooks::CGameObjectArray__AddInternalObject::Unhook();
    Hooks::CGameObjectArray__AddObjectAtPos::Unhook();
    Hooks::CGameObjectArray__Delete__0::Unhook();
    Hooks::CGameObjectArray__Delete__1::Unhook();
    Hooks::CGameObjectArray__GetGameObject::Unhook();
}