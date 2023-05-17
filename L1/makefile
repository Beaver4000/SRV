CFLAGS = -Wall

all: lab1 test

lab1: labl.o
	gcc $(CFLAGS) -o lab1 lab1.o

lab1.o: labl.c
	gcc $(CFLAGS) -c lab1.c

test: test.o
	gcc $(CFLAGS) -o test test.o

test.o: test.c
	gcc $(CFLAGS) -c test.c

debug: lab1 test
debug: CFLAGS+=-g

clean:
	rm -rf lab1 test *.o
