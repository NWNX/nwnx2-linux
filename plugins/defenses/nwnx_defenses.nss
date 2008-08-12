/* interface functions for nwnx_defenses plugin */

/* Set minimum/maximum alignment values for paladin/blackguard saves. */
const int NWNX_DEFENSES_OPT_PALADIN_SAVES_MIN_ALIGN_GE    =   0; 
const int NWNX_DEFENSES_OPT_PALADIN_SAVES_MIN_ALIGN_LC    =   1; 
const int NWNX_DEFENSES_OPT_BLACKGUARD_SAVES_MAX_ALIGN_GE =   2; 
const int NWNX_DEFENSES_OPT_BLACKGUARD_SAVES_MAX_ALIGN_LC =   3; 

/* Set whether or not Death Attack and Sneak Attack should ignore immunity to
 * critical hits.
 */
const int NWNX_DEFENSES_OPT_DEATHATT_IGNORE_CRIT_IMM      =   4;
const int NWNX_DEFENSES_OPT_SNEAKATT_IGNORE_CRIT_IMM      =   5;

/* AC type constants for GetACByType(). */
const int AC_STRENGTH_BONUS                               = -15;
const int AC_DEXTERITY_BONUS                              = -14;
const int AC_CONSTITUTION_BONUS                           = -13;
const int AC_INTELLIGENCE_BONUS                           = -12;
const int AC_CHARISMA_BONUS                               = -11;
const int AC_EQUIP_BONUS                                  = -10;
const int AC_SKILL_BONUS                                  =  -9;
const int AC_CLASS_BONUS                                  =  -8;
const int AC_FEAT_BONUS                                   =  -7;
const int AC_WISDOM_BONUS                                 =  -6;
const int AC_OTHER_BONUS                                  =  -5;
const int AC_TOUCH_BASE                                   =  -4;
const int AC_SHIELD_BASE                                  =  -3;
const int AC_ARMOUR_BASE                                  =  -2;
const int AC_NATURAL_BASE                                 =  -1;


/* Get and set NWNX_DEFENSES_OPT_* options. */
int GetDefenseOption (int nOption);
int SetDefenseOption (int nOption, int nValue);

/* Get oCreature's AC of the specified type. */
int GetACByType (object oCreature, int nACType=AC_DODGE_BONUS);

/* Get oTarget's AC against oAttacker. */
int GetACVersus (object oAttacker, object oTarget=OBJECT_SELF);

/* Get oCreature's true total damage immunity against the specified type. */
int GetTrueDamageImmunity (object oCreature, int nDamType);


int NWNXDefensesZero (object oObject, string sFunc) {
    SetLocalString(oObject, sFunc, "          ");
    return StringToInt(GetLocalString(oObject, sFunc));
}

int NWNXDefensesOne (object oObject, string sFunc, int nVal1) {
    SetLocalString(oObject, sFunc, IntToString(nVal1) + "          ");
    return StringToInt(GetLocalString(oObject, sFunc));
}

int NWNXDefensesTwo (object oObject, string sFunc, int nVal1, int nVal2) {
    SetLocalString(oObject, sFunc, IntToString(nVal1) + " " + IntToString(nVal2) + "          ");
    return StringToInt(GetLocalString(oObject, sFunc));
}

int NWNXDefensesThree (object oObject, string sFunc, int nVal1, int nVal2, int nVal3) {
    SetLocalString(oObject, sFunc, IntToString(nVal1) + " " + IntToString(nVal2) +
      " " + IntToString(nVal3) + "          ");
    return StringToInt(GetLocalString(oObject, sFunc));
}


int GetDefenseOption (int nOption) {
    return NWNXDefensesOne(GetModule(), "NWNX!DEFENSES!GETDEFENSEOPTION", nOption); 
}

int SetDefenseOption (int nOption, int nValue) {
    return NWNXDefensesTwo(GetModule(), "NWNX!DEFENSES!SETDEFENSEOPTION", nOption, nValue); 
}

int GetACByType (object oCreature, int nACType=AC_DODGE_BONUS) {
    return NWNXDefensesOne(GetModule(), "NWNX!DEFENSES!GETACBYTYPE", nACType); 
}

int GetACVersus (object oAttacker, object oTarget=OBJECT_SELF) {
    if (!GetIsObjectValid(oAttacker) || !GetIsObjectValid(oTarget))
        return 0;

    SetLocalString(oTarget, "NWNX!DEFENSES!GETACVERSUS",
        ObjectToString(oAttacker) + "          ");
    return StringToInt(GetLocalString(oTarget, "NWNX!DEFENSES!GETACVERSUS"));
}

int GetTrueDamageImmunity (object oCreature, int nDamType) {
    return NWNXDefensesOne(oCreature, "NWNX!DEFENSES!GETTRUEDAMAGEIMMUNITY", nDamType);
}
