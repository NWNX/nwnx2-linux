#include "NWNXArelithProfiler.hpp"
#include "ProfilingHandler.hpp"

unsigned short NWNXArelithProfiler::m_serverId;
std::string NWNXArelithProfiler::m_username;
std::string NWNXArelithProfiler::m_password;
std::string NWNXArelithProfiler::m_dbName;
std::string NWNXArelithProfiler::m_host;
unsigned int NWNXArelithProfiler::m_port;

NWNXArelithProfiler::NWNXArelithProfiler()
{
    confKey = "ARELITH_PROFILER";
}

NWNXArelithProfiler::~NWNXArelithProfiler()
{
}

bool NWNXArelithProfiler::OnCreate(gline* config, const char* logDir)
{
    char logBuffer[128];
    sprintf(logBuffer, "%s/nwnx_arelith_profiler.txt", logDir);

    if (!CNWNXBase::OnCreate(config, logBuffer))
        return false;

    Log(0, "NWNX Arelith Profiler loaded \n");
    Log(0, "http://www.arelith.com       \n");
    Log(0, "(c) Scholar Midnight 2015    \n");
    Log(0, "---------------------------- \n");

    // Parse the config file to locate any script registrations.
    if (nwnxConfig->exists(confKey)) 
    {
        const std::string serverId = (*nwnxConfig)[confKey]["server_id"];
        m_serverId = serverId.empty() ? 0 : std::stoi(serverId.c_str());
        m_username = (*nwnxConfig)[confKey]["db_username"];
        m_password = (*nwnxConfig)[confKey]["db_password"];
        m_dbName   = (*nwnxConfig)[confKey]["db_name"];
        m_host     = (*nwnxConfig)[confKey]["db_host"];
        const std::string port     = (*nwnxConfig)[confKey]["db_port"];
        m_port = port.empty() ? 0 : std::stoi(port.c_str());
        m_profilingHandler = new ProfilingHandler(this);
        return true;
    }

    return false;
}

char* NWNXArelithProfiler::OnRequest(char* gameObject, char* request, char* params)
{
    return nullptr;
}

unsigned short NWNXArelithProfiler::serverId()
{
    return m_serverId;
}

std::string NWNXArelithProfiler::username()
{
    return m_username;
}

std::string NWNXArelithProfiler::password()
{
    return m_password;
}

std::string NWNXArelithProfiler::dbName()
{
    return m_dbName;
}

std::string NWNXArelithProfiler::host()
{
    return m_host;
}

unsigned int NWNXArelithProfiler::port()
{
    return m_port;
}