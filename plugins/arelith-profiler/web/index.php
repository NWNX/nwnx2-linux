<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="utf-8">
<title>Arelith Profiling Tool</title>
<link rel="stylesheet" href="includes/style.css" type="text/css">
<script src="includes/canvasjs.js"></script>
<script src="includes/scripts.js"></script>

<?php
    $time = microtime();
    $time = explode(' ', $time);
    $time = $time[1] + $time[0];
    $start = $time;
    
    include 'includes/include.php';

    mysql_connect('localhost', 'arelith_profiler', 'pr0filing@ErryDay');
    mysql_select_db('arelith_profiler'); 
    
    if($_GET["server"])
    {
        define("CURRENT_SERVER", mysql_real_escape_string($_GET["server"]));
    }
    else
    {
        define("CURRENT_SERVER", 1);
    }       

    $serverData = get_server_data();
    $snapshotLongTermData = get_snapshot_long_term_data(CURRENT_SERVER);
    $snapshotShortTermData = get_snapshot_short_term_data(CURRENT_SERVER, $snapshotLongTermData);
    $aggScriptData = get_snapshot_aggscript_data(CURRENT_SERVER);
    $aggAreaPathingData = get_snapshot_aggpathing_intraarea_data(CURRENT_SERVER);
    $archivedSetsData = get_archive_set_data(CURRENT_SERVER);
    $archivedAggScriptData = get_archive_aggscript_data(CURRENT_SERVER);
    $archivedAggAreaPathingData = get_archive_aggpathing_intraarea_data(CURRENT_SERVER);
    
    $time = microtime();
    $time = explode(' ', $time);
    $time = $time[1] + $time[0];
    $finish = $time;
    $total_time = round(($finish - $start), 4);
    echo 'Data retrieved in '.$total_time.' seconds.';
?>

<h2>Server: 
<?php   
    foreach ($serverData as $key => $value) 
    {
        if ($key == CURRENT_SERVER)
        {
            echo "<i>" . $value['Name'] . "</i> ";
        }
        else
        {
            echo "<a href=\"?server=" . $key . "\">" . $value['Name'] . "</a> ";
        }
    }   
?>
</h2> 

<a href="#perf_snapshots">perf_snapshots (most recent 50 snapshots)</a><br>
<a href="#perf_snapshots_aggscripts">perf_snapshots_scripts (aggregated data from the most recent 50 snapshots)</a><br>
<a href="#perf_snapshots_pathing_intraarea">perf_snapshots_pathing_intraarea (aggregated data from the most recent 50 snapshots)</a><br>
<a href="#perf_archive_sets">perf_archive_sets (most recent 2 sets)</a><br>
<a href="#perf_archive_aggscripts">perf_archive_aggscripts (most recent 2 sets)</a><br>
<a href="#perf_archive_aggpathing_intraarea">perf_archive_aggpathing_intraarea (most recent 2 sets)</a><br>

<br>
<hr>

<div id="snapshotsChart" style="height: 250px; width: 75%;"></div>
<script type="text/javascript">
    var snapshotsChart = new CanvasJS.Chart("snapshotsChart",
    {
        zoomEnabled: true, 
        title: 
        {
            text: "Server Performance"
        },
        axisX:
        {
            title: "Time",
        },
        axisY:
        {
            title: "Main Loop Ticks",
        },
        data: 
        [
            {
                type: "area",
                dataPoints: 
                [
                <?php 
                    foreach ($snapshotLongTermData as $key => $value) 
                    {
                        echo "{x: Date.createFromMysql(\"" . $value['TimeStamp'] . "\"), y: " . $value['MainLoopTicks'] . "},";
                    }
                ?>
                ]
            }
        ]
    });

    snapshotsChart.render();
</script>

<div id="playerMetricsChart" style="height: 250px; width: 75%;"></div>
<script type="text/javascript">
    var playerMetricsChart = new CanvasJS.Chart("playerMetricsChart",
    {
        zoomEnabled: true, 
        title: 
        {
            text: "Server Traffic"
        },
        axisX:
        {
            title: "Time",
        },
        axisY:
        {
            title: "Client Count",
        },
        data: 
        [
            {
                type: "area",
                dataPoints: 
                [
                <?php 
                    foreach ($snapshotLongTermData as $key => $value) 
                    {
                        echo "{x: Date.createFromMysql(\"" . $value['TimeStamp'] . "\"), y: " . $value['PlayerCount'] . "},";
                    }
                ?>
                ]
            },
            {
                type: "area",
                dataPoints: 
                [
                <?php 
                    foreach ($snapshotLongTermData as $key => $value) 
                    {
                        echo "{x: Date.createFromMysql(\"" . $value['TimeStamp'] . "\"), y: " . $value['DMCount'] . "},";
                    }
                ?>
                ]
            }
        ]
    });

    playerMetricsChart.render();
</script>

<!-- Snapshots -->
<a name="perf_snapshots">
<h2>perf_snapshots (most recent 50 snapshots) <a href="#">(back to top)</a></h2>
<table border="1">
<?php
    echo_snapshot_header();  
    foreach ($snapshotShortTermData as $key => $value) 
    {
        echo_snapshot_body($value);  
    }
?>
</table>
<br>
<hr>
<!-- Snapshot aggregated script data -->
<a name="perf_snapshots_aggscripts">
<h2>perf_snapshots_scripts (aggregated data from the most recent 50 snapshots) <a href="#">(back to top)</a></h2>
<table border="1">
<?php
    echo_pie_chart("aggscripts_pie_chart", "Script Execution Time", $aggScriptData);
    echo_snapshot_aggscript_header();
    foreach ($aggScriptData as $key => $value) 
    {
        echo_snapshot_aggscript_body($value);
    }   
?>
</table>
<br>
<hr>
<!-- Snapshot aggregated area pathing data -->
<a name="perf_snapshots_pathing_intraarea">
<h2>perf_snapshots_pathing_intraarea (aggregated data from the most recent 50 snapshots) <a href="#">(back to top)</a></h2>
<table border="1">
<?php
    echo_pie_chart("aggareapathing_pie_chart", "Pathing Time", $aggAreaPathingData);
    echo_snapshot_aggpathing_intraarea_header();
    foreach ($aggAreaPathingData as $key => $value) 
    {
        echo_snapshot_aggpathing_intraarea_body($value);
    }   
?>
</table>
<br>
<hr>
<!-- Archived sets -->
<a name="perf_archive_sets"> 
<h2>perf_archive_sets (most recent 2 sets) <a href="#">(back to top)</a></h2>
<table border="1">
<?php
    echo_archive_set_header();
    foreach ($archivedSetsData as $key => $value)
    {
        echo_archive_set_body($value);
    }
?>
</table>
<br>
<hr>
<!-- Aggregated archive set data. -->
<a name="perf_archive_aggscripts">
<h2>perf_archive_aggscripts (most recent 2 sets) <a href="#">(back to top)</a></h2>
<?php 
    foreach ($archivedAggScriptData as $key => $value) 
    {
        echo_pie_chart("archive_aggscripts_pie_chart_" . $key, "Script Execution Time", $value);
        
        echo "<table border=\"1\">\n";
        echo_archive_aggscript_header();
    
        foreach ($value as $innerKey => $innerValue)
        {
            echo_archive_aggscript_body($innerValue);
        }
        
        echo "</table>\n";      
        echo "<br>\n";
    }
?>
<hr>
<!-- Aggregated area pathing set data. -->
<a name="perf_archive_aggpathing_intraarea">
<h2>perf_archive_aggpathing_intraarea (most recent 2 sets) <a href="#">(back to top)</a></h2>
<?php 
    foreach ($archivedAggAreaPathingData as $key => $value) 
    {
        echo_pie_chart("archive_aggpathing_intraarea_pie_chart_" . $key, "Pathing Time", $value);
        
        echo "<table border=\"1\">\n";
        echo_archive_aggpathing_intraarea_header();
    
        foreach ($value as $innerKey => $innerValue)
        {
            echo_archive_aggpathing_intraarea_body($innerValue);
        }
        
        echo "</table>\n";
        echo "<br>\n";
    }
?>
