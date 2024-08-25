CC=gcc
CFLAGS+=-O0 -g3

all:
	$(CC) $(CFLAGS)

clean:
	ls | grep -v "\." | grep -v Makefile | xargs rm
