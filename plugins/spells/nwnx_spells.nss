/* interface functions for nwnx_spells plugin */

/* No options yet. */
const int NWNX_SPELLS_OPT_NO_OPTIONS_YET                  =   0; 


/* Get and set NWNX_SPELLS_OPT_* options. */
int GetSpellOption (int nOption);
int SetSpellOption (int nOption, int nValue);

/* Get nClass's caster ability. */
int GetClassCasterAbility (int nClass);

/* Set nClass's caster ability. */
int SetClassCasterAbility (int nClass, int nAbil);

/* Get the spell level of nSpell for nClass. */
int GetClassSpellLevel (int nClass, int nSpell);

/* Set the spell level of nSpell for nClass. */
int SetClassSpellLevel (int nClass, int nSpell, int nLevel);


int NWNXSpellsZero (object oObject, string sFunc) {
    SetLocalString(oObject, sFunc, "          ");
    return StringToInt(GetLocalString(oObject, sFunc));
}

int NWNXSpellsOne (object oObject, string sFunc, int nVal1) {
    SetLocalString(oObject, sFunc, IntToString(nVal1) + "          ");
    return StringToInt(GetLocalString(oObject, sFunc));
}

int NWNXSpellsTwo (object oObject, string sFunc, int nVal1, int nVal2) {
    SetLocalString(oObject, sFunc, IntToString(nVal1) + " " + IntToString(nVal2) + "          ");
    return StringToInt(GetLocalString(oObject, sFunc));
}

int NWNXSpellsThree (object oObject, string sFunc, int nVal1, int nVal2, int nVal3) {
    SetLocalString(oObject, sFunc, IntToString(nVal1) + " " + IntToString(nVal2) +
      " " + IntToString(nVal3) + "          ");
    return StringToInt(GetLocalString(oObject, sFunc));
}

int NWNXSpellsFour (object oObject, string sFunc, int nVal1, int nVal2, int nVal3, int nVal4) {
    SetLocalString(oObject, sFunc, IntToString(nVal1) + " " + IntToString(nVal2) +
      " " + IntToString(nVal3) + " " + IntToString(nVal4) + "          ");
    return StringToInt(GetLocalString(oObject, sFunc));
}


int GetSpellOption (int nOption) {
    return NWNXSpellsOne(GetModule(), "NWNX!SPELLS!GETSPELLOPTION", nOption); 
}

int SetSpellOption (int nOption, int nValue) {
    return NWNXSpellsTwo(GetModule(), "NWNX!SPELLS!SETSPELLOPTION", nOption, nValue); 
}


int GetClassCasterAbility (int nClass) {
    return NWNXSpellsOne(GetModule(), "NWNX!SPELLS!GETCLASSCASTERABILITY", nClass); 
}

int SetClassCasterAbility (int nClass, int nAbil) {
    return NWNXSpellsTwo(GetModule(), "NWNX!SPELLS!SETCLASSCASTERABILITY", nClass, nAbil); 
}


int GetClassSpellLevel (int nClass, int nSpell) {
    return NWNXSpellsTwo(GetModule(), "NWNX!SPELLS!GETCLASSSPELLLEVEL", nClass, nSpell); 
}

int SetClassSpellLevel (int nClass, int nSpell, int nLevel) {
    return NWNXSpellsThree(GetModule(), "NWNX!SPELLS!SETCLASSSPELLLEVEL", nClass, nSpell, nLevel); 
}

