/* interface functions for nwnx_structs plugin */

/* effect icon constants */
const int EFFECT_ICON_DAMAGE_RESISTANCE                         =   1;
const int EFFECT_ICON_REGENERATE                                =   2;
const int EFFECT_ICON_DAMAGE_REDUCTION                          =   3;
const int EFFECT_ICON_TEMPORARY_HITPOINTS                       =   4;
const int EFFECT_ICON_ENTANGLE                                  =   5;
const int EFFECT_ICON_INVULNERABLE                              =   6;
const int EFFECT_ICON_DEAF                                      =   7;
const int EFFECT_ICON_FATIGUE                                   =   8;
const int EFFECT_ICON_IMMUNITY                                  =   9;
const int EFFECT_ICON_BLIND                                     =  10;
const int EFFECT_ICON_ENEMY_ATTACK_BONUS                        =  11;
const int EFFECT_ICON_CHARMED                                   =  12;
const int EFFECT_ICON_CONFUSED                                  =  13;
const int EFFECT_ICON_FRIGHTENED                                =  14;
const int EFFECT_ICON_DOMINATED                                 =  15;
const int EFFECT_ICON_PARALYZE                                  =  16;
const int EFFECT_ICON_DAZED                                     =  17;
const int EFFECT_ICON_STUNNED                                   =  18;
const int EFFECT_ICON_SLEEP                                     =  19;
const int EFFECT_ICON_POISON                                    =  20;
const int EFFECT_ICON_DISEASE                                   =  21;
const int EFFECT_ICON_CURSE                                     =  22;
const int EFFECT_ICON_SILENCE                                   =  23;
const int EFFECT_ICON_TURNED                                    =  24;
const int EFFECT_ICON_HASTE                                     =  25;
const int EFFECT_ICON_SLOW                                      =  26;
const int EFFECT_ICON_ABILITY_INCREASE_STR                      =  27;
const int EFFECT_ICON_ABILITY_DECREASE_STR                      =  28;
const int EFFECT_ICON_ATTACK_INCREASE                           =  29;
const int EFFECT_ICON_ATTACK_DECREASE                           =  30;
const int EFFECT_ICON_DAMAGE_INCREASE                           =  31;
const int EFFECT_ICON_DAMAGE_DECREASE                           =  32;
const int EFFECT_ICON_DAMAGE_IMMUNITY_INCREASE                  =  33;
const int EFFECT_ICON_DAMAGE_IMMUNITY_DECREASE                  =  34;
const int EFFECT_ICON_AC_INCREASE                               =  35;
const int EFFECT_ICON_AC_DECREASE                               =  36;
const int EFFECT_ICON_MOVEMENT_SPEED_INCREASE                   =  37;
const int EFFECT_ICON_MOVEMENT_SPEED_DECREASE                   =  38;
const int EFFECT_ICON_SAVING_THROW_INCREASE                     =  39;
const int EFFECT_ICON_SAVING_THROW_DECREASE                     =  40;
const int EFFECT_ICON_SPELL_RESISTANCE_INCREASE                 =  41;
const int EFFECT_ICON_SPELL_RESISTANCE_DECREASE                 =  42;
const int EFFECT_ICON_SKILL_INCREASE                            =  43;
const int EFFECT_ICON_SKILL_DECREASE                            =  44;
const int EFFECT_ICON_INVISIBILITY                              =  45;
const int EFFECT_ICON_IMPROVEDINVISIBILITY                      =  46;
const int EFFECT_ICON_DARKNESS                                  =  47;
const int EFFECT_ICON_DISPELMAGICALL                            =  48;
const int EFFECT_ICON_ELEMENTALSHIELD                           =  49;
const int EFFECT_ICON_LEVELDRAIN                                =  50;
const int EFFECT_ICON_POLYMORPH                                 =  51;
const int EFFECT_ICON_SANCTUARY                                 =  52;
const int EFFECT_ICON_TRUESEEING                                =  53;
const int EFFECT_ICON_SEEINVISIBILITY                           =  54;
const int EFFECT_ICON_TIMESTOP                                  =  55;
const int EFFECT_ICON_BLINDNESS                                 =  56;
const int EFFECT_ICON_SPELLLEVELABSORPTION                      =  57;
const int EFFECT_ICON_DISPELMAGICBEST                           =  58;
const int EFFECT_ICON_ABILITY_INCREASE_DEX                      =  59;
const int EFFECT_ICON_ABILITY_DECREASE_DEX                      =  60;
const int EFFECT_ICON_ABILITY_INCREASE_CON                      =  61;
const int EFFECT_ICON_ABILITY_DECREASE_CON                      =  62;
const int EFFECT_ICON_ABILITY_INCREASE_INT                      =  63;
const int EFFECT_ICON_ABILITY_DECREASE_INT                      =  64;
const int EFFECT_ICON_ABILITY_INCREASE_WIS                      =  65;
const int EFFECT_ICON_ABILITY_DECREASE_WIS                      =  66;
const int EFFECT_ICON_ABILITY_INCREASE_CHA                      =  67;
const int EFFECT_ICON_ABILITY_DECREASE_CHA                      =  68;
const int EFFECT_ICON_IMMUNITY_ALL                              =  69;
const int EFFECT_ICON_IMMUNITY_MIND                             =  70;
const int EFFECT_ICON_IMMUNITY_POISON                           =  71;
const int EFFECT_ICON_IMMUNITY_DISEASE                          =  72;
const int EFFECT_ICON_IMMUNITY_FEAR                             =  73;
const int EFFECT_ICON_IMMUNITY_TRAP                             =  74;
const int EFFECT_ICON_IMMUNITY_PARALYSIS                        =  75;
const int EFFECT_ICON_IMMUNITY_BLINDNESS                        =  76;
const int EFFECT_ICON_IMMUNITY_DEAFNESS                         =  77;
const int EFFECT_ICON_IMMUNITY_SLOW                             =  78;
const int EFFECT_ICON_IMMUNITY_ENTANGLE                         =  79;
const int EFFECT_ICON_IMMUNITY_SILENCE                          =  80;
const int EFFECT_ICON_IMMUNITY_STUN                             =  81;
const int EFFECT_ICON_IMMUNITY_SLEEP                            =  82;
const int EFFECT_ICON_IMMUNITY_CHARM                            =  83;
const int EFFECT_ICON_IMMUNITY_DOMINATE                         =  84;
const int EFFECT_ICON_IMMUNITY_CONFUSE                          =  85;
const int EFFECT_ICON_IMMUNITY_CURSE                            =  86;
const int EFFECT_ICON_IMMUNITY_DAZED                            =  87;
const int EFFECT_ICON_IMMUNITY_ABILITY_DECREASE                 =  88;
const int EFFECT_ICON_IMMUNITY_ATTACK_DECREASE                  =  89;
const int EFFECT_ICON_IMMUNITY_DAMAGE_DECREASE                  =  90;
const int EFFECT_ICON_IMMUNITY_DAMAGE_IMMUNITY_DECREASE         =  91;
const int EFFECT_ICON_IMMUNITY_AC_DECREASE                      =  92;
const int EFFECT_ICON_IMMUNITY_MOVEMENT_SPEED_DECREASE          =  93;
const int EFFECT_ICON_IMMUNITY_SAVING_THROW_DECREASE            =  94;
const int EFFECT_ICON_IMMUNITY_SPELL_RESISTANCE_DECREASE        =  95;
const int EFFECT_ICON_IMMUNITY_SKILL_DECREASE                   =  96;
const int EFFECT_ICON_IMMUNITY_KNOCKDOWN                        =  97;
const int EFFECT_ICON_IMMUNITY_NEGATIVE_LEVEL                   =  98;
const int EFFECT_ICON_IMMUNITY_SNEAK_ATTACK                     =  99;
const int EFFECT_ICON_IMMUNITY_CRITICAL_HIT                     = 100;
const int EFFECT_ICON_IMMUNITY_DEATH_MAGIC                      = 101;
const int EFFECT_ICON_REFLEX_SAVE_INCREASED                     = 102;
const int EFFECT_ICON_FORT_SAVE_INCREASED                       = 103;
const int EFFECT_ICON_WILL_SAVE_INCREASED                       = 104;
const int EFFECT_ICON_TAUNTED                                   = 105;
const int EFFECT_ICON_SPELLIMMUNITY                             = 106;
const int EFFECT_ICON_ETHEREALNESS                              = 107;
const int EFFECT_ICON_CONCEALMENT                               = 108;
const int EFFECT_ICON_PETRIFIED                                 = 109;
const int EFFECT_ICON_SPELL_FAILURE                             = 110;
const int EFFECT_ICON_DAMAGE_IMMUNITY_MAGIC                     = 111;
const int EFFECT_ICON_DAMAGE_IMMUNITY_ACID                      = 112;
const int EFFECT_ICON_DAMAGE_IMMUNITY_COLD                      = 113;
const int EFFECT_ICON_DAMAGE_IMMUNITY_DIVINE                    = 114;
const int EFFECT_ICON_DAMAGE_IMMUNITY_ELECTRICAL                = 115;
const int EFFECT_ICON_DAMAGE_IMMUNITY_FIRE                      = 116;
const int EFFECT_ICON_DAMAGE_IMMUNITY_NEGATIVE                  = 117;
const int EFFECT_ICON_DAMAGE_IMMUNITY_POSITIVE                  = 118;
const int EFFECT_ICON_DAMAGE_IMMUNITY_SONIC                     = 119;
const int EFFECT_ICON_DAMAGE_IMMUNITY_MAGIC_DECREASE            = 120;
const int EFFECT_ICON_DAMAGE_IMMUNITY_ACID_DECREASE             = 121;
const int EFFECT_ICON_DAMAGE_IMMUNITY_COLD_DECREASE             = 122;
const int EFFECT_ICON_DAMAGE_IMMUNITY_DIVINE_DECREASE           = 123;
const int EFFECT_ICON_DAMAGE_IMMUNITY_ELECTRICAL_DECREASE       = 124;
const int EFFECT_ICON_DAMAGE_IMMUNITY_FIRE_DECREASE             = 125;
const int EFFECT_ICON_DAMAGE_IMMUNITY_NEGATIVE_DECREASE         = 126;
const int EFFECT_ICON_DAMAGE_IMMUNITY_POSITIVE_DECREASE         = 127;
const int EFFECT_ICON_DAMAGE_IMMUNITY_SONIC_DECREASE            = 128;
const int EFFECT_ICON_WOUNDING                                  = 129;

/* effect state constants */
const int EFFECT_STATE_CHARMED                                  =   1;
const int EFFECT_STATE_CONFUSED                                 =   2;
const int EFFECT_STATE_FRIGHTENED                               =   3;
const int EFFECT_STATE_TURNED                                   =   4;
const int EFFECT_STATE_DAZED                                    =   5;
const int EFFECT_STATE_STUNNED                                  =   6;
const int EFFECT_STATE_DOMINATED                                =   7;
const int EFFECT_STATE_PARALYZE                                 =   8;
const int EFFECT_STATE_SLEEP                                    =   9;

/* effect true type constants */
const int EFFECT_TRUETYPE_INVALIDEFFECT                         =   0;
const int EFFECT_TRUETYPE_HASTE                                 =   1;
const int EFFECT_TRUETYPE_DAMAGE_RESISTANCE                     =   2;
const int EFFECT_TRUETYPE_SLOW                                  =   3;
const int EFFECT_TRUETYPE_RESURRECTION                          =   4;
const int EFFECT_TRUETYPE_DISEASE                               =   5;
const int EFFECT_TRUETYPE_SUMMON_CREATURE                       =   6;
const int EFFECT_TRUETYPE_REGENERATE                            =   7;
const int EFFECT_TRUETYPE_SETSTATE                              =   8;
const int EFFECT_TRUETYPE_SETSTATE_INTERNAL                     =   9;
const int EFFECT_TRUETYPE_ATTACK_INCREASE                       =  10;
const int EFFECT_TRUETYPE_ATTACK_DECREASE                       =  11;
const int EFFECT_TRUETYPE_DAMAGE_REDUCTION                      =  12;
const int EFFECT_TRUETYPE_DAMAGE_INCREASE                       =  13;
const int EFFECT_TRUETYPE_DAMAGE_DECREASE                       =  14;
const int EFFECT_TRUETYPE_TEMPORARY_HITPOINTS                   =  15;
const int EFFECT_TRUETYPE_DAMAGE_IMMUNITY_INCREASE              =  16;
const int EFFECT_TRUETYPE_DAMAGE_IMMUNITY_DECREASE              =  17;
const int EFFECT_TRUETYPE_ENTANGLE                              =  18;
const int EFFECT_TRUETYPE_DEATH                                 =  19;
const int EFFECT_TRUETYPE_KNOCKDOWN                             =  20;
const int EFFECT_TRUETYPE_DEAF                                  =  21;
const int EFFECT_TRUETYPE_IMMUNITY                              =  22;
const int EFFECT_TRUETYPE_SET_AI_STATE                          =  23;
const int EFFECT_TRUETYPE_ENEMY_ATTACK_BONUS                    =  24;
const int EFFECT_TRUETYPE_ARCANE_SPELL_FAILURE                  =  25;
const int EFFECT_TRUETYPE_SAVING_THROW_INCREASE                 =  26;
const int EFFECT_TRUETYPE_SAVING_THROW_DECREASE                 =  27;
const int EFFECT_TRUETYPE_MOVEMENT_SPEED_INCREASE               =  28;
const int EFFECT_TRUETYPE_MOVEMENT_SPEED_DECREASE               =  29;
const int EFFECT_TRUETYPE_VISUALEFFECT                          =  30;
const int EFFECT_TRUETYPE_AREA_OF_EFFECT                        =  31;
const int EFFECT_TRUETYPE_BEAM                                  =  32;
const int EFFECT_TRUETYPE_SPELL_RESISTANCE_INCREASE             =  33;
const int EFFECT_TRUETYPE_SPELL_RESISTANCE_DECREASE             =  34;
const int EFFECT_TRUETYPE_POISON                                =  35;
const int EFFECT_TRUETYPE_ABILITY_INCREASE                      =  36;
const int EFFECT_TRUETYPE_ABILITY_DECREASE                      =  37;
const int EFFECT_TRUETYPE_DAMAGE                                =  38;
const int EFFECT_TRUETYPE_HEAL                                  =  39;
const int EFFECT_TRUETYPE_LINK                                  =  40;
const int EFFECT_TRUETYPE_HASTE_INTERNAL                        =  41;
const int EFFECT_TRUETYPE_SLOW_INTERNAL                         =  42;
const int EFFECT_TRUETYPE_MODIFYNUMATTACKS                      =  44;
const int EFFECT_TRUETYPE_CURSE                                 =  45;
const int EFFECT_TRUETYPE_SILENCE                               =  46;
const int EFFECT_TRUETYPE_INVISIBILITY                          =  47;
const int EFFECT_TRUETYPE_AC_INCREASE                           =  48;
const int EFFECT_TRUETYPE_AC_DECREASE                           =  49;
const int EFFECT_TRUETYPE_SPELL_IMMUNITY                        =  50;
const int EFFECT_TRUETYPE_DISPEL_ALL_MAGIC                      =  51;
const int EFFECT_TRUETYPE_DISPEL_BEST_MAGIC                     =  52;
const int EFFECT_TRUETYPE_TAUNT                                 =  53;
const int EFFECT_TRUETYPE_LIGHT                                 =  54;
const int EFFECT_TRUETYPE_SKILL_INCREASE                        =  55;
const int EFFECT_TRUETYPE_SKILL_DECREASE                        =  56;
const int EFFECT_TRUETYPE_HITPOINTCHANGEWHENDYING               =  57;
const int EFFECT_TRUETYPE_SETWALKANIMATION                      =  58;
const int EFFECT_TRUETYPE_LIMIT_MOVEMENT_SPEED                  =  59;
const int EFFECT_TRUETYPE_DAMAGE_SHIELD                         =  61;
const int EFFECT_TRUETYPE_POLYMORPH                             =  62;
const int EFFECT_TRUETYPE_SANCTUARY                             =  63;
const int EFFECT_TRUETYPE_TIMESTOP                              =  64;
const int EFFECT_TRUETYPE_SPELL_LEVEL_ABSORPTION                =  65;
const int EFFECT_TRUETYPE_ICON                                  =  67;
const int EFFECT_TRUETYPE_RACIAL_TYPE                           =  68;
const int EFFECT_TRUETYPE_VISION                                =  69;
const int EFFECT_TRUETYPE_SEEINVISIBLE                          =  70;
const int EFFECT_TRUETYPE_ULTRAVISION                           =  71;
const int EFFECT_TRUETYPE_TRUESEEING                            =  72;
const int EFFECT_TRUETYPE_BLINDNESS                             =  73;
const int EFFECT_TRUETYPE_DARKNESS                              =  74;
const int EFFECT_TRUETYPE_MISS_CHANCE                           =  75;
const int EFFECT_TRUETYPE_CONCEALMENT                           =  76;
const int EFFECT_TRUETYPE_TURN_RESISTANCE_INCREASE              =  77;
const int EFFECT_TRUETYPE_BONUS_SPELL_OF_LEVEL                  =  78;
const int EFFECT_TRUETYPE_DISAPPEARAPPEAR                       =  79;
const int EFFECT_TRUETYPE_DISAPPEAR                             =  80;
const int EFFECT_TRUETYPE_APPEAR                                =  81;
const int EFFECT_TRUETYPE_NEGATIVE_LEVEL                        =  82;
const int EFFECT_TRUETYPE_BONUS_FEAT                            =  83;
const int EFFECT_TRUETYPE_WOUNDING                              =  84;
const int EFFECT_TRUETYPE_SWARM                                 =  85;
const int EFFECT_TRUETYPE_VAMPIRIC_REGENERATION                 =  86;
const int EFFECT_TRUETYPE_DISARM                                =  87;
const int EFFECT_TRUETYPE_TURN_RESISTANCE_DECREASE              =  88;
const int EFFECT_TRUETYPE_BLINDNESS_INACTIVE                    =  89;
const int EFFECT_TRUETYPE_PETRIFY                               =  90;
const int EFFECT_TRUETYPE_ITEMPROPERTY                          =  91;
const int EFFECT_TRUETYPE_SPELL_FAILURE                         =  92;
const int EFFECT_TRUETYPE_CUTSCENEGHOST                         =  93;
const int EFFECT_TRUETYPE_CUTSCENEIMMOBILE                      =  94;
const int EFFECT_TRUETYPE_DEFENSIVESTANCE                       =  95;


//////////////////////////////////////////////////////////////////////////////
//                               PROTOTYPES                                 //
//////////////////////////////////////////////////////////////////////////////

/* Returns the class level of the caster who created the effect, in the class
 * used to cast the spell.  0 is returned if the effect wasn't creatcd by a
 * creature or if it was created by a special ability rather than a spell. */
int GetEffectCasterLevel(effect eEffect);

/* Returns the duration specified at ApplyEffectToObject() time for
 * the effect. The value of this is undefined for effects which are
 * not of DURATION_TYPE_TEMPORARY. */
float GetEffectDuration (effect eEffect);

/* Returns the remaining duration of the specified effect. The value
 * of this is undefined for effects which are not of
 * DURATION_TYPE_TEMPORARY. */
float GetEffectDurationRemaining (effect eEffect);

/* Returns the number of effect integers the given effect has.
 * This number is entirely dependant on the given effect type.
 * By default, new CGameEffects have 8; but you need to check anyways.
 */
int GetEffectNumIntegers (effect eEffect);

/* Returns the internal effect integer at the index specified. The index
 * is limited to being between 0 and GetEffectNumIntegers(), and which index
 * contains what value depends entirely on the type of effect. */
int GetEffectInteger (effect eEffect, int nIndex);

/* Sets the internal effect integer at the specified index to the
 * value specified. */
void SetEffectInteger (effect eEffect, int nIndex, int nValue);

/* Sets the effect's spell id as specified, which will later be returned
 * with GetEffectSpellId(). */
void SetEffectSpellId (effect eEffect, int nSpellId);

/* Returns the duration specified at AddItemProperty() time for
 * the item property. The value of this is undefined for properties
 * which are not of DURATION_TYPE_TEMPORARY. */
float GetItemPropertyDuration (itemproperty ipProp);

/* Returns the remaining duration of the specified item property. The
 * value of this is undefined for effects which are not of
 * DURATION_TYPE_TEMPORARY. */
float GetItemPropertyDurationRemaining (itemproperty ipProp);

/* Returns the internal item property integer at the index specified.
 * The index is limited to being between 0 and 15, and which index
 * contains what * value depends entirely on the type of property. */
int GetItemPropertyInteger (itemproperty ipProp, int nIndex);

/* Sets the internal item property integer at the specified index to the
 * value specified. */
void SetItemPropertyInteger (itemproperty ipProp, int nIndex, int nValue);

/* Returns the spell id that created the item property. */
int GetItemPropertySpellId (itemproperty ipProp);

/* Sets the item property's spell id as specified, which will later be
 * returned with GetItemPropertySpellId(). */
void SetItemPropertySpellId (itemproperty ipProp, int nSpellId);


//////////////////////////////////////////////////////////////////////////////
//                             IMPLEMENTATION                               //
//////////////////////////////////////////////////////////////////////////////

int GetEffectCasterLevel(effect eEffect) {
    SetLocalString(GetModule(), "NWNX!STRUCTS!GETLEVEL", "          ");
    return StringToInt(GetLocalString(GetModule(), "NWNX!STRUCTS!GETLEVEL"));
}

float GetEffectDuration (effect eEffect) {
    SetLocalString(GetModule(), "NWNX!STRUCTS!GETDURATION", "          ");
    return StringToFloat(GetLocalString(GetModule(), "NWNX!STRUCTS!GETDURATION"));
}

float GetEffectDurationRemaining (effect eEffect) {
    SetLocalString(GetModule(), "NWNX!STRUCTS!GETDURATIONREMAINING", "          ");
    return StringToFloat(GetLocalString(GetModule(), "NWNX!STRUCTS!GETDURATIONREMAINING"));
}

int GetEffectNumIntegers (effect eEffect) {
    SetLocalString(GetModule(), "NWNX!STRUCTS!GETNUMINTEGERS", "          ");
    return StringToInt(GetLocalString(GetModule(), "NWNX!STRUCTS!GETNUMINTEGERS"));
}

int GetEffectInteger (effect eEffect, int nIndex) {
    SetLocalString(GetModule(), "NWNX!STRUCTS!GETINTEGER", IntToString(nIndex) + "          ");
    return StringToInt(GetLocalString(GetModule(), "NWNX!STRUCTS!GETINTEGER"));
}

void SetEffectInteger (effect eEffect, int nIndex, int nValue) {
    SetLocalString(GetModule(), "NWNX!STRUCTS!SETINTEGER", IntToString(nIndex) + " " + IntToString(nValue));
}

void SetEffectSpellId (effect eEffect, int nSpellId) {
    SetLocalString(GetModule(), "NWNX!STRUCTS!SETSPELLID", IntToString(nSpellId));
}

int GetEffectTrueType (effect eEffect) {
    SetLocalString(GetModule(), "NWNX!STRUCTS!GETTRUETYPE", "          ");
    return StringToInt(GetLocalString(GetModule(), "NWNX!STRUCTS!GETTRUETYPE"));
}

void SetEffectTrueType (effect eEffect, int nTrueType) {
    SetLocalString(GetModule(), "NWNX!STRUCTS!SETTRUETYPE", IntToString(nTrueType));
}

void SetEffectCreator (effect eEffect, object oCreator) {
    SetLocalString(GetModule(), "NWNX!STRUCTS!SETCREATOR", ObjectToString(oCreator));
}


int GetHasMatchingEffect (object oObject, object oCreator, int nSpellId, int nTrueType, int nInt0) {
    SetLocalString(oObject, "NWNX!STRUCTS!GETHASEFFECT", ObjectToString(oCreator) + " " +
        IntToString(nSpellId) + " " + IntToString(nTrueType) + " " + IntToString(nInt0));
    return StringToInt(GetLocalString(oObject, "NWNX!STRUCTS!GETHASEFFECT"));
}

int GetHasEffectByCreator (object oCreator, object oObject=OBJECT_SELF, int nSpellId=-1) {
    return GetHasMatchingEffect(oObject, oCreator, nSpellId, -1, 0);
}

int GetHasEffectOfTrueType (int nTrueType, object oObject=OBJECT_SELF, int nSpellId=-1) {
    return GetHasMatchingEffect(oObject, OBJECT_INVALID, nSpellId, nTrueType, 0);
}

int GetHasEffectState (int nState, object oObject=OBJECT_SELF, object oCreator=OBJECT_INVALID, int nSpellId=-1) {
    return GetHasMatchingEffect(oObject, oCreator, nSpellId, EFFECT_TRUETYPE_SETSTATE, nState);
}


object GetItemPropertyCreator (itemproperty ipProp) {
    SetLocalString(GetModule(), "NWNX!STRUCTS!GETCREATORREQUEST", " ");
    return GetLocalObject(GetModule(), "NWNX!STRUCTS!GETCREATOR");
}

float GetItemPropertyDuration (itemproperty ipProp) {
    SetLocalString(GetModule(), "NWNX!STRUCTS!GETDURATION", "          ");
    return StringToFloat(GetLocalString(GetModule(), "NWNX!STRUCTS!GETDURATION"));
}

float GetItemPropertyDurationRemaining (itemproperty ipProp) {
    SetLocalString(GetModule(), "NWNX!STRUCTS!GETDURATIONREMAINING", "          ");
    return StringToFloat(GetLocalString(GetModule(), "NWNX!STRUCTS!GETDURATIONREMAINING"));
}

int GetItemPropertyInteger (itemproperty ipProp, int nIndex) {
    SetLocalString(GetModule(), "NWNX!STRUCTS!GETINTEGER", IntToString(nIndex) + "          ");
    return StringToInt(GetLocalString(GetModule(), "NWNX!STRUCTS!GETINTEGER"));
}

void SetItemPropertyInteger (itemproperty ipProp, int nIndex, int nValue) {
    SetLocalString(GetModule(), "NWNX!STRUCTS!SETINTEGER", IntToString(nIndex) + " " + IntToString(nValue));
}

int GetItemPropertySpellId (itemproperty ipProp) {
    SetLocalString(GetModule(), "NWNX!STRUCTS!GETSPELLID", "          ");
    return StringToInt(GetLocalString(GetModule(), "NWNX!STRUCTS!GETSPELLID"));
}

void SetItemPropertySpellId (itemproperty ipProp, int nSpellId) {
    SetLocalString(GetModule(), "NWNX!STRUCTS!SETSPELLID", IntToString(nSpellId));
}

void SetItemPropertyCreator (itemproperty ipProp, object oCreator) {
    SetLocalString(GetModule(), "NWNX!STRUCTS!SETCREATOR", ObjectToString(oCreator));
}


effect EffectBonusFeat (int nFeat) {
    effect eEff = EffectVisualEffect(nFeat);

    SetEffectTrueType(eEff, EFFECT_TRUETYPE_BONUS_FEAT);
    return eEff;
}

effect EffectIcon (int nIcon) {
    effect eEff = EffectVisualEffect(nIcon);

    SetEffectTrueType(eEff, EFFECT_TRUETYPE_ICON);
    return eEff;
}
