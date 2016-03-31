add_module(resman HookDemandRes NWNXResMan plugin-resman DirectoryHandler OnRequest)

set_target_properties(resman PROPERTIES COMPILE_FLAGS "-O0")
