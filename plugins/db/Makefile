NWNXDIR  = ../..
CPPFLAGS = $(PLUGIN_CPPFLAGS) -I$(NWNXDIR)
LFLAGS   = $(PLUGIN_LFLAGS)

LIBS     = -L/usr/lib/mysql -lmysqlclient -lz

all: nwnx_odbc.so

nwnx_odbc.so: NWNXmysql.o plugin-mysql.o data.o dbmysql.o
	$(CXX) $(LFLAGS) -o $@ $^ $(LIBS)

clean:
	/bin/rm -f *.o *.so *~

distclean: clean
	/bin/rm -f Makefile

install: nwnx_odbc.so
	mkdir -p /usr/local/share/nwn/ ; install nwnx_odbc.so /usr/local/share/nwn/
