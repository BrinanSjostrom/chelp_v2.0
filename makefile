CC=gcc
CFLAGS=-g
EXE=chelp


make: main.c
	$(CC) main.c $(CFLAGS) -o $(EXE)
