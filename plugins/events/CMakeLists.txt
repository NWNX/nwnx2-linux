include_directories(
    ../../
    .
)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-return-type")

add_module(events
    HookFunc
    NWNXEvents
    plugin-events
    ../../api/nwnsyms.S
    ../../api/all
)
