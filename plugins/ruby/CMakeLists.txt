find_package(Ruby 1.8)

if (RUBY_FOUND)
	include_directories(${RUBY_INCLUDE_DIRS})
	add_module(ruby FunctionHooks ruby_int NWNXRuby plugin-ruby)
	target_link_libraries(ruby ${RUBY_LIBRARY})

    set_target_properties(ruby PROPERTIES COMPILE_FLAGS "-O0")

else (RUBY_FOUND)
	message(WARNING "Cannot find ruby libraries.")
endif (RUBY_FOUND)
