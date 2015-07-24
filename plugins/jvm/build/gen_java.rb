#!/usr/bin/env ruby

require 'yaml'
require './build/fids'

$core_package = "org.nwnx.nwnx2.jvm"
$core_classprefix = "org_nwnx_nwnx2_jvm_"
$core_classpath = "org/nwnx/nwnx2/jvm/"

$path = ARGV.shift or fail "Need argument: funcs.nss"
$path = File.expand_path($path)
$path.freeze

TypeMapIce = {
  'int' => 'jint',
  'float' => 'jfloat',
  'bool' => 'jboolean',
  'void' => 'void',
  'action' => nil,
  'talent' => nil,
  'event' => nil,

  'string' => 'jstring',
  '_ret string' => 'jstring',

  '_ret object' => 'jobject',
  'object' => 'jobject',
  '_ret effect' => 'jobject',
  'effect' => 'jobject',
  '_ret itemproperty' => 'jobject',
  'itemproperty' => 'jobject',
  '_ret location' => 'jobject',
  'location' => 'jobject',
  '_ret vector' => 'jobject',
  'vector' => 'jobject'
}

TypeMap = {
  'int' => 'int',
  'string' => 'String',
  'float' => 'float',
  'void' => 'void',
  'bool' => 'boolean',

  'action' => nil,
  'talent' => nil,
  'event' => nil,

  'object' => 'NWObject',
  'effect' => 'NWEffect',
  'itemproperty' => 'NWItemProperty',
  'location' => 'NWLocation',
  'vector' => 'NWVector',
}
TypeRXStr = ("(" + TypeMap.keys.join("|") + ")").freeze

ArgumentRename = {
  'SetPlotFlag nPlotFlag' => 'bPlotFlag',
  'SetItemCursedFlag nCursed' => 'bCursed',
  'SetStolenFlag nStolenFlag' => 'bStolenFlag',
  'SetUseableFlag nUseableFlag' => 'bUseableFlag',
  'SetTrapRecoverable nRecoverable' => 'bRecoverable',
  'SetTrapOneShot nOneShot' => 'bOneShot',
  'SetTrapDisarmable nDisarmable' => 'bDisarmable',
  'SetTrapDetectable nDetectable' => 'bDetectable',
  'SetTrapActive nActive' => 'bActive',
  'SetPanelButtonFlash nEnableFlash' => 'bEnableFlash',
  'SetMapPinEnabled nEnabled' => 'bEnabled',
  'SetLockLockable nLockable' => 'bLockable',
  'SetLockKeyRequired nKeyRequired' => 'bKeyRequired',
  'SetEncounterActive nNewValue' => 'bNewValue',

  'JumpToObject nWalkStraightLineToPoint' => 'bWalkStraightLineToPoint',
  'GetSkillRank nBaseSkillRank' => 'bBaseSkillRank',
  'GetPCPublicCDKey nSinglePlayerCDKey' => 'bSinglePlayerCDKey',
  'GetNearestTrapToObject nTrapDetected' => 'bTrapDetected',

  'EffectVisualEffect nMissEffect' => 'bMissEffect',
  'EffectSummonCreature nUseAppearAnimation' => 'bUseAppearAnimation',
  'EffectPolymorph nLocked' => 'bLocked',
  'EffectDeath nSpectacularDeath' => 'bSpectacularDeath',
  'EffectDeath nDisplayFeedback' => 'bDisplayFeedback',

  'ClearAllActions nClearCombatState' => 'bClearCombatState',

  'GetFirstObjectInShape nShape' => 'nShapeType',
  'GetNextObjectInShape nShape' => 'nShapeType',
  'nRace' => 'nIPRacialType',
  'CreateTrapAtLocation nFaction' => 'nStandardFaction',
  'CreateTrapOnObject nFaction' => 'nStandardFaction',
  'SetCutsceneMode nInCutscene' => 'bInCutscene',
  'SetCutsceneMode nLeftClickingEnabled' => 'bLeftClickingEnabled',

  'GetActionMode nMode' => 'nActionMode',

  'EffectAbilityIncrease nAbilityToIncrease' => 'nAbility',
  'GetAbilityScore nAbilityType' => 'nAbility',
  'GetAbilityScore nBaseAbilityScore' => 'bBaseAbilityScore',
  'EffectConcealment nMissType' => 'nMissChanceType',
  'EffectSwarm nLooping' => 'bLooping',
#  Matches the regular consts
#  'ItemPropertyAbilityBonus nAbility' => 'nIPAbility',
#  'ItemPropertyDecreaseAbility nAbility' => 'nIPAbility',

  'ItemPropertyACBonusVsAlign nAlignGroup' => 'nIPAlignGroup',
  'ItemPropertyACBonusVsSAlign nAlign' => 'nAlignment',
  'ItemPropertyAttackBonusVsAlign nAlignGroup' => 'nIPAlignGroup',
  'ItemPropertyDamageBonusVsAlign nAlignGroup' => 'nIPAlignGroup',
  'ItemPropertyDamageBonusVsSAlign nAlign' => 'nAlignment',
  'ItemPropertyEnhancementBonusVsAlign nAlignGroup' => 'nIPAlignGroup',
  'ItemPropertyEnhancementBonusVsSAlign nAlign' => 'nAlignment',
  'ItemPropertyLimitUseByAlign nAlignGroup' => 'nIPAlignGroup',

  'ItemPropertyACBonusVsDmgType nDamageType' => 'nIPDamageType',
  'ItemPropertyDamageBonus nDamageType' => 'nIPDamageType',
  'ItemPropertyDamageBonusVsAlign nDamageType' => 'nIPDamageType',
  'ItemPropertyDamageBonusVsRace nDamageType' => 'nIPDamageType',
  'ItemPropertyDamageBonusVsSAlign nDamageType' => 'nIPDamageType',
  'ItemPropertyDamageImmunity nDamageType' => 'nIPDamageType',
  'ItemPropertyDamageResistance nDamageType' => 'nIPDamageType',
  'ItemPropertyDamageVulnerability nDamageType' => 'nIPDamageType',
  'ItemPropertyExtraMeleeDamageType nDamageType' => 'nIPDamageType',
  'ItemPropertyExtraRangeDamageType nDamageType' => 'nIPDamageType',

  'ItemPropertyTrap nTrapType' => 'nIPTrapType',

  'EffectACIncrease nModifyType' => 'nACModifyType',
  'EffectACDecrease nModifyType' => 'nACModifyType',

  'SetActionMode nMode' => 'nActionMode',
  'SetActionMode nStatus' => 'bStatus',

  'EffectAttackIncrease nModifierType' => 'nAttackBonus',
  'EffectAttackDecrease nModifierType' => 'nAttackBonus',

  'ItemPropertyImmunityMisc nImmunityType' => 'nIPMiscImmunityType',
  'ItemPropertySpellImmunitySchool nSchool' => 'nIPSpellSchool',

  'EffectBeam nBodyPart' => 'nCreaturePart',
  'GetCreatureBodyPart nPart' => 'nCreaturePart',
  'SetCreatureBodyPart nPart' => 'nCreaturePart',

}

ArgumentTypeDef = {
  'SetTileMainLightColor nMainLight1Color' => 'TileMainLightColor',
  'SetTileMainLightColor nMainLight2Color' => 'TileMainLightColor',
  'SetTileSourceLightColor nSourceLight1Color' => 'TileSourceLightColor',
  'SetTileSourceLightColor nSourceLight2Color' => 'TileSourceLightColor',
}

ArgumentDropWith = {
  'getAC nForFutureUse' => '1'
}

ReturnRename = {
  'getItemHasItemProperty' => 'bool',
  'getCommandable' => 'bool',
  'getIdentified' => 'bool',
  'getImmortal' => 'bool',
  'getLastPerceptionHeard' => 'bool',
  'getLastPerceptionInaudible' => 'bool',
  'getLastPerceptionSeen' => 'bool',
  'getLastPerceptionVanished' => 'bool',
  'getLastSpellHarmful' => 'bool',
  'getLockKeyRequired' => 'bool',
  'getLockLockable' => 'bool',
  'getLocked' => 'bool',
  'getLootable' => 'bool',
  'getObjectHeard' => 'bool',
  'getObjectSeen' => 'bool',

  'getTrapActive' => 'bool',
  'getTrapFlagged' => 'bool',
  'getTrapDetectable' => 'bool',
  'getTrapDetectedBy' => 'bool',
  'getTrapDisarmable' => 'bool',
  'getTrapOneShot' => 'bool',
  'getTrapRecoverable' => 'bool',
  'getWeaponRanged' => 'bool',

  'getFactionEqual' => 'bool',
  'getCutsceneMode' => 'bool',
  'getActionMode' => 'bool',
}
DisabledReturnRenames = {

  'getObjectType' => 'ObjectType',
  'getEffectDurationType' => 'DurationType',
  'getItemPropertyDurationType' => 'DurationType',
  'getRacialType' => 'RacialType',

  'getTileMainLight1Color' => 'TileMainLightColor',
  'getTileMainLight2Color' => 'TileMainLightColor',
  'getTileSourceLight1Color' => 'TileSourceLightColor',
  'getTileSourceLight2Color' => 'TileSourceLightColor',

  'getWeather' => 'Weather',
  'getMetaMagicFeat' => 'MetaMagic',
  'getGender' => 'Gender',

  'getEffectSubType' => 'EffectSubType',
  'getEffectType' => 'EffectType',
  'reflexSave' => 'SavingThrowResult',
  'willSave' => 'SavingThrowResult',
  'fortitudeSave' => 'SavingThrowResult',

  'touchAttackMelee' => 'AttackResult',
  'touchAttackRanged' => 'AttackResult',

  'getPhenoType' => 'PhenoType',

  'getLastAttackMode' => 'CombatMode',
  'getLastAttackType' => 'SpecialAttack',
  'getLastAssociateCommand' => 'AssociateCommand',

  'getCreatureSize' => 'CreatureSize',
  'getAssociateType' => 'AssociateType',

  'getCurrentAction' => 'Action',

  'getAlignmentLawChaos' => 'Alignment',
  'getAlignmentGoodEvil' => 'Alignment',
  'getAILevel' => 'AILevel',
}

Enums = {
  'CreaturePart' => {
    0 => 'RightFootPart', 1 => 'LeftFootPart', 2 => 'RightShinPart', 3 =>
    'LeftShinPart', 4 => 'LeftThighPart', 5 => 'RightThighPart', 6 =>
    'PelvisPart', 7 => 'TorsoPart', 8 => 'BeltPart', 9 => 'NeckPart', 10 =>
    'RightForearmPart', 11 => 'LeftForearmPart', 12 => 'RightBicepPart', 13 =>
    'LeftBicepPart', 14 => 'RightShoulderPart', 15 => 'LeftShoulderPart', 16 =>
    'RightHandPart', 17 => 'LeftHandPart', 20 => 'HeadPart', },
  'IPMiscImmunityType' => {
    0 => 'BackstabIPImmunity', 1 => 'LevelAbilDrainIPImmunity', 2 =>
    'MindSpellsIPImmunity', 3 => 'PoisonIPImmunity', 4 => 'DiseaseIPImmunity', 5 =>
    'FearIPImmunity', 6 => 'KnockdownIPImmunity', 7 => 'ParalysisIPImmunity', 8 =>
    'CriticalHitsIPImmunity', 9 => 'DeathMagicIPImmunity', },
  'ImmunityType' => {
    0 => 'NoneImmunity', 1 => 'MindSpellsImmunity', 2 => 'PoisonImmunity', 3 =>
    'DiseaseImmunity', 4 => 'FearImmunity', 5 => 'TrapImmunity', 6 =>
    'ParalysisImmunity', 7 => 'BlindnessImmunity', 8 => 'DeafnessImmunity',
    9 => 'SlowImmunity', 10 => 'EntangleImmunity', 11 => 'SilenceImmunity', 12 =>
    'StunImmunity', 13 => 'SleepImmunity', 14 => 'CharmImmunity', 15 =>
    'DominateImmunity', 16 => 'ConfusedImmunity', 17 => 'CursedImmunity', 18 =>
    'DazedImmunity', 19 => 'AbilityDecreaseImmunity', 20 =>
    'AttackDecreaseImmunity', 21 => 'DamageDecreaseImmunity', 22 =>
    'DamageImmunityDecreaseImmunity', 23 => 'AcDecreaseImmunity', 24 =>
    'MovementSpeedDecreaseImmunity', 25 => 'SavingThrowDecreaseImmunity', 26 =>
    'SpellResistanceDecreaseImmunity', 27 => 'SkillDecreaseImmunity', 28 =>
    'KnockdownImmunity', 29 => 'NegativeLevelImmunity', 30 =>
    'SneakAttackImmunity', 31 => 'CriticalHitImmunity', 32 => 'DeathImmunity', },
  'AttackBonus' => { 0 => 'MiscBonus', 1 => 'OnhandBonus', 2 => 'OffhandBonus', },
  'AILevel' => { -1 => 'DefaultAI', 0 => 'VeryLowAI', 1 => 'LowAI', 2 => 'NormalAI', 3 => 'HighAI', 4 => 'VeryHighAI' },
  'ACModifyType' => { 0 => 'ACDodgeBonus', 1 => 'ACNaturalBonus', 2 => 'ACArmorEnchantmentBonus', 3 => 'ACShieldEnchantmentBonus',
    4 => 'ACDeflectionBonus' },
  'DamageType'   => {1 => 'BludgeoningDamage', 2 => 'PiercingDamage', 4 => 'SlashingDamage', 8 => 'MagicalDamage',
    16 => 'AcidDamage', 32 => 'ColdDamage', 64 => 'DivineDamage', 128 => 'ElectricalDamage', 256 => 'FireDamage',
    512 => 'NegativeDamage', 1024 => 'PositiveDamage', 2048 => 'SonicDamage', 4096 => 'BaseDamage', 4103 => 'ACVsAllDamage' },
  'IPDamageType'   => {0 => 'BludgeoningIPDamage', 1 => 'PiercingIPDamage', 2 => 'SlashingIPDamage', 3 => 'SubdualIPDamage',
    4 => 'PhysicalIPDamage', 5 => 'MagicalIPDamage', 6 => 'AcidIPDamage', 7 => 'ColdIPDamage', 8 => 'DivineIPDamage',
    9 => 'ElectricalIPDamage', 10 => 'FireIPDamage', 11 => 'NegativeIPDamage', 12 => 'PositiveIPDamage', 13 => 'SonicIPDamage',
   },
  'DamagePower' => {
    0 => 'NormalDamage', 1 => 'PlusOneDamage', 2 => 'PlusTwoDamage', 3 => 'PlusThreeDamage',
    4 => 'PlusFourDamage', 5 => 'PlusFiveDamage', 6 => 'EnergyDamage', 7 => 'PlusSixDamage',
    8 => 'PlusSevenDamage', 9 => 'PlusEightDamage', 10 => 'PlusNineDamage', 11 => 'PlusTenDamage',
    12 => 'PlusElevenDamage', 13 => 'PlusTwelveDamage', 14 => 'PlusThirteenDamage', 15 => 'PlusFourteenDamage',
    16 => 'PlusFifteenDamage', 17 => 'PlusSixteenDamage', 18 => 'PlusSeventeenDamage',
    19 => 'PlusEighteenDamage', 20 => 'PlusNinteenDamage', 21 => 'PlusTwentyDamage'
  },
  #'DamageBonus' => {
  #  1 => 'OneBonus', 2 => 'TwoBonus', 3 => 'ThreeBonus', 4 => 'FourBonus', 5 => 'FiveBonus',
  #  6 => 'Bonus1d4',
  #},

  'TrapType' => {
    0 => 'MinorSpikeTrap', 1 => 'AverageSpikeTrap', 2 => 'StrongSpikeTrap', 3 => 'DeadlySpikeTrap',
    4 => 'MinorHolyTrap', 5 => 'AverageHolyTrap', 6 => 'StrongHolyTrap', 7 => 'DeadlyHolyTrap',
    8 => 'MinorTangleTrap', 9 => 'AverageTangleTrap', 10 => 'StrongTangleTrap', 11 => 'DeadlyTangleTrap',
    12 => 'MinorAcidTrap', 13 => 'AverageAcidTrap', 14 => 'StrongAcidTrap', 15 => 'DeadlyAcidTrap', 16 => 'MinorFireTrap',
    17 => 'AverageFireTrap', 18 => 'StrongFireTrap', 19 => 'DeadlyFireTrap', 20 => 'MinorElectricalTrap',
    21 => 'AverageElectricalTrap', 22 => 'StrongElectricalTrap', 23 => 'DeadlyElectricalTrap', 24 => 'MinorGasTrap',
    25 => 'AverageGasTrap', 26 => 'StrongGasTrap', 27 => 'DeadlyGasTrap', 28 => 'MinorFrostTrap', 29 => 'AverageFrostTrap',
    30 => 'StrongFrostTrap', 31 => 'DeadlyFrostTrap', 32 => 'MinorNegativeTrap', 33 => 'AverageNegativeTrap',
    34 => 'StrongNegativeTrap', 35 => 'DeadlyNegativeTrap', 36 => 'MinorSonicTrap', 37 => 'AverageSonicTrap',
    38 => 'StrongSonicTrap', 39 => 'DeadlySonicTrap', 40 => 'MinorAcidSplashTrap', 41 => 'AverageAcidSplashTrap',
    42 => 'StrongAcidSplashTrap', 43 => 'DeadlyAcidSplashTrap', 44 => 'EpicElectricalTrap', 45 => 'EpicFireTrap',
    46 => 'EpicFrostTrap', 47 => 'EpicSonicTrap'
  },
  'IPTrapType' => {
    1 => 'SpikeIPTrap', 2 => 'HolyIPTrap', 3 => 'TangleIPTrap', 4 => 'BlobOfAcidIPTrap', 5 => 'FireIPTrap',
    6 => 'ElectricalIPTrap', 7 => 'GasIPTrap', 8 => 'FrostIPTrap', 9 => 'AcidSplashIPTrap',
    10 => 'SonicIPTrap', 11 => 'NegativeIPTrap',
  },

  'Alignment'    => {0 => 'Any', 1 => 'Neutral', 2 => 'Lawful', 3 => 'Chaotic', 4 => 'Good', 5 => 'Evil'},
  'IPAlignment' => { 0 => 'LgAlignment', 1 => 'LnAlignment', 2 => 'LeAlignment', 3 => 'NgAlignment',
    4 => 'TnAlignment', 5 => 'NeAlignment', 6 => 'CgAlignment', 7 => 'CnAlignment', 8 => 'CeAlignment' },
  'IPAlignGroup' => { 0 => 'AllAlignGroup', 1 => 'NeutralAlignGroup', 2 => 'LawfulAlignGroup',
    3 => 'ChaoticAlignGroup', 4 => 'GoodAlignGroup', 5 => 'EvilAlignGroup' },
  'MissChanceType' => { 0 => 'MissChanceVSAll', 1=> 'MissChanceVSRanged', 2=> 'MissChanceVSMelee' },
  'SpellSchool' => {
    "GeneralSchool" => 0, "AbjurationSchool" => 1, "ConjurationSchool" => 2, "DivinationSchool" => 3, "EnchantmentSchool" => 4,
    "EvocationSchool" => 5, "IllusionSchool" => 6, "NecromancySchool" => 7, "TransmutationSchool" => 8,
  }.invert,
  'IPSpellSchool' => {
    0 => 'AbjurationIPSchool', 1 => 'ConjurationIPSchool', 2 =>
    'DivinationIPSchool', 3 => 'EnchantmentIPSchool', 4 => 'EvocationIPSchool',
    5 => 'IllusionIPSchool', 6 => 'NecromancyIPSchool', 7 => 'TransmutationIPSchool', },
  'Ability' => { 0 => 'Strength', 1 => 'Dexterity', 2 => 'Constitution', 3 => 'Intelligence', 4 => 'Wisdom', 5 => 'Charisma' },
  'ActionMode' => {0 => 'DetectMode', 1 => 'StealthMode', 2 => 'ParryMode', 3 => 'PowerAttackMode',
    4 => 'ImprovedPowerAttackMode', 5 => 'CounterspellMode', 6 => 'FlurryOfBlowsMode',
    7 => 'RapidShotMode', 8 => 'ExpertiseMode', 9 => 'ImprovedExpertiseMode', 10 => 'DefensiveCastMode',
    11 => 'DirtyFightingMode' },
  'Action' => {
    0 => 'MoveToPointAction', 1 => 'PickupItemAction', 2 => 'DropItemAction', 3 => 'AttackObjectAction',
    4 => 'CastSpellAction', 5 => 'OpenDoorAction', 6 => 'CloseDoorAction', 7 => 'DialogObjectAction',
    8 => 'DisableTrapAction', 9 => 'RecoverTrapAction', 10 => 'FlagTrapAction', 11 => 'ExamineTrapAction',
    12 => 'SetTrapAction', 13 => 'OpenLockAction', 14 => 'LockAction', 15 => 'UseObjectAction',
    16 => 'AnimalEmpathyAction', 17 => 'RestAction', 18 => 'TauntAction', 19 => 'ItemCastSpellAction',
    31 => 'CounterSpellAction', 33 => 'HealAction', 34 => 'PickpocketAction', 35 => 'FollowAction',
    36 => 'WaitAction', 37 => 'SitAction', 40 => 'SmiteGoodAction', 41 => 'KIDamageAction',
    43 => 'RandomWalkAction', 65535  => 'InvalidAction',
  },
  'AttackResult' => { 0 => 'MissedAttack', 1 => 'HitAttack', 2 => 'CriticalHitAttack' },
  'SavingThrowResult' => { 0 => 'FailedRoll', 1 => 'SucceededRoll', 3 => 'ImmuneToSaveType' },
  'SpecialAttack' => {
    0 => 'InvalidSpecialAttack', 1 => 'CalledShotLegSpecialAttack', 2 => 'CalledShotArmSpecialAttack',
    3 => 'SapSpecialAttack', 4 => 'DisarmSpecialAttack', 5 => 'ImprovedDisarmSpecialAttack',
    6 => 'KnockdownSpecialAttack', 7 => 'ImprovedKnockdownSpecialAttack', 8 => 'StunningFistSpecialAttack',
    9 => 'FlurryOfBlowsSpecialAttack', 10 => 'RapidShotSpecialAttack',
  },
  'CombatMode' => {
    0 => 'InvalidCombatMode', 1 => 'ParryCombatMode', 2 => 'PowerAttackCombatMode',
    3 => 'ImprovedPowerAttackCombatMode', 4 => 'FlurryOfBlowsCombatMode', 5 => 'RapidShotCombatMode',
    6 => 'ExpertiseCombatMode', 7 => 'ImprovedExpertiseCombatMode', 8 => 'DefensiveCastingCombatMode',
    9 => 'DirtyFightingCombatMode', 10 => 'DefensiveStanceCombatMode',
  },
  'AssociateType' => {
    0 => 'NoAssociate', 1 => 'HenchmanAssociate', 2 => 'AnimalCompanionAssociate',
    3 => 'FamiliarAssociate', 4 => 'SummonedAssociate', 5 => 'DominatedAssociate',
  },
  'AssociateCommand' => {
    -2 => 'StandGroundCommand', -3 => 'AttackNearestCommand', -4 => 'HealMasterCommand', -5 => 'FollowMasterCommand',
    -6 => 'MasterFailedLockpickCommand', -7 => 'GuardMasterCommand', -8 => 'UnsummonFamiliarCommand',
    -9 => 'UnsummonAnimalCompanionCommand', -10 => 'UnsummonSummonedCommand', -11 => 'MasterUnderAttackCommand',
    -12 => 'ReleaseDominationCommand', -13 => 'UnpossessFamiliarCommand', -14 => 'MasterSawTrapCommand',
    -15 => 'MasterAttackedOtherCommand', -16 => 'MasterGoingToBeAttackedCommand', -17 => 'LeavePartyCommand',
    -18 => 'PickLockCommand', -19 => 'InventoryCommand', -20 => 'DisarmTrapCommand', -21 => 'ToggleCastingCommand',
    -22 => 'ToggleStealthCommand', -23 => 'ToggleSearchCommand',
  },
  'Button'  => { 0 => 'MapButton', 1 => 'InventoryButton', 2 => 'JournalButton',
    3 => 'CharacterButton', 4 => 'OptionsButton', 5 => 'SpellsButton',
    6 => 'RestButton', 7 => 'PvPButton'
  },
  'CreatureSize' => {
    0 => 'InvalidSize', 1 => 'TinySize', 2 => 'SmallSize', 3 => 'MediumSize', 4 => 'LargeSize', 5 => 'HugeSize',
  },
  'TalkVolume'   => {0 => 'TalkVol', 1 => 'WhisperVol', 2 => 'ShoutVol',
    3 => 'SilentTalkVol', 4 => 'SilentShoutVol', 5 => 'PartyVol', 6 => 'TellVol'},
  'DurationType' => {-1 => 'InvalidDuration', 0 => 'Instant', 1 => 'Temporary', 2 => 'Permanent'},
  'ObjectType'   => {0 => 'InvalidObject', 1 => 'Creature', 2 => 'Item', 4 => 'Trigger', 8 => 'Door',
    16 => 'AOE', 32 => 'Waypoint', 64 => 'Placeable', 128 => 'Store', 256 => 'Encounter',
    32767 => 'All' },
  'ShapeType' => {0 => 'SpellCylinderShape', 1 => 'ConeShape', 2 => 'CubeShape', 3 => 'SpellConeShape',
    4 => 'SphereShape' },
  'ProjectilePathType' => {0 => 'DefaultPath', 1 => 'HomingPath', 2 => 'BallisticPath',
    3 => 'HighBallisticPath', 4 => 'AcceleratingPath' },
  'DoorAction' => {0 => 'OpenDoor', 1 => 'UnlockDoor', 2 => 'BashDoor', 3 => 'IgnoreDoor', 4 => 'KnockDoor'},
  'PlaceableAction' => {0 => 'UsePlaceable', 1 => 'UnlockPlaceable', 2 => 'BashPlaceable', 4 => 'KnockPlaceable'},
  'RacialType' => { 0 => 'DwarfRace', 1 => 'ElfRace', 2 => 'GnomeRace', 3 => 'HalflingRace',
    4 => 'HalfelfRace', 5 => 'HalforcRace', 6 => 'HumanRace', 7 => 'AberrationRace', 8 => 'AnimalRace',
    9 => 'BeastRace', 10 => 'ConstructRace', 11 => 'DragonRace', 12 => 'HumanoidGoblinoidRace',
    13 => 'HumanoidMonstrousRace', 14 => 'HumanoidOrcRace', 15 => 'HumanoidReptilianRace',
    16 => 'ElementalRace', 17 => 'FeyRace', 18 => 'GiantRace', 19 => 'MagicalBeastRace', 20 => 'OutsiderRace',
    23 => 'ShapechangerRace', 24 => 'UndeadRace', 25 => 'VerminRace', 28 => 'AllRace',
    28 => 'InvalidRace', 29 => 'OozeRace' },
  'IPRacialType' => { 0 => 'DwarfIPRace', 1 => 'ElfIPRace', 2 => 'GnomeIPRace', 3 => 'HalflingIPRace', 4 => 'HalfelfIPRace',
    5 => 'HalforcIPRace', 6 => 'HumanIPRace', 7 => 'AberrationIPRace', 8 => 'AnimalIPRace', 9 => 'BeastIPRace',
    10 => 'ConstructIPRace', 11 => 'DragonIPRace', 12 => 'HumanoidGoblinoidIPRace', 13 => 'HumanoidMonstrousIPRace',
    14 => 'HumanoidOrcIPRace', 15 => 'HumanoidReptilianIPRace', 16 => 'ElementalIPRace', 17 => 'FeyIPRace',
    18 => 'GiantIPRace', 19 => 'MagicalBeastIPRace', 20 => 'OutsiderIPRace', 23 => 'ShapechangerIPRace',
    24 => 'UndeadIPRace', 25 => 'VerminIPRace' },
  'StandardFaction' => {0 => 'Hostile', 1 => 'Commoner', 2 => 'Merchant', 3 => 'Defender'},
  'TileMainLightColor' => {
    0 => 'BlackTileMainLightColor', 1 => 'DimWhiteTileMainLightColor', 2 => 'WhiteTileMainLightColor',
    3 => 'BrightWhiteTileMainLightColor', 4 => 'PaleDarkYellowTileMainLightColor', 5 => 'DarkYellowTileMainLightColor',
    6 => 'PaleYellowTileMainLightColor', 7 => 'YellowTileMainLightColor', 8 => 'PaleDarkGreenTileMainLightColor',
    9 => 'DarkGreenTileMainLightColor', 10 => 'PaleGreenTileMainLightColor', 11 => 'GreenTileMainLightColor',
    12 => 'PaleDarkAquaTileMainLightColor', 13 => 'DarkAquaTileMainLightColor', 14 => 'PaleAquaTileMainLightColor',
    15 => 'AquaTileMainLightColor', 16 => 'PaleDarkBlueTileMainLightColor', 17 => 'DarkBlueTileMainLightColor',
    18 => 'PaleBlueTileMainLightColor', 19 => 'BlueTileMainLightColor', 20 => 'PaleDarkPurpleTileMainLightColor',
    21 => 'DarkPurpleTileMainLightColor', 22 => 'PalePurpleTileMainLightColor', 23 => 'PurpleTileMainLightColor',
    24 => 'PaleDarkRedTileMainLightColor', 25 => 'DarkRedTileMainLightColor', 26 => 'PaleRedTileMainLightColor',
    27 => 'RedTileMainLightColor', 28 => 'PaleDarkOrangeTileMainLightColor', 29 => 'DarkOrangeTileMainLightColor',
    30 => 'PaleOrangeTileMainLightColor', 31 => 'OrangeTileMainLightColor',
  },
  'TileSourceLightColor' => {
    0 => 'BlackTileSourceLightColor', 1 => 'WhiteTileSourceLightColor', 2 => 'PaleDarkYellowTileSourceLightColor',
    3 => 'PaleYellowTileSourceLightColor', 4 => 'PaleDarkGreenTileSourceLightColor', 5 => 'PaleGreenTileSourceLightColor',
    6 => 'PaleDarkAquaTileSourceLightColor', 7 => 'PaleAquaTileSourceLightColor', 8 => 'PaleDarkBlueTileSourceLightColor',
    9 => 'PaleBlueTileSourceLightColor', 10 => 'PaleDarkPurpleTileSourceLightColor', 11 => 'PalePurpleTileSourceLightColor',
    12 => 'PaleDarkRedTileSourceLightColor', 13 => 'PaleRedTileSourceLightColor', 14 => 'PaleDarkOrangeTileSourceLightColor',
    15 => 'PaleOrangeTileSourceLightColor',
  },
  'SaveType' => {
    0 => 'AllOrNoneSaveType', 1 => 'MindSpellsSaveType', 2 => 'PoisonSaveType',
    3 => 'DiseaseSaveType', 4 => 'FearSaveType', 5 => 'SonicSaveType', 6 => 'AcidSaveType', 7 => 'FireSaveType',
    8 => 'ElectricitySaveType', 9 => 'PositiveSaveType', 10 => 'NegativeSaveType', 11 => 'DeathSaveType',
    12 => 'ColdSaveType', 13 => 'DivineSaveType', 14 => 'TrapSaveType', 15 => 'SpellSaveType', 16 => 'GoodSaveType',
    17 => 'EvilSaveType', 18 => 'LawSaveType', 19 => 'ChaosSaveType',
  },
  'Weather' => {
    -1 => 'InvalidWeather', 0 => 'ClearWeather', 1 => 'RainWeather', 2 => 'SnowWeather', 3 => 'AreaDefaultsWeather',
  },
  'MetaMagic' => {
    'CATCHALL' => 'InvalidMeta',
    0 => 'NoneMeta', 1 => 'EmpowerMeta', 2 => 'ExtendMeta', 4 => 'MaximizeMeta', 8 => 'QuickenMeta', 16 => 'SilentMeta',
    32 => 'StillMeta', 255 => 'AnyMeta',
  },
  'Gender' => {
    0 => 'MaleGender', 1 => 'Female', 2 => 'BothGender', 3 => 'OtherGender', 4 => 'NoneGender',
  },
  'InventorySlot' => {
    0 => 'HeadSlot', 1 => 'ChestSlot', 2 => 'BootsSlot', 3 => 'ArmsSlot', 4 => 'RighthandSlot', 5 => 'LefthandSlot',
    6 => 'CloakSlot', 7 => 'LeftringSlot', 8 => 'RightringSlot', 9 => 'NeckSlot', 10 => 'BeltSlot', 11 => 'ArrowsSlot',
    12 => 'BulletsSlot', 13 => 'BoltsSlot', 14 => 'CreatureLefthandSlot', 15 => 'CreatureRighthandSlot',
    16 => 'CreatureBiteSlot', 17 => 'CreatureArmorSlot',
  },

  'EffectState' => {
    1 => 'CharmedState', 2 => 'ConfusedState', 3 => 'FrightenedState', 4 =>
    'TurnedState', 5 => 'DazedState', 6 => 'StunnedState', 7 =>
    'DominatedState', 8 => 'ParalyzeState', 9 => 'SleepState'
  },

  'EffectSubType' => {
    0 => 'InvalidSubType', 8 => 'MagicalSubType', 16 => 'SupernaturalSubType', 24 => 'ExtraordinarySubType',
  },
  'EffectTrueType' => {
    0 => 'InvalidEffectType', 1 => 'HasteEffectType', 2 =>
    'DamageResistanceEffectType', 3 => 'SlowEffectType', 4 =>
    'ResurrectionEffectType', 5 => 'DiseaseEffectType', 6 =>
    'SummonCreatureEffectType', 7 => 'RegenerateEffectType', 8 =>
    'SetStateEffectType', 9 => 'SetStateInternalEffectType', 10 =>
    'AttackIncreaseEffectType', 11 => 'AttackDecreaseEffectType', 12 =>
    'DamageReductionEffectType', 13 => 'DamageIncreaseEffectType', 14 =>
    'DamageDecreaseEffectType', 15 => 'TemporaryHitpointsEffectType', 16 =>
    'DamageImmunityIncreaseEffectType', 17 =>
    'DamageImmunityDecreaseEffectType', 18 => 'EntangleEffectType', 19 =>
    'DeathEffectType', 20 => 'KnockdownEffectType', 21 => 'DeafEffectType',
    22 => 'ImmunityEffectType', 23 => 'SetAIStateEffectType', 24 =>
    'EnemyAttackBonusEffectType', 25 => 'ArcaneSpellFailureEffectType', 26 =>
    'SavingThrowIncreaseEffectType', 27 => 'SavingThrowDecreaseEffectType',
    28 => 'MovementSpeedIncreaseEffectType', 29 =>
    'MovementSpeedDecreaseEffectType', 30 => 'VisualEffectType', 31 =>
    'AOEEffectType', 32 => 'BeamEffectType', 33 =>
    'SpellResistanceIncreaseEffectType', 34 =>
    'SpellResistanceDecreaseEffectType', 35 => 'PoisonEffectType', 36 =>
    'AbilityIncreaseEffectType', 37 => 'AbilityDecreaseEffectType', 38 =>
    'DamageEffectType', 39 => 'HealEffectType', 40 => 'LinkEffectType', 41 =>
    'HasteInternalEffectType', 42 => 'SlowInternalEffectType', 44 =>
    'ModifynumattacksEffectType', 45 => 'CurseEffectType', 46 =>
    'SilenceEffectType', 47 => 'InvisibilityEffectType', 48 =>
    'AcIncreaseEffectType', 49 => 'AcDecreaseEffectType', 50 =>
    'SpellImmunityEffectType', 51 => 'DispelAllMagicEffectType', 52 =>
    'DispelBestMagicEffectType', 53 => 'TauntEffectType', 54 =>
    'LightEffectType', 55 => 'SkillIncreaseEffectType', 56 =>
    'SkillDecreaseEffectType', 57 => 'HitpointChangeWhenDyingEffectType', 58 =>
    'SetWalkAnimationEffectType', 59 => 'LimitMovementSpeedEffectType', 61 =>
    'DamageShieldEffectType', 62 => 'PolymorphEffectType', 63 =>
    'SanctuaryEffectType', 64 => 'TimestopEffectType', 65 =>
    'SpellLevelAbsorptionEffectType', 67 => 'IconEffectType', 68 =>
    'RacialTypeEffectType', 69 => 'VisionEffectType', 70 =>
    'SeeInvisibleEffectType', 71 => 'UltravisionEffectType', 72 =>
    'TrueSeeingEffectType', 73 => 'BlindnessEffectType', 74 =>
    'DarknessEffectType', 75 => 'MissChanceEffectType', 76 =>
    'ConcealmentEffectType', 77 => 'TurnResistanceIncreaseEffectType', 78 =>
    'BonusSpellOfLevelEffectType', 79 => 'DisappearAppearEffectType', 80 =>
    'DisappearEffectType', 81 => 'AppearEffectType', 82 =>
    'NegativeLevelEffectType', 83 => 'BonusFeatEffectType', 84 =>
    'WoundingEffectType', 85 => 'SwarmEffectType', 86 =>
    'VampiricRegenerationEffectType', 87 => 'DisarmEffectType', 88 =>
    'TurnResistanceDecreaseEffectType', 89 => 'BlindnessInactiveEffectType',
    90 => 'PetrifyEffectType', 91 => 'ItempropertyEffectType', 92 =>
    'SpellFailureEffectType', 93 => 'CutsceneGhostEffectType', 94 =>
    'CutsceneImmobileEffectType', 95 => 'DefensiveStanceEffectType'
  },

  'EffectType' => {
    0 => 'InvalidEffect', 1 => 'DamageResistanceEffect', 3 => 'RegenerateEffect', 7 => 'DamageReductionEffect',
    9 => 'TemporaryHitpointsEffect', 11 => 'EntangleEffect', 12 => 'InvulnerableEffect', 13 => 'DeafEffect',
    14 => 'ResurrectionEffect', 15 => 'ImmunityEffect', 17 => 'EnemyAttackBonusEffect', 18 => 'ArcaneSpellFailureEffect',
    20 => 'AreaOfEffectEffect', 21 => 'BeamEffect', 23 => 'CharmedEffect', 24 => 'ConfusedEffect', 25 => 'FrightenedEffect',
    26 => 'DominatedEffect', 27 => 'ParalyzeEffect', 28 => 'DazedEffect', 29 => 'StunnedEffect', 30 => 'SleepEffect',
    31 => 'PoisonEffect', 32 => 'DiseaseEffect', 33 => 'CurseEffect', 34 => 'SilenceEffect', 35 => 'TurnedEffect',
    36 => 'HasteEffect', 37 => 'SlowEffect', 38 => 'AbilityIncreaseEffect', 39 => 'AbilityDecreaseEffect',
    40 => 'AttackIncreaseEffect', 41 => 'AttackDecreaseEffect', 42 => 'DamageIncreaseEffect', 43 => 'DamageDecreaseEffect',
    44 => 'DamageImmunityIncreaseEffect', 45 => 'DamageImmunityDecreaseEffect', 46 => 'ACIncreaseEffect',
    47 => 'ACDecreaseEffect', 48 => 'MovementSpeedIncreaseEffect', 49 => 'MovementSpeedDecreaseEffect',
    50 => 'SavingThrowIncreaseEffect', 51 => 'SavingThrowDecreaseEffect', 52 => 'SpellResistanceIncreaseEffect',
    53 => 'SpellResistanceDecreaseEffect', 54 => 'SkillIncreaseEffect', 55 => 'SkillDecreaseEffect',
    56 => 'InvisibilityEffect', 57 => 'ImprovedInvisibilityEffect', 58 => 'DarknessEffect',
    59 => 'DispelMagicAllEffect', 60 => 'ElementalShieldEffect', 61 => 'NegativeLevelEffect',
    62 => 'PolymorphEffect', 63 => 'SanctuaryEffect', 64 => 'TrueSeeingEffect', 65 => 'SeeInvisibleEffect',
    66 => 'TimestopEffect', 67 => 'BlindnessEffect', 68 => 'SpellLevelAbsorptionEffect', 69 => 'DispelMagicBestEffect',
    70 => 'UltravisionEffect', 71 => 'MissChanceEffect', 72 => 'ConcealmentEffect', 73 => 'SpellImmunityEffect',
    74 => 'VisualEffect', 75 => 'DisappearAppearEffect', 76 => 'SwarmEffect', 77 => 'TurnResistanceDecreaseEffect',
    78 => 'TurnResistanceIncreaseEffect', 79 => 'PetrifyEffect', 80 => 'CutsceneParalyzeEffect', 81 => 'EtherealEffect',
    82 => 'SpellFailureEffect', 83 => 'CutsceneGhostEffect', 84 => 'CutsceneImmobilizeEffect',
  },
  'PhenoType' => {
    0 => 'NormalPhenoType', 2 => 'BigPhenoType', 3 => 'Custom1PhenoType', 4 => 'Custom2PhenoType',
    5 => 'Custom3PhenoType', 6 => 'Custom4PhenoType', 7 => 'Custom5PhenoType', 8 => 'Custom6PhenoType',
    9 => 'Custom7PhenoType', 10 => 'Custom8PhenoType', 11 => 'Custom9PhenoType', 12 => 'Custom10PhenoType',
    13 => 'Custom11PhenoType', 14 => 'Custom12PhenoType', 15 => 'Custom13PhenoType', 16 => 'Custom14PhenoType',
    17 => 'Custom15PhenoType', 18 => 'Custom16PhenoType', 19 => 'Custom17PhenoType', 20 => 'Custom18PhenoType',
  }
}

ArgumentTypeDef.clear
# ReturnRename.clear
Enums.clear

Enums.each {|type,values|
  TypeMapIce[type] = "jobject" # "NWN::#{type}"
}

EnumsStr = Enums.map {|enum, values|
  "enum #{enum} { #{values.sort {|a,b| (a[0] == 'CATCHALL' || b[0] == 'CATCHALL') ? -1 : (a[0] <=> b[0]) }.map {|k,v| v }.join(", ")} };"
#  "enum #{enum} { #{values.map {|k,v| v }.join(", ")} };"
}.join("\n  ")

DontDoAtAll = %w{
  abs acos asin atan cos fabs log pow random sin sqrt tan
  d2 d3 d4 d6 d8 d10 d12 d20 d100
  yardsToMeters feetToMeters
  getSubString getStringUpperCase getStringRight getStringLowerCase getStringLength
  getStringLeft findSubString insertString testStringAgainstPattern
  intToHexString intToString intToFloat
  floatToString floatToInt
  stringToFloat stringToInt
  getFacingFromLocation getAreaFromLocation getPositionFromLocation

  spawnScriptDebugger

  location vector
}

DontExport = %w{
  getFirstPC getNextPC
  getFirstEffect getNextEffect
  getFirstFactionMember getNextFactionMember
  getFirstItemInInventory getNextItemInInventory
  getFirstItemProperty getNextItemProperty
  getFirstObjectInArea getNextObjectInArea
  getFirstObjectInShape getNextObjectInShape
  getFirstInPersistentObject getNextInPersistentObject

  getModule

  badBadReplaceMeThisDoesNothing

  objectToString
}
DontExportDisabled = %w{
  printFloat printInteger printObject printString printVector
}

ExceptionReturnValue = {
  'void' => '',
  'int' => '0',
  'float' => '0.0',
  'bool' => 'JNI_FALSE'
}
ExceptionReturnValue.default = 'NULL'

RX = %r{ ( \n// .+? ) \n \s* #{TypeRXStr} \s+ (.+?) \s* \((.*?)\) \s* ; }xm

$fun = {}

$funs = []

File.open($path, "r") {|_f|
ln = 0
s = _f.read
s.gsub!('[0.0,0.0,0.0]', "_DEFAULT_VECTOR_")

post = s
while m = RX.match(post)
  post = m.post_match

  comment = "line #{ln}: #{s}"

	doc, ret, function, params = $1.strip, $2.strip, $3.strip, $4.strip

  next if DontDoAtAll.index(function)

  in_list = false
  doc = doc.split("\r\n").map {|x|
    x.gsub(%r{^\s*//\s*}, "").strip
  }.map {|x|
    x.gsub(%r{- ([^:]+)(: (.+))?}) {|v|
      vxa = if ArgumentRename[function + " " + $1]
        ArgumentRename[function + " " + $1]
      else $1 end
      "@param " + vxa + ($3 ? " " + $3 : "")
    }
  }

	params = params.split(/,\s*/).map {|p|
    p =~ /^ \s* #{TypeRXStr} \s+ (.+?) (?:\s*=\s*(.+?))? $/x or fail "cannot parse #{p.inspect} (in #{s.inspect})"
    [$1.strip, $2.strip, $3 == '_DEFAULT_VECTOR_' ? '[0.0,0.0,0.0]' : $3]
  }

  catch (:skip) {
    params = params.map {|(type, name, default)|
      t = TypeMap[type] or begin
        $stderr.puts "#{function}: parameter #{name}: cannot resolve type #{type.inspect}, will not export"
        throw :skip
      end

      if ArgumentRename[function + " " + name]
        name = ArgumentRename[function + " " + name]
      elsif ArgumentRename[name]
        name = ArgumentRename[name]
      end

    # Try to detect boolean argument values
      type = "bool" if type == "int" && name =~ /^b[A-Z]/

      if name =~ /^n(.+)$/ && Enums[$1]
        type = $1
        name = "t#{$1}"
      end

      if ArgumentTypeDef[function + " " + name]
        type = ArgumentTypeDef[function + " " + name]
      end

      [type, name, default]
    }

    TypeMap[ret] != nil or begin
      $stderr.puts "#{function} retval #{ret.inspect}: cannot resolve, will not export"
      throw :skip
    end

    # Java semantics: first letter is downcase ..
    function[0,1] = function[0,1].downcase

    # Try to detect boolean result values
    ret = 'bool' if 'int' == ret && function =~ /^get(Is|Has)/ || function =~ /^isIn/ || function =~ /^get.+?Flag$/

    ret = ReturnRename[function] if ReturnRename[function]

    $funs << b = [ret, function, params, doc]
  }
end
}

$funs.sort! {|a,b| a[1] <=> b[1] }

File.open("funs.yaml", "w") do |f|
  x = $funs.map {|(ret, function, params, doc)|
    {
      :fid => FIDS[function],
      :name => function,
      :result => ret,
      :arguments => params,
      :doc => doc,
    }
  }
  YAML.dump(x, f)
end if false


Enums.each {|type, values|
  File.open("java/src/#{$core_classpath}/#{type}.java", "w") do |f|
    f.puts "package #{$core_package};"
    f.puts ""
    f.puts "public enum #{type} {"
    f.puts "  " + values.values.join(", ")
    f.puts "}"
  end
}


# First, generate the .ice file
File.open("java/src/#{$core_classpath}NWScript.java", "w") do |f|
  f.puts <<EOF
// Generated on #{Time.now.to_s} from #{$path}

package #{$core_package};

public class NWScript {
  public NWScript() { }
EOF

  $funs.each {|(ret,function,params, doc)|
    next unless ret

    next if DontExport.index(function)

    catch (:skip) {
      ret = TypeMap[ret] if TypeMap[ret]
      p1 = params.map {|type, name, default|
        if ArgumentDropWith["#{function} #{name}"]
          nil
        else
          type = TypeMap[type] if TypeMap[type]
          "%s %s" % [type, name]
        end
      }.compact

      doc = "/**\n     * " + doc.join("\n     * ") + "\n     */"

      keys = ""
      ex = ['NWNotInContextException']
      ex << 'NWInvalidEffectException' if params.select {|t,n,d| t == "effect"}.size > 0
      ex << 'NWInvalidItemPropertyException' if params.select {|t,n,d| t == "itemproperty"}.size > 0

      f.puts ""
      f.puts "    #{doc}"
      f.puts "    public native static synchronized #{ret} #{function}(#{p1.join(", ")}) throws #{ex.join(", ")};"
    }
  }
  f.puts ""
  f.puts IO.read("NWScript_addon.java")
  f.puts "}"
end

File.open("java/src/#{$core_classpath}Action.java", "w") do |f|
  f.puts "// Generated on #{Time.now.to_s} from #{$path}"
  f.puts ""
  f.puts "package #{$core_package};"
  f.puts ""
  f.puts "import java.lang.Runnable;"
  f.puts ""
  f.puts <<EOF
/**
 * This singleton-class provides convenient wrappers around all
 * NWScript action-type method calls that modify the action queue.
 */
EOF
  f.puts "public final class Action {"
  f.puts "    private Action() {}"
  f.puts <<EOF

    /**
     * Clears all actions for the given object.
     */
    public final static void clear(NWObject objectSelf, final boolean combatToo) {
        Scheduler.assign(objectSelf, new Runnable() {
            @Override public void run() {
                NWScript.clearAllActions(combatToo);
            }
        });
    }
EOF
  $funs.each {|(ret,function,params, doc)|
    next unless function =~ /^action(.+?)$/
    action = $1
    action[0,1] = action[0,1].downcase
    paramA = params.map {|type, name, default|
      if ArgumentDropWith["#{function} #{name}"]
        nil
      else
        type = TypeMap[type] if TypeMap[type]
        "final %s %s" % [type, name]
      end
    }.compact.join(", ")
    paramC = paramA.split(", ").map {|x| x.split(" ", 3)[-1]}.join(", ")

    doc = "/**\n     * " + doc.join("\n     * ") + "\n     */"

    f.puts ""
    f.puts "    #{doc}"
    f.puts "    public final static void %s(NWObject objectSelf%s%s) {" % [ action, paramA.size > 0 ? ", " : "", paramA ]
    f.puts "        Scheduler.assign(objectSelf, new Runnable() {"
    f.puts "            @Override public void run() {"
    f.puts "                NWScript.%s(%s);" % [ function, paramC ]
    f.puts "            }"
    f.puts "        });"
    f.puts "    }"
  }
  f.puts "}"
end

# Then generate the header
File.open("#{$core_classprefix}NWScript.h", "w") do |f|
  f.puts <<EOF
// Generated on #{Time.now.to_s} from #{$path}

#ifndef NWSCRIPT_H
#define NWSCRIPT_H
#include <jni.h>

#include "typedef.h"
#include "api/all.h"
#include <iostream>

#define ENGINE_STRUCTURE_EFFECT 0
#define ENGINE_STRUCTURE_EVENT 1
#define ENGINE_STRUCTURE_LOCATION 2
#define ENGINE_STRUCTURE_TALENT 3
#define ENGINE_STRUCTURE_ITEMPROPERTY 4


extern "C" {
EOF

  $funs.each {|(ret,function,params,comment)|
    next unless ret

    ret = TypeMapIce["_ret " + ret] || TypeMapIce[ret] || ret

    p1 = params.map {|type, name, default|
      if ArgumentDropWith["#{function} #{name}"]
        nil
      else
        type = TypeMapIce[type] || type
        "%s" % [type]
      end
    }.compact
    p1.unshift "jclass"
    p1.unshift "JNIEnv *"
    f.puts "    JNIEXPORT #{ret} JNICALL Java_#{$core_classprefix}NWScript_#{function}(#{p1.join(", ")});"
  }
  Enums.each {|enum, ha|
    f.puts "    long enum_#{enum}_2_long(JNIEnv*, jobject);"
    f.puts "    jobject enum_long_2_#{enum}(JNIEnv*, long);"
  }

  f.puts "};"
  f.puts "#endif"
end

def type_to_sig type
  case type
    when 'int' ;     'I'
    when 'bool' ;    'Z'
    when 'float' ;   'F'
    when 'void' ;    'V'
    when 'object' ;  "L#{$core_classpath}NWObject;"
    when 'vector' ;  "L#{$core_classpath}NWVector;"
    when 'location' ;  "L#{$core_classpath}NWLocation;"
    when 'effect' ;  "L#{$core_classpath}NWEffect;"
    when 'itemproperty' ;  "L#{$core_classpath}NWItemProperty;"
    when 'string';  "Ljava/lang/String;"
    else
      if Enums[type]
        "L#{$core_classpath}#{type};"
      else
        fail "Don't know #{type}"
      end
  end
end

File.open("#{$core_classprefix}registerNWScript.cpp", "w") do |f|
  f.puts "jint CNWNXJVM::registerNWScriptNatives() {"
  f.puts "  JNINativeMethod methods[] = {"
  exported = 0
  funs = $funs.dup
  funs.each_with_index {|(ret,function,params,comment), index|
    name = function
    next if DontExport.index(function)
    exported += 1
    sig = "(" + params.map {|(type, pname, default)|
      if ArgumentDropWith["#{function} #{pname}"]
        nil
      else
        type_to_sig(type)
      end
    }.compact.join("") + ")" + type_to_sig(ret)
    f.puts "    { (char*) \"%s\", (char*) \"%s\", (void*) Java_#{$core_classprefix}NWScript_%s }%s" % [name, sig, name, index < $funs.size - 1 ? "," : ""]
  }
  f.puts "  };"
  f.puts "  return (this->env)->RegisterNatives(this->cls_nwscript, methods, #{exported});"
  f.puts "};"
end

# Now generate the .cpp with the actual body ..
File.open("#{$core_classprefix}NWScript.cpp", "w") do |f|
  f.puts <<EOF
// Generated on #{Time.now.to_s} from #{$path}
#ifndef NWSCRIPT_CPP
#define NWSCRIPT_CPP

#include <jni.h>
#include "#{$core_classprefix}NWScript.h"
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <set>
#include <math.h>

using namespace std;

extern jclass jclassNWObject;
extern jmethodID jmethodNWObjectCreate;
extern jmethodID jmethodNWObjectgetOid;

extern jclass jclassNWVector;
extern jmethodID jmethodNWVectorCreate;
extern jmethodID jmethodNWVectorgetX;
extern jmethodID jmethodNWVectorgetY;
extern jmethodID jmethodNWVectorgetZ;

extern jclass jclassNWLocation;
extern jmethodID jmethodNWLocationCreate;
extern jmethodID jmethodNWLocationgetArea;
extern jmethodID jmethodNWLocationgetX;
extern jmethodID jmethodNWLocationgetY;
extern jmethodID jmethodNWLocationgetZ;
extern jmethodID jmethodNWLocationgetFacing;

extern jclass jclassNWEffect;
extern jmethodID jmethodNWEffectCreate;
extern jmethodID jmethodNWEffectgetOid;

extern jclass jclassNWItemProperty;
extern jmethodID jmethodNWItemPropertyCreate;
extern jmethodID jmethodNWItemPropertygetOid;

extern jclass jclassNWNotInContextException;
extern jclass jclassNWInvalidObjectException;
extern jclass jclassNWInvalidEffectException;
extern jclass jclassNWInvalidItemPropertyException;

extern jclass jclassConv;
extern jmethodID jmethodConvToNative;
extern jmethodID jmethodConvFromNative;

extern unsigned long nwn_contextDepth;
extern bool j_debugNWScriptCalls;

unsigned long j_callCounter = 0;

std::set<CGameEffect*> j_touchedEffects;
std::set<CGameEffect*> j_touchedIprp;
void j_resetPerEventMappings(JNIEnv* env) {
  j_touchedEffects.clear();
  j_touchedIprp.clear();
};

#define JE(jnienvtok,code) if (jnienvtok->ExceptionCheck()) { \
jnienvtok->ExceptionDescribe(); \
jnienvtok->FatalError("while executing native code " #code); \
}

#define J(jnienvtok,code) jnienvtok->code; JE(jnienvtok,code);

EOF

  Enums.each {|enum, ha|
    f.puts "long enum_#{enum}_2_long(JNIEnv * env, jobject k) {"
      #ha.each {|id,val|
      #  f.puts "  if (k == NWN::#{val}) return #{id};" unless id == 'CATCHALL'
      #}
      f.puts "  throw \"omg\";"    # never reached, in theory
    f.puts "};"

    f.puts "jobject enum_long_2_#{enum}(JNIEnv * env, long v) {"
      #catchAll, ha2 = ha.partition {|k,v| k == 'CATCHALL'}
      #ha2.each {|id,val|
      #  f.puts "  if (v == #{id}) return NWN::#{val};"
      #}
      #if catchAll.size > 0
      #  f.puts "  printf(\"Invalid enum value of type #{enum} passed: %d. Returning catchall value.\", v);"
      #  f.puts "  return NWN::%s;" % catchAll[0][1]
      #else
      #  f.puts "  printf(\"Invalid enum value of type #{enum} passed: %d. Cannot continue, and it's your fault!\", v); exit(1);"
      #end
    f.puts "};"
  }

  $funs.each {|(ret,function,params, comment)|
    fail unless ret
    fid = FIDS[function] or raise "Cannot get FID for #{function}"

    # f.puts "%d: %s" % [fid, function]

    p = params.map {|type, name, default|
      if ArgumentDropWith["#{function} #{name}"]
        nil
      else
        type = TypeMapIce[type] || type
        "%s %s" % [type, name]
      end
    }.compact
    p.unshift "jclass klass"
    p.unshift "JNIEnv * env"

    hdr = "JNIEXPORT %s JNICALL Java_#{$core_classprefix}NWScript_%s(%s)" % [
      TypeMapIce["_ret " + ret] || TypeMapIce[ret] || ret,
      function, p.join(", ")
    ]

    f.puts hdr + " {"

    # XXX: disabled for testing two-thread model
    # f.puts "  if (nwn_contextDepth < 1) { env->ThrowNew(jclassNWNotInContextException, \"Not in nwn context while calling #{function}(..)\"); return #{ExceptionReturnValue[ret]}; }"

    f.puts "  if (j_debugNWScriptCalls)"
    f.puts "    printf(\"#{function}(..)\\n\");"

    # Verify given parameters
    params.each {|type, name, default|
      case type
        when "effect"
          f.puts "  CGameEffect* id_%1$s = (CGameEffect*) J(env, CallLongMethod(%1$s, jmethodNWEffectgetOid));" % name
          f.puts "  if (j_touchedEffects.find(id_%1$s) == j_touchedEffects.end()) { env->ThrowNew(jclassNWInvalidEffectException, \"Do not use effects from past context switches.\"); return #{ExceptionReturnValue[ret]}; }" % name
        when "itemproperty"
          f.puts "  CGameEffect* id_%1$s = (CGameEffect*) J(env, CallLongMethod(%1$s, jmethodNWItemPropertygetOid));" % name
          f.puts "  if (j_touchedIprp.find(id_%1$s) == j_touchedIprp.end()) { env->ThrowNew(jclassNWInvalidItemPropertyException, \"Do not use itemProperties from past context switches.\"); return #{ExceptionReturnValue[ret]}; }" % name
        when "object"
          f.puts "  nwobjid id_%1$s;" % name
          f.puts "  if (%1$s == NULL) id_%1$s = 0x7f000000; // OBJECT_INVALID" % name
          f.puts "  else id_%1$s = J(env, CallIntMethod(%1$s, jmethodNWObjectgetOid));" % name
          f.puts "  if (id_%1$s < 0 || id_%1$s > 0x7fffffff) { env->ThrowNew(jclassNWInvalidObjectException, \"Invalid oid() in passed NWObject to #{name} (0 <= oid <= 0xffffffff).\"); return #{ExceptionReturnValue[ret]}; } " % name
        when "location"
          f.puts "  jobject %1$s_area = J(env, CallObjectMethod(%1$s, jmethodNWLocationgetArea));" % name
          f.puts "  nwobjid id_%1$s;" % name
          f.puts "  if (%1$s_area == NULL) id_%1$s = 0x7f000000; // OBJECT_INVALID" % name
          f.puts "  else id_%1$s = J(env, CallIntMethod(%1$s_area, jmethodNWObjectgetOid));" % name
          f.puts "  if (id_%1$s < 0 || id_%1$s > 0x7fffffff) { env->ThrowNew(jclassNWInvalidObjectException, \"Invalid area.oid() in passed NWObject to #{name} (0 <= oid <= 0xffffffff).\"); return #{ExceptionReturnValue[ret]}; }" % name
      end
    }

    f.puts "  j_callCounter += 1;"

    # Push all arguments
    params.reverse.each {|type, name, default|
      f.puts("  " + (case type
        when "string"
          "jbyteArray toNative_%1$s = (jbyteArray) J(env, CallStaticObjectMethod(jclassConv, jmethodConvToNative, %1$s));\n    " +
          "jint len_%1$s = J(env, GetArrayLength(toNative_%1$s));\n    " +
          "jbyte* toNative2_%1$s = (jbyte*) J(env, GetByteArrayElements(toNative_%1$s, 0));\n    " +
          "char* whatever_%1$s = strndup((const char*) toNative2_%1$s, len_%1$s);\n    " +
          "J(env, ReleaseByteArrayElements(toNative_%1$s, toNative2_%1$s, JNI_ABORT));\n    " +
          "g_pVirtualMachine->StackPushString(whatever_%1$s);\n    " +
          "free(whatever_%1$s);\n    "

        when "float"
          "g_pVirtualMachine->StackPushFloat(%s);"

        when "object"
          "g_pVirtualMachine->StackPushObject(id_%1$s);"

        when "int"
          "g_pVirtualMachine->StackPushInteger(%s);"

        when "bool"
          "g_pVirtualMachine->StackPushInteger(%s == JNI_TRUE ? 1 : 0);"

        when "vector"
          "Vector v%1$s;\n  " +
          "v%1$s.X = J(env, CallFloatMethod(%1$s, jmethodNWVectorgetX));\n  " +
          "v%1$s.Y = J(env, CallFloatMethod(%1$s, jmethodNWVectorgetY));\n  " +
          "v%1$s.Z = J(env, CallFloatMethod(%1$s, jmethodNWVectorgetZ));\n  " +
          "g_pVirtualMachine->StackPushVector(v%1$s);"

        when "location"
          "float %1$s_f = J(env, CallFloatMethod(%1$s, jmethodNWLocationgetFacing));\n  " +
          "g_pVirtualMachine->StackPushFloat(%1$s_f);\n  " +
          "Vector %1$s_vv;\n  " +
          "%1$s_vv.X = J(env, CallFloatMethod(%1$s, jmethodNWLocationgetX));\n  " +
          "%1$s_vv.Y = J(env, CallFloatMethod(%1$s, jmethodNWLocationgetY));\n  " +
          "%1$s_vv.Z = J(env, CallFloatMethod(%1$s, jmethodNWLocationgetZ));\n  " +
          "g_pVirtualMachine->StackPushVector(%1$s_vv);\n  " +

          "g_pVirtualMachine->StackPushObject(id_%1$s);\n  " +
          "g_pVirtualMachine->m_pCmdImplementer->ExecuteCommand(215, 3); // This leaves us with a location on the stack.\n  "

        when "effect"
          "g_pVirtualMachine->StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, id_%1$s);"
        when "itemproperty"
          "g_pVirtualMachine->StackPushEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, id_%1$s);"

        else
          if Enums[type]
            "g_pVirtualMachine->StackPushInteger(enum_#{type}_2_long(env, %1$s));\n  "
            #(Enums[type].map {|int, str|
            #  "if (%1$s == NWN::#{str}) StackPushInteger(#{int});\n  "
            #}).join(" else ") + " else { printf(\"Invalid enum value in #{function} for parameter #{name} of type #{type} passed: %%d. Cannot continue, and it's your fault!\\n\", %1$s); exit(1); };"
          else
            raise "Cannot cast argtype: #{type}"
          end
      end
      ) % [ArgumentDropWith["#{function} #{name}"] || name])
    }

    f.puts ""
    f.puts "  g_pVirtualMachine->m_pCmdImplementer->ExecuteCommand(%d, %d);" % [fid, params.size]
    f.puts ""

    unlock = ""

    case ret
      when "void"
        f.puts unlock

      when "int"
        f.puts "  int nRetVal;\n  g_pVirtualMachine->StackPopInteger(&nRetVal);\n  #{unlock}return nRetVal;"

      when "bool"
        f.puts "  int nRetVal;\n  g_pVirtualMachine->StackPopInteger(&nRetVal);\n  #{unlock}return nRetVal != 0 ? JNI_TRUE : JNI_FALSE;"

      when "float"
        f.puts "  float fRetVal;\n  g_pVirtualMachine->StackPopFloat(&fRetVal);\n  #{unlock}return fRetVal;"

      when "string"
        f.puts "  CExoString sRetVal;\n" +
          "  g_pVirtualMachine->StackPopString(&sRetVal);\n" +
          "  const char* retstr = sRetVal != NULL ? sRetVal.Text : \"\";\n" +
          "  jbyteArray myByteStuff = J(env, NewByteArray(strlen(retstr)));\n" +
          "  J(env, SetByteArrayRegion(myByteStuff, 0, strlen(retstr), (jbyte*) retstr));\n" +
          "  jstring retStr = (jstring) J(env, CallStaticObjectMethod(jclassConv, jmethodConvFromNative, myByteStuff));\n" +
          "  #{unlock}return retStr;"

      when "object"
        f.puts "  long unsigned int lRetVal;\n  g_pVirtualMachine->StackPopObject(&lRetVal);\n  #{unlock}" +
        "jobject ret = J(env, CallStaticObjectMethod(jclassNWObject, jmethodNWObjectCreate, lRetVal));\n" +
        "#{unlock}return ret;"

      when "vector"
        f.puts "  Vector vRetVal;\n  g_pVirtualMachine->StackPopVector(&vRetVal);\n  " +
        "jobject ret = J(env, CallStaticObjectMethod(jclassNWVector, jmethodNWVectorCreate, vRetVal.X, vRetVal.Y, vRetVal.Z));\n" +
        "#{unlock}return ret;"

      when "location"
        f.puts "  CScriptLocation *pRetVal;\n  " +
        "g_pVirtualMachine->StackPopEngineStructure(ENGINE_STRUCTURE_LOCATION, (void **) &pRetVal);\n  " +
        "jobject ret_area = J(env, CallStaticObjectMethod(jclassNWObject, jmethodNWObjectCreate, pRetVal->AreaID));\n" +
        "float facing = atan2(pRetVal->OrientationY, pRetVal->OrientationX) * (180 / 3.1415927);\n  " +
        "while (facing > 360.0) facing -= 360.0; while (facing < 0.0) facing += 360.0;\n  " +
        "jobject ret = J(env, CallStaticObjectMethod(jclassNWLocation, jmethodNWLocationCreate, ret_area, pRetVal->X, pRetVal->Y, pRetVal->Z, facing));\n  " +
        "#{unlock}return ret;"

      when "itemproperty", "effect"
        f.puts "  CGameEffect *pRetVal;\n  " +
        (case ret
          when "effect"
            "g_pVirtualMachine->StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);\n  " +
            "j_touchedEffects.insert(pRetVal);\n  " +
            "jobject e = J(env, CallStaticObjectMethod(jclassNWEffect, jmethodNWEffectCreate, (long) pRetVal));\n  " +
            ""
          when "itemproperty"
            "g_pVirtualMachine->StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);\n  " +
            "j_touchedIprp.insert(pRetVal);\n  " +
            "jobject e = J(env, CallStaticObjectMethod(jclassNWItemProperty, jmethodNWItemPropertyCreate, (long) pRetVal));\n  " +

            ""
        end) +
        "#{unlock}return e;"

      else
        if Enums[ret]
          f.puts "  int nRetVal;\n  g_pVirtualMachine->StackPopInteger(&nRetVal);\n  #{unlock}" +
          "  return enum_long_2_#{ret}(env, nRetVal);\n  "
          #(Enums[ret].map {|int, str|
          #  "if (nRetVal == #{int}) return NWN::#{str};\n  "
          #}).join("") + "printf(\"Error: Unmapped enum return type in #{function} of type #{ret}: %d. Cannot continue, and it's your fault!\\n\", nRetVal); exit(1);"
        else
          raise "Cannot cast rettype: #{ret}"
        end
    end

    f.puts "};"
    f.puts ""
  }
  f.puts "#endif"
end
