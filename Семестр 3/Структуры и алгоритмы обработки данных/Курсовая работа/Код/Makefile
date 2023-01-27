CC = gcc
# CFLAGS = -g -Wall -Werror -Wextra
CFLAGS = -g
CFILES = main.c sequence.c deque.c sentence.c

all: main

main: 
	$(CC) -o executable $(CFLAGS) $(CFILES)

clean:
	rm -rf executable
	rm -rf *.dSYM

rebuild:
	rm -rf executable
	rm -rf *.dSYM
	$(CC) -o executable $(CFLAGS) $(CFILES)
