APS/NWNX for Linux
==================

** The documentation found in the doc/ directory is horribly out of date! **

** Please read the DEBUGLEVEL section **

IMPORTANT CHANGES
-----------------
- The zlib dependancy is back and now, configure will complain and bail
  if it cannot find it.  If you're compiling software, chances are you
  need it anyway.  RPM based distributions need to install zlib-devel.

- The configure script will add -mcpu=i386 to the compilation instructions.
  DO NOT OVERRIDE THIS or use -march=processor!

- The configure script accepts a new option, --enable-debug, to generate
  a version with debug symbols.  Needed for tracing core dumps.

- The configure script accepts a new option, --with-extraplugins="plugin1 
  plugin2 ..." that accepts a list of additional plugin directories to
  configure and compile.

- The hooked function can be called from parts of the server code other
  than the script VM.  This is the cause of the map pin and log in/out 
  crashes.

  To help the extender tell the difference between script context and the
  other parts of the code, it is required that your OnLoad script issues
  the following call:

    SetLocalString(oTgt,"NWNX!INIT","1");  // oTgt=GetModule();

- A new configuration option, disablenwnxinit=y, has been added to allow
  NWNX!INIT enforcement to be disabled.  The extender will get the information 
  it needs from the first call to SetLocalString with the "NWNX!" prefix.

  It is STRONGLY recommended that you do not enable this feature UNLESS
  you make APS or NWNX calls in your OnLoad script.

- The logrotate feature was removed.  If you depend on that feature you can
  either add equivalent functionality to nwstartup.sh or write a plugin.

- UnixODBC support has been removed.  If you need it please contact the
  developers (or send a patch!  We like patches :)

INSTALLATION
------------
The configure script has been rewritten so that it will install nwnx2.so,
the plugins and nwnx2.ini to /usr/local/share/nwn, the default game
installation path.  If you've installed in a separate location, please
use the --prefix option to change it.  If nwnx2.ini already exists it will
not overwrite it.

If the configure script is having troubles, you can regenerate it by issuing:
$ autoconf

Building:
$ ./configure [--prefix=/full/path/to/nwndir] [--enable-debug] [--with-extraplugins="plugin1 plugin2 ..."]
$ make install

- Copy nwnstartup.sh.example to nwnstartup.sh in the directory nwserver is in.
- Edit nwnx2.ini and nwnstartup.sh and put in relevant changes for your local 
  settings
- From your nwserver dir run nwnx like nwnstartup.sh by itself or in a while 
  loop like the following to have it autorestart on crash

while [ nwncheck != 1 ]
do
./nwnstartup.sh
done

PLUGINS
-------
The plugin framework will attempt to load any file in the current working 
directory that matches this pattern "nwnx_*.so".  The series of characters 
between the '_' and the '.so' will be used as that plugin's registration
key.

eg. nwnx_xyzzy.so --> XYZZY

Any NWNX!XYZZY!string commands sent to NWNX will be passed on to the plugin
registerred to that key for processing.

CONFIGURATION
-------------
The .ini file processor was replaced with a more generic parser.  Each plugin
will search the parsed nwnx2.ini for section key that matches its registration
key:

[XYZZY]
disabled=n

Each plugin honors the following common configs:
"disabled":		Y/N, If set to "Y" it prevents the plugin from registerring.
				Default is "N"

DEBUGLEVEL
----------
Each of the shared objects have their own log file and their own independent
debuglevel setting.  If unspecified, it will be set to the global debuglevel.

The messages have been segregated into priorities.  If a log message's priority
is <= the plugin's debuglevel, it will be written to the plugin's logfile.
Priority 0 is special.  It will be logged and sent to the console.

Each priority enables the lower priority messages in addition.

[NWNX] nwnx2.so:
 0: Errors
 1: Low frequency informational messages, recommended minimum debuglevel
 2: Context tracing
 3: Debugging

[Database] nwnx_odbc.so:
 0: Errors, recommended minimum debuglevel
 1: Enables dbmysql error messages
 2: Debug Request strings
 3: Debug Parameter strings

[MNX] nwnx_mnx.so:
 0: Errors, recommended minimum debuglevel
 1: Socket Send/Recv debugging
 2: Debug Request strings
 3: Debug Parameter strings

[FUNCTIONS] nwnx_functions.so:
 0: Errors, recommended minimum debuglevel
 1: n/a
 2: Debug Request strings
 3: Debug Parameter strings

[HASHSET] nwnx_hashset.so:
 0: Errors, recommended minimum debuglevel
 1: n/a
 2: Debug Request strings
 3: Debug Parameter strings
 4: Debug Results strings


The APS/NWNX Linux Conversion Group:
====================================

* Ingmar Stieger (Papillon), Project leader, Programmer
* Joel Martin (Garad Moonbeam), Programmer
* MaShaun Jones (Tenkawa), Programmer, Autoconf, second and third beta
* John Klar (PlasmaJohn), Programmer, plugins, beta4, beta5
* Mirko Bernardoni (Firedeath), Programmer, Database connectivity

Alpha testing and many ideas came from:
Blackwings, BriHurley, Carey Durbin, Kaldais, Lucindrea


Frequently asked questions:
===========================

Q. I get alot of messages about not being able to find mysql_connect, 
   mysql_open , etc.
A. The make and compile program looks for mysql in /usr/lib and /usr/lib/mysql 
   ... you may need to get the dev version of mysql.
   You might have to add the path to your libmysqlclient.so.? library to the 
   LD_PRELOAD statement in the nwnstartup.sh file.

Q. I get the message ""NWNX2: Couldn't find server. No such file:nwserver"
A. NWNX2 must be run in the same dir as nwserver.

Q. How do I write my own plugins?
A. Better documentation is forthcoming.  In the mean time, study the code
   for the Functions plugin
