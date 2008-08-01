#
# A simple MySql database
# for use with NWNX
#
# use  mysql -u <user> -p < ./nwnx-db
#


CREATE DATABASE IF NOT EXISTS NWNX;

USE NWNX;

DROP TABLE IF EXISTS BindLocation;
CREATE TABLE BindLocation (
  player varchar(64) default '',
  tag varchar(64) default '',
  name varchar(64) default '',
  val text,
  expire int(11) default '0',
  last timestamp(14) NOT NULL,
  KEY idx (player,tag,name)
) TYPE=MyISAM;
# --------------------------------------------------------

#
# Table structure for table `LastSlept`
#

DROP TABLE IF EXISTS LastSlept;
CREATE TABLE LastSlept (
  player varchar(64) default '',
  tag varchar(64) default '',
  name varchar(64) default '',
  val text,
  expire int(11) default '0',
  last timestamp(14) NOT NULL,
  KEY idx (player,tag,name)
) TYPE=MyISAM;
# --------------------------------------------------------

#
# Table structure for table `QuestTokens`
#

DROP TABLE IF EXISTS QuestTokens;
CREATE TABLE QuestTokens (
  player varchar(64) default '',
  tag varchar(64) default '',
  name varchar(64) default '',
  val text,
  expire int(11) default '0',
  last timestamp(14) NOT NULL,
  KEY idx (player,tag,name)
) TYPE=MyISAM;
# --------------------------------------------------------

#
# Table structure for table `SkillLevels`
#

DROP TABLE IF EXISTS SkillLevels;
CREATE TABLE SkillLevels (
  player varchar(64) default '',
  tag varchar(64) default '',
  name varchar(64) default '',
  val smallint(32) default NULL,
  expire int(11) default '0',
  last timestamp(14) NOT NULL,
  KEY idx (player,tag,name)
) TYPE=MyISAM;
# --------------------------------------------------------

#
# Table structure for table `containers`
#

DROP TABLE IF EXISTS containers;
CREATE TABLE containers (
  charname text,
  player text,
  item text,
  count int(64) default NULL,
  IDENTIFIED int(64) default NULL
) TYPE=MyISAM;
# --------------------------------------------------------

#
# Table structure for table `pwdata`
#

DROP TABLE IF EXISTS pwdata;
CREATE TABLE pwdata (
  player varchar(64) default '',
  tag varchar(64) default '',
  name varchar(64) default '',
  val text,
  expire int(11) default '0',
  last timestamp(14) NOT NULL,
  KEY idx (player,tag,name)
) TYPE=MyISAM;
