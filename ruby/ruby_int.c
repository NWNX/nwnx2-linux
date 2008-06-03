#include "FunctionHooks.h"
#include "ruby_int.h"
#include "ruby/ruby.h"

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
	StackPushString(rb_str2cstr(sString, NULL));
	VM_ExecuteCommand(1, 1);
	return Qnil;
}

static VALUE NWScript_PrintFloat(int argc, VALUE *argv, VALUE self)
{
	VALUE fFloat, nWidth, nDecimals;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	fFloat = argv[0];
	if(argc>1) nWidth = argv[1];
	else nWidth = INT2NUM(18);
	if(argc>2) nDecimals = argv[2];
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
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	fFloat = argv[0];
	if(argc>1) nWidth = argv[1];
	else nWidth = INT2NUM(18);
	if(argc>2) nDecimals = argv[2];
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
	StackPushString(rb_str2cstr(sScript, NULL));
	VM_ExecuteCommand(8, 2);
	return Qnil;
}

static VALUE NWScript_ClearAllActions(int argc, VALUE *argv, VALUE self)
{
	VALUE nClearCombatState;
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) nClearCombatState = argv[0];
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

static VALUE NWScript_GetCalendarYear()
{
	VM_ExecuteCommand(13, 0);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetCalendarMonth()
{
	VM_ExecuteCommand(14, 0);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetCalendarDay()
{
	VM_ExecuteCommand(15, 0);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetTimeHour()
{
	VM_ExecuteCommand(16, 0);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetTimeMinute()
{
	VM_ExecuteCommand(17, 0);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetTimeSecond()
{
	VM_ExecuteCommand(18, 0);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetTimeMillisecond()
{
	VM_ExecuteCommand(19, 0);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_ActionRandomWalk()
{
	VM_ExecuteCommand(20, 0);
	return Qnil;
}

static VALUE NWScript_ActionMoveToLocation(int argc, VALUE *argv, VALUE self)
{
	VALUE lDestination, bRun;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	lDestination = argv[0];
	if(argc>1) bRun = argv[1];
	else bRun = INT2NUM(FALSE);
	StackPushInteger(NUM2INT(bRun));
	//ERROR: Undefined variable type: location
	VM_ExecuteCommand(21, 2);
	return Qnil;
}

static VALUE NWScript_ActionMoveToObject(int argc, VALUE *argv, VALUE self)
{
	VALUE oMoveTo, bRun, fRange;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oMoveTo = argv[0];
	if(argc>1) bRun = argv[1];
	else bRun = INT2NUM(FALSE);
	if(argc>2) fRange = argv[2];
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
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oFleeFrom = argv[0];
	if(argc>1) bRun = argv[1];
	else bRun = INT2NUM(FALSE);
	if(argc>2) fMoveAwayRange = argv[2];
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

static VALUE NWScript_GetEnteringObject()
{
	VM_ExecuteCommand(25, 0);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetExitingObject()
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
//ERROR: Undefined variable type: vector
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
	StackPushString(rb_str2cstr(sItemTag, NULL));
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(30, 2);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_CreateItemOnObject(int argc, VALUE *argv, VALUE self)
{
	VALUE sItemTemplate, oTarget, nStackSize, sNewTag;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	sItemTemplate = argv[0];
	if(argc>1) oTarget = argv[1];
	else oTarget = INT2NUM(OBJECT_SELF);
	if(argc>2) nStackSize = argv[2];
	else nStackSize = INT2NUM(1);
	if(argc>3) sNewTag = argv[3];
	else sNewTag = rb_str_new2("");
	StackPushString(rb_str2cstr(sNewTag, NULL));
	StackPushInteger(NUM2INT(nStackSize));
	StackPushObject(NUM2UINT(oTarget));
	StackPushString(rb_str2cstr(sItemTemplate, NULL));
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
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oAttackee = argv[0];
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
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oAttackee = argv[0];
	if(argc>1) bPassive = argv[1];
	else bPassive = INT2NUM(FALSE);
	StackPushInteger(NUM2INT(bPassive));
	StackPushObject(NUM2UINT(oAttackee));
	VM_ExecuteCommand(37, 2);
	return Qnil;
}

static VALUE NWScript_GetNearestCreature(int argc, VALUE *argv, VALUE self)
{
	VALUE nFirstCriteriaType, nFirstCriteriaValue, oTarget, nNth, nSecondCriteriaType, nSecondCriteriaValue, nThirdCriteriaType, nThirdCriteriaValue;
	if(argc < 2)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nFirstCriteriaType = argv[0];
	nFirstCriteriaValue = argv[1];
	if(argc>2) oTarget = argv[2];
	else oTarget = INT2NUM(OBJECT_SELF);
	if(argc>3) nNth = argv[3];
	else nNth = INT2NUM(1);
	if(argc>4) nSecondCriteriaType = argv[4];
	else nSecondCriteriaType = INT2NUM(-1);
	if(argc>5) nSecondCriteriaValue = argv[5];
	else nSecondCriteriaValue = INT2NUM(-1);
	if(argc>6) nThirdCriteriaType = argv[6];
	else nThirdCriteriaType = INT2NUM(-1);
	if(argc>7) nThirdCriteriaValue = argv[7];
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
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	sStringToSpeak = argv[0];
	if(argc>1) nTalkVolume = argv[1];
	else nTalkVolume = INT2NUM(TALKVOLUME_TALK);
	StackPushInteger(NUM2INT(nTalkVolume));
	StackPushString(rb_str2cstr(sStringToSpeak, NULL));
	VM_ExecuteCommand(39, 2);
	return Qnil;
}

static VALUE NWScript_ActionPlayAnimation(int argc, VALUE *argv, VALUE self)
{
	VALUE nAnimation, fSpeed, fDurationSeconds;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nAnimation = argv[0];
	if(argc>1) fSpeed = argv[1];
	else fSpeed = rb_float_new(1.0);
	if(argc>2) fDurationSeconds = argv[2];
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
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	fDirection = argv[0];
	if(argc>1) fDistance  = argv[1];
	else fDistance  = rb_float_new( -1.0f);
	if(argc>2) fPitch  = argv[2];
	else fPitch  = rb_float_new( -1.0);
	if(argc>3) nTransitionType = argv[3];
	else nTransitionType = INT2NUM(CAMERA_TRANSITION_TYPE_SNAP);
	StackPushInteger(NUM2INT(nTransitionType));
	StackPushFloat(NUM2DBL(fPitch ));
	StackPushFloat(NUM2DBL(fDistance ));
	StackPushFloat(NUM2DBL(fDirection));
	VM_ExecuteCommand(45, 4);
	return Qnil;
}

static VALUE NWScript_PlaySound(VALUE self, VALUE sSoundName)
{
	StackPushString(rb_str2cstr(sSoundName, NULL));
	VM_ExecuteCommand(46, 1);
	return Qnil;
}

static VALUE NWScript_GetSpellTargetObject()
{
	VM_ExecuteCommand(47, 0);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_ActionCastSpellAtObject(int argc, VALUE *argv, VALUE self)
{
	VALUE nSpell, oTarget, nMetaMagic, bCheat, nDomainLevel, nProjectilePathType, bInstantSpell;
	if(argc < 2)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nSpell = argv[0];
	oTarget = argv[1];
	if(argc>2) nMetaMagic = argv[2];
	else nMetaMagic = INT2NUM(METAMAGIC_ANY);
	if(argc>3) bCheat = argv[3];
	else bCheat = INT2NUM(FALSE);
	if(argc>4) nDomainLevel = argv[4];
	else nDomainLevel = INT2NUM(0);
	if(argc>5) nProjectilePathType = argv[5];
	else nProjectilePathType = INT2NUM(PROJECTILE_PATH_TYPE_DEFAULT);
	if(argc>6) bInstantSpell = argv[6];
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
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oObject = argv[0];
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
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oObject = argv[0];
	else oObject = INT2NUM(OBJECT_SELF);
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(50, 1);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLocalInt(VALUE self, VALUE oObject, VALUE sVarName)
{
	StackPushString(rb_str2cstr(sVarName, NULL));
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(51, 2);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLocalFloat(VALUE self, VALUE oObject, VALUE sVarName)
{
	StackPushString(rb_str2cstr(sVarName, NULL));
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(52, 2);
	float fRetVal;
	StackPopFloat(&fRetVal);
	return rb_float_new(fRetVal);
}

static VALUE NWScript_GetLocalString(VALUE self, VALUE oObject, VALUE sVarName)
{
	StackPushString(rb_str2cstr(sVarName, NULL));
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(53, 2);
	char *sRetVal;
	StackPopString(&sRetVal);
	return rb_str_new2(sRetVal);
}

static VALUE NWScript_GetLocalObject(VALUE self, VALUE oObject, VALUE sVarName)
{
	StackPushString(rb_str2cstr(sVarName, NULL));
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(54, 2);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_SetLocalInt(VALUE self, VALUE oObject, VALUE sVarName, VALUE nValue)
{
	StackPushInteger(NUM2INT(nValue));
	StackPushString(rb_str2cstr(sVarName, NULL));
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(55, 3);
	return Qnil;
}

static VALUE NWScript_SetLocalFloat(VALUE self, VALUE oObject, VALUE sVarName, VALUE fValue)
{
	StackPushFloat(NUM2DBL(fValue));
	StackPushString(rb_str2cstr(sVarName, NULL));
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(56, 3);
	return Qnil;
}

static VALUE NWScript_SetLocalString(VALUE self, VALUE oObject, VALUE sVarName, VALUE sValue)
{
	StackPushString(rb_str2cstr(sValue, NULL));
	StackPushString(rb_str2cstr(sVarName, NULL));
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(57, 3);
	return Qnil;
}

static VALUE NWScript_SetLocalObject(VALUE self, VALUE oObject, VALUE sVarName, VALUE oValue)
{
	StackPushObject(NUM2UINT(oValue));
	StackPushString(rb_str2cstr(sVarName, NULL));
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(58, 3);
	return Qnil;
}

static VALUE NWScript_GetStringLength(VALUE self, VALUE sString)
{
	StackPushString(rb_str2cstr(sString, NULL));
	VM_ExecuteCommand(59, 1);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetStringUpperCase(VALUE self, VALUE sString)
{
	StackPushString(rb_str2cstr(sString, NULL));
	VM_ExecuteCommand(60, 1);
	char *sRetVal;
	StackPopString(&sRetVal);
	return rb_str_new2(sRetVal);
}

static VALUE NWScript_GetStringLowerCase(VALUE self, VALUE sString)
{
	StackPushString(rb_str2cstr(sString, NULL));
	VM_ExecuteCommand(61, 1);
	char *sRetVal;
	StackPopString(&sRetVal);
	return rb_str_new2(sRetVal);
}

static VALUE NWScript_GetStringRight(VALUE self, VALUE sString, VALUE nCount)
{
	StackPushInteger(NUM2INT(nCount));
	StackPushString(rb_str2cstr(sString, NULL));
	VM_ExecuteCommand(62, 2);
	char *sRetVal;
	StackPopString(&sRetVal);
	return rb_str_new2(sRetVal);
}

static VALUE NWScript_GetStringLeft(VALUE self, VALUE sString, VALUE nCount)
{
	StackPushInteger(NUM2INT(nCount));
	StackPushString(rb_str2cstr(sString, NULL));
	VM_ExecuteCommand(63, 2);
	char *sRetVal;
	StackPopString(&sRetVal);
	return rb_str_new2(sRetVal);
}

static VALUE NWScript_InsertString(VALUE self, VALUE sDestination, VALUE sString, VALUE nPosition)
{
	StackPushInteger(NUM2INT(nPosition));
	StackPushString(rb_str2cstr(sString, NULL));
	StackPushString(rb_str2cstr(sDestination, NULL));
	VM_ExecuteCommand(64, 3);
	char *sRetVal;
	StackPopString(&sRetVal);
	return rb_str_new2(sRetVal);
}

static VALUE NWScript_GetSubString(VALUE self, VALUE sString, VALUE nStart, VALUE nCount)
{
	StackPushInteger(NUM2INT(nCount));
	StackPushInteger(NUM2INT(nStart));
	StackPushString(rb_str2cstr(sString, NULL));
	VM_ExecuteCommand(65, 3);
	char *sRetVal;
	StackPopString(&sRetVal);
	return rb_str_new2(sRetVal);
}

static VALUE NWScript_FindSubString(int argc, VALUE *argv, VALUE self)
{
	VALUE sString, sSubString, nStart;
	if(argc < 2)
	{
		//TODO: Raise exception
		return Qnil;
	}
	sString = argv[0];
	sSubString = argv[1];
	if(argc>2) nStart = argv[2];
	else nStart = INT2NUM(0);
	StackPushInteger(NUM2INT(nStart));
	StackPushString(rb_str2cstr(sSubString, NULL));
	StackPushString(rb_str2cstr(sString, NULL));
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
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectDamage(int argc, VALUE *argv, VALUE self)
{
	VALUE nDamageAmount, nDamageType, nDamagePower;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nDamageAmount = argv[0];
	if(argc>1) nDamageType = argv[1];
	else nDamageType = INT2NUM(DAMAGE_TYPE_MAGICAL);
	if(argc>2) nDamagePower = argv[2];
	else nDamagePower = INT2NUM(DAMAGE_POWER_NORMAL);
	StackPushInteger(NUM2INT(nDamagePower));
	StackPushInteger(NUM2INT(nDamageType));
	StackPushInteger(NUM2INT(nDamageAmount));
	VM_ExecuteCommand(79, 3);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectAbilityIncrease(VALUE self, VALUE nAbilityToIncrease, VALUE nModifyBy)
{
	StackPushInteger(NUM2INT(nModifyBy));
	StackPushInteger(NUM2INT(nAbilityToIncrease));
	VM_ExecuteCommand(80, 2);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectDamageResistance(int argc, VALUE *argv, VALUE self)
{
	VALUE nDamageType, nAmount, nLimit;
	if(argc < 2)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nDamageType = argv[0];
	nAmount = argv[1];
	if(argc>2) nLimit = argv[2];
	else nLimit = INT2NUM(0);
	StackPushInteger(NUM2INT(nLimit));
	StackPushInteger(NUM2INT(nAmount));
	StackPushInteger(NUM2INT(nDamageType));
	VM_ExecuteCommand(81, 3);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectResurrection()
{
	VM_ExecuteCommand(82, 0);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectSummonCreature(int argc, VALUE *argv, VALUE self)
{
	VALUE sCreatureResref, nVisualEffectId, fDelaySeconds, nUseAppearAnimation;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	sCreatureResref = argv[0];
	if(argc>1) nVisualEffectId = argv[1];
	else nVisualEffectId = INT2NUM(VFX_NONE);
	if(argc>2) fDelaySeconds = argv[2];
	else fDelaySeconds = rb_float_new(0.0f);
	if(argc>3) nUseAppearAnimation = argv[3];
	else nUseAppearAnimation = INT2NUM(0);
	StackPushInteger(NUM2INT(nUseAppearAnimation));
	StackPushFloat(NUM2DBL(fDelaySeconds));
	StackPushInteger(NUM2INT(nVisualEffectId));
	StackPushString(rb_str2cstr(sCreatureResref, NULL));
	VM_ExecuteCommand(83, 4);
//ERROR: Undefined variable type: effect
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
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_GetNextEffect(VALUE self, VALUE oCreature)
{
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(86, 1);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_RemoveEffect(VALUE self, VALUE oCreature, VALUE eEffect)
{
	//ERROR: Undefined variable type: effect
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(87, 2);
	return Qnil;
}

static VALUE NWScript_GetIsEffectValid(VALUE self, VALUE eEffect)
{
	//ERROR: Undefined variable type: effect
	VM_ExecuteCommand(88, 1);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetEffectDurationType(VALUE self, VALUE eEffect)
{
	//ERROR: Undefined variable type: effect
	VM_ExecuteCommand(89, 1);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetEffectSubType(VALUE self, VALUE eEffect)
{
	//ERROR: Undefined variable type: effect
	VM_ExecuteCommand(90, 1);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetEffectCreator(VALUE self, VALUE eEffect)
{
	//ERROR: Undefined variable type: effect
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
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oArea = argv[0];
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
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oArea = argv[0];
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
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) nNumDice = argv[0];
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
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) nNumDice = argv[0];
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
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) nNumDice = argv[0];
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
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) nNumDice = argv[0];
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
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) nNumDice = argv[0];
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
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) nNumDice = argv[0];
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
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) nNumDice = argv[0];
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
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) nNumDice = argv[0];
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
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) nNumDice = argv[0];
	else nNumDice = INT2NUM(1);
	StackPushInteger(NUM2INT(nNumDice));
	VM_ExecuteCommand(103, 1);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_VectorMagnitude(VALUE self, VALUE vVector)
{
	//ERROR: Undefined variable type: vector
	VM_ExecuteCommand(104, 1);
	float fRetVal;
	StackPopFloat(&fRetVal);
	return rb_float_new(fRetVal);
}

static VALUE NWScript_GetMetaMagicFeat()
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
	if(argc < 2)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oCreature = argv[0];
	nDC = argv[1];
	if(argc>2) nSaveType = argv[2];
	else nSaveType = INT2NUM(SAVING_THROW_TYPE_NONE);
	if(argc>3) oSaveVersus = argv[3];
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
	if(argc < 2)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oCreature = argv[0];
	nDC = argv[1];
	if(argc>2) nSaveType = argv[2];
	else nSaveType = INT2NUM(SAVING_THROW_TYPE_NONE);
	if(argc>3) oSaveVersus = argv[3];
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
	if(argc < 2)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oCreature = argv[0];
	nDC = argv[1];
	if(argc>2) nSaveType = argv[2];
	else nSaveType = INT2NUM(SAVING_THROW_TYPE_NONE);
	if(argc>3) oSaveVersus = argv[3];
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

static VALUE NWScript_GetSpellSaveDC()
{
	VM_ExecuteCommand(111, 0);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_MagicalEffect(VALUE self, VALUE eEffect)
{
	//ERROR: Undefined variable type: effect
	VM_ExecuteCommand(112, 1);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_SupernaturalEffect(VALUE self, VALUE eEffect)
{
	//ERROR: Undefined variable type: effect
	VM_ExecuteCommand(113, 1);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_ExtraordinaryEffect(VALUE self, VALUE eEffect)
{
	//ERROR: Undefined variable type: effect
	VM_ExecuteCommand(114, 1);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectACIncrease(int argc, VALUE *argv, VALUE self)
{
	VALUE nValue, nModifyType, nDamageType;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nValue = argv[0];
	if(argc>1) nModifyType = argv[1];
	else nModifyType = INT2NUM(AC_DODGE_BONUS);
	if(argc>2) nDamageType = argv[2];
	else nDamageType = INT2NUM(AC_VS_DAMAGE_TYPE_ALL);
	StackPushInteger(NUM2INT(nDamageType));
	StackPushInteger(NUM2INT(nModifyType));
	StackPushInteger(NUM2INT(nValue));
	VM_ExecuteCommand(115, 3);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_GetAC(int argc, VALUE *argv, VALUE self)
{
	VALUE oObject, nForFutureUse;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oObject = argv[0];
	if(argc>1) nForFutureUse = argv[1];
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
	if(argc < 2)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nSave = argv[0];
	nValue = argv[1];
	if(argc>2) nSaveType = argv[2];
	else nSaveType = INT2NUM(SAVING_THROW_TYPE_ALL);
	StackPushInteger(NUM2INT(nSaveType));
	StackPushInteger(NUM2INT(nValue));
	StackPushInteger(NUM2INT(nSave));
	VM_ExecuteCommand(117, 3);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectAttackIncrease(int argc, VALUE *argv, VALUE self)
{
	VALUE nBonus, nModifierType;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nBonus = argv[0];
	if(argc>1) nModifierType = argv[1];
	else nModifierType = INT2NUM(ATTACK_BONUS_MISC);
	StackPushInteger(NUM2INT(nModifierType));
	StackPushInteger(NUM2INT(nBonus));
	VM_ExecuteCommand(118, 2);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectDamageReduction(int argc, VALUE *argv, VALUE self)
{
	VALUE nAmount, nDamagePower, nLimit;
	if(argc < 2)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nAmount = argv[0];
	nDamagePower = argv[1];
	if(argc>2) nLimit = argv[2];
	else nLimit = INT2NUM(0);
	StackPushInteger(NUM2INT(nLimit));
	StackPushInteger(NUM2INT(nDamagePower));
	StackPushInteger(NUM2INT(nAmount));
	VM_ExecuteCommand(119, 3);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectDamageIncrease(int argc, VALUE *argv, VALUE self)
{
	VALUE nBonus, nDamageType;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nBonus = argv[0];
	if(argc>1) nDamageType = argv[1];
	else nDamageType = INT2NUM(DAMAGE_TYPE_MAGICAL);
	StackPushInteger(NUM2INT(nDamageType));
	StackPushInteger(NUM2INT(nBonus));
	VM_ExecuteCommand(120, 2);
//ERROR: Undefined variable type: effect
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

static VALUE NWScript_EffectEntangle()
{
	VM_ExecuteCommand(130, 0);
//ERROR: Undefined variable type: effect
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
}

static VALUE NWScript_EffectDeath(int argc, VALUE *argv, VALUE self)
{
	VALUE nSpectacularDeath, nDisplayFeedback;
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) nSpectacularDeath = argv[0];
	else nSpectacularDeath = INT2NUM(FALSE);
	if(argc>1) nDisplayFeedback = argv[1];
	else nDisplayFeedback = INT2NUM(TRUE);
	StackPushInteger(NUM2INT(nDisplayFeedback));
	StackPushInteger(NUM2INT(nSpectacularDeath));
	VM_ExecuteCommand(133, 2);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectKnockdown()
{
	VM_ExecuteCommand(134, 0);
//ERROR: Undefined variable type: effect
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
	//ERROR: Undefined variable type: vector
	VM_ExecuteCommand(137, 1);
//ERROR: Undefined variable type: vector
}

static VALUE NWScript_EffectCurse(int argc, VALUE *argv, VALUE self)
{
	VALUE nStrMod, nDexMod, nConMod, nIntMod, nWisMod, nChaMod;
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) nStrMod = argv[0];
	else nStrMod = INT2NUM(1);
	if(argc>1) nDexMod = argv[1];
	else nDexMod = INT2NUM(1);
	if(argc>2) nConMod = argv[2];
	else nConMod = INT2NUM(1);
	if(argc>3) nIntMod = argv[3];
	else nIntMod = INT2NUM(1);
	if(argc>4) nWisMod = argv[4];
	else nWisMod = INT2NUM(1);
	if(argc>5) nChaMod = argv[5];
	else nChaMod = INT2NUM(1);
	StackPushInteger(NUM2INT(nChaMod));
	StackPushInteger(NUM2INT(nWisMod));
	StackPushInteger(NUM2INT(nIntMod));
	StackPushInteger(NUM2INT(nConMod));
	StackPushInteger(NUM2INT(nDexMod));
	StackPushInteger(NUM2INT(nStrMod));
	VM_ExecuteCommand(138, 6);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_GetAbilityScore(int argc, VALUE *argv, VALUE self)
{
	VALUE oCreature, nAbilityType, nBaseAbilityScore;
	if(argc < 2)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oCreature = argv[0];
	nAbilityType = argv[1];
	if(argc>2) nBaseAbilityScore = argv[2];
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
	//ERROR: Undefined variable type: vector
	VM_ExecuteCommand(141, 2);
	return Qnil;
}

static VALUE NWScript_Vector(int argc, VALUE *argv, VALUE self)
{
	VALUE x, y, z;
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) x = argv[0];
	else x = rb_float_new(0.0f);
	if(argc>1) y = argv[1];
	else y = rb_float_new(0.0f);
	if(argc>2) z = argv[2];
	else z = rb_float_new(0.0f);
	StackPushFloat(NUM2DBL(z));
	StackPushFloat(NUM2DBL(y));
	StackPushFloat(NUM2DBL(x));
	VM_ExecuteCommand(142, 3);
//ERROR: Undefined variable type: vector
}

static VALUE NWScript_SetFacingPoint(VALUE self, VALUE vTarget)
{
	//ERROR: Undefined variable type: vector
	VM_ExecuteCommand(143, 1);
	return Qnil;
}

static VALUE NWScript_AngleToVector(VALUE self, VALUE fAngle)
{
	StackPushFloat(NUM2DBL(fAngle));
	VM_ExecuteCommand(144, 1);
//ERROR: Undefined variable type: vector
}

static VALUE NWScript_VectorToAngle(VALUE self, VALUE vVector)
{
	//ERROR: Undefined variable type: vector
	VM_ExecuteCommand(145, 1);
	float fRetVal;
	StackPopFloat(&fRetVal);
	return rb_float_new(fRetVal);
}

static VALUE NWScript_TouchAttackMelee(int argc, VALUE *argv, VALUE self)
{
	VALUE oTarget, bDisplayFeedback;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oTarget = argv[0];
	if(argc>1) bDisplayFeedback = argv[1];
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
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oTarget = argv[0];
	if(argc>1) bDisplayFeedback = argv[1];
	else bDisplayFeedback = INT2NUM(TRUE);
	StackPushInteger(NUM2INT(bDisplayFeedback));
	StackPushObject(NUM2UINT(oTarget));
	VM_ExecuteCommand(147, 2);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_EffectParalyze()
{
	VM_ExecuteCommand(148, 0);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectSpellImmunity(int argc, VALUE *argv, VALUE self)
{
	VALUE nImmunityToSpell;
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) nImmunityToSpell = argv[0];
	else nImmunityToSpell = INT2NUM(SPELL_ALL_SPELLS);
	StackPushInteger(NUM2INT(nImmunityToSpell));
	VM_ExecuteCommand(149, 1);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectDeaf()
{
	VM_ExecuteCommand(150, 0);
//ERROR: Undefined variable type: effect
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
	//ERROR: Undefined variable type: location
	StackPushString(rb_str2cstr(sVarName, NULL));
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(152, 3);
	return Qnil;
}

static VALUE NWScript_GetLocalLocation(VALUE self, VALUE oObject, VALUE sVarName)
{
	StackPushString(rb_str2cstr(sVarName, NULL));
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(153, 2);
//ERROR: Undefined variable type: location
}

static VALUE NWScript_EffectSleep()
{
	VM_ExecuteCommand(154, 0);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_GetItemInSlot(int argc, VALUE *argv, VALUE self)
{
	VALUE nInventorySlot, oCreature;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nInventorySlot = argv[0];
	if(argc>1) oCreature = argv[1];
	else oCreature = INT2NUM(OBJECT_SELF);
	StackPushObject(NUM2UINT(oCreature));
	StackPushInteger(NUM2INT(nInventorySlot));
	VM_ExecuteCommand(155, 2);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_EffectCharmed()
{
	VM_ExecuteCommand(156, 0);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectConfused()
{
	VM_ExecuteCommand(157, 0);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectFrightened()
{
	VM_ExecuteCommand(158, 0);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectDominated()
{
	VM_ExecuteCommand(159, 0);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectDazed()
{
	VM_ExecuteCommand(160, 0);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectStunned()
{
	VM_ExecuteCommand(161, 0);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_SetCommandable(int argc, VALUE *argv, VALUE self)
{
	VALUE bCommandable, oTarget;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	bCommandable = argv[0];
	if(argc>1) oTarget = argv[1];
	else oTarget = INT2NUM(OBJECT_SELF);
	StackPushObject(NUM2UINT(oTarget));
	StackPushInteger(NUM2INT(bCommandable));
	VM_ExecuteCommand(162, 2);
	return Qnil;
}

static VALUE NWScript_GetCommandable(int argc, VALUE *argv, VALUE self)
{
	VALUE oTarget;
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oTarget = argv[0];
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
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectMovementSpeedIncrease(VALUE self, VALUE nPercentChange)
{
	StackPushInteger(NUM2INT(nPercentChange));
	VM_ExecuteCommand(165, 1);
//ERROR: Undefined variable type: effect
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
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oFollow = argv[0];
	if(argc>1) fFollowDistance = argv[1];
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
	//ERROR: Undefined variable type: effect
	VM_ExecuteCommand(170, 1);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_EffectAreaOfEffect(int argc, VALUE *argv, VALUE self)
{
	VALUE nAreaEffectId, sOnEnterScript, sHeartbeatScript, sOnExitScript;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nAreaEffectId = argv[0];
	if(argc>1) sOnEnterScript = argv[1];
	else sOnEnterScript = rb_str_new2("");
	if(argc>2) sHeartbeatScript = argv[2];
	else sHeartbeatScript = rb_str_new2("");
	if(argc>3) sOnExitScript = argv[3];
	else sOnExitScript = rb_str_new2("");
	StackPushString(rb_str2cstr(sOnExitScript, NULL));
	StackPushString(rb_str2cstr(sHeartbeatScript, NULL));
	StackPushString(rb_str2cstr(sOnEnterScript, NULL));
	StackPushInteger(NUM2INT(nAreaEffectId));
	VM_ExecuteCommand(171, 4);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_GetFactionEqual(int argc, VALUE *argv, VALUE self)
{
	VALUE oFirstObject, oSecondObject;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oFirstObject = argv[0];
	if(argc>1) oSecondObject = argv[1];
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
	if(argc < 2)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oObject = argv[0];
	sPattern = argv[1];
	if(argc>2) nNumber = argv[2];
	else nNumber = INT2NUM(0);
	StackPushInteger(NUM2INT(nNumber));
	StackPushString(rb_str2cstr(sPattern, NULL));
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(176, 3);
	return Qnil;
}

static VALUE NWScript_TestStringAgainstPattern(VALUE self, VALUE sPattern, VALUE sStringToTest)
{
	StackPushString(rb_str2cstr(sStringToTest, NULL));
	StackPushString(rb_str2cstr(sPattern, NULL));
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

static VALUE NWScript_GetMatchedSubstringsCount()
{
	VM_ExecuteCommand(179, 0);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_EffectVisualEffect(int argc, VALUE *argv, VALUE self)
{
	VALUE nVisualEffectId, nMissEffect;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nVisualEffectId = argv[0];
	if(argc>1) nMissEffect = argv[1];
	else nMissEffect = INT2NUM(FALSE);
	StackPushInteger(NUM2INT(nMissEffect));
	StackPushInteger(NUM2INT(nVisualEffectId));
	VM_ExecuteCommand(180, 2);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_GetFactionWeakestMember(int argc, VALUE *argv, VALUE self)
{
	VALUE oFactionMember, bMustBeVisible;
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oFactionMember = argv[0];
	else oFactionMember = INT2NUM(OBJECT_SELF);
	if(argc>1) bMustBeVisible = argv[1];
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
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oFactionMember = argv[0];
	else oFactionMember = INT2NUM(OBJECT_SELF);
	if(argc>1) bMustBeVisible = argv[1];
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
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oFactionMember = argv[0];
	else oFactionMember = INT2NUM(OBJECT_SELF);
	if(argc>1) bMustBeVisible = argv[1];
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
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oFactionMember = argv[0];
	else oFactionMember = INT2NUM(OBJECT_SELF);
	if(argc>1) bMustBeVisible = argv[1];
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
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oFactionMember = argv[0];
	else oFactionMember = INT2NUM(OBJECT_SELF);
	if(argc>1) bMustBeVisible = argv[1];
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
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oFactionMember = argv[0];
	else oFactionMember = INT2NUM(OBJECT_SELF);
	if(argc>1) bMustBeVisible = argv[1];
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

static VALUE NWScript_GetListenPatternNumber()
{
	VM_ExecuteCommand(195, 0);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_ActionJumpToObject(int argc, VALUE *argv, VALUE self)
{
	VALUE oToJumpTo, bWalkStraightLineToPoint;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oToJumpTo = argv[0];
	if(argc>1) bWalkStraightLineToPoint = argv[1];
	else bWalkStraightLineToPoint = INT2NUM(TRUE);
	StackPushInteger(NUM2INT(bWalkStraightLineToPoint));
	StackPushObject(NUM2UINT(oToJumpTo));
	VM_ExecuteCommand(196, 2);
	return Qnil;
}

static VALUE NWScript_GetWaypointByTag(VALUE self, VALUE sWaypointTag)
{
	StackPushString(rb_str2cstr(sWaypointTag, NULL));
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
	//ERROR: Undefined variable type: effect
	//ERROR: Undefined variable type: effect
	VM_ExecuteCommand(199, 2);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_GetObjectByTag(int argc, VALUE *argv, VALUE self)
{
	VALUE sTag, nNth;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	sTag = argv[0];
	if(argc>1) nNth = argv[1];
	else nNth = INT2NUM(0);
	StackPushInteger(NUM2INT(nNth));
	StackPushString(rb_str2cstr(sTag, NULL));
	VM_ExecuteCommand(200, 2);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_AdjustAlignment(int argc, VALUE *argv, VALUE self)
{
	VALUE oSubject, nAlignment, nShift, bAllPartyMembers;
	if(argc < 3)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oSubject = argv[0];
	nAlignment = argv[1];
	nShift = argv[2];
	if(argc>3) bAllPartyMembers = argv[3];
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
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nPredefinedAreaTransition = argv[0];
	if(argc>1) sCustomAreaTransitionBMP = argv[1];
	else sCustomAreaTransitionBMP = rb_str_new2("");
	StackPushString(rb_str2cstr(sCustomAreaTransitionBMP, NULL));
	StackPushInteger(NUM2INT(nPredefinedAreaTransition));
	VM_ExecuteCommand(203, 2);
	return Qnil;
}

static VALUE NWScript_ActionStartConversation(int argc, VALUE *argv, VALUE self)
{
	VALUE oObjectToConverseWith, sDialogResRef, bPrivateConversation, bPlayHello;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oObjectToConverseWith = argv[0];
	if(argc>1) sDialogResRef = argv[1];
	else sDialogResRef = rb_str_new2("");
	if(argc>2) bPrivateConversation = argv[2];
	else bPrivateConversation = INT2NUM(FALSE);
	if(argc>3) bPlayHello = argv[3];
	else bPlayHello = INT2NUM(TRUE);
	StackPushInteger(NUM2INT(bPlayHello));
	StackPushInteger(NUM2INT(bPrivateConversation));
	StackPushString(rb_str2cstr(sDialogResRef, NULL));
	StackPushObject(NUM2UINT(oObjectToConverseWith));
	VM_ExecuteCommand(204, 4);
	return Qnil;
}

static VALUE NWScript_ActionPauseConversation()
{
	VM_ExecuteCommand(205, 0);
	return Qnil;
}

static VALUE NWScript_ActionResumeConversation()
{
	VM_ExecuteCommand(206, 0);
	return Qnil;
}

static VALUE NWScript_EffectBeam(int argc, VALUE *argv, VALUE self)
{
	VALUE nBeamVisualEffect, oEffector, nBodyPart, bMissEffect;
	if(argc < 3)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nBeamVisualEffect = argv[0];
	oEffector = argv[1];
	nBodyPart = argv[2];
	if(argc>3) bMissEffect = argv[3];
	else bMissEffect = INT2NUM(FALSE);
	StackPushInteger(NUM2INT(bMissEffect));
	StackPushInteger(NUM2INT(nBodyPart));
	StackPushObject(NUM2UINT(oEffector));
	StackPushInteger(NUM2INT(nBeamVisualEffect));
	VM_ExecuteCommand(207, 4);
//ERROR: Undefined variable type: effect
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
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_GetLocation(VALUE self, VALUE oObject)
{
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(213, 1);
//ERROR: Undefined variable type: location
}

static VALUE NWScript_ActionJumpToLocation(VALUE self, VALUE lLocation)
{
	//ERROR: Undefined variable type: location
	VM_ExecuteCommand(214, 1);
	return Qnil;
}

static VALUE NWScript_Location(VALUE self, VALUE oArea, VALUE vPosition, VALUE fOrientation)
{
	StackPushFloat(NUM2DBL(fOrientation));
	//ERROR: Undefined variable type: vector
	StackPushObject(NUM2UINT(oArea));
	VM_ExecuteCommand(215, 3);
//ERROR: Undefined variable type: location
}

static VALUE NWScript_ApplyEffectAtLocation(int argc, VALUE *argv, VALUE self)
{
	VALUE nDurationType, eEffect, lLocation, fDuration;
	if(argc < 3)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nDurationType = argv[0];
	eEffect = argv[1];
	lLocation = argv[2];
	if(argc>3) fDuration = argv[3];
	else fDuration = rb_float_new(0.0f);
	StackPushFloat(NUM2DBL(fDuration));
	//ERROR: Undefined variable type: location
	//ERROR: Undefined variable type: effect
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
	if(argc < 3)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nDurationType = argv[0];
	eEffect = argv[1];
	oTarget = argv[2];
	if(argc>3) fDuration = argv[3];
	else fDuration = rb_float_new(0.0f);
	StackPushFloat(NUM2DBL(fDuration));
	StackPushObject(NUM2UINT(oTarget));
	//ERROR: Undefined variable type: effect
	StackPushInteger(NUM2INT(nDurationType));
	VM_ExecuteCommand(220, 4);
	return Qnil;
}

static VALUE NWScript_SpeakString(int argc, VALUE *argv, VALUE self)
{
	VALUE sStringToSpeak, nTalkVolume;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	sStringToSpeak = argv[0];
	if(argc>1) nTalkVolume = argv[1];
	else nTalkVolume = INT2NUM(TALKVOLUME_TALK);
	StackPushInteger(NUM2INT(nTalkVolume));
	StackPushString(rb_str2cstr(sStringToSpeak, NULL));
	VM_ExecuteCommand(221, 2);
	return Qnil;
}

static VALUE NWScript_GetSpellTargetLocation()
{
	VM_ExecuteCommand(222, 0);
//ERROR: Undefined variable type: location
}

static VALUE NWScript_GetPositionFromLocation(VALUE self, VALUE lLocation)
{
	//ERROR: Undefined variable type: location
	VM_ExecuteCommand(223, 1);
//ERROR: Undefined variable type: vector
}

static VALUE NWScript_GetAreaFromLocation(VALUE self, VALUE lLocation)
{
	//ERROR: Undefined variable type: location
	VM_ExecuteCommand(224, 1);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetFacingFromLocation(VALUE self, VALUE lLocation)
{
	//ERROR: Undefined variable type: location
	VM_ExecuteCommand(225, 1);
	float fRetVal;
	StackPopFloat(&fRetVal);
	return rb_float_new(fRetVal);
}

static VALUE NWScript_GetNearestCreatureToLocation(int argc, VALUE *argv, VALUE self)
{
	VALUE nFirstCriteriaType, nFirstCriteriaValue, lLocation, nNth, nSecondCriteriaType, nSecondCriteriaValue, nThirdCriteriaType, nThirdCriteriaValue;
	if(argc < 3)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nFirstCriteriaType = argv[0];
	nFirstCriteriaValue = argv[1];
	lLocation = argv[2];
	if(argc>3) nNth = argv[3];
	else nNth = INT2NUM(1);
	if(argc>4) nSecondCriteriaType = argv[4];
	else nSecondCriteriaType = INT2NUM(-1);
	if(argc>5) nSecondCriteriaValue = argv[5];
	else nSecondCriteriaValue = INT2NUM(-1);
	if(argc>6) nThirdCriteriaType = argv[6];
	else nThirdCriteriaType = INT2NUM(-1);
	if(argc>7) nThirdCriteriaValue = argv[7];
	else nThirdCriteriaValue = INT2NUM(-1);
	StackPushInteger(NUM2INT(nThirdCriteriaValue));
	StackPushInteger(NUM2INT(nThirdCriteriaType));
	StackPushInteger(NUM2INT(nSecondCriteriaValue));
	StackPushInteger(NUM2INT(nSecondCriteriaType));
	StackPushInteger(NUM2INT(nNth));
	//ERROR: Undefined variable type: location
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
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) nObjectType = argv[0];
	else nObjectType = INT2NUM(OBJECT_TYPE_ALL);
	if(argc>1) oTarget = argv[1];
	else oTarget = INT2NUM(OBJECT_SELF);
	if(argc>2) nNth = argv[2];
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
	if(argc < 2)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nObjectType = argv[0];
	lLocation = argv[1];
	if(argc>2) nNth = argv[2];
	else nNth = INT2NUM(1);
	StackPushInteger(NUM2INT(nNth));
	//ERROR: Undefined variable type: location
	StackPushInteger(NUM2INT(nObjectType));
	VM_ExecuteCommand(228, 3);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetNearestObjectByTag(int argc, VALUE *argv, VALUE self)
{
	VALUE sTag, oTarget, nNth;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	sTag = argv[0];
	if(argc>1) oTarget = argv[1];
	else oTarget = INT2NUM(OBJECT_SELF);
	if(argc>2) nNth = argv[2];
	else nNth = INT2NUM(1);
	StackPushInteger(NUM2INT(nNth));
	StackPushObject(NUM2UINT(oTarget));
	StackPushString(rb_str2cstr(sTag, NULL));
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
	StackPushString(rb_str2cstr(sNumber, NULL));
	VM_ExecuteCommand(232, 1);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_StringToFloat(VALUE self, VALUE sNumber)
{
	StackPushString(rb_str2cstr(sNumber, NULL));
	VM_ExecuteCommand(233, 1);
	float fRetVal;
	StackPopFloat(&fRetVal);
	return rb_float_new(fRetVal);
}

static VALUE NWScript_ActionCastSpellAtLocation(int argc, VALUE *argv, VALUE self)
{
	VALUE nSpell, lTargetLocation, nMetaMagic, bCheat, nProjectilePathType, bInstantSpell;
	if(argc < 2)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nSpell = argv[0];
	lTargetLocation = argv[1];
	if(argc>2) nMetaMagic = argv[2];
	else nMetaMagic = INT2NUM(METAMAGIC_ANY);
	if(argc>3) bCheat = argv[3];
	else bCheat = INT2NUM(FALSE);
	if(argc>4) nProjectilePathType = argv[4];
	else nProjectilePathType = INT2NUM(PROJECTILE_PATH_TYPE_DEFAULT);
	if(argc>5) bInstantSpell = argv[5];
	else bInstantSpell = INT2NUM(FALSE);
	StackPushInteger(NUM2INT(bInstantSpell));
	StackPushInteger(NUM2INT(nProjectilePathType));
	StackPushInteger(NUM2INT(bCheat));
	StackPushInteger(NUM2INT(nMetaMagic));
	//ERROR: Undefined variable type: location
	StackPushInteger(NUM2INT(nSpell));
	VM_ExecuteCommand(234, 6);
	return Qnil;
}

static VALUE NWScript_GetIsEnemy(int argc, VALUE *argv, VALUE self)
{
	VALUE oTarget, oSource;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oTarget = argv[0];
	if(argc>1) oSource = argv[1];
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
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oTarget = argv[0];
	if(argc>1) oSource = argv[1];
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
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oTarget = argv[0];
	if(argc>1) oSource = argv[1];
	else oSource = INT2NUM(OBJECT_SELF);
	StackPushObject(NUM2UINT(oSource));
	StackPushObject(NUM2UINT(oTarget));
	VM_ExecuteCommand(237, 2);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetPCSpeaker()
{
	VM_ExecuteCommand(238, 0);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetStringByStrRef(int argc, VALUE *argv, VALUE self)
{
	VALUE nStrRef, nGender;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nStrRef = argv[0];
	if(argc>1) nGender = argv[1];
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
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nStrRef = argv[0];
	if(argc>1) nTalkVolume = argv[1];
	else nTalkVolume = INT2NUM(TALKVOLUME_TALK);
	StackPushInteger(NUM2INT(nTalkVolume));
	StackPushInteger(NUM2INT(nStrRef));
	VM_ExecuteCommand(240, 2);
	return Qnil;
}

static VALUE NWScript_DestroyObject(int argc, VALUE *argv, VALUE self)
{
	VALUE oDestroy, fDelay;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oDestroy = argv[0];
	if(argc>1) fDelay = argv[1];
	else fDelay = rb_float_new(0.0f);
	StackPushFloat(NUM2DBL(fDelay));
	StackPushObject(NUM2UINT(oDestroy));
	VM_ExecuteCommand(241, 2);
	return Qnil;
}

static VALUE NWScript_GetModule()
{
	VM_ExecuteCommand(242, 0);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_CreateObject(int argc, VALUE *argv, VALUE self)
{
	VALUE nObjectType, sTemplate, lLocation, bUseAppearAnimation, sNewTag;
	if(argc < 3)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nObjectType = argv[0];
	sTemplate = argv[1];
	lLocation = argv[2];
	if(argc>3) bUseAppearAnimation = argv[3];
	else bUseAppearAnimation = INT2NUM(FALSE);
	if(argc>4) sNewTag = argv[4];
	else sNewTag = rb_str_new2("");
	StackPushString(rb_str2cstr(sNewTag, NULL));
	StackPushInteger(NUM2INT(bUseAppearAnimation));
	//ERROR: Undefined variable type: location
	StackPushString(rb_str2cstr(sTemplate, NULL));
	StackPushInteger(NUM2INT(nObjectType));
	VM_ExecuteCommand(243, 5);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_EventSpellCastAt(int argc, VALUE *argv, VALUE self)
{
	VALUE oCaster, nSpell, bHarmful;
	if(argc < 2)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oCaster = argv[0];
	nSpell = argv[1];
	if(argc>2) bHarmful = argv[2];
	else bHarmful = INT2NUM(TRUE);
	StackPushInteger(NUM2INT(bHarmful));
	StackPushInteger(NUM2INT(nSpell));
	StackPushObject(NUM2UINT(oCaster));
	VM_ExecuteCommand(244, 3);
//ERROR: Undefined variable type: event
}

static VALUE NWScript_GetLastSpellCaster()
{
	VM_ExecuteCommand(245, 0);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastSpell()
{
	VM_ExecuteCommand(246, 0);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetUserDefinedEventNumber()
{
	VM_ExecuteCommand(247, 0);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetSpellId()
{
	VM_ExecuteCommand(248, 0);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_RandomName(int argc, VALUE *argv, VALUE self)
{
	VALUE nNameType;
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) nNameType = argv[0];
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
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectDisease(VALUE self, VALUE nDiseaseType)
{
	StackPushInteger(NUM2INT(nDiseaseType));
	VM_ExecuteCommand(251, 1);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectSilence()
{
	VM_ExecuteCommand(252, 0);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_GetName(int argc, VALUE *argv, VALUE self)
{
	VALUE oObject, bOriginalName;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oObject = argv[0];
	if(argc>1) bOriginalName = argv[1];
	else bOriginalName = INT2NUM(FALSE);
	StackPushInteger(NUM2INT(bOriginalName));
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(253, 2);
	char *sRetVal;
	StackPopString(&sRetVal);
	return rb_str_new2(sRetVal);
}

static VALUE NWScript_GetLastSpeaker()
{
	VM_ExecuteCommand(254, 0);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_BeginConversation(int argc, VALUE *argv, VALUE self)
{
	VALUE sResRef, oObjectToDialog;
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) sResRef = argv[0];
	else sResRef = rb_str_new2("");
	if(argc>1) oObjectToDialog = argv[1];
	else oObjectToDialog = INT2NUM(OBJECT_INVALID);
	StackPushObject(NUM2UINT(oObjectToDialog));
	StackPushString(rb_str2cstr(sResRef, NULL));
	VM_ExecuteCommand(255, 2);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastPerceived()
{
	VM_ExecuteCommand(256, 0);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastPerceptionHeard()
{
	VM_ExecuteCommand(257, 0);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastPerceptionInaudible()
{
	VM_ExecuteCommand(258, 0);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastPerceptionSeen()
{
	VM_ExecuteCommand(259, 0);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastClosedBy()
{
	VM_ExecuteCommand(260, 0);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastPerceptionVanished()
{
	VM_ExecuteCommand(261, 0);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetFirstInPersistentObject(int argc, VALUE *argv, VALUE self)
{
	VALUE oPersistentObject, nResidentObjectType, nPersistentZone;
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oPersistentObject = argv[0];
	else oPersistentObject = INT2NUM(OBJECT_SELF);
	if(argc>1) nResidentObjectType = argv[1];
	else nResidentObjectType = INT2NUM(OBJECT_TYPE_CREATURE);
	if(argc>2) nPersistentZone = argv[2];
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
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oPersistentObject = argv[0];
	else oPersistentObject = INT2NUM(OBJECT_SELF);
	if(argc>1) nResidentObjectType = argv[1];
	else nResidentObjectType = INT2NUM(OBJECT_TYPE_CREATURE);
	if(argc>2) nPersistentZone = argv[2];
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
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oAreaOfEffectObject = argv[0];
	else oAreaOfEffectObject = INT2NUM(OBJECT_SELF);
	StackPushObject(NUM2UINT(oAreaOfEffectObject));
	VM_ExecuteCommand(264, 1);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_DeleteLocalInt(VALUE self, VALUE oObject, VALUE sVarName)
{
	StackPushString(rb_str2cstr(sVarName, NULL));
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(265, 2);
	return Qnil;
}

static VALUE NWScript_DeleteLocalFloat(VALUE self, VALUE oObject, VALUE sVarName)
{
	StackPushString(rb_str2cstr(sVarName, NULL));
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(266, 2);
	return Qnil;
}

static VALUE NWScript_DeleteLocalString(VALUE self, VALUE oObject, VALUE sVarName)
{
	StackPushString(rb_str2cstr(sVarName, NULL));
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(267, 2);
	return Qnil;
}

static VALUE NWScript_DeleteLocalObject(VALUE self, VALUE oObject, VALUE sVarName)
{
	StackPushString(rb_str2cstr(sVarName, NULL));
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(268, 2);
	return Qnil;
}

static VALUE NWScript_DeleteLocalLocation(VALUE self, VALUE oObject, VALUE sVarName)
{
	StackPushString(rb_str2cstr(sVarName, NULL));
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(269, 2);
	return Qnil;
}

static VALUE NWScript_EffectHaste()
{
	VM_ExecuteCommand(270, 0);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectSlow()
{
	VM_ExecuteCommand(271, 0);
//ERROR: Undefined variable type: effect
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
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_GetIsImmune(int argc, VALUE *argv, VALUE self)
{
	VALUE oCreature, nImmunityType, oVersus;
	if(argc < 2)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oCreature = argv[0];
	nImmunityType = argv[1];
	if(argc>2) oVersus = argv[2];
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
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_GetEncounterActive(int argc, VALUE *argv, VALUE self)
{
	VALUE oEncounter;
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oEncounter = argv[0];
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
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nNewValue = argv[0];
	if(argc>1) oEncounter = argv[1];
	else oEncounter = INT2NUM(OBJECT_SELF);
	StackPushObject(NUM2UINT(oEncounter));
	StackPushInteger(NUM2INT(nNewValue));
	VM_ExecuteCommand(277, 2);
	return Qnil;
}

static VALUE NWScript_GetEncounterSpawnsMax(int argc, VALUE *argv, VALUE self)
{
	VALUE oEncounter;
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oEncounter = argv[0];
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
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nNewValue = argv[0];
	if(argc>1) oEncounter = argv[1];
	else oEncounter = INT2NUM(OBJECT_SELF);
	StackPushObject(NUM2UINT(oEncounter));
	StackPushInteger(NUM2INT(nNewValue));
	VM_ExecuteCommand(279, 2);
	return Qnil;
}

static VALUE NWScript_GetEncounterSpawnsCurrent(int argc, VALUE *argv, VALUE self)
{
	VALUE oEncounter;
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oEncounter = argv[0];
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
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nNewValue = argv[0];
	if(argc>1) oEncounter = argv[1];
	else oEncounter = INT2NUM(OBJECT_SELF);
	StackPushObject(NUM2UINT(oEncounter));
	StackPushInteger(NUM2INT(nNewValue));
	VM_ExecuteCommand(281, 2);
	return Qnil;
}

static VALUE NWScript_GetModuleItemAcquired()
{
	VM_ExecuteCommand(282, 0);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetModuleItemAcquiredFrom()
{
	VM_ExecuteCommand(283, 0);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_SetCustomToken(VALUE self, VALUE nCustomTokenNumber, VALUE sTokenValue)
{
	StackPushString(rb_str2cstr(sTokenValue, NULL));
	StackPushInteger(NUM2INT(nCustomTokenNumber));
	VM_ExecuteCommand(284, 2);
	return Qnil;
}

static VALUE NWScript_GetHasFeat(int argc, VALUE *argv, VALUE self)
{
	VALUE nFeat, oCreature;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nFeat = argv[0];
	if(argc>1) oCreature = argv[1];
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
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nSkill = argv[0];
	if(argc>1) oCreature = argv[1];
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
	if(argc < 2)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nSkill = argv[0];
	oTarget = argv[1];
	if(argc>2) nSubSkill = argv[2];
	else nSubSkill = INT2NUM(0);
	if(argc>3) oItemUsed = argv[3];
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
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oTarget = argv[0];
	if(argc>1) oSource = argv[1];
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
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oTarget = argv[0];
	if(argc>1) oSource = argv[1];
	else oSource = INT2NUM(OBJECT_SELF);
	StackPushObject(NUM2UINT(oSource));
	StackPushObject(NUM2UINT(oTarget));
	VM_ExecuteCommand(290, 2);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastPlayerDied()
{
	VM_ExecuteCommand(291, 0);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetModuleItemLost()
{
	VM_ExecuteCommand(292, 0);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetModuleItemLostBy()
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

static VALUE NWScript_EventConversation()
{
	VM_ExecuteCommand(295, 0);
//ERROR: Undefined variable type: event
}

static VALUE NWScript_SetEncounterDifficulty(int argc, VALUE *argv, VALUE self)
{
	VALUE nEncounterDifficulty, oEncounter;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nEncounterDifficulty = argv[0];
	if(argc>1) oEncounter = argv[1];
	else oEncounter = INT2NUM(OBJECT_SELF);
	StackPushObject(NUM2UINT(oEncounter));
	StackPushInteger(NUM2INT(nEncounterDifficulty));
	VM_ExecuteCommand(296, 2);
	return Qnil;
}

static VALUE NWScript_GetEncounterDifficulty(int argc, VALUE *argv, VALUE self)
{
	VALUE oEncounter;
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oEncounter = argv[0];
	else oEncounter = INT2NUM(OBJECT_SELF);
	StackPushObject(NUM2UINT(oEncounter));
	VM_ExecuteCommand(297, 1);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetDistanceBetweenLocations(VALUE self, VALUE lLocationA, VALUE lLocationB)
{
	//ERROR: Undefined variable type: location
	//ERROR: Undefined variable type: location
	VM_ExecuteCommand(298, 2);
	float fRetVal;
	StackPopFloat(&fRetVal);
	return rb_float_new(fRetVal);
}

static VALUE NWScript_GetReflexAdjustedDamage(int argc, VALUE *argv, VALUE self)
{
	VALUE nDamage, oTarget, nDC, nSaveType, oSaveVersus;
	if(argc < 3)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nDamage = argv[0];
	oTarget = argv[1];
	nDC = argv[2];
	if(argc>3) nSaveType = argv[3];
	else nSaveType = INT2NUM(SAVING_THROW_TYPE_NONE);
	if(argc>4) oSaveVersus = argv[4];
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
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nAnimation = argv[0];
	if(argc>1) fSpeed = argv[1];
	else fSpeed = rb_float_new(1.0);
	if(argc>2) fSeconds = argv[2];
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
}

static VALUE NWScript_TalentFeat(VALUE self, VALUE nFeat)
{
	StackPushInteger(NUM2INT(nFeat));
	VM_ExecuteCommand(302, 1);
//ERROR: Undefined variable type: talent
}

static VALUE NWScript_TalentSkill(VALUE self, VALUE nSkill)
{
	StackPushInteger(NUM2INT(nSkill));
	VM_ExecuteCommand(303, 1);
//ERROR: Undefined variable type: talent
}

static VALUE NWScript_GetHasSpellEffect(int argc, VALUE *argv, VALUE self)
{
	VALUE nSpell, oObject;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nSpell = argv[0];
	if(argc>1) oObject = argv[1];
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
	//ERROR: Undefined variable type: effect
	VM_ExecuteCommand(305, 1);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetCreatureHasTalent(int argc, VALUE *argv, VALUE self)
{
	VALUE tTalent, oCreature;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	tTalent = argv[0];
	if(argc>1) oCreature = argv[1];
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
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nCategory = argv[0];
	if(argc>1) oCreature = argv[1];
	else oCreature = INT2NUM(OBJECT_SELF);
	StackPushObject(NUM2UINT(oCreature));
	StackPushInteger(NUM2INT(nCategory));
	VM_ExecuteCommand(307, 2);
//ERROR: Undefined variable type: talent
}

static VALUE NWScript_GetCreatureTalentBest(int argc, VALUE *argv, VALUE self)
{
	VALUE nCategory, nCRMax, oCreature;
	if(argc < 2)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nCategory = argv[0];
	nCRMax = argv[1];
	if(argc>2) oCreature = argv[2];
	else oCreature = INT2NUM(OBJECT_SELF);
	StackPushObject(NUM2UINT(oCreature));
	StackPushInteger(NUM2INT(nCRMax));
	StackPushInteger(NUM2INT(nCategory));
	VM_ExecuteCommand(308, 3);
//ERROR: Undefined variable type: talent
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
	//ERROR: Undefined variable type: location
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
	//ERROR: Undefined variable type: location
	VM_ExecuteCommand(313, 1);
	return Qnil;
}

static VALUE NWScript_EffectTemporaryHitpoints(VALUE self, VALUE nHitPoints)
{
	StackPushInteger(NUM2INT(nHitPoints));
	VM_ExecuteCommand(314, 1);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_GetSkillRank(int argc, VALUE *argv, VALUE self)
{
	VALUE nSkill, oTarget, nBaseSkillRank;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nSkill = argv[0];
	if(argc>1) oTarget = argv[1];
	else oTarget = INT2NUM(OBJECT_SELF);
	if(argc>2) nBaseSkillRank = argv[2];
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
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oCreature = argv[0];
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
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oCreature = argv[0];
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
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oCreature = argv[0];
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
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oAssociate = argv[0];
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
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oCreature = argv[0];
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
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oAssociate = argv[0];
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
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	bDestroyable = argv[0];
	if(argc>1) bRaiseable = argv[1];
	else bRaiseable = INT2NUM(TRUE);
	if(argc>2) bSelectableWhenDead = argv[2];
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

static VALUE NWScript_GetClickingObject()
{
	VM_ExecuteCommand(326, 0);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_SetAssociateListenPatterns(int argc, VALUE *argv, VALUE self)
{
	VALUE oTarget;
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oTarget = argv[0];
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

static VALUE NWScript_GetLastUsedBy()
{
	VM_ExecuteCommand(330, 0);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetAbilityModifier(int argc, VALUE *argv, VALUE self)
{
	VALUE nAbility, oCreature;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nAbility = argv[0];
	if(argc>1) oCreature = argv[1];
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
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oMaster = argv[0];
	else oMaster = INT2NUM(OBJECT_SELF);
	StackPushObject(NUM2UINT(oMaster));
	VM_ExecuteCommand(334, 1);
	return Qnil;
}

static VALUE NWScript_SummonFamiliar(int argc, VALUE *argv, VALUE self)
{
	VALUE oMaster;
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oMaster = argv[0];
	else oMaster = INT2NUM(OBJECT_SELF);
	StackPushObject(NUM2UINT(oMaster));
	VM_ExecuteCommand(335, 1);
	return Qnil;
}

static VALUE NWScript_GetBlockingDoor()
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
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oTarget = argv[0];
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
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oTarget = argv[0];
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
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nClassPosition = argv[0];
	if(argc>1) oCreature = argv[1];
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
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nClassPosition = argv[0];
	if(argc>1) oCreature = argv[1];
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
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nClassType = argv[0];
	if(argc>1) oCreature = argv[1];
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

static VALUE NWScript_GetTotalDamageDealt()
{
	VM_ExecuteCommand(345, 0);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastDamager(int argc, VALUE *argv, VALUE self)
{
	VALUE oObject;
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oObject = argv[0];
	else oObject = INT2NUM(OBJECT_SELF);
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(346, 1);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastDisarmed()
{
	VM_ExecuteCommand(347, 0);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastDisturbed()
{
	VM_ExecuteCommand(348, 0);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastLocked()
{
	VM_ExecuteCommand(349, 0);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastUnlocked()
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
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_GetInventoryDisturbType()
{
	VM_ExecuteCommand(352, 0);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetInventoryDisturbItem()
{
	VM_ExecuteCommand(353, 0);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetHenchman(int argc, VALUE *argv, VALUE self)
{
	VALUE oMaster, nNth;
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oMaster = argv[0];
	else oMaster = INT2NUM(OBJECT_SELF);
	if(argc>1) nNth = argv[1];
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
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	eEffect = argv[0];
	if(argc>1) nLawChaos = argv[1];
	else nLawChaos = INT2NUM(ALIGNMENT_ALL);
	if(argc>2) nGoodEvil = argv[2];
	else nGoodEvil = INT2NUM(ALIGNMENT_ALL);
	StackPushInteger(NUM2INT(nGoodEvil));
	StackPushInteger(NUM2INT(nLawChaos));
	//ERROR: Undefined variable type: effect
	VM_ExecuteCommand(355, 3);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_VersusRacialTypeEffect(VALUE self, VALUE eEffect, VALUE nRacialType)
{
	StackPushInteger(NUM2INT(nRacialType));
	//ERROR: Undefined variable type: effect
	VM_ExecuteCommand(356, 2);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_VersusTrapEffect(VALUE self, VALUE eEffect)
{
	//ERROR: Undefined variable type: effect
	VM_ExecuteCommand(357, 1);
//ERROR: Undefined variable type: effect
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
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	lMoveAwayFrom = argv[0];
	if(argc>1) bRun = argv[1];
	else bRun = INT2NUM(FALSE);
	if(argc>2) fMoveAwayRange = argv[2];
	else fMoveAwayRange = rb_float_new(40.0f);
	StackPushFloat(NUM2DBL(fMoveAwayRange));
	StackPushInteger(NUM2INT(bRun));
	//ERROR: Undefined variable type: location
	VM_ExecuteCommand(360, 3);
	return Qnil;
}

static VALUE NWScript_GetAttemptedAttackTarget()
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
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nAssociateType = argv[0];
	if(argc>1) oMaster = argv[1];
	else oMaster = INT2NUM(OBJECT_SELF);
	if(argc>2) nTh = argv[2];
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
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oMaster = argv[0];
	if(argc>1) oHenchman = argv[1];
	else oHenchman = INT2NUM(OBJECT_SELF);
	StackPushObject(NUM2UINT(oHenchman));
	StackPushObject(NUM2UINT(oMaster));
	VM_ExecuteCommand(365, 2);
	return Qnil;
}

static VALUE NWScript_RemoveHenchman(int argc, VALUE *argv, VALUE self)
{
	VALUE oMaster, oHenchman;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oMaster = argv[0];
	if(argc>1) oHenchman = argv[1];
	else oHenchman = INT2NUM(OBJECT_SELF);
	StackPushObject(NUM2UINT(oHenchman));
	StackPushObject(NUM2UINT(oMaster));
	VM_ExecuteCommand(366, 2);
	return Qnil;
}

static VALUE NWScript_AddJournalQuestEntry(int argc, VALUE *argv, VALUE self)
{
	VALUE szPlotID, nState, oCreature, bAllPartyMembers, bAllPlayers, bAllowOverrideHigher;
	if(argc < 3)
	{
		//TODO: Raise exception
		return Qnil;
	}
	szPlotID = argv[0];
	nState = argv[1];
	oCreature = argv[2];
	if(argc>3) bAllPartyMembers = argv[3];
	else bAllPartyMembers = INT2NUM(TRUE);
	if(argc>4) bAllPlayers = argv[4];
	else bAllPlayers = INT2NUM(FALSE);
	if(argc>5) bAllowOverrideHigher = argv[5];
	else bAllowOverrideHigher = INT2NUM(FALSE);
	StackPushInteger(NUM2INT(bAllowOverrideHigher));
	StackPushInteger(NUM2INT(bAllPlayers));
	StackPushInteger(NUM2INT(bAllPartyMembers));
	StackPushObject(NUM2UINT(oCreature));
	StackPushInteger(NUM2INT(nState));
	StackPushString(rb_str2cstr(szPlotID, NULL));
	VM_ExecuteCommand(367, 6);
	return Qnil;
}

static VALUE NWScript_RemoveJournalQuestEntry(int argc, VALUE *argv, VALUE self)
{
	VALUE szPlotID, oCreature, bAllPartyMembers, bAllPlayers;
	if(argc < 2)
	{
		//TODO: Raise exception
		return Qnil;
	}
	szPlotID = argv[0];
	oCreature = argv[1];
	if(argc>2) bAllPartyMembers = argv[2];
	else bAllPartyMembers = INT2NUM(TRUE);
	if(argc>3) bAllPlayers = argv[3];
	else bAllPlayers = INT2NUM(FALSE);
	StackPushInteger(NUM2INT(bAllPlayers));
	StackPushInteger(NUM2INT(bAllPartyMembers));
	StackPushObject(NUM2UINT(oCreature));
	StackPushString(rb_str2cstr(szPlotID, NULL));
	VM_ExecuteCommand(368, 4);
	return Qnil;
}

static VALUE NWScript_GetPCPublicCDKey(int argc, VALUE *argv, VALUE self)
{
	VALUE oPlayer, nSinglePlayerCDKey;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oPlayer = argv[0];
	if(argc>1) nSinglePlayerCDKey = argv[1];
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
	StackPushString(rb_str2cstr(szMessage, NULL));
	StackPushObject(NUM2UINT(oPlayer));
	VM_ExecuteCommand(374, 2);
	return Qnil;
}

static VALUE NWScript_GetAttemptedSpellTarget()
{
	VM_ExecuteCommand(375, 0);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastOpenedBy()
{
	VM_ExecuteCommand(376, 0);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetHasSpell(int argc, VALUE *argv, VALUE self)
{
	VALUE nSpell, oCreature;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nSpell = argv[0];
	if(argc>1) oCreature = argv[1];
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
	if(argc < 2)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oStore = argv[0];
	oPC = argv[1];
	if(argc>2) nBonusMarkUp = argv[2];
	else nBonusMarkUp = INT2NUM(0);
	if(argc>3) nBonusMarkDown = argv[3];
	else nBonusMarkDown = INT2NUM(0);
	StackPushInteger(NUM2INT(nBonusMarkDown));
	StackPushInteger(NUM2INT(nBonusMarkUp));
	StackPushObject(NUM2UINT(oPC));
	StackPushObject(NUM2UINT(oStore));
	VM_ExecuteCommand(378, 4);
	return Qnil;
}

static VALUE NWScript_EffectTurned()
{
	VM_ExecuteCommand(379, 0);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_GetFirstFactionMember(int argc, VALUE *argv, VALUE self)
{
	VALUE oMemberOfFaction, bPCOnly;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oMemberOfFaction = argv[0];
	if(argc>1) bPCOnly = argv[1];
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
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oMemberOfFaction = argv[0];
	if(argc>1) bPCOnly = argv[1];
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
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	lDestination = argv[0];
	if(argc>1) bRun = argv[1];
	else bRun = INT2NUM(FALSE);
	if(argc>2) fTimeout = argv[2];
	else fTimeout = rb_float_new(30.0f);
	StackPushFloat(NUM2DBL(fTimeout));
	StackPushInteger(NUM2INT(bRun));
	//ERROR: Undefined variable type: location
	VM_ExecuteCommand(382, 3);
	return Qnil;
}

static VALUE NWScript_ActionForceMoveToObject(int argc, VALUE *argv, VALUE self)
{
	VALUE oMoveTo, bRun, fRange, fTimeout;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oMoveTo = argv[0];
	if(argc>1) bRun = argv[1];
	else bRun = INT2NUM(FALSE);
	if(argc>2) fRange = argv[2];
	else fRange = rb_float_new(1.0f);
	if(argc>3) fTimeout = argv[3];
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
	StackPushString(rb_str2cstr(szPlotID, NULL));
	VM_ExecuteCommand(384, 1);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_JumpToObject(int argc, VALUE *argv, VALUE self)
{
	VALUE oToJumpTo, nWalkStraightLineToPoint;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oToJumpTo = argv[0];
	if(argc>1) nWalkStraightLineToPoint = argv[1];
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
//ERROR: Undefined variable type: effect
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
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oTarget = argv[0];
	if(argc>1) oSource = argv[1];
	else oSource = INT2NUM(OBJECT_SELF);
	StackPushObject(NUM2UINT(oSource));
	StackPushObject(NUM2UINT(oTarget));
	VM_ExecuteCommand(389, 2);
	return Qnil;
}

static VALUE NWScript_SetIsTemporaryFriend(int argc, VALUE *argv, VALUE self)
{
	VALUE oTarget, oSource, bDecays, fDurationInSeconds;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oTarget = argv[0];
	if(argc>1) oSource = argv[1];
	else oSource = INT2NUM(OBJECT_SELF);
	if(argc>2) bDecays = argv[2];
	else bDecays = INT2NUM(FALSE);
	if(argc>3) fDurationInSeconds = argv[3];
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
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oTarget = argv[0];
	if(argc>1) oSource = argv[1];
	else oSource = INT2NUM(OBJECT_SELF);
	if(argc>2) bDecays = argv[2];
	else bDecays = INT2NUM(FALSE);
	if(argc>3) fDurationInSeconds = argv[3];
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
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oTarget = argv[0];
	if(argc>1) oSource = argv[1];
	else oSource = INT2NUM(OBJECT_SELF);
	if(argc>2) bDecays = argv[2];
	else bDecays = INT2NUM(FALSE);
	if(argc>3) fDurationInSeconds = argv[3];
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
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oVersus = argv[0];
	else oVersus = INT2NUM(OBJECT_INVALID);
	if(argc>1) bOffHand = argv[1];
	else bOffHand = INT2NUM(FALSE);
	StackPushInteger(NUM2INT(bOffHand));
	StackPushObject(NUM2UINT(oVersus));
	VM_ExecuteCommand(399, 2);
	return Qnil;
}

static VALUE NWScript_ActionEquipMostDamagingRanged(int argc, VALUE *argv, VALUE self)
{
	VALUE oVersus;
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oVersus = argv[0];
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
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) bCreatureToEnemyLineOfSightCheck = argv[0];
	else bCreatureToEnemyLineOfSightCheck = INT2NUM(FALSE);
	StackPushInteger(NUM2INT(bCreatureToEnemyLineOfSightCheck));
	VM_ExecuteCommand(402, 1);
	return Qnil;
}

static VALUE NWScript_ExploreAreaForPlayer(int argc, VALUE *argv, VALUE self)
{
	VALUE oArea, oPlayer, bExplored;
	if(argc < 2)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oArea = argv[0];
	oPlayer = argv[1];
	if(argc>2) bExplored = argv[2];
	else bExplored = INT2NUM(TRUE);
	StackPushInteger(NUM2INT(bExplored));
	StackPushObject(NUM2UINT(oPlayer));
	StackPushObject(NUM2UINT(oArea));
	VM_ExecuteCommand(403, 3);
	return Qnil;
}

static VALUE NWScript_ActionEquipMostEffectiveArmor()
{
	VM_ExecuteCommand(404, 0);
	return Qnil;
}

static VALUE NWScript_GetIsDay()
{
	VM_ExecuteCommand(405, 0);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetIsNight()
{
	VM_ExecuteCommand(406, 0);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetIsDawn()
{
	VM_ExecuteCommand(407, 0);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetIsDusk()
{
	VM_ExecuteCommand(408, 0);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetIsEncounterCreature(int argc, VALUE *argv, VALUE self)
{
	VALUE oCreature;
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oCreature = argv[0];
	else oCreature = INT2NUM(OBJECT_SELF);
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(409, 1);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastPlayerDying()
{
	VM_ExecuteCommand(410, 0);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetStartingLocation()
{
	VM_ExecuteCommand(411, 0);
//ERROR: Undefined variable type: location
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
	//ERROR: Undefined variable type: vector
	StackPushObject(NUM2UINT(oSound));
	VM_ExecuteCommand(416, 2);
	return Qnil;
}

static VALUE NWScript_SpeakOneLinerConversation(int argc, VALUE *argv, VALUE self)
{
	VALUE sDialogResRef, oTokenTarget;
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) sDialogResRef = argv[0];
	else sDialogResRef = rb_str_new2("");
	if(argc>1) oTokenTarget = argv[1];
	else oTokenTarget = INT2NUM(OBJECT_TYPE_INVALID);
	StackPushObject(NUM2UINT(oTokenTarget));
	StackPushString(rb_str2cstr(sDialogResRef, NULL));
	VM_ExecuteCommand(417, 2);
	return Qnil;
}

static VALUE NWScript_GetGold(int argc, VALUE *argv, VALUE self)
{
	VALUE oTarget;
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oTarget = argv[0];
	else oTarget = INT2NUM(OBJECT_SELF);
	StackPushObject(NUM2UINT(oTarget));
	VM_ExecuteCommand(418, 1);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastRespawnButtonPresser()
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
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nVoiceChatID = argv[0];
	if(argc>1) oTarget = argv[1];
	else oTarget = INT2NUM(OBJECT_SELF);
	StackPushObject(NUM2UINT(oTarget));
	StackPushInteger(NUM2INT(nVoiceChatID));
	VM_ExecuteCommand(421, 2);
	return Qnil;
}

static VALUE NWScript_GetIsWeaponEffective(int argc, VALUE *argv, VALUE self)
{
	VALUE oVersus, bOffHand;
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oVersus = argv[0];
	else oVersus = INT2NUM(OBJECT_INVALID);
	if(argc>1) bOffHand = argv[1];
	else bOffHand = INT2NUM(FALSE);
	StackPushInteger(NUM2INT(bOffHand));
	StackPushObject(NUM2UINT(oVersus));
	VM_ExecuteCommand(422, 2);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastSpellHarmful()
{
	VM_ExecuteCommand(423, 0);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_EventActivateItem(int argc, VALUE *argv, VALUE self)
{
	VALUE oItem, lTarget, oTarget;
	if(argc < 2)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oItem = argv[0];
	lTarget = argv[1];
	if(argc>2) oTarget = argv[2];
	else oTarget = INT2NUM(OBJECT_INVALID);
	StackPushObject(NUM2UINT(oTarget));
	//ERROR: Undefined variable type: location
	StackPushObject(NUM2UINT(oItem));
	VM_ExecuteCommand(424, 3);
//ERROR: Undefined variable type: event
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

static VALUE NWScript_GetLastKiller()
{
	VM_ExecuteCommand(437, 0);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetSpellCastItem()
{
	VM_ExecuteCommand(438, 0);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetItemActivated()
{
	VM_ExecuteCommand(439, 0);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetItemActivator()
{
	VM_ExecuteCommand(440, 0);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetItemActivatedTargetLocation()
{
	VM_ExecuteCommand(441, 0);
//ERROR: Undefined variable type: location
}

static VALUE NWScript_GetItemActivatedTarget()
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
	if(argc < 2)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nAmount = argv[0];
	oCreatureToTakeFrom = argv[1];
	if(argc>2) bDestroy = argv[2];
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
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectAttackDecrease(int argc, VALUE *argv, VALUE self)
{
	VALUE nPenalty, nModifierType;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nPenalty = argv[0];
	if(argc>1) nModifierType = argv[1];
	else nModifierType = INT2NUM(ATTACK_BONUS_MISC);
	StackPushInteger(NUM2INT(nModifierType));
	StackPushInteger(NUM2INT(nPenalty));
	VM_ExecuteCommand(447, 2);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectDamageDecrease(int argc, VALUE *argv, VALUE self)
{
	VALUE nPenalty, nDamageType;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nPenalty = argv[0];
	if(argc>1) nDamageType = argv[1];
	else nDamageType = INT2NUM(DAMAGE_TYPE_MAGICAL);
	StackPushInteger(NUM2INT(nDamageType));
	StackPushInteger(NUM2INT(nPenalty));
	VM_ExecuteCommand(448, 2);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectDamageImmunityDecrease(VALUE self, VALUE nDamageType, VALUE nPercentImmunity)
{
	StackPushInteger(NUM2INT(nPercentImmunity));
	StackPushInteger(NUM2INT(nDamageType));
	VM_ExecuteCommand(449, 2);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectACDecrease(int argc, VALUE *argv, VALUE self)
{
	VALUE nValue, nModifyType, nDamageType;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nValue = argv[0];
	if(argc>1) nModifyType = argv[1];
	else nModifyType = INT2NUM(AC_DODGE_BONUS);
	if(argc>2) nDamageType = argv[2];
	else nDamageType = INT2NUM(AC_VS_DAMAGE_TYPE_ALL);
	StackPushInteger(NUM2INT(nDamageType));
	StackPushInteger(NUM2INT(nModifyType));
	StackPushInteger(NUM2INT(nValue));
	VM_ExecuteCommand(450, 3);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectMovementSpeedDecrease(VALUE self, VALUE nPercentChange)
{
	StackPushInteger(NUM2INT(nPercentChange));
	VM_ExecuteCommand(451, 1);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectSavingThrowDecrease(int argc, VALUE *argv, VALUE self)
{
	VALUE nSave, nValue, nSaveType;
	if(argc < 2)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nSave = argv[0];
	nValue = argv[1];
	if(argc>2) nSaveType = argv[2];
	else nSaveType = INT2NUM(SAVING_THROW_TYPE_ALL);
	StackPushInteger(NUM2INT(nSaveType));
	StackPushInteger(NUM2INT(nValue));
	StackPushInteger(NUM2INT(nSave));
	VM_ExecuteCommand(452, 3);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectSkillDecrease(VALUE self, VALUE nSkill, VALUE nValue)
{
	StackPushInteger(NUM2INT(nValue));
	StackPushInteger(NUM2INT(nSkill));
	VM_ExecuteCommand(453, 2);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectSpellResistanceDecrease(VALUE self, VALUE nValue)
{
	StackPushInteger(NUM2INT(nValue));
	VM_ExecuteCommand(454, 1);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_GetPlotFlag(int argc, VALUE *argv, VALUE self)
{
	VALUE oTarget;
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oTarget = argv[0];
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
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectConcealment(int argc, VALUE *argv, VALUE self)
{
	VALUE nPercentage, nMissType;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nPercentage = argv[0];
	if(argc>1) nMissType = argv[1];
	else nMissType = INT2NUM(MISS_CHANCE_TYPE_NORMAL);
	StackPushInteger(NUM2INT(nMissType));
	StackPushInteger(NUM2INT(nPercentage));
	VM_ExecuteCommand(458, 2);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectDarkness()
{
	VM_ExecuteCommand(459, 0);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectDispelMagicAll(int argc, VALUE *argv, VALUE self)
{
	VALUE nCasterLevel;
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) nCasterLevel = argv[0];
	else nCasterLevel = INT2NUM(USE_CREATURE_LEVEL);
	StackPushInteger(NUM2INT(nCasterLevel));
	VM_ExecuteCommand(460, 1);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectUltravision()
{
	VM_ExecuteCommand(461, 0);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectNegativeLevel(int argc, VALUE *argv, VALUE self)
{
	VALUE nNumLevels, bHPBonus;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nNumLevels = argv[0];
	if(argc>1) bHPBonus = argv[1];
	else bHPBonus = INT2NUM(FALSE);
	StackPushInteger(NUM2INT(bHPBonus));
	StackPushInteger(NUM2INT(nNumLevels));
	VM_ExecuteCommand(462, 2);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectPolymorph(int argc, VALUE *argv, VALUE self)
{
	VALUE nPolymorphSelection, nLocked;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nPolymorphSelection = argv[0];
	if(argc>1) nLocked = argv[1];
	else nLocked = INT2NUM(FALSE);
	StackPushInteger(NUM2INT(nLocked));
	StackPushInteger(NUM2INT(nPolymorphSelection));
	VM_ExecuteCommand(463, 2);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectSanctuary(VALUE self, VALUE nDifficultyClass)
{
	StackPushInteger(NUM2INT(nDifficultyClass));
	VM_ExecuteCommand(464, 1);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectTrueSeeing()
{
	VM_ExecuteCommand(465, 0);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectSeeInvisible()
{
	VM_ExecuteCommand(466, 0);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectTimeStop()
{
	VM_ExecuteCommand(467, 0);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectBlindness()
{
	VM_ExecuteCommand(468, 0);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_GetIsReactionTypeFriendly(int argc, VALUE *argv, VALUE self)
{
	VALUE oTarget, oSource;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oTarget = argv[0];
	if(argc>1) oSource = argv[1];
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
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oTarget = argv[0];
	if(argc>1) oSource = argv[1];
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
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oTarget = argv[0];
	if(argc>1) oSource = argv[1];
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
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nMaxSpellLevelAbsorbed = argv[0];
	if(argc>1) nTotalSpellLevelsAbsorbed = argv[1];
	else nTotalSpellLevelsAbsorbed = INT2NUM(0);
	if(argc>2) nSpellSchool = argv[2];
	else nSpellSchool = INT2NUM(SPELL_SCHOOL_GENERAL);
	StackPushInteger(NUM2INT(nSpellSchool));
	StackPushInteger(NUM2INT(nTotalSpellLevelsAbsorbed));
	StackPushInteger(NUM2INT(nMaxSpellLevelAbsorbed));
	VM_ExecuteCommand(472, 3);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectDispelMagicBest(int argc, VALUE *argv, VALUE self)
{
	VALUE nCasterLevel;
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) nCasterLevel = argv[0];
	else nCasterLevel = INT2NUM(USE_CREATURE_LEVEL);
	StackPushInteger(NUM2INT(nCasterLevel));
	VM_ExecuteCommand(473, 1);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_ActivatePortal(int argc, VALUE *argv, VALUE self)
{
	VALUE oTarget, sIPaddress, sPassword, sWaypointTag, bSeemless;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oTarget = argv[0];
	if(argc>1) sIPaddress = argv[1];
	else sIPaddress = rb_str_new2("");
	if(argc>2) sPassword = argv[2];
	else sPassword = rb_str_new2("");
	if(argc>3) sWaypointTag = argv[3];
	else sWaypointTag = rb_str_new2("");
	if(argc>4) bSeemless = argv[4];
	else bSeemless = INT2NUM(FALSE);
	StackPushInteger(NUM2INT(bSeemless));
	StackPushString(rb_str2cstr(sWaypointTag, NULL));
	StackPushString(rb_str2cstr(sPassword, NULL));
	StackPushString(rb_str2cstr(sIPaddress, NULL));
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

static VALUE NWScript_SurrenderToEnemies()
{
	VM_ExecuteCommand(476, 0);
	return Qnil;
}

static VALUE NWScript_EffectMissChance(int argc, VALUE *argv, VALUE self)
{
	VALUE nPercentage, nMissChanceType;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nPercentage = argv[0];
	if(argc>1) nMissChanceType = argv[1];
	else nMissChanceType = INT2NUM(MISS_CHANCE_TYPE_NORMAL);
	StackPushInteger(NUM2INT(nMissChanceType));
	StackPushInteger(NUM2INT(nPercentage));
	VM_ExecuteCommand(477, 2);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_GetTurnResistanceHD(int argc, VALUE *argv, VALUE self)
{
	VALUE oUndead;
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oUndead = argv[0];
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
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	lLocation = argv[0];
	if(argc>1) nAnimation = argv[1];
	else nAnimation = INT2NUM(1);
	StackPushInteger(NUM2INT(nAnimation));
	//ERROR: Undefined variable type: location
	VM_ExecuteCommand(480, 2);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectDisappear(int argc, VALUE *argv, VALUE self)
{
	VALUE nAnimation;
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) nAnimation = argv[0];
	else nAnimation = INT2NUM(1);
	StackPushInteger(NUM2INT(nAnimation));
	VM_ExecuteCommand(481, 1);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectAppear(int argc, VALUE *argv, VALUE self)
{
	VALUE nAnimation;
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) nAnimation = argv[0];
	else nAnimation = INT2NUM(1);
	StackPushInteger(NUM2INT(nAnimation));
	VM_ExecuteCommand(482, 1);
//ERROR: Undefined variable type: effect
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
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_GetLastTrapDetected(int argc, VALUE *argv, VALUE self)
{
	VALUE oTarget;
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oTarget = argv[0];
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
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_GetNearestTrapToObject(int argc, VALUE *argv, VALUE self)
{
	VALUE oTarget, nTrapDetected;
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oTarget = argv[0];
	else oTarget = INT2NUM(OBJECT_SELF);
	if(argc>1) nTrapDetected = argv[1];
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
	if(argc < 2)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nSpell = argv[0];
	oTarget = argv[1];
	if(argc>2) nProjectilePathType = argv[2];
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
	if(argc < 2)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nSpell = argv[0];
	lTarget = argv[1];
	if(argc>2) nProjectilePathType = argv[2];
	else nProjectilePathType = INT2NUM(PROJECTILE_PATH_TYPE_DEFAULT);
	StackPushInteger(NUM2INT(nProjectilePathType));
	//ERROR: Undefined variable type: location
	StackPushInteger(NUM2INT(nSpell));
	VM_ExecuteCommand(502, 3);
	return Qnil;
}

static VALUE NWScript_RemoveSummonedAssociate(int argc, VALUE *argv, VALUE self)
{
	VALUE oMaster, oAssociate;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oMaster = argv[0];
	if(argc>1) oAssociate = argv[1];
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
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oCreature = argv[0];
	else oCreature = INT2NUM(OBJECT_SELF);
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(505, 1);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastPCRested()
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

static VALUE NWScript_GetLastRestEventType()
{
	VM_ExecuteCommand(508, 0);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_StartNewModule(VALUE self, VALUE sModuleName)
{
	StackPushString(rb_str2cstr(sModuleName, NULL));
	VM_ExecuteCommand(509, 1);
	return Qnil;
}

static VALUE NWScript_EffectSwarm(int argc, VALUE *argv, VALUE self)
{
	VALUE nLooping, sCreatureTemplate1, sCreatureTemplate2, sCreatureTemplate3, sCreatureTemplate4;
	if(argc < 2)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nLooping = argv[0];
	sCreatureTemplate1 = argv[1];
	if(argc>2) sCreatureTemplate2 = argv[2];
	else sCreatureTemplate2 = rb_str_new2("");
	if(argc>3) sCreatureTemplate3 = argv[3];
	else sCreatureTemplate3 = rb_str_new2("");
	if(argc>4) sCreatureTemplate4 = argv[4];
	else sCreatureTemplate4 = rb_str_new2("");
	StackPushString(rb_str2cstr(sCreatureTemplate4, NULL));
	StackPushString(rb_str2cstr(sCreatureTemplate3, NULL));
	StackPushString(rb_str2cstr(sCreatureTemplate2, NULL));
	StackPushString(rb_str2cstr(sCreatureTemplate1, NULL));
	StackPushInteger(NUM2INT(nLooping));
	VM_ExecuteCommand(510, 5);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_GetWeaponRanged(VALUE self, VALUE oItem)
{
	StackPushObject(NUM2UINT(oItem));
	VM_ExecuteCommand(511, 1);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_DoSinglePlayerAutoSave()
{
	VM_ExecuteCommand(512, 0);
	return Qnil;
}

static VALUE NWScript_GetGameDifficulty()
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
	//ERROR: Undefined variable type: location
	VM_ExecuteCommand(514, 3);
	return Qnil;
}

static VALUE NWScript_SetTileSourceLightColor(VALUE self, VALUE lTileLocation, VALUE nSourceLight1Color, VALUE nSourceLight2Color)
{
	StackPushInteger(NUM2INT(nSourceLight2Color));
	StackPushInteger(NUM2INT(nSourceLight1Color));
	//ERROR: Undefined variable type: location
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
	//ERROR: Undefined variable type: location
	VM_ExecuteCommand(517, 1);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetTileMainLight2Color(VALUE self, VALUE lTile)
{
	//ERROR: Undefined variable type: location
	VM_ExecuteCommand(518, 1);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetTileSourceLight1Color(VALUE self, VALUE lTile)
{
	//ERROR: Undefined variable type: location
	VM_ExecuteCommand(519, 1);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetTileSourceLight2Color(VALUE self, VALUE lTile)
{
	//ERROR: Undefined variable type: location
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
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oObject = argv[0];
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
	if(argc < 2)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nStandardFaction = argv[0];
	nNewReputation = argv[1];
	if(argc>2) oCreature = argv[2];
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
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nStandardFaction = argv[0];
	if(argc>1) oCreature = argv[1];
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
	if(argc < 2)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nStrRefToDisplay = argv[0];
	oCreatureToFloatAbove = argv[1];
	if(argc>2) bBroadcastToFaction = argv[2];
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
	if(argc < 2)
	{
		//TODO: Raise exception
		return Qnil;
	}
	sStringToDisplay = argv[0];
	oCreatureToFloatAbove = argv[1];
	if(argc>2) bBroadcastToFaction = argv[2];
	else bBroadcastToFaction = INT2NUM(TRUE);
	StackPushInteger(NUM2INT(bBroadcastToFaction));
	StackPushObject(NUM2UINT(oCreatureToFloatAbove));
	StackPushString(rb_str2cstr(sStringToDisplay, NULL));
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

static VALUE NWScript_GetPCLevellingUp()
{
	VM_ExecuteCommand(542, 0);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetHasFeatEffect(int argc, VALUE *argv, VALUE self)
{
	VALUE nFeat, oObject;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nFeat = argv[0];
	if(argc>1) oObject = argv[1];
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
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oPlaceable = argv[0];
	else oPlaceable = INT2NUM(OBJECT_SELF);
	if(argc>1) bIlluminate = argv[1];
	else bIlluminate = INT2NUM(TRUE);
	StackPushInteger(NUM2INT(bIlluminate));
	StackPushObject(NUM2UINT(oPlaceable));
	VM_ExecuteCommand(544, 2);
	return Qnil;
}

static VALUE NWScript_GetPlaceableIllumination(int argc, VALUE *argv, VALUE self)
{
	VALUE oPlaceable;
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oPlaceable = argv[0];
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

static VALUE NWScript_GetFirstPC()
{
	VM_ExecuteCommand(548, 0);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetNextPC()
{
	VM_ExecuteCommand(549, 0);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_SetTrapDetectedBy(int argc, VALUE *argv, VALUE self)
{
	VALUE oTrap, oDetector, bDetected;
	if(argc < 2)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oTrap = argv[0];
	oDetector = argv[1];
	if(argc>2) bDetected = argv[2];
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
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_EffectTurnResistanceIncrease(VALUE self, VALUE nHitDice)
{
	StackPushInteger(NUM2INT(nHitDice));
	VM_ExecuteCommand(553, 1);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_PopUpDeathGUIPanel(int argc, VALUE *argv, VALUE self)
{
	VALUE oPC, bRespawnButtonEnabled, bWaitForHelpButtonEnabled, nHelpStringReference, sHelpString;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oPC = argv[0];
	if(argc>1) bRespawnButtonEnabled = argv[1];
	else bRespawnButtonEnabled = INT2NUM(TRUE);
	if(argc>2) bWaitForHelpButtonEnabled = argv[2];
	else bWaitForHelpButtonEnabled = INT2NUM(TRUE);
	if(argc>3) nHelpStringReference = argv[3];
	else nHelpStringReference = INT2NUM(0);
	if(argc>4) sHelpString = argv[4];
	else sHelpString = rb_str_new2("");
	StackPushString(rb_str2cstr(sHelpString, NULL));
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
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oVictim = argv[0];
	else oVictim = INT2NUM(OBJECT_SELF);
	StackPushObject(NUM2UINT(oVictim));
	VM_ExecuteCommand(556, 1);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_ExportAllCharacters()
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
	StackPushString(rb_str2cstr(sLogEntry, NULL));
	VM_ExecuteCommand(560, 1);
	return Qnil;
}

static VALUE NWScript_GetModuleName()
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
	StackPushString(rb_str2cstr(szMessage, NULL));
	VM_ExecuteCommand(563, 1);
	return Qnil;
}

static VALUE NWScript_EndGame(VALUE self, VALUE sEndMovie)
{
	StackPushString(rb_str2cstr(sEndMovie, NULL));
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

static VALUE NWScript_SpawnScriptDebugger()
{
	VM_ExecuteCommand(578, 0);
	return Qnil;
}

static VALUE NWScript_GetModuleItemAcquiredStackSize()
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

static VALUE NWScript_EffectPetrify()
{
	VM_ExecuteCommand(583, 0);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_CopyItem(int argc, VALUE *argv, VALUE self)
{
	VALUE oItem, oTargetInventory, bCopyVars;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oItem = argv[0];
	if(argc>1) oTargetInventory = argv[1];
	else oTargetInventory = INT2NUM(OBJECT_INVALID);
	if(argc>2) bCopyVars = argv[2];
	else bCopyVars = INT2NUM(FALSE);
	StackPushInteger(NUM2INT(bCopyVars));
	StackPushObject(NUM2UINT(oTargetInventory));
	StackPushObject(NUM2UINT(oItem));
	VM_ExecuteCommand(584, 3);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_EffectCutsceneParalyze()
{
	VM_ExecuteCommand(585, 0);
//ERROR: Undefined variable type: effect
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
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oObject = argv[0];
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
	if(argc < 3)
	{
		//TODO: Raise exception
		return Qnil;
	}
	sCampaignName = argv[0];
	sVarName = argv[1];
	flFloat = argv[2];
	if(argc>3) oPlayer = argv[3];
	else oPlayer = INT2NUM(OBJECT_INVALID);
	StackPushObject(NUM2UINT(oPlayer));
	StackPushFloat(NUM2DBL(flFloat));
	StackPushString(rb_str2cstr(sVarName, NULL));
	StackPushString(rb_str2cstr(sCampaignName, NULL));
	VM_ExecuteCommand(589, 4);
	return Qnil;
}

static VALUE NWScript_SetCampaignInt(int argc, VALUE *argv, VALUE self)
{
	VALUE sCampaignName, sVarName, nInt, oPlayer;
	if(argc < 3)
	{
		//TODO: Raise exception
		return Qnil;
	}
	sCampaignName = argv[0];
	sVarName = argv[1];
	nInt = argv[2];
	if(argc>3) oPlayer = argv[3];
	else oPlayer = INT2NUM(OBJECT_INVALID);
	StackPushObject(NUM2UINT(oPlayer));
	StackPushInteger(NUM2INT(nInt));
	StackPushString(rb_str2cstr(sVarName, NULL));
	StackPushString(rb_str2cstr(sCampaignName, NULL));
	VM_ExecuteCommand(590, 4);
	return Qnil;
}

static VALUE NWScript_SetCampaignVector(int argc, VALUE *argv, VALUE self)
{
	VALUE sCampaignName, sVarName, vVector, oPlayer;
	if(argc < 3)
	{
		//TODO: Raise exception
		return Qnil;
	}
	sCampaignName = argv[0];
	sVarName = argv[1];
	vVector = argv[2];
	if(argc>3) oPlayer = argv[3];
	else oPlayer = INT2NUM(OBJECT_INVALID);
	StackPushObject(NUM2UINT(oPlayer));
	//ERROR: Undefined variable type: vector
	StackPushString(rb_str2cstr(sVarName, NULL));
	StackPushString(rb_str2cstr(sCampaignName, NULL));
	VM_ExecuteCommand(591, 4);
	return Qnil;
}

static VALUE NWScript_SetCampaignLocation(int argc, VALUE *argv, VALUE self)
{
	VALUE sCampaignName, sVarName, locLocation, oPlayer;
	if(argc < 3)
	{
		//TODO: Raise exception
		return Qnil;
	}
	sCampaignName = argv[0];
	sVarName = argv[1];
	locLocation = argv[2];
	if(argc>3) oPlayer = argv[3];
	else oPlayer = INT2NUM(OBJECT_INVALID);
	StackPushObject(NUM2UINT(oPlayer));
	//ERROR: Undefined variable type: location
	StackPushString(rb_str2cstr(sVarName, NULL));
	StackPushString(rb_str2cstr(sCampaignName, NULL));
	VM_ExecuteCommand(592, 4);
	return Qnil;
}

static VALUE NWScript_SetCampaignString(int argc, VALUE *argv, VALUE self)
{
	VALUE sCampaignName, sVarName, sString, oPlayer;
	if(argc < 3)
	{
		//TODO: Raise exception
		return Qnil;
	}
	sCampaignName = argv[0];
	sVarName = argv[1];
	sString = argv[2];
	if(argc>3) oPlayer = argv[3];
	else oPlayer = INT2NUM(OBJECT_INVALID);
	StackPushObject(NUM2UINT(oPlayer));
	StackPushString(rb_str2cstr(sString, NULL));
	StackPushString(rb_str2cstr(sVarName, NULL));
	StackPushString(rb_str2cstr(sCampaignName, NULL));
	VM_ExecuteCommand(593, 4);
	return Qnil;
}

static VALUE NWScript_DestroyCampaignDatabase(VALUE self, VALUE sCampaignName)
{
	StackPushString(rb_str2cstr(sCampaignName, NULL));
	VM_ExecuteCommand(594, 1);
	return Qnil;
}

static VALUE NWScript_GetCampaignFloat(int argc, VALUE *argv, VALUE self)
{
	VALUE sCampaignName, sVarName, oPlayer;
	if(argc < 2)
	{
		//TODO: Raise exception
		return Qnil;
	}
	sCampaignName = argv[0];
	sVarName = argv[1];
	if(argc>2) oPlayer = argv[2];
	else oPlayer = INT2NUM(OBJECT_INVALID);
	StackPushObject(NUM2UINT(oPlayer));
	StackPushString(rb_str2cstr(sVarName, NULL));
	StackPushString(rb_str2cstr(sCampaignName, NULL));
	VM_ExecuteCommand(595, 3);
	float fRetVal;
	StackPopFloat(&fRetVal);
	return rb_float_new(fRetVal);
}

static VALUE NWScript_GetCampaignInt(int argc, VALUE *argv, VALUE self)
{
	VALUE sCampaignName, sVarName, oPlayer;
	if(argc < 2)
	{
		//TODO: Raise exception
		return Qnil;
	}
	sCampaignName = argv[0];
	sVarName = argv[1];
	if(argc>2) oPlayer = argv[2];
	else oPlayer = INT2NUM(OBJECT_INVALID);
	StackPushObject(NUM2UINT(oPlayer));
	StackPushString(rb_str2cstr(sVarName, NULL));
	StackPushString(rb_str2cstr(sCampaignName, NULL));
	VM_ExecuteCommand(596, 3);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetCampaignVector(int argc, VALUE *argv, VALUE self)
{
	VALUE sCampaignName, sVarName, oPlayer;
	if(argc < 2)
	{
		//TODO: Raise exception
		return Qnil;
	}
	sCampaignName = argv[0];
	sVarName = argv[1];
	if(argc>2) oPlayer = argv[2];
	else oPlayer = INT2NUM(OBJECT_INVALID);
	StackPushObject(NUM2UINT(oPlayer));
	StackPushString(rb_str2cstr(sVarName, NULL));
	StackPushString(rb_str2cstr(sCampaignName, NULL));
	VM_ExecuteCommand(597, 3);
//ERROR: Undefined variable type: vector
}

static VALUE NWScript_GetCampaignLocation(int argc, VALUE *argv, VALUE self)
{
	VALUE sCampaignName, sVarName, oPlayer;
	if(argc < 2)
	{
		//TODO: Raise exception
		return Qnil;
	}
	sCampaignName = argv[0];
	sVarName = argv[1];
	if(argc>2) oPlayer = argv[2];
	else oPlayer = INT2NUM(OBJECT_INVALID);
	StackPushObject(NUM2UINT(oPlayer));
	StackPushString(rb_str2cstr(sVarName, NULL));
	StackPushString(rb_str2cstr(sCampaignName, NULL));
	VM_ExecuteCommand(598, 3);
//ERROR: Undefined variable type: location
}

static VALUE NWScript_GetCampaignString(int argc, VALUE *argv, VALUE self)
{
	VALUE sCampaignName, sVarName, oPlayer;
	if(argc < 2)
	{
		//TODO: Raise exception
		return Qnil;
	}
	sCampaignName = argv[0];
	sVarName = argv[1];
	if(argc>2) oPlayer = argv[2];
	else oPlayer = INT2NUM(OBJECT_INVALID);
	StackPushObject(NUM2UINT(oPlayer));
	StackPushString(rb_str2cstr(sVarName, NULL));
	StackPushString(rb_str2cstr(sCampaignName, NULL));
	VM_ExecuteCommand(599, 3);
	char *sRetVal;
	StackPopString(&sRetVal);
	return rb_str_new2(sRetVal);
}

static VALUE NWScript_CopyObject(int argc, VALUE *argv, VALUE self)
{
	VALUE oSource, locLocation, oOwner , sNewTag ;
	if(argc < 2)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oSource = argv[0];
	locLocation = argv[1];
	if(argc>2) oOwner  = argv[2];
	else oOwner  = INT2NUM( OBJECT_INVALID);
	if(argc>3) sNewTag  = argv[3];
	else sNewTag  = rb_str_new2( "");
	StackPushString(rb_str2cstr(sNewTag , NULL));
	StackPushObject(NUM2UINT(oOwner ));
	//ERROR: Undefined variable type: location
	StackPushObject(NUM2UINT(oSource));
	VM_ExecuteCommand(600, 4);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_DeleteCampaignVariable(int argc, VALUE *argv, VALUE self)
{
	VALUE sCampaignName, sVarName, oPlayer;
	if(argc < 2)
	{
		//TODO: Raise exception
		return Qnil;
	}
	sCampaignName = argv[0];
	sVarName = argv[1];
	if(argc>2) oPlayer = argv[2];
	else oPlayer = INT2NUM(OBJECT_INVALID);
	StackPushObject(NUM2UINT(oPlayer));
	StackPushString(rb_str2cstr(sVarName, NULL));
	StackPushString(rb_str2cstr(sCampaignName, NULL));
	VM_ExecuteCommand(601, 3);
	return Qnil;
}

static VALUE NWScript_StoreCampaignObject(int argc, VALUE *argv, VALUE self)
{
	VALUE sCampaignName, sVarName, oObject, oPlayer;
	if(argc < 3)
	{
		//TODO: Raise exception
		return Qnil;
	}
	sCampaignName = argv[0];
	sVarName = argv[1];
	oObject = argv[2];
	if(argc>3) oPlayer = argv[3];
	else oPlayer = INT2NUM(OBJECT_INVALID);
	StackPushObject(NUM2UINT(oPlayer));
	StackPushObject(NUM2UINT(oObject));
	StackPushString(rb_str2cstr(sVarName, NULL));
	StackPushString(rb_str2cstr(sCampaignName, NULL));
	VM_ExecuteCommand(602, 4);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_RetrieveCampaignObject(int argc, VALUE *argv, VALUE self)
{
	VALUE sCampaignName, sVarName, locLocation, oOwner , oPlayer;
	if(argc < 3)
	{
		//TODO: Raise exception
		return Qnil;
	}
	sCampaignName = argv[0];
	sVarName = argv[1];
	locLocation = argv[2];
	if(argc>3) oOwner  = argv[3];
	else oOwner  = INT2NUM( OBJECT_INVALID);
	if(argc>4) oPlayer = argv[4];
	else oPlayer = INT2NUM(OBJECT_INVALID);
	StackPushObject(NUM2UINT(oPlayer));
	StackPushObject(NUM2UINT(oOwner ));
	//ERROR: Undefined variable type: location
	StackPushString(rb_str2cstr(sVarName, NULL));
	StackPushString(rb_str2cstr(sCampaignName, NULL));
	VM_ExecuteCommand(603, 5);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_EffectCutsceneDominated()
{
	VM_ExecuteCommand(604, 0);
//ERROR: Undefined variable type: effect
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
	if(argc < 3)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nDurationType = argv[0];
	ipProperty = argv[1];
	oItem = argv[2];
	if(argc>3) fDuration = argv[3];
	else fDuration = rb_float_new(0.0f);
	StackPushFloat(NUM2DBL(fDuration));
	StackPushObject(NUM2UINT(oItem));
	//ERROR: Undefined variable type: itemproperty
	StackPushInteger(NUM2INT(nDurationType));
	VM_ExecuteCommand(609, 4);
	return Qnil;
}

static VALUE NWScript_RemoveItemProperty(VALUE self, VALUE oItem, VALUE ipProperty)
{
	//ERROR: Undefined variable type: itemproperty
	StackPushObject(NUM2UINT(oItem));
	VM_ExecuteCommand(610, 2);
	return Qnil;
}

static VALUE NWScript_GetIsItemPropertyValid(VALUE self, VALUE ipProperty)
{
	//ERROR: Undefined variable type: itemproperty
	VM_ExecuteCommand(611, 1);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetFirstItemProperty(VALUE self, VALUE oItem)
{
	StackPushObject(NUM2UINT(oItem));
	VM_ExecuteCommand(612, 1);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_GetNextItemProperty(VALUE self, VALUE oItem)
{
	StackPushObject(NUM2UINT(oItem));
	VM_ExecuteCommand(613, 1);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_GetItemPropertyType(VALUE self, VALUE ip)
{
	//ERROR: Undefined variable type: itemproperty
	VM_ExecuteCommand(614, 1);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetItemPropertyDurationType(VALUE self, VALUE ip)
{
	//ERROR: Undefined variable type: itemproperty
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
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyACBonus(VALUE self, VALUE nBonus)
{
	StackPushInteger(NUM2INT(nBonus));
	VM_ExecuteCommand(617, 1);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyACBonusVsAlign(VALUE self, VALUE nAlignGroup, VALUE nACBonus)
{
	StackPushInteger(NUM2INT(nACBonus));
	StackPushInteger(NUM2INT(nAlignGroup));
	VM_ExecuteCommand(618, 2);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyACBonusVsDmgType(VALUE self, VALUE nDamageType, VALUE nACBonus)
{
	StackPushInteger(NUM2INT(nACBonus));
	StackPushInteger(NUM2INT(nDamageType));
	VM_ExecuteCommand(619, 2);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyACBonusVsRace(VALUE self, VALUE nRace, VALUE nACBonus)
{
	StackPushInteger(NUM2INT(nACBonus));
	StackPushInteger(NUM2INT(nRace));
	VM_ExecuteCommand(620, 2);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyACBonusVsSAlign(VALUE self, VALUE nAlign, VALUE nACBonus)
{
	StackPushInteger(NUM2INT(nACBonus));
	StackPushInteger(NUM2INT(nAlign));
	VM_ExecuteCommand(621, 2);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyEnhancementBonus(VALUE self, VALUE nEnhancementBonus)
{
	StackPushInteger(NUM2INT(nEnhancementBonus));
	VM_ExecuteCommand(622, 1);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyEnhancementBonusVsAlign(VALUE self, VALUE nAlignGroup, VALUE nBonus)
{
	StackPushInteger(NUM2INT(nBonus));
	StackPushInteger(NUM2INT(nAlignGroup));
	VM_ExecuteCommand(623, 2);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyEnhancementBonusVsRace(VALUE self, VALUE nRace, VALUE nBonus)
{
	StackPushInteger(NUM2INT(nBonus));
	StackPushInteger(NUM2INT(nRace));
	VM_ExecuteCommand(624, 2);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyEnhancementBonusVsSAlign(VALUE self, VALUE nAlign, VALUE nBonus)
{
	StackPushInteger(NUM2INT(nBonus));
	StackPushInteger(NUM2INT(nAlign));
	VM_ExecuteCommand(625, 2);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyEnhancementPenalty(VALUE self, VALUE nPenalty)
{
	StackPushInteger(NUM2INT(nPenalty));
	VM_ExecuteCommand(626, 1);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyWeightReduction(VALUE self, VALUE nReduction)
{
	StackPushInteger(NUM2INT(nReduction));
	VM_ExecuteCommand(627, 1);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyBonusFeat(VALUE self, VALUE nFeat)
{
	StackPushInteger(NUM2INT(nFeat));
	VM_ExecuteCommand(628, 1);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyBonusLevelSpell(VALUE self, VALUE nClass, VALUE nSpellLevel)
{
	StackPushInteger(NUM2INT(nSpellLevel));
	StackPushInteger(NUM2INT(nClass));
	VM_ExecuteCommand(629, 2);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyCastSpell(VALUE self, VALUE nSpell, VALUE nNumUses)
{
	StackPushInteger(NUM2INT(nNumUses));
	StackPushInteger(NUM2INT(nSpell));
	VM_ExecuteCommand(630, 2);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyDamageBonus(VALUE self, VALUE nDamageType, VALUE nDamage)
{
	StackPushInteger(NUM2INT(nDamage));
	StackPushInteger(NUM2INT(nDamageType));
	VM_ExecuteCommand(631, 2);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyDamageBonusVsAlign(VALUE self, VALUE nAlignGroup, VALUE nDamageType, VALUE nDamage)
{
	StackPushInteger(NUM2INT(nDamage));
	StackPushInteger(NUM2INT(nDamageType));
	StackPushInteger(NUM2INT(nAlignGroup));
	VM_ExecuteCommand(632, 3);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyDamageBonusVsRace(VALUE self, VALUE nRace, VALUE nDamageType, VALUE nDamage)
{
	StackPushInteger(NUM2INT(nDamage));
	StackPushInteger(NUM2INT(nDamageType));
	StackPushInteger(NUM2INT(nRace));
	VM_ExecuteCommand(633, 3);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyDamageBonusVsSAlign(VALUE self, VALUE nAlign, VALUE nDamageType, VALUE nDamage)
{
	StackPushInteger(NUM2INT(nDamage));
	StackPushInteger(NUM2INT(nDamageType));
	StackPushInteger(NUM2INT(nAlign));
	VM_ExecuteCommand(634, 3);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyDamageImmunity(VALUE self, VALUE nDamageType, VALUE nImmuneBonus)
{
	StackPushInteger(NUM2INT(nImmuneBonus));
	StackPushInteger(NUM2INT(nDamageType));
	VM_ExecuteCommand(635, 2);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyDamagePenalty(VALUE self, VALUE nPenalty)
{
	StackPushInteger(NUM2INT(nPenalty));
	VM_ExecuteCommand(636, 1);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyDamageReduction(VALUE self, VALUE nEnhancement, VALUE nHPSoak)
{
	StackPushInteger(NUM2INT(nHPSoak));
	StackPushInteger(NUM2INT(nEnhancement));
	VM_ExecuteCommand(637, 2);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyDamageResistance(VALUE self, VALUE nDamageType, VALUE nHPResist)
{
	StackPushInteger(NUM2INT(nHPResist));
	StackPushInteger(NUM2INT(nDamageType));
	VM_ExecuteCommand(638, 2);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyDamageVulnerability(VALUE self, VALUE nDamageType, VALUE nVulnerability)
{
	StackPushInteger(NUM2INT(nVulnerability));
	StackPushInteger(NUM2INT(nDamageType));
	VM_ExecuteCommand(639, 2);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyDarkvision()
{
	VM_ExecuteCommand(640, 0);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyDecreaseAbility(VALUE self, VALUE nAbility, VALUE nModifier)
{
	StackPushInteger(NUM2INT(nModifier));
	StackPushInteger(NUM2INT(nAbility));
	VM_ExecuteCommand(641, 2);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyDecreaseAC(VALUE self, VALUE nModifierType, VALUE nPenalty)
{
	StackPushInteger(NUM2INT(nPenalty));
	StackPushInteger(NUM2INT(nModifierType));
	VM_ExecuteCommand(642, 2);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyDecreaseSkill(VALUE self, VALUE nSkill, VALUE nPenalty)
{
	StackPushInteger(NUM2INT(nPenalty));
	StackPushInteger(NUM2INT(nSkill));
	VM_ExecuteCommand(643, 2);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyContainerReducedWeight(VALUE self, VALUE nContainerType)
{
	StackPushInteger(NUM2INT(nContainerType));
	VM_ExecuteCommand(644, 1);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyExtraMeleeDamageType(VALUE self, VALUE nDamageType)
{
	StackPushInteger(NUM2INT(nDamageType));
	VM_ExecuteCommand(645, 1);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyExtraRangeDamageType(VALUE self, VALUE nDamageType)
{
	StackPushInteger(NUM2INT(nDamageType));
	VM_ExecuteCommand(646, 1);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyHaste()
{
	VM_ExecuteCommand(647, 0);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyHolyAvenger()
{
	VM_ExecuteCommand(648, 0);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyImmunityMisc(VALUE self, VALUE nImmunityType)
{
	StackPushInteger(NUM2INT(nImmunityType));
	VM_ExecuteCommand(649, 1);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyImprovedEvasion()
{
	VM_ExecuteCommand(650, 0);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyBonusSpellResistance(VALUE self, VALUE nBonus)
{
	StackPushInteger(NUM2INT(nBonus));
	VM_ExecuteCommand(651, 1);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyBonusSavingThrowVsX(VALUE self, VALUE nBonusType, VALUE nBonus)
{
	StackPushInteger(NUM2INT(nBonus));
	StackPushInteger(NUM2INT(nBonusType));
	VM_ExecuteCommand(652, 2);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyBonusSavingThrow(VALUE self, VALUE nBaseSaveType, VALUE nBonus)
{
	StackPushInteger(NUM2INT(nBonus));
	StackPushInteger(NUM2INT(nBaseSaveType));
	VM_ExecuteCommand(653, 2);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyKeen()
{
	VM_ExecuteCommand(654, 0);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyLight(VALUE self, VALUE nBrightness, VALUE nColor)
{
	StackPushInteger(NUM2INT(nColor));
	StackPushInteger(NUM2INT(nBrightness));
	VM_ExecuteCommand(655, 2);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyMaxRangeStrengthMod(VALUE self, VALUE nModifier)
{
	StackPushInteger(NUM2INT(nModifier));
	VM_ExecuteCommand(656, 1);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyNoDamage()
{
	VM_ExecuteCommand(657, 0);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyOnHitProps(int argc, VALUE *argv, VALUE self)
{
	VALUE nProperty, nSaveDC, nSpecial;
	if(argc < 2)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nProperty = argv[0];
	nSaveDC = argv[1];
	if(argc>2) nSpecial = argv[2];
	else nSpecial = INT2NUM(0);
	StackPushInteger(NUM2INT(nSpecial));
	StackPushInteger(NUM2INT(nSaveDC));
	StackPushInteger(NUM2INT(nProperty));
	VM_ExecuteCommand(658, 3);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyReducedSavingThrowVsX(VALUE self, VALUE nBaseSaveType, VALUE nPenalty)
{
	StackPushInteger(NUM2INT(nPenalty));
	StackPushInteger(NUM2INT(nBaseSaveType));
	VM_ExecuteCommand(659, 2);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyReducedSavingThrow(VALUE self, VALUE nBonusType, VALUE nPenalty)
{
	StackPushInteger(NUM2INT(nPenalty));
	StackPushInteger(NUM2INT(nBonusType));
	VM_ExecuteCommand(660, 2);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyRegeneration(VALUE self, VALUE nRegenAmount)
{
	StackPushInteger(NUM2INT(nRegenAmount));
	VM_ExecuteCommand(661, 1);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertySkillBonus(VALUE self, VALUE nSkill, VALUE nBonus)
{
	StackPushInteger(NUM2INT(nBonus));
	StackPushInteger(NUM2INT(nSkill));
	VM_ExecuteCommand(662, 2);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertySpellImmunitySpecific(VALUE self, VALUE nSpell)
{
	StackPushInteger(NUM2INT(nSpell));
	VM_ExecuteCommand(663, 1);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertySpellImmunitySchool(VALUE self, VALUE nSchool)
{
	StackPushInteger(NUM2INT(nSchool));
	VM_ExecuteCommand(664, 1);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyThievesTools(VALUE self, VALUE nModifier)
{
	StackPushInteger(NUM2INT(nModifier));
	VM_ExecuteCommand(665, 1);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyAttackBonus(VALUE self, VALUE nBonus)
{
	StackPushInteger(NUM2INT(nBonus));
	VM_ExecuteCommand(666, 1);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyAttackBonusVsAlign(VALUE self, VALUE nAlignGroup, VALUE nBonus)
{
	StackPushInteger(NUM2INT(nBonus));
	StackPushInteger(NUM2INT(nAlignGroup));
	VM_ExecuteCommand(667, 2);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyAttackBonusVsRace(VALUE self, VALUE nRace, VALUE nBonus)
{
	StackPushInteger(NUM2INT(nBonus));
	StackPushInteger(NUM2INT(nRace));
	VM_ExecuteCommand(668, 2);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyAttackBonusVsSAlign(VALUE self, VALUE nAlignment, VALUE nBonus)
{
	StackPushInteger(NUM2INT(nBonus));
	StackPushInteger(NUM2INT(nAlignment));
	VM_ExecuteCommand(669, 2);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyAttackPenalty(VALUE self, VALUE nPenalty)
{
	StackPushInteger(NUM2INT(nPenalty));
	VM_ExecuteCommand(670, 1);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyUnlimitedAmmo(int argc, VALUE *argv, VALUE self)
{
	VALUE nAmmoDamage;
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) nAmmoDamage = argv[0];
	else nAmmoDamage = INT2NUM(IP_CONST_UNLIMITEDAMMO_BASIC);
	StackPushInteger(NUM2INT(nAmmoDamage));
	VM_ExecuteCommand(671, 1);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyLimitUseByAlign(VALUE self, VALUE nAlignGroup)
{
	StackPushInteger(NUM2INT(nAlignGroup));
	VM_ExecuteCommand(672, 1);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyLimitUseByClass(VALUE self, VALUE nClass)
{
	StackPushInteger(NUM2INT(nClass));
	VM_ExecuteCommand(673, 1);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyLimitUseByRace(VALUE self, VALUE nRace)
{
	StackPushInteger(NUM2INT(nRace));
	VM_ExecuteCommand(674, 1);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyLimitUseBySAlign(VALUE self, VALUE nAlignment)
{
	StackPushInteger(NUM2INT(nAlignment));
	VM_ExecuteCommand(675, 1);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_BadBadReplaceMeThisDoesNothing()
{
	VM_ExecuteCommand(676, 0);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyVampiricRegeneration(VALUE self, VALUE nRegenAmount)
{
	StackPushInteger(NUM2INT(nRegenAmount));
	VM_ExecuteCommand(677, 1);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyTrap(VALUE self, VALUE nTrapLevel, VALUE nTrapType)
{
	StackPushInteger(NUM2INT(nTrapType));
	StackPushInteger(NUM2INT(nTrapLevel));
	VM_ExecuteCommand(678, 2);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyTrueSeeing()
{
	VM_ExecuteCommand(679, 0);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyOnMonsterHitProperties(int argc, VALUE *argv, VALUE self)
{
	VALUE nProperty, nSpecial;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nProperty = argv[0];
	if(argc>1) nSpecial = argv[1];
	else nSpecial = INT2NUM(0);
	StackPushInteger(NUM2INT(nSpecial));
	StackPushInteger(NUM2INT(nProperty));
	VM_ExecuteCommand(680, 2);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyTurnResistance(VALUE self, VALUE nModifier)
{
	StackPushInteger(NUM2INT(nModifier));
	VM_ExecuteCommand(681, 1);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyMassiveCritical(VALUE self, VALUE nDamage)
{
	StackPushInteger(NUM2INT(nDamage));
	VM_ExecuteCommand(682, 1);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyFreeAction()
{
	VM_ExecuteCommand(683, 0);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyMonsterDamage(VALUE self, VALUE nDamage)
{
	StackPushInteger(NUM2INT(nDamage));
	VM_ExecuteCommand(684, 1);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyImmunityToSpellLevel(VALUE self, VALUE nLevel)
{
	StackPushInteger(NUM2INT(nLevel));
	VM_ExecuteCommand(685, 1);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertySpecialWalk(int argc, VALUE *argv, VALUE self)
{
	VALUE nWalkType;
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) nWalkType = argv[0];
	else nWalkType = INT2NUM(0);
	StackPushInteger(NUM2INT(nWalkType));
	VM_ExecuteCommand(686, 1);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyHealersKit(VALUE self, VALUE nModifier)
{
	StackPushInteger(NUM2INT(nModifier));
	VM_ExecuteCommand(687, 1);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyWeightIncrease(VALUE self, VALUE nWeight)
{
	StackPushInteger(NUM2INT(nWeight));
	VM_ExecuteCommand(688, 1);
//ERROR: Undefined variable type: itemproperty
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
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) nPercent = argv[0];
	else nPercent = INT2NUM(100);
	if(argc>1) nSpellSchool = argv[1];
	else nSpellSchool = INT2NUM(SPELL_SCHOOL_GENERAL);
	StackPushInteger(NUM2INT(nSpellSchool));
	StackPushInteger(NUM2INT(nPercent));
	VM_ExecuteCommand(690, 2);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_SpeakStringByStrRef(int argc, VALUE *argv, VALUE self)
{
	VALUE nStrRef, nTalkVolume;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nStrRef = argv[0];
	if(argc>1) nTalkVolume = argv[1];
	else nTalkVolume = INT2NUM(TALKVOLUME_TALK);
	StackPushInteger(NUM2INT(nTalkVolume));
	StackPushInteger(NUM2INT(nStrRef));
	VM_ExecuteCommand(691, 2);
	return Qnil;
}

static VALUE NWScript_SetCutsceneMode(int argc, VALUE *argv, VALUE self)
{
	VALUE oCreature, nInCutscene, nLeftClickingEnabled;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oCreature = argv[0];
	if(argc>1) nInCutscene = argv[1];
	else nInCutscene = INT2NUM(TRUE);
	if(argc>2) nLeftClickingEnabled = argv[2];
	else nLeftClickingEnabled = INT2NUM(FALSE);
	StackPushInteger(NUM2INT(nLeftClickingEnabled));
	StackPushInteger(NUM2INT(nInCutscene));
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(692, 3);
	return Qnil;
}

static VALUE NWScript_GetLastPCToCancelCutscene()
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
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oCreature = argv[0];
	if(argc>1) fSpeed = argv[1];
	else fSpeed = rb_float_new(FADE_SPEED_MEDIUM);
	StackPushFloat(NUM2DBL(fSpeed));
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(695, 2);
	return Qnil;
}

static VALUE NWScript_FadeToBlack(int argc, VALUE *argv, VALUE self)
{
	VALUE oCreature, fSpeed;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oCreature = argv[0];
	if(argc>1) fSpeed = argv[1];
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

static VALUE NWScript_StoreCameraFacing()
{
	VM_ExecuteCommand(702, 0);
	return Qnil;
}

static VALUE NWScript_RestoreCameraFacing()
{
	VM_ExecuteCommand(703, 0);
	return Qnil;
}

static VALUE NWScript_LevelUpHenchman(int argc, VALUE *argv, VALUE self)
{
	VALUE oCreature, nClass , bReadyAllSpells , nPackage ;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oCreature = argv[0];
	if(argc>1) nClass  = argv[1];
	else nClass  = INT2NUM( CLASS_TYPE_INVALID);
	if(argc>2) bReadyAllSpells  = argv[2];
	else bReadyAllSpells  = INT2NUM( FALSE);
	if(argc>3) nPackage  = argv[3];
	else nPackage  = INT2NUM( PACKAGE_INVALID);
	StackPushInteger(NUM2INT(nPackage ));
	StackPushInteger(NUM2INT(bReadyAllSpells ));
	StackPushInteger(NUM2INT(nClass ));
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
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oTarget = argv[0];
	else oTarget = INT2NUM(OBJECT_SELF);
	StackPushObject(NUM2UINT(oTarget));
	VM_ExecuteCommand(706, 1);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetModuleItemAcquiredBy()
{
	VM_ExecuteCommand(707, 0);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetImmortal(int argc, VALUE *argv, VALUE self)
{
	VALUE oTarget;
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oTarget = argv[0];
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
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) bDisplayFeedback = argv[0];
	else bDisplayFeedback = INT2NUM(TRUE);
	if(argc>1) bImproved = argv[1];
	else bImproved = INT2NUM(FALSE);
	StackPushInteger(NUM2INT(bImproved));
	StackPushInteger(NUM2INT(bDisplayFeedback));
	VM_ExecuteCommand(709, 2);
	return Qnil;
}

static VALUE NWScript_Get2DAString(VALUE self, VALUE s2DA, VALUE sColumn, VALUE nRow)
{
	StackPushInteger(NUM2INT(nRow));
	StackPushString(rb_str2cstr(sColumn, NULL));
	StackPushString(rb_str2cstr(s2DA, NULL));
	VM_ExecuteCommand(710, 3);
	char *sRetVal;
	StackPopString(&sRetVal);
	return rb_str_new2(sRetVal);
}

static VALUE NWScript_EffectEthereal()
{
	VM_ExecuteCommand(711, 0);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_GetAILevel(int argc, VALUE *argv, VALUE self)
{
	VALUE oTarget;
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oTarget = argv[0];
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
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oArea  = argv[0];
	else oArea  = INT2NUM( OBJECT_INVALID);
	StackPushObject(NUM2UINT(oArea ));
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
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nStrRef = argv[0];
	if(argc>1) nRunAsAction  = argv[1];
	else nRunAsAction  = INT2NUM( TRUE);
	StackPushInteger(NUM2INT(nRunAsAction ));
	StackPushInteger(NUM2INT(nStrRef));
	VM_ExecuteCommand(720, 2);
	return Qnil;
}

static VALUE NWScript_SetSubRace(VALUE self, VALUE oCreature, VALUE sSubRace)
{
	StackPushString(rb_str2cstr(sSubRace, NULL));
	StackPushObject(NUM2UINT(oCreature));
	VM_ExecuteCommand(721, 2);
	return Qnil;
}

static VALUE NWScript_SetDeity(VALUE self, VALUE oCreature, VALUE sDeity)
{
	StackPushString(rb_str2cstr(sDeity, NULL));
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

static VALUE NWScript_GetPCItemLastEquipped()
{
	VM_ExecuteCommand(727, 0);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetPCItemLastEquippedBy()
{
	VM_ExecuteCommand(728, 0);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetPCItemLastUnequipped()
{
	VM_ExecuteCommand(729, 0);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetPCItemLastUnequippedBy()
{
	VM_ExecuteCommand(730, 0);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_CopyItemAndModify(int argc, VALUE *argv, VALUE self)
{
	VALUE oItem, nType, nIndex, nNewValue, bCopyVars;
	if(argc < 4)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oItem = argv[0];
	nType = argv[1];
	nIndex = argv[2];
	nNewValue = argv[3];
	if(argc>4) bCopyVars = argv[4];
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
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_GetItemPropertySubType(VALUE self, VALUE iProperty)
{
	//ERROR: Undefined variable type: itemproperty
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
//ERROR: Undefined variable type: itemproperty
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

static VALUE NWScript_GetMaxHenchmen()
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
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oPlayer = argv[0];
	if(argc>1) fTransitionTime = argv[1];
	else fTransitionTime = rb_float_new(0.0f);
	StackPushFloat(NUM2DBL(fTransitionTime));
	StackPushObject(NUM2UINT(oPlayer));
	VM_ExecuteCommand(750, 2);
	return Qnil;
}

static VALUE NWScript_NightToDay(int argc, VALUE *argv, VALUE self)
{
	VALUE oPlayer, fTransitionTime;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oPlayer = argv[0];
	if(argc>1) fTransitionTime = argv[1];
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
	//ERROR: Undefined variable type: vector
	//ERROR: Undefined variable type: vector
	VM_ExecuteCommand(753, 2);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetLastSpellCastClass()
{
	VM_ExecuteCommand(754, 0);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_SetBaseAttackBonus(int argc, VALUE *argv, VALUE self)
{
	VALUE nBaseAttackBonus, oCreature ;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nBaseAttackBonus = argv[0];
	if(argc>1) oCreature  = argv[1];
	else oCreature  = INT2NUM( OBJECT_SELF);
	StackPushObject(NUM2UINT(oCreature ));
	StackPushInteger(NUM2INT(nBaseAttackBonus));
	VM_ExecuteCommand(755, 2);
	return Qnil;
}

static VALUE NWScript_RestoreBaseAttackBonus(int argc, VALUE *argv, VALUE self)
{
	VALUE oCreature ;
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oCreature  = argv[0];
	else oCreature  = INT2NUM( OBJECT_SELF);
	StackPushObject(NUM2UINT(oCreature ));
	VM_ExecuteCommand(756, 1);
	return Qnil;
}

static VALUE NWScript_EffectCutsceneGhost()
{
	VM_ExecuteCommand(757, 0);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_ItemPropertyArcaneSpellFailure(VALUE self, VALUE nModLevel)
{
	StackPushInteger(NUM2INT(nModLevel));
	VM_ExecuteCommand(758, 1);
//ERROR: Undefined variable type: itemproperty
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

static VALUE NWScript_EffectCutsceneImmobilize()
{
	VM_ExecuteCommand(767, 0);
//ERROR: Undefined variable type: effect
}

static VALUE NWScript_GetIsInSubArea(int argc, VALUE *argv, VALUE self)
{
	VALUE oCreature, oSubArea;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oCreature = argv[0];
	if(argc>1) oSubArea = argv[1];
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
	//ERROR: Undefined variable type: itemproperty
	VM_ExecuteCommand(769, 1);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetItemPropertyCostTableValue(VALUE self, VALUE iProp)
{
	//ERROR: Undefined variable type: itemproperty
	VM_ExecuteCommand(770, 1);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetItemPropertyParam1(VALUE self, VALUE iProp)
{
	//ERROR: Undefined variable type: itemproperty
	VM_ExecuteCommand(771, 1);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetItemPropertyParam1Value(VALUE self, VALUE iProp)
{
	//ERROR: Undefined variable type: itemproperty
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
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oPlayer = argv[0];
	if(argc>1) fHeight = argv[1];
	else fHeight = rb_float_new(0.0f);
	StackPushFloat(NUM2DBL(fHeight));
	StackPushObject(NUM2UINT(oPlayer));
	VM_ExecuteCommand(776, 2);
	return Qnil;
}

static VALUE NWScript_SetSkyBox(int argc, VALUE *argv, VALUE self)
{
	VALUE nSkyBox, oArea;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nSkyBox = argv[0];
	if(argc>1) oArea = argv[1];
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
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nPhenoType = argv[0];
	if(argc>1) oCreature = argv[1];
	else oCreature = INT2NUM(OBJECT_SELF);
	StackPushObject(NUM2UINT(oCreature));
	StackPushInteger(NUM2INT(nPhenoType));
	VM_ExecuteCommand(779, 2);
	return Qnil;
}

static VALUE NWScript_SetFogColor(int argc, VALUE *argv, VALUE self)
{
	VALUE nFogType, nFogColor, oArea;
	if(argc < 2)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nFogType = argv[0];
	nFogColor = argv[1];
	if(argc>2) oArea = argv[2];
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
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oCreature = argv[0];
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
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oArea = argv[0];
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
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nFogType = argv[0];
	if(argc>1) oArea = argv[1];
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
	if(argc < 2)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nFogType = argv[0];
	nFogAmount = argv[1];
	if(argc>2) oArea = argv[2];
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
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nFogType = argv[0];
	if(argc>1) oArea = argv[1];
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
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oCreature = argv[0];
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
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nFootstepType = argv[0];
	if(argc>1) oCreature = argv[1];
	else oCreature = INT2NUM(OBJECT_SELF);
	StackPushObject(NUM2UINT(oCreature));
	StackPushInteger(NUM2INT(nFootstepType));
	VM_ExecuteCommand(789, 2);
	return Qnil;
}

static VALUE NWScript_GetCreatureWingType(int argc, VALUE *argv, VALUE self)
{
	VALUE oCreature;
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oCreature = argv[0];
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
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nWingType = argv[0];
	if(argc>1) oCreature = argv[1];
	else oCreature = INT2NUM(OBJECT_SELF);
	StackPushObject(NUM2UINT(oCreature));
	StackPushInteger(NUM2INT(nWingType));
	VM_ExecuteCommand(791, 2);
	return Qnil;
}

static VALUE NWScript_GetCreatureBodyPart(int argc, VALUE *argv, VALUE self)
{
	VALUE nPart, oCreature;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nPart = argv[0];
	if(argc>1) oCreature = argv[1];
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
	if(argc < 2)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nPart = argv[0];
	nModelNumber = argv[1];
	if(argc>2) oCreature = argv[2];
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
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oCreature = argv[0];
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
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nTailType = argv[0];
	if(argc>1) oCreature = argv[1];
	else oCreature = INT2NUM(OBJECT_SELF);
	StackPushObject(NUM2UINT(oCreature));
	StackPushInteger(NUM2INT(nTailType));
	VM_ExecuteCommand(795, 2);
	return Qnil;
}

static VALUE NWScript_GetHardness(int argc, VALUE *argv, VALUE self)
{
	VALUE oObject;
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oObject = argv[0];
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
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nHardness = argv[0];
	if(argc>1) oObject = argv[1];
	else oObject = INT2NUM(OBJECT_SELF);
	StackPushObject(NUM2UINT(oObject));
	StackPushInteger(NUM2INT(nHardness));
	VM_ExecuteCommand(797, 2);
	return Qnil;
}

static VALUE NWScript_SetLockKeyRequired(int argc, VALUE *argv, VALUE self)
{
	VALUE oObject, nKeyRequired;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oObject = argv[0];
	if(argc>1) nKeyRequired = argv[1];
	else nKeyRequired = INT2NUM(TRUE);
	StackPushInteger(NUM2INT(nKeyRequired));
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(798, 2);
	return Qnil;
}

static VALUE NWScript_SetLockKeyTag(VALUE self, VALUE oObject, VALUE sNewKeyTag)
{
	StackPushString(rb_str2cstr(sNewKeyTag, NULL));
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(799, 2);
	return Qnil;
}

static VALUE NWScript_SetLockLockable(int argc, VALUE *argv, VALUE self)
{
	VALUE oObject, nLockable;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oObject = argv[0];
	if(argc>1) nLockable = argv[1];
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
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oTrapObject = argv[0];
	if(argc>1) nDisarmable = argv[1];
	else nDisarmable = INT2NUM(TRUE);
	StackPushInteger(NUM2INT(nDisarmable));
	StackPushObject(NUM2UINT(oTrapObject));
	VM_ExecuteCommand(803, 2);
	return Qnil;
}

static VALUE NWScript_SetTrapDetectable(int argc, VALUE *argv, VALUE self)
{
	VALUE oTrapObject, nDetectable;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oTrapObject = argv[0];
	if(argc>1) nDetectable = argv[1];
	else nDetectable = INT2NUM(TRUE);
	StackPushInteger(NUM2INT(nDetectable));
	StackPushObject(NUM2UINT(oTrapObject));
	VM_ExecuteCommand(804, 2);
	return Qnil;
}

static VALUE NWScript_SetTrapOneShot(int argc, VALUE *argv, VALUE self)
{
	VALUE oTrapObject, nOneShot;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oTrapObject = argv[0];
	if(argc>1) nOneShot = argv[1];
	else nOneShot = INT2NUM(TRUE);
	StackPushInteger(NUM2INT(nOneShot));
	StackPushObject(NUM2UINT(oTrapObject));
	VM_ExecuteCommand(805, 2);
	return Qnil;
}

static VALUE NWScript_SetTrapKeyTag(VALUE self, VALUE oTrapObject, VALUE sKeyTag)
{
	StackPushString(rb_str2cstr(sKeyTag, NULL));
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
	if(argc < 2)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nTrapType = argv[0];
	lLocation = argv[1];
	if(argc>2) fSize = argv[2];
	else fSize = rb_float_new(2.0f);
	if(argc>3) sTag = argv[3];
	else sTag = rb_str_new2("");
	if(argc>4) nFaction = argv[4];
	else nFaction = INT2NUM(STANDARD_FACTION_HOSTILE);
	if(argc>5) sOnDisarmScript = argv[5];
	else sOnDisarmScript = rb_str_new2("");
	if(argc>6) sOnTrapTriggeredScript = argv[6];
	else sOnTrapTriggeredScript = rb_str_new2("");
	StackPushString(rb_str2cstr(sOnTrapTriggeredScript, NULL));
	StackPushString(rb_str2cstr(sOnDisarmScript, NULL));
	StackPushInteger(NUM2INT(nFaction));
	StackPushString(rb_str2cstr(sTag, NULL));
	StackPushFloat(NUM2DBL(fSize));
	//ERROR: Undefined variable type: location
	StackPushInteger(NUM2INT(nTrapType));
	VM_ExecuteCommand(809, 7);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_CreateTrapOnObject(int argc, VALUE *argv, VALUE self)
{
	VALUE nTrapType, oObject, nFaction, sOnDisarmScript, sOnTrapTriggeredScript;
	if(argc < 2)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nTrapType = argv[0];
	oObject = argv[1];
	if(argc>2) nFaction = argv[2];
	else nFaction = INT2NUM(STANDARD_FACTION_HOSTILE);
	if(argc>3) sOnDisarmScript = argv[3];
	else sOnDisarmScript = rb_str_new2("");
	if(argc>4) sOnTrapTriggeredScript = argv[4];
	else sOnTrapTriggeredScript = rb_str_new2("");
	StackPushString(rb_str2cstr(sOnTrapTriggeredScript, NULL));
	StackPushString(rb_str2cstr(sOnDisarmScript, NULL));
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
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oTrapObject = argv[0];
	if(argc>1) nRecoverable = argv[1];
	else nRecoverable = INT2NUM(TRUE);
	StackPushInteger(NUM2INT(nRecoverable));
	StackPushObject(NUM2UINT(oTrapObject));
	VM_ExecuteCommand(816, 2);
	return Qnil;
}

static VALUE NWScript_GetModuleXPScale()
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
	StackPushString(rb_str2cstr(sFeedbackMessage, NULL));
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
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oTrapObject = argv[0];
	if(argc>1) nActive = argv[1];
	else nActive = INT2NUM(TRUE);
	StackPushInteger(NUM2INT(nActive));
	StackPushObject(NUM2UINT(oTrapObject));
	VM_ExecuteCommand(822, 2);
	return Qnil;
}

static VALUE NWScript_LockCameraPitch(int argc, VALUE *argv, VALUE self)
{
	VALUE oPlayer, bLocked;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oPlayer = argv[0];
	if(argc>1) bLocked = argv[1];
	else bLocked = INT2NUM(TRUE);
	StackPushInteger(NUM2INT(bLocked));
	StackPushObject(NUM2UINT(oPlayer));
	VM_ExecuteCommand(823, 2);
	return Qnil;
}

static VALUE NWScript_LockCameraDistance(int argc, VALUE *argv, VALUE self)
{
	VALUE oPlayer, bLocked;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oPlayer = argv[0];
	if(argc>1) bLocked = argv[1];
	else bLocked = INT2NUM(TRUE);
	StackPushInteger(NUM2INT(bLocked));
	StackPushObject(NUM2UINT(oPlayer));
	VM_ExecuteCommand(824, 2);
	return Qnil;
}

static VALUE NWScript_LockCameraDirection(int argc, VALUE *argv, VALUE self)
{
	VALUE oPlayer, bLocked;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oPlayer = argv[0];
	if(argc>1) bLocked = argv[1];
	else bLocked = INT2NUM(TRUE);
	StackPushInteger(NUM2INT(bLocked));
	StackPushObject(NUM2UINT(oPlayer));
	VM_ExecuteCommand(825, 2);
	return Qnil;
}

static VALUE NWScript_GetPlaceableLastClickedBy()
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
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oItem = argv[0];
	if(argc>1) bInfinite = argv[1];
	else bInfinite = INT2NUM(TRUE);
	StackPushInteger(NUM2INT(bInfinite));
	StackPushObject(NUM2UINT(oItem));
	VM_ExecuteCommand(828, 2);
	return Qnil;
}

static VALUE NWScript_GetAreaSize(int argc, VALUE *argv, VALUE self)
{
	VALUE nAreaDimension, oArea;
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	nAreaDimension = argv[0];
	if(argc>1) oArea = argv[1];
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
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oObject = argv[0];
	if(argc>1) sNewName = argv[1];
	else sNewName = rb_str_new2("");
	StackPushString(rb_str2cstr(sNewName, NULL));
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(830, 2);
	return Qnil;
}

static VALUE NWScript_GetPortraitId(int argc, VALUE *argv, VALUE self)
{
	VALUE oTarget;
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oTarget = argv[0];
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
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) oTarget = argv[0];
	else oTarget = INT2NUM(OBJECT_SELF);
	StackPushObject(NUM2UINT(oTarget));
	VM_ExecuteCommand(833, 1);
	char *sRetVal;
	StackPopString(&sRetVal);
	return rb_str_new2(sRetVal);
}

static VALUE NWScript_SetPortraitResRef(VALUE self, VALUE oTarget, VALUE sPortraitResRef)
{
	StackPushString(rb_str2cstr(sPortraitResRef, NULL));
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
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oObject = argv[0];
	if(argc>1) bOriginalDescription = argv[1];
	else bOriginalDescription = INT2NUM(FALSE);
	if(argc>2) bIdentifiedDescription = argv[2];
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
	if(argc < 1)
	{
		//TODO: Raise exception
		return Qnil;
	}
	oObject = argv[0];
	if(argc>1) sNewDescription = argv[1];
	else sNewDescription = rb_str_new2("");
	if(argc>2) bIdentifiedDescription = argv[2];
	else bIdentifiedDescription = INT2NUM(TRUE);
	StackPushInteger(NUM2INT(bIdentifiedDescription));
	StackPushString(rb_str2cstr(sNewDescription, NULL));
	StackPushObject(NUM2UINT(oObject));
	VM_ExecuteCommand(837, 3);
	return Qnil;
}

static VALUE NWScript_GetPCChatSpeaker()
{
	VM_ExecuteCommand(838, 0);
	dword nRetVal;
	StackPopObject(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_GetPCChatMessage()
{
	VM_ExecuteCommand(839, 0);
	char *sRetVal;
	StackPopString(&sRetVal);
	return rb_str_new2(sRetVal);
}

static VALUE NWScript_GetPCChatVolume()
{
	VM_ExecuteCommand(840, 0);
	int nRetVal;
	StackPopInteger(&nRetVal);
	return INT2NUM(nRetVal);
}

static VALUE NWScript_SetPCChatMessage(int argc, VALUE *argv, VALUE self)
{
	VALUE sNewChatMessage;
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) sNewChatMessage = argv[0];
	else sNewChatMessage = rb_str_new2("");
	StackPushString(rb_str2cstr(sNewChatMessage, NULL));
	VM_ExecuteCommand(841, 1);
	return Qnil;
}

static VALUE NWScript_SetPCChatVolume(int argc, VALUE *argv, VALUE self)
{
	VALUE nTalkVolume;
	if(argc < 0)
	{
		//TODO: Raise exception
		return Qnil;
	}
	if(argc>0) nTalkVolume = argv[0];
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
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyQuality(VALUE self, VALUE nQuality)
{
	StackPushInteger(NUM2INT(nQuality));
	VM_ExecuteCommand(846, 1);
//ERROR: Undefined variable type: itemproperty
}

static VALUE NWScript_ItemPropertyAdditional(VALUE self, VALUE nAdditionalProperty)
{
	StackPushInteger(NUM2INT(nAdditionalProperty));
	VM_ExecuteCommand(847, 1);
//ERROR: Undefined variable type: itemproperty
}



VALUE RubyInt_InitNWScript()
{
	VALUE cNWScript = rb_define_class("NWScript", rb_cObject);
	rb_define_method(cNWScript, "Random", NWScript_Random, 1);
	rb_define_method(cNWScript, "PrintString", NWScript_PrintString, 1);
	rb_define_method(cNWScript, "PrintFloat", NWScript_PrintFloat, -1);
	rb_define_method(cNWScript, "FloatToString", NWScript_FloatToString, -1);
	rb_define_method(cNWScript, "PrintInteger", NWScript_PrintInteger, 1);
	rb_define_method(cNWScript, "PrintObject", NWScript_PrintObject, 1);
	rb_define_method(cNWScript, "AssignCommand", NWScript_AssignCommand, 2);
	rb_define_method(cNWScript, "DelayCommand", NWScript_DelayCommand, 2);
	rb_define_method(cNWScript, "ExecuteScript", NWScript_ExecuteScript, 2);
	rb_define_method(cNWScript, "ClearAllActions", NWScript_ClearAllActions, -1);
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
	rb_define_method(cNWScript, "ActionMoveToLocation", NWScript_ActionMoveToLocation, -1);
	rb_define_method(cNWScript, "ActionMoveToObject", NWScript_ActionMoveToObject, -1);
	rb_define_method(cNWScript, "ActionMoveAwayFromObject", NWScript_ActionMoveAwayFromObject, -1);
	rb_define_method(cNWScript, "GetArea", NWScript_GetArea, 1);
	rb_define_method(cNWScript, "GetEnteringObject", NWScript_GetEnteringObject, 0);
	rb_define_method(cNWScript, "GetExitingObject", NWScript_GetExitingObject, 0);
	rb_define_method(cNWScript, "GetPosition", NWScript_GetPosition, 1);
	rb_define_method(cNWScript, "GetFacing", NWScript_GetFacing, 1);
	rb_define_method(cNWScript, "GetItemPossessor", NWScript_GetItemPossessor, 1);
	rb_define_method(cNWScript, "GetItemPossessedBy", NWScript_GetItemPossessedBy, 2);
	rb_define_method(cNWScript, "CreateItemOnObject", NWScript_CreateItemOnObject, -1);
	rb_define_method(cNWScript, "ActionEquipItem", NWScript_ActionEquipItem, 2);
	rb_define_method(cNWScript, "ActionUnequipItem", NWScript_ActionUnequipItem, 1);
	rb_define_method(cNWScript, "ActionPickUpItem", NWScript_ActionPickUpItem, 1);
	rb_define_method(cNWScript, "ActionPutDownItem", NWScript_ActionPutDownItem, 1);
	rb_define_method(cNWScript, "GetLastAttacker", NWScript_GetLastAttacker, -1);
	rb_define_method(cNWScript, "ActionAttack", NWScript_ActionAttack, -1);
	rb_define_method(cNWScript, "GetNearestCreature", NWScript_GetNearestCreature, -1);
	rb_define_method(cNWScript, "ActionSpeakString", NWScript_ActionSpeakString, -1);
	rb_define_method(cNWScript, "ActionPlayAnimation", NWScript_ActionPlayAnimation, -1);
	rb_define_method(cNWScript, "GetDistanceToObject", NWScript_GetDistanceToObject, 1);
	rb_define_method(cNWScript, "GetIsObjectValid", NWScript_GetIsObjectValid, 1);
	rb_define_method(cNWScript, "ActionOpenDoor", NWScript_ActionOpenDoor, 1);
	rb_define_method(cNWScript, "ActionCloseDoor", NWScript_ActionCloseDoor, 1);
	rb_define_method(cNWScript, "SetCameraFacing", NWScript_SetCameraFacing, -1);
	rb_define_method(cNWScript, "PlaySound", NWScript_PlaySound, 1);
	rb_define_method(cNWScript, "GetSpellTargetObject", NWScript_GetSpellTargetObject, 0);
	rb_define_method(cNWScript, "ActionCastSpellAtObject", NWScript_ActionCastSpellAtObject, -1);
	rb_define_method(cNWScript, "GetCurrentHitPoints", NWScript_GetCurrentHitPoints, -1);
	rb_define_method(cNWScript, "GetMaxHitPoints", NWScript_GetMaxHitPoints, -1);
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
	rb_define_method(cNWScript, "FindSubString", NWScript_FindSubString, -1);
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
	rb_define_method(cNWScript, "EffectDamage", NWScript_EffectDamage, -1);
	rb_define_method(cNWScript, "EffectAbilityIncrease", NWScript_EffectAbilityIncrease, 2);
	rb_define_method(cNWScript, "EffectDamageResistance", NWScript_EffectDamageResistance, -1);
	rb_define_method(cNWScript, "EffectResurrection", NWScript_EffectResurrection, 0);
	rb_define_method(cNWScript, "EffectSummonCreature", NWScript_EffectSummonCreature, -1);
	rb_define_method(cNWScript, "GetCasterLevel", NWScript_GetCasterLevel, 1);
	rb_define_method(cNWScript, "GetFirstEffect", NWScript_GetFirstEffect, 1);
	rb_define_method(cNWScript, "GetNextEffect", NWScript_GetNextEffect, 1);
	rb_define_method(cNWScript, "RemoveEffect", NWScript_RemoveEffect, 2);
	rb_define_method(cNWScript, "GetIsEffectValid", NWScript_GetIsEffectValid, 1);
	rb_define_method(cNWScript, "GetEffectDurationType", NWScript_GetEffectDurationType, 1);
	rb_define_method(cNWScript, "GetEffectSubType", NWScript_GetEffectSubType, 1);
	rb_define_method(cNWScript, "GetEffectCreator", NWScript_GetEffectCreator, 1);
	rb_define_method(cNWScript, "IntToString", NWScript_IntToString, 1);
	rb_define_method(cNWScript, "GetFirstObjectInArea", NWScript_GetFirstObjectInArea, -1);
	rb_define_method(cNWScript, "GetNextObjectInArea", NWScript_GetNextObjectInArea, -1);
	rb_define_method(cNWScript, "d2", NWScript_d2, -1);
	rb_define_method(cNWScript, "d3", NWScript_d3, -1);
	rb_define_method(cNWScript, "d4", NWScript_d4, -1);
	rb_define_method(cNWScript, "d6", NWScript_d6, -1);
	rb_define_method(cNWScript, "d8", NWScript_d8, -1);
	rb_define_method(cNWScript, "d10", NWScript_d10, -1);
	rb_define_method(cNWScript, "d12", NWScript_d12, -1);
	rb_define_method(cNWScript, "d20", NWScript_d20, -1);
	rb_define_method(cNWScript, "d100", NWScript_d100, -1);
	rb_define_method(cNWScript, "VectorMagnitude", NWScript_VectorMagnitude, 1);
	rb_define_method(cNWScript, "GetMetaMagicFeat", NWScript_GetMetaMagicFeat, 0);
	rb_define_method(cNWScript, "GetObjectType", NWScript_GetObjectType, 1);
	rb_define_method(cNWScript, "GetRacialType", NWScript_GetRacialType, 1);
	rb_define_method(cNWScript, "FortitudeSave", NWScript_FortitudeSave, -1);
	rb_define_method(cNWScript, "ReflexSave", NWScript_ReflexSave, -1);
	rb_define_method(cNWScript, "WillSave", NWScript_WillSave, -1);
	rb_define_method(cNWScript, "GetSpellSaveDC", NWScript_GetSpellSaveDC, 0);
	rb_define_method(cNWScript, "MagicalEffect", NWScript_MagicalEffect, 1);
	rb_define_method(cNWScript, "SupernaturalEffect", NWScript_SupernaturalEffect, 1);
	rb_define_method(cNWScript, "ExtraordinaryEffect", NWScript_ExtraordinaryEffect, 1);
	rb_define_method(cNWScript, "EffectACIncrease", NWScript_EffectACIncrease, -1);
	rb_define_method(cNWScript, "GetAC", NWScript_GetAC, -1);
	rb_define_method(cNWScript, "EffectSavingThrowIncrease", NWScript_EffectSavingThrowIncrease, -1);
	rb_define_method(cNWScript, "EffectAttackIncrease", NWScript_EffectAttackIncrease, -1);
	rb_define_method(cNWScript, "EffectDamageReduction", NWScript_EffectDamageReduction, -1);
	rb_define_method(cNWScript, "EffectDamageIncrease", NWScript_EffectDamageIncrease, -1);
	rb_define_method(cNWScript, "RoundsToSeconds", NWScript_RoundsToSeconds, 1);
	rb_define_method(cNWScript, "HoursToSeconds", NWScript_HoursToSeconds, 1);
	rb_define_method(cNWScript, "TurnsToSeconds", NWScript_TurnsToSeconds, 1);
	rb_define_method(cNWScript, "GetLawChaosValue", NWScript_GetLawChaosValue, 1);
	rb_define_method(cNWScript, "GetGoodEvilValue", NWScript_GetGoodEvilValue, 1);
	rb_define_method(cNWScript, "GetAlignmentLawChaos", NWScript_GetAlignmentLawChaos, 1);
	rb_define_method(cNWScript, "GetAlignmentGoodEvil", NWScript_GetAlignmentGoodEvil, 1);
	rb_define_method(cNWScript, "EffectEntangle", NWScript_EffectEntangle, 0);
	rb_define_method(cNWScript, "SignalEvent", NWScript_SignalEvent, 2);
	rb_define_method(cNWScript, "EventUserDefined", NWScript_EventUserDefined, 1);
	rb_define_method(cNWScript, "EffectDeath", NWScript_EffectDeath, -1);
	rb_define_method(cNWScript, "EffectKnockdown", NWScript_EffectKnockdown, 0);
	rb_define_method(cNWScript, "ActionGiveItem", NWScript_ActionGiveItem, 2);
	rb_define_method(cNWScript, "ActionTakeItem", NWScript_ActionTakeItem, 2);
	rb_define_method(cNWScript, "VectorNormalize", NWScript_VectorNormalize, 1);
	rb_define_method(cNWScript, "EffectCurse", NWScript_EffectCurse, -1);
	rb_define_method(cNWScript, "GetAbilityScore", NWScript_GetAbilityScore, -1);
	rb_define_method(cNWScript, "GetIsDead", NWScript_GetIsDead, 1);
	rb_define_method(cNWScript, "PrintVector", NWScript_PrintVector, 2);
	rb_define_method(cNWScript, "Vector", NWScript_Vector, -1);
	rb_define_method(cNWScript, "SetFacingPoint", NWScript_SetFacingPoint, 1);
	rb_define_method(cNWScript, "AngleToVector", NWScript_AngleToVector, 1);
	rb_define_method(cNWScript, "VectorToAngle", NWScript_VectorToAngle, 1);
	rb_define_method(cNWScript, "TouchAttackMelee", NWScript_TouchAttackMelee, -1);
	rb_define_method(cNWScript, "TouchAttackRanged", NWScript_TouchAttackRanged, -1);
	rb_define_method(cNWScript, "EffectParalyze", NWScript_EffectParalyze, 0);
	rb_define_method(cNWScript, "EffectSpellImmunity", NWScript_EffectSpellImmunity, -1);
	rb_define_method(cNWScript, "EffectDeaf", NWScript_EffectDeaf, 0);
	rb_define_method(cNWScript, "GetDistanceBetween", NWScript_GetDistanceBetween, 2);
	rb_define_method(cNWScript, "SetLocalLocation", NWScript_SetLocalLocation, 3);
	rb_define_method(cNWScript, "GetLocalLocation", NWScript_GetLocalLocation, 2);
	rb_define_method(cNWScript, "EffectSleep", NWScript_EffectSleep, 0);
	rb_define_method(cNWScript, "GetItemInSlot", NWScript_GetItemInSlot, -1);
	rb_define_method(cNWScript, "EffectCharmed", NWScript_EffectCharmed, 0);
	rb_define_method(cNWScript, "EffectConfused", NWScript_EffectConfused, 0);
	rb_define_method(cNWScript, "EffectFrightened", NWScript_EffectFrightened, 0);
	rb_define_method(cNWScript, "EffectDominated", NWScript_EffectDominated, 0);
	rb_define_method(cNWScript, "EffectDazed", NWScript_EffectDazed, 0);
	rb_define_method(cNWScript, "EffectStunned", NWScript_EffectStunned, 0);
	rb_define_method(cNWScript, "SetCommandable", NWScript_SetCommandable, -1);
	rb_define_method(cNWScript, "GetCommandable", NWScript_GetCommandable, -1);
	rb_define_method(cNWScript, "EffectRegenerate", NWScript_EffectRegenerate, 2);
	rb_define_method(cNWScript, "EffectMovementSpeedIncrease", NWScript_EffectMovementSpeedIncrease, 1);
	rb_define_method(cNWScript, "GetHitDice", NWScript_GetHitDice, 1);
	rb_define_method(cNWScript, "ActionForceFollowObject", NWScript_ActionForceFollowObject, -1);
	rb_define_method(cNWScript, "GetTag", NWScript_GetTag, 1);
	rb_define_method(cNWScript, "ResistSpell", NWScript_ResistSpell, 2);
	rb_define_method(cNWScript, "GetEffectType", NWScript_GetEffectType, 1);
	rb_define_method(cNWScript, "EffectAreaOfEffect", NWScript_EffectAreaOfEffect, -1);
	rb_define_method(cNWScript, "GetFactionEqual", NWScript_GetFactionEqual, -1);
	rb_define_method(cNWScript, "ChangeFaction", NWScript_ChangeFaction, 2);
	rb_define_method(cNWScript, "GetIsListening", NWScript_GetIsListening, 1);
	rb_define_method(cNWScript, "SetListening", NWScript_SetListening, 2);
	rb_define_method(cNWScript, "SetListenPattern", NWScript_SetListenPattern, -1);
	rb_define_method(cNWScript, "TestStringAgainstPattern", NWScript_TestStringAgainstPattern, 2);
	rb_define_method(cNWScript, "GetMatchedSubstring", NWScript_GetMatchedSubstring, 1);
	rb_define_method(cNWScript, "GetMatchedSubstringsCount", NWScript_GetMatchedSubstringsCount, 0);
	rb_define_method(cNWScript, "EffectVisualEffect", NWScript_EffectVisualEffect, -1);
	rb_define_method(cNWScript, "GetFactionWeakestMember", NWScript_GetFactionWeakestMember, -1);
	rb_define_method(cNWScript, "GetFactionStrongestMember", NWScript_GetFactionStrongestMember, -1);
	rb_define_method(cNWScript, "GetFactionMostDamagedMember", NWScript_GetFactionMostDamagedMember, -1);
	rb_define_method(cNWScript, "GetFactionLeastDamagedMember", NWScript_GetFactionLeastDamagedMember, -1);
	rb_define_method(cNWScript, "GetFactionGold", NWScript_GetFactionGold, 1);
	rb_define_method(cNWScript, "GetFactionAverageReputation", NWScript_GetFactionAverageReputation, 2);
	rb_define_method(cNWScript, "GetFactionAverageGoodEvilAlignment", NWScript_GetFactionAverageGoodEvilAlignment, 1);
	rb_define_method(cNWScript, "GetFactionAverageLawChaosAlignment", NWScript_GetFactionAverageLawChaosAlignment, 1);
	rb_define_method(cNWScript, "GetFactionAverageLevel", NWScript_GetFactionAverageLevel, 1);
	rb_define_method(cNWScript, "GetFactionAverageXP", NWScript_GetFactionAverageXP, 1);
	rb_define_method(cNWScript, "GetFactionMostFrequentClass", NWScript_GetFactionMostFrequentClass, 1);
	rb_define_method(cNWScript, "GetFactionWorstAC", NWScript_GetFactionWorstAC, -1);
	rb_define_method(cNWScript, "GetFactionBestAC", NWScript_GetFactionBestAC, -1);
	rb_define_method(cNWScript, "ActionSit", NWScript_ActionSit, 1);
	rb_define_method(cNWScript, "GetListenPatternNumber", NWScript_GetListenPatternNumber, 0);
	rb_define_method(cNWScript, "ActionJumpToObject", NWScript_ActionJumpToObject, -1);
	rb_define_method(cNWScript, "GetWaypointByTag", NWScript_GetWaypointByTag, 1);
	rb_define_method(cNWScript, "GetTransitionTarget", NWScript_GetTransitionTarget, 1);
	rb_define_method(cNWScript, "EffectLinkEffects", NWScript_EffectLinkEffects, 2);
	rb_define_method(cNWScript, "GetObjectByTag", NWScript_GetObjectByTag, -1);
	rb_define_method(cNWScript, "AdjustAlignment", NWScript_AdjustAlignment, -1);
	rb_define_method(cNWScript, "ActionWait", NWScript_ActionWait, 1);
	rb_define_method(cNWScript, "SetAreaTransitionBMP", NWScript_SetAreaTransitionBMP, -1);
	rb_define_method(cNWScript, "ActionStartConversation", NWScript_ActionStartConversation, -1);
	rb_define_method(cNWScript, "ActionPauseConversation", NWScript_ActionPauseConversation, 0);
	rb_define_method(cNWScript, "ActionResumeConversation", NWScript_ActionResumeConversation, 0);
	rb_define_method(cNWScript, "EffectBeam", NWScript_EffectBeam, -1);
	rb_define_method(cNWScript, "GetReputation", NWScript_GetReputation, 2);
	rb_define_method(cNWScript, "AdjustReputation", NWScript_AdjustReputation, 3);
	rb_define_method(cNWScript, "GetSittingCreature", NWScript_GetSittingCreature, 1);
	rb_define_method(cNWScript, "GetGoingToBeAttackedBy", NWScript_GetGoingToBeAttackedBy, 1);
	rb_define_method(cNWScript, "EffectSpellResistanceIncrease", NWScript_EffectSpellResistanceIncrease, 1);
	rb_define_method(cNWScript, "GetLocation", NWScript_GetLocation, 1);
	rb_define_method(cNWScript, "ActionJumpToLocation", NWScript_ActionJumpToLocation, 1);
	rb_define_method(cNWScript, "Location", NWScript_Location, 3);
	rb_define_method(cNWScript, "ApplyEffectAtLocation", NWScript_ApplyEffectAtLocation, -1);
	rb_define_method(cNWScript, "GetIsPC", NWScript_GetIsPC, 1);
	rb_define_method(cNWScript, "FeetToMeters", NWScript_FeetToMeters, 1);
	rb_define_method(cNWScript, "YardsToMeters", NWScript_YardsToMeters, 1);
	rb_define_method(cNWScript, "ApplyEffectToObject", NWScript_ApplyEffectToObject, -1);
	rb_define_method(cNWScript, "SpeakString", NWScript_SpeakString, -1);
	rb_define_method(cNWScript, "GetSpellTargetLocation", NWScript_GetSpellTargetLocation, 0);
	rb_define_method(cNWScript, "GetPositionFromLocation", NWScript_GetPositionFromLocation, 1);
	rb_define_method(cNWScript, "GetAreaFromLocation", NWScript_GetAreaFromLocation, 1);
	rb_define_method(cNWScript, "GetFacingFromLocation", NWScript_GetFacingFromLocation, 1);
	rb_define_method(cNWScript, "GetNearestCreatureToLocation", NWScript_GetNearestCreatureToLocation, -1);
	rb_define_method(cNWScript, "GetNearestObject", NWScript_GetNearestObject, -1);
	rb_define_method(cNWScript, "GetNearestObjectToLocation", NWScript_GetNearestObjectToLocation, -1);
	rb_define_method(cNWScript, "GetNearestObjectByTag", NWScript_GetNearestObjectByTag, -1);
	rb_define_method(cNWScript, "IntToFloat", NWScript_IntToFloat, 1);
	rb_define_method(cNWScript, "FloatToInt", NWScript_FloatToInt, 1);
	rb_define_method(cNWScript, "StringToInt", NWScript_StringToInt, 1);
	rb_define_method(cNWScript, "StringToFloat", NWScript_StringToFloat, 1);
	rb_define_method(cNWScript, "ActionCastSpellAtLocation", NWScript_ActionCastSpellAtLocation, -1);
	rb_define_method(cNWScript, "GetIsEnemy", NWScript_GetIsEnemy, -1);
	rb_define_method(cNWScript, "GetIsFriend", NWScript_GetIsFriend, -1);
	rb_define_method(cNWScript, "GetIsNeutral", NWScript_GetIsNeutral, -1);
	rb_define_method(cNWScript, "GetPCSpeaker", NWScript_GetPCSpeaker, 0);
	rb_define_method(cNWScript, "GetStringByStrRef", NWScript_GetStringByStrRef, -1);
	rb_define_method(cNWScript, "ActionSpeakStringByStrRef", NWScript_ActionSpeakStringByStrRef, -1);
	rb_define_method(cNWScript, "DestroyObject", NWScript_DestroyObject, -1);
	rb_define_method(cNWScript, "GetModule", NWScript_GetModule, 0);
	rb_define_method(cNWScript, "CreateObject", NWScript_CreateObject, -1);
	rb_define_method(cNWScript, "EventSpellCastAt", NWScript_EventSpellCastAt, -1);
	rb_define_method(cNWScript, "GetLastSpellCaster", NWScript_GetLastSpellCaster, 0);
	rb_define_method(cNWScript, "GetLastSpell", NWScript_GetLastSpell, 0);
	rb_define_method(cNWScript, "GetUserDefinedEventNumber", NWScript_GetUserDefinedEventNumber, 0);
	rb_define_method(cNWScript, "GetSpellId", NWScript_GetSpellId, 0);
	rb_define_method(cNWScript, "RandomName", NWScript_RandomName, -1);
	rb_define_method(cNWScript, "EffectPoison", NWScript_EffectPoison, 1);
	rb_define_method(cNWScript, "EffectDisease", NWScript_EffectDisease, 1);
	rb_define_method(cNWScript, "EffectSilence", NWScript_EffectSilence, 0);
	rb_define_method(cNWScript, "GetName", NWScript_GetName, -1);
	rb_define_method(cNWScript, "GetLastSpeaker", NWScript_GetLastSpeaker, 0);
	rb_define_method(cNWScript, "BeginConversation", NWScript_BeginConversation, -1);
	rb_define_method(cNWScript, "GetLastPerceived", NWScript_GetLastPerceived, 0);
	rb_define_method(cNWScript, "GetLastPerceptionHeard", NWScript_GetLastPerceptionHeard, 0);
	rb_define_method(cNWScript, "GetLastPerceptionInaudible", NWScript_GetLastPerceptionInaudible, 0);
	rb_define_method(cNWScript, "GetLastPerceptionSeen", NWScript_GetLastPerceptionSeen, 0);
	rb_define_method(cNWScript, "GetLastClosedBy", NWScript_GetLastClosedBy, 0);
	rb_define_method(cNWScript, "GetLastPerceptionVanished", NWScript_GetLastPerceptionVanished, 0);
	rb_define_method(cNWScript, "GetFirstInPersistentObject", NWScript_GetFirstInPersistentObject, -1);
	rb_define_method(cNWScript, "GetNextInPersistentObject", NWScript_GetNextInPersistentObject, -1);
	rb_define_method(cNWScript, "GetAreaOfEffectCreator", NWScript_GetAreaOfEffectCreator, -1);
	rb_define_method(cNWScript, "DeleteLocalInt", NWScript_DeleteLocalInt, 2);
	rb_define_method(cNWScript, "DeleteLocalFloat", NWScript_DeleteLocalFloat, 2);
	rb_define_method(cNWScript, "DeleteLocalString", NWScript_DeleteLocalString, 2);
	rb_define_method(cNWScript, "DeleteLocalObject", NWScript_DeleteLocalObject, 2);
	rb_define_method(cNWScript, "DeleteLocalLocation", NWScript_DeleteLocalLocation, 2);
	rb_define_method(cNWScript, "EffectHaste", NWScript_EffectHaste, 0);
	rb_define_method(cNWScript, "EffectSlow", NWScript_EffectSlow, 0);
	rb_define_method(cNWScript, "ObjectToString", NWScript_ObjectToString, 1);
	rb_define_method(cNWScript, "EffectImmunity", NWScript_EffectImmunity, 1);
	rb_define_method(cNWScript, "GetIsImmune", NWScript_GetIsImmune, -1);
	rb_define_method(cNWScript, "EffectDamageImmunityIncrease", NWScript_EffectDamageImmunityIncrease, 2);
	rb_define_method(cNWScript, "GetEncounterActive", NWScript_GetEncounterActive, -1);
	rb_define_method(cNWScript, "SetEncounterActive", NWScript_SetEncounterActive, -1);
	rb_define_method(cNWScript, "GetEncounterSpawnsMax", NWScript_GetEncounterSpawnsMax, -1);
	rb_define_method(cNWScript, "SetEncounterSpawnsMax", NWScript_SetEncounterSpawnsMax, -1);
	rb_define_method(cNWScript, "GetEncounterSpawnsCurrent", NWScript_GetEncounterSpawnsCurrent, -1);
	rb_define_method(cNWScript, "SetEncounterSpawnsCurrent", NWScript_SetEncounterSpawnsCurrent, -1);
	rb_define_method(cNWScript, "GetModuleItemAcquired", NWScript_GetModuleItemAcquired, 0);
	rb_define_method(cNWScript, "GetModuleItemAcquiredFrom", NWScript_GetModuleItemAcquiredFrom, 0);
	rb_define_method(cNWScript, "SetCustomToken", NWScript_SetCustomToken, 2);
	rb_define_method(cNWScript, "GetHasFeat", NWScript_GetHasFeat, -1);
	rb_define_method(cNWScript, "GetHasSkill", NWScript_GetHasSkill, -1);
	rb_define_method(cNWScript, "ActionUseFeat", NWScript_ActionUseFeat, 2);
	rb_define_method(cNWScript, "ActionUseSkill", NWScript_ActionUseSkill, -1);
	rb_define_method(cNWScript, "GetObjectSeen", NWScript_GetObjectSeen, -1);
	rb_define_method(cNWScript, "GetObjectHeard", NWScript_GetObjectHeard, -1);
	rb_define_method(cNWScript, "GetLastPlayerDied", NWScript_GetLastPlayerDied, 0);
	rb_define_method(cNWScript, "GetModuleItemLost", NWScript_GetModuleItemLost, 0);
	rb_define_method(cNWScript, "GetModuleItemLostBy", NWScript_GetModuleItemLostBy, 0);
	rb_define_method(cNWScript, "ActionDoCommand", NWScript_ActionDoCommand, 1);
	rb_define_method(cNWScript, "EventConversation", NWScript_EventConversation, 0);
	rb_define_method(cNWScript, "SetEncounterDifficulty", NWScript_SetEncounterDifficulty, -1);
	rb_define_method(cNWScript, "GetEncounterDifficulty", NWScript_GetEncounterDifficulty, -1);
	rb_define_method(cNWScript, "GetDistanceBetweenLocations", NWScript_GetDistanceBetweenLocations, 2);
	rb_define_method(cNWScript, "GetReflexAdjustedDamage", NWScript_GetReflexAdjustedDamage, -1);
	rb_define_method(cNWScript, "PlayAnimation", NWScript_PlayAnimation, -1);
	rb_define_method(cNWScript, "TalentSpell", NWScript_TalentSpell, 1);
	rb_define_method(cNWScript, "TalentFeat", NWScript_TalentFeat, 1);
	rb_define_method(cNWScript, "TalentSkill", NWScript_TalentSkill, 1);
	rb_define_method(cNWScript, "GetHasSpellEffect", NWScript_GetHasSpellEffect, -1);
	rb_define_method(cNWScript, "GetEffectSpellId", NWScript_GetEffectSpellId, 1);
	rb_define_method(cNWScript, "GetCreatureHasTalent", NWScript_GetCreatureHasTalent, -1);
	rb_define_method(cNWScript, "GetCreatureTalentRandom", NWScript_GetCreatureTalentRandom, -1);
	rb_define_method(cNWScript, "GetCreatureTalentBest", NWScript_GetCreatureTalentBest, -1);
	rb_define_method(cNWScript, "ActionUseTalentOnObject", NWScript_ActionUseTalentOnObject, 2);
	rb_define_method(cNWScript, "ActionUseTalentAtLocation", NWScript_ActionUseTalentAtLocation, 2);
	rb_define_method(cNWScript, "GetGoldPieceValue", NWScript_GetGoldPieceValue, 1);
	rb_define_method(cNWScript, "GetIsPlayableRacialType", NWScript_GetIsPlayableRacialType, 1);
	rb_define_method(cNWScript, "JumpToLocation", NWScript_JumpToLocation, 1);
	rb_define_method(cNWScript, "EffectTemporaryHitpoints", NWScript_EffectTemporaryHitpoints, 1);
	rb_define_method(cNWScript, "GetSkillRank", NWScript_GetSkillRank, -1);
	rb_define_method(cNWScript, "GetAttackTarget", NWScript_GetAttackTarget, -1);
	rb_define_method(cNWScript, "GetLastAttackType", NWScript_GetLastAttackType, -1);
	rb_define_method(cNWScript, "GetLastAttackMode", NWScript_GetLastAttackMode, -1);
	rb_define_method(cNWScript, "GetMaster", NWScript_GetMaster, -1);
	rb_define_method(cNWScript, "GetIsInCombat", NWScript_GetIsInCombat, -1);
	rb_define_method(cNWScript, "GetLastAssociateCommand", NWScript_GetLastAssociateCommand, -1);
	rb_define_method(cNWScript, "GiveGoldToCreature", NWScript_GiveGoldToCreature, 2);
	rb_define_method(cNWScript, "SetIsDestroyable", NWScript_SetIsDestroyable, -1);
	rb_define_method(cNWScript, "SetLocked", NWScript_SetLocked, 2);
	rb_define_method(cNWScript, "GetLocked", NWScript_GetLocked, 1);
	rb_define_method(cNWScript, "GetClickingObject", NWScript_GetClickingObject, 0);
	rb_define_method(cNWScript, "SetAssociateListenPatterns", NWScript_SetAssociateListenPatterns, -1);
	rb_define_method(cNWScript, "GetLastWeaponUsed", NWScript_GetLastWeaponUsed, 1);
	rb_define_method(cNWScript, "ActionInteractObject", NWScript_ActionInteractObject, 1);
	rb_define_method(cNWScript, "GetLastUsedBy", NWScript_GetLastUsedBy, 0);
	rb_define_method(cNWScript, "GetAbilityModifier", NWScript_GetAbilityModifier, -1);
	rb_define_method(cNWScript, "GetIdentified", NWScript_GetIdentified, 1);
	rb_define_method(cNWScript, "SetIdentified", NWScript_SetIdentified, 2);
	rb_define_method(cNWScript, "SummonAnimalCompanion", NWScript_SummonAnimalCompanion, -1);
	rb_define_method(cNWScript, "SummonFamiliar", NWScript_SummonFamiliar, -1);
	rb_define_method(cNWScript, "GetBlockingDoor", NWScript_GetBlockingDoor, 0);
	rb_define_method(cNWScript, "GetIsDoorActionPossible", NWScript_GetIsDoorActionPossible, 2);
	rb_define_method(cNWScript, "DoDoorAction", NWScript_DoDoorAction, 2);
	rb_define_method(cNWScript, "GetFirstItemInInventory", NWScript_GetFirstItemInInventory, -1);
	rb_define_method(cNWScript, "GetNextItemInInventory", NWScript_GetNextItemInInventory, -1);
	rb_define_method(cNWScript, "GetClassByPosition", NWScript_GetClassByPosition, -1);
	rb_define_method(cNWScript, "GetLevelByPosition", NWScript_GetLevelByPosition, -1);
	rb_define_method(cNWScript, "GetLevelByClass", NWScript_GetLevelByClass, -1);
	rb_define_method(cNWScript, "GetDamageDealtByType", NWScript_GetDamageDealtByType, 1);
	rb_define_method(cNWScript, "GetTotalDamageDealt", NWScript_GetTotalDamageDealt, 0);
	rb_define_method(cNWScript, "GetLastDamager", NWScript_GetLastDamager, -1);
	rb_define_method(cNWScript, "GetLastDisarmed", NWScript_GetLastDisarmed, 0);
	rb_define_method(cNWScript, "GetLastDisturbed", NWScript_GetLastDisturbed, 0);
	rb_define_method(cNWScript, "GetLastLocked", NWScript_GetLastLocked, 0);
	rb_define_method(cNWScript, "GetLastUnlocked", NWScript_GetLastUnlocked, 0);
	rb_define_method(cNWScript, "EffectSkillIncrease", NWScript_EffectSkillIncrease, 2);
	rb_define_method(cNWScript, "GetInventoryDisturbType", NWScript_GetInventoryDisturbType, 0);
	rb_define_method(cNWScript, "GetInventoryDisturbItem", NWScript_GetInventoryDisturbItem, 0);
	rb_define_method(cNWScript, "GetHenchman", NWScript_GetHenchman, -1);
	rb_define_method(cNWScript, "VersusAlignmentEffect", NWScript_VersusAlignmentEffect, -1);
	rb_define_method(cNWScript, "VersusRacialTypeEffect", NWScript_VersusRacialTypeEffect, 2);
	rb_define_method(cNWScript, "VersusTrapEffect", NWScript_VersusTrapEffect, 1);
	rb_define_method(cNWScript, "GetGender", NWScript_GetGender, 1);
	rb_define_method(cNWScript, "GetIsTalentValid", NWScript_GetIsTalentValid, 1);
	rb_define_method(cNWScript, "ActionMoveAwayFromLocation", NWScript_ActionMoveAwayFromLocation, -1);
	rb_define_method(cNWScript, "GetAttemptedAttackTarget", NWScript_GetAttemptedAttackTarget, 0);
	rb_define_method(cNWScript, "GetTypeFromTalent", NWScript_GetTypeFromTalent, 1);
	rb_define_method(cNWScript, "GetIdFromTalent", NWScript_GetIdFromTalent, 1);
	rb_define_method(cNWScript, "GetAssociate", NWScript_GetAssociate, -1);
	rb_define_method(cNWScript, "AddHenchman", NWScript_AddHenchman, -1);
	rb_define_method(cNWScript, "RemoveHenchman", NWScript_RemoveHenchman, -1);
	rb_define_method(cNWScript, "AddJournalQuestEntry", NWScript_AddJournalQuestEntry, -1);
	rb_define_method(cNWScript, "RemoveJournalQuestEntry", NWScript_RemoveJournalQuestEntry, -1);
	rb_define_method(cNWScript, "GetPCPublicCDKey", NWScript_GetPCPublicCDKey, -1);
	rb_define_method(cNWScript, "GetPCIPAddress", NWScript_GetPCIPAddress, 1);
	rb_define_method(cNWScript, "GetPCPlayerName", NWScript_GetPCPlayerName, 1);
	rb_define_method(cNWScript, "SetPCLike", NWScript_SetPCLike, 2);
	rb_define_method(cNWScript, "SetPCDislike", NWScript_SetPCDislike, 2);
	rb_define_method(cNWScript, "SendMessageToPC", NWScript_SendMessageToPC, 2);
	rb_define_method(cNWScript, "GetAttemptedSpellTarget", NWScript_GetAttemptedSpellTarget, 0);
	rb_define_method(cNWScript, "GetLastOpenedBy", NWScript_GetLastOpenedBy, 0);
	rb_define_method(cNWScript, "GetHasSpell", NWScript_GetHasSpell, -1);
	rb_define_method(cNWScript, "OpenStore", NWScript_OpenStore, -1);
	rb_define_method(cNWScript, "EffectTurned", NWScript_EffectTurned, 0);
	rb_define_method(cNWScript, "GetFirstFactionMember", NWScript_GetFirstFactionMember, -1);
	rb_define_method(cNWScript, "GetNextFactionMember", NWScript_GetNextFactionMember, -1);
	rb_define_method(cNWScript, "ActionForceMoveToLocation", NWScript_ActionForceMoveToLocation, -1);
	rb_define_method(cNWScript, "ActionForceMoveToObject", NWScript_ActionForceMoveToObject, -1);
	rb_define_method(cNWScript, "GetJournalQuestExperience", NWScript_GetJournalQuestExperience, 1);
	rb_define_method(cNWScript, "JumpToObject", NWScript_JumpToObject, -1);
	rb_define_method(cNWScript, "SetMapPinEnabled", NWScript_SetMapPinEnabled, 2);
	rb_define_method(cNWScript, "EffectHitPointChangeWhenDying", NWScript_EffectHitPointChangeWhenDying, 1);
	rb_define_method(cNWScript, "PopUpGUIPanel", NWScript_PopUpGUIPanel, 2);
	rb_define_method(cNWScript, "ClearPersonalReputation", NWScript_ClearPersonalReputation, -1);
	rb_define_method(cNWScript, "SetIsTemporaryFriend", NWScript_SetIsTemporaryFriend, -1);
	rb_define_method(cNWScript, "SetIsTemporaryEnemy", NWScript_SetIsTemporaryEnemy, -1);
	rb_define_method(cNWScript, "SetIsTemporaryNeutral", NWScript_SetIsTemporaryNeutral, -1);
	rb_define_method(cNWScript, "GiveXPToCreature", NWScript_GiveXPToCreature, 2);
	rb_define_method(cNWScript, "SetXP", NWScript_SetXP, 2);
	rb_define_method(cNWScript, "GetXP", NWScript_GetXP, 1);
	rb_define_method(cNWScript, "IntToHexString", NWScript_IntToHexString, 1);
	rb_define_method(cNWScript, "GetBaseItemType", NWScript_GetBaseItemType, 1);
	rb_define_method(cNWScript, "GetItemHasItemProperty", NWScript_GetItemHasItemProperty, 2);
	rb_define_method(cNWScript, "ActionEquipMostDamagingMelee", NWScript_ActionEquipMostDamagingMelee, -1);
	rb_define_method(cNWScript, "ActionEquipMostDamagingRanged", NWScript_ActionEquipMostDamagingRanged, -1);
	rb_define_method(cNWScript, "GetItemACValue", NWScript_GetItemACValue, 1);
	rb_define_method(cNWScript, "ActionRest", NWScript_ActionRest, -1);
	rb_define_method(cNWScript, "ExploreAreaForPlayer", NWScript_ExploreAreaForPlayer, -1);
	rb_define_method(cNWScript, "ActionEquipMostEffectiveArmor", NWScript_ActionEquipMostEffectiveArmor, 0);
	rb_define_method(cNWScript, "GetIsDay", NWScript_GetIsDay, 0);
	rb_define_method(cNWScript, "GetIsNight", NWScript_GetIsNight, 0);
	rb_define_method(cNWScript, "GetIsDawn", NWScript_GetIsDawn, 0);
	rb_define_method(cNWScript, "GetIsDusk", NWScript_GetIsDusk, 0);
	rb_define_method(cNWScript, "GetIsEncounterCreature", NWScript_GetIsEncounterCreature, -1);
	rb_define_method(cNWScript, "GetLastPlayerDying", NWScript_GetLastPlayerDying, 0);
	rb_define_method(cNWScript, "GetStartingLocation", NWScript_GetStartingLocation, 0);
	rb_define_method(cNWScript, "ChangeToStandardFaction", NWScript_ChangeToStandardFaction, 2);
	rb_define_method(cNWScript, "SoundObjectPlay", NWScript_SoundObjectPlay, 1);
	rb_define_method(cNWScript, "SoundObjectStop", NWScript_SoundObjectStop, 1);
	rb_define_method(cNWScript, "SoundObjectSetVolume", NWScript_SoundObjectSetVolume, 2);
	rb_define_method(cNWScript, "SoundObjectSetPosition", NWScript_SoundObjectSetPosition, 2);
	rb_define_method(cNWScript, "SpeakOneLinerConversation", NWScript_SpeakOneLinerConversation, -1);
	rb_define_method(cNWScript, "GetGold", NWScript_GetGold, -1);
	rb_define_method(cNWScript, "GetLastRespawnButtonPresser", NWScript_GetLastRespawnButtonPresser, 0);
	rb_define_method(cNWScript, "GetIsDM", NWScript_GetIsDM, 1);
	rb_define_method(cNWScript, "PlayVoiceChat", NWScript_PlayVoiceChat, -1);
	rb_define_method(cNWScript, "GetIsWeaponEffective", NWScript_GetIsWeaponEffective, -1);
	rb_define_method(cNWScript, "GetLastSpellHarmful", NWScript_GetLastSpellHarmful, 0);
	rb_define_method(cNWScript, "EventActivateItem", NWScript_EventActivateItem, -1);
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
	rb_define_method(cNWScript, "TakeGoldFromCreature", NWScript_TakeGoldFromCreature, -1);
	rb_define_method(cNWScript, "IsInConversation", NWScript_IsInConversation, 1);
	rb_define_method(cNWScript, "EffectAbilityDecrease", NWScript_EffectAbilityDecrease, 2);
	rb_define_method(cNWScript, "EffectAttackDecrease", NWScript_EffectAttackDecrease, -1);
	rb_define_method(cNWScript, "EffectDamageDecrease", NWScript_EffectDamageDecrease, -1);
	rb_define_method(cNWScript, "EffectDamageImmunityDecrease", NWScript_EffectDamageImmunityDecrease, 2);
	rb_define_method(cNWScript, "EffectACDecrease", NWScript_EffectACDecrease, -1);
	rb_define_method(cNWScript, "EffectMovementSpeedDecrease", NWScript_EffectMovementSpeedDecrease, 1);
	rb_define_method(cNWScript, "EffectSavingThrowDecrease", NWScript_EffectSavingThrowDecrease, -1);
	rb_define_method(cNWScript, "EffectSkillDecrease", NWScript_EffectSkillDecrease, 2);
	rb_define_method(cNWScript, "EffectSpellResistanceDecrease", NWScript_EffectSpellResistanceDecrease, 1);
	rb_define_method(cNWScript, "GetPlotFlag", NWScript_GetPlotFlag, -1);
	rb_define_method(cNWScript, "SetPlotFlag", NWScript_SetPlotFlag, 2);
	rb_define_method(cNWScript, "EffectInvisibility", NWScript_EffectInvisibility, 1);
	rb_define_method(cNWScript, "EffectConcealment", NWScript_EffectConcealment, -1);
	rb_define_method(cNWScript, "EffectDarkness", NWScript_EffectDarkness, 0);
	rb_define_method(cNWScript, "EffectDispelMagicAll", NWScript_EffectDispelMagicAll, -1);
	rb_define_method(cNWScript, "EffectUltravision", NWScript_EffectUltravision, 0);
	rb_define_method(cNWScript, "EffectNegativeLevel", NWScript_EffectNegativeLevel, -1);
	rb_define_method(cNWScript, "EffectPolymorph", NWScript_EffectPolymorph, -1);
	rb_define_method(cNWScript, "EffectSanctuary", NWScript_EffectSanctuary, 1);
	rb_define_method(cNWScript, "EffectTrueSeeing", NWScript_EffectTrueSeeing, 0);
	rb_define_method(cNWScript, "EffectSeeInvisible", NWScript_EffectSeeInvisible, 0);
	rb_define_method(cNWScript, "EffectTimeStop", NWScript_EffectTimeStop, 0);
	rb_define_method(cNWScript, "EffectBlindness", NWScript_EffectBlindness, 0);
	rb_define_method(cNWScript, "GetIsReactionTypeFriendly", NWScript_GetIsReactionTypeFriendly, -1);
	rb_define_method(cNWScript, "GetIsReactionTypeNeutral", NWScript_GetIsReactionTypeNeutral, -1);
	rb_define_method(cNWScript, "GetIsReactionTypeHostile", NWScript_GetIsReactionTypeHostile, -1);
	rb_define_method(cNWScript, "EffectSpellLevelAbsorption", NWScript_EffectSpellLevelAbsorption, -1);
	rb_define_method(cNWScript, "EffectDispelMagicBest", NWScript_EffectDispelMagicBest, -1);
	rb_define_method(cNWScript, "ActivatePortal", NWScript_ActivatePortal, -1);
	rb_define_method(cNWScript, "GetNumStackedItems", NWScript_GetNumStackedItems, 1);
	rb_define_method(cNWScript, "SurrenderToEnemies", NWScript_SurrenderToEnemies, 0);
	rb_define_method(cNWScript, "EffectMissChance", NWScript_EffectMissChance, -1);
	rb_define_method(cNWScript, "GetTurnResistanceHD", NWScript_GetTurnResistanceHD, -1);
	rb_define_method(cNWScript, "GetCreatureSize", NWScript_GetCreatureSize, 1);
	rb_define_method(cNWScript, "EffectDisappearAppear", NWScript_EffectDisappearAppear, -1);
	rb_define_method(cNWScript, "EffectDisappear", NWScript_EffectDisappear, -1);
	rb_define_method(cNWScript, "EffectAppear", NWScript_EffectAppear, -1);
	rb_define_method(cNWScript, "ActionUnlockObject", NWScript_ActionUnlockObject, 1);
	rb_define_method(cNWScript, "ActionLockObject", NWScript_ActionLockObject, 1);
	rb_define_method(cNWScript, "EffectModifyAttacks", NWScript_EffectModifyAttacks, 1);
	rb_define_method(cNWScript, "GetLastTrapDetected", NWScript_GetLastTrapDetected, -1);
	rb_define_method(cNWScript, "EffectDamageShield", NWScript_EffectDamageShield, 3);
	rb_define_method(cNWScript, "GetNearestTrapToObject", NWScript_GetNearestTrapToObject, -1);
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
	rb_define_method(cNWScript, "ActionCastFakeSpellAtObject", NWScript_ActionCastFakeSpellAtObject, -1);
	rb_define_method(cNWScript, "ActionCastFakeSpellAtLocation", NWScript_ActionCastFakeSpellAtLocation, -1);
	rb_define_method(cNWScript, "RemoveSummonedAssociate", NWScript_RemoveSummonedAssociate, -1);
	rb_define_method(cNWScript, "SetCameraMode", NWScript_SetCameraMode, 2);
	rb_define_method(cNWScript, "GetIsResting", NWScript_GetIsResting, -1);
	rb_define_method(cNWScript, "GetLastPCRested", NWScript_GetLastPCRested, 0);
	rb_define_method(cNWScript, "SetWeather", NWScript_SetWeather, 2);
	rb_define_method(cNWScript, "GetLastRestEventType", NWScript_GetLastRestEventType, 0);
	rb_define_method(cNWScript, "StartNewModule", NWScript_StartNewModule, 1);
	rb_define_method(cNWScript, "EffectSwarm", NWScript_EffectSwarm, -1);
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
	rb_define_method(cNWScript, "GetCurrentAction", NWScript_GetCurrentAction, -1);
	rb_define_method(cNWScript, "SetStandardFactionReputation", NWScript_SetStandardFactionReputation, -1);
	rb_define_method(cNWScript, "GetStandardFactionReputation", NWScript_GetStandardFactionReputation, -1);
	rb_define_method(cNWScript, "FloatingTextStrRefOnCreature", NWScript_FloatingTextStrRefOnCreature, -1);
	rb_define_method(cNWScript, "FloatingTextStringOnCreature", NWScript_FloatingTextStringOnCreature, -1);
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
	rb_define_method(cNWScript, "GetHasFeatEffect", NWScript_GetHasFeatEffect, -1);
	rb_define_method(cNWScript, "SetPlaceableIllumination", NWScript_SetPlaceableIllumination, -1);
	rb_define_method(cNWScript, "GetPlaceableIllumination", NWScript_GetPlaceableIllumination, -1);
	rb_define_method(cNWScript, "GetIsPlaceableObjectActionPossible", NWScript_GetIsPlaceableObjectActionPossible, 2);
	rb_define_method(cNWScript, "DoPlaceableObjectAction", NWScript_DoPlaceableObjectAction, 2);
	rb_define_method(cNWScript, "GetFirstPC", NWScript_GetFirstPC, 0);
	rb_define_method(cNWScript, "GetNextPC", NWScript_GetNextPC, 0);
	rb_define_method(cNWScript, "SetTrapDetectedBy", NWScript_SetTrapDetectedBy, -1);
	rb_define_method(cNWScript, "GetIsTrapped", NWScript_GetIsTrapped, 1);
	rb_define_method(cNWScript, "EffectTurnResistanceDecrease", NWScript_EffectTurnResistanceDecrease, 1);
	rb_define_method(cNWScript, "EffectTurnResistanceIncrease", NWScript_EffectTurnResistanceIncrease, 1);
	rb_define_method(cNWScript, "PopUpDeathGUIPanel", NWScript_PopUpDeathGUIPanel, -1);
	rb_define_method(cNWScript, "SetTrapDisabled", NWScript_SetTrapDisabled, 1);
	rb_define_method(cNWScript, "GetLastHostileActor", NWScript_GetLastHostileActor, -1);
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
	rb_define_method(cNWScript, "CopyItem", NWScript_CopyItem, -1);
	rb_define_method(cNWScript, "EffectCutsceneParalyze", NWScript_EffectCutsceneParalyze, 0);
	rb_define_method(cNWScript, "GetDroppableFlag", NWScript_GetDroppableFlag, 1);
	rb_define_method(cNWScript, "GetUseableFlag", NWScript_GetUseableFlag, -1);
	rb_define_method(cNWScript, "GetStolenFlag", NWScript_GetStolenFlag, 1);
	rb_define_method(cNWScript, "SetCampaignFloat", NWScript_SetCampaignFloat, -1);
	rb_define_method(cNWScript, "SetCampaignInt", NWScript_SetCampaignInt, -1);
	rb_define_method(cNWScript, "SetCampaignVector", NWScript_SetCampaignVector, -1);
	rb_define_method(cNWScript, "SetCampaignLocation", NWScript_SetCampaignLocation, -1);
	rb_define_method(cNWScript, "SetCampaignString", NWScript_SetCampaignString, -1);
	rb_define_method(cNWScript, "DestroyCampaignDatabase", NWScript_DestroyCampaignDatabase, 1);
	rb_define_method(cNWScript, "GetCampaignFloat", NWScript_GetCampaignFloat, -1);
	rb_define_method(cNWScript, "GetCampaignInt", NWScript_GetCampaignInt, -1);
	rb_define_method(cNWScript, "GetCampaignVector", NWScript_GetCampaignVector, -1);
	rb_define_method(cNWScript, "GetCampaignLocation", NWScript_GetCampaignLocation, -1);
	rb_define_method(cNWScript, "GetCampaignString", NWScript_GetCampaignString, -1);
	rb_define_method(cNWScript, "CopyObject", NWScript_CopyObject, -1);
	rb_define_method(cNWScript, "DeleteCampaignVariable", NWScript_DeleteCampaignVariable, -1);
	rb_define_method(cNWScript, "StoreCampaignObject", NWScript_StoreCampaignObject, -1);
	rb_define_method(cNWScript, "RetrieveCampaignObject", NWScript_RetrieveCampaignObject, -1);
	rb_define_method(cNWScript, "EffectCutsceneDominated", NWScript_EffectCutsceneDominated, 0);
	rb_define_method(cNWScript, "GetItemStackSize", NWScript_GetItemStackSize, 1);
	rb_define_method(cNWScript, "SetItemStackSize", NWScript_SetItemStackSize, 2);
	rb_define_method(cNWScript, "GetItemCharges", NWScript_GetItemCharges, 1);
	rb_define_method(cNWScript, "SetItemCharges", NWScript_SetItemCharges, 2);
	rb_define_method(cNWScript, "AddItemProperty", NWScript_AddItemProperty, -1);
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
	rb_define_method(cNWScript, "ItemPropertyOnHitProps", NWScript_ItemPropertyOnHitProps, -1);
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
	rb_define_method(cNWScript, "ItemPropertyUnlimitedAmmo", NWScript_ItemPropertyUnlimitedAmmo, -1);
	rb_define_method(cNWScript, "ItemPropertyLimitUseByAlign", NWScript_ItemPropertyLimitUseByAlign, 1);
	rb_define_method(cNWScript, "ItemPropertyLimitUseByClass", NWScript_ItemPropertyLimitUseByClass, 1);
	rb_define_method(cNWScript, "ItemPropertyLimitUseByRace", NWScript_ItemPropertyLimitUseByRace, 1);
	rb_define_method(cNWScript, "ItemPropertyLimitUseBySAlign", NWScript_ItemPropertyLimitUseBySAlign, 1);
	rb_define_method(cNWScript, "BadBadReplaceMeThisDoesNothing", NWScript_BadBadReplaceMeThisDoesNothing, 0);
	rb_define_method(cNWScript, "ItemPropertyVampiricRegeneration", NWScript_ItemPropertyVampiricRegeneration, 1);
	rb_define_method(cNWScript, "ItemPropertyTrap", NWScript_ItemPropertyTrap, 2);
	rb_define_method(cNWScript, "ItemPropertyTrueSeeing", NWScript_ItemPropertyTrueSeeing, 0);
	rb_define_method(cNWScript, "ItemPropertyOnMonsterHitProperties", NWScript_ItemPropertyOnMonsterHitProperties, -1);
	rb_define_method(cNWScript, "ItemPropertyTurnResistance", NWScript_ItemPropertyTurnResistance, 1);
	rb_define_method(cNWScript, "ItemPropertyMassiveCritical", NWScript_ItemPropertyMassiveCritical, 1);
	rb_define_method(cNWScript, "ItemPropertyFreeAction", NWScript_ItemPropertyFreeAction, 0);
	rb_define_method(cNWScript, "ItemPropertyMonsterDamage", NWScript_ItemPropertyMonsterDamage, 1);
	rb_define_method(cNWScript, "ItemPropertyImmunityToSpellLevel", NWScript_ItemPropertyImmunityToSpellLevel, 1);
	rb_define_method(cNWScript, "ItemPropertySpecialWalk", NWScript_ItemPropertySpecialWalk, -1);
	rb_define_method(cNWScript, "ItemPropertyHealersKit", NWScript_ItemPropertyHealersKit, 1);
	rb_define_method(cNWScript, "ItemPropertyWeightIncrease", NWScript_ItemPropertyWeightIncrease, 1);
	rb_define_method(cNWScript, "GetIsSkillSuccessful", NWScript_GetIsSkillSuccessful, 3);
	rb_define_method(cNWScript, "EffectSpellFailure", NWScript_EffectSpellFailure, -1);
	rb_define_method(cNWScript, "SpeakStringByStrRef", NWScript_SpeakStringByStrRef, -1);
	rb_define_method(cNWScript, "SetCutsceneMode", NWScript_SetCutsceneMode, -1);
	rb_define_method(cNWScript, "GetLastPCToCancelCutscene", NWScript_GetLastPCToCancelCutscene, 0);
	rb_define_method(cNWScript, "GetDialogSoundLength", NWScript_GetDialogSoundLength, 1);
	rb_define_method(cNWScript, "FadeFromBlack", NWScript_FadeFromBlack, -1);
	rb_define_method(cNWScript, "FadeToBlack", NWScript_FadeToBlack, -1);
	rb_define_method(cNWScript, "StopFade", NWScript_StopFade, 1);
	rb_define_method(cNWScript, "BlackScreen", NWScript_BlackScreen, 1);
	rb_define_method(cNWScript, "GetBaseAttackBonus", NWScript_GetBaseAttackBonus, 1);
	rb_define_method(cNWScript, "SetImmortal", NWScript_SetImmortal, 2);
	rb_define_method(cNWScript, "OpenInventory", NWScript_OpenInventory, 2);
	rb_define_method(cNWScript, "StoreCameraFacing", NWScript_StoreCameraFacing, 0);
	rb_define_method(cNWScript, "RestoreCameraFacing", NWScript_RestoreCameraFacing, 0);
	rb_define_method(cNWScript, "LevelUpHenchman", NWScript_LevelUpHenchman, -1);
	rb_define_method(cNWScript, "SetDroppableFlag", NWScript_SetDroppableFlag, 2);
	rb_define_method(cNWScript, "GetWeight", NWScript_GetWeight, -1);
	rb_define_method(cNWScript, "GetModuleItemAcquiredBy", NWScript_GetModuleItemAcquiredBy, 0);
	rb_define_method(cNWScript, "GetImmortal", NWScript_GetImmortal, -1);
	rb_define_method(cNWScript, "DoWhirlwindAttack", NWScript_DoWhirlwindAttack, -1);
	rb_define_method(cNWScript, "Get2DAString", NWScript_Get2DAString, 3);
	rb_define_method(cNWScript, "EffectEthereal", NWScript_EffectEthereal, 0);
	rb_define_method(cNWScript, "GetAILevel", NWScript_GetAILevel, -1);
	rb_define_method(cNWScript, "SetAILevel", NWScript_SetAILevel, 2);
	rb_define_method(cNWScript, "GetIsPossessedFamiliar", NWScript_GetIsPossessedFamiliar, 1);
	rb_define_method(cNWScript, "UnpossessFamiliar", NWScript_UnpossessFamiliar, 1);
	rb_define_method(cNWScript, "GetIsAreaInterior", NWScript_GetIsAreaInterior, -1);
	rb_define_method(cNWScript, "SendMessageToPCByStrRef", NWScript_SendMessageToPCByStrRef, 2);
	rb_define_method(cNWScript, "IncrementRemainingFeatUses", NWScript_IncrementRemainingFeatUses, 2);
	rb_define_method(cNWScript, "ExportSingleCharacter", NWScript_ExportSingleCharacter, 1);
	rb_define_method(cNWScript, "PlaySoundByStrRef", NWScript_PlaySoundByStrRef, -1);
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
	rb_define_method(cNWScript, "CopyItemAndModify", NWScript_CopyItemAndModify, -1);
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
	rb_define_method(cNWScript, "DayToNight", NWScript_DayToNight, -1);
	rb_define_method(cNWScript, "NightToDay", NWScript_NightToDay, -1);
	rb_define_method(cNWScript, "LineOfSightObject", NWScript_LineOfSightObject, 2);
	rb_define_method(cNWScript, "LineOfSightVector", NWScript_LineOfSightVector, 2);
	rb_define_method(cNWScript, "GetLastSpellCastClass", NWScript_GetLastSpellCastClass, 0);
	rb_define_method(cNWScript, "SetBaseAttackBonus", NWScript_SetBaseAttackBonus, -1);
	rb_define_method(cNWScript, "RestoreBaseAttackBonus", NWScript_RestoreBaseAttackBonus, -1);
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
	rb_define_method(cNWScript, "GetIsInSubArea", NWScript_GetIsInSubArea, -1);
	rb_define_method(cNWScript, "GetItemPropertyCostTable", NWScript_GetItemPropertyCostTable, 1);
	rb_define_method(cNWScript, "GetItemPropertyCostTableValue", NWScript_GetItemPropertyCostTableValue, 1);
	rb_define_method(cNWScript, "GetItemPropertyParam1", NWScript_GetItemPropertyParam1, 1);
	rb_define_method(cNWScript, "GetItemPropertyParam1Value", NWScript_GetItemPropertyParam1Value, 1);
	rb_define_method(cNWScript, "GetIsCreatureDisarmable", NWScript_GetIsCreatureDisarmable, 1);
	rb_define_method(cNWScript, "SetStolenFlag", NWScript_SetStolenFlag, 2);
	rb_define_method(cNWScript, "ForceRest", NWScript_ForceRest, 1);
	rb_define_method(cNWScript, "SetCameraHeight", NWScript_SetCameraHeight, -1);
	rb_define_method(cNWScript, "SetSkyBox", NWScript_SetSkyBox, -1);
	rb_define_method(cNWScript, "GetPhenoType", NWScript_GetPhenoType, 1);
	rb_define_method(cNWScript, "SetPhenoType", NWScript_SetPhenoType, -1);
	rb_define_method(cNWScript, "SetFogColor", NWScript_SetFogColor, -1);
	rb_define_method(cNWScript, "GetCutsceneMode", NWScript_GetCutsceneMode, -1);
	rb_define_method(cNWScript, "GetSkyBox", NWScript_GetSkyBox, -1);
	rb_define_method(cNWScript, "GetFogColor", NWScript_GetFogColor, -1);
	rb_define_method(cNWScript, "SetFogAmount", NWScript_SetFogAmount, -1);
	rb_define_method(cNWScript, "GetFogAmount", NWScript_GetFogAmount, -1);
	rb_define_method(cNWScript, "GetPickpocketableFlag", NWScript_GetPickpocketableFlag, 1);
	rb_define_method(cNWScript, "SetPickpocketableFlag", NWScript_SetPickpocketableFlag, 2);
	rb_define_method(cNWScript, "GetFootstepType", NWScript_GetFootstepType, -1);
	rb_define_method(cNWScript, "SetFootstepType", NWScript_SetFootstepType, -1);
	rb_define_method(cNWScript, "GetCreatureWingType", NWScript_GetCreatureWingType, -1);
	rb_define_method(cNWScript, "SetCreatureWingType", NWScript_SetCreatureWingType, -1);
	rb_define_method(cNWScript, "GetCreatureBodyPart", NWScript_GetCreatureBodyPart, -1);
	rb_define_method(cNWScript, "SetCreatureBodyPart", NWScript_SetCreatureBodyPart, -1);
	rb_define_method(cNWScript, "GetCreatureTailType", NWScript_GetCreatureTailType, -1);
	rb_define_method(cNWScript, "SetCreatureTailType", NWScript_SetCreatureTailType, -1);
	rb_define_method(cNWScript, "GetHardness", NWScript_GetHardness, -1);
	rb_define_method(cNWScript, "SetHardness", NWScript_SetHardness, -1);
	rb_define_method(cNWScript, "SetLockKeyRequired", NWScript_SetLockKeyRequired, -1);
	rb_define_method(cNWScript, "SetLockKeyTag", NWScript_SetLockKeyTag, 2);
	rb_define_method(cNWScript, "SetLockLockable", NWScript_SetLockLockable, -1);
	rb_define_method(cNWScript, "SetLockUnlockDC", NWScript_SetLockUnlockDC, 2);
	rb_define_method(cNWScript, "SetLockLockDC", NWScript_SetLockLockDC, 2);
	rb_define_method(cNWScript, "SetTrapDisarmable", NWScript_SetTrapDisarmable, -1);
	rb_define_method(cNWScript, "SetTrapDetectable", NWScript_SetTrapDetectable, -1);
	rb_define_method(cNWScript, "SetTrapOneShot", NWScript_SetTrapOneShot, -1);
	rb_define_method(cNWScript, "SetTrapKeyTag", NWScript_SetTrapKeyTag, 2);
	rb_define_method(cNWScript, "SetTrapDisarmDC", NWScript_SetTrapDisarmDC, 2);
	rb_define_method(cNWScript, "SetTrapDetectDC", NWScript_SetTrapDetectDC, 2);
	rb_define_method(cNWScript, "CreateTrapAtLocation", NWScript_CreateTrapAtLocation, -1);
	rb_define_method(cNWScript, "CreateTrapOnObject", NWScript_CreateTrapOnObject, -1);
	rb_define_method(cNWScript, "SetWillSavingThrow", NWScript_SetWillSavingThrow, 2);
	rb_define_method(cNWScript, "SetReflexSavingThrow", NWScript_SetReflexSavingThrow, 2);
	rb_define_method(cNWScript, "SetFortitudeSavingThrow", NWScript_SetFortitudeSavingThrow, 2);
	rb_define_method(cNWScript, "GetTilesetResRef", NWScript_GetTilesetResRef, 1);
	rb_define_method(cNWScript, "GetTrapRecoverable", NWScript_GetTrapRecoverable, 1);
	rb_define_method(cNWScript, "SetTrapRecoverable", NWScript_SetTrapRecoverable, -1);
	rb_define_method(cNWScript, "GetModuleXPScale", NWScript_GetModuleXPScale, 0);
	rb_define_method(cNWScript, "SetModuleXPScale", NWScript_SetModuleXPScale, 1);
	rb_define_method(cNWScript, "GetKeyRequiredFeedback", NWScript_GetKeyRequiredFeedback, 1);
	rb_define_method(cNWScript, "SetKeyRequiredFeedback", NWScript_SetKeyRequiredFeedback, 2);
	rb_define_method(cNWScript, "GetTrapActive", NWScript_GetTrapActive, 1);
	rb_define_method(cNWScript, "SetTrapActive", NWScript_SetTrapActive, -1);
	rb_define_method(cNWScript, "LockCameraPitch", NWScript_LockCameraPitch, -1);
	rb_define_method(cNWScript, "LockCameraDistance", NWScript_LockCameraDistance, -1);
	rb_define_method(cNWScript, "LockCameraDirection", NWScript_LockCameraDirection, -1);
	rb_define_method(cNWScript, "GetPlaceableLastClickedBy", NWScript_GetPlaceableLastClickedBy, 0);
	rb_define_method(cNWScript, "GetInfiniteFlag", NWScript_GetInfiniteFlag, 1);
	rb_define_method(cNWScript, "SetInfiniteFlag", NWScript_SetInfiniteFlag, -1);
	rb_define_method(cNWScript, "GetAreaSize", NWScript_GetAreaSize, -1);
	rb_define_method(cNWScript, "SetName", NWScript_SetName, -1);
	rb_define_method(cNWScript, "GetPortraitId", NWScript_GetPortraitId, -1);
	rb_define_method(cNWScript, "SetPortraitId", NWScript_SetPortraitId, 2);
	rb_define_method(cNWScript, "GetPortraitResRef", NWScript_GetPortraitResRef, -1);
	rb_define_method(cNWScript, "SetPortraitResRef", NWScript_SetPortraitResRef, 2);
	rb_define_method(cNWScript, "SetUseableFlag", NWScript_SetUseableFlag, 2);
	rb_define_method(cNWScript, "GetDescription", NWScript_GetDescription, -1);
	rb_define_method(cNWScript, "SetDescription", NWScript_SetDescription, -1);
	rb_define_method(cNWScript, "GetPCChatSpeaker", NWScript_GetPCChatSpeaker, 0);
	rb_define_method(cNWScript, "GetPCChatMessage", NWScript_GetPCChatMessage, 0);
	rb_define_method(cNWScript, "GetPCChatVolume", NWScript_GetPCChatVolume, 0);
	rb_define_method(cNWScript, "SetPCChatMessage", NWScript_SetPCChatMessage, -1);
	rb_define_method(cNWScript, "SetPCChatVolume", NWScript_SetPCChatVolume, -1);
	rb_define_method(cNWScript, "GetColor", NWScript_GetColor, 2);
	rb_define_method(cNWScript, "SetColor", NWScript_SetColor, 3);
	rb_define_method(cNWScript, "ItemPropertyMaterial", NWScript_ItemPropertyMaterial, 1);
	rb_define_method(cNWScript, "ItemPropertyQuality", NWScript_ItemPropertyQuality, 1);
	rb_define_method(cNWScript, "ItemPropertyAdditional", NWScript_ItemPropertyAdditional, 1);


	rb_define_class_variable(cNWScript, "@@retval", INT2NUM(0));
	return cNWScript;
}

