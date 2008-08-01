CXX = g++
LIBS = -L/usr/lib/mysql -lmysqlclient -lz
#LIBS = -L/usr/lib/mysql -L/usr/local/pgsql/lib -lpq -lmysqlclient -lz
FLAGS = -w -fPIC -shared -static -W -Wall -Llib/
DEFS = -DHAVE_CONFIG_H

NWNXDIR = ../..

# CFLAGS = -g -O2 -I$(NWNXDIR)
# CXXFLAGS= -g -O2 $(CFLAGS)
CPPFLAGS = -mcpu=i386 -I$(NWNXDIR)

NWNXBASE=$(NWNXDIR)/NWNXBase.o $(NWNXDIR)/gline.o
# $(NWNXDIR)/db/data.o $(NWNXDIR)/db/dbmysql.o 

all: nwnx_odbc.so

nwnx_odbc.so: HookSCORCO.o NWNXodbc.o mysql.o plugin-odbc.o $(NWNXBASE)
	$(CXX) $(FLAGS) -o $@ $^ $(LIBS) $(DEFS) 

clean:
	/bin/rm -f *.o *.so

distclean: clean
	/bin/rm -f Makefile

install: all
	mkdir -p /home/dumbo/test/
