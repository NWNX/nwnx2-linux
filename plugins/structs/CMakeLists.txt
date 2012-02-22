if (gperf)

add_custom_command(OUTPUT StructsStrCmds.h
	COMMAND ../gperf_gen.sh StructsStr STRUCTS STR DEPENDS StructsStrCmds.gperf)
add_custom_command(OUTPUT StructsObjCmds.h
	COMMAND ../gperf_gen.sh StructsObj STRUCTS OBJ DEPENDS StructsObjCmds.gperf)

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
