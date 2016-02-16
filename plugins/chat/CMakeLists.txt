include_directories(
    ../..
    .
)

add_module(chat
    HookChat
    NWNXChat
    plugin-chat)

set_target_properties(chat PROPERTIES COMPILE_FLAGS "-O0")