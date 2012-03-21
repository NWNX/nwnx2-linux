cmake_minimum_required(VERSION 2.8)
project(nwnx-core-2.8)

# You can exclude plugins from being built here.
set(dont_build_plugins connect)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMakeModules)

set(CMAKE_C_FLAGS "-mtune=i386 -m32 -Wall -Wno-unused -Wno-write-strings")
set(CMAKE_CXX_FLAGS "-mtune=i386 -m32 -Wall -Wno-unused -Wno-write-strings")
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

add_library(nwnx2 SHARED nwnx2lib NWNXBase modules lists gline
	lib/nwn_data lib/nwn_funcs lib/nwn_hooks
	lib/nx_hook lib/nx_log lib/nx_safe lib/nx_signature
)
set_target_properties(nwnx2 PROPERTIES PREFIX "")
target_link_libraries(nwnx2 dl z)

# find all plugins with valid CMakeLists
file(GLOB plugins plugins/*/CMakeLists.txt)

function(add_module target)
	add_library(${target} MODULE ${ARGN})
	set_target_properties(${target} PROPERTIES PREFIX "nwnx_")
endfunction()

foreach(plugin ${plugins})
	get_filename_component(pa ${plugin} PATH)
	get_filename_component(na ${pa} NAME)

	list(FIND dont_build_plugins ${na} dontbuild)
	if (${dontbuild} EQUAL -1)
		add_subdirectory(${pa})
	else (${dontbuild} EQUAL -1)
		message(STATUS "Skipping plugin ${na} due to configuration")
	endif (${dontbuild} EQUAL -1)
endforeach(plugin)

add_subdirectory(override)
