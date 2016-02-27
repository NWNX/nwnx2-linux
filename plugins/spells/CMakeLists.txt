if (gperf)

add_gperf_target(spells SpellsStrCmds SpellsStr SPELLS STR)
add_gperf_target(spells SpellsObjCmds SpellsObj SPELLS OBJ)

include_directories(.)
add_module(spells NWNXSpells plugin-spells
	SpellsStrCmds SpellsObjCmds

	funcs/f_GetSpellOption
	funcs/f_IntToObject
	funcs/f_SetSpellOption
	hooks/h_ComputeSpellRange
	hooks/h_GetCasterClassAbility
	hooks/h_GetClassSpellLevel
	hooks/h_GetIsMemorizationCasterClass
	hooks/h_GetIsUnlimitedBookCasterClass
	hooks/h_GetSpellMinAbilityMet
	hooks/h_IdentifySpell
	hooks/h_SpellSlotLoop
	local/l_GetIsArcaneCasterClass
	local/l_GetIsMemorizationCasterClass
	local/l_GetIsSpontaneousCasterClass
	local/l_GetIsUnlimitedBookCasterClass
	tables/t_SpellAbilities
	tables/t_SpellOptions
)

set_target_properties(spells PROPERTIES COMPILE_FLAGS "-O0")

endif (gperf)
