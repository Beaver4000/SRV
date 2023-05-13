all: barrier

barrier: barrier.o
	gcc -o barrier barrier.o

barrier.o: barrier.c
	gcc -c barrier.c

clean:
	rm -rf barrier *.o