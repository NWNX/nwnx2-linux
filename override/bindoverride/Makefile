CC     = gcc
OPTS   = -O2 -pipe
DEBUG  =
CFLAGS = -Wall -Werror -fno-stack-protector $(DEBUG)
LIBS   = -ldl

all: bindoverride.so

bindoverride.o: bindoverride.c
	$(CC) $(CFLAGS) -fPIC -o bindoverride.o -c bindoverride.c

bindoverride.so: bindoverride.o
	$(CC) $(CFLAGS) -fPIC -shared -o bindoverride.so bindoverride.o $(LIBS)

clean:
	/bin/rm -f *.o *.so
