#pragma once

#include "typedef.h"
#include "Signal.h"
#include "Service.h"

#include <unordered_map>
#include <memory>

class CGameObject;

using ServiceObjectRequest = Service<CGameObject*, char*, nwobjid&>;
using ServiceStringRequest = Service<CGameObject*, char*, char**>;

class IPCManager {
    using IPCMap = std::unordered_map<std::string, detail::ServiceSignalBase*>;
    IPCMap signals;
    IPCMap services;
public:
    template <typename T>
    void ServiceRegister(const std::string& service, typename T::function_type func) {
        auto it = services.emplace(service, new T(std::move(func)));
        if(!it.second) {
            T* s = reinterpret_cast<T*>(it.first->second);
            s->SetFunction(std::move(func));
        }
    }

    // Wrappers around ServiceRegister.
    void ServiceRegisterObjectRequest(const std::string &name, std::function<bool(CGameObject*, char*, nwobjid&)> func);
    void ServiceRegisterStringRequest(const std::string &name, std::function<bool(CGameObject*, char*, char**)> func);

    // Call a serivce.  If service is not available false is returned.
    template<typename... Args>
    bool ServiceCall(const std::string& name, Args... args) {
        const size_t hash = typeid(Service<Args...>).hash_code();
        auto it = services.find(name);
        if(it == services.end() || it->second->hash() != hash) {
            return false;
        }
        auto temp = reinterpret_cast<Service<Args...>*>(it->second);
        temp->Call(args...);
        return true;
    }

    bool ServiceExists(const std::string& name) {
        return services.find(name) != services.end();
    }

    // IPCManager owns the signal.
    template <typename T>
    T* SignalRegister(const std::string& signal, bool abortable=false, std::function<void()> init = std::function<void()>())
    {
        auto it = signals.insert({ signal, new T(abortable, std::move(init)) });
        return reinterpret_cast<T*>(it.first->second);
    }

    // Connect to a signal.  Probably a better way to do this than having observers pass in a string ID.
    template <typename T>
    bool Connect(const std::string& signal, const char* observer, typename T::function_type f)
    {
        auto it = signals.find(signal);
        const size_t hash = typeid(T).hash_code();
        if(it == signals.end() || it->second->hash() != hash) {
            return false;
        }
        auto temp = reinterpret_cast<T*>(it->second);
        temp->connect(observer, f);
        return true;
    }

    // Disconnect to a signal.  Probably a better way to do this than having observers pass in a string ID.
    template <typename T>
    bool Disconnect(const std::string& signal, const char* observer)
    {
        auto it = signals.find(signal);
        const size_t hash = typeid(T).hash_code();
        if(it == signals.end() || it->second->hash() != hash) {
            return false;
        }
        auto temp = reinterpret_cast<T*>(it->second);
        return temp->disconnect(observer);
    }
};

// Created/Set in nwnx2lib.cpp
extern std::unique_ptr<IPCManager> g_IPCMgr;
