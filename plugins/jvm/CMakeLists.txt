find_package(JNI)
find_package(Java)
if (ruby)
if (JNI_FOUND AND JAVA_FOUND)

	add_custom_command(
		OUTPUT
			java/src/org/nwnx/nwnx2/jvm/NWScript.java
			org_nwnx_nwnx2_jvm_NWScript.cpp
			org_nwnx_nwnx2_jvm_registerNWScript.cpp
			org_nwnx_nwnx2_jvm_NWScript.h
		DEPENDS
			build/funcs.nss build/gen_java.rb
		COMMAND
			${ruby} ./build/gen_java.rb ./build/funcs.nss
	)

	add_custom_command(OUTPUT nwnxjvm_NWScript.h
		COMMAND javah -jni -o nwnxjvm_NWScript.h nwnxjvm.NWScript
	)

	include_directories(${JNI_INCLUDE_DIRS})
	add_module(jvm NWNXJVM plugin-jvm
		org_nwnx_nwnx2_jvm_NWScript
		org_nwnx_nwnx2_jvm_NWScript_addon)
	target_link_libraries(jvm ${JAVA_JVM_LIBRARY})

    set_target_properties(jvm PROPERTIES COMPILE_FLAGS "-O0")

	add_subdirectory(java)
else (JNI_FOUND AND JAVA_FOUND)
	message(WARNING "Cannot find java libraries")
endif (JNI_FOUND AND JAVA_FOUND)
else (ruby)
	message(WARNING "Cannot compile nwnx_jvm until you install ruby")
endif (ruby)
