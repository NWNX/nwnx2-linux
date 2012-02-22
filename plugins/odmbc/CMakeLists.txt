set(all_deps HookSCORCO CExoString ObjectStorage NWNXodbc plugin-odbc)

find_library(lmysql mysqlclient)
if (lmysql)
	add_module(odmbc_mysql_dynamic mysql ${all_deps})
	target_link_libraries(odmbc_mysql_dynamic mysqlclient)

	add_module(odmbc_mysql_static mysql ${all_deps})
	target_link_libraries(odmbc_mysql_static mysqlclient.a)

	set_target_properties(odmbc_mysql_dynamic odmbc_mysql_static
		PROPERTIES
			COMPILE_FLAGS "-DMYSQL_SUPPORT=1"
	)
else (lmysql)
	message(WARNING "Cannot find mysql libraries, not building nwnx_mysql")
endif (lmysql)

find_library(lpq pq)
if (lpq)
	add_module(odmbc_pq_dynamic pgsql ${all_deps})
	target_link_libraries(odmbc_pq_dynamic pq)

	set_target_properties(odmbc_pq_dynamic
		PROPERTIES
			COMPILE_FLAGS "-DPGSQL_SUPPORT=1"
	)
else (lpq)
	message(WARNING "Cannot find pq libraries, not building nwnx_pgsql")
endif (lpq)

find_library(lsqlite sqlite3)
if (lsqlite)
	add_module(odmbc_sqlite_dynamic sqlite ${all_deps})
	target_link_libraries(odmbc_sqlite_dynamic sqlite3)

	add_module(odmbc_sqlite_static sqlite ${all_deps})
	target_link_libraries(odmbc_sqlite_static sqlite3.a)

	set_target_properties(odmbc_sqlite_dynamic odmbc_sqlite_static
		PROPERTIES
			COMPILE_FLAGS "-DSQLITE_SUPPORT=1"
	)
else (lsqlite)
	message(WARNING "Cannot find sqlite libraries, not building nwnx_sqlite")
endif (lsqlite)
