find_library(MHASH_LIBRARY mhash)
find_library(UUID_LIBRARY uuid)

if (UUID_LIBRARY)
if (MHASH_LIBRARY)
add_module(mhash
    NWNXMHash
    plugin-mhash
)

target_link_libraries(mhash ${MHASH_LIBRARY} ${UUID_LIBRARY})

endif (MHASH_LIBRARY)
endif (UUID_LIBRARY)
