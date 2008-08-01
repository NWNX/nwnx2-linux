CXX = g++
FLAGS = -w -fPIC -shared -W -Wall 
DEFS = -DHAVE_CONFIG_H

###################################################
# Note: If you're getting missing symbols like
# compress, deflate, etc. add -lz to the end of
# the next line and rerun configure
LIBS =  -L/usr/lib/mysql -lmysqlclient -lz

# TODO: snarf from configure somehow
# the user should be able to specify NWNXDIR
# if NWNXDIR is not specified, configure should
# probe (.. ../linnwnx2) and die if not found.
# NWNXDIR = @NWNXDIR@
NWNXDIR = ../..

# CFLAGS = -g -O2 -I$(NWNXDIR)
# CXXFLAGS= -g -O2 $(CFLAGS)
CPPFLAGS = -mtune=i386  -I$(NWNXDIR)

NWNXBASE=$(NWNXDIR)/NWNXBase.o $(NWNXDIR)/gline.o 

all: nwnx_odbc.so

# dbodbc.o
nwnx_odbc.so: NWNXmysql.o plugin-mysql.o data.o dbmysql.o
	$(CXX) $(FLAGS) -o $@ $^ $(LIBS) $(DEFS)

plugin-t: plugin-t.o $(NWNXBASE)
	$(CXX) -o $@ $(CXXFLAGS) $^ -ldl

clean:
	/bin/rm -f *.o *.so *~ plugin-t

distclean: clean
	/bin/rm -f Makefile

install: all
	mkdir -p /usr/local/share/nwn/ ; install nwnx_odbc.so /usr/local/share/nwn/
