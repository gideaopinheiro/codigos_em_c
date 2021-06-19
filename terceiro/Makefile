CC=gcc
CFLAGS=-Wall -g
BINS=terceiro mymath.so
all: $(BINS)

mymath.o: mymath.c mymath.h
	$(CC) $(CFLAGS) -c mymath.c

mymath.so: mymath.c mymath.h
	$(CC) $(CFLAGS) -fPIC -shared -o $@ terceiro.c -lc

terceiro: terceiro.c mymath.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm *.o $(BINS)
