#include "IPCManager.h"

void IPCManager::ServiceRegisterObjectRequest(const std::string& name, std::function<bool (CGameObject *, char *, nwobjid &)> func)
{
    ServiceRegister<ServiceObjectRequest>(name, std::move(func));
}

void IPCManager::ServiceRegisterStringRequest(const std::string& name, std::function<bool (CGameObject *, char *, char **)> func)
{
    ServiceRegister<ServiceStringRequest>(name, std::move(func));
}

std::unique_ptr<IPCManager> g_IPCMgr;
