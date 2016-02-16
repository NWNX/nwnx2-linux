find_library(MHASH_LIBRARY mhash)
find_library(UUID_LIBRARY uuid)

if (UUID_LIBRARY)
if (MHASH_LIBRARY)
add_module(mhash
    NWNXMHash
    plugin-mhash
)

target_link_libraries(mhash ${MHASH_LIBRARY} ${UUID_LIBRARY})

set_target_properties(mhash PROPERTIES COMPILE_FLAGS "-O0")

endif (MHASH_LIBRARY)
endif (UUID_LIBRARY)
