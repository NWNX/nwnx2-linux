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
CPPFLAGS = -mcpu=i386 -I$(NWNXDIR)

NWNXBASE=$(NWNXDIR)/NWNXBase.o $(NWNXDIR)/gline.o
# $(NWNXDIR)/db/data.o $(NWNXDIR)/db/dbmysql.o 

all: nwnx_chat.so

nwnx_chat.so: HookChat.o NWNXChat.o plugin-chat.o $(NWNXBASE)
	$(CXX) $(FLAGS) -o $@ $^ $(LIBS) $(DEFS) 

#plugin-t: plugin-t.o $(NWNXBASE)
#	$(CXX) -o $@ $(CXXFLAGS) $^ -ldl

clean:
	/bin/rm -f *.o *.so

distclean: clean
	/bin/rm -f Makefile

install: all
	mkdir -p /home/dumbo/test/ ; install nwnx_speech.so /home/jeroen/applications/nwn//
