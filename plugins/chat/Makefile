NWNXDIR  = ../..
CPPFLAGS = $(PLUGIN_CPPFLAGS) -I$(NWNXDIR)
LFLAGS   = $(PLUGIN_LFLAGS)

all: nwnx_chat.so

nwnx_chat.so: HookChat.o NWNXChat.o plugin-chat.o
	$(CXX) $(LFLAGS) -o $@ $^ $(LIBS)

clean:
	/bin/rm -f *.o *.so *~

distclean: clean
	/bin/rm -f Makefile

install: nwnx_chat.so
	mkdir -p /usr/local/share/nwn/ ; install nwnx_chat.so /usr/local/share/nwn/
