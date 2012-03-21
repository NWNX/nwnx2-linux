find_program(ant ant)
if (ruby AND ant)
	add_custom_command(
		OUTPUT
			src/org/nwnx/nwnx2/jvm/constants/All.java
		DEPENDS
			../build/consts.nss ../build/gen_const.rb
		COMMAND
			mkdir -p src/org/nwnx/nwnx2/jvm/constants &&
			cd .. &&
			${ruby} build/gen_const.rb build/consts.nss
	)

	add_custom_command(
		COMMENT "Building nwnx_jvm dist jarfile"
		OUTPUT
			dist/org.nwnx.nwnx2.jvm.jar
		DEPENDS
			src/org/nwnx/nwnx2/jvm/constants/All.java
			src/org/nwnx/nwnx2/jvm/NWScript.java
		COMMAND ant -q
	)
	
	add_custom_target(jar ALL
		DEPENDS dist/org.nwnx.nwnx2.jvm.jar
	)

else (ruby AND ant)
	message(WARNING "Cannot build nwnx_jvm jar until you install ant")
endif(ruby AND ant)
