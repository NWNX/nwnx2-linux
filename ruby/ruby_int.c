#include "FunctionHooks.h"
#include "ruby_int.h"
#include "ruby/ruby.h"

static VALUE NWScript_Random(VALUE self, VALUE nMaxInteger)
{
	StackPushInteger(NUM2INT(nMaxInteger));
	VM_ExecuteCommand(0);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_PrintString(VALUE self, VALUE sString)
{
	StackPushString(rb_str2cstr(sString, NULL));
	VM_ExecuteCommand(1);
	return Qnil;
}

static VALUE NWScript_PrintFloat(VALUE self, VALUE fFloat, VALUE nWidth, VALUE nDecimals)
{
	StackPushInteger(NUM2INT(nDecimals));
	StackPushInteger(NUM2INT(nWidth));
	StackPushFloat(NUM2DBL(fFloat));
	VM_ExecuteCommand(2);
	return Qnil;
}

static VALUE NWScript_FloatToString(VALUE self, VALUE fFloat, VALUE nWidth, VALUE nDecimals)
{
	StackPushInteger(NUM2INT(nDecimals));
	StackPushInteger(NUM2INT(nWidth));
	StackPushFloat(NUM2DBL(fFloat));
	VM_ExecuteCommand(3);
	char *sRetVal;
	StackPopString(sRetVal);
	return rb_str_new2(sRetVal);
}

static VALUE NWScript_PrintInteger(VALUE self, VALUE nInteger)
{
	StackPushInteger(NUM2INT(nInteger));
	VM_ExecuteCommand(4);
	return Qnil;
}

static VALUE NWScript_PrintObject(VALUE self, VALUE oObject)
{
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(5);
	return Qnil;
}

static VALUE NWScript_AssignCommand(VALUE self, VALUE oActionSubject, VALUE aActionToAssign)
{
	//ERROR: Undefined variable type: action
	StackPushObject(NUM2UINT(oActionSubject));
	VM_ExecuteCommand(6);
	return Qnil;
}

static VALUE NWScript_DelayCommand(VALUE self, VALUE fSeconds, VALUE aActionToDelay)
{
	//ERROR: Undefined variable type: action
	StackPushFloat(NUM2DBL(fSeconds));
	VM_ExecuteCommand(7);
	return Qnil;
}

static VALUE NWScript_ExecuteScript(VALUE self, VALUE sScript, VALUE oTarget)
{
	StackPushObject(NUM2UINT(oTarget));
	StackPushString(rb_str2cstr(sScript, NULL));
	VM_ExecuteCommand(8);
	return Qnil;
}

static VALUE NWScript_ClearAllActions(VALUE self, VALUE nClearCombatState)
{
	StackPushInteger(NUM2INT(nClearCombatState));
	VM_ExecuteCommand(9);
	return Qnil;
}

static VALUE NWScript_SetFacing(VALUE self, VALUE fDirection)
{
	StackPushFloat(NUM2DBL(fDirection));
	VM_ExecuteCommand(10);
	return Qnil;
}

static VALUE NWScript_SetCalendar(VALUE self, VALUE nYear, VALUE nMonth, VALUE nDay)
{
	StackPushInteger(NUM2INT(nDay));
	StackPushInteger(NUM2INT(nMonth));
	StackPushInteger(NUM2INT(nYear));
	VM_ExecuteCommand(11);
	return Qnil;
}

static VALUE NWScript_SetTime(VALUE self, VALUE nHour, VALUE nMinute, VALUE nSecond, VALUE nMillisecond)
{
	StackPushInteger(NUM2INT(nMillisecond));
	StackPushInteger(NUM2INT(nSecond));
	StackPushInteger(NUM2INT(nMinute));
	StackPushInteger(NUM2INT(nHour));
	VM_ExecuteCommand(12);
	return Qnil;
}

static VALUE NWScript_GetCalendarYear()
{
	VM_ExecuteCommand(13);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetCalendarMonth()
{
	VM_ExecuteCommand(14);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetCalendarDay()
{
	VM_ExecuteCommand(15);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetTimeHour()
{
	VM_ExecuteCommand(16);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetTimeMinute()
{
	VM_ExecuteCommand(17);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetTimeSecond()
{
	VM_ExecuteCommand(18);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetTimeMillisecond()
{
	VM_ExecuteCommand(19);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_ActionRandomWalk()
{
	VM_ExecuteCommand(20);
	return Qnil;
}

static VALUE NWScript_ActionMoveToLocation(VALUE self, VALUE lDestination, VALUE bRun)
{
	StackPushInteger(NUM2INT(bRun));
	//ERROR: Undefined variable type: location
	VM_ExecuteCommand(21);
	return Qnil;
}

static VALUE NWScript_ActionMoveToObject(VALUE self, VALUE oMoveTo, VALUE bRun, VALUE fRange)
{
	StackPushFloat(NUM2DBL(fRange));
	StackPushInteger(NUM2INT(bRun));
	StackPushObject(NUM2UINT(oMoveTo));
	VM_ExecuteCommand(22);
	return Qnil;
}

static VALUE NWScript_ActionMoveAwayFromObject(VALUE self, VALUE oFleeFrom, VALUE bRun, VALUE fMoveAwayRange)
{
	StackPushFloat(NUM2DBL(fMoveAwayRange));
	StackPushInteger(NUM2INT(bRun));
	StackPushObject(NUM2UINT(oFleeFrom));
	VM_ExecuteCommand(23);
	return Qnil;
}

static VALUE NWScript_GetArea(VALUE self, VALUE oTarget)
{
	StackPushObject(NUM2UINT(oTarget));
	VM_ExecuteCommand(24);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetEnteringObject()
{
	VM_ExecuteCommand(25);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetExitingObject()
{
	VM_ExecuteCommand(26);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetPosition(VALUE self, VALUE oTarget)
{
	StackPushObject(NUM2UINT(oTarget));
	VM_ExecuteCommand(27);
//ERROR: Undefined variable type: vector
}

static VALUE NWScript_GetFacing(VALUE self, VALUE oTarget)
{
	StackPushObject(NUM2UINT(oTarget));
	VM_ExecuteCommand(28);
	float fRetVal;
	StackPopFloat(&fRetVal);
	return rb_float_new(fRetVal);
}

static VALUE NWScript_GetItemPossessor(VALUE self, VALUE oItem)
{
	StackPushObject(NUM2UINT(oItem));
	VM_ExecuteCommand(29);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetItemPossessedBy(VALUE self, VALUE oCreature, VALUE sItemTag)
{
	StackPushString(rb_str2cstr(sItemTag, NULL));
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(30);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_CreateItemOnObject(VALUE self, VALUE sItemTemplate, VALUE oTarget, VALUE nStackSize, VALUE sNewTag)
{
	StackPushString(rb_str2cstr(sNewTag, NULL));
	StackPushInteger(NUM2INT(nStackSize));
	StackPushObject(NUM2UINT(oTarget));
	StackPushString(rb_str2cstr(sItemTemplate, NULL));
	VM_ExecuteCommand(31);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_ActionEquipItem(VALUE self, VALUE oItem, VALUE nInventorySlot)
{
	StackPushInteger(NUM2INT(nInventorySlot));
	StackPushObject(NUM2UINT(oItem));
	VM_ExecuteCommand(32);
	return Qnil;
}

static VALUE NWScript_ActionUnequipItem(VALUE self, VALUE oItem)
{
	StackPushObject(NUM2UINT(oItem));
	VM_ExecuteCommand(33);
	return Qnil;
}

static VALUE NWScript_ActionPickUpItem(VALUE self, VALUE oItem)
{
	StackPushObject(NUM2UINT(oItem));
	VM_ExecuteCommand(34);
	return Qnil;
}

static VALUE NWScript_ActionPutDownItem(VALUE self, VALUE oItem)
{
	StackPushObject(NUM2UINT(oItem));
	VM_ExecuteCommand(35);
	return Qnil;
}

static VALUE NWScript_GetLastAttacker(VALUE self, VALUE oAttackee)
{
	StackPushObject(NUM2UINT(oAttackee));
	VM_ExecuteCommand(36);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_ActionAttack(VALUE self, VALUE oAttackee, VALUE bPassive)
{
	StackPushInteger(NUM2INT(bPassive));
	StackPushObject(NUM2UINT(oAttackee));
	VM_ExecuteCommand(37);
	return Qnil;
}

static VALUE NWScript_GetNearestCreature(VALUE self, VALUE nFirstCriteriaType, VALUE nFirstCriteriaValue, VALUE oTarget, VALUE nNth, VALUE nSecondCriteriaType, VALUE nSecondCriteriaValue, VALUE nThirdCriteriaType, VALUE nThirdCriteriaValue)
{
	StackPushInteger(NUM2INT(nThirdCriteriaValue));
	StackPushInteger(NUM2INT(nThirdCriteriaType));
	StackPushInteger(NUM2INT(nSecondCriteriaValue));
	StackPushInteger(NUM2INT(nSecondCriteriaType));
	StackPushInteger(NUM2INT(nNth));
	StackPushObject(NUM2UINT(oTarget));
	StackPushInteger(NUM2INT(nFirstCriteriaValue));
	StackPushInteger(NUM2INT(nFirstCriteriaType));
	VM_ExecuteCommand(38);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_ActionSpeakString(VALUE self, VALUE sStringToSpeak, VALUE nTalkVolume)
{
	StackPushInteger(NUM2INT(nTalkVolume));
	StackPushString(rb_str2cstr(sStringToSpeak, NULL));
	VM_ExecuteCommand(39);
	return Qnil;
}

static VALUE NWScript_ActionPlayAnimation(VALUE self, VALUE nAnimation, VALUE fSpeed, VALUE fDurationSeconds)
{
	StackPushFloat(NUM2DBL(fDurationSeconds));
	StackPushFloat(NUM2DBL(fSpeed));
	StackPushInteger(NUM2INT(nAnimation));
	VM_ExecuteCommand(40);
	return Qnil;
}

static VALUE NWScript_GetDistanceToObject(VALUE self, VALUE oObject)
{
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(41);
	float fRetVal;
	StackPopFloat(&fRetVal);
	return rb_float_new(fRetVal);
}

static VALUE NWScript_GetIsObjectValid(VALUE self, VALUE oObject)
{
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(42);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_ActionOpenDoor(VALUE self, VALUE oDoor)
{
	StackPushObject(NUM2UINT(oDoor));
	VM_ExecuteCommand(43);
	return Qnil;
}

static VALUE NWScript_ActionCloseDoor(VALUE self, VALUE oDoor)
{
	StackPushObject(NUM2UINT(oDoor));
	VM_ExecuteCommand(44);
	return Qnil;
}

static VALUE NWScript_SetCameraFacing(VALUE self, VALUE fDirection, VALUE fDistance , VALUE fPitch , VALUE nTransitionType)
{
	StackPushInteger(NUM2INT(nTransitionType));
	StackPushFloat(NUM2DBL(fPitch ));
	StackPushFloat(NUM2DBL(fDistance ));
	StackPushFloat(NUM2DBL(fDirection));
	VM_ExecuteCommand(45);
	return Qnil;
}

static VALUE NWScript_PlaySound(VALUE self, VALUE sSoundName)
{
	StackPushString(rb_str2cstr(sSoundName, NULL));
	VM_ExecuteCommand(46);
	return Qnil;
}

static VALUE NWScript_GetSpellTargetObject()
{
	VM_ExecuteCommand(47);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_ActionCastSpellAtObject(VALUE self, VALUE nSpell, VALUE oTarget, VALUE nMetaMagic, VALUE bCheat, VALUE nDomainLevel, VALUE nProjectilePathType, VALUE bInstantSpell)
{
	StackPushInteger(NUM2INT(bInstantSpell));
	StackPushInteger(NUM2INT(nProjectilePathType));
	StackPushInteger(NUM2INT(nDomainLevel));
	StackPushInteger(NUM2INT(bCheat));
	StackPushInteger(NUM2INT(nMetaMagic));
	StackPushObject(NUM2UINT(oTarget));
	StackPushInteger(NUM2INT(nSpell));
	VM_ExecuteCommand(48);
	return Qnil;
}

static VALUE NWScript_GetCurrentHitPoints(VALUE self, VALUE oObject)
{
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(49);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetMaxHitPoints(VALUE self, VALUE oObject)
{
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(50);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLocalInt(VALUE self, VALUE oObject, VALUE sVarName)
{
	StackPushString(rb_str2cstr(sVarName, NULL));
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(51);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLocalFloat(VALUE self, VALUE oObject, VALUE sVarName)
{
	StackPushString(rb_str2cstr(sVarName, NULL));
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(52);
	float fRetVal;
	StackPopFloat(&fRetVal);
	return rb_float_new(fRetVal);
}

static VALUE NWScript_GetLocalString(VALUE self, VALUE oObject, VALUE sVarName)
{
	StackPushString(rb_str2cstr(sVarName, NULL));
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(53);
	char *sRetVal;
	StackPopString(sRetVal);
	return rb_str_new2(sRetVal);
}

static VALUE NWScript_GetLocalObject(VALUE self, VALUE oObject, VALUE sVarName)
{
	StackPushString(rb_str2cstr(sVarName, NULL));
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(54);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_SetLocalInt(VALUE self, VALUE oObject, VALUE sVarName, VALUE nValue)
{
	StackPushInteger(NUM2INT(nValue));
	StackPushString(rb_str2cstr(sVarName, NULL));
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(55);
	return Qnil;
}

static VALUE NWScript_SetLocalFloat(VALUE self, VALUE oObject, VALUE sVarName, VALUE fValue)
{
	StackPushFloat(NUM2DBL(fValue));
	StackPushString(rb_str2cstr(sVarName, NULL));
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(56);
	return Qnil;
}

static VALUE NWScript_SetLocalString(VALUE self, VALUE oObject, VALUE sVarName, VALUE sValue)
{
	StackPushString(rb_str2cstr(sValue, NULL));
	StackPushString(rb_str2cstr(sVarName, NULL));
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(57);
	return Qnil;
}

static VALUE NWScript_SetLocalObject(VALUE self, VALUE oObject, VALUE sVarName, VALUE oValue)
{
	StackPushObject(NUM2UINT(oValue));
	StackPushString(rb_str2cstr(sVarName, NULL));
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(58);
	return Qnil;
}

static VALUE NWScript_GetStringLength(VALUE self, VALUE sString)
{
	StackPushString(rb_str2cstr(sString, NULL));
	VM_ExecuteCommand(59);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetStringUpperCase(VALUE self, VALUE sString)
{
	StackPushString(rb_str2cstr(sString, NULL));
	VM_ExecuteCommand(60);
	char *sRetVal;
	StackPopString(sRetVal);
	return rb_str_new2(sRetVal);
}

static VALUE NWScript_GetStringLowerCase(VALUE self, VALUE sString)
{
	StackPushString(rb_str2cstr(sString, NULL));
	VM_ExecuteCommand(61);
	char *sRetVal;
	StackPopString(sRetVal);
	return rb_str_new2(sRetVal);
}

static VALUE NWScript_GetStringRight(VALUE self, VALUE sString, VALUE nCount)
{
	StackPushInteger(NUM2INT(nCount));
	StackPushString(rb_str2cstr(sString, NULL));
	VM_ExecuteCommand(62);
	char *sRetVal;
	StackPopString(sRetVal);
	return rb_str_new2(sRetVal);
}

static VALUE NWScript_GetStringLeft(VALUE self, VALUE sString, VALUE nCount)
{
	StackPushInteger(NUM2INT(nCount));
	StackPushString(rb_str2cstr(sString, NULL));
	VM_ExecuteCommand(63);
	char *sRetVal;
	StackPopString(sRetVal);
	return rb_str_new2(sRetVal);
}

static VALUE NWScript_InsertString(VALUE self, VALUE sDestination, VALUE sString, VALUE nPosition)
{
	StackPushInteger(NUM2INT(nPosition));
	StackPushString(rb_str2cstr(sString, NULL));
	StackPushString(rb_str2cstr(sDestination, NULL));
	VM_ExecuteCommand(64);
	char *sRetVal;
	StackPopString(sRetVal);
	return rb_str_new2(sRetVal);
}

static VALUE NWScript_GetSubString(VALUE self, VALUE sString, VALUE nStart, VALUE nCount)
{
	StackPushInteger(NUM2INT(nCount));
	StackPushInteger(NUM2INT(nStart));
	StackPushString(rb_str2cstr(sString, NULL));
	VM_ExecuteCommand(65);
	char *sRetVal;
	StackPopString(sRetVal);
	return rb_str_new2(sRetVal);
}

static VALUE NWScript_FindSubString(VALUE self, VALUE sString, VALUE sSubString, VALUE nStart)
{
	StackPushInteger(NUM2INT(nStart));
	StackPushString(rb_str2cstr(sSubString, NULL));
	StackPushString(rb_str2cstr(sString, NULL));
	VM_ExecuteCommand(66);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_fabs(VALUE self, VALUE fValue)
{
	StackPushFloat(NUM2DBL(fValue));
	VM_ExecuteCommand(67);
	float fRetVal;
	StackPopFloat(&fRetVal);
	return rb_float_new(fRetVal);
}

static VALUE NWScript_cos(VALUE self, VALUE fValue)
{
	StackPushFloat(NUM2DBL(fValue));
	VM_ExecuteCommand(68);
	float fRetVal;
	StackPopFloat(&fRetVal);
	return rb_float_new(fRetVal);
}

static VALUE NWScript_sin(VALUE self, VALUE fValue)
{
	StackPushFloat(NUM2DBL(fValue));
	VM_ExecuteCommand(69);
	float fRetVal;
	StackPopFloat(&fRetVal);
	return rb_float_new(fRetVal);
}

static VALUE NWScript_tan(VALUE self, VALUE fValue)
{
	StackPushFloat(NUM2DBL(fValue));
	VM_ExecuteCommand(70);
	float fRetVal;
	StackPopFloat(&fRetVal);
	return rb_float_new(fRetVal);
}

static VALUE NWScript_acos(VALUE self, VALUE fValue)
{
	StackPushFloat(NUM2DBL(fValue));
	VM_ExecuteCommand(71);
	float fRetVal;
	StackPopFloat(&fRetVal);
	return rb_float_new(fRetVal);
}

static VALUE NWScript_asin(VALUE self, VALUE fValue)
{
	StackPushFloat(NUM2DBL(fValue));
	VM_ExecuteCommand(72);
	float fRetVal;
	StackPopFloat(&fRetVal);
	return rb_float_new(fRetVal);
}

static VALUE NWScript_atan(VALUE self, VALUE fValue)
{
	StackPushFloat(NUM2DBL(fValue));
	VM_ExecuteCommand(73);
	float fRetVal;
	StackPopFloat(&fRetVal);
	return rb_float_new(fRetVal);
}

static VALUE NWScript_log(VALUE self, VALUE fValue)
{
	StackPushFloat(NUM2DBL(fValue));
	VM_ExecuteCommand(74);
	float fRetVal;
	StackPopFloat(&fRetVal);
	return rb_float_new(fRetVal);
}

static VALUE NWScript_pow(VALUE self, VALUE fValue, VALUE fExponent)
{
	StackPushFloat(NUM2DBL(fExponent));
	StackPushFloat(NUM2DBL(fValue));
	VM_ExecuteCommand(75);
	float fRetVal;
	StackPopFloat(&fRetVal);
	return rb_float_new(fRetVal);
}

static VALUE NWScript_sqrt(VALUE self, VALUE fValue)
{
	StackPushFloat(NUM2DBL(fValue));
	VM_ExecuteCommand(76);
	float fRetVal;
	StackPopFloat(&fRetVal);
	return rb_float_new(fRetVal);
}

static VALUE NWScript_abs(VALUE self, VALUE nValue)
{
	StackPushInteger(NUM2INT(nValue));
	VM_ExecuteCommand(77);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_EffectHeal(VALUE self, VALUE nDamageToHeal)
{
	StackPushInteger(NUM2INT(nDamageToHeal));
	VM_ExecuteCommand(78);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectDamage(VALUE self, VALUE nDamageAmount, VALUE nDamageType, VALUE nDamagePower)
{
	StackPushInteger(NUM2INT(nDamagePower));
	StackPushInteger(NUM2INT(nDamageType));
	StackPushInteger(NUM2INT(nDamageAmount));
	VM_ExecuteCommand(79);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectAbilityIncrease(VALUE self, VALUE nAbilityToIncrease, VALUE nModifyBy)
{
	StackPushInteger(NUM2INT(nModifyBy));
	StackPushInteger(NUM2INT(nAbilityToIncrease));
	VM_ExecuteCommand(80);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectDamageResistance(VALUE self, VALUE nDamageType, VALUE nAmount, VALUE nLimit)
{
	StackPushInteger(NUM2INT(nLimit));
	StackPushInteger(NUM2INT(nAmount));
	StackPushInteger(NUM2INT(nDamageType));
	VM_ExecuteCommand(81);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectResurrection()
{
	VM_ExecuteCommand(82);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectSummonCreature(VALUE self, VALUE sCreatureResref, VALUE nVisualEffectId, VALUE fDelaySeconds, VALUE nUseAppearAnimation)
{
	StackPushInteger(NUM2INT(nUseAppearAnimation));
	StackPushFloat(NUM2DBL(fDelaySeconds));
	StackPushInteger(NUM2INT(nVisualEffectId));
	StackPushString(rb_str2cstr(sCreatureResref, NULL));
	VM_ExecuteCommand(83);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_GetCasterLevel(VALUE self, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(84);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetFirstEffect(VALUE self, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(85);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_GetNextEffect(VALUE self, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(86);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_RemoveEffect(VALUE self, VALUE oCreature, VALUE eEffect)
{
	//ERROR: Undefined variable type: effect
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(87);
	return Qnil;
}

static VALUE NWScript_GetIsEffectValid(VALUE self, VALUE eEffect)
{
	//ERROR: Undefined variable type: effect
	VM_ExecuteCommand(88);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetEffectDurationType(VALUE self, VALUE eEffect)
{
	//ERROR: Undefined variable type: effect
	VM_ExecuteCommand(89);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetEffectSubType(VALUE self, VALUE eEffect)
{
	//ERROR: Undefined variable type: effect
	VM_ExecuteCommand(90);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetEffectCreator(VALUE self, VALUE eEffect)
{
	//ERROR: Undefined variable type: effect
	VM_ExecuteCommand(91);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_IntToString(VALUE self, VALUE nInteger)
{
	StackPushInteger(NUM2INT(nInteger));
	VM_ExecuteCommand(92);
	char *sRetVal;
	StackPopString(sRetVal);
	return rb_str_new2(sRetVal);
}

static VALUE NWScript_GetFirstObjectInArea(VALUE self, VALUE oArea)
{
	StackPushObject(NUM2UINT(oArea));
	VM_ExecuteCommand(93);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetNextObjectInArea(VALUE self, VALUE oArea)
{
	StackPushObject(NUM2UINT(oArea));
	VM_ExecuteCommand(94);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_d2(VALUE self, VALUE nNumDice)
{
	StackPushInteger(NUM2INT(nNumDice));
	VM_ExecuteCommand(95);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_d3(VALUE self, VALUE nNumDice)
{
	StackPushInteger(NUM2INT(nNumDice));
	VM_ExecuteCommand(96);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_d4(VALUE self, VALUE nNumDice)
{
	StackPushInteger(NUM2INT(nNumDice));
	VM_ExecuteCommand(97);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_d6(VALUE self, VALUE nNumDice)
{
	StackPushInteger(NUM2INT(nNumDice));
	VM_ExecuteCommand(98);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_d8(VALUE self, VALUE nNumDice)
{
	StackPushInteger(NUM2INT(nNumDice));
	VM_ExecuteCommand(99);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_d10(VALUE self, VALUE nNumDice)
{
	StackPushInteger(NUM2INT(nNumDice));
	VM_ExecuteCommand(100);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_d12(VALUE self, VALUE nNumDice)
{
	StackPushInteger(NUM2INT(nNumDice));
	VM_ExecuteCommand(101);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_d20(VALUE self, VALUE nNumDice)
{
	StackPushInteger(NUM2INT(nNumDice));
	VM_ExecuteCommand(102);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_d100(VALUE self, VALUE nNumDice)
{
	StackPushInteger(NUM2INT(nNumDice));
	VM_ExecuteCommand(103);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_VectorMagnitude(VALUE self, VALUE vVector)
{
	//ERROR: Undefined variable type: vector
	VM_ExecuteCommand(104);
	float fRetVal;
	StackPopFloat(&fRetVal);
	return rb_float_new(fRetVal);
}

static VALUE NWScript_GetMetaMagicFeat()
{
	VM_ExecuteCommand(105);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetObjectType(VALUE self, VALUE oTarget)
{
	StackPushObject(NUM2UINT(oTarget));
	VM_ExecuteCommand(106);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetRacialType(VALUE self, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(107);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_FortitudeSave(VALUE self, VALUE oCreature, VALUE nDC, VALUE nSaveType, VALUE oSaveVersus)
{
	StackPushObject(NUM2UINT(oSaveVersus));
	StackPushInteger(NUM2INT(nSaveType));
	StackPushInteger(NUM2INT(nDC));
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(108);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_ReflexSave(VALUE self, VALUE oCreature, VALUE nDC, VALUE nSaveType, VALUE oSaveVersus)
{
	StackPushObject(NUM2UINT(oSaveVersus));
	StackPushInteger(NUM2INT(nSaveType));
	StackPushInteger(NUM2INT(nDC));
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(109);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_WillSave(VALUE self, VALUE oCreature, VALUE nDC, VALUE nSaveType, VALUE oSaveVersus)
{
	StackPushObject(NUM2UINT(oSaveVersus));
	StackPushInteger(NUM2INT(nSaveType));
	StackPushInteger(NUM2INT(nDC));
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(110);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetSpellSaveDC()
{
	VM_ExecuteCommand(111);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_MagicalEffect(VALUE self, VALUE eEffect)
{
	//ERROR: Undefined variable type: effect
	VM_ExecuteCommand(112);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_SupernaturalEffect(VALUE self, VALUE eEffect)
{
	//ERROR: Undefined variable type: effect
	VM_ExecuteCommand(113);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_ExtraordinaryEffect(VALUE self, VALUE eEffect)
{
	//ERROR: Undefined variable type: effect
	VM_ExecuteCommand(114);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectACIncrease(VALUE self, VALUE nValue, VALUE nModifyType, VALUE nDamageType)
{
	StackPushInteger(NUM2INT(nDamageType));
	StackPushInteger(NUM2INT(nModifyType));
	StackPushInteger(NUM2INT(nValue));
	VM_ExecuteCommand(115);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_GetAC(VALUE self, VALUE oObject, VALUE nForFutureUse)
{
	StackPushInteger(NUM2INT(nForFutureUse));
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(116);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_EffectSavingThrowIncrease(VALUE self, VALUE nSave, VALUE nValue, VALUE nSaveType)
{
	StackPushInteger(NUM2INT(nSaveType));
	StackPushInteger(NUM2INT(nValue));
	StackPushInteger(NUM2INT(nSave));
	VM_ExecuteCommand(117);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectAttackIncrease(VALUE self, VALUE nBonus, VALUE nModifierType)
{
	StackPushInteger(NUM2INT(nModifierType));
	StackPushInteger(NUM2INT(nBonus));
	VM_ExecuteCommand(118);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectDamageReduction(VALUE self, VALUE nAmount, VALUE nDamagePower, VALUE nLimit)
{
	StackPushInteger(NUM2INT(nLimit));
	StackPushInteger(NUM2INT(nDamagePower));
	StackPushInteger(NUM2INT(nAmount));
	VM_ExecuteCommand(119);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectDamageIncrease(VALUE self, VALUE nBonus, VALUE nDamageType)
{
	StackPushInteger(NUM2INT(nDamageType));
	StackPushInteger(NUM2INT(nBonus));
	VM_ExecuteCommand(120);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_RoundsToSeconds(VALUE self, VALUE nRounds)
{
	StackPushInteger(NUM2INT(nRounds));
	VM_ExecuteCommand(121);
	float fRetVal;
	StackPopFloat(&fRetVal);
	return rb_float_new(fRetVal);
}

static VALUE NWScript_HoursToSeconds(VALUE self, VALUE nHours)
{
	StackPushInteger(NUM2INT(nHours));
	VM_ExecuteCommand(122);
	float fRetVal;
	StackPopFloat(&fRetVal);
	return rb_float_new(fRetVal);
}

static VALUE NWScript_TurnsToSeconds(VALUE self, VALUE nTurns)
{
	StackPushInteger(NUM2INT(nTurns));
	VM_ExecuteCommand(123);
	float fRetVal;
	StackPopFloat(&fRetVal);
	return rb_float_new(fRetVal);
}

static VALUE NWScript_GetLawChaosValue(VALUE self, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(124);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetGoodEvilValue(VALUE self, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(125);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetAlignmentLawChaos(VALUE self, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(126);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetAlignmentGoodEvil(VALUE self, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(127);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetFirstObjectInShape(VALUE self, VALUE nShape, VALUE fSize, VALUE lTarget, VALUE bLineOfSight, VALUE nObjectFilter, VALUE vOrigin)
{
	//ERROR: Undefined variable type: 
	//ERROR: Undefined variable type: 
	//ERROR: Undefined variable type: vector
	StackPushInteger(NUM2INT(nObjectFilter));
	StackPushInteger(NUM2INT(bLineOfSight));
	//ERROR: Undefined variable type: location
	StackPushFloat(NUM2DBL(fSize));
	StackPushInteger(NUM2INT(nShape));
	VM_ExecuteCommand(128);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetNextObjectInShape(VALUE self, VALUE nShape, VALUE fSize, VALUE lTarget, VALUE bLineOfSight, VALUE nObjectFilter, VALUE vOrigin)
{
	//ERROR: Undefined variable type: 
	//ERROR: Undefined variable type: 
	//ERROR: Undefined variable type: vector
	StackPushInteger(NUM2INT(nObjectFilter));
	StackPushInteger(NUM2INT(bLineOfSight));
	//ERROR: Undefined variable type: location
	StackPushFloat(NUM2DBL(fSize));
	StackPushInteger(NUM2INT(nShape));
	VM_ExecuteCommand(129);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_EffectEntangle()
{
	VM_ExecuteCommand(130);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_SignalEvent(VALUE self, VALUE oObject, VALUE evToRun)
{
	//ERROR: Undefined variable type: event
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(131);
	return Qnil;
}

static VALUE NWScript_EventUserDefined(VALUE self, VALUE nUserDefinedEventNumber)
{
	StackPushInteger(NUM2INT(nUserDefinedEventNumber));
	VM_ExecuteCommand(132);
//ERROR: Undefined variable type: event
}

static VALUE NWScript_EffectDeath(VALUE self, VALUE nSpectacularDeath, VALUE nDisplayFeedback)
{
	StackPushInteger(NUM2INT(nDisplayFeedback));
	StackPushInteger(NUM2INT(nSpectacularDeath));
	VM_ExecuteCommand(133);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectKnockdown()
{
	VM_ExecuteCommand(134);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_ActionGiveItem(VALUE self, VALUE oItem, VALUE oGiveTo)
{
	StackPushObject(NUM2UINT(oGiveTo));
	StackPushObject(NUM2UINT(oItem));
	VM_ExecuteCommand(135);
	return Qnil;
}

static VALUE NWScript_ActionTakeItem(VALUE self, VALUE oItem, VALUE oTakeFrom)
{
	StackPushObject(NUM2UINT(oTakeFrom));
	StackPushObject(NUM2UINT(oItem));
	VM_ExecuteCommand(136);
	return Qnil;
}

static VALUE NWScript_VectorNormalize(VALUE self, VALUE vVector)
{
	//ERROR: Undefined variable type: vector
	VM_ExecuteCommand(137);
//ERROR: Undefined variable type: vector
}

static VALUE NWScript_EffectCurse(VALUE self, VALUE nStrMod, VALUE nDexMod, VALUE nConMod, VALUE nIntMod, VALUE nWisMod, VALUE nChaMod)
{
	StackPushInteger(NUM2INT(nChaMod));
	StackPushInteger(NUM2INT(nWisMod));
	StackPushInteger(NUM2INT(nIntMod));
	StackPushInteger(NUM2INT(nConMod));
	StackPushInteger(NUM2INT(nDexMod));
	StackPushInteger(NUM2INT(nStrMod));
	VM_ExecuteCommand(138);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_GetAbilityScore(VALUE self, VALUE oCreature, VALUE nAbilityType, VALUE nBaseAbilityScore)
{
	StackPushInteger(NUM2INT(nBaseAbilityScore));
	StackPushInteger(NUM2INT(nAbilityType));
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(139);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetIsDead(VALUE self, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(140);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_PrintVector(VALUE self, VALUE vVector, VALUE bPrepend)
{
	StackPushInteger(NUM2INT(bPrepend));
	//ERROR: Undefined variable type: vector
	VM_ExecuteCommand(141);
	return Qnil;
}

static VALUE NWScript_Vector(VALUE self, VALUE x, VALUE y, VALUE z)
{
	StackPushFloat(NUM2DBL(z));
	StackPushFloat(NUM2DBL(y));
	StackPushFloat(NUM2DBL(x));
	VM_ExecuteCommand(142);
//ERROR: Undefined variable type: vector
}

static VALUE NWScript_SetFacingPoint(VALUE self, VALUE vTarget)
{
	//ERROR: Undefined variable type: vector
	VM_ExecuteCommand(143);
	return Qnil;
}

static VALUE NWScript_AngleToVector(VALUE self, VALUE fAngle)
{
	StackPushFloat(NUM2DBL(fAngle));
	VM_ExecuteCommand(144);
//ERROR: Undefined variable type: vector
}

static VALUE NWScript_VectorToAngle(VALUE self, VALUE vVector)
{
	//ERROR: Undefined variable type: vector
	VM_ExecuteCommand(145);
	float fRetVal;
	StackPopFloat(&fRetVal);
	return rb_float_new(fRetVal);
}

static VALUE NWScript_TouchAttackMelee(VALUE self, VALUE oTarget, VALUE bDisplayFeedback)
{
	StackPushInteger(NUM2INT(bDisplayFeedback));
	StackPushObject(NUM2UINT(oTarget));
	VM_ExecuteCommand(146);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_TouchAttackRanged(VALUE self, VALUE oTarget, VALUE bDisplayFeedback)
{
	StackPushInteger(NUM2INT(bDisplayFeedback));
	StackPushObject(NUM2UINT(oTarget));
	VM_ExecuteCommand(147);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_EffectParalyze()
{
	VM_ExecuteCommand(148);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectSpellImmunity(VALUE self, VALUE nImmunityToSpell)
{
	StackPushInteger(NUM2INT(nImmunityToSpell));
	VM_ExecuteCommand(149);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectDeaf()
{
	VM_ExecuteCommand(150);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_GetDistanceBetween(VALUE self, VALUE oObjectA, VALUE oObjectB)
{
	StackPushObject(NUM2UINT(oObjectB));
	StackPushObject(NUM2UINT(oObjectA));
	VM_ExecuteCommand(151);
	float fRetVal;
	StackPopFloat(&fRetVal);
	return rb_float_new(fRetVal);
}

static VALUE NWScript_SetLocalLocation(VALUE self, VALUE oObject, VALUE sVarName, VALUE lValue)
{
	//ERROR: Undefined variable type: location
	StackPushString(rb_str2cstr(sVarName, NULL));
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(152);
	return Qnil;
}

static VALUE NWScript_GetLocalLocation(VALUE self, VALUE oObject, VALUE sVarName)
{
	StackPushString(rb_str2cstr(sVarName, NULL));
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(153);
//ERROR: Undefined variable type: location
}

static VALUE NWScript_EffectSleep()
{
	VM_ExecuteCommand(154);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_GetItemInSlot(VALUE self, VALUE nInventorySlot, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	StackPushInteger(NUM2INT(nInventorySlot));
	VM_ExecuteCommand(155);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_EffectCharmed()
{
	VM_ExecuteCommand(156);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectConfused()
{
	VM_ExecuteCommand(157);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectFrightened()
{
	VM_ExecuteCommand(158);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectDominated()
{
	VM_ExecuteCommand(159);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectDazed()
{
	VM_ExecuteCommand(160);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectStunned()
{
	VM_ExecuteCommand(161);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_SetCommandable(VALUE self, VALUE bCommandable, VALUE oTarget)
{
	StackPushObject(NUM2UINT(oTarget));
	StackPushInteger(NUM2INT(bCommandable));
	VM_ExecuteCommand(162);
	return Qnil;
}

static VALUE NWScript_GetCommandable(VALUE self, VALUE oTarget)
{
	StackPushObject(NUM2UINT(oTarget));
	VM_ExecuteCommand(163);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_EffectRegenerate(VALUE self, VALUE nAmount, VALUE fIntervalSeconds)
{
	StackPushFloat(NUM2DBL(fIntervalSeconds));
	StackPushInteger(NUM2INT(nAmount));
	VM_ExecuteCommand(164);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectMovementSpeedIncrease(VALUE self, VALUE nPercentChange)
{
	StackPushInteger(NUM2INT(nPercentChange));
	VM_ExecuteCommand(165);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_GetHitDice(VALUE self, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(166);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_ActionForceFollowObject(VALUE self, VALUE oFollow, VALUE fFollowDistance)
{
	StackPushFloat(NUM2DBL(fFollowDistance));
	StackPushObject(NUM2UINT(oFollow));
	VM_ExecuteCommand(167);
	return Qnil;
}

static VALUE NWScript_GetTag(VALUE self, VALUE oObject)
{
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(168);
	char *sRetVal;
	StackPopString(sRetVal);
	return rb_str_new2(sRetVal);
}

static VALUE NWScript_ResistSpell(VALUE self, VALUE oCaster, VALUE oTarget)
{
	StackPushObject(NUM2UINT(oTarget));
	StackPushObject(NUM2UINT(oCaster));
	VM_ExecuteCommand(169);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetEffectType(VALUE self, VALUE eEffect)
{
	//ERROR: Undefined variable type: effect
	VM_ExecuteCommand(170);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_EffectAreaOfEffect(VALUE self, VALUE nAreaEffectId, VALUE sOnEnterScript, VALUE sHeartbeatScript, VALUE sOnExitScript)
{
	StackPushString(rb_str2cstr(sOnExitScript, NULL));
	StackPushString(rb_str2cstr(sHeartbeatScript, NULL));
	StackPushString(rb_str2cstr(sOnEnterScript, NULL));
	StackPushInteger(NUM2INT(nAreaEffectId));
	VM_ExecuteCommand(171);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_GetFactionEqual(VALUE self, VALUE oFirstObject, VALUE oSecondObject)
{
	StackPushObject(NUM2UINT(oSecondObject));
	StackPushObject(NUM2UINT(oFirstObject));
	VM_ExecuteCommand(172);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_ChangeFaction(VALUE self, VALUE oObjectToChangeFaction, VALUE oMemberOfFactionToJoin)
{
	StackPushObject(NUM2UINT(oMemberOfFactionToJoin));
	StackPushObject(NUM2UINT(oObjectToChangeFaction));
	VM_ExecuteCommand(173);
	return Qnil;
}

static VALUE NWScript_GetIsListening(VALUE self, VALUE oObject)
{
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(174);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_SetListening(VALUE self, VALUE oObject, VALUE bValue)
{
	StackPushInteger(NUM2INT(bValue));
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(175);
	return Qnil;
}

static VALUE NWScript_SetListenPattern(VALUE self, VALUE oObject, VALUE sPattern, VALUE nNumber)
{
	StackPushInteger(NUM2INT(nNumber));
	StackPushString(rb_str2cstr(sPattern, NULL));
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(176);
	return Qnil;
}

static VALUE NWScript_TestStringAgainstPattern(VALUE self, VALUE sPattern, VALUE sStringToTest)
{
	StackPushString(rb_str2cstr(sStringToTest, NULL));
	StackPushString(rb_str2cstr(sPattern, NULL));
	VM_ExecuteCommand(177);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetMatchedSubstring(VALUE self, VALUE nString)
{
	StackPushInteger(NUM2INT(nString));
	VM_ExecuteCommand(178);
	char *sRetVal;
	StackPopString(sRetVal);
	return rb_str_new2(sRetVal);
}

static VALUE NWScript_GetMatchedSubstringsCount()
{
	VM_ExecuteCommand(179);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_EffectVisualEffect(VALUE self, VALUE nVisualEffectId, VALUE nMissEffect)
{
	StackPushInteger(NUM2INT(nMissEffect));
	StackPushInteger(NUM2INT(nVisualEffectId));
	VM_ExecuteCommand(180);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_GetFactionWeakestMember(VALUE self, VALUE oFactionMember, VALUE bMustBeVisible)
{
	StackPushInteger(NUM2INT(bMustBeVisible));
	StackPushObject(NUM2UINT(oFactionMember));
	VM_ExecuteCommand(181);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetFactionStrongestMember(VALUE self, VALUE oFactionMember, VALUE bMustBeVisible)
{
	StackPushInteger(NUM2INT(bMustBeVisible));
	StackPushObject(NUM2UINT(oFactionMember));
	VM_ExecuteCommand(182);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetFactionMostDamagedMember(VALUE self, VALUE oFactionMember, VALUE bMustBeVisible)
{
	StackPushInteger(NUM2INT(bMustBeVisible));
	StackPushObject(NUM2UINT(oFactionMember));
	VM_ExecuteCommand(183);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetFactionLeastDamagedMember(VALUE self, VALUE oFactionMember, VALUE bMustBeVisible)
{
	StackPushInteger(NUM2INT(bMustBeVisible));
	StackPushObject(NUM2UINT(oFactionMember));
	VM_ExecuteCommand(184);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetFactionGold(VALUE self, VALUE oFactionMember)
{
	StackPushObject(NUM2UINT(oFactionMember));
	VM_ExecuteCommand(185);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetFactionAverageReputation(VALUE self, VALUE oSourceFactionMember, VALUE oTarget)
{
	StackPushObject(NUM2UINT(oTarget));
	StackPushObject(NUM2UINT(oSourceFactionMember));
	VM_ExecuteCommand(186);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetFactionAverageGoodEvilAlignment(VALUE self, VALUE oFactionMember)
{
	StackPushObject(NUM2UINT(oFactionMember));
	VM_ExecuteCommand(187);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetFactionAverageLawChaosAlignment(VALUE self, VALUE oFactionMember)
{
	StackPushObject(NUM2UINT(oFactionMember));
	VM_ExecuteCommand(188);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetFactionAverageLevel(VALUE self, VALUE oFactionMember)
{
	StackPushObject(NUM2UINT(oFactionMember));
	VM_ExecuteCommand(189);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetFactionAverageXP(VALUE self, VALUE oFactionMember)
{
	StackPushObject(NUM2UINT(oFactionMember));
	VM_ExecuteCommand(190);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetFactionMostFrequentClass(VALUE self, VALUE oFactionMember)
{
	StackPushObject(NUM2UINT(oFactionMember));
	VM_ExecuteCommand(191);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetFactionWorstAC(VALUE self, VALUE oFactionMember, VALUE bMustBeVisible)
{
	StackPushInteger(NUM2INT(bMustBeVisible));
	StackPushObject(NUM2UINT(oFactionMember));
	VM_ExecuteCommand(192);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetFactionBestAC(VALUE self, VALUE oFactionMember, VALUE bMustBeVisible)
{
	StackPushInteger(NUM2INT(bMustBeVisible));
	StackPushObject(NUM2UINT(oFactionMember));
	VM_ExecuteCommand(193);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_ActionSit(VALUE self, VALUE oChair)
{
	StackPushObject(NUM2UINT(oChair));
	VM_ExecuteCommand(194);
	return Qnil;
}

static VALUE NWScript_GetListenPatternNumber()
{
	VM_ExecuteCommand(195);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_ActionJumpToObject(VALUE self, VALUE oToJumpTo, VALUE bWalkStraightLineToPoint)
{
	StackPushInteger(NUM2INT(bWalkStraightLineToPoint));
	StackPushObject(NUM2UINT(oToJumpTo));
	VM_ExecuteCommand(196);
	return Qnil;
}

static VALUE NWScript_GetWaypointByTag(VALUE self, VALUE sWaypointTag)
{
	StackPushString(rb_str2cstr(sWaypointTag, NULL));
	VM_ExecuteCommand(197);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetTransitionTarget(VALUE self, VALUE oTransition)
{
	StackPushObject(NUM2UINT(oTransition));
	VM_ExecuteCommand(198);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_EffectLinkEffects(VALUE self, VALUE eChildEffect, VALUE eParentEffect)
{
	//ERROR: Undefined variable type: effect
	//ERROR: Undefined variable type: effect
	VM_ExecuteCommand(199);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_GetObjectByTag(VALUE self, VALUE sTag, VALUE nNth)
{
	StackPushInteger(NUM2INT(nNth));
	StackPushString(rb_str2cstr(sTag, NULL));
	VM_ExecuteCommand(200);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_AdjustAlignment(VALUE self, VALUE oSubject, VALUE nAlignment, VALUE nShift, VALUE bAllPartyMembers)
{
	StackPushInteger(NUM2INT(bAllPartyMembers));
	StackPushInteger(NUM2INT(nShift));
	StackPushInteger(NUM2INT(nAlignment));
	StackPushObject(NUM2UINT(oSubject));
	VM_ExecuteCommand(201);
	return Qnil;
}

static VALUE NWScript_ActionWait(VALUE self, VALUE fSeconds)
{
	StackPushFloat(NUM2DBL(fSeconds));
	VM_ExecuteCommand(202);
	return Qnil;
}

static VALUE NWScript_SetAreaTransitionBMP(VALUE self, VALUE nPredefinedAreaTransition, VALUE sCustomAreaTransitionBMP)
{
	StackPushString(rb_str2cstr(sCustomAreaTransitionBMP, NULL));
	StackPushInteger(NUM2INT(nPredefinedAreaTransition));
	VM_ExecuteCommand(203);
	return Qnil;
}

static VALUE NWScript_ActionStartConversation(VALUE self, VALUE oObjectToConverseWith, VALUE sDialogResRef, VALUE bPrivateConversation, VALUE bPlayHello)
{
	StackPushInteger(NUM2INT(bPlayHello));
	StackPushInteger(NUM2INT(bPrivateConversation));
	StackPushString(rb_str2cstr(sDialogResRef, NULL));
	StackPushObject(NUM2UINT(oObjectToConverseWith));
	VM_ExecuteCommand(204);
	return Qnil;
}

static VALUE NWScript_ActionPauseConversation()
{
	VM_ExecuteCommand(205);
	return Qnil;
}

static VALUE NWScript_ActionResumeConversation()
{
	VM_ExecuteCommand(206);
	return Qnil;
}

static VALUE NWScript_EffectBeam(VALUE self, VALUE nBeamVisualEffect, VALUE oEffector, VALUE nBodyPart, VALUE bMissEffect)
{
	StackPushInteger(NUM2INT(bMissEffect));
	StackPushInteger(NUM2INT(nBodyPart));
	StackPushObject(NUM2UINT(oEffector));
	StackPushInteger(NUM2INT(nBeamVisualEffect));
	VM_ExecuteCommand(207);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_GetReputation(VALUE self, VALUE oSource, VALUE oTarget)
{
	StackPushObject(NUM2UINT(oTarget));
	StackPushObject(NUM2UINT(oSource));
	VM_ExecuteCommand(208);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_AdjustReputation(VALUE self, VALUE oTarget, VALUE oSourceFactionMember, VALUE nAdjustment)
{
	StackPushInteger(NUM2INT(nAdjustment));
	StackPushObject(NUM2UINT(oSourceFactionMember));
	StackPushObject(NUM2UINT(oTarget));
	VM_ExecuteCommand(209);
	return Qnil;
}

static VALUE NWScript_GetSittingCreature(VALUE self, VALUE oChair)
{
	StackPushObject(NUM2UINT(oChair));
	VM_ExecuteCommand(210);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetGoingToBeAttackedBy(VALUE self, VALUE oTarget)
{
	StackPushObject(NUM2UINT(oTarget));
	VM_ExecuteCommand(211);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_EffectSpellResistanceIncrease(VALUE self, VALUE nValue)
{
	StackPushInteger(NUM2INT(nValue));
	VM_ExecuteCommand(212);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_GetLocation(VALUE self, VALUE oObject)
{
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(213);
//ERROR: Undefined variable type: location
}

static VALUE NWScript_ActionJumpToLocation(VALUE self, VALUE lLocation)
{
	//ERROR: Undefined variable type: location
	VM_ExecuteCommand(214);
	return Qnil;
}

static VALUE NWScript_Location(VALUE self, VALUE oArea, VALUE vPosition, VALUE fOrientation)
{
	StackPushFloat(NUM2DBL(fOrientation));
	//ERROR: Undefined variable type: vector
	StackPushObject(NUM2UINT(oArea));
	VM_ExecuteCommand(215);
//ERROR: Undefined variable type: location
}

static VALUE NWScript_ApplyEffectAtLocation(VALUE self, VALUE nDurationType, VALUE eEffect, VALUE lLocation, VALUE fDuration)
{
	StackPushFloat(NUM2DBL(fDuration));
	//ERROR: Undefined variable type: location
	//ERROR: Undefined variable type: effect
	StackPushInteger(NUM2INT(nDurationType));
	VM_ExecuteCommand(216);
	return Qnil;
}

static VALUE NWScript_GetIsPC(VALUE self, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(217);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_FeetToMeters(VALUE self, VALUE fFeet)
{
	StackPushFloat(NUM2DBL(fFeet));
	VM_ExecuteCommand(218);
	float fRetVal;
	StackPopFloat(&fRetVal);
	return rb_float_new(fRetVal);
}

static VALUE NWScript_YardsToMeters(VALUE self, VALUE fYards)
{
	StackPushFloat(NUM2DBL(fYards));
	VM_ExecuteCommand(219);
	float fRetVal;
	StackPopFloat(&fRetVal);
	return rb_float_new(fRetVal);
}

static VALUE NWScript_ApplyEffectToObject(VALUE self, VALUE nDurationType, VALUE eEffect, VALUE oTarget, VALUE fDuration)
{
	StackPushFloat(NUM2DBL(fDuration));
	StackPushObject(NUM2UINT(oTarget));
	//ERROR: Undefined variable type: effect
	StackPushInteger(NUM2INT(nDurationType));
	VM_ExecuteCommand(220);
	return Qnil;
}

static VALUE NWScript_SpeakString(VALUE self, VALUE sStringToSpeak, VALUE nTalkVolume)
{
	StackPushInteger(NUM2INT(nTalkVolume));
	StackPushString(rb_str2cstr(sStringToSpeak, NULL));
	VM_ExecuteCommand(221);
	return Qnil;
}

static VALUE NWScript_GetSpellTargetLocation()
{
	VM_ExecuteCommand(222);
//ERROR: Undefined variable type: location
}

static VALUE NWScript_GetPositionFromLocation(VALUE self, VALUE lLocation)
{
	//ERROR: Undefined variable type: location
	VM_ExecuteCommand(223);
//ERROR: Undefined variable type: vector
}

static VALUE NWScript_GetAreaFromLocation(VALUE self, VALUE lLocation)
{
	//ERROR: Undefined variable type: location
	VM_ExecuteCommand(224);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetFacingFromLocation(VALUE self, VALUE lLocation)
{
	//ERROR: Undefined variable type: location
	VM_ExecuteCommand(225);
	float fRetVal;
	StackPopFloat(&fRetVal);
	return rb_float_new(fRetVal);
}

static VALUE NWScript_GetNearestCreatureToLocation(VALUE self, VALUE nFirstCriteriaType, VALUE nFirstCriteriaValue, VALUE lLocation, VALUE nNth, VALUE nSecondCriteriaType, VALUE nSecondCriteriaValue, VALUE nThirdCriteriaType, VALUE nThirdCriteriaValue)
{
	StackPushInteger(NUM2INT(nThirdCriteriaValue));
	StackPushInteger(NUM2INT(nThirdCriteriaType));
	StackPushInteger(NUM2INT(nSecondCriteriaValue));
	StackPushInteger(NUM2INT(nSecondCriteriaType));
	StackPushInteger(NUM2INT(nNth));
	//ERROR: Undefined variable type: location
	StackPushInteger(NUM2INT(nFirstCriteriaValue));
	StackPushInteger(NUM2INT(nFirstCriteriaType));
	VM_ExecuteCommand(226);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetNearestObject(VALUE self, VALUE nObjectType, VALUE oTarget, VALUE nNth)
{
	StackPushInteger(NUM2INT(nNth));
	StackPushObject(NUM2UINT(oTarget));
	StackPushInteger(NUM2INT(nObjectType));
	VM_ExecuteCommand(227);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetNearestObjectToLocation(VALUE self, VALUE nObjectType, VALUE lLocation, VALUE nNth)
{
	StackPushInteger(NUM2INT(nNth));
	//ERROR: Undefined variable type: location
	StackPushInteger(NUM2INT(nObjectType));
	VM_ExecuteCommand(228);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetNearestObjectByTag(VALUE self, VALUE sTag, VALUE oTarget, VALUE nNth)
{
	StackPushInteger(NUM2INT(nNth));
	StackPushObject(NUM2UINT(oTarget));
	StackPushString(rb_str2cstr(sTag, NULL));
	VM_ExecuteCommand(229);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_IntToFloat(VALUE self, VALUE nInteger)
{
	StackPushInteger(NUM2INT(nInteger));
	VM_ExecuteCommand(230);
	float fRetVal;
	StackPopFloat(&fRetVal);
	return rb_float_new(fRetVal);
}

static VALUE NWScript_FloatToInt(VALUE self, VALUE fFloat)
{
	StackPushFloat(NUM2DBL(fFloat));
	VM_ExecuteCommand(231);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_StringToInt(VALUE self, VALUE sNumber)
{
	StackPushString(rb_str2cstr(sNumber, NULL));
	VM_ExecuteCommand(232);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_StringToFloat(VALUE self, VALUE sNumber)
{
	StackPushString(rb_str2cstr(sNumber, NULL));
	VM_ExecuteCommand(233);
	float fRetVal;
	StackPopFloat(&fRetVal);
	return rb_float_new(fRetVal);
}

static VALUE NWScript_ActionCastSpellAtLocation(VALUE self, VALUE nSpell, VALUE lTargetLocation, VALUE nMetaMagic, VALUE bCheat, VALUE nProjectilePathType, VALUE bInstantSpell)
{
	StackPushInteger(NUM2INT(bInstantSpell));
	StackPushInteger(NUM2INT(nProjectilePathType));
	StackPushInteger(NUM2INT(bCheat));
	StackPushInteger(NUM2INT(nMetaMagic));
	//ERROR: Undefined variable type: location
	StackPushInteger(NUM2INT(nSpell));
	VM_ExecuteCommand(234);
	return Qnil;
}

static VALUE NWScript_GetIsEnemy(VALUE self, VALUE oTarget, VALUE oSource)
{
	StackPushObject(NUM2UINT(oSource));
	StackPushObject(NUM2UINT(oTarget));
	VM_ExecuteCommand(235);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetIsFriend(VALUE self, VALUE oTarget, VALUE oSource)
{
	StackPushObject(NUM2UINT(oSource));
	StackPushObject(NUM2UINT(oTarget));
	VM_ExecuteCommand(236);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetIsNeutral(VALUE self, VALUE oTarget, VALUE oSource)
{
	StackPushObject(NUM2UINT(oSource));
	StackPushObject(NUM2UINT(oTarget));
	VM_ExecuteCommand(237);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetPCSpeaker()
{
	VM_ExecuteCommand(238);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetStringByStrRef(VALUE self, VALUE nStrRef, VALUE nGender)
{
	StackPushInteger(NUM2INT(nGender));
	StackPushInteger(NUM2INT(nStrRef));
	VM_ExecuteCommand(239);
	char *sRetVal;
	StackPopString(sRetVal);
	return rb_str_new2(sRetVal);
}

static VALUE NWScript_ActionSpeakStringByStrRef(VALUE self, VALUE nStrRef, VALUE nTalkVolume)
{
	StackPushInteger(NUM2INT(nTalkVolume));
	StackPushInteger(NUM2INT(nStrRef));
	VM_ExecuteCommand(240);
	return Qnil;
}

static VALUE NWScript_DestroyObject(VALUE self, VALUE oDestroy, VALUE fDelay)
{
	StackPushFloat(NUM2DBL(fDelay));
	StackPushObject(NUM2UINT(oDestroy));
	VM_ExecuteCommand(241);
	return Qnil;
}

static VALUE NWScript_GetModule()
{
	VM_ExecuteCommand(242);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_CreateObject(VALUE self, VALUE nObjectType, VALUE sTemplate, VALUE lLocation, VALUE bUseAppearAnimation, VALUE sNewTag)
{
	StackPushString(rb_str2cstr(sNewTag, NULL));
	StackPushInteger(NUM2INT(bUseAppearAnimation));
	//ERROR: Undefined variable type: location
	StackPushString(rb_str2cstr(sTemplate, NULL));
	StackPushInteger(NUM2INT(nObjectType));
	VM_ExecuteCommand(243);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_EventSpellCastAt(VALUE self, VALUE oCaster, VALUE nSpell, VALUE bHarmful)
{
	StackPushInteger(NUM2INT(bHarmful));
	StackPushInteger(NUM2INT(nSpell));
	StackPushObject(NUM2UINT(oCaster));
	VM_ExecuteCommand(244);
//ERROR: Undefined variable type: event
}

static VALUE NWScript_GetLastSpellCaster()
{
	VM_ExecuteCommand(245);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastSpell()
{
	VM_ExecuteCommand(246);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetUserDefinedEventNumber()
{
	VM_ExecuteCommand(247);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetSpellId()
{
	VM_ExecuteCommand(248);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_RandomName(VALUE self, VALUE nNameType)
{
	StackPushInteger(NUM2INT(nNameType));
	VM_ExecuteCommand(249);
	char *sRetVal;
	StackPopString(sRetVal);
	return rb_str_new2(sRetVal);
}

static VALUE NWScript_EffectPoison(VALUE self, VALUE nPoisonType)
{
	StackPushInteger(NUM2INT(nPoisonType));
	VM_ExecuteCommand(250);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectDisease(VALUE self, VALUE nDiseaseType)
{
	StackPushInteger(NUM2INT(nDiseaseType));
	VM_ExecuteCommand(251);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectSilence()
{
	VM_ExecuteCommand(252);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_GetName(VALUE self, VALUE oObject, VALUE bOriginalName)
{
	StackPushInteger(NUM2INT(bOriginalName));
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(253);
	char *sRetVal;
	StackPopString(sRetVal);
	return rb_str_new2(sRetVal);
}

static VALUE NWScript_GetLastSpeaker()
{
	VM_ExecuteCommand(254);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_BeginConversation(VALUE self, VALUE sResRef, VALUE oObjectToDialog)
{
	StackPushObject(NUM2UINT(oObjectToDialog));
	StackPushString(rb_str2cstr(sResRef, NULL));
	VM_ExecuteCommand(255);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastPerceived()
{
	VM_ExecuteCommand(256);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastPerceptionHeard()
{
	VM_ExecuteCommand(257);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastPerceptionInaudible()
{
	VM_ExecuteCommand(258);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastPerceptionSeen()
{
	VM_ExecuteCommand(259);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastClosedBy()
{
	VM_ExecuteCommand(260);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastPerceptionVanished()
{
	VM_ExecuteCommand(261);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetFirstInPersistentObject(VALUE self, VALUE oPersistentObject, VALUE nResidentObjectType, VALUE nPersistentZone)
{
	StackPushInteger(NUM2INT(nPersistentZone));
	StackPushInteger(NUM2INT(nResidentObjectType));
	StackPushObject(NUM2UINT(oPersistentObject));
	VM_ExecuteCommand(262);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetNextInPersistentObject(VALUE self, VALUE oPersistentObject, VALUE nResidentObjectType, VALUE nPersistentZone)
{
	StackPushInteger(NUM2INT(nPersistentZone));
	StackPushInteger(NUM2INT(nResidentObjectType));
	StackPushObject(NUM2UINT(oPersistentObject));
	VM_ExecuteCommand(263);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetAreaOfEffectCreator(VALUE self, VALUE oAreaOfEffectObject)
{
	StackPushObject(NUM2UINT(oAreaOfEffectObject));
	VM_ExecuteCommand(264);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_DeleteLocalInt(VALUE self, VALUE oObject, VALUE sVarName)
{
	StackPushString(rb_str2cstr(sVarName, NULL));
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(265);
	return Qnil;
}

static VALUE NWScript_DeleteLocalFloat(VALUE self, VALUE oObject, VALUE sVarName)
{
	StackPushString(rb_str2cstr(sVarName, NULL));
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(266);
	return Qnil;
}

static VALUE NWScript_DeleteLocalString(VALUE self, VALUE oObject, VALUE sVarName)
{
	StackPushString(rb_str2cstr(sVarName, NULL));
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(267);
	return Qnil;
}

static VALUE NWScript_DeleteLocalObject(VALUE self, VALUE oObject, VALUE sVarName)
{
	StackPushString(rb_str2cstr(sVarName, NULL));
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(268);
	return Qnil;
}

static VALUE NWScript_DeleteLocalLocation(VALUE self, VALUE oObject, VALUE sVarName)
{
	StackPushString(rb_str2cstr(sVarName, NULL));
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(269);
	return Qnil;
}

static VALUE NWScript_EffectHaste()
{
	VM_ExecuteCommand(270);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectSlow()
{
	VM_ExecuteCommand(271);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_ObjectToString(VALUE self, VALUE oObject)
{
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(272);
	char *sRetVal;
	StackPopString(sRetVal);
	return rb_str_new2(sRetVal);
}

static VALUE NWScript_EffectImmunity(VALUE self, VALUE nImmunityType)
{
	StackPushInteger(NUM2INT(nImmunityType));
	VM_ExecuteCommand(273);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_GetIsImmune(VALUE self, VALUE oCreature, VALUE nImmunityType, VALUE oVersus)
{
	StackPushObject(NUM2UINT(oVersus));
	StackPushInteger(NUM2INT(nImmunityType));
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(274);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_EffectDamageImmunityIncrease(VALUE self, VALUE nDamageType, VALUE nPercentImmunity)
{
	StackPushInteger(NUM2INT(nPercentImmunity));
	StackPushInteger(NUM2INT(nDamageType));
	VM_ExecuteCommand(275);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_GetEncounterActive(VALUE self, VALUE oEncounter)
{
	StackPushObject(NUM2UINT(oEncounter));
	VM_ExecuteCommand(276);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_SetEncounterActive(VALUE self, VALUE nNewValue, VALUE oEncounter)
{
	StackPushObject(NUM2UINT(oEncounter));
	StackPushInteger(NUM2INT(nNewValue));
	VM_ExecuteCommand(277);
	return Qnil;
}

static VALUE NWScript_GetEncounterSpawnsMax(VALUE self, VALUE oEncounter)
{
	StackPushObject(NUM2UINT(oEncounter));
	VM_ExecuteCommand(278);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_SetEncounterSpawnsMax(VALUE self, VALUE nNewValue, VALUE oEncounter)
{
	StackPushObject(NUM2UINT(oEncounter));
	StackPushInteger(NUM2INT(nNewValue));
	VM_ExecuteCommand(279);
	return Qnil;
}

static VALUE NWScript_GetEncounterSpawnsCurrent(VALUE self, VALUE oEncounter)
{
	StackPushObject(NUM2UINT(oEncounter));
	VM_ExecuteCommand(280);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_SetEncounterSpawnsCurrent(VALUE self, VALUE nNewValue, VALUE oEncounter)
{
	StackPushObject(NUM2UINT(oEncounter));
	StackPushInteger(NUM2INT(nNewValue));
	VM_ExecuteCommand(281);
	return Qnil;
}

static VALUE NWScript_GetModuleItemAcquired()
{
	VM_ExecuteCommand(282);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetModuleItemAcquiredFrom()
{
	VM_ExecuteCommand(283);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_SetCustomToken(VALUE self, VALUE nCustomTokenNumber, VALUE sTokenValue)
{
	StackPushString(rb_str2cstr(sTokenValue, NULL));
	StackPushInteger(NUM2INT(nCustomTokenNumber));
	VM_ExecuteCommand(284);
	return Qnil;
}

static VALUE NWScript_GetHasFeat(VALUE self, VALUE nFeat, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	StackPushInteger(NUM2INT(nFeat));
	VM_ExecuteCommand(285);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetHasSkill(VALUE self, VALUE nSkill, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	StackPushInteger(NUM2INT(nSkill));
	VM_ExecuteCommand(286);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_ActionUseFeat(VALUE self, VALUE nFeat, VALUE oTarget)
{
	StackPushObject(NUM2UINT(oTarget));
	StackPushInteger(NUM2INT(nFeat));
	VM_ExecuteCommand(287);
	return Qnil;
}

static VALUE NWScript_ActionUseSkill(VALUE self, VALUE nSkill, VALUE oTarget, VALUE nSubSkill, VALUE oItemUsed)
{
	StackPushObject(NUM2UINT(oItemUsed));
	StackPushInteger(NUM2INT(nSubSkill));
	StackPushObject(NUM2UINT(oTarget));
	StackPushInteger(NUM2INT(nSkill));
	VM_ExecuteCommand(288);
	return Qnil;
}

static VALUE NWScript_GetObjectSeen(VALUE self, VALUE oTarget, VALUE oSource)
{
	StackPushObject(NUM2UINT(oSource));
	StackPushObject(NUM2UINT(oTarget));
	VM_ExecuteCommand(289);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetObjectHeard(VALUE self, VALUE oTarget, VALUE oSource)
{
	StackPushObject(NUM2UINT(oSource));
	StackPushObject(NUM2UINT(oTarget));
	VM_ExecuteCommand(290);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastPlayerDied()
{
	VM_ExecuteCommand(291);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetModuleItemLost()
{
	VM_ExecuteCommand(292);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetModuleItemLostBy()
{
	VM_ExecuteCommand(293);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_ActionDoCommand(VALUE self, VALUE aActionToDo)
{
	//ERROR: Undefined variable type: action
	VM_ExecuteCommand(294);
	return Qnil;
}

static VALUE NWScript_EventConversation()
{
	VM_ExecuteCommand(295);
//ERROR: Undefined variable type: event
}

static VALUE NWScript_SetEncounterDifficulty(VALUE self, VALUE nEncounterDifficulty, VALUE oEncounter)
{
	StackPushObject(NUM2UINT(oEncounter));
	StackPushInteger(NUM2INT(nEncounterDifficulty));
	VM_ExecuteCommand(296);
	return Qnil;
}

static VALUE NWScript_GetEncounterDifficulty(VALUE self, VALUE oEncounter)
{
	StackPushObject(NUM2UINT(oEncounter));
	VM_ExecuteCommand(297);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetDistanceBetweenLocations(VALUE self, VALUE lLocationA, VALUE lLocationB)
{
	//ERROR: Undefined variable type: location
	//ERROR: Undefined variable type: location
	VM_ExecuteCommand(298);
	float fRetVal;
	StackPopFloat(&fRetVal);
	return rb_float_new(fRetVal);
}

static VALUE NWScript_GetReflexAdjustedDamage(VALUE self, VALUE nDamage, VALUE oTarget, VALUE nDC, VALUE nSaveType, VALUE oSaveVersus)
{
	StackPushObject(NUM2UINT(oSaveVersus));
	StackPushInteger(NUM2INT(nSaveType));
	StackPushInteger(NUM2INT(nDC));
	StackPushObject(NUM2UINT(oTarget));
	StackPushInteger(NUM2INT(nDamage));
	VM_ExecuteCommand(299);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_PlayAnimation(VALUE self, VALUE nAnimation, VALUE fSpeed, VALUE fSeconds)
{
	StackPushFloat(NUM2DBL(fSeconds));
	StackPushFloat(NUM2DBL(fSpeed));
	StackPushInteger(NUM2INT(nAnimation));
	VM_ExecuteCommand(300);
	return Qnil;
}

static VALUE NWScript_TalentSpell(VALUE self, VALUE nSpell)
{
	StackPushInteger(NUM2INT(nSpell));
	VM_ExecuteCommand(301);
//ERROR: Undefined variable type: talent
}

static VALUE NWScript_TalentFeat(VALUE self, VALUE nFeat)
{
	StackPushInteger(NUM2INT(nFeat));
	VM_ExecuteCommand(302);
//ERROR: Undefined variable type: talent
}

static VALUE NWScript_TalentSkill(VALUE self, VALUE nSkill)
{
	StackPushInteger(NUM2INT(nSkill));
	VM_ExecuteCommand(303);
//ERROR: Undefined variable type: talent
}

static VALUE NWScript_GetHasSpellEffect(VALUE self, VALUE nSpell, VALUE oObject)
{
	StackPushObject(NUM2UINT(oObject));
	StackPushInteger(NUM2INT(nSpell));
	VM_ExecuteCommand(304);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetEffectSpellId(VALUE self, VALUE eSpellEffect)
{
	//ERROR: Undefined variable type: effect
	VM_ExecuteCommand(305);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetCreatureHasTalent(VALUE self, VALUE tTalent, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	//ERROR: Undefined variable type: talent
	VM_ExecuteCommand(306);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetCreatureTalentRandom(VALUE self, VALUE nCategory, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	StackPushInteger(NUM2INT(nCategory));
	VM_ExecuteCommand(307);
//ERROR: Undefined variable type: talent
}

static VALUE NWScript_GetCreatureTalentBest(VALUE self, VALUE nCategory, VALUE nCRMax, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	StackPushInteger(NUM2INT(nCRMax));
	StackPushInteger(NUM2INT(nCategory));
	VM_ExecuteCommand(308);
//ERROR: Undefined variable type: talent
}

static VALUE NWScript_ActionUseTalentOnObject(VALUE self, VALUE tChosenTalent, VALUE oTarget)
{
	StackPushObject(NUM2UINT(oTarget));
	//ERROR: Undefined variable type: talent
	VM_ExecuteCommand(309);
	return Qnil;
}

static VALUE NWScript_ActionUseTalentAtLocation(VALUE self, VALUE tChosenTalent, VALUE lTargetLocation)
{
	//ERROR: Undefined variable type: location
	//ERROR: Undefined variable type: talent
	VM_ExecuteCommand(310);
	return Qnil;
}

static VALUE NWScript_GetGoldPieceValue(VALUE self, VALUE oItem)
{
	StackPushObject(NUM2UINT(oItem));
	VM_ExecuteCommand(311);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetIsPlayableRacialType(VALUE self, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(312);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_JumpToLocation(VALUE self, VALUE lDestination)
{
	//ERROR: Undefined variable type: location
	VM_ExecuteCommand(313);
	return Qnil;
}

static VALUE NWScript_EffectTemporaryHitpoints(VALUE self, VALUE nHitPoints)
{
	StackPushInteger(NUM2INT(nHitPoints));
	VM_ExecuteCommand(314);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_GetSkillRank(VALUE self, VALUE nSkill, VALUE oTarget, VALUE nBaseSkillRank)
{
	StackPushInteger(NUM2INT(nBaseSkillRank));
	StackPushObject(NUM2UINT(oTarget));
	StackPushInteger(NUM2INT(nSkill));
	VM_ExecuteCommand(315);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetAttackTarget(VALUE self, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(316);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastAttackType(VALUE self, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(317);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastAttackMode(VALUE self, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(318);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetMaster(VALUE self, VALUE oAssociate)
{
	StackPushObject(NUM2UINT(oAssociate));
	VM_ExecuteCommand(319);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetIsInCombat(VALUE self, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(320);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastAssociateCommand(VALUE self, VALUE oAssociate)
{
	StackPushObject(NUM2UINT(oAssociate));
	VM_ExecuteCommand(321);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GiveGoldToCreature(VALUE self, VALUE oCreature, VALUE nGP)
{
	StackPushInteger(NUM2INT(nGP));
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(322);
	return Qnil;
}

static VALUE NWScript_SetIsDestroyable(VALUE self, VALUE bDestroyable, VALUE bRaiseable, VALUE bSelectableWhenDead)
{
	StackPushInteger(NUM2INT(bSelectableWhenDead));
	StackPushInteger(NUM2INT(bRaiseable));
	StackPushInteger(NUM2INT(bDestroyable));
	VM_ExecuteCommand(323);
	return Qnil;
}

static VALUE NWScript_SetLocked(VALUE self, VALUE oTarget, VALUE bLocked)
{
	StackPushInteger(NUM2INT(bLocked));
	StackPushObject(NUM2UINT(oTarget));
	VM_ExecuteCommand(324);
	return Qnil;
}

static VALUE NWScript_GetLocked(VALUE self, VALUE oTarget)
{
	StackPushObject(NUM2UINT(oTarget));
	VM_ExecuteCommand(325);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetClickingObject()
{
	VM_ExecuteCommand(326);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_SetAssociateListenPatterns(VALUE self, VALUE oTarget)
{
	StackPushObject(NUM2UINT(oTarget));
	VM_ExecuteCommand(327);
	return Qnil;
}

static VALUE NWScript_GetLastWeaponUsed(VALUE self, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(328);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_ActionInteractObject(VALUE self, VALUE oPlaceable)
{
	StackPushObject(NUM2UINT(oPlaceable));
	VM_ExecuteCommand(329);
	return Qnil;
}

static VALUE NWScript_GetLastUsedBy()
{
	VM_ExecuteCommand(330);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetAbilityModifier(VALUE self, VALUE nAbility, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	StackPushInteger(NUM2INT(nAbility));
	VM_ExecuteCommand(331);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetIdentified(VALUE self, VALUE oItem)
{
	StackPushObject(NUM2UINT(oItem));
	VM_ExecuteCommand(332);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_SetIdentified(VALUE self, VALUE oItem, VALUE bIdentified)
{
	StackPushInteger(NUM2INT(bIdentified));
	StackPushObject(NUM2UINT(oItem));
	VM_ExecuteCommand(333);
	return Qnil;
}

static VALUE NWScript_SummonAnimalCompanion(VALUE self, VALUE oMaster)
{
	StackPushObject(NUM2UINT(oMaster));
	VM_ExecuteCommand(334);
	return Qnil;
}

static VALUE NWScript_SummonFamiliar(VALUE self, VALUE oMaster)
{
	StackPushObject(NUM2UINT(oMaster));
	VM_ExecuteCommand(335);
	return Qnil;
}

static VALUE NWScript_GetBlockingDoor()
{
	VM_ExecuteCommand(336);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetIsDoorActionPossible(VALUE self, VALUE oTargetDoor, VALUE nDoorAction)
{
	StackPushInteger(NUM2INT(nDoorAction));
	StackPushObject(NUM2UINT(oTargetDoor));
	VM_ExecuteCommand(337);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_DoDoorAction(VALUE self, VALUE oTargetDoor, VALUE nDoorAction)
{
	StackPushInteger(NUM2INT(nDoorAction));
	StackPushObject(NUM2UINT(oTargetDoor));
	VM_ExecuteCommand(338);
	return Qnil;
}

static VALUE NWScript_GetFirstItemInInventory(VALUE self, VALUE oTarget)
{
	StackPushObject(NUM2UINT(oTarget));
	VM_ExecuteCommand(339);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetNextItemInInventory(VALUE self, VALUE oTarget)
{
	StackPushObject(NUM2UINT(oTarget));
	VM_ExecuteCommand(340);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetClassByPosition(VALUE self, VALUE nClassPosition, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	StackPushInteger(NUM2INT(nClassPosition));
	VM_ExecuteCommand(341);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLevelByPosition(VALUE self, VALUE nClassPosition, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	StackPushInteger(NUM2INT(nClassPosition));
	VM_ExecuteCommand(342);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLevelByClass(VALUE self, VALUE nClassType, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	StackPushInteger(NUM2INT(nClassType));
	VM_ExecuteCommand(343);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetDamageDealtByType(VALUE self, VALUE nDamageType)
{
	StackPushInteger(NUM2INT(nDamageType));
	VM_ExecuteCommand(344);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetTotalDamageDealt()
{
	VM_ExecuteCommand(345);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastDamager(VALUE self, VALUE oObject)
{
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(346);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastDisarmed()
{
	VM_ExecuteCommand(347);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastDisturbed()
{
	VM_ExecuteCommand(348);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastLocked()
{
	VM_ExecuteCommand(349);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastUnlocked()
{
	VM_ExecuteCommand(350);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_EffectSkillIncrease(VALUE self, VALUE nSkill, VALUE nValue)
{
	StackPushInteger(NUM2INT(nValue));
	StackPushInteger(NUM2INT(nSkill));
	VM_ExecuteCommand(351);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_GetInventoryDisturbType()
{
	VM_ExecuteCommand(352);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetInventoryDisturbItem()
{
	VM_ExecuteCommand(353);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetHenchman(VALUE self, VALUE oMaster, VALUE nNth)
{
	StackPushInteger(NUM2INT(nNth));
	StackPushObject(NUM2UINT(oMaster));
	VM_ExecuteCommand(354);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_VersusAlignmentEffect(VALUE self, VALUE eEffect, VALUE nLawChaos, VALUE nGoodEvil)
{
	StackPushInteger(NUM2INT(nGoodEvil));
	StackPushInteger(NUM2INT(nLawChaos));
	//ERROR: Undefined variable type: effect
	VM_ExecuteCommand(355);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_VersusRacialTypeEffect(VALUE self, VALUE eEffect, VALUE nRacialType)
{
	StackPushInteger(NUM2INT(nRacialType));
	//ERROR: Undefined variable type: effect
	VM_ExecuteCommand(356);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_VersusTrapEffect(VALUE self, VALUE eEffect)
{
	//ERROR: Undefined variable type: effect
	VM_ExecuteCommand(357);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_GetGender(VALUE self, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(358);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetIsTalentValid(VALUE self, VALUE tTalent)
{
	//ERROR: Undefined variable type: talent
	VM_ExecuteCommand(359);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_ActionMoveAwayFromLocation(VALUE self, VALUE lMoveAwayFrom, VALUE bRun, VALUE fMoveAwayRange)
{
	StackPushFloat(NUM2DBL(fMoveAwayRange));
	StackPushInteger(NUM2INT(bRun));
	//ERROR: Undefined variable type: location
	VM_ExecuteCommand(360);
	return Qnil;
}

static VALUE NWScript_GetAttemptedAttackTarget()
{
	VM_ExecuteCommand(361);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetTypeFromTalent(VALUE self, VALUE tTalent)
{
	//ERROR: Undefined variable type: talent
	VM_ExecuteCommand(362);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetIdFromTalent(VALUE self, VALUE tTalent)
{
	//ERROR: Undefined variable type: talent
	VM_ExecuteCommand(363);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetAssociate(VALUE self, VALUE nAssociateType, VALUE oMaster, VALUE nTh)
{
	StackPushInteger(NUM2INT(nTh));
	StackPushObject(NUM2UINT(oMaster));
	StackPushInteger(NUM2INT(nAssociateType));
	VM_ExecuteCommand(364);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_AddHenchman(VALUE self, VALUE oMaster, VALUE oHenchman)
{
	StackPushObject(NUM2UINT(oHenchman));
	StackPushObject(NUM2UINT(oMaster));
	VM_ExecuteCommand(365);
	return Qnil;
}

static VALUE NWScript_RemoveHenchman(VALUE self, VALUE oMaster, VALUE oHenchman)
{
	StackPushObject(NUM2UINT(oHenchman));
	StackPushObject(NUM2UINT(oMaster));
	VM_ExecuteCommand(366);
	return Qnil;
}

static VALUE NWScript_AddJournalQuestEntry(VALUE self, VALUE szPlotID, VALUE nState, VALUE oCreature, VALUE bAllPartyMembers, VALUE bAllPlayers, VALUE bAllowOverrideHigher)
{
	StackPushInteger(NUM2INT(bAllowOverrideHigher));
	StackPushInteger(NUM2INT(bAllPlayers));
	StackPushInteger(NUM2INT(bAllPartyMembers));
	StackPushObject(NUM2UINT(oCreature));
	StackPushInteger(NUM2INT(nState));
	StackPushString(rb_str2cstr(szPlotID, NULL));
	VM_ExecuteCommand(367);
	return Qnil;
}

static VALUE NWScript_RemoveJournalQuestEntry(VALUE self, VALUE szPlotID, VALUE oCreature, VALUE bAllPartyMembers, VALUE bAllPlayers)
{
	StackPushInteger(NUM2INT(bAllPlayers));
	StackPushInteger(NUM2INT(bAllPartyMembers));
	StackPushObject(NUM2UINT(oCreature));
	StackPushString(rb_str2cstr(szPlotID, NULL));
	VM_ExecuteCommand(368);
	return Qnil;
}

static VALUE NWScript_GetPCPublicCDKey(VALUE self, VALUE oPlayer, VALUE nSinglePlayerCDKey)
{
	StackPushInteger(NUM2INT(nSinglePlayerCDKey));
	StackPushObject(NUM2UINT(oPlayer));
	VM_ExecuteCommand(369);
	char *sRetVal;
	StackPopString(sRetVal);
	return rb_str_new2(sRetVal);
}

static VALUE NWScript_GetPCIPAddress(VALUE self, VALUE oPlayer)
{
	StackPushObject(NUM2UINT(oPlayer));
	VM_ExecuteCommand(370);
	char *sRetVal;
	StackPopString(sRetVal);
	return rb_str_new2(sRetVal);
}

static VALUE NWScript_GetPCPlayerName(VALUE self, VALUE oPlayer)
{
	StackPushObject(NUM2UINT(oPlayer));
	VM_ExecuteCommand(371);
	char *sRetVal;
	StackPopString(sRetVal);
	return rb_str_new2(sRetVal);
}

static VALUE NWScript_SetPCLike(VALUE self, VALUE oPlayer, VALUE oTarget)
{
	StackPushObject(NUM2UINT(oTarget));
	StackPushObject(NUM2UINT(oPlayer));
	VM_ExecuteCommand(372);
	return Qnil;
}

static VALUE NWScript_SetPCDislike(VALUE self, VALUE oPlayer, VALUE oTarget)
{
	StackPushObject(NUM2UINT(oTarget));
	StackPushObject(NUM2UINT(oPlayer));
	VM_ExecuteCommand(373);
	return Qnil;
}

static VALUE NWScript_SendMessageToPC(VALUE self, VALUE oPlayer, VALUE szMessage)
{
	StackPushString(rb_str2cstr(szMessage, NULL));
	StackPushObject(NUM2UINT(oPlayer));
	VM_ExecuteCommand(374);
	return Qnil;
}

static VALUE NWScript_GetAttemptedSpellTarget()
{
	VM_ExecuteCommand(375);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastOpenedBy()
{
	VM_ExecuteCommand(376);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetHasSpell(VALUE self, VALUE nSpell, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	StackPushInteger(NUM2INT(nSpell));
	VM_ExecuteCommand(377);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_OpenStore(VALUE self, VALUE oStore, VALUE oPC, VALUE nBonusMarkUp, VALUE nBonusMarkDown)
{
	StackPushInteger(NUM2INT(nBonusMarkDown));
	StackPushInteger(NUM2INT(nBonusMarkUp));
	StackPushObject(NUM2UINT(oPC));
	StackPushObject(NUM2UINT(oStore));
	VM_ExecuteCommand(378);
	return Qnil;
}

static VALUE NWScript_EffectTurned()
{
	VM_ExecuteCommand(379);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_GetFirstFactionMember(VALUE self, VALUE oMemberOfFaction, VALUE bPCOnly)
{
	StackPushInteger(NUM2INT(bPCOnly));
	StackPushObject(NUM2UINT(oMemberOfFaction));
	VM_ExecuteCommand(380);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetNextFactionMember(VALUE self, VALUE oMemberOfFaction, VALUE bPCOnly)
{
	StackPushInteger(NUM2INT(bPCOnly));
	StackPushObject(NUM2UINT(oMemberOfFaction));
	VM_ExecuteCommand(381);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_ActionForceMoveToLocation(VALUE self, VALUE lDestination, VALUE bRun, VALUE fTimeout)
{
	StackPushFloat(NUM2DBL(fTimeout));
	StackPushInteger(NUM2INT(bRun));
	//ERROR: Undefined variable type: location
	VM_ExecuteCommand(382);
	return Qnil;
}

static VALUE NWScript_ActionForceMoveToObject(VALUE self, VALUE oMoveTo, VALUE bRun, VALUE fRange, VALUE fTimeout)
{
	StackPushFloat(NUM2DBL(fTimeout));
	StackPushFloat(NUM2DBL(fRange));
	StackPushInteger(NUM2INT(bRun));
	StackPushObject(NUM2UINT(oMoveTo));
	VM_ExecuteCommand(383);
	return Qnil;
}

static VALUE NWScript_GetJournalQuestExperience(VALUE self, VALUE szPlotID)
{
	StackPushString(rb_str2cstr(szPlotID, NULL));
	VM_ExecuteCommand(384);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_JumpToObject(VALUE self, VALUE oToJumpTo, VALUE nWalkStraightLineToPoint)
{
	StackPushInteger(NUM2INT(nWalkStraightLineToPoint));
	StackPushObject(NUM2UINT(oToJumpTo));
	VM_ExecuteCommand(385);
	return Qnil;
}

static VALUE NWScript_SetMapPinEnabled(VALUE self, VALUE oMapPin, VALUE nEnabled)
{
	StackPushInteger(NUM2INT(nEnabled));
	StackPushObject(NUM2UINT(oMapPin));
	VM_ExecuteCommand(386);
	return Qnil;
}

static VALUE NWScript_EffectHitPointChangeWhenDying(VALUE self, VALUE fHitPointChangePerRound)
{
	StackPushFloat(NUM2DBL(fHitPointChangePerRound));
	VM_ExecuteCommand(387);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_PopUpGUIPanel(VALUE self, VALUE oPC, VALUE nGUIPanel)
{
	StackPushInteger(NUM2INT(nGUIPanel));
	StackPushObject(NUM2UINT(oPC));
	VM_ExecuteCommand(388);
	return Qnil;
}

static VALUE NWScript_ClearPersonalReputation(VALUE self, VALUE oTarget, VALUE oSource)
{
	StackPushObject(NUM2UINT(oSource));
	StackPushObject(NUM2UINT(oTarget));
	VM_ExecuteCommand(389);
	return Qnil;
}

static VALUE NWScript_SetIsTemporaryFriend(VALUE self, VALUE oTarget, VALUE oSource, VALUE bDecays, VALUE fDurationInSeconds)
{
	StackPushFloat(NUM2DBL(fDurationInSeconds));
	StackPushInteger(NUM2INT(bDecays));
	StackPushObject(NUM2UINT(oSource));
	StackPushObject(NUM2UINT(oTarget));
	VM_ExecuteCommand(390);
	return Qnil;
}

static VALUE NWScript_SetIsTemporaryEnemy(VALUE self, VALUE oTarget, VALUE oSource, VALUE bDecays, VALUE fDurationInSeconds)
{
	StackPushFloat(NUM2DBL(fDurationInSeconds));
	StackPushInteger(NUM2INT(bDecays));
	StackPushObject(NUM2UINT(oSource));
	StackPushObject(NUM2UINT(oTarget));
	VM_ExecuteCommand(391);
	return Qnil;
}

static VALUE NWScript_SetIsTemporaryNeutral(VALUE self, VALUE oTarget, VALUE oSource, VALUE bDecays, VALUE fDurationInSeconds)
{
	StackPushFloat(NUM2DBL(fDurationInSeconds));
	StackPushInteger(NUM2INT(bDecays));
	StackPushObject(NUM2UINT(oSource));
	StackPushObject(NUM2UINT(oTarget));
	VM_ExecuteCommand(392);
	return Qnil;
}

static VALUE NWScript_GiveXPToCreature(VALUE self, VALUE oCreature, VALUE nXpAmount)
{
	StackPushInteger(NUM2INT(nXpAmount));
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(393);
	return Qnil;
}

static VALUE NWScript_SetXP(VALUE self, VALUE oCreature, VALUE nXpAmount)
{
	StackPushInteger(NUM2INT(nXpAmount));
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(394);
	return Qnil;
}

static VALUE NWScript_GetXP(VALUE self, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(395);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_IntToHexString(VALUE self, VALUE nInteger)
{
	StackPushInteger(NUM2INT(nInteger));
	VM_ExecuteCommand(396);
	char *sRetVal;
	StackPopString(sRetVal);
	return rb_str_new2(sRetVal);
}

static VALUE NWScript_GetBaseItemType(VALUE self, VALUE oItem)
{
	StackPushObject(NUM2UINT(oItem));
	VM_ExecuteCommand(397);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetItemHasItemProperty(VALUE self, VALUE oItem, VALUE nProperty)
{
	StackPushInteger(NUM2INT(nProperty));
	StackPushObject(NUM2UINT(oItem));
	VM_ExecuteCommand(398);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_ActionEquipMostDamagingMelee(VALUE self, VALUE oVersus, VALUE bOffHand)
{
	StackPushInteger(NUM2INT(bOffHand));
	StackPushObject(NUM2UINT(oVersus));
	VM_ExecuteCommand(399);
	return Qnil;
}

static VALUE NWScript_ActionEquipMostDamagingRanged(VALUE self, VALUE oVersus)
{
	StackPushObject(NUM2UINT(oVersus));
	VM_ExecuteCommand(400);
	return Qnil;
}

static VALUE NWScript_GetItemACValue(VALUE self, VALUE oItem)
{
	StackPushObject(NUM2UINT(oItem));
	VM_ExecuteCommand(401);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_ActionRest(VALUE self, VALUE bCreatureToEnemyLineOfSightCheck)
{
	StackPushInteger(NUM2INT(bCreatureToEnemyLineOfSightCheck));
	VM_ExecuteCommand(402);
	return Qnil;
}

static VALUE NWScript_ExploreAreaForPlayer(VALUE self, VALUE oArea, VALUE oPlayer, VALUE bExplored)
{
	StackPushInteger(NUM2INT(bExplored));
	StackPushObject(NUM2UINT(oPlayer));
	StackPushObject(NUM2UINT(oArea));
	VM_ExecuteCommand(403);
	return Qnil;
}

static VALUE NWScript_ActionEquipMostEffectiveArmor()
{
	VM_ExecuteCommand(404);
	return Qnil;
}

static VALUE NWScript_GetIsDay()
{
	VM_ExecuteCommand(405);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetIsNight()
{
	VM_ExecuteCommand(406);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetIsDawn()
{
	VM_ExecuteCommand(407);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetIsDusk()
{
	VM_ExecuteCommand(408);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetIsEncounterCreature(VALUE self, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(409);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastPlayerDying()
{
	VM_ExecuteCommand(410);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetStartingLocation()
{
	VM_ExecuteCommand(411);
//ERROR: Undefined variable type: location
}

static VALUE NWScript_ChangeToStandardFaction(VALUE self, VALUE oCreatureToChange, VALUE nStandardFaction)
{
	StackPushInteger(NUM2INT(nStandardFaction));
	StackPushObject(NUM2UINT(oCreatureToChange));
	VM_ExecuteCommand(412);
	return Qnil;
}

static VALUE NWScript_SoundObjectPlay(VALUE self, VALUE oSound)
{
	StackPushObject(NUM2UINT(oSound));
	VM_ExecuteCommand(413);
	return Qnil;
}

static VALUE NWScript_SoundObjectStop(VALUE self, VALUE oSound)
{
	StackPushObject(NUM2UINT(oSound));
	VM_ExecuteCommand(414);
	return Qnil;
}

static VALUE NWScript_SoundObjectSetVolume(VALUE self, VALUE oSound, VALUE nVolume)
{
	StackPushInteger(NUM2INT(nVolume));
	StackPushObject(NUM2UINT(oSound));
	VM_ExecuteCommand(415);
	return Qnil;
}

static VALUE NWScript_SoundObjectSetPosition(VALUE self, VALUE oSound, VALUE vPosition)
{
	//ERROR: Undefined variable type: vector
	StackPushObject(NUM2UINT(oSound));
	VM_ExecuteCommand(416);
	return Qnil;
}

static VALUE NWScript_SpeakOneLinerConversation(VALUE self, VALUE sDialogResRef, VALUE oTokenTarget)
{
	StackPushObject(NUM2UINT(oTokenTarget));
	StackPushString(rb_str2cstr(sDialogResRef, NULL));
	VM_ExecuteCommand(417);
	return Qnil;
}

static VALUE NWScript_GetGold(VALUE self, VALUE oTarget)
{
	StackPushObject(NUM2UINT(oTarget));
	VM_ExecuteCommand(418);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastRespawnButtonPresser()
{
	VM_ExecuteCommand(419);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetIsDM(VALUE self, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(420);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_PlayVoiceChat(VALUE self, VALUE nVoiceChatID, VALUE oTarget)
{
	StackPushObject(NUM2UINT(oTarget));
	StackPushInteger(NUM2INT(nVoiceChatID));
	VM_ExecuteCommand(421);
	return Qnil;
}

static VALUE NWScript_GetIsWeaponEffective(VALUE self, VALUE oVersus, VALUE bOffHand)
{
	StackPushInteger(NUM2INT(bOffHand));
	StackPushObject(NUM2UINT(oVersus));
	VM_ExecuteCommand(422);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastSpellHarmful()
{
	VM_ExecuteCommand(423);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_EventActivateItem(VALUE self, VALUE oItem, VALUE lTarget, VALUE oTarget)
{
	StackPushObject(NUM2UINT(oTarget));
	//ERROR: Undefined variable type: location
	StackPushObject(NUM2UINT(oItem));
	VM_ExecuteCommand(424);
//ERROR: Undefined variable type: event
}

static VALUE NWScript_MusicBackgroundPlay(VALUE self, VALUE oArea)
{
	StackPushObject(NUM2UINT(oArea));
	VM_ExecuteCommand(425);
	return Qnil;
}

static VALUE NWScript_MusicBackgroundStop(VALUE self, VALUE oArea)
{
	StackPushObject(NUM2UINT(oArea));
	VM_ExecuteCommand(426);
	return Qnil;
}

static VALUE NWScript_MusicBackgroundSetDelay(VALUE self, VALUE oArea, VALUE nDelay)
{
	StackPushInteger(NUM2INT(nDelay));
	StackPushObject(NUM2UINT(oArea));
	VM_ExecuteCommand(427);
	return Qnil;
}

static VALUE NWScript_MusicBackgroundChangeDay(VALUE self, VALUE oArea, VALUE nTrack)
{
	StackPushInteger(NUM2INT(nTrack));
	StackPushObject(NUM2UINT(oArea));
	VM_ExecuteCommand(428);
	return Qnil;
}

static VALUE NWScript_MusicBackgroundChangeNight(VALUE self, VALUE oArea, VALUE nTrack)
{
	StackPushInteger(NUM2INT(nTrack));
	StackPushObject(NUM2UINT(oArea));
	VM_ExecuteCommand(429);
	return Qnil;
}

static VALUE NWScript_MusicBattlePlay(VALUE self, VALUE oArea)
{
	StackPushObject(NUM2UINT(oArea));
	VM_ExecuteCommand(430);
	return Qnil;
}

static VALUE NWScript_MusicBattleStop(VALUE self, VALUE oArea)
{
	StackPushObject(NUM2UINT(oArea));
	VM_ExecuteCommand(431);
	return Qnil;
}

static VALUE NWScript_MusicBattleChange(VALUE self, VALUE oArea, VALUE nTrack)
{
	StackPushInteger(NUM2INT(nTrack));
	StackPushObject(NUM2UINT(oArea));
	VM_ExecuteCommand(432);
	return Qnil;
}

static VALUE NWScript_AmbientSoundPlay(VALUE self, VALUE oArea)
{
	StackPushObject(NUM2UINT(oArea));
	VM_ExecuteCommand(433);
	return Qnil;
}

static VALUE NWScript_AmbientSoundStop(VALUE self, VALUE oArea)
{
	StackPushObject(NUM2UINT(oArea));
	VM_ExecuteCommand(434);
	return Qnil;
}

static VALUE NWScript_AmbientSoundChangeDay(VALUE self, VALUE oArea, VALUE nTrack)
{
	StackPushInteger(NUM2INT(nTrack));
	StackPushObject(NUM2UINT(oArea));
	VM_ExecuteCommand(435);
	return Qnil;
}

static VALUE NWScript_AmbientSoundChangeNight(VALUE self, VALUE oArea, VALUE nTrack)
{
	StackPushInteger(NUM2INT(nTrack));
	StackPushObject(NUM2UINT(oArea));
	VM_ExecuteCommand(436);
	return Qnil;
}

static VALUE NWScript_GetLastKiller()
{
	VM_ExecuteCommand(437);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetSpellCastItem()
{
	VM_ExecuteCommand(438);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetItemActivated()
{
	VM_ExecuteCommand(439);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetItemActivator()
{
	VM_ExecuteCommand(440);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetItemActivatedTargetLocation()
{
	VM_ExecuteCommand(441);
//ERROR: Undefined variable type: location
}

static VALUE NWScript_GetItemActivatedTarget()
{
	VM_ExecuteCommand(442);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetIsOpen(VALUE self, VALUE oObject)
{
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(443);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_TakeGoldFromCreature(VALUE self, VALUE nAmount, VALUE oCreatureToTakeFrom, VALUE bDestroy)
{
	StackPushInteger(NUM2INT(bDestroy));
	StackPushObject(NUM2UINT(oCreatureToTakeFrom));
	StackPushInteger(NUM2INT(nAmount));
	VM_ExecuteCommand(444);
	return Qnil;
}

static VALUE NWScript_IsInConversation(VALUE self, VALUE oObject)
{
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(445);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_EffectAbilityDecrease(VALUE self, VALUE nAbility, VALUE nModifyBy)
{
	StackPushInteger(NUM2INT(nModifyBy));
	StackPushInteger(NUM2INT(nAbility));
	VM_ExecuteCommand(446);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectAttackDecrease(VALUE self, VALUE nPenalty, VALUE nModifierType)
{
	StackPushInteger(NUM2INT(nModifierType));
	StackPushInteger(NUM2INT(nPenalty));
	VM_ExecuteCommand(447);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectDamageDecrease(VALUE self, VALUE nPenalty, VALUE nDamageType)
{
	StackPushInteger(NUM2INT(nDamageType));
	StackPushInteger(NUM2INT(nPenalty));
	VM_ExecuteCommand(448);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectDamageImmunityDecrease(VALUE self, VALUE nDamageType, VALUE nPercentImmunity)
{
	StackPushInteger(NUM2INT(nPercentImmunity));
	StackPushInteger(NUM2INT(nDamageType));
	VM_ExecuteCommand(449);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectACDecrease(VALUE self, VALUE nValue, VALUE nModifyType, VALUE nDamageType)
{
	StackPushInteger(NUM2INT(nDamageType));
	StackPushInteger(NUM2INT(nModifyType));
	StackPushInteger(NUM2INT(nValue));
	VM_ExecuteCommand(450);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectMovementSpeedDecrease(VALUE self, VALUE nPercentChange)
{
	StackPushInteger(NUM2INT(nPercentChange));
	VM_ExecuteCommand(451);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectSavingThrowDecrease(VALUE self, VALUE nSave, VALUE nValue, VALUE nSaveType)
{
	StackPushInteger(NUM2INT(nSaveType));
	StackPushInteger(NUM2INT(nValue));
	StackPushInteger(NUM2INT(nSave));
	VM_ExecuteCommand(452);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectSkillDecrease(VALUE self, VALUE nSkill, VALUE nValue)
{
	StackPushInteger(NUM2INT(nValue));
	StackPushInteger(NUM2INT(nSkill));
	VM_ExecuteCommand(453);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectSpellResistanceDecrease(VALUE self, VALUE nValue)
{
	StackPushInteger(NUM2INT(nValue));
	VM_ExecuteCommand(454);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_GetPlotFlag(VALUE self, VALUE oTarget)
{
	StackPushObject(NUM2UINT(oTarget));
	VM_ExecuteCommand(455);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_SetPlotFlag(VALUE self, VALUE oTarget, VALUE nPlotFlag)
{
	StackPushInteger(NUM2INT(nPlotFlag));
	StackPushObject(NUM2UINT(oTarget));
	VM_ExecuteCommand(456);
	return Qnil;
}

static VALUE NWScript_EffectInvisibility(VALUE self, VALUE nInvisibilityType)
{
	StackPushInteger(NUM2INT(nInvisibilityType));
	VM_ExecuteCommand(457);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectConcealment(VALUE self, VALUE nPercentage, VALUE nMissType)
{
	StackPushInteger(NUM2INT(nMissType));
	StackPushInteger(NUM2INT(nPercentage));
	VM_ExecuteCommand(458);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectDarkness()
{
	VM_ExecuteCommand(459);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectDispelMagicAll(VALUE self, VALUE nCasterLevel)
{
	StackPushInteger(NUM2INT(nCasterLevel));
	VM_ExecuteCommand(460);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectUltravision()
{
	VM_ExecuteCommand(461);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectNegativeLevel(VALUE self, VALUE nNumLevels, VALUE bHPBonus)
{
	StackPushInteger(NUM2INT(bHPBonus));
	StackPushInteger(NUM2INT(nNumLevels));
	VM_ExecuteCommand(462);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectPolymorph(VALUE self, VALUE nPolymorphSelection, VALUE nLocked)
{
	StackPushInteger(NUM2INT(nLocked));
	StackPushInteger(NUM2INT(nPolymorphSelection));
	VM_ExecuteCommand(463);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectSanctuary(VALUE self, VALUE nDifficultyClass)
{
	StackPushInteger(NUM2INT(nDifficultyClass));
	VM_ExecuteCommand(464);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectTrueSeeing()
{
	VM_ExecuteCommand(465);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectSeeInvisible()
{
	VM_ExecuteCommand(466);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectTimeStop()
{
	VM_ExecuteCommand(467);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectBlindness()
{
	VM_ExecuteCommand(468);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_GetIsReactionTypeFriendly(VALUE self, VALUE oTarget, VALUE oSource)
{
	StackPushObject(NUM2UINT(oSource));
	StackPushObject(NUM2UINT(oTarget));
	VM_ExecuteCommand(469);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetIsReactionTypeNeutral(VALUE self, VALUE oTarget, VALUE oSource)
{
	StackPushObject(NUM2UINT(oSource));
	StackPushObject(NUM2UINT(oTarget));
	VM_ExecuteCommand(470);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetIsReactionTypeHostile(VALUE self, VALUE oTarget, VALUE oSource)
{
	StackPushObject(NUM2UINT(oSource));
	StackPushObject(NUM2UINT(oTarget));
	VM_ExecuteCommand(471);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_EffectSpellLevelAbsorption(VALUE self, VALUE nMaxSpellLevelAbsorbed, VALUE nTotalSpellLevelsAbsorbed, VALUE nSpellSchool)
{
	StackPushInteger(NUM2INT(nSpellSchool));
	StackPushInteger(NUM2INT(nTotalSpellLevelsAbsorbed));
	StackPushInteger(NUM2INT(nMaxSpellLevelAbsorbed));
	VM_ExecuteCommand(472);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectDispelMagicBest(VALUE self, VALUE nCasterLevel)
{
	StackPushInteger(NUM2INT(nCasterLevel));
	VM_ExecuteCommand(473);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_ActivatePortal(VALUE self, VALUE oTarget, VALUE sIPaddress, VALUE sPassword, VALUE sWaypointTag, VALUE bSeemless)
{
	StackPushInteger(NUM2INT(bSeemless));
	StackPushString(rb_str2cstr(sWaypointTag, NULL));
	StackPushString(rb_str2cstr(sPassword, NULL));
	StackPushString(rb_str2cstr(sIPaddress, NULL));
	StackPushObject(NUM2UINT(oTarget));
	VM_ExecuteCommand(474);
	return Qnil;
}

static VALUE NWScript_GetNumStackedItems(VALUE self, VALUE oItem)
{
	StackPushObject(NUM2UINT(oItem));
	VM_ExecuteCommand(475);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_SurrenderToEnemies()
{
	VM_ExecuteCommand(476);
	return Qnil;
}

static VALUE NWScript_EffectMissChance(VALUE self, VALUE nPercentage, VALUE nMissChanceType)
{
	StackPushInteger(NUM2INT(nMissChanceType));
	StackPushInteger(NUM2INT(nPercentage));
	VM_ExecuteCommand(477);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_GetTurnResistanceHD(VALUE self, VALUE oUndead)
{
	StackPushObject(NUM2UINT(oUndead));
	VM_ExecuteCommand(478);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetCreatureSize(VALUE self, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(479);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_EffectDisappearAppear(VALUE self, VALUE lLocation, VALUE nAnimation)
{
	StackPushInteger(NUM2INT(nAnimation));
	//ERROR: Undefined variable type: location
	VM_ExecuteCommand(480);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectDisappear(VALUE self, VALUE nAnimation)
{
	StackPushInteger(NUM2INT(nAnimation));
	VM_ExecuteCommand(481);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectAppear(VALUE self, VALUE nAnimation)
{
	StackPushInteger(NUM2INT(nAnimation));
	VM_ExecuteCommand(482);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_ActionUnlockObject(VALUE self, VALUE oTarget)
{
	StackPushObject(NUM2UINT(oTarget));
	VM_ExecuteCommand(483);
	return Qnil;
}

static VALUE NWScript_ActionLockObject(VALUE self, VALUE oTarget)
{
	StackPushObject(NUM2UINT(oTarget));
	VM_ExecuteCommand(484);
	return Qnil;
}

static VALUE NWScript_EffectModifyAttacks(VALUE self, VALUE nAttacks)
{
	StackPushInteger(NUM2INT(nAttacks));
	VM_ExecuteCommand(485);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_GetLastTrapDetected(VALUE self, VALUE oTarget)
{
	StackPushObject(NUM2UINT(oTarget));
	VM_ExecuteCommand(486);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_EffectDamageShield(VALUE self, VALUE nDamageAmount, VALUE nRandomAmount, VALUE nDamageType)
{
	StackPushInteger(NUM2INT(nDamageType));
	StackPushInteger(NUM2INT(nRandomAmount));
	StackPushInteger(NUM2INT(nDamageAmount));
	VM_ExecuteCommand(487);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_GetNearestTrapToObject(VALUE self, VALUE oTarget, VALUE nTrapDetected)
{
	StackPushInteger(NUM2INT(nTrapDetected));
	StackPushObject(NUM2UINT(oTarget));
	VM_ExecuteCommand(488);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetDeity(VALUE self, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(489);
	char *sRetVal;
	StackPopString(sRetVal);
	return rb_str_new2(sRetVal);
}

static VALUE NWScript_GetSubRace(VALUE self, VALUE oTarget)
{
	StackPushObject(NUM2UINT(oTarget));
	VM_ExecuteCommand(490);
	char *sRetVal;
	StackPopString(sRetVal);
	return rb_str_new2(sRetVal);
}

static VALUE NWScript_GetFortitudeSavingThrow(VALUE self, VALUE oTarget)
{
	StackPushObject(NUM2UINT(oTarget));
	VM_ExecuteCommand(491);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetWillSavingThrow(VALUE self, VALUE oTarget)
{
	StackPushObject(NUM2UINT(oTarget));
	VM_ExecuteCommand(492);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetReflexSavingThrow(VALUE self, VALUE oTarget)
{
	StackPushObject(NUM2UINT(oTarget));
	VM_ExecuteCommand(493);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetChallengeRating(VALUE self, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(494);
	float fRetVal;
	StackPopFloat(&fRetVal);
	return rb_float_new(fRetVal);
}

static VALUE NWScript_GetAge(VALUE self, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(495);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetMovementRate(VALUE self, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(496);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetFamiliarCreatureType(VALUE self, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(497);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetAnimalCompanionCreatureType(VALUE self, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(498);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetFamiliarName(VALUE self, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(499);
	char *sRetVal;
	StackPopString(sRetVal);
	return rb_str_new2(sRetVal);
}

static VALUE NWScript_GetAnimalCompanionName(VALUE self, VALUE oTarget)
{
	StackPushObject(NUM2UINT(oTarget));
	VM_ExecuteCommand(500);
	char *sRetVal;
	StackPopString(sRetVal);
	return rb_str_new2(sRetVal);
}

static VALUE NWScript_ActionCastFakeSpellAtObject(VALUE self, VALUE nSpell, VALUE oTarget, VALUE nProjectilePathType)
{
	StackPushInteger(NUM2INT(nProjectilePathType));
	StackPushObject(NUM2UINT(oTarget));
	StackPushInteger(NUM2INT(nSpell));
	VM_ExecuteCommand(501);
	return Qnil;
}

static VALUE NWScript_ActionCastFakeSpellAtLocation(VALUE self, VALUE nSpell, VALUE lTarget, VALUE nProjectilePathType)
{
	StackPushInteger(NUM2INT(nProjectilePathType));
	//ERROR: Undefined variable type: location
	StackPushInteger(NUM2INT(nSpell));
	VM_ExecuteCommand(502);
	return Qnil;
}

static VALUE NWScript_RemoveSummonedAssociate(VALUE self, VALUE oMaster, VALUE oAssociate)
{
	StackPushObject(NUM2UINT(oAssociate));
	StackPushObject(NUM2UINT(oMaster));
	VM_ExecuteCommand(503);
	return Qnil;
}

static VALUE NWScript_SetCameraMode(VALUE self, VALUE oPlayer, VALUE nCameraMode)
{
	StackPushInteger(NUM2INT(nCameraMode));
	StackPushObject(NUM2UINT(oPlayer));
	VM_ExecuteCommand(504);
	return Qnil;
}

static VALUE NWScript_GetIsResting(VALUE self, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(505);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastPCRested()
{
	VM_ExecuteCommand(506);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_SetWeather(VALUE self, VALUE oTarget, VALUE nWeather)
{
	StackPushInteger(NUM2INT(nWeather));
	StackPushObject(NUM2UINT(oTarget));
	VM_ExecuteCommand(507);
	return Qnil;
}

static VALUE NWScript_GetLastRestEventType()
{
	VM_ExecuteCommand(508);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_StartNewModule(VALUE self, VALUE sModuleName)
{
	StackPushString(rb_str2cstr(sModuleName, NULL));
	VM_ExecuteCommand(509);
	return Qnil;
}

static VALUE NWScript_EffectSwarm(VALUE self, VALUE nLooping, VALUE sCreatureTemplate1, VALUE sCreatureTemplate2, VALUE sCreatureTemplate3, VALUE sCreatureTemplate4)
{
	StackPushString(rb_str2cstr(sCreatureTemplate4, NULL));
	StackPushString(rb_str2cstr(sCreatureTemplate3, NULL));
	StackPushString(rb_str2cstr(sCreatureTemplate2, NULL));
	StackPushString(rb_str2cstr(sCreatureTemplate1, NULL));
	StackPushInteger(NUM2INT(nLooping));
	VM_ExecuteCommand(510);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_GetWeaponRanged(VALUE self, VALUE oItem)
{
	StackPushObject(NUM2UINT(oItem));
	VM_ExecuteCommand(511);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_DoSinglePlayerAutoSave()
{
	VM_ExecuteCommand(512);
	return Qnil;
}

static VALUE NWScript_GetGameDifficulty()
{
	VM_ExecuteCommand(513);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_SetTileMainLightColor(VALUE self, VALUE lTileLocation, VALUE nMainLight1Color, VALUE nMainLight2Color)
{
	StackPushInteger(NUM2INT(nMainLight2Color));
	StackPushInteger(NUM2INT(nMainLight1Color));
	//ERROR: Undefined variable type: location
	VM_ExecuteCommand(514);
	return Qnil;
}

static VALUE NWScript_SetTileSourceLightColor(VALUE self, VALUE lTileLocation, VALUE nSourceLight1Color, VALUE nSourceLight2Color)
{
	StackPushInteger(NUM2INT(nSourceLight2Color));
	StackPushInteger(NUM2INT(nSourceLight1Color));
	//ERROR: Undefined variable type: location
	VM_ExecuteCommand(515);
	return Qnil;
}

static VALUE NWScript_RecomputeStaticLighting(VALUE self, VALUE oArea)
{
	StackPushObject(NUM2UINT(oArea));
	VM_ExecuteCommand(516);
	return Qnil;
}

static VALUE NWScript_GetTileMainLight1Color(VALUE self, VALUE lTile)
{
	//ERROR: Undefined variable type: location
	VM_ExecuteCommand(517);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetTileMainLight2Color(VALUE self, VALUE lTile)
{
	//ERROR: Undefined variable type: location
	VM_ExecuteCommand(518);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetTileSourceLight1Color(VALUE self, VALUE lTile)
{
	//ERROR: Undefined variable type: location
	VM_ExecuteCommand(519);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetTileSourceLight2Color(VALUE self, VALUE lTile)
{
	//ERROR: Undefined variable type: location
	VM_ExecuteCommand(520);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_SetPanelButtonFlash(VALUE self, VALUE oPlayer, VALUE nButton, VALUE nEnableFlash)
{
	StackPushInteger(NUM2INT(nEnableFlash));
	StackPushInteger(NUM2INT(nButton));
	StackPushObject(NUM2UINT(oPlayer));
	VM_ExecuteCommand(521);
	return Qnil;
}

static VALUE NWScript_GetCurrentAction(VALUE self, VALUE oObject)
{
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(522);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_SetStandardFactionReputation(VALUE self, VALUE nStandardFaction, VALUE nNewReputation, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	StackPushInteger(NUM2INT(nNewReputation));
	StackPushInteger(NUM2INT(nStandardFaction));
	VM_ExecuteCommand(523);
	return Qnil;
}

static VALUE NWScript_GetStandardFactionReputation(VALUE self, VALUE nStandardFaction, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	StackPushInteger(NUM2INT(nStandardFaction));
	VM_ExecuteCommand(524);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_FloatingTextStrRefOnCreature(VALUE self, VALUE nStrRefToDisplay, VALUE oCreatureToFloatAbove, VALUE bBroadcastToFaction)
{
	StackPushInteger(NUM2INT(bBroadcastToFaction));
	StackPushObject(NUM2UINT(oCreatureToFloatAbove));
	StackPushInteger(NUM2INT(nStrRefToDisplay));
	VM_ExecuteCommand(525);
	return Qnil;
}

static VALUE NWScript_FloatingTextStringOnCreature(VALUE self, VALUE sStringToDisplay, VALUE oCreatureToFloatAbove, VALUE bBroadcastToFaction)
{
	StackPushInteger(NUM2INT(bBroadcastToFaction));
	StackPushObject(NUM2UINT(oCreatureToFloatAbove));
	StackPushString(rb_str2cstr(sStringToDisplay, NULL));
	VM_ExecuteCommand(526);
	return Qnil;
}

static VALUE NWScript_GetTrapDisarmable(VALUE self, VALUE oTrapObject)
{
	StackPushObject(NUM2UINT(oTrapObject));
	VM_ExecuteCommand(527);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetTrapDetectable(VALUE self, VALUE oTrapObject)
{
	StackPushObject(NUM2UINT(oTrapObject));
	VM_ExecuteCommand(528);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetTrapDetectedBy(VALUE self, VALUE oTrapObject, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	StackPushObject(NUM2UINT(oTrapObject));
	VM_ExecuteCommand(529);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetTrapFlagged(VALUE self, VALUE oTrapObject)
{
	StackPushObject(NUM2UINT(oTrapObject));
	VM_ExecuteCommand(530);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetTrapBaseType(VALUE self, VALUE oTrapObject)
{
	StackPushObject(NUM2UINT(oTrapObject));
	VM_ExecuteCommand(531);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetTrapOneShot(VALUE self, VALUE oTrapObject)
{
	StackPushObject(NUM2UINT(oTrapObject));
	VM_ExecuteCommand(532);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetTrapCreator(VALUE self, VALUE oTrapObject)
{
	StackPushObject(NUM2UINT(oTrapObject));
	VM_ExecuteCommand(533);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetTrapKeyTag(VALUE self, VALUE oTrapObject)
{
	StackPushObject(NUM2UINT(oTrapObject));
	VM_ExecuteCommand(534);
	char *sRetVal;
	StackPopString(sRetVal);
	return rb_str_new2(sRetVal);
}

static VALUE NWScript_GetTrapDisarmDC(VALUE self, VALUE oTrapObject)
{
	StackPushObject(NUM2UINT(oTrapObject));
	VM_ExecuteCommand(535);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetTrapDetectDC(VALUE self, VALUE oTrapObject)
{
	StackPushObject(NUM2UINT(oTrapObject));
	VM_ExecuteCommand(536);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLockKeyRequired(VALUE self, VALUE oObject)
{
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(537);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLockKeyTag(VALUE self, VALUE oObject)
{
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(538);
	char *sRetVal;
	StackPopString(sRetVal);
	return rb_str_new2(sRetVal);
}

static VALUE NWScript_GetLockLockable(VALUE self, VALUE oObject)
{
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(539);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLockUnlockDC(VALUE self, VALUE oObject)
{
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(540);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLockLockDC(VALUE self, VALUE oObject)
{
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(541);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetPCLevellingUp()
{
	VM_ExecuteCommand(542);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetHasFeatEffect(VALUE self, VALUE nFeat, VALUE oObject)
{
	StackPushObject(NUM2UINT(oObject));
	StackPushInteger(NUM2INT(nFeat));
	VM_ExecuteCommand(543);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_SetPlaceableIllumination(VALUE self, VALUE oPlaceable, VALUE bIlluminate)
{
	StackPushInteger(NUM2INT(bIlluminate));
	StackPushObject(NUM2UINT(oPlaceable));
	VM_ExecuteCommand(544);
	return Qnil;
}

static VALUE NWScript_GetPlaceableIllumination(VALUE self, VALUE oPlaceable)
{
	StackPushObject(NUM2UINT(oPlaceable));
	VM_ExecuteCommand(545);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetIsPlaceableObjectActionPossible(VALUE self, VALUE oPlaceable, VALUE nPlaceableAction)
{
	StackPushInteger(NUM2INT(nPlaceableAction));
	StackPushObject(NUM2UINT(oPlaceable));
	VM_ExecuteCommand(546);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_DoPlaceableObjectAction(VALUE self, VALUE oPlaceable, VALUE nPlaceableAction)
{
	StackPushInteger(NUM2INT(nPlaceableAction));
	StackPushObject(NUM2UINT(oPlaceable));
	VM_ExecuteCommand(547);
	return Qnil;
}

static VALUE NWScript_GetFirstPC()
{
	VM_ExecuteCommand(548);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetNextPC()
{
	VM_ExecuteCommand(549);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_SetTrapDetectedBy(VALUE self, VALUE oTrap, VALUE oDetector, VALUE bDetected)
{
	StackPushInteger(NUM2INT(bDetected));
	StackPushObject(NUM2UINT(oDetector));
	StackPushObject(NUM2UINT(oTrap));
	VM_ExecuteCommand(550);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetIsTrapped(VALUE self, VALUE oObject)
{
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(551);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_EffectTurnResistanceDecrease(VALUE self, VALUE nHitDice)
{
	StackPushInteger(NUM2INT(nHitDice));
	VM_ExecuteCommand(552);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectTurnResistanceIncrease(VALUE self, VALUE nHitDice)
{
	StackPushInteger(NUM2INT(nHitDice));
	VM_ExecuteCommand(553);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_PopUpDeathGUIPanel(VALUE self, VALUE oPC, VALUE bRespawnButtonEnabled, VALUE bWaitForHelpButtonEnabled, VALUE nHelpStringReference, VALUE sHelpString)
{
	StackPushString(rb_str2cstr(sHelpString, NULL));
	StackPushInteger(NUM2INT(nHelpStringReference));
	StackPushInteger(NUM2INT(bWaitForHelpButtonEnabled));
	StackPushInteger(NUM2INT(bRespawnButtonEnabled));
	StackPushObject(NUM2UINT(oPC));
	VM_ExecuteCommand(554);
	return Qnil;
}

static VALUE NWScript_SetTrapDisabled(VALUE self, VALUE oTrap)
{
	StackPushObject(NUM2UINT(oTrap));
	VM_ExecuteCommand(555);
	return Qnil;
}

static VALUE NWScript_GetLastHostileActor(VALUE self, VALUE oVictim)
{
	StackPushObject(NUM2UINT(oVictim));
	VM_ExecuteCommand(556);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_ExportAllCharacters()
{
	VM_ExecuteCommand(557);
	return Qnil;
}

static VALUE NWScript_MusicBackgroundGetDayTrack(VALUE self, VALUE oArea)
{
	StackPushObject(NUM2UINT(oArea));
	VM_ExecuteCommand(558);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_MusicBackgroundGetNightTrack(VALUE self, VALUE oArea)
{
	StackPushObject(NUM2UINT(oArea));
	VM_ExecuteCommand(559);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_WriteTimestampedLogEntry(VALUE self, VALUE sLogEntry)
{
	StackPushString(rb_str2cstr(sLogEntry, NULL));
	VM_ExecuteCommand(560);
	return Qnil;
}

static VALUE NWScript_GetModuleName()
{
	VM_ExecuteCommand(561);
	char *sRetVal;
	StackPopString(sRetVal);
	return rb_str_new2(sRetVal);
}

static VALUE NWScript_GetFactionLeader(VALUE self, VALUE oMemberOfFaction)
{
	StackPushObject(NUM2UINT(oMemberOfFaction));
	VM_ExecuteCommand(562);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_SendMessageToAllDMs(VALUE self, VALUE szMessage)
{
	StackPushString(rb_str2cstr(szMessage, NULL));
	VM_ExecuteCommand(563);
	return Qnil;
}

static VALUE NWScript_EndGame(VALUE self, VALUE sEndMovie)
{
	StackPushString(rb_str2cstr(sEndMovie, NULL));
	VM_ExecuteCommand(564);
	return Qnil;
}

static VALUE NWScript_BootPC(VALUE self, VALUE oPlayer)
{
	StackPushObject(NUM2UINT(oPlayer));
	VM_ExecuteCommand(565);
	return Qnil;
}

static VALUE NWScript_ActionCounterSpell(VALUE self, VALUE oCounterSpellTarget)
{
	StackPushObject(NUM2UINT(oCounterSpellTarget));
	VM_ExecuteCommand(566);
	return Qnil;
}

static VALUE NWScript_AmbientSoundSetDayVolume(VALUE self, VALUE oArea, VALUE nVolume)
{
	StackPushInteger(NUM2INT(nVolume));
	StackPushObject(NUM2UINT(oArea));
	VM_ExecuteCommand(567);
	return Qnil;
}

static VALUE NWScript_AmbientSoundSetNightVolume(VALUE self, VALUE oArea, VALUE nVolume)
{
	StackPushInteger(NUM2INT(nVolume));
	StackPushObject(NUM2UINT(oArea));
	VM_ExecuteCommand(568);
	return Qnil;
}

static VALUE NWScript_MusicBackgroundGetBattleTrack(VALUE self, VALUE oArea)
{
	StackPushObject(NUM2UINT(oArea));
	VM_ExecuteCommand(569);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetHasInventory(VALUE self, VALUE oObject)
{
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(570);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetStrRefSoundDuration(VALUE self, VALUE nStrRef)
{
	StackPushInteger(NUM2INT(nStrRef));
	VM_ExecuteCommand(571);
	float fRetVal;
	StackPopFloat(&fRetVal);
	return rb_float_new(fRetVal);
}

static VALUE NWScript_AddToParty(VALUE self, VALUE oPC, VALUE oPartyLeader)
{
	StackPushObject(NUM2UINT(oPartyLeader));
	StackPushObject(NUM2UINT(oPC));
	VM_ExecuteCommand(572);
	return Qnil;
}

static VALUE NWScript_RemoveFromParty(VALUE self, VALUE oPC)
{
	StackPushObject(NUM2UINT(oPC));
	VM_ExecuteCommand(573);
	return Qnil;
}

static VALUE NWScript_GetStealthMode(VALUE self, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(574);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetDetectMode(VALUE self, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(575);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetDefensiveCastingMode(VALUE self, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(576);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetAppearanceType(VALUE self, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(577);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_SpawnScriptDebugger()
{
	VM_ExecuteCommand(578);
	return Qnil;
}

static VALUE NWScript_GetModuleItemAcquiredStackSize()
{
	VM_ExecuteCommand(579);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_DecrementRemainingFeatUses(VALUE self, VALUE oCreature, VALUE nFeat)
{
	StackPushInteger(NUM2INT(nFeat));
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(580);
	return Qnil;
}

static VALUE NWScript_DecrementRemainingSpellUses(VALUE self, VALUE oCreature, VALUE nSpell)
{
	StackPushInteger(NUM2INT(nSpell));
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(581);
	return Qnil;
}

static VALUE NWScript_GetResRef(VALUE self, VALUE oObject)
{
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(582);
	char *sRetVal;
	StackPopString(sRetVal);
	return rb_str_new2(sRetVal);
}

static VALUE NWScript_EffectPetrify()
{
	VM_ExecuteCommand(583);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_CopyItem(VALUE self, VALUE oItem, VALUE oTargetInventory, VALUE bCopyVars)
{
	StackPushInteger(NUM2INT(bCopyVars));
	StackPushObject(NUM2UINT(oTargetInventory));
	StackPushObject(NUM2UINT(oItem));
	VM_ExecuteCommand(584);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_EffectCutsceneParalyze()
{
	VM_ExecuteCommand(585);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_GetDroppableFlag(VALUE self, VALUE oItem)
{
	StackPushObject(NUM2UINT(oItem));
	VM_ExecuteCommand(586);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetUseableFlag(VALUE self, VALUE oObject)
{
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(587);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetStolenFlag(VALUE self, VALUE oStolen)
{
	StackPushObject(NUM2UINT(oStolen));
	VM_ExecuteCommand(588);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_SetCampaignFloat(VALUE self, VALUE sCampaignName, VALUE sVarName, VALUE flFloat, VALUE oPlayer)
{
	StackPushObject(NUM2UINT(oPlayer));
	StackPushFloat(NUM2DBL(flFloat));
	StackPushString(rb_str2cstr(sVarName, NULL));
	StackPushString(rb_str2cstr(sCampaignName, NULL));
	VM_ExecuteCommand(589);
	return Qnil;
}

static VALUE NWScript_SetCampaignInt(VALUE self, VALUE sCampaignName, VALUE sVarName, VALUE nInt, VALUE oPlayer)
{
	StackPushObject(NUM2UINT(oPlayer));
	StackPushInteger(NUM2INT(nInt));
	StackPushString(rb_str2cstr(sVarName, NULL));
	StackPushString(rb_str2cstr(sCampaignName, NULL));
	VM_ExecuteCommand(590);
	return Qnil;
}

static VALUE NWScript_SetCampaignVector(VALUE self, VALUE sCampaignName, VALUE sVarName, VALUE vVector, VALUE oPlayer)
{
	StackPushObject(NUM2UINT(oPlayer));
	//ERROR: Undefined variable type: vector
	StackPushString(rb_str2cstr(sVarName, NULL));
	StackPushString(rb_str2cstr(sCampaignName, NULL));
	VM_ExecuteCommand(591);
	return Qnil;
}

static VALUE NWScript_SetCampaignLocation(VALUE self, VALUE sCampaignName, VALUE sVarName, VALUE locLocation, VALUE oPlayer)
{
	StackPushObject(NUM2UINT(oPlayer));
	//ERROR: Undefined variable type: location
	StackPushString(rb_str2cstr(sVarName, NULL));
	StackPushString(rb_str2cstr(sCampaignName, NULL));
	VM_ExecuteCommand(592);
	return Qnil;
}

static VALUE NWScript_SetCampaignString(VALUE self, VALUE sCampaignName, VALUE sVarName, VALUE sString, VALUE oPlayer)
{
	StackPushObject(NUM2UINT(oPlayer));
	StackPushString(rb_str2cstr(sString, NULL));
	StackPushString(rb_str2cstr(sVarName, NULL));
	StackPushString(rb_str2cstr(sCampaignName, NULL));
	VM_ExecuteCommand(593);
	return Qnil;
}

static VALUE NWScript_DestroyCampaignDatabase(VALUE self, VALUE sCampaignName)
{
	StackPushString(rb_str2cstr(sCampaignName, NULL));
	VM_ExecuteCommand(594);
	return Qnil;
}

static VALUE NWScript_GetCampaignFloat(VALUE self, VALUE sCampaignName, VALUE sVarName, VALUE oPlayer)
{
	StackPushObject(NUM2UINT(oPlayer));
	StackPushString(rb_str2cstr(sVarName, NULL));
	StackPushString(rb_str2cstr(sCampaignName, NULL));
	VM_ExecuteCommand(595);
	float fRetVal;
	StackPopFloat(&fRetVal);
	return rb_float_new(fRetVal);
}

static VALUE NWScript_GetCampaignInt(VALUE self, VALUE sCampaignName, VALUE sVarName, VALUE oPlayer)
{
	StackPushObject(NUM2UINT(oPlayer));
	StackPushString(rb_str2cstr(sVarName, NULL));
	StackPushString(rb_str2cstr(sCampaignName, NULL));
	VM_ExecuteCommand(596);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetCampaignVector(VALUE self, VALUE sCampaignName, VALUE sVarName, VALUE oPlayer)
{
	StackPushObject(NUM2UINT(oPlayer));
	StackPushString(rb_str2cstr(sVarName, NULL));
	StackPushString(rb_str2cstr(sCampaignName, NULL));
	VM_ExecuteCommand(597);
//ERROR: Undefined variable type: vector
}

static VALUE NWScript_GetCampaignLocation(VALUE self, VALUE sCampaignName, VALUE sVarName, VALUE oPlayer)
{
	StackPushObject(NUM2UINT(oPlayer));
	StackPushString(rb_str2cstr(sVarName, NULL));
	StackPushString(rb_str2cstr(sCampaignName, NULL));
	VM_ExecuteCommand(598);
//ERROR: Undefined variable type: location
}

static VALUE NWScript_GetCampaignString(VALUE self, VALUE sCampaignName, VALUE sVarName, VALUE oPlayer)
{
	StackPushObject(NUM2UINT(oPlayer));
	StackPushString(rb_str2cstr(sVarName, NULL));
	StackPushString(rb_str2cstr(sCampaignName, NULL));
	VM_ExecuteCommand(599);
	char *sRetVal;
	StackPopString(sRetVal);
	return rb_str_new2(sRetVal);
}

static VALUE NWScript_CopyObject(VALUE self, VALUE oSource, VALUE locLocation, VALUE oOwner , VALUE sNewTag )
{
	StackPushString(rb_str2cstr(sNewTag , NULL));
	StackPushObject(NUM2UINT(oOwner ));
	//ERROR: Undefined variable type: location
	StackPushObject(NUM2UINT(oSource));
	VM_ExecuteCommand(600);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_DeleteCampaignVariable(VALUE self, VALUE sCampaignName, VALUE sVarName, VALUE oPlayer)
{
	StackPushObject(NUM2UINT(oPlayer));
	StackPushString(rb_str2cstr(sVarName, NULL));
	StackPushString(rb_str2cstr(sCampaignName, NULL));
	VM_ExecuteCommand(601);
	return Qnil;
}

static VALUE NWScript_StoreCampaignObject(VALUE self, VALUE sCampaignName, VALUE sVarName, VALUE oObject, VALUE oPlayer)
{
	StackPushObject(NUM2UINT(oPlayer));
	StackPushObject(NUM2UINT(oObject));
	StackPushString(rb_str2cstr(sVarName, NULL));
	StackPushString(rb_str2cstr(sCampaignName, NULL));
	VM_ExecuteCommand(602);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_RetrieveCampaignObject(VALUE self, VALUE sCampaignName, VALUE sVarName, VALUE locLocation, VALUE oOwner , VALUE oPlayer)
{
	StackPushObject(NUM2UINT(oPlayer));
	StackPushObject(NUM2UINT(oOwner ));
	//ERROR: Undefined variable type: location
	StackPushString(rb_str2cstr(sVarName, NULL));
	StackPushString(rb_str2cstr(sCampaignName, NULL));
	VM_ExecuteCommand(603);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_EffectCutsceneDominated()
{
	VM_ExecuteCommand(604);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_GetItemStackSize(VALUE self, VALUE oItem)
{
	StackPushObject(NUM2UINT(oItem));
	VM_ExecuteCommand(605);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_SetItemStackSize(VALUE self, VALUE oItem, VALUE nSize)
{
	StackPushInteger(NUM2INT(nSize));
	StackPushObject(NUM2UINT(oItem));
	VM_ExecuteCommand(606);
	return Qnil;
}

static VALUE NWScript_GetItemCharges(VALUE self, VALUE oItem)
{
	StackPushObject(NUM2UINT(oItem));
	VM_ExecuteCommand(607);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_SetItemCharges(VALUE self, VALUE oItem, VALUE nCharges)
{
	StackPushInteger(NUM2INT(nCharges));
	StackPushObject(NUM2UINT(oItem));
	VM_ExecuteCommand(608);
	return Qnil;
}

static VALUE NWScript_AddItemProperty(VALUE self, VALUE nDurationType, VALUE ipProperty, VALUE oItem, VALUE fDuration)
{
	StackPushFloat(NUM2DBL(fDuration));
	StackPushObject(NUM2UINT(oItem));
	//ERROR: Undefined variable type: itemproperty
	StackPushInteger(NUM2INT(nDurationType));
	VM_ExecuteCommand(609);
	return Qnil;
}

static VALUE NWScript_RemoveItemProperty(VALUE self, VALUE oItem, VALUE ipProperty)
{
	//ERROR: Undefined variable type: itemproperty
	StackPushObject(NUM2UINT(oItem));
	VM_ExecuteCommand(610);
	return Qnil;
}

static VALUE NWScript_GetIsItemPropertyValid(VALUE self, VALUE ipProperty)
{
	//ERROR: Undefined variable type: itemproperty
	VM_ExecuteCommand(611);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetFirstItemProperty(VALUE self, VALUE oItem)
{
	StackPushObject(NUM2UINT(oItem));
	VM_ExecuteCommand(612);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_GetNextItemProperty(VALUE self, VALUE oItem)
{
	StackPushObject(NUM2UINT(oItem));
	VM_ExecuteCommand(613);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_GetItemPropertyType(VALUE self, VALUE ip)
{
	//ERROR: Undefined variable type: itemproperty
	VM_ExecuteCommand(614);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetItemPropertyDurationType(VALUE self, VALUE ip)
{
	//ERROR: Undefined variable type: itemproperty
	VM_ExecuteCommand(615);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_ItemPropertyAbilityBonus(VALUE self, VALUE nAbility, VALUE nBonus)
{
	StackPushInteger(NUM2INT(nBonus));
	StackPushInteger(NUM2INT(nAbility));
	VM_ExecuteCommand(616);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyACBonus(VALUE self, VALUE nBonus)
{
	StackPushInteger(NUM2INT(nBonus));
	VM_ExecuteCommand(617);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyACBonusVsAlign(VALUE self, VALUE nAlignGroup, VALUE nACBonus)
{
	StackPushInteger(NUM2INT(nACBonus));
	StackPushInteger(NUM2INT(nAlignGroup));
	VM_ExecuteCommand(618);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyACBonusVsDmgType(VALUE self, VALUE nDamageType, VALUE nACBonus)
{
	StackPushInteger(NUM2INT(nACBonus));
	StackPushInteger(NUM2INT(nDamageType));
	VM_ExecuteCommand(619);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyACBonusVsRace(VALUE self, VALUE nRace, VALUE nACBonus)
{
	StackPushInteger(NUM2INT(nACBonus));
	StackPushInteger(NUM2INT(nRace));
	VM_ExecuteCommand(620);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyACBonusVsSAlign(VALUE self, VALUE nAlign, VALUE nACBonus)
{
	StackPushInteger(NUM2INT(nACBonus));
	StackPushInteger(NUM2INT(nAlign));
	VM_ExecuteCommand(621);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyEnhancementBonus(VALUE self, VALUE nEnhancementBonus)
{
	StackPushInteger(NUM2INT(nEnhancementBonus));
	VM_ExecuteCommand(622);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyEnhancementBonusVsAlign(VALUE self, VALUE nAlignGroup, VALUE nBonus)
{
	StackPushInteger(NUM2INT(nBonus));
	StackPushInteger(NUM2INT(nAlignGroup));
	VM_ExecuteCommand(623);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyEnhancementBonusVsRace(VALUE self, VALUE nRace, VALUE nBonus)
{
	StackPushInteger(NUM2INT(nBonus));
	StackPushInteger(NUM2INT(nRace));
	VM_ExecuteCommand(624);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyEnhancementBonusVsSAlign(VALUE self, VALUE nAlign, VALUE nBonus)
{
	StackPushInteger(NUM2INT(nBonus));
	StackPushInteger(NUM2INT(nAlign));
	VM_ExecuteCommand(625);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyEnhancementPenalty(VALUE self, VALUE nPenalty)
{
	StackPushInteger(NUM2INT(nPenalty));
	VM_ExecuteCommand(626);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyWeightReduction(VALUE self, VALUE nReduction)
{
	StackPushInteger(NUM2INT(nReduction));
	VM_ExecuteCommand(627);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyBonusFeat(VALUE self, VALUE nFeat)
{
	StackPushInteger(NUM2INT(nFeat));
	VM_ExecuteCommand(628);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyBonusLevelSpell(VALUE self, VALUE nClass, VALUE nSpellLevel)
{
	StackPushInteger(NUM2INT(nSpellLevel));
	StackPushInteger(NUM2INT(nClass));
	VM_ExecuteCommand(629);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyCastSpell(VALUE self, VALUE nSpell, VALUE nNumUses)
{
	StackPushInteger(NUM2INT(nNumUses));
	StackPushInteger(NUM2INT(nSpell));
	VM_ExecuteCommand(630);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyDamageBonus(VALUE self, VALUE nDamageType, VALUE nDamage)
{
	StackPushInteger(NUM2INT(nDamage));
	StackPushInteger(NUM2INT(nDamageType));
	VM_ExecuteCommand(631);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyDamageBonusVsAlign(VALUE self, VALUE nAlignGroup, VALUE nDamageType, VALUE nDamage)
{
	StackPushInteger(NUM2INT(nDamage));
	StackPushInteger(NUM2INT(nDamageType));
	StackPushInteger(NUM2INT(nAlignGroup));
	VM_ExecuteCommand(632);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyDamageBonusVsRace(VALUE self, VALUE nRace, VALUE nDamageType, VALUE nDamage)
{
	StackPushInteger(NUM2INT(nDamage));
	StackPushInteger(NUM2INT(nDamageType));
	StackPushInteger(NUM2INT(nRace));
	VM_ExecuteCommand(633);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyDamageBonusVsSAlign(VALUE self, VALUE nAlign, VALUE nDamageType, VALUE nDamage)
{
	StackPushInteger(NUM2INT(nDamage));
	StackPushInteger(NUM2INT(nDamageType));
	StackPushInteger(NUM2INT(nAlign));
	VM_ExecuteCommand(634);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyDamageImmunity(VALUE self, VALUE nDamageType, VALUE nImmuneBonus)
{
	StackPushInteger(NUM2INT(nImmuneBonus));
	StackPushInteger(NUM2INT(nDamageType));
	VM_ExecuteCommand(635);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyDamagePenalty(VALUE self, VALUE nPenalty)
{
	StackPushInteger(NUM2INT(nPenalty));
	VM_ExecuteCommand(636);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyDamageReduction(VALUE self, VALUE nEnhancement, VALUE nHPSoak)
{
	StackPushInteger(NUM2INT(nHPSoak));
	StackPushInteger(NUM2INT(nEnhancement));
	VM_ExecuteCommand(637);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyDamageResistance(VALUE self, VALUE nDamageType, VALUE nHPResist)
{
	StackPushInteger(NUM2INT(nHPResist));
	StackPushInteger(NUM2INT(nDamageType));
	VM_ExecuteCommand(638);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyDamageVulnerability(VALUE self, VALUE nDamageType, VALUE nVulnerability)
{
	StackPushInteger(NUM2INT(nVulnerability));
	StackPushInteger(NUM2INT(nDamageType));
	VM_ExecuteCommand(639);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyDarkvision()
{
	VM_ExecuteCommand(640);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyDecreaseAbility(VALUE self, VALUE nAbility, VALUE nModifier)
{
	StackPushInteger(NUM2INT(nModifier));
	StackPushInteger(NUM2INT(nAbility));
	VM_ExecuteCommand(641);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyDecreaseAC(VALUE self, VALUE nModifierType, VALUE nPenalty)
{
	StackPushInteger(NUM2INT(nPenalty));
	StackPushInteger(NUM2INT(nModifierType));
	VM_ExecuteCommand(642);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyDecreaseSkill(VALUE self, VALUE nSkill, VALUE nPenalty)
{
	StackPushInteger(NUM2INT(nPenalty));
	StackPushInteger(NUM2INT(nSkill));
	VM_ExecuteCommand(643);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyContainerReducedWeight(VALUE self, VALUE nContainerType)
{
	StackPushInteger(NUM2INT(nContainerType));
	VM_ExecuteCommand(644);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyExtraMeleeDamageType(VALUE self, VALUE nDamageType)
{
	StackPushInteger(NUM2INT(nDamageType));
	VM_ExecuteCommand(645);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyExtraRangeDamageType(VALUE self, VALUE nDamageType)
{
	StackPushInteger(NUM2INT(nDamageType));
	VM_ExecuteCommand(646);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyHaste()
{
	VM_ExecuteCommand(647);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyHolyAvenger()
{
	VM_ExecuteCommand(648);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyImmunityMisc(VALUE self, VALUE nImmunityType)
{
	StackPushInteger(NUM2INT(nImmunityType));
	VM_ExecuteCommand(649);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyImprovedEvasion()
{
	VM_ExecuteCommand(650);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyBonusSpellResistance(VALUE self, VALUE nBonus)
{
	StackPushInteger(NUM2INT(nBonus));
	VM_ExecuteCommand(651);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyBonusSavingThrowVsX(VALUE self, VALUE nBonusType, VALUE nBonus)
{
	StackPushInteger(NUM2INT(nBonus));
	StackPushInteger(NUM2INT(nBonusType));
	VM_ExecuteCommand(652);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyBonusSavingThrow(VALUE self, VALUE nBaseSaveType, VALUE nBonus)
{
	StackPushInteger(NUM2INT(nBonus));
	StackPushInteger(NUM2INT(nBaseSaveType));
	VM_ExecuteCommand(653);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyKeen()
{
	VM_ExecuteCommand(654);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyLight(VALUE self, VALUE nBrightness, VALUE nColor)
{
	StackPushInteger(NUM2INT(nColor));
	StackPushInteger(NUM2INT(nBrightness));
	VM_ExecuteCommand(655);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyMaxRangeStrengthMod(VALUE self, VALUE nModifier)
{
	StackPushInteger(NUM2INT(nModifier));
	VM_ExecuteCommand(656);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyNoDamage()
{
	VM_ExecuteCommand(657);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyOnHitProps(VALUE self, VALUE nProperty, VALUE nSaveDC, VALUE nSpecial)
{
	StackPushInteger(NUM2INT(nSpecial));
	StackPushInteger(NUM2INT(nSaveDC));
	StackPushInteger(NUM2INT(nProperty));
	VM_ExecuteCommand(658);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyReducedSavingThrowVsX(VALUE self, VALUE nBaseSaveType, VALUE nPenalty)
{
	StackPushInteger(NUM2INT(nPenalty));
	StackPushInteger(NUM2INT(nBaseSaveType));
	VM_ExecuteCommand(659);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyReducedSavingThrow(VALUE self, VALUE nBonusType, VALUE nPenalty)
{
	StackPushInteger(NUM2INT(nPenalty));
	StackPushInteger(NUM2INT(nBonusType));
	VM_ExecuteCommand(660);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyRegeneration(VALUE self, VALUE nRegenAmount)
{
	StackPushInteger(NUM2INT(nRegenAmount));
	VM_ExecuteCommand(661);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertySkillBonus(VALUE self, VALUE nSkill, VALUE nBonus)
{
	StackPushInteger(NUM2INT(nBonus));
	StackPushInteger(NUM2INT(nSkill));
	VM_ExecuteCommand(662);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertySpellImmunitySpecific(VALUE self, VALUE nSpell)
{
	StackPushInteger(NUM2INT(nSpell));
	VM_ExecuteCommand(663);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertySpellImmunitySchool(VALUE self, VALUE nSchool)
{
	StackPushInteger(NUM2INT(nSchool));
	VM_ExecuteCommand(664);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyThievesTools(VALUE self, VALUE nModifier)
{
	StackPushInteger(NUM2INT(nModifier));
	VM_ExecuteCommand(665);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyAttackBonus(VALUE self, VALUE nBonus)
{
	StackPushInteger(NUM2INT(nBonus));
	VM_ExecuteCommand(666);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyAttackBonusVsAlign(VALUE self, VALUE nAlignGroup, VALUE nBonus)
{
	StackPushInteger(NUM2INT(nBonus));
	StackPushInteger(NUM2INT(nAlignGroup));
	VM_ExecuteCommand(667);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyAttackBonusVsRace(VALUE self, VALUE nRace, VALUE nBonus)
{
	StackPushInteger(NUM2INT(nBonus));
	StackPushInteger(NUM2INT(nRace));
	VM_ExecuteCommand(668);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyAttackBonusVsSAlign(VALUE self, VALUE nAlignment, VALUE nBonus)
{
	StackPushInteger(NUM2INT(nBonus));
	StackPushInteger(NUM2INT(nAlignment));
	VM_ExecuteCommand(669);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyAttackPenalty(VALUE self, VALUE nPenalty)
{
	StackPushInteger(NUM2INT(nPenalty));
	VM_ExecuteCommand(670);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyUnlimitedAmmo(VALUE self, VALUE nAmmoDamage)
{
	StackPushInteger(NUM2INT(nAmmoDamage));
	VM_ExecuteCommand(671);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyLimitUseByAlign(VALUE self, VALUE nAlignGroup)
{
	StackPushInteger(NUM2INT(nAlignGroup));
	VM_ExecuteCommand(672);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyLimitUseByClass(VALUE self, VALUE nClass)
{
	StackPushInteger(NUM2INT(nClass));
	VM_ExecuteCommand(673);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyLimitUseByRace(VALUE self, VALUE nRace)
{
	StackPushInteger(NUM2INT(nRace));
	VM_ExecuteCommand(674);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyLimitUseBySAlign(VALUE self, VALUE nAlignment)
{
	StackPushInteger(NUM2INT(nAlignment));
	VM_ExecuteCommand(675);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_BadBadReplaceMeThisDoesNothing()
{
	VM_ExecuteCommand(676);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyVampiricRegeneration(VALUE self, VALUE nRegenAmount)
{
	StackPushInteger(NUM2INT(nRegenAmount));
	VM_ExecuteCommand(677);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyTrap(VALUE self, VALUE nTrapLevel, VALUE nTrapType)
{
	StackPushInteger(NUM2INT(nTrapType));
	StackPushInteger(NUM2INT(nTrapLevel));
	VM_ExecuteCommand(678);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyTrueSeeing()
{
	VM_ExecuteCommand(679);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyOnMonsterHitProperties(VALUE self, VALUE nProperty, VALUE nSpecial)
{
	StackPushInteger(NUM2INT(nSpecial));
	StackPushInteger(NUM2INT(nProperty));
	VM_ExecuteCommand(680);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyTurnResistance(VALUE self, VALUE nModifier)
{
	StackPushInteger(NUM2INT(nModifier));
	VM_ExecuteCommand(681);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyMassiveCritical(VALUE self, VALUE nDamage)
{
	StackPushInteger(NUM2INT(nDamage));
	VM_ExecuteCommand(682);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyFreeAction()
{
	VM_ExecuteCommand(683);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyMonsterDamage(VALUE self, VALUE nDamage)
{
	StackPushInteger(NUM2INT(nDamage));
	VM_ExecuteCommand(684);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyImmunityToSpellLevel(VALUE self, VALUE nLevel)
{
	StackPushInteger(NUM2INT(nLevel));
	VM_ExecuteCommand(685);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertySpecialWalk(VALUE self, VALUE nWalkType)
{
	StackPushInteger(NUM2INT(nWalkType));
	VM_ExecuteCommand(686);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyHealersKit(VALUE self, VALUE nModifier)
{
	StackPushInteger(NUM2INT(nModifier));
	VM_ExecuteCommand(687);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyWeightIncrease(VALUE self, VALUE nWeight)
{
	StackPushInteger(NUM2INT(nWeight));
	VM_ExecuteCommand(688);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_GetIsSkillSuccessful(VALUE self, VALUE oTarget, VALUE nSkill, VALUE nDifficulty)
{
	StackPushInteger(NUM2INT(nDifficulty));
	StackPushInteger(NUM2INT(nSkill));
	StackPushObject(NUM2UINT(oTarget));
	VM_ExecuteCommand(689);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_EffectSpellFailure(VALUE self, VALUE nPercent, VALUE nSpellSchool)
{
	StackPushInteger(NUM2INT(nSpellSchool));
	StackPushInteger(NUM2INT(nPercent));
	VM_ExecuteCommand(690);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_SpeakStringByStrRef(VALUE self, VALUE nStrRef, VALUE nTalkVolume)
{
	StackPushInteger(NUM2INT(nTalkVolume));
	StackPushInteger(NUM2INT(nStrRef));
	VM_ExecuteCommand(691);
	return Qnil;
}

static VALUE NWScript_SetCutsceneMode(VALUE self, VALUE oCreature, VALUE nInCutscene, VALUE nLeftClickingEnabled)
{
	StackPushInteger(NUM2INT(nLeftClickingEnabled));
	StackPushInteger(NUM2INT(nInCutscene));
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(692);
	return Qnil;
}

static VALUE NWScript_GetLastPCToCancelCutscene()
{
	VM_ExecuteCommand(693);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetDialogSoundLength(VALUE self, VALUE nStrRef)
{
	StackPushInteger(NUM2INT(nStrRef));
	VM_ExecuteCommand(694);
	float fRetVal;
	StackPopFloat(&fRetVal);
	return rb_float_new(fRetVal);
}

static VALUE NWScript_FadeFromBlack(VALUE self, VALUE oCreature, VALUE fSpeed)
{
	StackPushFloat(NUM2DBL(fSpeed));
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(695);
	return Qnil;
}

static VALUE NWScript_FadeToBlack(VALUE self, VALUE oCreature, VALUE fSpeed)
{
	StackPushFloat(NUM2DBL(fSpeed));
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(696);
	return Qnil;
}

static VALUE NWScript_StopFade(VALUE self, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(697);
	return Qnil;
}

static VALUE NWScript_BlackScreen(VALUE self, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(698);
	return Qnil;
}

static VALUE NWScript_GetBaseAttackBonus(VALUE self, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(699);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_SetImmortal(VALUE self, VALUE oCreature, VALUE bImmortal)
{
	StackPushInteger(NUM2INT(bImmortal));
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(700);
	return Qnil;
}

static VALUE NWScript_OpenInventory(VALUE self, VALUE oCreature, VALUE oPlayer)
{
	StackPushObject(NUM2UINT(oPlayer));
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(701);
	return Qnil;
}

static VALUE NWScript_StoreCameraFacing()
{
	VM_ExecuteCommand(702);
	return Qnil;
}

static VALUE NWScript_RestoreCameraFacing()
{
	VM_ExecuteCommand(703);
	return Qnil;
}

static VALUE NWScript_LevelUpHenchman(VALUE self, VALUE oCreature, VALUE nClass , VALUE bReadyAllSpells , VALUE nPackage )
{
	StackPushInteger(NUM2INT(nPackage ));
	StackPushInteger(NUM2INT(bReadyAllSpells ));
	StackPushInteger(NUM2INT(nClass ));
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(704);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_SetDroppableFlag(VALUE self, VALUE oItem, VALUE bDroppable)
{
	StackPushInteger(NUM2INT(bDroppable));
	StackPushObject(NUM2UINT(oItem));
	VM_ExecuteCommand(705);
	return Qnil;
}

static VALUE NWScript_GetWeight(VALUE self, VALUE oTarget)
{
	StackPushObject(NUM2UINT(oTarget));
	VM_ExecuteCommand(706);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetModuleItemAcquiredBy()
{
	VM_ExecuteCommand(707);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetImmortal(VALUE self, VALUE oTarget)
{
	StackPushObject(NUM2UINT(oTarget));
	VM_ExecuteCommand(708);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_DoWhirlwindAttack(VALUE self, VALUE bDisplayFeedback, VALUE bImproved)
{
	StackPushInteger(NUM2INT(bImproved));
	StackPushInteger(NUM2INT(bDisplayFeedback));
	VM_ExecuteCommand(709);
	return Qnil;
}

static VALUE NWScript_Get2DAString(VALUE self, VALUE s2DA, VALUE sColumn, VALUE nRow)
{
	StackPushInteger(NUM2INT(nRow));
	StackPushString(rb_str2cstr(sColumn, NULL));
	StackPushString(rb_str2cstr(s2DA, NULL));
	VM_ExecuteCommand(710);
	char *sRetVal;
	StackPopString(sRetVal);
	return rb_str_new2(sRetVal);
}

static VALUE NWScript_EffectEthereal()
{
	VM_ExecuteCommand(711);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_GetAILevel(VALUE self, VALUE oTarget)
{
	StackPushObject(NUM2UINT(oTarget));
	VM_ExecuteCommand(712);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_SetAILevel(VALUE self, VALUE oTarget, VALUE nAILevel)
{
	StackPushInteger(NUM2INT(nAILevel));
	StackPushObject(NUM2UINT(oTarget));
	VM_ExecuteCommand(713);
	return Qnil;
}

static VALUE NWScript_GetIsPossessedFamiliar(VALUE self, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(714);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_UnpossessFamiliar(VALUE self, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(715);
	return Qnil;
}

static VALUE NWScript_GetIsAreaInterior(VALUE self, VALUE oArea )
{
	StackPushObject(NUM2UINT(oArea ));
	VM_ExecuteCommand(716);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_SendMessageToPCByStrRef(VALUE self, VALUE oPlayer, VALUE nStrRef)
{
	StackPushInteger(NUM2INT(nStrRef));
	StackPushObject(NUM2UINT(oPlayer));
	VM_ExecuteCommand(717);
	return Qnil;
}

static VALUE NWScript_IncrementRemainingFeatUses(VALUE self, VALUE oCreature, VALUE nFeat)
{
	StackPushInteger(NUM2INT(nFeat));
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(718);
	return Qnil;
}

static VALUE NWScript_ExportSingleCharacter(VALUE self, VALUE oPlayer)
{
	StackPushObject(NUM2UINT(oPlayer));
	VM_ExecuteCommand(719);
	return Qnil;
}

static VALUE NWScript_PlaySoundByStrRef(VALUE self, VALUE nStrRef, VALUE nRunAsAction )
{
	StackPushInteger(NUM2INT(nRunAsAction ));
	StackPushInteger(NUM2INT(nStrRef));
	VM_ExecuteCommand(720);
	return Qnil;
}

static VALUE NWScript_SetSubRace(VALUE self, VALUE oCreature, VALUE sSubRace)
{
	StackPushString(rb_str2cstr(sSubRace, NULL));
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(721);
	return Qnil;
}

static VALUE NWScript_SetDeity(VALUE self, VALUE oCreature, VALUE sDeity)
{
	StackPushString(rb_str2cstr(sDeity, NULL));
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(722);
	return Qnil;
}

static VALUE NWScript_GetIsDMPossessed(VALUE self, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(723);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetWeather(VALUE self, VALUE oArea)
{
	StackPushObject(NUM2UINT(oArea));
	VM_ExecuteCommand(724);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetIsAreaNatural(VALUE self, VALUE oArea)
{
	StackPushObject(NUM2UINT(oArea));
	VM_ExecuteCommand(725);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetIsAreaAboveGround(VALUE self, VALUE oArea)
{
	StackPushObject(NUM2UINT(oArea));
	VM_ExecuteCommand(726);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetPCItemLastEquipped()
{
	VM_ExecuteCommand(727);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetPCItemLastEquippedBy()
{
	VM_ExecuteCommand(728);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetPCItemLastUnequipped()
{
	VM_ExecuteCommand(729);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetPCItemLastUnequippedBy()
{
	VM_ExecuteCommand(730);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_CopyItemAndModify(VALUE self, VALUE oItem, VALUE nType, VALUE nIndex, VALUE nNewValue, VALUE bCopyVars)
{
	StackPushInteger(NUM2INT(bCopyVars));
	StackPushInteger(NUM2INT(nNewValue));
	StackPushInteger(NUM2INT(nIndex));
	StackPushInteger(NUM2INT(nType));
	StackPushObject(NUM2UINT(oItem));
	VM_ExecuteCommand(731);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetItemAppearance(VALUE self, VALUE oItem, VALUE nType, VALUE nIndex)
{
	StackPushInteger(NUM2INT(nIndex));
	StackPushInteger(NUM2INT(nType));
	StackPushObject(NUM2UINT(oItem));
	VM_ExecuteCommand(732);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_ItemPropertyOnHitCastSpell(VALUE self, VALUE nSpell, VALUE nLevel)
{
	StackPushInteger(NUM2INT(nLevel));
	StackPushInteger(NUM2INT(nSpell));
	VM_ExecuteCommand(733);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_GetItemPropertySubType(VALUE self, VALUE iProperty)
{
	//ERROR: Undefined variable type: itemproperty
	VM_ExecuteCommand(734);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetActionMode(VALUE self, VALUE oCreature, VALUE nMode)
{
	StackPushInteger(NUM2INT(nMode));
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(735);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_SetActionMode(VALUE self, VALUE oCreature, VALUE nMode, VALUE nStatus)
{
	StackPushInteger(NUM2INT(nStatus));
	StackPushInteger(NUM2INT(nMode));
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(736);
	return Qnil;
}

static VALUE NWScript_GetArcaneSpellFailure(VALUE self, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(737);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_ActionExamine(VALUE self, VALUE oExamine)
{
	StackPushObject(NUM2UINT(oExamine));
	VM_ExecuteCommand(738);
	return Qnil;
}

static VALUE NWScript_ItemPropertyVisualEffect(VALUE self, VALUE nEffect)
{
	StackPushInteger(NUM2INT(nEffect));
	VM_ExecuteCommand(739);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_SetLootable(VALUE self, VALUE oCreature, VALUE bLootable)
{
	StackPushInteger(NUM2INT(bLootable));
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(740);
	return Qnil;
}

static VALUE NWScript_GetLootable(VALUE self, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(741);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetCutsceneCameraMoveRate(VALUE self, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(742);
	float fRetVal;
	StackPopFloat(&fRetVal);
	return rb_float_new(fRetVal);
}

static VALUE NWScript_SetCutsceneCameraMoveRate(VALUE self, VALUE oCreature, VALUE fRate)
{
	StackPushFloat(NUM2DBL(fRate));
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(743);
	return Qnil;
}

static VALUE NWScript_GetItemCursedFlag(VALUE self, VALUE oItem)
{
	StackPushObject(NUM2UINT(oItem));
	VM_ExecuteCommand(744);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_SetItemCursedFlag(VALUE self, VALUE oItem, VALUE nCursed)
{
	StackPushInteger(NUM2INT(nCursed));
	StackPushObject(NUM2UINT(oItem));
	VM_ExecuteCommand(745);
	return Qnil;
}

static VALUE NWScript_SetMaxHenchmen(VALUE self, VALUE nNumHenchmen)
{
	StackPushInteger(NUM2INT(nNumHenchmen));
	VM_ExecuteCommand(746);
	return Qnil;
}

static VALUE NWScript_GetMaxHenchmen()
{
	VM_ExecuteCommand(747);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetAssociateType(VALUE self, VALUE oAssociate)
{
	StackPushObject(NUM2UINT(oAssociate));
	VM_ExecuteCommand(748);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetSpellResistance(VALUE self, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(749);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_DayToNight(VALUE self, VALUE oPlayer, VALUE fTransitionTime)
{
	StackPushFloat(NUM2DBL(fTransitionTime));
	StackPushObject(NUM2UINT(oPlayer));
	VM_ExecuteCommand(750);
	return Qnil;
}

static VALUE NWScript_NightToDay(VALUE self, VALUE oPlayer, VALUE fTransitionTime)
{
	StackPushFloat(NUM2DBL(fTransitionTime));
	StackPushObject(NUM2UINT(oPlayer));
	VM_ExecuteCommand(751);
	return Qnil;
}

static VALUE NWScript_LineOfSightObject(VALUE self, VALUE oSource, VALUE oTarget)
{
	StackPushObject(NUM2UINT(oTarget));
	StackPushObject(NUM2UINT(oSource));
	VM_ExecuteCommand(752);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_LineOfSightVector(VALUE self, VALUE vSource, VALUE vTarget)
{
	//ERROR: Undefined variable type: vector
	//ERROR: Undefined variable type: vector
	VM_ExecuteCommand(753);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastSpellCastClass()
{
	VM_ExecuteCommand(754);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_SetBaseAttackBonus(VALUE self, VALUE nBaseAttackBonus, VALUE oCreature )
{
	StackPushObject(NUM2UINT(oCreature ));
	StackPushInteger(NUM2INT(nBaseAttackBonus));
	VM_ExecuteCommand(755);
	return Qnil;
}

static VALUE NWScript_RestoreBaseAttackBonus(VALUE self, VALUE oCreature )
{
	StackPushObject(NUM2UINT(oCreature ));
	VM_ExecuteCommand(756);
	return Qnil;
}

static VALUE NWScript_EffectCutsceneGhost()
{
	VM_ExecuteCommand(757);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_ItemPropertyArcaneSpellFailure(VALUE self, VALUE nModLevel)
{
	StackPushInteger(NUM2INT(nModLevel));
	VM_ExecuteCommand(758);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_GetStoreGold(VALUE self, VALUE oidStore)
{
	StackPushObject(NUM2UINT(oidStore));
	VM_ExecuteCommand(759);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_SetStoreGold(VALUE self, VALUE oidStore, VALUE nGold)
{
	StackPushInteger(NUM2INT(nGold));
	StackPushObject(NUM2UINT(oidStore));
	VM_ExecuteCommand(760);
	return Qnil;
}

static VALUE NWScript_GetStoreMaxBuyPrice(VALUE self, VALUE oidStore)
{
	StackPushObject(NUM2UINT(oidStore));
	VM_ExecuteCommand(761);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_SetStoreMaxBuyPrice(VALUE self, VALUE oidStore, VALUE nMaxBuy)
{
	StackPushInteger(NUM2INT(nMaxBuy));
	StackPushObject(NUM2UINT(oidStore));
	VM_ExecuteCommand(762);
	return Qnil;
}

static VALUE NWScript_GetStoreIdentifyCost(VALUE self, VALUE oidStore)
{
	StackPushObject(NUM2UINT(oidStore));
	VM_ExecuteCommand(763);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_SetStoreIdentifyCost(VALUE self, VALUE oidStore, VALUE nCost)
{
	StackPushInteger(NUM2INT(nCost));
	StackPushObject(NUM2UINT(oidStore));
	VM_ExecuteCommand(764);
	return Qnil;
}

static VALUE NWScript_SetCreatureAppearanceType(VALUE self, VALUE oCreature, VALUE nAppearanceType)
{
	StackPushInteger(NUM2INT(nAppearanceType));
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(765);
	return Qnil;
}

static VALUE NWScript_GetCreatureStartingPackage(VALUE self, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(766);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_EffectCutsceneImmobilize()
{
	VM_ExecuteCommand(767);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_GetIsInSubArea(VALUE self, VALUE oCreature, VALUE oSubArea)
{
	StackPushObject(NUM2UINT(oSubArea));
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(768);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetItemPropertyCostTable(VALUE self, VALUE iProp)
{
	//ERROR: Undefined variable type: itemproperty
	VM_ExecuteCommand(769);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetItemPropertyCostTableValue(VALUE self, VALUE iProp)
{
	//ERROR: Undefined variable type: itemproperty
	VM_ExecuteCommand(770);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetItemPropertyParam1(VALUE self, VALUE iProp)
{
	//ERROR: Undefined variable type: itemproperty
	VM_ExecuteCommand(771);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetItemPropertyParam1Value(VALUE self, VALUE iProp)
{
	//ERROR: Undefined variable type: itemproperty
	VM_ExecuteCommand(772);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetIsCreatureDisarmable(VALUE self, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(773);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_SetStolenFlag(VALUE self, VALUE oItem, VALUE nStolenFlag)
{
	StackPushInteger(NUM2INT(nStolenFlag));
	StackPushObject(NUM2UINT(oItem));
	VM_ExecuteCommand(774);
	return Qnil;
}

static VALUE NWScript_ForceRest(VALUE self, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(775);
	return Qnil;
}

static VALUE NWScript_SetCameraHeight(VALUE self, VALUE oPlayer, VALUE fHeight)
{
	StackPushFloat(NUM2DBL(fHeight));
	StackPushObject(NUM2UINT(oPlayer));
	VM_ExecuteCommand(776);
	return Qnil;
}

static VALUE NWScript_SetSkyBox(VALUE self, VALUE nSkyBox, VALUE oArea)
{
	StackPushObject(NUM2UINT(oArea));
	StackPushInteger(NUM2INT(nSkyBox));
	VM_ExecuteCommand(777);
	return Qnil;
}

static VALUE NWScript_GetPhenoType(VALUE self, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(778);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_SetPhenoType(VALUE self, VALUE nPhenoType, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	StackPushInteger(NUM2INT(nPhenoType));
	VM_ExecuteCommand(779);
	return Qnil;
}

static VALUE NWScript_SetFogColor(VALUE self, VALUE nFogType, VALUE nFogColor, VALUE oArea)
{
	StackPushObject(NUM2UINT(oArea));
	StackPushInteger(NUM2INT(nFogColor));
	StackPushInteger(NUM2INT(nFogType));
	VM_ExecuteCommand(780);
	return Qnil;
}

static VALUE NWScript_GetCutsceneMode(VALUE self, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(781);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetSkyBox(VALUE self, VALUE oArea)
{
	StackPushObject(NUM2UINT(oArea));
	VM_ExecuteCommand(782);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetFogColor(VALUE self, VALUE nFogType, VALUE oArea)
{
	StackPushObject(NUM2UINT(oArea));
	StackPushInteger(NUM2INT(nFogType));
	VM_ExecuteCommand(783);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_SetFogAmount(VALUE self, VALUE nFogType, VALUE nFogAmount, VALUE oArea)
{
	StackPushObject(NUM2UINT(oArea));
	StackPushInteger(NUM2INT(nFogAmount));
	StackPushInteger(NUM2INT(nFogType));
	VM_ExecuteCommand(784);
	return Qnil;
}

static VALUE NWScript_GetFogAmount(VALUE self, VALUE nFogType, VALUE oArea)
{
	StackPushObject(NUM2UINT(oArea));
	StackPushInteger(NUM2INT(nFogType));
	VM_ExecuteCommand(785);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetPickpocketableFlag(VALUE self, VALUE oItem)
{
	StackPushObject(NUM2UINT(oItem));
	VM_ExecuteCommand(786);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_SetPickpocketableFlag(VALUE self, VALUE oItem, VALUE bPickpocketable)
{
	StackPushInteger(NUM2INT(bPickpocketable));
	StackPushObject(NUM2UINT(oItem));
	VM_ExecuteCommand(787);
	return Qnil;
}

static VALUE NWScript_GetFootstepType(VALUE self, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(788);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_SetFootstepType(VALUE self, VALUE nFootstepType, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	StackPushInteger(NUM2INT(nFootstepType));
	VM_ExecuteCommand(789);
	return Qnil;
}

static VALUE NWScript_GetCreatureWingType(VALUE self, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(790);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_SetCreatureWingType(VALUE self, VALUE nWingType, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	StackPushInteger(NUM2INT(nWingType));
	VM_ExecuteCommand(791);
	return Qnil;
}

static VALUE NWScript_GetCreatureBodyPart(VALUE self, VALUE nPart, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	StackPushInteger(NUM2INT(nPart));
	VM_ExecuteCommand(792);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_SetCreatureBodyPart(VALUE self, VALUE nPart, VALUE nModelNumber, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	StackPushInteger(NUM2INT(nModelNumber));
	StackPushInteger(NUM2INT(nPart));
	VM_ExecuteCommand(793);
	return Qnil;
}

static VALUE NWScript_GetCreatureTailType(VALUE self, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(794);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_SetCreatureTailType(VALUE self, VALUE nTailType, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	StackPushInteger(NUM2INT(nTailType));
	VM_ExecuteCommand(795);
	return Qnil;
}

static VALUE NWScript_GetHardness(VALUE self, VALUE oObject)
{
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(796);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_SetHardness(VALUE self, VALUE nHardness, VALUE oObject)
{
	StackPushObject(NUM2UINT(oObject));
	StackPushInteger(NUM2INT(nHardness));
	VM_ExecuteCommand(797);
	return Qnil;
}

static VALUE NWScript_SetLockKeyRequired(VALUE self, VALUE oObject, VALUE nKeyRequired)
{
	StackPushInteger(NUM2INT(nKeyRequired));
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(798);
	return Qnil;
}

static VALUE NWScript_SetLockKeyTag(VALUE self, VALUE oObject, VALUE sNewKeyTag)
{
	StackPushString(rb_str2cstr(sNewKeyTag, NULL));
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(799);
	return Qnil;
}

static VALUE NWScript_SetLockLockable(VALUE self, VALUE oObject, VALUE nLockable)
{
	StackPushInteger(NUM2INT(nLockable));
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(800);
	return Qnil;
}

static VALUE NWScript_SetLockUnlockDC(VALUE self, VALUE oObject, VALUE nNewUnlockDC)
{
	StackPushInteger(NUM2INT(nNewUnlockDC));
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(801);
	return Qnil;
}

static VALUE NWScript_SetLockLockDC(VALUE self, VALUE oObject, VALUE nNewLockDC)
{
	StackPushInteger(NUM2INT(nNewLockDC));
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(802);
	return Qnil;
}

static VALUE NWScript_SetTrapDisarmable(VALUE self, VALUE oTrapObject, VALUE nDisarmable)
{
	StackPushInteger(NUM2INT(nDisarmable));
	StackPushObject(NUM2UINT(oTrapObject));
	VM_ExecuteCommand(803);
	return Qnil;
}

static VALUE NWScript_SetTrapDetectable(VALUE self, VALUE oTrapObject, VALUE nDetectable)
{
	StackPushInteger(NUM2INT(nDetectable));
	StackPushObject(NUM2UINT(oTrapObject));
	VM_ExecuteCommand(804);
	return Qnil;
}

static VALUE NWScript_SetTrapOneShot(VALUE self, VALUE oTrapObject, VALUE nOneShot)
{
	StackPushInteger(NUM2INT(nOneShot));
	StackPushObject(NUM2UINT(oTrapObject));
	VM_ExecuteCommand(805);
	return Qnil;
}

static VALUE NWScript_SetTrapKeyTag(VALUE self, VALUE oTrapObject, VALUE sKeyTag)
{
	StackPushString(rb_str2cstr(sKeyTag, NULL));
	StackPushObject(NUM2UINT(oTrapObject));
	VM_ExecuteCommand(806);
	return Qnil;
}

static VALUE NWScript_SetTrapDisarmDC(VALUE self, VALUE oTrapObject, VALUE nDisarmDC)
{
	StackPushInteger(NUM2INT(nDisarmDC));
	StackPushObject(NUM2UINT(oTrapObject));
	VM_ExecuteCommand(807);
	return Qnil;
}

static VALUE NWScript_SetTrapDetectDC(VALUE self, VALUE oTrapObject, VALUE nDetectDC)
{
	StackPushInteger(NUM2INT(nDetectDC));
	StackPushObject(NUM2UINT(oTrapObject));
	VM_ExecuteCommand(808);
	return Qnil;
}

static VALUE NWScript_CreateTrapAtLocation(VALUE self, VALUE nTrapType, VALUE lLocation, VALUE fSize, VALUE sTag, VALUE nFaction, VALUE sOnDisarmScript, VALUE sOnTrapTriggeredScript)
{
	StackPushString(rb_str2cstr(sOnTrapTriggeredScript, NULL));
	StackPushString(rb_str2cstr(sOnDisarmScript, NULL));
	StackPushInteger(NUM2INT(nFaction));
	StackPushString(rb_str2cstr(sTag, NULL));
	StackPushFloat(NUM2DBL(fSize));
	//ERROR: Undefined variable type: location
	StackPushInteger(NUM2INT(nTrapType));
	VM_ExecuteCommand(809);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_CreateTrapOnObject(VALUE self, VALUE nTrapType, VALUE oObject, VALUE nFaction, VALUE sOnDisarmScript, VALUE sOnTrapTriggeredScript)
{
	StackPushString(rb_str2cstr(sOnTrapTriggeredScript, NULL));
	StackPushString(rb_str2cstr(sOnDisarmScript, NULL));
	StackPushInteger(NUM2INT(nFaction));
	StackPushObject(NUM2UINT(oObject));
	StackPushInteger(NUM2INT(nTrapType));
	VM_ExecuteCommand(810);
	return Qnil;
}

static VALUE NWScript_SetWillSavingThrow(VALUE self, VALUE oObject, VALUE nWillSave)
{
	StackPushInteger(NUM2INT(nWillSave));
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(811);
	return Qnil;
}

static VALUE NWScript_SetReflexSavingThrow(VALUE self, VALUE oObject, VALUE nReflexSave)
{
	StackPushInteger(NUM2INT(nReflexSave));
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(812);
	return Qnil;
}

static VALUE NWScript_SetFortitudeSavingThrow(VALUE self, VALUE oObject, VALUE nFortitudeSave)
{
	StackPushInteger(NUM2INT(nFortitudeSave));
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(813);
	return Qnil;
}

static VALUE NWScript_GetTilesetResRef(VALUE self, VALUE oArea)
{
	StackPushObject(NUM2UINT(oArea));
	VM_ExecuteCommand(814);
	char *sRetVal;
	StackPopString(sRetVal);
	return rb_str_new2(sRetVal);
}

static VALUE NWScript_GetTrapRecoverable(VALUE self, VALUE oTrapObject)
{
	StackPushObject(NUM2UINT(oTrapObject));
	VM_ExecuteCommand(815);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_SetTrapRecoverable(VALUE self, VALUE oTrapObject, VALUE nRecoverable)
{
	StackPushInteger(NUM2INT(nRecoverable));
	StackPushObject(NUM2UINT(oTrapObject));
	VM_ExecuteCommand(816);
	return Qnil;
}

static VALUE NWScript_GetModuleXPScale()
{
	VM_ExecuteCommand(817);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_SetModuleXPScale(VALUE self, VALUE nXPScale)
{
	StackPushInteger(NUM2INT(nXPScale));
	VM_ExecuteCommand(818);
	return Qnil;
}

static VALUE NWScript_GetKeyRequiredFeedback(VALUE self, VALUE oObject)
{
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(819);
	char *sRetVal;
	StackPopString(sRetVal);
	return rb_str_new2(sRetVal);
}

static VALUE NWScript_SetKeyRequiredFeedback(VALUE self, VALUE oObject, VALUE sFeedbackMessage)
{
	StackPushString(rb_str2cstr(sFeedbackMessage, NULL));
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(820);
	return Qnil;
}

static VALUE NWScript_GetTrapActive(VALUE self, VALUE oTrapObject)
{
	StackPushObject(NUM2UINT(oTrapObject));
	VM_ExecuteCommand(821);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_SetTrapActive(VALUE self, VALUE oTrapObject, VALUE nActive)
{
	StackPushInteger(NUM2INT(nActive));
	StackPushObject(NUM2UINT(oTrapObject));
	VM_ExecuteCommand(822);
	return Qnil;
}

static VALUE NWScript_LockCameraPitch(VALUE self, VALUE oPlayer, VALUE bLocked)
{
	StackPushInteger(NUM2INT(bLocked));
	StackPushObject(NUM2UINT(oPlayer));
	VM_ExecuteCommand(823);
	return Qnil;
}

static VALUE NWScript_LockCameraDistance(VALUE self, VALUE oPlayer, VALUE bLocked)
{
	StackPushInteger(NUM2INT(bLocked));
	StackPushObject(NUM2UINT(oPlayer));
	VM_ExecuteCommand(824);
	return Qnil;
}

static VALUE NWScript_LockCameraDirection(VALUE self, VALUE oPlayer, VALUE bLocked)
{
	StackPushInteger(NUM2INT(bLocked));
	StackPushObject(NUM2UINT(oPlayer));
	VM_ExecuteCommand(825);
	return Qnil;
}

static VALUE NWScript_GetPlaceableLastClickedBy()
{
	VM_ExecuteCommand(826);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetInfiniteFlag(VALUE self, VALUE oItem)
{
	StackPushObject(NUM2UINT(oItem));
	VM_ExecuteCommand(827);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_SetInfiniteFlag(VALUE self, VALUE oItem, VALUE bInfinite)
{
	StackPushInteger(NUM2INT(bInfinite));
	StackPushObject(NUM2UINT(oItem));
	VM_ExecuteCommand(828);
	return Qnil;
}

static VALUE NWScript_GetAreaSize(VALUE self, VALUE nAreaDimension, VALUE oArea)
{
	StackPushObject(NUM2UINT(oArea));
	StackPushInteger(NUM2INT(nAreaDimension));
	VM_ExecuteCommand(829);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_SetName(VALUE self, VALUE oObject, VALUE sNewName)
{
	StackPushString(rb_str2cstr(sNewName, NULL));
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(830);
	return Qnil;
}

static VALUE NWScript_GetPortraitId(VALUE self, VALUE oTarget)
{
	StackPushObject(NUM2UINT(oTarget));
	VM_ExecuteCommand(831);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_SetPortraitId(VALUE self, VALUE oTarget, VALUE nPortraitId)
{
	StackPushInteger(NUM2INT(nPortraitId));
	StackPushObject(NUM2UINT(oTarget));
	VM_ExecuteCommand(832);
	return Qnil;
}

static VALUE NWScript_GetPortraitResRef(VALUE self, VALUE oTarget)
{
	StackPushObject(NUM2UINT(oTarget));
	VM_ExecuteCommand(833);
	char *sRetVal;
	StackPopString(sRetVal);
	return rb_str_new2(sRetVal);
}

static VALUE NWScript_SetPortraitResRef(VALUE self, VALUE oTarget, VALUE sPortraitResRef)
{
	StackPushString(rb_str2cstr(sPortraitResRef, NULL));
	StackPushObject(NUM2UINT(oTarget));
	VM_ExecuteCommand(834);
	return Qnil;
}

static VALUE NWScript_SetUseableFlag(VALUE self, VALUE oPlaceable, VALUE nUseableFlag)
{
	StackPushInteger(NUM2INT(nUseableFlag));
	StackPushObject(NUM2UINT(oPlaceable));
	VM_ExecuteCommand(835);
	return Qnil;
}

static VALUE NWScript_GetDescription(VALUE self, VALUE oObject, VALUE bOriginalDescription, VALUE bIdentifiedDescription)
{
	StackPushInteger(NUM2INT(bIdentifiedDescription));
	StackPushInteger(NUM2INT(bOriginalDescription));
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(836);
	char *sRetVal;
	StackPopString(sRetVal);
	return rb_str_new2(sRetVal);
}

static VALUE NWScript_SetDescription(VALUE self, VALUE oObject, VALUE sNewDescription, VALUE bIdentifiedDescription)
{
	StackPushInteger(NUM2INT(bIdentifiedDescription));
	StackPushString(rb_str2cstr(sNewDescription, NULL));
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(837);
	return Qnil;
}

static VALUE NWScript_GetPCChatSpeaker()
{
	VM_ExecuteCommand(838);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetPCChatMessage()
{
	VM_ExecuteCommand(839);
	char *sRetVal;
	StackPopString(sRetVal);
	return rb_str_new2(sRetVal);
}

static VALUE NWScript_GetPCChatVolume()
{
	VM_ExecuteCommand(840);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_SetPCChatMessage(VALUE self, VALUE sNewChatMessage)
{
	StackPushString(rb_str2cstr(sNewChatMessage, NULL));
	VM_ExecuteCommand(841);
	return Qnil;
}

static VALUE NWScript_SetPCChatVolume(VALUE self, VALUE nTalkVolume)
{
	StackPushInteger(NUM2INT(nTalkVolume));
	VM_ExecuteCommand(842);
	return Qnil;
}

static VALUE NWScript_GetColor(VALUE self, VALUE oObject, VALUE nColorChannel)
{
	StackPushInteger(NUM2INT(nColorChannel));
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(843);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_SetColor(VALUE self, VALUE oObject, VALUE nColorChannel, VALUE nColorValue)
{
	StackPushInteger(NUM2INT(nColorValue));
	StackPushInteger(NUM2INT(nColorChannel));
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(844);
	return Qnil;
}

static VALUE NWScript_ItemPropertyMaterial(VALUE self, VALUE nMaterialType)
{
	StackPushInteger(NUM2INT(nMaterialType));
	VM_ExecuteCommand(845);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyQuality(VALUE self, VALUE nQuality)
{
	StackPushInteger(NUM2INT(nQuality));
	VM_ExecuteCommand(846);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyAdditional(VALUE self, VALUE nAdditionalProperty)
{
	StackPushInteger(NUM2INT(nAdditionalProperty));
	VM_ExecuteCommand(847);
//ERROR: Undefined variable type: itemproperty
}





VALUE RubyInt_InitNWScript()
{
	VALUE cNWScript = rb_define_class("NWScript", rb_cObject);
	rb_define_method(cNWScript, "Random", NWScript_Random, 1);
	rb_define_method(cNWScript, "PrintString", NWScript_PrintString, 1);
	rb_define_method(cNWScript, "PrintFloat", NWScript_PrintFloat, 3);
	rb_define_method(cNWScript, "FloatToString", NWScript_FloatToString, 3);
	rb_define_method(cNWScript, "PrintInteger", NWScript_PrintInteger, 1);
	rb_define_method(cNWScript, "PrintObject", NWScript_PrintObject, 1);
	rb_define_method(cNWScript, "AssignCommand", NWScript_AssignCommand, 2);
	rb_define_method(cNWScript, "DelayCommand", NWScript_DelayCommand, 2);
	rb_define_method(cNWScript, "ExecuteScript", NWScript_ExecuteScript, 2);
	rb_define_method(cNWScript, "ClearAllActions", NWScript_ClearAllActions, 1);
	rb_define_method(cNWScript, "SetFacing", NWScript_SetFacing, 1);
	rb_define_method(cNWScript, "SetCalendar", NWScript_SetCalendar, 3);
	rb_define_method(cNWScript, "SetTime", NWScript_SetTime, 4);
	rb_define_method(cNWScript, "GetCalendarYear", NWScript_GetCalendarYear, 0);
	rb_define_method(cNWScript, "GetCalendarMonth", NWScript_GetCalendarMonth, 0);
	rb_define_method(cNWScript, "GetCalendarDay", NWScript_GetCalendarDay, 0);
	rb_define_method(cNWScript, "GetTimeHour", NWScript_GetTimeHour, 0);
	rb_define_method(cNWScript, "GetTimeMinute", NWScript_GetTimeMinute, 0);
	rb_define_method(cNWScript, "GetTimeSecond", NWScript_GetTimeSecond, 0);
	rb_define_method(cNWScript, "GetTimeMillisecond", NWScript_GetTimeMillisecond, 0);
	rb_define_method(cNWScript, "ActionRandomWalk", NWScript_ActionRandomWalk, 0);
	rb_define_method(cNWScript, "ActionMoveToLocation", NWScript_ActionMoveToLocation, 2);
	rb_define_method(cNWScript, "ActionMoveToObject", NWScript_ActionMoveToObject, 3);
	rb_define_method(cNWScript, "ActionMoveAwayFromObject", NWScript_ActionMoveAwayFromObject, 3);
	rb_define_method(cNWScript, "GetArea", NWScript_GetArea, 1);
	rb_define_method(cNWScript, "GetEnteringObject", NWScript_GetEnteringObject, 0);
	rb_define_method(cNWScript, "GetExitingObject", NWScript_GetExitingObject, 0);
	rb_define_method(cNWScript, "GetPosition", NWScript_GetPosition, 1);
	rb_define_method(cNWScript, "GetFacing", NWScript_GetFacing, 1);
	rb_define_method(cNWScript, "GetItemPossessor", NWScript_GetItemPossessor, 1);
	rb_define_method(cNWScript, "GetItemPossessedBy", NWScript_GetItemPossessedBy, 2);
	rb_define_method(cNWScript, "CreateItemOnObject", NWScript_CreateItemOnObject, 4);
	rb_define_method(cNWScript, "ActionEquipItem", NWScript_ActionEquipItem, 2);
	rb_define_method(cNWScript, "ActionUnequipItem", NWScript_ActionUnequipItem, 1);
	rb_define_method(cNWScript, "ActionPickUpItem", NWScript_ActionPickUpItem, 1);
	rb_define_method(cNWScript, "ActionPutDownItem", NWScript_ActionPutDownItem, 1);
	rb_define_method(cNWScript, "GetLastAttacker", NWScript_GetLastAttacker, 1);
	rb_define_method(cNWScript, "ActionAttack", NWScript_ActionAttack, 2);
	rb_define_method(cNWScript, "GetNearestCreature", NWScript_GetNearestCreature, 8);
	rb_define_method(cNWScript, "ActionSpeakString", NWScript_ActionSpeakString, 2);
	rb_define_method(cNWScript, "ActionPlayAnimation", NWScript_ActionPlayAnimation, 3);
	rb_define_method(cNWScript, "GetDistanceToObject", NWScript_GetDistanceToObject, 1);
	rb_define_method(cNWScript, "GetIsObjectValid", NWScript_GetIsObjectValid, 1);
	rb_define_method(cNWScript, "ActionOpenDoor", NWScript_ActionOpenDoor, 1);
	rb_define_method(cNWScript, "ActionCloseDoor", NWScript_ActionCloseDoor, 1);
	rb_define_method(cNWScript, "SetCameraFacing", NWScript_SetCameraFacing, 4);
	rb_define_method(cNWScript, "PlaySound", NWScript_PlaySound, 1);
	rb_define_method(cNWScript, "GetSpellTargetObject", NWScript_GetSpellTargetObject, 0);
	rb_define_method(cNWScript, "ActionCastSpellAtObject", NWScript_ActionCastSpellAtObject, 7);
	rb_define_method(cNWScript, "GetCurrentHitPoints", NWScript_GetCurrentHitPoints, 1);
	rb_define_method(cNWScript, "GetMaxHitPoints", NWScript_GetMaxHitPoints, 1);
	rb_define_method(cNWScript, "GetLocalInt", NWScript_GetLocalInt, 2);
	rb_define_method(cNWScript, "GetLocalFloat", NWScript_GetLocalFloat, 2);
	rb_define_method(cNWScript, "GetLocalString", NWScript_GetLocalString, 2);
	rb_define_method(cNWScript, "GetLocalObject", NWScript_GetLocalObject, 2);
	rb_define_method(cNWScript, "SetLocalInt", NWScript_SetLocalInt, 3);
	rb_define_method(cNWScript, "SetLocalFloat", NWScript_SetLocalFloat, 3);
	rb_define_method(cNWScript, "SetLocalString", NWScript_SetLocalString, 3);
	rb_define_method(cNWScript, "SetLocalObject", NWScript_SetLocalObject, 3);
	rb_define_method(cNWScript, "GetStringLength", NWScript_GetStringLength, 1);
	rb_define_method(cNWScript, "GetStringUpperCase", NWScript_GetStringUpperCase, 1);
	rb_define_method(cNWScript, "GetStringLowerCase", NWScript_GetStringLowerCase, 1);
	rb_define_method(cNWScript, "GetStringRight", NWScript_GetStringRight, 2);
	rb_define_method(cNWScript, "GetStringLeft", NWScript_GetStringLeft, 2);
	rb_define_method(cNWScript, "InsertString", NWScript_InsertString, 3);
	rb_define_method(cNWScript, "GetSubString", NWScript_GetSubString, 3);
	rb_define_method(cNWScript, "FindSubString", NWScript_FindSubString, 3);
	rb_define_method(cNWScript, "fabs", NWScript_fabs, 1);
	rb_define_method(cNWScript, "cos", NWScript_cos, 1);
	rb_define_method(cNWScript, "sin", NWScript_sin, 1);
	rb_define_method(cNWScript, "tan", NWScript_tan, 1);
	rb_define_method(cNWScript, "acos", NWScript_acos, 1);
	rb_define_method(cNWScript, "asin", NWScript_asin, 1);
	rb_define_method(cNWScript, "atan", NWScript_atan, 1);
	rb_define_method(cNWScript, "log", NWScript_log, 1);
	rb_define_method(cNWScript, "pow", NWScript_pow, 2);
	rb_define_method(cNWScript, "sqrt", NWScript_sqrt, 1);
	rb_define_method(cNWScript, "abs", NWScript_abs, 1);
	rb_define_method(cNWScript, "EffectHeal", NWScript_EffectHeal, 1);
	rb_define_method(cNWScript, "EffectDamage", NWScript_EffectDamage, 3);
	rb_define_method(cNWScript, "EffectAbilityIncrease", NWScript_EffectAbilityIncrease, 2);
	rb_define_method(cNWScript, "EffectDamageResistance", NWScript_EffectDamageResistance, 3);
	rb_define_method(cNWScript, "EffectResurrection", NWScript_EffectResurrection, 0);
	rb_define_method(cNWScript, "EffectSummonCreature", NWScript_EffectSummonCreature, 4);
	rb_define_method(cNWScript, "GetCasterLevel", NWScript_GetCasterLevel, 1);
	rb_define_method(cNWScript, "GetFirstEffect", NWScript_GetFirstEffect, 1);
	rb_define_method(cNWScript, "GetNextEffect", NWScript_GetNextEffect, 1);
	rb_define_method(cNWScript, "RemoveEffect", NWScript_RemoveEffect, 2);
	rb_define_method(cNWScript, "GetIsEffectValid", NWScript_GetIsEffectValid, 1);
	rb_define_method(cNWScript, "GetEffectDurationType", NWScript_GetEffectDurationType, 1);
	rb_define_method(cNWScript, "GetEffectSubType", NWScript_GetEffectSubType, 1);
	rb_define_method(cNWScript, "GetEffectCreator", NWScript_GetEffectCreator, 1);
	rb_define_method(cNWScript, "IntToString", NWScript_IntToString, 1);
	rb_define_method(cNWScript, "GetFirstObjectInArea", NWScript_GetFirstObjectInArea, 1);
	rb_define_method(cNWScript, "GetNextObjectInArea", NWScript_GetNextObjectInArea, 1);
	rb_define_method(cNWScript, "d2", NWScript_d2, 1);
	rb_define_method(cNWScript, "d3", NWScript_d3, 1);
	rb_define_method(cNWScript, "d4", NWScript_d4, 1);
	rb_define_method(cNWScript, "d6", NWScript_d6, 1);
	rb_define_method(cNWScript, "d8", NWScript_d8, 1);
	rb_define_method(cNWScript, "d10", NWScript_d10, 1);
	rb_define_method(cNWScript, "d12", NWScript_d12, 1);
	rb_define_method(cNWScript, "d20", NWScript_d20, 1);
	rb_define_method(cNWScript, "d100", NWScript_d100, 1);
	rb_define_method(cNWScript, "VectorMagnitude", NWScript_VectorMagnitude, 1);
	rb_define_method(cNWScript, "GetMetaMagicFeat", NWScript_GetMetaMagicFeat, 0);
	rb_define_method(cNWScript, "GetObjectType", NWScript_GetObjectType, 1);
	rb_define_method(cNWScript, "GetRacialType", NWScript_GetRacialType, 1);
	rb_define_method(cNWScript, "FortitudeSave", NWScript_FortitudeSave, 4);
	rb_define_method(cNWScript, "ReflexSave", NWScript_ReflexSave, 4);
	rb_define_method(cNWScript, "WillSave", NWScript_WillSave, 4);
	rb_define_method(cNWScript, "GetSpellSaveDC", NWScript_GetSpellSaveDC, 0);
	rb_define_method(cNWScript, "MagicalEffect", NWScript_MagicalEffect, 1);
	rb_define_method(cNWScript, "SupernaturalEffect", NWScript_SupernaturalEffect, 1);
	rb_define_method(cNWScript, "ExtraordinaryEffect", NWScript_ExtraordinaryEffect, 1);
	rb_define_method(cNWScript, "EffectACIncrease", NWScript_EffectACIncrease, 3);
	rb_define_method(cNWScript, "GetAC", NWScript_GetAC, 2);
	rb_define_method(cNWScript, "EffectSavingThrowIncrease", NWScript_EffectSavingThrowIncrease, 3);
	rb_define_method(cNWScript, "EffectAttackIncrease", NWScript_EffectAttackIncrease, 2);
	rb_define_method(cNWScript, "EffectDamageReduction", NWScript_EffectDamageReduction, 3);
	rb_define_method(cNWScript, "EffectDamageIncrease", NWScript_EffectDamageIncrease, 2);
	rb_define_method(cNWScript, "RoundsToSeconds", NWScript_RoundsToSeconds, 1);
	rb_define_method(cNWScript, "HoursToSeconds", NWScript_HoursToSeconds, 1);
	rb_define_method(cNWScript, "TurnsToSeconds", NWScript_TurnsToSeconds, 1);
	rb_define_method(cNWScript, "GetLawChaosValue", NWScript_GetLawChaosValue, 1);
	rb_define_method(cNWScript, "GetGoodEvilValue", NWScript_GetGoodEvilValue, 1);
	rb_define_method(cNWScript, "GetAlignmentLawChaos", NWScript_GetAlignmentLawChaos, 1);
	rb_define_method(cNWScript, "GetAlignmentGoodEvil", NWScript_GetAlignmentGoodEvil, 1);
	rb_define_method(cNWScript, "GetFirstObjectInShape", NWScript_GetFirstObjectInShape, 8);
	rb_define_method(cNWScript, "GetNextObjectInShape", NWScript_GetNextObjectInShape, 8);
	rb_define_method(cNWScript, "EffectEntangle", NWScript_EffectEntangle, 0);
	rb_define_method(cNWScript, "SignalEvent", NWScript_SignalEvent, 2);
	rb_define_method(cNWScript, "EventUserDefined", NWScript_EventUserDefined, 1);
	rb_define_method(cNWScript, "EffectDeath", NWScript_EffectDeath, 2);
	rb_define_method(cNWScript, "EffectKnockdown", NWScript_EffectKnockdown, 0);
	rb_define_method(cNWScript, "ActionGiveItem", NWScript_ActionGiveItem, 2);
	rb_define_method(cNWScript, "ActionTakeItem", NWScript_ActionTakeItem, 2);
	rb_define_method(cNWScript, "VectorNormalize", NWScript_VectorNormalize, 1);
	rb_define_method(cNWScript, "EffectCurse", NWScript_EffectCurse, 6);
	rb_define_method(cNWScript, "GetAbilityScore", NWScript_GetAbilityScore, 3);
	rb_define_method(cNWScript, "GetIsDead", NWScript_GetIsDead, 1);
	rb_define_method(cNWScript, "PrintVector", NWScript_PrintVector, 2);
	rb_define_method(cNWScript, "Vector", NWScript_Vector, 3);
	rb_define_method(cNWScript, "SetFacingPoint", NWScript_SetFacingPoint, 1);
	rb_define_method(cNWScript, "AngleToVector", NWScript_AngleToVector, 1);
	rb_define_method(cNWScript, "VectorToAngle", NWScript_VectorToAngle, 1);
	rb_define_method(cNWScript, "TouchAttackMelee", NWScript_TouchAttackMelee, 2);
	rb_define_method(cNWScript, "TouchAttackRanged", NWScript_TouchAttackRanged, 2);
	rb_define_method(cNWScript, "EffectParalyze", NWScript_EffectParalyze, 0);
	rb_define_method(cNWScript, "EffectSpellImmunity", NWScript_EffectSpellImmunity, 1);
	rb_define_method(cNWScript, "EffectDeaf", NWScript_EffectDeaf, 0);
	rb_define_method(cNWScript, "GetDistanceBetween", NWScript_GetDistanceBetween, 2);
	rb_define_method(cNWScript, "SetLocalLocation", NWScript_SetLocalLocation, 3);
	rb_define_method(cNWScript, "GetLocalLocation", NWScript_GetLocalLocation, 2);
	rb_define_method(cNWScript, "EffectSleep", NWScript_EffectSleep, 0);
	rb_define_method(cNWScript, "GetItemInSlot", NWScript_GetItemInSlot, 2);
	rb_define_method(cNWScript, "EffectCharmed", NWScript_EffectCharmed, 0);
	rb_define_method(cNWScript, "EffectConfused", NWScript_EffectConfused, 0);
	rb_define_method(cNWScript, "EffectFrightened", NWScript_EffectFrightened, 0);
	rb_define_method(cNWScript, "EffectDominated", NWScript_EffectDominated, 0);
	rb_define_method(cNWScript, "EffectDazed", NWScript_EffectDazed, 0);
	rb_define_method(cNWScript, "EffectStunned", NWScript_EffectStunned, 0);
	rb_define_method(cNWScript, "SetCommandable", NWScript_SetCommandable, 2);
	rb_define_method(cNWScript, "GetCommandable", NWScript_GetCommandable, 1);
	rb_define_method(cNWScript, "EffectRegenerate", NWScript_EffectRegenerate, 2);
	rb_define_method(cNWScript, "EffectMovementSpeedIncrease", NWScript_EffectMovementSpeedIncrease, 1);
	rb_define_method(cNWScript, "GetHitDice", NWScript_GetHitDice, 1);
	rb_define_method(cNWScript, "ActionForceFollowObject", NWScript_ActionForceFollowObject, 2);
	rb_define_method(cNWScript, "GetTag", NWScript_GetTag, 1);
	rb_define_method(cNWScript, "ResistSpell", NWScript_ResistSpell, 2);
	rb_define_method(cNWScript, "GetEffectType", NWScript_GetEffectType, 1);
	rb_define_method(cNWScript, "EffectAreaOfEffect", NWScript_EffectAreaOfEffect, 4);
	rb_define_method(cNWScript, "GetFactionEqual", NWScript_GetFactionEqual, 2);
	rb_define_method(cNWScript, "ChangeFaction", NWScript_ChangeFaction, 2);
	rb_define_method(cNWScript, "GetIsListening", NWScript_GetIsListening, 1);
	rb_define_method(cNWScript, "SetListening", NWScript_SetListening, 2);
	rb_define_method(cNWScript, "SetListenPattern", NWScript_SetListenPattern, 3);
	rb_define_method(cNWScript, "TestStringAgainstPattern", NWScript_TestStringAgainstPattern, 2);
	rb_define_method(cNWScript, "GetMatchedSubstring", NWScript_GetMatchedSubstring, 1);
	rb_define_method(cNWScript, "GetMatchedSubstringsCount", NWScript_GetMatchedSubstringsCount, 0);
	rb_define_method(cNWScript, "EffectVisualEffect", NWScript_EffectVisualEffect, 2);
	rb_define_method(cNWScript, "GetFactionWeakestMember", NWScript_GetFactionWeakestMember, 2);
	rb_define_method(cNWScript, "GetFactionStrongestMember", NWScript_GetFactionStrongestMember, 2);
	rb_define_method(cNWScript, "GetFactionMostDamagedMember", NWScript_GetFactionMostDamagedMember, 2);
	rb_define_method(cNWScript, "GetFactionLeastDamagedMember", NWScript_GetFactionLeastDamagedMember, 2);
	rb_define_method(cNWScript, "GetFactionGold", NWScript_GetFactionGold, 1);
	rb_define_method(cNWScript, "GetFactionAverageReputation", NWScript_GetFactionAverageReputation, 2);
	rb_define_method(cNWScript, "GetFactionAverageGoodEvilAlignment", NWScript_GetFactionAverageGoodEvilAlignment, 1);
	rb_define_method(cNWScript, "GetFactionAverageLawChaosAlignment", NWScript_GetFactionAverageLawChaosAlignment, 1);
	rb_define_method(cNWScript, "GetFactionAverageLevel", NWScript_GetFactionAverageLevel, 1);
	rb_define_method(cNWScript, "GetFactionAverageXP", NWScript_GetFactionAverageXP, 1);
	rb_define_method(cNWScript, "GetFactionMostFrequentClass", NWScript_GetFactionMostFrequentClass, 1);
	rb_define_method(cNWScript, "GetFactionWorstAC", NWScript_GetFactionWorstAC, 2);
	rb_define_method(cNWScript, "GetFactionBestAC", NWScript_GetFactionBestAC, 2);
	rb_define_method(cNWScript, "ActionSit", NWScript_ActionSit, 1);
	rb_define_method(cNWScript, "GetListenPatternNumber", NWScript_GetListenPatternNumber, 0);
	rb_define_method(cNWScript, "ActionJumpToObject", NWScript_ActionJumpToObject, 2);
	rb_define_method(cNWScript, "GetWaypointByTag", NWScript_GetWaypointByTag, 1);
	rb_define_method(cNWScript, "GetTransitionTarget", NWScript_GetTransitionTarget, 1);
	rb_define_method(cNWScript, "EffectLinkEffects", NWScript_EffectLinkEffects, 2);
	rb_define_method(cNWScript, "GetObjectByTag", NWScript_GetObjectByTag, 2);
	rb_define_method(cNWScript, "AdjustAlignment", NWScript_AdjustAlignment, 4);
	rb_define_method(cNWScript, "ActionWait", NWScript_ActionWait, 1);
	rb_define_method(cNWScript, "SetAreaTransitionBMP", NWScript_SetAreaTransitionBMP, 2);
	rb_define_method(cNWScript, "ActionStartConversation", NWScript_ActionStartConversation, 4);
	rb_define_method(cNWScript, "ActionPauseConversation", NWScript_ActionPauseConversation, 0);
	rb_define_method(cNWScript, "ActionResumeConversation", NWScript_ActionResumeConversation, 0);
	rb_define_method(cNWScript, "EffectBeam", NWScript_EffectBeam, 4);
	rb_define_method(cNWScript, "GetReputation", NWScript_GetReputation, 2);
	rb_define_method(cNWScript, "AdjustReputation", NWScript_AdjustReputation, 3);
	rb_define_method(cNWScript, "GetSittingCreature", NWScript_GetSittingCreature, 1);
	rb_define_method(cNWScript, "GetGoingToBeAttackedBy", NWScript_GetGoingToBeAttackedBy, 1);
	rb_define_method(cNWScript, "EffectSpellResistanceIncrease", NWScript_EffectSpellResistanceIncrease, 1);
	rb_define_method(cNWScript, "GetLocation", NWScript_GetLocation, 1);
	rb_define_method(cNWScript, "ActionJumpToLocation", NWScript_ActionJumpToLocation, 1);
	rb_define_method(cNWScript, "Location", NWScript_Location, 3);
	rb_define_method(cNWScript, "ApplyEffectAtLocation", NWScript_ApplyEffectAtLocation, 4);
	rb_define_method(cNWScript, "GetIsPC", NWScript_GetIsPC, 1);
	rb_define_method(cNWScript, "FeetToMeters", NWScript_FeetToMeters, 1);
	rb_define_method(cNWScript, "YardsToMeters", NWScript_YardsToMeters, 1);
	rb_define_method(cNWScript, "ApplyEffectToObject", NWScript_ApplyEffectToObject, 4);
	rb_define_method(cNWScript, "SpeakString", NWScript_SpeakString, 2);
	rb_define_method(cNWScript, "GetSpellTargetLocation", NWScript_GetSpellTargetLocation, 0);
	rb_define_method(cNWScript, "GetPositionFromLocation", NWScript_GetPositionFromLocation, 1);
	rb_define_method(cNWScript, "GetAreaFromLocation", NWScript_GetAreaFromLocation, 1);
	rb_define_method(cNWScript, "GetFacingFromLocation", NWScript_GetFacingFromLocation, 1);
	rb_define_method(cNWScript, "GetNearestCreatureToLocation", NWScript_GetNearestCreatureToLocation, 8);
	rb_define_method(cNWScript, "GetNearestObject", NWScript_GetNearestObject, 3);
	rb_define_method(cNWScript, "GetNearestObjectToLocation", NWScript_GetNearestObjectToLocation, 3);
	rb_define_method(cNWScript, "GetNearestObjectByTag", NWScript_GetNearestObjectByTag, 3);
	rb_define_method(cNWScript, "IntToFloat", NWScript_IntToFloat, 1);
	rb_define_method(cNWScript, "FloatToInt", NWScript_FloatToInt, 1);
	rb_define_method(cNWScript, "StringToInt", NWScript_StringToInt, 1);
	rb_define_method(cNWScript, "StringToFloat", NWScript_StringToFloat, 1);
	rb_define_method(cNWScript, "ActionCastSpellAtLocation", NWScript_ActionCastSpellAtLocation, 6);
	rb_define_method(cNWScript, "GetIsEnemy", NWScript_GetIsEnemy, 2);
	rb_define_method(cNWScript, "GetIsFriend", NWScript_GetIsFriend, 2);
	rb_define_method(cNWScript, "GetIsNeutral", NWScript_GetIsNeutral, 2);
	rb_define_method(cNWScript, "GetPCSpeaker", NWScript_GetPCSpeaker, 0);
	rb_define_method(cNWScript, "GetStringByStrRef", NWScript_GetStringByStrRef, 2);
	rb_define_method(cNWScript, "ActionSpeakStringByStrRef", NWScript_ActionSpeakStringByStrRef, 2);
	rb_define_method(cNWScript, "DestroyObject", NWScript_DestroyObject, 2);
	rb_define_method(cNWScript, "GetModule", NWScript_GetModule, 0);
	rb_define_method(cNWScript, "CreateObject", NWScript_CreateObject, 5);
	rb_define_method(cNWScript, "EventSpellCastAt", NWScript_EventSpellCastAt, 3);
	rb_define_method(cNWScript, "GetLastSpellCaster", NWScript_GetLastSpellCaster, 0);
	rb_define_method(cNWScript, "GetLastSpell", NWScript_GetLastSpell, 0);
	rb_define_method(cNWScript, "GetUserDefinedEventNumber", NWScript_GetUserDefinedEventNumber, 0);
	rb_define_method(cNWScript, "GetSpellId", NWScript_GetSpellId, 0);
	rb_define_method(cNWScript, "RandomName", NWScript_RandomName, 1);
	rb_define_method(cNWScript, "EffectPoison", NWScript_EffectPoison, 1);
	rb_define_method(cNWScript, "EffectDisease", NWScript_EffectDisease, 1);
	rb_define_method(cNWScript, "EffectSilence", NWScript_EffectSilence, 0);
	rb_define_method(cNWScript, "GetName", NWScript_GetName, 2);
	rb_define_method(cNWScript, "GetLastSpeaker", NWScript_GetLastSpeaker, 0);
	rb_define_method(cNWScript, "BeginConversation", NWScript_BeginConversation, 2);
	rb_define_method(cNWScript, "GetLastPerceived", NWScript_GetLastPerceived, 0);
	rb_define_method(cNWScript, "GetLastPerceptionHeard", NWScript_GetLastPerceptionHeard, 0);
	rb_define_method(cNWScript, "GetLastPerceptionInaudible", NWScript_GetLastPerceptionInaudible, 0);
	rb_define_method(cNWScript, "GetLastPerceptionSeen", NWScript_GetLastPerceptionSeen, 0);
	rb_define_method(cNWScript, "GetLastClosedBy", NWScript_GetLastClosedBy, 0);
	rb_define_method(cNWScript, "GetLastPerceptionVanished", NWScript_GetLastPerceptionVanished, 0);
	rb_define_method(cNWScript, "GetFirstInPersistentObject", NWScript_GetFirstInPersistentObject, 3);
	rb_define_method(cNWScript, "GetNextInPersistentObject", NWScript_GetNextInPersistentObject, 3);
	rb_define_method(cNWScript, "GetAreaOfEffectCreator", NWScript_GetAreaOfEffectCreator, 1);
	rb_define_method(cNWScript, "DeleteLocalInt", NWScript_DeleteLocalInt, 2);
	rb_define_method(cNWScript, "DeleteLocalFloat", NWScript_DeleteLocalFloat, 2);
	rb_define_method(cNWScript, "DeleteLocalString", NWScript_DeleteLocalString, 2);
	rb_define_method(cNWScript, "DeleteLocalObject", NWScript_DeleteLocalObject, 2);
	rb_define_method(cNWScript, "DeleteLocalLocation", NWScript_DeleteLocalLocation, 2);
	rb_define_method(cNWScript, "EffectHaste", NWScript_EffectHaste, 0);
	rb_define_method(cNWScript, "EffectSlow", NWScript_EffectSlow, 0);
	rb_define_method(cNWScript, "ObjectToString", NWScript_ObjectToString, 1);
	rb_define_method(cNWScript, "EffectImmunity", NWScript_EffectImmunity, 1);
	rb_define_method(cNWScript, "GetIsImmune", NWScript_GetIsImmune, 3);
	rb_define_method(cNWScript, "EffectDamageImmunityIncrease", NWScript_EffectDamageImmunityIncrease, 2);
	rb_define_method(cNWScript, "GetEncounterActive", NWScript_GetEncounterActive, 1);
	rb_define_method(cNWScript, "SetEncounterActive", NWScript_SetEncounterActive, 2);
	rb_define_method(cNWScript, "GetEncounterSpawnsMax", NWScript_GetEncounterSpawnsMax, 1);
	rb_define_method(cNWScript, "SetEncounterSpawnsMax", NWScript_SetEncounterSpawnsMax, 2);
	rb_define_method(cNWScript, "GetEncounterSpawnsCurrent", NWScript_GetEncounterSpawnsCurrent, 1);
	rb_define_method(cNWScript, "SetEncounterSpawnsCurrent", NWScript_SetEncounterSpawnsCurrent, 2);
	rb_define_method(cNWScript, "GetModuleItemAcquired", NWScript_GetModuleItemAcquired, 0);
	rb_define_method(cNWScript, "GetModuleItemAcquiredFrom", NWScript_GetModuleItemAcquiredFrom, 0);
	rb_define_method(cNWScript, "SetCustomToken", NWScript_SetCustomToken, 2);
	rb_define_method(cNWScript, "GetHasFeat", NWScript_GetHasFeat, 2);
	rb_define_method(cNWScript, "GetHasSkill", NWScript_GetHasSkill, 2);
	rb_define_method(cNWScript, "ActionUseFeat", NWScript_ActionUseFeat, 2);
	rb_define_method(cNWScript, "ActionUseSkill", NWScript_ActionUseSkill, 4);
	rb_define_method(cNWScript, "GetObjectSeen", NWScript_GetObjectSeen, 2);
	rb_define_method(cNWScript, "GetObjectHeard", NWScript_GetObjectHeard, 2);
	rb_define_method(cNWScript, "GetLastPlayerDied", NWScript_GetLastPlayerDied, 0);
	rb_define_method(cNWScript, "GetModuleItemLost", NWScript_GetModuleItemLost, 0);
	rb_define_method(cNWScript, "GetModuleItemLostBy", NWScript_GetModuleItemLostBy, 0);
	rb_define_method(cNWScript, "ActionDoCommand", NWScript_ActionDoCommand, 1);
	rb_define_method(cNWScript, "EventConversation", NWScript_EventConversation, 0);
	rb_define_method(cNWScript, "SetEncounterDifficulty", NWScript_SetEncounterDifficulty, 2);
	rb_define_method(cNWScript, "GetEncounterDifficulty", NWScript_GetEncounterDifficulty, 1);
	rb_define_method(cNWScript, "GetDistanceBetweenLocations", NWScript_GetDistanceBetweenLocations, 2);
	rb_define_method(cNWScript, "GetReflexAdjustedDamage", NWScript_GetReflexAdjustedDamage, 5);
	rb_define_method(cNWScript, "PlayAnimation", NWScript_PlayAnimation, 3);
	rb_define_method(cNWScript, "TalentSpell", NWScript_TalentSpell, 1);
	rb_define_method(cNWScript, "TalentFeat", NWScript_TalentFeat, 1);
	rb_define_method(cNWScript, "TalentSkill", NWScript_TalentSkill, 1);
	rb_define_method(cNWScript, "GetHasSpellEffect", NWScript_GetHasSpellEffect, 2);
	rb_define_method(cNWScript, "GetEffectSpellId", NWScript_GetEffectSpellId, 1);
	rb_define_method(cNWScript, "GetCreatureHasTalent", NWScript_GetCreatureHasTalent, 2);
	rb_define_method(cNWScript, "GetCreatureTalentRandom", NWScript_GetCreatureTalentRandom, 2);
	rb_define_method(cNWScript, "GetCreatureTalentBest", NWScript_GetCreatureTalentBest, 3);
	rb_define_method(cNWScript, "ActionUseTalentOnObject", NWScript_ActionUseTalentOnObject, 2);
	rb_define_method(cNWScript, "ActionUseTalentAtLocation", NWScript_ActionUseTalentAtLocation, 2);
	rb_define_method(cNWScript, "GetGoldPieceValue", NWScript_GetGoldPieceValue, 1);
	rb_define_method(cNWScript, "GetIsPlayableRacialType", NWScript_GetIsPlayableRacialType, 1);
	rb_define_method(cNWScript, "JumpToLocation", NWScript_JumpToLocation, 1);
	rb_define_method(cNWScript, "EffectTemporaryHitpoints", NWScript_EffectTemporaryHitpoints, 1);
	rb_define_method(cNWScript, "GetSkillRank", NWScript_GetSkillRank, 3);
	rb_define_method(cNWScript, "GetAttackTarget", NWScript_GetAttackTarget, 1);
	rb_define_method(cNWScript, "GetLastAttackType", NWScript_GetLastAttackType, 1);
	rb_define_method(cNWScript, "GetLastAttackMode", NWScript_GetLastAttackMode, 1);
	rb_define_method(cNWScript, "GetMaster", NWScript_GetMaster, 1);
	rb_define_method(cNWScript, "GetIsInCombat", NWScript_GetIsInCombat, 1);
	rb_define_method(cNWScript, "GetLastAssociateCommand", NWScript_GetLastAssociateCommand, 1);
	rb_define_method(cNWScript, "GiveGoldToCreature", NWScript_GiveGoldToCreature, 2);
	rb_define_method(cNWScript, "SetIsDestroyable", NWScript_SetIsDestroyable, 3);
	rb_define_method(cNWScript, "SetLocked", NWScript_SetLocked, 2);
	rb_define_method(cNWScript, "GetLocked", NWScript_GetLocked, 1);
	rb_define_method(cNWScript, "GetClickingObject", NWScript_GetClickingObject, 0);
	rb_define_method(cNWScript, "SetAssociateListenPatterns", NWScript_SetAssociateListenPatterns, 1);
	rb_define_method(cNWScript, "GetLastWeaponUsed", NWScript_GetLastWeaponUsed, 1);
	rb_define_method(cNWScript, "ActionInteractObject", NWScript_ActionInteractObject, 1);
	rb_define_method(cNWScript, "GetLastUsedBy", NWScript_GetLastUsedBy, 0);
	rb_define_method(cNWScript, "GetAbilityModifier", NWScript_GetAbilityModifier, 2);
	rb_define_method(cNWScript, "GetIdentified", NWScript_GetIdentified, 1);
	rb_define_method(cNWScript, "SetIdentified", NWScript_SetIdentified, 2);
	rb_define_method(cNWScript, "SummonAnimalCompanion", NWScript_SummonAnimalCompanion, 1);
	rb_define_method(cNWScript, "SummonFamiliar", NWScript_SummonFamiliar, 1);
	rb_define_method(cNWScript, "GetBlockingDoor", NWScript_GetBlockingDoor, 0);
	rb_define_method(cNWScript, "GetIsDoorActionPossible", NWScript_GetIsDoorActionPossible, 2);
	rb_define_method(cNWScript, "DoDoorAction", NWScript_DoDoorAction, 2);
	rb_define_method(cNWScript, "GetFirstItemInInventory", NWScript_GetFirstItemInInventory, 1);
	rb_define_method(cNWScript, "GetNextItemInInventory", NWScript_GetNextItemInInventory, 1);
	rb_define_method(cNWScript, "GetClassByPosition", NWScript_GetClassByPosition, 2);
	rb_define_method(cNWScript, "GetLevelByPosition", NWScript_GetLevelByPosition, 2);
	rb_define_method(cNWScript, "GetLevelByClass", NWScript_GetLevelByClass, 2);
	rb_define_method(cNWScript, "GetDamageDealtByType", NWScript_GetDamageDealtByType, 1);
	rb_define_method(cNWScript, "GetTotalDamageDealt", NWScript_GetTotalDamageDealt, 0);
	rb_define_method(cNWScript, "GetLastDamager", NWScript_GetLastDamager, 1);
	rb_define_method(cNWScript, "GetLastDisarmed", NWScript_GetLastDisarmed, 0);
	rb_define_method(cNWScript, "GetLastDisturbed", NWScript_GetLastDisturbed, 0);
	rb_define_method(cNWScript, "GetLastLocked", NWScript_GetLastLocked, 0);
	rb_define_method(cNWScript, "GetLastUnlocked", NWScript_GetLastUnlocked, 0);
	rb_define_method(cNWScript, "EffectSkillIncrease", NWScript_EffectSkillIncrease, 2);
	rb_define_method(cNWScript, "GetInventoryDisturbType", NWScript_GetInventoryDisturbType, 0);
	rb_define_method(cNWScript, "GetInventoryDisturbItem", NWScript_GetInventoryDisturbItem, 0);
	rb_define_method(cNWScript, "GetHenchman", NWScript_GetHenchman, 2);
	rb_define_method(cNWScript, "VersusAlignmentEffect", NWScript_VersusAlignmentEffect, 3);
	rb_define_method(cNWScript, "VersusRacialTypeEffect", NWScript_VersusRacialTypeEffect, 2);
	rb_define_method(cNWScript, "VersusTrapEffect", NWScript_VersusTrapEffect, 1);
	rb_define_method(cNWScript, "GetGender", NWScript_GetGender, 1);
	rb_define_method(cNWScript, "GetIsTalentValid", NWScript_GetIsTalentValid, 1);
	rb_define_method(cNWScript, "ActionMoveAwayFromLocation", NWScript_ActionMoveAwayFromLocation, 3);
	rb_define_method(cNWScript, "GetAttemptedAttackTarget", NWScript_GetAttemptedAttackTarget, 0);
	rb_define_method(cNWScript, "GetTypeFromTalent", NWScript_GetTypeFromTalent, 1);
	rb_define_method(cNWScript, "GetIdFromTalent", NWScript_GetIdFromTalent, 1);
	rb_define_method(cNWScript, "GetAssociate", NWScript_GetAssociate, 3);
	rb_define_method(cNWScript, "AddHenchman", NWScript_AddHenchman, 2);
	rb_define_method(cNWScript, "RemoveHenchman", NWScript_RemoveHenchman, 2);
	rb_define_method(cNWScript, "AddJournalQuestEntry", NWScript_AddJournalQuestEntry, 6);
	rb_define_method(cNWScript, "RemoveJournalQuestEntry", NWScript_RemoveJournalQuestEntry, 4);
	rb_define_method(cNWScript, "GetPCPublicCDKey", NWScript_GetPCPublicCDKey, 2);
	rb_define_method(cNWScript, "GetPCIPAddress", NWScript_GetPCIPAddress, 1);
	rb_define_method(cNWScript, "GetPCPlayerName", NWScript_GetPCPlayerName, 1);
	rb_define_method(cNWScript, "SetPCLike", NWScript_SetPCLike, 2);
	rb_define_method(cNWScript, "SetPCDislike", NWScript_SetPCDislike, 2);
	rb_define_method(cNWScript, "SendMessageToPC", NWScript_SendMessageToPC, 2);
	rb_define_method(cNWScript, "GetAttemptedSpellTarget", NWScript_GetAttemptedSpellTarget, 0);
	rb_define_method(cNWScript, "GetLastOpenedBy", NWScript_GetLastOpenedBy, 0);
	rb_define_method(cNWScript, "GetHasSpell", NWScript_GetHasSpell, 2);
	rb_define_method(cNWScript, "OpenStore", NWScript_OpenStore, 4);
	rb_define_method(cNWScript, "EffectTurned", NWScript_EffectTurned, 0);
	rb_define_method(cNWScript, "GetFirstFactionMember", NWScript_GetFirstFactionMember, 2);
	rb_define_method(cNWScript, "GetNextFactionMember", NWScript_GetNextFactionMember, 2);
	rb_define_method(cNWScript, "ActionForceMoveToLocation", NWScript_ActionForceMoveToLocation, 3);
	rb_define_method(cNWScript, "ActionForceMoveToObject", NWScript_ActionForceMoveToObject, 4);
	rb_define_method(cNWScript, "GetJournalQuestExperience", NWScript_GetJournalQuestExperience, 1);
	rb_define_method(cNWScript, "JumpToObject", NWScript_JumpToObject, 2);
	rb_define_method(cNWScript, "SetMapPinEnabled", NWScript_SetMapPinEnabled, 2);
	rb_define_method(cNWScript, "EffectHitPointChangeWhenDying", NWScript_EffectHitPointChangeWhenDying, 1);
	rb_define_method(cNWScript, "PopUpGUIPanel", NWScript_PopUpGUIPanel, 2);
	rb_define_method(cNWScript, "ClearPersonalReputation", NWScript_ClearPersonalReputation, 2);
	rb_define_method(cNWScript, "SetIsTemporaryFriend", NWScript_SetIsTemporaryFriend, 4);
	rb_define_method(cNWScript, "SetIsTemporaryEnemy", NWScript_SetIsTemporaryEnemy, 4);
	rb_define_method(cNWScript, "SetIsTemporaryNeutral", NWScript_SetIsTemporaryNeutral, 4);
	rb_define_method(cNWScript, "GiveXPToCreature", NWScript_GiveXPToCreature, 2);
	rb_define_method(cNWScript, "SetXP", NWScript_SetXP, 2);
	rb_define_method(cNWScript, "GetXP", NWScript_GetXP, 1);
	rb_define_method(cNWScript, "IntToHexString", NWScript_IntToHexString, 1);
	rb_define_method(cNWScript, "GetBaseItemType", NWScript_GetBaseItemType, 1);
	rb_define_method(cNWScript, "GetItemHasItemProperty", NWScript_GetItemHasItemProperty, 2);
	rb_define_method(cNWScript, "ActionEquipMostDamagingMelee", NWScript_ActionEquipMostDamagingMelee, 2);
	rb_define_method(cNWScript, "ActionEquipMostDamagingRanged", NWScript_ActionEquipMostDamagingRanged, 1);
	rb_define_method(cNWScript, "GetItemACValue", NWScript_GetItemACValue, 1);
	rb_define_method(cNWScript, "ActionRest", NWScript_ActionRest, 1);
	rb_define_method(cNWScript, "ExploreAreaForPlayer", NWScript_ExploreAreaForPlayer, 3);
	rb_define_method(cNWScript, "ActionEquipMostEffectiveArmor", NWScript_ActionEquipMostEffectiveArmor, 0);
	rb_define_method(cNWScript, "GetIsDay", NWScript_GetIsDay, 0);
	rb_define_method(cNWScript, "GetIsNight", NWScript_GetIsNight, 0);
	rb_define_method(cNWScript, "GetIsDawn", NWScript_GetIsDawn, 0);
	rb_define_method(cNWScript, "GetIsDusk", NWScript_GetIsDusk, 0);
	rb_define_method(cNWScript, "GetIsEncounterCreature", NWScript_GetIsEncounterCreature, 1);
	rb_define_method(cNWScript, "GetLastPlayerDying", NWScript_GetLastPlayerDying, 0);
	rb_define_method(cNWScript, "GetStartingLocation", NWScript_GetStartingLocation, 0);
	rb_define_method(cNWScript, "ChangeToStandardFaction", NWScript_ChangeToStandardFaction, 2);
	rb_define_method(cNWScript, "SoundObjectPlay", NWScript_SoundObjectPlay, 1);
	rb_define_method(cNWScript, "SoundObjectStop", NWScript_SoundObjectStop, 1);
	rb_define_method(cNWScript, "SoundObjectSetVolume", NWScript_SoundObjectSetVolume, 2);
	rb_define_method(cNWScript, "SoundObjectSetPosition", NWScript_SoundObjectSetPosition, 2);
	rb_define_method(cNWScript, "SpeakOneLinerConversation", NWScript_SpeakOneLinerConversation, 2);
	rb_define_method(cNWScript, "GetGold", NWScript_GetGold, 1);
	rb_define_method(cNWScript, "GetLastRespawnButtonPresser", NWScript_GetLastRespawnButtonPresser, 0);
	rb_define_method(cNWScript, "GetIsDM", NWScript_GetIsDM, 1);
	rb_define_method(cNWScript, "PlayVoiceChat", NWScript_PlayVoiceChat, 2);
	rb_define_method(cNWScript, "GetIsWeaponEffective", NWScript_GetIsWeaponEffective, 2);
	rb_define_method(cNWScript, "GetLastSpellHarmful", NWScript_GetLastSpellHarmful, 0);
	rb_define_method(cNWScript, "EventActivateItem", NWScript_EventActivateItem, 3);
	rb_define_method(cNWScript, "MusicBackgroundPlay", NWScript_MusicBackgroundPlay, 1);
	rb_define_method(cNWScript, "MusicBackgroundStop", NWScript_MusicBackgroundStop, 1);
	rb_define_method(cNWScript, "MusicBackgroundSetDelay", NWScript_MusicBackgroundSetDelay, 2);
	rb_define_method(cNWScript, "MusicBackgroundChangeDay", NWScript_MusicBackgroundChangeDay, 2);
	rb_define_method(cNWScript, "MusicBackgroundChangeNight", NWScript_MusicBackgroundChangeNight, 2);
	rb_define_method(cNWScript, "MusicBattlePlay", NWScript_MusicBattlePlay, 1);
	rb_define_method(cNWScript, "MusicBattleStop", NWScript_MusicBattleStop, 1);
	rb_define_method(cNWScript, "MusicBattleChange", NWScript_MusicBattleChange, 2);
	rb_define_method(cNWScript, "AmbientSoundPlay", NWScript_AmbientSoundPlay, 1);
	rb_define_method(cNWScript, "AmbientSoundStop", NWScript_AmbientSoundStop, 1);
	rb_define_method(cNWScript, "AmbientSoundChangeDay", NWScript_AmbientSoundChangeDay, 2);
	rb_define_method(cNWScript, "AmbientSoundChangeNight", NWScript_AmbientSoundChangeNight, 2);
	rb_define_method(cNWScript, "GetLastKiller", NWScript_GetLastKiller, 0);
	rb_define_method(cNWScript, "GetSpellCastItem", NWScript_GetSpellCastItem, 0);
	rb_define_method(cNWScript, "GetItemActivated", NWScript_GetItemActivated, 0);
	rb_define_method(cNWScript, "GetItemActivator", NWScript_GetItemActivator, 0);
	rb_define_method(cNWScript, "GetItemActivatedTargetLocation", NWScript_GetItemActivatedTargetLocation, 0);
	rb_define_method(cNWScript, "GetItemActivatedTarget", NWScript_GetItemActivatedTarget, 0);
	rb_define_method(cNWScript, "GetIsOpen", NWScript_GetIsOpen, 1);
	rb_define_method(cNWScript, "TakeGoldFromCreature", NWScript_TakeGoldFromCreature, 3);
	rb_define_method(cNWScript, "IsInConversation", NWScript_IsInConversation, 1);
	rb_define_method(cNWScript, "EffectAbilityDecrease", NWScript_EffectAbilityDecrease, 2);
	rb_define_method(cNWScript, "EffectAttackDecrease", NWScript_EffectAttackDecrease, 2);
	rb_define_method(cNWScript, "EffectDamageDecrease", NWScript_EffectDamageDecrease, 2);
	rb_define_method(cNWScript, "EffectDamageImmunityDecrease", NWScript_EffectDamageImmunityDecrease, 2);
	rb_define_method(cNWScript, "EffectACDecrease", NWScript_EffectACDecrease, 3);
	rb_define_method(cNWScript, "EffectMovementSpeedDecrease", NWScript_EffectMovementSpeedDecrease, 1);
	rb_define_method(cNWScript, "EffectSavingThrowDecrease", NWScript_EffectSavingThrowDecrease, 3);
	rb_define_method(cNWScript, "EffectSkillDecrease", NWScript_EffectSkillDecrease, 2);
	rb_define_method(cNWScript, "EffectSpellResistanceDecrease", NWScript_EffectSpellResistanceDecrease, 1);
	rb_define_method(cNWScript, "GetPlotFlag", NWScript_GetPlotFlag, 1);
	rb_define_method(cNWScript, "SetPlotFlag", NWScript_SetPlotFlag, 2);
	rb_define_method(cNWScript, "EffectInvisibility", NWScript_EffectInvisibility, 1);
	rb_define_method(cNWScript, "EffectConcealment", NWScript_EffectConcealment, 2);
	rb_define_method(cNWScript, "EffectDarkness", NWScript_EffectDarkness, 0);
	rb_define_method(cNWScript, "EffectDispelMagicAll", NWScript_EffectDispelMagicAll, 1);
	rb_define_method(cNWScript, "EffectUltravision", NWScript_EffectUltravision, 0);
	rb_define_method(cNWScript, "EffectNegativeLevel", NWScript_EffectNegativeLevel, 2);
	rb_define_method(cNWScript, "EffectPolymorph", NWScript_EffectPolymorph, 2);
	rb_define_method(cNWScript, "EffectSanctuary", NWScript_EffectSanctuary, 1);
	rb_define_method(cNWScript, "EffectTrueSeeing", NWScript_EffectTrueSeeing, 0);
	rb_define_method(cNWScript, "EffectSeeInvisible", NWScript_EffectSeeInvisible, 0);
	rb_define_method(cNWScript, "EffectTimeStop", NWScript_EffectTimeStop, 0);
	rb_define_method(cNWScript, "EffectBlindness", NWScript_EffectBlindness, 0);
	rb_define_method(cNWScript, "GetIsReactionTypeFriendly", NWScript_GetIsReactionTypeFriendly, 2);
	rb_define_method(cNWScript, "GetIsReactionTypeNeutral", NWScript_GetIsReactionTypeNeutral, 2);
	rb_define_method(cNWScript, "GetIsReactionTypeHostile", NWScript_GetIsReactionTypeHostile, 2);
	rb_define_method(cNWScript, "EffectSpellLevelAbsorption", NWScript_EffectSpellLevelAbsorption, 3);
	rb_define_method(cNWScript, "EffectDispelMagicBest", NWScript_EffectDispelMagicBest, 1);
	rb_define_method(cNWScript, "ActivatePortal", NWScript_ActivatePortal, 5);
	rb_define_method(cNWScript, "GetNumStackedItems", NWScript_GetNumStackedItems, 1);
	rb_define_method(cNWScript, "SurrenderToEnemies", NWScript_SurrenderToEnemies, 0);
	rb_define_method(cNWScript, "EffectMissChance", NWScript_EffectMissChance, 2);
	rb_define_method(cNWScript, "GetTurnResistanceHD", NWScript_GetTurnResistanceHD, 1);
	rb_define_method(cNWScript, "GetCreatureSize", NWScript_GetCreatureSize, 1);
	rb_define_method(cNWScript, "EffectDisappearAppear", NWScript_EffectDisappearAppear, 2);
	rb_define_method(cNWScript, "EffectDisappear", NWScript_EffectDisappear, 1);
	rb_define_method(cNWScript, "EffectAppear", NWScript_EffectAppear, 1);
	rb_define_method(cNWScript, "ActionUnlockObject", NWScript_ActionUnlockObject, 1);
	rb_define_method(cNWScript, "ActionLockObject", NWScript_ActionLockObject, 1);
	rb_define_method(cNWScript, "EffectModifyAttacks", NWScript_EffectModifyAttacks, 1);
	rb_define_method(cNWScript, "GetLastTrapDetected", NWScript_GetLastTrapDetected, 1);
	rb_define_method(cNWScript, "EffectDamageShield", NWScript_EffectDamageShield, 3);
	rb_define_method(cNWScript, "GetNearestTrapToObject", NWScript_GetNearestTrapToObject, 2);
	rb_define_method(cNWScript, "GetDeity", NWScript_GetDeity, 1);
	rb_define_method(cNWScript, "GetSubRace", NWScript_GetSubRace, 1);
	rb_define_method(cNWScript, "GetFortitudeSavingThrow", NWScript_GetFortitudeSavingThrow, 1);
	rb_define_method(cNWScript, "GetWillSavingThrow", NWScript_GetWillSavingThrow, 1);
	rb_define_method(cNWScript, "GetReflexSavingThrow", NWScript_GetReflexSavingThrow, 1);
	rb_define_method(cNWScript, "GetChallengeRating", NWScript_GetChallengeRating, 1);
	rb_define_method(cNWScript, "GetAge", NWScript_GetAge, 1);
	rb_define_method(cNWScript, "GetMovementRate", NWScript_GetMovementRate, 1);
	rb_define_method(cNWScript, "GetFamiliarCreatureType", NWScript_GetFamiliarCreatureType, 1);
	rb_define_method(cNWScript, "GetAnimalCompanionCreatureType", NWScript_GetAnimalCompanionCreatureType, 1);
	rb_define_method(cNWScript, "GetFamiliarName", NWScript_GetFamiliarName, 1);
	rb_define_method(cNWScript, "GetAnimalCompanionName", NWScript_GetAnimalCompanionName, 1);
	rb_define_method(cNWScript, "ActionCastFakeSpellAtObject", NWScript_ActionCastFakeSpellAtObject, 3);
	rb_define_method(cNWScript, "ActionCastFakeSpellAtLocation", NWScript_ActionCastFakeSpellAtLocation, 3);
	rb_define_method(cNWScript, "RemoveSummonedAssociate", NWScript_RemoveSummonedAssociate, 2);
	rb_define_method(cNWScript, "SetCameraMode", NWScript_SetCameraMode, 2);
	rb_define_method(cNWScript, "GetIsResting", NWScript_GetIsResting, 1);
	rb_define_method(cNWScript, "GetLastPCRested", NWScript_GetLastPCRested, 0);
	rb_define_method(cNWScript, "SetWeather", NWScript_SetWeather, 2);
	rb_define_method(cNWScript, "GetLastRestEventType", NWScript_GetLastRestEventType, 0);
	rb_define_method(cNWScript, "StartNewModule", NWScript_StartNewModule, 1);
	rb_define_method(cNWScript, "EffectSwarm", NWScript_EffectSwarm, 5);
	rb_define_method(cNWScript, "GetWeaponRanged", NWScript_GetWeaponRanged, 1);
	rb_define_method(cNWScript, "DoSinglePlayerAutoSave", NWScript_DoSinglePlayerAutoSave, 0);
	rb_define_method(cNWScript, "GetGameDifficulty", NWScript_GetGameDifficulty, 0);
	rb_define_method(cNWScript, "SetTileMainLightColor", NWScript_SetTileMainLightColor, 3);
	rb_define_method(cNWScript, "SetTileSourceLightColor", NWScript_SetTileSourceLightColor, 3);
	rb_define_method(cNWScript, "RecomputeStaticLighting", NWScript_RecomputeStaticLighting, 1);
	rb_define_method(cNWScript, "GetTileMainLight1Color", NWScript_GetTileMainLight1Color, 1);
	rb_define_method(cNWScript, "GetTileMainLight2Color", NWScript_GetTileMainLight2Color, 1);
	rb_define_method(cNWScript, "GetTileSourceLight1Color", NWScript_GetTileSourceLight1Color, 1);
	rb_define_method(cNWScript, "GetTileSourceLight2Color", NWScript_GetTileSourceLight2Color, 1);
	rb_define_method(cNWScript, "SetPanelButtonFlash", NWScript_SetPanelButtonFlash, 3);
	rb_define_method(cNWScript, "GetCurrentAction", NWScript_GetCurrentAction, 1);
	rb_define_method(cNWScript, "SetStandardFactionReputation", NWScript_SetStandardFactionReputation, 3);
	rb_define_method(cNWScript, "GetStandardFactionReputation", NWScript_GetStandardFactionReputation, 2);
	rb_define_method(cNWScript, "FloatingTextStrRefOnCreature", NWScript_FloatingTextStrRefOnCreature, 3);
	rb_define_method(cNWScript, "FloatingTextStringOnCreature", NWScript_FloatingTextStringOnCreature, 3);
	rb_define_method(cNWScript, "GetTrapDisarmable", NWScript_GetTrapDisarmable, 1);
	rb_define_method(cNWScript, "GetTrapDetectable", NWScript_GetTrapDetectable, 1);
	rb_define_method(cNWScript, "GetTrapDetectedBy", NWScript_GetTrapDetectedBy, 2);
	rb_define_method(cNWScript, "GetTrapFlagged", NWScript_GetTrapFlagged, 1);
	rb_define_method(cNWScript, "GetTrapBaseType", NWScript_GetTrapBaseType, 1);
	rb_define_method(cNWScript, "GetTrapOneShot", NWScript_GetTrapOneShot, 1);
	rb_define_method(cNWScript, "GetTrapCreator", NWScript_GetTrapCreator, 1);
	rb_define_method(cNWScript, "GetTrapKeyTag", NWScript_GetTrapKeyTag, 1);
	rb_define_method(cNWScript, "GetTrapDisarmDC", NWScript_GetTrapDisarmDC, 1);
	rb_define_method(cNWScript, "GetTrapDetectDC", NWScript_GetTrapDetectDC, 1);
	rb_define_method(cNWScript, "GetLockKeyRequired", NWScript_GetLockKeyRequired, 1);
	rb_define_method(cNWScript, "GetLockKeyTag", NWScript_GetLockKeyTag, 1);
	rb_define_method(cNWScript, "GetLockLockable", NWScript_GetLockLockable, 1);
	rb_define_method(cNWScript, "GetLockUnlockDC", NWScript_GetLockUnlockDC, 1);
	rb_define_method(cNWScript, "GetLockLockDC", NWScript_GetLockLockDC, 1);
	rb_define_method(cNWScript, "GetPCLevellingUp", NWScript_GetPCLevellingUp, 0);
	rb_define_method(cNWScript, "GetHasFeatEffect", NWScript_GetHasFeatEffect, 2);
	rb_define_method(cNWScript, "SetPlaceableIllumination", NWScript_SetPlaceableIllumination, 2);
	rb_define_method(cNWScript, "GetPlaceableIllumination", NWScript_GetPlaceableIllumination, 1);
	rb_define_method(cNWScript, "GetIsPlaceableObjectActionPossible", NWScript_GetIsPlaceableObjectActionPossible, 2);
	rb_define_method(cNWScript, "DoPlaceableObjectAction", NWScript_DoPlaceableObjectAction, 2);
	rb_define_method(cNWScript, "GetFirstPC", NWScript_GetFirstPC, 0);
	rb_define_method(cNWScript, "GetNextPC", NWScript_GetNextPC, 0);
	rb_define_method(cNWScript, "SetTrapDetectedBy", NWScript_SetTrapDetectedBy, 3);
	rb_define_method(cNWScript, "GetIsTrapped", NWScript_GetIsTrapped, 1);
	rb_define_method(cNWScript, "EffectTurnResistanceDecrease", NWScript_EffectTurnResistanceDecrease, 1);
	rb_define_method(cNWScript, "EffectTurnResistanceIncrease", NWScript_EffectTurnResistanceIncrease, 1);
	rb_define_method(cNWScript, "PopUpDeathGUIPanel", NWScript_PopUpDeathGUIPanel, 5);
	rb_define_method(cNWScript, "SetTrapDisabled", NWScript_SetTrapDisabled, 1);
	rb_define_method(cNWScript, "GetLastHostileActor", NWScript_GetLastHostileActor, 1);
	rb_define_method(cNWScript, "ExportAllCharacters", NWScript_ExportAllCharacters, 0);
	rb_define_method(cNWScript, "MusicBackgroundGetDayTrack", NWScript_MusicBackgroundGetDayTrack, 1);
	rb_define_method(cNWScript, "MusicBackgroundGetNightTrack", NWScript_MusicBackgroundGetNightTrack, 1);
	rb_define_method(cNWScript, "WriteTimestampedLogEntry", NWScript_WriteTimestampedLogEntry, 1);
	rb_define_method(cNWScript, "GetModuleName", NWScript_GetModuleName, 0);
	rb_define_method(cNWScript, "GetFactionLeader", NWScript_GetFactionLeader, 1);
	rb_define_method(cNWScript, "SendMessageToAllDMs", NWScript_SendMessageToAllDMs, 1);
	rb_define_method(cNWScript, "EndGame", NWScript_EndGame, 1);
	rb_define_method(cNWScript, "BootPC", NWScript_BootPC, 1);
	rb_define_method(cNWScript, "ActionCounterSpell", NWScript_ActionCounterSpell, 1);
	rb_define_method(cNWScript, "AmbientSoundSetDayVolume", NWScript_AmbientSoundSetDayVolume, 2);
	rb_define_method(cNWScript, "AmbientSoundSetNightVolume", NWScript_AmbientSoundSetNightVolume, 2);
	rb_define_method(cNWScript, "MusicBackgroundGetBattleTrack", NWScript_MusicBackgroundGetBattleTrack, 1);
	rb_define_method(cNWScript, "GetHasInventory", NWScript_GetHasInventory, 1);
	rb_define_method(cNWScript, "GetStrRefSoundDuration", NWScript_GetStrRefSoundDuration, 1);
	rb_define_method(cNWScript, "AddToParty", NWScript_AddToParty, 2);
	rb_define_method(cNWScript, "RemoveFromParty", NWScript_RemoveFromParty, 1);
	rb_define_method(cNWScript, "GetStealthMode", NWScript_GetStealthMode, 1);
	rb_define_method(cNWScript, "GetDetectMode", NWScript_GetDetectMode, 1);
	rb_define_method(cNWScript, "GetDefensiveCastingMode", NWScript_GetDefensiveCastingMode, 1);
	rb_define_method(cNWScript, "GetAppearanceType", NWScript_GetAppearanceType, 1);
	rb_define_method(cNWScript, "SpawnScriptDebugger", NWScript_SpawnScriptDebugger, 0);
	rb_define_method(cNWScript, "GetModuleItemAcquiredStackSize", NWScript_GetModuleItemAcquiredStackSize, 0);
	rb_define_method(cNWScript, "DecrementRemainingFeatUses", NWScript_DecrementRemainingFeatUses, 2);
	rb_define_method(cNWScript, "DecrementRemainingSpellUses", NWScript_DecrementRemainingSpellUses, 2);
	rb_define_method(cNWScript, "GetResRef", NWScript_GetResRef, 1);
	rb_define_method(cNWScript, "EffectPetrify", NWScript_EffectPetrify, 0);
	rb_define_method(cNWScript, "CopyItem", NWScript_CopyItem, 3);
	rb_define_method(cNWScript, "EffectCutsceneParalyze", NWScript_EffectCutsceneParalyze, 0);
	rb_define_method(cNWScript, "GetDroppableFlag", NWScript_GetDroppableFlag, 1);
	rb_define_method(cNWScript, "GetUseableFlag", NWScript_GetUseableFlag, 1);
	rb_define_method(cNWScript, "GetStolenFlag", NWScript_GetStolenFlag, 1);
	rb_define_method(cNWScript, "SetCampaignFloat", NWScript_SetCampaignFloat, 4);
	rb_define_method(cNWScript, "SetCampaignInt", NWScript_SetCampaignInt, 4);
	rb_define_method(cNWScript, "SetCampaignVector", NWScript_SetCampaignVector, 4);
	rb_define_method(cNWScript, "SetCampaignLocation", NWScript_SetCampaignLocation, 4);
	rb_define_method(cNWScript, "SetCampaignString", NWScript_SetCampaignString, 4);
	rb_define_method(cNWScript, "DestroyCampaignDatabase", NWScript_DestroyCampaignDatabase, 1);
	rb_define_method(cNWScript, "GetCampaignFloat", NWScript_GetCampaignFloat, 3);
	rb_define_method(cNWScript, "GetCampaignInt", NWScript_GetCampaignInt, 3);
	rb_define_method(cNWScript, "GetCampaignVector", NWScript_GetCampaignVector, 3);
	rb_define_method(cNWScript, "GetCampaignLocation", NWScript_GetCampaignLocation, 3);
	rb_define_method(cNWScript, "GetCampaignString", NWScript_GetCampaignString, 3);
	rb_define_method(cNWScript, "CopyObject", NWScript_CopyObject, 4);
	rb_define_method(cNWScript, "DeleteCampaignVariable", NWScript_DeleteCampaignVariable, 3);
	rb_define_method(cNWScript, "StoreCampaignObject", NWScript_StoreCampaignObject, 4);
	rb_define_method(cNWScript, "RetrieveCampaignObject", NWScript_RetrieveCampaignObject, 5);
	rb_define_method(cNWScript, "EffectCutsceneDominated", NWScript_EffectCutsceneDominated, 0);
	rb_define_method(cNWScript, "GetItemStackSize", NWScript_GetItemStackSize, 1);
	rb_define_method(cNWScript, "SetItemStackSize", NWScript_SetItemStackSize, 2);
	rb_define_method(cNWScript, "GetItemCharges", NWScript_GetItemCharges, 1);
	rb_define_method(cNWScript, "SetItemCharges", NWScript_SetItemCharges, 2);
	rb_define_method(cNWScript, "AddItemProperty", NWScript_AddItemProperty, 4);
	rb_define_method(cNWScript, "RemoveItemProperty", NWScript_RemoveItemProperty, 2);
	rb_define_method(cNWScript, "GetIsItemPropertyValid", NWScript_GetIsItemPropertyValid, 1);
	rb_define_method(cNWScript, "GetFirstItemProperty", NWScript_GetFirstItemProperty, 1);
	rb_define_method(cNWScript, "GetNextItemProperty", NWScript_GetNextItemProperty, 1);
	rb_define_method(cNWScript, "GetItemPropertyType", NWScript_GetItemPropertyType, 1);
	rb_define_method(cNWScript, "GetItemPropertyDurationType", NWScript_GetItemPropertyDurationType, 1);
	rb_define_method(cNWScript, "ItemPropertyAbilityBonus", NWScript_ItemPropertyAbilityBonus, 2);
	rb_define_method(cNWScript, "ItemPropertyACBonus", NWScript_ItemPropertyACBonus, 1);
	rb_define_method(cNWScript, "ItemPropertyACBonusVsAlign", NWScript_ItemPropertyACBonusVsAlign, 2);
	rb_define_method(cNWScript, "ItemPropertyACBonusVsDmgType", NWScript_ItemPropertyACBonusVsDmgType, 2);
	rb_define_method(cNWScript, "ItemPropertyACBonusVsRace", NWScript_ItemPropertyACBonusVsRace, 2);
	rb_define_method(cNWScript, "ItemPropertyACBonusVsSAlign", NWScript_ItemPropertyACBonusVsSAlign, 2);
	rb_define_method(cNWScript, "ItemPropertyEnhancementBonus", NWScript_ItemPropertyEnhancementBonus, 1);
	rb_define_method(cNWScript, "ItemPropertyEnhancementBonusVsAlign", NWScript_ItemPropertyEnhancementBonusVsAlign, 2);
	rb_define_method(cNWScript, "ItemPropertyEnhancementBonusVsRace", NWScript_ItemPropertyEnhancementBonusVsRace, 2);
	rb_define_method(cNWScript, "ItemPropertyEnhancementBonusVsSAlign", NWScript_ItemPropertyEnhancementBonusVsSAlign, 2);
	rb_define_method(cNWScript, "ItemPropertyEnhancementPenalty", NWScript_ItemPropertyEnhancementPenalty, 1);
	rb_define_method(cNWScript, "ItemPropertyWeightReduction", NWScript_ItemPropertyWeightReduction, 1);
	rb_define_method(cNWScript, "ItemPropertyBonusFeat", NWScript_ItemPropertyBonusFeat, 1);
	rb_define_method(cNWScript, "ItemPropertyBonusLevelSpell", NWScript_ItemPropertyBonusLevelSpell, 2);
	rb_define_method(cNWScript, "ItemPropertyCastSpell", NWScript_ItemPropertyCastSpell, 2);
	rb_define_method(cNWScript, "ItemPropertyDamageBonus", NWScript_ItemPropertyDamageBonus, 2);
	rb_define_method(cNWScript, "ItemPropertyDamageBonusVsAlign", NWScript_ItemPropertyDamageBonusVsAlign, 3);
	rb_define_method(cNWScript, "ItemPropertyDamageBonusVsRace", NWScript_ItemPropertyDamageBonusVsRace, 3);
	rb_define_method(cNWScript, "ItemPropertyDamageBonusVsSAlign", NWScript_ItemPropertyDamageBonusVsSAlign, 3);
	rb_define_method(cNWScript, "ItemPropertyDamageImmunity", NWScript_ItemPropertyDamageImmunity, 2);
	rb_define_method(cNWScript, "ItemPropertyDamagePenalty", NWScript_ItemPropertyDamagePenalty, 1);
	rb_define_method(cNWScript, "ItemPropertyDamageReduction", NWScript_ItemPropertyDamageReduction, 2);
	rb_define_method(cNWScript, "ItemPropertyDamageResistance", NWScript_ItemPropertyDamageResistance, 2);
	rb_define_method(cNWScript, "ItemPropertyDamageVulnerability", NWScript_ItemPropertyDamageVulnerability, 2);
	rb_define_method(cNWScript, "ItemPropertyDarkvision", NWScript_ItemPropertyDarkvision, 0);
	rb_define_method(cNWScript, "ItemPropertyDecreaseAbility", NWScript_ItemPropertyDecreaseAbility, 2);
	rb_define_method(cNWScript, "ItemPropertyDecreaseAC", NWScript_ItemPropertyDecreaseAC, 2);
	rb_define_method(cNWScript, "ItemPropertyDecreaseSkill", NWScript_ItemPropertyDecreaseSkill, 2);
	rb_define_method(cNWScript, "ItemPropertyContainerReducedWeight", NWScript_ItemPropertyContainerReducedWeight, 1);
	rb_define_method(cNWScript, "ItemPropertyExtraMeleeDamageType", NWScript_ItemPropertyExtraMeleeDamageType, 1);
	rb_define_method(cNWScript, "ItemPropertyExtraRangeDamageType", NWScript_ItemPropertyExtraRangeDamageType, 1);
	rb_define_method(cNWScript, "ItemPropertyHaste", NWScript_ItemPropertyHaste, 0);
	rb_define_method(cNWScript, "ItemPropertyHolyAvenger", NWScript_ItemPropertyHolyAvenger, 0);
	rb_define_method(cNWScript, "ItemPropertyImmunityMisc", NWScript_ItemPropertyImmunityMisc, 1);
	rb_define_method(cNWScript, "ItemPropertyImprovedEvasion", NWScript_ItemPropertyImprovedEvasion, 0);
	rb_define_method(cNWScript, "ItemPropertyBonusSpellResistance", NWScript_ItemPropertyBonusSpellResistance, 1);
	rb_define_method(cNWScript, "ItemPropertyBonusSavingThrowVsX", NWScript_ItemPropertyBonusSavingThrowVsX, 2);
	rb_define_method(cNWScript, "ItemPropertyBonusSavingThrow", NWScript_ItemPropertyBonusSavingThrow, 2);
	rb_define_method(cNWScript, "ItemPropertyKeen", NWScript_ItemPropertyKeen, 0);
	rb_define_method(cNWScript, "ItemPropertyLight", NWScript_ItemPropertyLight, 2);
	rb_define_method(cNWScript, "ItemPropertyMaxRangeStrengthMod", NWScript_ItemPropertyMaxRangeStrengthMod, 1);
	rb_define_method(cNWScript, "ItemPropertyNoDamage", NWScript_ItemPropertyNoDamage, 0);
	rb_define_method(cNWScript, "ItemPropertyOnHitProps", NWScript_ItemPropertyOnHitProps, 3);
	rb_define_method(cNWScript, "ItemPropertyReducedSavingThrowVsX", NWScript_ItemPropertyReducedSavingThrowVsX, 2);
	rb_define_method(cNWScript, "ItemPropertyReducedSavingThrow", NWScript_ItemPropertyReducedSavingThrow, 2);
	rb_define_method(cNWScript, "ItemPropertyRegeneration", NWScript_ItemPropertyRegeneration, 1);
	rb_define_method(cNWScript, "ItemPropertySkillBonus", NWScript_ItemPropertySkillBonus, 2);
	rb_define_method(cNWScript, "ItemPropertySpellImmunitySpecific", NWScript_ItemPropertySpellImmunitySpecific, 1);
	rb_define_method(cNWScript, "ItemPropertySpellImmunitySchool", NWScript_ItemPropertySpellImmunitySchool, 1);
	rb_define_method(cNWScript, "ItemPropertyThievesTools", NWScript_ItemPropertyThievesTools, 1);
	rb_define_method(cNWScript, "ItemPropertyAttackBonus", NWScript_ItemPropertyAttackBonus, 1);
	rb_define_method(cNWScript, "ItemPropertyAttackBonusVsAlign", NWScript_ItemPropertyAttackBonusVsAlign, 2);
	rb_define_method(cNWScript, "ItemPropertyAttackBonusVsRace", NWScript_ItemPropertyAttackBonusVsRace, 2);
	rb_define_method(cNWScript, "ItemPropertyAttackBonusVsSAlign", NWScript_ItemPropertyAttackBonusVsSAlign, 2);
	rb_define_method(cNWScript, "ItemPropertyAttackPenalty", NWScript_ItemPropertyAttackPenalty, 1);
	rb_define_method(cNWScript, "ItemPropertyUnlimitedAmmo", NWScript_ItemPropertyUnlimitedAmmo, 1);
	rb_define_method(cNWScript, "ItemPropertyLimitUseByAlign", NWScript_ItemPropertyLimitUseByAlign, 1);
	rb_define_method(cNWScript, "ItemPropertyLimitUseByClass", NWScript_ItemPropertyLimitUseByClass, 1);
	rb_define_method(cNWScript, "ItemPropertyLimitUseByRace", NWScript_ItemPropertyLimitUseByRace, 1);
	rb_define_method(cNWScript, "ItemPropertyLimitUseBySAlign", NWScript_ItemPropertyLimitUseBySAlign, 1);
	rb_define_method(cNWScript, "BadBadReplaceMeThisDoesNothing", NWScript_BadBadReplaceMeThisDoesNothing, 0);
	rb_define_method(cNWScript, "ItemPropertyVampiricRegeneration", NWScript_ItemPropertyVampiricRegeneration, 1);
	rb_define_method(cNWScript, "ItemPropertyTrap", NWScript_ItemPropertyTrap, 2);
	rb_define_method(cNWScript, "ItemPropertyTrueSeeing", NWScript_ItemPropertyTrueSeeing, 0);
	rb_define_method(cNWScript, "ItemPropertyOnMonsterHitProperties", NWScript_ItemPropertyOnMonsterHitProperties, 2);
	rb_define_method(cNWScript, "ItemPropertyTurnResistance", NWScript_ItemPropertyTurnResistance, 1);
	rb_define_method(cNWScript, "ItemPropertyMassiveCritical", NWScript_ItemPropertyMassiveCritical, 1);
	rb_define_method(cNWScript, "ItemPropertyFreeAction", NWScript_ItemPropertyFreeAction, 0);
	rb_define_method(cNWScript, "ItemPropertyMonsterDamage", NWScript_ItemPropertyMonsterDamage, 1);
	rb_define_method(cNWScript, "ItemPropertyImmunityToSpellLevel", NWScript_ItemPropertyImmunityToSpellLevel, 1);
	rb_define_method(cNWScript, "ItemPropertySpecialWalk", NWScript_ItemPropertySpecialWalk, 1);
	rb_define_method(cNWScript, "ItemPropertyHealersKit", NWScript_ItemPropertyHealersKit, 1);
	rb_define_method(cNWScript, "ItemPropertyWeightIncrease", NWScript_ItemPropertyWeightIncrease, 1);
	rb_define_method(cNWScript, "GetIsSkillSuccessful", NWScript_GetIsSkillSuccessful, 3);
	rb_define_method(cNWScript, "EffectSpellFailure", NWScript_EffectSpellFailure, 2);
	rb_define_method(cNWScript, "SpeakStringByStrRef", NWScript_SpeakStringByStrRef, 2);
	rb_define_method(cNWScript, "SetCutsceneMode", NWScript_SetCutsceneMode, 3);
	rb_define_method(cNWScript, "GetLastPCToCancelCutscene", NWScript_GetLastPCToCancelCutscene, 0);
	rb_define_method(cNWScript, "GetDialogSoundLength", NWScript_GetDialogSoundLength, 1);
	rb_define_method(cNWScript, "FadeFromBlack", NWScript_FadeFromBlack, 2);
	rb_define_method(cNWScript, "FadeToBlack", NWScript_FadeToBlack, 2);
	rb_define_method(cNWScript, "StopFade", NWScript_StopFade, 1);
	rb_define_method(cNWScript, "BlackScreen", NWScript_BlackScreen, 1);
	rb_define_method(cNWScript, "GetBaseAttackBonus", NWScript_GetBaseAttackBonus, 1);
	rb_define_method(cNWScript, "SetImmortal", NWScript_SetImmortal, 2);
	rb_define_method(cNWScript, "OpenInventory", NWScript_OpenInventory, 2);
	rb_define_method(cNWScript, "StoreCameraFacing", NWScript_StoreCameraFacing, 0);
	rb_define_method(cNWScript, "RestoreCameraFacing", NWScript_RestoreCameraFacing, 0);
	rb_define_method(cNWScript, "LevelUpHenchman", NWScript_LevelUpHenchman, 4);
	rb_define_method(cNWScript, "SetDroppableFlag", NWScript_SetDroppableFlag, 2);
	rb_define_method(cNWScript, "GetWeight", NWScript_GetWeight, 1);
	rb_define_method(cNWScript, "GetModuleItemAcquiredBy", NWScript_GetModuleItemAcquiredBy, 0);
	rb_define_method(cNWScript, "GetImmortal", NWScript_GetImmortal, 1);
	rb_define_method(cNWScript, "DoWhirlwindAttack", NWScript_DoWhirlwindAttack, 2);
	rb_define_method(cNWScript, "Get2DAString", NWScript_Get2DAString, 3);
	rb_define_method(cNWScript, "EffectEthereal", NWScript_EffectEthereal, 0);
	rb_define_method(cNWScript, "GetAILevel", NWScript_GetAILevel, 1);
	rb_define_method(cNWScript, "SetAILevel", NWScript_SetAILevel, 2);
	rb_define_method(cNWScript, "GetIsPossessedFamiliar", NWScript_GetIsPossessedFamiliar, 1);
	rb_define_method(cNWScript, "UnpossessFamiliar", NWScript_UnpossessFamiliar, 1);
	rb_define_method(cNWScript, "GetIsAreaInterior", NWScript_GetIsAreaInterior, 1);
	rb_define_method(cNWScript, "SendMessageToPCByStrRef", NWScript_SendMessageToPCByStrRef, 2);
	rb_define_method(cNWScript, "IncrementRemainingFeatUses", NWScript_IncrementRemainingFeatUses, 2);
	rb_define_method(cNWScript, "ExportSingleCharacter", NWScript_ExportSingleCharacter, 1);
	rb_define_method(cNWScript, "PlaySoundByStrRef", NWScript_PlaySoundByStrRef, 2);
	rb_define_method(cNWScript, "SetSubRace", NWScript_SetSubRace, 2);
	rb_define_method(cNWScript, "SetDeity", NWScript_SetDeity, 2);
	rb_define_method(cNWScript, "GetIsDMPossessed", NWScript_GetIsDMPossessed, 1);
	rb_define_method(cNWScript, "GetWeather", NWScript_GetWeather, 1);
	rb_define_method(cNWScript, "GetIsAreaNatural", NWScript_GetIsAreaNatural, 1);
	rb_define_method(cNWScript, "GetIsAreaAboveGround", NWScript_GetIsAreaAboveGround, 1);
	rb_define_method(cNWScript, "GetPCItemLastEquipped", NWScript_GetPCItemLastEquipped, 0);
	rb_define_method(cNWScript, "GetPCItemLastEquippedBy", NWScript_GetPCItemLastEquippedBy, 0);
	rb_define_method(cNWScript, "GetPCItemLastUnequipped", NWScript_GetPCItemLastUnequipped, 0);
	rb_define_method(cNWScript, "GetPCItemLastUnequippedBy", NWScript_GetPCItemLastUnequippedBy, 0);
	rb_define_method(cNWScript, "CopyItemAndModify", NWScript_CopyItemAndModify, 5);
	rb_define_method(cNWScript, "GetItemAppearance", NWScript_GetItemAppearance, 3);
	rb_define_method(cNWScript, "ItemPropertyOnHitCastSpell", NWScript_ItemPropertyOnHitCastSpell, 2);
	rb_define_method(cNWScript, "GetItemPropertySubType", NWScript_GetItemPropertySubType, 1);
	rb_define_method(cNWScript, "GetActionMode", NWScript_GetActionMode, 2);
	rb_define_method(cNWScript, "SetActionMode", NWScript_SetActionMode, 3);
	rb_define_method(cNWScript, "GetArcaneSpellFailure", NWScript_GetArcaneSpellFailure, 1);
	rb_define_method(cNWScript, "ActionExamine", NWScript_ActionExamine, 1);
	rb_define_method(cNWScript, "ItemPropertyVisualEffect", NWScript_ItemPropertyVisualEffect, 1);
	rb_define_method(cNWScript, "SetLootable", NWScript_SetLootable, 2);
	rb_define_method(cNWScript, "GetLootable", NWScript_GetLootable, 1);
	rb_define_method(cNWScript, "GetCutsceneCameraMoveRate", NWScript_GetCutsceneCameraMoveRate, 1);
	rb_define_method(cNWScript, "SetCutsceneCameraMoveRate", NWScript_SetCutsceneCameraMoveRate, 2);
	rb_define_method(cNWScript, "GetItemCursedFlag", NWScript_GetItemCursedFlag, 1);
	rb_define_method(cNWScript, "SetItemCursedFlag", NWScript_SetItemCursedFlag, 2);
	rb_define_method(cNWScript, "SetMaxHenchmen", NWScript_SetMaxHenchmen, 1);
	rb_define_method(cNWScript, "GetMaxHenchmen", NWScript_GetMaxHenchmen, 0);
	rb_define_method(cNWScript, "GetAssociateType", NWScript_GetAssociateType, 1);
	rb_define_method(cNWScript, "GetSpellResistance", NWScript_GetSpellResistance, 1);
	rb_define_method(cNWScript, "DayToNight", NWScript_DayToNight, 2);
	rb_define_method(cNWScript, "NightToDay", NWScript_NightToDay, 2);
	rb_define_method(cNWScript, "LineOfSightObject", NWScript_LineOfSightObject, 2);
	rb_define_method(cNWScript, "LineOfSightVector", NWScript_LineOfSightVector, 2);
	rb_define_method(cNWScript, "GetLastSpellCastClass", NWScript_GetLastSpellCastClass, 0);
	rb_define_method(cNWScript, "SetBaseAttackBonus", NWScript_SetBaseAttackBonus, 2);
	rb_define_method(cNWScript, "RestoreBaseAttackBonus", NWScript_RestoreBaseAttackBonus, 1);
	rb_define_method(cNWScript, "EffectCutsceneGhost", NWScript_EffectCutsceneGhost, 0);
	rb_define_method(cNWScript, "ItemPropertyArcaneSpellFailure", NWScript_ItemPropertyArcaneSpellFailure, 1);
	rb_define_method(cNWScript, "GetStoreGold", NWScript_GetStoreGold, 1);
	rb_define_method(cNWScript, "SetStoreGold", NWScript_SetStoreGold, 2);
	rb_define_method(cNWScript, "GetStoreMaxBuyPrice", NWScript_GetStoreMaxBuyPrice, 1);
	rb_define_method(cNWScript, "SetStoreMaxBuyPrice", NWScript_SetStoreMaxBuyPrice, 2);
	rb_define_method(cNWScript, "GetStoreIdentifyCost", NWScript_GetStoreIdentifyCost, 1);
	rb_define_method(cNWScript, "SetStoreIdentifyCost", NWScript_SetStoreIdentifyCost, 2);
	rb_define_method(cNWScript, "SetCreatureAppearanceType", NWScript_SetCreatureAppearanceType, 2);
	rb_define_method(cNWScript, "GetCreatureStartingPackage", NWScript_GetCreatureStartingPackage, 1);
	rb_define_method(cNWScript, "EffectCutsceneImmobilize", NWScript_EffectCutsceneImmobilize, 0);
	rb_define_method(cNWScript, "GetIsInSubArea", NWScript_GetIsInSubArea, 2);
	rb_define_method(cNWScript, "GetItemPropertyCostTable", NWScript_GetItemPropertyCostTable, 1);
	rb_define_method(cNWScript, "GetItemPropertyCostTableValue", NWScript_GetItemPropertyCostTableValue, 1);
	rb_define_method(cNWScript, "GetItemPropertyParam1", NWScript_GetItemPropertyParam1, 1);
	rb_define_method(cNWScript, "GetItemPropertyParam1Value", NWScript_GetItemPropertyParam1Value, 1);
	rb_define_method(cNWScript, "GetIsCreatureDisarmable", NWScript_GetIsCreatureDisarmable, 1);
	rb_define_method(cNWScript, "SetStolenFlag", NWScript_SetStolenFlag, 2);
	rb_define_method(cNWScript, "ForceRest", NWScript_ForceRest, 1);
	rb_define_method(cNWScript, "SetCameraHeight", NWScript_SetCameraHeight, 2);
	rb_define_method(cNWScript, "SetSkyBox", NWScript_SetSkyBox, 2);
	rb_define_method(cNWScript, "GetPhenoType", NWScript_GetPhenoType, 1);
	rb_define_method(cNWScript, "SetPhenoType", NWScript_SetPhenoType, 2);
	rb_define_method(cNWScript, "SetFogColor", NWScript_SetFogColor, 3);
	rb_define_method(cNWScript, "GetCutsceneMode", NWScript_GetCutsceneMode, 1);
	rb_define_method(cNWScript, "GetSkyBox", NWScript_GetSkyBox, 1);
	rb_define_method(cNWScript, "GetFogColor", NWScript_GetFogColor, 2);
	rb_define_method(cNWScript, "SetFogAmount", NWScript_SetFogAmount, 3);
	rb_define_method(cNWScript, "GetFogAmount", NWScript_GetFogAmount, 2);
	rb_define_method(cNWScript, "GetPickpocketableFlag", NWScript_GetPickpocketableFlag, 1);
	rb_define_method(cNWScript, "SetPickpocketableFlag", NWScript_SetPickpocketableFlag, 2);
	rb_define_method(cNWScript, "GetFootstepType", NWScript_GetFootstepType, 1);
	rb_define_method(cNWScript, "SetFootstepType", NWScript_SetFootstepType, 2);
	rb_define_method(cNWScript, "GetCreatureWingType", NWScript_GetCreatureWingType, 1);
	rb_define_method(cNWScript, "SetCreatureWingType", NWScript_SetCreatureWingType, 2);
	rb_define_method(cNWScript, "GetCreatureBodyPart", NWScript_GetCreatureBodyPart, 2);
	rb_define_method(cNWScript, "SetCreatureBodyPart", NWScript_SetCreatureBodyPart, 3);
	rb_define_method(cNWScript, "GetCreatureTailType", NWScript_GetCreatureTailType, 1);
	rb_define_method(cNWScript, "SetCreatureTailType", NWScript_SetCreatureTailType, 2);
	rb_define_method(cNWScript, "GetHardness", NWScript_GetHardness, 1);
	rb_define_method(cNWScript, "SetHardness", NWScript_SetHardness, 2);
	rb_define_method(cNWScript, "SetLockKeyRequired", NWScript_SetLockKeyRequired, 2);
	rb_define_method(cNWScript, "SetLockKeyTag", NWScript_SetLockKeyTag, 2);
	rb_define_method(cNWScript, "SetLockLockable", NWScript_SetLockLockable, 2);
	rb_define_method(cNWScript, "SetLockUnlockDC", NWScript_SetLockUnlockDC, 2);
	rb_define_method(cNWScript, "SetLockLockDC", NWScript_SetLockLockDC, 2);
	rb_define_method(cNWScript, "SetTrapDisarmable", NWScript_SetTrapDisarmable, 2);
	rb_define_method(cNWScript, "SetTrapDetectable", NWScript_SetTrapDetectable, 2);
	rb_define_method(cNWScript, "SetTrapOneShot", NWScript_SetTrapOneShot, 2);
	rb_define_method(cNWScript, "SetTrapKeyTag", NWScript_SetTrapKeyTag, 2);
	rb_define_method(cNWScript, "SetTrapDisarmDC", NWScript_SetTrapDisarmDC, 2);
	rb_define_method(cNWScript, "SetTrapDetectDC", NWScript_SetTrapDetectDC, 2);
	rb_define_method(cNWScript, "CreateTrapAtLocation", NWScript_CreateTrapAtLocation, 7);
	rb_define_method(cNWScript, "CreateTrapOnObject", NWScript_CreateTrapOnObject, 5);
	rb_define_method(cNWScript, "SetWillSavingThrow", NWScript_SetWillSavingThrow, 2);
	rb_define_method(cNWScript, "SetReflexSavingThrow", NWScript_SetReflexSavingThrow, 2);
	rb_define_method(cNWScript, "SetFortitudeSavingThrow", NWScript_SetFortitudeSavingThrow, 2);
	rb_define_method(cNWScript, "GetTilesetResRef", NWScript_GetTilesetResRef, 1);
	rb_define_method(cNWScript, "GetTrapRecoverable", NWScript_GetTrapRecoverable, 1);
	rb_define_method(cNWScript, "SetTrapRecoverable", NWScript_SetTrapRecoverable, 2);
	rb_define_method(cNWScript, "GetModuleXPScale", NWScript_GetModuleXPScale, 0);
	rb_define_method(cNWScript, "SetModuleXPScale", NWScript_SetModuleXPScale, 1);
	rb_define_method(cNWScript, "GetKeyRequiredFeedback", NWScript_GetKeyRequiredFeedback, 1);
	rb_define_method(cNWScript, "SetKeyRequiredFeedback", NWScript_SetKeyRequiredFeedback, 2);
	rb_define_method(cNWScript, "GetTrapActive", NWScript_GetTrapActive, 1);
	rb_define_method(cNWScript, "SetTrapActive", NWScript_SetTrapActive, 2);
	rb_define_method(cNWScript, "LockCameraPitch", NWScript_LockCameraPitch, 2);
	rb_define_method(cNWScript, "LockCameraDistance", NWScript_LockCameraDistance, 2);
	rb_define_method(cNWScript, "LockCameraDirection", NWScript_LockCameraDirection, 2);
	rb_define_method(cNWScript, "GetPlaceableLastClickedBy", NWScript_GetPlaceableLastClickedBy, 0);
	rb_define_method(cNWScript, "GetInfiniteFlag", NWScript_GetInfiniteFlag, 1);
	rb_define_method(cNWScript, "SetInfiniteFlag", NWScript_SetInfiniteFlag, 2);
	rb_define_method(cNWScript, "GetAreaSize", NWScript_GetAreaSize, 2);
	rb_define_method(cNWScript, "SetName", NWScript_SetName, 2);
	rb_define_method(cNWScript, "GetPortraitId", NWScript_GetPortraitId, 1);
	rb_define_method(cNWScript, "SetPortraitId", NWScript_SetPortraitId, 2);
	rb_define_method(cNWScript, "GetPortraitResRef", NWScript_GetPortraitResRef, 1);
	rb_define_method(cNWScript, "SetPortraitResRef", NWScript_SetPortraitResRef, 2);
	rb_define_method(cNWScript, "SetUseableFlag", NWScript_SetUseableFlag, 2);
	rb_define_method(cNWScript, "GetDescription", NWScript_GetDescription, 3);
	rb_define_method(cNWScript, "SetDescription", NWScript_SetDescription, 3);
	rb_define_method(cNWScript, "GetPCChatSpeaker", NWScript_GetPCChatSpeaker, 0);
	rb_define_method(cNWScript, "GetPCChatMessage", NWScript_GetPCChatMessage, 0);
	rb_define_method(cNWScript, "GetPCChatVolume", NWScript_GetPCChatVolume, 0);
	rb_define_method(cNWScript, "SetPCChatMessage", NWScript_SetPCChatMessage, 1);
	rb_define_method(cNWScript, "SetPCChatVolume", NWScript_SetPCChatVolume, 1);
	rb_define_method(cNWScript, "GetColor", NWScript_GetColor, 2);
	rb_define_method(cNWScript, "SetColor", NWScript_SetColor, 3);
	rb_define_method(cNWScript, "ItemPropertyMaterial", NWScript_ItemPropertyMaterial, 1);
	rb_define_method(cNWScript, "ItemPropertyQuality", NWScript_ItemPropertyQuality, 1);
	rb_define_method(cNWScript, "ItemPropertyAdditional", NWScript_ItemPropertyAdditional, 1);
	return cNWScript;
}

