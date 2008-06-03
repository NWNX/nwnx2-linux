/* CalculateStructs duration basis. This must be called with a PC or creature
 * as a target before any calls to GetEffectDurationRemaining() or
 * GetItemPropertyDurationRemaining().
 *
 * It only needs to be called once, so it can be called during module
 * startup or when the first PC logs in.
 *
 * Depending on as-yet-undetermined internals of how the server keeps
 * track of time, it may be necessary to re-call this. More testing
 * needs to be done to see if the basis drifts. */
void CalculateStructDurationBasis (object oTarget);

/* Returns the duration specified at ApplyEffectToObject() time for
 * the effect. The value of this is undefined for effects which are
 * not of DURATION_TYPE_TEMPORARY. */
float GetEffectDuration (effect eEffect);

/* Returns the remaining duration of the specified effect. The value
 * of this is undefined for effects which are not of
 * DURATION_TYPE_TEMPORARY. */
float GetEffectDurationRemaining (effect eEffect);

/* Returns the internal effect integer at the index specified. The index
 * is limited to being between 0 and 15, and which index contains what
 * value depends entirely on the type of effect. */
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

void CalculateStructDurationBasisExtract (effect eEffect) {
    SetLocalString(GetModule(), "NWNX!STRUCTS!CALCDURATIONBASIS", "300");
}

void CalculateStructDurationBasisFinish (object oTarget) {
    effect eEffect = GetFirstEffect(oTarget);

    while (GetIsEffectValid(eEffect)) {
        if (GetEffectSpellId(eEffect) == 562951413) {
            CalculateStructDurationBasisExtract(eEffect);

            RemoveEffect(oTarget, eEffect);
            break;
        }

        eEffect = GetNextEffect(oTarget);
    }
}

void CalculateStructDurationBasis (object oTarget) {
    SetLocalString(GetModule(), "NWNX!STRUCTS!SETDURATIONBASIS", "      ");

    effect eEffect = EffectVisualEffect(VFX_DUR_LIGHT_GREY_5);
    SetEffectSpellId(eEffect, 562951413);  /* pi backwards */

    ApplyEffectToObject(DURATION_TYPE_TEMPORARY, eEffect, oTarget, 300.0);

    DelayCommand(1.0, CalculateStructDurationBasisFinish(oTarget));
}

float GetEffectDuration (effect eEffect) {
    SetLocalString(GetModule(), "NWNX!STRUCTS!GETDURATION", "          ");
    return StringToFloat(GetLocalString(GetModule(),
        "NWNX!STRUCTS!GETDURATION"));
}

float GetEffectDurationRemaining (effect eEffect) {
    SetLocalString(GetModule(), "NWNX!STRUCTS!GETDURATIONREMAINING",
        "          ");
    return StringToFloat(GetLocalString(GetModule(),
        "NWNX!STRUCTS!GETDURATIONREMAINING"));
}

int GetEffectInteger (effect eEffect, int nIndex) {
    SetLocalString(GetModule(), "NWNX!STRUCTS!GETINTEGER",
        IntToString(nIndex) + "          ");
    return StringToInt(GetLocalString(GetModule(), "NWNX!STRUCTS!GETINTEGER"));
}

void SetEffectInteger (effect eEffect, int nIndex, int nValue) {
    SetLocalString(GetModule(), "NWNX!STRUCTS!SETINTEGER",
        IntToString(nIndex) + " " + IntToString(nValue));
}

void SetEffectSpellId (effect eEffect, int nSpellId) {
    SetLocalString(GetModule(), "NWNX!STRUCTS!SETSPELLID",
        IntToString(nSpellId));
}

float GetItemPropertyDuration (itemproperty ipProp) {
    SetLocalString(GetModule(), "NWNX!STRUCTS!GETDURATION", "          ");
    return StringToFloat(GetLocalString(GetModule(),
        "NWNX!STRUCTS!GETDURATION"));
}

float GetItemPropertyDurationRemaining (itemproperty ipProp) {
    SetLocalString(GetModule(), "NWNX!STRUCTS!GETDURATIONREMAINING",
        "          ");
    return StringToFloat(GetLocalString(GetModule(),
        "NWNX!STRUCTS!GETDURATIONREMAINING"));
}

int GetItemPropertyInteger (itemproperty ipProp, int nIndex) {
    SetLocalString(GetModule(), "NWNX!STRUCTS!GETINTEGER",
        IntToString(nIndex) + "          ");
    return StringToInt(GetLocalString(GetModule(), "NWNX!STRUCTS!GETINTEGER"));
}

void SetItemPropertyInteger (itemproperty ipProp, int nIndex, int nValue) {
    SetLocalString(GetModule(), "NWNX!STRUCTS!SETINTEGER",
        IntToString(nIndex) + " " + IntToString(nValue));
}

int GetItemPropertySpellId (itemproperty ipProp) {
    SetLocalString(GetModule(), "NWNX!STRUCTS!GETSPELLID", "          ");
    return StringToInt(GetLocalString(GetModule(), "NWNX!STRUCTS!GETSPELLID"));
}

void SetItemPropertySpellId (itemproperty ipProp, int nSpellId) {
    SetLocalString(GetModule(), "NWNX!STRUCTS!SETSPELLID",
        IntToString(nSpellId));
}
