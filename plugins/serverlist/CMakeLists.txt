add_module(serverlist ServerlistHooks NWNXServerlist plugin-serverlist)

set_target_properties(serverlist PROPERTIES COMPILE_FLAGS "-O0")
