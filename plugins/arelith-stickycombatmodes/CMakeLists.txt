set(CMAKE_CXX_FLAGS "-m32 -mno-accumulate-outgoing-args -Wall -Wno-unused -Wno-return-type -Wno-write-strings -Werror -std=c++14 -fno-omit-frame-pointer -fno-rtti")
set(CMAKE_CXX_FLAGS_DEBUG "-DDEBUG -Og -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "-DRELEASE -O2 -s")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-DRELWITHDEBINFO -O2")

add_module(
    arelith_stickycombatmodes

    # Top level
	plugin-arelith_stickycombatmodes
    NWNXArelithStickyCombatModes

    # Hooks
    hooks/CNWSCreature__ToggleMode
    hooks/CNWSCreature__SetCombatMode
)

target_include_directories(
    arelith_stickycombatmodes

    PRIVATE "."
    PRIVATE "../../lib-arelith")