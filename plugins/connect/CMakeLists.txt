include_directories(../../api)
add_module(connect ../../api/nwnsyms.S ../../api/all
	ConnectHooks NWNXConnect plugin-connect)
