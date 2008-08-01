CXX = g++
LIBS = 
# -lpthread 
# -lz
# -lpcap -L/usr/lib/mysql -lmysqlclient
FLAGS = -w -fPIC -shared -W -Wall -Llib/
DEFS = -DHAVE_CONFIG_H

# TODO: snarf from configure somehow
# the user should be able to specify NWNXDIR
# if NWNXDIR is not specified, configure should
# probe (.. ../linnwnx2) and die if not found.
# NWNXDIR = @NWNXDIR@
NWNXDIR = ../..

# CFLAGS = -g -O2 -I$(NWNXDIR)
# CXXFLAGS= -g -O2 $(CFLAGS)
CPPFLAGS = -mtune=i386 -I$(NWNXDIR)

NWNXBASE=$(NWNXDIR)/NWNXBase.o $(NWNXDIR)/gline.o
# $(NWNXDIR)/db/data.o $(NWNXDIR)/db/dbmysql.o 

all: nwnx_profiler.so

nwnx_profiler.so: hash.o HookRunScript.o NWNXProfiler.o plugin-profiler.o $(NWNXBASE)
	$(CXX) $(FLAGS) -o $@ $^ $(LIBS) $(DEFS) 

#plugin-t: plugin-t.o $(NWNXBASE)
#	$(CXX) -o $@ $(CXXFLAGS) $^ -ldl

clean:
	/bin/rm -f *.o *.so

distclean: clean
	/bin/rm -f Makefile
