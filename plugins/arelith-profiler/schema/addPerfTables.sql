DROP TABLE IF EXISTS perf_servers;
CREATE TABLE perf_servers 
(
  ID TINYINT UNSIGNED NOT NULL AUTO_INCREMENT,
  Name VARCHAR(45) NOT NULL,
  PRIMARY KEY(ID)
);

INSERT INTO perf_servers(Name) VALUES
    ('Server')

DROP TABLE IF EXISTS perf_snapshots;
CREATE TABLE perf_snapshots 
(
    ID INT UNSIGNED NOT NULL AUTO_INCREMENT,
    perf_servers_ID TINYINT UNSIGNED NOT NULL,
    MainLoopTicks INT UNSIGNED NOT NULL,
    MainLoopExecutionCycles BIGINT UNSIGNED NOT NULL,
    LogOutputExecutionCycles BIGINT UNSIGNED NOT NULL,
    PlayerCount TINYINT UNSIGNED NOT NULL,
    DMCount TINYINT UNSIGNED NOT NULL,
    TimeStamp TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
    PRIMARY KEY(ID),
    FOREIGN KEY(perf_servers_ID) REFERENCES perf_servers(ID),
    INDEX perf_snapshots_FKIndex1(perf_servers_ID)
);

DROP TABLE IF EXISTS perf_snapshots_scripts;
CREATE TABLE perf_snapshots_scripts 
(
    ID INT UNSIGNED NOT NULL AUTO_INCREMENT,
    perf_snapshots_ID INT UNSIGNED NOT NULL,
    ScriptName VARCHAR(16) NOT NULL,
    Cycles BIGINT UNSIGNED NOT NULL,
    Calls INT UNSIGNED NOT NULL,
    PRIMARY KEY(ID),
    FOREIGN KEY(perf_snapshots_ID) REFERENCES perf_snapshots(ID),
    INDEX perf_snapshots_scripts_FKIndex1(perf_snapshots_ID)
);

DROP TABLE IF EXISTS perf_snapshots_pathing_intraarea;
CREATE TABLE perf_snapshots_pathing_intraarea
(
    ID INT UNSIGNED NOT NULL AUTO_INCREMENT,
    perf_snapshots_ID INT UNSIGNED NOT NULL,
    AreaName VARCHAR(32) NOT NULL,
    Cycles BIGINT UNSIGNED NOT NULL,
    PRIMARY KEY(ID),
    FOREIGN KEY(perf_snapshots_ID) REFERENCES perf_snapshots(ID),
    INDEX perf_snapshots_pathing_intraarea_FKIndex1(perf_snapshots_ID)
);

DROP TABLE IF EXISTS perf_archive_sets;
CREATE TABLE perf_archive_sets 
(
    ID INT UNSIGNED NOT NULL AUTO_INCREMENT,
    perf_servers_ID TINYINT UNSIGNED NOT NULL,
    SetStart TIMESTAMP NOT NULL,
    SetEnd TIMESTAMP NOT NULL,
    PRIMARY KEY(ID),
    FOREIGN KEY(perf_servers_ID) REFERENCES perf_servers(ID),
    INDEX perf_archive_sets_FKIndex1(perf_servers_ID)
);

DROP TABLE IF EXISTS perf_archive_aggscripts;
CREATE TABLE perf_archive_aggscripts 
(
    ID INT UNSIGNED NOT NULL AUTO_INCREMENT,
    perf_archive_sets_ID INT UNSIGNED NOT NULL,
    ScriptName VARCHAR(16) NOT NULL,
    TotalCycles BIGINT UNSIGNED NOT NULL,
    TotalCalls BIGINT UNSIGNED NOT NULL,
    PRIMARY KEY(ID),
    FOREIGN KEY(perf_archive_sets_ID) REFERENCES perf_archive_sets(ID),
    INDEX perf_archive_aggscripts_FKIndex1(perf_archive_sets_ID)
);

DROP TABLE IF EXISTS perf_archive_aggpathing_intraarea;
CREATE TABLE perf_archive_aggpathing_intraarea 
(
    ID INT UNSIGNED NOT NULL AUTO_INCREMENT,
    perf_archive_sets_ID INT UNSIGNED NOT NULL,
    AreaName VARCHAR(32) NOT NULL,
    TotalCycles BIGINT UNSIGNED NOT NULL,
    PRIMARY KEY(ID),
    FOREIGN KEY(perf_archive_sets_ID) REFERENCES perf_archive_sets(ID),
    INDEX perf_archive_aggpathing_intraarea_FKIndex1(perf_archive_sets_ID)
);