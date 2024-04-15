CC=gcc
FLAGS=-Wall -Wextra

all: main
	./main

main: main.c arvBin.o
	$(CC) $(FLAGS) arvBin.o main.c -o main

arvBin.o: arvBin.c arvBin.h
	$(CC) $(FLAGS) -c arvBin.c

clean:
	rm -f *.o

purge:
	rm -f main
purge: clean
