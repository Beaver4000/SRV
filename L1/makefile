CFLAGS =-o

all: lab1 test

debug: lab1
	gcc -g $(CFLAGS) lab1_debug lab1.c

lab1: lab1.c
	gcc $(CFLAGS) lab1 lab1.c

test: test.c
	gcc $(CFLAGS) test test.c

clean:
	rm -rf lab1 test lab1_debug *.o
