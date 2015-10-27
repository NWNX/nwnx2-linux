include_directories(.)

add_module(statsd NWNXStatsd plugin-statsd statsd_client)

set_target_properties(statsd PROPERTIES
        COMPILE_FLAGS "-Wno-deprecated -Wno-return-type")

target_link_libraries(statsd rt)
