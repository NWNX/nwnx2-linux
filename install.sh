#!/bin/sh

# Check for dependencies
abort=0
zlib=$(apt-cache pkgnames | grep zlib1g-dev)
mysql=$(apt-cache pkgnames | grep libmysqlclient-dev)
if [ $zlib != "zlib1g-dev" ]; then
	abort=1
fi
if [ $mysql != "libmysqlclient-dev" ]; then
	abort=1
fi

if [ $abort -eq 0 ] || [ $1 -eq "force" ]; then
	# Configure with all the extra plugins
	./configure --with-extraplugins="chat events fixes leto odmbc profiler resman structs tmi"

	# Compile
	make

	# Put the .so files in a directory
	mv ./nwnx2.so ./compiled/
	mv ./chat/nwnx_chat.so ./compiled/
	mv ./events/nwnx_events.so ./compiled/
	mv ./fixes/nwnx_fixes.so ./compiled/
	mv ./functions/nwnx_functions.so ./compiled/
	mv ./hashset/nwnx_hashset.so ./compiled/
	mv ./leto/nwnx_leto.so ./compiled/
	mv ./mnx/nwnx_mnx.so ./compiled/
	mv ./odmbc/nwnx_odbc.so ./compiled/
	mv ./profiler/nwnx_profiler.so ./compiled/
	mv ./resman/nwnx_resman.so ./compiled/
	mv ./structs/nwnx_structs.so ./compiled/
	mv ./tmi/nwnx_tmi.so ./compiled
	cp ./nwnstartup.sh ./compiled/
	cp ./nwnx2.ini ./compiled/

	# Clean up
	make clean
	make distclean

	# Success!
	echo "NWNX has been compiled. Look in the 'compiled' directory for the libraries - these should be copied into your NWN directory. Change NWNX2.ini and nwnstartup.sh to match your server's settings."
else
	echo "You are missing some packages: please make sure zlib1-dev and libmysqlclient-dev are installed. If you are not using apt package manager, try './install.sh force' instead."
fi