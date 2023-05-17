CFLAGS =

all: lab1 test

lab1: labl.c
	gcc $(CFLAGS) -c lab1.c

test: test.c
	gcc $(CFLAGS) -c test.c

debug: lab1 test
debug: CFLAGS+=-g

clean:
	rm -rf lab1 test
