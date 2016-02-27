set(all_deps HookSCORCO CExoString ObjectStorage NWNXodbc plugin-odbc)

find_package(PostgreSQL)
if (PostgreSQL_FOUND)
	message("Found PostgreSQL installation!")
	message("PostgreSQL_INCLUDE_DIRS = " "${PostgreSQL_INCLUDE_DIRS}")
	message("PostgreSQL_LIBRARIES    = " "${PostgreSQL_LIBRARIES}")
	include_directories(${PostgreSQL_INCLUDE_DIRS})

	add_module(odmbc_pgsql pgsql ${all_deps})
	target_link_libraries(odmbc_pgsql ${PostgreSQL_LIBRARIES})

    set_target_properties(odmbc_pgsql PROPERTIES COMPILE_FLAGS "-O0")

	set_target_properties(odmbc_pgsql
		PROPERTIES COMPILE_FLAGS "-DPGSQL_SUPPORT=1")
else (PostgreSQL_FOUND)
	message(WARNING "PostgreSQL installation not found")
endif (PostgreSQL_FOUND)

find_package(SQLite3)
if (SQLITE3_FOUND)
	message("Found SQLite3 installation!")
	message("SQLITE3_INCLUDE_DIRS = " "${SQLITE3_INCLUDE_DIRS}")
	message("SQLITE3_LIBRARIES    = " "${SQLITE3_LIBRARIES}")
	include_directories(${SQLITE3_INCLUDE_DIRS})

	add_module(odmbc_sqlite sqlite ${all_deps})
	target_link_libraries(odmbc_sqlite ${SQLITE3_LIBRARIES})

    set_target_properties(odmbc_sqlite PROPERTIES COMPILE_FLAGS "-O0")

	set_target_properties(odmbc_sqlite
		PROPERTIES COMPILE_FLAGS "-DSQLITE_SUPPORT=1")
else (SQLITE3_FOUND)
	message(WARNING "SQLite3 installation not found")
endif (SQLITE3_FOUND)

find_package(MySQL)
if (MYSQL_FOUND)
	message("Found MySQL installation!")
	message("MYSQL_INCLUDE_DIR = " "${MYSQL_INCLUDE_DIR}")
	message("MYSQL_LIBRARY     = " "${MYSQL_LIBRARY}")
	include_directories(${MYSQL_INCLUDE_DIR})

	add_module(odmbc_mysql mysql ${all_deps})
	target_link_libraries(odmbc_mysql ${MYSQL_LIBRARY})

    set_target_properties(odmbc_mysql PROPERTIES COMPILE_FLAGS "-O0")

	#add_module(odmbc_mysql_static mysql ${all_deps})
	#target_link_libraries(odmbc_mysql_static mysqlclient.a)

	set_target_properties(odmbc_mysql
		PROPERTIES COMPILE_FLAGS "-DMYSQL_SUPPORT=1")
else (MYSQL_FOUND)
	message(WARNING "MySQL installation not found")
endif (MYSQL_FOUND)
