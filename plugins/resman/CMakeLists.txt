add_module(resman HookDemandRes NWNXResMan plugin-resman)
set_target_properties(resman PROPERTIES
	COMPILE_FLAGS "-Wno-deprecated")
