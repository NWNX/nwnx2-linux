CREATE TABLE `ax_dynamic_names` (
  `id` int(10) unsigned NOT NULL auto_increment,
  `pc1` int(10) unsigned default NULL,
  `pc2` int(10) unsigned default NULL,
  `name` varchar(100) default NULL,
  PRIMARY KEY  (`id`),
  UNIQUE KEY `id` (`pc1`,`pc2`)
) ENGINE=MyISAM;