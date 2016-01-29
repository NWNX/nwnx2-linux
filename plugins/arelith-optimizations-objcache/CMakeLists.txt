set(CMAKE_CXX_FLAGS "-m32 -mno-accumulate-outgoing-args -Wall -Wno-unused -Wno-return-type -Wno-write-strings -Werror -std=c++14 -fno-omit-frame-pointer -fno-rtti")

# We ALWAYS want to compile with full optimizations.
# It's very important that the standard library containers are fast here.
set(CMAKE_CXX_FLAGS_DEBUG "-DRELEASE -O2 -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "-DRELEASE -O2 -s")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-DRELWITHDEBINFO -O2")

add_module(
    arelith_optimizations_objcache

    # Top level
	plugin-arelith_optimizations_objcache
    NWNXArelithOptimizationsObjCache

    # Hooks
    hooks/CGameObjectArray
    hooks/CGameObjectArray__AddInternalObject
    hooks/CGameObjectArray__AddObjectAtPos
    hooks/CGameObjectArray__Delete__0
    hooks/CGameObjectArray__Delete__1
    hooks/CGameObjectArray__GetGameObject
)

target_include_directories(
    arelith_optimizations_objcache

    PRIVATE "."
    PRIVATE "../../lib-arelith")