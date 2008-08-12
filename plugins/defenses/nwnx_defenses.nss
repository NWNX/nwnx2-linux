/* interface functions for nwnx_defenses plugin */

/* TODO:
 *   Everything.
 */

const int AC_STRENGTH_BONUS                             = -15;
const int AC_DEXTERITY_BONUS                            = -14;
const int AC_CONSTITUTION_BONUS                         = -13;
const int AC_INTELLIGENCE_BONUS                         = -12;
const int AC_CHARISMA_BONUS                             = -11;
const int AC_EQUIP_BONUS                                = -10;
const int AC_SKILL_BONUS                                =  -9;
const int AC_CLASS_BONUS                                =  -8;
const int AC_FEAT_BONUS                                 =  -7;
const int AC_WISDOM_BONUS                               =  -6;
const int AC_OTHER_BONUS                                =  -5;
const int AC_TOUCH_BASE                                 =  -4;
const int AC_SHIELD_BASE                                =  -3;
const int AC_ARMOUR_BASE                                =  -2;
const int AC_NATURAL_BASE                               =  -1;

/* Disable Devastating Critical insta-kill for all beings or for PCs only. */
const int NWNX_DEFENSES_OPT_DEVCRIT_DISABLE_ALL         =   0; 
const int NWNX_DEFENSES_OPT_DEVCRIT_DISABLE_PC          =   1; 

/* Set whether or not Death Attack and Sneak Attack should ignore immunity to
 * critical hits.
 */
const int NWNX_DEFENSES_OPT_DEATHATT_IGNORE_CRIT_IMM    =  25;
const int NWNX_DEFENSES_OPT_SNEAKATT_IGNORE_CRIT_IMM    =  26;


/* Get and set NWNX_DEFENSES_OPT_* options. */
int GetDefenseOption (int nOption);
int SetDefenseOption (int nOption, int nValue);

/* Get oCreature's AC of the specified type. */
int GetACByType (object oCreature, int nACType=AC_DODGE_BONUS);


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
