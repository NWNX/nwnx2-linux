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

set(CMAKE_C_FLAGS "-mtune=i386 -m32 -mno-accumulate-outgoing-args -Wall -Wno-unused -Wno-write-strings")
set(CMAKE_CXX_FLAGS "-mtune=i386 -m32 -mno-accumulate-outgoing-args -Wall -Wno-unused -Wno-write-strings -Wno-return-type")
set(CMAKE_SHARED_LIBRARY_C_FLAGS "")
set(CMAKE_SHARED_LIBRARY_CXX_FLAGS "")

enable_language(ASM)

find_package(ZLIB REQUIRED)

find_program(gperf gperf)
if (NOT gperf)
	message(WARNING "No gperf found, cannot compile gperf-dependent plugins")
endif (NOT gperf)
find_program(ruby NAMES ruby1.8 ruby)
if (NOT ruby)
	message(WARNING "No ruby interpreter found, cannot compile ruby-interpreter dependent plugins")
endif (NOT ruby)

include_directories(lib include .)
include_directories(plugins)

add_library(nwnx2 SHARED nwnx2lib NWNXBase modules lists gline
	lib/nwn_data lib/nwn_funcs lib/nwn_hooks
	lib/nx_hook lib/nx_log lib/nx_safe lib/nx_signature
	lib/NwnDefines
	api/nwnsyms.S api/all
)

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
