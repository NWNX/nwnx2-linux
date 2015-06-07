add_module(resman ../../api/nwnsyms.S ../../api/all
   HookDemandRes NWNXResMan plugin-resman DirectoryHandler)

set_target_properties(resman PROPERTIES
        COMPILE_FLAGS "-std=c++0x -Wno-return-type")
