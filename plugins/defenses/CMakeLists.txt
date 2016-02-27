if (gperf)

add_gperf_target(defenses DefensesStrCmds DefensesStr DEFENSES STR)
add_gperf_target(defenses DefensesObjCmds DefensesObj DEFENSES OBJ)

include_directories(.)
add_module(defenses NWNXDefenses plugin-defenses
	DefensesStrCmds DefensesObjCmds

	funcs/f_GetACByType
	funcs/f_GetACVersus
	funcs/f_GetAllSpellImmunities
	funcs/f_GetBaseSaveBonus
	funcs/f_GetDefenseOption
	funcs/f_GetEffectDamageReduction
	funcs/f_GetEffectDamageResistance
	funcs/f_GetEffectSaveModifier
	funcs/f_GetHasSpellImmunity
	funcs/f_GetSavingThrowFeat
	funcs/f_GetSavingThrowVersus
	funcs/f_GetTotalDamageImmunityDecrease
	funcs/f_GetTrueDamageImmunity
	funcs/f_IntToObject
	funcs/f_SetDefenseOption
	funcs/f_SetSavingThrowFeat
	hooks/h_AddDamageImmunity
	hooks/h_CheckConcealment
	hooks/h_CombatHitDamage
	hooks/h_ConfirmCritical
	hooks/h_GetACNaturalBase
	hooks/h_GetArmorCheckPenalty
	hooks/h_GetDamageImmunity
	hooks/h_GetDamageResistance
	hooks/h_GetHasSlipperyMind
	hooks/h_GetIsDeathAttackImmune
	hooks/h_GetIsSneakAttackImmune
	hooks/h_GetSavingThrow
	hooks/h_GetTumbleACBonus
	hooks/h_PickPocketDC
	hooks/h_SetDamageImmunity
	local/l_AdjustCombatHitDamage
	local/l_GetACChaAdjustment
	local/l_GetACClassAdjustment
	local/l_GetACConAdjustment
	local/l_GetACDexAdjustment
	local/l_GetACEquipAdjustment
	local/l_GetACFeatAdjustment
	local/l_GetACIntAdjustment
	local/l_GetACSkillAdjustment
	local/l_GetACStrAdjustment
	local/l_GetACTouchBase
	local/l_GetACTumbleAdjustment
	local/l_GetACWisAdjustment
	local/l_GetArmorCheckPenaltyAdjustment
	local/l_GetConcealmentCheckResult
	local/l_GetCritConfirmationResult
	local/l_GetDamageImmunity
	local/l_GetHasSlipperyMind
	local/l_GetIsDeathAttackImmune
	local/l_GetIsSneakAttackImmune
	local/l_GetPickPocketDCAdjustment
	tables/t_DefenseOptions
	tables/t_DefenseSaveFeats
)

set_target_properties(defenses PROPERTIES COMPILE_FLAGS "-O0")

endif (gperf)
