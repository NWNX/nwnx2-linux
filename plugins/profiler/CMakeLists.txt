add_module(profiler hash HookRunScript NWNXProfiler plugin-profiler)

set_target_properties(profiler PROPERTIES COMPILE_FLAGS "-O0")
