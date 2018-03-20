add_module(sortset NWNXSortSet plugin-sortset SortSetImpl)

set_target_properties(sortset PROPERTIES COMPILE_FLAGS "-O0")