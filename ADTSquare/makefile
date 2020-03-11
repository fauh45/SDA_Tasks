CC=gcc
CFLAGS=-Wall
LIBS=-lm -lncurses

SRC=$(wildcard *.c)

line: $(SRC)
	$(CC) -o $@.out $^ $(CFLAGS) $(LIBS)