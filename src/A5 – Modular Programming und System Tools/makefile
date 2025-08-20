CC = gcc
CFLAGS = -Wall -Wextra -std=c11

all: program

program: main.c tools.c tools.h
	$(CC) $(CFLAGS) -o program main.c tools.c

clean:
	rm -f program *.o