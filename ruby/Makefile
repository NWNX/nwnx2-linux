CXX = g++
LIBS = -lruby-static -lcrypt
FLAGS = -w -fPIC -shared -W -Wall 
DEFS = -DHAVE_CONFIG_H

# TODO: snarf from configure somehow
# the user should be able to specify NWNXDIR
# if NWNXDIR is not specified, configure should
# probe (.. ../linnwnx2) and die if not found.
# NWNXDIR = @NWNXDIR@
NWNXDIR = ..

# CFLAGS = -g -O2 -I$(NWNXDIR)
# CXXFLAGS= -g -O2 $(CFLAGS)
CPPFLAGS = -mcpu=i386  -I$(NWNXDIR)

NWNXBASE=$(NWNXDIR)/NWNXBase.o $(NWNXDIR)/gline.o 

all: nwnx_ruby.so

nwnx_ruby.so: FunctionHooks.o ruby_int.o NWNXRuby.o plugin-ruby.o
	$(CXX) $(FLAGS) -o $@ $^ $(LIBS) $(DEFS)

plugin-t: plugin-t.o $(NWNXBASE)
	$(CXX) -o $@ $(CXXFLAGS) $^ -ldl

clean:
	/bin/rm -f *.o *.so *~ plugin-t

distclean: clean
	/bin/rm -f Makefile

install: all
	mkdir -p /home/nwn/ ; install nwnx_ruby.so /home/nwn/
