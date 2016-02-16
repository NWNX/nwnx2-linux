add_module(visibility CExoLinkedList HookFunc NWNXVisibility
	plugin-visibility)

set_target_properties(visibility PROPERTIES COMPILE_FLAGS "-O0")
