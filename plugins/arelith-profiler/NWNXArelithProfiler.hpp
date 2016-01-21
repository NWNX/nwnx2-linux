#ifndef NWNX_ARELITH_PROFILER_HPP_
#define NWNX_ARELITH_PROFILER_HPP_

#include "NWNXBase.h"
#include <memory>

class ProfilingHandler;

class NWNXArelithProfiler final : public CNWNXBase
{
public:
    NWNXArelithProfiler();
    virtual ~NWNXArelithProfiler();
    bool OnCreate(gline* config, const char* logDir) override;
    char* OnRequest(char* gameObject, char* request, char* params) override;

    static unsigned short serverId();
    static std::string username();
    static std::string password();
    static std::string dbName();
    static std::string host();
    static unsigned int port();

private:
    ProfilingHandler* m_profilingHandler;
    static unsigned short m_serverId;
    static std::string m_username;
    static std::string m_password;
    static std::string m_dbName;
    static std::string m_host;
    static unsigned int m_port;
};

#endif // NWNX_ARELITH_PROFILER_HPP_