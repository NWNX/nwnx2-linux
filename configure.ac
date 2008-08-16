# Process this file with autoconf to produce a configure script.
AC_INIT(FULL-PACKAGE-NAME, VERSION, BUG-REPORT-ADDRESS)
# AC_CONFIG_SRCDIR([linnwnx2])
AC_CONFIG_HEADER([config.h])

# EXTREMELY IMPORTANT! MUST NOT BE OVERRIDDEN!
LFLAGS="$LFLAGS"
CFLAGS="-mtune=i386 -pipe $CFLAGS"
CPPFLAGS="-mtune=i386 -pipe $CPPFLAGS"

AC_ARG_ENABLE(debug,
  [  --enable-debug      compile with debugging symbols])
if test "$enable_debug" = "yes"; then
	CFLAGS="-g $CFLAGS"
	CPPFLAGS="-g $CPPFLAGS"
	LDFLAGS="-g $LDFLAGS"
fi

AC_ARG_WITH(glibc24,
  [  --without-glibc24   disable the stack protector from GLIBC_2.4])
if test "$with_glibc24" = "no"; then
	CFLAGS="-fno-stack-protector $CFLAGS"
	CPPFLAGS="-fno-stack-protector $CPPFLAGS"
	LDFLAGS="-fno-stack-protector $LDFLAGS"
fi

AC_ARG_WITH(extraplugins,
  [  --with-extraplugins="list of plugins"  config and compile other plugins ])
# echo "** with_extraplugins = $with_extraplugins"
if test -n "$with_extraplugins"; then
	extraplugindirs=$with_extraplugins
	# plugin1/Makefile plugin2/Makefile plugin3/Makefile ...
	for i in $extraplugindirs; do
		extraplugins="$extraplugins$i/Makefile "
	done
fi

AC_SUBST(EXTRAPLUGINDIRS,$extraplugindirs)

# NOTE!!!
# plugin dependencies belong in the plugin directories!!!
# TODO: AC_CONFIG_SUBDIRS

# db is fairly complex so it warrants its own subconfig
# AC_CONFIG_SUBDIRS(db)

# where the nwn installer installs the game files
AC_PREFIX_DEFAULT([/usr/local/share/nwn])

# Checks for programs.
AC_PROG_CC
AC_PROG_CXX
# Command line argument used for debug. Tenkawa

# Checks for header files.
AC_HEADER_STDC
AC_HEADER_SYS_WAIT
AC_CHECK_HEADERS([fcntl.h netinet/in.h stdlib.h string.h sys/ioctl.h sys/mman.h sys/socket.h sys/time.h unistd.h dlfcn.h],,[echo configure cannot find necessary include files. ; exit 1])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_TYPE_SIZE_T
# Checks for library functions.
AC_FUNC_MALLOC
AC_CHECK_FUNCS([bzero getspnam])

AC_CHECK_SIZEOF(void *)
if test "$ac_cv_sizeof_void_p" = "8"; then
	CFLAGS="-m32 $CFLAGS"
	CPPFLAGS="-m32 $CPPFLAGS"
	LDFLAGS="-m32 $LDFLAGS"
fi

# zlib, move to db subdir's config
AC_CHECK_LIB(z, inflateEnd,[true],[echo Unable to find -lz \(zlib\).  Please install a zlib developer\'s package. ; exit 1])

AC_CONFIG_FILES([
        Makefile
        plugins/chat/Makefile
        plugins/db/Makefile
        plugins/defenses/Makefile
        plugins/events/Makefile
        plugins/fixes/Makefile
        plugins/funcs/Makefile
        plugins/functions/Makefile
        plugins/hashset/Makefile
        plugins/mnx/Makefile
        plugins/odmbc/Makefile
        plugins/profiler/Makefile
        plugins/reset/Makefile
        plugins/resman/Makefile
        plugins/ruby/Makefile
        plugins/structs/Makefile
        plugins/tmi/Makefile
        plugins/weapons/Makefile
        $extraplugins ])

AC_OUTPUT
