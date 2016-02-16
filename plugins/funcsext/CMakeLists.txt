add_module(funcsext FunctionHooks NWNXFuncsExt plugin-funcsext)

set_target_properties(funcsext PROPERTIES COMPILE_FLAGS "-O0")
