include_directories(../../api)

# Ignore no return errors from v2.8 api.
SET(FIXES_CXX_FLAGS "-Wno-return-type" CACHE STRING
    "plugins/fixes specific compiler flags.")

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${FIXES_CXX_FLAGS}")

add_module(fixes ../../api/all ../../api/nwnsyms.S ../../include/nx_hook FixesHooks FixesHooksNewApi NWNXFixes plugin-fixes)
