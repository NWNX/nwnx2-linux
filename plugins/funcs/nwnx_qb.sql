CREATE TABLE `player_qb` (
  `id` mediumint(8) unsigned NOT NULL AUTO_INCREMENT,
  `player_id` mediumint(8) unsigned NOT NULL,
  `name` varchar(16) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `player_name` (`player_id`,`name`),
  KEY `player_id` (`player_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE `player_qb_slots` (
  `qb_id` mediumint(8) unsigned NOT NULL,
  `slot` tinyint(2) unsigned NOT NULL,
  `slot_type` tinyint(1) unsigned NOT NULL,
  `special_id` int(11) DEFAULT NULL,
  `meta` int(11) unsigned DEFAULT NULL,
  `class` int(11) unsigned DEFAULT NULL,
  `label` varchar(128) DEFAULT NULL,
  `command` varchar(255) DEFAULT NULL,
  `item_one` mediumint(8) unsigned DEFAULT NULL,
  `item_two` mediumint(8) unsigned DEFAULT NULL,
  PRIMARY KEY (`qb_id`,`slot`),
  KEY `qb_id` (`qb_id`),
  CONSTRAINT `player_qb_slots_ibfk_1` FOREIGN KEY (`qb_id`) REFERENCES `player_qb` (`id`) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;