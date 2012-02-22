if (gperf)

add_custom_command(OUTPUT TweaksStrCmds.h
	COMMAND ../gperf_gen.sh TweaksStr TWEAKS STR DEPENDS TweaksStrCmds.gperf)
add_custom_command(OUTPUT TweaksObjCmds.h
	COMMAND ../gperf_gen.sh TweaksObj TWEAKS OBJ DEPENDS TweaksObjCmds.gperf)

include_directories(.)
add_module(tweaks NWNXTweaks plugin-tweaks
	TweaksStrCmds TweaksObjCmds

	funcs/f_GetTweakOption
	funcs/f_IntToObject
	funcs/f_SetTweakOption
	hooks/h_FixSendFeedbackMessage
	tables/t_TweakOptions
)

endif (gperf)
