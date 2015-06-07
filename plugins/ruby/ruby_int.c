#include "FunctionHooks.h"
#include "ruby_int.h"

static VALUE NWScript_Random(VALUE self, VALUE nMaxInteger)
{
    StackPushInteger(NUM2INT(nMaxInteger));
    VM_ExecuteCommand(0, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_PrintString(VALUE self, VALUE sString)
{
    StackPushString(StringValueCStr(sString));
    VM_ExecuteCommand(1, 1);
    return Qnil;
}

static VALUE NWScript_PrintFloat(int argc, VALUE *argv, VALUE self)
{
    VALUE fFloat, nWidth, nDecimals;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    fFloat = argv[0];
    if (argc > 1) nWidth = argv[1];
    else nWidth = INT2NUM(18);
    if (argc > 2) nDecimals = argv[2];
    else nDecimals = INT2NUM(9);
    StackPushInteger(NUM2INT(nDecimals));
    StackPushInteger(NUM2INT(nWidth));
    StackPushFloat(NUM2DBL(fFloat));
    VM_ExecuteCommand(2, 3);
    return Qnil;
}

static VALUE NWScript_FloatToString(int argc, VALUE *argv, VALUE self)
{
    VALUE fFloat, nWidth, nDecimals;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    fFloat = argv[0];
    if (argc > 1) nWidth = argv[1];
    else nWidth = INT2NUM(18);
    if (argc > 2) nDecimals = argv[2];
    else nDecimals = INT2NUM(9);
    StackPushInteger(NUM2INT(nDecimals));
    StackPushInteger(NUM2INT(nWidth));
    StackPushFloat(NUM2DBL(fFloat));
    VM_ExecuteCommand(3, 3);
    char *sRetVal;
    StackPopString(&sRetVal);
    return rb_str_new2(sRetVal);
}

static VALUE NWScript_PrintInteger(VALUE self, VALUE nInteger)
{
    StackPushInteger(NUM2INT(nInteger));
    VM_ExecuteCommand(4, 1);
    return Qnil;
}

static VALUE NWScript_PrintObject(VALUE self, VALUE oObject)
{
    StackPushObject(NUM2UINT(oObject));
    VM_ExecuteCommand(5, 1);
    return Qnil;
}

static VALUE NWScript_AssignCommand(VALUE self, VALUE oActionSubject, VALUE aActionToAssign)
{
    //ERROR: Undefined variable type: action
    StackPushObject(NUM2UINT(oActionSubject));
    VM_ExecuteCommand(6, 2);
    return Qnil;
}

static VALUE NWScript_DelayCommand(VALUE self, VALUE fSeconds, VALUE aActionToDelay)
{
    //ERROR: Undefined variable type: action
    StackPushFloat(NUM2DBL(fSeconds));
    VM_ExecuteCommand(7, 2);
    return Qnil;
}

static VALUE NWScript_ExecuteScript(VALUE self, VALUE sScript, VALUE oTarget)
{
    StackPushObject(NUM2UINT(oTarget));
    StackPushString(StringValueCStr(sScript));
    VM_ExecuteCommand(8, 2);
    return Qnil;
}

static VALUE NWScript_ClearAllActions(int argc, VALUE *argv, VALUE self)
{
    VALUE nClearCombatState;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) nClearCombatState = argv[0];
    else nClearCombatState = INT2NUM(FALSE);
    StackPushInteger(NUM2INT(nClearCombatState));
    VM_ExecuteCommand(9, 1);
    return Qnil;
}

static VALUE NWScript_SetFacing(VALUE self, VALUE fDirection)
{
    StackPushFloat(NUM2DBL(fDirection));
    VM_ExecuteCommand(10, 1);
    return Qnil;
}

static VALUE NWScript_SetCalendar(VALUE self, VALUE nYear, VALUE nMonth, VALUE nDay)
{
    StackPushInteger(NUM2INT(nDay));
    StackPushInteger(NUM2INT(nMonth));
    StackPushInteger(NUM2INT(nYear));
    VM_ExecuteCommand(11, 3);
    return Qnil;
}

static VALUE NWScript_SetTime(VALUE self, VALUE nHour, VALUE nMinute, VALUE nSecond, VALUE nMillisecond)
{
    StackPushInteger(NUM2INT(nMillisecond));
    StackPushInteger(NUM2INT(nSecond));
    StackPushInteger(NUM2INT(nMinute));
    StackPushInteger(NUM2INT(nHour));
    VM_ExecuteCommand(12, 4);
    return Qnil;
}

static VALUE NWScript_GetCalendarYear(VALUE self)
{
    VM_ExecuteCommand(13, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetCalendarMonth(VALUE self)
{
    VM_ExecuteCommand(14, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetCalendarDay(VALUE self)
{
    VM_ExecuteCommand(15, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetTimeHour(VALUE self)
{
    VM_ExecuteCommand(16, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetTimeMinute(VALUE self)
{
    VM_ExecuteCommand(17, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetTimeSecond(VALUE self)
{
    VM_ExecuteCommand(18, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetTimeMillisecond(VALUE self)
{
    VM_ExecuteCommand(19, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_ActionRandomWalk(VALUE self)
{
    VM_ExecuteCommand(20, 0);
    return Qnil;
}

static VALUE NWScript_ActionMoveToLocation(int argc, VALUE *argv, VALUE self)
{
    VALUE lDestination, bRun;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    lDestination = argv[0];
    if (argc > 1) bRun = argv[1];
    else bRun = INT2NUM(FALSE);
    StackPushInteger(NUM2INT(bRun));
    CScriptLocation *lDestination_ptr;
    Data_Get_Struct(lDestination, CScriptLocation, lDestination_ptr);
    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lDestination_ptr);
    VM_ExecuteCommand(21, 2);
    return Qnil;
}

static VALUE NWScript_ActionMoveToObject(int argc, VALUE *argv, VALUE self)
{
    VALUE oMoveTo, bRun, fRange;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    oMoveTo = argv[0];
    if (argc > 1) bRun = argv[1];
    else bRun = INT2NUM(FALSE);
    if (argc > 2) fRange = argv[2];
    else fRange = rb_float_new(1.0f);
    StackPushFloat(NUM2DBL(fRange));
    StackPushInteger(NUM2INT(bRun));
    StackPushObject(NUM2UINT(oMoveTo));
    VM_ExecuteCommand(22, 3);
    return Qnil;
}

static VALUE NWScript_ActionMoveAwayFromObject(int argc, VALUE *argv, VALUE self)
{
    VALUE oFleeFrom, bRun, fMoveAwayRange;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    oFleeFrom = argv[0];
    if (argc > 1) bRun = argv[1];
    else bRun = INT2NUM(FALSE);
    if (argc > 2) fMoveAwayRange = argv[2];
    else fMoveAwayRange = rb_float_new(40.0f);
    StackPushFloat(NUM2DBL(fMoveAwayRange));
    StackPushInteger(NUM2INT(bRun));
    StackPushObject(NUM2UINT(oFleeFrom));
    VM_ExecuteCommand(23, 3);
    return Qnil;
}

static VALUE NWScript_GetArea(VALUE self, VALUE oTarget)
{
    StackPushObject(NUM2UINT(oTarget));
    VM_ExecuteCommand(24, 1);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetEnteringObject(VALUE self)
{
    VM_ExecuteCommand(25, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetExitingObject(VALUE self)
{
    VM_ExecuteCommand(26, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetPosition(VALUE self, VALUE oTarget)
{
    StackPushObject(NUM2UINT(oTarget));
    VM_ExecuteCommand(27, 1);
    Vector *vRetVal = (Vector *) malloc(sizeof(Vector));
    StackPopVector(vRetVal);
    return Data_Wrap_Struct(g_cVectorClass, 0, free, vRetVal);
}

static VALUE NWScript_GetFacing(VALUE self, VALUE oTarget)
{
    StackPushObject(NUM2UINT(oTarget));
    VM_ExecuteCommand(28, 1);
    float fRetVal;
    StackPopFloat(&fRetVal);
    return rb_float_new(fRetVal);
}

static VALUE NWScript_GetItemPossessor(VALUE self, VALUE oItem)
{
    StackPushObject(NUM2UINT(oItem));
    VM_ExecuteCommand(29, 1);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetItemPossessedBy(VALUE self, VALUE oCreature, VALUE sItemTag)
{
    StackPushString(StringValueCStr(sItemTag));
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(30, 2);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_CreateItemOnObject(int argc, VALUE *argv, VALUE self)
{
    VALUE sItemTemplate, oTarget, nStackSize, sNewTag;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    sItemTemplate = argv[0];
    if (argc > 1) oTarget = argv[1];
    else oTarget = INT2NUM(OBJECT_SELF);
    if (argc > 2) nStackSize = argv[2];
    else nStackSize = INT2NUM(1);
    if (argc > 3) sNewTag = argv[3];
    else sNewTag = rb_str_new2("");
    StackPushString(StringValueCStr(sNewTag));
    StackPushInteger(NUM2INT(nStackSize));
    StackPushObject(NUM2UINT(oTarget));
    StackPushString(StringValueCStr(sItemTemplate));
    VM_ExecuteCommand(31, 4);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_ActionEquipItem(VALUE self, VALUE oItem, VALUE nInventorySlot)
{
    StackPushInteger(NUM2INT(nInventorySlot));
    StackPushObject(NUM2UINT(oItem));
    VM_ExecuteCommand(32, 2);
    return Qnil;
}

static VALUE NWScript_ActionUnequipItem(VALUE self, VALUE oItem)
{
    StackPushObject(NUM2UINT(oItem));
    VM_ExecuteCommand(33, 1);
    return Qnil;
}

static VALUE NWScript_ActionPickUpItem(VALUE self, VALUE oItem)
{
    StackPushObject(NUM2UINT(oItem));
    VM_ExecuteCommand(34, 1);
    return Qnil;
}

static VALUE NWScript_ActionPutDownItem(VALUE self, VALUE oItem)
{
    StackPushObject(NUM2UINT(oItem));
    VM_ExecuteCommand(35, 1);
    return Qnil;
}

static VALUE NWScript_GetLastAttacker(int argc, VALUE *argv, VALUE self)
{
    VALUE oAttackee;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oAttackee = argv[0];
    else oAttackee = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oAttackee));
    VM_ExecuteCommand(36, 1);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_ActionAttack(int argc, VALUE *argv, VALUE self)
{
    VALUE oAttackee, bPassive;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    oAttackee = argv[0];
    if (argc > 1) bPassive = argv[1];
    else bPassive = INT2NUM(FALSE);
    StackPushInteger(NUM2INT(bPassive));
    StackPushObject(NUM2UINT(oAttackee));
    VM_ExecuteCommand(37, 2);
    return Qnil;
}

static VALUE NWScript_GetNearestCreature(int argc, VALUE *argv, VALUE self)
{
    VALUE nFirstCriteriaType, nFirstCriteriaValue, oTarget, nNth, nSecondCriteriaType, nSecondCriteriaValue, nThirdCriteriaType, nThirdCriteriaValue;
    if (argc < 2) {
        //TODO: Raise exception
        return Qnil;
    }
    nFirstCriteriaType = argv[0];
    nFirstCriteriaValue = argv[1];
    if (argc > 2) oTarget = argv[2];
    else oTarget = INT2NUM(OBJECT_SELF);
    if (argc > 3) nNth = argv[3];
    else nNth = INT2NUM(1);
    if (argc > 4) nSecondCriteriaType = argv[4];
    else nSecondCriteriaType = INT2NUM(-1);
    if (argc > 5) nSecondCriteriaValue = argv[5];
    else nSecondCriteriaValue = INT2NUM(-1);
    if (argc > 6) nThirdCriteriaType = argv[6];
    else nThirdCriteriaType = INT2NUM(-1);
    if (argc > 7) nThirdCriteriaValue = argv[7];
    else nThirdCriteriaValue = INT2NUM(-1);
    StackPushInteger(NUM2INT(nThirdCriteriaValue));
    StackPushInteger(NUM2INT(nThirdCriteriaType));
    StackPushInteger(NUM2INT(nSecondCriteriaValue));
    StackPushInteger(NUM2INT(nSecondCriteriaType));
    StackPushInteger(NUM2INT(nNth));
    StackPushObject(NUM2UINT(oTarget));
    StackPushInteger(NUM2INT(nFirstCriteriaValue));
    StackPushInteger(NUM2INT(nFirstCriteriaType));
    VM_ExecuteCommand(38, 8);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_ActionSpeakString(int argc, VALUE *argv, VALUE self)
{
    VALUE sStringToSpeak, nTalkVolume;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    sStringToSpeak = argv[0];
    if (argc > 1) nTalkVolume = argv[1];
    else nTalkVolume = INT2NUM(TALKVOLUME_TALK);
    StackPushInteger(NUM2INT(nTalkVolume));
    StackPushString(StringValueCStr(sStringToSpeak));
    VM_ExecuteCommand(39, 2);
    return Qnil;
}

static VALUE NWScript_ActionPlayAnimation(int argc, VALUE *argv, VALUE self)
{
    VALUE nAnimation, fSpeed, fDurationSeconds;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    nAnimation = argv[0];
    if (argc > 1) fSpeed = argv[1];
    else fSpeed = rb_float_new(1.0);
    if (argc > 2) fDurationSeconds = argv[2];
    else fDurationSeconds = rb_float_new(0.0);
    StackPushFloat(NUM2DBL(fDurationSeconds));
    StackPushFloat(NUM2DBL(fSpeed));
    StackPushInteger(NUM2INT(nAnimation));
    VM_ExecuteCommand(40, 3);
    return Qnil;
}

static VALUE NWScript_GetDistanceToObject(VALUE self, VALUE oObject)
{
    StackPushObject(NUM2UINT(oObject));
    VM_ExecuteCommand(41, 1);
    float fRetVal;
    StackPopFloat(&fRetVal);
    return rb_float_new(fRetVal);
}

static VALUE NWScript_GetIsObjectValid(VALUE self, VALUE oObject)
{
    StackPushObject(NUM2UINT(oObject));
    VM_ExecuteCommand(42, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_ActionOpenDoor(VALUE self, VALUE oDoor)
{
    StackPushObject(NUM2UINT(oDoor));
    VM_ExecuteCommand(43, 1);
    return Qnil;
}

static VALUE NWScript_ActionCloseDoor(VALUE self, VALUE oDoor)
{
    StackPushObject(NUM2UINT(oDoor));
    VM_ExecuteCommand(44, 1);
    return Qnil;
}

static VALUE NWScript_SetCameraFacing(int argc, VALUE *argv, VALUE self)
{
    VALUE fDirection, fDistance , fPitch , nTransitionType;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    fDirection = argv[0];
    if (argc > 1) fDistance  = argv[1];
    else fDistance  = rb_float_new(-1.0f);
    if (argc > 2) fPitch  = argv[2];
    else fPitch  = rb_float_new(-1.0);
    if (argc > 3) nTransitionType = argv[3];
    else nTransitionType = INT2NUM(CAMERA_TRANSITION_TYPE_SNAP);
    StackPushInteger(NUM2INT(nTransitionType));
    StackPushFloat(NUM2DBL(fPitch));
    StackPushFloat(NUM2DBL(fDistance));
    StackPushFloat(NUM2DBL(fDirection));
    VM_ExecuteCommand(45, 4);
    return Qnil;
}

static VALUE NWScript_PlaySound(VALUE self, VALUE sSoundName)
{
    StackPushString(StringValueCStr(sSoundName));
    VM_ExecuteCommand(46, 1);
    return Qnil;
}

static VALUE NWScript_GetSpellTargetObject(VALUE self)
{
    VM_ExecuteCommand(47, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_ActionCastSpellAtObject(int argc, VALUE *argv, VALUE self)
{
    VALUE nSpell, oTarget, nMetaMagic, bCheat, nDomainLevel, nProjectilePathType, bInstantSpell;
    if (argc < 2) {
        //TODO: Raise exception
        return Qnil;
    }
    nSpell = argv[0];
    oTarget = argv[1];
    if (argc > 2) nMetaMagic = argv[2];
    else nMetaMagic = INT2NUM(METAMAGIC_ANY);
    if (argc > 3) bCheat = argv[3];
    else bCheat = INT2NUM(FALSE);
    if (argc > 4) nDomainLevel = argv[4];
    else nDomainLevel = INT2NUM(0);
    if (argc > 5) nProjectilePathType = argv[5];
    else nProjectilePathType = INT2NUM(PROJECTILE_PATH_TYPE_DEFAULT);
    if (argc > 6) bInstantSpell = argv[6];
    else bInstantSpell = INT2NUM(FALSE);
    StackPushInteger(NUM2INT(bInstantSpell));
    StackPushInteger(NUM2INT(nProjectilePathType));
    StackPushInteger(NUM2INT(nDomainLevel));
    StackPushInteger(NUM2INT(bCheat));
    StackPushInteger(NUM2INT(nMetaMagic));
    StackPushObject(NUM2UINT(oTarget));
    StackPushInteger(NUM2INT(nSpell));
    VM_ExecuteCommand(48, 7);
    return Qnil;
}

static VALUE NWScript_GetCurrentHitPoints(int argc, VALUE *argv, VALUE self)
{
    VALUE oObject;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oObject = argv[0];
    else oObject = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oObject));
    VM_ExecuteCommand(49, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetMaxHitPoints(int argc, VALUE *argv, VALUE self)
{
    VALUE oObject;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oObject = argv[0];
    else oObject = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oObject));
    VM_ExecuteCommand(50, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLocalInt(VALUE self, VALUE oObject, VALUE sVarName)
{
    StackPushString(StringValueCStr(sVarName));
    StackPushObject(NUM2UINT(oObject));
    VM_ExecuteCommand(51, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLocalFloat(VALUE self, VALUE oObject, VALUE sVarName)
{
    StackPushString(StringValueCStr(sVarName));
    StackPushObject(NUM2UINT(oObject));
    VM_ExecuteCommand(52, 2);
    float fRetVal;
    StackPopFloat(&fRetVal);
    return rb_float_new(fRetVal);
}

static VALUE NWScript_GetLocalString(VALUE self, VALUE oObject, VALUE sVarName)
{
    StackPushString(StringValueCStr(sVarName));
    StackPushObject(NUM2UINT(oObject));
    VM_ExecuteCommand(53, 2);
    char *sRetVal;
    StackPopString(&sRetVal);
    return rb_str_new2(sRetVal);
}

static VALUE NWScript_GetLocalObject(VALUE self, VALUE oObject, VALUE sVarName)
{
    StackPushString(StringValueCStr(sVarName));
    StackPushObject(NUM2UINT(oObject));
    VM_ExecuteCommand(54, 2);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_SetLocalInt(VALUE self, VALUE oObject, VALUE sVarName, VALUE nValue)
{
    StackPushInteger(NUM2INT(nValue));
    StackPushString(StringValueCStr(sVarName));
    StackPushObject(NUM2UINT(oObject));
    VM_ExecuteCommand(55, 3);
    return Qnil;
}

static VALUE NWScript_SetLocalFloat(VALUE self, VALUE oObject, VALUE sVarName, VALUE fValue)
{
    StackPushFloat(NUM2DBL(fValue));
    StackPushString(StringValueCStr(sVarName));
    StackPushObject(NUM2UINT(oObject));
    VM_ExecuteCommand(56, 3);
    return Qnil;
}

static VALUE NWScript_SetLocalString(VALUE self, VALUE oObject, VALUE sVarName, VALUE sValue)
{
    StackPushString(StringValueCStr(sValue));
    StackPushString(StringValueCStr(sVarName));
    StackPushObject(NUM2UINT(oObject));
    VM_ExecuteCommand(57, 3);
    return Qnil;
}

static VALUE NWScript_SetLocalObject(VALUE self, VALUE oObject, VALUE sVarName, VALUE oValue)
{
    StackPushObject(NUM2UINT(oValue));
    StackPushString(StringValueCStr(sVarName));
    StackPushObject(NUM2UINT(oObject));
    VM_ExecuteCommand(58, 3);
    return Qnil;
}

static VALUE NWScript_GetStringLength(VALUE self, VALUE sString)
{
    StackPushString(StringValueCStr(sString));
    VM_ExecuteCommand(59, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetStringUpperCase(VALUE self, VALUE sString)
{
    StackPushString(StringValueCStr(sString));
    VM_ExecuteCommand(60, 1);
    char *sRetVal;
    StackPopString(&sRetVal);
    return rb_str_new2(sRetVal);
}

static VALUE NWScript_GetStringLowerCase(VALUE self, VALUE sString)
{
    StackPushString(StringValueCStr(sString));
    VM_ExecuteCommand(61, 1);
    char *sRetVal;
    StackPopString(&sRetVal);
    return rb_str_new2(sRetVal);
}

static VALUE NWScript_GetStringRight(VALUE self, VALUE sString, VALUE nCount)
{
    StackPushInteger(NUM2INT(nCount));
    StackPushString(StringValueCStr(sString));
    VM_ExecuteCommand(62, 2);
    char *sRetVal;
    StackPopString(&sRetVal);
    return rb_str_new2(sRetVal);
}

static VALUE NWScript_GetStringLeft(VALUE self, VALUE sString, VALUE nCount)
{
    StackPushInteger(NUM2INT(nCount));
    StackPushString(StringValueCStr(sString));
    VM_ExecuteCommand(63, 2);
    char *sRetVal;
    StackPopString(&sRetVal);
    return rb_str_new2(sRetVal);
}

static VALUE NWScript_InsertString(VALUE self, VALUE sDestination, VALUE sString, VALUE nPosition)
{
    StackPushInteger(NUM2INT(nPosition));
    StackPushString(StringValueCStr(sString));
    StackPushString(StringValueCStr(sDestination));
    VM_ExecuteCommand(64, 3);
    char *sRetVal;
    StackPopString(&sRetVal);
    return rb_str_new2(sRetVal);
}

static VALUE NWScript_GetSubString(VALUE self, VALUE sString, VALUE nStart, VALUE nCount)
{
    StackPushInteger(NUM2INT(nCount));
    StackPushInteger(NUM2INT(nStart));
    StackPushString(StringValueCStr(sString));
    VM_ExecuteCommand(65, 3);
    char *sRetVal;
    StackPopString(&sRetVal);
    return rb_str_new2(sRetVal);
}

static VALUE NWScript_FindSubString(int argc, VALUE *argv, VALUE self)
{
    VALUE sString, sSubString, nStart;
    if (argc < 2) {
        //TODO: Raise exception
        return Qnil;
    }
    sString = argv[0];
    sSubString = argv[1];
    if (argc > 2) nStart = argv[2];
    else nStart = INT2NUM(0);
    StackPushInteger(NUM2INT(nStart));
    StackPushString(StringValueCStr(sSubString));
    StackPushString(StringValueCStr(sString));
    VM_ExecuteCommand(66, 3);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_fabs(VALUE self, VALUE fValue)
{
    StackPushFloat(NUM2DBL(fValue));
    VM_ExecuteCommand(67, 1);
    float fRetVal;
    StackPopFloat(&fRetVal);
    return rb_float_new(fRetVal);
}

static VALUE NWScript_cos(VALUE self, VALUE fValue)
{
    StackPushFloat(NUM2DBL(fValue));
    VM_ExecuteCommand(68, 1);
    float fRetVal;
    StackPopFloat(&fRetVal);
    return rb_float_new(fRetVal);
}

static VALUE NWScript_sin(VALUE self, VALUE fValue)
{
    StackPushFloat(NUM2DBL(fValue));
    VM_ExecuteCommand(69, 1);
    float fRetVal;
    StackPopFloat(&fRetVal);
    return rb_float_new(fRetVal);
}

static VALUE NWScript_tan(VALUE self, VALUE fValue)
{
    StackPushFloat(NUM2DBL(fValue));
    VM_ExecuteCommand(70, 1);
    float fRetVal;
    StackPopFloat(&fRetVal);
    return rb_float_new(fRetVal);
}

static VALUE NWScript_acos(VALUE self, VALUE fValue)
{
    StackPushFloat(NUM2DBL(fValue));
    VM_ExecuteCommand(71, 1);
    float fRetVal;
    StackPopFloat(&fRetVal);
    return rb_float_new(fRetVal);
}

static VALUE NWScript_asin(VALUE self, VALUE fValue)
{
    StackPushFloat(NUM2DBL(fValue));
    VM_ExecuteCommand(72, 1);
    float fRetVal;
    StackPopFloat(&fRetVal);
    return rb_float_new(fRetVal);
}

static VALUE NWScript_atan(VALUE self, VALUE fValue)
{
    StackPushFloat(NUM2DBL(fValue));
    VM_ExecuteCommand(73, 1);
    float fRetVal;
    StackPopFloat(&fRetVal);
    return rb_float_new(fRetVal);
}

static VALUE NWScript_log(VALUE self, VALUE fValue)
{
    StackPushFloat(NUM2DBL(fValue));
    VM_ExecuteCommand(74, 1);
    float fRetVal;
    StackPopFloat(&fRetVal);
    return rb_float_new(fRetVal);
}

static VALUE NWScript_pow(VALUE self, VALUE fValue, VALUE fExponent)
{
    StackPushFloat(NUM2DBL(fExponent));
    StackPushFloat(NUM2DBL(fValue));
    VM_ExecuteCommand(75, 2);
    float fRetVal;
    StackPopFloat(&fRetVal);
    return rb_float_new(fRetVal);
}

static VALUE NWScript_sqrt(VALUE self, VALUE fValue)
{
    StackPushFloat(NUM2DBL(fValue));
    VM_ExecuteCommand(76, 1);
    float fRetVal;
    StackPopFloat(&fRetVal);
    return rb_float_new(fRetVal);
}

static VALUE NWScript_abs(VALUE self, VALUE nValue)
{
    StackPushInteger(NUM2INT(nValue));
    VM_ExecuteCommand(77, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_EffectHeal(VALUE self, VALUE nDamageToHeal)
{
    StackPushInteger(NUM2INT(nDamageToHeal));
    VM_ExecuteCommand(78, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_EffectDamage(int argc, VALUE *argv, VALUE self)
{
    VALUE nDamageAmount, nDamageType, nDamagePower;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    nDamageAmount = argv[0];
    if (argc > 1) nDamageType = argv[1];
    else nDamageType = INT2NUM(DAMAGE_TYPE_MAGICAL);
    if (argc > 2) nDamagePower = argv[2];
    else nDamagePower = INT2NUM(DAMAGE_POWER_NORMAL);
    StackPushInteger(NUM2INT(nDamagePower));
    StackPushInteger(NUM2INT(nDamageType));
    StackPushInteger(NUM2INT(nDamageAmount));
    VM_ExecuteCommand(79, 3);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_EffectAbilityIncrease(VALUE self, VALUE nAbilityToIncrease, VALUE nModifyBy)
{
    StackPushInteger(NUM2INT(nModifyBy));
    StackPushInteger(NUM2INT(nAbilityToIncrease));
    VM_ExecuteCommand(80, 2);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_EffectDamageResistance(int argc, VALUE *argv, VALUE self)
{
    VALUE nDamageType, nAmount, nLimit;
    if (argc < 2) {
        //TODO: Raise exception
        return Qnil;
    }
    nDamageType = argv[0];
    nAmount = argv[1];
    if (argc > 2) nLimit = argv[2];
    else nLimit = INT2NUM(0);
    StackPushInteger(NUM2INT(nLimit));
    StackPushInteger(NUM2INT(nAmount));
    StackPushInteger(NUM2INT(nDamageType));
    VM_ExecuteCommand(81, 3);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_EffectResurrection(VALUE self)
{
    VM_ExecuteCommand(82, 0);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_EffectSummonCreature(int argc, VALUE *argv, VALUE self)
{
    VALUE sCreatureResref, nVisualEffectId, fDelaySeconds, nUseAppearAnimation;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    sCreatureResref = argv[0];
    if (argc > 1) nVisualEffectId = argv[1];
    else nVisualEffectId = INT2NUM(VFX_NONE);
    if (argc > 2) fDelaySeconds = argv[2];
    else fDelaySeconds = rb_float_new(0.0f);
    if (argc > 3) nUseAppearAnimation = argv[3];
    else nUseAppearAnimation = INT2NUM(0);
    StackPushInteger(NUM2INT(nUseAppearAnimation));
    StackPushFloat(NUM2DBL(fDelaySeconds));
    StackPushInteger(NUM2INT(nVisualEffectId));
    StackPushString(StringValueCStr(sCreatureResref));
    VM_ExecuteCommand(83, 4);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_GetCasterLevel(VALUE self, VALUE oCreature)
{
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(84, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetFirstEffect(VALUE self, VALUE oCreature)
{
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(85, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_GetNextEffect(VALUE self, VALUE oCreature)
{
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(86, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_RemoveEffect(VALUE self, VALUE oCreature, VALUE eEffect)
{
    CGameEffect *eEffect_ptr;
    Data_Get_Struct(eEffect, CGameEffect, eEffect_ptr);
    StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eEffect_ptr);
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(87, 2);
    return Qnil;
}

static VALUE NWScript_GetIsEffectValid(VALUE self, VALUE eEffect)
{
    CGameEffect *eEffect_ptr;
    Data_Get_Struct(eEffect, CGameEffect, eEffect_ptr);
    StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eEffect_ptr);
    VM_ExecuteCommand(88, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetEffectDurationType(VALUE self, VALUE eEffect)
{
    CGameEffect *eEffect_ptr;
    Data_Get_Struct(eEffect, CGameEffect, eEffect_ptr);
    StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eEffect_ptr);
    VM_ExecuteCommand(89, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetEffectSubType(VALUE self, VALUE eEffect)
{
    CGameEffect *eEffect_ptr;
    Data_Get_Struct(eEffect, CGameEffect, eEffect_ptr);
    StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eEffect_ptr);
    VM_ExecuteCommand(90, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetEffectCreator(VALUE self, VALUE eEffect)
{
    CGameEffect *eEffect_ptr;
    Data_Get_Struct(eEffect, CGameEffect, eEffect_ptr);
    StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eEffect_ptr);
    VM_ExecuteCommand(91, 1);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_IntToString(VALUE self, VALUE nInteger)
{
    StackPushInteger(NUM2INT(nInteger));
    VM_ExecuteCommand(92, 1);
    char *sRetVal;
    StackPopString(&sRetVal);
    return rb_str_new2(sRetVal);
}

static VALUE NWScript_GetFirstObjectInArea(int argc, VALUE *argv, VALUE self)
{
    VALUE oArea;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oArea = argv[0];
    else oArea = INT2NUM(OBJECT_INVALID);
    StackPushObject(NUM2UINT(oArea));
    VM_ExecuteCommand(93, 1);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetNextObjectInArea(int argc, VALUE *argv, VALUE self)
{
    VALUE oArea;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oArea = argv[0];
    else oArea = INT2NUM(OBJECT_INVALID);
    StackPushObject(NUM2UINT(oArea));
    VM_ExecuteCommand(94, 1);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_d2(int argc, VALUE *argv, VALUE self)
{
    VALUE nNumDice;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) nNumDice = argv[0];
    else nNumDice = INT2NUM(1);
    StackPushInteger(NUM2INT(nNumDice));
    VM_ExecuteCommand(95, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_d3(int argc, VALUE *argv, VALUE self)
{
    VALUE nNumDice;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) nNumDice = argv[0];
    else nNumDice = INT2NUM(1);
    StackPushInteger(NUM2INT(nNumDice));
    VM_ExecuteCommand(96, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_d4(int argc, VALUE *argv, VALUE self)
{
    VALUE nNumDice;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) nNumDice = argv[0];
    else nNumDice = INT2NUM(1);
    StackPushInteger(NUM2INT(nNumDice));
    VM_ExecuteCommand(97, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_d6(int argc, VALUE *argv, VALUE self)
{
    VALUE nNumDice;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) nNumDice = argv[0];
    else nNumDice = INT2NUM(1);
    StackPushInteger(NUM2INT(nNumDice));
    VM_ExecuteCommand(98, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_d8(int argc, VALUE *argv, VALUE self)
{
    VALUE nNumDice;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) nNumDice = argv[0];
    else nNumDice = INT2NUM(1);
    StackPushInteger(NUM2INT(nNumDice));
    VM_ExecuteCommand(99, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_d10(int argc, VALUE *argv, VALUE self)
{
    VALUE nNumDice;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) nNumDice = argv[0];
    else nNumDice = INT2NUM(1);
    StackPushInteger(NUM2INT(nNumDice));
    VM_ExecuteCommand(100, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_d12(int argc, VALUE *argv, VALUE self)
{
    VALUE nNumDice;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) nNumDice = argv[0];
    else nNumDice = INT2NUM(1);
    StackPushInteger(NUM2INT(nNumDice));
    VM_ExecuteCommand(101, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_d20(int argc, VALUE *argv, VALUE self)
{
    VALUE nNumDice;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) nNumDice = argv[0];
    else nNumDice = INT2NUM(1);
    StackPushInteger(NUM2INT(nNumDice));
    VM_ExecuteCommand(102, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_d100(int argc, VALUE *argv, VALUE self)
{
    VALUE nNumDice;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) nNumDice = argv[0];
    else nNumDice = INT2NUM(1);
    StackPushInteger(NUM2INT(nNumDice));
    VM_ExecuteCommand(103, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_VectorMagnitude(VALUE self, VALUE vVector)
{
    Vector *vVector_ptr;
    Data_Get_Struct(vVector, Vector, vVector_ptr);
    StackPushVector(*vVector_ptr);
    VM_ExecuteCommand(104, 1);
    float fRetVal;
    StackPopFloat(&fRetVal);
    return rb_float_new(fRetVal);
}

static VALUE NWScript_GetMetaMagicFeat(VALUE self)
{
    VM_ExecuteCommand(105, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetObjectType(VALUE self, VALUE oTarget)
{
    StackPushObject(NUM2UINT(oTarget));
    VM_ExecuteCommand(106, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetRacialType(VALUE self, VALUE oCreature)
{
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(107, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_FortitudeSave(int argc, VALUE *argv, VALUE self)
{
    VALUE oCreature, nDC, nSaveType, oSaveVersus;
    if (argc < 2) {
        //TODO: Raise exception
        return Qnil;
    }
    oCreature = argv[0];
    nDC = argv[1];
    if (argc > 2) nSaveType = argv[2];
    else nSaveType = INT2NUM(SAVING_THROW_TYPE_NONE);
    if (argc > 3) oSaveVersus = argv[3];
    else oSaveVersus = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oSaveVersus));
    StackPushInteger(NUM2INT(nSaveType));
    StackPushInteger(NUM2INT(nDC));
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(108, 4);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_ReflexSave(int argc, VALUE *argv, VALUE self)
{
    VALUE oCreature, nDC, nSaveType, oSaveVersus;
    if (argc < 2) {
        //TODO: Raise exception
        return Qnil;
    }
    oCreature = argv[0];
    nDC = argv[1];
    if (argc > 2) nSaveType = argv[2];
    else nSaveType = INT2NUM(SAVING_THROW_TYPE_NONE);
    if (argc > 3) oSaveVersus = argv[3];
    else oSaveVersus = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oSaveVersus));
    StackPushInteger(NUM2INT(nSaveType));
    StackPushInteger(NUM2INT(nDC));
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(109, 4);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_WillSave(int argc, VALUE *argv, VALUE self)
{
    VALUE oCreature, nDC, nSaveType, oSaveVersus;
    if (argc < 2) {
        //TODO: Raise exception
        return Qnil;
    }
    oCreature = argv[0];
    nDC = argv[1];
    if (argc > 2) nSaveType = argv[2];
    else nSaveType = INT2NUM(SAVING_THROW_TYPE_NONE);
    if (argc > 3) oSaveVersus = argv[3];
    else oSaveVersus = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oSaveVersus));
    StackPushInteger(NUM2INT(nSaveType));
    StackPushInteger(NUM2INT(nDC));
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(110, 4);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetSpellSaveDC(VALUE self)
{
    VM_ExecuteCommand(111, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_MagicalEffect(VALUE self, VALUE eEffect)
{
    CGameEffect *eEffect_ptr;
    Data_Get_Struct(eEffect, CGameEffect, eEffect_ptr);
    StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eEffect_ptr);
    VM_ExecuteCommand(112, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_SupernaturalEffect(VALUE self, VALUE eEffect)
{
    CGameEffect *eEffect_ptr;
    Data_Get_Struct(eEffect, CGameEffect, eEffect_ptr);
    StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eEffect_ptr);
    VM_ExecuteCommand(113, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_ExtraordinaryEffect(VALUE self, VALUE eEffect)
{
    CGameEffect *eEffect_ptr;
    Data_Get_Struct(eEffect, CGameEffect, eEffect_ptr);
    StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eEffect_ptr);
    VM_ExecuteCommand(114, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_EffectACIncrease(int argc, VALUE *argv, VALUE self)
{
    VALUE nValue, nModifyType, nDamageType;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    nValue = argv[0];
    if (argc > 1) nModifyType = argv[1];
    else nModifyType = INT2NUM(AC_DODGE_BONUS);
    if (argc > 2) nDamageType = argv[2];
    else nDamageType = INT2NUM(AC_VS_DAMAGE_TYPE_ALL);
    StackPushInteger(NUM2INT(nDamageType));
    StackPushInteger(NUM2INT(nModifyType));
    StackPushInteger(NUM2INT(nValue));
    VM_ExecuteCommand(115, 3);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_GetAC(int argc, VALUE *argv, VALUE self)
{
    VALUE oObject, nForFutureUse;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    oObject = argv[0];
    if (argc > 1) nForFutureUse = argv[1];
    else nForFutureUse = INT2NUM(0);
    StackPushInteger(NUM2INT(nForFutureUse));
    StackPushObject(NUM2UINT(oObject));
    VM_ExecuteCommand(116, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_EffectSavingThrowIncrease(int argc, VALUE *argv, VALUE self)
{
    VALUE nSave, nValue, nSaveType;
    if (argc < 2) {
        //TODO: Raise exception
        return Qnil;
    }
    nSave = argv[0];
    nValue = argv[1];
    if (argc > 2) nSaveType = argv[2];
    else nSaveType = INT2NUM(SAVING_THROW_TYPE_ALL);
    StackPushInteger(NUM2INT(nSaveType));
    StackPushInteger(NUM2INT(nValue));
    StackPushInteger(NUM2INT(nSave));
    VM_ExecuteCommand(117, 3);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_EffectAttackIncrease(int argc, VALUE *argv, VALUE self)
{
    VALUE nBonus, nModifierType;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    nBonus = argv[0];
    if (argc > 1) nModifierType = argv[1];
    else nModifierType = INT2NUM(ATTACK_BONUS_MISC);
    StackPushInteger(NUM2INT(nModifierType));
    StackPushInteger(NUM2INT(nBonus));
    VM_ExecuteCommand(118, 2);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_EffectDamageReduction(int argc, VALUE *argv, VALUE self)
{
    VALUE nAmount, nDamagePower, nLimit;
    if (argc < 2) {
        //TODO: Raise exception
        return Qnil;
    }
    nAmount = argv[0];
    nDamagePower = argv[1];
    if (argc > 2) nLimit = argv[2];
    else nLimit = INT2NUM(0);
    StackPushInteger(NUM2INT(nLimit));
    StackPushInteger(NUM2INT(nDamagePower));
    StackPushInteger(NUM2INT(nAmount));
    VM_ExecuteCommand(119, 3);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_EffectDamageIncrease(int argc, VALUE *argv, VALUE self)
{
    VALUE nBonus, nDamageType;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    nBonus = argv[0];
    if (argc > 1) nDamageType = argv[1];
    else nDamageType = INT2NUM(DAMAGE_TYPE_MAGICAL);
    StackPushInteger(NUM2INT(nDamageType));
    StackPushInteger(NUM2INT(nBonus));
    VM_ExecuteCommand(120, 2);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_RoundsToSeconds(VALUE self, VALUE nRounds)
{
    StackPushInteger(NUM2INT(nRounds));
    VM_ExecuteCommand(121, 1);
    float fRetVal;
    StackPopFloat(&fRetVal);
    return rb_float_new(fRetVal);
}

static VALUE NWScript_HoursToSeconds(VALUE self, VALUE nHours)
{
    StackPushInteger(NUM2INT(nHours));
    VM_ExecuteCommand(122, 1);
    float fRetVal;
    StackPopFloat(&fRetVal);
    return rb_float_new(fRetVal);
}

static VALUE NWScript_TurnsToSeconds(VALUE self, VALUE nTurns)
{
    StackPushInteger(NUM2INT(nTurns));
    VM_ExecuteCommand(123, 1);
    float fRetVal;
    StackPopFloat(&fRetVal);
    return rb_float_new(fRetVal);
}

static VALUE NWScript_GetLawChaosValue(VALUE self, VALUE oCreature)
{
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(124, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetGoodEvilValue(VALUE self, VALUE oCreature)
{
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(125, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetAlignmentLawChaos(VALUE self, VALUE oCreature)
{
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(126, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetAlignmentGoodEvil(VALUE self, VALUE oCreature)
{
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(127, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_EffectEntangle(VALUE self)
{
    VM_ExecuteCommand(130, 0);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_SignalEvent(VALUE self, VALUE oObject, VALUE evToRun)
{
    //ERROR: Undefined variable type: event
    StackPushObject(NUM2UINT(oObject));
    VM_ExecuteCommand(131, 2);
    return Qnil;
}

static VALUE NWScript_EventUserDefined(VALUE self, VALUE nUserDefinedEventNumber)
{
    StackPushInteger(NUM2INT(nUserDefinedEventNumber));
    VM_ExecuteCommand(132, 1);
//ERROR: Undefined variable type: event
    return Qnil;
}

static VALUE NWScript_EffectDeath(int argc, VALUE *argv, VALUE self)
{
    VALUE nSpectacularDeath, nDisplayFeedback;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) nSpectacularDeath = argv[0];
    else nSpectacularDeath = INT2NUM(FALSE);
    if (argc > 1) nDisplayFeedback = argv[1];
    else nDisplayFeedback = INT2NUM(TRUE);
    StackPushInteger(NUM2INT(nDisplayFeedback));
    StackPushInteger(NUM2INT(nSpectacularDeath));
    VM_ExecuteCommand(133, 2);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_EffectKnockdown(VALUE self)
{
    VM_ExecuteCommand(134, 0);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_ActionGiveItem(VALUE self, VALUE oItem, VALUE oGiveTo)
{
    StackPushObject(NUM2UINT(oGiveTo));
    StackPushObject(NUM2UINT(oItem));
    VM_ExecuteCommand(135, 2);
    return Qnil;
}

static VALUE NWScript_ActionTakeItem(VALUE self, VALUE oItem, VALUE oTakeFrom)
{
    StackPushObject(NUM2UINT(oTakeFrom));
    StackPushObject(NUM2UINT(oItem));
    VM_ExecuteCommand(136, 2);
    return Qnil;
}

static VALUE NWScript_VectorNormalize(VALUE self, VALUE vVector)
{
    Vector *vVector_ptr;
    Data_Get_Struct(vVector, Vector, vVector_ptr);
    StackPushVector(*vVector_ptr);
    VM_ExecuteCommand(137, 1);
    Vector *vRetVal = (Vector *) malloc(sizeof(Vector));
    StackPopVector(vRetVal);
    return Data_Wrap_Struct(g_cVectorClass, 0, free, vRetVal);
}

static VALUE NWScript_EffectCurse(int argc, VALUE *argv, VALUE self)
{
    VALUE nStrMod, nDexMod, nConMod, nIntMod, nWisMod, nChaMod;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) nStrMod = argv[0];
    else nStrMod = INT2NUM(1);
    if (argc > 1) nDexMod = argv[1];
    else nDexMod = INT2NUM(1);
    if (argc > 2) nConMod = argv[2];
    else nConMod = INT2NUM(1);
    if (argc > 3) nIntMod = argv[3];
    else nIntMod = INT2NUM(1);
    if (argc > 4) nWisMod = argv[4];
    else nWisMod = INT2NUM(1);
    if (argc > 5) nChaMod = argv[5];
    else nChaMod = INT2NUM(1);
    StackPushInteger(NUM2INT(nChaMod));
    StackPushInteger(NUM2INT(nWisMod));
    StackPushInteger(NUM2INT(nIntMod));
    StackPushInteger(NUM2INT(nConMod));
    StackPushInteger(NUM2INT(nDexMod));
    StackPushInteger(NUM2INT(nStrMod));
    VM_ExecuteCommand(138, 6);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_GetAbilityScore(int argc, VALUE *argv, VALUE self)
{
    VALUE oCreature, nAbilityType, nBaseAbilityScore;
    if (argc < 2) {
        //TODO: Raise exception
        return Qnil;
    }
    oCreature = argv[0];
    nAbilityType = argv[1];
    if (argc > 2) nBaseAbilityScore = argv[2];
    else nBaseAbilityScore = INT2NUM(FALSE);
    StackPushInteger(NUM2INT(nBaseAbilityScore));
    StackPushInteger(NUM2INT(nAbilityType));
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(139, 3);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetIsDead(VALUE self, VALUE oCreature)
{
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(140, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_PrintVector(VALUE self, VALUE vVector, VALUE bPrepend)
{
    StackPushInteger(NUM2INT(bPrepend));
    Vector *vVector_ptr;
    Data_Get_Struct(vVector, Vector, vVector_ptr);
    StackPushVector(*vVector_ptr);
    VM_ExecuteCommand(141, 2);
    return Qnil;
}

static VALUE NWScript_Vector(int argc, VALUE *argv, VALUE self)
{
    VALUE x, y, z;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) x = argv[0];
    else x = rb_float_new(0.0f);
    if (argc > 1) y = argv[1];
    else y = rb_float_new(0.0f);
    if (argc > 2) z = argv[2];
    else z = rb_float_new(0.0f);
    StackPushFloat(NUM2DBL(z));
    StackPushFloat(NUM2DBL(y));
    StackPushFloat(NUM2DBL(x));
    VM_ExecuteCommand(142, 3);
    Vector *vRetVal = (Vector *) malloc(sizeof(Vector));
    StackPopVector(vRetVal);
    return Data_Wrap_Struct(g_cVectorClass, 0, free, vRetVal);
}

static VALUE NWScript_SetFacingPoint(VALUE self, VALUE vTarget)
{
    Vector *vTarget_ptr;
    Data_Get_Struct(vTarget, Vector, vTarget_ptr);
    StackPushVector(*vTarget_ptr);
    VM_ExecuteCommand(143, 1);
    return Qnil;
}

static VALUE NWScript_AngleToVector(VALUE self, VALUE fAngle)
{
    StackPushFloat(NUM2DBL(fAngle));
    VM_ExecuteCommand(144, 1);
    Vector *vRetVal = (Vector *) malloc(sizeof(Vector));
    StackPopVector(vRetVal);
    return Data_Wrap_Struct(g_cVectorClass, 0, free, vRetVal);
}

static VALUE NWScript_VectorToAngle(VALUE self, VALUE vVector)
{
    Vector *vVector_ptr;
    Data_Get_Struct(vVector, Vector, vVector_ptr);
    StackPushVector(*vVector_ptr);
    VM_ExecuteCommand(145, 1);
    float fRetVal;
    StackPopFloat(&fRetVal);
    return rb_float_new(fRetVal);
}

static VALUE NWScript_TouchAttackMelee(int argc, VALUE *argv, VALUE self)
{
    VALUE oTarget, bDisplayFeedback;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    oTarget = argv[0];
    if (argc > 1) bDisplayFeedback = argv[1];
    else bDisplayFeedback = INT2NUM(TRUE);
    StackPushInteger(NUM2INT(bDisplayFeedback));
    StackPushObject(NUM2UINT(oTarget));
    VM_ExecuteCommand(146, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_TouchAttackRanged(int argc, VALUE *argv, VALUE self)
{
    VALUE oTarget, bDisplayFeedback;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    oTarget = argv[0];
    if (argc > 1) bDisplayFeedback = argv[1];
    else bDisplayFeedback = INT2NUM(TRUE);
    StackPushInteger(NUM2INT(bDisplayFeedback));
    StackPushObject(NUM2UINT(oTarget));
    VM_ExecuteCommand(147, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_EffectParalyze(VALUE self)
{
    VM_ExecuteCommand(148, 0);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_EffectSpellImmunity(int argc, VALUE *argv, VALUE self)
{
    VALUE nImmunityToSpell;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) nImmunityToSpell = argv[0];
    else nImmunityToSpell = INT2NUM(SPELL_ALL_SPELLS);
    StackPushInteger(NUM2INT(nImmunityToSpell));
    VM_ExecuteCommand(149, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_EffectDeaf(VALUE self)
{
    VM_ExecuteCommand(150, 0);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_GetDistanceBetween(VALUE self, VALUE oObjectA, VALUE oObjectB)
{
    StackPushObject(NUM2UINT(oObjectB));
    StackPushObject(NUM2UINT(oObjectA));
    VM_ExecuteCommand(151, 2);
    float fRetVal;
    StackPopFloat(&fRetVal);
    return rb_float_new(fRetVal);
}

static VALUE NWScript_SetLocalLocation(VALUE self, VALUE oObject, VALUE sVarName, VALUE lValue)
{
    CScriptLocation *lValue_ptr;
    Data_Get_Struct(lValue, CScriptLocation, lValue_ptr);
    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lValue_ptr);
    StackPushString(StringValueCStr(sVarName));
    StackPushObject(NUM2UINT(oObject));
    VM_ExecuteCommand(152, 3);
    return Qnil;
}

static VALUE NWScript_GetLocalLocation(VALUE self, VALUE oObject, VALUE sVarName)
{
    StackPushString(StringValueCStr(sVarName));
    StackPushObject(NUM2UINT(oObject));
    VM_ExecuteCommand(153, 2);
    CScriptLocation *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_LOCATION, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cLocationClass, 0, free, pRetVal);
}

static VALUE NWScript_EffectSleep(VALUE self)
{
    VM_ExecuteCommand(154, 0);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_GetItemInSlot(int argc, VALUE *argv, VALUE self)
{
    VALUE nInventorySlot, oCreature;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    nInventorySlot = argv[0];
    if (argc > 1) oCreature = argv[1];
    else oCreature = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oCreature));
    StackPushInteger(NUM2INT(nInventorySlot));
    VM_ExecuteCommand(155, 2);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_EffectCharmed(VALUE self)
{
    VM_ExecuteCommand(156, 0);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_EffectConfused(VALUE self)
{
    VM_ExecuteCommand(157, 0);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_EffectFrightened(VALUE self)
{
    VM_ExecuteCommand(158, 0);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_EffectDominated(VALUE self)
{
    VM_ExecuteCommand(159, 0);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_EffectDazed(VALUE self)
{
    VM_ExecuteCommand(160, 0);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_EffectStunned(VALUE self)
{
    VM_ExecuteCommand(161, 0);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_SetCommandable(int argc, VALUE *argv, VALUE self)
{
    VALUE bCommandable, oTarget;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    bCommandable = argv[0];
    if (argc > 1) oTarget = argv[1];
    else oTarget = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oTarget));
    StackPushInteger(NUM2INT(bCommandable));
    VM_ExecuteCommand(162, 2);
    return Qnil;
}

static VALUE NWScript_GetCommandable(int argc, VALUE *argv, VALUE self)
{
    VALUE oTarget;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oTarget = argv[0];
    else oTarget = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oTarget));
    VM_ExecuteCommand(163, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_EffectRegenerate(VALUE self, VALUE nAmount, VALUE fIntervalSeconds)
{
    StackPushFloat(NUM2DBL(fIntervalSeconds));
    StackPushInteger(NUM2INT(nAmount));
    VM_ExecuteCommand(164, 2);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_EffectMovementSpeedIncrease(VALUE self, VALUE nPercentChange)
{
    StackPushInteger(NUM2INT(nPercentChange));
    VM_ExecuteCommand(165, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_GetHitDice(VALUE self, VALUE oCreature)
{
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(166, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_ActionForceFollowObject(int argc, VALUE *argv, VALUE self)
{
    VALUE oFollow, fFollowDistance;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    oFollow = argv[0];
    if (argc > 1) fFollowDistance = argv[1];
    else fFollowDistance = rb_float_new(0.0f);
    StackPushFloat(NUM2DBL(fFollowDistance));
    StackPushObject(NUM2UINT(oFollow));
    VM_ExecuteCommand(167, 2);
    return Qnil;
}

static VALUE NWScript_GetTag(VALUE self, VALUE oObject)
{
    StackPushObject(NUM2UINT(oObject));
    VM_ExecuteCommand(168, 1);
    char *sRetVal;
    StackPopString(&sRetVal);
    return rb_str_new2(sRetVal);
}

static VALUE NWScript_ResistSpell(VALUE self, VALUE oCaster, VALUE oTarget)
{
    StackPushObject(NUM2UINT(oTarget));
    StackPushObject(NUM2UINT(oCaster));
    VM_ExecuteCommand(169, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetEffectType(VALUE self, VALUE eEffect)
{
    CGameEffect *eEffect_ptr;
    Data_Get_Struct(eEffect, CGameEffect, eEffect_ptr);
    StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eEffect_ptr);
    VM_ExecuteCommand(170, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_EffectAreaOfEffect(int argc, VALUE *argv, VALUE self)
{
    VALUE nAreaEffectId, sOnEnterScript, sHeartbeatScript, sOnExitScript;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    nAreaEffectId = argv[0];
    if (argc > 1) sOnEnterScript = argv[1];
    else sOnEnterScript = rb_str_new2("");
    if (argc > 2) sHeartbeatScript = argv[2];
    else sHeartbeatScript = rb_str_new2("");
    if (argc > 3) sOnExitScript = argv[3];
    else sOnExitScript = rb_str_new2("");
    StackPushString(StringValueCStr(sOnExitScript));
    StackPushString(StringValueCStr(sHeartbeatScript));
    StackPushString(StringValueCStr(sOnEnterScript));
    StackPushInteger(NUM2INT(nAreaEffectId));
    VM_ExecuteCommand(171, 4);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_GetFactionEqual(int argc, VALUE *argv, VALUE self)
{
    VALUE oFirstObject, oSecondObject;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    oFirstObject = argv[0];
    if (argc > 1) oSecondObject = argv[1];
    else oSecondObject = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oSecondObject));
    StackPushObject(NUM2UINT(oFirstObject));
    VM_ExecuteCommand(172, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_ChangeFaction(VALUE self, VALUE oObjectToChangeFaction, VALUE oMemberOfFactionToJoin)
{
    StackPushObject(NUM2UINT(oMemberOfFactionToJoin));
    StackPushObject(NUM2UINT(oObjectToChangeFaction));
    VM_ExecuteCommand(173, 2);
    return Qnil;
}

static VALUE NWScript_GetIsListening(VALUE self, VALUE oObject)
{
    StackPushObject(NUM2UINT(oObject));
    VM_ExecuteCommand(174, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_SetListening(VALUE self, VALUE oObject, VALUE bValue)
{
    StackPushInteger(NUM2INT(bValue));
    StackPushObject(NUM2UINT(oObject));
    VM_ExecuteCommand(175, 2);
    return Qnil;
}

static VALUE NWScript_SetListenPattern(int argc, VALUE *argv, VALUE self)
{
    VALUE oObject, sPattern, nNumber;
    if (argc < 2) {
        //TODO: Raise exception
        return Qnil;
    }
    oObject = argv[0];
    sPattern = argv[1];
    if (argc > 2) nNumber = argv[2];
    else nNumber = INT2NUM(0);
    StackPushInteger(NUM2INT(nNumber));
    StackPushString(StringValueCStr(sPattern));
    StackPushObject(NUM2UINT(oObject));
    VM_ExecuteCommand(176, 3);
    return Qnil;
}

static VALUE NWScript_TestStringAgainstPattern(VALUE self, VALUE sPattern, VALUE sStringToTest)
{
    StackPushString(StringValueCStr(sStringToTest));
    StackPushString(StringValueCStr(sPattern));
    VM_ExecuteCommand(177, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetMatchedSubstring(VALUE self, VALUE nString)
{
    StackPushInteger(NUM2INT(nString));
    VM_ExecuteCommand(178, 1);
    char *sRetVal;
    StackPopString(&sRetVal);
    return rb_str_new2(sRetVal);
}

static VALUE NWScript_GetMatchedSubstringsCount(VALUE self)
{
    VM_ExecuteCommand(179, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_EffectVisualEffect(int argc, VALUE *argv, VALUE self)
{
    VALUE nVisualEffectId, nMissEffect;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    nVisualEffectId = argv[0];
    if (argc > 1) nMissEffect = argv[1];
    else nMissEffect = INT2NUM(FALSE);
    StackPushInteger(NUM2INT(nMissEffect));
    StackPushInteger(NUM2INT(nVisualEffectId));
    VM_ExecuteCommand(180, 2);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_GetFactionWeakestMember(int argc, VALUE *argv, VALUE self)
{
    VALUE oFactionMember, bMustBeVisible;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oFactionMember = argv[0];
    else oFactionMember = INT2NUM(OBJECT_SELF);
    if (argc > 1) bMustBeVisible = argv[1];
    else bMustBeVisible = INT2NUM(TRUE);
    StackPushInteger(NUM2INT(bMustBeVisible));
    StackPushObject(NUM2UINT(oFactionMember));
    VM_ExecuteCommand(181, 2);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetFactionStrongestMember(int argc, VALUE *argv, VALUE self)
{
    VALUE oFactionMember, bMustBeVisible;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oFactionMember = argv[0];
    else oFactionMember = INT2NUM(OBJECT_SELF);
    if (argc > 1) bMustBeVisible = argv[1];
    else bMustBeVisible = INT2NUM(TRUE);
    StackPushInteger(NUM2INT(bMustBeVisible));
    StackPushObject(NUM2UINT(oFactionMember));
    VM_ExecuteCommand(182, 2);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetFactionMostDamagedMember(int argc, VALUE *argv, VALUE self)
{
    VALUE oFactionMember, bMustBeVisible;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oFactionMember = argv[0];
    else oFactionMember = INT2NUM(OBJECT_SELF);
    if (argc > 1) bMustBeVisible = argv[1];
    else bMustBeVisible = INT2NUM(TRUE);
    StackPushInteger(NUM2INT(bMustBeVisible));
    StackPushObject(NUM2UINT(oFactionMember));
    VM_ExecuteCommand(183, 2);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetFactionLeastDamagedMember(int argc, VALUE *argv, VALUE self)
{
    VALUE oFactionMember, bMustBeVisible;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oFactionMember = argv[0];
    else oFactionMember = INT2NUM(OBJECT_SELF);
    if (argc > 1) bMustBeVisible = argv[1];
    else bMustBeVisible = INT2NUM(TRUE);
    StackPushInteger(NUM2INT(bMustBeVisible));
    StackPushObject(NUM2UINT(oFactionMember));
    VM_ExecuteCommand(184, 2);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetFactionGold(VALUE self, VALUE oFactionMember)
{
    StackPushObject(NUM2UINT(oFactionMember));
    VM_ExecuteCommand(185, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetFactionAverageReputation(VALUE self, VALUE oSourceFactionMember, VALUE oTarget)
{
    StackPushObject(NUM2UINT(oTarget));
    StackPushObject(NUM2UINT(oSourceFactionMember));
    VM_ExecuteCommand(186, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetFactionAverageGoodEvilAlignment(VALUE self, VALUE oFactionMember)
{
    StackPushObject(NUM2UINT(oFactionMember));
    VM_ExecuteCommand(187, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetFactionAverageLawChaosAlignment(VALUE self, VALUE oFactionMember)
{
    StackPushObject(NUM2UINT(oFactionMember));
    VM_ExecuteCommand(188, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetFactionAverageLevel(VALUE self, VALUE oFactionMember)
{
    StackPushObject(NUM2UINT(oFactionMember));
    VM_ExecuteCommand(189, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetFactionAverageXP(VALUE self, VALUE oFactionMember)
{
    StackPushObject(NUM2UINT(oFactionMember));
    VM_ExecuteCommand(190, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetFactionMostFrequentClass(VALUE self, VALUE oFactionMember)
{
    StackPushObject(NUM2UINT(oFactionMember));
    VM_ExecuteCommand(191, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetFactionWorstAC(int argc, VALUE *argv, VALUE self)
{
    VALUE oFactionMember, bMustBeVisible;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oFactionMember = argv[0];
    else oFactionMember = INT2NUM(OBJECT_SELF);
    if (argc > 1) bMustBeVisible = argv[1];
    else bMustBeVisible = INT2NUM(TRUE);
    StackPushInteger(NUM2INT(bMustBeVisible));
    StackPushObject(NUM2UINT(oFactionMember));
    VM_ExecuteCommand(192, 2);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetFactionBestAC(int argc, VALUE *argv, VALUE self)
{
    VALUE oFactionMember, bMustBeVisible;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oFactionMember = argv[0];
    else oFactionMember = INT2NUM(OBJECT_SELF);
    if (argc > 1) bMustBeVisible = argv[1];
    else bMustBeVisible = INT2NUM(TRUE);
    StackPushInteger(NUM2INT(bMustBeVisible));
    StackPushObject(NUM2UINT(oFactionMember));
    VM_ExecuteCommand(193, 2);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_ActionSit(VALUE self, VALUE oChair)
{
    StackPushObject(NUM2UINT(oChair));
    VM_ExecuteCommand(194, 1);
    return Qnil;
}

static VALUE NWScript_GetListenPatternNumber(VALUE self)
{
    VM_ExecuteCommand(195, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_ActionJumpToObject(int argc, VALUE *argv, VALUE self)
{
    VALUE oToJumpTo, bWalkStraightLineToPoint;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    oToJumpTo = argv[0];
    if (argc > 1) bWalkStraightLineToPoint = argv[1];
    else bWalkStraightLineToPoint = INT2NUM(TRUE);
    StackPushInteger(NUM2INT(bWalkStraightLineToPoint));
    StackPushObject(NUM2UINT(oToJumpTo));
    VM_ExecuteCommand(196, 2);
    return Qnil;
}

static VALUE NWScript_GetWaypointByTag(VALUE self, VALUE sWaypointTag)
{
    StackPushString(StringValueCStr(sWaypointTag));
    VM_ExecuteCommand(197, 1);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetTransitionTarget(VALUE self, VALUE oTransition)
{
    StackPushObject(NUM2UINT(oTransition));
    VM_ExecuteCommand(198, 1);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_EffectLinkEffects(VALUE self, VALUE eChildEffect, VALUE eParentEffect)
{
    CGameEffect *eParentEffect_ptr;
    Data_Get_Struct(eParentEffect, CGameEffect, eParentEffect_ptr);
    StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eParentEffect_ptr);
    CGameEffect *eChildEffect_ptr;
    Data_Get_Struct(eChildEffect, CGameEffect, eChildEffect_ptr);
    StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eChildEffect_ptr);
    VM_ExecuteCommand(199, 2);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_GetObjectByTag(int argc, VALUE *argv, VALUE self)
{
    VALUE sTag, nNth;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    sTag = argv[0];
    if (argc > 1) nNth = argv[1];
    else nNth = INT2NUM(0);
    StackPushInteger(NUM2INT(nNth));
    StackPushString(StringValueCStr(sTag));
    VM_ExecuteCommand(200, 2);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_AdjustAlignment(int argc, VALUE *argv, VALUE self)
{
    VALUE oSubject, nAlignment, nShift, bAllPartyMembers;
    if (argc < 3) {
        //TODO: Raise exception
        return Qnil;
    }
    oSubject = argv[0];
    nAlignment = argv[1];
    nShift = argv[2];
    if (argc > 3) bAllPartyMembers = argv[3];
    else bAllPartyMembers = INT2NUM(TRUE);
    StackPushInteger(NUM2INT(bAllPartyMembers));
    StackPushInteger(NUM2INT(nShift));
    StackPushInteger(NUM2INT(nAlignment));
    StackPushObject(NUM2UINT(oSubject));
    VM_ExecuteCommand(201, 4);
    return Qnil;
}

static VALUE NWScript_ActionWait(VALUE self, VALUE fSeconds)
{
    StackPushFloat(NUM2DBL(fSeconds));
    VM_ExecuteCommand(202, 1);
    return Qnil;
}

static VALUE NWScript_SetAreaTransitionBMP(int argc, VALUE *argv, VALUE self)
{
    VALUE nPredefinedAreaTransition, sCustomAreaTransitionBMP;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    nPredefinedAreaTransition = argv[0];
    if (argc > 1) sCustomAreaTransitionBMP = argv[1];
    else sCustomAreaTransitionBMP = rb_str_new2("");
    StackPushString(StringValueCStr(sCustomAreaTransitionBMP));
    StackPushInteger(NUM2INT(nPredefinedAreaTransition));
    VM_ExecuteCommand(203, 2);
    return Qnil;
}

static VALUE NWScript_ActionStartConversation(int argc, VALUE *argv, VALUE self)
{
    VALUE oObjectToConverseWith, sDialogResRef, bPrivateConversation, bPlayHello;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    oObjectToConverseWith = argv[0];
    if (argc > 1) sDialogResRef = argv[1];
    else sDialogResRef = rb_str_new2("");
    if (argc > 2) bPrivateConversation = argv[2];
    else bPrivateConversation = INT2NUM(FALSE);
    if (argc > 3) bPlayHello = argv[3];
    else bPlayHello = INT2NUM(TRUE);
    StackPushInteger(NUM2INT(bPlayHello));
    StackPushInteger(NUM2INT(bPrivateConversation));
    StackPushString(StringValueCStr(sDialogResRef));
    StackPushObject(NUM2UINT(oObjectToConverseWith));
    VM_ExecuteCommand(204, 4);
    return Qnil;
}

static VALUE NWScript_ActionPauseConversation(VALUE self)
{
    VM_ExecuteCommand(205, 0);
    return Qnil;
}

static VALUE NWScript_ActionResumeConversation(VALUE self)
{
    VM_ExecuteCommand(206, 0);
    return Qnil;
}

static VALUE NWScript_EffectBeam(int argc, VALUE *argv, VALUE self)
{
    VALUE nBeamVisualEffect, oEffector, nBodyPart, bMissEffect;
    if (argc < 3) {
        //TODO: Raise exception
        return Qnil;
    }
    nBeamVisualEffect = argv[0];
    oEffector = argv[1];
    nBodyPart = argv[2];
    if (argc > 3) bMissEffect = argv[3];
    else bMissEffect = INT2NUM(FALSE);
    StackPushInteger(NUM2INT(bMissEffect));
    StackPushInteger(NUM2INT(nBodyPart));
    StackPushObject(NUM2UINT(oEffector));
    StackPushInteger(NUM2INT(nBeamVisualEffect));
    VM_ExecuteCommand(207, 4);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_GetReputation(VALUE self, VALUE oSource, VALUE oTarget)
{
    StackPushObject(NUM2UINT(oTarget));
    StackPushObject(NUM2UINT(oSource));
    VM_ExecuteCommand(208, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_AdjustReputation(VALUE self, VALUE oTarget, VALUE oSourceFactionMember, VALUE nAdjustment)
{
    StackPushInteger(NUM2INT(nAdjustment));
    StackPushObject(NUM2UINT(oSourceFactionMember));
    StackPushObject(NUM2UINT(oTarget));
    VM_ExecuteCommand(209, 3);
    return Qnil;
}

static VALUE NWScript_GetSittingCreature(VALUE self, VALUE oChair)
{
    StackPushObject(NUM2UINT(oChair));
    VM_ExecuteCommand(210, 1);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetGoingToBeAttackedBy(VALUE self, VALUE oTarget)
{
    StackPushObject(NUM2UINT(oTarget));
    VM_ExecuteCommand(211, 1);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_EffectSpellResistanceIncrease(VALUE self, VALUE nValue)
{
    StackPushInteger(NUM2INT(nValue));
    VM_ExecuteCommand(212, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_GetLocation(VALUE self, VALUE oObject)
{
    StackPushObject(NUM2UINT(oObject));
    VM_ExecuteCommand(213, 1);
    CScriptLocation *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_LOCATION, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cLocationClass, 0, free, pRetVal);
}

static VALUE NWScript_ActionJumpToLocation(VALUE self, VALUE lLocation)
{
    CScriptLocation *lLocation_ptr;
    Data_Get_Struct(lLocation, CScriptLocation, lLocation_ptr);
    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lLocation_ptr);
    VM_ExecuteCommand(214, 1);
    return Qnil;
}

static VALUE NWScript_Location(VALUE self, VALUE oArea, VALUE vPosition, VALUE fOrientation)
{
    StackPushFloat(NUM2DBL(fOrientation));
    Vector *vPosition_ptr;
    Data_Get_Struct(vPosition, Vector, vPosition_ptr);
    StackPushVector(*vPosition_ptr);
    StackPushObject(NUM2UINT(oArea));
    VM_ExecuteCommand(215, 3);
    CScriptLocation *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_LOCATION, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cLocationClass, 0, free, pRetVal);
}

static VALUE NWScript_ApplyEffectAtLocation(int argc, VALUE *argv, VALUE self)
{
    VALUE nDurationType, eEffect, lLocation, fDuration;
    if (argc < 3) {
        //TODO: Raise exception
        return Qnil;
    }
    nDurationType = argv[0];
    eEffect = argv[1];
    lLocation = argv[2];
    if (argc > 3) fDuration = argv[3];
    else fDuration = rb_float_new(0.0f);
    StackPushFloat(NUM2DBL(fDuration));
    CScriptLocation *lLocation_ptr;
    Data_Get_Struct(lLocation, CScriptLocation, lLocation_ptr);
    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lLocation_ptr);
    CGameEffect *eEffect_ptr;
    Data_Get_Struct(eEffect, CGameEffect, eEffect_ptr);
    StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eEffect_ptr);
    StackPushInteger(NUM2INT(nDurationType));
    VM_ExecuteCommand(216, 4);
    return Qnil;
}

static VALUE NWScript_GetIsPC(VALUE self, VALUE oCreature)
{
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(217, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_FeetToMeters(VALUE self, VALUE fFeet)
{
    StackPushFloat(NUM2DBL(fFeet));
    VM_ExecuteCommand(218, 1);
    float fRetVal;
    StackPopFloat(&fRetVal);
    return rb_float_new(fRetVal);
}

static VALUE NWScript_YardsToMeters(VALUE self, VALUE fYards)
{
    StackPushFloat(NUM2DBL(fYards));
    VM_ExecuteCommand(219, 1);
    float fRetVal;
    StackPopFloat(&fRetVal);
    return rb_float_new(fRetVal);
}

static VALUE NWScript_ApplyEffectToObject(int argc, VALUE *argv, VALUE self)
{
    VALUE nDurationType, eEffect, oTarget, fDuration;
    if (argc < 3) {
        //TODO: Raise exception
        return Qnil;
    }
    nDurationType = argv[0];
    eEffect = argv[1];
    oTarget = argv[2];
    if (argc > 3) fDuration = argv[3];
    else fDuration = rb_float_new(0.0f);
    StackPushFloat(NUM2DBL(fDuration));
    StackPushObject(NUM2UINT(oTarget));
    CGameEffect *eEffect_ptr;
    Data_Get_Struct(eEffect, CGameEffect, eEffect_ptr);
    StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eEffect_ptr);
    StackPushInteger(NUM2INT(nDurationType));
    VM_ExecuteCommand(220, 4);
    return Qnil;
}

static VALUE NWScript_SpeakString(int argc, VALUE *argv, VALUE self)
{
    VALUE sStringToSpeak, nTalkVolume;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    sStringToSpeak = argv[0];
    if (argc > 1) nTalkVolume = argv[1];
    else nTalkVolume = INT2NUM(TALKVOLUME_TALK);
    StackPushInteger(NUM2INT(nTalkVolume));
    StackPushString(StringValueCStr(sStringToSpeak));
    VM_ExecuteCommand(221, 2);
    return Qnil;
}

static VALUE NWScript_GetSpellTargetLocation(VALUE self)
{
    VM_ExecuteCommand(222, 0);
    CScriptLocation *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_LOCATION, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cLocationClass, 0, free, pRetVal);
}

static VALUE NWScript_GetPositionFromLocation(VALUE self, VALUE lLocation)
{
    CScriptLocation *lLocation_ptr;
    Data_Get_Struct(lLocation, CScriptLocation, lLocation_ptr);
    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lLocation_ptr);
    VM_ExecuteCommand(223, 1);
    Vector *vRetVal = (Vector *) malloc(sizeof(Vector));
    StackPopVector(vRetVal);
    return Data_Wrap_Struct(g_cVectorClass, 0, free, vRetVal);
}

static VALUE NWScript_GetAreaFromLocation(VALUE self, VALUE lLocation)
{
    CScriptLocation *lLocation_ptr;
    Data_Get_Struct(lLocation, CScriptLocation, lLocation_ptr);
    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lLocation_ptr);
    VM_ExecuteCommand(224, 1);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetFacingFromLocation(VALUE self, VALUE lLocation)
{
    CScriptLocation *lLocation_ptr;
    Data_Get_Struct(lLocation, CScriptLocation, lLocation_ptr);
    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lLocation_ptr);
    VM_ExecuteCommand(225, 1);
    float fRetVal;
    StackPopFloat(&fRetVal);
    return rb_float_new(fRetVal);
}

static VALUE NWScript_GetNearestCreatureToLocation(int argc, VALUE *argv, VALUE self)
{
    VALUE nFirstCriteriaType, nFirstCriteriaValue, lLocation, nNth, nSecondCriteriaType, nSecondCriteriaValue, nThirdCriteriaType, nThirdCriteriaValue;
    if (argc < 3) {
        //TODO: Raise exception
        return Qnil;
    }
    nFirstCriteriaType = argv[0];
    nFirstCriteriaValue = argv[1];
    lLocation = argv[2];
    if (argc > 3) nNth = argv[3];
    else nNth = INT2NUM(1);
    if (argc > 4) nSecondCriteriaType = argv[4];
    else nSecondCriteriaType = INT2NUM(-1);
    if (argc > 5) nSecondCriteriaValue = argv[5];
    else nSecondCriteriaValue = INT2NUM(-1);
    if (argc > 6) nThirdCriteriaType = argv[6];
    else nThirdCriteriaType = INT2NUM(-1);
    if (argc > 7) nThirdCriteriaValue = argv[7];
    else nThirdCriteriaValue = INT2NUM(-1);
    StackPushInteger(NUM2INT(nThirdCriteriaValue));
    StackPushInteger(NUM2INT(nThirdCriteriaType));
    StackPushInteger(NUM2INT(nSecondCriteriaValue));
    StackPushInteger(NUM2INT(nSecondCriteriaType));
    StackPushInteger(NUM2INT(nNth));
    CScriptLocation *lLocation_ptr;
    Data_Get_Struct(lLocation, CScriptLocation, lLocation_ptr);
    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lLocation_ptr);
    StackPushInteger(NUM2INT(nFirstCriteriaValue));
    StackPushInteger(NUM2INT(nFirstCriteriaType));
    VM_ExecuteCommand(226, 8);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetNearestObject(int argc, VALUE *argv, VALUE self)
{
    VALUE nObjectType, oTarget, nNth;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) nObjectType = argv[0];
    else nObjectType = INT2NUM(OBJECT_TYPE_ALL);
    if (argc > 1) oTarget = argv[1];
    else oTarget = INT2NUM(OBJECT_SELF);
    if (argc > 2) nNth = argv[2];
    else nNth = INT2NUM(1);
    StackPushInteger(NUM2INT(nNth));
    StackPushObject(NUM2UINT(oTarget));
    StackPushInteger(NUM2INT(nObjectType));
    VM_ExecuteCommand(227, 3);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetNearestObjectToLocation(int argc, VALUE *argv, VALUE self)
{
    VALUE nObjectType, lLocation, nNth;
    if (argc < 2) {
        //TODO: Raise exception
        return Qnil;
    }
    nObjectType = argv[0];
    lLocation = argv[1];
    if (argc > 2) nNth = argv[2];
    else nNth = INT2NUM(1);
    StackPushInteger(NUM2INT(nNth));
    CScriptLocation *lLocation_ptr;
    Data_Get_Struct(lLocation, CScriptLocation, lLocation_ptr);
    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lLocation_ptr);
    StackPushInteger(NUM2INT(nObjectType));
    VM_ExecuteCommand(228, 3);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetNearestObjectByTag(int argc, VALUE *argv, VALUE self)
{
    VALUE sTag, oTarget, nNth;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    sTag = argv[0];
    if (argc > 1) oTarget = argv[1];
    else oTarget = INT2NUM(OBJECT_SELF);
    if (argc > 2) nNth = argv[2];
    else nNth = INT2NUM(1);
    StackPushInteger(NUM2INT(nNth));
    StackPushObject(NUM2UINT(oTarget));
    StackPushString(StringValueCStr(sTag));
    VM_ExecuteCommand(229, 3);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_IntToFloat(VALUE self, VALUE nInteger)
{
    StackPushInteger(NUM2INT(nInteger));
    VM_ExecuteCommand(230, 1);
    float fRetVal;
    StackPopFloat(&fRetVal);
    return rb_float_new(fRetVal);
}

static VALUE NWScript_FloatToInt(VALUE self, VALUE fFloat)
{
    StackPushFloat(NUM2DBL(fFloat));
    VM_ExecuteCommand(231, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_StringToInt(VALUE self, VALUE sNumber)
{
    StackPushString(StringValueCStr(sNumber));
    VM_ExecuteCommand(232, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_StringToFloat(VALUE self, VALUE sNumber)
{
    StackPushString(StringValueCStr(sNumber));
    VM_ExecuteCommand(233, 1);
    float fRetVal;
    StackPopFloat(&fRetVal);
    return rb_float_new(fRetVal);
}

static VALUE NWScript_ActionCastSpellAtLocation(int argc, VALUE *argv, VALUE self)
{
    VALUE nSpell, lTargetLocation, nMetaMagic, bCheat, nProjectilePathType, bInstantSpell;
    if (argc < 2) {
        //TODO: Raise exception
        return Qnil;
    }
    nSpell = argv[0];
    lTargetLocation = argv[1];
    if (argc > 2) nMetaMagic = argv[2];
    else nMetaMagic = INT2NUM(METAMAGIC_ANY);
    if (argc > 3) bCheat = argv[3];
    else bCheat = INT2NUM(FALSE);
    if (argc > 4) nProjectilePathType = argv[4];
    else nProjectilePathType = INT2NUM(PROJECTILE_PATH_TYPE_DEFAULT);
    if (argc > 5) bInstantSpell = argv[5];
    else bInstantSpell = INT2NUM(FALSE);
    StackPushInteger(NUM2INT(bInstantSpell));
    StackPushInteger(NUM2INT(nProjectilePathType));
    StackPushInteger(NUM2INT(bCheat));
    StackPushInteger(NUM2INT(nMetaMagic));
    CScriptLocation *lTargetLocation_ptr;
    Data_Get_Struct(lTargetLocation, CScriptLocation, lTargetLocation_ptr);
    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lTargetLocation_ptr);
    StackPushInteger(NUM2INT(nSpell));
    VM_ExecuteCommand(234, 6);
    return Qnil;
}

static VALUE NWScript_GetIsEnemy(int argc, VALUE *argv, VALUE self)
{
    VALUE oTarget, oSource;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    oTarget = argv[0];
    if (argc > 1) oSource = argv[1];
    else oSource = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oSource));
    StackPushObject(NUM2UINT(oTarget));
    VM_ExecuteCommand(235, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetIsFriend(int argc, VALUE *argv, VALUE self)
{
    VALUE oTarget, oSource;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    oTarget = argv[0];
    if (argc > 1) oSource = argv[1];
    else oSource = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oSource));
    StackPushObject(NUM2UINT(oTarget));
    VM_ExecuteCommand(236, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetIsNeutral(int argc, VALUE *argv, VALUE self)
{
    VALUE oTarget, oSource;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    oTarget = argv[0];
    if (argc > 1) oSource = argv[1];
    else oSource = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oSource));
    StackPushObject(NUM2UINT(oTarget));
    VM_ExecuteCommand(237, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetPCSpeaker(VALUE self)
{
    VM_ExecuteCommand(238, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetStringByStrRef(int argc, VALUE *argv, VALUE self)
{
    VALUE nStrRef, nGender;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    nStrRef = argv[0];
    if (argc > 1) nGender = argv[1];
    else nGender = INT2NUM(GENDER_MALE);
    StackPushInteger(NUM2INT(nGender));
    StackPushInteger(NUM2INT(nStrRef));
    VM_ExecuteCommand(239, 2);
    char *sRetVal;
    StackPopString(&sRetVal);
    return rb_str_new2(sRetVal);
}

static VALUE NWScript_ActionSpeakStringByStrRef(int argc, VALUE *argv, VALUE self)
{
    VALUE nStrRef, nTalkVolume;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    nStrRef = argv[0];
    if (argc > 1) nTalkVolume = argv[1];
    else nTalkVolume = INT2NUM(TALKVOLUME_TALK);
    StackPushInteger(NUM2INT(nTalkVolume));
    StackPushInteger(NUM2INT(nStrRef));
    VM_ExecuteCommand(240, 2);
    return Qnil;
}

static VALUE NWScript_DestroyObject(int argc, VALUE *argv, VALUE self)
{
    VALUE oDestroy, fDelay;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    oDestroy = argv[0];
    if (argc > 1) fDelay = argv[1];
    else fDelay = rb_float_new(0.0f);
    StackPushFloat(NUM2DBL(fDelay));
    StackPushObject(NUM2UINT(oDestroy));
    VM_ExecuteCommand(241, 2);
    return Qnil;
}

static VALUE NWScript_GetModule(VALUE self)
{
    VM_ExecuteCommand(242, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_CreateObject(int argc, VALUE *argv, VALUE self)
{
    VALUE nObjectType, sTemplate, lLocation, bUseAppearAnimation, sNewTag;
    if (argc < 3) {
        //TODO: Raise exception
        return Qnil;
    }
    nObjectType = argv[0];
    sTemplate = argv[1];
    lLocation = argv[2];
    if (argc > 3) bUseAppearAnimation = argv[3];
    else bUseAppearAnimation = INT2NUM(FALSE);
    if (argc > 4) sNewTag = argv[4];
    else sNewTag = rb_str_new2("");
    StackPushString(StringValueCStr(sNewTag));
    StackPushInteger(NUM2INT(bUseAppearAnimation));
    CScriptLocation *lLocation_ptr;
    Data_Get_Struct(lLocation, CScriptLocation, lLocation_ptr);
    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lLocation_ptr);
    StackPushString(StringValueCStr(sTemplate));
    StackPushInteger(NUM2INT(nObjectType));
    VM_ExecuteCommand(243, 5);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_EventSpellCastAt(int argc, VALUE *argv, VALUE self)
{
    VALUE oCaster, nSpell, bHarmful;
    if (argc < 2) {
        //TODO: Raise exception
        return Qnil;
    }
    oCaster = argv[0];
    nSpell = argv[1];
    if (argc > 2) bHarmful = argv[2];
    else bHarmful = INT2NUM(TRUE);
    StackPushInteger(NUM2INT(bHarmful));
    StackPushInteger(NUM2INT(nSpell));
    StackPushObject(NUM2UINT(oCaster));
    VM_ExecuteCommand(244, 3);
//ERROR: Undefined variable type: event
    return Qnil;
}

static VALUE NWScript_GetLastSpellCaster(VALUE self)
{
    VM_ExecuteCommand(245, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastSpell(VALUE self)
{
    VM_ExecuteCommand(246, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetUserDefinedEventNumber(VALUE self)
{
    VM_ExecuteCommand(247, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetSpellId(VALUE self)
{
    VM_ExecuteCommand(248, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_RandomName(int argc, VALUE *argv, VALUE self)
{
    VALUE nNameType;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) nNameType = argv[0];
    else nNameType = INT2NUM(NAME_FIRST_GENERIC_MALE);
    StackPushInteger(NUM2INT(nNameType));
    VM_ExecuteCommand(249, 1);
    char *sRetVal;
    StackPopString(&sRetVal);
    return rb_str_new2(sRetVal);
}

static VALUE NWScript_EffectPoison(VALUE self, VALUE nPoisonType)
{
    StackPushInteger(NUM2INT(nPoisonType));
    VM_ExecuteCommand(250, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_EffectDisease(VALUE self, VALUE nDiseaseType)
{
    StackPushInteger(NUM2INT(nDiseaseType));
    VM_ExecuteCommand(251, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_EffectSilence(VALUE self)
{
    VM_ExecuteCommand(252, 0);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_GetName(int argc, VALUE *argv, VALUE self)
{
    VALUE oObject, bOriginalName;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    oObject = argv[0];
    if (argc > 1) bOriginalName = argv[1];
    else bOriginalName = INT2NUM(FALSE);
    StackPushInteger(NUM2INT(bOriginalName));
    StackPushObject(NUM2UINT(oObject));
    VM_ExecuteCommand(253, 2);
    char *sRetVal;
    StackPopString(&sRetVal);
    return rb_str_new2(sRetVal);
}

static VALUE NWScript_GetLastSpeaker(VALUE self)
{
    VM_ExecuteCommand(254, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_BeginConversation(int argc, VALUE *argv, VALUE self)
{
    VALUE sResRef, oObjectToDialog;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) sResRef = argv[0];
    else sResRef = rb_str_new2("");
    if (argc > 1) oObjectToDialog = argv[1];
    else oObjectToDialog = INT2NUM(OBJECT_INVALID);
    StackPushObject(NUM2UINT(oObjectToDialog));
    StackPushString(StringValueCStr(sResRef));
    VM_ExecuteCommand(255, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastPerceived(VALUE self)
{
    VM_ExecuteCommand(256, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastPerceptionHeard(VALUE self)
{
    VM_ExecuteCommand(257, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastPerceptionInaudible(VALUE self)
{
    VM_ExecuteCommand(258, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastPerceptionSeen(VALUE self)
{
    VM_ExecuteCommand(259, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastClosedBy(VALUE self)
{
    VM_ExecuteCommand(260, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastPerceptionVanished(VALUE self)
{
    VM_ExecuteCommand(261, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetFirstInPersistentObject(int argc, VALUE *argv, VALUE self)
{
    VALUE oPersistentObject, nResidentObjectType, nPersistentZone;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oPersistentObject = argv[0];
    else oPersistentObject = INT2NUM(OBJECT_SELF);
    if (argc > 1) nResidentObjectType = argv[1];
    else nResidentObjectType = INT2NUM(OBJECT_TYPE_CREATURE);
    if (argc > 2) nPersistentZone = argv[2];
    else nPersistentZone = INT2NUM(PERSISTENT_ZONE_ACTIVE);
    StackPushInteger(NUM2INT(nPersistentZone));
    StackPushInteger(NUM2INT(nResidentObjectType));
    StackPushObject(NUM2UINT(oPersistentObject));
    VM_ExecuteCommand(262, 3);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetNextInPersistentObject(int argc, VALUE *argv, VALUE self)
{
    VALUE oPersistentObject, nResidentObjectType, nPersistentZone;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oPersistentObject = argv[0];
    else oPersistentObject = INT2NUM(OBJECT_SELF);
    if (argc > 1) nResidentObjectType = argv[1];
    else nResidentObjectType = INT2NUM(OBJECT_TYPE_CREATURE);
    if (argc > 2) nPersistentZone = argv[2];
    else nPersistentZone = INT2NUM(PERSISTENT_ZONE_ACTIVE);
    StackPushInteger(NUM2INT(nPersistentZone));
    StackPushInteger(NUM2INT(nResidentObjectType));
    StackPushObject(NUM2UINT(oPersistentObject));
    VM_ExecuteCommand(263, 3);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetAreaOfEffectCreator(int argc, VALUE *argv, VALUE self)
{
    VALUE oAreaOfEffectObject;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oAreaOfEffectObject = argv[0];
    else oAreaOfEffectObject = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oAreaOfEffectObject));
    VM_ExecuteCommand(264, 1);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_DeleteLocalInt(VALUE self, VALUE oObject, VALUE sVarName)
{
    StackPushString(StringValueCStr(sVarName));
    StackPushObject(NUM2UINT(oObject));
    VM_ExecuteCommand(265, 2);
    return Qnil;
}

static VALUE NWScript_DeleteLocalFloat(VALUE self, VALUE oObject, VALUE sVarName)
{
    StackPushString(StringValueCStr(sVarName));
    StackPushObject(NUM2UINT(oObject));
    VM_ExecuteCommand(266, 2);
    return Qnil;
}

static VALUE NWScript_DeleteLocalString(VALUE self, VALUE oObject, VALUE sVarName)
{
    StackPushString(StringValueCStr(sVarName));
    StackPushObject(NUM2UINT(oObject));
    VM_ExecuteCommand(267, 2);
    return Qnil;
}

static VALUE NWScript_DeleteLocalObject(VALUE self, VALUE oObject, VALUE sVarName)
{
    StackPushString(StringValueCStr(sVarName));
    StackPushObject(NUM2UINT(oObject));
    VM_ExecuteCommand(268, 2);
    return Qnil;
}

static VALUE NWScript_DeleteLocalLocation(VALUE self, VALUE oObject, VALUE sVarName)
{
    StackPushString(StringValueCStr(sVarName));
    StackPushObject(NUM2UINT(oObject));
    VM_ExecuteCommand(269, 2);
    return Qnil;
}

static VALUE NWScript_EffectHaste(VALUE self)
{
    VM_ExecuteCommand(270, 0);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_EffectSlow(VALUE self)
{
    VM_ExecuteCommand(271, 0);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_ObjectToString(VALUE self, VALUE oObject)
{
    StackPushObject(NUM2UINT(oObject));
    VM_ExecuteCommand(272, 1);
    char *sRetVal;
    StackPopString(&sRetVal);
    return rb_str_new2(sRetVal);
}

static VALUE NWScript_EffectImmunity(VALUE self, VALUE nImmunityType)
{
    StackPushInteger(NUM2INT(nImmunityType));
    VM_ExecuteCommand(273, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_GetIsImmune(int argc, VALUE *argv, VALUE self)
{
    VALUE oCreature, nImmunityType, oVersus;
    if (argc < 2) {
        //TODO: Raise exception
        return Qnil;
    }
    oCreature = argv[0];
    nImmunityType = argv[1];
    if (argc > 2) oVersus = argv[2];
    else oVersus = INT2NUM(OBJECT_INVALID);
    StackPushObject(NUM2UINT(oVersus));
    StackPushInteger(NUM2INT(nImmunityType));
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(274, 3);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_EffectDamageImmunityIncrease(VALUE self, VALUE nDamageType, VALUE nPercentImmunity)
{
    StackPushInteger(NUM2INT(nPercentImmunity));
    StackPushInteger(NUM2INT(nDamageType));
    VM_ExecuteCommand(275, 2);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_GetEncounterActive(int argc, VALUE *argv, VALUE self)
{
    VALUE oEncounter;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oEncounter = argv[0];
    else oEncounter = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oEncounter));
    VM_ExecuteCommand(276, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_SetEncounterActive(int argc, VALUE *argv, VALUE self)
{
    VALUE nNewValue, oEncounter;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    nNewValue = argv[0];
    if (argc > 1) oEncounter = argv[1];
    else oEncounter = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oEncounter));
    StackPushInteger(NUM2INT(nNewValue));
    VM_ExecuteCommand(277, 2);
    return Qnil;
}

static VALUE NWScript_GetEncounterSpawnsMax(int argc, VALUE *argv, VALUE self)
{
    VALUE oEncounter;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oEncounter = argv[0];
    else oEncounter = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oEncounter));
    VM_ExecuteCommand(278, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_SetEncounterSpawnsMax(int argc, VALUE *argv, VALUE self)
{
    VALUE nNewValue, oEncounter;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    nNewValue = argv[0];
    if (argc > 1) oEncounter = argv[1];
    else oEncounter = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oEncounter));
    StackPushInteger(NUM2INT(nNewValue));
    VM_ExecuteCommand(279, 2);
    return Qnil;
}

static VALUE NWScript_GetEncounterSpawnsCurrent(int argc, VALUE *argv, VALUE self)
{
    VALUE oEncounter;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oEncounter = argv[0];
    else oEncounter = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oEncounter));
    VM_ExecuteCommand(280, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_SetEncounterSpawnsCurrent(int argc, VALUE *argv, VALUE self)
{
    VALUE nNewValue, oEncounter;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    nNewValue = argv[0];
    if (argc > 1) oEncounter = argv[1];
    else oEncounter = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oEncounter));
    StackPushInteger(NUM2INT(nNewValue));
    VM_ExecuteCommand(281, 2);
    return Qnil;
}

static VALUE NWScript_GetModuleItemAcquired(VALUE self)
{
    VM_ExecuteCommand(282, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetModuleItemAcquiredFrom(VALUE self)
{
    VM_ExecuteCommand(283, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_SetCustomToken(VALUE self, VALUE nCustomTokenNumber, VALUE sTokenValue)
{
    StackPushString(StringValueCStr(sTokenValue));
    StackPushInteger(NUM2INT(nCustomTokenNumber));
    VM_ExecuteCommand(284, 2);
    return Qnil;
}

static VALUE NWScript_GetHasFeat(int argc, VALUE *argv, VALUE self)
{
    VALUE nFeat, oCreature;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    nFeat = argv[0];
    if (argc > 1) oCreature = argv[1];
    else oCreature = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oCreature));
    StackPushInteger(NUM2INT(nFeat));
    VM_ExecuteCommand(285, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetHasSkill(int argc, VALUE *argv, VALUE self)
{
    VALUE nSkill, oCreature;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    nSkill = argv[0];
    if (argc > 1) oCreature = argv[1];
    else oCreature = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oCreature));
    StackPushInteger(NUM2INT(nSkill));
    VM_ExecuteCommand(286, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_ActionUseFeat(VALUE self, VALUE nFeat, VALUE oTarget)
{
    StackPushObject(NUM2UINT(oTarget));
    StackPushInteger(NUM2INT(nFeat));
    VM_ExecuteCommand(287, 2);
    return Qnil;
}

static VALUE NWScript_ActionUseSkill(int argc, VALUE *argv, VALUE self)
{
    VALUE nSkill, oTarget, nSubSkill, oItemUsed;
    if (argc < 2) {
        //TODO: Raise exception
        return Qnil;
    }
    nSkill = argv[0];
    oTarget = argv[1];
    if (argc > 2) nSubSkill = argv[2];
    else nSubSkill = INT2NUM(0);
    if (argc > 3) oItemUsed = argv[3];
    else oItemUsed = INT2NUM(OBJECT_INVALID);
    StackPushObject(NUM2UINT(oItemUsed));
    StackPushInteger(NUM2INT(nSubSkill));
    StackPushObject(NUM2UINT(oTarget));
    StackPushInteger(NUM2INT(nSkill));
    VM_ExecuteCommand(288, 4);
    return Qnil;
}

static VALUE NWScript_GetObjectSeen(int argc, VALUE *argv, VALUE self)
{
    VALUE oTarget, oSource;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    oTarget = argv[0];
    if (argc > 1) oSource = argv[1];
    else oSource = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oSource));
    StackPushObject(NUM2UINT(oTarget));
    VM_ExecuteCommand(289, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetObjectHeard(int argc, VALUE *argv, VALUE self)
{
    VALUE oTarget, oSource;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    oTarget = argv[0];
    if (argc > 1) oSource = argv[1];
    else oSource = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oSource));
    StackPushObject(NUM2UINT(oTarget));
    VM_ExecuteCommand(290, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastPlayerDied(VALUE self)
{
    VM_ExecuteCommand(291, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetModuleItemLost(VALUE self)
{
    VM_ExecuteCommand(292, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetModuleItemLostBy(VALUE self)
{
    VM_ExecuteCommand(293, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_ActionDoCommand(VALUE self, VALUE aActionToDo)
{
    //ERROR: Undefined variable type: action
    VM_ExecuteCommand(294, 1);
    return Qnil;
}

static VALUE NWScript_EventConversation(VALUE self)
{
    VM_ExecuteCommand(295, 0);
//ERROR: Undefined variable type: event
    return Qnil;
}

static VALUE NWScript_SetEncounterDifficulty(int argc, VALUE *argv, VALUE self)
{
    VALUE nEncounterDifficulty, oEncounter;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    nEncounterDifficulty = argv[0];
    if (argc > 1) oEncounter = argv[1];
    else oEncounter = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oEncounter));
    StackPushInteger(NUM2INT(nEncounterDifficulty));
    VM_ExecuteCommand(296, 2);
    return Qnil;
}

static VALUE NWScript_GetEncounterDifficulty(int argc, VALUE *argv, VALUE self)
{
    VALUE oEncounter;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oEncounter = argv[0];
    else oEncounter = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oEncounter));
    VM_ExecuteCommand(297, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetDistanceBetweenLocations(VALUE self, VALUE lLocationA, VALUE lLocationB)
{
    CScriptLocation *lLocationB_ptr;
    Data_Get_Struct(lLocationB, CScriptLocation, lLocationB_ptr);
    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lLocationB_ptr);
    CScriptLocation *lLocationA_ptr;
    Data_Get_Struct(lLocationA, CScriptLocation, lLocationA_ptr);
    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lLocationA_ptr);
    VM_ExecuteCommand(298, 2);
    float fRetVal;
    StackPopFloat(&fRetVal);
    return rb_float_new(fRetVal);
}

static VALUE NWScript_GetReflexAdjustedDamage(int argc, VALUE *argv, VALUE self)
{
    VALUE nDamage, oTarget, nDC, nSaveType, oSaveVersus;
    if (argc < 3) {
        //TODO: Raise exception
        return Qnil;
    }
    nDamage = argv[0];
    oTarget = argv[1];
    nDC = argv[2];
    if (argc > 3) nSaveType = argv[3];
    else nSaveType = INT2NUM(SAVING_THROW_TYPE_NONE);
    if (argc > 4) oSaveVersus = argv[4];
    else oSaveVersus = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oSaveVersus));
    StackPushInteger(NUM2INT(nSaveType));
    StackPushInteger(NUM2INT(nDC));
    StackPushObject(NUM2UINT(oTarget));
    StackPushInteger(NUM2INT(nDamage));
    VM_ExecuteCommand(299, 5);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_PlayAnimation(int argc, VALUE *argv, VALUE self)
{
    VALUE nAnimation, fSpeed, fSeconds;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    nAnimation = argv[0];
    if (argc > 1) fSpeed = argv[1];
    else fSpeed = rb_float_new(1.0);
    if (argc > 2) fSeconds = argv[2];
    else fSeconds = rb_float_new(0.0);
    StackPushFloat(NUM2DBL(fSeconds));
    StackPushFloat(NUM2DBL(fSpeed));
    StackPushInteger(NUM2INT(nAnimation));
    VM_ExecuteCommand(300, 3);
    return Qnil;
}

static VALUE NWScript_TalentSpell(VALUE self, VALUE nSpell)
{
    StackPushInteger(NUM2INT(nSpell));
    VM_ExecuteCommand(301, 1);
//ERROR: Undefined variable type: talent
    return Qnil;
}

static VALUE NWScript_TalentFeat(VALUE self, VALUE nFeat)
{
    StackPushInteger(NUM2INT(nFeat));
    VM_ExecuteCommand(302, 1);
//ERROR: Undefined variable type: talent
    return Qnil;
}

static VALUE NWScript_TalentSkill(VALUE self, VALUE nSkill)
{
    StackPushInteger(NUM2INT(nSkill));
    VM_ExecuteCommand(303, 1);
//ERROR: Undefined variable type: talent
    return Qnil;
}

static VALUE NWScript_GetHasSpellEffect(int argc, VALUE *argv, VALUE self)
{
    VALUE nSpell, oObject;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    nSpell = argv[0];
    if (argc > 1) oObject = argv[1];
    else oObject = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oObject));
    StackPushInteger(NUM2INT(nSpell));
    VM_ExecuteCommand(304, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetEffectSpellId(VALUE self, VALUE eSpellEffect)
{
    CGameEffect *eSpellEffect_ptr;
    Data_Get_Struct(eSpellEffect, CGameEffect, eSpellEffect_ptr);
    StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eSpellEffect_ptr);
    VM_ExecuteCommand(305, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetCreatureHasTalent(int argc, VALUE *argv, VALUE self)
{
    VALUE tTalent, oCreature;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    tTalent = argv[0];
    if (argc > 1) oCreature = argv[1];
    else oCreature = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oCreature));
    //ERROR: Undefined variable type: talent
    VM_ExecuteCommand(306, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetCreatureTalentRandom(int argc, VALUE *argv, VALUE self)
{
    VALUE nCategory, oCreature;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    nCategory = argv[0];
    if (argc > 1) oCreature = argv[1];
    else oCreature = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oCreature));
    StackPushInteger(NUM2INT(nCategory));
    VM_ExecuteCommand(307, 2);
//ERROR: Undefined variable type: talent
    return Qnil;
}

static VALUE NWScript_GetCreatureTalentBest(int argc, VALUE *argv, VALUE self)
{
    VALUE nCategory, nCRMax, oCreature;
    if (argc < 2) {
        //TODO: Raise exception
        return Qnil;
    }
    nCategory = argv[0];
    nCRMax = argv[1];
    if (argc > 2) oCreature = argv[2];
    else oCreature = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oCreature));
    StackPushInteger(NUM2INT(nCRMax));
    StackPushInteger(NUM2INT(nCategory));
    VM_ExecuteCommand(308, 3);
//ERROR: Undefined variable type: talent
    return Qnil;
}

static VALUE NWScript_ActionUseTalentOnObject(VALUE self, VALUE tChosenTalent, VALUE oTarget)
{
    StackPushObject(NUM2UINT(oTarget));
    //ERROR: Undefined variable type: talent
    VM_ExecuteCommand(309, 2);
    return Qnil;
}

static VALUE NWScript_ActionUseTalentAtLocation(VALUE self, VALUE tChosenTalent, VALUE lTargetLocation)
{
    CScriptLocation *lTargetLocation_ptr;
    Data_Get_Struct(lTargetLocation, CScriptLocation, lTargetLocation_ptr);
    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lTargetLocation_ptr);
    //ERROR: Undefined variable type: talent
    VM_ExecuteCommand(310, 2);
    return Qnil;
}

static VALUE NWScript_GetGoldPieceValue(VALUE self, VALUE oItem)
{
    StackPushObject(NUM2UINT(oItem));
    VM_ExecuteCommand(311, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetIsPlayableRacialType(VALUE self, VALUE oCreature)
{
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(312, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_JumpToLocation(VALUE self, VALUE lDestination)
{
    CScriptLocation *lDestination_ptr;
    Data_Get_Struct(lDestination, CScriptLocation, lDestination_ptr);
    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lDestination_ptr);
    VM_ExecuteCommand(313, 1);
    return Qnil;
}

static VALUE NWScript_EffectTemporaryHitpoints(VALUE self, VALUE nHitPoints)
{
    StackPushInteger(NUM2INT(nHitPoints));
    VM_ExecuteCommand(314, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_GetSkillRank(int argc, VALUE *argv, VALUE self)
{
    VALUE nSkill, oTarget, nBaseSkillRank;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    nSkill = argv[0];
    if (argc > 1) oTarget = argv[1];
    else oTarget = INT2NUM(OBJECT_SELF);
    if (argc > 2) nBaseSkillRank = argv[2];
    else nBaseSkillRank = INT2NUM(FALSE);
    StackPushInteger(NUM2INT(nBaseSkillRank));
    StackPushObject(NUM2UINT(oTarget));
    StackPushInteger(NUM2INT(nSkill));
    VM_ExecuteCommand(315, 3);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetAttackTarget(int argc, VALUE *argv, VALUE self)
{
    VALUE oCreature;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oCreature = argv[0];
    else oCreature = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(316, 1);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastAttackType(int argc, VALUE *argv, VALUE self)
{
    VALUE oCreature;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oCreature = argv[0];
    else oCreature = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(317, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastAttackMode(int argc, VALUE *argv, VALUE self)
{
    VALUE oCreature;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oCreature = argv[0];
    else oCreature = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(318, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetMaster(int argc, VALUE *argv, VALUE self)
{
    VALUE oAssociate;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oAssociate = argv[0];
    else oAssociate = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oAssociate));
    VM_ExecuteCommand(319, 1);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetIsInCombat(int argc, VALUE *argv, VALUE self)
{
    VALUE oCreature;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oCreature = argv[0];
    else oCreature = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(320, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastAssociateCommand(int argc, VALUE *argv, VALUE self)
{
    VALUE oAssociate;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oAssociate = argv[0];
    else oAssociate = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oAssociate));
    VM_ExecuteCommand(321, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GiveGoldToCreature(VALUE self, VALUE oCreature, VALUE nGP)
{
    StackPushInteger(NUM2INT(nGP));
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(322, 2);
    return Qnil;
}

static VALUE NWScript_SetIsDestroyable(int argc, VALUE *argv, VALUE self)
{
    VALUE bDestroyable, bRaiseable, bSelectableWhenDead;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    bDestroyable = argv[0];
    if (argc > 1) bRaiseable = argv[1];
    else bRaiseable = INT2NUM(TRUE);
    if (argc > 2) bSelectableWhenDead = argv[2];
    else bSelectableWhenDead = INT2NUM(FALSE);
    StackPushInteger(NUM2INT(bSelectableWhenDead));
    StackPushInteger(NUM2INT(bRaiseable));
    StackPushInteger(NUM2INT(bDestroyable));
    VM_ExecuteCommand(323, 3);
    return Qnil;
}

static VALUE NWScript_SetLocked(VALUE self, VALUE oTarget, VALUE bLocked)
{
    StackPushInteger(NUM2INT(bLocked));
    StackPushObject(NUM2UINT(oTarget));
    VM_ExecuteCommand(324, 2);
    return Qnil;
}

static VALUE NWScript_GetLocked(VALUE self, VALUE oTarget)
{
    StackPushObject(NUM2UINT(oTarget));
    VM_ExecuteCommand(325, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetClickingObject(VALUE self)
{
    VM_ExecuteCommand(326, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_SetAssociateListenPatterns(int argc, VALUE *argv, VALUE self)
{
    VALUE oTarget;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oTarget = argv[0];
    else oTarget = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oTarget));
    VM_ExecuteCommand(327, 1);
    return Qnil;
}

static VALUE NWScript_GetLastWeaponUsed(VALUE self, VALUE oCreature)
{
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(328, 1);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_ActionInteractObject(VALUE self, VALUE oPlaceable)
{
    StackPushObject(NUM2UINT(oPlaceable));
    VM_ExecuteCommand(329, 1);
    return Qnil;
}

static VALUE NWScript_GetLastUsedBy(VALUE self)
{
    VM_ExecuteCommand(330, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetAbilityModifier(int argc, VALUE *argv, VALUE self)
{
    VALUE nAbility, oCreature;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    nAbility = argv[0];
    if (argc > 1) oCreature = argv[1];
    else oCreature = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oCreature));
    StackPushInteger(NUM2INT(nAbility));
    VM_ExecuteCommand(331, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetIdentified(VALUE self, VALUE oItem)
{
    StackPushObject(NUM2UINT(oItem));
    VM_ExecuteCommand(332, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_SetIdentified(VALUE self, VALUE oItem, VALUE bIdentified)
{
    StackPushInteger(NUM2INT(bIdentified));
    StackPushObject(NUM2UINT(oItem));
    VM_ExecuteCommand(333, 2);
    return Qnil;
}

static VALUE NWScript_SummonAnimalCompanion(int argc, VALUE *argv, VALUE self)
{
    VALUE oMaster;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oMaster = argv[0];
    else oMaster = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oMaster));
    VM_ExecuteCommand(334, 1);
    return Qnil;
}

static VALUE NWScript_SummonFamiliar(int argc, VALUE *argv, VALUE self)
{
    VALUE oMaster;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oMaster = argv[0];
    else oMaster = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oMaster));
    VM_ExecuteCommand(335, 1);
    return Qnil;
}

static VALUE NWScript_GetBlockingDoor(VALUE self)
{
    VM_ExecuteCommand(336, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetIsDoorActionPossible(VALUE self, VALUE oTargetDoor, VALUE nDoorAction)
{
    StackPushInteger(NUM2INT(nDoorAction));
    StackPushObject(NUM2UINT(oTargetDoor));
    VM_ExecuteCommand(337, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_DoDoorAction(VALUE self, VALUE oTargetDoor, VALUE nDoorAction)
{
    StackPushInteger(NUM2INT(nDoorAction));
    StackPushObject(NUM2UINT(oTargetDoor));
    VM_ExecuteCommand(338, 2);
    return Qnil;
}

static VALUE NWScript_GetFirstItemInInventory(int argc, VALUE *argv, VALUE self)
{
    VALUE oTarget;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oTarget = argv[0];
    else oTarget = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oTarget));
    VM_ExecuteCommand(339, 1);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetNextItemInInventory(int argc, VALUE *argv, VALUE self)
{
    VALUE oTarget;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oTarget = argv[0];
    else oTarget = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oTarget));
    VM_ExecuteCommand(340, 1);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetClassByPosition(int argc, VALUE *argv, VALUE self)
{
    VALUE nClassPosition, oCreature;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    nClassPosition = argv[0];
    if (argc > 1) oCreature = argv[1];
    else oCreature = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oCreature));
    StackPushInteger(NUM2INT(nClassPosition));
    VM_ExecuteCommand(341, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLevelByPosition(int argc, VALUE *argv, VALUE self)
{
    VALUE nClassPosition, oCreature;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    nClassPosition = argv[0];
    if (argc > 1) oCreature = argv[1];
    else oCreature = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oCreature));
    StackPushInteger(NUM2INT(nClassPosition));
    VM_ExecuteCommand(342, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLevelByClass(int argc, VALUE *argv, VALUE self)
{
    VALUE nClassType, oCreature;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    nClassType = argv[0];
    if (argc > 1) oCreature = argv[1];
    else oCreature = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oCreature));
    StackPushInteger(NUM2INT(nClassType));
    VM_ExecuteCommand(343, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetDamageDealtByType(VALUE self, VALUE nDamageType)
{
    StackPushInteger(NUM2INT(nDamageType));
    VM_ExecuteCommand(344, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetTotalDamageDealt(VALUE self)
{
    VM_ExecuteCommand(345, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastDamager(int argc, VALUE *argv, VALUE self)
{
    VALUE oObject;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oObject = argv[0];
    else oObject = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oObject));
    VM_ExecuteCommand(346, 1);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastDisarmed(VALUE self)
{
    VM_ExecuteCommand(347, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastDisturbed(VALUE self)
{
    VM_ExecuteCommand(348, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastLocked(VALUE self)
{
    VM_ExecuteCommand(349, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastUnlocked(VALUE self)
{
    VM_ExecuteCommand(350, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_EffectSkillIncrease(VALUE self, VALUE nSkill, VALUE nValue)
{
    StackPushInteger(NUM2INT(nValue));
    StackPushInteger(NUM2INT(nSkill));
    VM_ExecuteCommand(351, 2);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_GetInventoryDisturbType(VALUE self)
{
    VM_ExecuteCommand(352, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetInventoryDisturbItem(VALUE self)
{
    VM_ExecuteCommand(353, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetHenchman(int argc, VALUE *argv, VALUE self)
{
    VALUE oMaster, nNth;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oMaster = argv[0];
    else oMaster = INT2NUM(OBJECT_SELF);
    if (argc > 1) nNth = argv[1];
    else nNth = INT2NUM(1);
    StackPushInteger(NUM2INT(nNth));
    StackPushObject(NUM2UINT(oMaster));
    VM_ExecuteCommand(354, 2);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_VersusAlignmentEffect(int argc, VALUE *argv, VALUE self)
{
    VALUE eEffect, nLawChaos, nGoodEvil;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    eEffect = argv[0];
    if (argc > 1) nLawChaos = argv[1];
    else nLawChaos = INT2NUM(ALIGNMENT_ALL);
    if (argc > 2) nGoodEvil = argv[2];
    else nGoodEvil = INT2NUM(ALIGNMENT_ALL);
    StackPushInteger(NUM2INT(nGoodEvil));
    StackPushInteger(NUM2INT(nLawChaos));
    CGameEffect *eEffect_ptr;
    Data_Get_Struct(eEffect, CGameEffect, eEffect_ptr);
    StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eEffect_ptr);
    VM_ExecuteCommand(355, 3);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_VersusRacialTypeEffect(VALUE self, VALUE eEffect, VALUE nRacialType)
{
    StackPushInteger(NUM2INT(nRacialType));
    CGameEffect *eEffect_ptr;
    Data_Get_Struct(eEffect, CGameEffect, eEffect_ptr);
    StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eEffect_ptr);
    VM_ExecuteCommand(356, 2);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_VersusTrapEffect(VALUE self, VALUE eEffect)
{
    CGameEffect *eEffect_ptr;
    Data_Get_Struct(eEffect, CGameEffect, eEffect_ptr);
    StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eEffect_ptr);
    VM_ExecuteCommand(357, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_GetGender(VALUE self, VALUE oCreature)
{
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(358, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetIsTalentValid(VALUE self, VALUE tTalent)
{
    //ERROR: Undefined variable type: talent
    VM_ExecuteCommand(359, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_ActionMoveAwayFromLocation(int argc, VALUE *argv, VALUE self)
{
    VALUE lMoveAwayFrom, bRun, fMoveAwayRange;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    lMoveAwayFrom = argv[0];
    if (argc > 1) bRun = argv[1];
    else bRun = INT2NUM(FALSE);
    if (argc > 2) fMoveAwayRange = argv[2];
    else fMoveAwayRange = rb_float_new(40.0f);
    StackPushFloat(NUM2DBL(fMoveAwayRange));
    StackPushInteger(NUM2INT(bRun));
    CScriptLocation *lMoveAwayFrom_ptr;
    Data_Get_Struct(lMoveAwayFrom, CScriptLocation, lMoveAwayFrom_ptr);
    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lMoveAwayFrom_ptr);
    VM_ExecuteCommand(360, 3);
    return Qnil;
}

static VALUE NWScript_GetAttemptedAttackTarget(VALUE self)
{
    VM_ExecuteCommand(361, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetTypeFromTalent(VALUE self, VALUE tTalent)
{
    //ERROR: Undefined variable type: talent
    VM_ExecuteCommand(362, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetIdFromTalent(VALUE self, VALUE tTalent)
{
    //ERROR: Undefined variable type: talent
    VM_ExecuteCommand(363, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetAssociate(int argc, VALUE *argv, VALUE self)
{
    VALUE nAssociateType, oMaster, nTh;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    nAssociateType = argv[0];
    if (argc > 1) oMaster = argv[1];
    else oMaster = INT2NUM(OBJECT_SELF);
    if (argc > 2) nTh = argv[2];
    else nTh = INT2NUM(1);
    StackPushInteger(NUM2INT(nTh));
    StackPushObject(NUM2UINT(oMaster));
    StackPushInteger(NUM2INT(nAssociateType));
    VM_ExecuteCommand(364, 3);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_AddHenchman(int argc, VALUE *argv, VALUE self)
{
    VALUE oMaster, oHenchman;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    oMaster = argv[0];
    if (argc > 1) oHenchman = argv[1];
    else oHenchman = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oHenchman));
    StackPushObject(NUM2UINT(oMaster));
    VM_ExecuteCommand(365, 2);
    return Qnil;
}

static VALUE NWScript_RemoveHenchman(int argc, VALUE *argv, VALUE self)
{
    VALUE oMaster, oHenchman;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    oMaster = argv[0];
    if (argc > 1) oHenchman = argv[1];
    else oHenchman = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oHenchman));
    StackPushObject(NUM2UINT(oMaster));
    VM_ExecuteCommand(366, 2);
    return Qnil;
}

static VALUE NWScript_AddJournalQuestEntry(int argc, VALUE *argv, VALUE self)
{
    VALUE szPlotID, nState, oCreature, bAllPartyMembers, bAllPlayers, bAllowOverrideHigher;
    if (argc < 3) {
        //TODO: Raise exception
        return Qnil;
    }
    szPlotID = argv[0];
    nState = argv[1];
    oCreature = argv[2];
    if (argc > 3) bAllPartyMembers = argv[3];
    else bAllPartyMembers = INT2NUM(TRUE);
    if (argc > 4) bAllPlayers = argv[4];
    else bAllPlayers = INT2NUM(FALSE);
    if (argc > 5) bAllowOverrideHigher = argv[5];
    else bAllowOverrideHigher = INT2NUM(FALSE);
    StackPushInteger(NUM2INT(bAllowOverrideHigher));
    StackPushInteger(NUM2INT(bAllPlayers));
    StackPushInteger(NUM2INT(bAllPartyMembers));
    StackPushObject(NUM2UINT(oCreature));
    StackPushInteger(NUM2INT(nState));
    StackPushString(StringValueCStr(szPlotID));
    VM_ExecuteCommand(367, 6);
    return Qnil;
}

static VALUE NWScript_RemoveJournalQuestEntry(int argc, VALUE *argv, VALUE self)
{
    VALUE szPlotID, oCreature, bAllPartyMembers, bAllPlayers;
    if (argc < 2) {
        //TODO: Raise exception
        return Qnil;
    }
    szPlotID = argv[0];
    oCreature = argv[1];
    if (argc > 2) bAllPartyMembers = argv[2];
    else bAllPartyMembers = INT2NUM(TRUE);
    if (argc > 3) bAllPlayers = argv[3];
    else bAllPlayers = INT2NUM(FALSE);
    StackPushInteger(NUM2INT(bAllPlayers));
    StackPushInteger(NUM2INT(bAllPartyMembers));
    StackPushObject(NUM2UINT(oCreature));
    StackPushString(StringValueCStr(szPlotID));
    VM_ExecuteCommand(368, 4);
    return Qnil;
}

static VALUE NWScript_GetPCPublicCDKey(int argc, VALUE *argv, VALUE self)
{
    VALUE oPlayer, nSinglePlayerCDKey;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    oPlayer = argv[0];
    if (argc > 1) nSinglePlayerCDKey = argv[1];
    else nSinglePlayerCDKey = INT2NUM(FALSE);
    StackPushInteger(NUM2INT(nSinglePlayerCDKey));
    StackPushObject(NUM2UINT(oPlayer));
    VM_ExecuteCommand(369, 2);
    char *sRetVal;
    StackPopString(&sRetVal);
    return rb_str_new2(sRetVal);
}

static VALUE NWScript_GetPCIPAddress(VALUE self, VALUE oPlayer)
{
    StackPushObject(NUM2UINT(oPlayer));
    VM_ExecuteCommand(370, 1);
    char *sRetVal;
    StackPopString(&sRetVal);
    return rb_str_new2(sRetVal);
}

static VALUE NWScript_GetPCPlayerName(VALUE self, VALUE oPlayer)
{
    StackPushObject(NUM2UINT(oPlayer));
    VM_ExecuteCommand(371, 1);
    char *sRetVal;
    StackPopString(&sRetVal);
    return rb_str_new2(sRetVal);
}

static VALUE NWScript_SetPCLike(VALUE self, VALUE oPlayer, VALUE oTarget)
{
    StackPushObject(NUM2UINT(oTarget));
    StackPushObject(NUM2UINT(oPlayer));
    VM_ExecuteCommand(372, 2);
    return Qnil;
}

static VALUE NWScript_SetPCDislike(VALUE self, VALUE oPlayer, VALUE oTarget)
{
    StackPushObject(NUM2UINT(oTarget));
    StackPushObject(NUM2UINT(oPlayer));
    VM_ExecuteCommand(373, 2);
    return Qnil;
}

static VALUE NWScript_SendMessageToPC(VALUE self, VALUE oPlayer, VALUE szMessage)
{
    StackPushString(StringValueCStr(szMessage));
    StackPushObject(NUM2UINT(oPlayer));
    VM_ExecuteCommand(374, 2);
    return Qnil;
}

static VALUE NWScript_GetAttemptedSpellTarget(VALUE self)
{
    VM_ExecuteCommand(375, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastOpenedBy(VALUE self)
{
    VM_ExecuteCommand(376, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetHasSpell(int argc, VALUE *argv, VALUE self)
{
    VALUE nSpell, oCreature;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    nSpell = argv[0];
    if (argc > 1) oCreature = argv[1];
    else oCreature = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oCreature));
    StackPushInteger(NUM2INT(nSpell));
    VM_ExecuteCommand(377, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_OpenStore(int argc, VALUE *argv, VALUE self)
{
    VALUE oStore, oPC, nBonusMarkUp, nBonusMarkDown;
    if (argc < 2) {
        //TODO: Raise exception
        return Qnil;
    }
    oStore = argv[0];
    oPC = argv[1];
    if (argc > 2) nBonusMarkUp = argv[2];
    else nBonusMarkUp = INT2NUM(0);
    if (argc > 3) nBonusMarkDown = argv[3];
    else nBonusMarkDown = INT2NUM(0);
    StackPushInteger(NUM2INT(nBonusMarkDown));
    StackPushInteger(NUM2INT(nBonusMarkUp));
    StackPushObject(NUM2UINT(oPC));
    StackPushObject(NUM2UINT(oStore));
    VM_ExecuteCommand(378, 4);
    return Qnil;
}

static VALUE NWScript_EffectTurned(VALUE self)
{
    VM_ExecuteCommand(379, 0);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_GetFirstFactionMember(int argc, VALUE *argv, VALUE self)
{
    VALUE oMemberOfFaction, bPCOnly;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    oMemberOfFaction = argv[0];
    if (argc > 1) bPCOnly = argv[1];
    else bPCOnly = INT2NUM(TRUE);
    StackPushInteger(NUM2INT(bPCOnly));
    StackPushObject(NUM2UINT(oMemberOfFaction));
    VM_ExecuteCommand(380, 2);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetNextFactionMember(int argc, VALUE *argv, VALUE self)
{
    VALUE oMemberOfFaction, bPCOnly;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    oMemberOfFaction = argv[0];
    if (argc > 1) bPCOnly = argv[1];
    else bPCOnly = INT2NUM(TRUE);
    StackPushInteger(NUM2INT(bPCOnly));
    StackPushObject(NUM2UINT(oMemberOfFaction));
    VM_ExecuteCommand(381, 2);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_ActionForceMoveToLocation(int argc, VALUE *argv, VALUE self)
{
    VALUE lDestination, bRun, fTimeout;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    lDestination = argv[0];
    if (argc > 1) bRun = argv[1];
    else bRun = INT2NUM(FALSE);
    if (argc > 2) fTimeout = argv[2];
    else fTimeout = rb_float_new(30.0f);
    StackPushFloat(NUM2DBL(fTimeout));
    StackPushInteger(NUM2INT(bRun));
    CScriptLocation *lDestination_ptr;
    Data_Get_Struct(lDestination, CScriptLocation, lDestination_ptr);
    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lDestination_ptr);
    VM_ExecuteCommand(382, 3);
    return Qnil;
}

static VALUE NWScript_ActionForceMoveToObject(int argc, VALUE *argv, VALUE self)
{
    VALUE oMoveTo, bRun, fRange, fTimeout;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    oMoveTo = argv[0];
    if (argc > 1) bRun = argv[1];
    else bRun = INT2NUM(FALSE);
    if (argc > 2) fRange = argv[2];
    else fRange = rb_float_new(1.0f);
    if (argc > 3) fTimeout = argv[3];
    else fTimeout = rb_float_new(30.0f);
    StackPushFloat(NUM2DBL(fTimeout));
    StackPushFloat(NUM2DBL(fRange));
    StackPushInteger(NUM2INT(bRun));
    StackPushObject(NUM2UINT(oMoveTo));
    VM_ExecuteCommand(383, 4);
    return Qnil;
}

static VALUE NWScript_GetJournalQuestExperience(VALUE self, VALUE szPlotID)
{
    StackPushString(StringValueCStr(szPlotID));
    VM_ExecuteCommand(384, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_JumpToObject(int argc, VALUE *argv, VALUE self)
{
    VALUE oToJumpTo, nWalkStraightLineToPoint;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    oToJumpTo = argv[0];
    if (argc > 1) nWalkStraightLineToPoint = argv[1];
    else nWalkStraightLineToPoint = INT2NUM(1);
    StackPushInteger(NUM2INT(nWalkStraightLineToPoint));
    StackPushObject(NUM2UINT(oToJumpTo));
    VM_ExecuteCommand(385, 2);
    return Qnil;
}

static VALUE NWScript_SetMapPinEnabled(VALUE self, VALUE oMapPin, VALUE nEnabled)
{
    StackPushInteger(NUM2INT(nEnabled));
    StackPushObject(NUM2UINT(oMapPin));
    VM_ExecuteCommand(386, 2);
    return Qnil;
}

static VALUE NWScript_EffectHitPointChangeWhenDying(VALUE self, VALUE fHitPointChangePerRound)
{
    StackPushFloat(NUM2DBL(fHitPointChangePerRound));
    VM_ExecuteCommand(387, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_PopUpGUIPanel(VALUE self, VALUE oPC, VALUE nGUIPanel)
{
    StackPushInteger(NUM2INT(nGUIPanel));
    StackPushObject(NUM2UINT(oPC));
    VM_ExecuteCommand(388, 2);
    return Qnil;
}

static VALUE NWScript_ClearPersonalReputation(int argc, VALUE *argv, VALUE self)
{
    VALUE oTarget, oSource;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    oTarget = argv[0];
    if (argc > 1) oSource = argv[1];
    else oSource = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oSource));
    StackPushObject(NUM2UINT(oTarget));
    VM_ExecuteCommand(389, 2);
    return Qnil;
}

static VALUE NWScript_SetIsTemporaryFriend(int argc, VALUE *argv, VALUE self)
{
    VALUE oTarget, oSource, bDecays, fDurationInSeconds;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    oTarget = argv[0];
    if (argc > 1) oSource = argv[1];
    else oSource = INT2NUM(OBJECT_SELF);
    if (argc > 2) bDecays = argv[2];
    else bDecays = INT2NUM(FALSE);
    if (argc > 3) fDurationInSeconds = argv[3];
    else fDurationInSeconds = rb_float_new(180.0f);
    StackPushFloat(NUM2DBL(fDurationInSeconds));
    StackPushInteger(NUM2INT(bDecays));
    StackPushObject(NUM2UINT(oSource));
    StackPushObject(NUM2UINT(oTarget));
    VM_ExecuteCommand(390, 4);
    return Qnil;
}

static VALUE NWScript_SetIsTemporaryEnemy(int argc, VALUE *argv, VALUE self)
{
    VALUE oTarget, oSource, bDecays, fDurationInSeconds;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    oTarget = argv[0];
    if (argc > 1) oSource = argv[1];
    else oSource = INT2NUM(OBJECT_SELF);
    if (argc > 2) bDecays = argv[2];
    else bDecays = INT2NUM(FALSE);
    if (argc > 3) fDurationInSeconds = argv[3];
    else fDurationInSeconds = rb_float_new(180.0f);
    StackPushFloat(NUM2DBL(fDurationInSeconds));
    StackPushInteger(NUM2INT(bDecays));
    StackPushObject(NUM2UINT(oSource));
    StackPushObject(NUM2UINT(oTarget));
    VM_ExecuteCommand(391, 4);
    return Qnil;
}

static VALUE NWScript_SetIsTemporaryNeutral(int argc, VALUE *argv, VALUE self)
{
    VALUE oTarget, oSource, bDecays, fDurationInSeconds;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    oTarget = argv[0];
    if (argc > 1) oSource = argv[1];
    else oSource = INT2NUM(OBJECT_SELF);
    if (argc > 2) bDecays = argv[2];
    else bDecays = INT2NUM(FALSE);
    if (argc > 3) fDurationInSeconds = argv[3];
    else fDurationInSeconds = rb_float_new(180.0f);
    StackPushFloat(NUM2DBL(fDurationInSeconds));
    StackPushInteger(NUM2INT(bDecays));
    StackPushObject(NUM2UINT(oSource));
    StackPushObject(NUM2UINT(oTarget));
    VM_ExecuteCommand(392, 4);
    return Qnil;
}

static VALUE NWScript_GiveXPToCreature(VALUE self, VALUE oCreature, VALUE nXpAmount)
{
    StackPushInteger(NUM2INT(nXpAmount));
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(393, 2);
    return Qnil;
}

static VALUE NWScript_SetXP(VALUE self, VALUE oCreature, VALUE nXpAmount)
{
    StackPushInteger(NUM2INT(nXpAmount));
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(394, 2);
    return Qnil;
}

static VALUE NWScript_GetXP(VALUE self, VALUE oCreature)
{
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(395, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_IntToHexString(VALUE self, VALUE nInteger)
{
    StackPushInteger(NUM2INT(nInteger));
    VM_ExecuteCommand(396, 1);
    char *sRetVal;
    StackPopString(&sRetVal);
    return rb_str_new2(sRetVal);
}

static VALUE NWScript_GetBaseItemType(VALUE self, VALUE oItem)
{
    StackPushObject(NUM2UINT(oItem));
    VM_ExecuteCommand(397, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetItemHasItemProperty(VALUE self, VALUE oItem, VALUE nProperty)
{
    StackPushInteger(NUM2INT(nProperty));
    StackPushObject(NUM2UINT(oItem));
    VM_ExecuteCommand(398, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_ActionEquipMostDamagingMelee(int argc, VALUE *argv, VALUE self)
{
    VALUE oVersus, bOffHand;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oVersus = argv[0];
    else oVersus = INT2NUM(OBJECT_INVALID);
    if (argc > 1) bOffHand = argv[1];
    else bOffHand = INT2NUM(FALSE);
    StackPushInteger(NUM2INT(bOffHand));
    StackPushObject(NUM2UINT(oVersus));
    VM_ExecuteCommand(399, 2);
    return Qnil;
}

static VALUE NWScript_ActionEquipMostDamagingRanged(int argc, VALUE *argv, VALUE self)
{
    VALUE oVersus;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oVersus = argv[0];
    else oVersus = INT2NUM(OBJECT_INVALID);
    StackPushObject(NUM2UINT(oVersus));
    VM_ExecuteCommand(400, 1);
    return Qnil;
}

static VALUE NWScript_GetItemACValue(VALUE self, VALUE oItem)
{
    StackPushObject(NUM2UINT(oItem));
    VM_ExecuteCommand(401, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_ActionRest(int argc, VALUE *argv, VALUE self)
{
    VALUE bCreatureToEnemyLineOfSightCheck;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) bCreatureToEnemyLineOfSightCheck = argv[0];
    else bCreatureToEnemyLineOfSightCheck = INT2NUM(FALSE);
    StackPushInteger(NUM2INT(bCreatureToEnemyLineOfSightCheck));
    VM_ExecuteCommand(402, 1);
    return Qnil;
}

static VALUE NWScript_ExploreAreaForPlayer(int argc, VALUE *argv, VALUE self)
{
    VALUE oArea, oPlayer, bExplored;
    if (argc < 2) {
        //TODO: Raise exception
        return Qnil;
    }
    oArea = argv[0];
    oPlayer = argv[1];
    if (argc > 2) bExplored = argv[2];
    else bExplored = INT2NUM(TRUE);
    StackPushInteger(NUM2INT(bExplored));
    StackPushObject(NUM2UINT(oPlayer));
    StackPushObject(NUM2UINT(oArea));
    VM_ExecuteCommand(403, 3);
    return Qnil;
}

static VALUE NWScript_ActionEquipMostEffectiveArmor(VALUE self)
{
    VM_ExecuteCommand(404, 0);
    return Qnil;
}

static VALUE NWScript_GetIsDay(VALUE self)
{
    VM_ExecuteCommand(405, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetIsNight(VALUE self)
{
    VM_ExecuteCommand(406, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetIsDawn(VALUE self)
{
    VM_ExecuteCommand(407, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetIsDusk(VALUE self)
{
    VM_ExecuteCommand(408, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetIsEncounterCreature(int argc, VALUE *argv, VALUE self)
{
    VALUE oCreature;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oCreature = argv[0];
    else oCreature = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(409, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastPlayerDying(VALUE self)
{
    VM_ExecuteCommand(410, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetStartingLocation(VALUE self)
{
    VM_ExecuteCommand(411, 0);
    CScriptLocation *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_LOCATION, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cLocationClass, 0, free, pRetVal);
}

static VALUE NWScript_ChangeToStandardFaction(VALUE self, VALUE oCreatureToChange, VALUE nStandardFaction)
{
    StackPushInteger(NUM2INT(nStandardFaction));
    StackPushObject(NUM2UINT(oCreatureToChange));
    VM_ExecuteCommand(412, 2);
    return Qnil;
}

static VALUE NWScript_SoundObjectPlay(VALUE self, VALUE oSound)
{
    StackPushObject(NUM2UINT(oSound));
    VM_ExecuteCommand(413, 1);
    return Qnil;
}

static VALUE NWScript_SoundObjectStop(VALUE self, VALUE oSound)
{
    StackPushObject(NUM2UINT(oSound));
    VM_ExecuteCommand(414, 1);
    return Qnil;
}

static VALUE NWScript_SoundObjectSetVolume(VALUE self, VALUE oSound, VALUE nVolume)
{
    StackPushInteger(NUM2INT(nVolume));
    StackPushObject(NUM2UINT(oSound));
    VM_ExecuteCommand(415, 2);
    return Qnil;
}

static VALUE NWScript_SoundObjectSetPosition(VALUE self, VALUE oSound, VALUE vPosition)
{
    Vector *vPosition_ptr;
    Data_Get_Struct(vPosition, Vector, vPosition_ptr);
    StackPushVector(*vPosition_ptr);
    StackPushObject(NUM2UINT(oSound));
    VM_ExecuteCommand(416, 2);
    return Qnil;
}

static VALUE NWScript_SpeakOneLinerConversation(int argc, VALUE *argv, VALUE self)
{
    VALUE sDialogResRef, oTokenTarget;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) sDialogResRef = argv[0];
    else sDialogResRef = rb_str_new2("");
    if (argc > 1) oTokenTarget = argv[1];
    else oTokenTarget = INT2NUM(OBJECT_TYPE_INVALID);
    StackPushObject(NUM2UINT(oTokenTarget));
    StackPushString(StringValueCStr(sDialogResRef));
    VM_ExecuteCommand(417, 2);
    return Qnil;
}

static VALUE NWScript_GetGold(int argc, VALUE *argv, VALUE self)
{
    VALUE oTarget;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oTarget = argv[0];
    else oTarget = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oTarget));
    VM_ExecuteCommand(418, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastRespawnButtonPresser(VALUE self)
{
    VM_ExecuteCommand(419, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetIsDM(VALUE self, VALUE oCreature)
{
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(420, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_PlayVoiceChat(int argc, VALUE *argv, VALUE self)
{
    VALUE nVoiceChatID, oTarget;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    nVoiceChatID = argv[0];
    if (argc > 1) oTarget = argv[1];
    else oTarget = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oTarget));
    StackPushInteger(NUM2INT(nVoiceChatID));
    VM_ExecuteCommand(421, 2);
    return Qnil;
}

static VALUE NWScript_GetIsWeaponEffective(int argc, VALUE *argv, VALUE self)
{
    VALUE oVersus, bOffHand;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oVersus = argv[0];
    else oVersus = INT2NUM(OBJECT_INVALID);
    if (argc > 1) bOffHand = argv[1];
    else bOffHand = INT2NUM(FALSE);
    StackPushInteger(NUM2INT(bOffHand));
    StackPushObject(NUM2UINT(oVersus));
    VM_ExecuteCommand(422, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastSpellHarmful(VALUE self)
{
    VM_ExecuteCommand(423, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_EventActivateItem(int argc, VALUE *argv, VALUE self)
{
    VALUE oItem, lTarget, oTarget;
    if (argc < 2) {
        //TODO: Raise exception
        return Qnil;
    }
    oItem = argv[0];
    lTarget = argv[1];
    if (argc > 2) oTarget = argv[2];
    else oTarget = INT2NUM(OBJECT_INVALID);
    StackPushObject(NUM2UINT(oTarget));
    CScriptLocation *lTarget_ptr;
    Data_Get_Struct(lTarget, CScriptLocation, lTarget_ptr);
    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lTarget_ptr);
    StackPushObject(NUM2UINT(oItem));
    VM_ExecuteCommand(424, 3);
//ERROR: Undefined variable type: event
    return Qnil;
}

static VALUE NWScript_MusicBackgroundPlay(VALUE self, VALUE oArea)
{
    StackPushObject(NUM2UINT(oArea));
    VM_ExecuteCommand(425, 1);
    return Qnil;
}

static VALUE NWScript_MusicBackgroundStop(VALUE self, VALUE oArea)
{
    StackPushObject(NUM2UINT(oArea));
    VM_ExecuteCommand(426, 1);
    return Qnil;
}

static VALUE NWScript_MusicBackgroundSetDelay(VALUE self, VALUE oArea, VALUE nDelay)
{
    StackPushInteger(NUM2INT(nDelay));
    StackPushObject(NUM2UINT(oArea));
    VM_ExecuteCommand(427, 2);
    return Qnil;
}

static VALUE NWScript_MusicBackgroundChangeDay(VALUE self, VALUE oArea, VALUE nTrack)
{
    StackPushInteger(NUM2INT(nTrack));
    StackPushObject(NUM2UINT(oArea));
    VM_ExecuteCommand(428, 2);
    return Qnil;
}

static VALUE NWScript_MusicBackgroundChangeNight(VALUE self, VALUE oArea, VALUE nTrack)
{
    StackPushInteger(NUM2INT(nTrack));
    StackPushObject(NUM2UINT(oArea));
    VM_ExecuteCommand(429, 2);
    return Qnil;
}

static VALUE NWScript_MusicBattlePlay(VALUE self, VALUE oArea)
{
    StackPushObject(NUM2UINT(oArea));
    VM_ExecuteCommand(430, 1);
    return Qnil;
}

static VALUE NWScript_MusicBattleStop(VALUE self, VALUE oArea)
{
    StackPushObject(NUM2UINT(oArea));
    VM_ExecuteCommand(431, 1);
    return Qnil;
}

static VALUE NWScript_MusicBattleChange(VALUE self, VALUE oArea, VALUE nTrack)
{
    StackPushInteger(NUM2INT(nTrack));
    StackPushObject(NUM2UINT(oArea));
    VM_ExecuteCommand(432, 2);
    return Qnil;
}

static VALUE NWScript_AmbientSoundPlay(VALUE self, VALUE oArea)
{
    StackPushObject(NUM2UINT(oArea));
    VM_ExecuteCommand(433, 1);
    return Qnil;
}

static VALUE NWScript_AmbientSoundStop(VALUE self, VALUE oArea)
{
    StackPushObject(NUM2UINT(oArea));
    VM_ExecuteCommand(434, 1);
    return Qnil;
}

static VALUE NWScript_AmbientSoundChangeDay(VALUE self, VALUE oArea, VALUE nTrack)
{
    StackPushInteger(NUM2INT(nTrack));
    StackPushObject(NUM2UINT(oArea));
    VM_ExecuteCommand(435, 2);
    return Qnil;
}

static VALUE NWScript_AmbientSoundChangeNight(VALUE self, VALUE oArea, VALUE nTrack)
{
    StackPushInteger(NUM2INT(nTrack));
    StackPushObject(NUM2UINT(oArea));
    VM_ExecuteCommand(436, 2);
    return Qnil;
}

static VALUE NWScript_GetLastKiller(VALUE self)
{
    VM_ExecuteCommand(437, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetSpellCastItem(VALUE self)
{
    VM_ExecuteCommand(438, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetItemActivated(VALUE self)
{
    VM_ExecuteCommand(439, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetItemActivator(VALUE self)
{
    VM_ExecuteCommand(440, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetItemActivatedTargetLocation(VALUE self)
{
    VM_ExecuteCommand(441, 0);
    CScriptLocation *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_LOCATION, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cLocationClass, 0, free, pRetVal);
}

static VALUE NWScript_GetItemActivatedTarget(VALUE self)
{
    VM_ExecuteCommand(442, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetIsOpen(VALUE self, VALUE oObject)
{
    StackPushObject(NUM2UINT(oObject));
    VM_ExecuteCommand(443, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_TakeGoldFromCreature(int argc, VALUE *argv, VALUE self)
{
    VALUE nAmount, oCreatureToTakeFrom, bDestroy;
    if (argc < 2) {
        //TODO: Raise exception
        return Qnil;
    }
    nAmount = argv[0];
    oCreatureToTakeFrom = argv[1];
    if (argc > 2) bDestroy = argv[2];
    else bDestroy = INT2NUM(FALSE);
    StackPushInteger(NUM2INT(bDestroy));
    StackPushObject(NUM2UINT(oCreatureToTakeFrom));
    StackPushInteger(NUM2INT(nAmount));
    VM_ExecuteCommand(444, 3);
    return Qnil;
}

static VALUE NWScript_IsInConversation(VALUE self, VALUE oObject)
{
    StackPushObject(NUM2UINT(oObject));
    VM_ExecuteCommand(445, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_EffectAbilityDecrease(VALUE self, VALUE nAbility, VALUE nModifyBy)
{
    StackPushInteger(NUM2INT(nModifyBy));
    StackPushInteger(NUM2INT(nAbility));
    VM_ExecuteCommand(446, 2);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_EffectAttackDecrease(int argc, VALUE *argv, VALUE self)
{
    VALUE nPenalty, nModifierType;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    nPenalty = argv[0];
    if (argc > 1) nModifierType = argv[1];
    else nModifierType = INT2NUM(ATTACK_BONUS_MISC);
    StackPushInteger(NUM2INT(nModifierType));
    StackPushInteger(NUM2INT(nPenalty));
    VM_ExecuteCommand(447, 2);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_EffectDamageDecrease(int argc, VALUE *argv, VALUE self)
{
    VALUE nPenalty, nDamageType;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    nPenalty = argv[0];
    if (argc > 1) nDamageType = argv[1];
    else nDamageType = INT2NUM(DAMAGE_TYPE_MAGICAL);
    StackPushInteger(NUM2INT(nDamageType));
    StackPushInteger(NUM2INT(nPenalty));
    VM_ExecuteCommand(448, 2);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_EffectDamageImmunityDecrease(VALUE self, VALUE nDamageType, VALUE nPercentImmunity)
{
    StackPushInteger(NUM2INT(nPercentImmunity));
    StackPushInteger(NUM2INT(nDamageType));
    VM_ExecuteCommand(449, 2);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_EffectACDecrease(int argc, VALUE *argv, VALUE self)
{
    VALUE nValue, nModifyType, nDamageType;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    nValue = argv[0];
    if (argc > 1) nModifyType = argv[1];
    else nModifyType = INT2NUM(AC_DODGE_BONUS);
    if (argc > 2) nDamageType = argv[2];
    else nDamageType = INT2NUM(AC_VS_DAMAGE_TYPE_ALL);
    StackPushInteger(NUM2INT(nDamageType));
    StackPushInteger(NUM2INT(nModifyType));
    StackPushInteger(NUM2INT(nValue));
    VM_ExecuteCommand(450, 3);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_EffectMovementSpeedDecrease(VALUE self, VALUE nPercentChange)
{
    StackPushInteger(NUM2INT(nPercentChange));
    VM_ExecuteCommand(451, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_EffectSavingThrowDecrease(int argc, VALUE *argv, VALUE self)
{
    VALUE nSave, nValue, nSaveType;
    if (argc < 2) {
        //TODO: Raise exception
        return Qnil;
    }
    nSave = argv[0];
    nValue = argv[1];
    if (argc > 2) nSaveType = argv[2];
    else nSaveType = INT2NUM(SAVING_THROW_TYPE_ALL);
    StackPushInteger(NUM2INT(nSaveType));
    StackPushInteger(NUM2INT(nValue));
    StackPushInteger(NUM2INT(nSave));
    VM_ExecuteCommand(452, 3);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_EffectSkillDecrease(VALUE self, VALUE nSkill, VALUE nValue)
{
    StackPushInteger(NUM2INT(nValue));
    StackPushInteger(NUM2INT(nSkill));
    VM_ExecuteCommand(453, 2);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_EffectSpellResistanceDecrease(VALUE self, VALUE nValue)
{
    StackPushInteger(NUM2INT(nValue));
    VM_ExecuteCommand(454, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_GetPlotFlag(int argc, VALUE *argv, VALUE self)
{
    VALUE oTarget;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oTarget = argv[0];
    else oTarget = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oTarget));
    VM_ExecuteCommand(455, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_SetPlotFlag(VALUE self, VALUE oTarget, VALUE nPlotFlag)
{
    StackPushInteger(NUM2INT(nPlotFlag));
    StackPushObject(NUM2UINT(oTarget));
    VM_ExecuteCommand(456, 2);
    return Qnil;
}

static VALUE NWScript_EffectInvisibility(VALUE self, VALUE nInvisibilityType)
{
    StackPushInteger(NUM2INT(nInvisibilityType));
    VM_ExecuteCommand(457, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_EffectConcealment(int argc, VALUE *argv, VALUE self)
{
    VALUE nPercentage, nMissType;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    nPercentage = argv[0];
    if (argc > 1) nMissType = argv[1];
    else nMissType = INT2NUM(MISS_CHANCE_TYPE_NORMAL);
    StackPushInteger(NUM2INT(nMissType));
    StackPushInteger(NUM2INT(nPercentage));
    VM_ExecuteCommand(458, 2);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_EffectDarkness(VALUE self)
{
    VM_ExecuteCommand(459, 0);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_EffectDispelMagicAll(int argc, VALUE *argv, VALUE self)
{
    VALUE nCasterLevel;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) nCasterLevel = argv[0];
    else nCasterLevel = INT2NUM(USE_CREATURE_LEVEL);
    StackPushInteger(NUM2INT(nCasterLevel));
    VM_ExecuteCommand(460, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_EffectUltravision(VALUE self)
{
    VM_ExecuteCommand(461, 0);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_EffectNegativeLevel(int argc, VALUE *argv, VALUE self)
{
    VALUE nNumLevels, bHPBonus;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    nNumLevels = argv[0];
    if (argc > 1) bHPBonus = argv[1];
    else bHPBonus = INT2NUM(FALSE);
    StackPushInteger(NUM2INT(bHPBonus));
    StackPushInteger(NUM2INT(nNumLevels));
    VM_ExecuteCommand(462, 2);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_EffectPolymorph(int argc, VALUE *argv, VALUE self)
{
    VALUE nPolymorphSelection, nLocked;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    nPolymorphSelection = argv[0];
    if (argc > 1) nLocked = argv[1];
    else nLocked = INT2NUM(FALSE);
    StackPushInteger(NUM2INT(nLocked));
    StackPushInteger(NUM2INT(nPolymorphSelection));
    VM_ExecuteCommand(463, 2);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_EffectSanctuary(VALUE self, VALUE nDifficultyClass)
{
    StackPushInteger(NUM2INT(nDifficultyClass));
    VM_ExecuteCommand(464, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_EffectTrueSeeing(VALUE self)
{
    VM_ExecuteCommand(465, 0);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_EffectSeeInvisible(VALUE self)
{
    VM_ExecuteCommand(466, 0);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_EffectTimeStop(VALUE self)
{
    VM_ExecuteCommand(467, 0);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_EffectBlindness(VALUE self)
{
    VM_ExecuteCommand(468, 0);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_GetIsReactionTypeFriendly(int argc, VALUE *argv, VALUE self)
{
    VALUE oTarget, oSource;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    oTarget = argv[0];
    if (argc > 1) oSource = argv[1];
    else oSource = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oSource));
    StackPushObject(NUM2UINT(oTarget));
    VM_ExecuteCommand(469, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetIsReactionTypeNeutral(int argc, VALUE *argv, VALUE self)
{
    VALUE oTarget, oSource;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    oTarget = argv[0];
    if (argc > 1) oSource = argv[1];
    else oSource = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oSource));
    StackPushObject(NUM2UINT(oTarget));
    VM_ExecuteCommand(470, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetIsReactionTypeHostile(int argc, VALUE *argv, VALUE self)
{
    VALUE oTarget, oSource;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    oTarget = argv[0];
    if (argc > 1) oSource = argv[1];
    else oSource = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oSource));
    StackPushObject(NUM2UINT(oTarget));
    VM_ExecuteCommand(471, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_EffectSpellLevelAbsorption(int argc, VALUE *argv, VALUE self)
{
    VALUE nMaxSpellLevelAbsorbed, nTotalSpellLevelsAbsorbed, nSpellSchool;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    nMaxSpellLevelAbsorbed = argv[0];
    if (argc > 1) nTotalSpellLevelsAbsorbed = argv[1];
    else nTotalSpellLevelsAbsorbed = INT2NUM(0);
    if (argc > 2) nSpellSchool = argv[2];
    else nSpellSchool = INT2NUM(SPELL_SCHOOL_GENERAL);
    StackPushInteger(NUM2INT(nSpellSchool));
    StackPushInteger(NUM2INT(nTotalSpellLevelsAbsorbed));
    StackPushInteger(NUM2INT(nMaxSpellLevelAbsorbed));
    VM_ExecuteCommand(472, 3);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_EffectDispelMagicBest(int argc, VALUE *argv, VALUE self)
{
    VALUE nCasterLevel;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) nCasterLevel = argv[0];
    else nCasterLevel = INT2NUM(USE_CREATURE_LEVEL);
    StackPushInteger(NUM2INT(nCasterLevel));
    VM_ExecuteCommand(473, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_ActivatePortal(int argc, VALUE *argv, VALUE self)
{
    VALUE oTarget, sIPaddress, sPassword, sWaypointTag, bSeemless;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    oTarget = argv[0];
    if (argc > 1) sIPaddress = argv[1];
    else sIPaddress = rb_str_new2("");
    if (argc > 2) sPassword = argv[2];
    else sPassword = rb_str_new2("");
    if (argc > 3) sWaypointTag = argv[3];
    else sWaypointTag = rb_str_new2("");
    if (argc > 4) bSeemless = argv[4];
    else bSeemless = INT2NUM(FALSE);
    StackPushInteger(NUM2INT(bSeemless));
    StackPushString(StringValueCStr(sWaypointTag));
    StackPushString(StringValueCStr(sPassword));
    StackPushString(StringValueCStr(sIPaddress));
    StackPushObject(NUM2UINT(oTarget));
    VM_ExecuteCommand(474, 5);
    return Qnil;
}

static VALUE NWScript_GetNumStackedItems(VALUE self, VALUE oItem)
{
    StackPushObject(NUM2UINT(oItem));
    VM_ExecuteCommand(475, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_SurrenderToEnemies(VALUE self)
{
    VM_ExecuteCommand(476, 0);
    return Qnil;
}

static VALUE NWScript_EffectMissChance(int argc, VALUE *argv, VALUE self)
{
    VALUE nPercentage, nMissChanceType;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    nPercentage = argv[0];
    if (argc > 1) nMissChanceType = argv[1];
    else nMissChanceType = INT2NUM(MISS_CHANCE_TYPE_NORMAL);
    StackPushInteger(NUM2INT(nMissChanceType));
    StackPushInteger(NUM2INT(nPercentage));
    VM_ExecuteCommand(477, 2);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_GetTurnResistanceHD(int argc, VALUE *argv, VALUE self)
{
    VALUE oUndead;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oUndead = argv[0];
    else oUndead = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oUndead));
    VM_ExecuteCommand(478, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetCreatureSize(VALUE self, VALUE oCreature)
{
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(479, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_EffectDisappearAppear(int argc, VALUE *argv, VALUE self)
{
    VALUE lLocation, nAnimation;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    lLocation = argv[0];
    if (argc > 1) nAnimation = argv[1];
    else nAnimation = INT2NUM(1);
    StackPushInteger(NUM2INT(nAnimation));
    CScriptLocation *lLocation_ptr;
    Data_Get_Struct(lLocation, CScriptLocation, lLocation_ptr);
    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lLocation_ptr);
    VM_ExecuteCommand(480, 2);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_EffectDisappear(int argc, VALUE *argv, VALUE self)
{
    VALUE nAnimation;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) nAnimation = argv[0];
    else nAnimation = INT2NUM(1);
    StackPushInteger(NUM2INT(nAnimation));
    VM_ExecuteCommand(481, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_EffectAppear(int argc, VALUE *argv, VALUE self)
{
    VALUE nAnimation;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) nAnimation = argv[0];
    else nAnimation = INT2NUM(1);
    StackPushInteger(NUM2INT(nAnimation));
    VM_ExecuteCommand(482, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_ActionUnlockObject(VALUE self, VALUE oTarget)
{
    StackPushObject(NUM2UINT(oTarget));
    VM_ExecuteCommand(483, 1);
    return Qnil;
}

static VALUE NWScript_ActionLockObject(VALUE self, VALUE oTarget)
{
    StackPushObject(NUM2UINT(oTarget));
    VM_ExecuteCommand(484, 1);
    return Qnil;
}

static VALUE NWScript_EffectModifyAttacks(VALUE self, VALUE nAttacks)
{
    StackPushInteger(NUM2INT(nAttacks));
    VM_ExecuteCommand(485, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_GetLastTrapDetected(int argc, VALUE *argv, VALUE self)
{
    VALUE oTarget;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oTarget = argv[0];
    else oTarget = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oTarget));
    VM_ExecuteCommand(486, 1);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_EffectDamageShield(VALUE self, VALUE nDamageAmount, VALUE nRandomAmount, VALUE nDamageType)
{
    StackPushInteger(NUM2INT(nDamageType));
    StackPushInteger(NUM2INT(nRandomAmount));
    StackPushInteger(NUM2INT(nDamageAmount));
    VM_ExecuteCommand(487, 3);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_GetNearestTrapToObject(int argc, VALUE *argv, VALUE self)
{
    VALUE oTarget, nTrapDetected;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oTarget = argv[0];
    else oTarget = INT2NUM(OBJECT_SELF);
    if (argc > 1) nTrapDetected = argv[1];
    else nTrapDetected = INT2NUM(TRUE);
    StackPushInteger(NUM2INT(nTrapDetected));
    StackPushObject(NUM2UINT(oTarget));
    VM_ExecuteCommand(488, 2);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetDeity(VALUE self, VALUE oCreature)
{
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(489, 1);
    char *sRetVal;
    StackPopString(&sRetVal);
    return rb_str_new2(sRetVal);
}

static VALUE NWScript_GetSubRace(VALUE self, VALUE oTarget)
{
    StackPushObject(NUM2UINT(oTarget));
    VM_ExecuteCommand(490, 1);
    char *sRetVal;
    StackPopString(&sRetVal);
    return rb_str_new2(sRetVal);
}

static VALUE NWScript_GetFortitudeSavingThrow(VALUE self, VALUE oTarget)
{
    StackPushObject(NUM2UINT(oTarget));
    VM_ExecuteCommand(491, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetWillSavingThrow(VALUE self, VALUE oTarget)
{
    StackPushObject(NUM2UINT(oTarget));
    VM_ExecuteCommand(492, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetReflexSavingThrow(VALUE self, VALUE oTarget)
{
    StackPushObject(NUM2UINT(oTarget));
    VM_ExecuteCommand(493, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetChallengeRating(VALUE self, VALUE oCreature)
{
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(494, 1);
    float fRetVal;
    StackPopFloat(&fRetVal);
    return rb_float_new(fRetVal);
}

static VALUE NWScript_GetAge(VALUE self, VALUE oCreature)
{
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(495, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetMovementRate(VALUE self, VALUE oCreature)
{
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(496, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetFamiliarCreatureType(VALUE self, VALUE oCreature)
{
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(497, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetAnimalCompanionCreatureType(VALUE self, VALUE oCreature)
{
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(498, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetFamiliarName(VALUE self, VALUE oCreature)
{
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(499, 1);
    char *sRetVal;
    StackPopString(&sRetVal);
    return rb_str_new2(sRetVal);
}

static VALUE NWScript_GetAnimalCompanionName(VALUE self, VALUE oTarget)
{
    StackPushObject(NUM2UINT(oTarget));
    VM_ExecuteCommand(500, 1);
    char *sRetVal;
    StackPopString(&sRetVal);
    return rb_str_new2(sRetVal);
}

static VALUE NWScript_ActionCastFakeSpellAtObject(int argc, VALUE *argv, VALUE self)
{
    VALUE nSpell, oTarget, nProjectilePathType;
    if (argc < 2) {
        //TODO: Raise exception
        return Qnil;
    }
    nSpell = argv[0];
    oTarget = argv[1];
    if (argc > 2) nProjectilePathType = argv[2];
    else nProjectilePathType = INT2NUM(PROJECTILE_PATH_TYPE_DEFAULT);
    StackPushInteger(NUM2INT(nProjectilePathType));
    StackPushObject(NUM2UINT(oTarget));
    StackPushInteger(NUM2INT(nSpell));
    VM_ExecuteCommand(501, 3);
    return Qnil;
}

static VALUE NWScript_ActionCastFakeSpellAtLocation(int argc, VALUE *argv, VALUE self)
{
    VALUE nSpell, lTarget, nProjectilePathType;
    if (argc < 2) {
        //TODO: Raise exception
        return Qnil;
    }
    nSpell = argv[0];
    lTarget = argv[1];
    if (argc > 2) nProjectilePathType = argv[2];
    else nProjectilePathType = INT2NUM(PROJECTILE_PATH_TYPE_DEFAULT);
    StackPushInteger(NUM2INT(nProjectilePathType));
    CScriptLocation *lTarget_ptr;
    Data_Get_Struct(lTarget, CScriptLocation, lTarget_ptr);
    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lTarget_ptr);
    StackPushInteger(NUM2INT(nSpell));
    VM_ExecuteCommand(502, 3);
    return Qnil;
}

static VALUE NWScript_RemoveSummonedAssociate(int argc, VALUE *argv, VALUE self)
{
    VALUE oMaster, oAssociate;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    oMaster = argv[0];
    if (argc > 1) oAssociate = argv[1];
    else oAssociate = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oAssociate));
    StackPushObject(NUM2UINT(oMaster));
    VM_ExecuteCommand(503, 2);
    return Qnil;
}

static VALUE NWScript_SetCameraMode(VALUE self, VALUE oPlayer, VALUE nCameraMode)
{
    StackPushInteger(NUM2INT(nCameraMode));
    StackPushObject(NUM2UINT(oPlayer));
    VM_ExecuteCommand(504, 2);
    return Qnil;
}

static VALUE NWScript_GetIsResting(int argc, VALUE *argv, VALUE self)
{
    VALUE oCreature;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oCreature = argv[0];
    else oCreature = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(505, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastPCRested(VALUE self)
{
    VM_ExecuteCommand(506, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_SetWeather(VALUE self, VALUE oTarget, VALUE nWeather)
{
    StackPushInteger(NUM2INT(nWeather));
    StackPushObject(NUM2UINT(oTarget));
    VM_ExecuteCommand(507, 2);
    return Qnil;
}

static VALUE NWScript_GetLastRestEventType(VALUE self)
{
    VM_ExecuteCommand(508, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_StartNewModule(VALUE self, VALUE sModuleName)
{
    StackPushString(StringValueCStr(sModuleName));
    VM_ExecuteCommand(509, 1);
    return Qnil;
}

static VALUE NWScript_EffectSwarm(int argc, VALUE *argv, VALUE self)
{
    VALUE nLooping, sCreatureTemplate1, sCreatureTemplate2, sCreatureTemplate3, sCreatureTemplate4;
    if (argc < 2) {
        //TODO: Raise exception
        return Qnil;
    }
    nLooping = argv[0];
    sCreatureTemplate1 = argv[1];
    if (argc > 2) sCreatureTemplate2 = argv[2];
    else sCreatureTemplate2 = rb_str_new2("");
    if (argc > 3) sCreatureTemplate3 = argv[3];
    else sCreatureTemplate3 = rb_str_new2("");
    if (argc > 4) sCreatureTemplate4 = argv[4];
    else sCreatureTemplate4 = rb_str_new2("");
    StackPushString(StringValueCStr(sCreatureTemplate4));
    StackPushString(StringValueCStr(sCreatureTemplate3));
    StackPushString(StringValueCStr(sCreatureTemplate2));
    StackPushString(StringValueCStr(sCreatureTemplate1));
    StackPushInteger(NUM2INT(nLooping));
    VM_ExecuteCommand(510, 5);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_GetWeaponRanged(VALUE self, VALUE oItem)
{
    StackPushObject(NUM2UINT(oItem));
    VM_ExecuteCommand(511, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_DoSinglePlayerAutoSave(VALUE self)
{
    VM_ExecuteCommand(512, 0);
    return Qnil;
}

static VALUE NWScript_GetGameDifficulty(VALUE self)
{
    VM_ExecuteCommand(513, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_SetTileMainLightColor(VALUE self, VALUE lTileLocation, VALUE nMainLight1Color, VALUE nMainLight2Color)
{
    StackPushInteger(NUM2INT(nMainLight2Color));
    StackPushInteger(NUM2INT(nMainLight1Color));
    CScriptLocation *lTileLocation_ptr;
    Data_Get_Struct(lTileLocation, CScriptLocation, lTileLocation_ptr);
    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lTileLocation_ptr);
    VM_ExecuteCommand(514, 3);
    return Qnil;
}

static VALUE NWScript_SetTileSourceLightColor(VALUE self, VALUE lTileLocation, VALUE nSourceLight1Color, VALUE nSourceLight2Color)
{
    StackPushInteger(NUM2INT(nSourceLight2Color));
    StackPushInteger(NUM2INT(nSourceLight1Color));
    CScriptLocation *lTileLocation_ptr;
    Data_Get_Struct(lTileLocation, CScriptLocation, lTileLocation_ptr);
    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lTileLocation_ptr);
    VM_ExecuteCommand(515, 3);
    return Qnil;
}

static VALUE NWScript_RecomputeStaticLighting(VALUE self, VALUE oArea)
{
    StackPushObject(NUM2UINT(oArea));
    VM_ExecuteCommand(516, 1);
    return Qnil;
}

static VALUE NWScript_GetTileMainLight1Color(VALUE self, VALUE lTile)
{
    CScriptLocation *lTile_ptr;
    Data_Get_Struct(lTile, CScriptLocation, lTile_ptr);
    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lTile_ptr);
    VM_ExecuteCommand(517, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetTileMainLight2Color(VALUE self, VALUE lTile)
{
    CScriptLocation *lTile_ptr;
    Data_Get_Struct(lTile, CScriptLocation, lTile_ptr);
    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lTile_ptr);
    VM_ExecuteCommand(518, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetTileSourceLight1Color(VALUE self, VALUE lTile)
{
    CScriptLocation *lTile_ptr;
    Data_Get_Struct(lTile, CScriptLocation, lTile_ptr);
    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lTile_ptr);
    VM_ExecuteCommand(519, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetTileSourceLight2Color(VALUE self, VALUE lTile)
{
    CScriptLocation *lTile_ptr;
    Data_Get_Struct(lTile, CScriptLocation, lTile_ptr);
    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lTile_ptr);
    VM_ExecuteCommand(520, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_SetPanelButtonFlash(VALUE self, VALUE oPlayer, VALUE nButton, VALUE nEnableFlash)
{
    StackPushInteger(NUM2INT(nEnableFlash));
    StackPushInteger(NUM2INT(nButton));
    StackPushObject(NUM2UINT(oPlayer));
    VM_ExecuteCommand(521, 3);
    return Qnil;
}

static VALUE NWScript_GetCurrentAction(int argc, VALUE *argv, VALUE self)
{
    VALUE oObject;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oObject = argv[0];
    else oObject = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oObject));
    VM_ExecuteCommand(522, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_SetStandardFactionReputation(int argc, VALUE *argv, VALUE self)
{
    VALUE nStandardFaction, nNewReputation, oCreature;
    if (argc < 2) {
        //TODO: Raise exception
        return Qnil;
    }
    nStandardFaction = argv[0];
    nNewReputation = argv[1];
    if (argc > 2) oCreature = argv[2];
    else oCreature = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oCreature));
    StackPushInteger(NUM2INT(nNewReputation));
    StackPushInteger(NUM2INT(nStandardFaction));
    VM_ExecuteCommand(523, 3);
    return Qnil;
}

static VALUE NWScript_GetStandardFactionReputation(int argc, VALUE *argv, VALUE self)
{
    VALUE nStandardFaction, oCreature;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    nStandardFaction = argv[0];
    if (argc > 1) oCreature = argv[1];
    else oCreature = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oCreature));
    StackPushInteger(NUM2INT(nStandardFaction));
    VM_ExecuteCommand(524, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_FloatingTextStrRefOnCreature(int argc, VALUE *argv, VALUE self)
{
    VALUE nStrRefToDisplay, oCreatureToFloatAbove, bBroadcastToFaction;
    if (argc < 2) {
        //TODO: Raise exception
        return Qnil;
    }
    nStrRefToDisplay = argv[0];
    oCreatureToFloatAbove = argv[1];
    if (argc > 2) bBroadcastToFaction = argv[2];
    else bBroadcastToFaction = INT2NUM(TRUE);
    StackPushInteger(NUM2INT(bBroadcastToFaction));
    StackPushObject(NUM2UINT(oCreatureToFloatAbove));
    StackPushInteger(NUM2INT(nStrRefToDisplay));
    VM_ExecuteCommand(525, 3);
    return Qnil;
}

static VALUE NWScript_FloatingTextStringOnCreature(int argc, VALUE *argv, VALUE self)
{
    VALUE sStringToDisplay, oCreatureToFloatAbove, bBroadcastToFaction;
    if (argc < 2) {
        //TODO: Raise exception
        return Qnil;
    }
    sStringToDisplay = argv[0];
    oCreatureToFloatAbove = argv[1];
    if (argc > 2) bBroadcastToFaction = argv[2];
    else bBroadcastToFaction = INT2NUM(TRUE);
    StackPushInteger(NUM2INT(bBroadcastToFaction));
    StackPushObject(NUM2UINT(oCreatureToFloatAbove));
    StackPushString(StringValueCStr(sStringToDisplay));
    VM_ExecuteCommand(526, 3);
    return Qnil;
}

static VALUE NWScript_GetTrapDisarmable(VALUE self, VALUE oTrapObject)
{
    StackPushObject(NUM2UINT(oTrapObject));
    VM_ExecuteCommand(527, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetTrapDetectable(VALUE self, VALUE oTrapObject)
{
    StackPushObject(NUM2UINT(oTrapObject));
    VM_ExecuteCommand(528, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetTrapDetectedBy(VALUE self, VALUE oTrapObject, VALUE oCreature)
{
    StackPushObject(NUM2UINT(oCreature));
    StackPushObject(NUM2UINT(oTrapObject));
    VM_ExecuteCommand(529, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetTrapFlagged(VALUE self, VALUE oTrapObject)
{
    StackPushObject(NUM2UINT(oTrapObject));
    VM_ExecuteCommand(530, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetTrapBaseType(VALUE self, VALUE oTrapObject)
{
    StackPushObject(NUM2UINT(oTrapObject));
    VM_ExecuteCommand(531, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetTrapOneShot(VALUE self, VALUE oTrapObject)
{
    StackPushObject(NUM2UINT(oTrapObject));
    VM_ExecuteCommand(532, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetTrapCreator(VALUE self, VALUE oTrapObject)
{
    StackPushObject(NUM2UINT(oTrapObject));
    VM_ExecuteCommand(533, 1);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetTrapKeyTag(VALUE self, VALUE oTrapObject)
{
    StackPushObject(NUM2UINT(oTrapObject));
    VM_ExecuteCommand(534, 1);
    char *sRetVal;
    StackPopString(&sRetVal);
    return rb_str_new2(sRetVal);
}

static VALUE NWScript_GetTrapDisarmDC(VALUE self, VALUE oTrapObject)
{
    StackPushObject(NUM2UINT(oTrapObject));
    VM_ExecuteCommand(535, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetTrapDetectDC(VALUE self, VALUE oTrapObject)
{
    StackPushObject(NUM2UINT(oTrapObject));
    VM_ExecuteCommand(536, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLockKeyRequired(VALUE self, VALUE oObject)
{
    StackPushObject(NUM2UINT(oObject));
    VM_ExecuteCommand(537, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLockKeyTag(VALUE self, VALUE oObject)
{
    StackPushObject(NUM2UINT(oObject));
    VM_ExecuteCommand(538, 1);
    char *sRetVal;
    StackPopString(&sRetVal);
    return rb_str_new2(sRetVal);
}

static VALUE NWScript_GetLockLockable(VALUE self, VALUE oObject)
{
    StackPushObject(NUM2UINT(oObject));
    VM_ExecuteCommand(539, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLockUnlockDC(VALUE self, VALUE oObject)
{
    StackPushObject(NUM2UINT(oObject));
    VM_ExecuteCommand(540, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLockLockDC(VALUE self, VALUE oObject)
{
    StackPushObject(NUM2UINT(oObject));
    VM_ExecuteCommand(541, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetPCLevellingUp(VALUE self)
{
    VM_ExecuteCommand(542, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetHasFeatEffect(int argc, VALUE *argv, VALUE self)
{
    VALUE nFeat, oObject;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    nFeat = argv[0];
    if (argc > 1) oObject = argv[1];
    else oObject = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oObject));
    StackPushInteger(NUM2INT(nFeat));
    VM_ExecuteCommand(543, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_SetPlaceableIllumination(int argc, VALUE *argv, VALUE self)
{
    VALUE oPlaceable, bIlluminate;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oPlaceable = argv[0];
    else oPlaceable = INT2NUM(OBJECT_SELF);
    if (argc > 1) bIlluminate = argv[1];
    else bIlluminate = INT2NUM(TRUE);
    StackPushInteger(NUM2INT(bIlluminate));
    StackPushObject(NUM2UINT(oPlaceable));
    VM_ExecuteCommand(544, 2);
    return Qnil;
}

static VALUE NWScript_GetPlaceableIllumination(int argc, VALUE *argv, VALUE self)
{
    VALUE oPlaceable;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oPlaceable = argv[0];
    else oPlaceable = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oPlaceable));
    VM_ExecuteCommand(545, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetIsPlaceableObjectActionPossible(VALUE self, VALUE oPlaceable, VALUE nPlaceableAction)
{
    StackPushInteger(NUM2INT(nPlaceableAction));
    StackPushObject(NUM2UINT(oPlaceable));
    VM_ExecuteCommand(546, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_DoPlaceableObjectAction(VALUE self, VALUE oPlaceable, VALUE nPlaceableAction)
{
    StackPushInteger(NUM2INT(nPlaceableAction));
    StackPushObject(NUM2UINT(oPlaceable));
    VM_ExecuteCommand(547, 2);
    return Qnil;
}

static VALUE NWScript_GetFirstPC(VALUE self)
{
    VM_ExecuteCommand(548, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetNextPC(VALUE self)
{
    VM_ExecuteCommand(549, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_SetTrapDetectedBy(int argc, VALUE *argv, VALUE self)
{
    VALUE oTrap, oDetector, bDetected;
    if (argc < 2) {
        //TODO: Raise exception
        return Qnil;
    }
    oTrap = argv[0];
    oDetector = argv[1];
    if (argc > 2) bDetected = argv[2];
    else bDetected = INT2NUM(TRUE);
    StackPushInteger(NUM2INT(bDetected));
    StackPushObject(NUM2UINT(oDetector));
    StackPushObject(NUM2UINT(oTrap));
    VM_ExecuteCommand(550, 3);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetIsTrapped(VALUE self, VALUE oObject)
{
    StackPushObject(NUM2UINT(oObject));
    VM_ExecuteCommand(551, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_EffectTurnResistanceDecrease(VALUE self, VALUE nHitDice)
{
    StackPushInteger(NUM2INT(nHitDice));
    VM_ExecuteCommand(552, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_EffectTurnResistanceIncrease(VALUE self, VALUE nHitDice)
{
    StackPushInteger(NUM2INT(nHitDice));
    VM_ExecuteCommand(553, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_PopUpDeathGUIPanel(int argc, VALUE *argv, VALUE self)
{
    VALUE oPC, bRespawnButtonEnabled, bWaitForHelpButtonEnabled, nHelpStringReference, sHelpString;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    oPC = argv[0];
    if (argc > 1) bRespawnButtonEnabled = argv[1];
    else bRespawnButtonEnabled = INT2NUM(TRUE);
    if (argc > 2) bWaitForHelpButtonEnabled = argv[2];
    else bWaitForHelpButtonEnabled = INT2NUM(TRUE);
    if (argc > 3) nHelpStringReference = argv[3];
    else nHelpStringReference = INT2NUM(0);
    if (argc > 4) sHelpString = argv[4];
    else sHelpString = rb_str_new2("");
    StackPushString(StringValueCStr(sHelpString));
    StackPushInteger(NUM2INT(nHelpStringReference));
    StackPushInteger(NUM2INT(bWaitForHelpButtonEnabled));
    StackPushInteger(NUM2INT(bRespawnButtonEnabled));
    StackPushObject(NUM2UINT(oPC));
    VM_ExecuteCommand(554, 5);
    return Qnil;
}

static VALUE NWScript_SetTrapDisabled(VALUE self, VALUE oTrap)
{
    StackPushObject(NUM2UINT(oTrap));
    VM_ExecuteCommand(555, 1);
    return Qnil;
}

static VALUE NWScript_GetLastHostileActor(int argc, VALUE *argv, VALUE self)
{
    VALUE oVictim;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oVictim = argv[0];
    else oVictim = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oVictim));
    VM_ExecuteCommand(556, 1);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_ExportAllCharacters(VALUE self)
{
    VM_ExecuteCommand(557, 0);
    return Qnil;
}

static VALUE NWScript_MusicBackgroundGetDayTrack(VALUE self, VALUE oArea)
{
    StackPushObject(NUM2UINT(oArea));
    VM_ExecuteCommand(558, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_MusicBackgroundGetNightTrack(VALUE self, VALUE oArea)
{
    StackPushObject(NUM2UINT(oArea));
    VM_ExecuteCommand(559, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_WriteTimestampedLogEntry(VALUE self, VALUE sLogEntry)
{
    StackPushString(StringValueCStr(sLogEntry));
    VM_ExecuteCommand(560, 1);
    return Qnil;
}

static VALUE NWScript_GetModuleName(VALUE self)
{
    VM_ExecuteCommand(561, 0);
    char *sRetVal;
    StackPopString(&sRetVal);
    return rb_str_new2(sRetVal);
}

static VALUE NWScript_GetFactionLeader(VALUE self, VALUE oMemberOfFaction)
{
    StackPushObject(NUM2UINT(oMemberOfFaction));
    VM_ExecuteCommand(562, 1);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_SendMessageToAllDMs(VALUE self, VALUE szMessage)
{
    StackPushString(StringValueCStr(szMessage));
    VM_ExecuteCommand(563, 1);
    return Qnil;
}

static VALUE NWScript_EndGame(VALUE self, VALUE sEndMovie)
{
    StackPushString(StringValueCStr(sEndMovie));
    VM_ExecuteCommand(564, 1);
    return Qnil;
}

static VALUE NWScript_BootPC(VALUE self, VALUE oPlayer)
{
    StackPushObject(NUM2UINT(oPlayer));
    VM_ExecuteCommand(565, 1);
    return Qnil;
}

static VALUE NWScript_ActionCounterSpell(VALUE self, VALUE oCounterSpellTarget)
{
    StackPushObject(NUM2UINT(oCounterSpellTarget));
    VM_ExecuteCommand(566, 1);
    return Qnil;
}

static VALUE NWScript_AmbientSoundSetDayVolume(VALUE self, VALUE oArea, VALUE nVolume)
{
    StackPushInteger(NUM2INT(nVolume));
    StackPushObject(NUM2UINT(oArea));
    VM_ExecuteCommand(567, 2);
    return Qnil;
}

static VALUE NWScript_AmbientSoundSetNightVolume(VALUE self, VALUE oArea, VALUE nVolume)
{
    StackPushInteger(NUM2INT(nVolume));
    StackPushObject(NUM2UINT(oArea));
    VM_ExecuteCommand(568, 2);
    return Qnil;
}

static VALUE NWScript_MusicBackgroundGetBattleTrack(VALUE self, VALUE oArea)
{
    StackPushObject(NUM2UINT(oArea));
    VM_ExecuteCommand(569, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetHasInventory(VALUE self, VALUE oObject)
{
    StackPushObject(NUM2UINT(oObject));
    VM_ExecuteCommand(570, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetStrRefSoundDuration(VALUE self, VALUE nStrRef)
{
    StackPushInteger(NUM2INT(nStrRef));
    VM_ExecuteCommand(571, 1);
    float fRetVal;
    StackPopFloat(&fRetVal);
    return rb_float_new(fRetVal);
}

static VALUE NWScript_AddToParty(VALUE self, VALUE oPC, VALUE oPartyLeader)
{
    StackPushObject(NUM2UINT(oPartyLeader));
    StackPushObject(NUM2UINT(oPC));
    VM_ExecuteCommand(572, 2);
    return Qnil;
}

static VALUE NWScript_RemoveFromParty(VALUE self, VALUE oPC)
{
    StackPushObject(NUM2UINT(oPC));
    VM_ExecuteCommand(573, 1);
    return Qnil;
}

static VALUE NWScript_GetStealthMode(VALUE self, VALUE oCreature)
{
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(574, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetDetectMode(VALUE self, VALUE oCreature)
{
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(575, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetDefensiveCastingMode(VALUE self, VALUE oCreature)
{
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(576, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetAppearanceType(VALUE self, VALUE oCreature)
{
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(577, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_SpawnScriptDebugger(VALUE self)
{
    VM_ExecuteCommand(578, 0);
    return Qnil;
}

static VALUE NWScript_GetModuleItemAcquiredStackSize(VALUE self)
{
    VM_ExecuteCommand(579, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_DecrementRemainingFeatUses(VALUE self, VALUE oCreature, VALUE nFeat)
{
    StackPushInteger(NUM2INT(nFeat));
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(580, 2);
    return Qnil;
}

static VALUE NWScript_DecrementRemainingSpellUses(VALUE self, VALUE oCreature, VALUE nSpell)
{
    StackPushInteger(NUM2INT(nSpell));
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(581, 2);
    return Qnil;
}

static VALUE NWScript_GetResRef(VALUE self, VALUE oObject)
{
    StackPushObject(NUM2UINT(oObject));
    VM_ExecuteCommand(582, 1);
    char *sRetVal;
    StackPopString(&sRetVal);
    return rb_str_new2(sRetVal);
}

static VALUE NWScript_EffectPetrify(VALUE self)
{
    VM_ExecuteCommand(583, 0);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_CopyItem(int argc, VALUE *argv, VALUE self)
{
    VALUE oItem, oTargetInventory, bCopyVars;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    oItem = argv[0];
    if (argc > 1) oTargetInventory = argv[1];
    else oTargetInventory = INT2NUM(OBJECT_INVALID);
    if (argc > 2) bCopyVars = argv[2];
    else bCopyVars = INT2NUM(FALSE);
    StackPushInteger(NUM2INT(bCopyVars));
    StackPushObject(NUM2UINT(oTargetInventory));
    StackPushObject(NUM2UINT(oItem));
    VM_ExecuteCommand(584, 3);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_EffectCutsceneParalyze(VALUE self)
{
    VM_ExecuteCommand(585, 0);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_GetDroppableFlag(VALUE self, VALUE oItem)
{
    StackPushObject(NUM2UINT(oItem));
    VM_ExecuteCommand(586, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetUseableFlag(int argc, VALUE *argv, VALUE self)
{
    VALUE oObject;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oObject = argv[0];
    else oObject = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oObject));
    VM_ExecuteCommand(587, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetStolenFlag(VALUE self, VALUE oStolen)
{
    StackPushObject(NUM2UINT(oStolen));
    VM_ExecuteCommand(588, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_SetCampaignFloat(int argc, VALUE *argv, VALUE self)
{
    VALUE sCampaignName, sVarName, flFloat, oPlayer;
    if (argc < 3) {
        //TODO: Raise exception
        return Qnil;
    }
    sCampaignName = argv[0];
    sVarName = argv[1];
    flFloat = argv[2];
    if (argc > 3) oPlayer = argv[3];
    else oPlayer = INT2NUM(OBJECT_INVALID);
    StackPushObject(NUM2UINT(oPlayer));
    StackPushFloat(NUM2DBL(flFloat));
    StackPushString(StringValueCStr(sVarName));
    StackPushString(StringValueCStr(sCampaignName));
    VM_ExecuteCommand(589, 4);
    return Qnil;
}

static VALUE NWScript_SetCampaignInt(int argc, VALUE *argv, VALUE self)
{
    VALUE sCampaignName, sVarName, nInt, oPlayer;
    if (argc < 3) {
        //TODO: Raise exception
        return Qnil;
    }
    sCampaignName = argv[0];
    sVarName = argv[1];
    nInt = argv[2];
    if (argc > 3) oPlayer = argv[3];
    else oPlayer = INT2NUM(OBJECT_INVALID);
    StackPushObject(NUM2UINT(oPlayer));
    StackPushInteger(NUM2INT(nInt));
    StackPushString(StringValueCStr(sVarName));
    StackPushString(StringValueCStr(sCampaignName));
    VM_ExecuteCommand(590, 4);
    return Qnil;
}

static VALUE NWScript_SetCampaignVector(int argc, VALUE *argv, VALUE self)
{
    VALUE sCampaignName, sVarName, vVector, oPlayer;
    if (argc < 3) {
        //TODO: Raise exception
        return Qnil;
    }
    sCampaignName = argv[0];
    sVarName = argv[1];
    vVector = argv[2];
    if (argc > 3) oPlayer = argv[3];
    else oPlayer = INT2NUM(OBJECT_INVALID);
    StackPushObject(NUM2UINT(oPlayer));
    Vector *vVector_ptr;
    Data_Get_Struct(vVector, Vector, vVector_ptr);
    StackPushVector(*vVector_ptr);
    StackPushString(StringValueCStr(sVarName));
    StackPushString(StringValueCStr(sCampaignName));
    VM_ExecuteCommand(591, 4);
    return Qnil;
}

static VALUE NWScript_SetCampaignLocation(int argc, VALUE *argv, VALUE self)
{
    VALUE sCampaignName, sVarName, locLocation, oPlayer;
    if (argc < 3) {
        //TODO: Raise exception
        return Qnil;
    }
    sCampaignName = argv[0];
    sVarName = argv[1];
    locLocation = argv[2];
    if (argc > 3) oPlayer = argv[3];
    else oPlayer = INT2NUM(OBJECT_INVALID);
    StackPushObject(NUM2UINT(oPlayer));
    CScriptLocation *locLocation_ptr;
    Data_Get_Struct(locLocation, CScriptLocation, locLocation_ptr);
    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, locLocation_ptr);
    StackPushString(StringValueCStr(sVarName));
    StackPushString(StringValueCStr(sCampaignName));
    VM_ExecuteCommand(592, 4);
    return Qnil;
}

static VALUE NWScript_SetCampaignString(int argc, VALUE *argv, VALUE self)
{
    VALUE sCampaignName, sVarName, sString, oPlayer;
    if (argc < 3) {
        //TODO: Raise exception
        return Qnil;
    }
    sCampaignName = argv[0];
    sVarName = argv[1];
    sString = argv[2];
    if (argc > 3) oPlayer = argv[3];
    else oPlayer = INT2NUM(OBJECT_INVALID);
    StackPushObject(NUM2UINT(oPlayer));
    StackPushString(StringValueCStr(sString));
    StackPushString(StringValueCStr(sVarName));
    StackPushString(StringValueCStr(sCampaignName));
    VM_ExecuteCommand(593, 4);
    return Qnil;
}

static VALUE NWScript_DestroyCampaignDatabase(VALUE self, VALUE sCampaignName)
{
    StackPushString(StringValueCStr(sCampaignName));
    VM_ExecuteCommand(594, 1);
    return Qnil;
}

static VALUE NWScript_GetCampaignFloat(int argc, VALUE *argv, VALUE self)
{
    VALUE sCampaignName, sVarName, oPlayer;
    if (argc < 2) {
        //TODO: Raise exception
        return Qnil;
    }
    sCampaignName = argv[0];
    sVarName = argv[1];
    if (argc > 2) oPlayer = argv[2];
    else oPlayer = INT2NUM(OBJECT_INVALID);
    StackPushObject(NUM2UINT(oPlayer));
    StackPushString(StringValueCStr(sVarName));
    StackPushString(StringValueCStr(sCampaignName));
    VM_ExecuteCommand(595, 3);
    float fRetVal;
    StackPopFloat(&fRetVal);
    return rb_float_new(fRetVal);
}

static VALUE NWScript_GetCampaignInt(int argc, VALUE *argv, VALUE self)
{
    VALUE sCampaignName, sVarName, oPlayer;
    if (argc < 2) {
        //TODO: Raise exception
        return Qnil;
    }
    sCampaignName = argv[0];
    sVarName = argv[1];
    if (argc > 2) oPlayer = argv[2];
    else oPlayer = INT2NUM(OBJECT_INVALID);
    StackPushObject(NUM2UINT(oPlayer));
    StackPushString(StringValueCStr(sVarName));
    StackPushString(StringValueCStr(sCampaignName));
    VM_ExecuteCommand(596, 3);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetCampaignVector(int argc, VALUE *argv, VALUE self)
{
    VALUE sCampaignName, sVarName, oPlayer;
    if (argc < 2) {
        //TODO: Raise exception
        return Qnil;
    }
    sCampaignName = argv[0];
    sVarName = argv[1];
    if (argc > 2) oPlayer = argv[2];
    else oPlayer = INT2NUM(OBJECT_INVALID);
    StackPushObject(NUM2UINT(oPlayer));
    StackPushString(StringValueCStr(sVarName));
    StackPushString(StringValueCStr(sCampaignName));
    VM_ExecuteCommand(597, 3);
    Vector *vRetVal = (Vector *) malloc(sizeof(Vector));
    StackPopVector(vRetVal);
    return Data_Wrap_Struct(g_cVectorClass, 0, free, vRetVal);
}

static VALUE NWScript_GetCampaignLocation(int argc, VALUE *argv, VALUE self)
{
    VALUE sCampaignName, sVarName, oPlayer;
    if (argc < 2) {
        //TODO: Raise exception
        return Qnil;
    }
    sCampaignName = argv[0];
    sVarName = argv[1];
    if (argc > 2) oPlayer = argv[2];
    else oPlayer = INT2NUM(OBJECT_INVALID);
    StackPushObject(NUM2UINT(oPlayer));
    StackPushString(StringValueCStr(sVarName));
    StackPushString(StringValueCStr(sCampaignName));
    VM_ExecuteCommand(598, 3);
    CScriptLocation *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_LOCATION, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cLocationClass, 0, free, pRetVal);
}

static VALUE NWScript_GetCampaignString(int argc, VALUE *argv, VALUE self)
{
    VALUE sCampaignName, sVarName, oPlayer;
    if (argc < 2) {
        //TODO: Raise exception
        return Qnil;
    }
    sCampaignName = argv[0];
    sVarName = argv[1];
    if (argc > 2) oPlayer = argv[2];
    else oPlayer = INT2NUM(OBJECT_INVALID);
    StackPushObject(NUM2UINT(oPlayer));
    StackPushString(StringValueCStr(sVarName));
    StackPushString(StringValueCStr(sCampaignName));
    VM_ExecuteCommand(599, 3);
    char *sRetVal;
    StackPopString(&sRetVal);
    return rb_str_new2(sRetVal);
}

static VALUE NWScript_CopyObject(int argc, VALUE *argv, VALUE self)
{
    VALUE oSource, locLocation, oOwner , sNewTag ;
    if (argc < 2) {
        //TODO: Raise exception
        return Qnil;
    }
    oSource = argv[0];
    locLocation = argv[1];
    if (argc > 2) oOwner  = argv[2];
    else oOwner  = INT2NUM(OBJECT_INVALID);
    if (argc > 3) sNewTag  = argv[3];
    else sNewTag  = rb_str_new2("");
    StackPushString(StringValueCStr(sNewTag));
    StackPushObject(NUM2UINT(oOwner));
    CScriptLocation *locLocation_ptr;
    Data_Get_Struct(locLocation, CScriptLocation, locLocation_ptr);
    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, locLocation_ptr);
    StackPushObject(NUM2UINT(oSource));
    VM_ExecuteCommand(600, 4);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_DeleteCampaignVariable(int argc, VALUE *argv, VALUE self)
{
    VALUE sCampaignName, sVarName, oPlayer;
    if (argc < 2) {
        //TODO: Raise exception
        return Qnil;
    }
    sCampaignName = argv[0];
    sVarName = argv[1];
    if (argc > 2) oPlayer = argv[2];
    else oPlayer = INT2NUM(OBJECT_INVALID);
    StackPushObject(NUM2UINT(oPlayer));
    StackPushString(StringValueCStr(sVarName));
    StackPushString(StringValueCStr(sCampaignName));
    VM_ExecuteCommand(601, 3);
    return Qnil;
}

static VALUE NWScript_StoreCampaignObject(int argc, VALUE *argv, VALUE self)
{
    VALUE sCampaignName, sVarName, oObject, oPlayer;
    if (argc < 3) {
        //TODO: Raise exception
        return Qnil;
    }
    sCampaignName = argv[0];
    sVarName = argv[1];
    oObject = argv[2];
    if (argc > 3) oPlayer = argv[3];
    else oPlayer = INT2NUM(OBJECT_INVALID);
    StackPushObject(NUM2UINT(oPlayer));
    StackPushObject(NUM2UINT(oObject));
    StackPushString(StringValueCStr(sVarName));
    StackPushString(StringValueCStr(sCampaignName));
    VM_ExecuteCommand(602, 4);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_RetrieveCampaignObject(int argc, VALUE *argv, VALUE self)
{
    VALUE sCampaignName, sVarName, locLocation, oOwner , oPlayer;
    if (argc < 3) {
        //TODO: Raise exception
        return Qnil;
    }
    sCampaignName = argv[0];
    sVarName = argv[1];
    locLocation = argv[2];
    if (argc > 3) oOwner  = argv[3];
    else oOwner  = INT2NUM(OBJECT_INVALID);
    if (argc > 4) oPlayer = argv[4];
    else oPlayer = INT2NUM(OBJECT_INVALID);
    StackPushObject(NUM2UINT(oPlayer));
    StackPushObject(NUM2UINT(oOwner));
    CScriptLocation *locLocation_ptr;
    Data_Get_Struct(locLocation, CScriptLocation, locLocation_ptr);
    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, locLocation_ptr);
    StackPushString(StringValueCStr(sVarName));
    StackPushString(StringValueCStr(sCampaignName));
    VM_ExecuteCommand(603, 5);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_EffectCutsceneDominated(VALUE self)
{
    VM_ExecuteCommand(604, 0);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_GetItemStackSize(VALUE self, VALUE oItem)
{
    StackPushObject(NUM2UINT(oItem));
    VM_ExecuteCommand(605, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_SetItemStackSize(VALUE self, VALUE oItem, VALUE nSize)
{
    StackPushInteger(NUM2INT(nSize));
    StackPushObject(NUM2UINT(oItem));
    VM_ExecuteCommand(606, 2);
    return Qnil;
}

static VALUE NWScript_GetItemCharges(VALUE self, VALUE oItem)
{
    StackPushObject(NUM2UINT(oItem));
    VM_ExecuteCommand(607, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_SetItemCharges(VALUE self, VALUE oItem, VALUE nCharges)
{
    StackPushInteger(NUM2INT(nCharges));
    StackPushObject(NUM2UINT(oItem));
    VM_ExecuteCommand(608, 2);
    return Qnil;
}

static VALUE NWScript_AddItemProperty(int argc, VALUE *argv, VALUE self)
{
    VALUE nDurationType, ipProperty, oItem, fDuration;
    if (argc < 3) {
        //TODO: Raise exception
        return Qnil;
    }
    nDurationType = argv[0];
    ipProperty = argv[1];
    oItem = argv[2];
    if (argc > 3) fDuration = argv[3];
    else fDuration = rb_float_new(0.0f);
    StackPushFloat(NUM2DBL(fDuration));
    StackPushObject(NUM2UINT(oItem));
    CGameEffect *ipProperty_ptr;
    Data_Get_Struct(ipProperty, CGameEffect, ipProperty_ptr);
    StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, ipProperty_ptr);
    StackPushInteger(NUM2INT(nDurationType));
    VM_ExecuteCommand(609, 4);
    return Qnil;
}

static VALUE NWScript_RemoveItemProperty(VALUE self, VALUE oItem, VALUE ipProperty)
{
    CGameEffect *ipProperty_ptr;
    Data_Get_Struct(ipProperty, CGameEffect, ipProperty_ptr);
    StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, ipProperty_ptr);
    StackPushObject(NUM2UINT(oItem));
    VM_ExecuteCommand(610, 2);
    return Qnil;
}

static VALUE NWScript_GetIsItemPropertyValid(VALUE self, VALUE ipProperty)
{
    CGameEffect *ipProperty_ptr;
    Data_Get_Struct(ipProperty, CGameEffect, ipProperty_ptr);
    StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, ipProperty_ptr);
    VM_ExecuteCommand(611, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetFirstItemProperty(VALUE self, VALUE oItem)
{
    StackPushObject(NUM2UINT(oItem));
    VM_ExecuteCommand(612, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_GetNextItemProperty(VALUE self, VALUE oItem)
{
    StackPushObject(NUM2UINT(oItem));
    VM_ExecuteCommand(613, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_GetItemPropertyType(VALUE self, VALUE ip)
{
    CGameEffect *ip_ptr;
    Data_Get_Struct(ip, CGameEffect, ip_ptr);
    StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, ip_ptr);
    VM_ExecuteCommand(614, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetItemPropertyDurationType(VALUE self, VALUE ip)
{
    CGameEffect *ip_ptr;
    Data_Get_Struct(ip, CGameEffect, ip_ptr);
    StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, ip_ptr);
    VM_ExecuteCommand(615, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_ItemPropertyAbilityBonus(VALUE self, VALUE nAbility, VALUE nBonus)
{
    StackPushInteger(NUM2INT(nBonus));
    StackPushInteger(NUM2INT(nAbility));
    VM_ExecuteCommand(616, 2);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyACBonus(VALUE self, VALUE nBonus)
{
    StackPushInteger(NUM2INT(nBonus));
    VM_ExecuteCommand(617, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyACBonusVsAlign(VALUE self, VALUE nAlignGroup, VALUE nACBonus)
{
    StackPushInteger(NUM2INT(nACBonus));
    StackPushInteger(NUM2INT(nAlignGroup));
    VM_ExecuteCommand(618, 2);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyACBonusVsDmgType(VALUE self, VALUE nDamageType, VALUE nACBonus)
{
    StackPushInteger(NUM2INT(nACBonus));
    StackPushInteger(NUM2INT(nDamageType));
    VM_ExecuteCommand(619, 2);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyACBonusVsRace(VALUE self, VALUE nRace, VALUE nACBonus)
{
    StackPushInteger(NUM2INT(nACBonus));
    StackPushInteger(NUM2INT(nRace));
    VM_ExecuteCommand(620, 2);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyACBonusVsSAlign(VALUE self, VALUE nAlign, VALUE nACBonus)
{
    StackPushInteger(NUM2INT(nACBonus));
    StackPushInteger(NUM2INT(nAlign));
    VM_ExecuteCommand(621, 2);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyEnhancementBonus(VALUE self, VALUE nEnhancementBonus)
{
    StackPushInteger(NUM2INT(nEnhancementBonus));
    VM_ExecuteCommand(622, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyEnhancementBonusVsAlign(VALUE self, VALUE nAlignGroup, VALUE nBonus)
{
    StackPushInteger(NUM2INT(nBonus));
    StackPushInteger(NUM2INT(nAlignGroup));
    VM_ExecuteCommand(623, 2);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyEnhancementBonusVsRace(VALUE self, VALUE nRace, VALUE nBonus)
{
    StackPushInteger(NUM2INT(nBonus));
    StackPushInteger(NUM2INT(nRace));
    VM_ExecuteCommand(624, 2);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyEnhancementBonusVsSAlign(VALUE self, VALUE nAlign, VALUE nBonus)
{
    StackPushInteger(NUM2INT(nBonus));
    StackPushInteger(NUM2INT(nAlign));
    VM_ExecuteCommand(625, 2);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyEnhancementPenalty(VALUE self, VALUE nPenalty)
{
    StackPushInteger(NUM2INT(nPenalty));
    VM_ExecuteCommand(626, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyWeightReduction(VALUE self, VALUE nReduction)
{
    StackPushInteger(NUM2INT(nReduction));
    VM_ExecuteCommand(627, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyBonusFeat(VALUE self, VALUE nFeat)
{
    StackPushInteger(NUM2INT(nFeat));
    VM_ExecuteCommand(628, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyBonusLevelSpell(VALUE self, VALUE nClass, VALUE nSpellLevel)
{
    StackPushInteger(NUM2INT(nSpellLevel));
    StackPushInteger(NUM2INT(nClass));
    VM_ExecuteCommand(629, 2);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyCastSpell(VALUE self, VALUE nSpell, VALUE nNumUses)
{
    StackPushInteger(NUM2INT(nNumUses));
    StackPushInteger(NUM2INT(nSpell));
    VM_ExecuteCommand(630, 2);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyDamageBonus(VALUE self, VALUE nDamageType, VALUE nDamage)
{
    StackPushInteger(NUM2INT(nDamage));
    StackPushInteger(NUM2INT(nDamageType));
    VM_ExecuteCommand(631, 2);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyDamageBonusVsAlign(VALUE self, VALUE nAlignGroup, VALUE nDamageType, VALUE nDamage)
{
    StackPushInteger(NUM2INT(nDamage));
    StackPushInteger(NUM2INT(nDamageType));
    StackPushInteger(NUM2INT(nAlignGroup));
    VM_ExecuteCommand(632, 3);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyDamageBonusVsRace(VALUE self, VALUE nRace, VALUE nDamageType, VALUE nDamage)
{
    StackPushInteger(NUM2INT(nDamage));
    StackPushInteger(NUM2INT(nDamageType));
    StackPushInteger(NUM2INT(nRace));
    VM_ExecuteCommand(633, 3);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyDamageBonusVsSAlign(VALUE self, VALUE nAlign, VALUE nDamageType, VALUE nDamage)
{
    StackPushInteger(NUM2INT(nDamage));
    StackPushInteger(NUM2INT(nDamageType));
    StackPushInteger(NUM2INT(nAlign));
    VM_ExecuteCommand(634, 3);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyDamageImmunity(VALUE self, VALUE nDamageType, VALUE nImmuneBonus)
{
    StackPushInteger(NUM2INT(nImmuneBonus));
    StackPushInteger(NUM2INT(nDamageType));
    VM_ExecuteCommand(635, 2);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyDamagePenalty(VALUE self, VALUE nPenalty)
{
    StackPushInteger(NUM2INT(nPenalty));
    VM_ExecuteCommand(636, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyDamageReduction(VALUE self, VALUE nEnhancement, VALUE nHPSoak)
{
    StackPushInteger(NUM2INT(nHPSoak));
    StackPushInteger(NUM2INT(nEnhancement));
    VM_ExecuteCommand(637, 2);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyDamageResistance(VALUE self, VALUE nDamageType, VALUE nHPResist)
{
    StackPushInteger(NUM2INT(nHPResist));
    StackPushInteger(NUM2INT(nDamageType));
    VM_ExecuteCommand(638, 2);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyDamageVulnerability(VALUE self, VALUE nDamageType, VALUE nVulnerability)
{
    StackPushInteger(NUM2INT(nVulnerability));
    StackPushInteger(NUM2INT(nDamageType));
    VM_ExecuteCommand(639, 2);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyDarkvision(VALUE self)
{
    VM_ExecuteCommand(640, 0);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyDecreaseAbility(VALUE self, VALUE nAbility, VALUE nModifier)
{
    StackPushInteger(NUM2INT(nModifier));
    StackPushInteger(NUM2INT(nAbility));
    VM_ExecuteCommand(641, 2);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyDecreaseAC(VALUE self, VALUE nModifierType, VALUE nPenalty)
{
    StackPushInteger(NUM2INT(nPenalty));
    StackPushInteger(NUM2INT(nModifierType));
    VM_ExecuteCommand(642, 2);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyDecreaseSkill(VALUE self, VALUE nSkill, VALUE nPenalty)
{
    StackPushInteger(NUM2INT(nPenalty));
    StackPushInteger(NUM2INT(nSkill));
    VM_ExecuteCommand(643, 2);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyContainerReducedWeight(VALUE self, VALUE nContainerType)
{
    StackPushInteger(NUM2INT(nContainerType));
    VM_ExecuteCommand(644, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyExtraMeleeDamageType(VALUE self, VALUE nDamageType)
{
    StackPushInteger(NUM2INT(nDamageType));
    VM_ExecuteCommand(645, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyExtraRangeDamageType(VALUE self, VALUE nDamageType)
{
    StackPushInteger(NUM2INT(nDamageType));
    VM_ExecuteCommand(646, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyHaste(VALUE self)
{
    VM_ExecuteCommand(647, 0);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyHolyAvenger(VALUE self)
{
    VM_ExecuteCommand(648, 0);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyImmunityMisc(VALUE self, VALUE nImmunityType)
{
    StackPushInteger(NUM2INT(nImmunityType));
    VM_ExecuteCommand(649, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyImprovedEvasion(VALUE self)
{
    VM_ExecuteCommand(650, 0);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyBonusSpellResistance(VALUE self, VALUE nBonus)
{
    StackPushInteger(NUM2INT(nBonus));
    VM_ExecuteCommand(651, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyBonusSavingThrowVsX(VALUE self, VALUE nBonusType, VALUE nBonus)
{
    StackPushInteger(NUM2INT(nBonus));
    StackPushInteger(NUM2INT(nBonusType));
    VM_ExecuteCommand(652, 2);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyBonusSavingThrow(VALUE self, VALUE nBaseSaveType, VALUE nBonus)
{
    StackPushInteger(NUM2INT(nBonus));
    StackPushInteger(NUM2INT(nBaseSaveType));
    VM_ExecuteCommand(653, 2);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyKeen(VALUE self)
{
    VM_ExecuteCommand(654, 0);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyLight(VALUE self, VALUE nBrightness, VALUE nColor)
{
    StackPushInteger(NUM2INT(nColor));
    StackPushInteger(NUM2INT(nBrightness));
    VM_ExecuteCommand(655, 2);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyMaxRangeStrengthMod(VALUE self, VALUE nModifier)
{
    StackPushInteger(NUM2INT(nModifier));
    VM_ExecuteCommand(656, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyNoDamage(VALUE self)
{
    VM_ExecuteCommand(657, 0);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyOnHitProps(int argc, VALUE *argv, VALUE self)
{
    VALUE nProperty, nSaveDC, nSpecial;
    if (argc < 2) {
        //TODO: Raise exception
        return Qnil;
    }
    nProperty = argv[0];
    nSaveDC = argv[1];
    if (argc > 2) nSpecial = argv[2];
    else nSpecial = INT2NUM(0);
    StackPushInteger(NUM2INT(nSpecial));
    StackPushInteger(NUM2INT(nSaveDC));
    StackPushInteger(NUM2INT(nProperty));
    VM_ExecuteCommand(658, 3);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyReducedSavingThrowVsX(VALUE self, VALUE nBaseSaveType, VALUE nPenalty)
{
    StackPushInteger(NUM2INT(nPenalty));
    StackPushInteger(NUM2INT(nBaseSaveType));
    VM_ExecuteCommand(659, 2);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyReducedSavingThrow(VALUE self, VALUE nBonusType, VALUE nPenalty)
{
    StackPushInteger(NUM2INT(nPenalty));
    StackPushInteger(NUM2INT(nBonusType));
    VM_ExecuteCommand(660, 2);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyRegeneration(VALUE self, VALUE nRegenAmount)
{
    StackPushInteger(NUM2INT(nRegenAmount));
    VM_ExecuteCommand(661, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertySkillBonus(VALUE self, VALUE nSkill, VALUE nBonus)
{
    StackPushInteger(NUM2INT(nBonus));
    StackPushInteger(NUM2INT(nSkill));
    VM_ExecuteCommand(662, 2);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertySpellImmunitySpecific(VALUE self, VALUE nSpell)
{
    StackPushInteger(NUM2INT(nSpell));
    VM_ExecuteCommand(663, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertySpellImmunitySchool(VALUE self, VALUE nSchool)
{
    StackPushInteger(NUM2INT(nSchool));
    VM_ExecuteCommand(664, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyThievesTools(VALUE self, VALUE nModifier)
{
    StackPushInteger(NUM2INT(nModifier));
    VM_ExecuteCommand(665, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyAttackBonus(VALUE self, VALUE nBonus)
{
    StackPushInteger(NUM2INT(nBonus));
    VM_ExecuteCommand(666, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyAttackBonusVsAlign(VALUE self, VALUE nAlignGroup, VALUE nBonus)
{
    StackPushInteger(NUM2INT(nBonus));
    StackPushInteger(NUM2INT(nAlignGroup));
    VM_ExecuteCommand(667, 2);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyAttackBonusVsRace(VALUE self, VALUE nRace, VALUE nBonus)
{
    StackPushInteger(NUM2INT(nBonus));
    StackPushInteger(NUM2INT(nRace));
    VM_ExecuteCommand(668, 2);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyAttackBonusVsSAlign(VALUE self, VALUE nAlignment, VALUE nBonus)
{
    StackPushInteger(NUM2INT(nBonus));
    StackPushInteger(NUM2INT(nAlignment));
    VM_ExecuteCommand(669, 2);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyAttackPenalty(VALUE self, VALUE nPenalty)
{
    StackPushInteger(NUM2INT(nPenalty));
    VM_ExecuteCommand(670, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyUnlimitedAmmo(int argc, VALUE *argv, VALUE self)
{
    VALUE nAmmoDamage;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) nAmmoDamage = argv[0];
    else nAmmoDamage = INT2NUM(IP_CONST_UNLIMITEDAMMO_BASIC);
    StackPushInteger(NUM2INT(nAmmoDamage));
    VM_ExecuteCommand(671, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyLimitUseByAlign(VALUE self, VALUE nAlignGroup)
{
    StackPushInteger(NUM2INT(nAlignGroup));
    VM_ExecuteCommand(672, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyLimitUseByClass(VALUE self, VALUE nClass)
{
    StackPushInteger(NUM2INT(nClass));
    VM_ExecuteCommand(673, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyLimitUseByRace(VALUE self, VALUE nRace)
{
    StackPushInteger(NUM2INT(nRace));
    VM_ExecuteCommand(674, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyLimitUseBySAlign(VALUE self, VALUE nAlignment)
{
    StackPushInteger(NUM2INT(nAlignment));
    VM_ExecuteCommand(675, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_BadBadReplaceMeThisDoesNothing(VALUE self)
{
    VM_ExecuteCommand(676, 0);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyVampiricRegeneration(VALUE self, VALUE nRegenAmount)
{
    StackPushInteger(NUM2INT(nRegenAmount));
    VM_ExecuteCommand(677, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyTrap(VALUE self, VALUE nTrapLevel, VALUE nTrapType)
{
    StackPushInteger(NUM2INT(nTrapType));
    StackPushInteger(NUM2INT(nTrapLevel));
    VM_ExecuteCommand(678, 2);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyTrueSeeing(VALUE self)
{
    VM_ExecuteCommand(679, 0);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyOnMonsterHitProperties(int argc, VALUE *argv, VALUE self)
{
    VALUE nProperty, nSpecial;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    nProperty = argv[0];
    if (argc > 1) nSpecial = argv[1];
    else nSpecial = INT2NUM(0);
    StackPushInteger(NUM2INT(nSpecial));
    StackPushInteger(NUM2INT(nProperty));
    VM_ExecuteCommand(680, 2);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyTurnResistance(VALUE self, VALUE nModifier)
{
    StackPushInteger(NUM2INT(nModifier));
    VM_ExecuteCommand(681, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyMassiveCritical(VALUE self, VALUE nDamage)
{
    StackPushInteger(NUM2INT(nDamage));
    VM_ExecuteCommand(682, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyFreeAction(VALUE self)
{
    VM_ExecuteCommand(683, 0);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyMonsterDamage(VALUE self, VALUE nDamage)
{
    StackPushInteger(NUM2INT(nDamage));
    VM_ExecuteCommand(684, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyImmunityToSpellLevel(VALUE self, VALUE nLevel)
{
    StackPushInteger(NUM2INT(nLevel));
    VM_ExecuteCommand(685, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertySpecialWalk(int argc, VALUE *argv, VALUE self)
{
    VALUE nWalkType;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) nWalkType = argv[0];
    else nWalkType = INT2NUM(0);
    StackPushInteger(NUM2INT(nWalkType));
    VM_ExecuteCommand(686, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyHealersKit(VALUE self, VALUE nModifier)
{
    StackPushInteger(NUM2INT(nModifier));
    VM_ExecuteCommand(687, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyWeightIncrease(VALUE self, VALUE nWeight)
{
    StackPushInteger(NUM2INT(nWeight));
    VM_ExecuteCommand(688, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_GetIsSkillSuccessful(VALUE self, VALUE oTarget, VALUE nSkill, VALUE nDifficulty)
{
    StackPushInteger(NUM2INT(nDifficulty));
    StackPushInteger(NUM2INT(nSkill));
    StackPushObject(NUM2UINT(oTarget));
    VM_ExecuteCommand(689, 3);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_EffectSpellFailure(int argc, VALUE *argv, VALUE self)
{
    VALUE nPercent, nSpellSchool;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) nPercent = argv[0];
    else nPercent = INT2NUM(100);
    if (argc > 1) nSpellSchool = argv[1];
    else nSpellSchool = INT2NUM(SPELL_SCHOOL_GENERAL);
    StackPushInteger(NUM2INT(nSpellSchool));
    StackPushInteger(NUM2INT(nPercent));
    VM_ExecuteCommand(690, 2);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_SpeakStringByStrRef(int argc, VALUE *argv, VALUE self)
{
    VALUE nStrRef, nTalkVolume;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    nStrRef = argv[0];
    if (argc > 1) nTalkVolume = argv[1];
    else nTalkVolume = INT2NUM(TALKVOLUME_TALK);
    StackPushInteger(NUM2INT(nTalkVolume));
    StackPushInteger(NUM2INT(nStrRef));
    VM_ExecuteCommand(691, 2);
    return Qnil;
}

static VALUE NWScript_SetCutsceneMode(int argc, VALUE *argv, VALUE self)
{
    VALUE oCreature, nInCutscene, nLeftClickingEnabled;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    oCreature = argv[0];
    if (argc > 1) nInCutscene = argv[1];
    else nInCutscene = INT2NUM(TRUE);
    if (argc > 2) nLeftClickingEnabled = argv[2];
    else nLeftClickingEnabled = INT2NUM(FALSE);
    StackPushInteger(NUM2INT(nLeftClickingEnabled));
    StackPushInteger(NUM2INT(nInCutscene));
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(692, 3);
    return Qnil;
}

static VALUE NWScript_GetLastPCToCancelCutscene(VALUE self)
{
    VM_ExecuteCommand(693, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetDialogSoundLength(VALUE self, VALUE nStrRef)
{
    StackPushInteger(NUM2INT(nStrRef));
    VM_ExecuteCommand(694, 1);
    float fRetVal;
    StackPopFloat(&fRetVal);
    return rb_float_new(fRetVal);
}

static VALUE NWScript_FadeFromBlack(int argc, VALUE *argv, VALUE self)
{
    VALUE oCreature, fSpeed;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    oCreature = argv[0];
    if (argc > 1) fSpeed = argv[1];
    else fSpeed = rb_float_new(FADE_SPEED_MEDIUM);
    StackPushFloat(NUM2DBL(fSpeed));
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(695, 2);
    return Qnil;
}

static VALUE NWScript_FadeToBlack(int argc, VALUE *argv, VALUE self)
{
    VALUE oCreature, fSpeed;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    oCreature = argv[0];
    if (argc > 1) fSpeed = argv[1];
    else fSpeed = rb_float_new(FADE_SPEED_MEDIUM);
    StackPushFloat(NUM2DBL(fSpeed));
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(696, 2);
    return Qnil;
}

static VALUE NWScript_StopFade(VALUE self, VALUE oCreature)
{
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(697, 1);
    return Qnil;
}

static VALUE NWScript_BlackScreen(VALUE self, VALUE oCreature)
{
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(698, 1);
    return Qnil;
}

static VALUE NWScript_GetBaseAttackBonus(VALUE self, VALUE oCreature)
{
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(699, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_SetImmortal(VALUE self, VALUE oCreature, VALUE bImmortal)
{
    StackPushInteger(NUM2INT(bImmortal));
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(700, 2);
    return Qnil;
}

static VALUE NWScript_OpenInventory(VALUE self, VALUE oCreature, VALUE oPlayer)
{
    StackPushObject(NUM2UINT(oPlayer));
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(701, 2);
    return Qnil;
}

static VALUE NWScript_StoreCameraFacing(VALUE self)
{
    VM_ExecuteCommand(702, 0);
    return Qnil;
}

static VALUE NWScript_RestoreCameraFacing(VALUE self)
{
    VM_ExecuteCommand(703, 0);
    return Qnil;
}

static VALUE NWScript_LevelUpHenchman(int argc, VALUE *argv, VALUE self)
{
    VALUE oCreature, nClass , bReadyAllSpells , nPackage ;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    oCreature = argv[0];
    if (argc > 1) nClass  = argv[1];
    else nClass  = INT2NUM(CLASS_TYPE_INVALID);
    if (argc > 2) bReadyAllSpells  = argv[2];
    else bReadyAllSpells  = INT2NUM(FALSE);
    if (argc > 3) nPackage  = argv[3];
    else nPackage  = INT2NUM(PACKAGE_INVALID);
    StackPushInteger(NUM2INT(nPackage));
    StackPushInteger(NUM2INT(bReadyAllSpells));
    StackPushInteger(NUM2INT(nClass));
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(704, 4);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_SetDroppableFlag(VALUE self, VALUE oItem, VALUE bDroppable)
{
    StackPushInteger(NUM2INT(bDroppable));
    StackPushObject(NUM2UINT(oItem));
    VM_ExecuteCommand(705, 2);
    return Qnil;
}

static VALUE NWScript_GetWeight(int argc, VALUE *argv, VALUE self)
{
    VALUE oTarget;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oTarget = argv[0];
    else oTarget = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oTarget));
    VM_ExecuteCommand(706, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetModuleItemAcquiredBy(VALUE self)
{
    VM_ExecuteCommand(707, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetImmortal(int argc, VALUE *argv, VALUE self)
{
    VALUE oTarget;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oTarget = argv[0];
    else oTarget = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oTarget));
    VM_ExecuteCommand(708, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_DoWhirlwindAttack(int argc, VALUE *argv, VALUE self)
{
    VALUE bDisplayFeedback, bImproved;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) bDisplayFeedback = argv[0];
    else bDisplayFeedback = INT2NUM(TRUE);
    if (argc > 1) bImproved = argv[1];
    else bImproved = INT2NUM(FALSE);
    StackPushInteger(NUM2INT(bImproved));
    StackPushInteger(NUM2INT(bDisplayFeedback));
    VM_ExecuteCommand(709, 2);
    return Qnil;
}

static VALUE NWScript_Get2DAString(VALUE self, VALUE s2DA, VALUE sColumn, VALUE nRow)
{
    StackPushInteger(NUM2INT(nRow));
    StackPushString(StringValueCStr(sColumn));
    StackPushString(StringValueCStr(s2DA));
    VM_ExecuteCommand(710, 3);
    char *sRetVal;
    StackPopString(&sRetVal);
    return rb_str_new2(sRetVal);
}

static VALUE NWScript_EffectEthereal(VALUE self)
{
    VM_ExecuteCommand(711, 0);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_GetAILevel(int argc, VALUE *argv, VALUE self)
{
    VALUE oTarget;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oTarget = argv[0];
    else oTarget = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oTarget));
    VM_ExecuteCommand(712, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_SetAILevel(VALUE self, VALUE oTarget, VALUE nAILevel)
{
    StackPushInteger(NUM2INT(nAILevel));
    StackPushObject(NUM2UINT(oTarget));
    VM_ExecuteCommand(713, 2);
    return Qnil;
}

static VALUE NWScript_GetIsPossessedFamiliar(VALUE self, VALUE oCreature)
{
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(714, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_UnpossessFamiliar(VALUE self, VALUE oCreature)
{
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(715, 1);
    return Qnil;
}

static VALUE NWScript_GetIsAreaInterior(int argc, VALUE *argv, VALUE self)
{
    VALUE oArea ;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oArea  = argv[0];
    else oArea  = INT2NUM(OBJECT_INVALID);
    StackPushObject(NUM2UINT(oArea));
    VM_ExecuteCommand(716, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_SendMessageToPCByStrRef(VALUE self, VALUE oPlayer, VALUE nStrRef)
{
    StackPushInteger(NUM2INT(nStrRef));
    StackPushObject(NUM2UINT(oPlayer));
    VM_ExecuteCommand(717, 2);
    return Qnil;
}

static VALUE NWScript_IncrementRemainingFeatUses(VALUE self, VALUE oCreature, VALUE nFeat)
{
    StackPushInteger(NUM2INT(nFeat));
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(718, 2);
    return Qnil;
}

static VALUE NWScript_ExportSingleCharacter(VALUE self, VALUE oPlayer)
{
    StackPushObject(NUM2UINT(oPlayer));
    VM_ExecuteCommand(719, 1);
    return Qnil;
}

static VALUE NWScript_PlaySoundByStrRef(int argc, VALUE *argv, VALUE self)
{
    VALUE nStrRef, nRunAsAction ;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    nStrRef = argv[0];
    if (argc > 1) nRunAsAction  = argv[1];
    else nRunAsAction  = INT2NUM(TRUE);
    StackPushInteger(NUM2INT(nRunAsAction));
    StackPushInteger(NUM2INT(nStrRef));
    VM_ExecuteCommand(720, 2);
    return Qnil;
}

static VALUE NWScript_SetSubRace(VALUE self, VALUE oCreature, VALUE sSubRace)
{
    StackPushString(StringValueCStr(sSubRace));
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(721, 2);
    return Qnil;
}

static VALUE NWScript_SetDeity(VALUE self, VALUE oCreature, VALUE sDeity)
{
    StackPushString(StringValueCStr(sDeity));
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(722, 2);
    return Qnil;
}

static VALUE NWScript_GetIsDMPossessed(VALUE self, VALUE oCreature)
{
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(723, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetWeather(VALUE self, VALUE oArea)
{
    StackPushObject(NUM2UINT(oArea));
    VM_ExecuteCommand(724, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetIsAreaNatural(VALUE self, VALUE oArea)
{
    StackPushObject(NUM2UINT(oArea));
    VM_ExecuteCommand(725, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetIsAreaAboveGround(VALUE self, VALUE oArea)
{
    StackPushObject(NUM2UINT(oArea));
    VM_ExecuteCommand(726, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetPCItemLastEquipped(VALUE self)
{
    VM_ExecuteCommand(727, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetPCItemLastEquippedBy(VALUE self)
{
    VM_ExecuteCommand(728, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetPCItemLastUnequipped(VALUE self)
{
    VM_ExecuteCommand(729, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetPCItemLastUnequippedBy(VALUE self)
{
    VM_ExecuteCommand(730, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_CopyItemAndModify(int argc, VALUE *argv, VALUE self)
{
    VALUE oItem, nType, nIndex, nNewValue, bCopyVars;
    if (argc < 4) {
        //TODO: Raise exception
        return Qnil;
    }
    oItem = argv[0];
    nType = argv[1];
    nIndex = argv[2];
    nNewValue = argv[3];
    if (argc > 4) bCopyVars = argv[4];
    else bCopyVars = INT2NUM(FALSE);
    StackPushInteger(NUM2INT(bCopyVars));
    StackPushInteger(NUM2INT(nNewValue));
    StackPushInteger(NUM2INT(nIndex));
    StackPushInteger(NUM2INT(nType));
    StackPushObject(NUM2UINT(oItem));
    VM_ExecuteCommand(731, 5);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetItemAppearance(VALUE self, VALUE oItem, VALUE nType, VALUE nIndex)
{
    StackPushInteger(NUM2INT(nIndex));
    StackPushInteger(NUM2INT(nType));
    StackPushObject(NUM2UINT(oItem));
    VM_ExecuteCommand(732, 3);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_ItemPropertyOnHitCastSpell(VALUE self, VALUE nSpell, VALUE nLevel)
{
    StackPushInteger(NUM2INT(nLevel));
    StackPushInteger(NUM2INT(nSpell));
    VM_ExecuteCommand(733, 2);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_GetItemPropertySubType(VALUE self, VALUE iProperty)
{
    CGameEffect *iProperty_ptr;
    Data_Get_Struct(iProperty, CGameEffect, iProperty_ptr);
    StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, iProperty_ptr);
    VM_ExecuteCommand(734, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetActionMode(VALUE self, VALUE oCreature, VALUE nMode)
{
    StackPushInteger(NUM2INT(nMode));
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(735, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_SetActionMode(VALUE self, VALUE oCreature, VALUE nMode, VALUE nStatus)
{
    StackPushInteger(NUM2INT(nStatus));
    StackPushInteger(NUM2INT(nMode));
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(736, 3);
    return Qnil;
}

static VALUE NWScript_GetArcaneSpellFailure(VALUE self, VALUE oCreature)
{
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(737, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_ActionExamine(VALUE self, VALUE oExamine)
{
    StackPushObject(NUM2UINT(oExamine));
    VM_ExecuteCommand(738, 1);
    return Qnil;
}

static VALUE NWScript_ItemPropertyVisualEffect(VALUE self, VALUE nEffect)
{
    StackPushInteger(NUM2INT(nEffect));
    VM_ExecuteCommand(739, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_SetLootable(VALUE self, VALUE oCreature, VALUE bLootable)
{
    StackPushInteger(NUM2INT(bLootable));
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(740, 2);
    return Qnil;
}

static VALUE NWScript_GetLootable(VALUE self, VALUE oCreature)
{
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(741, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetCutsceneCameraMoveRate(VALUE self, VALUE oCreature)
{
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(742, 1);
    float fRetVal;
    StackPopFloat(&fRetVal);
    return rb_float_new(fRetVal);
}

static VALUE NWScript_SetCutsceneCameraMoveRate(VALUE self, VALUE oCreature, VALUE fRate)
{
    StackPushFloat(NUM2DBL(fRate));
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(743, 2);
    return Qnil;
}

static VALUE NWScript_GetItemCursedFlag(VALUE self, VALUE oItem)
{
    StackPushObject(NUM2UINT(oItem));
    VM_ExecuteCommand(744, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_SetItemCursedFlag(VALUE self, VALUE oItem, VALUE nCursed)
{
    StackPushInteger(NUM2INT(nCursed));
    StackPushObject(NUM2UINT(oItem));
    VM_ExecuteCommand(745, 2);
    return Qnil;
}

static VALUE NWScript_SetMaxHenchmen(VALUE self, VALUE nNumHenchmen)
{
    StackPushInteger(NUM2INT(nNumHenchmen));
    VM_ExecuteCommand(746, 1);
    return Qnil;
}

static VALUE NWScript_GetMaxHenchmen(VALUE self)
{
    VM_ExecuteCommand(747, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetAssociateType(VALUE self, VALUE oAssociate)
{
    StackPushObject(NUM2UINT(oAssociate));
    VM_ExecuteCommand(748, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetSpellResistance(VALUE self, VALUE oCreature)
{
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(749, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_DayToNight(int argc, VALUE *argv, VALUE self)
{
    VALUE oPlayer, fTransitionTime;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    oPlayer = argv[0];
    if (argc > 1) fTransitionTime = argv[1];
    else fTransitionTime = rb_float_new(0.0f);
    StackPushFloat(NUM2DBL(fTransitionTime));
    StackPushObject(NUM2UINT(oPlayer));
    VM_ExecuteCommand(750, 2);
    return Qnil;
}

static VALUE NWScript_NightToDay(int argc, VALUE *argv, VALUE self)
{
    VALUE oPlayer, fTransitionTime;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    oPlayer = argv[0];
    if (argc > 1) fTransitionTime = argv[1];
    else fTransitionTime = rb_float_new(0.0f);
    StackPushFloat(NUM2DBL(fTransitionTime));
    StackPushObject(NUM2UINT(oPlayer));
    VM_ExecuteCommand(751, 2);
    return Qnil;
}

static VALUE NWScript_LineOfSightObject(VALUE self, VALUE oSource, VALUE oTarget)
{
    StackPushObject(NUM2UINT(oTarget));
    StackPushObject(NUM2UINT(oSource));
    VM_ExecuteCommand(752, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_LineOfSightVector(VALUE self, VALUE vSource, VALUE vTarget)
{
    Vector *vTarget_ptr;
    Data_Get_Struct(vTarget, Vector, vTarget_ptr);
    StackPushVector(*vTarget_ptr);
    Vector *vSource_ptr;
    Data_Get_Struct(vSource, Vector, vSource_ptr);
    StackPushVector(*vSource_ptr);
    VM_ExecuteCommand(753, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastSpellCastClass(VALUE self)
{
    VM_ExecuteCommand(754, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_SetBaseAttackBonus(int argc, VALUE *argv, VALUE self)
{
    VALUE nBaseAttackBonus, oCreature ;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    nBaseAttackBonus = argv[0];
    if (argc > 1) oCreature  = argv[1];
    else oCreature  = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oCreature));
    StackPushInteger(NUM2INT(nBaseAttackBonus));
    VM_ExecuteCommand(755, 2);
    return Qnil;
}

static VALUE NWScript_RestoreBaseAttackBonus(int argc, VALUE *argv, VALUE self)
{
    VALUE oCreature ;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oCreature  = argv[0];
    else oCreature  = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(756, 1);
    return Qnil;
}

static VALUE NWScript_EffectCutsceneGhost(VALUE self)
{
    VM_ExecuteCommand(757, 0);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyArcaneSpellFailure(VALUE self, VALUE nModLevel)
{
    StackPushInteger(NUM2INT(nModLevel));
    VM_ExecuteCommand(758, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_GetStoreGold(VALUE self, VALUE oidStore)
{
    StackPushObject(NUM2UINT(oidStore));
    VM_ExecuteCommand(759, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_SetStoreGold(VALUE self, VALUE oidStore, VALUE nGold)
{
    StackPushInteger(NUM2INT(nGold));
    StackPushObject(NUM2UINT(oidStore));
    VM_ExecuteCommand(760, 2);
    return Qnil;
}

static VALUE NWScript_GetStoreMaxBuyPrice(VALUE self, VALUE oidStore)
{
    StackPushObject(NUM2UINT(oidStore));
    VM_ExecuteCommand(761, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_SetStoreMaxBuyPrice(VALUE self, VALUE oidStore, VALUE nMaxBuy)
{
    StackPushInteger(NUM2INT(nMaxBuy));
    StackPushObject(NUM2UINT(oidStore));
    VM_ExecuteCommand(762, 2);
    return Qnil;
}

static VALUE NWScript_GetStoreIdentifyCost(VALUE self, VALUE oidStore)
{
    StackPushObject(NUM2UINT(oidStore));
    VM_ExecuteCommand(763, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_SetStoreIdentifyCost(VALUE self, VALUE oidStore, VALUE nCost)
{
    StackPushInteger(NUM2INT(nCost));
    StackPushObject(NUM2UINT(oidStore));
    VM_ExecuteCommand(764, 2);
    return Qnil;
}

static VALUE NWScript_SetCreatureAppearanceType(VALUE self, VALUE oCreature, VALUE nAppearanceType)
{
    StackPushInteger(NUM2INT(nAppearanceType));
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(765, 2);
    return Qnil;
}

static VALUE NWScript_GetCreatureStartingPackage(VALUE self, VALUE oCreature)
{
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(766, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_EffectCutsceneImmobilize(VALUE self)
{
    VM_ExecuteCommand(767, 0);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cEffectClass, 0, free, pRetVal);
}

static VALUE NWScript_GetIsInSubArea(int argc, VALUE *argv, VALUE self)
{
    VALUE oCreature, oSubArea;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    oCreature = argv[0];
    if (argc > 1) oSubArea = argv[1];
    else oSubArea = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oSubArea));
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(768, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetItemPropertyCostTable(VALUE self, VALUE iProp)
{
    CGameEffect *iProp_ptr;
    Data_Get_Struct(iProp, CGameEffect, iProp_ptr);
    StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, iProp_ptr);
    VM_ExecuteCommand(769, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetItemPropertyCostTableValue(VALUE self, VALUE iProp)
{
    CGameEffect *iProp_ptr;
    Data_Get_Struct(iProp, CGameEffect, iProp_ptr);
    StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, iProp_ptr);
    VM_ExecuteCommand(770, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetItemPropertyParam1(VALUE self, VALUE iProp)
{
    CGameEffect *iProp_ptr;
    Data_Get_Struct(iProp, CGameEffect, iProp_ptr);
    StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, iProp_ptr);
    VM_ExecuteCommand(771, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetItemPropertyParam1Value(VALUE self, VALUE iProp)
{
    CGameEffect *iProp_ptr;
    Data_Get_Struct(iProp, CGameEffect, iProp_ptr);
    StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, iProp_ptr);
    VM_ExecuteCommand(772, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetIsCreatureDisarmable(VALUE self, VALUE oCreature)
{
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(773, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_SetStolenFlag(VALUE self, VALUE oItem, VALUE nStolenFlag)
{
    StackPushInteger(NUM2INT(nStolenFlag));
    StackPushObject(NUM2UINT(oItem));
    VM_ExecuteCommand(774, 2);
    return Qnil;
}

static VALUE NWScript_ForceRest(VALUE self, VALUE oCreature)
{
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(775, 1);
    return Qnil;
}

static VALUE NWScript_SetCameraHeight(int argc, VALUE *argv, VALUE self)
{
    VALUE oPlayer, fHeight;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    oPlayer = argv[0];
    if (argc > 1) fHeight = argv[1];
    else fHeight = rb_float_new(0.0f);
    StackPushFloat(NUM2DBL(fHeight));
    StackPushObject(NUM2UINT(oPlayer));
    VM_ExecuteCommand(776, 2);
    return Qnil;
}

static VALUE NWScript_SetSkyBox(int argc, VALUE *argv, VALUE self)
{
    VALUE nSkyBox, oArea;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    nSkyBox = argv[0];
    if (argc > 1) oArea = argv[1];
    else oArea = INT2NUM(OBJECT_INVALID);
    StackPushObject(NUM2UINT(oArea));
    StackPushInteger(NUM2INT(nSkyBox));
    VM_ExecuteCommand(777, 2);
    return Qnil;
}

static VALUE NWScript_GetPhenoType(VALUE self, VALUE oCreature)
{
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(778, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_SetPhenoType(int argc, VALUE *argv, VALUE self)
{
    VALUE nPhenoType, oCreature;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    nPhenoType = argv[0];
    if (argc > 1) oCreature = argv[1];
    else oCreature = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oCreature));
    StackPushInteger(NUM2INT(nPhenoType));
    VM_ExecuteCommand(779, 2);
    return Qnil;
}

static VALUE NWScript_SetFogColor(int argc, VALUE *argv, VALUE self)
{
    VALUE nFogType, nFogColor, oArea;
    if (argc < 2) {
        //TODO: Raise exception
        return Qnil;
    }
    nFogType = argv[0];
    nFogColor = argv[1];
    if (argc > 2) oArea = argv[2];
    else oArea = INT2NUM(OBJECT_INVALID);
    StackPushObject(NUM2UINT(oArea));
    StackPushInteger(NUM2INT(nFogColor));
    StackPushInteger(NUM2INT(nFogType));
    VM_ExecuteCommand(780, 3);
    return Qnil;
}

static VALUE NWScript_GetCutsceneMode(int argc, VALUE *argv, VALUE self)
{
    VALUE oCreature;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oCreature = argv[0];
    else oCreature = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(781, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetSkyBox(int argc, VALUE *argv, VALUE self)
{
    VALUE oArea;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oArea = argv[0];
    else oArea = INT2NUM(OBJECT_INVALID);
    StackPushObject(NUM2UINT(oArea));
    VM_ExecuteCommand(782, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetFogColor(int argc, VALUE *argv, VALUE self)
{
    VALUE nFogType, oArea;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    nFogType = argv[0];
    if (argc > 1) oArea = argv[1];
    else oArea = INT2NUM(OBJECT_INVALID);
    StackPushObject(NUM2UINT(oArea));
    StackPushInteger(NUM2INT(nFogType));
    VM_ExecuteCommand(783, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_SetFogAmount(int argc, VALUE *argv, VALUE self)
{
    VALUE nFogType, nFogAmount, oArea;
    if (argc < 2) {
        //TODO: Raise exception
        return Qnil;
    }
    nFogType = argv[0];
    nFogAmount = argv[1];
    if (argc > 2) oArea = argv[2];
    else oArea = INT2NUM(OBJECT_INVALID);
    StackPushObject(NUM2UINT(oArea));
    StackPushInteger(NUM2INT(nFogAmount));
    StackPushInteger(NUM2INT(nFogType));
    VM_ExecuteCommand(784, 3);
    return Qnil;
}

static VALUE NWScript_GetFogAmount(int argc, VALUE *argv, VALUE self)
{
    VALUE nFogType, oArea;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    nFogType = argv[0];
    if (argc > 1) oArea = argv[1];
    else oArea = INT2NUM(OBJECT_INVALID);
    StackPushObject(NUM2UINT(oArea));
    StackPushInteger(NUM2INT(nFogType));
    VM_ExecuteCommand(785, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetPickpocketableFlag(VALUE self, VALUE oItem)
{
    StackPushObject(NUM2UINT(oItem));
    VM_ExecuteCommand(786, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_SetPickpocketableFlag(VALUE self, VALUE oItem, VALUE bPickpocketable)
{
    StackPushInteger(NUM2INT(bPickpocketable));
    StackPushObject(NUM2UINT(oItem));
    VM_ExecuteCommand(787, 2);
    return Qnil;
}

static VALUE NWScript_GetFootstepType(int argc, VALUE *argv, VALUE self)
{
    VALUE oCreature;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oCreature = argv[0];
    else oCreature = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(788, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_SetFootstepType(int argc, VALUE *argv, VALUE self)
{
    VALUE nFootstepType, oCreature;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    nFootstepType = argv[0];
    if (argc > 1) oCreature = argv[1];
    else oCreature = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oCreature));
    StackPushInteger(NUM2INT(nFootstepType));
    VM_ExecuteCommand(789, 2);
    return Qnil;
}

static VALUE NWScript_GetCreatureWingType(int argc, VALUE *argv, VALUE self)
{
    VALUE oCreature;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oCreature = argv[0];
    else oCreature = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(790, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_SetCreatureWingType(int argc, VALUE *argv, VALUE self)
{
    VALUE nWingType, oCreature;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    nWingType = argv[0];
    if (argc > 1) oCreature = argv[1];
    else oCreature = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oCreature));
    StackPushInteger(NUM2INT(nWingType));
    VM_ExecuteCommand(791, 2);
    return Qnil;
}

static VALUE NWScript_GetCreatureBodyPart(int argc, VALUE *argv, VALUE self)
{
    VALUE nPart, oCreature;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    nPart = argv[0];
    if (argc > 1) oCreature = argv[1];
    else oCreature = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oCreature));
    StackPushInteger(NUM2INT(nPart));
    VM_ExecuteCommand(792, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_SetCreatureBodyPart(int argc, VALUE *argv, VALUE self)
{
    VALUE nPart, nModelNumber, oCreature;
    if (argc < 2) {
        //TODO: Raise exception
        return Qnil;
    }
    nPart = argv[0];
    nModelNumber = argv[1];
    if (argc > 2) oCreature = argv[2];
    else oCreature = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oCreature));
    StackPushInteger(NUM2INT(nModelNumber));
    StackPushInteger(NUM2INT(nPart));
    VM_ExecuteCommand(793, 3);
    return Qnil;
}

static VALUE NWScript_GetCreatureTailType(int argc, VALUE *argv, VALUE self)
{
    VALUE oCreature;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oCreature = argv[0];
    else oCreature = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oCreature));
    VM_ExecuteCommand(794, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_SetCreatureTailType(int argc, VALUE *argv, VALUE self)
{
    VALUE nTailType, oCreature;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    nTailType = argv[0];
    if (argc > 1) oCreature = argv[1];
    else oCreature = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oCreature));
    StackPushInteger(NUM2INT(nTailType));
    VM_ExecuteCommand(795, 2);
    return Qnil;
}

static VALUE NWScript_GetHardness(int argc, VALUE *argv, VALUE self)
{
    VALUE oObject;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oObject = argv[0];
    else oObject = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oObject));
    VM_ExecuteCommand(796, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_SetHardness(int argc, VALUE *argv, VALUE self)
{
    VALUE nHardness, oObject;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    nHardness = argv[0];
    if (argc > 1) oObject = argv[1];
    else oObject = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oObject));
    StackPushInteger(NUM2INT(nHardness));
    VM_ExecuteCommand(797, 2);
    return Qnil;
}

static VALUE NWScript_SetLockKeyRequired(int argc, VALUE *argv, VALUE self)
{
    VALUE oObject, nKeyRequired;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    oObject = argv[0];
    if (argc > 1) nKeyRequired = argv[1];
    else nKeyRequired = INT2NUM(TRUE);
    StackPushInteger(NUM2INT(nKeyRequired));
    StackPushObject(NUM2UINT(oObject));
    VM_ExecuteCommand(798, 2);
    return Qnil;
}

static VALUE NWScript_SetLockKeyTag(VALUE self, VALUE oObject, VALUE sNewKeyTag)
{
    StackPushString(StringValueCStr(sNewKeyTag));
    StackPushObject(NUM2UINT(oObject));
    VM_ExecuteCommand(799, 2);
    return Qnil;
}

static VALUE NWScript_SetLockLockable(int argc, VALUE *argv, VALUE self)
{
    VALUE oObject, nLockable;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    oObject = argv[0];
    if (argc > 1) nLockable = argv[1];
    else nLockable = INT2NUM(TRUE);
    StackPushInteger(NUM2INT(nLockable));
    StackPushObject(NUM2UINT(oObject));
    VM_ExecuteCommand(800, 2);
    return Qnil;
}

static VALUE NWScript_SetLockUnlockDC(VALUE self, VALUE oObject, VALUE nNewUnlockDC)
{
    StackPushInteger(NUM2INT(nNewUnlockDC));
    StackPushObject(NUM2UINT(oObject));
    VM_ExecuteCommand(801, 2);
    return Qnil;
}

static VALUE NWScript_SetLockLockDC(VALUE self, VALUE oObject, VALUE nNewLockDC)
{
    StackPushInteger(NUM2INT(nNewLockDC));
    StackPushObject(NUM2UINT(oObject));
    VM_ExecuteCommand(802, 2);
    return Qnil;
}

static VALUE NWScript_SetTrapDisarmable(int argc, VALUE *argv, VALUE self)
{
    VALUE oTrapObject, nDisarmable;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    oTrapObject = argv[0];
    if (argc > 1) nDisarmable = argv[1];
    else nDisarmable = INT2NUM(TRUE);
    StackPushInteger(NUM2INT(nDisarmable));
    StackPushObject(NUM2UINT(oTrapObject));
    VM_ExecuteCommand(803, 2);
    return Qnil;
}

static VALUE NWScript_SetTrapDetectable(int argc, VALUE *argv, VALUE self)
{
    VALUE oTrapObject, nDetectable;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    oTrapObject = argv[0];
    if (argc > 1) nDetectable = argv[1];
    else nDetectable = INT2NUM(TRUE);
    StackPushInteger(NUM2INT(nDetectable));
    StackPushObject(NUM2UINT(oTrapObject));
    VM_ExecuteCommand(804, 2);
    return Qnil;
}

static VALUE NWScript_SetTrapOneShot(int argc, VALUE *argv, VALUE self)
{
    VALUE oTrapObject, nOneShot;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    oTrapObject = argv[0];
    if (argc > 1) nOneShot = argv[1];
    else nOneShot = INT2NUM(TRUE);
    StackPushInteger(NUM2INT(nOneShot));
    StackPushObject(NUM2UINT(oTrapObject));
    VM_ExecuteCommand(805, 2);
    return Qnil;
}

static VALUE NWScript_SetTrapKeyTag(VALUE self, VALUE oTrapObject, VALUE sKeyTag)
{
    StackPushString(StringValueCStr(sKeyTag));
    StackPushObject(NUM2UINT(oTrapObject));
    VM_ExecuteCommand(806, 2);
    return Qnil;
}

static VALUE NWScript_SetTrapDisarmDC(VALUE self, VALUE oTrapObject, VALUE nDisarmDC)
{
    StackPushInteger(NUM2INT(nDisarmDC));
    StackPushObject(NUM2UINT(oTrapObject));
    VM_ExecuteCommand(807, 2);
    return Qnil;
}

static VALUE NWScript_SetTrapDetectDC(VALUE self, VALUE oTrapObject, VALUE nDetectDC)
{
    StackPushInteger(NUM2INT(nDetectDC));
    StackPushObject(NUM2UINT(oTrapObject));
    VM_ExecuteCommand(808, 2);
    return Qnil;
}

static VALUE NWScript_CreateTrapAtLocation(int argc, VALUE *argv, VALUE self)
{
    VALUE nTrapType, lLocation, fSize, sTag, nFaction, sOnDisarmScript, sOnTrapTriggeredScript;
    if (argc < 2) {
        //TODO: Raise exception
        return Qnil;
    }
    nTrapType = argv[0];
    lLocation = argv[1];
    if (argc > 2) fSize = argv[2];
    else fSize = rb_float_new(2.0f);
    if (argc > 3) sTag = argv[3];
    else sTag = rb_str_new2("");
    if (argc > 4) nFaction = argv[4];
    else nFaction = INT2NUM(STANDARD_FACTION_HOSTILE);
    if (argc > 5) sOnDisarmScript = argv[5];
    else sOnDisarmScript = rb_str_new2("");
    if (argc > 6) sOnTrapTriggeredScript = argv[6];
    else sOnTrapTriggeredScript = rb_str_new2("");
    StackPushString(StringValueCStr(sOnTrapTriggeredScript));
    StackPushString(StringValueCStr(sOnDisarmScript));
    StackPushInteger(NUM2INT(nFaction));
    StackPushString(StringValueCStr(sTag));
    StackPushFloat(NUM2DBL(fSize));
    CScriptLocation *lLocation_ptr;
    Data_Get_Struct(lLocation, CScriptLocation, lLocation_ptr);
    StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lLocation_ptr);
    StackPushInteger(NUM2INT(nTrapType));
    VM_ExecuteCommand(809, 7);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_CreateTrapOnObject(int argc, VALUE *argv, VALUE self)
{
    VALUE nTrapType, oObject, nFaction, sOnDisarmScript, sOnTrapTriggeredScript;
    if (argc < 2) {
        //TODO: Raise exception
        return Qnil;
    }
    nTrapType = argv[0];
    oObject = argv[1];
    if (argc > 2) nFaction = argv[2];
    else nFaction = INT2NUM(STANDARD_FACTION_HOSTILE);
    if (argc > 3) sOnDisarmScript = argv[3];
    else sOnDisarmScript = rb_str_new2("");
    if (argc > 4) sOnTrapTriggeredScript = argv[4];
    else sOnTrapTriggeredScript = rb_str_new2("");
    StackPushString(StringValueCStr(sOnTrapTriggeredScript));
    StackPushString(StringValueCStr(sOnDisarmScript));
    StackPushInteger(NUM2INT(nFaction));
    StackPushObject(NUM2UINT(oObject));
    StackPushInteger(NUM2INT(nTrapType));
    VM_ExecuteCommand(810, 5);
    return Qnil;
}

static VALUE NWScript_SetWillSavingThrow(VALUE self, VALUE oObject, VALUE nWillSave)
{
    StackPushInteger(NUM2INT(nWillSave));
    StackPushObject(NUM2UINT(oObject));
    VM_ExecuteCommand(811, 2);
    return Qnil;
}

static VALUE NWScript_SetReflexSavingThrow(VALUE self, VALUE oObject, VALUE nReflexSave)
{
    StackPushInteger(NUM2INT(nReflexSave));
    StackPushObject(NUM2UINT(oObject));
    VM_ExecuteCommand(812, 2);
    return Qnil;
}

static VALUE NWScript_SetFortitudeSavingThrow(VALUE self, VALUE oObject, VALUE nFortitudeSave)
{
    StackPushInteger(NUM2INT(nFortitudeSave));
    StackPushObject(NUM2UINT(oObject));
    VM_ExecuteCommand(813, 2);
    return Qnil;
}

static VALUE NWScript_GetTilesetResRef(VALUE self, VALUE oArea)
{
    StackPushObject(NUM2UINT(oArea));
    VM_ExecuteCommand(814, 1);
    char *sRetVal;
    StackPopString(&sRetVal);
    return rb_str_new2(sRetVal);
}

static VALUE NWScript_GetTrapRecoverable(VALUE self, VALUE oTrapObject)
{
    StackPushObject(NUM2UINT(oTrapObject));
    VM_ExecuteCommand(815, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_SetTrapRecoverable(int argc, VALUE *argv, VALUE self)
{
    VALUE oTrapObject, nRecoverable;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    oTrapObject = argv[0];
    if (argc > 1) nRecoverable = argv[1];
    else nRecoverable = INT2NUM(TRUE);
    StackPushInteger(NUM2INT(nRecoverable));
    StackPushObject(NUM2UINT(oTrapObject));
    VM_ExecuteCommand(816, 2);
    return Qnil;
}

static VALUE NWScript_GetModuleXPScale(VALUE self)
{
    VM_ExecuteCommand(817, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_SetModuleXPScale(VALUE self, VALUE nXPScale)
{
    StackPushInteger(NUM2INT(nXPScale));
    VM_ExecuteCommand(818, 1);
    return Qnil;
}

static VALUE NWScript_GetKeyRequiredFeedback(VALUE self, VALUE oObject)
{
    StackPushObject(NUM2UINT(oObject));
    VM_ExecuteCommand(819, 1);
    char *sRetVal;
    StackPopString(&sRetVal);
    return rb_str_new2(sRetVal);
}

static VALUE NWScript_SetKeyRequiredFeedback(VALUE self, VALUE oObject, VALUE sFeedbackMessage)
{
    StackPushString(StringValueCStr(sFeedbackMessage));
    StackPushObject(NUM2UINT(oObject));
    VM_ExecuteCommand(820, 2);
    return Qnil;
}

static VALUE NWScript_GetTrapActive(VALUE self, VALUE oTrapObject)
{
    StackPushObject(NUM2UINT(oTrapObject));
    VM_ExecuteCommand(821, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_SetTrapActive(int argc, VALUE *argv, VALUE self)
{
    VALUE oTrapObject, nActive;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    oTrapObject = argv[0];
    if (argc > 1) nActive = argv[1];
    else nActive = INT2NUM(TRUE);
    StackPushInteger(NUM2INT(nActive));
    StackPushObject(NUM2UINT(oTrapObject));
    VM_ExecuteCommand(822, 2);
    return Qnil;
}

static VALUE NWScript_LockCameraPitch(int argc, VALUE *argv, VALUE self)
{
    VALUE oPlayer, bLocked;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    oPlayer = argv[0];
    if (argc > 1) bLocked = argv[1];
    else bLocked = INT2NUM(TRUE);
    StackPushInteger(NUM2INT(bLocked));
    StackPushObject(NUM2UINT(oPlayer));
    VM_ExecuteCommand(823, 2);
    return Qnil;
}

static VALUE NWScript_LockCameraDistance(int argc, VALUE *argv, VALUE self)
{
    VALUE oPlayer, bLocked;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    oPlayer = argv[0];
    if (argc > 1) bLocked = argv[1];
    else bLocked = INT2NUM(TRUE);
    StackPushInteger(NUM2INT(bLocked));
    StackPushObject(NUM2UINT(oPlayer));
    VM_ExecuteCommand(824, 2);
    return Qnil;
}

static VALUE NWScript_LockCameraDirection(int argc, VALUE *argv, VALUE self)
{
    VALUE oPlayer, bLocked;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    oPlayer = argv[0];
    if (argc > 1) bLocked = argv[1];
    else bLocked = INT2NUM(TRUE);
    StackPushInteger(NUM2INT(bLocked));
    StackPushObject(NUM2UINT(oPlayer));
    VM_ExecuteCommand(825, 2);
    return Qnil;
}

static VALUE NWScript_GetPlaceableLastClickedBy(VALUE self)
{
    VM_ExecuteCommand(826, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetInfiniteFlag(VALUE self, VALUE oItem)
{
    StackPushObject(NUM2UINT(oItem));
    VM_ExecuteCommand(827, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_SetInfiniteFlag(int argc, VALUE *argv, VALUE self)
{
    VALUE oItem, bInfinite;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    oItem = argv[0];
    if (argc > 1) bInfinite = argv[1];
    else bInfinite = INT2NUM(TRUE);
    StackPushInteger(NUM2INT(bInfinite));
    StackPushObject(NUM2UINT(oItem));
    VM_ExecuteCommand(828, 2);
    return Qnil;
}

static VALUE NWScript_GetAreaSize(int argc, VALUE *argv, VALUE self)
{
    VALUE nAreaDimension, oArea;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    nAreaDimension = argv[0];
    if (argc > 1) oArea = argv[1];
    else oArea = INT2NUM(OBJECT_INVALID);
    StackPushObject(NUM2UINT(oArea));
    StackPushInteger(NUM2INT(nAreaDimension));
    VM_ExecuteCommand(829, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_SetName(int argc, VALUE *argv, VALUE self)
{
    VALUE oObject, sNewName;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    oObject = argv[0];
    if (argc > 1) sNewName = argv[1];
    else sNewName = rb_str_new2("");
    StackPushString(StringValueCStr(sNewName));
    StackPushObject(NUM2UINT(oObject));
    VM_ExecuteCommand(830, 2);
    return Qnil;
}

static VALUE NWScript_GetPortraitId(int argc, VALUE *argv, VALUE self)
{
    VALUE oTarget;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oTarget = argv[0];
    else oTarget = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oTarget));
    VM_ExecuteCommand(831, 1);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_SetPortraitId(VALUE self, VALUE oTarget, VALUE nPortraitId)
{
    StackPushInteger(NUM2INT(nPortraitId));
    StackPushObject(NUM2UINT(oTarget));
    VM_ExecuteCommand(832, 2);
    return Qnil;
}

static VALUE NWScript_GetPortraitResRef(int argc, VALUE *argv, VALUE self)
{
    VALUE oTarget;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) oTarget = argv[0];
    else oTarget = INT2NUM(OBJECT_SELF);
    StackPushObject(NUM2UINT(oTarget));
    VM_ExecuteCommand(833, 1);
    char *sRetVal;
    StackPopString(&sRetVal);
    return rb_str_new2(sRetVal);
}

static VALUE NWScript_SetPortraitResRef(VALUE self, VALUE oTarget, VALUE sPortraitResRef)
{
    StackPushString(StringValueCStr(sPortraitResRef));
    StackPushObject(NUM2UINT(oTarget));
    VM_ExecuteCommand(834, 2);
    return Qnil;
}

static VALUE NWScript_SetUseableFlag(VALUE self, VALUE oPlaceable, VALUE nUseableFlag)
{
    StackPushInteger(NUM2INT(nUseableFlag));
    StackPushObject(NUM2UINT(oPlaceable));
    VM_ExecuteCommand(835, 2);
    return Qnil;
}

static VALUE NWScript_GetDescription(int argc, VALUE *argv, VALUE self)
{
    VALUE oObject, bOriginalDescription, bIdentifiedDescription;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    oObject = argv[0];
    if (argc > 1) bOriginalDescription = argv[1];
    else bOriginalDescription = INT2NUM(FALSE);
    if (argc > 2) bIdentifiedDescription = argv[2];
    else bIdentifiedDescription = INT2NUM(TRUE);
    StackPushInteger(NUM2INT(bIdentifiedDescription));
    StackPushInteger(NUM2INT(bOriginalDescription));
    StackPushObject(NUM2UINT(oObject));
    VM_ExecuteCommand(836, 3);
    char *sRetVal;
    StackPopString(&sRetVal);
    return rb_str_new2(sRetVal);
}

static VALUE NWScript_SetDescription(int argc, VALUE *argv, VALUE self)
{
    VALUE oObject, sNewDescription, bIdentifiedDescription;
    if (argc < 1) {
        //TODO: Raise exception
        return Qnil;
    }
    oObject = argv[0];
    if (argc > 1) sNewDescription = argv[1];
    else sNewDescription = rb_str_new2("");
    if (argc > 2) bIdentifiedDescription = argv[2];
    else bIdentifiedDescription = INT2NUM(TRUE);
    StackPushInteger(NUM2INT(bIdentifiedDescription));
    StackPushString(StringValueCStr(sNewDescription));
    StackPushObject(NUM2UINT(oObject));
    VM_ExecuteCommand(837, 3);
    return Qnil;
}

static VALUE NWScript_GetPCChatSpeaker(VALUE self)
{
    VM_ExecuteCommand(838, 0);
    dword nRetVal;
    StackPopObject(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_GetPCChatMessage(VALUE self)
{
    VM_ExecuteCommand(839, 0);
    char *sRetVal;
    StackPopString(&sRetVal);
    return rb_str_new2(sRetVal);
}

static VALUE NWScript_GetPCChatVolume(VALUE self)
{
    VM_ExecuteCommand(840, 0);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_SetPCChatMessage(int argc, VALUE *argv, VALUE self)
{
    VALUE sNewChatMessage;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) sNewChatMessage = argv[0];
    else sNewChatMessage = rb_str_new2("");
    StackPushString(StringValueCStr(sNewChatMessage));
    VM_ExecuteCommand(841, 1);
    return Qnil;
}

static VALUE NWScript_SetPCChatVolume(int argc, VALUE *argv, VALUE self)
{
    VALUE nTalkVolume;
    if (argc < 0) {
        //TODO: Raise exception
        return Qnil;
    }
    if (argc > 0) nTalkVolume = argv[0];
    else nTalkVolume = INT2NUM(TALKVOLUME_TALK);
    StackPushInteger(NUM2INT(nTalkVolume));
    VM_ExecuteCommand(842, 1);
    return Qnil;
}

static VALUE NWScript_GetColor(VALUE self, VALUE oObject, VALUE nColorChannel)
{
    StackPushInteger(NUM2INT(nColorChannel));
    StackPushObject(NUM2UINT(oObject));
    VM_ExecuteCommand(843, 2);
    int nRetVal;
    StackPopInteger(&nRetVal);
    return INT2NUM(nRetVal);
}

static VALUE NWScript_SetColor(VALUE self, VALUE oObject, VALUE nColorChannel, VALUE nColorValue)
{
    StackPushInteger(NUM2INT(nColorValue));
    StackPushInteger(NUM2INT(nColorChannel));
    StackPushObject(NUM2UINT(oObject));
    VM_ExecuteCommand(844, 3);
    return Qnil;
}

static VALUE NWScript_ItemPropertyMaterial(VALUE self, VALUE nMaterialType)
{
    StackPushInteger(NUM2INT(nMaterialType));
    VM_ExecuteCommand(845, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyQuality(VALUE self, VALUE nQuality)
{
    StackPushInteger(NUM2INT(nQuality));
    VM_ExecuteCommand(846, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}

static VALUE NWScript_ItemPropertyAdditional(VALUE self, VALUE nAdditionalProperty)
{
    StackPushInteger(NUM2INT(nAdditionalProperty));
    VM_ExecuteCommand(847, 1);
    CGameEffect *pRetVal;
    StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
    return Data_Wrap_Struct(g_cItemPropertyClass, 0, free, pRetVal);
}





VALUE RubyInt_InitNWScript()
{
    VALUE cNWScript = rb_define_module("NWScript");
    rb_define_module_function(cNWScript, "Random", NWScript_Random, 1);
    rb_define_module_function(cNWScript, "PrintString", NWScript_PrintString, 1);
    rb_define_module_function(cNWScript, "PrintFloat", NWScript_PrintFloat, -1);
    rb_define_module_function(cNWScript, "FloatToString", NWScript_FloatToString, -1);
    rb_define_module_function(cNWScript, "PrintInteger", NWScript_PrintInteger, 1);
    rb_define_module_function(cNWScript, "PrintObject", NWScript_PrintObject, 1);
    //rb_define_module_function(cNWScript, "AssignCommand", NWScript_AssignCommand, 2);
    rb_define_module_function(cNWScript, "DelayCommand", NWScript_DelayCommand, 2);
    rb_define_module_function(cNWScript, "ExecuteScript", NWScript_ExecuteScript, 2);
    rb_define_module_function(cNWScript, "ClearAllActions", NWScript_ClearAllActions, -1);
    rb_define_module_function(cNWScript, "SetFacing", NWScript_SetFacing, 1);
    rb_define_module_function(cNWScript, "SetCalendar", NWScript_SetCalendar, 3);
    rb_define_module_function(cNWScript, "SetTime", NWScript_SetTime, 4);
    rb_define_module_function(cNWScript, "GetCalendarYear", NWScript_GetCalendarYear, 0);
    rb_define_module_function(cNWScript, "GetCalendarMonth", NWScript_GetCalendarMonth, 0);
    rb_define_module_function(cNWScript, "GetCalendarDay", NWScript_GetCalendarDay, 0);
    rb_define_module_function(cNWScript, "GetTimeHour", NWScript_GetTimeHour, 0);
    rb_define_module_function(cNWScript, "GetTimeMinute", NWScript_GetTimeMinute, 0);
    rb_define_module_function(cNWScript, "GetTimeSecond", NWScript_GetTimeSecond, 0);
    rb_define_module_function(cNWScript, "GetTimeMillisecond", NWScript_GetTimeMillisecond, 0);
    rb_define_module_function(cNWScript, "ActionRandomWalk", NWScript_ActionRandomWalk, 0);
    rb_define_module_function(cNWScript, "ActionMoveToLocation", NWScript_ActionMoveToLocation, -1);
    rb_define_module_function(cNWScript, "ActionMoveToObject", NWScript_ActionMoveToObject, -1);
    rb_define_module_function(cNWScript, "ActionMoveAwayFromObject", NWScript_ActionMoveAwayFromObject, -1);
    rb_define_module_function(cNWScript, "GetArea", NWScript_GetArea, 1);
    rb_define_module_function(cNWScript, "GetEnteringObject", NWScript_GetEnteringObject, 0);
    rb_define_module_function(cNWScript, "GetExitingObject", NWScript_GetExitingObject, 0);
    rb_define_module_function(cNWScript, "GetPosition", NWScript_GetPosition, 1);
    rb_define_module_function(cNWScript, "GetFacing", NWScript_GetFacing, 1);
    rb_define_module_function(cNWScript, "GetItemPossessor", NWScript_GetItemPossessor, 1);
    rb_define_module_function(cNWScript, "GetItemPossessedBy", NWScript_GetItemPossessedBy, 2);
    rb_define_module_function(cNWScript, "CreateItemOnObject", NWScript_CreateItemOnObject, -1);
    rb_define_module_function(cNWScript, "ActionEquipItem", NWScript_ActionEquipItem, 2);
    rb_define_module_function(cNWScript, "ActionUnequipItem", NWScript_ActionUnequipItem, 1);
    rb_define_module_function(cNWScript, "ActionPickUpItem", NWScript_ActionPickUpItem, 1);
    rb_define_module_function(cNWScript, "ActionPutDownItem", NWScript_ActionPutDownItem, 1);
    rb_define_module_function(cNWScript, "GetLastAttacker", NWScript_GetLastAttacker, -1);
    rb_define_module_function(cNWScript, "ActionAttack", NWScript_ActionAttack, -1);
    rb_define_module_function(cNWScript, "GetNearestCreature", NWScript_GetNearestCreature, -1);
    rb_define_module_function(cNWScript, "ActionSpeakString", NWScript_ActionSpeakString, -1);
    rb_define_module_function(cNWScript, "ActionPlayAnimation", NWScript_ActionPlayAnimation, -1);
    rb_define_module_function(cNWScript, "GetDistanceToObject", NWScript_GetDistanceToObject, 1);
    rb_define_module_function(cNWScript, "GetIsObjectValid", NWScript_GetIsObjectValid, 1);
    rb_define_module_function(cNWScript, "ActionOpenDoor", NWScript_ActionOpenDoor, 1);
    rb_define_module_function(cNWScript, "ActionCloseDoor", NWScript_ActionCloseDoor, 1);
    rb_define_module_function(cNWScript, "SetCameraFacing", NWScript_SetCameraFacing, -1);
    rb_define_module_function(cNWScript, "PlaySound", NWScript_PlaySound, 1);
    rb_define_module_function(cNWScript, "GetSpellTargetObject", NWScript_GetSpellTargetObject, 0);
    rb_define_module_function(cNWScript, "ActionCastSpellAtObject", NWScript_ActionCastSpellAtObject, -1);
    rb_define_module_function(cNWScript, "GetCurrentHitPoints", NWScript_GetCurrentHitPoints, -1);
    rb_define_module_function(cNWScript, "GetMaxHitPoints", NWScript_GetMaxHitPoints, -1);
    rb_define_module_function(cNWScript, "GetLocalInt", NWScript_GetLocalInt, 2);
    rb_define_module_function(cNWScript, "GetLocalFloat", NWScript_GetLocalFloat, 2);
    rb_define_module_function(cNWScript, "GetLocalString", NWScript_GetLocalString, 2);
    rb_define_module_function(cNWScript, "GetLocalObject", NWScript_GetLocalObject, 2);
    rb_define_module_function(cNWScript, "SetLocalInt", NWScript_SetLocalInt, 3);
    rb_define_module_function(cNWScript, "SetLocalFloat", NWScript_SetLocalFloat, 3);
    rb_define_module_function(cNWScript, "SetLocalString", NWScript_SetLocalString, 3);
    rb_define_module_function(cNWScript, "SetLocalObject", NWScript_SetLocalObject, 3);
    rb_define_module_function(cNWScript, "GetStringLength", NWScript_GetStringLength, 1);
    rb_define_module_function(cNWScript, "GetStringUpperCase", NWScript_GetStringUpperCase, 1);
    rb_define_module_function(cNWScript, "GetStringLowerCase", NWScript_GetStringLowerCase, 1);
    rb_define_module_function(cNWScript, "GetStringRight", NWScript_GetStringRight, 2);
    rb_define_module_function(cNWScript, "GetStringLeft", NWScript_GetStringLeft, 2);
    rb_define_module_function(cNWScript, "InsertString", NWScript_InsertString, 3);
    rb_define_module_function(cNWScript, "GetSubString", NWScript_GetSubString, 3);
    rb_define_module_function(cNWScript, "FindSubString", NWScript_FindSubString, -1);
    rb_define_module_function(cNWScript, "fabs", NWScript_fabs, 1);
    rb_define_module_function(cNWScript, "cos", NWScript_cos, 1);
    rb_define_module_function(cNWScript, "sin", NWScript_sin, 1);
    rb_define_module_function(cNWScript, "tan", NWScript_tan, 1);
    rb_define_module_function(cNWScript, "acos", NWScript_acos, 1);
    rb_define_module_function(cNWScript, "asin", NWScript_asin, 1);
    rb_define_module_function(cNWScript, "atan", NWScript_atan, 1);
    rb_define_module_function(cNWScript, "log", NWScript_log, 1);
    rb_define_module_function(cNWScript, "pow", NWScript_pow, 2);
    rb_define_module_function(cNWScript, "sqrt", NWScript_sqrt, 1);
    rb_define_module_function(cNWScript, "abs", NWScript_abs, 1);
    rb_define_module_function(cNWScript, "EffectHeal", NWScript_EffectHeal, 1);
    rb_define_module_function(cNWScript, "EffectDamage", NWScript_EffectDamage, -1);
    rb_define_module_function(cNWScript, "EffectAbilityIncrease", NWScript_EffectAbilityIncrease, 2);
    rb_define_module_function(cNWScript, "EffectDamageResistance", NWScript_EffectDamageResistance, -1);
    rb_define_module_function(cNWScript, "EffectResurrection", NWScript_EffectResurrection, 0);
    rb_define_module_function(cNWScript, "EffectSummonCreature", NWScript_EffectSummonCreature, -1);
    rb_define_module_function(cNWScript, "GetCasterLevel", NWScript_GetCasterLevel, 1);
    rb_define_module_function(cNWScript, "GetFirstEffect", NWScript_GetFirstEffect, 1);
    rb_define_module_function(cNWScript, "GetNextEffect", NWScript_GetNextEffect, 1);
    rb_define_module_function(cNWScript, "RemoveEffect", NWScript_RemoveEffect, 2);
    rb_define_module_function(cNWScript, "GetIsEffectValid", NWScript_GetIsEffectValid, 1);
    rb_define_module_function(cNWScript, "GetEffectDurationType", NWScript_GetEffectDurationType, 1);
    rb_define_module_function(cNWScript, "GetEffectSubType", NWScript_GetEffectSubType, 1);
    rb_define_module_function(cNWScript, "GetEffectCreator", NWScript_GetEffectCreator, 1);
    rb_define_module_function(cNWScript, "IntToString", NWScript_IntToString, 1);
    rb_define_module_function(cNWScript, "GetFirstObjectInArea", NWScript_GetFirstObjectInArea, -1);
    rb_define_module_function(cNWScript, "GetNextObjectInArea", NWScript_GetNextObjectInArea, -1);
    rb_define_module_function(cNWScript, "d2", NWScript_d2, -1);
    rb_define_module_function(cNWScript, "d3", NWScript_d3, -1);
    rb_define_module_function(cNWScript, "d4", NWScript_d4, -1);
    rb_define_module_function(cNWScript, "d6", NWScript_d6, -1);
    rb_define_module_function(cNWScript, "d8", NWScript_d8, -1);
    rb_define_module_function(cNWScript, "d10", NWScript_d10, -1);
    rb_define_module_function(cNWScript, "d12", NWScript_d12, -1);
    rb_define_module_function(cNWScript, "d20", NWScript_d20, -1);
    rb_define_module_function(cNWScript, "d100", NWScript_d100, -1);
    rb_define_module_function(cNWScript, "VectorMagnitude", NWScript_VectorMagnitude, 1);
    rb_define_module_function(cNWScript, "GetMetaMagicFeat", NWScript_GetMetaMagicFeat, 0);
    rb_define_module_function(cNWScript, "GetObjectType", NWScript_GetObjectType, 1);
    rb_define_module_function(cNWScript, "GetRacialType", NWScript_GetRacialType, 1);
    rb_define_module_function(cNWScript, "FortitudeSave", NWScript_FortitudeSave, -1);
    rb_define_module_function(cNWScript, "ReflexSave", NWScript_ReflexSave, -1);
    rb_define_module_function(cNWScript, "WillSave", NWScript_WillSave, -1);
    rb_define_module_function(cNWScript, "GetSpellSaveDC", NWScript_GetSpellSaveDC, 0);
    rb_define_module_function(cNWScript, "MagicalEffect", NWScript_MagicalEffect, 1);
    rb_define_module_function(cNWScript, "SupernaturalEffect", NWScript_SupernaturalEffect, 1);
    rb_define_module_function(cNWScript, "ExtraordinaryEffect", NWScript_ExtraordinaryEffect, 1);
    rb_define_module_function(cNWScript, "EffectACIncrease", NWScript_EffectACIncrease, -1);
    rb_define_module_function(cNWScript, "GetAC", NWScript_GetAC, -1);
    rb_define_module_function(cNWScript, "EffectSavingThrowIncrease", NWScript_EffectSavingThrowIncrease, -1);
    rb_define_module_function(cNWScript, "EffectAttackIncrease", NWScript_EffectAttackIncrease, -1);
    rb_define_module_function(cNWScript, "EffectDamageReduction", NWScript_EffectDamageReduction, -1);
    rb_define_module_function(cNWScript, "EffectDamageIncrease", NWScript_EffectDamageIncrease, -1);
    rb_define_module_function(cNWScript, "RoundsToSeconds", NWScript_RoundsToSeconds, 1);
    rb_define_module_function(cNWScript, "HoursToSeconds", NWScript_HoursToSeconds, 1);
    rb_define_module_function(cNWScript, "TurnsToSeconds", NWScript_TurnsToSeconds, 1);
    rb_define_module_function(cNWScript, "GetLawChaosValue", NWScript_GetLawChaosValue, 1);
    rb_define_module_function(cNWScript, "GetGoodEvilValue", NWScript_GetGoodEvilValue, 1);
    rb_define_module_function(cNWScript, "GetAlignmentLawChaos", NWScript_GetAlignmentLawChaos, 1);
    rb_define_module_function(cNWScript, "GetAlignmentGoodEvil", NWScript_GetAlignmentGoodEvil, 1);
    rb_define_module_function(cNWScript, "EffectEntangle", NWScript_EffectEntangle, 0);
    rb_define_module_function(cNWScript, "SignalEvent", NWScript_SignalEvent, 2);
    rb_define_module_function(cNWScript, "EventUserDefined", NWScript_EventUserDefined, 1);
    rb_define_module_function(cNWScript, "EffectDeath", NWScript_EffectDeath, -1);
    rb_define_module_function(cNWScript, "EffectKnockdown", NWScript_EffectKnockdown, 0);
    rb_define_module_function(cNWScript, "ActionGiveItem", NWScript_ActionGiveItem, 2);
    rb_define_module_function(cNWScript, "ActionTakeItem", NWScript_ActionTakeItem, 2);
    rb_define_module_function(cNWScript, "VectorNormalize", NWScript_VectorNormalize, 1);
    rb_define_module_function(cNWScript, "EffectCurse", NWScript_EffectCurse, -1);
    rb_define_module_function(cNWScript, "GetAbilityScore", NWScript_GetAbilityScore, -1);
    rb_define_module_function(cNWScript, "GetIsDead", NWScript_GetIsDead, 1);
    rb_define_module_function(cNWScript, "PrintVector", NWScript_PrintVector, 2);
    rb_define_module_function(cNWScript, "Vector", NWScript_Vector, -1);
    rb_define_module_function(cNWScript, "SetFacingPoint", NWScript_SetFacingPoint, 1);
    rb_define_module_function(cNWScript, "AngleToVector", NWScript_AngleToVector, 1);
    rb_define_module_function(cNWScript, "VectorToAngle", NWScript_VectorToAngle, 1);
    rb_define_module_function(cNWScript, "TouchAttackMelee", NWScript_TouchAttackMelee, -1);
    rb_define_module_function(cNWScript, "TouchAttackRanged", NWScript_TouchAttackRanged, -1);
    rb_define_module_function(cNWScript, "EffectParalyze", NWScript_EffectParalyze, 0);
    rb_define_module_function(cNWScript, "EffectSpellImmunity", NWScript_EffectSpellImmunity, -1);
    rb_define_module_function(cNWScript, "EffectDeaf", NWScript_EffectDeaf, 0);
    rb_define_module_function(cNWScript, "GetDistanceBetween", NWScript_GetDistanceBetween, 2);
    rb_define_module_function(cNWScript, "SetLocalLocation", NWScript_SetLocalLocation, 3);
    rb_define_module_function(cNWScript, "GetLocalLocation", NWScript_GetLocalLocation, 2);
    rb_define_module_function(cNWScript, "EffectSleep", NWScript_EffectSleep, 0);
    rb_define_module_function(cNWScript, "GetItemInSlot", NWScript_GetItemInSlot, -1);
    rb_define_module_function(cNWScript, "EffectCharmed", NWScript_EffectCharmed, 0);
    rb_define_module_function(cNWScript, "EffectConfused", NWScript_EffectConfused, 0);
    rb_define_module_function(cNWScript, "EffectFrightened", NWScript_EffectFrightened, 0);
    rb_define_module_function(cNWScript, "EffectDominated", NWScript_EffectDominated, 0);
    rb_define_module_function(cNWScript, "EffectDazed", NWScript_EffectDazed, 0);
    rb_define_module_function(cNWScript, "EffectStunned", NWScript_EffectStunned, 0);
    rb_define_module_function(cNWScript, "SetCommandable", NWScript_SetCommandable, -1);
    rb_define_module_function(cNWScript, "GetCommandable", NWScript_GetCommandable, -1);
    rb_define_module_function(cNWScript, "EffectRegenerate", NWScript_EffectRegenerate, 2);
    rb_define_module_function(cNWScript, "EffectMovementSpeedIncrease", NWScript_EffectMovementSpeedIncrease, 1);
    rb_define_module_function(cNWScript, "GetHitDice", NWScript_GetHitDice, 1);
    rb_define_module_function(cNWScript, "ActionForceFollowObject", NWScript_ActionForceFollowObject, -1);
    rb_define_module_function(cNWScript, "GetTag", NWScript_GetTag, 1);
    rb_define_module_function(cNWScript, "ResistSpell", NWScript_ResistSpell, 2);
    rb_define_module_function(cNWScript, "GetEffectType", NWScript_GetEffectType, 1);
    rb_define_module_function(cNWScript, "EffectAreaOfEffect", NWScript_EffectAreaOfEffect, -1);
    rb_define_module_function(cNWScript, "GetFactionEqual", NWScript_GetFactionEqual, -1);
    rb_define_module_function(cNWScript, "ChangeFaction", NWScript_ChangeFaction, 2);
    rb_define_module_function(cNWScript, "GetIsListening", NWScript_GetIsListening, 1);
    rb_define_module_function(cNWScript, "SetListening", NWScript_SetListening, 2);
    rb_define_module_function(cNWScript, "SetListenPattern", NWScript_SetListenPattern, -1);
    rb_define_module_function(cNWScript, "TestStringAgainstPattern", NWScript_TestStringAgainstPattern, 2);
    rb_define_module_function(cNWScript, "GetMatchedSubstring", NWScript_GetMatchedSubstring, 1);
    rb_define_module_function(cNWScript, "GetMatchedSubstringsCount", NWScript_GetMatchedSubstringsCount, 0);
    rb_define_module_function(cNWScript, "EffectVisualEffect", NWScript_EffectVisualEffect, -1);
    rb_define_module_function(cNWScript, "GetFactionWeakestMember", NWScript_GetFactionWeakestMember, -1);
    rb_define_module_function(cNWScript, "GetFactionStrongestMember", NWScript_GetFactionStrongestMember, -1);
    rb_define_module_function(cNWScript, "GetFactionMostDamagedMember", NWScript_GetFactionMostDamagedMember, -1);
    rb_define_module_function(cNWScript, "GetFactionLeastDamagedMember", NWScript_GetFactionLeastDamagedMember, -1);
    rb_define_module_function(cNWScript, "GetFactionGold", NWScript_GetFactionGold, 1);
    rb_define_module_function(cNWScript, "GetFactionAverageReputation", NWScript_GetFactionAverageReputation, 2);
    rb_define_module_function(cNWScript, "GetFactionAverageGoodEvilAlignment", NWScript_GetFactionAverageGoodEvilAlignment, 1);
    rb_define_module_function(cNWScript, "GetFactionAverageLawChaosAlignment", NWScript_GetFactionAverageLawChaosAlignment, 1);
    rb_define_module_function(cNWScript, "GetFactionAverageLevel", NWScript_GetFactionAverageLevel, 1);
    rb_define_module_function(cNWScript, "GetFactionAverageXP", NWScript_GetFactionAverageXP, 1);
    rb_define_module_function(cNWScript, "GetFactionMostFrequentClass", NWScript_GetFactionMostFrequentClass, 1);
    rb_define_module_function(cNWScript, "GetFactionWorstAC", NWScript_GetFactionWorstAC, -1);
    rb_define_module_function(cNWScript, "GetFactionBestAC", NWScript_GetFactionBestAC, -1);
    rb_define_module_function(cNWScript, "ActionSit", NWScript_ActionSit, 1);
    rb_define_module_function(cNWScript, "GetListenPatternNumber", NWScript_GetListenPatternNumber, 0);
    rb_define_module_function(cNWScript, "ActionJumpToObject", NWScript_ActionJumpToObject, -1);
    rb_define_module_function(cNWScript, "GetWaypointByTag", NWScript_GetWaypointByTag, 1);
    rb_define_module_function(cNWScript, "GetTransitionTarget", NWScript_GetTransitionTarget, 1);
    rb_define_module_function(cNWScript, "EffectLinkEffects", NWScript_EffectLinkEffects, 2);
    rb_define_module_function(cNWScript, "GetObjectByTag", NWScript_GetObjectByTag, -1);
    rb_define_module_function(cNWScript, "AdjustAlignment", NWScript_AdjustAlignment, -1);
    rb_define_module_function(cNWScript, "ActionWait", NWScript_ActionWait, 1);
    rb_define_module_function(cNWScript, "SetAreaTransitionBMP", NWScript_SetAreaTransitionBMP, -1);
    rb_define_module_function(cNWScript, "ActionStartConversation", NWScript_ActionStartConversation, -1);
    rb_define_module_function(cNWScript, "ActionPauseConversation", NWScript_ActionPauseConversation, 0);
    rb_define_module_function(cNWScript, "ActionResumeConversation", NWScript_ActionResumeConversation, 0);
    rb_define_module_function(cNWScript, "EffectBeam", NWScript_EffectBeam, -1);
    rb_define_module_function(cNWScript, "GetReputation", NWScript_GetReputation, 2);
    rb_define_module_function(cNWScript, "AdjustReputation", NWScript_AdjustReputation, 3);
    rb_define_module_function(cNWScript, "GetSittingCreature", NWScript_GetSittingCreature, 1);
    rb_define_module_function(cNWScript, "GetGoingToBeAttackedBy", NWScript_GetGoingToBeAttackedBy, 1);
    rb_define_module_function(cNWScript, "EffectSpellResistanceIncrease", NWScript_EffectSpellResistanceIncrease, 1);
    rb_define_module_function(cNWScript, "GetLocation", NWScript_GetLocation, 1);
    rb_define_module_function(cNWScript, "ActionJumpToLocation", NWScript_ActionJumpToLocation, 1);
    rb_define_module_function(cNWScript, "Location", NWScript_Location, 3);
    rb_define_module_function(cNWScript, "ApplyEffectAtLocation", NWScript_ApplyEffectAtLocation, -1);
    rb_define_module_function(cNWScript, "GetIsPC", NWScript_GetIsPC, 1);
    rb_define_module_function(cNWScript, "FeetToMeters", NWScript_FeetToMeters, 1);
    rb_define_module_function(cNWScript, "YardsToMeters", NWScript_YardsToMeters, 1);
    rb_define_module_function(cNWScript, "ApplyEffectToObject", NWScript_ApplyEffectToObject, -1);
    rb_define_module_function(cNWScript, "SpeakString", NWScript_SpeakString, -1);
    rb_define_module_function(cNWScript, "GetSpellTargetLocation", NWScript_GetSpellTargetLocation, 0);
    rb_define_module_function(cNWScript, "GetPositionFromLocation", NWScript_GetPositionFromLocation, 1);
    rb_define_module_function(cNWScript, "GetAreaFromLocation", NWScript_GetAreaFromLocation, 1);
    rb_define_module_function(cNWScript, "GetFacingFromLocation", NWScript_GetFacingFromLocation, 1);
    rb_define_module_function(cNWScript, "GetNearestCreatureToLocation", NWScript_GetNearestCreatureToLocation, -1);
    rb_define_module_function(cNWScript, "GetNearestObject", NWScript_GetNearestObject, -1);
    rb_define_module_function(cNWScript, "GetNearestObjectToLocation", NWScript_GetNearestObjectToLocation, -1);
    rb_define_module_function(cNWScript, "GetNearestObjectByTag", NWScript_GetNearestObjectByTag, -1);
    rb_define_module_function(cNWScript, "IntToFloat", NWScript_IntToFloat, 1);
    rb_define_module_function(cNWScript, "FloatToInt", NWScript_FloatToInt, 1);
    rb_define_module_function(cNWScript, "StringToInt", NWScript_StringToInt, 1);
    rb_define_module_function(cNWScript, "StringToFloat", NWScript_StringToFloat, 1);
    rb_define_module_function(cNWScript, "ActionCastSpellAtLocation", NWScript_ActionCastSpellAtLocation, -1);
    rb_define_module_function(cNWScript, "GetIsEnemy", NWScript_GetIsEnemy, -1);
    rb_define_module_function(cNWScript, "GetIsFriend", NWScript_GetIsFriend, -1);
    rb_define_module_function(cNWScript, "GetIsNeutral", NWScript_GetIsNeutral, -1);
    rb_define_module_function(cNWScript, "GetPCSpeaker", NWScript_GetPCSpeaker, 0);
    rb_define_module_function(cNWScript, "GetStringByStrRef", NWScript_GetStringByStrRef, -1);
    rb_define_module_function(cNWScript, "ActionSpeakStringByStrRef", NWScript_ActionSpeakStringByStrRef, -1);
    rb_define_module_function(cNWScript, "DestroyObject", NWScript_DestroyObject, -1);
    rb_define_module_function(cNWScript, "GetModule", NWScript_GetModule, 0);
    rb_define_module_function(cNWScript, "CreateObject", NWScript_CreateObject, -1);
    rb_define_module_function(cNWScript, "EventSpellCastAt", NWScript_EventSpellCastAt, -1);
    rb_define_module_function(cNWScript, "GetLastSpellCaster", NWScript_GetLastSpellCaster, 0);
    rb_define_module_function(cNWScript, "GetLastSpell", NWScript_GetLastSpell, 0);
    rb_define_module_function(cNWScript, "GetUserDefinedEventNumber", NWScript_GetUserDefinedEventNumber, 0);
    rb_define_module_function(cNWScript, "GetSpellId", NWScript_GetSpellId, 0);
    rb_define_module_function(cNWScript, "RandomName", NWScript_RandomName, -1);
    rb_define_module_function(cNWScript, "EffectPoison", NWScript_EffectPoison, 1);
    rb_define_module_function(cNWScript, "EffectDisease", NWScript_EffectDisease, 1);
    rb_define_module_function(cNWScript, "EffectSilence", NWScript_EffectSilence, 0);
    rb_define_module_function(cNWScript, "GetName", NWScript_GetName, -1);
    rb_define_module_function(cNWScript, "GetLastSpeaker", NWScript_GetLastSpeaker, 0);
    rb_define_module_function(cNWScript, "BeginConversation", NWScript_BeginConversation, -1);
    rb_define_module_function(cNWScript, "GetLastPerceived", NWScript_GetLastPerceived, 0);
    rb_define_module_function(cNWScript, "GetLastPerceptionHeard", NWScript_GetLastPerceptionHeard, 0);
    rb_define_module_function(cNWScript, "GetLastPerceptionInaudible", NWScript_GetLastPerceptionInaudible, 0);
    rb_define_module_function(cNWScript, "GetLastPerceptionSeen", NWScript_GetLastPerceptionSeen, 0);
    rb_define_module_function(cNWScript, "GetLastClosedBy", NWScript_GetLastClosedBy, 0);
    rb_define_module_function(cNWScript, "GetLastPerceptionVanished", NWScript_GetLastPerceptionVanished, 0);
    rb_define_module_function(cNWScript, "GetFirstInPersistentObject", NWScript_GetFirstInPersistentObject, -1);
    rb_define_module_function(cNWScript, "GetNextInPersistentObject", NWScript_GetNextInPersistentObject, -1);
    rb_define_module_function(cNWScript, "GetAreaOfEffectCreator", NWScript_GetAreaOfEffectCreator, -1);
    rb_define_module_function(cNWScript, "DeleteLocalInt", NWScript_DeleteLocalInt, 2);
    rb_define_module_function(cNWScript, "DeleteLocalFloat", NWScript_DeleteLocalFloat, 2);
    rb_define_module_function(cNWScript, "DeleteLocalString", NWScript_DeleteLocalString, 2);
    rb_define_module_function(cNWScript, "DeleteLocalObject", NWScript_DeleteLocalObject, 2);
    rb_define_module_function(cNWScript, "DeleteLocalLocation", NWScript_DeleteLocalLocation, 2);
    rb_define_module_function(cNWScript, "EffectHaste", NWScript_EffectHaste, 0);
    rb_define_module_function(cNWScript, "EffectSlow", NWScript_EffectSlow, 0);
    rb_define_module_function(cNWScript, "ObjectToString", NWScript_ObjectToString, 1);
    rb_define_module_function(cNWScript, "EffectImmunity", NWScript_EffectImmunity, 1);
    rb_define_module_function(cNWScript, "GetIsImmune", NWScript_GetIsImmune, -1);
    rb_define_module_function(cNWScript, "EffectDamageImmunityIncrease", NWScript_EffectDamageImmunityIncrease, 2);
    rb_define_module_function(cNWScript, "GetEncounterActive", NWScript_GetEncounterActive, -1);
    rb_define_module_function(cNWScript, "SetEncounterActive", NWScript_SetEncounterActive, -1);
    rb_define_module_function(cNWScript, "GetEncounterSpawnsMax", NWScript_GetEncounterSpawnsMax, -1);
    rb_define_module_function(cNWScript, "SetEncounterSpawnsMax", NWScript_SetEncounterSpawnsMax, -1);
    rb_define_module_function(cNWScript, "GetEncounterSpawnsCurrent", NWScript_GetEncounterSpawnsCurrent, -1);
    rb_define_module_function(cNWScript, "SetEncounterSpawnsCurrent", NWScript_SetEncounterSpawnsCurrent, -1);
    rb_define_module_function(cNWScript, "GetModuleItemAcquired", NWScript_GetModuleItemAcquired, 0);
    rb_define_module_function(cNWScript, "GetModuleItemAcquiredFrom", NWScript_GetModuleItemAcquiredFrom, 0);
    rb_define_module_function(cNWScript, "SetCustomToken", NWScript_SetCustomToken, 2);
    rb_define_module_function(cNWScript, "GetHasFeat", NWScript_GetHasFeat, -1);
    rb_define_module_function(cNWScript, "GetHasSkill", NWScript_GetHasSkill, -1);
    rb_define_module_function(cNWScript, "ActionUseFeat", NWScript_ActionUseFeat, 2);
    rb_define_module_function(cNWScript, "ActionUseSkill", NWScript_ActionUseSkill, -1);
    rb_define_module_function(cNWScript, "GetObjectSeen", NWScript_GetObjectSeen, -1);
    rb_define_module_function(cNWScript, "GetObjectHeard", NWScript_GetObjectHeard, -1);
    rb_define_module_function(cNWScript, "GetLastPlayerDied", NWScript_GetLastPlayerDied, 0);
    rb_define_module_function(cNWScript, "GetModuleItemLost", NWScript_GetModuleItemLost, 0);
    rb_define_module_function(cNWScript, "GetModuleItemLostBy", NWScript_GetModuleItemLostBy, 0);
    rb_define_module_function(cNWScript, "ActionDoCommand", NWScript_ActionDoCommand, 1);
    rb_define_module_function(cNWScript, "EventConversation", NWScript_EventConversation, 0);
    rb_define_module_function(cNWScript, "SetEncounterDifficulty", NWScript_SetEncounterDifficulty, -1);
    rb_define_module_function(cNWScript, "GetEncounterDifficulty", NWScript_GetEncounterDifficulty, -1);
    rb_define_module_function(cNWScript, "GetDistanceBetweenLocations", NWScript_GetDistanceBetweenLocations, 2);
    rb_define_module_function(cNWScript, "GetReflexAdjustedDamage", NWScript_GetReflexAdjustedDamage, -1);
    rb_define_module_function(cNWScript, "PlayAnimation", NWScript_PlayAnimation, -1);
    rb_define_module_function(cNWScript, "TalentSpell", NWScript_TalentSpell, 1);
    rb_define_module_function(cNWScript, "TalentFeat", NWScript_TalentFeat, 1);
    rb_define_module_function(cNWScript, "TalentSkill", NWScript_TalentSkill, 1);
    rb_define_module_function(cNWScript, "GetHasSpellEffect", NWScript_GetHasSpellEffect, -1);
    rb_define_module_function(cNWScript, "GetEffectSpellId", NWScript_GetEffectSpellId, 1);
    rb_define_module_function(cNWScript, "GetCreatureHasTalent", NWScript_GetCreatureHasTalent, -1);
    rb_define_module_function(cNWScript, "GetCreatureTalentRandom", NWScript_GetCreatureTalentRandom, -1);
    rb_define_module_function(cNWScript, "GetCreatureTalentBest", NWScript_GetCreatureTalentBest, -1);
    rb_define_module_function(cNWScript, "ActionUseTalentOnObject", NWScript_ActionUseTalentOnObject, 2);
    rb_define_module_function(cNWScript, "ActionUseTalentAtLocation", NWScript_ActionUseTalentAtLocation, 2);
    rb_define_module_function(cNWScript, "GetGoldPieceValue", NWScript_GetGoldPieceValue, 1);
    rb_define_module_function(cNWScript, "GetIsPlayableRacialType", NWScript_GetIsPlayableRacialType, 1);
    rb_define_module_function(cNWScript, "JumpToLocation", NWScript_JumpToLocation, 1);
    rb_define_module_function(cNWScript, "EffectTemporaryHitpoints", NWScript_EffectTemporaryHitpoints, 1);
    rb_define_module_function(cNWScript, "GetSkillRank", NWScript_GetSkillRank, -1);
    rb_define_module_function(cNWScript, "GetAttackTarget", NWScript_GetAttackTarget, -1);
    rb_define_module_function(cNWScript, "GetLastAttackType", NWScript_GetLastAttackType, -1);
    rb_define_module_function(cNWScript, "GetLastAttackMode", NWScript_GetLastAttackMode, -1);
    rb_define_module_function(cNWScript, "GetMaster", NWScript_GetMaster, -1);
    rb_define_module_function(cNWScript, "GetIsInCombat", NWScript_GetIsInCombat, -1);
    rb_define_module_function(cNWScript, "GetLastAssociateCommand", NWScript_GetLastAssociateCommand, -1);
    rb_define_module_function(cNWScript, "GiveGoldToCreature", NWScript_GiveGoldToCreature, 2);
    rb_define_module_function(cNWScript, "SetIsDestroyable", NWScript_SetIsDestroyable, -1);
    rb_define_module_function(cNWScript, "SetLocked", NWScript_SetLocked, 2);
    rb_define_module_function(cNWScript, "GetLocked", NWScript_GetLocked, 1);
    rb_define_module_function(cNWScript, "GetClickingObject", NWScript_GetClickingObject, 0);
    rb_define_module_function(cNWScript, "SetAssociateListenPatterns", NWScript_SetAssociateListenPatterns, -1);
    rb_define_module_function(cNWScript, "GetLastWeaponUsed", NWScript_GetLastWeaponUsed, 1);
    rb_define_module_function(cNWScript, "ActionInteractObject", NWScript_ActionInteractObject, 1);
    rb_define_module_function(cNWScript, "GetLastUsedBy", NWScript_GetLastUsedBy, 0);
    rb_define_module_function(cNWScript, "GetAbilityModifier", NWScript_GetAbilityModifier, -1);
    rb_define_module_function(cNWScript, "GetIdentified", NWScript_GetIdentified, 1);
    rb_define_module_function(cNWScript, "SetIdentified", NWScript_SetIdentified, 2);
    rb_define_module_function(cNWScript, "SummonAnimalCompanion", NWScript_SummonAnimalCompanion, -1);
    rb_define_module_function(cNWScript, "SummonFamiliar", NWScript_SummonFamiliar, -1);
    rb_define_module_function(cNWScript, "GetBlockingDoor", NWScript_GetBlockingDoor, 0);
    rb_define_module_function(cNWScript, "GetIsDoorActionPossible", NWScript_GetIsDoorActionPossible, 2);
    rb_define_module_function(cNWScript, "DoDoorAction", NWScript_DoDoorAction, 2);
    rb_define_module_function(cNWScript, "GetFirstItemInInventory", NWScript_GetFirstItemInInventory, -1);
    rb_define_module_function(cNWScript, "GetNextItemInInventory", NWScript_GetNextItemInInventory, -1);
    rb_define_module_function(cNWScript, "GetClassByPosition", NWScript_GetClassByPosition, -1);
    rb_define_module_function(cNWScript, "GetLevelByPosition", NWScript_GetLevelByPosition, -1);
    rb_define_module_function(cNWScript, "GetLevelByClass", NWScript_GetLevelByClass, -1);
    rb_define_module_function(cNWScript, "GetDamageDealtByType", NWScript_GetDamageDealtByType, 1);
    rb_define_module_function(cNWScript, "GetTotalDamageDealt", NWScript_GetTotalDamageDealt, 0);
    rb_define_module_function(cNWScript, "GetLastDamager", NWScript_GetLastDamager, -1);
    rb_define_module_function(cNWScript, "GetLastDisarmed", NWScript_GetLastDisarmed, 0);
    rb_define_module_function(cNWScript, "GetLastDisturbed", NWScript_GetLastDisturbed, 0);
    rb_define_module_function(cNWScript, "GetLastLocked", NWScript_GetLastLocked, 0);
    rb_define_module_function(cNWScript, "GetLastUnlocked", NWScript_GetLastUnlocked, 0);
    rb_define_module_function(cNWScript, "EffectSkillIncrease", NWScript_EffectSkillIncrease, 2);
    rb_define_module_function(cNWScript, "GetInventoryDisturbType", NWScript_GetInventoryDisturbType, 0);
    rb_define_module_function(cNWScript, "GetInventoryDisturbItem", NWScript_GetInventoryDisturbItem, 0);
    rb_define_module_function(cNWScript, "GetHenchman", NWScript_GetHenchman, -1);
    rb_define_module_function(cNWScript, "VersusAlignmentEffect", NWScript_VersusAlignmentEffect, -1);
    rb_define_module_function(cNWScript, "VersusRacialTypeEffect", NWScript_VersusRacialTypeEffect, 2);
    rb_define_module_function(cNWScript, "VersusTrapEffect", NWScript_VersusTrapEffect, 1);
    rb_define_module_function(cNWScript, "GetGender", NWScript_GetGender, 1);
    rb_define_module_function(cNWScript, "GetIsTalentValid", NWScript_GetIsTalentValid, 1);
    rb_define_module_function(cNWScript, "ActionMoveAwayFromLocation", NWScript_ActionMoveAwayFromLocation, -1);
    rb_define_module_function(cNWScript, "GetAttemptedAttackTarget", NWScript_GetAttemptedAttackTarget, 0);
    rb_define_module_function(cNWScript, "GetTypeFromTalent", NWScript_GetTypeFromTalent, 1);
    rb_define_module_function(cNWScript, "GetIdFromTalent", NWScript_GetIdFromTalent, 1);
    rb_define_module_function(cNWScript, "GetAssociate", NWScript_GetAssociate, -1);
    rb_define_module_function(cNWScript, "AddHenchman", NWScript_AddHenchman, -1);
    rb_define_module_function(cNWScript, "RemoveHenchman", NWScript_RemoveHenchman, -1);
    rb_define_module_function(cNWScript, "AddJournalQuestEntry", NWScript_AddJournalQuestEntry, -1);
    rb_define_module_function(cNWScript, "RemoveJournalQuestEntry", NWScript_RemoveJournalQuestEntry, -1);
    rb_define_module_function(cNWScript, "GetPCPublicCDKey", NWScript_GetPCPublicCDKey, -1);
    rb_define_module_function(cNWScript, "GetPCIPAddress", NWScript_GetPCIPAddress, 1);
    rb_define_module_function(cNWScript, "GetPCPlayerName", NWScript_GetPCPlayerName, 1);
    rb_define_module_function(cNWScript, "SetPCLike", NWScript_SetPCLike, 2);
    rb_define_module_function(cNWScript, "SetPCDislike", NWScript_SetPCDislike, 2);
    rb_define_module_function(cNWScript, "SendMessageToPC", NWScript_SendMessageToPC, 2);
    rb_define_module_function(cNWScript, "GetAttemptedSpellTarget", NWScript_GetAttemptedSpellTarget, 0);
    rb_define_module_function(cNWScript, "GetLastOpenedBy", NWScript_GetLastOpenedBy, 0);
    rb_define_module_function(cNWScript, "GetHasSpell", NWScript_GetHasSpell, -1);
    rb_define_module_function(cNWScript, "OpenStore", NWScript_OpenStore, -1);
    rb_define_module_function(cNWScript, "EffectTurned", NWScript_EffectTurned, 0);
    rb_define_module_function(cNWScript, "GetFirstFactionMember", NWScript_GetFirstFactionMember, -1);
    rb_define_module_function(cNWScript, "GetNextFactionMember", NWScript_GetNextFactionMember, -1);
    rb_define_module_function(cNWScript, "ActionForceMoveToLocation", NWScript_ActionForceMoveToLocation, -1);
    rb_define_module_function(cNWScript, "ActionForceMoveToObject", NWScript_ActionForceMoveToObject, -1);
    rb_define_module_function(cNWScript, "GetJournalQuestExperience", NWScript_GetJournalQuestExperience, 1);
    rb_define_module_function(cNWScript, "JumpToObject", NWScript_JumpToObject, -1);
    rb_define_module_function(cNWScript, "SetMapPinEnabled", NWScript_SetMapPinEnabled, 2);
    rb_define_module_function(cNWScript, "EffectHitPointChangeWhenDying", NWScript_EffectHitPointChangeWhenDying, 1);
    rb_define_module_function(cNWScript, "PopUpGUIPanel", NWScript_PopUpGUIPanel, 2);
    rb_define_module_function(cNWScript, "ClearPersonalReputation", NWScript_ClearPersonalReputation, -1);
    rb_define_module_function(cNWScript, "SetIsTemporaryFriend", NWScript_SetIsTemporaryFriend, -1);
    rb_define_module_function(cNWScript, "SetIsTemporaryEnemy", NWScript_SetIsTemporaryEnemy, -1);
    rb_define_module_function(cNWScript, "SetIsTemporaryNeutral", NWScript_SetIsTemporaryNeutral, -1);
    rb_define_module_function(cNWScript, "GiveXPToCreature", NWScript_GiveXPToCreature, 2);
    rb_define_module_function(cNWScript, "SetXP", NWScript_SetXP, 2);
    rb_define_module_function(cNWScript, "GetXP", NWScript_GetXP, 1);
    rb_define_module_function(cNWScript, "IntToHexString", NWScript_IntToHexString, 1);
    rb_define_module_function(cNWScript, "GetBaseItemType", NWScript_GetBaseItemType, 1);
    rb_define_module_function(cNWScript, "GetItemHasItemProperty", NWScript_GetItemHasItemProperty, 2);
    rb_define_module_function(cNWScript, "ActionEquipMostDamagingMelee", NWScript_ActionEquipMostDamagingMelee, -1);
    rb_define_module_function(cNWScript, "ActionEquipMostDamagingRanged", NWScript_ActionEquipMostDamagingRanged, -1);
    rb_define_module_function(cNWScript, "GetItemACValue", NWScript_GetItemACValue, 1);
    rb_define_module_function(cNWScript, "ActionRest", NWScript_ActionRest, -1);
    rb_define_module_function(cNWScript, "ExploreAreaForPlayer", NWScript_ExploreAreaForPlayer, -1);
    rb_define_module_function(cNWScript, "ActionEquipMostEffectiveArmor", NWScript_ActionEquipMostEffectiveArmor, 0);
    rb_define_module_function(cNWScript, "GetIsDay", NWScript_GetIsDay, 0);
    rb_define_module_function(cNWScript, "GetIsNight", NWScript_GetIsNight, 0);
    rb_define_module_function(cNWScript, "GetIsDawn", NWScript_GetIsDawn, 0);
    rb_define_module_function(cNWScript, "GetIsDusk", NWScript_GetIsDusk, 0);
    rb_define_module_function(cNWScript, "GetIsEncounterCreature", NWScript_GetIsEncounterCreature, -1);
    rb_define_module_function(cNWScript, "GetLastPlayerDying", NWScript_GetLastPlayerDying, 0);
    rb_define_module_function(cNWScript, "GetStartingLocation", NWScript_GetStartingLocation, 0);
    rb_define_module_function(cNWScript, "ChangeToStandardFaction", NWScript_ChangeToStandardFaction, 2);
    rb_define_module_function(cNWScript, "SoundObjectPlay", NWScript_SoundObjectPlay, 1);
    rb_define_module_function(cNWScript, "SoundObjectStop", NWScript_SoundObjectStop, 1);
    rb_define_module_function(cNWScript, "SoundObjectSetVolume", NWScript_SoundObjectSetVolume, 2);
    rb_define_module_function(cNWScript, "SoundObjectSetPosition", NWScript_SoundObjectSetPosition, 2);
    rb_define_module_function(cNWScript, "SpeakOneLinerConversation", NWScript_SpeakOneLinerConversation, -1);
    rb_define_module_function(cNWScript, "GetGold", NWScript_GetGold, -1);
    rb_define_module_function(cNWScript, "GetLastRespawnButtonPresser", NWScript_GetLastRespawnButtonPresser, 0);
    rb_define_module_function(cNWScript, "GetIsDM", NWScript_GetIsDM, 1);
    rb_define_module_function(cNWScript, "PlayVoiceChat", NWScript_PlayVoiceChat, -1);
    rb_define_module_function(cNWScript, "GetIsWeaponEffective", NWScript_GetIsWeaponEffective, -1);
    rb_define_module_function(cNWScript, "GetLastSpellHarmful", NWScript_GetLastSpellHarmful, 0);
    rb_define_module_function(cNWScript, "EventActivateItem", NWScript_EventActivateItem, -1);
    rb_define_module_function(cNWScript, "MusicBackgroundPlay", NWScript_MusicBackgroundPlay, 1);
    rb_define_module_function(cNWScript, "MusicBackgroundStop", NWScript_MusicBackgroundStop, 1);
    rb_define_module_function(cNWScript, "MusicBackgroundSetDelay", NWScript_MusicBackgroundSetDelay, 2);
    rb_define_module_function(cNWScript, "MusicBackgroundChangeDay", NWScript_MusicBackgroundChangeDay, 2);
    rb_define_module_function(cNWScript, "MusicBackgroundChangeNight", NWScript_MusicBackgroundChangeNight, 2);
    rb_define_module_function(cNWScript, "MusicBattlePlay", NWScript_MusicBattlePlay, 1);
    rb_define_module_function(cNWScript, "MusicBattleStop", NWScript_MusicBattleStop, 1);
    rb_define_module_function(cNWScript, "MusicBattleChange", NWScript_MusicBattleChange, 2);
    rb_define_module_function(cNWScript, "AmbientSoundPlay", NWScript_AmbientSoundPlay, 1);
    rb_define_module_function(cNWScript, "AmbientSoundStop", NWScript_AmbientSoundStop, 1);
    rb_define_module_function(cNWScript, "AmbientSoundChangeDay", NWScript_AmbientSoundChangeDay, 2);
    rb_define_module_function(cNWScript, "AmbientSoundChangeNight", NWScript_AmbientSoundChangeNight, 2);
    rb_define_module_function(cNWScript, "GetLastKiller", NWScript_GetLastKiller, 0);
    rb_define_module_function(cNWScript, "GetSpellCastItem", NWScript_GetSpellCastItem, 0);
    rb_define_module_function(cNWScript, "GetItemActivated", NWScript_GetItemActivated, 0);
    rb_define_module_function(cNWScript, "GetItemActivator", NWScript_GetItemActivator, 0);
    rb_define_module_function(cNWScript, "GetItemActivatedTargetLocation", NWScript_GetItemActivatedTargetLocation, 0);
    rb_define_module_function(cNWScript, "GetItemActivatedTarget", NWScript_GetItemActivatedTarget, 0);
    rb_define_module_function(cNWScript, "GetIsOpen", NWScript_GetIsOpen, 1);
    rb_define_module_function(cNWScript, "TakeGoldFromCreature", NWScript_TakeGoldFromCreature, -1);
    rb_define_module_function(cNWScript, "IsInConversation", NWScript_IsInConversation, 1);
    rb_define_module_function(cNWScript, "EffectAbilityDecrease", NWScript_EffectAbilityDecrease, 2);
    rb_define_module_function(cNWScript, "EffectAttackDecrease", NWScript_EffectAttackDecrease, -1);
    rb_define_module_function(cNWScript, "EffectDamageDecrease", NWScript_EffectDamageDecrease, -1);
    rb_define_module_function(cNWScript, "EffectDamageImmunityDecrease", NWScript_EffectDamageImmunityDecrease, 2);
    rb_define_module_function(cNWScript, "EffectACDecrease", NWScript_EffectACDecrease, -1);
    rb_define_module_function(cNWScript, "EffectMovementSpeedDecrease", NWScript_EffectMovementSpeedDecrease, 1);
    rb_define_module_function(cNWScript, "EffectSavingThrowDecrease", NWScript_EffectSavingThrowDecrease, -1);
    rb_define_module_function(cNWScript, "EffectSkillDecrease", NWScript_EffectSkillDecrease, 2);
    rb_define_module_function(cNWScript, "EffectSpellResistanceDecrease", NWScript_EffectSpellResistanceDecrease, 1);
    rb_define_module_function(cNWScript, "GetPlotFlag", NWScript_GetPlotFlag, -1);
    rb_define_module_function(cNWScript, "SetPlotFlag", NWScript_SetPlotFlag, 2);
    rb_define_module_function(cNWScript, "EffectInvisibility", NWScript_EffectInvisibility, 1);
    rb_define_module_function(cNWScript, "EffectConcealment", NWScript_EffectConcealment, -1);
    rb_define_module_function(cNWScript, "EffectDarkness", NWScript_EffectDarkness, 0);
    rb_define_module_function(cNWScript, "EffectDispelMagicAll", NWScript_EffectDispelMagicAll, -1);
    rb_define_module_function(cNWScript, "EffectUltravision", NWScript_EffectUltravision, 0);
    rb_define_module_function(cNWScript, "EffectNegativeLevel", NWScript_EffectNegativeLevel, -1);
    rb_define_module_function(cNWScript, "EffectPolymorph", NWScript_EffectPolymorph, -1);
    rb_define_module_function(cNWScript, "EffectSanctuary", NWScript_EffectSanctuary, 1);
    rb_define_module_function(cNWScript, "EffectTrueSeeing", NWScript_EffectTrueSeeing, 0);
    rb_define_module_function(cNWScript, "EffectSeeInvisible", NWScript_EffectSeeInvisible, 0);
    rb_define_module_function(cNWScript, "EffectTimeStop", NWScript_EffectTimeStop, 0);
    rb_define_module_function(cNWScript, "EffectBlindness", NWScript_EffectBlindness, 0);
    rb_define_module_function(cNWScript, "GetIsReactionTypeFriendly", NWScript_GetIsReactionTypeFriendly, -1);
    rb_define_module_function(cNWScript, "GetIsReactionTypeNeutral", NWScript_GetIsReactionTypeNeutral, -1);
    rb_define_module_function(cNWScript, "GetIsReactionTypeHostile", NWScript_GetIsReactionTypeHostile, -1);
    rb_define_module_function(cNWScript, "EffectSpellLevelAbsorption", NWScript_EffectSpellLevelAbsorption, -1);
    rb_define_module_function(cNWScript, "EffectDispelMagicBest", NWScript_EffectDispelMagicBest, -1);
    rb_define_module_function(cNWScript, "ActivatePortal", NWScript_ActivatePortal, -1);
    rb_define_module_function(cNWScript, "GetNumStackedItems", NWScript_GetNumStackedItems, 1);
    rb_define_module_function(cNWScript, "SurrenderToEnemies", NWScript_SurrenderToEnemies, 0);
    rb_define_module_function(cNWScript, "EffectMissChance", NWScript_EffectMissChance, -1);
    rb_define_module_function(cNWScript, "GetTurnResistanceHD", NWScript_GetTurnResistanceHD, -1);
    rb_define_module_function(cNWScript, "GetCreatureSize", NWScript_GetCreatureSize, 1);
    rb_define_module_function(cNWScript, "EffectDisappearAppear", NWScript_EffectDisappearAppear, -1);
    rb_define_module_function(cNWScript, "EffectDisappear", NWScript_EffectDisappear, -1);
    rb_define_module_function(cNWScript, "EffectAppear", NWScript_EffectAppear, -1);
    rb_define_module_function(cNWScript, "ActionUnlockObject", NWScript_ActionUnlockObject, 1);
    rb_define_module_function(cNWScript, "ActionLockObject", NWScript_ActionLockObject, 1);
    rb_define_module_function(cNWScript, "EffectModifyAttacks", NWScript_EffectModifyAttacks, 1);
    rb_define_module_function(cNWScript, "GetLastTrapDetected", NWScript_GetLastTrapDetected, -1);
    rb_define_module_function(cNWScript, "EffectDamageShield", NWScript_EffectDamageShield, 3);
    rb_define_module_function(cNWScript, "GetNearestTrapToObject", NWScript_GetNearestTrapToObject, -1);
    rb_define_module_function(cNWScript, "GetDeity", NWScript_GetDeity, 1);
    rb_define_module_function(cNWScript, "GetSubRace", NWScript_GetSubRace, 1);
    rb_define_module_function(cNWScript, "GetFortitudeSavingThrow", NWScript_GetFortitudeSavingThrow, 1);
    rb_define_module_function(cNWScript, "GetWillSavingThrow", NWScript_GetWillSavingThrow, 1);
    rb_define_module_function(cNWScript, "GetReflexSavingThrow", NWScript_GetReflexSavingThrow, 1);
    rb_define_module_function(cNWScript, "GetChallengeRating", NWScript_GetChallengeRating, 1);
    rb_define_module_function(cNWScript, "GetAge", NWScript_GetAge, 1);
    rb_define_module_function(cNWScript, "GetMovementRate", NWScript_GetMovementRate, 1);
    rb_define_module_function(cNWScript, "GetFamiliarCreatureType", NWScript_GetFamiliarCreatureType, 1);
    rb_define_module_function(cNWScript, "GetAnimalCompanionCreatureType", NWScript_GetAnimalCompanionCreatureType, 1);
    rb_define_module_function(cNWScript, "GetFamiliarName", NWScript_GetFamiliarName, 1);
    rb_define_module_function(cNWScript, "GetAnimalCompanionName", NWScript_GetAnimalCompanionName, 1);
    rb_define_module_function(cNWScript, "ActionCastFakeSpellAtObject", NWScript_ActionCastFakeSpellAtObject, -1);
    rb_define_module_function(cNWScript, "ActionCastFakeSpellAtLocation", NWScript_ActionCastFakeSpellAtLocation, -1);
    rb_define_module_function(cNWScript, "RemoveSummonedAssociate", NWScript_RemoveSummonedAssociate, -1);
    rb_define_module_function(cNWScript, "SetCameraMode", NWScript_SetCameraMode, 2);
    rb_define_module_function(cNWScript, "GetIsResting", NWScript_GetIsResting, -1);
    rb_define_module_function(cNWScript, "GetLastPCRested", NWScript_GetLastPCRested, 0);
    rb_define_module_function(cNWScript, "SetWeather", NWScript_SetWeather, 2);
    rb_define_module_function(cNWScript, "GetLastRestEventType", NWScript_GetLastRestEventType, 0);
    rb_define_module_function(cNWScript, "StartNewModule", NWScript_StartNewModule, 1);
    rb_define_module_function(cNWScript, "EffectSwarm", NWScript_EffectSwarm, -1);
    rb_define_module_function(cNWScript, "GetWeaponRanged", NWScript_GetWeaponRanged, 1);
    rb_define_module_function(cNWScript, "DoSinglePlayerAutoSave", NWScript_DoSinglePlayerAutoSave, 0);
    rb_define_module_function(cNWScript, "GetGameDifficulty", NWScript_GetGameDifficulty, 0);
    rb_define_module_function(cNWScript, "SetTileMainLightColor", NWScript_SetTileMainLightColor, 3);
    rb_define_module_function(cNWScript, "SetTileSourceLightColor", NWScript_SetTileSourceLightColor, 3);
    rb_define_module_function(cNWScript, "RecomputeStaticLighting", NWScript_RecomputeStaticLighting, 1);
    rb_define_module_function(cNWScript, "GetTileMainLight1Color", NWScript_GetTileMainLight1Color, 1);
    rb_define_module_function(cNWScript, "GetTileMainLight2Color", NWScript_GetTileMainLight2Color, 1);
    rb_define_module_function(cNWScript, "GetTileSourceLight1Color", NWScript_GetTileSourceLight1Color, 1);
    rb_define_module_function(cNWScript, "GetTileSourceLight2Color", NWScript_GetTileSourceLight2Color, 1);
    rb_define_module_function(cNWScript, "SetPanelButtonFlash", NWScript_SetPanelButtonFlash, 3);
    rb_define_module_function(cNWScript, "GetCurrentAction", NWScript_GetCurrentAction, -1);
    rb_define_module_function(cNWScript, "SetStandardFactionReputation", NWScript_SetStandardFactionReputation, -1);
    rb_define_module_function(cNWScript, "GetStandardFactionReputation", NWScript_GetStandardFactionReputation, -1);
    rb_define_module_function(cNWScript, "FloatingTextStrRefOnCreature", NWScript_FloatingTextStrRefOnCreature, -1);
    rb_define_module_function(cNWScript, "FloatingTextStringOnCreature", NWScript_FloatingTextStringOnCreature, -1);
    rb_define_module_function(cNWScript, "GetTrapDisarmable", NWScript_GetTrapDisarmable, 1);
    rb_define_module_function(cNWScript, "GetTrapDetectable", NWScript_GetTrapDetectable, 1);
    rb_define_module_function(cNWScript, "GetTrapDetectedBy", NWScript_GetTrapDetectedBy, 2);
    rb_define_module_function(cNWScript, "GetTrapFlagged", NWScript_GetTrapFlagged, 1);
    rb_define_module_function(cNWScript, "GetTrapBaseType", NWScript_GetTrapBaseType, 1);
    rb_define_module_function(cNWScript, "GetTrapOneShot", NWScript_GetTrapOneShot, 1);
    rb_define_module_function(cNWScript, "GetTrapCreator", NWScript_GetTrapCreator, 1);
    rb_define_module_function(cNWScript, "GetTrapKeyTag", NWScript_GetTrapKeyTag, 1);
    rb_define_module_function(cNWScript, "GetTrapDisarmDC", NWScript_GetTrapDisarmDC, 1);
    rb_define_module_function(cNWScript, "GetTrapDetectDC", NWScript_GetTrapDetectDC, 1);
    rb_define_module_function(cNWScript, "GetLockKeyRequired", NWScript_GetLockKeyRequired, 1);
    rb_define_module_function(cNWScript, "GetLockKeyTag", NWScript_GetLockKeyTag, 1);
    rb_define_module_function(cNWScript, "GetLockLockable", NWScript_GetLockLockable, 1);
    rb_define_module_function(cNWScript, "GetLockUnlockDC", NWScript_GetLockUnlockDC, 1);
    rb_define_module_function(cNWScript, "GetLockLockDC", NWScript_GetLockLockDC, 1);
    rb_define_module_function(cNWScript, "GetPCLevellingUp", NWScript_GetPCLevellingUp, 0);
    rb_define_module_function(cNWScript, "GetHasFeatEffect", NWScript_GetHasFeatEffect, -1);
    rb_define_module_function(cNWScript, "SetPlaceableIllumination", NWScript_SetPlaceableIllumination, -1);
    rb_define_module_function(cNWScript, "GetPlaceableIllumination", NWScript_GetPlaceableIllumination, -1);
    rb_define_module_function(cNWScript, "GetIsPlaceableObjectActionPossible", NWScript_GetIsPlaceableObjectActionPossible, 2);
    rb_define_module_function(cNWScript, "DoPlaceableObjectAction", NWScript_DoPlaceableObjectAction, 2);
    rb_define_module_function(cNWScript, "GetFirstPC", NWScript_GetFirstPC, 0);
    rb_define_module_function(cNWScript, "GetNextPC", NWScript_GetNextPC, 0);
    rb_define_module_function(cNWScript, "SetTrapDetectedBy", NWScript_SetTrapDetectedBy, -1);
    rb_define_module_function(cNWScript, "GetIsTrapped", NWScript_GetIsTrapped, 1);
    rb_define_module_function(cNWScript, "EffectTurnResistanceDecrease", NWScript_EffectTurnResistanceDecrease, 1);
    rb_define_module_function(cNWScript, "EffectTurnResistanceIncrease", NWScript_EffectTurnResistanceIncrease, 1);
    rb_define_module_function(cNWScript, "PopUpDeathGUIPanel", NWScript_PopUpDeathGUIPanel, -1);
    rb_define_module_function(cNWScript, "SetTrapDisabled", NWScript_SetTrapDisabled, 1);
    rb_define_module_function(cNWScript, "GetLastHostileActor", NWScript_GetLastHostileActor, -1);
    rb_define_module_function(cNWScript, "ExportAllCharacters", NWScript_ExportAllCharacters, 0);
    rb_define_module_function(cNWScript, "MusicBackgroundGetDayTrack", NWScript_MusicBackgroundGetDayTrack, 1);
    rb_define_module_function(cNWScript, "MusicBackgroundGetNightTrack", NWScript_MusicBackgroundGetNightTrack, 1);
    rb_define_module_function(cNWScript, "WriteTimestampedLogEntry", NWScript_WriteTimestampedLogEntry, 1);
    rb_define_module_function(cNWScript, "GetModuleName", NWScript_GetModuleName, 0);
    rb_define_module_function(cNWScript, "GetFactionLeader", NWScript_GetFactionLeader, 1);
    rb_define_module_function(cNWScript, "SendMessageToAllDMs", NWScript_SendMessageToAllDMs, 1);
    rb_define_module_function(cNWScript, "EndGame", NWScript_EndGame, 1);
    rb_define_module_function(cNWScript, "BootPC", NWScript_BootPC, 1);
    rb_define_module_function(cNWScript, "ActionCounterSpell", NWScript_ActionCounterSpell, 1);
    rb_define_module_function(cNWScript, "AmbientSoundSetDayVolume", NWScript_AmbientSoundSetDayVolume, 2);
    rb_define_module_function(cNWScript, "AmbientSoundSetNightVolume", NWScript_AmbientSoundSetNightVolume, 2);
    rb_define_module_function(cNWScript, "MusicBackgroundGetBattleTrack", NWScript_MusicBackgroundGetBattleTrack, 1);
    rb_define_module_function(cNWScript, "GetHasInventory", NWScript_GetHasInventory, 1);
    rb_define_module_function(cNWScript, "GetStrRefSoundDuration", NWScript_GetStrRefSoundDuration, 1);
    rb_define_module_function(cNWScript, "AddToParty", NWScript_AddToParty, 2);
    rb_define_module_function(cNWScript, "RemoveFromParty", NWScript_RemoveFromParty, 1);
    rb_define_module_function(cNWScript, "GetStealthMode", NWScript_GetStealthMode, 1);
    rb_define_module_function(cNWScript, "GetDetectMode", NWScript_GetDetectMode, 1);
    rb_define_module_function(cNWScript, "GetDefensiveCastingMode", NWScript_GetDefensiveCastingMode, 1);
    rb_define_module_function(cNWScript, "GetAppearanceType", NWScript_GetAppearanceType, 1);
    rb_define_module_function(cNWScript, "SpawnScriptDebugger", NWScript_SpawnScriptDebugger, 0);
    rb_define_module_function(cNWScript, "GetModuleItemAcquiredStackSize", NWScript_GetModuleItemAcquiredStackSize, 0);
    rb_define_module_function(cNWScript, "DecrementRemainingFeatUses", NWScript_DecrementRemainingFeatUses, 2);
    rb_define_module_function(cNWScript, "DecrementRemainingSpellUses", NWScript_DecrementRemainingSpellUses, 2);
    rb_define_module_function(cNWScript, "GetResRef", NWScript_GetResRef, 1);
    rb_define_module_function(cNWScript, "EffectPetrify", NWScript_EffectPetrify, 0);
    rb_define_module_function(cNWScript, "CopyItem", NWScript_CopyItem, -1);
    rb_define_module_function(cNWScript, "EffectCutsceneParalyze", NWScript_EffectCutsceneParalyze, 0);
    rb_define_module_function(cNWScript, "GetDroppableFlag", NWScript_GetDroppableFlag, 1);
    rb_define_module_function(cNWScript, "GetUseableFlag", NWScript_GetUseableFlag, -1);
    rb_define_module_function(cNWScript, "GetStolenFlag", NWScript_GetStolenFlag, 1);
    rb_define_module_function(cNWScript, "SetCampaignFloat", NWScript_SetCampaignFloat, -1);
    rb_define_module_function(cNWScript, "SetCampaignInt", NWScript_SetCampaignInt, -1);
    rb_define_module_function(cNWScript, "SetCampaignVector", NWScript_SetCampaignVector, -1);
    rb_define_module_function(cNWScript, "SetCampaignLocation", NWScript_SetCampaignLocation, -1);
    rb_define_module_function(cNWScript, "SetCampaignString", NWScript_SetCampaignString, -1);
    rb_define_module_function(cNWScript, "DestroyCampaignDatabase", NWScript_DestroyCampaignDatabase, 1);
    rb_define_module_function(cNWScript, "GetCampaignFloat", NWScript_GetCampaignFloat, -1);
    rb_define_module_function(cNWScript, "GetCampaignInt", NWScript_GetCampaignInt, -1);
    rb_define_module_function(cNWScript, "GetCampaignVector", NWScript_GetCampaignVector, -1);
    rb_define_module_function(cNWScript, "GetCampaignLocation", NWScript_GetCampaignLocation, -1);
    rb_define_module_function(cNWScript, "GetCampaignString", NWScript_GetCampaignString, -1);
    rb_define_module_function(cNWScript, "CopyObject", NWScript_CopyObject, -1);
    rb_define_module_function(cNWScript, "DeleteCampaignVariable", NWScript_DeleteCampaignVariable, -1);
    rb_define_module_function(cNWScript, "StoreCampaignObject", NWScript_StoreCampaignObject, -1);
    rb_define_module_function(cNWScript, "RetrieveCampaignObject", NWScript_RetrieveCampaignObject, -1);
    rb_define_module_function(cNWScript, "EffectCutsceneDominated", NWScript_EffectCutsceneDominated, 0);
    rb_define_module_function(cNWScript, "GetItemStackSize", NWScript_GetItemStackSize, 1);
    rb_define_module_function(cNWScript, "SetItemStackSize", NWScript_SetItemStackSize, 2);
    rb_define_module_function(cNWScript, "GetItemCharges", NWScript_GetItemCharges, 1);
    rb_define_module_function(cNWScript, "SetItemCharges", NWScript_SetItemCharges, 2);
    rb_define_module_function(cNWScript, "AddItemProperty", NWScript_AddItemProperty, -1);
    rb_define_module_function(cNWScript, "RemoveItemProperty", NWScript_RemoveItemProperty, 2);
    rb_define_module_function(cNWScript, "GetIsItemPropertyValid", NWScript_GetIsItemPropertyValid, 1);
    rb_define_module_function(cNWScript, "GetFirstItemProperty", NWScript_GetFirstItemProperty, 1);
    rb_define_module_function(cNWScript, "GetNextItemProperty", NWScript_GetNextItemProperty, 1);
    rb_define_module_function(cNWScript, "GetItemPropertyType", NWScript_GetItemPropertyType, 1);
    rb_define_module_function(cNWScript, "GetItemPropertyDurationType", NWScript_GetItemPropertyDurationType, 1);
    rb_define_module_function(cNWScript, "ItemPropertyAbilityBonus", NWScript_ItemPropertyAbilityBonus, 2);
    rb_define_module_function(cNWScript, "ItemPropertyACBonus", NWScript_ItemPropertyACBonus, 1);
    rb_define_module_function(cNWScript, "ItemPropertyACBonusVsAlign", NWScript_ItemPropertyACBonusVsAlign, 2);
    rb_define_module_function(cNWScript, "ItemPropertyACBonusVsDmgType", NWScript_ItemPropertyACBonusVsDmgType, 2);
    rb_define_module_function(cNWScript, "ItemPropertyACBonusVsRace", NWScript_ItemPropertyACBonusVsRace, 2);
    rb_define_module_function(cNWScript, "ItemPropertyACBonusVsSAlign", NWScript_ItemPropertyACBonusVsSAlign, 2);
    rb_define_module_function(cNWScript, "ItemPropertyEnhancementBonus", NWScript_ItemPropertyEnhancementBonus, 1);
    rb_define_module_function(cNWScript, "ItemPropertyEnhancementBonusVsAlign", NWScript_ItemPropertyEnhancementBonusVsAlign, 2);
    rb_define_module_function(cNWScript, "ItemPropertyEnhancementBonusVsRace", NWScript_ItemPropertyEnhancementBonusVsRace, 2);
    rb_define_module_function(cNWScript, "ItemPropertyEnhancementBonusVsSAlign", NWScript_ItemPropertyEnhancementBonusVsSAlign, 2);
    rb_define_module_function(cNWScript, "ItemPropertyEnhancementPenalty", NWScript_ItemPropertyEnhancementPenalty, 1);
    rb_define_module_function(cNWScript, "ItemPropertyWeightReduction", NWScript_ItemPropertyWeightReduction, 1);
    rb_define_module_function(cNWScript, "ItemPropertyBonusFeat", NWScript_ItemPropertyBonusFeat, 1);
    rb_define_module_function(cNWScript, "ItemPropertyBonusLevelSpell", NWScript_ItemPropertyBonusLevelSpell, 2);
    rb_define_module_function(cNWScript, "ItemPropertyCastSpell", NWScript_ItemPropertyCastSpell, 2);
    rb_define_module_function(cNWScript, "ItemPropertyDamageBonus", NWScript_ItemPropertyDamageBonus, 2);
    rb_define_module_function(cNWScript, "ItemPropertyDamageBonusVsAlign", NWScript_ItemPropertyDamageBonusVsAlign, 3);
    rb_define_module_function(cNWScript, "ItemPropertyDamageBonusVsRace", NWScript_ItemPropertyDamageBonusVsRace, 3);
    rb_define_module_function(cNWScript, "ItemPropertyDamageBonusVsSAlign", NWScript_ItemPropertyDamageBonusVsSAlign, 3);
    rb_define_module_function(cNWScript, "ItemPropertyDamageImmunity", NWScript_ItemPropertyDamageImmunity, 2);
    rb_define_module_function(cNWScript, "ItemPropertyDamagePenalty", NWScript_ItemPropertyDamagePenalty, 1);
    rb_define_module_function(cNWScript, "ItemPropertyDamageReduction", NWScript_ItemPropertyDamageReduction, 2);
    rb_define_module_function(cNWScript, "ItemPropertyDamageResistance", NWScript_ItemPropertyDamageResistance, 2);
    rb_define_module_function(cNWScript, "ItemPropertyDamageVulnerability", NWScript_ItemPropertyDamageVulnerability, 2);
    rb_define_module_function(cNWScript, "ItemPropertyDarkvision", NWScript_ItemPropertyDarkvision, 0);
    rb_define_module_function(cNWScript, "ItemPropertyDecreaseAbility", NWScript_ItemPropertyDecreaseAbility, 2);
    rb_define_module_function(cNWScript, "ItemPropertyDecreaseAC", NWScript_ItemPropertyDecreaseAC, 2);
    rb_define_module_function(cNWScript, "ItemPropertyDecreaseSkill", NWScript_ItemPropertyDecreaseSkill, 2);
    rb_define_module_function(cNWScript, "ItemPropertyContainerReducedWeight", NWScript_ItemPropertyContainerReducedWeight, 1);
    rb_define_module_function(cNWScript, "ItemPropertyExtraMeleeDamageType", NWScript_ItemPropertyExtraMeleeDamageType, 1);
    rb_define_module_function(cNWScript, "ItemPropertyExtraRangeDamageType", NWScript_ItemPropertyExtraRangeDamageType, 1);
    rb_define_module_function(cNWScript, "ItemPropertyHaste", NWScript_ItemPropertyHaste, 0);
    rb_define_module_function(cNWScript, "ItemPropertyHolyAvenger", NWScript_ItemPropertyHolyAvenger, 0);
    rb_define_module_function(cNWScript, "ItemPropertyImmunityMisc", NWScript_ItemPropertyImmunityMisc, 1);
    rb_define_module_function(cNWScript, "ItemPropertyImprovedEvasion", NWScript_ItemPropertyImprovedEvasion, 0);
    rb_define_module_function(cNWScript, "ItemPropertyBonusSpellResistance", NWScript_ItemPropertyBonusSpellResistance, 1);
    rb_define_module_function(cNWScript, "ItemPropertyBonusSavingThrowVsX", NWScript_ItemPropertyBonusSavingThrowVsX, 2);
    rb_define_module_function(cNWScript, "ItemPropertyBonusSavingThrow", NWScript_ItemPropertyBonusSavingThrow, 2);
    rb_define_module_function(cNWScript, "ItemPropertyKeen", NWScript_ItemPropertyKeen, 0);
    rb_define_module_function(cNWScript, "ItemPropertyLight", NWScript_ItemPropertyLight, 2);
    rb_define_module_function(cNWScript, "ItemPropertyMaxRangeStrengthMod", NWScript_ItemPropertyMaxRangeStrengthMod, 1);
    rb_define_module_function(cNWScript, "ItemPropertyNoDamage", NWScript_ItemPropertyNoDamage, 0);
    rb_define_module_function(cNWScript, "ItemPropertyOnHitProps", NWScript_ItemPropertyOnHitProps, -1);
    rb_define_module_function(cNWScript, "ItemPropertyReducedSavingThrowVsX", NWScript_ItemPropertyReducedSavingThrowVsX, 2);
    rb_define_module_function(cNWScript, "ItemPropertyReducedSavingThrow", NWScript_ItemPropertyReducedSavingThrow, 2);
    rb_define_module_function(cNWScript, "ItemPropertyRegeneration", NWScript_ItemPropertyRegeneration, 1);
    rb_define_module_function(cNWScript, "ItemPropertySkillBonus", NWScript_ItemPropertySkillBonus, 2);
    rb_define_module_function(cNWScript, "ItemPropertySpellImmunitySpecific", NWScript_ItemPropertySpellImmunitySpecific, 1);
    rb_define_module_function(cNWScript, "ItemPropertySpellImmunitySchool", NWScript_ItemPropertySpellImmunitySchool, 1);
    rb_define_module_function(cNWScript, "ItemPropertyThievesTools", NWScript_ItemPropertyThievesTools, 1);
    rb_define_module_function(cNWScript, "ItemPropertyAttackBonus", NWScript_ItemPropertyAttackBonus, 1);
    rb_define_module_function(cNWScript, "ItemPropertyAttackBonusVsAlign", NWScript_ItemPropertyAttackBonusVsAlign, 2);
    rb_define_module_function(cNWScript, "ItemPropertyAttackBonusVsRace", NWScript_ItemPropertyAttackBonusVsRace, 2);
    rb_define_module_function(cNWScript, "ItemPropertyAttackBonusVsSAlign", NWScript_ItemPropertyAttackBonusVsSAlign, 2);
    rb_define_module_function(cNWScript, "ItemPropertyAttackPenalty", NWScript_ItemPropertyAttackPenalty, 1);
    rb_define_module_function(cNWScript, "ItemPropertyUnlimitedAmmo", NWScript_ItemPropertyUnlimitedAmmo, -1);
    rb_define_module_function(cNWScript, "ItemPropertyLimitUseByAlign", NWScript_ItemPropertyLimitUseByAlign, 1);
    rb_define_module_function(cNWScript, "ItemPropertyLimitUseByClass", NWScript_ItemPropertyLimitUseByClass, 1);
    rb_define_module_function(cNWScript, "ItemPropertyLimitUseByRace", NWScript_ItemPropertyLimitUseByRace, 1);
    rb_define_module_function(cNWScript, "ItemPropertyLimitUseBySAlign", NWScript_ItemPropertyLimitUseBySAlign, 1);
    rb_define_module_function(cNWScript, "BadBadReplaceMeThisDoesNothing", NWScript_BadBadReplaceMeThisDoesNothing, 0);
    rb_define_module_function(cNWScript, "ItemPropertyVampiricRegeneration", NWScript_ItemPropertyVampiricRegeneration, 1);
    rb_define_module_function(cNWScript, "ItemPropertyTrap", NWScript_ItemPropertyTrap, 2);
    rb_define_module_function(cNWScript, "ItemPropertyTrueSeeing", NWScript_ItemPropertyTrueSeeing, 0);
    rb_define_module_function(cNWScript, "ItemPropertyOnMonsterHitProperties", NWScript_ItemPropertyOnMonsterHitProperties, -1);
    rb_define_module_function(cNWScript, "ItemPropertyTurnResistance", NWScript_ItemPropertyTurnResistance, 1);
    rb_define_module_function(cNWScript, "ItemPropertyMassiveCritical", NWScript_ItemPropertyMassiveCritical, 1);
    rb_define_module_function(cNWScript, "ItemPropertyFreeAction", NWScript_ItemPropertyFreeAction, 0);
    rb_define_module_function(cNWScript, "ItemPropertyMonsterDamage", NWScript_ItemPropertyMonsterDamage, 1);
    rb_define_module_function(cNWScript, "ItemPropertyImmunityToSpellLevel", NWScript_ItemPropertyImmunityToSpellLevel, 1);
    rb_define_module_function(cNWScript, "ItemPropertySpecialWalk", NWScript_ItemPropertySpecialWalk, -1);
    rb_define_module_function(cNWScript, "ItemPropertyHealersKit", NWScript_ItemPropertyHealersKit, 1);
    rb_define_module_function(cNWScript, "ItemPropertyWeightIncrease", NWScript_ItemPropertyWeightIncrease, 1);
    rb_define_module_function(cNWScript, "GetIsSkillSuccessful", NWScript_GetIsSkillSuccessful, 3);
    rb_define_module_function(cNWScript, "EffectSpellFailure", NWScript_EffectSpellFailure, -1);
    rb_define_module_function(cNWScript, "SpeakStringByStrRef", NWScript_SpeakStringByStrRef, -1);
    rb_define_module_function(cNWScript, "SetCutsceneMode", NWScript_SetCutsceneMode, -1);
    rb_define_module_function(cNWScript, "GetLastPCToCancelCutscene", NWScript_GetLastPCToCancelCutscene, 0);
    rb_define_module_function(cNWScript, "GetDialogSoundLength", NWScript_GetDialogSoundLength, 1);
    rb_define_module_function(cNWScript, "FadeFromBlack", NWScript_FadeFromBlack, -1);
    rb_define_module_function(cNWScript, "FadeToBlack", NWScript_FadeToBlack, -1);
    rb_define_module_function(cNWScript, "StopFade", NWScript_StopFade, 1);
    rb_define_module_function(cNWScript, "BlackScreen", NWScript_BlackScreen, 1);
    rb_define_module_function(cNWScript, "GetBaseAttackBonus", NWScript_GetBaseAttackBonus, 1);
    rb_define_module_function(cNWScript, "SetImmortal", NWScript_SetImmortal, 2);
    rb_define_module_function(cNWScript, "OpenInventory", NWScript_OpenInventory, 2);
    rb_define_module_function(cNWScript, "StoreCameraFacing", NWScript_StoreCameraFacing, 0);
    rb_define_module_function(cNWScript, "RestoreCameraFacing", NWScript_RestoreCameraFacing, 0);
    rb_define_module_function(cNWScript, "LevelUpHenchman", NWScript_LevelUpHenchman, -1);
    rb_define_module_function(cNWScript, "SetDroppableFlag", NWScript_SetDroppableFlag, 2);
    rb_define_module_function(cNWScript, "GetWeight", NWScript_GetWeight, -1);
    rb_define_module_function(cNWScript, "GetModuleItemAcquiredBy", NWScript_GetModuleItemAcquiredBy, 0);
    rb_define_module_function(cNWScript, "GetImmortal", NWScript_GetImmortal, -1);
    rb_define_module_function(cNWScript, "DoWhirlwindAttack", NWScript_DoWhirlwindAttack, -1);
    rb_define_module_function(cNWScript, "Get2DAString", NWScript_Get2DAString, 3);
    rb_define_module_function(cNWScript, "EffectEthereal", NWScript_EffectEthereal, 0);
    rb_define_module_function(cNWScript, "GetAILevel", NWScript_GetAILevel, -1);
    rb_define_module_function(cNWScript, "SetAILevel", NWScript_SetAILevel, 2);
    rb_define_module_function(cNWScript, "GetIsPossessedFamiliar", NWScript_GetIsPossessedFamiliar, 1);
    rb_define_module_function(cNWScript, "UnpossessFamiliar", NWScript_UnpossessFamiliar, 1);
    rb_define_module_function(cNWScript, "GetIsAreaInterior", NWScript_GetIsAreaInterior, -1);
    rb_define_module_function(cNWScript, "SendMessageToPCByStrRef", NWScript_SendMessageToPCByStrRef, 2);
    rb_define_module_function(cNWScript, "IncrementRemainingFeatUses", NWScript_IncrementRemainingFeatUses, 2);
    rb_define_module_function(cNWScript, "ExportSingleCharacter", NWScript_ExportSingleCharacter, 1);
    rb_define_module_function(cNWScript, "PlaySoundByStrRef", NWScript_PlaySoundByStrRef, -1);
    rb_define_module_function(cNWScript, "SetSubRace", NWScript_SetSubRace, 2);
    rb_define_module_function(cNWScript, "SetDeity", NWScript_SetDeity, 2);
    rb_define_module_function(cNWScript, "GetIsDMPossessed", NWScript_GetIsDMPossessed, 1);
    rb_define_module_function(cNWScript, "GetWeather", NWScript_GetWeather, 1);
    rb_define_module_function(cNWScript, "GetIsAreaNatural", NWScript_GetIsAreaNatural, 1);
    rb_define_module_function(cNWScript, "GetIsAreaAboveGround", NWScript_GetIsAreaAboveGround, 1);
    rb_define_module_function(cNWScript, "GetPCItemLastEquipped", NWScript_GetPCItemLastEquipped, 0);
    rb_define_module_function(cNWScript, "GetPCItemLastEquippedBy", NWScript_GetPCItemLastEquippedBy, 0);
    rb_define_module_function(cNWScript, "GetPCItemLastUnequipped", NWScript_GetPCItemLastUnequipped, 0);
    rb_define_module_function(cNWScript, "GetPCItemLastUnequippedBy", NWScript_GetPCItemLastUnequippedBy, 0);
    rb_define_module_function(cNWScript, "CopyItemAndModify", NWScript_CopyItemAndModify, -1);
    rb_define_module_function(cNWScript, "GetItemAppearance", NWScript_GetItemAppearance, 3);
    rb_define_module_function(cNWScript, "ItemPropertyOnHitCastSpell", NWScript_ItemPropertyOnHitCastSpell, 2);
    rb_define_module_function(cNWScript, "GetItemPropertySubType", NWScript_GetItemPropertySubType, 1);
    rb_define_module_function(cNWScript, "GetActionMode", NWScript_GetActionMode, 2);
    rb_define_module_function(cNWScript, "SetActionMode", NWScript_SetActionMode, 3);
    rb_define_module_function(cNWScript, "GetArcaneSpellFailure", NWScript_GetArcaneSpellFailure, 1);
    rb_define_module_function(cNWScript, "ActionExamine", NWScript_ActionExamine, 1);
    rb_define_module_function(cNWScript, "ItemPropertyVisualEffect", NWScript_ItemPropertyVisualEffect, 1);
    rb_define_module_function(cNWScript, "SetLootable", NWScript_SetLootable, 2);
    rb_define_module_function(cNWScript, "GetLootable", NWScript_GetLootable, 1);
    rb_define_module_function(cNWScript, "GetCutsceneCameraMoveRate", NWScript_GetCutsceneCameraMoveRate, 1);
    rb_define_module_function(cNWScript, "SetCutsceneCameraMoveRate", NWScript_SetCutsceneCameraMoveRate, 2);
    rb_define_module_function(cNWScript, "GetItemCursedFlag", NWScript_GetItemCursedFlag, 1);
    rb_define_module_function(cNWScript, "SetItemCursedFlag", NWScript_SetItemCursedFlag, 2);
    rb_define_module_function(cNWScript, "SetMaxHenchmen", NWScript_SetMaxHenchmen, 1);
    rb_define_module_function(cNWScript, "GetMaxHenchmen", NWScript_GetMaxHenchmen, 0);
    rb_define_module_function(cNWScript, "GetAssociateType", NWScript_GetAssociateType, 1);
    rb_define_module_function(cNWScript, "GetSpellResistance", NWScript_GetSpellResistance, 1);
    rb_define_module_function(cNWScript, "DayToNight", NWScript_DayToNight, -1);
    rb_define_module_function(cNWScript, "NightToDay", NWScript_NightToDay, -1);
    rb_define_module_function(cNWScript, "LineOfSightObject", NWScript_LineOfSightObject, 2);
    rb_define_module_function(cNWScript, "LineOfSightVector", NWScript_LineOfSightVector, 2);
    rb_define_module_function(cNWScript, "GetLastSpellCastClass", NWScript_GetLastSpellCastClass, 0);
    rb_define_module_function(cNWScript, "SetBaseAttackBonus", NWScript_SetBaseAttackBonus, -1);
    rb_define_module_function(cNWScript, "RestoreBaseAttackBonus", NWScript_RestoreBaseAttackBonus, -1);
    rb_define_module_function(cNWScript, "EffectCutsceneGhost", NWScript_EffectCutsceneGhost, 0);
    rb_define_module_function(cNWScript, "ItemPropertyArcaneSpellFailure", NWScript_ItemPropertyArcaneSpellFailure, 1);
    rb_define_module_function(cNWScript, "GetStoreGold", NWScript_GetStoreGold, 1);
    rb_define_module_function(cNWScript, "SetStoreGold", NWScript_SetStoreGold, 2);
    rb_define_module_function(cNWScript, "GetStoreMaxBuyPrice", NWScript_GetStoreMaxBuyPrice, 1);
    rb_define_module_function(cNWScript, "SetStoreMaxBuyPrice", NWScript_SetStoreMaxBuyPrice, 2);
    rb_define_module_function(cNWScript, "GetStoreIdentifyCost", NWScript_GetStoreIdentifyCost, 1);
    rb_define_module_function(cNWScript, "SetStoreIdentifyCost", NWScript_SetStoreIdentifyCost, 2);
    rb_define_module_function(cNWScript, "SetCreatureAppearanceType", NWScript_SetCreatureAppearanceType, 2);
    rb_define_module_function(cNWScript, "GetCreatureStartingPackage", NWScript_GetCreatureStartingPackage, 1);
    rb_define_module_function(cNWScript, "EffectCutsceneImmobilize", NWScript_EffectCutsceneImmobilize, 0);
    rb_define_module_function(cNWScript, "GetIsInSubArea", NWScript_GetIsInSubArea, -1);
    rb_define_module_function(cNWScript, "GetItemPropertyCostTable", NWScript_GetItemPropertyCostTable, 1);
    rb_define_module_function(cNWScript, "GetItemPropertyCostTableValue", NWScript_GetItemPropertyCostTableValue, 1);
    rb_define_module_function(cNWScript, "GetItemPropertyParam1", NWScript_GetItemPropertyParam1, 1);
    rb_define_module_function(cNWScript, "GetItemPropertyParam1Value", NWScript_GetItemPropertyParam1Value, 1);
    rb_define_module_function(cNWScript, "GetIsCreatureDisarmable", NWScript_GetIsCreatureDisarmable, 1);
    rb_define_module_function(cNWScript, "SetStolenFlag", NWScript_SetStolenFlag, 2);
    rb_define_module_function(cNWScript, "ForceRest", NWScript_ForceRest, 1);
    rb_define_module_function(cNWScript, "SetCameraHeight", NWScript_SetCameraHeight, -1);
    rb_define_module_function(cNWScript, "SetSkyBox", NWScript_SetSkyBox, -1);
    rb_define_module_function(cNWScript, "GetPhenoType", NWScript_GetPhenoType, 1);
    rb_define_module_function(cNWScript, "SetPhenoType", NWScript_SetPhenoType, -1);
    rb_define_module_function(cNWScript, "SetFogColor", NWScript_SetFogColor, -1);
    rb_define_module_function(cNWScript, "GetCutsceneMode", NWScript_GetCutsceneMode, -1);
    rb_define_module_function(cNWScript, "GetSkyBox", NWScript_GetSkyBox, -1);
    rb_define_module_function(cNWScript, "GetFogColor", NWScript_GetFogColor, -1);
    rb_define_module_function(cNWScript, "SetFogAmount", NWScript_SetFogAmount, -1);
    rb_define_module_function(cNWScript, "GetFogAmount", NWScript_GetFogAmount, -1);
    rb_define_module_function(cNWScript, "GetPickpocketableFlag", NWScript_GetPickpocketableFlag, 1);
    rb_define_module_function(cNWScript, "SetPickpocketableFlag", NWScript_SetPickpocketableFlag, 2);
    rb_define_module_function(cNWScript, "GetFootstepType", NWScript_GetFootstepType, -1);
    rb_define_module_function(cNWScript, "SetFootstepType", NWScript_SetFootstepType, -1);
    rb_define_module_function(cNWScript, "GetCreatureWingType", NWScript_GetCreatureWingType, -1);
    rb_define_module_function(cNWScript, "SetCreatureWingType", NWScript_SetCreatureWingType, -1);
    rb_define_module_function(cNWScript, "GetCreatureBodyPart", NWScript_GetCreatureBodyPart, -1);
    rb_define_module_function(cNWScript, "SetCreatureBodyPart", NWScript_SetCreatureBodyPart, -1);
    rb_define_module_function(cNWScript, "GetCreatureTailType", NWScript_GetCreatureTailType, -1);
    rb_define_module_function(cNWScript, "SetCreatureTailType", NWScript_SetCreatureTailType, -1);
    rb_define_module_function(cNWScript, "GetHardness", NWScript_GetHardness, -1);
    rb_define_module_function(cNWScript, "SetHardness", NWScript_SetHardness, -1);
    rb_define_module_function(cNWScript, "SetLockKeyRequired", NWScript_SetLockKeyRequired, -1);
    rb_define_module_function(cNWScript, "SetLockKeyTag", NWScript_SetLockKeyTag, 2);
    rb_define_module_function(cNWScript, "SetLockLockable", NWScript_SetLockLockable, -1);
    rb_define_module_function(cNWScript, "SetLockUnlockDC", NWScript_SetLockUnlockDC, 2);
    rb_define_module_function(cNWScript, "SetLockLockDC", NWScript_SetLockLockDC, 2);
    rb_define_module_function(cNWScript, "SetTrapDisarmable", NWScript_SetTrapDisarmable, -1);
    rb_define_module_function(cNWScript, "SetTrapDetectable", NWScript_SetTrapDetectable, -1);
    rb_define_module_function(cNWScript, "SetTrapOneShot", NWScript_SetTrapOneShot, -1);
    rb_define_module_function(cNWScript, "SetTrapKeyTag", NWScript_SetTrapKeyTag, 2);
    rb_define_module_function(cNWScript, "SetTrapDisarmDC", NWScript_SetTrapDisarmDC, 2);
    rb_define_module_function(cNWScript, "SetTrapDetectDC", NWScript_SetTrapDetectDC, 2);
    rb_define_module_function(cNWScript, "CreateTrapAtLocation", NWScript_CreateTrapAtLocation, -1);
    rb_define_module_function(cNWScript, "CreateTrapOnObject", NWScript_CreateTrapOnObject, -1);
    rb_define_module_function(cNWScript, "SetWillSavingThrow", NWScript_SetWillSavingThrow, 2);
    rb_define_module_function(cNWScript, "SetReflexSavingThrow", NWScript_SetReflexSavingThrow, 2);
    rb_define_module_function(cNWScript, "SetFortitudeSavingThrow", NWScript_SetFortitudeSavingThrow, 2);
    rb_define_module_function(cNWScript, "GetTilesetResRef", NWScript_GetTilesetResRef, 1);
    rb_define_module_function(cNWScript, "GetTrapRecoverable", NWScript_GetTrapRecoverable, 1);
    rb_define_module_function(cNWScript, "SetTrapRecoverable", NWScript_SetTrapRecoverable, -1);
    rb_define_module_function(cNWScript, "GetModuleXPScale", NWScript_GetModuleXPScale, 0);
    rb_define_module_function(cNWScript, "SetModuleXPScale", NWScript_SetModuleXPScale, 1);
    rb_define_module_function(cNWScript, "GetKeyRequiredFeedback", NWScript_GetKeyRequiredFeedback, 1);
    rb_define_module_function(cNWScript, "SetKeyRequiredFeedback", NWScript_SetKeyRequiredFeedback, 2);
    rb_define_module_function(cNWScript, "GetTrapActive", NWScript_GetTrapActive, 1);
    rb_define_module_function(cNWScript, "SetTrapActive", NWScript_SetTrapActive, -1);
    rb_define_module_function(cNWScript, "LockCameraPitch", NWScript_LockCameraPitch, -1);
    rb_define_module_function(cNWScript, "LockCameraDistance", NWScript_LockCameraDistance, -1);
    rb_define_module_function(cNWScript, "LockCameraDirection", NWScript_LockCameraDirection, -1);
    rb_define_module_function(cNWScript, "GetPlaceableLastClickedBy", NWScript_GetPlaceableLastClickedBy, 0);
    rb_define_module_function(cNWScript, "GetInfiniteFlag", NWScript_GetInfiniteFlag, 1);
    rb_define_module_function(cNWScript, "SetInfiniteFlag", NWScript_SetInfiniteFlag, -1);
    rb_define_module_function(cNWScript, "GetAreaSize", NWScript_GetAreaSize, -1);
    rb_define_module_function(cNWScript, "SetName", NWScript_SetName, -1);
    rb_define_module_function(cNWScript, "GetPortraitId", NWScript_GetPortraitId, -1);
    rb_define_module_function(cNWScript, "SetPortraitId", NWScript_SetPortraitId, 2);
    rb_define_module_function(cNWScript, "GetPortraitResRef", NWScript_GetPortraitResRef, -1);
    rb_define_module_function(cNWScript, "SetPortraitResRef", NWScript_SetPortraitResRef, 2);
    rb_define_module_function(cNWScript, "SetUseableFlag", NWScript_SetUseableFlag, 2);
    rb_define_module_function(cNWScript, "GetDescription", NWScript_GetDescription, -1);
    rb_define_module_function(cNWScript, "SetDescription", NWScript_SetDescription, -1);
    rb_define_module_function(cNWScript, "GetPCChatSpeaker", NWScript_GetPCChatSpeaker, 0);
    rb_define_module_function(cNWScript, "GetPCChatMessage", NWScript_GetPCChatMessage, 0);
    rb_define_module_function(cNWScript, "GetPCChatVolume", NWScript_GetPCChatVolume, 0);
    rb_define_module_function(cNWScript, "SetPCChatMessage", NWScript_SetPCChatMessage, -1);
    rb_define_module_function(cNWScript, "SetPCChatVolume", NWScript_SetPCChatVolume, -1);
    rb_define_module_function(cNWScript, "GetColor", NWScript_GetColor, 2);
    rb_define_module_function(cNWScript, "SetColor", NWScript_SetColor, 3);
    rb_define_module_function(cNWScript, "ItemPropertyMaterial", NWScript_ItemPropertyMaterial, 1);
    rb_define_module_function(cNWScript, "ItemPropertyQuality", NWScript_ItemPropertyQuality, 1);
    rb_define_module_function(cNWScript, "ItemPropertyAdditional", NWScript_ItemPropertyAdditional, 1);

    rb_define_class_variable(cNWScript, "@@retval", INT2NUM(0));
    return cNWScript;
}

static VALUE RubyInt_GetObjectSelf(ID id, VALUE *data)
{
    return UINT2NUM(GetObjectSelf());
}

static VALUE vector_get_x(VALUE self)
{
    Vector *ptr;
    Data_Get_Struct(self, Vector, ptr);
    return rb_float_new(ptr->X);
}
static VALUE vector_get_y(VALUE self)
{
    Vector *ptr;
    Data_Get_Struct(self, Vector, ptr);
    return rb_float_new(ptr->Y);
}
static VALUE vector_get_z(VALUE self)
{
    Vector *ptr;
    Data_Get_Struct(self, Vector, ptr);
    return rb_float_new(ptr->Z);
}

static VALUE location_get_x(VALUE self)
{
    CScriptLocation *ptr;
    Data_Get_Struct(self, CScriptLocation, ptr);
    return rb_float_new(ptr->X);
}
static VALUE location_get_y(VALUE self)
{
    CScriptLocation *ptr;
    Data_Get_Struct(self, CScriptLocation, ptr);
    return rb_float_new(ptr->Y);
}
static VALUE location_get_z(VALUE self)
{
    CScriptLocation *ptr;
    Data_Get_Struct(self, CScriptLocation, ptr);
    return rb_float_new(ptr->Z);
}
static VALUE location_get_area_id(VALUE self)
{
    CScriptLocation *ptr;
    Data_Get_Struct(self, CScriptLocation, ptr);
    return rb_int_new(ptr->AreaID);
}
static VALUE location_get_facing(VALUE self)
{
    CScriptLocation *ptr;
    Data_Get_Struct(self, CScriptLocation, ptr);
    return rb_float_new(ptr->OrientationX);
}

void RubyInt_DefineConstants()
{
    VALUE cNWScript = rb_define_module("NWScript");
    g_cEffectClass = rb_define_class_under(cNWScript, "Effect", rb_cObject); /* ::NWScript::Effect */
    g_cItemPropertyClass = rb_define_class_under(cNWScript, "ItemProperty", rb_cObject); /* ::NWScript::ItemProperty */
    g_cLocationClass = rb_define_class_under(cNWScript, "Location", rb_cObject); /* ::NWScript::Location */
    rb_define_method(g_cLocationClass, "x", location_get_x, 0);
    rb_define_method(g_cLocationClass, "y", location_get_y, 0);
    rb_define_method(g_cLocationClass, "z", location_get_z, 0);
    rb_define_method(g_cLocationClass, "area", location_get_area_id, 0);
    rb_define_method(g_cLocationClass, "facing", location_get_facing, 0);

    g_cVectorClass = rb_define_class_under(cNWScript, "Vector", rb_cObject); /* ::NWScript::Vector */
    rb_define_virtual_variable("OBJECT_SELF", RubyInt_GetObjectSelf, 0);
    rb_define_method(g_cVectorClass, "x", vector_get_x, 0);
    rb_define_method(g_cVectorClass, "y", vector_get_y, 0);
    rb_define_method(g_cVectorClass, "z", vector_get_z, 0);

    rb_define_const(cNWScript, "NUM_INVENTORY_SLOTS", INT2NUM(18));
    rb_define_const(cNWScript, "TRUE", INT2NUM(1));
    rb_define_const(cNWScript, "FALSE", INT2NUM(0));
    rb_define_const(cNWScript, "DIRECTION_EAST", rb_float_new(0.0));
    rb_define_const(cNWScript, "DIRECTION_NORTH", rb_float_new(90.0));
    rb_define_const(cNWScript, "DIRECTION_WEST", rb_float_new(180.0));
    rb_define_const(cNWScript, "DIRECTION_SOUTH", rb_float_new(270.0));
    rb_define_const(cNWScript, "PI", rb_float_new(3.141592));
    rb_define_const(cNWScript, "ATTITUDE_NEUTRAL", INT2NUM(0));
    rb_define_const(cNWScript, "ATTITUDE_AGGRESSIVE", INT2NUM(1));
    rb_define_const(cNWScript, "ATTITUDE_DEFENSIVE", INT2NUM(2));
    rb_define_const(cNWScript, "ATTITUDE_SPECIAL", INT2NUM(3));
    rb_define_const(cNWScript, "TALKVOLUME_TALK", INT2NUM(0));
    rb_define_const(cNWScript, "TALKVOLUME_WHISPER", INT2NUM(1));
    rb_define_const(cNWScript, "TALKVOLUME_SHOUT", INT2NUM(2));
    rb_define_const(cNWScript, "TALKVOLUME_SILENT_TALK", INT2NUM(3));
    rb_define_const(cNWScript, "TALKVOLUME_SILENT_SHOUT", INT2NUM(4));
    rb_define_const(cNWScript, "TALKVOLUME_PARTY", INT2NUM(5));
    rb_define_const(cNWScript, "TALKVOLUME_TELL", INT2NUM(6));
    rb_define_const(cNWScript, "INVENTORY_SLOT_HEAD", INT2NUM(0));
    rb_define_const(cNWScript, "INVENTORY_SLOT_CHEST", INT2NUM(1));
    rb_define_const(cNWScript, "INVENTORY_SLOT_BOOTS", INT2NUM(2));
    rb_define_const(cNWScript, "INVENTORY_SLOT_ARMS", INT2NUM(3));
    rb_define_const(cNWScript, "INVENTORY_SLOT_RIGHTHAND", INT2NUM(4));
    rb_define_const(cNWScript, "INVENTORY_SLOT_LEFTHAND", INT2NUM(5));
    rb_define_const(cNWScript, "INVENTORY_SLOT_CLOAK", INT2NUM(6));
    rb_define_const(cNWScript, "INVENTORY_SLOT_LEFTRING", INT2NUM(7));
    rb_define_const(cNWScript, "INVENTORY_SLOT_RIGHTRING", INT2NUM(8));
    rb_define_const(cNWScript, "INVENTORY_SLOT_NECK", INT2NUM(9));
    rb_define_const(cNWScript, "INVENTORY_SLOT_BELT", INT2NUM(10));
    rb_define_const(cNWScript, "INVENTORY_SLOT_ARROWS", INT2NUM(11));
    rb_define_const(cNWScript, "INVENTORY_SLOT_BULLETS", INT2NUM(12));
    rb_define_const(cNWScript, "INVENTORY_SLOT_BOLTS", INT2NUM(13));
    rb_define_const(cNWScript, "INVENTORY_SLOT_CWEAPON_L", INT2NUM(14));
    rb_define_const(cNWScript, "INVENTORY_SLOT_CWEAPON_R", INT2NUM(15));
    rb_define_const(cNWScript, "INVENTORY_SLOT_CWEAPON_B", INT2NUM(16));
    rb_define_const(cNWScript, "INVENTORY_SLOT_CARMOUR", INT2NUM(17));
    rb_define_const(cNWScript, "DURATION_TYPE_INSTANT", INT2NUM(0));
    rb_define_const(cNWScript, "DURATION_TYPE_TEMPORARY", INT2NUM(1));
    rb_define_const(cNWScript, "DURATION_TYPE_PERMANENT", INT2NUM(2));
    rb_define_const(cNWScript, "SUBTYPE_MAGICAL", INT2NUM(8));
    rb_define_const(cNWScript, "SUBTYPE_SUPERNATURAL", INT2NUM(16));
    rb_define_const(cNWScript, "SUBTYPE_EXTRAORDINARY", INT2NUM(24));
    rb_define_const(cNWScript, "ABILITY_STRENGTH", INT2NUM(0));
    rb_define_const(cNWScript, "ABILITY_DEXTERITY", INT2NUM(1));
    rb_define_const(cNWScript, "ABILITY_CONSTITUTION", INT2NUM(2));
    rb_define_const(cNWScript, "ABILITY_INTELLIGENCE", INT2NUM(3));
    rb_define_const(cNWScript, "ABILITY_WISDOM", INT2NUM(4));
    rb_define_const(cNWScript, "ABILITY_CHARISMA", INT2NUM(5));
    rb_define_const(cNWScript, "SHAPE_SPELLCYLINDER", INT2NUM(0));
    rb_define_const(cNWScript, "SHAPE_CONE", INT2NUM(1));
    rb_define_const(cNWScript, "SHAPE_CUBE", INT2NUM(2));
    rb_define_const(cNWScript, "SHAPE_SPELLCONE", INT2NUM(3));
    rb_define_const(cNWScript, "SHAPE_SPHERE", INT2NUM(4));
    rb_define_const(cNWScript, "METAMAGIC_NONE", INT2NUM(0));
    rb_define_const(cNWScript, "METAMAGIC_EMPOWER", INT2NUM(1));
    rb_define_const(cNWScript, "METAMAGIC_EXTEND", INT2NUM(2));
    rb_define_const(cNWScript, "METAMAGIC_MAXIMIZE", INT2NUM(4));
    rb_define_const(cNWScript, "METAMAGIC_QUICKEN", INT2NUM(8));
    rb_define_const(cNWScript, "METAMAGIC_SILENT", INT2NUM(16));
    rb_define_const(cNWScript, "METAMAGIC_STILL", INT2NUM(32));
    rb_define_const(cNWScript, "METAMAGIC_ANY", INT2NUM(255));
    rb_define_const(cNWScript, "OBJECT_TYPE_CREATURE", INT2NUM(1));
    rb_define_const(cNWScript, "OBJECT_TYPE_ITEM", INT2NUM(2));
    rb_define_const(cNWScript, "OBJECT_TYPE_TRIGGER", INT2NUM(4));
    rb_define_const(cNWScript, "OBJECT_TYPE_DOOR", INT2NUM(8));
    rb_define_const(cNWScript, "OBJECT_TYPE_AREA_OF_EFFECT", INT2NUM(16));
    rb_define_const(cNWScript, "OBJECT_TYPE_WAYPOINT", INT2NUM(32));
    rb_define_const(cNWScript, "OBJECT_TYPE_PLACEABLE", INT2NUM(64));
    rb_define_const(cNWScript, "OBJECT_TYPE_STORE", INT2NUM(128));
    rb_define_const(cNWScript, "OBJECT_TYPE_ENCOUNTER", INT2NUM(256));
    rb_define_const(cNWScript, "OBJECT_TYPE_ALL", INT2NUM(32767));
    rb_define_const(cNWScript, "OBJECT_TYPE_INVALID", INT2NUM(32767));
    rb_define_const(cNWScript, "GENDER_MALE", INT2NUM(0));
    rb_define_const(cNWScript, "GENDER_FEMALE", INT2NUM(1));
    rb_define_const(cNWScript, "GENDER_BOTH", INT2NUM(2));
    rb_define_const(cNWScript, "GENDER_OTHER", INT2NUM(3));
    rb_define_const(cNWScript, "GENDER_NONE", INT2NUM(4));
    rb_define_const(cNWScript, "DAMAGE_TYPE_BLUDGEONING", INT2NUM(1));
    rb_define_const(cNWScript, "DAMAGE_TYPE_PIERCING", INT2NUM(2));
    rb_define_const(cNWScript, "DAMAGE_TYPE_SLASHING", INT2NUM(4));
    rb_define_const(cNWScript, "DAMAGE_TYPE_MAGICAL", INT2NUM(8));
    rb_define_const(cNWScript, "DAMAGE_TYPE_ACID", INT2NUM(16));
    rb_define_const(cNWScript, "DAMAGE_TYPE_COLD", INT2NUM(32));
    rb_define_const(cNWScript, "DAMAGE_TYPE_DIVINE", INT2NUM(64));
    rb_define_const(cNWScript, "DAMAGE_TYPE_ELECTRICAL", INT2NUM(128));
    rb_define_const(cNWScript, "DAMAGE_TYPE_FIRE", INT2NUM(256));
    rb_define_const(cNWScript, "DAMAGE_TYPE_NEGATIVE", INT2NUM(512));
    rb_define_const(cNWScript, "DAMAGE_TYPE_POSITIVE", INT2NUM(1024));
    rb_define_const(cNWScript, "DAMAGE_TYPE_SONIC", INT2NUM(2048));
    rb_define_const(cNWScript, "DAMAGE_TYPE_BASE_WEAPON", INT2NUM(4096));
    rb_define_const(cNWScript, "AC_VS_DAMAGE_TYPE_ALL", INT2NUM(4103));
    rb_define_const(cNWScript, "DAMAGE_BONUS_1", INT2NUM(1));
    rb_define_const(cNWScript, "DAMAGE_BONUS_2", INT2NUM(2));
    rb_define_const(cNWScript, "DAMAGE_BONUS_3", INT2NUM(3));
    rb_define_const(cNWScript, "DAMAGE_BONUS_4", INT2NUM(4));
    rb_define_const(cNWScript, "DAMAGE_BONUS_5", INT2NUM(5));
    rb_define_const(cNWScript, "DAMAGE_BONUS_1d4", INT2NUM(6));
    rb_define_const(cNWScript, "DAMAGE_BONUS_1d6", INT2NUM(7));
    rb_define_const(cNWScript, "DAMAGE_BONUS_1d8", INT2NUM(8));
    rb_define_const(cNWScript, "DAMAGE_BONUS_1d10", INT2NUM(9));
    rb_define_const(cNWScript, "DAMAGE_BONUS_2d6", INT2NUM(10));
    rb_define_const(cNWScript, "DAMAGE_BONUS_2d8", INT2NUM(11));
    rb_define_const(cNWScript, "DAMAGE_BONUS_2d4", INT2NUM(12));
    rb_define_const(cNWScript, "DAMAGE_BONUS_2d10", INT2NUM(13));
    rb_define_const(cNWScript, "DAMAGE_BONUS_1d12", INT2NUM(14));
    rb_define_const(cNWScript, "DAMAGE_BONUS_2d12", INT2NUM(15));
    rb_define_const(cNWScript, "DAMAGE_BONUS_6", INT2NUM(16));
    rb_define_const(cNWScript, "DAMAGE_BONUS_7", INT2NUM(17));
    rb_define_const(cNWScript, "DAMAGE_BONUS_8", INT2NUM(18));
    rb_define_const(cNWScript, "DAMAGE_BONUS_9", INT2NUM(19));
    rb_define_const(cNWScript, "DAMAGE_BONUS_10", INT2NUM(20));
    rb_define_const(cNWScript, "DAMAGE_BONUS_11", INT2NUM(21));
    rb_define_const(cNWScript, "DAMAGE_BONUS_12", INT2NUM(22));
    rb_define_const(cNWScript, "DAMAGE_BONUS_13", INT2NUM(23));
    rb_define_const(cNWScript, "DAMAGE_BONUS_14", INT2NUM(24));
    rb_define_const(cNWScript, "DAMAGE_BONUS_15", INT2NUM(25));
    rb_define_const(cNWScript, "DAMAGE_BONUS_16", INT2NUM(26));
    rb_define_const(cNWScript, "DAMAGE_BONUS_17", INT2NUM(27));
    rb_define_const(cNWScript, "DAMAGE_BONUS_18", INT2NUM(28));
    rb_define_const(cNWScript, "DAMAGE_BONUS_19", INT2NUM(29));
    rb_define_const(cNWScript, "DAMAGE_BONUS_20", INT2NUM(30));
    rb_define_const(cNWScript, "DAMAGE_POWER_NORMAL", INT2NUM(0));
    rb_define_const(cNWScript, "DAMAGE_POWER_PLUS_ONE", INT2NUM(1));
    rb_define_const(cNWScript, "DAMAGE_POWER_PLUS_TWO", INT2NUM(2));
    rb_define_const(cNWScript, "DAMAGE_POWER_PLUS_THREE", INT2NUM(3));
    rb_define_const(cNWScript, "DAMAGE_POWER_PLUS_FOUR", INT2NUM(4));
    rb_define_const(cNWScript, "DAMAGE_POWER_PLUS_FIVE", INT2NUM(5));
    rb_define_const(cNWScript, "DAMAGE_POWER_ENERGY", INT2NUM(6));
    rb_define_const(cNWScript, "DAMAGE_POWER_PLUS_SIX", INT2NUM(7));
    rb_define_const(cNWScript, "DAMAGE_POWER_PLUS_SEVEN", INT2NUM(8));
    rb_define_const(cNWScript, "DAMAGE_POWER_PLUS_EIGHT", INT2NUM(9));
    rb_define_const(cNWScript, "DAMAGE_POWER_PLUS_NINE", INT2NUM(10));
    rb_define_const(cNWScript, "DAMAGE_POWER_PLUS_TEN", INT2NUM(11));
    rb_define_const(cNWScript, "DAMAGE_POWER_PLUS_ELEVEN", INT2NUM(12));
    rb_define_const(cNWScript, "DAMAGE_POWER_PLUS_TWELVE", INT2NUM(13));
    rb_define_const(cNWScript, "DAMAGE_POWER_PLUS_THIRTEEN", INT2NUM(14));
    rb_define_const(cNWScript, "DAMAGE_POWER_PLUS_FOURTEEN", INT2NUM(15));
    rb_define_const(cNWScript, "DAMAGE_POWER_PLUS_FIFTEEN", INT2NUM(16));
    rb_define_const(cNWScript, "DAMAGE_POWER_PLUS_SIXTEEN", INT2NUM(17));
    rb_define_const(cNWScript, "DAMAGE_POWER_PLUS_SEVENTEEN", INT2NUM(18));
    rb_define_const(cNWScript, "DAMAGE_POWER_PLUS_EIGHTEEN", INT2NUM(19));
    rb_define_const(cNWScript, "DAMAGE_POWER_PLUS_NINTEEN", INT2NUM(20));
    rb_define_const(cNWScript, "DAMAGE_POWER_PLUS_TWENTY", INT2NUM(21));
    rb_define_const(cNWScript, "ATTACK_BONUS_MISC", INT2NUM(0));
    rb_define_const(cNWScript, "ATTACK_BONUS_ONHAND", INT2NUM(1));
    rb_define_const(cNWScript, "ATTACK_BONUS_OFFHAND", INT2NUM(2));
    rb_define_const(cNWScript, "AC_DODGE_BONUS", INT2NUM(0));
    rb_define_const(cNWScript, "AC_NATURAL_BONUS", INT2NUM(1));
    rb_define_const(cNWScript, "AC_ARMOUR_ENCHANTMENT_BONUS", INT2NUM(2));
    rb_define_const(cNWScript, "AC_SHIELD_ENCHANTMENT_BONUS", INT2NUM(3));
    rb_define_const(cNWScript, "AC_DEFLECTION_BONUS", INT2NUM(4));
    rb_define_const(cNWScript, "MISS_CHANCE_TYPE_NORMAL", INT2NUM(0));
    rb_define_const(cNWScript, "MISS_CHANCE_TYPE_VS_RANGED", INT2NUM(1));
    rb_define_const(cNWScript, "MISS_CHANCE_TYPE_VS_MELEE", INT2NUM(2));
    rb_define_const(cNWScript, "DOOR_ACTION_OPEN", INT2NUM(0));
    rb_define_const(cNWScript, "DOOR_ACTION_UNLOCK", INT2NUM(1));
    rb_define_const(cNWScript, "DOOR_ACTION_BASH", INT2NUM(2));
    rb_define_const(cNWScript, "DOOR_ACTION_IGNORE", INT2NUM(3));
    rb_define_const(cNWScript, "DOOR_ACTION_KNOCK", INT2NUM(4));
    rb_define_const(cNWScript, "PLACEABLE_ACTION_USE", INT2NUM(0));
    rb_define_const(cNWScript, "PLACEABLE_ACTION_UNLOCK", INT2NUM(1));
    rb_define_const(cNWScript, "PLACEABLE_ACTION_BASH", INT2NUM(2));
    rb_define_const(cNWScript, "PLACEABLE_ACTION_KNOCK", INT2NUM(4));
    rb_define_const(cNWScript, "RACIAL_TYPE_DWARF", INT2NUM(0));
    rb_define_const(cNWScript, "RACIAL_TYPE_ELF", INT2NUM(1));
    rb_define_const(cNWScript, "RACIAL_TYPE_GNOME", INT2NUM(2));
    rb_define_const(cNWScript, "RACIAL_TYPE_HALFLING", INT2NUM(3));
    rb_define_const(cNWScript, "RACIAL_TYPE_HALFELF", INT2NUM(4));
    rb_define_const(cNWScript, "RACIAL_TYPE_HALFORC", INT2NUM(5));
    rb_define_const(cNWScript, "RACIAL_TYPE_HUMAN", INT2NUM(6));
    rb_define_const(cNWScript, "RACIAL_TYPE_ABERRATION", INT2NUM(7));
    rb_define_const(cNWScript, "RACIAL_TYPE_ANIMAL", INT2NUM(8));
    rb_define_const(cNWScript, "RACIAL_TYPE_BEAST", INT2NUM(9));
    rb_define_const(cNWScript, "RACIAL_TYPE_CONSTRUCT", INT2NUM(10));
    rb_define_const(cNWScript, "RACIAL_TYPE_DRAGON", INT2NUM(11));
    rb_define_const(cNWScript, "RACIAL_TYPE_HUMANOID_GOBLINOID", INT2NUM(12));
    rb_define_const(cNWScript, "RACIAL_TYPE_HUMANOID_MONSTROUS", INT2NUM(13));
    rb_define_const(cNWScript, "RACIAL_TYPE_HUMANOID_ORC", INT2NUM(14));
    rb_define_const(cNWScript, "RACIAL_TYPE_HUMANOID_REPTILIAN", INT2NUM(15));
    rb_define_const(cNWScript, "RACIAL_TYPE_ELEMENTAL", INT2NUM(16));
    rb_define_const(cNWScript, "RACIAL_TYPE_FEY", INT2NUM(17));
    rb_define_const(cNWScript, "RACIAL_TYPE_GIANT", INT2NUM(18));
    rb_define_const(cNWScript, "RACIAL_TYPE_MAGICAL_BEAST", INT2NUM(19));
    rb_define_const(cNWScript, "RACIAL_TYPE_OUTSIDER", INT2NUM(20));
    rb_define_const(cNWScript, "RACIAL_TYPE_SHAPECHANGER", INT2NUM(23));
    rb_define_const(cNWScript, "RACIAL_TYPE_UNDEAD", INT2NUM(24));
    rb_define_const(cNWScript, "RACIAL_TYPE_VERMIN", INT2NUM(25));
    rb_define_const(cNWScript, "RACIAL_TYPE_ALL", INT2NUM(28));
    rb_define_const(cNWScript, "RACIAL_TYPE_INVALID", INT2NUM(28));
    rb_define_const(cNWScript, "RACIAL_TYPE_OOZE", INT2NUM(29));
    rb_define_const(cNWScript, "ALIGNMENT_ALL", INT2NUM(0));
    rb_define_const(cNWScript, "ALIGNMENT_NEUTRAL", INT2NUM(1));
    rb_define_const(cNWScript, "ALIGNMENT_LAWFUL", INT2NUM(2));
    rb_define_const(cNWScript, "ALIGNMENT_CHAOTIC", INT2NUM(3));
    rb_define_const(cNWScript, "ALIGNMENT_GOOD", INT2NUM(4));
    rb_define_const(cNWScript, "ALIGNMENT_EVIL", INT2NUM(5));
    rb_define_const(cNWScript, "SAVING_THROW_ALL", INT2NUM(0));
    rb_define_const(cNWScript, "SAVING_THROW_FORT", INT2NUM(1));
    rb_define_const(cNWScript, "SAVING_THROW_REFLEX", INT2NUM(2));
    rb_define_const(cNWScript, "SAVING_THROW_WILL", INT2NUM(3));
    rb_define_const(cNWScript, "SAVING_THROW_TYPE_ALL", INT2NUM(0));
    rb_define_const(cNWScript, "SAVING_THROW_TYPE_NONE", INT2NUM(0));
    rb_define_const(cNWScript, "SAVING_THROW_TYPE_MIND_SPELLS", INT2NUM(1));
    rb_define_const(cNWScript, "SAVING_THROW_TYPE_POISON", INT2NUM(2));
    rb_define_const(cNWScript, "SAVING_THROW_TYPE_DISEASE", INT2NUM(3));
    rb_define_const(cNWScript, "SAVING_THROW_TYPE_FEAR", INT2NUM(4));
    rb_define_const(cNWScript, "SAVING_THROW_TYPE_SONIC", INT2NUM(5));
    rb_define_const(cNWScript, "SAVING_THROW_TYPE_ACID", INT2NUM(6));
    rb_define_const(cNWScript, "SAVING_THROW_TYPE_FIRE", INT2NUM(7));
    rb_define_const(cNWScript, "SAVING_THROW_TYPE_ELECTRICITY", INT2NUM(8));
    rb_define_const(cNWScript, "SAVING_THROW_TYPE_POSITIVE", INT2NUM(9));
    rb_define_const(cNWScript, "SAVING_THROW_TYPE_NEGATIVE", INT2NUM(10));
    rb_define_const(cNWScript, "SAVING_THROW_TYPE_DEATH", INT2NUM(11));
    rb_define_const(cNWScript, "SAVING_THROW_TYPE_COLD", INT2NUM(12));
    rb_define_const(cNWScript, "SAVING_THROW_TYPE_DIVINE", INT2NUM(13));
    rb_define_const(cNWScript, "SAVING_THROW_TYPE_TRAP", INT2NUM(14));
    rb_define_const(cNWScript, "SAVING_THROW_TYPE_SPELL", INT2NUM(15));
    rb_define_const(cNWScript, "SAVING_THROW_TYPE_GOOD", INT2NUM(16));
    rb_define_const(cNWScript, "SAVING_THROW_TYPE_EVIL", INT2NUM(17));
    rb_define_const(cNWScript, "SAVING_THROW_TYPE_LAW", INT2NUM(18));
    rb_define_const(cNWScript, "SAVING_THROW_TYPE_CHAOS", INT2NUM(19));
    rb_define_const(cNWScript, "IMMUNITY_TYPE_NONE", INT2NUM(0));
    rb_define_const(cNWScript, "IMMUNITY_TYPE_MIND_SPELLS", INT2NUM(1));
    rb_define_const(cNWScript, "IMMUNITY_TYPE_POISON", INT2NUM(2));
    rb_define_const(cNWScript, "IMMUNITY_TYPE_DISEASE", INT2NUM(3));
    rb_define_const(cNWScript, "IMMUNITY_TYPE_FEAR", INT2NUM(4));
    rb_define_const(cNWScript, "IMMUNITY_TYPE_TRAP", INT2NUM(5));
    rb_define_const(cNWScript, "IMMUNITY_TYPE_PARALYSIS", INT2NUM(6));
    rb_define_const(cNWScript, "IMMUNITY_TYPE_BLINDNESS", INT2NUM(7));
    rb_define_const(cNWScript, "IMMUNITY_TYPE_DEAFNESS", INT2NUM(8));
    rb_define_const(cNWScript, "IMMUNITY_TYPE_SLOW", INT2NUM(9));
    rb_define_const(cNWScript, "IMMUNITY_TYPE_ENTANGLE", INT2NUM(10));
    rb_define_const(cNWScript, "IMMUNITY_TYPE_SILENCE", INT2NUM(11));
    rb_define_const(cNWScript, "IMMUNITY_TYPE_STUN", INT2NUM(12));
    rb_define_const(cNWScript, "IMMUNITY_TYPE_SLEEP", INT2NUM(13));
    rb_define_const(cNWScript, "IMMUNITY_TYPE_CHARM", INT2NUM(14));
    rb_define_const(cNWScript, "IMMUNITY_TYPE_DOMINATE", INT2NUM(15));
    rb_define_const(cNWScript, "IMMUNITY_TYPE_CONFUSED", INT2NUM(16));
    rb_define_const(cNWScript, "IMMUNITY_TYPE_CURSED", INT2NUM(17));
    rb_define_const(cNWScript, "IMMUNITY_TYPE_DAZED", INT2NUM(18));
    rb_define_const(cNWScript, "IMMUNITY_TYPE_ABILITY_DECREASE", INT2NUM(19));
    rb_define_const(cNWScript, "IMMUNITY_TYPE_ATTACK_DECREASE", INT2NUM(20));
    rb_define_const(cNWScript, "IMMUNITY_TYPE_DAMAGE_DECREASE", INT2NUM(21));
    rb_define_const(cNWScript, "IMMUNITY_TYPE_DAMAGE_IMMUNITY_DECREASE", INT2NUM(22));
    rb_define_const(cNWScript, "IMMUNITY_TYPE_AC_DECREASE", INT2NUM(23));
    rb_define_const(cNWScript, "IMMUNITY_TYPE_MOVEMENT_SPEED_DECREASE", INT2NUM(24));
    rb_define_const(cNWScript, "IMMUNITY_TYPE_SAVING_THROW_DECREASE", INT2NUM(25));
    rb_define_const(cNWScript, "IMMUNITY_TYPE_SPELL_RESISTANCE_DECREASE", INT2NUM(26));
    rb_define_const(cNWScript, "IMMUNITY_TYPE_SKILL_DECREASE", INT2NUM(27));
    rb_define_const(cNWScript, "IMMUNITY_TYPE_KNOCKDOWN", INT2NUM(28));
    rb_define_const(cNWScript, "IMMUNITY_TYPE_NEGATIVE_LEVEL", INT2NUM(29));
    rb_define_const(cNWScript, "IMMUNITY_TYPE_SNEAK_ATTACK", INT2NUM(30));
    rb_define_const(cNWScript, "IMMUNITY_TYPE_CRITICAL_HIT", INT2NUM(31));
    rb_define_const(cNWScript, "IMMUNITY_TYPE_DEATH", INT2NUM(32));
    rb_define_const(cNWScript, "AREA_TRANSITION_RANDOM", INT2NUM(0));
    rb_define_const(cNWScript, "AREA_TRANSITION_USER_DEFINED", INT2NUM(1));
    rb_define_const(cNWScript, "AREA_TRANSITION_CITY_01", INT2NUM(2));
    rb_define_const(cNWScript, "AREA_TRANSITION_CITY_02", INT2NUM(3));
    rb_define_const(cNWScript, "AREA_TRANSITION_CITY_03", INT2NUM(4));
    rb_define_const(cNWScript, "AREA_TRANSITION_CITY_04", INT2NUM(5));
    rb_define_const(cNWScript, "AREA_TRANSITION_CITY_05", INT2NUM(6));
    rb_define_const(cNWScript, "AREA_TRANSITION_CRYPT_01", INT2NUM(7));
    rb_define_const(cNWScript, "AREA_TRANSITION_CRYPT_02", INT2NUM(8));
    rb_define_const(cNWScript, "AREA_TRANSITION_CRYPT_03", INT2NUM(9));
    rb_define_const(cNWScript, "AREA_TRANSITION_CRYPT_04", INT2NUM(10));
    rb_define_const(cNWScript, "AREA_TRANSITION_CRYPT_05", INT2NUM(11));
    rb_define_const(cNWScript, "AREA_TRANSITION_DUNGEON_01", INT2NUM(12));
    rb_define_const(cNWScript, "AREA_TRANSITION_DUNGEON_02", INT2NUM(13));
    rb_define_const(cNWScript, "AREA_TRANSITION_DUNGEON_03", INT2NUM(14));
    rb_define_const(cNWScript, "AREA_TRANSITION_DUNGEON_04", INT2NUM(15));
    rb_define_const(cNWScript, "AREA_TRANSITION_DUNGEON_05", INT2NUM(16));
    rb_define_const(cNWScript, "AREA_TRANSITION_DUNGEON_06", INT2NUM(17));
    rb_define_const(cNWScript, "AREA_TRANSITION_DUNGEON_07", INT2NUM(18));
    rb_define_const(cNWScript, "AREA_TRANSITION_DUNGEON_08", INT2NUM(19));
    rb_define_const(cNWScript, "AREA_TRANSITION_MINES_01", INT2NUM(20));
    rb_define_const(cNWScript, "AREA_TRANSITION_MINES_02", INT2NUM(21));
    rb_define_const(cNWScript, "AREA_TRANSITION_MINES_03", INT2NUM(22));
    rb_define_const(cNWScript, "AREA_TRANSITION_MINES_04", INT2NUM(23));
    rb_define_const(cNWScript, "AREA_TRANSITION_MINES_05", INT2NUM(24));
    rb_define_const(cNWScript, "AREA_TRANSITION_MINES_06", INT2NUM(25));
    rb_define_const(cNWScript, "AREA_TRANSITION_MINES_07", INT2NUM(26));
    rb_define_const(cNWScript, "AREA_TRANSITION_MINES_08", INT2NUM(27));
    rb_define_const(cNWScript, "AREA_TRANSITION_MINES_09", INT2NUM(28));
    rb_define_const(cNWScript, "AREA_TRANSITION_SEWER_01", INT2NUM(29));
    rb_define_const(cNWScript, "AREA_TRANSITION_SEWER_02", INT2NUM(30));
    rb_define_const(cNWScript, "AREA_TRANSITION_SEWER_03", INT2NUM(31));
    rb_define_const(cNWScript, "AREA_TRANSITION_SEWER_04", INT2NUM(32));
    rb_define_const(cNWScript, "AREA_TRANSITION_SEWER_05", INT2NUM(33));
    rb_define_const(cNWScript, "AREA_TRANSITION_CASTLE_01", INT2NUM(34));
    rb_define_const(cNWScript, "AREA_TRANSITION_CASTLE_02", INT2NUM(35));
    rb_define_const(cNWScript, "AREA_TRANSITION_CASTLE_03", INT2NUM(36));
    rb_define_const(cNWScript, "AREA_TRANSITION_CASTLE_04", INT2NUM(37));
    rb_define_const(cNWScript, "AREA_TRANSITION_CASTLE_05", INT2NUM(38));
    rb_define_const(cNWScript, "AREA_TRANSITION_CASTLE_06", INT2NUM(39));
    rb_define_const(cNWScript, "AREA_TRANSITION_CASTLE_07", INT2NUM(40));
    rb_define_const(cNWScript, "AREA_TRANSITION_CASTLE_08", INT2NUM(41));
    rb_define_const(cNWScript, "AREA_TRANSITION_INTERIOR_01", INT2NUM(42));
    rb_define_const(cNWScript, "AREA_TRANSITION_INTERIOR_02", INT2NUM(43));
    rb_define_const(cNWScript, "AREA_TRANSITION_INTERIOR_03", INT2NUM(44));
    rb_define_const(cNWScript, "AREA_TRANSITION_INTERIOR_04", INT2NUM(45));
    rb_define_const(cNWScript, "AREA_TRANSITION_INTERIOR_05", INT2NUM(46));
    rb_define_const(cNWScript, "AREA_TRANSITION_INTERIOR_06", INT2NUM(47));
    rb_define_const(cNWScript, "AREA_TRANSITION_INTERIOR_07", INT2NUM(48));
    rb_define_const(cNWScript, "AREA_TRANSITION_INTERIOR_08", INT2NUM(49));
    rb_define_const(cNWScript, "AREA_TRANSITION_INTERIOR_09", INT2NUM(50));
    rb_define_const(cNWScript, "AREA_TRANSITION_INTERIOR_10", INT2NUM(51));
    rb_define_const(cNWScript, "AREA_TRANSITION_INTERIOR_11", INT2NUM(52));
    rb_define_const(cNWScript, "AREA_TRANSITION_INTERIOR_12", INT2NUM(53));
    rb_define_const(cNWScript, "AREA_TRANSITION_INTERIOR_13", INT2NUM(54));
    rb_define_const(cNWScript, "AREA_TRANSITION_INTERIOR_14", INT2NUM(55));
    rb_define_const(cNWScript, "AREA_TRANSITION_INTERIOR_15", INT2NUM(56));
    rb_define_const(cNWScript, "AREA_TRANSITION_INTERIOR_16", INT2NUM(57));
    rb_define_const(cNWScript, "AREA_TRANSITION_FOREST_01", INT2NUM(58));
    rb_define_const(cNWScript, "AREA_TRANSITION_FOREST_02", INT2NUM(59));
    rb_define_const(cNWScript, "AREA_TRANSITION_FOREST_03", INT2NUM(60));
    rb_define_const(cNWScript, "AREA_TRANSITION_FOREST_04", INT2NUM(61));
    rb_define_const(cNWScript, "AREA_TRANSITION_FOREST_05", INT2NUM(62));
    rb_define_const(cNWScript, "AREA_TRANSITION_RURAL_01", INT2NUM(63));
    rb_define_const(cNWScript, "AREA_TRANSITION_RURAL_02", INT2NUM(64));
    rb_define_const(cNWScript, "AREA_TRANSITION_RURAL_03", INT2NUM(65));
    rb_define_const(cNWScript, "AREA_TRANSITION_RURAL_04", INT2NUM(66));
    rb_define_const(cNWScript, "AREA_TRANSITION_RURAL_05", INT2NUM(67));
    rb_define_const(cNWScript, "AREA_TRANSITION_WRURAL_01", INT2NUM(68));
    rb_define_const(cNWScript, "AREA_TRANSITION_WRURAL_02", INT2NUM(69));
    rb_define_const(cNWScript, "AREA_TRANSITION_WRURAL_03", INT2NUM(70));
    rb_define_const(cNWScript, "AREA_TRANSITION_WRURAL_04", INT2NUM(71));
    rb_define_const(cNWScript, "AREA_TRANSITION_WRURAL_05", INT2NUM(72));
    rb_define_const(cNWScript, "AREA_TRANSITION_DESERT_01", INT2NUM(73));
    rb_define_const(cNWScript, "AREA_TRANSITION_DESERT_02", INT2NUM(74));
    rb_define_const(cNWScript, "AREA_TRANSITION_DESERT_03", INT2NUM(75));
    rb_define_const(cNWScript, "AREA_TRANSITION_DESERT_04", INT2NUM(76));
    rb_define_const(cNWScript, "AREA_TRANSITION_DESERT_05", INT2NUM(77));
    rb_define_const(cNWScript, "AREA_TRANSITION_RUINS_01", INT2NUM(78));
    rb_define_const(cNWScript, "AREA_TRANSITION_RUINS_02", INT2NUM(79));
    rb_define_const(cNWScript, "AREA_TRANSITION_RUINS_03", INT2NUM(80));
    rb_define_const(cNWScript, "AREA_TRANSITION_RUINS_04", INT2NUM(81));
    rb_define_const(cNWScript, "AREA_TRANSITION_RUINS_05", INT2NUM(82));
    rb_define_const(cNWScript, "AREA_TRANSITION_CARAVAN_WINTER", INT2NUM(83));
    rb_define_const(cNWScript, "AREA_TRANSITION_CARAVAN_DESERT", INT2NUM(84));
    rb_define_const(cNWScript, "AREA_TRANSITION_CARAVAN_RURAL", INT2NUM(85));
    rb_define_const(cNWScript, "AREA_TRANSITION_MAGICAL_01", INT2NUM(86));
    rb_define_const(cNWScript, "AREA_TRANSITION_MAGICAL_02", INT2NUM(87));
    rb_define_const(cNWScript, "AREA_TRANSITION_UNDERDARK_01", INT2NUM(88));
    rb_define_const(cNWScript, "AREA_TRANSITION_UNDERDARK_02", INT2NUM(89));
    rb_define_const(cNWScript, "AREA_TRANSITION_UNDERDARK_03", INT2NUM(90));
    rb_define_const(cNWScript, "AREA_TRANSITION_UNDERDARK_04", INT2NUM(91));
    rb_define_const(cNWScript, "AREA_TRANSITION_UNDERDARK_05", INT2NUM(92));
    rb_define_const(cNWScript, "AREA_TRANSITION_UNDERDARK_06", INT2NUM(93));
    rb_define_const(cNWScript, "AREA_TRANSITION_UNDERDARK_07", INT2NUM(94));
    rb_define_const(cNWScript, "AREA_TRANSITION_BEHOLDER_01", INT2NUM(95));
    rb_define_const(cNWScript, "AREA_TRANSITION_BEHOLDER_02", INT2NUM(96));
    rb_define_const(cNWScript, "AREA_TRANSITION_DROW_01", INT2NUM(97));
    rb_define_const(cNWScript, "AREA_TRANSITION_DROW_02", INT2NUM(98));
    rb_define_const(cNWScript, "AREA_TRANSITION_ILLITHID_01", INT2NUM(99));
    rb_define_const(cNWScript, "AREA_TRANSITION_ILLITHID_02", INT2NUM(100));
    rb_define_const(cNWScript, "AREA_TRANSITION_WASTELAND_01", INT2NUM(101));
    rb_define_const(cNWScript, "AREA_TRANSITION_WASTELAND_02", INT2NUM(102));
    rb_define_const(cNWScript, "AREA_TRANSITION_WASTELAND_03", INT2NUM(103));
    rb_define_const(cNWScript, "AREA_TRANSITION_DROW_03", INT2NUM(104));
    rb_define_const(cNWScript, "AREA_TRANSITION_DROW_04", INT2NUM(105));
    rb_define_const(cNWScript, "AREA_TRANSITION_CITY", INT2NUM(2));
    rb_define_const(cNWScript, "AREA_TRANSITION_CRYPT", INT2NUM(7));
    rb_define_const(cNWScript, "AREA_TRANSITION_FOREST", INT2NUM(58));
    rb_define_const(cNWScript, "AREA_TRANSITION_RURAL", INT2NUM(63));
    rb_define_const(cNWScript, "BODY_NODE_HAND", INT2NUM(0));
    rb_define_const(cNWScript, "BODY_NODE_CHEST", INT2NUM(1));
    rb_define_const(cNWScript, "BODY_NODE_MONSTER_0", INT2NUM(2));
    rb_define_const(cNWScript, "BODY_NODE_MONSTER_1", INT2NUM(3));
    rb_define_const(cNWScript, "BODY_NODE_MONSTER_2", INT2NUM(4));
    rb_define_const(cNWScript, "BODY_NODE_MONSTER_3", INT2NUM(5));
    rb_define_const(cNWScript, "BODY_NODE_MONSTER_4", INT2NUM(6));
    rb_define_const(cNWScript, "BODY_NODE_MONSTER_5", INT2NUM(7));
    rb_define_const(cNWScript, "BODY_NODE_MONSTER_6", INT2NUM(8));
    rb_define_const(cNWScript, "BODY_NODE_MONSTER_7", INT2NUM(9));
    rb_define_const(cNWScript, "BODY_NODE_MONSTER_8", INT2NUM(10));
    rb_define_const(cNWScript, "BODY_NODE_MONSTER_9", INT2NUM(11));
    rb_define_const(cNWScript, "RADIUS_SIZE_SMALL", rb_float_new(1.67f));
    rb_define_const(cNWScript, "RADIUS_SIZE_MEDIUM", rb_float_new(3.33f));
    rb_define_const(cNWScript, "RADIUS_SIZE_LARGE", rb_float_new(5.0f));
    rb_define_const(cNWScript, "RADIUS_SIZE_HUGE", rb_float_new(6.67f));
    rb_define_const(cNWScript, "RADIUS_SIZE_GARGANTUAN", rb_float_new(8.33f));
    rb_define_const(cNWScript, "RADIUS_SIZE_COLOSSAL", rb_float_new(10.0f));
    rb_define_const(cNWScript, "EFFECT_TYPE_INVALIDEFFECT", INT2NUM(0));
    rb_define_const(cNWScript, "EFFECT_TYPE_DAMAGE_RESISTANCE", INT2NUM(1));
    rb_define_const(cNWScript, "EFFECT_TYPE_REGENERATE", INT2NUM(3));
    rb_define_const(cNWScript, "EFFECT_TYPE_DAMAGE_REDUCTION", INT2NUM(7));
    rb_define_const(cNWScript, "EFFECT_TYPE_TEMPORARY_HITPOINTS", INT2NUM(9));
    rb_define_const(cNWScript, "EFFECT_TYPE_ENTANGLE", INT2NUM(11));
    rb_define_const(cNWScript, "EFFECT_TYPE_INVULNERABLE", INT2NUM(12));
    rb_define_const(cNWScript, "EFFECT_TYPE_DEAF", INT2NUM(13));
    rb_define_const(cNWScript, "EFFECT_TYPE_RESURRECTION", INT2NUM(14));
    rb_define_const(cNWScript, "EFFECT_TYPE_IMMUNITY", INT2NUM(15));
    rb_define_const(cNWScript, "EFFECT_TYPE_ENEMY_ATTACK_BONUS", INT2NUM(17));
    rb_define_const(cNWScript, "EFFECT_TYPE_ARCANE_SPELL_FAILURE", INT2NUM(18));
    rb_define_const(cNWScript, "EFFECT_TYPE_AREA_OF_EFFECT", INT2NUM(20));
    rb_define_const(cNWScript, "EFFECT_TYPE_BEAM", INT2NUM(21));
    rb_define_const(cNWScript, "EFFECT_TYPE_CHARMED", INT2NUM(23));
    rb_define_const(cNWScript, "EFFECT_TYPE_CONFUSED", INT2NUM(24));
    rb_define_const(cNWScript, "EFFECT_TYPE_FRIGHTENED", INT2NUM(25));
    rb_define_const(cNWScript, "EFFECT_TYPE_DOMINATED", INT2NUM(26));
    rb_define_const(cNWScript, "EFFECT_TYPE_PARALYZE", INT2NUM(27));
    rb_define_const(cNWScript, "EFFECT_TYPE_DAZED", INT2NUM(28));
    rb_define_const(cNWScript, "EFFECT_TYPE_STUNNED", INT2NUM(29));
    rb_define_const(cNWScript, "EFFECT_TYPE_SLEEP", INT2NUM(30));
    rb_define_const(cNWScript, "EFFECT_TYPE_POISON", INT2NUM(31));
    rb_define_const(cNWScript, "EFFECT_TYPE_DISEASE", INT2NUM(32));
    rb_define_const(cNWScript, "EFFECT_TYPE_CURSE", INT2NUM(33));
    rb_define_const(cNWScript, "EFFECT_TYPE_SILENCE", INT2NUM(34));
    rb_define_const(cNWScript, "EFFECT_TYPE_TURNED", INT2NUM(35));
    rb_define_const(cNWScript, "EFFECT_TYPE_HASTE", INT2NUM(36));
    rb_define_const(cNWScript, "EFFECT_TYPE_SLOW", INT2NUM(37));
    rb_define_const(cNWScript, "EFFECT_TYPE_ABILITY_INCREASE", INT2NUM(38));
    rb_define_const(cNWScript, "EFFECT_TYPE_ABILITY_DECREASE", INT2NUM(39));
    rb_define_const(cNWScript, "EFFECT_TYPE_ATTACK_INCREASE", INT2NUM(40));
    rb_define_const(cNWScript, "EFFECT_TYPE_ATTACK_DECREASE", INT2NUM(41));
    rb_define_const(cNWScript, "EFFECT_TYPE_DAMAGE_INCREASE", INT2NUM(42));
    rb_define_const(cNWScript, "EFFECT_TYPE_DAMAGE_DECREASE", INT2NUM(43));
    rb_define_const(cNWScript, "EFFECT_TYPE_DAMAGE_IMMUNITY_INCREASE", INT2NUM(44));
    rb_define_const(cNWScript, "EFFECT_TYPE_DAMAGE_IMMUNITY_DECREASE", INT2NUM(45));
    rb_define_const(cNWScript, "EFFECT_TYPE_AC_INCREASE", INT2NUM(46));
    rb_define_const(cNWScript, "EFFECT_TYPE_AC_DECREASE", INT2NUM(47));
    rb_define_const(cNWScript, "EFFECT_TYPE_MOVEMENT_SPEED_INCREASE", INT2NUM(48));
    rb_define_const(cNWScript, "EFFECT_TYPE_MOVEMENT_SPEED_DECREASE", INT2NUM(49));
    rb_define_const(cNWScript, "EFFECT_TYPE_SAVING_THROW_INCREASE", INT2NUM(50));
    rb_define_const(cNWScript, "EFFECT_TYPE_SAVING_THROW_DECREASE", INT2NUM(51));
    rb_define_const(cNWScript, "EFFECT_TYPE_SPELL_RESISTANCE_INCREASE", INT2NUM(52));
    rb_define_const(cNWScript, "EFFECT_TYPE_SPELL_RESISTANCE_DECREASE", INT2NUM(53));
    rb_define_const(cNWScript, "EFFECT_TYPE_SKILL_INCREASE", INT2NUM(54));
    rb_define_const(cNWScript, "EFFECT_TYPE_SKILL_DECREASE", INT2NUM(55));
    rb_define_const(cNWScript, "EFFECT_TYPE_INVISIBILITY", INT2NUM(56));
    rb_define_const(cNWScript, "EFFECT_TYPE_IMPROVEDINVISIBILITY", INT2NUM(57));
    rb_define_const(cNWScript, "EFFECT_TYPE_DARKNESS", INT2NUM(58));
    rb_define_const(cNWScript, "EFFECT_TYPE_DISPELMAGICALL", INT2NUM(59));
    rb_define_const(cNWScript, "EFFECT_TYPE_ELEMENTALSHIELD", INT2NUM(60));
    rb_define_const(cNWScript, "EFFECT_TYPE_NEGATIVELEVEL", INT2NUM(61));
    rb_define_const(cNWScript, "EFFECT_TYPE_POLYMORPH", INT2NUM(62));
    rb_define_const(cNWScript, "EFFECT_TYPE_SANCTUARY", INT2NUM(63));
    rb_define_const(cNWScript, "EFFECT_TYPE_TRUESEEING", INT2NUM(64));
    rb_define_const(cNWScript, "EFFECT_TYPE_SEEINVISIBLE", INT2NUM(65));
    rb_define_const(cNWScript, "EFFECT_TYPE_TIMESTOP", INT2NUM(66));
    rb_define_const(cNWScript, "EFFECT_TYPE_BLINDNESS", INT2NUM(67));
    rb_define_const(cNWScript, "EFFECT_TYPE_SPELLLEVELABSORPTION", INT2NUM(68));
    rb_define_const(cNWScript, "EFFECT_TYPE_DISPELMAGICBEST", INT2NUM(69));
    rb_define_const(cNWScript, "EFFECT_TYPE_ULTRAVISION", INT2NUM(70));
    rb_define_const(cNWScript, "EFFECT_TYPE_MISS_CHANCE", INT2NUM(71));
    rb_define_const(cNWScript, "EFFECT_TYPE_CONCEALMENT", INT2NUM(72));
    rb_define_const(cNWScript, "EFFECT_TYPE_SPELL_IMMUNITY", INT2NUM(73));
    rb_define_const(cNWScript, "EFFECT_TYPE_VISUALEFFECT", INT2NUM(74));
    rb_define_const(cNWScript, "EFFECT_TYPE_DISAPPEARAPPEAR", INT2NUM(75));
    rb_define_const(cNWScript, "EFFECT_TYPE_SWARM", INT2NUM(76));
    rb_define_const(cNWScript, "EFFECT_TYPE_TURN_RESISTANCE_DECREASE", INT2NUM(77));
    rb_define_const(cNWScript, "EFFECT_TYPE_TURN_RESISTANCE_INCREASE", INT2NUM(78));
    rb_define_const(cNWScript, "EFFECT_TYPE_PETRIFY", INT2NUM(79));
    rb_define_const(cNWScript, "EFFECT_TYPE_CUTSCENE_PARALYZE", INT2NUM(80));
    rb_define_const(cNWScript, "EFFECT_TYPE_ETHEREAL", INT2NUM(81));
    rb_define_const(cNWScript, "EFFECT_TYPE_SPELL_FAILURE", INT2NUM(82));
    rb_define_const(cNWScript, "EFFECT_TYPE_CUTSCENEGHOST", INT2NUM(83));
    rb_define_const(cNWScript, "EFFECT_TYPE_CUTSCENEIMMOBILIZE", INT2NUM(84));
    rb_define_const(cNWScript, "ITEM_APPR_TYPE_SIMPLE_MODEL", INT2NUM(0));
    rb_define_const(cNWScript, "ITEM_APPR_TYPE_WEAPON_COLOR", INT2NUM(1));
    rb_define_const(cNWScript, "ITEM_APPR_TYPE_WEAPON_MODEL", INT2NUM(2));
    rb_define_const(cNWScript, "ITEM_APPR_TYPE_ARMOR_MODEL", INT2NUM(3));
    rb_define_const(cNWScript, "ITEM_APPR_TYPE_ARMOR_COLOR", INT2NUM(4));
    rb_define_const(cNWScript, "ITEM_APPR_NUM_TYPES", INT2NUM(5));
    rb_define_const(cNWScript, "ITEM_APPR_ARMOR_COLOR_LEATHER1", INT2NUM(0));
    rb_define_const(cNWScript, "ITEM_APPR_ARMOR_COLOR_LEATHER2", INT2NUM(1));
    rb_define_const(cNWScript, "ITEM_APPR_ARMOR_COLOR_CLOTH1", INT2NUM(2));
    rb_define_const(cNWScript, "ITEM_APPR_ARMOR_COLOR_CLOTH2", INT2NUM(3));
    rb_define_const(cNWScript, "ITEM_APPR_ARMOR_COLOR_METAL1", INT2NUM(4));
    rb_define_const(cNWScript, "ITEM_APPR_ARMOR_COLOR_METAL2", INT2NUM(5));
    rb_define_const(cNWScript, "ITEM_APPR_ARMOR_NUM_COLORS", INT2NUM(6));
    rb_define_const(cNWScript, "ITEM_APPR_ARMOR_MODEL_RFOOT", INT2NUM(0));
    rb_define_const(cNWScript, "ITEM_APPR_ARMOR_MODEL_LFOOT", INT2NUM(1));
    rb_define_const(cNWScript, "ITEM_APPR_ARMOR_MODEL_RSHIN", INT2NUM(2));
    rb_define_const(cNWScript, "ITEM_APPR_ARMOR_MODEL_LSHIN", INT2NUM(3));
    rb_define_const(cNWScript, "ITEM_APPR_ARMOR_MODEL_LTHIGH", INT2NUM(4));
    rb_define_const(cNWScript, "ITEM_APPR_ARMOR_MODEL_RTHIGH", INT2NUM(5));
    rb_define_const(cNWScript, "ITEM_APPR_ARMOR_MODEL_PELVIS", INT2NUM(6));
    rb_define_const(cNWScript, "ITEM_APPR_ARMOR_MODEL_TORSO", INT2NUM(7));
    rb_define_const(cNWScript, "ITEM_APPR_ARMOR_MODEL_BELT", INT2NUM(8));
    rb_define_const(cNWScript, "ITEM_APPR_ARMOR_MODEL_NECK", INT2NUM(9));
    rb_define_const(cNWScript, "ITEM_APPR_ARMOR_MODEL_RFOREARM", INT2NUM(10));
    rb_define_const(cNWScript, "ITEM_APPR_ARMOR_MODEL_LFOREARM", INT2NUM(11));
    rb_define_const(cNWScript, "ITEM_APPR_ARMOR_MODEL_RBICEP", INT2NUM(12));
    rb_define_const(cNWScript, "ITEM_APPR_ARMOR_MODEL_LBICEP", INT2NUM(13));
    rb_define_const(cNWScript, "ITEM_APPR_ARMOR_MODEL_RSHOULDER", INT2NUM(14));
    rb_define_const(cNWScript, "ITEM_APPR_ARMOR_MODEL_LSHOULDER", INT2NUM(15));
    rb_define_const(cNWScript, "ITEM_APPR_ARMOR_MODEL_RHAND", INT2NUM(16));
    rb_define_const(cNWScript, "ITEM_APPR_ARMOR_MODEL_LHAND", INT2NUM(17));
    rb_define_const(cNWScript, "ITEM_APPR_ARMOR_MODEL_ROBE", INT2NUM(18));
    rb_define_const(cNWScript, "ITEM_APPR_ARMOR_NUM_MODELS", INT2NUM(19));
    rb_define_const(cNWScript, "ITEM_APPR_WEAPON_MODEL_BOTTOM", INT2NUM(0));
    rb_define_const(cNWScript, "ITEM_APPR_WEAPON_MODEL_MIDDLE", INT2NUM(1));
    rb_define_const(cNWScript, "ITEM_APPR_WEAPON_MODEL_TOP", INT2NUM(2));
    rb_define_const(cNWScript, "ITEM_APPR_WEAPON_COLOR_BOTTOM", INT2NUM(0));
    rb_define_const(cNWScript, "ITEM_APPR_WEAPON_COLOR_MIDDLE", INT2NUM(1));
    rb_define_const(cNWScript, "ITEM_APPR_WEAPON_COLOR_TOP", INT2NUM(2));
    rb_define_const(cNWScript, "ITEM_PROPERTY_ABILITY_BONUS", INT2NUM(0));
    rb_define_const(cNWScript, "ITEM_PROPERTY_AC_BONUS", INT2NUM(1));
    rb_define_const(cNWScript, "ITEM_PROPERTY_AC_BONUS_VS_ALIGNMENT_GROUP", INT2NUM(2));
    rb_define_const(cNWScript, "ITEM_PROPERTY_AC_BONUS_VS_DAMAGE_TYPE", INT2NUM(3));
    rb_define_const(cNWScript, "ITEM_PROPERTY_AC_BONUS_VS_RACIAL_GROUP", INT2NUM(4));
    rb_define_const(cNWScript, "ITEM_PROPERTY_AC_BONUS_VS_SPECIFIC_ALIGNMENT", INT2NUM(5));
    rb_define_const(cNWScript, "ITEM_PROPERTY_ENHANCEMENT_BONUS", INT2NUM(6));
    rb_define_const(cNWScript, "ITEM_PROPERTY_ENHANCEMENT_BONUS_VS_ALIGNMENT_GROUP", INT2NUM(7));
    rb_define_const(cNWScript, "ITEM_PROPERTY_ENHANCEMENT_BONUS_VS_RACIAL_GROUP", INT2NUM(8));
    rb_define_const(cNWScript, "ITEM_PROPERTY_ENHANCEMENT_BONUS_VS_SPECIFIC_ALIGNEMENT", INT2NUM(9));
    rb_define_const(cNWScript, "ITEM_PROPERTY_DECREASED_ENHANCEMENT_MODIFIER", INT2NUM(10));
    rb_define_const(cNWScript, "ITEM_PROPERTY_BASE_ITEM_WEIGHT_REDUCTION", INT2NUM(11));
    rb_define_const(cNWScript, "ITEM_PROPERTY_BONUS_FEAT", INT2NUM(12));
    rb_define_const(cNWScript, "ITEM_PROPERTY_BONUS_SPELL_SLOT_OF_LEVEL_N", INT2NUM(13));
    rb_define_const(cNWScript, "ITEM_PROPERTY_CAST_SPELL", INT2NUM(15));
    rb_define_const(cNWScript, "ITEM_PROPERTY_DAMAGE_BONUS", INT2NUM(16));
    rb_define_const(cNWScript, "ITEM_PROPERTY_DAMAGE_BONUS_VS_ALIGNMENT_GROUP", INT2NUM(17));
    rb_define_const(cNWScript, "ITEM_PROPERTY_DAMAGE_BONUS_VS_RACIAL_GROUP", INT2NUM(18));
    rb_define_const(cNWScript, "ITEM_PROPERTY_DAMAGE_BONUS_VS_SPECIFIC_ALIGNMENT", INT2NUM(19));
    rb_define_const(cNWScript, "ITEM_PROPERTY_IMMUNITY_DAMAGE_TYPE", INT2NUM(20));
    rb_define_const(cNWScript, "ITEM_PROPERTY_DECREASED_DAMAGE", INT2NUM(21));
    rb_define_const(cNWScript, "ITEM_PROPERTY_DAMAGE_REDUCTION", INT2NUM(22));
    rb_define_const(cNWScript, "ITEM_PROPERTY_DAMAGE_RESISTANCE", INT2NUM(23));
    rb_define_const(cNWScript, "ITEM_PROPERTY_DAMAGE_VULNERABILITY", INT2NUM(24));
    rb_define_const(cNWScript, "ITEM_PROPERTY_DARKVISION", INT2NUM(26));
    rb_define_const(cNWScript, "ITEM_PROPERTY_DECREASED_ABILITY_SCORE", INT2NUM(27));
    rb_define_const(cNWScript, "ITEM_PROPERTY_DECREASED_AC", INT2NUM(28));
    rb_define_const(cNWScript, "ITEM_PROPERTY_DECREASED_SKILL_MODIFIER", INT2NUM(29));
    rb_define_const(cNWScript, "ITEM_PROPERTY_ENHANCED_CONTAINER_REDUCED_WEIGHT", INT2NUM(32));
    rb_define_const(cNWScript, "ITEM_PROPERTY_EXTRA_MELEE_DAMAGE_TYPE", INT2NUM(33));
    rb_define_const(cNWScript, "ITEM_PROPERTY_EXTRA_RANGED_DAMAGE_TYPE", INT2NUM(34));
    rb_define_const(cNWScript, "ITEM_PROPERTY_HASTE", INT2NUM(35));
    rb_define_const(cNWScript, "ITEM_PROPERTY_HOLY_AVENGER", INT2NUM(36));
    rb_define_const(cNWScript, "ITEM_PROPERTY_IMMUNITY_MISCELLANEOUS", INT2NUM(37));
    rb_define_const(cNWScript, "ITEM_PROPERTY_IMPROVED_EVASION", INT2NUM(38));
    rb_define_const(cNWScript, "ITEM_PROPERTY_SPELL_RESISTANCE", INT2NUM(39));
    rb_define_const(cNWScript, "ITEM_PROPERTY_SAVING_THROW_BONUS", INT2NUM(40));
    rb_define_const(cNWScript, "ITEM_PROPERTY_SAVING_THROW_BONUS_SPECIFIC", INT2NUM(41));
    rb_define_const(cNWScript, "ITEM_PROPERTY_KEEN", INT2NUM(43));
    rb_define_const(cNWScript, "ITEM_PROPERTY_LIGHT", INT2NUM(44));
    rb_define_const(cNWScript, "ITEM_PROPERTY_MIGHTY", INT2NUM(45));
    rb_define_const(cNWScript, "ITEM_PROPERTY_MIND_BLANK", INT2NUM(46));
    rb_define_const(cNWScript, "ITEM_PROPERTY_NO_DAMAGE", INT2NUM(47));
    rb_define_const(cNWScript, "ITEM_PROPERTY_ON_HIT_PROPERTIES", INT2NUM(48));
    rb_define_const(cNWScript, "ITEM_PROPERTY_DECREASED_SAVING_THROWS", INT2NUM(49));
    rb_define_const(cNWScript, "ITEM_PROPERTY_DECREASED_SAVING_THROWS_SPECIFIC", INT2NUM(50));
    rb_define_const(cNWScript, "ITEM_PROPERTY_REGENERATION", INT2NUM(51));
    rb_define_const(cNWScript, "ITEM_PROPERTY_SKILL_BONUS", INT2NUM(52));
    rb_define_const(cNWScript, "ITEM_PROPERTY_IMMUNITY_SPECIFIC_SPELL", INT2NUM(53));
    rb_define_const(cNWScript, "ITEM_PROPERTY_IMMUNITY_SPELL_SCHOOL", INT2NUM(54));
    rb_define_const(cNWScript, "ITEM_PROPERTY_THIEVES_TOOLS", INT2NUM(55));
    rb_define_const(cNWScript, "ITEM_PROPERTY_ATTACK_BONUS", INT2NUM(56));
    rb_define_const(cNWScript, "ITEM_PROPERTY_ATTACK_BONUS_VS_ALIGNMENT_GROUP", INT2NUM(57));
    rb_define_const(cNWScript, "ITEM_PROPERTY_ATTACK_BONUS_VS_RACIAL_GROUP", INT2NUM(58));
    rb_define_const(cNWScript, "ITEM_PROPERTY_ATTACK_BONUS_VS_SPECIFIC_ALIGNMENT", INT2NUM(59));
    rb_define_const(cNWScript, "ITEM_PROPERTY_DECREASED_ATTACK_MODIFIER", INT2NUM(60));
    rb_define_const(cNWScript, "ITEM_PROPERTY_UNLIMITED_AMMUNITION", INT2NUM(61));
    rb_define_const(cNWScript, "ITEM_PROPERTY_USE_LIMITATION_ALIGNMENT_GROUP", INT2NUM(62));
    rb_define_const(cNWScript, "ITEM_PROPERTY_USE_LIMITATION_CLASS", INT2NUM(63));
    rb_define_const(cNWScript, "ITEM_PROPERTY_USE_LIMITATION_RACIAL_TYPE", INT2NUM(64));
    rb_define_const(cNWScript, "ITEM_PROPERTY_USE_LIMITATION_SPECIFIC_ALIGNMENT", INT2NUM(65));
    rb_define_const(cNWScript, "ITEM_PROPERTY_USE_LIMITATION_TILESET", INT2NUM(66));
    rb_define_const(cNWScript, "ITEM_PROPERTY_REGENERATION_VAMPIRIC", INT2NUM(67));
    rb_define_const(cNWScript, "ITEM_PROPERTY_TRAP", INT2NUM(70));
    rb_define_const(cNWScript, "ITEM_PROPERTY_TRUE_SEEING", INT2NUM(71));
    rb_define_const(cNWScript, "ITEM_PROPERTY_ON_MONSTER_HIT", INT2NUM(72));
    rb_define_const(cNWScript, "ITEM_PROPERTY_TURN_RESISTANCE", INT2NUM(73));
    rb_define_const(cNWScript, "ITEM_PROPERTY_MASSIVE_CRITICALS", INT2NUM(74));
    rb_define_const(cNWScript, "ITEM_PROPERTY_FREEDOM_OF_MOVEMENT", INT2NUM(75));
    rb_define_const(cNWScript, "ITEM_PROPERTY_POISON", INT2NUM(76));
    rb_define_const(cNWScript, "ITEM_PROPERTY_MONSTER_DAMAGE", INT2NUM(77));
    rb_define_const(cNWScript, "ITEM_PROPERTY_IMMUNITY_SPELLS_BY_LEVEL", INT2NUM(78));
    rb_define_const(cNWScript, "ITEM_PROPERTY_SPECIAL_WALK", INT2NUM(79));
    rb_define_const(cNWScript, "ITEM_PROPERTY_HEALERS_KIT", INT2NUM(80));
    rb_define_const(cNWScript, "ITEM_PROPERTY_WEIGHT_INCREASE", INT2NUM(81));
    rb_define_const(cNWScript, "ITEM_PROPERTY_ONHITCASTSPELL", INT2NUM(82));
    rb_define_const(cNWScript, "ITEM_PROPERTY_VISUALEFFECT", INT2NUM(83));
    rb_define_const(cNWScript, "ITEM_PROPERTY_ARCANE_SPELL_FAILURE", INT2NUM(84));
    rb_define_const(cNWScript, "ITEM_PROPERTY_MATERIAL", INT2NUM(85));
    rb_define_const(cNWScript, "ITEM_PROPERTY_QUALITY", INT2NUM(86));
    rb_define_const(cNWScript, "ITEM_PROPERTY_ADDITIONAL", INT2NUM(87));
    rb_define_const(cNWScript, "BASE_ITEM_SHORTSWORD", INT2NUM(0));
    rb_define_const(cNWScript, "BASE_ITEM_LONGSWORD", INT2NUM(1));
    rb_define_const(cNWScript, "BASE_ITEM_BATTLEAXE", INT2NUM(2));
    rb_define_const(cNWScript, "BASE_ITEM_BASTARDSWORD", INT2NUM(3));
    rb_define_const(cNWScript, "BASE_ITEM_LIGHTFLAIL", INT2NUM(4));
    rb_define_const(cNWScript, "BASE_ITEM_WARHAMMER", INT2NUM(5));
    rb_define_const(cNWScript, "BASE_ITEM_HEAVYCROSSBOW", INT2NUM(6));
    rb_define_const(cNWScript, "BASE_ITEM_LIGHTCROSSBOW", INT2NUM(7));
    rb_define_const(cNWScript, "BASE_ITEM_LONGBOW", INT2NUM(8));
    rb_define_const(cNWScript, "BASE_ITEM_LIGHTMACE", INT2NUM(9));
    rb_define_const(cNWScript, "BASE_ITEM_HALBERD", INT2NUM(10));
    rb_define_const(cNWScript, "BASE_ITEM_SHORTBOW", INT2NUM(11));
    rb_define_const(cNWScript, "BASE_ITEM_TWOBLADEDSWORD", INT2NUM(12));
    rb_define_const(cNWScript, "BASE_ITEM_GREATSWORD", INT2NUM(13));
    rb_define_const(cNWScript, "BASE_ITEM_SMALLSHIELD", INT2NUM(14));
    rb_define_const(cNWScript, "BASE_ITEM_TORCH", INT2NUM(15));
    rb_define_const(cNWScript, "BASE_ITEM_ARMOR", INT2NUM(16));
    rb_define_const(cNWScript, "BASE_ITEM_HELMET", INT2NUM(17));
    rb_define_const(cNWScript, "BASE_ITEM_GREATAXE", INT2NUM(18));
    rb_define_const(cNWScript, "BASE_ITEM_AMULET", INT2NUM(19));
    rb_define_const(cNWScript, "BASE_ITEM_ARROW", INT2NUM(20));
    rb_define_const(cNWScript, "BASE_ITEM_BELT", INT2NUM(21));
    rb_define_const(cNWScript, "BASE_ITEM_DAGGER", INT2NUM(22));
    rb_define_const(cNWScript, "BASE_ITEM_MISCSMALL", INT2NUM(24));
    rb_define_const(cNWScript, "BASE_ITEM_BOLT", INT2NUM(25));
    rb_define_const(cNWScript, "BASE_ITEM_BOOTS", INT2NUM(26));
    rb_define_const(cNWScript, "BASE_ITEM_BULLET", INT2NUM(27));
    rb_define_const(cNWScript, "BASE_ITEM_CLUB", INT2NUM(28));
    rb_define_const(cNWScript, "BASE_ITEM_MISCMEDIUM", INT2NUM(29));
    rb_define_const(cNWScript, "BASE_ITEM_DART", INT2NUM(31));
    rb_define_const(cNWScript, "BASE_ITEM_DIREMACE", INT2NUM(32));
    rb_define_const(cNWScript, "BASE_ITEM_DOUBLEAXE", INT2NUM(33));
    rb_define_const(cNWScript, "BASE_ITEM_MISCLARGE", INT2NUM(34));
    rb_define_const(cNWScript, "BASE_ITEM_HEAVYFLAIL", INT2NUM(35));
    rb_define_const(cNWScript, "BASE_ITEM_GLOVES", INT2NUM(36));
    rb_define_const(cNWScript, "BASE_ITEM_LIGHTHAMMER", INT2NUM(37));
    rb_define_const(cNWScript, "BASE_ITEM_HANDAXE", INT2NUM(38));
    rb_define_const(cNWScript, "BASE_ITEM_HEALERSKIT", INT2NUM(39));
    rb_define_const(cNWScript, "BASE_ITEM_KAMA", INT2NUM(40));
    rb_define_const(cNWScript, "BASE_ITEM_KATANA", INT2NUM(41));
    rb_define_const(cNWScript, "BASE_ITEM_KUKRI", INT2NUM(42));
    rb_define_const(cNWScript, "BASE_ITEM_MISCTALL", INT2NUM(43));
    rb_define_const(cNWScript, "BASE_ITEM_MAGICROD", INT2NUM(44));
    rb_define_const(cNWScript, "BASE_ITEM_MAGICSTAFF", INT2NUM(45));
    rb_define_const(cNWScript, "BASE_ITEM_MAGICWAND", INT2NUM(46));
    rb_define_const(cNWScript, "BASE_ITEM_MORNINGSTAR", INT2NUM(47));
    rb_define_const(cNWScript, "BASE_ITEM_POTIONS", INT2NUM(49));
    rb_define_const(cNWScript, "BASE_ITEM_QUARTERSTAFF", INT2NUM(50));
    rb_define_const(cNWScript, "BASE_ITEM_RAPIER", INT2NUM(51));
    rb_define_const(cNWScript, "BASE_ITEM_RING", INT2NUM(52));
    rb_define_const(cNWScript, "BASE_ITEM_SCIMITAR", INT2NUM(53));
    rb_define_const(cNWScript, "BASE_ITEM_SCROLL", INT2NUM(54));
    rb_define_const(cNWScript, "BASE_ITEM_SCYTHE", INT2NUM(55));
    rb_define_const(cNWScript, "BASE_ITEM_LARGESHIELD", INT2NUM(56));
    rb_define_const(cNWScript, "BASE_ITEM_TOWERSHIELD", INT2NUM(57));
    rb_define_const(cNWScript, "BASE_ITEM_SHORTSPEAR", INT2NUM(58));
    rb_define_const(cNWScript, "BASE_ITEM_SHURIKEN", INT2NUM(59));
    rb_define_const(cNWScript, "BASE_ITEM_SICKLE", INT2NUM(60));
    rb_define_const(cNWScript, "BASE_ITEM_SLING", INT2NUM(61));
    rb_define_const(cNWScript, "BASE_ITEM_THIEVESTOOLS", INT2NUM(62));
    rb_define_const(cNWScript, "BASE_ITEM_THROWINGAXE", INT2NUM(63));
    rb_define_const(cNWScript, "BASE_ITEM_TRAPKIT", INT2NUM(64));
    rb_define_const(cNWScript, "BASE_ITEM_KEY", INT2NUM(65));
    rb_define_const(cNWScript, "BASE_ITEM_LARGEBOX", INT2NUM(66));
    rb_define_const(cNWScript, "BASE_ITEM_MISCWIDE", INT2NUM(68));
    rb_define_const(cNWScript, "BASE_ITEM_CSLASHWEAPON", INT2NUM(69));
    rb_define_const(cNWScript, "BASE_ITEM_CPIERCWEAPON", INT2NUM(70));
    rb_define_const(cNWScript, "BASE_ITEM_CBLUDGWEAPON", INT2NUM(71));
    rb_define_const(cNWScript, "BASE_ITEM_CSLSHPRCWEAP", INT2NUM(72));
    rb_define_const(cNWScript, "BASE_ITEM_CREATUREITEM", INT2NUM(73));
    rb_define_const(cNWScript, "BASE_ITEM_BOOK", INT2NUM(74));
    rb_define_const(cNWScript, "BASE_ITEM_SPELLSCROLL", INT2NUM(75));
    rb_define_const(cNWScript, "BASE_ITEM_GOLD", INT2NUM(76));
    rb_define_const(cNWScript, "BASE_ITEM_GEM", INT2NUM(77));
    rb_define_const(cNWScript, "BASE_ITEM_BRACER", INT2NUM(78));
    rb_define_const(cNWScript, "BASE_ITEM_MISCTHIN", INT2NUM(79));
    rb_define_const(cNWScript, "BASE_ITEM_CLOAK", INT2NUM(80));
    rb_define_const(cNWScript, "BASE_ITEM_GRENADE", INT2NUM(81));
    rb_define_const(cNWScript, "BASE_ITEM_TRIDENT", INT2NUM(95));
    rb_define_const(cNWScript, "BASE_ITEM_BLANK_POTION", INT2NUM(101));
    rb_define_const(cNWScript, "BASE_ITEM_BLANK_SCROLL", INT2NUM(102));
    rb_define_const(cNWScript, "BASE_ITEM_BLANK_WAND", INT2NUM(103));
    rb_define_const(cNWScript, "BASE_ITEM_ENCHANTED_POTION", INT2NUM(104));
    rb_define_const(cNWScript, "BASE_ITEM_ENCHANTED_SCROLL", INT2NUM(105));
    rb_define_const(cNWScript, "BASE_ITEM_ENCHANTED_WAND", INT2NUM(106));
    rb_define_const(cNWScript, "BASE_ITEM_DWARVENWARAXE", INT2NUM(108));
    rb_define_const(cNWScript, "BASE_ITEM_CRAFTMATERIALMED", INT2NUM(109));
    rb_define_const(cNWScript, "BASE_ITEM_CRAFTMATERIALSML", INT2NUM(110));
    rb_define_const(cNWScript, "BASE_ITEM_WHIP", INT2NUM(111));
    rb_define_const(cNWScript, "BASE_ITEM_INVALID", INT2NUM(256));
    rb_define_const(cNWScript, "VFX_NONE", INT2NUM(-1));
    rb_define_const(cNWScript, "VFX_DUR_BLUR", INT2NUM(0));
    rb_define_const(cNWScript, "VFX_DUR_DARKNESS", INT2NUM(1));
    rb_define_const(cNWScript, "VFX_DUR_ENTANGLE", INT2NUM(2));
    rb_define_const(cNWScript, "VFX_DUR_FREEDOM_OF_MOVEMENT", INT2NUM(3));
    rb_define_const(cNWScript, "VFX_DUR_GLOBE_INVULNERABILITY", INT2NUM(4));
    rb_define_const(cNWScript, "VFX_DUR_BLACKOUT", INT2NUM(5));
    rb_define_const(cNWScript, "VFX_DUR_INVISIBILITY", INT2NUM(6));
    rb_define_const(cNWScript, "VFX_DUR_MIND_AFFECTING_NEGATIVE", INT2NUM(7));
    rb_define_const(cNWScript, "VFX_DUR_MIND_AFFECTING_POSITIVE", INT2NUM(8));
    rb_define_const(cNWScript, "VFX_DUR_GHOSTLY_VISAGE", INT2NUM(9));
    rb_define_const(cNWScript, "VFX_DUR_ETHEREAL_VISAGE", INT2NUM(10));
    rb_define_const(cNWScript, "VFX_DUR_PROT_BARKSKIN", INT2NUM(11));
    rb_define_const(cNWScript, "VFX_DUR_PROT_GREATER_STONESKIN", INT2NUM(12));
    rb_define_const(cNWScript, "VFX_DUR_PROT_PREMONITION", INT2NUM(13));
    rb_define_const(cNWScript, "VFX_DUR_PROT_SHADOW_ARMOR", INT2NUM(14));
    rb_define_const(cNWScript, "VFX_DUR_PROT_STONESKIN", INT2NUM(15));
    rb_define_const(cNWScript, "VFX_DUR_SANCTUARY", INT2NUM(16));
    rb_define_const(cNWScript, "VFX_DUR_WEB", INT2NUM(17));
    rb_define_const(cNWScript, "VFX_FNF_BLINDDEAF", INT2NUM(18));
    rb_define_const(cNWScript, "VFX_FNF_DISPEL", INT2NUM(19));
    rb_define_const(cNWScript, "VFX_FNF_DISPEL_DISJUNCTION", INT2NUM(20));
    rb_define_const(cNWScript, "VFX_FNF_DISPEL_GREATER", INT2NUM(21));
    rb_define_const(cNWScript, "VFX_FNF_FIREBALL", INT2NUM(22));
    rb_define_const(cNWScript, "VFX_FNF_FIRESTORM", INT2NUM(23));
    rb_define_const(cNWScript, "VFX_FNF_IMPLOSION", INT2NUM(24));
    rb_define_const(cNWScript, "VFX_FNF_MASS_HEAL", INT2NUM(26));
    rb_define_const(cNWScript, "VFX_FNF_MASS_MIND_AFFECTING", INT2NUM(27));
    rb_define_const(cNWScript, "VFX_FNF_METEOR_SWARM", INT2NUM(28));
    rb_define_const(cNWScript, "VFX_FNF_NATURES_BALANCE", INT2NUM(29));
    rb_define_const(cNWScript, "VFX_FNF_PWKILL", INT2NUM(30));
    rb_define_const(cNWScript, "VFX_FNF_PWSTUN", INT2NUM(31));
    rb_define_const(cNWScript, "VFX_FNF_SUMMON_GATE", INT2NUM(32));
    rb_define_const(cNWScript, "VFX_FNF_SUMMON_MONSTER_1", INT2NUM(33));
    rb_define_const(cNWScript, "VFX_FNF_SUMMON_MONSTER_2", INT2NUM(34));
    rb_define_const(cNWScript, "VFX_FNF_SUMMON_MONSTER_3", INT2NUM(35));
    rb_define_const(cNWScript, "VFX_FNF_SUMMON_UNDEAD", INT2NUM(36));
    rb_define_const(cNWScript, "VFX_FNF_SUNBEAM", INT2NUM(37));
    rb_define_const(cNWScript, "VFX_FNF_TIME_STOP", INT2NUM(38));
    rb_define_const(cNWScript, "VFX_FNF_WAIL_O_BANSHEES", INT2NUM(39));
    rb_define_const(cNWScript, "VFX_FNF_WEIRD", INT2NUM(40));
    rb_define_const(cNWScript, "VFX_FNF_WORD", INT2NUM(41));
    rb_define_const(cNWScript, "VFX_IMP_AC_BONUS", INT2NUM(42));
    rb_define_const(cNWScript, "VFX_IMP_ACID_L", INT2NUM(43));
    rb_define_const(cNWScript, "VFX_IMP_ACID_S", INT2NUM(44));
    rb_define_const(cNWScript, "VFX_IMP_BLIND_DEAF_M", INT2NUM(46));
    rb_define_const(cNWScript, "VFX_IMP_BREACH", INT2NUM(47));
    rb_define_const(cNWScript, "VFX_IMP_CONFUSION_S", INT2NUM(48));
    rb_define_const(cNWScript, "VFX_IMP_DAZED_S", INT2NUM(49));
    rb_define_const(cNWScript, "VFX_IMP_DEATH", INT2NUM(50));
    rb_define_const(cNWScript, "VFX_IMP_DISEASE_S", INT2NUM(51));
    rb_define_const(cNWScript, "VFX_IMP_DISPEL", INT2NUM(52));
    rb_define_const(cNWScript, "VFX_IMP_DISPEL_DISJUNCTION", INT2NUM(53));
    rb_define_const(cNWScript, "VFX_IMP_DIVINE_STRIKE_FIRE", INT2NUM(54));
    rb_define_const(cNWScript, "VFX_IMP_DIVINE_STRIKE_HOLY", INT2NUM(55));
    rb_define_const(cNWScript, "VFX_IMP_DOMINATE_S", INT2NUM(56));
    rb_define_const(cNWScript, "VFX_IMP_DOOM", INT2NUM(57));
    rb_define_const(cNWScript, "VFX_IMP_FEAR_S", INT2NUM(58));
    rb_define_const(cNWScript, "VFX_IMP_FLAME_M", INT2NUM(60));
    rb_define_const(cNWScript, "VFX_IMP_FLAME_S", INT2NUM(61));
    rb_define_const(cNWScript, "VFX_IMP_FROST_L", INT2NUM(62));
    rb_define_const(cNWScript, "VFX_IMP_FROST_S", INT2NUM(63));
    rb_define_const(cNWScript, "VFX_IMP_GREASE", INT2NUM(64));
    rb_define_const(cNWScript, "VFX_IMP_HASTE", INT2NUM(65));
    rb_define_const(cNWScript, "VFX_IMP_HEALING_G", INT2NUM(66));
    rb_define_const(cNWScript, "VFX_IMP_HEALING_L", INT2NUM(67));
    rb_define_const(cNWScript, "VFX_IMP_HEALING_M", INT2NUM(68));
    rb_define_const(cNWScript, "VFX_IMP_HEALING_S", INT2NUM(69));
    rb_define_const(cNWScript, "VFX_IMP_HEALING_X", INT2NUM(70));
    rb_define_const(cNWScript, "VFX_IMP_HOLY_AID", INT2NUM(71));
    rb_define_const(cNWScript, "VFX_IMP_KNOCK", INT2NUM(72));
    rb_define_const(cNWScript, "VFX_BEAM_LIGHTNING", INT2NUM(73));
    rb_define_const(cNWScript, "VFX_IMP_LIGHTNING_M", INT2NUM(74));
    rb_define_const(cNWScript, "VFX_IMP_LIGHTNING_S", INT2NUM(75));
    rb_define_const(cNWScript, "VFX_IMP_MAGBLUE", INT2NUM(76));
    rb_define_const(cNWScript, "VFX_IMP_NEGATIVE_ENERGY", INT2NUM(81));
    rb_define_const(cNWScript, "VFX_DUR_PARALYZE_HOLD", INT2NUM(82));
    rb_define_const(cNWScript, "VFX_IMP_POISON_L", INT2NUM(83));
    rb_define_const(cNWScript, "VFX_IMP_POISON_S", INT2NUM(84));
    rb_define_const(cNWScript, "VFX_IMP_POLYMORPH", INT2NUM(85));
    rb_define_const(cNWScript, "VFX_IMP_PULSE_COLD", INT2NUM(86));
    rb_define_const(cNWScript, "VFX_IMP_PULSE_FIRE", INT2NUM(87));
    rb_define_const(cNWScript, "VFX_IMP_PULSE_HOLY", INT2NUM(88));
    rb_define_const(cNWScript, "VFX_IMP_PULSE_NEGATIVE", INT2NUM(89));
    rb_define_const(cNWScript, "VFX_IMP_RAISE_DEAD", INT2NUM(90));
    rb_define_const(cNWScript, "VFX_IMP_REDUCE_ABILITY_SCORE", INT2NUM(91));
    rb_define_const(cNWScript, "VFX_IMP_REMOVE_CONDITION", INT2NUM(92));
    rb_define_const(cNWScript, "VFX_IMP_SILENCE", INT2NUM(93));
    rb_define_const(cNWScript, "VFX_IMP_SLEEP", INT2NUM(94));
    rb_define_const(cNWScript, "VFX_IMP_SLOW", INT2NUM(95));
    rb_define_const(cNWScript, "VFX_IMP_SONIC", INT2NUM(96));
    rb_define_const(cNWScript, "VFX_IMP_STUN", INT2NUM(97));
    rb_define_const(cNWScript, "VFX_IMP_SUNSTRIKE", INT2NUM(98));
    rb_define_const(cNWScript, "VFX_IMP_UNSUMMON", INT2NUM(99));
    rb_define_const(cNWScript, "VFX_COM_SPECIAL_BLUE_RED", INT2NUM(100));
    rb_define_const(cNWScript, "VFX_COM_SPECIAL_PINK_ORANGE", INT2NUM(101));
    rb_define_const(cNWScript, "VFX_COM_SPECIAL_RED_WHITE", INT2NUM(102));
    rb_define_const(cNWScript, "VFX_COM_SPECIAL_RED_ORANGE", INT2NUM(103));
    rb_define_const(cNWScript, "VFX_COM_SPECIAL_WHITE_BLUE", INT2NUM(104));
    rb_define_const(cNWScript, "VFX_COM_SPECIAL_WHITE_ORANGE", INT2NUM(105));
    rb_define_const(cNWScript, "VFX_COM_BLOOD_REG_WIMP", INT2NUM(106));
    rb_define_const(cNWScript, "VFX_COM_BLOOD_LRG_WIMP", INT2NUM(107));
    rb_define_const(cNWScript, "VFX_COM_BLOOD_CRT_WIMP", INT2NUM(108));
    rb_define_const(cNWScript, "VFX_COM_BLOOD_REG_RED", INT2NUM(109));
    rb_define_const(cNWScript, "VFX_COM_BLOOD_REG_GREEN", INT2NUM(110));
    rb_define_const(cNWScript, "VFX_COM_BLOOD_REG_YELLOW", INT2NUM(111));
    rb_define_const(cNWScript, "VFX_COM_BLOOD_LRG_RED", INT2NUM(112));
    rb_define_const(cNWScript, "VFX_COM_BLOOD_LRG_GREEN", INT2NUM(113));
    rb_define_const(cNWScript, "VFX_COM_BLOOD_LRG_YELLOW", INT2NUM(114));
    rb_define_const(cNWScript, "VFX_COM_BLOOD_CRT_RED", INT2NUM(115));
    rb_define_const(cNWScript, "VFX_COM_BLOOD_CRT_GREEN", INT2NUM(116));
    rb_define_const(cNWScript, "VFX_COM_BLOOD_CRT_YELLOW", INT2NUM(117));
    rb_define_const(cNWScript, "VFX_COM_SPARKS_PARRY", INT2NUM(118));
    rb_define_const(cNWScript, "VFX_COM_UNLOAD_MODEL", INT2NUM(120));
    rb_define_const(cNWScript, "VFX_COM_CHUNK_RED_SMALL", INT2NUM(121));
    rb_define_const(cNWScript, "VFX_COM_CHUNK_RED_MEDIUM", INT2NUM(122));
    rb_define_const(cNWScript, "VFX_COM_CHUNK_GREEN_SMALL", INT2NUM(123));
    rb_define_const(cNWScript, "VFX_COM_CHUNK_GREEN_MEDIUM", INT2NUM(124));
    rb_define_const(cNWScript, "VFX_COM_CHUNK_YELLOW_SMALL", INT2NUM(125));
    rb_define_const(cNWScript, "VFX_COM_CHUNK_YELLOW_MEDIUM", INT2NUM(126));
    rb_define_const(cNWScript, "VFX_DUR_SPELLTURNING", INT2NUM(138));
    rb_define_const(cNWScript, "VFX_IMP_IMPROVE_ABILITY_SCORE", INT2NUM(139));
    rb_define_const(cNWScript, "VFX_IMP_CHARM", INT2NUM(140));
    rb_define_const(cNWScript, "VFX_IMP_MAGICAL_VISION", INT2NUM(141));
    rb_define_const(cNWScript, "VFX_IMP_EVIL_HELP", INT2NUM(144));
    rb_define_const(cNWScript, "VFX_IMP_GOOD_HELP", INT2NUM(145));
    rb_define_const(cNWScript, "VFX_IMP_DEATH_WARD", INT2NUM(146));
    rb_define_const(cNWScript, "VFX_DUR_ELEMENTAL_SHIELD", INT2NUM(147));
    rb_define_const(cNWScript, "VFX_DUR_LIGHT", INT2NUM(148));
    rb_define_const(cNWScript, "VFX_IMP_MAGIC_PROTECTION", INT2NUM(149));
    rb_define_const(cNWScript, "VFX_IMP_SUPER_HEROISM", INT2NUM(150));
    rb_define_const(cNWScript, "VFX_FNF_STORM", INT2NUM(151));
    rb_define_const(cNWScript, "VFX_IMP_ELEMENTAL_PROTECTION", INT2NUM(152));
    rb_define_const(cNWScript, "VFX_DUR_LIGHT_BLUE_5", INT2NUM(153));
    rb_define_const(cNWScript, "VFX_DUR_LIGHT_BLUE_10", INT2NUM(154));
    rb_define_const(cNWScript, "VFX_DUR_LIGHT_BLUE_15", INT2NUM(155));
    rb_define_const(cNWScript, "VFX_DUR_LIGHT_BLUE_20", INT2NUM(156));
    rb_define_const(cNWScript, "VFX_DUR_LIGHT_YELLOW_5", INT2NUM(157));
    rb_define_const(cNWScript, "VFX_DUR_LIGHT_YELLOW_10", INT2NUM(158));
    rb_define_const(cNWScript, "VFX_DUR_LIGHT_YELLOW_15", INT2NUM(159));
    rb_define_const(cNWScript, "VFX_DUR_LIGHT_YELLOW_20", INT2NUM(160));
    rb_define_const(cNWScript, "VFX_DUR_LIGHT_PURPLE_5", INT2NUM(161));
    rb_define_const(cNWScript, "VFX_DUR_LIGHT_PURPLE_10", INT2NUM(162));
    rb_define_const(cNWScript, "VFX_DUR_LIGHT_PURPLE_15", INT2NUM(163));
    rb_define_const(cNWScript, "VFX_DUR_LIGHT_PURPLE_20", INT2NUM(164));
    rb_define_const(cNWScript, "VFX_DUR_LIGHT_RED_5", INT2NUM(165));
    rb_define_const(cNWScript, "VFX_DUR_LIGHT_RED_10", INT2NUM(166));
    rb_define_const(cNWScript, "VFX_DUR_LIGHT_RED_15", INT2NUM(167));
    rb_define_const(cNWScript, "VFX_DUR_LIGHT_RED_20", INT2NUM(168));
    rb_define_const(cNWScript, "VFX_DUR_LIGHT_ORANGE_5", INT2NUM(169));
    rb_define_const(cNWScript, "VFX_DUR_LIGHT_ORANGE_10", INT2NUM(170));
    rb_define_const(cNWScript, "VFX_DUR_LIGHT_ORANGE_15", INT2NUM(171));
    rb_define_const(cNWScript, "VFX_DUR_LIGHT_ORANGE_20", INT2NUM(172));
    rb_define_const(cNWScript, "VFX_DUR_LIGHT_WHITE_5", INT2NUM(173));
    rb_define_const(cNWScript, "VFX_DUR_LIGHT_WHITE_10", INT2NUM(174));
    rb_define_const(cNWScript, "VFX_DUR_LIGHT_WHITE_15", INT2NUM(175));
    rb_define_const(cNWScript, "VFX_DUR_LIGHT_WHITE_20", INT2NUM(176));
    rb_define_const(cNWScript, "VFX_DUR_LIGHT_GREY_5", INT2NUM(177));
    rb_define_const(cNWScript, "VFX_DUR_LIGHT_GREY_10", INT2NUM(178));
    rb_define_const(cNWScript, "VFX_DUR_LIGHT_GREY_15", INT2NUM(179));
    rb_define_const(cNWScript, "VFX_DUR_LIGHT_GREY_20", INT2NUM(180));
    rb_define_const(cNWScript, "VFX_IMP_MIRV", INT2NUM(181));
    rb_define_const(cNWScript, "VFX_DUR_DARKVISION", INT2NUM(182));
    rb_define_const(cNWScript, "VFX_FNF_SOUND_BURST", INT2NUM(183));
    rb_define_const(cNWScript, "VFX_FNF_STRIKE_HOLY", INT2NUM(184));
    rb_define_const(cNWScript, "VFX_FNF_LOS_EVIL_10", INT2NUM(185));
    rb_define_const(cNWScript, "VFX_FNF_LOS_EVIL_20", INT2NUM(186));
    rb_define_const(cNWScript, "VFX_FNF_LOS_EVIL_30", INT2NUM(187));
    rb_define_const(cNWScript, "VFX_FNF_LOS_HOLY_10", INT2NUM(188));
    rb_define_const(cNWScript, "VFX_FNF_LOS_HOLY_20", INT2NUM(189));
    rb_define_const(cNWScript, "VFX_FNF_LOS_HOLY_30", INT2NUM(190));
    rb_define_const(cNWScript, "VFX_FNF_LOS_NORMAL_10", INT2NUM(191));
    rb_define_const(cNWScript, "VFX_FNF_LOS_NORMAL_20", INT2NUM(192));
    rb_define_const(cNWScript, "VFX_FNF_LOS_NORMAL_30", INT2NUM(193));
    rb_define_const(cNWScript, "VFX_IMP_HEAD_ACID", INT2NUM(194));
    rb_define_const(cNWScript, "VFX_IMP_HEAD_FIRE", INT2NUM(195));
    rb_define_const(cNWScript, "VFX_IMP_HEAD_SONIC", INT2NUM(196));
    rb_define_const(cNWScript, "VFX_IMP_HEAD_ELECTRICITY", INT2NUM(197));
    rb_define_const(cNWScript, "VFX_IMP_HEAD_COLD", INT2NUM(198));
    rb_define_const(cNWScript, "VFX_IMP_HEAD_HOLY", INT2NUM(199));
    rb_define_const(cNWScript, "VFX_IMP_HEAD_NATURE", INT2NUM(200));
    rb_define_const(cNWScript, "VFX_IMP_HEAD_HEAL", INT2NUM(201));
    rb_define_const(cNWScript, "VFX_IMP_HEAD_MIND", INT2NUM(202));
    rb_define_const(cNWScript, "VFX_IMP_HEAD_EVIL", INT2NUM(203));
    rb_define_const(cNWScript, "VFX_IMP_HEAD_ODD", INT2NUM(204));
    rb_define_const(cNWScript, "VFX_DUR_CESSATE_NEUTRAL", INT2NUM(205));
    rb_define_const(cNWScript, "VFX_DUR_CESSATE_POSITIVE", INT2NUM(206));
    rb_define_const(cNWScript, "VFX_DUR_CESSATE_NEGATIVE", INT2NUM(207));
    rb_define_const(cNWScript, "VFX_DUR_MIND_AFFECTING_DISABLED", INT2NUM(208));
    rb_define_const(cNWScript, "VFX_DUR_MIND_AFFECTING_DOMINATED", INT2NUM(209));
    rb_define_const(cNWScript, "VFX_BEAM_FIRE", INT2NUM(210));
    rb_define_const(cNWScript, "VFX_BEAM_COLD", INT2NUM(211));
    rb_define_const(cNWScript, "VFX_BEAM_HOLY", INT2NUM(212));
    rb_define_const(cNWScript, "VFX_BEAM_MIND", INT2NUM(213));
    rb_define_const(cNWScript, "VFX_BEAM_EVIL", INT2NUM(214));
    rb_define_const(cNWScript, "VFX_BEAM_ODD", INT2NUM(215));
    rb_define_const(cNWScript, "VFX_BEAM_FIRE_LASH", INT2NUM(216));
    rb_define_const(cNWScript, "VFX_IMP_DEATH_L", INT2NUM(217));
    rb_define_const(cNWScript, "VFX_DUR_MIND_AFFECTING_FEAR", INT2NUM(218));
    rb_define_const(cNWScript, "VFX_FNF_SUMMON_CELESTIAL", INT2NUM(219));
    rb_define_const(cNWScript, "VFX_DUR_GLOBE_MINOR", INT2NUM(220));
    rb_define_const(cNWScript, "VFX_IMP_RESTORATION_LESSER", INT2NUM(221));
    rb_define_const(cNWScript, "VFX_IMP_RESTORATION", INT2NUM(222));
    rb_define_const(cNWScript, "VFX_IMP_RESTORATION_GREATER", INT2NUM(223));
    rb_define_const(cNWScript, "VFX_DUR_PROTECTION_ELEMENTS", INT2NUM(224));
    rb_define_const(cNWScript, "VFX_DUR_PROTECTION_GOOD_MINOR", INT2NUM(225));
    rb_define_const(cNWScript, "VFX_DUR_PROTECTION_GOOD_MAJOR", INT2NUM(226));
    rb_define_const(cNWScript, "VFX_DUR_PROTECTION_EVIL_MINOR", INT2NUM(227));
    rb_define_const(cNWScript, "VFX_DUR_PROTECTION_EVIL_MAJOR", INT2NUM(228));
    rb_define_const(cNWScript, "VFX_DUR_MAGICAL_SIGHT", INT2NUM(229));
    rb_define_const(cNWScript, "VFX_DUR_WEB_MASS", INT2NUM(230));
    rb_define_const(cNWScript, "VFX_FNF_ICESTORM", INT2NUM(231));
    rb_define_const(cNWScript, "VFX_DUR_PARALYZED", INT2NUM(232));
    rb_define_const(cNWScript, "VFX_IMP_MIRV_FLAME", INT2NUM(233));
    rb_define_const(cNWScript, "VFX_IMP_DESTRUCTION", INT2NUM(234));
    rb_define_const(cNWScript, "VFX_COM_CHUNK_RED_LARGE", INT2NUM(235));
    rb_define_const(cNWScript, "VFX_COM_CHUNK_BONE_MEDIUM", INT2NUM(236));
    rb_define_const(cNWScript, "VFX_COM_BLOOD_SPARK_SMALL", INT2NUM(237));
    rb_define_const(cNWScript, "VFX_COM_BLOOD_SPARK_MEDIUM", INT2NUM(238));
    rb_define_const(cNWScript, "VFX_COM_BLOOD_SPARK_LARGE", INT2NUM(239));
    rb_define_const(cNWScript, "VFX_DUR_GHOSTLY_PULSE", INT2NUM(240));
    rb_define_const(cNWScript, "VFX_FNF_HORRID_WILTING", INT2NUM(241));
    rb_define_const(cNWScript, "VFX_DUR_BLINDVISION", INT2NUM(242));
    rb_define_const(cNWScript, "VFX_DUR_LOWLIGHTVISION", INT2NUM(243));
    rb_define_const(cNWScript, "VFX_DUR_ULTRAVISION", INT2NUM(244));
    rb_define_const(cNWScript, "VFX_DUR_MIRV_ACID", INT2NUM(245));
    rb_define_const(cNWScript, "VFX_IMP_HARM", INT2NUM(246));
    rb_define_const(cNWScript, "VFX_DUR_BLIND", INT2NUM(247));
    rb_define_const(cNWScript, "VFX_DUR_ANTI_LIGHT_10", INT2NUM(248));
    rb_define_const(cNWScript, "VFX_DUR_MAGIC_RESISTANCE", INT2NUM(249));
    rb_define_const(cNWScript, "VFX_IMP_MAGIC_RESISTANCE_USE", INT2NUM(250));
    rb_define_const(cNWScript, "VFX_IMP_GLOBE_USE", INT2NUM(251));
    rb_define_const(cNWScript, "VFX_IMP_WILL_SAVING_THROW_USE", INT2NUM(252));
    rb_define_const(cNWScript, "VFX_IMP_SPIKE_TRAP", INT2NUM(253));
    rb_define_const(cNWScript, "VFX_IMP_SPELL_MANTLE_USE", INT2NUM(254));
    rb_define_const(cNWScript, "VFX_IMP_FORTITUDE_SAVING_THROW_USE", INT2NUM(255));
    rb_define_const(cNWScript, "VFX_IMP_REFLEX_SAVE_THROW_USE", INT2NUM(256));
    rb_define_const(cNWScript, "VFX_FNF_GAS_EXPLOSION_ACID", INT2NUM(257));
    rb_define_const(cNWScript, "VFX_FNF_GAS_EXPLOSION_EVIL", INT2NUM(258));
    rb_define_const(cNWScript, "VFX_FNF_GAS_EXPLOSION_NATURE", INT2NUM(259));
    rb_define_const(cNWScript, "VFX_FNF_GAS_EXPLOSION_FIRE", INT2NUM(260));
    rb_define_const(cNWScript, "VFX_FNF_GAS_EXPLOSION_GREASE", INT2NUM(261));
    rb_define_const(cNWScript, "VFX_FNF_GAS_EXPLOSION_MIND", INT2NUM(262));
    rb_define_const(cNWScript, "VFX_FNF_SMOKE_PUFF", INT2NUM(263));
    rb_define_const(cNWScript, "VFX_IMP_PULSE_WATER", INT2NUM(264));
    rb_define_const(cNWScript, "VFX_IMP_PULSE_WIND", INT2NUM(265));
    rb_define_const(cNWScript, "VFX_IMP_PULSE_NATURE", INT2NUM(266));
    rb_define_const(cNWScript, "VFX_DUR_AURA_COLD", INT2NUM(267));
    rb_define_const(cNWScript, "VFX_DUR_AURA_FIRE", INT2NUM(268));
    rb_define_const(cNWScript, "VFX_DUR_AURA_POISON", INT2NUM(269));
    rb_define_const(cNWScript, "VFX_DUR_AURA_DISEASE", INT2NUM(270));
    rb_define_const(cNWScript, "VFX_DUR_AURA_ODD", INT2NUM(271));
    rb_define_const(cNWScript, "VFX_DUR_AURA_SILENCE", INT2NUM(272));
    rb_define_const(cNWScript, "VFX_IMP_AURA_HOLY", INT2NUM(273));
    rb_define_const(cNWScript, "VFX_IMP_AURA_UNEARTHLY", INT2NUM(274));
    rb_define_const(cNWScript, "VFX_IMP_AURA_FEAR", INT2NUM(275));
    rb_define_const(cNWScript, "VFX_IMP_AURA_NEGATIVE_ENERGY", INT2NUM(276));
    rb_define_const(cNWScript, "VFX_DUR_BARD_SONG", INT2NUM(277));
    rb_define_const(cNWScript, "VFX_FNF_HOWL_MIND", INT2NUM(278));
    rb_define_const(cNWScript, "VFX_FNF_HOWL_ODD", INT2NUM(279));
    rb_define_const(cNWScript, "VFX_COM_HIT_FIRE", INT2NUM(280));
    rb_define_const(cNWScript, "VFX_COM_HIT_FROST", INT2NUM(281));
    rb_define_const(cNWScript, "VFX_COM_HIT_ELECTRICAL", INT2NUM(282));
    rb_define_const(cNWScript, "VFX_COM_HIT_ACID", INT2NUM(283));
    rb_define_const(cNWScript, "VFX_COM_HIT_SONIC", INT2NUM(284));
    rb_define_const(cNWScript, "VFX_FNF_HOWL_WAR_CRY", INT2NUM(285));
    rb_define_const(cNWScript, "VFX_FNF_SCREEN_SHAKE", INT2NUM(286));
    rb_define_const(cNWScript, "VFX_FNF_SCREEN_BUMP", INT2NUM(287));
    rb_define_const(cNWScript, "VFX_COM_HIT_NEGATIVE", INT2NUM(288));
    rb_define_const(cNWScript, "VFX_COM_HIT_DIVINE", INT2NUM(289));
    rb_define_const(cNWScript, "VFX_FNF_HOWL_WAR_CRY_FEMALE", INT2NUM(290));
    rb_define_const(cNWScript, "VFX_DUR_AURA_DRAGON_FEAR", INT2NUM(291));
    rb_define_const(cNWScript, "VFX_DUR_FLAG_RED", INT2NUM(303));
    rb_define_const(cNWScript, "VFX_DUR_FLAG_BLUE", INT2NUM(304));
    rb_define_const(cNWScript, "VFX_DUR_FLAG_GOLD", INT2NUM(305));
    rb_define_const(cNWScript, "VFX_DUR_FLAG_PURPLE", INT2NUM(306));
    rb_define_const(cNWScript, "VFX_DUR_FLAG_GOLD_FIXED", INT2NUM(306));
    rb_define_const(cNWScript, "VFX_DUR_FLAG_PURPLE_FIXED", INT2NUM(305));
    rb_define_const(cNWScript, "VFX_DUR_TENTACLE", INT2NUM(346));
    rb_define_const(cNWScript, "VFX_DUR_PETRIFY", INT2NUM(351));
    rb_define_const(cNWScript, "VFX_DUR_FREEZE_ANIMATION", INT2NUM(352));
    rb_define_const(cNWScript, "VFX_COM_CHUNK_STONE_SMALL", INT2NUM(353));
    rb_define_const(cNWScript, "VFX_COM_CHUNK_STONE_MEDIUM", INT2NUM(354));
    rb_define_const(cNWScript, "VFX_BEAM_SILENT_LIGHTNING", INT2NUM(307));
    rb_define_const(cNWScript, "VFX_BEAM_SILENT_FIRE", INT2NUM(308));
    rb_define_const(cNWScript, "VFX_BEAM_SILENT_COLD", INT2NUM(309));
    rb_define_const(cNWScript, "VFX_BEAM_SILENT_HOLY", INT2NUM(310));
    rb_define_const(cNWScript, "VFX_BEAM_SILENT_MIND", INT2NUM(311));
    rb_define_const(cNWScript, "VFX_BEAM_SILENT_EVIL", INT2NUM(312));
    rb_define_const(cNWScript, "VFX_BEAM_SILENT_ODD", INT2NUM(313));
    rb_define_const(cNWScript, "VFX_DUR_BIGBYS_INTERPOSING_HAND", INT2NUM(314));
    rb_define_const(cNWScript, "VFX_IMP_BIGBYS_FORCEFUL_HAND", INT2NUM(315));
    rb_define_const(cNWScript, "VFX_DUR_BIGBYS_CLENCHED_FIST", INT2NUM(316));
    rb_define_const(cNWScript, "VFX_DUR_BIGBYS_CRUSHING_HAND", INT2NUM(317));
    rb_define_const(cNWScript, "VFX_DUR_BIGBYS_GRASPING_HAND", INT2NUM(318));
    rb_define_const(cNWScript, "VFX_DUR_CALTROPS", INT2NUM(319));
    rb_define_const(cNWScript, "VFX_DUR_SMOKE", INT2NUM(320));
    rb_define_const(cNWScript, "VFX_DUR_PIXIEDUST", INT2NUM(321));
    rb_define_const(cNWScript, "VFX_FNF_DECK", INT2NUM(322));
    rb_define_const(cNWScript, "VFX_DUR_CUTSCENE_INVISIBILITY", INT2NUM(355));
    rb_define_const(cNWScript, "VFX_EYES_RED_FLAME_HUMAN_MALE", INT2NUM(360));
    rb_define_const(cNWScript, "VFX_EYES_RED_FLAME_HUMAN_FEMALE", INT2NUM(361));
    rb_define_const(cNWScript, "VFX_EYES_RED_FLAME_HALFELF_MALE", INT2NUM(360));
    rb_define_const(cNWScript, "VFX_EYES_RED_FLAME_HALFELF_FEMALE", INT2NUM(361));
    rb_define_const(cNWScript, "VFX_EYES_RED_FLAME_DWARF_MALE", INT2NUM(362));
    rb_define_const(cNWScript, "VFX_EYES_RED_FLAME_DWARF_FEMALE", INT2NUM(363));
    rb_define_const(cNWScript, "VFX_EYES_RED_FLAME_ELF_MALE", INT2NUM(364));
    rb_define_const(cNWScript, "VFX_EYES_RED_FLAME_ELF_FEMALE", INT2NUM(365));
    rb_define_const(cNWScript, "VFX_EYES_RED_FLAME_GNOME_MALE", INT2NUM(366));
    rb_define_const(cNWScript, "VFX_EYES_RED_FLAME_GNOME_FEMALE", INT2NUM(367));
    rb_define_const(cNWScript, "VFX_EYES_RED_FLAME_HALFLING_MALE", INT2NUM(368));
    rb_define_const(cNWScript, "VFX_EYES_RED_FLAME_HALFLING_FEMALE", INT2NUM(369));
    rb_define_const(cNWScript, "VFX_EYES_RED_FLAME_HALFORC_MALE", INT2NUM(370));
    rb_define_const(cNWScript, "VFX_EYES_RED_FLAME_HALFORC_FEMALE", INT2NUM(371));
    rb_define_const(cNWScript, "VFX_EYES_RED_FLAME_TROGLODYTE", INT2NUM(372));
    rb_define_const(cNWScript, "VFX_EYES_YEL_HUMAN_MALE", INT2NUM(373));
    rb_define_const(cNWScript, "VFX_EYES_YEL_HUMAN_FEMALE", INT2NUM(374));
    rb_define_const(cNWScript, "VFX_EYES_YEL_DWARF_MALE", INT2NUM(375));
    rb_define_const(cNWScript, "VFX_EYES_YEL_DWARF_FEMALE", INT2NUM(376));
    rb_define_const(cNWScript, "VFX_EYES_YEL_ELF_MALE", INT2NUM(377));
    rb_define_const(cNWScript, "VFX_EYES_YEL_ELF_FEMALE", INT2NUM(378));
    rb_define_const(cNWScript, "VFX_EYES_YEL_GNOME_MALE", INT2NUM(379));
    rb_define_const(cNWScript, "VFX_EYES_YEL_GNOME_FEMALE", INT2NUM(380));
    rb_define_const(cNWScript, "VFX_EYES_YEL_HALFLING_MALE", INT2NUM(381));
    rb_define_const(cNWScript, "VFX_EYES_YEL_HALFLING_FEMALE", INT2NUM(382));
    rb_define_const(cNWScript, "VFX_EYES_YEL_HALFORC_MALE", INT2NUM(383));
    rb_define_const(cNWScript, "VFX_EYES_YEL_HALFORC_FEMALE", INT2NUM(384));
    rb_define_const(cNWScript, "VFX_EYES_YEL_TROGLODYTE", INT2NUM(385));
    rb_define_const(cNWScript, "VFX_EYES_ORG_HUMAN_MALE", INT2NUM(386));
    rb_define_const(cNWScript, "VFX_EYES_ORG_HUMAN_FEMALE", INT2NUM(387));
    rb_define_const(cNWScript, "VFX_EYES_ORG_DWARF_MALE", INT2NUM(388));
    rb_define_const(cNWScript, "VFX_EYES_ORG_DWARF_FEMALE", INT2NUM(389));
    rb_define_const(cNWScript, "VFX_EYES_ORG_ELF_MALE", INT2NUM(390));
    rb_define_const(cNWScript, "VFX_EYES_ORG_ELF_FEMALE", INT2NUM(391));
    rb_define_const(cNWScript, "VFX_EYES_ORG_GNOME_MALE", INT2NUM(392));
    rb_define_const(cNWScript, "VFX_EYES_ORG_GNOME_FEMALE", INT2NUM(393));
    rb_define_const(cNWScript, "VFX_EYES_ORG_HALFLING_MALE", INT2NUM(394));
    rb_define_const(cNWScript, "VFX_EYES_ORG_HALFLING_FEMALE", INT2NUM(395));
    rb_define_const(cNWScript, "VFX_EYES_ORG_HALFORC_MALE", INT2NUM(396));
    rb_define_const(cNWScript, "VFX_EYES_ORG_HALFORC_FEMALE", INT2NUM(397));
    rb_define_const(cNWScript, "VFX_EYES_ORG_TROGLODYTE", INT2NUM(398));
    rb_define_const(cNWScript, "VFX_DUR_IOUNSTONE", INT2NUM(403));
    rb_define_const(cNWScript, "VFX_IMP_TORNADO", INT2NUM(407));
    rb_define_const(cNWScript, "VFX_DUR_GLOW_LIGHT_BLUE", INT2NUM(408));
    rb_define_const(cNWScript, "VFX_DUR_GLOW_PURPLE", INT2NUM(409));
    rb_define_const(cNWScript, "VFX_DUR_GLOW_BLUE", INT2NUM(410));
    rb_define_const(cNWScript, "VFX_DUR_GLOW_RED", INT2NUM(411));
    rb_define_const(cNWScript, "VFX_DUR_GLOW_LIGHT_RED", INT2NUM(412));
    rb_define_const(cNWScript, "VFX_DUR_GLOW_YELLOW", INT2NUM(413));
    rb_define_const(cNWScript, "VFX_DUR_GLOW_LIGHT_YELLOW", INT2NUM(414));
    rb_define_const(cNWScript, "VFX_DUR_GLOW_GREEN", INT2NUM(415));
    rb_define_const(cNWScript, "VFX_DUR_GLOW_LIGHT_GREEN", INT2NUM(416));
    rb_define_const(cNWScript, "VFX_DUR_GLOW_ORANGE", INT2NUM(417));
    rb_define_const(cNWScript, "VFX_DUR_GLOW_LIGHT_ORANGE", INT2NUM(418));
    rb_define_const(cNWScript, "VFX_DUR_GLOW_BROWN", INT2NUM(419));
    rb_define_const(cNWScript, "VFX_DUR_GLOW_LIGHT_BROWN", INT2NUM(420));
    rb_define_const(cNWScript, "VFX_DUR_GLOW_GREY", INT2NUM(421));
    rb_define_const(cNWScript, "VFX_DUR_GLOW_WHITE", INT2NUM(422));
    rb_define_const(cNWScript, "VFX_DUR_GLOW_LIGHT_PURPLE", INT2NUM(423));
    rb_define_const(cNWScript, "VFX_DUR_GHOST_TRANSPARENT", INT2NUM(424));
    rb_define_const(cNWScript, "VFX_DUR_GHOST_SMOKE", INT2NUM(425));
    rb_define_const(cNWScript, "VFX_DUR_GLYPH_OF_WARDING", INT2NUM(445));
    rb_define_const(cNWScript, "VFX_FNF_SOUND_BURST_SILENT", INT2NUM(446));
    rb_define_const(cNWScript, "VFX_BEAM_DISINTEGRATE", INT2NUM(447));
    rb_define_const(cNWScript, "VFX_FNF_ELECTRIC_EXPLOSION", INT2NUM(459));
    rb_define_const(cNWScript, "VFX_IMP_DUST_EXPLOSION", INT2NUM(460));
    rb_define_const(cNWScript, "VFX_IMP_PULSE_HOLY_SILENT", INT2NUM(461));
    rb_define_const(cNWScript, "VFX_DUR_DEATH_ARMOR", INT2NUM(463));
    rb_define_const(cNWScript, "VFX_DUR_ICESKIN", INT2NUM(465));
    rb_define_const(cNWScript, "VFX_FNF_SWINGING_BLADE", INT2NUM(473));
    rb_define_const(cNWScript, "VFX_DUR_INFERNO", INT2NUM(474));
    rb_define_const(cNWScript, "VFX_FNF_DEMON_HAND", INT2NUM(475));
    rb_define_const(cNWScript, "VFX_DUR_STONEHOLD", INT2NUM(476));
    rb_define_const(cNWScript, "VFX_FNF_MYSTICAL_EXPLOSION", INT2NUM(477));
    rb_define_const(cNWScript, "VFX_DUR_GHOSTLY_VISAGE_NO_SOUND", INT2NUM(478));
    rb_define_const(cNWScript, "VFX_DUR_GHOST_SMOKE_2", INT2NUM(479));
    rb_define_const(cNWScript, "VFX_DUR_FLIES", INT2NUM(480));
    rb_define_const(cNWScript, "VFX_FNF_SUMMONDRAGON", INT2NUM(481));
    rb_define_const(cNWScript, "VFX_BEAM_FIRE_W", INT2NUM(482));
    rb_define_const(cNWScript, "VFX_BEAM_FIRE_W_SILENT", INT2NUM(483));
    rb_define_const(cNWScript, "VFX_BEAM_CHAIN", INT2NUM(484));
    rb_define_const(cNWScript, "VFX_BEAM_BLACK", INT2NUM(485));
    rb_define_const(cNWScript, "VFX_IMP_WALLSPIKE", INT2NUM(486));
    rb_define_const(cNWScript, "VFX_FNF_GREATER_RUIN", INT2NUM(487));
    rb_define_const(cNWScript, "VFX_FNF_UNDEAD_DRAGON", INT2NUM(488));
    rb_define_const(cNWScript, "VFX_DUR_PROT_EPIC_ARMOR", INT2NUM(495));
    rb_define_const(cNWScript, "VFX_FNF_SUMMON_EPIC_UNDEAD", INT2NUM(496));
    rb_define_const(cNWScript, "VFX_DUR_PROT_EPIC_ARMOR_2", INT2NUM(497));
    rb_define_const(cNWScript, "VFX_DUR_INFERNO_CHEST", INT2NUM(498));
    rb_define_const(cNWScript, "VFX_DUR_IOUNSTONE_RED", INT2NUM(499));
    rb_define_const(cNWScript, "VFX_DUR_IOUNSTONE_BLUE", INT2NUM(500));
    rb_define_const(cNWScript, "VFX_DUR_IOUNSTONE_YELLOW", INT2NUM(501));
    rb_define_const(cNWScript, "VFX_DUR_IOUNSTONE_GREEN", INT2NUM(502));
    rb_define_const(cNWScript, "VFX_IMP_MIRV_ELECTRIC", INT2NUM(503));
    rb_define_const(cNWScript, "VFX_COM_CHUNK_RED_BALLISTA", INT2NUM(504));
    rb_define_const(cNWScript, "VFX_DUR_INFERNO_NO_SOUND", INT2NUM(505));
    rb_define_const(cNWScript, "VFX_DUR_AURA_PULSE_RED_WHITE", INT2NUM(512));
    rb_define_const(cNWScript, "VFX_DUR_AURA_PULSE_BLUE_WHITE", INT2NUM(513));
    rb_define_const(cNWScript, "VFX_DUR_AURA_PULSE_GREEN_WHITE", INT2NUM(514));
    rb_define_const(cNWScript, "VFX_DUR_AURA_PULSE_YELLOW_WHITE", INT2NUM(515));
    rb_define_const(cNWScript, "VFX_DUR_AURA_PULSE_MAGENTA_WHITE", INT2NUM(516));
    rb_define_const(cNWScript, "VFX_DUR_AURA_PULSE_CYAN_WHITE", INT2NUM(517));
    rb_define_const(cNWScript, "VFX_DUR_AURA_PULSE_ORANGE_WHITE", INT2NUM(518));
    rb_define_const(cNWScript, "VFX_DUR_AURA_PULSE_BROWN_WHITE", INT2NUM(519));
    rb_define_const(cNWScript, "VFX_DUR_AURA_PULSE_PURPLE_WHITE", INT2NUM(520));
    rb_define_const(cNWScript, "VFX_DUR_AURA_PULSE_GREY_WHITE", INT2NUM(521));
    rb_define_const(cNWScript, "VFX_DUR_AURA_PULSE_GREY_BLACK", INT2NUM(522));
    rb_define_const(cNWScript, "VFX_DUR_AURA_PULSE_BLUE_GREEN", INT2NUM(523));
    rb_define_const(cNWScript, "VFX_DUR_AURA_PULSE_RED_BLUE", INT2NUM(524));
    rb_define_const(cNWScript, "VFX_DUR_AURA_PULSE_RED_YELLOW", INT2NUM(525));
    rb_define_const(cNWScript, "VFX_DUR_AURA_PULSE_GREEN_YELLOW", INT2NUM(526));
    rb_define_const(cNWScript, "VFX_DUR_AURA_PULSE_RED_GREEN", INT2NUM(527));
    rb_define_const(cNWScript, "VFX_DUR_AURA_PULSE_BLUE_YELLOW", INT2NUM(528));
    rb_define_const(cNWScript, "VFX_DUR_AURA_PULSE_BLUE_BLACK", INT2NUM(529));
    rb_define_const(cNWScript, "VFX_DUR_AURA_PULSE_RED_BLACK", INT2NUM(530));
    rb_define_const(cNWScript, "VFX_DUR_AURA_PULSE_GREEN_BLACK", INT2NUM(531));
    rb_define_const(cNWScript, "VFX_DUR_AURA_PULSE_YELLOW_BLACK", INT2NUM(532));
    rb_define_const(cNWScript, "VFX_DUR_AURA_PULSE_MAGENTA_BLACK", INT2NUM(533));
    rb_define_const(cNWScript, "VFX_DUR_AURA_PULSE_CYAN_BLACK", INT2NUM(534));
    rb_define_const(cNWScript, "VFX_DUR_AURA_PULSE_ORANGE_BLACK", INT2NUM(535));
    rb_define_const(cNWScript, "VFX_DUR_AURA_PULSE_BROWN_BLACK", INT2NUM(536));
    rb_define_const(cNWScript, "VFX_DUR_AURA_PULSE_PURPLE_BLACK", INT2NUM(537));
    rb_define_const(cNWScript, "VFX_DUR_AURA_PULSE_CYAN_GREEN", INT2NUM(538));
    rb_define_const(cNWScript, "VFX_DUR_AURA_PULSE_CYAN_BLUE", INT2NUM(539));
    rb_define_const(cNWScript, "VFX_DUR_AURA_PULSE_CYAN_RED", INT2NUM(540));
    rb_define_const(cNWScript, "VFX_DUR_AURA_PULSE_CYAN_YELLOW", INT2NUM(541));
    rb_define_const(cNWScript, "VFX_DUR_AURA_PULSE_MAGENTA_BLUE", INT2NUM(542));
    rb_define_const(cNWScript, "VFX_DUR_AURA_PULSE_MAGENTA_RED", INT2NUM(543));
    rb_define_const(cNWScript, "VFX_DUR_AURA_PULSE_MAGENTA_GREEN", INT2NUM(544));
    rb_define_const(cNWScript, "VFX_DUR_AURA_PULSE_MAGENTA_YELLOW", INT2NUM(545));
    rb_define_const(cNWScript, "VFX_DUR_AURA_PULSE_RED_ORANGE", INT2NUM(546));
    rb_define_const(cNWScript, "VFX_DUR_AURA_PULSE_YELLOW_ORANGE", INT2NUM(547));
    rb_define_const(cNWScript, "VFX_DUR_AURA_RED", INT2NUM(548));
    rb_define_const(cNWScript, "VFX_DUR_AURA_GREEN", INT2NUM(549));
    rb_define_const(cNWScript, "VFX_DUR_AURA_BLUE", INT2NUM(550));
    rb_define_const(cNWScript, "VFX_DUR_AURA_MAGENTA", INT2NUM(551));
    rb_define_const(cNWScript, "VFX_DUR_AURA_YELLOW", INT2NUM(552));
    rb_define_const(cNWScript, "VFX_DUR_AURA_WHITE", INT2NUM(553));
    rb_define_const(cNWScript, "VFX_DUR_AURA_ORANGE", INT2NUM(554));
    rb_define_const(cNWScript, "VFX_DUR_AURA_BROWN", INT2NUM(555));
    rb_define_const(cNWScript, "VFX_DUR_AURA_PURPLE", INT2NUM(556));
    rb_define_const(cNWScript, "VFX_DUR_AURA_CYAN", INT2NUM(557));
    rb_define_const(cNWScript, "VFX_DUR_AURA_GREEN_DARK", INT2NUM(558));
    rb_define_const(cNWScript, "VFX_DUR_AURA_GREEN_LIGHT", INT2NUM(559));
    rb_define_const(cNWScript, "VFX_DUR_AURA_RED_DARK", INT2NUM(560));
    rb_define_const(cNWScript, "VFX_DUR_AURA_RED_LIGHT", INT2NUM(561));
    rb_define_const(cNWScript, "VFX_DUR_AURA_BLUE_DARK", INT2NUM(562));
    rb_define_const(cNWScript, "VFX_DUR_AURA_BLUE_LIGHT", INT2NUM(563));
    rb_define_const(cNWScript, "VFX_DUR_AURA_YELLOW_DARK", INT2NUM(564));
    rb_define_const(cNWScript, "VFX_DUR_AURA_YELLOW_LIGHT", INT2NUM(565));
    rb_define_const(cNWScript, "VFX_DUR_BUBBLES", INT2NUM(566));
    rb_define_const(cNWScript, "VFX_EYES_GREEN_HUMAN_MALE", INT2NUM(567));
    rb_define_const(cNWScript, "VFX_EYES_GREEN_HUMAN_FEMALE", INT2NUM(568));
    rb_define_const(cNWScript, "VFX_EYES_GREEN_HALFELF_MALE", INT2NUM(567));
    rb_define_const(cNWScript, "VFX_EYES_GREEN_HALFELF_FEMALE", INT2NUM(568));
    rb_define_const(cNWScript, "VFX_EYES_GREEN_DWARF_MALE", INT2NUM(569));
    rb_define_const(cNWScript, "VFX_EYES_GREEN_DWARF_FEMALE", INT2NUM(570));
    rb_define_const(cNWScript, "VFX_EYES_GREEN_ELF_MALE", INT2NUM(571));
    rb_define_const(cNWScript, "VFX_EYES_GREEN_ELF_FEMALE", INT2NUM(572));
    rb_define_const(cNWScript, "VFX_EYES_GREEN_GNOME_MALE", INT2NUM(573));
    rb_define_const(cNWScript, "VFX_EYES_GREEN_GNOME_FEMALE", INT2NUM(574));
    rb_define_const(cNWScript, "VFX_EYES_GREEN_HALFLING_MALE", INT2NUM(575));
    rb_define_const(cNWScript, "VFX_EYES_GREEN_HALFLING_FEMALE", INT2NUM(576));
    rb_define_const(cNWScript, "VFX_EYES_GREEN_HALFORC_MALE", INT2NUM(577));
    rb_define_const(cNWScript, "VFX_EYES_GREEN_HALFORC_FEMALE", INT2NUM(578));
    rb_define_const(cNWScript, "VFX_EYES_GREEN_TROGLODYTE", INT2NUM(579));
    rb_define_const(cNWScript, "VFX_EYES_PUR_HUMAN_MALE", INT2NUM(580));
    rb_define_const(cNWScript, "VFX_EYES_PUR_HUMAN_FEMALE", INT2NUM(581));
    rb_define_const(cNWScript, "VFX_EYES_PUR_DWARF_MALE", INT2NUM(582));
    rb_define_const(cNWScript, "VFX_EYES_PUR_DWARF_FEMALE", INT2NUM(583));
    rb_define_const(cNWScript, "VFX_EYES_PUR_ELF_MALE", INT2NUM(584));
    rb_define_const(cNWScript, "VFX_EYES_PUR_ELF_FEMALE", INT2NUM(585));
    rb_define_const(cNWScript, "VFX_EYES_PUR_GNOME_MALE", INT2NUM(586));
    rb_define_const(cNWScript, "VFX_EYES_PUR_GNOME_FEMALE", INT2NUM(587));
    rb_define_const(cNWScript, "VFX_EYES_PUR_HALFLING_MALE", INT2NUM(588));
    rb_define_const(cNWScript, "VFX_EYES_PUR_HALFLING_FEMALE", INT2NUM(589));
    rb_define_const(cNWScript, "VFX_EYES_PUR_HALFORC_MALE", INT2NUM(590));
    rb_define_const(cNWScript, "VFX_EYES_PUR_HALFORC_FEMALE", INT2NUM(591));
    rb_define_const(cNWScript, "VFX_EYES_PUR_TROGLODYTE", INT2NUM(592));
    rb_define_const(cNWScript, "VFX_EYES_CYN_HUMAN_MALE", INT2NUM(593));
    rb_define_const(cNWScript, "VFX_EYES_CYN_HUMAN_FEMALE", INT2NUM(594));
    rb_define_const(cNWScript, "VFX_EYES_CYN_DWARF_MALE", INT2NUM(595));
    rb_define_const(cNWScript, "VFX_EYES_CYN_DWARF_FEMALE", INT2NUM(596));
    rb_define_const(cNWScript, "VFX_EYES_CYN_ELF_MALE", INT2NUM(597));
    rb_define_const(cNWScript, "VFX_EYES_CYN_ELF_FEMALE", INT2NUM(598));
    rb_define_const(cNWScript, "VFX_EYES_CYN_GNOME_MALE", INT2NUM(599));
    rb_define_const(cNWScript, "VFX_EYES_CYN_GNOME_FEMALE", INT2NUM(600));
    rb_define_const(cNWScript, "VFX_EYES_CYN_HALFLING_MALE", INT2NUM(601));
    rb_define_const(cNWScript, "VFX_EYES_CYN_HALFLING_FEMALE", INT2NUM(602));
    rb_define_const(cNWScript, "VFX_EYES_CYN_HALFORC_MALE", INT2NUM(603));
    rb_define_const(cNWScript, "VFX_EYES_CYN_HALFORC_FEMALE", INT2NUM(604));
    rb_define_const(cNWScript, "VFX_EYES_CYN_TROGLODYTE", INT2NUM(605));
    rb_define_const(cNWScript, "VFX_EYES_WHT_HUMAN_MALE", INT2NUM(606));
    rb_define_const(cNWScript, "VFX_EYES_WHT_HUMAN_FEMALE", INT2NUM(607));
    rb_define_const(cNWScript, "VFX_EYES_WHT_DWARF_MALE", INT2NUM(608));
    rb_define_const(cNWScript, "VFX_EYES_WHT_DWARF_FEMALE", INT2NUM(609));
    rb_define_const(cNWScript, "VFX_EYES_WHT_ELF_MALE", INT2NUM(610));
    rb_define_const(cNWScript, "VFX_EYES_WHT_ELF_FEMALE", INT2NUM(611));
    rb_define_const(cNWScript, "VFX_EYES_WHT_GNOME_MALE", INT2NUM(612));
    rb_define_const(cNWScript, "VFX_EYES_WHT_GNOME_FEMALE", INT2NUM(613));
    rb_define_const(cNWScript, "VFX_EYES_WHT_HALFLING_MALE", INT2NUM(614));
    rb_define_const(cNWScript, "VFX_EYES_WHT_HALFLING_FEMALE", INT2NUM(615));
    rb_define_const(cNWScript, "VFX_EYES_WHT_HALFORC_MALE", INT2NUM(616));
    rb_define_const(cNWScript, "VFX_EYES_WHT_HALFORC_FEMALE", INT2NUM(617));
    rb_define_const(cNWScript, "VFX_EYES_WHT_TROGLODYTE", INT2NUM(618));
    rb_define_const(cNWScript, "VFX_IMP_PDK_GENERIC_PULSE", INT2NUM(623));
    rb_define_const(cNWScript, "VFX_IMP_PDK_GENERIC_HEAD_HIT", INT2NUM(624));
    rb_define_const(cNWScript, "VFX_IMP_PDK_RALLYING_CRY", INT2NUM(625));
    rb_define_const(cNWScript, "VFX_IMP_PDK_HEROIC_SHIELD", INT2NUM(626));
    rb_define_const(cNWScript, "VFX_IMP_PDK_INSPIRE_COURAGE", INT2NUM(627));
    rb_define_const(cNWScript, "VFX_DUR_PDK_FEAR", INT2NUM(628));
    rb_define_const(cNWScript, "VFX_IMP_PDK_WRATH", INT2NUM(629));
    rb_define_const(cNWScript, "VFX_IMP_PDK_OATH", INT2NUM(630));
    rb_define_const(cNWScript, "VFX_IMP_PDK_FINAL_STAND", INT2NUM(631));
    rb_define_const(cNWScript, "VFX_DUR_ARROW_IN_STERNUM", INT2NUM(632));
    rb_define_const(cNWScript, "VFX_DUR_ARROW_IN_CHEST_LEFT", INT2NUM(633));
    rb_define_const(cNWScript, "VFX_DUR_ARROW_IN_CHEST_RIGHT", INT2NUM(634));
    rb_define_const(cNWScript, "VFX_DUR_ARROW_IN_BACK", INT2NUM(635));
    rb_define_const(cNWScript, "VFX_DUR_ARROW_IN_TEMPLES", INT2NUM(636));
    rb_define_const(cNWScript, "VFX_DUR_ARROW_IN_FACE", INT2NUM(637));
    rb_define_const(cNWScript, "VFX_DUR_ARROW_IN_HEAD", INT2NUM(638));
    rb_define_const(cNWScript, "VFX_DUR_QUILL_IN_CHEST", INT2NUM(639));
    rb_define_const(cNWScript, "VFX_IMP_STARBURST_GREEN", INT2NUM(644));
    rb_define_const(cNWScript, "VFX_IMP_STARBURST_RED", INT2NUM(645));
    rb_define_const(cNWScript, "VFX_IMP_NIGHTMARE_HEAD_HIT", INT2NUM(670));
    rb_define_const(cNWScript, "AOE_PER_FOGACID", INT2NUM(0));
    rb_define_const(cNWScript, "AOE_PER_FOGFIRE", INT2NUM(1));
    rb_define_const(cNWScript, "AOE_PER_FOGSTINK", INT2NUM(2));
    rb_define_const(cNWScript, "AOE_PER_FOGKILL", INT2NUM(3));
    rb_define_const(cNWScript, "AOE_PER_FOGMIND", INT2NUM(4));
    rb_define_const(cNWScript, "AOE_PER_WALLFIRE", INT2NUM(5));
    rb_define_const(cNWScript, "AOE_PER_WALLWIND", INT2NUM(6));
    rb_define_const(cNWScript, "AOE_PER_WALLBLADE", INT2NUM(7));
    rb_define_const(cNWScript, "AOE_PER_WEB", INT2NUM(8));
    rb_define_const(cNWScript, "AOE_PER_ENTANGLE", INT2NUM(9));
    rb_define_const(cNWScript, "AOE_PER_DARKNESS", INT2NUM(11));
    rb_define_const(cNWScript, "AOE_MOB_CIRCEVIL", INT2NUM(12));
    rb_define_const(cNWScript, "AOE_MOB_CIRCGOOD", INT2NUM(13));
    rb_define_const(cNWScript, "AOE_MOB_CIRCLAW", INT2NUM(14));
    rb_define_const(cNWScript, "AOE_MOB_CIRCCHAOS", INT2NUM(15));
    rb_define_const(cNWScript, "AOE_MOB_FEAR", INT2NUM(16));
    rb_define_const(cNWScript, "AOE_MOB_BLINDING", INT2NUM(17));
    rb_define_const(cNWScript, "AOE_MOB_UNEARTHLY", INT2NUM(18));
    rb_define_const(cNWScript, "AOE_MOB_MENACE", INT2NUM(19));
    rb_define_const(cNWScript, "AOE_MOB_UNNATURAL", INT2NUM(20));
    rb_define_const(cNWScript, "AOE_MOB_STUN", INT2NUM(21));
    rb_define_const(cNWScript, "AOE_MOB_PROTECTION", INT2NUM(22));
    rb_define_const(cNWScript, "AOE_MOB_FIRE", INT2NUM(23));
    rb_define_const(cNWScript, "AOE_MOB_FROST", INT2NUM(24));
    rb_define_const(cNWScript, "AOE_MOB_ELECTRICAL", INT2NUM(25));
    rb_define_const(cNWScript, "AOE_PER_FOGGHOUL", INT2NUM(26));
    rb_define_const(cNWScript, "AOE_MOB_TYRANT_FOG", INT2NUM(27));
    rb_define_const(cNWScript, "AOE_PER_STORM", INT2NUM(28));
    rb_define_const(cNWScript, "AOE_PER_INVIS_SPHERE", INT2NUM(29));
    rb_define_const(cNWScript, "AOE_MOB_SILENCE", INT2NUM(30));
    rb_define_const(cNWScript, "AOE_PER_DELAY_BLAST_FIREBALL", INT2NUM(31));
    rb_define_const(cNWScript, "AOE_PER_GREASE", INT2NUM(32));
    rb_define_const(cNWScript, "AOE_PER_CREEPING_DOOM", INT2NUM(33));
    rb_define_const(cNWScript, "AOE_PER_EVARDS_BLACK_TENTACLES", INT2NUM(34));
    rb_define_const(cNWScript, "AOE_MOB_INVISIBILITY_PURGE", INT2NUM(35));
    rb_define_const(cNWScript, "AOE_MOB_DRAGON_FEAR", INT2NUM(36));
    rb_define_const(cNWScript, "AOE_PER_CUSTOM_AOE", INT2NUM(37));
    rb_define_const(cNWScript, "AOE_PER_GLYPH_OF_WARDING", INT2NUM(38));
    rb_define_const(cNWScript, "AOE_PER_FOG_OF_BEWILDERMENT", INT2NUM(39));
    rb_define_const(cNWScript, "AOE_PER_VINE_MINE_CAMOUFLAGE", INT2NUM(40));
    rb_define_const(cNWScript, "AOE_MOB_TIDE_OF_BATTLE", INT2NUM(41));
    rb_define_const(cNWScript, "AOE_PER_STONEHOLD", INT2NUM(42));
    rb_define_const(cNWScript, "AOE_PER_OVERMIND", INT2NUM(43));
    rb_define_const(cNWScript, "AOE_MOB_HORRIFICAPPEARANCE", INT2NUM(44));
    rb_define_const(cNWScript, "AOE_MOB_TROGLODYTE_STENCH", INT2NUM(45));
    rb_define_const(cNWScript, "SPELL_ALL_SPELLS", INT2NUM(-1));
    rb_define_const(cNWScript, "SPELL_ACID_FOG", INT2NUM(0));
    rb_define_const(cNWScript, "SPELL_AID", INT2NUM(1));
    rb_define_const(cNWScript, "SPELL_ANIMATE_DEAD", INT2NUM(2));
    rb_define_const(cNWScript, "SPELL_BARKSKIN", INT2NUM(3));
    rb_define_const(cNWScript, "SPELL_BESTOW_CURSE", INT2NUM(4));
    rb_define_const(cNWScript, "SPELL_BLADE_BARRIER", INT2NUM(5));
    rb_define_const(cNWScript, "SPELL_BLESS", INT2NUM(6));
    rb_define_const(cNWScript, "SPELL_BLESS_WEAPON", INT2NUM(537));
    rb_define_const(cNWScript, "SPELL_BLINDNESS_AND_DEAFNESS", INT2NUM(8));
    rb_define_const(cNWScript, "SPELL_BULLS_STRENGTH", INT2NUM(9));
    rb_define_const(cNWScript, "SPELL_BURNING_HANDS", INT2NUM(10));
    rb_define_const(cNWScript, "SPELL_CALL_LIGHTNING", INT2NUM(11));
    rb_define_const(cNWScript, "SPELL_CATS_GRACE", INT2NUM(13));
    rb_define_const(cNWScript, "SPELL_CHAIN_LIGHTNING", INT2NUM(14));
    rb_define_const(cNWScript, "SPELL_CHARM_MONSTER", INT2NUM(15));
    rb_define_const(cNWScript, "SPELL_CHARM_PERSON", INT2NUM(16));
    rb_define_const(cNWScript, "SPELL_CHARM_PERSON_OR_ANIMAL", INT2NUM(17));
    rb_define_const(cNWScript, "SPELL_CIRCLE_OF_DEATH", INT2NUM(18));
    rb_define_const(cNWScript, "SPELL_CIRCLE_OF_DOOM", INT2NUM(19));
    rb_define_const(cNWScript, "SPELL_CLAIRAUDIENCE_AND_CLAIRVOYANCE", INT2NUM(20));
    rb_define_const(cNWScript, "SPELL_CLARITY", INT2NUM(21));
    rb_define_const(cNWScript, "SPELL_CLOAK_OF_CHAOS", INT2NUM(22));
    rb_define_const(cNWScript, "SPELL_CLOUDKILL", INT2NUM(23));
    rb_define_const(cNWScript, "SPELL_COLOR_SPRAY", INT2NUM(24));
    rb_define_const(cNWScript, "SPELL_CONE_OF_COLD", INT2NUM(25));
    rb_define_const(cNWScript, "SPELL_CONFUSION", INT2NUM(26));
    rb_define_const(cNWScript, "SPELL_CONTAGION", INT2NUM(27));
    rb_define_const(cNWScript, "SPELL_CONTROL_UNDEAD", INT2NUM(28));
    rb_define_const(cNWScript, "SPELL_CREATE_GREATER_UNDEAD", INT2NUM(29));
    rb_define_const(cNWScript, "SPELL_CREATE_UNDEAD", INT2NUM(30));
    rb_define_const(cNWScript, "SPELL_CURE_CRITICAL_WOUNDS", INT2NUM(31));
    rb_define_const(cNWScript, "SPELL_CURE_LIGHT_WOUNDS", INT2NUM(32));
    rb_define_const(cNWScript, "SPELL_CURE_MINOR_WOUNDS", INT2NUM(33));
    rb_define_const(cNWScript, "SPELL_CURE_MODERATE_WOUNDS", INT2NUM(34));
    rb_define_const(cNWScript, "SPELL_CURE_SERIOUS_WOUNDS", INT2NUM(35));
    rb_define_const(cNWScript, "SPELL_DARKNESS", INT2NUM(36));
    rb_define_const(cNWScript, "SPELL_DAZE", INT2NUM(37));
    rb_define_const(cNWScript, "SPELL_DEATH_WARD", INT2NUM(38));
    rb_define_const(cNWScript, "SPELL_DELAYED_BLAST_FIREBALL", INT2NUM(39));
    rb_define_const(cNWScript, "SPELL_DISMISSAL", INT2NUM(40));
    rb_define_const(cNWScript, "SPELL_DISPEL_MAGIC", INT2NUM(41));
    rb_define_const(cNWScript, "SPELL_DIVINE_POWER", INT2NUM(42));
    rb_define_const(cNWScript, "SPELL_DOMINATE_ANIMAL", INT2NUM(43));
    rb_define_const(cNWScript, "SPELL_DOMINATE_MONSTER", INT2NUM(44));
    rb_define_const(cNWScript, "SPELL_DOMINATE_PERSON", INT2NUM(45));
    rb_define_const(cNWScript, "SPELL_DOOM", INT2NUM(46));
    rb_define_const(cNWScript, "SPELL_ELEMENTAL_SHIELD", INT2NUM(47));
    rb_define_const(cNWScript, "SPELL_ELEMENTAL_SWARM", INT2NUM(48));
    rb_define_const(cNWScript, "SPELL_ENDURANCE", INT2NUM(49));
    rb_define_const(cNWScript, "SPELL_ENDURE_ELEMENTS", INT2NUM(50));
    rb_define_const(cNWScript, "SPELL_ENERGY_DRAIN", INT2NUM(51));
    rb_define_const(cNWScript, "SPELL_ENERVATION", INT2NUM(52));
    rb_define_const(cNWScript, "SPELL_ENTANGLE", INT2NUM(53));
    rb_define_const(cNWScript, "SPELL_FEAR", INT2NUM(54));
    rb_define_const(cNWScript, "SPELL_FEEBLEMIND", INT2NUM(55));
    rb_define_const(cNWScript, "SPELL_FINGER_OF_DEATH", INT2NUM(56));
    rb_define_const(cNWScript, "SPELL_FIRE_STORM", INT2NUM(57));
    rb_define_const(cNWScript, "SPELL_FIREBALL", INT2NUM(58));
    rb_define_const(cNWScript, "SPELL_FLAME_ARROW", INT2NUM(59));
    rb_define_const(cNWScript, "SPELL_FLAME_LASH", INT2NUM(60));
    rb_define_const(cNWScript, "SPELL_FLAME_STRIKE", INT2NUM(61));
    rb_define_const(cNWScript, "SPELL_FREEDOM_OF_MOVEMENT", INT2NUM(62));
    rb_define_const(cNWScript, "SPELL_GATE", INT2NUM(63));
    rb_define_const(cNWScript, "SPELL_GHOUL_TOUCH", INT2NUM(64));
    rb_define_const(cNWScript, "SPELL_GLOBE_OF_INVULNERABILITY", INT2NUM(65));
    rb_define_const(cNWScript, "SPELL_GREASE", INT2NUM(66));
    rb_define_const(cNWScript, "SPELL_GREATER_DISPELLING", INT2NUM(67));
    rb_define_const(cNWScript, "SPELL_GREATER_PLANAR_BINDING", INT2NUM(69));
    rb_define_const(cNWScript, "SPELL_GREATER_RESTORATION", INT2NUM(70));
    rb_define_const(cNWScript, "SPELL_GREATER_SPELL_BREACH", INT2NUM(72));
    rb_define_const(cNWScript, "SPELL_GREATER_SPELL_MANTLE", INT2NUM(73));
    rb_define_const(cNWScript, "SPELL_GREATER_STONESKIN", INT2NUM(74));
    rb_define_const(cNWScript, "SPELL_GUST_OF_WIND", INT2NUM(75));
    rb_define_const(cNWScript, "SPELL_HAMMER_OF_THE_GODS", INT2NUM(76));
    rb_define_const(cNWScript, "SPELL_HARM", INT2NUM(77));
    rb_define_const(cNWScript, "SPELL_HASTE", INT2NUM(78));
    rb_define_const(cNWScript, "SPELL_HEAL", INT2NUM(79));
    rb_define_const(cNWScript, "SPELL_HEALING_CIRCLE", INT2NUM(80));
    rb_define_const(cNWScript, "SPELL_HOLD_ANIMAL", INT2NUM(81));
    rb_define_const(cNWScript, "SPELL_HOLD_MONSTER", INT2NUM(82));
    rb_define_const(cNWScript, "SPELL_HOLD_PERSON", INT2NUM(83));
    rb_define_const(cNWScript, "SPELL_HOLY_AURA", INT2NUM(84));
    rb_define_const(cNWScript, "SPELL_HOLY_SWORD", INT2NUM(538));
    rb_define_const(cNWScript, "SPELL_IDENTIFY", INT2NUM(86));
    rb_define_const(cNWScript, "SPELL_IMPLOSION", INT2NUM(87));
    rb_define_const(cNWScript, "SPELL_IMPROVED_INVISIBILITY", INT2NUM(88));
    rb_define_const(cNWScript, "SPELL_INCENDIARY_CLOUD", INT2NUM(89));
    rb_define_const(cNWScript, "SPELL_INVISIBILITY", INT2NUM(90));
    rb_define_const(cNWScript, "SPELL_INVISIBILITY_PURGE", INT2NUM(91));
    rb_define_const(cNWScript, "SPELL_INVISIBILITY_SPHERE", INT2NUM(92));
    rb_define_const(cNWScript, "SPELL_KNOCK", INT2NUM(93));
    rb_define_const(cNWScript, "SPELL_LESSER_DISPEL", INT2NUM(94));
    rb_define_const(cNWScript, "SPELL_LESSER_MIND_BLANK", INT2NUM(95));
    rb_define_const(cNWScript, "SPELL_LESSER_PLANAR_BINDING", INT2NUM(96));
    rb_define_const(cNWScript, "SPELL_LESSER_RESTORATION", INT2NUM(97));
    rb_define_const(cNWScript, "SPELL_LESSER_SPELL_BREACH", INT2NUM(98));
    rb_define_const(cNWScript, "SPELL_LESSER_SPELL_MANTLE", INT2NUM(99));
    rb_define_const(cNWScript, "SPELL_LIGHT", INT2NUM(100));
    rb_define_const(cNWScript, "SPELL_LIGHTNING_BOLT", INT2NUM(101));
    rb_define_const(cNWScript, "SPELL_MAGE_ARMOR", INT2NUM(102));
    rb_define_const(cNWScript, "SPELL_MAGIC_CIRCLE_AGAINST_CHAOS", INT2NUM(103));
    rb_define_const(cNWScript, "SPELL_MAGIC_CIRCLE_AGAINST_EVIL", INT2NUM(104));
    rb_define_const(cNWScript, "SPELL_MAGIC_CIRCLE_AGAINST_GOOD", INT2NUM(105));
    rb_define_const(cNWScript, "SPELL_MAGIC_CIRCLE_AGAINST_LAW", INT2NUM(106));
    rb_define_const(cNWScript, "SPELL_MAGIC_MISSILE", INT2NUM(107));
    rb_define_const(cNWScript, "SPELL_MAGIC_VESTMENT", INT2NUM(546));
    rb_define_const(cNWScript, "SPELL_MASS_BLINDNESS_AND_DEAFNESS", INT2NUM(110));
    rb_define_const(cNWScript, "SPELL_MASS_CHARM", INT2NUM(111));
    rb_define_const(cNWScript, "SPELL_MASS_HASTE", INT2NUM(113));
    rb_define_const(cNWScript, "SPELL_MASS_HEAL", INT2NUM(114));
    rb_define_const(cNWScript, "SPELL_MELFS_ACID_ARROW", INT2NUM(115));
    rb_define_const(cNWScript, "SPELL_METEOR_SWARM", INT2NUM(116));
    rb_define_const(cNWScript, "SPELL_MIND_BLANK", INT2NUM(117));
    rb_define_const(cNWScript, "SPELL_MIND_FOG", INT2NUM(118));
    rb_define_const(cNWScript, "SPELL_MINOR_GLOBE_OF_INVULNERABILITY", INT2NUM(119));
    rb_define_const(cNWScript, "SPELL_GHOSTLY_VISAGE", INT2NUM(120));
    rb_define_const(cNWScript, "SPELL_ETHEREAL_VISAGE", INT2NUM(121));
    rb_define_const(cNWScript, "SPELL_MORDENKAINENS_DISJUNCTION", INT2NUM(122));
    rb_define_const(cNWScript, "SPELL_MORDENKAINENS_SWORD", INT2NUM(123));
    rb_define_const(cNWScript, "SPELL_NATURES_BALANCE", INT2NUM(124));
    rb_define_const(cNWScript, "SPELL_NEGATIVE_ENERGY_PROTECTION", INT2NUM(125));
    rb_define_const(cNWScript, "SPELL_NEUTRALIZE_POISON", INT2NUM(126));
    rb_define_const(cNWScript, "SPELL_PHANTASMAL_KILLER", INT2NUM(127));
    rb_define_const(cNWScript, "SPELL_PLANAR_BINDING", INT2NUM(128));
    rb_define_const(cNWScript, "SPELL_POISON", INT2NUM(129));
    rb_define_const(cNWScript, "SPELL_POLYMORPH_SELF", INT2NUM(130));
    rb_define_const(cNWScript, "SPELL_POWER_WORD_KILL", INT2NUM(131));
    rb_define_const(cNWScript, "SPELL_POWER_WORD_STUN", INT2NUM(132));
    rb_define_const(cNWScript, "SPELL_PRAYER", INT2NUM(133));
    rb_define_const(cNWScript, "SPELL_PREMONITION", INT2NUM(134));
    rb_define_const(cNWScript, "SPELL_PRISMATIC_SPRAY", INT2NUM(135));
    rb_define_const(cNWScript, "SPELL_PROTECTION__FROM_CHAOS", INT2NUM(136));
    rb_define_const(cNWScript, "SPELL_PROTECTION_FROM_ELEMENTS", INT2NUM(137));
    rb_define_const(cNWScript, "SPELL_PROTECTION_FROM_EVIL", INT2NUM(138));
    rb_define_const(cNWScript, "SPELL_PROTECTION_FROM_GOOD", INT2NUM(139));
    rb_define_const(cNWScript, "SPELL_PROTECTION_FROM_LAW", INT2NUM(140));
    rb_define_const(cNWScript, "SPELL_PROTECTION_FROM_SPELLS", INT2NUM(141));
    rb_define_const(cNWScript, "SPELL_RAISE_DEAD", INT2NUM(142));
    rb_define_const(cNWScript, "SPELL_RAY_OF_ENFEEBLEMENT", INT2NUM(143));
    rb_define_const(cNWScript, "SPELL_RAY_OF_FROST", INT2NUM(144));
    rb_define_const(cNWScript, "SPELL_REMOVE_BLINDNESS_AND_DEAFNESS", INT2NUM(145));
    rb_define_const(cNWScript, "SPELL_REMOVE_CURSE", INT2NUM(146));
    rb_define_const(cNWScript, "SPELL_REMOVE_DISEASE", INT2NUM(147));
    rb_define_const(cNWScript, "SPELL_REMOVE_FEAR", INT2NUM(148));
    rb_define_const(cNWScript, "SPELL_REMOVE_PARALYSIS", INT2NUM(149));
    rb_define_const(cNWScript, "SPELL_RESIST_ELEMENTS", INT2NUM(150));
    rb_define_const(cNWScript, "SPELL_RESISTANCE", INT2NUM(151));
    rb_define_const(cNWScript, "SPELL_RESTORATION", INT2NUM(152));
    rb_define_const(cNWScript, "SPELL_RESURRECTION", INT2NUM(153));
    rb_define_const(cNWScript, "SPELL_SANCTUARY", INT2NUM(154));
    rb_define_const(cNWScript, "SPELL_SCARE", INT2NUM(155));
    rb_define_const(cNWScript, "SPELL_SEARING_LIGHT", INT2NUM(156));
    rb_define_const(cNWScript, "SPELL_SEE_INVISIBILITY", INT2NUM(157));
    rb_define_const(cNWScript, "SPELL_SHADOW_SHIELD", INT2NUM(160));
    rb_define_const(cNWScript, "SPELL_SHAPECHANGE", INT2NUM(161));
    rb_define_const(cNWScript, "SPELL_SHIELD_OF_LAW", INT2NUM(162));
    rb_define_const(cNWScript, "SPELL_SILENCE", INT2NUM(163));
    rb_define_const(cNWScript, "SPELL_SLAY_LIVING", INT2NUM(164));
    rb_define_const(cNWScript, "SPELL_SLEEP", INT2NUM(165));
    rb_define_const(cNWScript, "SPELL_SLOW", INT2NUM(166));
    rb_define_const(cNWScript, "SPELL_SOUND_BURST", INT2NUM(167));
    rb_define_const(cNWScript, "SPELL_SPELL_RESISTANCE", INT2NUM(168));
    rb_define_const(cNWScript, "SPELL_SPELL_MANTLE", INT2NUM(169));
    rb_define_const(cNWScript, "SPELL_SPHERE_OF_CHAOS", INT2NUM(170));
    rb_define_const(cNWScript, "SPELL_STINKING_CLOUD", INT2NUM(171));
    rb_define_const(cNWScript, "SPELL_STONESKIN", INT2NUM(172));
    rb_define_const(cNWScript, "SPELL_STORM_OF_VENGEANCE", INT2NUM(173));
    rb_define_const(cNWScript, "SPELL_SUMMON_CREATURE_I", INT2NUM(174));
    rb_define_const(cNWScript, "SPELL_SUMMON_CREATURE_II", INT2NUM(175));
    rb_define_const(cNWScript, "SPELL_SUMMON_CREATURE_III", INT2NUM(176));
    rb_define_const(cNWScript, "SPELL_SUMMON_CREATURE_IV", INT2NUM(177));
    rb_define_const(cNWScript, "SPELL_SUMMON_CREATURE_IX", INT2NUM(178));
    rb_define_const(cNWScript, "SPELL_SUMMON_CREATURE_V", INT2NUM(179));
    rb_define_const(cNWScript, "SPELL_SUMMON_CREATURE_VI", INT2NUM(180));
    rb_define_const(cNWScript, "SPELL_SUMMON_CREATURE_VII", INT2NUM(181));
    rb_define_const(cNWScript, "SPELL_SUMMON_CREATURE_VIII", INT2NUM(182));
    rb_define_const(cNWScript, "SPELL_SUNBEAM", INT2NUM(183));
    rb_define_const(cNWScript, "SPELL_TENSERS_TRANSFORMATION", INT2NUM(184));
    rb_define_const(cNWScript, "SPELL_TIME_STOP", INT2NUM(185));
    rb_define_const(cNWScript, "SPELL_TRUE_SEEING", INT2NUM(186));
    rb_define_const(cNWScript, "SPELL_UNHOLY_AURA", INT2NUM(187));
    rb_define_const(cNWScript, "SPELL_VAMPIRIC_TOUCH", INT2NUM(188));
    rb_define_const(cNWScript, "SPELL_VIRTUE", INT2NUM(189));
    rb_define_const(cNWScript, "SPELL_WAIL_OF_THE_BANSHEE", INT2NUM(190));
    rb_define_const(cNWScript, "SPELL_WALL_OF_FIRE", INT2NUM(191));
    rb_define_const(cNWScript, "SPELL_WEB", INT2NUM(192));
    rb_define_const(cNWScript, "SPELL_WEIRD", INT2NUM(193));
    rb_define_const(cNWScript, "SPELL_WORD_OF_FAITH", INT2NUM(194));
    rb_define_const(cNWScript, "SPELLABILITY_AURA_BLINDING", INT2NUM(195));
    rb_define_const(cNWScript, "SPELLABILITY_AURA_COLD", INT2NUM(196));
    rb_define_const(cNWScript, "SPELLABILITY_AURA_ELECTRICITY", INT2NUM(197));
    rb_define_const(cNWScript, "SPELLABILITY_AURA_FEAR", INT2NUM(198));
    rb_define_const(cNWScript, "SPELLABILITY_AURA_FIRE", INT2NUM(199));
    rb_define_const(cNWScript, "SPELLABILITY_AURA_MENACE", INT2NUM(200));
    rb_define_const(cNWScript, "SPELLABILITY_AURA_PROTECTION", INT2NUM(201));
    rb_define_const(cNWScript, "SPELLABILITY_AURA_STUN", INT2NUM(202));
    rb_define_const(cNWScript, "SPELLABILITY_AURA_UNEARTHLY_VISAGE", INT2NUM(203));
    rb_define_const(cNWScript, "SPELLABILITY_AURA_UNNATURAL", INT2NUM(204));
    rb_define_const(cNWScript, "SPELLABILITY_BOLT_ABILITY_DRAIN_CHARISMA", INT2NUM(205));
    rb_define_const(cNWScript, "SPELLABILITY_BOLT_ABILITY_DRAIN_CONSTITUTION", INT2NUM(206));
    rb_define_const(cNWScript, "SPELLABILITY_BOLT_ABILITY_DRAIN_DEXTERITY", INT2NUM(207));
    rb_define_const(cNWScript, "SPELLABILITY_BOLT_ABILITY_DRAIN_INTELLIGENCE", INT2NUM(208));
    rb_define_const(cNWScript, "SPELLABILITY_BOLT_ABILITY_DRAIN_STRENGTH", INT2NUM(209));
    rb_define_const(cNWScript, "SPELLABILITY_BOLT_ABILITY_DRAIN_WISDOM", INT2NUM(210));
    rb_define_const(cNWScript, "SPELLABILITY_BOLT_ACID", INT2NUM(211));
    rb_define_const(cNWScript, "SPELLABILITY_BOLT_CHARM", INT2NUM(212));
    rb_define_const(cNWScript, "SPELLABILITY_BOLT_COLD", INT2NUM(213));
    rb_define_const(cNWScript, "SPELLABILITY_BOLT_CONFUSE", INT2NUM(214));
    rb_define_const(cNWScript, "SPELLABILITY_BOLT_DAZE", INT2NUM(215));
    rb_define_const(cNWScript, "SPELLABILITY_BOLT_DEATH", INT2NUM(216));
    rb_define_const(cNWScript, "SPELLABILITY_BOLT_DISEASE", INT2NUM(217));
    rb_define_const(cNWScript, "SPELLABILITY_BOLT_DOMINATE", INT2NUM(218));
    rb_define_const(cNWScript, "SPELLABILITY_BOLT_FIRE", INT2NUM(219));
    rb_define_const(cNWScript, "SPELLABILITY_BOLT_KNOCKDOWN", INT2NUM(220));
    rb_define_const(cNWScript, "SPELLABILITY_BOLT_LEVEL_DRAIN", INT2NUM(221));
    rb_define_const(cNWScript, "SPELLABILITY_BOLT_LIGHTNING", INT2NUM(222));
    rb_define_const(cNWScript, "SPELLABILITY_BOLT_PARALYZE", INT2NUM(223));
    rb_define_const(cNWScript, "SPELLABILITY_BOLT_POISON", INT2NUM(224));
    rb_define_const(cNWScript, "SPELLABILITY_BOLT_SHARDS", INT2NUM(225));
    rb_define_const(cNWScript, "SPELLABILITY_BOLT_SLOW", INT2NUM(226));
    rb_define_const(cNWScript, "SPELLABILITY_BOLT_STUN", INT2NUM(227));
    rb_define_const(cNWScript, "SPELLABILITY_BOLT_WEB", INT2NUM(228));
    rb_define_const(cNWScript, "SPELLABILITY_CONE_ACID", INT2NUM(229));
    rb_define_const(cNWScript, "SPELLABILITY_CONE_COLD", INT2NUM(230));
    rb_define_const(cNWScript, "SPELLABILITY_CONE_DISEASE", INT2NUM(231));
    rb_define_const(cNWScript, "SPELLABILITY_CONE_FIRE", INT2NUM(232));
    rb_define_const(cNWScript, "SPELLABILITY_CONE_LIGHTNING", INT2NUM(233));
    rb_define_const(cNWScript, "SPELLABILITY_CONE_POISON", INT2NUM(234));
    rb_define_const(cNWScript, "SPELLABILITY_CONE_SONIC", INT2NUM(235));
    rb_define_const(cNWScript, "SPELLABILITY_DRAGON_BREATH_ACID", INT2NUM(236));
    rb_define_const(cNWScript, "SPELLABILITY_DRAGON_BREATH_COLD", INT2NUM(237));
    rb_define_const(cNWScript, "SPELLABILITY_DRAGON_BREATH_FEAR", INT2NUM(238));
    rb_define_const(cNWScript, "SPELLABILITY_DRAGON_BREATH_FIRE", INT2NUM(239));
    rb_define_const(cNWScript, "SPELLABILITY_DRAGON_BREATH_GAS", INT2NUM(240));
    rb_define_const(cNWScript, "SPELLABILITY_DRAGON_BREATH_LIGHTNING", INT2NUM(241));
    rb_define_const(cNWScript, "SPELLABILITY_DRAGON_BREATH_PARALYZE", INT2NUM(242));
    rb_define_const(cNWScript, "SPELLABILITY_DRAGON_BREATH_SLEEP", INT2NUM(243));
    rb_define_const(cNWScript, "SPELLABILITY_DRAGON_BREATH_SLOW", INT2NUM(244));
    rb_define_const(cNWScript, "SPELLABILITY_DRAGON_BREATH_WEAKEN", INT2NUM(245));
    rb_define_const(cNWScript, "SPELLABILITY_DRAGON_WING_BUFFET", INT2NUM(246));
    rb_define_const(cNWScript, "SPELLABILITY_FEROCITY_1", INT2NUM(247));
    rb_define_const(cNWScript, "SPELLABILITY_FEROCITY_2", INT2NUM(248));
    rb_define_const(cNWScript, "SPELLABILITY_FEROCITY_3", INT2NUM(249));
    rb_define_const(cNWScript, "SPELLABILITY_GAZE_CHARM", INT2NUM(250));
    rb_define_const(cNWScript, "SPELLABILITY_GAZE_CONFUSION", INT2NUM(251));
    rb_define_const(cNWScript, "SPELLABILITY_GAZE_DAZE", INT2NUM(252));
    rb_define_const(cNWScript, "SPELLABILITY_GAZE_DEATH", INT2NUM(253));
    rb_define_const(cNWScript, "SPELLABILITY_GAZE_DESTROY_CHAOS", INT2NUM(254));
    rb_define_const(cNWScript, "SPELLABILITY_GAZE_DESTROY_EVIL", INT2NUM(255));
    rb_define_const(cNWScript, "SPELLABILITY_GAZE_DESTROY_GOOD", INT2NUM(256));
    rb_define_const(cNWScript, "SPELLABILITY_GAZE_DESTROY_LAW", INT2NUM(257));
    rb_define_const(cNWScript, "SPELLABILITY_GAZE_DOMINATE", INT2NUM(258));
    rb_define_const(cNWScript, "SPELLABILITY_GAZE_DOOM", INT2NUM(259));
    rb_define_const(cNWScript, "SPELLABILITY_GAZE_FEAR", INT2NUM(260));
    rb_define_const(cNWScript, "SPELLABILITY_GAZE_PARALYSIS", INT2NUM(261));
    rb_define_const(cNWScript, "SPELLABILITY_GAZE_STUNNED", INT2NUM(262));
    rb_define_const(cNWScript, "SPELLABILITY_GOLEM_BREATH_GAS", INT2NUM(263));
    rb_define_const(cNWScript, "SPELLABILITY_HELL_HOUND_FIREBREATH", INT2NUM(264));
    rb_define_const(cNWScript, "SPELLABILITY_HOWL_CONFUSE", INT2NUM(265));
    rb_define_const(cNWScript, "SPELLABILITY_HOWL_DAZE", INT2NUM(266));
    rb_define_const(cNWScript, "SPELLABILITY_HOWL_DEATH", INT2NUM(267));
    rb_define_const(cNWScript, "SPELLABILITY_HOWL_DOOM", INT2NUM(268));
    rb_define_const(cNWScript, "SPELLABILITY_HOWL_FEAR", INT2NUM(269));
    rb_define_const(cNWScript, "SPELLABILITY_HOWL_PARALYSIS", INT2NUM(270));
    rb_define_const(cNWScript, "SPELLABILITY_HOWL_SONIC", INT2NUM(271));
    rb_define_const(cNWScript, "SPELLABILITY_HOWL_STUN", INT2NUM(272));
    rb_define_const(cNWScript, "SPELLABILITY_INTENSITY_1", INT2NUM(273));
    rb_define_const(cNWScript, "SPELLABILITY_INTENSITY_2", INT2NUM(274));
    rb_define_const(cNWScript, "SPELLABILITY_INTENSITY_3", INT2NUM(275));
    rb_define_const(cNWScript, "SPELLABILITY_KRENSHAR_SCARE", INT2NUM(276));
    rb_define_const(cNWScript, "SPELLABILITY_LESSER_BODY_ADJUSTMENT", INT2NUM(277));
    rb_define_const(cNWScript, "SPELLABILITY_MEPHIT_SALT_BREATH", INT2NUM(278));
    rb_define_const(cNWScript, "SPELLABILITY_MEPHIT_STEAM_BREATH", INT2NUM(279));
    rb_define_const(cNWScript, "SPELLABILITY_MUMMY_BOLSTER_UNDEAD", INT2NUM(280));
    rb_define_const(cNWScript, "SPELLABILITY_PULSE_DROWN", INT2NUM(281));
    rb_define_const(cNWScript, "SPELLABILITY_PULSE_SPORES", INT2NUM(282));
    rb_define_const(cNWScript, "SPELLABILITY_PULSE_WHIRLWIND", INT2NUM(283));
    rb_define_const(cNWScript, "SPELLABILITY_PULSE_FIRE", INT2NUM(284));
    rb_define_const(cNWScript, "SPELLABILITY_PULSE_LIGHTNING", INT2NUM(285));
    rb_define_const(cNWScript, "SPELLABILITY_PULSE_COLD", INT2NUM(286));
    rb_define_const(cNWScript, "SPELLABILITY_PULSE_NEGATIVE", INT2NUM(287));
    rb_define_const(cNWScript, "SPELLABILITY_PULSE_HOLY", INT2NUM(288));
    rb_define_const(cNWScript, "SPELLABILITY_PULSE_DEATH", INT2NUM(289));
    rb_define_const(cNWScript, "SPELLABILITY_PULSE_LEVEL_DRAIN", INT2NUM(290));
    rb_define_const(cNWScript, "SPELLABILITY_PULSE_ABILITY_DRAIN_INTELLIGENCE", INT2NUM(291));
    rb_define_const(cNWScript, "SPELLABILITY_PULSE_ABILITY_DRAIN_CHARISMA", INT2NUM(292));
    rb_define_const(cNWScript, "SPELLABILITY_PULSE_ABILITY_DRAIN_CONSTITUTION", INT2NUM(293));
    rb_define_const(cNWScript, "SPELLABILITY_PULSE_ABILITY_DRAIN_DEXTERITY", INT2NUM(294));
    rb_define_const(cNWScript, "SPELLABILITY_PULSE_ABILITY_DRAIN_STRENGTH", INT2NUM(295));
    rb_define_const(cNWScript, "SPELLABILITY_PULSE_ABILITY_DRAIN_WISDOM", INT2NUM(296));
    rb_define_const(cNWScript, "SPELLABILITY_PULSE_POISON", INT2NUM(297));
    rb_define_const(cNWScript, "SPELLABILITY_PULSE_DISEASE", INT2NUM(298));
    rb_define_const(cNWScript, "SPELLABILITY_RAGE_3", INT2NUM(299));
    rb_define_const(cNWScript, "SPELLABILITY_RAGE_4", INT2NUM(300));
    rb_define_const(cNWScript, "SPELLABILITY_RAGE_5", INT2NUM(301));
    rb_define_const(cNWScript, "SPELLABILITY_SMOKE_CLAW", INT2NUM(302));
    rb_define_const(cNWScript, "SPELLABILITY_SUMMON_SLAAD", INT2NUM(303));
    rb_define_const(cNWScript, "SPELLABILITY_SUMMON_TANARRI", INT2NUM(304));
    rb_define_const(cNWScript, "SPELLABILITY_TRUMPET_BLAST", INT2NUM(305));
    rb_define_const(cNWScript, "SPELLABILITY_TYRANT_FOG_MIST", INT2NUM(306));
    rb_define_const(cNWScript, "SPELLABILITY_BARBARIAN_RAGE", INT2NUM(307));
    rb_define_const(cNWScript, "SPELLABILITY_TURN_UNDEAD", INT2NUM(308));
    rb_define_const(cNWScript, "SPELLABILITY_WHOLENESS_OF_BODY", INT2NUM(309));
    rb_define_const(cNWScript, "SPELLABILITY_QUIVERING_PALM", INT2NUM(310));
    rb_define_const(cNWScript, "SPELLABILITY_EMPTY_BODY", INT2NUM(311));
    rb_define_const(cNWScript, "SPELLABILITY_DETECT_EVIL", INT2NUM(312));
    rb_define_const(cNWScript, "SPELLABILITY_LAY_ON_HANDS", INT2NUM(313));
    rb_define_const(cNWScript, "SPELLABILITY_AURA_OF_COURAGE", INT2NUM(314));
    rb_define_const(cNWScript, "SPELLABILITY_SMITE_EVIL", INT2NUM(315));
    rb_define_const(cNWScript, "SPELLABILITY_REMOVE_DISEASE", INT2NUM(316));
    rb_define_const(cNWScript, "SPELLABILITY_SUMMON_ANIMAL_COMPANION", INT2NUM(317));
    rb_define_const(cNWScript, "SPELLABILITY_SUMMON_FAMILIAR", INT2NUM(318));
    rb_define_const(cNWScript, "SPELLABILITY_ELEMENTAL_SHAPE", INT2NUM(319));
    rb_define_const(cNWScript, "SPELLABILITY_WILD_SHAPE", INT2NUM(320));
    rb_define_const(cNWScript, "SPELL_SHADES_SUMMON_SHADOW", INT2NUM(324));
    rb_define_const(cNWScript, "SPELL_SHADES_CONE_OF_COLD", INT2NUM(340));
    rb_define_const(cNWScript, "SPELL_SHADES_FIREBALL", INT2NUM(341));
    rb_define_const(cNWScript, "SPELL_SHADES_STONESKIN", INT2NUM(342));
    rb_define_const(cNWScript, "SPELL_SHADES_WALL_OF_FIRE", INT2NUM(343));
    rb_define_const(cNWScript, "SPELL_SHADOW_CONJURATION_SUMMON_SHADOW", INT2NUM(344));
    rb_define_const(cNWScript, "SPELL_SHADOW_CONJURATION_DARKNESS", INT2NUM(345));
    rb_define_const(cNWScript, "SPELL_SHADOW_CONJURATION_INIVSIBILITY", INT2NUM(346));
    rb_define_const(cNWScript, "SPELL_SHADOW_CONJURATION_MAGE_ARMOR", INT2NUM(347));
    rb_define_const(cNWScript, "SPELL_SHADOW_CONJURATION_MAGIC_MISSILE", INT2NUM(348));
    rb_define_const(cNWScript, "SPELL_GREATER_SHADOW_CONJURATION_SUMMON_SHADOW", INT2NUM(349));
    rb_define_const(cNWScript, "SPELL_GREATER_SHADOW_CONJURATION_ACID_ARROW", INT2NUM(350));
    rb_define_const(cNWScript, "SPELL_GREATER_SHADOW_CONJURATION_MIRROR_IMAGE", INT2NUM(351));
    rb_define_const(cNWScript, "SPELL_GREATER_SHADOW_CONJURATION_WEB", INT2NUM(352));
    rb_define_const(cNWScript, "SPELL_GREATER_SHADOW_CONJURATION_MINOR_GLOBE", INT2NUM(353));
    rb_define_const(cNWScript, "SPELL_EAGLE_SPLEDOR", INT2NUM(354));
    rb_define_const(cNWScript, "SPELL_OWLS_WISDOM", INT2NUM(355));
    rb_define_const(cNWScript, "SPELL_FOXS_CUNNING", INT2NUM(356));
    rb_define_const(cNWScript, "SPELL_GREATER_EAGLE_SPLENDOR", INT2NUM(357));
    rb_define_const(cNWScript, "SPELL_GREATER_OWLS_WISDOM", INT2NUM(358));
    rb_define_const(cNWScript, "SPELL_GREATER_FOXS_CUNNING", INT2NUM(359));
    rb_define_const(cNWScript, "SPELL_GREATER_BULLS_STRENGTH", INT2NUM(360));
    rb_define_const(cNWScript, "SPELL_GREATER_CATS_GRACE", INT2NUM(361));
    rb_define_const(cNWScript, "SPELL_GREATER_ENDURANCE", INT2NUM(362));
    rb_define_const(cNWScript, "SPELL_AWAKEN", INT2NUM(363));
    rb_define_const(cNWScript, "SPELL_CREEPING_DOOM", INT2NUM(364));
    rb_define_const(cNWScript, "SPELL_DARKVISION", INT2NUM(365));
    rb_define_const(cNWScript, "SPELL_DESTRUCTION", INT2NUM(366));
    rb_define_const(cNWScript, "SPELL_HORRID_WILTING", INT2NUM(367));
    rb_define_const(cNWScript, "SPELL_ICE_STORM", INT2NUM(368));
    rb_define_const(cNWScript, "SPELL_ENERGY_BUFFER", INT2NUM(369));
    rb_define_const(cNWScript, "SPELL_NEGATIVE_ENERGY_BURST", INT2NUM(370));
    rb_define_const(cNWScript, "SPELL_NEGATIVE_ENERGY_RAY", INT2NUM(371));
    rb_define_const(cNWScript, "SPELL_AURA_OF_VITALITY", INT2NUM(372));
    rb_define_const(cNWScript, "SPELL_WAR_CRY", INT2NUM(373));
    rb_define_const(cNWScript, "SPELL_REGENERATE", INT2NUM(374));
    rb_define_const(cNWScript, "SPELL_EVARDS_BLACK_TENTACLES", INT2NUM(375));
    rb_define_const(cNWScript, "SPELL_LEGEND_LORE", INT2NUM(376));
    rb_define_const(cNWScript, "SPELL_FIND_TRAPS", INT2NUM(377));
    rb_define_const(cNWScript, "SPELLABILITY_SUMMON_MEPHIT", INT2NUM(378));
    rb_define_const(cNWScript, "SPELLABILITY_SUMMON_CELESTIAL", INT2NUM(379));
    rb_define_const(cNWScript, "SPELLABILITY_BATTLE_MASTERY", INT2NUM(380));
    rb_define_const(cNWScript, "SPELLABILITY_DIVINE_STRENGTH", INT2NUM(381));
    rb_define_const(cNWScript, "SPELLABILITY_DIVINE_PROTECTION", INT2NUM(382));
    rb_define_const(cNWScript, "SPELLABILITY_NEGATIVE_PLANE_AVATAR", INT2NUM(383));
    rb_define_const(cNWScript, "SPELLABILITY_DIVINE_TRICKERY", INT2NUM(384));
    rb_define_const(cNWScript, "SPELLABILITY_ROGUES_CUNNING", INT2NUM(385));
    rb_define_const(cNWScript, "SPELLABILITY_ACTIVATE_ITEM", INT2NUM(386));
    rb_define_const(cNWScript, "SPELLABILITY_DRAGON_FEAR", INT2NUM(412));
    rb_define_const(cNWScript, "SPELL_DIVINE_FAVOR", INT2NUM(414));
    rb_define_const(cNWScript, "SPELL_TRUE_STRIKE", INT2NUM(415));
    rb_define_const(cNWScript, "SPELL_FLARE", INT2NUM(416));
    rb_define_const(cNWScript, "SPELL_SHIELD", INT2NUM(417));
    rb_define_const(cNWScript, "SPELL_ENTROPIC_SHIELD", INT2NUM(418));
    rb_define_const(cNWScript, "SPELL_CONTINUAL_FLAME", INT2NUM(419));
    rb_define_const(cNWScript, "SPELL_ONE_WITH_THE_LAND", INT2NUM(420));
    rb_define_const(cNWScript, "SPELL_CAMOFLAGE", INT2NUM(421));
    rb_define_const(cNWScript, "SPELL_BLOOD_FRENZY", INT2NUM(422));
    rb_define_const(cNWScript, "SPELL_BOMBARDMENT", INT2NUM(423));
    rb_define_const(cNWScript, "SPELL_ACID_SPLASH", INT2NUM(424));
    rb_define_const(cNWScript, "SPELL_QUILLFIRE", INT2NUM(425));
    rb_define_const(cNWScript, "SPELL_EARTHQUAKE", INT2NUM(426));
    rb_define_const(cNWScript, "SPELL_SUNBURST", INT2NUM(427));
    rb_define_const(cNWScript, "SPELL_ACTIVATE_ITEM_SELF2", INT2NUM(428));
    rb_define_const(cNWScript, "SPELL_AURAOFGLORY", INT2NUM(429));
    rb_define_const(cNWScript, "SPELL_BANISHMENT", INT2NUM(430));
    rb_define_const(cNWScript, "SPELL_INFLICT_MINOR_WOUNDS", INT2NUM(431));
    rb_define_const(cNWScript, "SPELL_INFLICT_LIGHT_WOUNDS", INT2NUM(432));
    rb_define_const(cNWScript, "SPELL_INFLICT_MODERATE_WOUNDS", INT2NUM(433));
    rb_define_const(cNWScript, "SPELL_INFLICT_SERIOUS_WOUNDS", INT2NUM(434));
    rb_define_const(cNWScript, "SPELL_INFLICT_CRITICAL_WOUNDS", INT2NUM(435));
    rb_define_const(cNWScript, "SPELL_BALAGARNSIRONHORN", INT2NUM(436));
    rb_define_const(cNWScript, "SPELL_DROWN", INT2NUM(437));
    rb_define_const(cNWScript, "SPELL_OWLS_INSIGHT", INT2NUM(438));
    rb_define_const(cNWScript, "SPELL_ELECTRIC_JOLT", INT2NUM(439));
    rb_define_const(cNWScript, "SPELL_FIREBRAND", INT2NUM(440));
    rb_define_const(cNWScript, "SPELL_WOUNDING_WHISPERS", INT2NUM(441));
    rb_define_const(cNWScript, "SPELL_AMPLIFY", INT2NUM(442));
    rb_define_const(cNWScript, "SPELL_ETHEREALNESS", INT2NUM(443));
    rb_define_const(cNWScript, "SPELL_UNDEATHS_ETERNAL_FOE", INT2NUM(444));
    rb_define_const(cNWScript, "SPELL_DIRGE", INT2NUM(445));
    rb_define_const(cNWScript, "SPELL_INFERNO", INT2NUM(446));
    rb_define_const(cNWScript, "SPELL_ISAACS_LESSER_MISSILE_STORM", INT2NUM(447));
    rb_define_const(cNWScript, "SPELL_ISAACS_GREATER_MISSILE_STORM", INT2NUM(448));
    rb_define_const(cNWScript, "SPELL_BANE", INT2NUM(449));
    rb_define_const(cNWScript, "SPELL_SHIELD_OF_FAITH", INT2NUM(450));
    rb_define_const(cNWScript, "SPELL_PLANAR_ALLY", INT2NUM(451));
    rb_define_const(cNWScript, "SPELL_MAGIC_FANG", INT2NUM(452));
    rb_define_const(cNWScript, "SPELL_GREATER_MAGIC_FANG", INT2NUM(453));
    rb_define_const(cNWScript, "SPELL_SPIKE_GROWTH", INT2NUM(454));
    rb_define_const(cNWScript, "SPELL_MASS_CAMOFLAGE", INT2NUM(455));
    rb_define_const(cNWScript, "SPELL_EXPEDITIOUS_RETREAT", INT2NUM(456));
    rb_define_const(cNWScript, "SPELL_TASHAS_HIDEOUS_LAUGHTER", INT2NUM(457));
    rb_define_const(cNWScript, "SPELL_DISPLACEMENT", INT2NUM(458));
    rb_define_const(cNWScript, "SPELL_BIGBYS_INTERPOSING_HAND", INT2NUM(459));
    rb_define_const(cNWScript, "SPELL_BIGBYS_FORCEFUL_HAND", INT2NUM(460));
    rb_define_const(cNWScript, "SPELL_BIGBYS_GRASPING_HAND", INT2NUM(461));
    rb_define_const(cNWScript, "SPELL_BIGBYS_CLENCHED_FIST", INT2NUM(462));
    rb_define_const(cNWScript, "SPELL_BIGBYS_CRUSHING_HAND", INT2NUM(463));
    rb_define_const(cNWScript, "SPELL_GRENADE_FIRE", INT2NUM(464));
    rb_define_const(cNWScript, "SPELL_GRENADE_TANGLE", INT2NUM(465));
    rb_define_const(cNWScript, "SPELL_GRENADE_HOLY", INT2NUM(466));
    rb_define_const(cNWScript, "SPELL_GRENADE_CHOKING", INT2NUM(467));
    rb_define_const(cNWScript, "SPELL_GRENADE_THUNDERSTONE", INT2NUM(468));
    rb_define_const(cNWScript, "SPELL_GRENADE_ACID", INT2NUM(469));
    rb_define_const(cNWScript, "SPELL_GRENADE_CHICKEN", INT2NUM(470));
    rb_define_const(cNWScript, "SPELL_GRENADE_CALTROPS", INT2NUM(471));
    rb_define_const(cNWScript, "SPELL_ACTIVATE_ITEM_PORTAL", INT2NUM(472));
    rb_define_const(cNWScript, "SPELL_DIVINE_MIGHT", INT2NUM(473));
    rb_define_const(cNWScript, "SPELL_DIVINE_SHIELD", INT2NUM(474));
    rb_define_const(cNWScript, "SPELL_SHADOW_DAZE", INT2NUM(475));
    rb_define_const(cNWScript, "SPELL_SUMMON_SHADOW", INT2NUM(476));
    rb_define_const(cNWScript, "SPELL_SHADOW_EVADE", INT2NUM(477));
    rb_define_const(cNWScript, "SPELL_TYMORAS_SMILE", INT2NUM(478));
    rb_define_const(cNWScript, "SPELL_CRAFT_HARPER_ITEM", INT2NUM(479));
    rb_define_const(cNWScript, "SPELL_FLESH_TO_STONE", INT2NUM(485));
    rb_define_const(cNWScript, "SPELL_STONE_TO_FLESH", INT2NUM(486));
    rb_define_const(cNWScript, "SPELL_TRAP_ARROW", INT2NUM(487));
    rb_define_const(cNWScript, "SPELL_TRAP_BOLT", INT2NUM(488));
    rb_define_const(cNWScript, "SPELL_TRAP_DART", INT2NUM(493));
    rb_define_const(cNWScript, "SPELL_TRAP_SHURIKEN", INT2NUM(494));
    rb_define_const(cNWScript, "SPELLABILITY_BREATH_PETRIFY", INT2NUM(495));
    rb_define_const(cNWScript, "SPELLABILITY_TOUCH_PETRIFY", INT2NUM(496));
    rb_define_const(cNWScript, "SPELLABILITY_GAZE_PETRIFY", INT2NUM(497));
    rb_define_const(cNWScript, "SPELLABILITY_MANTICORE_SPIKES", INT2NUM(498));
    rb_define_const(cNWScript, "SPELL_ROD_OF_WONDER", INT2NUM(499));
    rb_define_const(cNWScript, "SPELL_DECK_OF_MANY_THINGS", INT2NUM(500));
    rb_define_const(cNWScript, "SPELL_ELEMENTAL_SUMMONING_ITEM", INT2NUM(502));
    rb_define_const(cNWScript, "SPELL_DECK_AVATAR", INT2NUM(503));
    rb_define_const(cNWScript, "SPELL_DECK_GEMSPRAY", INT2NUM(504));
    rb_define_const(cNWScript, "SPELL_DECK_BUTTERFLYSPRAY", INT2NUM(505));
    rb_define_const(cNWScript, "SPELL_HEALINGKIT", INT2NUM(506));
    rb_define_const(cNWScript, "SPELL_POWERSTONE", INT2NUM(507));
    rb_define_const(cNWScript, "SPELL_SPELLSTAFF", INT2NUM(508));
    rb_define_const(cNWScript, "SPELL_CHARGER", INT2NUM(500));
    rb_define_const(cNWScript, "SPELL_DECHARGER", INT2NUM(510));
    rb_define_const(cNWScript, "SPELL_KOBOLD_JUMP", INT2NUM(511));
    rb_define_const(cNWScript, "SPELL_CRUMBLE", INT2NUM(512));
    rb_define_const(cNWScript, "SPELL_INFESTATION_OF_MAGGOTS", INT2NUM(513));
    rb_define_const(cNWScript, "SPELL_HEALING_STING", INT2NUM(514));
    rb_define_const(cNWScript, "SPELL_GREAT_THUNDERCLAP", INT2NUM(515));
    rb_define_const(cNWScript, "SPELL_BALL_LIGHTNING", INT2NUM(516));
    rb_define_const(cNWScript, "SPELL_BATTLETIDE", INT2NUM(517));
    rb_define_const(cNWScript, "SPELL_COMBUST", INT2NUM(518));
    rb_define_const(cNWScript, "SPELL_DEATH_ARMOR", INT2NUM(519));
    rb_define_const(cNWScript, "SPELL_GEDLEES_ELECTRIC_LOOP", INT2NUM(520));
    rb_define_const(cNWScript, "SPELL_HORIZIKAULS_BOOM", INT2NUM(521));
    rb_define_const(cNWScript, "SPELL_IRONGUTS", INT2NUM(522));
    rb_define_const(cNWScript, "SPELL_MESTILS_ACID_BREATH", INT2NUM(523));
    rb_define_const(cNWScript, "SPELL_MESTILS_ACID_SHEATH", INT2NUM(524));
    rb_define_const(cNWScript, "SPELL_MONSTROUS_REGENERATION", INT2NUM(525));
    rb_define_const(cNWScript, "SPELL_SCINTILLATING_SPHERE", INT2NUM(526));
    rb_define_const(cNWScript, "SPELL_STONE_BONES", INT2NUM(527));
    rb_define_const(cNWScript, "SPELL_UNDEATH_TO_DEATH", INT2NUM(528));
    rb_define_const(cNWScript, "SPELL_VINE_MINE", INT2NUM(529));
    rb_define_const(cNWScript, "SPELL_VINE_MINE_ENTANGLE", INT2NUM(530));
    rb_define_const(cNWScript, "SPELL_VINE_MINE_HAMPER_MOVEMENT", INT2NUM(531));
    rb_define_const(cNWScript, "SPELL_VINE_MINE_CAMOUFLAGE", INT2NUM(532));
    rb_define_const(cNWScript, "SPELL_BLACK_BLADE_OF_DISASTER", INT2NUM(533));
    rb_define_const(cNWScript, "SPELL_SHELGARNS_PERSISTENT_BLADE", INT2NUM(534));
    rb_define_const(cNWScript, "SPELL_BLADE_THIRST", INT2NUM(535));
    rb_define_const(cNWScript, "SPELL_DEAFENING_CLANG", INT2NUM(536));
    rb_define_const(cNWScript, "SPELL_CLOUD_OF_BEWILDERMENT", INT2NUM(569));
    rb_define_const(cNWScript, "SPELL_KEEN_EDGE", INT2NUM(539));
    rb_define_const(cNWScript, "SPELL_BLACKSTAFF", INT2NUM(541));
    rb_define_const(cNWScript, "SPELL_FLAME_WEAPON", INT2NUM(542));
    rb_define_const(cNWScript, "SPELL_ICE_DAGGER", INT2NUM(543));
    rb_define_const(cNWScript, "SPELL_MAGIC_WEAPON", INT2NUM(544));
    rb_define_const(cNWScript, "SPELL_GREATER_MAGIC_WEAPON", INT2NUM(545));
    rb_define_const(cNWScript, "SPELL_STONEHOLD", INT2NUM(547));
    rb_define_const(cNWScript, "SPELL_DARKFIRE", INT2NUM(548));
    rb_define_const(cNWScript, "SPELL_GLYPH_OF_WARDING", INT2NUM(549));
    rb_define_const(cNWScript, "SPELLABILITY_MINDBLAST", INT2NUM(551));
    rb_define_const(cNWScript, "SPELLABILITY_CHARMMONSTER", INT2NUM(552));
    rb_define_const(cNWScript, "SPELL_IOUN_STONE_DUSTY_ROSE", INT2NUM(554));
    rb_define_const(cNWScript, "SPELL_IOUN_STONE_PALE_BLUE", INT2NUM(555));
    rb_define_const(cNWScript, "SPELL_IOUN_STONE_SCARLET_BLUE", INT2NUM(556));
    rb_define_const(cNWScript, "SPELL_IOUN_STONE_BLUE", INT2NUM(557));
    rb_define_const(cNWScript, "SPELL_IOUN_STONE_DEEP_RED", INT2NUM(558));
    rb_define_const(cNWScript, "SPELL_IOUN_STONE_PINK", INT2NUM(559));
    rb_define_const(cNWScript, "SPELL_IOUN_STONE_PINK_GREEN", INT2NUM(560));
    rb_define_const(cNWScript, "SPELLABILITY_WHIRLWIND", INT2NUM(561));
    rb_define_const(cNWScript, "SPELLABILITY_COMMAND_THE_HORDE", INT2NUM(571));
    rb_define_const(cNWScript, "SPELLABILITY_AA_IMBUE_ARROW", INT2NUM(600));
    rb_define_const(cNWScript, "SPELLABILITY_AA_SEEKER_ARROW_1", INT2NUM(601));
    rb_define_const(cNWScript, "SPELLABILITY_AA_SEEKER_ARROW_2", INT2NUM(602));
    rb_define_const(cNWScript, "SPELLABILITY_AA_HAIL_OF_ARROWS", INT2NUM(603));
    rb_define_const(cNWScript, "SPELLABILITY_AA_ARROW_OF_DEATH", INT2NUM(604));
    rb_define_const(cNWScript, "SPELLABILITY_AS_GHOSTLY_VISAGE", INT2NUM(605));
    rb_define_const(cNWScript, "SPELLABILITY_AS_DARKNESS", INT2NUM(606));
    rb_define_const(cNWScript, "SPELLABILITY_AS_INVISIBILITY", INT2NUM(607));
    rb_define_const(cNWScript, "SPELLABILITY_AS_IMPROVED_INVISIBLITY", INT2NUM(608));
    rb_define_const(cNWScript, "SPELLABILITY_BG_CREATEDEAD", INT2NUM(609));
    rb_define_const(cNWScript, "SPELLABILITY_BG_FIENDISH_SERVANT", INT2NUM(610));
    rb_define_const(cNWScript, "SPELLABILITY_BG_INFLICT_SERIOUS_WOUNDS", INT2NUM(611));
    rb_define_const(cNWScript, "SPELLABILITY_BG_INFLICT_CRITICAL_WOUNDS", INT2NUM(612));
    rb_define_const(cNWScript, "SPELLABILITY_BG_CONTAGION", INT2NUM(613));
    rb_define_const(cNWScript, "SPELLABILITY_BG_BULLS_STRENGTH", INT2NUM(614));
    rb_define_const(cNWScript, "SPELL_FLYING_DEBRIS", INT2NUM(620));
    rb_define_const(cNWScript, "SPELLABILITY_DC_DIVINE_WRATH", INT2NUM(622));
    rb_define_const(cNWScript, "SPELLABILITY_PM_ANIMATE_DEAD", INT2NUM(623));
    rb_define_const(cNWScript, "SPELLABILITY_PM_SUMMON_UNDEAD", INT2NUM(624));
    rb_define_const(cNWScript, "SPELLABILITY_PM_UNDEAD_GRAFT_1", INT2NUM(625));
    rb_define_const(cNWScript, "SPELLABILITY_PM_UNDEAD_GRAFT_2", INT2NUM(626));
    rb_define_const(cNWScript, "SPELLABILITY_PM_SUMMON_GREATER_UNDEAD", INT2NUM(627));
    rb_define_const(cNWScript, "SPELLABILITY_PM_DEATHLESS_MASTER_TOUCH", INT2NUM(628));
    rb_define_const(cNWScript, "SPELL_EPIC_HELLBALL", INT2NUM(636));
    rb_define_const(cNWScript, "SPELL_EPIC_MUMMY_DUST", INT2NUM(637));
    rb_define_const(cNWScript, "SPELL_EPIC_DRAGON_KNIGHT", INT2NUM(638));
    rb_define_const(cNWScript, "SPELL_EPIC_MAGE_ARMOR", INT2NUM(639));
    rb_define_const(cNWScript, "SPELL_EPIC_RUIN", INT2NUM(640));
    rb_define_const(cNWScript, "SPELLABILITY_DW_DEFENSIVE_STANCE", INT2NUM(641));
    rb_define_const(cNWScript, "SPELLABILITY_EPIC_MIGHTY_RAGE", INT2NUM(642));
    rb_define_const(cNWScript, "SPELLABILITY_EPIC_CURSE_SONG", INT2NUM(644));
    rb_define_const(cNWScript, "SPELLABILITY_EPIC_IMPROVED_WHIRLWIND", INT2NUM(645));
    rb_define_const(cNWScript, "SPELLABILITY_EPIC_SHAPE_DRAGONKIN", INT2NUM(646));
    rb_define_const(cNWScript, "SPELLABILITY_EPIC_SHAPE_DRAGON", INT2NUM(647));
    rb_define_const(cNWScript, "SPELL_CRAFT_DYE_CLOTHCOLOR_1", INT2NUM(648));
    rb_define_const(cNWScript, "SPELL_CRAFT_DYE_CLOTHCOLOR_2", INT2NUM(649));
    rb_define_const(cNWScript, "SPELL_CRAFT_DYE_LEATHERCOLOR_1", INT2NUM(650));
    rb_define_const(cNWScript, "SPELL_CRAFT_DYE_LEATHERCOLOR_2", INT2NUM(651));
    rb_define_const(cNWScript, "SPELL_CRAFT_DYE_METALCOLOR_1", INT2NUM(652));
    rb_define_const(cNWScript, "SPELL_CRAFT_DYE_METALCOLOR_2", INT2NUM(653));
    rb_define_const(cNWScript, "SPELL_CRAFT_ADD_ITEM_PROPERTY", INT2NUM(654));
    rb_define_const(cNWScript, "SPELL_CRAFT_POISON_WEAPON_OR_AMMO", INT2NUM(655));
    rb_define_const(cNWScript, "SPELL_CRAFT_CRAFT_WEAPON_SKILL", INT2NUM(656));
    rb_define_const(cNWScript, "SPELL_CRAFT_CRAFT_ARMOR_SKILL", INT2NUM(657));
    rb_define_const(cNWScript, "SPELLABILITY_DRAGON_BREATH_NEGATIVE", INT2NUM(698));
    rb_define_const(cNWScript, "SPELLABILITY_SEAHAG_EVILEYE", INT2NUM(803));
    rb_define_const(cNWScript, "SPELLABILITY_AURA_HORRIFICAPPEARANCE", INT2NUM(804));
    rb_define_const(cNWScript, "SPELLABILITY_TROGLODYTE_STENCH", INT2NUM(805));
    rb_define_const(cNWScript, "SPELL_HORSE_MENU", INT2NUM(812));
    rb_define_const(cNWScript, "SPELL_HORSE_MOUNT", INT2NUM(813));
    rb_define_const(cNWScript, "SPELL_HORSE_DISMOUNT", INT2NUM(814));
    rb_define_const(cNWScript, "SPELL_HORSE_PARTY_MOUNT", INT2NUM(815));
    rb_define_const(cNWScript, "SPELL_HORSE_PARTY_DISMOUNT", INT2NUM(816));
    rb_define_const(cNWScript, "SPELL_HORSE_ASSIGN_MOUNT", INT2NUM(817));
    rb_define_const(cNWScript, "SPELL_PALADIN_SUMMON_MOUNT", INT2NUM(818));
    rb_define_const(cNWScript, "POISON_NIGHTSHADE", INT2NUM(0));
    rb_define_const(cNWScript, "POISON_SMALL_CENTIPEDE_POISON", INT2NUM(1));
    rb_define_const(cNWScript, "POISON_BLADE_BANE", INT2NUM(2));
    rb_define_const(cNWScript, "POISON_GREENBLOOD_OIL", INT2NUM(3));
    rb_define_const(cNWScript, "POISON_BLOODROOT", INT2NUM(4));
    rb_define_const(cNWScript, "POISON_PURPLE_WORM_POISON", INT2NUM(5));
    rb_define_const(cNWScript, "POISON_LARGE_SCORPION_VENOM", INT2NUM(6));
    rb_define_const(cNWScript, "POISON_WYVERN_POISON", INT2NUM(7));
    rb_define_const(cNWScript, "POISON_BLUE_WHINNIS", INT2NUM(8));
    rb_define_const(cNWScript, "POISON_GIANT_WASP_POISON", INT2NUM(9));
    rb_define_const(cNWScript, "POISON_SHADOW_ESSENCE", INT2NUM(10));
    rb_define_const(cNWScript, "POISON_BLACK_ADDER_VENOM", INT2NUM(11));
    rb_define_const(cNWScript, "POISON_DEATHBLADE", INT2NUM(12));
    rb_define_const(cNWScript, "POISON_MALYSS_ROOT_PASTE", INT2NUM(13));
    rb_define_const(cNWScript, "POISON_NITHARIT", INT2NUM(14));
    rb_define_const(cNWScript, "POISON_DRAGON_BILE", INT2NUM(15));
    rb_define_const(cNWScript, "POISON_SASSONE_LEAF_RESIDUE", INT2NUM(16));
    rb_define_const(cNWScript, "POISON_TERINAV_ROOT", INT2NUM(17));
    rb_define_const(cNWScript, "POISON_CARRION_CRAWLER_BRAIN_JUICE", INT2NUM(18));
    rb_define_const(cNWScript, "POISON_BLACK_LOTUS_EXTRACT", INT2NUM(19));
    rb_define_const(cNWScript, "POISON_OIL_OF_TAGGIT", INT2NUM(20));
    rb_define_const(cNWScript, "POISON_ID_MOSS", INT2NUM(21));
    rb_define_const(cNWScript, "POISON_STRIPED_TOADSTOOL", INT2NUM(22));
    rb_define_const(cNWScript, "POISON_ARSENIC", INT2NUM(23));
    rb_define_const(cNWScript, "POISON_LICH_DUST", INT2NUM(24));
    rb_define_const(cNWScript, "POISON_DARK_REAVER_POWDER", INT2NUM(25));
    rb_define_const(cNWScript, "POISON_UNGOL_DUST", INT2NUM(26));
    rb_define_const(cNWScript, "POISON_BURNT_OTHUR_FUMES", INT2NUM(27));
    rb_define_const(cNWScript, "POISON_CHAOS_MIST", INT2NUM(28));
    rb_define_const(cNWScript, "POISON_BEBILITH_VENOM", INT2NUM(29));
    rb_define_const(cNWScript, "POISON_QUASIT_VENOM", INT2NUM(30));
    rb_define_const(cNWScript, "POISON_PIT_FIEND_ICHOR", INT2NUM(31));
    rb_define_const(cNWScript, "POISON_ETTERCAP_VENOM", INT2NUM(32));
    rb_define_const(cNWScript, "POISON_ARANEA_VENOM", INT2NUM(33));
    rb_define_const(cNWScript, "POISON_TINY_SPIDER_VENOM", INT2NUM(34));
    rb_define_const(cNWScript, "POISON_SMALL_SPIDER_VENOM", INT2NUM(35));
    rb_define_const(cNWScript, "POISON_MEDIUM_SPIDER_VENOM", INT2NUM(36));
    rb_define_const(cNWScript, "POISON_LARGE_SPIDER_VENOM", INT2NUM(37));
    rb_define_const(cNWScript, "POISON_HUGE_SPIDER_VENOM", INT2NUM(38));
    rb_define_const(cNWScript, "POISON_GARGANTUAN_SPIDER_VENOM", INT2NUM(39));
    rb_define_const(cNWScript, "POISON_COLOSSAL_SPIDER_VENOM", INT2NUM(40));
    rb_define_const(cNWScript, "POISON_PHASE_SPIDER_VENOM", INT2NUM(41));
    rb_define_const(cNWScript, "POISON_WRAITH_SPIDER_VENOM", INT2NUM(42));
    rb_define_const(cNWScript, "POISON_IRON_GOLEM", INT2NUM(43));
    rb_define_const(cNWScript, "DISEASE_BLINDING_SICKNESS", INT2NUM(0));
    rb_define_const(cNWScript, "DISEASE_CACKLE_FEVER", INT2NUM(1));
    rb_define_const(cNWScript, "DISEASE_DEVIL_CHILLS", INT2NUM(2));
    rb_define_const(cNWScript, "DISEASE_DEMON_FEVER", INT2NUM(3));
    rb_define_const(cNWScript, "DISEASE_FILTH_FEVER", INT2NUM(4));
    rb_define_const(cNWScript, "DISEASE_MINDFIRE", INT2NUM(5));
    rb_define_const(cNWScript, "DISEASE_MUMMY_ROT", INT2NUM(6));
    rb_define_const(cNWScript, "DISEASE_RED_ACHE", INT2NUM(7));
    rb_define_const(cNWScript, "DISEASE_SHAKES", INT2NUM(8));
    rb_define_const(cNWScript, "DISEASE_SLIMY_DOOM", INT2NUM(9));
    rb_define_const(cNWScript, "DISEASE_RED_SLAAD_EGGS", INT2NUM(10));
    rb_define_const(cNWScript, "DISEASE_GHOUL_ROT", INT2NUM(11));
    rb_define_const(cNWScript, "DISEASE_ZOMBIE_CREEP", INT2NUM(12));
    rb_define_const(cNWScript, "DISEASE_DREAD_BLISTERS", INT2NUM(13));
    rb_define_const(cNWScript, "DISEASE_BURROW_MAGGOTS", INT2NUM(14));
    rb_define_const(cNWScript, "DISEASE_SOLDIER_SHAKES", INT2NUM(15));
    rb_define_const(cNWScript, "DISEASE_VERMIN_MADNESS", INT2NUM(16));
    rb_define_const(cNWScript, "CREATURE_TYPE_RACIAL_TYPE", INT2NUM(0));
    rb_define_const(cNWScript, "CREATURE_TYPE_PLAYER_CHAR", INT2NUM(1));
    rb_define_const(cNWScript, "CREATURE_TYPE_CLASS", INT2NUM(2));
    rb_define_const(cNWScript, "CREATURE_TYPE_REPUTATION", INT2NUM(3));
    rb_define_const(cNWScript, "CREATURE_TYPE_IS_ALIVE", INT2NUM(4));
    rb_define_const(cNWScript, "CREATURE_TYPE_HAS_SPELL_EFFECT", INT2NUM(5));
    rb_define_const(cNWScript, "CREATURE_TYPE_DOES_NOT_HAVE_SPELL_EFFECT", INT2NUM(6));
    rb_define_const(cNWScript, "CREATURE_TYPE_PERCEPTION", INT2NUM(7));
    rb_define_const(cNWScript, "REPUTATION_TYPE_FRIEND", INT2NUM(0));
    rb_define_const(cNWScript, "REPUTATION_TYPE_ENEMY", INT2NUM(1));
    rb_define_const(cNWScript, "REPUTATION_TYPE_NEUTRAL", INT2NUM(2));
    rb_define_const(cNWScript, "PERCEPTION_SEEN_AND_HEARD", INT2NUM(0));
    rb_define_const(cNWScript, "PERCEPTION_NOT_SEEN_AND_NOT_HEARD", INT2NUM(1));
    rb_define_const(cNWScript, "PERCEPTION_HEARD_AND_NOT_SEEN", INT2NUM(2));
    rb_define_const(cNWScript, "PERCEPTION_SEEN_AND_NOT_HEARD", INT2NUM(3));
    rb_define_const(cNWScript, "PERCEPTION_NOT_HEARD", INT2NUM(4));
    rb_define_const(cNWScript, "PERCEPTION_HEARD", INT2NUM(5));
    rb_define_const(cNWScript, "PERCEPTION_NOT_SEEN", INT2NUM(6));
    rb_define_const(cNWScript, "PERCEPTION_SEEN", INT2NUM(7));
    rb_define_const(cNWScript, "PLAYER_CHAR_NOT_PC", INT2NUM(FALSE));
    rb_define_const(cNWScript, "PLAYER_CHAR_IS_PC", INT2NUM(TRUE));
    rb_define_const(cNWScript, "CLASS_TYPE_BARBARIAN", INT2NUM(0));
    rb_define_const(cNWScript, "CLASS_TYPE_BARD", INT2NUM(1));
    rb_define_const(cNWScript, "CLASS_TYPE_CLERIC", INT2NUM(2));
    rb_define_const(cNWScript, "CLASS_TYPE_DRUID", INT2NUM(3));
    rb_define_const(cNWScript, "CLASS_TYPE_FIGHTER", INT2NUM(4));
    rb_define_const(cNWScript, "CLASS_TYPE_MONK", INT2NUM(5));
    rb_define_const(cNWScript, "CLASS_TYPE_PALADIN", INT2NUM(6));
    rb_define_const(cNWScript, "CLASS_TYPE_RANGER", INT2NUM(7));
    rb_define_const(cNWScript, "CLASS_TYPE_ROGUE", INT2NUM(8));
    rb_define_const(cNWScript, "CLASS_TYPE_SORCERER", INT2NUM(9));
    rb_define_const(cNWScript, "CLASS_TYPE_WIZARD", INT2NUM(10));
    rb_define_const(cNWScript, "CLASS_TYPE_ABERRATION", INT2NUM(11));
    rb_define_const(cNWScript, "CLASS_TYPE_ANIMAL", INT2NUM(12));
    rb_define_const(cNWScript, "CLASS_TYPE_CONSTRUCT", INT2NUM(13));
    rb_define_const(cNWScript, "CLASS_TYPE_HUMANOID", INT2NUM(14));
    rb_define_const(cNWScript, "CLASS_TYPE_MONSTROUS", INT2NUM(15));
    rb_define_const(cNWScript, "CLASS_TYPE_ELEMENTAL", INT2NUM(16));
    rb_define_const(cNWScript, "CLASS_TYPE_FEY", INT2NUM(17));
    rb_define_const(cNWScript, "CLASS_TYPE_DRAGON", INT2NUM(18));
    rb_define_const(cNWScript, "CLASS_TYPE_UNDEAD", INT2NUM(19));
    rb_define_const(cNWScript, "CLASS_TYPE_COMMONER", INT2NUM(20));
    rb_define_const(cNWScript, "CLASS_TYPE_BEAST", INT2NUM(21));
    rb_define_const(cNWScript, "CLASS_TYPE_GIANT", INT2NUM(22));
    rb_define_const(cNWScript, "CLASS_TYPE_MAGICAL_BEAST", INT2NUM(23));
    rb_define_const(cNWScript, "CLASS_TYPE_OUTSIDER", INT2NUM(24));
    rb_define_const(cNWScript, "CLASS_TYPE_SHAPECHANGER", INT2NUM(25));
    rb_define_const(cNWScript, "CLASS_TYPE_VERMIN", INT2NUM(26));
    rb_define_const(cNWScript, "CLASS_TYPE_SHADOWDANCER", INT2NUM(27));
    rb_define_const(cNWScript, "CLASS_TYPE_HARPER", INT2NUM(28));
    rb_define_const(cNWScript, "CLASS_TYPE_ARCANE_ARCHER", INT2NUM(29));
    rb_define_const(cNWScript, "CLASS_TYPE_ASSASSIN", INT2NUM(30));
    rb_define_const(cNWScript, "CLASS_TYPE_BLACKGUARD", INT2NUM(31));
    rb_define_const(cNWScript, "CLASS_TYPE_DIVINECHAMPION", INT2NUM(32));
    rb_define_const(cNWScript, "CLASS_TYPE_DIVINE_CHAMPION", INT2NUM(32));
    rb_define_const(cNWScript, "CLASS_TYPE_WEAPON_MASTER", INT2NUM(33));
    rb_define_const(cNWScript, "CLASS_TYPE_PALEMASTER", INT2NUM(34));
    rb_define_const(cNWScript, "CLASS_TYPE_PALE_MASTER", INT2NUM(34));
    rb_define_const(cNWScript, "CLASS_TYPE_SHIFTER", INT2NUM(35));
    rb_define_const(cNWScript, "CLASS_TYPE_DWARVENDEFENDER", INT2NUM(36));
    rb_define_const(cNWScript, "CLASS_TYPE_DWARVEN_DEFENDER", INT2NUM(36));
    rb_define_const(cNWScript, "CLASS_TYPE_DRAGONDISCIPLE", INT2NUM(37));
    rb_define_const(cNWScript, "CLASS_TYPE_DRAGON_DISCIPLE", INT2NUM(37));
    rb_define_const(cNWScript, "CLASS_TYPE_OOZE", INT2NUM(38));
    rb_define_const(cNWScript, "CLASS_TYPE_EYE_OF_GRUUMSH", INT2NUM(39));
    rb_define_const(cNWScript, "CLASS_TYPE_SHOU_DISCIPLE", INT2NUM(40));
    rb_define_const(cNWScript, "CLASS_TYPE_PURPLE_DRAGON_KNIGHT", INT2NUM(41));
    rb_define_const(cNWScript, "CLASS_TYPE_INVALID", INT2NUM(255));
    rb_define_const(cNWScript, "PACKAGE_BARBARIAN", INT2NUM(0));
    rb_define_const(cNWScript, "PACKAGE_BARD", INT2NUM(1));
    rb_define_const(cNWScript, "PACKAGE_CLERIC", INT2NUM(2));
    rb_define_const(cNWScript, "PACKAGE_DRUID", INT2NUM(3));
    rb_define_const(cNWScript, "PACKAGE_FIGHTER", INT2NUM(4));
    rb_define_const(cNWScript, "PACKAGE_MONK", INT2NUM(5));
    rb_define_const(cNWScript, "PACKAGE_PALADIN", INT2NUM(6));
    rb_define_const(cNWScript, "PACKAGE_RANGER", INT2NUM(7));
    rb_define_const(cNWScript, "PACKAGE_ROGUE", INT2NUM(8));
    rb_define_const(cNWScript, "PACKAGE_SORCERER", INT2NUM(9));
    rb_define_const(cNWScript, "PACKAGE_WIZARDGENERALIST", INT2NUM(10));
    rb_define_const(cNWScript, "PACKAGE_DRUID_INTERLOPER", INT2NUM(11));
    rb_define_const(cNWScript, "PACKAGE_DRUID_GRAY", INT2NUM(12));
    rb_define_const(cNWScript, "PACKAGE_DRUID_DEATH", INT2NUM(13));
    rb_define_const(cNWScript, "PACKAGE_DRUID_HAWKMASTER", INT2NUM(14));
    rb_define_const(cNWScript, "PACKAGE_BARBARIAN_BRUTE", INT2NUM(15));
    rb_define_const(cNWScript, "PACKAGE_BARBARIAN_SLAYER", INT2NUM(16));
    rb_define_const(cNWScript, "PACKAGE_BARBARIAN_SAVAGE", INT2NUM(17));
    rb_define_const(cNWScript, "PACKAGE_BARBARIAN_ORCBLOOD", INT2NUM(18));
    rb_define_const(cNWScript, "PACKAGE_CLERIC_SHAMAN", INT2NUM(19));
    rb_define_const(cNWScript, "PACKAGE_CLERIC_DEADWALKER", INT2NUM(20));
    rb_define_const(cNWScript, "PACKAGE_CLERIC_ELEMENTALIST", INT2NUM(21));
    rb_define_const(cNWScript, "PACKAGE_CLERIC_BATTLE_PRIEST", INT2NUM(22));
    rb_define_const(cNWScript, "PACKAGE_FIGHTER_FINESSE", INT2NUM(23));
    rb_define_const(cNWScript, "PACKAGE_FIGHTER_PIRATE", INT2NUM(24));
    rb_define_const(cNWScript, "PACKAGE_FIGHTER_GLADIATOR", INT2NUM(25));
    rb_define_const(cNWScript, "PACKAGE_FIGHTER_COMMANDER", INT2NUM(26));
    rb_define_const(cNWScript, "PACKAGE_WIZARD_ABJURATION", INT2NUM(27));
    rb_define_const(cNWScript, "PACKAGE_WIZARD_CONJURATION", INT2NUM(28));
    rb_define_const(cNWScript, "PACKAGE_WIZARD_DIVINATION", INT2NUM(29));
    rb_define_const(cNWScript, "PACKAGE_WIZARD_ENCHANTMENT", INT2NUM(30));
    rb_define_const(cNWScript, "PACKAGE_WIZARD_EVOCATION", INT2NUM(31));
    rb_define_const(cNWScript, "PACKAGE_WIZARD_ILLUSION", INT2NUM(32));
    rb_define_const(cNWScript, "PACKAGE_WIZARD_NECROMANCY", INT2NUM(33));
    rb_define_const(cNWScript, "PACKAGE_WIZARD_TRANSMUTATION", INT2NUM(34));
    rb_define_const(cNWScript, "PACKAGE_SORCERER_ABJURATION", INT2NUM(35));
    rb_define_const(cNWScript, "PACKAGE_SORCERER_CONJURATION", INT2NUM(36));
    rb_define_const(cNWScript, "PACKAGE_SORCERER_DIVINATION", INT2NUM(37));
    rb_define_const(cNWScript, "PACKAGE_SORCERER_ENCHANTMENT", INT2NUM(38));
    rb_define_const(cNWScript, "PACKAGE_SORCERER_EVOCATION", INT2NUM(39));
    rb_define_const(cNWScript, "PACKAGE_SORCERER_ILLUSION", INT2NUM(40));
    rb_define_const(cNWScript, "PACKAGE_SORCERER_NECROMANCY", INT2NUM(41));
    rb_define_const(cNWScript, "PACKAGE_SORCERER_TRANSMUTATION", INT2NUM(42));
    rb_define_const(cNWScript, "PACKAGE_BARD_BLADE", INT2NUM(43));
    rb_define_const(cNWScript, "PACKAGE_BARD_GALLANT", INT2NUM(44));
    rb_define_const(cNWScript, "PACKAGE_BARD_JESTER", INT2NUM(45));
    rb_define_const(cNWScript, "PACKAGE_BARD_LOREMASTER", INT2NUM(46));
    rb_define_const(cNWScript, "PACKAGE_MONK_SPIRIT", INT2NUM(47));
    rb_define_const(cNWScript, "PACKAGE_MONK_GIFTED", INT2NUM(48));
    rb_define_const(cNWScript, "PACKAGE_MONK_DEVOUT", INT2NUM(49));
    rb_define_const(cNWScript, "PACKAGE_MONK_PEASANT", INT2NUM(50));
    rb_define_const(cNWScript, "PACKAGE_PALADIN_ERRANT", INT2NUM(51));
    rb_define_const(cNWScript, "PACKAGE_PALADIN_UNDEAD", INT2NUM(52));
    rb_define_const(cNWScript, "PACKAGE_PALADIN_INQUISITOR", INT2NUM(53));
    rb_define_const(cNWScript, "PACKAGE_PALADIN_CHAMPION", INT2NUM(54));
    rb_define_const(cNWScript, "PACKAGE_RANGER_MARKSMAN", INT2NUM(55));
    rb_define_const(cNWScript, "PACKAGE_RANGER_WARDEN", INT2NUM(56));
    rb_define_const(cNWScript, "PACKAGE_RANGER_STALKER", INT2NUM(57));
    rb_define_const(cNWScript, "PACKAGE_RANGER_GIANTKILLER", INT2NUM(58));
    rb_define_const(cNWScript, "PACKAGE_ROGUE_GYPSY", INT2NUM(59));
    rb_define_const(cNWScript, "PACKAGE_ROGUE_BANDIT", INT2NUM(60));
    rb_define_const(cNWScript, "PACKAGE_ROGUE_SCOUT", INT2NUM(61));
    rb_define_const(cNWScript, "PACKAGE_ROGUE_SWASHBUCKLER", INT2NUM(62));
    rb_define_const(cNWScript, "PACKAGE_SHADOWDANCER", INT2NUM(63));
    rb_define_const(cNWScript, "PACKAGE_HARPER", INT2NUM(64));
    rb_define_const(cNWScript, "PACKAGE_ARCANE_ARCHER", INT2NUM(65));
    rb_define_const(cNWScript, "PACKAGE_ASSASSIN", INT2NUM(66));
    rb_define_const(cNWScript, "PACKAGE_BLACKGUARD", INT2NUM(67));
    rb_define_const(cNWScript, "PACKAGE_NPC_SORCERER", INT2NUM(70));
    rb_define_const(cNWScript, "PACKAGE_NPC_ROGUE", INT2NUM(71));
    rb_define_const(cNWScript, "PACKAGE_NPC_BARD", INT2NUM(72));
    rb_define_const(cNWScript, "PACKAGE_ABERRATION", INT2NUM(73));
    rb_define_const(cNWScript, "PACKAGE_ANIMAL", INT2NUM(74));
    rb_define_const(cNWScript, "PACKAGE_CONSTRUCT", INT2NUM(75));
    rb_define_const(cNWScript, "PACKAGE_HUMANOID", INT2NUM(76));
    rb_define_const(cNWScript, "PACKAGE_MONSTROUS", INT2NUM(77));
    rb_define_const(cNWScript, "PACKAGE_ELEMENTAL", INT2NUM(78));
    rb_define_const(cNWScript, "PACKAGE_FEY", INT2NUM(79));
    rb_define_const(cNWScript, "PACKAGE_DRAGON", INT2NUM(80));
    rb_define_const(cNWScript, "PACKAGE_UNDEAD", INT2NUM(81));
    rb_define_const(cNWScript, "PACKAGE_COMMONER", INT2NUM(82));
    rb_define_const(cNWScript, "PACKAGE_BEAST", INT2NUM(83));
    rb_define_const(cNWScript, "PACKAGE_GIANT", INT2NUM(84));
    rb_define_const(cNWScript, "PACKAGE_MAGICBEAST", INT2NUM(85));
    rb_define_const(cNWScript, "PACKAGE_OUTSIDER", INT2NUM(86));
    rb_define_const(cNWScript, "PACKAGE_SHAPECHANGER", INT2NUM(87));
    rb_define_const(cNWScript, "PACKAGE_VERMIN", INT2NUM(88));
    rb_define_const(cNWScript, "PACKAGE_DWARVEN_DEFENDER", INT2NUM(89));
    rb_define_const(cNWScript, "PACKAGE_BARBARIAN_BLACKGUARD", INT2NUM(90));
    rb_define_const(cNWScript, "PACKAGE_BARD_HARPER", INT2NUM(91));
    rb_define_const(cNWScript, "PACKAGE_CLERIC_DIVINE", INT2NUM(92));
    rb_define_const(cNWScript, "PACKAGE_DRUID_SHIFTER", INT2NUM(93));
    rb_define_const(cNWScript, "PACKAGE_FIGHTER_WEAPONMASTER", INT2NUM(94));
    rb_define_const(cNWScript, "PACKAGE_MONK_ASSASSIN", INT2NUM(95));
    rb_define_const(cNWScript, "PACKAGE_PALADIN_DIVINE", INT2NUM(96));
    rb_define_const(cNWScript, "PACKAGE_RANGER_ARCANEARCHER", INT2NUM(97));
    rb_define_const(cNWScript, "PACKAGE_ROGUE_SHADOWDANCER", INT2NUM(98));
    rb_define_const(cNWScript, "PACKAGE_SORCERER_DRAGONDISCIPLE", INT2NUM(99));
    rb_define_const(cNWScript, "PACKAGE_WIZARD_PALEMASTER", INT2NUM(100));
    rb_define_const(cNWScript, "PACKAGE_NPC_WIZASSASSIN", INT2NUM(101));
    rb_define_const(cNWScript, "PACKAGE_NPC_FT_WEAPONMASTER", INT2NUM(102));
    rb_define_const(cNWScript, "PACKAGE_NPC_RG_SHADOWDANCER", INT2NUM(103));
    rb_define_const(cNWScript, "PACKAGE_NPC_CLERIC_LINU", INT2NUM(104));
    rb_define_const(cNWScript, "PACKAGE_NPC_BARBARIAN_DAELAN", INT2NUM(105));
    rb_define_const(cNWScript, "PACKAGE_NPC_BARD_FIGHTER", INT2NUM(106));
    rb_define_const(cNWScript, "PACKAGE_NPC_PALADIN_FALLING", INT2NUM(107));
    rb_define_const(cNWScript, "PACKAGE_SHIFTER", INT2NUM(108));
    rb_define_const(cNWScript, "PACKAGE_DIVINE_CHAMPION", INT2NUM(109));
    rb_define_const(cNWScript, "PACKAGE_PALE_MASTER", INT2NUM(110));
    rb_define_const(cNWScript, "PACKAGE_DRAGON_DISCIPLE", INT2NUM(111));
    rb_define_const(cNWScript, "PACKAGE_WEAPONMASTER", INT2NUM(112));
    rb_define_const(cNWScript, "PACKAGE_NPC_FT_WEAPONMASTER_VALEN_2", INT2NUM(113));
    rb_define_const(cNWScript, "PACKAGE_NPC_BARD_FIGHTER_SHARWYN2", INT2NUM(114));
    rb_define_const(cNWScript, "PACKAGE_NPC_WIZASSASSIN_NATHYRRA", INT2NUM(115));
    rb_define_const(cNWScript, "PACKAGE_NPC_RG_TOMI_2", INT2NUM(116));
    rb_define_const(cNWScript, "PACKAGE_NPC_BARD_DEEKIN_2", INT2NUM(117));
    rb_define_const(cNWScript, "PACKAGE_BARBARIAN_BLACKGUARD_2NDCLASS", INT2NUM(118));
    rb_define_const(cNWScript, "PACKAGE_BARD_HARPER_2NDCLASS", INT2NUM(119));
    rb_define_const(cNWScript, "PACKAGE_CLERIC_DIVINE_2NDCLASS", INT2NUM(120));
    rb_define_const(cNWScript, "PACKAGE_DRUID_SHIFTER_2NDCLASS", INT2NUM(121));
    rb_define_const(cNWScript, "PACKAGE_FIGHTER_WEAPONMASTER_2NDCLASS", INT2NUM(122));
    rb_define_const(cNWScript, "PACKAGE_MONK_ASSASSIN_2NDCLASS", INT2NUM(123));
    rb_define_const(cNWScript, "PACKAGE_PALADIN_DIVINE_2NDCLASS", INT2NUM(124));
    rb_define_const(cNWScript, "PACKAGE_RANGER_ARCANEARCHER_2NDCLASS", INT2NUM(125));
    rb_define_const(cNWScript, "PACKAGE_ROGUE_SHADOWDANCER_2NDCLASS", INT2NUM(126));
    rb_define_const(cNWScript, "PACKAGE_SORCERER_DRAGONDISCIPLE_2NDCLASS", INT2NUM(127));
    rb_define_const(cNWScript, "PACKAGE_WIZARD_PALEMASTER_2NDCLASS", INT2NUM(128));
    rb_define_const(cNWScript, "PACKAGE_NPC_ARIBETH_PALADIN", INT2NUM(129));
    rb_define_const(cNWScript, "PACKAGE_NPC_ARIBETH_BLACKGUARD", INT2NUM(130));
    rb_define_const(cNWScript, "PACKAGE_INVALID", INT2NUM(255));
    rb_define_const(cNWScript, "PERSISTENT_ZONE_ACTIVE", INT2NUM(0));
    rb_define_const(cNWScript, "PERSISTENT_ZONE_FOLLOW", INT2NUM(1));
    rb_define_const(cNWScript, "STANDARD_FACTION_HOSTILE", INT2NUM(0));
    rb_define_const(cNWScript, "STANDARD_FACTION_COMMONER", INT2NUM(1));
    rb_define_const(cNWScript, "STANDARD_FACTION_MERCHANT", INT2NUM(2));
    rb_define_const(cNWScript, "STANDARD_FACTION_DEFENDER", INT2NUM(3));
    rb_define_const(cNWScript, "SKILL_ANIMAL_EMPATHY", INT2NUM(0));
    rb_define_const(cNWScript, "SKILL_CONCENTRATION", INT2NUM(1));
    rb_define_const(cNWScript, "SKILL_DISABLE_TRAP", INT2NUM(2));
    rb_define_const(cNWScript, "SKILL_DISCIPLINE", INT2NUM(3));
    rb_define_const(cNWScript, "SKILL_HEAL", INT2NUM(4));
    rb_define_const(cNWScript, "SKILL_HIDE", INT2NUM(5));
    rb_define_const(cNWScript, "SKILL_LISTEN", INT2NUM(6));
    rb_define_const(cNWScript, "SKILL_LORE", INT2NUM(7));
    rb_define_const(cNWScript, "SKILL_MOVE_SILENTLY", INT2NUM(8));
    rb_define_const(cNWScript, "SKILL_OPEN_LOCK", INT2NUM(9));
    rb_define_const(cNWScript, "SKILL_PARRY", INT2NUM(10));
    rb_define_const(cNWScript, "SKILL_PERFORM", INT2NUM(11));
    rb_define_const(cNWScript, "SKILL_PERSUADE", INT2NUM(12));
    rb_define_const(cNWScript, "SKILL_PICK_POCKET", INT2NUM(13));
    rb_define_const(cNWScript, "SKILL_SEARCH", INT2NUM(14));
    rb_define_const(cNWScript, "SKILL_SET_TRAP", INT2NUM(15));
    rb_define_const(cNWScript, "SKILL_SPELLCRAFT", INT2NUM(16));
    rb_define_const(cNWScript, "SKILL_SPOT", INT2NUM(17));
    rb_define_const(cNWScript, "SKILL_TAUNT", INT2NUM(18));
    rb_define_const(cNWScript, "SKILL_USE_MAGIC_DEVICE", INT2NUM(19));
    rb_define_const(cNWScript, "SKILL_APPRAISE", INT2NUM(20));
    rb_define_const(cNWScript, "SKILL_TUMBLE", INT2NUM(21));
    rb_define_const(cNWScript, "SKILL_CRAFT_TRAP", INT2NUM(22));
    rb_define_const(cNWScript, "SKILL_BLUFF", INT2NUM(23));
    rb_define_const(cNWScript, "SKILL_INTIMIDATE", INT2NUM(24));
    rb_define_const(cNWScript, "SKILL_CRAFT_ARMOR", INT2NUM(25));
    rb_define_const(cNWScript, "SKILL_CRAFT_WEAPON", INT2NUM(26));
    rb_define_const(cNWScript, "SKILL_RIDE", INT2NUM(27));
    rb_define_const(cNWScript, "SKILL_ALL_SKILLS", INT2NUM(255));
    rb_define_const(cNWScript, "SUBSKILL_FLAGTRAP", INT2NUM(100));
    rb_define_const(cNWScript, "SUBSKILL_RECOVERTRAP", INT2NUM(101));
    rb_define_const(cNWScript, "SUBSKILL_EXAMINETRAP", INT2NUM(102));
    rb_define_const(cNWScript, "FEAT_ALERTNESS", INT2NUM(0));
    rb_define_const(cNWScript, "FEAT_AMBIDEXTERITY", INT2NUM(1));
    rb_define_const(cNWScript, "FEAT_ARMOR_PROFICIENCY_HEAVY", INT2NUM(2));
    rb_define_const(cNWScript, "FEAT_ARMOR_PROFICIENCY_LIGHT", INT2NUM(3));
    rb_define_const(cNWScript, "FEAT_ARMOR_PROFICIENCY_MEDIUM", INT2NUM(4));
    rb_define_const(cNWScript, "FEAT_CALLED_SHOT", INT2NUM(5));
    rb_define_const(cNWScript, "FEAT_CLEAVE", INT2NUM(6));
    rb_define_const(cNWScript, "FEAT_COMBAT_CASTING", INT2NUM(7));
    rb_define_const(cNWScript, "FEAT_DEFLECT_ARROWS", INT2NUM(8));
    rb_define_const(cNWScript, "FEAT_DISARM", INT2NUM(9));
    rb_define_const(cNWScript, "FEAT_DODGE", INT2NUM(10));
    rb_define_const(cNWScript, "FEAT_EMPOWER_SPELL", INT2NUM(11));
    rb_define_const(cNWScript, "FEAT_EXTEND_SPELL", INT2NUM(12));
    rb_define_const(cNWScript, "FEAT_EXTRA_TURNING", INT2NUM(13));
    rb_define_const(cNWScript, "FEAT_GREAT_FORTITUDE", INT2NUM(14));
    rb_define_const(cNWScript, "FEAT_IMPROVED_CRITICAL_CLUB", INT2NUM(15));
    rb_define_const(cNWScript, "FEAT_IMPROVED_DISARM", INT2NUM(16));
    rb_define_const(cNWScript, "FEAT_IMPROVED_KNOCKDOWN", INT2NUM(17));
    rb_define_const(cNWScript, "FEAT_IMPROVED_PARRY", INT2NUM(18));
    rb_define_const(cNWScript, "FEAT_IMPROVED_POWER_ATTACK", INT2NUM(19));
    rb_define_const(cNWScript, "FEAT_IMPROVED_TWO_WEAPON_FIGHTING", INT2NUM(20));
    rb_define_const(cNWScript, "FEAT_IMPROVED_UNARMED_STRIKE", INT2NUM(21));
    rb_define_const(cNWScript, "FEAT_IRON_WILL", INT2NUM(22));
    rb_define_const(cNWScript, "FEAT_KNOCKDOWN", INT2NUM(23));
    rb_define_const(cNWScript, "FEAT_LIGHTNING_REFLEXES", INT2NUM(24));
    rb_define_const(cNWScript, "FEAT_MAXIMIZE_SPELL", INT2NUM(25));
    rb_define_const(cNWScript, "FEAT_MOBILITY", INT2NUM(26));
    rb_define_const(cNWScript, "FEAT_POINT_BLANK_SHOT", INT2NUM(27));
    rb_define_const(cNWScript, "FEAT_POWER_ATTACK", INT2NUM(28));
    rb_define_const(cNWScript, "FEAT_QUICKEN_SPELL", INT2NUM(29));
    rb_define_const(cNWScript, "FEAT_RAPID_SHOT", INT2NUM(30));
    rb_define_const(cNWScript, "FEAT_SAP", INT2NUM(31));
    rb_define_const(cNWScript, "FEAT_SHIELD_PROFICIENCY", INT2NUM(32));
    rb_define_const(cNWScript, "FEAT_SILENCE_SPELL", INT2NUM(33));
    rb_define_const(cNWScript, "FEAT_SKILL_FOCUS_ANIMAL_EMPATHY", INT2NUM(34));
    rb_define_const(cNWScript, "FEAT_SPELL_FOCUS_ABJURATION", INT2NUM(35));
    rb_define_const(cNWScript, "FEAT_SPELL_PENETRATION", INT2NUM(36));
    rb_define_const(cNWScript, "FEAT_STILL_SPELL", INT2NUM(37));
    rb_define_const(cNWScript, "FEAT_STUNNING_FIST", INT2NUM(39));
    rb_define_const(cNWScript, "FEAT_TOUGHNESS", INT2NUM(40));
    rb_define_const(cNWScript, "FEAT_TWO_WEAPON_FIGHTING", INT2NUM(41));
    rb_define_const(cNWScript, "FEAT_WEAPON_FINESSE", INT2NUM(42));
    rb_define_const(cNWScript, "FEAT_WEAPON_FOCUS_CLUB", INT2NUM(43));
    rb_define_const(cNWScript, "FEAT_WEAPON_PROFICIENCY_EXOTIC", INT2NUM(44));
    rb_define_const(cNWScript, "FEAT_WEAPON_PROFICIENCY_MARTIAL", INT2NUM(45));
    rb_define_const(cNWScript, "FEAT_WEAPON_PROFICIENCY_SIMPLE", INT2NUM(46));
    rb_define_const(cNWScript, "FEAT_WEAPON_SPECIALIZATION_CLUB", INT2NUM(47));
    rb_define_const(cNWScript, "FEAT_WEAPON_PROFICIENCY_DRUID", INT2NUM(48));
    rb_define_const(cNWScript, "FEAT_WEAPON_PROFICIENCY_MONK", INT2NUM(49));
    rb_define_const(cNWScript, "FEAT_WEAPON_PROFICIENCY_ROGUE", INT2NUM(50));
    rb_define_const(cNWScript, "FEAT_WEAPON_PROFICIENCY_WIZARD", INT2NUM(51));
    rb_define_const(cNWScript, "FEAT_IMPROVED_CRITICAL_DAGGER", INT2NUM(52));
    rb_define_const(cNWScript, "FEAT_IMPROVED_CRITICAL_DART", INT2NUM(53));
    rb_define_const(cNWScript, "FEAT_IMPROVED_CRITICAL_HEAVY_CROSSBOW", INT2NUM(54));
    rb_define_const(cNWScript, "FEAT_IMPROVED_CRITICAL_LIGHT_CROSSBOW", INT2NUM(55));
    rb_define_const(cNWScript, "FEAT_IMPROVED_CRITICAL_LIGHT_MACE", INT2NUM(56));
    rb_define_const(cNWScript, "FEAT_IMPROVED_CRITICAL_MORNING_STAR", INT2NUM(57));
    rb_define_const(cNWScript, "FEAT_IMPROVED_CRITICAL_STAFF", INT2NUM(58));
    rb_define_const(cNWScript, "FEAT_IMPROVED_CRITICAL_SPEAR", INT2NUM(59));
    rb_define_const(cNWScript, "FEAT_IMPROVED_CRITICAL_SICKLE", INT2NUM(60));
    rb_define_const(cNWScript, "FEAT_IMPROVED_CRITICAL_SLING", INT2NUM(61));
    rb_define_const(cNWScript, "FEAT_IMPROVED_CRITICAL_UNARMED_STRIKE", INT2NUM(62));
    rb_define_const(cNWScript, "FEAT_IMPROVED_CRITICAL_LONGBOW", INT2NUM(63));
    rb_define_const(cNWScript, "FEAT_IMPROVED_CRITICAL_SHORTBOW", INT2NUM(64));
    rb_define_const(cNWScript, "FEAT_IMPROVED_CRITICAL_SHORT_SWORD", INT2NUM(65));
    rb_define_const(cNWScript, "FEAT_IMPROVED_CRITICAL_RAPIER", INT2NUM(66));
    rb_define_const(cNWScript, "FEAT_IMPROVED_CRITICAL_SCIMITAR", INT2NUM(67));
    rb_define_const(cNWScript, "FEAT_IMPROVED_CRITICAL_LONG_SWORD", INT2NUM(68));
    rb_define_const(cNWScript, "FEAT_IMPROVED_CRITICAL_GREAT_SWORD", INT2NUM(69));
    rb_define_const(cNWScript, "FEAT_IMPROVED_CRITICAL_HAND_AXE", INT2NUM(70));
    rb_define_const(cNWScript, "FEAT_IMPROVED_CRITICAL_THROWING_AXE", INT2NUM(71));
    rb_define_const(cNWScript, "FEAT_IMPROVED_CRITICAL_BATTLE_AXE", INT2NUM(72));
    rb_define_const(cNWScript, "FEAT_IMPROVED_CRITICAL_GREAT_AXE", INT2NUM(73));
    rb_define_const(cNWScript, "FEAT_IMPROVED_CRITICAL_HALBERD", INT2NUM(74));
    rb_define_const(cNWScript, "FEAT_IMPROVED_CRITICAL_LIGHT_HAMMER", INT2NUM(75));
    rb_define_const(cNWScript, "FEAT_IMPROVED_CRITICAL_LIGHT_FLAIL", INT2NUM(76));
    rb_define_const(cNWScript, "FEAT_IMPROVED_CRITICAL_WAR_HAMMER", INT2NUM(77));
    rb_define_const(cNWScript, "FEAT_IMPROVED_CRITICAL_HEAVY_FLAIL", INT2NUM(78));
    rb_define_const(cNWScript, "FEAT_IMPROVED_CRITICAL_KAMA", INT2NUM(79));
    rb_define_const(cNWScript, "FEAT_IMPROVED_CRITICAL_KUKRI", INT2NUM(80));
    rb_define_const(cNWScript, "FEAT_IMPROVED_CRITICAL_SHURIKEN", INT2NUM(82));
    rb_define_const(cNWScript, "FEAT_IMPROVED_CRITICAL_SCYTHE", INT2NUM(83));
    rb_define_const(cNWScript, "FEAT_IMPROVED_CRITICAL_KATANA", INT2NUM(84));
    rb_define_const(cNWScript, "FEAT_IMPROVED_CRITICAL_BASTARD_SWORD", INT2NUM(85));
    rb_define_const(cNWScript, "FEAT_IMPROVED_CRITICAL_DIRE_MACE", INT2NUM(87));
    rb_define_const(cNWScript, "FEAT_IMPROVED_CRITICAL_DOUBLE_AXE", INT2NUM(88));
    rb_define_const(cNWScript, "FEAT_IMPROVED_CRITICAL_TWO_BLADED_SWORD", INT2NUM(89));
    rb_define_const(cNWScript, "FEAT_WEAPON_FOCUS_DAGGER", INT2NUM(90));
    rb_define_const(cNWScript, "FEAT_WEAPON_FOCUS_DART", INT2NUM(91));
    rb_define_const(cNWScript, "FEAT_WEAPON_FOCUS_HEAVY_CROSSBOW", INT2NUM(92));
    rb_define_const(cNWScript, "FEAT_WEAPON_FOCUS_LIGHT_CROSSBOW", INT2NUM(93));
    rb_define_const(cNWScript, "FEAT_WEAPON_FOCUS_LIGHT_MACE", INT2NUM(94));
    rb_define_const(cNWScript, "FEAT_WEAPON_FOCUS_MORNING_STAR", INT2NUM(95));
    rb_define_const(cNWScript, "FEAT_WEAPON_FOCUS_STAFF", INT2NUM(96));
    rb_define_const(cNWScript, "FEAT_WEAPON_FOCUS_SPEAR", INT2NUM(97));
    rb_define_const(cNWScript, "FEAT_WEAPON_FOCUS_SICKLE", INT2NUM(98));
    rb_define_const(cNWScript, "FEAT_WEAPON_FOCUS_SLING", INT2NUM(99));
    rb_define_const(cNWScript, "FEAT_WEAPON_FOCUS_UNARMED_STRIKE", INT2NUM(100));
    rb_define_const(cNWScript, "FEAT_WEAPON_FOCUS_LONGBOW", INT2NUM(101));
    rb_define_const(cNWScript, "FEAT_WEAPON_FOCUS_SHORTBOW", INT2NUM(102));
    rb_define_const(cNWScript, "FEAT_WEAPON_FOCUS_SHORT_SWORD", INT2NUM(103));
    rb_define_const(cNWScript, "FEAT_WEAPON_FOCUS_RAPIER", INT2NUM(104));
    rb_define_const(cNWScript, "FEAT_WEAPON_FOCUS_SCIMITAR", INT2NUM(105));
    rb_define_const(cNWScript, "FEAT_WEAPON_FOCUS_LONG_SWORD", INT2NUM(106));
    rb_define_const(cNWScript, "FEAT_WEAPON_FOCUS_GREAT_SWORD", INT2NUM(107));
    rb_define_const(cNWScript, "FEAT_WEAPON_FOCUS_HAND_AXE", INT2NUM(108));
    rb_define_const(cNWScript, "FEAT_WEAPON_FOCUS_THROWING_AXE", INT2NUM(109));
    rb_define_const(cNWScript, "FEAT_WEAPON_FOCUS_BATTLE_AXE", INT2NUM(110));
    rb_define_const(cNWScript, "FEAT_WEAPON_FOCUS_GREAT_AXE", INT2NUM(111));
    rb_define_const(cNWScript, "FEAT_WEAPON_FOCUS_HALBERD", INT2NUM(112));
    rb_define_const(cNWScript, "FEAT_WEAPON_FOCUS_LIGHT_HAMMER", INT2NUM(113));
    rb_define_const(cNWScript, "FEAT_WEAPON_FOCUS_LIGHT_FLAIL", INT2NUM(114));
    rb_define_const(cNWScript, "FEAT_WEAPON_FOCUS_WAR_HAMMER", INT2NUM(115));
    rb_define_const(cNWScript, "FEAT_WEAPON_FOCUS_HEAVY_FLAIL", INT2NUM(116));
    rb_define_const(cNWScript, "FEAT_WEAPON_FOCUS_KAMA", INT2NUM(117));
    rb_define_const(cNWScript, "FEAT_WEAPON_FOCUS_KUKRI", INT2NUM(118));
    rb_define_const(cNWScript, "FEAT_WEAPON_FOCUS_SHURIKEN", INT2NUM(120));
    rb_define_const(cNWScript, "FEAT_WEAPON_FOCUS_SCYTHE", INT2NUM(121));
    rb_define_const(cNWScript, "FEAT_WEAPON_FOCUS_KATANA", INT2NUM(122));
    rb_define_const(cNWScript, "FEAT_WEAPON_FOCUS_BASTARD_SWORD", INT2NUM(123));
    rb_define_const(cNWScript, "FEAT_WEAPON_FOCUS_DIRE_MACE", INT2NUM(125));
    rb_define_const(cNWScript, "FEAT_WEAPON_FOCUS_DOUBLE_AXE", INT2NUM(126));
    rb_define_const(cNWScript, "FEAT_WEAPON_FOCUS_TWO_BLADED_SWORD", INT2NUM(127));
    rb_define_const(cNWScript, "FEAT_WEAPON_SPECIALIZATION_DAGGER", INT2NUM(128));
    rb_define_const(cNWScript, "FEAT_WEAPON_SPECIALIZATION_DART", INT2NUM(129));
    rb_define_const(cNWScript, "FEAT_WEAPON_SPECIALIZATION_HEAVY_CROSSBOW", INT2NUM(130));
    rb_define_const(cNWScript, "FEAT_WEAPON_SPECIALIZATION_LIGHT_CROSSBOW", INT2NUM(131));
    rb_define_const(cNWScript, "FEAT_WEAPON_SPECIALIZATION_LIGHT_MACE", INT2NUM(132));
    rb_define_const(cNWScript, "FEAT_WEAPON_SPECIALIZATION_MORNING_STAR", INT2NUM(133));
    rb_define_const(cNWScript, "FEAT_WEAPON_SPECIALIZATION_STAFF", INT2NUM(134));
    rb_define_const(cNWScript, "FEAT_WEAPON_SPECIALIZATION_SPEAR", INT2NUM(135));
    rb_define_const(cNWScript, "FEAT_WEAPON_SPECIALIZATION_SICKLE", INT2NUM(136));
    rb_define_const(cNWScript, "FEAT_WEAPON_SPECIALIZATION_SLING", INT2NUM(137));
    rb_define_const(cNWScript, "FEAT_WEAPON_SPECIALIZATION_UNARMED_STRIKE", INT2NUM(138));
    rb_define_const(cNWScript, "FEAT_WEAPON_SPECIALIZATION_LONGBOW", INT2NUM(139));
    rb_define_const(cNWScript, "FEAT_WEAPON_SPECIALIZATION_SHORTBOW", INT2NUM(140));
    rb_define_const(cNWScript, "FEAT_WEAPON_SPECIALIZATION_SHORT_SWORD", INT2NUM(141));
    rb_define_const(cNWScript, "FEAT_WEAPON_SPECIALIZATION_RAPIER", INT2NUM(142));
    rb_define_const(cNWScript, "FEAT_WEAPON_SPECIALIZATION_SCIMITAR", INT2NUM(143));
    rb_define_const(cNWScript, "FEAT_WEAPON_SPECIALIZATION_LONG_SWORD", INT2NUM(144));
    rb_define_const(cNWScript, "FEAT_WEAPON_SPECIALIZATION_GREAT_SWORD", INT2NUM(145));
    rb_define_const(cNWScript, "FEAT_WEAPON_SPECIALIZATION_HAND_AXE", INT2NUM(146));
    rb_define_const(cNWScript, "FEAT_WEAPON_SPECIALIZATION_THROWING_AXE", INT2NUM(147));
    rb_define_const(cNWScript, "FEAT_WEAPON_SPECIALIZATION_BATTLE_AXE", INT2NUM(148));
    rb_define_const(cNWScript, "FEAT_WEAPON_SPECIALIZATION_GREAT_AXE", INT2NUM(149));
    rb_define_const(cNWScript, "FEAT_WEAPON_SPECIALIZATION_HALBERD", INT2NUM(150));
    rb_define_const(cNWScript, "FEAT_WEAPON_SPECIALIZATION_LIGHT_HAMMER", INT2NUM(151));
    rb_define_const(cNWScript, "FEAT_WEAPON_SPECIALIZATION_LIGHT_FLAIL", INT2NUM(152));
    rb_define_const(cNWScript, "FEAT_WEAPON_SPECIALIZATION_WAR_HAMMER", INT2NUM(153));
    rb_define_const(cNWScript, "FEAT_WEAPON_SPECIALIZATION_HEAVY_FLAIL", INT2NUM(154));
    rb_define_const(cNWScript, "FEAT_WEAPON_SPECIALIZATION_KAMA", INT2NUM(155));
    rb_define_const(cNWScript, "FEAT_WEAPON_SPECIALIZATION_KUKRI", INT2NUM(156));
    rb_define_const(cNWScript, "FEAT_WEAPON_SPECIALIZATION_SHURIKEN", INT2NUM(158));
    rb_define_const(cNWScript, "FEAT_WEAPON_SPECIALIZATION_SCYTHE", INT2NUM(159));
    rb_define_const(cNWScript, "FEAT_WEAPON_SPECIALIZATION_KATANA", INT2NUM(160));
    rb_define_const(cNWScript, "FEAT_WEAPON_SPECIALIZATION_BASTARD_SWORD", INT2NUM(161));
    rb_define_const(cNWScript, "FEAT_WEAPON_SPECIALIZATION_DIRE_MACE", INT2NUM(163));
    rb_define_const(cNWScript, "FEAT_WEAPON_SPECIALIZATION_DOUBLE_AXE", INT2NUM(164));
    rb_define_const(cNWScript, "FEAT_WEAPON_SPECIALIZATION_TWO_BLADED_SWORD", INT2NUM(165));
    rb_define_const(cNWScript, "FEAT_SPELL_FOCUS_CONJURATION", INT2NUM(166));
    rb_define_const(cNWScript, "FEAT_SPELL_FOCUS_DIVINATION", INT2NUM(167));
    rb_define_const(cNWScript, "FEAT_SPELL_FOCUS_ENCHANTMENT", INT2NUM(168));
    rb_define_const(cNWScript, "FEAT_SPELL_FOCUS_EVOCATION", INT2NUM(169));
    rb_define_const(cNWScript, "FEAT_SPELL_FOCUS_ILLUSION", INT2NUM(170));
    rb_define_const(cNWScript, "FEAT_SPELL_FOCUS_NECROMANCY", INT2NUM(171));
    rb_define_const(cNWScript, "FEAT_SPELL_FOCUS_TRANSMUTATION", INT2NUM(172));
    rb_define_const(cNWScript, "FEAT_SKILL_FOCUS_CONCENTRATION", INT2NUM(173));
    rb_define_const(cNWScript, "FEAT_SKILL_FOCUS_DISABLE_TRAP", INT2NUM(174));
    rb_define_const(cNWScript, "FEAT_SKILL_FOCUS_DISCIPLINE", INT2NUM(175));
    rb_define_const(cNWScript, "FEAT_SKILL_FOCUS_HEAL", INT2NUM(177));
    rb_define_const(cNWScript, "FEAT_SKILL_FOCUS_HIDE", INT2NUM(178));
    rb_define_const(cNWScript, "FEAT_SKILL_FOCUS_LISTEN", INT2NUM(179));
    rb_define_const(cNWScript, "FEAT_SKILL_FOCUS_LORE", INT2NUM(180));
    rb_define_const(cNWScript, "FEAT_SKILL_FOCUS_MOVE_SILENTLY", INT2NUM(181));
    rb_define_const(cNWScript, "FEAT_SKILL_FOCUS_OPEN_LOCK", INT2NUM(182));
    rb_define_const(cNWScript, "FEAT_SKILL_FOCUS_PARRY", INT2NUM(183));
    rb_define_const(cNWScript, "FEAT_SKILL_FOCUS_PERFORM", INT2NUM(184));
    rb_define_const(cNWScript, "FEAT_SKILL_FOCUS_PERSUADE", INT2NUM(185));
    rb_define_const(cNWScript, "FEAT_SKILL_FOCUS_PICK_POCKET", INT2NUM(186));
    rb_define_const(cNWScript, "FEAT_SKILL_FOCUS_SEARCH", INT2NUM(187));
    rb_define_const(cNWScript, "FEAT_SKILL_FOCUS_SET_TRAP", INT2NUM(188));
    rb_define_const(cNWScript, "FEAT_SKILL_FOCUS_SPELLCRAFT", INT2NUM(189));
    rb_define_const(cNWScript, "FEAT_SKILL_FOCUS_SPOT", INT2NUM(190));
    rb_define_const(cNWScript, "FEAT_SKILL_FOCUS_TAUNT", INT2NUM(192));
    rb_define_const(cNWScript, "FEAT_SKILL_FOCUS_USE_MAGIC_DEVICE", INT2NUM(193));
    rb_define_const(cNWScript, "FEAT_BARBARIAN_ENDURANCE", INT2NUM(194));
    rb_define_const(cNWScript, "FEAT_UNCANNY_DODGE_1", INT2NUM(195));
    rb_define_const(cNWScript, "FEAT_DAMAGE_REDUCTION", INT2NUM(196));
    rb_define_const(cNWScript, "FEAT_BARDIC_KNOWLEDGE", INT2NUM(197));
    rb_define_const(cNWScript, "FEAT_NATURE_SENSE", INT2NUM(198));
    rb_define_const(cNWScript, "FEAT_ANIMAL_COMPANION", INT2NUM(199));
    rb_define_const(cNWScript, "FEAT_WOODLAND_STRIDE", INT2NUM(200));
    rb_define_const(cNWScript, "FEAT_TRACKLESS_STEP", INT2NUM(201));
    rb_define_const(cNWScript, "FEAT_RESIST_NATURES_LURE", INT2NUM(202));
    rb_define_const(cNWScript, "FEAT_VENOM_IMMUNITY", INT2NUM(203));
    rb_define_const(cNWScript, "FEAT_FLURRY_OF_BLOWS", INT2NUM(204));
    rb_define_const(cNWScript, "FEAT_EVASION", INT2NUM(206));
    rb_define_const(cNWScript, "FEAT_MONK_ENDURANCE", INT2NUM(207));
    rb_define_const(cNWScript, "FEAT_STILL_MIND", INT2NUM(208));
    rb_define_const(cNWScript, "FEAT_PURITY_OF_BODY", INT2NUM(209));
    rb_define_const(cNWScript, "FEAT_WHOLENESS_OF_BODY", INT2NUM(211));
    rb_define_const(cNWScript, "FEAT_IMPROVED_EVASION", INT2NUM(212));
    rb_define_const(cNWScript, "FEAT_KI_STRIKE", INT2NUM(213));
    rb_define_const(cNWScript, "FEAT_DIAMOND_BODY", INT2NUM(214));
    rb_define_const(cNWScript, "FEAT_DIAMOND_SOUL", INT2NUM(215));
    rb_define_const(cNWScript, "FEAT_PERFECT_SELF", INT2NUM(216));
    rb_define_const(cNWScript, "FEAT_DIVINE_GRACE", INT2NUM(217));
    rb_define_const(cNWScript, "FEAT_DIVINE_HEALTH", INT2NUM(219));
    rb_define_const(cNWScript, "FEAT_SNEAK_ATTACK", INT2NUM(221));
    rb_define_const(cNWScript, "FEAT_CRIPPLING_STRIKE", INT2NUM(222));
    rb_define_const(cNWScript, "FEAT_DEFENSIVE_ROLL", INT2NUM(223));
    rb_define_const(cNWScript, "FEAT_OPPORTUNIST", INT2NUM(224));
    rb_define_const(cNWScript, "FEAT_SKILL_MASTERY", INT2NUM(225));
    rb_define_const(cNWScript, "FEAT_UNCANNY_REFLEX", INT2NUM(226));
    rb_define_const(cNWScript, "FEAT_STONECUNNING", INT2NUM(227));
    rb_define_const(cNWScript, "FEAT_DARKVISION", INT2NUM(228));
    rb_define_const(cNWScript, "FEAT_HARDINESS_VERSUS_POISONS", INT2NUM(229));
    rb_define_const(cNWScript, "FEAT_HARDINESS_VERSUS_SPELLS", INT2NUM(230));
    rb_define_const(cNWScript, "FEAT_BATTLE_TRAINING_VERSUS_ORCS", INT2NUM(231));
    rb_define_const(cNWScript, "FEAT_BATTLE_TRAINING_VERSUS_GOBLINS", INT2NUM(232));
    rb_define_const(cNWScript, "FEAT_BATTLE_TRAINING_VERSUS_GIANTS", INT2NUM(233));
    rb_define_const(cNWScript, "FEAT_SKILL_AFFINITY_LORE", INT2NUM(234));
    rb_define_const(cNWScript, "FEAT_IMMUNITY_TO_SLEEP", INT2NUM(235));
    rb_define_const(cNWScript, "FEAT_HARDINESS_VERSUS_ENCHANTMENTS", INT2NUM(236));
    rb_define_const(cNWScript, "FEAT_SKILL_AFFINITY_LISTEN", INT2NUM(237));
    rb_define_const(cNWScript, "FEAT_SKILL_AFFINITY_SEARCH", INT2NUM(238));
    rb_define_const(cNWScript, "FEAT_SKILL_AFFINITY_SPOT", INT2NUM(239));
    rb_define_const(cNWScript, "FEAT_KEEN_SENSE", INT2NUM(240));
    rb_define_const(cNWScript, "FEAT_HARDINESS_VERSUS_ILLUSIONS", INT2NUM(241));
    rb_define_const(cNWScript, "FEAT_BATTLE_TRAINING_VERSUS_REPTILIANS", INT2NUM(242));
    rb_define_const(cNWScript, "FEAT_SKILL_AFFINITY_CONCENTRATION", INT2NUM(243));
    rb_define_const(cNWScript, "FEAT_PARTIAL_SKILL_AFFINITY_LISTEN", INT2NUM(244));
    rb_define_const(cNWScript, "FEAT_PARTIAL_SKILL_AFFINITY_SEARCH", INT2NUM(245));
    rb_define_const(cNWScript, "FEAT_PARTIAL_SKILL_AFFINITY_SPOT", INT2NUM(246));
    rb_define_const(cNWScript, "FEAT_SKILL_AFFINITY_MOVE_SILENTLY", INT2NUM(247));
    rb_define_const(cNWScript, "FEAT_LUCKY", INT2NUM(248));
    rb_define_const(cNWScript, "FEAT_FEARLESS", INT2NUM(249));
    rb_define_const(cNWScript, "FEAT_GOOD_AIM", INT2NUM(250));
    rb_define_const(cNWScript, "FEAT_UNCANNY_DODGE_2", INT2NUM(251));
    rb_define_const(cNWScript, "FEAT_UNCANNY_DODGE_3", INT2NUM(252));
    rb_define_const(cNWScript, "FEAT_UNCANNY_DODGE_4", INT2NUM(253));
    rb_define_const(cNWScript, "FEAT_UNCANNY_DODGE_5", INT2NUM(254));
    rb_define_const(cNWScript, "FEAT_UNCANNY_DODGE_6", INT2NUM(255));
    rb_define_const(cNWScript, "FEAT_WEAPON_PROFICIENCY_ELF", INT2NUM(256));
    rb_define_const(cNWScript, "FEAT_BARD_SONGS", INT2NUM(257));
    rb_define_const(cNWScript, "FEAT_QUICK_TO_MASTER", INT2NUM(258));
    rb_define_const(cNWScript, "FEAT_SLIPPERY_MIND", INT2NUM(259));
    rb_define_const(cNWScript, "FEAT_MONK_AC_BONUS", INT2NUM(260));
    rb_define_const(cNWScript, "FEAT_FAVORED_ENEMY_DWARF", INT2NUM(261));
    rb_define_const(cNWScript, "FEAT_FAVORED_ENEMY_ELF", INT2NUM(262));
    rb_define_const(cNWScript, "FEAT_FAVORED_ENEMY_GNOME", INT2NUM(263));
    rb_define_const(cNWScript, "FEAT_FAVORED_ENEMY_HALFLING", INT2NUM(264));
    rb_define_const(cNWScript, "FEAT_FAVORED_ENEMY_HALFELF", INT2NUM(265));
    rb_define_const(cNWScript, "FEAT_FAVORED_ENEMY_HALFORC", INT2NUM(266));
    rb_define_const(cNWScript, "FEAT_FAVORED_ENEMY_HUMAN", INT2NUM(267));
    rb_define_const(cNWScript, "FEAT_FAVORED_ENEMY_ABERRATION", INT2NUM(268));
    rb_define_const(cNWScript, "FEAT_FAVORED_ENEMY_ANIMAL", INT2NUM(269));
    rb_define_const(cNWScript, "FEAT_FAVORED_ENEMY_BEAST", INT2NUM(270));
    rb_define_const(cNWScript, "FEAT_FAVORED_ENEMY_CONSTRUCT", INT2NUM(271));
    rb_define_const(cNWScript, "FEAT_FAVORED_ENEMY_DRAGON", INT2NUM(272));
    rb_define_const(cNWScript, "FEAT_FAVORED_ENEMY_GOBLINOID", INT2NUM(273));
    rb_define_const(cNWScript, "FEAT_FAVORED_ENEMY_MONSTROUS", INT2NUM(274));
    rb_define_const(cNWScript, "FEAT_FAVORED_ENEMY_ORC", INT2NUM(275));
    rb_define_const(cNWScript, "FEAT_FAVORED_ENEMY_REPTILIAN", INT2NUM(276));
    rb_define_const(cNWScript, "FEAT_FAVORED_ENEMY_ELEMENTAL", INT2NUM(277));
    rb_define_const(cNWScript, "FEAT_FAVORED_ENEMY_FEY", INT2NUM(278));
    rb_define_const(cNWScript, "FEAT_FAVORED_ENEMY_GIANT", INT2NUM(279));
    rb_define_const(cNWScript, "FEAT_FAVORED_ENEMY_MAGICAL_BEAST", INT2NUM(280));
    rb_define_const(cNWScript, "FEAT_FAVORED_ENEMY_OUTSIDER", INT2NUM(281));
    rb_define_const(cNWScript, "FEAT_FAVORED_ENEMY_SHAPECHANGER", INT2NUM(284));
    rb_define_const(cNWScript, "FEAT_FAVORED_ENEMY_UNDEAD", INT2NUM(285));
    rb_define_const(cNWScript, "FEAT_FAVORED_ENEMY_VERMIN", INT2NUM(286));
    rb_define_const(cNWScript, "FEAT_WEAPON_PROFICIENCY_CREATURE", INT2NUM(289));
    rb_define_const(cNWScript, "FEAT_WEAPON_SPECIALIZATION_CREATURE", INT2NUM(290));
    rb_define_const(cNWScript, "FEAT_WEAPON_FOCUS_CREATURE", INT2NUM(291));
    rb_define_const(cNWScript, "FEAT_IMPROVED_CRITICAL_CREATURE", INT2NUM(292));
    rb_define_const(cNWScript, "FEAT_BARBARIAN_RAGE", INT2NUM(293));
    rb_define_const(cNWScript, "FEAT_TURN_UNDEAD", INT2NUM(294));
    rb_define_const(cNWScript, "FEAT_QUIVERING_PALM", INT2NUM(296));
    rb_define_const(cNWScript, "FEAT_EMPTY_BODY", INT2NUM(297));
    rb_define_const(cNWScript, "FEAT_LAY_ON_HANDS", INT2NUM(299));
    rb_define_const(cNWScript, "FEAT_AURA_OF_COURAGE", INT2NUM(300));
    rb_define_const(cNWScript, "FEAT_SMITE_EVIL", INT2NUM(301));
    rb_define_const(cNWScript, "FEAT_REMOVE_DISEASE", INT2NUM(302));
    rb_define_const(cNWScript, "FEAT_SUMMON_FAMILIAR", INT2NUM(303));
    rb_define_const(cNWScript, "FEAT_ELEMENTAL_SHAPE", INT2NUM(304));
    rb_define_const(cNWScript, "FEAT_WILD_SHAPE", INT2NUM(305));
    rb_define_const(cNWScript, "FEAT_WAR_DOMAIN_POWER", INT2NUM(306));
    rb_define_const(cNWScript, "FEAT_STRENGTH_DOMAIN_POWER", INT2NUM(307));
    rb_define_const(cNWScript, "FEAT_PROTECTION_DOMAIN_POWER", INT2NUM(308));
    rb_define_const(cNWScript, "FEAT_LUCK_DOMAIN_POWER", INT2NUM(309));
    rb_define_const(cNWScript, "FEAT_DEATH_DOMAIN_POWER", INT2NUM(310));
    rb_define_const(cNWScript, "FEAT_AIR_DOMAIN_POWER", INT2NUM(311));
    rb_define_const(cNWScript, "FEAT_ANIMAL_DOMAIN_POWER", INT2NUM(312));
    rb_define_const(cNWScript, "FEAT_DESTRUCTION_DOMAIN_POWER", INT2NUM(313));
    rb_define_const(cNWScript, "FEAT_EARTH_DOMAIN_POWER", INT2NUM(314));
    rb_define_const(cNWScript, "FEAT_EVIL_DOMAIN_POWER", INT2NUM(315));
    rb_define_const(cNWScript, "FEAT_FIRE_DOMAIN_POWER", INT2NUM(316));
    rb_define_const(cNWScript, "FEAT_GOOD_DOMAIN_POWER", INT2NUM(317));
    rb_define_const(cNWScript, "FEAT_HEALING_DOMAIN_POWER", INT2NUM(318));
    rb_define_const(cNWScript, "FEAT_KNOWLEDGE_DOMAIN_POWER", INT2NUM(319));
    rb_define_const(cNWScript, "FEAT_MAGIC_DOMAIN_POWER", INT2NUM(320));
    rb_define_const(cNWScript, "FEAT_PLANT_DOMAIN_POWER", INT2NUM(321));
    rb_define_const(cNWScript, "FEAT_SUN_DOMAIN_POWER", INT2NUM(322));
    rb_define_const(cNWScript, "FEAT_TRAVEL_DOMAIN_POWER", INT2NUM(323));
    rb_define_const(cNWScript, "FEAT_TRICKERY_DOMAIN_POWER", INT2NUM(324));
    rb_define_const(cNWScript, "FEAT_WATER_DOMAIN_POWER", INT2NUM(325));
    rb_define_const(cNWScript, "FEAT_LOWLIGHTVISION", INT2NUM(354));
    rb_define_const(cNWScript, "FEAT_IMPROVED_INITIATIVE", INT2NUM(377));
    rb_define_const(cNWScript, "FEAT_ARTIST", INT2NUM(378));
    rb_define_const(cNWScript, "FEAT_BLOODED", INT2NUM(379));
    rb_define_const(cNWScript, "FEAT_BULLHEADED", INT2NUM(380));
    rb_define_const(cNWScript, "FEAT_COURTLY_MAGOCRACY", INT2NUM(381));
    rb_define_const(cNWScript, "FEAT_LUCK_OF_HEROES", INT2NUM(382));
    rb_define_const(cNWScript, "FEAT_RESIST_POISON", INT2NUM(383));
    rb_define_const(cNWScript, "FEAT_SILVER_PALM", INT2NUM(384));
    rb_define_const(cNWScript, "FEAT_SNAKEBLOOD", INT2NUM(386));
    rb_define_const(cNWScript, "FEAT_STEALTHY", INT2NUM(387));
    rb_define_const(cNWScript, "FEAT_STRONGSOUL", INT2NUM(388));
    rb_define_const(cNWScript, "FEAT_EXPERTISE", INT2NUM(389));
    rb_define_const(cNWScript, "FEAT_IMPROVED_EXPERTISE", INT2NUM(390));
    rb_define_const(cNWScript, "FEAT_GREAT_CLEAVE", INT2NUM(391));
    rb_define_const(cNWScript, "FEAT_SPRING_ATTACK", INT2NUM(392));
    rb_define_const(cNWScript, "FEAT_GREATER_SPELL_FOCUS_ABJURATION", INT2NUM(393));
    rb_define_const(cNWScript, "FEAT_GREATER_SPELL_FOCUS_CONJURATION", INT2NUM(394));
    rb_define_const(cNWScript, "FEAT_GREATER_SPELL_FOCUS_DIVINIATION", INT2NUM(395));
    rb_define_const(cNWScript, "FEAT_GREATER_SPELL_FOCUS_DIVINATION", INT2NUM(395));
    rb_define_const(cNWScript, "FEAT_GREATER_SPELL_FOCUS_ENCHANTMENT", INT2NUM(396));
    rb_define_const(cNWScript, "FEAT_GREATER_SPELL_FOCUS_EVOCATION", INT2NUM(397));
    rb_define_const(cNWScript, "FEAT_GREATER_SPELL_FOCUS_ILLUSION", INT2NUM(398));
    rb_define_const(cNWScript, "FEAT_GREATER_SPELL_FOCUS_NECROMANCY", INT2NUM(399));
    rb_define_const(cNWScript, "FEAT_GREATER_SPELL_FOCUS_TRANSMUTATION", INT2NUM(400));
    rb_define_const(cNWScript, "FEAT_GREATER_SPELL_PENETRATION", INT2NUM(401));
    rb_define_const(cNWScript, "FEAT_THUG", INT2NUM(402));
    rb_define_const(cNWScript, "FEAT_SKILLFOCUS_APPRAISE", INT2NUM(404));
    rb_define_const(cNWScript, "FEAT_SKILL_FOCUS_TUMBLE", INT2NUM(406));
    rb_define_const(cNWScript, "FEAT_SKILL_FOCUS_CRAFT_TRAP", INT2NUM(407));
    rb_define_const(cNWScript, "FEAT_BLIND_FIGHT", INT2NUM(408));
    rb_define_const(cNWScript, "FEAT_CIRCLE_KICK", INT2NUM(409));
    rb_define_const(cNWScript, "FEAT_EXTRA_STUNNING_ATTACK", INT2NUM(410));
    rb_define_const(cNWScript, "FEAT_RAPID_RELOAD", INT2NUM(411));
    rb_define_const(cNWScript, "FEAT_ZEN_ARCHERY", INT2NUM(412));
    rb_define_const(cNWScript, "FEAT_DIVINE_MIGHT", INT2NUM(413));
    rb_define_const(cNWScript, "FEAT_DIVINE_SHIELD", INT2NUM(414));
    rb_define_const(cNWScript, "FEAT_ARCANE_DEFENSE_ABJURATION", INT2NUM(415));
    rb_define_const(cNWScript, "FEAT_ARCANE_DEFENSE_CONJURATION", INT2NUM(416));
    rb_define_const(cNWScript, "FEAT_ARCANE_DEFENSE_DIVINATION", INT2NUM(417));
    rb_define_const(cNWScript, "FEAT_ARCANE_DEFENSE_ENCHANTMENT", INT2NUM(418));
    rb_define_const(cNWScript, "FEAT_ARCANE_DEFENSE_EVOCATION", INT2NUM(419));
    rb_define_const(cNWScript, "FEAT_ARCANE_DEFENSE_ILLUSION", INT2NUM(420));
    rb_define_const(cNWScript, "FEAT_ARCANE_DEFENSE_NECROMANCY", INT2NUM(421));
    rb_define_const(cNWScript, "FEAT_ARCANE_DEFENSE_TRANSMUTATION", INT2NUM(422));
    rb_define_const(cNWScript, "FEAT_EXTRA_MUSIC", INT2NUM(423));
    rb_define_const(cNWScript, "FEAT_LINGERING_SONG", INT2NUM(424));
    rb_define_const(cNWScript, "FEAT_DIRTY_FIGHTING", INT2NUM(425));
    rb_define_const(cNWScript, "FEAT_RESIST_DISEASE", INT2NUM(426));
    rb_define_const(cNWScript, "FEAT_RESIST_ENERGY_COLD", INT2NUM(427));
    rb_define_const(cNWScript, "FEAT_RESIST_ENERGY_ACID", INT2NUM(428));
    rb_define_const(cNWScript, "FEAT_RESIST_ENERGY_FIRE", INT2NUM(429));
    rb_define_const(cNWScript, "FEAT_RESIST_ENERGY_ELECTRICAL", INT2NUM(430));
    rb_define_const(cNWScript, "FEAT_RESIST_ENERGY_SONIC", INT2NUM(431));
    rb_define_const(cNWScript, "FEAT_HIDE_IN_PLAIN_SIGHT", INT2NUM(433));
    rb_define_const(cNWScript, "FEAT_SHADOW_DAZE", INT2NUM(434));
    rb_define_const(cNWScript, "FEAT_SUMMON_SHADOW", INT2NUM(435));
    rb_define_const(cNWScript, "FEAT_SHADOW_EVADE", INT2NUM(436));
    rb_define_const(cNWScript, "FEAT_DENEIRS_EYE", INT2NUM(437));
    rb_define_const(cNWScript, "FEAT_TYMORAS_SMILE", INT2NUM(438));
    rb_define_const(cNWScript, "FEAT_LLIIRAS_HEART", INT2NUM(439));
    rb_define_const(cNWScript, "FEAT_CRAFT_HARPER_ITEM", INT2NUM(440));
    rb_define_const(cNWScript, "FEAT_HARPER_SLEEP", INT2NUM(441));
    rb_define_const(cNWScript, "FEAT_HARPER_CATS_GRACE", INT2NUM(442));
    rb_define_const(cNWScript, "FEAT_HARPER_EAGLES_SPLENDOR", INT2NUM(443));
    rb_define_const(cNWScript, "FEAT_HARPER_INVISIBILITY", INT2NUM(444));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_ENCHANT_ARROW_1", INT2NUM(445));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_ENCHANT_ARROW_2", INT2NUM(446));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_ENCHANT_ARROW_3", INT2NUM(447));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_ENCHANT_ARROW_4", INT2NUM(448));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_ENCHANT_ARROW_5", INT2NUM(449));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_IMBUE_ARROW", INT2NUM(450));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_SEEKER_ARROW_1", INT2NUM(451));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_SEEKER_ARROW_2", INT2NUM(452));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_HAIL_OF_ARROWS", INT2NUM(453));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_ARROW_OF_DEATH", INT2NUM(454));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_DEATH_ATTACK_1", INT2NUM(455));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_DEATH_ATTACK_2", INT2NUM(456));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_DEATH_ATTACK_3", INT2NUM(457));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_DEATH_ATTACK_4", INT2NUM(458));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_DEATH_ATTACK_5", INT2NUM(459));
    rb_define_const(cNWScript, "FEAT_BLACKGUARD_SNEAK_ATTACK_1D6", INT2NUM(460));
    rb_define_const(cNWScript, "FEAT_BLACKGUARD_SNEAK_ATTACK_2D6", INT2NUM(461));
    rb_define_const(cNWScript, "FEAT_BLACKGUARD_SNEAK_ATTACK_3D6", INT2NUM(462));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_POISON_SAVE_1", INT2NUM(463));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_POISON_SAVE_2", INT2NUM(464));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_POISON_SAVE_3", INT2NUM(465));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_POISON_SAVE_4", INT2NUM(466));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_POISON_SAVE_5", INT2NUM(467));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_SPELL_GHOSTLY_VISAGE", INT2NUM(468));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_DARKNESS", INT2NUM(469));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_INVISIBILITY_1", INT2NUM(470));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_INVISIBILITY_2", INT2NUM(471));
    rb_define_const(cNWScript, "FEAT_SMITE_GOOD", INT2NUM(472));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_DARK_BLESSING", INT2NUM(473));
    rb_define_const(cNWScript, "FEAT_INFLICT_LIGHT_WOUNDS", INT2NUM(474));
    rb_define_const(cNWScript, "FEAT_INFLICT_MODERATE_WOUNDS", INT2NUM(475));
    rb_define_const(cNWScript, "FEAT_INFLICT_SERIOUS_WOUNDS", INT2NUM(476));
    rb_define_const(cNWScript, "FEAT_INFLICT_CRITICAL_WOUNDS", INT2NUM(477));
    rb_define_const(cNWScript, "FEAT_BULLS_STRENGTH", INT2NUM(478));
    rb_define_const(cNWScript, "FEAT_CONTAGION", INT2NUM(479));
    rb_define_const(cNWScript, "FEAT_EYE_OF_GRUUMSH_BLINDING_SPITTLE", INT2NUM(480));
    rb_define_const(cNWScript, "FEAT_EYE_OF_GRUUMSH_BLINDING_SPITTLE_2", INT2NUM(481));
    rb_define_const(cNWScript, "FEAT_EYE_OF_GRUUMSH_COMMAND_THE_HORDE", INT2NUM(482));
    rb_define_const(cNWScript, "FEAT_EYE_OF_GRUUMSH_SWING_BLINDLY", INT2NUM(483));
    rb_define_const(cNWScript, "FEAT_EYE_OF_GRUUMSH_RITUAL_SCARRING", INT2NUM(484));
    rb_define_const(cNWScript, "FEAT_BLINDSIGHT_5_FEET", INT2NUM(485));
    rb_define_const(cNWScript, "FEAT_BLINDSIGHT_10_FEET", INT2NUM(486));
    rb_define_const(cNWScript, "FEAT_EYE_OF_GRUUMSH_SIGHT_OF_GRUUMSH", INT2NUM(487));
    rb_define_const(cNWScript, "FEAT_BLINDSIGHT_60_FEET", INT2NUM(488));
    rb_define_const(cNWScript, "FEAT_SHOU_DISCIPLE_DODGE_2", INT2NUM(489));
    rb_define_const(cNWScript, "FEAT_EPIC_ARMOR_SKIN", INT2NUM(490));
    rb_define_const(cNWScript, "FEAT_EPIC_BLINDING_SPEED", INT2NUM(491));
    rb_define_const(cNWScript, "FEAT_EPIC_DAMAGE_REDUCTION_3", INT2NUM(492));
    rb_define_const(cNWScript, "FEAT_EPIC_DAMAGE_REDUCTION_6", INT2NUM(493));
    rb_define_const(cNWScript, "FEAT_EPIC_DAMAGE_REDUCTION_9", INT2NUM(494));
    rb_define_const(cNWScript, "FEAT_EPIC_DEVASTATING_CRITICAL_CLUB", INT2NUM(495));
    rb_define_const(cNWScript, "FEAT_EPIC_DEVASTATING_CRITICAL_DAGGER", INT2NUM(496));
    rb_define_const(cNWScript, "FEAT_EPIC_DEVASTATING_CRITICAL_DART", INT2NUM(497));
    rb_define_const(cNWScript, "FEAT_EPIC_DEVASTATING_CRITICAL_HEAVYCROSSBOW", INT2NUM(498));
    rb_define_const(cNWScript, "FEAT_EPIC_DEVASTATING_CRITICAL_LIGHTCROSSBOW", INT2NUM(499));
    rb_define_const(cNWScript, "FEAT_EPIC_DEVASTATING_CRITICAL_LIGHTMACE", INT2NUM(500));
    rb_define_const(cNWScript, "FEAT_EPIC_DEVASTATING_CRITICAL_MORNINGSTAR", INT2NUM(501));
    rb_define_const(cNWScript, "FEAT_EPIC_DEVASTATING_CRITICAL_QUARTERSTAFF", INT2NUM(502));
    rb_define_const(cNWScript, "FEAT_EPIC_DEVASTATING_CRITICAL_SHORTSPEAR", INT2NUM(503));
    rb_define_const(cNWScript, "FEAT_EPIC_DEVASTATING_CRITICAL_SICKLE", INT2NUM(504));
    rb_define_const(cNWScript, "FEAT_EPIC_DEVASTATING_CRITICAL_SLING", INT2NUM(505));
    rb_define_const(cNWScript, "FEAT_EPIC_DEVASTATING_CRITICAL_UNARMED", INT2NUM(506));
    rb_define_const(cNWScript, "FEAT_EPIC_DEVASTATING_CRITICAL_LONGBOW", INT2NUM(507));
    rb_define_const(cNWScript, "FEAT_EPIC_DEVASTATING_CRITICAL_SHORTBOW", INT2NUM(508));
    rb_define_const(cNWScript, "FEAT_EPIC_DEVASTATING_CRITICAL_SHORTSWORD", INT2NUM(509));
    rb_define_const(cNWScript, "FEAT_EPIC_DEVASTATING_CRITICAL_RAPIER", INT2NUM(510));
    rb_define_const(cNWScript, "FEAT_EPIC_DEVASTATING_CRITICAL_SCIMITAR", INT2NUM(511));
    rb_define_const(cNWScript, "FEAT_EPIC_DEVASTATING_CRITICAL_LONGSWORD", INT2NUM(512));
    rb_define_const(cNWScript, "FEAT_EPIC_DEVASTATING_CRITICAL_GREATSWORD", INT2NUM(513));
    rb_define_const(cNWScript, "FEAT_EPIC_DEVASTATING_CRITICAL_HANDAXE", INT2NUM(514));
    rb_define_const(cNWScript, "FEAT_EPIC_DEVASTATING_CRITICAL_THROWINGAXE", INT2NUM(515));
    rb_define_const(cNWScript, "FEAT_EPIC_DEVASTATING_CRITICAL_BATTLEAXE", INT2NUM(516));
    rb_define_const(cNWScript, "FEAT_EPIC_DEVASTATING_CRITICAL_GREATAXE", INT2NUM(517));
    rb_define_const(cNWScript, "FEAT_EPIC_DEVASTATING_CRITICAL_HALBERD", INT2NUM(518));
    rb_define_const(cNWScript, "FEAT_EPIC_DEVASTATING_CRITICAL_LIGHTHAMMER", INT2NUM(519));
    rb_define_const(cNWScript, "FEAT_EPIC_DEVASTATING_CRITICAL_LIGHTFLAIL", INT2NUM(520));
    rb_define_const(cNWScript, "FEAT_EPIC_DEVASTATING_CRITICAL_WARHAMMER", INT2NUM(521));
    rb_define_const(cNWScript, "FEAT_EPIC_DEVASTATING_CRITICAL_HEAVYFLAIL", INT2NUM(522));
    rb_define_const(cNWScript, "FEAT_EPIC_DEVASTATING_CRITICAL_KAMA", INT2NUM(523));
    rb_define_const(cNWScript, "FEAT_EPIC_DEVASTATING_CRITICAL_KUKRI", INT2NUM(524));
    rb_define_const(cNWScript, "FEAT_EPIC_DEVASTATING_CRITICAL_SHURIKEN", INT2NUM(525));
    rb_define_const(cNWScript, "FEAT_EPIC_DEVASTATING_CRITICAL_SCYTHE", INT2NUM(526));
    rb_define_const(cNWScript, "FEAT_EPIC_DEVASTATING_CRITICAL_KATANA", INT2NUM(527));
    rb_define_const(cNWScript, "FEAT_EPIC_DEVASTATING_CRITICAL_BASTARDSWORD", INT2NUM(528));
    rb_define_const(cNWScript, "FEAT_EPIC_DEVASTATING_CRITICAL_DIREMACE", INT2NUM(529));
    rb_define_const(cNWScript, "FEAT_EPIC_DEVASTATING_CRITICAL_DOUBLEAXE", INT2NUM(530));
    rb_define_const(cNWScript, "FEAT_EPIC_DEVASTATING_CRITICAL_TWOBLADEDSWORD", INT2NUM(531));
    rb_define_const(cNWScript, "FEAT_EPIC_DEVASTATING_CRITICAL_CREATURE", INT2NUM(532));
    rb_define_const(cNWScript, "FEAT_EPIC_ENERGY_RESISTANCE_COLD_1", INT2NUM(533));
    rb_define_const(cNWScript, "FEAT_EPIC_ENERGY_RESISTANCE_COLD_2", INT2NUM(534));
    rb_define_const(cNWScript, "FEAT_EPIC_ENERGY_RESISTANCE_COLD_3", INT2NUM(535));
    rb_define_const(cNWScript, "FEAT_EPIC_ENERGY_RESISTANCE_COLD_4", INT2NUM(536));
    rb_define_const(cNWScript, "FEAT_EPIC_ENERGY_RESISTANCE_COLD_5", INT2NUM(537));
    rb_define_const(cNWScript, "FEAT_EPIC_ENERGY_RESISTANCE_COLD_6", INT2NUM(538));
    rb_define_const(cNWScript, "FEAT_EPIC_ENERGY_RESISTANCE_COLD_7", INT2NUM(539));
    rb_define_const(cNWScript, "FEAT_EPIC_ENERGY_RESISTANCE_COLD_8", INT2NUM(540));
    rb_define_const(cNWScript, "FEAT_EPIC_ENERGY_RESISTANCE_COLD_9", INT2NUM(541));
    rb_define_const(cNWScript, "FEAT_EPIC_ENERGY_RESISTANCE_COLD_10", INT2NUM(542));
    rb_define_const(cNWScript, "FEAT_EPIC_ENERGY_RESISTANCE_ACID_1", INT2NUM(543));
    rb_define_const(cNWScript, "FEAT_EPIC_ENERGY_RESISTANCE_ACID_2", INT2NUM(544));
    rb_define_const(cNWScript, "FEAT_EPIC_ENERGY_RESISTANCE_ACID_3", INT2NUM(545));
    rb_define_const(cNWScript, "FEAT_EPIC_ENERGY_RESISTANCE_ACID_4", INT2NUM(546));
    rb_define_const(cNWScript, "FEAT_EPIC_ENERGY_RESISTANCE_ACID_5", INT2NUM(547));
    rb_define_const(cNWScript, "FEAT_EPIC_ENERGY_RESISTANCE_ACID_6", INT2NUM(548));
    rb_define_const(cNWScript, "FEAT_EPIC_ENERGY_RESISTANCE_ACID_7", INT2NUM(549));
    rb_define_const(cNWScript, "FEAT_EPIC_ENERGY_RESISTANCE_ACID_8", INT2NUM(550));
    rb_define_const(cNWScript, "FEAT_EPIC_ENERGY_RESISTANCE_ACID_9", INT2NUM(551));
    rb_define_const(cNWScript, "FEAT_EPIC_ENERGY_RESISTANCE_ACID_10", INT2NUM(552));
    rb_define_const(cNWScript, "FEAT_EPIC_ENERGY_RESISTANCE_FIRE_1", INT2NUM(553));
    rb_define_const(cNWScript, "FEAT_EPIC_ENERGY_RESISTANCE_FIRE_2", INT2NUM(554));
    rb_define_const(cNWScript, "FEAT_EPIC_ENERGY_RESISTANCE_FIRE_3", INT2NUM(555));
    rb_define_const(cNWScript, "FEAT_EPIC_ENERGY_RESISTANCE_FIRE_4", INT2NUM(556));
    rb_define_const(cNWScript, "FEAT_EPIC_ENERGY_RESISTANCE_FIRE_5", INT2NUM(557));
    rb_define_const(cNWScript, "FEAT_EPIC_ENERGY_RESISTANCE_FIRE_6", INT2NUM(558));
    rb_define_const(cNWScript, "FEAT_EPIC_ENERGY_RESISTANCE_FIRE_7", INT2NUM(559));
    rb_define_const(cNWScript, "FEAT_EPIC_ENERGY_RESISTANCE_FIRE_8", INT2NUM(560));
    rb_define_const(cNWScript, "FEAT_EPIC_ENERGY_RESISTANCE_FIRE_9", INT2NUM(561));
    rb_define_const(cNWScript, "FEAT_EPIC_ENERGY_RESISTANCE_FIRE_10", INT2NUM(562));
    rb_define_const(cNWScript, "FEAT_EPIC_ENERGY_RESISTANCE_ELECTRICAL_1", INT2NUM(563));
    rb_define_const(cNWScript, "FEAT_EPIC_ENERGY_RESISTANCE_ELECTRICAL_2", INT2NUM(564));
    rb_define_const(cNWScript, "FEAT_EPIC_ENERGY_RESISTANCE_ELECTRICAL_3", INT2NUM(565));
    rb_define_const(cNWScript, "FEAT_EPIC_ENERGY_RESISTANCE_ELECTRICAL_4", INT2NUM(566));
    rb_define_const(cNWScript, "FEAT_EPIC_ENERGY_RESISTANCE_ELECTRICAL_5", INT2NUM(567));
    rb_define_const(cNWScript, "FEAT_EPIC_ENERGY_RESISTANCE_ELECTRICAL_6", INT2NUM(568));
    rb_define_const(cNWScript, "FEAT_EPIC_ENERGY_RESISTANCE_ELECTRICAL_7", INT2NUM(569));
    rb_define_const(cNWScript, "FEAT_EPIC_ENERGY_RESISTANCE_ELECTRICAL_8", INT2NUM(570));
    rb_define_const(cNWScript, "FEAT_EPIC_ENERGY_RESISTANCE_ELECTRICAL_9", INT2NUM(571));
    rb_define_const(cNWScript, "FEAT_EPIC_ENERGY_RESISTANCE_ELECTRICAL_10", INT2NUM(572));
    rb_define_const(cNWScript, "FEAT_EPIC_ENERGY_RESISTANCE_SONIC_1", INT2NUM(573));
    rb_define_const(cNWScript, "FEAT_EPIC_ENERGY_RESISTANCE_SONIC_2", INT2NUM(574));
    rb_define_const(cNWScript, "FEAT_EPIC_ENERGY_RESISTANCE_SONIC_3", INT2NUM(575));
    rb_define_const(cNWScript, "FEAT_EPIC_ENERGY_RESISTANCE_SONIC_4", INT2NUM(576));
    rb_define_const(cNWScript, "FEAT_EPIC_ENERGY_RESISTANCE_SONIC_5", INT2NUM(577));
    rb_define_const(cNWScript, "FEAT_EPIC_ENERGY_RESISTANCE_SONIC_6", INT2NUM(578));
    rb_define_const(cNWScript, "FEAT_EPIC_ENERGY_RESISTANCE_SONIC_7", INT2NUM(579));
    rb_define_const(cNWScript, "FEAT_EPIC_ENERGY_RESISTANCE_SONIC_8", INT2NUM(580));
    rb_define_const(cNWScript, "FEAT_EPIC_ENERGY_RESISTANCE_SONIC_9", INT2NUM(581));
    rb_define_const(cNWScript, "FEAT_EPIC_ENERGY_RESISTANCE_SONIC_10", INT2NUM(582));
    rb_define_const(cNWScript, "FEAT_EPIC_FORTITUDE", INT2NUM(583));
    rb_define_const(cNWScript, "FEAT_EPIC_PROWESS", INT2NUM(584));
    rb_define_const(cNWScript, "FEAT_EPIC_REFLEXES", INT2NUM(585));
    rb_define_const(cNWScript, "FEAT_EPIC_REPUTATION", INT2NUM(586));
    rb_define_const(cNWScript, "FEAT_EPIC_SKILL_FOCUS_ANIMAL_EMPATHY", INT2NUM(587));
    rb_define_const(cNWScript, "FEAT_EPIC_SKILL_FOCUS_APPRAISE", INT2NUM(588));
    rb_define_const(cNWScript, "FEAT_EPIC_SKILL_FOCUS_CONCENTRATION", INT2NUM(589));
    rb_define_const(cNWScript, "FEAT_EPIC_SKILL_FOCUS_CRAFT_TRAP", INT2NUM(590));
    rb_define_const(cNWScript, "FEAT_EPIC_SKILL_FOCUS_DISABLETRAP", INT2NUM(591));
    rb_define_const(cNWScript, "FEAT_EPIC_SKILL_FOCUS_DISCIPLINE", INT2NUM(592));
    rb_define_const(cNWScript, "FEAT_EPIC_SKILL_FOCUS_HEAL", INT2NUM(593));
    rb_define_const(cNWScript, "FEAT_EPIC_SKILL_FOCUS_HIDE", INT2NUM(594));
    rb_define_const(cNWScript, "FEAT_EPIC_SKILL_FOCUS_LISTEN", INT2NUM(595));
    rb_define_const(cNWScript, "FEAT_EPIC_SKILL_FOCUS_LORE", INT2NUM(596));
    rb_define_const(cNWScript, "FEAT_EPIC_SKILL_FOCUS_MOVESILENTLY", INT2NUM(597));
    rb_define_const(cNWScript, "FEAT_EPIC_SKILL_FOCUS_OPENLOCK", INT2NUM(598));
    rb_define_const(cNWScript, "FEAT_EPIC_SKILL_FOCUS_PARRY", INT2NUM(599));
    rb_define_const(cNWScript, "FEAT_EPIC_SKILL_FOCUS_PERFORM", INT2NUM(600));
    rb_define_const(cNWScript, "FEAT_EPIC_SKILL_FOCUS_PERSUADE", INT2NUM(601));
    rb_define_const(cNWScript, "FEAT_EPIC_SKILL_FOCUS_PICKPOCKET", INT2NUM(602));
    rb_define_const(cNWScript, "FEAT_EPIC_SKILL_FOCUS_SEARCH", INT2NUM(603));
    rb_define_const(cNWScript, "FEAT_EPIC_SKILL_FOCUS_SETTRAP", INT2NUM(604));
    rb_define_const(cNWScript, "FEAT_EPIC_SKILL_FOCUS_SPELLCRAFT", INT2NUM(605));
    rb_define_const(cNWScript, "FEAT_EPIC_SKILL_FOCUS_SPOT", INT2NUM(606));
    rb_define_const(cNWScript, "FEAT_EPIC_SKILL_FOCUS_TAUNT", INT2NUM(607));
    rb_define_const(cNWScript, "FEAT_EPIC_SKILL_FOCUS_TUMBLE", INT2NUM(608));
    rb_define_const(cNWScript, "FEAT_EPIC_SKILL_FOCUS_USEMAGICDEVICE", INT2NUM(609));
    rb_define_const(cNWScript, "FEAT_EPIC_SPELL_FOCUS_ABJURATION", INT2NUM(610));
    rb_define_const(cNWScript, "FEAT_EPIC_SPELL_FOCUS_CONJURATION", INT2NUM(611));
    rb_define_const(cNWScript, "FEAT_EPIC_SPELL_FOCUS_DIVINATION", INT2NUM(612));
    rb_define_const(cNWScript, "FEAT_EPIC_SPELL_FOCUS_ENCHANTMENT", INT2NUM(613));
    rb_define_const(cNWScript, "FEAT_EPIC_SPELL_FOCUS_EVOCATION", INT2NUM(614));
    rb_define_const(cNWScript, "FEAT_EPIC_SPELL_FOCUS_ILLUSION", INT2NUM(615));
    rb_define_const(cNWScript, "FEAT_EPIC_SPELL_FOCUS_NECROMANCY", INT2NUM(616));
    rb_define_const(cNWScript, "FEAT_EPIC_SPELL_FOCUS_TRANSMUTATION", INT2NUM(617));
    rb_define_const(cNWScript, "FEAT_EPIC_SPELL_PENETRATION", INT2NUM(618));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_FOCUS_CLUB", INT2NUM(619));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_FOCUS_DAGGER", INT2NUM(620));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_FOCUS_DART", INT2NUM(621));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_FOCUS_HEAVYCROSSBOW", INT2NUM(622));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_FOCUS_LIGHTCROSSBOW", INT2NUM(623));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_FOCUS_LIGHTMACE", INT2NUM(624));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_FOCUS_MORNINGSTAR", INT2NUM(625));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_FOCUS_QUARTERSTAFF", INT2NUM(626));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_FOCUS_SHORTSPEAR", INT2NUM(627));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_FOCUS_SICKLE", INT2NUM(628));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_FOCUS_SLING", INT2NUM(629));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_FOCUS_UNARMED", INT2NUM(630));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_FOCUS_LONGBOW", INT2NUM(631));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_FOCUS_SHORTBOW", INT2NUM(632));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_FOCUS_SHORTSWORD", INT2NUM(633));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_FOCUS_RAPIER", INT2NUM(634));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_FOCUS_SCIMITAR", INT2NUM(635));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_FOCUS_LONGSWORD", INT2NUM(636));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_FOCUS_GREATSWORD", INT2NUM(637));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_FOCUS_HANDAXE", INT2NUM(638));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_FOCUS_THROWINGAXE", INT2NUM(639));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_FOCUS_BATTLEAXE", INT2NUM(640));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_FOCUS_GREATAXE", INT2NUM(641));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_FOCUS_HALBERD", INT2NUM(642));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_FOCUS_LIGHTHAMMER", INT2NUM(643));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_FOCUS_LIGHTFLAIL", INT2NUM(644));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_FOCUS_WARHAMMER", INT2NUM(645));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_FOCUS_HEAVYFLAIL", INT2NUM(646));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_FOCUS_KAMA", INT2NUM(647));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_FOCUS_KUKRI", INT2NUM(648));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_FOCUS_SHURIKEN", INT2NUM(649));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_FOCUS_SCYTHE", INT2NUM(650));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_FOCUS_KATANA", INT2NUM(651));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_FOCUS_BASTARDSWORD", INT2NUM(652));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_FOCUS_DIREMACE", INT2NUM(653));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_FOCUS_DOUBLEAXE", INT2NUM(654));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_FOCUS_TWOBLADEDSWORD", INT2NUM(655));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_FOCUS_CREATURE", INT2NUM(656));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_SPECIALIZATION_CLUB", INT2NUM(657));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_SPECIALIZATION_DAGGER", INT2NUM(658));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_SPECIALIZATION_DART", INT2NUM(659));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_SPECIALIZATION_HEAVYCROSSBOW", INT2NUM(660));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_SPECIALIZATION_LIGHTCROSSBOW", INT2NUM(661));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_SPECIALIZATION_LIGHTMACE", INT2NUM(662));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_SPECIALIZATION_MORNINGSTAR", INT2NUM(663));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_SPECIALIZATION_QUARTERSTAFF", INT2NUM(664));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_SPECIALIZATION_SHORTSPEAR", INT2NUM(665));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_SPECIALIZATION_SICKLE", INT2NUM(666));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_SPECIALIZATION_SLING", INT2NUM(667));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_SPECIALIZATION_UNARMED", INT2NUM(668));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_SPECIALIZATION_LONGBOW", INT2NUM(669));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_SPECIALIZATION_SHORTBOW", INT2NUM(670));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_SPECIALIZATION_SHORTSWORD", INT2NUM(671));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_SPECIALIZATION_RAPIER", INT2NUM(672));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_SPECIALIZATION_SCIMITAR", INT2NUM(673));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_SPECIALIZATION_LONGSWORD", INT2NUM(674));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_SPECIALIZATION_GREATSWORD", INT2NUM(675));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_SPECIALIZATION_HANDAXE", INT2NUM(676));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_SPECIALIZATION_THROWINGAXE", INT2NUM(677));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_SPECIALIZATION_BATTLEAXE", INT2NUM(678));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_SPECIALIZATION_GREATAXE", INT2NUM(679));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_SPECIALIZATION_HALBERD", INT2NUM(680));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_SPECIALIZATION_LIGHTHAMMER", INT2NUM(681));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_SPECIALIZATION_LIGHTFLAIL", INT2NUM(682));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_SPECIALIZATION_WARHAMMER", INT2NUM(683));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_SPECIALIZATION_HEAVYFLAIL", INT2NUM(684));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_SPECIALIZATION_KAMA", INT2NUM(685));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_SPECIALIZATION_KUKRI", INT2NUM(686));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_SPECIALIZATION_SHURIKEN", INT2NUM(687));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_SPECIALIZATION_SCYTHE", INT2NUM(688));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_SPECIALIZATION_KATANA", INT2NUM(689));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_SPECIALIZATION_BASTARDSWORD", INT2NUM(690));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_SPECIALIZATION_DIREMACE", INT2NUM(691));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_SPECIALIZATION_DOUBLEAXE", INT2NUM(692));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_SPECIALIZATION_TWOBLADEDSWORD", INT2NUM(693));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_SPECIALIZATION_CREATURE", INT2NUM(694));
    rb_define_const(cNWScript, "FEAT_EPIC_WILL", INT2NUM(695));
    rb_define_const(cNWScript, "FEAT_EPIC_IMPROVED_COMBAT_CASTING", INT2NUM(696));
    rb_define_const(cNWScript, "FEAT_EPIC_IMPROVED_KI_STRIKE_4", INT2NUM(697));
    rb_define_const(cNWScript, "FEAT_EPIC_IMPROVED_KI_STRIKE_5", INT2NUM(698));
    rb_define_const(cNWScript, "FEAT_EPIC_IMPROVED_SPELL_RESISTANCE_1", INT2NUM(699));
    rb_define_const(cNWScript, "FEAT_EPIC_IMPROVED_SPELL_RESISTANCE_2", INT2NUM(700));
    rb_define_const(cNWScript, "FEAT_EPIC_IMPROVED_SPELL_RESISTANCE_3", INT2NUM(701));
    rb_define_const(cNWScript, "FEAT_EPIC_IMPROVED_SPELL_RESISTANCE_4", INT2NUM(702));
    rb_define_const(cNWScript, "FEAT_EPIC_IMPROVED_SPELL_RESISTANCE_5", INT2NUM(703));
    rb_define_const(cNWScript, "FEAT_EPIC_IMPROVED_SPELL_RESISTANCE_6", INT2NUM(704));
    rb_define_const(cNWScript, "FEAT_EPIC_IMPROVED_SPELL_RESISTANCE_7", INT2NUM(705));
    rb_define_const(cNWScript, "FEAT_EPIC_IMPROVED_SPELL_RESISTANCE_8", INT2NUM(706));
    rb_define_const(cNWScript, "FEAT_EPIC_IMPROVED_SPELL_RESISTANCE_9", INT2NUM(707));
    rb_define_const(cNWScript, "FEAT_EPIC_IMPROVED_SPELL_RESISTANCE_10", INT2NUM(708));
    rb_define_const(cNWScript, "FEAT_EPIC_OVERWHELMING_CRITICAL_CLUB", INT2NUM(709));
    rb_define_const(cNWScript, "FEAT_EPIC_OVERWHELMING_CRITICAL_DAGGER", INT2NUM(710));
    rb_define_const(cNWScript, "FEAT_EPIC_OVERWHELMING_CRITICAL_DART", INT2NUM(711));
    rb_define_const(cNWScript, "FEAT_EPIC_OVERWHELMING_CRITICAL_HEAVYCROSSBOW", INT2NUM(712));
    rb_define_const(cNWScript, "FEAT_EPIC_OVERWHELMING_CRITICAL_LIGHTCROSSBOW", INT2NUM(713));
    rb_define_const(cNWScript, "FEAT_EPIC_OVERWHELMING_CRITICAL_LIGHTMACE", INT2NUM(714));
    rb_define_const(cNWScript, "FEAT_EPIC_OVERWHELMING_CRITICAL_MORNINGSTAR", INT2NUM(715));
    rb_define_const(cNWScript, "FEAT_EPIC_OVERWHELMING_CRITICAL_QUARTERSTAFF", INT2NUM(716));
    rb_define_const(cNWScript, "FEAT_EPIC_OVERWHELMING_CRITICAL_SHORTSPEAR", INT2NUM(717));
    rb_define_const(cNWScript, "FEAT_EPIC_OVERWHELMING_CRITICAL_SICKLE", INT2NUM(718));
    rb_define_const(cNWScript, "FEAT_EPIC_OVERWHELMING_CRITICAL_SLING", INT2NUM(719));
    rb_define_const(cNWScript, "FEAT_EPIC_OVERWHELMING_CRITICAL_UNARMED", INT2NUM(720));
    rb_define_const(cNWScript, "FEAT_EPIC_OVERWHELMING_CRITICAL_LONGBOW", INT2NUM(721));
    rb_define_const(cNWScript, "FEAT_EPIC_OVERWHELMING_CRITICAL_SHORTBOW", INT2NUM(722));
    rb_define_const(cNWScript, "FEAT_EPIC_OVERWHELMING_CRITICAL_SHORTSWORD", INT2NUM(723));
    rb_define_const(cNWScript, "FEAT_EPIC_OVERWHELMING_CRITICAL_RAPIER", INT2NUM(724));
    rb_define_const(cNWScript, "FEAT_EPIC_OVERWHELMING_CRITICAL_SCIMITAR", INT2NUM(725));
    rb_define_const(cNWScript, "FEAT_EPIC_OVERWHELMING_CRITICAL_LONGSWORD", INT2NUM(726));
    rb_define_const(cNWScript, "FEAT_EPIC_OVERWHELMING_CRITICAL_GREATSWORD", INT2NUM(727));
    rb_define_const(cNWScript, "FEAT_EPIC_OVERWHELMING_CRITICAL_HANDAXE", INT2NUM(728));
    rb_define_const(cNWScript, "FEAT_EPIC_OVERWHELMING_CRITICAL_THROWINGAXE", INT2NUM(729));
    rb_define_const(cNWScript, "FEAT_EPIC_OVERWHELMING_CRITICAL_BATTLEAXE", INT2NUM(730));
    rb_define_const(cNWScript, "FEAT_EPIC_OVERWHELMING_CRITICAL_GREATAXE", INT2NUM(731));
    rb_define_const(cNWScript, "FEAT_EPIC_OVERWHELMING_CRITICAL_HALBERD", INT2NUM(732));
    rb_define_const(cNWScript, "FEAT_EPIC_OVERWHELMING_CRITICAL_LIGHTHAMMER", INT2NUM(733));
    rb_define_const(cNWScript, "FEAT_EPIC_OVERWHELMING_CRITICAL_LIGHTFLAIL", INT2NUM(734));
    rb_define_const(cNWScript, "FEAT_EPIC_OVERWHELMING_CRITICAL_WARHAMMER", INT2NUM(735));
    rb_define_const(cNWScript, "FEAT_EPIC_OVERWHELMING_CRITICAL_HEAVYFLAIL", INT2NUM(736));
    rb_define_const(cNWScript, "FEAT_EPIC_OVERWHELMING_CRITICAL_KAMA", INT2NUM(737));
    rb_define_const(cNWScript, "FEAT_EPIC_OVERWHELMING_CRITICAL_KUKRI", INT2NUM(738));
    rb_define_const(cNWScript, "FEAT_EPIC_OVERWHELMING_CRITICAL_SHURIKEN", INT2NUM(739));
    rb_define_const(cNWScript, "FEAT_EPIC_OVERWHELMING_CRITICAL_SCYTHE", INT2NUM(740));
    rb_define_const(cNWScript, "FEAT_EPIC_OVERWHELMING_CRITICAL_KATANA", INT2NUM(741));
    rb_define_const(cNWScript, "FEAT_EPIC_OVERWHELMING_CRITICAL_BASTARDSWORD", INT2NUM(742));
    rb_define_const(cNWScript, "FEAT_EPIC_OVERWHELMING_CRITICAL_DIREMACE", INT2NUM(743));
    rb_define_const(cNWScript, "FEAT_EPIC_OVERWHELMING_CRITICAL_DOUBLEAXE", INT2NUM(744));
    rb_define_const(cNWScript, "FEAT_EPIC_OVERWHELMING_CRITICAL_TWOBLADEDSWORD", INT2NUM(745));
    rb_define_const(cNWScript, "FEAT_EPIC_OVERWHELMING_CRITICAL_CREATURE", INT2NUM(746));
    rb_define_const(cNWScript, "FEAT_EPIC_PERFECT_HEALTH", INT2NUM(747));
    rb_define_const(cNWScript, "FEAT_EPIC_SELF_CONCEALMENT_10", INT2NUM(748));
    rb_define_const(cNWScript, "FEAT_EPIC_SELF_CONCEALMENT_20", INT2NUM(749));
    rb_define_const(cNWScript, "FEAT_EPIC_SELF_CONCEALMENT_30", INT2NUM(750));
    rb_define_const(cNWScript, "FEAT_EPIC_SELF_CONCEALMENT_40", INT2NUM(751));
    rb_define_const(cNWScript, "FEAT_EPIC_SELF_CONCEALMENT_50", INT2NUM(752));
    rb_define_const(cNWScript, "FEAT_EPIC_SUPERIOR_INITIATIVE", INT2NUM(753));
    rb_define_const(cNWScript, "FEAT_EPIC_TOUGHNESS_1", INT2NUM(754));
    rb_define_const(cNWScript, "FEAT_EPIC_TOUGHNESS_2", INT2NUM(755));
    rb_define_const(cNWScript, "FEAT_EPIC_TOUGHNESS_3", INT2NUM(756));
    rb_define_const(cNWScript, "FEAT_EPIC_TOUGHNESS_4", INT2NUM(757));
    rb_define_const(cNWScript, "FEAT_EPIC_TOUGHNESS_5", INT2NUM(758));
    rb_define_const(cNWScript, "FEAT_EPIC_TOUGHNESS_6", INT2NUM(759));
    rb_define_const(cNWScript, "FEAT_EPIC_TOUGHNESS_7", INT2NUM(760));
    rb_define_const(cNWScript, "FEAT_EPIC_TOUGHNESS_8", INT2NUM(761));
    rb_define_const(cNWScript, "FEAT_EPIC_TOUGHNESS_9", INT2NUM(762));
    rb_define_const(cNWScript, "FEAT_EPIC_TOUGHNESS_10", INT2NUM(763));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_CHARISMA_1", INT2NUM(764));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_CHARISMA_2", INT2NUM(765));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_CHARISMA_3", INT2NUM(766));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_CHARISMA_4", INT2NUM(767));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_CHARISMA_5", INT2NUM(768));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_CHARISMA_6", INT2NUM(769));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_CHARISMA_7", INT2NUM(770));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_CHARISMA_8", INT2NUM(771));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_CHARISMA_9", INT2NUM(772));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_CHARISMA_10", INT2NUM(773));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_CONSTITUTION_1", INT2NUM(774));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_CONSTITUTION_2", INT2NUM(775));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_CONSTITUTION_3", INT2NUM(776));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_CONSTITUTION_4", INT2NUM(777));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_CONSTITUTION_5", INT2NUM(778));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_CONSTITUTION_6", INT2NUM(779));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_CONSTITUTION_7", INT2NUM(780));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_CONSTITUTION_8", INT2NUM(781));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_CONSTITUTION_9", INT2NUM(782));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_CONSTITUTION_10", INT2NUM(783));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_DEXTERITY_1", INT2NUM(784));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_DEXTERITY_2", INT2NUM(785));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_DEXTERITY_3", INT2NUM(786));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_DEXTERITY_4", INT2NUM(787));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_DEXTERITY_5", INT2NUM(788));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_DEXTERITY_6", INT2NUM(789));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_DEXTERITY_7", INT2NUM(790));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_DEXTERITY_8", INT2NUM(791));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_DEXTERITY_9", INT2NUM(792));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_DEXTERITY_10", INT2NUM(793));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_INTELLIGENCE_1", INT2NUM(794));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_INTELLIGENCE_2", INT2NUM(795));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_INTELLIGENCE_3", INT2NUM(796));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_INTELLIGENCE_4", INT2NUM(797));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_INTELLIGENCE_5", INT2NUM(798));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_INTELLIGENCE_6", INT2NUM(799));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_INTELLIGENCE_7", INT2NUM(800));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_INTELLIGENCE_8", INT2NUM(801));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_INTELLIGENCE_9", INT2NUM(802));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_INTELLIGENCE_10", INT2NUM(803));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_WISDOM_1", INT2NUM(804));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_WISDOM_2", INT2NUM(805));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_WISDOM_3", INT2NUM(806));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_WISDOM_4", INT2NUM(807));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_WISDOM_5", INT2NUM(808));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_WISDOM_6", INT2NUM(809));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_WISDOM_7", INT2NUM(810));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_WISDOM_8", INT2NUM(811));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_WISDOM_9", INT2NUM(812));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_WISDOM_10", INT2NUM(813));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_STRENGTH_1", INT2NUM(814));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_STRENGTH_2", INT2NUM(815));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_STRENGTH_3", INT2NUM(816));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_STRENGTH_4", INT2NUM(817));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_STRENGTH_5", INT2NUM(818));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_STRENGTH_6", INT2NUM(819));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_STRENGTH_7", INT2NUM(820));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_STRENGTH_8", INT2NUM(821));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_STRENGTH_9", INT2NUM(822));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_STRENGTH_10", INT2NUM(823));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_SMITING_1", INT2NUM(824));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_SMITING_2", INT2NUM(825));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_SMITING_3", INT2NUM(826));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_SMITING_4", INT2NUM(827));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_SMITING_5", INT2NUM(828));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_SMITING_6", INT2NUM(829));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_SMITING_7", INT2NUM(830));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_SMITING_8", INT2NUM(831));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_SMITING_9", INT2NUM(832));
    rb_define_const(cNWScript, "FEAT_EPIC_GREAT_SMITING_10", INT2NUM(833));
    rb_define_const(cNWScript, "FEAT_EPIC_IMPROVED_SNEAK_ATTACK_1", INT2NUM(834));
    rb_define_const(cNWScript, "FEAT_EPIC_IMPROVED_SNEAK_ATTACK_2", INT2NUM(835));
    rb_define_const(cNWScript, "FEAT_EPIC_IMPROVED_SNEAK_ATTACK_3", INT2NUM(836));
    rb_define_const(cNWScript, "FEAT_EPIC_IMPROVED_SNEAK_ATTACK_4", INT2NUM(837));
    rb_define_const(cNWScript, "FEAT_EPIC_IMPROVED_SNEAK_ATTACK_5", INT2NUM(838));
    rb_define_const(cNWScript, "FEAT_EPIC_IMPROVED_SNEAK_ATTACK_6", INT2NUM(839));
    rb_define_const(cNWScript, "FEAT_EPIC_IMPROVED_SNEAK_ATTACK_7", INT2NUM(840));
    rb_define_const(cNWScript, "FEAT_EPIC_IMPROVED_SNEAK_ATTACK_8", INT2NUM(841));
    rb_define_const(cNWScript, "FEAT_EPIC_IMPROVED_SNEAK_ATTACK_9", INT2NUM(842));
    rb_define_const(cNWScript, "FEAT_EPIC_IMPROVED_SNEAK_ATTACK_10", INT2NUM(843));
    rb_define_const(cNWScript, "FEAT_EPIC_IMPROVED_STUNNING_FIST_1", INT2NUM(844));
    rb_define_const(cNWScript, "FEAT_EPIC_IMPROVED_STUNNING_FIST_2", INT2NUM(845));
    rb_define_const(cNWScript, "FEAT_EPIC_IMPROVED_STUNNING_FIST_3", INT2NUM(846));
    rb_define_const(cNWScript, "FEAT_EPIC_IMPROVED_STUNNING_FIST_4", INT2NUM(847));
    rb_define_const(cNWScript, "FEAT_EPIC_IMPROVED_STUNNING_FIST_5", INT2NUM(848));
    rb_define_const(cNWScript, "FEAT_EPIC_IMPROVED_STUNNING_FIST_6", INT2NUM(849));
    rb_define_const(cNWScript, "FEAT_EPIC_IMPROVED_STUNNING_FIST_7", INT2NUM(850));
    rb_define_const(cNWScript, "FEAT_EPIC_IMPROVED_STUNNING_FIST_8", INT2NUM(851));
    rb_define_const(cNWScript, "FEAT_EPIC_IMPROVED_STUNNING_FIST_9", INT2NUM(852));
    rb_define_const(cNWScript, "FEAT_EPIC_IMPROVED_STUNNING_FIST_10", INT2NUM(853));
    rb_define_const(cNWScript, "FEAT_EPIC_BANE_OF_ENEMIES", INT2NUM(855));
    rb_define_const(cNWScript, "FEAT_EPIC_DODGE", INT2NUM(856));
    rb_define_const(cNWScript, "FEAT_EPIC_AUTOMATIC_QUICKEN_1", INT2NUM(857));
    rb_define_const(cNWScript, "FEAT_EPIC_AUTOMATIC_QUICKEN_2", INT2NUM(858));
    rb_define_const(cNWScript, "FEAT_EPIC_AUTOMATIC_QUICKEN_3", INT2NUM(859));
    rb_define_const(cNWScript, "FEAT_EPIC_AUTOMATIC_SILENT_SPELL_1", INT2NUM(860));
    rb_define_const(cNWScript, "FEAT_EPIC_AUTOMATIC_SILENT_SPELL_2", INT2NUM(861));
    rb_define_const(cNWScript, "FEAT_EPIC_AUTOMATIC_SILENT_SPELL_3", INT2NUM(862));
    rb_define_const(cNWScript, "FEAT_EPIC_AUTOMATIC_STILL_SPELL_1", INT2NUM(863));
    rb_define_const(cNWScript, "FEAT_EPIC_AUTOMATIC_STILL_SPELL_2", INT2NUM(864));
    rb_define_const(cNWScript, "FEAT_EPIC_AUTOMATIC_STILL_SPELL_3", INT2NUM(865));
    rb_define_const(cNWScript, "FEAT_SHOU_DISCIPLE_MARTIAL_FLURRY_LIGHT", INT2NUM(866));
    rb_define_const(cNWScript, "FEAT_WHIRLWIND_ATTACK", INT2NUM(867));
    rb_define_const(cNWScript, "FEAT_IMPROVED_WHIRLWIND", INT2NUM(868));
    rb_define_const(cNWScript, "FEAT_MIGHTY_RAGE", INT2NUM(869));
    rb_define_const(cNWScript, "FEAT_EPIC_LASTING_INSPIRATION", INT2NUM(870));
    rb_define_const(cNWScript, "FEAT_CURSE_SONG", INT2NUM(871));
    rb_define_const(cNWScript, "FEAT_EPIC_WILD_SHAPE_UNDEAD", INT2NUM(872));
    rb_define_const(cNWScript, "FEAT_EPIC_WILD_SHAPE_DRAGON", INT2NUM(873));
    rb_define_const(cNWScript, "FEAT_EPIC_SPELL_MUMMY_DUST", INT2NUM(874));
    rb_define_const(cNWScript, "FEAT_EPIC_SPELL_DRAGON_KNIGHT", INT2NUM(875));
    rb_define_const(cNWScript, "FEAT_EPIC_SPELL_HELLBALL", INT2NUM(876));
    rb_define_const(cNWScript, "FEAT_EPIC_SPELL_MAGE_ARMOUR", INT2NUM(877));
    rb_define_const(cNWScript, "FEAT_EPIC_SPELL_RUIN", INT2NUM(878));
    rb_define_const(cNWScript, "FEAT_WEAPON_OF_CHOICE_SICKLE", INT2NUM(879));
    rb_define_const(cNWScript, "FEAT_WEAPON_OF_CHOICE_KAMA", INT2NUM(880));
    rb_define_const(cNWScript, "FEAT_WEAPON_OF_CHOICE_KUKRI", INT2NUM(881));
    rb_define_const(cNWScript, "FEAT_KI_DAMAGE", INT2NUM(882));
    rb_define_const(cNWScript, "FEAT_INCREASE_MULTIPLIER", INT2NUM(883));
    rb_define_const(cNWScript, "FEAT_SUPERIOR_WEAPON_FOCUS", INT2NUM(884));
    rb_define_const(cNWScript, "FEAT_KI_CRITICAL", INT2NUM(885));
    rb_define_const(cNWScript, "FEAT_BONE_SKIN_2", INT2NUM(886));
    rb_define_const(cNWScript, "FEAT_BONE_SKIN_4", INT2NUM(887));
    rb_define_const(cNWScript, "FEAT_BONE_SKIN_6", INT2NUM(888));
    rb_define_const(cNWScript, "FEAT_ANIMATE_DEAD", INT2NUM(889));
    rb_define_const(cNWScript, "FEAT_SUMMON_UNDEAD", INT2NUM(890));
    rb_define_const(cNWScript, "FEAT_DEATHLESS_VIGOR", INT2NUM(891));
    rb_define_const(cNWScript, "FEAT_UNDEAD_GRAFT_1", INT2NUM(892));
    rb_define_const(cNWScript, "FEAT_UNDEAD_GRAFT_2", INT2NUM(893));
    rb_define_const(cNWScript, "FEAT_TOUGH_AS_BONE", INT2NUM(894));
    rb_define_const(cNWScript, "FEAT_SUMMON_GREATER_UNDEAD", INT2NUM(895));
    rb_define_const(cNWScript, "FEAT_DEATHLESS_MASTERY", INT2NUM(896));
    rb_define_const(cNWScript, "FEAT_DEATHLESS_MASTER_TOUCH", INT2NUM(897));
    rb_define_const(cNWScript, "FEAT_GREATER_WILDSHAPE_1", INT2NUM(898));
    rb_define_const(cNWScript, "FEAT_SHOU_DISCIPLE_MARTIAL_FLURRY_ANY", INT2NUM(899));
    rb_define_const(cNWScript, "FEAT_GREATER_WILDSHAPE_2", INT2NUM(900));
    rb_define_const(cNWScript, "FEAT_GREATER_WILDSHAPE_3", INT2NUM(901));
    rb_define_const(cNWScript, "FEAT_HUMANOID_SHAPE", INT2NUM(902));
    rb_define_const(cNWScript, "FEAT_GREATER_WILDSHAPE_4", INT2NUM(903));
    rb_define_const(cNWScript, "FEAT_SACRED_DEFENSE_1", INT2NUM(904));
    rb_define_const(cNWScript, "FEAT_SACRED_DEFENSE_2", INT2NUM(905));
    rb_define_const(cNWScript, "FEAT_SACRED_DEFENSE_3", INT2NUM(906));
    rb_define_const(cNWScript, "FEAT_SACRED_DEFENSE_4", INT2NUM(907));
    rb_define_const(cNWScript, "FEAT_SACRED_DEFENSE_5", INT2NUM(908));
    rb_define_const(cNWScript, "FEAT_DIVINE_WRATH", INT2NUM(909));
    rb_define_const(cNWScript, "FEAT_EXTRA_SMITING", INT2NUM(910));
    rb_define_const(cNWScript, "FEAT_SKILL_FOCUS_CRAFT_ARMOR", INT2NUM(911));
    rb_define_const(cNWScript, "FEAT_SKILL_FOCUS_CRAFT_WEAPON", INT2NUM(912));
    rb_define_const(cNWScript, "FEAT_EPIC_SKILL_FOCUS_CRAFT_ARMOR", INT2NUM(913));
    rb_define_const(cNWScript, "FEAT_EPIC_SKILL_FOCUS_CRAFT_WEAPON", INT2NUM(914));
    rb_define_const(cNWScript, "FEAT_SKILL_FOCUS_BLUFF", INT2NUM(915));
    rb_define_const(cNWScript, "FEAT_SKILL_FOCUS_INTIMIDATE", INT2NUM(916));
    rb_define_const(cNWScript, "FEAT_EPIC_SKILL_FOCUS_BLUFF", INT2NUM(917));
    rb_define_const(cNWScript, "FEAT_EPIC_SKILL_FOCUS_INTIMIDATE", INT2NUM(918));
    rb_define_const(cNWScript, "FEAT_WEAPON_OF_CHOICE_CLUB", INT2NUM(919));
    rb_define_const(cNWScript, "FEAT_WEAPON_OF_CHOICE_DAGGER", INT2NUM(920));
    rb_define_const(cNWScript, "FEAT_WEAPON_OF_CHOICE_LIGHTMACE", INT2NUM(921));
    rb_define_const(cNWScript, "FEAT_WEAPON_OF_CHOICE_MORNINGSTAR", INT2NUM(922));
    rb_define_const(cNWScript, "FEAT_WEAPON_OF_CHOICE_QUARTERSTAFF", INT2NUM(923));
    rb_define_const(cNWScript, "FEAT_WEAPON_OF_CHOICE_SHORTSPEAR", INT2NUM(924));
    rb_define_const(cNWScript, "FEAT_WEAPON_OF_CHOICE_SHORTSWORD", INT2NUM(925));
    rb_define_const(cNWScript, "FEAT_WEAPON_OF_CHOICE_RAPIER", INT2NUM(926));
    rb_define_const(cNWScript, "FEAT_WEAPON_OF_CHOICE_SCIMITAR", INT2NUM(927));
    rb_define_const(cNWScript, "FEAT_WEAPON_OF_CHOICE_LONGSWORD", INT2NUM(928));
    rb_define_const(cNWScript, "FEAT_WEAPON_OF_CHOICE_GREATSWORD", INT2NUM(929));
    rb_define_const(cNWScript, "FEAT_WEAPON_OF_CHOICE_HANDAXE", INT2NUM(930));
    rb_define_const(cNWScript, "FEAT_WEAPON_OF_CHOICE_BATTLEAXE", INT2NUM(931));
    rb_define_const(cNWScript, "FEAT_WEAPON_OF_CHOICE_GREATAXE", INT2NUM(932));
    rb_define_const(cNWScript, "FEAT_WEAPON_OF_CHOICE_HALBERD", INT2NUM(933));
    rb_define_const(cNWScript, "FEAT_WEAPON_OF_CHOICE_LIGHTHAMMER", INT2NUM(934));
    rb_define_const(cNWScript, "FEAT_WEAPON_OF_CHOICE_LIGHTFLAIL", INT2NUM(935));
    rb_define_const(cNWScript, "FEAT_WEAPON_OF_CHOICE_WARHAMMER", INT2NUM(936));
    rb_define_const(cNWScript, "FEAT_WEAPON_OF_CHOICE_HEAVYFLAIL", INT2NUM(937));
    rb_define_const(cNWScript, "FEAT_WEAPON_OF_CHOICE_SCYTHE", INT2NUM(938));
    rb_define_const(cNWScript, "FEAT_WEAPON_OF_CHOICE_KATANA", INT2NUM(939));
    rb_define_const(cNWScript, "FEAT_WEAPON_OF_CHOICE_BASTARDSWORD", INT2NUM(940));
    rb_define_const(cNWScript, "FEAT_WEAPON_OF_CHOICE_DIREMACE", INT2NUM(941));
    rb_define_const(cNWScript, "FEAT_WEAPON_OF_CHOICE_DOUBLEAXE", INT2NUM(942));
    rb_define_const(cNWScript, "FEAT_WEAPON_OF_CHOICE_TWOBLADEDSWORD", INT2NUM(943));
    rb_define_const(cNWScript, "FEAT_BREW_POTION", INT2NUM(944));
    rb_define_const(cNWScript, "FEAT_SCRIBE_SCROLL", INT2NUM(945));
    rb_define_const(cNWScript, "FEAT_CRAFT_WAND", INT2NUM(946));
    rb_define_const(cNWScript, "FEAT_DWARVEN_DEFENDER_DEFENSIVE_STANCE", INT2NUM(947));
    rb_define_const(cNWScript, "FEAT_DAMAGE_REDUCTION_6", INT2NUM(948));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_DEFENSIVE_AWARENESS_1", INT2NUM(949));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_DEFENSIVE_AWARENESS_2", INT2NUM(950));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_DEFENSIVE_AWARENESS_3", INT2NUM(951));
    rb_define_const(cNWScript, "FEAT_WEAPON_FOCUS_DWAXE", INT2NUM(952));
    rb_define_const(cNWScript, "FEAT_WEAPON_SPECIALIZATION_DWAXE", INT2NUM(953));
    rb_define_const(cNWScript, "FEAT_IMPROVED_CRITICAL_DWAXE", INT2NUM(954));
    rb_define_const(cNWScript, "FEAT_EPIC_DEVASTATING_CRITICAL_DWAXE", INT2NUM(955));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_FOCUS_DWAXE", INT2NUM(956));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_SPECIALIZATION_DWAXE", INT2NUM(957));
    rb_define_const(cNWScript, "FEAT_EPIC_OVERWHELMING_CRITICAL_DWAXE", INT2NUM(958));
    rb_define_const(cNWScript, "FEAT_WEAPON_OF_CHOICE_DWAXE", INT2NUM(959));
    rb_define_const(cNWScript, "FEAT_USE_POISON", INT2NUM(960));
    rb_define_const(cNWScript, "FEAT_DRAGON_ARMOR", INT2NUM(961));
    rb_define_const(cNWScript, "FEAT_DRAGON_ABILITIES", INT2NUM(962));
    rb_define_const(cNWScript, "FEAT_DRAGON_IMMUNE_PARALYSIS", INT2NUM(963));
    rb_define_const(cNWScript, "FEAT_DRAGON_IMMUNE_FIRE", INT2NUM(964));
    rb_define_const(cNWScript, "FEAT_DRAGON_DIS_BREATH", INT2NUM(965));
    rb_define_const(cNWScript, "FEAT_EPIC_FIGHTER", INT2NUM(966));
    rb_define_const(cNWScript, "FEAT_EPIC_BARBARIAN", INT2NUM(967));
    rb_define_const(cNWScript, "FEAT_EPIC_BARD", INT2NUM(968));
    rb_define_const(cNWScript, "FEAT_EPIC_CLERIC", INT2NUM(969));
    rb_define_const(cNWScript, "FEAT_EPIC_DRUID", INT2NUM(970));
    rb_define_const(cNWScript, "FEAT_EPIC_MONK", INT2NUM(971));
    rb_define_const(cNWScript, "FEAT_EPIC_PALADIN", INT2NUM(972));
    rb_define_const(cNWScript, "FEAT_EPIC_RANGER", INT2NUM(973));
    rb_define_const(cNWScript, "FEAT_EPIC_ROGUE", INT2NUM(974));
    rb_define_const(cNWScript, "FEAT_EPIC_SORCERER", INT2NUM(975));
    rb_define_const(cNWScript, "FEAT_EPIC_WIZARD", INT2NUM(976));
    rb_define_const(cNWScript, "FEAT_EPIC_ARCANE_ARCHER", INT2NUM(977));
    rb_define_const(cNWScript, "FEAT_EPIC_ASSASSIN", INT2NUM(978));
    rb_define_const(cNWScript, "FEAT_EPIC_BLACKGUARD", INT2NUM(979));
    rb_define_const(cNWScript, "FEAT_EPIC_SHADOWDANCER", INT2NUM(980));
    rb_define_const(cNWScript, "FEAT_EPIC_HARPER_SCOUT", INT2NUM(981));
    rb_define_const(cNWScript, "FEAT_EPIC_DIVINE_CHAMPION", INT2NUM(982));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_MASTER", INT2NUM(983));
    rb_define_const(cNWScript, "FEAT_EPIC_PALE_MASTER", INT2NUM(984));
    rb_define_const(cNWScript, "FEAT_EPIC_DWARVEN_DEFENDER", INT2NUM(985));
    rb_define_const(cNWScript, "FEAT_EPIC_SHIFTER", INT2NUM(986));
    rb_define_const(cNWScript, "FEAT_EPIC_RED_DRAGON_DISC", INT2NUM(987));
    rb_define_const(cNWScript, "FEAT_EPIC_THUNDERING_RAGE", INT2NUM(988));
    rb_define_const(cNWScript, "FEAT_EPIC_TERRIFYING_RAGE", INT2NUM(989));
    rb_define_const(cNWScript, "FEAT_EPIC_SPELL_EPIC_WARDING", INT2NUM(990));
    rb_define_const(cNWScript, "FEAT_WEAPON_FOCUS_WHIP", INT2NUM(993));
    rb_define_const(cNWScript, "FEAT_WEAPON_SPECIALIZATION_WHIP", INT2NUM(994));
    rb_define_const(cNWScript, "FEAT_IMPROVED_CRITICAL_WHIP", INT2NUM(995));
    rb_define_const(cNWScript, "FEAT_EPIC_DEVASTATING_CRITICAL_WHIP", INT2NUM(996));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_FOCUS_WHIP", INT2NUM(997));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_SPECIALIZATION_WHIP", INT2NUM(998));
    rb_define_const(cNWScript, "FEAT_EPIC_OVERWHELMING_CRITICAL_WHIP", INT2NUM(999));
    rb_define_const(cNWScript, "FEAT_WEAPON_OF_CHOICE_WHIP", INT2NUM(1000));
    rb_define_const(cNWScript, "FEAT_EPIC_CHARACTER", INT2NUM(1001));
    rb_define_const(cNWScript, "FEAT_EPIC_EPIC_SHADOWLORD", INT2NUM(1002));
    rb_define_const(cNWScript, "FEAT_EPIC_EPIC_FIEND", INT2NUM(1003));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_DEATH_ATTACK_6", INT2NUM(1004));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_DEATH_ATTACK_7", INT2NUM(1005));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_DEATH_ATTACK_8", INT2NUM(1006));
    rb_define_const(cNWScript, "FEAT_BLACKGUARD_SNEAK_ATTACK_4D6", INT2NUM(1007));
    rb_define_const(cNWScript, "FEAT_BLACKGUARD_SNEAK_ATTACK_5D6", INT2NUM(1008));
    rb_define_const(cNWScript, "FEAT_BLACKGUARD_SNEAK_ATTACK_6D6", INT2NUM(1009));
    rb_define_const(cNWScript, "FEAT_BLACKGUARD_SNEAK_ATTACK_7D6", INT2NUM(1010));
    rb_define_const(cNWScript, "FEAT_BLACKGUARD_SNEAK_ATTACK_8D6", INT2NUM(1011));
    rb_define_const(cNWScript, "FEAT_BLACKGUARD_SNEAK_ATTACK_9D6", INT2NUM(1012));
    rb_define_const(cNWScript, "FEAT_BLACKGUARD_SNEAK_ATTACK_10D6", INT2NUM(1013));
    rb_define_const(cNWScript, "FEAT_BLACKGUARD_SNEAK_ATTACK_11D6", INT2NUM(1014));
    rb_define_const(cNWScript, "FEAT_BLACKGUARD_SNEAK_ATTACK_12D6", INT2NUM(1015));
    rb_define_const(cNWScript, "FEAT_BLACKGUARD_SNEAK_ATTACK_13D6", INT2NUM(1016));
    rb_define_const(cNWScript, "FEAT_BLACKGUARD_SNEAK_ATTACK_14D6", INT2NUM(1017));
    rb_define_const(cNWScript, "FEAT_BLACKGUARD_SNEAK_ATTACK_15D6", INT2NUM(1018));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_DEATH_ATTACK_9", INT2NUM(1019));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_DEATH_ATTACK_10", INT2NUM(1020));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_DEATH_ATTACK_11", INT2NUM(1021));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_DEATH_ATTACK_12", INT2NUM(1022));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_DEATH_ATTACK_13", INT2NUM(1023));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_DEATH_ATTACK_14", INT2NUM(1024));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_DEATH_ATTACK_15", INT2NUM(1025));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_DEATH_ATTACK_16", INT2NUM(1026));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_DEATH_ATTACK_17", INT2NUM(1027));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_DEATH_ATTACK_18", INT2NUM(1028));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_DEATH_ATTACK_19", INT2NUM(1029));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_DEATH_ATTACK_20", INT2NUM(1030));
    rb_define_const(cNWScript, "FEAT_SHOU_DISCIPLE_DODGE_3", INT2NUM(1031));
    rb_define_const(cNWScript, "FEAT_DRAGON_HDINCREASE_D6", INT2NUM(1042));
    rb_define_const(cNWScript, "FEAT_DRAGON_HDINCREASE_D8", INT2NUM(1043));
    rb_define_const(cNWScript, "FEAT_DRAGON_HDINCREASE_D10", INT2NUM(1044));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_ENCHANT_ARROW_6", INT2NUM(1045));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_ENCHANT_ARROW_7", INT2NUM(1046));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_ENCHANT_ARROW_8", INT2NUM(1047));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_ENCHANT_ARROW_9", INT2NUM(1048));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_ENCHANT_ARROW_10", INT2NUM(1049));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_ENCHANT_ARROW_11", INT2NUM(1050));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_ENCHANT_ARROW_12", INT2NUM(1051));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_ENCHANT_ARROW_13", INT2NUM(1052));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_ENCHANT_ARROW_14", INT2NUM(1053));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_ENCHANT_ARROW_15", INT2NUM(1054));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_ENCHANT_ARROW_16", INT2NUM(1055));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_ENCHANT_ARROW_17", INT2NUM(1056));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_ENCHANT_ARROW_18", INT2NUM(1057));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_ENCHANT_ARROW_19", INT2NUM(1058));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_ENCHANT_ARROW_20", INT2NUM(1059));
    rb_define_const(cNWScript, "FEAT_EPIC_OUTSIDER_SHAPE", INT2NUM(1060));
    rb_define_const(cNWScript, "FEAT_EPIC_CONSTRUCT_SHAPE", INT2NUM(1061));
    rb_define_const(cNWScript, "FEAT_EPIC_SHIFTER_INFINITE_WILDSHAPE_1", INT2NUM(1062));
    rb_define_const(cNWScript, "FEAT_EPIC_SHIFTER_INFINITE_WILDSHAPE_2", INT2NUM(1063));
    rb_define_const(cNWScript, "FEAT_EPIC_SHIFTER_INFINITE_WILDSHAPE_3", INT2NUM(1064));
    rb_define_const(cNWScript, "FEAT_EPIC_SHIFTER_INFINITE_WILDSHAPE_4", INT2NUM(1065));
    rb_define_const(cNWScript, "FEAT_EPIC_SHIFTER_INFINITE_HUMANOID_SHAPE", INT2NUM(1066));
    rb_define_const(cNWScript, "FEAT_EPIC_BARBARIAN_DAMAGE_REDUCTION", INT2NUM(1067));
    rb_define_const(cNWScript, "FEAT_EPIC_DRUID_INFINITE_WILDSHAPE", INT2NUM(1068));
    rb_define_const(cNWScript, "FEAT_EPIC_DRUID_INFINITE_ELEMENTAL_SHAPE", INT2NUM(1069));
    rb_define_const(cNWScript, "FEAT_PRESTIGE_POISON_SAVE_EPIC", INT2NUM(1070));
    rb_define_const(cNWScript, "FEAT_EPIC_SUPERIOR_WEAPON_FOCUS", INT2NUM(1071));
    rb_define_const(cNWScript, "FEAT_WEAPON_FOCUS_TRIDENT", INT2NUM(1072));
    rb_define_const(cNWScript, "FEAT_WEAPON_SPECIALIZATION_TRIDENT", INT2NUM(1073));
    rb_define_const(cNWScript, "FEAT_IMPROVED_CRITICAL_TRIDENT", INT2NUM(1074));
    rb_define_const(cNWScript, "FEAT_EPIC_DEVASTATING_CRITICAL_TRIDENT", INT2NUM(1075));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_FOCUS_TRIDENT", INT2NUM(1076));
    rb_define_const(cNWScript, "FEAT_EPIC_WEAPON_SPECIALIZATION_TRIDENT", INT2NUM(1077));
    rb_define_const(cNWScript, "FEAT_EPIC_OVERWHELMING_CRITICAL_TRIDENT", INT2NUM(1078));
    rb_define_const(cNWScript, "FEAT_WEAPON_OF_CHOICE_TRIDENT", INT2NUM(1079));
    rb_define_const(cNWScript, "FEAT_PDK_RALLY", INT2NUM(1080));
    rb_define_const(cNWScript, "FEAT_PDK_SHIELD", INT2NUM(1081));
    rb_define_const(cNWScript, "FEAT_PDK_FEAR", INT2NUM(1082));
    rb_define_const(cNWScript, "FEAT_PDK_WRATH", INT2NUM(1083));
    rb_define_const(cNWScript, "FEAT_PDK_STAND", INT2NUM(1084));
    rb_define_const(cNWScript, "FEAT_PDK_INSPIRE_1", INT2NUM(1085));
    rb_define_const(cNWScript, "FEAT_PDK_INSPIRE_2", INT2NUM(1086));
    rb_define_const(cNWScript, "FEAT_MOUNTED_COMBAT", INT2NUM(1087));
    rb_define_const(cNWScript, "FEAT_MOUNTED_ARCHERY", INT2NUM(1088));
    rb_define_const(cNWScript, "FEAT_HORSE_MENU", INT2NUM(1089));
    rb_define_const(cNWScript, "FEAT_HORSE_MOUNT", INT2NUM(1090));
    rb_define_const(cNWScript, "FEAT_HORSE_DISMOUNT", INT2NUM(1091));
    rb_define_const(cNWScript, "FEAT_HORSE_PARTY_MOUNT", INT2NUM(1092));
    rb_define_const(cNWScript, "FEAT_HORSE_PARTY_DISMOUNT", INT2NUM(1093));
    rb_define_const(cNWScript, "FEAT_HORSE_ASSIGN_MOUNT", INT2NUM(1094));
    rb_define_const(cNWScript, "FEAT_PALADIN_SUMMON_MOUNT", INT2NUM(1095));
    rb_define_const(cNWScript, "FEAT_PLAYER_TOOL_01", INT2NUM(1106));
    rb_define_const(cNWScript, "FEAT_PLAYER_TOOL_02", INT2NUM(1107));
    rb_define_const(cNWScript, "FEAT_PLAYER_TOOL_03", INT2NUM(1108));
    rb_define_const(cNWScript, "FEAT_PLAYER_TOOL_04", INT2NUM(1109));
    rb_define_const(cNWScript, "FEAT_PLAYER_TOOL_05", INT2NUM(1110));
    rb_define_const(cNWScript, "FEAT_PLAYER_TOOL_06", INT2NUM(1111));
    rb_define_const(cNWScript, "FEAT_PLAYER_TOOL_07", INT2NUM(1112));
    rb_define_const(cNWScript, "FEAT_PLAYER_TOOL_08", INT2NUM(1113));
    rb_define_const(cNWScript, "FEAT_PLAYER_TOOL_09", INT2NUM(1114));
    rb_define_const(cNWScript, "FEAT_PLAYER_TOOL_10", INT2NUM(1115));
    rb_define_const(cNWScript, "SPECIAL_ATTACK_INVALID", INT2NUM(0));
    rb_define_const(cNWScript, "SPECIAL_ATTACK_CALLED_SHOT_LEG", INT2NUM(1));
    rb_define_const(cNWScript, "SPECIAL_ATTACK_CALLED_SHOT_ARM", INT2NUM(2));
    rb_define_const(cNWScript, "SPECIAL_ATTACK_SAP", INT2NUM(3));
    rb_define_const(cNWScript, "SPECIAL_ATTACK_DISARM", INT2NUM(4));
    rb_define_const(cNWScript, "SPECIAL_ATTACK_IMPROVED_DISARM", INT2NUM(5));
    rb_define_const(cNWScript, "SPECIAL_ATTACK_KNOCKDOWN", INT2NUM(6));
    rb_define_const(cNWScript, "SPECIAL_ATTACK_IMPROVED_KNOCKDOWN", INT2NUM(7));
    rb_define_const(cNWScript, "SPECIAL_ATTACK_STUNNING_FIST", INT2NUM(8));
    rb_define_const(cNWScript, "SPECIAL_ATTACK_FLURRY_OF_BLOWS", INT2NUM(9));
    rb_define_const(cNWScript, "SPECIAL_ATTACK_RAPID_SHOT", INT2NUM(10));
    rb_define_const(cNWScript, "COMBAT_MODE_INVALID", INT2NUM(0));
    rb_define_const(cNWScript, "COMBAT_MODE_PARRY", INT2NUM(1));
    rb_define_const(cNWScript, "COMBAT_MODE_POWER_ATTACK", INT2NUM(2));
    rb_define_const(cNWScript, "COMBAT_MODE_IMPROVED_POWER_ATTACK", INT2NUM(3));
    rb_define_const(cNWScript, "COMBAT_MODE_FLURRY_OF_BLOWS", INT2NUM(4));
    rb_define_const(cNWScript, "COMBAT_MODE_RAPID_SHOT", INT2NUM(5));
    rb_define_const(cNWScript, "COMBAT_MODE_EXPERTISE", INT2NUM(6));
    rb_define_const(cNWScript, "COMBAT_MODE_IMPROVED_EXPERTISE", INT2NUM(7));
    rb_define_const(cNWScript, "COMBAT_MODE_DEFENSIVE_CASTING", INT2NUM(8));
    rb_define_const(cNWScript, "COMBAT_MODE_DIRTY_FIGHTING", INT2NUM(9));
    rb_define_const(cNWScript, "COMBAT_MODE_DEFENSIVE_STANCE", INT2NUM(10));
    rb_define_const(cNWScript, "ENCOUNTER_DIFFICULTY_VERY_EASY", INT2NUM(0));
    rb_define_const(cNWScript, "ENCOUNTER_DIFFICULTY_EASY", INT2NUM(1));
    rb_define_const(cNWScript, "ENCOUNTER_DIFFICULTY_NORMAL", INT2NUM(2));
    rb_define_const(cNWScript, "ENCOUNTER_DIFFICULTY_HARD", INT2NUM(3));
    rb_define_const(cNWScript, "ENCOUNTER_DIFFICULTY_IMPOSSIBLE", INT2NUM(4));
    rb_define_const(cNWScript, "ANIMATION_LOOPING_PAUSE", INT2NUM(0));
    rb_define_const(cNWScript, "ANIMATION_LOOPING_PAUSE2", INT2NUM(1));
    rb_define_const(cNWScript, "ANIMATION_LOOPING_LISTEN", INT2NUM(2));
    rb_define_const(cNWScript, "ANIMATION_LOOPING_MEDITATE", INT2NUM(3));
    rb_define_const(cNWScript, "ANIMATION_LOOPING_WORSHIP", INT2NUM(4));
    rb_define_const(cNWScript, "ANIMATION_LOOPING_LOOK_FAR", INT2NUM(5));
    rb_define_const(cNWScript, "ANIMATION_LOOPING_SIT_CHAIR", INT2NUM(6));
    rb_define_const(cNWScript, "ANIMATION_LOOPING_SIT_CROSS", INT2NUM(7));
    rb_define_const(cNWScript, "ANIMATION_LOOPING_TALK_NORMAL", INT2NUM(8));
    rb_define_const(cNWScript, "ANIMATION_LOOPING_TALK_PLEADING", INT2NUM(9));
    rb_define_const(cNWScript, "ANIMATION_LOOPING_TALK_FORCEFUL", INT2NUM(10));
    rb_define_const(cNWScript, "ANIMATION_LOOPING_TALK_LAUGHING", INT2NUM(11));
    rb_define_const(cNWScript, "ANIMATION_LOOPING_GET_LOW", INT2NUM(12));
    rb_define_const(cNWScript, "ANIMATION_LOOPING_GET_MID", INT2NUM(13));
    rb_define_const(cNWScript, "ANIMATION_LOOPING_PAUSE_TIRED", INT2NUM(14));
    rb_define_const(cNWScript, "ANIMATION_LOOPING_PAUSE_DRUNK", INT2NUM(15));
    rb_define_const(cNWScript, "ANIMATION_LOOPING_DEAD_FRONT", INT2NUM(16));
    rb_define_const(cNWScript, "ANIMATION_LOOPING_DEAD_BACK", INT2NUM(17));
    rb_define_const(cNWScript, "ANIMATION_LOOPING_CONJURE1", INT2NUM(18));
    rb_define_const(cNWScript, "ANIMATION_LOOPING_CONJURE2", INT2NUM(19));
    rb_define_const(cNWScript, "ANIMATION_LOOPING_SPASM", INT2NUM(20));
    rb_define_const(cNWScript, "ANIMATION_LOOPING_CUSTOM1", INT2NUM(21));
    rb_define_const(cNWScript, "ANIMATION_LOOPING_CUSTOM2", INT2NUM(22));
    rb_define_const(cNWScript, "ANIMATION_LOOPING_CUSTOM3", INT2NUM(23));
    rb_define_const(cNWScript, "ANIMATION_LOOPING_CUSTOM4", INT2NUM(24));
    rb_define_const(cNWScript, "ANIMATION_LOOPING_CUSTOM5", INT2NUM(25));
    rb_define_const(cNWScript, "ANIMATION_LOOPING_CUSTOM6", INT2NUM(26));
    rb_define_const(cNWScript, "ANIMATION_LOOPING_CUSTOM7", INT2NUM(27));
    rb_define_const(cNWScript, "ANIMATION_LOOPING_CUSTOM8", INT2NUM(28));
    rb_define_const(cNWScript, "ANIMATION_LOOPING_CUSTOM9", INT2NUM(29));
    rb_define_const(cNWScript, "ANIMATION_LOOPING_CUSTOM10", INT2NUM(30));
    rb_define_const(cNWScript, "ANIMATION_LOOPING_CUSTOM11", INT2NUM(31));
    rb_define_const(cNWScript, "ANIMATION_LOOPING_CUSTOM12", INT2NUM(32));
    rb_define_const(cNWScript, "ANIMATION_LOOPING_CUSTOM13", INT2NUM(33));
    rb_define_const(cNWScript, "ANIMATION_LOOPING_CUSTOM14", INT2NUM(34));
    rb_define_const(cNWScript, "ANIMATION_LOOPING_CUSTOM15", INT2NUM(35));
    rb_define_const(cNWScript, "ANIMATION_LOOPING_CUSTOM16", INT2NUM(36));
    rb_define_const(cNWScript, "ANIMATION_LOOPING_CUSTOM17", INT2NUM(37));
    rb_define_const(cNWScript, "ANIMATION_LOOPING_CUSTOM18", INT2NUM(38));
    rb_define_const(cNWScript, "ANIMATION_LOOPING_CUSTOM19", INT2NUM(39));
    rb_define_const(cNWScript, "ANIMATION_LOOPING_CUSTOM20", INT2NUM(40));
    rb_define_const(cNWScript, "ANIMATION_MOUNT1", INT2NUM(41));
    rb_define_const(cNWScript, "ANIMATION_DISMOUNT1", INT2NUM(42));
    rb_define_const(cNWScript, "ANIMATION_FIREFORGET_HEAD_TURN_LEFT", INT2NUM(100));
    rb_define_const(cNWScript, "ANIMATION_FIREFORGET_HEAD_TURN_RIGHT", INT2NUM(101));
    rb_define_const(cNWScript, "ANIMATION_FIREFORGET_PAUSE_SCRATCH_HEAD", INT2NUM(102));
    rb_define_const(cNWScript, "ANIMATION_FIREFORGET_PAUSE_BORED", INT2NUM(103));
    rb_define_const(cNWScript, "ANIMATION_FIREFORGET_SALUTE", INT2NUM(104));
    rb_define_const(cNWScript, "ANIMATION_FIREFORGET_BOW", INT2NUM(105));
    rb_define_const(cNWScript, "ANIMATION_FIREFORGET_STEAL", INT2NUM(106));
    rb_define_const(cNWScript, "ANIMATION_FIREFORGET_GREETING", INT2NUM(107));
    rb_define_const(cNWScript, "ANIMATION_FIREFORGET_TAUNT", INT2NUM(108));
    rb_define_const(cNWScript, "ANIMATION_FIREFORGET_VICTORY1", INT2NUM(109));
    rb_define_const(cNWScript, "ANIMATION_FIREFORGET_VICTORY2", INT2NUM(110));
    rb_define_const(cNWScript, "ANIMATION_FIREFORGET_VICTORY3", INT2NUM(111));
    rb_define_const(cNWScript, "ANIMATION_FIREFORGET_READ", INT2NUM(112));
    rb_define_const(cNWScript, "ANIMATION_FIREFORGET_DRINK", INT2NUM(113));
    rb_define_const(cNWScript, "ANIMATION_FIREFORGET_DODGE_SIDE", INT2NUM(114));
    rb_define_const(cNWScript, "ANIMATION_FIREFORGET_DODGE_DUCK", INT2NUM(115));
    rb_define_const(cNWScript, "ANIMATION_FIREFORGET_SPASM", INT2NUM(116));
    rb_define_const(cNWScript, "ANIMATION_PLACEABLE_ACTIVATE", INT2NUM(200));
    rb_define_const(cNWScript, "ANIMATION_PLACEABLE_DEACTIVATE", INT2NUM(201));
    rb_define_const(cNWScript, "ANIMATION_PLACEABLE_OPEN", INT2NUM(202));
    rb_define_const(cNWScript, "ANIMATION_PLACEABLE_CLOSE", INT2NUM(203));
    rb_define_const(cNWScript, "ANIMATION_DOOR_CLOSE", INT2NUM(204));
    rb_define_const(cNWScript, "ANIMATION_DOOR_OPEN1", INT2NUM(205));
    rb_define_const(cNWScript, "ANIMATION_DOOR_OPEN2", INT2NUM(206));
    rb_define_const(cNWScript, "ANIMATION_DOOR_DESTROY", INT2NUM(207));
    rb_define_const(cNWScript, "TALENT_TYPE_SPELL", INT2NUM(0));
    rb_define_const(cNWScript, "TALENT_TYPE_FEAT", INT2NUM(1));
    rb_define_const(cNWScript, "TALENT_TYPE_SKILL", INT2NUM(2));
    rb_define_const(cNWScript, "ASSOCIATE_COMMAND_STANDGROUND", INT2NUM(-2));
    rb_define_const(cNWScript, "ASSOCIATE_COMMAND_ATTACKNEAREST", INT2NUM(-3));
    rb_define_const(cNWScript, "ASSOCIATE_COMMAND_HEALMASTER", INT2NUM(-4));
    rb_define_const(cNWScript, "ASSOCIATE_COMMAND_FOLLOWMASTER", INT2NUM(-5));
    rb_define_const(cNWScript, "ASSOCIATE_COMMAND_MASTERFAILEDLOCKPICK", INT2NUM(-6));
    rb_define_const(cNWScript, "ASSOCIATE_COMMAND_GUARDMASTER", INT2NUM(-7));
    rb_define_const(cNWScript, "ASSOCIATE_COMMAND_UNSUMMONFAMILIAR", INT2NUM(-8));
    rb_define_const(cNWScript, "ASSOCIATE_COMMAND_UNSUMMONANIMALCOMPANION", INT2NUM(-9));
    rb_define_const(cNWScript, "ASSOCIATE_COMMAND_UNSUMMONSUMMONED", INT2NUM(-10));
    rb_define_const(cNWScript, "ASSOCIATE_COMMAND_MASTERUNDERATTACK", INT2NUM(-11));
    rb_define_const(cNWScript, "ASSOCIATE_COMMAND_RELEASEDOMINATION", INT2NUM(-12));
    rb_define_const(cNWScript, "ASSOCIATE_COMMAND_UNPOSSESSFAMILIAR", INT2NUM(-13));
    rb_define_const(cNWScript, "ASSOCIATE_COMMAND_MASTERSAWTRAP", INT2NUM(-14));
    rb_define_const(cNWScript, "ASSOCIATE_COMMAND_MASTERATTACKEDOTHER", INT2NUM(-15));
    rb_define_const(cNWScript, "ASSOCIATE_COMMAND_MASTERGOINGTOBEATTACKED", INT2NUM(-16));
    rb_define_const(cNWScript, "ASSOCIATE_COMMAND_LEAVEPARTY", INT2NUM(-17));
    rb_define_const(cNWScript, "ASSOCIATE_COMMAND_PICKLOCK", INT2NUM(-18));
    rb_define_const(cNWScript, "ASSOCIATE_COMMAND_INVENTORY", INT2NUM(-19));
    rb_define_const(cNWScript, "ASSOCIATE_COMMAND_DISARMTRAP", INT2NUM(-20));
    rb_define_const(cNWScript, "ASSOCIATE_COMMAND_TOGGLECASTING", INT2NUM(-21));
    rb_define_const(cNWScript, "ASSOCIATE_COMMAND_TOGGLESTEALTH", INT2NUM(-22));
    rb_define_const(cNWScript, "ASSOCIATE_COMMAND_TOGGLESEARCH", INT2NUM(-23));
    rb_define_const(cNWScript, "ASSOCIATE_TYPE_NONE", INT2NUM(0));
    rb_define_const(cNWScript, "ASSOCIATE_TYPE_HENCHMAN", INT2NUM(1));
    rb_define_const(cNWScript, "ASSOCIATE_TYPE_ANIMALCOMPANION", INT2NUM(2));
    rb_define_const(cNWScript, "ASSOCIATE_TYPE_FAMILIAR", INT2NUM(3));
    rb_define_const(cNWScript, "ASSOCIATE_TYPE_SUMMONED", INT2NUM(4));
    rb_define_const(cNWScript, "ASSOCIATE_TYPE_DOMINATED", INT2NUM(5));
    rb_define_const(cNWScript, "TALENT_CATEGORY_HARMFUL_AREAEFFECT_DISCRIMINANT", INT2NUM(1));
    rb_define_const(cNWScript, "TALENT_CATEGORY_HARMFUL_RANGED", INT2NUM(2));
    rb_define_const(cNWScript, "TALENT_CATEGORY_HARMFUL_TOUCH", INT2NUM(3));
    rb_define_const(cNWScript, "TALENT_CATEGORY_BENEFICIAL_HEALING_AREAEFFECT", INT2NUM(4));
    rb_define_const(cNWScript, "TALENT_CATEGORY_BENEFICIAL_HEALING_TOUCH", INT2NUM(5));
    rb_define_const(cNWScript, "TALENT_CATEGORY_BENEFICIAL_CONDITIONAL_AREAEFFECT", INT2NUM(6));
    rb_define_const(cNWScript, "TALENT_CATEGORY_BENEFICIAL_CONDITIONAL_SINGLE", INT2NUM(7));
    rb_define_const(cNWScript, "TALENT_CATEGORY_BENEFICIAL_ENHANCEMENT_AREAEFFECT", INT2NUM(8));
    rb_define_const(cNWScript, "TALENT_CATEGORY_BENEFICIAL_ENHANCEMENT_SINGLE", INT2NUM(9));
    rb_define_const(cNWScript, "TALENT_CATEGORY_BENEFICIAL_ENHANCEMENT_SELF", INT2NUM(10));
    rb_define_const(cNWScript, "TALENT_CATEGORY_HARMFUL_AREAEFFECT_INDISCRIMINANT", INT2NUM(11));
    rb_define_const(cNWScript, "TALENT_CATEGORY_BENEFICIAL_PROTECTION_SELF", INT2NUM(12));
    rb_define_const(cNWScript, "TALENT_CATEGORY_BENEFICIAL_PROTECTION_SINGLE", INT2NUM(13));
    rb_define_const(cNWScript, "TALENT_CATEGORY_BENEFICIAL_PROTECTION_AREAEFFECT", INT2NUM(14));
    rb_define_const(cNWScript, "TALENT_CATEGORY_BENEFICIAL_OBTAIN_ALLIES", INT2NUM(15));
    rb_define_const(cNWScript, "TALENT_CATEGORY_PERSISTENT_AREA_OF_EFFECT", INT2NUM(16));
    rb_define_const(cNWScript, "TALENT_CATEGORY_BENEFICIAL_HEALING_POTION", INT2NUM(17));
    rb_define_const(cNWScript, "TALENT_CATEGORY_BENEFICIAL_CONDITIONAL_POTION", INT2NUM(18));
    rb_define_const(cNWScript, "TALENT_CATEGORY_DRAGONS_BREATH", INT2NUM(19));
    rb_define_const(cNWScript, "TALENT_CATEGORY_BENEFICIAL_PROTECTION_POTION", INT2NUM(20));
    rb_define_const(cNWScript, "TALENT_CATEGORY_BENEFICIAL_ENHANCEMENT_POTION", INT2NUM(21));
    rb_define_const(cNWScript, "TALENT_CATEGORY_HARMFUL_MELEE", INT2NUM(22));
    rb_define_const(cNWScript, "INVENTORY_DISTURB_TYPE_ADDED", INT2NUM(0));
    rb_define_const(cNWScript, "INVENTORY_DISTURB_TYPE_REMOVED", INT2NUM(1));
    rb_define_const(cNWScript, "INVENTORY_DISTURB_TYPE_STOLEN", INT2NUM(2));
    rb_define_const(cNWScript, "GUI_PANEL_PLAYER_DEATH", INT2NUM(0));
    rb_define_const(cNWScript, "VOICE_CHAT_ATTACK", INT2NUM(0));
    rb_define_const(cNWScript, "VOICE_CHAT_BATTLECRY1", INT2NUM(1));
    rb_define_const(cNWScript, "VOICE_CHAT_BATTLECRY2", INT2NUM(2));
    rb_define_const(cNWScript, "VOICE_CHAT_BATTLECRY3", INT2NUM(3));
    rb_define_const(cNWScript, "VOICE_CHAT_HEALME", INT2NUM(4));
    rb_define_const(cNWScript, "VOICE_CHAT_HELP", INT2NUM(5));
    rb_define_const(cNWScript, "VOICE_CHAT_ENEMIES", INT2NUM(6));
    rb_define_const(cNWScript, "VOICE_CHAT_FLEE", INT2NUM(7));
    rb_define_const(cNWScript, "VOICE_CHAT_TAUNT", INT2NUM(8));
    rb_define_const(cNWScript, "VOICE_CHAT_GUARDME", INT2NUM(9));
    rb_define_const(cNWScript, "VOICE_CHAT_HOLD", INT2NUM(10));
    rb_define_const(cNWScript, "VOICE_CHAT_GATTACK1", INT2NUM(11));
    rb_define_const(cNWScript, "VOICE_CHAT_GATTACK2", INT2NUM(12));
    rb_define_const(cNWScript, "VOICE_CHAT_GATTACK3", INT2NUM(13));
    rb_define_const(cNWScript, "VOICE_CHAT_PAIN1", INT2NUM(14));
    rb_define_const(cNWScript, "VOICE_CHAT_PAIN2", INT2NUM(15));
    rb_define_const(cNWScript, "VOICE_CHAT_PAIN3", INT2NUM(16));
    rb_define_const(cNWScript, "VOICE_CHAT_NEARDEATH", INT2NUM(17));
    rb_define_const(cNWScript, "VOICE_CHAT_DEATH", INT2NUM(18));
    rb_define_const(cNWScript, "VOICE_CHAT_POISONED", INT2NUM(19));
    rb_define_const(cNWScript, "VOICE_CHAT_SPELLFAILED", INT2NUM(20));
    rb_define_const(cNWScript, "VOICE_CHAT_WEAPONSUCKS", INT2NUM(21));
    rb_define_const(cNWScript, "VOICE_CHAT_FOLLOWME", INT2NUM(22));
    rb_define_const(cNWScript, "VOICE_CHAT_LOOKHERE", INT2NUM(23));
    rb_define_const(cNWScript, "VOICE_CHAT_GROUP", INT2NUM(24));
    rb_define_const(cNWScript, "VOICE_CHAT_MOVEOVER", INT2NUM(25));
    rb_define_const(cNWScript, "VOICE_CHAT_PICKLOCK", INT2NUM(26));
    rb_define_const(cNWScript, "VOICE_CHAT_SEARCH", INT2NUM(27));
    rb_define_const(cNWScript, "VOICE_CHAT_HIDE", INT2NUM(28));
    rb_define_const(cNWScript, "VOICE_CHAT_CANDO", INT2NUM(29));
    rb_define_const(cNWScript, "VOICE_CHAT_CANTDO", INT2NUM(30));
    rb_define_const(cNWScript, "VOICE_CHAT_TASKCOMPLETE", INT2NUM(31));
    rb_define_const(cNWScript, "VOICE_CHAT_ENCUMBERED", INT2NUM(32));
    rb_define_const(cNWScript, "VOICE_CHAT_SELECTED", INT2NUM(33));
    rb_define_const(cNWScript, "VOICE_CHAT_HELLO", INT2NUM(34));
    rb_define_const(cNWScript, "VOICE_CHAT_YES", INT2NUM(35));
    rb_define_const(cNWScript, "VOICE_CHAT_NO", INT2NUM(36));
    rb_define_const(cNWScript, "VOICE_CHAT_STOP", INT2NUM(37));
    rb_define_const(cNWScript, "VOICE_CHAT_REST", INT2NUM(38));
    rb_define_const(cNWScript, "VOICE_CHAT_BORED", INT2NUM(39));
    rb_define_const(cNWScript, "VOICE_CHAT_GOODBYE", INT2NUM(40));
    rb_define_const(cNWScript, "VOICE_CHAT_THANKS", INT2NUM(41));
    rb_define_const(cNWScript, "VOICE_CHAT_LAUGH", INT2NUM(42));
    rb_define_const(cNWScript, "VOICE_CHAT_CUSS", INT2NUM(43));
    rb_define_const(cNWScript, "VOICE_CHAT_CHEER", INT2NUM(44));
    rb_define_const(cNWScript, "VOICE_CHAT_TALKTOME", INT2NUM(45));
    rb_define_const(cNWScript, "VOICE_CHAT_GOODIDEA", INT2NUM(46));
    rb_define_const(cNWScript, "VOICE_CHAT_BADIDEA", INT2NUM(47));
    rb_define_const(cNWScript, "VOICE_CHAT_THREATEN", INT2NUM(48));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_WEREWOLF", INT2NUM(0));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_WERERAT", INT2NUM(1));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_WERECAT", INT2NUM(2));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_GIANT_SPIDER", INT2NUM(3));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_TROLL", INT2NUM(4));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_UMBER_HULK", INT2NUM(5));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_PIXIE", INT2NUM(6));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_ZOMBIE", INT2NUM(7));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_RED_DRAGON", INT2NUM(8));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_FIRE_GIANT", INT2NUM(9));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_BALOR", INT2NUM(10));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_DEATH_SLAAD", INT2NUM(11));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_IRON_GOLEM", INT2NUM(12));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_HUGE_FIRE_ELEMENTAL", INT2NUM(13));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_HUGE_WATER_ELEMENTAL", INT2NUM(14));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_HUGE_EARTH_ELEMENTAL", INT2NUM(15));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_HUGE_AIR_ELEMENTAL", INT2NUM(16));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_ELDER_FIRE_ELEMENTAL", INT2NUM(17));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_ELDER_WATER_ELEMENTAL", INT2NUM(18));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_ELDER_EARTH_ELEMENTAL", INT2NUM(19));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_ELDER_AIR_ELEMENTAL", INT2NUM(20));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_BROWN_BEAR", INT2NUM(21));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_PANTHER", INT2NUM(22));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_WOLF", INT2NUM(23));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_BOAR", INT2NUM(24));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_BADGER", INT2NUM(25));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_PENGUIN", INT2NUM(26));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_COW", INT2NUM(27));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_DOOM_KNIGHT", INT2NUM(28));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_YUANTI", INT2NUM(29));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_IMP", INT2NUM(30));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_QUASIT", INT2NUM(31));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_SUCCUBUS", INT2NUM(32));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_DIRE_BROWN_BEAR", INT2NUM(33));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_DIRE_PANTHER", INT2NUM(34));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_DIRE_WOLF", INT2NUM(35));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_DIRE_BOAR", INT2NUM(36));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_DIRE_BADGER", INT2NUM(37));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_CELESTIAL_AVENGER", INT2NUM(38));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_VROCK", INT2NUM(39));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_CHICKEN", INT2NUM(40));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_FROST_GIANT_MALE", INT2NUM(41));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_FROST_GIANT_FEMALE", INT2NUM(42));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_HEURODIS", INT2NUM(43));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_JNAH_GIANT_MALE", INT2NUM(44));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_JNAH_GIANT_FEMAL", INT2NUM(45));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_WYRMLING_WHITE", INT2NUM(52));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_WYRMLING_BLUE", INT2NUM(53));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_WYRMLING_RED", INT2NUM(54));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_WYRMLING_GREEN", INT2NUM(55));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_WYRMLING_BLACK", INT2NUM(56));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_GOLEM_AUTOMATON", INT2NUM(57));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_MANTICORE", INT2NUM(58));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_MALE_DROW", INT2NUM(59));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_HARPY", INT2NUM(60));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_BASILISK", INT2NUM(61));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_DRIDER", INT2NUM(62));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_BEHOLDER", INT2NUM(63));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_MEDUSA", INT2NUM(64));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_GARGOYLE", INT2NUM(65));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_MINOTAUR", INT2NUM(66));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_SUPER_CHICKEN", INT2NUM(67));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_MINDFLAYER", INT2NUM(68));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_DIRETIGER", INT2NUM(69));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_FEMALE_DROW", INT2NUM(70));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_ANCIENT_BLUE_DRAGON", INT2NUM(71));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_ANCIENT_RED_DRAGON", INT2NUM(72));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_ANCIENT_GREEN_DRAGON", INT2NUM(73));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_VAMPIRE_MALE", INT2NUM(74));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_RISEN_LORD", INT2NUM(75));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_SPECTRE", INT2NUM(76));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_VAMPIRE_FEMALE", INT2NUM(77));
    rb_define_const(cNWScript, "POLYMORPH_TYPE_NULL_HUMAN", INT2NUM(78));
    rb_define_const(cNWScript, "INVISIBILITY_TYPE_NORMAL", INT2NUM(1));
    rb_define_const(cNWScript, "INVISIBILITY_TYPE_DARKNESS", INT2NUM(2));
    rb_define_const(cNWScript, "INVISIBILITY_TYPE_IMPROVED", INT2NUM(4));
    rb_define_const(cNWScript, "CREATURE_SIZE_INVALID", INT2NUM(0));
    rb_define_const(cNWScript, "CREATURE_SIZE_TINY", INT2NUM(1));
    rb_define_const(cNWScript, "CREATURE_SIZE_SMALL", INT2NUM(2));
    rb_define_const(cNWScript, "CREATURE_SIZE_MEDIUM", INT2NUM(3));
    rb_define_const(cNWScript, "CREATURE_SIZE_LARGE", INT2NUM(4));
    rb_define_const(cNWScript, "CREATURE_SIZE_HUGE", INT2NUM(5));
    rb_define_const(cNWScript, "SPELL_SCHOOL_GENERAL", INT2NUM(0));
    rb_define_const(cNWScript, "SPELL_SCHOOL_ABJURATION", INT2NUM(1));
    rb_define_const(cNWScript, "SPELL_SCHOOL_CONJURATION", INT2NUM(2));
    rb_define_const(cNWScript, "SPELL_SCHOOL_DIVINATION", INT2NUM(3));
    rb_define_const(cNWScript, "SPELL_SCHOOL_ENCHANTMENT", INT2NUM(4));
    rb_define_const(cNWScript, "SPELL_SCHOOL_EVOCATION", INT2NUM(5));
    rb_define_const(cNWScript, "SPELL_SCHOOL_ILLUSION", INT2NUM(6));
    rb_define_const(cNWScript, "SPELL_SCHOOL_NECROMANCY", INT2NUM(7));
    rb_define_const(cNWScript, "SPELL_SCHOOL_TRANSMUTATION", INT2NUM(8));
    rb_define_const(cNWScript, "ANIMAL_COMPANION_CREATURE_TYPE_BADGER", INT2NUM(0));
    rb_define_const(cNWScript, "ANIMAL_COMPANION_CREATURE_TYPE_WOLF", INT2NUM(1));
    rb_define_const(cNWScript, "ANIMAL_COMPANION_CREATURE_TYPE_BEAR", INT2NUM(2));
    rb_define_const(cNWScript, "ANIMAL_COMPANION_CREATURE_TYPE_BOAR", INT2NUM(3));
    rb_define_const(cNWScript, "ANIMAL_COMPANION_CREATURE_TYPE_HAWK", INT2NUM(4));
    rb_define_const(cNWScript, "ANIMAL_COMPANION_CREATURE_TYPE_PANTHER", INT2NUM(5));
    rb_define_const(cNWScript, "ANIMAL_COMPANION_CREATURE_TYPE_SPIDER", INT2NUM(6));
    rb_define_const(cNWScript, "ANIMAL_COMPANION_CREATURE_TYPE_DIREWOLF", INT2NUM(7));
    rb_define_const(cNWScript, "ANIMAL_COMPANION_CREATURE_TYPE_DIRERAT", INT2NUM(8));
    rb_define_const(cNWScript, "ANIMAL_COMPANION_CREATURE_TYPE_NONE", INT2NUM(255));
    rb_define_const(cNWScript, "FAMILIAR_CREATURE_TYPE_BAT", INT2NUM(0));
    rb_define_const(cNWScript, "FAMILIAR_CREATURE_TYPE_CRAGCAT", INT2NUM(1));
    rb_define_const(cNWScript, "FAMILIAR_CREATURE_TYPE_HELLHOUND", INT2NUM(2));
    rb_define_const(cNWScript, "FAMILIAR_CREATURE_TYPE_IMP", INT2NUM(3));
    rb_define_const(cNWScript, "FAMILIAR_CREATURE_TYPE_FIREMEPHIT", INT2NUM(4));
    rb_define_const(cNWScript, "FAMILIAR_CREATURE_TYPE_ICEMEPHIT", INT2NUM(5));
    rb_define_const(cNWScript, "FAMILIAR_CREATURE_TYPE_PIXIE", INT2NUM(6));
    rb_define_const(cNWScript, "FAMILIAR_CREATURE_TYPE_RAVEN", INT2NUM(7));
    rb_define_const(cNWScript, "FAMILIAR_CREATURE_TYPE_FAIRY_DRAGON", INT2NUM(8));
    rb_define_const(cNWScript, "FAMILIAR_CREATURE_TYPE_PSEUDO_DRAGON", INT2NUM(9));
    rb_define_const(cNWScript, "FAMILIAR_CREATURE_TYPE_EYEBALL", INT2NUM(10));
    rb_define_const(cNWScript, "FAMILIAR_CREATURE_TYPE_NONE", INT2NUM(255));
    rb_define_const(cNWScript, "CAMERA_MODE_CHASE_CAMERA", INT2NUM(0));
    rb_define_const(cNWScript, "CAMERA_MODE_TOP_DOWN", INT2NUM(1));
    rb_define_const(cNWScript, "CAMERA_MODE_STIFF_CHASE_CAMERA", INT2NUM(2));
    rb_define_const(cNWScript, "WEATHER_INVALID", INT2NUM(-1));
    rb_define_const(cNWScript, "WEATHER_CLEAR", INT2NUM(0));
    rb_define_const(cNWScript, "WEATHER_RAIN", INT2NUM(1));
    rb_define_const(cNWScript, "WEATHER_SNOW", INT2NUM(2));
    rb_define_const(cNWScript, "WEATHER_USE_AREA_SETTINGS", INT2NUM(-1));
    rb_define_const(cNWScript, "REST_EVENTTYPE_REST_INVALID", INT2NUM(0));
    rb_define_const(cNWScript, "REST_EVENTTYPE_REST_STARTED", INT2NUM(1));
    rb_define_const(cNWScript, "REST_EVENTTYPE_REST_FINISHED", INT2NUM(2));
    rb_define_const(cNWScript, "REST_EVENTTYPE_REST_CANCELLED", INT2NUM(3));
    rb_define_const(cNWScript, "PROJECTILE_PATH_TYPE_DEFAULT", INT2NUM(0));
    rb_define_const(cNWScript, "PROJECTILE_PATH_TYPE_HOMING", INT2NUM(1));
    rb_define_const(cNWScript, "PROJECTILE_PATH_TYPE_BALLISTIC", INT2NUM(2));
    rb_define_const(cNWScript, "PROJECTILE_PATH_TYPE_HIGH_BALLISTIC", INT2NUM(3));
    rb_define_const(cNWScript, "PROJECTILE_PATH_TYPE_ACCELERATING", INT2NUM(4));
    rb_define_const(cNWScript, "GAME_DIFFICULTY_VERY_EASY", INT2NUM(0));
    rb_define_const(cNWScript, "GAME_DIFFICULTY_EASY", INT2NUM(1));
    rb_define_const(cNWScript, "GAME_DIFFICULTY_NORMAL", INT2NUM(2));
    rb_define_const(cNWScript, "GAME_DIFFICULTY_CORE_RULES", INT2NUM(3));
    rb_define_const(cNWScript, "GAME_DIFFICULTY_DIFFICULT", INT2NUM(4));
    rb_define_const(cNWScript, "TILE_MAIN_LIGHT_COLOR_BLACK", INT2NUM(0));
    rb_define_const(cNWScript, "TILE_MAIN_LIGHT_COLOR_DIM_WHITE", INT2NUM(1));
    rb_define_const(cNWScript, "TILE_MAIN_LIGHT_COLOR_WHITE", INT2NUM(2));
    rb_define_const(cNWScript, "TILE_MAIN_LIGHT_COLOR_BRIGHT_WHITE", INT2NUM(3));
    rb_define_const(cNWScript, "TILE_MAIN_LIGHT_COLOR_PALE_DARK_YELLOW", INT2NUM(4));
    rb_define_const(cNWScript, "TILE_MAIN_LIGHT_COLOR_DARK_YELLOW", INT2NUM(5));
    rb_define_const(cNWScript, "TILE_MAIN_LIGHT_COLOR_PALE_YELLOW", INT2NUM(6));
    rb_define_const(cNWScript, "TILE_MAIN_LIGHT_COLOR_YELLOW", INT2NUM(7));
    rb_define_const(cNWScript, "TILE_MAIN_LIGHT_COLOR_PALE_DARK_GREEN", INT2NUM(8));
    rb_define_const(cNWScript, "TILE_MAIN_LIGHT_COLOR_DARK_GREEN", INT2NUM(9));
    rb_define_const(cNWScript, "TILE_MAIN_LIGHT_COLOR_PALE_GREEN", INT2NUM(10));
    rb_define_const(cNWScript, "TILE_MAIN_LIGHT_COLOR_GREEN", INT2NUM(11));
    rb_define_const(cNWScript, "TILE_MAIN_LIGHT_COLOR_PALE_DARK_AQUA", INT2NUM(12));
    rb_define_const(cNWScript, "TILE_MAIN_LIGHT_COLOR_DARK_AQUA", INT2NUM(13));
    rb_define_const(cNWScript, "TILE_MAIN_LIGHT_COLOR_PALE_AQUA", INT2NUM(14));
    rb_define_const(cNWScript, "TILE_MAIN_LIGHT_COLOR_AQUA", INT2NUM(15));
    rb_define_const(cNWScript, "TILE_MAIN_LIGHT_COLOR_PALE_DARK_BLUE", INT2NUM(16));
    rb_define_const(cNWScript, "TILE_MAIN_LIGHT_COLOR_DARK_BLUE", INT2NUM(17));
    rb_define_const(cNWScript, "TILE_MAIN_LIGHT_COLOR_PALE_BLUE", INT2NUM(18));
    rb_define_const(cNWScript, "TILE_MAIN_LIGHT_COLOR_BLUE", INT2NUM(19));
    rb_define_const(cNWScript, "TILE_MAIN_LIGHT_COLOR_PALE_DARK_PURPLE", INT2NUM(20));
    rb_define_const(cNWScript, "TILE_MAIN_LIGHT_COLOR_DARK_PURPLE", INT2NUM(21));
    rb_define_const(cNWScript, "TILE_MAIN_LIGHT_COLOR_PALE_PURPLE", INT2NUM(22));
    rb_define_const(cNWScript, "TILE_MAIN_LIGHT_COLOR_PURPLE", INT2NUM(23));
    rb_define_const(cNWScript, "TILE_MAIN_LIGHT_COLOR_PALE_DARK_RED", INT2NUM(24));
    rb_define_const(cNWScript, "TILE_MAIN_LIGHT_COLOR_DARK_RED", INT2NUM(25));
    rb_define_const(cNWScript, "TILE_MAIN_LIGHT_COLOR_PALE_RED", INT2NUM(26));
    rb_define_const(cNWScript, "TILE_MAIN_LIGHT_COLOR_RED", INT2NUM(27));
    rb_define_const(cNWScript, "TILE_MAIN_LIGHT_COLOR_PALE_DARK_ORANGE", INT2NUM(28));
    rb_define_const(cNWScript, "TILE_MAIN_LIGHT_COLOR_DARK_ORANGE", INT2NUM(29));
    rb_define_const(cNWScript, "TILE_MAIN_LIGHT_COLOR_PALE_ORANGE", INT2NUM(30));
    rb_define_const(cNWScript, "TILE_MAIN_LIGHT_COLOR_ORANGE", INT2NUM(31));
    rb_define_const(cNWScript, "TILE_SOURCE_LIGHT_COLOR_BLACK", INT2NUM(0));
    rb_define_const(cNWScript, "TILE_SOURCE_LIGHT_COLOR_WHITE", INT2NUM(1));
    rb_define_const(cNWScript, "TILE_SOURCE_LIGHT_COLOR_PALE_DARK_YELLOW", INT2NUM(2));
    rb_define_const(cNWScript, "TILE_SOURCE_LIGHT_COLOR_PALE_YELLOW", INT2NUM(3));
    rb_define_const(cNWScript, "TILE_SOURCE_LIGHT_COLOR_PALE_DARK_GREEN", INT2NUM(4));
    rb_define_const(cNWScript, "TILE_SOURCE_LIGHT_COLOR_PALE_GREEN", INT2NUM(5));
    rb_define_const(cNWScript, "TILE_SOURCE_LIGHT_COLOR_PALE_DARK_AQUA", INT2NUM(6));
    rb_define_const(cNWScript, "TILE_SOURCE_LIGHT_COLOR_PALE_AQUA", INT2NUM(7));
    rb_define_const(cNWScript, "TILE_SOURCE_LIGHT_COLOR_PALE_DARK_BLUE", INT2NUM(8));
    rb_define_const(cNWScript, "TILE_SOURCE_LIGHT_COLOR_PALE_BLUE", INT2NUM(9));
    rb_define_const(cNWScript, "TILE_SOURCE_LIGHT_COLOR_PALE_DARK_PURPLE", INT2NUM(10));
    rb_define_const(cNWScript, "TILE_SOURCE_LIGHT_COLOR_PALE_PURPLE", INT2NUM(11));
    rb_define_const(cNWScript, "TILE_SOURCE_LIGHT_COLOR_PALE_DARK_RED", INT2NUM(12));
    rb_define_const(cNWScript, "TILE_SOURCE_LIGHT_COLOR_PALE_RED", INT2NUM(13));
    rb_define_const(cNWScript, "TILE_SOURCE_LIGHT_COLOR_PALE_DARK_ORANGE", INT2NUM(14));
    rb_define_const(cNWScript, "TILE_SOURCE_LIGHT_COLOR_PALE_ORANGE", INT2NUM(15));
    rb_define_const(cNWScript, "PANEL_BUTTON_MAP", INT2NUM(0));
    rb_define_const(cNWScript, "PANEL_BUTTON_INVENTORY", INT2NUM(1));
    rb_define_const(cNWScript, "PANEL_BUTTON_JOURNAL", INT2NUM(2));
    rb_define_const(cNWScript, "PANEL_BUTTON_CHARACTER", INT2NUM(3));
    rb_define_const(cNWScript, "PANEL_BUTTON_OPTIONS", INT2NUM(4));
    rb_define_const(cNWScript, "PANEL_BUTTON_SPELLS", INT2NUM(5));
    rb_define_const(cNWScript, "PANEL_BUTTON_REST", INT2NUM(6));
    rb_define_const(cNWScript, "PANEL_BUTTON_PLAYER_VERSUS_PLAYER", INT2NUM(7));
    rb_define_const(cNWScript, "ACTION_MOVETOPOINT", INT2NUM(0));
    rb_define_const(cNWScript, "ACTION_PICKUPITEM", INT2NUM(1));
    rb_define_const(cNWScript, "ACTION_DROPITEM", INT2NUM(2));
    rb_define_const(cNWScript, "ACTION_ATTACKOBJECT", INT2NUM(3));
    rb_define_const(cNWScript, "ACTION_CASTSPELL", INT2NUM(4));
    rb_define_const(cNWScript, "ACTION_OPENDOOR", INT2NUM(5));
    rb_define_const(cNWScript, "ACTION_CLOSEDOOR", INT2NUM(6));
    rb_define_const(cNWScript, "ACTION_DIALOGOBJECT", INT2NUM(7));
    rb_define_const(cNWScript, "ACTION_DISABLETRAP", INT2NUM(8));
    rb_define_const(cNWScript, "ACTION_RECOVERTRAP", INT2NUM(9));
    rb_define_const(cNWScript, "ACTION_FLAGTRAP", INT2NUM(10));
    rb_define_const(cNWScript, "ACTION_EXAMINETRAP", INT2NUM(11));
    rb_define_const(cNWScript, "ACTION_SETTRAP", INT2NUM(12));
    rb_define_const(cNWScript, "ACTION_OPENLOCK", INT2NUM(13));
    rb_define_const(cNWScript, "ACTION_LOCK", INT2NUM(14));
    rb_define_const(cNWScript, "ACTION_USEOBJECT", INT2NUM(15));
    rb_define_const(cNWScript, "ACTION_ANIMALEMPATHY", INT2NUM(16));
    rb_define_const(cNWScript, "ACTION_REST", INT2NUM(17));
    rb_define_const(cNWScript, "ACTION_TAUNT", INT2NUM(18));
    rb_define_const(cNWScript, "ACTION_ITEMCASTSPELL", INT2NUM(19));
    rb_define_const(cNWScript, "ACTION_COUNTERSPELL", INT2NUM(31));
    rb_define_const(cNWScript, "ACTION_HEAL", INT2NUM(33));
    rb_define_const(cNWScript, "ACTION_PICKPOCKET", INT2NUM(34));
    rb_define_const(cNWScript, "ACTION_FOLLOW", INT2NUM(35));
    rb_define_const(cNWScript, "ACTION_WAIT", INT2NUM(36));
    rb_define_const(cNWScript, "ACTION_SIT", INT2NUM(37));
    rb_define_const(cNWScript, "ACTION_SMITEGOOD", INT2NUM(40));
    rb_define_const(cNWScript, "ACTION_KIDAMAGE", INT2NUM(41));
    rb_define_const(cNWScript, "ACTION_RANDOMWALK", INT2NUM(43));
    rb_define_const(cNWScript, "ACTION_INVALID", INT2NUM(65535));
    rb_define_const(cNWScript, "TRAP_BASE_TYPE_MINOR_SPIKE", INT2NUM(0));
    rb_define_const(cNWScript, "TRAP_BASE_TYPE_AVERAGE_SPIKE", INT2NUM(1));
    rb_define_const(cNWScript, "TRAP_BASE_TYPE_STRONG_SPIKE", INT2NUM(2));
    rb_define_const(cNWScript, "TRAP_BASE_TYPE_DEADLY_SPIKE", INT2NUM(3));
    rb_define_const(cNWScript, "TRAP_BASE_TYPE_MINOR_HOLY", INT2NUM(4));
    rb_define_const(cNWScript, "TRAP_BASE_TYPE_AVERAGE_HOLY", INT2NUM(5));
    rb_define_const(cNWScript, "TRAP_BASE_TYPE_STRONG_HOLY", INT2NUM(6));
    rb_define_const(cNWScript, "TRAP_BASE_TYPE_DEADLY_HOLY", INT2NUM(7));
    rb_define_const(cNWScript, "TRAP_BASE_TYPE_MINOR_TANGLE", INT2NUM(8));
    rb_define_const(cNWScript, "TRAP_BASE_TYPE_AVERAGE_TANGLE", INT2NUM(9));
    rb_define_const(cNWScript, "TRAP_BASE_TYPE_STRONG_TANGLE", INT2NUM(10));
    rb_define_const(cNWScript, "TRAP_BASE_TYPE_DEADLY_TANGLE", INT2NUM(11));
    rb_define_const(cNWScript, "TRAP_BASE_TYPE_MINOR_ACID", INT2NUM(12));
    rb_define_const(cNWScript, "TRAP_BASE_TYPE_AVERAGE_ACID", INT2NUM(13));
    rb_define_const(cNWScript, "TRAP_BASE_TYPE_STRONG_ACID", INT2NUM(14));
    rb_define_const(cNWScript, "TRAP_BASE_TYPE_DEADLY_ACID", INT2NUM(15));
    rb_define_const(cNWScript, "TRAP_BASE_TYPE_MINOR_FIRE", INT2NUM(16));
    rb_define_const(cNWScript, "TRAP_BASE_TYPE_AVERAGE_FIRE", INT2NUM(17));
    rb_define_const(cNWScript, "TRAP_BASE_TYPE_STRONG_FIRE", INT2NUM(18));
    rb_define_const(cNWScript, "TRAP_BASE_TYPE_DEADLY_FIRE", INT2NUM(19));
    rb_define_const(cNWScript, "TRAP_BASE_TYPE_MINOR_ELECTRICAL", INT2NUM(20));
    rb_define_const(cNWScript, "TRAP_BASE_TYPE_AVERAGE_ELECTRICAL", INT2NUM(21));
    rb_define_const(cNWScript, "TRAP_BASE_TYPE_STRONG_ELECTRICAL", INT2NUM(22));
    rb_define_const(cNWScript, "TRAP_BASE_TYPE_DEADLY_ELECTRICAL", INT2NUM(23));
    rb_define_const(cNWScript, "TRAP_BASE_TYPE_MINOR_GAS", INT2NUM(24));
    rb_define_const(cNWScript, "TRAP_BASE_TYPE_AVERAGE_GAS", INT2NUM(25));
    rb_define_const(cNWScript, "TRAP_BASE_TYPE_STRONG_GAS", INT2NUM(26));
    rb_define_const(cNWScript, "TRAP_BASE_TYPE_DEADLY_GAS", INT2NUM(27));
    rb_define_const(cNWScript, "TRAP_BASE_TYPE_MINOR_FROST", INT2NUM(28));
    rb_define_const(cNWScript, "TRAP_BASE_TYPE_AVERAGE_FROST", INT2NUM(29));
    rb_define_const(cNWScript, "TRAP_BASE_TYPE_STRONG_FROST", INT2NUM(30));
    rb_define_const(cNWScript, "TRAP_BASE_TYPE_DEADLY_FROST", INT2NUM(31));
    rb_define_const(cNWScript, "TRAP_BASE_TYPE_MINOR_NEGATIVE", INT2NUM(32));
    rb_define_const(cNWScript, "TRAP_BASE_TYPE_AVERAGE_NEGATIVE", INT2NUM(33));
    rb_define_const(cNWScript, "TRAP_BASE_TYPE_STRONG_NEGATIVE", INT2NUM(34));
    rb_define_const(cNWScript, "TRAP_BASE_TYPE_DEADLY_NEGATIVE", INT2NUM(35));
    rb_define_const(cNWScript, "TRAP_BASE_TYPE_MINOR_SONIC", INT2NUM(36));
    rb_define_const(cNWScript, "TRAP_BASE_TYPE_AVERAGE_SONIC", INT2NUM(37));
    rb_define_const(cNWScript, "TRAP_BASE_TYPE_STRONG_SONIC", INT2NUM(38));
    rb_define_const(cNWScript, "TRAP_BASE_TYPE_DEADLY_SONIC", INT2NUM(39));
    rb_define_const(cNWScript, "TRAP_BASE_TYPE_MINOR_ACID_SPLASH", INT2NUM(40));
    rb_define_const(cNWScript, "TRAP_BASE_TYPE_AVERAGE_ACID_SPLASH", INT2NUM(41));
    rb_define_const(cNWScript, "TRAP_BASE_TYPE_STRONG_ACID_SPLASH", INT2NUM(42));
    rb_define_const(cNWScript, "TRAP_BASE_TYPE_DEADLY_ACID_SPLASH", INT2NUM(43));
    rb_define_const(cNWScript, "TRAP_BASE_TYPE_EPIC_ELECTRICAL", INT2NUM(44));
    rb_define_const(cNWScript, "TRAP_BASE_TYPE_EPIC_FIRE", INT2NUM(45));
    rb_define_const(cNWScript, "TRAP_BASE_TYPE_EPIC_FROST", INT2NUM(46));
    rb_define_const(cNWScript, "TRAP_BASE_TYPE_EPIC_SONIC", INT2NUM(47));
    rb_define_const(cNWScript, "TRACK_RURALDAY1", INT2NUM(1));
    rb_define_const(cNWScript, "TRACK_RURALDAY2", INT2NUM(2));
    rb_define_const(cNWScript, "TRACK_RURALNIGHT", INT2NUM(3));
    rb_define_const(cNWScript, "TRACK_FORESTDAY1", INT2NUM(4));
    rb_define_const(cNWScript, "TRACK_FORESTDAY2", INT2NUM(5));
    rb_define_const(cNWScript, "TRACK_FORESTNIGHT", INT2NUM(6));
    rb_define_const(cNWScript, "TRACK_DUNGEON1", INT2NUM(7));
    rb_define_const(cNWScript, "TRACK_SEWER", INT2NUM(8));
    rb_define_const(cNWScript, "TRACK_MINES1", INT2NUM(9));
    rb_define_const(cNWScript, "TRACK_MINES2", INT2NUM(10));
    rb_define_const(cNWScript, "TRACK_CRYPT1", INT2NUM(11));
    rb_define_const(cNWScript, "TRACK_CRYPT2", INT2NUM(12));
    rb_define_const(cNWScript, "TRACK_DESERT_DAY", INT2NUM(58));
    rb_define_const(cNWScript, "TRACK_DESERT_NIGHT", INT2NUM(61));
    rb_define_const(cNWScript, "TRACK_WINTER_DAY", INT2NUM(59));
    rb_define_const(cNWScript, "TRACK_EVILDUNGEON1", INT2NUM(13));
    rb_define_const(cNWScript, "TRACK_EVILDUNGEON2", INT2NUM(14));
    rb_define_const(cNWScript, "TRACK_CITYSLUMDAY", INT2NUM(15));
    rb_define_const(cNWScript, "TRACK_CITYSLUMNIGHT", INT2NUM(16));
    rb_define_const(cNWScript, "TRACK_CITYDOCKDAY", INT2NUM(17));
    rb_define_const(cNWScript, "TRACK_CITYDOCKNIGHT", INT2NUM(18));
    rb_define_const(cNWScript, "TRACK_CITYWEALTHY", INT2NUM(19));
    rb_define_const(cNWScript, "TRACK_CITYMARKET", INT2NUM(20));
    rb_define_const(cNWScript, "TRACK_CITYNIGHT", INT2NUM(21));
    rb_define_const(cNWScript, "TRACK_TAVERN1", INT2NUM(22));
    rb_define_const(cNWScript, "TRACK_TAVERN2", INT2NUM(23));
    rb_define_const(cNWScript, "TRACK_TAVERN3", INT2NUM(24));
    rb_define_const(cNWScript, "TRACK_TAVERN4", INT2NUM(56));
    rb_define_const(cNWScript, "TRACK_RICHHOUSE", INT2NUM(25));
    rb_define_const(cNWScript, "TRACK_STORE", INT2NUM(26));
    rb_define_const(cNWScript, "TRACK_TEMPLEGOOD", INT2NUM(27));
    rb_define_const(cNWScript, "TRACK_TEMPLEGOOD2", INT2NUM(49));
    rb_define_const(cNWScript, "TRACK_TEMPLEEVIL", INT2NUM(28));
    rb_define_const(cNWScript, "TRACK_THEME_NWN", INT2NUM(29));
    rb_define_const(cNWScript, "TRACK_THEME_CHAPTER1", INT2NUM(30));
    rb_define_const(cNWScript, "TRACK_THEME_CHAPTER2", INT2NUM(31));
    rb_define_const(cNWScript, "TRACK_THEME_CHAPTER3", INT2NUM(32));
    rb_define_const(cNWScript, "TRACK_THEME_CHAPTER4", INT2NUM(33));
    rb_define_const(cNWScript, "TRACK_BATTLE_RURAL1", INT2NUM(34));
    rb_define_const(cNWScript, "TRACK_BATTLE_FOREST1", INT2NUM(35));
    rb_define_const(cNWScript, "TRACK_BATTLE_FOREST2", INT2NUM(36));
    rb_define_const(cNWScript, "TRACK_BATTLE_DUNGEON1", INT2NUM(37));
    rb_define_const(cNWScript, "TRACK_BATTLE_DUNGEON2", INT2NUM(38));
    rb_define_const(cNWScript, "TRACK_BATTLE_DUNGEON3", INT2NUM(39));
    rb_define_const(cNWScript, "TRACK_BATTLE_CITY1", INT2NUM(40));
    rb_define_const(cNWScript, "TRACK_BATTLE_CITY2", INT2NUM(41));
    rb_define_const(cNWScript, "TRACK_BATTLE_CITY3", INT2NUM(42));
    rb_define_const(cNWScript, "TRACK_BATTLE_CITYBOSS", INT2NUM(43));
    rb_define_const(cNWScript, "TRACK_BATTLE_FORESTBOSS", INT2NUM(44));
    rb_define_const(cNWScript, "TRACK_BATTLE_LIZARDBOSS", INT2NUM(45));
    rb_define_const(cNWScript, "TRACK_BATTLE_DRAGON", INT2NUM(46));
    rb_define_const(cNWScript, "TRACK_BATTLE_ARIBETH", INT2NUM(47));
    rb_define_const(cNWScript, "TRACK_BATTLE_ENDBOSS", INT2NUM(48));
    rb_define_const(cNWScript, "TRACK_BATTLE_DESERT", INT2NUM(57));
    rb_define_const(cNWScript, "TRACK_BATTLE_WINTER", INT2NUM(60));
    rb_define_const(cNWScript, "TRACK_CASTLE", INT2NUM(50));
    rb_define_const(cNWScript, "TRACK_THEME_ARIBETH1", INT2NUM(51));
    rb_define_const(cNWScript, "TRACK_THEME_ARIBETH2", INT2NUM(52));
    rb_define_const(cNWScript, "TRACK_THEME_GEND", INT2NUM(53));
    rb_define_const(cNWScript, "TRACK_THEME_MAUGRIM", INT2NUM(54));
    rb_define_const(cNWScript, "TRACK_THEME_MORAG", INT2NUM(55));
    rb_define_const(cNWScript, "TRACK_HOTU_THEME", INT2NUM(62));
    rb_define_const(cNWScript, "TRACK_HOTU_WATERDEEP", INT2NUM(63));
    rb_define_const(cNWScript, "TRACK_HOTU_UNDERMOUNTAIN", INT2NUM(64));
    rb_define_const(cNWScript, "TRACK_HOTU_REBELCAMP", INT2NUM(65));
    rb_define_const(cNWScript, "TRACK_HOTU_FIREPLANE", INT2NUM(66));
    rb_define_const(cNWScript, "TRACK_HOTU_QUEEN", INT2NUM(67));
    rb_define_const(cNWScript, "TRACK_HOTU_HELLFROZEOVER", INT2NUM(68));
    rb_define_const(cNWScript, "TRACK_HOTU_DRACOLICH", INT2NUM(69));
    rb_define_const(cNWScript, "TRACK_HOTU_BATTLE_SMALL", INT2NUM(70));
    rb_define_const(cNWScript, "TRACK_HOTU_BATTLE_MED", INT2NUM(71));
    rb_define_const(cNWScript, "TRACK_HOTU_BATTLE_LARGE", INT2NUM(72));
    rb_define_const(cNWScript, "TRACK_HOTU_BATTLE_HELL", INT2NUM(73));
    rb_define_const(cNWScript, "TRACK_HOTU_BATTLE_BOSS1", INT2NUM(74));
    rb_define_const(cNWScript, "TRACK_HOTU_BATTLE_BOSS2", INT2NUM(75));
    rb_define_const(cNWScript, "STEALTH_MODE_DISABLED", INT2NUM(0));
    rb_define_const(cNWScript, "STEALTH_MODE_ACTIVATED", INT2NUM(1));
    rb_define_const(cNWScript, "DETECT_MODE_PASSIVE", INT2NUM(0));
    rb_define_const(cNWScript, "DETECT_MODE_ACTIVE", INT2NUM(1));
    rb_define_const(cNWScript, "DEFENSIVE_CASTING_MODE_DISABLED", INT2NUM(0));
    rb_define_const(cNWScript, "DEFENSIVE_CASTING_MODE_ACTIVATED", INT2NUM(1));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_INVALID", INT2NUM(-1));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_ALLIP", INT2NUM(186));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_ARANEA", INT2NUM(157));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_ARCH_TARGET", INT2NUM(200));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_ARIBETH", INT2NUM(190));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_ASABI_CHIEFTAIN", INT2NUM(353));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_ASABI_SHAMAN", INT2NUM(354));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_ASABI_WARRIOR", INT2NUM(355));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_BADGER", INT2NUM(8));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_BADGER_DIRE", INT2NUM(9));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_BALOR", INT2NUM(38));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_BARTENDER", INT2NUM(234));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_BASILISK", INT2NUM(369));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_BAT", INT2NUM(10));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_BAT_HORROR", INT2NUM(11));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_BEAR_BLACK", INT2NUM(12));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_BEAR_BROWN", INT2NUM(13));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_BEAR_DIRE", INT2NUM(15));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_BEAR_KODIAK", INT2NUM(204));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_BEAR_POLAR", INT2NUM(14));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_BEETLE_FIRE", INT2NUM(18));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_BEETLE_SLICER", INT2NUM(17));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_BEETLE_STAG", INT2NUM(19));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_BEETLE_STINK", INT2NUM(20));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_BEGGER", INT2NUM(220));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_BLOOD_SAILER", INT2NUM(221));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_BOAR", INT2NUM(21));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_BOAR_DIRE", INT2NUM(22));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_BODAK", INT2NUM(23));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_BUGBEAR_A", INT2NUM(29));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_BUGBEAR_B", INT2NUM(30));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_BUGBEAR_CHIEFTAIN_A", INT2NUM(25));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_BUGBEAR_CHIEFTAIN_B", INT2NUM(26));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_BUGBEAR_SHAMAN_A", INT2NUM(27));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_BUGBEAR_SHAMAN_B", INT2NUM(28));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_BULETTE", INT2NUM(481));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_CAT_CAT_DIRE", INT2NUM(95));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_CAT_COUGAR", INT2NUM(203));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_CAT_CRAG_CAT", INT2NUM(94));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_CAT_JAGUAR", INT2NUM(98));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_CAT_KRENSHAR", INT2NUM(96));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_CAT_LEOPARD", INT2NUM(93));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_CAT_LION", INT2NUM(97));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_CAT_MPANTHER", INT2NUM(306));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_CAT_PANTHER", INT2NUM(202));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_CHICKEN", INT2NUM(31));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_COCKATRICE", INT2NUM(368));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_COMBAT_DUMMY", INT2NUM(201));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_CONVICT", INT2NUM(238));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_COW", INT2NUM(34));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_CULT_MEMBER", INT2NUM(212));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_DEER", INT2NUM(35));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_DEER_STAG", INT2NUM(37));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_DEVIL", INT2NUM(392));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_DOG", INT2NUM(176));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_DOG_BLINKDOG", INT2NUM(174));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_DOG_DIRE_WOLF", INT2NUM(175));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_DOG_FENHOUND", INT2NUM(177));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_DOG_HELL_HOUND", INT2NUM(179));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_DOG_SHADOW_MASTIF", INT2NUM(180));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_DOG_WINTER_WOLF", INT2NUM(184));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_DOG_WOLF", INT2NUM(181));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_DOG_WORG", INT2NUM(185));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_DOOM_KNIGHT", INT2NUM(40));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_DRAGON_BLACK", INT2NUM(41));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_DRAGON_BLUE", INT2NUM(47));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_DRAGON_BRASS", INT2NUM(42));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_DRAGON_BRONZE", INT2NUM(45));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_DRAGON_COPPER", INT2NUM(43));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_DRAGON_GOLD", INT2NUM(46));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_DRAGON_GREEN", INT2NUM(48));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_DRAGON_RED", INT2NUM(49));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_DRAGON_SILVER", INT2NUM(44));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_DRAGON_WHITE", INT2NUM(50));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_DROW_CLERIC", INT2NUM(215));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_DROW_FIGHTER", INT2NUM(216));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_DRUEGAR_CLERIC", INT2NUM(218));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_DRUEGAR_FIGHTER", INT2NUM(217));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_DRYAD", INT2NUM(51));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_DWARF", INT2NUM(0));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_DWARF_NPC_FEMALE", INT2NUM(248));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_DWARF_NPC_MALE", INT2NUM(249));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_ELEMENTAL_AIR", INT2NUM(52));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_ELEMENTAL_AIR_ELDER", INT2NUM(53));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_ELEMENTAL_EARTH", INT2NUM(56));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_ELEMENTAL_EARTH_ELDER", INT2NUM(57));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_ELEMENTAL_FIRE", INT2NUM(60));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_ELEMENTAL_FIRE_ELDER", INT2NUM(61));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_ELEMENTAL_WATER", INT2NUM(69));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_ELEMENTAL_WATER_ELDER", INT2NUM(68));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_ELF", INT2NUM(1));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_ELF_NPC_FEMALE", INT2NUM(245));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_ELF_NPC_MALE_01", INT2NUM(246));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_ELF_NPC_MALE_02", INT2NUM(247));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_ETTERCAP", INT2NUM(166));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_ETTIN", INT2NUM(72));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_FAERIE_DRAGON", INT2NUM(374));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_FAIRY", INT2NUM(55));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_FALCON", INT2NUM(144));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_FEMALE_01", INT2NUM(222));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_FEMALE_02", INT2NUM(223));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_FEMALE_03", INT2NUM(224));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_FEMALE_04", INT2NUM(225));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_FORMIAN_MYRMARCH", INT2NUM(362));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_FORMIAN_QUEEN", INT2NUM(363));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_FORMIAN_WARRIOR", INT2NUM(361));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_FORMIAN_WORKER", INT2NUM(360));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_GARGOYLE", INT2NUM(73));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_GHAST", INT2NUM(74));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_GHOUL", INT2NUM(76));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_GHOUL_LORD", INT2NUM(77));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_GIANT_FIRE", INT2NUM(80));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_GIANT_FIRE_FEMALE", INT2NUM(351));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_GIANT_FROST", INT2NUM(81));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_GIANT_FROST_FEMALE", INT2NUM(350));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_GIANT_HILL", INT2NUM(78));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_GIANT_MOUNTAIN", INT2NUM(79));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_GNOLL_WARRIOR", INT2NUM(388));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_GNOLL_WIZ", INT2NUM(389));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_GNOME", INT2NUM(2));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_GNOME_NPC_FEMALE", INT2NUM(243));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_GNOME_NPC_MALE", INT2NUM(244));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_GOBLIN_A", INT2NUM(86));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_GOBLIN_B", INT2NUM(87));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_GOBLIN_CHIEF_A", INT2NUM(82));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_GOBLIN_CHIEF_B", INT2NUM(83));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_GOBLIN_SHAMAN_A", INT2NUM(84));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_GOBLIN_SHAMAN_B", INT2NUM(85));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_GOLEM_BONE", INT2NUM(24));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_GOLEM_CLAY", INT2NUM(91));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_GOLEM_FLESH", INT2NUM(88));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_GOLEM_IRON", INT2NUM(89));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_GOLEM_STONE", INT2NUM(92));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_GORGON", INT2NUM(367));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_GRAY_OOZE", INT2NUM(393));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_GREY_RENDER", INT2NUM(205));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_GYNOSPHINX", INT2NUM(365));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_HALFLING", INT2NUM(3));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_HALFLING_NPC_FEMALE", INT2NUM(250));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_HALFLING_NPC_MALE", INT2NUM(251));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_HALF_ELF", INT2NUM(4));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_HALF_ORC", INT2NUM(5));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_HALF_ORC_NPC_FEMALE", INT2NUM(252));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_HALF_ORC_NPC_MALE_01", INT2NUM(253));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_HALF_ORC_NPC_MALE_02", INT2NUM(254));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_HELMED_HORROR", INT2NUM(100));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_HEURODIS_LICH", INT2NUM(370));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_HOBGOBLIN_WARRIOR", INT2NUM(390));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_HOBGOBLIN_WIZARD", INT2NUM(391));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_HOOK_HORROR", INT2NUM(102));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_HOUSE_GUARD", INT2NUM(219));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_HUMAN", INT2NUM(6));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_HUMAN_NPC_FEMALE_01", INT2NUM(255));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_HUMAN_NPC_FEMALE_02", INT2NUM(256));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_HUMAN_NPC_FEMALE_03", INT2NUM(257));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_HUMAN_NPC_FEMALE_04", INT2NUM(258));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_HUMAN_NPC_FEMALE_05", INT2NUM(259));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_HUMAN_NPC_FEMALE_06", INT2NUM(260));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_HUMAN_NPC_FEMALE_07", INT2NUM(261));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_HUMAN_NPC_FEMALE_08", INT2NUM(262));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_HUMAN_NPC_FEMALE_09", INT2NUM(263));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_HUMAN_NPC_FEMALE_10", INT2NUM(264));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_HUMAN_NPC_FEMALE_11", INT2NUM(265));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_HUMAN_NPC_FEMALE_12", INT2NUM(266));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_HUMAN_NPC_MALE_01", INT2NUM(267));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_HUMAN_NPC_MALE_02", INT2NUM(268));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_HUMAN_NPC_MALE_03", INT2NUM(269));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_HUMAN_NPC_MALE_04", INT2NUM(270));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_HUMAN_NPC_MALE_05", INT2NUM(271));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_HUMAN_NPC_MALE_06", INT2NUM(272));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_HUMAN_NPC_MALE_07", INT2NUM(273));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_HUMAN_NPC_MALE_08", INT2NUM(274));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_HUMAN_NPC_MALE_09", INT2NUM(275));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_HUMAN_NPC_MALE_10", INT2NUM(276));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_HUMAN_NPC_MALE_11", INT2NUM(277));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_HUMAN_NPC_MALE_12", INT2NUM(278));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_HUMAN_NPC_MALE_13", INT2NUM(279));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_HUMAN_NPC_MALE_14", INT2NUM(280));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_HUMAN_NPC_MALE_15", INT2NUM(281));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_HUMAN_NPC_MALE_16", INT2NUM(282));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_HUMAN_NPC_MALE_17", INT2NUM(283));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_HUMAN_NPC_MALE_18", INT2NUM(284));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_IMP", INT2NUM(105));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_INN_KEEPER", INT2NUM(233));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_INTELLECT_DEVOURER", INT2NUM(117));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_INVISIBLE_HUMAN_MALE", INT2NUM(298));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_INVISIBLE_STALKER", INT2NUM(64));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_KID_FEMALE", INT2NUM(242));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_KID_MALE", INT2NUM(241));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_KOBOLD_A", INT2NUM(302));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_KOBOLD_B", INT2NUM(305));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_KOBOLD_CHIEF_A", INT2NUM(300));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_KOBOLD_CHIEF_B", INT2NUM(303));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_KOBOLD_SHAMAN_A", INT2NUM(301));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_KOBOLD_SHAMAN_B", INT2NUM(304));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_LANTERN_ARCHON", INT2NUM(103));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_LICH", INT2NUM(39));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_LIZARDFOLK_A", INT2NUM(134));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_LIZARDFOLK_B", INT2NUM(135));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_LIZARDFOLK_SHAMAN_A", INT2NUM(132));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_LIZARDFOLK_SHAMAN_B", INT2NUM(133));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_LIZARDFOLK_WARRIOR_A", INT2NUM(130));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_LIZARDFOLK_WARRIOR_B", INT2NUM(131));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_LUSKAN_GUARD", INT2NUM(211));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_MALE_01", INT2NUM(226));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_MALE_02", INT2NUM(227));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_MALE_03", INT2NUM(228));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_MALE_04", INT2NUM(229));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_MALE_05", INT2NUM(230));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_MANTICORE", INT2NUM(366));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_MEDUSA", INT2NUM(352));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_MEPHIT_AIR", INT2NUM(106));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_MEPHIT_DUST", INT2NUM(107));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_MEPHIT_EARTH", INT2NUM(108));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_MEPHIT_FIRE", INT2NUM(109));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_MEPHIT_ICE", INT2NUM(110));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_MEPHIT_MAGMA", INT2NUM(114));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_MEPHIT_OOZE", INT2NUM(112));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_MEPHIT_SALT", INT2NUM(111));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_MEPHIT_STEAM", INT2NUM(113));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_MEPHIT_WATER", INT2NUM(115));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_MINOGON", INT2NUM(119));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_MINOTAUR", INT2NUM(120));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_MINOTAUR_CHIEFTAIN", INT2NUM(121));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_MINOTAUR_SHAMAN", INT2NUM(122));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_MOHRG", INT2NUM(123));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_MUMMY_COMMON", INT2NUM(58));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_MUMMY_FIGHTER_2", INT2NUM(59));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_MUMMY_GREATER", INT2NUM(124));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_MUMMY_WARRIOR", INT2NUM(125));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_NWN_AARIN", INT2NUM(188));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_NWN_ARIBETH_EVIL", INT2NUM(189));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_NWN_HAEDRALINE", INT2NUM(191));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_NWN_MAUGRIM", INT2NUM(193));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_NWN_MORAG", INT2NUM(192));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_NWN_NASHER", INT2NUM(296));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_NWN_SEDOS", INT2NUM(297));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_NW_MILITIA_MEMBER", INT2NUM(210));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_NYMPH", INT2NUM(126));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_OCHRE_JELLY_LARGE", INT2NUM(394));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_OCHRE_JELLY_MEDIUM", INT2NUM(396));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_OCHRE_JELLY_SMALL", INT2NUM(398));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_OGRE", INT2NUM(127));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_OGREB", INT2NUM(207));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_OGRE_CHIEFTAIN", INT2NUM(128));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_OGRE_CHIEFTAINB", INT2NUM(208));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_OGRE_MAGE", INT2NUM(129));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_OGRE_MAGEB", INT2NUM(209));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_OLD_MAN", INT2NUM(239));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_OLD_WOMAN", INT2NUM(240));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_ORC_A", INT2NUM(140));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_ORC_B", INT2NUM(141));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_ORC_CHIEFTAIN_A", INT2NUM(136));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_ORC_CHIEFTAIN_B", INT2NUM(137));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_ORC_SHAMAN_A", INT2NUM(138));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_ORC_SHAMAN_B", INT2NUM(139));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_OX", INT2NUM(142));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_PARROT", INT2NUM(7));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_PENGUIN", INT2NUM(206));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_PLAGUE_VICTIM", INT2NUM(231));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_PROSTITUTE_01", INT2NUM(236));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_PROSTITUTE_02", INT2NUM(237));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_PSEUDODRAGON", INT2NUM(375));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_QUASIT", INT2NUM(104));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_RAKSHASA_BEAR_MALE", INT2NUM(294));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_RAKSHASA_TIGER_FEMALE", INT2NUM(290));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_RAKSHASA_TIGER_MALE", INT2NUM(293));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_RAKSHASA_WOLF_MALE", INT2NUM(295));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_RAT", INT2NUM(386));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_RAT_DIRE", INT2NUM(387));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_RAVEN", INT2NUM(145));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_SAHUAGIN", INT2NUM(65));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_SAHUAGIN_LEADER", INT2NUM(66));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_SAHUAGIN_CLERIC", INT2NUM(67));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_SEAGULL_FLYING", INT2NUM(291));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_SEAGULL_WALKING", INT2NUM(292));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_SHADOW", INT2NUM(146));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_SHADOW_FIEND", INT2NUM(147));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_SHARK_MAKO", INT2NUM(447));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_SHARK_HAMMERHEAD", INT2NUM(448));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_SHARK_GOBLIN", INT2NUM(449));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_SHIELD_GUARDIAN", INT2NUM(90));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_SHOP_KEEPER", INT2NUM(232));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_SKELETAL_DEVOURER", INT2NUM(36));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_SKELETON_CHIEFTAIN", INT2NUM(182));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_SKELETON_COMMON", INT2NUM(63));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_SKELETON_MAGE", INT2NUM(148));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_SKELETON_PRIEST", INT2NUM(62));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_SKELETON_WARRIOR", INT2NUM(150));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_SKELETON_WARRIOR_1", INT2NUM(70));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_SKELETON_WARRIOR_2", INT2NUM(71));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_SLAAD_BLUE", INT2NUM(151));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_SLAAD_DEATH", INT2NUM(152));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_SLAAD_GRAY", INT2NUM(153));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_SLAAD_GREEN", INT2NUM(154));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_SLAAD_RED", INT2NUM(155));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_SPECTRE", INT2NUM(156));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_SPHINX", INT2NUM(364));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_SPIDER_DIRE", INT2NUM(158));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_SPIDER_GIANT", INT2NUM(159));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_SPIDER_PHASE", INT2NUM(160));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_SPIDER_SWORD", INT2NUM(161));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_SPIDER_WRAITH", INT2NUM(162));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_STINGER", INT2NUM(356));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_STINGER_CHIEFTAIN", INT2NUM(358));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_STINGER_MAGE", INT2NUM(359));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_STINGER_WARRIOR", INT2NUM(357));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_SUCCUBUS", INT2NUM(163));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_TROGLODYTE", INT2NUM(451));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_TROGLODYTE_WARRIOR", INT2NUM(452));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_TROGLODYTE_CLERIC", INT2NUM(453));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_TROLL", INT2NUM(167));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_TROLL_CHIEFTAIN", INT2NUM(164));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_TROLL_SHAMAN", INT2NUM(165));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_UMBERHULK", INT2NUM(168));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_UTHGARD_ELK_TRIBE", INT2NUM(213));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_UTHGARD_TIGER_TRIBE", INT2NUM(214));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_VAMPIRE_FEMALE", INT2NUM(288));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_VAMPIRE_MALE", INT2NUM(289));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_VROCK", INT2NUM(101));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_WAITRESS", INT2NUM(235));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_WAR_DEVOURER", INT2NUM(54));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_WERECAT", INT2NUM(99));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_WERERAT", INT2NUM(170));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_WEREWOLF", INT2NUM(171));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_WIGHT", INT2NUM(172));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_WILL_O_WISP", INT2NUM(116));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_WRAITH", INT2NUM(187));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_WYRMLING_BLACK", INT2NUM(378));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_WYRMLING_BLUE", INT2NUM(377));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_WYRMLING_BRASS", INT2NUM(381));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_WYRMLING_BRONZE", INT2NUM(383));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_WYRMLING_COPPER", INT2NUM(382));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_WYRMLING_GOLD", INT2NUM(385));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_WYRMLING_GREEN", INT2NUM(379));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_WYRMLING_RED", INT2NUM(376));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_WYRMLING_SILVER", INT2NUM(384));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_WYRMLING_WHITE", INT2NUM(380));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_YUAN_TI", INT2NUM(285));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_YUAN_TI_CHIEFTEN", INT2NUM(286));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_YUAN_TI_WIZARD", INT2NUM(287));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_ZOMBIE", INT2NUM(198));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_ZOMBIE_ROTTING", INT2NUM(195));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_ZOMBIE_TYRANT_FOG", INT2NUM(199));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_ZOMBIE_WARRIOR_1", INT2NUM(196));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_ZOMBIE_WARRIOR_2", INT2NUM(197));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_BEHOLDER", INT2NUM(401));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_BEHOLDER_MAGE", INT2NUM(402));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_BEHOLDER_EYEBALL", INT2NUM(403));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_MEPHISTO_BIG", INT2NUM(404));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_DRACOLICH", INT2NUM(405));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_DRIDER", INT2NUM(406));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_DRIDER_CHIEF", INT2NUM(407));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_DROW_SLAVE", INT2NUM(408));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_DROW_WIZARD", INT2NUM(409));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_DROW_MATRON", INT2NUM(410));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_DUERGAR_SLAVE", INT2NUM(411));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_DUERGAR_CHIEF", INT2NUM(412));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_MINDFLAYER", INT2NUM(413));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_MINDFLAYER_2", INT2NUM(414));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_MINDFLAYER_ALHOON", INT2NUM(415));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_DEEP_ROTHE", INT2NUM(416));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_DRAGON_SHADOW", INT2NUM(418));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_HARPY", INT2NUM(419));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_GOLEM_MITHRAL", INT2NUM(420));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_GOLEM_ADAMANTIUM", INT2NUM(421));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_SPIDER_DEMON", INT2NUM(422));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_SVIRF_MALE", INT2NUM(423));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_SVIRF_FEMALE", INT2NUM(424));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_DRAGON_PRIS", INT2NUM(425));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_SLAAD_BLACK", INT2NUM(426));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_SLAAD_WHITE", INT2NUM(427));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_AZER_MALE", INT2NUM(428));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_AZER_FEMALE", INT2NUM(429));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_DEMI_LICH", INT2NUM(430));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_OBJECT_CHAIR", INT2NUM(431));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_OBJECT_TABLE", INT2NUM(432));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_OBJECT_CANDLE", INT2NUM(433));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_OBJECT_CHEST", INT2NUM(434));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_OBJECT_WHITE", INT2NUM(435));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_OBJECT_BLUE", INT2NUM(436));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_OBJECT_CYAN", INT2NUM(437));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_OBJECT_GREEN", INT2NUM(438));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_OBJECT_YELLOW", INT2NUM(439));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_OBJECT_ORANGE", INT2NUM(440));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_OBJECT_RED", INT2NUM(441));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_OBJECT_PURPLE", INT2NUM(442));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_OBJECT_FLAME_SMALL", INT2NUM(443));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_OBJECT_FLAME_MEDIUM", INT2NUM(444));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_OBJECT_FLAME_LARGE", INT2NUM(445));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_DRIDER_FEMALE", INT2NUM(446));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_SEA_HAG", INT2NUM(454));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_GOLEM_DEMONFLESH", INT2NUM(468));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_ANIMATED_CHEST", INT2NUM(469));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_GELATINOUS_CUBE", INT2NUM(470));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_MEPHISTO_NORM", INT2NUM(471));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_BEHOLDER_MOTHER", INT2NUM(472));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_OBJECT_BOAT", INT2NUM(473));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_DWARF_GOLEM", INT2NUM(474));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_DWARF_HALFORC", INT2NUM(475));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_DROW_WARRIOR_1", INT2NUM(476));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_DROW_WARRIOR_2", INT2NUM(477));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_DROW_FEMALE_1", INT2NUM(478));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_DROW_FEMALE_2", INT2NUM(479));
    rb_define_const(cNWScript, "APPEARANCE_TYPE_DROW_WARRIOR_3", INT2NUM(480));
    rb_define_const(cNWScript, "PHENOTYPE_NORMAL", INT2NUM(0));
    rb_define_const(cNWScript, "PHENOTYPE_BIG", INT2NUM(2));
    rb_define_const(cNWScript, "PHENOTYPE_CUSTOM1", INT2NUM(3));
    rb_define_const(cNWScript, "PHENOTYPE_CUSTOM2", INT2NUM(4));
    rb_define_const(cNWScript, "PHENOTYPE_CUSTOM3", INT2NUM(5));
    rb_define_const(cNWScript, "PHENOTYPE_CUSTOM4", INT2NUM(6));
    rb_define_const(cNWScript, "PHENOTYPE_CUSTOM5", INT2NUM(7));
    rb_define_const(cNWScript, "PHENOTYPE_CUSTOM6", INT2NUM(8));
    rb_define_const(cNWScript, "PHENOTYPE_CUSTOM7", INT2NUM(9));
    rb_define_const(cNWScript, "PHENOTYPE_CUSTOM8", INT2NUM(10));
    rb_define_const(cNWScript, "PHENOTYPE_CUSTOM9", INT2NUM(11));
    rb_define_const(cNWScript, "PHENOTYPE_CUSTOM10", INT2NUM(12));
    rb_define_const(cNWScript, "PHENOTYPE_CUSTOM11", INT2NUM(13));
    rb_define_const(cNWScript, "PHENOTYPE_CUSTOM12", INT2NUM(14));
    rb_define_const(cNWScript, "PHENOTYPE_CUSTOM13", INT2NUM(15));
    rb_define_const(cNWScript, "PHENOTYPE_CUSTOM14", INT2NUM(16));
    rb_define_const(cNWScript, "PHENOTYPE_CUSTOM15", INT2NUM(17));
    rb_define_const(cNWScript, "PHENOTYPE_CUSTOM16", INT2NUM(18));
    rb_define_const(cNWScript, "PHENOTYPE_CUSTOM17", INT2NUM(19));
    rb_define_const(cNWScript, "PHENOTYPE_CUSTOM18", INT2NUM(20));
    rb_define_const(cNWScript, "CAMERA_TRANSITION_TYPE_SNAP", INT2NUM(0));
    rb_define_const(cNWScript, "CAMERA_TRANSITION_TYPE_CRAWL", INT2NUM(2));
    rb_define_const(cNWScript, "CAMERA_TRANSITION_TYPE_VERY_SLOW", INT2NUM(5));
    rb_define_const(cNWScript, "CAMERA_TRANSITION_TYPE_SLOW", INT2NUM(20));
    rb_define_const(cNWScript, "CAMERA_TRANSITION_TYPE_MEDIUM", INT2NUM(40));
    rb_define_const(cNWScript, "CAMERA_TRANSITION_TYPE_FAST", INT2NUM(70));
    rb_define_const(cNWScript, "CAMERA_TRANSITION_TYPE_VERY_FAST", INT2NUM(100));
    rb_define_const(cNWScript, "FADE_SPEED_SLOWEST", rb_float_new(0.003));
    rb_define_const(cNWScript, "FADE_SPEED_SLOW", rb_float_new(0.005));
    rb_define_const(cNWScript, "FADE_SPEED_MEDIUM", rb_float_new(0.01));
    rb_define_const(cNWScript, "FADE_SPEED_FAST", rb_float_new(0.017));
    rb_define_const(cNWScript, "FADE_SPEED_FASTEST", rb_float_new(0.25));
    rb_define_const(cNWScript, "EVENT_HEARTBEAT", INT2NUM(1001));
    rb_define_const(cNWScript, "EVENT_PERCEIVE", INT2NUM(1002));
    rb_define_const(cNWScript, "EVENT_END_COMBAT_ROUND", INT2NUM(1003));
    rb_define_const(cNWScript, "EVENT_DIALOGUE", INT2NUM(1004));
    rb_define_const(cNWScript, "EVENT_ATTACKED", INT2NUM(1005));
    rb_define_const(cNWScript, "EVENT_DAMAGED", INT2NUM(1006));
    rb_define_const(cNWScript, "EVENT_DISTURBED", INT2NUM(1008));
    rb_define_const(cNWScript, "EVENT_SPELL_CAST_AT", INT2NUM(1011));
    rb_define_const(cNWScript, "AI_LEVEL_INVALID", INT2NUM(-1));
    rb_define_const(cNWScript, "AI_LEVEL_DEFAULT", INT2NUM(-1));
    rb_define_const(cNWScript, "AI_LEVEL_VERY_LOW", INT2NUM(0));
    rb_define_const(cNWScript, "AI_LEVEL_LOW", INT2NUM(1));
    rb_define_const(cNWScript, "AI_LEVEL_NORMAL", INT2NUM(2));
    rb_define_const(cNWScript, "AI_LEVEL_HIGH", INT2NUM(3));
    rb_define_const(cNWScript, "AI_LEVEL_VERY_HIGH", INT2NUM(4));
    rb_define_const(cNWScript, "AREA_INVALID", INT2NUM(-1));
    rb_define_const(cNWScript, "AREA_NATURAL", INT2NUM(1));
    rb_define_const(cNWScript, "AREA_ARTIFICIAL", INT2NUM(0));
    rb_define_const(cNWScript, "AREA_ABOVEGROUND", INT2NUM(1));
    rb_define_const(cNWScript, "AREA_UNDERGROUND", INT2NUM(0));
    rb_define_const(cNWScript, "AREA_HEIGHT", INT2NUM(0));
    rb_define_const(cNWScript, "AREA_WIDTH", INT2NUM(1));
    rb_define_const(cNWScript, "PORTRAIT_INVALID", INT2NUM(65535));
    rb_define_const(cNWScript, "USE_CREATURE_LEVEL", INT2NUM(0));
    rb_define_const(cNWScript, "IP_CONST_ABILITY_STR", INT2NUM(0));
    rb_define_const(cNWScript, "IP_CONST_ABILITY_DEX", INT2NUM(1));
    rb_define_const(cNWScript, "IP_CONST_ABILITY_CON", INT2NUM(2));
    rb_define_const(cNWScript, "IP_CONST_ABILITY_INT", INT2NUM(3));
    rb_define_const(cNWScript, "IP_CONST_ABILITY_WIS", INT2NUM(4));
    rb_define_const(cNWScript, "IP_CONST_ABILITY_CHA", INT2NUM(5));
    rb_define_const(cNWScript, "IP_CONST_ACMODIFIERTYPE_DODGE", INT2NUM(0));
    rb_define_const(cNWScript, "IP_CONST_ACMODIFIERTYPE_NATURAL", INT2NUM(1));
    rb_define_const(cNWScript, "IP_CONST_ACMODIFIERTYPE_ARMOR", INT2NUM(2));
    rb_define_const(cNWScript, "IP_CONST_ACMODIFIERTYPE_SHIELD", INT2NUM(3));
    rb_define_const(cNWScript, "IP_CONST_ACMODIFIERTYPE_DEFLECTION", INT2NUM(4));
    rb_define_const(cNWScript, "IP_CONST_ADDITIONAL_UNKNOWN", INT2NUM(0));
    rb_define_const(cNWScript, "IP_CONST_ADDITIONAL_CURSED", INT2NUM(1));
    rb_define_const(cNWScript, "IP_CONST_ALIGNMENTGROUP_ALL", INT2NUM(0));
    rb_define_const(cNWScript, "IP_CONST_ALIGNMENTGROUP_NEUTRAL", INT2NUM(1));
    rb_define_const(cNWScript, "IP_CONST_ALIGNMENTGROUP_LAWFUL", INT2NUM(2));
    rb_define_const(cNWScript, "IP_CONST_ALIGNMENTGROUP_CHAOTIC", INT2NUM(3));
    rb_define_const(cNWScript, "IP_CONST_ALIGNMENTGROUP_GOOD", INT2NUM(4));
    rb_define_const(cNWScript, "IP_CONST_ALIGNMENTGROUP_EVIL", INT2NUM(5));
    rb_define_const(cNWScript, "IP_CONST_ALIGNMENT_LG", INT2NUM(0));
    rb_define_const(cNWScript, "IP_CONST_ALIGNMENT_LN", INT2NUM(1));
    rb_define_const(cNWScript, "IP_CONST_ALIGNMENT_LE", INT2NUM(2));
    rb_define_const(cNWScript, "IP_CONST_ALIGNMENT_NG", INT2NUM(3));
    rb_define_const(cNWScript, "IP_CONST_ALIGNMENT_TN", INT2NUM(4));
    rb_define_const(cNWScript, "IP_CONST_ALIGNMENT_NE", INT2NUM(5));
    rb_define_const(cNWScript, "IP_CONST_ALIGNMENT_CG", INT2NUM(6));
    rb_define_const(cNWScript, "IP_CONST_ALIGNMENT_CN", INT2NUM(7));
    rb_define_const(cNWScript, "IP_CONST_ALIGNMENT_CE", INT2NUM(8));
    rb_define_const(cNWScript, "IP_CONST_RACIALTYPE_DWARF", INT2NUM(0));
    rb_define_const(cNWScript, "IP_CONST_RACIALTYPE_ELF", INT2NUM(1));
    rb_define_const(cNWScript, "IP_CONST_RACIALTYPE_GNOME", INT2NUM(2));
    rb_define_const(cNWScript, "IP_CONST_RACIALTYPE_HALFLING", INT2NUM(3));
    rb_define_const(cNWScript, "IP_CONST_RACIALTYPE_HALFELF", INT2NUM(4));
    rb_define_const(cNWScript, "IP_CONST_RACIALTYPE_HALFORC", INT2NUM(5));
    rb_define_const(cNWScript, "IP_CONST_RACIALTYPE_HUMAN", INT2NUM(6));
    rb_define_const(cNWScript, "IP_CONST_RACIALTYPE_ABERRATION", INT2NUM(7));
    rb_define_const(cNWScript, "IP_CONST_RACIALTYPE_ANIMAL", INT2NUM(8));
    rb_define_const(cNWScript, "IP_CONST_RACIALTYPE_BEAST", INT2NUM(9));
    rb_define_const(cNWScript, "IP_CONST_RACIALTYPE_CONSTRUCT", INT2NUM(10));
    rb_define_const(cNWScript, "IP_CONST_RACIALTYPE_DRAGON", INT2NUM(11));
    rb_define_const(cNWScript, "IP_CONST_RACIALTYPE_HUMANOID_GOBLINOID", INT2NUM(12));
    rb_define_const(cNWScript, "IP_CONST_RACIALTYPE_HUMANOID_MONSTROUS", INT2NUM(13));
    rb_define_const(cNWScript, "IP_CONST_RACIALTYPE_HUMANOID_ORC", INT2NUM(14));
    rb_define_const(cNWScript, "IP_CONST_RACIALTYPE_HUMANOID_REPTILIAN", INT2NUM(15));
    rb_define_const(cNWScript, "IP_CONST_RACIALTYPE_ELEMENTAL", INT2NUM(16));
    rb_define_const(cNWScript, "IP_CONST_RACIALTYPE_FEY", INT2NUM(17));
    rb_define_const(cNWScript, "IP_CONST_RACIALTYPE_GIANT", INT2NUM(18));
    rb_define_const(cNWScript, "IP_CONST_RACIALTYPE_MAGICAL_BEAST", INT2NUM(19));
    rb_define_const(cNWScript, "IP_CONST_RACIALTYPE_OUTSIDER", INT2NUM(20));
    rb_define_const(cNWScript, "IP_CONST_RACIALTYPE_SHAPECHANGER", INT2NUM(23));
    rb_define_const(cNWScript, "IP_CONST_RACIALTYPE_UNDEAD", INT2NUM(24));
    rb_define_const(cNWScript, "IP_CONST_RACIALTYPE_VERMIN", INT2NUM(25));
    rb_define_const(cNWScript, "IP_CONST_UNLIMITEDAMMO_BASIC", INT2NUM(1));
    rb_define_const(cNWScript, "IP_CONST_UNLIMITEDAMMO_1D6FIRE", INT2NUM(2));
    rb_define_const(cNWScript, "IP_CONST_UNLIMITEDAMMO_1D6COLD", INT2NUM(3));
    rb_define_const(cNWScript, "IP_CONST_UNLIMITEDAMMO_1D6LIGHT", INT2NUM(4));
    rb_define_const(cNWScript, "IP_CONST_UNLIMITEDAMMO_PLUS1", INT2NUM(11));
    rb_define_const(cNWScript, "IP_CONST_UNLIMITEDAMMO_PLUS2", INT2NUM(12));
    rb_define_const(cNWScript, "IP_CONST_UNLIMITEDAMMO_PLUS3", INT2NUM(13));
    rb_define_const(cNWScript, "IP_CONST_UNLIMITEDAMMO_PLUS4", INT2NUM(14));
    rb_define_const(cNWScript, "IP_CONST_UNLIMITEDAMMO_PLUS5", INT2NUM(15));
    rb_define_const(cNWScript, "IP_CONST_AMMOTYPE_ARROW", INT2NUM(0));
    rb_define_const(cNWScript, "IP_CONST_AMMOTYPE_BOLT", INT2NUM(1));
    rb_define_const(cNWScript, "IP_CONST_AMMOTYPE_BULLET", INT2NUM(2));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_NUMUSES_SINGLE_USE", INT2NUM(1));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_NUMUSES_5_CHARGES_PER_USE", INT2NUM(2));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_NUMUSES_4_CHARGES_PER_USE", INT2NUM(3));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_NUMUSES_3_CHARGES_PER_USE", INT2NUM(4));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_NUMUSES_2_CHARGES_PER_USE", INT2NUM(5));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_NUMUSES_1_CHARGE_PER_USE", INT2NUM(6));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_NUMUSES_0_CHARGES_PER_USE", INT2NUM(7));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_NUMUSES_1_USE_PER_DAY", INT2NUM(8));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_NUMUSES_2_USES_PER_DAY", INT2NUM(9));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_NUMUSES_3_USES_PER_DAY", INT2NUM(10));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_NUMUSES_4_USES_PER_DAY", INT2NUM(11));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_NUMUSES_5_USES_PER_DAY", INT2NUM(12));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_NUMUSES_UNLIMITED_USE", INT2NUM(13));
    rb_define_const(cNWScript, "IP_CONST_DAMAGEBONUS_1", INT2NUM(1));
    rb_define_const(cNWScript, "IP_CONST_DAMAGEBONUS_2", INT2NUM(2));
    rb_define_const(cNWScript, "IP_CONST_DAMAGEBONUS_3", INT2NUM(3));
    rb_define_const(cNWScript, "IP_CONST_DAMAGEBONUS_4", INT2NUM(4));
    rb_define_const(cNWScript, "IP_CONST_DAMAGEBONUS_5", INT2NUM(5));
    rb_define_const(cNWScript, "IP_CONST_DAMAGEBONUS_1d4", INT2NUM(6));
    rb_define_const(cNWScript, "IP_CONST_DAMAGEBONUS_1d6", INT2NUM(7));
    rb_define_const(cNWScript, "IP_CONST_DAMAGEBONUS_1d8", INT2NUM(8));
    rb_define_const(cNWScript, "IP_CONST_DAMAGEBONUS_1d10", INT2NUM(9));
    rb_define_const(cNWScript, "IP_CONST_DAMAGEBONUS_2d6", INT2NUM(10));
    rb_define_const(cNWScript, "IP_CONST_DAMAGEBONUS_2d8", INT2NUM(11));
    rb_define_const(cNWScript, "IP_CONST_DAMAGEBONUS_2d4", INT2NUM(12));
    rb_define_const(cNWScript, "IP_CONST_DAMAGEBONUS_2d10", INT2NUM(13));
    rb_define_const(cNWScript, "IP_CONST_DAMAGEBONUS_1d12", INT2NUM(14));
    rb_define_const(cNWScript, "IP_CONST_DAMAGEBONUS_2d12", INT2NUM(15));
    rb_define_const(cNWScript, "IP_CONST_DAMAGEBONUS_6", INT2NUM(16));
    rb_define_const(cNWScript, "IP_CONST_DAMAGEBONUS_7", INT2NUM(17));
    rb_define_const(cNWScript, "IP_CONST_DAMAGEBONUS_8", INT2NUM(18));
    rb_define_const(cNWScript, "IP_CONST_DAMAGEBONUS_9", INT2NUM(19));
    rb_define_const(cNWScript, "IP_CONST_DAMAGEBONUS_10", INT2NUM(20));
    rb_define_const(cNWScript, "IP_CONST_DAMAGETYPE_BLUDGEONING", INT2NUM(0));
    rb_define_const(cNWScript, "IP_CONST_DAMAGETYPE_PIERCING", INT2NUM(1));
    rb_define_const(cNWScript, "IP_CONST_DAMAGETYPE_SLASHING", INT2NUM(2));
    rb_define_const(cNWScript, "IP_CONST_DAMAGETYPE_SUBDUAL", INT2NUM(3));
    rb_define_const(cNWScript, "IP_CONST_DAMAGETYPE_PHYSICAL", INT2NUM(4));
    rb_define_const(cNWScript, "IP_CONST_DAMAGETYPE_MAGICAL", INT2NUM(5));
    rb_define_const(cNWScript, "IP_CONST_DAMAGETYPE_ACID", INT2NUM(6));
    rb_define_const(cNWScript, "IP_CONST_DAMAGETYPE_COLD", INT2NUM(7));
    rb_define_const(cNWScript, "IP_CONST_DAMAGETYPE_DIVINE", INT2NUM(8));
    rb_define_const(cNWScript, "IP_CONST_DAMAGETYPE_ELECTRICAL", INT2NUM(9));
    rb_define_const(cNWScript, "IP_CONST_DAMAGETYPE_FIRE", INT2NUM(10));
    rb_define_const(cNWScript, "IP_CONST_DAMAGETYPE_NEGATIVE", INT2NUM(11));
    rb_define_const(cNWScript, "IP_CONST_DAMAGETYPE_POSITIVE", INT2NUM(12));
    rb_define_const(cNWScript, "IP_CONST_DAMAGETYPE_SONIC", INT2NUM(13));
    rb_define_const(cNWScript, "IP_CONST_DAMAGEIMMUNITY_5_PERCENT", INT2NUM(1));
    rb_define_const(cNWScript, "IP_CONST_DAMAGEIMMUNITY_10_PERCENT", INT2NUM(2));
    rb_define_const(cNWScript, "IP_CONST_DAMAGEIMMUNITY_25_PERCENT", INT2NUM(3));
    rb_define_const(cNWScript, "IP_CONST_DAMAGEIMMUNITY_50_PERCENT", INT2NUM(4));
    rb_define_const(cNWScript, "IP_CONST_DAMAGEIMMUNITY_75_PERCENT", INT2NUM(5));
    rb_define_const(cNWScript, "IP_CONST_DAMAGEIMMUNITY_90_PERCENT", INT2NUM(6));
    rb_define_const(cNWScript, "IP_CONST_DAMAGEIMMUNITY_100_PERCENT", INT2NUM(7));
    rb_define_const(cNWScript, "IP_CONST_DAMAGEVULNERABILITY_5_PERCENT", INT2NUM(1));
    rb_define_const(cNWScript, "IP_CONST_DAMAGEVULNERABILITY_10_PERCENT", INT2NUM(2));
    rb_define_const(cNWScript, "IP_CONST_DAMAGEVULNERABILITY_25_PERCENT", INT2NUM(3));
    rb_define_const(cNWScript, "IP_CONST_DAMAGEVULNERABILITY_50_PERCENT", INT2NUM(4));
    rb_define_const(cNWScript, "IP_CONST_DAMAGEVULNERABILITY_75_PERCENT", INT2NUM(5));
    rb_define_const(cNWScript, "IP_CONST_DAMAGEVULNERABILITY_90_PERCENT", INT2NUM(6));
    rb_define_const(cNWScript, "IP_CONST_DAMAGEVULNERABILITY_100_PERCENT", INT2NUM(7));
    rb_define_const(cNWScript, "IP_CONST_FEAT_ALERTNESS", INT2NUM(0));
    rb_define_const(cNWScript, "IP_CONST_FEAT_AMBIDEXTROUS", INT2NUM(1));
    rb_define_const(cNWScript, "IP_CONST_FEAT_CLEAVE", INT2NUM(2));
    rb_define_const(cNWScript, "IP_CONST_FEAT_COMBAT_CASTING", INT2NUM(3));
    rb_define_const(cNWScript, "IP_CONST_FEAT_DODGE", INT2NUM(4));
    rb_define_const(cNWScript, "IP_CONST_FEAT_EXTRA_TURNING", INT2NUM(5));
    rb_define_const(cNWScript, "IP_CONST_FEAT_KNOCKDOWN", INT2NUM(6));
    rb_define_const(cNWScript, "IP_CONST_FEAT_POINTBLANK", INT2NUM(7));
    rb_define_const(cNWScript, "IP_CONST_FEAT_SPELLFOCUSABJ", INT2NUM(8));
    rb_define_const(cNWScript, "IP_CONST_FEAT_SPELLFOCUSCON", INT2NUM(9));
    rb_define_const(cNWScript, "IP_CONST_FEAT_SPELLFOCUSDIV", INT2NUM(10));
    rb_define_const(cNWScript, "IP_CONST_FEAT_SPELLFOCUSENC", INT2NUM(11));
    rb_define_const(cNWScript, "IP_CONST_FEAT_SPELLFOCUSEVO", INT2NUM(12));
    rb_define_const(cNWScript, "IP_CONST_FEAT_SPELLFOCUSILL", INT2NUM(13));
    rb_define_const(cNWScript, "IP_CONST_FEAT_SPELLFOCUSNEC", INT2NUM(14));
    rb_define_const(cNWScript, "IP_CONST_FEAT_SPELLPENETRATION", INT2NUM(15));
    rb_define_const(cNWScript, "IP_CONST_FEAT_POWERATTACK", INT2NUM(16));
    rb_define_const(cNWScript, "IP_CONST_FEAT_TWO_WEAPON_FIGHTING", INT2NUM(17));
    rb_define_const(cNWScript, "IP_CONST_FEAT_WEAPSPEUNARM", INT2NUM(18));
    rb_define_const(cNWScript, "IP_CONST_FEAT_WEAPFINESSE", INT2NUM(19));
    rb_define_const(cNWScript, "IP_CONST_FEAT_IMPCRITUNARM", INT2NUM(20));
    rb_define_const(cNWScript, "IP_CONST_FEAT_WEAPON_PROF_EXOTIC", INT2NUM(21));
    rb_define_const(cNWScript, "IP_CONST_FEAT_WEAPON_PROF_MARTIAL", INT2NUM(22));
    rb_define_const(cNWScript, "IP_CONST_FEAT_WEAPON_PROF_SIMPLE", INT2NUM(23));
    rb_define_const(cNWScript, "IP_CONST_FEAT_ARMOR_PROF_HEAVY", INT2NUM(24));
    rb_define_const(cNWScript, "IP_CONST_FEAT_ARMOR_PROF_LIGHT", INT2NUM(25));
    rb_define_const(cNWScript, "IP_CONST_FEAT_ARMOR_PROF_MEDIUM", INT2NUM(26));
    rb_define_const(cNWScript, "IP_CONST_FEAT_MOBILITY", INT2NUM(27));
    rb_define_const(cNWScript, "IP_CONST_FEAT_DISARM", INT2NUM(28));
    rb_define_const(cNWScript, "IP_CONST_FEAT_WHIRLWIND", INT2NUM(29));
    rb_define_const(cNWScript, "IP_CONST_FEAT_RAPID_SHOT", INT2NUM(30));
    rb_define_const(cNWScript, "IP_CONST_FEAT_HIDE_IN_PLAIN_SIGHT", INT2NUM(31));
    rb_define_const(cNWScript, "IP_CONST_FEAT_SNEAK_ATTACK_1D6", INT2NUM(32));
    rb_define_const(cNWScript, "IP_CONST_FEAT_SNEAK_ATTACK_2D6", INT2NUM(33));
    rb_define_const(cNWScript, "IP_CONST_FEAT_SNEAK_ATTACK_3D6", INT2NUM(34));
    rb_define_const(cNWScript, "IP_CONST_FEAT_SHIELD_PROFICIENCY", INT2NUM(35));
    rb_define_const(cNWScript, "IP_CONST_FEAT_USE_POISON", INT2NUM(36));
    rb_define_const(cNWScript, "IP_CONST_FEAT_DISARM_WHIP", INT2NUM(37));
    rb_define_const(cNWScript, "IP_CONST_FEAT_WEAPON_PROF_CREATURE", INT2NUM(38));
    rb_define_const(cNWScript, "IP_CONST_FEAT_SNEAK_ATTACK_5D6", INT2NUM(39));
    rb_define_const(cNWScript, "IP_CONST_FEAT_PLAYER_TOOL_01", INT2NUM(53));
    rb_define_const(cNWScript, "IP_CONST_FEAT_PLAYER_TOOL_02", INT2NUM(54));
    rb_define_const(cNWScript, "IP_CONST_FEAT_PLAYER_TOOL_03", INT2NUM(55));
    rb_define_const(cNWScript, "IP_CONST_FEAT_PLAYER_TOOL_04", INT2NUM(56));
    rb_define_const(cNWScript, "IP_CONST_FEAT_PLAYER_TOOL_05", INT2NUM(57));
    rb_define_const(cNWScript, "IP_CONST_FEAT_PLAYER_TOOL_06", INT2NUM(58));
    rb_define_const(cNWScript, "IP_CONST_FEAT_PLAYER_TOOL_07", INT2NUM(59));
    rb_define_const(cNWScript, "IP_CONST_FEAT_PLAYER_TOOL_08", INT2NUM(60));
    rb_define_const(cNWScript, "IP_CONST_FEAT_PLAYER_TOOL_09", INT2NUM(61));
    rb_define_const(cNWScript, "IP_CONST_FEAT_PLAYER_TOOL_10", INT2NUM(62));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYMISC_BACKSTAB", INT2NUM(0));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYMISC_LEVEL_ABIL_DRAIN", INT2NUM(1));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYMISC_MINDSPELLS", INT2NUM(2));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYMISC_POISON", INT2NUM(3));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYMISC_DISEASE", INT2NUM(4));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYMISC_FEAR", INT2NUM(5));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYMISC_KNOCKDOWN", INT2NUM(6));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYMISC_PARALYSIS", INT2NUM(7));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYMISC_CRITICAL_HITS", INT2NUM(8));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYMISC_DEATH_MAGIC", INT2NUM(9));
    rb_define_const(cNWScript, "IP_CONST_LIGHTBRIGHTNESS_DIM", INT2NUM(1));
    rb_define_const(cNWScript, "IP_CONST_LIGHTBRIGHTNESS_LOW", INT2NUM(2));
    rb_define_const(cNWScript, "IP_CONST_LIGHTBRIGHTNESS_NORMAL", INT2NUM(3));
    rb_define_const(cNWScript, "IP_CONST_LIGHTBRIGHTNESS_BRIGHT", INT2NUM(4));
    rb_define_const(cNWScript, "IP_CONST_LIGHTCOLOR_BLUE", INT2NUM(0));
    rb_define_const(cNWScript, "IP_CONST_LIGHTCOLOR_YELLOW", INT2NUM(1));
    rb_define_const(cNWScript, "IP_CONST_LIGHTCOLOR_PURPLE", INT2NUM(2));
    rb_define_const(cNWScript, "IP_CONST_LIGHTCOLOR_RED", INT2NUM(3));
    rb_define_const(cNWScript, "IP_CONST_LIGHTCOLOR_GREEN", INT2NUM(4));
    rb_define_const(cNWScript, "IP_CONST_LIGHTCOLOR_ORANGE", INT2NUM(5));
    rb_define_const(cNWScript, "IP_CONST_LIGHTCOLOR_WHITE", INT2NUM(6));
    rb_define_const(cNWScript, "IP_CONST_MONSTERDAMAGE_1d2", INT2NUM(1));
    rb_define_const(cNWScript, "IP_CONST_MONSTERDAMAGE_1d3", INT2NUM(2));
    rb_define_const(cNWScript, "IP_CONST_MONSTERDAMAGE_1d4", INT2NUM(3));
    rb_define_const(cNWScript, "IP_CONST_MONSTERDAMAGE_2d4", INT2NUM(4));
    rb_define_const(cNWScript, "IP_CONST_MONSTERDAMAGE_3d4", INT2NUM(5));
    rb_define_const(cNWScript, "IP_CONST_MONSTERDAMAGE_4d4", INT2NUM(6));
    rb_define_const(cNWScript, "IP_CONST_MONSTERDAMAGE_5d4", INT2NUM(7));
    rb_define_const(cNWScript, "IP_CONST_MONSTERDAMAGE_1d6", INT2NUM(8));
    rb_define_const(cNWScript, "IP_CONST_MONSTERDAMAGE_2d6", INT2NUM(9));
    rb_define_const(cNWScript, "IP_CONST_MONSTERDAMAGE_3d6", INT2NUM(10));
    rb_define_const(cNWScript, "IP_CONST_MONSTERDAMAGE_4d6", INT2NUM(11));
    rb_define_const(cNWScript, "IP_CONST_MONSTERDAMAGE_5d6", INT2NUM(12));
    rb_define_const(cNWScript, "IP_CONST_MONSTERDAMAGE_6d6", INT2NUM(13));
    rb_define_const(cNWScript, "IP_CONST_MONSTERDAMAGE_7d6", INT2NUM(14));
    rb_define_const(cNWScript, "IP_CONST_MONSTERDAMAGE_8d6", INT2NUM(15));
    rb_define_const(cNWScript, "IP_CONST_MONSTERDAMAGE_9d6", INT2NUM(16));
    rb_define_const(cNWScript, "IP_CONST_MONSTERDAMAGE_10d6", INT2NUM(17));
    rb_define_const(cNWScript, "IP_CONST_MONSTERDAMAGE_1d8", INT2NUM(18));
    rb_define_const(cNWScript, "IP_CONST_MONSTERDAMAGE_2d8", INT2NUM(19));
    rb_define_const(cNWScript, "IP_CONST_MONSTERDAMAGE_3d8", INT2NUM(20));
    rb_define_const(cNWScript, "IP_CONST_MONSTERDAMAGE_4d8", INT2NUM(21));
    rb_define_const(cNWScript, "IP_CONST_MONSTERDAMAGE_5d8", INT2NUM(22));
    rb_define_const(cNWScript, "IP_CONST_MONSTERDAMAGE_6d8", INT2NUM(23));
    rb_define_const(cNWScript, "IP_CONST_MONSTERDAMAGE_7d8", INT2NUM(24));
    rb_define_const(cNWScript, "IP_CONST_MONSTERDAMAGE_8d8", INT2NUM(25));
    rb_define_const(cNWScript, "IP_CONST_MONSTERDAMAGE_9d8", INT2NUM(26));
    rb_define_const(cNWScript, "IP_CONST_MONSTERDAMAGE_10d8", INT2NUM(27));
    rb_define_const(cNWScript, "IP_CONST_MONSTERDAMAGE_1d10", INT2NUM(28));
    rb_define_const(cNWScript, "IP_CONST_MONSTERDAMAGE_2d10", INT2NUM(29));
    rb_define_const(cNWScript, "IP_CONST_MONSTERDAMAGE_3d10", INT2NUM(30));
    rb_define_const(cNWScript, "IP_CONST_MONSTERDAMAGE_4d10", INT2NUM(31));
    rb_define_const(cNWScript, "IP_CONST_MONSTERDAMAGE_5d10", INT2NUM(32));
    rb_define_const(cNWScript, "IP_CONST_MONSTERDAMAGE_6d10", INT2NUM(33));
    rb_define_const(cNWScript, "IP_CONST_MONSTERDAMAGE_7d10", INT2NUM(34));
    rb_define_const(cNWScript, "IP_CONST_MONSTERDAMAGE_8d10", INT2NUM(35));
    rb_define_const(cNWScript, "IP_CONST_MONSTERDAMAGE_9d10", INT2NUM(36));
    rb_define_const(cNWScript, "IP_CONST_MONSTERDAMAGE_10d10", INT2NUM(37));
    rb_define_const(cNWScript, "IP_CONST_MONSTERDAMAGE_1d12", INT2NUM(38));
    rb_define_const(cNWScript, "IP_CONST_MONSTERDAMAGE_2d12", INT2NUM(39));
    rb_define_const(cNWScript, "IP_CONST_MONSTERDAMAGE_3d12", INT2NUM(40));
    rb_define_const(cNWScript, "IP_CONST_MONSTERDAMAGE_4d12", INT2NUM(41));
    rb_define_const(cNWScript, "IP_CONST_MONSTERDAMAGE_5d12", INT2NUM(42));
    rb_define_const(cNWScript, "IP_CONST_MONSTERDAMAGE_6d12", INT2NUM(43));
    rb_define_const(cNWScript, "IP_CONST_MONSTERDAMAGE_7d12", INT2NUM(44));
    rb_define_const(cNWScript, "IP_CONST_MONSTERDAMAGE_8d12", INT2NUM(45));
    rb_define_const(cNWScript, "IP_CONST_MONSTERDAMAGE_9d12", INT2NUM(46));
    rb_define_const(cNWScript, "IP_CONST_MONSTERDAMAGE_10d12", INT2NUM(47));
    rb_define_const(cNWScript, "IP_CONST_MONSTERDAMAGE_1d20", INT2NUM(48));
    rb_define_const(cNWScript, "IP_CONST_MONSTERDAMAGE_2d20", INT2NUM(49));
    rb_define_const(cNWScript, "IP_CONST_MONSTERDAMAGE_3d20", INT2NUM(50));
    rb_define_const(cNWScript, "IP_CONST_MONSTERDAMAGE_4d20", INT2NUM(51));
    rb_define_const(cNWScript, "IP_CONST_MONSTERDAMAGE_5d20", INT2NUM(52));
    rb_define_const(cNWScript, "IP_CONST_MONSTERDAMAGE_6d20", INT2NUM(53));
    rb_define_const(cNWScript, "IP_CONST_MONSTERDAMAGE_7d20", INT2NUM(54));
    rb_define_const(cNWScript, "IP_CONST_MONSTERDAMAGE_8d20", INT2NUM(55));
    rb_define_const(cNWScript, "IP_CONST_MONSTERDAMAGE_9d20", INT2NUM(56));
    rb_define_const(cNWScript, "IP_CONST_MONSTERDAMAGE_10d20", INT2NUM(57));
    rb_define_const(cNWScript, "IP_CONST_ONMONSTERHIT_ABILITYDRAIN", INT2NUM(0));
    rb_define_const(cNWScript, "IP_CONST_ONMONSTERHIT_CONFUSION", INT2NUM(1));
    rb_define_const(cNWScript, "IP_CONST_ONMONSTERHIT_DISEASE", INT2NUM(2));
    rb_define_const(cNWScript, "IP_CONST_ONMONSTERHIT_DOOM", INT2NUM(3));
    rb_define_const(cNWScript, "IP_CONST_ONMONSTERHIT_FEAR", INT2NUM(4));
    rb_define_const(cNWScript, "IP_CONST_ONMONSTERHIT_LEVELDRAIN", INT2NUM(5));
    rb_define_const(cNWScript, "IP_CONST_ONMONSTERHIT_POISON", INT2NUM(6));
    rb_define_const(cNWScript, "IP_CONST_ONMONSTERHIT_SLOW", INT2NUM(7));
    rb_define_const(cNWScript, "IP_CONST_ONMONSTERHIT_STUN", INT2NUM(8));
    rb_define_const(cNWScript, "IP_CONST_ONMONSTERHIT_WOUNDING", INT2NUM(9));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_SLEEP", INT2NUM(0));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_STUN", INT2NUM(1));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_HOLD", INT2NUM(2));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CONFUSION", INT2NUM(3));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_DAZE", INT2NUM(5));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_DOOM", INT2NUM(6));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_FEAR", INT2NUM(7));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_KNOCK", INT2NUM(8));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_SLOW", INT2NUM(9));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_LESSERDISPEL", INT2NUM(10));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_DISPELMAGIC", INT2NUM(11));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_GREATERDISPEL", INT2NUM(12));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_MORDSDISJUNCTION", INT2NUM(13));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_SILENCE", INT2NUM(14));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_DEAFNESS", INT2NUM(15));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_BLINDNESS", INT2NUM(16));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_LEVELDRAIN", INT2NUM(17));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_ABILITYDRAIN", INT2NUM(18));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_ITEMPOISON", INT2NUM(19));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_DISEASE", INT2NUM(20));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_SLAYRACE", INT2NUM(21));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_SLAYALIGNMENTGROUP", INT2NUM(22));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_SLAYALIGNMENT", INT2NUM(23));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_VORPAL", INT2NUM(24));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_WOUNDING", INT2NUM(25));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_SAVEDC_14", INT2NUM(0));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_SAVEDC_16", INT2NUM(1));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_SAVEDC_18", INT2NUM(2));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_SAVEDC_20", INT2NUM(3));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_SAVEDC_22", INT2NUM(4));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_SAVEDC_24", INT2NUM(5));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_SAVEDC_26", INT2NUM(6));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_DURATION_5_PERCENT_5_ROUNDS", INT2NUM(0));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_DURATION_10_PERCENT_4_ROUNDS", INT2NUM(1));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_DURATION_25_PERCENT_3_ROUNDS", INT2NUM(2));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_DURATION_50_PERCENT_2_ROUNDS", INT2NUM(3));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_DURATION_75_PERCENT_1_ROUND", INT2NUM(4));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_ACID_FOG", INT2NUM(0));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_BESTOW_CURSE", INT2NUM(1));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_BLADE_BARRIER", INT2NUM(2));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_BLINDNESS_AND_DEAFNESS", INT2NUM(3));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_CALL_LIGHTNING", INT2NUM(4));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_CHAIN_LIGHTNING", INT2NUM(5));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_CLOUDKILL", INT2NUM(6));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_CONFUSION", INT2NUM(7));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_CONTAGION", INT2NUM(8));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_DARKNESS", INT2NUM(9));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_DAZE", INT2NUM(10));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_DELAYED_BLAST_FIREBALL", INT2NUM(11));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_DISMISSAL", INT2NUM(12));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_DISPEL_MAGIC", INT2NUM(13));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_DOOM", INT2NUM(14));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_ENERGY_DRAIN", INT2NUM(15));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_ENERVATION", INT2NUM(16));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_ENTANGLE", INT2NUM(17));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_FEAR", INT2NUM(18));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_FEEBLEMIND", INT2NUM(19));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_FIRE_STORM", INT2NUM(20));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_FIREBALL", INT2NUM(21));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_FLAME_LASH", INT2NUM(22));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_FLAME_STRIKE", INT2NUM(23));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_GHOUL_TOUCH", INT2NUM(24));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_GREASE", INT2NUM(25));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_GREATER_DISPELLING", INT2NUM(26));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_GREATER_SPELL_BREACH", INT2NUM(27));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_GUST_OF_WIND", INT2NUM(28));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_HAMMER_OF_THE_GODS", INT2NUM(29));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_HARM", INT2NUM(30));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_HOLD_ANIMAL", INT2NUM(31));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_HOLD_MONSTER", INT2NUM(32));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_HOLD_PERSON", INT2NUM(33));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_IMPLOSION", INT2NUM(34));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_INCENDIARY_CLOUD", INT2NUM(35));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_LESSER_DISPEL", INT2NUM(36));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_LESSER_SPELL_BREACH", INT2NUM(38));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_LIGHT", INT2NUM(40));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_LIGHTNING_BOLT", INT2NUM(41));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_MAGIC_MISSILE", INT2NUM(42));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_MASS_BLINDNESS_AND_DEAFNESS", INT2NUM(43));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_MASS_CHARM", INT2NUM(44));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_MELFS_ACID_ARROW", INT2NUM(45));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_METEOR_SWARM", INT2NUM(46));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_MIND_FOG", INT2NUM(47));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_PHANTASMAL_KILLER", INT2NUM(49));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_POISON", INT2NUM(50));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_POWER_WORD_KILL", INT2NUM(51));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_POWER_WORD_STUN", INT2NUM(52));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_SCARE", INT2NUM(54));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_SEARING_LIGHT", INT2NUM(55));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_SILENCE", INT2NUM(56));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_SLAY_LIVING", INT2NUM(57));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_SLEEP", INT2NUM(58));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_SLOW", INT2NUM(59));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_SOUND_BURST", INT2NUM(60));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_STINKING_CLOUD", INT2NUM(61));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_STORM_OF_VENGEANCE", INT2NUM(63));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_SUNBEAM", INT2NUM(64));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_VAMPIRIC_TOUCH", INT2NUM(65));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_WAIL_OF_THE_BANSHEE", INT2NUM(66));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_WALL_OF_FIRE", INT2NUM(67));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_WEB", INT2NUM(68));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_WEIRD", INT2NUM(69));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_WORD_OF_FAITH", INT2NUM(70));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_CREEPING_DOOM", INT2NUM(72));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_DESTRUCTION", INT2NUM(73));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_HORRID_WILTING", INT2NUM(74));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_ICE_STORM", INT2NUM(75));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_NEGATIVE_ENERGY_BURST", INT2NUM(76));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_EVARDS_BLACK_TENTACLES", INT2NUM(77));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_ACTIVATE_ITEM", INT2NUM(78));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_FLARE", INT2NUM(79));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_BOMBARDMENT", INT2NUM(80));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_ACID_SPLASH", INT2NUM(81));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_QUILLFIRE", INT2NUM(82));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_EARTHQUAKE", INT2NUM(83));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_SUNBURST", INT2NUM(84));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_BANISHMENT", INT2NUM(85));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_INFLICT_MINOR_WOUNDS", INT2NUM(86));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_INFLICT_LIGHT_WOUNDS", INT2NUM(87));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_INFLICT_MODERATE_WOUNDS", INT2NUM(88));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_INFLICT_SERIOUS_WOUNDS", INT2NUM(89));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_INFLICT_CRITICAL_WOUNDS", INT2NUM(90));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_BALAGARNSIRONHORN", INT2NUM(91));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_DROWN", INT2NUM(92));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_ELECTRIC_JOLT", INT2NUM(93));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_FIREBRAND", INT2NUM(94));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_WOUNDING_WHISPERS", INT2NUM(95));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_UNDEATHS_ETERNAL_FOE", INT2NUM(96));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_INFERNO", INT2NUM(97));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_ISAACS_LESSER_MISSILE_STORM", INT2NUM(98));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_ISAACS_GREATER_MISSILE_STORM", INT2NUM(99));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_BANE", INT2NUM(100));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_SPIKE_GROWTH", INT2NUM(101));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_TASHAS_HIDEOUS_LAUGHTER", INT2NUM(102));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_BIGBYS_INTERPOSING_HAND", INT2NUM(103));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_BIGBYS_FORCEFUL_HAND", INT2NUM(104));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_BIGBYS_GRASPING_HAND", INT2NUM(105));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_BIGBYS_CLENCHED_FIST", INT2NUM(106));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_BIGBYS_CRUSHING_HAND", INT2NUM(107));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_FLESH_TO_STONE", INT2NUM(108));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_STONE_TO_FLESH", INT2NUM(109));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_CRUMBLE", INT2NUM(110));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_INFESTATION_OF_MAGGOTS", INT2NUM(111));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_GREAT_THUNDERCLAP", INT2NUM(112));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_BALL_LIGHTNING", INT2NUM(113));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_GEDLEES_ELECTRIC_LOOP", INT2NUM(114));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_HORIZIKAULS_BOOM", INT2NUM(115));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_MESTILS_ACID_BREATH", INT2NUM(116));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_SCINTILLATING_SPHERE", INT2NUM(117));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_UNDEATH_TO_DEATH", INT2NUM(118));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_STONEHOLD", INT2NUM(119));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_EVIL_BLIGHT", INT2NUM(121));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_ONHIT_TELEPORT", INT2NUM(122));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_ONHIT_SLAYRAKSHASA", INT2NUM(123));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_ONHIT_FIREDAMAGE", INT2NUM(124));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_ONHIT_UNIQUEPOWER", INT2NUM(125));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_ONHIT_PLANARRIFT", INT2NUM(126));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_ONHIT_DARKFIRE", INT2NUM(127));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_ONHIT_EXTRACTBRAIN", INT2NUM(128));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_ONHITFLAMINGSKIN", INT2NUM(129));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_ONHIT_CHAOSSHIELD", INT2NUM(130));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_ONHIT_CONSTRICTWEAPON", INT2NUM(131));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_ONHITRUINARMORBEBILITH", INT2NUM(132));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_ONHITDEMILICHTOUCH", INT2NUM(133));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_ONHITDRACOLICHTOUCH", INT2NUM(134));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_INTELLIGENT_WEAPON_ONHIT", INT2NUM(135));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_PARALYZE_2", INT2NUM(136));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_DEAFENING_CLNG", INT2NUM(137));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_KNOCKDOWN", INT2NUM(138));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_FREEZE", INT2NUM(139));
    rb_define_const(cNWScript, "IP_CONST_ONHIT_CASTSPELL_COMBUST", INT2NUM(140));
    rb_define_const(cNWScript, "IP_CONST_POISON_1D2_STRDAMAGE", INT2NUM(0));
    rb_define_const(cNWScript, "IP_CONST_POISON_1D2_DEXDAMAGE", INT2NUM(1));
    rb_define_const(cNWScript, "IP_CONST_POISON_1D2_CONDAMAGE", INT2NUM(2));
    rb_define_const(cNWScript, "IP_CONST_POISON_1D2_INTDAMAGE", INT2NUM(3));
    rb_define_const(cNWScript, "IP_CONST_POISON_1D2_WISDAMAGE", INT2NUM(4));
    rb_define_const(cNWScript, "IP_CONST_POISON_1D2_CHADAMAGE", INT2NUM(5));
    rb_define_const(cNWScript, "IP_CONST_QUALITY_UNKOWN", INT2NUM(0));
    rb_define_const(cNWScript, "IP_CONST_QUALITY_DESTROYED", INT2NUM(1));
    rb_define_const(cNWScript, "IP_CONST_QUALITY_RUINED", INT2NUM(2));
    rb_define_const(cNWScript, "IP_CONST_QUALITY_VERY_POOR", INT2NUM(3));
    rb_define_const(cNWScript, "IP_CONST_QUALITY_POOR", INT2NUM(4));
    rb_define_const(cNWScript, "IP_CONST_QUALITY_BELOW_AVERAGE", INT2NUM(5));
    rb_define_const(cNWScript, "IP_CONST_QUALITY_AVERAGE", INT2NUM(6));
    rb_define_const(cNWScript, "IP_CONST_QUALITY_ABOVE_AVERAGE", INT2NUM(7));
    rb_define_const(cNWScript, "IP_CONST_QUALITY_GOOD", INT2NUM(8));
    rb_define_const(cNWScript, "IP_CONST_QUALITY_VERY_GOOD", INT2NUM(9));
    rb_define_const(cNWScript, "IP_CONST_QUALITY_EXCELLENT", INT2NUM(10));
    rb_define_const(cNWScript, "IP_CONST_QUALITY_MASTERWORK", INT2NUM(11));
    rb_define_const(cNWScript, "IP_CONST_QUALITY_GOD_LIKE", INT2NUM(12));
    rb_define_const(cNWScript, "IP_CONST_QUALITY_RAW", INT2NUM(13));
    rb_define_const(cNWScript, "IP_CONST_QUALITY_CUT", INT2NUM(14));
    rb_define_const(cNWScript, "IP_CONST_QUALITY_POLISHED", INT2NUM(15));
    rb_define_const(cNWScript, "IP_CONST_CONTAINERWEIGHTRED_20_PERCENT", INT2NUM(1));
    rb_define_const(cNWScript, "IP_CONST_CONTAINERWEIGHTRED_40_PERCENT", INT2NUM(2));
    rb_define_const(cNWScript, "IP_CONST_CONTAINERWEIGHTRED_60_PERCENT", INT2NUM(3));
    rb_define_const(cNWScript, "IP_CONST_CONTAINERWEIGHTRED_80_PERCENT", INT2NUM(4));
    rb_define_const(cNWScript, "IP_CONST_CONTAINERWEIGHTRED_100_PERCENT", INT2NUM(5));
    rb_define_const(cNWScript, "IP_CONST_DAMAGERESIST_5", INT2NUM(1));
    rb_define_const(cNWScript, "IP_CONST_DAMAGERESIST_10", INT2NUM(2));
    rb_define_const(cNWScript, "IP_CONST_DAMAGERESIST_15", INT2NUM(3));
    rb_define_const(cNWScript, "IP_CONST_DAMAGERESIST_20", INT2NUM(4));
    rb_define_const(cNWScript, "IP_CONST_DAMAGERESIST_25", INT2NUM(5));
    rb_define_const(cNWScript, "IP_CONST_DAMAGERESIST_30", INT2NUM(6));
    rb_define_const(cNWScript, "IP_CONST_DAMAGERESIST_35", INT2NUM(7));
    rb_define_const(cNWScript, "IP_CONST_DAMAGERESIST_40", INT2NUM(8));
    rb_define_const(cNWScript, "IP_CONST_DAMAGERESIST_45", INT2NUM(9));
    rb_define_const(cNWScript, "IP_CONST_DAMAGERESIST_50", INT2NUM(10));
    rb_define_const(cNWScript, "IP_CONST_SAVEVS_ACID", INT2NUM(1));
    rb_define_const(cNWScript, "IP_CONST_SAVEVS_COLD", INT2NUM(3));
    rb_define_const(cNWScript, "IP_CONST_SAVEVS_DEATH", INT2NUM(4));
    rb_define_const(cNWScript, "IP_CONST_SAVEVS_DISEASE", INT2NUM(5));
    rb_define_const(cNWScript, "IP_CONST_SAVEVS_DIVINE", INT2NUM(6));
    rb_define_const(cNWScript, "IP_CONST_SAVEVS_ELECTRICAL", INT2NUM(7));
    rb_define_const(cNWScript, "IP_CONST_SAVEVS_FEAR", INT2NUM(8));
    rb_define_const(cNWScript, "IP_CONST_SAVEVS_FIRE", INT2NUM(9));
    rb_define_const(cNWScript, "IP_CONST_SAVEVS_MINDAFFECTING", INT2NUM(11));
    rb_define_const(cNWScript, "IP_CONST_SAVEVS_NEGATIVE", INT2NUM(12));
    rb_define_const(cNWScript, "IP_CONST_SAVEVS_POISON", INT2NUM(13));
    rb_define_const(cNWScript, "IP_CONST_SAVEVS_POSITIVE", INT2NUM(14));
    rb_define_const(cNWScript, "IP_CONST_SAVEVS_SONIC", INT2NUM(15));
    rb_define_const(cNWScript, "IP_CONST_SAVEVS_UNIVERSAL", INT2NUM(0));
    rb_define_const(cNWScript, "IP_CONST_SAVEBASETYPE_FORTITUDE", INT2NUM(1));
    rb_define_const(cNWScript, "IP_CONST_SAVEBASETYPE_WILL", INT2NUM(2));
    rb_define_const(cNWScript, "IP_CONST_SAVEBASETYPE_REFLEX", INT2NUM(3));
    rb_define_const(cNWScript, "IP_CONST_DAMAGESOAK_5_HP", INT2NUM(1));
    rb_define_const(cNWScript, "IP_CONST_DAMAGESOAK_10_HP", INT2NUM(2));
    rb_define_const(cNWScript, "IP_CONST_DAMAGESOAK_15_HP", INT2NUM(3));
    rb_define_const(cNWScript, "IP_CONST_DAMAGESOAK_20_HP", INT2NUM(4));
    rb_define_const(cNWScript, "IP_CONST_DAMAGESOAK_25_HP", INT2NUM(5));
    rb_define_const(cNWScript, "IP_CONST_DAMAGESOAK_30_HP", INT2NUM(6));
    rb_define_const(cNWScript, "IP_CONST_DAMAGESOAK_35_HP", INT2NUM(7));
    rb_define_const(cNWScript, "IP_CONST_DAMAGESOAK_40_HP", INT2NUM(8));
    rb_define_const(cNWScript, "IP_CONST_DAMAGESOAK_45_HP", INT2NUM(9));
    rb_define_const(cNWScript, "IP_CONST_DAMAGESOAK_50_HP", INT2NUM(10));
    rb_define_const(cNWScript, "IP_CONST_DAMAGEREDUCTION_1", INT2NUM(0));
    rb_define_const(cNWScript, "IP_CONST_DAMAGEREDUCTION_2", INT2NUM(1));
    rb_define_const(cNWScript, "IP_CONST_DAMAGEREDUCTION_3", INT2NUM(2));
    rb_define_const(cNWScript, "IP_CONST_DAMAGEREDUCTION_4", INT2NUM(3));
    rb_define_const(cNWScript, "IP_CONST_DAMAGEREDUCTION_5", INT2NUM(4));
    rb_define_const(cNWScript, "IP_CONST_DAMAGEREDUCTION_6", INT2NUM(5));
    rb_define_const(cNWScript, "IP_CONST_DAMAGEREDUCTION_7", INT2NUM(6));
    rb_define_const(cNWScript, "IP_CONST_DAMAGEREDUCTION_8", INT2NUM(7));
    rb_define_const(cNWScript, "IP_CONST_DAMAGEREDUCTION_9", INT2NUM(8));
    rb_define_const(cNWScript, "IP_CONST_DAMAGEREDUCTION_10", INT2NUM(9));
    rb_define_const(cNWScript, "IP_CONST_DAMAGEREDUCTION_11", INT2NUM(10));
    rb_define_const(cNWScript, "IP_CONST_DAMAGEREDUCTION_12", INT2NUM(11));
    rb_define_const(cNWScript, "IP_CONST_DAMAGEREDUCTION_13", INT2NUM(12));
    rb_define_const(cNWScript, "IP_CONST_DAMAGEREDUCTION_14", INT2NUM(13));
    rb_define_const(cNWScript, "IP_CONST_DAMAGEREDUCTION_15", INT2NUM(14));
    rb_define_const(cNWScript, "IP_CONST_DAMAGEREDUCTION_16", INT2NUM(15));
    rb_define_const(cNWScript, "IP_CONST_DAMAGEREDUCTION_17", INT2NUM(16));
    rb_define_const(cNWScript, "IP_CONST_DAMAGEREDUCTION_18", INT2NUM(17));
    rb_define_const(cNWScript, "IP_CONST_DAMAGEREDUCTION_19", INT2NUM(18));
    rb_define_const(cNWScript, "IP_CONST_DAMAGEREDUCTION_20", INT2NUM(19));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_ACID_FOG", INT2NUM(0));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_AID", INT2NUM(1));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_BARKSKIN", INT2NUM(2));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_BESTOW_CURSE", INT2NUM(3));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_BLINDNESS_AND_DEAFNESS", INT2NUM(6));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_BURNING_HANDS", INT2NUM(8));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_CALL_LIGHTNING", INT2NUM(9));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_CHAIN_LIGHTNING", INT2NUM(12));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_CHARM_MONSTER", INT2NUM(13));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_CHARM_PERSON", INT2NUM(14));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_CHARM_PERSON_OR_ANIMAL", INT2NUM(15));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_CIRCLE_OF_DEATH", INT2NUM(16));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_CIRCLE_OF_DOOM", INT2NUM(17));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_CLOUDKILL", INT2NUM(21));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_COLOR_SPRAY", INT2NUM(22));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_CONE_OF_COLD", INT2NUM(23));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_CONFUSION", INT2NUM(24));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_CONTAGION", INT2NUM(25));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_CONTROL_UNDEAD", INT2NUM(26));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_CURE_CRITICAL_WOUNDS", INT2NUM(27));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_CURE_LIGHT_WOUNDS", INT2NUM(28));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_CURE_MINOR_WOUNDS", INT2NUM(29));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_CURE_MODERATE_WOUNDS", INT2NUM(30));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_CURE_SERIOUS_WOUNDS", INT2NUM(31));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_DARKNESS", INT2NUM(32));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_DAZE", INT2NUM(33));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_DEATH_WARD", INT2NUM(34));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_DELAYED_BLAST_FIREBALL", INT2NUM(35));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_DISMISSAL", INT2NUM(36));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_DISPEL_MAGIC", INT2NUM(37));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_DOMINATE_ANIMAL", INT2NUM(39));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_DOMINATE_MONSTER", INT2NUM(40));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_DOMINATE_PERSON", INT2NUM(41));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_DOOM", INT2NUM(42));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_ENERGY_DRAIN", INT2NUM(46));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_ENERVATION", INT2NUM(47));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_ENTANGLE", INT2NUM(48));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_FEAR", INT2NUM(49));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_FEEBLEMIND", INT2NUM(50));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_FINGER_OF_DEATH", INT2NUM(51));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_FIRE_STORM", INT2NUM(52));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_FIREBALL", INT2NUM(53));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_FLAME_ARROW", INT2NUM(54));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_FLAME_LASH", INT2NUM(55));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_FLAME_STRIKE", INT2NUM(56));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_FREEDOM_OF_MOVEMENT", INT2NUM(57));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_GREASE", INT2NUM(59));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_GREATER_DISPELLING", INT2NUM(60));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_GREATER_PLANAR_BINDING", INT2NUM(62));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_GREATER_SHADOW_CONJURATION", INT2NUM(64));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_GREATER_SPELL_BREACH", INT2NUM(65));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_HAMMER_OF_THE_GODS", INT2NUM(68));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_HARM", INT2NUM(69));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_HEAL", INT2NUM(71));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_HEALING_CIRCLE", INT2NUM(72));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_HOLD_ANIMAL", INT2NUM(73));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_HOLD_MONSTER", INT2NUM(74));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_HOLD_PERSON", INT2NUM(75));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_IMPLOSION", INT2NUM(78));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_IMPROVED_INVISIBILITY", INT2NUM(79));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_INCENDIARY_CLOUD", INT2NUM(80));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_INVISIBILITY_PURGE", INT2NUM(82));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_LESSER_DISPEL", INT2NUM(84));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_LESSER_PLANAR_BINDING", INT2NUM(86));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_LESSER_SPELL_BREACH", INT2NUM(88));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_LIGHTNING_BOLT", INT2NUM(91));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_MAGIC_MISSILE", INT2NUM(97));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_MASS_BLINDNESS_AND_DEAFNESS", INT2NUM(100));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_MASS_CHARM", INT2NUM(101));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_MASS_HEAL", INT2NUM(104));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_MELFS_ACID_ARROW", INT2NUM(105));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_METEOR_SWARM", INT2NUM(106));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_MIND_FOG", INT2NUM(108));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_MORDENKAINENS_DISJUNCTION", INT2NUM(112));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_PHANTASMAL_KILLER", INT2NUM(116));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_PLANAR_BINDING", INT2NUM(117));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_POISON", INT2NUM(118));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_POWER_WORD_KILL", INT2NUM(120));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_POWER_WORD_STUN", INT2NUM(121));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_PRISMATIC_SPRAY", INT2NUM(124));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_RAY_OF_ENFEEBLEMENT", INT2NUM(131));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_RAY_OF_FROST", INT2NUM(132));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_SCARE", INT2NUM(142));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_SEARING_LIGHT", INT2NUM(143));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_SHADES", INT2NUM(145));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_SHADOW_CONJURATION", INT2NUM(146));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_SILENCE", INT2NUM(150));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_SLAY_LIVING", INT2NUM(151));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_SLEEP", INT2NUM(152));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_SLOW", INT2NUM(153));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_SOUND_BURST", INT2NUM(154));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_STINKING_CLOUD", INT2NUM(158));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_STONESKIN", INT2NUM(159));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_STORM_OF_VENGEANCE", INT2NUM(160));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_SUNBEAM", INT2NUM(161));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_VIRTUE", INT2NUM(165));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_WAIL_OF_THE_BANSHEE", INT2NUM(166));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_WEB", INT2NUM(167));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_WEIRD", INT2NUM(168));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_WORD_OF_FAITH", INT2NUM(169));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_MAGIC_CIRCLE_AGAINST_ALIGNMENT", INT2NUM(171));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_EAGLE_SPLEDOR", INT2NUM(173));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_OWLS_WISDOM", INT2NUM(174));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_FOXS_CUNNING", INT2NUM(175));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_GREATER_EAGLES_SPLENDOR", INT2NUM(176));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_GREATER_OWLS_WISDOM", INT2NUM(177));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_GREATER_FOXS_CUNNING", INT2NUM(178));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_GREATER_BULLS_STRENGTH", INT2NUM(179));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_GREATER_CATS_GRACE", INT2NUM(180));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_GREATER_ENDURANCE", INT2NUM(181));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_AURA_OF_VITALITY", INT2NUM(182));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_WAR_CRY", INT2NUM(183));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_REGENERATE", INT2NUM(184));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_EVARDS_BLACK_TENTACLES", INT2NUM(185));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_LEGEND_LORE", INT2NUM(186));
    rb_define_const(cNWScript, "IP_CONST_IMMUNITYSPELL_FIND_TRAPS", INT2NUM(187));
    rb_define_const(cNWScript, "IP_CONST_SPELLLEVEL_0", INT2NUM(0));
    rb_define_const(cNWScript, "IP_CONST_SPELLLEVEL_1", INT2NUM(1));
    rb_define_const(cNWScript, "IP_CONST_SPELLLEVEL_2", INT2NUM(2));
    rb_define_const(cNWScript, "IP_CONST_SPELLLEVEL_3", INT2NUM(3));
    rb_define_const(cNWScript, "IP_CONST_SPELLLEVEL_4", INT2NUM(4));
    rb_define_const(cNWScript, "IP_CONST_SPELLLEVEL_5", INT2NUM(5));
    rb_define_const(cNWScript, "IP_CONST_SPELLLEVEL_6", INT2NUM(6));
    rb_define_const(cNWScript, "IP_CONST_SPELLLEVEL_7", INT2NUM(7));
    rb_define_const(cNWScript, "IP_CONST_SPELLLEVEL_8", INT2NUM(8));
    rb_define_const(cNWScript, "IP_CONST_SPELLLEVEL_9", INT2NUM(9));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_ACID_FOG_11", INT2NUM(0));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_ACID_SPLASH_1", INT2NUM(355));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_ACTIVATE_ITEM", INT2NUM(359));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_AID_3", INT2NUM(1));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_AMPLIFY_5", INT2NUM(373));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_ANIMATE_DEAD_10", INT2NUM(3));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_ANIMATE_DEAD_15", INT2NUM(4));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_ANIMATE_DEAD_5", INT2NUM(2));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_AURA_OF_VITALITY_13", INT2NUM(321));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_AURA_VERSUS_ALIGNMENT_15", INT2NUM(287));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_AURAOFGLORY_7", INT2NUM(360));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_AWAKEN_9", INT2NUM(303));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_BALAGARNSIRONHORN_7", INT2NUM(367));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_BANE_5", INT2NUM(380));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_BANISHMENT_15", INT2NUM(361));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_BARKSKIN_12", INT2NUM(7));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_BARKSKIN_3", INT2NUM(5));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_BARKSKIN_6", INT2NUM(6));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_BESTOW_CURSE_5", INT2NUM(8));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_BIGBYS_CLENCHED_FIST_20", INT2NUM(393));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_BIGBYS_CRUSHING_HAND_20", INT2NUM(394));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_BIGBYS_FORCEFUL_HAND_15", INT2NUM(391));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_BIGBYS_GRASPING_HAND_17", INT2NUM(392));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_BIGBYS_INTERPOSING_HAND_15", INT2NUM(390));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_BLADE_BARRIER_11", INT2NUM(9));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_BLADE_BARRIER_15", INT2NUM(10));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_BLESS_2", INT2NUM(11));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_BLINDNESS_DEAFNESS_3", INT2NUM(14));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_BLOOD_FRENZY_7", INT2NUM(353));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_BOMBARDMENT_20", INT2NUM(354));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_BULLS_STRENGTH_10", INT2NUM(16));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_BULLS_STRENGTH_15", INT2NUM(17));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_BULLS_STRENGTH_3", INT2NUM(15));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_BURNING_HANDS_2", INT2NUM(18));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_BURNING_HANDS_5", INT2NUM(19));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_CALL_LIGHTNING_10", INT2NUM(21));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_CALL_LIGHTNING_5", INT2NUM(20));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_CAMOFLAGE_5", INT2NUM(352));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_CATS_GRACE_10", INT2NUM(26));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_CATS_GRACE_15", INT2NUM(27));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_CATS_GRACE_3", INT2NUM(25));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_CHAIN_LIGHTNING_11", INT2NUM(28));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_CHAIN_LIGHTNING_15", INT2NUM(29));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_CHAIN_LIGHTNING_20", INT2NUM(30));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_CHARM_MONSTER_10", INT2NUM(32));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_CHARM_MONSTER_5", INT2NUM(31));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_CHARM_PERSON_10", INT2NUM(34));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_CHARM_PERSON_2", INT2NUM(33));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_CHARM_PERSON_OR_ANIMAL_10", INT2NUM(36));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_CHARM_PERSON_OR_ANIMAL_3", INT2NUM(35));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_CIRCLE_OF_DEATH_11", INT2NUM(37));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_CIRCLE_OF_DEATH_15", INT2NUM(38));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_CIRCLE_OF_DEATH_20", INT2NUM(39));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_CIRCLE_OF_DOOM_15", INT2NUM(41));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_CIRCLE_OF_DOOM_20", INT2NUM(42));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_CIRCLE_OF_DOOM_9", INT2NUM(40));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_CLAIRAUDIENCE_CLAIRVOYANCE_10", INT2NUM(44));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_CLAIRAUDIENCE_CLAIRVOYANCE_15", INT2NUM(45));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_CLAIRAUDIENCE_CLAIRVOYANCE_5", INT2NUM(43));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_CLARITY_3", INT2NUM(46));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_CLOUDKILL_9", INT2NUM(48));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_COLOR_SPRAY_2", INT2NUM(49));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_CONE_OF_COLD_15", INT2NUM(51));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_CONE_OF_COLD_9", INT2NUM(50));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_CONFUSION_10", INT2NUM(53));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_CONFUSION_5", INT2NUM(52));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_CONTAGION_5", INT2NUM(54));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_CONTINUAL_FLAME_7", INT2NUM(350));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_CONTROL_UNDEAD_13", INT2NUM(55));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_CONTROL_UNDEAD_20", INT2NUM(56));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_CREATE_GREATER_UNDEAD_15", INT2NUM(57));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_CREATE_GREATER_UNDEAD_16", INT2NUM(58));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_CREATE_GREATER_UNDEAD_18", INT2NUM(59));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_CREATE_UNDEAD_11", INT2NUM(60));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_CREATE_UNDEAD_14", INT2NUM(61));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_CREATE_UNDEAD_16", INT2NUM(62));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_CREEPING_DOOM_13", INT2NUM(304));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_CURE_CRITICAL_WOUNDS_12", INT2NUM(64));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_CURE_CRITICAL_WOUNDS_15", INT2NUM(65));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_CURE_CRITICAL_WOUNDS_7", INT2NUM(63));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_CURE_LIGHT_WOUNDS_2", INT2NUM(66));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_CURE_LIGHT_WOUNDS_5", INT2NUM(67));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_CURE_MINOR_WOUNDS_1", INT2NUM(68));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_CURE_MODERATE_WOUNDS_10", INT2NUM(71));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_CURE_MODERATE_WOUNDS_3", INT2NUM(69));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_CURE_MODERATE_WOUNDS_6", INT2NUM(70));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_CURE_SERIOUS_WOUNDS_10", INT2NUM(73));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_CURE_SERIOUS_WOUNDS_5", INT2NUM(72));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_DARKNESS_3", INT2NUM(75));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_DARKVISION_3", INT2NUM(305));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_DARKVISION_6", INT2NUM(306));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_DAZE_1", INT2NUM(76));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_DEATH_WARD_7", INT2NUM(77));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_DELAYED_BLAST_FIREBALL_13", INT2NUM(78));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_DELAYED_BLAST_FIREBALL_15", INT2NUM(79));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_DELAYED_BLAST_FIREBALL_20", INT2NUM(80));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_DESTRUCTION_13", INT2NUM(307));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_DIRGE_15", INT2NUM(376));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_DISMISSAL_12", INT2NUM(82));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_DISMISSAL_18", INT2NUM(83));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_DISMISSAL_7", INT2NUM(81));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_DISPEL_MAGIC_10", INT2NUM(85));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_DISPEL_MAGIC_5", INT2NUM(84));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_DISPLACEMENT_9", INT2NUM(389));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_DIVINE_FAVOR_5", INT2NUM(345));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_DIVINE_MIGHT_5", INT2NUM(395));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_DIVINE_POWER_7", INT2NUM(86));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_DIVINE_SHIELD_5", INT2NUM(396));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_DOMINATE_ANIMAL_5", INT2NUM(87));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_DOMINATE_MONSTER_17", INT2NUM(88));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_DOMINATE_PERSON_7", INT2NUM(89));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_DOOM_2", INT2NUM(90));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_DOOM_5", INT2NUM(91));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_DRAGON_BREATH_ACID_10", INT2NUM(400));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_DRAGON_BREATH_COLD_10", INT2NUM(401));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_DRAGON_BREATH_FEAR_10", INT2NUM(402));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_DRAGON_BREATH_FIRE_10", INT2NUM(403));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_DRAGON_BREATH_GAS_10", INT2NUM(404));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_DRAGON_BREATH_LIGHTNING_10", INT2NUM(405));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_DRAGON_BREATH_PARALYZE_10", INT2NUM(406));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_DRAGON_BREATH_SLEEP_10", INT2NUM(407));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_DRAGON_BREATH_SLOW_10", INT2NUM(408));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_DRAGON_BREATH_WEAKEN_10", INT2NUM(409));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_DROWN_15", INT2NUM(368));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_EAGLE_SPLEDOR_10", INT2NUM(289));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_EAGLE_SPLEDOR_15", INT2NUM(290));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_EAGLE_SPLEDOR_3", INT2NUM(288));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_EARTHQUAKE_20", INT2NUM(357));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_ELECTRIC_JOLT_1", INT2NUM(370));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_ELEMENTAL_SHIELD_12", INT2NUM(93));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_ELEMENTAL_SHIELD_7", INT2NUM(92));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_ELEMENTAL_SWARM_17", INT2NUM(94));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_ENDURANCE_10", INT2NUM(96));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_ENDURANCE_15", INT2NUM(97));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_ENDURANCE_3", INT2NUM(95));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_ENDURE_ELEMENTS_2", INT2NUM(98));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_ENERGY_BUFFER_11", INT2NUM(311));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_ENERGY_BUFFER_15", INT2NUM(312));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_ENERGY_BUFFER_20", INT2NUM(313));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_ENERGY_DRAIN_17", INT2NUM(99));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_ENERVATION_7", INT2NUM(100));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_ENTANGLE_2", INT2NUM(101));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_ENTANGLE_5", INT2NUM(102));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_ENTROPIC_SHIELD_5", INT2NUM(349));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_ETHEREAL_VISAGE_15", INT2NUM(196));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_ETHEREAL_VISAGE_9", INT2NUM(195));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_ETHEREALNESS_18", INT2NUM(374));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_EVARDS_BLACK_TENTACLES_15", INT2NUM(325));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_EVARDS_BLACK_TENTACLES_7", INT2NUM(324));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_EXPEDITIOUS_RETREAT_5", INT2NUM(387));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_FEAR_5", INT2NUM(103));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_FEEBLEMIND_9", INT2NUM(104));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_FIND_TRAPS_3", INT2NUM(327));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_FINGER_OF_DEATH_13", INT2NUM(105));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_FIRE_STORM_13", INT2NUM(106));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_FIRE_STORM_18", INT2NUM(107));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_FIREBALL_10", INT2NUM(109));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_FIREBALL_5", INT2NUM(108));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_FIREBRAND_15", INT2NUM(371));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_FLAME_ARROW_12", INT2NUM(111));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_FLAME_ARROW_18", INT2NUM(112));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_FLAME_ARROW_5", INT2NUM(110));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_FLAME_LASH_10", INT2NUM(114));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_FLAME_LASH_3", INT2NUM(113));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_FLAME_STRIKE_12", INT2NUM(116));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_FLAME_STRIKE_18", INT2NUM(117));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_FLAME_STRIKE_7", INT2NUM(115));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_FLARE_1", INT2NUM(347));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_FLESH_TO_STONE_5", INT2NUM(398));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_FOXS_CUNNING_10", INT2NUM(295));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_FOXS_CUNNING_15", INT2NUM(296));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_FOXS_CUNNING_3", INT2NUM(294));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_FREEDOM_OF_MOVEMENT_7", INT2NUM(118));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_GATE_17", INT2NUM(119));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_GHOSTLY_VISAGE_15", INT2NUM(194));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_GHOSTLY_VISAGE_3", INT2NUM(192));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_GHOSTLY_VISAGE_9", INT2NUM(193));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_GHOUL_TOUCH_3", INT2NUM(120));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_GLOBE_OF_INVULNERABILITY_11", INT2NUM(121));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_GREASE_2", INT2NUM(122));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_GREATER_BULLS_STRENGTH_11", INT2NUM(300));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_GREATER_CATS_GRACE_11", INT2NUM(301));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_GREATER_DISPELLING_15", INT2NUM(124));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_GREATER_DISPELLING_7", INT2NUM(123));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_GREATER_EAGLES_SPLENDOR_11", INT2NUM(297));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_GREATER_ENDURANCE_11", INT2NUM(302));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_GREATER_FOXS_CUNNING_11", INT2NUM(299));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_GREATER_MAGIC_FANG_9", INT2NUM(384));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_GREATER_OWLS_WISDOM_11", INT2NUM(298));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_GREATER_PLANAR_BINDING_15", INT2NUM(126));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_GREATER_RESTORATION_13", INT2NUM(127));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_GREATER_SHADOW_CONJURATION_9", INT2NUM(128));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_GREATER_SPELL_BREACH_11", INT2NUM(129));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_GREATER_SPELL_MANTLE_17", INT2NUM(130));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_GREATER_STONESKIN_11", INT2NUM(131));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_GRENADE_ACID_1", INT2NUM(341));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_GRENADE_CALTROPS_1", INT2NUM(343));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_GRENADE_CHICKEN_1", INT2NUM(342));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_GRENADE_CHOKING_1", INT2NUM(339));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_GRENADE_FIRE_1", INT2NUM(336));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_GRENADE_HOLY_1", INT2NUM(338));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_GRENADE_TANGLE_1", INT2NUM(337));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_GRENADE_THUNDERSTONE_1", INT2NUM(340));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_GUST_OF_WIND_10", INT2NUM(410));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_HAMMER_OF_THE_GODS_12", INT2NUM(134));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_HAMMER_OF_THE_GODS_7", INT2NUM(133));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_HARM_11", INT2NUM(136));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_HASTE_10", INT2NUM(138));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_HASTE_5", INT2NUM(137));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_HEAL_11", INT2NUM(139));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_HEALING_CIRCLE_16", INT2NUM(141));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_HEALING_CIRCLE_9", INT2NUM(140));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_HOLD_ANIMAL_3", INT2NUM(142));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_HOLD_MONSTER_7", INT2NUM(143));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_HOLD_PERSON_3", INT2NUM(144));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_HORRID_WILTING_15", INT2NUM(308));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_HORRID_WILTING_20", INT2NUM(309));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_ICE_STORM_9", INT2NUM(310));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_IDENTIFY_3", INT2NUM(147));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_IMPLOSION_17", INT2NUM(148));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_IMPROVED_INVISIBILITY_7", INT2NUM(149));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_INCENDIARY_CLOUD_15", INT2NUM(150));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_INFERNO_15", INT2NUM(377));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_INFLICT_CRITICAL_WOUNDS_12", INT2NUM(366));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_INFLICT_LIGHT_WOUNDS_5", INT2NUM(363));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_INFLICT_MINOR_WOUNDS_1", INT2NUM(362));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_INFLICT_MODERATE_WOUNDS_7", INT2NUM(364));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_INFLICT_SERIOUS_WOUNDS_9", INT2NUM(365));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_INVISIBILITY_3", INT2NUM(151));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_INVISIBILITY_PURGE_5", INT2NUM(152));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_INVISIBILITY_SPHERE_5", INT2NUM(153));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_ISAACS_GREATER_MISSILE_STORM_15", INT2NUM(379));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_ISAACS_LESSER_MISSILE_STORM_13", INT2NUM(378));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_KNOCK_3", INT2NUM(154));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_LEGEND_LORE_5", INT2NUM(326));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_LESSER_DISPEL_3", INT2NUM(155));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_LESSER_DISPEL_5", INT2NUM(156));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_LESSER_MIND_BLANK_9", INT2NUM(157));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_LESSER_PLANAR_BINDING_9", INT2NUM(158));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_LESSER_RESTORATION_3", INT2NUM(159));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_LESSER_SPELL_BREACH_7", INT2NUM(160));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_LESSER_SPELL_MANTLE_9", INT2NUM(161));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_LIGHT_1", INT2NUM(162));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_LIGHT_5", INT2NUM(163));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_LIGHTNING_BOLT_10", INT2NUM(165));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_LIGHTNING_BOLT_5", INT2NUM(164));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_MAGE_ARMOR_2", INT2NUM(167));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_MAGIC_CIRCLE_AGAINST_ALIGNMENT_5", INT2NUM(286));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_MAGIC_FANG_5", INT2NUM(383));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_MAGIC_MISSILE_3", INT2NUM(172));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_MAGIC_MISSILE_5", INT2NUM(173));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_MAGIC_MISSILE_9", INT2NUM(174));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_MANIPULATE_PORTAL_STONE", INT2NUM(344));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_MASS_BLINDNESS_DEAFNESS_15", INT2NUM(179));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_MASS_CAMOFLAGE_13", INT2NUM(386));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_MASS_CHARM_15", INT2NUM(180));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_MASS_HASTE_11", INT2NUM(182));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_MASS_HEAL_15", INT2NUM(183));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_MELFS_ACID_ARROW_3", INT2NUM(184));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_MELFS_ACID_ARROW_6", INT2NUM(185));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_MELFS_ACID_ARROW_9", INT2NUM(186));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_METEOR_SWARM_17", INT2NUM(187));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_MIND_BLANK_15", INT2NUM(188));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_MIND_FOG_9", INT2NUM(189));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_MINOR_GLOBE_OF_INVULNERABILITY_15", INT2NUM(191));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_MINOR_GLOBE_OF_INVULNERABILITY_7", INT2NUM(190));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_MORDENKAINENS_DISJUNCTION_17", INT2NUM(197));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_MORDENKAINENS_SWORD_13", INT2NUM(198));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_MORDENKAINENS_SWORD_18", INT2NUM(199));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_NATURES_BALANCE_15", INT2NUM(200));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_NEGATIVE_ENERGY_BURST_10", INT2NUM(315));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_NEGATIVE_ENERGY_BURST_5", INT2NUM(314));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_NEGATIVE_ENERGY_PROTECTION_10", INT2NUM(202));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_NEGATIVE_ENERGY_PROTECTION_15", INT2NUM(203));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_NEGATIVE_ENERGY_PROTECTION_5", INT2NUM(201));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_NEGATIVE_ENERGY_RAY_1", INT2NUM(316));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_NEGATIVE_ENERGY_RAY_3", INT2NUM(317));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_NEGATIVE_ENERGY_RAY_5", INT2NUM(318));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_NEGATIVE_ENERGY_RAY_7", INT2NUM(319));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_NEGATIVE_ENERGY_RAY_9", INT2NUM(320));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_NEUTRALIZE_POISON_5", INT2NUM(204));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_ONE_WITH_THE_LAND_7", INT2NUM(351));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_OWLS_INSIGHT_15", INT2NUM(369));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_OWLS_WISDOM_10", INT2NUM(292));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_OWLS_WISDOM_15", INT2NUM(293));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_OWLS_WISDOM_3", INT2NUM(291));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_PHANTASMAL_KILLER_7", INT2NUM(205));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_PLANAR_ALLY_15", INT2NUM(382));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_PLANAR_BINDING_11", INT2NUM(206));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_POISON_5", INT2NUM(207));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_POLYMORPH_SELF_7", INT2NUM(208));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_POWER_WORD_KILL_17", INT2NUM(209));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_POWER_WORD_STUN_13", INT2NUM(210));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_PRAYER_5", INT2NUM(211));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_PREMONITION_15", INT2NUM(212));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_PRISMATIC_SPRAY_13", INT2NUM(213));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_PROTECTION_FROM_ALIGNMENT_2", INT2NUM(284));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_PROTECTION_FROM_ALIGNMENT_5", INT2NUM(285));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_PROTECTION_FROM_ELEMENTS_10", INT2NUM(217));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_PROTECTION_FROM_ELEMENTS_3", INT2NUM(216));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_PROTECTION_FROM_SPELLS_13", INT2NUM(224));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_PROTECTION_FROM_SPELLS_20", INT2NUM(225));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_QUILLFIRE_8", INT2NUM(356));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_RAISE_DEAD_9", INT2NUM(226));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_RAY_OF_ENFEEBLEMENT_2", INT2NUM(227));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_RAY_OF_FROST_1", INT2NUM(228));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_REGENERATE_13", INT2NUM(323));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_REMOVE_BLINDNESS_DEAFNESS_5", INT2NUM(229));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_REMOVE_CURSE_5", INT2NUM(230));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_REMOVE_DISEASE_5", INT2NUM(231));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_REMOVE_FEAR_2", INT2NUM(232));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_REMOVE_PARALYSIS_3", INT2NUM(233));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_RESIST_ELEMENTS_10", INT2NUM(235));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_RESIST_ELEMENTS_3", INT2NUM(234));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_RESISTANCE_2", INT2NUM(236));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_RESISTANCE_5", INT2NUM(237));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_RESTORATION_7", INT2NUM(238));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_RESURRECTION_13", INT2NUM(239));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_ROGUES_CUNNING_3", INT2NUM(328));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_SANCTUARY_2", INT2NUM(240));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_SCARE_2", INT2NUM(241));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_SEARING_LIGHT_5", INT2NUM(242));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_SEE_INVISIBILITY_3", INT2NUM(243));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_SHADES_11", INT2NUM(244));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_SHADOW_CONJURATION_7", INT2NUM(245));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_SHADOW_SHIELD_13", INT2NUM(246));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_SHAPECHANGE_17", INT2NUM(247));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_SHIELD_5", INT2NUM(348));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_SHIELD_OF_FAITH_5", INT2NUM(381));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_SILENCE_3", INT2NUM(249));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_SLAY_LIVING_9", INT2NUM(250));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_SLEEP_2", INT2NUM(251));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_SLEEP_5", INT2NUM(252));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_SLOW_5", INT2NUM(253));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_SOUND_BURST_3", INT2NUM(254));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_SPECIAL_ALCOHOL_BEER", INT2NUM(330));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_SPECIAL_ALCOHOL_SPIRITS", INT2NUM(332));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_SPECIAL_ALCOHOL_WINE", INT2NUM(331));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_SPECIAL_HERB_BELLADONNA", INT2NUM(333));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_SPECIAL_HERB_GARLIC", INT2NUM(334));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_SPELL_MANTLE_13", INT2NUM(257));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_SPELL_RESISTANCE_15", INT2NUM(256));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_SPELL_RESISTANCE_9", INT2NUM(255));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_SPIKE_GROWTH_9", INT2NUM(385));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_STINKING_CLOUD_5", INT2NUM(259));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_STONE_TO_FLESH_5", INT2NUM(399));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_STONESKIN_7", INT2NUM(260));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_STORM_OF_VENGEANCE_17", INT2NUM(261));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_SUMMON_CREATURE_I_2", INT2NUM(262));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_SUMMON_CREATURE_I_5", INT2NUM(263));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_SUMMON_CREATURE_II_3", INT2NUM(264));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_SUMMON_CREATURE_III_5", INT2NUM(265));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_SUMMON_CREATURE_IV_7", INT2NUM(266));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_SUMMON_CREATURE_IX_17", INT2NUM(267));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_SUMMON_CREATURE_V_9", INT2NUM(268));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_SUMMON_CREATURE_VI_11", INT2NUM(269));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_SUMMON_CREATURE_VII_13", INT2NUM(270));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_SUMMON_CREATURE_VIII_15", INT2NUM(271));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_SUNBEAM_13", INT2NUM(272));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_SUNBURST_20", INT2NUM(358));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_TASHAS_HIDEOUS_LAUGHTER_7", INT2NUM(388));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_TENSERS_TRANSFORMATION_11", INT2NUM(273));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_TIME_STOP_17", INT2NUM(274));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_TRUE_SEEING_9", INT2NUM(275));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_TRUE_STRIKE_5", INT2NUM(346));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_UNDEATHS_ETERNAL_FOE_20", INT2NUM(375));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_UNIQUE_POWER", INT2NUM(329));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_UNIQUE_POWER_SELF_ONLY", INT2NUM(335));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_VAMPIRIC_TOUCH_5", INT2NUM(277));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_VIRTUE_1", INT2NUM(278));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_WAIL_OF_THE_BANSHEE_17", INT2NUM(279));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_WALL_OF_FIRE_9", INT2NUM(280));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_WAR_CRY_7", INT2NUM(322));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_WEB_3", INT2NUM(281));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_WEIRD_17", INT2NUM(282));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_WORD_OF_FAITH_13", INT2NUM(283));
    rb_define_const(cNWScript, "IP_CONST_CASTSPELL_WOUNDING_WHISPERS_9", INT2NUM(372));
    rb_define_const(cNWScript, "IP_CONST_SPELLSCHOOL_ABJURATION", INT2NUM(0));
    rb_define_const(cNWScript, "IP_CONST_SPELLSCHOOL_CONJURATION", INT2NUM(1));
    rb_define_const(cNWScript, "IP_CONST_SPELLSCHOOL_DIVINATION", INT2NUM(2));
    rb_define_const(cNWScript, "IP_CONST_SPELLSCHOOL_ENCHANTMENT", INT2NUM(3));
    rb_define_const(cNWScript, "IP_CONST_SPELLSCHOOL_EVOCATION", INT2NUM(4));
    rb_define_const(cNWScript, "IP_CONST_SPELLSCHOOL_ILLUSION", INT2NUM(5));
    rb_define_const(cNWScript, "IP_CONST_SPELLSCHOOL_NECROMANCY", INT2NUM(6));
    rb_define_const(cNWScript, "IP_CONST_SPELLSCHOOL_TRANSMUTATION", INT2NUM(7));
    rb_define_const(cNWScript, "IP_CONST_SPELLRESISTANCEBONUS_10", INT2NUM(0));
    rb_define_const(cNWScript, "IP_CONST_SPELLRESISTANCEBONUS_12", INT2NUM(1));
    rb_define_const(cNWScript, "IP_CONST_SPELLRESISTANCEBONUS_14", INT2NUM(2));
    rb_define_const(cNWScript, "IP_CONST_SPELLRESISTANCEBONUS_16", INT2NUM(3));
    rb_define_const(cNWScript, "IP_CONST_SPELLRESISTANCEBONUS_18", INT2NUM(4));
    rb_define_const(cNWScript, "IP_CONST_SPELLRESISTANCEBONUS_20", INT2NUM(5));
    rb_define_const(cNWScript, "IP_CONST_SPELLRESISTANCEBONUS_22", INT2NUM(6));
    rb_define_const(cNWScript, "IP_CONST_SPELLRESISTANCEBONUS_24", INT2NUM(7));
    rb_define_const(cNWScript, "IP_CONST_SPELLRESISTANCEBONUS_26", INT2NUM(8));
    rb_define_const(cNWScript, "IP_CONST_SPELLRESISTANCEBONUS_28", INT2NUM(9));
    rb_define_const(cNWScript, "IP_CONST_SPELLRESISTANCEBONUS_30", INT2NUM(10));
    rb_define_const(cNWScript, "IP_CONST_SPELLRESISTANCEBONUS_32", INT2NUM(11));
    rb_define_const(cNWScript, "IP_CONST_TRAPTYPE_SPIKE", INT2NUM(1));
    rb_define_const(cNWScript, "IP_CONST_TRAPTYPE_HOLY", INT2NUM(2));
    rb_define_const(cNWScript, "IP_CONST_TRAPTYPE_TANGLE", INT2NUM(3));
    rb_define_const(cNWScript, "IP_CONST_TRAPTYPE_BLOBOFACID", INT2NUM(4));
    rb_define_const(cNWScript, "IP_CONST_TRAPTYPE_FIRE", INT2NUM(5));
    rb_define_const(cNWScript, "IP_CONST_TRAPTYPE_ELECTRICAL", INT2NUM(6));
    rb_define_const(cNWScript, "IP_CONST_TRAPTYPE_GAS", INT2NUM(7));
    rb_define_const(cNWScript, "IP_CONST_TRAPTYPE_FROST", INT2NUM(8));
    rb_define_const(cNWScript, "IP_CONST_TRAPTYPE_ACID_SPLASH", INT2NUM(9));
    rb_define_const(cNWScript, "IP_CONST_TRAPTYPE_SONIC", INT2NUM(10));
    rb_define_const(cNWScript, "IP_CONST_TRAPTYPE_NEGATIVE", INT2NUM(11));
    rb_define_const(cNWScript, "IP_CONST_TRAPSTRENGTH_MINOR", INT2NUM(0));
    rb_define_const(cNWScript, "IP_CONST_TRAPSTRENGTH_AVERAGE", INT2NUM(1));
    rb_define_const(cNWScript, "IP_CONST_TRAPSTRENGTH_STRONG", INT2NUM(2));
    rb_define_const(cNWScript, "IP_CONST_TRAPSTRENGTH_DEADLY", INT2NUM(3));
    rb_define_const(cNWScript, "IP_CONST_REDUCEDWEIGHT_80_PERCENT", INT2NUM(1));
    rb_define_const(cNWScript, "IP_CONST_REDUCEDWEIGHT_60_PERCENT", INT2NUM(2));
    rb_define_const(cNWScript, "IP_CONST_REDUCEDWEIGHT_40_PERCENT", INT2NUM(3));
    rb_define_const(cNWScript, "IP_CONST_REDUCEDWEIGHT_20_PERCENT", INT2NUM(4));
    rb_define_const(cNWScript, "IP_CONST_REDUCEDWEIGHT_10_PERCENT", INT2NUM(5));
    rb_define_const(cNWScript, "IP_CONST_WEIGHTINCREASE_5_LBS", INT2NUM(0));
    rb_define_const(cNWScript, "IP_CONST_WEIGHTINCREASE_10_LBS", INT2NUM(1));
    rb_define_const(cNWScript, "IP_CONST_WEIGHTINCREASE_15_LBS", INT2NUM(2));
    rb_define_const(cNWScript, "IP_CONST_WEIGHTINCREASE_30_LBS", INT2NUM(3));
    rb_define_const(cNWScript, "IP_CONST_WEIGHTINCREASE_50_LBS", INT2NUM(4));
    rb_define_const(cNWScript, "IP_CONST_WEIGHTINCREASE_100_LBS", INT2NUM(5));
    rb_define_const(cNWScript, "IP_CONST_CLASS_BARBARIAN", INT2NUM(0));
    rb_define_const(cNWScript, "IP_CONST_CLASS_BARD", INT2NUM(1));
    rb_define_const(cNWScript, "IP_CONST_CLASS_CLERIC", INT2NUM(2));
    rb_define_const(cNWScript, "IP_CONST_CLASS_DRUID", INT2NUM(3));
    rb_define_const(cNWScript, "IP_CONST_CLASS_FIGHTER", INT2NUM(4));
    rb_define_const(cNWScript, "IP_CONST_CLASS_MONK", INT2NUM(5));
    rb_define_const(cNWScript, "IP_CONST_CLASS_PALADIN", INT2NUM(6));
    rb_define_const(cNWScript, "IP_CONST_CLASS_RANGER", INT2NUM(7));
    rb_define_const(cNWScript, "IP_CONST_CLASS_ROGUE", INT2NUM(8));
    rb_define_const(cNWScript, "IP_CONST_CLASS_SORCERER", INT2NUM(9));
    rb_define_const(cNWScript, "IP_CONST_CLASS_WIZARD", INT2NUM(10));
    rb_define_const(cNWScript, "IP_CONST_ARCANE_SPELL_FAILURE_MINUS_50_PERCENT", INT2NUM(0));
    rb_define_const(cNWScript, "IP_CONST_ARCANE_SPELL_FAILURE_MINUS_45_PERCENT", INT2NUM(1));
    rb_define_const(cNWScript, "IP_CONST_ARCANE_SPELL_FAILURE_MINUS_40_PERCENT", INT2NUM(2));
    rb_define_const(cNWScript, "IP_CONST_ARCANE_SPELL_FAILURE_MINUS_35_PERCENT", INT2NUM(3));
    rb_define_const(cNWScript, "IP_CONST_ARCANE_SPELL_FAILURE_MINUS_30_PERCENT", INT2NUM(4));
    rb_define_const(cNWScript, "IP_CONST_ARCANE_SPELL_FAILURE_MINUS_25_PERCENT", INT2NUM(5));
    rb_define_const(cNWScript, "IP_CONST_ARCANE_SPELL_FAILURE_MINUS_20_PERCENT", INT2NUM(6));
    rb_define_const(cNWScript, "IP_CONST_ARCANE_SPELL_FAILURE_MINUS_15_PERCENT", INT2NUM(7));
    rb_define_const(cNWScript, "IP_CONST_ARCANE_SPELL_FAILURE_MINUS_10_PERCENT", INT2NUM(8));
    rb_define_const(cNWScript, "IP_CONST_ARCANE_SPELL_FAILURE_MINUS_5_PERCENT", INT2NUM(9));
    rb_define_const(cNWScript, "IP_CONST_ARCANE_SPELL_FAILURE_PLUS_5_PERCENT", INT2NUM(10));
    rb_define_const(cNWScript, "IP_CONST_ARCANE_SPELL_FAILURE_PLUS_10_PERCENT", INT2NUM(11));
    rb_define_const(cNWScript, "IP_CONST_ARCANE_SPELL_FAILURE_PLUS_15_PERCENT", INT2NUM(12));
    rb_define_const(cNWScript, "IP_CONST_ARCANE_SPELL_FAILURE_PLUS_20_PERCENT", INT2NUM(13));
    rb_define_const(cNWScript, "IP_CONST_ARCANE_SPELL_FAILURE_PLUS_25_PERCENT", INT2NUM(14));
    rb_define_const(cNWScript, "IP_CONST_ARCANE_SPELL_FAILURE_PLUS_30_PERCENT", INT2NUM(15));
    rb_define_const(cNWScript, "IP_CONST_ARCANE_SPELL_FAILURE_PLUS_35_PERCENT", INT2NUM(16));
    rb_define_const(cNWScript, "IP_CONST_ARCANE_SPELL_FAILURE_PLUS_40_PERCENT", INT2NUM(17));
    rb_define_const(cNWScript, "IP_CONST_ARCANE_SPELL_FAILURE_PLUS_45_PERCENT", INT2NUM(18));
    rb_define_const(cNWScript, "IP_CONST_ARCANE_SPELL_FAILURE_PLUS_50_PERCENT", INT2NUM(19));
    rb_define_const(cNWScript, "ACTION_MODE_DETECT", INT2NUM(0));
    rb_define_const(cNWScript, "ACTION_MODE_STEALTH", INT2NUM(1));
    rb_define_const(cNWScript, "ACTION_MODE_PARRY", INT2NUM(2));
    rb_define_const(cNWScript, "ACTION_MODE_POWER_ATTACK", INT2NUM(3));
    rb_define_const(cNWScript, "ACTION_MODE_IMPROVED_POWER_ATTACK", INT2NUM(4));
    rb_define_const(cNWScript, "ACTION_MODE_COUNTERSPELL", INT2NUM(5));
    rb_define_const(cNWScript, "ACTION_MODE_FLURRY_OF_BLOWS", INT2NUM(6));
    rb_define_const(cNWScript, "ACTION_MODE_RAPID_SHOT", INT2NUM(7));
    rb_define_const(cNWScript, "ACTION_MODE_EXPERTISE", INT2NUM(8));
    rb_define_const(cNWScript, "ACTION_MODE_IMPROVED_EXPERTISE", INT2NUM(9));
    rb_define_const(cNWScript, "ACTION_MODE_DEFENSIVE_CAST", INT2NUM(10));
    rb_define_const(cNWScript, "ACTION_MODE_DIRTY_FIGHTING", INT2NUM(11));
    rb_define_const(cNWScript, "ITEM_VISUAL_ACID", INT2NUM(0));
    rb_define_const(cNWScript, "ITEM_VISUAL_COLD", INT2NUM(1));
    rb_define_const(cNWScript, "ITEM_VISUAL_ELECTRICAL", INT2NUM(2));
    rb_define_const(cNWScript, "ITEM_VISUAL_FIRE", INT2NUM(3));
    rb_define_const(cNWScript, "ITEM_VISUAL_SONIC", INT2NUM(4));
    rb_define_const(cNWScript, "ITEM_VISUAL_HOLY", INT2NUM(5));
    rb_define_const(cNWScript, "ITEM_VISUAL_EVIL", INT2NUM(6));
    rb_define_const(cNWScript, "SKYBOX_NONE", INT2NUM(0));
    rb_define_const(cNWScript, "SKYBOX_GRASS_CLEAR", INT2NUM(1));
    rb_define_const(cNWScript, "SKYBOX_GRASS_STORM", INT2NUM(2));
    rb_define_const(cNWScript, "SKYBOX_DESERT_CLEAR", INT2NUM(3));
    rb_define_const(cNWScript, "SKYBOX_WINTER_CLEAR", INT2NUM(4));
    rb_define_const(cNWScript, "SKYBOX_ICY", INT2NUM(5));
    rb_define_const(cNWScript, "FOG_TYPE_ALL", INT2NUM(0));
    rb_define_const(cNWScript, "FOG_TYPE_SUN", INT2NUM(1));
    rb_define_const(cNWScript, "FOG_TYPE_MOON", INT2NUM(2));
    rb_define_const(cNWScript, "FOG_COLOR_RED", INT2NUM(16711680));
    rb_define_const(cNWScript, "FOG_COLOR_RED_DARK", INT2NUM(6684672));
    rb_define_const(cNWScript, "FOG_COLOR_GREEN", INT2NUM(65280));
    rb_define_const(cNWScript, "FOG_COLOR_GREEN_DARK", INT2NUM(23112));
    rb_define_const(cNWScript, "FOG_COLOR_BLUE", INT2NUM(255));
    rb_define_const(cNWScript, "FOG_COLOR_BLUE_DARK", INT2NUM(102));
    rb_define_const(cNWScript, "FOG_COLOR_BLACK", INT2NUM(0));
    rb_define_const(cNWScript, "FOG_COLOR_WHITE", INT2NUM(16777215));
    rb_define_const(cNWScript, "FOG_COLOR_GREY", INT2NUM(10066329));
    rb_define_const(cNWScript, "FOG_COLOR_YELLOW", INT2NUM(16776960));
    rb_define_const(cNWScript, "FOG_COLOR_YELLOW_DARK", INT2NUM(11184640));
    rb_define_const(cNWScript, "FOG_COLOR_CYAN", INT2NUM(65535));
    rb_define_const(cNWScript, "FOG_COLOR_MAGENTA", INT2NUM(16711935));
    rb_define_const(cNWScript, "FOG_COLOR_ORANGE", INT2NUM(16750848));
    rb_define_const(cNWScript, "FOG_COLOR_ORANGE_DARK", INT2NUM(13395456));
    rb_define_const(cNWScript, "FOG_COLOR_BROWN", INT2NUM(10053120));
    rb_define_const(cNWScript, "FOG_COLOR_BROWN_DARK", INT2NUM(6697728));
    rb_define_const(cNWScript, "AMBIENT_SOUND_NONE", INT2NUM(0));
    rb_define_const(cNWScript, "AMBIENT_SOUND_MEN_WHISPER_INSIDE", INT2NUM(1));
    rb_define_const(cNWScript, "AMBIENT_SOUND_WOMEN_WHISPER_INSIDE", INT2NUM(2));
    rb_define_const(cNWScript, "AMBIENT_SOUND_PEOPLE_WHISPER_INSIDE", INT2NUM(3));
    rb_define_const(cNWScript, "AMBIENT_SOUND_SMALL_GROUP_TALKS_INSIDE", INT2NUM(4));
    rb_define_const(cNWScript, "AMBIENT_SOUND_MEDIUM_GROUP_TALKS_INSIDE", INT2NUM(5));
    rb_define_const(cNWScript, "AMBIENT_SOUND_LARGE_GROUP_TALKS_INSIDE", INT2NUM(6));
    rb_define_const(cNWScript, "AMBIENT_SOUND_COMMONER_TAVERN_TALK", INT2NUM(7));
    rb_define_const(cNWScript, "AMBIENT_SOUND_NOBLE_TAVERN_TALK", INT2NUM(8));
    rb_define_const(cNWScript, "AMBIENT_SOUND_CITY_SLUMS_DAY_CROWDED", INT2NUM(9));
    rb_define_const(cNWScript, "AMBIENT_SOUND_CITY_SLUMS_DAY_SPARSE", INT2NUM(10));
    rb_define_const(cNWScript, "AMBIENT_SOUND_CITY_SLUMS_NIGHT", INT2NUM(11));
    rb_define_const(cNWScript, "AMBIENT_SOUND_CITY_DAY_CROWDED", INT2NUM(12));
    rb_define_const(cNWScript, "AMBIENT_SOUND_CITY_DAY_SPARSE", INT2NUM(13));
    rb_define_const(cNWScript, "AMBIENT_SOUND_CITY_NIGHT", INT2NUM(14));
    rb_define_const(cNWScript, "AMBIENT_SOUND_CITY_MARKET", INT2NUM(15));
    rb_define_const(cNWScript, "AMBIENT_SOUND_CITY_TEMPLE_DISTRICT", INT2NUM(16));
    rb_define_const(cNWScript, "AMBIENT_SOUND_TOWN_DAY_CROWDED", INT2NUM(17));
    rb_define_const(cNWScript, "AMBIENT_SOUND_TOWN_DAY_SPARSE", INT2NUM(18));
    rb_define_const(cNWScript, "AMBIENT_SOUND_TOWN_NIGHT", INT2NUM(19));
    rb_define_const(cNWScript, "AMBIENT_SOUND_BORDELLO_WOMEN", INT2NUM(20));
    rb_define_const(cNWScript, "AMBIENT_SOUND_BORDELLO_MEN_AND_WOMEN", INT2NUM(21));
    rb_define_const(cNWScript, "AMBIENT_SOUND_RIOT_OUTSIDE", INT2NUM(22));
    rb_define_const(cNWScript, "AMBIENT_SOUND_RIOT_MUFFLED", INT2NUM(23));
    rb_define_const(cNWScript, "AMBIENT_SOUND_COMBAT_OUTSIDE_1", INT2NUM(24));
    rb_define_const(cNWScript, "AMBIENT_SOUND_COMBAT_OUTSIDE_2", INT2NUM(25));
    rb_define_const(cNWScript, "AMBIENT_SOUND_COMBAT_MUFFLED_1", INT2NUM(26));
    rb_define_const(cNWScript, "AMBIENT_SOUND_COMBAT_MUFFLED_2", INT2NUM(27));
    rb_define_const(cNWScript, "AMBIENT_SOUND_DUNGEON_LAKE_LAVA", INT2NUM(28));
    rb_define_const(cNWScript, "AMBIENT_SOUND_SEWER_SLUDGE_LAKE", INT2NUM(29));
    rb_define_const(cNWScript, "AMBIENT_SOUND_WIND_SOFT", INT2NUM(30));
    rb_define_const(cNWScript, "AMBIENT_SOUND_WIND_MEDIUM", INT2NUM(31));
    rb_define_const(cNWScript, "AMBIENT_SOUND_WIND_STRONG", INT2NUM(32));
    rb_define_const(cNWScript, "AMBIENT_SOUND_WIND_FOREST", INT2NUM(33));
    rb_define_const(cNWScript, "AMBIENT_SOUND_GUST_CHASM", INT2NUM(34));
    rb_define_const(cNWScript, "AMBIENT_SOUND_GUST_CAVERN", INT2NUM(35));
    rb_define_const(cNWScript, "AMBIENT_SOUND_GUST_GRASS", INT2NUM(36));
    rb_define_const(cNWScript, "AMBIENT_SOUND_GUST_DRAFT", INT2NUM(37));
    rb_define_const(cNWScript, "AMBIENT_SOUND_RAIN_LIGHT", INT2NUM(38));
    rb_define_const(cNWScript, "AMBIENT_SOUND_RAIN_HARD", INT2NUM(39));
    rb_define_const(cNWScript, "AMBIENT_SOUND_RAIN_STORM_SMALL", INT2NUM(40));
    rb_define_const(cNWScript, "AMBIENT_SOUND_RAIN_STORM_BIG", INT2NUM(41));
    rb_define_const(cNWScript, "AMBIENT_SOUND_CAVE_INSECTS_1", INT2NUM(42));
    rb_define_const(cNWScript, "AMBIENT_SOUND_CAVE_INSECTS_2", INT2NUM(43));
    rb_define_const(cNWScript, "AMBIENT_SOUND_INTERIOR_INSECTS_1", INT2NUM(44));
    rb_define_const(cNWScript, "AMBIENT_SOUND_INTERIOR_INSECTS_2", INT2NUM(45));
    rb_define_const(cNWScript, "AMBIENT_SOUND_LIZARD_FOLK_CAVE_CRYSTALS", INT2NUM(46));
    rb_define_const(cNWScript, "AMBIENT_SOUND_SEWERS_1", INT2NUM(47));
    rb_define_const(cNWScript, "AMBIENT_SOUND_SEWERS_2", INT2NUM(48));
    rb_define_const(cNWScript, "AMBIENT_SOUND_FOREST_DAY_1", INT2NUM(49));
    rb_define_const(cNWScript, "AMBIENT_SOUND_FOREST_DAY_2", INT2NUM(50));
    rb_define_const(cNWScript, "AMBIENT_SOUND_FOREST_DAY_3", INT2NUM(51));
    rb_define_const(cNWScript, "AMBIENT_SOUND_FOREST_DAY_SCARY", INT2NUM(52));
    rb_define_const(cNWScript, "AMBIENT_SOUND_FOREST_NIGHT_1", INT2NUM(53));
    rb_define_const(cNWScript, "AMBIENT_SOUND_FOREST_NIGHT_2", INT2NUM(54));
    rb_define_const(cNWScript, "AMBIENT_SOUND_FOREST_NIGHT_SCARY", INT2NUM(55));
    rb_define_const(cNWScript, "AMBIENT_SOUND_FOREST_MAGICAL", INT2NUM(56));
    rb_define_const(cNWScript, "AMBIENT_SOUND_EVIL_DUNGEON_SMALL", INT2NUM(57));
    rb_define_const(cNWScript, "AMBIENT_SOUND_EVIL_DUNGEON_MEDIUM", INT2NUM(58));
    rb_define_const(cNWScript, "AMBIENT_SOUND_EVIL_DUNGEON_LARGE", INT2NUM(59));
    rb_define_const(cNWScript, "AMBIENT_SOUND_CAVE_SMALL", INT2NUM(60));
    rb_define_const(cNWScript, "AMBIENT_SOUND_CAVE_MEDIUM", INT2NUM(61));
    rb_define_const(cNWScript, "AMBIENT_SOUND_CAVE_LARGE", INT2NUM(62));
    rb_define_const(cNWScript, "AMBIENT_SOUND_MINE_SMALL", INT2NUM(63));
    rb_define_const(cNWScript, "AMBIENT_SOUND_MINE_MEDIUM", INT2NUM(64));
    rb_define_const(cNWScript, "AMBIENT_SOUND_MINE_LARGE", INT2NUM(65));
    rb_define_const(cNWScript, "AMBIENT_SOUND_CASTLE_INTERIOR_SMALL", INT2NUM(66));
    rb_define_const(cNWScript, "AMBIENT_SOUND_CASTLE_INTERIOR_MEDIUM", INT2NUM(67));
    rb_define_const(cNWScript, "AMBIENT_SOUND_CASTLE_INTERIOR_LARGE", INT2NUM(68));
    rb_define_const(cNWScript, "AMBIENT_SOUND_CRYPT_SMALL", INT2NUM(69));
    rb_define_const(cNWScript, "AMBIENT_SOUND_CRYPT_MEDIUM_1", INT2NUM(70));
    rb_define_const(cNWScript, "AMBIENT_SOUND_CRYPT_MEDIUM_2", INT2NUM(71));
    rb_define_const(cNWScript, "AMBIENT_SOUND_HOUSE_INTERIOR_1", INT2NUM(72));
    rb_define_const(cNWScript, "AMBIENT_SOUND_HOUSE_INTERIOR_2", INT2NUM(73));
    rb_define_const(cNWScript, "AMBIENT_SOUND_HOUSE_INTERIOR_3", INT2NUM(74));
    rb_define_const(cNWScript, "AMBIENT_SOUND_KITCHEN_INTERIOR_SMALL", INT2NUM(75));
    rb_define_const(cNWScript, "AMBIENT_SOUND_KITCHEN_INTERIOR_LARGE", INT2NUM(76));
    rb_define_const(cNWScript, "AMBIENT_SOUND_HAUNTED_INTERIOR_1", INT2NUM(77));
    rb_define_const(cNWScript, "AMBIENT_SOUND_HAUNTED_INTERIOR_2", INT2NUM(78));
    rb_define_const(cNWScript, "AMBIENT_SOUND_HAUNTED_INTERIOR_3", INT2NUM(79));
    rb_define_const(cNWScript, "AMBIENT_SOUND_BLACK_SMITH", INT2NUM(80));
    rb_define_const(cNWScript, "AMBIENT_SOUND_PIT_CRIES", INT2NUM(81));
    rb_define_const(cNWScript, "AMBIENT_SOUND_MAGIC_INTERIOR_SMALL", INT2NUM(82));
    rb_define_const(cNWScript, "AMBIENT_SOUND_MAGIC_INTERIOR_MEDIUM", INT2NUM(83));
    rb_define_const(cNWScript, "AMBIENT_SOUND_MAGIC_INTERIOR_LARGE", INT2NUM(84));
    rb_define_const(cNWScript, "AMBIENT_SOUND_MAGIC_INTERIOR_EVIL", INT2NUM(85));
    rb_define_const(cNWScript, "AMBIENT_SOUND_MAGICAL_INTERIOR_FIRELAB", INT2NUM(86));
    rb_define_const(cNWScript, "AMBIENT_SOUND_MAGICAL_INTERIOR_EARTHLAB", INT2NUM(87));
    rb_define_const(cNWScript, "AMBIENT_SOUND_MAGICAL_INTERIOR_AIRLAB", INT2NUM(88));
    rb_define_const(cNWScript, "AMBIENT_SOUND_MAGICAL_INTERIOR_WATERLAB", INT2NUM(89));
    rb_define_const(cNWScript, "AMBIENT_SOUND_WINTER_DAY_WET_XP1", INT2NUM(90));
    rb_define_const(cNWScript, "AMBIENT_SOUND_WINTER_DAY_WINDY_XP1", INT2NUM(91));
    rb_define_const(cNWScript, "AMBIENT_SOUND_DESERT_DAY_XP1", INT2NUM(92));
    rb_define_const(cNWScript, "AMBIENT_SOUND_DESERT_NIGHT_XP1", INT2NUM(93));
    rb_define_const(cNWScript, "AMBIENT_SOUND_MONASTERY_INTERIOR_XP1", INT2NUM(94));
    rb_define_const(cNWScript, "AMBIENT_SOUND_RUIN_WET_XP1", INT2NUM(96));
    rb_define_const(cNWScript, "AMBIENT_SOUND_RUIN_RUMBLING_XP1", INT2NUM(97));
    rb_define_const(cNWScript, "AMBIENT_SOUND_RUIN_HAUNTED_XP1", INT2NUM(98));
    rb_define_const(cNWScript, "AMBIENT_SOUND_SAND_STORM_LIGHT_XP1", INT2NUM(99));
    rb_define_const(cNWScript, "AMBIENT_SOUND_SAND_STORM_EXTREME_XP1", INT2NUM(100));
    rb_define_const(cNWScript, "AMBIENT_SOUND_EVIL_DRONE_XP2", INT2NUM(101));
    rb_define_const(cNWScript, "AMBIENT_SOUND_PLAIN_OF_FIRE_XP2", INT2NUM(102));
    rb_define_const(cNWScript, "AMBIENT_SOUND_FROZEN_HELL_XP2", INT2NUM(103));
    rb_define_const(cNWScript, "AMBIENT_SOUND_CAVE_EVIL_1_XP2", INT2NUM(104));
    rb_define_const(cNWScript, "AMBIENT_SOUND_CAVE_EVIL_2_XP2", INT2NUM(105));
    rb_define_const(cNWScript, "AMBIENT_SOUND_CAVE_EVIL_3_XP2", INT2NUM(106));
    rb_define_const(cNWScript, "AMBIENT_SOUND_TAVERN_ROWDY", INT2NUM(107));
    rb_define_const(cNWScript, "FOOTSTEP_TYPE_INVALID", INT2NUM(-1));
    rb_define_const(cNWScript, "FOOTSTEP_TYPE_NORMAL", INT2NUM(0));
    rb_define_const(cNWScript, "FOOTSTEP_TYPE_LARGE", INT2NUM(1));
    rb_define_const(cNWScript, "FOOTSTEP_TYPE_DRAGON", INT2NUM(2));
    rb_define_const(cNWScript, "FOOTSTEP_TYPE_SOFT", INT2NUM(3));
    rb_define_const(cNWScript, "FOOTSTEP_TYPE_HOOF", INT2NUM(4));
    rb_define_const(cNWScript, "FOOTSTEP_TYPE_HOOF_LARGE", INT2NUM(5));
    rb_define_const(cNWScript, "FOOTSTEP_TYPE_BEETLE", INT2NUM(6));
    rb_define_const(cNWScript, "FOOTSTEP_TYPE_SPIDER", INT2NUM(7));
    rb_define_const(cNWScript, "FOOTSTEP_TYPE_SKELETON", INT2NUM(8));
    rb_define_const(cNWScript, "FOOTSTEP_TYPE_LEATHER_WING", INT2NUM(9));
    rb_define_const(cNWScript, "FOOTSTEP_TYPE_FEATHER_WING", INT2NUM(10));
    rb_define_const(cNWScript, "FOOTSTEP_TYPE_NONE", INT2NUM(12));
    rb_define_const(cNWScript, "FOOTSTEP_TYPE_SEAGULL", INT2NUM(13));
    rb_define_const(cNWScript, "FOOTSTEP_TYPE_SHARK", INT2NUM(14));
    rb_define_const(cNWScript, "FOOTSTEP_TYPE_WATER_NORMAL", INT2NUM(15));
    rb_define_const(cNWScript, "FOOTSTEP_TYPE_WATER_LARGE", INT2NUM(16));
    rb_define_const(cNWScript, "FOOTSTEP_TYPE_HORSE", INT2NUM(17));
    rb_define_const(cNWScript, "FOOTSTEP_TYPE_DEFAULT", INT2NUM(65535));
    rb_define_const(cNWScript, "CREATURE_WING_TYPE_NONE", INT2NUM(0));
    rb_define_const(cNWScript, "CREATURE_WING_TYPE_DEMON", INT2NUM(1));
    rb_define_const(cNWScript, "CREATURE_WING_TYPE_ANGEL", INT2NUM(2));
    rb_define_const(cNWScript, "CREATURE_WING_TYPE_BAT", INT2NUM(3));
    rb_define_const(cNWScript, "CREATURE_WING_TYPE_DRAGON", INT2NUM(4));
    rb_define_const(cNWScript, "CREATURE_WING_TYPE_BUTTERFLY", INT2NUM(5));
    rb_define_const(cNWScript, "CREATURE_WING_TYPE_BIRD", INT2NUM(6));
    rb_define_const(cNWScript, "CREATURE_TAIL_TYPE_NONE", INT2NUM(0));
    rb_define_const(cNWScript, "CREATURE_TAIL_TYPE_LIZARD", INT2NUM(1));
    rb_define_const(cNWScript, "CREATURE_TAIL_TYPE_BONE", INT2NUM(2));
    rb_define_const(cNWScript, "CREATURE_TAIL_TYPE_DEVIL", INT2NUM(3));
    rb_define_const(cNWScript, "CREATURE_PART_RIGHT_FOOT", INT2NUM(0));
    rb_define_const(cNWScript, "CREATURE_PART_LEFT_FOOT", INT2NUM(1));
    rb_define_const(cNWScript, "CREATURE_PART_RIGHT_SHIN", INT2NUM(2));
    rb_define_const(cNWScript, "CREATURE_PART_LEFT_SHIN", INT2NUM(3));
    rb_define_const(cNWScript, "CREATURE_PART_LEFT_THIGH", INT2NUM(4));
    rb_define_const(cNWScript, "CREATURE_PART_RIGHT_THIGH", INT2NUM(5));
    rb_define_const(cNWScript, "CREATURE_PART_PELVIS", INT2NUM(6));
    rb_define_const(cNWScript, "CREATURE_PART_TORSO", INT2NUM(7));
    rb_define_const(cNWScript, "CREATURE_PART_BELT", INT2NUM(8));
    rb_define_const(cNWScript, "CREATURE_PART_NECK", INT2NUM(9));
    rb_define_const(cNWScript, "CREATURE_PART_RIGHT_FOREARM", INT2NUM(10));
    rb_define_const(cNWScript, "CREATURE_PART_LEFT_FOREARM", INT2NUM(11));
    rb_define_const(cNWScript, "CREATURE_PART_RIGHT_BICEP", INT2NUM(12));
    rb_define_const(cNWScript, "CREATURE_PART_LEFT_BICEP", INT2NUM(13));
    rb_define_const(cNWScript, "CREATURE_PART_RIGHT_SHOULDER", INT2NUM(14));
    rb_define_const(cNWScript, "CREATURE_PART_LEFT_SHOULDER", INT2NUM(15));
    rb_define_const(cNWScript, "CREATURE_PART_RIGHT_HAND", INT2NUM(16));
    rb_define_const(cNWScript, "CREATURE_PART_LEFT_HAND", INT2NUM(17));
    rb_define_const(cNWScript, "CREATURE_PART_HEAD", INT2NUM(20));
    rb_define_const(cNWScript, "CREATURE_MODEL_TYPE_NONE", INT2NUM(0));
    rb_define_const(cNWScript, "CREATURE_MODEL_TYPE_SKIN", INT2NUM(1));
    rb_define_const(cNWScript, "CREATURE_MODEL_TYPE_TATTOO", INT2NUM(2));
    rb_define_const(cNWScript, "CREATURE_MODEL_TYPE_UNDEAD", INT2NUM(255));
    rb_define_const(cNWScript, "COLOR_CHANNEL_SKIN", INT2NUM(0));
    rb_define_const(cNWScript, "COLOR_CHANNEL_HAIR", INT2NUM(1));
    rb_define_const(cNWScript, "COLOR_CHANNEL_TATTOO_1", INT2NUM(2));
    rb_define_const(cNWScript, "COLOR_CHANNEL_TATTOO_2", INT2NUM(3));
    rb_define_const(cNWScript, "TILESET_RESREF_BEHOLDER_CAVES", rb_str_new2("tib01"));
    rb_define_const(cNWScript, "TILESET_RESREF_CASTLE_INTERIOR", rb_str_new2("tic01"));
    rb_define_const(cNWScript, "TILESET_RESREF_CITY_EXTERIOR", rb_str_new2("tcn01"));
    rb_define_const(cNWScript, "TILESET_RESREF_CITY_INTERIOR", rb_str_new2("tin01"));
    rb_define_const(cNWScript, "TILESET_RESREF_CRYPT", rb_str_new2("tdc01"));
    rb_define_const(cNWScript, "TILESET_RESREF_DESERT", rb_str_new2("ttd01"));
    rb_define_const(cNWScript, "TILESET_RESREF_DROW_INTERIOR", rb_str_new2("tid01"));
    rb_define_const(cNWScript, "TILESET_RESREF_DUNGEON", rb_str_new2("tde01"));
    rb_define_const(cNWScript, "TILESET_RESREF_FOREST", rb_str_new2("ttf01"));
    rb_define_const(cNWScript, "TILESET_RESREF_FROZEN_WASTES", rb_str_new2("tti01"));
    rb_define_const(cNWScript, "TILESET_RESREF_ILLITHID_INTERIOR", rb_str_new2("tii01"));
    rb_define_const(cNWScript, "TILESET_RESREF_MICROSET", rb_str_new2("tms01"));
    rb_define_const(cNWScript, "TILESET_RESREF_MINES_AND_CAVERNS", rb_str_new2("tdm01"));
    rb_define_const(cNWScript, "TILESET_RESREF_RUINS", rb_str_new2("tdr01"));
    rb_define_const(cNWScript, "TILESET_RESREF_RURAL", rb_str_new2("ttr01"));
    rb_define_const(cNWScript, "TILESET_RESREF_RURAL_WINTER", rb_str_new2("tts01"));
    rb_define_const(cNWScript, "TILESET_RESREF_SEWERS", rb_str_new2("tds01"));
    rb_define_const(cNWScript, "TILESET_RESREF_UNDERDARK", rb_str_new2("ttu01"));
    rb_define_const(cNWScript, "NAME_FIRST_GENERIC_MALE", INT2NUM(-1));
    rb_define_const(cNWScript, "NAME_ANIMAL", INT2NUM(0));
    rb_define_const(cNWScript, "NAME_FAMILIAR", INT2NUM(1));
    rb_define_const(cNWScript, "NAME_FIRST_DWARF_MALE", INT2NUM(2));
    rb_define_const(cNWScript, "NAME_FIRST_DWARF_FEMALE", INT2NUM(3));
    rb_define_const(cNWScript, "NAME_LAST_DWARF", INT2NUM(4));
    rb_define_const(cNWScript, "NAME_FIRST_ELF_MALE", INT2NUM(5));
    rb_define_const(cNWScript, "NAME_FIRST_ELF_FEMALE", INT2NUM(6));
    rb_define_const(cNWScript, "NAME_LAST_ELF", INT2NUM(7));
    rb_define_const(cNWScript, "NAME_FIRST_GNOME_MALE", INT2NUM(8));
    rb_define_const(cNWScript, "NAME_FIRST_GNOME_FEMALE", INT2NUM(9));
    rb_define_const(cNWScript, "NAME_LAST_GNOME", INT2NUM(10));
    rb_define_const(cNWScript, "NAME_FIRST_HALFELF_MALE", INT2NUM(11));
    rb_define_const(cNWScript, "NAME_FIRST_HALFELF_FEMALE", INT2NUM(12));
    rb_define_const(cNWScript, "NAME_LAST_HALFELF", INT2NUM(13));
    rb_define_const(cNWScript, "NAME_FIRST_HALFLING_MALE", INT2NUM(14));
    rb_define_const(cNWScript, "NAME_FIRST_HALFLING_FEMALE", INT2NUM(15));
    rb_define_const(cNWScript, "NAME_LAST_HALFLING", INT2NUM(16));
    rb_define_const(cNWScript, "NAME_FIRST_HALFORC_MALE", INT2NUM(17));
    rb_define_const(cNWScript, "NAME_FIRST_HALFORC_FEMALE", INT2NUM(18));
    rb_define_const(cNWScript, "NAME_LAST_HALFORC", INT2NUM(19));
    rb_define_const(cNWScript, "NAME_FIRST_HUMAN_MALE", INT2NUM(20));
    rb_define_const(cNWScript, "NAME_FIRST_HUMAN_FEMALE", INT2NUM(21));
    rb_define_const(cNWScript, "NAME_LAST_HUMAN", INT2NUM(22));

    rb_define_const(cNWScript, "OBJECT_INVALID", INT2NUM(OBJECT_INVALID));

}

