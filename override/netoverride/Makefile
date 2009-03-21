CC     = gcc
OPTS   = -O2 -pipe
DEBUG  =
CFLAGS = -Wall -Werror -fno-stack-protector $(DEBUG)
LIBS   = -ldl

all: netoverride.so

netoverride.o: netoverride.c
	$(CC) $(CFLAGS) -fPIC -o netoverride.o -c netoverride.c

netoverride.so: netoverride.o
	$(CC) $(CFLAGS) -fPIC -shared -o netoverride.so netoverride.o $(LIBS)

clean:
	/bin/rm -f *.o *.so
