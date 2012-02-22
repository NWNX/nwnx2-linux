add_library(bindoverride SHARED bindoverride/bindoverride)
add_library(netoverride SHARED netoverride/netoverride)
add_library(openoverride SHARED openoverride/openoverride)

set_target_properties(
	bindoverride netoverride openoverride
	PROPERTIES PREFIX ""
)
