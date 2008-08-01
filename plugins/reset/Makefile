NWNXDIR  = ../..
CPPFLAGS = $(PLUGIN_CPPFLAGS) -I$(NWNXDIR)
LFLAGS   = $(PLUGIN_LFLAGS)

all: nwnx_reset.so

nwnx_reset.so: NWNXReset.o plugin-reset.o
	$(CXX) $(LFLAGS) -o $@ $^ $(LIBS) $(DEFS)

clean:
	/bin/rm -f *.o *.so *~

distclean: clean
	/bin/rm -f Makefile

install: nwnx_reset.so
	mkdir -p /usr/local/share/nwn/ ; install nwnx_reset.so /usr/local/share/nwn/
