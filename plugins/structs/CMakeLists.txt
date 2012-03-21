if (gperf)

add_gperf_target(StructsStrCmds StructsStr STRUCTS STR)
add_gperf_target(StructsObjCmds StructsObj STRUCTS OBJ)

include_directories(.)
add_module(structs NWNXStructs plugin-structs
	StructsStrCmds StructsObjCmds

	funcs/f_GetCreator
	funcs/f_GetDuration
	funcs/f_GetDurationRemaining
	funcs/f_GetHasEffect
	funcs/f_GetInteger
	funcs/f_GetSpellId
	funcs/f_GetTrueType
	funcs/f_SetCreator
	funcs/f_SetInteger
	funcs/f_SetSpellId
	funcs/f_SetTrueType
	hooks/h_PushStruct
)

endif (gperf)
