if (gperf)

add_gperf_target(tweaks TweaksStrCmds TweaksStr TWEAKS STR)
add_gperf_target(tweaks TweaksObjCmds TweaksObj TWEAKS OBJ)

include_directories(.)
add_module(tweaks NWNXTweaks plugin-tweaks
	TweaksStrCmds TweaksObjCmds

	funcs/f_GetTweakOption
	funcs/f_IntToObject
	funcs/f_SetTweakOption
	hooks/h_FixSendFeedbackMessage
	tables/t_TweakOptions
)

set_target_properties(tweaks PROPERTIES COMPILE_FLAGS "-O0")

endif (gperf)
