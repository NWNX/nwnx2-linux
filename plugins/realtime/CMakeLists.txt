if (gperf)

add_gperf_target(realtime RealTimeStrCmds RealTimeStr REALTIME STR)

add_module(realtime NWNXRealTime plugin-realtime
    RealTimeStrCmds f_RealTime)

set_target_properties(realtime PROPERTIES COMPILE_FLAGS "-O0")

endif (gperf)
