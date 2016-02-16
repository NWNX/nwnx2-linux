include_directories(../../api)

add_module(connect ConnectHooks NWNXConnect plugin-connect)

set_target_properties(connect PROPERTIES COMPILE_FLAGS "-O0")