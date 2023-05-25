CC = gcc
CFLAGS = -Wall -g

build: main

main: main.o citire.o
	$(CC) -o main $^

main.o: main.c
	$(CC) $(CFLAGS) -c $^

citire.o: citire.c
	$(CC) $(CFLAGS) -c $^

run: build
	./main

clean:
	rm -f *.o main