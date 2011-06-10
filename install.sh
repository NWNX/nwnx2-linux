#!/bin/sh

set -e

extraplugins=""
MAKESTR=""

if [ `uname -p` = "x86_64" ]; then
	echo "nwnx2 does not build on x64 currently."
	exit 1
fi

echo "Hello. I'll be trying to help you compile nwnx2 successfully."
echo ""

if [ "$@"x != "x" ]; then
	echo "You have given me the following arguments: $@"
	echo "The only arguments I ever accept are extra plugins that you want to build."

	for plugin in $@; do
		if [ ! -f plugins/$plugin/Makefile.in ]; then
			echo "Cannot find plugin: $plugin"
			exit 1
		fi
		extraplugins="$extraplugins plugins/$plugin"
		echo "Building out-of-tree plugin: $plugin"
	done
	echo "Note that these plugins may require individual configuration not covered here."
	echo ""
else
	echo "If you want to build any out-of-tree plugins press CTRL-C now and
give them to me as arguments (for example: ./install.sh jvm)"
fi

packages=""

while true; do
echo -n "Database support: Do you want mySQL, sqlite3, or pgsql, or none [mspn]? "
read dbtype
case "$dbtype" in
	[Mm]*)
		dbtype=mysql
		MAKESTR="MYSQL_SUPPORT=1"
		packages="libmysqlclient16 libmysqlclient-dev"
		;;
	[Ss]*)
		dbtype=sqlite
		MAKESTR="SQLITE_SUPPORT=1"
		packages="libsqlite3-0 libsqlite3-dev"
		;;
	[Pp]*)
		dbtype=pgsql
		MAKESTR="PGSQL_SUPPORT=1"
		packages="libpq5 libpq-dev"
		;;
	[n]*)
		dbtype=none
		;;
	*)
		echo "Select one of m[ysql], s[qlite], p[ostgres], or n[one]."
		continue
		;;
esac
break
done
echo ""
if [ $dbtype = "none" ]; then
	echo "NOT building any database support!"
else
	echo "Selecting $dbtype as the database plugin to build."
fi
echo ""

packages="autoconf make build-essential gcc g++ zlib1g-dev $packages"

echo "If you have problems and think that something leftover from a
previous build is interfering, try running 'make clean' before
atempting another build."
echo ""
echo "Please make sure the following packages are installed:"
echo " $packages (on Debian and Ubuntu, YMMV.)"
echo "And then press enter when ready."
read whatever

rm -r compiled || true
mkdir -vp ./compiled/lib

autoconf

sh ./configure --with-extraplugins="$extraplugins"

make $MAKESTR

cp -v ./nwnstartup.sh ./compiled/
cp -v ./nwnx2.ini ./compiled/
for p in plugins/*/; do
	if [ -f $p/*.so ]; then
		if [ -f $p/nwnx2.ini ]; then
			echo ""  >> ./compiled/nwnx2.ini
			echo ""  >> ./compiled/nwnx2.ini
			cat $p/nwnx2.ini >> ./compiled/nwnx2.ini
		fi
		if [ -f $p/lib/* ]; then
			cp -v $p/lib/* ./compiled/lib
		fi
	fi
done
mv -v ./plugins/*/*.so ./compiled/
mv -v ./nwnx2.so ./compiled/
if [ "$dbtype" != "none" ] ; then
	mv -v ./compiled/nwnx_odbc_${dbtype}.so ./compiled/nwnx_odbc.so
	cp -v ./plugins/odmbc/lib/${dbtype}/* ./compiled/lib
fi

echo ""
echo ""
echo "NWNX has been compiled successfully."
echo " - Look in the 'compiled' directory for the libraries."
echo " -- These should be copied into your NWN directory."
echo " -- Include lib/ if you cannot or do not want to install required shared libraries."
echo "     (If you have compiled this successfully, they're already installed. They are"
echo "      provided for your convenience if you want to run nwserver on another system.)"
echo ""
echo " - Read & change nwnx2.ini carefully."
echo " - Edit nwnstartup.sh to match your desired server settings."
echo ""
echo "Have fun!"
