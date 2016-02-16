find_package(Boost 1.35 COMPONENTS system thread program_options)
if (Boost_FOUND)
	include_directories(${Boost_INCLUDE_DIR})
	add_executable(vaultster-server vaultster-serv vaultster-config blowfish)
	target_link_libraries(vaultster-server z ${Boost_LIBRARIES})

	add_module(vaultster NWNXVaultster client blowfish plugin-vaultster)
	target_link_libraries(vaultster z ${Boost_LIBRARIES})

    set_target_properties(vaultster-server PROPERTIES COMPILE_FLAGS "-O0")
    set_target_properties(vaultster PROPERTIES COMPILE_FLAGS "-O0")

else (Boost_FOUND)
	message(WARNING "Cannot find boost libraries, not building vaultster")
endif (Boost_FOUND)
