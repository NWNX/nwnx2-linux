add_module(dmactions FunctionHooks NWNXdmactions
	plugin-dmactions)

set_target_properties(dmactions PROPERTIES COMPILE_FLAGS "-O0")
