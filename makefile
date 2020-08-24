CC=gcc
CFLAGS=-g
EXE=chelp
BIN=/usr/bin

make: main.c
	$(CC) main.c $(CFLAGS) -o $(EXE)
	mv $(EXE) $(BIN)
clean:
	rm chelp
noinstall:
	$(CC) main.c $(CFLAGS) -o $(EXE)
