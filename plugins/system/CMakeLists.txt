if (gperf)

add_custom_command(OUTPUT SystemStrCmds.h
	COMMAND ../gperf_gen.sh SystemStr SYSTEM STR DEPENDS SystemStrCmds.gperf)
add_custom_command(OUTPUT SystemObjCmds.h
	COMMAND ../gperf_gen.sh SystemObj SYSTEM OBJ DEPENDS SystemObjCmds.gperf)

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
)

endif (gperf)
