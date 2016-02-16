include_directories(../../api)

add_module(fixes FixesHooks FixesHooksNewApi NWNXFixes plugin-fixes)

set_target_properties(fixes PROPERTIES COMPILE_FLAGS "-O0")
