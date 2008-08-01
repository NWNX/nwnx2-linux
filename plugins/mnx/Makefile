NWNXDIR  = ../..
CPPFLAGS = $(PLUGIN_CPPFLAGS) -I$(NWNXDIR)
LFLAGS   = $(PLUGIN_LFLAGS)

all: nwnx_mnx.so

nwnx_mnx.so: NWNXmnx.o plugin-mnx.o
	$(CXX) $(LFLAGS) -o $@ $^ $(LIBS)

clean:
	/bin/rm -f *.o *.so *~

distclean: clean
	/bin/rm -f Makefile

install: nwnx_mnx.so
	mkdir -p /usr/local/share/nwn/ ; install nwnx_mnx.so /usr/local/share/nwn/
