/* interface functions for nwnx_defenses plugin */

/* TODO:
 *   Everything.
 */

/* Disable Devastating Critical insta-kill for all beings or for PCs only. */
const int NWNX_DEFENSES_OPT_DEVCRIT_DISABLE_ALL     =  0; 
const int NWNX_DEFENSES_OPT_DEVCRIT_DISABLE_PC      =  1; 

/* Set whether or not Death Attack and Sneak Attack should ignore immunity to
 * critical hits.
 */
const int NWNX_WEAPONS_OPT_DEATHATT_IGNORE_CRIT_IMM  = 25;
const int NWNX_WEAPONS_OPT_SNEAKATT_IGNORE_CRIT_IMM  = 26;

/* Get and set NWNX_DEFENSES_OPT_* options. */
int GetDefenseOption (int nOption);
int SetDefenseOption (int nOption, int nValue);


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
    return NWNXDefensesOne(GetModule(), "NWNX!DEFENSES!GETWEAPONOPTION", nOption); 
}

int SetDefenseOption (int nOption, int nValue) {
    return NWNXDefensesOne(GetModule(), "NWNX!DEFENSES!GETWEAPONOPTION", nOption, nValue); 
}


