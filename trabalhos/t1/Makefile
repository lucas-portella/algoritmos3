# a compilacao so funciona em linux :(
CC=gcc
FLAGS=-Wall -Wextra

all: prog
	./prog

prog: arvBin.h tadArvBinInt.o tadFilaApontador.o clienteArvBin.c
	$(CC) $(FLAGS) tadArvBinInt.o tadFilaApontador.o clienteArvBin.c -o prog -lm

