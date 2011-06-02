// Get an integer between 0 and nMaxInteger-1.
// Return value on error: 0
int Random(int nMaxInteger);

// Output sString to the log file.
void PrintString(string sString);

// Output a formatted float to the log file.
// - nWidth should be a value from 0 to 18 inclusive.
// - nDecimals should be a value from 0 to 9 inclusive.
void PrintFloat(float fFloat, int nWidth=18, int nDecimals=9);

// Convert fFloat into a string.
// - nWidth should be a value from 0 to 18 inclusive.
// - nDecimals should be a value from 0 to 9 inclusive.
string FloatToString(float fFloat, int nWidth=18, int nDecimals=9);

// Output nInteger to the log file.
void PrintInteger(int nInteger);

// Output oObject's ID to the log file.
void PrintObject(object oObject);

// Assign aActionToAssign to oActionSubject.
// * No return value, but if an error occurs, the log file will contain
//   "AssignCommand failed."
//   (If the object doesn't exist, nothing happens.)
void AssignCommand(object oActionSubject,action aActionToAssign);

// Delay aActionToDelay by fSeconds.
// * No return value, but if an error occurs, the log file will contain
//   "DelayCommand failed.".
// It is suggested that functions which create effects should not be used
// as parameters to delayed actions.  Instead, the effect should be created in the
// script and then passed into the action.  For example:
// effect eDamage = EffectDamage(nDamage, DAMAGE_TYPE_MAGICAL);
// DelayCommand(fDelay, ApplyEffectToObject(DURATION_TYPE_INSTANT, eDamage, oTarget);
void DelayCommand(float fSeconds, action aActionToDelay);

// Make oTarget run sScript and then return execution to the calling script.
// If sScript does not specify a compiled script, nothing happens.
void ExecuteScript(string sScript, object oTarget);

// Clear all the actions of the caller.
// * No return value, but if an error occurs, the log file will contain
//   "ClearAllActions failed.".
// - nClearCombatState: if true, this will immediately clear the combat state
//   on a creature, which will stop the combat music and allow them to rest,
//   engage in dialog, or other actions that they would normally have to wait for.
void ClearAllActions(int nClearCombatState=FALSE);

// Cause the caller to face fDirection.
// - fDirection is expressed as anticlockwise degrees from Due East.
//   DIRECTION_EAST, DIRECTION_NORTH, DIRECTION_WEST and DIRECTION_SOUTH are
//   predefined. (0.0f=East, 90.0f=North, 180.0f=West, 270.0f=South)
void SetFacing(float fDirection);

// Set the calendar to the specified date.
// - nYear should be from 0 to 32000 inclusive
// - nMonth should be from 1 to 12 inclusive
// - nDay should be from 1 to 28 inclusive
// 1) Time can only be advanced forwards; attempting to set the time backwards
//    will result in no change to the calendar.
// 2) If values larger than the month or day are specified, they will be wrapped
//    around and the overflow will be used to advance the next field.
//    e.g. Specifying a year of 1350, month of 33 and day of 10 will result in
//    the calender being set to a year of 1352, a month of 9 and a day of 10.
void SetCalendar(int nYear,int nMonth, int nDay);

// Set the time to the time specified.
// - nHour should be from 0 to 23 inclusive
// - nMinute should be from 0 to 59 inclusive
// - nSecond should be from 0 to 59 inclusive
// - nMillisecond should be from 0 to 999 inclusive
// 1) Time can only be advanced forwards; attempting to set the time backwards
//    will result in the day advancing and then the time being set to that
//    specified, e.g. if the current hour is 15 and then the hour is set to 3,
//    the day will be advanced by 1 and the hour will be set to 3.
// 2) If values larger than the max hour, minute, second or millisecond are
//    specified, they will be wrapped around and the overflow will be used to
//    advance the next field, e.g. specifying 62 hours, 250 minutes, 10 seconds
//    and 10 milliseconds will result in the calendar day being advanced by 2
//    and the time being set to 18 hours, 10 minutes, 10 milliseconds.
void SetTime(int nHour,int nMinute,int nSecond,int nMillisecond);

// Get the current calendar year.
int GetCalendarYear();

// Get the current calendar month.
int GetCalendarMonth();

// Get the current calendar day.
int GetCalendarDay();

// Get the current hour.
int GetTimeHour();

// Get the current minute
int GetTimeMinute();

// Get the current second
int GetTimeSecond();

// Get the current millisecond
int GetTimeMillisecond();

// The action subject will generate a random location near its current location
// and pathfind to it.  ActionRandomwalk never ends, which means it is neccessary
// to call ClearAllActions in order to allow a creature to perform any other action
// once ActionRandomWalk has been called.
// * No return value, but if an error occurs the log file will contain
//   "ActionRandomWalk failed."
void ActionRandomWalk();

// The action subject will move to lDestination.
// - lDestination: The object will move to this location.  If the location is
//   invalid or a path cannot be found to it, the command does nothing.
// - bRun: If this is TRUE, the action subject will run rather than walk
// * No return value, but if an error occurs the log file will contain
//   "MoveToPoint failed."
void ActionMoveToLocation(location lDestination, int bRun=FALSE);

// Cause the action subject to move to a certain distance from oMoveTo.
// If there is no path to oMoveTo, this command will do nothing.
// - oMoveTo: This is the object we wish the action subject to move to
// - bRun: If this is TRUE, the action subject will run rather than walk
// - fRange: This is the desired distance between the action subject and oMoveTo
// * No return value, but if an error occurs the log file will contain
//   "ActionMoveToObject failed."
void ActionMoveToObject(object oMoveTo, int bRun=FALSE, float fRange=1.0f);

// Cause the action subject to move to a certain distance away from oFleeFrom.
// - oFleeFrom: This is the object we wish the action subject to move away from.
//   If oFleeFrom is not in the same area as the action subject, nothing will
//   happen.
// - bRun: If this is TRUE, the action subject will run rather than walk
// - fMoveAwayRange: This is the distance we wish the action subject to put
//   between themselves and oFleeFrom
// * No return value, but if an error occurs the log file will contain
//   "ActionMoveAwayFromObject failed."
void ActionMoveAwayFromObject(object oFleeFrom, int bRun=FALSE, float fMoveAwayRange=40.0f);

// Get the area that oTarget is currently in
// * Return value on error: OBJECT_INVALID
object GetArea(object oTarget);

// The value returned by this function depends on the object type of the caller:
// 1) If the caller is a door it returns the object that last
//    triggered it.
// 2) If the caller is a trigger, area of effect, module, area or encounter it
//    returns the object that last entered it.
// * Return value on error: OBJECT_INVALID
//  When used for doors, this should only be called from the OnAreaTransitionClick
//  event.  Otherwise, it should only be called in OnEnter scripts.
object GetEnteringObject();

// Get the object that last left the caller.  This function works on triggers,
// areas of effect, modules, areas and encounters.
// * Return value on error: OBJECT_INVALID
// Should only be called in OnExit scripts.
object GetExitingObject();

// Get the position of oTarget
// * Return value on error: vector (0.0f, 0.0f, 0.0f)
vector GetPosition(object oTarget);

// Get the direction in which oTarget is facing, expressed as a float between
// 0.0f and 360.0f
// * Return value on error: -1.0f
float GetFacing(object oTarget);

// Get the possessor of oItem
// * Return value on error: OBJECT_INVALID
object GetItemPossessor(object oItem);

// Get the object possessed by oCreature with the tag sItemTag
// * Return value on error: OBJECT_INVALID
object GetItemPossessedBy(object oCreature, string sItemTag);

// Create an item with the template sItemTemplate in oTarget's inventory.
// - nStackSize: This is the stack size of the item to be created
// - sNewTag: If this string is not empty, it will replace the default tag from the template
// * Return value: The object that has been created.  On error, this returns
//   OBJECT_INVALID.
// If the item created was merged into an existing stack of similar items,
// the function will return the merged stack object. If the merged stack
// overflowed, the function will return the overflowed stack that was created.
object CreateItemOnObject(string sItemTemplate, object oTarget=OBJECT_SELF, int nStackSize=1, string sNewTag="");

// Equip oItem into nInventorySlot.
// - nInventorySlot: INVENTORY_SLOT_*
// * No return value, but if an error occurs the log file will contain
//   "ActionEquipItem failed."
//
// Note: 
//       If the creature already has an item equipped in the slot specified, it will be 
//       unequipped automatically by the call to ActionEquipItem.
//     
//       In order for ActionEquipItem to succeed the creature must be able to equip the
//       item oItem normally. This means that:
//       1) The item is in the creature's inventory.
//       2) The item must already be identified (if magical). 
//       3) The creature has the level required to equip the item (if magical and ILR is on).
//       4) The creature possesses the required feats to equip the item (such as weapon proficiencies).
void ActionEquipItem(object oItem, int nInventorySlot);

// Unequip oItem from whatever slot it is currently in.
void ActionUnequipItem(object oItem);

// Pick up oItem from the ground.
// * No return value, but if an error occurs the log file will contain
//   "ActionPickUpItem failed."
void ActionPickUpItem(object oItem);

// Put down oItem on the ground.
// * No return value, but if an error occurs the log file will contain
//   "ActionPutDownItem failed."
void ActionPutDownItem(object oItem);

// Get the last attacker of oAttackee.  This should only be used ONLY in the
// OnAttacked events for creatures, placeables and doors.
// * Return value on error: OBJECT_INVALID
object GetLastAttacker(object oAttackee=OBJECT_SELF);

// Attack oAttackee.
// - bPassive: If this is TRUE, attack is in passive mode.
void ActionAttack(object oAttackee, int bPassive=FALSE);

// Get the creature nearest to oTarget, subject to all the criteria specified.
// - nFirstCriteriaType: CREATURE_TYPE_*
// - nFirstCriteriaValue:
//   -> CLASS_TYPE_* if nFirstCriteriaType was CREATURE_TYPE_CLASS
//   -> SPELL_* if nFirstCriteriaType was CREATURE_TYPE_DOES_NOT_HAVE_SPELL_EFFECT
//      or CREATURE_TYPE_HAS_SPELL_EFFECT
//   -> TRUE or FALSE if nFirstCriteriaType was CREATURE_TYPE_IS_ALIVE
//   -> PERCEPTION_* if nFirstCriteriaType was CREATURE_TYPE_PERCEPTION
//   -> PLAYER_CHAR_IS_PC or PLAYER_CHAR_NOT_PC if nFirstCriteriaType was
//      CREATURE_TYPE_PLAYER_CHAR
//   -> RACIAL_TYPE_* if nFirstCriteriaType was CREATURE_TYPE_RACIAL_TYPE
//   -> REPUTATION_TYPE_* if nFirstCriteriaType was CREATURE_TYPE_REPUTATION
//   For example, to get the nearest PC, use:
//   (CREATURE_TYPE_PLAYER_CHAR, PLAYER_CHAR_IS_PC)
// - oTarget: We're trying to find the creature of the specified type that is
//   nearest to oTarget
// - nNth: We don't have to find the first nearest: we can find the Nth nearest...
// - nSecondCriteriaType: This is used in the same way as nFirstCriteriaType to
//   further specify the type of creature that we are looking for.
// - nSecondCriteriaValue: This is used in the same way as nFirstCriteriaValue
//   to further specify the type of creature that we are looking for.
// - nThirdCriteriaType: This is used in the same way as nFirstCriteriaType to
//   further specify the type of creature that we are looking for.
// - nThirdCriteriaValue: This is used in the same way as nFirstCriteriaValue to
//   further specify the type of creature that we are looking for.
// * Return value on error: OBJECT_INVALID
object GetNearestCreature(int nFirstCriteriaType, int nFirstCriteriaValue, object oTarget=OBJECT_SELF, int nNth=1, int nSecondCriteriaType=-1, int nSecondCriteriaValue=-1, int nThirdCriteriaType=-1,  int nThirdCriteriaValue=-1 );

// Add a speak action to the action subject.
// - sStringToSpeak: String to be spoken
// - nTalkVolume: TALKVOLUME_*
void ActionSpeakString(string sStringToSpeak, int nTalkVolume=TALKVOLUME_TALK);

// Cause the action subject to play an animation
// - nAnimation: ANIMATION_*
// - fSpeed: Speed of the animation
// - fDurationSeconds: Duration of the animation (this is not used for Fire and
//   Forget animations)
void ActionPlayAnimation(int nAnimation, float fSpeed=1.0, float fDurationSeconds=0.0);

// Get the distance from the caller to oObject in metres.
// * Return value on error: -1.0f
float GetDistanceToObject(object oObject);

// * Returns TRUE if oObject is a valid object.
int GetIsObjectValid(object oObject);

// Cause the action subject to open oDoor
void ActionOpenDoor(object oDoor);

// Cause the action subject to close oDoor
void ActionCloseDoor(object oDoor);

// Change the direction in which the camera is facing
// - fDirection is expressed as anticlockwise degrees from Due East.
//   (0.0f=East, 90.0f=North, 180.0f=West, 270.0f=South)
// A value of -1.0f for any parameter will be ignored and instead it will
// use the current camera value.
// This can be used to change the way the camera is facing after the player
// emerges from an area transition.
// - nTransitionType: CAMERA_TRANSITION_TYPE_*  SNAP will immediately move the
//   camera to the new position, while the other types will result in the camera moving gradually into position
// Pitch and distance are limited to valid values for the current camera mode:
// Top Down: Distance = 5-20, Pitch = 1-50
// Driving camera: Distance = 6 (can't be changed), Pitch = 1-62
// Chase: Distance = 5-20, Pitch = 1-50
// *** NOTE *** In NWN:Hordes of the Underdark the camera limits have been relaxed to the following:
// Distance 1-25
// Pitch 1-89
void SetCameraFacing(float fDirection, float fDistance = -1.0f, float fPitch = -1.0, int nTransitionType=CAMERA_TRANSITION_TYPE_SNAP);

// Play sSoundName
// - sSoundName: TBD - SS
// This will play a mono sound from the location of the object running the command.
void PlaySound(string sSoundName);

// Get the object at which the caller last cast a spell
// * Return value on error: OBJECT_INVALID
object GetSpellTargetObject();

// This action casts a spell at oTarget.
// - nSpell: SPELL_*
// - oTarget: Target for the spell
// - nMetamagic: METAMAGIC_*
// - bCheat: If this is TRUE, then the executor of the action doesn't have to be
//   able to cast the spell.
// - nDomainLevel: TBD - SS
// - nProjectilePathType: PROJECTILE_PATH_TYPE_*
// - bInstantSpell: If this is TRUE, the spell is cast immediately. This allows
//   the end-user to simulate a high-level magic-user having lots of advance
//   warning of impending trouble
void ActionCastSpellAtObject(int nSpell, object oTarget, int nMetaMagic=METAMAGIC_ANY, int bCheat=FALSE, int nDomainLevel=0, int nProjectilePathType=PROJECTILE_PATH_TYPE_DEFAULT, int bInstantSpell=FALSE);

// Get the current hitpoints of oObject
// * Return value on error: 0
int GetCurrentHitPoints(object oObject=OBJECT_SELF);

// Get the maximum hitpoints of oObject
// * Return value on error: 0
int GetMaxHitPoints(object oObject=OBJECT_SELF);

// Get oObject's local integer variable sVarName
// * Return value on error: 0
int GetLocalInt(object oObject, string sVarName);

// Get oObject's local float variable sVarName
// * Return value on error: 0.0f
float GetLocalFloat(object oObject, string sVarName);

// Get oObject's local string variable sVarName
// * Return value on error: ""
string GetLocalString(object oObject, string sVarName);

// Get oObject's local object variable sVarName
// * Return value on error: OBJECT_INVALID
object GetLocalObject(object oObject, string sVarName);

// Set oObject's local integer variable sVarName to nValue
void SetLocalInt(object oObject, string sVarName, int nValue);

// Set oObject's local float variable sVarName to nValue
void SetLocalFloat(object oObject, string sVarName, float fValue);

// Set oObject's local string variable sVarName to nValue
void SetLocalString(object oObject, string sVarName, string sValue);

// Set oObject's local object variable sVarName to nValue
void SetLocalObject(object oObject, string sVarName, object oValue);

// Get the length of sString
// * Return value on error: -1
int GetStringLength(string sString);

// Convert sString into upper case
// * Return value on error: ""
string GetStringUpperCase(string sString);

// Convert sString into lower case
// * Return value on error: ""
string GetStringLowerCase(string sString);

// Get nCount characters from the right end of sString
// * Return value on error: ""
string GetStringRight(string sString, int nCount);

// Get nCounter characters from the left end of sString
// * Return value on error: ""
string GetStringLeft(string sString, int nCount);

// Insert sString into sDestination at nPosition
// * Return value on error: ""
string InsertString(string sDestination, string sString, int nPosition);

// Get nCount characters from sString, starting at nStart
// * Return value on error: ""
string GetSubString(string sString, int nStart, int nCount);

// Find the position of sSubstring inside sString
// - nStart: The character position to start searching at (from the left end of the string). 
// * Return value on error: -1
int FindSubString(string sString, string sSubString, int nStart=0);

// math operations

// Maths operation: absolute value of fValue
float fabs(float fValue);

// Maths operation: cosine of fValue
float cos(float fValue);

// Maths operation: sine of fValue
float sin(float fValue);

// Maths operation: tan of fValue
float tan(float fValue);

// Maths operation: arccosine of fValue
// * Returns zero if fValue > 1 or fValue < -1
float acos(float fValue);

// Maths operation: arcsine of fValue
// * Returns zero if fValue >1 or fValue < -1
float asin(float fValue);

// Maths operation: arctan of fValue
float atan(float fValue);

// Maths operation: log of fValue
// * Returns zero if fValue <= zero
float log(float fValue);

// Maths operation: fValue is raised to the power of fExponent
// * Returns zero if fValue ==0 and fExponent <0
float pow(float fValue, float fExponent);

// Maths operation: square root of fValue
// * Returns zero if fValue <0
float sqrt(float fValue);

// Maths operation: integer absolute value of nValue
// * Return value on error: 0
int abs(int nValue);

// Create a Heal effect. This should be applied as an instantaneous effect.
// * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nDamageToHeal < 0.
effect EffectHeal(int nDamageToHeal);

// Create a Damage effect
// - nDamageAmount: amount of damage to be dealt. This should be applied as an
//   instantaneous effect.
// - nDamageType: DAMAGE_TYPE_*
// - nDamagePower: DAMAGE_POWER_*
effect EffectDamage(int nDamageAmount, int nDamageType=DAMAGE_TYPE_MAGICAL, int nDamagePower=DAMAGE_POWER_NORMAL);

// Create an Ability Increase effect
// - bAbilityToIncrease: ABILITY_*
effect EffectAbilityIncrease(int nAbilityToIncrease, int nModifyBy);

// Create a Damage Resistance effect that removes the first nAmount points of
// damage of type nDamageType, up to nLimit (or infinite if nLimit is 0)
// - nDamageType: DAMAGE_TYPE_*
// - nAmount
// - nLimit
effect EffectDamageResistance(int nDamageType, int nAmount, int nLimit=0);

// Create a Resurrection effect. This should be applied as an instantaneous effect.
effect EffectResurrection();

// Create a Summon Creature effect.  The creature is created and placed into the
// caller's party/faction.
// - sCreatureResref: Identifies the creature to be summoned
// - nVisualEffectId: VFX_*
// - fDelaySeconds: There can be delay between the visual effect being played, and the
//   creature being added to the area
// - nUseAppearAnimation: should this creature play it's "appear" animation when it is
//   summoned. If zero, it will just fade in somewhere near the target.  If the value is 1
//   it will use the appear animation, and if it's 2 it will use appear2 (which doesn't exist for most creatures)
effect EffectSummonCreature(string sCreatureResref, int nVisualEffectId=VFX_NONE, float fDelaySeconds=0.0f, int nUseAppearAnimation=0);

// Get the level at which this creature cast it's last spell (or spell-like ability)
// * Return value on error, or if oCreature has not yet cast a spell: 0;
int GetCasterLevel(object oCreature);

// Get the first in-game effect on oCreature.
effect GetFirstEffect(object oCreature);

// Get the next in-game effect on oCreature.
effect GetNextEffect(object oCreature);

// Remove eEffect from oCreature.
// * No return value
void RemoveEffect(object oCreature, effect eEffect);

// * Returns TRUE if eEffect is a valid effect. The effect must have been applied to
// * an object or else it will return FALSE
int GetIsEffectValid(effect eEffect);

// Get the duration type (DURATION_TYPE_*) of eEffect.
// * Return value if eEffect is not valid: -1
int GetEffectDurationType(effect eEffect);

// Get the subtype (SUBTYPE_*) of eEffect.
// * Return value on error: 0
int GetEffectSubType(effect eEffect);

// Get the object that created eEffect.
// * Returns OBJECT_INVALID if eEffect is not a valid effect.
object GetEffectCreator(effect eEffect);

// Convert nInteger into a string.
// * Return value on error: ""
string IntToString(int nInteger);

// Get the first object in oArea.
// If no valid area is specified, it will use the caller's area.
// * Return value on error: OBJECT_INVALID
object GetFirstObjectInArea(object oArea=OBJECT_INVALID);

// Get the next object in oArea.
// If no valid area is specified, it will use the caller's area.
// * Return value on error: OBJECT_INVALID
object GetNextObjectInArea(object oArea=OBJECT_INVALID);

// Get the total from rolling (nNumDice x d2 dice).
// - nNumDice: If this is less than 1, the value 1 will be used.
int d2(int nNumDice=1);

// Get the total from rolling (nNumDice x d3 dice).
// - nNumDice: If this is less than 1, the value 1 will be used.
int d3(int nNumDice=1);

// Get the total from rolling (nNumDice x d4 dice).
// - nNumDice: If this is less than 1, the value 1 will be used.
int d4(int nNumDice=1);

// Get the total from rolling (nNumDice x d6 dice).
// - nNumDice: If this is less than 1, the value 1 will be used.
int d6(int nNumDice=1);

// Get the total from rolling (nNumDice x d8 dice).
// - nNumDice: If this is less than 1, the value 1 will be used.
int d8(int nNumDice=1);

// Get the total from rolling (nNumDice x d10 dice).
// - nNumDice: If this is less than 1, the value 1 will be used.
int d10(int nNumDice=1);

// Get the total from rolling (nNumDice x d12 dice).
// - nNumDice: If this is less than 1, the value 1 will be used.
int d12(int nNumDice=1);

// Get the total from rolling (nNumDice x d20 dice).
// - nNumDice: If this is less than 1, the value 1 will be used.
int d20(int nNumDice=1);

// Get the total from rolling (nNumDice x d100 dice).
// - nNumDice: If this is less than 1, the value 1 will be used.
int d100(int nNumDice=1);

// Get the magnitude of vVector; this can be used to determine the
// distance between two points.
// * Return value on error: 0.0f
float VectorMagnitude(vector vVector);

// Get the metamagic type (METAMAGIC_*) of the last spell cast by the caller
// * Return value if the caster is not a valid object: -1
int GetMetaMagicFeat();

// Get the object type (OBJECT_TYPE_*) of oTarget
// * Return value if oTarget is not a valid object: -1
int GetObjectType(object oTarget);

// Get the racial type (RACIAL_TYPE_*) of oCreature
// * Return value if oCreature is not a valid creature: RACIAL_TYPE_INVALID
int GetRacialType(object oCreature);

// Do a Fortitude Save check for the given DC
// - oCreature
// - nDC: Difficulty check
// - nSaveType: SAVING_THROW_TYPE_*
// - oSaveVersus
// Returns: 0 if the saving throw roll failed
// Returns: 1 if the saving throw roll succeeded
// Returns: 2 if the target was immune to the save type specified
// Note: If used within an Area of Effect Object Script (On Enter, OnExit, OnHeartbeat), you MUST pass
// GetAreaOfEffectCreator() into oSaveVersus!!
int FortitudeSave(object oCreature, int nDC, int nSaveType=SAVING_THROW_TYPE_NONE, object oSaveVersus=OBJECT_SELF);

// Does a Reflex Save check for the given DC
// - oCreature
// - nDC: Difficulty check
// - nSaveType: SAVING_THROW_TYPE_*
// - oSaveVersus
// Returns: 0 if the saving throw roll failed
// Returns: 1 if the saving throw roll succeeded
// Returns: 2 if the target was immune to the save type specified
// Note: If used within an Area of Effect Object Script (On Enter, OnExit, OnHeartbeat), you MUST pass
// GetAreaOfEffectCreator() into oSaveVersus!!
int ReflexSave(object oCreature, int nDC, int nSaveType=SAVING_THROW_TYPE_NONE, object oSaveVersus=OBJECT_SELF);

// Does a Will Save check for the given DC
// - oCreature
// - nDC: Difficulty check
// - nSaveType: SAVING_THROW_TYPE_*
// - oSaveVersus
// Returns: 0 if the saving throw roll failed
// Returns: 1 if the saving throw roll succeeded
// Returns: 2 if the target was immune to the save type specified
// Note: If used within an Area of Effect Object Script (On Enter, OnExit, OnHeartbeat), you MUST pass
// GetAreaOfEffectCreator() into oSaveVersus!!
int WillSave(object oCreature, int nDC, int nSaveType=SAVING_THROW_TYPE_NONE, object oSaveVersus=OBJECT_SELF);

// Get the DC to save against for a spell (10 + spell level + relevant ability
// bonus).  This can be called by a creature or by an Area of Effect object.
int GetSpellSaveDC();

// Set the subtype of eEffect to Magical and return eEffect.
// (Effects default to magical if the subtype is not set)
// Magical effects are removed by resting, and by dispel magic
effect MagicalEffect(effect eEffect);

// Set the subtype of eEffect to Supernatural and return eEffect.
// (Effects default to magical if the subtype is not set)
// Permanent supernatural effects are not removed by resting
effect SupernaturalEffect(effect eEffect);

// Set the subtype of eEffect to Extraordinary and return eEffect.
// (Effects default to magical if the subtype is not set)
// Extraordinary effects are removed by resting, but not by dispel magic
effect ExtraordinaryEffect(effect eEffect);

// Create an AC Increase effect
// - nValue: size of AC increase
// - nModifyType: AC_*_BONUS
// - nDamageType: DAMAGE_TYPE_*
//   * Default value for nDamageType should only ever be used in this function prototype.
effect EffectACIncrease(int nValue, int nModifyType=AC_DODGE_BONUS, int nDamageType=AC_VS_DAMAGE_TYPE_ALL);

// If oObject is a creature, this will return that creature's armour class
// If oObject is an item, door or placeable, this will return zero.
// - nForFutureUse: this parameter is not currently used
// * Return value if oObject is not a creature, item, door or placeable: -1
int GetAC(object oObject, int nForFutureUse=0);

// Create a Saving Throw Increase effect
// - nSave: SAVING_THROW_* (not SAVING_THROW_TYPE_*)
//          SAVING_THROW_ALL
//          SAVING_THROW_FORT
//          SAVING_THROW_REFLEX
//          SAVING_THROW_WILL 
// - nValue: size of the Saving Throw increase
// - nSaveType: SAVING_THROW_TYPE_* (e.g. SAVING_THROW_TYPE_ACID )
effect EffectSavingThrowIncrease(int nSave, int nValue, int nSaveType=SAVING_THROW_TYPE_ALL);

// Create an Attack Increase effect
// - nBonus: size of attack bonus
// - nModifierType: ATTACK_BONUS_*
effect EffectAttackIncrease(int nBonus, int nModifierType=ATTACK_BONUS_MISC);

// Create a Damage Reduction effect
// - nAmount: amount of damage reduction
// - nDamagePower: DAMAGE_POWER_*
// - nLimit: How much damage the effect can absorb before disappearing.
//   Set to zero for infinite
effect EffectDamageReduction(int nAmount, int nDamagePower, int nLimit=0);

// Create a Damage Increase effect
// - nBonus: DAMAGE_BONUS_*
// - nDamageType: DAMAGE_TYPE_*
// NOTE! You *must* use the DAMAGE_BONUS_* constants! Using other values may
//       result in odd behaviour.
effect EffectDamageIncrease(int nBonus, int nDamageType=DAMAGE_TYPE_MAGICAL);

// Convert nRounds into a number of seconds
// A round is always 6.0 seconds
float RoundsToSeconds(int nRounds);

// Convert nHours into a number of seconds
// The result will depend on how many minutes there are per hour (game-time)
float HoursToSeconds(int nHours);

// Convert nTurns into a number of seconds
// A turn is always 60.0 seconds
float TurnsToSeconds(int nTurns);

// Get an integer between 0 and 100 (inclusive) to represent oCreature's
// Law/Chaos alignment
// (100=law, 0=chaos)
// * Return value if oCreature is not a valid creature: -1
int GetLawChaosValue(object oCreature);

// Get an integer between 0 and 100 (inclusive) to represent oCreature's
// Good/Evil alignment
// (100=good, 0=evil)
// * Return value if oCreature is not a valid creature: -1
int GetGoodEvilValue(object oCreature);

// Return an ALIGNMENT_* constant to represent oCreature's law/chaos alignment
// * Return value if oCreature is not a valid creature: -1
int GetAlignmentLawChaos(object oCreature);

// Return an ALIGNMENT_* constant to represent oCreature's good/evil alignment
// * Return value if oCreature is not a valid creature: -1
int GetAlignmentGoodEvil(object oCreature);

// Get the first object in nShape
// - nShape: SHAPE_*
// - fSize:
//   -> If nShape == SHAPE_SPHERE, this is the radius of the sphere
//   -> If nShape == SHAPE_SPELLCYLINDER, this is the length of the cylinder
//      Spell Cylinder's always have a radius of 1.5m.
//   -> If nShape == SHAPE_CONE, this is the widest radius of the cone
//   -> If nShape == SHAPE_SPELLCONE, this is the length of the cone in the
//      direction of lTarget. Spell cones are always 60 degrees with the origin
//      at OBJECT_SELF.
//   -> If nShape == SHAPE_CUBE, this is half the length of one of the sides of
//      the cube
// - lTarget: This is the centre of the effect, usually GetSpellTargetLocation(),
//   or the end of a cylinder or cone.
// - bLineOfSight: This controls whether to do a line-of-sight check on the
//   object returned. Line of sight check is done from origin to target object
//   at a height 1m above the ground
//   (This can be used to ensure that spell effects do not go through walls.)
// - nObjectFilter: This allows you to filter out undesired object types, using
//   bitwise "or".
//   For example, to return only creatures and doors, the value for this
//   parameter would be OBJECT_TYPE_CREATURE | OBJECT_TYPE_DOOR
// - vOrigin: This is only used for cylinders and cones, and specifies the
//   origin of the effect(normally the spell-caster's position).
// Return value on error: OBJECT_INVALID
object GetFirstObjectInShape(int nShape, float fSize, location lTarget, int bLineOfSight=FALSE, int nObjectFilter=OBJECT_TYPE_CREATURE, vector vOrigin=[0.0,0.0,0.0]);

// Get the next object in nShape
// - nShape: SHAPE_*
// - fSize:
//   -> If nShape == SHAPE_SPHERE, this is the radius of the sphere
//   -> If nShape == SHAPE_SPELLCYLINDER, this is the length of the cylinder.
//      Spell Cylinder's always have a radius of 1.5m.
//   -> If nShape == SHAPE_CONE, this is the widest radius of the cone
//   -> If nShape == SHAPE_SPELLCONE, this is the length of the cone in the
//      direction of lTarget. Spell cones are always 60 degrees with the origin
//      at OBJECT_SELF.
//   -> If nShape == SHAPE_CUBE, this is half the length of one of the sides of
//      the cube
// - lTarget: This is the centre of the effect, usually GetSpellTargetLocation(),
//   or the end of a cylinder or cone.
// - bLineOfSight: This controls whether to do a line-of-sight check on the
//   object returned. (This can be used to ensure that spell effects do not go
//   through walls.) Line of sight check is done from origin to target object
//   at a height 1m above the ground
// - nObjectFilter: This allows you to filter out undesired object types, using
//   bitwise "or". For example, to return only creatures and doors, the value for
//   this parameter would be OBJECT_TYPE_CREATURE | OBJECT_TYPE_DOOR
// - vOrigin: This is only used for cylinders and cones, and specifies the origin
//   of the effect (normally the spell-caster's position).
// Return value on error: OBJECT_INVALID
object GetNextObjectInShape(int nShape, float fSize, location lTarget, int bLineOfSight=FALSE, int nObjectFilter=OBJECT_TYPE_CREATURE, vector vOrigin=[0.0,0.0,0.0]);

// Create an Entangle effect
// When applied, this effect will restrict the creature's movement and apply a
// (-2) to all attacks and a -4 to AC.
effect EffectEntangle();

// Causes object oObject to run the event evToRun. The script on the object that is
// associated with the event specified will run.
// Events can be created using the following event functions:
//    EventActivateItem() - This creates an OnActivateItem module event. The script for handling
//                          this event can be set in Module Properties on the Event Tab.
//    EventConversation() - This creates on OnConversation creature event. The script for handling
//                          this event can be set by viewing the Creature Properties on a 
//                          creature and then clicking on the Scripts Tab.
//    EventSpellCastAt()  - This creates an OnSpellCastAt event. The script for handling this
//                          event can be set in the Scripts Tab of the Properties menu 
//                          for the object.
//    EventUserDefined()  - This creates on OnUserDefined event. The script for handling this event
//                          can be set in the Scripts Tab of the Properties menu for the object/area/module.
void SignalEvent(object oObject, event evToRun);

// Create an event of the type nUserDefinedEventNumber
// Note: This only creates the event. The event wont actually trigger until SignalEvent()
// is called using this created UserDefined event as an argument.
// For example:
//     SignalEvent(oObject, EventUserDefined(9999));
// Once the event has been signaled. The script associated with the OnUserDefined event will
// run on the object oObject.
//
// To specify the OnUserDefined script that should run, view the object's Properties
// and click on the Scripts Tab. Then specify a script for the OnUserDefined event.
// From inside the OnUserDefined script call:
//    GetUserDefinedEventNumber() to retrieve the value of nUserDefinedEventNumber
//    that was used when the event was signaled.
event EventUserDefined(int nUserDefinedEventNumber);

// Create a Death effect
// - nSpectacularDeath: if this is TRUE, the creature to which this effect is
//   applied will die in an extraordinary fashion
// - nDisplayFeedback
effect EffectDeath(int nSpectacularDeath=FALSE, int nDisplayFeedback=TRUE);

// Create a Knockdown effect
// This effect knocks creatures off their feet, they will sit until the effect
// is removed. This should be applied as a temporary effect with a 3 second
// duration minimum (1 second to fall, 1 second sitting, 1 second to get up).
effect EffectKnockdown();

// Give oItem to oGiveTo
// If oItem is not a valid item, or oGiveTo is not a valid object, nothing will
// happen.
void ActionGiveItem(object oItem, object oGiveTo);

// Take oItem from oTakeFrom
// If oItem is not a valid item, or oTakeFrom is not a valid object, nothing
// will happen.
void ActionTakeItem(object oItem, object oTakeFrom);

// Normalize vVector
vector VectorNormalize(vector vVector);

// Create a Curse effect.
// - nStrMod: strength modifier
// - nDexMod: dexterity modifier
// - nConMod: constitution modifier
// - nIntMod: intelligence modifier
// - nWisMod: wisdom modifier
// - nChaMod: charisma modifier
effect EffectCurse(int nStrMod=1, int nDexMod=1, int nConMod=1, int nIntMod=1, int nWisMod=1, int nChaMod=1);

// Get the ability score of type nAbility for a creature (otherwise 0)
// - oCreature: the creature whose ability score we wish to find out
// - nAbilityType: ABILITY_*
// - nBaseAbilityScore: if set to true will return the base ability score without
//                      bonuses (e.g. ability bonuses granted from equipped items).
// Return value on error: 0
int GetAbilityScore(object oCreature, int nAbilityType, int nBaseAbilityScore=FALSE);

// * Returns TRUE if oCreature is a dead NPC, dead PC or a dying PC.
int GetIsDead(object oCreature);

// Output vVector to the logfile.
// - vVector
// - bPrepend: if this is TRUE, the message will be prefixed with "PRINTVECTOR:"
void PrintVector(vector vVector, int bPrepend);

// Create a vector with the specified values for x, y and z
vector Vector(float x=0.0f, float y=0.0f, float z=0.0f);

// Cause the caller to face vTarget
void SetFacingPoint(vector vTarget);

// Convert fAngle to a vector
vector AngleToVector(float fAngle);

// Convert vVector to an angle
float VectorToAngle(vector vVector);

// The caller will perform a Melee Touch Attack on oTarget
// This is not an action, and it assumes the caller is already within range of
// oTarget
// * Returns 0 on a miss, 1 on a hit and 2 on a critical hit
int TouchAttackMelee(object oTarget, int bDisplayFeedback=TRUE);

// The caller will perform a Ranged Touch Attack on oTarget
// * Returns 0 on a miss, 1 on a hit and 2 on a critical hit
int TouchAttackRanged(object oTarget, int bDisplayFeedback=TRUE);

// Create a Paralyze effect
effect EffectParalyze();

// Create a Spell Immunity effect.
// There is a known bug with this function. There *must* be a parameter specified
// when this is called (even if the desired parameter is SPELL_ALL_SPELLS),
// otherwise an effect of type EFFECT_TYPE_INVALIDEFFECT will be returned.
// - nImmunityToSpell: SPELL_*
// * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nImmunityToSpell is
//   invalid.
effect EffectSpellImmunity(int nImmunityToSpell=SPELL_ALL_SPELLS);

// Create a Deaf effect
effect EffectDeaf();

// Get the distance in metres between oObjectA and oObjectB.
// * Return value if either object is invalid: 0.0f
float GetDistanceBetween(object oObjectA, object oObjectB);

// Set oObject's local location variable sVarname to lValue
void SetLocalLocation(object oObject, string sVarName, location lValue);

// Get oObject's local location variable sVarname
location GetLocalLocation(object oObject, string sVarName);

// Create a Sleep effect
effect EffectSleep();

// Get the object which is in oCreature's specified inventory slot
// - nInventorySlot: INVENTORY_SLOT_*
// - oCreature
// * Returns OBJECT_INVALID if oCreature is not a valid creature or there is no
//   item in nInventorySlot.
object GetItemInSlot(int nInventorySlot, object oCreature=OBJECT_SELF);

// Create a Charm effect
effect EffectCharmed();

// Create a Confuse effect
effect EffectConfused();

// Create a Frighten effect
effect EffectFrightened();

// Create a Dominate effect
effect EffectDominated();

// Create a Daze effect
effect EffectDazed();

// Create a Stun effect
effect EffectStunned();

// Set whether oTarget's action stack can be modified
void SetCommandable(int bCommandable, object oTarget=OBJECT_SELF);

// Determine whether oTarget's action stack can be modified.
int GetCommandable(object oTarget=OBJECT_SELF);

// Create a Regenerate effect.
// - nAmount: amount of damage to be regenerated per time interval
// - fIntervalSeconds: length of interval in seconds
effect EffectRegenerate(int nAmount, float fIntervalSeconds);

// Create a Movement Speed Increase effect.
// - nPercentChange - range 0 through 99
// eg.
//    0 = no change in speed
//   50 = 50% faster
//   99 = almost twice as fast
effect EffectMovementSpeedIncrease(int nPercentChange);

// Get the number of hitdice for oCreature.
// * Return value if oCreature is not a valid creature: 0
int GetHitDice(object oCreature);

// The action subject will follow oFollow until a ClearAllActions() is called.
// - oFollow: this is the object to be followed
// - fFollowDistance: follow distance in metres
// * No return value
void ActionForceFollowObject(object oFollow, float fFollowDistance=0.0f);

// Get the Tag of oObject
// * Return value if oObject is not a valid object: ""
string GetTag(object oObject);

// Do a Spell Resistance check between oCaster and oTarget, returning TRUE if
// the spell was resisted.
// * Return value if oCaster or oTarget is an invalid object: FALSE
// * Return value if spell cast is not a player spell: - 1
// * Return value if spell resisted: 1
// * Return value if spell resisted via magic immunity: 2
// * Return value if spell resisted via spell absorption: 3
int ResistSpell(object oCaster, object oTarget);

// Get the effect type (EFFECT_TYPE_*) of eEffect.
// * Return value if eEffect is invalid: EFFECT_INVALIDEFFECT
int GetEffectType(effect eEffect);

// Create an Area Of Effect effect in the area of the creature it is applied to.
// If the scripts are not specified, default ones will be used.
effect EffectAreaOfEffect(int nAreaEffectId, string sOnEnterScript="", string sHeartbeatScript="", string sOnExitScript="");

// * Returns TRUE if the Faction Ids of the two objects are the same
int GetFactionEqual(object oFirstObject, object oSecondObject=OBJECT_SELF);

// Make oObjectToChangeFaction join the faction of oMemberOfFactionToJoin.
// NB. ** This will only work for two NPCs **
void ChangeFaction(object oObjectToChangeFaction, object oMemberOfFactionToJoin);

// * Returns TRUE if oObject is listening for something
int GetIsListening(object oObject);

// Set whether oObject is listening.
void SetListening(object oObject, int bValue);

// Set the string for oObject to listen for.
// Note: this does not set oObject to be listening.
void SetListenPattern(object oObject, string sPattern, int nNumber=0);

// * Returns TRUE if sStringToTest matches sPattern.
int TestStringAgainstPattern(string sPattern, string sStringToTest);

// Get the appropriate matched string (this should only be used in
// OnConversation scripts).
// * Returns the appropriate matched string, otherwise returns ""
string GetMatchedSubstring(int nString);

// Get the number of string parameters available.
// * Returns -1 if no string matched (this could be because of a dialogue event)
int GetMatchedSubstringsCount();

// * Create a Visual Effect that can be applied to an object.
// - nVisualEffectId
// - nMissEffect: if this is TRUE, a random vector near or past the target will
//   be generated, on which to play the effect
effect EffectVisualEffect(int nVisualEffectId, int nMissEffect=FALSE);

// Get the weakest member of oFactionMember's faction.
// * Returns OBJECT_INVALID if oFactionMember's faction is invalid.
object GetFactionWeakestMember(object oFactionMember=OBJECT_SELF, int bMustBeVisible=TRUE);

// Get the strongest member of oFactionMember's faction.
// * Returns OBJECT_INVALID if oFactionMember's faction is invalid.
object GetFactionStrongestMember(object oFactionMember=OBJECT_SELF, int bMustBeVisible=TRUE);

// Get the member of oFactionMember's faction that has taken the most hit points
// of damage.
// * Returns OBJECT_INVALID if oFactionMember's faction is invalid.
object GetFactionMostDamagedMember(object oFactionMember=OBJECT_SELF, int bMustBeVisible=TRUE);

// Get the member of oFactionMember's faction that has taken the fewest hit
// points of damage.
// * Returns OBJECT_INVALID if oFactionMember's faction is invalid.
object GetFactionLeastDamagedMember(object oFactionMember=OBJECT_SELF, int bMustBeVisible=TRUE);

// Get the amount of gold held by oFactionMember's faction.
// * Returns -1 if oFactionMember's faction is invalid.
int GetFactionGold(object oFactionMember);

// Get an integer between 0 and 100 (inclusive) that represents how
// oSourceFactionMember's faction feels about oTarget.
// * Return value on error: -1
int GetFactionAverageReputation(object oSourceFactionMember, object oTarget);

// Get an integer between 0 and 100 (inclusive) that represents the average
// good/evil alignment of oFactionMember's faction.
// * Return value on error: -1
int GetFactionAverageGoodEvilAlignment(object oFactionMember);

// Get an integer between 0 and 100 (inclusive) that represents the average
// law/chaos alignment of oFactionMember's faction.
// * Return value on error: -1
int GetFactionAverageLawChaosAlignment(object oFactionMember);

// Get the average level of the members of the faction.
// * Return value on error: -1
int GetFactionAverageLevel(object oFactionMember);

// Get the average XP of the members of the faction.
// * Return value on error: -1
int GetFactionAverageXP(object oFactionMember);

// Get the most frequent class in the faction - this can be compared with the
// constants CLASS_TYPE_*.
// * Return value on error: -1
int GetFactionMostFrequentClass(object oFactionMember);

// Get the object faction member with the lowest armour class.
// * Returns OBJECT_INVALID if oFactionMember's faction is invalid.
object GetFactionWorstAC(object oFactionMember=OBJECT_SELF, int bMustBeVisible=TRUE);

// Get the object faction member with the highest armour class.
// * Returns OBJECT_INVALID if oFactionMember's faction is invalid.
object GetFactionBestAC(object oFactionMember=OBJECT_SELF, int bMustBeVisible=TRUE);

// Sit in oChair.
// Note: Not all creatures will be able to sit and not all
//       objects can be sat on.
//       The object oChair must also be marked as usable in the toolset.
//
// For Example: To get a player to sit in oChair when they click on it,
// place the following script in the OnUsed event for the object oChair.
// void main()
// {
//    object oChair = OBJECT_SELF;
//    AssignCommand(GetLastUsedBy(),ActionSit(oChair));
// }
void ActionSit(object oChair);

// In an onConversation script this gets the number of the string pattern
// matched (the one that triggered the script).
// * Returns -1 if no string matched
int GetListenPatternNumber();

// Jump to an object ID, or as near to it as possible.
void ActionJumpToObject(object oToJumpTo, int bWalkStraightLineToPoint=TRUE);

// Get the first waypoint with the specified tag.
// * Returns OBJECT_INVALID if the waypoint cannot be found.
object GetWaypointByTag(string sWaypointTag);

// Get the destination (a waypoint or a door) for a trigger or a door.
// * Returns OBJECT_INVALID if oTransition is not a valid trigger or door.
object GetTransitionTarget(object oTransition);

// Link the two supplied effects, returning eChildEffect as a child of
// eParentEffect.
// Note: When applying linked effects if the target is immune to all valid
// effects all other effects will be removed as well. This means that if you
// apply a visual effect and a silence effect (in a link) and the target is
// immune to the silence effect that the visual effect will get removed as well.
// Visual Effects are not considered "valid" effects for the purposes of
// determining if an effect will be removed or not and as such should never be
// packaged *only* with other visual effects in a link.
effect EffectLinkEffects(effect eChildEffect, effect eParentEffect );

// Get the nNth object with the specified tag.
// - sTag
// - nNth: the nth object with this tag may be requested
// * Returns OBJECT_INVALID if the object cannot be found.
// Note: The module cannot be retrieved by GetObjectByTag(), use GetModule() instead.
object GetObjectByTag(string sTag, int nNth=0);

// Adjust the alignment of oSubject.
// - oSubject
// - nAlignment:
//   -> ALIGNMENT_LAWFUL/ALIGNMENT_CHAOTIC/ALIGNMENT_GOOD/ALIGNMENT_EVIL: oSubject's
//      alignment will be shifted in the direction specified
//   -> ALIGNMENT_ALL: nShift will be added to oSubject's law/chaos and
//      good/evil alignment values
//   -> ALIGNMENT_NEUTRAL: nShift is applied to oSubject's law/chaos and
//      good/evil alignment values in the direction which is towards neutrality.
//     e.g. If oSubject has a law/chaos value of 10 (i.e. chaotic) and a
//          good/evil value of 80 (i.e. good) then if nShift is 15, the
//          law/chaos value will become (10+15)=25 and the good/evil value will
//          become (80-25)=55
//     Furthermore, the shift will at most take the alignment value to 50 and
//     not beyond.
//     e.g. If oSubject has a law/chaos value of 40 and a good/evil value of 70,
//          then if nShift is 15, the law/chaos value will become 50 and the
//          good/evil value will become 55
// - nShift: this is the desired shift in alignment
// - bAllPartyMembers: when TRUE the alignment shift of oSubject also has a 
//                     diminished affect all members of oSubject's party (if oSubject is a Player).
//                     When FALSE the shift only affects oSubject.
// * No return value
void AdjustAlignment(object oSubject, int nAlignment, int nShift, int bAllPartyMembers=TRUE);

// Do nothing for fSeconds seconds.
void ActionWait(float fSeconds);

// Set the transition bitmap of a player; this should only be called in area
// transition scripts. This action should be run by the person "clicking" the
// area transition via AssignCommand.
// - nPredefinedAreaTransition:
//   -> To use a predefined area transition bitmap, use one of AREA_TRANSITION_*
//   -> To use a custom, user-defined area transition bitmap, use
//      AREA_TRANSITION_USER_DEFINED and specify the filename in the second
//      parameter
// - sCustomAreaTransitionBMP: this is the filename of a custom, user-defined
//   area transition bitmap
void SetAreaTransitionBMP(int nPredefinedAreaTransition, string sCustomAreaTransitionBMP="");

// Starts a conversation with oObjectToConverseWith - this will cause their
// OnDialog event to fire.
// - oObjectToConverseWith
// - sDialogResRef: If this is blank, the creature's own dialogue file will be used
// - bPrivateConversation
// Turn off bPlayHello if you don't want the initial greeting to play
void ActionStartConversation(object oObjectToConverseWith, string sDialogResRef="", int bPrivateConversation=FALSE, int bPlayHello=TRUE);

// Pause the current conversation.
void ActionPauseConversation();

// Resume a conversation after it has been paused.
void ActionResumeConversation();

// Create a Beam effect.
// - nBeamVisualEffect: VFX_BEAM_*
// - oEffector: the beam is emitted from this creature
// - nBodyPart: BODY_NODE_*
// - bMissEffect: If this is TRUE, the beam will fire to a random vector near or
//   past the target
// * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nBeamVisualEffect is
//   not valid.
effect EffectBeam(int nBeamVisualEffect, object oEffector, int nBodyPart, int bMissEffect=FALSE);

// Get an integer between 0 and 100 (inclusive) that represents how oSource
// feels about oTarget.
// -> 0-10 means oSource is hostile to oTarget
// -> 11-89 means oSource is neutral to oTarget
// -> 90-100 means oSource is friendly to oTarget
// * Returns -1 if oSource or oTarget does not identify a valid object
int GetReputation(object oSource, object oTarget);

// Adjust how oSourceFactionMember's faction feels about oTarget by the
// specified amount.
// Note: This adjusts Faction Reputation, how the entire faction that
// oSourceFactionMember is in, feels about oTarget.
// * No return value
// Note: You can't adjust a player character's (PC) faction towards
//       NPCs, so attempting to make an NPC hostile by passing in a PC object
//       as oSourceFactionMember in the following call will fail:
//       AdjustReputation(oNPC,oPC,-100);
//       Instead you should pass in the PC object as the first
//       parameter as in the following call which should succeed: 
//       AdjustReputation(oPC,oNPC,-100);
// Note: Will fail if oSourceFactionMember is a plot object.
void AdjustReputation(object oTarget, object oSourceFactionMember, int nAdjustment);

// Get the creature that is currently sitting on the specified object.
// - oChair
// * Returns OBJECT_INVALID if oChair is not a valid placeable.
object GetSittingCreature(object oChair);

// Get the creature that is going to attack oTarget.
// Note: This value is cleared out at the end of every combat round and should
// not be used in any case except when getting a "going to be attacked" shout
// from the master creature (and this creature is a henchman)
// * Returns OBJECT_INVALID if oTarget is not a valid creature.
object GetGoingToBeAttackedBy(object oTarget);

// Create a Spell Resistance Increase effect.
// - nValue: size of spell resistance increase
effect EffectSpellResistanceIncrease(int nValue);

// Get the location of oObject.
location GetLocation(object oObject);

// The subject will jump to lLocation instantly (even between areas).
// If lLocation is invalid, nothing will happen.
void ActionJumpToLocation(location lLocation);

// Create a location.
location Location(object oArea, vector vPosition, float fOrientation);

// Apply eEffect at lLocation.
void ApplyEffectAtLocation(int nDurationType, effect eEffect, location lLocation, float fDuration=0.0f);

// * Returns TRUE if oCreature is a Player Controlled character.
int GetIsPC(object oCreature);

// Convert fFeet into a number of meters.
float FeetToMeters(float fFeet);

// Convert fYards into a number of meters.
float YardsToMeters(float fYards);

// Apply eEffect to oTarget.
void ApplyEffectToObject(int nDurationType, effect eEffect, object oTarget, float fDuration=0.0f);

// The caller will immediately speak sStringToSpeak (this is different from
// ActionSpeakString)
// - sStringToSpeak
// - nTalkVolume: TALKVOLUME_*
void SpeakString(string sStringToSpeak, int nTalkVolume=TALKVOLUME_TALK);

// Get the location of the caller's last spell target.
location GetSpellTargetLocation();

// Get the position vector from lLocation.
vector GetPositionFromLocation(location lLocation);

// Get the area's object ID from lLocation.
object GetAreaFromLocation(location lLocation);

// Get the orientation value from lLocation.
float GetFacingFromLocation(location lLocation);

// Get the creature nearest to lLocation, subject to all the criteria specified.
// - nFirstCriteriaType: CREATURE_TYPE_*
// - nFirstCriteriaValue:
//   -> CLASS_TYPE_* if nFirstCriteriaType was CREATURE_TYPE_CLASS
//   -> SPELL_* if nFirstCriteriaType was CREATURE_TYPE_DOES_NOT_HAVE_SPELL_EFFECT
//      or CREATURE_TYPE_HAS_SPELL_EFFECT
//   -> TRUE or FALSE if nFirstCriteriaType was CREATURE_TYPE_IS_ALIVE
//   -> PERCEPTION_* if nFirstCriteriaType was CREATURE_TYPE_PERCEPTION
//   -> PLAYER_CHAR_IS_PC or PLAYER_CHAR_NOT_PC if nFirstCriteriaType was
//      CREATURE_TYPE_PLAYER_CHAR
//   -> RACIAL_TYPE_* if nFirstCriteriaType was CREATURE_TYPE_RACIAL_TYPE
//   -> REPUTATION_TYPE_* if nFirstCriteriaType was CREATURE_TYPE_REPUTATION
//   For example, to get the nearest PC, use
//   (CREATURE_TYPE_PLAYER_CHAR, PLAYER_CHAR_IS_PC)
// - lLocation: We're trying to find the creature of the specified type that is
//   nearest to lLocation
// - nNth: We don't have to find the first nearest: we can find the Nth nearest....
// - nSecondCriteriaType: This is used in the same way as nFirstCriteriaType to
//   further specify the type of creature that we are looking for.
// - nSecondCriteriaValue: This is used in the same way as nFirstCriteriaValue
//   to further specify the type of creature that we are looking for.
// - nThirdCriteriaType: This is used in the same way as nFirstCriteriaType to
//   further specify the type of creature that we are looking for.
// - nThirdCriteriaValue: This is used in the same way as nFirstCriteriaValue to
//   further specify the type of creature that we are looking for.
// * Return value on error: OBJECT_INVALID
object GetNearestCreatureToLocation(int nFirstCriteriaType, int nFirstCriteriaValue,  location lLocation, int nNth=1, int nSecondCriteriaType=-1, int nSecondCriteriaValue=-1, int nThirdCriteriaType=-1,  int nThirdCriteriaValue=-1 );

// Get the Nth object nearest to oTarget that is of the specified type.
// - nObjectType: OBJECT_TYPE_*
// - oTarget
// - nNth
// * Return value on error: OBJECT_INVALID
object GetNearestObject(int nObjectType=OBJECT_TYPE_ALL, object oTarget=OBJECT_SELF, int nNth=1);

// Get the nNth object nearest to lLocation that is of the specified type.
// - nObjectType: OBJECT_TYPE_*
// - lLocation
// - nNth
// * Return value on error: OBJECT_INVALID
object GetNearestObjectToLocation(int nObjectType, location lLocation, int nNth=1);

// Get the nth Object nearest to oTarget that has sTag as its tag.
// * Return value on error: OBJECT_INVALID
object GetNearestObjectByTag(string sTag, object oTarget=OBJECT_SELF, int nNth=1);

// Convert nInteger into a floating point number.
float IntToFloat(int nInteger);

// Convert fFloat into the nearest integer.
int FloatToInt(float fFloat);

// Convert sNumber into an integer.
int StringToInt(string sNumber);

// Convert sNumber into a floating point number.
float StringToFloat(string sNumber);

// Cast spell nSpell at lTargetLocation.
// - nSpell: SPELL_*
// - lTargetLocation
// - nMetaMagic: METAMAGIC_*
// - bCheat: If this is TRUE, then the executor of the action doesn't have to be
//   able to cast the spell.
// - nProjectilePathType: PROJECTILE_PATH_TYPE_*
// - bInstantSpell: If this is TRUE, the spell is cast immediately; this allows
//   the end-user to simulate
//   a high-level magic user having lots of advance warning of impending trouble.
void   ActionCastSpellAtLocation(int nSpell, location lTargetLocation, int nMetaMagic=METAMAGIC_ANY, int bCheat=FALSE, int nProjectilePathType=PROJECTILE_PATH_TYPE_DEFAULT, int bInstantSpell=FALSE);

// * Returns TRUE if oSource considers oTarget as an enemy.
int GetIsEnemy(object oTarget, object oSource=OBJECT_SELF);

// * Returns TRUE if oSource considers oTarget as a friend.
int GetIsFriend(object oTarget, object oSource=OBJECT_SELF);

// * Returns TRUE if oSource considers oTarget as neutral.
int GetIsNeutral(object oTarget, object oSource=OBJECT_SELF);

// Get the PC that is involved in the conversation.
// * Returns OBJECT_INVALID on error.
object GetPCSpeaker();

// Get a string from the talk table using nStrRef.
string GetStringByStrRef(int nStrRef, int nGender=GENDER_MALE);

// Causes the creature to speak a translated string.
// - nStrRef: Reference of the string in the talk table
// - nTalkVolume: TALKVOLUME_*
void ActionSpeakStringByStrRef(int nStrRef, int nTalkVolume=TALKVOLUME_TALK);

// Destroy oObject (irrevocably).
// This will not work on modules and areas.
void DestroyObject(object oDestroy, float fDelay=0.0f);

// Get the module.
// * Return value on error: OBJECT_INVALID
object GetModule();

// Create an object of the specified type at lLocation.
// - nObjectType: OBJECT_TYPE_ITEM, OBJECT_TYPE_CREATURE, OBJECT_TYPE_PLACEABLE,
//   OBJECT_TYPE_STORE, OBJECT_TYPE_WAYPOINT
// - sTemplate
// - lLocation
// - bUseAppearAnimation
// - sNewTag - if this string is not empty, it will replace the default tag from the template
object CreateObject(int nObjectType, string sTemplate, location lLocation, int bUseAppearAnimation=FALSE, string sNewTag="");

// Create an event which triggers the "SpellCastAt" script
// Note: This only creates the event. The event wont actually trigger until SignalEvent()
// is called using this created SpellCastAt event as an argument.
// For example:
//     SignalEvent(oCreature, EventSpellCastAt(oCaster, SPELL_MAGIC_MISSILE, TRUE));
// This function doesn't cast the spell specified, it only creates an event so that
// when the event is signaled on an object, the object will use its OnSpellCastAt script
// to react to the spell being cast.
//
// To specify the OnSpellCastAt script that should run, view the Object's Properties 
// and click on the Scripts Tab. Then specify a script for the OnSpellCastAt event.
// From inside the OnSpellCastAt script call:
//     GetLastSpellCaster() to get the object that cast the spell (oCaster).
//     GetLastSpell() to get the type of spell cast (nSpell)
//     GetLastSpellHarmful() to determine if the spell cast at the object was harmful.
event EventSpellCastAt(object oCaster, int nSpell, int bHarmful=TRUE);

// This is for use in a "Spell Cast" script, it gets who cast the spell.
// The spell could have been cast by a creature, placeable or door.
// * Returns OBJECT_INVALID if the caller is not a creature, placeable or door.
object GetLastSpellCaster();

// This is for use in a "Spell Cast" script, it gets the ID of the spell that
// was cast.
int GetLastSpell();

// This is for use in a user-defined script, it gets the event number.
int GetUserDefinedEventNumber();

// This is for use in a Spell script, it gets the ID of the spell that is being
// cast (SPELL_*).
int GetSpellId();

// Generate a random name.
// nNameType: The type of random name to be generated (NAME_*)
string RandomName(int nNameType=NAME_FIRST_GENERIC_MALE);

// Create a Poison effect.
// - nPoisonType: POISON_*
effect EffectPoison(int nPoisonType);

// Create a Disease effect.
// - nDiseaseType: DISEASE_*
effect EffectDisease(int nDiseaseType);

// Create a Silence effect.
effect EffectSilence();

// Get the name of oObject.
// - bOriginalName:  if set to true any new name specified via a SetName scripting command
//                   is ignored and the original object's name is returned instead.
string GetName(object oObject, int bOriginalName=FALSE);

// Use this in a conversation script to get the person with whom you are conversing.
// * Returns OBJECT_INVALID if the caller is not a valid creature.
object GetLastSpeaker();

// Use this in an OnDialog script to start up the dialog tree.
// - sResRef: if this is not specified, the default dialog file will be used
// - oObjectToDialog: if this is not specified the person that triggered the
//   event will be used
int BeginConversation(string sResRef="", object oObjectToDialog=OBJECT_INVALID);

// Use this in an OnPerception script to get the object that was perceived.
// * Returns OBJECT_INVALID if the caller is not a valid creature.
object GetLastPerceived();

// Use this in an OnPerception script to determine whether the object that was
// perceived was heard.
int GetLastPerceptionHeard();

// Use this in an OnPerception script to determine whether the object that was
// perceived has become inaudible.
int GetLastPerceptionInaudible();

// Use this in an OnPerception script to determine whether the object that was
// perceived was seen.
int GetLastPerceptionSeen();

// Use this in an OnClosed script to get the object that closed the door or placeable.
// * Returns OBJECT_INVALID if the caller is not a valid door or placeable.
object GetLastClosedBy();

// Use this in an OnPerception script to determine whether the object that was
// perceived has vanished.
int GetLastPerceptionVanished();

// Get the first object within oPersistentObject.
// - oPersistentObject
// - nResidentObjectType: OBJECT_TYPE_*
// - nPersistentZone: PERSISTENT_ZONE_ACTIVE. [This could also take the value
//   PERSISTENT_ZONE_FOLLOW, but this is no longer used.]
// * Returns OBJECT_INVALID if no object is found.
object GetFirstInPersistentObject(object oPersistentObject=OBJECT_SELF, int nResidentObjectType=OBJECT_TYPE_CREATURE, int nPersistentZone=PERSISTENT_ZONE_ACTIVE);

// Get the next object within oPersistentObject.
// - oPersistentObject
// - nResidentObjectType: OBJECT_TYPE_*
// - nPersistentZone: PERSISTENT_ZONE_ACTIVE. [This could also take the value
//   PERSISTENT_ZONE_FOLLOW, but this is no longer used.]
// * Returns OBJECT_INVALID if no object is found.
object GetNextInPersistentObject(object oPersistentObject=OBJECT_SELF, int nResidentObjectType=OBJECT_TYPE_CREATURE, int nPersistentZone=PERSISTENT_ZONE_ACTIVE);

// This returns the creator of oAreaOfEffectObject.
// * Returns OBJECT_INVALID if oAreaOfEffectObject is not a valid Area of Effect object.
object GetAreaOfEffectCreator(object oAreaOfEffectObject=OBJECT_SELF);

// Delete oObject's local integer variable sVarName
void DeleteLocalInt(object oObject, string sVarName);

// Delete oObject's local float variable sVarName
void DeleteLocalFloat(object oObject, string sVarName);

// Delete oObject's local string variable sVarName
void DeleteLocalString(object oObject, string sVarName);

// Delete oObject's local object variable sVarName
void DeleteLocalObject(object oObject, string sVarName);

// Delete oObject's local location variable sVarName
void DeleteLocalLocation(object oObject, string sVarName);

// Create a Haste effect.
effect EffectHaste();

// Create a Slow effect.
effect EffectSlow();

// Convert oObject into a hexadecimal string.
string ObjectToString(object oObject);

// Create an Immunity effect.
// - nImmunityType: IMMUNITY_TYPE_*
effect EffectImmunity(int nImmunityType);

// - oCreature
// - nImmunityType: IMMUNITY_TYPE_*
// - oVersus: if this is specified, then we also check for the race and
//   alignment of oVersus
// * Returns TRUE if oCreature has immunity of type nImmunity versus oVersus.
int GetIsImmune(object oCreature, int nImmunityType, object oVersus=OBJECT_INVALID);

// Creates a Damage Immunity Increase effect.
// - nDamageType: DAMAGE_TYPE_*
// - nPercentImmunity
effect EffectDamageImmunityIncrease(int nDamageType, int nPercentImmunity);

// Determine whether oEncounter is active.
int  GetEncounterActive(object oEncounter=OBJECT_SELF);

// Set oEncounter's active state to nNewValue.
// - nNewValue: TRUE/FALSE
// - oEncounter
void SetEncounterActive(int nNewValue, object oEncounter=OBJECT_SELF);

// Get the maximum number of times that oEncounter will spawn.
int GetEncounterSpawnsMax(object oEncounter=OBJECT_SELF);

// Set the maximum number of times that oEncounter can spawn
void SetEncounterSpawnsMax(int nNewValue, object oEncounter=OBJECT_SELF);

// Get the number of times that oEncounter has spawned so far
int  GetEncounterSpawnsCurrent(object oEncounter=OBJECT_SELF);

// Set the number of times that oEncounter has spawned so far
void SetEncounterSpawnsCurrent(int nNewValue, object oEncounter=OBJECT_SELF);

// Use this in an OnItemAcquired script to get the item that was acquired.
// * Returns OBJECT_INVALID if the module is not valid.
object GetModuleItemAcquired();

// Use this in an OnItemAcquired script to get the creatre that previously
// possessed the item.
// * Returns OBJECT_INVALID if the item was picked up from the ground.
object GetModuleItemAcquiredFrom();

// Set the value for a custom token.
void SetCustomToken(int nCustomTokenNumber, string sTokenValue);

// Determine whether oCreature has nFeat, and nFeat is useable.
// - nFeat: FEAT_*
// - oCreature
int GetHasFeat(int nFeat, object oCreature=OBJECT_SELF);

// Determine whether oCreature has nSkill, and nSkill is useable.
// - nSkill: SKILL_*
// - oCreature
int GetHasSkill(int nSkill, object oCreature=OBJECT_SELF);

// Use nFeat on oTarget.
// - nFeat: FEAT_*
// - oTarget
void ActionUseFeat(int nFeat, object oTarget);

// Runs the action "UseSkill" on the current creature
// Use nSkill on oTarget.
// - nSkill: SKILL_*
// - oTarget
// - nSubSkill: SUBSKILL_*
// - oItemUsed: Item to use in conjunction with the skill
void ActionUseSkill(int nSkill, object oTarget, int nSubSkill=0, object oItemUsed=OBJECT_INVALID );

// Determine whether oSource sees oTarget.
// NOTE: This *only* works on creatures, as visibility lists are not
//       maintained for non-creature objects.
int GetObjectSeen(object oTarget, object oSource=OBJECT_SELF);

// Determine whether oSource hears oTarget.
// NOTE: This *only* works on creatures, as visibility lists are not
//       maintained for non-creature objects.
int GetObjectHeard(object oTarget, object oSource=OBJECT_SELF);

// Use this in an OnPlayerDeath module script to get the last player that died.
object GetLastPlayerDied();

// Use this in an OnItemLost script to get the item that was lost/dropped.
// * Returns OBJECT_INVALID if the module is not valid.
object GetModuleItemLost();

// Use this in an OnItemLost script to get the creature that lost the item.
// * Returns OBJECT_INVALID if the module is not valid.
object GetModuleItemLostBy();

// Do aActionToDo.
void ActionDoCommand(action aActionToDo);

// Creates a conversation event.
// Note: This only creates the event. The event wont actually trigger until SignalEvent()
// is called using this created conversation event as an argument.
// For example:
//     SignalEvent(oCreature, EventConversation());
// Once the event has been signaled. The script associated with the OnConversation event will
// run on the creature oCreature.
//
// To specify the OnConversation script that should run, view the Creature Properties on
// the creature and click on the Scripts Tab. Then specify a script for the OnConversation event.
event EventConversation();

// Set the difficulty level of oEncounter.
// - nEncounterDifficulty: ENCOUNTER_DIFFICULTY_*
// - oEncounter
void SetEncounterDifficulty(int nEncounterDifficulty, object oEncounter=OBJECT_SELF);

// Get the difficulty level of oEncounter.
int GetEncounterDifficulty(object oEncounter=OBJECT_SELF);

// Get the distance between lLocationA and lLocationB.
float GetDistanceBetweenLocations(location lLocationA, location lLocationB);

// Use this in spell scripts to get nDamage adjusted by oTarget's reflex and
// evasion saves.
// - nDamage
// - oTarget
// - nDC: Difficulty check
// - nSaveType: SAVING_THROW_TYPE_*
// - oSaveVersus
int GetReflexAdjustedDamage(int nDamage, object oTarget, int nDC, int nSaveType=SAVING_THROW_TYPE_NONE, object oSaveVersus=OBJECT_SELF);

// Play nAnimation immediately.
// - nAnimation: ANIMATION_*
// - fSpeed
// - fSeconds
void PlayAnimation(int nAnimation, float fSpeed=1.0, float fSeconds=0.0);

// Create a Spell Talent.
// - nSpell: SPELL_*
talent TalentSpell(int nSpell);

// Create a Feat Talent.
// - nFeat: FEAT_*
talent TalentFeat(int nFeat);

// Create a Skill Talent.
// - nSkill: SKILL_*
talent TalentSkill(int nSkill);

// Determines whether oObject has any effects applied by nSpell
// - nSpell: SPELL_*
// - oObject
// * The spell id on effects is only valid if the effect is created
//   when the spell script runs. If it is created in a delayed command
//   then the spell id on the effect will be invalid.
int GetHasSpellEffect(int nSpell, object oObject=OBJECT_SELF);

// Get the spell (SPELL_*) that applied eSpellEffect.
// * Returns -1 if eSpellEffect was applied outside a spell script.
int GetEffectSpellId(effect eSpellEffect);

// Determine whether oCreature has tTalent.
int GetCreatureHasTalent(talent tTalent, object oCreature=OBJECT_SELF);

// Get a random talent of oCreature, within nCategory.
// - nCategory: TALENT_CATEGORY_*
// - oCreature
talent GetCreatureTalentRandom(int nCategory, object oCreature=OBJECT_SELF);

// Get the best talent (i.e. closest to nCRMax without going over) of oCreature,
// within nCategory.
// - nCategory: TALENT_CATEGORY_*
// - nCRMax: Challenge Rating of the talent
// - oCreature
talent GetCreatureTalentBest(int nCategory, int nCRMax, object oCreature=OBJECT_SELF);

// Use tChosenTalent on oTarget.
void ActionUseTalentOnObject(talent tChosenTalent, object oTarget);

// Use tChosenTalent at lTargetLocation.
void ActionUseTalentAtLocation(talent tChosenTalent, location lTargetLocation);

// Get the gold piece value of oItem.
// * Returns 0 if oItem is not a valid item.
int GetGoldPieceValue(object oItem);

// * Returns TRUE if oCreature is of a playable racial type.
int GetIsPlayableRacialType(object oCreature);

// Jump to lDestination.  The action is added to the TOP of the action queue.
void JumpToLocation(location lDestination);

// Create a Temporary Hitpoints effect.
// - nHitPoints: a positive integer
// * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nHitPoints < 0.
effect EffectTemporaryHitpoints(int nHitPoints);

// Get the number of ranks that oTarget has in nSkill.
// - nSkill: SKILL_*
// - oTarget
// - nBaseSkillRank: if set to true returns the number of base skill ranks the target
//                   has (i.e. not including any bonuses from ability scores, feats, etc).
// * Returns -1 if oTarget doesn't have nSkill.
// * Returns 0 if nSkill is untrained.
int GetSkillRank(int nSkill, object oTarget=OBJECT_SELF, int nBaseSkillRank=FALSE);

// Get the attack target of oCreature.
// This only works when oCreature is in combat.
object GetAttackTarget(object oCreature=OBJECT_SELF);

// Get the attack type (SPECIAL_ATTACK_*) of oCreature's last attack.
// This only works when oCreature is in combat.
int GetLastAttackType(object oCreature=OBJECT_SELF);

// Get the attack mode (COMBAT_MODE_*) of oCreature's last attack.
// This only works when oCreature is in combat.
int GetLastAttackMode(object oCreature=OBJECT_SELF);

// Get the master of oAssociate.
object GetMaster(object oAssociate=OBJECT_SELF);

// * Returns TRUE if oCreature is in combat.
int GetIsInCombat(object oCreature=OBJECT_SELF);

// Get the last command (ASSOCIATE_COMMAND_*) issued to oAssociate.
int GetLastAssociateCommand(object oAssociate=OBJECT_SELF);

// Give nGP gold to oCreature.
void GiveGoldToCreature(object oCreature, int nGP);

// Set the destroyable status of the caller.
// - bDestroyable: If this is FALSE, the caller does not fade out on death, but
//   sticks around as a corpse.
// - bRaiseable: If this is TRUE, the caller can be raised via resurrection.
// - bSelectableWhenDead: If this is TRUE, the caller is selectable after death.
void SetIsDestroyable(int bDestroyable, int bRaiseable=TRUE, int bSelectableWhenDead=FALSE);

// Set the locked state of oTarget, which can be a door or a placeable object.
void SetLocked(object oTarget, int bLocked);

// Get the locked state of oTarget, which can be a door or a placeable object.
int GetLocked(object oTarget);

// Use this in a trigger's OnClick event script to get the object that last
// clicked on it.
// This is identical to GetEnteringObject.
// GetClickingObject() should not be called from a placeable's OnClick event,
// instead use GetPlaceableLastClickedBy();
object GetClickingObject();

// Initialise oTarget to listen for the standard Associates commands.
void SetAssociateListenPatterns(object oTarget=OBJECT_SELF);

// Get the last weapon that oCreature used in an attack.
// * Returns OBJECT_INVALID if oCreature did not attack, or has no weapon equipped.
object GetLastWeaponUsed(object oCreature);

// Use oPlaceable.
void ActionInteractObject(object oPlaceable);

// Get the last object that used the placeable object that is calling this function.
// * Returns OBJECT_INVALID if it is called by something other than a placeable or
//   a door.
object GetLastUsedBy();

// Returns the ability modifier for the specified ability
// Get oCreature's ability modifier for nAbility.
// - nAbility: ABILITY_*
// - oCreature
int GetAbilityModifier(int nAbility, object oCreature=OBJECT_SELF);

// Determined whether oItem has been identified.
int GetIdentified(object oItem);

// Set whether oItem has been identified.
void SetIdentified(object oItem, int bIdentified);

// Summon an Animal Companion
void SummonAnimalCompanion(object oMaster=OBJECT_SELF);

// Summon a Familiar
void SummonFamiliar(object oMaster=OBJECT_SELF);

// Get the last blocking door encountered by the caller of this function.
// * Returns OBJECT_INVALID if the caller is not a valid creature.
object GetBlockingDoor();

// - oTargetDoor
// - nDoorAction: DOOR_ACTION_*
// * Returns TRUE if nDoorAction can be performed on oTargetDoor.
int GetIsDoorActionPossible(object oTargetDoor, int nDoorAction);

// Perform nDoorAction on oTargetDoor.
void DoDoorAction(object oTargetDoor, int nDoorAction);

// Get the first item in oTarget's inventory (start to cycle through oTarget's
// inventory).
// * Returns OBJECT_INVALID if the caller is not a creature, item, placeable or store,
//   or if no item is found.
object GetFirstItemInInventory(object oTarget=OBJECT_SELF);

// Get the next item in oTarget's inventory (continue to cycle through oTarget's
// inventory).
// * Returns OBJECT_INVALID if the caller is not a creature, item, placeable or store,
//   or if no item is found.
object GetNextItemInInventory(object oTarget=OBJECT_SELF);

// A creature can have up to three classes.  This function determines the
// creature's class (CLASS_TYPE_*) based on nClassPosition.
// - nClassPosition: 1, 2 or 3
// - oCreature
// * Returns CLASS_TYPE_INVALID if the oCreature does not have a class in
//   nClassPosition (i.e. a single-class creature will only have a value in
//   nClassLocation=1) or if oCreature is not a valid creature.
int GetClassByPosition(int nClassPosition, object oCreature=OBJECT_SELF);

// A creature can have up to three classes.  This function determines the
// creature's class level based on nClass Position.
// - nClassPosition: 1, 2 or 3
// - oCreature
// * Returns 0 if oCreature does not have a class in nClassPosition
//   (i.e. a single-class creature will only have a value in nClassLocation=1)
//   or if oCreature is not a valid creature.
int GetLevelByPosition(int nClassPosition, object oCreature=OBJECT_SELF);

// Determine the levels that oCreature holds in nClassType.
// - nClassType: CLASS_TYPE_*
// - oCreature
int GetLevelByClass(int nClassType, object oCreature=OBJECT_SELF);

// Get the amount of damage of type nDamageType that has been dealt to the caller.
// - nDamageType: DAMAGE_TYPE_*
int GetDamageDealtByType(int nDamageType);

// Get the total amount of damage that has been dealt to the caller.
int GetTotalDamageDealt();

// Get the last object that damaged oObject
// * Returns OBJECT_INVALID if the passed in object is not a valid object.
object GetLastDamager(object oObject=OBJECT_SELF);

// Get the last object that disarmed the trap on the caller.
// * Returns OBJECT_INVALID if the caller is not a valid placeable, trigger or
//   door.
object GetLastDisarmed();

// Get the last object that disturbed the inventory of the caller.
// * Returns OBJECT_INVALID if the caller is not a valid creature or placeable.
object GetLastDisturbed();

// Get the last object that locked the caller.
// * Returns OBJECT_INVALID if the caller is not a valid door or placeable.
object GetLastLocked();

// Get the last object that unlocked the caller.
// * Returns OBJECT_INVALID if the caller is not a valid door or placeable.
object GetLastUnlocked();

// Create a Skill Increase effect.
// - nSkill: SKILL_*
// - nValue
// * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nSkill is invalid.
effect EffectSkillIncrease(int nSkill, int nValue);

// Get the type of disturbance (INVENTORY_DISTURB_*) that caused the caller's
// OnInventoryDisturbed script to fire.  This will only work for creatures and
// placeables.
int GetInventoryDisturbType();

// get the item that caused the caller's OnInventoryDisturbed script to fire.
// * Returns OBJECT_INVALID if the caller is not a valid object.
object GetInventoryDisturbItem();

// Get the henchman belonging to oMaster.
// * Return OBJECT_INVALID if oMaster does not have a henchman.
// -nNth: Which henchman to return.
object GetHenchman(object oMaster=OBJECT_SELF,int nNth=1);

// Set eEffect to be versus a specific alignment.
// - eEffect
// - nLawChaos: ALIGNMENT_LAWFUL/ALIGNMENT_CHAOTIC/ALIGNMENT_ALL
// - nGoodEvil: ALIGNMENT_GOOD/ALIGNMENT_EVIL/ALIGNMENT_ALL
effect VersusAlignmentEffect(effect eEffect, int nLawChaos=ALIGNMENT_ALL, int nGoodEvil=ALIGNMENT_ALL);

// Set eEffect to be versus nRacialType.
// - eEffect
// - nRacialType: RACIAL_TYPE_*
effect VersusRacialTypeEffect(effect eEffect, int nRacialType);

// Set eEffect to be versus traps.
effect VersusTrapEffect(effect eEffect);

// Get the gender of oCreature.
int GetGender(object oCreature);

// * Returns TRUE if tTalent is valid.
int GetIsTalentValid(talent tTalent);

// Causes the action subject to move away from lMoveAwayFrom.
void ActionMoveAwayFromLocation(location lMoveAwayFrom, int bRun=FALSE, float fMoveAwayRange=40.0f);

// Get the target that the caller attempted to attack - this should be used in
// conjunction with GetAttackTarget(). This value is set every time an attack is
// made, and is reset at the end of combat.
// * Returns OBJECT_INVALID if the caller is not a valid creature.
object GetAttemptedAttackTarget();

// Get the type (TALENT_TYPE_*) of tTalent.
int GetTypeFromTalent(talent tTalent);

// Get the ID of tTalent.  This could be a SPELL_*, FEAT_* or SKILL_*.
int GetIdFromTalent(talent tTalent);

// Get the associate of type nAssociateType belonging to oMaster.
// - nAssociateType: ASSOCIATE_TYPE_*
// - nMaster
// - nTh: Which associate of the specified type to return
// * Returns OBJECT_INVALID if no such associate exists.
object GetAssociate(int nAssociateType, object oMaster=OBJECT_SELF, int nTh=1);

// Add oHenchman as a henchman to oMaster
// If oHenchman is either a DM or a player character, this will have no effect.
void AddHenchman(object oMaster, object oHenchman=OBJECT_SELF);

// Remove oHenchman from the service of oMaster, returning them to their original faction.
void RemoveHenchman(object oMaster, object oHenchman=OBJECT_SELF);

// Add a journal quest entry to oCreature.
// - szPlotID: the plot identifier used in the toolset's Journal Editor
// - nState: the state of the plot as seen in the toolset's Journal Editor
// - oCreature
// - bAllPartyMembers: If this is TRUE, the entry will show up in the journal of
//   everyone in the party
// - bAllPlayers: If this is TRUE, the entry will show up in the journal of
//   everyone in the world
// - bAllowOverrideHigher: If this is TRUE, you can set the state to a lower
//   number than the one it is currently on
void AddJournalQuestEntry(string szPlotID, int nState, object oCreature, int bAllPartyMembers=TRUE, int bAllPlayers=FALSE, int bAllowOverrideHigher=FALSE);

// Remove a journal quest entry from oCreature.
// - szPlotID: the plot identifier used in the toolset's Journal Editor
// - oCreature
// - bAllPartyMembers: If this is TRUE, the entry will be removed from the
//   journal of everyone in the party
// - bAllPlayers: If this is TRUE, the entry will be removed from the journal of
//   everyone in the world
void RemoveJournalQuestEntry(string szPlotID, object oCreature, int bAllPartyMembers=TRUE, int bAllPlayers=FALSE);

// Get the public part of the CD Key that oPlayer used when logging in.
// - nSinglePlayerCDKey: If set to TRUE, the player's public CD Key will 
//   be returned when the player is playing in single player mode 
//   (otherwise returns an empty string in single player mode).
string GetPCPublicCDKey(object oPlayer, int nSinglePlayerCDKey=FALSE);

// Get the IP address from which oPlayer has connected.
string GetPCIPAddress(object oPlayer);

// Get the name of oPlayer.
string GetPCPlayerName(object oPlayer);

// Sets oPlayer and oTarget to like each other.
void SetPCLike(object oPlayer, object oTarget);

// Sets oPlayer and oTarget to dislike each other.
void SetPCDislike(object oPlayer, object oTarget);

// Send a server message (szMessage) to the oPlayer.
void SendMessageToPC(object oPlayer, string szMessage);

// Get the target at which the caller attempted to cast a spell.
// This value is set every time a spell is cast and is reset at the end of
// combat.
// * Returns OBJECT_INVALID if the caller is not a valid creature.
object GetAttemptedSpellTarget();

// Get the last creature that opened the caller.
// * Returns OBJECT_INVALID if the caller is not a valid door, placeable or store.
object GetLastOpenedBy();

// Determines the number of times that oCreature has nSpell memorised.
// - nSpell: SPELL_*
// - oCreature
int GetHasSpell(int nSpell, object oCreature=OBJECT_SELF);

// Open oStore for oPC.
// - nBonusMarkUp is added to the stores default mark up percentage on items sold (-100 to 100)
// - nBonusMarkDown is added to the stores default mark down percentage on items bought (-100 to 100)
void OpenStore(object oStore, object oPC, int nBonusMarkUp=0, int nBonusMarkDown=0);

// Create a Turned effect.
// Turned effects are supernatural by default.
effect EffectTurned();

// Get the first member of oMemberOfFaction's faction (start to cycle through
// oMemberOfFaction's faction).
// * Returns OBJECT_INVALID if oMemberOfFaction's faction is invalid.
object GetFirstFactionMember(object oMemberOfFaction, int bPCOnly=TRUE);

// Get the next member of oMemberOfFaction's faction (continue to cycle through
// oMemberOfFaction's faction).
// * Returns OBJECT_INVALID if oMemberOfFaction's faction is invalid.
object GetNextFactionMember(object oMemberOfFaction, int bPCOnly=TRUE);

// Force the action subject to move to lDestination.
void ActionForceMoveToLocation(location lDestination, int bRun=FALSE, float fTimeout=30.0f);

// Force the action subject to move to oMoveTo.
void ActionForceMoveToObject(object oMoveTo, int bRun=FALSE, float fRange=1.0f, float fTimeout=30.0f);

// Get the experience assigned in the journal editor for szPlotID.
int GetJournalQuestExperience(string szPlotID);

// Jump to oToJumpTo (the action is added to the top of the action queue).
void JumpToObject(object oToJumpTo, int nWalkStraightLineToPoint=1);

// Set whether oMapPin is enabled.
// - oMapPin
// - nEnabled: 0=Off, 1=On
void SetMapPinEnabled(object oMapPin, int nEnabled);

// Create a Hit Point Change When Dying effect.
// - fHitPointChangePerRound: this can be positive or negative, but not zero.
// * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if fHitPointChangePerRound is 0.
effect EffectHitPointChangeWhenDying(float fHitPointChangePerRound);

// Spawn a GUI panel for the client that controls oPC.
// - oPC
// - nGUIPanel: GUI_PANEL_*
// * Nothing happens if oPC is not a player character or if an invalid value is
//   used for nGUIPanel.
void PopUpGUIPanel(object oPC, int nGUIPanel);

// Clear all personal feelings that oSource has about oTarget.
void ClearPersonalReputation(object oTarget, object oSource=OBJECT_SELF);

// oSource will temporarily be friends towards oTarget.
// bDecays determines whether the personal reputation value decays over time
// fDurationInSeconds is the length of time that the temporary friendship lasts
// Make oSource into a temporary friend of oTarget using personal reputation.
// - oTarget
// - oSource
// - bDecays: If this is TRUE, the friendship decays over fDurationInSeconds;
//   otherwise it is indefinite.
// - fDurationInSeconds: This is only used if bDecays is TRUE, it is how long
//   the friendship lasts.
// Note: If bDecays is TRUE, the personal reputation amount decreases in size
// over fDurationInSeconds. Friendship will only be in effect as long as
// (faction reputation + total personal reputation) >= REPUTATION_TYPE_FRIEND.
void SetIsTemporaryFriend(object oTarget, object oSource=OBJECT_SELF, int bDecays=FALSE, float fDurationInSeconds=180.0f);

// Make oSource into a temporary enemy of oTarget using personal reputation.
// - oTarget
// - oSource
// - bDecays: If this is TRUE, the enmity decays over fDurationInSeconds;
//   otherwise it is indefinite.
// - fDurationInSeconds: This is only used if bDecays is TRUE, it is how long
//   the enmity lasts.
// Note: If bDecays is TRUE, the personal reputation amount decreases in size
// over fDurationInSeconds. Enmity will only be in effect as long as
// (faction reputation + total personal reputation) <= REPUTATION_TYPE_ENEMY.
void SetIsTemporaryEnemy(object oTarget, object oSource=OBJECT_SELF, int bDecays=FALSE, float fDurationInSeconds=180.0f);

// Make oSource temporarily neutral to oTarget using personal reputation.
// - oTarget
// - oSource
// - bDecays: If this is TRUE, the neutrality decays over fDurationInSeconds;
//   otherwise it is indefinite.
// - fDurationInSeconds: This is only used if bDecays is TRUE, it is how long
//   the neutrality lasts.
// Note: If bDecays is TRUE, the personal reputation amount decreases in size
// over fDurationInSeconds. Neutrality will only be in effect as long as
// (faction reputation + total personal reputation) > REPUTATION_TYPE_ENEMY and
// (faction reputation + total personal reputation) < REPUTATION_TYPE_FRIEND.
void SetIsTemporaryNeutral(object oTarget, object oSource=OBJECT_SELF, int bDecays=FALSE, float fDurationInSeconds=180.0f);

// Gives nXpAmount to oCreature.
void GiveXPToCreature(object oCreature, int nXpAmount);

// Sets oCreature's experience to nXpAmount.
void SetXP(object oCreature, int nXpAmount);

// Get oCreature's experience.
int GetXP(object oCreature);

// Convert nInteger to hex, returning the hex value as a string.
// * Return value has the format "0x????????" where each ? will be a hex digit
//   (8 digits in total).
string IntToHexString(int nInteger);

// Get the base item type (BASE_ITEM_*) of oItem.
// * Returns BASE_ITEM_INVALID if oItem is an invalid item.
int GetBaseItemType(object oItem);

// Determines whether oItem has nProperty.
// - oItem
// - nProperty: ITEM_PROPERTY_*
// * Returns FALSE if oItem is not a valid item, or if oItem does not have
//   nProperty.
int GetItemHasItemProperty(object oItem, int nProperty);

// The creature will equip the melee weapon in its possession that can do the
// most damage. If no valid melee weapon is found, it will equip the most
// damaging range weapon. This function should only ever be called in the
// EndOfCombatRound scripts, because otherwise it would have to stop the combat
// round to run simulation.
// - oVersus: You can try to get the most damaging weapon against oVersus
// - bOffHand
void ActionEquipMostDamagingMelee(object oVersus=OBJECT_INVALID, int bOffHand=FALSE);

// The creature will equip the range weapon in its possession that can do the
// most damage.
// If no valid range weapon can be found, it will equip the most damaging melee
// weapon.
// - oVersus: You can try to get the most damaging weapon against oVersus
void ActionEquipMostDamagingRanged(object oVersus=OBJECT_INVALID);

// Get the Armour Class of oItem.
// * Return 0 if the oItem is not a valid item, or if oItem has no armour value.
int GetItemACValue(object oItem);

// The creature will rest if not in combat and no enemies are nearby.
// - bCreatureToEnemyLineOfSightCheck: TRUE to allow the creature to rest if enemies
//                                     are nearby, but the creature can't see the enemy.
//                                     FALSE the creature will not rest if enemies are
//                                     nearby regardless of whether or not the creature
//                                     can see them, such as if an enemy is close by,
//                                     but is in a different room behind a closed door.
void ActionRest(int bCreatureToEnemyLineOfSightCheck=FALSE);

// Expose/Hide the entire map of oArea for oPlayer.
// - oArea: The area that the map will be exposed/hidden for.
// - oPlayer: The player the map will be exposed/hidden for.
// - bExplored: TRUE/FALSE. Whether the map should be completely explored or hidden.
void ExploreAreaForPlayer(object oArea, object oPlayer, int bExplored=TRUE);

// The creature will equip the armour in its possession that has the highest
// armour class.
void ActionEquipMostEffectiveArmor();

// * Returns TRUE if it is currently day.
int GetIsDay();

// * Returns TRUE if it is currently night.
int GetIsNight();

// * Returns TRUE if it is currently dawn.
int GetIsDawn();

// * Returns TRUE if it is currently dusk.
int GetIsDusk();

// * Returns TRUE if oCreature was spawned from an encounter.
int GetIsEncounterCreature(object oCreature=OBJECT_SELF);

// Use this in an OnPlayerDying module script to get the last player who is dying.
object GetLastPlayerDying();

// Get the starting location of the module.
location GetStartingLocation();

// Make oCreatureToChange join one of the standard factions.
// ** This will only work on an NPC **
// - nStandardFaction: STANDARD_FACTION_*
void ChangeToStandardFaction(object oCreatureToChange, int nStandardFaction);

// Play oSound.
void SoundObjectPlay(object oSound);

// Stop playing oSound.
void SoundObjectStop(object oSound);

// Set the volume of oSound.
// - oSound
// - nVolume: 0-127
void SoundObjectSetVolume(object oSound, int nVolume);

// Set the position of oSound.
void SoundObjectSetPosition(object oSound, vector vPosition);

// Immediately speak a conversation one-liner.
// - sDialogResRef
// - oTokenTarget: This must be specified if there are creature-specific tokens
//   in the string.
void SpeakOneLinerConversation(string sDialogResRef="", object oTokenTarget=OBJECT_TYPE_INVALID);

// Get the amount of gold possessed by oTarget.
int GetGold(object oTarget=OBJECT_SELF);

// Use this in an OnRespawnButtonPressed module script to get the object id of
// the player who last pressed the respawn button.
object GetLastRespawnButtonPresser();

// * Returns TRUE if oCreature is the Dungeon Master.
// Note: This will return FALSE if oCreature is a DM Possessed creature.
// To determine if oCreature is a DM Possessed creature, use GetIsDMPossessed()
int GetIsDM(object oCreature);

// Play a voice chat.
// - nVoiceChatID: VOICE_CHAT_*
// - oTarget
void PlayVoiceChat(int nVoiceChatID, object oTarget=OBJECT_SELF);

// * Returns TRUE if the weapon equipped is capable of damaging oVersus.
int GetIsWeaponEffective(object oVersus=OBJECT_INVALID, int bOffHand=FALSE);

// Use this in a SpellCast script to determine whether the spell was considered
// harmful.
// * Returns TRUE if the last spell cast was harmful.
int GetLastSpellHarmful();

// Activate oItem.
event EventActivateItem(object oItem, location lTarget, object oTarget=OBJECT_INVALID);

// Play the background music for oArea.
void MusicBackgroundPlay(object oArea);

// Stop the background music for oArea.
void MusicBackgroundStop(object oArea);

// Set the delay for the background music for oArea.
// - oArea
// - nDelay: delay in milliseconds
void MusicBackgroundSetDelay(object oArea, int nDelay);

// Change the background day track for oArea to nTrack.
// - oArea
// - nTrack
void MusicBackgroundChangeDay(object oArea, int nTrack);

// Change the background night track for oArea to nTrack.
// - oArea
// - nTrack
void MusicBackgroundChangeNight(object oArea, int nTrack);

// Play the battle music for oArea.
void MusicBattlePlay(object oArea);

// Stop the battle music for oArea.
void MusicBattleStop(object oArea);

// Change the battle track for oArea.
// - oArea
// - nTrack
void MusicBattleChange(object oArea, int nTrack);

// Play the ambient sound for oArea.
void AmbientSoundPlay(object oArea);

// Stop the ambient sound for oArea.
void AmbientSoundStop(object oArea);

// Change the ambient day track for oArea to nTrack.
// - oArea
// - nTrack
void AmbientSoundChangeDay(object oArea, int nTrack);

// Change the ambient night track for oArea to nTrack.
// - oArea
// - nTrack
void AmbientSoundChangeNight(object oArea, int nTrack);

// Get the object that killed the caller.
object GetLastKiller();

// Use this in a spell script to get the item used to cast the spell.
object GetSpellCastItem();

// Use this in an OnItemActivated module script to get the item that was activated.
object GetItemActivated();

// Use this in an OnItemActivated module script to get the creature that
// activated the item.
object GetItemActivator();

// Use this in an OnItemActivated module script to get the location of the item's
// target.
location GetItemActivatedTargetLocation();

// Use this in an OnItemActivated module script to get the item's target.
object GetItemActivatedTarget();

// * Returns TRUE if oObject (which is a placeable or a door) is currently open.
int GetIsOpen(object oObject);

// Take nAmount of gold from oCreatureToTakeFrom.
// - nAmount
// - oCreatureToTakeFrom: If this is not a valid creature, nothing will happen.
// - bDestroy: If this is TRUE, the caller will not get the gold.  Instead, the
//   gold will be destroyed and will vanish from the game.
void TakeGoldFromCreature(int nAmount, object oCreatureToTakeFrom, int bDestroy=FALSE);

// Determine whether oObject is in conversation.
int IsInConversation(object oObject);

// Create an Ability Decrease effect.
// - nAbility: ABILITY_*
// - nModifyBy: This is the amount by which to decrement the ability
effect EffectAbilityDecrease(int nAbility, int nModifyBy);

// Create an Attack Decrease effect.
// - nPenalty
// - nModifierType: ATTACK_BONUS_*
effect EffectAttackDecrease(int nPenalty, int nModifierType=ATTACK_BONUS_MISC);

// Create a Damage Decrease effect.
// - nPenalty
// - nDamageType: DAMAGE_TYPE_*
effect EffectDamageDecrease(int nPenalty, int nDamageType=DAMAGE_TYPE_MAGICAL);

// Create a Damage Immunity Decrease effect.
// - nDamageType: DAMAGE_TYPE_*
// - nPercentImmunity
effect EffectDamageImmunityDecrease(int nDamageType, int nPercentImmunity);

// Create an AC Decrease effect.
// - nValue
// - nModifyType: AC_*
// - nDamageType: DAMAGE_TYPE_*
//   * Default value for nDamageType should only ever be used in this function prototype.
effect EffectACDecrease(int nValue, int nModifyType=AC_DODGE_BONUS, int nDamageType=AC_VS_DAMAGE_TYPE_ALL);

// Create a Movement Speed Decrease effect.
// - nPercentChange - range 0 through 99
// eg.
//    0 = no change in speed
//   50 = 50% slower
//   99 = almost immobile
effect EffectMovementSpeedDecrease(int nPercentChange);

// Create a Saving Throw Decrease effect.
// - nSave: SAVING_THROW_* (not SAVING_THROW_TYPE_*)
//          SAVING_THROW_ALL
//          SAVING_THROW_FORT
//          SAVING_THROW_REFLEX
//          SAVING_THROW_WILL 
// - nValue: size of the Saving Throw decrease
// - nSaveType: SAVING_THROW_TYPE_* (e.g. SAVING_THROW_TYPE_ACID )
effect EffectSavingThrowDecrease(int nSave, int nValue, int nSaveType=SAVING_THROW_TYPE_ALL);

// Create a Skill Decrease effect.
// * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nSkill is invalid.
effect EffectSkillDecrease(int nSkill, int nValue);

// Create a Spell Resistance Decrease effect.
effect EffectSpellResistanceDecrease(int nValue);

// Determine whether oTarget is a plot object.
int GetPlotFlag(object oTarget=OBJECT_SELF);

// Set oTarget's plot object status.
void SetPlotFlag(object oTarget, int nPlotFlag);

// Create an Invisibility effect.
// - nInvisibilityType: INVISIBILITY_TYPE_*
// * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nInvisibilityType
//   is invalid.
effect EffectInvisibility(int nInvisibilityType);

// Create a Concealment effect.
// - nPercentage: 1-100 inclusive
// - nMissChanceType: MISS_CHANCE_TYPE_*
// * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nPercentage < 1 or
//   nPercentage > 100.
effect EffectConcealment(int nPercentage, int nMissType=MISS_CHANCE_TYPE_NORMAL);

// Create a Darkness effect.
effect EffectDarkness();

// Create a Dispel Magic All effect.
// If no parameter is specified, USE_CREATURE_LEVEL will be used. This will
// cause the dispel effect to use the level of the creature that created the
// effect.
effect EffectDispelMagicAll(int nCasterLevel=USE_CREATURE_LEVEL);

// Create an Ultravision effect.
effect EffectUltravision();

// Create a Negative Level effect.
// - nNumLevels: the number of negative levels to apply.
// * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nNumLevels > 100.
effect EffectNegativeLevel(int nNumLevels, int bHPBonus=FALSE);

// Create a Polymorph effect.
effect EffectPolymorph(int nPolymorphSelection, int nLocked=FALSE);

// Create a Sanctuary effect.
// - nDifficultyClass: must be a non-zero, positive number
// * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nDifficultyClass <= 0.
effect EffectSanctuary(int nDifficultyClass);

// Create a True Seeing effect.
effect EffectTrueSeeing();

// Create a See Invisible effect.
effect EffectSeeInvisible();

// Create a Time Stop effect.
effect EffectTimeStop();

// Create a Blindness effect.
effect EffectBlindness();

// Determine whether oSource has a friendly reaction towards oTarget, depending
// on the reputation, PVP setting and (if both oSource and oTarget are PCs),
// oSource's Like/Dislike setting for oTarget.
// Note: If you just want to know how two objects feel about each other in terms
// of faction and personal reputation, use GetIsFriend() instead.
// * Returns TRUE if oSource has a friendly reaction towards oTarget
int GetIsReactionTypeFriendly(object oTarget, object oSource=OBJECT_SELF);

// Determine whether oSource has a neutral reaction towards oTarget, depending
// on the reputation, PVP setting and (if both oSource and oTarget are PCs),
// oSource's Like/Dislike setting for oTarget.
// Note: If you just want to know how two objects feel about each other in terms
// of faction and personal reputation, use GetIsNeutral() instead.
// * Returns TRUE if oSource has a neutral reaction towards oTarget
int GetIsReactionTypeNeutral(object oTarget, object oSource=OBJECT_SELF);

// Determine whether oSource has a Hostile reaction towards oTarget, depending
// on the reputation, PVP setting and (if both oSource and oTarget are PCs),
// oSource's Like/Dislike setting for oTarget.
// Note: If you just want to know how two objects feel about each other in terms
// of faction and personal reputation, use GetIsEnemy() instead.
// * Returns TRUE if oSource has a hostile reaction towards oTarget
int GetIsReactionTypeHostile(object oTarget, object oSource=OBJECT_SELF);

// Create a Spell Level Absorption effect.
// - nMaxSpellLevelAbsorbed: maximum spell level that will be absorbed by the
//   effect
// - nTotalSpellLevelsAbsorbed: maximum number of spell levels that will be
//   absorbed by the effect
// - nSpellSchool: SPELL_SCHOOL_*
// * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if:
//   nMaxSpellLevelAbsorbed is not between -1 and 9 inclusive, or nSpellSchool
//   is invalid.
effect EffectSpellLevelAbsorption(int nMaxSpellLevelAbsorbed, int nTotalSpellLevelsAbsorbed=0, int nSpellSchool=SPELL_SCHOOL_GENERAL );

// Create a Dispel Magic Best effect.
// If no parameter is specified, USE_CREATURE_LEVEL will be used. This will
// cause the dispel effect to use the level of the creature that created the
// effect.
effect EffectDispelMagicBest(int nCasterLevel=USE_CREATURE_LEVEL);

// Try to send oTarget to a new server defined by sIPaddress.
// - oTarget
// - sIPaddress: this can be numerical "192.168.0.84" or alphanumeric
//   "www.bioware.com". It can also contain a port "192.168.0.84:5121" or
//   "www.bioware.com:5121"; if the port is not specified, it will default to
//   5121.
// - sPassword: login password for the destination server
// - sWaypointTag: if this is set, after portalling the character will be moved
//   to this waypoint if it exists
// - bSeamless: if this is set, the client wil not be prompted with the
//   information window telling them about the server, and they will not be
//   allowed to save a copy of their character if they are using a local vault
//   character.
void ActivatePortal(object oTarget, string sIPaddress="", string sPassword="", string sWaypointTag="", int bSeemless=FALSE);

// Get the number of stacked items that oItem comprises.
int GetNumStackedItems(object oItem);

// Use this on an NPC to cause all creatures within a 10-metre radius to stop
// what they are doing and sets the NPC's enemies within this range to be
// neutral towards the NPC for roughly 3 minutes. If this command is run on a PC
// or an object that is not a creature, nothing will happen.
void SurrenderToEnemies();

// Create a Miss Chance effect.
// - nPercentage: 1-100 inclusive
// - nMissChanceType: MISS_CHANCE_TYPE_*
// * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nPercentage < 1 or
//   nPercentage > 100.
effect EffectMissChance(int nPercentage, int nMissChanceType=MISS_CHANCE_TYPE_NORMAL);

// Get the number of Hitdice worth of Turn Resistance that oUndead may have.
// This will only work on undead creatures.
int GetTurnResistanceHD(object oUndead=OBJECT_SELF);

// Get the size (CREATURE_SIZE_*) of oCreature.
int GetCreatureSize(object oCreature);

// Create a Disappear/Appear effect.
// The object will "fly away" for the duration of the effect and will reappear
// at lLocation.
// - nAnimation determines which appear and disappear animations to use. Most creatures
// only have animation 1, although a few have 2 (like beholders)
effect EffectDisappearAppear(location lLocation, int nAnimation=1);

// Create a Disappear effect to make the object "fly away" and then destroy
// itself.
// - nAnimation determines which appear and disappear animations to use. Most creatures
// only have animation 1, although a few have 2 (like beholders)
effect EffectDisappear(int nAnimation=1);

// Create an Appear effect to make the object "fly in".
// - nAnimation determines which appear and disappear animations to use. Most creatures
// only have animation 1, although a few have 2 (like beholders)
effect EffectAppear(int nAnimation=1);

// The action subject will unlock oTarget, which can be a door or a placeable
// object.
void ActionUnlockObject(object oTarget);

// The action subject will lock oTarget, which can be a door or a placeable
// object.
void ActionLockObject(object oTarget);

// Create a Modify Attacks effect to add attacks.
// - nAttacks: maximum is 5, even with the effect stacked
// * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nAttacks > 5.
effect EffectModifyAttacks(int nAttacks);

// Get the last trap detected by oTarget.
// * Return value on error: OBJECT_INVALID
object GetLastTrapDetected(object oTarget=OBJECT_SELF);

// Create a Damage Shield effect which does (nDamageAmount + nRandomAmount)
// damage to any melee attacker on a successful attack of damage type nDamageType.
// - nDamageAmount: an integer value
// - nRandomAmount: DAMAGE_BONUS_*
// - nDamageType: DAMAGE_TYPE_*
// NOTE! You *must* use the DAMAGE_BONUS_* constants! Using other values may
//       result in odd behaviour.
effect EffectDamageShield(int nDamageAmount, int nRandomAmount, int nDamageType);

// Get the trap nearest to oTarget.
// Note : "trap objects" are actually any trigger, placeable or door that is
// trapped in oTarget's area.
// - oTarget
// - nTrapDetected: if this is TRUE, the trap returned has to have been detected
//   by oTarget.
object GetNearestTrapToObject(object oTarget=OBJECT_SELF, int nTrapDetected=TRUE);

// Get the name of oCreature's deity.
// * Returns "" if oCreature is invalid (or if the deity name is blank for
//   oCreature).
string GetDeity(object oCreature);

// Get the name of oCreature's sub race.
// * Returns "" if oCreature is invalid (or if sub race is blank for oCreature).
string GetSubRace(object oTarget);

// Get oTarget's base fortitude saving throw value (this will only work for
// creatures, doors, and placeables).
// * Returns 0 if oTarget is invalid.
int GetFortitudeSavingThrow(object oTarget);

// Get oTarget's base will saving throw value (this will only work for creatures,
// doors, and placeables).
// * Returns 0 if oTarget is invalid.
int GetWillSavingThrow(object oTarget);

// Get oTarget's base reflex saving throw value (this will only work for
// creatures, doors, and placeables).
// * Returns 0 if oTarget is invalid.
int GetReflexSavingThrow(object oTarget);

// Get oCreature's challenge rating.
// * Returns 0.0 if oCreature is invalid.
float GetChallengeRating(object oCreature);

// Get oCreature's age.
// * Returns 0 if oCreature is invalid.
int GetAge(object oCreature);

// Get oCreature's movement rate.
// * Returns 0 if oCreature is invalid.
int GetMovementRate(object oCreature);

// Get oCreature's familiar creature type (FAMILIAR_CREATURE_TYPE_*).
// * Returns FAMILIAR_CREATURE_TYPE_NONE if oCreature is invalid or does not
//   currently have a familiar.
int GetFamiliarCreatureType(object oCreature);

// Get oCreature's animal companion creature type
// (ANIMAL_COMPANION_CREATURE_TYPE_*).
// * Returns ANIMAL_COMPANION_CREATURE_TYPE_NONE if oCreature is invalid or does
//   not currently have an animal companion.
int GetAnimalCompanionCreatureType(object oCreature);

// Get oCreature's familiar's name.
// * Returns "" if oCreature is invalid, does not currently
// have a familiar or if the familiar's name is blank.
string GetFamiliarName(object oCreature);

// Get oCreature's animal companion's name.
// * Returns "" if oCreature is invalid, does not currently
// have an animal companion or if the animal companion's name is blank.
string GetAnimalCompanionName(object oTarget);

// The action subject will fake casting a spell at oTarget; the conjure and cast
// animations and visuals will occur, nothing else.
// - nSpell
// - oTarget
// - nProjectilePathType: PROJECTILE_PATH_TYPE_*
void ActionCastFakeSpellAtObject(int nSpell, object oTarget, int nProjectilePathType=PROJECTILE_PATH_TYPE_DEFAULT);

// The action subject will fake casting a spell at lLocation; the conjure and
// cast animations and visuals will occur, nothing else.
// - nSpell
// - lTarget
// - nProjectilePathType: PROJECTILE_PATH_TYPE_*
void ActionCastFakeSpellAtLocation(int nSpell, location lTarget, int nProjectilePathType=PROJECTILE_PATH_TYPE_DEFAULT);

// Removes oAssociate from the service of oMaster, returning them to their
// original faction.
void RemoveSummonedAssociate(object oMaster, object oAssociate=OBJECT_SELF);

// Set the camera mode for oPlayer.
// - oPlayer
// - nCameraMode: CAMERA_MODE_*
// * If oPlayer is not player-controlled or nCameraMode is invalid, nothing
//   happens.
void SetCameraMode(object oPlayer, int nCameraMode);

// * Returns TRUE if oCreature is resting.
int GetIsResting(object oCreature=OBJECT_SELF);

// Get the last PC that has rested in the module.
object GetLastPCRested();

// Set the weather for oTarget.
// - oTarget: if this is GetModule(), all outdoor areas will be modified by the
//   weather constant. If it is an area, oTarget will play the weather only if
//   it is an outdoor area.
// - nWeather: WEATHER_*
//   -> WEATHER_USER_AREA_SETTINGS will set the area back to random weather.
//   -> WEATHER_CLEAR, WEATHER_RAIN, WEATHER_SNOW will make the weather go to
//      the appropriate precipitation *without stopping*.
void SetWeather(object oTarget, int nWeather);

// Determine the type (REST_EVENTTYPE_REST_*) of the last rest event (as
// returned from the OnPCRested module event).
int GetLastRestEventType();

// Shut down the currently loaded module and start a new one (moving all
// currently-connected players to the starting point.
void StartNewModule(string sModuleName);

// Create a Swarm effect.
// - nLooping: If this is TRUE, for the duration of the effect when one creature
//   created by this effect dies, the next one in the list will be created.  If
//   the last creature in the list dies, we loop back to the beginning and
//   sCreatureTemplate1 will be created, and so on...
// - sCreatureTemplate1
// - sCreatureTemplate2
// - sCreatureTemplate3
// - sCreatureTemplate4
effect EffectSwarm(int nLooping, string sCreatureTemplate1, string sCreatureTemplate2="", string sCreatureTemplate3="", string sCreatureTemplate4="");

// * Returns TRUE if oItem is a ranged weapon.
int GetWeaponRanged(object oItem);

// Only if we are in a single player game, AutoSave the game.
void DoSinglePlayerAutoSave();

// Get the game difficulty (GAME_DIFFICULTY_*).
int GetGameDifficulty();

// Set the main light color on the tile at lTileLocation.
// - lTileLocation: the vector part of this is the tile grid (x,y) coordinate of
//   the tile.
// - nMainLight1Color: TILE_MAIN_LIGHT_COLOR_*
// - nMainLight2Color: TILE_MAIN_LIGHT_COLOR_*
void SetTileMainLightColor(location lTileLocation, int nMainLight1Color, int nMainLight2Color);

// Set the source light color on the tile at lTileLocation.
// - lTileLocation: the vector part of this is the tile grid (x,y) coordinate of
//   the tile.
// - nSourceLight1Color: TILE_SOURCE_LIGHT_COLOR_*
// - nSourceLight2Color: TILE_SOURCE_LIGHT_COLOR_*
void SetTileSourceLightColor(location lTileLocation, int nSourceLight1Color, int nSourceLight2Color);

// All clients in oArea will recompute the static lighting.
// This can be used to update the lighting after changing any tile lights or if
// placeables with lights have been added/deleted.
void RecomputeStaticLighting(object oArea);

// Get the color (TILE_MAIN_LIGHT_COLOR_*) for the main light 1 of the tile at
// lTile.
// - lTile: the vector part of this is the tile grid (x,y) coordinate of the tile.
int GetTileMainLight1Color(location lTile);

// Get the color (TILE_MAIN_LIGHT_COLOR_*) for the main light 2 of the tile at
// lTile.
// - lTile: the vector part of this is the tile grid (x,y) coordinate of the
//   tile.
int GetTileMainLight2Color(location lTile);

// Get the color (TILE_SOURCE_LIGHT_COLOR_*) for the source light 1 of the tile
// at lTile.
// - lTile: the vector part of this is the tile grid (x,y) coordinate of the
//   tile.
int GetTileSourceLight1Color(location lTile);

// Get the color (TILE_SOURCE_LIGHT_COLOR_*) for the source light 2 of the tile
// at lTile.
// - lTile: the vector part of this is the tile grid (x,y) coordinate of the
//   tile.
int GetTileSourceLight2Color(location lTile);

// Make the corresponding panel button on the player's client start or stop
// flashing.
// - oPlayer
// - nButton: PANEL_BUTTON_*
// - nEnableFlash: if this is TRUE nButton will start flashing.  It if is FALSE,
//   nButton will stop flashing.
void SetPanelButtonFlash(object oPlayer, int nButton, int nEnableFlash);

// Get the current action (ACTION_*) that oObject is executing.
int GetCurrentAction(object oObject=OBJECT_SELF);

// Set how nStandardFaction feels about oCreature.
// - nStandardFaction: STANDARD_FACTION_*
// - nNewReputation: 0-100 (inclusive)
// - oCreature
void SetStandardFactionReputation(int nStandardFaction, int nNewReputation, object oCreature=OBJECT_SELF);

// Find out how nStandardFaction feels about oCreature.
// - nStandardFaction: STANDARD_FACTION_*
// - oCreature
// Returns -1 on an error.
// Returns 0-100 based on the standing of oCreature within the faction nStandardFaction.
// 0-10   :  Hostile.
// 11-89  :  Neutral.
// 90-100 :  Friendly.
int GetStandardFactionReputation(int nStandardFaction, object oCreature=OBJECT_SELF);

// Display floaty text above the specified creature.
// The text will also appear in the chat buffer of each player that receives the
// floaty text.
// - nStrRefToDisplay: String ref (therefore text is translated)
// - oCreatureToFloatAbove
// - bBroadcastToFaction: If this is TRUE then only creatures in the same faction
//   as oCreatureToFloatAbove
//   will see the floaty text, and only if they are within range (30 metres).
void FloatingTextStrRefOnCreature(int nStrRefToDisplay, object oCreatureToFloatAbove, int bBroadcastToFaction=TRUE);

// Display floaty text above the specified creature.
// The text will also appear in the chat buffer of each player that receives the
// floaty text.
// - sStringToDisplay: String
// - oCreatureToFloatAbove
// - bBroadcastToFaction: If this is TRUE then only creatures in the same faction
//   as oCreatureToFloatAbove
//   will see the floaty text, and only if they are within range (30 metres).
void FloatingTextStringOnCreature(string sStringToDisplay, object oCreatureToFloatAbove, int bBroadcastToFaction=TRUE);

// - oTrapObject: a placeable, door or trigger
// * Returns TRUE if oTrapObject is disarmable.
int GetTrapDisarmable(object oTrapObject);

// - oTrapObject: a placeable, door or trigger
// * Returns TRUE if oTrapObject is detectable.
int GetTrapDetectable(object oTrapObject);

// - oTrapObject: a placeable, door or trigger
// - oCreature
// * Returns TRUE if oCreature has detected oTrapObject
int GetTrapDetectedBy(object oTrapObject, object oCreature);

// - oTrapObject: a placeable, door or trigger
// * Returns TRUE if oTrapObject has been flagged as visible to all creatures.
int GetTrapFlagged(object oTrapObject);

// Get the trap base type (TRAP_BASE_TYPE_*) of oTrapObject.
// - oTrapObject: a placeable, door or trigger
int GetTrapBaseType(object oTrapObject);

// - oTrapObject: a placeable, door or trigger
// * Returns TRUE if oTrapObject is one-shot (i.e. it does not reset itself
//   after firing.
int GetTrapOneShot(object oTrapObject);

// Get the creator of oTrapObject, the creature that set the trap.
// - oTrapObject: a placeable, door or trigger
// * Returns OBJECT_INVALID if oTrapObject was created in the toolset.
object GetTrapCreator(object oTrapObject);

// Get the tag of the key that will disarm oTrapObject.
// - oTrapObject: a placeable, door or trigger
string GetTrapKeyTag(object oTrapObject);

// Get the DC for disarming oTrapObject.
// - oTrapObject: a placeable, door or trigger
int GetTrapDisarmDC(object oTrapObject);

// Get the DC for detecting oTrapObject.
// - oTrapObject: a placeable, door or trigger
int GetTrapDetectDC(object oTrapObject);

// * Returns TRUE if a specific key is required to open the lock on oObject.
int GetLockKeyRequired(object oObject);

// Get the tag of the key that will open the lock on oObject.
string GetLockKeyTag(object oObject);

// * Returns TRUE if the lock on oObject is lockable.
int GetLockLockable(object oObject);

// Get the DC for unlocking oObject.
int GetLockUnlockDC(object oObject);

// Get the DC for locking oObject.
int GetLockLockDC(object oObject);

// Get the last PC that levelled up.
object GetPCLevellingUp();

// - nFeat: FEAT_*
// - oObject
// * Returns TRUE if oObject has effects on it originating from nFeat.
int GetHasFeatEffect(int nFeat, object oObject=OBJECT_SELF);

// Set the status of the illumination for oPlaceable.
// - oPlaceable
// - bIlluminate: if this is TRUE, oPlaceable's illumination will be turned on.
//   If this is FALSE, oPlaceable's illumination will be turned off.
// Note: You must call RecomputeStaticLighting() after calling this function in
// order for the changes to occur visually for the players.
// SetPlaceableIllumination() buffers the illumination changes, which are then
// sent out to the players once RecomputeStaticLighting() is called.  As such,
// it is best to call SetPlaceableIllumination() for all the placeables you wish
// to set the illumination on, and then call RecomputeStaticLighting() once after
// all the placeable illumination has been set.
// * If oPlaceable is not a placeable object, or oPlaceable is a placeable that
//   doesn't have a light, nothing will happen.
void SetPlaceableIllumination(object oPlaceable=OBJECT_SELF, int bIlluminate=TRUE);

// * Returns TRUE if the illumination for oPlaceable is on
int GetPlaceableIllumination(object oPlaceable=OBJECT_SELF);

// - oPlaceable
// - nPlaceableAction: PLACEABLE_ACTION_*
// * Returns TRUE if nPlacebleAction is valid for oPlaceable.
int GetIsPlaceableObjectActionPossible(object oPlaceable, int nPlaceableAction);

// The caller performs nPlaceableAction on oPlaceable.
// - oPlaceable
// - nPlaceableAction: PLACEABLE_ACTION_*
void DoPlaceableObjectAction(object oPlaceable, int nPlaceableAction);

// Get the first PC in the player list.
// This resets the position in the player list for GetNextPC().
object GetFirstPC();

// Get the next PC in the player list.
// This picks up where the last GetFirstPC() or GetNextPC() left off.
object GetNextPC();

// Set whether or not the creature oDetector has detected the trapped object oTrap.
// - oTrap: A trapped trigger, placeable or door object.
// - oDetector: This is the creature that the detected status of the trap is being adjusted for.
// - bDetected: A Boolean that sets whether the trapped object has been detected or not.
int SetTrapDetectedBy(object oTrap, object oDetector, int bDetected=TRUE);

// Note: Only placeables, doors and triggers can be trapped.
// * Returns TRUE if oObject is trapped.
int GetIsTrapped(object oObject);

// Create a Turn Resistance Decrease effect.
// - nHitDice: a positive number representing the number of hit dice for the
///  decrease
effect EffectTurnResistanceDecrease(int nHitDice);

// Create a Turn Resistance Increase effect.
// - nHitDice: a positive number representing the number of hit dice for the
//   increase
effect EffectTurnResistanceIncrease(int nHitDice);

// Spawn in the Death GUI.
// The default (as defined by BioWare) can be spawned in by PopUpGUIPanel, but
// if you want to turn off the "Respawn" or "Wait for Help" buttons, this is the
// function to use.
// - oPC
// - bRespawnButtonEnabled: if this is TRUE, the "Respawn" button will be enabled
//   on the Death GUI.
// - bWaitForHelpButtonEnabled: if this is TRUE, the "Wait For Help" button will
//   be enabled on the Death GUI (Note: This button will not appear in single player games).
// - nHelpStringReference
// - sHelpString
void PopUpDeathGUIPanel(object oPC, int bRespawnButtonEnabled=TRUE, int bWaitForHelpButtonEnabled=TRUE, int nHelpStringReference=0, string sHelpString="");

// Disable oTrap.
// - oTrap: a placeable, door or trigger.
void SetTrapDisabled(object oTrap);

// Get the last object that was sent as a GetLastAttacker(), GetLastDamager(),
// GetLastSpellCaster() (for a hostile spell), or GetLastDisturbed() (when a
// creature is pickpocketed).
// Note: Return values may only ever be:
// 1) A Creature
// 2) Plot Characters will never have this value set
// 3) Area of Effect Objects will return the AOE creator if they are registered
//    as this value, otherwise they will return INVALID_OBJECT_ID
// 4) Traps will not return the creature that set the trap.
// 5) This value will never be overwritten by another non-creature object.
// 6) This value will never be a dead/destroyed creature
object GetLastHostileActor(object oVictim=OBJECT_SELF);

// Force all the characters of the players who are currently in the game to
// be exported to their respective directories i.e. LocalVault/ServerVault/ etc.
void ExportAllCharacters();

// Get the Day Track for oArea.
int MusicBackgroundGetDayTrack(object oArea);

// Get the Night Track for oArea.
int MusicBackgroundGetNightTrack(object oArea);

// Write sLogEntry as a timestamped entry into the log file
void WriteTimestampedLogEntry(string sLogEntry);

// Get the module's name in the language of the server that's running it.
// * If there is no entry for the language of the server, it will return an
//   empty string
string GetModuleName();

// Get the player leader of the faction of which oMemberOfFaction is a member.
// * Returns OBJECT_INVALID if oMemberOfFaction is not a valid creature,
//   or oMemberOfFaction is a member of a NPC faction.
object GetFactionLeader(object oMemberOfFaction);

// Sends szMessage to all the Dungeon Masters currently on the server.
void SendMessageToAllDMs(string szMessage);

// End the currently running game, play sEndMovie then return all players to the
// game's main menu.
void EndGame(string sEndMovie);

// Remove oPlayer from the server.
void BootPC(object oPlayer);

// Counterspell oCounterSpellTarget.
void ActionCounterSpell(object oCounterSpellTarget);

// Set the ambient day volume for oArea to nVolume.
// - oArea
// - nVolume: 0 - 100
void AmbientSoundSetDayVolume(object oArea, int nVolume);

// Set the ambient night volume for oArea to nVolume.
// - oArea
// - nVolume: 0 - 100
void AmbientSoundSetNightVolume(object oArea, int nVolume);

// Get the Battle Track for oArea.
int MusicBackgroundGetBattleTrack(object oArea);

// Determine whether oObject has an inventory.
// * Returns TRUE for creatures and stores, and checks to see if an item or placeable object is a container.
// * Returns FALSE for all other object types.
int GetHasInventory(object oObject);

// Get the duration (in seconds) of the sound attached to nStrRef
// * Returns 0.0f if no duration is stored or if no sound is attached
float GetStrRefSoundDuration(int nStrRef);

// Add oPC to oPartyLeader's party.  This will only work on two PCs.
// - oPC: player to add to a party
// - oPartyLeader: player already in the party
void AddToParty(object oPC, object oPartyLeader);

// Remove oPC from their current party. This will only work on a PC.
// - oPC: removes this player from whatever party they're currently in.
void RemoveFromParty(object oPC);

// Returns the stealth mode of the specified creature.
// - oCreature
// * Returns a constant STEALTH_MODE_*
int GetStealthMode(object oCreature);

// Returns the detection mode of the specified creature.
// - oCreature
// * Returns a constant DETECT_MODE_*
int GetDetectMode(object oCreature);

// Returns the defensive casting mode of the specified creature.
// - oCreature
// * Returns a constant DEFENSIVE_CASTING_MODE_*
int GetDefensiveCastingMode(object oCreature);

// returns the appearance type of the specified creature.
// * returns a constant APPEARANCE_TYPE_* for valid creatures
// * returns APPEARANCE_TYPE_INVALID for non creatures/invalid creatures
int GetAppearanceType(object oCreature);

// SpawnScriptDebugger() will cause the script debugger to be executed
// after this command is executed!  
// In order to compile the script for debugging go to Tools->Options->Script Editor
// and check the box labeled "Generate Debug Information When Compiling Scripts"
// After you have checked the above box, recompile the script that you want to debug.
// If the script file isn't compiled for debugging, this command will do nothing.
// Remove any SpawnScriptDebugger() calls once you have finished 
// debugging the script.
void SpawnScriptDebugger();

// in an onItemAcquired script, returns the size of the stack of the item
// that was just acquired.
// * returns the stack size of the item acquired
int GetModuleItemAcquiredStackSize();

// Decrement the remaining uses per day for this creature by one.
// - oCreature: creature to modify
// - nFeat: constant FEAT_*
void DecrementRemainingFeatUses(object oCreature, int nFeat);

// Decrement the remaining uses per day for this creature by one.
// - oCreature: creature to modify
// - nSpell: constant SPELL_*
void DecrementRemainingSpellUses(object oCreature, int nSpell);

// returns the template used to create this object (if appropriate)
// * returns an empty string when no template found
string GetResRef(object oObject);

// returns an effect that will petrify the target
// * currently applies EffectParalyze and the stoneskin visual effect.
effect EffectPetrify();

// duplicates the item and returns a new object
// oItem - item to copy
// oTargetInventory - create item in this object's inventory. If this parameter
//                    is not valid, the item will be created in oItem's location
// bCopyVars - copy the local variables from the old item to the new one
// * returns the new item
// * returns OBJECT_INVALID for non-items.
// * can only copy empty item containers. will return OBJECT_INVALID if oItem contains
//   other items.
// * if it is possible to merge this item with any others in the target location,
//   then it will do so and return the merged object.
object CopyItem(object oItem, object oTargetInventory=OBJECT_INVALID, int bCopyVars=FALSE);

// returns an effect that is guaranteed to paralyze a creature.
// this effect is identical to EffectParalyze except that it cannot be resisted.
effect EffectCutsceneParalyze();

// returns TRUE if the item CAN be dropped
// Droppable items will appear on a creature's remains when the creature is killed.
int GetDroppableFlag(object oItem);

// returns TRUE if the placeable object is usable
int GetUseableFlag(object oObject=OBJECT_SELF);

// returns TRUE if the item is stolen
int GetStolenFlag(object oStolen);

// This stores a float out to the specified campaign database
// The database name IS case sensitive and it must be the same for both set and get functions.
// The var name must be unique across the entire database, regardless of the variable type.
// If you want a variable to pertain to a specific player in the game, provide a player object.
void SetCampaignFloat(string sCampaignName, string sVarName, float flFloat, object oPlayer=OBJECT_INVALID);

// This stores an int out to the specified campaign database
// The database name IS case sensitive and it must be the same for both set and get functions.
// The var name must be unique across the entire database, regardless of the variable type.
// If you want a variable to pertain to a specific player in the game, provide a player object.
void SetCampaignInt(string sCampaignName, string sVarName, int nInt, object oPlayer=OBJECT_INVALID);

// This stores a vector out to the specified campaign database
// The database name IS case sensitive and it must be the same for both set and get functions.
// The var name must be unique across the entire database, regardless of the variable type.
// If you want a variable to pertain to a specific player in the game, provide a player object.
void SetCampaignVector(string sCampaignName, string sVarName, vector vVector, object oPlayer=OBJECT_INVALID);

// This stores a location out to the specified campaign database
// The database name IS case sensitive and it must be the same for both set and get functions.
// The var name must be unique across the entire database, regardless of the variable type.
// If you want a variable to pertain to a specific player in the game, provide a player object.
void SetCampaignLocation(string sCampaignName, string sVarName, location locLocation, object oPlayer=OBJECT_INVALID);

// This stores a string out to the specified campaign database
// The database name IS case sensitive and it must be the same for both set and get functions.
// The var name must be unique across the entire database, regardless of the variable type.
// If you want a variable to pertain to a specific player in the game, provide a player object.
void SetCampaignString(string sCampaignName, string sVarName, string sString, object oPlayer=OBJECT_INVALID);

// This will delete the entire campaign database if it exists.
void DestroyCampaignDatabase(string sCampaignName);

// This will read a float from the  specified campaign database
// The database name IS case sensitive and it must be the same for both set and get functions.
// The var name must be unique across the entire database, regardless of the variable type.
// If you want a variable to pertain to a specific player in the game, provide a player object.
float GetCampaignFloat(string sCampaignName, string sVarName, object oPlayer=OBJECT_INVALID);

// This will read an int from the  specified campaign database
// The database name IS case sensitive and it must be the same for both set and get functions.
// The var name must be unique across the entire database, regardless of the variable type.
// If you want a variable to pertain to a specific player in the game, provide a player object.
int GetCampaignInt(string sCampaignName, string sVarName, object oPlayer=OBJECT_INVALID);

// This will read a vector from the  specified campaign database
// The database name IS case sensitive and it must be the same for both set and get functions.
// The var name must be unique across the entire database, regardless of the variable type.
// If you want a variable to pertain to a specific player in the game, provide a player object.
vector GetCampaignVector(string sCampaignName, string sVarName, object oPlayer=OBJECT_INVALID);

// This will read a location from the  specified campaign database
// The database name IS case sensitive and it must be the same for both set and get functions.
// The var name must be unique across the entire database, regardless of the variable type.
// If you want a variable to pertain to a specific player in the game, provide a player object.
location GetCampaignLocation(string sCampaignName, string sVarName, object oPlayer=OBJECT_INVALID);

// This will read a string from the  specified campaign database
// The database name IS case sensitive and it must be the same for both set and get functions.
// The var name must be unique across the entire database, regardless of the variable type.
// If you want a variable to pertain to a specific player in the game, provide a player object.
string GetCampaignString(string sCampaignName, string sVarName, object oPlayer=OBJECT_INVALID);

// Duplicates the object specified by oSource.
// ONLY creatures and items can be specified.
// If an owner is specified and the object is an item, it will be put into their inventory
// If the object is a creature, they will be created at the location.
// If a new tag is specified, it will be assigned to the new object.
object CopyObject(object oSource, location locLocation, object oOwner = OBJECT_INVALID, string sNewTag = "");

// This will remove ANY campaign variable. Regardless of type.
// Note that by normal database standards, deleting does not actually removed the entry from
// the database, but flags it as deleted. Do not expect the database files to shrink in size
// from this command. If you want to 'pack' the database, you will have to do it externally
// from the game.
void DeleteCampaignVariable(string sCampaignName, string sVarName, object oPlayer=OBJECT_INVALID);

// Stores an object with the given id.
// NOTE: this command can only be used for storing Creatures and Items.
// Returns 0 if it failled, 1 if it worked.
int StoreCampaignObject(string sCampaignName, string sVarName, object oObject, object oPlayer=OBJECT_INVALID);

// Use RetrieveCampaign with the given id to restore it.
// If you specify an owner, the object will try to be created in their repository
// If the owner can't handle the item (or if it's a creature) it will be created on the ground.
object RetrieveCampaignObject(string sCampaignName, string sVarName, location locLocation, object oOwner = OBJECT_INVALID, object oPlayer=OBJECT_INVALID);

// Returns an effect that is guaranteed to dominate a creature
// Like EffectDominated but cannot be resisted
effect EffectCutsceneDominated();

// Returns stack size of an item
// - oItem: item to query
int GetItemStackSize(object oItem);

// Sets stack size of an item.
// - oItem: item to change
// - nSize: new size of stack.  Will be restricted to be between 1 and the
//   maximum stack size for the item type.  If a value less than 1 is passed it
//   will set the stack to 1.  If a value greater than the max is passed
//   then it will set the stack to the maximum size
void SetItemStackSize(object oItem, int nSize);

// Returns charges left on an item
// - oItem: item to query
int GetItemCharges(object oItem);

// Sets charges left on an item.
// - oItem: item to change
// - nCharges: number of charges.  If value below 0 is passed, # charges will
//   be set to 0.  If value greater than maximum is passed, # charges will
//   be set to maximum.  If the # charges drops to 0 the item
//   will be destroyed.
void SetItemCharges(object oItem, int nCharges);

// ***********************  START OF ITEM PROPERTY FUNCTIONS  **********************

// adds an item property to the specified item
// Only temporary and permanent duration types are allowed.
void AddItemProperty(int nDurationType, itemproperty ipProperty, object oItem, float fDuration=0.0f);

// removes an item property from the specified item
void RemoveItemProperty(object oItem, itemproperty ipProperty);

// if the item property is valid this will return true
int GetIsItemPropertyValid(itemproperty ipProperty);

// Gets the first item property on an item
itemproperty GetFirstItemProperty(object oItem);

// Will keep retrieving the next and the next item property on an Item,
// will return an invalid item property when the list is empty.
itemproperty GetNextItemProperty(object oItem);

// will return the item property type (ie. holy avenger)
int GetItemPropertyType(itemproperty ip);

// will return the duration type of the item property
int GetItemPropertyDurationType(itemproperty ip);

// Returns Item property ability bonus.  You need to specify an
// ability constant(IP_CONST_ABILITY_*) and the bonus.  The bonus should
// be a positive integer between 1 and 12.
itemproperty ItemPropertyAbilityBonus(int nAbility, int nBonus);

// Returns Item property AC bonus.  You need to specify the bonus.
// The bonus should be a positive integer between 1 and 20. The modifier
// type depends on the item it is being applied to.
itemproperty ItemPropertyACBonus(int nBonus);

// Returns Item property AC bonus vs. alignment group.  An example of
// an alignment group is Chaotic, or Good.  You need to specify the
// alignment group constant(IP_CONST_ALIGNMENTGROUP_*) and the AC bonus.
// The AC bonus should be an integer between 1 and 20.  The modifier
// type depends on the item it is being applied to.
itemproperty ItemPropertyACBonusVsAlign(int nAlignGroup, int nACBonus);

// Returns Item property AC bonus vs. Damage type (ie. piercing).  You
// need to specify the damage type constant(IP_CONST_DAMAGETYPE_*) and the
// AC bonus.  The AC bonus should be an integer between 1 and 20.  The
// modifier type depends on the item it is being applied to.
// NOTE: Only the first 3 damage types may be used here, the 3 basic
//       physical types.
itemproperty ItemPropertyACBonusVsDmgType(int nDamageType, int nACBonus);

// Returns Item property AC bonus vs. Racial group.  You need to specify
// the racial group constant(IP_CONST_RACIALTYPE_*) and the AC bonus.  The AC
// bonus should be an integer between 1 and 20.  The modifier type depends
// on the item it is being applied to.
itemproperty ItemPropertyACBonusVsRace(int nRace, int nACBonus);

// Returns Item property AC bonus vs. Specific alignment.  You need to
// specify the specific alignment constant(IP_CONST_ALIGNMENT_*) and the AC
// bonus.  The AC bonus should be an integer between 1 and 20.  The
// modifier type depends on the item it is being applied to.
itemproperty ItemPropertyACBonusVsSAlign(int nAlign, int nACBonus);

// Returns Item property Enhancement bonus.  You need to specify the
// enhancement bonus.  The Enhancement bonus should be an integer between
// 1 and 20.
itemproperty ItemPropertyEnhancementBonus(int nEnhancementBonus);

// Returns Item property Enhancement bonus vs. an Alignment group.  You
// need to specify the alignment group constant(IP_CONST_ALIGNMENTGROUP_*)
// and the enhancement bonus.  The Enhancement bonus should be an integer
// between 1 and 20.
itemproperty ItemPropertyEnhancementBonusVsAlign(int nAlignGroup, int nBonus);

// Returns Item property Enhancement bonus vs. Racial group.  You need
// to specify the racial group constant(IP_CONST_RACIALTYPE_*) and the
// enhancement bonus.  The enhancement bonus should be an integer between
// 1 and 20.
itemproperty ItemPropertyEnhancementBonusVsRace(int nRace, int nBonus);

// Returns Item property Enhancement bonus vs. a specific alignment.  You
// need to specify the alignment constant(IP_CONST_ALIGNMENT_*) and the
// enhancement bonus.  The enhancement bonus should be an integer between
// 1 and 20.
itemproperty ItemPropertyEnhancementBonusVsSAlign(int nAlign, int nBonus);

// Returns Item property Enhancment penalty.  You need to specify the
// enhancement penalty.  The enhancement penalty should be a POSITIVE
// integer between 1 and 5 (ie. 1 = -1).
itemproperty ItemPropertyEnhancementPenalty(int nPenalty);

// Returns Item property weight reduction.  You need to specify the weight
// reduction constant(IP_CONST_REDUCEDWEIGHT_*).
itemproperty ItemPropertyWeightReduction(int nReduction);

// Returns Item property Bonus Feat.  You need to specify the the feat
// constant(IP_CONST_FEAT_*).
itemproperty ItemPropertyBonusFeat(int nFeat);

// Returns Item property Bonus level spell (Bonus spell of level).  You must
// specify the class constant(IP_CONST_CLASS_*) of the bonus spell(MUST BE a
// spell casting class) and the level of the bonus spell.  The level of the
// bonus spell should be an integer between 0 and 9.
itemproperty ItemPropertyBonusLevelSpell(int nClass, int nSpellLevel);

// Returns Item property Cast spell.  You must specify the spell constant
// (IP_CONST_CASTSPELL_*) and the number of uses constant(IP_CONST_CASTSPELL_NUMUSES_*).
// NOTE: The number after the name of the spell in the constant is the level
//       at which the spell will be cast.  Sometimes there are multiple copies
//       of the same spell but they each are cast at a different level.  The higher
//       the level, the more cost will be added to the item.
// NOTE: The list of spells that can be applied to an item will depend on the
//       item type.  For instance there are spells that can be applied to a wand
//       that cannot be applied to a potion.  Below is a list of the types and the
//       spells that are allowed to be placed on them.  If you try to put a cast
//       spell effect on an item that is not allowed to have that effect it will
//       not work.
// NOTE: Even if spells have multiple versions of different levels they are only
//       listed below once.
//
// WANDS:
//          Acid_Splash
//          Activate_Item
//          Aid
//          Amplify
//          Animate_Dead
//          AuraOfGlory
//          BalagarnsIronHorn
//          Bane
//          Banishment
//          Barkskin
//          Bestow_Curse
//          Bigbys_Clenched_Fist
//          Bigbys_Crushing_Hand
//          Bigbys_Forceful_Hand
//          Bigbys_Grasping_Hand
//          Bigbys_Interposing_Hand
//          Bless
//          Bless_Weapon
//          Blindness/Deafness
//          Blood_Frenzy
//          Bombardment
//          Bulls_Strength
//          Burning_Hands
//          Call_Lightning
//          Camoflage
//          Cats_Grace
//          Charm_Monster
//          Charm_Person
//          Charm_Person_or_Animal
//          Clairaudience/Clairvoyance
//          Clarity
//          Color_Spray
//          Confusion
//          Continual_Flame
//          Cure_Critical_Wounds
//          Cure_Light_Wounds
//          Cure_Minor_Wounds
//          Cure_Moderate_Wounds
//          Cure_Serious_Wounds
//          Darkness
//          Darkvision
//          Daze
//          Death_Ward
//          Dirge
//          Dismissal
//          Dispel_Magic
//          Displacement
//          Divine_Favor
//          Divine_Might
//          Divine_Power
//          Divine_Shield
//          Dominate_Animal
//          Dominate_Person
//          Doom
//          Dragon_Breath_Acid
//          Dragon_Breath_Cold
//          Dragon_Breath_Fear
//          Dragon_Breath_Fire
//          Dragon_Breath_Gas
//          Dragon_Breath_Lightning
//          Dragon_Breath_Paralyze
//          Dragon_Breath_Sleep
//          Dragon_Breath_Slow
//          Dragon_Breath_Weaken
//          Drown
//          Eagle_Spledor
//          Earthquake
//          Electric_Jolt
//          Elemental_Shield
//          Endurance
//          Endure_Elements
//          Enervation
//          Entangle
//          Entropic_Shield
//          Etherealness
//          Expeditious_Retreat
//          Fear
//          Find_Traps
//          Fireball
//          Firebrand
//          Flame_Arrow
//          Flame_Lash
//          Flame_Strike
//          Flare
//          Foxs_Cunning
//          Freedom_of_Movement
//          Ghostly_Visage
//          Ghoul_Touch
//          Grease
//          Greater_Magic_Fang
//          Greater_Magic_Weapon
//          Grenade_Acid
//          Grenade_Caltrops
//          Grenade_Chicken
//          Grenade_Choking
//          Grenade_Fire
//          Grenade_Holy
//          Grenade_Tangle
//          Grenade_Thunderstone
//          Gust_of_wind
//          Hammer_of_the_Gods
//          Haste
//          Hold_Animal
//          Hold_Monster
//          Hold_Person
//          Ice_Storm
//          Identify
//          Improved_Invisibility
//          Inferno
//          Inflict_Critical_Wounds
//          Inflict_Light_Wounds
//          Inflict_Minor_Wounds
//          Inflict_Moderate_Wounds
//          Inflict_Serious_Wounds
//          Invisibility
//          Invisibility_Purge
//          Invisibility_Sphere
//          Isaacs_Greater_Missile_Storm
//          Isaacs_Lesser_Missile_Storm
//          Knock
//          Lesser_Dispel
//          Lesser_Restoration
//          Lesser_Spell_Breach
//          Light
//          Lightning_Bolt
//          Mage_Armor
//          Magic_Circle_against_Alignment
//          Magic_Fang
//          Magic_Missile
//          Manipulate_Portal_Stone
//          Mass_Camoflage
//          Melfs_Acid_Arrow
//          Meteor_Swarm
//          Mind_Blank
//          Mind_Fog
//          Negative_Energy_Burst
//          Negative_Energy_Protection
//          Negative_Energy_Ray
//          Neutralize_Poison
//          One_With_The_Land
//          Owls_Insight
//          Owls_Wisdom
//          Phantasmal_Killer
//          Planar_Ally
//          Poison
//          Polymorph_Self
//          Prayer
//          Protection_from_Alignment
//          Protection_From_Elements
//          Quillfire
//          Ray_of_Enfeeblement
//          Ray_of_Frost
//          Remove_Blindness/Deafness
//          Remove_Curse
//          Remove_Disease
//          Remove_Fear
//          Remove_Paralysis
//          Resist_Elements
//          Resistance
//          Restoration
//          Sanctuary
//          Scare
//          Searing_Light
//          See_Invisibility
//          Shadow_Conjuration
//          Shield
//          Shield_of_Faith
//          Silence
//          Sleep
//          Slow
//          Sound_Burst
//          Spike_Growth
//          Stinking_Cloud
//          Stoneskin
//          Summon_Creature_I
//          Summon_Creature_I
//          Summon_Creature_II
//          Summon_Creature_III
//          Summon_Creature_IV
//          Sunburst
//          Tashas_Hideous_Laughter
//          True_Strike
//          Undeaths_Eternal_Foe
//          Unique_Power
//          Unique_Power_Self_Only
//          Vampiric_Touch
//          Virtue
//          Wall_of_Fire
//          Web
//          Wounding_Whispers
//
// POTIONS:
//          Activate_Item
//          Aid
//          Amplify
//          AuraOfGlory
//          Bane
//          Barkskin
//          Barkskin
//          Barkskin
//          Bless
//          Bless_Weapon
//          Bless_Weapon
//          Blood_Frenzy
//          Bulls_Strength
//          Bulls_Strength
//          Bulls_Strength
//          Camoflage
//          Cats_Grace
//          Cats_Grace
//          Cats_Grace
//          Clairaudience/Clairvoyance
//          Clairaudience/Clairvoyance
//          Clairaudience/Clairvoyance
//          Clarity
//          Continual_Flame
//          Cure_Critical_Wounds
//          Cure_Critical_Wounds
//          Cure_Critical_Wounds
//          Cure_Light_Wounds
//          Cure_Light_Wounds
//          Cure_Minor_Wounds
//          Cure_Moderate_Wounds
//          Cure_Moderate_Wounds
//          Cure_Moderate_Wounds
//          Cure_Serious_Wounds
//          Cure_Serious_Wounds
//          Cure_Serious_Wounds
//          Darkness
//          Darkvision
//          Darkvision
//          Death_Ward
//          Dispel_Magic
//          Dispel_Magic
//          Displacement
//          Divine_Favor
//          Divine_Might
//          Divine_Power
//          Divine_Shield
//          Dragon_Breath_Acid
//          Dragon_Breath_Cold
//          Dragon_Breath_Fear
//          Dragon_Breath_Fire
//          Dragon_Breath_Gas
//          Dragon_Breath_Lightning
//          Dragon_Breath_Paralyze
//          Dragon_Breath_Sleep
//          Dragon_Breath_Slow
//          Dragon_Breath_Weaken
//          Eagle_Spledor
//          Eagle_Spledor
//          Eagle_Spledor
//          Elemental_Shield
//          Elemental_Shield
//          Endurance
//          Endurance
//          Endurance
//          Endure_Elements
//          Entropic_Shield
//          Ethereal_Visage
//          Ethereal_Visage
//          Etherealness
//          Expeditious_Retreat
//          Find_Traps
//          Foxs_Cunning
//          Foxs_Cunning
//          Foxs_Cunning
//          Freedom_of_Movement
//          Ghostly_Visage
//          Ghostly_Visage
//          Ghostly_Visage
//          Globe_of_Invulnerability
//          Greater_Bulls_Strength
//          Greater_Cats_Grace
//          Greater_Dispelling
//          Greater_Dispelling
//          Greater_Eagles_Splendor
//          Greater_Endurance
//          Greater_Foxs_Cunning
//          Greater_Magic_Weapon
//          Greater_Owls_Wisdom
//          Greater_Restoration
//          Greater_Spell_Mantle
//          Greater_Stoneskin
//          Grenade_Acid
//          Grenade_Caltrops
//          Grenade_Chicken
//          Grenade_Choking
//          Grenade_Fire
//          Grenade_Holy
//          Grenade_Tangle
//          Grenade_Thunderstone
//          Haste
//          Haste
//          Heal
//          Hold_Animal
//          Hold_Monster
//          Hold_Person
//          Identify
//          Invisibility
//          Lesser_Dispel
//          Lesser_Dispel
//          Lesser_Mind_Blank
//          Lesser_Restoration
//          Lesser_Spell_Mantle
//          Light
//          Light
//          Mage_Armor
//          Manipulate_Portal_Stone
//          Mass_Camoflage
//          Mind_Blank
//          Minor_Globe_of_Invulnerability
//          Minor_Globe_of_Invulnerability
//          Mordenkainens_Disjunction
//          Negative_Energy_Protection
//          Negative_Energy_Protection
//          Negative_Energy_Protection
//          Neutralize_Poison
//          One_With_The_Land
//          Owls_Insight
//          Owls_Wisdom
//          Owls_Wisdom
//          Owls_Wisdom
//          Polymorph_Self
//          Prayer
//          Premonition
//          Protection_From_Elements
//          Protection_From_Elements
//          Protection_from_Spells
//          Protection_from_Spells
//          Raise_Dead
//          Remove_Blindness/Deafness
//          Remove_Curse
//          Remove_Disease
//          Remove_Fear
//          Remove_Paralysis
//          Resist_Elements
//          Resist_Elements
//          Resistance
//          Resistance
//          Restoration
//          Resurrection
//          Rogues_Cunning
//          See_Invisibility
//          Shadow_Shield
//          Shapechange
//          Shield
//          Shield_of_Faith
//          Special_Alcohol_Beer
//          Special_Alcohol_Spirits
//          Special_Alcohol_Wine
//          Special_Herb_Belladonna
//          Special_Herb_Garlic
//          Spell_Mantle
//          Spell_Resistance
//          Spell_Resistance
//          Stoneskin
//          Tensers_Transformation
//          True_Seeing
//          True_Strike
//          Unique_Power
//          Unique_Power_Self_Only
//          Virtue
//
// GENERAL USE (ie. everything else):
//          Just about every spell is useable by all the general use items so instead we
//          will only list the ones that are not allowed:
//          Special_Alcohol_Beer
//          Special_Alcohol_Spirits
//          Special_Alcohol_Wine
//
itemproperty ItemPropertyCastSpell(int nSpell, int nNumUses);

// Returns Item property damage bonus.  You must specify the damage type constant
// (IP_CONST_DAMAGETYPE_*) and the amount of damage constant(IP_CONST_DAMAGEBONUS_*).
// NOTE: not all the damage types will work, use only the following: Acid, Bludgeoning,
//       Cold, Electrical, Fire, Piercing, Slashing, Sonic.
itemproperty ItemPropertyDamageBonus(int nDamageType, int nDamage);

// Returns Item property damage bonus vs. Alignment groups.  You must specify the
// alignment group constant(IP_CONST_ALIGNMENTGROUP_*) and the damage type constant
// (IP_CONST_DAMAGETYPE_*) and the amount of damage constant(IP_CONST_DAMAGEBONUS_*).
// NOTE: not all the damage types will work, use only the following: Acid, Bludgeoning,
//       Cold, Electrical, Fire, Piercing, Slashing, Sonic.
itemproperty ItemPropertyDamageBonusVsAlign(int nAlignGroup, int nDamageType, int nDamage);

// Returns Item property damage bonus vs. specific race.  You must specify the
// racial group constant(IP_CONST_RACIALTYPE_*) and the damage type constant
// (IP_CONST_DAMAGETYPE_*) and the amount of damage constant(IP_CONST_DAMAGEBONUS_*).
// NOTE: not all the damage types will work, use only the following: Acid, Bludgeoning,
//       Cold, Electrical, Fire, Piercing, Slashing, Sonic.
itemproperty ItemPropertyDamageBonusVsRace(int nRace, int nDamageType, int nDamage);

// Returns Item property damage bonus vs. specific alignment.  You must specify the
// specific alignment constant(IP_CONST_ALIGNMENT_*) and the damage type constant
// (IP_CONST_DAMAGETYPE_*) and the amount of damage constant(IP_CONST_DAMAGEBONUS_*).
// NOTE: not all the damage types will work, use only the following: Acid, Bludgeoning,
//       Cold, Electrical, Fire, Piercing, Slashing, Sonic.
itemproperty ItemPropertyDamageBonusVsSAlign(int nAlign, int nDamageType, int nDamage);

// Returns Item property damage immunity.  You must specify the damage type constant
// (IP_CONST_DAMAGETYPE_*) that you want to be immune to and the immune bonus percentage
// constant(IP_CONST_DAMAGEIMMUNITY_*).
// NOTE: not all the damage types will work, use only the following: Acid, Bludgeoning,
//       Cold, Electrical, Fire, Piercing, Slashing, Sonic.
itemproperty ItemPropertyDamageImmunity(int nDamageType, int nImmuneBonus);

// Returns Item property damage penalty.  You must specify the damage penalty.
// The damage penalty should be a POSITIVE integer between 1 and 5 (ie. 1 = -1).
itemproperty ItemPropertyDamagePenalty(int nPenalty);

// Returns Item property damage reduction.  You must specify the enhancment level
// (IP_CONST_DAMAGEREDUCTION_*) that is required to get past the damage reduction
// and the amount of HP of damage constant(IP_CONST_DAMAGESOAK_*) will be soaked
// up if your weapon is not of high enough enhancement.
itemproperty ItemPropertyDamageReduction(int nEnhancement, int nHPSoak);

// Returns Item property damage resistance.  You must specify the damage type
// constant(IP_CONST_DAMAGETYPE_*) and the amount of HP of damage constant
// (IP_CONST_DAMAGERESIST_*) that will be resisted against each round.
itemproperty ItemPropertyDamageResistance(int nDamageType, int nHPResist);

// Returns Item property damage vulnerability.  You must specify the damage type
// constant(IP_CONST_DAMAGETYPE_*) that you want the user to be extra vulnerable to
// and the percentage vulnerability constant(IP_CONST_DAMAGEVULNERABILITY_*).
itemproperty ItemPropertyDamageVulnerability(int nDamageType, int nVulnerability);

// Return Item property Darkvision.
itemproperty ItemPropertyDarkvision();

// Return Item property decrease ability score.  You must specify the ability
// constant(IP_CONST_ABILITY_*) and the modifier constant.  The modifier must be
// a POSITIVE integer between 1 and 10 (ie. 1 = -1).
itemproperty ItemPropertyDecreaseAbility(int nAbility, int nModifier);

// Returns Item property decrease Armor Class.  You must specify the armor
// modifier type constant(IP_CONST_ACMODIFIERTYPE_*) and the armor class penalty.
// The penalty must be a POSITIVE integer between 1 and 5 (ie. 1 = -1).
itemproperty ItemPropertyDecreaseAC(int nModifierType, int nPenalty);

// Returns Item property decrease skill.  You must specify the constant for the
// skill to be decreased(SKILL_*) and the amount of the penalty.  The penalty
// must be a POSITIVE integer between 1 and 10 (ie. 1 = -1).
itemproperty ItemPropertyDecreaseSkill(int nSkill, int nPenalty);

// Returns Item property container reduced weight.  This is used for special
// containers that reduce the weight of the objects inside them.  You must
// specify the container weight reduction type constant(IP_CONST_CONTAINERWEIGHTRED_*).
itemproperty ItemPropertyContainerReducedWeight(int nContainerType);

// Returns Item property extra melee damage type.  You must specify the extra
// melee base damage type that you want applied.  It is a constant(IP_CONST_DAMAGETYPE_*).
// NOTE: only the first 3 base types (piercing, slashing, & bludgeoning are applicable
//       here.
// NOTE: It is also only applicable to melee weapons.
itemproperty ItemPropertyExtraMeleeDamageType(int nDamageType);

// Returns Item property extra ranged damage type.  You must specify the extra
// melee base damage type that you want applied.  It is a constant(IP_CONST_DAMAGETYPE_*).
// NOTE: only the first 3 base types (piercing, slashing, & bludgeoning are applicable
//       here.
// NOTE: It is also only applicable to ranged weapons.
itemproperty ItemPropertyExtraRangeDamageType(int nDamageType);

// Returns Item property haste.
itemproperty ItemPropertyHaste();

// Returns Item property Holy Avenger.
itemproperty ItemPropertyHolyAvenger();

// Returns Item property immunity to miscellaneous effects.  You must specify the
// effect to which the user is immune, it is a constant(IP_CONST_IMMUNITYMISC_*).
itemproperty ItemPropertyImmunityMisc(int nImmunityType);

// Returns Item property improved evasion.
itemproperty ItemPropertyImprovedEvasion();

// Returns Item property bonus spell resistance.  You must specify the bonus spell
// resistance constant(IP_CONST_SPELLRESISTANCEBONUS_*).
itemproperty ItemPropertyBonusSpellResistance(int nBonus);

// Returns Item property saving throw bonus vs. a specific effect or damage type.
// You must specify the save type constant(IP_CONST_SAVEVS_*) that the bonus is
// applied to and the bonus that is be applied.  The bonus must be an integer
// between 1 and 20.
itemproperty ItemPropertyBonusSavingThrowVsX(int nBonusType, int nBonus);

// Returns Item property saving throw bonus to the base type (ie. will, reflex,
// fortitude).  You must specify the base type constant(IP_CONST_SAVEBASETYPE_*)
// to which the user gets the bonus and the bonus that he/she will get.  The
// bonus must be an integer between 1 and 20.
itemproperty ItemPropertyBonusSavingThrow(int nBaseSaveType, int nBonus);

// Returns Item property keen.  This means a critical threat range of 19-20 on a
// weapon will be increased to 17-20 etc.
itemproperty ItemPropertyKeen();

// Returns Item property light.  You must specify the intesity constant of the
// light(IP_CONST_LIGHTBRIGHTNESS_*) and the color constant of the light
// (IP_CONST_LIGHTCOLOR_*).
itemproperty ItemPropertyLight(int nBrightness, int nColor);

// Returns Item property Max range strength modification (ie. mighty).  You must
// specify the maximum modifier for strength that is allowed on a ranged weapon.
// The modifier must be a positive integer between 1 and 20.
itemproperty ItemPropertyMaxRangeStrengthMod(int nModifier);

// Returns Item property no damage.  This means the weapon will do no damage in
// combat.
itemproperty ItemPropertyNoDamage();

// Returns Item property on hit -> do effect property.  You must specify the on
// hit property constant(IP_CONST_ONHIT_*) and the save DC constant(IP_CONST_ONHIT_SAVEDC_*).
// Some of the item properties require a special parameter as well.  If the
// property does not require one you may leave out the last one.  The list of
// the ones with 3 parameters and what they are are as follows:
//      ABILITYDRAIN      :nSpecial is the ability it is to drain.
//                         constant(IP_CONST_ABILITY_*)
//      BLINDNESS         :nSpecial is the duration/percentage of effecting victim.
//                         constant(IP_CONST_ONHIT_DURATION_*)
//      CONFUSION         :nSpecial is the duration/percentage of effecting victim.
//                         constant(IP_CONST_ONHIT_DURATION_*)
//      DAZE              :nSpecial is the duration/percentage of effecting victim.
//                         constant(IP_CONST_ONHIT_DURATION_*)
//      DEAFNESS          :nSpecial is the duration/percentage of effecting victim.
//                         constant(IP_CONST_ONHIT_DURATION_*)
//      DISEASE           :nSpecial is the type of desease that will effect the victim.
//                         constant(DISEASE_*)
//      DOOM              :nSpecial is the duration/percentage of effecting victim.
//                         constant(IP_CONST_ONHIT_DURATION_*)
//      FEAR              :nSpecial is the duration/percentage of effecting victim.
//                         constant(IP_CONST_ONHIT_DURATION_*)
//      HOLD              :nSpecial is the duration/percentage of effecting victim.
//                         constant(IP_CONST_ONHIT_DURATION_*)
//      ITEMPOISON        :nSpecial is the type of poison that will effect the victim.
//                         constant(IP_CONST_POISON_*)
//      SILENCE           :nSpecial is the duration/percentage of effecting victim.
//                         constant(IP_CONST_ONHIT_DURATION_*)
//      SLAYRACE          :nSpecial is the race that will be slain.
//                         constant(IP_CONST_RACIALTYPE_*)
//      SLAYALIGNMENTGROUP:nSpecial is the alignment group that will be slain(ie. chaotic).
//                         constant(IP_CONST_ALIGNMENTGROUP_*)
//      SLAYALIGNMENT     :nSpecial is the specific alignment that will be slain.
//                         constant(IP_CONST_ALIGNMENT_*)
//      SLEEP             :nSpecial is the duration/percentage of effecting victim.
//                         constant(IP_CONST_ONHIT_DURATION_*)
//      SLOW              :nSpecial is the duration/percentage of effecting victim.
//                         constant(IP_CONST_ONHIT_DURATION_*)
//      STUN              :nSpecial is the duration/percentage of effecting victim.
//                         constant(IP_CONST_ONHIT_DURATION_*)
itemproperty ItemPropertyOnHitProps(int nProperty, int nSaveDC, int nSpecial=0);

// Returns Item property reduced saving throw vs. an effect or damage type.  You must
// specify the constant to which the penalty applies(IP_CONST_SAVEVS_*) and the
// penalty to be applied.  The penalty must be a POSITIVE integer between 1 and 20
// (ie. 1 = -1).
itemproperty ItemPropertyReducedSavingThrowVsX(int nBaseSaveType, int nPenalty);

// Returns Item property reduced saving to base type.  You must specify the base
// type to which the penalty applies (ie. will, reflex, or fortitude) and the penalty
// to be applied.  The constant for the base type starts with (IP_CONST_SAVEBASETYPE_*).
// The penalty must be a POSITIVE integer between 1 and 20 (ie. 1 = -1).
itemproperty ItemPropertyReducedSavingThrow(int nBonusType, int nPenalty);

// Returns Item property regeneration.  You must specify the regeneration amount.
// The amount must be an integer between 1 and 20.
itemproperty ItemPropertyRegeneration(int nRegenAmount);

// Returns Item property skill bonus.  You must specify the skill to which the user
// will get a bonus(SKILL_*) and the amount of the bonus.  The bonus amount must
// be an integer between 1 and 50.
itemproperty ItemPropertySkillBonus(int nSkill, int nBonus);

// Returns Item property spell immunity vs. specific spell.  You must specify the
// spell to which the user will be immune(IP_CONST_IMMUNITYSPELL_*).
itemproperty ItemPropertySpellImmunitySpecific(int nSpell);

// Returns Item property spell immunity vs. spell school.  You must specify the
// school to which the user will be immune(IP_CONST_SPELLSCHOOL_*).
itemproperty ItemPropertySpellImmunitySchool(int nSchool);

// Returns Item property Thieves tools.  You must specify the modifier you wish
// the tools to have.  The modifier must be an integer between 1 and 12.
itemproperty ItemPropertyThievesTools(int nModifier);

// Returns Item property Attack bonus.  You must specify an attack bonus.  The bonus
// must be an integer between 1 and 20.
itemproperty ItemPropertyAttackBonus(int nBonus);

// Returns Item property Attack bonus vs. alignment group.  You must specify the
// alignment group constant(IP_CONST_ALIGNMENTGROUP_*) and the attack bonus.  The
// bonus must be an integer between 1 and 20.
itemproperty ItemPropertyAttackBonusVsAlign(int nAlignGroup, int nBonus);

// Returns Item property attack bonus vs. racial group.  You must specify the
// racial group constant(IP_CONST_RACIALTYPE_*) and the attack bonus.  The bonus
// must be an integer between 1 and 20.
itemproperty ItemPropertyAttackBonusVsRace(int nRace, int nBonus);

// Returns Item property attack bonus vs. a specific alignment.  You must specify
// the alignment you want the bonus to work against(IP_CONST_ALIGNMENT_*) and the
// attack bonus.  The bonus must be an integer between 1 and 20.
itemproperty ItemPropertyAttackBonusVsSAlign(int nAlignment, int nBonus);

// Returns Item property attack penalty.  You must specify the attack penalty.
// The penalty must be a POSITIVE integer between 1 and 5 (ie. 1 = -1).
itemproperty ItemPropertyAttackPenalty(int nPenalty);

// Returns Item property unlimited ammo.  If you leave the parameter field blank
// it will be just a normal bolt, arrow, or bullet.  However you may specify that
// you want the ammunition to do special damage (ie. +1d6 Fire, or +1 enhancement
// bonus).  For this parmeter you use the constants beginning with:
//      (IP_CONST_UNLIMITEDAMMO_*).
itemproperty ItemPropertyUnlimitedAmmo(int nAmmoDamage=IP_CONST_UNLIMITEDAMMO_BASIC);

// Returns Item property limit use by alignment group.  You must specify the
// alignment group(s) that you want to be able to use this item(IP_CONST_ALIGNMENTGROUP_*).
itemproperty ItemPropertyLimitUseByAlign(int nAlignGroup);

// Returns Item property limit use by class.  You must specify the class(es) who
// are able to use this item(IP_CONST_CLASS_*).
itemproperty ItemPropertyLimitUseByClass(int nClass);

// Returns Item property limit use by race.  You must specify the race(s) who are
// allowed to use this item(IP_CONST_RACIALTYPE_*).
itemproperty ItemPropertyLimitUseByRace(int nRace);

// Returns Item property limit use by specific alignment.  You must specify the
// alignment(s) of those allowed to use the item(IP_CONST_ALIGNMENT_*).
itemproperty ItemPropertyLimitUseBySAlign(int nAlignment);

// replace this function it does nothing.
itemproperty BadBadReplaceMeThisDoesNothing();

// Returns Item property vampiric regeneration.  You must specify the amount of
// regeneration.  The regen amount must be an integer between 1 and 20.
itemproperty ItemPropertyVampiricRegeneration(int nRegenAmount);

// Returns Item property Trap.  You must specify the trap level constant
// (IP_CONST_TRAPSTRENGTH_*) and the trap type constant(IP_CONST_TRAPTYPE_*).
itemproperty ItemPropertyTrap(int nTrapLevel, int nTrapType);

// Returns Item property true seeing.
itemproperty ItemPropertyTrueSeeing();

// Returns Item property Monster on hit apply effect property.  You must specify
// the property that you want applied on hit.  There are some properties that
// require an additional special parameter to be specified.  The others that
// don't require any additional parameter you may just put in the one.  The
// special cases are as follows:
//      ABILITYDRAIN:nSpecial is the ability to drain.
//                   constant(IP_CONST_ABILITY_*)
//      DISEASE     :nSpecial is the disease that you want applied.
//                   constant(DISEASE_*)
//      LEVELDRAIN  :nSpecial is the number of levels that you want drained.
//                   integer between 1 and 5.
//      POISON      :nSpecial is the type of poison that will effect the victim.
//                   constant(IP_CONST_POISON_*)
//      WOUNDING    :nSpecial is the amount of wounding.
//                   integer between 1 and 5.
// NOTE: Any that do not appear in the above list do not require the second
//       parameter.
// NOTE: These can only be applied to monster NATURAL weapons (ie. bite, claw,
//       gore, and slam).  IT WILL NOT WORK ON NORMAL WEAPONS.
itemproperty ItemPropertyOnMonsterHitProperties(int nProperty, int nSpecial=0);

// Returns Item property turn resistance.  You must specify the resistance bonus.
// The bonus must be an integer between 1 and 50.
itemproperty ItemPropertyTurnResistance(int nModifier);

// Returns Item property Massive Critical.  You must specify the extra damage
// constant(IP_CONST_DAMAGEBONUS_*) of the criticals.
itemproperty ItemPropertyMassiveCritical(int nDamage);

// Returns Item property free action.
itemproperty ItemPropertyFreeAction();

// Returns Item property monster damage.  You must specify the amount of damage
// the monster's attack will do(IP_CONST_MONSTERDAMAGE_*).
// NOTE: These can only be applied to monster NATURAL weapons (ie. bite, claw,
//       gore, and slam).  IT WILL NOT WORK ON NORMAL WEAPONS.
itemproperty ItemPropertyMonsterDamage(int nDamage);

// Returns Item property immunity to spell level.  You must specify the level of
// which that and below the user will be immune.  The level must be an integer
// between 1 and 9.  By putting in a 3 it will mean the user is immune to all
// 3rd level and lower spells.
itemproperty ItemPropertyImmunityToSpellLevel(int nLevel);

// Returns Item property special walk.  If no parameters are specified it will
// automatically use the zombie walk.  This will apply the special walk animation
// to the user.
itemproperty ItemPropertySpecialWalk(int nWalkType=0);

// Returns Item property healers kit.  You must specify the level of the kit.
// The modifier must be an integer between 1 and 12.
itemproperty ItemPropertyHealersKit(int nModifier);

// Returns Item property weight increase.  You must specify the weight increase
// constant(IP_CONST_WEIGHTINCREASE_*).
itemproperty ItemPropertyWeightIncrease(int nWeight);

// ***********************  END OF ITEM PROPERTY FUNCTIONS  **************************

// Returns true if 1d20 roll + skill rank is greater than or equal to difficulty
// - oTarget: the creature using the skill
// - nSkill: the skill being used
// - nDifficulty: Difficulty class of skill
int GetIsSkillSuccessful(object oTarget, int nSkill, int nDifficulty);

// Creates an effect that inhibits spells
// - nPercent - percentage of failure
// - nSpellSchool - the school of spells affected.
effect EffectSpellFailure(int nPercent=100, int nSpellSchool=SPELL_SCHOOL_GENERAL);

// Causes the object to instantly speak a translated string.
// (not an action, not blocked when uncommandable)
// - nStrRef: Reference of the string in the talk table
// - nTalkVolume: TALKVOLUME_*
void SpeakStringByStrRef(int nStrRef, int nTalkVolume=TALKVOLUME_TALK);

// Sets the given creature into cutscene mode.  This prevents the player from
// using the GUI and camera controls.
// - oCreature: creature in a cutscene
// - nInCutscene: TRUE to move them into cutscene, FALSE to remove cutscene mode
// - nLeftClickingEnabled: TRUE to allow the user to interact with the game world using the left mouse button only.
//                         FALSE to stop the user from interacting with the game world.
// Note: SetCutsceneMode(oPlayer, TRUE) will also make the player 'plot' (unkillable).
// SetCutsceneMode(oPlayer, FALSE) will restore the player's plot flag to what it
// was when SetCutsceneMode(oPlayer, TRUE) was called.
void SetCutsceneMode(object oCreature, int nInCutscene=TRUE, int nLeftClickingEnabled=FALSE);

// Gets the last player character to cancel from a cutscene.
object GetLastPCToCancelCutscene();

// Gets the length of the specified wavefile, in seconds
// Only works for sounds used for dialog.
float GetDialogSoundLength(int nStrRef);

// Fades the screen for the given creature/player from black to regular screen
// - oCreature: creature controlled by player that should fade from black
void FadeFromBlack(object oCreature, float fSpeed=FADE_SPEED_MEDIUM);

// Fades the screen for the given creature/player from regular screen to black
// - oCreature: creature controlled by player that should fade to black
void FadeToBlack(object oCreature, float fSpeed=FADE_SPEED_MEDIUM);

// Removes any fading or black screen.
// - oCreature: creature controlled by player that should be cleared
void StopFade(object oCreature);

// Sets the screen to black.  Can be used in preparation for a fade-in (FadeFromBlack)
// Can be cleared by either doing a FadeFromBlack, or by calling StopFade.
// - oCreature: creature controlled by player that should see black screen
void BlackScreen(object oCreature);

// Returns the base attach bonus for the given creature.
int GetBaseAttackBonus(object oCreature);

// Set a creature's immortality flag.
// -oCreature: creature affected
// -bImmortal: TRUE = creature is immortal and cannot be killed (but still takes damage)
//             FALSE = creature is not immortal and is damaged normally.
// This scripting command only works on Creature objects.
void SetImmortal(object oCreature, int bImmortal);

// Open's this creature's inventory panel for this player
// - oCreature: creature to view
// - oPlayer: the owner of this creature will see the panel pop up
// * DM's can view any creature's inventory
// * Players can view their own inventory, or that of their henchman, familiar or animal companion
void OpenInventory(object oCreature, object oPlayer);

// Stores the current camera mode and position so that it can be restored (using
// RestoreCameraFacing())
void StoreCameraFacing();

// Restores the camera mode and position to what they were last time StoreCameraFacing
// was called.  RestoreCameraFacing can only be called once, and must correspond to a
// previous call to StoreCameraFacing.
void RestoreCameraFacing();

// Levels up a creature using default settings.
// If successfull it returns the level the creature now is, or 0 if it fails.
// If you want to give them a different level (ie: Give a Fighter a level of Wizard)
//    you can specify that in the nClass.
// However, if you specify a class to which the creature no package specified,
//   they will use the default package for that class for their levelup choices.
//   (ie: no Barbarian Savage/Wizard Divination combinations)
// If you turn on bReadyAllSpells, all memorized spells will be ready to cast without resting.
// if nPackage is PACKAGE_INVALID then it will use the starting package assigned to that class or just the class package
int LevelUpHenchman(object oCreature, int nClass = CLASS_TYPE_INVALID, int bReadyAllSpells = FALSE, int nPackage = PACKAGE_INVALID);

// Sets the droppable flag on an item
// - oItem: the item to change
// - bDroppable: TRUE or FALSE, whether the item should be droppable
// Droppable items will appear on a creature's remains when the creature is killed.
void SetDroppableFlag(object oItem, int bDroppable);

// Gets the weight of an item, or the total carried weight of a creature in tenths
// of pounds (as per the baseitems.2da).
// - oTarget: the item or creature for which the weight is needed
int GetWeight(object oTarget=OBJECT_SELF);

// Gets the object that acquired the module item.  May be a creature, item, or placeable
object GetModuleItemAcquiredBy();

// Get the immortal flag on a creature
int GetImmortal(object oTarget=OBJECT_SELF);

// Does a single attack on every hostile creature within 10ft. of the attacker
// and determines damage accordingly.  If the attacker has a ranged weapon
// equipped, this will have no effect.
// ** NOTE ** This is meant to be called inside the spell script for whirlwind
// attack, it is not meant to be used to queue up a new whirlwind attack.  To do
// that you need to call ActionUseFeat(FEAT_WHIRLWIND_ATTACK, oEnemy)
// - int bDisplayFeedback: TRUE or FALSE, whether or not feedback should be
//   displayed
// - int bImproved: If TRUE, the improved version of whirlwind is used
void DoWhirlwindAttack(int bDisplayFeedback=TRUE, int bImproved=FALSE);

// Gets a value from a 2DA file on the server and returns it as a string
// avoid using this function in loops
// - s2DA: the name of the 2da file, 16 chars max
// - sColumn: the name of the column in the 2da
// - nRow: the row in the 2da
// * returns an empty string if file, row, or column not found
string Get2DAString(string s2DA, string sColumn, int nRow);

// Returns an effect of type EFFECT_TYPE_ETHEREAL which works just like EffectSanctuary
// except that the observers get no saving throw
effect EffectEthereal();

// Gets the current AI Level that the creature is running at.
// Returns one of the following:
// AI_LEVEL_INVALID, AI_LEVEL_VERY_LOW, AI_LEVEL_LOW, AI_LEVEL_NORMAL, AI_LEVEL_HIGH, AI_LEVEL_VERY_HIGH
int GetAILevel(object oTarget=OBJECT_SELF);

// Sets the current AI Level of the creature to the value specified. Does not work on Players.
// The game by default will choose an appropriate AI level for
// creatures based on the circumstances that the creature is in.
// Explicitly setting an AI level will over ride the game AI settings.
// The new setting will last until SetAILevel is called again with the argument AI_LEVEL_DEFAULT.
// AI_LEVEL_DEFAULT  - Default setting. The game will take over seting the appropriate AI level when required.
// AI_LEVEL_VERY_LOW - Very Low priority, very stupid, but low CPU usage for AI. Typically used when no players are in the area.
// AI_LEVEL_LOW      - Low priority, mildly stupid, but slightly more CPU usage for AI. Typically used when not in combat, but a player is in the area.
// AI_LEVEL_NORMAL   - Normal priority, average AI, but more CPU usage required for AI. Typically used when creature is in combat.
// AI_LEVEL_HIGH     - High priority, smartest AI, but extremely high CPU usage required for AI. Avoid using this. It is most likely only ever needed for cutscenes.
void SetAILevel(object oTarget, int nAILevel);

// This will return TRUE if the creature running the script is a familiar currently
// possessed by his master.
// returns FALSE if not or if the creature object is invalid
int GetIsPossessedFamiliar(object oCreature);

// This will cause a Player Creature to unpossess his/her familiar.  It will work if run
// on the player creature or the possessed familiar.  It does not work in conjunction with
// any DM possession.
void UnpossessFamiliar(object oCreature);

// This will return TRUE if the area is flagged as either interior or underground.
int GetIsAreaInterior( object oArea = OBJECT_INVALID );

// Send a server message (szMessage) to the oPlayer.
void SendMessageToPCByStrRef(object oPlayer, int nStrRef);

// Increment the remaining uses per day for this creature by one.
// Total number of feats per day can not exceed the maximum.
// - oCreature: creature to modify
// - nFeat: constant FEAT_*
void IncrementRemainingFeatUses(object oCreature, int nFeat);

// Force the character of the player specified to be exported to its respective directory
// i.e. LocalVault/ServerVault/ etc.
void ExportSingleCharacter(object oPlayer);

// This will play a sound that is associated with a stringRef, it will be a mono sound from the location of the object running the command.
// if nRunAsAction is off then the sound is forced to play intantly.
void PlaySoundByStrRef(int nStrRef, int nRunAsAction = TRUE );

// Set the name of oCreature's sub race to sSubRace.
void SetSubRace(object oCreature, string sSubRace);

// Set the name of oCreature's Deity to sDeity.
void SetDeity(object oCreature, string sDeity);

// Returns TRUE if the creature oCreature is currently possessed by a DM character.
// Returns FALSE otherwise.
// Note: GetIsDMPossessed() will return FALSE if oCreature is the DM character.
// To determine if oCreature is a DM character use GetIsDM()
int GetIsDMPossessed(object oCreature);

// Gets the current weather conditions for the area oArea.
//   Returns: WEATHER_CLEAR, WEATHER_RAIN, WEATHER_SNOW, WEATHER_INVALID
//   Note: If called on an Interior area, this will always return WEATHER_CLEAR.
int GetWeather(object oArea);

// Returns AREA_NATURAL if the area oArea is natural, AREA_ARTIFICIAL otherwise.
// Returns AREA_INVALID, on an error.
int GetIsAreaNatural(object oArea);

// Returns AREA_ABOVEGROUND if the area oArea is above ground, AREA_UNDERGROUND otherwise.
// Returns AREA_INVALID, on an error.
int GetIsAreaAboveGround(object oArea);

// Use this to get the item last equipped by a player character in OnPlayerEquipItem..
object GetPCItemLastEquipped();

// Use this to get the player character who last equipped an item in OnPlayerEquipItem..
object GetPCItemLastEquippedBy();

// Use this to get the item last unequipped by a player character in OnPlayerEquipItem..
object GetPCItemLastUnequipped();

// Use this to get the player character who last unequipped an item in OnPlayerUnEquipItem..
object GetPCItemLastUnequippedBy();

// Creates a new copy of an item, while making a single change to the appearance of the item.
// Helmet models and simple items ignore iIndex.
// iType                            iIndex                      iNewValue
// ITEM_APPR_TYPE_SIMPLE_MODEL      [Ignored]                   Model #
// ITEM_APPR_TYPE_WEAPON_COLOR      ITEM_APPR_WEAPON_COLOR_*    1-4
// ITEM_APPR_TYPE_WEAPON_MODEL      ITEM_APPR_WEAPON_MODEL_*    Model #
// ITEM_APPR_TYPE_ARMOR_MODEL       ITEM_APPR_ARMOR_MODEL_*     Model #
// ITEM_APPR_TYPE_ARMOR_COLOR       ITEM_APPR_ARMOR_COLOR_*     0-175
object CopyItemAndModify(object oItem, int nType, int nIndex, int nNewValue, int bCopyVars=FALSE);

// Queries the current value of the appearance settings on an item. The parameters are
// identical to those of CopyItemAndModify().
int GetItemAppearance(object oItem, int nType, int nIndex);

// Creates an item property that (when applied to a weapon item) causes a spell to be cast
// when a successful strike is made, or (when applied to armor) is struck by an opponent.
// - nSpell uses the IP_CONST_ONHIT_CASTSPELL_* constants
itemproperty ItemPropertyOnHitCastSpell(int nSpell, int nLevel);

// Returns the SubType number of the item property. See the 2DA files for value definitions.
int GetItemPropertySubType(itemproperty iProperty);

// Gets the status of ACTION_MODE_* modes on a creature.
int GetActionMode(object oCreature, int nMode);

// Sets the status of modes ACTION_MODE_* on a creature.
void SetActionMode(object oCreature, int nMode, int nStatus);

// Returns the current arcane spell failure factor of a creature
int GetArcaneSpellFailure(object oCreature);

// Makes a player examine the object oExamine. This causes the examination
// pop-up box to appear for the object specified.
void ActionExamine(object oExamine);

// Creates a visual effect (ITEM_VISUAL_*) that may be applied to
// melee weapons only.
itemproperty ItemPropertyVisualEffect(int nEffect);

// Sets the lootable state of a *living* NPC creature.
// This function will *not* work on players or dead creatures.
void SetLootable( object oCreature, int bLootable );

// Returns the lootable state of a creature.
int GetLootable( object oCreature );

// Returns the current movement rate factor
// of the cutscene 'camera man'.
// NOTE: This will be a value between 0.1, 2.0 (10%-200%)
float GetCutsceneCameraMoveRate( object oCreature );

// Sets the current movement rate factor for the cutscene
// camera man.
// NOTE: You can only set values between 0.1, 2.0 (10%-200%)
void SetCutsceneCameraMoveRate( object oCreature, float fRate );

// Returns TRUE if the item is cursed and cannot be dropped
int GetItemCursedFlag(object oItem);

// When cursed, items cannot be dropped
void SetItemCursedFlag(object oItem, int nCursed);

// Sets the maximum number of henchmen
void SetMaxHenchmen( int nNumHenchmen );

// Gets the maximum number of henchmen
int GetMaxHenchmen();

// Returns the associate type of the specified creature.
// - Returns ASSOCIATE_TYPE_NONE if the creature is not the associate of anyone.
int GetAssociateType( object oAssociate );

// Returns the spell resistance of the specified creature.
// - Returns 0 if the creature has no spell resistance or an invalid
//   creature is passed in.
int GetSpellResistance( object oCreature );

// Changes the current Day/Night cycle for this player to night
// - oPlayer: which player to change the lighting for
// - fTransitionTime: how long the transition should take
void DayToNight(object oPlayer, float fTransitionTime=0.0f);

// Changes the current Day/Night cycle for this player to daylight
// - oPlayer: which player to change the lighting for
// - fTransitionTime: how long the transition should take
void NightToDay(object oPlayer, float fTransitionTime=0.0f);

// Returns whether or not there is a direct line of sight
// between the two objects. (Not blocked by any geometry).
//
// PLEASE NOTE: This is an expensive function and may
//              degrade performance if used frequently.
int LineOfSightObject( object oSource, object oTarget );

// Returns whether or not there is a direct line of sight
// between the two vectors. (Not blocked by any geometry).
//
// This function must be run on a valid object in the area
// it will not work on the module or area.
//
// PLEASE NOTE: This is an expensive function and may
//              degrade performance if used frequently.
int LineOfSightVector( vector vSource, vector vTarget );

// Returns the class that the spellcaster cast the
// spell as.
// - Returns CLASS_TYPE_INVALID if the caster has
//   no valid class (placeables, etc...)
int GetLastSpellCastClass();

// Sets the number of base attacks for the specified
// creatures. The range of values accepted are from
// 1 to 6
// Note: This function does not work on Player Characters
void SetBaseAttackBonus( int nBaseAttackBonus, object oCreature = OBJECT_SELF );

// Restores the number of base attacks back to it's
// original state.
void RestoreBaseAttackBonus( object oCreature = OBJECT_SELF );

// Creates a cutscene ghost effect, this will allow creatures
// to pathfind through other creatures without bumping into them
// for the duration of the effect.
effect EffectCutsceneGhost();

// Creates an item property that offsets the effect on arcane spell failure
// that a particular item has. Parameters come from the ITEM_PROP_ASF_* group.
itemproperty ItemPropertyArcaneSpellFailure(int nModLevel);

// Returns the amount of gold a store currently has. -1 indicates it is not using gold.
// -2 indicates the store could not be located.
int GetStoreGold(object oidStore);

// Sets the amount of gold a store has. -1 means the store does not use gold.
void SetStoreGold(object oidStore, int nGold);

// Gets the maximum amount a store will pay for any item. -1 means price unlimited.
// -2 indicates the store could not be located.
int GetStoreMaxBuyPrice(object oidStore);

// Sets the maximum amount a store will pay for any item. -1 means price unlimited.
void SetStoreMaxBuyPrice(object oidStore, int nMaxBuy);

// Gets the amount a store charges for identifying an item. Default is 100. -1 means
// the store will not identify items.
// -2 indicates the store could not be located.
int GetStoreIdentifyCost(object oidStore);

// Sets the amount a store charges for identifying an item. Default is 100. -1 means
// the store will not identify items.
void SetStoreIdentifyCost(object oidStore, int nCost);

// Sets the creature's appearance type to the value specified (uses the APPEARANCE_TYPE_XXX constants)
void SetCreatureAppearanceType(object oCreature, int nAppearanceType);

// Returns the default package selected for this creature to level up with
// - returns PACKAGE_INVALID if error occurs
int GetCreatureStartingPackage(object oCreature);

// Returns an effect that when applied will paralyze the target's legs, rendering
// them unable to walk but otherwise unpenalized. This effect cannot be resisted.
effect EffectCutsceneImmobilize();

// Is this creature in the given subarea? (trigger, area of effect object, etc..)
// This function will tell you if the creature has triggered an onEnter event,
// not if it is physically within the space of the subarea
int GetIsInSubArea(object oCreature, object oSubArea=OBJECT_SELF);

// Returns the Cost Table number of the item property. See the 2DA files for value definitions.
int GetItemPropertyCostTable(itemproperty iProp);

// Returns the Cost Table value (index of the cost table) of the item property.
// See the 2DA files for value definitions.
int GetItemPropertyCostTableValue(itemproperty iProp);

// Returns the Param1 number of the item property. See the 2DA files for value definitions.
int GetItemPropertyParam1(itemproperty iProp);

// Returns the Param1 value of the item property. See the 2DA files for value definitions.
int GetItemPropertyParam1Value(itemproperty iProp);

// Is this creature able to be disarmed? (checks disarm flag on creature, and if
// the creature actually has a weapon equipped in their right hand that is droppable)
int GetIsCreatureDisarmable(object oCreature);

// Sets whether this item is 'stolen' or not
void SetStolenFlag(object oItem, int nStolenFlag);

// Instantly gives this creature the benefits of a rest (restored hitpoints, spells, feats, etc..)
void ForceRest(object oCreature);

// Forces this player's camera to be set to this height. Setting this value to zero will
// restore the camera to the racial default height.
void SetCameraHeight(object oPlayer, float fHeight=0.0f);

// Changes the sky that is displayed in the specified area.
// nSkyBox = SKYBOX_* constants (associated with skyboxes.2da)
// If no valid area (or object) is specified, it uses the area of caller.
// If an object other than an area is specified, will use the area that the object is currently in.
void SetSkyBox(int nSkyBox, object oArea=OBJECT_INVALID);

// Returns the creature's currently set PhenoType (body type).
int GetPhenoType(object oCreature);

// Sets the creature's PhenoType (body type) to the type specified.
// nPhenoType = PHENOTYPE_NORMAL
// nPhenoType = PHENOTYPE_BIG
// nPhenoType = PHENOTYPE_CUSTOM* - The custom PhenoTypes should only ever
// be used if you have specifically created your own custom content that
// requires the use of a new PhenoType and you have specified the appropriate
// custom PhenoType in your custom content.
// SetPhenoType will only work on part based creature (i.e. the starting
// default playable races).
void SetPhenoType(int nPhenoType, object oCreature=OBJECT_SELF);

// Sets the fog color in the area specified.
// nFogType = FOG_TYPE_* specifies wether the Sun, Moon, or both fog types are set.
// nFogColor = FOG_COLOR_* specifies the color the fog is being set to.
// The fog color can also be represented as a hex RGB number if specific color shades
// are desired.
// The format of a hex specified color would be 0xFFEEDD where
// FF would represent the amount of red in the color
// EE would represent the amount of green in the color
// DD would represent the amount of blue in the color.
// If no valid area (or object) is specified, it uses the area of caller.
// If an object other than an area is specified, will use the area that the object is currently in.
void SetFogColor(int nFogType, int nFogColor, object oArea=OBJECT_INVALID);

// Gets the current cutscene state of the player specified by oCreature.
// Returns TRUE if the player is in cutscene mode.
// Returns FALSE if the player is not in cutscene mode, or on an error
// (such as specifying a non creature object).
int GetCutsceneMode(object oCreature=OBJECT_SELF);

// Gets the skybox that is currently displayed in the specified area.
// Returns:
//     SKYBOX_* constant
// If no valid area (or object) is specified, it uses the area of caller.
// If an object other than an area is specified, will use the area that the object is currently in.
int GetSkyBox(object oArea=OBJECT_INVALID);

// Gets the fog color in the area specified.
// nFogType specifies wether the Sun, or Moon fog type is returned. 
//    Valid values for nFogType are FOG_TYPE_SUN or FOG_TYPE_MOON.
// If no valid area (or object) is specified, it uses the area of caller.
// If an object other than an area is specified, will use the area that the object is currently in.
int GetFogColor(int nFogType, object oArea=OBJECT_INVALID);

// Sets the fog amount in the area specified.
// nFogType = FOG_TYPE_* specifies wether the Sun, Moon, or both fog types are set.
// nFogAmount = specifies the density that the fog is being set to.
// If no valid area (or object) is specified, it uses the area of caller.
// If an object other than an area is specified, will use the area that the object is currently in.
void SetFogAmount(int nFogType, int nFogAmount, object oArea=OBJECT_INVALID);

// Gets the fog amount in the area specified.
// nFogType = nFogType specifies wether the Sun, or Moon fog type is returned. 
//    Valid values for nFogType are FOG_TYPE_SUN or FOG_TYPE_MOON.
// If no valid area (or object) is specified, it uses the area of caller.
// If an object other than an area is specified, will use the area that the object is currently in.
int GetFogAmount(int nFogType, object oArea=OBJECT_INVALID);

// returns TRUE if the item CAN be pickpocketed
int GetPickpocketableFlag(object oItem);

// Sets the Pickpocketable flag on an item
// - oItem: the item to change
// - bPickpocketable: TRUE or FALSE, whether the item can be pickpocketed.
void SetPickpocketableFlag(object oItem, int bPickpocketable);

// returns the footstep type of the creature specified.
// The footstep type determines what the creature's footsteps sound
// like when ever they take a step.
// returns FOOTSTEP_TYPE_INVALID if used on a non-creature object, or if
// used on creature that has no footstep sounds by default (e.g. Will-O'-Wisp).
int GetFootstepType(object oCreature=OBJECT_SELF);

// Sets the footstep type of the creature specified.
// Changing a creature's footstep type will change the sound that
// its feet make when ever the creature makes takes a step.
// By default a creature's footsteps are detemined by the appearance
// type of the creature. SetFootstepType() allows you to make a
// creature use a difference footstep type than it would use by default
// for its given appearance.
// - nFootstepType (FOOTSTEP_TYPE_*):
//      FOOTSTEP_TYPE_NORMAL
//      FOOTSTEP_TYPE_LARGE
//      FOOTSTEP_TYPE_DRAGON
//      FOOTSTEP_TYPE_SoFT
//      FOOTSTEP_TYPE_HOOF
//      FOOTSTEP_TYPE_HOOF_LARGE
//      FOOTSTEP_TYPE_BEETLE
//      FOOTSTEP_TYPE_SPIDER
//      FOOTSTEP_TYPE_SKELETON
//      FOOTSTEP_TYPE_LEATHER_WING
//      FOOTSTEP_TYPE_FEATHER_WING
//      FOOTSTEP_TYPE_DEFAULT - Makes the creature use its original default footstep sounds.
//      FOOTSTEP_TYPE_NONE
// - oCreature: the creature to change the footstep sound for.
void SetFootstepType(int nFootstepType, object oCreature=OBJECT_SELF);

// returns the Wing type of the creature specified.
//      CREATURE_WING_TYPE_NONE
//      CREATURE_WING_TYPE_DEMON
//      CREATURE_WING_TYPE_ANGEL
//      CREATURE_WING_TYPE_BAT
//      CREATURE_WING_TYPE_DRAGON
//      CREATURE_WING_TYPE_BUTTERFLY
//      CREATURE_WING_TYPE_BIRD
// returns CREATURE_WING_TYPE_NONE if used on a non-creature object,
// if the creature has no wings, or if the creature can not have its
// wing type changed in the toolset.
int GetCreatureWingType(object oCreature=OBJECT_SELF);

// Sets the Wing type of the creature specified.
// - nWingType (CREATURE_WING_TYPE_*)
//      CREATURE_WING_TYPE_NONE
//      CREATURE_WING_TYPE_DEMON
//      CREATURE_WING_TYPE_ANGEL
//      CREATURE_WING_TYPE_BAT
//      CREATURE_WING_TYPE_DRAGON
//      CREATURE_WING_TYPE_BUTTERFLY
//      CREATURE_WING_TYPE_BIRD
// - oCreature: the creature to change the wing type for.
// Note: Only two creature model types will support wings. 
// The MODELTYPE for the part based (playable races) 'P' 
// and MODELTYPE 'W'in the appearance.2da
void SetCreatureWingType(int nWingType, object oCreature=OBJECT_SELF);

// returns the model number being used for the body part and creature specified
// The model number returned is for the body part when the creature is not wearing
// armor (i.e. whether or not the creature is wearing armor does not affect
// the return value).
// Note: Only works on part based creatures, which is typically restricted to
// the playable races (unless some new part based custom content has been 
// added to the module).
//
// returns CREATURE_PART_INVALID if used on a non-creature object,
// or if the creature does not use a part based model.
//
// - nPart (CREATURE_PART_*)
//      CREATURE_PART_RIGHT_FOOT
//      CREATURE_PART_LEFT_FOOT
//      CREATURE_PART_RIGHT_SHIN
//      CREATURE_PART_LEFT_SHIN
//      CREATURE_PART_RIGHT_THIGH
//      CREATURE_PART_LEFT_THIGH
//      CREATURE_PART_PELVIS
//      CREATURE_PART_TORSO
//      CREATURE_PART_BELT
//      CREATURE_PART_NECK
//      CREATURE_PART_RIGHT_FOREARM
//      CREATURE_PART_LEFT_FOREARM
//      CREATURE_PART_RIGHT_BICEP
//      CREATURE_PART_LEFT_BICEP
//      CREATURE_PART_RIGHT_SHOULDER
//      CREATURE_PART_LEFT_SHOULDER
//      CREATURE_PART_RIGHT_HAND
//      CREATURE_PART_LEFT_HAND
//      CREATURE_PART_HEAD
int GetCreatureBodyPart(int nPart, object oCreature=OBJECT_SELF);

// Sets the body part model to be used on the creature specified.
// The model names for parts need to be in the following format:
//   p<m/f><race letter><phenotype>_<body part><model number>.mdl
//
// - nPart (CREATURE_PART_*)
//      CREATURE_PART_RIGHT_FOOT
//      CREATURE_PART_LEFT_FOOT
//      CREATURE_PART_RIGHT_SHIN
//      CREATURE_PART_LEFT_SHIN
//      CREATURE_PART_RIGHT_THIGH
//      CREATURE_PART_LEFT_THIGH
//      CREATURE_PART_PELVIS
//      CREATURE_PART_TORSO
//      CREATURE_PART_BELT
//      CREATURE_PART_NECK
//      CREATURE_PART_RIGHT_FOREARM
//      CREATURE_PART_LEFT_FOREARM
//      CREATURE_PART_RIGHT_BICEP
//      CREATURE_PART_LEFT_BICEP
//      CREATURE_PART_RIGHT_SHOULDER
//      CREATURE_PART_LEFT_SHOULDER
//      CREATURE_PART_RIGHT_HAND
//      CREATURE_PART_LEFT_HAND
//      CREATURE_PART_HEAD
// - nModelNumber: CREATURE_MODEL_TYPE_*
//      CREATURE_MODEL_TYPE_NONE
//      CREATURE_MODEL_TYPE_SKIN (not for use on shoulders, pelvis or head).
//      CREATURE_MODEL_TYPE_TATTOO (for body parts that support tattoos, i.e. not heads/feet/hands).
//      CREATURE_MODEL_TYPE_UNDEAD (undead model only exists for the right arm parts).
// - oCreature: the creature to change the body part for.
// Note: Only part based creature appearance types are supported. 
// i.e. The model types for the playable races ('P') in the appearance.2da
void SetCreatureBodyPart(int nPart, int nModelNumber, object oCreature=OBJECT_SELF);

// returns the Tail type of the creature specified.
//      CREATURE_TAIL_TYPE_NONE
//      CREATURE_TAIL_TYPE_LIZARD
//      CREATURE_TAIL_TYPE_BONE
//      CREATURE_TAIL_TYPE_DEVIL
// returns CREATURE_TAIL_TYPE_NONE if used on a non-creature object,
// if the creature has no Tail, or if the creature can not have its
// Tail type changed in the toolset.
int GetCreatureTailType(object oCreature=OBJECT_SELF);

// Sets the Tail type of the creature specified.
// - nTailType (CREATURE_TAIL_TYPE_*)
//      CREATURE_TAIL_TYPE_NONE
//      CREATURE_TAIL_TYPE_LIZARD
//      CREATURE_TAIL_TYPE_BONE
//      CREATURE_TAIL_TYPE_DEVIL
// - oCreature: the creature to change the Tail type for.
// Note: Only two creature model types will support Tails. 
// The MODELTYPE for the part based (playable) races 'P' 
// and MODELTYPE 'T'in the appearance.2da
void SetCreatureTailType(int nTailType, object oCreature=OBJECT_SELF);

// returns the Hardness of a Door or Placeable object.
// - oObject: a door or placeable object.
// returns -1 on an error or if used on an object that is
// neither a door nor a placeable object.
int GetHardness(object oObject=OBJECT_SELF);

// Sets the Hardness of a Door or Placeable object.
// - nHardness: must be between 0 and 250.
// - oObject: a door or placeable object.
// Does nothing if used on an object that is neither
// a door nor a placeable.
void SetHardness(int nHardness, object oObject=OBJECT_SELF);

// When set the object can not be opened unless the
// opener possesses the required key. The key tag required
// can be specified either in the toolset, or by using
// the SetLockKeyTag() scripting command.
// - oObject: a door, or placeable.
// - nKeyRequired: TRUE/FALSE
void SetLockKeyRequired(object oObject, int nKeyRequired=TRUE);

// Set the key tag required to open object oObject.
// This will only have an effect if the object is set to
// "Key required to unlock or lock" either in the toolset
// or by using the scripting command SetLockKeyRequired().
// - oObject: a door, placeable or trigger.
// - sNewKeyTag: the key tag required to open the locked object.
void SetLockKeyTag(object oObject, string sNewKeyTag);

// Sets whether or not the object can be locked.
// - oObject: a door or placeable.
// - nLockable: TRUE/FALSE
void SetLockLockable(object oObject, int nLockable=TRUE);

// Sets the DC for unlocking the object.
// - oObject: a door or placeable object.
// - nNewUnlockDC: must be between 0 and 250.
void SetLockUnlockDC(object oObject, int nNewUnlockDC);

// Sets the DC for locking the object.
// - oObject: a door or placeable object.
// - nNewLockDC: must be between 0 and 250.
void SetLockLockDC(object oObject, int nNewLockDC);

// Sets whether or not the trapped object can be disarmed.
// - oTrapObject: a placeable, door or trigger
// - nDisarmable: TRUE/FALSE
void SetTrapDisarmable(object oTrapObject, int nDisarmable=TRUE);

// Sets whether or not the trapped object can be detected.
// - oTrapObject: a placeable, door or trigger
// - nDetectable: TRUE/FALSE
// Note: Setting a trapped object to not be detectable will
// not make the trap disappear if it has already been detected.
void SetTrapDetectable(object oTrapObject, int nDetectable=TRUE);

// Sets whether or not the trap is a one-shot trap
// (i.e. whether or not the trap resets itself after firing).
// - oTrapObject: a placeable, door or trigger
// - nOneShot: TRUE/FALSE
void SetTrapOneShot(object oTrapObject, int nOneShot=TRUE);

// Set the tag of the key that will disarm oTrapObject.
// - oTrapObject: a placeable, door or trigger
void SetTrapKeyTag(object oTrapObject, string sKeyTag);

// Set the DC for disarming oTrapObject.
// - oTrapObject: a placeable, door or trigger
// - nDisarmDC: must be between 0 and 250.
void SetTrapDisarmDC(object oTrapObject, int nDisarmDC);

// Set the DC for detecting oTrapObject.
// - oTrapObject: a placeable, door or trigger
// - nDetectDC: must be between 0 and 250.
void SetTrapDetectDC(object oTrapObject, int nDetectDC);

// Creates a square Trap object.
// - nTrapType: The base type of trap (TRAP_BASE_TYPE_*)
// - lLocation: The location and orientation that the trap will be created at.
// - fSize: The size of the trap. Minimum size allowed is 1.0f.
// - sTag: The tag of the trap being created.
// - nFaction: The faction of the trap (STANDARD_FACTION_*).
// - sOnDisarmScript: The OnDisarm script that will fire when the trap is disarmed.
//                    If "" no script will fire.
// - sOnTrapTriggeredScript: The OnTrapTriggered script that will fire when the
//                           trap is triggered.
//                           If "" the default OnTrapTriggered script for the trap
//                           type specified will fire instead (as specified in the
//                           traps.2da).
object CreateTrapAtLocation(int nTrapType, location lLocation, float fSize=2.0f, string sTag="", int nFaction=STANDARD_FACTION_HOSTILE, string sOnDisarmScript="", string sOnTrapTriggeredScript="");

// Creates a Trap on the object specified.
// - nTrapType: The base type of trap (TRAP_BASE_TYPE_*)
// - oObject: The object that the trap will be created on. Works only on Doors and Placeables.
// - nFaction: The faction of the trap (STANDARD_FACTION_*).
// - sOnDisarmScript: The OnDisarm script that will fire when the trap is disarmed.
//                    If "" no script will fire.
// - sOnTrapTriggeredScript: The OnTrapTriggered script that will fire when the
//                           trap is triggered.
//                           If "" the default OnTrapTriggered script for the trap
//                           type specified will fire instead (as specified in the
//                           traps.2da).
// Note: After creating a trap on an object, you can change the trap's properties
//       using the various SetTrap* scripting commands by passing in the object
//       that the trap was created on (i.e. oObject) to any subsequent SetTrap* commands.
void CreateTrapOnObject(int nTrapType, object oObject, int nFaction=STANDARD_FACTION_HOSTILE, string sOnDisarmScript="", string sOnTrapTriggeredScript="");

// Set the Will saving throw value of the Door or Placeable object oObject.
// - oObject: a door or placeable object.
// - nWillSave: must be between 0 and 250.
void SetWillSavingThrow(object oObject, int nWillSave);

// Set the Reflex saving throw value of the Door or Placeable object oObject.
// - oObject: a door or placeable object.
// - nReflexSave: must be between 0 and 250.
void SetReflexSavingThrow(object oObject, int nReflexSave);

// Set the Fortitude saving throw value of the Door or Placeable object oObject.
// - oObject: a door or placeable object.
// - nFortitudeSave: must be between 0 and 250.
void SetFortitudeSavingThrow(object oObject, int nFortitudeSave);

// returns the resref (TILESET_RESREF_*) of the tileset used to create area oArea.
//      TILESET_RESREF_BEHOLDER_CAVES
//      TILESET_RESREF_CASTLE_INTERIOR
//      TILESET_RESREF_CITY_EXTERIOR
//      TILESET_RESREF_CITY_INTERIOR
//      TILESET_RESREF_CRYPT
//      TILESET_RESREF_DESERT
//      TILESET_RESREF_DROW_INTERIOR
//      TILESET_RESREF_DUNGEON
//      TILESET_RESREF_FOREST
//      TILESET_RESREF_FROZEN_WASTES
//      TILESET_RESREF_ILLITHID_INTERIOR
//      TILESET_RESREF_MICROSET
//      TILESET_RESREF_MINES_AND_CAVERNS
//      TILESET_RESREF_RUINS
//      TILESET_RESREF_RURAL
//      TILESET_RESREF_RURAL_WINTER
//      TILESET_RESREF_SEWERS
//      TILESET_RESREF_UNDERDARK
// * returns an empty string on an error.
string GetTilesetResRef(object oArea);

// - oTrapObject: a placeable, door or trigger
// * Returns TRUE if oTrapObject can be recovered.
int GetTrapRecoverable(object oTrapObject);

// Sets whether or not the trapped object can be recovered.
// - oTrapObject: a placeable, door or trigger
void SetTrapRecoverable(object oTrapObject, int nRecoverable=TRUE);

// Get the XP scale being used for the module.
int GetModuleXPScale();

// Set the XP scale used by the module.
// - nXPScale: The XP scale to be used. Must be between 0 and 200.
void SetModuleXPScale(int nXPScale);

// Get the feedback message that will be displayed when trying to unlock the object oObject.
// - oObject: a door or placeable.
// Returns an empty string "" on an error or if the game's default feedback message is being used
string GetKeyRequiredFeedback(object oObject);

// Set the feedback message that is displayed when trying to unlock the object oObject.
// This will only have an effect if the object is set to
// "Key required to unlock or lock" either in the toolset
// or by using the scripting command SetLockKeyRequired().
// - oObject: a door or placeable.
// - sFeedbackMessage: the string to be displayed in the player's text window.
//                     to use the game's default message, set sFeedbackMessage to ""
void SetKeyRequiredFeedback(object oObject, string sFeedbackMessage);

// - oTrapObject: a placeable, door or trigger
// * Returns TRUE if oTrapObject is active
int GetTrapActive(object oTrapObject);

// Sets whether or not the trap is an active trap
// - oTrapObject: a placeable, door or trigger
// - nActive: TRUE/FALSE
// Notes:
// Setting a trap as inactive will not make the
// trap disappear if it has already been detected.
// Call SetTrapDetectedBy() to make a detected trap disappear.
// To make an inactive trap not detectable call SetTrapDetectable()
void SetTrapActive(object oTrapObject, int nActive=TRUE);

// Locks the player's camera pitch to its current pitch setting,
// or unlocks the player's camera pitch.
// Stops the player from tilting their camera angle. 
// - oPlayer: A player object.
// - bLocked: TRUE/FALSE.
void LockCameraPitch(object oPlayer, int bLocked=TRUE);

// Locks the player's camera distance to its current distance setting,
// or unlocks the player's camera distance.
// Stops the player from being able to zoom in/out the camera.
// - oPlayer: A player object.
// - bLocked: TRUE/FALSE.
void LockCameraDistance(object oPlayer, int bLocked=TRUE);

// Locks the player's camera direction to its current direction,
// or unlocks the player's camera direction to enable it to move
// freely again.
// Stops the player from being able to rotate the camera direction.
// - oPlayer: A player object.
// - bLocked: TRUE/FALSE.
void LockCameraDirection(object oPlayer, int bLocked=TRUE);

// Get the last object that default clicked (left clicked) on the placeable object
// that is calling this function.
// Should only be called from a placeables OnClick event.
// * Returns OBJECT_INVALID if it is called by something other than a placeable.
object GetPlaceableLastClickedBy();

// returns TRUE if the item is flagged as infinite.
// - oItem: an item.
// The infinite property affects the buying/selling behavior of the item in a store.
// An infinite item will still be available to purchase from a store after a player
// buys the item (non-infinite items will disappear from the store when purchased).
int GetInfiniteFlag(object oItem);

// Sets the Infinite flag on an item
// - oItem: the item to change
// - bInfinite: TRUE or FALSE, whether the item should be Infinite
// The infinite property affects the buying/selling behavior of the item in a store.
// An infinite item will still be available to purchase from a store after a player
// buys the item (non-infinite items will disappear from the store when purchased).
void SetInfiniteFlag(object oItem, int bInfinite=TRUE);

// Gets the size of the area.
// - nAreaDimension: The area dimension that you wish to determine.
//      AREA_HEIGHT
//      AREA_WIDTH
// - oArea: The area that you wish to get the size of.
// Returns: The number of tiles that the area is wide/high, or zero on an error.
// If no valid area (or object) is specified, it uses the area of the caller.
// If an object other than an area is specified, will use the area that the object is currently in.
int GetAreaSize(int nAreaDimension, object oArea=OBJECT_INVALID);

// Set the name of oObject.
// - oObject: the object for which you are changing the name (a creature, placeable, item, or door).
// - sNewName: the new name that the object will use.
// Note: SetName() does not work on player objects.
//       Setting an object's name to "" will make the object
//       revert to using the name it had originally before any
//       SetName() calls were made on the object.
void SetName(object oObject, string sNewName="");

// Get the PortraitId of oTarget.
// - oTarget: the object for which you are getting the portrait Id.
// Returns: The Portrait Id number being used for the object oTarget.
//          The Portrait Id refers to the row number of the Portraits.2da
//          that this portrait is from.
//          If a custom portrait is being used, oTarget is a player object,
//          or on an error returns PORTRAIT_INVALID. In these instances
//          try using GetPortraitResRef() instead.
int GetPortraitId(object oTarget=OBJECT_SELF);

// Change the portrait of oTarget to use the Portrait Id specified.
// - oTarget: the object for which you are changing the portrait.
// - nPortraitId: The Id of the new portrait to use. 
//                nPortraitId refers to a row in the Portraits.2da
// Note: Not all portrait Ids are suitable for use with all object types.
//       Setting the portrait Id will also cause the portrait ResRef
//       to be set to the appropriate portrait ResRef for the Id specified.
void SetPortraitId(object oTarget, int nPortraitId);

// Get the Portrait ResRef of oTarget.
// - oTarget: the object for which you are getting the portrait ResRef.
// Returns: The Portrait ResRef being used for the object oTarget.
//          The Portrait ResRef will not include a trailing size letter.
string GetPortraitResRef(object oTarget=OBJECT_SELF);

// Change the portrait of oTarget to use the Portrait ResRef specified.
// - oTarget: the object for which you are changing the portrait.
// - sPortraitResRef: The ResRef of the new portrait to use. 
//                    The ResRef should not include any trailing size letter ( e.g. po_el_f_09_ ).
// Note: Not all portrait ResRefs are suitable for use with all object types.
//       Setting the portrait ResRef will also cause the portrait Id
//       to be set to PORTRAIT_INVALID.
void SetPortraitResRef(object oTarget, string sPortraitResRef);

// Set oPlaceable's useable object status.
// Note: Only works on non-static placeables.
void SetUseableFlag(object oPlaceable, int nUseableFlag);

// Get the description of oObject.
// - oObject: the object from which you are obtaining the description. 
//            Can be a creature, item, placeable, door, trigger or module object.
// - bOriginalDescription:  if set to true any new description specified via a SetDescription scripting command
//                   is ignored and the original object's description is returned instead.
// - bIdentified: If oObject is an item, setting this to TRUE will return the identified description,
//                setting this to FALSE will return the unidentified description. This flag has no
//                effect on objects other than items.
string GetDescription(object oObject, int bOriginalDescription=FALSE, int bIdentifiedDescription=TRUE);

// Set the description of oObject.
// - oObject: the object for which you are changing the description 
//            Can be a creature, placeable, item, door, or trigger.
// - sNewDescription: the new description that the object will use.
// - bIdentified: If oObject is an item, setting this to TRUE will set the identified description,
//                setting this to FALSE will set the unidentified description. This flag has no
//                effect on objects other than items.
// Note: Setting an object's description to "" will make the object
//       revert to using the description it originally had before any
//       SetDescription() calls were made on the object.
void SetDescription(object oObject, string sNewDescription="", int bIdentifiedDescription=TRUE);

// Get the PC that sent the last player chat(text) message.
// Should only be called from a module's OnPlayerChat event script.
// * Returns OBJECT_INVALID on error.
// Note: Private tells do not trigger a OnPlayerChat event.
object GetPCChatSpeaker();

// Get the last player chat(text) message that was sent.
// Should only be called from a module's OnPlayerChat event script.
// * Returns empty string "" on error.
// Note: Private tells do not trigger a OnPlayerChat event.
string GetPCChatMessage();

// Get the volume of the last player chat(text) message that was sent.
// Returns one of the following TALKVOLUME_* constants based on the volume setting
// that the player used to send the chat message.
//                TALKVOLUME_TALK
//                TALKVOLUME_WHISPER
//                TALKVOLUME_SHOUT
//                TALKVOLUME_SILENT_SHOUT (used for DM chat channel)
//                TALKVOLUME_PARTY
// Should only be called from a module's OnPlayerChat event script.
// * Returns -1 on error.
// Note: Private tells do not trigger a OnPlayerChat event.
int GetPCChatVolume();

// Set the last player chat(text) message before it gets sent to other players.
// - sNewChatMessage: The new chat text to be sent onto other players.
//                    Setting the player chat message to an empty string "",
//                    will cause the chat message to be discarded 
//                    (i.e. it will not be sent to other players).
// Note: The new chat message gets sent after the OnPlayerChat script exits.
void SetPCChatMessage(string sNewChatMessage="");

// Set the last player chat(text) volume before it gets sent to other players.
// - nTalkVolume: The new volume of the chat text to be sent onto other players.
//                TALKVOLUME_TALK
//                TALKVOLUME_WHISPER
//                TALKVOLUME_SHOUT
//                TALKVOLUME_SILENT_SHOUT (used for DM chat channel)
//                TALKVOLUME_PARTY
//                TALKVOLUME_TELL (sends the chat message privately back to the original speaker)
// Note: The new chat message gets sent after the OnPlayerChat script exits.
void SetPCChatVolume(int nTalkVolume=TALKVOLUME_TALK);

// Get the Color of oObject from the color channel specified.
// - oObject: the object from which you are obtaining the color. 
//            Can be a creature that has color information (i.e. the playable races).
// - nColorChannel: The color channel that you want to get the color value of.
//                   COLOR_CHANNEL_SKIN
//                   COLOR_CHANNEL_HAIR
//                   COLOR_CHANNEL_TATTOO_1
//                   COLOR_CHANNEL_TATTOO_2
// * Returns -1 on error.
int GetColor(object oObject, int nColorChannel);

// Set the color channel of oObject to the color specified.
// - oObject: the object for which you are changing the color.
//            Can be a creature that has color information (i.e. the playable races).
// - nColorChannel: The color channel that you want to set the color value of.
//                   COLOR_CHANNEL_SKIN
//                   COLOR_CHANNEL_HAIR
//                   COLOR_CHANNEL_TATTOO_1
//                   COLOR_CHANNEL_TATTOO_2
// - nColorValue: The color you want to set (0-175).
void SetColor(object oObject, int nColorChannel, int nColorValue);

// Returns Item property Material.  You need to specify the Material Type.
// - nMasterialType: The Material Type should be a positive integer between 0 and 77 (see iprp_matcost.2da).
// Note: The Material Type property will only affect the cost of the item if you modify the cost in the iprp_matcost.2da.
itemproperty ItemPropertyMaterial(int nMaterialType);

// Returns Item property Quality. You need to specify the Quality.
// - nQuality:  The Quality of the item property to create (see iprp_qualcost.2da).
//              IP_CONST_QUALITY_*
// Note: The quality property will only affect the cost of the item if you modify the cost in the iprp_qualcost.2da.
itemproperty ItemPropertyQuality(int nQuality);

// Returns a generic Additional Item property. You need to specify the Additional property.
// - nProperty: The item property to create (see iprp_addcost.2da).
//              IP_CONST_ADDITIONAL_*
// Note: The additional property only affects the cost of the item if you modify the cost in the iprp_addcost.2da.
itemproperty ItemPropertyAdditional(int nAdditionalProperty);

