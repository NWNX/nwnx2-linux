MV     = mv
CP     = cp
CC     = gcc
SED    = sed
GPERF  = gperf
OPTS   = -O2 -pipe
DEBUG  =
CFLAGS = -Wall -Werror -fno-stack-protector $(DEBUG)
LIBS   = -ldl

all: openoverride.so

openoverride.h: openoverride.gperf
	$(GPERF) -L ANSI-C -tG -m 10 -K name -H oo_hash -N oo_lookup -W oo_list \
	  "openoverride.gperf" --output-file="gperf.out"
	$(SED) -i 's/\<\(\(MIN\|MAX\)_\(WORD_LENGTH\|HASH_VALUE\)\|TOTAL_KEYWORDS\)\>/OPENOVERRIDE_HASH_\1/g' \
	  "gperf.out" || rm -f "gperf.out"
	$(SED) -i 's/^const struct/static const struct/' "gperf.out" || rm -f "gperf.out"
	$(MV) "gperf.out" "openoverride.h"

openoverride.o: openoverride.c openoverride.h
	$(CC) $(CFLAGS) -fPIC -o openoverride.o -c openoverride.c

openoverride.so: openoverride.o
	$(CC) $(CFLAGS) -fPIC -shared -o openoverride.so openoverride.o $(LIBS)

clean:
	/bin/rm -f *.o *.so
