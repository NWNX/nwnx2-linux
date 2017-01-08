#include "ProfilingHandler.hpp"
#include "AllHooks.hpp"
#include "MySQLHandler.hpp"

ProfilingHandler::ProfilingHandler(NWNXArelithProfiler* parent)
    : m_parent(parent)
{    
    m_mainLoopHook = std::make_unique<MainLoopHook>(this);
    m_runScriptHook = std::make_unique<RunScriptHook>(this);
    m_printLogEntryHook = std::make_unique<PrintLogEntryHook>(this);
    m_intraTileDFSHook = std::make_unique<IntraTileDFSHook>(this);   
    m_mySqlHandler = std::make_unique<MySQLHandler>(this, NWNXArelithProfiler::username(), 
        NWNXArelithProfiler::password(), NWNXArelithProfiler::dbName(), 
        NWNXArelithProfiler::host(), NWNXArelithProfiler::port());
    m_mySqlHandler->archiveOldData(NWNXArelithProfiler::serverId());
}

ProfilingHandler::~ProfilingHandler()
{
}

void ProfilingHandler::storeData(const SnapshotDataStruct* snapshotData, 
                                 const std::unordered_map<std::string, ScriptPerfInfoStruct>* scriptData,
                                 const std::unordered_map<std::string, PathingPerfInfoStruct>* pathingData) const
{
    m_mySqlHandler->storeData(snapshotData, scriptData, pathingData);
}