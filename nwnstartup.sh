#!/bin/sh

export LD_PRELOAD=./nwnx2.so
export LD_LIBRARY_PATH=lib/:$LD_LIBRARY_PATH

./nwserver \
	-publicserver 1 \
	-servername YourServerHere \
	-dmpassword yourpw \
	-oneparty 0 \
	-pvp 0 \
	-difficulty 2 \
	-elc 1 \
	-reloadwhenempty 0 \
	-module "YourModuleHere" \
	-maxclients 32 \
	-servervault 1 \
	-maxlevel 40 \
	-gametype 0 \
	-autosaveinterval 0 \
	"$@"

