## NWNX2 for Linux

### Building

If you don't want to compile NWNX2 yourself pre-compiled binaries are available at niv's [continuous integration server](http://www.nwnx.org/phpBB2/viewtopic.php?t=1775)

#### Getting the source

    git clone https://github.com/NWNX/nwnx2-linux.git

#### Installing dependencies

For Debian/Ubuntu based systems dependencies are listed in `apt-dep` files in the source tree.  For other systems you will need to translate these into what your package manager expects.

At minimum you will need to install the dependencies for the core library:

    cat apt-dep | xargs sudo apt-get install -y

If a plugin doesn't compile due to missing dependencies, warnings will be emitted.  To install them:

    cat plugins/<plugin>/apt-dep | xargs sudo apt-get install -y

If you want to install all dependencies:

    find . -name apt-dep -exec cat {} \; | xargs sudo apt-get install -y

#### Example build

* `git clone https://github.com/NWNX/nwnx2-linux.git`
* `cd nwnx2-linux`
* `find . -name apt-dep -exec cat {} \; | xargs sudo apt-get install` (check list carefully before pressing enter!)
* `mkdir build && cd build`
* `cmake ..`
* `make`

When completed, all libraries and configuration files will be in the `compiled` subdirectory of your build directory.

#### Building on a 64bit host system

This is a bit more involved. You need to install the relevant 32bit toolchain and libraries.

Please note that when compiling on a 64bit host, you **cannot use the apt-dep** as shown above. You will have to install all wnanted dependencies manually by installing the :i386 variants of packages, like so:

* `sudo dpkg --add-architecture i386 && sudo apt-get update`
* `sudo apt-get install libsqlite3-dev:i386`

Then grab multilib support for gcc, and compile:

* `sudo apt-get install gcc-multilib g++-multilib`
* `CC="gcc -m32" CXX="g++ -m32" cmake .`

### Installing

NWNX2 should be installed in the same directory as your NWN installation.  You can do this by copying and/or symlinking `nwnx2.so`, `nwnx2.ini`, `nwnstartup.sh` and any plugins that interest you into your NWN directory.

### Configuring

#### Edit nwnx2.ini

The NWNX2 build system creates a `nwnx2.ini` file for you, which has sensible defaults for NWNX2 and most plugins.

Configuration options for NWNX2 core:

    [NWNX]
    disablenwnxinit=n     # Set to "y" to disable the NWNX!INIT requirement.
                          # If you do this, it's a very good idea to make sure
                          # a NWNX plugin is called early in your OnModLoad
                          # script.
    [Debug]
    debuglevel=0          # Set to 1 or higher to output successively
                          # verbose debug information
    [LogDir]
    logdir=logs.0         # Set to the relative root of the log directory.

If you set `disablenwnxinit=n` you **must** call `SetLocalString(GetModule(),"NWNX!INIT","1");` in your module load event script.

NWNX2 core debug levels:

    0 - Errors
    1 - Low frequency informational messages, recommended minimum debuglevel
    2 - Context tracing
    3 - Debugging

The debug level is global to all plugins, so check their READMEs to find out what information they log at each level.

#### Edit nwnstartup.sh

Modify or add command line options to match your desired server settings.

If you'd like to use any of the [overrides](https://github.com/NWNX/nwnx2-linux/tree/master/override) they need to be added to this file as well.

Suppose you'd like to use the netoverride, to do that you'd:

* Copy netoverride.so into your NWN directory along with NWNX.
* Add the library to the LD_PRELOAD variable in nwnstartup.sh.  Each library
  is separated by **:** so you'd change `export LD_PRELOAD=./nwnx2.so` to
  `export LD_PRELOAD=./nwnx2.so:./netoverride.so`

The process for adding the others would be the same.  

### Original Contributors

* Ingmar Stieger (Papillon), Project leader, Programmer
* Joel Martin (Garad Moonbeam), Programmer
* MaShaun Jones (Tenkawa), Programmer, Autoconf, second and third beta
* John Klar (PlasmaJohn), Programmer, plugins, beta4, beta5
* Mirko Bernardoni (Firedeath), Programmer, Database connectivity

Alpha testing and many ideas came from:
Blackwings, BriHurley, Carey Durbin, Kaldais, Lucindrea

