CC=gcc
CFLAGS+=-O0 -g3 -lm

all:
	$(CC) $(CFLAGS)

clean:
	rm -f *.o
	ls | grep -v "\." | grep -v Makefile | xargs rm
