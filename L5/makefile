all: timeout

timeout: timeout.o
	gcc -o timeout timeout.o

timeout.o: timeout.c
	gcc -c timeout.c

clean:
	rm -rf timeout *.o