add_module(events
    HookFunc
    NWNXEvents
    plugin-events
)

set_target_properties(events PROPERTIES COMPILE_FLAGS "-O0")
