#include "MySQLHandler.hpp"
#include "MainLoopHook.hpp"
#include <sstream>
#include <vector>

MySQLHandler::MySQLHandler(ProfilingHandler* parent, const std::string& username, const std::string& pw, const std::string& db, 
    const std::string& host, const unsigned int port)
    : m_connection{nullptr}, m_parent{parent}, m_username{username}, m_password{pw}, m_dbName{db}, m_host{host}, m_port{port}, m_failed{false}
{
    mysql_library_init(0, nullptr, nullptr);
    connect();
}

MySQLHandler::~MySQLHandler()
{
    if (m_connection != nullptr)
    {
        mysql_close(m_connection);
    }
}

// The timeline of this function is:
//     - Retrieves all the stored script data for the provided server.
//     - Aggregates it.
//     - Does the same for pathing data.
//     - Generates a set in perf_archive_sets associated with a timeframe, from
//       the lowest to the highest timestamp of scripts.
//     - Inserts the aggregated data into perf_archives_aggscripts, associated with
//       the generated set in perf_archive_sets.
//     - Same for pathing data into
//     - Clears perf_snapshots_scripts of all scripts matching the server ID.
//     - Same for perf_snapshots_pathing_intraarea.
//     - Clears perf_snapshots of all snapshots matching the server ID.
void MySQLHandler::archiveOldData(const unsigned short serverId)
{
    if (m_failed)
    {
        connect();

        if (m_failed)
        {
            return;
        }
    }

    // ----------------------------------------
    // Gather historical snapshot script data.
    // ----------------------------------------

    std::stringstream ss;

    ss << "SELECT ScriptName, "
                 "SUM(Cycles), "
                 "SUM(Calls) "
          "FROM   perf_snapshots_scripts "
                 "INNER JOIN perf_snapshots "
                 "ON perf_snapshots_scripts.perf_snapshots_ID=perf_snapshots.ID "
          "WHERE  perf_snapshots.perf_servers_ID=" << serverId << " "
          "GROUP  BY ScriptName "
          "ORDER  BY Cycles DESC ";

    std::string query = ss.str();

    if (mysql_query(m_connection, query.c_str()))
    {
        m_failed = true;
        m_parent->log(2, "Query failed: '%s' because '%s'.\n", query.c_str(), mysql_error(m_connection));
        return;
    }
    
    struct AggScriptFormatStruct
    {
        unsigned long long totalCycles;
        unsigned long long totalCalls;
    };

    std::unordered_map<std::string, AggScriptFormatStruct> aggregatedScriptData;
    MYSQL_RES* result = mysql_store_result(m_connection);
    MYSQL_ROW row = mysql_fetch_row(result);

    if (result == nullptr || row == nullptr)
    {        
        m_parent->log(2, "Failed to retrieve the historical script data because '%s'. This is most likely because there was no stored historical script data.\n", mysql_error(m_connection));
    }
    else
    {
        while (row != nullptr)
        {
            auto& val = aggregatedScriptData[std::string{row[0]}];
            
            try
            {
                val.totalCycles = std::stoull(row[1]);
            }
            catch (const std::out_of_range& ex)
            {
                val.totalCycles = 0;
                m_parent->log(2, "Failed to capture total cycles when archiving old script data because '%s' -- using '0'.\n", ex.what());
            }

            try
            {
                val.totalCalls = std::stoul(row[2]);
            }
            catch (const std::out_of_range& ex)
            {
                val.totalCalls = 0;
                m_parent->log(2, "Failed to capture total calls when archiving old script data because '%s' -- using '0'.\n", ex.what());
            }

            row = mysql_fetch_row(result);
        }
    }
    
    // ----------------------------------------------
    // End gathering historical snapshot script data.
    // ----------------------------------------------

    if (result != nullptr)
    {
        mysql_free_result(result);
        result = nullptr;
    }

    ss.str(std::string());
    ss.clear();

    // ---------------------------------------
    // Gather historical snapshot pathing data
    // ---------------------------------------

    ss << "SELECT AreaName, "
                 "SUM(Cycles) "
          "FROM   perf_snapshots_pathing_intraarea "
                 "INNER JOIN perf_snapshots "
                 "ON perf_snapshots_pathing_intraarea.perf_snapshots_ID=perf_snapshots.ID "
          "WHERE  perf_snapshots.perf_servers_ID=" << serverId << " "
          "GROUP  BY AreaName "
          "ORDER  BY Cycles DESC ";
          
    query = ss.str();

    if (mysql_query(m_connection, query.c_str()))
    {
        m_failed = true;
        m_parent->log(2, "Query failed: '%s' because '%s'.\n", query.c_str(), mysql_error(m_connection));
        return;
    }
    
    std::unordered_map<std::string, unsigned long long> aggregatedPathingData;
    result = mysql_store_result(m_connection);
    row = mysql_fetch_row(result);

    if (result == nullptr || row == nullptr)
    {        
        m_parent->log(2, "Failed to retrieve the historical path data because '%s'. This is most likely because there was no stored historical path data.\n", mysql_error(m_connection));
    }
    else
    {
        while (row != nullptr)
        {
            auto& val = aggregatedPathingData[std::string{row[0]}];
            
            try
            {
                val = std::stoull(row[1]);
            }
            catch (const std::out_of_range& ex)
            {
                val = 0;
                m_parent->log(2, "Failed to capture total cycles when archiving old pathing data because '%s' -- using '0'.\n", ex.what());
            }

            row = mysql_fetch_row(result);
        }
    }

    // --------------------------------------------
    // End gathering historical snapshot area data.
    // --------------------------------------------

    if (result != nullptr)
    {
        mysql_free_result(result);
        result = nullptr;
    }

    ss.str(std::string());
    ss.clear();

    // ------------------------
    // Determine the set range.
    // ------------------------

    ss << "SELECT MIN(TimeStamp), MAX(TimeStamp) FROM perf_snapshots WHERE perf_servers_ID=" << serverId;
    query = ss.str();

    if (mysql_query(m_connection, query.c_str()))
    {
        m_failed = true;
        m_parent->log(2, "Query failed: '%s' because '%s'.\n", query.c_str(), mysql_error(m_connection));
        return;
    }

    result = mysql_store_result(m_connection);
    row = mysql_fetch_row(result);

    if (result == nullptr || row == nullptr || row[0] == nullptr || row[1] == nullptr)
    {        
        m_failed = true;
        m_parent->log(2, "Failed to retrieve the timestamps from perf_snapshots because '%s'.\n", mysql_error(m_connection));

        if (result != nullptr)
        {
            mysql_free_result(result);
        }

        return;
    }

    char* setStart = row[0];
    char* setEnd = row[1];

    // ------------------------------
    // End determining the set range.
    // ------------------------------

    mysql_free_result(result);
    result = nullptr;
    ss.str(std::string());
    ss.clear();

    // ---------------
    // Insert the set.
    // ---------------

    ss << "INSERT INTO perf_archive_sets(perf_servers_ID, SetStart, SetEnd) VALUES(" << serverId << ", '" << setStart << "', '" << setEnd << "')";
    query = ss.str();

    if (mysql_query(m_connection, query.c_str()))
    {
        m_failed = true;
        m_parent->log(2, "Query failed: '%s' because '%s'.\n", query.c_str(), mysql_error(m_connection));
        return;
    }

    // ----------------------
    // End inserting the set.
    // ----------------------

    ss.str(std::string());
    ss.clear();

    // ----------------------------------
    // Retrieve the last inserted Set ID.
    // ----------------------------------

    ss << "SELECT MAX(ID) FROM perf_archive_sets WHERE perf_servers_ID=" << serverId;
    query = ss.str();

    if (mysql_query(m_connection, query.c_str()))
    {
        m_failed = true;
        m_parent->log(2, "Query failed: '%s' because '%s'.\n", query.c_str(), mysql_error(m_connection));
        return;
    }

    result = mysql_store_result(m_connection);
    row = mysql_fetch_row(result);

    if (result == nullptr || row == nullptr || row[0] == nullptr)
    {        
        m_failed = true;
        m_parent->log(2, "Failed to retrieve the transaction ID of the previous set because '%s'.\n", mysql_error(m_connection));

        if (result != nullptr)
        {
            mysql_free_result(result);
        }

        return;
    }

    const int setId = std::stoi(row[0]);

    // ----------------------------------------
    // End retrieving the last inserted Set ID.
    // ----------------------------------------

    mysql_free_result(result);
    result = nullptr;
    ss.str(std::string());
    ss.clear();

    // -------------------------------
    // Insert script data into the DB.
    // -------------------------------

    if (!aggregatedScriptData.empty())
    {
        // Then store the snapshot script info.
        ss << "INSERT INTO perf_archive_aggscripts(perf_archive_sets_ID, ScriptName, TotalCycles, TotalCalls) VALUES";

        for (const auto& elem : aggregatedScriptData)
        {
            ss << "(" << setId << ", '" << elem.first << "', " << elem.second.totalCycles << ", " << elem.second.totalCalls << "), ";
        }

        // Replace the last comma with null termination.
        query = ss.str();
        *(query.end() - 2) = '\0';   

        if (mysql_query(m_connection, query.c_str()))
        {
            m_failed = true;
            m_parent->log(2, "Query failed: '%s' because '%s'.\n", query.c_str(), mysql_error(m_connection));
            return;
        }
    }

    // --------------------------------------
    // End inserting script data into the DB.
    // --------------------------------------
    
    ss.str(std::string());
    ss.clear();

    // ----------------------------------------------
    // Remove the historical script data from the DB.
    // ----------------------------------------------

    ss << "DELETE scripts.*"
          "FROM   perf_snapshots_scripts scripts "
                 "INNER JOIN perf_snapshots snapshots "
                 "ON scripts.perf_snapshots_ID=snapshots.ID "
          "WHERE  snapshots.perf_servers_ID=" << serverId;
    query = ss.str();

    if (mysql_query(m_connection, query.c_str()))
    {
        m_failed = true;
        m_parent->log(2, "Query failed: '%s' because '%s'.\n", query.c_str(), mysql_error(m_connection));
        return;
    }

    // ----------------------------------------------------
    // End removing the historical script data from the DB.
    // ----------------------------------------------------

    ss.str(std::string());
    ss.clear();

    // -----------------------------
    // Insert area data into the DB.
    // -----------------------------

    if (!aggregatedPathingData.empty())
    {
        // Then store the snapshot script info.
        ss << "INSERT INTO perf_archive_aggpathing_intraarea(perf_archive_sets_ID, AreaName, TotalCycles) VALUES";

        for (const auto& elem : aggregatedPathingData)
        {
            ss << "(" << setId << ", '" << elem.first << "', " << elem.second << "), ";
        }

        // Replace the last comma with null termination.
        query = ss.str();
        *(query.end() - 2) = '\0';   

        if (mysql_query(m_connection, query.c_str()))
        {
            m_failed = true;
            m_parent->log(2, "Query failed: '%s' because '%s'.\n", query.c_str(), mysql_error(m_connection));
            return;
        }
    }

    // ------------------------------------
    // End inserting area data into the DB.
    // ------------------------------------

    ss.str(std::string());
    ss.clear();

    // --------------------------------------------
    // Remove the historical area data from the DB.
    // --------------------------------------------

    ss << "DELETE pathing.* "
          "FROM   perf_snapshots_pathing_intraarea pathing "
                 "INNER JOIN perf_snapshots snapshots "
                 "ON pathing.perf_snapshots_ID=snapshots.ID "
          "WHERE  snapshots.perf_servers_ID=" << serverId;
    query = ss.str();

    if (mysql_query(m_connection, query.c_str()))
    {
        m_failed = true;
        m_parent->log(2, "Query failed: '%s' because '%s'.\n", query.c_str(), mysql_error(m_connection));
        return;
    }

    // --------------------------------------------------
    // End removing the historical area data from the DB.
    // --------------------------------------------------

    ss.str(std::string());
    ss.clear();

    // --------------------------------------------
    // Remove the historical snapshots from the DB.
    // --------------------------------------------

    ss << "DELETE FROM perf_snapshots WHERE perf_servers_ID=" << serverId;
    query = ss.str();

    if (mysql_query(m_connection, query.c_str()))
    {
        m_failed = true;
        m_parent->log(2, "Query failed: '%s' because '%s'.\n", query.c_str(), mysql_error(m_connection));
        return;
    }

    // --------------------------------------------------
    // End removing the historical snapshots from the DB.
    // --------------------------------------------------

    m_parent->log(2, "Archived the historical data.\n");
}

// The timeline of this function is:
//     - Inserts a snapshot into perf_snapshots with the data provided in the first argument.
//     - Inserts multiple records as provided in the second argument into perf_snapshots_scripts,
//       and associates it with the previously-generated snapshot.
//     - Does the same for any intra-area pathing data.
void MySQLHandler::storeData(const SnapshotDataStruct* snapshotData, 
                             const std::unordered_map<std::string, ScriptPerfInfoStruct>* scriptData,
                             const std::unordered_map<std::string, PathingPerfInfoStruct>* pathingData)
{
    if (m_failed)
    {
        connect();

        if (m_failed)
        {
            return;
        }
    }

    std::stringstream ss;

    // First, store the snapshot.
    ss << "INSERT INTO perf_snapshots(perf_servers_ID, MainLoopTicks, MainLoopExecutionCycles, LogOutputExecutionCycles, PlayerCount, DMCount)"
       << "VALUES(" << snapshotData->serverID << ", " << snapshotData->mainLoopTicks << ", " << snapshotData->mainLoopCycles << ", " 
       << snapshotData->logCycles << ", " << snapshotData->playerCount << ", " << snapshotData->dmCount << ")";
    std::string query = ss.str();

    if (mysql_query(m_connection, query.c_str()))
    {
        m_failed = true;
        m_parent->log(2, "Query failed: '%s' because '%s'.\n", query.c_str(), mysql_error(m_connection));
        return;
    }

    // Reset the stringstream.
    ss.str(std::string());
    ss.clear();

    // Get the ID of the record that we just inserted.
    // This might generate a race condition if another thread/process/user is inserting at the same time for the same server.
    // Thankfully, that shouldn't ever happen.
    ss << "SELECT MAX(ID) FROM perf_snapshots WHERE perf_servers_id=" << snapshotData->serverID;
    query = ss.str();

    if (mysql_query(m_connection, query.c_str()))
    {
        m_failed = true;
        m_parent->log(2, "Query failed: '%s' because '%s'.\n", query.c_str(), mysql_error(m_connection));
        return;
    }

    MYSQL_RES* result = mysql_store_result(m_connection);
    MYSQL_ROW row = mysql_fetch_row(result);

    if (result == nullptr || row == nullptr || row[0] == nullptr)
    {        
        m_failed = true;
        m_parent->log(2, "Failed to retrieve the transaction ID of the previous snapshot because '%s'.\n", mysql_error(m_connection));

        if (result != nullptr)
        {
            mysql_free_result(result);
        }

        return;
    }

    mysql_free_result(result);
    result = nullptr;
    const int snapshotId = std::stoi(row[0]);

    // Reset the stringstream.
    ss.str(std::string());
    ss.clear();

    if (!scriptData->empty())
    {
        // Then store the snapshot script info.
        ss << "INSERT INTO perf_snapshots_scripts(perf_snapshots_ID, ScriptName, Cycles, Calls) VALUES";

        for (const auto& elem : *scriptData)
        {
            ss << "(" << snapshotId << ", '" << elem.first << "', " << elem.second.totalExecutionCycles << ", " << elem.second.totalCalls << "), ";
        }

        // Replace the last comma with null termination.
        query = ss.str();
        *(query.end() - 2) = '\0';    

        if (mysql_query(m_connection, query.c_str()))
        {
            m_failed = true;
            m_parent->log(2, "Query failed: '%s' because '%s'.\n", query.c_str(), mysql_error(m_connection));
            return;
        }
    }

    // Reset the stringstream.
    ss.str(std::string());
    ss.clear();

    if (!pathingData->empty())
    {
        // Then store the snapshot script info.
        ss << "INSERT INTO perf_snapshots_pathing_intraarea(perf_snapshots_ID, AreaName, Cycles) VALUES";

        for (const auto& elem : *pathingData)
        {
            ss << "(" << snapshotId << ", '" << elem.first << "', " << elem.second.totalExecutionCycles << "), ";
        }

        // Replace the last comma with null termination.
        query = ss.str();
        *(query.end() - 2) = '\0';   

        if (mysql_query(m_connection, query.c_str()))
        {
            m_failed = true;
            m_parent->log(2, "Query failed: '%s' because '%s'.\n", query.c_str(), mysql_error(m_connection));
            return;
        }
    }
}

bool MySQLHandler::failed() const
{
    return m_failed;
}

void MySQLHandler::connect()
{
    if (m_connection != nullptr)
    {
        m_parent->log(2, "Closing current MySQL connection.\n");
        mysql_close(m_connection);
    }

    m_parent->log(2, "Initialising MySQL context.\n");
    m_connection = mysql_init(nullptr);

    if (mysql_real_connect(m_connection, m_host.c_str(), 
                                         m_username.c_str(), m_password.c_str(), 
                                         m_dbName.c_str(), m_port, 
                                         nullptr, 0) == m_connection)
    {
        m_failed = false;
        m_parent->log(2, "Connected to '%s:%u' with login details '%s:%s' on db '%s'.\n",
            m_host.c_str(), m_port, m_username.c_str(), m_password.c_str(), m_dbName.c_str(), mysql_error(m_connection));
    }
    else
    {
        m_failed = true;
        m_parent->log(2, "Failed to connect to '%s:%u' with login details '%s:%s' on db '%s' because '%s'.\n",
            m_host.c_str(), m_port, m_username.c_str(), m_password.c_str(), m_dbName.c_str(), mysql_error(m_connection));
    }
}