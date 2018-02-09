add_module(damage Hooks NWNXDamage plugin-damage)

set_target_properties(damage PROPERTIES COMPILE_FLAGS "-O0")
