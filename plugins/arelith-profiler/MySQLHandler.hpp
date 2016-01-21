#ifndef NWNX_MYSQL_HANDLER_HPP_
#define NWNX_MYSQL_HANDLER_HPP_

#include "ProfilingHandler.hpp"
#include "mysql.h"
#include <string>
#include <unordered_map>

class MySQLHandler
{
public:
    MySQLHandler(ProfilingHandler* parent, const std::string& username, const std::string& pw, const std::string& db,
        const std::string& host = "localhost", const unsigned int port = 0);
    ~MySQLHandler();

    void archiveOldData(const unsigned short serverId);
    void storeData(const SnapshotDataStruct* snapshotData, 
                   const std::unordered_map<std::string, ScriptPerfInfoStruct>* scriptData,
                   const std::unordered_map<std::string, PathingPerfInfoStruct>* pathingData);
    bool failed() const;

private:
    void connect();

    MYSQL* m_connection;
    ProfilingHandler* m_parent;
    const std::string m_username;
    const std::string m_password;
    const std::string m_dbName;
    const std::string m_host;
    const unsigned int m_port;
    bool m_failed;
};

#endif // NWNX_MYSQL_HANDLER_HPP_