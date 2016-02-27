add_module(areas CExoLinkedList CExoLocString HookFunc NWNXAreas
	plugin-areas)

set_target_properties(areas PROPERTIES COMPILE_FLAGS "-O0")