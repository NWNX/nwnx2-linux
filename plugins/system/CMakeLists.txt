if (gperf)

add_gperf_target(system SystemStrCmds SystemStr SYSTEM STR)
add_gperf_target(system SystemObjCmds SystemObj SYSTEM OBJ)

include_directories(.)
add_module(system NWNXSystem plugin-system
	SystemStrCmds SystemObjCmds

	funcs/f_DirList
	funcs/f_FileCopy
	funcs/f_FileLink
	funcs/f_FileDelete
	funcs/f_FileReadAll
	funcs/f_FileRename
	funcs/f_FileSymlink
	funcs/f_GetProcessCPUUsage
	funcs/f_GetProcessMemoryUsage
	funcs/f_GetSystemTime
	funcs/f_GetTMILimit
	funcs/f_IntToObject
	funcs/f_SetTMILimit
	funcs/f_ShutdownServer
	funcs/f_TrueRandom
)

set_target_properties(system PROPERTIES COMPILE_FLAGS "-O0")

endif (gperf)
