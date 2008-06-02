NWNX Functions 1.8.7
----
New functions:
  int GetItemCount(object oTarget);
  object GetItemByPosition(object oTarget, int nPosition);

Fixed a crash in GetNextVariable function
Fixed a crash in GetConversation function
Added dynamic allocation support to GetDescription (spacer is not required anymore)
---

virusman
02.06.2008

------------------------------------------
Complete function list:

int GetArmorAC(object oObject);
void SetArmorAC(object oObject, int iAC);
void SetGoldPieceValue(object oObject, int iValue);
void SetTag(object oObject, string sValue);
void SetRacialType(object oObject, int nRacialType);
int GetDescriptionLength(object oObject);
string GetDescription(object oObject);
string SetDescription(object oObject, string sNewDescription);
string GetConversation(object oObject);
int GetUndroppableFlag(object oItem);
void SetUndroppableFlag(object oItem, int bUndroppable);
int GetItemWeight(object oObject);
void SetItemWeight(object oObject, int nWeight);
string GetEventHandler(object oObject, int nEventId);
void SetEventHandler(object oObject, int nEventId, string sScript);
int GetFactionID(object oObject);
void SetFactionID(object oObject, int nFaction);
float GetGroundHeight(location lLocation);
int GetIsWalkable(location lLocation);
object GetFirstArea();
object GetNextArea();
void Set2DAString(string s2DA, string sColumn, int nRow, string sValue);
void SetMovementRate(object oCreature, int nMovementRate);
void ActionUseItemOnObject(object oItem, object oTarget, int nPropertyNum = 0);
void ActionUseItemAtLocation(object oItem, location lLocation, int nPropertyNum = 0);
int GetPCPort(object oPlayer);
void BootPCWithMessage(object oPC, int nStrRef);
int JumpToLimbo(object oObject);
int GetIsVariableValid(struct scriptvar svVariable);
struct scriptvar GetFirstLocalVariable(object oObject);
struct scriptvar GetNextLocalVariable(object oObject);
int GetItemCount(object oTarget);
object GetItemByPosition(object oTarget, int nPosition);

------------------------------------------
Previous versions:

NWNX Functions 1.8.6 (24.11.2007)
----
New functions:
  int JumpToLimbo(object oObject);
  int GetIsVariableValid(struct scriptvar svVariable);
  struct scriptvar GetFirstLocalVariable(object oObject);
  struct scriptvar GetNextLocalVariable(object oObject);

Added DeleteLocalString to some of the functions

NWNX Functions 1.8.5 (24.06.2007)
----
New functions:
  int GetPCPort(object oPlayer);
  void BootPCWithMessage(object oPC, int nStrRef);

NWNX Functions 1.8.4 (16.06.2007)
----
New functions:
  void ActionUseItemOnObject(object oItem, object oTarget, int nPropertyNum = 0);
  void ActionUseItemAtLocation(object oItem, location lLocation, int nPropertyNum = 0);

NWNX Functions 1.8.3 (13.06.2007)
----
New function:
  void SetMovementRate(object oCreature, int nMovementRate);

NWNX Functions 1.8.2 (01.05.2007)
----
New function:
  void Set2DAString(string s2DA, string sColumn, int nRow, string sValue);

NWNX Functions 1.8.1 (15.04.2007)
----
New functions:
  object GetFirstArea();
  object GetNextArea();

NWNX Functions 1.8 (08.04.2007)
----
New functions:
  float GetGroundHeight(location lLocation);
  int GetIsWalkable(location lLocation);
Updated:
  Ported faction functions to 1.68.

NWNX Functions 1.7 (15.02.2007)
----
New functions:
  int GetDescriptionLength(object oObject);
  string GetConversation(object oObject);
  int GetUndroppableFlag(object oItem);
  void SetUndroppableFlag(object oItem, int bUndroppable);
  int GetItemWeight(object oObject);
  void SetItemWeight(object oObject, int nWeight);

Updated:
  Get/SetDescription now work with doors and creatures.
  Added a bit more comments on functions
  Added plugin sources to the package

NWNX Functions 1.6 (18.09.2006)
----
New functions:
  void SetRacialType(object oObject, int iValue);
  string GetEventHandler(object oObject, int nEventId);
  void SetEventHandler(object oObject, int nEventId, string sScript);
  int GetFactionID(object oObject);
  void SetFactionID(object oObject, int nFaction);