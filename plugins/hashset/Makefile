NWNXDIR  = ../..
CPPFLAGS = $(PLUGIN_CPPFLAGS) -I$(NWNXDIR)
LFLAGS   = $(PLUGIN_LFLAGS)

all: nwnx_hashset.so

nwnx_hashset.so: NWNXHashSet.o plugin-hashset.o
	$(CXX) $(LFLAGS) -o $@ $^ $(LIBS)

clean:
	/bin/rm -f *.o *.so *~

distclean: clean
	/bin/rm -f Makefile

install: nwnx_hashset.so
	mkdir -p /usr/local/share/nwn/ ; install nwnx_hashset.so /usr/local/share/nwn/
