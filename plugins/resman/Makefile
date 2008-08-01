CXX = g++
LIBS = 
FLAGS = -w -fPIC -shared -W -Wall -Llib/
DEFS = -DHAVE_CONFIG_H

NWNXDIR = ..

# CFLAGS = -g -O2 -I$(NWNXDIR)
# CXXFLAGS= -g -O2 $(CFLAGS)
CPPFLAGS = -mcpu=i386 -I$(NWNXDIR)

NWNXBASE=$(NWNXDIR)/NWNXBase.o $(NWNXDIR)/gline.o
# $(NWNXDIR)/db/data.o $(NWNXDIR)/db/dbmysql.o 

all: nwnx_resman.so

nwnx_resman.so: HookDemandRes.o NwnDefines.o NWNXResMan.o plugin-resman.o $(NWNXBASE)
	$(CXX) $(FLAGS) -o $@ $^ $(LIBS) $(DEFS) 

#plugin-t: plugin-t.o $(NWNXBASE)
#	$(CXX) -o $@ $(CXXFLAGS) $^ -ldl

clean:
	/bin/rm -f *.o *.so

distclean: clean
	/bin/rm -f Makefile

install: all
	mkdir -p /home/dumbo/test/
