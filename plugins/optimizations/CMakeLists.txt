add_module(optimizations HookFunc NWNXOptimizations plugin-optimizations)

set_target_properties(optimizations PROPERTIES COMPILE_FLAGS "-O0")
