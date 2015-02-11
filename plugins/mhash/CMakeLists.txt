find_package(MHASH)

if (MHASH_FOUND)

	add_module(mhash
	    NWNXMHash
	    plugin-mhash
	)

	target_link_libraries(mhash ${MHASH_LIBRARY})

endif (MHASH_FOUND)
