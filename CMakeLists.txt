cmake_minimum_required(VERSION 2.8)
project(nwnx-core-2.8)

set(NWNX_OUTPUT_DIR ${PROJECT_BINARY_DIR}/compiled)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${NWNX_OUTPUT_DIR})

# You can exclude plugins from being built here.
set(dont_build_plugins

)

# Compatibility with cmake 2.8.9 and above.
if(POLICY CMP0018)
    cmake_policy(SET CMP0018 OLD)
endif()

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMakeModules)

# Our must-have flags for compilers
# - i386/m32: nwnx only runs with a 32bit host nwserver, obviously.
if (NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
	message(FATAL_ERROR "nwnx2 will only work on 32bit toolchains. Use one (CC='gcc -m32' CXX='g++ -m32' cmake .)!")
endif()
SET(OUR_CFLAGS_MUST_HAVES "${OUR_CFLAGS_MUST_HAVES} -m32")

# - no-omit-frame-pointer: breaks assembly on -O1/-O2 for some plugins
# - no-accumulate-outgoing-args: same
SET(OUR_CFLAGS_MUST_HAVES "${OUR_CFLAGS_MUST_HAVES} -mno-accumulate-outgoing-args -fno-omit-frame-pointer")
# - warnings: self-explanatory
SET(OUR_CFLAGS_MUST_HAVES "${OUR_CFLAGS_MUST_HAVES} -Wall -Wextra -Wno-unused-parameter -Wno-unused -Wno-write-strings")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OUR_CFLAGS_MUST_HAVES}" CACHE STRING "" FORCE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OUR_CFLAGS_MUST_HAVES} -Wno-invalid-offsetof -Wno-return-type" CACHE STRING "" FORCE)
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} ${OUR_CFLAGS_MUST_HAVES}" CACHE STRING "" FORCE)

# removes stuff like -fPIC, which breaks nwnx plugin loading
set(CMAKE_SHARED_LIBRARY_C_FLAGS "")
set(CMAKE_SHARED_LIBRARY_CXX_FLAGS "")

# nwnx is currently still kind of broken with -O > 0. Until that's properly fixed
# and tested, force -O0 for release and relwithdebinfo builds. Individual
# plugins can always override this!
SET(CMAKE_C_FLAGS_DEBUG "-g -ggdb3 -gdwarf-4 -fno-eliminate-unused-debug-types")
SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG}")
SET(CMAKE_C_FLAGS_RELEASE "-O2 -DNDEBUG")
SET(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG")
SET(CMAKE_C_FLAGS_RELWITHDEBINFO "${CMAKE_C_FLAGS_DEBUG} -O2 -DNDEBUG")
SET(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_DEBUG} -O2 -DNDEBUG")

enable_language(ASM)

find_package(ZLIB REQUIRED)

find_program(gperf gperf)
if (NOT gperf)
	message(WARNING "No gperf found, cannot compile gperf-dependent plugins")
endif (NOT gperf)
find_program(ruby NAMES ruby1.8 ruby1.9 ruby2.0 ruby2.1 ruby)
if (NOT ruby)
	message(WARNING "No ruby interpreter found, cannot compile ruby-interpreter dependent plugins")
endif (NOT ruby)

include_directories(lib include .)
include_directories(plugins)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
        message(SEND_ERROR "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

add_library(nwnx2 SHARED nwnx2lib NWNXBase modules lists gline
	lib/nwn_data lib/nwn_funcs lib/nwn_hooks
	lib/nx_hook lib/nx_log lib/nx_safe lib/nx_signature
	lib/NwnDefines
	api/nwnsyms.S api/all

    core/core
    core/events/Console
    core/events/Console_Builtins
    core/events/Mainloop
    core/events/Module
    core/events/RunScript
    core/events/Object
    core/ThreadUtil
)

# for core/ThreadUtil
target_link_libraries(nwnx2 pthread)

# The core library doesnt really work yet with -O2.
set_target_properties(nwnx2 PROPERTIES COMPILE_FLAGS "-O0")

# Fake target to force recreating the compiled directory.
add_custom_target(always_rebuild_compiled ALL
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${NWNX_OUTPUT_DIR}
    COMMAND ${CMAKE_COMMAND} -E make_directory ${NWNX_OUTPUT_DIR}
)

add_custom_command(
    TARGET nwnx2 POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ARGS ${PROJECT_SOURCE_DIR}/nwnx2.ini ${NWNX_OUTPUT_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy ARGS ${PROJECT_SOURCE_DIR}/nwnstartup.sh ${NWNX_OUTPUT_DIR}
)

set_target_properties(nwnx2 PROPERTIES PREFIX "")
target_link_libraries(nwnx2 dl z)

# find all plugins with valid CMakeLists
file(GLOB plugins plugins/*/CMakeLists.txt)

function(add_module target)
	add_library(${target} MODULE ${ARGN})
	set_target_properties(${target} PROPERTIES PREFIX "nwnx_")
endfunction()

function(add_gperf_target target gperf v k l)
	add_custom_command(
                WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/plugins/${target}
                OUTPUT "${PROJECT_SOURCE_DIR}/plugins/${target}/${gperf}.h"
                COMMAND ${PROJECT_SOURCE_DIR}/plugins/gperf_gen.sh "${v}" "${k}" "${l}"
                DEPENDS ${PROJECT_SOURCE_DIR}/plugins/gperf_gen.sh "${gperf}.gperf"
	)
endfunction()

foreach(plugin ${plugins})
	get_filename_component(pa ${plugin} PATH)
	get_filename_component(na ${pa} NAME)

	list(FIND dont_build_plugins ${na} dontbuild)
	if (${dontbuild} EQUAL -1)
        if(EXISTS "${pa}/nwnx2.ini")
             add_custom_command(
                 TARGET nwnx2 POST_BUILD
                 COMMAND echo ARGS "" >> ${NWNX_OUTPUT_DIR}/nwnx2.ini
                 COMMAND echo ARGS "" >> ${NWNX_OUTPUT_DIR}/nwnx2.ini
                 COMMAND cat ARGS ${pa}/nwnx2.ini >> ${NWNX_OUTPUT_DIR}/nwnx2.ini
             )
        endif(EXISTS "${pa}/nwnx2.ini")

		add_subdirectory(${pa})
	else (${dontbuild} EQUAL -1)
		message(STATUS "Skipping plugin ${na} due to configuration")
	endif (${dontbuild} EQUAL -1)
endforeach(plugin)

add_subdirectory(override)
