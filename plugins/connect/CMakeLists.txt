include_directories(../../api)

# Ignore no return errors.
SET(CONNECT_CXX_FLAGS "-Wno-return-type" CACHE STRING
    "plugins/connect specific compiler flags.")

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CONNECT_CXX_FLAGS}")

add_module(connect ../../api/nwnsyms.S ../../api/all
	ConnectHooks NWNXConnect plugin-connect)
