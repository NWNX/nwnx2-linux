#include "nwnx_dmactions"
//#include "dmw_include"

void main() {
    object oDM = OBJECT_SELF;
    int nAction = nGetDMActionID();

    if(nAction == DM_ACTION_GIVE_XP) {
        object oTarget = oGetDMAction_Target();
        int nXP = nGetDMAction_Param();
        WriteTimestampedLogEntry("DM Action: <"+GetName(oDM)+"> (GiveXP "+IntToString(nXP)+") <"+GetName(oTarget)+"> <"+(GetIsPC(oTarget)?GetPCPlayerName(oTarget):GetTag(oTarget))+">");
    } else
    if(nAction == DM_ACTION_GIVE_LEVEL) {
        object oTarget = oGetDMAction_Target(); ;
        int nLevels = nGetDMAction_Param();
        WriteTimestampedLogEntry("DM Action: <"+GetName(oDM)+"> (GiveLevel "+IntToString(nLevels)+") <"+GetName(oTarget)+"> <"+(GetIsPC(oTarget)?GetPCPlayerName(oTarget):GetTag(oTarget))+">");
    } else
    if(nAction == DM_ACTION_GIVE_GOLD) {
        object oTarget = oGetDMAction_Target();
        int nGold = nGetDMAction_Param();
        WriteTimestampedLogEntry("DM Action: <"+GetName(oDM)+"> (GiveGold "+IntToString(nGold)+") <"+GetName(oTarget)+"> <"+(GetIsPC(oTarget)?GetPCPlayerName(oTarget):GetTag(oTarget))+">");
    } else
    if(nAction == DM_ACTION_CREATE_ITEM_ON_OBJECT) {
        object oTarget = oGetDMAction_Target();
        object oItem = oGetDMAction_Target(TRUE);
        WriteTimestampedLogEntry("DM Action: <"+GetName(oDM)+"> (CreateItem "+GetResRef(oItem)+") <"+GetName(oTarget)+"> <"+(GetIsPC(oTarget)?GetPCPlayerName(oTarget):GetTag(oTarget))+">");
        if(GetGoldPieceValue(oItem) > 10000) {// Prevent creation of expensive items
            PreventDMAction();
            DestroyObject(oItem); // Clean up; We don't need it anymore?
        }
    } else
    if(nAction == DM_ACTION_CREATE_ITEM_ON_AREA) {
        vector vPos = vGetDMAction_Position();
        object oArea = oGetDMAction_Target();
        object oItem = oGetDMAction_Target(TRUE);
        WriteTimestampedLogEntry("DM Action: <"+GetName(oDM)+"> (CreateItem "+GetResRef(oItem)+") Area("+GetResRef(oArea)+") x:"+FloatToString(vPos.x, 0)+" y:"+FloatToString(vPos.y, 0)+" z:"+FloatToString(vPos.z, 0));
        if(GetGoldPieceValue(oItem) > 10000) {// Prevent creation of expensive items
            PreventDMAction();
            DestroyObject(oItem); // Clean up; We don't need it any more?
        }
    } else
    if(nAction == DM_ACTION_HEAL_CREATURE) {
        object oTarget = oGetDMAction_Target();
        PreventDMAction(); // Prevent standard DM Heal effect
        /* Your own Heal code */
        // e.g.: do standard heal behaviour except removing effects
        if(GetIsDead(oTarget)) {
            ApplyEffectToObject(DURATION_TYPE_INSTANT, EffectResurrection(), oTarget);
        }
        ApplyEffectToObject(DURATION_TYPE_INSTANT, EffectHeal(GetMaxHitPoints(oTarget)-GetCurrentHitPoints(oTarget)), oTarget);
        /* End of Heal code */
        WriteTimestampedLogEntry("DM Action: <"+GetName(oDM)+"> (Heal) <"+GetName(oTarget)+"> <"+(GetIsPC(oTarget)?GetPCPlayerName(oTarget):GetTag(oTarget))+">");

   } else
   if(nAction == DM_ACTION_RUNSCRIPT) {
        string sScript = sGetDMAction_Param();

        // Allow only dm_ prefix
        if(GetSubString(sGetDMAction_Param(), 0, 3) != "dm_") {
            PreventDMAction(); // Prevent running script
        }

        WriteTimestampedLogEntry("DM Action: <"+GetName(oDM)+"> (Script) <"+sScript+">");

   } else
   if(nAction == DM_ACTION_CREATE_PLACEABLE) {
        //object oTarget = oGetDMAction_Target();
        //object oArea = oGetDMAction_Target(TRUE);
        //vector vPos = vGetDMAction_Position();
   } else
   if(nAction == DM_ACTION_SPAWN_CREATURE) {
        object oTarget = oGetDMAction_Target();
        object oArea = oGetDMAction_Target(TRUE);
        vector vPos = vGetDMAction_Position();
        WriteTimestampedLogEntry("DM Action: <"+GetName(oDM)+"> (SpawnCreature "+GetResRef(oTarget)+") Area("+GetResRef(oArea)+") x:"+FloatToString(vPos.x, 0)+" y:"+FloatToString(vPos.y, 0)+" z:"+FloatToString(vPos.z, 0));
   } else
   if(nAction == DM_ACTION_TOGGLE_INVULNERABILITY) {
        object oTarget = oGetDMAction_Target();
        int bState = GetPlotFlag(oTarget); //Current invulnerability state
        WriteTimestampedLogEntry("DM Action: <"+GetName(oDM)+"> (Invulnerability "+(bState?"OFF":"ON")+") <"+GetName(oTarget)+"> <"+(GetIsPC(oTarget)?GetPCPlayerName(oTarget):GetTag(oTarget))+">");
   } else
   if(nAction == DM_ACTION_TOGGLE_IMMORTALITY) {
        object oTarget = oGetDMAction_Target();
        int bState = GetImmortal(oTarget); //Current immortality state
        WriteTimestampedLogEntry("DM Action: <"+GetName(oDM)+"> (Immortality "+(bState?"OFF":"ON")+") <"+GetName(oTarget)+"> <"+(GetIsPC(oTarget)?GetPCPlayerName(oTarget):GetTag(oTarget))+">");
   } else
   if(nAction == DM_ACTION_MESSAGE_TYPE) {
        int nType = nGetDMAction_Param();
        if(nType == 139) { // Prevent VAR dump
            PreventDMAction();
        }
        // More nTypes in nss/dm_messagetypes.txt in tarball with sources
        //WriteTimestampedLogEntry("DM Action: <"+GetName(oDM)+"> (MessageType) <"+IntToString(nType)+">");

   }
   /* Example - MultiSelection Tool - StartCode */
   /*
   else
   if(nAction == DM_ACTION_REST_CREATURE) {
        PreventDMAction(); // Prevent standard effect
        object oTarget = oGetDMAction_Target();

        int nTargets = nGetDMAction_TargetsCount(),
            nCurrent = nGetDMAction_TargetsCurrent();

        if(nCurrent == 0) { // First Target
            // Clear pseudo array from targets
            dmwClearAllMultiTargets(oDM);
        }

        // Add Target to pseudo array
        dmwAddMultiTarget(oDM, oTarget);

        // Last Target, start multiselection tool dialog
        if((nTargets - 1) == nCurrent) {
            AssignCommand(oDM, ClearAllActions(TRUE));
            AssignCommand(oDM, ActionStartConversation(oDM, "dmw_multiselect", TRUE, FALSE));
        }
   }
   */
}
