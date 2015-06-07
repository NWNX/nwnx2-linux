include_directories(
    ../..
    .
)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-return-type")

add_module(chat
    HookChat
    NWNXChat
    plugin-chat)
