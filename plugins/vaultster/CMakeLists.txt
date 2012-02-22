find_library(lboostthread boost_thread)
find_library(lboost boost_system)
find_library(lboostopt boost_program_options)

if (lboost AND lboostopt AND lboostthread)
		add_executable(vaultster-server vaultster-serv vaultster-config blowfish)
		target_link_libraries(vaultster-server z ${lboostthread} ${lboost}
			${lboostopt})

		add_module(vaultster NWNXVaultster client blowfish plugin-vaultster)
		target_link_libraries(vaultster z ${lboostthread} ${lboost}
			${lboostopt})

else (lboost AND lboostopt AND lboostthread)
	message(WARNING "Cannot find boost libraries, not building vaultster")
endif (lboost AND lboostopt AND lboostthread)

