cmake_policy(SET CMP0015 NEW)

find_package(Boost 1.35 COMPONENTS thread)
if (Boost_FOUND)
include_directories(${Boost_INCLUDE_DIR})

include_directories(hiredis/)
link_directories(hiredis/)

add_module(redis NWNXRedis HookFunc plugin-redis
	hiredis/hiredis
	hiredis/net
	hiredis/sds
	hiredis/dict
	hiredis/async
)
target_link_libraries(redis ${Boost_LIBRARIES})

endif (Boost_FOUND)
