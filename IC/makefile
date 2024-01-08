CC = gcc
CFLAGS = -Wall
objects = listaduplamente.o

executa: main
	./main
	
main: listaduplamente.o main.c
	$(CC) -o main listaduplamente.o main.c
	
listaduplamente.o: listaduplamente.c listaduplamente.h
	$(CC) -c listaduplamente.c
	
clean:
	rm main $(objects)