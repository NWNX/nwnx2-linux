NWNX Events plugin (version 1.2.2)
(requires NWNX Core version 2.7-beta2 or higher)

Provides hooks for the following events:
* PickPocket (can be blocked from script)
  - OBJECT_SELF       = Thief
  - GetActionTarget() = Victim
* Attack
  - OBJECT_SELF       = Attacker
  - GetActionTarget() = Target
* UseItem (can be blocked from script)
  - OBJECT_SELF        = Item user
  - GetActionTarget()  = Item target
  - GetEventItem()     = Item used
  - GetEventPosition() = Target position (as a vector)
* QuickChat (can be blocked from script)
  - OBJECT_SELF       = Talker
  - GetEventSubType() = QuickChat ID
* Examine (can be blocked from script except OnExamineItem)
  - OBJECT_SELF       = Examiner
  - GetActionTarget() = Thing to be examined
* UseSkill (can be blocked from script)
  - OBJECT_SELF        = Skill user
  - GetEventSubType()  = Skill ID (SKILL_*)
  - GetActionTarget()  = Skill target
  - GetEventPosition() = Skill target position (as a vector)
  - GetEventItem()     = Item associated with the skill
* UseFeat (can be blocked from script)
  - OBJECT_SELF        = Feat user
  - GetEventSubType()  = Feat ID (FEAT_*)
  - GetActionTarget()  = Feat target
  - GetEventPosition() = Feat target position (as a vector)
* ToggleMode (can be blocked from script)
  - OBJECT_SELF       = Creature toggling
  - GetEventSubType() = Action mode toggled (ACTION_MODE_*)

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

The default event script name is vir_events.
To set custom script name, add the following lines to your nwnx2.ini file:
--
[EVENTS]
event_script=<your script name>
--
Example script and demo module are included.

---
virusman, 04.06.2008


-----------------
CHANGELOG:

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