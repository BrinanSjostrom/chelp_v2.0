CC=gcc
CFLAGS=-g
EXE=chelp
BIN=/usr/bin

make: main.c
	$(CC) main.c $(CFLAGS) -o $(EXE)
	mv $(EXE) $(BIN)
