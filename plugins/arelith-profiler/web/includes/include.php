<?php
function get_server_data()
{
    $serverQuery = mysql_query("SELECT *
                                FROM   perf_servers
                                ORDER  BY ID ASC ");
    
    $serverData = array();    
    while ($row = mysql_fetch_assoc($serverQuery))
    {
        $serverID = $row['ID'];
        $serverData[$serverID]['ID'] = $serverID;
        $serverData[$serverID]['Name'] = $row['Name'];
    }   
    
    return $serverData;
}

function get_snapshot_long_term_data($serverId)
{
    $snapshotLongTermQuery = mysql_query("SELECT ID,
                                                 MainLoopTicks,
                                                 PlayerCount,
                                                 DMCount,
                                                 TimeStamp
                                          FROM   perf_snapshots
                                          WHERE  perf_servers_id = " . $serverId . "
                                          ORDER  BY ID DESC");

    $longTermData = array();
    while ($row = mysql_fetch_assoc($snapshotLongTermQuery))
    {
        $id = $row['ID'];
        $longTermData[$id]['ID'] = $id;
        $longTermData[$id]['MainLoopTicks'] = $row['MainLoopTicks'];
        $longTermData[$id]['PlayerCount'] = $row['PlayerCount'];
        $longTermData[$id]['DMCount'] = $row['DMCount'];
        $longTermData[$id]['TimeStamp'] = $row['TimeStamp'];
    }
    
    return $longTermData;
}

function get_snapshot_short_term_data($serverId, $longTermData)
{
    $snapshotShortTermQuery = mysql_query("SELECT ID,
                                                  perf_servers_ID, 
                                                  MainLoopExecutionCycles,
                                                  LogOutputExecutionCycles
                                           FROM   perf_snapshots
                                           WHERE  perf_servers_id = " . $serverId . "
                                           ORDER  BY ID DESC
                                           LIMIT  50");
                                          
    $shortTermData = array();
    while ($row = mysql_fetch_assoc($snapshotShortTermQuery))
    {
        $id = $row['ID'];
        $shortTermData[$id]['ID'] = $id;
        $shortTermData[$id]['perf_servers_ID'] = $row['perf_servers_ID'];
        $shortTermData[$id]['MainLoopTicks'] = $longTermData[$id]['MainLoopTicks'];
        $shortTermData[$id]['MainLoopExecutionCycles'] = $row['MainLoopExecutionCycles'];
        $shortTermData[$id]['LogOutputExecutionCycles'] = $row['LogOutputExecutionCycles'];
        $shortTermData[$id]['PlayerCount'] = $longTermData[$id]['PlayerCount'];
        $shortTermData[$id]['DMCount'] = $longTermData[$id]['DMCount'];
        $shortTermData[$id]['TimeStamp'] = $longTermData[$id]['TimeStamp'];

        $scriptTimeQuery = mysql_query("SELECT COALESCE(
                                            (SELECT SUM(Cycles)
                                             FROM perf_snapshots_scripts
                                             WHERE perf_snapshots_id = " . $id . ")
                                             , 0) as TotalCycles");
        $scriptTime = mysql_fetch_assoc($scriptTimeQuery);
        $shortTermData[$id]['ScriptCycles'] = $scriptTime['TotalCycles'];

        $intraPathTimeQuery = mysql_query("SELECT COALESCE(
                                                (SELECT SUM(Cycles)
                                                 FROM perf_snapshots_pathing_intraarea
                                                 WHERE perf_snapshots_id = " . $id . ")
                                             , 0) as TotalCycles");
        $intraPathTime = mysql_fetch_assoc($intraPathTimeQuery);
        $shortTermData[$id]['IntraPathCycles'] = $intraPathTime['TotalCycles'];

        $shortTermData[$id]['UnknownTime'] = $row['MainLoopExecutionCycles'] - 
                                                 $row['LogOutputExecutionCycles'] -
                                                 $scriptTime['TotalCycles'] -
                                                 $intraPathTime['TotalCycles'];
    }
    
    return $shortTermData;
}

function echo_snapshot_header()
{
    echo "<tr>";
    echo "<th>Snapshot ID</th>";
    echo "<th>Server ID</th>";
    echo "<th>MLoop Ticks</th>";
    echo "<th>MLoop Time</th>";
    echo "<th>Player Count</th>";
    echo "<th>DM Count</th>";
    echo "<th>Timestamp</th>";
    echo "<th>Script Time</th>";
    echo "<th>Path Time</th>";
    echo "<th>Log Time</th>";
    echo "<th>Unknown Time</th>";
    echo "</tr>";
}

function echo_snapshot_body($data)
{
    echo "<tr>";
    echo "<td>" . $data['ID'] . "</td>";
    echo "<td>" . $data['perf_servers_ID'] . "</td>";
    echo "<td>" . $data['MainLoopTicks'] . "</td>";
    echo "<td>" . $data['MainLoopExecutionCycles'] . "</td>";
    echo "<td>" . $data['PlayerCount'] . "</td>";
    echo "<td>" . $data['DMCount'] . "</td>";
    echo "<td>" . $data['TimeStamp'] . "</td>";
    echo "<td>" . $data['ScriptCycles'] . "</td>";
    echo "<td>" . $data['IntraPathCycles'] . "</td>";
    echo "<td>" . $data['LogOutputExecutionCycles'] . "</td>";
    echo "<td>" . $data['UnknownTime'] . "</td>";
    echo "</tr>";
}

function get_snapshot_aggscript_data($serverId)
{
    $scriptQuery = mysql_query("SELECT ScriptName,
                                       SUM(Cycles),
                                       SUM(Calls)
                                FROM   perf_snapshots_scripts
                                       INNER JOIN (SELECT DISTINCT ID
                                             FROM   perf_snapshots
                                             WHERE  perf_servers_id = " . $serverId . "
                                             ORDER  BY ID DESC
                                             LIMIT  50) AS snapshot
                                         ON perf_snapshots_id = snapshot.ID
                                GROUP  BY ScriptName
                                ORDER  BY SUM(Cycles) DESC");

    $scriptData = array();                    
    while ($row = mysql_fetch_assoc($scriptQuery))
    {
        $scriptName = $row['ScriptName'];
        $scriptData[$scriptName]['ScriptName'] = $scriptName;
        $scriptData[$scriptName]['TotalCycles'] = $row['SUM(Cycles)'];
        $scriptData[$scriptName]['TotalCalls'] = $row['SUM(Calls)'];
    }
    return $scriptData;
}

function echo_snapshot_aggscript_header()
{
    echo "<tr>";
    echo "<th>Script Name</th>";
    echo "<th>Total Cycles</th>";
    echo "<th>Totals Calls</th>";
    echo "</tr>";
}

function echo_snapshot_aggscript_body($data)
{
    echo "<tr>";
    echo "<td>" . $data['ScriptName'] . "</td>";
    echo "<td>" . $data['TotalCycles'] . "</td>";
    echo "<td>" . $data['TotalCalls'] . "</td>";
    echo "</tr>";
}

function get_snapshot_script_data($serverId)
{
}

function echo_snapshot_script_header()
{
    echo "<tr>";
    echo "<th>Entry ID</th>";
    echo "<th>Snapshot ID</th>";
    echo "<th>Script Name</th>";
    echo "<th>Cycles</th>";
    echo "<th>Calls</th>";
    echo "</tr>";
}

function echo_snapshot_script_body($data)
{
    echo "<tr>";
    echo "<td>" . $data['ID'] . "</td>";
    echo "<td>" . $data['perf_snapshots_ID'] . "</td>";
    echo "<td>" . $data['ScriptName'] . "</td>";
    echo "<td>" . $data['Cycles'] . "</td>";
    echo "<td>" . $data['Calls'] . "</td>";
    echo "</tr>";
}
    
function get_archive_set_data($serverId)
{
    $archivedSetsQuery = mysql_query("SELECT *
                                      FROM   perf_archive_sets
                                      WHERE  perf_servers_id = " . $serverId . "
                                      ORDER  BY ID DESC
                                      LIMIT  2"); 
                                            
    $archivedSets = array();
    while ($row = mysql_fetch_assoc($archivedSetsQuery))
    {
        $setId = $row['ID'];
        $archivedSets[$setId]['ID'] = $setId;
        $archivedSets[$setId]['perf_servers_ID'] = $row['perf_servers_ID'];
        $archivedSets[$setId]['SetStart'] = $row['SetStart'];
        $archivedSets[$setId]['SetEnd'] = $row['SetEnd'];
    }  
    return $archivedSets;
}
    
function echo_archive_set_header()
{
    echo "<tr>";
    echo "<th>Set ID</th>";
    echo "<th>Server ID</th>";
    echo "<th>Set Start</th>";
    echo "<th>Set End</th>";
    echo "</tr>";
}

function echo_archive_set_body($data)
{
    echo "<tr>";
    echo "<td>" . $data['ID'] . "</td>";
    echo "<td>" . $data['perf_servers_ID'] . "</td>";
    echo "<td>" . $data['SetStart'] . "</td>";
    echo "<td>" . $data['SetEnd'] . "</td>";
    echo "</tr>";
}

function get_archive_aggscript_data($serverId)
{
    $archivedScriptsQuery = mysql_query("SELECT *
                                         FROM   perf_archive_aggscripts
                                                INNER JOIN (SELECT DISTINCT ID
                                                            FROM   perf_archive_sets
                                                            WHERE  perf_servers_id = " . $serverId . "
                                                            ORDER  BY ID DESC
                                                            LIMIT  2) sets
                                                        ON perf_archive_sets_id = sets.ID
                                         ORDER  BY perf_archive_sets_id DESC,
                                                   TotalCycles DESC");
                                                
    $archivedScripts = array();  
    while ($row = mysql_fetch_assoc($archivedScriptsQuery))
    {
        $setId = $row['perf_archive_sets_ID'];
        $scriptName = $row['ScriptName'];
        $archivedScripts[$setId][$scriptName]['ID'] = $row['ID'];
        $archivedScripts[$setId][$scriptName]['perf_archive_sets_ID'] = $setId;
        $archivedScripts[$setId][$scriptName]['ScriptName'] = $scriptName;
        $archivedScripts[$setId][$scriptName]['TotalCycles'] = $row['TotalCycles'];
        $archivedScripts[$setId][$scriptName]['TotalCalls'] = $row['TotalCalls'];
    }
    return $archivedScripts;
}

function echo_archive_aggscript_header()
{
    echo "<tr>";
    echo "<th>Entry ID</th>";
    echo "<th>Set ID</th>";
    echo "<th>Script Name</th>";
    echo "<th>Total Cycles</th>";
    echo "<th>Total Calls</th>";
    echo "</tr>";
}

function echo_archive_aggscript_body($data)
{
    echo "<tr>";
    echo "<td>" . $data['ID'] . "</td>";
    echo "<td>" . $data['perf_archive_sets_ID'] . "</td>";
    echo "<td>" . $data['ScriptName'] . "</td>";
    echo "<td>" . $data['TotalCycles'] . "</td>";
    echo "<td>" . $data['TotalCalls'] . "</td>";
    echo "</tr>";
}

function get_snapshot_aggpathing_intraarea_data($serverId)
{
    $pathQuery = mysql_query("SELECT AreaName,
                                     SUM(Cycles)
                              FROM   perf_snapshots_pathing_intraarea
                                     INNER JOIN (SELECT DISTINCT ID
                                           FROM   perf_snapshots
                                           WHERE  perf_servers_id = " . $serverId . "
                                           ORDER  BY ID DESC
                                           LIMIT  50) AS snapshot
                                       ON perf_snapshots_id = snapshot.ID
                              GROUP  BY AreaName
                              ORDER  BY SUM(Cycles) DESC");

    $pathData = array();                    
    while ($row = mysql_fetch_assoc($pathQuery))
    {
        $areaName = $row['AreaName'];
        $pathData[$areaName]['AreaName'] = $areaName;
        $pathData[$areaName]['TotalCycles'] = $row['SUM(Cycles)'];
    }
    return $pathData;
}

function get_archive_aggpathing_intraarea_data($serverId)
{
    $archivePathQuery = mysql_query("SELECT *
                                     FROM   perf_archive_aggpathing_intraarea
                                            INNER JOIN (SELECT DISTINCT ID
                                                        FROM   perf_archive_sets
                                                        WHERE  perf_servers_id = " . $serverId . "
                                                        ORDER  BY ID DESC
                                                        LIMIT  2) sets
                                                    ON perf_archive_sets_id = sets.ID
                                     ORDER  BY perf_archive_sets_id DESC,
                                               TotalCycles DESC ");

    $archivedPathData = array();  
    while ($row = mysql_fetch_assoc($archivePathQuery))
    {
        $setId = $row['perf_archive_sets_ID'];
        $areaName = $row['AreaName'];
        $archivedPathData[$setId][$areaName]['ID'] = $row['ID'];
        $archivedPathData[$setId][$areaName]['perf_archive_sets_ID'] = $setId;
        $archivedPathData[$setId][$areaName]['AreaName'] = $areaName;
        $archivedPathData[$setId][$areaName]['TotalCycles'] = $row['TotalCycles'];
    }
    return $archivedPathData;
}

function echo_snapshot_aggpathing_intraarea_header()
{
    echo "<tr>";
    echo "<th>Area Name</th>";
    echo "<th>Total Cycles</th>";
    echo "</tr>";
}

function echo_snapshot_aggpathing_intraarea_body($data)
{
    echo "<tr>";
    echo "<td>" . $data['AreaName'] . "</td>";
    echo "<td>" . $data['TotalCycles'] . "</td>";
    echo "</tr>";
}

function echo_archive_aggpathing_intraarea_header()
{
    echo "<tr>";
    echo "<th>Entry ID</th>";
    echo "<th>Set ID</th>";
    echo "<th>Area Name</th>";
    echo "<th>Total Cycles</th>";
    echo "</tr>";
}

function echo_archive_aggpathing_intraarea_body($data)
{
    echo "<tr>";
    echo "<td>" . $data['ID'] . "</td>";
    echo "<td>" . $data['perf_archive_sets_ID'] . "</td>";
    echo "<td>" . $data['AreaName'] . "</td>";
    echo "<td>" . $data['TotalCycles'] . "</td>";
    echo "</tr>";
}

function echo_pie_chart($name, $text, $data)
{
    echo "<div id=\"" . $name . "\" style=\"height: 400px; width: 800px;\"></div>";
    
    echo "<script type=\"text/javascript\">
        var " . $name . "_chart = new CanvasJS.Chart(\"" . $name . "\",
        {
            zoomEnabled: true, 
            title:
            {
                text: \"" . $text . "\"
            },
            data:
            [{
                type: \"pie\",
                showInLegend: false,
                dataPoints: 
                [";

                foreach ($data as $key => $value) 
                {
                    echo "{ y: " . $value['TotalCycles'] . ", indexLabel: \"" . $key . "\" },";
                }
                echo "
                ]    
            }]
        });

        " . $name . "_chart.render();
    </script>";
}?>