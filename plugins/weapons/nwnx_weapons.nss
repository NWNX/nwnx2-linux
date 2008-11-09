/* interface functions for nwnx_weapons plugin */

/* TODO:
 *   Make the _STACK options properly exclude other feats and not only
 *   Increased Multiplier and Ki Critical.
 *
 *   Add support for critical confirmation roll bonuses.
 *
 *   Add support for GWF/LWF bonuses.
 *   Add support for extra Epic Prowess bonus when combined with LWF.
 */

/* Disable Devastating Critical insta-kill for all beings or for PCs only. */
const int NWNX_WEAPONS_OPT_DEVCRIT_DISABLE_ALL       =  0; 
const int NWNX_WEAPONS_OPT_DEVCRIT_DISABLE_PC        =  1; 

/* For each of the four critical feat sets (Devastating Critical, Overwhelming
 * Critical, Power Critical, and Superior Critical), set their bonus to
 * critical confirmation rolls, critical multiplier, and critical range.
 *
 * Note that the maximum critical confirmation roll is 31, so you should never
 * make a critical confirmation bonus greather than 11.
 */
const int NWNX_WEAPONS_OPT_DEVCRIT_CONF_BONUS        =  2; 
const int NWNX_WEAPONS_OPT_DEVCRIT_MULT_BONUS        =  3; 
const int NWNX_WEAPONS_OPT_DEVCRIT_MULT_STACK        =  4; 
const int NWNX_WEAPONS_OPT_DEVCRIT_RANGE_BONUS       =  5; 
const int NWNX_WEAPONS_OPT_DEVCRIT_RANGE_STACK       =  6; 
const int NWNX_WEAPONS_OPT_OVERCRIT_CONF_BONUS       =  7; 
const int NWNX_WEAPONS_OPT_OVERCRIT_MULT_BONUS       =  8; 
const int NWNX_WEAPONS_OPT_OVERCRIT_MULT_STACK       =  9;
const int NWNX_WEAPONS_OPT_OVERCRIT_RANGE_BONUS      = 10;
const int NWNX_WEAPONS_OPT_OVERCRIT_RANGE_STACK      = 11;
const int NWNX_WEAPONS_OPT_POWCRIT_CONF_BONUS        = 12;
const int NWNX_WEAPONS_OPT_POWCRIT_MULT_BONUS        = 13;
const int NWNX_WEAPONS_OPT_POWCRIT_MULT_STACK        = 14;
const int NWNX_WEAPONS_OPT_POWCRIT_RANGE_BONUS       = 15;
const int NWNX_WEAPONS_OPT_POWCRIT_RANGE_STACK       = 16;
const int NWNX_WEAPONS_OPT_SUPCRIT_CONF_BONUS        = 17;
const int NWNX_WEAPONS_OPT_SUPCRIT_MULT_BONUS        = 18;
const int NWNX_WEAPONS_OPT_SUPCRIT_MULT_STACK        = 19;
const int NWNX_WEAPONS_OPT_SUPCRIT_RANGE_BONUS       = 20;
const int NWNX_WEAPONS_OPT_SUPCRIT_RANGE_STACK       = 21;

/* Set the AB bonus for having Greater Weapon Focus or Legendary Weapon Focus
 * in a weapon. Also set the AB bonus for having LWF and Epic Prowess.
 */
const int NWNX_WEAPONS_OPT_GRTFOCUS_AB_BONUS         = 22;
const int NWNX_WEAPONS_OPT_LEGFOCUS_AB_BONUS         = 23;
const int NWNX_WEAPONS_OPT_LEGFOCUS_AB_EPBONUS       = 24;


/* Get and set NWNX_WEAPONS_OPT_* options. */
int GetWeaponOption (int nOption);
int SetWeaponOption (int nOption, int nValue);

/* Get and set the minimum Monk level required for nBaseItem to be a Monk weapon. */
int GetWeaponIsMonkWeapon (int nBaseItem);
int SetWeaponIsMonkWeapon (int nBaseItem, int nMonkLevelsRequired);

/* Get and set weapon ability-substitution feats (e.g. Zen Archery for Wisdom on bows). */
int GetWeaponAbilityFeat (int nBaseItem, int nAbility);
int SetWeaponAbilityFeat (int nBaseItem, int nAbility, int nFeat);

/* Get and set finesse size (e.g. Medium for rapiers). */
int GetWeaponFinesseSize (int nBaseItem);
int SetWeaponFinesseSize (int nBaseItem, int nSize);

/* Get and set the various weapon feats for individual base item types. */
int GetWeaponDevastatingCriticalFeat (int nBaseItem);
int GetWeaponEpicFocusFeat (int nBaseItem);
int GetWeaponEpicSpecializationFeat (int nBaseItem);
int GetWeaponFocusFeat (int nBaseItem);
int GetWeaponGreaterFocusFeat (int nBaseItem);
int GetWeaponImprovedCriticalFeat (int nBaseItem);
int GetWeaponLegendaryFocusFeat (int nBaseItem);
int GetWeaponOfChoiceFeat (int nBaseItem);
int GetWeaponOverwhelmingCriticalFeat (int nBaseItem);
int GetWeaponPowerCriticalFeat (int nBaseItem);
int GetWeaponSpecializationFeat (int nBaseItem);
int GetWeaponSuperiorCriticalFeat (int nBaseItem);
int SetWeaponDevastatingCriticalFeat (int nBaseItem, int nFeat);
int SetWeaponEpicFocusFeat (int nBaseItem, int nFeat);
int SetWeaponEpicSpecializationFeat (int nBaseItem, int nFeat);
int SetWeaponFocusFeat (int nBaseItem, int nFeat);
int SetWeaponGreaterFocusFeat (int nBaseItem, int nFeat);
int SetWeaponImprovedCriticalFeat (int nBaseItem, int nFeat);
int SetWeaponLegendaryFocusFeat (int nBaseItem, int nFeat);
int SetWeaponOfChoiceFeat (int nBaseItem, int nFeat);
int SetWeaponOverwhelmingCriticalFeat (int nBaseItem, int nFeat);
int SetWeaponPowerCriticalFeat (int nBaseItem, int nFeat);
int SetWeaponSpecializationFeat (int nBaseItem, int nFeat);
int SetWeaponSuperiorCriticalFeat (int nBaseItem, int nFeat);


int NWNXWeaponsZero (object oObject, string sFunc) {
    SetLocalString(oObject, sFunc, "          ");
    return StringToInt(GetLocalString(oObject, sFunc));
}

int NWNXWeaponsOne (object oObject, string sFunc, int nVal1) {
    SetLocalString(oObject, sFunc, IntToString(nVal1) + "          ");
    return StringToInt(GetLocalString(oObject, sFunc));
}

int NWNXWeaponsTwo (object oObject, string sFunc, int nVal1, int nVal2) {
    SetLocalString(oObject, sFunc, IntToString(nVal1) + " " + IntToString(nVal2) + "          ");
    return StringToInt(GetLocalString(oObject, sFunc));
}

int NWNXWeaponsThree (object oObject, string sFunc, int nVal1, int nVal2, int nVal3) {
    SetLocalString(oObject, sFunc, IntToString(nVal1) + " " + IntToString(nVal2) +
      " " + IntToString(nVal3) + "          ");
    return StringToInt(GetLocalString(oObject, sFunc));
}


int GetWeaponOption (int nOption) {
    return NWNXWeaponsOne(GetModule(), "NWNX!WEAPONS!GETWEAPONOPTION", nOption); 
}

int SetWeaponOption (int nOption, int nValue) {
    return NWNXWeaponsTwo(GetModule(), "NWNX!WEAPONS!SETWEAPONOPTION", nOption, nValue); 
}


int GetWeaponIsMonkWeapon (int nBaseItem) {
    return NWNXWeaponsOne(GetModule(), "NWNX!WEAPONS!GETWEAPONISMONKWEAPON", nBaseItem); 
}

int SetWeaponIsMonkWeapon (int nBaseItem, int nMonkLevelsRequired) {
    return NWNXWeaponsTwo(GetModule(), "NWNX!WEAPONS!SETWEAPONISMONKWEAPON", nBaseItem, nMonkLevelsRequired); 
}


int GetWeaponAbilityFeat (int nBaseItem, int nAbility) {
    return NWNXWeaponsTwo(GetModule(), "NWNX!WEAPONS!GETWEAPONABILITYFEAT", nBaseItem, nAbility); 
}

int SetWeaponAbilityFeat (int nBaseItem, int nAbility, int nFeat) {
    return NWNXWeaponsThree(GetModule(), "NWNX!WEAPONS!SETWEAPONABILITYFEAT", nBaseItem, nAbility, nFeat); 
}


int GetWeaponFinesseSize (int nBaseItem) {
    return NWNXWeaponsOne(GetModule(), "NWNX!WEAPONS!GETWEAPONFINESSESIZE", nBaseItem); 
}

int SetWeaponFinesseSize (int nBaseItem, int nSize) {
    return NWNXWeaponsTwo(GetModule(), "NWNX!WEAPONS!SETWEAPONFINESSESIZE", nBaseItem, nSize); 
}


int GetWeaponDevastatingCriticalFeat  (int nBaseItem) {
     return NWNXWeaponsOne(GetModule(), "NWNX!WEAPONS!GETWEAPONDEVASTATINGCRITICALFEAT",  nBaseItem); 
}

int GetWeaponEpicFocusFeat            (int nBaseItem) {
     return NWNXWeaponsOne(GetModule(), "NWNX!WEAPONS!GETWEAPONEPICFOCUSFEAT",            nBaseItem); 
}

int GetWeaponEpicSpecializationFeat   (int nBaseItem) {
     return NWNXWeaponsOne(GetModule(), "NWNX!WEAPONS!GETWEAPONEPICSPECIALIZATIONFEAT",   nBaseItem); 
}

int GetWeaponFocusFeat                (int nBaseItem) {
     return NWNXWeaponsOne(GetModule(), "NWNX!WEAPONS!GETWEAPONFOCUSFEAT",                nBaseItem); 
}

int GetWeaponGreaterFocusFeat         (int nBaseItem) {
     return NWNXWeaponsOne(GetModule(), "NWNX!WEAPONS!GETWEAPONGREATERFOCUSFEAT",         nBaseItem); 
}

int GetWeaponImprovedCriticalFeat     (int nBaseItem) {
     return NWNXWeaponsOne(GetModule(), "NWNX!WEAPONS!GETWEAPONIMPROVEDCRITICALFEAT",     nBaseItem); 
}

int GetWeaponLegendaryFocusFeat       (int nBaseItem) {
     return NWNXWeaponsOne(GetModule(), "NWNX!WEAPONS!GETWEAPONLEGENDARYFOCUSFEAT",       nBaseItem); 
}

int GetWeaponOfChoiceFeat             (int nBaseItem) {
     return NWNXWeaponsOne(GetModule(), "NWNX!WEAPONS!GETWEAPONOFCHOICEFEAT",             nBaseItem); 
}

int GetWeaponOverwhelmingCriticalFeat (int nBaseItem) {
     return NWNXWeaponsOne(GetModule(), "NWNX!WEAPONS!GETWEAPONOVERWHELMINGCRITICALFEAT", nBaseItem); 
}

int GetWeaponPowerCriticalFeat        (int nBaseItem) {
     return NWNXWeaponsOne(GetModule(), "NWNX!WEAPONS!GETWEAPONPOWERCRITICALFEAT",        nBaseItem); 
}

int GetWeaponSpecializationFeat       (int nBaseItem) {
     return NWNXWeaponsOne(GetModule(), "NWNX!WEAPONS!GETWEAPONSPECIALIZATIONFEAT",       nBaseItem); 
}

int GetWeaponSuperiorCriticalFeat     (int nBaseItem) {
     return NWNXWeaponsOne(GetModule(), "NWNX!WEAPONS!GETWEAPONSUPERIORCRITICALFEAT",     nBaseItem); 
}


int SetWeaponDevastatingCriticalFeat  (int nBaseItem, int nFeat) {
     return NWNXWeaponsTwo(GetModule(), "NWNX!WEAPONS!SETWEAPONDEVASTATINGCRITICALFEAT",  nBaseItem, nFeat); 
}

int SetWeaponEpicFocusFeat            (int nBaseItem, int nFeat) {
     return NWNXWeaponsTwo(GetModule(), "NWNX!WEAPONS!SETWEAPONEPICFOCUSFEAT",            nBaseItem, nFeat); 
}

int SetWeaponEpicSpecializationFeat   (int nBaseItem, int nFeat) {
     return NWNXWeaponsTwo(GetModule(), "NWNX!WEAPONS!SETWEAPONEPICSPECIALIZATIONFEAT",   nBaseItem, nFeat); 
}

int SetWeaponFocusFeat                (int nBaseItem, int nFeat) {
     return NWNXWeaponsTwo(GetModule(), "NWNX!WEAPONS!SETWEAPONFOCUSFEAT",                nBaseItem, nFeat); 
}

int SetWeaponGreaterFocusFeat         (int nBaseItem, int nFeat) {
     return NWNXWeaponsTwo(GetModule(), "NWNX!WEAPONS!SETWEAPONGREATERFOCUSFEAT",         nBaseItem, nFeat); 
}

int SetWeaponImprovedCriticalFeat     (int nBaseItem, int nFeat) {
     return NWNXWeaponsTwo(GetModule(), "NWNX!WEAPONS!SETWEAPONIMPROVEDCRITICALFEAT",     nBaseItem, nFeat); 
}

int SetWeaponLegendaryFocusFeat       (int nBaseItem, int nFeat) {
     return NWNXWeaponsTwo(GetModule(), "NWNX!WEAPONS!SETWEAPONLEGENDARYFOCUSFEAT",       nBaseItem, nFeat); 
}

int SetWeaponOfChoiceFeat             (int nBaseItem, int nFeat) {
     return NWNXWeaponsTwo(GetModule(), "NWNX!WEAPONS!SETWEAPONOFCHOICEFEAT",             nBaseItem, nFeat); 
}

int SetWeaponOverwhelmingCriticalFeat (int nBaseItem, int nFeat) {
     return NWNXWeaponsTwo(GetModule(), "NWNX!WEAPONS!SETWEAPONOVERWHELMINGCRITICALFEAT", nBaseItem, nFeat); 
}

int SetWeaponPowerCriticalFeat        (int nBaseItem, int nFeat) {
     return NWNXWeaponsTwo(GetModule(), "NWNX!WEAPONS!SETWEAPONPOWERCRITICALFEAT",        nBaseItem, nFeat); 
}

int SetWeaponSpecializationFeat       (int nBaseItem, int nFeat) {
     return NWNXWeaponsTwo(GetModule(), "NWNX!WEAPONS!SETWEAPONSPECIALIZATIONFEAT",       nBaseItem, nFeat); 
}

int SetWeaponSuperiorCriticalFeat     (int nBaseItem, int nFeat) {
     return NWNXWeaponsTwo(GetModule(), "NWNX!WEAPONS!SETWEAPONSUPERIORCRITICALFEAT",     nBaseItem, nFeat); }
