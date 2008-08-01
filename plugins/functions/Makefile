NWNXDIR  = ../..
CPPFLAGS = $(PLUGIN_CPPFLAGS) -I$(NWNXDIR)
LFLAGS   = $(PLUGIN_LFLAGS)

all: nwnx_functions.so

nwnx_functions.so: C2DA.o CNWSScriptVarTable.o CExoLinkedList.o CItemRepository.o CExoLocString.o FunctionHooks.o NWNXFunction.o plugin-functions.o
	$(CXX) $(LFLAGS) -o $@ $^ $(LIBS)

clean:
	/bin/rm -f *.o *.so *~

distclean: clean
	/bin/rm -f Makefile

install: nwnx_functions.so
	mkdir -p /usr/local/share/nwn/ ; install nwnx_functions.so /usr/local/share/nwn/
