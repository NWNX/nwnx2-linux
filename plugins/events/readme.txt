NWNX Events plugin (version 1.3.3)
(requires NWNX Core version 2.7-beta2 or higher)

Provides hooks for the following events:
* PickPocket (can be blocked from script)
    - OBJECT_SELF        = Thief
    - GetEventTarget()   = Victim
* Attack
    - OBJECT_SELF        = Attacker
    - GetEventTarget()   = Target
* UseItem (can be blocked from script)
    - OBJECT_SELF        = Item user
    - GetEventTarget()   = Item target
    - GetEventItem()     = Item used
    - GetEventPosition() = Target position (as a vector)
* QuickChat (can be blocked from script)
    - OBJECT_SELF        = Talker
    - GetEventSubType()  = QuickChat ID
* Examine (can be blocked from script except OnExamineItem)
    - OBJECT_SELF        = Examiner
    - GetEventTarget()   = Thing to be examined
* UseSkill (can be blocked from script)
    - OBJECT_SELF        = Skill user
    - GetEventSubType()  = Skill ID (SKILL_*)
    - GetEventTarget()   = Skill target
    - GetEventPosition() = Skill target position (as a vector)
    - GetEventItem()     = Item associated with the skill
* UseFeat (can be blocked from script)
    - OBJECT_SELF        = Feat user
    - GetEventSubType()  = Feat ID (FEAT_*)
    - GetEventTarget()   = Feat target
    - GetEventPosition() = Feat target position (as a vector)
* ToggleMode (can be blocked from script)
    - OBJECT_SELF        = Creature toggling
    - GetEventSubType()  = Action mode toggled (ACTION_MODE_*)
* CastSpell (can be blocked from script)
    - OBJECT_SELF        = Spell user
    - GetEventSubType()  = Spell ID (SPELL_*) - mask with '& 0xFFFF'
    - GetEventTarget()   = Spell target
    - GetEventPosition() = Spell target position (as a vector)
* TogglePause (can be blocked from script)
    - GetEventSubType()  = Pause state
* PossessFamiliar (can be blocked from script)
    - OBJECT_SELF        = Player character
* ValidateCharacter (can be overriden by script)
    - OBJECT_SELF        = Player character
    * BypassEvent()      = Override default ELC check
    * SetReturnValue()   = Return value to override
                           0 - valid character
                           <any number> - StrRef (TLK string) of the error message (the character won't be able to enter)
* DestroyObject (unsafe)
    - OBJECT_SELF        = The object being destroyed
* DevastatingCritical (can be blocked from script)
    - OBJECT_SELF        = The attacker that is using DevCrit feat
    - GetEventTarget()   = Creature being hit with the devastating critical
    - GetEventSubType()  = Total damage being dealt to target
    - GetEventItem()     = Attacker's weapon, in which the attacker has the devcrit feat
    * BypassEvent()      = Override default devastating critical handling
    * SetReturnValue()   = Whether the attacker gets a cleave attack. Only valid if BypassEvent() was called.


Provides functions for conditional and action scripts:
    int GetCurrentNodeType();
    int GetCurrentNodeID();
    int GetCurrentAbsoluteNodeID();
    string GetCurrentNodeText(int nLangID, int nGender);
    void SetCurrentNodeText(string sText, int nLangID, int nGender);
    int GetSelectedNodeID();
    int GetSelectedAbsoluteNodeID();
    string GetSelectedNodeText(int nLangID, int nGender);
See the Demo module for examples.

By default, the 'vir_events' script will be called. To set a custom script for a
given event, call the SetGlobalEventHandler() function as follows:
    SetGlobalEventHandler(EVENT_TYPE_ATTACK, "vir_ev_attack");

You can also use the following lines in your nwnx2.ini file:
[EVENTS]
event_script=<your script name>
enable_unsafe_events=0

Example script and demo module are included.

---
virusman, 19.06.2011


-----------------
CHANGELOG:

1.3.3 (19.06.2011)
- New event: DestroyObject
- New ini config: enable_unsafe_events
- New function: GetScriptReturnValue()

1.3.2 (05.05.2010)
- New event: ValidateCharacter

1.3.1 (12.11.2008)
- New function:
    SetGlobalEventHandler()

1.3.0 (01.08.2008)
- New events:
    EVENT_TYPE_CAST_SPELL (Acaos)
    EVENT_TYPE_TOGGLE_PAUSE (elven)
    EVENT_TYPE_POSSESS_FAMILIAR (elven)

1.2.2 (04.06.2008)
- Updated RunScript signature for compatibility with 1.69 beta 10

1.2.1 (12.05.2008)
- Updated RunScript signature for compatibility with 1.69

1.2.0 (15.03.2008)
- New events: UseSkill, UseFeat, ToggleMode

1.1.8 (15.03.2008)
- Minor fix in RunScript function
- New event: Examine

1.1.7 (23.02.2008)
- New event: Quickchat
- New function:
    int GetEventSubType();

1.1.6 (19.06.2007)
- New function for UseItem event:
    int GetEventItemRadial();
- Added bypass option to PickPocket event
- Fixed a bug that could cause the server to crash

1.1.5 (14.04.2007)
- New functions for conversations:
    string GetCurrentNodeText(int nLangID, int nGender);
    void SetCurrentNodeText(string sText, int nLangID, int nGender);
    string GetSelectedNodeText(int nLangID, int nGender);

1.1.4 (11.04.2007)
- Added GetEventPosition() for UseItem event

1.1.3 (09.04.2007)
- (Minor change) Returned support for old format of function call: GETEVENTID

1.1.2 (04.04.2007)
- New functions for conversations:
    int GetSelectedNodeID();
    int GetSelectedAbsoluteNodeID();
- Removed SelectSonversationNode event: use Action scripts instead
- Added underscores to function calls
- Cleaned up the code a bit

1.1 (22.03.2007)
- New functions for conversations:
    int GetCurrentNodeType();
    int GetCurrentNodeID();
    int GetCurrentAbsoluteNodeID();
- Released the sources

