/*
 *  NWNeXalt - Empty File
 *  (c) 2007 Doug Swarin (zac@#defineertex.net)
 *
 *  This program is free software you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *  $Id$
 *  $HeadURL$
 *
 */

#ifndef _NX_NWN_CONST_H_
#define _NX_NWN_CONST_H_

#define OBJECT_INVALID                            0x7F000000

#define OBJECT_TYPE_GUI                                    1
#define OBJECT_TYPE_TILE                                   2
#define OBJECT_TYPE_MODULE                                 3
#define OBJECT_TYPE_AREA                                   4
#define OBJECT_TYPE_CREATURE                               5
#define OBJECT_TYPE_ITEM                                   6
#define OBJECT_TYPE_TRIGGER                                7
#define OBJECT_TYPE_PROJECTILE                             8
#define OBJECT_TYPE_PLACEABLE                              9
#define OBJECT_TYPE_DOOR                                  10
#define OBJECT_TYPE_AREA_OF_EFFECT                        11
#define OBJECT_TYPE_WAYPOINT                              12
#define OBJECT_TYPE_ENCOUNTER                             13
#define OBJECT_TYPE_STORE                                 14
#define OBJECT_TYPE_PORTAL                                15
#define OBJECT_TYPE_SOUND                                 16

#define QUICKBAR_TYPE_INVALID                              0
#define QUICKBAR_TYPE_ITEM                                 1
#define QUICKBAR_TYPE_SPELL                                2
#define QUICKBAR_TYPE_PARRY                                3
#define QUICKBAR_TYPE_FEAT                                 4
#define QUICKBAR_TYPE_TALKTO                               6
#define QUICKBAR_TYPE_ATTACK                               7
#define QUICKBAR_TYPE_EMOTE                                8
#define QUICKBAR_TYPE_MODE                                10
#define QUICKBAR_TYPE_MACRO                               18

#define CREATURE_EVENT_HEARTBEAT                           0
#define CREATURE_EVENT_PERCEPTION                          1
#define CREATURE_EVENT_SPELLCAST                           2
#define CREATURE_EVENT_ATTACKED                            3
#define CREATURE_EVENT_DAMAGED                             4
#define CREATURE_EVENT_DISTURBED                           5
#define CREATURE_EVENT_ENDCOMBAT                           6
#define CREATURE_EVENT_CONVERSATION                        7
#define CREATURE_EVENT_SPAWN                               8
#define CREATURE_EVENT_RESTED                              9
#define CREATURE_EVENT_DEATH                              10
#define CREATURE_EVENT_USERDEF                            11
#define CREATURE_EVENT_BLOCKED                            12

#define EQUIPMENT_SLOT_HEAD                        (1 <<  0)    /* ESLOT_0001 */
#define EQUIPMENT_SLOT_CHEST                       (1 <<  1)    /* ESLOT_0002 */
#define EQUIPMENT_SLOT_BOOTS                       (1 <<  2)    /* ESLOT_0004 */
#define EQUIPMENT_SLOT_ARMS                        (1 <<  3)    /* ESLOT_0008 */
#define EQUIPMENT_SLOT_RIGHTHAND                   (1 <<  4)    /* ESLOT_0010 */
#define EQUIPMENT_SLOT_LEFTHAND                    (1 <<  5)    /* ESLOT_0020 */
#define EQUIPMENT_SLOT_CLOAK                       (1 <<  6)    /* ESLOT_0040 */
#define EQUIPMENT_SLOT_LEFTRING                    (1 <<  7)    /* ESLOT_0080 */
#define EQUIPMENT_SLOT_RIGHTRING                   (1 <<  8)    /* ESLOT_0100 */
#define EQUIPMENT_SLOT_NECK                        (1 <<  9)    /* ESLOT_0200 */
#define EQUIPMENT_SLOT_BELT                        (1 << 10)    /* ESLOT_0400 */
#define EQUIPMENT_SLOT_ARROWS                      (1 << 11)    /* ESLOT_0800 */
#define EQUIPMENT_SLOT_BULLETS                     (1 << 12)    /* ESLOT_1000 */
#define EQUIPMENT_SLOT_BOLTS                       (1 << 13)    /* ESLOT_2000 */
#define EQUIPMENT_SLOT_CWEAPON_L                   (1 << 14)    /* ESLOT_4000 */
#define EQUIPMENT_SLOT_CWEAPON_R                   (1 << 15)    /* ESLOT_8000 */
#define EQUIPMENT_SLOT_CWEAPON_B                   (1 << 16)    /* ESLOT_10000 */
#define EQUIPMENT_SLOT_CARMOUR                     (1 << 17)    /* ESLOT_20000 */

#define INVENTORY_SLOT_HEAD                                0
#define INVENTORY_SLOT_CHEST                               1
#define INVENTORY_SLOT_BOOTS                               2
#define INVENTORY_SLOT_ARMS                                3
#define INVENTORY_SLOT_RIGHTHAND                           4
#define INVENTORY_SLOT_LEFTHAND                            5
#define INVENTORY_SLOT_CLOAK                               6
#define INVENTORY_SLOT_LEFTRING                            7
#define INVENTORY_SLOT_RIGHTRING                           8
#define INVENTORY_SLOT_NECK                                9
#define INVENTORY_SLOT_BELT                               10
#define INVENTORY_SLOT_ARROWS                             11
#define INVENTORY_SLOT_BULLETS                            12
#define INVENTORY_SLOT_BOLTS                              13
#define INVENTORY_SLOT_CWEAPON_L                          14
#define INVENTORY_SLOT_CWEAPON_R                          15
#define INVENTORY_SLOT_CWEAPON_B                          16
#define INVENTORY_SLOT_CARMOUR                            17


#define BASE_ITEM_SHORTSWORD                               0    /* BASE_000 */
#define BASE_ITEM_LONGSWORD                                1    /* BASE_001 */
#define BASE_ITEM_BATTLEAXE                                2    /* BASE_002 */
#define BASE_ITEM_BASTARDSWORD                             3    /* BASE_003 */
#define BASE_ITEM_LIGHTFLAIL                               4    /* BASE_004 */
#define BASE_ITEM_WARHAMMER                                5    /* BASE_005 */
#define BASE_ITEM_HEAVYCROSSBOW                            6    /* BASE_006 */
#define BASE_ITEM_LIGHTCROSSBOW                            7    /* BASE_007 */
#define BASE_ITEM_LONGBOW                                  8    /* BASE_008 */
#define BASE_ITEM_LIGHTMACE                                9    /* BASE_009 */
#define BASE_ITEM_HALBERD                                 10    /* BASE_00A */
#define BASE_ITEM_SHORTBOW                                11    /* BASE_00B */
#define BASE_ITEM_TWOBLADEDSWORD                          12    /* BASE_00C */
#define BASE_ITEM_GREATSWORD                              13    /* BASE_00D */
#define BASE_ITEM_SMALLSHIELD                             14    /* BASE_00E */
#define BASE_ITEM_TORCH                                   15    /* BASE_00F */
#define BASE_ITEM_ARMOR                                   16    /* BASE_010 */
#define BASE_ITEM_HELMET                                  17    /* BASE_011 */
#define BASE_ITEM_GREATAXE                                18    /* BASE_012 */
#define BASE_ITEM_AMULET                                  19    /* BASE_013 */
#define BASE_ITEM_ARROW                                   20    /* BASE_014 */
#define BASE_ITEM_BELT                                    21    /* BASE_015 */
#define BASE_ITEM_DAGGER                                  22    /* BASE_016 */
#define BASE_ITEM_MISCSMALL                               24    /* BASE_018 */
#define BASE_ITEM_BOLT                                    25    /* BASE_019 */
#define BASE_ITEM_BOOTS                                   26    /* BASE_01A */
#define BASE_ITEM_BULLET                                  27    /* BASE_01B */
#define BASE_ITEM_CLUB                                    28    /* BASE_01C */
#define BASE_ITEM_MISCMEDIUM                              29    /* BASE_01D */
#define BASE_ITEM_DART                                    31    /* BASE_01F */
#define BASE_ITEM_DIREMACE                                32    /* BASE_020 */
#define BASE_ITEM_DOUBLEAXE                               33    /* BASE_021 */
#define BASE_ITEM_MISCLARGE                               34    /* BASE_022 */
#define BASE_ITEM_HEAVYFLAIL                              35    /* BASE_023 */
#define BASE_ITEM_GLOVES                                  36    /* BASE_024 */
#define BASE_ITEM_LIGHTHAMMER                             37    /* BASE_025 */
#define BASE_ITEM_HANDAXE                                 38    /* BASE_026 */
#define BASE_ITEM_HEALERSKIT                              39    /* BASE_027 */
#define BASE_ITEM_KAMA                                    40    /* BASE_028 */
#define BASE_ITEM_KATANA                                  41    /* BASE_029 */
#define BASE_ITEM_KUKRI                                   42    /* BASE_02A */
#define BASE_ITEM_MISCTALL                                43    /* BASE_02B */
#define BASE_ITEM_MAGICROD                                44    /* BASE_02C */
#define BASE_ITEM_MAGICSTAFF                              45    /* BASE_02D */
#define BASE_ITEM_MAGICWAND                               46    /* BASE_02E */
#define BASE_ITEM_MORNINGSTAR                             47    /* BASE_02F */
#define BASE_ITEM_POTIONS                                 49    /* BASE_031 */
#define BASE_ITEM_QUARTERSTAFF                            50    /* BASE_032 */
#define BASE_ITEM_RAPIER                                  51    /* BASE_033 */
#define BASE_ITEM_RING                                    52    /* BASE_034 */
#define BASE_ITEM_SCIMITAR                                53    /* BASE_035 */
#define BASE_ITEM_SCROLL                                  54    /* BASE_036 */
#define BASE_ITEM_SCYTHE                                  55    /* BASE_037 */
#define BASE_ITEM_LARGESHIELD                             56    /* BASE_038 */
#define BASE_ITEM_TOWERSHIELD                             57    /* BASE_039 */
#define BASE_ITEM_SHORTSPEAR                              58    /* BASE_03A */
#define BASE_ITEM_SHURIKEN                                59    /* BASE_03B */
#define BASE_ITEM_SICKLE                                  60    /* BASE_03C */
#define BASE_ITEM_SLING                                   61    /* BASE_03D */
#define BASE_ITEM_THIEVESTOOLS                            62    /* BASE_03E */
#define BASE_ITEM_THROWINGAXE                             63    /* BASE_03F */
#define BASE_ITEM_TRAPKIT                                 64    /* BASE_040 */
#define BASE_ITEM_KEY                                     65    /* BASE_041 */
#define BASE_ITEM_LARGEBOX                                66    /* BASE_042 */
#define BASE_ITEM_MISCWIDE                                68    /* BASE_044 */
#define BASE_ITEM_CSLASHWEAPON                            69    /* BASE_045 */
#define BASE_ITEM_CPIERCWEAPON                            70    /* BASE_046 */
#define BASE_ITEM_CBLUDGWEAPON                            71    /* BASE_047 */
#define BASE_ITEM_CSLSHPRCWEAP                            72    /* BASE_048 */
#define BASE_ITEM_CREATUREITEM                            73    /* BASE_049 */
#define BASE_ITEM_BOOK                                    74    /* BASE_04A */
#define BASE_ITEM_SPELLSCROLL                             75    /* BASE_04B */
#define BASE_ITEM_GOLD                                    76    /* BASE_04C */
#define BASE_ITEM_GEM                                     77    /* BASE_04D */
#define BASE_ITEM_BRACER                                  78    /* BASE_04E */
#define BASE_ITEM_MISCTHIN                                79    /* BASE_04F */
#define BASE_ITEM_CLOAK                                   80    /* BASE_050 */
#define BASE_ITEM_GRENADE                                 81    /* BASE_051 */
#define BASE_ITEM_ENCAMPMENT                              82    /* BASE_052 */
#define BASE_ITEM_LANCE                                   92    /* BASE_05C */
#define BASE_ITEM_TRUMPET                                 92    /* BASE_05D */
#define BASE_ITEM_MOONONASTICK                            92    /* BASE_05E */
#define BASE_ITEM_TRIDENT                                 95    /* BASE_05F */
#define BASE_ITEM_BLANK_POTION                           101    /* BASE_065 */
#define BASE_ITEM_BLANK_SCROLL                           102    /* BASE_066 */
#define BASE_ITEM_BLANK_WAND                             103    /* BASE_067 */
#define BASE_ITEM_ENCHANTED_POTION                       104    /* BASE_068 */
#define BASE_ITEM_ENCHANTED_SCROLL                       105    /* BASE_069 */
#define BASE_ITEM_ENCHANTED_WAND                         106    /* BASE_06A */
#define BASE_ITEM_DWARVENWARAXE                          108    /* BASE_06C */
#define BASE_ITEM_CRAFTMATERIALMED                       109    /* BASE_06D */
#define BASE_ITEM_CRAFTMATERIALSML                       110    /* BASE_06E */
#define BASE_ITEM_WHIP                                   111    /* BASE_06F */
#define BASE_ITEM_CRAFTBASE                              112    /* BASE_070 */
#define BASE_ITEM_INVALID                                255    /* BASE_0FF */

#define BASE_ITEM_CEP_TRIDENT                            300    /* BASE_12C */
#define BASE_ITEM_CEP_HEAVYPICK                          301    /* BASE_12D */
#define BASE_ITEM_CEP_LIGHTPICK                          302    /* BASE_12E */
#define BASE_ITEM_CEP_SAI                                303    /* BASE_12F */
#define BASE_ITEM_CEP_NUNCHAKU                           304    /* BASE_130 */
#define BASE_ITEM_CEP_FALCHION                           305    /* BASE_131 */
#define BASE_ITEM_CEP_SMALLBOX                           306    /* BASE_132 */
#define BASE_ITEM_CEP_MISCMEDIUM2                        307    /* BASE_133 */
#define BASE_ITEM_CEP_SAP                                308    /* BASE_134 */
#define BASE_ITEM_CEP_ASSASSINDAGGER                     309    /* BASE_135 */
#define BASE_ITEM_CEP_KATAR                              310    /* BASE_136 */
#define BASE_ITEM_CEP_MISCSMALL2                         311    /* BASE_137 */
#define BASE_ITEM_CEP_HEAVYMACE                          317    /* BASE_13D */
#define BASE_ITEM_CEP_MAUL                               318    /* BASE_13E */
#define BASE_ITEM_CEP_MERCURIALLONGSWORD                 319    /* BASE_13F */
#define BASE_ITEM_CEP_MERCURIALGREATSWORD                320    /* BASE_140 */
#define BASE_ITEM_CEP_DOUBLESCIMITAR                     321    /* BASE_141 */
#define BASE_ITEM_CEP_GOAD                               322    /* BASE_142 */
#define BASE_ITEM_CEP_WINDFIREWHEEL                      323    /* BASE_143 */
#define BASE_ITEM_CEP_DOUBLEPICK                         324    /* BASE_144 */
#define BASE_ITEM_CEP_FLOWERS                            325    /* BASE_145 */
#define BASE_ITEM_CEP_CLOAK                              349    /* BASE_15D */

#define CREATURE_SIZE_INVALID                              0
#define CREATURE_SIZE_TINY                                 1
#define CREATURE_SIZE_SMALL                                2
#define CREATURE_SIZE_MEDIUM                               3
#define CREATURE_SIZE_LARGE                                4
#define CREATURE_SIZE_HUGE                                 5

#define CLASS_TYPE_BARBARIAN                               0    /* CLASS_00 */
#define CLASS_TYPE_BARD                                    1    /* CLASS_01 */
#define CLASS_TYPE_CLERIC                                  2    /* CLASS_02 */
#define CLASS_TYPE_DRUID                                   3    /* CLASS_03 */
#define CLASS_TYPE_FIGHTER                                 4    /* CLASS_04 */
#define CLASS_TYPE_MONK                                    5    /* CLASS_05 */
#define CLASS_TYPE_PALADIN                                 6    /* CLASS_06 */
#define CLASS_TYPE_RANGER                                  7    /* CLASS_07 */
#define CLASS_TYPE_ROGUE                                   8    /* CLASS_08 */
#define CLASS_TYPE_SORCERER                                9    /* CLASS_09 */
#define CLASS_TYPE_WIZARD                                 10    /* CLASS_0A */
#define CLASS_TYPE_ABERRATION                             11    /* CLASS_0B */
#define CLASS_TYPE_ANIMAL                                 12    /* CLASS_0C */
#define CLASS_TYPE_CONSTRUCT                              13    /* CLASS_0D */
#define CLASS_TYPE_HUMANOID                               14    /* CLASS_0E */
#define CLASS_TYPE_MONSTROUS                              15    /* CLASS_0F */
#define CLASS_TYPE_ELEMENTAL                              16    /* CLASS_10 */
#define CLASS_TYPE_FEY                                    17    /* CLASS_11 */
#define CLASS_TYPE_DRAGON                                 18    /* CLASS_12 */
#define CLASS_TYPE_UNDEAD                                 19    /* CLASS_13 */
#define CLASS_TYPE_COMMONER                               20    /* CLASS_14 */
#define CLASS_TYPE_BEAST                                  21    /* CLASS_15 */
#define CLASS_TYPE_GIANT                                  22    /* CLASS_16 */
#define CLASS_TYPE_MAGICAL_BEAST                          23    /* CLASS_17 */
#define CLASS_TYPE_OUTSIDER                               24    /* CLASS_18 */
#define CLASS_TYPE_SHAPECHANGER                           25    /* CLASS_19 */
#define CLASS_TYPE_VERMIN                                 26    /* CLASS_1A */
#define CLASS_TYPE_SHADOWDANCER                           27    /* CLASS_1B */
#define CLASS_TYPE_HARPER                                 28    /* CLASS_1C */
#define CLASS_TYPE_ARCANE_ARCHER                          29    /* CLASS_1D */
#define CLASS_TYPE_ASSASSIN                               30    /* CLASS_1E */
#define CLASS_TYPE_BLACKGUARD                             31    /* CLASS_1F */
#define CLASS_TYPE_DIVINECHAMPION                         32    /* CLASS_20 */
#define CLASS_TYPE_WEAPON_MASTER                          33    /* CLASS_21 */
#define CLASS_TYPE_PALEMASTER                             34    /* CLASS_22 */
#define CLASS_TYPE_SHIFTER                                35    /* CLASS_23 */
#define CLASS_TYPE_DWARVENDEFENDER                        36    /* CLASS_24 */
#define CLASS_TYPE_DRAGONDISCIPLE                         37    /* CLASS_25 */
#define CLASS_TYPE_OOZE                                   38    /* CLASS_26 */
#define CLASS_TYPE_EYE_OF_GRUUMSH                         39    /* CLASS_27 */
#define CLASS_TYPE_SHOU_DISCIPLE                          40    /* CLASS_28 */
#define CLASS_TYPE_PDK                                    41    /* CLASS_29 */
#define CLASS_TYPE_INVALID                               255    /* CLASS_FF */

#define RACIAL_TYPE_DWARF                                  0    /* RACE_00 */
#define RACIAL_TYPE_ELF                                    1    /* RACE_01 */
#define RACIAL_TYPE_GNOME                                  2    /* RACE_02 */
#define RACIAL_TYPE_HALFLING                               3    /* RACE_03 */
#define RACIAL_TYPE_HALFELF                                4    /* RACE_04 */
#define RACIAL_TYPE_HALFORC                                5    /* RACE_05 */
#define RACIAL_TYPE_HUMAN                                  6    /* RACE_06 */
#define RACIAL_TYPE_ABERRATION                             7    /* RACE_07 */
#define RACIAL_TYPE_ANIMAL                                 8    /* RACE_08 */
#define RACIAL_TYPE_BEAST                                  9    /* RACE_09 */
#define RACIAL_TYPE_CONSTRUCT                             10    /* RACE_0A */
#define RACIAL_TYPE_DRAGON                                11    /* RACE_0B */
#define RACIAL_TYPE_HUMANOID_GOBLINOID                    12    /* RACE_0C */
#define RACIAL_TYPE_HUMANOID_MONSTROUS                    13    /* RACE_0D */
#define RACIAL_TYPE_HUMANOID_ORC                          14    /* RACE_0E */
#define RACIAL_TYPE_HUMANOID_REPTILIAN                    15    /* RACE_0F */
#define RACIAL_TYPE_ELEMENTAL                             16    /* RACE_10 */
#define RACIAL_TYPE_FEY                                   17    /* RACE_11 */
#define RACIAL_TYPE_GIANT                                 18    /* RACE_12 */
#define RACIAL_TYPE_MAGICAL_BEAST                         19    /* RACE_13 */
#define RACIAL_TYPE_OUTSIDER                              20    /* RACE_14 */
#define RACIAL_TYPE_SHAPECHANGER                          23    /* RACE_17 */
#define RACIAL_TYPE_UNDEAD                                24    /* RACE_18 */
#define RACIAL_TYPE_VERMIN                                25    /* RACE_19 */
#define RACIAL_TYPE_ALL                                   28    /* RACE_1C */
#define RACIAL_TYPE_INVALID                               28    /* RACE_1C */
#define RACIAL_TYPE_OOZE                                  29    /* RACE_1D */
#define RACIAL_TYPE_PLANT                                 52    /* RACE_34 */


#define SAVING_THROW_ALL                                   0
#define SAVING_THROW_NONE                                  0
#define SAVING_THROW_FORT                                  1
#define SAVING_THROW_REFLEX                                2
#define SAVING_THROW_WILL                                  3

#define SAVING_THROW_TYPE_ALL                              0
#define SAVING_THROW_TYPE_NONE                             0
#define SAVING_THROW_TYPE_MIND_SPELLS                      1
#define SAVING_THROW_TYPE_POISON                           2
#define SAVING_THROW_TYPE_DISEASE                          3
#define SAVING_THROW_TYPE_FEAR                             4
#define SAVING_THROW_TYPE_SONIC                            5
#define SAVING_THROW_TYPE_ACID                             6
#define SAVING_THROW_TYPE_FIRE                             7
#define SAVING_THROW_TYPE_ELECTRICITY                      8
#define SAVING_THROW_TYPE_POSITIVE                         9
#define SAVING_THROW_TYPE_NEGATIVE                         10
#define SAVING_THROW_TYPE_DEATH                            11
#define SAVING_THROW_TYPE_COLD                             12
#define SAVING_THROW_TYPE_DIVINE                           13
#define SAVING_THROW_TYPE_TRAP                             14
#define SAVING_THROW_TYPE_SPELL                            15
#define SAVING_THROW_TYPE_GOOD                             16
#define SAVING_THROW_TYPE_EVIL                             17
#define SAVING_THROW_TYPE_LAW                              18
#define SAVING_THROW_TYPE_CHAOS                            19

#define ABILITY_STRENGTH                                   0
#define ABILITY_DEXTERITY                                  1
#define ABILITY_CONSTITUTION                               2
#define ABILITY_INTELLIGENCE                               3
#define ABILITY_WISDOM                                     4
#define ABILITY_CHARISMA                                   5


#define AC_DODGE_BONUS                                     0
#define AC_NATURAL_BONUS                                   1
#define AC_ARMOUR_ENCHANTMENT_BONUS                        2
#define AC_SHIELD_ENCHANTMENT_BONUS                        3
#define AC_DEFLECTION_BONUS                                4


#define DAMAGE_TYPE_BLUDGEONING                            1
#define DAMAGE_TYPE_PIERCING                               2
#define DAMAGE_TYPE_SLASHING                               4
#define DAMAGE_TYPE_MAGICAL                                8
#define DAMAGE_TYPE_ACID                                  16
#define DAMAGE_TYPE_COLD                                  32
#define DAMAGE_TYPE_DIVINE                                64
#define DAMAGE_TYPE_ELECTRICAL                           128
#define DAMAGE_TYPE_FIRE                                 256
#define DAMAGE_TYPE_NEGATIVE                             512
#define DAMAGE_TYPE_POSITIVE                            1024
#define DAMAGE_TYPE_SONIC                               2048

#define DAMAGE_TYPE_PHYSICAL      (DAMAGE_TYPE_BLUDGEONING | \
                                      DAMAGE_TYPE_PIERCING | \
                                       DAMAGE_TYPE_SLASHING)

#define DAMAGE_TYPE_ELEMENTAL            (DAMAGE_TYPE_ACID | \
                                          DAMAGE_TYPE_COLD | \
                                    DAMAGE_TYPE_ELECTRICAL | \
                                          DAMAGE_TYPE_FIRE | \
                                          DAMAGE_TYPE_SONIC)

#define DAMAGE_TYPE_EXOTIC             (DAMAGE_TYPE_DIVINE | \
                                       DAMAGE_TYPE_MAGICAL | \
                                      DAMAGE_TYPE_NEGATIVE | \
                                       DAMAGE_TYPE_POSITIVE)


#define IMMUNITY_TYPE_NONE                                0
#define IMMUNITY_TYPE_MIND_SPELLS                         1
#define IMMUNITY_TYPE_POISON                              2
#define IMMUNITY_TYPE_DISEASE                             3
#define IMMUNITY_TYPE_FEAR                                4
#define IMMUNITY_TYPE_TRAP                                5
#define IMMUNITY_TYPE_PARALYSIS                           6
#define IMMUNITY_TYPE_BLINDNESS                           7
#define IMMUNITY_TYPE_DEAFNESS                            8
#define IMMUNITY_TYPE_SLOW                                9
#define IMMUNITY_TYPE_ENTANGLE                            10
#define IMMUNITY_TYPE_SILENCE                             11
#define IMMUNITY_TYPE_STUN                                12
#define IMMUNITY_TYPE_SLEEP                               13
#define IMMUNITY_TYPE_CHARM                               14
#define IMMUNITY_TYPE_DOMINATE                            15
#define IMMUNITY_TYPE_CONFUSED                            16
#define IMMUNITY_TYPE_CURSED                              17
#define IMMUNITY_TYPE_DAZED                               18
#define IMMUNITY_TYPE_ABILITY_DECREASE                    19
#define IMMUNITY_TYPE_ATTACK_DECREASE                     20
#define IMMUNITY_TYPE_DAMAGE_DECREASE                     21
#define IMMUNITY_TYPE_DAMAGE_IMMUNITY_DECREASE            22
#define IMMUNITY_TYPE_AC_DECREASE                         23
#define IMMUNITY_TYPE_MOVEMENT_SPEED_DECREASE             24
#define IMMUNITY_TYPE_SAVING_THROW_DECREASE               25
#define IMMUNITY_TYPE_SPELL_RESISTANCE_DECREASE           26
#define IMMUNITY_TYPE_SKILL_DECREASE                      27
#define IMMUNITY_TYPE_KNOCKDOWN                           28
#define IMMUNITY_TYPE_NEGATIVE_LEVEL                      29
#define IMMUNITY_TYPE_SNEAK_ATTACK                        30
#define IMMUNITY_TYPE_CRITICAL_HIT                        31
#define IMMUNITY_TYPE_DEATH                               32


#define SKILL_ANIMAL_EMPATHY                               0    /* SKILL_00 */
#define SKILL_CONCENTRATION                                1    /* SKILL_01 */
#define SKILL_DISABLE_TRAP                                 2    /* SKILL_02 */
#define SKILL_DISCIPLINE                                   3    /* SKILL_03 */
#define SKILL_HEAL                                         4    /* SKILL_04 */
#define SKILL_HIDE                                         5    /* SKILL_05 */
#define SKILL_LISTEN                                       6    /* SKILL_06 */
#define SKILL_LORE                                         7    /* SKILL_07 */
#define SKILL_MOVE_SILENTLY                                8    /* SKILL_08 */
#define SKILL_OPEN_LOCK                                    9    /* SKILL_09 */
#define SKILL_PARRY                                       10    /* SKILL_0A */
#define SKILL_PERFORM                                     11    /* SKILL_0B */
#define SKILL_PERSUADE                                    12    /* SKILL_0C */
#define SKILL_PICK_POCKET                                 13    /* SKILL_0D */
#define SKILL_SEARCH                                      14    /* SKILL_0E */
#define SKILL_SET_TRAP                                    15    /* SKILL_0F */
#define SKILL_SPELLCRAFT                                  16    /* SKILL_10 */
#define SKILL_SPOT                                        17    /* SKILL_11 */
#define SKILL_TAUNT                                       18    /* SKILL_12 */
#define SKILL_USE_MAGIC_DEVICE                            19    /* SKILL_13 */
#define SKILL_APPRAISE                                    20    /* SKILL_14 */
#define SKILL_TUMBLE                                      21    /* SKILL_15 */
#define SKILL_CRAFT_TRAP                                  22    /* SKILL_16 */
#define SKILL_BLUFF                                       23    /* SKILL_17 */
#define SKILL_INTIMIDATE                                  24    /* SKILL_18 */
#define SKILL_CRAFT_ARMOR                                 25    /* SKILL_19 */
#define SKILL_CRAFT_WEAPON                                26    /* SKILL_1A */
#define SKILL_RIDE                                        27    /* SKILL_1B */
#define SKILL_LAST                                        27    /* SKILL_1B */
#define SKILL_ALL_SKILLS                                 255    /* SKILL_FF */


#define SUBTYPE_MASK                                      24
#define SUBTYPE_MAGICAL                                    8
#define SUBTYPE_SUPERNATURAL                              16
#define SUBTYPE_EXTRAORDINARY                             24

#define DURATION_TYPE_MASK                                 7
#define DURATION_TYPE_INSTANT                              0
#define DURATION_TYPE_TEMPORARY                            1
#define DURATION_TYPE_PERMANENT                            2
#define DURATION_TYPE_EQUIPPED                             3
#define DURATION_TYPE_INNATE                               4

#define EFFECT_TRUETYPE_INVALIDEFFECT                      0
#define EFFECT_TRUETYPE_HASTE                              1
#define EFFECT_TRUETYPE_DAMAGE_RESISTANCE                  2
#define EFFECT_TRUETYPE_SLOW                               3
#define EFFECT_TRUETYPE_RESURRECTION                       4
#define EFFECT_TRUETYPE_DISEASE                            5
#define EFFECT_TRUETYPE_SUMMON_CREATURE                    6
#define EFFECT_TRUETYPE_REGENERATE                         7
#define EFFECT_TRUETYPE_SETSTATE                           8
#define EFFECT_TRUETYPE_SETSTATE_INTERNAL                  9
#define EFFECT_TRUETYPE_ATTACK_INCREASE                   10
#define EFFECT_TRUETYPE_ATTACK_DECREASE                   11
#define EFFECT_TRUETYPE_DAMAGE_REDUCTION                  12
#define EFFECT_TRUETYPE_DAMAGE_INCREASE                   13
#define EFFECT_TRUETYPE_DAMAGE_DECREASE                   14
#define EFFECT_TRUETYPE_TEMPORARY_HITPOINTS               15
#define EFFECT_TRUETYPE_DAMAGE_IMMUNITY_INCREASE          16
#define EFFECT_TRUETYPE_DAMAGE_IMMUNITY_DECREASE          17
#define EFFECT_TRUETYPE_ENTANGLE                          18
#define EFFECT_TRUETYPE_DEATH                             19
#define EFFECT_TRUETYPE_KNOCKDOWN                         20
#define EFFECT_TRUETYPE_DEAF                              21
#define EFFECT_TRUETYPE_IMMUNITY                          22
#define EFFECT_TRUETYPE_SET_AI_STATE                      23
#define EFFECT_TRUETYPE_ENEMY_ATTACK_BONUS                24
#define EFFECT_TRUETYPE_ARCANE_SPELL_FAILURE              25
#define EFFECT_TRUETYPE_SAVING_THROW_INCREASE             26
#define EFFECT_TRUETYPE_SAVING_THROW_DECREASE             27
#define EFFECT_TRUETYPE_MOVEMENT_SPEED_INCREASE           28
#define EFFECT_TRUETYPE_MOVEMENT_SPEED_DECREASE           29
#define EFFECT_TRUETYPE_VISUALEFFECT                      30
#define EFFECT_TRUETYPE_AREA_OF_EFFECT                    31
#define EFFECT_TRUETYPE_BEAM                              32
#define EFFECT_TRUETYPE_SPELL_RESISTANCE_INCREASE         33
#define EFFECT_TRUETYPE_SPELL_RESISTANCE_DECREASE         34
#define EFFECT_TRUETYPE_POISON                            35
#define EFFECT_TRUETYPE_ABILITY_INCREASE                  36
#define EFFECT_TRUETYPE_ABILITY_DECREASE                  37
#define EFFECT_TRUETYPE_DAMAGE                            38
#define EFFECT_TRUETYPE_HEAL                              39
#define EFFECT_TRUETYPE_LINK                              40
#define EFFECT_TRUETYPE_HASTE_INTERNAL                    41
#define EFFECT_TRUETYPE_SLOW_INTERNAL                     42
#define EFFECT_TRUETYPE_MODIFYNUMATTACKS                  44
#define EFFECT_TRUETYPE_CURSE                             45
#define EFFECT_TRUETYPE_SILENCE                           46
#define EFFECT_TRUETYPE_INVISIBILITY                      47
#define EFFECT_TRUETYPE_AC_INCREASE                       48
#define EFFECT_TRUETYPE_AC_DECREASE                       49
#define EFFECT_TRUETYPE_SPELL_IMMUNITY                    50
#define EFFECT_TRUETYPE_DISPEL_ALL_MAGIC                  51
#define EFFECT_TRUETYPE_DISPEL_BEST_MAGIC                 52
#define EFFECT_TRUETYPE_TAUNT                             53
#define EFFECT_TRUETYPE_LIGHT                             54
#define EFFECT_TRUETYPE_SKILL_INCREASE                    55
#define EFFECT_TRUETYPE_SKILL_DECREASE                    56
#define EFFECT_TRUETYPE_HITPOINTCHANGEWHENDYING           57
#define EFFECT_TRUETYPE_SETWALKANIMATION                  58
#define EFFECT_TRUETYPE_LIMIT_MOVEMENT_SPEED              59
#define EFFECT_TRUETYPE_DAMAGE_SHIELD                     61
#define EFFECT_TRUETYPE_POLYMORPH                         62
#define EFFECT_TRUETYPE_SANCTUARY                         63
#define EFFECT_TRUETYPE_TIMESTOP                          64
#define EFFECT_TRUETYPE_SPELL_LEVEL_ABSORPTION            65
#define EFFECT_TRUETYPE_ICON                              67
#define EFFECT_TRUETYPE_RACIAL_TYPE                       68
#define EFFECT_TRUETYPE_VISION                            69
#define EFFECT_TRUETYPE_SEEINVISIBLE                      70
#define EFFECT_TRUETYPE_ULTRAVISION                       71
#define EFFECT_TRUETYPE_TRUESEEING                        72
#define EFFECT_TRUETYPE_BLINDNESS                         73
#define EFFECT_TRUETYPE_DARKNESS                          74
#define EFFECT_TRUETYPE_MISS_CHANCE                       75
#define EFFECT_TRUETYPE_CONCEALMENT                       76
#define EFFECT_TRUETYPE_TURN_RESISTANCE_INCREASE          77
#define EFFECT_TRUETYPE_BONUS_SPELL_OF_LEVEL              78
#define EFFECT_TRUETYPE_DISAPPEARAPPEAR                   79
#define EFFECT_TRUETYPE_DISAPPEAR                         80
#define EFFECT_TRUETYPE_APPEAR                            81
#define EFFECT_TRUETYPE_NEGATIVE_LEVEL                    82
#define EFFECT_TRUETYPE_BONUS_FEAT                        83
#define EFFECT_TRUETYPE_WOUNDING                          84
#define EFFECT_TRUETYPE_SWARM                             85
#define EFFECT_TRUETYPE_VAMPIRIC_REGENERATION             86
#define EFFECT_TRUETYPE_DISARM                            87
#define EFFECT_TRUETYPE_TURN_RESISTANCE_DECREASE          88
#define EFFECT_TRUETYPE_BLINDNESS_INACTIVE                89
#define EFFECT_TRUETYPE_PETRIFY                           90
#define EFFECT_TRUETYPE_ITEMPROPERTY                      91
#define EFFECT_TRUETYPE_SPELL_FAILURE                     92
#define EFFECT_TRUETYPE_CUTSCENEGHOST                     93
#define EFFECT_TRUETYPE_CUTSCENEIMMOBILE                  94
#define EFFECT_TRUETYPE_DEFENSIVESTANCE                   95


#define ITEM_RULE_WEAPON_SIZE                             25


#define ITEM_APPR_COLOR_LEATHER_1                         -9
#define ITEM_APPR_COLOR_LEATHER_2                         -8
#define ITEM_APPR_COLOR_CLOTH_1                           -7
#define ITEM_APPR_COLOR_CLOTH_2                           -6
#define ITEM_APPR_COLOR_METAL_1                           -5
#define ITEM_APPR_COLOR_METAL_2                           -4
#define ITEM_APPR_MODEL_PART_1                            -3
#define ITEM_APPR_MODEL_PART_2                            -2
#define ITEM_APPR_MODEL_PART_3                            -1
#define ITEM_APPR_ARMOR_MODEL_RFOOT                        0
#define ITEM_APPR_ARMOR_MODEL_LFOOT                        1
#define ITEM_APPR_ARMOR_MODEL_RSHIN                        2
#define ITEM_APPR_ARMOR_MODEL_LSHIN                        3
#define ITEM_APPR_ARMOR_MODEL_LTHIGH                       4
#define ITEM_APPR_ARMOR_MODEL_RTHIGH                       5
#define ITEM_APPR_ARMOR_MODEL_PELVIS                       6
#define ITEM_APPR_ARMOR_MODEL_TORSO                        7
#define ITEM_APPR_ARMOR_MODEL_BELT                         8
#define ITEM_APPR_ARMOR_MODEL_NECK                         9
#define ITEM_APPR_ARMOR_MODEL_RFOREARM                    10
#define ITEM_APPR_ARMOR_MODEL_LFOREARM                    11
#define ITEM_APPR_ARMOR_MODEL_RBICEP                      12
#define ITEM_APPR_ARMOR_MODEL_LBICEP                      13
#define ITEM_APPR_ARMOR_MODEL_RSHOULDER                   14
#define ITEM_APPR_ARMOR_MODEL_LSHOULDER                   15
#define ITEM_APPR_ARMOR_MODEL_RHAND                       16
#define ITEM_APPR_ARMOR_MODEL_LHAND                       17
#define ITEM_APPR_ARMOR_MODEL_ROBE                        18


#include "nwn_const_feats.h"
#include "nwn_const_spells.h"
#include "nwn_const_vfx.h"

#endif /* _NX_NWN_CONST_H_ */

/* vim: set sw=4: */
