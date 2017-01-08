set(CMAKE_CXX_FLAGS "-m32 -mno-accumulate-outgoing-args -Wall -Wno-unused -Wno-return-type -Wno-write-strings -Werror -std=c++14 -fno-omit-frame-pointer -fno-rtti")
set(CMAKE_CXX_FLAGS_DEBUG "-DDEBUG -Og -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "-DRELEASE -O2 -s")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-DRELWITHDEBINFO -O2")

find_package(MySQL REQUIRED)

add_module(
    arelith_profiler

    # Top level	
	plugin-arelith_profiler
    NWNXArelithProfiler
    ProfilingHandler
    MySQLHandler
    
    # Hooks
    hooks/AllHooks
    hooks/RunScriptHook
    hooks/MainLoopHook
    hooks/PrintLogEntryHook
    hooks/IntraTileDFSHook

    # Useful helpers
    lib-arelith/FunctionHook
    )
    
target_include_directories(
    arelith_profiler 

    PRIVATE "."
    PRIVATE "hooks"
    PRIVATE "lib-arelith"
    PRIVATE ${MYSQL_INCLUDE_DIR})

target_link_libraries(arelith_profiler ${MYSQL_LIBRARY})