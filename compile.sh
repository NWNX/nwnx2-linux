#!/bin/sh

set -e

if [ `uname -p` = "x86_64" ]; then
	echo "nwnx2 does not build on x64."
	echo "Try running this in a 32bit chroot."
	exit 1
fi


echo "
=====

This script compiles nwnx2 for linux.

You will need the following packages installed to compile the core:

  cmake, build-essential (including gcc, make, bintools ..), gzlib1-dev

A lot of plugins depend on 'gperf' to generate lookup tables, but it is not
strictly required to compile the core.

This is a non-exhaustive list of plugin dependencies:

  * odmbc-mysql: libmysqlclient-dev
  * odmbc-pq: libpq-dev
  * odmbc-sqlite: libsqlite3-dev
  * ruby: libruby1.8-dev
  * jvm: any recent java jdk with jni headers
  * lua: liblua5.1-dev
  * vaultster: libboost-system-dev, libboost-boost-program-options-dev

You will see warnings emitted for plugins that cannot be compiled due to
missing dependencies.

=====

Press enter to begin.
"

read x

cmake .
make all

echo "
=====

NWNX has been compiled successfully.

- Look in the 'compiled' directory for the libraries.
- Copy those that you want to use into your NWN server directory.

IMPORTANT:
- In the case of multiple so files and/or dynamic and static
  variants (for example, the odmbc plugin), choose only one.
  If you're running wserver the same host that you are compiling on,
  the dynamic one is recommended.
  static binaries include the database connector linked in.

- Read & change nwnx2.ini carefully.
- Edit nwnstartup.sh to match your desired server settings.

Have fun!

====="
