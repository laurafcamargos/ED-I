CC = gcc
CFLAGS = -Wall
objects = main.o abb.o

executa: main
	./main
	
main: abb.o main.c
	$(CC) -o main abb.o main.c
	
abb.o: abb.c abb.h
	$(CC) -c abb.c
	
clean:
	rm main $(objects)