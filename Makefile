CC = gcc

all: adding_machine.c

adding_machine.o: adding_machine.c
	$(CC) -c adding_machine.c
adding_machine.c: adding_machine.o
	$(CC) -o call adding_machine.o
